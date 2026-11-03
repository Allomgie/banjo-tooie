#include "common.h"

extern f32 func_800EFB8C(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct { s32 local_0; f32 local_1; } ClimbBaseScalePreset;
extern ClimbBaseScalePreset D_808003B0_chclimbbase[];
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800F7F50(s32, f32 *, f32 *, f32, s32, s32);
extern void func_800F7F00(s32, f32 *, f32 *, f32, s32, s32, f32);
extern void *D_808003D0_chclimbbase;
extern void *D_80800418_chclimbbase;

s32 func_80800000_chclimbbase(Actor *param_0, f32 *param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    s32 local_3;
    s32 local_4;
    f32 *local_5;
    f32 local_6;

    local_5 = param_0->position;
    local_4 = _gccubesearch_entrypoint_13(local_0, 0x1FA, local_5);
    local_3 = _gccubesearch_entrypoint_13(local_1, 0x1FB, local_5);
    if (!local_4 && !local_3) {
        return 0;
    }
    if (local_4 && local_3) {
        local_2 = func_800EFB8C(local_5, local_0);
        local_6 = func_800EFB8C(local_5, local_1);
        if (local_6 < local_2) {
            local_4 = 0;
        }
    }
    if (local_4) {
        func_800EE7F8(param_1, local_0);
        param_0->unk6C_0 = 1;
    } else {
        func_800EE7F8(param_1, local_1);
        param_0->unk6C_0 = 2;
    }
    return 1;
}

s32 func_808000FC_chclimbbase(void) {
    if (_gclevel_entrypoint_4(0x80)) {
        return 2;
    }
    return 1;
}

void func_80800128_chclimbbase(Actor *param_0)
{
    ClimbBaseScalePreset *local_0;

    func_80800000_chclimbbase(param_0, param_0->actorData);
    local_0 = D_808003B0_chclimbbase;
    if (param_0->scale == 1.0f) {
        param_0->actorData[3] = func_808000FC_chclimbbase();
    } else {
        while (local_0->local_0 != 4 && local_0->local_1 != param_0->scale) local_0++;
        param_0->actorData[3] = local_0->local_0;
    }
    *(s16 *)((u8 *)param_0 + 0x7C) = (s32)func_800EEAD4(param_0->position, (f32 *)param_0->actorData) + 500;
}

void func_80800200_chclimbbase(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2[3];
    local_1 = (s32)param_0->unk74_7 + 25;
    func_8010D254(local_2);
    func_800EFB24(local_0, param_0->position, local_2);
    if (local_0[0] * local_0[0] + local_0[2] * local_0[2] < local_1 * local_1 &&
        param_0->position[1] < local_2[1] && local_2[1] <= ((f32 *)param_0->actorData)[1]) {
        switch (param_0->unk6C_9) {
            case 0x1F9:
                func_800F7F50(func_800F54E4(), param_0->position, (f32 *)param_0->actorData, (f32)param_0->unk74_7, param_0->unk6C_0, param_0->actorData[3]);
                break;
            case 0x16E:
                func_800F7F00(func_800F54E4(), param_0->position, (f32 *)param_0->actorData, (f32)param_0->unk74_7, param_0->unk6C_0, param_0->actorData[3], param_0->rotation[1]);
                break;
        }
    }
}

int chclimbbase_entrypoint_0()
{
  return &D_808003D0_chclimbbase;
}

int chclimbbase_entrypoint_1()
{
  return &D_80800418_chclimbbase;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/climbbase.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_808003B4_chclimbbase = D_808003B0_chclimbbase + 0x4 */
extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
ClimbBaseScalePreset D_808003B0_chclimbbase[4] = { 0x1, 1.01f, 0x2, 1.02f, 0x3, 1.03f, 0x4, 0.0f };
void *D_808003D0_chclimbbase = (void *)0x003501F9;
static u32 D_808003D0_chclimbbase_rest[17] = { 0x1, 0x0, (u32)func_80800200_chclimbbase, (u32)func_80105834, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, (u32)func_80800128_chclimbbase, (u32)func_80107C2C, 0x80002602, 0x0, 0x0 };
void *D_80800418_chclimbbase = (void *)0x0035016E;
static u32 D_80800418_chclimbbase_rest[17] = { 0x1, 0x0, (u32)func_80800200_chclimbbase, (u32)func_80105834, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, (u32)func_80800128_chclimbbase, (u32)func_80107C2C, 0x80002602, 0x0, 0x0 };
