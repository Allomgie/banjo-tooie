#include "common.h"

extern int D_80801B34_chfactorybattery[];
extern s32 _gccubesearch_entrypoint_12(f32 *, s32, f32 *, Actor *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80102FDC(Actor *, f32);
typedef struct {
    u32 pad : 7;
    u32 flag : 1;
    u32 pad2 : 24;
} BitTest7;
extern void *_subaddietaxi_entrypoint_16;
typedef struct Mass44BatteryFlags {
    u8 pad_0[0x78];
    u32 pad_1 : 26;
    u32 local_0 : 1;
    u32 pad_2 : 5;
} Mass44BatteryFlags;
extern void func_8010A3E8(Actor *, f32);
extern void _chfactorybattery_entrypoint_0();
typedef union {
    s32 local_0;
    void *local_1;
} FactoryBatteryEvent60;
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x50];
    s32 local_0;
} BatteryParticleHolder;
extern f32 func_80103EAC(Actor *);
extern s32 func_800C8A98(void);
extern int D_80801BA8_chfactorybattery[];
extern void _chdoormake_entrypoint_9();
extern s32 _chdoormake_entrypoint_1(Actor *, f32, s32, s32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
typedef union {
    s32 word;
    void *pointer;
} FactoryBatteryEvent;
extern int D_80801BF0_chfactorybattery[];
extern Vec3f D_80801B3C_chfactorybattery;
extern Vec3f D_80801B48_chfactorybattery;
extern Vec3f D_80801B54_chfactorybattery;
extern f32 func_800DC178(f32, f32);
extern void func_800F3214(f32 *, f32 *, f32 *, f32);
extern u8 D_80801B78_chfactorybattery[];
extern u8 D_80801B60_chfactorybattery[];
extern f32 func_80103EF4(Actor *);
extern void func_800F4EC8(s32, f32 *, f32, f32, f32);
typedef struct {
    u8 pad0[0x70];
    u32 unk70_25 : 7;
    u32 pad70_16 : 9;
    u32 pad70_10 : 6;
    u32 unk70_4 : 6;
    u32 pad70_0 : 4;
} BatteryKeys;
typedef struct {
    u8 pad0[6];
    u16 unk6;
} BatteryRoute;
extern f32 D_80801B88_chfactorybattery[];
extern void *func_80100094(Actor *, s32);
extern void _subaddiefx_entrypoint_0(Actor *, s32, void *);
extern s32 func_800D90A4(f32 *);
extern s32 _subaddietaxi_entrypoint_1(Actor *, s32);
extern s32 _subaddietaxi_entrypoint_11(Actor *, s32);
extern s32 _subaddietaxi_entrypoint_5(Actor *, s32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, f32 *, s32);
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern s32 func_8010C500(Actor *);
extern f32 *func_800CC63C(s32, s32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern s32 func_800F54E4(void);
extern f32 func_8010CD50(Actor *, s32);
extern void _subaddierouteDll_entrypoint_6(Actor *, BatteryRoute *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_7(Actor *, BatteryRoute *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, BatteryRoute *, s32, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern s32 _subaddiejoy_entrypoint_6(Actor *, s32);
extern s32 func_800DC128(s32, s32);
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern s32 func_80102CCC(Actor *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_8010BA80(Actor *, s32, s32);
extern s32 func_8010C9FC(f32 *, s32, s32, s32);
extern void func_8010108C(Actor *, s32, s32);
extern void _subaddietaxi_entrypoint_9(Actor *, s32);
extern f32 func_8010A40C(Actor *);
int func_80800444_chfactorybattery();
int func_80800480_chfactorybattery();
int func_808004E8_chfactorybattery();
int func_80800558_chfactorybattery();
f32 func_80800580_chfactorybattery();
int func_80800678_chfactorybattery();
void func_808006E4_chfactorybattery();
void func_8080130C_chfactorybattery();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80108ED0();
extern u8 D_80801AB0_chfactorybattery[], D_80801AC4_chfactorybattery[], boot_thread_stack[];

int *chfactorybattery_entrypoint_0()
{
    return D_80801B34_chfactorybattery;
}

// Snaps the battery to the nearest marker (0x28C).
s32 func_8080000C_chfactorybattery(Actor *actor)
{
    f32 snap_pos[3];
    s32 result;

    result = _gccubesearch_entrypoint_12(snap_pos, 0x28C, actor->position, actor);
    func_800EE7F8(actor->position, snap_pos);
    return result;
}

void func_80800050_chfactorybattery(Actor *actor, s32 unk_1)
{
    f32 delivery_pos[3];
    switch (func_800CB3E0(unk_1)) {
        case 6:
            break;
        case 1:
            actor->unk6C_0 = unk_1;
            func_80102FDC(actor, 0.45f);
            func_8080130C_chfactorybattery(actor, 6);
            ((BitTest7 *) ((u8 *) actor + 0x64))->flag = 1;
            break;
        case 3:
            actor->unk6C_0 = unk_1;
            func_80102FDC(actor, 0.45f);
            _subaddietaxi_entrypoint_10(actor, unk_1, 4);
            break;
        case 4:
            actor->rotation[1] = func_80800580_chfactorybattery(delivery_pos);
            actor->unk6C_0 = unk_1;
            func_80102FDC(actor, 0.45f);
            _subaddietaxi_entrypoint_0(actor, unk_1, delivery_pos, 3);
    }
    if (actor && !(*(u32 *) ((u8 *) actor + 0x6C) >> 21))
        actor->unk6C_0 = unk_1;
}

void func_8080019C_chfactorybattery(volatile unsigned long param_0, u8 *param_1, s32 param_2,
                                    s32 param_3)
{
    _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, param_0,
                                *(s32 *) ((u8 *) param_1 + 0), *(s32 *) ((u8 *) param_1 + 4),
                                *(s32 *) ((u8 *) param_1 + 8), param_2, param_3);
}

int func_808001F8_chfactorybattery(Actor *actor)
{
    func_80102FDC(actor, 0.45f);
    func_8010A3E8(actor, 0.6f);
    if (((Mass44BatteryFlags *) actor)->local_0) {
        if (func_80800678_chfactorybattery(actor)) {
            if (!func_80800558_chfactorybattery(actor)) {
                if (_subaddietaxi_entrypoint_13(actor, func_80800678_chfactorybattery(actor),
                                                _chfactorybattery_entrypoint_0, 3))
                    actor->unk64_24 = 1;
                else {
                    func_800FFAB0(actor);
                    return 0;
                }
            } else {
                func_800FFAB0(actor);
                return 0;
            }
        } else {
            *((u8 *) actor + 0x64) &= 0xFFFE;
            *((u8 *) actor + 0x64) &= 0xE7;
            if (func_80800444_chfactorybattery())
                func_8080130C_chfactorybattery(actor, 13);
            else {
                func_800FFAB0(actor);
                return 0;
            }
        }
    } else {
        if (func_80800678_chfactorybattery(actor)) {
            if (func_80800558_chfactorybattery(actor)) {
                func_800FFAB0(actor);
                return 0;
            }
        } else {
            func_800FFAB0(actor);
            return 0;
        }
    }
    func_808006E4_chfactorybattery(actor);
    func_8080130C_chfactorybattery(actor, actor->unk70_10);
    if (actor->unk70_10 != 3 && actor->unk70_10 != 4 && actor->unk70_10 != 5 &&
        actor->unk70_10 != 13) {
        if ((*(u32 *) ((u8 *) actor + 0x70) >> 25) == 0 ||
            ((*(u32 *) ((u8 *) actor + 0x70) << 22) >> 26) == 0) {
            func_8080000C_chfactorybattery(actor);
            _subaddieDll_entrypoint_1(actor);
        }
        _subaddierouteDll_entrypoint_1(actor);
    }
    return 1;
}

s32 func_808003C0_chfactorybattery(FactoryBatteryEvent60 param_0, f32 *target_pos, f32 *out_pos)
{
    if (!func_80800444_chfactorybattery()) {
        if (func_808004E8_chfactorybattery()) {
            func_80800580_chfactorybattery(out_pos);
            if (func_800EEAD4(out_pos, target_pos) < 1000.0f) {
                return 2;
            }
            return 1;
        }
    }
    return 1;
}

int func_80800444_chfactorybattery()
{
    s32 flag;
    flag = func_80800480_chfactorybattery();
    if (flag != 0) {
        return func_800DA298(flag | 0);
    }
    return 0;
}

// Maps the floor's map id to its battery progress flag (FLAG_1B0..1B3).
int func_80800480_chfactorybattery()
{
    switch (func_800EA05C()) {
        case 0x101:
            return 0x1B0;

        case 0x106:
            return 0x1B1;

        case 0x109:
            return 0x1B2;

        case 0x10B:
            return 0x1B3;

        default:
            return 0;
    }
}

int func_808004E8_chfactorybattery(void)
{
    return func_800EA05C() == 0x101 || func_800EA05C() == 0x106 || func_800EA05C() == 0x109 ||
           func_800EA05C() == 0x10B;
}

int func_80800558_chfactorybattery()
{
    s32 battery_flag;
    battery_flag = func_80800678_chfactorybattery();
    func_800DA298(battery_flag + 0x1B1);
}

// Writes the floor delivery point to out_pos and returns its yaw.
f32 func_80800580_chfactorybattery(out_pos)
s32 out_pos;
{
    s32 map_id;

    map_id = func_800EA05C();

    switch (map_id) {
        case 0x101:
            func_800EFA4C(out_pos, 0x451D9000, 0x443B8000, 0xC51E1000);
            return 310.0f;
        case 0x106:
            func_800EFA4C(out_pos, 0x45C4F800, 0x44C1C000, 0xC4768000);
            return 180.0f;
        case 0x109:
            func_800EFA4C(out_pos, 0xC3928000, 0x42480000, 0x4524A000);
            return 180.0f;
        case 0x10B:
            func_800EFA4C(out_pos, 0x4565E000, 0x43AF0000, 0xC4F94000);
            return 90.0f;
        default:
            return 0.0f;
    }
}

int func_80800678_chfactorybattery(actor)
Actor *actor;
{
    u32 word;
    u32 state;

    word = (*(u32 *) ((char *) (actor) + 0x6C));
    state = word >> 21;

    switch (state) {
        case 0x51:
            return 3;
        case 0x5C:
            return 4;
        case 0x63:
            return 5;
        case 0x65:
            return 6;
        case 0:
            return word & 0x1FF;
        default:
            return 0;
    }
}

void func_808006E4_chfactorybattery(actor) Actor *actor;
{
    f32 particle_params[2];
    f32 radius;

    radius = func_80103EAC(actor);
    particle_params[0] = radius + radius;
    particle_params[1] = func_80103EAC(actor) * 4.0f;
    ((BatteryParticleHolder *) actor)->local_0 = func_800C8A98();

    if (((BatteryParticleHolder *) actor)->local_0) {
        func_800C8F64(((BatteryParticleHolder *) actor)->local_0, 3);
        func_800C8D4C(((BatteryParticleHolder *) actor)->local_0, particle_params);
        func_800C8FE0(((BatteryParticleHolder *) actor)->local_0, 0);
    }
}

void func_80800760_chfactorybattery(Actor *actor)
{
    Vec3f pos;
    Vec3f unk_0;
    Vec3f unk_1;
    Vec3f unk_2;
    Vec3f unk_3;

    if (_subaddieskeleton_entrypoint_2(actor->unk0, 4, pos.f) &&
        *(s32 *) ((u8 *) actor + 0x50)) {
        if (actor->unk70_10 == 1 || actor->unk70_10 == 9) {
            unk_0 = D_80801B3C_chfactorybattery;
            func_800C8CB8(*(s32 *) ((u8 *) actor + 0x50), pos.f);
            func_800C8E84(*(s32 *) ((u8 *) actor + 0x50), unk_0.f);
            func_800C8FE0(*(s32 *) ((u8 *) actor + 0x50), 1);
            return;
        }
        if (actor->unk79_4) {
            unk_2 = D_80801B48_chfactorybattery;
            unk_3 = D_80801B54_chfactorybattery;
            func_800F3214(unk_1.f, unk_2.f, unk_3.f, func_800DC178(0.7f, 1.0f));
            func_800C8CB8(*(s32 *) ((u8 *) actor + 0x50), pos.f);
            func_800C8E84(*(s32 *) ((u8 *) actor + 0x50), unk_1.f);
            func_800C8FE0(*(s32 *) ((u8 *) actor + 0x50), 1);
            return;
        }
        func_800C8FE0(*(s32 *) ((u8 *) actor + 0x50), 0);
    }
}

void func_808008C8_chfactorybattery(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 9:
            actor->unk79_4 = 0;
            break;
        case 5:
        case 7:
        case 10:
        case 13:
            actor->unk79_4 = func_800DC128(1, 4);
    }
}

void func_80800948_chfactorybattery(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
        case 2:
            break;
        case 6:
        case 8:
        case 10:
            _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                             D_80801B60_chfactorybattery, 0x3F000000);
    }

    if (actor->unk79_4) {
        _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80801B78_chfactorybattery);
    }
}

