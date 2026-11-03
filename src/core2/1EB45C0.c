#include "core2/1EB45C0.h"

s16 func_800A8184(void);
f32 func_800D9004(void);

extern u8 D_8012762C;
extern f32 D_8012C768[];

// TU-NOTE: D_8012C768 aliases D_8012C7A0 - 14 floats, so it is indexed by raw level id (0xE-based).
// D_8012C7A0 holds play time in seconds per level, level ids 0xF..0x1B.
f32 D_8012C7A0[14];

// Reset all level times.
void func_800DACD0(void)
{
    s32 i;
    for (i = 0; i < 14; i++) {
        D_8012C7A0[i] = 0;
    }
}

// Sum of all level times.
s32 func_800DAD10(void)
{
    s32 ret = 0;
    s32 i;
    for (i = 0; i < 14; i++) {
        ret += D_8012C7A0[i];
    }
    return ret;
}

// Play time of a level by raw level id.
u16 func_800DADEC(s32 level_id)
{
    return D_8012C768[level_id];
}

// Per-frame: add elapsed seconds to the current level's time, capped at 65535.
void func_800DAE9C(void)
{
    s32 level_id = D_8012762C;
    f32 total;
    f32 new_total;

    if ((func_800A8184() != 4) && (func_80090128() != 0) && (level_id >= 0xF) && (level_id < 0x1C) &&
        (level_id != 0x11)) {
        // Matching: the MINs expand into multiple func_800D9004 calls each.
        total = MIN(65535.0f, D_8012C7A0[level_id - 14] + func_800D9004());
        if (total < 1.0f) {
            D_8012C7A0[level_id - 14] = 1.0f;
            return;
        }

        new_total = MIN(65535.0f, D_8012C7A0[level_id - 14] + func_800D9004());
        D_8012C7A0[level_id - 14] = new_total;
    }
}

// Save size in bytes (14 u16).
s32 func_800DAFC4(void)
{
    return 0x1C;
}

// Matching: the line breaks in this function are needed for the match.
// Writes the level times as big-endian u16.
void func_800DAFCC(u8 dst[2 * ARRLEN(D_8012C7A0)]) {
    s32 i;
    for (i = 0; i < ARRLEN(D_8012C7A0); i++) {
        dst[i * 2 + 0] = (s16)(u32)D_8012C7A0[i] >> 8; dst[i * 2 + 1] = (s16)(u32)D_8012C7A0[i];
    }
}

// Reads the level times from big-endian u16 save bytes.
void func_800DB67C(u8 *data, u32 size)
{
    s32 count;
    s32 i;

    func_800DACD0();
    count = size / 2;
    count = MIN(ARRLEN(D_8012C7A0), count);
    for (i = 0; i < count; i++) {
        D_8012C7A0[i] = (data[2 * i + 0] << 8) | data[2 * i + 1];
    }
}

// Sum of the level times in a save image; -1 if unreadable.
s32 func_800DB7C0(u8 *save)
{
    s32 offset;
    u32 length;
    s32 i;
    s32 sum;
    s32 count;

    if (_glgamedata_entrypoint_3(save, 3, &offset, &length)) {
        sum = 0;
        count = length / 2;
        for (i = 0; i < count; i++) {
            // Matching: pointer arithmetic here; indexing with offset directly does not match.
            s32 val = ((save + offset)[2 * i + 0] << 8) | (save + offset)[2 * i + 1];
            sum += val;
        }
        return sum;
    }
    return -1;
}

// Time of one level from a save image; -1 if unreadable.
s32 func_800DB83C(u8 *save, s32 level_id)
{
    s32 offset;
    u32 length;
    s32 count;
    s32 val;

    if (_glgamedata_entrypoint_3(save, 3, &offset, &length)) {
        level_id -= 0xE;
        count = length / 2;
        if (count < level_id) {
            return -1;
        }
        // Matching: pointer arithmetic here; indexing with offset directly does not match.
        val = ((save + offset)[level_id * 2 + 0] << 8) | (save + offset)[level_id * 2 + 1];
        return val;
    }
    return -1;
}

void func_800E6A10(char *, const char *);
void func_800E6DB4(char *, s32);

// Formats seconds as h:mm:ss.
void func_800DB8BC(char *out, s32 time)
{
    s32 hours = time / 3600;
    s32 minutes = (time / 60) % 60;
    s32 seconds = time % 60;

    func_800E6DB4(out, hours);
    func_800E6A10(out, ":");

    if (minutes < 10) {
        func_800E6A10(out, "0");
    }
    func_800E6DB4(out, minutes);
    func_800E6A10(out, ":");

    if (seconds < 10) {
        func_800E6A10(out, "0");
    }
    func_800E6DB4(out, seconds);
    func_800E6A10(out, "");
}

// Is a cutscene active.
int func_800DB9B0(void)
{
    return func_800DA298(FLAG2_641_CUTSCENE_STORAGE_ACTIVE);
}
