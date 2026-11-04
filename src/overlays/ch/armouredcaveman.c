#include "common.h"

extern u32 D_80800B20_charmouredcaveman[];
extern int func_800D0B68(int, int);
extern void func_800D1000(int, int, void *, int, int);
extern int func_800DA298(int);
extern int func_800DA564(int, int);
extern void func_800FFAB0(void *);
extern void func_80102424(void *, int);
extern void func_8010B990(void *, int);
extern int _glcutDll_entrypoint_20(void);
typedef struct {
    int unk2C;
    int unk28;
    unsigned short unk76_11;
} CharmouredCavemanActor;
extern u8 D_80800BA4_charmouredcaveman[];
extern u8 D_80800BBC_charmouredcaveman[];
extern u8 D_80800BB0_charmouredcaveman[];
extern u8 D_80800B78_charmouredcaveman[];
extern int _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 D_80800C08_charmouredcaveman[];
extern s32 D_80800C14_charmouredcaveman[];
extern s32 D_80800C20_charmouredcaveman[];
extern void _subaddiedialog_entrypoint_11(void *, int, int, void *, int);
extern void func_8010A570(void *);
typedef struct {
    u8 pad[0x65];
    u8 pad65 : 4;
    u8 flag : 1;
    u8 rest65 : 3;
    u8 pad66[0xC];
    u16 f72 : 6;
    u16 rest : 10;
} CavemanState;
extern f32 func_8010CD28(Actor *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern s32 _subaddiefade_entrypoint_0(Actor *);
typedef struct {
    u32 pad_0 : 11;
    u32 local_0 : 1;
    u32 pad_1 : 20;
} Broad51ArmouredFlags;
extern f32 func_800F2094(f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern u8 D_80800B68_charmouredcaveman[];
extern u8 _chbaddiesetup_entrypoint_10[];
typedef struct {
    u8 pad0[0x18];
    u16 hi;
    u16 id : 11;
    u16 rest : 5;
    u32 pad1C;
    u32 pad20;
    u32 kind : 10;
    u32 rest24 : 22;
} CaveMsg;
typedef struct {
    f32 local_0[4];
} CavemanFloats61;
typedef union {
    s16 local_0[4];
    s32 local_1[2];
} CavemanShorts61;
extern CavemanFloats61 D_80800BCC_charmouredcaveman;
extern CavemanFloats61 D_80800BDC_charmouredcaveman;
extern s32 D_80800BEC_charmouredcaveman[];
extern s32 D_80800BF4_charmouredcaveman[];
extern u8 D_80800BFC_charmouredcaveman[];
extern f32 func_800DC178(f32, f32);
extern void func_800C31DC(u8, f32);
extern s32 func_80101E14(Actor *, f32);
int func_8080072C_charmouredcaveman();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(),
    func_8080000C_charmouredcaveman(), func_808000EC_charmouredcaveman();

char *charmouredcaveman_entrypoint_0()
{
    return &D_80800B20_charmouredcaveman;
}

// Init: per-instance defeat flag is 0x17A + (marker id - 0x32); respawns the jiggy when all 5 are beaten.
void func_8080000C_charmouredcaveman(actor) CharmouredCavemanActor *actor;
{
    int instance;
    int marker_id;
    marker_id = (unsigned int) *(u16 *) ((char *) actor + 118) >> 7;
    marker_id = marker_id - 0x32;
    instance = marker_id;
    *(s32 *) ((char *) actor + 44) = instance;
    *(s32 *) ((char *) actor + 40) = instance + 0x17A;
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(actor, 7);
        goto block_9;
    }
    if (func_800DA298(0x5D) != 0) {
        if ((func_800DA564(0x17A, 5) == *(s32 *) ((char *) actor + 44)) &&
            (func_800D0B68(0x31, 1) == 0)) {
            func_800D1000(0x31, 1, &actor->unk28, 3, 0);
        }
        func_800FFAB0(actor);
        return;
    }
    if (func_800DA298(*(s32 *) ((char *) actor + 40)) != 0) {
        func_800FFAB0(actor);
        return;
    }
block_9:
    func_8010B990(actor, 0x1000);
}

void func_808009D4_charmouredcaveman();

void func_8080095C_charmouredcaveman();

void func_80800640_charmouredcaveman();

void func_808000EC_charmouredcaveman(actor) Actor *actor;
{
    s32 run_common;
    s32 on_screen;
    s32 deflect_flags;

    run_common = 1;
    on_screen = func_8010D23C();
    deflect_flags = 0;
    if (actor->unk70_10 != 6) {
        deflect_flags = _sudeflect_entrypoint_1(actor->position, 250.0f, -10.0f, 140.0f, 10) & 8;
    }
    switch (actor->unk70_10) {
        case 1:
            func_80800640_charmouredcaveman(actor);
            if (deflect_flags) {
                func_808009D4_charmouredcaveman(actor, deflect_flags);
            }
            if (on_screen && func_8010D278() != 0x11 && func_8010C9B0(actor->position, 400)) {
                actor->unk64_19 = 0;
                func_80102424(actor, 4);
            }
            break;
        case 2:
            func_80800640_charmouredcaveman(actor);
            run_common = 0;
            break;
        case 3:
            func_8080072C_charmouredcaveman(actor, deflect_flags);
            if (func_80101DDC(actor)) {
                func_80102424(actor, actor->unk64_20 ? 2 : 1);
            }
            break;
        case 4:
            func_808008B0_charmouredcaveman(actor);
            if (func_80101DDC(actor)) {
                if (actor->unk64_19) {
                    func_8080095C_charmouredcaveman(actor);
                } else {
                    func_80102424(actor, 1);
                }
            }
            break;
        case 5:
            run_common = 0;
            func_8080092C_charmouredcaveman(actor);
            if (func_80101DDC(actor)) {
                func_80102424(actor, 6);
                _subaddiefade_entrypoint_5(actor);
            }
            break;
        case 6:
            run_common = 0;
            if (_subaddiefade_entrypoint_0(actor) == 0) {
                deflect_flags = 0;
            } else {
                deflect_flags = 1;
            }
            ((Broad51ArmouredFlags *) ((u8 *) actor + 0x74))->local_0 = actor->unk64_16 =
                deflect_flags;
            break;
        case 7:
            func_8080072C_charmouredcaveman(actor, deflect_flags);
    }
    if (run_common && on_screen) {
        if (func_8010D278() != 0x11) {
            actor->unk54 = func_8010CD28(actor);
        }
        func_80102BF8(actor, 0.3f, 3.0f, 300.0f);
    }
}

s32 func_80800370_charmouredcaveman(Actor *actor, s32 msg_type, s32 msg)
{
    CaveMsg *egg;
    f32 egg_pos[3];
    s32 dialog_id;
    s32 spawn_pos[3];
    s32 first_defeat;
    s32 dialog;
    f32 *actor_pos;
    switch (msg_type) {
        // Egg hit: only egg 0x270 from behind defeats it.
        case 0x40:
            egg = (CaveMsg *) *(s32 *) &msg;
            if (egg->kind == 0x270) {
                if ((_sueggmisc_entrypoint_0(egg) == 0) &&
                    (((u32) (actor->unk0->unk18 << 0xB) >> 0x1C) == 1)) {
                    func_800EC398(egg, egg_pos);
                    actor_pos = actor->position;
                    if (func_800F2094(func_800F1DF4(actor_pos, egg_pos), actor->rotation[1]) > 100.0f) {
                        func_80109600(actor, egg);
                        func_8010A570(actor);
                        func_80102424(actor, 5);
                        _subaddieDll_entrypoint_4(actor, 1);
                        func_80103DFC(actor, spawn_pos);
                        _chbaddiesetup_entrypoint_5(&_chbaddiesetup_entrypoint_10, 4, spawn_pos[0],
                                                    spawn_pos[1], spawn_pos[2],
                                                    *(s32 *) ((s8 *) actor + 0x48));
                        first_defeat = func_800DA564(0x17A, 5) == 0;
                        func_800DA544(*(s32 *) ((s8 *) actor + 0x28));
                        if (first_defeat != 0) {
                            dialog = 0x17E3;
                        } else if (func_800DA564(0x17A, 5) == 0x1F) {
                            dialog = 0x1806;
                            func_800DA544(0x5D);
                            func_800DA7A8(0x17A, *(s32 *) ((s8 *) actor + 0x2C), 5);
                            func_800D1000(0x31, 1, actor_pos, 1, 0);
                        } else {
                            dialog = 0x17E4;
                        }
                        _subaddiedialog_entrypoint_11(actor->unk0, dialog, 0x44, actor_pos, 0xA6);
                        *(u8 *) ((s8 *) actor + 0x75) =
                            (u8) (*(u8 *) ((s8 *) actor + 0x75) & 0xFFFD);
                        return 1;
                    }
                }
            }

        case 0x3E:
        case 0x3F:
            if ((((CaveMsg *) *(s32 *) &msg)->kind == 0) &&
                (func_800F64A4(((CaveMsg *) *(s32 *) &msg)->id, 0x10000) != 0)) {
                return 0;
            }
            func_808009D4_charmouredcaveman(actor);
            func_80109600(actor, *(s32 *) &msg);
            break;

        case 0x30:
            return 5 - func_800DA980(0x17A, 5);

        case 0x2E:
            dialog_id = *(s16 *) &msg;
            if (dialog_id == 0x17E2) {
                func_800DA544(0x66C);
                *(u8 *) ((s8 *) actor + 0x65) = (u8) (*(u8 *) ((s8 *) actor + 0x65) & 0xFFEF);
                func_8010A590(actor);
                func_80102424(actor, 1);
            } else {
                func_800FFAB0(actor);
            }
            break;

        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800B68_charmouredcaveman,
                                         *(s32 *) ((s8 *) actor + 0x38));
            break;

        default:
            return 0;
    }
    return 1;
}

