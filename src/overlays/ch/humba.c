// Humba Wumba in her wigwam (one actor for all ten wigwam maps): dialog, Glowbo payment, and the
// magic pool where the player transforms or turns back, with splash and sparkle effects.
#include "common.h"

extern s32 func_800EA05C(void);
extern void func_8008F8B0();
extern void func_8008F904();
extern void func_8008F938();
extern void func_8008F8D8();
extern void func_8008F990();
extern void func_800EE7F8();
extern s32 func_800F54E4(void);
extern void _capod_entrypoint_3(int);
extern int func_800DA298(int);
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct {
    s32 f0;
    s32 f4;
    u8 pad[0x6C];
    u8 pad74 : 1;
    u8 flag : 1;
    u8 rest : 6;
} FarmerState;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
extern s32 D_80802648_chhumba[];
extern s16 D_8080266E_chhumba[];
extern void func_8010D5DC(void);
extern void func_8008F9F8(f32 *, f32);
extern void func_8010D254(f32 *);
extern void func_800F1EA4(f32 *, f32 *);
extern f32 func_800F1F38(f32, f32, f32);
extern void func_800EFCD8(f32 *, f32, f32);
extern s32 func_800F20BC(f32, f32, f32);
extern f32 D_80802694_chhumba[];
extern void func_8008FB10(f32 *, f32, f32, f32);
extern f32 D_8080272C_chhumba[][3];
extern int D_80802738_chhumba[];
extern void *D_80802780_chhumba;
extern s32 D_80802684_chhumba[];
extern Actor *func_801084B0(s32, Actor **);
extern u8 *func_80103CB8(Actor *, s32);
extern s32 _gcdialogcamera_entrypoint_3(void *, f32);
typedef struct {
    u8 pad[0x17];
    u8 rest : 7;
    u8 flag : 1;
} HumbaBits17;
typedef union {
    u32 local_0;
    s16 local_1[2];
    s32 s;
} Mass64HumbaEvent;
extern s32 func_800F0064(f32 *, f32, f32 *);
extern s32 D_808026A0_chhumba[];
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern u8 D_80802590_chhumba[];
extern Vec3f D_808026F0_chhumba;
extern void func_800EF334(f32 *, f32);
extern void func_8008FE68(f32 *);
extern void func_800907C0(f32 *);
extern void func_8008FF40(f32 *);
extern void func_800906DC(f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 D_808026FC_chhumba[][3];
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800F7F50(s32, f32 *, f32 *, f32, s32, s32);
extern f32 func_800D8FF8(void);
extern s32 func_800902E4(f32 *, f32, s32, Actor **);
void func_80800E44_chhumba();
void func_80801DB0_chhumba();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_808015DC_chhumba(),
    func_808021F4_chhumba();

// Matching: the "| 0" is needed for the match.
int func_80800000_chhumba(s32 actor[3], s32 unk_0)
{
    _capod_entrypoint_2(actor[0], 9, unk_0 | 0);
}

void func_80800028_chhumba(Actor *actor, s32 unk_0, s32 unk_1)
{
    switch (actor->unk74_7) {
        case 0:
            func_80800000_chhumba(actor, 0);
        case 1:
        case 3:
            _capod_entrypoint_8(1);
            actor->unk74_7 = 2;
            _gcdialogcamera_entrypoint_6(actor->unk0);
            _gcdialogcamera_entrypoint_8();
            _capod_entrypoint_12(0);
        case 2:
            _capod_entrypoint_7(unk_0, unk_1);
    }
}

void func_808000D4_chhumba(Actor *actor, s32 unk_0, s32 unk_1, Unk80132ED0 *unk_2)
{
    switch (actor->unk74_7) {
        case 0:
            func_80800000_chhumba(actor, unk_1);
        case 1:
        case 2:
            actor->unk74_7 = 3;
        case 3:
            _capod_entrypoint_20(unk_2, unk_0, unk_1);
    }
}

void func_8080015C_chhumba(Actor *actor, s32 unk_0, s32 unk_1, Unk80132ED0 *unk_2)
{
    switch (actor->unk74_7) {
        case 0:
            func_80800000_chhumba(actor, unk_1);
        case 2:
        case 3:
            actor->unk74_7 = 1;
        case 1:
            _capod_entrypoint_6(unk_2, unk_0, unk_1);
    }
}

void func_808001E4_chhumba(void *actor)
{
    if (func_800DA298(0x9C7) != 0) {
        if (((u32) *(u16 *) ((char *) actor + 0x76) >> 7) != 0) {
            _capod_entrypoint_3(0);
            *(u16 *) ((char *) actor + 0x76) = *(u16 *) ((char *) actor + 0x76) & 0x7F;
        }
    }
}

void func_80800238_chhumba(u8 *actor, f32 *pos)
{
    func_800EFA4C(pos, 0.0f, *(f32 *) (actor + 0x38) * 5.0f * -50.0f, 0.0f);
}

int func_80800294_chhumba(s32 actor, s32 unk_0)
{
    if ((unk_0 != 0) && func_800DA298(0x9C8)) {
        func_800904C8(0x8D);
    }
    if (func_800EA05C() != 0x122) {
        if (unk_0 != 0) {
            func_80090734(1, actor + 4);
            return;
        }
        if (func_800DA298(0x9C8) != 0) {
            func_80090708(0);
        }
    } else {
        if (func_800DA298(0x9C8) != 0) {
            func_80090658(unk_0);
        }
    }
}

void func_80800338_chhumba(FarmerState *actor, s32 dialog_id, s32 flags)
{
    flags |= 4;
    _subaddiedialog_entrypoint_11(actor->f0, dialog_id, flags, &actor->f4, 0x40);
    actor->flag = 1;
}

// Returns the transformation id for this wigwam.
int func_80800384_chhumba(Actor *actor)
{
    switch (func_800EA05C()) {
        case 0x122:
            return 0x13;

        default:
            return D_80802648_chhumba[(*(s32 *) ((char *) actor + 0x6C) & 0x1FF)];
    }
}

// Returns the dialog id for this wigwam.
s32 func_808003CC_chhumba(u8 *actor)
{
    if (func_800EA05C() == 0x122) {
        return 0x11AA;
    }
    return D_8080266E_chhumba[*(s32 *) (actor + 0x6C) & 0x1FF];
}

// Returns a flag id per wigwam (0x346 + index).
int func_80800414_chhumba(Actor *actor)
{
    s32 map_id;
    map_id = func_800EA05C();
    if (map_id == 0x122) {
        return 0x346;
    }
    return (*(s32 *) ((char *) actor + 0x6C) & 0x1FF) + 0x346;
}

void func_80801F74_chhumba();

// Actor event handler: event_id selects the case, event_data carries its arguments.
s32 func_80800450_chhumba(Actor *actor, s32 event_id, Mass64HumbaEvent event_data)
{
    Actor *spawned;
    f32 pool_center[3];
    u8 *unk_0;

    switch (event_id) {
        case 0x49:
            func_80801F74_chhumba(actor);
            break;
        case 0xA1:
            switch (actor->unk70_10) {
                case 10:
                    func_80800E44_chhumba(actor, 11);
                    break;
                case 15:
                    func_80800E44_chhumba(actor, 16);
            }
            break;
        case 0x3D:
            func_80800238_chhumba(actor, pool_center);
            spawned = func_801084B0(0x29F, &actor);
            func_800EE7F8((f32 *) spawned->actorData, pool_center);
            func_8010D254(spawned->position);
            spawned->unk74_30 = 1;
            actor->unk3C = spawned->unk0;
            func_80800E44_chhumba(actor, 6);
            break;
        case 0x2E:
            func_80801DB0_chhumba(actor, event_data.local_1[0], event_data.local_1[1]);
            break;
        case 0x2F:
            if (event_data.local_1[1] == 1) {
                func_80090708(0);
                func_80090708(1);
            }
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80802684_chhumba, actor->scale);
            break;
        case 0x57:
            if (_gcdialogcamera_entrypoint_0(event_data.s & 0xFFFF,
                                             (event_data.local_0 & 0xFFFF0000) >> 16)) {
                if (actor->unk74_7 != 2) {
                    func_80800028_chhumba(actor, 2, 1);
                }
                return 2;
            }
            return 1;
        case 0x32:
            switch (actor->unk70_10) {
                case 17:
                    func_80800338_chhumba(actor, 0x11AF, 0xF);
                    break;
                case 18:
                    func_80800E44_chhumba(actor, 18);
                    break;
                default:
                    func_800904C8(0x8D);
                    if (actor->unk74_29) {
                        func_80800338_chhumba(actor, 0x11BD, 0xF);
                    } else {
                        func_80800338_chhumba(actor, 0x11A4, 0xF);
                    }
            }
            break;
        case 0x1F:
            func_801015D0(actor);
            unk_0 = func_80103CB8(actor, func_801039E4(actor->unk0));
            ((HumbaBits17 *) unk_0)->flag = 1;
            func_800DF744(3, 0);
            func_800DF744(5, 0);
            break;
        default:
            return 0;
    }
    return 1;
}

