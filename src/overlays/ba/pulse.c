#include "common.h"

extern void func_800F10B4(f32, f32, s32, f32, f32);
typedef struct { u8 local_0; u8 pad_0[3]; f32 local_1; f32 local_2; } PlayerPulseState;
typedef struct { u8 pad_0[0xE8]; PlayerPulseState *local_0; } PlayerPulseOwner;
extern f32 func_800D8FF8(void);
extern f32 func_800F13C4(f32, f32);

s32 bapulse_entrypoint_0() 
{
    return 0xC;
}

void bapulse_entrypoint_1(u8 *param_0) {
    u8 *local_0 = *(u8 **)(param_0 + 0xE8);
    func_800F10B4(*(f32 *)(local_0 + 8), 0.0f, *(s32 *)(local_0 + 4), 0.0f, 1.0f);
}

void bapulse_entrypoint_2(s32 arg0) 
{
}
void bapulse_entrypoint_3(void *param_0, float param_1, float param_2)
{
    (*(s8 *)((char *)((*(void **)((char *)(param_0) + (0xE8)))) + (0))) = 0;
    (*(float *)((char *)((*(void **)((char *)(param_0) + (0xE8)))) + (8))) = param_1;
    (*(float *)((char *)((*(void **)((char *)(param_0) + (0xE8)))) + (4))) = param_2;
}

void bapulse_entrypoint_4(PlayerPulseOwner *param_0)
{
    f32 local_0;
    f32 local_1;

    local_0 = func_800D8FF8();
    if (!param_0->local_0->local_0) {
        param_0->local_0->local_2 += local_0;
        local_1 = param_0->local_0->local_2;
        if (local_1 >= param_0->local_0->local_1) {
            param_0->local_0->local_2 = param_0->local_0->local_1 - func_800F13C4(local_1, param_0->local_0->local_1);
            param_0->local_0->local_0 = 1;
        }
    } else {
        param_0->local_0->local_2 -= local_0;
        local_1 = param_0->local_0->local_2;
        if (local_1 < 0.0f) {
            param_0->local_0->local_2 = func_800F13C4(-local_1, param_0->local_0->local_1);
            param_0->local_0->local_0 = 0;
        }
    }
}
