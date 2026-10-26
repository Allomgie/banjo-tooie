#include "common.h"

typedef struct { Unk80132ED0 *marker; s32 id; } BaddieLink1425;
typedef struct { u8 pad_0[0x12]; u16 id; } BaddieMarker1425;
extern Actor *func_80106790(Unk80132ED0 *);
extern int _subaddiefind_entrypoint_8();

void subaddielink_entrypoint_0(param_0) void *param_0;
{
  s32 *new_var;
  *((s32 *) (((u8 *) param_0) + 4)) = 0;
  new_var = (s32 *) (((u8 *) param_0) + 4);
  *new_var = 0;
  new_var = (u8 *) param_0;
  *((s32 *) (new_var + 1)) = 0;
  *((s32 *) (new_var + 0)) = 0;
}

void subaddielink_entrypoint_1(u8 *param_0, u8 *param_1)
{
  u16 temp;
  u32 temp2;
  long new_var;
  if (param_1 != 0)
  {
    new_var = *((u16 *) (param_1 + 0x12));
    temp = new_var;
    *((u8 **) param_0) = param_1;
    temp2 = temp;
    temp2 = temp2 >> 1;
    *((u32 *) (param_0 + 4)) = temp2;
    return;
  }
  subaddielink_entrypoint_0();
}

int subaddielink_entrypoint_2(BaddieLink1425 *param_0)
{
    if (param_0->marker) {
        if (param_0->id == ((u32)((BaddieMarker1425 *)param_0->marker)->id >> 1) &&
            !func_80106790(param_0->marker)->unk64_17) {
            return 1;
        }
        param_0->marker = NULL;
        param_0->id = 0;
    }
    return 0;
}

int subaddielink_entrypoint_3(void *param_0)
{
  void *local_0;
  char *new_var;
  new_var = (char *) param_0;
  local_0 = *((void **) (new_var + 4));
  *((void **) (new_var + 0)) = 0;
  new_var = new_var;
  new_var = new_var + 0;
  if (local_0 != 0)
  {
    local_0 = _subaddiefind_entrypoint_8(local_0);
    if (local_0 != 0)
    {
      *((void **) new_var) = *((void **) local_0);
    }
  }
  return (*((void **) new_var)) != 0;
 goto dummy_label_606071; dummy_label_606071: ;
}

s32 subaddielink_entrypoint_4(ALLink *param_0) {
    if (!subaddielink_entrypoint_2(param_0)) {
        return 0;
    } else {
        func_80106790(param_0->next);
    }
}

s32 subaddielink_entrypoint_5(s32 src[2], s32 dst[2]){
    dst[0] = src[0];
    dst[1] = src[1];
}
