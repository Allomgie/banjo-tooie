// Map model manager: draws the opaque and translucent map layers, exposes layer state and bounds,
// and implements the global map collision queries combined with the map sections overlay.
#include "common.h"

extern f32 func_800DC178(f32, f32);
typedef struct {
    s32 collision, unk_4, unk_8, model;
    s32 vertex_sets[2];
    s32 unk_18, unk_1C, unk_20, unk_24;
    u8 unk_28, vertex_idx, collision_on, visible;
} MapRecord;
typedef struct {
    MapRecord record[2];
    u8 pad_58[0x1F];
    u8 sections_on;
    u8 pad_78[13];
    u8 env_r, env_g, env_b;
    u8 pad_88[0x128];
    s32 hit_model;
} MapState;
void func_800DF428(float param_0);
extern void _gcmapsects_entrypoint_17(s32 *);
extern s32 D_801285B4[];
extern u8 D_80128627;
extern int D_801285BC[];
typedef struct {
    u8 pad0[0x14];
    void *unk14;
    u8 pad18[0x14];
} E_BEB98;
extern int D_801285D0[];
extern s32 D_80128734;
extern s32 D_80128730;
extern s32 D_8012873C;
extern s32 D_80128748;
extern s32 D_80128754;
extern void func_800EFD24(f32 *);
extern int func_800AD2C8(s32, s32, s32, s32, f32 *, s32, s32, f32);
extern int _gcmapsects_entrypoint_20(void *, s32, s32, s32, s32, f32);
extern s32 func_800AD894(s32, s32, s32, s32, s32, s32 *, f32);
extern s32 _gcmapsects_entrypoint_21(s32 *, s32, s32, s32, f32);
extern s32 func_800AC638(s32, s32, s32, s32, f32, s32, s32, s32);
extern s32 _gcmapsects_entrypoint_23(void *, s32, s32, f32, s32, s32, s32);
extern void _gcmapDll_entrypoint_3(void *);
extern void func_800C6A28(void *, void *, void *, void *);
typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0x23];
    u8 unk2B;
} E_BF4DC;
extern void _idworldmake_entrypoint_6(s32, s32, s32);
void *func_800DC060(void *);
void *func_800EE5D8(void *);
void *func_800F9F90(void *, void *);
void *defrag(void *);
extern u8 D_80128634;
extern int _gcmapsects_entrypoint_24();
extern s32 _dbvpl_entrypoint_0(s32, s32);
int func_800BECE0();
s32 func_800BEF00();
void func_800BF774();

typedef struct {
    u8 pad_0[4];
    void *unk_4;
    void *unk_8;
    u8 pad_C[0xc];
    void *unk_18;
    void *unk_1C;
    u8 pad_20[0x10];
    void *unk_30;
    void *unk_34;
    u8 pad_38[0xc];
    void *unk_44;
    void *unk_48;
    u8 pad_4C[0x1c];
    void *unk_68;
    u8 pad_6C[0xb];
    u8 unk_77;
    u8 pad_78[0x100];
    void *unk_178;
    void *unk_17C;
    void *unk_180;
} D_801285B0_unk;

// TU-NOTE: D_801285B0 is reached through several views (MapState, flat byte/word
// arrays, D_801285B0_unk) so IDO emits the original addressing.
typedef union {
    MapState MapState;
    D_801285B0_unk D_801285B0_unk;
    s32 raw;
    struct {
        struct {
            s32 words[11];
        } rec[3];
        s8 unk_84;
    } BF8E4;
    s8 b[1];
    u8 u[1];
} Union_D_801285B0;
extern Union_D_801285B0 D_801285B0;
extern s32 D_80128728;
extern s32 D_8012872C;
extern s32 D_80128760;

