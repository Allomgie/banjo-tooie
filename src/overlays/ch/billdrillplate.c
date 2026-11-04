// Bill Drill plates in Grunty Industries (three actor kinds): bolts that pop out when drilled,
// a plate held by four bolts that lifts off once all are drilled, and a cover that explodes.
#include "common.h"
#include "types.h"
#include "macros.h"

extern int D_80801124_chbilldrillplate[];
extern int D_8080116C_chbilldrillplate[];
extern s32 func_800DC298(f32);
typedef union {
    s32 word;
    Unk80132ED0 *marker;
} BillDrillPlateEventPayload;
extern void _subaddiefade_entrypoint_14(void *arg);
extern void _subaddielink_entrypoint_0(void *param_0);
extern void *func_80100094(Actor *, u32);
extern Actor *_subaddiefind_entrypoint_0();
extern Actor *_subaddielink_entrypoint_4(void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern u8 D_80801220_chbilldrillplate[];
extern void func_800EE7F8(f32 *, f32 *);
extern u32 D_808010DC_chbilldrillplate[];
typedef struct {
    u16 unk0;
    u16 unk2;
    u8 pad[16];
} BilldrillPlateEntry;
extern BilldrillPlateEntry D_808010A0_chbilldrillplate[];
extern s32 func_800EA05C(void);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 28;
    u32 bit : 1;
    u32 pad_2 : 3;
} ChBDP;
extern void _chbounce_entrypoint_5();
extern void _subaddiefade_entrypoint_3();
extern void func_80101FDC();
extern s32 D_808011B4_chbilldrillplate[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern void _chbounce_entrypoint_3(f32);
extern u8 D_808011C4_chbilldrillplate[];
extern u8 D_808011D4_chbilldrillplate[];
extern u8 D_808011E0_chbilldrillplate[];
extern u8 D_808011F0_chbilldrillplate[];
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
extern u32 D_80801234_chbilldrillplate[];
extern u32 D_80801244_chbilldrillplate[];
extern void *func_80101080(void);
extern void *func_80106790(void *);
extern void _chexploder_entrypoint_6(void *, f32, f32);
Actor *func_80800978_chbilldrillplate();
u8 *func_80800FCC_chbilldrillplate();
BilldrillPlateEntry *func_80801020_chbilldrillplate();

int *chbilldrillplate_entrypoint_0()
{
    return (int *) D_808010DC_chbilldrillplate;
}

int chbilldrillplate_entrypoint_1()
{
    return (int) &D_80801124_chbilldrillplate;
}

int chbilldrillplate_entrypoint_2()
{
    return &D_8080116C_chbilldrillplate;
}

void func_80800024_chbilldrillplate(Actor *actor)
{
    f32 sign;
    if (func_800DA298(*(u16 *) ((u8 *) func_80800FCC_chbilldrillplate(actor) + 0xC))) {
        func_800FFAB0(actor);
    } else {
        _subaddiefade_entrypoint_14(actor);
        sign = func_800DC298(0.5f) ? -1.0f : 1.0f;
        ((f32 *) actor->actorData)[4] = sign * 200.0f;
    }
}

void func_808002A0_chbilldrillplate();

void func_808000B0_chbilldrillplate(Actor *actor)
{
    switch (actor->unk70_10) {
        case 2:
            if (func_800D90A4((f32 *) ((u8 *) actor + 0x2C))) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 &D_808011B4_chbilldrillplate);
                *(f32 *) ((u8 *) actor + 0x2C) = 0.4f;
            }
            actor->rotation[1] = func_800136E4(actor->rotation[1] + func_800D8FF8() * 600.0f);
            actor->position[1] += func_800D8FF8() * 50.0f;
            if (_subaddieDll_entrypoint_6(actor, 0xB)) {
                _chbounce_entrypoint_3(actor->rotation[1]);
                _chbounce_entrypoint_5(0x1B, actor);
                func_80101FDC(actor, 3);
                func_8010A624(actor);
                func_8010A570(actor);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 &D_808011B4_chbilldrillplate);
                *(f32 *) ((u8 *) actor + 0x30) = 1.2f;
            }
        case 1:
            break;
        case 3:
            actor->rotation[0] = func_800136E4(
                actor->rotation[0] + func_800D8FF8() * *(f32 *) ((u8 *) actor + 0x28));
            if (func_800D9078((f32 *) ((u8 *) actor + 0x30))) {
                func_808002A0_chbilldrillplate(actor);
            }
            if (!((ChBDP *) actor)->bit) {
                _subaddiefade_entrypoint_3(actor);
                func_80101FDC(actor, 4);
                func_80103110(actor, 0);
            }
    }
}

