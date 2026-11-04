#include "common.h"

extern int D_80801448_chtiptup[];
extern int D_80801490_chtiptup[];
extern int D_808014D8_chtiptup[];
extern f32 D_80801398_chtiptup[];
extern void _gcdialogcamera_entrypoint_3(f32 *, f32);
extern s32 D_80801570_chtiptup[];
extern s32 D_80801360_chtiptup[];
extern s32 _subaddiedialog_entrypoint_8(Actor *, f32[3], void *, void *, s32);
extern s32 _subaddiedialog_entrypoint_9(Actor *, s32, void *, s32);
extern void func_800D1000();
extern void func_800F82D4(void *param_0, s32 param_1);
extern void *func_800F54E4();
extern void func_80102424(Actor *param_0, s32 param_1);
extern s32 func_800DA298(s32 param_0);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
// Spawn bubble effect of the given kind between two points.
void func_80800614_chtiptup(f32 *, f32 *, s32, f32, void *);
extern s32 D_80801580_chtiptup[];
extern s32 D_808015B0_chtiptup[];
extern s32 D_808015C0_chtiptup[];
extern s32 D_808015CC_chtiptup[];
extern s32 D_808015DC_chtiptup[];
extern s32 D_808015EC_chtiptup[];
extern s32 D_80801600_chtiptup[];
extern void _capod_entrypoint_2();
extern void _gcdialogcamera_entrypoint_4(f32 *);
extern void _gcdialogcamera_entrypoint_5(f32 *);
typedef struct {
    u8 pad[0x95];
    u8 local_0 : 7;
    u8 local_1 : 1;
} TiptupFlags27;
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern int D_8080165C_chtiptup[];
extern int D_80801668_chtiptup[];
extern int D_80801674_chtiptup[];
extern int D_8080167C_chtiptup[];
extern u8 D_808016A0_chtiptup[];
extern u8 D_80801690_chtiptup[];
extern u8 D_808016AC_chtiptup[];
extern s32 func_800D9154(f32 *, f32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, void *, void *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_80801520_chtiptup[];
extern u8 D_8080152C_chtiptup[];
extern u8 D_8080154C_chtiptup[];
extern u8 D_80801558_chtiptup[];
extern u8 D_80801568_chtiptup[];
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern s32 func_80101DDC(Actor *);
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern s32 func_80105A5C(Actor *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern s32 func_8001210C(s32);
extern f32 func_80105AE8(Actor *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80105834(Actor *);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, void *);
extern s32 D_80801620_chtiptup[];
extern s32 D_8080162C_chtiptup[];
extern s32 D_80801638_chtiptup[];
extern s32 D_80801644_chtiptup[];
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern void func_80105A9C(Actor *, f32);
extern f32 func_800F3780(f32, s32 *, s32);
extern s32 func_800F4F34(s32, f32 *, f32, f32);
extern s32 _chbadshad_entrypoint_1(Actor *, f32 *, f32);
s32 func_80800534_chtiptup();
int func_80800578_chtiptup();
int func_80800774_chtiptup();
int func_808007CC_chtiptup();
void func_80800808_chtiptup();
int func_808008B4_chtiptup();
void func_80800934_chtiptup();
extern void func_80101870(), func_80102EC0(), func_80107C2C(), func_80108ED0(),
    func_80800C70_chtiptup();

int chtiptup_entrypoint_0()
{
    return (int) &D_80801448_chtiptup;
}

int chtiptup_entrypoint_1()
{
    return (int) &D_80801490_chtiptup;
}

int *chtiptup_entrypoint_2()
{
    return &D_808014D8_chtiptup;
}

void func_80800694_chtiptup();

void func_808004C4_chtiptup();

void func_80800024_chtiptup(Actor *actor)
{
    u8 *sfx_table;
    f32 bubble_pos[3];

    _sudeflect_entrypoint_1(actor->position, 250.0f, 0.0f, 70.0f, 0xE);
    func_80800694_chtiptup(actor);
    switch (actor->unk70_10) {
        case 1:
            func_808004C4_chtiptup(actor);
            break;
        case 4:
            if (_subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801520_chtiptup,
                                                 0.7f)) {
                func_80800614_chtiptup(actor->position, actor->position, 8, 1.5f,
                                       D_8080152C_chtiptup);
            }
            if (func_80101DDC(actor)) {
                func_80102424(actor, 5);
                _subaddieDll_entrypoint_4(actor, 1);
            }
            break;
        case 5:
            if (!func_80105A5C(actor) && func_800D9154(&actor->unk58, 2.4f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801558_chtiptup);
            }
            if (!func_8001210C(3)) {
                sfx_table = (func_80105AE8(actor) < 0.45f) ? NULL : D_80801568_chtiptup;
                func_800EE7F8(bubble_pos, actor->position);
                func_800EF1B8(bubble_pos, actor->rotation[1], 5e+01f);
                bubble_pos[1] -= 40.0f;
                func_80800614_chtiptup(actor->position, bubble_pos, 3, 1.0f, sfx_table);
            }
            func_80105834(actor);
            _subaddieaudioloop_entrypoint_4(actor, actor->position, func_80105A5C(actor) == 0,
                                            D_8080154C_chtiptup);
    }
}

void func_80800200_chtiptup(Actor *actor)
{
    s32 *found;

    if ((func_800D0A9C(0x20, 1) != 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800FFAB0(actor);
        return;
    }
    actor->unk6C_0 = _subaddiesect_entrypoint_1(actor);
    _subaddiesect_entrypoint_2(actor, actor->unk6C_0, 0);
    found = _subaddiefind_entrypoint_2(0x359, 0);
    if (found != 0) {
        actor->unk3C = (Unk80132ED0 *) *found;
    }
    func_80105A9C(actor, 4e+02f);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(actor, 6);
    }
}

s32 func_808002C8_chtiptup(Actor *this)
{
    u8 value = _subaddieaudioloop_entrypoint_3(*(u8 *) ((char *) this + 40));
    *(u8 *) ((char *) this + 40) = value;
}

int func_808002F4_chtiptup(Actor *actor, s32 msg, s32 msg_data)
{
    s32 stage;
    s32 flag_set;
    switch (msg) {
        case 0x2E:
            func_80800578_chtiptup(actor, ((s16 *) &msg_data)[0], ((s16 *) &msg_data)[1]);
            break;
        case 0x2F:
            func_80800534_chtiptup(actor, ((s16 *) &msg_data)[0], ((s16 *) &msg_data)[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80801398_chtiptup, actor->scale);
            break;
        case 0x57:
            return func_80800774_chtiptup(actor, msg_data & 0xFFFF,
                                          (u32) (msg_data & 0xFFFF0000) >> 16);
        case 0xB:
            if (msg_data == 4) {
                func_808007CC_chtiptup(actor);
                func_800FFA88(actor->unk3C);
                func_800FFAB0(actor);
                return 4;
            }
            return 3;
        case 0x95:
            ((u8 *) actor)[0x28] = 0;
            break;
        case 0xB8:
            stage = msg_data & 0xFFFF;
            flag_set = func_800DA298(0xBD);
            switch (stage) {
                case 1:
                    return flag_set ? 0xFF8 : 0xFF7;
                case 2:
                    return flag_set ? 0xFF8 : 0x104F;
                case 3:
                    return flag_set ? 0xFF8 : 0xFF7;
            }
        default:
            return 0;
        case 0x29:
        case 0x2A:
            break;
    }
    return 1;
}

void func_808004C4_chtiptup(Actor *actor)
{
    s32 choice;

    choice = _subaddiedialog_entrypoint_8(actor, actor->position, &D_80801570_chtiptup,
                                           &D_80801360_chtiptup, 7);
    if (choice != 0) {
        if (_subaddiedialog_entrypoint_9(actor, choice, &D_80801360_chtiptup, 7) != 3) {
            func_80800808_chtiptup(actor, 2, 0);
        }
    }
}

s32 func_80800534_chtiptup(s32 actor, s32 unk_1, s32 unk_2)
{
    func_80800934_chtiptup(actor, 0x40, 0);
    func_800D1000(0x20, 1, 0, 0, 0);
}

int func_80800578_chtiptup(actor, dialog_id, unk_2)
Actor *actor;
s32 dialog_id;
s32 unk_2;
{
    if (dialog_id == 0xFFA) {
        func_800F82D4(func_800F54E4(actor), 0);
        func_80102424(actor, 4);
        func_808008B4_chtiptup(actor, 4, 0x30);
    } else {
        if (*(s32 *) ((char *) actor + 0x2C) != 0) {
            func_808007CC_chtiptup(actor);
        }
        func_80102424(actor, func_800DA298(0xBE) ? 3 : 1);
    }
}

// Spawn bubble effect of the given kind between two points.
void func_80800614_chtiptup(f32 *start, f32 *end, s32 kind, f32 speed, void *extra)
{
    s32 handle;

    handle = func_800B53A4(kind);
    func_800BABB8(handle, start, end, speed, &D_80801580_chtiptup);
    if (extra != 0) {
        func_800BABB8(handle, start, end, speed, extra);
    }
    func_800BA22C(handle, kind);
}

void func_80800694_chtiptup(u8 *actor)
{
    switch (func_801022E4()) {
        case 0x18A:
            _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_808015B0_chtiptup, 0.7f);
            _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_808015C0_chtiptup, 0.35f);
            _subaddieaudioquick_entrypoint_4(actor, actor + 4, &D_808015CC_chtiptup,
                                             &D_808015DC_chtiptup);
            break;
        case 0x189:
            if (func_80101E4C(actor, &D_80801600_chtiptup) != 0) {
                if (actor[0x28] == 0) {
                    actor[0x28] = _subaddieaudioquick_entrypoint_1(actor, actor + 4);
                }
                func_800C4350(actor[0x28], actor + 4, &D_808015EC_chtiptup);
            }
    }
}

