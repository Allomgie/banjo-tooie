#include "common.h"

extern s32 _dbzone_entrypoint_2(s32, s32, s32);
extern s32 _dbzone_entrypoint_3(s32, s32);
void glzone_entrypoint_2();

// Zone set: heap byte array [count, flag per zone].
// Creates a zone set sized from the zone count in src[0].
s32 glzone_entrypoint_0(u8 *src)
{
    u8 *set;
    set = (u8 *) heap_alloc(src[0] + 1);
    set[0] = src[0];
    glzone_entrypoint_2(set);
    return set;
}

void glzone_entrypoint_1(void *set)
{
    heap_free(set);
}

// Clears all zone flags.
void glzone_entrypoint_2(set) u8 *set;
{
    u8 *end = set + *set + 1;
    set++;

while (set < end) {
    *set++ = 0;
}

}

// Marks a zone active.
s32 glzone_entrypoint_3(u8 *set, s32 zone)
{
    set[zone] = 1;
}

s32 glzone_entrypoint_4(s32 set, s32 zone)
{
    u8 flag;
    flag = *(u8 *) (set + zone);
    return flag;

}

// Returns the zone (1-based) containing pos; keeps prev while pos is still inside it.
s32 glzone_entrypoint_5(s32 zones, s32 pos, s32 prev)
{
    if (prev != 0 && _dbzone_entrypoint_2(zones, pos, prev - 1)) {
        return prev;
    }

return _dbzone_entrypoint_3(zones, pos) + 1;
}

// Returns 1 if any of the 'count' zones in 'ids' is active.
int glzone_entrypoint_6(u8 *set, u8 *ids, s32 count)
{
    int i;

for (i = 0; i < count; i++) {
    if (set[ids[i] + 1])
        return 1;
}

return 0;
}
