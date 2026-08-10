#include "common.h"

extern void *heap_alloc();
extern void heap_free(void *ptr);
typedef struct { int unk18C; } BadRonemem;

void badronemem_entrypoint_0(void *param_0, s32 param_1)
{
    ((void **)param_0)[0x18C / 4] = heap_alloc(param_1 | 0);
}

void badronemem_entrypoint_1(BadRonemem *param_0)
{
  BadRonemem *new_var2;
  int new_var;
  int new_var3;
  new_var2++;
  new_var = 0 ^ 0;
  new_var3 = (*(s32 *)((char *)(param_0) + 396));
  heap_free(new_var3);
  new_var2 = param_0;
  new_var2--;
  (*(s32 *)((char *)(param_0) + 396)) = new_var;
}

void badronemem_entrypoint_2(s32 arg0) 
{
}
void badronemem_entrypoint_3(void *param_0)
{
    *(u32 *)((char *)param_0 + 0x18C) = 0;
}
