/* Not core2/1EB5980.h: that header declares func_800DC128 as returning u8,
   which is what its callers were compiled against, but the function itself
   converts a float with trunc.w.s and returns the full word. Including the
   header here would force an unsigned conversion into the definition. */
#include "common.h"

extern s32 D_8012C7F0;
extern s32 D_8011B9A0;
extern s32 D_8011B9A4;
extern s32 D_8012C7F4;
extern s32 D_8012C7F8;
extern s32 D_8012C7FC;

s32 func_800DC090(void)
{
    return D_8012C7F0 = D_8012C7F0 * 0x19660D + 0x3C6EF35F;
}

f32 func_800DC0C0(void) {
    s32 local_0;
    f32 local_1;

    D_8012C7F0 = D_8012C7F0 * 0x19660D + 0x3C6EF35F;
    local_0 = (D_8011B9A4 & D_8012C7F0) | D_8011B9A0;
    local_1 = *(f32*)&local_0 - 1.0f;
    return local_1;
}

s32 func_800DC128(s32 param_0, s32 param_1)
{
  f32 local_0;
  f32 local_1;
  f32 local_2;
  local_0 = param_1 - param_0;
  local_2 = (local_0 * func_800DC0C0()) + param_0;
  return local_2;
}

f32 func_800DC178(f32 param_0, f32 param_1) {
    return func_800DC0C0() * (param_1 - param_0) + param_0;
}

f32 func_800DC1AC(void) {
    s32 local_0;
    f32 local_1;

    D_8012C7F4 = D_8012C7F4 * 0x19660D + 0x3C6EF35F;
    local_0 = (D_8011B9A4 & D_8012C7F4) | D_8011B9A0;
    local_1 = *(f32*)&local_0 - 1.0f;
    return local_1;
}

s32 func_800DC214(s32 param_0, s32 param_1)
{
  return (s32) ((func_800DC1AC() * (f32) (param_1 - param_0)) + (f32) param_0);
}

f32 func_800DC264(f32 param_0, f32 param_1) {
    return func_800DC1AC() * (param_1 - param_0) + param_0;
}

int func_800DC298(f32 param_0)
{
  f32 local_0;
  s32 local_1;
 do { local_0 = func_800DC0C0(); local_1 = 0; if (local_0 < param_0) { local_1 |= 1; goto block_1; } local_1 ^= 0; block_1: return local_1; } while (0);
}

int func_800DC2D4(f32 param_0)
{
  f32 new_var;
  f32 local_0;
  s32 local_1;
  local_0 = func_800DC1AC();
 do { local_1 = 0; new_var = local_0; if (new_var < param_0) { local_1 = 1; } else { local_1 = 0; } return local_1; } while (0);
}

void func_800DC310()
{
  D_8012C7F0 = 0x00EAA0C7;
}

int func_800DC324(s32 param_0)
{
  D_8012C7F0 = param_0;
}

void func_800DC330()
{
  D_8012C7F8 = D_8012C7F0;
  D_8012C7FC = D_8012C7F4;
}

void func_800DC354()
{
  D_8012C7F0 = D_8012C7F8;
  D_8012C7F4 = D_8012C7FC;
}
