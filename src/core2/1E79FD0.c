#include "core2/1E79FD0.h"
extern f32 D_80125490;

#define STATE(p) (*(LocalState **) ((u8 *) (p) + 0x150))
extern s32 func_80092B80(s32);
typedef struct LocalModelParams {
    f32 blend_0, blend_1;
    u8 pad_8[5];
    u8 unk_0D, unk_0E, unk_0F, expression, unk_11, unk_12;
    u8 unk_13, unk_14, unk_15, unk_16, unk_17;
} LocalModelParams;
typedef struct LocalModelPlayer {
    u8 pad_0[0x138];
    LocalModelParams *params;
    u8 pad_13C[0x48];
    s32 config;
} LocalModelPlayer;
extern void func_800DF3E0(void);
extern void func_800DF744(s32, s32);
extern f32 func_800F1214(f32, f32, f32);
extern s32 func_800A940C(s32);
extern u8 D_80119250[];
extern u8 D_80119254[];
extern f32 func_800D8FF8(void);
extern f32 func_800964DC(PlayerState *);
extern void func_8009C128(PlayerState *, f32 *);
extern f32 func_800DC178(f32, f32);
extern void func_8009DBF0(PlayerState *, s32, f32);
extern s32 _fxsplash_entrypoint_2(f32 *, f32);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern void _fxripple_entrypoint_0(s32, f32 *);
extern void _fxsplash25d_entrypoint_0(f32 *);
typedef struct {
    u8 below, active, contact, pad_3;
    f32 offset;
} LocalState;
extern f32 func_8009C150(PlayerState *);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
void func_800A0714();
void func_800A0CD0();
void func_800A0D74(s32 player, f32 value);
void func_800A0D84(s32 player, f32 value);
int func_800A0DB8();

s32 func_800A06E0()
{
    return 0x18;
}

void func_800A06E8(s32 player)
{
    func_800A0714(player, func_80092B80(player));
}

// Applies the appearance parameters to the parts of the player model asset.
void func_800A0714(player, model_id) LocalModelPlayer *player;
s32 model_id;
{
    s32 variant;
    func_800DF3E0();
    switch (model_id) {
        case 0x607:
        case 0x608:
        case 0x61F:
        case 0x992:
            if (!player->params->unk_17) {
                func_800DF744(9, player->params->expression);
                func_800DF744(15, player->params->expression);
                func_800DF744(10, player->params->unk_0E);
                func_800DF744(16, player->params->unk_0E);
                func_800DF744(11, player->params->unk_0D);
                func_800DF744(17, player->params->unk_0D);
                variant = player->params->unk_0F;
                func_800DF744(34, variant);
                func_800DF744(38, variant);
                func_800DF744(35, variant);
                func_800DF744(39, variant);
                variant = player->params->unk_11 + 1;
                func_800DF744(42, variant);
                func_800DF744(46, variant);
                func_800DF744(43, variant);
                func_800DF744(47, variant);
            }
            func_800DF744(3, player->params->unk_12);
            func_800DF744(4, player->params->unk_12);
            func_800DF744(7, player->params->unk_12);
            func_800DF744(18, player->params->unk_12);
            variant = func_800F1214(player->params->blend_0, 1.0f, 8.0f);
            func_800DF744(53, variant);
            func_800DF744(57, variant);
            variant = func_800F1214(player->params->blend_1, 1.0f, 8.0f);
            func_800DF744(52, variant);
            func_800DF744(56, variant);

            break;
        case 0x61C:
        case 0x83A:
        case 0x993:
            if (player->params->unk_15)
                func_800DF744(3, 2);
            else
                func_800DF744(3, 1);
            variant = player->params->unk_0F;
            func_800DF744(6, variant);
            func_800DF744(7, variant);
            variant = player->params->unk_11 + 1;
            func_800DF744(4, variant);
            func_800DF744(5, variant);
            func_800DF744(0x33, (s32) func_800F1214(player->params->blend_0, 1.0f, 5.0f));
            func_800DF744(0x32, (s32) func_800F1214(player->params->blend_1, 1.0f, 5.0f));
            break;
        case 0x665:
            func_800DF744(4, player->params->unk_13);
            func_800DF744(5, player->params->unk_14);
            func_800DF744(1, (s32) func_800F1214(player->params->blend_1, 1.0f, 4.0f));
            break;
        case 0x60D:
            func_800DF744(1, (s32) func_800F1214(player->params->blend_0, 1.0f, 4.0f));
            func_800DF744(2, (s32) func_800F1214(player->params->blend_1, 1.0f, 4.0f));
            break;
        case 0x609:
            func_800DF744(0x33, (s32) func_800F1214(player->params->blend_0, 1.0f, 4.0f));
            func_800DF744(0x32, (s32) func_800F1214(player->params->blend_1, 1.0f, 4.0f));
            break;
        case 0x60B:
        case 0x60C:
        case 0x623:
        case 0x624:
        case 0x626:
        case 0x998:
            func_800DF744(0x33, (s32) func_800F1214(player->params->blend_0, 1.0f, 5.0f));
            func_800DF744(0x32, (s32) func_800F1214(player->params->blend_1, 1.0f, 5.0f));
            break;
        case 0x988:
            variant = D_80119250[func_800A940C(player->config)];
            func_800DF744(5, variant);
            func_800DF744(4, variant);
            func_800DF744(3, player->params->unk_16);
            break;
        case 0x98D:
            func_800DF744(4, D_80119254[func_800A940C(player->config)]);
            break;
        case 0x984:
        case 0x986:
            func_800DF744(1, player->params->unk_16);
    }
}

