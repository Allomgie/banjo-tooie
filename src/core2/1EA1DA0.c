#include "core2/1EA1DA0.h"
#include <ultra64.h>

// TU-NOTE: no <vector.h> here. vector_at is called with extra arguments in this unit,
// so the original had no prototypes for the vector functions.
typedef struct {
    s32 element_size;
} Vector;

extern u8 D_8011A9B8[];
extern u8 D_8011A938[];
extern u8 D_8011A934[];
extern u8 D_8011A930[];
extern int D_8011A9C0[];
extern void func_800EE830(s32, void *);
extern void *D_8012AB04;
extern s32 D_8012AB10;
extern void func_800EE88C();
extern s32 D_8012AB1C;
extern s32 D_8012AB28;
void *vector_begin(Vector *vec);
void *vector_end(Vector *vec);
extern u8 D_8011A9D8[];
extern u8 D_8011A9E0[];
extern u8 D_8011A9CC[];
extern void *vector_push_back();
extern f32 D_8011A9EC[];
extern f32 D_8011A9F8[];
extern u32 D_8011AA00[];
extern void func_800EE940();
extern void func_800EE814();
typedef struct {
    void *unk0[5];
    u8 unk14;
} G_C91C8;
extern G_C91C8 D_8012AB40;
extern void heap_free(void *);
extern void _gctransitionDll_entrypoint_9(void *);
extern void func_800A8BD4(int, int, int);
extern void func_800A8CCC(int, int);
extern void _gctransitionDll_entrypoint_0(void *, int);
extern s32 _gctransitionDll_entrypoint_4(s32);
typedef struct {
    f32 local_0;
    u8 local_1;
    u8 local_2[3];
    s32 local_3[6];
    u8 local_4[0x50];
} local_entry;
extern void func_800C3FF0(s32 a, f32 b);
void func_800C4244(s32, s32, s32, u8 *, f32, f32);
extern s32 func_801069A4();
typedef struct {
    Vector *local_0;
    f32 local_1;
} Struct_D_8012AB60;
extern Struct_D_8012AB60 D_8012AB60;
extern u8 *vector_at();
typedef struct {
    u32 unk0;
    f32 unk4;
    u32 unk8;
    f32 unkC[3];
    f32 unk18;
    f32 unk1C;
} S_C9C70;
extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    f32 unkC[3];
    s16 unk18;
} S_C9CD0;
extern void func_800EFD24(f32 *);
extern void func_800A54F8(void);
extern s32 func_800A5524;
extern float D_8012AB64;
typedef struct {
    f32 local_0;
    u8 local_1[0x6C];
} local_type_800CA0A8;
extern f32 func_800D8FF8(void);
extern void *rare_memcpy(void *, const void *, size_t);
void *func_800C91C8();
void func_800C9E64(f32 delay, u32 *callback, u32 arg0, u32 arg1, s32 arg2);
void func_800C9EF8(f32, s32, s32);

extern u8 *D_8012AB00;

// Maps collision flags (material bits 0x1F00, bit 17) to a surface type.
int func_800C84B0(s32 flags)
{
    __OSTranxInfo *entry;
    long is_first;
    s32 material;
    material = flags;
    material = material & 0x1F00;
    if ((flags << 14) < 0) {
        return 4;
    }
    if (material == 0) {
        return 0;
    }
    // Matching: extra temporary needed for the match.
    is_first = material == *(s32 *) &D_8011A930[0];
    entry = (__OSTranxInfo *) &D_8011A938[0];
    if (is_first) {
        return *(s32 *) &D_8011A934[0];
    }
loop_7:
    if (material == *(s32 *) ((char *) entry + 0x0)) {
        return *(s32 *) ((char *) entry + 0x4);
    }

    if (material == *(s32 *) ((char *) entry + 0x8)) {
        return *(s32 *) ((char *) entry + 0xC);
    }
    if (material == *(s32 *) ((char *) entry + 0x10)) {
        return *(s32 *) ((char *) entry + 0x14);
    }
    if (material == *(s32 *) ((char *) entry + 0x18)) {
        return *(s32 *) ((char *) entry + 0x1C);
    }
    entry = (__OSTranxInfo *) ((char *) entry + 0x20);
    if (entry == (__OSTranxInfo *) &D_8011A9B8[0]) {
        return 1;
    }
    goto loop_7;
}

s32 func_800C8560(u8 *light, s32 mask)
{
    u8 *light_alias;
    s32 dirty;
    // Matching: the copy and the comma expression are needed for the match.
    light_alias = light;
    dirty = *(u8 *) ((s8 *) (0, light_alias) + 0x16) != 0;
    if (dirty != 0) {
        return (*(u8 *) ((s8 *) light + 0x15) & mask) != 0;
    }
}

