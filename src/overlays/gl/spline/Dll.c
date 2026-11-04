#include "common.h"

typedef struct {
    s16 next;
    s16 pos[3];
    u16 has_prev : 1;
    u16 visited : 1;
    u16 is_event : 1;
    u16 unk_8_0 : 10;
    u16 unk_8_1 : 1;
    u16 unk_8_2 : 1;
    u16 unk_8_3 : 1;
    s16 id;
    u16 prop_type : 6;
    u16 unk_C : 9;
    u16 pad_0 : 1;
    u16 unk_E : 9;
    u16 unk_E1 : 5;
    u16 pad_1 : 2;
} SplineDllNode;
typedef struct {
    f32 t;
    u32 unk_4;
    u8 pad_0[3];
    u8 path_index;
    u32 unk_C;
    u32 unk_10;
} SplineDllEvent;
typedef struct {
    s32 count;
    SplineDllEvent items[];
} SplineDllEvents;
typedef struct {
    s16 start_node;
    u8 point_count;
    u8 unk_3;
    u8 unk_4;
    u8 pad_0[3];
    f32 unk_8;
    f32 unk_C;
    s16 index_handle;
    u8 pad_1[2];
    f32 points[];
} SplineDllPath;
typedef struct {
    s8 unk_0 : 1;
    s8 pad_0 : 7;
    u8 pad_1[11];
} SplineDllSlot;
typedef struct {
    u8 pad_0[0x184];
    s16 path_list;
    s16 node_list;
    s32 path_count;
    u8 pad_1[4];
    f32 unk_190;
    f32 unk_194;
    s32 script_id;
    s32 *program_offsets;
    s32 program_count;
    SplineDllSlot *slots;
    u8 unk_1A8;
} SplineDllState;
extern s32 D_80800FC0_glsplineDll[];
extern s32 func_800E6A00(void);
extern s16 func_8001B668(s32, s32);
extern void *func_8001B798(s16);
extern void *heap_alloc(s32);
extern void heap_free(void *);
extern s32 _gccubeDll_entrypoint_7(void);
extern s32 _gccubesearch_entrypoint_18(s32, s32 *, s32 *, s32 *, s32 *, s32 *, u8 **);
extern SplineDllEvent *_gccubesearch_entrypoint_17(s32, s32 *);
extern void func_800E9EE8(s32);
extern void rare_memcpy(void *, void *, s32);
extern s32 func_800D7488(s16, s16);
extern void func_800D87B0(void);
extern u8 *func_800D674C(s32);
extern SplineDllEvent *func_800D7570(s32);
extern void *func_800D7520(s32);
extern void func_800C84A4(void *, s32);
typedef struct {
    s16 map;
    s16 value;
} SplineMapRecord;
extern SplineMapRecord D_80800FC8_glsplineDll[];
extern u8 D_8012762C;
typedef struct {
    u8 pad_0[0x184];
    s16 path_list;
    s16 node_list;
    s32 path_count;
    u8 pad_18C[0xC];
    s32 script_id;
    void *program_offsets;
    s32 program_count;
    void *slots;
} SplineSet;
extern void func_8001B754();

// Decodes a spline-node prop (type 0xB) into the out values; returns 1 on success.
s32 func_80800000_glsplineDll(u32 *out_0, s32 *out_1, u32 *out_2, u32 *out_3, u32 *out_4,
                              u32 *out_5, s32 *out_ctrl, u8 *prop)
{
    s32 header;

    header = *(s32 *) ((s8 *) prop + 4);
    if (!(header & 1) && (((u32) (header << 0x19) >> 0x1A) == 0xB)) {
        *out_0 = (u32) (*(s32 *) ((s8 *) prop + 8) << 0x16) >> 0x1F;
        *out_1 = *(u8 *) ((s8 *) prop + 0xA) & 1;
        *out_2 = (u32) (*(u32 *) ((s8 *) prop + 0xC) << 0x12) >> 0x16;
        *out_3 = (u32) (*(s32 *) ((s8 *) prop + 8) << 0x12) >> 0x1F;
        *out_4 = (u32) *(u32 *) ((s8 *) prop + 0xC) >> 0x17;
        *out_5 = (u32) (*(u32 *) ((s8 *) prop + 0xC) << 9) >> 0x17;
        *out_ctrl = _gspropctrl_entrypoint_6(prop);
        return 1;
    }
    return 0;
}

