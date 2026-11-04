// Hut in Glitter Gulch Mine blown up by a linked TNT detonator: explodes with debris and a big
// sound, and sets flag 0x84.
#include "common.h"

extern int D_80800220_chtnthut[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 D_808002D8_chtnthut[];
extern s32 D_80800268_chtnthut[];
extern void _chexploder_entrypoint_10();
extern f32 func_800D8FF8(void);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
void func_80800170_chtnthut();

int *chtnthut_entrypoint_0()
{
    return &D_80800220_chtnthut;
}

void func_8080000C_chtnthut(s32 arg0)
{
}

void func_80800014_chtnthut(Actor *actor)
{
    if (actor->unk70_10 == 2) {
        actor->unk58 += func_800D8FF8();
        if (actor->unk58 > 0.5f) {
            func_800C4104(0x43F, 0.9f, 0x6D60, actor->position, 1250.0f, 2500.0f);
            func_800FFAB0(actor);
        }
    }
}

s32 func_808000B0_chtnthut(Actor *actor, s32 message, s32 unk_2)
{
    f32 pos[3];
    switch (message) {
        case 5: // explosion spawns debris
            func_800EE7F8(pos, actor->position);
            func_800EF1B8(pos, actor->rotation[1], -100.0f);
            pos[1] += 75.0f;
            _chexploder_entrypoint_3(actor, pos, 0);
            break;
        case 0x90:
            func_80800170_chtnthut(actor);
            break;
        case 0x95:
            _chtntdetonator_entrypoint_1(actor, 0x84);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800170_chtnthut(actor) Actor *actor;
{
    s32 exploder;

    exploder =func_80106790(func_80101080());
    _chexploder_entrypoint_12(exploder, 0x3C);
    _chexploder_entrypoint_13(exploder, 4);
    _chexploder_entrypoint_10(exploder, &D_808002D8_chtnthut);
    func_800BABB8(0, (u8 *) actor + 4, exploder + 0x18, *(s32 **) ((u8 *) actor + 0x38),
                  &D_80800268_chtnthut);
    func_80101FDC(actor, 2);
    func_80103110(actor, 1);
    func_800DA544(0x84);
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file, and IDO schedules them differently otherwise.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800220_chtnthut[18] = {0x158014A,
                               0x6A80001,
                               0x0,
                               (u32) func_80800014_chtnthut,
                               (u32) func_80105834,
                               (u32) func_80101870,
                               0xBB8,
                               0x0,
                               0x0,
                               0x800,
                               0x0,
                               0x0,
                               0x0,
                               (u32) func_8080000C_chtnthut,
                               (u32) func_80107C2C,
                               -0x7FFFD3FE,
                               (u32) func_808000B0_chtnthut,
                               0x0};
s32 D_80800268_chtnthut[28] = {0x410001D, 0x9DD002B,  0x8000A00, 0x220200,  0x2800600, 0x8000015,
                               0x26,      0x190000,   0x7002C,   -0x13FFEC, -0x13FFEC, 0x280014,
                               0x20DEA7,  0x71C0000A, -0xF9FFCE, -0xF9FF06, 0xC800FA,  0x41A0F10,
                               0x1D06A3,  0x14002D,   0x1F402EE, 0x2200B3,  0xCC0066,  0x99001E,
                               0x500050,  0xD0064,    0x5FEA7,   0xF1A0000};
s32 D_808002D8_chtnthut[6] = {0x2A002B, 0x2C002D, 0x2E002F, 0x300031, 0x320033, 0x34FFFF};