func_800C8588(u8 *light, u8 unk_0)
{
    return light[0x14];
}

int func_800C8594(u8 *light, unsigned int mask)
{
    return light[0x15] & mask;
}

// Returns the 1-based index of the first light accepted by predicate, or 0.
s32 func_800C85A0(predicate, arg) s32 (*predicate)(u32, s32);
s32 arg;
{
    u32 first;
    u32 end;
    u32 light;

    first = vector_begin(((void *) D_8012AB00));
    end = vector_end(((void *) D_8012AB00));
    light = first;

    if (light < end) {
    loop_1:
        if ((*(u8 *) ((s8 *) light + 0x15) != 0) && (predicate(light, arg) != 0) &&
            ((*(u8 *) ((s8 *) light + 0x17) != 0) || (*(u8 *) ((s8 *) light + 0x18) != 0))) {
            return ((s32) (light - first) / 28) + 1;
        }
        light += 0x1C;
        if (light >= end) {
            goto block_7;
        }
        goto loop_1;
    }

block_7:
    return 0;
}

// Like func_800C85A0, but starts with the light after start_index.
s32 func_800C8678(start_index, predicate, arg)
s32 start_index;

s32 (*predicate)(u32, s32);
s32 arg;
{
    s32 *first;
    u8 *light;
    u8 *end;

    first = vector_begin(((u8 *) D_8012AB00));
    light = vector_at(((u8 *) D_8012AB00), start_index - 1);
    end = vector_end(((u8 *) D_8012AB00));
    light += 0x1C;

    if (light < end) {
        do {
            if ((*(u8 *) ((char *) light + 0x15) != 0) && (predicate(light, arg) != 0) &&
                ((*(u8 *) ((char *) light + 0x17) != 0) ||
                 (*(u8 *) ((char *) light + 0x18) != 0))) {
                return (((s32) light - (s32) first) / 0x1C) + 1;
            }
            light += 0x1C;
        } while (light < end);
    }

    return 0;
}

void func_800C8760(s32 predicate_id)
{
    func_800C85A0(D_8011A9C0[predicate_id]);
}

int func_800C878C(s32 start_index, s32 predicate_id)
{
    func_800C8678(start_index, ((s32 *) D_8011A9C0)[predicate_id]);
}

void func_800C87B8(s32 dst)
{
    func_800EE830(dst, &D_8012AB04);
}

void func_800C87DC(s32 dst)
{
    func_800EE830(dst, &D_8012AB10);
}

s32 func_800C8800(s32 light_id, Actor **out)
{
    func_800EE88C(out, vector_at(D_8012AB00, light_id - 1));
}

// Writes the inner and outer radius of a light.
void func_800C883C(s32 light_id, f32 *out)
{
    s16 *light = vector_at(((void *) D_8012AB00), light_id - 1);
    out[0] = light[3];
    out[1] = light[4];
}

// Writes inner radius, outer radius and 1/(outer - inner) of a light.
void func_800C8898(s32 light_id, f32 *out)
{
    s16 *light;

    light = (s16 *) vector_at((void *) ((void *) D_8012AB00), light_id - 1);
    out[0] = (f32) light[3];
    out[1] = (f32) light[4];
    out[2] = *(f32 *) &light[8];
}

int func_800C8900(s32 light_id, s32 dst)
{
    u8 *light;
    light = vector_at(((u8 *) D_8012AB00), light_id - 1);

    if (!light[0x17]) {
        func_800EFA88(dst, 0, 0, 0);
    }

    else {
        func_800F2EE0(dst, light + 0xA);
    }
}

// Reads the global ambient colour and light direction.
int func_800C8960(s32 ambient_out, s32 direction_out)
{
    if (ambient_out != 0) {
        func_800EE830(ambient_out, &D_8012AB1C);
    }

    if (direction_out != 0) {
        func_800EE7F8(direction_out, &D_8012AB28);
    }
}

u8 func_800C89A8(s32 light_id)
{
    return (*(u8 *) ((char *) (vector_at(((int) D_8012AB00), light_id - 1, light_id)) + 21));
}

int func_800C89D8(s32 light_id)
{
    u8 *light = vector_at(((u8 *) D_8012AB00), light_id - 1);
    return *(u8 *) ((char *) light + 25);
}

