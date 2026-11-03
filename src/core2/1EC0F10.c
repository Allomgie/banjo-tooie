#include <ultra64.h>

int func_800F371C(u32[4], u32[4]);
void func_800F2E7C(u32[4], u32[4]);

typedef struct {
    u32 prim_color[4];
    u32 texture_lut;
    u32 cycle_type;
    u32 filtering_mode;
    u32 texture_persp;
    u32 combiner;
    u8 needs_pipesync;
    u8 unk25;
} RenderState;

extern RenderState D_8012D580;

void func_800E7620(void)
{
    D_8012D580.prim_color[0] = D_8012D580.prim_color[1] = D_8012D580.prim_color[2] =
        D_8012D580.prim_color[3] = D_8012D580.cycle_type = D_8012D580.combiner =
            D_8012D580.filtering_mode = (u32) -1;

    D_8012D580.texture_lut = 0;
    D_8012D580.texture_persp = G_TP_PERSP;
    D_8012D580.needs_pipesync = FALSE;
}

void func_800E765C(Gfx **gfx)
{
    if (D_8012D580.needs_pipesync) {
        gDPPipeSync((*gfx)++);
        D_8012D580.needs_pipesync = FALSE;
    }
}

void func_800E7694()
{
    D_8012D580.needs_pipesync = TRUE;
}

void func_800E76A4(Gfx **gfx, s32 arg1)
{
    if (D_8012D580.combiner != arg1) {
        D_8012D580.combiner = arg1;
        func_800E765C(gfx);
        switch (arg1) {
            case 0:
                gDPSetCombineLERP((*gfx)++, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                                  TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0);
                break;
            case 1:
                gDPSetCombineLERP((*gfx)++, 0, 0, 0, TEXEL0, TEXEL0, 0, TEXEL1, 0, COMBINED, 0,
                                  PRIMITIVE, 0, COMBINED, 0, PRIMITIVE, 0);
                break;
            case 2:
                gDPSetCombineLERP((*gfx)++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0,
                                  PRIMITIVE, 0, 0, 0, PRIMITIVE);
        }
    }
}

void func_800E7778(Gfx **gfx, u32 cycle_type)
{
    if (D_8012D580.cycle_type != cycle_type) {
        D_8012D580.cycle_type = cycle_type;
        func_800E765C(gfx);
        gDPSetCycleType((*gfx)++, cycle_type);

        if (cycle_type == G_CYC_1CYCLE) {
            gDPSetRenderMode((*gfx)++, G_RM_XLU_SURF | ZMODE_XLU, G_RM_XLU_SURF2 | ZMODE_XLU);
        } else {
            gDPSetRenderMode((*gfx)++, G_RM_PASS, G_RM_XLU_SURF2 | ZMODE_XLU);
        }
    }
}

void func_800E7828(Gfx **gfx, u8 color[4])
{
    u32 color_u32[4];
    func_800F2EFC(color_u32, color);
    if (!func_800F371C(D_8012D580.prim_color, color_u32)) {
        func_800F2E7C(D_8012D580.prim_color, color_u32);
        func_800E765C(gfx);

        gDPSetPrimColor((*gfx)++, 0, 0, color_u32[0], color_u32[1], color_u32[2], color_u32[3]);
    }
}

void func_800E78C8(Gfx **gfx, u32 mode)
{
    if (D_8012D580.filtering_mode != mode) {
        D_8012D580.filtering_mode = mode;
        func_800E765C(gfx);
        gDPSetTextureFilter((*gfx)++, mode);
    }
}

void func_800E7928(Gfx **gfx, u32 texture_lut)
{
    if (D_8012D580.texture_lut != texture_lut) {
        D_8012D580.texture_lut = texture_lut;
        func_800E765C(gfx);
        gDPSetTextureLUT((*gfx)++, texture_lut);
    }
}

void func_800E7988(Gfx **gfx, u32 texture_persp)
{
    if (D_8012D580.texture_persp != texture_persp) {
        D_8012D580.texture_persp = texture_persp;
        func_800E765C(gfx);
        gDPSetTexturePersp((*gfx)++, texture_persp);
    }
}

extern Gfx D_80123310[];

void func_800E79E8(Gfx **gfx)
{
    gSPDisplayList((*gfx)++, OS_K0_TO_PHYSICAL(D_80123310));
    func_800E7620();
    D_8012D580.unk25 = 1;
}

void func_800E7A2C(Gfx **gfx)
{
    func_800E7620();
}

void func_800E7A4C(Gfx **gfx)
{
    func_800E7928(gfx, G_TT_NONE);
    func_800E7988(gfx, G_TP_PERSP);
    func_800E78C8(gfx, G_TF_BILERP);
    D_8012D580.unk25 = 0;
}

Gfx D_80123310[6] = {0xE7000000, 0x0,        0xD9C0FFFA, 0x0, 0xD9FFFFFF, 0x200004,
                     0xD7000002, 0x80008000, 0xDF000000, 0x0, 0x0,        0x0};
