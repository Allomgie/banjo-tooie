#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"

extern void func_8010114C();
typedef struct { u8 pad_0[0x40]; f32 local_0; f32 local_1; } BubbledAnimationState;
extern void _badata_entrypoint_0(PlayerState *, s32 *, f32 *);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(s32, s32, s32, s32, s32);
typedef struct { u8 pad_0[0x40]; f32 local_0; } BubbledDroneAir;
typedef struct { u8 pad_0[0x54]; BubbledDroneAir *local_0; } BubbledDronePlayer;
extern f32 func_800F13F0(f32, f32);
typedef struct { u8 pad_0[0x54]; BubbledAnimationState *local_0; } DroneBubblePlayer1482;
extern f32 func_800D8FF8(void);
extern s32 func_800F1574(f32 *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern void anctrl_setDuration(void *, f32);

void func_80800000_bsdronebubbled(param_0) u8 *param_0; {
    func_8010114C(*(s32 *)((s8 *)((*(u8 **)((s8 *)param_0 + 0x54))) + 0x48), 0x2C, *(s32 *)((s8 *)param_0 + 0x184), param_0);
    *(s32 *)((s8 *)((*(u8 **)((s8 *)param_0 + 0x54))) + 0x48) = 0;
}

void bsdronebubbled_entrypoint_0(u8 *param_0) {
    if ((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (0x48))) != 0) {
        func_80800000_bsdronebubbled();
    }
}

void bsdronebubbled_entrypoint_1(PlayerState *param_0)
{
    f32 local_1;
    s32 local_0;
    _badata_entrypoint_0(param_0, &local_0, &local_1);
    baanim_playForDuration_loopSmooth(param_0, local_0, local_1);
    (*(BubbledAnimationState **)((u8 *)param_0 + 0x54))->local_1 = local_1;
    (*(BubbledAnimationState **)((u8 *)param_0 + 0x54))->local_0 = 0.0f;
    func_8009FFD8(param_0, 1, 1, 3, 7);
    func_8009D9D4(param_0);
}

void bsdronebubbled_entrypoint_2(PlayerState *param_0)
{
    switch (func_8009E6EC(param_0)) {
    case 0x21:
        func_80099B94(param_0);
        break;
    case 0x6F:
        func_8009E830(param_0, 1);
        break;
    case 0x70:
        bs_setState(param_0, _badata_entrypoint_34(param_0));
        break;
    case 0x7B:
        ((BubbledDronePlayer *)param_0)->local_0->local_0 = func_800F13F0(1.0f, ((BubbledDronePlayer *)param_0)->local_0->local_0 + 0.2f);
        break;
    default:
        func_80099B94(param_0);
        break;
    }
}

void bsdronebubbled_entrypoint_3(PlayerState *param_0)
{
    f32 local_0;
    f32 local_2;
    void *local_1;

    local_0 = ((DroneBubblePlayer1482 *)param_0)->local_0->local_1;
    func_800F1574(&((DroneBubblePlayer1482 *)param_0)->local_0->local_0, func_800D8FF8() * 0.8333333135f); local_1 = baanim_getAnimCtrlPtr(param_0); local_2 = func_800F1214(((DroneBubblePlayer1482 *)param_0)->local_0->local_0, local_0, local_0 * 0.3333333433f);
    anctrl_setDuration(local_1, local_2);
}

void bsdronebubbled_entrypoint_4(s32 arg0) 
{
}
void bsdronebubbled_entrypoint_5(s32 param_0) {
    f32 local_1;
    s32 local_0;
    _badata_entrypoint_0(param_0, &local_0, &local_1);
    local_1 *= 2.0f;
    baanim_playForDuration_loopSmooth(param_0, local_0, local_1);
    func_8009FFD8(param_0, 1, 1, 3, 7);
}

void bsdronebubbled_entrypoint_6()
{
    func_80099B94();
}

bsdronebubbled_entrypoint_7(param_0) {
    return;
}
