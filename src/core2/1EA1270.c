#include "core2/1EA1270.h"

extern void _mlspline_entrypoint_6(void);
extern void _mlspline_entrypoint_7(void);
extern void _mlspline_entrypoint_8(void);
extern void _mlspline_entrypoint_10(void);
extern u8 _mlspline_entrypoint_0[];
extern u8 _mlspline_entrypoint_5[];
extern u8 _mlspline_entrypoint_4[];
extern u8 _mlspline_entrypoint_2[];
extern f32 _mlspline_entrypoint_13(s32, s32 *, f32, f32, f32, s32);
typedef struct { s16 pad; u8 local_0; u8 pad1[0x11]; f32 local_1[1][3]; } PathC7BCC;
typedef struct { s16 local_0; u8 local_1, pad[9]; f32 local_2; s32 local_3; f32 local_4[1][3]; } LocalSpline;
extern float func_800D8FF8(void);
extern float _glintrosyncDll_entrypoint_5(void);
typedef void (*FN_C810C)(f32, u8, void *, f32 *);
extern void func_800F1A88(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern void func_800EF2A0(f32 *);
extern f32 func_800F0E00(f32,f32);
extern f32 func_800F13F0(f32,f32);
extern f32 func_800EEB40(f32 *, f32 *);
void (*func_800C79EC(Unk800C7A68 *))(f32, u8, s32 *, s32);

FN_C810C func_800C7980(param_0) u8 * param_0;
{
  short local_0;
  void *new_var2;
  u8 local_1;
  unsigned short new_var;
  local_0 = param_0[2];
  new_var = (local_1 = param_0[3]);
  if (local_0 < 2)
  {
    return 0;
  }
  if (local_0 == 2)
  {
    return _mlspline_entrypoint_6;
  }
  if (((unsigned long) local_0) == 3)
  {
    return _mlspline_entrypoint_7;
  }
  if (local_1 == 1)
  {
    return _mlspline_entrypoint_10;
  }
  return _mlspline_entrypoint_8;
}

void (*func_800C79EC(Unk800C7A68 *param_0))(f32, u8, s32 *, s32)
{
  u8 local_1;
  short local_0;
  local_0 = *((u8 *) (((char *) param_0) + 2));
  local_1 = *((u8 *) (((char *) param_0) + 3));
  if (local_0 < 2)
  {
    return 0;
  }
  if (local_0 == 2)
  {
    return (void (*)(f32, u8, s32 *, s32)) _mlspline_entrypoint_0;
  }
  if (local_0 == 3)
  {
    return (void (*)(f32, u8, s32 *, s32)) _mlspline_entrypoint_2;
  }
  if (local_1 == 1)
  {
    return (void (*)(f32, u8, s32 *, s32)) _mlspline_entrypoint_5;
  }
  return (void (*)(f32, u8, s32 *, s32)) _mlspline_entrypoint_4;
}

void func_800C7A58(void) {
}

void func_800C7A60(void) {
}

void func_800C7A68(Unk800C7A68* arg0, f32 arg1, f32 *arg2) {
    if (arg1 < 0.0f) {
        arg1 = 0.0f;
    } else if (arg1 > 1.0f) {
        arg1 = 1.0f;
    }

    func_800C79EC(arg0)(arg1, arg0->unk2, &arg0->unk14, arg2);
}

void func_800C7AE4(u8 *param_0, s32 param_1, s32 param_2) {
    _mlspline_entrypoint_11((*(u8 *)((s8 *)(param_0) + (2))), param_0 + 0x14, param_1, param_2, func_800C7980());
}

int func_800C7B28(s32 param_0, s32 param_1, s32 param_2, volatile int param_3)
{
  int new_var;
  u32 local_0;
  local_0 = func_800C7980();
  new_var = *(u8 *)(param_0 + 2);
  _mlspline_entrypoint_12(new_var, param_0 + 0x14, param_1, param_2, param_3 << 1, local_0);
}

f32 func_800C7B7C(Unk800C7A68 *param_0, f32 param_1, f32 param_2, f32 param_3) {
    return _mlspline_entrypoint_13(param_0->unk2, &param_0->unk14, param_1, param_2, 0.0f, func_800C7980());
}

f32 func_800C7BCC(PathC7BCC *param_0, f32 *param_1) {
    f32 (*local_0)[3];
    f32 (*local_1)[3];
    s32 local_2;
    s32 local_3;
    local_3 = param_0->local_0;
    local_0 = param_0->local_1;
    local_1 = local_3 + param_0->local_1;
    local_2 = 0;
    for (; local_0 != local_1; local_0++) {
        if ((*local_0)[0] == param_1[0] && (*local_0)[1] == param_1[1] && (*local_0)[2] == param_1[2]) {
            return (f32)local_2 / (local_3 - 1);
        }
        local_2++;
    }
    return -1.0f;
}

f32 func_800C7E28(LocalSpline *param_0)
{
    s32 local_0;
    s32 local_1;
    f32 (*local_2)[3];
    f32 (*local_3)[3];
    local_0 = param_0->local_1;
    local_2 = param_0->local_4;
    local_3 = local_2 + local_0 - 1;
    for (local_1 = 0; local_2 != local_3; local_2++, local_1++) {
        if ((*local_2)[0] == (*local_3)[0] && (*local_2)[1] == (*local_3)[1] && (*local_2)[2] == (*local_3)[2]) {
            return param_0->local_2 = (f32)local_1 / (f32)(local_0 - 1);
        }
    }
    return param_0->local_2 = 1.0f;
}

f32 func_800C7FD4(unsigned char *param_0, f32 param_1, float param_2) {
    int sp34;
    float sp30;
    float sp2c;
    int sp28;

    if ((*(unsigned char *)((signed char *)(param_0) + 4)) != 0) {
        sp2c = _glintrosyncDll_entrypoint_5();
    } else {
        sp2c = func_800D8FF8();
    }
    sp30 = func_800C7E28(param_0);
    return _mlspline_entrypoint_13((*(unsigned char *)((signed char *)(param_0) + 2)), (s32 *) (param_0 + 0x14), param_1, sp2c * param_2, sp30, (s32) func_800C7980(param_0));
}

f32 func_800C8070(f32 param_0[3], f32 param_1, f32 param_2, s32 *param_3) {
    f32 f = func_800C7FD4(param_0, param_1, param_2);
    *param_3 = 0;
    if (param_2 > 0.0f) {
        if (f < param_1) {
            *param_3 = 1;
        }
    } else if (param_2 < 0.0f) {
        if (f > param_1) {
            *param_3 = 1;
        }
    }
    return f;
}

void func_800C810C(void *param_0, f32 param_1, f32 *param_2, f32 *param_3) {
    FN_C810C f = func_800C7980(param_0);
    f(param_1, *(u8 *)((u8 *)param_0 + 2), (u8 *)param_0 + 0x14, param_2);
    func_800F1A88(param_2, param_3);
    param_3[0] = func_800136E4(param_3[0]);
    param_3[1] = func_800136E4(param_3[1] + 180.0f);
    param_3[2] = 0.0f;
    func_800EF2A0(param_2);
}

f32 func_800C8198(Unk800C7A68 *param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4)
{
    /* HEADER DEPENDENCY: also push data/header/include/core2/1EA1270.h and
     * data/header/matched/core2/1EA1270.c; func_800C7A68 takes an f32 * output vector. */
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    param_2 = func_800F0E00(0.0f, param_2);
    param_3 = func_800F13F0(1.0f, param_3);
    local_4 = 1e+08f;
    local_5 = param_2;
    local_2 = param_2;
    while (1) {
        func_800C7A68(param_0, local_2, local_1);
        func_800EFB24(local_0, param_1, local_1);
        local_6 = local_0[0]*local_0[0] + local_0[1]*local_0[1] + local_0[2]*local_0[2];
        if (local_6 < local_4) { local_4 = local_6; local_5 = local_2; }
        if (local_2 == param_3) break;
        local_2 += param_4;
        if (local_2 > param_3) local_2 = param_3;
    }
    return local_5;
}

f32 func_800C82CC(Unk800C7A68 *param_0, f32 *param_1)
{
    /* HEADER DEPENDENCY: also push data/header/include/core2/1EA1270.h and
     * data/header/matched/core2/1EA1270.c; func_800C7A68 takes an f32 * output vector. */
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4[3];
    f32 local_5[3];
    local_0 = func_800C7BCC(param_0, param_1);
    if (0 <= local_0) return local_0;
    local_1 = 0.01f;
    local_0 = func_800C8198(param_0, param_1, 0.0f, 1.0f, local_1);
    local_2 = local_0 - local_1;
    local_3 = local_0 + local_1;
    local_1 = local_1 / 10.0f + local_1 / 10.0f;
    local_0 = func_800C8198(param_0, param_1, local_2, local_3, local_1);
    local_2 = local_0 - local_1;
    local_3 = local_0 + local_1;
    local_1 = local_1 / 10.0f + local_1 / 10.0f;
    local_0 = func_800C8198(param_0, param_1, local_2, local_3, local_1);
    local_2 = local_0 - local_1;
    local_3 = local_0 + local_1;
    local_1 = local_1 / 10.0f + local_1 / 10.0f;
    local_0 = func_800C8198(param_0, param_1, local_2, local_3, local_1);
    local_2 = local_0 - local_1;
    local_3 = local_0 + local_1;
    local_1 = local_1 / 10.0f + local_1 / 10.0f;
    local_0 = func_800C8198(param_0, param_1, local_2, local_3, local_1);
    local_2 = local_0 - local_1;
    local_3 = local_0 + local_1;
    local_1 = local_1 / 10.0f + local_1 / 10.0f;
    local_0 = func_800C8198(param_0, param_1, local_2, local_3, local_1);
    func_800C7A68(param_0, local_0, local_4);
    func_800C7A68(param_0, 1.0f, local_5);
    if (func_800EEB40(param_1, local_4) < func_800EEB40(param_1, local_5)) return local_0;
    return 1.0f;
}

void func_800C84A4(u8 *param_0, int param_1)
{
  volatile short pad;
  *((s8 *) (((s8 *) param_0) + 3)) = param_1;
}
