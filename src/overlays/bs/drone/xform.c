#include "common.h"
#include "overlays/ba/playerstate.h"

#define DXF (*(DroneXformData **)((u8 *)this + 0x18C))
extern void func_800BA3FC(s32, s32);
extern void *D_808011F0_bsdronexform;
typedef struct { u8 pad_0[0x14]; f32 local_0; } DroneTransformState;
typedef struct { u8 pad_0[0x18C]; DroneTransformState *local_0; } DroneTransformPlayer;
extern void func_800BA7C4(s32, f32, f32);
extern u8 D_8080121C_bsdronexform[];
extern u8 D_80801248_bsdronexform[];
extern u8 D_80801274_bsdronexform[];
extern u8 D_808012B8_bsdronexform[];
extern u8 D_808012D0_bsdronexform[];
extern u8 D_808012F0_bsdronexform[];
extern u8 D_80801334_bsdronexform[];
extern u8 D_8080134C_bsdronexform[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
typedef struct { u8 pad_0[0x20]; f32 local_0; f32 local_1; f32 local_2; } DroneScaleData;
typedef struct { u8 pad_0[0x18C]; DroneScaleData *local_0; } DroneScalePlayer;
extern void *func_800F53D0(s32);
extern f32 func_800F1074(f32, f32);
extern void _bsdronexform_entrypoint_0(void);
extern void func_8008C9D8();
extern f32 func_800D8FF8();
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern f32 _batimer_get(s32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F0F9C(f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800F13C4(f32, f32);
extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
extern f32 func_80013970(f32);
extern f32 func_800138D0(f32);
extern f32 func_8009C150(PlayerState *);
extern void _batimer_set(PlayerState *, s32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 func_800CA3F4(s32, f32 *, f32);
extern s32 func_800E1610(s32, f32, f32, f32 *);
typedef struct { u8 pad0[0x1C]; u8 unk1C; u8 pad1D[0x2C - 0x1D]; f32 unk2C; u8 pad30[2]; u8 state; } DroneXformData;
extern s32 _batimer_decrement(PlayerState *, s32);
extern void func_8009C118(PlayerState *, f32);
extern void func_800C59F0(s32, s32, s32);
extern s32 _badata_entrypoint_34(PlayerState *);
extern void bs_setState(PlayerState *, s32);
void func_80800304_bsdronexform();
void func_80800758_bsdronexform();

void func_80800000_bsdronexform(s32 param_0, s32 param_1, s32 param_2)
{
    func_800BABB8(param_1 | 0, 0, 0, 1.0f, &D_808011F0_bsdronexform);
    func_800BA3FC(param_1, param_2);
}

void func_80800050_bsdronexform(PlayerState *param_0, s32 param_1, f32 param_2, f32 param_3)
{
    s16 local_0;
    s16 local_1;
    local_0 = param_2 * 30.0f;
    local_1 = param_3 * 30.0f;
    func_800BA930(param_1, local_0, 10, local_1, local_0, 10, local_1);
    func_800BA7C4(param_1, ((DroneTransformPlayer *)param_0)->local_0->local_0,
        ((DroneTransformPlayer *)param_0)->local_0->local_0);
}

void func_808000E4_bsdronexform(void *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5[3];

    func_8008FE68(&local_5);
    local_4 = *(f32 *)(*(u8 **)((u8 *)param_0 + 0x18C) + 8);
    local_1 = func_800F0F9C(local_4, 0.38f);
    local_3 = func_800137F4(360.0f * local_1);
    local_2 = func_80013788();
    local_5[0] += local_3 * *(f32 *)(*(u8 **)((u8 *)param_0 + 0x18C) + 0x18);
    local_5[1] += func_800F1214(func_800F0F9C(local_4, 1.14f), 0.0f, 130.0f);
    local_5[2] += local_2 * *(f32 *)(*(u8 **)((u8 *)param_0 + 0x18C) + 0x18);
    func_80800050_bsdronexform(param_0, *(s32 *)(*(u8 **)((u8 *)param_0 + 0x18C) + 4), local_3, local_2);
    func_800BA75C(*(s32 *)(*(u8 **)((u8 *)param_0 + 0x18C) + 4), &local_5);
    func_800BA22C(*(s32 *)(*(u8 **)((u8 *)param_0 + 0x18C) + 4), 1);
    func_8008FE68(&local_5);
    local_0 = (1.0f - func_800F13C4(local_1 + 0.5f, 1.0f)) * 360.0f;
    local_5[0] -= func_80013970(local_0) * *(f32 *)(*(u8 **)((u8 *)param_0 + 0x18C) + 0x18);
    local_5[1] += func_800F1214(func_800F0F9C(local_4, 1.14f), 130.0f, 0.0f);
    local_5[2] -= func_800138D0(local_0) * *(f32 *)(*(u8 **)((u8 *)param_0 + 0x18C) + 0x18);
    func_80800050_bsdronexform(param_0, **(s32 **)((u8 *)param_0 + 0x18C), local_3, local_2);
    func_800BA75C(**(s32 **)((u8 *)param_0 + 0x18C), &local_5);
    func_800BA22C(**(s32 **)((u8 *)param_0 + 0x18C), 1);
}

void func_808002CC_bsdronexform(Actor *param_0)
{
  func_800B5450(*(*(void ***)(((char *)param_0) + 0x18c) + 1));
  func_800B5450(*(*(void ***)(((char *)param_0) + 0x18c)));
}

void func_80800304_bsdronexform(param_0) u8 *param_0; {
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x18C)))) + (0))) = func_800B53A4(0x32);
    func_80800000_bsdronexform(param_0, (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x18C)))) + (0))), 0x6F7);
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x18C)))) + (4))) = func_800B53A4(0x32);
    func_80800000_bsdronexform(param_0, (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x18C)))) + (4))), 0x6F8);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x18C)))) + (0x10))) = 0.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x18C)))) + (8))) = 0.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x18C)))) + (0xC))) = 1.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x18C)))) + (0x18))) = 55.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x18C)))) + (0x14))) = 0.35f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x18C)))) + (0x1C))) = 0;
}

