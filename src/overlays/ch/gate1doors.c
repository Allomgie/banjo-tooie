#include "common.h"

extern int D_808004B8_chgate1doors;
extern int D_80800500_chgate1doors;
extern u8 D_80800480_chgate1doors[];
extern u8 D_80800494_chgate1doors[];
extern u8 D_808004A8_chgate1doors[];
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_80109748(f32 *, s32, s32, s32, f32, s32, s32, s32);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);

s32 func_80800000_chgate1doors(u8 *param_0, s32 param_1, s32 param_2) {
    u8 *local_0;

    if (param_1 == 0x40) {
        local_0 = func_80106790((*(s32 *)((s8 *)(param_0) + (0x3C))));
        if ((s32) ((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x72)))) >> 0xA) < 3) {
            func_80103110(param_0, 1);
        }
        if ((s32) ((u32)((u16) (*(u16 *)((s8 *)(local_0) + (0x72)))) >> 0xA) < 3) {
            func_80103110(local_0, 1);
        }
        func_8010A570(param_0);
        func_8010A570(local_0);
        func_800DA544(0xB1);
    } else {
        return 0;
    }
    return 1;
}

int func_808000A4_chgate1doors(Actor *param_0)
{
  s32 *local_0;
  local_0 = (s32 *) (((char *) param_0) + 0x4);
  if (func_800DA298(0xB1))
  {
    local_0 = (char *) param_0;
    *((f32 *) (((char *) local_0) + 0x48)) = 90.0f;
    func_8010A570(param_0);
    func_80101FDC(param_0, 3);
  }
  else
  {
    Actor *local_1;
    local_1 = _subaddiefind_entrypoint_0(local_0, 0x129, -1, 0);
    local_0 = (char *) param_0;
    if (local_1 != 0)
    {
      *((s32 *) (0x3C + ((char *) local_1))) = *((s32 *) (local_0 + 0));
      *((s32 *) (local_0 = ((char *) param_0) + 0x3C)) = *((s32 *) (((char *) local_1) + 0));
    }
  }
}

void func_80800128_chgate1doors(Actor *param_0)
{
    f32 local_0[3];
    switch (param_0->unk70_10) {
    case 1:
        if (func_800DA298(0xB1)) {
            func_800EEB9C(local_0, param_0->rotation[1] - 180.0f, 400.0f);
            func_800EF04C(local_0, param_0->position);
            func_80109748(local_0, 8, -40, 100, 2.15f, 180, 60, 80);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800480_chgate1doors);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800494_chgate1doors);
            func_80101FDC(param_0, 2);
            _subaddieDll_entrypoint_4(param_0, 1);
            ((u8 *)param_0)[0x74] &= ~0x40;
            *(f32 *)((u8 *)param_0 + 0x58) = 0.0f;
        }
        break;
    case 3: break;
    case 2:
        *(f32 *)((u8 *)param_0 + 0x54) = 90.0f;
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808004A8_chgate1doors);
        if (func_80102CF4(param_0, 2.0f)) {
            func_80101FDC(param_0, 3);
            func_80103110(param_0, 0);
            _subaddieaudioloop_entrypoint_2(param_0);
            return;
        }
        func_80102B2C(param_0, 1.0f);
        break;
    }
}

int func_808002B0_chgate1doors(Actor *param_0)
{
    s32 *local_0;
    local_0 = (s32 *)((char *)param_0 + 0);
    if (func_800DA298(0xB1))
    {
        *(f32 *)((char *)local_0 + 0x48) = -90.0f;
        func_8010A570(param_0);
        func_80101FDC(param_0, 3);
    }
    else
    {
        Actor *local_1;
        local_1 = _subaddiefind_entrypoint_0((char *)param_0 + 4, 0x128, -1, 0);
        if (local_1 != 0)
        {
            *(s32 *)((char *)local_1 + 0x3C) = *(s32 *)((char *)param_0 + 0);
            *(s32 *)((char *)param_0 + 0x3C) = *(s32 *)((char *)local_1 + 0);
        }
    }
}

void func_80800334_chgate1doors(Actor *param_0)
{
    f32 local_0[3];
    switch (param_0->unk70_10) {
    case 1:
        if (func_800DA298(0xB1)) {
            func_800EEB9C(local_0, param_0->rotation[1], 400.0f);
            func_800EF04C(local_0, param_0->position);
            func_80109748(local_0, 8, -40, 100, 2.15f, 180, 60, 80);
            func_80101FDC(param_0, 2);
            func_80103110(param_0, 1);
        }
        break;
    case 2:
        param_0->unk54 = -90.0f;
        if (func_80102CF4(param_0, 2.0f)) {
            func_80101FDC(param_0, 3);
            func_80103110(param_0, 0);
        } else {
            func_80102B2C(param_0, 1.0f);
        }
        break;
    case 3:
        break;
    }
}

int chgate1doors_entrypoint_0()
{
    return &D_808004B8_chgate1doors;
}

int chgate1doors_entrypoint_1()
{
  return (int)&D_80800500_chgate1doors;
}
