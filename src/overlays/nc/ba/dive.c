#include "nc/ba/dive.h"

extern void func_800EF410(int param_0);
extern f32 func_800EEF94(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);

s32 ncbadive_entrypoint_0()
{
    return 0x10;
}

void ncbadive_entrypoint_1(u8 *camera)
{
    func_800EFD24(*(u8 **) (camera + 0x18));
    *(f32 *) ((u8 *) *(u8 **) (camera + 0x18) + 0xC) = 0.0f;
    func_801120CC(camera, 0x45834000, 0x46034000, 0xC6034000);
}

void ncbadive_entrypoint_2(int camera)
{
    func_801120CC(camera, 0x44FA0000, 0x457A0000, 0xC57A0000);
}

void func_80800080_ncbadive(PlayerState *camera, f32 *target)
{
    func_80112524(camera, target);
}

// Per-frame update: the look-at point blends from the stored point toward the player.
void ncbadive_entrypoint_3(u8 *camera)
{
    f32 target[3];
    f32 offset[3];
    f32 to_player[3];
    f32 look_at[3];
    f32 cam_pos[3];
    f32 rotation[3];
    f32 distance;
    f32 blend;

    func_801107F0(camera, cam_pos);
    func_80800080_ncbadive(camera, target);
    func_800EFB24(to_player, cam_pos, target);
    distance = func_800EEF94(to_player);
    blend =
        func_800F10B4(*(f32 *) (*(u8 **) (camera + 0x18) + 0xC), 0.2f, 0.5f, distance, 300.0f);
    *(f32 *) (*(u8 **) (camera + 0x18) + 0xC) += func_800D8FF8();
    func_800EFA20(look_at, *(f32 **) (camera + 0x18), blend);
    func_800EFB24(offset, target, look_at);
    if (func_80111FD4(camera, offset)) {
        func_8011309C(camera, 0);
    }
    func_80800080_ncbadive(camera, target);
    func_80110A68(camera, rotation, target);
    func_80110790(camera, rotation);
}

// Resets the stored point.
void ncbadive_entrypoint_4(int camera)
{
    func_800EF410(*(int *) (camera + 0x18));
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
