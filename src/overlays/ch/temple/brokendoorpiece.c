#include "common.h"

extern u8 D_80800100_chtemplebrokendoorpiece[];
extern u8 D_80800114_chtemplebrokendoorpiece[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern int D_8080015C_chtemplebrokendoorpiece;

void func_80800000_chtemplebrokendoorpiece(s32 arg0) 
{
}
void func_80800008_chtemplebrokendoorpiece(Actor *param_0) {
    func_800BABB8(0, (s32 *)((char *)param_0 + 4), (s32 *)((char *)param_0 + 4), *(s32 *)((char *)param_0 + 0x38), &D_80800114_chtemplebrokendoorpiece);
    _subaddieaudioquick_entrypoint_2(param_0, (s32 *)((char *)param_0 + 4), &D_80800100_chtemplebrokendoorpiece);
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
    return (int)&D_8080015C_chtemplebrokendoorpiece;
}
