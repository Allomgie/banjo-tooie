// Shared enter/exit/update hooks of the Bee states: set bee flags, stick zones, collision size and
// roll/pitch rates on enter, restore them on exit, and forward updates to the bee subsystem.
#include "common.h"

extern void func_8009BF5C(void *, f32);
extern void baroll_setIdeal(void *, f32);
extern void func_80092864(void *, f32);

// Bee transformation: shared enter/exit/update hooks for all Bee states.
// Exit hook: restores what the enter hook changed.
void bsbee_entrypoint_0(void *player)
{
    if (!func_8009E74C(player, 1)) {
        func_800947EC(player, 1, 0);
        func_8009BF5C(player, 0.0f);
        baroll_setIdeal(player, 0.0f);
        bastick_popZone(player);
        func_800A0CF4(player, 0);
        func_800A0CE8(player, 0);
        baflag_clear(player, 3);
        baflag_clear(player, 4);
        func_8009E474(player);
        func_80095A40(player);
        _babee_entrypoint_3(player);
        func_80092864(player, 1.0f);
    }
}

// Enter hook: sets bee flags, stick zones and collision size.
void bsbee_entrypoint_1(s32 player)
{
    if (func_8009E77C(player, 1) == 0) {
        _babee_entrypoint_4(player);
        func_8009BFE4(player, 0x447A0000, 0x41400000);
        baroll_setAngularVelocity(player, 0x447A0000, 0x41400000);
        func_800959C8(player, 0x42480000, 0x41C80000);
        baflag_set(player, 3);
        baflag_set(player, 4);
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0x3CF5C28F);
        bastick_setZoneMax(player, 1, 0x3F800000);
        func_8009E4AC(player);
        func_8009E55C(player, 0, 0x41F00000);
        func_8009E55C(player, 1, 0x42200000);
        func_800959C8(player, 0x42960000, 0x422C0000);
        func_8009590C(player, 0x42960000);
        func_800947EC(player, 1, 1);
        func_80092864(player, 1.0999908f);
    }
}

// Update: forwards to the bee subsystem.
int bsbee_entrypoint_2()
{
    _babee_entrypoint_8();
}
