#include "gc/gamefix.h"

// Save-data fix-ups run at game start.
void gcgamefix_entrypoint_0(void)
{
    func_808000D0_gcgamefix();
    func_8080011C_gcgamefix();
    func_80800164_gcgamefix();
    func_800D1864(0x4B, 0, 0);
    func_800D1864(0x4C, 0, 0);
}

// At map start: awards a Jinjo family jiggy when all Jinjos of that colour are collected.
void gcgamefix_entrypoint_1(s32 arg0)
{
    u32 i;

    for (i = 0; i < 9; i++) {
        // All Jinjos of this colour collected
        if (func_800D1338(i) == func_800D129C(i)) {
            // Jiggy not collected yet
            if (func_800D0B68(i + IoH_JV_JINJO_FAMILY_WHITE, 1U) == 0) {
                func_800D0C78(i + IoH_JV_JINJO_FAMILY_WHITE, 1U, 1U);
            }
        }
    }
}

void func_808000D0_gcgamefix(void)
{
    // Canary Mary freed -> ready to race
    if (func_800DA298(FLAG_066_PROGRESS_GGM_CANARY_MARY_FREED_1) != 0) {
        func_800DA544(FLAG_507_PROGRESS_GGM_CANARY_MARY_FREED_READY_TO_RACE);
    }
    // Cheato page from Canary Mary race 2 was spawned -> Canary Mary in CCL
    if (func_800D0A9C(4, 4) != 0) {
        func_800DA544(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL);
    }
}

void func_8080011C_gcgamefix(void)
{
    if (func_800DA298(FLAG_4FC_UNK) != 0) {
        func_800DA544(FLAG_4FD_UNK);
    }
    if (func_800DA298(FLAG_4FF_UNK) != 0) {
        func_800DA544(FLAG_500_UNK);
    }
}

void func_80800164_gcgamefix(void)
{
    // Dippy was given water but the jiggy is missing
    if ((func_800DA298(FLAG_327_UNK) != 0) && (func_800D0B68(TDL_DIPPY, 1) == 0)) {
        func_800D0C78(TDL_DIPPY, 1, 1);
    }
}