s32 func_80800240_chbilldrillplate(Actor *actor, s32 event, BillDrillPlateEventPayload payload)
{
    switch (event) {
        case 0x3F:
            if (_subaddieDll_entrypoint_5(actor, payload.word)) {
                func_80103110(actor, 1);
                func_80101FDC(actor, 2);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

// Counts bolts still in place; at 3 or 0 left plays the cutscene (sets the flag at 0).
void func_808002A0_chbilldrillplate(Actor *actor)
{
    Actor *bolts[4];
    s32 bolt_count;
    s32 i;
    s32 remaining;
    u16 *entry;

    bolt_count = _subaddiefind_entrypoint_4(0x3DC, bolts, 4);
    remaining = bolt_count;
    for (i = 0; i < bolt_count; i++) {
        if ((s32) bolts[i]->unk70_10 >= 3) {
            remaining--;
        }
    }
    if (remaining == 3 || remaining == 0) {
        entry = func_80800FCC_chbilldrillplate();
        if (remaining == 0) {
            func_800DA544(entry[6]);
        }
        _glcutDll_entrypoint_6(entry[1], entry[7]);
    }
}

void func_80800358_chbilldrillplate(Actor *actor)
{
    void *entry;
    void *link;
    void *data;
    unsigned short lift_raw;
    float base_y;
    float lift;
    // Matching: the comma expression is needed for the match.
    entry = (0, func_80801020_chbilldrillplate());
    data = func_80100094(actor, 0);
    link = data;
    *(float *) ((char *) actor + 0x34) = 600.0f;
    base_y = *(float *) ((char *) actor + 0x8);
    *(float *) ((char *) actor + 0x28) = base_y;
    // Matching: the "^ 0" is needed for the match.
    lift_raw = *(unsigned short *) ((char *) entry + 0x4) ^ 0;
    lift = (float) lift_raw;
    *(float *) ((char *) actor + 0x8) = (float) (base_y + lift);
    _subaddielink_entrypoint_0(data);
    _subaddiefade_entrypoint_14(actor);
    if (*(unsigned short *) ((char *) entry + 0x10)) {
        *(float *) ((char *) link + 0x8) = 25.f;
    }
}

s32 func_80800C98_chbilldrillplate(Actor *param_0, f32 *param_1, f32 param_2);

void func_80800B9C_chbilldrillplate();

void func_80800408_chbilldrillplate(Actor *actor)
{
    u8 *link;
    f32 floor_y;
    s32 i;
    Vec3f pos;
    f32 dt;
    s32 particle_type;
    Actor *linked;

    link = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            if (!actor->unk64_20) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808011C4_chbilldrillplate);
                actor->unk64_20 = 1;
            }
            _subaddieDll_entrypoint_7(actor, 8);
            if (_subaddielink_entrypoint_2(link)) {
                _subaddieDll_entrypoint_7(_subaddielink_entrypoint_4(link), 8);
            }
            if (func_800D9078(&actor->unk58)) {
                func_80800B9C_chbilldrillplate(actor);
                func_80101FDC(actor, 4);
            }
            break;
        case 3:
            if (!actor->unk64_20) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808011C4_chbilldrillplate);
                actor->unk64_20 = 1;
            }
            if (func_800D9078((f32 *) &actor->actorData[6])) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808011D4_chbilldrillplate);
            }
            _subaddieDll_entrypoint_7(actor, 8);
            if (_subaddielink_entrypoint_2(link)) {
                _subaddieDll_entrypoint_7(_subaddielink_entrypoint_4(link), 8);
            }
            if (func_800D9078(&actor->unk58)) {
                func_80101FDC(actor, 1);
                func_80103110(actor, 0);
            }
            break;
        case 4:
            dt = func_800D8FF8();
            actor->position[1] -= *(f32 *) &actor->actorData[7] * dt;
            *(f32 *) &actor->actorData[7] += 2500.0f * dt;
            func_80800C98_chbilldrillplate(actor, &floor_y,
                                           *(f32 *) &actor->actorData[7] * dt);
            if (actor->position[1] < floor_y) {
                actor->position[1] = floor_y;
                *(f32 *) &actor->actorData[7] = 600.0f;
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808011E0_chbilldrillplate);
                particle_type = func_800B53A4(8);
                for (i = 0; i != 8; i++) {
                    func_800EE7F8(pos.f, actor->position);
                    func_800EF1B8(pos.f, (f32) i * 45.0f, func_800DC178(100.0f, 120.0f));
                    func_800BABB8(particle_type, pos.f, actor->position, 1.5f,
                                  D_808011F0_chbilldrillplate);
                }
                func_800E15CC(0, 30.0f, 0.9f);
                func_80018820(0, 2.0f, 0.3f);
                func_80101FDC(actor, 5);
                func_80103110(actor, 0);
            }
            if (_subaddielink_entrypoint_2(link)) {
                linked = _subaddielink_entrypoint_4(link);
                linked->position[1] = *(f32 *) (link + 8) + actor->position[1];
                func_80103014(linked);
            }
    }
}

