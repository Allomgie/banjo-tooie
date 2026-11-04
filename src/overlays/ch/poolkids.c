// Piglets' pool (Jolly Roger's Lagoon): two piglet NPCs plus a pool controller that fades the
// water layers. Flag 0x166 = toxic pools fixed, 0x167 = HFP hot pool drained; both give jiggy 0x22.
#include "common.h"


extern int D_808013F0_chpoolkids[];
extern int D_80801438_chpoolkids[];
extern void *D_80801480_chpoolkids;
extern u32 D_808014E8_chpoolkids[];
extern u32 D_808014F8_chpoolkids[];
extern void _gcdialogcamera_entrypoint_3(u32 *, f32);
typedef struct {
    s16 unk_0;
    s16 unk_2;
} PK2;
extern s32 _glcutDll_entrypoint_20();
extern void func_8010D600(f32 *);
extern f32 func_80102D78();
extern void func_80102BF8(u8 *, f32, f32, f32);
extern s32 D_80801520_chpoolkids[];
extern s32 func_80101E14(Actor *, f32);
extern s32 _fxsplash_entrypoint_2(f32 *, f32);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern int D_8080152C_chpoolkids[];
extern int D_8080153C_chpoolkids[];
extern int D_8080154C_chpoolkids[];
extern int D_8080155C_chpoolkids[];
extern int D_8080156C_chpoolkids[];
extern int D_8080157C_chpoolkids[];
extern void _subaddieaudioquick_entrypoint_4(int, int, int *, int *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern u8 D_80801594_chpoolkids[];
extern void _chpoolkids_entrypoint_3();
extern Actor *func_80106790(Unk80132ED0 *);
extern void *func_80100094(Actor *, u32);
extern u8 D_808012F8_chpoolkids[];
extern u8 D_808014C8_chpoolkids[];
extern u8 D_808012B0_chpoolkids[];
extern u8 D_808012D8_chpoolkids[];
extern f32 func_80101F24(Actor *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern s32 func_8008FB58(f32 *, f32, f32);
extern s32 func_800D9078();
extern u8 D_808014D8_chpoolkids[];
extern u8 D_80801318_chpoolkids[];
extern u8 D_80801340_chpoolkids[];
extern u8 D_80801360_chpoolkids[];
extern void func_80102424();
extern void func_80103014();
extern f32 D_80801508_chpoolkids[];
extern f32 D_80801514_chpoolkids[];
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_808015A0_chpoolkids[];
extern f32 D_808015EC_chpoolkids[];
extern void *func_800B5BE4(s32);
extern void *func_800BABB8(void *, f32 *, f32 *, f32, void *);
void func_808006F8_chpoolkids();
// Dialog end handler; 0x1022 gives the Piglets Pool jiggy.
void func_808007F0_chpoolkids();
void func_80800D74_chpoolkids();
void func_808008DC_chpoolkids();
void func_808011A8_chpoolkids();

// Piglets: proximity dialogs per pool state, swim effects, jiggy hand-out.
int chpoolkids_entrypoint_0()
{
    return (int) &D_808013F0_chpoolkids;
}

int chpoolkids_entrypoint_1()
{
    return (int) &D_80801438_chpoolkids;
}

// Pool controller: fades two mesh layers, runs the change cutscenes, steam and water sound.
int chpoolkids_entrypoint_2()
{
    return &D_80801480_chpoolkids;
}

int func_80800024_chpoolkids(Actor *actor)
{
    int section;
    // Matching: missing return is needed for the match.
    section = _subaddiesect_entrypoint_1();
    *(s32 *) ((char *) actor + 0x30) = section;
    _subaddiesect_entrypoint_2(actor, section, 1);
}

void func_80800944_chpoolkids(Actor *actor, f32 unk_0);

void func_80800058_chpoolkids(Actor *actor)
{
    s32 state;
    f32 anim_progress;
    if (func_80104248(actor)) {
        if (func_801022E4(actor) == 0x2B9) {
            anim_progress = func_80101F24(actor);
            *(f32 *) &actor->actorData[5] =
                func_80013970(func_800F10B4(anim_progress, 0.75f, 0.99f, 0.0f, 180.0f));
            if (anim_progress > 0.33f && anim_progress < 0.52f) {
                *((u8 *) actor + 0x77) = (*((u8 *) actor + 0x77) & ~0xF) | 2;
            } else {
                *((u8 *) actor + 0x77) = (*((u8 *) actor + 0x77) & ~0xF) | 1;
            }
        } else {
            *((u8 *) actor + 0x77) = (*((u8 *) actor + 0x77) & ~0xF) | 1;
            *(f32 *) &actor->actorData[5] = 0.0f;
        }
    }
    func_8008FB58(actor->position, 60.0f, 60.0f);
    state = actor->unk70_10;
    switch (state) {
        case 1:
            actor->actorData[4] = state;
            _subaddiedialog_entrypoint_8(actor, actor->position, D_808014C8_chpoolkids,
                                         D_808012B0_chpoolkids, 5);
            func_80800AA0_chpoolkids(actor);
            break;
        case 2:
            func_80800AA0_chpoolkids(actor);
            break;
        case 3:
            func_80800AA0_chpoolkids(actor);
            if (func_800D9078(&actor->unk58))
                _glcutDll_entrypoint_17();
            break;
        case 4:
            actor->actorData[4] = state;
            _subaddiedialog_entrypoint_8(actor, actor->position, D_808014C8_chpoolkids,
                                         D_808012D8_chpoolkids, 4);
            func_80800AA0_chpoolkids(actor);
            break;
        case 5:
            actor->actorData[4] = state;
            _subaddiedialog_entrypoint_8(actor, actor->position, D_808014C8_chpoolkids,
                                         D_808012F8_chpoolkids, 4);
            func_80800AA0_chpoolkids(actor);
            break;
        case 6:
            func_808008DC_chpoolkids(actor);
            func_80800944_chpoolkids(actor, 0.55f);
    }
}

void func_80800884_chpoolkids();

void func_80800290_chpoolkids(Actor *actor)
{
    s32 state;
    func_8008FB58(actor->position, 60.0f, 60.0f);
    switch (state = actor->unk70_10) {
        case 1:
            actor->actorData[4] = state;
            _subaddiedialog_entrypoint_8(actor, actor->position, D_808014D8_chpoolkids,
                                         D_80801318_chpoolkids, 5);
            func_80800B38_chpoolkids(actor);
            break;
        case 2:
            func_80800B38_chpoolkids(actor);
            break;
        case 4:
            actor->actorData[4] = state;
            _subaddiedialog_entrypoint_8(actor, actor->position, D_808014D8_chpoolkids,
                                         D_80801340_chpoolkids, 4);
            func_80800B38_chpoolkids(actor);
            break;
        case 5:
            actor->actorData[4] = state;
            _subaddiedialog_entrypoint_8(actor, actor->position, D_808014D8_chpoolkids,
                                         D_80801360_chpoolkids, 4);
            func_80800B38_chpoolkids(actor);
            break;
        case 6:
            func_80800884_chpoolkids(actor);
            func_808008DC_chpoolkids(actor);
            func_80800944_chpoolkids(actor, 0.9f);
            break;
    }
}

s32 func_808003DC_chpoolkids(Actor *actor, s32 event, PK2 data)
{
    s32 toxic_done;
    s32 hot_done;
    f32 morph_scale[2];
    s32 unk_0;
    switch (event) {
        case 0x2E:
            func_808007F0_chpoolkids(actor, data.unk_0, data.unk_2);
            break;
        case 0xC:
            toxic_done = func_800DA298(0x166);
            hot_done = func_800DA298(0x167);
            if (toxic_done && hot_done) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1022, 6, actor->position, 0xA0);
                return 3;
            }
            if (toxic_done) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1021, 6, actor->position, 0xA0);
                return 3;
            }
            _subaddiedialog_entrypoint_11(actor->unk0, 0x1020, 6, actor->position, 0xA0);
            return 3;
        case 0x1F:
            unk_0 = *(s32 *) &data;
            morph_scale[0] = morph_scale[1] = *(f32 *) &actor->actorData[5];
            _dbmorph_entrypoint_3((void *) func_800B2768(unk_0),
                                  (void *) func_80103CB8(actor, unk_0), func_800B2840(unk_0),
                                  1, morph_scale);
            func_801015D0(actor);
            break;
        case 0x49:
            if (actor->unk6C_9 != 0x3A3)
                return 0;
            if (_glcutDll_entrypoint_19(0x2A)) {
                _capod_entrypoint_13(actor->unk0, 0, 0x1F, 0x2830);
                break;
            }
            if (_glcutDll_entrypoint_19(0x29)) {
                _capod_entrypoint_13(actor->unk0, 0, 0x2A, 0x2830);
                break;
            }
            return 0;
        case 0x95:
            func_808006F8_chpoolkids(actor);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(actor->unk6C_9 == 0x3A3 ? D_808014E8_chpoolkids
                                                                   : D_808014F8_chpoolkids,
                                         actor->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800618_chpoolkids(actor) Actor *actor;
{
    func_80102424(actor, 6);
    switch (actor->unk6C_9) {
        case 0x3A3:
            func_800EE7F8(actor->position, D_80801508_chpoolkids);
            break;
        case 0x3A4:
            func_800EE7F8(actor->position, D_80801514_chpoolkids);
            func_801020DC(actor, 0);
            func_80101DAC(actor, 0);
    }
    if (!_glcutDll_entrypoint_20()) {
        func_800EF1B8(actor->position, func_800DC178(0.0f, 359.0f), func_800DC178(0.0f, 200.0f));
    }
    func_80103014(actor);
}

void func_808006F8_chpoolkids(actor) Actor *actor;
{
    s32 toxic_done;
    s32 hot_done;
    s32 clear_flags;

    clear_flags = 0;
    toxic_done = func_800DA298(0x166);
    hot_done = func_800DA298(0x167);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800618_chpoolkids(actor);
    } else if ((_glcutDll_entrypoint_19(0x2A) != 0) || (_glcutDll_entrypoint_19(0x29) != 0)) {
        clear_flags = 1;
    } else if ((toxic_done != 0) && (hot_done == 0)) {
        func_80102424(actor, 4);
    } else if ((toxic_done == 0) && (hot_done != 0)) {
        func_80102424(actor, 5);
    } else if ((toxic_done != 0) && (hot_done != 0)) {
        func_80800618_chpoolkids(actor);
    }
    if (clear_flags != 0) {
        func_800DA524(0x168);
        func_800DA524(0x1CE);
    }
}