// Builds all spline paths from the spline-node props of the current map.
void glsplineDll_entrypoint_0(SplineDllState *state)
{
    s32 node_count;
    s32 i;
    SplineDllNode *nodes;
    s32 j;
    s32 pos[3];
    s32 next_id;
    s32 is_event;
    s32 unk_0[3];
    s32 unk_1;
    u8 *prop;
    u32 unk_2;
    s32 unk_3;
    u32 unk_4;
    u32 unk_5;
    u32 unk_6;
    u32 unk_7;
    s32 prop_ctrl;
    s32 unused_0; // frame slot, unused
    u32 point_count;
    u32 event_count;
    s32 k;
    s32 id;
    s32 float_idx;
    SplineDllPath *path;
    SplineDllEvents *events;
    s32 *indices;
    s32 index_pos = 0;
    s16 index_handle;
    s16 path_handle;
    s16 event_handle;
    f32 *path_data;
    SplineDllEvent *cur_event;
    SplineDllEvent *other_event;
    s32 counter;
    s32 unused_1; // frame slot, unused
    SplineDllEvent tmp_event;
    SplineDllEvent *last_event;
    SplineDllEvent *event;
    SplineDllNode *node;
    s32 float_count;
    u8 *script_data;
    s32 *program;
    s32 program_idx;
    s32 unused_2; // frame filler, unused
    s32 unused_3; // frame filler, unused
    s32 unused_4;
    state->unk_1A8 = func_800E6A00();
    state->path_list = func_8001B668(0, 0);
    state->node_list = func_8001B668(0, 0);
    state->path_count = 0;
    node_count = _gccubeDll_entrypoint_7() + 1;
    if (node_count > 1) {
        nodes = heap_alloc(node_count * sizeof(SplineDllNode));
        for (i = 0; i < node_count; i++) {
            (nodes + i)->next = -1;
        }
        _gccubesearch_entrypoint_18(0, pos, &next_id, &is_event, unk_0, &unk_1, &prop);
        do {
            id = _gccubesearch_entrypoint_18(1, pos, &next_id, &is_event, unk_0,
                                                   &unk_1, &prop);
            if (id >= 0) {
                // Matching: needed for the match.
                node = (SplineDllNode *) ((s32) nodes ^ 0) + id;
                node->id = id;
                node->next = next_id;
                node->is_event = is_event;
                node->pos[0] = pos[0];
                node->pos[1] = pos[1];
                node->pos[2] = pos[2];
                if (func_80800000_glsplineDll(&unk_2, &unk_3, &unk_4, &unk_5, &unk_6,
                                              &unk_7, &prop_ctrl, prop)) {
                    node->prop_type = 11;
                    node->unk_8_2 = unk_2;
                    node->unk_8_3 = unk_3;
                    node->unk_8_0 = unk_4;
                    node->unk_8_1 = unk_5;
                    node->unk_C = unk_6;
                    node->unk_E = unk_7;
                    node->unk_E1 = prop_ctrl;
                } else {
                    node->prop_type = 0;
                }
            }
        } while (id >= 0);
        for (i = 1; i < node_count; i++) {
            (nodes + i)->has_prev = 0;
            if ((nodes + i)->next >= node_count || (nodes + i)->next == -1) {
                (nodes + i)->next = 0;
            }
        }
        for (i = 1; i < node_count; i++) {
            if ((nodes + i)->next > 0) {
                (nodes + (nodes + i)->next)->has_prev = 1;
            }
        }
        for (i = 1; i < node_count; i++) {
            if ((nodes + i)->is_event == 1 &&
                ((nodes + i)->has_prev != 0 || (nodes + i)->next <= 0) &&
                ((nodes + i)->has_prev != 1 || (nodes + i)->next <= 0) &&
                ((nodes + i)->has_prev != 1 || (nodes + i)->next != 0)) {
                func_800E9EE8(i);
                (nodes + i)->next = -1;
                (nodes + i)->is_event = 0;
            }
        }
        for (i = 1; i < node_count; i++) {
            if ((nodes + i)->next > 0 && (nodes + i)->has_prev == 0 &&
                (nodes + i)->is_event == 0) {
                k = 1;
                float_idx = 5;
                point_count = 1;
                event_count = 0;
                index_pos = 0;
                for (; k < node_count; k++) {
                    (nodes + k)->visited = 0;
                }
                for (k = i;
                     (nodes + k)->next != 0 && !(nodes + k)->visited;
                     k = (nodes + k)->next) {
                    (nodes + k)->visited = 1;
                    point_count += (nodes + k)->is_event == 0 ? 1 : 0;
                    event_count += (nodes + k)->is_event == 0 ? 0 : 1;
                    // Matching: empty blocks steer IDO's register allocation.
                    if (state) {
                    }
                    if (1) {
                    }
                }
                index_handle = func_8001B668(0, point_count * sizeof(s32));
                unused_4 = state->path_count;
                k = i;
                indices = func_8001B798(index_handle);
                float_count = point_count * 3;
                path_handle = func_8001B668(0, 0x14 + float_count * sizeof(f32));
                path = func_8001B798(path_handle);
                path_data = (f32 *) path;
                path->point_count = point_count;
                path->unk_3 = 0;
                path->unk_8 = 0.0f;
                // Matching: empty block steers IDO's register allocation.
                if (unused_4) {
                }
                path->unk_C = 0.0f;
                event_handle = func_8001B668(0, 4 + event_count * sizeof(SplineDllEvent));
                events = func_8001B798(event_handle);
                events->count = event_count;
                other_event = events->items;
                j = i;
                counter = events->count;
                for (; counter != 0; j = (nodes + j)->next) {
                    if ((nodes + j)->is_event == 1) {
                        event = _gccubesearch_entrypoint_17(j, 0);
                        event->path_index = state->path_count;
                        rare_memcpy(other_event, event, sizeof(SplineDllEvent));
                        other_event++;
                        counter--;
                    }
                }
                last_event = events->count - 1 + events->items;
                do {
                    counter = 0;
                    for (cur_event = events->items; cur_event < last_event; cur_event++) {
                        other_event = cur_event + 1;
                        if (cur_event->t > other_event->t) {
                            rare_memcpy(&tmp_event, cur_event, sizeof(SplineDllEvent));
                            rare_memcpy(cur_event, other_event, sizeof(SplineDllEvent));
                            rare_memcpy(other_event, &tmp_event, sizeof(SplineDllEvent));
                            counter++;
                        }
                    }
                } while (counter);
                path->start_node = (nodes + i)->id;
                path->unk_4 = state->unk_1A8;
                path->index_handle = index_handle;
                for (j = point_count; j != 0; k = (nodes + k)->next) {
                    if (!(nodes + k)->is_event) {
                        path_data[float_idx] = (nodes + k)->pos[0];
                        path_data[float_idx + 1] = (nodes + k)->pos[1];
                        path_data[float_idx + 2] = (nodes + k)->pos[2];
                        float_idx += 3;
                        j--;
                        indices[index_pos++] = (nodes + k)->id;
                    }
                }
                func_800D7488(path_handle, event_handle);
            }
        }
        heap_free(nodes);
    }
    state->script_id = 0;
    state->program_offsets = 0;
    state->program_count = 0;
    state->unk_190 = 0;
    state->unk_194 = 0;
    func_800D87B0();
    if (state->program_offsets != 0) {
        script_data = func_800D674C(state->script_id);
        for (i = 0; i < state->path_count; i++) {
            event = func_800D7570(i);
            if (event && (event->unk_4 & 1) && (event->unk_C & 1) &&
                *(u8 *) &event->unk_C) {
                program_idx = *(u8 *) &event->unk_C - 1;
                program = (s32 *) (state->program_offsets[program_idx] + script_data);
                if (program[1] == D_80800FC0_glsplineDll[0] &&
                    program[2] == D_80800FC0_glsplineDll[1]) {
                    func_800C84A4(func_800D7520(i), 1);
                }
            }
        }
    }
    state->slots = heap_alloc(7 * sizeof(SplineDllSlot));
    for (j = 0; j < 7; j++) {
        state->slots[j].unk_0 = 0;
    }
}

