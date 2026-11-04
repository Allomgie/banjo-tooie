#include "common.h"

typedef struct {
    f32 aabb_min[3];
    f32 aabb_max[3];
    f32 center[3];
    s16 radius;
    s16 model_0;
    s16 model_1;
    s16 pad_0;
} LagoonSector1180;
extern LagoonSector1180 D_80800230_gcmapsects_lagoonmid[4];
extern s16 D_808002E0_gcmapsects_lagoonmid[3][2];
extern s16 D_808002EC_gcmapsects_lagoonmid[4];
extern s16 D_808002F4_gcmapsects_lagoonmid[];
extern void _gcmapsects_lagoonmid_entrypoint_1();
extern void _gcmapsects_entrypoint_0(s32, s32, f32 *, f32 *, void *, f32);
extern void func_800E39A8(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 func_800136E4(f32);
extern s32 func_800E3E8C(void *, f32);

// Registers the 4 map sections, their neighbour pairs and flags, and the per-frame callback.
void gcmapsects_lagoonmid_entrypoint_0(void)
{
    u32 i;
    s16(*pair)[2];

    _gcmapsects_entrypoint_10(4);
    for (i = 0; i < 4; i++) {
        _gcmapsects_entrypoint_0(D_80800230_gcmapsects_lagoonmid[i].model_0,
                                 D_80800230_gcmapsects_lagoonmid[i].model_1,
                                 D_80800230_gcmapsects_lagoonmid[i].aabb_min,
                                 D_80800230_gcmapsects_lagoonmid[i].aabb_max,
                                 D_80800230_gcmapsects_lagoonmid[i].center,
                                 D_80800230_gcmapsects_lagoonmid[i].radius);
    }
    pair = D_808002E0_gcmapsects_lagoonmid;
    i = 0;
    do {
        _gcmapsects_entrypoint_3(*pair[0], (*pair)[1]);
        pair++;
    } while (++i < 3);
    for (i = 0; i < 4; i++) {
        _gcmapsects_entrypoint_1(D_808002EC_gcmapsects_lagoonmid[i], 0);
        _gcmapsects_entrypoint_2(D_808002EC_gcmapsects_lagoonmid[i], 0);
    }
    _gcmapsects_entrypoint_12(_gcmapsects_lagoonmid_entrypoint_1);
    _gcmapsects_entrypoint_14(2);
}

// Per-frame: sets/clears the map layer-1 draw flag (+0x7E) from camera height, pitch and a frustum test.
void gcmapsects_lagoonmid_entrypoint_1(u8 *map)
{
    f32 pos[3];
    f32 rot[3];
    u8 layer_on;
    func_800E39A8(pos, rot);
    rot[0] = func_80013728(rot[0]);
    rot[1] = func_800136E4(rot[1]);
    layer_on = map[0x7E];
    if (layer_on && ((pos[1] < 8000.0f && rot[0] < -20.0f) ||
                    (pos[1] < 6000.0f && rot[0] < 0.0f))) {
        layer_on = map[0x7E] = 0;
    }
    if (layer_on && pos[1] < 4000.0f && rot[0] >= 0.0f)
        map[0x7E] = func_800E3E8C(D_808002F4_gcmapsects_lagoonmid, 982.0f);
}

LagoonSector1180 D_80800230_gcmapsects_lagoonmid[4] = {
    -4.4e+03f, -3.5e+03f, 8.2e+03f,  -13567.0f, -5.91e+03f, 3.7e+03f,  2.2e+03f,  -1e+02f,
    14731.0f,  0x1D4C,    0x72A,     0x0,       0x0,        3.5e+03f,  -5.6e+03f, 2.6e+03f,
    -397.0f,   -7843.0f,  -2428.0f,  6558.0f,   -3053.0f,   7587.0f,   0x1D4C,    0x730,
    0x0,       0x0,       3.5e+03f,  -6e+03f,   1.02e+04f,  1806.0f,   -6485.0f,  7554.0f,
    4588.0f,   -4579.0f,  12675.0f,  0x1D4C,    0x72D,      0x0,       0x0,       -1.69e+04f,
    -8e+02f,   9.4e+03f,  -19355.0f, -3666.0f,  7359.0f,    -11455.0f, 1631.0f,   11719.0f,
    -0xA0,     0x733,     0x737,     0x0};
s16 D_808002E0_gcmapsects_lagoonmid[3][2] = {0x0, 0x2, 0x0, 0x3, 0x2, 0x1};
s16 D_808002EC_gcmapsects_lagoonmid[4] = {0x0, 0x3, 0x1, 0x2};
s16 D_808002F4_gcmapsects_lagoonmid[2] = {-0x39F3, 0x5000};
u32 D_808002F8_gcmapsects_lagoonmid[2] = {0x45BAF000, 0xC54C9000};
