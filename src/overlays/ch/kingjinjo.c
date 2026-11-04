// This seems to be King Jingaling in his Jinjo Village throne room: greets the player and offers
// dialogs leading to Bottles' house or back to the village; after his life is sapped he wanders as
// a zombie. A second actor is the throne-room prop with ambient sounds.
#include "common.h"

extern int D_808011A8_chkingjinjo[];
extern int D_808011F0_chkingjinjo[];
typedef struct {
    u8 pad_0[0x75];
    u8 p0 : 3;
    u8 f10 : 1;
    u8 p1 : 4;
    u8 pad_1[5];
    u8 p2 : 6;
    u8 f2 : 1;
    u8 p3 : 1;
} KJFlags;
extern void *func_80100094();
extern f32 func_800DC178(f32, f32);
extern int D_808012A0_chkingjinjo[];
extern int D_808012B0_chkingjinjo[];
extern int _gcdialogcamera_entrypoint_0(int, int);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern u8 D_808012C0_chkingjinjo[];
extern u8 D_808012E8_chkingjinjo[];
extern u8 D_808012D0_chkingjinjo[];
extern u8 D_808012F8_chkingjinjo[];
extern u8 D_808012DC_chkingjinjo[];
extern u8 D_80801304_chkingjinjo[];
extern void func_800DF744(int, int);
extern void func_80101870(void *, void *);
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} KJState;
extern u8 D_80801238_chkingjinjo[];
extern u8 D_80801254_chkingjinjo[];
extern u8 D_80801264_chkingjinjo[];
extern u8 D_80801274_chkingjinjo[];
extern u8 D_80801284_chkingjinjo[];
extern int func_800C3D78();
extern u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
extern f32 func_8010CD28(Actor *);
extern void func_800F4EC8(s32, f32 *, f32, f32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
extern s32 func_80102320(Actor *, f32, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 func_80101E14(void *, f32);
extern int func_8010CD88(u8 *, f32, f32);
extern void func_8010D5DC();
extern void func_80102424(Actor *, s32);
extern s32 *_subaddiefind_entrypoint_2(s32, s32);
extern s32 func_800DA298(s32);
extern void func_801032B0(Actor *, s32, s32);
extern void _subaddierouteDll_entrypoint_1(Actor *);
extern s32 _glcutDll_entrypoint_20(void);
extern s32 func_800F54E4(void);
extern void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
extern void func_800F497C(s32);
extern void func_800F49A8(s32, s32);
extern void func_800F49D4(s32, void *, Unk80132ED0 *);
extern void func_800F4A58(s32, f32 *, f32);
extern s32 _suexpression_entrypoint_7(Actor *, s32, s16);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern void _suexpression_entrypoint_17(s32, s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void _gcgoto_entrypoint_1(s32, s32);
extern void func_801015D0(Actor *);
int func_80800C18_chkingjinjo();
void func_80800C60_chkingjinjo();
void func_808009FC_chkingjinjo();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80108ED0(),
    func_80800018_chkingjinjo();

// King Jingaling NPC (normal and zombie) with dialog camera pods.
int chkingjinjo_entrypoint_0()
{
    return (int) &D_808011A8_chkingjinjo;
}

// Throne-room prop with ambient sounds and a flag-dependent model variant.
int *chkingjinjo_entrypoint_1()
{
    return &D_808011F0_chkingjinjo;
}

void func_80800018_chkingjinjo(actor) Actor *actor;
{
    u8 *route;
    f32 *pos;
    s32 pad_v[2];
    f32 marker_pos[3];
    route = func_80100094(actor, 0);
    if (_glcutDll_entrypoint_20()) {
        func_80102424(actor, 0xB);
        ((KJFlags *) actor)->f10 = 0;
        return;
    }
    if (func_800DA298(0x360)) {
        _subaddiemarker_entrypoint_1(actor, 0x154, 0x32, marker_pos, 1);
        pos = actor->position;
        func_800EE7F8(pos, marker_pos);
        actor->rotation[1] = func_800DC178(0.0f, 360.0f);
        _subaddieDll_entrypoint_1(actor);
        _subaddierouteDll_entrypoint_3(actor, route, pos);
        func_80102424(actor, 6);
        func_8010A590(actor);
        func_80104E78(actor);
        ((KJFlags *) actor)->f10 = 1;
        *(f32 *) ((u8 *) actor + 0x58) = func_800DC178(8.0f, 12.0f);
        *(f32 *) (route + 0xC) = func_800DC178(4.0f, 6.0f);
        ((KJFlags *) actor)->f2 = 1;
        return;
    }
    if (func_800DA298(0x3B)) {
        if (!func_800DA298(0x43)) {
            func_800FFAB0(actor);
            return;
        }
        func_80102424(actor, 9);
        ((KJFlags *) actor)->f10 = 0;
        return;
    }
    ((KJFlags *) actor)->f10 = 0;
}

void func_80800194_chkingjinjo(Actor *actor)
{
    u8 *route;
    f32 pos[3];
    u8 sfx;

    route = func_80100094(actor, 0);
    switch (((KJState *) actor)->st) {
        case 3:
            func_80800AE4_chkingjinjo(actor, D_80801238_chkingjinjo);
            break;
        case 5:
            if (func_800D9078(&actor->unk58)) {
                func_800F5A00(func_800F54E4(), pos);
                pos[1] += 200.0f;
                func_800D1000(0x5A, 1, pos, 1, 0);
                func_80102424(actor, 4);
            }
            break;
        case 6:
            if (func_800D9078(route + 0xC)) {
                sfx = actor->unk5F;
                if (sfx == 0) {
                    actor->unk5F = _subaddieaudioquick_entrypoint_1(actor, actor->position);
                    sfx = actor->unk5F;
                }
                actor->unk5F = func_800C4350(sfx, actor->position, D_80801254_chkingjinjo);
                *(f32 *) (route + 0xC) = func_800DC178(4.0f, 6.0f);
            }
            if (!func_800C0638()) {
                if (func_8010CAC0(actor->position, 1000)) {
                    if (func_800D90A4(&actor->unk58)) {
                        _subaddiedialog_entrypoint_11(actor->unk0, func_800DC128(0, 6) + 0x152F,
                                                      0x44, actor->position, 0xA5);
                        actor->unk58 = func_800DC178(8.0f, 12.0f);
                    }
                }
            }
            if (func_8010D248()) {
                if (func_8010C500(actor)) {
                    actor->unk54 = func_8010CD28(actor);
                }
            }
            *(f32 *) &actor->actorData[3] = actor->scale * 60.0f;
            _subaddierouteDll_entrypoint_7(actor, route, actor->rotation[1], actor->unk54,
                                           400.0f, 0x4000);
            _subaddierouteDll_entrypoint_6(actor, route, *(u16 *) (route + 6), 0x7F, 0.2f,
                                           0x14, 0x28);
            _subaddierouteDll_entrypoint_5(actor, route, *(u16 *) (route + 6), 0.1f, 4.0f,
                                           80.0f);
            func_8010B990(actor, 0x1405);
            if (func_8010C9B0(actor->position, 0xC8)) {
                if (func_8010CD88(actor, 180.0f, 60.0f)) {
                    func_80102424(actor, 8);
                }
            }
            break;
        case 7:
            if (func_80101E14(actor, 0.3f)) {
                if (actor->unk5F != 0 && func_800C3D78(actor->unk5F)) {
                    func_800C3CE8(actor->unk5F);
                }
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80801264_chkingjinjo);
            }
            if (func_80101DDC(actor)) {
                func_80102424(actor, 6);
            }
            break;
        case 8:
            if (func_8010D248()) {
                if (func_8010C500(actor)) {
                    actor->unk54 = func_8010CD28(actor);
                }
            }
            func_80102BF8(actor, 0.1f, 4.0f, 80.0f);
            if (func_80101E14(actor, 0.3f)) {
                if (actor->unk5F != 0 && func_800C3D78(actor->unk5F)) {
                    func_800C3CE8(actor->unk5F);
                }
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80801274_chkingjinjo);
            }
            if (func_80101DDC(actor)) {
                func_80102424(actor, 6);
            }
            break;
        case 9:
            func_80800AE4_chkingjinjo(actor, D_80801284_chkingjinjo);
    }
    if (func_800DA298(0x360)) {
        func_800F4EC8(func_800F54E4(), actor->position, actor->scale * 300.0f, 0,
                      actor->scale * 90.0f);
    } else {
        if (func_801022E4(actor) == 0x3A9 && func_80102320(actor, 0.55f, 0.95f)) {
            _suexpression_entrypoint_18(_suexpression_entrypoint_20(actor), 1);
        }
    }
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(actor), actor->unk0, 0);
}

