#include "common.h"

extern int D_80800330_chlagoonbilldrillcover;
extern void func_800EE7F8(void *param_0, void *param_1);
extern void _chexploder_entrypoint_3(Actor *param_0, void *param_1, int param_2);
extern void func_800BBCB8(void *param_0, void *param_1, int param_2, int param_3, void *param_4);
extern void _subaddieaudioquick_entrypoint_2(Actor *param_0, void *param_1, void *param_2);
extern void func_8010A624(Actor *param_0);
extern void func_80108B04(Actor *param_0, int param_1);
extern void func_800DA544(int param_0);
extern int D_80800378_chlagoonbilldrillcover;
extern int D_808003B0_chlagoonbilldrillcover;
extern s32 func_80101080(void);
extern void _chexploder_entrypoint_12();
extern void func_800FFAB0();
extern void func_80101FDC();
void func_8080024C_chlagoonbilldrillcover();

int *chlagoonbilldrillcover_entrypoint_0()
{
    return &D_80800330_chlagoonbilldrillcover;
}

void func_8080000C_chlagoonbilldrillcover(u8 *param_0) {
    if (func_800DA298(((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7) + 0x3C2) != 0) {
        if ((s32) ((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7) >= 0x35) {
            func_8010A570(param_0);
            func_8010A624(param_0);
            (*(u8 *)((s8 *)(param_0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(param_0) + (0x65))) & 0xFFFE);
            func_80108B04(param_0, 0);
            return;
        }
        func_800FFAB0(param_0);
    }
}

int func_80800094_chlagoonbilldrillcover(s32 param_0)
{
  if ((2 == (((*((u16 *) (((u8 *) param_0) + 0x72))) & 0xFFFFFFFFu) >> 10)) && _subaddieDll_entrypoint_6(param_0, 11))
  {
    func_8080024C_chlagoonbilldrillcover(param_0);
  }
 do { } while (0);
}

int func_808000DC_chlagoonbilldrillcover(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 pad[2];
    f32 local_0[3];
    u32 local_1;

    switch (param_1) {
    case 0x40:
        if (_subaddieDll_entrypoint_5(param_0, (*(s32 *)&param_2))) {
            func_80103110(param_0, 1);
            func_80101FDC(param_0, 2);
        } else func_8080024C_chlagoonbilldrillcover(param_0);
        break;
    case 0x90:
        _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x28);
        break;
    case 0x3D:
        local_1 = param_0->unk74_7 - 0x32;
        func_800EE7F8(local_0, param_0->position);
        local_0[1] -= 100.0f;
        func_800FFAB0(param_0);
        switch (local_1) {
        case 0:
        case 1:
        case 2: func_800D10D4(local_1 + 0x13, 7, local_0, 3, 0); break;
        case 3: func_80108474(0x210, local_0, 0x10E); break;
        case 4: func_80108474(0x210, local_0, 0); break;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080024C_chlagoonbilldrillcover(param_0) Actor *param_0;
{
  f32 local_0[3];
  func_800EE7F8(local_0, (char *)param_0 + 4);
  local_0[1] -= 200.0f;
  _chexploder_entrypoint_3(param_0, local_0, 5);
  func_800BBCB8((char *)param_0 + 4, local_0, 0x3F800000, 3, &D_80800378_chlagoonbilldrillcover);
  _subaddieaudioquick_entrypoint_2(param_0, (char *)param_0 + 4, &D_808003B0_chlagoonbilldrillcover);
  func_8010A624(param_0);
  *((u8 *) (((char *) param_0) + 0x65)) &= ~1;
  func_80108B04(param_0, 0);
  func_800DA544(((u32)((u16) *((u16 *) (((char *) param_0) + 0x76))) >> 7) + 0x3C2);
}
