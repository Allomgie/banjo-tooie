#include "common.h"

typedef struct { s32 local_0; u8 pad[9]; u8 local_1; u8 pad2[2]; f32 local_2; } State114EEC;
extern f32 func_80013970(f32);
extern s32 func_800EA068(s32);
extern s32 func_80110014(s32);
extern s32 func_80110840(s32);
extern s32 func_800A940C(s32);
extern void func_800C4B90(s32, f32, f32);
typedef struct { u8 pad0[4]; s32 index; f32 value; u8 enabled, padD, active; } LocalState;
typedef struct { u8 unused, color[3], value; } LocalEntry;
extern LocalEntry D_80124A50[];
extern f32 D_80126600, D_80126604, D_80126608;
extern void func_800B99CC(s32,s32,s32 *);
extern s16 D_80124A58;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
typedef struct { s32 local_0; s32 pad; f32 local_1; u8 local_2; } State1151C4;
extern f32 D_8012660C;
extern s32 func_8010FF80(s32);
extern void func_800CA7E4(s32, f32 *);
extern s32 func_800BEAAC(f32 *, f32 *);

s32 func_80114E80(s32 param_0)
{
  u8 *local_0;
 local_0 = ((u8 *) D_80124A50); while ((*local_0) != 0) {
    if (param_0 == (*local_0))
    {
      return ((local_0 - (((u8 *) D_80124A50))) ^ 0) / 5;
    }
    local_0 += 5;
  }

  return (local_0 - (((u8 *) D_80124A50))) / 5;
}

void func_80114EEC(State114EEC *param_0, s32 param_1) {
    f32 local_3[3];
    local_3[0] = func_80013970(param_0->local_2) * 1.5f;
    local_3[1] = func_80013970(param_0->local_2 * 1.5f) * 1.5f;
    if (!func_800EA068(0x20)) {
        func_800C4B90(func_800A940C(func_80110840(func_80110014(param_0->local_0))), local_3[0], local_3[1]);
        param_0->local_2 += 2.0f;
        param_0->local_1 = 1;
    }
}

void func_80114FA4(s32 param_0, LocalState *param_1)
{
    f32 local_0;
    f32 local_1;
    s32 local_2;
    s32 local_3[3];
    f32 local_4;
    if (param_1->enabled && param_1->active) {
        local_0 = param_1->value > D_80126600 ? 1.0f : param_1->value * D_80126604;
        local_1 = local_0 * D_80126608;
        for (local_2 = 0; local_2 < 3; local_2++) {
            local_3[local_2] = (u32)D_80124A50[param_1->index].color[local_2] + -(s32)D_80124A50[param_1->index].color[local_2] * local_1;
        }
        local_4 = (u32)D_80124A50[param_1->index].value;
        func_800B99CC(param_0, local_4 * local_0 + local_4, local_3);
    }
}

func_801150F0(u8 *param_0) {
    return param_0[0xC];
}

void func_801150F8(void* arg0) 
{
    heap_free(arg0);
}
u8 *func_80115118(s32 param_0) {
    s16 *local_0;
    s16 local_1;
    s32 local_2;
    u8 *local_3;

    local_3 = heap_alloc(0x14);
    (*(s32 *)((s8 *)(local_3) + (0))) = param_0;
    local_2 = func_800EA05C();
    (*(s32 *)((s8 *)(local_3) + (4))) = func_80114E80(local_2);
    (*(s8 *)((s8 *)(local_3) + (0xC))) = 0;
    (*(s8 *)((s8 *)(local_3) + (0xD))) = 0;
    (*(s8 *)((s8 *)(local_3) + (0xE))) = 1;
    (*(f32 *)((s8 *)(local_3) + (0x10))) = 0.0f;
    local_2 = func_800EA05C();
    local_1 = (s16)local_2;
    local_0 = (s16 *)&D_80124A58;
    while (*local_0 != 0) {
        if (*local_0 == local_1) {
            (*(s8 *)((s8 *)(local_3) + (0xE))) = 0;
            break;
        }
        local_0++;
    }
    return local_3;
}

void func_801151C4(State1151C4 *param_0) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    local_5 = func_8010FF80(param_0->local_0);
    func_800CA7E4(local_5, local_1);
    if (!func_800BEAAC(local_1, &local_3)) {
        func_800EFA4C(local_2, local_1[0], local_1[1] + D_8012660C, local_1[2]);
        local_4 = func_800BEF00(local_1, local_2, local_0, 0x1F00);
        if (local_4) {
            local_4 = (*(u32 *)(local_4 + 8) & 0x20000) ? 1 : 0;
            param_0->local_2 = local_4;
        } else {
            param_0->local_2 = 0;
        }
    } else {
        local_2[0] = local_1[0];
        local_2[2] = local_1[2];
        local_2[1] = local_1[1] + 1000.0f;
        local_4 = func_800BEF00(local_1, local_2, local_0, 0x1F00);
        if (!local_4 || !(*(u32 *)(local_4 + 8) & 0x20000)) local_2[1] = local_3;
        if (local_1[1] <= local_2[1]) param_0->local_2 = 1;
        else param_0->local_2 = 0;
    }
    if (param_0->local_2) {
        param_0->local_1 = local_2[1] - local_1[1];
        func_80114EEC(param_0, local_5);
    }
}

int func_80115324(s32 *param_0, s32 param_1)
{
  *param_0 = param_1;
  defrag();
}
