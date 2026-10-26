#include "common.h"

extern u8 B_808003F0_sccustom_big[];
extern s32 B_80800400_sccustom_big;
extern f32 _scinfobar_entrypoint_18(s32);
extern s32 func_800E7188(s32);

int func_80800000_sccustom_big(s32 param_0)
{
  func_800E73D4(&B_808003F0_sccustom_big);
  func_800E6DB4(&B_808003F0_sccustom_big, _scinfobar_entrypoint_19(param_0));
  return (int)&B_808003F0_sccustom_big;
}

s32 *func_80800044_sccustom_big(param_0, param_1) s32 param_0; u8 param_1; {
    func_800E73D4(&B_80800400_sccustom_big);
    func_800E6DB4(&B_80800400_sccustom_big, _scinfobar_entrypoint_19(param_0));
    func_800E6A58(&B_80800400_sccustom_big, param_1);
    func_800E6DB4(&B_80800400_sccustom_big, _scinfobar_entrypoint_20(param_0));
    return &B_80800400_sccustom_big;
}

int func_808000B4_sccustom_big(s32 param_0, s32 param_1, s32 param_2,
    s32 param_3, u8 *param_4)
{
    s32 local_0;
    f32 local_1;
    s32 local_2;
    f32 local_3;

    s32 local_5;
    s32 local_6;
    s32 local_7;
    f32 local_8;
    s32 local_9;

    local_0 = _scinfobar_entrypoint_11(param_1);
    local_1 = _scinfobar_entrypoint_18(param_1);
    local_2 = _scinfobar_entrypoint_15(param_1);
    func_800B8C50();
    func_800B8C98(1);
    func_800B8CE0(0xC26);
    local_3 = (f32)local_0;
    if (local_3 < (24.0f * local_1 + 8.0f)) {
        local_5 = (s32)((1.0f - (((24.0f * local_1 + 8.0f) - local_3) / (24.0f * local_1 + 8.0f))) * 255.0f);
    } else {
        local_5 = 255;
    }
    local_6 = func_800E7188((s32)param_4) - 1;
    func_800B8C8C(local_5);
    func_800B7F14(param_0);
    for (local_7 = local_6; local_7 >= 0; local_7--) {
        local_8 = (24.0f * local_1 + 8.0f) + 16.0f * (f32)local_7;
        if (local_3 < local_8) {
            local_8 = local_3;
        }
        if (local_2 == 2) {
            local_8 = -local_8;
            local_9 = param_4[local_6 - local_7];
        } else {
            local_9 = param_4[local_7];
        }
        func_800B8DEC(param_0, (s32)((f32)param_2 + local_8), param_3, local_9);
    }
    func_800B811C(param_0);
}

s32 sccustom_big_entrypoint_0(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_0;

    local_0 = func_80800000_sccustom_big(param_1);
    return func_808000B4_sccustom_big(param_0, param_1, param_2, param_3, local_0);
}

s32 sccustom_big_entrypoint_1(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_0;

    local_0 = func_80800044_sccustom_big(param_1, 0x2F);
    return func_808000B4_sccustom_big(param_0, param_1, param_2, param_3, local_0);
}

s32 func_80800314_sccustom_big(s32 param_0, s32 param_1)
{
    s32 local_0;
    f32 local_1;

    local_0 = func_800E7188(param_1);
    local_1 = _scinfobar_entrypoint_18(param_0);
    if (local_0 < 2) {
        local_0 = 2;
    }
    local_0--;
    return 24.0f * local_1 + 8.0f + 16.0f * local_0;
}

s32 sccustom_big_entrypoint_2(Actor *this) {
    s32 pad;
    s32 out;

    out = func_80800000_sccustom_big(this);
    func_80800314_sccustom_big(this, out | 0);
}

void sccustom_big_entrypoint_3(s32 param_0){
    s32 out;
    out = func_80800044_sccustom_big(param_0, 0x2F);
    out |= func_80800314_sccustom_big(param_0, out);
    return;
}
