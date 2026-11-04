#include "common.h"

extern void *D_80800110_chfactoryposter;
extern u8 D_80800158_chfactoryposter[];

int chfactoryposter_entrypoint_0()
{
    return &D_80800110_chfactoryposter;
}

// Despawns at once if flag 0x3D is already set.
s32 func_8080000C_chfactoryposter(Actor *this)
{
    if (func_800DA298(0x3D) != 0) {
        func_800BF744(2, 2);
        func_800FFAB0(this);
    } else {
        func_800BF744(2, 1);
    }
}

// Tears the poster when the player passes it from the right in the right state.
void func_8080005C_chfactoryposter(Actor *actor)
{
    f32 player_pos[3];
    if (actor->unk70_10 == 1 && func_800F6438(func_800F54E4())) {
        func_800F5A00(func_800F54E4(), player_pos);
        if (player_pos[0] < actor->position[0]) {
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_80800158_chfactoryposter);
            func_800BF744(2, 2);
            func_800DA544(0x3D);
            func_800FFAB0(actor);
        }
    }
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
void *D_80800110_chfactoryposter = (void *) 0x015804ED;
static u32 D_80800110_chfactoryposter_rest[17] = {0x1,
                                                  0x0,
                                                  (u32) func_8080005C_chfactoryposter,
                                                  (u32) func_80105834,
                                                  (u32) func_80101870,
                                                  0x12C0000,
                                                  0x0,
                                                  0x0,
                                                  0x4,
                                                  0x0,
                                                  0x0,
                                                  0x0,
                                                  (u32) func_8080000C_chfactoryposter,
                                                  (u32) func_80107C2C,
                                                  0x80000402,
                                                  0x0,
                                                  0x0};
u8 D_80800158_chfactoryposter[8] = {0x0, 0x13, 0x4, 0x84, 0x0, 0x0, 0x0, 0x0};