s32 func_80800738_chbilldrillplate(Actor *actor, s32 event, s32 arg)
{
    u8 *entry;
    u8 *link;
    u8 *init_entry;
    u16 target_id;
    Actor *other;

    if (event == 0x49) {
        entry = func_80801020_chbilldrillplate();
        if (arg == *(u16 *) (entry + 0xE)) {
            func_80103110(actor, 1);
            if (func_800DA298(*(u16 *) (entry + 0xC))) {
                func_80101FDC(actor, 2);
                actor->unk58 = 1.0f;
                func_800FC660(16);
                other = func_80800978_chbilldrillplate(actor);
                other->actorData[5] = 0;
                _capod_entrypoint_13(other->unk0, 0, *(u16 *) (entry + 8), 0x900);
                return 1;
            }
            actor->actorData[5] = 1;
            ((f32 *) actor->actorData)[6] = 0.5f;
            func_80101FDC(actor, 3);
            actor->unk58 = 1.0f;
            _capod_entrypoint_13(actor->unk0, 0, *(u16 *) (entry + 0xA), 0x900);
            return 1;
        }
    }
    if (event == 0x95) {
        link = func_80100094(actor, 0);
        init_entry = func_80801020_chbilldrillplate();
        if (init_entry[0x12]) {
            _subaddieDll_entrypoint_0(actor);
        }
        func_80103140(actor, *(u16 *) (init_entry + 6), *(u16 *) ((u8 *) actor->unk0 + 0x16));
        _subaddielink_entrypoint_0(link);
        target_id = *(u16 *) (init_entry + 0x10);
        if (target_id) {
            other = _subaddiefind_entrypoint_0(actor->position, target_id, -1, 0);
            if (other != NULL) {
                _subaddielink_entrypoint_1(link, other->unk0);
            }
        }
        if (!_glcutDll_entrypoint_19(*(u16 *) (init_entry + 0xE))) {
            if (func_800DA298(*(u16 *) (init_entry + 0xC))) {
                actor->actorData[5] = 0;
                actor->position[1] = ((f32 *) actor->actorData)[4];
            } else {
                actor->actorData[5] = 1;
            }
        }
        other = _subaddielink_entrypoint_4(link);
        if (other != NULL) {
            other->position[1] = *(f32 *) (link + 8) + actor->position[1];
            func_80103014(other);
        }
    }
    return 0;
}

