#include "common.h"

extern s32 _glglobaldata_entrypoint_1(s32);
extern int D_80079D70[];
extern s32 B_80800270_glgamestore;
extern s32 _gleeprom_entrypoint_1();

s32 func_80800000_glgamestore() {
    s32 ret;

    ret = _glcrc_entrypoint_1();
    if (ret) {
        ret = 3;
    }
    return ret;
}

s32 func_80800030_glgamestore(param_0) s32 param_0;{
    return param_0 << 7;
}

int func_80800038_glgamestore(param_0) s32 param_0;
{
  s32 new_var2;
  int new_var;
  new_var = param_0 * (new_var2 = 448);
  return func_80800030_glgamestore(2) + new_var;
}

s32 func_8080006C_glgamestore(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0 = 0;
  if (_gleeprom_entrypoint_2(param_0, param_1, param_2))
  {
    local_0 = 2;
  }
  if (local_0 == 0)
  {
    local_0 = func_80800000_glgamestore(param_1, param_2);
  }
  return local_0;
}

s32 glgamestore_entrypoint_0(s32 param_0, s32 param_1) {
    s32 local_0 = func_80800038_glgamestore(param_0);
    func_8080006C_glgamestore(local_0, param_1, 0x1C0);
}

s32 glgamestore_entrypoint_1(s32 param_0, s32 param_1) {
    s32 local_0 = func_8080006C_glgamestore(func_80800030_glgamestore(param_0), param_1, 0x80);
    if (local_0 == 0 && _glglobaldata_entrypoint_1(param_1) == 0) {
        local_0 = 2;
    }
    return local_0;
}

int func_8080013C_glgamestore()
{
  s32 local_1;

  local_1 = 0;
  if (D_80079D70[0x7B] == 2)
  {
    local_1 = 0;
    if (_gleeprom_entrypoint_1() != 0)
    {
      local_1 = 1;
    }
  }
  return local_1;
}

s32 glgamestore_entrypoint_2(s32 param_0, s32 param_1){
    func_8080013C_glgamestore(func_80800038_glgamestore(param_0), param_1, 0x1C0);
}

s32 glgamestore_entrypoint_3(s32 param_0, s32 param_1){
    func_8080013C_glgamestore(func_80800030_glgamestore(param_0), param_1, 0x80);
}

s32 func_808001E0_glgamestore(s32 param_0) {
    s32 local_0 = 0;
    if (_gleeprom_entrypoint_1(param_0, &B_80800270_glgamestore, 8) != 0) {
        local_0 = 1;
    }
    return local_0;
}

void glgamestore_entrypoint_4()
{
    func_808001E0_glgamestore(func_80800038_glgamestore());
}

s32 glgamestore_entrypoint_5(void){
    s32 out;
    out = func_80800030_glgamestore();
    func_808001E0_glgamestore(out);
}
