#include "common.h"

// Crushing Shed boulder: lifted by Mumbo's levitate magic outside (map 0xC7), then
// dropped onto and ground down by the crusher inside (map 0xCB).

extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern Vec3f D_80801388_chcrusherboulder;
extern Vec3f D_80801394_chcrusherboulder;
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, f32 *, f32 *);
extern void func_80105A9C(Actor *, f32);
extern f32 func_800DC178(f32, f32);
typedef struct {
    u8 pad[0x74];
    u32 pad74 : 2;
    u32 flag : 1;
    u32 rest : 29;
} CrushS;
extern void _sudeflect_entrypoint_0(u8 *, f32, f32, s32);
extern s32 D_80801470_chcrusherboulder[];
extern void *D_80801464_chcrusherboulder;
extern void func_800BBCB8(void *param_0, int param_1, float param_2, int param_3, s32 *param_4);
extern s32 D_808014BC_chcrusherboulder[];
extern int D_808014EC_chcrusherboulder[];
extern f32 D_808013A0_chcrusherboulder[];
extern s32 func_80100094(Actor *, s32);
extern f32 func_800D8FF8(void);
extern s32 func_800DA298(s32);
extern void func_800DA544(s32);
extern f32 _sumumbofx_entrypoint_22(s32);
extern void _sumumbofx_entrypoint_1(Actor *, s32);
extern void func_8010A800(Actor *, s32);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern f32 func_800DC0C0(void);
extern u8 _subaddieaudioloop_entrypoint_7();
extern void func_800187B4(s32, f32, f32, f32);
extern f32 D_808013B4_chcrusherboulder[];
extern f32 D_808013C0_chcrusherboulder[];
extern f32 D_808013C8_chcrusherboulder[];
extern f32 D_80801360_chcrusherboulder[];
extern f32 D_808013D4_chcrusherboulder[];
extern f32 D_80801374_chcrusherboulder[];
extern void func_80101FDC(Actor *, s32);
extern s32 _chmumbopad_entrypoint_0(s32);
extern void _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
extern void _sumumbofx_entrypoint_2(s32);
extern void _sumumbofx_entrypoint_3(s32, f32);
extern void _sumumbofx_entrypoint_4(s32);
extern void _sumumbofx_entrypoint_12(s32, f32 *, f32 *, f32 *);
extern void _sumumbofx_entrypoint_15(s32, f32);
extern void _sumumbofx_entrypoint_16(s32, f32);
extern void _sumumbofx_entrypoint_24(s32, f32);
extern void _sumumbofx_entrypoint_25(s32, s32, f32 *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern u8 _subaddieaudioloop_entrypoint_3();
extern void func_80101180(s32, s32, s32);
extern Vec3f D_808013E0_chcrusherboulder;
extern u8 D_808013EC_chcrusherboulder[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 D_808013FC_chcrusherboulder[];
extern s32 D_8080143C_chcrusherboulder[];
extern s32 D_80801450_chcrusherboulder[];
void func_80800A1C_chcrusherboulder();
void func_80800F38_chcrusherboulder();
void func_80801064_chcrusherboulder();

void func_80800000_chcrusherboulder(Actor *actor, s32 arg)
{
    f32 saved_pos[3];
    f32 rot[3];
    void *fx;
    s32 unk_0;
    f32 *pos;

    fx = func_80100094(actor, 1);
    rot[0] = -actor->rotation[0];
    rot[1] = actor->rotation[1];
    rot[2] = actor->rotation[2];
    if (fx) {
        unk_0 = _sumumbofx_entrypoint_10(fx);
        func_800DF5D8(unk_0, 255, unk_0, 255);
    }
    pos = actor->position;
    func_800EE7F8(saved_pos, pos);
    func_800EF5A0(pos, rot, 0.0f, 150.0f, 0.0f);
    func_800EF04C(pos, saved_pos);
    actor->position[1] -= 150.0f;
    if (fx) {
        _sumumbofx_entrypoint_9(fx, arg);
    }
    func_80101870(actor, arg);
    func_800EE7F8(pos, saved_pos);
    if (fx) {
        _sumumbofx_entrypoint_8(fx, arg);
    }
}

void func_80800100_chcrusherboulder(void *fx, f32 *pos)
{
    Vec3f zero;
    Vec3f offset;

    zero = D_80801388_chcrusherboulder;
    offset = D_80801394_chcrusherboulder;
    _sumumbofx_entrypoint_7(fx, 225.0f, 0, 25, pos, offset.f, zero.f);
    _sumumbofx_entrypoint_14(fx);
    pos[1] += 300.0f;
    _sumumbofx_entrypoint_11(fx, pos);
    pos[1] -= 300.0f;
}

int func_808001CC_chcrusherboulder(s32 actor)
{
    s32 fx;
    fx = func_80100094(actor, 1);
    _sumumbofx_entrypoint_5(fx | 0, 0x40400000);
    func_80800100_chcrusherboulder(fx, actor + 4);
}

void func_80800210_chcrusherboulder(Actor *actor)
{
    f32 saved_rot[3];
    s32 i;

    if (actor->unk58 < 20.0f) {
        func_800EE7F8(saved_rot, actor->rotation);
        func_80105A9C(actor, 80.0f);
        func_80105834(actor);
        func_800EE7F8(actor->rotation, saved_rot);
    }
    for (i = 0; i < 3; i++) {
        actor->rotation[i] += func_800DC178(-0.25f, 0.25f);
        actor->rotation[i] =
            actor->rotation[i] < -10.0f
                ? -10.0f
                : (actor->rotation[i] > 10.0f ? 10.0f : actor->rotation[i]);
    }
}

void func_80800338_chcrusherboulder(actor) Actor *actor;
{
    s32 fx;
    u8 audio_state;

    fx = func_80100094(actor, 1);
    switch (actor->unk70_10) {
        case 2:
            func_80800100_chcrusherboulder(fx, actor->position);
            if (5.0f < actor->position[1]) {
                actor->position[1] -= 210.0f * func_800D8FF8();
            } else {
                actor->unk64_20 = 0;
                actor->unk58 = 0.0f;
                func_80800A1C_chcrusherboulder(actor, 3);
            }
            break;
        case 3:
            func_80800100_chcrusherboulder(fx, actor->position);
            actor->position[1] = 15.0f;
            *(f32 *) &actor->actorData[7] = 0.0f;
            if (func_800DA298(0x4FB)) {
                func_80800A1C_chcrusherboulder(actor, 5);
            } else {
                func_80800A1C_chcrusherboulder(actor, 4);
            }
            func_800DA544(0x4FD);
            func_800DA544(0x9DF);
            break;
        case 4:
            func_80800100_chcrusherboulder(fx, actor->position);
            if (_sumumbofx_entrypoint_22(fx) <= 0.02f) {
                _sumumbofx_entrypoint_1(actor, 1);
                func_8010A800(actor, 0);
                func_80800A1C_chcrusherboulder(actor, 6);
            }
            break;
        case 6:
            if (func_800DA298(0x4FB)) {
                _capod_entrypoint_13(actor->unk0, 0, 4, 0x4030);
                func_80800A1C_chcrusherboulder(actor, 7);
            }
            break;
        case 5:
            func_80800100_chcrusherboulder(fx, actor->position);
            if (_sumumbofx_entrypoint_22(fx) <= 0.02f) {
                _sumumbofx_entrypoint_1(actor, 1);
                func_8010A800(actor, 0);
                func_80800A1C_chcrusherboulder(actor, 7);
            }
        case 7:
            if (actor->position[0] < -2850.0f) {
                func_80800A1C_chcrusherboulder(actor, 12);
            }
            if (actor->position[0] < -1900.0f) {
                if (-2350.0f < actor->position[0]) {
                    if (*(f32 *) &actor->actorData[7] < 500.0f) {
                        *(f32 *) &actor->actorData[7] += 2.0f;
                    }
                } else if (0.0f < *(f32 *) &actor->actorData[7]) {
                    *(f32 *) &actor->actorData[7] -= 2.0f;
                }
                if (-325.0f < actor->position[2]) {
                    if (func_800DC0C0() < 0.4f) {
                        actor->position[2] -= func_800DC178(4.0f, 8.0f);
                        actor->rotation[2] = -func_800DC178(2.0f, 8.0f);
                    }
                }
                if (actor->position[2] < -375.0f) {
                    if (func_800DC0C0() < 0.4f) {
                        actor->position[2] += func_800DC178(4.0f, 8.0f);
                        actor->rotation[2] = func_800DC178(2.0f, 8.0f);
                    }
                }
                if (actor->unk74_30) {
                    actor->position[0] -= 144.0f * func_800D8FF8() * func_800DC178(0.2f, 0.3f);
                    audio_state = _subaddieaudioloop_entrypoint_7(
                        *(u8 *) &actor->actorData[3], actor->position, 1,
                        D_808013A0_chcrusherboulder, *(u32 *) ((u8 *) actor + 0x70) & 1);
                    *(f32 *) &actor->actorData[3] = *(f32 *) &audio_state;
                    if (func_800DC0C0() < 0.2f) {
                        actor->unk74_30 = 0;
                    }
                } else {
                    actor->position[0] -= 144.0f * func_800D8FF8() * func_800DC178(0.9f, 1.0f);
                    if (func_800DC0C0() < 0.2f) {
                        actor->unk74_30 = 1;
                    }
                }
                func_80800F38_chcrusherboulder(actor);
                if (!actor->unk64_20) {
                    func_800187B4(0, 1.0f, 1.0f, 6.5f);
                    actor->unk64_20 = 1;
                }
            } else {
                actor->position[0] -= 144.0f * func_800D8FF8();
            }
        case 1:
        case 12:
            break;
    }
}

void func_808010EC_chcrusherboulder();

void func_8080087C_chcrusherboulder(actor) Actor *actor;
{
    switch (actor->unk70_10) {
        case 1:
            if (func_800DA9E4(0x9DE, 0))
                func_80800A1C_chcrusherboulder(actor, 8);
            break;
        case 8:
            func_80800210_chcrusherboulder(actor);
            func_808001CC_chcrusherboulder(actor);
            if (actor->unk58 > 0.0f)
                actor->unk58 -= func_800D8FF8();
            else if (!actor->unk64_19) {
                _chglowbo_entrypoint_6();
                actor->unk64_19 = 1;
            }
            break;
        case 11:
            actor->unk58 -= func_800D8FF8();
            if (actor->unk58 > 0.0f && !(func_8001211C() & 2) && func_800DC0C0() < 0.3f)
                func_808010EC_chcrusherboulder();
    }
}

void func_808009C0_chcrusherboulder(CrushS *actor)
{
    _sudeflect_entrypoint_0((u8 *) actor + 4, 1.5e+02f, 240.0f, 0xA);
    if (actor->flag) {
        func_80800338_chcrusherboulder(actor);
    } else {
        func_8080087C_chcrusherboulder(actor);
    }
}

void func_80800A1C_chcrusherboulder(actor, state) Actor *actor;
s32 state;
{
    s32 fx;
    f32 fx_target[3];
    u8 audio_state;
    s32 fx_b;
    f32 fx_target_b[3];

    fx = func_80100094(actor, 1);
    func_80101FDC(actor, state);
    switch (state) {
        case 2:
            actor->position[1] = 750.0f;
            _sumumbofx_entrypoint_0(actor, 1, 25, _chmumbopad_entrypoint_0(1));
            fx = func_80100094(actor, 1);
            _sumumbofx_entrypoint_2(fx);
            _sumumbofx_entrypoint_4(fx);
            _sumumbofx_entrypoint_15(fx, 0.1f);
            _sumumbofx_entrypoint_25(fx, 0x80, D_808013B4_chcrusherboulder);
            func_8010A800(actor, 2);
            _sumumbofx_entrypoint_3(fx, 250.0f);
            fx_target[0] = actor->position[0];
            fx_target[1] = actor->position[1] + 300.0f;
            fx_target[2] = actor->position[2];
            _sumumbofx_entrypoint_12(fx, fx_target, D_808013C0_chcrusherboulder,
                                     D_808013C8_chcrusherboulder);
            break;
        case 4:
        case 5:
            _sumumbofx_entrypoint_16(fx, 0.5f);
            break;
        case 3:
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_80801360_chcrusherboulder);
            func_800E1610(0, 10.0f, 0.8f, actor->position);
            break;
        case 6:
            actor->position[1] = 15.0f;
            break;
        case 7:
            func_800DA544(0x4FF);
            func_800DA544(0);
            actor->unk74_30 = 0;
            break;
        case 12:
            _subaddieaudioloop_entrypoint_2(actor);
            audio_state = _subaddieaudioloop_entrypoint_3(*(u8 *) &actor->actorData[3]);
            *(f32 *) &actor->actorData[3] = *(f32 *) &audio_state;
            break;
        case 8:
            _sumumbofx_entrypoint_0(actor, 1, 45, _chmumbopad_entrypoint_0(1));
            fx_b = func_80100094(actor, 1);
            _sumumbofx_entrypoint_2(fx_b);
            _sumumbofx_entrypoint_24(fx_b, 0.65f);
            _sumumbofx_entrypoint_15(fx_b, 3.0f);
            _sumumbofx_entrypoint_25(fx_b, 0x80, D_808013B4_chcrusherboulder);
            func_8010A800(actor, 2);
            fx_target_b[0] = actor->position[0];
            fx_target_b[1] = actor->position[1] + 300.0f;
            fx_target_b[2] = actor->position[2];
            _sumumbofx_entrypoint_12(fx_b, fx_target_b, D_808013C0_chcrusherboulder,
                                     D_808013C8_chcrusherboulder);
            func_80800210_chcrusherboulder(actor);
            _capod_entrypoint_13(actor->unk0, 0, 6, 0x4810);
            actor->unk58 = 22.5f;
            break;
        case 11:
            _capod_entrypoint_13(actor->unk0, 0, 8, 0x2830);
            actor->unk64_16 = 0;
            actor->unk58 = 3.0f;
            func_808010EC_chcrusherboulder();
            func_80101180(0x180, 10, 0);
            _subaddieaudioquick_entrypoint_2(actor, D_808013D4_chcrusherboulder,
                                             D_80801374_chcrusherboulder);
    }
}

void func_80800D3C_chcrusherboulder(Actor *actor)
{
    *(f32 *) ((s8 *) actor + 0x38) = 0.7f;
    if (func_800EA05C() == 0xCB) {
        actor->unk74_29 = 1;
    } else {
        actor->unk74_29 = 0;
    }
    if (actor->unk74_29) {
        if ((func_800DA298(0x4FF) != 0) || (func_800DA298(0x4FC) == 0)) {
            func_800FFAB0(actor);
            return;
        }
        if (func_800DA298(0x4FC) != 0) {
            if (func_800DA298(0x4FD) != 0) {
                func_80800A1C_chcrusherboulder(actor, 6);
                return;
            }
            if (func_800DA298(0x4FB) != 0) {
                _capod_entrypoint_13(*(s32 *) ((s8 *) actor + 0), 0, 2, 0x2820);
            } else {
                _capod_entrypoint_13(*(s32 *) ((s8 *) actor + 0), 0, 0, 0x2820);
            }
            func_80800A1C_chcrusherboulder(actor, 2);
        }
    } else {
        if (func_800DA298(0x4FF) != 0) {
            if (func_800DA9E4(0x500, 1) == 0) {
                func_80800A1C_chcrusherboulder(actor, 0xB);
                return;
            }
            func_800FFAB0(actor);
            return;
        }
        if (func_800DA298(0x4FC) != 0) {
            func_800FFAB0(actor);
            return;
        }
        if (func_800DA298(0x4FD) != 0) {
            func_800FFAB0(actor);
        }
    }
}

void func_80800ED0_chcrusherboulder(Actor *actor)
{
    u8 audio_state;

    if (func_80100094(actor, 1)) {
        _sumumbofx_entrypoint_1(actor, 1);
    }
    _subaddieaudioloop_entrypoint_2(actor);
    audio_state = _subaddieaudioloop_entrypoint_3(*(u8 *) ((u8 *) actor + 0x24));
    *(f32 *) ((u8 *) actor + 0x24) = *(f32 *) &audio_state;
    func_800DA524(0);
}

void func_80801128_chcrusherboulder();

// Spawns dust and spark particles at both ends of the crusher.
void func_80800F38_chcrusherboulder(actor) Actor *actor;
{
    Vec3f pos = D_808013E0_chcrusherboulder;

    if ((func_8001211C() & 3) == 0) {
        pos.f[2] = *(f32 *) &actor->actorData[7] + -325.0f;
        if (func_800DC0C0() < 0.6f) {
            func_80801064_chcrusherboulder(pos.f, *(s32 *) &actor->scale);
        }
        pos.f[2] += 25.0f;
        func_800DC0C0();
        func_80801128_chcrusherboulder(pos.f, *(s32 *) &actor->scale);
        pos.f[2] = -325.0f - *(f32 *) &actor->actorData[7];
        if (func_800DC0C0() < 0.6f) {
            func_80801064_chcrusherboulder(pos.f, *(s32 *) &actor->scale);
        }
        pos.f[2] -= 25.0f;
        func_800DC0C0();
        func_80801128_chcrusherboulder(pos.f, *(s32 *) &actor->scale);
    }
    _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_808013EC_chcrusherboulder);
}

