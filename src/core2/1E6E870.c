#include "core2/1E6E870.h"
#include "types.h"

#define STATE(p) (*(LocalEntry **)((u8 *)(p)+0x78))
f32 func_800A0C2C(void *param_0);
f32 func_800A0C38(void *param_0);
extern void func_800A0D74(s32, f32);
extern void func_800A0D84(s32, f32);
typedef struct { f32 local_0; u8 local_1; u8 pad_5[3]; } Struct8009518CElement;
typedef struct { u8 pad_0[0x78]; Struct8009518CElement *local_0; } Struct8009518C;
typedef struct { f32 duration; u8 state; u8 pad[3]; } LocalEntry;
extern f32 func_800D8FF8(void);

s32 func_80094F80(void)
{
	return 0x20;
}

f32 func_80094F88(void *param_0, s32 param_1) {
    switch (param_1) {
    case 0:
        return func_800A0C2C(param_0);
    case 1:
        return func_800A0C38(param_0);
    case 2:
        return 0.0f;
    case 3:
        return 0.0f;
    default:
        return 0.0f;
    }
}

void func_80095004(s32 param_0, s32 param_1, f32 param_2)
{
  switch (param_1)
  {
    case 0 :
      func_800A0D74(param_0, param_2);
      break;

    case 1 :
      func_800A0D84(param_0, param_2);
      break;

    case 2 :
    case 3 :
      break;
  }
}

void func_80095068(u8 *param_0)
{
    s32 i;
    
    for (i = 0; i != 4; i++)
    {
        *(f32 *)(*(u8 **)(param_0 + 0x78) + i * 8) = 1.0f;
        *(u8 *)(*(u8 **)(param_0 + 0x78) + i * 8 + 4) = 0;
        func_80095004(param_0, i, 0.0f);
    }
}

void func_800950FC(u8 *arg0, s32 arg1, f32 arg2) {
    s32 temp_v0;

    temp_v0 = arg1 * 8;
    *(u8 *)((u8 *)*(s32 *)((u8 *)arg0 + 0x78) + temp_v0 + 4) = 1;
    *(f32 *)((u8 *)*(s32 *)((u8 *)arg0 + 0x78) + temp_v0) = arg2;
}

void func_80095124(u8 *param_0, s32 param_1, f32 param_2) {
    s32 temp_v0;

    temp_v0 = param_1 * 8;
    (*(s8 *)((s8 *)(((*(s32 *)((s8 *)(param_0) + (0x78))) + temp_v0)) + (4))) = 5;
    (*(f32 *)((s8 *)((*(s32 *)((s8 *)(param_0) + (0x78))) + temp_v0))) = param_2;
}

void func_8009514C(PlayerState *param_0)
{
  func_80095124(param_0, 0, 0.09f);
  func_80095124(param_0, 1, 0.09f);
}

int func_8009518C(void *param_0, s32 param_1, f32 param_2)
{
    ((Struct8009518C *)param_0)->local_0[param_1].local_1 = 4;
    ((Struct8009518C *)param_0)->local_0[param_1].local_0 = param_2;
}

void func_800951B4(PlayerState *param_0)
{
    func_8009518C(param_0, 0, 0.034f);
    func_8009518C(param_0, 1, 0.034f);
}

void func_800951F4(void *param_0)
{
    s32 local_0;
    s32 local_4;
    f32 local_1;
    f32 local_2;
    LocalEntry *local_3;
    local_1 = func_800D8FF8();
    local_0 = 0;
    local_4 = 0;
    do {
        local_2 = func_80094F88(param_0, local_0);
        local_3 = (LocalEntry *)((u8 *)STATE(param_0) + local_4);
        switch (local_3->state) {
        case 1:
            local_2 += local_1 / local_3->duration;
            if (local_2 > 1.0f) { local_2 = 1.0f; local_3->state = 2; }
            func_80095004(param_0, local_0, local_2);
            break;
        case 2:
            local_3->state = 3;
            break;
        case 3: case 4:
            local_2 -= local_1 / local_3->duration;
            if (local_2 < 0.0f) { local_2 = 0.0f; local_3->state = 0; }
            func_80095004(param_0, local_0, local_2);
            break;
        case 5:
            local_2 += local_1 / local_3->duration;
            if (local_2 > 1.0f) { local_2 = 1.0f; local_3->state = 0; }
            func_80095004(param_0, local_0, local_2);
            break;
        case 0: break;
        }
        local_0++;
        local_4 += 8;
    } while (local_0 != 4);
}
