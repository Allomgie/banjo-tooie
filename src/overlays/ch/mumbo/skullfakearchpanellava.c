#include "common.h"

extern s32 D_80800160_chmumboskullfakearchpanellava[];
extern u8 D_808001CC_chmumboskullfakearchpanellava[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void *D_808001E0_chmumboskullfakearchpanellava;
extern int D_80800228_chmumboskullfakearchpanellava[];

int func_80800000_chmumboskullfakearchpanellava()
{
    if (func_800EA05C() == 0x134) {
        return 0x39C;
    }
    if (func_800EA05C() == 0xEF) {
        return 0x39D;
    }
    return 0;
}

int func_80800054_chmumboskullfakearchpanellava(s32 param_0)
{
    if (func_800DA298(func_80800000_chmumboskullfakearchpanellava(param_0))) {
        func_800FFAB0(param_0);
    }
}

s32 func_8080008C_chmumboskullfakearchpanellava(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 *local_0;

    switch (param_1) {
        case 0x40:
            local_0 = param_0->position;
            _chexploder_entrypoint_3(param_0, local_0, 0xC);
            func_800BABB8(0, local_0, local_0, param_0->scale,
                          D_80800160_chmumboskullfakearchpanellava);
            func_800C4AF0(local_0, D_808001CC_chmumboskullfakearchpanellava);
            func_800DA544(func_80800000_chmumboskullfakearchpanellava());
            break;
        default:
            return 0;
    }
    return 1;
}

void *chmumboskullfakearchpanellava_entrypoint_0(void)
{
    return &D_808001E0_chmumboskullfakearchpanellava;
}

s32 func_8080012C_chmumboskullfakearchpanellava(s32 param_0)
{
    func_800EFD24(param_0 + 4);
}

int chmumboskullfakearchpanellava_entrypoint_1()
{
    return (int) &D_80800228_chmumboskullfakearchpanellava;
}

extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _bsbtrot_entrypoint_8();
s32 D_80800160_chmumboskullfakearchpanellava[27] = {
    0x610001D, 0x9DD002B, 0x2000300, 0x220180, 0x2000480,  0x6000015, 0x26,
    0x190000,  0x7002D,   0x320064,  0x20DEA7, 0x71C0000A, -0x63FFE7, -0x63FF9C,
    0x4B0064,  0x61A1910, 0x1D06A0,  0x14002D, 0x1900258,  0x1BFCE0,  -0x257FFDE,
    0xB300CC,  0xB300B3,  0x1E0032,  0x32000D, 0x4B191A,   0x0};
u8 D_808001CC_chmumboskullfakearchpanellava[20] = {0x0,  0x13, 0x4,  0x13, 0x0,  0xA, 0x0,
                                                   0xE6, 0x0,  0x16, 0x6D, 0x60, 0x0, 0x1,
                                                   0x19, 0x64, 0x19, 0x64, 0x0,  0x0};
void *D_808001E0_chmumboskullfakearchpanellava = (void *) 0x00AC0280;
static u32 D_808001E0_chmumboskullfakearchpanellava_rest[17] = {
    0x8E20001,
    0x0,
    (u32) func_80102EC0,
    (u32) func_80105834,
    (u32) func_80101870,
    0x0,
    0x0,
    0x0,
    0x10000800,
    0x0,
    (u32) func_80108ED0,
    0x0,
    (u32) func_80800054_chmumboskullfakearchpanellava,
    (u32) func_80107C2C,
    (u32) _bsbtrot_entrypoint_8,
    (u32) func_8080008C_chmumboskullfakearchpanellava,
    0x0};
int D_80800228_chmumboskullfakearchpanellava[18] = {
    0xAC0495,
    0x8E30001,
    0x0,
    0x0,
    (u32) func_80105834,
    (u32) func_80101870,
    0x0,
    0x0,
    0x0,
    0x10000C00,
    0x0,
    0x0,
    0x0,
    (u32) func_8080012C_chmumboskullfakearchpanellava,
    (u32) func_80107C2C,
    -0x7FF7D3FE,
    0x0,
    0x0};