// Clears the dirty flags of all enabled lights; state 2 disables the light.
void func_800C8A08(void)
{
    void *begin;
    void *light;
    void *end;
    // Matching: extra temporary needed for the match.
    begin = vector_begin(((void *) D_8012AB00));
    end = vector_end(((void *) D_8012AB00));
    light = begin;

    if (light < end) {
        do {
            if (*(u8 *) ((char *) light + 0x15) != 0) {
                if (*(u8 *) ((char *) light + 0x16) == 2) {
                    *(u8 *) ((char *) light + 0x15) = 0;
                } else {
                    *(u8 *) ((char *) light + 0x16) = 0;
                }
                if (*(u8 *) ((char *) light + 0x18) != 0) {
                    *(u8 *) ((char *) light + 0x18) = 0;
                }
                *(s8 *) ((char *) light + 0x19) = 0;
            }
            light = (void *) ((char *) light + 0x1C);
        } while (light < end);
    }
}

// Allocates a light (reusing a free slot) and returns its 1-based id.
s32 func_800C8A98(void)
{
    u8 *begin;
    u8 *end;
    u8 *light;
    s32 light_id;

    begin = (u8 *) vector_begin(((void *) D_8012AB00));
    end = (u8 *) vector_end(((void *) D_8012AB00));
    for (light = begin; light < end; light += 0x1c) {
        if (!light[0x15])
            break;
    }

    if (light == end) {
        light = (u8 *) vector_push_back(((void **) &D_8012AB00));
    }
    light_id = vector_index_of((void *) D_8012AB00, (void *) light) + 1;
    light[0x15] = 0xb;
    light[0x16] = light[0x17] = 1;
    light[0x14] = 0;
    light[0x18] = 0;
    light[0x19] = 0;
    func_800C8CB8(light_id, D_8011A9CC);
    func_800C8D4C(light_id, D_8011A9D8);
    func_800C8E84(light_id, D_8011A9E0);
    return light_id;
}

// Resets a light to its default values and sets state 2.
void func_800C8B84(s32 light_id)
{
    void *light;
    light = vector_at((void *) D_8012AB00, light_id - 1);
    func_800C8CB8(light_id, &D_8011A9EC);
    func_800C8D4C(light_id, &D_8011A9F8);
    func_800C8E84(light_id, &D_8011AA00);
    ((u8 *) light)[0x16] = 2;
}

s32 func_800C8BF4(void)
{
    int count;
    count = vector_size(D_8012AB00);
}

// Counts the lights whose bytes 0x14 and 0x15 are both set.
int func_800C8C18()
{
    u8 *end;
    u8 *light;
    s32 count;
    u8 *vec;
    u8 *vec_alias;
    end = vector_end((u8 *) D_8012AB00);
    count = 0;
    // Matching: extra temporary needed for the match.
    vec_alias = (u8 *) D_8012AB00;
    vec = vec_alias;
    light = vector_begin(vec);
    while (light < end) {
        if (light[21] && light[20]) {
            count++;
        }

        light += 28;
    }

    return count;
}

int func_800C8C90(s32 src)
{
    s32 value;
    // Matching: the no-op '| 0' is needed for the match.
    value = src | 0;
    func_800EE830(((s32 *) &D_8012AB04), value);
}

// Sets the light position; marks the light dirty if it changed.
void func_800C8CB8(s32 light_id, f32 pos[3])
{
    s16 *light;
    s16 new_pos[3];
    light = vector_at(((void *) D_8012AB00), light_id - 1);
    func_800EE940(new_pos, pos);
    if (light[0] != new_pos[0] || light[1] != new_pos[1] || light[2] != new_pos[2]) {
        func_800EE814(light, new_pos);
        ((u8 *) light)[0x16] = ((u8 *) light)[0x19] = 1;
    }
}

// Sets inner/outer radius and 1/(outer - inner); marks the light dirty if changed.
void func_800C8D4C(light_id, radii) s32 light_id;
f32 *radii;
{
    s32 unk_0;
    s16 new_radii[2];
    u8 *light;
    light = vector_at(((Vector *) D_8012AB00), light_id - 1);
    new_radii[0] = radii[0];
    new_radii[1] = radii[1];
    if (new_radii[1] < new_radii[0])
        new_radii[1] = new_radii[0];
    if (new_radii[1] < new_radii[0])
        new_radii[0] = new_radii[1];
    if (new_radii[0] == new_radii[1])
        new_radii[1]++;
    if (*(s16 *) (light + 6) != new_radii[0] || *(s16 *) (light + 8) != new_radii[1]) {
        *(s16 *) (light + 6) = new_radii[0];
        *(s16 *) (light + 8) = new_radii[1];
        *(f32 *) (light + 0x10) = 1.0f / (new_radii[1] - new_radii[0]);
        light[0x16] = light[0x19] = 1;
    }
}

