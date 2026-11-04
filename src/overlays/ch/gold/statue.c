// The Golden Goliath statue in Mayahem Temple: wrapped in Mumbo magic when he casts, wakes up,
// hands control to the player as Golden Goliath, then stands in while that form is active.
#include "common.h"

extern void *func_80100094(Actor *, u32);
extern Vec3f D_80800910_chgoldstatue;
extern Vec3f D_8080091C_chgoldstatue;
extern Vec3f D_80800928_chgoldstatue;
extern Vec3f D_80800934_chgoldstatue;
extern f32 _sumumbofx_entrypoint_21(void *);
extern s32 _sumumbofx_entrypoint_5(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, Vec3f *, Vec3f *, Vec3f *);
extern void _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, Vec3f *, Vec3f *, Vec3f *);
extern int D_80800990_chgoldstatue[];
extern void func_800F7D38(s32, s32, f32 *, f32);
extern u8 D_80800890_chgoldstatue[];
extern u8 D_808008A0_chgoldstatue[];
extern u8 D_808008B8_chgoldstatue[];
extern u8 D_80800940_chgoldstatue[];
extern u8 D_80800954_chgoldstatue[];
extern u8 D_80800968_chgoldstatue[];
extern u8 D_8080097C_chgoldstatue[];
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern u8 _subaddieaudioloop_entrypoint_7();

// Wraps the statue in Mumbo magic (sumumbofx).
int func_80800000_chgoldstatue(s32 actor)
{
    s32 fx;
    s16 unk_0;
    unk_0 = _chmumbopad_entrypoint_0(2);
    fx = _sumumbofx_entrypoint_0(actor, 1, 0x2D, unk_0 | 0);
    fx = func_80100094(actor, 1);
    _sumumbofx_entrypoint_2(fx);
    _sumumbofx_entrypoint_24(fx, 0x3F266666);
    if (func_800DA298(0x57C) == 0) {
        _sumumbofx_entrypoint_15(fx, 0x40400000);
        return;
    }
    _sumumbofx_entrypoint_15(fx, 0x3E800000);
}

void func_80800094_chgoldstatue(s32 actor)
{
    _sumumbofx_entrypoint_1(actor, 1);
}

void func_808000B4_chgoldstatue(s32 actor, s32 value)
{
    Actor *fx;
    s32 level;

    fx = func_80100094(actor, 1);
    func_80101870(actor, value);
    if (fx != 0) {
        level = _sumumbofx_entrypoint_10(fx);
        _sumumbofx_entrypoint_8(fx, value);
        func_800DF5D8(0xFF, (s32) (((f32) level * 0.5f) + 128.0f), 0xFF, 0xFF);
    }
}

// State machine: 2 = awake, 3/4 = spell animation, 5 = hand over to player as Golden Goliath, 6/7 = stand-in.
void func_80800150_chgoldstatue(actor, state) Actor *actor;
s32 state;
{
    func_80102424(actor, state);
    switch (actor->unk70_10) {
        case 2:
            _subaddieDll_entrypoint_4(actor, 1);
            func_801032B0(actor, 0x673, actor->unk0->unk16);
            if (!func_800DA298(0x57C))
                _capod_entrypoint_13(actor->unk0, 0, 2, 0x20);
            else
                _capod_entrypoint_13(actor->unk0, 0, 8, 0x20);
            func_80101180(0x2B0, 0xBB, 2);
            func_80800000_chgoldstatue(actor);
            func_80090734(2, actor->position);
            break;
        case 3:
            func_800DA3B8(0x57C, 1);
            break;
        case 5:
            _capod_entrypoint_14();
            func_80800094_chgoldstatue(actor);
            func_800F7D38(func_800F54E4(), 0x3F, actor->position, actor->rotation[1]);
            func_800DA524(0x9DE);
            func_8010381C(actor);
            *((u8 *) actor + 0x65) &= ~1;
            break;
        case 6:
            if (*(u16 *) ((u8 *) actor + 0x64) & 1) {
                func_8010381C(actor);
                *((u8 *) actor + 0x65) &= ~1;
            }
            break;
        case 7:
            func_801032B0(actor, 0x673, actor->unk0->unk16);
            break;
    }
}

