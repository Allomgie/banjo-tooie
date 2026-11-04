#include "common.h"
#include "playerstate.h"
extern struct D_80801038_basnowball D_80801038_basnowball[];

#define SB (*(SnowballRoll **) ((u8 *) this + 0x110))
extern float D_80801020_basnowball[];
struct D_80801038_basnowball {
    f32 unk0;
    f32 unk4;
};
extern f32 D_80801068_basnowball[][2];
extern void func_800959C8(PlayerState *, f32, f32);
extern void func_8009590C(PlayerState *, f32);
extern void func_800A4D6C(PlayerState *, f32, f32);
extern f32 func_800F0E00(f32, f32);
typedef struct {
    u8 unused[0xC];
    f32 size;
    f32 saved;
    u8 state;
} SnowballStateView;
extern void func_80093230(PlayerState *, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8 unk14;
    u8 pad15[3];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u8 unk28;
    u8 pad29[3];
    u8 unk2C;
    u8 unk2D;
} SnowData;
typedef struct {
    u8 pad0[0x110];
    SnowData *unk110;
    u8 pad114[0x70];
    s32 unk184;
} SnowPlayer;
extern f32 func_800D8FF8(void);
extern s32 func_800EA068(s32);
extern s32 func_8009E674(SnowPlayer *, s32);
extern void _basnowball_entrypoint_11();
extern void func_8009919C(SnowPlayer *, void *, s32);
extern void func_800A17A8(SnowPlayer *, s32);
extern s32 func_8008DE50(SnowPlayer *);
extern s32 player_isStable(SnowPlayer *);
extern s32 func_800A1760(SnowPlayer *);
extern void func_80096394(SnowPlayer *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800FC660(s32);
extern s32 func_800958A4(SnowPlayer *, s32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800D9078(f32 *);
extern f32 func_800136E4(f32);
extern f32 func_800F13F0(f32, f32);
extern s32 func_80092AD8(SnowPlayer *);
extern void func_800E0AF0(s32, f32);
extern void func_800E0AFC(s32, s32, f32, f32, f32, f32);
extern void _bawobble_entrypoint_8(SnowPlayer *);
typedef struct {
    f32 unk0;
    f32 unk4;
    u8 pad8[0x10];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u8 unk28;
} SnowballRoll;
extern s32 func_800A1718();
extern void _bawobble_entrypoint_7(PlayerState *);
extern void _bawobble_entrypoint_1(PlayerState *);
extern void _bawobble_entrypoint_4(PlayerState *, f32, f32);
extern void _bawobble_entrypoint_5(PlayerState *, f32, f32);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern void _bawobble_entrypoint_6(PlayerState *);
extern s32 D_80801098_basnowball[];
extern f32 D_808010C0_basnowball[][3];
extern f32 D_808010F0_basnowball[][3];
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern void func_800BA8F8(s32, f32, f32);
extern f32 yaw_get(PlayerState *);
extern f32 func_800DC178(f32, f32);
extern void func_800EF214(void *, f32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern u8 D_8080110C_basnowball[];
extern s32 func_800B5BE4(s32);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_800BA730(s32, s16, s16, s32, s32);
extern void func_800BA930(s32, s16, s16, s16, s32, s32, s32);
extern void func_800BA77C(s32, s16, s16, s16);

s32 basnowball_entrypoint_0()
{
    return 0x30;
}

void func_80800008_basnowball(u8 *param_0, s32 param_1)
{
    u8 *var_v0;

    var_v0 = *(u8 **) ((s8 *) param_0 + 0x110);
    if (*(u8 *) ((s8 *) var_v0 + 0x2D) == 2) {
        baflag_clear(param_0, 0x3C);
        func_800FC74C(0x1C);
        var_v0 = *(u8 **) ((s8 *) param_0 + 0x110);
    }
    *(s8 *) ((s8 *) var_v0 + 0x2D) = (s8) param_1;
    if (param_1 == 2) {
        baflag_set(param_0, 0x3C);
        func_800FC660(0x1C);
    }
}

float func_80800084_basnowball(s32 param_0)
{
    return D_80801020_basnowball[param_0];
}

void func_80800098_basnowball(s32 param_0, u32 param_1, f32 *param_2, f32 *param_3)
{
    *param_2 = D_80801038_basnowball[param_1].unk0;
    *param_3 = D_80801038_basnowball[param_1].unk4;
}

int func_808000C0_basnowball(Actor *param_0)
{
    f32 radius;
    f32 height;
    s32 level;
    level = func_800A1718();
    func_80800098_basnowball(param_0, level, &radius, &height);
    func_800959C8(param_0, radius, height);
    func_8009590C(param_0, radius);
}

s32 func_80800110_basnowball(s32 param_0)
{
    f32 *cam;

    cam = D_80801068_basnowball[func_800A1718()];
    func_800A4D6C(param_0, cam[0], cam[1]);
}

void func_80800150_basnowball(PlayerState *param_0, s32 param_1)
{
    if (param_1 != (*(SnowballStateView **) ((u8 *) param_0 + 0x110))->state) {
        switch (param_1) {
            case 1:
                break;
            case 2:
                (*(SnowballStateView **) ((u8 *) param_0 + 0x110))->saved =
                    func_800F0E00((*(SnowballStateView **) ((u8 *) param_0 + 0x110))->size, 300.0f);
        }
        (*(SnowballStateView **) ((u8 *) param_0 + 0x110))->state = param_1;
    }
}

void func_808001B8_basnowball(this, state) PlayerState *this;
s32 state;
{
    f32 pitch;

    switch (SB->unk28) {
        case 0:
            SB->unk24 = func_80800084_basnowball(func_800A1718(this));
            break;
        case 2:
            _bawobble_entrypoint_7(this);
            func_8009E55C(this, 0, SB->unk1C * 50.0f);
            SB->unk0 = 0.0f;
            SB->unk4 = 7.5f;
    }
    SB->unk28 = state;
    switch (state) {
        case 1:
            SB->unk1C = SB->unk24;
            break;
        case 2:
            SB->unk18 = 1.0f;
            SB->unk20 = SB->unk1C;
            SB->unk24 = func_80800084_basnowball(func_800A1718(this));
            _bawobble_entrypoint_1(this);
            _bawobble_entrypoint_4(this, 0.2f, 0.2f);
            pitch = func_800F10B4(SB->unk24, 1.0, 3.0f, 0.0f, -0.5f) + 1.2f;
            if (SB->unk20 < SB->unk24) {
                _bawobble_entrypoint_5(this, 1.0, 1.2);
                func_8009DB04(this, 0x65A, pitch, 14000);
            } else {
                _bawobble_entrypoint_5(this, 1.0, 0.8f);
                func_8009DB04(this, 0x65B, pitch, 14000);
            }
            _bawobble_entrypoint_6(this);
            func_808000C0_basnowball(this);
            func_80800110_basnowball(this);
    }
}

void basnowball_entrypoint_1(PlayerState *param_0)
{
    func_80800008_basnowball(param_0, 0);
    func_8009E474(param_0);
    baflag_clear(param_0, 0x3C);
    func_80093230(param_0, 1.0f);
    func_80095A40(param_0);
    func_8009590C(param_0, 0.0f);
    _bawobble_entrypoint_2(param_0);
    func_800A4D6C(param_0, 1.0f, 1.0f);
}

void basnowball_entrypoint_2(PlayerState *param_0)
{
    _bawobble_entrypoint_3(param_0);
    *(f32 *) *(u8 **) ((u8 *) param_0 + 0x110) = 0.0f;
    *(f32 *) (*(u8 **) ((u8 *) param_0 + 0x110) + 4) = 7.5f;
    (*(u8 **) ((u8 *) param_0 + 0x110))[0x2D] = 0;
    (*(u8 **) ((u8 *) param_0 + 0x110))[0x2C] = 0;
    func_80800008_basnowball(param_0, 1);
    *(f32 *) (*(u8 **) ((u8 *) param_0 + 0x110) + 0xC) = 0.0f;
    *(f32 *) (*(u8 **) ((u8 *) param_0 + 0x110) + 8) = 0.0f;
    (*(u8 **) ((u8 *) param_0 + 0x110))[0x14] = 0;
    func_80800150_basnowball(param_0, 2);
    (*(u8 **) ((u8 *) param_0 + 0x110))[0x28] = 0;
    func_808001B8_basnowball(param_0, 1);
    func_80093230(param_0, *(f32 *) (*(u8 **) ((u8 *) param_0 + 0x110) + 0x1C));
    func_8009E4AC(param_0);
    func_8009E55C(param_0, 0, *(f32 *) (*(u8 **) ((u8 *) param_0 + 0x110) + 0x1C) * 50.0f);
    func_8009E55C(param_0, 1, 0.0f);
    func_808000C0_basnowball(param_0);
    func_80800110_basnowball(param_0);
}

f32 basnowball_entrypoint_3(u8 *param_0)
{
    return *(f32 *) ((s8 *) *(u8 **) ((s8 *) param_0 + 0x110) + 8);
}

float basnowball_entrypoint_4(void *param_0)
{
    return ((float *) ((int *) param_0)[68])[7];
}

void basnowball_entrypoint_5(void)
{
    func_800F10B4(func_800A1718(), 1.0f, 5.0f, 0.0f, 1.0f);
}

int basnowball_entrypoint_6()
{
    return func_800A1718() >= 5;
}

void basnowball_entrypoint_7(s32 param_0)
{
    int new_var;
    new_var = 1;
    *(u8 *) (*(s32 *) (param_0 + 0x110) + 0x2C) = new_var;
}

int basnowball_entrypoint_8(Actor *param_0, s32 param_1)
{
    if (param_1 != 0) {
        func_80800150_basnowball(param_0, 2);
    } else {
        func_80800150_basnowball(param_0, 1);
    }
}

int basnowball_entrypoint_9(s32 param_0, f32 param_1)
{
    int new_var;
    *(f32 *) (*(s32 *) (param_0 + 0x110) + (new_var = 0xC)) = param_1;
}

void basnowball_entrypoint_10(PlayerState *param_0)
{
    s32 i;
    s32 unk_0; // unused, but it carries the stack frame (the frame is 8 bytes smaller without it)
    f32 scale;
    s32 emitter_type;
    f32 pos[3];
    f32 spawn_pos[3];
    s32 emitter;
    f32(*unk_1)[3]; // unused, but it carries the stack frame

    emitter_type = func_800B5BE4(7);
    scale = *(f32 *) ((u8 *) *(void **) ((u8 *) param_0 + 0x110) + 0x1C);
    func_8009C128(param_0, pos);
    pos[1] += 50.0f * scale;
    emitter = func_800BABB8(emitter_type, pos, NULL, 1.0f, D_80801098_basnowball);
    func_800BA7C4(emitter, 0.5f * scale, 0.5f * scale);
    func_800BA7FC(emitter, 1.1f * scale, 1.1f * scale);
    func_800BA8F8(emitter, 0.175f * scale + 0.6f, 0.175f * scale + 0.6f);
    for (i = 0; i < 4; i++) {
        func_800EE7F8(spawn_pos, pos);
        spawn_pos[0] += D_808010C0_basnowball[i][0] * scale;
        spawn_pos[2] += D_808010C0_basnowball[i][1] * scale;
        func_800BA75C(emitter, spawn_pos);
        func_800BA77C(emitter, 0, 0, (s16) (s32) D_808010C0_basnowball[i][2]);
        func_800BA22C(emitter, 1);
    }
}

void func_808007CC_basnowball(param_0) PlayerState *param_0;
{
    f32 scale;
    f32 yaw;
    f32 count;
    f32 height;
    f32 angle;
    f32 spawn_pos[3];
    f32 pos[3];
    s32 emitter;
    s32 i;
    emitter = func_800B5BE4(9);
    func_8009C128(param_0, pos);
    height = *(f32 *) ((u8 *) *(void **) ((u8 *) param_0 + 0x110) + 0x1C) * 58.0f;
    pos[1] += height;
    scale = *(f32 *) ((u8 *) *(void **) ((u8 *) param_0 + 0x110) + 0x1C) * 0.15f + 0.3f;
    func_800BA7C4(emitter, scale, scale);
    yaw = yaw_get(param_0) + 90.0f;
    count = func_800A1718(param_0) + 1;
    for (i = 0; i < count; i++) {
        func_800EE7F8(spawn_pos, pos);
        angle = func_800DC178(0, 90);
        func_800EF214(spawn_pos, angle, func_800136E4(func_800DC178(0, 180) + yaw), height);
        func_800BABB8(emitter, spawn_pos, 0, 1.0f, (s32 *) D_808010F0_basnowball);
    }
}

void func_8080099C_basnowball(PlayerState *param_0)
{
    s32 emitter;
    f32 size_min;
    f32 scale;
    f32 speed_min;
    f32 pos[3];

    emitter = func_800B5BE4(7);
    func_8009C128(param_0, pos);
    size_min = *(f32 *) (*(u8 **) ((u8 *) param_0 + 0x110) + 0x1C) * 30.0f + 5.0f;
    speed_min = *(f32 *) (*(u8 **) ((u8 *) param_0 + 0x110) + 0x1C) * 100.0f + 200.0f;
    scale = *(f32 *) (*(u8 **) ((u8 *) param_0 + 0x110) + 0x1C) * 0.5f + 0.6f;
    func_800BA730(emitter, size_min, size_min + 10.0f, 0x41, 0x3C);
    func_800BA930(emitter, -10, speed_min, -10, 10, speed_min + 50.0f, 10);
    func_800BA7FC(emitter, scale, scale);
    func_800BA77C(emitter, 0, 0, func_800DC178(0.0f, 359.0f));
    func_800BABB8(emitter, pos, NULL, 1.0f, D_8080110C_basnowball);
}

void basnowball_entrypoint_11(s32 arg0)
{
    func_800F796C(arg0, 0x3);
}

void basnowball_entrypoint_12(SnowPlayer *param_0)
{
    f32 dt;
    s32 bone;
    s32 level;
    f32 step[3];
    f32 target_scale;
    s32 cur_level;
    s32 radius;
    s32 height;
    s32 needs_change;

    dt = func_800D8FF8();
    if (func_800EA068(1) && !func_8009E674(param_0, 0x10)) {
        level = func_800A1718(param_0);
        if (level > 0 && param_0->unk110->unk28 == 1) {
            param_0->unk110->unk4 -= dt;
            if (param_0->unk110->unk4 < 0.0f) {
                if (level == 1) {
                    func_8009919C(param_0, _basnowball_entrypoint_11, param_0->unk184);
                } else {
                    param_0->unk110->unk4 = 7.5f;
                    func_800A17A8(param_0, -1);
                }
            }
        }
    } else if (func_8008DE50(param_0) && player_isStable(param_0) &&
               100.0f < param_0->unk110->unkC) {
        func_8080099C_basnowball(param_0);
        if (func_800A1718(param_0) < func_800A1760(param_0) && param_0->unk110->unk28 == 1) {
            func_80096394(param_0, step);
            param_0->unk110->unk0 += func_800EEF94(step);
            if (1000.0f < param_0->unk110->unk0) {
                param_0->unk110->unk0 = 0.0f;
                func_800A17A8(param_0, 1);
                func_800FC660(8);
            }
        }
    }
    switch (param_0->unk110->unk28) {
        case 1:
            cur_level = func_800A1718(param_0);
            target_scale = func_80800084_basnowball(cur_level);
            if (target_scale != param_0->unk110->unk1C) {
                func_80800098_basnowball(param_0, cur_level, &radius, &height);
                needs_change = 0;
                if (target_scale < param_0->unk110->unk1C) {
                    needs_change = 1;
                } else if (!func_800958A4(param_0, radius, height)) {
                    needs_change = 1;
                }
                if (needs_change) {
                    func_808001B8_basnowball(param_0, 2);
                }
            }
            break;
        case 2:
            param_0->unk110->unk1C = func_800F10B4(param_0->unk110->unk18, 0.0f, 1.0f,
                                                   param_0->unk110->unk24, param_0->unk110->unk20);
            func_8009E55C(param_0, 0, param_0->unk110->unk1C * 50.0f);
            if (func_800D9078(&param_0->unk110->unk18)) {
                func_808001B8_basnowball(param_0, 1);
            }
            break;
    }
    switch (param_0->unk110->unk14) {
        case 1:
            param_0->unk110->unk8 = func_800136E4(
                param_0->unk110->unk8 + param_0->unk110->unkC / param_0->unk110->unk1C * dt);
            break;
        case 2: {
            f32 start_angle;
            f32 decel;
            f32 delta;
            start_angle = param_0->unk110->unk8;
            if (param_0->unk110->unk8 != 0.0f) {
                decel = func_800F13F0(param_0->unk110->unk10 / param_0->unk110->unk1C,
                                         (360.0f - start_angle) * 7.0f);
                delta = func_800F0E00(decel * dt, 1.5f);
                param_0->unk110->unk8 = func_800136E4(delta + param_0->unk110->unk8);
                if (param_0->unk110->unk8 < start_angle) {
                    param_0->unk110->unk8 = 0.0f;
                }
            }
        }
    }
    bone = func_80092AD8(param_0);
    func_800E0AF0(bone, 1.0f);
    func_800E0AFC(bone, 0x43, 1.0f, param_0->unk110->unk8, 0.0f, 0.0f);
    func_80093230(param_0, param_0->unk110->unk1C);
    _bawobble_entrypoint_8(param_0);
    if (param_0->unk110->unk2D == 2) {
        if (!param_0->unk110->unk2C) {
            func_80800008_basnowball(param_0, 1);
            return;
        }
        func_808007CC_basnowball(param_0);
        param_0->unk110->unk2C = 0;
    } else if (param_0->unk110->unk2C) {
        func_80800008_basnowball(param_0, 2);
        param_0->unk110->unk2C = 0;
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
float D_80801020_basnowball[6] = {1.0f, 1.0f, 1.5f, 2.0f, 2.5f, 3.0f};
struct D_80801038_basnowball D_80801038_basnowball[6] = {
    83.0f, 46.0f, 83.0f, 46.0f, 114.0f, 66.0f, 1.5e+02f, 88.0f, 1.9e+02f, 105.0f, 2.3e+02f, 125.0f};
f32 D_80801068_basnowball[6][2] = {1.0f, 1.0f, 1.0f, 1.0f,  1.2f, 1.05f,
                                   1.4f, 1.1f, 1.6f, 1.15f, 1.8f, 1.2f};
s32 D_80801098_basnowball[10] = {0x34001D, 0x9C90020, -0x19190001, 0x2CFFD8, 0x32FFD8,
                                 0x280064, 0x280015,  0x140066,    0x161000, 0x0};
f32 D_808010C0_basnowball[4][3] = {-44.0f, 0.0f,   0.0f,     44.0f, 0.0f,  9e+01f,
                                   0.0f,   -44.0f, 1.8e+02f, 0.0f,  44.0f, 2.7e+02f};
f32 D_808010F0_basnowball[2][3] = {2.666779e-39f, 1.92858e-39f,  6.97955e-39f,
                                   6.42858e-40f,  3.948998e-39f, 4.684005e-39f};
static u32 D_808010F0_basnowball_rest[1] = {0x0};
u8 D_8080110C_basnowball[52] = {0x0,  0x1D, 0x9,  0xC9, 0x0,  0x20, 0xE6, 0xE6, 0xFF, 0xFF, 0x0,
                                0x15, 0x0,  0x19, 0x0,  0x4C, 0x0,  0x1B, 0xFB, 0x50, 0xFB, 0x50,
                                0x0,  0x24, 0x0,  0x4C, 0x0,  0x66, 0x0,  0x2B, 0x0,  0x59, 0x0,
                                0x61, 0x1,  0x1A, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
                                0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
