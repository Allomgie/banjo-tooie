#include "common.h"

typedef struct CubeListView { u64 *local_0; u8 pad_0[0x20]; s32 local_1; } CubeListView;
extern void _gspropsDll_entrypoint_0(u64 *, u32 *, s32 *);
extern void _gspropsDll_entrypoint_1(u32 *, s32);
extern void *heap_alloc(s32);
extern void heap_free();
typedef struct { void *data; s32 min[3]; s32 max[3]; u32 stride1; u32 stride2; u32 total; s32 size[3]; u8 pad34[8]; s16 count; s16 pad3E; f32 inv; void *aux; } GCCube;
extern void func_800CD230(f32);
extern void func_800E9C44();
typedef struct { s32 a, b; } CubeEnt;
typedef struct { CubeEnt *arr; u8 pad[0x20]; s32 count; } CubeS;
extern void _gccollectDll_entrypoint_8(CubeEnt *);
extern void _gspropsDll_entrypoint_2(void *param_0, int param_1);
extern void func_800CB9FC(void);
extern void func_800CBA20(void);
extern void func_800CBA44(void);
int func_80800868_gccubeDll();

void gccubeDll_entrypoint_0(CubeListView *param_0)
{
    u64 *local_3;
    s32 local_1;
    u32 local_0[499];
    s32 pad;
    s32 local_2;

    for (local_1 = 0; local_1 < 500; local_1++) {
        local_0[local_1] = 0;
    }
    local_2 = 0;
    for (local_3 = param_0->local_0; local_3 < param_0->local_1 + param_0->local_0; local_3++) {
        _gspropsDll_entrypoint_0(local_3, local_0, &local_2);
    }
    _gspropsDll_entrypoint_1(local_0, local_2);
}

void func_808000B8_gccubeDll(void *param_0, s32 param_1)
{
    u8 local_0;
    s32 local_3;
    u8 *local_1;
    u8 *local_2;
    s32 local_4;
    if (_gsmaker_entrypoint_17(param_0, 0xA, &local_0)) {
        local_3 = local_0 * 0x14;
        local_1 = heap_alloc(local_3);
        _gsmaker_entrypoint_18(param_0, 0xB, local_1, local_0 * 0x14);
        for (local_4 = 0; local_4 < local_0 && param_1 == 0; local_4++) _gspropsDll_entrypoint_3(local_1 + local_4 * 0x14);
        heap_free(local_1);
    }
    if (_gsmaker_entrypoint_17(param_0, 8, &local_0)) {
        local_4 = 0;
        local_3 = local_0 * 0xC;
        local_2 = heap_alloc(local_3);
        _gsmaker_entrypoint_18(param_0, 9, local_2, local_0 * 0xC);
        for (; local_4 < local_0 && param_1 == 0; local_4++) _gspropsDll_entrypoint_4(local_2 + local_4 * 0xC);
        heap_free(local_2);
    }
}

void func_80800230_gccubeDll(void *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_3;
    u8 *local_1;
    u8 *local_2;

    if (_gsmaker_entrypoint_21(param_0, 0xA, &local_0)) {
        local_1 = heap_alloc(local_0 * 0x14);
        _gsmaker_entrypoint_8(param_0, local_1, local_0 * 0x14);
        for (local_3 = 0; local_3 < local_0 && param_1 == 0; local_3++) {
            _gspropsDll_entrypoint_3(local_1 + local_3 * 0x14);
        }
        heap_free(local_1);
    }
    if (_gsmaker_entrypoint_21(param_0, 8, &local_0)) {
        local_2 = heap_alloc(local_0 * 0xC);
        _gsmaker_entrypoint_8(param_0, local_2, local_0 * 0xC);
        for (local_3 = 0; local_3 < local_0 && param_1 == 0; local_3++) {
            _gspropsDll_entrypoint_4(local_2 + local_3 * 0xC);
        }
        heap_free(local_2);
    }
}

void func_808003A0_gccubeDll(s32 param_0, s32 param_1) {
  s8 _sfpad[8];
    s32 sp2C;

    if (_gsmaker_entrypoint_16(param_0, 1) == 0) {
        do {
            if (_gsmaker_entrypoint_22(param_0, 0, &sp2C, 3) != 0) {
                _gsmaker_entrypoint_12(param_0, &sp2C, 3);
            } else if ((_gsmaker_entrypoint_22(param_0, 2, &sp2C, 3) == 0) && (_gsmaker_entrypoint_16(param_0, 3) != 0)) {
                func_808000B8_gccubeDll(param_0, param_1);
            }
        } while (_gsmaker_entrypoint_16(param_0, 1) == 0);
    }
}

