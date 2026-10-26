#include "common.h"
#include "playerstate.h"

#define DRONE_TRANSITION_VIEW_DEFINED
extern u8 D_80800630_badrone[];
typedef struct { u8 pad_0; u8 unk1; u8 pad_2[6]; f32 unk8; f32 unkC; f32 unk10[3]; } DroneTransition;
typedef struct { u8 pad_0[0x54]; DroneTransition *unk54; } DronePlayerView;
extern void func_800EE7F8();
extern s32 _badata_entrypoint_21();
extern void bs_setState(void *, s32);
extern void func_8009C128(s32, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEFFC(f32 *);
extern void _badata_entrypoint_23();
typedef struct { u8 pad0[0x54]; void* unk54; } Badrones;
extern void baflag_clear(s32, s32);

s32 badrone_entrypoint_0() 
{
    return 0x4C;
}

u8 badrone_entrypoint_1(u8 *param_0)
{
  return D_80800630_badrone[**(u8 **)(param_0 + 0x54)];
}

void badrone_entrypoint_2(s32 param_0, s32 param_1) {
    func_800EE7F8(param_1, *(s32 *)(param_0 + 0x54) + 0x24);
}

u8 badrone_entrypoint_3(s32 param_0) {
    return *(*(u8 **)(param_0 + 0x54));
}

void badrone_entrypoint_4(u8 *param_0) {
    u8 *temp_v0;

    temp_v0 = *(u8 **)(param_0 + 0x54);
    *(u8 *)(temp_v0 + 0) = *(u8 *)(temp_v0 + 1);
}

void badrone_entrypoint_5(u8 *param_0) {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (4))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (5))) = 1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (8))) = 1.0f;
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0x54))) + 0x10, param_0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (0xC))) = 1.0f;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (0x1C))) = 0;
}

void badrone_entrypoint_6(u8 *param_0) {
    s32 (*local_1)(s32, s32, u8 *);
    u8 *local_0;

    local_0 = (*(u8 **)((s8 *)(param_0) + (0x54)));
    local_1 = (*(s32 (**)(s32, s32, u8 *))((s8 *)(local_0) + (0x1C)));
    if (local_1 != NULL) {
        local_1((*(s32 *)((s8 *)(local_0) + (0x20))), (*(s32 *)((s8 *)(param_0) + (0x184))), param_0);
    }
}

s32 badrone_entrypoint_7(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x54)))[4];
}

void badrone_entrypoint_8(u8 *param_0, s32 param_1, f32 *param_2, f32 *param_3) {
    func_800EE7F8(param_1, (*(u8 **)((s8 *)(param_0) + (0x54))) + 0x10);
    *param_2 = (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (8)));
    *param_3 = (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (0xC)));
}

s32 badrone_entrypoint_9(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x54)))[5];
}

void badrone_entrypoint_10(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x54)))[4] = v;
}

void badrone_entrypoint_11(u8 *param_0, s32 param_1, s32 param_2) {
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (0x1C))) = param_1;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (0x20))) = param_2;
}

void badrone_entrypoint_12(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x54)))[5] = v;
}

void badrone_entrypoint_13(u8 *param_0, s32 param_1) {
    func_800EE7F8((*(u8 **)((s8 *)(param_0) + (0x54))) + 0x10);
    if ((*(*(u8 **)((s8 *)(param_0) + (0x54))) == 1) && (func_8009BAF4(param_0) == 0xC)) {
        _bamovegoto_entrypoint_12(param_0, param_1);
    }
}

void badrone_entrypoint_14(DronePlayerView *param_0, f32 param_1[3], f32 param_2)
{
    func_800EE7F8(param_0->unk54->unk10, param_1);
    param_0->unk54->unkC = param_2;
    param_0->unk54->unk8 = 0.0f;
    param_0->unk54->unk1 = 1;
    bs_setState(param_0, _badata_entrypoint_21(param_0));
}

