// Bouncy-surface map-mesh effect: vertices act as damped springs that sag around the player and
// push the player back up, with a launch speed that depends on the transformation.

#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 pad_6[5];
} BouncePt;
typedef struct {
    u8 pad_0[4];
    f32 player_x;
    u8 pad_8[4];
    f32 player_z;
    u8 pad_10[0xC];
    f32 dt;
    f32 sag;
    u8 pad_24[4];
    f32 *vel_cur;
    u8 pad_2C[8];
    f32 inner_radius;
    f32 outer_radius;
    f32 falloff_scale;
    f32 spring;
    f32 damping;
} BounceCtx;
extern u8 D_80135480[];
extern s32 func_800F54E4(void);
typedef struct {
    u8 mode;
    u8 pad_1[3];
    f32 player_pos[3];
    u8 pad_10[0xC];
    f32 dt;
    f32 sag;
    f32 *vel_buf;
    f32 *vel_cur;
    f32 *vel_end;
    f32 strength;
    f32 inner_radius;
    f32 outer_radius;
    f32 falloff_scale;
    f32 spring;
    f32 damping;
    f32 unk_48;
    f32 unk_4C;
    f32 inv_scale;
    f32 origin[3];
} IdBounceData;
extern void func_800F83E4(u32, f32);
typedef struct {
    s32 mesh_id;
    u8 pad_4[0x1C];
} BounceLookupRecord;
extern BounceLookupRecord D_80800E50_idbounce[];
extern void heap_free(void *);
extern void *heap_alloc(s32);
extern void func_800EE7F8(f32 *, f32 *);
extern Actor *func_80106790(Unk80132ED0 *);
typedef struct {
    s8 mode;
    u8 pad_1[0x1F];
    f32 sag;
    f32 *vel_buf;
    f32 *vel_cur;
    f32 *vel_end;
    f32 strength;
    f32 inner_radius;
    f32 outer_radius;
    f32 falloff_scale;
    f32 spring;
    f32 damping;
    f32 unk_48;
    f32 unk_4C;
    f32 inv_scale;
    f32 origin[3];
} IdBounceInitData;
extern f32 func_800D8FF8(void);
extern void func_800EF334(f32 *, f32);
extern u8 D_8013546C;
extern void _idbounce_entrypoint_0(void);
extern void _idbounce_entrypoint_1(void);
extern void _idbounce_entrypoint_2(void);

f32 func_80800000_idbounce(void)
{
    switch (func_8008FD48()) {
        case 0x11:
            return 0.1f;
        case 0xA:
            return 0.7f;
        case 0xB:
            return 0.4f;
        default:
            return 1.0f;
    }
}

// Spring kernel over s16 vertices: each vertex sags near the player and springs back.
// D_80135480: [0] state flag rose this frame, [1] state flag set (see func_808008B4_idbounce),
// [2] launch applied this frame, [3] instance count.
void idbounce_entrypoint_0(s32 param_0, BouncePt *rest_pt, BouncePt *pt, s32 count,
                           BounceCtx *ctx)
{
    f32 sag;
    f32 px;
    f32 pz;
    f32 dt;
    f32 spring;
    f32 damping;
    f32 acc;
    f32 dist;
    f32 dx;
    f32 dz;
    BouncePt *end;

    px = ctx->player_x;
    pz = ctx->player_z;
    sag = ctx->sag;
    spring = ctx->spring;
    damping = ctx->damping;
    dt = ctx->dt;
    end = pt + count;
    if (pt < end) {
        do {
            acc = 0.0f;
            if (D_80135480[1] != 0) {
                dx = (f32) pt->x - px;
                dz = (f32) pt->z - pz;
                dist = sqrtf(dx * dx + dz * dz);
                if (dist < ctx->inner_radius) {
                    acc = 0.0f - sag;
                } else if (dist < ctx->outer_radius) {
                    acc -= sag * (1.0f - (dist - ctx->inner_radius) * ctx->falloff_scale);
                }
            }
            acc += ((f32) (rest_pt->y - pt->y) * spring - *ctx->vel_cur * damping);
            *ctx->vel_cur += acc * dt;
            pt->y += *ctx->vel_cur * dt;
            if (D_80135480[1] != 0) {
                if (D_80135480[2] == 0 && dist < ctx->inner_radius) {
                    // Matching: empty branches, needed for the match.
                    if (*ctx->vel_cur < 0.0f) {
                        if (*ctx->vel_cur < 0.0f) {
                        }
                    } else {
                    }
                    acc = *ctx->vel_cur;
                    if (D_80135480[2] == 0) {
                        if (2000.0f < *ctx->vel_cur) {
                            acc = 2000.0f;
                        } else {
                        }
                        func_800F83E4(func_800F54E4(), acc);
                        D_80135480[2] = 1;
                    }
                }
            }
            pt++;
            rest_pt++;
            ctx->vel_cur = ctx->vel_cur + 1;
        } while (pt < end);
    }
}

