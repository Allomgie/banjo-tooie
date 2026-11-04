#include "common.h"

extern Actor *func_80106790(void);
extern int _capod_entrypoint_9(u32, f32 *);
extern f32 D_808007C0_gcdialogcamera[][4];
extern s32 func_800F543C(s32);
extern s32 func_800F7058(s32);
extern s32 func_800F5D18(s32);
extern s32 func_800F6720(s32);
extern s32 func_800F67EC(s32);
extern f32 func_800F5C44(s32);

typedef struct {
    u8 pad_0[0x167];
    u8 unk_167;
    void *actor;
    s32 unk_16C;
} DialogCamera27;

// Splits a shot code (0-49, 50-99, 100+) into shot and variant.
void func_80800000_gcdialogcamera(s32 code, s32 *out_shot, s32 *out_variant)
{
    s32 shot;
    s32 variant;

    if (code < 0x32) {
        shot = code;
        variant = 0;
        goto end;
    }

    if (code >= 0x64) {
        shot = code - 0x64;
        variant = 1;
    } else {
        shot = code - 0x32;
        variant = 0x32;
    }

end:
    *out_variant = variant;
    *out_shot = shot;
}

s32 func_8080003C_gcdialogcamera(u8 *obj, s32 id)
{
    s32 ret;
    if (id == -1) {
        ret = 0;
    } else {
        ret = (id == ((u32) *(u16 *) (obj + 0x12) >> 1));
    }
    return ret;
}

int gcdialogcamera_entrypoint_0(s32 shot, s32 variant)
{
    int result;
    result = _ncpoddialog_entrypoint_11(shot, variant, 0);
    return 1 - result;
}

s32 gcdialogcamera_entrypoint_1(s32 mode, s32 code, s32 unk_0)
{
    s32 shot;
    s32 variant;

    func_80800000_gcdialogcamera(code, &shot, &variant);
    if (mode == 0x58) {
        if (_ncpoddialog_entrypoint_11(shot, variant, 0)) {
            _capod_entrypoint_3(0);
            return 4;
        }
        return 3;
    }
    return 0;
}

void gcdialogcamera_entrypoint_2(u8 *dialog)
{
    s32 state;

    state = _capod_entrypoint_4();
    if ((state != -1) && (state != 1)) {
        if (state == 6) {
            _capod_entrypoint_7(0, 0x64);
            return;
        }
        _capod_entrypoint_0(0x57, 0x10000, *(s32 *) ((char *) dialog + 0x168));
    }
}

// Aims the pod at the current dialog actor, sized by its bounding radius.
void func_8080015C_gcdialogcamera()
{
    Actor *actor;
    f32 radius;
    f32 size[4];
    actor = func_80106790();
    radius = (f32) (u32) *(u16 *) &actor->pad68 * actor->scale;
    size[0] = radius;
    size[1] = radius;
    size[2] = radius;
    size[3] = radius * 0.5f;
    _capod_entrypoint_9(0, size);
}

int gcdialogcamera_entrypoint_3(f32 base[4], f32 scale)
{
    f32 scaled[4];
    scaled[0] = base[0] * scale;
    scaled[1] = base[1] * scale;
    scaled[2] = base[2] * scale;
    scaled[3] = base[3] * scale;
    return _capod_entrypoint_9(0, scaled);
}

s32 gcdialogcamera_entrypoint_4(s32 vec)
{
    _capod_entrypoint_10(0, vec);
}

s32 gcdialogcamera_entrypoint_5(s32 vec)
{
    _capod_entrypoint_11(0, vec);
}

int func_8080026C_gcdialogcamera(s32 actor)
{
    if (func_8010114C(actor, 0x52, 0) <= 0) {
        func_8080015C_gcdialogcamera(actor);
    }
}

s32 func_808002A4_gcdialogcamera(void)
{
    s32 actor;
    actor = func_80106790();
    _capod_entrypoint_10(0, actor + 4);
    _capod_entrypoint_11(0, actor + 0x44);
}

void gcdialogcamera_entrypoint_6(s32 actor)
{
    func_808002A4_gcdialogcamera();
    func_8080026C_gcdialogcamera(actor);
}

// Positions the pod from the player.
s32 func_8080030C_gcdialogcamera(void)
{
    f32 pos[3];
    f32 unk_0[3];
    s32 player;

    player = func_800F54E4();
    func_800F5A00(player, pos);
    func_800F5DC8(player, unk_0);
    _capod_entrypoint_10(1, pos);
    _capod_entrypoint_11(1, unk_0);
}