int func_80800774_chtiptup(actor, unk_1, unk_2)
Actor *actor;
s32 unk_1;
s32 unk_2;
{
    if (_gcdialogcamera_entrypoint_0(unk_1 | 0, unk_2 | 0)) {
        if (*(s32 *) ((char *) actor + 0x2C) != 2) {
            func_80800808_chtiptup(actor, 2, 1);
        }
        return 2;
    }
    return 1;
}

int func_808007CC_chtiptup(actor)
Actor *actor;
{
    s32 *ptr = (s32 *) ((char *) actor + 0x2C);
    if (*ptr != 0) {
        _capod_entrypoint_3(0, actor);
        *ptr = 0;
    }
}

void func_80800808_chtiptup(actor, unk_1, unk_2) Actor *actor;
s32 unk_1;
s32 unk_2;
{
    switch (actor->actorData[5]) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 0x16, 0);
        case 1:
        case 3:
            _capod_entrypoint_8(1);
            actor->actorData[5] = 2;
            _gcdialogcamera_entrypoint_3(D_80801398_chtiptup, actor->scale);
            _gcdialogcamera_entrypoint_4(actor->position);
            _gcdialogcamera_entrypoint_5(actor->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(unk_1, unk_2);
    }
}

int func_808008B4_chtiptup(actor, unk_1, unk_2)
Unk80132ED0 *actor;
s32 unk_1;
s32 unk_2;
{
    Unk80132ED0 *camera_owner;
    s32 state;
    camera_owner = actor;
    state = *(s32 *) ((char *) actor + 0x2C);
    switch (state) {
        case 0:
            _capod_entrypoint_2(*(s32 *) ((char *) actor + 0x0), 0x16, unk_2, actor);

        case 2:
        case 3:
            *(s32 *) ((char *) actor + 0x2C) = 1;

        case 1:
            _capod_entrypoint_6(*(s32 *) ((char *) camera_owner + 0x0), unk_1, unk_2, actor);
    }
}