void func_800C8E54(s32 light_id, f32 inner, f32 outer)
{
    f32 radii[2];
    radii[0] = inner;
    radii[1] = outer;
    func_800C8D4C(light_id, &radii);
}

// Sets the light colour; marks the light dirty if it changed.
void func_800C8E84(s32 light_id, u32 rgb[3])
{
    u8 *light;

    light = vector_at((u8 *) D_8012AB00, light_id - 1, rgb, light_id);
    if ((light[0xA] != rgb[0]) || (light[0xB] != rgb[1]) ||
        (light[0xC] != rgb[2])) {
        light[0xA] = (u8) rgb[0];
        light[0xB] = (u8) rgb[1];
        light[0xC] = (u8) rgb[2];
        light[0x16] = 1;
    }
}

// Sets the global ambient colour and light direction.
int func_800C8F08(s32 ambient, s32 direction)
{
    if (ambient != 0) {
        func_800EE830(&D_8012AB1C, ambient);
    }
    if (direction != 0) {
        func_800EE7F8(&D_8012AB28, direction);
        func_800EF2A0(&D_8012AB28);
    }
}

void func_800C8F64(s32 light_id, s32 flags)
{
    u8 *light;

    light = vector_at(D_8012AB00, light_id - 1, light_id);
    if (flags != (*(u8 *) ((s8 *) (light) + (0x15)))) {
        (*(u8 *) ((s8 *) (light) + (0x15))) = (u8) flags;
        (*(s8 *) ((s8 *) (light) + (0x16))) = 1;
    }
}

void func_800C8FB0(s32 light_id, u32 red, u32 green, u32 blue)
{
    u32 rgb[3];
    rgb[0] = red;
    rgb[1] = green;
    rgb[2] = blue;
    func_800C8E84(light_id, rgb);
}

int func_800C8FE0(s32 light_id, s32 value)
{
    u8 *light;
    light = vector_at(((u8 *) D_8012AB00), light_id - 1);
    if (!light[22]) {
        light[22] = light[23] != value;
    }
    light[23] = value;
    if (value == 0) {
        light[24] = 1;
    }
}

u8 func_800C9044(s32 light_id)
{
    return vector_at(((u8 *) D_8012AB00), light_id - 1)[0x17];
}

void func_800C9074()
{
    if (D_8012AB00 != 0) {
        D_8012AB00 = vector_defrag(D_8012AB00);
    }
}

void func_800C90AC()
{
    _gclightsDll_entrypoint_0(&D_8012AB00);
}

void func_800C90D0()
{
    _gclightsDll_entrypoint_1(&D_8012AB00);
}

int func_800C90F4(s32 arg)
{
    s32 arg_copy;
    // Matching: the no-op '| 0' is needed for the match.
    arg_copy = arg | 0;
    _gclightsDll_entrypoint_2(&D_8012AB00, arg_copy);
}

int func_800C911C()
{
    return (int) &D_8012AB00;
}

int func_800C9128(s32 arg)
{
    s32 arg_copy;
    // Matching: the no-op '| 0' is needed for the match.
    arg_copy = arg | 0;
    _gclightsDll_entrypoint_3(&D_8012AB00, arg_copy);
}

// Returns the transition object with this id, creating it if needed.
s32 func_800C9150(s32 id)
{
    void *transition;

    transition = func_800C91C8(id);
    if (transition == NULL) {
        transition = heap_alloc(0x34);
        bzero(transition, 0x34);
        D_8012AB40.unk0[D_8012AB40.unk14++] = transition;
        _gctransitionDll_entrypoint_8(transition, id);
    }
    return (s32) transition;
}

// Finds a transition object by id.
void *func_800C91C8(id)
s32 id;
{
    s32 i;
    for (i = 0; i < D_8012AB40.unk14; i++) {
        if (id == *(s32 *) D_8012AB40.unk0[i]) {
            return D_8012AB40.unk0[i];
        }
    }
    return 0;
}

// Frees a transition object and removes it from the list.
void func_800C9214(void *transition)
{
    s32 i;
    for (i = 0; i < D_8012AB40.unk14; i++) {
        if (transition == D_8012AB40.unk0[i]) {
            heap_free(D_8012AB40.unk0[i]);
            D_8012AB40.unk0[i] = D_8012AB40.unk0[--D_8012AB40.unk14];
            break;
        }
    }
}

void func_800C929C()
{
    D_8012AB54 = 0;
}