// Group: map geometry collision queries (floor probe, ray hit, sphere tests, provider setup).
// Probes the floor below pos with jittered rays up to 51000 units down; returns its y.
f32 func_800BE600(f32 *pos, s32 flags)
{
    s32 unk_0;
    f32 hit[3];
    f32 ray_start[3];
    f32 ray_end[3];
    s32 y_up, y_down, unk_1;
    ray_start[0] = pos[0];
    ray_start[1] = pos[1];
    ray_start[2] = pos[2];
    ray_start[1] += 200.0f;
    ray_end[0] = pos[0];
    ray_end[1] = pos[1];
    ray_end[2] = pos[2];
    ray_end[1] -= 2000.0f;
    if (func_800BEF00(ray_start, ray_end, hit, flags))
        return ray_end[1];
    for (y_up = 150, y_down = 1000; y_down < 51000; y_up += 300, y_down += 2000) {
        ray_start[0] = pos[0];
        ray_start[1] = pos[1];
        ray_start[2] = pos[2];
        ray_start[0] += func_800DC178(-1.0f, 1.0f);
        ray_start[1] += y_up;
        ray_start[2] += func_800DC178(-1.0f, 1.0f);
        ray_end[0] = pos[0];
        ray_end[1] = pos[1];
        ray_end[2] = pos[2];
        ray_end[0] += func_800DC178(-1.0f, 1.0f);
        ray_end[1] -= y_down;
        ray_end[2] += func_800DC178(-1.0f, 1.0f);
        if (func_800BEF00(ray_start, ray_end, hit, flags))
            return ray_end[1];
    }
    return 0.0f;
}

// Group: map model state and rendering (layer draw, getters, flags, bounds, hooks, defrag).
// Draws one map layer (0 opaque, 1 translucent) and flips its vertex set.
void func_800BE7F8(s32 actor, s32 layer)
{
    s32 layer_id;
    s32 hook;
    s32 unk_0;
    s32 base;
    MapRecord *rec;

    rec = &D_801285B0.MapState.record[layer];
    if ((rec->model != 0) && (rec->visible != 0)) {
        func_800BF774();
        func_800DF738(D_80128728);
        if (rec == &D_801285B0.MapState.record[0]) {
            func_800DF83C(D_8012872C);
        }
        if (rec != &D_801285B0.MapState.record[0]) {
            layer_id = 2;
        } else {
            layer_id = 1;
        }
        func_800DF830(layer_id);
        unk_0 = rec->unk_28;
        if (unk_0 != 0) {
            func_800DF7E8(unk_0);
        }
        // Matching: base goes through an s32 cast.
        base = (s32) (MapState *) &D_801285B0.raw;
        func_800DF5D8(*(u8 *) (base + 0x85), *(u8 *) (base + 0x86), *(u8 *) (base + 0x87),
                      0xFF);
        func_800DF7DC(rec->unk_24);
        func_800DF818(rec->vertex_sets[rec->vertex_idx]);
        func_800DF428(29999.0f);
        func_800DF440(0);
        func_800DF4B0(1);
        func_800DE448(0, 0, 0x3F800000, 0, rec->model);
        hook = rec->unk_1C;
        if (hook != 0) {
            _vpmodule_entrypoint_3(hook, rec->unk_18,
                                   rec->vertex_sets[rec->vertex_idx]);
        }
        if ((rec->vertex_sets[1] != 0) && (func_800EA340() != 0)) {
            if (rec->unk_4 != 0) {
                _glid_entrypoint_6(rec->unk_4, rec->vertex_sets[rec->vertex_idx]);
            }
            rec->vertex_idx ^= 1;
            if (rec->unk_4 != 0) {
                _glid_entrypoint_5(rec->unk_4, rec->vertex_sets[rec->vertex_idx]);
            }
        }
    }
}

// Matching: the (unsigned char) (s8 *) casts below are needed for the match.
void func_800BE9B0()
{
    if ((unsigned char) (s8 *) D_801285B0.u[0x77]) {
        _gcmapsects_entrypoint_17(D_801285B0.u);
    }
}

// Draws the opaque layer, then the map-sections overlay.
s32 func_800BE9E4(Actor *this)
{
    func_800BE7F8(this, 0);
    if ((unsigned char) *(u8 *) ((char *) (int *) &D_801285B0.raw + 119)) {
        _gcmapsects_entrypoint_18((int *) &D_801285B0.raw, this);
    }
}

