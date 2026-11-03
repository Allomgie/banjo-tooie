#include "common.h"

typedef struct {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s16 local_3;
    s16 local_4;
    s16 local_5;
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

void gcmapsects_lagoonbot_entrypoint_0(void)
{
    u32 local_0;
    s16(*local_1)[2];

    _gcmapsects_entrypoint_10(4);
    for (local_0 = 0; local_0 < 4; local_0++) {
        _gcmapsects_entrypoint_0(D_80800230_gcmapsects_lagoonbot[local_0].local_4,
                                 D_80800230_gcmapsects_lagoonbot[local_0].local_5,
                                 D_80800230_gcmapsects_lagoonbot[local_0].local_0,
                                 D_80800230_gcmapsects_lagoonbot[local_0].local_1,
                                 D_80800230_gcmapsects_lagoonbot[local_0].local_2,
                                 D_80800230_gcmapsects_lagoonbot[local_0].local_3);
    }
    local_1 = D_808002E0_gcmapsects_lagoonbot;
    local_0 = 0;
    do {
        _gcmapsects_entrypoint_3(*local_1[0], (*local_1)[1]);
        local_1++;
    } while (++local_0 < 3);
    for (local_0 = 0; local_0 < 4; local_0++) {
        _gcmapsects_entrypoint_1(D_808002EC_gcmapsects_lagoonbot[local_0], 0);
        _gcmapsects_entrypoint_2(D_808002EC_gcmapsects_lagoonbot[local_0], 0);
    }
    _gcmapsects_entrypoint_12(_gcmapsects_lagoonbot_entrypoint_1);
    _gcmapsects_entrypoint_14(2);
}

void gcmapsects_lagoonbot_entrypoint_1(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    u8 local_2;
    func_800E39A8(local_0, local_1);
    local_1[0] = func_80013728(local_1[0]);
    local_1[1] = func_800136E4(local_1[1]);
    local_2 = param_0[0x7E];
    if (local_2 && ((local_0[1] < 8000.0f && local_1[0] < -20.0f) ||
                    (local_0[1] < 6000.0f && local_1[0] < 0.0f))) {
        local_2 = param_0[0x7E] = 0;
    }
    if (local_2 && local_0[1] < 4000.0f && local_1[0] >= 0.0f)
        param_0[0x7E] = func_800E3E8C(D_808002F4_gcmapsects_lagoonbot, 982.0f);
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
