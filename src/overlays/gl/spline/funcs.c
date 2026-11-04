#include "common.h"

typedef struct {
    u8 pad_0[0x77];
    u8 unk_77_0 : 3;
    u8 unk_77_3 : 1;
    u8 unk_77_4 : 4;
} AF;
typedef struct {
    u16 pad_0;
    s16 pad_1 : 5;
    s16 path_index : 10;
    s16 pad_2 : 1;
    u8 pad_3[8];
    f32 path_t;
} SplineSpawnState;
extern void *func_80105494(Actor *);
extern Actor *func_80108474(s32, f32 *, s32);
typedef struct {
    f32 t;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 event_word;
} SplineLookupNode;
typedef struct {
    s32 count;
    SplineLookupNode nodes[1];
} SplineLookupTable;
typedef struct {
    u8 pad_0[0x186];
    s16 unk_186;
    s32 path_count;
} SplineLookupLevel;
extern SplineLookupLevel *func_800D7400(void);
extern void *func_8001B798(s32);
extern void func_800C7A68(s32, f32, f32 *);

// Finds the node with the given event id, on cur_path first, then on the other paths.
// Returns 1 and fills the outputs on success. The extra values stay -9999.0 when the node has none.
s32 glsplinefuncs_entrypoint_0(event_id, out_path, out_t, out_pos, cur_path, out_extra_a, out_extra_b)
s32 event_id;
s32 *out_path;
f32 *out_t;
f32 *out_pos;
s32 cur_path;
f32 *out_extra_a;
f32 *out_extra_b;
{
    SplineLookupLevel *level;
    s16 *path_ids;
    SplineLookupTable *table;
    f32 missing;
    SplineLookupNode *node;
    SplineLookupNode *end;
    s32 i;

    level = func_800D7400();
    path_ids = func_8001B798(level->unk_186);
    missing = -9999.0f;
    *out_extra_b = *out_extra_a = missing;
    if (cur_path != -1) {
        table = func_8001B798(path_ids[cur_path]);
        node = table->nodes;
        end = table->count + table->nodes;
        while ((node->event_word >> 21) != event_id && node < end) {
            node++;
        }
        if (node < end) {
            if ((node->unk_4 & 1) == 1) {
                if (!(node->unk_C & 1) && (node->unk_4 << 25 >> 29) == 7) {
                    *out_extra_a = node->unk_C >> 23;
                    *out_extra_b = (u32) *(u16 *) ((u8 *) node + 6) >> 7;
                }
            }
            *out_path = cur_path;
            *out_t = node->t;
            func_800C7A68(func_800D7520(cur_path), node->t, out_pos);
            return 1;
        }
    }
    for (i = 0; i < level->path_count; i++) {
        if (i != cur_path) {
            table = func_8001B798(path_ids[i]);
            node = table->nodes;
            end = table->count + table->nodes;
            while ((node->event_word >> 21) != event_id && node < end) {
                node++;
            }
            if (node < end) {
                if ((node->unk_4 & 1) == 1) {
                    if (!(node->unk_C & 1) && (node->unk_4 << 25 >> 29) == 7) {
                        *out_extra_a = node->unk_C >> 23;
                        *out_extra_b = (u32) *(u16 *) ((u8 *) node + 6) >> 7;
                    }
                }
                *out_path = i;
                *out_t = node->t;
                func_800C7A68(func_800D7520(i), node->t, out_pos);
                return 1;
            }
        }
    }
    return 0;
}

// Callback for chbaddiesetup: spawns the actor at the node and starts it on the spline.
// packed: event id in the low 12 bits, slot in bits 12-17.
void glsplinefuncs_entrypoint_1(s32 spawn_id, s32 packed, s32 path_arg)
{
    s32 id;
    // Matching: unused locals, needed for the match.
    s32 fill0;
    s32 fill1;
    s32 path_index;
    s32 slot;
    f32 t;
    f32 pos[3];
    f32 extra_a;
    f32 extra_b;
    Actor *actor;
    SplineSpawnState *state;
    s32 event_id;
    // Matching: the dead reassignments of the parameters block copy propagation.
    id = spawn_id;
    spawn_id = 0;
    // state holds the path index until the spawned actor's record is fetched.
    state = (SplineSpawnState *) path_arg;
    path_arg = 0;
    event_id = packed;
    packed = 0;
    slot = (event_id >> 12) & 0x3F;
    event_id &= 0xFFF;
    glsplinefuncs_entrypoint_0(event_id, &path_index, &t, pos, (s32) state, &extra_a,
                               &extra_b);
    actor = func_80108474(id, pos, (s32) extra_a);
    state = func_80105494(actor);
    state->path_index = path_index;
    state->path_t = t;
    actor->unk50 = extra_b;
    actor->rotation[0] = extra_b;
    ((AF *) actor)->unk_77_3 = 1;
    if (slot)
        func_800D87D4(actor, slot);
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gl/spline/funcs.data.s) is defined here in C; values taken from the ROM.