s32 func_80800924_chbilldrillplate(s32 actor, s32 arg)
{
    s32 entry = func_80801020_chbilldrillplate();
    s32 value;
    if (*(u8 *) (entry + 0x13) != 0) {
        value = 0;
    } else {
        value = *(s32 *) (actor + 0x2C);
    }
    func_800DF744(1, value);
    func_80101870(actor, arg);
}

Actor *func_80800978_chbilldrillplate(actor)
Actor *actor;
{
    Vec3f hall_pos;
    Vec3f chamber_pos;

    switch (func_800EA05C()) {
        case 0x101:
            func_800EFA4C(hall_pos.f, 180.0f, 480.0f, 180.0f);
            func_800EF04C(hall_pos.f, actor->position);
            func_80108528(0x473, hall_pos.f, 0, &actor);
            func_800EFA4C(hall_pos.f, -180.0f, 480.0f, 180.0f);
            func_800EF04C(hall_pos.f, actor->position);
            func_80108528(0x473, hall_pos.f, 0, &actor);
            func_800EFA4C(hall_pos.f, 180.0f, 480.0f, -180.0f);
            func_800EF04C(hall_pos.f, actor->position);
            func_80108528(0x473, hall_pos.f, 0, &actor);
            func_800EFA4C(hall_pos.f, -180.0f, 480.0f, -180.0f);
            func_800EF04C(hall_pos.f, actor->position);
            func_80108528(0x473, hall_pos.f, 0, &actor);
            break;
        case 0x107:
            func_800EFA4C(chamber_pos.f, 130.0f, 20.0f, 130.0f);
            func_800EF04C(chamber_pos.f, actor->position);
            func_80108528(0x473, chamber_pos.f, 0, &actor);
            func_800EFA4C(chamber_pos.f, -130.0f, 20.0f, 130.0f);
            func_800EF04C(chamber_pos.f, actor->position);
            func_80108528(0x473, chamber_pos.f, 0, &actor);
            func_800EFA4C(chamber_pos.f, 130.0f, 20.0f, -130.0f);
            func_800EF04C(chamber_pos.f, actor->position);
            func_80108528(0x473, chamber_pos.f, 0, &actor);
            func_800EFA4C(chamber_pos.f, -130.0f, 20.0f, -130.0f);
            func_800EF04C(chamber_pos.f, actor->position);
            func_80108528(0x473, chamber_pos.f, 0, &actor);
    }
    return actor;
}

void func_80800B9C_chbilldrillplate(Actor *actor)
{
    f32 hall_pos[3];
    f32 chamber_pos[3];

    switch (func_800EA05C()) {
        case 0x101:
            func_800EFA4C(hall_pos, 180.0f, 680.0f, 180.0f);
            func_800EF04C(hall_pos, actor->position);
            func_80101010(hall_pos);
            func_80101180(0x473, 5, 0);
            _subaddieaudioquick_entrypoint_2(actor, hall_pos, D_80801220_chbilldrillplate);
            break;
        case 0x107:
            func_800EFA4C(chamber_pos, 130.0f, 220.0f, 130.0f);
            func_800EF04C(chamber_pos, actor->position);
            func_80101010(chamber_pos);
            func_80101180(0x473, 5, 0);
            _subaddieaudioquick_entrypoint_2(actor, chamber_pos, D_80801220_chbilldrillplate);
    }
}

