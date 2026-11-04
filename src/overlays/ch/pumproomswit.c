// Witchyworld castle pump room: split Banjo and Kazooie switches that must both be pressed,
// and the pump actor that then runs a cutscene, sets the pumped flag and plays a slowing pump sound

#include "common.h"

extern void *D_80800380_chpumproomswitch;
extern int D_808003C8_chpumproomswitch[];
extern void func_801032B0(Actor *, u16, u16);
extern void func_80103110(Actor *, s32);
extern void _chswitch_entrypoint_10(Actor *, s32, s32);
extern s16 D_80800410_chpumproomswitch[];
extern s16 D_80800424_chpumproomswitch[];
extern s32 func_800C4350();
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800C31DC(u8, f32);
int func_8080016C_chpumproomswitch();

int chpumproomswitch_entrypoint_0()
{
    return (int) &D_80800380_chpumproomswitch;
}

int chpumproomswitch_entrypoint_1()
{
    return (int) &D_808003C8_chpumproomswitch;
}

// Marker byte 0x32 is the Kazooie switch (flag 0x9E6), else Banjo (0x9E7).
int func_80800018_chpumproomswitch(s32 actor)
{
    if (func_800DA298(0xB2)) {
        func_800DA544(func_8080016C_chpumproomswitch(actor));
    }
    _chswitch_entrypoint_7(actor, func_8080016C_chpumproomswitch(actor));
    _chswitch_entrypoint_8(
        actor, ((u32) *(u16 *) ((char *) actor + 0x76) >> 7) == 0x32 ? 0x400 : 0x200);
    if (func_800DA298(0xB2)) {
        _chswitch_entrypoint_9(actor);
        func_80103110(actor, 0);
    }
}

void func_808000BC_chpumproomswitch(Actor *actor, s32 msg, s32 data)
{
    switch (msg) {
        case 0x95:
            func_801032B0(actor, actor->unk74_7 == 0x32 ? 0x7B9 : 0x7B8, actor->unk0->unk16);
            if (func_800DA298(0xB2))
                func_80103110(actor, 0);
            break;
        case 7:
            func_80101180(0x3D2, 10, 0);
    }
    _chswitch_entrypoint_10(actor, msg, data);
}

func_8080016C_chpumproomswitch(actor)
{
    return (((u32) (u16) *(u16 *) ((char *) actor + 0x76) >> 7) == 0x32) ? 0x9E6 : 0x9E7;
}

int func_80800194_chpumproomswitch(Actor *actor)
{
    actor->unk58 = 0.0f;
    if (func_800DA298(0xB2) != 0 || _glcutDll_entrypoint_19(0x20) != 0) {
        func_80101FDC(actor, 2);
    }
}

// Plays the slowing pump sound.
void func_808001E4_chpumproomswitch(Actor *actor)
{
    s16 *sound_table;
    if (actor->unk70_10 == 2) {
        if (!actor->unk5F) {
            if (func_800EA05C() == 0xE3)
                sound_table = D_80800410_chpumproomswitch;
            else
                sound_table = D_80800424_chpumproomswitch;
            actor->unk5F = func_800C4350(0, actor->position, sound_table);
        }
        func_800D9078(&actor->unk58);
        func_800C31DC(actor->unk5F, func_800F12D4(actor->unk58, 0.0f, 3.5f, 1.0f, 0.3f));
        func_800C4350(actor->unk5F, 0, 0);
    }
}

// Message 10 starts the pump when both switches are set; 11 runs the cutscene.
s32 func_808002A0_chpumproomswitch(Actor *actor, s32 msg, s32 data)
{
    switch (msg) {
        case 10:
            if (actor->unk70_10 == 1 && func_800DA298(0x9E6) && func_800DA298(0x9E7)) {
                actor->unk58 = 3.5f;
                func_80101FDC(actor, 2);
                _capod_entrypoint_13(actor->unk0, 0, 0, 0x10);
            }
            break;
        case 11:
            _capod_entrypoint_14();
            _glcutDll_entrypoint_6(0xE1, 0x20);
            return 4;
        default:
            return 0;
    }
    return 1;
}

extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_8010A730();
void *D_80800380_chpumproomswitch = (void *) 0x0343034B;
static u32 D_80800380_chpumproomswitch_rest[17] = {0x7B80001,
                                                   0x8011A220,
                                                   (u32) _chswitch_entrypoint_6,
                                                   (u32) func_80105834,
                                                   (u32) func_80101870,
                                                   0x0,
                                                   0x0,
                                                   0x0,
                                                   0x4000080C,
                                                   0x0,
                                                   0x0,
                                                   0x0,
                                                   (u32) func_80800018_chpumproomswitch,
                                                   (u32) func_80107C2C,
                                                   0x80082C12,
                                                   (u32) func_808000BC_chpumproomswitch,
                                                   0x0};
int D_808003C8_chpumproomswitch[18] = {0x33003D2,
                                       0x1,
                                       0x0,
                                       (u32) func_808001E4_chpumproomswitch,
                                       (u32) func_80105834,
                                       (u32) func_8010A730,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x4,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80800194_chpumproomswitch,
                                       (u32) func_80107C2C,
                                       -0x7FFFF9FE,
                                       (u32) func_808002A0_chpumproomswitch,
                                       0x0};
s16 D_80800410_chpumproomswitch[10] = {0x206, 0x13,  0x4B4, 0x16, 0x2EE0,
                                       0x1,   0x1F4, 0xDAC, 0x0,  0x0};
s16 D_80800424_chpumproomswitch[14] = {0x206,  0x13, 0x4B4, 0x16, 0x1F40, 0x1, 0x320,
                                       0x1194, 0x0,  0x0,   0x0,  0x0,    0x0, 0x0};