// Draws the translucent layer, then the map-sections overlay.
int func_800BEA24(Actor *actor)
{
    func_800BE7F8(actor, 1);
    if (((u8 *) (int *) &D_801285B0.raw)[0x77] != 0) {
        _gcmapsects_entrypoint_19((int *) &D_801285B0.raw, actor);
    }
}

void func_800BEA64(s32 pos)
{
    func_800BE600(pos, 0x20020);
}

// Collision data of a layer.
s32 func_800BEA88(s32 layer)
{
    return *(s32 *) ((char *) D_801285B4 + layer * 0x2C);
}

int func_800BEAAC(u32 arg0, u32 arg1)
{
    if (D_80128627 != 0) {
        // Matching: x | x is needed for the match.
        return _gcmapsects_entrypoint_6(&D_801285B0.raw, arg0 | arg0, arg1 | arg1);
    }
    return 0;
}

void func_800BEAF4()
{
    if (((u8 *) &D_801285B0.raw)[0x77]) {
        _gcmapsects_entrypoint_8(D_801285B0.u);
    }
}

s32 func_800BEB28(s32 layer)
{
    char *addr;
    int offset;
    s32 *field;
    // Matching: the extra temporaries are needed for the match.
    offset = layer * 0x2C;
    addr = (char *) D_801285BC + offset;
    field = (s32 *) addr;
    return *field;
}

s32 func_800BEB4C()
{
    return D_80128760;
}

int func_800BEB58(s32 value)
{
    D_80128760 = value;
}

s32 func_800BEB64(s32 layer)
{
    u8 *rec;
    s32 offset;
    rec = (u8 *) D_801285B0.u + (layer * 0x2C);
    offset = (rec[0x29] & 0xFFu) * 4;
    return *(s32 *) ((rec + offset) + 0x10);
}

s32 func_800BEB98(s32 layer)
{
    // Matching: rv is needed for the match.
    s32 rv = 1;
    return (((E_BEB98 *) &D_801285B0.raw)[layer].unk14 != 0) ? 2 : rv;
}

int func_800BEBD4(s32 layer)
{
    func_800B27A0(*(s32 *) ((u8 *) D_801285BC + layer * 44));
}

s32 func_800BEC10()
{
    return D_80128728;
}

s32 func_800BEC1C()
{
    return D_8012872C;
}

int func_800BEC28(s32 layer)
{
    return *(s32 *) ((u8 *) D_801285D0 + layer * 44);
}

// Map bounds as min/max corners.
void func_800BEC4C(s32 *bounds_min, s32 *bounds_max, s32 arg2)
{
    s32 i;
    func_800BECE0(bounds_min, bounds_max, arg2);
    func_800E37E8(bounds_min, bounds_max, arg2);
    for (i = 0; i < 3; i++) {
        bounds_min[i] = D_801285B0.b[i + 0x5E] + bounds_min[i];
        bounds_max[i] = D_801285B0.b[i + 0x61] + bounds_max[i];
    }
}

float func_800BECCC(void)
{
    return (float) D_80128734;
}

int func_800BECE0(bounds_min, bounds_max)
s32 bounds_min;
s32 bounds_max;
{
    func_800EE830(bounds_min, &D_80128730);
    func_800EE830(bounds_max, &D_8012873C);
}

int func_800BED18(s32 arg0, s32 arg1)
{
    func_800EE830(arg0, &D_80128748);
    func_800EE830(arg1, &D_80128754);
}

void func_800BED50(s32 pos)
{
    func_800BE600(pos, 0x1F00);
}

int func_800BED70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4)
{
    f32 scratch[3];
    int result;
    if (D_801285B0.u[0x2A]) {
        func_800EFD24(scratch);
        result = func_800AD2C8(*(s32 *) D_801285B0.u,
                                ((s32 *) (D_801285B0.u + 0x10))[D_801285B0.u[0x29]], arg0,
                                arg1, scratch, arg2, arg3, arg4);
        if (result)
            return result;
    }
    if (D_801285B0.u[0x77])
        return _gcmapsects_entrypoint_20(D_801285B0.u, arg0, arg1, arg2, arg3, arg4);
    return 0;
}

