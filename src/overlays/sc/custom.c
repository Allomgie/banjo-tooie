/*
 * sc/custom (overlays) -- IDO 5.3, -O2 -mips2 -G 0 (project default).
 */

#include "common.h"

extern void func_800B8CBC(u8, u8, u8);
extern s32 func_800E7188(s32);
extern f32 _scinfobar_entrypoint_18(s32);
extern void func_800B8DEC(void *, s32, s32, u8);
extern s32 B_80800930_sccustom;
extern u8 B_80800940_sccustom[];
extern int D_80800920_sccustom;
extern s32 B_80800950_sccustom;

void func_80800000_sccustom(void *param_0, s32 param_1, s32 param_2, s32 param_3, u8 *param_4);
void func_80800264_sccustom(void *param_0, s32 param_1, s32 param_2, s32 param_3, u8 *param_4);
s32 * func_808004C8_sccustom(s32 param_0);
void sccustom_entrypoint_0(s32 param_0, s32 param_1, s32 param_2, s32 param_3);
s32 sccustom_entrypoint_1(s32 param_0, s32 param_1, s32 param_2, s32 param_3);
int sccustom_entrypoint_2(s32 param_0, s32 param_1, s32 param_2, s32 param_3);
s32 func_808006C4_sccustom(s32 param_0, s32 param_1);
s32 sccustom_entrypoint_3(s32 param_0);
s32 sccustom_entrypoint_4(s32 param_0);
s32 sccustom_entrypoint_5(s32 param_0);
s32 * func_8080084C_sccustom(s32 param_0);
void sccustom_entrypoint_6(s32 param_0, s32 param_1, s32 param_2, s32 param_3);
int sccustom_entrypoint_7(s32 param_0);
void func_80800000_sccustom(void *param_0, s32 param_1, s32 param_2, s32 param_3, u8 *param_4)
{
    s32 local_0;
    f32 local_1;
    s32 local_2;
    s32 local_3;
    u8 local_4;
    f32 local_5;
    f32 local_6;
    s32 local_7;
    s32 local_11;
    s32 local_8;
    f32 local_9;
    u8 local_10;

    local_0 = _scinfobar_entrypoint_11(param_1);
    local_1 = _scinfobar_entrypoint_18(param_1);
    local_2 = _scinfobar_entrypoint_15(param_1);
    func_800B8C50();
    switch (_scinfobar_entrypoint_17(param_1)) {
    case 0: break;
    case 1: func_800B8CBC(0x80, 0x80, 0x80); break;
    case 2:
        local_3 = (func_8001211C() << 5) & 0x1FF;
        if (local_3 >= 0x100) local_3 = 0x200 - local_3;
        local_3 *= 0.5f;
        local_4 = local_3 + 0x7F;
        func_800B8CBC(local_4, local_4, local_4);
        break;
    }
    local_5 = local_0;
    local_6 = 24.0f * local_1 + 4.0f;
    if (local_5 < local_6) {
        local_7 = (1.0f - (local_6 - local_5) / local_6) * 255.0f;
    } else {
        local_7 = 0xFF;
    }
    local_8 = func_800E7188((s32)param_4) - 1;
    func_800B8C8C(local_7);
    func_800B7F14(param_0);
    for (local_11 = local_8; local_11 >= 0; local_11--) {
        local_9 = local_6;
        local_9 += 8.0f * local_11;
        if (local_5 < local_9) local_9 = local_5;
        if (local_2 == 2) {
            local_9 = -local_9;
            local_10 = param_4[local_8 - local_11];
        } else {
            local_10 = param_4[local_11];
        }
        func_800B8DEC(param_0, (s32)(param_2 + local_9), param_3, local_10);
    }
    func_800B811C(param_0);
}

void func_80800264_sccustom(void *param_0, s32 param_1, s32 param_2, s32 param_3, u8 *param_4)
{
    s32 local_0;
    f32 local_1;
    s32 local_2;
    s32 local_3;
    u8 local_4;
    f32 local_5;
    f32 local_6;
    s32 local_7;
    s32 local_11;
    s32 local_8;
    f32 local_9;
    u8 local_10;

    local_0 = _scinfobar_entrypoint_11(param_1);
    local_1 = _scinfobar_entrypoint_18(param_1);
    local_2 = _scinfobar_entrypoint_15(param_1);
    func_800B8C50();
    switch (_scinfobar_entrypoint_17(param_1)) {
    case 0: break;
    case 1: func_800B8CBC(0x80, 0x80, 0x80); break;
    case 2:
        local_3 = (func_8001211C() << 5) & 0x1FF;
        if (local_3 >= 0x100) local_3 = 0x200 - local_3;
        local_3 *= 0.5f;
        local_4 = local_3 + 0x7F;
        func_800B8CBC(local_4, local_4, local_4);
        break;
    }
    local_5 = local_0;
    local_6 = 24.0f * local_1 + 4.0f;
    if (local_5 < local_6) {
        local_7 = (1.0f - (local_6 - local_5) / local_6) * 255.0f;
    } else {
        local_7 = 0xFF;
    }
    local_8 = func_800E7188((s32)param_4) - 1;
    func_800B8C8C(local_7);
    func_800B7F14(param_0);
    for (local_11 = local_8; local_11 >= 0; local_11--) {
        local_9 = local_6;
        local_9 += 10.0f * local_11;
        if (local_5 < local_9) local_9 = local_5;
        if (local_2 == 2) {
            local_9 = -local_9;
            local_10 = param_4[local_8 - local_11];
        } else {
            local_10 = param_4[local_11];
        }
        func_800B8DEC(param_0, (s32)(param_2 + local_9), param_3, local_10);
    }
    func_800B811C(param_0);
}