// Spring kernel over Vtx vertices, updated in place.
void idbounce_entrypoint_1(s32 param_0, Vtx *rest_vtx, Vtx *vtx, s32 count,
                           IdBounceData *data)
{
    f32 sag;
    f32 px;
    f32 pz;
    f32 dt;
    f32 spring;
    f32 damping;
    f32 acc;
    f32 dist;
    f32 dx;
    f32 dz;
    Vtx *end;

    px = data->player_pos[0];
    pz = data->player_pos[2];
    sag = data->sag;
    spring = data->spring;
    damping = data->damping;
    dt = data->dt;

    for (end = vtx + count; vtx < end; vtx++) {
        // Matching: empty block, needed for the match.
        if (1) {
        }
        acc = 0.0f;
        if (D_80135480[1]) {
            dx = vtx->v.ob[0] - px;
            dz = vtx->v.ob[2] - pz;
            dist = sqrtf(dx * dx + dz * dz);
            if (dist < data->inner_radius) {
                acc -= sag;
            } else if (dist < data->outer_radius) {
                acc -= sag * (1.0f - (dist - data->inner_radius) * data->falloff_scale);
            }
        }
        acc += (rest_vtx->v.ob[1] - vtx->v.ob[1]) * spring - *data->vel_cur * damping;
        *data->vel_cur += acc * dt;
        vtx->v.ob[1] += *data->vel_cur * dt;
        if (D_80135480[1]) {
            if (D_80135480[2] == 0 && dist < data->inner_radius) {
                // Matching: empty branches, needed for the match.
                if (*data->vel_cur < 0.0f) {
                    if (*data->vel_cur < 0.0f) {
                    }
                } else {
                }
                acc = *data->vel_cur / data->inv_scale;
                if (D_80135480[2] == 0) {
                    if (acc > 2000.0f) {
                        acc = 2000.0f;
                    }
                    func_800F83E4(func_800F54E4(), acc);
                    D_80135480[2] = 1;
                }
            }
        }
        if (vtx->v.ob[1] < 0) {
            vtx->v.ob[1] = 0;
        }
        rest_vtx++;
        data->vel_cur++;
    }
}

