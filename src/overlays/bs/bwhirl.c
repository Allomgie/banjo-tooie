// Wonderwing: while held, Kazooie wraps Banjo in her wings for invulnerability, using up a golden
// feather every 2 s. Has a glow emitter, sparkles and ignores damage interrupts.
#include "common.h"
#include "overlays/ba/playerstate.h"
extern void baanim_playForDuration_loopSmooth(Actor *a0, s32 a1, f32 a2);

extern u8 D_80800F50_bsbwhirl[];
extern f32 func_80092B8C(PlayerState *, f32 *);
extern f32 func_80092BE8(PlayerState *);
extern void func_800C8E54(s32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern f32 D_80800F5C_bsbwhirl[];
extern f32 yaw_get(PlayerState *);
extern f32 func_800136E4(f32);
extern void func_800EFCD8(f32 *, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA930();
extern f32 func_800D8FF8(void);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern s32 D_80800F98_bsbwhirl[];
extern s32 D_80800FA8_bsbwhirl[];
extern void func_800A2CE8(PlayerState *, f32, s32);
extern s32 func_8009BCD4(PlayerState *, f32);
extern s32 D_80800FB8_bsbwhirl[];
extern void *baanim_getAnimCtrlPtr();
extern void anctrl_reset(void *);
extern void anctrl_setIndex(void *, s32);
extern void anctrl_setDuration(void *, f32);
extern void func_8008B1C8(void *, f32);
extern void anctrl_setStart(void *, f32);
extern void anctrl_setSubrange(void *, f32, f32);
extern void anctrl_setPlaybackType(void *, s32);
extern void anctrl_start(void *);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern s32 D_80800FC8_bsbwhirl[];
extern s32 D_80800FD8_bsbwhirl[];
extern s32 D_80800FE8_bsbwhirl[];
extern s32 _bsrest_entrypoint_20(s32);
extern s32 _bsrest_entrypoint_13(s32);
extern void bs_setState(s32, s32);
extern s32 D_80800FF8_bsbwhirl[];
extern void func_80099B94(void);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);

// Clears the light handle.
void func_80800000_bsbwhirl(void *player)
{
    *(u32 *) ((u8 *) player + 0x160) = 0;
}

// Creates the player light if needed and moves it with the player.
void func_80800008_bsbwhirl(PlayerState *player)
{
    f32 pos[3];
    f32 offset[3];
    f32 y_offset;

    if (func_800BF8E4() > 0) {
        if (!player->unk160.word) {
            player->unk160.word = func_800C8A98();
            func_800C8E54(player->unk160.word, 80.0f, 350.0f);
            func_800C8F64(player->unk160.word, 11);
            func_800C8E84(player->unk160.word, D_80800F50_bsbwhirl);
        }
        y_offset = func_80092B8C(player, offset);
        func_8009C128(player, pos);
        func_800EF04C(pos, offset);
        func_800EF1B8(pos, func_80092BE8(player), y_offset);
        pos[1] += y_offset;
        func_800C8CB8(player->unk160.word, pos);
    }
}

// Fades the light out.
void func_808000D8_bsbwhirl(void *player)
{
    u8 *base;
    u8 *base_copy;
    u8 *light_field;
    // Matching: extra temporaries and the stray semicolon are needed for the match.
    base = (u8 *) player;
    ;
    if (0 != *(s32 *) ((u8 *) player + 0x160)) {
        // Matching: empty blocks steer IDO's register allocation.
        if (1) {
        }
        if (1) {
        }
        light_field = (u8 *) player + 0x160;
        base_copy = (u8 *) player;
        *(s32 *) light_field = _chlightfader_entrypoint_1(*(s32 *) (base + 0x160) ^ 0, 0x3E800000,
                                                       2, *(s32 *) (base_copy + 0x160));
    }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

// Sets the target speed from the stick position.
void func_80800114_bsbwhirl(PlayerState *player)
{
    f32 zone_pos;

    zone_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(zone_pos, 80.0f, 425.0f));
    }
}