// Maps the current map id to the wigwam index.
s32 func_8080071C_chhumba(actor)
s32 actor;
{
    s32 map_id;

    map_id = func_800EA05C();

switch (map_id) {
    case 0xB6:
        return 1;
    case 0xD5:
        return 3;
    case 0xE9:
        return 2;
    case 0x11E:
    case 0x122:
        return 5;
    case 0x120:
        return 4;
    case 0x11F:
        return 6;
    case 0x135:
        return 7;
    case 0x140:
        return 8;
    case 0x157:
        return 9;
    default:
        return 0;
}

}

// Glowbo price of a transformation.
s32 func_808007EC_chhumba(s32 actor)
{
    return 1;
}

// Sets the wigwam's paid flag and takes the glowbo(s) as payment.
void func_808007F8_chhumba(Actor *actor)
{
    func_800DA544(actor->unk6C_0 + 0xD5);

if (actor->unk74_29) {
    func_800D175C(0x54, -func_808007EC_chhumba(actor));
} else {

func_800D175C(0x48, -func_808007EC_chhumba(actor));
}
actor->unk64_20 = 1;
}

// Returns whether this wigwam is already paid.
int func_80800878_chhumba(Actor *actor)
{
    return func_800DA298(((*(s32 *) ((char *) actor + 0x6C)) & 0x1FF) + 0xD5);
}

