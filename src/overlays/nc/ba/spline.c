#include "common.h"

extern s32 func_800D5424(s32);
typedef struct { s32 local_0; s32 local_1; f32 local_2; f32 local_3[3]; f32 local_4; f32 local_5[3]; s32 local_6; u8 local_7; u8 local_8; u8 local_9; u8 local_10; } SplineState48;
extern f32 func_800C82CC(s32, f32 *);
extern f32 func_800FB1EC(s32, f32, f32 *, s32);
extern void func_800C7A68(s32, f32, f32 *);
extern void _gspropctrl_entrypoint_11(void *, f32 *);
extern void *_gccubesearch_entrypoint_14(s32, s32 *);
extern f32 func_800C7B28(s32, f32, f32, s32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern f32 func_800C7FD4(s32, f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void func_800EF334(f32 *, f32);
extern void func_800EE780();
extern void func_80110770();
extern void func_80110790();
extern void func_801107F0();
extern void func_80110A68();
extern void func_80112524();
void ncbaspline_entrypoint_7();
s32 func_80800318_ncbaspline();

s32 ncbaspline_entrypoint_0() 
{
    return 0x30;
}

int func_80800008_ncbaspline(u8 *param_0) {
    func_800D7520(*(*(s32 **)((s8 *)(param_0) + 0x44)));
}

void func_8080002C_ncbaspline(param_0) u8 *param_0; {
    u8 *local_0;

    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x44)))) + (0))) = -1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x44)))) + (4))) = 0.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x44)))) + (8))) = 0.0f;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x44)))) + (0x28))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x44)))) + (0x2C))) = 0;
    (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x44)))) + (0x2F))) = 0U;
    local_0 = (*(u8 **)((s8 *)(param_0) + (0x44)));
    (*(u8 *)((s8 *)(local_0) + (0x2E))) = (u8) (*(u8 *)((s8 *)(local_0) + (0x2F)));
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0x44))) + 0xC, param_0);
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0x44))) + 0x1C, param_0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x44)))) + (0x18))) = 0.0f;
}

void ncbaspline_entrypoint_1()
{
    func_8080002C_ncbaspline();
}

int ncbaspline_entrypoint_2(Actor *param_0)
{
  func_801124D0(param_0, 0x1);
  func_80111B8C(param_0, 0x40400000, 0x41000000);
}

void ncbaspline_entrypoint_3()
{
    func_8080002C_ncbaspline();
}

s32 func_80800130_ncbaspline(s32 param_0, s32 param_1){
    s32 local_0;

    local_0 = func_80112518(param_0);
    func_801124D0(param_0, 1);
    func_80112524(param_0, param_1);
    func_801124D0(param_0, local_0);
}

f32 func_8080017C_ncbaspline(u8 *param_0, s32 param_1, f32 *param_2, f32 *param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5;
    local_4 = func_800C82CC(param_1, param_2);
    if (local_4 == 0.0f || local_4 == 1.0f) {
        func_800C7A68(param_1, local_4, local_1);
        if (local_4 == 0.0f) { func_800C7A68(param_1, local_4 + 0.001f, local_2); }
        else { func_800C7A68(param_1, local_4 - 0.001f, local_2); }
        func_800EFB24(local_3, local_2, local_1);
        func_800EF368(local_3, 400.0f);
        func_800EE780(local_2, local_3, local_1);
        func_800F018C(local_0, local_1, local_2, param_2);
        return func_800EEAD4(local_0, param_3);
    }
    func_800C7A68(param_1, local_4, local_0);
    local_5 = (*(f32 **)(param_0 + 0x44))[2];
    if (local_4 < local_5) { return func_800C7B28(param_1, local_4, local_5, 0xF); }
    else { return func_800C7B28(param_1, local_5, local_4, 0xF); }
}