void func_80801064_chcrusherboulder(pos, unk_1) f32 *pos;
s32 unk_1;
{
    s32 particle;
    particle = func_800BABB8(0, pos, 0, 1.0f, D_808013FC_chcrusherboulder);
    func_800BABB8(particle, pos, 0, 1.0f,
                  pos[2] < -325.0f ? D_8080143C_chcrusherboulder : D_80801450_chcrusherboulder);
}

void func_808010EC_chcrusherboulder()
{
    func_800BBCB8(&D_80801464_chcrusherboulder, 0, 1.0f, 3, &D_80801470_chcrusherboulder);
}

void func_80801128_chcrusherboulder(s32 pos, s32 unk_1)
{
    s32 handle;
    s32 emitter;

    emitter = func_800BABB8(0, pos, 0, 1.0f, &D_808014BC_chcrusherboulder);
    handle = emitter;
    func_800BA3FC(emitter, 0x9DD);
    func_800BA22C(handle, 1);
}

unsigned long func_80801184_chcrusherboulder(s32 actor, u32 unk_1, u32 unk_2)
{
    if (unk_1 == 0xB) {
        switch (unk_2) {
            case 6:
                func_800DA544(0x4FC);
                _glcutDll_entrypoint_6(0xCB, 0x19);
            default:
                return 3;
            case 0:
                _glcutDll_entrypoint_17();
                return 3;
            case 4:
                _capod_entrypoint_15();
                _glcutDll_entrypoint_6(0xC7, 0x19);
                return 4;
            case 2:
                _glcutDll_entrypoint_17();
                return 3;
            case 8:
                if (_glcutDll_entrypoint_23() != 0) {
                    _glcutDll_entrypoint_17();
                    return 3;
                }
                if (func_800DB9B0() != 0) {
                    _glcutDll_entrypoint_17();
                }
                _capod_entrypoint_14();
                func_800FFAB0(actor);
                return 4;
        }
    } else {
        return 0;
    }
}