void gcdialogcamera_entrypoint_7(s32 player, f32 *out)
{
    s32 idx;
    s32 i;
    f32 scale;

    scale = 1.0f;
    switch (func_800F543C(player)) {
        case 1:
            if (func_800F7058(player)) {
                idx = 0x10;
                break;
            }
        case 0x200:
            switch (func_800F5D18(player)) {
                case 0:
                    if (func_800F6720(player)) {
                        idx = 0xC;
                    } else {
                        idx = 1;
                    }
                    break;
                case 1:
                    idx = 7;
                    break;
                case 2:
                    idx = 8;
            }
            break;
        case 0x80:
            idx = 2;
            break;
        case 0x8000:
            idx = 3;
            break;
        case 0x4000:
            idx = 4;
            break;
        case 0x400:
            if (func_800F67EC(player)) {
                idx = 0x11;
            } else {
                idx = 5;
            }
            break;
        case 0x1000:
            idx = 6;
            break;
        case 0x40:
            idx = 9;
            break;
        case 0x20:
            idx = 0xA;
            break;
        case 0x100:
            idx = 0xB;
            break;
        case 0x20000:
            idx = 0xD;
            break;
        case 0x800:
            idx = 0xE;
            break;
        case 0x10000:
            idx = 0xF;
            break;
        case 2:
            idx = 0x12;
            scale = func_800F5C44(player);
            break;
        case 0x2000:
            idx = 0x13;
            break;
        case 0x40000:
            idx = 0x14;
            break;
        default:
            idx = 0;
    }
    for (i = 0; i < 4; i++) {
        out[i] = D_808007C0_gcdialogcamera[idx][i] * scale;
    }
}

int func_808005C0_gcdialogcamera()
{
    f32 params[4];
    gcdialogcamera_entrypoint_7(func_800F54E4(), params);
    _capod_entrypoint_9(1, params);
}

void gcdialogcamera_entrypoint_8()
{
    func_8080030C_gcdialogcamera();
    func_808005C0_gcdialogcamera();
}

s32 func_80800620_gcdialogcamera(s32 unk_0)
{
    if (_capod_entrypoint_2(0, 6, unk_0)) {
        _capod_entrypoint_8(1);
        return TRUE;
    }
    return FALSE;
}

int gcdialogcamera_entrypoint_9(enum gc_dialog_camera_e actor, enum gc_dialog_camera_e shot,
                                int variant)
{
    gcdialogcamera_entrypoint_6(actor);
    gcdialogcamera_entrypoint_8();
    if (shot == 7) {
        _capod_entrypoint_5(0x200);
    }
    _capod_entrypoint_7(shot, variant);
}

// Switches the camera shot when the current speaker changes.
void gcdialogcamera_entrypoint_10(DialogCamera27 *dialog, s32 code, s32 unk_0)
{
    s32 shot;
    s32 variant;

    func_80800000_gcdialogcamera(code, &shot, &variant);
    if (dialog->unk_167) {
        if (func_8080003C_gcdialogcamera(dialog->actor, dialog->unk_16C)) {
            switch (_capod_entrypoint_4()) {
                case -1:
                    func_80800620_gcdialogcamera(unk_0);
                case 6:
                    gcdialogcamera_entrypoint_9(dialog->actor, shot, variant);
                    break;
                default:
                    switch (
                        _capod_entrypoint_0(0x57, (variant << 16) | shot, dialog->actor)) {
                        case 0:
                        case 1:
                            break;
                        case 2:
                            gcdialogcamera_entrypoint_9(dialog->actor, shot, variant);
                    }
                    break;
            }
        } else if (_capod_entrypoint_4() == 6) {
            gcdialogcamera_entrypoint_9(dialog->actor, shot, variant);
        }
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
f32 D_808007C0_gcdialogcamera[21][4] = {
    1.3e+02f, 7e+01f,   1e+02f,   75.0f,    1.3e+02f, 7e+01f,   1e+02f,   75.0f,    9e+01f,
    6e+01f,   1.8e+02f, 2e+01f,   1.9e+02f, 1.5e+02f, 1.8e+02f, 8e+01f,   1.2e+02f, 6e+01f,
    6e+01f,   4e+01f,   9e+01f,   6e+01f,   7e+01f,   4e+01f,   165.0f,   8e+01f,   1e+02f,
    5e+01f,   1e+02f,   7e+01f,   1e+02f,   45.0f,    1.5e+02f, 1.5e+02f, 1.5e+02f, 0.0f,
    165.0f,   165.0f,   165.0f,   25.0f,    9e+01f,   9e+01f,   9e+01f,   0.0f,     1.2e+02f,
    1.2e+02f, 1.6e+02f, 5e+01f,   1.5e+02f, 1.5e+02f, 1.5e+02f, 0.0f,     1.8e+02f, 2.2e+02f,
    2.4e+02f, 0.0f,     1.8e+02f, 1.5e+02f, 1.5e+02f, 0.0f,     45.0f,    4e+01f,   4e+01f,
    1e+01f,   115.0f,   1e+02f,   1.2e+02f, 5e+01f,   1.2e+02f, 1e+02f,   7e+01f,   6e+01f,
    9e+01f,   9e+01f,   9e+01f,   2e+01f,   725.0f,   3e+02f,   3e+02f,   3.5e+02f, 6.5e+02f,
    6e+02f,   8e+02f,   1.5e+02f};
