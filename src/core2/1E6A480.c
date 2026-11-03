#include "common.h"
#include "core2/1E75920.h"
#include "core2/1E7D460.h"

s32 func_80090B90(void)
{
    return sizeof(BaUnknown2C);
}

void func_80090B98(PlayerState *self)
{
    self->unk2C->unk0 = self->unk2C->unk4 = -1;
    self->unk2C->unk18 = 0;
    self->unk2C->unk8 = -1;
    func_8009C128(self, self->unk2C->unkC);
    self->unk2C->unk19 = self->unk2C->unk1A = 0;
}

void func_80090C00(PlayerState *self, s32 arg1, s32 arg2)
{
    func_800CBB70(arg1, arg2);
}

void func_80090C28(PlayerState *self, s32 arg1)
{
    self->unk2C->unk18 = arg1;
}

#ifndef NONMATCHING

void func_80090C34(u8 *param_0)
{
    s32 local_7;
    s32 local_0;
    s32 local_1;
    int local_6;
    s32 local_2;
    s32 local_3;
    f32 local_4[3];
    s32 local_5;
    (*(u8 **) (param_0 + 0x2C))[0x1A] = (*(u8 **) (param_0 + 0x2C))[0x19];
    (*(u8 **) (param_0 + 0x2C))[0x19] = 0;
    local_5 = func_8008E37C(param_0) != 0 && 1;
    if ((((((*(u8 **) (param_0 + 0x2C))[0x18] != 0) || (player_isStable(param_0) != 0)) ||
          (local_5 != 0)) ||
         (func_800F3ED0(param_0) == 5)) ||
        (bs_getCurrentState(param_0) == 0xB)) {
        func_8009C128(param_0, *(u8 **) (param_0 + 0x2C) + 0xC);
    }
    if (func_800F3ED0(param_0) == 0xA) {
        *(s32 *) (*(u8 **) (param_0 + 0x2C) + 8) = -1;
        return;
    }
    local_0 = func_8008E37C(param_0) ? 6 : 1;
    local_2 = *(s32 *) (*(u8 **) (param_0 + 0x2C) + 0);
    local_6 = 4;
    local_3 = *(s32 *) (*(u8 **) (param_0 + 0x2C) + 4);
    local_1 = func_800CCDF4(*(u8 **) (param_0 + 0x2C) + 0xC, *(u8 **) (param_0 + 0x2C),
                            *(u8 **) (param_0 + 0x2C) + local_6, 0x12C, local_0);
    local_7 = local_1 != 0;
    if (local_7 != 0) {
        (*(u8 **) (param_0 + 0x2C))[0x19] = 1;
    }
    if ((local_7 == 0) && (*(s32 *) (*(u8 **) (param_0 + 0x2C) + 8) != -1)) {
        func_801107F0(func_800A4CA8(param_0), local_4);
        local_1 = func_800CCDF4(local_4, &local_2, &local_3, 0x384, local_0);
        if (local_1 != 0) {
            if (func_800CBBC0(local_2) != *(s32 *) (*(u8 **) (param_0 + 0x2C) + 8)) {
                local_1 = 0;
            } else {
                *(s32 *) (*(u8 **) (param_0 + 0x2C) + 0) = local_2;
                *(s32 *) (*(u8 **) (param_0 + 0x2C) + local_6) = local_3;
            }
        }
    }
    if (local_1 != 0) {
        *(s32 *) (*(u8 **) (param_0 + 0x2C) + 8) =
            func_800CBBC0(*(s32 *) (*(u8 **) (param_0 + 0x2C) + 0));
    } else {
        *(s32 *) (*(u8 **) (param_0 + 0x2C) + 8) = -1;
    }
}

#else
s32 func_80090C34(0)
{
#endif

    s32 func_80090E24(PlayerState * self)
    {
        return self->unk2C->unk8;
    }

    s32 func_80090E30(PlayerState * self)
    {
        return self->unk2C->unk1A;
    }
