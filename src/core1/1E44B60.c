#include "common.h"

typedef struct { u32 w0; u32 w1; } TTAcmd;
typedef struct { u8 pad0[0x8C]; u8 unk8C; /* 0x8C */ u8 pad8D[5]; s16 unk92; /* 0x92 */ u8 pad94[0x24]; u32 unkB8; /* 0xB8 */ void *unkBC; /* 0xBC */ } TTRvb;
typedef struct { s16 unk0; /* 0x0 */ } TTRParam;
extern f32 D_80041DA0;
extern f32 D_80041DA4;
extern f32 D_80041DA8;
extern TTAcmd *func_8002D450(TTRvb *, TTRParam *, TTAcmd *);
extern void func_80028C04(void *, f32);
typedef struct { u8 pad0[0x8C]; u8 unk8C; /* 0x8C */ u8 pad8D[3]; s16 unk90; /* 0x90 */ s16 unk92; /* 0x92 */ u8 pad94[0x24]; s32 unkB8; /* 0xB8: Dirty-Flags */ } TTVoiceE;
extern void func_8002CC9C(TTVoiceE *, s32, s32);

TTAcmd *func_8002D030(TTRvb *state, TTRParam *param, s32 arg2, TTAcmd *cmdBuf)
{
    TTAcmd *cmd = cmdBuf;
    f32 pitch;
    TTAcmd *p1;
    TTAcmd *p2;
    TTAcmd *p3;

    cmd = func_8002D450(state, param, cmdBuf);

    if (state->unk8C != 0 && state->unk8C < 0x40) {
        if (state->unk8C >= 6)
            pitch = D_80041DA0 / sqrtf((f32)state->unk8C + 1.0f);
        else
            pitch = 65536.0f / ((f32)state->unk8C + 1.0f);

        if (pitch < D_80041DA4)
            pitch = D_80041DA8;

        p1 = cmd++;
        p1->w0 = param->unk0 & 0xFFFF;
        p1->w1 = (((u32)pitch & 0xFFFF) << 16) | ((state->unk8C + 1) & 0xFFFF);
    }

    if (state->unk92 > 0) {
        if (state->unkB8 != 0)
            func_80028C04(&((u8 *)state)[0x90], 22050.0f);

        p2 = cmd++;
        p2->w0 = 0x0B000020;
        p2->w1 = osVirtualToPhysical(&((u8 *)state)[0x98]);

        if (state->unkB8 == 2)
            state->unkB8 = 0;

        p3 = cmd++;
        p3->w0 = (param->unk0 & 0xFFFF) | (((state->unkB8 & 0xFF) << 16) | 0x0E000000);
        p3->w1 = (osVirtualToPhysical(state->unkBC) & 0xFFFFFF) & 0xFFFFFF;
        state->unkB8 = 0;
    }

    return cmd;
}

s32 func_8002D328(TTVoiceE *v, s32 type, s32 val)
{
    f32 *fp = (f32 *)&val;

    switch (type) {
        case 4:
            v->unk92 = 0;
            func_8002CC9C(v, 4, val);
            break;
        case 0x12:
            v->unk92 = val;
            v->unkB8 |= 2;
            break;
        case 0x13:
            v->unk90 = (s32)*fp;
            v->unkB8 |= 2;
            break;
        case 0x11:
            v->unk8C = val;
            break;
        default:
            func_8002CC9C(v, type, val);
            break;
    }

    return 0;
}
