#include "common.h"
#ifndef M2C_MACROS_H
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr) ((s8 *) (expr) + (offset)))
#endif

typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd;
typedef struct {
    s32 base; // 0x00: sample data in ROM
    s32 len; // 0x04: length, quantised to 9-byte frames
} TTLoopH;
typedef struct {
    u8 pad0[0x14];
    u32 loop_start; // 0x14
    u32 loop_end; // 0x18
    s32 loop_count; // 0x1C
    TTLoopH *wave;
    u32 book_size; // 0x24
    u8 pad28[8];
    u32 pos; // 0x30: current sample position
    u32 phase; // 0x34: 0..15, position inside a 16-sample ADPCM frame
    s32 flags; // 0x38
    s32 rom_cursor; // 0x3C: ROM read cursor
} TTVceH;
typedef struct {
    s32 base; // 0x00: sample data in ROM
    s32 len; // 0x04: length, quantised to 9-byte frames
    s32 loop_start; // 0x08: loop {start, end, count}
    s32 loop_end;
    s32 loop_count;
    u8 loop_state[0x20]; // 0x14: ADPCM loop state block
    s32 unk_34;
    u8 pad38[0x80];
    s32 unk_B8;
} TTWave;
typedef struct {
    u8 pad0[0x10];
    void *state_dst; // 0x10
    s32 loop_start;
    s32 loop_end;
    s32 loop_count;
    TTWave *wave;
    s32 book_size;
    u8 pad28[8];
    s32 pos;
    s32 phase;
    s32 flags;
    s32 rom_cursor;
} TTVoiceF;
typedef struct {
    u8 pad0[0xC];
    s32 state_addr;
    s32 loop_addr;
    u8 pad14[0x14];
    s32 (*dma)(s32, s32, s32); // 0x28: DMA callback
    s32 dma_state;
    u8 pad30[8];
    s32 flags;
    s32 rom_cursor;
} TTVoiceG;

TTAcmd *func_8002CE70(TTAcmd *list, TTVoiceG *voice, s32 sample_cnt, s32 byte_len, s16 dmem_addr, s16 dmem_off, s32 flags);

// Returns 1 when the {head, tail} pair differs.
s32 func_8002C5C0(u8 *queue)
{
    if (M2C_FIELD(queue, s32 *, 4) == M2C_FIELD(queue, s32 *, 0)) {
        return 0;
    } else {
        return 1;
    }
}

// ADPCM pull: DMAs the compressed data and emits LOADADPCM/LOADBUFF/SETLOOP/ADPCM/
// DMEMMOVE/CLEARBUF commands, handling loops that wrap inside one pull.
TTAcmd *func_8002C5F8(TTVceH *state, s16 *dmem, s32 count, TTAcmd *list)
{
    TTAcmd *cmd = list;
    s16 unk_0;
    s32 sample_cnt;
    s32 frames;
    s32 bytes;
    s32 over;
    s32 zero_off;
    s32 skip;
    s32 chunk;
    s32 loop_dmem;
    s32 lead;
    s32 cur_dmem;
    s32 partial = 0;
    s32 wraps = 0;
    TTVceH *voice = state;
    TTAcmd *book;
    TTAcmd *move;
    TTAcmd *clear;

    if (count == 0)
        return cmd;

    unk_0 = 0;

    book = cmd++;
    book->w0 = (voice->book_size & 0xFFFFFF) | 0x0B000000;
    book->w1 = ((u32) voice->wave + 0x38) & 0x1FFFFFFF;

    wraps = (voice->pos + count > voice->loop_end) && (voice->loop_count != 0);

    if (wraps)
        chunk = voice->loop_end - voice->pos;
    else
        chunk = count;

    if (voice->phase)
        lead = 0x10 - voice->phase;
    else
        lead = 0;

    sample_cnt = chunk - lead;
    if (sample_cnt < 0)
        sample_cnt = 0;

    frames = (sample_cnt + 0xF) >> 4;
    bytes = frames * 9;

    if (wraps) {
        cmd = func_8002CE70(cmd, voice, sample_cnt, bytes, *dmem, unk_0, voice->flags);

        if (voice->phase)
            *dmem = *dmem + voice->phase * 2;
        else
            *dmem = *dmem + 0x20;

        voice->phase = voice->loop_start & 0xF;
        voice->rom_cursor = voice->wave->base + (voice->loop_start >> 4) * 9 + 9;
        voice->pos = voice->loop_start;
        cur_dmem = *dmem;

        while (count > chunk) {
            count -= chunk;
            loop_dmem = (((frames + 1) << 5) + cur_dmem + 0x10) & ~0x1F;
            cur_dmem += chunk * 2;

            if (voice->loop_count != -1 && voice->loop_count != 0)
                voice->loop_count--;

            chunk = (count < voice->loop_end - voice->loop_start) ? count : voice->loop_end - voice->loop_start;

            sample_cnt = chunk + voice->phase - 0x10;
            if (sample_cnt < 0)
                sample_cnt = 0;

            frames = (sample_cnt + 0xF) >> 4;
            bytes = frames * 9;

            cmd = func_8002CE70(cmd, voice, sample_cnt, bytes, loop_dmem, unk_0, voice->flags | 2);

            move = cmd++;
            move->w0 = ((voice->phase * 2 + loop_dmem) & 0xFFFFFF) | 0x0A000000;
            move->w1 = ((cur_dmem & 0xFFFF) << 16) | ((chunk * 2) & 0xFFFF);
        }

        voice->phase = (voice->phase + count) & 0xF;
        voice->pos = voice->pos + count;
        voice->rom_cursor = voice->rom_cursor + frames * 9;
        return cmd;
    }

    {
        chunk = frames << 4;

        over = (voice->rom_cursor + bytes) - (voice->wave->base + voice->wave->len);
        if (over < 0)
            over = 0;

        skip = over / 9 << 4;

        if (skip > chunk + lead)
            skip = chunk + lead;

        bytes = bytes - over;

        if (skip - (skip & 0xF) < count) {
            partial = 1;

            cmd = func_8002CE70(cmd, voice, chunk - skip, bytes, *dmem, unk_0, voice->flags);

            if (voice->phase)
                *dmem = *dmem + voice->phase * 2;
            else
                *dmem = *dmem + 0x20;

            voice->phase = (voice->phase + count) & 0xF;
            voice->pos = voice->pos + count;
            voice->rom_cursor = voice->rom_cursor + frames * 9;
        } else {
            voice->phase = 0;
            voice->rom_cursor = voice->rom_cursor + frames * 9;
        }

        if (skip != 0) {
            voice->phase = 0;

            if (partial)
                zero_off = (lead + chunk - skip) * 2;
            else
                zero_off = 0;

            clear = cmd++;
            clear->w0 = ((*dmem + zero_off) & 0xFFFFFF) | 0x02000000;
            clear->w1 = skip * 2;
        }
    }

    return cmd;
}

