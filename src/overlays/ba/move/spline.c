#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_800D8840(s32);
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800F2168(f32 *, f32);
typedef struct { u8 pad_0[0x90]; u8 local_0; u8 local_1; u8 local_2; u8 pad_1[9]; f32 local_3[3]; f32 local_4; } MoveSplineState;
typedef struct { u8 pad_0[0xC8]; MoveSplineState *local_0; } MoveSplinePlayer;
extern void func_800C810C(void *param_0, void *param_1, void *param_2, void *param_3);
extern void func_800EFA4C(s32 param_0, float param_1, float param_2, float param_3);
typedef struct { u8 pad_0[0x90]; u8 local_0; u8 pad_1[3]; s16 local_1; u8 pad_2[2]; f32 local_2; u8 pad_3[0xC]; f32 local_3; } MoveSplineEndpoint;
extern void *func_800D7520();
extern void func_800C7A68(void *, f32, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800136E4(f32);
extern f32 mlAbsF(f32);
extern f32 func_800EEFFC();
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 bastick_getAngleRelativeToBanjo(void *);
extern void func_800EF368(f32 *, f32);
typedef struct { u8 pad0[4]; f32 unk4[3]; f32 unk10[3]; u8 pad1C[0xC]; f32 unk28[3]; u8 pad34[0x5D]; u8 unk91; u8 unk92; u8 pad93; s16 unk94; u8 pad96[2]; f32 unk98; u8 pad9C[0xC]; f32 unkA8; } SplineMove;
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngle(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 func_8009BB18(PlayerState *);
extern f32 func_800C7FD4(void *, f32, f32);
typedef struct { u8 pad_0[0x90]; u8 state; u8 pad_1[3]; s16 path; u8 pad_2[2]; f32 progress; } SplineMoveProgress;
typedef struct { u8 pad_0[0xC8]; SplineMoveProgress *data; } SplineMovePlayer;
extern f32 func_800C82CC(void *, f32 *);

void func_80800000_bamovespline(PlayerState *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];

    func_800EEB9C((f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x1C), *(f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x40), *(f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x3C));
    local_2[0] = *(f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x10);
    local_2[1] = 0.0f;
    local_2[2] = *(f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x18);
    func_800EE7F8(local_3, (f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x1C));
    local_3[1] = 0.0f;
    func_800EFA20(local_0, local_3, func_800D8840(2));
    func_800EFA20(local_1, local_2, func_800D8840(2));
    func_800EF3DC(local_0, local_1);
    func_800EF334(local_0, func_800D8FF8() * 30.0f);
    func_800EF04C((f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x10), local_0);
    func_800F2168((f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x10), 0.0001f);
}

void func_808000F4_bamovespline(PlayerState *param_0, s32 param_1)
{
    switch (param_1) {
    case 1:
        ((MoveSplinePlayer *)param_0)->local_0->local_1 = 0;
        ((MoveSplinePlayer *)param_0)->local_0->local_2 = 0;
        ((MoveSplinePlayer *)param_0)->local_0->local_4 = 0.0f;
        break;
    case 3:
        func_8009C128(param_0, ((MoveSplinePlayer *)param_0)->local_0->local_3);
        break;
    case 2:
    case 4:
        break;
    }
    ((MoveSplinePlayer *)param_0)->local_0->local_0 = param_1;
}

void bamovespline_entrypoint_0(u8 *param_0, s32 param_1) {
  s8 _sfpad[8];
  s32 pad0;
    s32 sp20;
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(param_0) + (0xC8)));
    if ((*(u8 *)((s8 *)(temp_v0) + (0x90))) == 4) {
        func_800C810C(func_800D7520((*(s16 *)((s8 *)(temp_v0) + (0x94)))), (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0x98))), param_1, &sp20);
        return;
    }
    func_800EFA4C(param_1, 0, 1.0f, 0);
}

s32 bamovespline_entrypoint_1(PlayerState *param_0, f32 param_1)
{
    void *local_2;
    f32 local_0[3];
    f32 local_1[3];

    if ((*(MoveSplineEndpoint **)((u8 *)param_0 + 0xC8))->local_0 != 4) return 0;
    if ((*(MoveSplineEndpoint **)((u8 *)param_0 + 0xC8))->local_3 >= 0.0f) return 0;
    local_2 = func_800D7520((*(MoveSplineEndpoint **)((u8 *)param_0 + 0xC8))->local_1);
    func_800C7A68(local_2, (*(MoveSplineEndpoint **)((u8 *)param_0 + 0xC8))->local_2, local_0);
    func_800C7A68(local_2, 0.0f, local_1);
    return func_800EEB40(local_0, local_1) < param_1 * param_1;
}

s32 bamovespline_entrypoint_2(s32 param_0)
{
  int new_var;
  new_var = param_0;
  new_var = new_var + 0xC8;
  return ((u8 *) (*((int **) (new_var))))[0x91];
}

s32 bamovespline_entrypoint_3(s32 param_0)
{
    return ((u8 *)((s32 *)param_0)[0x32])[0x92];
}

s32 bamovespline_entrypoint_4(u8 *param_0) {
    return (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0x90))) == 4;
}

