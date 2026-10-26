#include "common.h"

extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct { u16 model; s16 state; } JamjarsDummyRecord;
extern JamjarsDummyRecord D_8080032C_chjamjarsdummy[];
extern int D_80800338_chjamjarsdummy;

void func_80800000_chjamjarsdummy(Actor *param_0, s32 param_1)
{
    param_0->unk79_4 = param_1;
    switch (param_0->unk79_4) {
    case 0:
        param_0->unk58 = 2.0f;
        _subaddiefade_entrypoint_8(param_0, 255);
        break;
    case 1:
        switch (param_0->unk6C_0) {
        case 0: param_0->unk58 = 5.0f; break;
        case 1: param_0->unk58 = 5.0f; break;
        case 2: param_0->unk58 = 5.0f; break;
        }
        break;
    case 2:
        param_0->unk58 = 2.0f;
        ((f32 *)param_0->actorData)[4] = 0.0f;
        break;
    }
}

void func_808000E0_chjamjarsdummy(Actor *param_0)
{
    s32 local_0;
    s32 local_1;

    *(f32 *)&param_0->actorData[4] += func_800D8FF8();
    if (param_0->unk6C_0 == 2) _chswappy_entrypoint_0(param_0, 0);
    switch (param_0->unk79_4) {
        case 0:
            local_0 = func_800F10B4(*(f32 *)&param_0->actorData[4], 0.0f, param_0->unk58, 0.0f, 255.0f);
            _subaddiefade_entrypoint_8(param_0, local_0);
            if (local_0 >= 255) func_80800000_chjamjarsdummy(param_0, 1);
            break;
        case 1:
            if (func_800DA9E4(0x9F1, 0)) func_800FFAB0(param_0);
            if (param_0->unk58 < *(f32 *)&param_0->actorData[4]) func_80800000_chjamjarsdummy(param_0, 2);
            break;
        case 2:
            local_1 = func_800F10B4(*(f32 *)&param_0->actorData[4], 0.0f, param_0->unk58, 255.0f, 0.0f);
            _subaddiefade_entrypoint_8(param_0, local_1);
            if (local_1 <= 0) func_800FFAB0(param_0);
            break;
    }
}

void func_80800238_chjamjarsdummy(s32 arg0) 
{
}
void func_80800240_chjamjarsdummy(Actor *param_0)
{
    func_80103140(param_0, D_8080032C_chjamjarsdummy[param_0->unk6C_0].model,
        param_0->unk0->unk16);
    func_80102424(param_0, D_8080032C_chjamjarsdummy[param_0->unk6C_0].state);
    func_80800000_chjamjarsdummy(param_0, 0);
}

void func_808002AC_chjamjarsdummy(void *param_0)
{
  if (((*((s32 *)((char *)(param_0) + 108))) & 0x1FF) == 2)
  {
    *((u8 *) (((u8 *) param_0) + 126)) = ((*((u8 *) (((u8 *) param_0) + 126))) & 0xFFFF) | 0x10;
  }
  else
  {
    func_80101870();
  }
}

int chjamjarsdummy_entrypoint_0()
{
    return (int)&D_80800338_chjamjarsdummy;
}
