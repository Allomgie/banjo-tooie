#include "common.h"

extern int D_808000E0_chcamerawibble;
typedef struct { u8 pad0[0x24]; f32 f24; u8 pad28[0x10]; f32 f38; u8 pad3C[0x18]; f32 f54; u8 pad58[0x1E]; u16 f76:9; u16 pad76:7; } WibbleState;
extern f32 func_80013970(f32);
extern void func_800C4B90(s32, f32, f32);
extern f32 func_800D8FF8(void);

int *chcamerawibble_entrypoint_0()
{
    return &D_808000E0_chcamerawibble;
}

void func_8080000C_chcamerawibble(WibbleState *param_0) {
    param_0->f24 = param_0->f76 * 10.0f;
    param_0->f54 = param_0->f38;
}

void func_8080004C_chcamerawibble()
{
    func_8080006C_chcamerawibble();
}

int func_8080006C_chcamerawibble(param_0)
Actor *param_0;
{
    f32 local_0;

    local_0 = func_80013970(param_0->unk58) * param_0->unk54;
    func_800C4B90(0, local_0, -local_0);
    param_0->unk58 += func_800D8FF8() * *(f32 *)&param_0->actorData[3];
}
