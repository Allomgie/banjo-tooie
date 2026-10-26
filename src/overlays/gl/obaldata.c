#include "common.h"

typedef void (*GlobalDataQuery)(s32 *, void **);
extern GlobalDataQuery D_80800238_glglobaldata[];
extern GlobalDataQuery D_80800230_glglobaldata[];
extern void rare_memcpy(void *, void *, s32);
extern s32 _glcrc_entrypoint_0(void *, s32);
int glglobaldata_entrypoint_4();

void glglobaldata_entrypoint_0(void)
{
    s32 local_2;
    s32 local_3;
    s32 local_0;
    void *local_1;
    local_3 = 1;
    for (local_2 = 0; local_2 < 2; local_2++) {
        ((GlobalDataQuery *) D_80800230_glglobaldata)[local_2](&local_0, &local_1);
        local_3 += local_0;
    }
}

int glglobaldata_entrypoint_1(u8 *param_0) {
    return param_0[0] == 8;
}

void glglobaldata_entrypoint_2(s32 param_0)
{
  s8 _sfpad[8];
  s32 local_0;
  s32 local_1;
  void (**local_3)(s32 *, s32 *);
  s32 local_2;
  local_2 = 1;
 local_3 = &D_80800230_glglobaldata; do { (*local_3)(&local_0, &local_1); rare_memcpy(local_1, (void *) (((char *) param_0) + local_2), local_0);
    local_3 += 1;
    local_2 += local_0;
  }
  while (local_3 != (void *) (&D_80800238_glglobaldata));
}

s32 func_80800124_glglobaldata(u8 *param_0, s32 *param_1) {
    param_0[*param_1 + 0] = 8;
    (*param_1)++;
}

s32 glglobaldata_entrypoint_3(u8 *param_0)
{
    s32 local_3;
    s32 local_2;
    s32 local_1;
    void *local_0;

    glglobaldata_entrypoint_4(param_0);
    local_2 = 0;
    func_80800124_glglobaldata(param_0, &local_2);
    for (local_3 = 0; local_3 < 2; local_3++) {
        D_80800230_glglobaldata[local_3](&local_1, &local_0);
        rare_memcpy(param_0 + local_2, local_0, local_1);
        local_2 += local_1;
    }
    return _glcrc_entrypoint_0(param_0, 0x80);
}

int glglobaldata_entrypoint_4(param_0) u8 *param_0;
{
  u32 local_0;
  for (local_0 = 0; local_0 < 0x80; local_0++)
  {
    param_0[local_0] = 0;
  }

}
