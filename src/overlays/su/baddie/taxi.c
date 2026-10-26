#include "common.h"

extern void func_8010D254(f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_80090010(void);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_800CB45C(s32, f32 *, s32 *, s32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern u8 D_80800D5C_subaddietaxi[];
extern void func_800DFF64();
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef union { f32 local_0; s32 local_1; } TaxiCallbackFloatWord1001;
extern void _subaddiefade_entrypoint_1();
extern Actor *func_80106790(Unk80132ED0 *);
extern void *func_80104248(Actor *);
extern void func_8008AEE4();
extern void func_8008AF04(void *, s32);
extern void _subaddietaxi_entrypoint_6(Actor *, f32);
typedef struct { u8 pad[0x48]; s32 f48; u8 pad4C[0x18]; u32 pad64:14; u32 flag:1; u32 rest:17; } TaxiS;
extern s32 func_800EA05C(void);
extern void func_800CB6B4();
extern void _subaddieaudioquick_entrypoint_2(s32, s32, void *);
extern void func_800BBCB8(s32, s32, f32, s32, void *);
extern s32 D_80800D50_subaddietaxi;
extern s32 D_80800D74_subaddietaxi;
typedef struct { s32 local_0; s32 local_1; f32 local_2; f32 local_3[3]; } TaxiSpawn62;
extern Actor *func_80108474(s32, f32 *, s32);
extern void func_8010108C(Actor *, s32, s32);
extern s16 D_80800DB4_subaddietaxi[];
extern void *func_8010410C();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_8001395C(f32);
extern f32 func_800CB3FC(s32, f32 *, s32 *);
extern void func_800CB534(s32, f32 *, f32);
extern f32 func_800F2094(f32, f32);
extern int func_800F1884(f32[3], f32 *);
extern int func_800C696C(f32[3], f32, f32, u32, f32 *);
extern int func_800E1610(s32, f32, f32, f32[3]);
extern u8 D_80800D68_subaddietaxi[];
s32 func_80800CF0_subaddietaxi();

void subaddietaxi_entrypoint_0(u8 *param_0, s32 param_1, u8 *param_2, s32 param_3) {
    u8 *local_0;

    local_0 = func_8010410C();
    if (param_3 >= 0) {
        func_80102424(param_0, param_3);
    }
    func_800EE7F8(local_0, param_0 + 4);
    func_800EE7F8(local_0 + 0xC, param_2);
    *(f32 *)((char *)local_0 + 0x18) = *(f32 *)((char *)param_0 + 0x38);
    *(f32 *)((char *)param_0 + 0x38) = 0.05f;
    *(f32 *)((char *)local_0 + 0x1C) = 0.5f;
}

void func_80800C00_subaddietaxi();

s32 subaddietaxi_entrypoint_1(Actor *param_0, s32 param_1)
{
    f32 *local_2;
    s32 local_0;
    f32 local_1;
    local_2 = func_8010410C(param_0);
    local_0 = func_800CB518(param_1);
    func_800CB698(param_1, 6);
    if (local_2[7] == 0.0f) { return 1; }
    if (local_0 & 1) { _fxsparkle_entrypoint_1(param_0->position, 0xB); }
    func_800D9078(local_2 + 7);
    local_1 = func_800F10B4(local_2[7], 0.0f, 0.5f, 0, 1.0f);
    param_0->scale = func_800F1214(local_1, local_2[6], 0.05f);
    func_800EFE50(param_0->position, local_2 + 3, local_2, local_1);
    param_0->position[1] += func_8001395C(local_1 * 3.1415927f) * 200.0f;
    func_80104580(param_0);
    if (local_2[7] == 0.0f) {
        local_2[6] = local_2[7];
        func_800EFD24(local_2);
        func_800EFD24(local_2 + 3);
        if (local_0 & 4) { func_800E1610(0, 20.0f, 0.9f, param_0->position); }
        if (local_0 & 2) { func_80800C00_subaddietaxi(param_0); }
        return 1;
    }
    return 0;
}

s32 func_80800220_subaddietaxi(Actor *param_0, f32 param_1)
{
    f32 local_0[3];
    f32 local_2;
    f32 local_1;

    func_8010D254(local_0);
    local_1 = func_800F1DF4(local_0, param_0->position);
    local_2 = func_80090010();
    return mlAbsF(func_800F1DCC(local_2, local_1)) < param_1;
}

int subaddietaxi_entrypoint_2(s32 *param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800CB3E0(param_1);
  if ((local_0 != 1) && (local_0 != 5))
  {
    return 0;
  }
  if (func_80800220_subaddietaxi(param_0, 9e+01f) == 0)
  {
    return 0;
  }
  if (_subaddiefade_entrypoint_0(param_0) < 0x78)
  {
    return 0;
  }
  return func_8008FCC8(*param_0) == 0x13 && func_800905C4(*param_0, param_1) != 0;
}

void subaddietaxi_entrypoint_3(void) {
}

void subaddietaxi_entrypoint_4(void)
{
    f32 local_0[3];
    f32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_1;

    local_3 = func_800EA05C();
    for (local_4 = 1; local_4 != 16; local_4++) {
        switch (func_800CB3E0(local_4)) {
            case 0:
            case 2:
            case 3:
            case 4:
                break;
            case 1:
                local_2 = func_800CB3FC(local_4, local_0, &local_1);
                if (local_1 == local_3) {
                    func_800CB534(local_4, local_0, local_2);
                }
                break;
            case 5:
                func_800CB70C(local_4);
                func_800CB698(local_4, 1);
                local_2 = func_800CB3FC(local_4, local_0, &local_1);
                if (local_1 == local_3) {
                    func_800CB534(local_4, local_0, local_2);
                }
                break;
            case 6:
                local_2 = func_800CB3FC(local_4, local_0, &local_1);
                if (local_1 == local_3) {
                    func_800CB534(local_4, local_0, local_2);
                }
                break;
                default:
            break;
}
    }
}

s32 subaddietaxi_entrypoint_5(Actor *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    f32 local_2[3];
    f32 local_3;
    s32 local_4;

    local_4 = 0;
    local_3 = func_800CB45C(param_1, local_2, &local_0, &local_1);
    if (func_800EA05C() == local_0) {
        param_0->rotation[1] = local_3;
        func_800EE7F8(param_0->position, local_2);
        param_0->unk74_7 = local_1;
        local_4 = 1;
        _subaddiefade_entrypoint_2(param_0);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800D5C_subaddietaxi);
    } else func_800FFAB0(param_0);
    func_800CB698(param_1, 1);
    func_800CB70C(param_1);
    return local_4;
}

void subaddietaxi_entrypoint_6(Actor *param_0, TaxiCallbackFloatWord1001 param_1)
{
    f32 local_0[3];
    if (1) {}
    func_800EFA4C(local_0, param_1.local_0, param_1.local_0, param_1.local_0);
    func_800DFF64(param_0, 0x12, local_0);
}

void subaddietaxi_entrypoint_7(Unk80132ED0 *param_0)
{
    Actor *local_0;
    f32 *local_1;
    void *local_2;
    TaxiCallbackFloatWord1001 local_3;
    local_0 = func_80106790(param_0);
    local_1 = func_8010410C();
    local_2 = func_80104248(local_0);
    func_800EE7F8(local_1, local_0->position);
    local_1[6] = local_0->scale;
    func_8008AEE4(local_2, _subaddietaxi_entrypoint_6);
    local_3.local_0 = 1.0f;
    func_8008AF04(local_2, local_3.local_1);
    _subaddiefade_entrypoint_1((u8 *)local_0, 0xFF);
}

void subaddietaxi_entrypoint_8(Unk80132ED0 *param_0, f32 *param_1, f32 param_2, f32 param_3, s32 param_4)
{
    Actor *local_2;
    f32 *local_1;
    s32 pad;
    TaxiCallbackFloatWord1001 local_0;

    local_2 = func_80106790(param_0);
    local_1 = func_8010410C();
    if (func_800CB518(param_4) & 1) {
        _fxsparkle_entrypoint_1(local_2->position, 11);
    }
    func_800EFE50(local_2->position, param_1, local_1, param_2);
    local_2->scale = func_800F10B4(param_3, 0.0f, 1.0f, 0.01f, local_1[6]);
    if (0.45f < param_3) {
        local_0.local_0 = 1 / param_3;
    } else {
        local_0.local_0 = func_800F10B4(param_3, 0.0f, 0.45f, 0.01f, 1.0f / param_3);
    }
    func_8008AF04(func_80104248(local_2), local_0.local_1);
}

void subaddietaxi_entrypoint_9(TaxiS *param_0, s32 param_1) {
    if (!param_0->flag) {
        func_800CB6B4(param_1, (u8 *)param_0 + 4, param_0->f48, func_800EA05C());
    }
}

int subaddietaxi_entrypoint_10(s32 param_0, s32 param_1, s32 param_2)
{
  Actor *local_0;
  local_0 = func_8010410C();
  if (param_2 >= 0)
  {
    func_80102424(param_0 | 0, param_2);
  }
  (*(f32 *)((char *)(param_0) + 0x34)) = -6800.0f;
  func_800EEB9C((f32 *)((char *)(param_0) + 0x28), (*(s32 *)((char *)(param_0) + 0x48)), 0x43960000);
  (*(f32 *)((char *)(param_0) + 0x2C)) = 1800.0f;
  (*(f32 *)((char *)(param_0) + 0x18)) = 8.0f;
  (*(f32 *)((char *)(param_0) + 0x1C)) = (*(f32 *)((char *)(param_0) + 0x38));
  (*(f32 *)((char *)(param_0) + 0x38)) = 0.05f;
  _subaddieDll_entrypoint_4(param_0, 1);
  (*(u16 *)((char *)(local_0) + 0x20)) = 0;
}

s32 subaddietaxi_entrypoint_11(Actor *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    f32 local_5[3];
    f32 local_6;
    f32 *local_8;
    f32 local_7;

    local_0 = func_8010410C();
    func_800CB698(param_1, 5);
    func_800D9078(param_0->actorData);
    if (((f32 *)param_0->actorData)[7] != 0.0f) {
        local_2 = func_800CB518(param_1);
        if (local_2 & 1) {
            _fxsparkle_entrypoint_1(param_0->position, 0xB);
        }
        local_3 = func_8010B990(param_0, 0x204024);
        if (local_3 & 0x28) {
            local_4 = local_3 & 8;
            if (local_3 & 0x20) {
                func_8010AA54(local_5);
                if (func_800F1884(local_5, &local_6)) {
                    if (func_800F2094(local_6, 90.0f) < 45.0f) {
                        local_4 = (local_3 & 8) + 1;
                    }
                } else if (local_5[1] > 0.0f) {
                    local_4 = (local_3 & 8) + 1;
                }
            }
            if (local_4) {
                local_8 = param_0->position;
                func_800EFD24(&param_0->actorData[4]);
                ((f32 *)param_0->actorData)[7] = 0.0f;
                if (func_800C696C(local_8, 50.0f, -50.0f, param_0->unk14, &local_7) && param_0->position[1] < local_7) {
                    param_0->position[1] = local_7;
                }
                if (local_2 & 4) {
                    func_800E1610(0, 20.0f, 0.9f, local_8);
                }
                if (local_2 & 2) {
                    func_80800C00_subaddietaxi(param_0);
                }
            }
        }
    }
    local_1 = _subaddiefade_entrypoint_0(param_0);
    _subaddiefade_entrypoint_1(param_0, (s32)func_800F10B4(((f32 *)param_0->actorData)[0], 0, 1.0f, 0.0f, 255.0f));
    param_0->scale = func_800F10B4(((f32 *)param_0->actorData)[0], 7.7f, 8.0f, ((f32 *)param_0->actorData)[1], 0.05f);
    if (local_1 == 255 && _subaddiefade_entrypoint_0(param_0) != 255) {
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800D68_subaddietaxi);
    }
    if (_subaddiefade_entrypoint_0(param_0) != 255) {
        func_801078DC(param_0, local_0 + 0x20);
    }
    if (((f32 *)param_0->actorData)[0] == 0.0f || param_0->position[1] < -30000.0f) {
        _subaddieDll_entrypoint_4(param_0, 0);
        return 1;
    }
    return 0;
}