void badrone_entrypoint_15(DronePlayerView *param_0, f32 param_1[3], f32 param_2)
{
    func_800EE7F8(param_0->unk54->unk10, param_1);
    param_0->unk54->unk8 = param_2;
    param_0->unk54->unkC = 0.0f;
    param_0->unk54->unk1 = 1;
    bs_setState(param_0, _badata_entrypoint_21(param_0));
}

void badrone_entrypoint_16(s32 param_0, f32 *param_1, f32 param_2) {
    f32 local_0[3];
    f32 local_1[3];
    func_8009C128(param_0, local_0);
    func_800EFB24(local_1, param_1, local_0);
    badrone_entrypoint_15(param_0, param_1, func_800EEFFC(local_1) / param_2);
}

int func_80800348_badrone(void *param_0, s32 param_1)
{
  *(u8 *)(*(s32 *)((char *)param_0 + 0x54) + 0x1) = param_1;
  _badata_entrypoint_21();
}

void badrone_entrypoint_17(s32 param_0) {
    *(u8 *)(*(s32 *)(param_0 + 0x54) + 1) = 7;
    _badata_entrypoint_23(param_0);
}

s32 badrone_entrypoint_18(u8 *param_0, s32 param_1) {
    *(s32 *)(*(u8 **)(param_0 + 0x54) + 0x48) = param_1;
    return func_80800348_badrone(param_0, 12);
}

void badrone_entrypoint_19(s32 arg0)
{
    func_80800348_badrone(arg0,0xD);
}

void badrone_entrypoint_20(u8 *param_0, s32 param_1, s32 param_2) {
    (*(u8 **)(param_0 + 0x54))[0x30] = param_2;
    func_800EE7F8(*(u8 **)(param_0 + 0x54) + 0x34, param_1);
    func_80800348_badrone(param_0, 8);
}

void badrone_entrypoint_21(u8 *param_0) {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (1))) = 0xF;
    _badata_entrypoint_22();
}

void badrone_entrypoint_22(Actor *param_0)
{
    func_800EE7F8(*(s32 *)&param_0->unk54 + 0x34);
    func_80800348_badrone(param_0, 0xb);
}

void badrone_entrypoint_23(Badrones *param_0)
{
  func_800EE7F8((void*)((char*)param_0->unk54 + 0x34));
  func_80800348_badrone(param_0, 0xa);
}

void badrone_entrypoint_24(s32 arg0)
{
    func_80800348_badrone(arg0,0x2);
}

void badrone_entrypoint_25(s32 arg0)
{
    func_80800348_badrone(arg0,0x9);
}

void badrone_entrypoint_26(u8 *param_0) {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (1))) = 3;
    _badata_entrypoint_23();
}

void badrone_entrypoint_27(s32 arg0)
{
    func_80800348_badrone(arg0,0x6);
}

void badrone_entrypoint_28(s32 param_0) {
    baflag_clear(param_0, 0x19);
    func_80800348_badrone(param_0, 0x4);
}

void badrone_entrypoint_29(s32 arg0)
{
    func_80800348_badrone(arg0,0xE);
}

int badrone_entrypoint_30(PlayerState *param_0)
{
    return badrone_entrypoint_3(param_0) == 2 && !player_inWater(param_0);
}

int badrone_entrypoint_31(s32 param_0)
{
    if ((*(u8 **)(param_0 + 0x54))[0] == 1) {
        return 1;
    }
    return 0;
}

void badrone_entrypoint_32(u8 *param_0) {
    u8 *local_0;

    (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x54)))) + (1))) = 0U;
    local_0 = (*(u8 **)((s8 *)(param_0) + (0x54)));
    (*(u8 *)((s8 *)(local_0) + (0))) = (u8) (*(u8 *)((s8 *)(local_0) + (1)));
}

void badrone_entrypoint_33(void *param_0)
{
    func_800EE7F8(*(int *)((char *)param_0 + 0x54) + 0x24);
}
