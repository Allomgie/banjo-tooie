#include "common.h"

extern int D_80128774[];
extern void func_800E3CB8(f32 *, f32 *);
extern void func_800E3C8C(f32, f32);
extern void func_800E3980(f32 *);
extern void func_800E44FC(s32);
extern void func_800DF738(s32);
extern void func_800DF7DC(s32);
extern void func_800DF818(s32);
extern void func_800DF4B0(s32);
extern void func_800DE448(f32 *, f32 *, f32, void *, s32);
extern s32 func_800EA340(void);
extern void _glid_entrypoint_6(s32, s32);
extern void _glid_entrypoint_5(s32, s32);
extern f32 func_800D8FF8(void);
extern s32 D_80128778[];
extern void func_800DBEFC(s32, s32, s32);

typedef struct { s32 local_0[2], local_1[2], local_2[2], local_3[2], local_4[2][2]; u8 pad[0xF0]; f32 local_5[2], local_6[2], local_7, local_8; s32 local_9[2]; } D_80128770_unk;

typedef union {
    D_80128770_unk D_80128770_unk;
    s32 arr[1];
} Union_D_80128770;
extern Union_D_80128770 D_80128770;
int func_800BFCD0(s32 param_0, s32 param_1)
{
    D_80128770.arr[param_0 + 0xC] = param_1;
    if (param_0 > D_80128770.arr[0xC])
    {
        D_80128770.arr[0xC] = param_0;
    }
}

int func_800BFD00()
{
  s32 *local_0;
  s32 local_1;
  local_1 = 1;
  if (((int *) D_80128770.arr)[12] > 0)
  {
    local_0 = &D_80128774[0];
    do
    {
      func_800DF744(local_1, (*(s32 *)((char *)(local_0) + 48)));
      local_1++;
      local_0++;
    }
    while (local_1 <= ((int *) D_80128770.arr)[12]);
  }
}

void func_800BFD6C(s32 param_0, s32 param_1) {
    s32 local_4;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    if (D_80128770.D_80128770_unk.local_2[0]) {
        func_800E3CB8(&local_2, &local_3);
        func_800E3C8C(5.0f, D_80128770.D_80128770_unk.local_7);
        func_800E3980(local_0);
        func_800E44FC(param_0);
        for (local_4 = 0; local_4 < 2; local_4++) {
            if (D_80128770.D_80128770_unk.local_2[local_4]) {
                local_1[0] = 0.0f;
                local_1[1] = D_80128770.D_80128770_unk.local_5[local_4] * D_80128770.D_80128770_unk.local_8;
                local_1[2] = 0.0f;
                func_800BFD00();
                func_800DF738(D_80128770.D_80128770_unk.local_0[local_4]);
                func_800DF7DC(D_80128770.D_80128770_unk.local_3[local_4]);
                func_800DF818(D_80128770.D_80128770_unk.local_4[local_4][D_80128770.D_80128770_unk.local_9[local_4]]);
                func_800DF4B0(2);
                func_800DE448(local_0, local_1, D_80128770.D_80128770_unk.local_6[local_4], 0, D_80128770.D_80128770_unk.local_2[local_4]);
                if (D_80128770.D_80128770_unk.local_4[local_4][1] && func_800EA340()) {
                    if (D_80128770.D_80128770_unk.local_1[local_4]) _glid_entrypoint_6(D_80128770.D_80128770_unk.local_1[local_4], D_80128770.D_80128770_unk.local_4[local_4][D_80128770.D_80128770_unk.local_9[local_4]]);
                    D_80128770.D_80128770_unk.local_9[local_4] ^= 1;
                    if (D_80128770.D_80128770_unk.local_1[local_4]) _glid_entrypoint_5(D_80128770.D_80128770_unk.local_1[local_4], D_80128770.D_80128770_unk.local_4[local_4][D_80128770.D_80128770_unk.local_9[local_4]]);
                }
            }
        }
        func_800E3C8C(local_2, local_3);
    }
}

void func_800BFF28()
{
    _gcskyDll_entrypoint_0(&D_80128770);
}

void func_800BFF4C()
{
    _gcskyDll_entrypoint_1(&D_80128770);
}

void func_800BFF70(void)
{
  ((f32 *) D_80128770.arr)[0x4D] += func_800D8FF8();
}

int func_800BFFA0(s32 param_0)
{
  return D_80128778[param_0];
}

s32 func_800BFFB4(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_0 = D_80128770.arr[param_0];
    if (local_0) { func_800DBEFC(local_0, param_1, param_2); return 1; }
    return 0;
}

void func_800BFFF4(void)
{
  s32 *local_0;
  s32 *new_var;
  s32 local_1;
  s32 local_2;
 do { new_var = ((s32 *) D_80128778); local_0 = ((s32 *) D_80128770.arr); do { local_1 = *((s32 *) (((s8 *) local_0) + 8)); if (local_1 != 0) { *((s32 *) (((s8 *) local_0) + 8)) = func_800EE5D8(local_1); } local_2 = *((s32 *) (((s8 *) local_0) + 0)); if (local_2 != 0) { *((s32 *) (((s8 *) local_0) + 0)) = func_800DC060(local_2); } local_0 += 1; } while (local_0 != new_var); } while (0);
}

int func_800C0064(s32 param_0)
{
  u32 local_0;
  local_0 = param_0 | 0;
  _gcskyDll_entrypoint_2(((s32 *) D_80128770.arr), local_0);
}
