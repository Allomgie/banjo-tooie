#include "common.h"
#include "playerstate.h"

extern s32 func_800EE7F8(s32);
extern f32 yaw_get(PlayerState *);
extern f32 func_800F1F0C(f32 *, f32 *, f32);
extern f32 mlAbsF(f32);
extern PlayerState *func_800F53D0(s32);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_set(PlayerState *, f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void yaw_applyIdeal(PlayerState *);
extern void func_800F90EC(f32);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern f32 func_800EEB40(f32 *, f32 *);
void baduo_entrypoint_7();
void baduo_entrypoint_10();
void baduo_entrypoint_11();
s32 func_80800C78_baduo();
int func_80800CA8_baduo();

s32 baduo_entrypoint_0() 
{
    return 0x14;
}

int func_80800008_baduo(s32 param_0, s32 param_1)
{
  s32 local_1;
  s32 local_0;
  local_0 = func_800A4C88(param_1);
  local_1 = func_800A4C88(param_0);
  func_801100E4(local_0, local_1);
}

s32 baduo_entrypoint_1(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x58)))[0];
}

int baduo_entrypoint_2()
{
    switch (func_800A3274()) {
        case 0xA:
            _plsu_entrypoint_1(0xB);
            break;
        case 0xB:
            _plsu_entrypoint_1(0xA);
            break;
        default:
            return 0;
    }
}

s32 baduo_entrypoint_3(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x58)))[1];
}

s32 baduo_entrypoint_4(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x58)))[2];
}

void baduo_entrypoint_5(s32 arg0) 
{
}
void baduo_entrypoint_6(u8 *param_0) {
    s32 local_0;

    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x58)))) + (1))) = 0;
    baduo_entrypoint_11(param_0, 0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x58)))) + (4))) = 0.0f;
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0x58))) + 8);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x58)))) + (0))) = 0;
    local_0 = func_800A3274(param_0);
    if ((local_0 == 0xA) || (local_0 == 0xB)) {
        if (func_800F8B88() == 2) {
            baduo_entrypoint_7(param_0, 3);
            return;
        }
        baduo_entrypoint_7(param_0, 1);
        return;
    }
    baduo_entrypoint_7(param_0, 1);
}

void baduo_entrypoint_7(param_0, param_1) u8 *param_0; int param_1;
{
  u8 temp_v0;
  *(*((u8 **) (((s8 *) param_0) + 0x58))) = param_1;
  ;
  switch (*(*((u8 **) (((s8 *) param_0) + 0x58))))
  {
    case 1:
      baduo_entrypoint_11(param_0, 0);
      func_8009ADF0(param_0, 2, 0);
      return;

    case 2:
      baduo_entrypoint_10(param_0, 0);
      baduo_entrypoint_11(param_0, 1);
      return;

    case 3:
      if (func_8008DAA8(param_0) != 0)
    {
      func_800A38F0(param_0, 1, 1);
    }
    else
    {
      func_800A38F0(param_0, 0, 1);
    }
      func_8009ADF0(param_0, 2, 1);
      return;

    case 4:
      _bashoes_entrypoint_6(param_0, 1);
      func_800F82D4(func_800F54E4(), 2);
      return;

  }

}

s32 baduo_entrypoint_8(s32 param_0) {
    return func_800EE7F8(*(s32 *)(param_0 + 0x58) + 0x8);
}

void baduo_entrypoint_9(s32 param_0, f32 param_1) {
    *(f32 *)(*(s32 *)(param_0 + 0x58) + 0x4) = param_1;
}

void baduo_entrypoint_10(arg, v) void *arg; s32 v;
{
    ((s8 *)(*(void **)((char *)arg + 0x58)))[1] = v;
}

void baduo_entrypoint_11(arg, v) void *arg; s32 v;
{
    ((s8 *)(*(void **)((char *)arg + 0x58)))[2] = v;
}

int baduo_entrypoint_12(Actor *param_0)
{
  if (func_8008E39C())
  {
    _bashoes_entrypoint_6(param_0, 2);
  }
  func_800F9A6C();
}