// Exit handler: stops the loop sfx and fades the light unless staying in a wonderwing state.
void func_8080017C_bsbwhirl(player) Actor *player;
{
    int state = bs_getNextState();
    if ((state != 0x1B) && (state != 0x1C) && (state != 0x1D) && (state != 0x1E) &&
        (state != 0xA4) && (state != 0xA5)) {
        bastick_resetZones(player);
        func_800A0CF4(player, 0);
        func_800FC74C(0xD);
        func_808000D8_bsbwhirl(player);
    }
    func_8008CA4C(player, 1);
}

// Spawns the sparkle particles around the player.
void func_80800200_bsbwhirl(player) PlayerState *player;
{
    f32 tmp;
    f32 offset[3];
    f32 box_min[3];
    f32 box_max[3];
    f32 pos[3];
    s32 emitter;

    func_8009C128(player, pos);
    func_800EFCD8(offset, yaw_get(player), 48.0f);
    offset[1] = 0.0f;
    func_800EF04C(pos, offset);
    emitter = func_800B5BE4(0xE);
    func_800BABB8(emitter, pos, NULL, 1.0f, &D_80800F5C_bsbwhirl);
    func_8009BB24(player, offset);
    func_800EFCD8(box_min, player->unk170, 250.0f);
    func_800EFCD8(box_max, player->unk170 + 45.0f, 250.0f);
    box_min[1] = box_max[1] = 0.0f;
    func_800EF04C(box_min, offset);
    func_800EF04C(box_max, offset);
    if (box_max[0] < box_min[0]) {
        tmp = box_max[0];
        box_max[0] = box_min[0];
        box_min[0] = tmp;
    }
    if (box_max[2] < box_min[2]) {
        tmp = box_max[2];
        box_max[2] = box_min[2];
        box_min[2] = tmp;
    }
    player->unk170 = func_800136E4(player->unk170 + 45.0f);
    func_800BA930(emitter, (s16) (s32) box_min[0], 250, (s16) (s32) box_min[2], (s32) box_max[0],
                  250, (s32) box_max[2]);
    func_800BA22C(emitter, 2);
}

// Picks the next state from stick and button input.
int func_808003A8_bsbwhirl(s32 player, s32 state)
{
    s32 next_state;
    next_state = state;
    if (bastick_getZone(player) > 0) {
        next_state = 0x1C;
    }
    if (bakey_released(player, 1)) {
        next_state = 0x1E;
    }
    if (bakey_pressed(player, 8) && player_isStable(player)) {
        next_state = 0x1D;
    }
    if (player_inWater(player)) {
        next_state = 0x2D;
    }
    return next_state;
}

// Every 2 s uses one golden feather; exits when none are left.
void func_80800430_bsbwhirl(PlayerState *player, s32 *next_state)
{
    player->unk16C += func_800D8FF8();
    if (player->unk16C > 2.0f) {
        player->unk16C = 0.0f;
        _suinv_entrypoint_0(next_state, 0x1E, -1, 0x47, 1);
        if (*next_state != 0x1E) {
            func_8009DF18(player, 0x3E9, 0.8f, 0x6D60);
            _chusefeather_entrypoint_1(player->unk184, 1);
        }
    }
}

void bsbwhirl_entrypoint_0(PlayerState *player)
{
    baanim_playForDuration_once(player, 0x22, 0.5f);
    func_8009FFD8(player, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    bastick_setZoneMax(player, 0, 0.03f);
    bastick_setZoneMax(player, 1, 1.0f);
    func_800A0CF4(player, 1);
    player->unk170 = 0.0f;
    player->unk16C = 0.0f;
    func_800FC660(0xD);
    func_80800000_bsbwhirl(player);
    func_8009D874(player);
    bainput_enable(player, 1, 0);
}

int bsbwhirl_entrypoint_1(Actor *player)
{
    s32 next_state;
    next_state = 0;
    bainput_enable(player, 1, 1);
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(player))) {
        next_state = 0x1B;
    }
    func_80800008_bsbwhirl(player);
    bs_setState(player, next_state);
}