void func_808009C8_chfactorybattery(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
        case 4:
        case 5:
        case 9:
        case 13:
            func_800F4EC8(func_800F54E4(), actor->position, func_80103EF4(actor), 0.0f,
                          func_80103EAC(actor) * 0.25f);
            break;
        case 8:
        case 10:
            if (actor->unk79_4 == 0) {
                func_800F4EC8(func_800F54E4(), actor->position, func_80103EF4(actor), 0.0f,
                              func_80103EAC(actor) * 0.25f);
            }
    }
}

void func_80800AB8_chfactorybattery(Actor *actor)
{
    f32 local_0;
    BatteryRoute *local_1;
    f32 local_x;
    f32 local_2;
    f32 local_3;

    switch (actor->unk70_10) {
        case 1:
            _subaddiefx_entrypoint_0(actor, 4, func_80100094(actor, 0));
            if (func_800D90A4(&actor->unk58)) {
                func_8080130C_chfactorybattery(actor, 6);
            }
            break;
        case 3:
            if (_subaddietaxi_entrypoint_1(actor, func_80800678_chfactorybattery(actor))) {
                func_8080130C_chfactorybattery(actor, 5);
            }
            break;
        case 4:
            if (_subaddietaxi_entrypoint_11(actor, func_80800678_chfactorybattery(actor))) {
                if (_subaddietaxi_entrypoint_5(actor, func_80800678_chfactorybattery(actor))) {
                    func_8080130C_chfactorybattery(actor, 6);
                }
            }
            break;
        case 6:
            local_0 = func_800F3780(func_80101F24(actor), D_80801B88_chfactorybattery, 4);
            local_1 = func_80100094(actor, 1);
            if (_subaddierouteDll_entrypoint_4(actor)) {
                if (func_8010C500(actor)) {
                    local_2 = func_800F1DF4(func_800CC63C(((BatteryKeys *) actor)->unk70_25 - 1,
                                                          ((BatteryKeys *) actor)->unk70_4 - 1),
                                            actor->position);
                    actor->unk54 = func_8010CD50(actor, func_800F54E4()) - 180.0f;
                    if (local_2 + 90.0f < actor->unk54) {
                        actor->unk54 = local_2 + 90.0f;
                    } else if (actor->unk54 < local_2 - 90.0f) {
                        actor->unk54 = local_2 - 90.0f;
                    }
                } else {
                    _subaddierouteDll_entrypoint_6(actor, local_1, actor->unk74_7, 0x3F, 0.4f,
                                                   0x14, 0x28);
                }
                _subaddierouteDll_entrypoint_7(actor, local_1, actor->rotation[1],
                                               actor->unk54, 200.0f, 0x4803);
                actor->unk74_7 = local_1->unk6;
            }
            _subaddierouteDll_entrypoint_5(actor, local_1, actor->unk74_7, 0.3f, 1.0f,
                                           300.0f * local_0);
            func_8010C3A8(actor, 0x305425, local_0);
            break;
        case 7:
            if (func_800D90A4(&actor->unk58)) {
                func_8080130C_chfactorybattery(actor, 6);
            }
            break;
        case 10:
            if (func_800D90A4(&actor->unk58)) {
                func_8080130C_chfactorybattery(actor, 8);
            }
        case 8:
            if (actor->unk64_20) {
                if (_subaddiejoy_entrypoint_6(actor, 1)) {
                    if (func_800D90A4(&actor->unk58)) {
                        actor->unk64_20 = 0;
                        actor->unk79_4 = 0;
                        actor->unk58 = 1.0f;
                    } else {
                        actor->unk79_4 = func_800DC128(1, 4);
                    }
                } else {
                    actor->unk79_4 = 0;
                }
            } else if (func_800D90A4(&actor->unk58) && _subaddiejoy_entrypoint_6(actor, 1)) {
                actor->unk64_20 = 1;
                actor->unk58 = 2.0f;
                actor->unk79_4 = func_800DC128(1, 4);
            }
            local_3 = 600.0f;
            local_3 *= _subaddiejoy_entrypoint_3(actor);
            if (0.5f < func_80101F24(actor)) {
                if (!func_80102CCC(actor)) {
                    func_80102BAC(actor, 1.5f, 1.0f, 20.0f);
                } else {
                    local_x = (0.5f < func_80101F24(actor))
                                  ? (func_80101F24(actor) - 0.5f) * 2.0f
                                  : 0.0f;
                    ((f32 *) actor->actorData)[3] = func_80013970(local_x * 180.0f) * local_3;
                    func_8010BA80(actor, 0x201005, 0x20);
                }
            }
            break;
        case 9:
            _subaddiefx_entrypoint_0(actor, 4, func_80100094(actor, 0));
            if (func_800D90A4(&actor->unk58)) {
                func_8080130C_chfactorybattery(actor, 8);
            }
            break;
        case 5:
        case 13:
            if (func_8010C9FC(actor->position, func_80103EAC(actor), func_80103EF4(actor),
                              0)) {
                func_8010108C(actor, 0x3E, 0);
            }
    }

    func_808009C8_chfactorybattery(actor);
    func_80800948_chfactorybattery(actor);
    func_808008C8_chfactorybattery(actor);
    func_80800760_chfactorybattery(actor);
    _subaddietaxi_entrypoint_9(actor, func_80800678_chfactorybattery(actor));
}

