#include "common.h"

extern s32 *heap_alloc(s32);
typedef struct { s32 pad_0; u8 *source; u8 *start; u8 *current; u8 *end; s32 mode; } MakerStream30;
extern void *heap_realloc(void *, s32);
typedef struct { u8 pad_0[0x14]; s32 state; s32 selected; } MakerSelectionState;

// void stuff() {
    
// }

int gsmaker_entrypoint_0(Actor *param_0)
{
    if (*(s32 *)((char *)param_0 + 0x14) == 2) {
        func_800D721C(*(s16 *)((char *)param_0 + 0x20), 0);
        func_800D70F8(*(s16 *)((char *)param_0 + 0x20), 0);
        func_800D6CEC(*(s16 *)((char *)param_0 + 0x20));
    }
    heap_free(param_0);
}

u8 *gsmaker_entrypoint_1(s32 param_0) {
    s32 temp_v0_2;
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x24);
    if (temp_v0 == NULL) {
        return NULL;
    }
    (*(s32 *)((s8 *)(temp_v0) + (0x14))) = 2;
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = -1;
    (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = -1;
    (*(s16 *)((s8 *)(temp_v0) + (0x20))) = (s16) param_0;
    temp_v0_2 = func_800D674C((*(s16 *)((s8 *)(temp_v0) + (0x20))));
    (*(s32 *)((s8 *)(temp_v0) + (0))) = temp_v0_2;
    (*(s32 *)((s8 *)(temp_v0) + (4))) = temp_v0_2;
    func_800D70D0(1);
    func_800D71F4(1);
    if ((*(s32 *)((s8 *)(temp_v0) + (0))) != 0) {
        return temp_v0;
    }
    heap_free(temp_v0);
    return NULL;
}

s32 gsmaker_entrypoint_2(s32 param_0) {
    gsmaker_entrypoint_1(param_0 + 0x955);
}

s32 gsmaker_entrypoint_3(s32 param_0, s32 param_1)
{
    s32 temp = param_0 + param_1;
    gsmaker_entrypoint_1(temp);
}

s32 *gsmaker_entrypoint_4(s32 param_0, s32 param_1) {
    s32 *local_0 = heap_alloc(0x24);
    local_0[5] = 3;
    local_0[6] = -1;
    local_0[7] = -1;
    local_0[2] = param_0;
    local_0[3] = param_0;
    local_0[4] = param_0 + param_1;
    return local_0;
}

u8 *gsmaker_entrypoint_5(void) {
    u8 *sp1C;
    u8 *temp_v0_2;

    sp1C = heap_alloc(0x24);
    (*(s32 *)((s8 *)sp1C + 0x14)) = 4;
    (*(s32 *)((s8 *)sp1C + 0x18)) = -1;
    (*(s32 *)((s8 *)sp1C + 0x1C)) = -1;
    temp_v0_2 = heap_alloc(0x20);
    (*(u8 **)((s8 *)sp1C + 8)) = temp_v0_2;
    (*(u8 **)((s8 *)sp1C + 0xC)) = temp_v0_2;
    (*(s32 *)((s8 *)sp1C + 0x10)) = (s32)(temp_v0_2 + 0x20);
    return sp1C;
}

void gsmaker_entrypoint_6(void *param_0, void **param_1, s32 *param_2)
{
  s32 local_0;
  local_0 = ((*((s32 *) (((char *) param_0) + 0xC))) - (*((s32 *) (((char *) param_0) + 0x8)))) & 0xFFFFFFFFFFFFFFFFu;
  *param_2 = local_0;
  *param_1 = heap_realloc(*((void **) (((char *) param_0) + 0x8)), local_0);
  *((s32 *) (((char *) param_0) + 0x8)) = 0;
  gsmaker_entrypoint_0(param_0);
}

void gsmaker_entrypoint_13();

void gsmaker_entrypoint_7(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13(arg0,arg1,0x1);
}

int gsmaker_entrypoint_8(int param_0, int param_1, int param_2)
{
  while (param_2 > 0)
  {
    gsmaker_entrypoint_7(param_0, param_1);
    param_2--;
    param_1++;
  }


}

void gsmaker_entrypoint_9(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13(arg0,arg1,0x4);
}

void gsmaker_entrypoint_10(s32 param_0, s32 param_1, s32 param_2)
{
  while (param_2 > 0)
  {
    gsmaker_entrypoint_9(param_0, param_1);
    param_2--;
    param_1 += 4;
  }


}

void gsmaker_entrypoint_11(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13(arg0,arg1,0x4);
}

s32 gsmaker_entrypoint_12(s32 param_0, s32 param_1, s32 param_2)
{
  while (param_2 > 0)
  {
    gsmaker_entrypoint_11(param_0, param_1);
    param_2--;
    param_1 += 4;
  }


}

