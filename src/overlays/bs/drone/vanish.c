#include "common.h"
#include "overlays/ba/playerstate.h"

typedef struct { u8 pad_0[0x18]; u8 local_0; } DroneVanishState;
extern void _batimer_set(PlayerState *, s32, f32);
typedef struct { s32 local_0; s32 local_1; } DroneVanishEmitters;
typedef struct { u8 pad_0[0x188]; DroneVanishEmitters *local_0; } DroneVanishEffectsPlayer;
extern s32 D_8080056C_bsdronevanish[];
extern s32 D_80800560_bsdronevanish[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BA3FC(void *, f32 *);
extern void *D_80800578_bsdronevanish;
extern f32 _batimer_get(PlayerState *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80092778();
extern void func_800961AC();
extern f32 func_800D8FF8(void);
void func_808002A4_bsdronevanish();

void func_80800000_bsdronevanish(PlayerState *param_0, s32 param_1)
{
    switch (param_1) {
    case 1:
        _batimer_set(param_0, 0, 0.3f);
        break;
    case 2:
        func_800FC618(0x1C, -1);
        func_800FCA90(0x1C);
        _batimer_set(param_0, 0, 0.4f);
        break;
    case 3:
        func_80093370(param_0, 0);
        func_800FCAE0(0x1C, 0, 2000);
        _batimer_set(param_0, 0, 2.0f);
        break;
    }
    ((DroneVanishState *)param_0->kazfly)->local_0 = param_1;
}

void func_808000CC_bsdronevanish(void *param_0)
{
    f32 local_0[3];

    func_800F3BB0(param_0, local_0);
    func_800BABB8(((DroneVanishEffectsPlayer *)param_0)->local_0->local_1, local_0, NULL, 1.0f, D_80800560_bsdronevanish);
    func_800BABB8(((DroneVanishEffectsPlayer *)param_0)->local_0->local_0, local_0, NULL, 1.0f, D_80800560_bsdronevanish);
    local_0[1] += 130.0f;
    func_800BABB8(((DroneVanishEffectsPlayer *)param_0)->local_0->local_1, local_0, NULL, 1.0f, D_8080056C_bsdronevanish);
    func_800BABB8(((DroneVanishEffectsPlayer *)param_0)->local_0->local_0, local_0, NULL, 1.0f, D_8080056C_bsdronevanish);
}

void func_8080019C_bsdronevanish(Actor *param_0, f32 param_1[3])
{
  func_800BABB8(param_0, 0, 0, 1.0f, &D_80800578_bsdronevanish);
  func_800BA3FC(param_0, param_1);
}

void func_808001E4_bsdronevanish(param_0) Actor *param_0;
{
    func_800B5450((*(s32 *)((s8 *)((*(s32 **)((s8 *)(param_0) + (0x188)))) + (4))));
    func_800B5450(*(*(s32 **)((s8 *)(param_0) + (0x188))));
}

void func_8080021C_bsdronevanish(u8 *param_0) {
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x188)))) + (0x10))) = 0.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x188)))) + (8))) = 0.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x188)))) + (0xC))) = 1.0f;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x188)))) + (0))) = func_800B53A4(0x3C);
    func_8080019C_bsdronevanish((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x188)))) + (0))), 0x9E5);
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x188)))) + (4))) = func_800B53A4(0x3C);
    func_8080019C_bsdronevanish((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x188)))) + (4))), 0x9E2);
}

void func_808002A4_bsdronevanish(param_0) void *param_0;
{
    (*(f32 **)((u8 *)param_0 + 0x188))[4] -= func_800D8FF8();
    if ((*(f32 **)((u8 *)param_0 + 0x188))[4] < 0.0f) {
        do {
            func_808000CC_bsdronevanish(param_0);
            (*(f32 **)((u8 *)param_0 + 0x188))[2] +=
                0.02f * (*(f32 **)((u8 *)param_0 + 0x188))[3];
            (*(f32 **)((u8 *)param_0 + 0x188))[4] += 0.02f;
        } while ((*(f32 **)((u8 *)param_0 + 0x188))[4] < 0.0f);
    }
}

void bsdronevanish_entrypoint_0(u8 *param_0) {
    s32 local_0;
    s32 local_1;

    _bastatemem_entrypoint_0(param_0, 0x1C);
    _badata_entrypoint_3(param_0, &local_1, &local_0);
    baanim_playForDuration_loopSmooth(param_0, local_1, local_0);
    func_8009FFD8(param_0, 1, 1, 3, 7);
    func_800961AC(param_0, 6);
    func_8080021C_bsdronevanish(param_0);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x188)))) + (0x18))) = 0;
    func_80800000_bsdronevanish(param_0, 1);
}

void bsdronevanish_entrypoint_1(PlayerState *param_0)
{
    s32 local_0;
    s32 local_1;
    local_0 = 0;
    switch (*((u8 *)param_0->kazfly + 0x18)) {
    case 1:
        func_808002A4_bsdronevanish(param_0);
        if (_batimer_decrement(param_0, 0)) func_80800000_bsdronevanish(param_0, 2);
        break;
    case 2:
        func_808002A4_bsdronevanish(param_0);
        local_1 = _batimer_decrement(param_0, 0);
        func_80092EBC(param_0, (s32)func_800F10B4(_batimer_get(param_0, 0), 0.0f, 0.4f, 0.0f, 255.0f));
        if (local_1) func_80800000_bsdronevanish(param_0, 3);
        break;
    case 3:
        if (_batimer_decrement(param_0, 0)) local_0 = _badata_entrypoint_34(param_0);
        break;
    }
    bs_setState(param_0, local_0);
}

s32 bsdronevanish_entrypoint_2(Actor *this){
    func_808001E4_bsdronevanish();
    func_800961AC(this, 1);
    func_80092778(this);
    _bastatemem_entrypoint_1(this);
}