s32 func_80800634_chkingjinjo(actor, msg, arg)
Actor *actor;
s32 msg;
s32 arg;
{
    s16 *halves;
    s32 dialog_state;
    s32 speaker_id;
    s32 unk_0;
    s32 *found;
    f32 cam_pos[3];
    s32 player;
    void (*callback)();
    s32 expression;
    s32 unk_1;
    f32 cam_pos2[3];
    s32 player2;

    switch (msg) {
        case 0x2E:
            halves = (s16 *) &arg;
            func_808009FC_chkingjinjo(actor, halves[0], halves[1]);
            break;
        case 0x3F:
            if (actor->unk70_10 != 7) {
                func_80102424(actor, 7);
            }
            break;
        case 0x52:
            func_80800B28_chkingjinjo(actor);
            break;
        case 0x95:
            found = _subaddiefind_entrypoint_2(0x147, 0);
            if (found != NULL) {
                actor->unk3C = *found;
            } else {
                actor->unk3C = 0;
            }
            if (func_800DA298(0x360)) {
                func_801032B0(actor, 0x897, ((u16 *) actor->unk0)[0xB]);
                _subaddierouteDll_entrypoint_1(actor);
            } else {
                if (!func_800DA298(0x1A5) && !func_800DA298(0x3B) && !_glcutDll_entrypoint_20()) {
                    player = func_800F54E4();
                    _subaddiemarker_entrypoint_1(actor, 0x154, 0x33, cam_pos, 1);
                    func_800F497C(player);
                    func_800F49A8(player, 1);
                    func_800F49D4(player, func_8010D5DC, actor->unk0);
                    func_800F4A58(player, cam_pos, 300.0f);
                    func_80800CFC_chkingjinjo(actor, 5, 0x20);
                    func_80102424(actor, 1);
                }
                func_801032B0(actor, 0x896, ((u16 *) actor->unk0)[0xB]);
            }
            if (actor->unk70_10 == 2) {
                callback = func_8010D5DC;
                player2 = func_800F54E4();
                _subaddiemarker_entrypoint_1(actor, 0x154, 0x34, cam_pos2, 1);
                func_800F497C(player2);
                func_800F49A8(player2, 1);
                func_800F49D4(player2, callback, actor->unk0);
                func_800F4A58(player2, cam_pos2, 300.0f);
                func_80800CFC_chkingjinjo(actor, 0x17, 0x2020);
            }
            if (func_800DA298(0x360)) {
                speaker_id = 0xA5;
            } else {
                speaker_id = 0xAE;
            }
            expression = _suexpression_entrypoint_7(actor, 1, speaker_id);
            _suexpression_entrypoint_12(expression, 60.0f, 20.0f);
            _suexpression_entrypoint_17(expression, 1500);
            break;
        case 0x57:
            return func_80800BBC_chkingjinjo(actor, arg & 0xFFFF,
                                             (arg & 0xFFFF0000) >> 16);
        case 0x0B:
            if (arg == 1) {
                func_80800C60_chkingjinjo(actor, 3, 1);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1535, 6, actor->position, 0xAE);
                return 4;
            }
            return 3;
        case 0x32:
            dialog_state = actor->unk70_10;
            switch (dialog_state) {
                case 1:
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x14FD, 0xE, actor->position,
                                                  0xAE);
                    break;
                case 2:
                    _gcgoto_entrypoint_1(0x142, 1);
            }
            break;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(3, 0);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_808009D0_chkingjinjo(actor_id)