// Dialog end handler; 0x1022 gives the Piglets Pool jiggy.
void func_808007F0_chpoolkids(actor, dialog_id, unk_0) Actor *actor;
s32 dialog_id;
s32 unk_0;
{
    switch (dialog_id) {
        case 0x1020:
        case 0x1021:
            _capod_entrypoint_14();
            _glcutDll_entrypoint_17();
            break;
        case 0x1022:
            func_800D0C78(0x22, 1, 0);
            actor->unk58 = 4.5f;
            func_80102424(actor, 3);
            break;
        default:
            func_80102424(actor, actor->actorData[4]);
    }
}

void func_80800884_chpoolkids(u8 *actor)
{
    f32 pos[3];
    if (!_glcutDll_entrypoint_20(actor)) {
        func_8010D600(pos);
        *(f32 *) (actor + 0x54) = func_80102D78(actor, pos);
        func_80102BF8(actor, 0.15f, 4.0f, 120.0f);
    }
}

void func_808008DC_chpoolkids(actor) Actor *actor;
{
    func_800D9078(&actor->unk58);
    if (actor->unk58 <= 0.0f) {
        _fxripple_entrypoint_0(3, actor->position);
        actor->unk58 = func_800DC178(0.6f, 1.2f);
    }
}

void func_80800944_chpoolkids(Actor *actor, f32 unk_0)
{
    f32 pos[3];
    s32 emitter;

    if (func_80101E14(actor, unk_0)) {
        func_800EE7F8(pos, actor->position);
        _subaddieaudioquick_entrypoint_2(actor, pos, &D_80801520_chpoolkids);
        _fxripple_entrypoint_0(3, pos);
        _fxsplash25d_entrypoint_0(pos);
        emitter = _fxsplash_entrypoint_2(pos, 35.0f);
        func_800BA930(emitter, -350, 300, -350, 350, 500, 350);
        func_800BA22C(emitter, 6);
        func_800BA930(emitter, -150, 500, -150, 150, 800, 150);
        func_800BA22C(emitter, 6);
        pos[1] -= 30.0f;
        emitter = _fxairbub_entrypoint_1(pos, 20.0f, actor->position[1], 1.0f);
        func_800BA930(emitter, -60, -250, -60, 60, -150, 60);
        func_800BA22C(emitter, 4);
    }
}

