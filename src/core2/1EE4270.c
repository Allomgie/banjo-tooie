#include "common.h"

extern u32 func_8010A698();
extern s32 func_8010A654(void *, s32);
extern u8 D_80136F20[];
typedef struct { s32 local_0; f32 local_1, local_2; s32 local_3, local_4, local_5; u8 local_6; u8 pad[3]; void *local_7; u8 pad1[0x24]; f32 local_8[3]; s32 local_9; u8 local_10, local_11, local_12, local_13; } CollisionAAC0;
typedef struct { u8 pad[0x20]; s16 local_0; } MarkerAAC0;
typedef struct { MarkerAAC0 *local_0; f32 local_1[3]; s32 pad; s32 local_2; } ActorAAC0;
extern f32 D_80136F30[3];
extern void func_8010A624(Actor *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800D4584(CollisionAAC0 *, f32 *, f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE7F8();
extern void func_800EF410(f32 *, f32 *);
extern f32 func_800EC708(s32);
extern f32 func_8010A40C();
extern s32 func_800BF340(void *, void *, void *, s32, f32);
extern s32 func_800BF0E0(f32 *, f32 *, f32, f32 *, s32, s32);
extern s32 func_800CC6CC(s32, s32);
void func_800EF214(f32 *, f32, f32, f32);
void func_800EF1B8(f32 *, f32, f32, ...);
f32 func_8010C4AC();
typedef struct { s32 pad; f32 local_0[3]; s32 pad2; s32 local_1; u8 pad3[28]; f32 local_2; u8 pad4[86]; s16 local_3; } Actor10B1F4;
typedef struct { s32 pad[2]; s32 local_0; } Hit10B1F4;
extern f32 D_80136F40[3];
extern f32 func_800D8FF8(void);
extern f32 func_800F13F0(f32, f32);
extern Hit10B1F4 *func_800BEF00(f32 *, f32 *, f32 *, s32);
typedef struct { void *marker; f32 position[3]; void *unused10; s32 flags; u8 pad18[0x1C]; f32 vertical; u8 pad38[0x56]; s16 collision; } LocalActor_8010B330;
extern s32 *func_800C6A7C(f32 *, f32 *, f32 *, s32);
extern void func_801045AC(void *, f32 *, f32 *, s32);
typedef struct { void *marker; f32 position[3]; void *unused10; s32 flags; u8 pad18[0x1C]; f32 vertical; u8 pad38[0x56]; s16 collision; } LocalActor_8010B410;
typedef struct { s32 pad; f32 local_0[3]; s32 pad_1; s32 local_1; u8 pad_2[0x1C]; f32 local_2; u8 pad_3[0x56]; s16 local_3; } State10B514;
extern f32 func_800BED50(void *, s32);
typedef struct {u8 local_0[4]; f32 local_1[3]; u8 local_2[0x60]; u32 local_3:7; u32 local_4:15; u32 local_5:6; u32 local_6:4;} local_type;
extern s32 func_800CC338(f32 *, s32, s32);
typedef struct { u8 pad0[4]; f32 unk4[3]; u8 pad10[0x18]; f32 unk28[3]; f32 unk34; } S_10B8A4;
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
void func_800EF174(s32, s32, f32);
typedef s32 (*LocalCallback)(Actor *, f32 *, s32, s32);
extern LocalCallback *D_80124714[6];
extern void func_80104580(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 sqrtf(f32);
extern f32 func_800DC0C0(void);
extern void func_800EF368(f32 *, f32);
typedef struct { u8 pad0[4]; f32 position[3]; u8 pad10[0x28]; f32 scale; u8 pad3C[0x24]; u32 unused:16; u32 radius:16; u8 pad64[0x24]; s16 bottom, top; } LocalBoundsActor;
typedef struct { u8 pad0[0x18]; u16 flags; } LocalMarker;
typedef struct { LocalMarker *marker; f32 position[3]; u8 pad10[0x60]; u16 flags70; u8 pad72[2], flags74; } LocalActor_8010BDB0;
typedef struct { LocalMarker *marker; s32 unused; u32 flags; } LocalEntry;
extern LocalActor_8010BDB0 *func_80106790(LocalMarker *);
extern s32 func_80102F74(LocalActor_8010BDB0 *, u32);
extern void _chflamer_entrypoint_1(LocalActor_8010BDB0 *, LocalMarker *);
void func_80102844(f32 *param_0, f32 param_1, s32 param_2, s32 param_3);
extern s32 func_800F1EA4(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800EEF94(f32 *);
extern f32 func_800138D0(f32);
typedef struct { u8 pad[0x18]; u16 local_0; } Marker10C100;
typedef struct { Marker10C100 *local_0; f32 local_1[3]; u8 pad[0x60]; u16 local_2; u8 pad2[2]; u8 local_3; } Actor10C100;
typedef struct { Marker10C100 *local_0; s32 pad; u32 local_1; } Entry10C100;
extern f32 func_80103F38(Actor10C100 *, f32 *);
extern void **func_800BE3F8(f32 *);
extern Entry10C100 *func_800E9E88(void *);
extern Entry10C100 *func_800E9EB4(void *);
extern f32 func_800EEFD4(s32 *);
f32 func_800BECCC(void);
s32 func_8010108C();
void func_800FFAB0();
s32 func_8010C2D8(s32 param_0, s32 param_1, f32 param_2, Actor10C100 *param_3);
s32 func_8010C3E8();
f32 func_8010C460();

int func_8010A980(void *param_0, f32 *param_1, u32 param_2, s32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    u32 local_2;
    int local_4;
    int local_3;
    local_2 = func_8010A698(param_0);
    func_8010A624(param_0);
    local_0[0] = *(f32 *)((char *)(param_1) + 0x0);
    local_0[1] = *(f32 *)((char *)(param_1) + 0x4) + 4.0f;
    local_0[2] = *(f32 *)((char *)(param_1) + 0x8);
    local_1[0] = *(f32 *)((char *)(param_0) + 0x4);
    local_1[1] = *(f32 *)((char *)(param_0) + 8) + 4.0f;
    local_1[2] = *(f32 *)((char *)(param_0) + 12);
    local_4 = func_800C6A7C(local_0, local_1, ((u8 *) D_80136F30), *(u32 *)((char *)(param_0) + 0x14));
    func_800EE7F8(&D_80136F20, local_1);
    func_8010A654(param_0, local_2);
    return (local_4 != 0) ? 1 : 0;
}

void func_8010AA54(s32 param_0) {
    func_800EE7F8(param_0, ((u8 *) D_80136F30));
}

void func_8010AA78(s32 param_0) {
    func_800EE7F8(param_0, &D_80136F20);
}

void func_8010AA9C(s32 param_0) {
    func_800EE7F8(param_0, ((u8 *) D_80136F40));
}

s32 func_8010AAC0(Actor *param_0, f32 *param_1, s32 param_2, s32 param_3) {
    CollisionAAC0 local_0;
    f32 local_1[3];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    f32 local_6[3];
    s32 local_7;
    local_2 = func_8010A698();
    func_8010A624(param_0);
    local_0.local_2 = func_800EC708(((ActorAAC0 *)param_0)->local_0);
    local_4 = 0;
    switch (param_2 & 0xF000) {
    case 0x1000: case 0x3000: case 0x5000: case 0x6000: local_4 = 1; break;
    }
    if (local_4) {
        local_0.local_2 *= 0.6f * func_8010A40C(param_0);
        local_0.local_1 = local_0.local_2 * 1.25f < ((ActorAAC0 *)param_0)->local_0->local_0 ? ((ActorAAC0 *)param_0)->local_0->local_0 : local_0.local_2 * 1.25f;
    } else {
        local_0.local_2 *= 0.5f * func_8010A40C(param_0);
        local_0.local_1 = local_0.local_2 * 1.25f < ((ActorAAC0 *)param_0)->local_0->local_0 ? ((ActorAAC0 *)param_0)->local_0->local_0 : local_0.local_2 * 1.25f;
    }
    local_0.local_0 = 0;
    local_0.local_3 = 0;
    local_0.local_4 = 0;
    local_0.local_5 = ((ActorAAC0 *)param_0)->local_2;
    local_0.local_6 = 0;
    local_0.local_7 = 0;
    local_0.local_9 = 0;
    local_0.local_10 = 0;
    local_0.local_11 = 0;
    local_0.local_12 = 0;
    func_800EFB24(local_1, ((ActorAAC0 *)param_0)->local_1, param_1);
    func_800D4584(&local_0, param_1, ((ActorAAC0 *)param_0)->local_1, local_1);
    local_3 = local_0.local_11;
    if (local_3) {
        func_800EE7F8(D_80136F30, local_0.local_8);
        if (!local_0.local_10) {
            func_800EF410(local_6, local_1);
            if (func_800EEAA4(local_0.local_8, local_6) > (-0.9396926f)) local_3 = 0;
        }
    }
    func_8010A654(param_0, local_2);
    return local_3 ? 1 : 0;
}

int func_8010ACE0(s32 param_0[3], s32 param_1, s32 param_2, s32 param_3)
{
  u32 local_0;
  u32 local_1;
  u32 local_2;
  u32 local_3;
  local_0 = param_0[28];
  local_1 = local_0 >> 25;
  if (local_1 != 0)
  {
    local_2 = local_0 << 22;
    local_3 = local_2 >> 26;
    if (func_800CC6CC(local_1 - 1, local_3 - 1) == 0)
    {
      return 0;
    }
  }
  return func_8010AAC0(param_0, param_1, param_2, param_3);
}

s32 func_8010AD4C(u8 *param_0, u8 *param_1, s32 param_2, s32 param_3) {
    f32 local_1;
    s32 local_2;
    f32 local_0;
    local_0 = func_800EC708(*(s32 *)(param_0));
    local_1 = func_8010A40C(param_0) * (local_0 * 0.666f);
    *(f32 *)(param_1 + 4) += local_1;
    *(f32 *)(param_0 + 8) += local_1;
    local_2 = func_800BF340(param_1, param_0 + 4, ((s32 *) D_80136F30), *(s32 *)(param_0 + 0x14), local_1);
    func_800EE7F8(((s32 *) D_80136F20), param_0 + 4);
    *(f32 *)(param_1 + 4) -= local_1;
    *(f32 *)(param_0 + 8) -= local_1;
    return local_2 ? 1 : 0;
}

int func_8010AE30(s32 param_0[3], f32 *param_1, f32 *param_2, f32 *param_3)
{
  u32 local_0;
  u32 local_1;
  u32 new_var;
  local_0 = param_0[28];
  if ((local_1 = local_0 >> 25) != 0)
  {
    new_var = ((u32) local_0 << 22) >> 26;
    if (func_800CC6CC(local_1 - 1, new_var - 1) == 0)
    {
      return 0;
    }
  }
  return func_8010AD4C(param_0, param_1, param_2, param_3);
}

s32 func_8010AE9C(u8 *param_0, f32 *param_1, s32 param_2, s32 param_3) {
    f32 local_0;
    s32 local_1;
    f32 local_2;
    local_2 = func_800EC708(*(s32 *)param_0);
    local_0 = func_8010A40C(param_0) * (local_2 * 0.666f);
    param_1[1] += local_0;
    *(f32 *)(param_0 + 8) += local_0;
    local_1 = func_800BF0E0(param_1, (f32 *)(param_0 + 4), local_0, D_80136F30, 3, *(s32 *)(param_0 + 0x14));
    func_800EE7F8(((f32 *) D_80136F20), (f32 *)(param_0 + 4));
    param_1[1] -= local_0;
    *(f32 *)(param_0 + 8) -= local_0;
    return local_1 ? 1 : 0;
}

int func_8010AF8C(s32 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
  u32 local_0;
  u32 local_1;
  u32 local_2;
  u32 local_3;
  local_0 = param_0[28];
  local_1 = local_0 >> 25;
  if (local_1 != 0)
  {
    local_2 = local_0 << 22;
    local_3 = local_2 >> 26;
    if (func_800CC6CC(local_1 - 1, local_3 - 1) == 0)
    {
      return 0;
    }
  }
  return func_8010AE9C(param_0, param_1, param_2, param_3);
}







s32 func_8010AFF8(u8 *param_0, s32 param_1, s32 param_2, f32 param_3)
{
  param_3 = func_8010C4AC();
  func_800EF214((f32 *) (param_0 + 4), *((f32 *) (((char *) param_0) + 0x44)), *((f32 *) (((char *) param_0) + 0x48)), param_3);
  return 0;
}

s32 func_8010B040(u8 *param_0, s32 param_1, s32 param_2, s32 param_3) {
    func_800EF1B8((f32 *) (param_0 + 4), *(f32 *)(param_0 + 0x48), func_8010C4AC(), param_0);
    return 0;
}

s32 func_8010B088(u8 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
  extern f32 func_800D8FF8(void);
  f32 new_var;
  f32 sp18;
  new_var = func_8010C4AC();
  sp18 = new_var;
  func_800EF1B8((f32 *) (param_0 + 4), *((f32 *) (((s8 *) param_0) + 0x48)), func_800D8FF8() * sp18);
  return 0;
}

s32 func_8010B0E0(u8 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    func_800EF214((f32 *) (param_0 + 4), *((f32 *)(param_0 + 0x44)), *((f32 *)(param_0 + 0x48)), func_8010C4AC() * func_800D8FF8());
    return 0;
}

s32 func_8010B13C(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
  f32 local_0 = func_8010C4AC(arg0);
  func_800EF214(arg0 + 1, -arg0[17], arg0[18], local_0);
  return 0;
}

s32 func_8010B190(void *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    f32 local_1;
    f32 local_0;

    local_0 = func_8010C4AC(param_0);
    local_1 = func_800D8FF8();
    func_800EF214((f32 *) ((char *)param_0 + 4), -((f32 *)param_0)[0x11], ((f32 *)param_0)[0x12], local_1 * local_0);
    return 0;
}

s32 func_8010B1F4(Actor10B1F4 *param_0, s32 param_1, s32 param_2, s32 param_3) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    Hit10B1F4 *local_4;
    local_2 = func_8010C460();
    local_3 = func_800D8FF8();
    func_800EE7F8(local_0, param_0->local_0);
    local_0[1] += local_2;
    func_800EE7F8(local_1, param_0->local_0);
    local_1[1] += func_800F13F0(param_0->local_2 * local_3, -200.0f);
    local_4 = func_800BEF00(local_0, local_1, D_80136F40, param_0->local_1);
    if (local_4) {
        param_0->local_2 = 0.0f;
        func_800EE7F8(param_0->local_0, local_1);
        if (param_0->local_3) func_801045AC(param_0, D_80136F40, local_1, local_4->local_0);
        return 1;
    } else {
        param_0->local_2 -= 1200.0f * local_3;
        param_0->local_0[1] += param_0->local_2;
        if (func_8010C3E8(param_0)) return -1;
    }
    return 0;
}

s32 func_8010B330(LocalActor_8010B330 *param_0, s32 param_1, f32 *param_2, s32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    s32 *local_3;
    local_2 = func_8010C460(param_0);
    func_800EE7F8(local_0, param_0->position);
    local_0[1] += local_2;
    func_800EE7F8(local_1, param_0->position);
    local_1[1] -= 100.0f;
    local_3 = func_800C6A7C(local_0, local_1, D_80136F40, param_0->flags);
    if (local_3) {
        param_0->vertical = 0.0f;
        func_800EE7F8(param_0->position, local_1);
        if (param_0->collision) func_801045AC(param_0, D_80136F40, local_1, local_3[2]);
        return 1;
    }
    return 0;
}

s32 func_8010B410(LocalActor_8010B410 *param_0, s32 param_1, f32 *param_2, s32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    s32 *local_3;
    local_2 = func_8010C460(param_0);
    func_800EE7F8(local_0, param_0->position);
    local_0[1] += local_2;
    func_800EE7F8(local_1, param_0->position);
    local_1[1] -= 200.0f;
    local_3 = (s32 *)func_800BEF00(local_0, local_1, D_80136F40, param_0->flags);
    if (local_3) {
        if (param_0->collision) func_801045AC(param_0, D_80136F40, local_1, local_3[2]);
        if (param_0->position[1] < local_1[1]) {
            param_0->position[1] = local_1[1] + 1.0f;
            return 1;
        }
    }
    if (func_8010C3E8(param_0)) return -1;
    return 0;
}

s32 func_8010B514(State10B514 *param_0, s32 param_1, s32 param_2, s32 param_3) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    s32 local_4;
    local_2 = func_8010C460(param_0);
    local_3 = func_800D8FF8();
    func_800EE7F8(local_0, param_0->local_0);
    local_0[1] += local_2;
    func_800EE7F8(local_1, param_0->local_0);
    local_1[1] += func_800F13F0(param_0->local_2 * local_3, -200.0f);
    param_0->local_2 -= 300.0f * local_3;
    local_4 = func_800BEF00(local_0, local_1, D_80136F40, param_0->local_1);
    if (local_4) {
        param_0->local_0[1] += param_0->local_2;
        if (func_8010C3E8(param_0)) return -1;
        param_0->local_2 = 0.0f;
        if (param_0->local_0[1] < local_1[1]) {
            param_0->local_2 = -50.0f;
            param_0->local_0[1] = local_1[1];
        }
        if (param_0->local_3) func_801045AC(param_0, D_80136F40, local_1, *(s32 *)(local_4 + 8));
        return 1;
    } else {
        param_0->local_0[1] += param_0->local_2;
        if (func_8010C3E8(param_0)) return -1;
        return 0;
    }
}

s32 func_8010B69C(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    f32 local_0 = func_800BED50((void *)((s32)param_0 + 4), param_0) - 130.0f;
    f32 local_1 = *(f32 *)((char *)param_0 + 8);
    if (local_1 < local_0) {
        *(f32 *)((char *)param_0 + 8) = local_1;
    } else {
        *(f32 *)((char *)param_0 + 8) = local_0;
    }
    return (local_0 == *(f32 *)((char *)param_0 + 8));
}

int func_8010B71C(u8 *param_0, s32 param_1, s32 param_2, s32 param_3) {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    u8 *local_3;
    local_1 = func_8010C460(param_0);
    local_2 = func_800D8FF8();
    local_0[0] = *(f32 *)(param_0 + 4);
    local_0[1] = *(f32 *)(param_0 + 8) + local_1;
    local_0[2] = *(f32 *)(param_0 + 12);
    *(f32 *)(param_0 + 8) += *(f32 *)(param_0 + 0x2C) * local_2;
    local_3 = func_800BEF00(local_0, (f32 *)(param_0 + 4), D_80136F40, *(s32 *)(param_0 + 0x14));
    if (local_3) {
        *(f32 *)(param_0 + 0x2C) = 0.0f;
        *(f32 *)(param_0 + 0x34) = 0.0f;
        if (*(s16 *)(param_0 + 0x8E)) func_801045AC(param_0, D_80136F40, (f32 *)(param_0 + 4), *(s32 *)(local_3 + 8));
        return 1;
    }
    *(f32 *)(param_0 + 0x2C) -= *(f32 *)(param_0 + 0x34) * local_2;
    return 0;
}

int func_8010B800(local_type *param_0, f32 *param_1, s32 param_2, s32 param_3) {
    s32 local_0;
    if (param_0->local_3) {
        local_0 = func_800CC338(param_0->local_1, param_0->local_3 - 1, param_0->local_5 - 1);
        if (local_0 == -1) {
            func_800EE7F8(param_0->local_1, param_1);
            return 1;
        }
        param_0->local_5 = local_0 + 1;
        return 0;
    }
    return 0;
}

s32 func_8010B8A4(S_10B8A4 *param_0, s32 param_1, s32 param_2, s32 param_3) {
    f32 t;
    f32 sp18[3];
    t = func_800D8FF8();
    param_0->unk28[1] = param_0->unk28[1] + (param_0->unk34 * t);
    func_800EFA20(sp18, param_0->unk28, t);
    func_800EF04C(param_0->unk4, sp18);
    return 0;
}

int func_8010B910(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  int new_var;
  int new_var3;
  u8 *local_0;
  u8 *new_var2;
  new_var = 4;
  new_var3 = 0x28;
  new_var3 = new_var3;
  local_0 = new_var + param_0;
  new_var2 = local_0;
  new_var = new_var3;
  new_var3 = 0 & 0xFFFFFFFFFFFFFFFFu;
  func_800EF04C(new_var2, (param_0 + new_var) + new_var3);
  return (((new_var3 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & (0xFFFFFFFFFFFFFFFFu ^ 0)) & 0xFFFFFFFFFFFFFFFFu;
}

s32 func_8010B94C(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  func_800EF174(param_0 + 4, param_0 + 0x28, func_800D8FF8());
  return 0;
}

s32 func_8010B990(Actor *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_3;
    f32 local_2[3];
    s32 local_4;
    local_1 = 0;
    func_80104580();
    func_800EE7F8(local_2, param_0->position);
    for (local_0 = 0; local_0 < 6; local_0++) {
        local_3 = ((u32)param_1 >> (local_0 << 2)) & 0xF;
        if (local_3) {
            local_4 = D_80124714[local_0][local_3](param_0, local_2, param_1, local_1);
            if (local_4 == -1) return 0;
            if (local_4) local_1 |= local_4 << local_0;
        }
    }
    return local_1;
}

s32 func_8010BA80(s32 param_0, s32 param_1, s32 param_2)
{
    s32 temp_v0;
    s32 var_v1;
    s32 sp2C;
    s32 sp20;

    func_800EE7F8(&sp20, param_0 + 4);
    temp_v0 = func_8010B990(param_0, param_1);
    var_v1 = temp_v0;
    if (temp_v0 & param_2) {
        sp2C = temp_v0;
        func_800EE7F8(param_0 + 4, &sp20);
        var_v1 = sp2C;
    }
    return var_v1;
}

s32 func_8010BAEC(s32 param_0, s32 param_1, s32 param_2)
{
  s32 var_v1;
  s32 sp28;
  s32 sp2C;
  s32 sp20;
  func_800EE7F8(&sp20, param_0 + 4);
  var_v1 = func_8010B990(param_0, param_1);
 do { sp28 = var_v1 & param_2; do { } while (0); if (sp28 != param_2) { func_800EE7F8(param_0 + 4, &sp20); } return var_v1; } while (0);
}

s32 func_8010BB5C(s32 param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4, f32 param_5) {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3;
    if (param_1[1] < param_2[1] + param_4) return 0;
    if (param_2[1] + param_3 < param_1[1]) return 0;
    func_800EFA4C(local_0, param_1[0] - param_2[0], 0.0f, param_1[2] - param_2[2]);
    local_1 = local_0[0] * local_0[0] + local_0[1] * local_0[1] + local_0[2] * local_0[2];
    if (param_5 * param_5 < local_1) return 0;
    local_1 = sqrtf(local_1);
    local_3 = func_800F13F0(func_800D8FF8() * 400.0f, param_5 - local_1);
    if (local_1 == 0.0f) {
        local_1 = func_800DC0C0();
        func_800EFA4C(local_0, local_1, 0.0f, func_800DC0C0());
    }
    func_800EF368(local_0, local_3);
    func_800EF04C(param_1, local_0);
    return 1;
}

s32 func_8010BCC8(LocalBoundsActor *param_0, f32 *param_1, LocalBoundsActor *param_2)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    if (!param_2->radius) return 0;
    func_800EE7F8(local_0, param_2->position);
    local_0[1] += param_2->scale * param_0->bottom;
    local_1 = (param_0->top - param_0->bottom) * param_2->scale;
    local_2 = func_8010A40C(param_0);
    local_2 *= param_2->radius * param_2->scale;
    return func_8010BB5C(param_0, param_1, local_0, local_1, -30.0f, local_2);
}

s32 func_8010BDB0(LocalActor_8010BDB0 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    void **local_0;
    LocalEntry *local_1;
    LocalEntry *local_2;
    LocalMarker *local_3;
    LocalActor_8010BDB0 *local_4;
    f32 *local_5;
    local_5 = param_0->position;
    for (local_0 = func_800BE3F8(local_5); *local_0; local_0++) {
        local_1 = func_800E9E88(*local_0);
        local_2 = func_800E9EB4(*local_0);
        for (; local_1 < local_2; local_1++) {
            if (!(local_1->flags & 1)) continue;
            local_3 = local_1->marker;
            if (!(local_3->flags & 1) || local_3 == param_0->marker) continue;
            local_4 = func_80106790(local_3);
            if (!(local_4->flags70 & 1) || !func_8010BCC8(param_0, local_5, local_4)) continue;
            if ((local_4->flags74 & 1) && !(param_0->flags74 & 1) && func_80102F74(param_0, 0x80020000)) {
                _chflamer_entrypoint_1(param_0, local_3);
            }
            if (!(local_4->flags74 & 1) && (param_0->flags74 & 1) && func_80102F74(local_4, 0x80020000)) {
                _chflamer_entrypoint_1(local_4, param_0->marker);
            }
            return 1;
        }
    }
    return 0;
}

void func_8010BF4C(f32 *param_0, s32 param_1, f32 param_2, s32 param_3, s32 param_4) {
    (*(f32 *)((char *)param_0 + 0x24)) = param_2;
    func_80102844(param_0, (f32)param_3, -1, param_1);
    func_8010B990(param_0, param_4);
}

s32 func_8010BFA4(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3)
{
    f32 local_5;
    f32 local_6;
    f32 local_0;
    f32 local_1;
    f32 local_2[3];
    f32 local_3;
    f32 local_7;
    f32 local_4;
    func_800EFB24(local_2, param_0, param_1);
    if (!func_800F1EA4(local_2, &local_1)) {
        func_800EE7F8(param_0, param_1);
        return 0;
    }
    local_3 = param_1[1];
    local_5 = func_800F1DF4(param_1, param_2);
    local_0 = func_800F1DCC(local_1, local_5);
    func_800EE7F8(param_0, param_2);
    func_800EF1B8(param_0, local_5 + 180.0f, param_3 + 2.0f);
    local_6 = local_0 > 0.0f ? 90.0f : -90.0f;
    local_5 = func_800136E4(local_5 + local_6);
    local_4 = func_800EEF94(local_2);
    local_7 = func_800F1DCC(local_1, local_5);
    local_6 = func_800138D0(local_7);
    func_800EF1B8(param_0, local_5, local_6 * local_4);
    param_0[1] = local_3;
    return 1;
}

s32 func_8010C100(Actor10C100 *param_0, s32 param_1, s32 param_2, s32 param_3) {
    f32 local_0[3];
    f32 local_3;
    Entry10C100 *local_4, *local_5;
    Marker10C100 *local_6;
    Actor10C100 *local_7;
    void **local_8;
    f32 local_2;
    local_2 = func_80103F38(param_0, local_0);
    local_3 = func_8010A40C(param_0) * (0.7f * local_2);
    for (local_8 = func_800BE3F8(param_0->local_1); *local_8; local_8++) {
        local_4 = func_800E9E88(*local_8);
        local_5 = func_800E9EB4(*local_8);
        for (; local_4 < local_5; local_4++) {
            if (!(local_4->local_1 & 1)) continue;
            local_6 = local_4->local_0;
            if (!(local_6->local_0 & 1) || local_6 == param_0->local_0) continue;
            local_7 = func_80106790(local_6);
            if ((local_7->local_2 & 1) && func_8010C2D8(param_0, local_0, local_3, local_7)) {
                if ((local_7->local_3 & 1) && !(param_0->local_3 & 1)) {
                    if (func_80102F74(param_0, 0x80020000)) _chflamer_entrypoint_1(param_0, local_6);
                }
                if (!(local_7->local_3 & 1) && (param_0->local_3 & 1)) {
                    if (func_80102F74(local_7, 0x80020000)) _chflamer_entrypoint_1(local_7, param_0->local_0);
                }
                return 1;
            }
        }
    }
    return 0;
}

s32 func_8010C2D8(s32 param_0, s32 param_1, f32 param_2, Actor10C100 *param_3) {
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;
    f32 temp_f0;

    sp24 = func_80103F38(param_3, sp34) * func_8010A40C(param_3);
    func_800EFB24(sp28, (f32 *) param_1, sp34);
    temp_f0 = func_800EEFD4((s32 *) sp28);
    if (temp_f0 < ((sp24 + param_2) * (sp24 + param_2))) {
        func_800EF368(sp28, ((sp24 + param_2) + 4.0f) - sqrtf(temp_f0));
        func_800EF04C((f32 *) (param_0 + 4), sp28);
        return 1;
    }
    return 0;
}

int func_8010C3A8(f32 param_0[3], f32 param_1[3], f32 param_2)
{
  f32 local_1;
  f32 local_0;
  local_0 = param_0[9];
  param_0[9] *= param_2;
  func_8010B990(param_0, param_1);
  param_0[9] = local_0;
}

s32 func_8010C3E8(param_0) u8 * param_0; {
    f32 var_f0 = func_800BECCC();
    f32 diff = var_f0 - 1000.0f;
    if (*((f32 *)(param_0 + 8)) < diff) {
        *(f32 *)(param_0 + 8) = diff;
        if (func_8010108C(param_0, 0x4D, 1) > 0) {
            return 0;
        }
        func_800FFAB0(param_0);
        return 1;
    }
    return 0;
}

f32 func_8010C460(param_0) s32 param_0; {
    f32 local_0;
    f32 local_1;
    local_0 = func_80103F38(param_0, 0) * 0.666f;
    local_1 = local_0;
    local_0 = 60.0f;
    if (local_1 < local_0) return local_0;
    return local_1;
}

f32 func_8010C4AC(param_0) u8 * param_0; {
    if (func_800D3E40(8) != 0) {
        return (*(f32 *)((s8 *)(param_0) + (0x24))) * 1.5f;
    }
    return (*(f32 *)((s8 *)(param_0) + (0x24)));
}
