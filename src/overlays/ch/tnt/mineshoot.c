// Glitter Gulch Mine "Ordnance Storage" minigame: walking TNT actors that explode on contact or
// when shot, the controller (count, timer, record, failure blast), entrance trigger, debris.
#include "common.h"

// TU-NOTE: the .data tables at the end are defined in C; they point to functions of this
// file, and IDO's assembler schedules some of them differently unless they share the unit.
// The extern declarations of these tables were adjusted to the object (same addresses).

extern s32 D_80802590_chtntmineshoot[];
extern s32 D_8080259C_chtntmineshoot[];
extern void func_800C4AF0(int, void *);
extern int D_808025A8_chtntmineshoot[];
extern s16 D_808025CC_chtntmineshoot[];
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_800187B4(s32, f32, f32, f32);
extern u32 func_800F54E4(void);
extern void func_800F5A00(s32, f32 *);
extern s32 D_808025DC_chtntmineshoot[];
extern f32 func_800F5F24(s32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern u8 D_808025F8_chtntmineshoot[];
extern u8 D_80802644_chtntmineshoot[];
extern void _subaddierouteDll_entrypoint_3();
extern void *func_80100094(Actor *, u32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_8010CD28(Actor *);
extern f32 func_800136E4(f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void func_80102BF8(Actor *, f32, f32, f32);
typedef struct {
    u8 pad_0;
    u8 state;
    u8 pad_1[2];
    u8 mode;
    u8 pad_2[3];
    f32 time;
} MineShootState;
extern f32 func_800DC0C0(void);
extern f32 func_800D8FF8(void);
extern int D_80802690_chtntmineshoot[];
extern s32 func_800C2E04(void);
extern void func_800C330C(s32, s32);
extern void func_800C431C(s32, s32);
extern void _susubgame_entrypoint_11(s32);
extern Actor *func_80106790(Unk80132ED0 *);
extern int D_808026D8_chtntmineshoot[];
extern Vec3f D_80802720_chtntmineshoot;
extern u8 D_8080272C_chtntmineshoot[];
typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 13;
    u32 local_0 : 1;
    u32 pad_2 : 18;
} MineShootFlags35;
extern void _bsfirstp_entrypoint_18(void);
extern int D_80802774_chtntmineshoot[];
typedef struct MineEntry {
    s32 f00;
    s16 f04;
    s16 f06;
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
} MineEntry;
extern u8 D_808027BC_chtntmineshoot[];
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EFA98(u8 *, f32 *, f32);
extern s32 func_80103140(void *, u16, u16);
extern void func_800DF5D8();
extern void func_80101870(void *param_0, s32 param_1);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
extern s32 func_800F1EA4(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern s32 D_8080287C_chtntmineshoot[];
extern s32 D_808028C4_chtntmineshoot[];
extern int func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 D_808028E4_chtntmineshoot[];
extern f32 func_80103EF4(Actor *);
extern f32 func_80103EAC(Actor *);
extern void func_8008FB10(f32 *, f32, f32, f32);
extern u8 D_80802580_chtntmineshoot[];
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F13F0(f32, f32);
extern void func_80101CDC(Actor *, f32);
extern void func_800FE820(f32);
extern void func_800CE8D8(s32, f32, s32);
typedef struct {
    s32 local_0;
    s32 local_1;
    f32 local_2;
    s32 pad_0;
    s32 local_3;
} Mass63TntState;
extern void _gcfrontend_entrypoint_9();
extern void func_800CE88C();
extern void func_800D2498();
extern void func_800D284C();
extern void func_800F49D4();
extern void func_800F7B9C();
extern void func_800F7C58();
extern void func_800F7F98();
extern void func_80101180();
extern void func_80101FDC();
extern f32 func_800CEA60(s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct {
    u8 pad_0[12];
    u8 local_0;
    u8 pad_1[3];
    s32 local_1;
} MineCountdown1570;
extern void func_800C35E8();
extern void func_800C301C(s32, s32);
extern void func_800C3058(s32, s32);
extern void func_800C3BDC(s32);
extern void func_800C3CE8(s32);
extern u8 func_800D9078();
void func_80800440_chtntmineshoot();
int func_80800BCC_chtntmineshoot();
void func_80800BF4_chtntmineshoot();
void func_80800C90_chtntmineshoot();
int func_80801A18_chtntmineshoot();
void func_80801F90_chtntmineshoot();
s32 func_808021C4_chtntmineshoot();
void func_808022A8_chtntmineshoot();
void func_80802320_chtntmineshoot();
void func_80800830_chtntmineshoot();
void func_80801318_chtntmineshoot();
void func_8080146C_chtntmineshoot();
void func_80801A54_chtntmineshoot();

void func_80800000_chtntmineshoot(s32 actor)
{
    func_800C4AF0(actor + 4, &D_80802590_chtntmineshoot);
    func_800C4AF0(actor + 4, &D_8080259C_chtntmineshoot);
}

void func_8080003C_chtntmineshoot(s32 actor)
{
    func_800BBCB8(actor + 4, 0, 1.0f, 4, &D_808025A8_chtntmineshoot);
}

void func_80800078_chtntmineshoot(f32 *pos, f32 param_1)
{
    f32 player_pos[3];

    if (pos != NULL) {
        func_800C4AF0(pos, D_808025CC_chtntmineshoot);
        if (param_1 != 0.0f)
            func_800E1610(0, 50.0f, param_1, pos);
    } else {
        func_800F5A00(func_800F54E4(), player_pos);
        func_800C4AF0(player_pos, D_808025CC_chtntmineshoot);
        if (param_1 != 0.0f)
            func_800E1610(0, 50.0f, param_1, player_pos);
    }
    func_800187B4(0, 0.5f, 2.0f, 0.5f);
}

void func_80800150_chtntmineshoot(u8 *actor)
{
    _subaddieaudioloop_entrypoint_4(actor, actor + 4, 1, &D_808025DC_chtntmineshoot);
    *(s8 *) ((s8 *) actor + 0x5F) = 0;
}

void func_80800188_chtntmineshoot(f32 *pos)
{
    f32 center[3];
    u32 player;
    if (pos) {
        func_800EE7F8(center, pos);
    } else {
        player = func_800F54E4();
        func_800F5A00(player, center);
        func_800EF1B8(center, func_800F5F24(player), 200.0f);
    }
    func_800BBCB8(center, 0, 1.0f, 1, D_808025F8_chtntmineshoot);
    func_800BBCB8(center, 0, 1.0f, 1, D_80802644_chtntmineshoot);
}

void func_80800228_chtntmineshoot(s32 actor)
{
    u8 *route = func_80100094(actor, 0);
    func_80800BCC_chtntmineshoot(actor);
    func_80800440_chtntmineshoot(actor, 0);
    _subaddierouteDll_entrypoint_3(actor, route + 0x18, actor + 4);
}

s32 func_80800AD0_chtntmineshoot();

s32 func_808004BC_chtntmineshoot();

// Walking TNT: per-frame behaviour.
void func_80800280_chtntmineshoot(Actor *actor)
{
    u8 *route;
    s32 hit_flags;

    route = func_80100094(actor, 0);
    hit_flags = func_80800AD0_chtntmineshoot(actor);
    switch (actor->unk70_10) {
        case 1:
            if (func_8010D248()) {
                func_808004BC_chtntmineshoot(actor, 2);
            }
            actor->unk54 = func_8010CD28(actor);
            func_80102BF8(actor, 0.1f, 4.0f, 360.0f);
            break;
        case 2:
            hit_flags &= 4;
            if (hit_flags) {
                *(f32 *) &actor->actorData[3] = 0.0f;
            }
            if (route[0x14] == 4) {
                if (hit_flags) {
                    actor->unk54 =
                        func_800136E4(actor->rotation[1] + func_800DC178(140.0f, 220.0f));
                    func_808004BC_chtntmineshoot(actor, 3);
                } else {
                    func_808004BC_chtntmineshoot(actor, 1);
                }
            }
            break;
        case 3:
            func_80102BF8(actor, 0.75f, 4.0f, 360.0f);
            if (actor->unk54 == actor->rotation[1]) {
                func_808004BC_chtntmineshoot(actor, 1);
            }
            break;
        case 4:
            func_80800000_chtntmineshoot(actor);
            func_80108B04(actor, 4);
            break;
        case 5:
            func_8080003C_chtntmineshoot(actor);
            func_80108B04(actor, 5);
    }
    func_8008FB10(actor->position, func_80103EF4(actor), 0.0f, func_80103EAC(actor));
}

void func_80800440_chtntmineshoot(actor, mode) s32 actor;
s32 mode;
{
    u8 *data;
    u8 *data_tmp;

    data_tmp = func_80100094(actor, 0);
    data = data_tmp;
    if (*data_tmp != 2) {
        if (mode != 0) {
            if ((mode == 1) || (mode == 2)) {
                _subaddieDll_entrypoint_4(actor, 1);
            }
        } else {
            _subaddieDll_entrypoint_4(actor, 0);
        }
        *data = (u8) mode;
    }
}

s32 func_808004BC_chtntmineshoot(Actor *actor, s32 state)
{
    switch (state) {
        case 2:
            func_80102424(actor, state);
            func_80800830_chtntmineshoot(actor, 1);
            break;
        case 4:
            func_80102424(actor, 4);
            func_80800830_chtntmineshoot(actor, 2);
            func_8010A570(actor);
            func_80800440_chtntmineshoot(actor, 2);
            break;
        case 5:
            func_80102424(actor, 5);
            func_80800830_chtntmineshoot(actor, 2);
            func_8010A570(actor);
            func_80800440_chtntmineshoot(actor, 2);
            func_800187B4(0, 0.5f, 2.0f, 0.75f);
        default:
            func_80102424(actor, state);
    }
    return 1;
}

s32 func_808005AC_chtntmineshoot(Actor *actor, s32 event, s32 event_arg)
{
    switch (event) {
        case 0x95:
            _subaddierouteDll_entrypoint_1(actor);
            break;
        case 0xA:
            func_80800BF4_chtntmineshoot(actor, 1);
            break;
        case 5:
            func_808004BC_chtntmineshoot(actor, 5);
            break;
        case 0x40:
            func_80101180(0x2BC, 5, 0);
            func_808004BC_chtntmineshoot(actor, 5);
            func_80800078_chtntmineshoot(actor->position, 0.95f);
            break;
        case 0x3F:
            func_80101180(0x2BC, 0x4F, 0);
            func_808004BC_chtntmineshoot(actor, 4);
            func_80800BF4_chtntmineshoot(actor, 2);
            break;
        case 0x3D:
            if (actor->unk7C_12)
                func_80801F90_chtntmineshoot(&actor, event_arg);
            func_800FFAB0(actor);
        default:
            return 0;
    }
    return 1;
}

void func_808006D0_chtntmineshoot(Actor *actor, s32 param_1)
{
    u8 *data = func_80100094(actor, 0);
    s32 unk_0;
    f32 color[3];

    func_800DF744(3, data[1] != 2);
    if (data[4])
        func_800DF5D8(*((u8 *) actor + 0x98), *((u8 *) actor + 0x99), *((u8 *) actor + 0x9A),
                      *((u8 *) actor + 0x9B));
    func_80101870(actor, param_1);
    if (actor->unk7C_12) {
        func_80800C90_chtntmineshoot(actor);
        if (data[1] == 1) {
            actor->unk50 += 1.0f;
            if (actor->unk50 >= 16.0f)
                actor->unk50 = 0.0f;
            func_800DBEFC(func_80104130(), 4, actor->actorData);
            unk_0 = func_800D674C(0x9C6);
            func_800EFA4C(color, 0.5f, 0.5f, 0.5f);
            func_800E2588(1);
            func_800E24D8(1);
            func_800E2AA4(param_1, unk_0, (s32) actor->unk50, 0, actor->actorData, color);
        }
    }
}

void func_80800830_chtntmineshoot(actor, state) Actor *actor;
s32 state;
{
    u8 *data;
    f32 duration;
    f32 jump_speed;
    f32 dist_factor;
    f32 player_pos[3];

    data = func_80100094(actor, 0);
    switch (state) {
        case 1:
            func_800F5A00(func_800F54E4(), player_pos);
            dist_factor = func_800F13F0(func_800EEAD4(player_pos, actor->position), 2000.0f) * 0.0005f;
            ((f32 *) actor->actorData)[3] = actor->scale * (1.0f - dist_factor) * 500.0f;
            duration = dist_factor * 0.6699999571f + 0.33f;
            jump_speed = (dist_factor * 200.0f + 200.0f) * actor->scale;
            func_800EFA4C((f32 *) &actor->actorData[4], 0.0f, jump_speed, 0.0f);
            ((f32 *) actor->actorData)[7] = (-jump_speed - jump_speed) / duration;
            duration += dist_factor * 0.5f;
            func_80101CDC(actor, duration);
            func_800C4AF0(actor->position, D_80802580_chtntmineshoot);
            func_80800440_chtntmineshoot(actor, 1);
            break;
        case 2:
            if (((f32 *) actor->actorData)[5] > 0.0f) {
                ((f32 *) actor->actorData)[5] = 0.0f;
            }
            break;
        case 3:
            func_800EFD24(&actor->actorData[4]);
            ((f32 *) actor->actorData)[7] = 0.0f;
            break;
        case 4:
            func_800EFD24(&actor->actorData[4]);
            ((f32 *) actor->actorData)[7] = 0.0f;
            ((f32 *) actor->actorData)[3] = 0.0f;
            func_80800440_chtntmineshoot(actor, 0);
    }
    data[0x14] = state;
}

s32 func_80800A1C_chtntmineshoot(Actor *actor)
{
    s32 hit_flags;
    u8 *route;

    route = func_80100094(actor, 0);
    actor->unk54 = func_800136E4(func_8010CD28(actor) + 180.0f);
    _subaddierouteDll_entrypoint_7(actor, route + 0x18, actor->rotation[1], actor->unk54,
                                   200.0f, 0x4000);
    func_80102BF8(actor, 0.1f, 4.0f, 100.0f);
    hit_flags = func_8010B990(actor, 0x325);
    hit_flags |= func_8010B990(actor, 0x4004);
    return hit_flags;
}

s32 func_80800AD0_chtntmineshoot(u8 *actor)
{
    // Matching: _pad and speed only exist for the match.
    s32 _pad;

    s32 hit_flags;
    f32 *speed;
    s32 flags_a;
    s32 flags_b;
    int state;
    u8 *data;
    data = func_80100094(actor, 0);
    hit_flags = 0;
    speed = &*(f32 *) ((s8 *) actor + 0x24);
    state = *(u8 *) ((s8 *) data + 0x14);
    switch (state) {
        case 4:
            break;

        case 1:
            flags_a = func_80800A1C_chtntmineshoot(actor);
            hit_flags = flags_a;
            if (flags_a & 8) {
                func_80800830_chtntmineshoot(actor, 3);
            }
            break;

        case 2:
            *(f32 *) ((s8 *) actor + 0x24) = *speed * 0.5f;
            flags_b = func_80800A1C_chtntmineshoot(actor);
            hit_flags = flags_b;
            if (flags_b & 8) {
                func_80800830_chtntmineshoot(actor, 4);
            }
            break;

        case 3:
            *(f32 *) ((s8 *) actor + 0x24) = *(f32 *) ((s8 *) actor + 0x24) * 0.5f;
            hit_flags = func_80800A1C_chtntmineshoot(actor);
            if (func_80101DDC(actor) != 0) {
                func_80800830_chtntmineshoot(actor, 4);
            }
    }

    return hit_flags;
}

int func_80800BCC_chtntmineshoot(actor)
int actor;
{
    u8 *data;
    data = func_80100094(actor, 0);
    data[1] = 0;
    data[4] = 0;
}

void func_80800BF4_chtntmineshoot(actor, state) Actor *actor;
s32 state;
{
    MineShootState *data;
    data = func_80100094(actor, 0);
    data->state = state;
    switch (state) {
        case 0:
            data->mode = 0;
            break;
        case 1:
            if (func_800DC090() & 1)
                data->mode = 1;
            else
                data->mode = 2;
            data->time = func_800DC0C0();
            break;
        case 2:
            data->mode = 3;
    }
}

// Warning flash: fades the actor color.
void func_80800C90_chtntmineshoot(actor) Actor *actor;
{
    u8 *data;
    f32 dt;
    f32 level;
    data = func_80100094(actor, 0);
    dt = func_800D8FF8();
    switch (data[4]) {
        case 2:
            *(f32 *) (data + 8) -= dt * 4.0f;
            if (*(f32 *) (data + 8) < 0.0f) {
                *(f32 *) (data + 8) = 0.0f;
                data[4] = 1;
            }
            break;
        case 1:
            *(f32 *) (data + 8) += dt * 4.0f;
            if (*(f32 *) (data + 8) > 1.0f) {
                *(f32 *) (data + 8) = 1.0f;
                data[4] = 2;
            }
            break;
        case 3:
            *(f32 *) (data + 8) += dt * 4.0f;
            if (*(f32 *) (data + 8) > 1.0f) {
                *(f32 *) (data + 8) = 1.0f;
                data[4] = 0;
            }
    }
    level = *(f32 *) (data + 8) * 224.0f;
    *((u8 *) actor + 0x98) = 255 - (s32) (level * 0.5f);
    *((u8 *) actor + 0x9A) = *((u8 *) actor + 0x99) = (s32) level + 31;
    *((u8 *) actor + 0x9B) = 255;
}

int chtntmineshoot_entrypoint_0()
{
    return (int) &D_80802690_chtntmineshoot;
}

void func_80800E10_chtntmineshoot(s32 actor)
{
    u8 *data = func_80100094(actor, 0);
    data[0xC] = func_800C2E04();
    func_800C330C(data[0xC], 3);
    func_800C431C(data[0xC], 0);
    _susubgame_entrypoint_11(0);
}

// Controller state change.
void func_80800E64_chtntmineshoot(actor, state) Actor *actor;
s32 state;
{
    Mass63TntState *data;
    void *player;
    s32 pad[2];
    s32 dialog_id;

    data = func_80100094(actor, 0);
    if (state != actor->unk70_10) {
        switch (state) {
            case 2:
                data->local_1 = 0;
                func_800D2498(0x102, data->local_0, 0);
                break;
            case 3:
                _gcfrontend_entrypoint_9(0x63);
                func_800CE8D8(0, (u32) actor->unk74_7, actor->unk74_7);
                func_800CE88C(0, 1);
                func_80101180(0x2BE, 10, 0);
                break;
            case 4:
                func_800FE820(1.0f);
                data->local_1 = 1;
                _susubgame_entrypoint_11(0);
                func_80801974_chtntmineshoot(actor, 0xFA2);
                break;
            case 5:
                data->local_1 = 2;
                data->local_3 = 0;
                _susubgame_entrypoint_11(0);
                break;
            case 7:
                _susubgame_entrypoint_11(0);
                func_800D284C(0xCC);
                func_800D284C(0x102);
                break;
            case 8:
                player = func_800F54E4();
                func_800F49D4(player, 0, 0);
                func_800F7B9C(player, 0x8F);
                func_800F7B9C(player, 0x62);
                func_800F7C58(player, 0x61, 0);
                func_80801974_chtntmineshoot(actor, func_800D211C(0x95) ? 0xFB3 : 0xCEC);
                func_800F7F98(func_800F54E4(), 1);
                break;
            case 9:
                data->local_1 = 0;
                data->local_2 = 0.0f;
                func_800D2498(0xCC, (s32) data->local_2, 0);
                func_800D2498(0x102, data->local_0, 0);
                func_80101180(0x2BE, 10, 0);
                break;
            case 11:
                switch (func_800D2054(1, 0x95, (s32) data->local_2)) {
                    case -1:
                        dialog_id = 0xFB6;
                        break;
                    case 0:
                        dialog_id = 0xFB5;
                        break;
                    case 1:
                        dialog_id = 0xFB4;
                        break;
                }
                func_80801974_chtntmineshoot(actor, dialog_id);
                break;
            case 10:
                data->local_3 = 0;
                break;
            case 12:
                func_80801974_chtntmineshoot(actor, 0xCEB);
        }
        func_80101FDC(actor, state);
    }
}

void func_80801128_chtntmineshoot(Actor *actor)
{
    f32 time_left;
    f32 value;

    time_left = func_800CEA60(0);
    if (time_left > 10.0f) {
        value = func_800F10B4(time_left, actor->unk74_7, 0.0f, 1.0f, 1.4f);
    } else {
        value = func_800F10B4(time_left, 10.0f, 0.0f, 1.4f, 1.55f);
    }
    func_800FE820(value);
}

void func_808011D4_chtntmineshoot(Actor *actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 2:
            func_800D24E8(0x102, *(s32 *) data, 0);
            break;
        case 3:
            func_800D24E8(0x102, *(s32 *) data, 0);
            func_80801128_chtntmineshoot(actor);
            if (func_800CEAD0(0))
                func_80800E64_chtntmineshoot(actor, 5);
            break;
        case 5:
            func_80801318_chtntmineshoot(actor);
            break;
        case 9:
            *(f32 *) (data + 8) =
                func_800F13F0(*(f32 *) (data + 8) + func_800D8FF8(), 999.0f);
            func_800D2498(0x102, *(s32 *) data, 0);
            func_800D2498(0xCC, (s32) *(f32 *) (data + 8), 0);
            break;
        case 11:
            func_800D2498(0xCC, (s32) *(f32 *) (data + 8), 0);
            break;
        case 10:
            func_8080146C_chtntmineshoot(actor);
    }
}

void func_80801318_chtntmineshoot(actor) Actor *actor;
{
    MineCountdown1570 *data;
    f32 player_pos[3];

    data = func_80100094(actor, 0);
    func_800F5A00(func_800F54E4(), player_pos);
    switch (data->local_1) {
        case 0:
            func_800C35E8(data->local_0, actor->position);
            func_800C301C(data->local_0, 0x414);
            func_800C3058(data->local_0, 0x7FFF);
            func_800C3BDC(data->local_0);
            actor->unk58 = 1.0f;
            data->local_1 = 1;
            break;
        case 1:
            if (func_800D9078(&actor->unk58)) {
                func_800C3CE8(data->local_0);
                func_80101180(0x2BE, 5, 0);
                func_80801974_chtntmineshoot(actor, 0xFA3);
                data->local_1 = 2;
            }
            break;
        case 2:
            func_80800078_chtntmineshoot(NULL, 0.95f);
            func_80800188_chtntmineshoot(NULL);
            actor->unk58 = func_800DC178(0.67f, 1.0f);
            data->local_1 = 3;
            break;
        case 3:
            if (func_800D9078(&actor->unk58))
                data->local_1 = 2;
    }
}

void func_8080146C_chtntmineshoot(actor) Actor *actor;
{
    u8 *data;
    f32 player_pos[3];
    data = func_80100094(actor, 0);
    func_800F5A00(func_800F54E4(), player_pos);
    switch (*(u32 *) (data + 0x10)) {
        case 0:
            func_800C35E8(data[0xC], actor->position);
            func_800C301C(data[0xC], 0x414);
            func_800C3058(data[0xC], 0x7FFF);
            func_800C3BDC(data[0xC]);
            actor->unk58 = 1.0f;
            *(u32 *) (data + 0x10) = 1;
            *(f32 *) (data + 0x14) = 5.0f;
            break;
        case 1:
            if (func_800D9078(&actor->unk58)) {
                func_800C3CE8(data[0xC]);
                func_80101180(0x2BE, 5, 0);
                *(u32 *) (data + 0x10) = 2;
            }
            break;
        case 2:
            func_80800078_chtntmineshoot(0, 0.95f);
            func_80800188_chtntmineshoot(0);
            actor->unk58 = func_800DC178(0.67f, 1.0f);
            *(u32 *) (data + 0x10) = 3;
            break;
        case 3:
            if (func_800D9078((f32 *) (data + 0x14))) {
                func_80800078_chtntmineshoot(0, 0.95f);
                func_80800150_chtntmineshoot(actor);
                *(u32 *) (data + 0x10) = 4;
                actor->unk58 = 1.0f;
            } else if (func_800D9078(&actor->unk58)) {
                *(u32 *) (data + 0x10) = 2;
            }
            break;
        case 4:
            if (func_800D9078(&actor->unk58)) {
                func_80800E64_chtntmineshoot(actor, 0xC);
            }
    }
}

int func_80801604_chtntmineshoot(s32 actor)
{
    Actor *data;
    data = func_80100094(actor, 0);
    _susubgame_entrypoint_11(0);
    func_800D284C(0x102);
    if (*(u8 *) ((char *) data + 0xC) != 0) {
        func_800C2FDC(*(u8 *) ((char *) data + 0xC));
        *(u8 *) ((char *) data + 0xC) = 0;
    }
}

s32 func_80801658_chtntmineshoot(Actor **actor_ref)
{
    Actor *actor;
    Unk80132ED0 *unk_0;
    Prop *found[20];
    s32 count;
    s32 i;

    actor = *actor_ref;
    unk_0 = actor->unk0;
    if (!func_800D0A9C(0xF, 1) || func_800D395C()) {
        count = _gccubesearch_entrypoint_9(0x2BA, found, 20);
    } else {
        count = 0;
    }
    for (i = 0; i < count; i++) {
        func_801085CC(0x2BE, found[i], found[i]->FlagOrRotation);
    }
    *actor_ref = func_80106790(unk_0);
    return count;
}

s32 func_80801714_chtntmineshoot(Actor *actor, s32 event, s32 event_arg)
{
    s32 *remaining;
    s32 count_a;
    s32 count_b;
    s32 skip_state;
    s32 end_state;
    s32 player;

    remaining = func_80100094(actor, 0);
    switch (event) {
        case 0x49:
            if (func_800D395C()) {
                count_a = func_80801658_chtntmineshoot(&actor);
                *(s32 *) func_80100094(actor, 0) = count_a;
                func_80800E64_chtntmineshoot(actor, 8);
            } else if (!func_800D0A9C(0xF, 1)) {
                count_b = func_80801658_chtntmineshoot(&actor);
                *(s32 *) func_80100094(actor, 0) = count_b;
                func_80800E64_chtntmineshoot(actor, 2);
            } else {
                *remaining = 0;
            }
            break;
        case 5:
            skip_state = func_800D395C() ? 0xA : 5;
            func_80800E64_chtntmineshoot(actor, skip_state);
            player = func_800F54E4();
            func_800F7F98(player, 1);
            break;
        case 0x4F:
            if (--*remaining) {
                if (!func_800D395C() && actor->unk70_10 == 2)
                    func_80800E64_chtntmineshoot(actor, 3);
                if (actor->unk70_10 == 3)
                    func_800FC660(0xE);
            } else {
                end_state = func_800D395C() ? 0xB : 4;
                func_800FC660(0x10);
                func_80800E64_chtntmineshoot(actor, end_state);
            }
            break;
        case 0x30:
            return func_80801A18_chtntmineshoot(actor, ((s16 *) &event_arg)[0],
                                                ((s16 *) &event_arg)[1]);
        case 0x2E:
            func_80801A54_chtntmineshoot(actor, ((s16 *) &event_arg)[0], ((s16 *) &event_arg)[1]);
            break;
        case 0x9F:
            func_80800E64_chtntmineshoot(actor, 7);
            break;
        case 0x96:
            if (!func_800D395C())
                return 0;
            func_80800E64_chtntmineshoot(actor, 0xC);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80801974_chtntmineshoot(Actor *actor, s32 dialog_id)
{
    s32 unk_0;

    unk_0 = 7;
    switch (dialog_id) {
        case 0xFA2:
        case 0xFA3:
        default:
            func_800F7F98(func_800F54E4(), 1);
            break;
        case 0xCEC:
        case 0xFB3:
            unk_0 = 0x23;
            break;
        case 0xCEB:
            unk_0 = 0x144;
        case 0xFA4:
            break;
    }
    _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, unk_0, 0, 0x3F);
    return 1;
}

int func_80801A18_chtntmineshoot(actor, dialog_id, param_2)
s32 actor;
s32 dialog_id;
s32 param_2;
{
    if (dialog_id == 0xFB3) {
        return func_800D211C(0x95);
    }
    return 0;
}

void func_80801A54_chtntmineshoot(actor, dialog_id, answer) Actor *actor;
s32 dialog_id;
s32 answer;
{
    switch (dialog_id) {
        case 0xFA3:
            func_80800078_chtntmineshoot(0, 0.95f);
            func_80800150_chtntmineshoot(actor);
            func_800A7AD4(1, 5);
            _gcgoto_entrypoint_1(0x163, 3);
            break;
        case 0xFA2:
            _glcutDll_entrypoint_6(0x163, 0x18);
            break;
        case 0xFB3:
            func_80801974_chtntmineshoot(actor, 0xCEC);
            break;
        case 0xCEC:
            func_800F7F98(func_800F54E4(), 0);
            func_80800E64_chtntmineshoot(actor, 9);
            break;
        case 0xFB4:
        case 0xFB5:
        case 0xFB6:
            func_80800E64_chtntmineshoot(actor, 0xC);
            break;
        case 0xCEB:
            func_800F7F98(func_800F54E4(), 0);
            if (answer > 0)
                _gcfrontend_entrypoint_11();
            else
                _gcfrontend_entrypoint_10();
    }
}

int chtntmineshoot_entrypoint_1()
{
    return &D_808026D8_chtntmineshoot;
}

void func_80801BA0_chtntmineshoot(void)
{
    Vec3f pos = D_80802720_chtntmineshoot;
    func_800BBCB8(pos.f, 0, 1.0f, 2, D_8080272C_chtntmineshoot);
    func_800E1610(0, 20.0f, 0.9f, pos.f);
}

void func_80801C10_chtntmineshoot(s32 arg0)
{
}

void func_80801C18_chtntmineshoot(s32 arg0)
{
}

// Entrance trigger: puts the player into first-person mode.
void func_80801C20_chtntmineshoot(Actor *actor)
{
    if (!((MineShootFlags35 *) actor)->local_0) {
        ((MineShootFlags35 *) actor)->local_0 = 1;
        if (actor->unk70_10 != 3) {
            switch (func_800EA090()) {
                case 3:
                    func_800C964C(6);
                    func_80801BA0_chtntmineshoot();
                    func_80800078_chtntmineshoot(0, 0.25f);
                    func_80101FDC(actor, 4);
                    _capod_entrypoint_13(actor->unk0, 0, 7, 0x2000);
                    break;
                case 2:
                    func_80101FDC(actor, 4);
                    _capod_entrypoint_13(actor->unk0, 0, 2, 0x2000);
                    break;
                case 1:
                    if (func_800C6E38(0x15) && func_800F5410(0) == 1 && !func_800DA9E4(0x6B9, 1)) {
                        func_80101FDC(actor, 2);
                        _capod_entrypoint_13(actor->unk0, 0, 5, 0x2020);
                        func_800F49D4(func_800F54E4(), _bsfirstp_entrypoint_18, 0);
                    }
            }
        }
    }
}

void func_80801D6C_chtntmineshoot(Actor *actor)
{
    func_80801C20_chtntmineshoot(actor);
    switch (actor->unk70_10) {
        case 2:
            break;
        case 3:
            if (func_800D9078(&actor->unk58)) {
                func_800D1000(0xF, 1, 0, 1, 0);
                func_80101FDC(actor, 1);
            }
        case 4:
            break;
    }
}

s32 func_80801DEC_chtntmineshoot(Actor *actor, s32 event, s32 event_arg)
{
    switch (event) {
        case 0xB:
            if (actor->unk70_10 == 4) {
                func_800F7F98(func_800F54E4(), 0);
                func_800F7B9C(func_800F54E4(), 0x73);
                func_80101FDC(actor, 1);
                if (!func_800D0A9C(0xF, 1)) {
                    if (func_800EA090() == 2) {
                        func_80801974_chtntmineshoot(actor, 0xFAB);
                    } else {
                        func_80801974_chtntmineshoot(actor, 0xFA4);
                    }
                }
            }
            return 3;
        case 0x49:
            if (_glcutDll_entrypoint_19(0x18)) {
                _capod_entrypoint_13(actor->unk0, 0, 0, 0x900);
                func_80101FDC(actor, 3);
                actor->unk58 = 0.15f;
                return 1;
            }
            break;
        case 0x2E:
            func_800F7F98(func_800F54E4(), 0);
            return 1;
        case 0x77:
            if (actor->unk70_10 == 2) {
                func_800F7B9C(event_arg, 0x73);
                func_80101FDC(actor, 1);
                _capod_entrypoint_14();
                func_800F7B9C(func_800F54E4(), 0x99);
                return 1;
            }
    }
    return 0;
}

int *chtntmineshoot_entrypoint_2()
{
    return &D_80802774_chtntmineshoot;
}

// Spawns the 5 debris pieces (actor 0x2C3) of an explosion.
void func_80801F90_chtntmineshoot(actor, kind) u8 *actor;
s32 kind;
{
    s32 i;
    s32 table_index;
    u8 *obj;
    f32 vec[3];
    u8 *spawned;
    MineEntry *base;
    MineEntry *entry;
    f32 angle;
    s32 *color_ptr;

    base = (MineEntry *) D_808027BC_chtntmineshoot;
    if (kind == 4) {
        table_index = 0;
    } else {
        table_index = 1;
    }
    base = (MineEntry *) ((u8 *) base + table_index * 0x60);
    entry = base;
    angle = *(f32 *) (*(u8 **) actor + 0x48);

    // Matching: the extra block and "entry = base + 1" are needed for the match.
    for (i = 0; i < 5;) {
        {
            spawned = func_801084B0(0x2C3, actor);
            color_ptr = (s32 *) (*(u8 **) actor + 0x98);
            *(s32 *) (spawned + 0x98) = *color_ptr;
            func_80101FDC(spawned, entry->f00);
            func_80103140(spawned, entry->f06, *(u16 *) (*(u8 **) spawned + 0x16));
            *(f32 *) (spawned + 0x34) = entry->f08;
            *(f32 *) (spawned + 0x54) = entry->f0C;
            *(f32 *) (spawned + 0x48) = func_800DC178(-30.0f, 30.0f) + angle;
            angle = angle + 72.0f;
            func_800EEB9C(vec, *(f32 *) (spawned + 0x48), entry->f10);
            vec[1] = entry->f14;
            func_800EF04C(spawned + 4, vec);
            vec[1] = 0.0f;
            func_800EFA98(spawned + 0x28, vec, func_800DC178(entry->f18, entry->f1C));
            *(f32 *) (spawned + 0x2C) = func_800DC178(entry->f20, entry->f24);
            *(f32 *) (spawned + 0x50) = func_800DC178(entry->f28, entry->f2C);
            entry = base + 1;
            i++;
        }
    }
}

void func_80802140_chtntmineshoot(s32 arg0)
{
}

void func_80802148_chtntmineshoot(s32 actor, s32 param_1)
{
    u8 *color;
    color = (u8 *) actor + 0x98;
    func_800DF5D8(*color, *(color + 1), *(color + 2), *(color + 3));
    func_80101870((void *) actor, param_1);
    func_80802320_chtntmineshoot((void *) actor);
}

int func_80802198_chtntmineshoot(s32 actor)
{
    s32 hit;
    hit = func_808021C4_chtntmineshoot(actor);
    func_808022A8_chtntmineshoot(actor, hit | 0); // Matching: "| 0" is needed for the match.
}

s32 func_808021C4_chtntmineshoot(actor)
Actor *actor;
{
    s32 hit;
    f32 new_pos[3];
    f32 dt;
    f32 step[3];
    f32 normal[3];

    dt = func_800D8FF8();
    *(f32 *) ((u8 *) actor + 0x2C) += *(f32 *) ((u8 *) actor + 0x34) * dt;
    if (*(f32 *) ((u8 *) actor + 0x2C) < actor->unk54) {
        *(f32 *) ((u8 *) actor + 0x2C) = actor->unk54;
    }
    func_800EFA20(step, (f32 *) ((u8 *) actor + 0x28), dt);
    func_800EE780(new_pos, actor->position, step);
    hit = func_800FAB50(actor->position, new_pos, normal, 0x024200A1, 15.0f);
    if (hit != 0) {
        func_800F059C((f32 *) ((u8 *) actor + 0x28), (f32 *) ((u8 *) actor + 0x28), normal);
    }
    func_800EE7F8(actor->position, new_pos);
    return hit != 0 ? 1 : 0;
}

void func_808022A8_chtntmineshoot(actor, hit) Actor *actor;
s32 hit;
{
    f32 angle;
    if (hit) {
        if (func_800F1EA4((f32 *) &actor->actorData[4], &angle))
            actor->rotation[1] = angle;
        func_800EF334((f32 *) &actor->actorData[4], 0.8f);
        _subaddiefade_entrypoint_3(actor);
    }
    actor->rotation[0] += actor->unk50 * func_800D8FF8();
}

void func_80802320_chtntmineshoot(actor) Actor *actor;
{
    f32 pos[3];
    s32 fx_a;
    s32 fx_b;

    switch (actor->unk70_10) {
        case 5:
            if (!(func_800DC090() & 3) &&
                _subaddieskeleton_entrypoint_2(actor->unk0, 4, pos)) {
                fx_a = func_800BABB8(0, pos, NULL, 1.0f, &D_8080287C_chtntmineshoot);
                func_800BA3FC(fx_a, func_8001211C() & 1 ? 0x9E3 : 0x9E2);
                func_800BA22C(fx_a, 1);
            }
            break;
        case 3:
            if ((func_800DC090() & 0xF) < 3U &&
                _subaddieskeleton_entrypoint_2(actor->unk0, 4, pos)) {
                fx_b = func_800BABB8(0, pos, NULL, 1.0f, &D_808028C4_chtntmineshoot);
                func_800BA4B0(fx_b, *((u8 *) actor + 0x9B));
                func_800BA22C(fx_b, 1);
            }
    }
}

int chtntmineshoot_entrypoint_3()
{
    return D_808028E4_chtntmineshoot;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80802550_chtntmineshoot[12] = {0x0,        0x0,       0x3F800000, 0x41D000A,
                                     0x3F800000, 0x41D004A, 0x3F800000, 0x41D000A,
                                     0x3F800000, 0x41D0000, 0x3F800000, 0x41D0000};
u8 D_80802580_chtntmineshoot[16] = {0x0, 0x13, 0x4, 0xD5, 0x0, 0x16, 0x36, 0xB0,
                                    0x0, 0x1,  0x1, 0x2C, 0x7, 0xD0, 0x0,  0x0};
s32 D_80802590_chtntmineshoot[3] = {0x130416, 0x1012C, 0x7D00000};
s32 D_8080259C_chtntmineshoot[3] = {0x1304A2, 0x1012C, 0x7D00000};
int D_808025A8_chtntmineshoot[9] = {0xC0050,  0x2303C0, 0x2B01E0, 0x2100015, 0xB300CC,
                                    0x1D09BB, 0x180000, 0x90C00,  0xC000000};
s16 D_808025CC_chtntmineshoot[8] = {0x13, 0x413, 0x18, 0x1, 0x12C, 0xBB8, 0x0, 0x0};
s32 D_808025DC_chtntmineshoot[7] = {0x20306,   0x2070016, 0x7D000015, 0x190280,
                                    0x1000013, 0x4A9000A, 0x1000000};
u8 D_808025F8_chtntmineshoot[76] = {
    0x0, 0x1D, 0x9,  0xCA, 0x0, 0x18, 0x0, 0x0, 0x0, 0xA,  0xC, 0x80, 0x14, 0x0,  0x0,  0x2C,
    0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x1E, 0x0, 0x0,  0x0,  0xA,  0xFF, 0x38,
    0x0, 0x0,  0xFF, 0x38, 0x0, 0xC8, 0x0, 0x0, 0x0, 0xC8, 0x0, 0x16, 0x0,  0x10, 0x0,  0x22,
    0x1, 0x0,  0x2,  0x80, 0x2, 0x0,  0x5, 0x0, 0x0, 0x15, 0x0, 0x19, 0x0,  0xE6, 0x0,  0x1E,
    0x0, 0x32, 0x0,  0x32, 0x0, 0x2B, 0x3, 0x0, 0x3, 0x0,  0x0, 0x0};
u8 D_80802644_chtntmineshoot[76] = {
    0x0, 0x1D, 0x9,  0xBB, 0x0, 0x18, 0x0, 0x0, 0x0, 0x9,  0xC, 0x0,  0xC, 0x0,  0x0,  0x2C,
    0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x1E, 0x0, 0x0,  0x0, 0xA,  0xFF, 0x38,
    0x0, 0x0,  0xFF, 0x38, 0x0, 0xC8, 0x0, 0x0, 0x0, 0xC8, 0x0, 0x16, 0x0, 0x10, 0x0,  0x22,
    0x1, 0x0,  0x2,  0x80, 0x2, 0x0,  0x5, 0x0, 0x0, 0x15, 0x0, 0x19, 0x0, 0xE6, 0x0,  0x1E,
    0x0, 0x32, 0x0,  0x32, 0x0, 0x2B, 0x3, 0x0, 0x3, 0x0,  0x0, 0x0};
int D_80802690_chtntmineshoot[18] = {0x16B02BE,
                                     0x8FC0001,
                                     (u32) &D_80802550_chtntmineshoot,
                                     (u32) func_80800280_chtntmineshoot,
                                     (u32) func_80105834,
                                     (u32) func_808006D0_chtntmineshoot,
                                     0x7D00000,
                                     0x3F800000,
                                     0x0,
                                     0x40023,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x240000,
                                     (u32) func_80800228_chtntmineshoot,
                                     (u32) func_80107C2C,
                                     -0x7FFFFBFC,
                                     (u32) func_808005AC_chtntmineshoot,
                                     0x0};
int D_808026D8_chtntmineshoot[18] = {0x15802BC,
                                     0x1,
                                     0x0,
                                     (u32) func_808011D4_chtntmineshoot,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80801604_chtntmineshoot,
                                     0x0,
                                     0x180000,
                                     (u32) func_80800E10_chtntmineshoot,
                                     (u32) func_80107C2C,
                                     -0x7FFFF9FE,
                                     (u32) func_80801714_chtntmineshoot,
                                     0x0};
Vec3f D_80802720_chtntmineshoot = {1e+02f, -25.0f, 3e+03f};
u8 D_8080272C_chtntmineshoot[72] = {
    0x0,  0x1D, 0x9,  0xDC, 0x0,  0x18, 0x0,  0x0,  0x0,  0x0,  0xF,  0x57, 0x12, 0xC7, 0x0,
    0x1,  0xFF, 0xEC, 0xFF, 0xEC, 0xFF, 0xCE, 0x0,  0x14, 0xFF, 0xD8, 0xFF, 0xCE, 0x0,  0x2C,
    0xFF, 0xEC, 0x0,  0x64, 0xFE, 0xD4, 0x0,  0x14, 0x0,  0xC8, 0xFE, 0x70, 0x0,  0x16, 0x2C,
    0x0,  0x0,  0x22, 0x1,  0x0,  0x1,  0xC2, 0x2,  0x80, 0x3,  0x0,  0x0,  0x15, 0x0,  0x28,
    0x0,  0xDC, 0x0,  0x2B, 0x4,  0x2,  0x4,  0x2,  0x0,  0x0,  0x0,  0x0};
int D_80802774_chtntmineshoot[18] = {0x15802BD,
                                     0x1,
                                     0x0,
                                     (u32) func_80801D6C_chtntmineshoot,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80801C18_chtntmineshoot,
                                     0x0,
                                     0x0,
                                     (u32) func_80801C10_chtntmineshoot,
                                     (u32) func_80107C2C,
                                     -0x7FFFFDFE,
                                     (u32) func_80801DEC_chtntmineshoot,
                                     0x0};
u8 D_808027BC_chtntmineshoot[192] = {
    0x0,  0x0,  0x0,  0x2, 0x0,  0x0,  0x8,  0x4B, 0xC4, 0x7A, 0x0, 0x0, 0xC3, 0xFA, 0x0, 0x0,
    0x42, 0x48, 0x0,  0x0, 0x42, 0x48, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0, 0x0,
    0x43, 0xFA, 0x0,  0x0, 0x43, 0xFA, 0x0,  0x0,  0x42, 0x34, 0x0, 0x0, 0x42, 0x34, 0x0, 0x0,
    0x0,  0x0,  0x0,  0x3, 0x0,  0x0,  0x8,  0x4C, 0xC4, 0x7A, 0x0, 0x0, 0xC3, 0xFA, 0x0, 0x0,
    0x41, 0xA0, 0x0,  0x0, 0x42, 0x48, 0x0,  0x0,  0x42, 0xC8, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0,
    0x43, 0x96, 0x0,  0x0, 0x43, 0xFA, 0x0,  0x0,  0x42, 0xB4, 0x0, 0x0, 0x43, 0x34, 0x0, 0x0,
    0x0,  0x0,  0x0,  0x4, 0x0,  0x0,  0x8,  0x4B, 0xC4, 0x7A, 0x0, 0x0, 0xC3, 0xFA, 0x0, 0x0,
    0x42, 0x48, 0x0,  0x0, 0x42, 0x48, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0, 0x0,
    0x44, 0x3B, 0x80, 0x0, 0x44, 0x3B, 0x80, 0x0,  0x43, 0x34, 0x0, 0x0, 0x43, 0x34, 0x0, 0x0,
    0x0,  0x0,  0x0,  0x5, 0x0,  0x0,  0x8,  0x4C, 0xC4, 0xFA, 0x0, 0x0, 0xC4, 0x7A, 0x0, 0x0,
    0x41, 0xA0, 0x0,  0x0, 0x42, 0x48, 0x0,  0x0,  0x43, 0x48, 0x0, 0x0, 0x43, 0xC8, 0x0, 0x0,
    0x43, 0xFA, 0x0,  0x0, 0x44, 0x9C, 0x40, 0x0,  0x43, 0x34, 0x0, 0x0, 0x43, 0xB4, 0x0, 0x0};
s32 D_8080287C_chtntmineshoot[18] = {0x1100015, 0x33,     0x2CFFE2, 0x3CFFE2, 0x1E0064, 0x1E001B,
                                     -0x13FFE2, 0xAFFF6,  0xFFF6,   0xA0000,  0xA0022,  0xF0019,
                                     0x23002E,  0x2B004C, 0x800015, 0x6600B3, 0x160004, 0x0};
s32 D_808028C4_chtntmineshoot[8] = {0x110001D, 0x9C90022, 0x330080, 0x190026,
                                    0x150000,  0x33002B,  0x420080, 0x0};
s32 D_808028E4_chtntmineshoot[19] = {0x15802C3,
                                     0x84C0001,
                                     0x0,
                                     (u32) func_80802198_chtntmineshoot,
                                     (u32) func_80105834,
                                     (u32) func_80802148_chtntmineshoot,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x40,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80802140_chtntmineshoot,
                                     (u32) func_80107C2C,
                                     -0x7FFFFBFE,
                                     0x0,
                                     0x0,
                                     0x0};
