#include "common.h"

extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern int D_80800480_chLagoonInnBlockedWall;
extern u8 D_80800570_chLagoonInnBlockedWall[];
extern u8 D_8080046C_chLagoonInnBlockedWall[];
extern u8 D_80800400_chLagoonInnBlockedWall[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef union { u32 word; s16 halves[2]; } LagoonWallEvent;
extern u8 D_80800528_chLagoonInnBlockedWall[];
extern u8 D_808004C8_chLagoonInnBlockedWall[];
extern u8 D_8080054C_chLagoonInnBlockedWall[];
extern u8 D_80800514_chLagoonInnBlockedWall[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_80109704(Actor *, s32, s32, s32, f32, s32, s32, s32);
void func_8080025C_chLagoonInnBlockedWall();

void func_80800000_chLagoonInnBlockedWall(Actor *param_0)
{
    f32 local_0[3];

    switch (param_0->unk70_10) {
    case 3:
        if (func_800D9078(&param_0->unk58)) {
            func_800EE7F8(local_0, param_0->position);
            func_800EF1B8(local_0, param_0->rotation[1], -100.0f);
            _chexploder_entrypoint_3(param_0, local_0, 3);
            func_800DA544(0x3A9);
        }
        break;
    case 2:
        if (func_800D9078(&param_0->unk58)) {
            func_800F82D4(func_800F54E4(), 0);
            _glcutDll_entrypoint_6(0x1A7, 0x32);
            func_800FFAB0(param_0);
        }
        break;
    }
}

void func_808000C0_chLagoonInnBlockedWall()
{
    func_8010A63C();
}

int func_808000E0_chLagoonInnBlockedWall(Actor *param_0, s32 param_1, LagoonWallEvent param_2)
{
    f32 local_0[3];

    switch (param_1) {
    case 0x49:
        if (_glcutDll_entrypoint_19(0x32)) {
            param_0->unk58 = 0.4f;
            func_80103110(param_0, 1);
            func_80101FDC(param_0, 3);
            _capod_entrypoint_13(param_0->unk0, 0, 0x1C, 0x910);
            return 1;
        }
        break;
    case 5:
        func_8010A570(param_0);
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, *(f32 *)((u8 *)param_0 + 0x48), 100.0f);
        _chexploder_entrypoint_3(param_0, local_0, 3);
        func_800F8300(func_800F54E4(), 2, param_0->position);
        return 1;
    case 0x90:
        if (func_800EA05C() == 0xED) {
            func_80101FDC(param_0, 2);
            func_80103110(param_0, 1);
            param_0->unk58 = 0.8f;
        } else func_800FFAB0(param_0);
        func_800BABB8(0, param_0->position, param_0->position,
            param_0->scale, D_80800400_chLagoonInnBlockedWall);
        func_800C4AF0(param_0->position, D_8080046C_chLagoonInnBlockedWall);
        return 1;
    }
    return 0;
}

int chLagoonInnBlockedWall_entrypoint_0()
{
  return &D_80800480_chLagoonInnBlockedWall;
}

void func_8080025C_chLagoonInnBlockedWall(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0[3];

    func_800EE7F8(local_0, param_0->position);
    local_0[1] += 80.0f;
    func_800BBCB8(local_0, 0, param_0->scale * 1.2f, 8, D_80800528_chLagoonInnBlockedWall);
    func_800BBCB8(local_0, 0, param_0->scale * 1.2f, 0x10, D_808004C8_chLagoonInnBlockedWall);
    func_800BBCB8(local_0, local_0, param_0->scale, 0xF, D_8080054C_chLagoonInnBlockedWall);
    func_80109704(param_0, 8, -0x28, 0xC8, 1.85f, 0xB4, 0x3C, 0x50);
    _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80800514_chLagoonInnBlockedWall);
    func_800FFAB0(param_0);
    func_80101180(0x488, 5, 0);
}

s32 func_80800398_chLagoonInnBlockedWall(s32 param_0, s32 param_1, s32 param_2)
{
  unsigned int *new_var;
  ;
  if ((param_1 == 0x40) ^ 0)
  {
    func_8080025C_chLagoonInnBlockedWall(*(&param_0), param_2 | 0);
    if (!param_2)
    {
    }
    return 1;
  }
  return 0;
}

u8 *chLagoonInnBlockedWall_entrypoint_1(void) {
    return D_80800570_chLagoonInnBlockedWall;
}
