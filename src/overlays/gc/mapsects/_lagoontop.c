// Map sections of the Jolly Roger's Lagoon surface (map 0x1A7): registers 5 sections with water
// heights and a per-frame callback that hides some sections and the base layer from the camera.
#include "common.h"

typedef struct {
    f32 pos[3];
    f32 aabb_min[3];
    f32 aabb_max[3];
    s16 water_height;
    s16 model_a;
    s16 model_b;
    s16 pad_2A;
} LagoonSector1180;
extern LagoonSector1180 D_80800630_gcmapsects_lagoontop[5];
extern s16 D_8080070C_gcmapsects_lagoontop[4][2];
extern s16 D_8080071C_gcmapsects_lagoontop[2];
extern void _gcmapsects_lagoontop_entrypoint_1();
extern void _gcmapsects_entrypoint_0(s32, s32, f32 *, f32 *, void *, f32);
typedef struct {
    u8 pad[0x1AC];
    u32 b31 : 1;
    u32 b30 : 1;
    u32 rest : 30;
} W428;
typedef struct {
    u8 pad[0x4C];
    u32 b31 : 1;
    u32 b30 : 1;
    u32 rest : 30;
} W76;
typedef struct {
    u8 pad[0x4C];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS76;
typedef struct {
    u8 pad[0xA4];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS164;
typedef struct {
    u8 pad[0xFC];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS252;
typedef struct {
    u8 pad[0x1AC];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS428;
typedef struct {
    u8 pad[0x68];
    char *obj;
    u8 pad2[0x12];
    u8 f7E;
} LagoonCtx;
extern void func_800E39A8(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 func_800136E4(f32);
extern s32 func_800E3E8C(void *, f32);
extern f32 D_80800720_gcmapsects_lagoontop[];
extern f32 D_8080072C_gcmapsects_lagoontop[];
extern f32 D_80800738_gcmapsects_lagoontop[];
extern f32 D_80800744_gcmapsects_lagoontop[];

// Registers the 5 map sections, their neighbour pairs and flags, and the per-frame visibility callback.
void gcmapsects_lagoontop_entrypoint_0(void)
{
    u32 i;
    s16(*pair)[2];

    _gcmapsects_entrypoint_10(5);
    for (i = 0; i < 5; i++) {
        _gcmapsects_entrypoint_0(D_80800630_gcmapsects_lagoontop[i].model_a,
                                 D_80800630_gcmapsects_lagoontop[i].model_b,
                                 D_80800630_gcmapsects_lagoontop[i].pos,
                                 D_80800630_gcmapsects_lagoontop[i].aabb_min,
                                 D_80800630_gcmapsects_lagoontop[i].aabb_max,
                                 D_80800630_gcmapsects_lagoontop[i].water_height);
    }
    pair = D_8080070C_gcmapsects_lagoontop;
    i = 0;
    do {
        _gcmapsects_entrypoint_3(*pair[0], (*pair)[1]);
        pair++;
    } while (++i < 4);
    for (i = 0; i < 2; i++) {
        _gcmapsects_entrypoint_1(D_8080071C_gcmapsects_lagoontop[i], 0);
        _gcmapsects_entrypoint_2(D_8080071C_gcmapsects_lagoontop[i], 0);
    }
    _gcmapsects_entrypoint_12(_gcmapsects_lagoontop_entrypoint_1);
}

// Per-frame callback: hides sections from camera position, angles and frustum tests.
void gcmapsects_lagoontop_entrypoint_1(LagoonCtx *ctx)
{
    f32 cam_pos[3];
    f32 cam_rot[3];
    u8 visible;

    func_800E39A8(cam_pos, cam_rot);
    cam_rot[0] = func_80013728(cam_rot[0]);
    cam_rot[1] = func_800136E4(cam_rot[1]);

    if ((*(u32 *) (ctx->obj + 0xA4) >> 31) != 0) {
        if (cam_pos[1] < 5100.0f) {
            ((BitS164 *) ctx->obj)->b7 = 0;
            ((BitS164 *) ctx->obj)->b6 = 0;
        }
        if (-5800.0f < cam_pos[2] && 95.0f < cam_rot[1] && cam_rot[1] < 240.0f) {
            ((BitS164 *) ctx->obj)->b7 = 0;
            ((BitS164 *) ctx->obj)->b6 = 0;
        }
    }
    if ((*(u32 *) (ctx->obj + 0x4C) >> 31) != 0) {
        if (cam_pos[1] < 4200.0f && cam_rot[0] < 0.0f) {
            ((BitS76 *) ctx->obj)->b7 = 0;
        } else if (cam_pos[1] < 5050.0f &&
                   !func_800E3E8C(D_80800720_gcmapsects_lagoontop, 1250.0f)) {
            ((BitS76 *) ctx->obj)->b7 = 0;
            ((BitS76 *) ctx->obj)->b6 = 0;
        }
    }
    if ((*(u32 *) (ctx->obj + 0x1AC) >> 31) != 0) {
        if (4300.0f < cam_pos[1]) {
            ((BitS428 *) ctx->obj)->b7 = 0;
            ((BitS428 *) ctx->obj)->b6 = 0;
        }
    }
    if ((*(u32 *) (ctx->obj + 0xFC) >> 31) != 0) {
        if (0.0f < cam_pos[2] && 160.0f < cam_rot[1] && cam_rot[1] < 320.0f) {
            ((BitS252 *) ctx->obj)->b7 = 0;
            ((BitS252 *) ctx->obj)->b6 = 0;
        } else if (5150.0f < cam_pos[1] &&
                   !func_800E3E8C(D_8080072C_gcmapsects_lagoontop, 1000.0f)) {
            ((BitS252 *) ctx->obj)->b7 = 0;
            ((BitS252 *) ctx->obj)->b6 = 0;
        } else if (-4700.0f < cam_pos[0] && cam_pos[1] < 10000.0f) {
            ((BitS252 *) ctx->obj)->b7 = 0;
            ((BitS252 *) ctx->obj)->b6 = 0;
        }
    }
    if (*(u32 *) (ctx->obj + 0x1AC) >> 31) {
        if (4000.0f < cam_pos[2]) {
            if (90.0f < cam_rot[1]) {
                if (cam_rot[1] < 270.0f) {
                    ((BitS428 *) ctx->obj)->b7 = 0;
                    ((BitS428 *) ctx->obj)->b6 = 0;
                }
            }
        } else if (!((W428 *) ctx->obj)->b30 &&
                   !func_800E3E8C(D_80800738_gcmapsects_lagoontop, 450.0f)) {
            ((BitS428 *) ctx->obj)->b7 = 0;
            ((BitS428 *) ctx->obj)->b6 = 0;
        }
    }
    visible = ctx->f7E;
    if (visible && ((cam_pos[1] < 8000.0f && cam_rot[0] < -20.0f) ||
                    (cam_pos[1] < 6000.0f && cam_rot[0] < 0.0f))) {
        visible = ctx->f7E = 0;
    }
    if (visible && cam_pos[1] < 4000.0f && cam_rot[0] >= 0.0f) {
        ctx->f7E = func_800E3E8C(D_80800744_gcmapsects_lagoontop, 982.0f);
    }
    if (((W76 *) ctx->obj)->b30) {
        ((BitS164 *) ctx->obj)->b6 = 1;
    }
}

// TU-NOTE: .data of this overlay is defined here in C (values from the ROM).
// D_8080063C_gcmapsects_lagoontop = D_80800630_gcmapsects_lagoontop + 0xC and
// D_80800648_gcmapsects_lagoontop = D_80800630_gcmapsects_lagoontop + 0x18 are linker symbols (undefined_syms.us.txt).
LagoonSector1180 D_80800630_gcmapsects_lagoontop[5] = {
    -9e+03f,    9e+03f,    -8e+03f,    -17203.0f, 5.2e+03f,  -1.43e+04f, 2632.0f,   1.195e+04f,
    361.0f,     -0x1,      0x727,      0x0,       0x0,       -9e+03f,    9e+03f,    -9.2e+03f,
    -12523.0f,  8.6e+03f,  -1.25e+04f, -5.4e+03f, 1.05e+04f, -5.9e+03f,  -0x1,      0x734,
    0x0,        0x0,       -9e+03f,    2e+03f,    -3.2e+03f, -12654.0f,  -5.4e+02f, -5457.0f,
    -6872.0f,   5.2e+03f,  -134.0f,    0x1D4C,    0x728,     0x0,        0x0,       -5.5e+03f,
    1.2e+03f,   -7.1e+03f, -7229.0f,   895.0f,    -8981.0f,  -3359.0f,   1694.0f,   -5101.0f,
    0x1D4C,     0x72B,     0x0,        0x0,       -5.4e+03f, -1.2e+03f,  1.2e+03f,  -7253.0f,
    -1.84e+03f, -517.0f,   -4243.0f,   -115.0f,   3.7e+03f,  0x1D4C,     0x72C,     0x0,
    0x0};
s16 D_8080070C_gcmapsects_lagoontop[4][2] = {0x1, 0x0, 0x0, 0x2, 0x2, 0x4, 0x2, 0x3};
s16 D_8080071C_gcmapsects_lagoontop[2] = {0x3, 0x4};
f32 D_80800720_gcmapsects_lagoontop[1] = {-9044.0f};
u32 D_80800724_gcmapsects_lagoontop[2] = {0x459DD000, 0xC54C9000};
f32 D_8080072C_gcmapsects_lagoontop[3] = {-9044.0f, 5.15e+03f, -3273.0f};
f32 D_80800738_gcmapsects_lagoontop[3] = {-6767.0f, -5.2e+02f, -103.0f};
f32 D_80800744_gcmapsects_lagoontop[3] = {-9044.0f, 5982.0f, -3273.0f};
