#include "common.h"

typedef struct { unsigned high : 26; unsigned enabled : 1; unsigned low : 5; } FogInitFlags;
typedef struct { unsigned high : 12; unsigned active : 1; unsigned low : 19; } FogActiveFlags;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern void *D_80800A90_chfog;
typedef struct { f32 field00, offsetX, offsetY; u8 pad0C[12]; f32 directionX, directionY; u8 pad20[8]; f32 speedX, speedY; u8 pad30[4]; f32 timer; u8 pad38[12]; f32 previousPosition[3]; f32 previousPitch, previousYaw; u8 pad58[12]; struct { unsigned high:12; unsigned active:1; unsigned low:19; } flags; u8 pad68[10]; struct { unsigned short value:6; unsigned short low:10; } state; } FogState;
extern f32 func_800DC0C0(void);
extern void func_800E3B50(f32 *, f32 *, f32 *);
extern void func_800E3980(f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern s32 func_800F54E4(void);
extern s32 func_800F690C(s32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800D90A4(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _subaddiefade_entrypoint_1(void *, s32);

void func_80800000_chfog(s32 param_0)
{
    func_800CF494();
}

void func_80800020_chfog(u8 *param_0)
{
    /* Capture the camera position and reset the fog motion vectors. */
    func_800E3980(param_0 + 0x44);
    func_800EFD24(param_0 + 4);
    func_800EFD24(param_0 + 0x28);
    *(f32 *)(param_0 + 0x18) = 1.0f;
    *(f32 *)(param_0 + 0x1C) = 1.0f;

    /* Select map-specific fog resources and fade behavior. */
    switch (func_800EA05C()) {
        case 0x10D:
            if (func_800DA298(0x1BD) == 0) {
                func_800FFAB0(param_0);
            } else if (((FogInitFlags *)(param_0 + 0x78))->enabled &&
                       func_800F6438(func_800F54E4()) != 0) {
                *(f32 *)(param_0 + 0x34) = 0.0f;
                func_800CF2D4(4);
            }
            ((FogActiveFlags *)(param_0 + 0x64))->active = 1;
            *(f32 *)(param_0 + 0x24) = 0.0f;
            return;
        case 0x138:
            func_800CF2D4(6);
            return;
        case 0x162:
            func_80101FDC(param_0, 2);
            _subaddiefade_entrypoint_2(param_0);
            func_800CF2D4(7);
            return;
        case 0x19A:
            func_80101FDC(param_0, 2);
            _subaddiefade_entrypoint_2(param_0);
            func_800CF2D4(8);
            param_0[0x75] &= 0xFFFD;
            return;
        default:
            func_800CF2D4(2);
            return;
    }
}

void func_80800174_chfog(s32 *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 *local_2;
    s32 *local_3;

    /* Select the fog render mode and update the map-specific companion. */
    switch (func_800EA05C()) {
        case 0x10D:
            local_2 = _subaddiefind_entrypoint_2(0x416, 0);
            if (local_2) {
                func_80101870(local_2, param_1);
            }
            func_800DF744(3, 1);
            break;
        case 0xDB:
            local_3 = _subaddiefind_entrypoint_2(0x176, 0);
            if (local_3) {
                func_80101074(param_1);
                func_8010114C(*local_3, 0xAB, 0);
            }
            func_800DF744(3, 1);
            break;
        case 0x138:
            func_800DF744(3, 2);
            break;
        case 0x162:
            func_800DF744(3, 2);
            break;
        case 0x19A:
            func_800DF744(3, 3);
            break;
        default:
            func_800DF744(3, 1);
            break;
    }

    /* Temporarily use a fixed view to render the moving fog layer. */
    func_800E41CC();
    func_800EFA4C(local_0, 0.0f, 0.0f, 300.0f);
    func_800EFD24(local_1);
    func_800E3BAC(local_0);
    func_800E3C30(local_1);
    func_800E3CE8();
    func_800E44FC(param_1);
    local_1[0] = -90.0f;
    func_800DF410(_subaddiefade_entrypoint_0(param_0));
    func_800DF830(0);
    func_800DE448((f32 *)(param_0 + 1), local_1, 0.2f, 0,
        func_8010347C(*param_0));
    func_800E4208();
    func_800E44FC(param_1);
}

void func_8080032C_chfog(FogState *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    f32 local_4[3];
    s16 local_5;

    /* Occasionally reverse the independent drift directions. */
    if (func_800DC0C0() < 0.01f) param_0->directionX = -param_0->directionX;
    if (func_800DC0C0() < 0.01f) param_0->directionY = -param_0->directionY;
    if (param_0->directionX == 1.0f) {
        if (param_0->speedX < 0.15f) param_0->speedX += 0.05f;
    } else if (param_0->speedX > -0.15f) param_0->speedX -= 0.05f;
    if (param_0->directionY == 1.0f) {
        if (param_0->speedY < 0.15f) param_0->speedY += 0.05f;
    } else if (param_0->speedY > -0.15f) param_0->speedY -= 0.05f;
    /* Reverse at the bounds; do not advance an offset on the reversal tick. */
    if (param_0->offsetX < -200.0f && param_0->directionX != 1.0f) {
        param_0->directionX = 1.0f;
    } else if (param_0->offsetX > 200.0f && param_0->directionX != -1.0f) {
        param_0->directionX = -1.0f;
    } else param_0->offsetX += param_0->speedX;
    if (param_0->offsetY < -200.0f && param_0->directionY != 1.0f) {
        param_0->directionY = 1.0f;
    } else if (param_0->offsetY > 200.0f && param_0->directionY != -1.0f) {
        param_0->directionY = -1.0f;
    } else param_0->offsetY += param_0->speedY;

    local_5 = 0;
    func_800E3B50(&local_1, &local_2, &local_0);
    func_800E3980(local_3);
    func_800EFB24(local_4, local_3, param_0->previousPosition);
    /* Resolve horizontal movement against four yaw sectors. The alternate
     * camera mode uses angle changes instead of position displacement. */
    if (!func_800F690C(func_800F54E4())) {
        if (local_2 > 135.0f && local_2 < 225.0f) {
            if (local_4[0] < -5.0f) local_5 = 1;
            if (local_4[0] > 5.0f) local_5 = -1;
        }
        if (local_2 > 315.0f || local_2 < 45.0f) {
            if (local_4[0] < -5.0f) local_5 = -1;
            if (local_4[0] > 5.0f) local_5 = 1;
        }
        if (local_2 > 45.0f && local_2 < 135.0f) {
            if (local_4[2] < -5.0f) local_5 = 1;
            if (local_4[2] > 5.0f) local_5 = -1;
        }
        if (local_2 > 225.0f && local_2 < 315.0f) {
            if (local_4[2] < -5.0f) local_5 = -1;
            if (local_4[2] > 5.0f) local_5 = 1;
        }
    } else {
        if (param_0->previousYaw < local_2) local_5 = -1;
        if (param_0->previousYaw > local_2) local_5 = 1;
        if (param_0->previousPitch > local_1) local_4[1] = -5.0f;
        if (param_0->previousPitch < local_1) local_4[1] = 5.0f;
        param_0->previousYaw = local_2;
        param_0->previousPitch = local_1;
    }
    func_800EE7F8(param_0->previousPosition, local_3);
    /* Smooth toward the camera-response speeds, otherwise damp the drift.
     * Both damping comparisons intentionally use positive 0.15f: this is
     * present in the target and must not be rewritten as an absolute test. */
    if (local_5 == 1) {
        param_0->directionX = -1.0f;
        param_0->speedX += (-5.0f - param_0->speedX) * 0.5f;
    } else if (local_5 == -1) {
        param_0->directionX = 1.0f;
        param_0->speedX += (5.0f - param_0->speedX) * 0.5f;
    } else {
        if (param_0->speedX > 0.15f || param_0->speedX < 0.15f) param_0->speedX *= 0.8f;
    }
    if (local_4[1] > 2.5f) {
        param_0->directionY = -1.0f;
        param_0->speedY += (-2.0f - param_0->speedY) * 0.5f;
    } else if (local_4[1] < -2.5f) {
        param_0->directionY = 1.0f;
        param_0->speedY += (2.0f - param_0->speedY) * 0.5f;
    } else if (param_0->speedX > 0.15f || param_0->speedX < 0.15f) param_0->speedX *= 0.3f;
    /* The final fallback above intentionally damps speedX, not speedY.
     * State 1 updates fade only when the packed active flag is set. */
    switch (param_0->state.value) {
    case 1:
        if (param_0->flags.active) {
            if (!func_800D90A4(&param_0->timer)) {
                _subaddiefade_entrypoint_1(param_0, (s32)func_800F10B4(param_0->timer, 0.0f, 8.0f, 255.0f, 0.0f));
            }
        }
        break;
    case 2:
        break;
    }
}

s32 func_808009F0_chfog(void *param_0, s32 param_1, s32 param_2)
{
    /* Release the fade state and fog resources on the cleanup event. */
    switch (param_1) {
        case 0x4F:
            _subaddiefade_entrypoint_3(param_0);
            func_800CF494();
            break;
        default:
            return 0;
    }
    return 1;
}

int chfog_entrypoint_0()
{
  return &D_80800A90_chfog;
}
