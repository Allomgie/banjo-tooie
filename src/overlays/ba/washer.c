// Player-side component of the Washing Machine transformation: fires laundry projectiles along
// the aim direction and animates the legs and feet (steering and spinning).
#include "common.h"
#include "overlays/ba/washer.h"
#include "core2/1E6A730.h"
#include "core2/1E6B900.h"
#include "core2/1E75920.h"
#include "core2/1EB2840.h"
#include "core2/1EBA250.h"
#include "core2/1EC8070.h"
#include "core2/1ECA640.h"
#include "core2/1ECE0B0.h"

s32 bawasher_entrypoint_0(void)
{
    return sizeof(BaWasher);
}

void bawasher_entrypoint_1(PlayerState *self)
{
}

void bawasher_entrypoint_2(PlayerState *self)
{
    self->washer->unk0 = 0.0f;
    self->washer->unk4 = 0.0f;
    self->washer->unk8 = 0.0f;
    self->washer->unkC = 0.0f;
}

void bawasher_entrypoint_3(PlayerState *self, f32 arg1[3])
{
    if (!func_80092CDC(self, arg1, 5)) {
        func_8009C128(self, arg1);
    }
}

void bawasher_entrypoint_4(PlayerState *self, f32 arg1)
{
    self->washer->unk4 = func_800F0DC0(arg1, 50.0f);
}

void bawasher_entrypoint_5(PlayerState *self, f32 arg1)
{
    self->washer->unkC = arg1;
}

void bawasher_entrypoint_6(s32 arg0)
{
    PlayerState *self = func_800F53D0(arg0);
    _chlaundry_entrypoint_1(self->washer->unk10, self->washer->unk1C, self->washer->unk28, arg0);
}

// Aims along bone 4->5, or via egg cursor as fallback; speed 1200.
void bawasher_entrypoint_7(PlayerState *self)
{
    f32 bone4_pos[3];
    f32 bone5_pos[3];
    f32 dir[3];
    if (func_80092CDC(self, bone4_pos, 4) && func_80092CDC(self, bone5_pos, 5)) {
        func_800EFB24(dir, bone4_pos, bone5_pos);
        func_800EF368(dir, 1200.0f);
    } else {
        _baeggfire_entrypoint_3(self, bone5_pos, dir);
        func_800EF368(dir, 100.0f);
        func_800EE780(bone4_pos, bone5_pos, dir);
        func_800EF368(dir, 1200.0f);
        _baeggcursor_entrypoint_8(self);
    }
    bawasher_entrypoint_8(self, bone5_pos, bone4_pos, dir);
}

void bawasher_entrypoint_8(PlayerState *self, f32 arg1[3], f32 arg2[3], f32 arg3[3])
{
    func_800EE7F8(self->washer->unk10, arg1);
    func_800EE7F8(self->washer->unk1C, arg2);
    func_800EE7F8(self->washer->unk28, arg3);
    _chbaddiesetup_entrypoint_1(_bawasher_entrypoint_6, self->unk184);
}

// Steers leg bones 0x34-0x37, spins feet bones 0x4E-0x51.
void bawasher_entrypoint_9(PlayerState *self)
{
    f32 dt = func_800D8FF8();
    Unkfunc_800E0960_1 *skeleton;
    self->washer->unk8 += self->washer->unkC * dt;
    self->washer->unk0 = func_800F15F8(self->washer->unk0, self->washer->unk4, dt * 200.0f);
    skeleton = func_80092AD8(self);
    func_800E0AF0(skeleton, 1.0f);
    func_800E0AFC(skeleton, 0x34, 1.0f, 0.0f, self->washer->unk0, 0.0f);
    func_800E0AFC(skeleton, 0x36, 1.0f, 0.0f, self->washer->unk0, 0.0f);
    func_800E0AFC(skeleton, 0x35, 1.0f, 0.0f, self->washer->unk0, 0.0f);
    func_800E0AFC(skeleton, 0x37, 1.0f, 0.0f, self->washer->unk0, 0.0f);
    func_800E0AFC(skeleton, 0x4E, 1.0f, self->washer->unk8, 0.0f, 0.0f);
    func_800E0AFC(skeleton, 0x50, 1.0f, self->washer->unk8, 0.0f, 0.0f);
    func_800E0AFC(skeleton, 0x4F, 1.0f, self->washer->unk8, 0.0f, 0.0f);
    func_800E0AFC(skeleton, 0x51, 1.0f, self->washer->unk8, 0.0f, 0.0f);
}

// TU-NOTE: the .data of this overlay is defined in C (values taken from the ROM).
