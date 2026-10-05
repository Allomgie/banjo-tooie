#include "common.h"

struct OSIoMesgHdr { s16 cmd; s16 len; OSMesgQueue *mq; };
typedef struct { s16 field_0, field_2; } BlockLink;
typedef struct { s16 elementSize, capacity, freeHead; } LocalHeap;
typedef struct { s16 next, size; } LocalBlock;
typedef struct { s16 start, count; } LocalHandle;
typedef struct { s16 local_0; s16 local_1; } local_9;

LocalBlock * func_800B39D0(s16 *param_0, s32 param_1)
{
  int offset;
  ;
  return (((u8 *) param_0) + (param_1 * param_0[0])) + ((0, 4));
}

void func_800B39E8(u8 *param_0) {
    s16 *local_0;
    *(s16 *)(param_0 + 6) = 0;
    local_0 = (s16 *)(param_0 + 4);
    if (*(s16 *)(param_0 + 2) != 0) {
        *local_0 = 1;
        local_0 = func_800B39D0(param_0, *local_0);
        *local_0 = 0;
        local_0[1] = *(s16 *)(param_0 + 2) - 1;
    } else {
        *local_0 = 0;
    }
}

void func_800B3A40(OSMesgQueue *param_0, struct OSIoMesgHdr *param_1, s32 param_2, s32 param_3) {
    struct OSIoMesgHdr *var2;
    struct OSIoMesgHdr *var3;
    var2 = func_800B39D0(param_0, param_2);
    if (param_1->cmd == (param_2 + param_3)) {
        var3 = func_800B39D0(param_0, param_1->cmd);
        var2->cmd = var3->cmd;
        var2->len = var3->len + param_3;
    } else {
        var2->cmd = param_1->cmd;
        var2->len = param_3;
    }
    var3 = func_800B39D0(param_0, param_2 - param_1->len);
    if (var3 == param_1) {
        param_1->len += var2->len;
        param_1->cmd = var2->cmd;
    } else {
        param_1->cmd = param_2;
    }
}

void func_800B3B08(s16 *param_0, s32 param_1, s32 param_2)
{
  s16 *local_0;
  s16 *local_1;
  s16 v0;
  s32 s1;
  local_1 = param_0;
  local_0 = local_1 + 2;
  ;
  if (local_0[0] == 0)
  {
    goto end;
  }
  s1 = ((s32) param_1) + param_2;
  while (1)
  {
    if (local_0[0] >= s1)
    {
      break;
    }
    local_0 = func_800B39D0(local_1, local_0[0]);
    if (local_0[0] == 0)
    {
      break;
    }
  }

  end:
  func_800B3A40(local_1, local_0, param_1, param_2);

}

void func_800B3B8C(u8 *param_0, s16 *param_1, s16 *param_2, s32 param_3) {
    u8 *temp_v0;

    *param_2 += param_3;
    temp_v0 = func_800B39D0(param_0, *param_2);
    *(s16 *)temp_v0 = *param_1;
    *(s16 *)(temp_v0 + 2) = param_1[1] - param_3;
}

u8 *func_800B3BDC(s32 param_0, s16 *param_1) {
    u8 *temp_v0;

    temp_v0 = func_800B39D0(param_0, *param_1);
    if ((*(s16 *)((s8 *)(temp_v0) + (2))) == 1) {
        *param_1 = (*(s16 *)((s8 *)(temp_v0) + (0)));
    } else {
        func_800B3B8C(param_0, temp_v0, param_1, 1);
    }
    return temp_v0;
}

BlockLink *func_800B3C40(BlockLink **param_0, s32 param_1, s32 param_2) {
    BlockLink *local_0;
    s32 local_1;
    BlockLink *local_3;
    s32 local_4;
    BlockLink *local_2;
    local_0 = *param_0;
    local_1 = local_0->field_2;
    local_4 = local_1 + param_2;
    local_0 = heap_realloc(local_0, local_0->field_0 * local_4 + 4);
    local_0->field_2 = local_4;
    *param_0 = local_0;
    local_2 = func_800B39D0(local_0, param_1);
    local_2->field_0 = local_1;
    local_3 = func_800B39D0(local_0, local_2->field_0);
    local_3->field_0 = 0;
    local_3->field_2 = param_2;
    return local_2;
}

void *func_800B3CDC(LocalHeap **param_0, LocalHandle *param_1)
{
    s16 *local_0;
    s32 local_1;
    LocalHeap *local_2;
    s32 local_3;
    LocalBlock *local_4;
    LocalBlock *local_5;
    s32 local_7;
    LocalBlock *local_6;

    local_2 = *param_0;
    local_4 = 0;
    local_0 = &local_2->freeHead;
    if (!*local_0) { local_0 = func_800B3C40(param_0,0,10); local_2 = *param_0; }
    if (param_1->start == 0) {
        param_1->start = *local_0;
        local_4 = func_800B3BDC(local_2,local_0);
    } else {
        local_1 = param_1->start + param_1->count;
        while (*local_0) {
            if (*local_0 == local_1) break;
            local_0 = &func_800B39D0(local_2,*local_0)->next;
        }
        if (*local_0) local_4 = func_800B3BDC(local_2,local_0);
        else {
            local_1 = param_1->count + 1;
            local_7 = param_1->start;
            local_3 = 0;
            local_0 = &local_2->freeHead;
            while (*local_0) {
                local_4 = func_800B39D0(local_2,*local_0);
                if (local_4->size >= local_1) break;
                local_3 = *local_0;
                local_0 = &local_4->next;
            }
            if (!local_4 || local_4->size < local_1) {
                local_0 = func_800B3C40(param_0,local_3,local_1+5);
                local_2 = *param_0;
            }
            local_5 = func_800B39D0(local_2,*local_0);
            local_6 = func_800B39D0(local_2,param_1->start);
            param_1->start = *local_0;
            func_800B3B8C(local_2,local_5,local_0,param_1->count);
            aligned4_memcpy(local_5,local_6,param_1->count * local_2->elementSize);
            local_4 = func_800B3BDC(local_2,local_0);
            func_800B3B08(local_2,local_7,param_1->count);
        }
    }
    param_1->count++;
    return local_4;
}

