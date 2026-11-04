// Map light set-up: parses the lights block of the map setup file into point, ambient and
// direction lights. Also has nearest-light and lights-in-range queries and a new-light helper.
#include "common.h"
#include "vector.h"

extern void *D_80800560_gclightsDll;
extern void *D_8080056C_gclightsDll;
extern void *D_80800578_gclightsDll;
extern void func_800C8C90(void *);
extern void func_800C8F08(void *, void *);
// Light list entry, 0x1C bytes.
typedef struct {
    s32 position[3];
    u8 pad_C[8];
    u8 enabled;
    u8 active;
    u8 pad_16;
    u8 visible;
    u32 pad_18;
} LightEntry29;
extern void func_800EE88C(f32 *, s32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
s32 gclightsDll_entrypoint_4();
s32 gclightsDll_entrypoint_5();

void func_80800000_gclightsDll(s32 lights)
{
    gclightsDll_entrypoint_1();
    _gclightsDll_entrypoint_0(lights);
}

// Creates the light vector and sets the default ambient and direction values.
void gclightsDll_entrypoint_0(s32 *lights)
{
    *lights = vector_new(0x1C, 1);
    func_800C8C90(&D_80800560_gclightsDll);
    gclightsDll_entrypoint_5(&D_8080056C_gclightsDll);
    func_800C8F08(&D_8080056C_gclightsDll, &D_80800578_gclightsDll);
}

int gclightsDll_entrypoint_1(void *lights)
{
    vector_free(*(void **) ((char *) lights + 0x0));
}

// Parses the lights block of the map setup stream into the light list.
void gclightsDll_entrypoint_2(s32 lights, void *stream)
{
    s32 unused_slot0; // Matching: unused local needed for the match.
    s32 *id_slot;
    Vector *ids;
    f32 position[3];
    f32 radii[2];
    s32 color[3];
    u8 flag;
    s32 id;
    s32 ambient[3];
    s32 unk_0[3];
    s32 *ids_end;
    s32 *ids_cur;
    s32 dir_color[3];
    f32 dir[3];
    s32 ignored[3];

    ids = vector_new(4, 0x10);
    func_80800000_gclightsDll(lights);
    if (!_gsmaker_entrypoint_16(stream, 0)) {
        do {
            if (_gsmaker_entrypoint_16(stream, 1) &&
                _gsmaker_entrypoint_20(stream, 2, position, 3) &&
                _gsmaker_entrypoint_20(stream, 3, radii, 2) &&
                _gsmaker_entrypoint_22(stream, 4, color, 3)) {
                id = gclightsDll_entrypoint_4();
                func_800C8CB8(id, position);
                func_800C8D4C(id, radii);
                func_800C8E84(id, color);
                if (_gsmaker_entrypoint_17(stream, 7, &flag)) {
                    func_800C8F64(id, flag);
                }
            } else if (_gsmaker_entrypoint_16(stream, 5) &&
                       _gsmaker_entrypoint_22(stream, 4, ambient, 3)) {
                func_800C8C90(ambient);
            } else if (_gsmaker_entrypoint_16(stream, 6) &&
                       _gsmaker_entrypoint_22(stream, 4, unk_0, 3)) {
                gclightsDll_entrypoint_5(unk_0);
            } else if (_gsmaker_entrypoint_16(stream, 8)) {
                id = gclightsDll_entrypoint_4();
                id_slot = vector_push_back(&ids);
                *id_slot = id;
            } else if (_gsmaker_entrypoint_16(stream, 9) &&
                       _gsmaker_entrypoint_20(stream, 2, dir, 3) &&
                       _gsmaker_entrypoint_22(stream, 4, dir_color, 3)) {
                func_800C8F08(dir_color, dir);
            } else if (_gsmaker_entrypoint_16(stream, 10)) {
                _gsmaker_entrypoint_22(stream, 4, ignored, 3);
            }
        } while (!_gsmaker_entrypoint_16(stream, 0));
    }
    ids_end = vector_end(ids);
    for (ids_cur = vector_begin(ids); ids_cur < ids_end; ids_cur++) {
        func_800C8B84(*ids_cur);
    }
    vector_free(ids);
}

// Returns the 1-based index of the nearest active light, or 0 if none.
s32 gclightsDll_entrypoint_3(Vector **lights, f32 *pos)
{
    LightEntry29 *begin;
    LightEntry29 *end;
    LightEntry29 *light;
    LightEntry29 *nearest;
    f32 dist;
    f32 nearest_dist;
    f32 light_pos[3];
    s32 index;
    begin = vector_begin(*lights);
    end = vector_end(*lights);
    nearest_dist = -1.0f;
    nearest = 0;
    for (light = begin; light < end; light++) {
        if (light->active && light->enabled && light->visible) {
            func_800EE88C(light_pos, light->position);
            dist = func_800EEAD4(pos, light_pos);
            if (!nearest || dist < nearest_dist) {
                nearest = light;
                nearest_dist = dist;
            }
        }
    }
    if (nearest)
        index = ((s32) ((u8 *) nearest - (u8 *) begin) + 0x1C) / 28;
    else
        index = 0;
    return index;
}

// Creates a new light and returns its id.
s32 gclightsDll_entrypoint_4(void)
{
    s32 *list;
    u32 entry;
    u32 end;
    s32 id;
    u8 *light;

    list = func_800C911C();
    entry = vector_begin(*list);
    end = vector_end(*list);
    if (entry < end) {
        do {
            if (*(u8 *) ((char *) entry + 0x14) == 0) {
                *(s8 *) ((char *) entry + 0x15) = 0;
            }
            entry += 0x1C;
        } while (entry < end);
    }
    id = func_800C8A98(end);
    light = vector_at(*list, id - 1);
    *(s8 *) ((char *) light + 0x14) = 1;
    *(s8 *) ((char *) light + 0x15) = 0xD;
    return id;
}

s32 gclightsDll_entrypoint_5(color)
s32 color;
{
    func_800EE830(func_800C911C() + 0x10, color);
}

// TU-NOTE: the overlay .data is defined here in C. Values are taken from the ROM.
void *D_80800560_gclightsDll = 0;
static u32 D_80800560_gclightsDll_rest[2] = {0x0, 0x0};
void *D_8080056C_gclightsDll = (void *) 0x000000FF;
static u32 D_8080056C_gclightsDll_rest[2] = {0xFF, 0xFF};
void *D_80800578_gclightsDll = 0;
static u32 D_80800578_gclightsDll_rest[5] = {0x3F800000, 0x0, 0x0, 0x0, 0x0};