s32 actor_id;
{
    func_80800C18_chkingjinjo();
    _suexpression_entrypoint_8(actor_id, 1);
}

void func_808009FC_chkingjinjo(actor, dialog_id, unused) u8 *actor;
s32 dialog_id;
s32 unused;
{
    s32 next_state;

switch (dialog_id) {
    case 0x14FD:
        func_800DA544(0x1A5);
        func_80800CFC_chkingjinjo(actor, 1, 0x30);
        func_80102424(actor, 5);
        *(f32 *) ((s8 *) actor + 0x58) = 0.4f;
        return;
    case 0x1535:
        func_80800C18_chkingjinjo(actor);
        func_80102424(actor, 2);
        _glcutDll_entrypoint_6(0x143, 0x65);
        return;
    default:
        if (func_800DA298(0x360) == 0) {
            if (*(s32 *) ((s8 *) actor + 0x6C) & 0x1FF) {
                func_80800C18_chkingjinjo(actor);
            }
            if (func_800DA298(0x3B) != 0) {
                next_state = 9;
            } else {
                next_state = 3;
            }
            func_80102424(actor, next_state);
        }
}

}

int func_80800AE4_chkingjinjo(s32 actor[3], s32 script)
{
    s32 result;
    result = _subaddiedialog_entrypoint_7(actor, actor + 1, script | 0);

if (result != 0 && result != 0x1208) {
    func_80800C60_chkingjinjo(actor, 3, 0);
}

}