int chcrusherboulder_entrypoint_0()
{
    return (int) &D_808014EC_chcrusherboulder;
}

extern void func_80107C2C();
f32 D_80801360_chcrusherboulder[5] = {1.746595e-39f, 9.18714e-40f, 2.065222e-39f, 9.1835e-41f,
                                      3.4331227e-27f};
f32 D_80801374_chcrusherboulder[5] = {1.746602e-39f, 9.18677e-40f, 2.065222e-39f, 1.05848e-40f,
                                      0.001159668f};
Vec3f D_80801388_chcrusherboulder = {0.0f, 0.0f, 0.0f};
Vec3f D_80801394_chcrusherboulder = {0.0f, 1.5e+02f, 0.0f};
f32 D_808013A0_chcrusherboulder[5] = {1.746552e-39f, 9.18677e-40f, 2.054012e-39f, 9.2536e-41f,
                                      3.4331227e-27f};
f32 D_808013B4_chcrusherboulder[3] = {0.0f, 0.0f, 0.0f};
f32 D_808013C0_chcrusherboulder[2] = {5e+02f, 1e+03f};
f32 D_808013C8_chcrusherboulder[3] = {0.0f, 3.57e-43f, 0.0f};
f32 D_808013D4_chcrusherboulder[3] = {-5e+03f, 9.5e+02f, -6e+03f};
Vec3f D_808013E0_chcrusherboulder = {-2.35e+03f, 325.0f, -325.0f};
u8 D_808013EC_chcrusherboulder[16] = {0x0, 0x13, 0x4, 0xD2, 0x0,  0x16, 0x7D, 0x0,
                                      0x0, 0x1,  0x1, 0xF4, 0x13, 0x88, 0x0,  0x0};