s32 func_80800C98_chbilldrillplate(Actor *actor, f32 *out_y, f32 extra_height)
{
    f32 top[3];
    f32 bottom[3];
    f32 hit_pos[3];
    s32 found;

    func_800EE7F8(top, actor->position);
    func_800EE7F8(bottom, actor->position);
    top[1] += 20.0f + extra_height;
    bottom[1] -= 20.0f;
    func_8010A624(actor);
    if (func_800C6A7C(top, bottom, hit_pos, 0x20020))
        found = 1;
    else
        found = 0;
    func_8010A63C(actor);
    if (found)
        *out_y = bottom[1];
    return found;
}

int func_80800D5C_chbilldrillplate(s32 actor)
{
    if (func_800DA298(*(u16 *) (func_80800FCC_chbilldrillplate() + 0xC))) {
        func_800FFAB0(actor);
        return;
    }
    _subaddiefade_entrypoint_14(actor);
}

void func_80800DA4_chbilldrillplate(Actor *actor)
{
    f32 origin[3];
    f32 pos[3];
    s32 particle_type;
    s32 i;
    if (actor->unk70_10 == 2 && func_800D9078((u8 *) actor + 0x58)) {
        func_800EE7F8(origin, actor->position);
        origin[1] -= 150.0f;
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80801234_chbilldrillplate);
        particle_type = func_800B53A4(5);
        for (i = 0; i != 5; i++) {
            func_800EE7F8(pos, actor->position);
            func_800EF1B8(pos, i * 72.0f, func_800DC178(100.0f, 120.0f));
            func_800BABB8(particle_type, pos, origin, 1.4f, &D_80801244_chbilldrillplate);
        }
        _chexploder_entrypoint_3(actor, origin, 8);
    }
}

s32 func_80800F24_chbilldrillplate(Actor *actor, s32 event, s32 arg)
{
    switch (event) {
        case 0x95:
            if (func_800DA298(*(u16 *) ((u8 *) func_80800FCC_chbilldrillplate() + 0xC))) {
                func_80101FDC(actor, 2);
                actor->unk58 = 0.16f;
                func_80103110(actor, 1);
            }
            break;
        case 0x90:
            _chexploder_entrypoint_6(func_80106790(func_80101080()), 500.0f, 600.0f);
            return 1;
        default:
            return 0;
    }
    return 1;
}

// Matching: the line breaks in this function are needed for the match.
u8 *func_80800FCC_chbilldrillplate(void)
{
    s32 map_id;
    u8 *entry;
    map_id = func_800EA05C();
    entry = (u8 *) (u8 *) D_808010A0_chbilldrillplate; loop_1: if (map_id == *(u16 *) entry) { return entry;
    }

    entry += 0x14;
    if ((u8 *) entry == (u8 *) &D_808010DC_chbilldrillplate)
    {
        return 0;
    }
    goto loop_1;
}

BilldrillPlateEntry *func_80801020_chbilldrillplate(void)
{
    s32 map_id;
    s32 i;
    map_id = func_800EA05C();
    for (i = 0; i < 3; i++) {
        if (D_808010A0_chbilldrillplate[i].unk2 == map_id) {
            return &D_808010A0_chbilldrillplate[i];
        }
    }
    return NULL;
}

// TU-NOTE: the overlay .data is defined in C here (values taken from the ROM); IDO schedules some
// functions differently unless these tables share the unit. The extern declarations at the top
// were adjusted to the object types (same addresses).
extern void func_80105834();
extern int func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
BilldrillPlateEntry D_808010A0_chbilldrillplate[3] = {
    0x106, 0x101, 0x3, 0xE8, 0x7,   0xA8,  0x0, 0x9,  0x0,   0x19,  0x1, 0xC2, 0x0, 0x3D,
    0x0,   0x0,   0x1, 0x0,  0x10E, 0x10B, 0x1, 0xA4, 0x7,   0xA9,  0x0, 0x7,  0x0, 0x8,
    0x1,   0xC3,  0x0, 0x3E, 0x2,   0x10,  0x0, 0x1,  0x109, 0x107, 0x2, 0xBC, 0x7, 0xA9,
    0x0,   0xE,   0x0, 0xC,  0x1,   0xC4,  0x0, 0x3F, 0x2,   0xB0,  0x0, 0x0};