// Returns the current expression.
// Matching: the extra temporary is needed for the match.
s32 func_800A0C20(PlayerState *player)
{
    s32 *params_addr;
    return *((char *) *(params_addr = (s32 *) ((char *) player + 0x138)) + 0x10);
}

f32 func_800A0C2C(void *player)
{
    return ((f32 *) *(void **) ((char *) player + 0x138))[0];
}

f32 func_800A0C38(u8 *player)
{
    return *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x138) + 4);
}

// Resets the appearance parameters.
// Matching: copying the parameter into a local is needed for the match.
int func_800A0C44(PlayerState *player)
{
    PlayerState *player_copy = player;
    func_800A0CF4(player_copy, 0);
    func_800A0CE8(player_copy, 0);
    func_800A0CDC(player_copy, 0);
    func_800A0D74(player_copy, 0);
    func_800A0D84(player_copy, 0);
    func_800A0DB8(player_copy, 1);
    func_800A0DD0(player_copy, 0);
    func_800A0CD0(player_copy, 1);
    func_800A0DC4(player_copy, 0);
}

void func_800A0CD0(player, value) void *player;
s32 value;
{
    ((s8 *) *(void **) ((char *) player + 0x138))[18] = value;
}

void func_800A0CDC(player, value) PlayerState *player;
s32 value;
{
    *(u8 *) (*(s32 *) ((char *) player + 0x138) + 0xD) = value;
}

void func_800A0CE8(player, value) PlayerState *player;
s32 value;
{
    *(s8 *) ((char *) (*(s32 **) ((char *) player + 0x138)) + 0xE) = value;
}

void func_800A0CF4(PlayerState *player, s32 expression)
{
    func_800A0D14(player, expression, 0.0f);
}

// Stores the expression; it takes effect at once if delay is 0, else when the timer runs out.
void func_800A0D14(PlayerState *player, s32 expression, f32 delay)
{
    *(f32 *) ((char *) ((*(s32 *) ((char *) (player) + 312))) + 0x8) = delay;
    *(u8 *) ((char *) ((*(s32 *) ((char *) (player) + 312))) + 0xC) = expression;

if (delay == 0.0f) {
    *(u8 *) ((char *) *(s32 *) ((char *) player + 312) + 0x10) = expression;
}

}

void func_800A0D44(int player, int expression)
{
    func_800A0D14(player, expression, 0.2f);
}

void func_800A0D68(void *player, s32 value)
{
    ((s8 *) (*(void **) ((char *) player + 0x138)))[23] = value;
}

void func_800A0D74(s32 player, f32 value)
{
    *(f32 *) (*(s32 *) (player + 0x138)) = value;
}

void func_800A0D84(s32 player, f32 value)
{
    *(f32 *) (*(s32 *) (player + 0x138) + 0x4) = value;
}

void func_800A0D94(void *player, s32 value)
{
    ((s8 *) (*(void **) ((char *) player + 0x138)))[22] = value;
}

s32 func_800A0DA0(PlayerState *player, s32 value)
{
    *(u8 *) (*(s32 *) ((char *) player + 0x138) + 0x14) = value;
}

void func_800A0DAC(PlayerState *player, s32 value)
{
    *(u8 *) (*(s32 *) ((char *) player + 0x138) + 0x13) = value;
}

// Matching: the ^ 0 and the temporary are needed for the match.
int func_800A0DB8(player, value)
s32 player;
long value;
{
    s32 addr;
    addr = player ^ 0;
    addr += 0x138;
    *(((s8 *) (*((u8 **) addr))) + 0xF) = value;
}

void func_800A0DC4(player, value) PlayerState *player;
s32 value;
{
    *(u8 *) ((char *) (*(s32 **) ((char *) (player) + 0x138)) + 0x15) = (s8) value;
}

void func_800A0DD0(player, value) PlayerState *player;
s32 value;
{
    s32 *params_addr;
    params_addr = (s32 *) ((u8 *) player + 0x138);
    *(u8 *) (*params_addr + 17) = (u8) value;

}