s32 func_808008A0_chhumba(Actor *actor)
{
    f32 pool_center[3];
    Actor *target;
    f32 scale;

    target = func_80106790(actor->unk3C);
    func_80800238_chhumba(actor, pool_center);
    scale = actor->scale;
    if (target->position[1] < -202.5f * scale &&
        func_800F0064(target->position, scale * 1550.0f, pool_center)) {
        return 1;
    }
    return 0;
}

// Fails unless the player is inside the scaled x/z bounds.
s32 func_80800934_chhumba(Actor *actor, s32 unk_0)
{
    f32 x_max;
    f32 x_min;
    f32 z_min;
    f32 z_max;
    f32 player_pos[3];
    x_max = actor->scale * 500.0f;
    x_min = actor->scale * -500.0f;
    z_min = actor->scale * 1900.0f;
    z_max = actor->scale * 2950.0f;
    func_8010D254(player_pos);
    if (player_pos[0] < x_min || player_pos[0] > x_max)
        return 0;
    if (player_pos[2] < z_min || player_pos[2] > z_max)
        return 0;
    if (!func_8008FA60(unk_0, 6))
        return 0;
    if (func_80090080()) {
        if (func_80016B30(0, 1))
            return 1;
        func_800F5FE0(func_800F54E4());
    }
    return 0;
}

s32 func_80800A50_chhumba(actor)
Actor *actor;
{
    f32 pool_center[3];
    f32 player_pos[3];

    func_80800238_chhumba(actor, pool_center);
    pool_center[1] = 0.0f;
    func_8010D254(player_pos);
    if (!func_8010C9FC(pool_center, (s32) (actor->scale * 1550.0f), (s32) (actor->scale * -202.5f),
                       (s32) (actor->scale * -1237.5f))) {
        return 0;
    }
    if (!func_800F71D4(func_800F54E4())) {
        return 0;
    }
    if (func_800EA05C() == 0x120 && -100.0f < player_pos[1]) {
        return 0;
    }
    return 1;
}

void func_80800B40_chhumba(Actor *actor)
{
    func_8080015C_chhumba(actor, 0, 0x60, 0);
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(func_8010D5DC, actor->unk0);
    func_8008F9F8((f32 *) &actor->actorData[4], 200.0f);
}

void func_80800BA8_chhumba(Actor *actor, f32 *out_pos)
{
    f32 unk_0;
    f32 player_pos[3];
    func_8010D254(player_pos);
    func_800F1EA4(player_pos, &unk_0);
    func_800EFCD8(out_pos, func_800F1F38(unk_0, 0.0f, 10.0f), actor->scale * 2000.0f);
    out_pos[1] = player_pos[1];
}

s32 func_80800C20_chhumba(s32 actor)
{
    f32 unk_0;
    f32 player_pos[3];
    func_8010D254(player_pos);
    func_800F1EA4(player_pos, &unk_0);
    if (func_800F20BC(0.0f, unk_0, 5.0f) == 0) {
        return 1;
    }
    return 0;
}

s32 func_80800C6C_chhumba(f32 actor[3])
{
    f32 pos[3];

    func_80800BA8_chhumba(actor, pos);
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *(s32 *) actor);
    func_8008F990(pos, 0x43960000);
}

void func_80800CC8_chhumba(Actor *actor)
{
    func_8008FB10(D_80802694_chhumba, actor->scale * 1600.0f, actor->scale * 72.0f,
                  actor->scale * 350.0f);
}

