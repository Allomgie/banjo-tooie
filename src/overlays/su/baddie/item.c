#include "common.h"

extern void _subaddielink_entrypoint_0();
extern void func_80090658();
extern f32 func_800D8FF8(void);
extern s32 func_800902E4(f32 *, f32, s32, Actor **);
typedef struct { u8 pad0[0x64]; u32 padH : 9; u32 f : 1; u32 padL : 22; } ShiftBf64_22_0;
typedef struct { u8 pad0[0x65]; u8 f : 1; u8 pad : 7; } SignBf65_0;
void func_80800224_subaddieitem();

void subaddieitem_entrypoint_0(void *param_0, long param_1, int param_2, unsigned int param_3)
{
  *((u8 *) (((char *) param_0) + 0x0)) = 0;
  *((s16 *) (((char *) param_0) + 0x4)) = param_1;
  *((s16 *) (((char *) param_0) + 0x6)) = param_2;
  *((u8 *) (((char *) param_0) + 0x1)) = param_3;
  *((u8 *) (((char *) param_0) + 0x2)) = 0;
  *((u8 *) (((char *) param_0) + 0x3)) = 0;
  *((f32 *) (((char *) param_0) + 0x10)) = 0.0f;
  _subaddielink_entrypoint_0(((char *) param_0) + 0x8);
}

s32 subaddieitem_entrypoint_1(u8 *ptr, s32 param_1){
    ptr[2] = param_1;
}

void subaddieitem_entrypoint_2(u8 *param_0)
{
    func_80090658(1, param_0);
    (*(s8 *)((s8 *)(param_0) + (3))) = 1;
    (*(s8 *)((s8 *)(param_0) + (0))) = 1;
    (*(f32 *)((s8 *)(param_0) + (0x10))) = 0.0f;
    _subaddielink_entrypoint_0(param_0 + 8, param_0);
}

int subaddieitem_entrypoint_3(Actor *param_0, f32 *param_1, u8 *param_2)
{
    s32 local_0;
  s32 pad0;
    Actor *local_2;
    f32 local_1[1];

    local_0 = 0;
    *(f32 *)(param_2 + 0x10) += func_800D8FF8();
    switch (param_2[0]) {
        case 1:
            if (func_800902E4(param_0->position, (f32)*(s16 *)(param_2 + 6), *(s16 *)(param_2 + 4), &param_0) &&
                func_8008FE14() == *(s16 *)(param_2 + 4) && func_80090818()) {
                if (!param_1) { param_1 = local_1; func_80103DFC(param_0, param_1); }
                _subaddielink_entrypoint_1(param_2 + 8, func_8008FDEC());
                func_80090768(param_1);
                param_2[0] = 2;
            }
            break;
        case 2:
            if (!_subaddielink_entrypoint_2(param_2 + 8)) {
                func_80800224_subaddieitem(param_0, param_2, 0);
            } else {
                local_2 = (Actor *)_subaddielink_entrypoint_4(param_2 + 8);
                if (!(((ShiftBf64_22_0 *)(local_2))->f) &&
                    !((SignBf65_0 *)(local_2))->f) {
                    func_80800224_subaddieitem(param_0, param_2, local_2);
                }
            }
            break;
        case 3:
            if (param_2[3]) { func_80090658(0); param_2[3] = 0; }
            _subaddielink_entrypoint_0(param_2 + 8);
            param_2[0] = 0;
            local_0 = 1;
            break;
    }
    return local_0;
}

void func_80800224_subaddieitem(param_0, param_1, param_2) s32 param_0; u8 *param_1; s32 param_2;
{
  unsigned long local_0;
  local_0 = *((u8 *) (((s8 *) param_1) + 1));
  if (local_0 & 2)
  {
    func_800FC660(0xE);
    if (1)
    {
      local_0 = *((u8 *) (((s8 *) param_1) + 1));
    }
  }
  if ((local_0 & 1) && (param_2 != 0))
  {
    func_800FFAB0(param_2);
  }
  _subaddielink_entrypoint_0(param_1 + 8);
  if ((*((u8 *) (((s8 *) param_1) + 2))) != (1 * 0))
  {
    func_800D175C(func_800D1B34(*((s16 *) (((s8 *) param_1) + 4))), -((s32) (*((u8 *) (((s8 *) param_1) + 2)))));
  }
  func_8010108C(param_0, 0x2D, *((s16 *) (((s8 *) param_1) + 4)));
  *((s8 *) (((s8 *) param_1) + 0)) = 3;
}
