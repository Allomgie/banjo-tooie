#include "common.h"

extern void heap_free(void *);
extern s32 D_00000000;
typedef struct { char pad[0x188]; void *unk188; } BastateMem;

void bastatemem_entrypoint_0(u8 *param_0, s32 param_1) {
    (*(s32 *)((s8 *)(param_0) + (0x188))) = heap_alloc(param_1);
}

void bastatemem_entrypoint_1(BastateMem *param_0)
{
    heap_free(param_0->unk188);
    param_0->unk188 = 0;
}

void bastatemem_entrypoint_2(s32 arg0) 
{
}
void bastatemem_entrypoint_3(void *param_0)
{
    *(s32 *)((char *)param_0 + 392) = 0;
}
