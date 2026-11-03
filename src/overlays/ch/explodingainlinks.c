#include "common.h"

extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern int D_808001B8_chexplodingchainlinks[];
void func_8080010C_chexplodingchainlinks();

int chexplodingchainlinks_entrypoint_0()
{
    extern void *D_80800170_chexplodingchainlinks;
    return (int) &D_80800170_chexplodingchainlinks;
}

void func_8080000C_chexplodingchainlinks(s32 arg0)
{
}

void func_80800014_chexplodingchainlinks(s32 arg0)
{
    _subaddieDll_entrypoint_7(arg0, 0xB);
}

s32 func_80800034_chexplodingchainlinks(s32 param_0, s32 param_1)
{
    f32 local_0[3];

    func_800E3A58(local_0);
    *(f32 *) ((char *) param_0 + 0x48) = local_0[1];
    func_80101870(param_0, param_1);
}

s32 func_80800070_chexplodingchainlinks(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    switch (param_1) {
        case 5:
            func_80101038(local_0);
            func_8080010C_chexplodingchainlinks(param_0, local_0);
            _chexploder_entrypoint_3(param_0, local_0, 8);
            break;
        case 0x90:
            _chexploder_entrypoint_6(func_80106790(func_80101080()), 300.0f, 400.0f);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080010C_chexplodingchainlinks(param_0, param_1) s32 param_0;
f32 *param_1;
{
    f32 sp24[3];

    func_800EE7F8(sp24, param_0 + 4, param_0);
    sp24[1] = param_1[1];
    func_800BBCB8(sp24, sp24, 0x3F4CCCCD, 4, &D_808001B8_chexplodingchainlinks);
}

extern void func_80105834();
extern void func_80107C2C();
void *D_80800170_chexplodingchainlinks = (void *) 0x01580473;
static u32 D_80800170_chexplodingchainlinks_rest[17] = {0x7BC0001,
                                                        0x0,
                                                        (u32) func_80800014_chexplodingchainlinks,
                                                        (u32) func_80105834,
                                                        (u32) func_80800034_chexplodingchainlinks,
                                                        0x0,
                                                        0x0,
                                                        0x0,
                                                        0x4,
                                                        0x0,
                                                        0x0,
                                                        0x0,
                                                        (u32) func_8080000C_chexplodingchainlinks,
                                                        (u32) func_80107C2C,
                                                        0x80000002,
                                                        (u32) func_80800070_chexplodingchainlinks,
                                                        0x0};
int D_808001B8_chexplodingchainlinks[14] = {0x1D09E2,  0x220026, 0x260019, 0x190027,  0xC8,
                                            0xF0,      0x150000, 0xCC002B, 0x14C01B3, 0x2D00FA,
                                            0x190000E, 0xA0014,  0x1BFC18, -0x3200000};