s32 func_80800D2C_chhumba(s32 actor)
{
    if (func_800DA9E4(0xE2, 1) == 0) {
        func_80800338_chhumba(actor, 0x11B5, 0xF);
        return 1;
    }
    return 0;
}

void func_80800D74_chhumba(Actor *actor)
{
    s32 unk_0;
    s32 unk_1;
    f32 pos[3];

    if (func_800DC0C0() < 0.1f) {
        unk_0 = func_800DC128(1, 3);
        unk_1 = func_800B53A4(unk_0);
        func_800EEB9C(pos, func_800DC178(0.0f, 360.0f),
                      func_800DC178(0.0f, 1000.0f) * actor->scale);
        pos[1] = -50.0f;
        func_800BABB8(unk_1, pos, NULL, 1.0f, D_808026A0_chhumba);
        func_800BA22C(unk_1, unk_0);
    }
}

// State machine transition: runs the exit actions of the old state and the entry actions of the new one.
void func_80800E44_chhumba(actor, state) Actor *actor;
s32 state;
{
    f32 splash_pos[3];
    Actor *target;
    f32 pool_center[3];

    switch (actor->unk70_10) {
        case 2:
            break;
        case 3:
            func_80800294_chhumba(actor, 0);
            break;
        case 5:
        case 6:
            func_80800238_chhumba(actor, splash_pos);
            func_80090658(0);
            _fxsplash_entrypoint_1(splash_pos);
            _fxsplash25d_entrypoint_0(splash_pos);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80802590_chhumba);
            func_808007F8_chhumba(actor);
            func_800FC660(0xE);
            func_80800338_chhumba(actor, 0x11B4, 0xF);
    }
    func_80101FDC(actor, state);
    switch (actor->unk70_10) {
        case 2:
            func_80800B40_chhumba(actor);
            return;
        case 3:
            func_80800028_chhumba(actor, 3, 1);
            func_80800294_chhumba(actor, 1);
            return;

case 18:
    if (func_80800C20_chhumba(actor)) {
        func_80800C6C_chhumba(actor);
        return;
    }

func_80800E44_chhumba(actor, 4);
return;
case 4:
    func_80090658(1);
    return;
case 5:
    func_80800238_chhumba(actor, pool_center);
    func_80090768(pool_center);
    actor->unk3C = (Unk80132ED0 *) func_8008FDEC();
    target = (Actor *) func_80106790(actor->unk3C);
    func_800EE7F8((f32 *) target->actorData, pool_center);
    target->unk74_30 = 1;
    func_808000D4_chhumba(actor, 0xE, 9, actor->unk3C);
    return;
case 6:
    func_808000D4_chhumba(actor, 0xE, 9, actor->unk3C);
    return;
case 8:
    func_80090658(1);
    func_8080015C_chhumba(actor, 2, 0x60, 0);
    return;
case 9:
    actor->unk58 = 4.0f;
    func_800FC6B0(0xC);

if (actor->unk74_29 && !func_8009EA2C()) {
    func_8009EAAC(1);
    func_800907EC(func_8008FD48());
    return;
}

func_800907EC(func_80800384_chhumba(actor));
return;
case 11:
    func_80090658(0);

if (!func_800DA9E4(func_80800414_chhumba(actor), 1)) {
    if (actor->unk74_29) {
        func_80090708(2);
        func_80800338_chhumba(actor, func_808003CC_chhumba(actor), 3);
        return;
    }
    func_80800338_chhumba(actor, func_808003CC_chhumba(actor), 0xB);
    return;
}

if (!func_80800D2C_chhumba(actor)) {
    func_808001E4_chhumba(actor);
    func_80800E44_chhumba(actor, 0xC);
}

break;
case 13:
    func_80090658(1);
    func_8080015C_chhumba(actor, 5, 0x60, 0);
    return;
case 14:
    actor->unk58 = 4.0f;
    func_800FC6B0(0xC);

if (actor->unk74_29 && func_8009EA2C()) {
    func_8009EAAC(0);
    func_800907EC(func_8008FD48());
    return;
}

func_800907EC(1);
return;
case 16:
    func_80090658(0);

if (!func_800DA9E4(0x1D1, 1)) {
    func_80800338_chhumba(actor, 0x11B6, 0xF);
    return;
}

func_808001E4_chhumba(actor);
func_80800E44_chhumba(actor, 7);
return;

case 17:
    if (!func_800DA9E4(0x505, 1)) {
        func_80800B40_chhumba(actor);
    }

}
}