void gccubeDll_entrypoint_1(GCCube *param_0)
{
    extern void func_800CD23C();
    extern void func_800CD3A8();
    extern void func_800CD544();

    s32 local_0[3];
    s32 local_1[3];
    s32 i;
    GCCube *p; /* unused: the target's frame has this slot */

    param_0->count = _gcmapDll_entrypoint_5();
    param_0->inv = 1.0f / (f32)param_0->count;
    func_800BEC4C(param_0->min, param_0->max, param_0->count);
    if (1) { /* NOSREG: the block lowers uopt's priority, so the loop gets v1/v0/a0 as in the target */
    for (i = 0; i < 3; i++) {
        param_0->size[i] = param_0->max[i] - param_0->min[i] + 1;
    }
    }
    param_0->stride1 = param_0->size[0];
    param_0->stride2 = param_0->size[1] * param_0->stride1;
    param_0->total = param_0->size[2] * param_0->stride2;
    param_0->data = heap_alloc(param_0->total << 3);
    param_0->aux = heap_alloc(param_0->total);
    for (local_0[0] = param_0->min[0]; local_0[0] <= param_0->max[0]; local_0[0]++) {
        for (local_0[1] = param_0->min[1]; local_0[1] <= param_0->max[1]; local_0[1]++) {
            for (local_0[2] = param_0->min[2]; local_0[2] <= param_0->max[2]; local_0[2]++) {
                func_800EFB58(local_1, local_0, param_0->min);
                func_800E9E4C((u64 *)param_0->data + local_1[0] + local_1[1] * param_0->stride1 + local_1[2] * param_0[0].stride2 /* [0] form: the target loads stride2 before local_1[2] */, local_0);
            }
        }
    }
    func_800E9E4C(param_0->pad34, 0);
    func_800CD230(func_800EA05C() == 0xD7 ? 1000.0f : 200.0f);
    func_800C6A08(func_800CD23C, func_800CD3A8, func_800CD544);
    func_800CE2DC();
    func_800E9708();
}

void gccubeDll_entrypoint_2(void *param_0)
{
  u32 local_0 = *((u32 *) param_0);
  if (local_0 < ((u32) (local_0 + (((s32 *) (((char *) param_0) + 0x24))[0] * 8))))
  {
    do
    {
      func_800E9C44((void *) local_0);
      local_0 += 8;
    }
    while (local_0 < ((u32) (((u32) ((u32 *) param_0)[0]) + (((s32 *) (((char *) param_0) + 0x24))[0] * 8))));
  }
  func_800E9C44((void *) (((char *) param_0) + 0x34));
  heap_free((void *) ((u32 *) param_0)[0]);
  ((u32 *) param_0)[0] = 0;
  heap_free((void *) ((u32 *) param_0)[0x11]);
  ((u32 *) param_0)[0x11] = 0;
}

void gccubeDll_entrypoint_3(void *param_0, void *param_1)
{
    s32 local_0[3];
    s32 local_1[3];
    s32 local_2[3];

    _gsmaker_entrypoint_22(param_1, 1, local_1, 3);
    _gsmaker_entrypoint_12(param_1, local_2, 3);
    for (local_0[0] = local_1[0]; local_0[0] <= local_2[0]; local_0[0]++) {
        for (local_0[1] = local_1[1]; local_0[1] <= local_2[1]; local_0[1]++) {
            for (local_0[2] = local_1[2]; local_0[2] <= local_2[2]; local_0[2]++) {
                func_808003A0_gccubeDll(param_1, 0);
            }
        }
    }
    _gsmaker_entrypoint_16(param_1, 0);
    func_80800868_gccubeDll(param_0, param_1);
}

s32 gccubeDll_entrypoint_4(s32 param_0, s32 param_1)
{
  s32 new_var;
  s32 new_var2;
  new_var = param_0;
  func_80800230_gccubeDll(new_var | (new_var = param_1), 0);
  new_var2 = new_var;
  _gsmaker_entrypoint_16(param_1, 1);
  func_80800868_gccubeDll(param_0, new_var2);
}

int func_80800868_gccubeDll(param_0, param_1) s32 param_0; s32 param_1;
{
  func_800CE308(param_0 ^ 0);
}

void gccubeDll_entrypoint_5(CubeS *param_0) {
    s32 i;
    for (i = 0; i < param_0->count; i++) {
        _gccollectDll_entrypoint_8(&param_0->arr[i]);
    }
}

void gccubeDll_entrypoint_6(void *param_0)
{
    s32 var_s0;

    var_s0 = 0;
    if ((*(s32 *)((char *)param_0 + 0x24)) > 0) {
        do {
            _gspropsDll_entrypoint_2((*(s32 *)((char *)param_0 + 0)) + (var_s0 << 3), 0);
            var_s0 += 1;
        } while (var_s0 < (*(s32 *)((char *)param_0 + 0x24)));
        var_s0 = 0;
    }
    func_800CBA20();
    if ((*(s32 *)((char *)param_0 + 0x24)) > 0) {
        do {
            _gspropsDll_entrypoint_2((*(s32 *)((char *)param_0 + 0)) + (var_s0 << 3), 1);
            var_s0 += 1;
        } while (var_s0 < (*(s32 *)((char *)param_0 + 0x24)));
    }
    func_800CB9FC();
    func_800CBA44();
}

u32 gccubeDll_entrypoint_7(void)
{
    u32 local_4;
    u32 local_0;
    u32 local_1;
    u32 local_2;
    u32 local_3;

    local_2 = 0;
    func_800BE52C(&local_0, &local_1);
    while (local_0 < local_1) {
        local_3 = func_800E9D68(local_0);
        local_4 = func_800E9D90(local_0);
        while (local_3 < local_4) {
            if (local_2 < (*(u32 *)(local_3 + 0x10) >> 21)) {
                local_2 = *(u32 *)(local_3 + 0x10) >> 21;
            }
            local_3 += 0x14;
        }
        local_0 += 8;
    }
    return local_2;
}