void func_808002C8_chgoldstatue(Actor *actor)
{
    _subaddieDll_entrypoint_1();
    if (func_8010D278() == 0xE) {
        func_80800150_chgoldstatue(actor, 6);
        return;
    }
    func_800DA524(0x9DE);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800150_chgoldstatue(actor, 7);
    }
}

void func_8080032C_chgoldstatue(Actor *actor)
{
    Vec3f zero = D_80800910_chgoldstatue;
    Vec3f bone_pos;
    Vec3f offset_up = D_8080091C_chgoldstatue;
    Vec3f offset_mid = D_80800928_chgoldstatue;
    Vec3f offset_down = D_80800934_chgoldstatue;
    void *fx;

    fx = func_80100094(actor, 1);
    if (actor->unk7C_12) {
        _subaddieskeleton_entrypoint_2(actor->unk0, 2, &bone_pos);
        _sumumbofx_entrypoint_7(fx, 175.0f, 0, 20, &offset_mid, &bone_pos, &zero);
        _sumumbofx_entrypoint_6(fx, 150.0f, 150.0f, 21, 35, &offset_down, &bone_pos, &zero);
        _sumumbofx_entrypoint_6(fx, 150.0f, 100.0f, 36, 45, &offset_up, &bone_pos, &zero);
        _sumumbofx_entrypoint_14(fx);
        if (actor->unk70_10 == 2 && _sumumbofx_entrypoint_21(fx) == 0.0f &&
            _sumumbofx_entrypoint_5(fx, 2.0f)) {
            _sumumbofx_entrypoint_17(fx, 1.0f);
            if (!func_800DA298(0x57C)) {
                func_80800150_chgoldstatue(actor, 3);
                return;
            }
            func_80800150_chgoldstatue(actor, 4);
        }
    }
}

void func_80800528_chgoldstatue(Actor *actor)
{
    s32 play_loop;
    void *fx;

    play_loop = 0;
    if (!actor->unk64_17) {
        fx = func_80100094(actor, 1);
        switch (actor->unk70_10) {
            case 1:
                _sudeflect_entrypoint_1(actor->position, 240.0f, 0.0f, 100.0f, 14);
                if (func_800DA298(0x9DE)) {
                    func_80800150_chgoldstatue(actor, 2);
                }
                break;
            case 2:
                func_8080032C_chgoldstatue(actor);
                break;
            case 3:
                if (func_80101E14(actor, 0.35f)) {
                    _chglowbo_entrypoint_6();
                }
                if (func_80101F24(actor) < 0.38f) {
                    play_loop = 1;
                }
                if (func_80101E14(actor, 0.38f)) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800890_chgoldstatue);
                } else if (func_80101E4C(actor, D_80800940_chgoldstatue)) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_808008A0_chgoldstatue);
                } else if (func_80101E4C(actor, D_80800954_chgoldstatue)) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_808008B8_chgoldstatue);
                }
                if (func_80101E14(actor, 0.39f)) {
                    func_800DA544(0x9DF);
                    _sumumbofx_entrypoint_16(fx, 3.0f);
                }
                func_8080032C_chgoldstatue(actor);
                if (func_80101DDC(actor)) {
                    func_80800150_chgoldstatue(actor, 5);
                }
                break;
            case 4:
                func_8080032C_chgoldstatue(actor);
                if (func_80101F24(actor) < 0.38f) {
                    play_loop = 1;
                }
                _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                                 D_80800890_chgoldstatue, 0.38f);
                if (func_80101E14(actor, 0.34f)) {
                    _sumumbofx_entrypoint_16(fx, 0.25f);
                    func_800DA544(0x9DF);
                } else if (func_80101E14(actor, 0.39f)) {
                    func_80800150_chgoldstatue(actor, 5);
                }
                break;
            case 5:
                if (!func_8010C500(actor)) {
                    func_80800150_chgoldstatue(actor, 6);
                }
                break;
            case 6:
                if (func_8010C500(actor)) {
                    func_800F7B9C(func_800F54E4(), 0x82);
                }
        }
        if (play_loop) {
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80800968_chgoldstatue);
            actor->unk6C_0 = _subaddieaudioloop_entrypoint_7(
                (u8) actor->unk6C_0, actor->position, 1, D_8080097C_chgoldstatue,
                *(u32 *) ((u8 *) actor + 0x70) & 1);
        }
    }
}