int bsbwhirl_entrypoint_2(Actor *player)
{
    bainput_enable(player, 1, 1);
    func_8080017C_bsbwhirl(player);
}

int bsbwhirl_entrypoint_3(s32 index)
{
    return D_80800F98_bsbwhirl[index];
}

void bsbwhirl_entrypoint_4(Actor *player)
{
    int value;
    // Matching: needed for the match.
    value = 0x23;
    baanim_playForDuration_loopSmooth(player, value, 1);
    value = 1;
    func_8009FFD8(player, 1, (0, 1), value, 2);
    baphysics_set_target_horizontal_velocity(player, 0);
}

void bsbwhirl_entrypoint_5(s32 player)
{
    s32 next_state;

    next_state = 0;
    func_80800200_bsbwhirl();
    next_state = func_808003A8_bsbwhirl(player, next_state);
    func_80800430_bsbwhirl(player, &next_state);
    func_80800008_bsbwhirl(player);
    if (func_8008E148(player) != 0) {
        next_state = _badrone_entrypoint_25(player);
    }
    if (player_inWater(player) != 0) {
        next_state = 0x4C;
    }
    bs_setState(player, next_state);
}

void bsbwhirl_entrypoint_6()
{
    func_8080017C_bsbwhirl();
}

int bsbwhirl_entrypoint_7(s32 index)
{
    return D_80800FA8_bsbwhirl[index];
}

void bsbwhirl_entrypoint_8(PlayerState *player)
{
    baanim_playForDuration_loopSmooth(player, 0x11, 0.53f);
    func_8008C9F0(player, 80.0f, 425.0f, 0.56f, 0.4f);
    func_8009FFD8(player, 2, 1, 1, 2);
}

void bsbwhirl_entrypoint_9(PlayerState *player)
{
    s32 next_state = 0;
    func_80800200_bsbwhirl(player);
    func_800A2CE8(player, 0.47f, 4);
    func_800A2CE8(player, 0.97f, 3);
    func_80800114_bsbwhirl(player);
    if (!bastick_getZone(player) && func_8009BCD4(player, 1.0f))
        next_state = 0x1B;
    if (bakey_released(player, 1))
        next_state = 0x1E;
    if (bakey_pressed(player, 8) && player_isStable(player))
        next_state = 0x1D;
    if (player_inWater(player))
        next_state = 0x4C;
    func_80800430_bsbwhirl(player, &next_state);
    func_80800008_bsbwhirl(player);
    if (func_8008E148(player))
        next_state = _badrone_entrypoint_25(player);
    bs_setState(player, next_state);
}

void bsbwhirl_entrypoint_10()
{
    func_8080017C_bsbwhirl();
}

int bsbwhirl_entrypoint_11(s32 index)
{
    return D_80800FB8_bsbwhirl[index];
}

void bsbwhirl_entrypoint_12(PlayerState *player)
{
    void *anim_ctrl = baanim_getAnimCtrlPtr(player);

    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x1B);
    anctrl_setDuration(anim_ctrl, 0.8f);
    func_8008B1C8(anim_ctrl, 0.134f);
    anctrl_setStart(anim_ctrl, 0.14f);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.4495f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 6);
    if (bastick_distance(player) != 0.0f)
        yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    func_80800114_bsbwhirl(player);
    baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                      baphysics_get_target_horizontal_velocity(player));
    baphysics_set_vertical_velocity(player, 693.5f);
    baphysics_set_gravity(player, -1200.0f);
    func_8009D7A4(player, 0.91f, 1.09f);
    *(s32 *) ((u8 *) player + 0x15C) = 0;
}

