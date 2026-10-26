#include "common.h"

extern int D_80800400_chklungoforcefield;
extern u8 D_80800460_chklungoforcefield[];
extern u8 D_80800448_chklungoforcefield[];
extern s32 func_800DC298(f32);
extern f32 func_800DC178(f32, f32);
extern u8 func_800E8B74(s32);
extern void func_800E8DB0(u8, s32);
extern void func_800E8D28(u8, f32);
typedef struct { u8 pad[0x18]; s32 f18; u8 pad1C[8]; u8 f24; } ForceS;
extern void func_800C8B84(s32);
extern void func_800E8C08(u8);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_801015D0(void);
extern void func_800DE448(f32 *, f32 *, f32, s32, void *);
extern void *func_8010347C(Unk80132ED0 *);
extern f32 D_8080046C_chklungoforcefield[];
extern f32 func_800D8FF8(void);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800C8E54(s32, f32, f32);

int *chklungoforcefield_entrypoint_0()
{
    return &D_80800400_chklungoforcefield;
}

void func_8080000C_chklungoforcefield(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    u8 local_2;

    local_0 = func_800DC298(0.5f) ? 1.0f : -1.0f;
    *(f32 *)((u8 *)param_0 + 0x20) = func_800DC178(30.0f, 45.0f) * local_0;
    local_1 = func_800C8A98();
    *(s32 *)((u8 *)param_0 + 0x18) = local_1;
    func_800C8CB8(local_1, param_0->position);
    func_800C8E84(*(s32 *)((u8 *)param_0 + 0x18), D_80800460_chklungoforcefield);
    local_2 = func_800E8B74(0);
    *(u8 *)((u8 *)param_0 + 0x24) = local_2;
    func_800E8DB0(local_2, 0xFF);
    func_800E8D28(*(u8 *)((u8 *)param_0 + 0x24), 1.0f);
    func_800E8D5C(*(u8 *)((u8 *)param_0 + 0x24), D_80800448_chklungoforcefield, 3);
    _subaddiefade_entrypoint_2(param_0);
    func_8010A828(param_0, 0x40);
}

void func_808000F0_chklungoforcefield(Actor *param_0)
{
    f32 local_0;

    *(f32 *)((u8 *)param_0 + 0x1C) += *(f32 *)((u8 *)param_0 + 0x20) * func_800D8FF8();
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_8080046C_chklungoforcefield);
    _subaddieaudioloop_entrypoint_1(param_0, (s32)func_800F12D4(_subaddiefade_entrypoint_0(param_0), 0.0f, 255.0f, 8000.0f, 32767.0f));
    if (*(s32 *)((u8 *)param_0 + 0x18) != 0) {
        local_0 = func_800F12D4(_subaddiefade_entrypoint_0(param_0), 0.0f, 255.0f, 300.0f, 800.0f);
        func_800C8E54(*(s32 *)((u8 *)param_0 + 0x18), local_0, 2.0f * local_0);
    }
}

void func_808001D4_chklungoforcefield(ForceS *param_0) {
    if (param_0->f18) {
        func_800C8B84(param_0->f18);
        param_0->f18 = 0;
    }
    if (param_0->f24) {
        func_800E8C08(param_0->f24);
        param_0->f24 = 0;
    }
}

s32 func_80800228_chklungoforcefield(u8 *param_0, s32 param_1, s32 param_2) {
    s32 local_0;

    if (param_1 == 0x2C) {
        local_0 = (*(s32 *)((s8 *)(param_0) + (0x18)));
        if (local_0 != 0) {
            (*(s32 *)((s8 *)(param_0) + (0x18))) = _chlightfader_entrypoint_1(local_0, 0x4019999A, 2, param_0);
        }
        _subaddiefade_entrypoint_3(param_0);
        return 1;
    }
    return 0;
}

void func_80800288_chklungoforcefield(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1;
    s32 local_2;
    void *local_4;
    s32 local_3;

    local_2 = *((u8 *)param_0 + 0x9B);
    local_1 = func_800F10B4((f32)func_800E8C58(*((u8 *)param_0 + 0x24)), 0.0f, 255.0f, 0.6f, 1.0f);
    func_800E3A58(local_0);
    func_80101970(param_0);
    local_0[2] += *(f32 *)&param_0->actorData[1];
    *((u8 *)param_0 + 0x9B) = (u32)((f32)local_2 * local_1);
    func_800DF47C(func_801015D0, param_0);
    local_3 = func_801018D8(param_0);
    local_4 = func_8010347C(param_0->unk0);
    func_800DE448(param_0->position, local_0, param_0->scale, local_3, local_4);
    *((u8 *)param_0 + 0x9B) = local_2;
}