int chgoldstatue_entrypoint_0()
{
    return (int) &D_80800990_chgoldstatue;
}

// TU-NOTE: the overlay .data is defined here; IDO schedules some functions differently unless the tables are in the same unit.
extern void func_80105834();
extern void func_80107C2C();
u8 D_80800890_chgoldstatue[16] = {0x0, 0x13, 0x4, 0xCC, 0x0,  0x16, 0x7D, 0x0,
                                  0x0, 0x1,  0x9, 0xC4, 0x13, 0x88, 0x0,  0x0};
u8 D_808008A0_chgoldstatue[24] = {0x0, 0x13, 0x4,  0xA1, 0x0,  0xD,  0x0, 0xE1,
                                  0x0, 0xF3, 0x0,  0x16, 0x2A, 0xF8, 0x0, 0x1,
                                  0x9, 0xC4, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
u8 D_808008B8_chgoldstatue[24] = {0x0, 0x13, 0x6,  0x32, 0x0,  0xD,  0x0, 0x8C,
                                  0x0, 0xA6, 0x0,  0x16, 0x1F, 0x40, 0x0, 0x1,
                                  0x9, 0xC4, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
u32 D_808008D0_chgoldstatue[16] = {
    0x0,        0x0,       0x4159999A, 0x1ED0044, 0x4159999A, 0x1ED0044, 0x4159999A, 0x1ED0002,
    0x4159999A, 0x1ED0002, 0x40E00000, 0x1EE0002, 0x40E00000, 0x1EE0002, 0x40E00000, 0x1EE0001};
Vec3f D_80800910_chgoldstatue = {0.0f, 0.0f, 0.0f};
Vec3f D_8080091C_chgoldstatue = {0.0f, 2.5e+02f, 0.0f};
Vec3f D_80800928_chgoldstatue = {0.0f, 75.0f, 0.0f};
Vec3f D_80800934_chgoldstatue = {0.0f, -2.5e+02f, 0.0f};
u8 D_80800940_chgoldstatue[20] = {0x3E, 0xDC, 0x28, 0xF6, 0x3F, 0xF,  0x5C, 0x29, 0x3F, 0x45,
                                  0x1E, 0xB8, 0x3F, 0x66, 0x66, 0x66, 0xBF, 0x80, 0x0,  0x0};
u8 D_80800954_chgoldstatue[20] = {0x3F, 0x0,  0x0,  0x0,  0x3F, 0x28, 0xF5, 0xC3, 0x3F, 0x57,
                                  0xA,  0x3D, 0x3F, 0x78, 0x51, 0xEC, 0xBF, 0x80, 0x0,  0x0};
u8 D_80800968_chgoldstatue[20] = {0x0, 0x13, 0x4, 0xAD, 0x0, 0x16, 0x61, 0xA8, 0x0, 0xA,
                                  0x0, 0x99, 0x0, 0x1,  0x9, 0xC4, 0x13, 0x88, 0x0, 0x0};
u8 D_8080097C_chgoldstatue[20] = {0x0, 0x13, 0x4, 0xA9, 0x0, 0x16, 0x61, 0xA8, 0x0, 0xA,
                                  0x1, 0x0,  0x0, 0x1,  0x9, 0xC4, 0x13, 0x88, 0x0, 0x0};
int D_80800990_chgoldstatue[20] = {0x2750163,
                                   0x83E0001,
                                   (u32) &D_808008D0_chgoldstatue,
                                   (u32) func_80800528_chgoldstatue,
                                   (u32) func_80105834,
                                   (u32) func_808000B4_chgoldstatue,
                                   0x3E80000,
                                   0x0,
                                   0x0,
                                   0x80141,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_808002C8_chgoldstatue,
                                   (u32) func_80107C2C,
                                   -0x7FFFFBFE,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x0};
