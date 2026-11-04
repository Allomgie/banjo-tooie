// Synth bus mixer: pulls each FX bus, mixes it into L/R and optionally applies a per-bus filter.
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd;
typedef struct TTChan_s {
    u8 pad0[2];
    s16 unk_2;
    u8 pad4[4];
    u32 coefs; // 0x08: coefficient table (32 bytes)
    u8 padC[0x1C];
    s32 dirty; // 0x28: coefficients need recomputing
    void *state_l; // 0x2C: pole filter state, left
    void *state_r; // 0x30: pole filter state, right
} TTChan;
typedef struct {
    u8 pad0[0x44];
    TTChan *chan;
} TTChSlot;
typedef struct {
    u8 pad0[4];
    TTAcmd *(*pull)(void *, TTAcmd *, s32);
} TTSynthV;
typedef struct {
    u8 pad0[0x30];
    TTSynthV *synth;
    TTChSlot *chan_slots;
    u8 pad38[4];
    s32 bus_count;
    s32 unk_40;
} TTAMgrC;
extern TTAMgrC *D_800411F4;
extern u8 D_8007EA33[];
extern u8 D_8007EA34[];
extern void func_80028C04(void *, f32);

// Per-bus pull and mix into L/R, plus optional pole filter per channel.
TTAcmd *func_8002C230(void *arg0, TTAcmd *list)
{
    TTAcmd *cmd = list;
    s32 i;
    TTAcmd *clear;
    TTAcmd *mix0;
    TTAcmd *mix1;
    TTAcmd *mix2;
    TTAcmd *mix3;
    TTAcmd *mix4;
    TTChan *chan;
    TTAcmd *coef;
    TTAcmd *polef_l;
    TTAcmd *polef_r;

    clear = cmd++;
    clear->w0 = 0x020004E0;
    clear->w1 = 0x2E0;

    for (i = 0; i < D_800411F4->bus_count; i++) {
        cmd = D_800411F4->synth->pull(arg0, cmd, i);

        if (D_8007EA33[i]) {
            if (D_8007EA34[i]) {
                mix0 = cmd++;
                mix0->w0 = 0x0C008000;
                mix0->w1 = 0x07C004E0;
                // Matching: empty block (compiled-out _DEBUG code) kept for the match.
                if (1) {
                }
            } else {
                mix1 = cmd++;
                mix1->w0 = 0x0C007FFF;
                mix1->w1 = 0x07C00650;
            }
        } else {
            if (D_8007EA34[i]) {
                mix2 = cmd++;
                mix2->w0 = 0x0C008000;
                mix2->w1 = 0x07C00650;
                // Matching: empty block (compiled-out _DEBUG code) kept for the match.
                if (1) {
                }
            } else {
                mix3 = cmd++;
                mix3->w0 = 0x0C007FFF;
                mix3->w1 = 0x07C00650;
            }
            mix4 = cmd++;
            mix4->w0 = 0x0C007FFF;
            mix4->w1 = 0x07C004E0;
        }

        if (D_800411F4->chan_slots[i].chan->unk_2 > 0) {
            chan = D_800411F4->chan_slots[i].chan;

            if (chan->dirty) {
                func_80028C04(chan, (f32) D_800411F4->unk_40);
            }

            coef = cmd++;
            coef->w0 = 0x0B000020;
            coef->w1 = osVirtualToPhysical(&chan->coefs);

            polef_l = cmd++;
            polef_l->w0 = 0x0E0004E0;
            polef_l->w1 = (osVirtualToPhysical(chan->state_l) & 0xFFFFFF) & 0xFFFFFF;

            polef_r = cmd++;
            polef_r->w0 = 0x0E000650;
            polef_r->w1 = (osVirtualToPhysical(chan->state_r) & 0xFFFFFF) & 0xFFFFFF;

            chan->dirty = 0;
        }
    }

    return cmd;
}

// TU-NOTE: this .rodata holds constants used by 1E42810 (formerly part of its
// .rodata.s). They follow 1E42810's literals in the ROM, so they cannot live in that file:
// IDO puts a file's const objects in front of its literals. This is the next file in link
// order without .rodata of its own (1E440D0 and 1E440F0 would fit as well).
const struct {
    f32 x;
    f32 pad[3];
} D_80041D90 = {26755.0f};