s32 func_80800318_ncbaspline(param_0, param_1) u8 *param_0; f32 *param_1;
{
    Vec3f local_0;
    Vec3f local_1;
    Vec3f local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;
    f32 local_9;
    s32 local_10;

    local_10 = func_80800008_ncbaspline(param_0);
    func_80800130_ncbaspline(param_0, local_2.f);
    local_9 = func_8080017C_ncbaspline(param_0, local_10, local_2.f, param_1);
    local_5 = func_800C7FD4(local_10, (*(f32 **)(param_0 + 0x44))[2], 1000.0f);
    local_6 = func_800C7FD4(local_10, (*(f32 **)(param_0 + 0x44))[2], -1000.0f);
    func_800C7A68(local_10, local_5, local_0.f);
    func_800C7A68(local_10, local_6, local_1.f);
    local_3 = func_800EEAD4(local_2.f, local_0.f);
    local_4 = func_800EEAD4(local_2.f, local_1.f);
    local_7 = 0.0f;
    if (mlAbsF(local_3 - local_4) > 3.0f) {
        local_8 = local_3 < local_4 ? 1.0f : -1.0f;
        if (local_9 > 550.0f) {
            local_7 = func_800F10B4(local_9, 550.0f, 650.0f, 0.0, 1500.0f) * local_8;
        } else if (local_9 < 500.0f) {
            local_7 = func_800F10B4(local_9, 4e+02f, 500.0f, 1500.0f, 0.0f) * -local_8;
        }
        if (mlAbsF((*(f32 **)(param_0 + 0x44))[1]) < mlAbsF(local_7)) {
            (*(f32 **)(param_0 + 0x44))[1] +=
                (local_7 - (*(f32 **)(param_0 + 0x44))[1]) * 0.08f;
        } else {
            (*(f32 **)(param_0 + 0x44))[1] = local_7;
        }
        (*(f32 **)(param_0 + 0x44))[2] = func_800C7FD4(local_10,
            (*(f32 **)(param_0 + 0x44))[2], (*(f32 **)(param_0 + 0x44))[1]);
        if ((local_7 > 0.0f && (*(f32 **)(param_0 + 0x44))[2] == 1.0f &&
            (*(u8 **)(param_0 + 0x44))[0x2F] == 0) ||
            (local_7 < 0.0f && (*(f32 **)(param_0 + 0x44))[2] == 0.0f &&
            (*(u8 **)(param_0 + 0x44))[0x2E] == 0)) {
            return 0;
        }
    } else {
        return 1;
    }
    if (local_7) {
        return 1;
    }
    return 2;
}

void ncbaspline_entrypoint_4(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3[3];
    f32 local_4[3];
    if (**(s32 **)(param_0 + 0x44) == -1) { return; }
    if ((*(u8 **)(param_0 + 0x44))[0x2C] == 1) { (*(u8 **)(param_0 + 0x44))[0x2C] = 2; }
    func_801107F0(param_0, local_3);
    if (*(s32 *)(*(u8 **)(param_0 + 0x44) + 0x28) == -1 ||
        !func_80800318_ncbaspline(param_0, local_3)) {
        *(s32 *)(*(u8 **)(param_0 + 0x44) + 0x28) = 0;
        return;
    }
    func_800C7A68(func_80800008_ncbaspline(param_0), *(f32 *)(*(u8 **)(param_0 + 0x44) + 8), local_3);
    if (*(f32 *)(*(u8 **)(param_0 + 0x44) + 0x18) < 1.0f) {
        local_2 = func_800F10B4(*(f32 *)(*(u8 **)(param_0 + 0x44) + 0x18), 0.5f, 1.0f, 0.05f, 0.01f);
        *(f32 *)(*(u8 **)(param_0 + 0x44) + 0x18) += (30.0f * func_800D8FF8()) * local_2;
        if (*(f32 *)(*(u8 **)(param_0 + 0x44) + 0x18) < 1.0f) {
            func_800EFB24(local_1, local_3, *(u8 **)(param_0 + 0x44) + 0xC);
            func_800EF334(local_1, *(f32 *)(*(u8 **)(param_0 + 0x44) + 0x18));
            func_800EE780(local_3, *(u8 **)(param_0 + 0x44) + 0xC, local_1);
        }
    }
    func_80110770(param_0, local_3);
    func_80112524(param_0, local_0);
    func_80110A68(param_0, local_4, local_0);
    func_80110790(param_0, local_4);
}