void func_808003BC_bsdronexform(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 0x18C) + 0xC) = param_1;
}

int func_808003CC_bsdronexform(s32 param_0, f32 param_1)
{
  *((f32 *) ((*((s32 *) (param_0 + 396))) + 0x18)) = param_1;
}

func_808003DC_bsdronexform(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 396) + 20) = param_1;
}

void func_808003EC_bsdronexform(void *param_0, f32 *param_1)
{
    s32 local_0;

    func_800BABB8(0, param_1, 0, 1.0f, D_8080121C_bsdronexform);
    func_800BABB8(0, param_1, 0, 1.0f, D_80801248_bsdronexform);
    local_0 = func_800BABB8(0, param_1, 0, 1.0f, D_80801274_bsdronexform);
    local_0 = func_800BABB8(local_0, param_1, 0, 1.0f, D_808012B8_bsdronexform);
    func_800BABB8(local_0, param_1, 0, 1.0f, D_808012D0_bsdronexform);
    local_0 = func_800BABB8(0, param_1, 0, 1.0f, D_808012F0_bsdronexform);
    local_0 = func_800BABB8(local_0, param_1, 0, 1.0f, D_80801334_bsdronexform);
    func_800BABB8(local_0, param_1, 0, 1.0f, D_8080134C_bsdronexform);
}

void func_8080051C_bsdronexform(void *param_0)
{
    (*(f32 **)((u8 *)param_0 + 0x18C))[4] -= func_800D8FF8();
    if ((*(f32 **)((u8 *)param_0 + 0x18C))[4] < 0.0f) {
        do {
            func_808000E4_bsdronexform(param_0);
            (*(f32 **)((u8 *)param_0 + 0x18C))[2] +=
                0.017f * (*(f32 **)((u8 *)param_0 + 0x18C))[3];
            (*(f32 **)((u8 *)param_0 + 0x18C))[4] += 0.017f;
        } while ((*(f32 **)((u8 *)param_0 + 0x18C))[4] < 0.0f);
    }
}

void bsdronexform_entrypoint_0(s32 param_0, s32 param_1)
{
    f32 local_0[3];
    f32 *local_1;
    s32 local_2;
    DroneScalePlayer *local_3;

    local_3 = func_800F53D0(param_1);
    local_2 = 0;
    local_1 = local_0;
    do {
        *local_1 = func_800F1074(local_3->local_0->local_0 + (local_2 / 3.0f) * 0.5f, 0.5f) *
                   (local_3->local_0->local_1 * local_3->local_0->local_2) + local_3->local_0->local_1;
        local_2++;
        local_1++;
    } while (local_2 != 3);
    func_800DFF64(param_0, 3, local_0);
}