void func_800C92A8(void)
{
    s32 i;
    for (i = 0; i < D_8012AB40.unk14; i++) {
        _gctransitionDll_entrypoint_9(D_8012AB40.unk0[i]);
    }
}

void func_800C9310(void)
{
    while (((u8 *) &D_8012AB40)[0x14]) {
        _gctransitionDll_entrypoint_5(*(u32 *) ((u8 *) &D_8012AB40));
    }
}

// Draws every transition except the main one (id 4).
void func_800C9358(s32 param_0, s32 param_1)
{
    s32 id;
    s32 i;
    void **slot;
    if (D_8012AB54) {
        i = 0;

        // Matching: multiplication by 0 is needed for the match.
        if ((s32) D_8012AB54 > (i * 0)) {
            slot = (void **) &D_8012AB40;
            do {
                id = **(s32 **) slot;
                if (id != 4) {
                    func_800A8BD4(param_0, id, param_1);
                    _gctransitionDll_entrypoint_0(*slot, param_0);
                }
                i += 1;
                slot += 1;
            } while (i < (s32) D_8012AB54);
        }

        func_800A8CCC(param_0, param_1);
    }
}

// Draws the main transition (id 4).
void func_800C940C(s32 param_0, s32 param_1)
{
    s32 i;
    s32 id;
    if (D_8012AB54) {
        for (i = 0; i < D_8012AB54; i++) {
            id = *((s32 **) &D_8012AB40)[i];

            if (id == 4) {
                _gctransitionDll_entrypoint_0(((s32 **) &D_8012AB40)[i], param_0);
                return;
            }
        }
    }
}

// Defragments the transition objects on the heap.
void func_800C9484(void)
{
    s32 i;
    s32 **slot;
    s32 *transition;
    s32 unk_0;
    i = 0;
    if (((s32) D_8012AB54) > 0) {
        slot = ((s32 **) &D_8012AB40);
        do {
            transition = *slot;

            if (transition != 0) {
                unk_0 = *(s32 *) ((char *) transition + 0x2C);
                if (*(s32 *) ((char *) transition + 0x2C) != 0) {
                    *(s32 *) ((char *) *slot + 0x2C) =
                        func_8008AEB4(unk_0, *(s32 *) ((char *) transition + 0x2C));
                }
                *slot = defrag(*slot);
            }

            i += 1;
            slot += 1;
        } while (i < ((s32) D_8012AB54));
    }
}

s32 func_800C9510()
{
    s32 transition;
    transition = func_800C91C8(4);
    if (transition != 0) {
        // Matching: the no-op '| 0' is needed for the match.
        // Matching: the no-op '| 0' is needed for the match.
        return _gctransitionDll_entrypoint_4(transition | 0);
    }
    return 0;
}

int func_800C954C()
{
    s32 transition;
    transition = func_800C91C8(4);
    if (transition != 0) {
        // Matching: the no-op '| 0' is needed for the match.
        // Matching: the no-op '| 0' is needed for the match.
        return _gctransitionDll_entrypoint_3(transition | 0);
    }
    return 0;
}

float func_800C9588(void)
{
    return 300.0f;
}