s32 func_80801040_chfactorybattery(actor, event, arg)
Actor *actor;
s32 event;
s32 arg;
{
    s32 state;

    switch (event) {
        case 0x3E:
            switch ((u32) *(u16 *) ((u8 *) actor + 0x72) >> 10) {
                case 1:
                case 4:
                case 9:
                    if (_subaddietaxi_entrypoint_2(actor,
                                                   func_80800678_chfactorybattery(actor))) {
                        func_8080130C_chfactorybattery(actor, 2);
                    }
                    return 1;
                case 6:
                case 7:
                    func_8080130C_chfactorybattery(actor, 7);
                    return 1;
                case 8:
                case 10:
                    if (((u32) *(u8 *) ((u8 *) actor + 0x79) >> 4) != 0) {
                        func_8080130C_chfactorybattery(actor, 0xA);
                    }
                    return 1;
                case 5:
                case 13:
                    func_800F7A2C(func_800F54E4(), 5, (u8 *) actor + 4);
                    return 1;
            }
            return 1;
        case 0x40:
            switch ((u32) *(u16 *) ((u8 *) actor + 0x72) >> 10) {
                case 1:
                case 6:
                    func_8080130C_chfactorybattery(actor, 1);
                    return 1;
                case 8:
                case 9:
                case 10:
                    func_8080130C_chfactorybattery(actor, 9);
                    return 1;
            }
            return 1;
        case 1:
            state = (u32) *(u16 *) ((u8 *) actor + 0x72) >> 10;
            if (state == 1 || state == 6 || state == 7) {
                func_8080130C_chfactorybattery(actor, 8);
                return 1;
            }
            return 1;
        case 2:
            func_80107070(actor, 1);
            return 1;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(3, (u32) *(u8 *) ((u8 *) actor + 0x79) >> 4);
            return 1;
        case 0x44:
            func_80800050_chfactorybattery(actor, arg);
            return 1;
        case 0x29:
            *(s16 *) (*(s32 *) actor + 0x20) = (s32) (func_8010A40C(actor) * 120.0f);
            return 1;
        case 0x95:
            func_808001F8_chfactorybattery(actor);
            return 1;
        case 0x4D:
            func_8080000C_chfactorybattery(actor);
            // Matching: empty block steers IDO's register allocation.
            if (1) {
            }
            state = (u32) *(u16 *) ((u8 *) actor + 0x72) >> 10;
            if (((u32) *(u16 *) ((u8 *) actor + 0x72) >> 10) != 3 &&
                ((u32) *(u16 *) ((u8 *) actor + 0x72) >> 10) != 4 && state != 5 && state != 0xD) {
                _subaddieDll_entrypoint_1(actor);
                _subaddierouteDll_entrypoint_1(actor);
            }
            return 1;
        default:
            return 0;
    }
}

