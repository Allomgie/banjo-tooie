// Map sections of the Jolly Roger's Lagoon sea bottom (map 0x1A9): registers 4 sections and a
// per-frame callback that hides or shows a map layer from camera height, pitch and a frustum test.
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
extern LagoonSector1180 D_80800230_gcmapsects_lagoonbot[4];
extern s16 D_808002E0_gcmapsects_lagoonbot[3][2];
extern s16 D_808002EC_gcmapsects_lagoonbot[4];
extern s16 D_808002F4_gcmapsects_lagoonbot[];
extern void _gcmapsects_lagoonbot_entrypoint_1();
extern void _gcmapsects_entrypoint_0(s32, s32, f32 *, f32 *, void *, f32);
extern void func_800E39A8(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 func_800136E4(f32);
extern s32 func_800E3E8C(void *, f32);

// Registers the 4 map sections, their neighbour pairs and flags, and the per-frame callback.
void gcmapsects_lagoonbot_entrypoint_0(void)
{
    u32 i;
    s16(*pair)[2];

    _gcmapsects_entrypoint_10(4);
    for (i = 0; i < 4; i++) {
        _gcmapsects_entrypoint_0(D_80800230_gcmapsects_lagoonbot[i].model_0,
                                 D_80800230_gcmapsects_lagoonbot[i].model_1,
                                 D_80800230_gcmapsects_lagoonbot[i].aabb_min,
                                 D_80800230_gcmapsects_lagoonbot[i].aabb_max,
                                 D_80800230_gcmapsects_lagoonbot[i].center,
                                 D_80800230_gcmapsects_lagoonbot[i].radius);
    }
    pair = D_808002E0_gcmapsects_lagoonbot;
    i = 0;
    do {
        _gcmapsects_entrypoint_3(*pair[0], (*pair)[1]);
        pair++;
    } while (++i < 3);
    for (i = 0; i < 4; i++) {
        _gcmapsects_entrypoint_1(D_808002EC_gcmapsects_lagoonbot[i], 0);
        _gcmapsects_entrypoint_2(D_808002EC_gcmapsects_lagoonbot[i], 0);
    }
    _gcmapsects_entrypoint_12(_gcmapsects_lagoonbot_entrypoint_1);
    _gcmapsects_entrypoint_14(2);
}

// Per-frame: sets/clears the map layer-1 draw flag (+0x7E) from camera height, pitch and a frustum test.
void gcmapsects_lagoonbot_entrypoint_1(u8 *map)
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
        map[0x7E] = func_800E3E8C(D_808002F4_gcmapsects_lagoonbot, 982.0f);
}

LagoonSector1180 D_80800230_gcmapsects_lagoonbot[4] = {
    8e+03f,    -6.7e+03f, 3e+02f,     5226.0f,  -7059.0f,  -3.86e+03f, 9383.0f,    -5327.0f,
    2928.0f,   0x1D4C,    0x72E,      0x0,      0x0,       1.43e+04f,  -6.3e+03f,  -4.6e+03f,
    12131.0f,  -7777.0f,  -8084.0f,   14841.0f, -5135.0f,  -246.0f,    0x1D4C,     0x72F,
    0x0,       0x0,       8.5e+03f,   -8e+03f,  -8.2e+03f, 2.57e+03f,  -1.15e+04f, -12886.0f,
    12131.0f,  -5047.0f,  -3.86e+03f, 0x1D4C,   0x731,     0x0,        0x0,        1.22e+04f,
    -3.8e+03f, 5.5e+03f,  6062.0f,    -5877.0f, -246.0f,   16887.0f,   -329.0f,    11196.0f,
    -0x591,    0x732,     0x738,      0x0};
s16 D_808002E0_gcmapsects_lagoonbot[3][2] = {0x0, 0x2, 0x2, 0x1, 0x1, 0x3};
s16 D_808002EC_gcmapsects_lagoonbot[4] = {0x2, 0x3, 0x0, 0x1};
s16 D_808002F4_gcmapsects_lagoonbot[2] = {-0x39F3, 0x5000};
u32 D_808002F8_gcmapsects_lagoonbot[2] = {0x45BAF000, 0xC54C9000};