// Matching: assigning offset inside the expression is needed for the match.
s32 func_800BEE40(s32 arg0, s32 arg1, s32 arg2, f32 arg3)
{
    char *scratch_ptr;
    u8 *base;
    s32 offset;
    s32 scratch;
    if (D_801285B0.u[0x2A] != 0) {
        func_800EFD24(&scratch);
        if (func_800AD894(*(s32 *) D_801285B0.u,
                          *(s32 *) ((D_801285B0.u + (D_801285B0.u[0x29] * 4)) + (offset = 0x10)),
                          arg0, arg1, arg2, &scratch, arg3) != 0) {
            return 1;
        }
    }
    base = D_801285B0.u;
    scratch_ptr = (char *) &scratch;
    if (base[0x77] != 0) {
        return _gcmapsects_entrypoint_21(D_801285B0.u, *(s32 *) ((char *) &scratch + 0x10),
                                         *(s32 *) ((char *) &scratch + 0x14),
                                         *(s32 *) (scratch_ptr + 0x18), arg3);
    }
    return 0;
}

// Line hit against map sections and both layers; stores the hit layer model in hit_model.
s32 func_800BEF00(ray_start, ray_end, hit, flags)
f32 *ray_start;
f32 *ray_end;
f32 *hit;
s32 flags;
{
    s32 hit_opaque;
    s32 hit_translucent;

    hit_opaque = 0;
    D_801285B0.MapState.hit_model = 0;

if (D_801285B0.MapState.record[1].collision_on != 0) {
    if ((flags & 0x1F00) != 0x1F00) {
        if (D_801285B0.MapState.sections_on != 0) {
            hit_opaque = _gcmapsects_entrypoint_22((MapState *) &D_801285B0.raw, ray_start, ray_end,
                                                hit, flags);
        }
        if ((hit_opaque == 0) && (D_801285B0.MapState.record[0].collision_on != 0)) {
            hit_opaque = func_800AB0BC(
                D_801285B0.MapState.record[0].collision,
                D_801285B0.MapState.record[0].vertex_sets[D_801285B0.MapState.record[0].vertex_idx],
                ray_start, ray_end, hit, flags);
        }
    }
    hit_translucent = func_800AB0BC(
        D_801285B0.MapState.record[1].collision,
        D_801285B0.MapState.record[1].vertex_sets[D_801285B0.MapState.record[1].vertex_idx], ray_start,
        ray_end, hit, flags);
    if (hit_translucent != 0) {
        D_801285B0.MapState.hit_model = (s32) D_801285B0.MapState.record[1].model;
        return hit_translucent;
    }
    if (D_801285B0.MapState.sections_on != 0) {
        hit_translucent = _gcmapsects_entrypoint_22((MapState *) &D_801285B0.raw, ray_start, ray_end, hit,
                                            flags);
        if (hit_translucent != 0) {
            return hit_translucent;
        }
    }
    if (hit_opaque != 0) {
        D_801285B0.MapState.hit_model = (s32) D_801285B0.MapState.record[0].model;
    }
    return hit_opaque;
}

if (D_801285B0.MapState.sections_on != 0) {
    hit_opaque =
        _gcmapsects_entrypoint_22((MapState *) &D_801285B0.raw, ray_start, ray_end, hit, flags);
}

if ((hit_opaque == 0) && (D_801285B0.MapState.record[0].collision_on != 0)) {
    hit_opaque = func_800AB0BC(
        D_801285B0.MapState.record[0].collision,
        D_801285B0.MapState.record[0].vertex_sets[D_801285B0.MapState.record[0].vertex_idx], ray_start,
        ray_end, hit, flags);
}

if (hit_opaque != 0) {
    D_801285B0.MapState.hit_model = (s32) D_801285B0.MapState.record[0].model;
    return hit_opaque;
}

return 0;
}

