#include "common.h"

extern void *func_800D674C(s32);
extern void *func_800B274C(void *);
extern u8 *_dbid_entrypoint_2(void *, s32);
extern u8 *func_800B2190(s32);
extern void *heap_alloc(s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFD24();
extern void aligned4_memcpy(void *, void *, s32);
void glidmake_entrypoint_2();

int func_80800000_glidmake(s32 param_0[3])
{
  s32 local_0;
  if (func_800EEEA8(param_0 + 2))
  {
    local_0 = 0 | 0;
  }
  else
  {
    local_0 = param_0 + 2;
  }
  return local_0;
}

int glidmake_entrypoint_0(s16 param_0[3], s16 param_1[3], s16 *param_2)
{
  s16 local_0[3];
  s16 local_1[3];
  glidmake_entrypoint_2(param_0, param_1, local_0, local_1);
  param_2[0] = (local_0[0] + local_1[0]) / 2;
  param_2[1] = (local_0[1] + local_1[1]) / 2;
  param_2[2] = (local_0[2] + local_1[2]) / 2;
}

int glidmake_entrypoint_1(s32 param_0[3])
{
  s32 local_0;
  local_0 = func_800D674C(param_0[0]);
  func_800B274C(local_0 | 0);
}

void glidmake_entrypoint_2(param_0, param_1, param_2, param_3) u8 *param_0; s32 param_1; s16 *param_2; s16 *param_3;
{
    s16 *local_1;
    s16 *local_2;
    u8 *local_0;
    u8 *local_3;
    s16 *local_4;
    s32 local_7;
    void *local_8;

    func_800EFD4C(param_2);
    func_800EFD4C(param_3);
    local_0 = _dbid_entrypoint_2(func_800B274C(func_800D674C(*(s32 *)param_0)), param_1);
    if (local_0 != NULL) {
        local_3 = func_800B2190(*(s32 *)(param_0 + 0x14));
        local_1 = (s16 *)(local_0 + 4);
        local_2 = (s16 *)(local_0 + 4 + *(s16 *)(local_0 + 2) * 2);
        while ((u32)local_1 < (u32)local_2) {
            local_4 = (s16 *)(local_3 + *local_1 * 16);
            for (local_7 = 0; local_7 < 3; local_7++) {
                if (local_1 == (s16 *)(local_0 + 4)) {
                    param_2[local_7] = param_3[local_7] = local_4[local_7];
                } else {
                    param_2[local_7] = local_4[local_7] < param_2[local_7] ? local_4[local_7] : param_2[local_7];
                    param_3[local_7] = param_3[local_7] < local_4[local_7] ? local_4[local_7] : param_3[local_7];
                }
            }
            local_1++;
        }
        local_8 = func_80800000_glidmake(param_0);
        if (local_8) {
            func_800EF0B4(param_2, local_8);
            func_800EF0B4(param_3, local_8);
        }
    }
}

s16 glidmake_entrypoint_3(s32 *param_0, s32 param_1) {
    s16 local_0;
    u8 *local_1;

    local_1 = _dbid_entrypoint_2(func_800B274C(func_800D674C(*param_0)), param_1);
    if (local_1 != NULL) {
        local_0 = *(s16 *)((char *)local_1 + 2);
    } else {
        local_0 = 0;
    }
    return local_0;
}

void glidmake_entrypoint_4(void* arg0) 
{
    heap_free(arg0);
}
u8 *glidmake_entrypoint_5(s32 param_0, f32 *param_1)
{
    s16 *local_0;
    u8 *local_1;
    u8 *local_11;
    s16 *local_3;
    s16 *local_4;
    s16 *local_5;
    s32 local_6;
    s32 local_2;
    s32 local_7;
    s32 local_8;
    s32 local_9;
    s32 local_10;
    u8 *local_12;
    u8 *local_13;
    u8 *local_14;
    local_9 = func_800D674C(param_0);
    local_0 = (s16 *)func_800B274C(local_9);
    if (!local_0) {
        return NULL;
    }
    local_1 = (u8 *)func_800B2840(local_9);
    local_10 = *local_0 * 8 + _dbid_entrypoint_1(local_0) * 0x10 + 0x1C;
    local_3 = local_0 + 1;
    local_4 = local_3;
    for (local_2 = 0; local_2 < *local_0; local_2++) {
        local_10 += _dbid_entrypoint_0(local_0, local_4[0]) * 4;
        local_4 += local_4[1];
    local_4 += 2;
    }
    local_4 = local_3;
    local_2 = 0;
    local_11 = heap_alloc(local_10);
    *(s32 *)local_11 = param_0;
    *(s32 *)(local_11 + 4) = *local_0;
    if (param_1) {
        func_800EE7F8((f32 *)(local_11 + 8), param_1);
    } else {
        func_800EFD24((f32 *)(local_11 + 8));
    }
    *(u8 **)(local_11 + 0x14) = local_1;
    *(s32 *)(local_11 + 0x18) = 0;
    local_12 = local_11 + 0x1C;
    for (; local_2 < *local_0; local_2++) {
        ((s16 *)local_12)[0] = local_4[0];
        ((s16 *)local_12)[1] = _dbid_entrypoint_0(local_0, local_4[0]);
        local_6 = 1;
        local_7 = 1;
        local_8 = local_4[2];
        local_5 = (s16 *)(local_12 + 8);
        local_13 = local_12 + ((s16 *)local_12)[1] * 4 + 8;
        aligned4_memcpy(local_13, local_1 + local_8 * 0x10 + 0x18, 0x10);
        local_13 += 0x10;
        local_3 = local_4 + 1;
        for (; local_7 < local_4[1]; local_7++) {
            if (local_3[2] != local_3[1] + 1) {
                local_5[0] = local_8;
                local_5[1] = local_6;
                local_6 = 0;
                local_5 += 2;
                local_8 = local_3[2];
            }
            aligned4_memcpy(local_13, local_1 + local_3[2] * 0x10 + 0x18, 0x10);
            local_3++;
            local_13 += 0x10;
            local_6++;
        }
        local_5[0] = local_8;
        local_5[1] = local_6;
        *(s32 *)(local_12 + 4) = local_13 - local_12;
        local_4 += local_4[1];
        local_4 += 2;
        local_12 = local_13;
    }
    return local_11;
}
