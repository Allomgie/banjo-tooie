#include "common.h"

extern void func_8009BF5C(void *, f32);
extern void baroll_setIdeal(void *, f32);
extern void func_80092864(void *, f32);

void bsbee_entrypoint_0(void *param_0)
{
    if (!func_8009E74C(param_0, 1)) {
        func_800947EC(param_0, 1, 0);
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        bastick_popZone(param_0);
        func_800A0CF4(param_0, 0);
        func_800A0CE8(param_0, 0);
        baflag_clear(param_0, 3);
        baflag_clear(param_0, 4);
        func_8009E474(param_0);
        func_80095A40(param_0);
        _babee_entrypoint_3(param_0);
        func_80092864(param_0, 1.0f);
    }
}

void bsbee_entrypoint_1(s32 param_0) {
    if (func_8009E77C(param_0, 1) == 0) {
        _babee_entrypoint_4(param_0);
        func_8009BFE4(param_0, 0x447A0000, 0x41400000);
        baroll_setAngularVelocity(param_0, 0x447A0000, 0x41400000);
        func_800959C8(param_0, 0x42480000, 0x41C80000);
        baflag_set(param_0, 3);
        baflag_set(param_0, 4);
        bastick_pushZone(param_0);
        bastick_setZoneMax(param_0, 0, 0x3CF5C28F);
        bastick_setZoneMax(param_0, 1, 0x3F800000);
        func_8009E4AC(param_0);
        func_8009E55C(param_0, 0, 0x41F00000);
        func_8009E55C(param_0, 1, 0x42200000);
        func_800959C8(param_0, 0x42960000, 0x422C0000);
        func_8009590C(param_0, 0x42960000);
        func_800947EC(param_0, 1, 1);
        func_80092864(param_0, 1.0999908f);
    }
}

int bsbee_entrypoint_2()
{
  _babee_entrypoint_8();
}