s32 func_800BF0E0(s32 arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s32 hit_opaque = 0;
    s32 hit_translucent;
    D_801285B0.MapState.hit_model = 0;

if (D_801285B0.MapState.sections_on) {
    hit_opaque = _gcmapsects_entrypoint_23((MapState *) &D_801285B0.raw, arg0, arg1, arg2,
                                        arg3, arg4, arg5);
}

if (!hit_opaque && D_801285B0.MapState.record[0].collision_on) {
    hit_opaque = func_800AC638(
        D_801285B0.MapState.record[0].collision,
        D_801285B0.MapState.record[0].vertex_sets[D_801285B0.MapState.record[0].vertex_idx], arg0,
        arg1, arg2, arg3, arg4, arg5);
}

if (hit_opaque)
    D_801285B0.MapState.hit_model = D_801285B0.MapState.record[0].model;
if (!D_801285B0.MapState.record[1].collision_on)
    return hit_opaque;
hit_translucent =
    func_800AC638(D_801285B0.MapState.record[1].collision,
                  D_801285B0.MapState.record[1].vertex_sets[D_801285B0.MapState.record[1].vertex_idx],
                  arg0, arg1, arg2, arg3, arg4, arg5);

if (hit_translucent) {
    D_801285B0.MapState.hit_model = D_801285B0.MapState.record[1].model;
    return hit_translucent;
}

return hit_opaque;
}

s32 func_800BF228(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 hit_opaque;
    s32 hit_translucent;
    hit_opaque = 0;
    *((s32 *) (&D_801285B0.u[0x1B0])) = 0;

if (D_801285B0.u[0x77] != 0) {
    hit_opaque = _gcmapsects_entrypoint_26(D_801285B0.u, arg0, arg1, arg2, arg3);
}

if ((hit_opaque == 0) && (D_801285B0.u[0x2A] != 0)) {
    hit_opaque = func_800AC978(*(s32 *) &D_801285B0.u[0],
                           *(s32 *) &D_801285B0.u[(D_801285B0.u[0x29] * 4) + 0x10], arg0, arg1,
                           arg2, arg3);
}

if (hit_opaque != 0) {
    *(s32 *) &D_801285B0.u[0x1B0] = *(s32 *) &D_801285B0.u[0xC];
}

if (D_801285B0.u[0x56] == 0) {
    return hit_opaque;
}

hit_translucent = func_800AC978(*((s32 *) (&D_801285B0.u[0x2C])),
                        *((s32 *) (&D_801285B0.u[(D_801285B0.u[0x55] * 4) + 0x3C])), arg0, arg1,
                        arg2, arg3);

if (hit_translucent != 0) {
    *(s32 *) &D_801285B0.u[0x1B0] = *(s32 *) &D_801285B0.u[0x38];
    return hit_translucent;
}

return hit_opaque;
}

// Casts a ray of length scale from ray_start; writes the hit point to out.
s32 func_800BF340(s32 ray_start, Actor *out, s32 hit, s32 flags, s32 scale)
{
    f32 dir[3];
    f32 ray_end[3];
    s32 result;
    s32 found;

    func_800EE7F8(ray_end);
    func_800EFB24(dir, ray_end, ray_start);
    func_800EF368(dir, scale);
    func_800EF04C(ray_end, dir);
    found = func_800BEF00(ray_start, ray_end, hit, flags);
    // Matching: the copy of found is needed for the match.
    result = found;

if (found == 0) {
    return 0;
}

func_800EF3DC(ray_end, dir);
func_800EE7F8(out, ray_end);
return result;
}

int func_800BF3E4(void)
{
    return ((*(u16 *) &D_801285B0.u[0x5A] != 0) || (D_801285B0.u[0x77] != 0)) &&
           (*(u16 *) &D_801285B0.u[0x5C] != 0);
}

void func_800BF420()
{
    _gcmapDll_entrypoint_4(D_801285B0.u);
}

// Registers the map collision queries with the collision provider list.
void func_800BF444()
{
    _gcmapDll_entrypoint_3(D_801285B0.u);
    func_800C6A28(&func_800BEF00, &func_800BF0E0, &func_800BF228, &func_800BEB4C);
}

void func_800BF48C(s32 red, s32 green, s32 blue)
{
    ((u8 *) D_801285B0.u)[0x85] = red;
    ((u8 *) D_801285B0.u)[0x86] = green;
    ((u8 *) D_801285B0.u)[0x87] = blue;
}