void bamovespline_entrypoint_5(s32 arg0) 
{
}
void bamovespline_entrypoint_6(void *param_0)
{
  s32 *t6;
  *((s8 *) ((*((s32 **) (((char *) param_0) + 0xC8))) + (0x90 / 4))) = 0;
  func_808000F4_bamovespline(param_0, 1);
}

void bamovespline_entrypoint_7(void *arg, s32 v)
{
    ((s16 *)(*(void **)((char *)arg + 0xC8)))[74] = v;
}

void bamovespline_entrypoint_8(s32 arg0)
{
    func_808000F4_bamovespline(arg0,0x2);
}

void bamovespline_entrypoint_9(u8 *param_0, f32 param_1)
{
  u8 *ptr;
  ;
  *((f32 *) ((*((u8 **) (param_0 + 0xC8))) + 0x98)) = param_1;
  func_808000F4_bamovespline(param_0, 4);
}

void func_80800374_bamovespline(void *param_0)
{
    f32 local_0;
    f32 local_7;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    f32 local_4[3];
    void *local_5;
    f32 local_8;

    local_5 = func_800D7520(*(s16 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x94));
    func_800EE7F8(local_4, *(u8 **)((u8 *)param_0 + 0xC8) + 0x9C);
    func_800C7A68(local_5, *(f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x98), local_3);
    local_1 = func_800F1DF4(local_4, local_3);
    if (bastick_distance(param_0) != 0.0f) {
        local_7 = func_800F1DCC(local_1, bastick_getAngleRelativeToBanjo(param_0));
        if (mlAbsF(local_7) < 90.0f) {
            baphysics_set_target_yaw(param_0, local_1);
        } else {
            local_8 = func_800136E4(local_1 + 180.0f);
            baphysics_set_target_yaw(param_0, local_8);
        }
    }
    func_80800000_bamovespline(param_0);
    local_2 = func_800F1DCC(local_1, *(f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x40));
    *(*(u8 **)((u8 *)param_0 + 0xC8) + 0x92) = mlAbsF(local_2) > 40.0f;
    local_0 = func_800EEFFC((f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x10)) * func_800D8FF8();
    *(f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0xA8) = local_0;
    func_800EFB24(*(u8 **)((u8 *)param_0 + 0xC8) + 0x28, local_3, local_4);
    func_800EF368(*(u8 **)((u8 *)param_0 + 0xC8) + 0x28, local_0);
    if (mlAbsF(local_2) > 90.0f) {
        func_800EF334((f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x28), -1.0f);
    }
    func_800EF04C(*(u8 **)((u8 *)param_0 + 0xC8) + 4, *(u8 **)((u8 *)param_0 + 0xC8) + 0x28);
    if (func_800EEAD4(local_3, local_4) < func_800EEAD4((f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 4), local_4)) {
        func_808000F4_bamovespline(param_0, 4);
    }
}

void func_8080057C_bamovespline(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1[3];
    void *local_2;

    if (bastick_distance(param_0) != 0.0f) {
        baphysics_set_target_yaw(param_0, bastick_getAngle(param_0));
    }
    func_80800000_bamovespline(param_0);
    local_2 = func_800D7520((*(SplineMove **)((u8 *)param_0 + 0xC8))->unk94);
    func_800C7A68(local_2, (*(SplineMove **)((u8 *)param_0 + 0xC8))->unk98, local_1);
    local_0 = func_800EEFFC((*(SplineMove **)((u8 *)param_0 + 0xC8))->unk10);
    if (func_8009BB18(param_0) > 180.0f) {
        local_0 = -local_0;
    }
    (*(SplineMove **)((u8 *)param_0 + 0xC8))->unk98 = func_800C7FD4(local_2, (*(SplineMove **)((u8 *)param_0 + 0xC8))->unk98, local_0);
    (*(SplineMove **)((u8 *)param_0 + 0xC8))->unkA8 = local_0;
    (*(SplineMove **)((u8 *)param_0 + 0xC8))->unk91 = (local_0 > 0.0f) && ((*(SplineMove **)((u8 *)param_0 + 0xC8))->unk98 == 1.0f);
    (*(SplineMove **)((u8 *)param_0 + 0xC8))->unk92 = (local_0 < 0.0f) && ((*(SplineMove **)((u8 *)param_0 + 0xC8))->unk98 == 0);
    func_800C7A68(local_2, (*(SplineMove **)((u8 *)param_0 + 0xC8))->unk98, (*(SplineMove **)((u8 *)param_0 + 0xC8))->unk4);
    func_800EFB24((*(SplineMove **)((u8 *)param_0 + 0xC8))->unk28, (*(SplineMove **)((u8 *)param_0 + 0xC8))->unk4, local_1);
}

void bamovespline_entrypoint_10(PlayerState *param_0)
{
    f32 local_0[3];
    void *local_1;
    f32 local_2;
    switch (((SplineMovePlayer *)param_0)->data->state) {
        case 2:
            func_8009C128(param_0, local_0);
            local_1 = func_800D7520(((SplineMovePlayer *)param_0)->data->path);
            local_2 = func_800C82CC(local_1, local_0);
            ((SplineMovePlayer *)param_0)->data->progress = local_2;
            func_808000F4_bamovespline(param_0, 3);
            break;
        case 3: func_80800374_bamovespline(param_0); break;
        case 4: func_8080057C_bamovespline(param_0); break;
    }
}
