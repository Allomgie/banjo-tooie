#include "common.h"

extern void heap_free(void *);

typedef struct {
    char pad_0[0x188];
    void *unk188;
} BastateMem;

// Allocates the per-state scratch block (pointer at PlayerState+0x188).
void bastatemem_entrypoint_0(u8 *state, s32 size)
{
    *(s32 *) ((s8 *) state + 0x188) = heap_alloc(size);
}

// Frees the scratch block and clears the pointer.
void bastatemem_entrypoint_1(BastateMem *state)
{
    heap_free(state->unk188);
    state->unk188 = 0;
}

void bastatemem_entrypoint_2(s32 arg0)
{
}

// Clears the scratch pointer without freeing.
void bastatemem_entrypoint_3(void *state)
{
    *(s32 *) ((char *) state + 392) = 0;
}

// TU-NOTE: the .data of this overlay is defined in C here (values from the ROM).