int subaddietaxi_entrypoint_12(struct Actor *param_0, s32 param_1)
{
    return *(f32 *)((char *)param_0 + 0x34) == 0.0f;
}

int subaddietaxi_entrypoint_13(s32 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  local_0 = func_800CB4D0(param_1 | 0, param_2 | 0, param_3 | 0);
  if (local_0 != 0)
  {
    local_1 = func_800EA05C();
    local_2 = func_800CB764(param_1, param_0 + 1, (*(s32 *)((char *)(param_0) + 0x48)), local_1, (u32)((u16)(*(s32 *)((char *)(param_0) + 0x74))) >> 7);
    func_800CB70C(param_1);
  }
  (*(s32 *)((char *)(param_0) + 0x14)) = 0x420021;
  return local_0;
}

void subaddietaxi_entrypoint_14(s32 param_0, s32 param_1) {
    (*(s16 *)((s8 *)(func_8010410C()) + (0x20))) = 0;
    _subaddieDll_entrypoint_4(param_0, 1);
}

s32 subaddietaxi_entrypoint_15(s32 param_0, s32 param_1)
{
  unsigned long local_0;
  func_801078DC(param_0, (s32)func_8010410C() + 0x20);
  local_0 = _subaddiefade_entrypoint_0(param_0);
  if (local_0 == 0xFF)
  {
    _subaddieDll_entrypoint_4(param_0, 0);
    return 1;
  }
  return 0;
}

void func_80800C00_subaddietaxi(s32 param_0)
{
  func_800BBCB8(param_0 + 4, param_0 + 4, 1.0f, 6, &D_80800D74_subaddietaxi);
  _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80800D50_subaddietaxi);
}

void subaddietaxi_entrypoint_16(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    Actor *local_1;
    TaxiSpawn62 local_0;

    local_0.local_1 = *(s32 *)&param_0;
    local_0.local_3[0] = *(f32 *)&param_1;
    local_0.local_3[1] = *(f32 *)&param_2;
    local_0.local_3[2] = *(f32 *)&param_3;
    local_0.local_2 = *(f32 *)&param_4;
    local_0.local_0 = param_5;
    local_1 = func_80108474(func_80800CF0_subaddietaxi(local_0.local_1),
        local_0.local_3, (s32)local_0.local_2);
    local_1->unk74_7 = local_0.local_0;
    func_8010108C(local_1, 0x44, local_0.local_1);
}

s32 func_80800CF0_subaddietaxi(param_0) s32 param_0;
{
  return D_80800DB4_subaddietaxi[param_0];
}