u32 D_808010DC_chbilldrillplate[18] = {0xA203DC,
                                       0x79F0001,
                                       0x0,
                                       (u32) func_808000B0_chbilldrillplate,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x800,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_80800024_chbilldrillplate,
                                       (u32) func_80107C2C,
                                       0x80080C10,
                                       (u32) func_80800240_chbilldrillplate,
                                       0x0};
int D_80801124_chbilldrillplate[18] = {0xA303DD,
                                       0x7A90001,
                                       0x0,
                                       (u32) func_80800408_chbilldrillplate,
                                       (u32) func_80105834,
                                       (u32) func_80800924_chbilldrillplate,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x800,
                                       0x0,
                                       0x0,
                                       0xC0000,
                                       (u32) func_80800358_chbilldrillplate,
                                       (u32) func_80107C2C,
                                       -0x7FF7F3EE,
                                       (u32) func_80800738_chbilldrillplate,
                                       0x0};
int D_8080116C_chbilldrillplate[18] = {0xA403DE,
                                       0x7AD0001,
                                       0x0,
                                       (u32) func_80800DA4_chbilldrillplate,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x800,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80800D5C_chbilldrillplate,
                                       (u32) func_80107C2C,
                                       -0x7FF7F3EE,
                                       (u32) func_80800F24_chbilldrillplate,
                                       0x0};
s32 D_808011B4_chbilldrillplate[4] = {0x130632, 0xD00F3, 0x10C0016, 0x61A80000};
u8 D_808011C4_chbilldrillplate[16] = {0x0, 0x13, 0x6, 0x33, 0x0,  0xD,  0x0, 0xF3,
                                      0x1, 0xC,  0x0, 0x16, 0x61, 0xA8, 0x0, 0x0};
u8 D_808011D4_chbilldrillplate[12] = {0x0, 0x13, 0x4, 0xA1, 0x0, 0xD,
                                      0x0, 0xF3, 0x1, 0xC,  0x0, 0x0};
u8 D_808011E0_chbilldrillplate[16] = {0x0, 0x13, 0x4, 0xA0, 0x0, 0xD, 0x0, 0xC0,
                                      0x0, 0xD9, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0};
u8 D_808011F0_chbilldrillplate[48] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x20, 0xC0, 0xC0, 0xC0, 0x80, 0x0, 0x16, 0x0, 0x8,  0x0, 0x22,
    0x1, 0x33, 0x1, 0x66, 0x1, 0xCC, 0x2,  0x33, 0x0,  0x15, 0x0, 0x0,  0x0, 0x99, 0x0, 0x2B,
    0x1, 0x0,  0x1, 0x33, 0x0, 0x2D, 0x0,  0xC8, 0x1,  0x2C, 0x1, 0x1A, 0x0, 0x0,  0x0, 0x0};
u8 D_80801220_chbilldrillplate[20] = {0x0, 0x13, 0x6, 0x28, 0x0,  0xD,  0x0, 0xF3, 0x1, 0xC,
                                      0x0, 0x2,  0x0, 0x16, 0x6D, 0x60, 0x0, 0x0,  0x0, 0x0};
u32 D_80801234_chbilldrillplate[4] = {0x1304C8, 0xD00D9, 0xF30018, 0x20000};
u32 D_80801244_chbilldrillplate[15] = {0x1D09DD,  0x20C0C0, 0xC0800016, 0x80022,   0x1330166,
                                       0x1CC0233, 0x150000, 0x99002B,   0x1000133, 0x2D00C8,
                                       0x12C011A, 0x0,      0x0,        0x0,       0x0};