int func_80800B28_chkingjinjo(s32 actor)
{
    f32 cam_pos[3];

if (func_801022E4() == 0x3A9) {
    func_800EE7F8(&cam_pos, actor + 4);
    func_800EF1B8(&cam_pos, *(s32 **) (actor + 0x48), 0xC2480000);
    _gcdialogcamera_entrypoint_3(&D_808012A0_chkingjinjo, *(s32 **) (actor + 0x38));
    _gcdialogcamera_entrypoint_4(&cam_pos);
    _gcdialogcamera_entrypoint_5(actor + 0x44);
    return;
}

_gcdialogcamera_entrypoint_3(&D_808012B0_chkingjinjo, *(s32 **) (actor + 0x38));
_gcdialogcamera_entrypoint_4(actor + 4);
_gcdialogcamera_entrypoint_5(actor + 0x44);

}

int func_80800BBC_chkingjinjo(Actor *actor, s32 arg1, s32 arg2)
{
    if (_gcdialogcamera_entrypoint_0(arg1 | 0, arg2 | 0)) {
        if ((*(s32 *) ((char *) actor + 0x6C) & 0x1FF) != 2) {
            func_80800C60_chkingjinjo(actor, 2, 1);
        }
        return 2;
    }

return 1;

}

int func_80800C18_chkingjinjo(actor)
Actor *actor;
{
    if (*(s32 *) ((char *) actor + 0x6C) & 0x1FF) {
        _capod_entrypoint_3(0, actor);
        *(u16 *) ((char *) actor + 0x6E) &= 0xFE00;
    }

}

void func_80800C60_chkingjinjo(actor, arg1, arg2) u8 *actor;
s32 arg1;
s32 arg2;
{
    s32 camera_state;

    camera_state = *(s32 *) ((char *) actor + 0x6C) & 0x1FF;

switch (camera_state) {
    case 0:
        _capod_entrypoint_2(*(s32 *) ((char *) actor + 0x0), 0x17, 0, actor);

    case 1:
        _capod_entrypoint_8(1);
        *(u16 *) ((char *) actor + 0x6E) =
            (u16) ((*(u16 *) ((char *) actor + 0x6E) & 0xFE00) | 2);
        func_80800B28_chkingjinjo(actor);
        _gcdialogcamera_entrypoint_8();

    case 2:
        _capod_entrypoint_7(arg1, arg2);
}

}

int func_80800CFC_chkingjinjo(Actor *actor, s32 arg1, s32 arg2)
{
    s32 flags;
    s32 camera_state;
    flags = *((s32 *) (((char *) actor) + 0x6C));
    camera_state = flags & 0x1FF;

switch (camera_state & 0xFFFF) {
    case 0:
        _capod_entrypoint_2(*(s32 *) ((char *) actor + 0x0), 0x17, arg2, actor);

    case 2:
        *(u16 *) ((char *) actor + 0x6E) =
            (u16) ((*(u16 *) ((char *) actor + 0x6E) & 0xFE00) | 1);

    case 1:
        _capod_entrypoint_6(*(s32 *) ((char *) actor + 0x0), arg1, arg2, actor);
}

}

