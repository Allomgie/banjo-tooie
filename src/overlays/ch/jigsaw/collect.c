#include "common.h"

extern void *D_80800670_chjigsawcollect;
typedef struct { f32 local_0; f32 local_1; f32 local_2; s32 local_3; s32 local_4; } JigsawCollectionState;
extern void *func_80100094(Actor *, u32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
typedef struct { u8 unused[0x73]; u8 unusedBit : 7; u8 collect : 1; } JiggyCollectFlags;
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } JigState;
extern u8 D_808006B8_chjigsawcollect[];
extern u8 D_808006C4_chjigsawcollect[];
extern f32 func_800D8FF8(void);
extern f32 func_80013728(f32);
extern f32 func_800136E4(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern f32 func_800DC0C0(void);
extern void func_800C4B64(f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080000C_chjigsawcollect(), func_80800524_chjigsawcollect();

int chjigsawcollect_entrypoint_0()
{
  return &D_80800670_chjigsawcollect;
}

void func_8080000C_chjigsawcollect(param_0) Actor *param_0;
{
    JigsawCollectionState *local_0;

    local_0 = func_80100094(param_0, 0);
    if (func_800CFA70(local_0->local_3, 1) != -1) {
        local_0->local_4 = func_800C8A98();
        func_800CF9E4(local_0->local_3, 1, local_0->local_4);
        func_800C8CB8(local_0->local_4, param_0->position);
    } else {
        local_0->local_4 = 0;
    }
    local_0->local_1 = 0.0f;
    local_0->local_0 = -70.0f;
    local_0->local_2 = 500.0f;
    func_800FC660(0x1C);
    func_800FC660(5);
    param_0->unk64_20 = 1;
}

void func_808000CC_chjigsawcollect(Actor *param_0)
{
    f32 local_6;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_7;
    f32 local_8;
    f32 *local_2;
    f32 local_3;
    s32 local_4;
    f32 local_5;

    local_2 = func_80100094(param_0, 0);
    local_3 = func_800D8FF8();
    func_800F5A00(func_800F54E4(), local_0);
    if (1) {}
    local_0[1] += 120.0f;
    switch (((JigState *)param_0)->st) {
    case 1:
        local_6 = local_2[1];
        local_2[1] += 600.0f * local_3;
        local_2[0] += 60.0f * local_3;
        if (90.0f <= local_2[0]) {
            local_2[0] = 90.0f;
            func_80101FDC(param_0, 2);
            if (param_0->unk64_20) {
                func_800FCAE0(0x1C, 0, 0x1F4);
                func_800FCA90(0x1C);
                param_0->unk64_20 = 0;
            }
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808006B8_chjigsawcollect);
        } else if (func_80013728(local_6) <= 0.0f && 0.0f < func_80013728(local_2[1]) && func_80013728(local_2[0]) < 70.0f) {
            func_800C4B64(func_800F10B4(func_80013728(local_2[0]), -70.0f, 70.0f, 1.0f, 1.2f));
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808006C4_chjigsawcollect);
        }
        local_2[0] = func_80013728(local_2[0]);
        local_2[1] = func_80013728(local_2[1]);
        param_0->rotation[1] = func_800136E4(func_800F1DF4(param_0->position, local_0));
        func_80103DFC(param_0, local_1);
        local_7 = func_800DC178(0.0f, 360.0f);
        local_8 = func_800DC178(0.0f, 360.0f);
        func_800EF214(local_1, local_7, local_8, 20.0f);
        func_808005B8_chjigsawcollect(param_0, local_1);
        break;
    case 2:
        local_2[2] = func_800F15F8(local_2[2], 1600.0f, local_3 * 1000.0f);
        param_0->rotation[1] += local_3 * local_2[2];
        for (local_4 = 0; local_4 != 4; local_4++) {
            if (func_800DC0C0() < 0.08f) {
                func_80103DFC(param_0, local_1);
                func_800EF214(local_1, func_800DC178(0.0f, 360.0f), func_800DC178(0.0f, 360.0f), 20.0f);
                _fxtwinkle_entrypoint_0(local_1);
            }
        }
        if (!func_8001210C(3)) {
            func_80103DFC(param_0, local_1);
            func_808005B8_chjigsawcollect(param_0, local_1);
        }
        if (local_2[2] == 1600.0f) {
            _fxsparkle_entrypoint_1(param_0->position, 0xA);
            if (*(s32 *)&local_2[4]) {
                *(s32 *)&local_2[4] = _chlightfader_entrypoint_1(*(s32 *)&local_2[4], 2.2f, 2);
            }
            func_800FFAB0(param_0);
        }
        break;
    }
    func_800EE7F8(param_0->position, local_0);
    local_5 = func_800F10B4(local_2[0], -70.0f, 90.0f, 10.0f, 40.0f);
    func_800EF214(param_0->position, local_2[0], local_2[1], 120.0f + local_5);
    if (*(s32 *)&local_2[4]) {
        func_800EE7F8(local_1, param_0->position);
        local_1[1] += 100.0f;
        func_800C8CB8(*(s32 *)&local_2[4], local_1);
    }
}

void func_80800524_chjigsawcollect(param_0) Actor *param_0;
{
    s32 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (local_0[4] != 0) {
        func_800C8B84(local_0[4]);
        local_0[4] = 0;
    }
    if (param_0->unk64_20) {
        func_800FCAE0(0x1C, 0, 0x1F4);
        func_800FCA90(0x1C);
        param_0->unk64_20 = 0;
    }
}

s32 func_808005A4_chjigsawcollect(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
int func_808005B8_chjigsawcollect(s32 param_0, s32 param_1)
{
  extern f32 D_808006D0_chjigsawcollect;
  func_800BBCB8(param_1, 0, 0x3F800000, 1, &D_808006D0_chjigsawcollect);
}

void chjigsawcollect_entrypoint_1(Actor **param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;

    local_0 = func_80108528(0x4EF, (*param_0)->position, 0, param_0);
    ((JiggyCollectFlags *)local_0)->collect = param_2;
    ((s32 *)func_80100094(local_0, 0))[3] = param_1;
}