void func_8080069C_bsdronexform(s32 arg0)
{
    func_8008C9D8(arg0,0);
}

void func_808006BC_bsdronexform(u8 *param_0) {
    *(f32 *)(*(u8 **)(param_0 + 0x18C) + 0x20) = 0.0f;
    *(f32 *)(*(u8 **)(param_0 + 0x18C) + 0x24) = 1.0f;
    *(f32 *)(*(u8 **)(param_0 + 0x18C) + 0x28) = 0.0f;
    func_8008C9D8(param_0, _bsdronexform_entrypoint_0);
}

func_80800704_bsdronexform(s32 param_0, f32 param_1){
    *(f32*)(*(s32*)(param_0 + 0x18C) + 0x28) = param_1;
}

void func_80800714_bsdronexform(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 0x18C) + 0x24) = param_1;
}

void func_80800724_bsdronexform(u8 *param_0) {
    *(f32 *)(*(u8 **)(param_0 + 0x18C) + 0x20) += func_800D8FF8(param_0);
}

void func_80800758_bsdronexform(param_0, param_1) PlayerState *param_0; s32 param_1;
{
  s32 local_0;
  f32 local_1;
  f32 local_3[3];
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x18C)))) + 0x32)) = param_1;
  switch (param_1)
  {
    case 1:
      *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x18C)))) + 0x1C)) = 1;
      *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x18C)))) + 0x2C)) = func_8009C150(param_0);
      func_808003BC_bsdronexform(param_0, 0.28f);
      func_808003CC_bsdronexform(param_0, 180.0f);
      func_808003DC_bsdronexform(param_0, 0.04f);
      func_80800704_bsdronexform(param_0, 0.05f);
      baphysics_set_type(param_0, 7);
      _batimer_set(param_0, 0, 2.8f);
      func_8009DF18(param_0, 0x5D2, 1.0f, 0x4E20);
      return;

    case 2:
      _batimer_set(param_0, 0, 0.5f);
      baphysics_set_type(param_0, 0xB);
      return;

    case 3:
      _batimer_set(param_0, 0, 0.05f);
      return;

    case 4:
      _batimer_set(param_0, 0, 0.8f);
      return;

    case 5:
      func_8009C128(param_0, local_3);
      local_3[1] += 30.0f;
      func_800CA3F4(func_800A4C48(param_0), local_3, 80.0f);
      func_808003EC_bsdronexform(param_0, local_3);
      _batimer_set(param_0, 0, 0.1f);
      return;

    case 6:
      func_8009C128(param_0, local_3);
      func_800E1610(2, 80.0f, 0.85f, local_3);
      func_8009DE38(param_0, 0x490, 1.0f);
      func_800D5034(func_800A3274(param_0), func_800A33F8(param_0));
      func_800A3410(param_0, func_800A33F8(param_0));
      func_80092778(param_0);
      _badata_entrypoint_5(param_0, &local_0, &local_1);
      baanim_playForDuration_loopSmooth(param_0, local_0, local_1);
      _batimer_set(param_0, 0, 0.1f);
      return;

    case 7:
      _batimer_set(param_0, 0, 0.8f);
      return;

    case 8:
      _batimer_set(param_0, 0, 1.0f);
      return;

    case 9:
      *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x18C)))) + 0x1C)) = 0;
      _batimer_set(param_0, 0, 0.7f);
      baphysics_set_type(param_0, 7);
      return;

    default:
      return;

  }

}

void bsdronexform_entrypoint_1(s32 param_0) {
    func_800961AC(param_0, 1);
    func_800C59F0(0xFF, 0xFF, 0xFF);
    func_808002CC_bsdronexform(param_0);
    func_8080069C_bsdronexform(param_0);
    func_8009CEE8(param_0);
    baflag_clear(param_0, 0x1B);
    _badronemem_entrypoint_1(param_0);
}