int func_800C9598()
{
    s32 transition;
    transition = func_800C91C8(4);
    if (!transition) {
        transition = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_1(transition);
}

int func_800C95D4()
{
    s32 transition;
    transition = func_800C91C8(4);
    if (transition != 0) {
        // Matching: the no-op '| 0' is needed for the match.
        // Matching: the no-op '| 0' is needed for the match.
        return _gctransitionDll_entrypoint_2(transition | 0);
    }
    return 1;
}

int func_800C9610()
{
    s32 transition;
    transition = func_800C91C8(4);
    if (!transition) {
        transition = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_6(transition);
}

void func_800C964C(s32 param_0)
{
    s32 transition;
    transition = func_800C91C8(4);
    if (transition == 0) {
        transition = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_7(transition, param_0);
}

int func_800C968C(s32 id, s32 param_1)
{
    s32 transition;
    transition = func_800C91C8();
    if (!transition) {
        transition = func_800C9150(id);
    }
    _gctransitionDll_entrypoint_7(transition, param_1);
}

int func_800C96CC()
{
    u8 *transition;
    s32 found;
    transition = func_800C91C8();
    // Matching: the no-op '^ 0' and '| 0' are needed for the match.
    // Matching: the no-op '^ 0' and '| 0' are needed for the match.
    if (found = (transition != 0) ^ 0) {
        found = 0;
        if (transition[0xA] == transition[0x1C]) {
            return 1;
        }
        {
            return found | 0;
        }
    }
    return 0;
}

int func_800C9714()
{
    s32 transition;
    transition = func_800C91C8();
    if (transition != 0) {
        // Matching: the no-op '| 0' is needed for the match.
        // Matching: the no-op '| 0' is needed for the match.
        return _gctransitionDll_entrypoint_3(transition | 0);
    }
    return 1;
}

// Inserts a deferred call into the time-sorted queue.
int func_800C9750(f32 delay, s32 kind, s32 callback, s32 arg0, s32 arg1, s32 arg2,
                  s32 arg3, s32 arg4)
{
    local_entry *begin;
    local_entry *end;
    local_entry *entry;
    if (!D_8012AB60.local_0)
        D_8012AB60.local_0 = vector_new(sizeof(local_entry), 8);
    begin = vector_begin(D_8012AB60.local_0);
    end = vector_end(D_8012AB60.local_0);
    if (end == begin)
        D_8012AB60.local_1 = 0.0f;
    else
        delay += D_8012AB60.local_1;
    for (entry = begin; entry < end; entry++) {
        if (delay < entry->local_0)
            break;
    }
    entry = vector_insert(&D_8012AB60.local_0, entry - begin);
    entry->local_0 = delay;
    entry->local_1 = kind;
    entry->local_3[0] = callback;
    entry->local_3[1] = arg0;
    entry->local_3[2] = arg1;
    entry->local_3[3] = arg2;
    entry->local_3[4] = arg3;
    entry->local_3[5] = arg4;
}

// Runs a queued call; byte 4 is the argument count, 6 passes a pointer to the blob.
void func_800C986C(u8 *entry)
{
    switch (entry[4]) {
        case 0:
            ((void (*)()) * ((u32 *) (entry + 8)))();
            break;
        case 1:
            ((void (*)()) * ((u32 *) (entry + 8)))((u8 *) *((u32 *) (entry + 12)));
            break;
        case 2:
            ((void (*)()) * ((u32 *) (entry + 8)))((u8 *) *((u32 *) (entry + 12)),
                                                     (u8 *) *((u32 *) (entry + 16)));
            break;
        case 3:
            ((void (*)()) * ((u32 *) (entry + 8)))((u8 *) *((u32 *) (entry + 12)),
                                                     (u8 *) *((u32 *) (entry + 16)),
                                                     (u8 *) *((u32 *) (entry + 20)));
            break;
        case 4:
            ((void (*)()) * ((u32 *) (entry + 8)))(
                (u8 *) *((u32 *) (entry + 12)), (u8 *) *((u32 *) (entry + 16)),
                (u8 *) *((u32 *) (entry + 20)), (u8 *) *((u32 *) (entry + 24)));
            break;
        case 5:
            ((void (*)()) * ((u32 *) (entry + 8)))(
                (u8 *) *((u32 *) (entry + 12)), (u8 *) *((u32 *) (entry + 16)),
                (u8 *) *((u32 *) (entry + 20)), (u8 *) *((u32 *) (entry + 24)),
                (u8 *) *((u32 *) (entry + 28)));
            break;
        case 6:
            ((void (*)()) * ((u32 *) (entry + 8)))((u8 *) (entry + 0x20));
    }
}

void func_800C9974()
{
    func_800FC63C();
}

void func_800C9994()
{
    func_800FCAE0();
}

void func_800C99B4(s32 sound, s32 value_milli)
{
    s32 sound_copy;
    f32 value;
    // Matching: extra temporary needed for the match.
    sound_copy = sound;
    value = ((f32) value_milli) / 1000.0f;
    func_800C3FF0(sound_copy ^ 0, value);
}

void func_800C99F0(u8 *args)
{
    func_800C4244(*(s32 *) (args), *(s32 *) (args + 4), *(s32 *) (args + 8), args + 0xC,
                  *(float *) (args + 0x18), *(float *) (args + 0x1C));
}

void func_800C9A38(void *args)
{
    u16 unk_0;
    if (func_800EEEA8((void *) (((u32) args) + 12))) {
        _subaddiedialog_entrypoint_11(
            *(u32 *) ((char *) args + 0), *(u32 *) ((char *) args + 4),
            *(u32 *) ((char *) args + 8), 0, (s32) *(s16 *) ((char *) args + 0x18));
        return;
    }
    _subaddiedialog_entrypoint_11(*(u32 *) ((char *) args + 0), *(u32 *) ((char *) args + 4),
                                  *(u32 *) ((char *) args + 8), (u32) (((u32) args) + 12),
                                  (s32) *(s16 *) ((char *) args + 0x18));
}

int func_800C9AB0(s32 param_0)
{
    switch (param_0) {
        case 1:
            func_80090708(1);
            break;

        case 2:
            func_80090708(3);
            break;

        case 3:
            func_80090708(2);
            break;

        case 0:
            func_80090708(0);
            break;

        case 5:
            func_800A51C0();
    }
}

void func_800C9B30(s32 param_0, s32 id, s32 param_2)
{
    u8 *target;

    // Matching: reads the parameter through its stack address.
    target = *(u8 **) &param_0;
    if ((func_801069A4(target) != 0) && (id == ((u32) *(u16 *) (target + 0x12) >> 1))) {
        func_8010114C((s32) target, 0x22, param_2);
    }
}

s32 func_800C9B84(void)
{
    if (D_8012AB60.local_0) {
        vector_clear(D_8012AB60.local_0);
    }
}

void func_800C9BB4(f32 delay, s32 sound, f32 value, s32 param_3)
{
    func_800C9E64(delay, (u32 *) func_800C99B4, sound, (s32) (value * 1000.0f), param_3);
}

void func_800C9C04(f32 delay, s32 arg0, s32 arg1)
{
    func_800C9E20(delay, &func_800C9974, (u32) arg0, (u32) arg1);
}

void func_800C9C34(f32 delay, s32 arg0, s32 arg1, s32 arg2)
{
    func_800C9E64(delay, (u32 *) func_800C9994, arg0, arg1, arg2);
}

void func_800C9C70(f32 delay, u32 param_1, f32 param_2, u32 param_3, f32 *pos, f32 param_5,
                   f32 param_6)
{
    S_C9C70 args;
    args.unk0 = param_1;
    args.unk4 = param_2;
    args.unk8 = param_3;
    args.unk18 = param_5;
    args.unk1C = param_6;
    func_800EE7F8(args.unkC, pos);
    func_800C9EF8(delay, func_800C99F0, &args);
}

void func_800C9CD0(f32 delay, u32 p1, u32 p2, u32 p3, f32 *pos, s16 p5)
{
    S_C9CD0 args;
    args.unk0 = p1;
    args.unk4 = p2;
    args.unk8 = p3;
    args.unk18 = p5;
    if (pos != 0) {
        func_800EE7F8(args.unkC, pos);
    } else {
        func_800EFD24(args.unkC);
    }
    func_800C9EF8(delay, func_800C9A38, &args);
}

void func_800C9DE4(f32, s32, s32);

int func_800C9D38(f32 delay, s32 arg)
{
    // Matching: the no-op '| 0' is needed for the match.
    // Matching: the no-op '| 0' is needed for the match.
    func_800C9DE4(delay, func_800C9AB0, arg | 0);
}

int func_800C9D60(f32 delay, s32 arg)
{
    // Matching: the no-op '| 0' is needed for the match.
    // Matching: the no-op '| 0' is needed for the match.
    func_800C9DE4(delay, &func_800A54F8, arg | 0);
}

s32 func_800C9DAC(f32, s32);

void func_800C9D88(f32 delay)
{
    func_800C9DAC(delay, &func_800A5524);
}

s32 func_800C9DAC(f32 delay, s32 callback)
{
    func_800C9750(delay, 0, callback, 0, 0, 0, 0, 0);
}

void func_800C9DE4(f32 delay, s32 callback, s32 arg)
{
    func_800C9750(delay, 1, callback, arg, 0, 0, 0, 0);
}

void func_800C9E20(f32 delay, u32 *callback, u32 arg0, u32 arg1)
{
    func_800C9750(delay, 2, callback, arg0, arg1, 0, 0, 0);
}

void func_800C9E64(f32 delay, u32 *callback, u32 arg0, u32 arg1, s32 arg2)
{
    func_800C9750(delay, 3, callback, arg0, arg1, arg2, 0, 0);
}

void func_800C9EAC(f32 delay, u32 *callback, u32 arg0, u32 arg1, s32 arg2, s32 arg3)
{
    func_800C9750(delay, 4, callback, arg0, arg1, arg2, arg3, 0);
}

void func_800C9EF8(f32 delay, s32 callback, s32 data)
{
    rare_memcpy(func_800C9750(delay, 6, callback, 0, 0, 0, 0, 0) + 0x20, data, 0x50);
}

void func_800C9F48(f32 delay, u8 *target, s32 param_2)
{
    func_800C9750(delay, 3, (u32 *) func_800C9B30, *(u32 *) &target,
                  (u32) *(u16 *) ((u8 *) target + 0x12) >> 1, param_2, 0, 0);
}

int func_800C9F94()
{
    return ((int) D_8012AB60.local_0) == 0 || vector_size(((int) D_8012AB60.local_0)) == 0;
}

// Runs all remaining queued calls, then frees the queue.
int func_800C9FD0()
{
    void *first;
    u8 entry[0x70];
    if (D_8012AB60.local_0 != 0) {
        while (vector_size(D_8012AB60.local_0) > 0) {
            first = vector_begin(D_8012AB60.local_0);
            rare_memcpy(entry, first, 0x70);
            vector_erase(D_8012AB60.local_0, 0);
            func_800C986C(entry);
        }

        vector_free(D_8012AB60.local_0);
        D_8012AB60.local_0 = 0;
    }
}

// Frees the queue without running its calls.
int func_800CA060()
{
    if (D_8012AB60.local_0 != 0) {
        vector_free(D_8012AB60.local_0);
        D_8012AB60.local_0 = 0;
    }
}

void func_800CA098()
{
    D_8012AB64 = 0.0f;
}

// Advances the queue time and runs the calls that are due.
void func_800CA0A8(void)
{
    local_type_800CA0A8 *head;
    local_type_800CA0A8 entry;
    if (func_800C9F94())
        return;
    D_8012AB60.local_1 += func_800D8FF8();
    while (vector_size(D_8012AB60.local_0) > 0) {
        head = vector_begin(D_8012AB60.local_0);
        if (D_8012AB60.local_1 < head->local_0)
            break;
        rare_memcpy(&entry, head, sizeof(local_type_800CA0A8));
        vector_erase(D_8012AB60.local_0, 0);
        func_800C986C(&entry);
    }
    if (vector_size(D_8012AB60.local_0) == 0) {
        vector_free(D_8012AB60.local_0);
        D_8012AB60.local_0 = 0;
    }
}

void func_800CA174()
{
    if (((int) D_8012AB60.local_0) != 0) {
        D_8012AB60.local_0 = vector_defrag(((int) D_8012AB60.local_0));
    }
}

// TU-NOTE: the .data of this file is defined here in C, with values taken from the ROM.
// Its tables point to functions of this file; IDO's assembler schedules some of them
// differently unless the tables are in the same unit.
u8 D_8011A930[4] = {0x0, 0x0, 0x1, 0x0};
u8 D_8011A934[4] = {0x0, 0x0, 0x0, 0x1};
u8 D_8011A938[128] = {
    0x0, 0x0, 0x2,  0x0, 0x0, 0x0, 0x0, 0xA,  0x0, 0x0, 0x3,  0x0, 0x0, 0x0, 0x0, 0x9,
    0x0, 0x0, 0x4,  0x0, 0x0, 0x0, 0x0, 0x6,  0x0, 0x0, 0x5,  0x0, 0x0, 0x0, 0x0, 0x5,
    0x0, 0x0, 0x6,  0x0, 0x0, 0x0, 0x0, 0x3,  0x0, 0x0, 0x7,  0x0, 0x0, 0x0, 0x0, 0x7,
    0x0, 0x0, 0x8,  0x0, 0x0, 0x0, 0x0, 0x8,  0x0, 0x0, 0x9,  0x0, 0x0, 0x0, 0x0, 0x2,
    0x0, 0x0, 0xA,  0x0, 0x0, 0x0, 0x0, 0xB,  0x0, 0x0, 0xB,  0x0, 0x0, 0x0, 0x0, 0x10,
    0x0, 0x0, 0xC,  0x0, 0x0, 0x0, 0x0, 0x11, 0x0, 0x0, 0xD,  0x0, 0x0, 0x0, 0x0, 0x12,
    0x0, 0x0, 0xE,  0x0, 0x0, 0x0, 0x0, 0x14, 0x0, 0x0, 0xF,  0x0, 0x0, 0x0, 0x0, 0x15,
    0x0, 0x0, 0x10, 0x0, 0x0, 0x0, 0x0, 0x18, 0x0, 0x0, 0x11, 0x0, 0x0, 0x0, 0x0, 0x19};
u8 D_8011A9B8[8] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
int D_8011A9C0[3] = {(u32) func_800C8594, (u32) func_800C8588, (u32) func_800C8560};
u8 D_8011A9CC[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
u8 D_8011A9D8[8] = {0x43, 0x16, 0x0, 0x0, 0x45, 0x3B, 0x80, 0x0};
u8 D_8011A9E0[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF};
f32 D_8011A9EC[3] = {0.0f, -1.6e+04f, 0.0f};
f32 D_8011A9F8[2] = {0.0f, 1.0f};
u32 D_8011AA00[4] = {0x0, 0x0, 0x0, 0x0};