void func_80800934_chtiptup(actor, unk_1, unk_2) s32 *actor;
s32 unk_1;
s32 unk_2;
{
    s32 state;

    state = *(s32 *) ((char *) actor + 0x2C);

switch (state) {
    case 0:
        _capod_entrypoint_2(*(s32 *) ((char *) actor + 0), 0x16, unk_2, actor);

    case 1:;
    case 2:
        *(s32 *) ((char *) actor + 0x2C) = 3;

    case 3:
        _capod_entrypoint_20(*(s32 *) ((char *) actor + 0), unk_1, unk_2, actor);
}

}

void func_80800E9C_chtiptup();

void func_808009B4_chtiptup(Actor *actor)
{
    Actor *partner;
    Actor *partner_b;

if (_subaddieskeleton_entrypoint_3(actor->unk0, 4, (f32 *) actor->actorData)) {
    _chbadshad_entrypoint_1(actor, (f32 *) actor->actorData, 0.8f);
}

switch (actor->unk70_10) {
    case 1:
        return;
    case 2:
        func_80800E2C_chtiptup(actor);
        if (func_80101DDC(actor)) {
            func_80102424(actor, 3);
            func_8010A590(actor);
            partner = func_80106790(actor->unk3C);
            func_800F82D4(func_800F54E4(), 0);
            _subaddiedialog_entrypoint_11(partner->unk0, 0xFF9, 0xC, partner->position, 0x54);
        }
        break;
    case 3:
    case 7:
        if (func_80101E14(actor, 0.2f)) {
            actor->unk64_19 = (actor->unk64_19 ^ 1) & 1;
            if (actor->unk64_19) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80801620_chtiptup);
            }
        }
        break;
    case 4:
        _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_8080162C_chtiptup, 0.4f);
        if (func_80101DDC(actor)) {
            func_80102424(actor, 5);
            _subaddieDll_entrypoint_4(actor, 1);
            func_800DA544(0xBE);
            partner_b = func_80106790(actor->unk3C);
            func_80102424(partner_b, 3);
            _subaddieaudioquick_entrypoint_2(partner_b, partner_b->position, &D_80801638_chtiptup);
            func_80800808_chtiptup(partner_b, 3, 1);
            _subaddiedialog_entrypoint_11(partner_b->unk0, 0xFFA, 0x46, partner_b->position, 0x54);
            _subaddieDll_entrypoint_4(partner_b, 1);
        }
        break;
    case 5:
        func_80800E9C_chtiptup(actor);
        func_80105A9C(actor,
                      func_800F3780(func_80101F24(actor), D_80801644_chtiptup, 3) * 200.0f);
        func_80105854(actor);
        break;
    case 6:
        func_80800E2C_chtiptup(actor);
        if (func_80101DDC(actor)) {
            func_80102424(actor, 7);
        }
}

