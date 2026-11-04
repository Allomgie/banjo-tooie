// Bee stinger weapon: keeps stinger parameter sets and a cooldown, aims at a lock-on target or
// along the egg-aim direction, and fires the stinger projectile with a muzzle particle.
#include "common.h"
#include "overlays/ba/bee.h"
#include "overlays/ba/yaw.h"
#include "overlays/ch/stinger.h"
#include "core2/1E75710.h"
#include "core2/1E75920.h"
#include "core2/1E93440.h"
#include "core2/1EB2840.h"
#include "core2/1EC8070.h"
#include "core2/1ECE0B0.h"
#include "core2/1ECD170.h"

extern s32 D_80800390_babee[];
extern s32 D_808003BC_babee[];

s32 babee_entrypoint_0(void)
{
    return sizeof(BaBee);
}

// Spawns the muzzle particle, pushed out by offset along dir.
void func_80800008_babee(f32 muzzle[3], f32 dir[3], f32 offset)
{
    f32 pos[3];
    func_800EFA98(pos, dir, offset);
    func_800EF04C(pos, muzzle);
    func_800BBCB8(pos, 0, 1.0f, 1, &D_80800390_babee);
}

// Fires a stinger, aimed at the lock-on target or along the egg-aim direction.
void babee_entrypoint_1(s32 player_index)
{
    f32 aim_pos[3];
    f32 muzzle[3];
    f32 dir[3];
    s32 unk_0;
    s32 has_target;
    PlayerState *self;
    BaBee *bee;
    f32 pitch;

    self = func_800F53D0(player_index);
    bee = self->bee;
    has_target = func_80092CDC(self, muzzle, 4);
    unk_0 = func_80092EB0(self);
    if (has_target && unk_0) {
        pitch = player_isStable(self) ? 0.0f : -func_8009BFCC(self);
        func_800F3BD0(self, 0x5, aim_pos);
        func_800EEC30(dir, pitch, yaw_get(self), bee->unk0[bee->index].unk0);
        func_80800008_babee(muzzle, dir, 0.0f);
    } else {
        _baeggfire_entrypoint_3(self, aim_pos, dir);
        func_800EF368(dir, 100.0f);
        func_800EE780(muzzle, aim_pos, dir);
        func_800EF368(dir, bee->unk0[bee->index].unk0);
        _baeggcursor_entrypoint_8(self);
        func_80800008_babee(muzzle, dir, 80.0f);
    }
    _chstinger_entrypoint_0(muzzle, aim_pos, dir, bee->unk0[bee->index].unk8, player_index);
}

// Fires when the cooldown has run out.
void babee_entrypoint_2(PlayerState *self)
{
    BaBee *bee = self->bee;
    f32 sfx_pos[3];

    if (!(0.0f < bee->cooldown)) {
        bee->cooldown += bee->unk0[bee->index].cooldown_time;
        func_8009C128(self, sfx_pos);
        func_8010D930(0xB, -1, sfx_pos, &D_808003BC_babee);
        _chbaddiesetup_entrypoint_1(_babee_entrypoint_1, self->unk184);
    }
}

void babee_entrypoint_3(PlayerState *self)
{
}

void babee_entrypoint_4(PlayerState *self)
{
    BaBee *bee = self->bee;
    bee->index = 0;
    bee->cooldown = 0.0f;
    bee->unk0[0].unk8 = 3000.0f;
    bee->unk0[0].cooldown_time = 0.5f;
    bee->unk0[0].unk0 = 1500.0f;
}

void babee_entrypoint_5(PlayerState *self)
{
    BaBee *bee = self->bee;
    bee->index--;
}

void babee_entrypoint_6(PlayerState *self)
{
    BaBee *bee = self->bee;
    bee->index++;
}

void babee_entrypoint_7(PlayerState *self, f32 speed, f32 cooldown, f32 range)
{
    BaBee *bee = self->bee;
    bee->unk0[bee->index].unk0 = speed;
    bee->unk0[bee->index].cooldown_time = cooldown;
    bee->unk0[bee->index].unk8 = range;
}

void babee_entrypoint_8(PlayerState *self)
{
    BaBee *bee = self->bee;
    if (0.0f < bee->cooldown) {
        bee->cooldown -= func_800D8FF8();
    }
}

// TU-NOTE: the overlay's .data is defined here in C; values are from the ROM.
// TU-NOTE: extern D_80800390_babee and D_808003BC_babee are declared as s32[] to match the objects.
s32 D_80800390_babee[11] = {0x1D09E2, 0x150019,  0x4C0016,  0x10000022, 0xCC00CC, 0x70007,
                            0x270000, 0x1F40000, 0x384002B, 0x260026,   0x0};
s32 D_808003BC_babee[5] = {0x13061B, 0x164E20, 0xD0100, 0x1190011, 0x0};
