#include "common.h"

extern int D_80800DB0_chswitch;
extern void *D_80800DC4_chswitch;
extern void *D_80800DD8_chswitch;
extern Actor *func_80106790();
extern void func_80103110(Actor *, s32);
extern void _gcaudiolist_entrypoint_0(s32);
typedef struct { u8 pad_0[0x50]; void *local_0; } SwitchPlayerOwner;
extern void *func_800F5410(s32);
extern s32 func_80101E14(Actor *, f32);
extern void func_80101EE4(Actor *, f32);
extern f32 func_800D8FF8(void);
extern void func_800F7F98(s32, s32);
extern Unk80132ED0 *func_800F55D0(s32);
int func_8080093C_chswitch();

int chswitch_entrypoint_0()
{
    return (int)&D_80800DB0_chswitch;
}

int chswitch_entrypoint_1()
{
  return &D_80800DC4_chswitch;
}

void *chswitch_entrypoint_2(void)
{
    return &D_80800DD8_chswitch;
}

void func_80800024_chswitch(Unk80132ED0 *param_0, s32 param_1)
{
    Actor *local_0;

    local_0 = func_80106790(param_0);
    if (!(local_0->unk58 > 0.0f) && func_8008FCC8(param_0) == 2) {
        local_0->unk64_20 = (s32)local_0->unk64_20 ^ 1;
        local_0->unk58 = 2.0f;
        func_80103110(local_0, 1);
    }
}

void func_808000B8_chswitch(Unk80132ED0 *param_0, s32 param_1)
{
    Actor *local_0;

    local_0 = func_80106790(param_0);
    if (!(local_0->unk58 > 0.0f)) {
        local_0->unk64_20 = (s32)local_0->unk64_20 ^ 1;
        local_0->unk58 = 2.0f;
        func_80103110(local_0, 1);
    }
}

void func_8080012C_chswitch(Unk80132ED0 *param_0, u8 *param_1)
{
    Actor *local_0;
    local_0 = func_80106790(param_0);
    if (func_8008FCC8(param_0) == 1 && (int)local_0->unk70_10 == 1) {
        _gcaudiolist_entrypoint_0(0);
        func_80102424(local_0, 2);
        local_0->actorData[4] = (u32)*(u16 *)(param_1 + 0x1A) >> 5;
        func_800F7F98(local_0->actorData[4], 1);
    }
}

int chswitch_entrypoint_3(void *param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800DA298(param_1 | 0);
  *((s32 *) (((char *) param_0) + 0x34)) = param_1;
  func_80103110(param_0, 0);
  if (!param_0) { }
  *((float *) (((char *) param_0) + 0x54)) = 0.75f;
  if (1)
  {
    func_80102E08();
    return local_0;
  }
}

void chswitch_entrypoint_4(Actor *param_0)
{
    if (param_0->unk70_10 == 2 && func_80101DDC() &&
        !param_0->unk64_20 && func_800D9078(&param_0->unk54)) {
        param_0->unk64_20 = 1;
        func_80102424(param_0, 3);
        func_80103110(param_0, 0);
        func_800F7F98(param_0->actorData[4], 0);
        func_800DA544(param_0->actorData[7]);
        func_8010108C(param_0, 7, 0);
    }
}

void func_808002B4_chswitch(s32 param_0, u8 *param_1)
{
  u16 new_var4;
  u8 *local_0;
  u8 *new_var3;
  u32 local_1;
  char *new_var;
  char *new_var2;
  local_0 = func_80106790();
  if (func_8008FCF4(param_0) == 1)
  {
    new_var2 = ((char *) param_1) + 0x1A;
    _gcaudiolist_entrypoint_0(0);
    new_var = ((char *) local_0) + 0x28;
    new_var3--;
    new_var3++;
    func_80102424(local_0, 2);
    new_var3 = local_0;
    func_8010A570(new_var3);
    func_80103110(local_0, 1);
    *((u32 *) new_var) = (local_1 = ((u32) (new_var4 = (*((u16 *) new_var2)) ^ 0)) >> 5);
    func_800F7F98(local_1, 1);
  }
}