if (func_800F52B8(func_800F54E4(), actor->unk0) != 1) {
    func_800F4F34(func_800F54E4(), (f32 *) actor->actorData, 0.0f, 30.0f);
}

}

void func_80800C70_chtiptup(actor) Actor *actor;
{
    if (func_800DA298(0xBE) && !_glcutDll_entrypoint_20()) {
        func_800FFAB0(actor);
    } else {

actor->unk6C_0 = _subaddiesect_entrypoint_1(actor);
_subaddiesect_entrypoint_2(actor, actor->unk6C_0, 0);

if (_glcutDll_entrypoint_20()) {
    func_80102424(actor, 6);
} else if (func_800DA298(0xBD)) {

func_80102424(actor, 3);
func_8010A590(actor);
} else {
func_80102424(actor, 1);
func_80103110(actor, 0);
actor->unk64_16 = 0;
}
func_80105BAC(actor);
((TiptupFlags27 *)actor)->local_1 = 1;
}
}

s32 func_80800D78_chtiptup(Actor *actor, s32 msg, s32 msg_data)
{
    Actor *found;

    switch (msg) {
        case 0x40:
        func_800F8300(func_800F54E4(), 2, actor->position);
        func_8010A570(actor);
        func_80102424(actor, 4);
        _subaddieDll_entrypoint_4(actor, 1);
        func_800FC660(0xE);
        return 1;
        case 0x95:
        found = _subaddiefind_entrypoint_2(0x358, 0);
        if (found) {
            actor->unk3C = found->unk0;
        }
        break;
        default:
        return 0;
    }
    return 1;
}

