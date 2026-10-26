#include "common.h"

extern void func_800EE84C();
extern void **func_800BDD24(s32 *);
extern int B_80800EB0_gccubesearch[];
extern s32 func_800EEB40;
extern s32 func_800EFC7C;
void func_800BE554();
void func_800BD64C(s32 *, f32 *);
extern void *func_800BDAD4(s32 *);
extern void *func_800E9D68(void *);
extern void *func_800E9D90(void *);
typedef struct Mass46CubeCoords { s32 local_0; s32 local_1; s32 local_2; } Mass46CubeCoords;
extern void *func_800E9BF4(void *, s32);
extern void func_800EFD24(f32 *);
extern void func_800EE7F8(f32 *, f32 *);
s32 gccubesearch_entrypoint_7();
s32 gccubesearch_entrypoint_8();
s32 gccubesearch_entrypoint_14();
s32 func_80800590_gccubesearch();

int gccubesearch_entrypoint_0(s32 param_0, f32 *param_1)
{
  s32 local_0[3];
  if (param_1 != 0)
  {
    local_0[0] = param_1[1];
    local_0[1] = param_1[2];
    local_0[2] = param_1[3];
  }
  gccubesearch_entrypoint_14(param_0, (param_1 == 0) ? (0) : (local_0));
}

s32 gccubesearch_entrypoint_1(s32 param_0, f32 param_1[3]) {
    s32 local_0[3];

    local_0[0] = (s32)param_1[0];
    local_0[1] = (s32)param_1[1];
    local_0[2] = (s32)param_1[2];
    return gccubesearch_entrypoint_14(param_0, local_0);
}

int gccubesearch_entrypoint_2(OSIoMesg *param_0, OSIoMesg *param_1)
{
  s16 local_0[3];
  int local_1;
  if ((local_1 = gccubesearch_entrypoint_14(param_0, 0)) != 0)
  {
    *(s32*)((char*)param_1 + 0x0) = *(s16*)((char*)local_1 + 0x0);
    *(s32*)((char*)param_1 + 0x4) = *(s16*)((char*)local_1 + 0x2);
    *(s32*)((char*)param_1 + 0x8) = *(s16*)((char*)local_1 + 0x4);
    return 1;
  }
  return 0;
}

s32 gccubesearch_entrypoint_3(s32 param_0, f32 param_1[3]) {
    
    f32 local_0[3];

    if (!gccubesearch_entrypoint_2(param_0, local_0)) {
        return 0;
    }
    func_800EE84C(param_1, local_0);
    return 1;
}

s32 func_80800160_gccubesearch(s32 param_0, s32 param_1, s32 param_2){
    return param_0 * param_0 + param_1 * param_1 + param_2 * param_2;
}

s16 *gccubesearch_entrypoint_4(s32 param_0, f32 *param_1, s32 param_2)
{
    s32 local_2;
    s16 *local_0[40];
    s32 local_3 = 0x7FFFFFFF;
    s16 *local_4 = NULL;
    s32 local_5;
    s32 local_6;
    s16 local_1[3];
    local_1[0] = (s32)param_1[0];
    local_1[1] = (s32)param_1[1];
    local_1[2] = (s32)param_1[2];
    if (!param_2) local_5 = gccubesearch_entrypoint_7(param_0, local_0, 40, param_1);
    else local_5 = gccubesearch_entrypoint_8(param_0, local_0, 40, param_1);
    if (!local_5) return NULL;
    for (local_2 = 0; local_2 < local_5; local_2++) {
        local_6 = func_80800160_gccubesearch(local_1[0] - local_0[local_2][0], local_1[1] - local_0[local_2][1], local_1[2] - local_0[local_2][2]);
        if (local_6 < local_3) {
            local_3 = local_6;
            local_4 = local_0[local_2];
        }
    }
    return local_4;
}

void gccubesearch_entrypoint_5(s32 p0, s32 p1) {
    gccubesearch_entrypoint_4(p0, p1, 0);
}

void gccubesearch_entrypoint_6(s32 arg0,s32 arg1)
{
    gccubesearch_entrypoint_4(arg0,arg1,0x1);
}

s32 gccubesearch_entrypoint_7(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    s32 var_s0;
    u32 sp30;
    u32 sp2C;

    var_s0 = 0;
    func_800BE52C(&sp30, &sp2C);
    if (sp30 < sp2C) {
        do {
            var_s0 += _gspropmarker_entrypoint_1(sp30, param_0, (var_s0 * 4) + param_1, param_2 - var_s0);
            sp30 += 8;
        } while (sp30 < sp2C);
    }
    return var_s0;
}

