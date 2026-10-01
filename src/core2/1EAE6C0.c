#include "core2/1EAE6C0.h"

extern s32 D_8012B420;
extern u8 D_8011B641[];
extern u8 D_8011B642[];
typedef struct { u8 unused, initial, count; } LocalEntry;
extern LocalEntry D_8011B640[];
int func_800D4E7C();
void func_800D4FB8();

s32 func_800D4DD0(s32 param_0) {
    if (D_8012B420 != 0) {
        switch (param_0) {
        case 10: param_0 = 1; break;
        case 4:
        case 11: param_0 = 0; break;
        }
    }
    return param_0;
}

void func_800D4E18(s32 param_0, s32 param_1) {
    if (param_0 == 9) {
        param_0 = 1;
    }
    if (param_1 < 0) {
        func_800FC660(0x74);
    }
    func_800D4FB8(param_0, func_800D4E7C(param_0) + param_1);
}

int func_800D4E7C(param_0) s32 param_0;
{
    s32 idx;
    if (param_0 == 9) {
        param_0 = 1;
    }
    idx = func_800D4DD0(param_0);
    return D_8011B641[idx * 3];
}

u8 func_800D4EB8(s32 param_0)
{
    s32 idx;
    if (param_0 == 9) {
        param_0 = 1;
    }
    idx = func_800D4DD0(param_0);
    return D_8011B642[idx * 3];
}

int func_800D4EF4(s32 param_0)
{
  switch (param_0 - 1)
  {
    case 0:  return 5;
    case 1:  return 5;
    case 5:  return 3;
    case 6:  return 6;
    case 7:  return 5;
    case 9:  return 3;
    case 10: return 2;
    case 11: return 5;
    case 12: return 4;
    case 13: return 0;
    case 14: return 4;
    case 15: return 0;
    case 16: return 0;
    case 17: return 4;
    case 18: return 0;
  }
  return 0;
}

func_800D4F9C(param_0){
    if(param_0 == 2)
        return 0;
    return 1;
}

void func_800D4FB8(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 idx;
  u8 *var_v1;
  if (param_0 == 9)
  {
    param_0 = 1;
  }
  idx = func_800D4DD0(param_0);
  if (param_1 < 0)
  {
    var_v1 = ((u8 *) D_8011B640) + idx * 3;
    param_1 = 0;
  }
  else
  {
    var_v1 = ((u8 *) D_8011B640) + idx * 3;
    if (var_v1[2] < param_1)
    {
      param_1 = var_v1[2];
    }
  }
  var_v1[1] = param_1;
}

void func_800D5034(s32 param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    if (param_1 == 9) param_1 = 1;
    local_0 = D_8011B640[param_1].initial;
    local_1 = D_8011B640[param_1].count;
    switch (param_1) {
    case 1:
        switch (param_0) {
        case 0: case 2: case 6: case 7: case 8: case 12: case 15: case 16: case 18: case 19:
            local_0 = local_1; break;
        case 10: case 11:
            local_0 = D_8011B640[10].initial + D_8011B640[11].initial; break;
        }
        break;
    case 2: local_0 = 1; break;
    case 6: case 7: case 8: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        local_0 = local_1; break;
    case 10: case 11:
        if ((param_0 == 0) != 0) {
            local_0 = local_1;
            func_800D4FB8(param_1 == 10 ? 11 : 10, local_1);
        } else {
            local_0 = (s32)D_8011B640[param_0].initial / 2;
            if (param_1 == 10) local_0 += (s32)D_8011B640[param_0].initial % 2;
            if (!local_0) local_0 = 1;
        }
        break;
    }
    func_800D4FB8(param_1, local_0);
}

void func_800D517C()
{
  u8 *local_1;
  u32 *local_2;
  s32 local_0;
  s32 local_3;
  s32 local_4;
  s32 local_5;

  local_5 = _gcextra_entrypoint_0();
  local_2 = ((u32 *) &D_8012B420);
  *local_2 = 0;
  local_1 = ((u8 *) D_8011B640);
  local_0 = 0;
  do {
    local_4 = func_800D4EF4(local_0);
    local_3 = local_4;
    if ((local_4 != 0) && (func_800D4F9C(local_0) != 0)) {
      local_3 += local_5;
    }
    local_0 += 1;
    local_1 += 3;
    local_1[-1] = local_3;
    local_1[-2] = local_3;
  } while (local_0 != 0x14);
}

int func_800D5210(param_0){
    if(param_0 == 9){
        param_0 = 1;
    }

    return ((char *) D_8011B640)[param_0 * 3];
}

void func_800D5234(s32 param_0)
{
  D_8012B420 = param_0;
}

int func_800D5240()
{
  return D_8012B420;
}