void func_80800D80_chkingjinjo(Actor *actor)
{
    if (_glcutDll_entrypoint_20() != 0) {
        actor->unk64_19 = 1;
        actor->unk6C_0 = 1;
        return;
    }

if ((func_800DA298(0x3B) != 0) && (func_800DA298(0x43) == 0)) {
    actor->unk6C_0 = 1;
    return;
}

if (func_800DA298(0x360) != 0) {
    func_80102424(actor, 2);
    actor->unk64_19 = 0;
    actor->unk6C_0 = 2;
    return;
}

actor->unk64_19 = 1;
actor->unk6C_0 = 1;
}

void func_80800E58_chkingjinjo(Actor *actor)
{
    f32 box_min[3];
    f32 box_max[3];

if (actor->unk70_10 == 1 && actor->unk64_19) {
    _subaddieaudioquick_entrypoint_4(actor, actor->position, D_808012C0_chkingjinjo,
                                     D_808012E8_chkingjinjo);
    _subaddieaudioquick_entrypoint_4(actor, actor->position, D_808012D0_chkingjinjo,
                                     D_808012F8_chkingjinjo);
    _subaddieaudioquick_entrypoint_4(actor, actor->position, D_808012DC_chkingjinjo,
                                     D_80801304_chkingjinjo);
}

func_800EFA4C(box_min, -280.0f, 0.0f, -250.0f);
func_800EFA4C(box_max, 170.0f, 400.0f, 80.0f);
func_800EF334(box_min, actor->scale);
func_800EF334(box_max, actor->scale);
func_800EF04C(box_min, actor->position);
func_800EF04C(box_max, actor->position);
_sudeflect_entrypoint_2(box_min, box_max, 0xA);
}

s32 func_80800F60_chkingjinjo(s32 arg0, s32 arg1, s32 arg2)
{
    return 0;
}
void func_80800F74_chkingjinjo(u8 *actor, s32 arg1)
{
    func_800DF744(3, (*(s32 *) ((u8 *) (actor) + 0x6C)) & 0x1FF);
    func_800DF744(4, (u32) ((*(s32 *) ((u8 *) (actor) + 0x64)) << 0xC) >> 0x1F);
    func_80101870(actor, arg1);
}

// TU-NOTE: the .data of this overlay is defined in this file; IDO schedules some of the
// functions differently unless the tables live in the same unit. Values are from the ROM.
u8 D_80801130_chkingjinjo[96] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x41, 0x44, 0xA3, 0xD7, 0x3, 0xA9, 0x0, 0x1,
    0x41, 0x44, 0xA3, 0xD7, 0x3, 0xA9, 0x0, 0x1, 0x41, 0x44, 0xA3, 0xD7, 0x3, 0xA9, 0x0, 0x1,
    0x41, 0x44, 0xA3, 0xD7, 0x3, 0xA9, 0x0, 0x1, 0x41, 0x44, 0xA3, 0xD7, 0x3, 0xA9, 0x0, 0x1,
    0x3F, 0xEA, 0x3D, 0x71, 0x3, 0xA6, 0x0, 0x1, 0x3F, 0x86, 0x66, 0x66, 0x3, 0xA8, 0x0, 0x2,
    0x3F, 0xEA, 0x3D, 0x71, 0x3, 0xA7, 0x0, 0x2, 0x41, 0x44, 0xA3, 0xD7, 0x3, 0xA9, 0x0, 0x1,
    0x41, 0x44, 0xA3, 0xD7, 0x3, 0xA9, 0x0, 0x1, 0x41, 0x44, 0xA3, 0xD7, 0x3, 0xA9, 0x0, 0x1};