void baduo_entrypoint_13(PlayerState *param_0)
{
    s32 local_0;
    s32 pad;
    f32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    s32 local_4;
    local_0 = func_800F54E4();
    switch (**(u8 **)((u8 *)param_0 + 0x58)) {
    case 3:
        if (func_800A3274(param_0) == 0xA && func_8008D40C(param_0)) baduo_entrypoint_7(param_0, 4);
        return;
    case 4:
        if (func_800F5B0C(local_0) == 2) {
            local_4 = baduo_entrypoint_2(param_0);
            if (local_0 == param_0->unk184) func_800F8EBC(_plsu_entrypoint_1(0xB));
            else func_800F8EBC(param_0->unk184);
            if (local_0 == param_0->unk184) func_800F82D4(local_0, 0);
            else {
                func_800F82D4(local_0, 0);
                func_800F82D4(param_0->unk184, 0);
            }
            _bapackctrl_entrypoint_5(param_0, 1);
            func_800F911C(1);
            func_800F80D8(param_0->unk184);
            func_800D5034(func_800A3274(param_0), 1);
            func_800A3410(param_0, 1);
            func_800F8268(param_0->unk184, 0, 1);
            if (local_0 != param_0->unk184) {
                func_80800008_baduo(func_800F53D0(local_4), func_800F53D0(param_0->unk184));
            }
            local_1 = yaw_get(param_0);
            func_800F5A00(local_4, local_3);
            func_8009C128(param_0, local_2);
            func_800F759C(local_4);
            func_800A38F0(param_0, 1, 1);
            func_800A91A8(param_0->unk184);
            baduo_entrypoint_7(param_0, 1);
            if (mlAbsF(func_800F1F0C(local_2, local_3, local_1)) > 90.0f) bs_setState(param_0, 0x69);
            else bs_setState(param_0, 0x6A);
            func_80101180(0x158, 0x17, 0);
        }
        break;
    }
}

void baduo_entrypoint_14(PlayerState *param_0, s32 param_1)
{
    s32 local_0;
    PlayerState *local_1;
    local_0 = func_800F6224(*(s32 *)((u8 *)param_0 + 0x184));
    local_1 = func_800F53D0(local_0);
    func_800F452C(local_1, param_1);
    func_800A3410(local_1, 0x11);
    func_80092778(local_1);
    func_80800008_baduo(param_0, local_1);
    _bababykaz_entrypoint_8(local_1);
    bs_setState(local_1, 0x139);
    yaw_set(local_1, yaw_get(param_0));
    yaw_setIdeal(local_1, yaw_getIdeal(param_0));
    _bababykaz_entrypoint_10(local_1, *(s32 *)((u8 *)param_0 + 0x184));
    _bsfirstp_entrypoint_28(param_0, local_1);
    func_800A91A8(local_0);
    func_800A38F0(param_0, 0, 1);
}

void baduo_entrypoint_15(PlayerState *param_0, f32 *param_1)
{
    s32 local_0;
    PlayerState *local_1;
    s32 local_2;
    s32 local_4;
    Vec3f local_3;

    local_0 = func_800F6224(*(void **)((u8 *)param_0 + 0x184));
    local_1 = (PlayerState *)func_800F53D0(local_0);
    func_800F452C(local_1, param_1);
    func_800A3410(local_1, 0x11);
    func_80092778(local_1);
    _bababykaz_entrypoint_8(local_1);
    func_80800008_baduo(param_0, local_1);
    local_2 = func_800A4CA8(local_1);
    func_800F3BB0(param_0, local_3.f);
    if (func_800EEB40(param_1, local_3.f) > 1000000.0f) {
        local_4 = 0;
        do {
            func_80110588(local_2);
            local_4++;
        } while (local_4 != 60);
    }
    bs_setState(local_1, 0x136);
    func_800F8128(local_0);
    func_800A38F0(param_0, 0, 1);
    func_800F8EE4(*(void **)((u8 *)param_0 + 0x184));
    bs_setState(param_0, _badrone_entrypoint_29(param_0));
    _sudialog_entrypoint_0(0xE8, 0xC);
    func_80800C78_baduo(local_1, 0x11);
    func_80800CA8_baduo(param_0, local_1);
    func_800F86C4(*(void **)((u8 *)local_1 + 0x184), 0x11);
}

void baduo_entrypoint_16(PlayerState *param_0)
{
    s32 local_0;
    PlayerState *local_1;

    local_0 = func_800F6224(param_0->unk184);
    local_1 = func_800F53D0(local_0);
    yaw_setIdeal(param_0, yaw_get(param_0));
    yaw_setIdeal(local_1, yaw_get(param_0));
    yaw_applyIdeal(local_1);
    bs_setState(local_1, 0xBA);
    func_80800008_baduo(param_0, local_1);
    baduo_entrypoint_7(local_1, 2);
    baduo_entrypoint_7(param_0, 2);
    func_800F911C(2);
    func_800F9098(10, *(u8 **)((u8 *)param_0 + 0x58) + 8);
    func_800F90EC(*(f32 *)(*(u8 **)((u8 *)param_0 + 0x58) + 4));
    func_800D5034(1, 10);
    func_800D5034(1, 11);
    func_800F8EE4(local_0);
    func_800F8128(param_0->unk184);
    func_80101180(0x158, 0x16, 0);
}