void func_800BF4A4(s32 layer, unsigned int enabled)
{
    u8 *rec;
    u8 *flag_ptr;
    rec = ((u8 *) (D_801285B0.u)) + (layer * 0x2C);

if (*(s32 *) rec != 0) {
    // Matching: the flag_ptr temporary is needed for the match.
    flag_ptr = rec + 0x2A;
    *(s8 *) flag_ptr = enabled;
}

}

void func_800BF4DC(s32 layer, s32 visible_flag)
{
    if (visible_flag != ((E_BF4DC *) &D_801285B0.raw)[layer].unk2B) {
        if (((E_BF4DC *) &D_801285B0.raw)[layer].unk4 != 0) {
            _idworldmake_entrypoint_5(((E_BF4DC *) &D_801285B0.raw)[layer].unk4);
        }
    }

((E_BF4DC *) &D_801285B0.raw)[layer].unk2B = visible_flag;
}

void func_800BF544(s32 layer, s32 arg1, s32 arg2)
{
    s32 handle = *(s32 *) ((u8 *) D_801285B4 + layer * 44);
    if (handle)
        _idworldmake_entrypoint_6(handle, arg1, arg2);

}

void func_800BF58C()
{
    if (D_801285B0.D_801285B0_unk.unk_178 != 0) {
        D_801285B0.D_801285B0_unk.unk_178 = func_800DC060(D_801285B0.D_801285B0_unk.unk_178);
    }

if (D_801285B0.D_801285B0_unk.unk_17C != 0) {
    D_801285B0.D_801285B0_unk.unk_17C = defrag(D_801285B0.D_801285B0_unk.unk_17C);
}

if (D_801285B0.D_801285B0_unk.unk_4 != 0) {
    D_801285B0.D_801285B0_unk.unk_4 = func_800EE5D8(D_801285B0.D_801285B0_unk.unk_4);
}

if (D_801285B0.D_801285B0_unk.unk_30 != 0) {
    D_801285B0.D_801285B0_unk.unk_30 = func_800EE5D8(D_801285B0.D_801285B0_unk.unk_30);
}

if (D_801285B0.D_801285B0_unk.unk_1C != 0) {
    D_801285B0.D_801285B0_unk.unk_1C =
        func_800F9F90(D_801285B0.D_801285B0_unk.unk_1C, D_801285B0.D_801285B0_unk.unk_18);
}

if (D_801285B0.D_801285B0_unk.unk_48 != 0) {
    D_801285B0.D_801285B0_unk.unk_48 =
        func_800F9F90(D_801285B0.D_801285B0_unk.unk_48, D_801285B0.D_801285B0_unk.unk_44);
}

if (D_801285B0.D_801285B0_unk.unk_8 != 0) {
    D_801285B0.D_801285B0_unk.unk_8 = defrag(D_801285B0.D_801285B0_unk.unk_8);
}

if (D_801285B0.D_801285B0_unk.unk_34 != 0) {
    D_801285B0.D_801285B0_unk.unk_34 = defrag(D_801285B0.D_801285B0_unk.unk_34);
}

if (D_801285B0.D_801285B0_unk.unk_77 != 0) {
    D_801285B0.D_801285B0_unk.unk_68 = defrag(D_801285B0.D_801285B0_unk.unk_68);
}

}

void func_800BF68C()
{
    int one;
    _gcmapDll_entrypoint_1(D_801285B0.u);
    // Matching: the negated temporary is needed for the match.
    one = 1;
    D_80128634 = -one;

}

int func_800BF6B8()
{
    if (D_801285B0.u[0x77] != 0) {
        int result = _gcmapsects_entrypoint_24(D_801285B0.u);
        if (result != 0) {
            return 2;
        }
        return 1;
    }

return 0;
}

int func_800BF704()
{
    return (int) &D_801285B0.raw;

}

void func_800BF710()
{
    if (((u8 *) &D_801285B0.raw)[0x77]) {
        _gcmapsects_entrypoint_9(D_801285B0.u);
    }

}

