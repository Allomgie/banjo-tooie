#include "common.h"

typedef struct { u32 w0; u32 w1; } TTAcmd;
typedef struct TTChan_s { u8 pad0[2]; s16 unk2; /* 0x02 */ u8 pad4[4]; u32 unk8; /* 0x08 */ u8 padC[0x1C]; s32 unk28; /* 0x28 */ void *unk2C; /* 0x2C */ void *unk30; /* 0x30 */ } TTChan;
typedef struct { u8 pad0[0x44]; TTChan *unk44; /* 0x44 */ } TTChSlot;
typedef struct { u8 pad0[4]; TTAcmd *(*unk4)(void *, TTAcmd *, s32); /* 0x04 */ } TTSynthV;
typedef struct { u8 pad0[0x30]; TTSynthV *unk30; /* 0x30 */ TTChSlot *unk34; /* 0x34 */ u8 pad38[4]; s32 unk3C; /* 0x3C */ s32 unk40; /* 0x40 */ } TTAMgrC;
extern TTAMgrC *D_800411F4;
extern u8 D_8007EA33[];
extern u8 D_8007EA34[];
extern void func_80028C04(void *, f32);

TTAcmd *func_8002C230(void *arg0, TTAcmd *cmdIn)
{
    TTAcmd *cmd = cmdIn;
    s32 i;
    TTAcmd *p0;
    TTAcmd *p1;
    TTAcmd *p2;
    TTAcmd *p3;
    TTAcmd *p4;
    TTAcmd *p5;
    TTChan *chan;
    TTAcmd *p6;
    TTAcmd *p7;
    TTAcmd *p8;

    p0 = cmd++;
    p0->w0 = 0x020004E0;
    p0->w1 = 0x2E0;

    for (i = 0; i < D_800411F4->unk3C; i++) {
        cmd = (D_800411F4->unk30->unk4)(arg0, cmd, i);

        if (D_8007EA33[i]) {
            if (D_8007EA34[i]) {
                p1 = cmd++;
                p1->w0 = 0x0C008000;
                p1->w1 = 0x07C004E0;
                if (1) {}   /* wegkompilierter _DEBUG-Block */
            } else {
                p2 = cmd++;
                p2->w0 = 0x0C007FFF;
                p2->w1 = 0x07C00650;
            }
        } else {
            if (D_8007EA34[i]) {
                p3 = cmd++;
                p3->w0 = 0x0C008000;
                p3->w1 = 0x07C00650;
                if (1) {}   /* wegkompilierter _DEBUG-Block */
            } else {
                p4 = cmd++;
                p4->w0 = 0x0C007FFF;
                p4->w1 = 0x07C00650;
            }
            p5 = cmd++;
            p5->w0 = 0x0C007FFF;
            p5->w1 = 0x07C004E0;
        }

        if (D_800411F4->unk34[i].unk44->unk2 > 0) {
            chan = D_800411F4->unk34[i].unk44;

            if (chan->unk28) {
                func_80028C04(chan, (f32)D_800411F4->unk40);
            }

            p6 = cmd++;
            p6->w0 = 0x0B000020;
            p6->w1 = osVirtualToPhysical(&chan->unk8);

            p7 = cmd++;
            p7->w0 = 0x0E0004E0;
            p7->w1 = (osVirtualToPhysical(chan->unk2C) & 0xFFFFFF) & 0xFFFFFF;

            p8 = cmd++;
            p8->w0 = 0x0E000650;
            p8->w1 = (osVirtualToPhysical(chan->unk30) & 0xFFFFFF) & 0xFFFFFF;

            chan->unk28 = 0;
        }
    }

    return cmd;
}
