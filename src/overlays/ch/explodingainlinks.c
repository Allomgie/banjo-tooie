#include "common.h"

extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern int D_808001B8_chexplodingchainlinks;
void func_8080010C_chexplodingchainlinks();

int chexplodingchainlinks_entrypoint_0()
{
    extern void *D_80800170_chexplodingchainlinks;
    return (int)&D_80800170_chexplodingchainlinks;
}

void func_8080000C_chexplodingchainlinks(s32 arg0) 
{
}
void func_80800014_chexplodingchainlinks(s32 arg0)
{
    _subaddieDll_entrypoint_7(arg0,0xB);
}

s32 func_80800034_chexplodingchainlinks(s32 param_0, s32 param_1){
    f32 local_0[3];

    func_800E3A58(local_0);
    *(f32 *)((char *)param_0 + 0x48) = local_0[1];
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

void func_8080010C_chexplodingchainlinks(param_0, param_1) s32 param_0; f32 *param_1; {
    f32 sp24[3];

    func_800EE7F8(sp24, param_0 + 4, param_0);
    sp24[1] = param_1[1];
    func_800BBCB8(sp24, sp24, 0x3F4CCCCD, 4, &D_808001B8_chexplodingchainlinks);
}