// Matching: the line breaks in this function are needed for the match.
int func_80800E2C_chtiptup(s32 actor)
{
    s32 pos;
    pos = actor + 0x18; _subaddieaudioquick_entrypoint_3(actor, pos, &D_8080165C_chtiptup, 0.02f);
    _subaddieaudioquick_entrypoint_3(actor, pos, &D_80801668_chtiptup, 0.14f);
    _subaddieaudioquick_entrypoint_4(actor, pos, &D_80801674_chtiptup, &D_8080167C_chtiptup);
}

void func_80800E9C_chtiptup(Actor *actor)
{
    f32 mid_pos[3];
    f32 left_pos[3];
    f32 right_pos[3];
    if (func_800D9154(&actor->unk58, 2.2f))
        _subaddieaudioquick_entrypoint_2(actor, actor->actorData, D_808016A0_chtiptup);
    if (_subaddieaudioquick_entrypoint_3(actor, actor->actorData, D_80801690_chtiptup, 0.1f)) {
        func_800EFA4C(mid_pos, *(f32 *)actor->actorData, actor->position[1], *(f32 *)(actor->actorData + 2));
        func_800EFA4C(left_pos, *(f32 *)actor->actorData, actor->position[1], *(f32 *)(actor->actorData + 2));
        func_800EFA4C(right_pos, *(f32 *)actor->actorData, actor->position[1], *(f32 *)(actor->actorData + 2));
        func_800EF1B8(mid_pos, actor->rotation[1], 20.0f);
        func_800EF1B8(left_pos, actor->rotation[1] + 70.0f, 10.0f);
        func_800EF1B8(right_pos, actor->rotation[1] - 70.0f, 10.0f);
        mid_pos[1] -= 10.0f;
        func_80800614_chtiptup(left_pos, mid_pos, 1, 0.5f, D_808016AC_chtiptup);
        func_80800614_chtiptup(right_pos, mid_pos, 1, 0.5f, D_808016AC_chtiptup);
    }
}

void func_80800FE8_chtiptup(u8 *actor) {
    s32 player;

    if (_subaddieskeleton_entrypoint_2(*(s32 *)((s8 *)actor + 0), 4, actor + 0x18) != 0) {
        _chbadshad_entrypoint_1(actor, actor + 0x18, 1.0f);
    }
    switch ((u32)(*(u16 *)((s8 *)actor + 0x72)) >> 0xA) {
        case 1:
        player = _plsu_entrypoint_3(*(s32 *)((s8 *)actor + 0));
        if (player != -1) {
            func_800F7BC8(player, 0x53, *(s32 *)((s8 *)actor + 0));
        }
        return;
        case 2:
        if (func_80101DDC(actor) != 0) {
            func_80102424(actor, 3);
            func_800DA544(0xBD);
        }
        break;
        case 3:
        func_800F4F34(func_800F54E4(), actor + 0x18, 3e+01f, 8e+01f);
    }
}

void func_808010CC_chtiptup(Actor *actor)
{
    u16 sect_bits;
    s32 sect;
    sect_bits = ((*((u16 *) (((char *) actor) + 0x6E))) & 0xFE00) | ((u16) (_subaddiesect_entrypoint_1() & 0x1FF));
    *((u16 *) (((char *) actor) + 0x6E)) = sect_bits;
    sect = (*((s32 *) (((char *) actor) + 0x6C))) & 0x1FF;
    _subaddiesect_entrypoint_2(actor, sect, 0);
    if (_glcutDll_entrypoint_20() != 0)
    {
        func_80102424(actor, 4);
        return;
    }
    if (func_800DA298(0xBD) != 0)
    {
        func_8010A570(actor);
        func_80102424(actor, 3);
        return;
    }
    func_8010A63C(actor);
    func_80102424(actor, 1);
}