int func_80800AA0_chpoolkids(s32 actor)
{
    s32 unk_0;
    unk_0 = actor | 0; // Matching: the OR with 0 is needed for the match.
    _subaddieaudioquick_entrypoint_3(unk_0, unk_0 + 4, &D_8080152C_chpoolkids, 0x3ECCCCCD);
    _subaddieaudioquick_entrypoint_3(unk_0, unk_0 + 4, &D_8080153C_chpoolkids, 0x3e3851ec);
    _subaddieaudioquick_entrypoint_3(unk_0, unk_0 + 4, &D_8080154C_chpoolkids, 0x3f3ae148);
    _subaddieaudioquick_entrypoint_3(unk_0, unk_0 + 4, &D_8080155C_chpoolkids, 0x3f451eb8);
}

int func_80800B38_chpoolkids(s32 actor)
{
    s32 unk_0;
    unk_0 = actor + 4;
    _subaddieaudioquick_entrypoint_4(actor, unk_0, &D_8080156C_chpoolkids,
                                     &D_8080157C_chpoolkids);
}

// Pool controller: fades the dirty and cold water layers and drives the water loop sound.
void func_80800B68_chpoolkids(Actor *actor)
{
    u8 *state;
    s32 dirty_active;
    s32 dirty_fade_done;
    s32 cold_fade_done;
    s32 mesh;

    state = func_80100094(actor, 0);
    if (_gcmapsects_entrypoint_5(*(s16 *) state)) {
        dirty_active = *(s16 *) (state + 0x10) == 0;
        if (dirty_active || (!dirty_active && actor->unk5F)) { // Matching: redundant re-test of dirty_active.
            _subaddieaudioloop_entrypoint_5(actor, actor->position, dirty_active, -1,
                                            D_80801594_chpoolkids);
        }
        switch (*(s16 *) (state + 2)) {
            case 1:
                dirty_fade_done = func_800D9078((f32 *) (state + 4));
                *(f32 *) (state + 0xC) =
                    func_800F12D4(*(f32 *) (state + 4), 0.0f, 4.0f, 1.0f, 0.0f);
                if (dirty_fade_done) {
                    *(s16 *) (state + 0x10) = 1;
                    *(s16 *) (state + 2) = 0;
                }
                break;
            case 2:
                cold_fade_done = func_800D9078((f32 *) (state + 4));
                func_808011A8_chpoolkids(actor);
                func_800BF744(3, 1);
                *(f32 *) (state + 0x20) =
                    func_800F12D4(*(f32 *) (state + 4), 0.0f, 2.1f, 1.0f, 0.0f);
                if (cold_fade_done) {
                    *(s16 *) (state + 0x24) = 1;
                    *(s16 *) (state + 2) = 0;
                }
                break;
        }
        if (!*(s16 *) (state + 0x10) || !*(s16 *) (state + 0x24)) {
            mesh = func_800BEA88(1);
            if (mesh) {
                if (!*(s16 *) (state + 0x24) && func_800E3DC0(state + 0x28, state + 0x2E)) {
                    _glid_entrypoint_0(mesh, 1, _chpoolkids_entrypoint_3, actor->unk0);
                }
                if (!*(s16 *) (state + 0x10) && func_800E3DC0(state + 0x14, state + 0x1A)) {
                    _glid_entrypoint_0(mesh, 2, _chpoolkids_entrypoint_3, actor->unk0);
                }
            }
        }
    }
}

