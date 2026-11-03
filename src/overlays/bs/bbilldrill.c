// TU-NOTE: the .data of this overlay is defined in this file; its tables point to functions here,
// and IDO schedules some of them differently unless they share a unit. Values come from the ROM.
// D_80800AC8_bsbbilldrill is declared int[] to match the object.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/anim.h"

struct UnkStruct {
    char pad[0x168];
    s32 light;
};
extern u32 D_80800AB0_bsbbilldrill[][3];
extern void func_800C8E54(s32, f32, f32);
extern f32 func_80092BF4(s32);
extern int D_80800AC8_bsbbilldrill[];
extern f32 func_800D8FF8(void);
extern void func_80093300(PlayerState *, f32);
extern void func_80098520(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 D_80800B68_bsbbilldrill[];
extern f32 func_800DC0C0(void);
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern u8 D_80800B30_bsbbilldrill[];
extern u8 D_80800B10_bsbbilldrill[];
extern u8 D_80800B50_bsbbilldrill[];
extern f32 yaw_get(PlayerState *);
extern s32 _batimer_set(PlayerState *, s32, f32);
extern s32 func_8009DF18(PlayerState *, s32, f32, s32);
extern s32 baphysics_set_terminal_velocity(PlayerState *, f32);
extern s32 baphysics_set_vertical_velocity(PlayerState *, f32);
extern s32 func_8009E53C(PlayerState *, s32, f32);
extern f32 func_800962D4(PlayerState *);
extern s32 func_800EFA4C(f32 *, f32, f32, f32);
extern s32 _badust_entrypoint_10(PlayerState *, f32);
extern s32 _bamotor_entrypoint_3(PlayerState *, f32, f32, f32, f32, f32, f32);
extern s32 func_8009DE38(PlayerState *, s32, f32);
extern s32 func_8009328C(PlayerState *, f32);
extern f32 _batimer_get(PlayerState *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 mlAbsF(f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);

// Clears the light handle.
void func_80800000_bsbbilldrill(void *player)
{
    ((struct UnkStruct *) player)->light = 0;
}

// Creates or moves the flickering point light under the player.
void func_80800008_bsbbilldrill(PlayerState *player)
{
    f32 pos[3];

    if (func_800BF8E4() > 0) {
        if (*(s32 *) ((u8 *) player + 0x168) == 0) {
            *(s32 *) ((u8 *) player + 0x168) = func_800C8A98();
            func_800C8E54(*(s32 *) ((u8 *) player + 0x168), 80.0f, 350.0f);
            func_800C8F64(*(s32 *) ((u8 *) player + 0x168), 0xB);
        }
        func_8009C128(player, pos);
        pos[1] -= 10.0f;
        func_800C8CB8(*(s32 *) ((u8 *) player + 0x168), pos);
        func_800C8E84(*(s32 *) ((u8 *) player + 0x168), D_80800AB0_bsbbilldrill[func_8001210C(1)]);
    }
}

// Fades out the point light.
void func_808000C0_bsbbilldrill(u8 *player)
{
    s32 light;
    light = *(s32 *) ((u8 *) player + 0x168);
    if (light != 0) {
        *(s32 *) ((u8 *) player + 0x168) = _chlightfader_entrypoint_1(light, 0x3F19999A, 2);
    }
}

void func_80800100_bsbbilldrill(s32 player)
{
    f32 speed = func_80092BF4(player);
    if (speed == 0.0f) {
        speed = 8.0f;
    }
    speed = -speed;
    func_80093300(player, speed);
}

int func_80800158_bsbbilldrill(s32 pos)
{
    func_800BABB8(func_800B5BE4(9), pos, 0, 0x3F800000, &D_80800AC8_bsbbilldrill);
}

// Spawns a dust particle under the player.
void func_8080019C_bsbbilldrill(void *player)
{
    f32 pos[3];
    f32 scale;
    s32 particle;

    scale = func_800DC0C0() <= 0.2f ? 0.15f : 0.09f;
    func_8009C128(player, pos);
    pos[1] -= 80.0f;
    particle = func_80800158_bsbbilldrill(pos);
    func_800BA7C4(particle, scale, scale);
    func_800BA7FC(particle, scale, scale);
    func_800BA22C(particle, 2);
}

void func_80800250_bsbbilldrill(s32 player)
{
    f32 pos[3];
    func_8009C128(player, pos);
    pos[1] -= 80.0f;
    func_800BA22C(_fxdlsmoke_entrypoint_0(pos), 1);
}

void func_80800298_bsbbilldrill(PlayerState *player)
{
    _bswalk_entrypoint_1(player);
    baphysics_set_target_horizontal_velocity(
        player, baphysics_get_target_horizontal_velocity(player) * 0.1f);
}

// State setup for each drill phase.
void func_808002DC_bsbbilldrill(player, state) PlayerState *player;
u32 state;
{
    f32 pos[3];
    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }

    player->unk15C.bytes[0] = state;
    switch (state) {
        case 1:
            *(f32 *) ((u8 *) player + 0x16C) = yaw_get(player);
            *(f32 *) ((u8 *) player + 0x170) = 0.0f;
            func_80098520(player, 0.0f);
            _batimer_set(player, 0, 0.3f);
            if (func_8009EA2C()) {
                player->unk164.bytes[0] = func_8009D454(player, 0, D_80800B30_bsbbilldrill);
            } else {
                player->unk164.bytes[0] = func_8009D454(player, 0, D_80800B10_bsbbilldrill);
            }
            player->unk15C.bytes[1] = 0;
            break;
        case 2:
            *(f32 *) ((u8 *) player + 0x170) = 1500.0f;
            func_80098520(player, 1.0f);
            _batimer_set(player, 0, 0.15f);
            break;
        case 3:
            func_8009DF18(player, 0x442F, 1.2f, 30000);
            baphysics_set_terminal_velocity(player, -5000.0f);
            baphysics_set_gravity(player, -20000.0f);
            baphysics_set_vertical_velocity(player, 2300.0f);
            baphysics_set_target_horizontal_velocity(player, 0.0f);
            func_8009E53C(player, 1, -100.0f);
            break;
        case 4:
            func_800EFA4C(pos, 0.0f, 80.0f - func_800962D4(player), 0.0f);
            func_8009C1F8(player, pos);
            _badust_entrypoint_10(player, -func_800962D4(player));
            baflag_set(player, 0x26);
            baphysics_set_gravity(player, 0.0f);
            func_8009BA9C(player, 0);
            _batimer_set(player, 0, 0.8f);
            _bamotor_entrypoint_3(player, 1.0f, 0.7f, 0.01f, 0.1f, 0.7, 0.4f);
            _bashake_entrypoint_1(player, 3, 2);
            player->unk160.bytes[0] = func_8009D454(player, 0, D_80800B50_bsbbilldrill);
            func_8009DE38(player, 0x40D, 1.0f);
            break;
        case 5:
            func_8009E53C(player, 1, 0.0f);
            baflag_clear(player, 0x22);
            func_8009328C(player, yaw_get(player));
            baphysics_set_vertical_velocity(player, 730.0f);
            baphysics_set_gravity(player, -2400.0f);
            baanim_setEndAndDuration(player, 0.7299000025f, 2.1f);
            func_808000C0_bsbbilldrill(player);
    }
}

// Advances the spin angle by spin speed * delta time.
void func_808005C0_bsbbilldrill(u8 *player)
{
    f32 dt = func_800D8FF8();
    *(f32 *) (player + 0x16C) += *(f32 *) (player + 0x170) * dt;
    func_8009328C(player, *(f32 *) (player + 0x16C));
}

// End.
void bsbbilldrill_entrypoint_0(PlayerState *player)
{
    func_800931AC(player, 1);
    func_80093300(player, 0.0f);
    func_80098520(player, 1.0f);
    baphysics_reset_gravity(player);
    baphysics_reset_terminal_velocity(player);
    func_800A0CF4(player, 0);
    baflag_clear(player, 0x22);
    baflag_clear(player, 0x26);
    func_8009E474(player);
    func_808000C0_bsbbilldrill(player);
}

// Init.
void bsbbilldrill_entrypoint_1(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x61);
    anctrl_setDuration(anim_ctrl, 1.02f);
    anctrl_setStart(anim_ctrl, 0.3637f);
    anctrl_setSubrange(anim_ctrl, 0, 0.4546f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 6);
    baphysics_set_gravity(player, 0);
    baphysics_set_target_horizontal_velocity(player, 0);
    func_800A0CF4(player, 1);
    baflag_clear(player, 0x22);
    baflag_clear(player, 0x26);
    func_800931AC(player, 3);
    func_8009E4AC(player);
    player->unk164.bytes[0] = 0;
    player->unk160.bytes[0] = 0;
    player->unk15C.bytes[0] = 0;
    func_808002DC_bsbbilldrill(player, 1);
    func_80800000_bsbbilldrill(player);
}