void bsbwhirl_entrypoint_13(Actor *player)
{
    s32 next_state;
    s32 anim_ctrl;
    f32 vel_z;
    f32 vel_y;
    f32 vel_x;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    func_80800200_bsbwhirl(player);
    func_80800114_bsbwhirl(player);
    func_8009BB24(player, &vel_x);
    if ((bakey_released(player, 8) != 0) && (vel_y > 0.0f)) {
        baphysics_reset_gravity(player);
    }
    switch (*(s32 *) ((s8 *) player + 0x15C)) {
        case 0:
            if (func_8008DF8C(player, 0x82) != 0) {
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setDuration(anim_ctrl, 0.8f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                *(s32 *) ((s8 *) player + 0x15C) = 1;
            }
            break;
        case 1:
            if (player_inWater(player) != 0) {
                next_state = 0x2D;
            }
            if (player_isStable(player) != 0) {
                *(s32 *) ((s8 *) player + 0x15C) = 2;
                func_8009FE58(player);
            }
            break;
        case 2:
            if (anctrl_isStopped(anim_ctrl) != 0) {
                next_state = 0x1B;
            }
            next_state = func_808003A8_bsbwhirl(player, next_state);
    }
    func_80800430_bsbwhirl(player, &next_state);
    func_80800008_bsbwhirl(player);
    if (func_8008DA24(player) != 0) {
        next_state = 0xA8;
    }
    if (player_inWater(player) != 0) {
        next_state = 0x4C;
    }
    bs_setState(player, next_state);
}

void bsbwhirl_entrypoint_14(s32 player)
{
    baphysics_reset_gravity();
    func_8080017C_bsbwhirl(player);
}

int bsbwhirl_entrypoint_15(s32 index)
{
    return D_80800FC8_bsbwhirl[index];
}

void bsbwhirl_entrypoint_16(PlayerState *player)
{
    void *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    func_8008B188(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, 0x22);
    anctrl_setDuration(anim_ctrl, 0.5f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8008CA4C(player, 1);
    func_8009D2D8(player, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800FCAE0(13, 0, 4000);
}

int bsbwhirl_entrypoint_17(Actor *player)
{
    s32 next_state;
    next_state = 0;
    // Matching: needed for the match.
    if (anctrl_isStopped((s32) baanim_getAnimCtrlPtr(player) | 0)) {
        next_state = 1;
    }
    func_80800008_bsbwhirl(player);
    bs_setState(player, next_state);
}

void bsbwhirl_entrypoint_18()
{
    func_8080017C_bsbwhirl();
}

int bsbwhirl_entrypoint_19(s32 index)
{
    return D_80800FD8_bsbwhirl[index];
}

void bsbwhirl_entrypoint_20()
{
    _bsdrone_entrypoint_0();
}

void bsbwhirl_entrypoint_21(s32 player)
{
    func_80800200_bsbwhirl();
    func_80800008_bsbwhirl(player);
    _bsdrone_entrypoint_1(player);
}

void bsbwhirl_entrypoint_22(s32 player)
{
    _bsdrone_entrypoint_2();
    func_8080017C_bsbwhirl(player);
}

int bsbwhirl_entrypoint_23(s32 index)
{
    return D_80800FE8_bsbwhirl[index];
}

void bsbwhirl_entrypoint_24(s32 player)
{
    _bsrest_entrypoint_14();
    func_8080017C_bsbwhirl(player);
}

void bsbwhirl_entrypoint_25()
{
    _bsrest_entrypoint_16();
}

void bsbwhirl_entrypoint_26(s32 player)
{
    s32 next_state = 0;
    func_80800200_bsbwhirl(player);
    func_80800008_bsbwhirl(player);
    if (_bsrest_entrypoint_20(player)) {
        next_state = _bsrest_entrypoint_13(player);
    }
    bs_setState(player, next_state);
}

int bsbwhirl_entrypoint_27(s32 index)
{
    return D_80800FF8_bsbwhirl[index];
}

// Ignores damage interrupts.
int func_80800EA0_bsbwhirl(s32 player, void *handler)
{
    s32 interrupt = func_8009E6EC(player);

    if (interrupt == 0x1F || interrupt == 0x20 || interrupt == 0x21 || interrupt == 0x4E || interrupt == 0x51 || interrupt == 0x52) {
        func_8009E830(player, 1);
        return;
    }

    ((void (*)(s32)) handler)(player);
}

void bsbwhirl_entrypoint_28(s32 player)
{
    func_80800EA0_bsbwhirl(player, &func_80099B94);
}

extern void _bsbwhirl_entrypoint_2();
extern void _bsbwhirl_entrypoint_0();
extern void _bsbwhirl_entrypoint_1();
extern void _bsbwhirl_entrypoint_28();
extern void _bsbwhirl_entrypoint_6();
extern void _bsbwhirl_entrypoint_4();
extern void _bsbwhirl_entrypoint_5();
extern void _bsbwhirl_entrypoint_10();
extern void _bsbwhirl_entrypoint_8();
extern void _bsbwhirl_entrypoint_9();
extern void _bsbwhirl_entrypoint_14();
extern void _bsbwhirl_entrypoint_12();
extern void _bsbwhirl_entrypoint_13();
extern void _bsbwhirl_entrypoint_18();
extern void _bsbwhirl_entrypoint_16();
extern void _bsbwhirl_entrypoint_17();
extern void _bsbwhirl_entrypoint_22();
extern void _bsbwhirl_entrypoint_20();
extern void _bsbwhirl_entrypoint_21();
extern void _bsdrone_entrypoint_3();
extern void _bsbwhirl_entrypoint_24();
extern void _bsbwhirl_entrypoint_25();
extern void _bsbwhirl_entrypoint_26();
u8 D_80800F50_bsbwhirl[12] = {0x0, 0x0, 0x0, 0xE0, 0x0, 0x0, 0x0, 0xE0, 0x0, 0x0, 0x0, 0xAA};
f32 D_80800F5C_bsbwhirl[15] = {2.666775e-39f,  1.010176e-39f,   4.683596e-39f, 9.18474e-40f,
                               9.18384e-40f,   1.83885e-40f,    3.122513e-39f, 6.979533e-39f,
                               2.295942e-39f,  5.32e-43f,       6.17e-43f,     3.949141e-39f,
                               1.4050869e-38f, -1.6365232e+37f, 0.0f};
s32 D_80800F98_bsbwhirl[4] = {(u32) _bsbwhirl_entrypoint_2, (u32) _bsbwhirl_entrypoint_0,
                              (u32) _bsbwhirl_entrypoint_1, (u32) _bsbwhirl_entrypoint_28};
s32 D_80800FA8_bsbwhirl[4] = {(u32) _bsbwhirl_entrypoint_6, (u32) _bsbwhirl_entrypoint_4,
                              (u32) _bsbwhirl_entrypoint_5, (u32) _bsbwhirl_entrypoint_28};
s32 D_80800FB8_bsbwhirl[4] = {(u32) _bsbwhirl_entrypoint_10, (u32) _bsbwhirl_entrypoint_8,
                              (u32) _bsbwhirl_entrypoint_9, (u32) _bsbwhirl_entrypoint_28};
s32 D_80800FC8_bsbwhirl[4] = {(u32) _bsbwhirl_entrypoint_14, (u32) _bsbwhirl_entrypoint_12,
                              (u32) _bsbwhirl_entrypoint_13, (u32) _bsbwhirl_entrypoint_28};
s32 D_80800FD8_bsbwhirl[4] = {(u32) _bsbwhirl_entrypoint_18, (u32) _bsbwhirl_entrypoint_16,
                              (u32) _bsbwhirl_entrypoint_17, (u32) _bsbwhirl_entrypoint_28};
s32 D_80800FE8_bsbwhirl[4] = {(u32) _bsbwhirl_entrypoint_22, (u32) _bsbwhirl_entrypoint_20,
                              (u32) _bsbwhirl_entrypoint_21, (u32) _bsdrone_entrypoint_3};
s32 D_80800FF8_bsbwhirl[6] = {(u32) _bsbwhirl_entrypoint_24,
                              (u32) _bsbwhirl_entrypoint_25,
                              (u32) _bsbwhirl_entrypoint_26,
                              (u32) _bsbwhirl_entrypoint_28,
                              0x0,
                              0x0};

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/bs/bwhirl.data.s) is defined here
// in C. Its tables hold pointers to functions of this file; IDO's assembler schedules some of
// these functions differently unless the tables are in the same unit. Values are taken from the
// ROM. D_80800F5C_bsbwhirl is declared as f32[] to match the object.
