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
    u8 local_0;
    void *local_1;
    s32 local_2;
} DialogCamera27;

void func_80800000_gcdialogcamera(s32 param_0, s32 *param_1, s32 *param_2)
{
    s32 v0;
    s32 v1;

    if (param_0 < 0x32) {
        v0 = param_0;
        v1 = 0;
        goto end;
    }

    if (param_0 >= 0x64) {
        v0 = param_0 - 0x64;
        v1 = 1;
    } else {
        v0 = param_0 - 0x32;
        v1 = 0x32;
    }

end:
    *param_2 = v1;
    *param_1 = v0;
}

s32 func_8080003C_gcdialogcamera(u8 *param_0, s32 param_1)
{
    s32 ret;
    if (param_1 == -1) {
        ret = 0;
    } else {
        ret = (param_1 == ((u32) *(u16 *) (param_0 + 0x12) >> 1));
    }
    return ret;
}

int gcdialogcamera_entrypoint_0(s32 param_0, s32 param_1)
{
    int local_0;
    local_0 = _ncpoddialog_entrypoint_11(param_0, param_1, 0);
    return 1 - local_0;
}

s32 gcdialogcamera_entrypoint_1(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    func_80800000_gcdialogcamera(param_1, &local_0, &local_1);
    if (param_0 == 0x58) {
        if (_ncpoddialog_entrypoint_11(local_0, local_1, 0)) {
            _capod_entrypoint_3(0);
            return 4;
        }
        return 3;
    }
    return 0;
}

void gcdialogcamera_entrypoint_2(u8 *param_0)
{
    s32 local_0;

    local_0 = _capod_entrypoint_4();
    if ((local_0 != -1) && (local_0 != 1)) {
        if (local_0 == 6) {
            _capod_entrypoint_7(0, 0x64);
            return;
        }
        _capod_entrypoint_0(0x57, 0x10000, *(s32 *) ((char *) param_0 + 0x168));
    }
}

void func_8080015C_gcdialogcamera()
{
    Actor *local_0;
    f32 local_2;
    f32 local_1[4];
    local_0 = func_80106790();
    local_2 = (f32) (u32) *(u16 *) &local_0->pad68 * local_0->scale;
    local_1[0] = local_2;
    local_1[1] = local_2;
    local_1[2] = local_2;
    local_1[3] = local_2 * 0.5f;
    _capod_entrypoint_9(0, local_1);
}

int gcdialogcamera_entrypoint_3(f32 param_0[4], f32 param_1)
{
    f32 local_0[4];
    local_0[0] = param_0[0] * param_1;
    local_0[1] = param_0[1] * param_1;
    local_0[2] = param_0[2] * param_1;
    local_0[3] = param_0[3] * param_1;
    return _capod_entrypoint_9(0, local_0);
}

s32 gcdialogcamera_entrypoint_4(s32 param_0)
{
    _capod_entrypoint_10(0, param_0);
}

s32 gcdialogcamera_entrypoint_5(s32 param_0)
{
    _capod_entrypoint_11(0, param_0);
}

int func_8080026C_gcdialogcamera(s32 param_0)
{
    if (func_8010114C(param_0, 0x52, 0) <= 0) {
        func_8080015C_gcdialogcamera(param_0);
    }
}

s32 func_808002A4_gcdialogcamera(void)
{
    s32 local_0;
    local_0 = func_80106790();
    _capod_entrypoint_10(0, local_0 + 4);
    _capod_entrypoint_11(0, local_0 + 0x44);
}

void gcdialogcamera_entrypoint_6(s32 arg0)
{
    func_808002A4_gcdialogcamera();
    func_8080026C_gcdialogcamera(arg0);
}

s32 func_8080030C_gcdialogcamera(void)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;

    local_2 = func_800F54E4();
    func_800F5A00(local_2, local_0);
    func_800F5DC8(local_2, local_1);
    _capod_entrypoint_10(1, local_0);
    _capod_entrypoint_11(1, local_1);
}

void gcdialogcamera_entrypoint_7(s32 arg0, f32 *out)
{
    s32 idx;
    s32 i;
    f32 scale;

    scale = 1.0f;
    switch (func_800F543C(arg0)) {
        case 1:
            if (func_800F7058(arg0)) {
                idx = 0x10;
                break;
            }
        case 0x200:
            switch (func_800F5D18(arg0)) {
                case 0:
                    if (func_800F6720(arg0)) {
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
            if (func_800F67EC(arg0)) {
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
            scale = func_800F5C44(arg0);
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
    f32 local_0[4];
    gcdialogcamera_entrypoint_7(func_800F54E4(), local_0);
    _capod_entrypoint_9(1, local_0);
}

void gcdialogcamera_entrypoint_8()
{
    func_8080030C_gcdialogcamera();
    func_808005C0_gcdialogcamera();
}

s32 func_80800620_gcdialogcamera(s32 param_0)
{
    if (_capod_entrypoint_2(0, 6, param_0)) {
        _capod_entrypoint_8(1);
        return TRUE;
    }
    return FALSE;
}

int gcdialogcamera_entrypoint_9(enum gc_dialog_camera_e param_0, enum gc_dialog_camera_e param_1,
                                int param_2)
{
    gcdialogcamera_entrypoint_6(param_0);
    gcdialogcamera_entrypoint_8();
    if (param_1 == 7) {
        _capod_entrypoint_5(0x200);
    }
    _capod_entrypoint_7(param_1, param_2);
}

void gcdialogcamera_entrypoint_10(DialogCamera27 *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    func_80800000_gcdialogcamera(param_1, &local_0, &local_1);
    if (param_0->local_0) {
        if (func_8080003C_gcdialogcamera(param_0->local_1, param_0->local_2)) {
            switch (_capod_entrypoint_4()) {
                case -1:
                    func_80800620_gcdialogcamera(param_2);
                case 6:
                    gcdialogcamera_entrypoint_9(param_0->local_1, local_0, local_1);
                    break;
                default:
                    switch (
                        _capod_entrypoint_0(0x57, (local_1 << 16) | local_0, param_0->local_1)) {
                        case 0:
                        case 1:
                            break;
                        case 2:
                            gcdialogcamera_entrypoint_9(param_0->local_1, local_0, local_1);
                    }
                    break;
            }
        } else if (_capod_entrypoint_4() == 6) {
            gcdialogcamera_entrypoint_9(param_0->local_1, local_0, local_1);
        }
    }
}

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
