#include "common.h"

extern int D_808003A0_chlightfader;
extern s32 func_800C954C(void);
extern void _chbaddiesetup_entrypoint_3(void (*)(void), s32, s32, s32);
extern void _chlightfader_entrypoint_2(void);
extern void func_800C8B84(s32);
typedef struct LightFadeSample { f32 local_0[2]; f32 local_1[3]; } LightFadeSample;
typedef struct LightFadeState { s32 local_0; f32 local_1; s32 local_2; s32 local_3; f32 local_4; LightFadeSample local_5[2]; } LightFadeState;
extern void func_800C8800(s32, f32 *);
extern Actor *func_80108474(u32, f32 *, s32);
extern void *func_80100094(Actor *, u32);
extern s32 func_800C89A8(s32);
extern void func_800C8900(s32, f32 *);
extern void func_800C883C(s32, f32 *);
extern s32 func_8001210C(s32);
extern void *func_800A93F8(s32);
extern s32 func_800A9420(s32);
extern s32 func_800A946C(void);
extern void func_800C8D4C(s32, f32 *);
extern void func_800C8E84(s32, f32 *);
extern s32 func_800CACEC(void *, void *, f32);
extern s32 func_800D9078(f32 *);
extern s32 func_800E3E8C(void *, f32);
extern void func_800F2E60(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F2F60(f32 *, f32 *, f32);
extern s32 func_800F6438(s32);
extern void func_800FFA88(s32);
typedef struct { s32 h; f32 f04; u32 flags; u8 pad0C[4]; f32 f10; f32 in[2]; f32 v1C[3]; f32 out[2]; f32 v30[3]; } LF;
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_8080000C_chlightfader();

int chlightfader_entrypoint_0()
{
  return &D_808003A0_chlightfader;
}

void func_8080000C_chlightfader(s32 arg0) 
{
}
void func_80800014_chlightfader(Actor *param_0)
{
    s32 local_1;
    f32 f;
    s32 i;
    s32 j;
    LF *s1;
    f32 local_2[3];
    s32 has;
    s32 found;
    f32 g;
    void *p;
    f32 inv;

    s1 = func_80100094(param_0, 0);
    has = 0;
    local_1 = func_800D9078(&param_0->unk58);
    f = func_800F10B4(param_0->unk58, 0, s1->f04, 1.0f, 0.1f);
    inv = 1.0f - f;
    if (s1->flags & 1) {
        for (j = 0; j < 2; j++) {
            s1->out[j] = s1->in[j] * inv;
        }
        has = 1;
    }
    if (s1->flags & 2) {
        func_800F2F60(s1->v30, s1->v1C, 1.0f - f);
    }
    func_800F2E60(local_2, s1->v30);
    if (s1->flags & 4) {
        if (func_8001210C(1)) {
            g = 1.0f;
        } else {
            g = 0.6f;
        }
        func_800F2F60(local_2, local_2, g);
    }
    if (func_800A946C() >= 2) {
        found = 0;
        for (i = 0; i != 8; i++) {
            if (func_800F6438(i) && func_800A9420(i)) {
                p = func_800A93F8(i);
                if (p != 0 && func_800CACEC(p, &param_0->position, s1->f10)) {
                    found = 1;
                    break;
                }
            }
        }
    } else {
        found = func_800E3E8C(&param_0->position, s1->f10);
    }
    if (found != 0) {
        s1->f10 = s1->out[1];
        func_800C8E84(s1->h, local_2);
        if (has != 0) {
            func_800C8D4C(s1->h, s1->out);
        }
    }
    if (local_1 != 0) {
        func_800C8B84(s1->h);
        func_800FFA88(*(s32 *)param_0);
    }
}

s32 chlightfader_entrypoint_1(s32 param_0, s32 param_1, s32 param_2) {
    if (func_800C954C() == 0) {
        _chbaddiesetup_entrypoint_3(_chlightfader_entrypoint_2, param_0, param_1, param_2);
    } else {
        func_800C8B84(param_0);
    }
    return 0;
}

void chlightfader_entrypoint_2(s32 param_0, f32 param_1, s32 param_2)
{
    Actor *local_0;
    f32 *local_8;
    f32 local_1;
    f32 local_2[3];
    f32 local_7;
    LightFadeState *local_3;
    s32 local_4;
    f32 *local_5;
    f32 *local_6;

    local_1 = *(f32 *)&param_1;
    local_8 = local_2;
    func_800C8800(param_0, local_8);
    local_0 = func_80108474(0x33C, local_8, 0);
    local_3 = func_80100094(local_0, 0);
    local_3->local_3 = func_800C89A8(param_0);
    local_4 = 0;
    local_5 = local_3->local_5[0].local_1;
    local_6 = local_3->local_5[0].local_0;
    do {
        func_800C8900(param_0, local_5);
        func_800C883C(param_0, local_6);
        local_4 += 0x14;
        local_5 += 5;
        local_6 += 5;
    } while (local_4 != 0x28);
    local_3->local_0 = param_0;
    local_3->local_1 = local_1;
    local_3->local_2 = param_2;
    local_3->local_4 = local_3->local_5[1].local_0[1];
    local_0->unk58 = local_1;
}
