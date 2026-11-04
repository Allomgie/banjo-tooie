#include "common.h"

#define AF(p, i) (*(f32 *) &(p)->actorData[i])
extern int D_80801580_chdippy[];
extern int D_808015C8_chdippy[];
typedef struct {
    u8 pad_0[0x70];
    u8 unk_70 : 7;
    u8 pad_1 : 1;
    u8 pad_2;
    u16 pad_3 : 6;
    u16 unk_72 : 6;
    u16 pad_4 : 4;
} DippyState1548;
extern int _glcutDll_entrypoint_20(void);
extern int _chcredits_entrypoint_1(void);
extern void _gccubesearch_entrypoint_3(s32, f32 *);
extern int func_800CBC3C(f32 *);
extern int func_800DA298(s32);
extern void func_800DA544(s32);
extern f32 func_800F5F24(s32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern s32 func_800F20BC(f32, f32, f32);
extern void func_8010D254(f32 *);
extern float D_80801490_chdippy[];
extern void *D_808014B0_chdippy;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64 : 11;
    u32 flag : 1;
    u32 rest : 20;
} BitsState;
extern void _capod_entrypoint_14();
extern Actor *func_80106790();
extern u8 D_80801610_chdippy[];
extern u8 D_808014A0_chdippy[];
extern u8 D_80801688_chdippy[];
extern u8 D_80801480_chdippy[];
extern u8 D_8080164C_chdippy[];
extern u8 D_80801698_chdippy[];
extern u8 D_8080165C_chdippy[];
extern u8 D_8080166C_chdippy[];
extern s32 D_80801620_chdippy[];
extern f32 func_80101F24(Actor *);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800BA544();
extern u8 D_808016E8_chdippy[];
extern u8 D_808016C4_chdippy[];
extern u8 D_808016DC_chdippy[];
extern s32 D_808014D8_chdippy[];
extern u8 D_808016B4_chdippy[];
extern u8 D_808016A4_chdippy[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} DippyState;
typedef struct {
    u8 pad_0[0x79];
    u8 cnt : 4;
    u8 low : 4;
} DippyCnt;
extern u8 D_808016F0_chdippy[];
extern u8 D_80801734_chdippy[];
extern void _chdippy_entrypoint_2(void);
extern void _chdippy_entrypoint_3(void);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800DC0C0(void);
extern void func_8010D930();
typedef struct DippyVisibilityFlags {
    u16 pad_0 : 15;
    u16 unk_64 : 1;
} DippyVisibilityFlags;
typedef union DippyEvent {
    s32 as_s32;
    f32 as_f32;
} DippyEvent;
extern void func_800DF500(f32, f32, f32);
extern u8 D_8080174C_chdippy[];
void func_80800CBC_chdippy();
void func_80800D44_chdippy();
int func_8080047C_chdippy();
void func_80800654_chdippy();
void func_80800800_chdippy();
void func_808009D8_chdippy();
void func_80801200_chdippy();

int chdippy_entrypoint_0()
{
    return (int) &D_80801580_chdippy;
}

int chdippy_entrypoint_1()
{
    return (int) &D_808015C8_chdippy;
}

void func_80800018_chdippy(Actor *actor)
{
    f32 pos[3];
    s32 unk_1;

    unk_1 = _glcutDll_entrypoint_20() && _chcredits_entrypoint_1() == 0x61;
    _gccubesearch_entrypoint_3(0x3AD, pos);
    ((DippyState1548 *) actor)->unk_70 = func_800CBC3C(pos) + 1;
    ((DippyState1548 *) actor)->unk_72 = 1;
    if (func_800DA298(0x327))
        func_800DA544(0x328);
    func_80800654_chdippy(actor, unk_1 ? 14 : 1);
}

void func_80800990_chdippy();

void func_80800530_chdippy();