void func_8080130C_chfactorybattery(actor, state) u8 *actor;
s32 state;
{
    s32 flag;

    switch (state) {
        case 1:
        case 9:
            *(u8 *) ((char *) actor + 0x79) = (u8) (*(u8 *) ((char *) actor + 0x79) & 0xFF0F);
            *(f32 *) ((char *) actor + 0x58) = 6.0f;
            break;
        case 6:
            *(f32 *) ((char *) actor + 0x24) = 800.0f;
            if (func_80100094(actor, 0) == 0) {
                func_80100074(actor, 0, 8);
            }
            if (func_80100094(actor, 1) == 0) {
                func_80100074(actor, 1, 0xC);
                _subaddierouteDll_entrypoint_3(actor, func_80100094(actor, 1), actor + 4);
            }
            if (func_80100094(actor, 0) != 0) {
                _subaddiefx_entrypoint_1(actor, func_80100094(actor, 0));
            }
            break;
        case 7:
        case 10:
            func_800F7A2C(func_800F54E4(), 5, actor + 4);
            *(f32 *) ((char *) actor + 0x58) = 1.0f;
            break;
        case 8:
            *(u8 *) ((char *) actor + 0x65) = (u8) (*(u8 *) ((char *) actor + 0x65) & 0xFFEF);
            *(u8 *) ((char *) actor + 0x79) = (u8) (*(u8 *) ((char *) actor + 0x79) & 0xFF0F);
            *(f32 *) ((char *) actor + 0x58) = 0.0f;
            if (func_80100094(actor, 0) != 0) {
                _subaddiefx_entrypoint_1(actor, func_80100094(actor, 0));
            }
            break;
        case 5:
            flag = func_80800480_chfactorybattery();
            if (flag != 0) {
                func_800DA544(flag);
                func_800DA544(func_80800678_chfactorybattery(actor) + 0x1B1);
            }
        case 13:
            func_8010A570(actor);
    }

    func_80102424(actor, state);
}