int func_80800D3C_chpoolkids(s32 actor, s32 event, s32 unk_0)
{
    if (event == 0x95) {
        func_80800D74_chpoolkids(actor);
        return 1;
    }
    return 0;
}

void func_80800D74_chpoolkids(actor) Actor *actor;
{
    u8 *state;
    s32 toxic_done;
    s32 hot_done;
    void *mesh;

    state = func_80100094(actor, 0);
    toxic_done = func_800DA298(0x166);
    hot_done = func_800DA298(0x167);
    *(s16 *) state = _gcmapsects_entrypoint_4(actor->position);
    *(s16 *) (state + 2) = 0;
    *(f32 *) (state + 4) = 0.0f;
    *(f32 *) (state + 8) = 0.0f;
    *(f32 *) (state + 0x20) = 0.0f;
    *(f32 *) (state + 0xC) = 0.0f;
    if (_glcutDll_entrypoint_20()) {
        toxic_done = 1;
        hot_done = 1;
    }
    if (toxic_done) {
        *(f32 *) (state + 0xC) = 1.0f;
    }
    if (hot_done) {
        *(f32 *) (state + 0x20) = 1.0f;
    }
    if (_glcutDll_entrypoint_19(0x2A)) {
        *(s16 *) (state + 2) = 1;
        *(f32 *) (state + 0xC) = 0.0f;
        *(f32 *) (state + 4) = 4.0f;
        *(f32 *) (state + 8) = 4.0f;
        _subaddieDll_entrypoint_4(actor, 1);
    } else if (_glcutDll_entrypoint_19(0x29)) {
        *(s16 *) (state + 2) = 2;
        *(f32 *) (state + 0x20) = 0.0f;
        *(f32 *) (state + 4) = 6.0f;
        *(f32 *) (state + 8) = 6.0f;
        _subaddieDll_entrypoint_4(actor, 1);
    }
    if (*(f32 *) (state + 0xC) == 1.0f) {
        *(s16 *) (state + 0x10) = 1;
    } else {
        *(s16 *) (state + 0x10) = 0;
    }
    if (*(f32 *) (state + 0x20) == 1.0f) {
        *(s16 *) (state + 0x24) = 1;
    } else {
        *(s16 *) (state + 0x24) = 0;
    }
    func_800BF744(3, 0);
    func_800BF744(2, *(s16 *) (state + 0x10) ? 0 : 1);
    mesh = func_800BEA88(1);
    _glidmake_entrypoint_2(mesh, 1, state + 0x28, state + 0x2E);
    _glidmake_entrypoint_2(mesh, 2, state + 0x14, state + 0x1A);
    _idworldmake_entrypoint_1(mesh, 0x8D, 1, 1);
    _idworldmake_entrypoint_1(mesh, 0x8D, 2, 1);
}