s32 gccubesearch_entrypoint_8(param_0, param_1, param_2, param_3) void *param_0; void **param_1; s32 param_2; f32 *param_3;
{
    void **local_1;
    s32 local_3;
    s32 local_0[3];

    local_3 = 0;
    func_800EE904(local_0, param_3);
    local_1 = func_800BDD24(local_0);
    for (; *local_1; local_1++) {
        local_3 += _gspropmarker_entrypoint_1(*local_1, param_0, param_1 + local_3, param_2 - local_3);
    }
    return local_3;
}

int gccubesearch_entrypoint_9(param_0) s32 param_0;
{
  s32 sp18[2];
  sp18[0] = param_0;
  sp18[1] = -1;
  gccubesearch_entrypoint_7(sp18);
}

int gccubesearch_entrypoint_10(int param_0, int param_1)
{
  int local_0;
  int local_1;
  int local_2;
  int local_3;
  local_0 = gccubesearch_entrypoint_9(param_0, &B_80800EB0_gccubesearch, 0x28);
  local_3 = param_1;
  local_1 = 0;
  for (local_2 = local_0 - 1; local_2 >= 0; local_2--)
  {
    if (((u32)(*(s32 *)((char *)B_80800EB0_gccubesearch[local_2] + 0x10)) >> 21) < local_3)
    {
      local_1++;
    }
  }

  return local_1;
}

s32 gccubesearch_entrypoint_11(s32 param_0, Vec3f *param_1, s32 param_2)
{
    s32 local_2 = 0;
    u8 *local_0;
    u8 *local_1;

    func_800BE52C(&local_0, &local_1);
    for (; local_0 < local_1; local_0 += 8) {
        local_2 += _gspropmarker_entrypoint_2(local_0, param_0, param_1 + local_2, param_2 - local_2);
    }
    return local_2;
}

s32 func_80800590_gccubesearch(param_0, param_1, param_2, param_3) f32 *param_0; void *param_1; void *param_2; f32 (*param_3)(void *, f32 *);
{
    f32 local_1[40][3];
    s32 local_0;
    f32 local_2;
    f32 local_3;
    s32 local_4;

    func_800EFD24(param_0);
    local_2 = 3.402823466e+38f;
    local_4 = gccubesearch_entrypoint_11(param_1, local_1, 40);
    if (local_4 == 0) {
        return 0;
    }
    for (local_0 = 0; local_0 < local_4; local_0++) {
        local_3 = param_3(param_2, local_1[local_0]);
        if (local_3 < local_2) {
            local_2 = local_3;
            func_800EE7F8(param_0, local_1[local_0]);
        }
    }
    if (local_2 == 3.402823466e+38f) {
        return 0;
    }
    return 1;
}

void gccubesearch_entrypoint_12(s32 p0, s32 p1, s32 p2) {
    func_80800590_gccubesearch(p0, p1, p2, &func_800EEB40);
}

int gccubesearch_entrypoint_13(s32 p0, s32 p1, s32 p2)
{
  func_80800590_gccubesearch(p0, p1, p2, &func_800EFC7C);
}

s32 gccubesearch_entrypoint_14(param_0, param_1) s32 param_0; s32 *param_1;
{
    s32 local_0[3];
    s32 local_11;
    s32 local_1[3];
    s32 local_2[3];
    f32 local_3[3];
    s32 local_4[3];
    s32 local_5[3];
    s32 local_12;

    func_800BE554(local_1, local_2, param_1);
    if (param_1) {
        local_3[0] = (f32)param_1[0];
        local_3[1] = (f32)param_1[1];
        local_3[2] = (f32)param_1[2];
        func_800BD64C(local_0, local_3);
        for (local_12 = 0; local_12 < 3; local_12++) {
            local_4[local_12] = local_0[local_12] - 1;
            local_5[local_12] = local_0[local_12] + 1;
            if (local_4[local_12] < local_1[local_12]) local_4[local_12] = local_1[local_12];
            if (local_2[local_12] < local_5[local_12]) local_5[local_12] = local_2[local_12];
        }
        for (local_0[0] = local_4[0]; local_0[0] <= local_5[0]; local_0[0]++) {
            for (local_0[1] = local_4[1]; local_0[1] <= local_5[1]; local_0[1]++) {
                for (local_0[2] = local_4[2]; local_0[2] <= local_5[2]; local_0[2]++) {
                    local_11 = _gspropmarker_entrypoint_0(func_800BDAD4(local_0), param_0);
                    if (local_11) return local_11;
                }
            }
        }
    }
    for (local_0[1] = local_1[1]; local_0[1] <= local_2[1]; local_0[1]++) {
        if (func_800D2E90(local_0[1] - local_1[1])) {
            for (local_0[0] = local_1[0]; local_0[0] <= local_2[0]; local_0[0]++) {
                for (local_0[2] = local_1[2]; local_0[2] <= local_2[2]; local_0[2]++) {
                    local_11 = _gspropmarker_entrypoint_0(func_800BDAD4(local_0), param_0);
                    if (local_11) return local_11;
                }
            }
        }
    }
    return 0;
}