s32 func_808014C0_chfactorybattery(actor)
s32 actor;
{
    s32 effect;

    effect = func_80100094(actor, 0);

    if (effect) {
        _subaddiefx_entrypoint_1(actor, func_80100094(actor, 0));
    }
}

int chfactorybattery_entrypoint_1()
{
    return (int) D_80801BA8_chfactorybattery;
}

void func_8080150C_chfactorybattery(Actor *actor)
{
    switch (func_800EA05C()) {
        case 0x101:
            func_80103140(actor, 0x87F, 0);
            _chdoormake_entrypoint_1(actor, -90.0f, 0x4C, func_80800480_chfactorybattery());
            _chdoormake_entrypoint_9(actor, 0, 6, 0x10);
            break;
        case 0x106:
            _chdoormake_entrypoint_3(actor, 0.0f, 90.0f, func_80103EF4(actor) * 0.75f, 0x44,
                                     func_80800480_chfactorybattery());
            _chdoormake_entrypoint_9(actor, 0, 3, 0x10);
            break;
        case 0x109:
            _chdoormake_entrypoint_3(actor, 0.0f, 90.0f, func_80103EF4(actor) * 0.75f, 0x44,
                                     func_80800480_chfactorybattery());
            _chdoormake_entrypoint_9(actor, 0, 1, 0x10);
            break;
        case 0x10B:
            _chdoormake_entrypoint_3(actor, 0.0f, 90.0f, func_80103EF4(actor) * 0.75f, 0x44,
                                     func_80800480_chfactorybattery());
            _chdoormake_entrypoint_9(actor, 0, 1, 0x10);
    }

    _chdoormake_entrypoint_8(actor, 4);
    _chdoormake_entrypoint_5(actor, 3.0f);
    _chdoormake_entrypoint_6(actor, 1.0f);

    if (func_800DA298(func_80800480_chfactorybattery())) {
        actor->unk74_30 = 1;
        actor->unk74_29 = actor->unk74_30;
    }
}

