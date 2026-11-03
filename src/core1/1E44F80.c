#include "common.h"

/* func_8002D450: builds audio RSP commands (0x0A... / 0x05... acmds) with the pitch quantised to
 * 1/32768 and a fraction accumulator at 0x4C. 1.99996 is the f64 limit, 1.99996f the f32 clamp. */

typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd2;

typedef struct {
    u8 pad0[0x40];
    void *unk40;           /* 0x40: Sample-Ptr */
    f32 unk44;             /* 0x44: Pitch */
    s32 unk48;             /* 0x48: Raw-Flag */
    f32 unk4C;             /* 0x4C: Frac-Akkumulator */
    s32 unk50;             /* 0x50: Startmode 0..3 */
} TTVoiceD;

extern TTAcmd2 *func_8002C5F8(TTVoiceD *, s16 *, s32, TTAcmd2 *);

TTAcmd2 *func_8002D450(TTVoiceD *v, s16 *arg1, TTAcmd2 *cmd)
{
    TTAcmd2 *p;
    s16 tmp;
    s32 ti;
    s32 pitch;
    f32 t;
    TTAcmd2 *c1;
    TTAcmd2 *c2;

    p = cmd;
    tmp = 0x170;

    if (v->unk48) {
        p = func_8002C5F8(v, &tmp, 0xB8, cmd);
        c1 = p++;
        c1->w0 = (tmp & 0xFFFFFF) | 0x0A000000;
        c1->w1 = ((*arg1 & 0xFFFF) << 16) | 0x170;
        if (1) {
        }
    }
    else {
        if (v->unk44 > 1.99996)
            v->unk44 = 1.99996f;

        v->unk44 = (f32)(s32)(v->unk44 * 32768.0f);
        v->unk44 = v->unk44 / 32768.0f;

        t = v->unk4C + v->unk44 * 184.0f;
        ti = (s32)t;
        v->unk4C = t - (f32)ti;

        p = func_8002C5F8(v, &tmp, ti, cmd);

        pitch = (s32)(v->unk44 * 32768.0f);

        c2 = p++;
        c2->w0 = (osVirtualToPhysical(v->unk40) & 0xFFFFFF) | 0x05000000;
        c2->w1 = ((v->unk50 & 3) << 30) | ((pitch & 0xFFFF) << 14) | ((tmp & 0xFFF) << 2);
        v->unk50 = 0;
    }

    return p;
}

s32 func_8002D694(s32 a, s32 b, s32 c)
{
    func_8002CC9C(a, b, c);
    return 0;
}
