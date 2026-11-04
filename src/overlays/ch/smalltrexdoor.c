#include "common.h"

extern void func_800F5A00(s32, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_80103EAC(Actor *);
extern void _chdoormake_entrypoint_2(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F2094(f32, f32);
extern int D_808002E0_chsmalltrexdoor[];

// Setup: opens for the small T-Rex within 500 units.
void func_80800000_chsmalltrexdoor(Actor *door)
{
    f32 player_pos[3];
    f32 unk_0[3];
    if (func_800F5410(func_800F54E4()) == 0x12) {
        func_800F5A00(func_800F54E4(), player_pos);
        if (func_800EEAD4(player_pos, door->position) < 500.0f) {
            door->unk64_20 = 1;
            func_80101FDC(door, 4);
        }
    }
    func_800EE7F8(player_pos, door->position);
    player_pos[1] += 100.0f;
    door->position[1] -= 100.0f;
    func_800BEF00(player_pos, door->position, unk_0, 0);
    door->position[1] += func_80103EAC(door);
    _chdoormake_entrypoint_2(door, door->rotation[1] + 90.0f, 0.0f, door->scale * 200.0f,
                             10, -1);
    _chdoormake_entrypoint_5(door, 1.0f);
    _chdoormake_entrypoint_6(door, 0.5f);
    _chdoormake_entrypoint_8(door, 5);
}

void func_80800150_chsmalltrexdoor(Actor *door)
{
    f32 player_pos[3];
    f32 yaw_to_player;

    if (door->unk70_10 == 4 && func_800D90A4((f32 *) ((u8 *) door + 0x34))) {
        func_800F5A00(func_800F54E4(), player_pos);
        yaw_to_player = func_800F1DF4(door->position, player_pos);
        if (func_800EEAD4(player_pos, door->position) < 400.0f) {
            if (func_800F2094(door->rotation[1] - 90.0f, yaw_to_player) > 30.0f) {
                func_8010108C(door, 8, 0);
            }
        } else {
            func_8010108C(door, 8, 0);
        }
    }
    _chdoor_entrypoint_0(door);
}

// A roar turns the open message into a timed open.
void func_80800244_chsmalltrexdoor(Actor *door, s32 msg, s32 msg_arg)
{
    if (msg == 0x1D || msg == 0x1E) {
        if (func_800F52B8(func_800F54E4(), door->unk0) == 0x18) {
            ((f32 *) door->actorData)[7] = 4.0f;
            _chdoor_entrypoint_1(door, 7, 0);
            return;
        }
    }
    _chdoor_entrypoint_1(door, msg, msg_arg);
}

int *chsmalltrexdoor_entrypoint_0()
{
    return D_808002E0_chsmalltrexdoor;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern u8 boot_thread_stack[];
int D_808002E0_chsmalltrexdoor[20] = {0xAC028F,
                                      0x8880001,
                                      0x0,
                                      (u32) func_80800150_chsmalltrexdoor,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x13880000,
                                      0x0,
                                      0x0,
                                      0x800,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800000_chsmalltrexdoor,
                                      (u32) func_80107C2C,
                                      (u32) ((u8 *) boot_thread_stack + 0x1F22),
                                      (u32) func_80800244_chsmalltrexdoor,
                                      0x0,
                                      0x0,
                                      0x0};
