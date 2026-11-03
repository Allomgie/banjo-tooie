#include "common.h"
#include "overlays/ba/cough.h"
#include "core2/1E76CC0.h"
#include "core2/1E7BFA0.h"
#include "core2/1EB5980.h"

s32 bacough_entrypoint_0(void)
{
    return sizeof(BaCough);
}

s32 bacough_entrypoint_1(PlayerState *self)
{
    return self->cough->unk0;
}

void bacough_entrypoint_2(PlayerState *self)
{
    bacough_entrypoint_4(self, 0);
}

void bacough_entrypoint_3(PlayerState *self)
{
    self->cough->unk0 = 0;
    bacough_entrypoint_4(self, 1);
}

// state: 0 = reset, 1 = disabled, 2 = enabled
void bacough_entrypoint_4(PlayerState *self, s32 state)
{
    switch (state) {
        case 1:
            func_8009ADF0(self, 9, 0);
            break;

        case 2:
            self->cough->unk4 = 2.0f;
            func_8009ADF0(self, 9, 1);
    }
    self->cough->unk0 = state;
}

// Per-frame tick: when the timer runs out, play a random cough for the current form and pick the next gap.
void bacough_entrypoint_5(PlayerState *self)
{
    s32 sfx_id;
    f32 roll;
    f32 pitch;

    if ((self->cough->unk0 == 2) && func_800F424C(self) && func_800D9078(&self->cough->unk4)) {
        roll = func_800DC0C0();
        pitch = func_800DC178(0.97f, 1.03f);
        switch (func_800A3274(self)) {
            case TRANSFORM_1_BK:
            case TRANSFORM_A_BANJO:
                if (roll < 0.3333f) {
                    sfx_id = 0x571;
                } else if (0.6666f < roll) {
                    sfx_id = 0x572;
                } else {
                    sfx_id = 0x573;
                }
                break;

            // Kazooie
            case 0xB:
                if (roll < 0.5f) {
                    sfx_id = 0x45B;
                } else {
                    sfx_id = 0x59F;
                }
                break;

            case TRANSFORM_D_MUMBO:
                if (roll < 0.5f) {
                    sfx_id = 0x50F;
                } else {
                    sfx_id = 0x510;
                }
                break;
            default:
                sfx_id = 0;
                break;
        }

        if (sfx_id != 0) {
            func_8009DB04(self, sfx_id, pitch, 24000);
        }

        if (func_800DC298(0.1f)) {
            self->cough->unk4 = func_800DC178(0.3f, 0.8f);
        } else if (func_800DC298(0.4f)) {
            self->cough->unk4 = func_800DC178(1.5f, 2.5f);
        } else {
            self->cough->unk4 = func_800DC178(3.5f, 4.5f);
        }
    }
}