void func_800A0DDC(void *player)
{
    if (*(f32 *) (*(u8 **) ((u8 *) player + 0x138) + 8) != 0.0f) {
        *(f32 *) (*(u8 **) ((u8 *) player + 0x138) + 8) -= func_800D8FF8();
        if (*(f32 *) (*(u8 **) ((u8 *) player + 0x138) + 8) <= 0.0f) {
            *(u8 *) (*(u8 **) ((u8 *) player + 0x138) + 0x10) =
                *(u8 *) (*(u8 **) ((u8 *) player + 0x138) + 0xC);
        }
    }

}

s32 func_800A0E50()
{
    return 0x14;
}

f32 func_800A0E58(struct SomeStruct *player)
{
    return *(f32 *) ((char *) (*(s32 **) ((char *) player + 0x150)) + 0x8);
}

// Splash, ripple and bubble effects plus sound when entering the water.
void func_800A0E64(PlayerState *player)
{
    f32 pos[3];
    s32 effect;
    f32 water_y;

if (func_80096544(player)) {
    func_8009DBF0(player, 0x409, func_800DC178(D_80125490, 0.75f));
    func_8009C128(player, pos);
    water_y = func_800964DC(player);
    pos[1] = water_y;
    effect = _fxsplash_entrypoint_2(pos, 35.0f);
    _fxripple_entrypoint_0(3, pos);
    func_800BA930(effect, -350, 300, -350, 350, 500, 350);
    func_800BA22C(effect, 10);
    func_800BA930(effect, -150, 500, -150, 150, 800, 150);
    func_800BA22C(effect, 10);
    _fxsplash25d_entrypoint_0(pos);
    pos[1] -= 30.0f;
    effect = _fxairbub_entrypoint_1(pos, 20.0f, water_y, 1.0f);
    func_800BA930(effect, -60, -250, -60, 60, -150, 60);
    func_800BA22C(effect, 8);
}

}

s32 func_800A0FCC(s32 player)
{
    return ((u8 *) (*(u8 **) (player + 0x150)))[2];
}

// Matching: the extra temporaries are needed for the match.
s32 func_800A0FD8(s32 player)
{
    int addr;
    s32 value;
    value = -0x150;
    addr = player - value;
    value = ((u8 **) addr)[0][0];
    return value;
}

s32 func_800A0FE4(s32 player)
{
    return ((u8 *) (*(u8 **) (player + 0x150)))[1];
}

// Resets the water tracking state.
void func_800A0FF0(void *player)
{
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x150)))) + (2))) = 1;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x150)))) + (0))) = 0;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x150)))) + (1))) = 0;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x150)))) + (4))) = 50.0f;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x150)))) + (8))) = 70.0f;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x150)))) + (0xC))) = -1.0f;
}

void func_800A1040(PlayerState *player)
{
    f32 *state;
    f32 *state_2;
    state = *((f32 **) (((char *) player) + 0x150));
    state[1] = state[3];

// Matching: empty block needed for the match.
if (player && player) {
}

state_2 = *((f32 **) (((char *) player) + 0x150));
state_2[2] = state_2[4];
*((f32 *) (((char *) (*((u32 **) (((char *) player) + 0x150)))) + 0xC)) = -1.0f;
}

void func_800A106C(PlayerState *player, f32 param_1, f32 param_2)
{
    f32 *state;
    f32 *state_2;
    char *base;
    state = *((f32 **) (((char *) player) + (0x150 & 0xFFFFu)));
    state[3] = state[1] * 1.0f;

// Matching: needed for the match.
if (1) {
    state = (char *) player;
    state_2 = *(f32 **) (state + 84);
    state_2[4] = state_2[2];
    base = state;
    (*(f32 **) (base + 0x150))[1] = param_1;
    (*(f32 **) (base + 0x150))[2] = param_2;
}

}

// Tracks whether the player is below the water surface, with hysteresis; triggers the entry splash.
void func_800A10A0(PlayerState *player)
{
    f32 surface;
    s32 was_below;
    s32 unk_0;
    was_below = STATE(player)->below;
    surface = func_800964DC(player) - STATE(player)->offset;

if (was_below) {
    STATE(player)->below = func_80096524(player) && func_8009C150(player) < surface + 2.0f;
} else {

STATE(player)->below = func_80096524(player) && func_8009C150(player) < surface - 2.0f;
}
if (!was_below && STATE(player)->below && baphysics_get_vertical_velocity(player) < -40.0f)
    func_800A0E64(player);
unk_0 = func_800F3ED0(player);
if (func_800A0FD8(player))
    STATE(player)->active = 1;
else if (player_isStable(player) || unk_0 == 10 || unk_0 == 5)
    STATE(player)->active = 0;
STATE(player)->contact = func_80096518(player);
}

// TU-NOTE: the .data of this file is defined here in C; values are from the ROM.
u8 D_80119250[4] = {0x2, 0x1, 0x4, 0x3};
u8 D_80119254[12] = {0x3, 0x2, 0x1, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
