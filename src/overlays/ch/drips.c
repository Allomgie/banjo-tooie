#include "common.h"

extern int D_80800610_chdrips;
extern f32 func_800DC178(f32, f32);
extern u8 D_80800658_chdrips[];
extern void func_800BABB8(s32, void *, void *, f32, void *);
extern s32 func_800DC298(f32);
extern u8 D_80800698_chdrips[];
extern void _chdrips_entrypoint_1(void);
extern void _chdrips_entrypoint_2(void);
typedef struct { u8 pad_0[0x76]; u16 local_0 : 9; u16 pad_1 : 7; } DripActorCount;
typedef struct { f32 local_0[3]; f32 local_1; u8 local_2; u8 local_3[3]; } DripPoint49;
extern void *func_80100094(Actor *, u32);
extern void *func_800CC63C(s32, s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 _subaddie3d_entrypoint_0(f32 *, f32, f32, f32 *);
extern s32 _subaddie3d_entrypoint_1(f32 *, f32, f32, f32 *);
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_80800260_chdrips(), func_808005CC_chdrips();

int chdrips_entrypoint_0()
{
  return &D_80800610_chdrips;
}

void chdrips_entrypoint_1(Actor *param_0, f32 *param_1)
{
    u16 local_0;

    local_0 = (u32)(func_800DC178(1.0f, 1.4f) * 1023.0f);
    func_800C4140((local_0 << 21) + 0xBBD53, param_1, 0x5DC012C);
    _fxripple_entrypoint_0(0, param_1);
}

void chdrips_entrypoint_2(s32 param_0, f32 *param_1)
{
    s32 local_0 = func_800B53A4(5);
    u16 local_1;

    func_800BA6B0(local_0, -50, 0, -50, 50, 0, 50);
    func_800BA4D0(local_0, (s16)(s32)param_1[1]);
    func_800BABB8(local_0, param_1, 0, 1.0f, D_80800658_chdrips);
    local_1 = (u32)(func_800DC178(1.0f, 1.4f) * 1023.0f);
    func_800C4140((local_1 << 21) + 0xBBD52, param_1, 0x5DC012C);
}

void func_80800260_chdrips(param_0) Actor *param_0;
{
    f32 local_0;
    u8 *local_1;
    s32 local_2;

    local_0 = (param_0->rotation[1] * 0.333f) * 0.0027777778f;
    if (func_800DC298(local_0)) {
        local_1 = func_80100094(param_0, 0);
        local_2 = func_800B53A4(1);
        local_1 += param_0->unk6C_0 * 0x14;
        if (local_1[0x10]) {
            func_800BA544(local_2, _chdrips_entrypoint_1);
        } else {
            func_800BA544(local_2, _chdrips_entrypoint_2);
        }
        func_800BA4D0(local_2, (s16)(s32)*(f32 *)(local_1 + 0xC));
        func_800BABB8(local_2, local_1, 0, 1.0f, D_80800698_chdrips);
        func_800BA22C(local_2, 1);
        param_0->unk6C_0 = func_800DC128(0, param_0->unk74_7);
    }
}

void func_80800394_chdrips(Actor *param_0)
{
    f32 local_1;
    s32 local_2;
    s32 local_3;
    f32 local_0;
    DripPoint49 *local_4;
    s16 *local_5;
    if ((*(u32 *)((u8 *)param_0 + 0x70) >> 25) == 0) {
        func_800FFA88(param_0->unk0);
        return;
    }
    if (((DripActorCount *)param_0)->local_0 < 51) ((DripActorCount *)param_0)->local_0 = 60;
    ((DripActorCount *)param_0)->local_0 -= 50;
    func_80100074(param_0, 0, ((DripActorCount *)param_0)->local_0 * sizeof(DripPoint49));
    local_4 = func_80100094(param_0, 0);
    local_3 = func_800CC5F4((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1);
    for (local_2 = 0; local_2 < (s32)((DripActorCount *)param_0)->local_0; local_2++, local_4++) {
        local_5 = func_800CC63C((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, func_800DC128(0, local_3));
        local_1 = func_800DC178(0.0f, 359.0f);
        func_800EEB9C(local_4->local_0, local_1, func_800DC178(0.0f, (f32)local_5[6]));
        func_800EF04C(local_4->local_0, local_5);
        if (!_subaddie3d_entrypoint_0(local_4->local_0, 0.0f, -5000.0f, &local_4->local_1))
            local_4->local_1 = *(f32 *)((u8 *)local_5 + 4);
        if (!_subaddie3d_entrypoint_1(local_4->local_0, 0.0f, -5000.0f, &local_0))
            local_0 = local_4->local_1 - 50.0f;
        if (local_4->local_1 < local_0) {
            local_4->local_1 = local_0;
            local_4->local_2 = 1;
        } else local_4->local_2 = 0;
    }
}

void func_808005CC_chdrips(param_0) s32 param_0; {
    func_80100074(param_0, 0, 0);
}