s32 func_80801180_chtiptup(Actor *actor, s32 msg, s32 msg_data)
{
    Actor *partner;
    Actor *partner_b;
    f32 target_pos[3];
    f32 *pos;
    Actor *found;
    switch (msg) {
        case 0x18:
        pos = actor->position;
        func_800EE7F8(target_pos, pos);
        func_800EF1B8(target_pos, actor->rotation[1] + 40.0f, 150.0f);
        func_800F77E8(func_800F54E4(), target_pos);
        func_800F8300(func_800F54E4(), 2, pos);
        func_80102424(actor, 2);
        func_8010A570(actor);
        partner = (Actor *)func_80106790(actor->unk3C);
        partner_b = (Actor *)func_80106790(partner->unk3C);
        func_8010A624(actor);
        func_80102424(partner, 2);
        func_80103110(partner, 1);
        partner->unk64_16 = 1;
        func_800DA544(0xBC);
        func_808008B4_chtiptup(partner_b, 0xB, 0x820);
        break;
        case 0x95:
        found = _subaddiefind_entrypoint_2(0x359, 0);
        if (found) actor->unk3C = found->unk0;
        else actor->unk3C = 0;
        break;
        case 0x40:
        found = _subaddiefind_entrypoint_2(0x358, 0);
        if (found && found->unk70_10 == 1) {
            _subaddiedialog_entrypoint_11(found->unk0, 0x1045, 0xE, found->position, 0x54);
            func_80102424(found, 2);
        }
        break;
        default: return 0;
    }
    return 1;
}