void func_80801260_chhumba(Actor *actor)
{
    Vec3f target = D_808026F0_chhumba;
    s32 i;
    f32 vec[3];

    func_800EF334(target.f, actor->scale);
    func_8008FE68(vec);
    for (i = 0; i < 3; i++) {
        vec[i] += (target.f[i] - vec[i]) * 0.05f;
    }
    func_800907C0(vec);
    func_8008FF40(vec);
    vec[1] += func_800F1DCC(180.0f, vec[1]) * 0.05f;
    vec[0] += func_800F1DCC(0.0f, vec[0]) * 0.05f;
    vec[2] += func_800F1DCC(0.0f, vec[2]) * 0.05f;
    func_800906DC(vec);
}

void func_8080138C_chhumba(Actor *actor)
{
    s32 form;

    if (func_80800A50_chhumba(actor) == 0 || func_80090270() != 0) {
        return;
    }
    form = func_8008FD48();
    if ((form == 1) && ((func_8009EA2C() == 0) || !actor->unk74_29)) {
        func_80800E44_chhumba(actor, 8);
    } else if ((func_80800384_chhumba(actor) == form) ||
               ((func_8009EA2C() != 0) && actor->unk74_29)) {
        func_80800E44_chhumba(actor, 0xD);
    }
}

// Pool push-out: pushes the player away from the cylinders listed in D_808026FC_chhumba.
void func_8080144C_chhumba(f32 scale)
{
    f32(*point)[3];
    f32 bottom[3];
    f32 player_pos[3];
    f32 top[3];
    f32 radius;
    f32 delta[3];
    f32 height;
    f32 max_dist_sq;

    func_8010D254(player_pos);
    radius = (scale <= 1.0f) ? 60.0f : 100.0f;
    height = 610.0f * scale;
    max_dist_sq = (radius + 25.0f) * (radius + 25.0f);
    point = D_808026FC_chhumba;
    do {
        func_800EFA20(bottom, *point, scale);
        func_800EE7F8(top, bottom);
        top[1] = height;
        func_800EFB24(delta, bottom, player_pos);

if (delta[0] * delta[0] + delta[2] * delta[2] < max_dist_sq && bottom[1] < player_pos[1] &&
    player_pos[1] <= top[1]) {
    func_800F7F50(func_800F54E4(), bottom, top, radius, 2, 1);
}

point++;
}
while (point != D_8080272C_chhumba)
    ;
}

