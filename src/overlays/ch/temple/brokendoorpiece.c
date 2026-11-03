#include "common.h"

extern u8 D_80800100_chtemplebrokendoorpiece[];
extern u8 D_80800114_chtemplebrokendoorpiece[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern int D_8080015C_chtemplebrokendoorpiece[];

void func_80800000_chtemplebrokendoorpiece(s32 arg0)
{
}

void func_80800008_chtemplebrokendoorpiece(Actor *param_0)
{
    func_800BABB8(0, (s32 *) ((char *) param_0 + 4), (s32 *) ((char *) param_0 + 4),
                  *(s32 *) ((char *) param_0 + 0x38), &D_80800114_chtemplebrokendoorpiece);
    _subaddieaudioquick_entrypoint_2(param_0, (s32 *) ((char *) param_0 + 4),
                                     &D_80800100_chtemplebrokendoorpiece);
    func_800DA544(0xC9);
}

int func_80800068_chtemplebrokendoorpiece(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    switch (param_1) {
        case 0x40:
            func_800EE7F8(local_0, param_0->position);
            func_800EF1B8(local_0, param_0->rotation[1], 400.0f);
            local_0[1] -= 100.0f;
            _chexploder_entrypoint_3(param_0, local_0, 12);
            func_80800008_chtemplebrokendoorpiece(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

int chtemplebrokendoorpiece_entrypoint_0()
{
    return (int) &D_8080015C_chtemplebrokendoorpiece;
}

extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_80800100_chtemplebrokendoorpiece[20] = {0x0,  0x13, 0x4, 0x13, 0x0, 0xA,  0x0, 0xE6, 0x0, 0x16,
                                             0x6D, 0x60, 0x0, 0x1,  0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0};
u8 D_80800114_chtemplebrokendoorpiece[72] = {
    0x5,  0x10, 0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x3,  0x0,  0x4,  0x0,  0x0,  0x22, 0x2,
    0x0,  0x2,  0x80, 0x6,  0x0,  0x8,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x99, 0x0,  0x19,
    0x0,  0x0,  0x0,  0x7,  0x0,  0x2C, 0xFF, 0xEC, 0x0,  0x14, 0xFF, 0xEC, 0x0,  0x14, 0x0,
    0x28, 0x0,  0x14, 0x0,  0x20, 0x82, 0xB4, 0xB4, 0xA0, 0x0,  0xA,  0xFF, 0x38, 0x0,  0x19,
    0xFF, 0x38, 0x0,  0xC8, 0x0,  0x4B, 0x0,  0xC8, 0x5,  0x1A, 0x0,  0x0};
int D_8080015C_chtemplebrokendoorpiece[21] = {0x197012A,
                                              0x6560001,
                                              0x0,
                                              (u32) func_80102EC0,
                                              (u32) func_80105834,
                                              (u32) func_80101870,
                                              0x0,
                                              0x0,
                                              0xC90000,
                                              0xC00,
                                              0x0,
                                              (u32) func_80108ED0,
                                              0x0,
                                              (u32) func_80800000_chtemplebrokendoorpiece,
                                              (u32) func_80107C2C,
                                              -0x7FFFD400,
                                              (u32) func_80800068_chtemplebrokendoorpiece,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0};
