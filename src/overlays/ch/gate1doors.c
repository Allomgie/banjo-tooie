#include "common.h"

extern int D_808004B8_chgate1doors[];
extern int D_80800500_chgate1doors[];
extern u8 D_80800480_chgate1doors[];
extern u8 D_80800494_chgate1doors[];
extern u8 D_808004A8_chgate1doors[];
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_80109748(f32 *, s32, s32, s32, f32, s32, s32, s32);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);

// Message 0x40 on either leaf: set flag 0xB1 and wake both doors.
s32 func_80800000_chgate1doors(u8 *door, s32 message, s32 param_2)
{
    u8 *other;

    if (message == 0x40) {
        other = func_80106790(*(s32 *) ((s8 *) door + 0x3C));
        if ((s32) ((u32) (u16) *(u16 *) ((s8 *) door + 0x72) >> 0xA) < 3) {
            func_80103110(door, 1);
        }
        if ((s32) ((u32) (u16) *(u16 *) ((s8 *) other + 0x72) >> 0xA) < 3) {
            func_80103110(other, 1);
        }
        func_8010A570(door);
        func_8010A570(other);
        func_800DA544(0xB1);
    } else {
        return 0;
    }
    return 1;
}

// Door 0x128: finds its partner 0x129 and links them; opens at once if flag 0xB1 is set.
int func_808000A4_chgate1doors(Actor *door)
{
    s32 *base;
    base = (s32 *) ((char *) door + 0x4);
    if (func_800DA298(0xB1)) {
        base = (char *) door;
        *(f32 *) ((char *) base + 0x48) = 90.0f;
        func_8010A570(door);
        func_80101FDC(door, 3);
    } else {
        Actor *other;
        other = _subaddiefind_entrypoint_0(base, 0x129, -1, 0);
        base = (char *) door;
        if (other != 0) {
            *(s32 *) (0x3C + (char *) other) = *(s32 *) (base + 0);
            *(s32 *) (base = (char *) door + 0x3C) = *(s32 *) ((char *) other + 0);
        }
    }
}

// Door 0x128: once opened, spawns debris and sounds and swings open by +90 degrees.
void func_80800128_chgate1doors(Actor *door)
{
    f32 debris_pos[3];
    switch (door->unk70_10) {
        case 1:
            if (func_800DA298(0xB1)) {
                func_800EEB9C(debris_pos, door->rotation[1] - 180.0f, 400.0f);
                func_800EF04C(debris_pos, door->position);
                func_80109748(debris_pos, 8, -40, 100, 2.15f, 180, 60, 80);
                _subaddieaudioquick_entrypoint_2(door, door->position,
                                                 D_80800480_chgate1doors);
                _subaddieaudioquick_entrypoint_2(door, door->position,
                                                 D_80800494_chgate1doors);
                func_80101FDC(door, 2);
                _subaddieDll_entrypoint_4(door, 1);
                ((u8 *) door)[0x74] &= ~0x40;
                *(f32 *) ((u8 *) door + 0x58) = 0.0f;
            }
        case 3:
            break;
        case 2:
            *(f32 *) ((u8 *) door + 0x54) = 90.0f;
            _subaddieaudioloop_entrypoint_4(door, door->position, 1, D_808004A8_chgate1doors);
            if (func_80102CF4(door, 2.0f)) {
                func_80101FDC(door, 3);
                func_80103110(door, 0);
                _subaddieaudioloop_entrypoint_2(door);
                return;
            }
            func_80102B2C(door, 1.0f);
    }
}

// Door 0x129: finds its partner 0x128 and links them; opens at once if flag 0xB1 is set.
int func_808002B0_chgate1doors(Actor *door)
{
    s32 *base;
    base = (s32 *) ((char *) door + 0);
    if (func_800DA298(0xB1)) {
        *(f32 *) ((char *) base + 0x48) = -90.0f;
        func_8010A570(door);
        func_80101FDC(door, 3);
    } else {
        Actor *other;
        other = _subaddiefind_entrypoint_0((char *) door + 4, 0x128, -1, 0);
        if (other != 0) {
            *(s32 *) ((char *) other + 0x3C) = *(s32 *) ((char *) door + 0);
            *(s32 *) ((char *) door + 0x3C) = *(s32 *) ((char *) other + 0);
        }
    }
}

// Door 0x129: once opened, spawns debris and swings open by -90 degrees.
void func_80800334_chgate1doors(Actor *door)
{
    f32 debris_pos[3];
    switch (door->unk70_10) {
        case 1:
            if (func_800DA298(0xB1)) {
                func_800EEB9C(debris_pos, door->rotation[1], 400.0f);
                func_800EF04C(debris_pos, door->position);
                func_80109748(debris_pos, 8, -40, 100, 2.15f, 180, 60, 80);
                func_80101FDC(door, 2);
                func_80103110(door, 1);
            }
            break;
        case 2:
            door->unk54 = -90.0f;
            if (func_80102CF4(door, 2.0f)) {
                func_80101FDC(door, 3);
                func_80103110(door, 0);
            } else {
                func_80102B2C(door, 1.0f);
            }
        case 3:
            break;
    }
}

int chgate1doors_entrypoint_0()
{
    return &D_808004B8_chgate1doors;
}

int chgate1doors_entrypoint_1()
{
    return (int) &D_80800500_chgate1doors;
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file and
// IDO's assembler schedules them differently otherwise. Values are taken from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_80800480_chgate1doors[20] = {0x0,  0x13, 0x4, 0x13, 0x0, 0xA,  0x0,  0xE6, 0x0, 0x16,
                                  0x6D, 0x60, 0x0, 0x1,  0x4, 0xE2, 0x13, 0x88, 0x0, 0x0};
u8 D_80800494_chgate1doors[20] = {0x0,  0x13, 0x3, 0xF1, 0x0, 0xA,  0x1,  0x0,  0x0, 0x16,
                                  0x6D, 0x60, 0x0, 0x1,  0x4, 0xE2, 0x13, 0x88, 0x0, 0x0};
u8 D_808004A8_chgate1doors[16] = {0x0, 0x13, 0x4, 0xAD, 0x0,  0x16, 0x61, 0xA8,
                                  0x0, 0x1,  0x0, 0xFA, 0x13, 0x88, 0x0,  0x0};
int D_808004B8_chgate1doors[18] = {0x560128,
                                   0x6540001,
                                   0x0,
                                   (u32) func_80800128_chgate1doors,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0xC04,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_808000A4_chgate1doors,
                                   (u32) func_80107C2C,
                                   -0x7FFFD400,
                                   (u32) func_80800000_chgate1doors,
                                   0x0};
int D_80800500_chgate1doors[20] = {0x570129,
                                   0x6550001,
                                   0x0,
                                   (u32) func_80800334_chgate1doors,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0xC04,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_808002B0_chgate1doors,
                                   (u32) func_80107C2C,
                                   -0x7FFFD400,
                                   (u32) func_80800000_chgate1doors,
                                   0x0,
                                   0x0,
                                   0x0};
