#include "common.h"

extern int D_80800420_ch1pfreeze;
typedef struct { u8 pad[0x72]; u16 f72:6; u16 pad72:10; } FreezeState;
extern int func_800F7B9C();
extern s32 *func_80100094(FreezeState *, s32);
extern f32 func_800D8FF8(void);
extern s32 func_800F1574(f32 *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern s32 func_800A89F8(void);
extern s32 func_800F5ECC(u32);
extern f32 func_800F5794(u32, f32 *, s32);
extern void func_800B99CC(s32, s32, f32 *);
extern void func_80101870(Actor *, s32);
typedef struct { u32 local_0; f32 local_1[3]; s32 local_2; f32 local_3; f32 local_4; f32 local_5; } FreezeData;
typedef struct { s32 local_0; f32 local_1[3]; s32 local_2; f32 local_3; f32 local_4; f32 local_5; } ChFreezeState;
extern Actor *func_80108474(s32, f32 *, s32);
extern void func_800F5A00(u32, f32 *);
extern f32 func_800F5F24(u32);
void func_808002D0_ch1pfreeze();

int *ch1pfreeze_entrypoint_0()
{
    return &D_80800420_ch1pfreeze;
}

void func_8080000C_ch1pfreeze(s32 arg0) 
{
}
void func_80800014_ch1pfreeze(FreezeState *param_0) {
    if (param_0->f72 < 4) {
        func_800F7B9C(*func_80100094(param_0, 0), 0xF);
    }
}

void func_80800054_ch1pfreeze(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
        case 2:
            if (func_800F1574((f32 *)(local_0 + 0x14), func_800D8FF8())) {
                func_808002D0_ch1pfreeze(param_0, 3);
            }
            *(f32 *)(local_0 + 0x1C) = 1.0f - *(f32 *)(local_0 + 0x14) / *(f32 *)(local_0 + 0x18);
            break;
        case 4:
            if (func_800F1574((f32 *)(local_0 + 0x14), func_800D8FF8())) {
                func_800FFAB0(param_0);
                return;
            }
            *(f32 *)(local_0 + 0x1C) = *(f32 *)(local_0 + 0x14) / *(f32 *)(local_0 + 0x18);
            break;
    }
    *(s32 *)(local_0 + 0x10) = func_800F1214(*(f32 *)(local_0 + 0x1C), 0.0f, 128.0f);
}

void func_8080014C_ch1pfreeze(Actor *param_0, s32 param_1)
{
    FreezeData *local_0;
    s32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    s32 i;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800A89F8();
    if (func_800F5ECC(local_0->local_0) != local_1) {
        local_2 = 0;
        if (param_0->unk70_10 != 4) {
            for (i = 0; i != 3; i++) {
                local_3 = func_800F5794(local_0->local_0, param_0->position, i);
                local_4 = local_3;
                if (i != 2) {
                    param_0->rotation[0] = 0.0f;
                    local_2 += local_3;
                } else {
                    local_4 = local_2 * 0.25f;
                    param_0->rotation[0] = 90.0f;
                }
                param_0->scale = local_0->local_5 * (local_4 / 75.0f);
                func_80101870(param_0, param_1);
            }
        }
    } else {
        func_800B99CC(param_1, local_0->local_2, local_0->local_1);
    }
}

s32 func_80800294_ch1pfreeze(Actor *this, s32 param_1, s32 param_2)
{
  Actor *new_var;
  if (param_1 == 0x4)
  {
    new_var = this;
    func_808002D0_ch1pfreeze(new_var, 4);
  }
  else
  {
    return 0;
  }
  return 1;
}

void func_808002D0_ch1pfreeze(param_0, param_1) Actor *param_0; s32 param_1;
{
    ChFreezeState *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 2:
            func_800EFA88(local_0->local_1, 0x80, 0xC0, 0xFF);
            local_0->local_2 = 0;
            local_0->local_3 = 0.25f;
            local_0->local_4 = 0.25f;
            local_0->local_5 = 0.0f;
            break;
        case 3:
            func_80103110(param_0, 0);
            break;
        case 4:
            _sufreezy_entrypoint_4(param_0->unk0, 8);
            local_0->local_3 = 0.25f;
            local_0->local_4 = 0.25f;
            func_80103110(param_0, 1);
            break;
    }
    func_80101FDC(param_0, param_1);
}

Unk80132ED0 *ch1pfreeze_entrypoint_1(u32 param_0)
{
    Actor *local_0;
    f32 local_1[3];

    func_800F5A00(param_0, local_1);
    local_0 = func_80108474(0x2C5, local_1, 0);
    *(u32 *)func_80100094(local_0, 0) = param_0;
    local_0->rotation[1] = func_800F5F24(param_0);
    func_808002D0_ch1pfreeze(local_0, 2);
    return local_0->unk0;
}
