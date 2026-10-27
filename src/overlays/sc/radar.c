#include "common.h"
#include "overlays/ba/playerstate.h"

#define SCRADAR_VIEW_TYPE
#define SCRADAR_BLIP_TYPE
#define SCRADAR_SET_CYCLE_TYPE(pkt, type) \
{ \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = _SHIFTL(0xE3, 24, 8) | _SHIFTL(32 - G_MDSFT_CYCLETYPE - 2, 8, 8) | _SHIFTL(2 - 1, 0, 8); \
    _g->words.w1 = (unsigned int)(type); \
}
#define SCRADAR_FOG_COLOR(pkt, r, g, b, a) \
    gDPSetColor(pkt, G_SETFOGCOLOR, _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(a, 0, 8) | _SHIFTL(b, 8, 8))
#define SCRADAR_TEXTURE_RECT(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy) \
{ \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = _SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12); \
    _g->words.w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12); \
    gImmp1(pkt, 0xE1, _SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16)); \
    gImmp1(pkt, 0xF1, _SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16)); \
}
extern PlayerState *func_800F53D0(u32);
typedef struct { u8 pad_0[4]; s16 local_0; s16 local_1; u8 local_2[4]; u8 local_3; u8 local_4; u8 pad_1[2]; } RadarIcon211;
typedef struct { s32 local_0; s32 local_1; u8 local_2; u8 pad_0; s16 local_3; s16 local_4; s16 local_5; RadarIcon211 local_6[6]; RadarIcon211 local_7[8]; } RadarView211;
extern RadarView211 B_80800E50_scradar[];
extern s16 D_80800E30_scradar[];
extern u8 D_80800E3C_scradar[][2];
extern void func_800F5A00(s32, f32 *);
extern f32 func_800F5F24(u32);
typedef struct { f32 unk0; s16 unk4; s16 unk6; u8 pad8[4]; u8 unkC; u8 unkD; } RadarBlip;
extern void func_800E253C(f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 sqrtf(f32);
extern f32 func_80013B70(f32, f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800137F4(f32);
extern f32 func_80013788();
extern f32 func_800F0DC0(f32, f32);
void func_80800000_scradar();
void func_808007D4_scradar(RadarBlip *param_0, f32 *param_1, f32 param_2);

void func_80800000_scradar(param_0, param_1, param_2) Gfx **param_0; s32 *param_1; void *param_2;
{
    s32 local_0;
    s32 local_1;
    char *local_7;

    local_7 = (char *)param_2;
    local_0 = (param_1[0] + *(s16 *)(local_7 + 4)) & ~3;
    local_1 = (param_1[1] + *(s16 *)(local_7 + 6)) & ~3;

    gDPPipeSync((*param_0)++);

    switch (*(u8 *)(local_7 + 0xC)) {
        case 0:
            SCRADAR_FOG_COLOR((*param_0)++, 0xFF, 0xFF, 0xFF, 0x80);

            SCRADAR_TEXTURE_RECT(
                (*param_0)++,
                local_0 - 4,
                local_1,
                local_0 + 8,
                local_1 + 4,
                G_TX_RENDERTILE,
                0,
                0,
                0x100,
                0x100
            );

            SCRADAR_TEXTURE_RECT(
                (*param_0)++,
                local_0,
                local_1 - 4,
                local_0 + 4,
                local_1 + 8,
                G_TX_RENDERTILE,
                0,
                0,
                0x100,
                0x100
            );
            break;

        case 1: {
            s32 local_6;
            local_6 = *(u8 *)(local_7 + 0xB);

            SCRADAR_FOG_COLOR(
                (*param_0)++,
                (*(u8 *)(local_7 + 8)) >> 2,
                (*(u8 *)(local_7 + 9)) >> 2,
                (*(u8 *)(local_7 + 0xA)) >> 2,
                (local_6 >> 1) + (local_6 >> 2)
            );

            SCRADAR_TEXTURE_RECT(
                (*param_0)++,
                local_0 - 8,
                local_1 - 8,
                local_0 + 8,
                local_1 + 8,
                G_TX_RENDERTILE,
                0,
                0,
                0x100,
                0x100
            );

            gDPPipeSync((*param_0)++);

            SCRADAR_FOG_COLOR(
                (*param_0)++,
                (*(u8 *)(local_7 + 8)),
                (*(u8 *)(local_7 + 9)),
                (*(u8 *)(local_7 + 0xA)),
                local_6
            );

            SCRADAR_TEXTURE_RECT(
                (*param_0)++,
                local_0 - 4,
                local_1 - 4,
                local_0 + 4,
                local_1 + 4,
                G_TX_RENDERTILE,
                0,
                0,
                0x100,
                0x100
            );
            break;

        }
        case 2:
            if (func_8001210C(4) == 0) {
                break;
            }

            SCRADAR_FOG_COLOR(
                (*param_0)++,
                *(u8 *)(local_7 + 8),
                *(u8 *)(local_7 + 9),
                *(u8 *)(local_7 + 0xA),
                *(u8 *)(local_7 + 0xB)
            );

            SCRADAR_TEXTURE_RECT(
                (*param_0)++,
                local_0 - 4,
                local_1,
                local_0 + 8,
                local_1 + 4,
                G_TX_RENDERTILE,
                0,
                0,
                0x100,
                0x100
            );

            SCRADAR_TEXTURE_RECT(
                (*param_0)++,
                local_0,
                local_1 - 4,
                local_0 + 4,
                local_1 + 8,
                G_TX_RENDERTILE,
                0,
                0,
                0x100,
                0x100
            );
            break;

        case 4: {
            s32 local_2;
            local_2 = (s32)(*(f32 *)local_7 * 8.0f);

            SCRADAR_FOG_COLOR(
                (*param_0)++,
                0,
                0,
                0,
                *(u8 *)(local_7 + 0xB) >> 1
            );

            SCRADAR_TEXTURE_RECT(
                (*param_0)++,
                local_0 - 6,
                local_1 - 14,
                local_0 + 6,
                local_1 + 14,
                G_TX_RENDERTILE,
                0,
                0,
                0x100,
                0x100
            );

            SCRADAR_TEXTURE_RECT(
                (*param_0)++,
                local_0 - 10,
                local_1 + local_2 - 6,
                local_0 + 10,
                local_1 + local_2 + 6,
                G_TX_RENDERTILE,
                0,
                0,
                0x100,
                0x100
            );

            gDPPipeSync((*param_0)++);
        }
        /* Fall through to draw the foreground after its shadow. */
        case 3: {
            s32 local_2;
            local_2 = (s32)(*(f32 *)local_7 * 8.0f);

            SCRADAR_FOG_COLOR(
                (*param_0)++,
                *(u8 *)(local_7 + 8),
                *(u8 *)(local_7 + 9),
                *(u8 *)(local_7 + 0xA),
                *(u8 *)(local_7 + 0xB)
            );

            SCRADAR_TEXTURE_RECT(
                (*param_0)++,
                local_0 - 2,
                local_1 - 10,
                local_0 + 2,
                local_1 + 10,
                G_TX_RENDERTILE,
                0,
                0,
                0x100,
                0x100
            );

            SCRADAR_TEXTURE_RECT(
                (*param_0)++,
                local_0 - 6,
                local_1 + local_2 - 2,
                local_0 + 6,
                local_1 + local_2 + 2,
                G_TX_RENDERTILE,
                0,
                0,
                0x100,
                0x100
            );
            break;
        }
    }
}

s32 func_8080074C_scradar(u8 *output, u8 param_1, u8 param_2, u8 param_3) {
    output[0] = param_1;
    output[1] = param_2;
    output[2] = param_3;
}

s32 func_80800768_scradar(u32 param_0)
{
    switch (func_800F5410(param_0)) {
    case 0xC:
        return 3;
    case 6:
        return 4;
    }
    if (func_8009E674(func_800F53D0(param_0), 0x20)) {
        return 2;
    }
    return 1;
}

void func_808007D4_scradar(RadarBlip *param_0, f32 *param_1, f32 param_2)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2;
    f32 local_4;

    local_0 = param_0->unkD;
    func_800F5A00(local_0, local_1);
    func_800EFB24(local_1, param_1, local_1);
    local_2 = sqrtf(local_1[0] * local_1[0] + local_1[2] * local_1[2]);
    local_4 = func_800136E4(func_80013B70(local_1[0], local_1[2], local_2) - param_2);
    if (local_2 > 5000.0f) {
        local_2 = 5000.0f;
    }
    local_2 *= 0.01f;
    param_0->unk4 = -func_800137F4(local_4) * local_2;
    param_0->unk6 = -func_80013788() * local_2;
    param_0->unkC = func_80800768_scradar(local_0);
    switch (param_0->unkC) {
    case 1:
    case 2:
        local_4 = 0.0f;
        break;
    case 3:
    case 4:
        local_4 = func_800F0DC0(local_1[1] * 0.001f, 1.0f);
        break;
    default:
        local_4 = 0.0f;
        break;
    }
    param_0->unk0 = local_4;
}

void scradar_entrypoint_0(void)
{
    s32 local_0;
    s32 local_1 = 0;
    s32 local_2;
    s32 local_3;
    RadarView211 *local_4;
    s32 local_5;
    s32 local_6;
    u8 local_7;
    RadarIcon211 *local_8;
    f32 local_9;
    s32 local_10;
    s32 local_11;
    s32 local_12;
    s32 local_13;
    Vec3f local_14;
    RadarView211 *local_15;
    s32 local_16;
    s32 local_21; /* now unused: keeps its frame slot (removing it: 21) */

    local_0 = func_800A946C();
    if (func_80800768_scradar(0) == 4) {
        local_1 = 1;
    }
    for (local_6 = 0; local_6 < local_0; local_6++) {
        local_2 = _gcstatusDll_entrypoint_16(local_6);
        B_80800E50_scradar[local_6].local_4 = 1;
        B_80800E50_scradar[local_6].local_3 = D_80800E30_scradar[local_2];
        B_80800E50_scradar[local_6].local_5 = 0;
        B_80800E50_scradar[local_6].local_2 = D_80800E3C_scradar[local_2][local_1];
    }
    for (local_5 = 0; local_5 < 8; local_5++) {
        if (func_800F6438(local_5)) {
            local_6 = func_800A940C(local_5);
            local_2 = _gcstatusDll_entrypoint_16(local_6);
            local_7 = func_80092258(func_800F53D0(local_5));
            for (local_3 = 0; local_3 < local_0; local_3++) {
                local_4 = &B_80800E50_scradar[local_3];
                if (_gcstatusDll_entrypoint_16(local_3) == local_2) {
                    if (local_3 == local_6 && func_800A9420(local_5)) {
                        local_8 = &local_4->local_6[0];
                        local_8->local_2[3] = 0xC0;
                    } else {
                        local_8 = (RadarIcon211 *)((local_4->local_4++ << 4) + (u8 *)local_4 + 0x10);
                        local_8->local_2[3] = 0x60;
                    }
                } else {
                    local_8 = (RadarIcon211 *)((local_4->local_5++ << 4) + (u8 *)local_4 + 0x70);
                    local_8->local_2[3] = local_7;
                }
                local_8->local_4 = local_5;
            }
        }
    }
    for (local_6 = 0; local_6 < local_0; local_6++) {
        local_15 = B_80800E50_scradar + local_6; /* agV31: other IV expression than loop 1 -> separate strength-reduced IVs (loop-1 IV s0) */
        func_800A8A04(local_6, &local_10, &local_11, &local_12, &local_13);
        local_15->local_0 = (local_12 + local_10 - 25) << 2;
        local_15->local_1 = (local_13 + local_11 - 19) << 2;
        if (local_15->local_4) {
            local_15->local_6[0].local_0 = 0;
            local_15->local_6[0].local_1 = 0;
            local_15->local_6[0].local_3 = 0;
            local_8 = &local_15->local_6[0];
            func_800F5A00(local_15->local_6[0].local_4, local_14.f);
            local_9 = func_800F5F24(local_8->local_4) + 180.0f;
            for (local_16 = 1; local_16 < local_15->local_4; local_16++) {
                local_8 = (RadarIcon211 *)((u8 *)local_15 + (local_16 << 4) + 0x10);
                func_808007D4_scradar((RadarBlip *)local_8, local_14.f, local_9);
                func_8080074C_scradar(local_8->local_2, 255, 255, 255);
            }
            for (local_16 = 0; local_16 < local_15->local_5; local_16++) {
                func_8080074C_scradar((u8 *)local_15 + (local_16 << 4) + 0x78, 255, 32, 32);
                func_808007D4_scradar((RadarBlip *)((u8 *)local_15 + (local_16 << 4) + 0x70), local_14.f, local_9);
            }
        }
    }
}

void scradar_entrypoint_1(Gfx **param_0)
{
    RadarView211 *local_0;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    local_2 = func_800A946C();
    for (local_3 = 0; local_3 < local_2; local_3++) {
        local_0 = &B_80800E50_scradar[local_3];
        if (local_0->local_4) {
            func_800E253C(1.25f);
            func_800E257C(local_0->local_2);
            func_800E2434(1);
            local_5 = func_800A7180();
            func_800E30E0(local_5, func_800D674C(local_0->local_3), 0, local_0);
        }
    }
    func_800B9990(param_0);
    for (local_3 = 0; local_3 < local_2; local_3++) {
        if (B_80800E50_scradar[local_3].local_4) {
            local_0 = &B_80800E50_scradar[local_3];
            for (local_4 = 0; local_4 < local_0->local_4; local_4++) {
                func_80800000_scradar(param_0, &local_0->local_0, (u8 *)local_0 + (local_4 << 4) + 0x10);
            }
            for (local_4 = 0; local_4 < local_0->local_5; local_4++) {
                func_80800000_scradar(param_0, &local_0->local_0, (u8 *)local_0 + (local_4 << 4) + 0x70);
            }
        }
    }
    gDPPipeSync((*param_0)++);
    SCRADAR_SET_CYCLE_TYPE((*param_0)++, G_CYC_2CYCLE);
}
