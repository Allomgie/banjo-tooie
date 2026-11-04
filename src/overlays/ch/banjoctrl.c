#include "common.h"

#define BOX ((f32 *) this->actorData)
extern int D_80801270_chbanjoctrl[];
extern s32 _chbanjoctrl_entrypoint_1(s32);
extern s32 _chbanjoctrl_entrypoint_2(s32);
extern void func_800F69E8(void);
extern void func_800F6968(void);
extern f32 func_800F2094(f32, f32);
extern s32 D_808012B8_chbanjoctrl[];
extern int func_8010CB0C(void *, s32, s32, s32);
extern int func_800F6C5C(s32);
extern int func_800F6478(s32);
extern f32 func_8010CD28(Actor *);
extern void func_800EFCD8(f32 *, f32, f32);
extern int func_800F7D90(s32, s32, f32 *, s32);
extern void _chhotwaterpoolbits_entrypoint_5(Actor *, f32);
extern u8 D_808012C4_chbanjoctrl[];
extern u8 D_808012E4_chbanjoctrl[];
extern u8 D_808012D4_chbanjoctrl[];
extern s32 func_800F54E4();
extern s32 func_800F6DA0(s32);
extern s32 func_800F6E40(s32);
extern s32 func_800F64A4(s32, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFD24(f32 *);
extern void func_800F586C(s32, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern s32 func_800F5410(s32);
extern void func_800F7E3C(s32, s32);
extern f32 mlAbsF(f32);
extern void func_800F7814(s32, f32 *);
extern void func_8008FE68(f32 *);
extern u8 D_808012F4_chbanjoctrl[];
extern s32 func_8001210C(s32);
extern s32 func_800F7058(s32);
extern s32 func_800F6590(s32);
extern s32 func_800F7018(s32);
extern s32 func_800F56AC(s32);
extern s32 func_800F6AA4(s32);
extern s32 func_800F55D0(s32);
extern s32 func_800F6438(s32);
extern f32 func_800F1DF4(void *, void *);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_800C696C(f32 *, f32, f32, s32, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800FEC1C(f32);
void func_80800098_chbanjoctrl();
void func_80800544_chbanjoctrl();
void func_80800684_chbanjoctrl(s32 *actor, f32 cooldown, s32 condition, s32 effect);
int func_808007D8_chbanjoctrl();
s32 func_808011F4_chbanjoctrl();
void func_80800DF8_chbanjoctrl();
void func_808010FC_chbanjoctrl();

int chbanjoctrl_entrypoint_0()
{
    return (int) &D_80801270_chbanjoctrl;
}

// Clears the flag at +0x65 only in map 0x12B (Chilli Billi), sets it elsewhere.
void func_8080000C_chbanjoctrl(f32 actor[3])
{
    s32 unk_0;
    if ((unk_0 = actor[18]) == 3) {
        actor[1] = 0.0f;
        actor[3] = 0.0f;
        if (func_800EA05C(actor, unk_0) == 0x12B) {
            ((u8 *) actor)[0x65] &= ~0x10;
        } else {
            ((u8 *) actor)[0x65] = (((u8 *) actor)[0x65] & 0xFFFFu) | 0x10;
        }
    }
    func_80101FDC(actor, unk_0);
    func_80800098_chbanjoctrl(actor);
}

void func_80800098_chbanjoctrl(actor) Actor *actor;
{
    ((u8 *) actor)[0x70] &= ~0xFE;
    switch (actor->unk70_10) {
        case 2:
            _subaddieDll_entrypoint_1(actor);
            break;
        case 4:
            func_80800684_chbanjoctrl(actor, 3.0f, func_800F69E8, _chbanjoctrl_entrypoint_1);
            break;
        case 5:
            func_80800684_chbanjoctrl(actor, 3.0f, func_800F6968, _chbanjoctrl_entrypoint_2);
    }
}

void func_8080012C_chbanjoctrl(u32 actor)
{
    u16 flags;
    u32 mode;
    flags = *(u16 *) (actor + 0x72);
    mode = (flags & 0xFFFFu) >> 10;
    if (mode != 0xb) {
        return;
    }
    func_808011F4_chbanjoctrl();
}

void func_80800D50_chbanjoctrl();

void func_80800D04_chbanjoctrl();

void func_80800B18_chbanjoctrl();

s32 func_80800ADC_chbanjoctrl();

void func_80800728_chbanjoctrl();

void func_808003F8_chbanjoctrl();

void func_8080025C_chbanjoctrl();

// Dispatches on the zone mode (unk70_10, 1-12).
void func_80800160_chbanjoctrl(Actor *actor)
{
    if (func_80090128()) {
        func_8008FE68((f32 *) actor->actorData);
        switch (actor->unk70_10) {
            case 1:
                break;
            case 2:
                func_8080025C_chbanjoctrl(actor);
                break;
            case 3:
                func_808003F8_chbanjoctrl(actor);
                break;
            case 4:
            case 5:
                func_80800728_chbanjoctrl(actor);
                break;
            case 6:
                func_80800ADC_chbanjoctrl(actor);
                break;
            case 7:
                func_80800B18_chbanjoctrl(actor);
                break;
            case 8:
                func_80800D04_chbanjoctrl(actor);
                break;
            case 9:
                func_80800D50_chbanjoctrl(actor);
                break;
            case 10:
                func_80800DF8_chbanjoctrl(actor);
                break;
            case 11:
                func_808010FC_chbanjoctrl(actor);
                break;
            case 12:
                func_80801088_chbanjoctrl(actor);
                break;
        }
    }
}

// Mode 2: kill plane, voids out the player when the actor is below its height.
void func_8080025C_chbanjoctrl(s32 actor)
{
    // Matching: the do/while(0), the unused locals and the empty statements are needed for the match.
    do {
        if (func_808007D8_chbanjoctrl()) {
            f32 unk_0;
            f32 unk_1;
            ;
            ;
            if (*(f32 *) ((u8 *) actor + 0x1C) < *(f32 *) ((u8 *) actor + 0x8)) {
                func_800904C8(0x91);
            }
        }
    } while (0);
}

s32 func_808002A4_chbanjoctrl(f32 angle)
{
    s32 deg;
    for (deg = 0; deg < 360; deg += 90) {
        if (func_800F2094(deg, angle) < 6.0f)
            return 0;
    }
    for (deg = 45; deg != 405; deg += 90) {
        if (func_800F2094(deg, angle) < 7.0f)
            return 0;
    }
    return 1;
}

// Searches outward from angle for the nearest one that passes func_808002A4.
f32 func_80800360_chbanjoctrl(f32 angle)
{
    // Matching: needed for the match.
    s32 zero = 0;
    f32 step = 1.0f;
    f32 candidate;
    do {
        candidate = angle + step;
        if (func_808002A4_chbanjoctrl(candidate))
            return candidate;
        candidate = angle - step;
        if (func_808002A4_chbanjoctrl(candidate))
            return candidate;
        step += 2.0f;
    } while (zero == 0);
    return angle;
}

// Mode 3: launch the player out of hot water (forced state 0x52).
void func_808003F8_chbanjoctrl(Actor *actor)
{
    s32 player;
    f32 target_x;
    f32 target[2];

    if (((f32 *) actor->actorData)[1] <= actor->position[1] &&
        func_8010CB0C(&D_808012B8_chbanjoctrl, 0xC1C, -140, -250)) {
        player = func_800F54E4();
        if (func_800F6C5C(player) && func_800F6478(player)) {
            target_x = func_80800360_chbanjoctrl(func_8010CD28(actor));
            func_800EFCD8(target, target_x, 3100.0f);
            target[1] = 0.0f;
            if (func_800F7D90(func_800F54E4(), 0x52, target, 1) == 2) {
                if (actor->unk64_20)
                    func_80800544_chbanjoctrl(actor);
                else
                    _chhotwaterpoolbits_entrypoint_5(actor, 1.0f);
            }
        }
    }
}

s32 chbanjoctrl_entrypoint_1(s32 actor)
{
    if (func_800F7B9C(func_800F54E4(), 0x51) == 2) {
        _chhotwaterpoolbits_entrypoint_5(actor, 1.0f);
        return 1;
    }
    return 0;
}

void func_80800544_chbanjoctrl(actor) s32 actor;
{
    s32 state;

    state = func_800F5410(func_800F54E4());

switch (state) {
    case 11:
        func_800C4AF0(actor + 4, &D_808012C4_chbanjoctrl);
        break;
    case 13:
        func_800C4AF0(actor + 4, &D_808012D4_chbanjoctrl);
        break;
    default:
        func_800C4AF0(actor + 4, &D_808012E4_chbanjoctrl);
}

func_800F7620(func_800F54E4(), 0x3F800000, 0x3F000000, 0x3ECCCCCD);
}

s32 chbanjoctrl_entrypoint_2(s32 actor)
{
    s32 player;

    player = func_800F54E4(actor);

if (func_800F798C(player, 0xD, 3)) {
    func_80800544_chbanjoctrl(actor);
    return 1;
}

return 0;

}

void func_80800638_chbanjoctrl(u8 *actor, s32 new_state)
{
    if ((new_state == 2) && ((*(s32(**)())((s8 *) actor + 0x24))() != 0)) {
        *(f32 *) ((s8 *) actor + 0x28) = (f32) *(f32 *) ((s8 *) actor + 0x2C);
    }

(*(s8 *) ((s8 *) (actor) + (0x30))) = (s8) new_state;
}

void func_80800684_chbanjoctrl(s32 *actor, f32 cooldown, s32 condition, s32 effect)
{
    actor[9] = effect;
    actor[20] = condition;
    *(s8 *) ((char *) actor + 0x30) = 1;
    *(f32 *) ((char *) actor + 0x2C) = cooldown;
    *(f32 *) ((char *) actor + 0x28) = 0.0f;
}

int func_808006A8_chbanjoctrl(Actor *actor)
{
    s32 player;

    player = func_800F54E4();
    return !func_800F6DA0(player) && !func_800F6E40(player) && !func_800F64A4(player, 0x8000) &&
           (*(s32(**)(s32))((u8 *) actor + 0x50))(player);
}

// State machine on the byte at +0x30: 1 waits for the condition, 2 counts down the timer at +0x28.
void func_80800728_chbanjoctrl(s32 actor)
{
    // Matching: the copies through the temporaries below are needed for the match.
    s32 actor_tmp;
    char state_raw;
    u8 state;
    s32 actor_copy;
    u8 state_byte;
    actor_copy = actor;
    state_raw = *((u8 *) (actor + 0x30));
    state_byte = state_raw;
    state = state_byte;

switch (state) {
    case 1:
        if (func_808006A8_chbanjoctrl(actor)) {
            func_80800638_chbanjoctrl(actor, 2);
        }
        return;

    case 2:
        func_800D9078(actor + 0x28);
        if (*(f32 *) (actor + 0x28) == 0.0f) {
            if (func_808006A8_chbanjoctrl(actor_copy)) {
                // Matching: needed for the match.
                func_80800638_chbanjoctrl(actor_tmp = actor_copy, 2);
                return;
            }
            func_80800638_chbanjoctrl(actor, 1);
        }
}

}

// Checks the actor position against the zone bounds; zone 0 means no check.
int func_808007D8_chbanjoctrl(actor)
Actor *actor;
{
    u32 zone;
    zone = (u32) (*(s32 *) ((char *) (actor) + 0x70)) >> 25;

if (zone == 0) {
    return 1;
}

return (func_800CC338((f32 *) ((char *) (actor) + 0x18), zone - 1, 0, actor) + 1) != 0;
}

void func_80800824_chbanjoctrl(u8 *actor, s32 player)
{
    f32 offset[3];
    f32 limit_y;
    f32 pos_y;

    func_800F5D70(player, offset, actor);

if ((offset[1] <= 0.0f) &&
    (limit_y = *(f32 *) ((s8 *) actor + 8), pos_y = *(f32 *) ((s8 *) actor + 0x1C),
     (pos_y <= (limit_y + 200.0f)))) {
    if (pos_y <= limit_y) {
        func_8080025C_chbanjoctrl(actor);
        return;
    }
    if (func_800F6720(player) != 0) {
        func_800F7B9C(func_800F54E4(), 0x18);
    }
}

}

void func_808008D8_chbanjoctrl(f32 *vec, f32 dx, f32 dz)
{
    func_800EFA4C(vec, vec[0] + dx, vec[1], vec[2] + dz);
}

// Clamps the player position (actorData) into the player bounds, inset by 1200.
void func_8080091C_chbanjoctrl(Actor *actor, s32 player)
{
    f32 push[3];
    f32 lower[3];
    f32 upper[3];
    s32 moved;
    f32 delta[3];
    moved = 0;
    func_800EFD24(push);
    func_800F586C(func_800F54E4(), lower, upper);
    lower[0] += 1200.0f;
    upper[0] -= 1200.0f;
    upper[1] -= 1200.0f;
    lower[2] += 1200.0f;
    upper[2] -= 1200.0f;

if (upper[1] < ((f32 *) actor->actorData)[1]) {
    ((f32 *) actor->actorData)[1] = upper[1];
    moved = 1;
}

if (((f32 *) actor->actorData)[0] < lower[0]) {
    ((f32 *) actor->actorData)[0] = lower[0];
    func_808008D8_chbanjoctrl(push, 1.0f, 0.0f);
} else if (upper[0] < ((f32 *) actor->actorData)[0]) {

((f32 *) actor->actorData)[0] = upper[0];
func_808008D8_chbanjoctrl(push, -1.0f, 0.0f);
}
if (((f32 *) actor->actorData)[2] < lower[2]) {
    ((f32 *) actor->actorData)[2] = lower[2];
    func_808008D8_chbanjoctrl(push, 0.0f, 1.0f);
} else if (upper[2] < ((f32 *) actor->actorData)[2]) {
    ((f32 *) actor->actorData)[2] = upper[2];
    func_808008D8_chbanjoctrl(push, 0.0f, -1.0f);
}
if (func_800EEF24(push)) {
    moved = 1;

if (func_800F6720(player)) {
    func_800EF368(push, 100.0f);
    func_800EFB24(delta, actor->actorData, push);
    func_800F7700(player, 10, delta);
}

}
if (moved) func_800F8418(player, actor->actorData);
}

s32 func_80800ADC_chbanjoctrl(s32 actor) {
    s32 player;

    player = func_800F54E4(actor);
    func_80800824_chbanjoctrl(actor, player);
    func_8080091C_chbanjoctrl(actor, player);
}

// Mode 7: pushes the camera to the nearest edge of the box around the actor.
void func_80800B18_chbanjoctrl(Actor *this)
{
    f32 radius;
    s32 player;
    f32 target[3];
    f32 pad;
    f32 dx;
    f32 dz;

    radius = this->unk74_7;
    player = func_800F54E4();
    if (func_800F5410(player) == 1) {
        return;
    }
    if (BOX[0] < this->position[0] - radius || this->position[0] + radius <= BOX[0]
        || BOX[1] < this->position[1] - radius || this->position[1] + radius - 100.0f <= BOX[1]
        || BOX[2] < this->position[2] - radius || this->position[2] + radius <= BOX[2]) {
        return;
    }
    func_800F7E3C(player, 0);
    func_800EFA4C(target, BOX[0], this->position[1] + radius, BOX[2]);
    dx = this->position[0] + radius - target[0];
    if (radius < dx) {
        dx -= radius + radius;
    }
    dz = this->position[2] + radius - target[2];
    if (radius < dz) {
        dz -= radius + radius;
    }
    if (mlAbsF(dx) < mlAbsF(dz)) {
        target[0] += dx;
    } else {
        target[2] += dz;
    }
    func_800F7814(player, target);
}

// Matching: the line breaks in this function are needed for the match.
void func_80800D04_chbanjoctrl(f32 *actor)
{
    f32 limit_y;
    do { limit_y = actor[2]; if (limit_y < actor[7]) { actor[7] = limit_y; func_800F8418(func_800F54E4(), actor + 6, actor); } ; } while (0);

}

// Mode 9: forces player state 0x51, then restarts the 3.0 timer in unk58.
void func_80800D50_chbanjoctrl(Actor *actor)
{
    if (func_800D90A4(&actor->unk58) && func_800F56AC(func_800F54E4()) == 0x19 &&
        !func_800F6DA0(func_800F54E4()) && func_800F6C5C(func_800F54E4())) {
        if (func_800F7B9C(func_800F54E4(), 0x51) == 2)
            actor->unk58 = 3.0f;
    }

}

// Mode 10: launches the player (state 0x52) toward the middle of the ground span found near y=-3000.
void func_80800DF8_chbanjoctrl(actor) Actor *actor;
{
    f32 min_dist;
    f32 pos[3];
    f32 distance;
    f32 max_dist;
    f32 yaw;
    s32 player;
    s32 offset;

if (!func_8001210C(4)) {
    return;
}

player = func_800F54E4();

if (func_800F7058(player) == 2) {
    return;
}

if (func_800F6590(player) || func_800F7018(player) || func_800F6DA0(player) || func_800F6E40(player)) {
    return;
}

if (func_800F56AC(player) != 0x14) {
    return;
}

if (func_800F6AA4(player) || func_800F55D0(player)) {
    return;
}

if (!func_800F6478(player) || !func_800F6438(player) || !func_800F6C5C(player)) {
    return;
}

max_dist = min_dist = 0.0f;
yaw = func_800F1DF4(D_808012F4_chbanjoctrl, actor->actorData);
for (offset = 0; offset != 600; offset += 100) {
    distance = offset + 3200.0f;
    func_800EEB9C(pos, yaw, distance);
    pos[1] = -3000.0f;

if (func_800C696C(pos, 100.0f, -100.0f, 0, &pos[1])) {
    if (-3020.0f < pos[1] && pos[1] < -2980.0f) {
        max_dist = distance;
        if (min_dist == 0.0f) {
            min_dist = distance;
        }
    }
}

}
func_800EEB9C(pos, yaw, (min_dist + max_dist) * 0.5f);
pos[1] = -3000.0f;
func_800F7D90(func_800F54E4(), 0x52, pos, 1);
}

// Ends the track 0x4A music effect and clears its flag.
void func_8080102C_chbanjoctrl(actor) Actor *actor;
{
    if (actor->unk64_20) {
        func_800FECB8(3);
        func_800FCAE0(0x4A, 0, 0x7D0);
        func_800FCA90(0x4A);
        *(u8 *) ((u8 *) actor + 0x65) &= 0xFFEF;
    }
}

int func_80801088_chbanjoctrl(Actor *actor)
{
    extern void func_800F4F34(s32, f32 *, f32, f32);
    s32 player;

    player = func_800F54E4();
    if (func_800F6720(player)) {
        func_800F4F34(player, actor->position, 0.0f, (f32) actor->unk74_7);

}
}

// Mode 11: height-driven crossfade of music track 0x4A.
void func_808010FC_chbanjoctrl(actor) Actor *actor;
{
    f32 player_pos[3];
    f32 blend;

    func_8008FE68(player_pos);
    if (actor->position[1] < player_pos[1]) {
        if (!actor->unk64_20) {
            func_800FEC60(3);
            actor->unk64_20 = 1;
        }

blend = func_800F10B4(player_pos[1] - actor->position[1], 0.0f, 2000.0f, 1.0f, 0.0f);
func_800FEC1C(blend);

if (!func_800FCCD4(0x4A)) {
    func_800FC6B0(0x4A);
}

func_800FCAE0(0x4A, (s32) ((1.0f - blend) * 20000.0f), 2000);
}
else
{
    func_8080102C_chbanjoctrl(actor);
}
}

s32 func_808011F4_chbanjoctrl(void)
{
    func_8080102C_chbanjoctrl();
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM). Its tables hold pointers
// to functions of this file, and IDO's assembler schedules some of them differently unless the tables
// are in the same unit. Declared to match the object: D_80801270_chbanjoctrl as int[], D_808012B8_chbanjoctrl as s32[].
extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
int D_80801270_chbanjoctrl[18] = {0xB2014D,
                                  0xE,
                                  0x0,
                                  (u32) func_80800160_chbanjoctrl,
                                  (u32) func_80105834,
                                  (u32) func_8010A730,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x4,
                                  (u32) func_8080012C_chbanjoctrl,
                                  0x0,
                                  0x0,
                                  (u32) func_8080000C_chbanjoctrl,
                                  (u32) func_80107C2C,
                                  -0x7FFFF9FE,
                                  0x0,
                                  0x0};
s32 D_808012B8_chbanjoctrl[3] = {0x0, 0x0, 0x0};
u8 D_808012C4_chbanjoctrl[16] = {0x0, 0x13, 0x5, 0x93, 0x0, 0xD, 0x0, 0xF3,
                                 0x1, 0xC,  0x0, 0x14, 0x0, 0x0, 0x0, 0x0};
u8 D_808012D4_chbanjoctrl[16] = {0x0, 0x13, 0x5, 0x10, 0x0, 0xD, 0x0, 0xF3,
                                 0x1, 0xC,  0x0, 0x14, 0x0, 0x0, 0x0, 0x0};
u8 D_808012E4_chbanjoctrl[16] = {0x0, 0x13, 0x4, 0x94, 0x0, 0x18, 0x0, 0xD,
                                 0x1, 0x2E, 0x1, 0x38, 0x0, 0x14, 0x0, 0x0};
u8 D_808012F4_chbanjoctrl[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
