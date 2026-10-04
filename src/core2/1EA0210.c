#include "common.h"

typedef struct CollisionC6 CollisionC6;
typedef struct { CollisionC6 *(*local_0)(f32 *, f32 *, f32 *, u32); CollisionC6 *(*local_1)(f32 *, f32 *, f32, f32 *, s32, u32); CollisionC6 *(*local_2)(f32 *, f32, f32 *, u32); void *(*local_3)(void); } EntryC6;
extern struct { EntryC6 local_0[8]; EntryC6 *local_1; void *local_2; } D_8012AA40;
int func_800C696C(f32 param_0[3], f32 param_1, f32 param_2, s32 param_3, f32 *param_4);
void func_800C6A28();
CollisionC6 *func_800C6A7C();

extern s32 D_8012AAC4;

f32 func_800C6920(s32 param_0, f32 param_1, f32 param_2, s32 param_3) {
    f32 sp24;
    if (func_800C696C(param_0, param_1, param_2, param_3, &sp24) == 0) {
        sp24 = 100.0f;
    }
    return sp24;
}

int func_800C696C(f32 param_0[3], f32 param_1, f32 param_2, s32 param_3, f32 *param_4)
{
  f32 local_0[3];
  f32 local_1[3];
  f32 local_2[3];
  func_800EE7F8(local_0, param_0);
  local_0[1] += param_1;
  func_800EE7F8(local_1, param_0);
  local_1[1] += param_2;
  if (func_800C6A7C(local_0, local_1, local_2, param_3))
  {
    *param_4 = local_1[1];
    return 1;
  }
  return 0;
}

s32 func_800C69FC()
{
    return D_8012AAC4;
}

s32 func_800C6A08(s32 map, s32 exit, s32 direction){
    func_800C6A28(map, exit, direction, 0);
}

void func_800C6A28(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s32 param_3; {
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(((s32 *) &D_8012AA40)) + (0x80)))) + (0))) = param_0;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(((s32 *) &D_8012AA40)) + (0x80)))) + (4))) = param_1;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(((s32 *) &D_8012AA40)) + (0x80)))) + (8))) = param_2;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(((s32 *) &D_8012AA40)) + (0x80)))) + (0xC))) = param_3;
    (*(u8 **)((s8 *)(((s32 *) &D_8012AA40)) + (0x80))) = (u8 *) ((*(u8 **)((s8 *)(((s32 *) &D_8012AA40)) + (0x80))) + 0x10);
}

void func_800C6A60(void) {
}

int func_800C6A68()
{
  *(int**)((char*)((int *) &D_8012AA40) + 0x80) = ((int *) &D_8012AA40);
  *(int*)((char*)((int *) &D_8012AA40) + 0x84) = 0;
}

CollisionC6 *func_800C6A7C(param_0, param_1, param_2, param_3) f32 * param_0; f32 * param_1; f32 * param_2; u32 param_3; {
    EntryC6 *local_0;
    CollisionC6 *local_1;
    CollisionC6 *local_2;
    local_2 = 0;
    D_8012AA40.local_2 = 0;
    for (local_0 = &D_8012AA40.local_0[0]; local_0 < D_8012AA40.local_1; local_0++) {
        if (local_0->local_0 != 0) {
            local_1 = local_0->local_0(param_0, param_1, param_2, param_3);
            if (local_1 != 0) {
                if (local_0->local_3 != 0) {
                    D_8012AA40.local_2 = local_0->local_3();
                } else {
                    D_8012AA40.local_2 = 0;
                }
            }
            local_2 = local_1 != 0 ? local_1 : local_2;
        }
    }
    return local_2;
}

CollisionC6 *func_800C6B78(f32 *param_0, f32 *param_1, f32 param_2, f32 *param_3, s32 param_4, u32 param_5) {
    EntryC6 *local_0;
    CollisionC6 *local_1;
    CollisionC6 *local_2;
    local_2 = 0;
    D_8012AA40.local_2 = 0;
    for (local_0 = &D_8012AA40.local_0[0]; local_0 < D_8012AA40.local_1; local_0++) {
        if (local_0->local_1 != 0) {
            local_1 = local_0->local_1(param_0, param_1, param_2, param_3, param_4, param_5);
            if (local_1 != 0) {
                if (local_0->local_3 != 0) {
                    D_8012AA40.local_2 = local_0->local_3();
                } else {
                    D_8012AA40.local_2 = 0;
                }
            }
            local_2 = local_1 != 0 ? local_1 : local_2;
        }
    }
    return local_2;
}

CollisionC6 *func_800C6C94(f32 *param_0, f32 param_1, f32 *param_2, u32 param_3) {
    EntryC6 *local_0;
    CollisionC6 *local_1;
    CollisionC6 *local_2;
    local_2 = 0;
    D_8012AA40.local_2 = 0;
    for (local_0 = &D_8012AA40.local_0[0]; local_0 < D_8012AA40.local_1; local_0++) {
        if (local_0->local_2 != 0) {
            local_1 = local_0->local_2(param_0, param_1, param_2, param_3);
            if (local_1 != 0) {
                if (local_0->local_3 != 0) {
                    D_8012AA40.local_2 = local_0->local_3();
                } else {
                    D_8012AA40.local_2 = 0;
                }
            }
            local_2 = local_1 != 0 ? local_1 : local_2;
        }
    }
    return local_2;
}
