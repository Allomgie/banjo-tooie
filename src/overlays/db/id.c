#include "common.h"

// Vertex-id group section: s16 group count, then records {id, count, indices[count]}.
typedef struct {
    s16 id;
    s16 count;
    s16 indices[1];
} DbIdRecord;

// Count the contiguous index runs of group `id`; 0 if there is no such group.
s32 dbid_entrypoint_0(s16 *groups, s32 id)
{
    s32 i;
    s32 j;
    s32 runs;
    s16 *group;

    group = groups + 1;
    for (i = 0; i < groups[0]; i++) {
        if (group[0] == id) {
            runs = 0;
            for (j = 1; j < group[1]; j++) {
                if (group[j + 2] != group[j + 1] + 1) {
                    runs++;
                }
            }
            return runs + 1;
        }
        group += group[1];
        group += 2;
    }
    return 0;
}

// Total index count over all groups.
int dbid_entrypoint_1(s16 *groups)
{
    s16 count;
    s32 i;
    s32 total;
    u8 *rec;
    total = 0;
    rec = (u8 *) groups + 2;
    i = 0;
    if (*groups > 0) {
        do {
            count = *(s16 *) ((s8 *) rec + 2);
            i += 1;
            rec = (u8 *) (((s8 *) rec + (count * 2)) + 4);
            total += count;
        } while (i < *groups);
    }
    return total;
}

// Find the group with the given id; 0 if missing.
s16 *dbid_entrypoint_2(s16 *groups, s32 id)
{
    s32 i;
    s16 *group = groups + 1;
    for (i = 0; i < *groups; i++) {
        if (group[0] == id) {
            return group;
        }
        group += group[1];
        group += 2;
    }
    return 0;
}

// Is the vertex index in group `id`?
s32 dbid_entrypoint_3(void *groups, s32 id, u16 *vertex)
{
    DbIdRecord *group;
    s32 i;
    group = dbid_entrypoint_2(groups, id);
    if (group != NULL) {
        for (i = 0; i < group->count; i++) {
            if (group->indices[i] == *vertex) {
                return 1;
            }
        }
    }
    return 0;
}
