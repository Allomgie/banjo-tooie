#include "common.h"

extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern int D_808001B8_chexplodingchainlinks[];
void func_8080010C_chexplodingchainlinks();

int chexplodingchainlinks_entrypoint_0()
{
    extern void *D_80800170_chexplodingchainlinks;
    return (int) &D_80800170_chexplodingchainlinks;
}

void func_8080000C_chexplodingchainlinks(s32 actor)
{
}

void func_80800014_chexplodingchainlinks(s32 actor)
{
    _subaddieDll_entrypoint_7(actor, 0xB);
}

// Billboard: turns the actor's yaw (+0x48) to face the viewport.
s32 func_80800034_chexplodingchainlinks(s32 actor, s32 param_1)
{
    f32 rotation[3];

    func_800E3A58(rotation);
    *(f32 *) ((char *) actor + 0x48) = rotation[1];
    func_80101870(actor, param_1);
}

// Message 5 (broken): dust burst and shatter. Message 0x90: set exploder velocity range.
s32 func_80800070_chexplodingchainlinks(Actor *actor, s32 message, s32 param_2)
{
    f32 pos[3];
    switch (message) {
        case 5:
            func_80101038(pos);
            func_8080010C_chexplodingchainlinks(actor, pos);
            _chexploder_entrypoint_3(actor, pos, 8);
            break;
        case 0x90:
            _chexploder_entrypoint_6(func_80106790(func_80101080()), 300.0f, 400.0f);
            break;
        default:
            return 0;
    }
    return 1;
}

// Spawns the dust burst.
void func_8080010C_chexplodingchainlinks(actor, pos) s32 actor;
f32 *pos;
{
    f32 burst_pos[3];

    func_800EE7F8(burst_pos, actor + 4, actor);
    burst_pos[1] = pos[1];
    func_800BBCB8(burst_pos, burst_pos, 0x3F4CCCCD, 4, &D_808001B8_chexplodingchainlinks);
}

// TU-NOTE: the overlay .data is defined here in C. Its tables point to functions of this file,
// and IDO's assembler schedules them differently unless defined in the same unit. Values are from the ROM.
// D_808001B8_chexplodingchainlinks is declared as int[] to match the object (same address).
extern void func_80105834();
extern void func_80107C2C();
void *D_80800170_chexplodingchainlinks = (void *) 0x01580473;
static u32 D_80800170_chexplodingchainlinks_rest[17] = {0x7BC0001,
                                                        0x0,
                                                        (u32) func_80800014_chexplodingchainlinks,
                                                        (u32) func_80105834,
                                                        (u32) func_80800034_chexplodingchainlinks,
                                                        0x0,
                                                        0x0,
                                                        0x0,
                                                        0x4,
                                                        0x0,
                                                        0x0,
                                                        0x0,
                                                        (u32) func_8080000C_chexplodingchainlinks,
                                                        (u32) func_80107C2C,
                                                        0x80000002,
                                                        (u32) func_80800070_chexplodingchainlinks,
                                                        0x0};
int D_808001B8_chexplodingchainlinks[14] = {0x1D09E2,  0x220026, 0x260019, 0x190027,  0xC8,
                                            0xF0,      0x150000, 0xCC002B, 0x14C01B3, 0x2D00FA,
                                            0x190000E, 0xA0014,  0x1BFC18, -0x3200000};
