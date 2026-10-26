#include "common.h"

typedef struct { u8 pad_0[0x7C]; u32 pad_1 : 17; u32 local_0 : 1; u32 pad_2 : 14; } SwappyFlags31;
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
typedef struct { u8 pad_0[0x1A]; u16 local_0; u8 pad_1[8]; u32 local_1; } SwappyContact;
typedef union { s32 local_0; s16 local_1[2]; } SwappyEventValue;
extern u8 D_808006CC_chswappy[];
extern u8 D_80800690_chswappy[];
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern int D_808006D4_chswappy;
extern void func_80102FDC(Actor *, f32);
typedef struct { u8 pad[0x7E]; u8 pad_0 : 1; u8 flag_40 : 1; u8 pad_1 : 1; u8 flag_10 : 1; u8 pad_2 : 4; } SwappyFlags;
extern s32 func_800E3E8C(f32 *, f32);
extern f32 func_800EEB40(f32 *, f32 *);
int chswappy_entrypoint_0();

void func_80800000_chswappy(Actor *param_0)
{
    func_80102FDC(param_0, param_0->scale * 0.6f);
    if (func_800F8B88() == 2) {
        _subaddiefade_entrypoint_1(param_0, 255);
        func_80103110(param_0, 1);
        func_8010A590(param_0);
        func_808000B0_chswappy(param_0, 1);
    } else {
        _subaddiefade_entrypoint_1(param_0, 0);
        func_80103110(param_0, 0);
        func_8010A570(param_0);
        func_808000B0_chswappy(param_0, 1);
    }
}

int func_808000B0_chswappy(s32 param_0, s32 param_1)
{
  func_80101FDC();
  switch (param_1)
  {
    case 1 :
      _subaddieDll_entrypoint_4(param_0, 0);
      break;

    case 2 :
      break;

    case 3 :

    default :
      break;

  }

}

void func_80800108_chswappy(Actor *param_0)
{
    int local_0;
    f32 local_1[3];
    s32 local_2;

    local_0 = (s32)param_0->unk70_10 == 2;
    switch (param_0->unk70_10) {
        case 1:
            local_2 = _plsu_entrypoint_1(10);
            if (local_2 != -1) {
                func_800F5A00(local_2, local_1);
                if (func_800EFFB4(param_0->position, 100.0f, local_1)) {
                    _sudeflect_entrypoint_1(local_1, 125.0f, 0.0f, 40.0f, 28);
                }
            }
            break;
        case 2:
            func_808000B0_chswappy(param_0, 3);
            break;
        case 3:
            if (!func_800F6BE4(param_0->unk79_4) || func_800F7B9C(param_0->unk79_4, 0x41) == 2) {
                func_808000B0_chswappy(param_0, 1);
            }
            break;
    }
    if (func_800F8B88() == 2) {
        chswappy_entrypoint_0(param_0, local_0);
    }
    ((SwappyFlags31 *)param_0)->local_0 = 0;
}

void func_80800234_chswappy(Actor *param_0, SwappyContact *param_1)
{
    u32 local_0;

    if ((param_1->local_1 >> 22) == 0) {
        local_0 = (u32)param_1->local_0 >> 5;
        if (func_800F64A4(local_0, 0x600) &&
            (param_0->unk74_7 != 0x32 || func_800F55D0(local_0)) &&
            (param_0->unk70_10 == 3 || func_800F7CF4(local_0, 0x40, param_0->position) == 2)) {
            param_0->unk79_4 = local_0;
            func_808000B0_chswappy(param_0, 2);
        }
    }
}

s32 func_80800300_chswappy(Actor *param_0, s32 param_1, SwappyEventValue param_2)
{
    switch (param_1) {
        case 0x95: func_808000B0_chswappy(param_0, 1); break;
        case 0x16:
            func_808000B0_chswappy(param_0, 1);
            func_80103110(param_0, 1);
            func_8010A590(param_0);
            _subaddiefade_entrypoint_2(param_0);
            break;
        case 0x17:
            func_808000B0_chswappy(param_0, 1);
            func_80103110(param_0, 0);
            func_8010A570(param_0);
            _subaddiefade_entrypoint_5(param_0);
            break;
        case 0x3E: func_80800234_chswappy(param_0, param_2.local_0); break;
        default: return 0;
    }
    return 1;
}

void func_808003DC_chswappy(Actor *param_0, s32 param_1)
{
    s32 local_0;
    f32 local_1[3];

    local_0 = func_800E3E8C(param_0->position, 300.0f);
    func_8010A73C(param_0, param_1);
    if (local_0 && func_800F8B88() == 2) {
        func_800E3980(local_1);
        if (func_800EEB40(param_0->position, local_1) < 6250000.0f) {
            ((SwappyFlags *)param_0)->flag_10 = 1;
        }
        ((SwappyFlags *)param_0)->flag_40 = 1;
    }
}

int chswappy_entrypoint_0(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_4;
    s32 local_5;
    f32 local_3[2];

    if (!param_0->unk7C_12) return;
    if (param_1) {
        local_4 = func_800B5BE4(0x1D);
        func_800BA3FC(local_4, 0x9DE);
    } else {
        local_5 = func_800DC128(0, 3);
        local_4 = func_800B5BE4(local_5 + 0x1E);
        func_800BA3FC(local_4, ((u16 *)D_808006CC_chswappy)[local_5]);
    }
    func_800E3980(local_0);
    func_800F18FC(param_0->position, local_0, local_3);
    func_800EE7F8(local_1, param_0->position);
    local_1[1] -= 200.0f;
    for (local_5 = 0; local_5 != 2; local_5++) {
        func_800EEB9C(local_2, local_3[1] + func_800DC178(-90.0f, 90.0f), 50.0f);
        func_800EF04C(local_2, param_0->position);
        local_2[1] += -30.0f + func_800DC178(0.0f, 100.0f);
        func_800BABB8(local_4, local_2, local_1, 1.0f, D_80800690_chswappy);
    }
}

int *chswappy_entrypoint_1()
{
    return &D_808006D4_chswappy;
}