s32 chswitch_entrypoint_5(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x29:
        return func_8080093C_chswitch(param_0);
    case 0x91:
        if (param_0->unk70_10 == 1) {
            _gcaudiolist_entrypoint_0(0);
            func_80102424(param_0, 2);
            func_8010A570(param_0);
            func_80103110(param_0, 1);
            param_0->actorData[4] = param_2;
            func_800F7F98(param_2, 1);
            return 1;
        }
        return 0;
    case 0x95:
        if (func_800DA298(param_0->actorData[7])) {
            func_80102424(param_0, 3);
            param_0->unk64_20 = 1;
            func_8010A570(param_0);
        } else {
            func_80102424(param_0, 1);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void chswitch_entrypoint_6(Actor *param_0)
{
    s32 local_0;
    switch (param_0->unk70_10) {
    case 1: break;
    case 2:
        if (func_80101DDC(param_0)) func_80102424(param_0, 3);
        break;
    case 3:
        local_0 = _plsu_entrypoint_1(*(s32 *)&param_0->unk50);
        if (!param_0->unk64_20 && (local_0 + 1)) {
            if (func_800D9078(&param_0->unk54)) {
                func_800F7F98(local_0, 0);
                func_800DA544(param_0->actorData[7]);
                param_0->unk64_20 = 1;
                if (param_0->actorData[6]) func_80103110(param_0, 0);
                func_8010108C(param_0, 7, 0);
            }
        } else if (!param_0->unk6C_0 || !(local_0 + 1)) {
            if (func_800D90A4(&param_0->unk58)) {
                _gcaudiolist_entrypoint_0(0);
                func_80102424(param_0, 4);
                param_0->unk64_20 = 0;
                param_0->unk54 = 0.375f;
            }
        } else param_0->unk58 = 0.15f;
        break;
    case 4:
        if (func_80101DDC(param_0)) {
            func_80103110(param_0, 0);
            func_80102424(param_0, 1);
            func_800DA524(param_0->actorData[7]);
            *(s32 *)&param_0->unk50 = 0;
            func_8010108C(param_0, 8, 0);
        }
        break;
    }
    param_0->unk6C_0 = 0;
}

s32 chswitch_entrypoint_7(s32 param_0, s32 param_1)
{
    s32 local_1;

    local_1 = func_800DA298(param_1);
    *(s32 *)((char *)param_0 + 0x34) = param_1;
    if (local_1 != 0)
    {
        *(f32 *)((char *)param_0 + 0x54) = 0.0f;
        func_80102424(param_0, 3);
    }
    else
    {
        *(f32 *)((char *)param_0 + 0x54) = 0.375f;
        func_80102424(param_0, 1);
    }
    *(s32 *)((char *)param_0 + 0x2C) = -1;
    *(s32 *)((char *)param_0 + 0x50) = 0;
    *(s32 *)((char *)param_0 + 0x30) = 0;
    func_80102E08(param_0);
    return local_1;
}

void chswitch_entrypoint_8(u8 *param_0, s32 param_1) {
    *(s32 *)((u8 *)param_0 + 0x2C) = param_1;
}

void chswitch_entrypoint_9(void *param_0)
{
  int new_var4;
  s32 *new_var5;
  int new_var3;
  void *new_var2;
  void *new_var;
 new_var = param_0; if (1) { new_var2 = new_var; new_var4 = 5; new_var5 = (s32 *) new_var2; new_var4 = 0xC; ((s32 *) new_var2)[new_var4] = 1; ((s32 *) new_var2)[new_var4] = new_var5[new_var4] ^ 0;
  }
}

void func_80800694_chswitch(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;
    s32 local_2;
    s32 local_3;

    if (func_800DA298(param_0->actorData[7])) {
        local_1 = _plsu_entrypoint_0(local_0, param_0->position);
        func_80103110(param_0, param_0->actorData[6] == 0);
        if (!param_0->unk6C_0) {
            func_80102424(param_0, 3);
            if (param_0->actorData[6] == 0 && local_1 != -1) {
                param_0->unk64_20 = 1;
                ((SwitchPlayerOwner *)param_0)->local_0 = func_800F5410(local_1);
                param_0->unk6C_0 = 1;
            }
        } else {
            ((SwitchPlayerOwner *)param_0)->local_0 = func_800F5410(local_1);
        }
    }
}

s32 chswitch_entrypoint_10(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_3[4];
    s32 local_0;
    s32 local_1;
    s32 local_2;

    switch (param_1) {
        case 0x29:
            return func_8080093C_chswitch(param_0);
        case 0x32:
            *(s32 *)&param_0->unk50 = func_800F5410(param_2);
            param_0->unk58 = 0.15f;
            _gcaudiolist_entrypoint_0(0);
            param_0->unk54 = 0.375f;
            func_80102424(param_0, 2);
            func_80103110(param_0, 1);
            func_800F7F98(param_2, 1);
            break;
        case 0x91:
            local_1 = func_800F55FC(param_2) & 0x08000000;
            param_0->unk6C_0 = func_800DA298(0x9D4);
            *(s32 *)&param_0->unk50 = func_800F5410(param_2);
            if (!local_1 && param_0->unk70_10 == 1 &&
                func_800F64A4(param_2, param_0->actorData[5]) && func_800DA298(0x9D4)) {
                if (func_800F54E4() == param_2) {
                    local_0 = 0;
                    for (local_2 = 0; local_2 != 8; local_2++) {
                        if (func_800F6438(local_2) && local_2 != param_2 &&
                            func_800F6C5C(local_2) && func_800F55D0(local_2) == param_0->unk0) {
                            local_0 = 1;
                            break;
                        }
                    }
                    if (!local_0) {
                        func_800F7874(param_2, param_0->unk0, param_0->position);
                    }
                }
            }
            return 1;
        case 0x95:
            func_80800694_chswitch(param_0);
            return 1;
        default:
            return 0;
    }
    return 1;
}

int func_8080093C_chswitch(param_0) Actor *param_0;
{
    s32 local_0;
    if (func_800CB854(&local_0) == 1) {
        func_80100120(param_0);
        if (!param_0->unk64_17 && func_800DA298(param_0->actorData[7])) {
            func_80102424(param_0, 3);
            func_80102204(param_0);
            param_0->unk64_20 = 1;
            param_0->unk6C_0 = 1;
        }
    }
    return 1;
}

void chswitch_entrypoint_11(u8 *param_0) {
    u32 local_0;

    local_0 = (u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x72)))) >> 0xA;
    switch (local_0) {                              
    case 2:
        if (func_80101DDC(param_0) != 0) {
            func_800DA544((*(s32 *)((s8 *)(param_0) + (0x34))));
            func_80102424(param_0, 3);
            func_800F7F98((*(s32 *)((s8 *)(param_0) + (0x28))), 0);
            func_8010108C(param_0, 7, 0);
            return;
        }
    case 1:
        return;
    case 3:
        if (func_800DA298((*(s32 *)((s8 *)(param_0) + (0x2C)))) != 0) {
            func_800DA524((*(s32 *)((s8 *)(param_0) + (0x2C))));
            _gcaudiolist_entrypoint_0(0);
            func_80102424(param_0, 4);
            return;
        }
        break;
    case 4:
        if (func_80101DDC(param_0) != 0) {
            func_800DA524((*(s32 *)((s8 *)(param_0) + (0x34))));
            func_80102424(param_0, 1);
            func_8010108C(param_0, 8, 0);
        }
        break;
    }
}