u32 D_80801190_chkingjinjo[6] = {0x0, 0x0, 0x4144A3D7, 0x3AA0001, 0x0, 0x0};
int D_808011A8_chkingjinjo[18] = {0x3B0438,
                                  0x8960003,
                                  (u32) &D_80801130_chkingjinjo,
                                  (u32) func_80800194_chkingjinjo,
                                  (u32) func_80105834,
                                  (u32) func_801018A4,
                                  0x0,
                                  0x40000000,
                                  0x0,
                                  0x3850520,
                                  (u32) func_808009D0_chkingjinjo,
                                  (u32) func_80108ED0,
                                  0x100000,
                                  (u32) func_80800018_chkingjinjo,
                                  (u32) func_80107C2C,
                                  -0x7FFFFBFE,
                                  (u32) func_80800634_chkingjinjo,
                                  0x0};
int D_808011F0_chkingjinjo[18] = {0x1580147,
                                  0x8980001,
                                  (u32) &D_80801190_chkingjinjo,
                                  (u32) func_80800E58_chkingjinjo,
                                  (u32) func_80105834,
                                  (u32) func_80800F74_chkingjinjo,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x800504,
                                  0x0,
                                  0x0,
                                  0x0,
                                  (u32) func_80800D80_chkingjinjo,
                                  (u32) func_80107C2C,
                                  -0x7FFFDBFE,
                                  (u32) func_80800F60_chkingjinjo,
                                  0x0};
u8 D_80801238_chkingjinjo[28] = {0x0, 0x0, 0x1,  0x5E, 0x0, 0x0, 0x14, 0xFE, 0x0, 0x0,
                                 0x2, 0x1, 0x12, 0x8,  0x0, 0x0, 0x0,  0xAE, 0x0, 0x0,
                                 0x0, 0xE, 0x6,  0x3C, 0x4, 0x0, 0x0,  0x0};
u8 D_80801254_chkingjinjo[16] = {0x3, 0x6,  0x0, 0x13, 0x6, 0x97, 0x0, 0xD,
                                 0x0, 0xF3, 0x1, 0xC,  0x0, 0x11, 0x0, 0x0};
u8 D_80801264_chkingjinjo[16] = {0x0, 0x13, 0x5, 0x31, 0x0, 0xD, 0x0, 0x8C,
                                 0x0, 0xA6, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_80801274_chkingjinjo[16] = {0x0, 0x13, 0x6, 0x17, 0x0, 0xD, 0x0, 0x8C,
                                 0x0, 0xA6, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_80801284_chkingjinjo[28] = {0x1, 0xA5, 0x1,  0x5E, 0x15, 0x56, 0x15, 0x57, 0x0, 0x0,
                                 0x2, 0x1,  0x12, 0x8,  0x0,  0x0,  0x0,  0xAE, 0x0, 0x0,
                                 0x0, 0xE,  0x6,  0x3C, 0xA,  0x0,  0x0,  0x0};
int D_808012A0_chkingjinjo[4] = {0x43C80000, 0x43960000, 0x43020000, 0x43340000};
int D_808012B0_chkingjinjo[4] = {0x43E10000, 0x43160000, 0x437A0000, 0x437A0000};
u8 D_808012C0_chkingjinjo[16] = {0x0, 0x13, 0x5, 0xCA, 0x0,  0xD,  0x0, 0xF3,
                                 0x1, 0xC,  0x0, 0x16, 0x65, 0x90, 0x0, 0x0};
u8 D_808012D0_chkingjinjo[12] = {0x0, 0x13, 0x5, 0x62, 0x0, 0xD, 0x1, 0x40, 0x1, 0x59, 0x0, 0x0};
u8 D_808012DC_chkingjinjo[12] = {0x0, 0x13, 0x5, 0x62, 0x0, 0xD, 0x1, 0x19, 0x1, 0x33, 0x0, 0x0};
u8 D_808012E8_chkingjinjo[16] = {0x3F, 0x35, 0xC2, 0x8F, 0x3F, 0x47, 0xAE, 0x14,
                                 0x3F, 0x5C, 0x28, 0xF6, 0xBF, 0x80, 0x0,  0x0};
u8 D_808012F8_chkingjinjo[12] = {0x3F, 0xC,  0xCC, 0xCD, 0x3F, 0x14,
                                 0x7A, 0xE1, 0xBF, 0x80, 0x0,  0x0};
u8 D_80801304_chkingjinjo[12] = {0x3F, 0x42, 0x8F, 0x5C, 0x3F, 0x57,
                                 0xA,  0x3D, 0xBF, 0x80, 0x0,  0x0};