s32 *func_808004C8_sccustom(s32 param_0) {
    func_800E73D4(&B_80800930_sccustom);
    func_800E6DB4(&B_80800930_sccustom, _scinfobar_entrypoint_19(param_0));
    return &B_80800930_sccustom;
}

int func_8080050C_sccustom(param_0, param_1) s32 param_0; u8 param_1;
{
  func_800E73D4(&B_80800940_sccustom);
  func_800E6DB4(&B_80800940_sccustom, _scinfobar_entrypoint_19(param_0));
  func_800E6A58(&B_80800940_sccustom, param_1);
  func_800E6DB4(&B_80800940_sccustom, _scinfobar_entrypoint_20(param_0));
  return &B_80800940_sccustom;
}

void sccustom_entrypoint_0(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_0;

    local_0 = func_808004C8_sccustom(param_1 | 0);
    func_80800000_sccustom(param_0, param_1, param_2, param_3, local_0);
}

s32 sccustom_entrypoint_1(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    if (_scinfobar_entrypoint_19(param_1) == 0x3E7) {
        func_80800264_sccustom(param_0, param_1, param_2, param_3, D_80800920_sccustom);
        return;
    }
    func_80800000_sccustom(param_0, param_1, param_2, param_3, func_808004C8_sccustom(param_1));
}

int sccustom_entrypoint_2(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 local_0;
  s32 local_1;
  local_0 = _scinfobar_entrypoint_19(param_1 | 0);
  local_1 = _scinfobar_entrypoint_20(param_1 | 0);
  if (local_1 == local_0)
  {
    _scinfobar_entrypoint_5(param_1 | 0, 1);
  }
  local_0 = func_8080050C_sccustom(param_1 | 0, 0x2F);
  func_80800000_sccustom(param_0, param_1 | 0, param_2, param_3, local_0);
}

s32 func_808006C4_sccustom(s32 param_0, s32 param_1)
{
    s32 local_0;
    f32 local_1;

    local_0 = func_800E7188(param_1);
    local_1 = _scinfobar_entrypoint_18(param_0);
    if (local_0 < 3) {
        local_0 = 3;
    }
    local_0--;
    return 24.0f * local_1 + 4.0f + 8.0f * local_0;
}

s32 sccustom_entrypoint_3(s32 param_0){
    s32 local_0;
    local_0 = func_808004C8_sccustom(param_0);
    func_808006C4_sccustom(param_0, local_0 | 0);
}

s32 sccustom_entrypoint_4(s32 param_0)
{
    s32 local_0;
    f32 local_1;

    if (_scinfobar_entrypoint_19() == 0x3E7) {
        local_0 = func_800E7188(D_80800920_sccustom);
        local_1 = _scinfobar_entrypoint_18(param_0);
        if (local_0 < 3) {
            local_0 = 3;
        }
        local_0--;
        return (s32)(24.0f * local_1 + 4.0f + 10.0f * local_0);
    }
    return func_808006C4_sccustom(param_0, func_808004C8_sccustom(param_0));
}

s32 sccustom_entrypoint_5(s32 param_0){
    func_808006C4_sccustom(param_0, func_8080050C_sccustom(param_0, 0x2F));
}

s32 *func_8080084C_sccustom(s32 param_0) {
    func_800E73D4(&B_80800950_sccustom);
    func_800DB8BC(&B_80800950_sccustom, _scinfobar_entrypoint_19(param_0));
    return &B_80800950_sccustom;
}

void sccustom_entrypoint_6(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_0;

    local_0 = func_8080084C_sccustom(param_1);
    func_80800000_sccustom(param_0, param_1, param_2, param_3, local_0);
}

int sccustom_entrypoint_7(s32 param_0)
{
  u32 local_0;
  local_0 = func_8080084C_sccustom(param_0);
  func_808006C4_sccustom(param_0, local_0 | 0);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/sc/custom.data.s) is defined here in C.
 * Values are taken from the ROM. */
int D_80800920_sccustom = (u32)"LOTS";
static u32 D_80800920_sccustom_rest[3] = { 0x0, 0x0, 0x0 };
