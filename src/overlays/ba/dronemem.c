#include "common.h"

extern void *heap_alloc();
extern void heap_free(void *ptr);

typedef struct {
    int scratch;
} BadRonemem;

// Allocates the scratch buffer at PlayerState+0x18C.
void badronemem_entrypoint_0(void *player_state, s32 size)
{
    ((void **) player_state)[0x18C / 4] = heap_alloc(size | 0); // Matching: needed for the match.
}

// Frees the scratch buffer and clears the slot.
void badronemem_entrypoint_1(BadRonemem *player_state)
{
    int cleared;
    int buffer;
    cleared = 0 ^ 0; // Matching: needed for the match.
    buffer = *(s32 *) ((char *) player_state + 396);
    heap_free(buffer);
    *(s32 *) ((char *) player_state + 396) = cleared;
}

void badronemem_entrypoint_2(s32 arg0)
{
}

// Clears the scratch slot without freeing it.
void badronemem_entrypoint_3(void *player_state)
{
    *(u32 *) ((char *) player_state + 0x18C) = 0;
}