// Spring kernel over Vtx vertices, written to a separate output array.
void idbounce_entrypoint_2(Vtx *rest_vtx, Vtx *out_vtx, Vtx *src_vtx, s32 count,
                           IdBounceData *data)
{
    f32 sag;
    f32 px;
    f32 pz;
    f32 dt;
    f32 spring;
    f32 damping;
    f32 acc;
    f32 dist;
    f32 dx;
    f32 dz;
    Vtx *end;
    s32 clamp_floor;

    px = data->player_pos[0];
    pz = data->player_pos[2];
    sag = data->sag;
    spring = data->spring;
    damping = data->damping;
    clamp_floor = data->mode == 2;
    dt = data->dt;

    for (end = out_vtx + count; out_vtx < end; out_vtx++) {
        dist = data->outer_radius;
        acc = 0.0f;
        if (D_80135480[1]) {
            dx = src_vtx->v.ob[0] - px;
            dz = src_vtx->v.ob[2] - pz;
            dist = sqrtf(dx * dx + dz * dz);
            if (dist < data->inner_radius) {
                acc -= sag;
            } else if (dist < data->outer_radius) {
                acc -= sag * (1.0f - (dist - data->inner_radius) * data->falloff_scale);
            }
        }
        acc += (rest_vtx->v.ob[1] - src_vtx->v.ob[1]) * spring - *data->vel_cur * damping;
        *data->vel_cur += acc * dt;
        out_vtx->v.ob[1] = *data->vel_cur * dt + src_vtx->v.ob[1];
        if (D_80135480[1]) {
            if (D_80135480[2] == 0 && dist < data->inner_radius) {
                if (*data->vel_cur < 0.0f) {
                    acc = *data->vel_cur / data->inv_scale;
                } else if (*data->vel_cur < 10.0f * data->inv_scale) {
                    acc = -1.0f;
                } else if (data->unk_48 < *data->vel_cur) {
                    acc = *data->vel_cur * data->unk_4C;
                } else {
                    acc = *data->vel_cur / data->inv_scale;
                }
                if (D_80135480[2] == 0) {
                    if (acc > 2000.0f) {
                        acc = 2000.0f;
                    }
                    func_800F83E4(func_800F54E4(), acc);
                    D_80135480[2] = 1;
                }
            }
        }
        if (clamp_floor && out_vtx->v.ob[1] < 0) {
            out_vtx->v.ob[1] = 0;
        }
        rest_vtx++;
        src_vtx++;
        data->vel_cur++;
    }
}

// Returns the parameter record for a mesh id (the -1 terminator if not found).
BounceLookupRecord *func_80800874_idbounce(s32 mesh_id)
{
    BounceLookupRecord *rec = D_80800E50_idbounce;
    while (rec->mesh_id != -1) {
        if (rec->mesh_id == mesh_id)
            break;
        rec++;
    }
    return rec;
}

// Tests the player state flag 0x8000.
int func_808008B4_idbounce()
{
    s32 player;
    s32 unk_1;
    player = func_800F54E4();
    unk_1 = func_800F6C5C(player);
    if (unk_1 == 0) {
        return 0;
    }
    // Matching: extra block, needed for the match.
    {
        if ((func_800F55FC(player) & 0x8000) == 0) {
            return 0;
        }
        return 1;
    }
}

// Frees the velocity buffer.
void idbounce_entrypoint_3(u8 *data)
{
    heap_free(*(void **) (data + 0x24));
    D_80135480[3]--;
}

// Sets up an instance: allocates one velocity float per vertex and loads the parameter record.
void idbounce_entrypoint_4(IdBounceInitData *data, s32 mesh_id, s32 param_2, s32 param_3,
                           s32 owner_kind)
{
    f32 *rec;
    s32 vtx_count;
    Actor *actor;
    s32 map_id;

    rec = (f32 *) func_80800874_idbounce(mesh_id);
    vtx_count = _glidmake_entrypoint_3(param_2, param_3);
    data->vel_buf = heap_alloc(vtx_count * sizeof(f32));
    data->vel_end = data->vel_buf + vtx_count;
    for (data->vel_cur = data->vel_buf; data->vel_cur < data->vel_end;
         data->vel_cur++) {
        *data->vel_cur = 0.0f;
    }
    data->sag = 0.0f;
    data->strength = -rec[1] / -2700.0f;
    data->inner_radius = rec[2];
    data->outer_radius = rec[3];
    data->spring = rec[4];
    data->damping = rec[5];
    data->unk_48 = rec[6];
    data->unk_4C = rec[7];
    if (owner_kind == 4) {
        actor = func_80106790(func_80106314());
        data->inv_scale = 1.0f / actor->scale;
        func_800EE7F8(data->origin, actor->position);
        switch (actor->unk6C_9) {
            case 0x34C:
                data->mode = 2;
                break;
            case 0x47E:
            case 0x4C4:
            case 0x4C5:
            case 0x4C6:
            case 0x4C7:
            case 0x50B:
            case 0x50C:
            case 0x531:
                data->mode = 3;
                break;
            default:
                data->mode = 1;
                break;
        }
    } else {
        data->origin[2] = 0.0f;
        data->origin[1] = 0.0f;
        data->origin[0] = 0.0f;
        map_id = func_800EA05C();
        if (map_id != 0xE2 && map_id != 0xE4 && map_id != 0xE5 && map_id != 0xF8 &&
            map_id != 0x138) {
            data->inv_scale = 0.0f;
            data->mode = 0;
        } else {
            data->mode = 3;
            data->inv_scale = 1.0f;
        }
    }
    if (data->inv_scale) {
        data->strength *= data->inv_scale;
        data->inner_radius *= data->inv_scale;
        data->outer_radius *= data->inv_scale;
        data->spring *= data->inv_scale;
        data->damping *= data->inv_scale;
        data->unk_48 *= data->inv_scale;
        data->unk_4C /= data->inv_scale;
    }
    data->falloff_scale = 1.0f / (rec[3] - rec[2]);
    D_80135480[3]++;
}