void func_800B3EDC(LocalHeap **param_0, s32 param_1)
{
    s16 *local_0;
    s32 local_1;
    LocalHeap *local_2;
    s16 *local_3;

    local_2 = *param_0;
    local_1 = 0;
    local_3 = 0;
    local_0 = &local_2->freeHead;
    while (*local_0) {
        local_3 = local_0;
        local_1 = *local_0;
        local_0 = &func_800B39D0(local_2, *local_0)->next;
    }
    if (local_2->capacity == local_0[1] + local_1 && local_0[1] >= param_1) {
        local_1 = local_2->capacity - (param_1 > 0 ? param_1 : local_0[1]);
        if (param_1 == 0 || param_1 == local_0[1]) {
            *local_3 = 0;
        } else {
            local_0[1] -= param_1;
        }
        local_2 = heap_realloc(local_2, local_2->elementSize * local_1 + 4);
        local_2->capacity = local_1;
        *param_0 = local_2;
    }
}

void func_800B3FD0(u8 **param_0, local_9 *param_1, s32 param_2)
{
  s32 local_0[2];
  s16 *local_1;
  s16 *local_3;
  s16 local_4;
  int local_6;
  s32 local_7;
  u8 *local_8;
  local_8 = *param_0;
  local_0[0] = 0;
  if (param_2 == 0)
  {
    local_3 = local_8 + 4;
    local_6 = 0;
    if ((*((s16 *) (((s8 *) local_8) + 4))) != 0)
    {
      loop_2:
      local_4 = param_1->local_0;

      if (local_4 == ((*((s16 *) (((s8 *) local_3) + 2))) + local_6))
      {
        func_800B3B08(local_8, local_4, 1);
        param_1->local_0 = (s16) (param_1->local_0 + 1);
        local_0[0] = 1;
      }
      else
      {
        local_4 = *((s16 *) (((s8 *) local_3) + 0));
        local_6 = local_4;
        local_3 = func_800B39D0(local_8, local_4);
 if ((*local_3) != 0) { goto loop_2;
        }
      }
    }
  }
  if (local_0[0] == 0)
  {
    local_7 = param_1->local_1;
    local_7 -= param_2;
    local_7 -= 1;
    if (local_7 > 0)
    {
      local_1 = func_800B39D0(local_8, param_1->local_0 + param_2);
      aligned4_memcpy(local_1, func_800B39D0(local_8, (param_1->local_0 + param_2) + 1), (*((s16 *) (((s8 *) local_8) + 0))) * local_7);
 goto dummy_label_870371; dummy_label_870371: ;
    }
    func_800B3B08(local_8, (param_1->local_0 + param_1->local_1) - 1, 1);
  }
  func_800B3EDC(param_0, 0xA);
  param_1->local_1 = (s16) (param_1->local_1 - 1);
  if (param_1->local_1 == 0)
  {
    param_1->local_0 = 0;
  }
}

s32 func_800B4134(LocalHeap **param_0, LocalHandle *param_1)
{
    s16 *local_0;
    s32 local_1;
    LocalHeap *local_2;
    s16 *local_3;
    s32 local_4;

    local_2 = *param_0;
    local_3 = 0;
    local_1 = 0;
    local_0 = &local_2->freeHead;
    while (*local_0) {
        if (param_1->start == local_0[1] + local_1) {
            *local_3 = *local_0;
            local_4 = local_0[1];
            aligned4_memcpy(local_0, func_800B39D0(local_2, param_1->start), param_1->count * local_2->elementSize);
            param_1->start = local_1;
            func_800B3B08(local_2, param_1->start + param_1->count, local_4);
            return 1;
        }
        local_3 = local_0;
        local_1 = *local_0;
        local_0 = &func_800B39D0(local_2, *local_0)->next;
    }
    return 0;
}

void func_800B422C(void *param_0, s16 *param_1)
{
  u32 local_0;
  u32 local_1;
  s16 local_2;
  local_0 = *((u32 *) param_0);
  if ((local_1 = param_1[0]) != 0)
  {
    ;
    func_800B3B08(local_0, local_1, param_1[1]);
    func_800B3EDC(param_0, 10);
    param_1[1] = 0;
    param_1[0] = param_1[1];
  }
}

s32 func_800B4290(s16 *param_0){
    param_0[1] = 0;
    param_0[0] = param_0[1];
}

s32 func_800B42A0(void *param_0, s16 *param_1) {
    s16 t = *param_1;
    s32 rv;
    if (t != 0) {
        rv = func_800B39D0(param_0, t);
    } else {
        rv = 0;
    }
    return rv;
}

void func_800B42DC(void* arg0) 
{
    heap_free(arg0);
}
u8 *func_800B42FC(s32 param_0, s32 param_1)
{
    u8 *local_0;
    param_1 = param_1 + 1;
    local_0 = heap_alloc((param_0 * param_1) + 4, param_1);
    *(s16 *)local_0 = (s16)param_0;
    *(s16 *)(local_0 + 2) = (s16)param_1;
    func_800B39E8(local_0);
    return local_0;
}

void func_800B4354(s32 arg0)
{
    func_800B3EDC(arg0,0);
}

func_800B4374(s16 *param_0) {
    return param_0[2];
}