void func_808015DC_chhumba(actor) Actor *actor;
{
    extern void _chglowbo_entrypoint_4(void);

    f32 player_pos[3];
    f32 pos[3];
    s32 actor_id;
    s32 price;
    s32 glowbos;

    _suexpression_entrypoint_10(func_80100094(actor, 1), *(s32 *) ((char *) actor + 0), 0);

    func_8080144C_chhumba(*(f32 *) ((char *) actor + 0x38) * 5.0f);

    if (func_800C0638()) {
        *(f32 *) ((char *) actor + 0x24) = 1.5f;
    } else if (*(f32 *) ((char *) actor + 0x24) > 0.0f) {
        *(f32 *) ((char *) actor + 0x24) -= func_800D8FF8();
    }

    if (func_80800878_chhumba(actor)) {
        func_80800D74_chhumba(actor);

}
else if (*(f32 *) ((char *) actor + 0x24) <= 0.0f)
{
    if (actor->unk74_29) {
        func_800D1824(0x54);
    } else {

func_800D1824(0x48);
}
}

func_8008FB10((char *) actor + 4, *(f32 *) ((char *) actor + 0x38) * 1350.0f,
              *(f32 *) ((char *) actor + 0x38) * 72.0f,
              *(f32 *) ((char *) actor + 0x38) * 350.0f);

if (func_80090178(0x10000)) {
    return;
}

switch (actor->unk70_10) {
    case 1:
        if (func_800EA05C() == 0x120) {
            func_8010D254(player_pos);

if (player_pos[1] > -30.0f) {
    if (func_80090178(0x6C8E3)) {
        if (_subaddiedialog_entrypoint_6(
                (char *) actor + 4, (s32) *(f32 *) ((char *) actor + 0x48), 0x15E, 0x32, 6)) {
            func_80800E44_chhumba(actor, 3);
        }
    }
}

if (func_80800934_chhumba(actor, 0x6C8E3)) {
    func_80800E44_chhumba(actor, 3);
}

}
else
{
    if (func_80090178(0x6C8E3)) {
        if (_subaddiedialog_entrypoint_6(
                (char *) actor + 4, (s32) *(f32 *) ((char *) actor + 0x48), 0x15E, 0x32, 0)) {
            func_80800E44_chhumba(actor, 3);
        }
    }

if (func_80800934_chhumba(actor, 0x6C8E3)) {
    func_80800E44_chhumba(actor, 3);
}

}
break;

case 3:
    if (!actor->unk74_30) {
        if (actor->unk74_29) {
            glowbos = func_800D1A04(0x54);
            price = func_808007EC_chhumba(actor);
            if (glowbos >= price) {
                func_80800338_chhumba(actor, 0x11BE, 0x4E);
            } else {
                func_80800338_chhumba(actor, 0x11BF, 0xF);
            }
        } else {

glowbos = func_800D1A04(0x48);
price = func_808007EC_chhumba(actor);

if (glowbos >= price) {
    func_80800338_chhumba(actor, 0x11B0, 0x4E);
} else {

func_80800338_chhumba(actor, 0x11B3, 0xF);

}
}
}
break;

case 18:
    func_80800BA8_chhumba(actor, pos);
    func_8008F964(pos);
    func_80800CC8_chhumba(actor);
    break;

case 4:
    if (func_800EA05C() == 0x120) {
        func_80108B04(actor, 0);
    } else {
        if (actor->unk74_29) {
            actor_id = 0x523;
        } else {
            actor_id = 0x29F;
        }

        if (func_800902E4((char *) actor + 4, 2500.0f, actor_id, &actor)) {
            if (func_8008FE14() == actor_id) {
                if (func_80090818()) {
                    func_80800E44_chhumba(actor, 5);
                }

}
}
}
break;

case 5:
case 6:
    if (func_808008A0_chhumba(actor)) {
        func_80800E44_chhumba(actor, 7);
    }
    break;

case 7:
    if ((func_80090178(0x6C8E3) &&
         _subaddiedialog_entrypoint_6((char *) actor + 4,
                                      (s32) *(f32 *) ((char *) actor + 0x48), 0x15E, 0x32, 6)) ||
        func_80800934_chhumba(actor, 0x6C8E3)) {
        func_80800338_chhumba(actor, 0x11B8, 0xF);
    } else {
        func_8080138C_chhumba(actor);
    }
    break;

case 8:
    func_80800E44_chhumba(actor, 9);
    break;

case 9:
    if (*(f32 *) ((char *) actor + 0x58) > 0.0f) {
        *(f32 *) ((char *) actor + 0x58) -= func_800D8FF8();

        if (actor->unk64_20 && *(f32 *) ((char *) actor + 0x58) < 1.5f) {
            _chbaddiesetup_entrypoint_0(_chglowbo_entrypoint_4);

            actor->unk64_20 = 0;
        }
    } else if (func_800903D0((char *) actor + 0x28)) {
        func_800904F4(0x89, *(s32 *) ((char *) actor + 0));

        func_80800E44_chhumba(actor, 0xA);
    }

    func_80801260_chhumba(actor);
    break;

case 12:
    if ((func_80090178(0x6C8E3) &&
         _subaddiedialog_entrypoint_6((char *) actor + 4,
                                      (s32) *(f32 *) ((char *) actor + 0x48), 0x15E, 0x32, 0)) ||
        func_80800934_chhumba(actor, 0x6C8E3)) {
        func_80800338_chhumba(actor, 0x11B9, 0xF);
    } else {
        func_8080138C_chhumba(actor);
    }
    break;

case 13:
    func_80800E44_chhumba(actor, 0xE);
    break;

case 14:
    if (*(f32 *) ((char *) actor + 0x58) > 0.0f) {
        *(f32 *) ((char *) actor + 0x58) -= func_800D8FF8();
    } else if (func_800903D0((char *) actor + 0x28)) {
        func_800904F4(0x89, *(s32 *) ((char *) actor + 0));

        func_80800E44_chhumba(actor, 0xF);
    }

    func_80801260_chhumba(actor);
    break;

case 17:
    if (_subaddiedialog_entrypoint_6((char *) actor + 4,
                                     (s32) *(f32 *) ((char *) actor + 0x48), 0x15E, 0x32, 0) ||
        func_80800934_chhumba(actor, 0x600)) {
        func_80800338_chhumba(actor, 0x11BC, 0xF);
    } else if (!actor->unk64_19) {
        if (func_80800A50_chhumba(actor)) {
            actor->unk64_19 = 1;

            func_80800338_chhumba(actor, 0x11BA, 0xF);
        }
    }
    break;

case 19:
    if (_subaddiedialog_entrypoint_6((char *) actor + 4,
                                     (s32) *(f32 *) ((char *) actor + 0x48), 0x15E, 0x32, 0) ||
        func_80800934_chhumba(actor, 0x600)) {
        func_80800338_chhumba(actor, func_80090178(0x200) ? 0x121C : 0x121D, 0xF);
    } else if (!actor->unk64_19) {
        if (func_80800A50_chhumba(actor)) {
            actor->unk64_19 = 1;

            func_80800338_chhumba(actor, 0x11BB, 0xF);
        }
    }
    }
    }

    // Dialog end handler: dialog_id is the finished line, answer the player's choice.
    void func_80801DB0_chhumba(actor, dialog_id, answer) Actor *actor;
    u32 dialog_id;
    s32 answer;
    {
        *((u8 *) (((char *) actor) + 0x74)) =
            (u8) ((*((u8 *) (((char *) actor) + 0x74))) & 0xFFBF);
        switch (dialog_id) {
            case 0x11AF:
                func_808001E4_chhumba(actor);
                return;

            case 0x11A4:

            case 0x11BD:
                func_80800E44_chhumba(actor, 3);
                return;

            case 0x11A5:

            case 0x11A6:

            case 0x11A7:

            case 0x11A8:

            case 0x11A9:

            case 0x11AA:

            case 0x11AB:

            case 0x11AC:

            case 0x11AD:

            case 0x11AE:

            case 0x11B7:
                if (func_80800D2C_chhumba(actor) == 0) {
                    func_800C0850();
                    func_808001E4_chhumba(actor);
                    func_80800E44_chhumba(actor, 0xC);
                }
                if (dialog_id == 0x11B7) {
                    func_80090708(0);
                }

                return;

            case 0x11B0:

            case 0x11BE:
                if (answer != 0) {
                    func_80800338_chhumba(actor, 0x11B1, 0xF);
                    return;
                }
                func_80800338_chhumba(actor, 0x11B2, 0xF);
                return;

            case 0x11B2:
                func_808001E4_chhumba(actor);
                func_800EE7F8((s32 *) (((char *) actor) + 0x18),
                              (s32 *) (((char *) actor) + 0x4));
                func_80800E44_chhumba(actor, 1);
                return;

            case 0x11B1:
                if (func_80800C20_chhumba(actor) != 0) {
                    func_808001E4_chhumba(actor);
                }
                func_808000D4_chhumba(actor, 0xE, 0x40, 0);
                func_80800E44_chhumba(actor, 0x12);
                return;

            case 0x11B3:

            case 0x11BF:
                func_808001E4_chhumba(actor);
                func_80800E44_chhumba(actor, 1);
                return;

            case 0x11B5:
                func_808001E4_chhumba(actor);
                func_80800E44_chhumba(actor, 0xC);
                return;

            case 0x11B4:
                func_808001E4_chhumba(actor);
                return;

            case 0x11B6:
                func_808001E4_chhumba(actor);
                func_80800E44_chhumba(actor, 7);
        }
    }

    // Actor init: picks the wigwam index and the starting state.
    void func_80801F74_chhumba(Actor *actor)
    {
        extern void _suexpression_entrypoint_12(void *, f32, f32);
        s32 unk_0;
        s32 map_id;
        unk_0 = _gccubesearch_entrypoint_1(0x226, actor->position);
        map_id = func_800EA05C();
        actor->unk74_7 = 0;
        if (!unk_0) {
            func_800FFAB0(actor);
            return;
        }
        _gspropctrl_entrypoint_11(unk_0, (u8 *) actor + 0x28);
        actor->unk6C_0 = func_8080071C_chhumba(actor);
        _suexpression_entrypoint_7(actor, 1, 0x40);
        _suexpression_entrypoint_12((void *) func_80100094(actor, 1), 0.0f, 0.0f);
        switch (map_id) {
            case 0x135:
                func_800BF744(1, 1);
                break;
            case 0x120:
                func_800BF744(2, 1);
                break;
            case 0x157:
                actor->unk74_29 = 1;
        }
        if (map_id != 0x135) {
            func_80108474(0x381, D_8080272C_chhumba, 0);
        }
        if (_glcutDll_entrypoint_20()) {
            func_80800E44_chhumba(actor, 0x14);
            return;
        }
        switch (func_8008FD70()) {
            case 0x1000:
                func_80800E44_chhumba(actor, 0x11);
                return;
            case 0x200:
            case 0x400:
                func_80800E44_chhumba(actor, 0x13);
            case 0x10000:
                return;
            default:
                if (actor->unk74_29 && !func_800DA9E4(0x55, 1)) {
                    func_80800E44_chhumba(actor, 2);
                    return;
                }
                if (!actor->unk74_29 && !func_800DA9E4(0x8F, 1)) {
                    func_80800E44_chhumba(actor, 2);
                    return;
                }
                if (func_80800878_chhumba(actor)) {
                    if (func_8008FD48() == 1 && (!func_8009EA2C() || !actor->unk74_29)) {
                        func_80800E44_chhumba(actor, 7);
                        return;
                    }
                    func_80800E44_chhumba(actor, 0xC);
                    return;
                }
                func_80800E44_chhumba(actor, 1);
        }
    }

    void func_808021F4_chhumba(Actor *actor)
    {
        if (func_80100094(actor, 1) != 0) {
            _suexpression_entrypoint_8(actor, 1);
        }
    }
    int chhumba_entrypoint_0()
    {
        return (int) &D_80802738_chhumba;
    }

    // Scale is 2.0 on map 0x122 (big TDL wigwam), 1.0 elsewhere.
    void func_80802234_chhumba(void *actor)
    {
        s32 map_id = func_800EA05C();
        if (map_id == 0x122) {
            *(float *) ((char *) actor + 0x38) = 2.0f;
        } else {
            *(float *) ((char *) actor + 0x38) = 1.0f;
        }
    }

    int chhumba_entrypoint_1()
    {
        return &D_80802780_chhumba;
    }

    // TU-NOTE: The overlay's .data (formerly asm/data/overlays/ch/humba.data.s) is defined in this
    // file. Its tables point to functions of this file, and IDO's assembler schedules some of them
    // differently unless the tables are in the same unit. Values are taken from the ROM.
    // TU-NOTE: D_8080266E_chhumba is a linker symbol (undefined_syms.us.txt) = D_80802648_chhumba + 0x26.
    // TU-NOTE: D_80802684_chhumba is declared s32[] and D_80802738_chhumba int[] to fit the objects
    // (same addresses).
    extern void func_80101870();
    u8 D_80802590_chhumba[20] = {0x0,  0x13, 0x4, 0x9, 0x0, 0xA,  0x1,  0x0,  0x0, 0x16,
                                 0x46, 0x50, 0x0, 0x1, 0x1, 0xF4, 0x13, 0x88, 0x0, 0x0};
    u8 D_808025A4_chhumba[164] = {
        0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,
        0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11,
        0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,
        0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0,
        0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,
        0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10,
        0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41,
        0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,
        0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,
        0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11,
        0x0,  0x0,  0x41, 0x10, 0x0,  0x0,  0x1,  0x11, 0x0,  0x0,  0x41, 0x10, 0x0,  0x0};
    s32 D_80802648_chhumba[15] = {0x1110000,  0x8,        0xF,        0x10,       0xC,
                                  0x12,       0x7,        0x2,        0x6,        0x10,
                                  0x11A511A6, 0x11A811A7, 0x11A911AB, 0x11AC11AD, 0x11B70000};
    s32 D_80802684_chhumba[4] = {0x44960000, 0x44160000, 0x43C80000, 0x44160000};
    f32 D_80802694_chhumba[3] = {0.0f, 0.0f, 0.0f};
    s32 D_808026A0_chhumba[20] = {0x1D09E9,  0x161100,  0x2E00FF, 0x15E,    0x1310167,
                                  0x1C2001B, -0x95012C, 0x70001,  0x150000, 0xCC002B,
                                  0x2800380, 0x22001E,  0x260014, 0x190015, 0xC0,
                                  0x2F0040,  0x400000,  0x19,     0x33,     0x0};
    Vec3f D_808026F0_chhumba = {0.0f, -7.5e+02f, 0.0f};
    f32 D_808026FC_chhumba[4][3] = {321.0f,    -3e+01f, -407.0f, -354.0f,  -3e+01f, -407.0f,
                                    -6.4e+02f, -7e+01f, 245.0f,  6.4e+02f, -7e+01f, 245.0f};
    f32 D_8080272C_chhumba[1][3] = {0.0f, 0.0f, 0.0f};
    int D_80802738_chhumba[18] = {0x20102A1,
                                  0x6750001,
                                  (u32) &D_808025A4_chhumba,
                                  (u32) func_808015DC_chhumba,
                                  (u32) func_80105834,
                                  (u32) func_801018A4,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x8056C,
                                  (u32) func_808021F4_chhumba,
                                  0x0,
                                  0x0,
                                  0x0,
                                  (u32) func_80107C2C,
                                  -0x7FFFFFFE,
                                  (u32) func_80800450_chhumba,
                                  0x0};
    void *D_80802780_chhumba = (void *) 0x01580381;
    static u32 D_80802780_chhumba_rest[19] = {0x8240001,
                                              0x0,
                                              0x0,
                                              (u32) func_80105834,
                                              (u32) func_80101870,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x1C0C,
                                              0x0,
                                              0x0,
                                              0x0,
                                              (u32) func_80802234_chhumba,
                                              (u32) func_80107C2C,
                                              0x80000802,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0};
