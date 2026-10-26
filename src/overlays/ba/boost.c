#include "common.h"

#include "overlays/ba/boost.h"
#include "playerstate.h"
#include "boost.h"

s32 baboost_entrypoint_0(void) {
    return sizeof(BaBoost);
}

s32 baboost_entrypoint_1(PlayerState *param_0)
{
    s32 local_0;
    s32 local_1 = 0;
    for (local_0 = 0; local_0 < 5; local_0++) {
        if (param_0->boost->unk8[local_0] != 0.0f) local_1++;
    }
    return local_1;
}

s32 baboost_entrypoint_2(PlayerState *self, f32 arg1);
s32 baboost_entrypoint_2(PlayerState *param_0, f32 param_1)
{
    s32 local_0;

    for (local_0 = 0; local_0 < 5; local_0++) {
        if (param_1 - 0.25f < param_0->boost->unk8[local_0]) {
            param_0->boost->unk4 = param_1;
            return 0;
        }
    }
    for (local_0 = 0; local_0 < 5; local_0++) {
        if (param_0->boost->unk8[local_0] == 0.0f) {
            param_0->boost->unk8[local_0] = param_1;
            return 1;
        }
    }
    param_0->boost->unk4 = param_1;
    return 0;
}

void baboost_entrypoint_3(PlayerState *param_0)
{
    s32 local_0;

    for (local_0 = 0; local_0 < 5; local_0++) {
        param_0->boost->unk8[local_0] = param_0->boost->unk8[local_0] = 0.0f;
    }
    param_0->boost->unk4 = 0;
    param_0->boost->unk0 = (u32)param_0->boost->unk4;
}

void baboost_entrypoint_4(PlayerState *self, s32 arg1) {
    self->boost->unk0 = arg1;
    if(self->boost->unk0 == 0) {
        _baboost_entrypoint_3(self);
    }
} 

void baboost_entrypoint_5(PlayerState *self) {
    s32 i;
    f32 tmp_f2;
    if (self->boost->unk0){
        for ( i = 0; i < 5; i++) {
            func_800D9078(&self->boost->unk8[i]);
        }
        if (self->boost->unk4 != 0.0f) {
            tmp_f2 = self->boost->unk4;
            self->boost->unk4 = 0.0f;
            baboost_entrypoint_2(self, tmp_f2);
        }
    }
}