// Sets entry idx (1-based) and grows the entry count.
int func_800BF744(s32 idx, s32 value)
{
    ((s32 *) &D_801285B0.raw)[idx + 0x22] = value;

if (idx > ((s32 *) &D_801285B0.raw)[0x22]) {
    ((s32 *) &D_801285B0.raw)[0x22] = idx;
}

}

void func_800BF774()
{
    s32 *entries;
    s32 idx;
    idx = 1;

if (((int *) &D_801285B0.raw)[34] > 0) {
    entries = &((int *) D_801285B4)[0];
    do {
        func_800DF744(idx, *(s32 *) ((char *) entries + 136));
        idx++;
        entries++;
    } while (idx <= ((int *) &D_801285B0.raw)[34]);
}

}

void func_800BF7E0(void)
{
    s32 unk_0;
    s32 unk_1;
    s32 vertices;

if (*(s32 *) ((s8 *) D_801285B0.u + 8) != 0) {
    vertices = func_800BEB64(0);
    unk_1 = func_800BEBD4(0);
    _rtlight_entrypoint_2(*(s32 *) ((s8 *) D_801285B0.u + 8), vertices, unk_1, func_800BEB98(0));
}

if (*(s32 *) ((s8 *) D_801285B0.u + 0x34) != 0) {
    vertices = func_800BEB64(1);
    unk_1 = func_800BEBD4(1);
    _rtlight_entrypoint_2(*(s32 *) ((s8 *) D_801285B0.u + 0x34), vertices, unk_1,
                          func_800BEB98(1));
}

if (*(s32 *) ((s8 *) D_801285B0.u + 0x1C) != 0) {
    _vpmodule_entrypoint_2(*(s32 *) ((s8 *) D_801285B0.u + 0x1C),
                           *(s32 *) ((s8 *) D_801285B0.u + 0x18));
}

if (*(s32 *) ((s8 *) D_801285B0.u + 0x48) != 0) {
    _vpmodule_entrypoint_2(*(s32 *) ((s8 *) D_801285B0.u + 0x48),
                           *(s32 *) ((s8 *) D_801285B0.u + 0x44));
}

}

u8 func_800BF8B0()
{
    return D_80128627;
}

int func_800BF8BC(s32 arg0)
{
    s32 value;
    // Matching: | 0 is needed for the match.
    value = arg0 | 0;
    _gcmapDll_entrypoint_6(&D_801285B0.raw, value);
}

s32 func_800BF8E4(void)
{
    s32 i;

if (D_801285B0.BF8E4.unk_84 == -1) {
    D_801285B0.BF8E4.unk_84 = 0;
    for (i = 0; i < 2; i++) {
        if (D_801285B0.BF8E4.rec[i].words[2])
            D_801285B0.BF8E4.unk_84 = 1;
        if (D_801285B0.BF8E4.rec[i].words[7] &&
            _dbvpl_entrypoint_0(D_801285B0.BF8E4.rec[i].words[6], 0))
            D_801285B0.BF8E4.unk_84 = 2;
    }
}

return D_801285B0.BF8E4.unk_84;

}

void func_800BF99C(s32 layer, s32 arg1, s32 arg2)
{
    if (*(s32 *) (((layer * 0x2C) + D_801285B0.u) + 0x1C) != 0) {
        _vpmodule_entrypoint_4(*(s32 *) (((layer * 0x2C) + D_801285B0.u) + 0x1C),
                               *(s32 *) (((layer * 0x2C) + D_801285B0.u) + 0x18), arg1,
                               arg2);
    }

if (*(s32 *) (((layer * 0x2C) + D_801285B0.u) + 4) != 0) {
    _idworldmake_entrypoint_7(*(s32 *) (((layer * 0x2C) + D_801285B0.u) + 4), arg1, arg2);
}

}

// Whether pos lies inside the layer bounds with a margin of 100.
int func_800BFA1C(f32 *pos)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        if (pos[i] < ((s32 *) D_801285B0.u)[i + 0x60] - 100)
            return 0;
        if (pos[i] > ((s32 *) D_801285B0.u)[i + 0x63] + 100)
            return 0;
    }
    return 1;
}

int func_800BFAA4()
{
    u8 *map;
    map = func_800BF704();
    return map[0x77];
}