void func_80801728_chfactorybattery(Actor *actor)
{
    if (!func_800DA298(0x343) && func_8010CA74(actor->position, 750) &&
        !func_800DA298(func_80800480_chfactorybattery())) {
        func_800DA544(0x343);
        _subaddiedialog_entrypoint_11(actor->unk0, 0x1352, 6, actor->position, 0);
        actor->unk74_30 = 1;
    }

    if (!actor->unk74_29 && func_800DA298(func_80800480_chfactorybattery())) {
        _subaddiedialog_entrypoint_11(actor->unk0, 0x1353, 6, actor->position, 0);
        actor->unk74_29 = 1;
    }

    _chdoor_entrypoint_0(actor);
}

s32 func_80801804_chfactorybattery(Actor *actor, s32 param_1, FactoryBatteryEvent param_2)
{
    if (param_1 == 0x95) {
        if (func_800EA05C() == 0x101) {
            func_80103140(actor, 0x87F, 0);
        }
        return _chdoor_entrypoint_1(actor, param_1, param_2.word);
    } else {
        return _chdoor_entrypoint_1(actor, param_1, param_2.word);
    }
}

int chfactorybattery_entrypoint_2()
{
    return (int) D_80801BF0_chfactorybattery;
}

extern void func_80101870();
u8 D_80801AB0_chfactorybattery[20] = {0x0, 0x6, 0x0, 0x0, 0x0, 0xB, 0x0, 0x0, 0x0, 0x0,
                                      0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0};
