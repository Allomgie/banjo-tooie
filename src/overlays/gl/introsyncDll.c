#include "common.h"

extern s32 D_808004A0_glintrosyncDll;
extern s32 D_808004A8_glintrosyncDll;
extern s32 D_808004B0_glintrosyncDll;
extern s32 D_808004B8_glintrosyncDll[];
extern u8 D_80127194[];
extern s32 func_800C954C(void);
extern f32 func_800D8FF8(void);
extern f32 func_800D9004(void);
typedef struct { f32 pad0; f32 pad4; f32 time; f32 val; u8 flag; } IntroSync90;
typedef struct { s32 key; f32 value; } IntroKey90;
extern IntroKey90 D_808004F8_glintrosyncDll[27];
extern s32 _gcsectionDll_entrypoint_4(void);
extern u32 osGetCount(void);
extern f32 D_808004A4_glintrosyncDll[][2];
typedef struct { s32 a; s32 idx; f32 f; } IntroSyncCtx;
extern IntroSyncCtx D_801275D0;
typedef struct { f32 pad0; f32 pad4; f32 time; f32 val; } IntroSync78;

s32 func_80800000_glintrosyncDll(s32 param_0) {
    s8 *var_v0;
    s32 var_v1;

    if (param_0 == D_808004A0_glintrosyncDll) {
        return 0;
    }
    if (param_0 == D_808004A8_glintrosyncDll) {
        return 1;
    }
    var_v0 = &D_808004B8_glintrosyncDll;
    var_v1 = 3;
    if (param_0 == D_808004B0_glintrosyncDll) {
        return 2;
    }
loop_7:
    if (param_0 == (*(s32 *)((s8 *)(var_v0) + (0)))) {
        return var_v1;
    }
    if (param_0 == (*(s32 *)((s8 *)(var_v0) + (0x8)))) {
        return var_v1 + 1;
    }
    if (param_0 == (*(s32 *)((s8 *)(var_v0) + (0x10)))) {
        return var_v1 + 2;
    }
    if (param_0 == (*(s32 *)((s8 *)(var_v0) + (0x18)))) {
        return var_v1 + 3;
    }
    var_v1 += 4;
    var_v0 += 0x20;
    if (var_v1 == 0xB) {
        return -1;
    }
    goto loop_7;
}

u32 func_808000BC_glintrosyncDll(s32 param_0)
{
    s32 local_0;
    u32 local_1;

    local_1 = osGetCount();
    if (local_1 >= *(u32 *)(D_80127194 + 0x43C)) {
        local_0 = local_1 - *(u32 *)(D_80127194 + 0x43C);
    } else {
        local_0 = (0xFFFFFFFFU - *(u32 *)(D_80127194 + 0x43C)) + local_1 + 1;
    }
    return (u32)((f32)local_0 * 0.0213333331f);
}

int glintrosyncDll_entrypoint_0(s32 param_0)
{
  s32 local_0;
  ((int *) D_80127194)[0x10F] = osGetCount();
  local_0 = func_80800000_glintrosyncDll(param_0);
  ((int *) D_80127194)[0x110] = local_0;
}

void glintrosyncDll_entrypoint_1(void)
{
    s32 local_1 = D_801275D0.idx;
    if (local_1 >= 0) {
        f32 local_2;
        u32 local_3;
        local_2 = D_808004A4_glintrosyncDll[local_1][0] - D_801275D0.f;
        local_2 = local_2 * 1000000.0f;
        local_3 = local_2 < 0.0f ? 0 : (u32)local_2;
        while (func_808000BC_glintrosyncDll(D_801275D0.a) < local_3) {
        }
        D_801275D0.f += (f32)func_808000BC_glintrosyncDll(D_801275D0.a) / 1000000.0f;
    }
}

void glintrosyncDll_entrypoint_2(f32 param_0)
{
  (*(f32 *)((u8 *)((u8 *) D_80127194) + 0x444)) = param_0;
}

float glintrosyncDll_entrypoint_3()
{
  return ((f32 *) D_80127194)[0x111];
}

void glintrosyncDll_entrypoint_4(f32 param_0)
{
    f32 t = (*((IntroSync78 *) &D_801275D0)).time;
    if (t < 364.5f && t + param_0 >= 364.5f) {
        (*((IntroSync78 *) &D_801275D0)).val = 0.86f;
    }
    (*((IntroSync78 *) &D_801275D0)).time = t + param_0;
}

f32 glintrosyncDll_entrypoint_5(void) {
    if (func_800C954C()) {
        return *(f32 *)(D_80127194 + 0x448) * func_800D8FF8();
    }
    return *(f32 *)(D_80127194 + 0x448) * func_800D9004();
}

void glintrosyncDll_entrypoint_6(s32 param_0)
{
    s32 i;

    if (_gcsectionDll_entrypoint_4() == 0xD) {
        (*((IntroSync90 *) &D_801275D0)).flag = 1;
    } else {
        (*((IntroSync90 *) &D_801275D0)).flag = 0;
    }
    (*((IntroSync90 *) &D_801275D0)).val = 1.0f;
    if ((*((IntroSync90 *) &D_801275D0)).flag) {
        for (i = 0; i < 27; i++) {
            if (param_0 == D_808004F8_glintrosyncDll[i].key) {
                (*((IntroSync90 *) &D_801275D0)).val = D_808004F8_glintrosyncDll[i].value;
                break;
            }
        }
    }
}
