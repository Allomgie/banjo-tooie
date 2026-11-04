// Most likely the Angler's model lighting callback: point-light vertex lighting like core2/1EE8100,
// but one pinned world light (its lure) is always kept and never evicted by nearer lights.
#include "common.h"

extern f32 func_800DF8C4(s32);
extern u8 *func_8010E810(void);
extern u8 *func_8010E924(s32, f32 *, f32, f32);

// Point-light vertex lighting like func_8010EACC; the light handle in pinned_light is inserted first with distance -1.
void func_80800000_trangler(s32 model, s32 capacity, s32 pinned_light, s32 param_3)
{
    s32 max_lights;
    f32 center[3];
    f32 radius;
    f32 scale;
    s32 light;
    u8 *ctx;
    ctx = func_8010E810();
    max_lights = capacity < 0 ? -capacity : capacity;
    *(u8 **) (ctx + 0x18) = *(u8 **) (ctx + 0x14) + max_lights * 40;
    func_800B237C(func_800DF8B4(model), center, &radius);
    scale = func_800DF8C4(model);
    func_80019224(center, center);
    radius *= scale;
    func_800DF900(model);
    if (pinned_light)
        *(f32 *) (func_8010E924(pinned_light, center, radius, scale) + 0x24) = -1.0f;
    light = func_800C8760(0, 1);
    while (light) {
        func_8010E924(light, center, radius, scale);
        light = func_800C878C(light, 0, 1);
    }
    ctx[0x11] = (*(u8 **) (ctx + 0x14) - ctx - 28) / 40;
    mlMtxPop();
}
// Lighting callback; packed = capacity (high half) | pinned light handle (low half).

void trangler_entrypoint_0(s32 model, u32 packed, s32 param_2, s32 param_3)
{
    s32 *ctx;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    ctx = (s32 *) func_8010E810();
    ctx[0] = model;
    unk_0 = func_800DF8D4(model);
    *(s8 *) (ctx + 0x4) = unk_0;
    ctx[5] = ctx + 0x7;
    func_80800000_trangler(model, ((s32) packed >> 0x10) & 0xFFFF, packed & 0xFFFF, param_3);
    func_800C87B8(ctx + 1);
    unk_2 = func_800DF8B4(model);
    unk_1 = func_800DF8CC(model);
    func_8010EBE4(unk_2, unk_1, func_800DF8BC(model));
}
