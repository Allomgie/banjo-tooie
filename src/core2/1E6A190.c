// Probably a small player sub-module that steps timed keyframe sequences on a model-modifier
// slot (idle or run sequence); similar in shape to BK's baeyes.
#include "common.h"
#include "core2/1E6A190.h"

typedef struct {
    u8 pad0[0xC];
} Unk_1E6A190_1;

typedef struct {
    f32 unk0;
} Unk_1E6A190_0;

extern u32 D_80117CC0[];
extern u32 D_80117CFC[];
extern u32 D_80117D80[];

s32 func_800908A0(void)
{
    return sizeof(BaUnknown20);
}

// Returns the keyframe table for a sequence index.
// Keyframe list has varying length; the struct view covers only its head.
Unk_1E6A190_0 *func_800908A8(s32 seq)
{
    switch (seq) {
        case 0:
            return (Unk_1E6A190_0 *) D_80117D80;

        case 1:
            return (Unk_1E6A190_0 *) D_80117CFC;

        case 2:
            return (Unk_1E6A190_0 *) D_80117CC0;

        default:
            return NULL;
    }
}

void func_800908F0(PlayerState *self, s32 mode)
{
    self->unk20->unk9 = mode;
    if (mode == 1) {
        func_8009ADF0(self, 4, 0);
    } else {
        func_8009ADF0(self, 4, 1);
    }
}

void func_80090938(PlayerState *self)
{
    self->unk20->unk0 = 0;
    self->unk20->unk4 = 0.0f;
    self->unk20->unk8 = 0;
    self->unk20->unk9 = 0;
    func_800908F0(self, 1);
}

void func_8009097C(PlayerState *self, s32 seq)
{
    self->unk20->unk0 = seq;
    self->unk20->unk8 = 0;
    self->unk20->unk4 = func_800908A8(seq)->unk0;
    func_800908F0(self, 2);
}

void func_800909CC(PlayerState *self)
{
    func_8009097C(self, 1);
}

void func_800909EC(PlayerState *self)
{
    func_8009097C(self, 0);
}

void func_80090A0C(PlayerState *self)
{
    func_8009097C(self, 2);
}

void func_80090A2C(PlayerState *self)
{
    func_800908F0(self, 1);
}

// Steps the active sequence by the frame time and applies due entries.
void func_80090A4C(u8 *player)
{
    f32 frame_delta;
    f32 timer;
    f32 time_left;
    u8 *entry;
    u8 *state;
    u8 *state_next;
    float mlAbsF(float);
    frame_delta = func_800D8FF8();
    time_left = frame_delta;
    if (frame_delta > 0.0f) {
    loop_1:
        state = *(u8 **) ((s8 *) player + 0x20);

        *(f32 *) ((s8 *) state + 4) = (f32) (*(f32 *) ((s8 *) state + 4) - time_left);
        timer = *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x20) + 4);
        if (!(timer > 0.0f)) {
            time_left = mlAbsF(timer);
            entry = (*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x20) + 8) * 0xC) +
                      (u8 *) func_800908A8(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x20) + 0));
            func_800950FC(player, *(u8 *) ((s8 *) entry + 4), *(s32 *) ((s8 *) entry + 8));
            entry += 0xC;
            if (*(u8 *) ((s8 *) entry + 4) == 4) {
                if (*(f32 *) entry == 0.0f) {
                    func_800908F0(player, 1);
                    return;
                }
                entry = func_800908A8(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x20) + 0));
                *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x20) + 8) = 0U;
                goto block_7;
            }
            state_next = *(u8 **) ((s8 *) player + 0x20);
            *(u8 *) ((s8 *) state_next + 8) = (u8) (*(u8 *) ((s8 *) state_next + 8) + 1);
        block_7:
            *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x20) + 4) = *(f32 *) entry;

            // Matching: empty branch needed for the match.
            if (!(time_left > 0.0f)) {
            } else {
                goto loop_1;
            }
        }
    }
}

// TU-NOTE: the .data of this file is defined here in C; values taken from the ROM.
// Table layout: first duration, then entries of {duration, slot, value}; slot 4 ends/loops.
u32 D_80117CC0[15] = {0x3E99999A, 0x1000000,  0x3DCCCCCD, 0x3D0B4396, 0x0,
                      0x3DCCCCCD, 0x3E99999A, 0x1000000,  0x3DCCCCCD, 0x3D0B4396,
                      0x0,        0x3DCCCCCD, 0x3F800000, 0x4000000,  0x0};
u32 D_80117CFC[33] = {0x40000000, 0x1000000, 0x3DCCCCCD, 0x3D0B4396, 0x0, 0x3DCCCCCD,
                      0x40A00000, 0x1000000, 0x3D75C28F, 0x3D0B4396, 0x0, 0x3D75C28F,
                      0x3E4CCCCD, 0x1000000, 0x3DB851EC, 0x3D0B4396, 0x0, 0x3DB851EC,
                      0x3F800000, 0x1000000, 0x3DCCCCCD, 0x3D0B4396, 0x0, 0x3DCCCCCD,
                      0x40A00000, 0x1000000, 0x3DCCCCCD, 0x3D0B4396, 0x0, 0x3DCCCCCD,
                      0x3F800000, 0x4000000, 0x0};
u32 D_80117D80[12] = {0x0, 0x1000000, 0x3DCCCCCD, 0x3D0B4396, 0x0, 0x3DCCCCCD,
                      0x0, 0x4000000, 0x0,        0x0,        0x0, 0x0};
