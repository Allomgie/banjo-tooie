#include "common.h"

extern void *D_80800410_chbottlesparty;
extern int D_80800458_chbottlesparty;
extern u8 D_808004A0_chbottlesparty[];
extern u8 D_808004B0_chbottlesparty[];
extern s32 D_808004CC_chbottlesparty[][3];
extern s32 D_808004FC_chbottlesparty[];
extern s32 D_80800508_chbottlesparty[];
extern f32 func_800F0F9C(f32, f32);
extern f32 func_800F3780(f32, s32 *, s32);
extern int func_800F3214(s32 *, s32 *, s32 *, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800DC178(f32, f32);
extern void func_800C8E54(s32, f32, f32);
int func_80800138_chbottlesparty();
void func_80800170_chbottlesparty();

int chbottlesparty_entrypoint_0()
{
  return &D_80800410_chbottlesparty;
}

int chbottlesparty_entrypoint_1()
{
  return &D_80800458_chbottlesparty;
}

s32 func_80800018_chbottlesparty(s32 param_0){
    if(func_800DA298(0x3B) == 0){
        func_800FFAB0(param_0);
    }
    else{
        func_8010A800(param_0, 0);
    }
}

void func_8080022C_chbottlesparty();

void func_8080005C_chbottlesparty(u8 *param_0)
{
    func_8080022C_chbottlesparty();
    if (((u32)((u16)(*(u16 *)((char *)param_0 + 0x72))) >> 0xA) == 1) {
        func_80800170_chbottlesparty(param_0);
    }
}

s32 func_8080009C_chbottlesparty(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x2E:
        *(f32 *)&param_0->actorData[4] = 6.0f;
        func_80101FDC(param_0, 1);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808004A0_chbottlesparty, *(s32 *)&param_0->scale);
        break;
    case 0x95:
        func_80800138_chbottlesparty(param_0);
        break;
    default: return 0;
    }
    return 1;
}

int func_80800138_chbottlesparty(param_0) Actor *param_0;
{
    if (((u32)(*(u16 *)((char *)(param_0) + 0x76)) >> 7) == 0x32) {
        func_80103140(param_0, 0x653, 0);
    }
}

void func_80800170_chbottlesparty(param_0) Actor *param_0;
{
    if (!func_800DA298(0x43)) {
        if (!func_800DA298(0x67C)) _subaddiedialog_entrypoint_7(param_0, param_0->position, D_808004B0_chbottlesparty);
        else if (func_800F64A4(func_800F54E4(), 0x601) &&
                 func_8010CAC0(param_0->position, 500) &&
                 func_800D90A4((f32 *)&param_0->actorData[4])) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x154F, 4, 0, 15);
            func_80101FDC(param_0, 2);
        }
    }
}

void func_8080022C_chbottlesparty(s32 arg0) 
{
}
void func_80800234_chbottlesparty(Actor *param_0)
{
    if (!func_800DA298(0x3B) || func_800DA298(0x43)) {
        func_800FFAB0(param_0);
    } else {
        *(f32 *)&param_0->actorData[5] = func_800DC178(0.4f, 0.6f);
        param_0->unk58 = func_800DC178(0.0f, *(f32 *)&param_0->actorData[5]);
        param_0->unk6C_0 = param_0->unk74_7 - 0x32;
        if (param_0->unk6C_0 >= 5) {
            param_0->unk6C_0 = 0;
        }
        param_0->actorData[4] = func_800C8A98();
        func_800C8E54(param_0->actorData[4], param_0->scale * 300.0f, param_0->scale * 600.0f);
        func_800C8CB8(param_0->actorData[4], param_0->position);
    }
}

void func_80800330_chbottlesparty(Actor *param_0)
{
  s32 local_0[3];
  Vec3f local_1;
  s32 pad0;
  f32 local_2;
  f32 local_3;
  if (param_0->actorData[4] != 0)
  {
    local_2 = func_800F3780(func_800F0F9C(param_0->unk58, *((f32 *) (&param_0->actorData[5]))), D_80800508_chbottlesparty, 3);
    func_80103DFC(param_0, local_1.f);
    func_800F3214(local_0, D_808004FC_chbottlesparty, D_808004CC_chbottlesparty[param_0->unk6C_0], local_2);
    func_800C8E84(param_0->actorData[4], local_0);
    param_0->unk58 += func_800D8FF8();
  }
}

s32 func_808003E4_chbottlesparty(s32 param_0, s32 param_1, s32 param_2){
    return 0;
}
