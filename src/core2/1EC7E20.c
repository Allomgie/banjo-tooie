#include "common.h"

extern void *D_80127EF8;
extern void (*D_80123590[])(void *);
extern void *vector_begin();
extern void *vector_defrag(void *);
extern void *vector_end();
extern u8 D_80135483;

int func_800EE530(s32 *param_0)
{
  s32 local_0;
  local_0 = (*(s32 *)((char *)(param_0) + 44));
 dummy_label_267321: ;
  (*(s32 *)((char *)(param_0) + 44)) = defrag(*(s32 *)((char *)(param_0) + 44));
}

void func_800EE55C(Actor *param_0)
{
  unsigned long local_0;
  s32 local_1;
  s32 local_2;
 local_1 = *((s32 *) (((char *) param_0) + 0x24)); local_0 = ((s32) ((*((s32 *) (((char *) param_0) + 0x2C))) - local_1)) >> 2;
  local_2 = defrag(local_1);
  *((s32 *) (((char *) param_0) + 0x24)) = local_2;
  *((s32 *) (((char *) param_0) + 0x2C)) = (s32) (local_2 + (local_0 * 4));
}

int func_800EE5AC(s32 *param_0)
{
    s32 *local_0;
    local_0 = *(s32 **)((char *)param_0 + 0x24);
    *(s32 **)((char *)param_0 + 0x24) = defrag(local_0);
}

s32 func_800EE5D8(s32 param_0)
{
  s32 temp_v0;
  int var_a3;
  u8 *sp1C;
  u8 *temp_v0_2;
  u8 *var_v1;
  u8 *new_var;
  temp_v0 = defrag();
 do { var_a3 = temp_v0; if ((((s32 *) D_80127EF8) != 0) && (temp_v0 != param_0)) { sp1C = vector_end(((s32 *) D_80127EF8)); temp_v0_2 = vector_begin(((s32 *) D_80127EF8)); var_v1 = temp_v0_2; if (temp_v0_2 < (new_var = sp1C)) { do { if (var_v1) { } if (param_0 == (*((s32 *) var_v1))) { *((s32 *) var_v1) = var_a3; } var_v1 += 0xA8; } while (var_v1 < sp1C); } } } while (0);
  return var_a3;
}

void func_800EE670(void) {
    void (*local_3)(void *);
    void *local_0;
    void *local_1;
    void *local_2;

    if (D_80127EF8 != 0) {
        local_0 = vector_end(D_80127EF8);
        local_1 = vector_begin(D_80127EF8);
        local_2 = local_1;
        if (local_1 < local_0) {
            do {
                local_3 = D_80123590[*(u8*)((char*)local_2 + 6)];
                if (local_3 != NULL) {
                    local_3((void*)((char*)local_2 + 8));
                }
                local_2 = (void*)((char*)local_2 + 0xA8);
            } while (local_2 < local_0);
        }
        D_80127EF8 = vector_defrag(D_80127EF8);
    }
}

int func_800EE718()
{
  if (D_80135483 != 0)
  {
    _idbounce_entrypoint_6();
  }
}

int func_800EE748()
{
  if (D_80135483 != 0)
  {
    _idbounce_entrypoint_7();
  }
}
