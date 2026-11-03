#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_8010114C();
typedef struct {
    u8 pad_0[0x40];
    f32 struggle;
    f32 base_duration;
} BubbledAnimationState;
extern void _badata_entrypoint_0(PlayerState *, s32 *, f32 *);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(s32, s32, s32, s32, s32);
typedef struct {
    u8 pad_0[0x40];
    f32 struggle;
} BubbledDroneAir;
typedef struct {
    u8 pad_0[0x54];
    BubbledDroneAir *block;
} BubbledDronePlayer;
extern f32 func_800F13F0(f32, f32);
typedef struct {
    u8 pad_0[0x54];
    BubbledAnimationState *block;
} DroneBubblePlayer1482;
extern f32 func_800D8FF8(void);
extern s32 func_800F1574(f32 *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern void anctrl_setDuration(void *, f32);

// Notifies the capturing actor (message 0x2C) and clears its handle.
void func_80800000_bsdronebubbled(player) u8 *player;
{
    func_8010114C(*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) player + 0x54))) + 0x48), 0x2C,
                  *(s32 *) ((s8 *) player + 0x184), player);
    *(s32 *) ((s8 *) ((*(u8 **) ((s8 *) player + 0x54))) + 0x48) = 0;
}

void bsdronebubbled_entrypoint_0(u8 *player)
{
    if (*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 0x48) != 0) {
        func_80800000_bsdronebubbled();
    }
}

void bsdronebubbled_entrypoint_1(PlayerState *player)
{
    f32 duration;
    s32 anim_id;
    _badata_entrypoint_0(player, &anim_id, &duration);
    baanim_playForDuration_loopSmooth(player, anim_id, duration);
    (*(BubbledAnimationState **) ((u8 *) player + 0x54))->base_duration = duration;
    (*(BubbledAnimationState **) ((u8 *) player + 0x54))->struggle = 0.0f;
    func_8009FFD8(player, 1, 1, 3, 7);
    func_8009D9D4(player);
}

// Interrupts: 0x6F and 0x70 release the player, 0x7B (struggle) raises the struggle value.
void bsdronebubbled_entrypoint_2(PlayerState *player)
{
    switch (func_8009E6EC(player)) {
        case 0x21:
            func_80099B94(player);
            break;
        case 0x6F:
            func_8009E830(player, 1);
            break;
        case 0x70:
            bs_setState(player, _badata_entrypoint_34(player));
            break;
        case 0x7B:
            ((BubbledDronePlayer *) player)->block->struggle =
                func_800F13F0(1.0f, ((BubbledDronePlayer *) player)->block->struggle + 0.2f);
            break;
        default:
            func_80099B94(player);
    }
}

// The struggle value decays over time and speeds up the anim.
// Matching: the line breaks in this function are needed for the match.
void bsdronebubbled_entrypoint_3(PlayerState *player)
{
    f32 base_duration;
    f32 duration;
    void *anim_ctrl;

    base_duration = ((DroneBubblePlayer1482 *)player)->block->base_duration;
    func_800F1574(&((DroneBubblePlayer1482 *)player)->block->struggle, func_800D8FF8() * 0.8333333135f); anim_ctrl = baanim_getAnimCtrlPtr(player); duration = func_800F1214(((DroneBubblePlayer1482 *)player)->block->struggle, base_duration, base_duration * 0.3333333433f);
    anctrl_setDuration(anim_ctrl, duration);
}

void bsdronebubbled_entrypoint_4(s32 player)
{
}

// Passive bubble float.
void bsdronebubbled_entrypoint_5(s32 player)
{
    f32 duration;
    s32 anim_id;
    _badata_entrypoint_0(player, &anim_id, &duration);
    duration *= 2.0f;
    baanim_playForDuration_loopSmooth(player, anim_id, duration);
    func_8009FFD8(player, 1, 1, 3, 7);
}

void bsdronebubbled_entrypoint_6()
{
    func_80099B94();
}

bsdronebubbled_entrypoint_7(unk_0)
{
}