void bsdronexform_entrypoint_2(PlayerState *param_0)
{
    f32 local_0;
    s32 local_1;

    _badronemem_entrypoint_0(param_0, 0x34);
    _badata_entrypoint_2(param_0, &local_1, &local_0);
    baanim_playForDuration_loopSmooth(param_0, local_1, local_0);
    func_8009FFD8(param_0, 1, 1, 3, 7);
    func_8009BA9C(param_0, 0);
    func_8009B94C(param_0, 0);
    func_8009BF5C(param_0, 0.0f);
    baroll_setIdeal(param_0, 0.0f);
    func_800961AC(param_0, 6);
    func_80800304_bsdronexform(param_0);
    func_808006BC_bsdronexform(param_0);
    (*(u8 **)((u8 *)param_0 + 0x18C))[0x31] = func_800A3274(param_0);
    (*(u8 **)((u8 *)param_0 + 0x18C))[0x30] = func_800A33F8(param_0);
    baflag_set(param_0, 0x1B);
    (*(u8 **)((u8 *)param_0 + 0x18C))[0x32] = 0;
    func_80800758_bsdronexform(param_0, 1);
}

f32 func_80800B5C_bsdronexform(s32 param_0, s32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    return func_800F10B4(_batimer_get(param_0, param_1), param_2, 0.0f, param_3, param_4);
}

void bsdronexform_entrypoint_3(PlayerState *this)
{
    int sp24;

    if (DXF->unk1C)
        func_8080051C_bsdronexform(this);

    func_80800724_bsdronexform(this);
    switch (DXF->state) {
        case 1:
            sp24 = _batimer_decrement(this, 0);
            func_8009C118(this, DXF->unk2C + func_80800B5C_bsdronexform(this, 0, 2.8f, 0.0f, 90.0f));
            func_808003BC_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 2.8f, 0.28f, 1.0f));
            func_808003CC_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 2.8f, 180.0f, 55.0f));
            func_808003DC_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 2.8f, 0.04f, 0.35f));
            func_80800714_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 2.8f, 1.0f, 0.8f));
            func_80800704_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 2.8f, 0.05f, 0.4f));
            func_800C59F0(
                (s32)func_80800B5C_bsdronexform(this, 0, 2.8f, 255.0f, 200.0f),
                (s32)func_80800B5C_bsdronexform(this, 0, 2.8f, 255.0f, 80.0f),
                (s32)func_80800B5C_bsdronexform(this, 0, 2.8f, 255.0f, 80.0f)
            );

            if (sp24)
                func_80800758_bsdronexform(this, 2);

            break;

        case 2:
            sp24 = _batimer_decrement(this, 0);
            func_80800704_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 0.5f, 0.4f, 0.6f));
            if (sp24)
                func_80800758_bsdronexform(this, 3);
            break;

        case 3:
            sp24 = _batimer_decrement(this, 0);
            func_80800714_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 0.05f, 0.8f, 1.2f));
            if (sp24)
                func_80800758_bsdronexform(this, 4);
            break;

        case 4:
            sp24 = _batimer_decrement(this, 0);
            func_80800714_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 0.8f, 1.2f, 0.09f));
            if (sp24)
                func_80800758_bsdronexform(this, 5);
            break;

        case 5:
            sp24 = _batimer_decrement(this, 0);
            if (sp24)
                func_80800758_bsdronexform(this, 6);
            break;

        case 6:
            sp24 = _batimer_decrement(this, 0);
            if (sp24)
                func_80800758_bsdronexform(this, 7);
            break;

        case 7:
            sp24 = _batimer_decrement(this, 0);
            func_80800714_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 0.8f, 0.09f, 1.0f));
            if (sp24)
                func_80800758_bsdronexform(this, 8);
            break;

        case 8:
            func_808003DC_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 1.0f, 0.35f, 0.03f));
            func_80800704_bsdronexform(this, func_80800B5C_bsdronexform(this, 0, 1.0f, 0.6f, 0.05f));
            func_800C59F0(
                (s32)func_80800B5C_bsdronexform(this, 0, 1.0f, 200.0f, 255.0f),
                (s32)func_80800B5C_bsdronexform(this, 0, 1.0f, 80.0f, 255.0f),
                (s32)func_80800B5C_bsdronexform(this, 0, 1.0f, 80.0f, 255.0f)
            );
            if (_batimer_decrement(this, 0))
                func_80800758_bsdronexform(this, 9);
            break;

        case 9:
            sp24 = _batimer_decrement(this, 0);
            func_8009C118(this, DXF->unk2C + func_80800B5C_bsdronexform(this, 0, 0.7f, 90.0f, 0.0f));
            if (sp24)
                bs_setState(this, _badata_entrypoint_34(this));
            break;
    }
}
