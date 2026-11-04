// Probably the per-camera underwater effect: detects a submerged camera via a ray to the water
// surface, wobbles the view and draws a per-map full-screen tint.
#include "common.h"

typedef struct {
    s32 camera;
    u8 pad_4[9];
    u8 unk_D;
    u8 pad_E[2];
    f32 phase;
} State114EEC;
extern f32 func_80013970(f32);
extern s32 func_800EA068(s32);
extern s32 func_80110014(s32);
extern s32 func_80110840(s32);
extern s32 func_800A940C(s32);
extern void func_800C4B90(s32, f32, f32);
typedef struct {
    u8 pad_0[4];
    s32 table_index;
    f32 depth;
    u8 submerged, pad_D, active;
} LocalState;
typedef struct {
    u8 map, color[3], alpha;
} LocalEntry;
extern LocalEntry D_80124A50[];
extern void func_800B99CC(s32, s32, s32 *);
extern s16 D_80124A58[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
typedef struct {
    s32 camera;
    s32 pad_4;
    f32 depth;
    u8 submerged;
} State1151C4;
extern s32 func_8010FF80(s32);
extern void func_800CA7E4(s32, f32 *);
extern s32 func_800BEAAC(f32 *, f32 *);

// Underwater state: allocation, per-map table lookup, submerged detection.
// Returns the index of map_id in the per-map tint table D_80124A50.
// Matching: the line breaks in this function are needed for the match.
s32 func_80114E80(s32 map_id)
{
    u8 *entry;
    entry = (u8 *) D_80124A50; while (*entry != 0) {
        if (map_id == *entry)
        {
            return ((entry - (u8 *) D_80124A50) ^ 0) / 5; // Matching: ^ 0 needed for the match.
        }
        entry += 5;
    }

    return (entry - (u8 *) D_80124A50) / 5;
}

// Visual side: view wobble and full-screen underwater tint.
// Applies the sine-based view wobble and advances its phase.
void func_80114EEC(State114EEC *state, s32 cam)
{
    f32 wobble[3];
    wobble[0] = func_80013970(state->phase) * 1.5f;
    wobble[1] = func_80013970(state->phase * 1.5f) * 1.5f;
    if (!func_800EA068(0x20)) {
        func_800C4B90(func_800A940C(func_80110840(func_80110014(state->camera))), wobble[0],
                      wobble[1]);
        state->phase += 2.0f;
        state->unk_D = 1;
    }
}

// Draws the full-screen underwater tint.
void func_80114FA4(s32 gfx, LocalState *state)
{
    f32 frac;
    f32 fade;
    s32 i;
    s32 rgb[3];
    f32 alpha;
    if (state->submerged && state->active) {
        frac = state->depth > 3e+03f ? 1.0f : state->depth * 0.00033333333f;
        fade = frac * 0.4f;
        for (i = 0; i < 3; i++) {
            rgb[i] = (u32) D_80124A50[state->table_index].color[i] +
                               -(s32) D_80124A50[state->table_index].color[i] * fade;
        }
        alpha = (u32) D_80124A50[state->table_index].alpha;
        func_800B99CC(gfx, alpha * frac + alpha, rgb);
    }
}

// Returns whether the camera is submerged.
func_801150F0(u8 *state)
{
    return state[0xC];
}

void func_801150F8(void *state)
{
    heap_free(state);
}

// Allocates the effect state; inactive on the maps listed in D_80124A58.
u8 *func_80115118(s32 camera)
{
    s16 *excluded;
    s16 map_id;
    s32 cur_map;
    u8 *state;

    state = heap_alloc(0x14);
    *(s32 *) ((s8 *) state + 0) = camera;
    cur_map = func_800EA05C();
    *(s32 *) ((s8 *) state + 4) = func_80114E80(cur_map);
    *(s8 *) ((s8 *) state + 0xC) = 0;
    *(s8 *) ((s8 *) state + 0xD) = 0;
    *(s8 *) ((s8 *) state + 0xE) = 1;
    *(f32 *) ((s8 *) state + 0x10) = 0.0f;
    cur_map = func_800EA05C();
    map_id = (s16) cur_map;
    excluded = (s16 *) D_80124A58;
    while (*excluded != 0) {
        if (*excluded == map_id) {
            *(s8 *) ((s8 *) state + 0xE) = 0;
            break;
        }
        excluded++;
    }
    return state;
}

// Casts a ray up from the camera to decide whether it is below the water surface.
void func_801151C4(State1151C4 *state)
{
    f32 hit_pos[3];
    f32 cam_pos[3];
    f32 ray_end[3];
    f32 water_y;
    s32 hit;
    s32 cam;
    s32 unk_0;
    cam = func_8010FF80(state->camera);
    func_800CA7E4(cam, cam_pos);
    if (!func_800BEAAC(cam_pos, &water_y)) {
        func_800EFA4C(ray_end, cam_pos[0], cam_pos[1] + 1e+04f, cam_pos[2]);
        hit = func_800BEF00(cam_pos, ray_end, hit_pos, 0x1F00);
        if (hit) {
            hit = (*(u32 *) (hit + 8) & 0x20000) ? 1 : 0;
            state->submerged = hit;
        } else {
            state->submerged = 0;
        }
    } else {
        ray_end[0] = cam_pos[0];
        ray_end[2] = cam_pos[2];
        ray_end[1] = cam_pos[1] + 1000.0f;
        hit = func_800BEF00(cam_pos, ray_end, hit_pos, 0x1F00);
        if (!hit || !(*(u32 *) (hit + 8) & 0x20000))
            ray_end[1] = water_y;
        if (cam_pos[1] <= ray_end[1])
            state->submerged = 1;
        else
            state->submerged = 0;
    }
    if (state->submerged) {
        state->depth = ray_end[1] - cam_pos[1];
        func_80114EEC(state, cam);
    }
}

int func_80115324(s32 *slot, s32 state)
{
    *slot = state;
    defrag();
}

// TU-NOTE: the .data of this file (D_80124A50, D_80124A58) is defined here in C, values taken from the ROM.
// D_80124A58 is declared s16[] to match the object (uses are written as NAME[0]).
// D_80124A50: per-map tint entries {map, r, g, b, alpha}; D_80124A58: maps where the effect is off.
LocalEntry D_80124A50[1] = {0x0, 0x1E, 0x50, 0xEF, 0x20};
s16 D_80124A58[12] = {0x181, 0x1A7, 0x1A8, 0x1A9, 0xFC, 0x1A6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
