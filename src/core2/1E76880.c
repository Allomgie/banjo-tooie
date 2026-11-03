#include "core2/1E76880.h"

extern f32 bastick_getX(PlayerState *);
extern f32 mlAbsF(f32);
extern f32 func_800F1344(f32, f32, f32, f32, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
f32 bastick_distance();
f32 bastick_getAngleRelativeToBanjo();
void yaw_update();
void yaw_set(void *, f32);
f32 func_800F1DCC(f32 a, f32 b);
extern f32 yaw_get(PlayerState *);
extern f32 func_800136E4(f32);
extern void func_800F1B78(f32 *, f32 *, f32, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);

s32 func_8009CF90()
{
    return 0x8;
}

// TU-NOTE: PlayerState+0xFC points to the turn-control state: +0 mode, +4 angle threshold.
void func_8009CF98(PlayerState *self)
{
    yaw_init();
    // Matching: raw pointer casts needed for the match.
    *(f32 *) ((u8 *) *(u8 **) ((u8 *) self + 0xFC) + 4) = 0.0f;
    *(s32 *) ((u8 *) *(u8 **) ((u8 *) self + 0xFC) + 0) = 0;
    func_8009D2D8(self, 1);
}

// Sets the angle threshold used by mode 7.
void func_8009CFD8(PlayerState *self, f32 threshold)
{
    *(f32 *) (*(s32 *) ((s8 *) self + 252) + 4) = threshold;
}

// Steers ideal yaw by stick X.
void func_8009CFE8(PlayerState *self)
{
    f32 x = bastick_getX(self);
    f32 delta;
    if (0.03f < mlAbsF(x)) {
        delta = func_800F1344(x, 0.0f, 1.0f, 1.0f, 6.0f);
    } else {
        delta = 0.0f;
    }
    yaw_setIdeal(self, yaw_getIdeal(self) + delta);
}

// Per-frame yaw control, by mode: 1 follow stick, 5 reversed, 3 keep ideal,
// 6 stick-X steering, 4 snap, 7 follow stick past threshold, 8 follow or keep current.
void func_8009D088(u8 *self)
{
    switch (**(u32 **) ((s8 *) self + 0xFC)) {
        case 0:
            break;
        case 1:
            if (bastick_distance(self) != 0.0f) {
                yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
            }
            yaw_update(self);
            return;
        case 5:
            if (bastick_distance(self) != 0.0f) {
                yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self) + 180.0f);
            }
            yaw_update(self);
            return;
        case 3:
            yaw_update(self);
            return;
        case 6:
            func_8009CFE8(self);
            yaw_update(self);
            return;
        case 4:
            if (bastick_distance(self) != 0.0f) {
                yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
                yaw_set(self, yaw_getIdeal(self));
            }
            yaw_update(self);
            return;
        case 7:
            if (bastick_distance(self) != 0.0f) {
                f32 stick_angle = bastick_getAngleRelativeToBanjo(self);
                if (*(f32 *) ((s8 *) *(u32 **) ((s8 *) self + 0xFC) + 4) <=
                    mlAbsF(func_800F1DCC(yaw_getIdeal(self), stick_angle))) {
                    yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
                }
            }
            yaw_update(self);
            return;
        case 8:
            if (bastick_distance(self) != 0.0f) {
                yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
            } else {
                yaw_setIdeal(self, yaw_get(self));
            }
            yaw_update(self);
            return;
        case 9:
            yaw_update(self);
    }
}

void func_8009D2D8(self, mode) PlayerState *self;
s32 mode;
{
    **(s32 **) ((u8 *) self + 0xFC) = mode;
}

u32 func_8009D2E4(u8 *self)
{
    return **(s32 ***) (self + 0xFC);
}

// Aligns pitch and roll to the floor normal, relative to yaw (or yaw + 180 if reversed).
void func_8009D2F0(PlayerState *self, s32 reversed, f32 unk_0)
{
    f32 normal[3];
    f32 angles[3];
    if ((func_80096628(self) & 2) == 0) {
        func_800963C0(self, normal);
        if (reversed != 0) {
            func_800F1B78(angles, normal, func_800136E4(yaw_get(self) + 180.0f), unk_0);
        } else {
            func_800F1B78(angles, normal, yaw_get(self), unk_0);
        }
        func_8009BF5C(self, angles[0]);
        baroll_setIdeal(self, angles[2]);
    }
}

void func_8009D3A8(PlayerState *self, s32 reversed)
{
    func_8009D2F0(self, reversed, 1.0f);
}