void func_80800640_charmouredcaveman(Actor *actor)
{
    s32 stepped;
    f32 ray_start[3];
    f32 ray_end[3];

    stepped = _subaddieaudioquick_entrypoint_4(
        actor, actor->position, D_80800BA4_charmouredcaveman, D_80800BBC_charmouredcaveman);
    _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80800BB0_charmouredcaveman,
                                     0.83f);
    if (stepped && actor->unk7C_12) {
        func_800EE7F8(ray_start, actor->position);
        ray_start[1] += actor->scale * 180.0f;
        func_800EE7F8(ray_end, ray_start);
        ray_end[1] -= actor->scale * 10.0f;
        func_800BBCB8(ray_start, ray_end, 1.0f, 8, D_80800B78_charmouredcaveman);
    }
}

int func_8080072C_charmouredcaveman(actor)
Actor *actor;
{
    CavemanFloats61 delays;
    CavemanFloats61 pitches;
    CavemanShorts61 sfx_ids;
    CavemanShorts61 volumes;
    s32 i;
    delays = D_80800BCC_charmouredcaveman;
    pitches = D_80800BDC_charmouredcaveman;
    sfx_ids = *(CavemanShorts61 *) D_80800BEC_charmouredcaveman;
    volumes = *(CavemanShorts61 *) D_80800BF4_charmouredcaveman;
    if (actor->unk5F == 0)
        actor->unk5F = func_800C4350(0, actor->position, D_80800BFC_charmouredcaveman);
    for (i = 0; i < 4; i++) {
        if (func_80101E14(actor, delays.local_0[i])) {
            func_800C301C(actor->unk5F, sfx_ids.local_0[i]);
            func_800C31DC(actor->unk5F, pitches.local_0[i] + func_800DC178(-0.02f, 0.02f));
            func_800C3058(actor->unk5F, volumes.local_0[i]);
            func_800C3BDC(actor->unk5F);
            break;
        }
    }
}

