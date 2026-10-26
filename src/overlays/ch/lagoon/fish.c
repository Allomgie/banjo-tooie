#include "common.h"

extern void func_80102B6C(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
typedef struct { u8 pad_0[0x70]; u32 pad_70_10 : 22; u32 unk70_4 : 6; u32 pad_70_0 : 4; } EelRouteActor;
extern void func_800EEC30(f32[3], f32, f32, f32);
extern void func_800EF04C(f32[3], f32[3]);
extern s32 func_800CC338(f32[3], s32, s32);
typedef struct LagoonFishItem { f32 local_0[3]; f32 local_1[3]; u8 pad_0[0xC]; f32 local_2; u8 pad_1[4]; u8 local_3; u8 pad_2[3]; } LagoonFishItem;
extern void *func_80100094(Actor *, u32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern f32 func_800DC178(f32, f32);
typedef struct { s16 a, b; } S16Pair;
extern u8 D_8012762C;
extern void func_80103140();
extern void *D_80800B70_chlagoonfish;
typedef struct { f32 local_0[3]; f32 local_1[3]; f32 local_2[3]; f32 local_3; f32 local_4; u8 local_5; u8 local_6[3]; } LagoonFishParticle;
extern void func_800EF214(f32 *, f32, f32, f32);
typedef struct { f32 pos[3]; f32 unkC; f32 unk10; f32 unk14; f32 target[3]; f32 pad24; f32 unk28; f32 pad2C; } LagoonFish;
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1828(f32 *, f32 *);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern f32 func_800DC0C0(void);
extern f32 func_800D8FF8(void);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EE780(f32 *, f32 *, f32 *);
void func_80800A44_chlagoonfish();
void func_80800000_chlagoonfish();

void func_80800000_chlagoonfish(param_0) Actor *param_0;
{
    LagoonFishParticle *local_0;
    u32 local_1;
    f32 local_2;
    f32 local_3;
    func_80100074(param_0, 0, param_0->unk6C_0 * sizeof(LagoonFishParticle));
    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < param_0->unk6C_0; local_1++, local_0++) {
        func_800EE7F8(local_0->local_0, param_0->position);
        local_2 = func_800DC178(-45.0f, 45.0f);
        local_3 = func_800DC178(180.0f, 360.0f);
        func_800EF214(local_0->local_0, local_2, local_3, func_800DC178(50.0f, 250.0f));
        local_0->local_3 = func_800DC178(param_0->scale * 0.4f, param_0->scale);
        local_0->local_5 = func_800DC128(0, 3);
        local_0->local_2[0] = func_800DC178(-400.0f, 400.0f);
        local_0->local_2[1] = func_800DC178(-400.0f, 400.0f);
        local_0->local_2[2] = func_800DC178(-400.0f, 400.0f);
        local_0->local_4 = 400.0f;
    }
}

void func_808001A0_chlagoonfish(Actor *param_0)
{
    s32 local_0;
    local_0 = param_0->unk74_7;
    if (local_0 < 0x33) {
        func_800FFAB0(param_0);
    } else {
        param_0->unk6C_0 = local_0 - 0x32;
        func_80800000_chlagoonfish(param_0);
        func_80800A44_chlagoonfish(param_0, 1);
        *(f32 *)&param_0->actorData[3] = param_0->scale * 600.0f;
        *(f32 *)&param_0->actorData[7] = _subaddiesect_entrypoint_1(param_0);
    }
}

void func_80800240_chlagoonfish(param_0) s32 param_0; {
    func_80100074(param_0, 0, 0);
}

void func_80800264_chlagoonfish()
{
    func_80800240_chlagoonfish();
}

void func_80800284_chlagoonfish(Actor *param_0)
{
    func_80102B6C(param_0, 2.0f);
    func_80102B2C(param_0, 2.0f);
    if ((func_8010B990(param_0, 0x500106) & 0x24) && param_0->unk70_10 != 2) {
        func_80800A44_chlagoonfish(param_0, 2);
    }
}

s32 func_808002F8_chlagoonfish(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;

    func_800EEC30(local_0, param_0->rotation[0], param_0->rotation[1], 200.0f);
    func_800EF04C(local_0, param_0->position);
    local_1 = func_800CC338(local_0, (*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1,
        ((*(u32 *)((u8 *)param_0 + 0x70) << 22) >> 26) - 1);
    if (local_1 != -1) {
        ((EelRouteActor *)param_0)->unk70_4 = local_1 + 1;
        return 1;
    }
    return 0;
}

void func_8080038C_chlagoonfish(Actor *param_0)
{
    LagoonFish *s0;
    f32 sp88[3];
    f32 sp84;
    f32 sp80;
    s32 sp7C;
    u32 i;
    f32 sp6C[3];
    f32 f2;
    f32 sp5C[3];

    if (func_80100094(param_0, 0) == NULL) {
        func_80800000_chlagoonfish(param_0);
    }
    switch (param_0->unk70_10) {
    case 1:
        func_80800284_chlagoonfish(param_0);
        if (!func_808002F8_chlagoonfish(param_0)) {
            func_80800A44_chlagoonfish(param_0, 2);
        } else if (600.0f * param_0->scale < *(f32 *)&param_0->actorData[3]) {
            *(f32 *)&param_0->actorData[3] -= 5.0f * param_0->scale;
        }
        if (func_800DC0C0() < 0.2f) {
            param_0->unk50 += func_800DC178(-15.0f, 15.0f);
        }
        if (func_800DC0C0() < 0.2f) {
            param_0->unk54 += func_800DC178(-15.0f, 15.0f);
        }
        break;
    case 2:
        param_0->unk54 = func_800F1DF4(param_0->position, (f32 *)param_0->actorData);
        param_0->unk50 = func_800F1828(param_0->position, (f32 *)param_0->actorData);
        func_80800284_chlagoonfish(param_0);
        if (func_800EFFB4((f32 *)param_0->actorData, 200.0f, param_0->position)) {
            if (func_808002F8_chlagoonfish(param_0)) {
                func_80800A44_chlagoonfish(param_0, 1);
            }
        } else if (600.0f * param_0->scale < *(f32 *)&param_0->actorData[3]) {
            *(f32 *)&param_0->actorData[3] -= 15.0f * param_0->scale;
        }
        break;
    }
    sp80 = func_800D8FF8();
    sp7C = func_8001210C(1);
    s0 = func_80100094(param_0, 0);
    func_8008FFBC(sp88);
    sp84 = mlAbsF(sp88[0]) + mlAbsF(sp88[1]) + mlAbsF(sp88[2]);
    func_8008FE68(sp88);
    for (i = 0; i < param_0->unk6C_0; i++) {
        func_800EF214(s0->pos, s0->unkC, s0->unk10, s0->unk28 * sp80);
        if ((sp7C && (i & 1)) || (!sp7C && !(i & 1))) {
            if (func_800EFFB4(s0->pos, sp84 * 0.5f, sp88)) {
                func_800F18FC(sp88, s0->pos, sp6C);
                if (s0->unk28 < 400.0f * param_0->scale) {
                    s0->unk28 += 50.0f * param_0->scale;
                }
            } else {
                func_800EE780(sp5C, param_0->position, s0->target);
                func_800F18FC(s0->pos, sp5C, sp6C);
                if (s0->unk28 > 400.0f * param_0->scale) {
                    s0->unk28 -= 50.0f * param_0->scale;
                }
            }
            if (func_800DC0C0() < 0.02f) {
                s0->target[0] = func_800DC178(-400.0f, 400.0f);
                s0->target[1] = func_800DC178(-400.0f, 400.0f);
                s0->target[2] = func_800DC178(-400.0f, 400.0f);
            }
            f2 = func_800F1DCC(sp6C[1], s0->unk10);
            if (f2 > 1.0f) {
                if (s0->unk14 < 8.0f) {
                    s0->unk14 += 2.0f;
                }
                s0->unk10 += s0->unk14 * 0.5f;
                s0->unk14 *= 0.9f;
            } else if (f2 < -1.0f) {
                if (-8.0f < s0->unk14) {
                    s0->unk14 -= 2.0f;
                }
                s0->unk10 += s0->unk14 * 0.5f;
                s0->unk14 *= 0.9f;
            }
            f2 = func_800F1DCC(sp6C[0], s0->unkC);
            if (f2 > 1.0f) {
                if (s0->unkC < 10.0f) {
                    s0->unkC += 1.0f;
                }
            } else if (f2 < -1.0f) {
                if (-10.0f < s0->unkC) {
                    s0->unkC -= 1.0f;
                }
            }
        }
        s0++;
    }
}

void func_80800908_chlagoonfish(Actor *param_0, s32 param_1)
{
    s32 local_1;
    LagoonFishItem *local_2;
    void *local_0[3];

    local_2 = func_80100094(param_0, 0);
    if (local_2 != NULL) {
        for (local_1 = 0; local_1 < 3; local_1++) {
            local_0[local_1] = (void *)func_800D674C(param_0->unk0->unk14 + local_1);
        }
        for (local_1 = 0; local_1 < param_0->unk6C_0; local_1++, local_2++) {
            if (local_0[local_2->local_3] != NULL) {
                func_800DF830(1);
                func_800DE448(local_2->local_0, local_2->local_1, local_2->local_2, NULL, (s32)local_0[local_2->local_3]);
            }
        }
    }
}

void func_808009FC_chlagoonfish(u8 *arg0) {
    u32 temp_v0;

    temp_v0 = *(u32 *)(arg0 + 0x70);
    func_800EE7F8(arg0 + 0x18, func_800CC63C((temp_v0 >> 25) - 1, ((temp_v0 << 22) >> 26) - 1));
}

void func_80800A44_chlagoonfish(param_0, param_1) Actor *param_0; s32 param_1;
{
    func_80101FDC(param_0, param_1);
    switch (param_1) {
    case 1:
        param_0->unk54 = param_0->rotation[1] + func_800DC178(-90.0f, 90.0f);
        param_0->unk50 = param_0->rotation[0] + func_800DC178(-90.0f, 90.0f);
        break;
    case 2:
        func_808009FC_chlagoonfish(param_0);
        break;
    }
}

s32 func_80800AE0_chlagoonfish(u8 **param_0, s32 param_1, S16Pair param_2) {
    if (param_1 == 0x95) {
        if (D_8012762C == 0x15) {
            func_80103140(param_0, 0x698, *(u16 *)(*param_0 + 0x16));
        }
    } else {
        return 0;
    }
    return 1;
}

int chlagoonfish_entrypoint_0()
{
  return &D_80800B70_chlagoonfish;
}
