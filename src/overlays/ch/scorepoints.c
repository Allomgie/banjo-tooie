#include "common.h"

extern int D_808003C0_chscorepoints;
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern f32 func_800D8FF8(void);
extern void *func_800A89F8(void);
extern void *func_80100094(Actor *, u32);
extern s32 func_800C4C34(void *, f32 *, f32 *, s32 *);
extern s32 _subaddiefade_entrypoint_0(Actor *);
typedef struct { u8 pad_0[0x28]; s32 local_0; s32 local_1; u8 pad_1[0x20]; s32 local_2; s32 local_3; } ScoreDisplay1581;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_80108474(s32, f32 *, s32);
extern int func_800D3DA4(s32);
extern s32 _chscorepoints_entrypoint_1;

int *chscorepoints_entrypoint_0()
{
    return &D_808003C0_chscorepoints;
}

void func_8080000C_chscorepoints(u8 *param_0) {
    char local_0[0x20];
    s32 local_2;

    func_800E73D4(local_0);
    func_800E6DB4(local_0, *(s32 **)(param_0 + 0x28));
    local_2 = func_800E7188(local_0);
    func_80100074(param_0, 0, local_2 + 1);
    rare_memcpy(func_80100094(param_0, 0), local_0, local_2 + 1);
    (*(f32 *)((s8 *)(param_0) + (0x58))) = 0.8f;
    if ((*(s32 *)((s8 *)(param_0) + (0x2C))) & 1) {
        if ((*(s32 *)((s8 *)(param_0) + (0x28))) < 0) {
            func_800FC660(0xF);
            return;
        }
        func_800FC660(0xE);
    }
}

void func_808000BC_chscorepoints(Actor *param_0)
{
    s32 local_0;

    switch (param_0->unk70_10) {
    case 1:
        local_0 = func_800D9078(&param_0->unk58);
        ((f32 *)param_0->actorData)[6] = func_80013970(func_800F12D4(param_0->unk58, 0.0f, 0.8f, 0.0f, 720.0f)) * 50.0f;
        if (local_0) {
            _subaddiefade_entrypoint_3(param_0);
            func_80101FDC(param_0, 2);
        }
        break;
    case 2:
        ((f32 *)param_0->actorData)[6] = 0.0f;
        param_0->position[1] += func_800D8FF8() * 120.0f;
        break;
    }
}

void func_8080019C_chscorepoints(Actor *param_0, void *param_1)
{
    s32 local_0;
    void *local_1;
    f32 local_2[2];
    f32 local_3[3];
    void *local_6;
    s32 local_4;
    s32 local_5;

    local_0 = *(s32 *)&param_0->unk54;
    local_1 = func_800A89F8();
    func_800B8C50();
    func_800B8C8C(_subaddiefade_entrypoint_0(param_0));
    func_800B8C98(1);
    func_800B8CE0(*(s32 *)&param_0->unk50);
    func_800B7F14(param_1);
    if (local_0 == -1 || (void *)func_800A940C(local_0) == local_1) {
        func_800EE7F8(local_3, param_0->position);
        local_3[1] += *(f32 *)&param_0->actorData[6];
        local_5 = func_800C4C34(local_1, local_3, local_2, &local_4);
        if (local_4 && local_5) {
            local_6 = func_80100094(param_0, 0);
            func_800B8E28(param_1, (s32)local_2[0], (s32)local_2[1], local_6);
        }
    }
    func_800B811C(param_1);
}

void chscorepoints_entrypoint_1(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    f32 local_0[3];
    ScoreDisplay1581 *local_1;

    func_800EFA4C(local_0, (f32)param_2, (f32)param_3, (f32)param_4);
    local_1 = func_80108474(0x14E, local_0, 0);
    local_1->local_0 = param_0;
    local_1->local_1 = param_5;
    local_1->local_3 = param_1;
    local_1->local_2 = func_800D3DA4(param_1) + 0xC29;
}

void chscorepoints_entrypoint_2(s32 param_0, s32 param_1, u8 *param_2, s32 param_3) {
    _chbaddiesetup_entrypoint_6(&_chscorepoints_entrypoint_1, param_0, param_1, (s32) (*(f32 *)((s8 *)(param_2) + (0))), (s32) (*(f32 *)((s8 *)(param_2) + (4))), (s32) (*(f32 *)((s8 *)(param_2) + (8))), param_3);
}
