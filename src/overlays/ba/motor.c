// Per-player rumble: maps a player to its controller and forwards start/pulse/stop requests.
#include "common.h"

extern void func_80018854(s32 param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4,
                          f32 param_5, f32 param_6);

// Each entrypoint maps the player to its controller index and forwards the rumble request.
int bamotor_entrypoint_0(s32 player, s32 unk_0, s32 unk_1)
{
    // Matching: "| 0" is needed for the match.
    func_80018820(bakey_getControllerIndex(player) | 0, unk_0, unk_1);
}

int bamotor_entrypoint_1(s32 player, s32 unk_0, s32 unk_1, s32 unk_2)
{
    // Matching: needed for the match.
    func_800187B4(bakey_getControllerIndex(player) | 0, unk_0, unk_1, unk_2);
}

int bamotor_entrypoint_2(s32 player, s32 unk_0, s32 unk_1, s32 unk_2)
{
    // Matching: "| 0" is needed for the match.
    func_800187E8(bakey_getControllerIndex(player) | 0, unk_0, unk_1, unk_2);
}

void bamotor_entrypoint_3(s32 player, s32 unk_0, s32 unk_1, s32 unk_2, f32 unk_3,
                          f32 unk_4, f32 unk_5)
{
    func_80018854(bakey_getControllerIndex(player), unk_0, unk_1, unk_2, unk_3, unk_4,
                  unk_5);
}