// Loader param handler: 5 sets the wavetable, 4 resets.
s32 func_8002CC9C(TTVoiceF *arg0, s32 type, TTWave *val)
{
    TTVoiceF *voice = arg0;

    switch (type) {
        case 5:
            voice->wave = val;
            voice->rom_cursor = voice->wave->base;
            voice->pos = 0;
            voice->wave->len = (voice->wave->len / 9) * 9;
            voice->book_size = voice->wave->unk_34 * 2 * voice->wave->unk_B8 * 8;
            if (func_8002C5C0(&voice->wave->loop_start)) {
                voice->loop_start = voice->wave->loop_start;
                voice->loop_end = voice->wave->loop_end;
                voice->loop_count = voice->wave->loop_count;
                bcopy(voice->wave->loop_state, voice->state_dst, 0x20);
            } else {
                voice->loop_start = voice->loop_end = voice->loop_count = 0;
            }
            break;
        case 4:
            voice->phase = 0;
            voice->flags = 1;
            voice->pos = 0;
            if (voice->wave) {
                voice->rom_cursor = voice->wave->base;
                if (func_8002C5C0(&voice->wave->loop_start)) {
                    voice->loop_count = voice->wave->loop_count;
                }
            }
            break;
        default:
            break;
    }

    return 0;
}

// Emits LOADBUFF (via the DMA callback), optional SETLOOP and ADPCM for one chunk.
TTAcmd *func_8002CE70(TTAcmd *list, TTVoiceG *voice, s32 sample_cnt, s32 byte_len, s16 dmem_addr, s16 dmem_off, s32 flags)
{
    s32 rem;
    s32 rom_addr;
    TTAcmd *loadbuf;
    TTAcmd *setloop;
    TTAcmd *adpcm;

    if (byte_len > 0) {
        rom_addr = voice->dma(voice->rom_cursor, byte_len, voice->dma_state);
        rem = rom_addr & 7;
        byte_len = byte_len + rem;
        loadbuf = list++;
        loadbuf->w0 = ((((byte_len - (byte_len & 7)) + 8) & 0xFFF) << 12 | 0x04000000) | (dmem_off & 0xFFF);
        loadbuf->w1 = rom_addr - rem;
        // Matching: empty block steers IDO's register allocation.
        if (1) {
        }
    } else {
        rem = 0;
    }

    if (flags & 2) {
        setloop = list++;
        setloop->w0 = 0x0F000000;
        setloop->w1 = voice->loop_addr & 0x1FFFFFFF;
    }

    adpcm = list++;
    adpcm->w0 = ((voice->state_addr & 0x1FFFFFFF) & 0xFFFFFF) | 0x01000000;
    adpcm->w1 =
        ((flags & 0xF) << 28) | (((sample_cnt * 2) & 0xFFF) << 16) | ((rem & 0xF) << 12) | (dmem_addr & 0xFFF);

    voice->flags = 0;

    return list;
}
