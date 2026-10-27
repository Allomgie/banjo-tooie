#include "common.h"

typedef struct { f32 local_0[3]; f32 local_1[3]; f32 local_2[3]; s16 local_3; s16 local_4; s16 local_5; s16 pad_0; } LagoonSector1180;
extern LagoonSector1180 D_80800630_gcmapsects_lagoontop[5];
extern s16 D_8080070C_gcmapsects_lagoontop[4][2];
extern s16 D_8080071C_gcmapsects_lagoontop[2];
extern void _gcmapsects_lagoontop_entrypoint_1();
extern void _gcmapsects_entrypoint_0(s32, s32, f32 *, f32 *, void *, f32);
typedef struct { u8 pad[0x1AC]; u32 b31 : 1; u32 b30 : 1; u32 rest : 30; } W428;
typedef struct { u8 pad[0x4C]; u32 b31 : 1; u32 b30 : 1; u32 rest : 30; } W76;
typedef struct { u8 pad[0x4C]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS76;
typedef struct { u8 pad[0xA4]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS164;
typedef struct { u8 pad[0xFC]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS252;
typedef struct { u8 pad[0x1AC]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS428;
typedef struct { u8 pad[0x68]; char *obj; u8 pad2[0x12]; u8 f7E; } LagoonCtx;
extern void func_800E39A8(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 func_800136E4(f32);
extern s32 func_800E3E8C(void *, f32);
extern f32 D_80800720_gcmapsects_lagoontop[];
extern f32 D_8080072C_gcmapsects_lagoontop[];
extern f32 D_80800738_gcmapsects_lagoontop[];
extern f32 D_80800744_gcmapsects_lagoontop[];

void gcmapsects_lagoontop_entrypoint_0(void)
{
    u32 local_0;
    s16 (*local_1)[2];

    _gcmapsects_entrypoint_10(5);
    for (local_0 = 0; local_0 < 5; local_0++) {
        _gcmapsects_entrypoint_0(D_80800630_gcmapsects_lagoontop[local_0].local_4,
            D_80800630_gcmapsects_lagoontop[local_0].local_5,
            D_80800630_gcmapsects_lagoontop[local_0].local_0,
            D_80800630_gcmapsects_lagoontop[local_0].local_1,
            D_80800630_gcmapsects_lagoontop[local_0].local_2,
            D_80800630_gcmapsects_lagoontop[local_0].local_3);
    }
    local_1 = D_8080070C_gcmapsects_lagoontop;
    local_0 = 0;
    do {
        _gcmapsects_entrypoint_3((*local_1)[0], (*local_1)[1]);
        local_1++;
    } while (++local_0 < 4);
    for (local_0 = 0; local_0 < 2; local_0++) {
        _gcmapsects_entrypoint_1(D_8080071C_gcmapsects_lagoontop[local_0], 0);
        _gcmapsects_entrypoint_2(D_8080071C_gcmapsects_lagoontop[local_0], 0);
    }
    _gcmapsects_entrypoint_12(_gcmapsects_lagoontop_entrypoint_1);
}

void gcmapsects_lagoontop_entrypoint_1(LagoonCtx *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    u8 local_2;

    func_800E39A8(local_0, local_1);
    local_1[0] = func_80013728(local_1[0]);
    local_1[1] = func_800136E4(local_1[1]);

    if ((*(u32 *)(param_0->obj + 0xA4) >> 31) != 0) {
        if (local_0[1] < 5100.0f) {
            ((BitS164 *)param_0->obj)->b7 = 0;
            ((BitS164 *)param_0->obj)->b6 = 0;
        }
        if (-5800.0f < local_0[2] && 95.0f < local_1[1] && local_1[1] < 240.0f) {
            ((BitS164 *)param_0->obj)->b7 = 0;
            ((BitS164 *)param_0->obj)->b6 = 0;
        }
    }
    if ((*(u32 *)(param_0->obj + 0x4C) >> 31) != 0) {
        if (local_0[1] < 4200.0f && local_1[0] < 0.0f) {
            ((BitS76 *)param_0->obj)->b7 = 0;
        } else if (local_0[1] < 5050.0f && !func_800E3E8C(D_80800720_gcmapsects_lagoontop, 1250.0f)) {
            ((BitS76 *)param_0->obj)->b7 = 0;
            ((BitS76 *)param_0->obj)->b6 = 0;
        }
    }
    if ((*(u32 *)(param_0->obj + 0x1AC) >> 31) != 0) {
        if (4300.0f < local_0[1]) {
            ((BitS428 *)param_0->obj)->b7 = 0;
            ((BitS428 *)param_0->obj)->b6 = 0;
        }
    }
    if ((*(u32 *)(param_0->obj + 0xFC) >> 31) != 0) {
        if (0.0f < local_0[2] && 160.0f < local_1[1] && local_1[1] < 320.0f) {
            ((BitS252 *)param_0->obj)->b7 = 0;
            ((BitS252 *)param_0->obj)->b6 = 0;
        } else if (5150.0f < local_0[1] && !func_800E3E8C(D_8080072C_gcmapsects_lagoontop, 1000.0f)) {
            ((BitS252 *)param_0->obj)->b7 = 0;
            ((BitS252 *)param_0->obj)->b6 = 0;
        } else if (-4700.0f < local_0[0] && local_0[1] < 10000.0f) {
            ((BitS252 *)param_0->obj)->b7 = 0;
            ((BitS252 *)param_0->obj)->b6 = 0;
        }
    }
    if (*(u32 *)(param_0->obj + 0x1AC) >> 31) {
        if (4000.0f < local_0[2]) {
            if (90.0f < local_1[1]) {
                if (local_1[1] < 270.0f) {
                    ((BitS428 *)param_0->obj)->b7 = 0;
                    ((BitS428 *)param_0->obj)->b6 = 0;
                }
            }
        } else if (!((W428 *)param_0->obj)->b30 && !func_800E3E8C(D_80800738_gcmapsects_lagoontop, 450.0f)) {
            ((BitS428 *)param_0->obj)->b7 = 0;
            ((BitS428 *)param_0->obj)->b6 = 0;
        }
    }
    local_2 = param_0->f7E;
    if (local_2 && ((local_0[1] < 8000.0f && local_1[0] < -20.0f) || (local_0[1] < 6000.0f && local_1[0] < 0.0f))) {
        local_2 = param_0->f7E = 0;
    }
    if (local_2 && local_0[1] < 4000.0f && local_1[0] >= 0.0f) {
        param_0->f7E = func_800E3E8C(D_80800744_gcmapsects_lagoontop, 982.0f);
    }
    if (((W76 *)param_0->obj)->b30) {
        ((BitS164 *)param_0->obj)->b6 = 1;
    }
}