void *gccubesearch_entrypoint_15(s32 param_0, s32 param_1, f32 *param_2)
{
    s32 local_0[3];
    s32 local_5;
    s32 local_1[3];
    s32 local_2[3];
    s32 local_3[3];
    s32 local_4[3];
    u8 *local_6;
    func_800BE554(local_3, local_4);
    func_800BD64C(local_0, param_2);
    for (local_5 = 0; local_5 < 3; local_5++) {
        local_1[local_5] = local_0[local_5] - 1;
        local_2[local_5] = local_0[local_5] + 1;
        if (local_1[local_5] < local_3[local_5]) local_1[local_5] = local_3[local_5];
        if (local_4[local_5] < local_2[local_5]) local_2[local_5] = local_4[local_5];
    }
    for (local_0[0] = local_1[0]; local_0[0] <= local_2[0]; local_0[0]++)
        for (local_0[1] = local_1[1]; local_0[1] <= local_2[1]; local_0[1]++)
            for (local_0[2] = local_1[2]; local_0[2] <= local_2[2]; local_0[2]++) {
                local_6 = (u8 *)_gspropmarker_entrypoint_0(func_800BDAD4(local_0), param_0);
                if (local_6 && (!param_1 || param_1 == (*(u32 *)(local_6 + 0x10) >> 21)))
                    return local_6;
            }
    return 0;
}

void gccubesearch_entrypoint_16(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    u64 *local_0;
    u64 *local_1;
    func_800EB880(param_0, param_3, param_4);
    func_800BE52C(&local_0, &local_1);
    while (local_0 < local_1) {
        func_800EB8C0(local_0);
        local_0++;
    }
    func_800EBB30(param_1, param_2);
}

void *gccubesearch_entrypoint_17(s32 param_0, void **param_1)
{
    s32 local_0[3];
    u8 *local_3;
    s32 local_1[3];
    s32 local_2[3];
    u8 *local_4;
    void *local_5;
    func_800BE554(local_1, local_2);
    for (local_0[1] = local_1[1]; local_0[1] <= local_2[1]; local_0[1]++) {
        if (func_800D2E90(local_0[1] - local_1[1])) {
            for (local_0[0] = local_1[0]; local_0[0] <= local_2[0]; local_0[0]++) {
                for (local_0[2] = local_1[2]; local_0[2] <= local_2[2]; local_0[2]++) {
                    local_5 = func_800BDAD4(local_0);
                    if (local_5) {
                        local_3 = func_800E9D68(local_5);
                        local_4 = func_800E9D90(local_5);
                        for (; local_3 < local_4; local_3 += 0x14) {
                            if (param_0 == *(u32 *)(local_3 + 0x10) >> 21) {
                                if (param_1) *param_1 = local_5;
                                return local_3;
                            }
                        }
                    }
                }
            }
        }
    }
    if (param_1) *param_1 = NULL;
    return NULL;
}

s32 gccubesearch_entrypoint_18(s32 param_0, s32 *param_1, s32 *param_2, s32 *param_3,
    s32 *param_4, s32 *param_5, u8 **param_6)
{
    s32 local_2;
    void *local_3;
    Mass46CubeCoords local_0;
    Mass46CubeCoords local_1;
    u32 local_4;

    local_2 = 0;
    func_800BE554(&local_0, &local_1);
    if (!param_0) {
        param_4[0] = local_0.local_0;
        param_4[1] = local_0.local_1;
        param_4[2] = local_0.local_2;
        *param_5 = 0;
        return 0;
    }
    do {
        if (local_1.local_0 < param_4[0]) {
            return -1;
        }
        local_3 = (void *)func_800BDAD4(param_4);
        if (local_3 && func_800E9DC4(local_3)) {
            *param_6 = func_800E9BF4(local_3, *param_5);
            local_4 = *(u32 *)(*param_6 + 0x10);
            *param_2 = (local_4 << 11) >> 21;
            local_2 = local_4 >> 21;
            *param_3 = *(u32 *)(*param_6 + 4) & 1;
            param_1[0] = *(s16 *)(*param_6);
            param_1[1] = *(s16 *)(*param_6 + 2);
            param_1[2] = *(s16 *)(*param_6 + 4);
            (*param_5)++;
        }
        if (!local_3 || *param_5 >= func_800E9DC4(local_3)) {
            *param_5 = 0;
            param_4[2]++;
            if (local_1.local_2 < param_4[2]) {
                param_4[2] = local_0.local_2;
                param_4[1]++;
                if (local_1.local_1 < param_4[1]) {
                    param_4[1] = local_0.local_1;
                    param_4[0]++;
                    if (local_1.local_0 < param_4[0]) {
                        return local_2 ? local_2 : -1;
                    }
                }
            }
        }
    } while (local_2 == 0);
    return local_2;
}