void chpoolkids_entrypoint_3(s32 layer, Vtx *src, Vtx *dst, s32 count,
                             Unk80132ED0 *unk_0)
{
    u8 *state;
    Vtx *end;
    f32 alpha_scale;

    state = func_80100094(func_80106790(unk_0), 0);
    switch (layer) {
        case 1:
            alpha_scale = 1.0f - *(f32 *) (state + 0x20);
            end = src + count;
            for (; src < end; src++, dst++) {
                dst->v.cn[3] = (u32) ((u32) src->v.cn[3] * alpha_scale);
            }
            break;
        case 2:
            alpha_scale = 1.0f - *(f32 *) (state + 0xC);
            end = src + count;
            for (; src < end; src++, dst++) {
                dst->v.cn[3] = (u32) ((u32) src->v.cn[3] * alpha_scale);
            }
    }
}

void func_808011A8_chpoolkids(actor) Actor *actor;
{
    void *emitter;
    s32 i;
    s32 count;

    emitter = func_800B5BE4(0x23);
    count = 1;
    for (i = 0; i < count; i++) {
        func_800BABB8(emitter, D_808015EC_chpoolkids, D_808015EC_chpoolkids, actor->scale * 1.15f,
                      D_808015A0_chpoolkids);
    }
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM). Its tables point to
// functions of this file; IDO assembler schedules some of them differently unless the tables
// are in the same unit.
extern void func_80105834();
extern void func_801018A4();
extern void func_80107C2C();
extern void func_80101870();
extern void func_80102EC0();
extern void func_8010A730();
u8 D_808012B0_chpoolkids[40] = {0x0,  0x0,  0x0,  0x1,  0x10, 0x14, 0x1,  0x0, 0x0,  0x0,
                                0x6,  0x1,  0x10, 0x16, 0x2,  0x0,  0x0,  0x0, 0x2,  0x0,
                                0x10, 0x61, 0x1,  0x0,  0x0,  0x0,  0x4,  0x0, 0x10, 0x62,
                                0x1,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
u8 D_808012D8_chpoolkids[32] = {0x0, 0x0,  0x2,  0x1,  0x10, 0x18, 0x1,  0x0, 0x0, 0x0,  0x6,
                                0x1, 0x10, 0x1A, 0x2,  0x0,  0x0,  0x0,  0x4, 0x0, 0x10, 0x65,
                                0x1, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0};
u8 D_808012F8_chpoolkids[32] = {0x0, 0x0,  0x2,  0x1,  0x10, 0x1C, 0x1,  0x0, 0x0, 0x0,  0x6,
                                0x1, 0x10, 0x1E, 0x2,  0x0,  0x0,  0x0,  0x4, 0x0, 0x10, 0x67,
                                0x1, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0};
u8 D_80801318_chpoolkids[40] = {0x0,  0x0,  0x0,  0x1,  0x10, 0x15, 0x1,  0x0, 0x0,  0x0,
                                0x6,  0x1,  0x10, 0x17, 0x2,  0x0,  0x0,  0x0, 0x2,  0x0,
                                0x10, 0x63, 0x1,  0x0,  0x0,  0x0,  0x4,  0x0, 0x10, 0x64,
                                0x1,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
u8 D_80801340_chpoolkids[32] = {0x0, 0x0,  0x4,  0x1,  0x10, 0x19, 0x1,  0x0, 0x0, 0x0,  0x6,
                                0x1, 0x10, 0x1B, 0x2,  0x0,  0x0,  0x0,  0x2, 0x0, 0x10, 0x66,
                                0x1, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0};
u8 D_80801360_chpoolkids[32] = {0x0, 0x0,  0x4,  0x1,  0x10, 0x1D, 0x1,  0x0, 0x0, 0x0,  0x6,
                                0x1, 0x10, 0x1F, 0x2,  0x0,  0x0,  0x0,  0x2, 0x0, 0x10, 0x68,
                                0x1, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0};
u32 D_80801380_chpoolkids[14] = {0x0,        0x0,        0x413547AE, 0x2B90000,  0x413547AE,
                                 0x2B90000,  0x413547AE, 0x2B90000,  0x413547AE, 0x2B90000,
                                 0x413547AE, 0x2B90000,  0x412E6666, 0x2C00000};
u32 D_808013B8_chpoolkids[14] = {0x0,        0x0,        0x40C0F5C3, 0x2BA0000,  0x40C0F5C3,
                                 0x2BA0000,  0x40C0F5C3, 0x2BA0000,  0x40C0F5C3, 0x2BA0000,
                                 0x40C0F5C3, 0x2BA0000,  0x40A00000, 0x2B40000};
int D_808013F0_chpoolkids[18] = {0x30C03A3,
                                 0x7D40001,
                                 (u32) &D_80801380_chpoolkids,
                                 (u32) func_80800058_chpoolkids,
                                 (u32) func_80105834,
                                 (u32) func_801018A4,
                                 0x7D00000,
                                 0x3F800000,
                                 0x0,
                                 0x800100,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_80800024_chpoolkids,
                                 (u32) func_80107C2C,
                                 -0x7BEF9B6E,
                                 (u32) func_808003DC_chpoolkids,
                                 0x0};
int D_80801438_chpoolkids[18] = {0x30D03A4,
                                 0x7D50001,
                                 (u32) &D_808013B8_chpoolkids,
                                 (u32) func_80800290_chpoolkids,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x7D00000,
                                 0x3F800000,
                                 0x0,
                                 0x100,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_80800024_chpoolkids,
                                 (u32) func_80107C2C,
                                 -0x7BEF9B6E,
                                 (u32) func_808003DC_chpoolkids,
                                 0x0};
void *D_80801480_chpoolkids = (void *) 0x032D03CD;
static u32 D_80801480_chpoolkids_rest[17] = {0x1,
                                             0x0,
                                             (u32) func_80800B68_chpoolkids,
                                             (u32) func_80102EC0,
                                             (u32) func_8010A730,
                                             0xBB80000,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x340000,
                                             0x0,
                                             (u32) func_80107C2C,
                                             0x80002602,
                                             (u32) func_80800D3C_chpoolkids,
                                             0x0};
u8 D_808014C8_chpoolkids[16] = {0x1, 0x68, 0x0, 0x0, 0x0, 0xFA, 0x0, 0xA0,
                                0x0, 0x0,  0x0, 0xC, 0x6, 0x32, 0x2, 0x0};
u8 D_808014D8_chpoolkids[16] = {0x1, 0xCE, 0x0, 0x0, 0x0, 0xFA, 0x0, 0xA1,
                                0x0, 0x0,  0x0, 0xC, 0x6, 0x32, 0x2, 0x0};
u32 D_808014E8_chpoolkids[4] = {0x430C0000, 0x42C80000, 0x42C80000, 0x42200000};
u32 D_808014F8_chpoolkids[4] = {0x430C0000, 0x43160000, 0x43160000, 0x42200000};
f32 D_80801508_chpoolkids[3] = {-1.57e+04f, 8189.0f, -7e+03f};
f32 D_80801514_chpoolkids[3] = {-1.48e+04f, 8189.0f, -8e+03f};
s32 D_80801520_chpoolkids[3] = {0x130409, 0xD00F3, 0x10C0000};
int D_8080152C_chpoolkids[4] = {0x130524, 0xD00F3, 0x10C0016, 0x46500000};
int D_8080153C_chpoolkids[4] = {0x13041D, 0xD00B3, 0xCC0016, 0x46500000};
int D_8080154C_chpoolkids[4] = {0x13055E, 0xD00F3, 0x10C0016, 0x46500000};
int D_8080155C_chpoolkids[4] = {0x1303FF, 0xD00F3, 0x10C0016, 0x46500000};
int D_8080156C_chpoolkids[4] = {0x130402, 0xD00F3, 0x10C0016, 0x5DC00000};
int D_8080157C_chpoolkids[6] = {0x3E4CCCCD, 0x3EB33333, 0x3F0A3D71,
                                0x3F47AE14, 0x3F7D70A4, -0x40800000};
u8 D_80801594_chpoolkids[12] = {0x0, 0x13, 0x6, 0x2C, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0, 0x0, 0x0};
u8 D_808015A0_chpoolkids[76] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x1B, 0x1,  0xC2, 0x2,  0x26, 0x0,  0x2D, 0x0, 0xC8, 0x0, 0xFA,
    0x0, 0xB,  0x0, 0x28, 0x0, 0x50, 0x0,  0xA,  0xFF, 0xF6, 0x0,  0x16, 0x6, 0x0,  0x0, 0x32,
    0x0, 0x0,  0x0, 0x33, 0x0, 0x2,  0x0,  0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x64,
    0x0, 0x22, 0x0, 0x91, 0x0, 0xAB, 0x0,  0xF8, 0x1,  0xF,  0x0,  0x15, 0x0, 0xC,  0x0, 0xA6,
    0x0, 0x2B, 0x0, 0x99, 0x0, 0xB3, 0x80, 0x2,  0x1,  0x1A, 0x0,  0x0};
f32 D_808015EC_chpoolkids[5] = {-1.53e+04f, 8.2e+03f, -8.2e+03f, 0.0f, 0.0f};