void chswitch_entrypoint_12(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    local_0 = func_800DA298(param_1);
    *(s32 *)((u8 *)param_0 + 0x34) = param_1;
    *(s32 *)((u8 *)param_0 + 0x2C) = param_2;
    if (param_2 != -1) {
        func_800DA524(param_2);
    }
    func_80102424(param_0, local_0 ? 3 : 1);
    func_80102E08(param_0);
}

void chswitch_entrypoint_13(Actor *param_0)
{
    f32 local_0 = func_800D8FF8();
    switch (param_0->unk70_10) {
    case 1:
        if (param_0->unk64_20) {
            _gcaudiolist_entrypoint_0(0);
            func_80102424(param_0, 2);
        }
        if (param_0->unk58 <= 0.0f) {
            func_80103110(param_0, 0);
            return;
        }
        param_0->unk58 -= local_0;
        break;
    case 2:
        if (func_80101E14(param_0, 0.5f)) {
            func_80102424(param_0, 3);
            func_80101EE4(param_0, 0.5f);
            if (!func_800F6CC8(func_800F54E4())) {
                func_800DA544(param_0->actorData[7]);
                func_8010108C(param_0, 7, 0);
            }
        }
        break;
    case 3:
        if (!param_0->unk64_20) {
            _gcaudiolist_entrypoint_0(0);
            func_80102424(param_0, 4);
        }
        if (param_0->unk58 <= 0.0f) {
            func_80103110(param_0, 0);
            return;
        }
        param_0->unk58 -= local_0;
        break;
    case 4:
        if (func_80101DDC(param_0)) {
            func_800DA524(param_0->actorData[7]);
            func_80102424(param_0, 1);
            func_8010108C(param_0, 8, 0);
        }
        break;
    }
}

s32 chswitch_entrypoint_14(Actor *param_0, s32 param_1)
{
    s32 local_0;
    local_0 = func_800DA298(param_1);
    param_0->actorData[7] = param_1;
    if (local_0) {
        func_80102424(param_0, 3);
        func_80101EE4(param_0, 0.5f);
    } else func_80102424(param_0, 1);
    param_0->unk64_20 = local_0;
    func_80103110(param_0, 0);
    return local_0;
}