s32 D_808013FC_chcrusherboulder[16] = {
    0x310001D, 0x688000A, 0xFF9C,    -0x320000, 0x640032, 0x1BFC18, -0x7CFFFD9, -0x1670168,
    0x1680168, 0x220280,  0x6000500, 0x3800015, 0x180,    0x160004, 0x70001,    0x0};
s32 D_8080143C_chcrusherboulder[5] = {0x2EFFE7, 0x5A0190, 0x190078, 0x320031A, 0x0};
s32 D_80801450_chcrusherboulder[5] = {0x2EFFE7, 0x3C0190, 0x19005A, 0x320031A, 0x0};
void *D_80801464_chcrusherboulder = (void *) 0xC59C4000;
static u32 D_80801464_chcrusherboulder_rest[2] = {0x446D8000, 0xC5BB8000};
s32 D_80801470_chcrusherboulder[19] = {0x1D0688,   0xAFFCE,   -0x310032, 0x320032,  0x32002E,
                                       -0x180023,  0x5DC0019, 0x2307D0,  0x1BF830,  -0xF9FFFD9,
                                       -0x1670168, 0x1680168, 0x220280,  0x6000500, 0x3800015,
                                       0x180,      0x160004,  0x70001,   0x0};
s32 D_808014BC_chcrusherboulder[12] = {0x1100019, 0x10006,   0xA0096,  -0x12B0064,
                                       0xFA0064,  0x64001B,  0x320064, 0x220180,
                                       0x2800080, 0x1800015, 0x180,    -0x23FE0000};
int D_808014EC_chcrusherboulder[21] = {0x262017E,
                                       0x6870001,
                                       0x0,
                                       (u32) func_808009C0_chcrusherboulder,
                                       (u32) func_808009C0_chcrusherboulder,
                                       (u32) func_80800000_chcrusherboulder,
                                       0xFA00000,
                                       0x0,
                                       0x0,
                                       0x20080004,
                                       (u32) func_80800ED0_chcrusherboulder,
                                       0x0,
                                       0x0,
                                       (u32) func_80800D3C_chcrusherboulder,
                                       (u32) func_80107C2C,
                                       -0x7FF7FFFE,
                                       (u32) func_80801184_chcrusherboulder,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0};