u8 D_80801AC4_chfactorybattery[112] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCC, 0x0, 0x1,
    0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCC, 0x0, 0x1, 0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCC, 0x0, 0x1,
    0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCC, 0x0, 0x1, 0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCC, 0x0, 0x1,
    0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCB, 0x0, 0x1, 0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCC, 0x0, 0x1,
    0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCB, 0x0, 0x1, 0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCC, 0x0, 0x1,
    0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCB, 0x0, 0x1, 0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCB, 0x0, 0x1,
    0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCB, 0x0, 0x1, 0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xCC, 0x0, 0x1};
int D_80801B34_chfactorybattery[2] = {(u32) func_808003C0_chfactorybattery,
                                      (u32) func_8080019C_chfactorybattery};
Vec3f D_80801B3C_chfactorybattery = {2.8e-43f, 2.8e-43f, 2.8e-43f};
Vec3f D_80801B48_chfactorybattery = {0.0f, 0.0f, 0.0f};
Vec3f D_80801B54_chfactorybattery = {5.6e-44f, 2.8e-43f, 3.57e-43f};
u8 D_80801B60_chfactorybattery[24] = {0x0, 0x13, 0x4,  0xD5, 0x0, 0x16, 0x27, 0x10,
                                      0x0, 0xD,  0x0,  0xCC, 0x0, 0xE6, 0x0,  0x1,
                                      0x0, 0xC8, 0x17, 0x70, 0x0, 0x0,  0x0,  0x0};
u8 D_80801B78_chfactorybattery[16] = {0x0, 0x13, 0x5, 0x2E, 0x0,  0xD,  0x1, 0x33,
                                      0x1, 0x66, 0x0, 0x16, 0x36, 0xB0, 0x0, 0x0};
f32 D_80801B88_chfactorybattery[8] = {0.0f, 0.0f, 0.4f, 0.0f, 0.8f, 1.0f, 1.0f, 0.0f};
int D_80801BA8_chfactorybattery[18] = {0x124028C,
                                       0x7E40006,
                                       (u32) &D_80801AC4_chfactorybattery,
                                       (u32) func_80800AB8_chfactorybattery,
                                       (u32) func_80105834,
                                       (u32) func_801018A4,
                                       0x7D00000,
                                       0x3FC00000,
                                       0x0,
                                       0x840165,
                                       (u32) func_808014C0_chfactorybattery,
                                       (u32) func_80108ED0,
                                       0x0,
                                       0x0,
                                       (u32) func_80107C2C,
                                       (u32) ((u8 *) &boot_thread_stack + 0xF25),
                                       (u32) func_80801040_chfactorybattery,
                                       (u32) &D_80801AB0_chfactorybattery};
int D_80801BF0_chfactorybattery[20] = {0x11A03FB,
                                       0x87B0001,
                                       0x0,
                                       (u32) func_80801728_chfactorybattery,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x7D00000,
                                       0x0,
                                       0x0,
                                       0x40000C00,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_8080150C_chfactorybattery,
                                       (u32) func_80107C2C,
                                       -0x7FF79BEE,
                                       (u32) func_80801804_chfactorybattery,
                                       0x0,
                                       0x0,
                                       0x0};