void ncbaspline_entrypoint_5(void *param_0, int param_1, int param_2)
{
  int *local_0;

  local_0 = (int *)*((int *)param_0 + 0x11);
  if (local_0[0xa] != 0)
  {
    local_0[0xa] = -1;
  }
}

void ncbaspline_entrypoint_6(s32 param_0, u8 *param_1, s32 param_2) {
    ncbaspline_entrypoint_7(param_0, func_800D5424(*(u16 *)(param_1 + 8)));
}

void ncbaspline_entrypoint_7(param_0, param_1) u8 *param_0; s32 param_1;
{
    f32 local_0[3];
    s32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    s32 local_5;
    void *local_4;

    local_5 = func_80110840(param_0);
    if (func_800F5C94(local_5) != 4) {
        local_3 = func_800D542C(param_1);
        if (local_3 != (*(SplineState48 **)(param_0 + 0x44))->local_6 &&
            (*(SplineState48 **)(param_0 + 0x44))->local_6 != -1) {
            func_801107B0(param_0, local_0);
            func_800EE904(local_1, local_0);
            local_4 = _gccubesearch_entrypoint_14(local_3, local_1);
            if (local_4 != NULL) {
                _gspropctrl_entrypoint_11(local_4, local_0);
                switch (_gspropctrl_entrypoint_13(local_4)) {
                case 1:
                    (*(SplineState48 **)(param_0 + 0x44))->local_9 = 1;
                    (*(SplineState48 **)(param_0 + 0x44))->local_10 = 0;
                    break;
                case 2:
                    (*(SplineState48 **)(param_0 + 0x44))->local_9 = 0;
                    (*(SplineState48 **)(param_0 + 0x44))->local_10 = 1;
                    break;
                case 3:
                    (*(SplineState48 **)(param_0 + 0x44))->local_9 = 1;
                    (*(SplineState48 **)(param_0 + 0x44))->local_10 = 1;
                    break;
                default:
                    (*(SplineState48 **)(param_0 + 0x44))->local_9 = 0;
                    (*(SplineState48 **)(param_0 + 0x44))->local_10 = 0;
                    break;
                }
                (*(SplineState48 **)(param_0 + 0x44))->local_8 = func_801106A0(param_0);
                func_801107F0(param_0, local_2);
                func_800EE7F8((*(SplineState48 **)(param_0 + 0x44))->local_3, local_2);
                (*(SplineState48 **)(param_0 + 0x44))->local_4 = 0.0f;
                (*(SplineState48 **)(param_0 + 0x44))->local_6 = local_3;
                (*(SplineState48 **)(param_0 + 0x44))->local_0 = _glsplinefind_entrypoint_3(local_0);
                (*(SplineState48 **)(param_0 + 0x44))->local_2 = func_800C82CC(func_80800008_ncbaspline(param_0), local_2);
                (*(SplineState48 **)(param_0 + 0x44))->local_2 = func_800FB1EC(func_80800008_ncbaspline(param_0),
                    (*(SplineState48 **)(param_0 + 0x44))->local_2, local_2, 0x20020);
                (*(SplineState48 **)(param_0 + 0x44))->local_7 = 1;
                func_800C7A68(func_80800008_ncbaspline(param_0),
                    (*(SplineState48 **)(param_0 + 0x44))->local_2,
                    (*(SplineState48 **)(param_0 + 0x44))->local_5);
                if (func_80800318_ncbaspline(param_0, (*(SplineState48 **)(param_0 + 0x44))->local_5) == 1) {
                    func_801106A8(param_0, 14);
                    func_800F7E9C(func_80110840(param_0), 1);
                } else {
                    (*(SplineState48 **)(param_0 + 0x44))->local_6 = 0;
                }
            }
        }
    }
}

int ncbaspline_entrypoint_8(void *param_0) {
    return (*(int **)((char *)param_0 + 0x44))[0x28 / 4] < 1;
}