void gsmaker_entrypoint_13(MakerStream30 *param_0, u8 *param_1, s32 param_2)
{
    s32 local_1;
    s32 local_0;
    if (param_0->mode == 2) {
        rare_memcpy(param_1, param_0->source, param_2);
        param_0->source += param_2;
    } else if (param_0->mode == 3) {
        rare_memcpy(param_1, param_0->current, param_2);
        param_0->current += param_2;
    } else if (param_0->mode == 4) {
        if (param_0->end < param_0->current + param_2) {
            local_0 = (param_0->end - param_0->start) * 2;
            local_1 = param_0->current - param_0->start;
            while (param_0->start + local_0 < param_0->current + param_2) local_0 *= 2;
            param_0->start = heap_realloc(param_0->start, local_0);
            param_0->current = param_0->start + local_1;
            param_0->end = param_0->start + local_0;
        }
        rare_memcpy(param_0->current, param_1, param_2);
        param_0->current += param_2;
    }
}

void gsmaker_entrypoint_14(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13(arg0,arg1,0x2);
}

void gsmaker_entrypoint_15(int param_0, int param_1, int param_2)
{
  while (param_2 > 0)
  {
    gsmaker_entrypoint_14(param_0, param_1);
    param_2--;
    param_1 += 2;
  }


}

s32 gsmaker_entrypoint_16(param_0, param_1) MakerSelectionState *param_0; s32 param_1;
{
    u8 local_0;
    local_0 = param_1;
    if (param_0->state == 1 || param_0->state == 4) {
        gsmaker_entrypoint_7(param_0, &local_0);
        return 1;
    }
    if (param_0->selected == -1) {
        gsmaker_entrypoint_7(param_0, &local_0);
        if (param_1 == local_0) return 1;
        param_0->selected = local_0;
        return 0;
    }
    if (param_1 == param_0->selected) {
        param_0->selected = -1;
        return 1;
    }
    return 0;
}

int gsmaker_entrypoint_17(s32 param_0, s32 param_1, s32 param_2)
{
  if (!gsmaker_entrypoint_16(param_0, param_1))
  {
    return 0;
  }
  {
    gsmaker_entrypoint_7(param_0, param_2);
    return 1;
  }

}

s32 gsmaker_entrypoint_18(enum gsworld_map_e map_id, enum gsworld_exit_e exit_id, s32 param_2, s32 param_3)
{
  s32 new_var;
  new_var = param_2;
  if (!gsmaker_entrypoint_16(map_id, exit_id, new_var, param_3))
  {
    return 0;
  }
 goto dummy_label_713969; new_var = exit_id; dummy_label_713969: ;
  gsmaker_entrypoint_8(map_id, new_var, param_3);
  return 1;
}

int gsmaker_entrypoint_19(s32 param_0, s32 param_1, s32 param_2)
{
  if (!gsmaker_entrypoint_16(param_0, param_1))
  {
    return 0;
  }
  {
    gsmaker_entrypoint_9(param_0, param_2);
    return 1;
  }

}

s32 gsmaker_entrypoint_20(enum gsworld_map_e map_id, enum gsworld_exit_e exit_id, s32 param_2, s32 param_3)
{
  s32 new_var;
  new_var = param_2;
  if (!gsmaker_entrypoint_16(map_id, exit_id, new_var, param_3))
  {
    return 0;
  }
 goto dummy_label_713969; new_var = exit_id; dummy_label_713969: ;
  gsmaker_entrypoint_10(map_id, new_var, param_3);
  return 1;
}

int gsmaker_entrypoint_21(s32 param_0, s32 param_1, s32 param_2)
{
  if (!gsmaker_entrypoint_16(param_0, param_1))
  {
    return 0;
  }
  {
    gsmaker_entrypoint_11(param_0, param_2);
    return 1;
  }

}

s32 gsmaker_entrypoint_22(enum gsworld_map_e map_id, enum gsworld_exit_e exit_id, s32 param_2, s32 param_3)
{
  s32 new_var;
  new_var = param_2;
  if (!gsmaker_entrypoint_16(map_id, exit_id, new_var, param_3))
  {
    return 0;
  }
 goto dummy_label_713969; new_var = exit_id; dummy_label_713969: ;
  gsmaker_entrypoint_12(map_id, new_var, param_3);
  return 1;
}

s32 gsmaker_entrypoint_23(enum gsworld_map_e map_id, enum gsworld_exit_e exit_id, s32 param_2, s32 param_3)
{
  s32 new_var;
  new_var = param_2;
  if (!gsmaker_entrypoint_16(map_id, exit_id, new_var, param_3))
  {
    return 0;
  }
 goto dummy_label_713969; new_var = exit_id; dummy_label_713969: ;
  gsmaker_entrypoint_13(map_id, new_var, param_3);
  return 1;
}

int gsmaker_entrypoint_24(s32 param_0, s32 param_1, s32 param_2)
{
  if (!gsmaker_entrypoint_16(param_0, param_1))
  {
    return 0;
  }
  {
    gsmaker_entrypoint_14(param_0, param_2);
    return 1;
  }

}

s32 gsmaker_entrypoint_25(enum gsworld_map_e map_id, enum gsworld_exit_e exit_id, s32 param_2, s32 param_3)
{
  s32 new_var;
  new_var = param_2;
  if (!gsmaker_entrypoint_16(map_id, exit_id, new_var, param_3))
  {
    return 0;
  }
 goto dummy_label_713969; new_var = exit_id; dummy_label_713969: ;
  gsmaker_entrypoint_15(map_id, new_var, param_3);
  return 1;
}