void func_808000D8_chdippy(u8 *actor)
{
    unsigned int state_word;
    u32 state;
    state_word = *(u16 *) ((s8 *) actor + 0x72);
    state = (u16) state_word;
    state = state >> 0xA;
    switch (state) {
        case 1:
            func_80800530_chdippy(actor);
            return;

        case 3:
            if (func_80101E14(actor, 0x3F19999A) != 0) {
                _chintrotext_entrypoint_1(0x18B9, 0xE, 1, 0);
            }
            func_80800800_chdippy(actor);
            if (func_80101DDC(actor) != 0) {
                _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) actor + 0), 0x17E9, 6, actor + 4,
                                              0xAC);
                func_80800654_chdippy(actor, 5);
            }

            return;

        case 4:
            func_80800948_chdippy(actor);
            if (func_80101DDC(actor) != 0) {
                if (func_800DA298(0x327) != 0) {
                    func_80800654_chdippy(actor, 0xA);
                    return;
                }
                _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) actor + 0), 0x17EA, 7, actor + 4,
                                              0xAC);
                func_80800654_chdippy(actor, 5);
            }
            break;

        case 6:
            if (func_80101DDC(actor) != 0) {
                func_80800D44_chdippy(actor);
                func_80800654_chdippy(actor, 1);
            }
            break;

        case 7:
            func_80800990_chdippy(actor);
            if (func_80101DDC(actor) != 0) {
                _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) actor + 0), 0x17EB, 6, actor + 4,
                                              0xAC);
                func_80800654_chdippy(actor, 8);
            }
            break;

        case 9:
            if (func_80101DDC(actor) != 0) {
                func_80800D44_chdippy(actor);
                func_80800654_chdippy(actor, 1);
            }
            break;

        case 10:
            func_808009D8_chdippy(actor);
            if (func_80101DDC(actor) != 0) {
                _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) actor + 0), 0x17EC, 6, actor + 4,
                                              0xAC);
                func_80800654_chdippy(actor, 8);
            }
            break;

        case 11:
            if (func_80101DDC(actor) != 0) {
                _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) actor + 0), 0x17ED, 7, actor + 4,
                                              0xAC);
                func_80800654_chdippy(actor, 0xC);
            }
            break;

        case 13:
            if (func_80101DDC(actor) != 0) {
                func_80800D44_chdippy(actor);
                func_80800654_chdippy(actor, 1);
            }
            break;

        case 14:
            func_80800990_chdippy(actor);
            if (func_80101DDC(actor) != 0) {
                func_80800654_chdippy(actor, 0xF);
            }
    }
}