// Per-frame update: refreshes player position, sag force and velocity cursor, then runs the
// kernel for the instance's mode.
void idbounce_entrypoint_5(u8 *data, s32 param_1, s32 param_2)
{
    f32 player_vel[3];
    *(f32 *) (data + 0x1C) = func_800D8FF8();
    func_800F5A00(func_800F54E4(), (f32 *) (data + 4));
    func_800EF3DC((f32 *) (data + 4), data + 0x54);
    if (*(f32 *) (data + 0x50) != 0.0f)
        func_800EF334((f32 *) (data + 4), *(f32 *) (data + 0x50));
    *(f32 *) (data + 0x20) = -*(f32 *) (data + 0x30) * func_80800000_idbounce() * -2700.0f;
    if (*((u8 *) &D_8013546C + 0x14)) {
        func_800F5D70(func_800F54E4(), player_vel);
        *(f32 *) (data + 0x20) -= *(f32 *) (data + 0x30) * func_80800000_idbounce() *
                                  player_vel[1] / *(f32 *) (data + 0x1C);
    }
    *(s32 *) (data + 0x28) = *(s32 *) (data + 0x24);
    switch (data[0]) {
        case 0:
            _glid_entrypoint_0(param_1, param_2, _idbounce_entrypoint_0, data);
            break;
        case 1:
            _glid_entrypoint_0(param_1, param_2, _idbounce_entrypoint_1, data);
            break;
        case 2:
        case 3:
            _glid_entrypoint_1(param_1, param_2, _idbounce_entrypoint_2, data);
            break;
    }
}

// Per-frame hook: updates the D_80135480 state flags.
void idbounce_entrypoint_6(void)
{
    s32 unk_0;

    unk_0 = func_808008B4_idbounce();
    D_80135480[2] = 0;
    D_80135480[0] = !D_80135480[1] && unk_0 != 0;
    D_80135480[1] = unk_0;
}

void idbounce_entrypoint_7(void)
{
    if (D_80135480[1] != 0 && D_80135480[2] == 0) {
        func_800F83E4(func_800F54E4(), -1.0f);
    }
}

