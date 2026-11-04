// Most likely the split-up pad states: Banjo's split animation, Kazooie jumping out and walking
// to her pad, a short wait that hands over control, and two recoil states for bumping each other.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 D_80800700_bssplitup[];
extern void _baduo_entrypoint_7(void *param_0, int param_1);
extern void func_800F8EE4(int param_0);
extern s32 D_80800710_bssplitup[];
extern s32 _batimer_decrement(s32, s32);
extern void _baduo_entrypoint_16(s32);
extern s32 D_80800720_bssplitup[];
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern f32 yaw_get(PlayerState *);
extern f32 func_800136E4(f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern s32 baanim_isStopped();
extern void bs_setState(s32, s32);
extern s32 D_80800730_bssplitup[];
extern s32 D_80800740_bssplitup[];
extern f32 func_800EEB40(f32 *, f32 *);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void _subaddiefind_entrypoint_5(s32, Actor **, s32, f32 *, f32, f32 (*)(f32 *, f32 *));
extern f32 baanim_getTimer(PlayerState *);
extern void _bamovegoto_entrypoint_7(PlayerState *, f32);

// Banjo split: switch control to Banjo and close the backpack.
void bssplitup_entrypoint_0(s32 player)
{
    func_800A3410(player, 0xA);
    _bapackctrl_entrypoint_5(player, 3);
    baanim_playForDuration_onceSmooth(player, 0xA2, 2.2f);
    func_8009FFD8(player, 1, 1, 3, 2);
    func_8009B94C(player, 0);
    func_8009BA9C(player, 0);
}

void bssplitup_entrypoint_1(u8 *player)
{
    s32 next_state;

    next_state = 0;
    if (baanim_isStopped() != 0) {
        next_state = 1;
        if (func_800F54E4() != *(s32 *) ((s8 *) player + 0x184)) {
            func_800F457C(player, 2);
        }
    }
    bs_setState(player, next_state);
}

// Exit: show dialog 0x4F5 unless leaving to state 0x5A.
int bssplitup_entrypoint_2(Actor *player)
{
    _baduo_entrypoint_7(player, 3);
    if (bs_getNextState(player) != 0x5A) {
        _sudialog_entrypoint_0(0x4F5, 0xc);
    }
}

int bssplitup_entrypoint_3(s32 index)
{
    return D_80800700_bssplitup[index];
}

// Kazooie split sequence: jump out, walk to her pad, record her parked position.
void func_8080012C_bssplitup(player, phase) PlayerState *player;
s32 phase;
{
    f32 pos[4];
    Actor *pad;

    *(s32 *) ((u8 *) player + 0x15C) = phase;
    switch (phase) {
        case 1:
            baanim_playForDuration_onceSmooth(player, 0xA3, 2.2f);
            func_8009FFD8(player, 1, 1, 3, 2);
            func_8009B94C(player, 0);
            func_8009BA9C(player, 0);
            func_8009DF18(player, 0x4592, 1.0f, 0x6D60);
            break;
        case 2:
            func_8009C128(player, &pos[1]);
            _subaddiefind_entrypoint_5(0x156, &pad, 2, &pos[1], 800.0f, func_800EEB40);
            func_800EE7F8(&pos[1], pad->position);
            _bamovegoto_entrypoint_0(player);
            _bamovegoto_entrypoint_12(player, &pos[1]);
            _bamovegoto_entrypoint_7(player, (0.51f - baanim_getTimer(player)) * 2.2f);
            _bamovegoto_entrypoint_13(player);
            func_800F9098(0xB, &pos[1]);
            break;
        case 3:
            baphysics_set_type(player, 2);
    }
}

// Kazooie jumps out as the controlled character.
void bssplitup_entrypoint_4(s32 player)
{
    s32 actor;
    actor = player | 0;
    func_800A3410(actor, 11);
    func_800A38F0(actor, 0, 0);
    func_80092778(actor);
    bastick_func_8009F258(actor);
    *(s32 *) ((char *) player + 0x15C) = 0;

    func_8080012C_bssplitup(actor, 1);
}

void bssplitup_entrypoint_5(u8 *player)
{
    s32 next_state;
    s32 phase;

    next_state = 0;
    phase = *(s32 *) ((s8 *) player + 0x15C);
    switch (phase) {
        case 3:
            break;
        case 1:
            if (baanim_isAt(player, 0x3D4CCCCD) != 0) {
                func_8080012C_bssplitup(player, 2);
            }
            break;
        case 2:
            if (baanim_isAt(player, 0x3F028F5C) != 0) {
                func_8080012C_bssplitup(player, 3);
            }
    }
    if (baanim_isStopped(player) != 0) {
        next_state = 0xBB;
        if (func_800F54E4() != *(s32 *) ((s8 *) player + 0x184)) {
            func_800F457C(player, 2);
        }
    }
    bs_setState(player, next_state);
}

void bssplitup_entrypoint_6(Actor *player)
{
    _baduo_entrypoint_7(player, 3);
    func_800F8EE4(*(int *) ((char *) player + 0x184));
}

int bssplitup_entrypoint_7(s32 index)
{
    return D_80800710_bssplitup[index];
}

// Short wait that hands control over.
void bssplitup_entrypoint_8(Actor *player)
{
    baanim_playForDuration_loopSmooth(player, 0x6F, 0x40B00000);
    func_8009FFD8(player, 1, 1, 3, 2);
    func_8009B94C(player, 0);
    func_8009BA9C(player, 0);
    _batimer_set(player, 0, 0x3DCCCCCD);
}

void bssplitup_entrypoint_9(s32 player)
{
    s32 next_state = 0;
    if (_batimer_decrement(player, 0)) {
        _baduo_entrypoint_16(player);
        next_state = 0xB9;
    }
    bs_setState(player, next_state);
}

void bssplitup_entrypoint_10(s32 player)
{
}

int bssplitup_entrypoint_11(s32 index)
{
    return D_80800720_bssplitup[index];
}

// Recoil backwards (push of 800).
void bssplitup_entrypoint_12(PlayerState *player)
{
    baanim_playForDuration_once(player, 0x296, 0.8f);
    func_8009FFD8(player, 1, 1, 3, 2);
    func_8009B94C(player, 0);
    baphysics_set_horizontal_velocity(player, func_800136E4(yaw_get(player) + 180.0f), 800.0f);
    func_800A0CF4(player, 1);
    func_8009DF18(player, 0x3EA, 1.0f, 0x6D60);
}

void bssplitup_entrypoint_13(s32 player)
{
    s32 next_state = 0;
    if (baanim_isStopped(player) != 0) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

void bssplitup_entrypoint_14(s32 player)
{
    func_800A0CF4(player, 0);
}

int bssplitup_entrypoint_15(s32 index)
{
    return D_80800730_bssplitup[index];
}

// Recoil forwards (push of 800).
void bssplitup_entrypoint_16(PlayerState *player)
{
    baanim_playForDuration_once(player, 0x292, 0.8f);
    func_8009FFD8(player, 1, 1, 3, 2);
    func_8009B94C(player, 0);
    baphysics_set_horizontal_velocity(player, yaw_get(player), 800.0f);
    func_800A0CF4(player, 1);
    func_8009DF18(player, 0x3EA, 1.0f, 0x6D60);
}

s32 bssplitup_entrypoint_17(s32 player)
{
    s32 next_state;
    next_state = 0;
    if (baanim_isStopped()) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

void bssplitup_entrypoint_18(s32 player)
{
    func_800A0CF4(player, 0);
}

int bssplitup_entrypoint_19(s32 index)
{
    return D_80800740_bssplitup[index];
}

// TU-NOTE: the tables below are defined in C; IDO schedules some functions differently unless they are in the same unit.
extern void _bssplitup_entrypoint_2();
extern void _bssplitup_entrypoint_0();
extern void _bssplitup_entrypoint_1();
extern void func_80099AA8();
extern void _bssplitup_entrypoint_6();
extern void _bssplitup_entrypoint_4();
extern void _bssplitup_entrypoint_5();
extern void _bssplitup_entrypoint_10();
extern void _bssplitup_entrypoint_8();
extern void _bssplitup_entrypoint_9();
extern void _bssplitup_entrypoint_14();
extern void _bssplitup_entrypoint_12();
extern void _bssplitup_entrypoint_13();
extern void func_80099B94();
extern void _bssplitup_entrypoint_18();
extern void _bssplitup_entrypoint_16();
extern void _bssplitup_entrypoint_17();
s32 D_80800700_bssplitup[4] = {(u32) _bssplitup_entrypoint_2, (u32) _bssplitup_entrypoint_0,
                               (u32) _bssplitup_entrypoint_1, (u32) func_80099AA8};
s32 D_80800710_bssplitup[4] = {(u32) _bssplitup_entrypoint_6, (u32) _bssplitup_entrypoint_4,
                               (u32) _bssplitup_entrypoint_5, (u32) func_80099AA8};
s32 D_80800720_bssplitup[4] = {(u32) _bssplitup_entrypoint_10, (u32) _bssplitup_entrypoint_8,
                               (u32) _bssplitup_entrypoint_9, (u32) func_80099AA8};
s32 D_80800730_bssplitup[4] = {(u32) _bssplitup_entrypoint_14, (u32) _bssplitup_entrypoint_12,
                               (u32) _bssplitup_entrypoint_13, (u32) func_80099B94};
s32 D_80800740_bssplitup[4] = {(u32) _bssplitup_entrypoint_18, (u32) _bssplitup_entrypoint_16,
                               (u32) _bssplitup_entrypoint_17, (u32) func_80099B94};
