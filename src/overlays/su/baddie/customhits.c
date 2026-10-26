#include "common.h"

extern void func_800EC358(Unk80132ED0 *, void *);
extern int D_80800350_subaddiecustomhits;
extern void func_800EE7F8(f32 *, f32 *);
extern Actor *func_80106790(void);
extern s32 func_800B1F8C(s32, f32 *, s32, f32, s32, s32, f32 *, f32, s32, s32);
extern u8 *func_80104124(void);
extern void func_80103DFC(Actor *, f32 *);
extern s32 func_800EFFB4(f32 *, f32, void *);
typedef struct { f32 position[3]; f32 radius; s32 id; s32 tick; } CustomHitSnapshot;
typedef struct { u8 pad_0[0x12]; u16 id : 15; u16 pad_1 : 1; } CustomHitMarker;
extern f32 func_80103F38(Actor *, f32 *);
typedef struct { u8 pad_0[8]; u32 pad_1 : 30; u32 custom : 1; u32 pad_2 : 1; } CustomHitFlags;
extern f32 func_800EC75C(Unk80132ED0 *, f32 *);

void subaddiecustomhits_entrypoint_0(Actor *param_0, void *param_1)
{
    func_800EC358(param_0->unk0, param_1);
    param_0->pad74_31 = 1;
}

int *subaddiecustomhits_entrypoint_1()
{
    return &D_80800350_subaddiecustomhits;
}

s32 subaddiecustomhits_entrypoint_2(Unk80132ED0 *param_0, f32 *param_1, f32 param_2, s32 param_3, s32 param_4)
{
    Actor *local_5;
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    u8 *local_6;

    local_5 = func_80106790();
    local_0 = func_80103AA0(param_0);
    local_3 = func_801040A8(local_5);
    if (!local_0 || !func_800AE0B8(local_3)) {
        return 0;
    }
    local_1 = func_800B2824(local_0);
    if (local_5->scale == 0.0f) {
        local_2 = 0;
    } else {
        local_2 = func_800B1F8C(local_1, local_5->position, func_801027F4(local_5), local_5->scale,
                              0, local_3, param_1, param_2, param_3, param_4);
    }
    if (local_2) {
        local_6 = func_80104124();
        func_800EE7F8(local_6, param_1);
        *(f32 *)(local_6 + 0xC) = param_2;
        *(u32 *)(local_6 + 0x10) = (u32)(*(u16 *)((u8 *)param_0 + 0x12)) >> 1;
        *(s32 *)(local_6 + 0x14) = func_8001211C();
    }
    return local_2;
}

s32 subaddiecustomhits_entrypoint_3(Actor *param_0, void *param_1, f32 param_2)
{
    f32 local_0[3];
    func_80103DFC(param_0, local_0);
    return !func_800EFFB4(local_0, (f32)(u32)*(u16 *)((u8 *)param_0 + 0x6A) * param_0->scale + param_2, param_1);
}

s32 subaddiecustomhits_entrypoint_4(Actor *param_0, f32 *param_1, f32 *param_2)
{
    CustomHitSnapshot *local_0;
    f32 local_1;
    local_0 = (CustomHitSnapshot *)func_80104124();
    if (local_0->id == ((CustomHitMarker *)param_0->unk0)->id && func_8001211C() == local_0->tick) {
        func_800EE7F8(param_1, local_0->position);
        if (param_2 != NULL) *param_2 = local_0->radius;
        return 1;
    }
    local_1 = func_80103F38(param_0, param_1);
    if (param_2 != NULL) *param_2 = local_1;
    return 0;
}

f32 subaddiecustomhits_entrypoint_5(Actor *param_0, f32 *param_1)
{
    if (!((CustomHitFlags *)param_0->unk0->unk0)->custom) return func_800EC75C(param_0->unk0, param_1);
    func_80103328(param_0);
    func_800EE7F8(param_1, param_0->position);
    return (f32)(u32)*(u16 *)((u8 *)param_0 + 0x6A) * param_0->scale * 1.15f;
}
