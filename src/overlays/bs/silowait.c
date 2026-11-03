#include "common.h"

extern s32 D_80800140_bssilowait[];

// Declared at file scope: a block-scope declaration at the first call would clash with this one.
extern void func_80092880(Actor *a0, s32 a1);

// Exit: pop the control mask and restore gravity.
int func_80800000_bssilowait(Actor *player)
{
    func_80092880(player, 1);
    func_80091E6C(player);
    baphysics_reset_gravity(player);
    baphysics_reset_terminal_velocity(player);
}

// Enter: float in place without gravity, control masked.
int func_8080003C_bssilowait(Actor *player)
{
    extern void baanim_playForDuration_loop(Actor * a0, s32 a1, f32 a2);
    extern void baphysics_set_target_horizontal_velocity(Actor * a0, f32 a1);
    extern void baphysics_set_gravity(Actor * a0, f32 a1);
    extern void func_8009FFD8(Actor * a0, s32 a1, s32 a2, s32 a3, s32 a4);
    extern void baphysics_set_terminal_velocity(Actor * a0, f32 a1);
    extern void func_8009BA9C(Actor * a0, s32 a1);
    extern void func_80091E48(Actor * a0, s32 a1);

    baanim_playForDuration_loop(player, 0x6f, 5.5f);
    func_8009FFD8(player, 1, 1, 3, 6);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_8009BA9C(player, 0);
    baphysics_set_gravity(player, 0);
    baphysics_set_terminal_velocity(player, 0);
    func_80091E48(player, 0x33);
    func_80092880(player, 0);
}

// Interrupt 0x90 from the silo ends the wait.
s32 func_808000D0_bssilowait(s32 player)
{
    if (func_8009E6EC() == 0x90) {
        bs_setState(player, 1);
        func_8009E830(player, 2);
    } else {
        func_80099AA8(player);
    }
}

void func_80800120_bssilowait(s32 arg0)
{
}

int bssilowait_entrypoint_0(s32 index)
{
    return D_80800140_bssilowait[index];
}

// TU-NOTE: this table is defined in C; IDO schedules some functions differently unless it is in the same unit.
s32 D_80800140_bssilowait[4] = {(u32) func_80800000_bssilowait, (u32) func_8080003C_bssilowait,
                                (u32) func_80800120_bssilowait, (u32) func_808000D0_bssilowait};