int func_808008B0_charmouredcaveman(s32 actor)
{
    s32 ref;
    s32 unk_1;
    ref = actor + 4;
    // Matching: empty block steers IDO.
    if (1) {
    }
    unk_1 =
        _subaddieaudioquick_entrypoint_3(actor, ref, &D_80800C08_charmouredcaveman, 0.3f);
    if (_subaddieaudioquick_entrypoint_3(actor, ref, &D_80800C14_charmouredcaveman, 0.5f)) {
        func_80018820(0, 0x3F800000, 0x3ECCCCCD);
        func_800E15CC(0, 0x41A00000, 0x3F59999A);
    }
}

int func_8080092C_charmouredcaveman(s32 actor)
{
    s32 ref;
    ref = actor + 4;
    _subaddieaudioquick_entrypoint_3(actor, ref, &D_80800C20_charmouredcaveman, 0.1f);
}

void func_8080095C_charmouredcaveman(u8 *actor)
{
    int unk_0;
    // Matching: extra temporary and redundant tests for the match.
    actor[0x65] &= 0xFFF7;
    if (func_800DA298(0x66C) == 0) {
        unk_0 = !actor;
        _subaddiedialog_entrypoint_11(*(s32 *) actor, 0x17E2, 0xE, 4 + actor, 0xA6);
        if ((unk_0 && !actor) && !actor) {
        }
        actor[0x65] |= 0x10;
        func_8010A570(actor);
    }
    func_80102424(actor, 3);
}

