#include "memory.h"

extern int heap_largest_free();
extern int heap_bytes_free();

struct HeapBlock_8001BDAC { struct HeapBlock_8001BDAC *prev; struct HeapBlock_8001BDAC *next; int field8; int fieldC; struct HeapBlock_8001BDAC *prev_free; };
struct HeapHeader_8001BE94 { struct HeapHeader_8001BE94 *prev; struct HeapHeader_8001BE94 *next; int field8; unsigned int allocation_overhead : 24; unsigned int state : 2; unsigned int fieldC_26 : 2; unsigned int fieldC_28 : 1; unsigned int fieldC_29 : 1; unsigned int fieldC_30 : 2; };
typedef struct Struct8001BF80 Struct8001BF80;
struct Struct8001BF80 { Struct8001BF80 *local_0; Struct8001BF80 *local_4; signed int local_8; unsigned int local_C; Struct8001BF80 *local_10; Struct8001BF80 *local_14; long long local_18; };
typedef struct Struct8001C0A0 Struct8001C0A0;
struct Struct8001C0A0 { Struct8001C0A0 *local_0; Struct8001C0A0 *local_4; signed int local_8; unsigned int local_C_0 : 24; unsigned int local_C_24 : 2; unsigned int local_C_26 : 6; };

// round_up_16
u32 func_8001BD30(u32 param_0)
{
    return (param_0 & 0xF) ? (param_0 - (param_0 & 0xF) + 0x10) : param_0;
}

int func_8001BD50(float param_0)
{
    int local_0;
    int local_1;
    heap_largest_free(&local_0);

    return local_0 < param_0 * heap_bytes_free();
}

int func_8001BDAC(int *param_0, int param_1)
{
    struct HeapBlock_8001BDAC *local_0;

    local_0 = (struct HeapBlock_8001BDAC *)(D_8007E990 + heap_bytes_allocated() - 0x20);
    for (; param_1 != 0; param_1--) {
        local_0 = local_0->prev_free;
        if (local_0 == (struct HeapBlock_8001BDAC *)D_8007E990) {
            return 0;
        }
    }

    *param_0 = (char *)local_0->next - (char *)local_0 - 0x10;
    return (int)((char *)local_0 + 0x10);
}

signed int func_8001BE94(signed int param_0)
{
  struct HeapHeader_8001BE94 *local_0;
  signed int local_1;
  unsigned int local_2;
  signed int local_3;
  local_0 = *((struct HeapHeader_8001BE94 **) ((D_8007E990 + heap_bytes_allocated()) - 0x20));
  if (param_0 > 0)
  {
    local_3 = param_0;
  }
  else
  {
    local_3 = 1;
  }
  local_2 = func_8001BD30(local_3);
  if ((((unsigned int) ((((char *) local_0->next) - ((char *) local_0)) - 0x10)) < local_2) || (local_0->state != 0))
  {
    local_1 = (signed int) D_8007E990;
    while (((signed int) local_0->prev) != local_1)
    {
      local_0 = local_0->prev;
      if ((((unsigned int) ((((char *) local_0->next) - ((char *) local_0)) - 0x10)) >= local_2) && (local_0->state == 0))
      {
        break;
      }
    }

  }
  if (local_0->state != 0)
  {
    return 0;
  }
  if ((local_1 = (unsigned int) ((((char *) local_0->next) - ((char *) local_0)) - 0x10)) < local_2)
  {
    return 0;
  }
  return (signed int) local_0;
}

signed int func_8001BF80(param_0) signed int param_0;
{
    Struct8001BF80 *local_0;
    unsigned int local_1;
    signed int local_2;

    local_0 = ((Struct8001BF80 *)D_8007E990)->local_14;
    if (param_0 > 0) {
        local_2 = param_0;
    } else {
        local_2 = 1;
    }
    local_1 = func_8001BD30(local_2);
    if ((unsigned int)((char *)local_0->local_4 - (char *)local_0 - 0x10) < local_1) {
        while ((char *)local_0->local_14 + 0x20 != D_8007E990 + heap_bytes_allocated()) {
            local_0 = local_0->local_14;
            if ((unsigned int)((char *)local_0->local_4 - (char *)local_0 - 0x10) >= local_1) {
                break;
            }
        }
    }
    local_2 = (unsigned int)((char *)local_0->local_4 - (char *)local_0 - 0x10) < local_1 ? 0 : (signed int)local_0;
    return local_2;
}

int func_8001C070()
{
  int local_0;
  if (func_8001BF80())
  {
    local_0 = 1;
  }
  else
  {
    local_0 = 0;
  }
  return local_0 | 0;
}

Struct8001C0A0 *func_8001C0A0(signed int param_0)
{
    Struct8001C0A0 *local_0;
    unsigned int local_1;
    signed int local_2;

    local_0 = ((Struct8001C0A0 *)D_8007E990)->local_4;
    if (param_0 > 0) {
        local_2 = param_0;
    } else {
        local_2 = 1;
    }
    local_1 = func_8001BD30(local_2);
    if ((unsigned int)((char *)local_0->local_4 - (char *)local_0 - 0x10) < local_1 ||
        local_0->local_C_24 != 0) {
        while ((char *)local_0->local_4 + 0x20 != D_8007E990 + heap_bytes_allocated()) {
            local_0 = local_0->local_4;
            if ((unsigned int)((char *)local_0->local_4 - (char *)local_0 - 0x10) >= local_1 &&
                local_0->local_C_24 == 0) {
                break;
            }
        }
    }
    if (local_0->local_C_24 != 0) {
        return 0;
    }
    if ((unsigned int)((char *)local_0->local_4 - (char *)local_0 - 0x10) < local_1) {
        return 0;
    }
    return local_0;
}
