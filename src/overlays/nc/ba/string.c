#include "nc/ba/string.h"

extern f32 _ncbawaypoint_entrypoint_3(void *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
typedef struct { f32 local_0; f32 local_1; u8 local_2; } StringCameraLimits;
typedef struct { u8 pad_0[0x50]; StringCameraLimits *local_0; } StringCameraNode;

s32 ncbastring_entrypoint_0() 
{
    return 0xC;
}

void func_80800008_ncbastring(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

int ncbastring_entrypoint_1(Actor *param_0)
{
  func_80111B8C(param_0, 0x40800000, 0x41000000);
  func_801124D0(param_0, 1);
  func_80115858(param_0, 1);
  func_80115870(param_0, 0x40A00000);
}

void ncbastring_entrypoint_2(s32 arg0) 
{
}
void func_8080007C_ncbastring(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

void ncbastring_entrypoint_3(void *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7[2];
    f32 local_8;
    f32 local_9;

    func_8080007C_ncbastring(param_0, local_0);
    func_801107F0(param_0, local_2);
    if (**(s32 **)((u8 *)param_0 + 0x5C)) {
        local_5 = _ncbawaypoint_entrypoint_3(param_0, local_0, local_2);
    } else {
        local_5 = 0.0f;
    }
    func_800EFB24(local_1, local_2, local_0);
    local_6 = func_800EEF94(local_1) + local_5;
    func_800F1A88(local_1, local_7);
    if (local_5 == 0.0f) {
        func_80113978(param_0, 1, 0);
    }
    local_4 = func_80115358(param_0, local_6);
    local_7[0] = func_80115750(param_0, local_7[0]);
    local_7[1] = func_80112C3C(param_0, local_7[1]);
    local_4 -= local_5;
    func_800EEBF0(local_1, local_7, local_4);
    func_800EE780(local_2, local_0, local_1);
    if (func_80111CC8(param_0, local_2)) {
        if (!func_801138A0(param_0)) {
            func_80115444(param_0, &local_8, &local_9);
            func_801107F0(param_0, local_2);
            local_4 = func_800EEAD4(local_2, local_0);
            if (local_9 * 1.5f < local_6 && local_9 * 1.5f < local_4 &&
                func_801138F4(param_0)) {
                func_80110F44(param_0);
            }
        } else if (func_801138F4(param_0)) {
            func_80110F44(param_0);
        }
    }
    func_80800008_ncbastring(param_0, local_0);
    func_80110A68(param_0, local_3, local_0);
    func_80110790(param_0, local_3);
}

void ncbastring_entrypoint_4(StringCameraNode *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    f32 local_5;
    func_8080007C_ncbastring(param_0, local_0);
    func_801107F0(param_0, local_1);
    func_800EFB24(local_2, local_1, local_0);
    local_5 = func_800EEF94(local_2);
    param_0->local_0->local_1 = local_5;
    param_0->local_0->local_0 = local_5;
    func_80115444(param_0, &local_3, &local_4);
    if (param_0->local_0->local_0 < local_3) {
        param_0->local_0->local_2 = 1;
        param_0->local_0->local_1 = local_4;
    } else if (local_4 < param_0->local_0->local_1) {
        param_0->local_0->local_2 = 1;
        param_0->local_0->local_0 = local_3;
    } else param_0->local_0->local_2 = 0;
}