s32 D_80801360_chtiptup[14] = { 0x1, 0xFF60100, 0x1, -0xFE00, 0x200, 0x104D0100, 0x200, -0x1FE00, 0x400, 0x104E0100, 0x400, -0x2FE00, -0x12001, 0x120B0300 };
f32 D_80801398_chtiptup[4] = { 2.2e+02f, 2e+02f, 1.4e+02f, 8e+01f };
u32 D_808013A8_chtiptup[14] = { 0x0, 0x0, 0x40D66666, 0x18A0001, 0x40D66666, 0x18A0001, 0x40900000, 0x1890001, 0x3FA00000, 0x1880002, 0x3F800000, 0x1870101, 0x40900000, 0x1890001 };
u8 D_808013E0_chtiptup[64] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0xE5, 0xC2, 0x8F, 0x1, 0x84, 0x0, 0x44, 0x40, 0xE5, 0xC2, 0x8F, 0x1, 0x84, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0, 0x1, 0x85, 0x0, 0x1, 0x3F, 0x4C, 0xCC, 0xCD, 0x1, 0x86, 0x0, 0x2, 0x3F, 0x2B, 0x85, 0x1F, 0x1, 0x8B, 0x0, 0x1, 0x40, 0xE5, 0xC2, 0x8F, 0x1, 0x84, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0, 0x1, 0x85, 0x0, 0x1 };
u32 D_80801420_chtiptup[10] = { 0x0, 0x0, 0x40E5C28F, 0x1830044, 0x40E5C28F, 0x1830002, 0x40E5C28F, 0x1830084, 0x40E5C28F, 0x1830002 };
int D_80801448_chtiptup[18] = { 0x2B90358, 0x6C80001, (u32)&D_808013A8_chtiptup, (u32)func_80102EC0, (u32)func_80800024_chtiptup, (u32)func_80101870, 0x5DC0000, 0x3FCCCCCD, 0x0, 0x40100, (u32)func_808002C8_chtiptup, 0x0, 0x0, (u32)func_80800200_chtiptup, (u32)func_80107C2C, -0x79FFBBEE, (u32)func_808002F4_chtiptup, 0x0 };
int D_80801490_chtiptup[18] = { 0x2BA0359, 0x6C70001, (u32)&D_808013E0_chtiptup, (u32)func_80102EC0, (u32)func_808009B4_chtiptup, (u32)func_80101870, 0x5DC0000, 0x0, 0x0, 0x40140, 0x0, (u32)func_80108ED0, 0x0, (u32)func_80800C70_chtiptup, (u32)func_80107C2C, -0x7BFFFBEE, (u32)func_80800D78_chtiptup, 0x0 };
int D_808014D8_chtiptup[18] = { 0x2BB035A, 0x6C60001, (u32)&D_80801420_chtiptup, (u32)func_80800FE8_chtiptup, (u32)func_80800FE8_chtiptup, (u32)func_80101870, 0x5DC0000, 0x0, 0x0, 0x40068, 0x0, (u32)func_80108ED0, 0x0, (u32)func_808010CC_chtiptup, (u32)func_80107C2C, -0x7DFFDBF0, (u32)func_80801180_chtiptup, 0x0 };
u8 D_80801520_chtiptup[12] = { 0x0, 0x13, 0x4, 0x17, 0x0, 0x16, 0x3E, 0x80, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080152C_chtiptup[32] = { 0x0, 0xB, 0x0, 0x14, 0x0, 0x14, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2D, 0x0, 0xC8, 0x0, 0xFA, 0x0, 0x1E, 0xFF, 0xFB, 0xFF, 0xFB, 0x0, 0x1B, 0x0, 0xC8, 0x1, 0x2C, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080154C_chtiptup[12] = { 0x0, 0x13, 0x4, 0x10, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x0, 0x0, 0x0 };
u8 D_80801558_chtiptup[16] = { 0x0, 0x13, 0x6, 0x12, 0x0, 0xD, 0x1, 0x66, 0x1, 0x80, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x0 };
u8 D_80801568_chtiptup[8] = { 0x0, 0x20, 0xE0, 0xE0, 0xE0, 0xC0, 0x0, 0x0 };
s32 D_80801570_chtiptup[4] = { 0xBC0000, 0x15E0054, 0xC, 0x6320200 };
s32 D_80801580_chtiptup[12] = { 0x1D09C9, 0x206046, 0x1EC80016, 0x80022, 0x660080, 0x9900CC, 0x150033, 0x99002B, 0x9900CC, 0xD0014, 0x2D0032, 0x640000 };
s32 D_808015B0_chtiptup[4] = { 0x130626, 0xD00C0, 0xD90016, 0x46500000 };
s32 D_808015C0_chtiptup[3] = { 0x1304D7, 0xD0166, 0x1800000 };
s32 D_808015CC_chtiptup[4] = { 0x130449, 0x162710, 0xD00F3, 0x10C0000 };
s32 D_808015DC_chtiptup[4] = { 0x3D75C28F, 0x3DCCCCCD, 0x3E0F5C29, -0x40800000 };
s32 D_808015EC_chtiptup[5] = { 0x3060013, 0x62F000D, 0xF3010C, 0x180011, 0x0 };
s32 D_80801600_chtiptup[8] = { 0x3D75C28F, 0x3E051EB8, 0x3E570A3D, 0x3E99999A, 0x3ECCCCCD, 0x3EF5C28F, 0x3F0F5C29, -0x40800000 };
s32 D_80801620_chtiptup[3] = { 0x130532, 0xD0173, 0x18C0000 };
s32 D_8080162C_chtiptup[3] = { 0x13043A, 0xA017D, 0x20000 };
s32 D_80801638_chtiptup[3] = { 0x13061F, 0xA00E6, 0x0 };
s32 D_80801644_chtiptup[6] = { 0x0, 0x0, 0x3E4CCCCD, 0x3F800000, 0x3EE66666, 0x0 };
int D_8080165C_chtiptup[3] = { 0x13041D, 0xA0133, 0x20000 };
int D_80801668_chtiptup[3] = { 0x130561, 0x180002, 0x0 };
int D_80801674_chtiptup[2] = { 0x13044A, 0x20000 };
int D_8080167C_chtiptup[5] = { 0x3EF5C28F, 0x3F000000, 0x3F59999A, 0x3F6147AE, -0x40800000 };
u8 D_80801690_chtiptup[16] = { 0x0, 0x13, 0x4, 0x1B, 0x0, 0xD, 0x0, 0xB3, 0x0, 0xCC, 0x0, 0x16, 0x3E, 0x80, 0x0, 0x0 };
u8 D_808016A0_chtiptup[12] = { 0x0, 0x13, 0x6, 0x3B, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
u8 D_808016AC_chtiptup[20] = { 0x0, 0xC, 0x0, 0x0, 0x0, 0x2D, 0x0, 0x64, 0x0, 0x96, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