// Update.
void bsbbilldrill_entrypoint_2(PlayerState *player)
{
    s32 next_state = 0;
    f32 timer;
    f32 vec[3];
    s32 unk_0;

    switch (*((u8 *) player + 0x15C)) {
        case 1:
            func_80800298_bsbbilldrill(player);
            timer = _batimer_get(player, 0);
            *(f32 *) ((u8 *) player + 0x170) = func_800F10B4(timer, 0.0f, 0.3f, 1500.0f, 50.0f);
            func_808005C0_bsbbilldrill(player);
            func_80098520(player, func_800F10B4(timer, 0.0f, 0.3f, 1.0f, 0.0f));
            if (_batimer_decrement(player, 0)) {
                func_808002DC_bsbbilldrill(player, 2);
            }
            break;
        case 2:
            func_80800298_bsbbilldrill(player);
            func_808005C0_bsbbilldrill(player);
            if (_batimer_decrement(player, 0)) {
                func_808002DC_bsbbilldrill(player, 3);
            }
            break;
        case 3:
            func_80096394(player, vec);
            if (mlAbsF(vec[1]) < 1.0f) {
                *((u8 *) player + 0x15D) += 1;
            } else {
                *((u8 *) player + 0x15D) = 0;
            }
            func_808005C0_bsbbilldrill(player);
            if (baphysics_get_vertical_velocity(player) < 0.0f) {
                baflag_set(player, 0x22);
            }
            if (player_inWater(player)) {
                next_state = 0x4C;
            } else if (func_8008DF8C(player, 0x50) || *((u8 *) player + 0x15D) >= 4) {
                if (func_800954E8(player, &unk_0)) {
                    next_state = 0x72;
                } else {
                    func_808002DC_bsbbilldrill(player, 4);
                }
            }
            break;
        case 4:
            baflag_clear(player, 0x26);
            func_808005C0_bsbbilldrill(player);
            func_80800250_bsbbilldrill(player);
            func_80800100_bsbbilldrill(player);
            func_8080019C_bsbbilldrill(player);
            func_80800008_bsbbilldrill(player);
            if (_batimer_decrement(player, 0)) {
                func_808002DC_bsbbilldrill(player, 5);
            }
            break;
        case 5:
            _bswalk_entrypoint_1(player);
            if (player_inWater(player)) {
                next_state = 0x4C;
            }
            if (player_isStable(player)) {
                baanim_setEndAndDuration(player, 1.0f, 1.9f);
                next_state = 0x20;
            }
    }
    bs_setState(player, next_state);
}