s32 func_80800374_chdippy(Actor *actor, s32 msg, s32 data)
{
    switch (msg) {
        case 0x2E:
            func_8080047C_chdippy(actor, ((s16 *) &data)[0], ((s16 *) &data)[1]);
            return 1;
        case 0xB:
            switch (data) {
                case 0x47:
                    func_80800654_chdippy(actor, 7);
                    return 4;
                case 0x37:
                    func_80800D44_chdippy(actor);
                    if (_glcutDll_entrypoint_19(0x36)) {
                        _glcutDll_entrypoint_17();
                    }
                    return 4;
            }
            return 3;
        case 0x95:
            if (_glcutDll_entrypoint_19(0x36)) {
                _subaddieDll_entrypoint_4(actor, 1);
                func_80800654_chdippy(actor, 2);
                func_80800CBC_chdippy(actor, 0x47, 0x2030);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

int func_8080047C_chdippy(actor, text_id, unused)
s32 actor;
u32 text_id;
Actor *unused;
{
    switch (text_id - 0x17E9) {
        case 0:
            func_80800654_chdippy(actor | 0, 6);
            return;

        case 1:
            func_80800654_chdippy(actor | 0, 6);
            return;

        case 2:
            func_80800654_chdippy(actor | 0, 0xA);
            return;

        case 3:
            func_800D0C78(0x2A, 1, 0);
            func_80800654_chdippy(actor | 0, 9);
            return;

        case 4:
            func_80800654_chdippy(actor | 0, 0xD);
    }
}

void func_80800530_chdippy(u8 *actor)
{
    s32 player;
    f32 pos[3];
    player = func_800F54E4();
    if (func_8010D23C() && func_800F6C5C(player) && func_800F64A4(player, 0x601) &&
        func_8010C500(actor)) {
        if (!func_800DA298(0x328)) {
            func_80800654_chdippy(actor, 3);
            return;
        }
        if (func_80016B30(0, 1) == 1 && func_800F4BB8(player, -1, 0)) {
            func_8010D254(pos);
            if (!func_800F20BC(func_800F5F24(player),
                               func_800F1DF4(pos, (f32 *) (actor + 4)), 60.0f)) {
                func_800F5FE0(player);
                return;
            }
            if (func_800DA298(0x327))
                func_80800654_chdippy(actor, 11);
            else
                func_80800654_chdippy(actor, 4);
        }
    }
}

void func_80800654_chdippy(actor, state) Actor *actor;
s32 state;
{
    f32 pos[3];
    _subaddieskeleton_entrypoint_3(actor->unk0, 5, pos, actor);
    func_80102424(actor, state);
    actor->unk64_16 = 1;
    switch (state) {
        case 1:
        case 2:
            actor->unk64_16 = 0;
            break;
        case 3:
            func_800DA544(0x328);
            func_80800CBC_chdippy(actor, 0x29, 0x30);
            break;
        case 4:
            func_80800CBC_chdippy(actor, 0x2E, 0x30);
            break;
        case 5:
            func_80800CBC_chdippy(actor, 0x31, 0x30);
            break;
        case 6:
            func_80800CBC_chdippy(actor, 0x37, 0x30);
            _subaddieaudioquick_entrypoint_2(actor, pos, D_80801610_chdippy);
            break;
        case 7:
            func_80800CBC_chdippy(actor, 0x2E, 0x30);
            break;
        case 8:
            func_80800CBC_chdippy(actor, 0x31, 0x30);
            break;
        case 9:
            func_80800CBC_chdippy(actor, 0x37, 0x30);
            break;
        case 10:
            func_80800CBC_chdippy(actor, 0x34, 0x30);
            break;
        case 11:
            func_80800CBC_chdippy(actor, 0x2E, 0x30);
            break;
        case 12:
            func_80800CBC_chdippy(actor, 0x31, 0x30);
            break;
        case 13:
            func_80800CBC_chdippy(actor, 0x37, 0x30);
            break;
    }
}

void func_80800800_chdippy(actor) Actor *actor;
{
    f32 pos[3];
    f32 anim_progress;
    s32 unk_2;
    anim_progress = func_80101F24(actor);
    unk_2 = func_8001211C();
    _subaddieskeleton_entrypoint_3(actor->unk0, 5, pos);
    _subaddieaudioquick_entrypoint_4(actor, pos, D_808014A0_chdippy, D_80801688_chdippy);
    _subaddieaudioquick_entrypoint_3(actor, pos, D_80801480_chdippy, 0.43f);
    _subaddieaudioquick_entrypoint_4(actor, pos, D_8080164C_chdippy, D_80801698_chdippy);
    _subaddieaudioquick_entrypoint_3(actor, pos, D_8080165C_chdippy, 0.9f);
    _subaddieaudioquick_entrypoint_3(actor, pos, D_8080166C_chdippy, 0.61f);
    if (anim_progress > 0.61f && anim_progress < 0.66f && !(unk_2 & 1) &&
        _subaddieskeleton_entrypoint_2(actor->unk0, 4, pos))
        func_800BBCB8(pos, 0, 1.0f, 1, D_80801620_chdippy);
}

int func_80800948_chdippy(Actor *actor)
{
    s32 pos[3];
    _subaddieskeleton_entrypoint_3(actor->unk0, 5, pos);
    _subaddieaudioquick_entrypoint_3(actor, pos, (int *) D_80801480_chdippy, 0.4f);
}

void func_80800990_chdippy(Actor *actor)
{
    f32 pos[3];

    _subaddieskeleton_entrypoint_3(actor->unk0, 5, pos);
    _subaddieaudioquick_entrypoint_3(actor, pos, &D_80801490_chdippy, 0.15f);
}

void func_808009D8_chdippy(actor) Actor *actor;
{
    f32 pos[3];
    f32 anim_progress;
    f32 mouth_pos[3];
    s32 pair_idx;
    f32 bone_pos[4][3];
    s32 i;
    s32 emitter;
    u8 *pair;

    anim_progress = func_80101F24(actor);
    _subaddieskeleton_entrypoint_3(actor->unk0, 5, pos);
    _subaddieaudioquick_entrypoint_4(actor, pos, D_808016A4_chdippy, D_808016C4_chdippy);
    _subaddieaudioquick_entrypoint_4(actor, pos, D_808016B4_chdippy, D_808016DC_chdippy);
    if (_subaddieskeleton_entrypoint_2(actor->unk0, 4, mouth_pos) && mouth_pos[1] < 1500.0f) {
        _subaddieskeleton_entrypoint_2(actor->unk0, 5, pos);
        pos[1] = 1500.0f;
        func_800BBCB8(pos, 0, 1.5f, 1, (s32 *) &D_808014B0_chdippy);
        _subaddieskeleton_entrypoint_2(actor->unk0, 7, pos);
        pos[1] = 1500.0f;
        func_800BBCB8(pos, 0, 1.5f, 1, (s32 *) &D_808014B0_chdippy);
    }
    if (anim_progress > 0.3f && actor->unk7C_12 && mouth_pos[1] > 1500.0f) {
        pair_idx = func_800DC128(0, 3);
        for (i = 0; i < 4; i++) {
            _subaddieskeleton_entrypoint_2(actor->unk0, i + 5, bone_pos[i]);
        }
        emitter = func_800B53A4(1);

        func_800BA994(emitter, -45, (s16) (actor->rotation[1] - 25.0f), 25, -25,
                      (s32) (actor->rotation[1] + 25.0f), 75);
        func_800BA5A8(emitter, 0x1200);
        func_800BABB8(emitter, mouth_pos, 0, 1.0f, D_808014D8_chdippy);
        func_800BA4D0(emitter, 1500);
        func_800BA544(emitter, _chdippy_entrypoint_2);
        pair = &D_808016E8_chdippy[pair_idx * 2];
        func_800BA1D0(emitter, bone_pos[pair[0]], bone_pos[pair[1]], 1);
    }
}

void chdippy_entrypoint_2(s32 unused, s32 pos)
{
    void *data = &D_808014B0_chdippy;
    func_800BBCB8(pos | 0, 0, 1.2f, 1, data);
}

void func_80800CBC_chdippy(actor, anim_id, flags) Actor *actor;
s32 anim_id;
u32 flags;
{
    if (actor->unk64_20) {
        _capod_entrypoint_14();
        flags |= 0x2000;
    }
    if (_glcutDll_entrypoint_19(0x36))
        flags |= 0x800;
    _capod_entrypoint_13(actor->unk0, 0, anim_id, flags);
    actor->unk64_20 = 1;
}

void func_80800D44_chdippy(actor) BitsState *actor;
{
    if (actor->flag) {
        _capod_entrypoint_14(actor);
        ((u8 *) actor)[0x65] &= ~0x10;
    }
}

int func_80800D84_chdippy(Actor *actor)
{
    *((u8 *) (((char *) actor) + 0x65)) = (*((u8 *) (((char *) actor) + 0x65))) & (~1);
    *((f32 *) (((char *) actor) + 0x1C)) = *((f32 *) (((char *) actor) + 0x8));
}

void func_80800D9C_chdippy(Actor *actor)
{
    s32 count;
    f32 spawn_pos[3];
    s32 emitter;
    s32 map_model;
    s32 model;
    s32 result;

    switch (((DippyState *) actor)->st) {
        case 2:
            func_800D9078(&actor->unk58);
            AF(actor, 0) = func_800F12D4(actor->unk58, 0.0f, 6.0f, 0.0f, -2000.0f);
            actor->position[1] = AF(actor, 1) + AF(actor, 0);
            if (1.0f < actor->unk58) {
                func_800BBCB8(actor->position, actor->position, 1.0f, 2, D_808016F0_chdippy);
            } else {
                actor->alpha = (s32) func_800F10B4(actor->unk58, 1.0f, 0.0f, 255.0f, 0.0f);
            }
            actor->unk64_16 = 1;
            result = func_800D90A4(&actor->actorData[2]);
            if (result) {
                actor->unk64_16 = 0;
                func_80101FDC(actor, 3);
            } else {
                if (func_800D90A4(&actor->actorData[3])) {
                    AF(actor, 3) = func_800DC178(0.2f, 0.5f);
                    func_8010D930(9, -1, actor->position, D_80801734_chdippy);
                }
                if (AF(actor, 2) < 15.0f) {
                    if (func_800DC0C0() < func_800F10B4(AF(actor, 2), 15.0f, 0.0f, 1.0f, 0.0f)) {
                        count = 1;
                    } else {
                        count = 0;
                    }
                } else {
                    count = func_800F10B4(AF(actor, 2), 30.0f, 0.0f, 3.0f, 1.0f);
                }
                if (count != 0) {
                    emitter = func_800B53A4(count);
                    func_800EE7F8(spawn_pos, actor->position);
                    spawn_pos[1] += 6000.0f;
                    func_800BA5A8(emitter, 0x200);
                    func_800BA714(emitter, 0x1F4, 0x1F4);
                    func_800BABB8(emitter, spawn_pos, 0, 1.0f, (u8 *) D_808014D8_chdippy);
                    func_800BA4D0(emitter, 0x5DC);
                    func_800BA544(emitter, _chdippy_entrypoint_2);
                    func_800BA22C(emitter, count);
                }
            }
            break;
        case 1:
        case 3:
            map_model = func_800BEA88(1);
            _glid_entrypoint_0(map_model, 1, _chdippy_entrypoint_3, actor->unk0);
            _glid_entrypoint_0(map_model, 2, _chdippy_entrypoint_3, actor->unk0);
            if (1) {
            }
            if (((DippyCnt *) actor)->cnt-- == 0) {
                func_800FFAB0(actor);
            }
    }

    model = func_800BEA88(1);
    result = _idworld_entrypoint_4(model, 1);

    if (result) {
        _idwibble_entrypoint_5(result, (s16) (s32) AF(actor, 0));
    }

    _glid_entrypoint_0(model, 2, _chdippy_entrypoint_3, actor->unk0);
}

s32 func_80801110_chdippy(Actor *actor, s32 msg, DippyEvent data)
{
    f32 cam_pos[3];

    switch (msg) {
        case 0x95:
            func_80801200_chdippy();
            return 1;
        case 0x1F:
            if (((DippyVisibilityFlags *) ((u8 *) actor + 0x64))->unk_64) {
                func_801015D0(actor);
                func_800E3980(cam_pos);
                actor->rotation[1] = func_800F1DF4(actor->position, cam_pos);
                if (actor->unk58 < 3.0f) {
                    func_800DF500(1.0f, func_800F10B4(actor->unk58, 3.0f, 0.0f, 5.0f, 0.001f),
                                  1.0f);
                } else {
                    func_800DF500(1.0f, 5.0f, 1.0f);
                }
            }
            return 1;
    }

    return 0;
}

void func_80801200_chdippy(actor) Actor *actor;
{
    s32 map_model = func_800BEA88(1);

    if (_glcutDll_entrypoint_20()) {
        actor->unk79_4 = 2;
        *(f32 *) &actor->actorData[0] = 0.0f;
        func_80101FDC(actor, 3);
    } else if (_glcutDll_entrypoint_19(0x36)) {
        actor->unk58 = 6.0f;
        func_80101FDC(actor, 2);
        actor->unk64_16 = 1;
        *(f32 *) &actor->actorData[2] = 30.0f;
        *(f32 *) &actor->actorData[3] = func_800DC178(0.2f, 0.5f);

    } else {
        if (!func_800DA298(0x327)) {
            actor->unk79_4 = 2;
            *(f32 *) &actor->actorData[0] = -2000.0f;
            func_80101FDC(actor, 1);
            return;
        }

        actor->unk79_4 = 2;
        *(f32 *) &actor->actorData[0] = 0.0f;
        func_80101FDC(actor, 3);
    }
    _idworldmake_entrypoint_1(map_model, 0x659, 1, 1);
    if (actor->unk70_10 == 2)
        func_800C4AF0(actor->actorData, D_8080174C_chdippy);
}

void chdippy_entrypoint_3(void *unused, Vtx *src, Vtx *dst, s32 count,
                          Unk80132ED0 *ctx)
{
    s16 offset;
    Vtx *end;
    offset = *(f32 *) &func_80106790(ctx)->actorData[0];
    end = dst + count;
    for (; dst < end; dst++, src++) {
        dst->v.ob[1] = src->v.ob[1] + offset;
    }
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_801018A4();
u8 D_80801480_chdippy[16] = {0x0, 0x13, 0x4, 0xCA, 0x0, 0x2,  0x0, 0x18,
                             0x0, 0xD,  0x0, 0x73, 0x0, 0x8C, 0x0, 0x0};
float D_80801490_chdippy[4] = {1.746592e-39f, 1.83705e-40f, 1.194076e-39f, 1.6438554e-38f};
u8 D_808014A0_chdippy[16] = {0x0, 0x13, 0x5, 0x51, 0x0, 0x2,  0x0, 0x18,
                             0x0, 0xD,  0x0, 0xCC, 0x0, 0xE6, 0x0, 0x0};
void *D_808014B0_chdippy = (void *) 0x001D09DB;
static u32 D_808014B0_chdippy_rest[9] = {0x160001, 0x2B00B3,  0xB30015,   0xB3, 0x2200CC,
                                         0xCC01CC, 0x1E6001F, 0xFFFFFE00, 0x0};
s32 D_808014D8_chdippy[10] = {0x1D09F3, 0x20FFFF,   -0x14BFFDE, 0x660080,  0x33004C,
                              0x1BF254, -0xDABFFF9, 0x1002B,    0xA000A00, 0x0};
u32 D_80801500_chdippy[32] = {
    0x0,        0x0,       0x0,        0x0,       0x0,        0x0,       0x41800000, 0x2D70002,
    0x40800000, 0x2D90002, 0x4104CCCD, 0x2D80001, 0x40600000, 0x2DA0002, 0x3FCCCCCD, 0x2DE0002,
    0x40B66666, 0x2DC0001, 0x40666666, 0x2DD0002, 0x40E33333, 0x2DB0002, 0x3FCCCCCD, 0x2DE0002,
    0x4099999A, 0x2DF0001, 0x3FCCCCCD, 0x2E00002, 0x3FCCCCCD, 0x2DE0002, 0x40B66666, 0x2DC0001};
int D_80801580_chdippy[18] = {0x340042D,
                              0x7E90005,
                              (u32) &D_80801500_chdippy,
                              (u32) func_808000D8_chdippy,
                              (u32) func_80105834,
                              (u32) func_80101870,
                              0x13880000,
                              0x0,
                              0x0,
                              0x448,
                              0x0,
                              0x0,
                              0x0,
                              (u32) func_80800018_chdippy,
                              (u32) func_80107C2C,
                              -0x7FFFFBFE,
                              (u32) func_80800374_chdippy,
                              0x0};
int D_808015C8_chdippy[18] = {0x1580441,
                              0x8DF0002,
                              0x0,
                              (u32) func_80800D9C_chdippy,
                              (u32) func_80105834,
                              (u32) func_801018A4,
                              0x0,
                              0x0,
                              0x0,
                              0x21C40,
                              0x0,
                              0x0,
                              0x0,
                              (u32) func_80800D84_chdippy,
                              (u32) func_80107C2C,
                              -0x7FFFDBFE,
                              (u32) func_80801110_chdippy,
                              0x0};
u8 D_80801610_chdippy[16] = {0x0, 0x13, 0x5, 0x14, 0x0, 0x2,  0x0, 0x18,
                             0x0, 0xD,  0x0, 0x33, 0x0, 0x4C, 0x0, 0x0};
s32 D_80801620_chdippy[11] = {0x1D09DD, 0x160200, 0x2B01CC, 0x2330022, 0x1800200, 0x4800600,
                              0x150000, 0x260019, 0x7,      0x1FDEA7,  0x71000000};
u8 D_8080164C_chdippy[16] = {0x0, 0x13, 0x4, 0x30, 0x0, 0x2, 0x0, 0xD,
                             0x0, 0x80, 0x0, 0x99, 0x0, 0x0, 0x0, 0x0};
u8 D_8080165C_chdippy[16] = {0x0, 0x13, 0x4, 0xF8, 0x0, 0x2, 0x0, 0x18,
                             0x0, 0xA,  0x0, 0x80, 0x0, 0x0, 0x0, 0x0};
u8 D_8080166C_chdippy[28] = {0x0, 0x13, 0x4, 0x10, 0x0, 0x2,  0x0, 0x18, 0x0, 0x15,
                             0x0, 0x0,  0x1, 0x0,  0x0, 0x33, 0x0, 0xC,  0x0, 0x0,
                             0x1, 0x33, 0x0, 0x33, 0x0, 0xB3, 0x0, 0x0};
u8 D_80801688_chdippy[16] = {0x3D, 0x8F, 0x5C, 0x29, 0x3D, 0xF5, 0xC2, 0x8F,
                             0x3E, 0xF,  0x5C, 0x29, 0xBF, 0x80, 0x0,  0x0};
u8 D_80801698_chdippy[12] = {0x3F, 0x4A, 0x3D, 0x71, 0x3F, 0x54, 0x7A, 0xE1, 0xBF, 0x80, 0x0, 0x0};
u8 D_808016A4_chdippy[16] = {0x0, 0x13, 0x4, 0xA,  0x0, 0x2,  0x0, 0x18,
                             0x0, 0xD,  0x0, 0x59, 0x0, 0x73, 0x0, 0x0};
u8 D_808016B4_chdippy[16] = {0x0, 0x13, 0x4, 0x34, 0x0, 0x2,  0x0, 0x18,
                             0x0, 0xD,  0x0, 0x73, 0x0, 0xA6, 0x0, 0x0};
u8 D_808016C4_chdippy[24] = {0x3E, 0x75, 0xC2, 0x8F, 0x3E, 0xB8, 0x51, 0xEC, 0x3F, 0x1E, 0xB8, 0x52,
                             0x3F, 0x33, 0x33, 0x33, 0x3F, 0x4C, 0xCC, 0xCD, 0xBF, 0x80, 0x0,  0x0};
u8 D_808016DC_chdippy[12] = {0x3E, 0xF0, 0xA3, 0xD7, 0x3F, 0x6B, 0x85, 0x1F, 0xBF, 0x80, 0x0, 0x0};
u8 D_808016E8_chdippy[8] = {0x1, 0x0, 0x0, 0x3, 0x2, 0x3, 0x0, 0x0};
u8 D_808016F0_chdippy[68] = {0x0, 0x1D, 0x9,  0xDD, 0x0,  0x16, 0x12, 0x10, 0x0,  0x18, 0x0, 0x0,
                             0x0, 0x7,  0x1E, 0x0,  0x1E, 0x0,  0x0,  0x2D, 0x0,  0xC8, 0x1, 0x2C,
                             0x0, 0xB,  0x0,  0xB4, 0x0,  0xB4, 0x0,  0x1E, 0xFF, 0xF6, 0x0, 0x22,
                             0x1, 0xCC, 0x2,  0x33, 0x0,  0xCC, 0x1,  0x0,  0xC0, 0x2,  0x0, 0x15,
                             0x0, 0x19, 0x0,  0x99, 0x0,  0x2B, 0x1,  0x33, 0x1,  0x66, 0x0, 0x1B,
                             0x0, 0xC8, 0x1,  0x2C, 0x0,  0x0,  0x0,  0x0};
u8 D_80801734_chdippy[24] = {0x0,  0x13, 0x5, 0x53, 0x0, 0xD, 0x1,  0x0,  0x1, 0x66, 0x0, 0x16,
                             0x46, 0x50, 0x0, 0x1,  0x0, 0x0, 0x27, 0x10, 0x0, 0x0,  0x0, 0x0};
u8 D_8080174C_chdippy[36] = {0x0, 0x13, 0x3, 0xEC, 0x0, 0x18, 0x0, 0xA,  0x0, 0x4C, 0x0, 0xA,
                             0x1, 0x0,  0x0, 0x15, 0x0, 0x33, 0x5, 0x4C, 0x0, 0x80, 0x0, 0x14,
                             0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
