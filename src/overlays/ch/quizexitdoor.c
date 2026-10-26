#include "common.h"

extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80103110();
extern void func_80101FDC();
extern int D_80800190_chquizexitdoor;

void func_80800000_chquizexitdoor(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 1:
        func_80103110(param_0, 0);
        break;
    case 2:
        if (func_800D90A4(&param_0->unk58)) {
            func_800DA544(0x440);
            func_800FFAB0(param_0);
        }
        *((u8 *)param_0 + 0x9B) = (u32)func_800F10B4(param_0->unk58, 2.0f, 0.0f, 255.0f, 0.0f);
        break;
    }
}

void func_80800124_chquizexitdoor(s32 arg0) 
{
}
s32 func_8080012C_chquizexitdoor(Actor *this, enum asset_e text_id, s32 param_2) {
    if (text_id == 7) {
        this->unk58 = 2.0f;
        func_80101FDC(this, 2);
        func_80103110(this, 1);
        return 1;
    }
    return 0;
}

int *chquizexitdoor_entrypoint_0()
{
    return &D_80800190_chquizexitdoor;
}