int bsbbilldrill_entrypoint_3(s32 index)
{
    return D_80800B68_bsbbilldrill[index];
}

extern void _bsbbilldrill_entrypoint_0();
extern void _bsbbilldrill_entrypoint_1();
extern void _bsbbilldrill_entrypoint_2();
extern void func_80099B94();
u32 D_80800AB0_bsbbilldrill[2][3] = {0xE0, 0xE0, 0xAA, 0xE0, 0xE0, 0xE0};
int D_80800AC8_bsbbilldrill[18] = {0x1D09E2, 0x220026,  0x260019, 0x190027, 0xC8,       0xF0,
                                   0x161000, 0x40099,   0x70002,  0x150000, 0xCC002B,   0x14C01B3,
                                   0x2CFF06, 0x190FF06, 0xFA0320, 0xFA001B, -0x7CF04B0, 0x0};
u8 D_80800B10_bsbbilldrill[32] = {0x3,  0x6,  0x0,  0x13, 0x4,  0x37, 0x0,  0x15, 0x0, 0x0, 0x0,
                                  0x73, 0x0,  0x33, 0x0,  0x16, 0x55, 0xF0, 0x0,  0xC, 0x0, 0x0,
                                  0x0,  0x4C, 0x0,  0xF3, 0x1,  0xC,  0x0,  0x11, 0x0, 0x0};
u8 D_80800B30_bsbbilldrill[32] = {0x3,  0x6,  0x0,  0x13, 0x4,  0x37, 0x0,  0x15, 0x0, 0x0, 0x0,
                                  0x73, 0x0,  0x33, 0x0,  0x16, 0x55, 0xF0, 0x0,  0xC, 0x0, 0x0,
                                  0x0,  0x4C, 0x0,  0xD9, 0x0,  0xF3, 0x0,  0x11, 0x0, 0x0};
u8 D_80800B50_bsbbilldrill[24] = {0x3, 0x6,  0x0, 0x13, 0x4,  0xC9, 0x0, 0x15, 0x0, 0x0, 0x0, 0xCC,
                                  0x0, 0x33, 0x0, 0x16, 0x55, 0xF0, 0x0, 0x11, 0x0, 0x0, 0x0, 0x0};
s32 D_80800B68_bsbbilldrill[6] = {(u32) _bsbbilldrill_entrypoint_0,
                                  (u32) _bsbbilldrill_entrypoint_1,
                                  (u32) _bsbbilldrill_entrypoint_2,
                                  (u32) func_80099B94,
                                  0x0,
                                  0x0};
