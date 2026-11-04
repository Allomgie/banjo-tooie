#include "common.h"

extern int D_808001C0_chcaveofhorrorsdoors[];
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 D_80800208_chcaveofhorrorsdoors[];
extern s32 func_80101080();
extern s32 func_80106790(s32);
extern void _chexploder_entrypoint_12(s32, s32);
extern void func_800C4AF0();
extern void func_800DA544(s32);
extern void func_800FFAB0();
typedef struct {
    u8 pad[0x76];
    u16 f76 : 9;
    u16 pad76 : 7;
} DoorState;
void func_80800144_chcaveofhorrorsdoors();
s32 func_808001A4_chcaveofhorrorsdoors();

int *chcaveofhorrorsdoors_entrypoint_0()
{
    return &D_808001C0_chcaveofhorrorsdoors;
}

int func_8080000C_chcaveofhorrorsdoors(s32 actor)
{
    s32 flag_id;
    // Matching: the extra copies of the flag id are needed for the match.
    unsigned int flag_copy;
    int flag_alias;
    flag_id = func_808001A4_chcaveofhorrorsdoors(actor);
    flag_copy = flag_id | flag_id;
    if (func_800DA298(flag_alias = flag_copy)) {
        func_800FFAB0(actor);
    } else {
        func_80109EEC(actor, 0x40);
        _subaddiefade_entrypoint_14(actor);
        func_8010A63C(actor);
    }
}

s32 func_8080006C_chcaveofhorrorsdoors(Actor *actor, s32 msg, s32 data)
{
    f32 pos[3];

    switch (msg) {
        case 0x40:
            func_800EE7F8(pos, actor->position);
            pos[1] += 150.0f;
            func_800EF1B8(pos, actor->rotation[1], -80.0f);
            _chexploder_entrypoint_3(actor, pos, 7);
            if ((s32) actor->unk74_7 < 0x34)
                func_800F8300(func_800F54E4(), 2, actor->position);
            break;
        case 0x90:
            func_80800144_chcaveofhorrorsdoors(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800144_chcaveofhorrorsdoors(actor) u8 *actor;
{
    _chexploder_entrypoint_12(func_80106790(func_80101080(actor)), 0x3C);
    func_800C4AF0(actor + 4, &D_80800208_chcaveofhorrorsdoors);
    func_800DA544(func_808001A4_chcaveofhorrorsdoors(actor));
    func_800FFAB0(actor);
}

// Broken flag id of this door: 0x65 + actor parameter.
s32 func_808001A4_chcaveofhorrorsdoors(door)
DoorState *door;
{
    return door->f76 + 0x65;
}

// TU-NOTE: the overlay .data is defined in this file. Its tables point to functions here, and
// IDO's assembler schedules some of them differently unless the tables are in the same unit.
extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _bsbtrot_entrypoint_10();
int D_808001C0_chcaveofhorrorsdoors[18] = {0x19A014C,
                                           0x78B0001,
                                           0x0,
                                           (u32) func_80102EC0,
                                           (u32) func_80105834,
                                           (u32) func_80101870,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x20000,
                                           0x0,
                                           (u32) func_80108ED0,
                                           0x0,
                                           (u32) func_8080000C_chcaveofhorrorsdoors,
                                           (u32) func_80107C2C,
                                           (u32) _bsbtrot_entrypoint_10,
                                           (u32) func_8080006C_chcaveofhorrorsdoors,
                                           0x0};
s32 D_80800208_chcaveofhorrorsdoors[6] = {0x1304C8, 0xA00E6, 0x180001, 0x3201388, 0x0, 0x0};
