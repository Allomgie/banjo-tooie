#include "common.h"

typedef struct { s16 local_0; s16 local_1; s16 local_2[1]; } DbIdRecord;

s32 dbid_entrypoint_0(s16 *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s16 *local_3;

    local_3 = param_0 + 1;
    for (local_0 = 0; local_0 < param_0[0]; local_0++) {
        if (local_3[0] == param_1) {
            local_2 = 0;
            for (local_1 = 1; local_1 < local_3[1]; local_1++) {
                if (local_3[local_1 + 2] != local_3[local_1 + 1] + 1) {
                    local_2++;
                }
            }
            return local_2 + 1;
        }
        local_3 += local_3[1];
        local_3 += 2;
    }
    return 0;
}

int dbid_entrypoint_1(s16 *param_0)
{
  s16 temp_a0;
  s16 temp_a2;
  s32 var_a1;
  s32 var_v1;
  u8 *var_v0;
  ;
  var_v1 = 0;
  var_v0 = ((u8 *) param_0) + 2;
  var_a1 = 0;
  if ((*param_0) > 0)
  {
    do
    {
      temp_a0 = *((s16 *) (((s8 *) var_v0) + 2));
      var_a1 += 1;
      var_v0 = (u8 *) ((((s8 *) var_v0) + (temp_a0 * 2)) + 4);
      var_v1 += temp_a0;
    }
    while (var_a1 < (*param_0));
  }
  return var_v1;
}

s16 *dbid_entrypoint_2(s16 *param_0, s32 param_1) {
    s32 i;
    s16 *local_0 = param_0 + 1;
    for (i = 0; i < *param_0; i++) {
        if (local_0[0] == param_1) {
            return local_0;
        }
        local_0 += local_0[1];
        local_0 += 2;
    }
    return 0;
}

s32 dbid_entrypoint_3(void *param_0, s32 param_1, u16 *param_2)
{
    DbIdRecord *local_0;
    s32 local_1;
    local_0 = dbid_entrypoint_2(param_0, param_1);
    if (local_0 != NULL) {
        for (local_1 = 0; local_1 < local_0->local_1; local_1++) {
            if (local_0->local_2[local_1] == *param_2) {
                return 1;
            }
        }
    }
    return 0;
}