void baduo_entrypoint_17(PlayerState *param_0, s32 param_1)
{
    s32 local_2;
    PlayerState *local_0;
    f32 local_1[3];

    func_8009C128(param_0, local_1);
    local_2 = func_800F6224(*(s32 *)((u8 *)param_0 + 0x184));
    local_0 = func_800F53D0(local_2);
    func_800F452C(local_0, param_1);
    bs_setState(local_0, 1);
    func_800F45B0(local_0, 2, local_1);
}

void baduo_entrypoint_18(PlayerState *param_0, s32 param_1)
{
    s32 local_0;
    PlayerState *local_1;

    local_0 = func_800F6224(*(s32 *)((u8 *)param_0 + 0x184));
    local_1 = func_800F53D0(local_0);
    func_800F452C(local_1, param_1);
    func_800A3410(local_1, 13);
    func_80092778(local_1);
    bs_setState(local_1, 0xE5);
    func_80800008_baduo(param_0, local_1);
    func_800A38F0(param_0, 0, 1);
    func_800F8128(local_0);
    func_800F8EE4(*(void **)((u8 *)param_0 + 0x184));
    func_800F45B0(param_0, 2, param_1);
    yaw_setIdeal(local_1, 0.0f);
    yaw_applyIdeal(local_1);
    func_80800C78_baduo(local_1, 13);
    func_80800CA8_baduo(param_0, local_1);
    func_8009DB04(param_0, 0x5A2, 0.9f, 0x6D60);
}

void baduo_entrypoint_19(u8 *param_0) {
    s32 local_0;

    local_0 = _plsu_entrypoint_1(0xD);
    func_800F457C(param_0, 0);
    func_800A38F0(param_0, 1, 1);
    func_800F8EBC((*(s32 *)((s8 *)(param_0) + (0x184))));
    func_80800008_baduo(func_800F53D0(local_0), param_0);
    func_800F8128((*(s32 *)((s8 *)(param_0) + (0x184))));
    func_80800CA8_baduo(func_800F53D0(local_0), param_0);
    func_800F759C(local_0);
    func_80800C78_baduo(param_0, 1);
    func_8009DB04(param_0, 0x5A4, 0.9f, 0x6D60);
}

void baduo_entrypoint_20(u8 *param_0, s32 param_1, f32 param_2) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_1 = func_800F6224((*(s32 *)((s8 *)(param_0) + (0x184))));
    local_0 = local_1;
    local_2 = func_800F53D0(local_1);
    func_800F452C(local_2, param_1);
    func_80800008_baduo(param_0, local_2);
    func_800A3410(local_2, 0xE);
    func_80092778(local_2);
    yaw_setIdeal(local_2, param_2);
    yaw_applyIdeal(local_2);
    _bsstatue_entrypoint_1(param_0);
    bs_setState(local_2, 0xF9);
    func_800F8128(local_0);
    func_800F8EE4((*(s32 *)((s8 *)(param_0) + (0x184))));
    func_800F45B0(param_0, 2, param_1);
    func_800A38F0(param_0, 0, 1);
    _sudialog_entrypoint_0(0x50, 0xE);
    func_80800C78_baduo(local_2, 0xE);
    func_80800CA8_baduo(param_0, local_2);
}

void baduo_entrypoint_21(PlayerState *param_0)
{
    s32 local_0;
    PlayerState *local_2;
    f32 local_1[3];
    func_800F911C(3);
    local_0 = func_800F6224(param_0->unk184);
    local_2 = func_800F53D0(local_0);
    func_8009C128(param_0, local_1);
    func_800F452C(local_2, local_1);
    func_800A3410(param_0, 10);
    func_800A3410(local_2, 11);
    func_80092778(local_2);
    yaw_setIdeal(param_0, yaw_get(param_0));
    yaw_setIdeal(local_2, yaw_get(param_0));
    yaw_applyIdeal(local_2);
    func_800F80D8(local_0);
    bs_setState(local_2, 0x153);
    func_800A91A8(local_0);
    func_80800008_baduo(param_0, local_2);
    func_800F8EE4(param_0->unk184);
    func_800A38F0(param_0, 0, 1);
    func_800D5234(1);
    func_800A16BC(1);
    func_800A1694();
    _bakaztorpedo_entrypoint_3(local_2);
}

s32 func_80800C78_baduo(param_0, param_1) s32 param_0; s32 param_1;{
    _surestart_entrypoint_0(param_1);
    func_800A1658(param_1);
}

int func_80800CA8_baduo(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 local_1;
  s32 local_0;
  local_0 = func_800A3274(param_0);
  local_1 = func_800A3274(param_1);
  func_800D5034(local_0, local_1);
}