void func_808009D4_charmouredcaveman(CavemanState *actor)
{
    switch (actor->f72) {
        case 3:
            break;
        case 4:
            actor->flag = 1;
            break;
        default:
            func_8080095C_charmouredcaveman(actor);
    }
}

u8 D_80800AE0_charmouredcaveman[64] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x40, 0xA3, 0x33, 0x33, 0x4, 0x30, 0x0, 0x1,
    0x40, 0xA3, 0x33, 0x33, 0x4, 0x30, 0x0, 0x1,  0x40, 0x4C, 0xCC, 0xCD, 0x4, 0x31, 0x0, 0x2,
    0x3F, 0x8C, 0xCC, 0xCD, 0x4, 0x32, 0x0, 0x2,  0x3F, 0xC0, 0x0,  0x0,  0x4, 0x33, 0x0, 0x2,
    0x3F, 0xC0, 0x0,  0x0,  0x4, 0x33, 0x0, 0x84, 0x40, 0x4C, 0xCC, 0xCD, 0x4, 0x31, 0x0, 0x1};
u32 D_80800B20_charmouredcaveman[18] = {0x31303AB,
                                        0x8FF0001,
                                        (u32) &D_80800AE0_charmouredcaveman,
                                        (u32) func_808000EC_charmouredcaveman,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x5DC0000,
                                        0x4019999A,
                                        0x0,
                                        0x40800124,
                                        0x0,
                                        (u32) func_80108ED0,
                                        0x0,
                                        (u32) func_8080000C_charmouredcaveman,
                                        (u32) func_80107C2C,
                                        0x84104410,
                                        (u32) func_80800370_charmouredcaveman,
                                        0x0};
u8 D_80800B68_charmouredcaveman[16] = {0x43, 0x48, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0,
                                       0x43, 0x48, 0x0, 0x0, 0x42, 0xF0, 0x0, 0x0};
u8 D_80800B78_charmouredcaveman[44] = {
    0x0,  0x1D, 0x9,  0xE3, 0x0,  0x15, 0x0,  0x0,  0x0,  0x99, 0x0,  0x22, 0x0,  0x38, 0x0,
    0x42, 0x0,  0x23, 0x0,  0x2E, 0x0,  0x2B, 0x0,  0x66, 0x0,  0x80, 0x0,  0x2D, 0x1,  0x2C,
    0x1,  0x90, 0x0,  0xB,  0x0,  0x14, 0x0,  0x1E, 0x0,  0x5,  0x0,  0x0,  0x0,  0x0};
u8 D_80800BA4_charmouredcaveman[12] = {0x0, 0x13, 0x4, 0x15, 0x0, 0xD,
                                       0x0, 0xF3, 0x1, 0xC,  0x0, 0x0};
u8 D_80800BB0_charmouredcaveman[12] = {0x0, 0x13, 0x4, 0x1D, 0x0, 0xD,
                                       0x1, 0xC,  0x1, 0x26, 0x0, 0x0};
u8 D_80800BBC_charmouredcaveman[16] = {0x3E, 0xE1, 0x47, 0xAE, 0x3F, 0xA,  0x3D, 0x71,
                                       0x3F, 0x1E, 0xB8, 0x52, 0xBF, 0x80, 0x0,  0x0};
CavemanFloats61 D_80800BCC_charmouredcaveman = {0.15f, 0.25f, 0.35f, 0.45f};
CavemanFloats61 D_80800BDC_charmouredcaveman = {0.9f, 1.1f, 1.05f, 1.0f};
s32 D_80800BEC_charmouredcaveman[2] = {0x5BC05BD, 0x5BD05BC};
s32 D_80800BF4_charmouredcaveman[2] = {0x6D6055F0, 0x55F055F0};
u8 D_80800BFC_charmouredcaveman[12] = {0x3, 0x6,  0x0, 0x1, 0x0, 0xC8,
                                       0xB, 0xB8, 0x0, 0x7, 0x0, 0x0};
s32 D_80800C08_charmouredcaveman[3] = {0x1305BC, 0xD0099, 0xB30000};
s32 D_80800C14_charmouredcaveman[3] = {0x130417, 0xD00F3, 0x10C0000};
s32 D_80800C20_charmouredcaveman[4] = {0x1305B6, 0xD00F3, 0x10C0018, 0x0};