// TU-NOTE: the table is defined here with values from the ROM.
BounceLookupRecord D_80800E50_idbounce[15] = {
    0x1,  0x44, 0x7A, 0x0,  0x0,  0x43, 0x16, 0x0,  0x0,  0x43, 0x96, 0x0,  0x0,  0x42, 0xC8, 0x0,
    0x0,  0x40, 0x40, 0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x3F, 0xC0, 0x0,  0x0,  0xA,  0x44, 0x7A,
    0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x43, 0x96, 0x0,  0x0,  0x42, 0xC8, 0x0,  0x0,  0x40, 0x40,
    0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x40, 0x0,  0x0,  0x0,  0xB,  0x44, 0xFA, 0x0,  0x0,  0x43,
    0x16, 0x0,  0x0,  0x43, 0x96, 0x0,  0x0,  0x42, 0xC8, 0x0,  0x0,  0x40, 0x40, 0x0,  0x0,  0x43,
    0xC8, 0x0,  0x0,  0x40, 0x13, 0x33, 0x33, 0xF,  0x43, 0xFA, 0x0,  0x0,  0x43, 0x16, 0x0,  0x0,
    0x43, 0x48, 0x0,  0x0,  0x42, 0xC8, 0x0,  0x0,  0x40, 0x40, 0x0,  0x0,  0x43, 0x48, 0x0,  0x0,
    0x40, 0x0,  0x0,  0x0,  0x10, 0x44, 0x7A, 0x0,  0x0,  0x43, 0xC8, 0x0,  0x0,  0x44, 0x16, 0x0,
    0x0,  0x42, 0xC8, 0x0,  0x0,  0x40, 0x40, 0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x40, 0x0,  0x0,
    0x0,  0x15, 0x44, 0x7A, 0x0,  0x0,  0x43, 0x16, 0x0,  0x0,  0x43, 0x96, 0x0,  0x0,  0x42, 0xC8,
    0x0,  0x0,  0x40, 0x40, 0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x3F, 0xC0, 0x0,  0x0,  0x1E, 0x44,
    0x7A, 0x0,  0x0,  0x43, 0x16, 0x0,  0x0,  0x43, 0x96, 0x0,  0x0,  0x42, 0xC8, 0x0,  0x0,  0x40,
    0x40, 0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x3F, 0xC0, 0x0,  0x0,  0x24, 0x44, 0x7A, 0x0,  0x0,
    0x43, 0x16, 0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x43, 0xFA, 0x0,  0x0,  0x40, 0xA0, 0x0,  0x0,
    0x43, 0x48, 0x0,  0x0,  0x3F, 0xC0, 0x0,  0x0,  0x25, 0x44, 0x7A, 0x0,  0x0,  0x43, 0x16, 0x0,
    0x0,  0x43, 0x96, 0x0,  0x0,  0x42, 0xC8, 0x0,  0x0,  0x40, 0x40, 0x0,  0x0,  0x43, 0x48, 0x0,
    0x0,  0x3F, 0xC0, 0x0,  0x0,  0x26, 0x44, 0x7A, 0x0,  0x0,  0x43, 0x16, 0x0,  0x0,  0x43, 0x96,
    0x0,  0x0,  0x42, 0xC8, 0x0,  0x0,  0x40, 0x40, 0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x3F, 0xC0,
    0x0,  0x0,  0x27, 0x44, 0x7A, 0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x43, 0x96, 0x0,  0x0,  0x42,
    0xA0, 0x0,  0x0,  0x40, 0x40, 0x0,  0x0,  0x42, 0xC8, 0x0,  0x0,  0x40, 0x20, 0x0,  0x0,  0x28,
    0x44, 0x7A, 0x0,  0x0,  0x43, 0x16, 0x0,  0x0,  0x43, 0x96, 0x0,  0x0,  0x42, 0xC8, 0x0,  0x0,
    0x40, 0x40, 0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x3F, 0xC0, 0x0,  0x0,  0x32, 0x43, 0xFA, 0x0,
    0x0,  0x43, 0x16, 0x0,  0x0,  0x43, 0x96, 0x0,  0x0,  0x42, 0xC8, 0x0,  0x0,  0x40, 0x40, 0x0,
    0x0,  0x43, 0x48, 0x0,  0x0,  0x3F, 0xC0, 0x0,  0x0,  0x33, 0x44, 0x7A, 0x0,  0x0,  0x43, 0x16,
    0x0,  0x0,  0x43, 0x96, 0x0,  0x0,  0x43, 0x48, 0x0,  0x0,  0x40, 0xA0, 0x0,  0x0,  0x42, 0xC8,
    0x0,  0x0,  0x3F, 0xC0, 0x0,  0x0,  -0x1, 0x44, 0xFA, 0x0,  0x0,  0x43, 0x16, 0x0,  0x0,  0x43,
    0x96, 0x0,  0x0,  0x42, 0xC8, 0x0,  0x0,  0x40, 0x40, 0x0,  0x0,  0x43, 0xC8, 0x0,  0x0,  0x40,
    0x20, 0x0,  0x0};