// Returns the spline-script asset id for the current map.
s32 func_80800C70_glsplineDll(void)
{
    s32 i = 0;

    while (D_8012762C != D_80800FC8_glsplineDll[i].map &&
           D_80800FC8_glsplineDll[i].map != -1) {
        i++;
    }
    return D_80800FC8_glsplineDll[i].value;
}

// Frees all paths and script data.
void glsplineDll_entrypoint_1(SplineSet *set)
{
    s16 *node_handles;
    s16 *path_handles;
    s32 i;

    path_handles = func_8001B798(set->path_list);
    node_handles = func_8001B798(set->node_list);
    for (i = 0; i < set->path_count; i++) {
        func_8001B754(((s16 *) func_8001B798(path_handles[i]))[8]);
        func_8001B754(path_handles[i]);
        func_8001B754(node_handles[i]);
    }
    func_8001B754(set->path_list);
    func_8001B754(set->node_list);
    set->path_list = 0;
    set->node_list = 0;
    heap_free(set->slots);
    set->path_count = 0;
    set->slots = NULL;
    set->script_id = 0;
    heap_free(set->program_offsets);
    set->program_offsets = NULL;
    set->program_count = 0;
}

// Loads the map's spline-script asset, indexes its programs and sets up the two
// 128-byte script variable tables.
void glsplineDll_entrypoint_2(u8 *set)
{
    s32 addr;
    s32 *script;
    s32 state;
    s32 n;
    s32 word;
    s32 *cursor;
    // Matching: constants held in locals for the match.
    s32 k2 = 2;
    s32 k5 = 0x10005;
    s32 k6 = 0x10006;
    word = func_80800C70_glsplineDll();
    if (word) {
        *(s32 *) (set + 0x198) = word;
        script = func_800D674C(word);
        *(s32 *) (set + 0x1A0) = 0;
        for (state = 0, addr = (s32) script; state != 3; addr += 4) {
            if (state == 2) {
                state = *(s32 *) addr == 3 ? 3 : 0;
            }
            word = *(s32 *) addr;
            if (state == 1) {
                state = k2 == word ? 2 : 0;
            }
            if (state == 0) {
                state = word == 0 ? 1 : 0;
            }
            if (k5 == word || k6 == word) {
                (*(s32 *) (set + 0x1A0))++;
            }
        }
        *(s32 **) (set + 0x19C) = heap_alloc(*(s32 *) (set + 0x1A0) * 4);
        cursor = script;
        state = 4;
        for (n = 0, addr = 0; state != 3; addr += 4) {
            if (state == 2) {
                state = *cursor == 3 ? 3 : *cursor == 0x10005 || *cursor == 0x10006 ? 4 : 0;
            }
            if (state == 1) {
                state = *cursor == 2 ? 2 : 0;
            }
            if (state == 0) {
                state = *cursor == 0 ? 1 : 0;
            }
            cursor++;
            if (state == 4) {
                state = 0;
                (*(s32 **) (set + 0x19C))[n++] = addr;
            }
        }
        // Matching: empty block steers IDO's register allocation.
        if (script) {
        }
        while (*cursor != 4) {
            set[(*cursor >> 16) & 0x7F] = *cursor & 0xFF;
            set[0x80 + ((*cursor >> 16) & 0x7F)] = *cursor & 0xFF;
            cursor++;
        }
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
s32 D_80800FC0_glsplineDll[2] = {0x0, 0x2D0001};
SplineMapRecord D_80800FC8_glsplineDll[26] = {
    0xD,  0xAFF, 0x3,  0x0,  0xA,  0x0,  0x7,  0x0, 0x2,  0x0, 0x1,  0x0,  0x4,
    0x0,  0xF,   0x0,  0x5,  0x0,  0x10, 0x0,  0x6, 0x0,  0xC, 0x0,  0x12, 0x0,
    0x13, 0x0,   0x14, 0x0,  0x15, 0x0,  0x16, 0x0, 0x17, 0x0, 0x18, 0x0,  0x19,
    0x0,  0x1A,  0x0,  0x11, 0x0,  -0x1, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0};
