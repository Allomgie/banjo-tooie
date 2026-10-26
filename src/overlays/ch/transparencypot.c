#include "common.h"

extern int D_808001B0_chtransparencypot;
extern f32 func_800DC178(f32 param_0, f32 param_1);
typedef struct { u8 pad[0x72]; u16 f72:6; u16 rest:10; } PotState;
extern s32 func_800D9078();
typedef union { s32 local_0; Unk80132ED0 *local_1; } TransparencyPotEvent;
extern u8 D_808001F8_chtransparencypot[];
extern void func_800F7C0C(s32, s32, f32);
extern void _fxsparkle_entrypoint_1(f32 *, s32);
void func_80800148_chtransparencypot();

int chtransparencypot_entrypoint_0()
{
    return (int)&D_808001B0_chtransparencypot;
}

void func_8080000C_chtransparencypot(void *param_0) {
    (*(float *)((char *)param_0 + 0x38)) = 0.5f;
}

void func_8080001C_chtransparencypot(Actor *param_0, s32 param_1)
{
  f32 local_0;

  if (param_1 != 1) {
    if (param_1 == 2) {
      param_0->unk64_16 = 0;
      func_8010A570();
      local_0 = *(f32 *)((u8 *)param_0 + 0x48) * func_800DC178(0.5f, 1.0f);
      *(f32 *)((u8 *)param_0 + 0x58) = local_0;
    }
  } else {
    param_0->unk64_16 = 1;
    func_8010A590(param_0);
    _subaddiefade_entrypoint_2(param_0);
  }
  func_80101FDC(param_0, param_1);
}

void func_808000B8_chtransparencypot(PotState *param_0, s32 param_1) {
    if (param_0->f72 == 2 && func_800D9078((u8 *)param_0 + 0x58, param_1, param_0) != 0) {
        func_8080001C_chtransparencypot(param_0, 1);
    }
}

s32 func_80800104_chtransparencypot(Actor *param_0, s32 param_1, TransparencyPotEvent param_2)
{
    switch (param_1) {
    case 0x3E:
        func_80800148_chtransparencypot(param_0, (u32)*(u16 *)((u8 *)param_2.local_1 + 0x1A) >> 5);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800148_chtransparencypot(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0;

    local_0 = param_0->rotation[1];
    func_800F7C0C(param_1, 0x67, local_0);
    _fxsparkle_entrypoint_1(param_0->position, 2);
    func_800C4AF0(param_0->position, D_808001F8_chtransparencypot);
    func_8080001C_chtransparencypot(param_0, 2);
}
