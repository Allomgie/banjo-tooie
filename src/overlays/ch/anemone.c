#include "common.h"

extern int D_808008D8_chanemone;
extern void func_80102FDC(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern void _subaddiecustomhits_entrypoint_0(void *param_0, void *param_1);
extern void func_800E0AFC(void *param_0, s32 param_1, f32 param_2, void *param_3, f32 param_4, f32 param_5);
extern s32 func_8010262C(void *param_0, s32 param_1);
extern void *_chanemone_entrypoint_1;
extern u8 D_80800954_chanemone[];
extern u8 D_80800964_chanemone[];
extern void _subaddieDll_entrypoint_4();
extern void _subaddieaudioloop_entrypoint_5();
extern u8 D_80800920_chanemone[];
extern u8 D_80800934_chanemone[];
extern u8 D_80800944_chanemone[];
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern int func_800D9078(f32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800136E4(f32);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern s32 func_800B1F8C(void *, f32 *, f32 *, f32, s32, s32, f32 *, f32, s32, s32);
void func_808005A0_chanemone();
void func_808003A8_chanemone();

int chanemone_entrypoint_0()
{
    return (int)&D_808008D8_chanemone;
}

void func_8080000C_chanemone(Actor *param_0)
{

    s32 local_0;
    s32 local_1;
    local_0 = 4;
    local_1 = param_0->unk70_10 != 3;
    func_808003A8_chanemone();
    if (func_8010D23C()) {
        if (param_0->unk70_10 != 1) local_0 = 30;
        if (func_800F64A4(func_800F54E4(), 0x400)) local_0 |= 2;
    }
    if (local_1) {
        _sudeflect_entrypoint_1(param_0->position, param_0->scale * 850.0f, 0.0f, param_0->scale * 600.0f, local_0);
        _sudeflect_entrypoint_0(param_0->position, param_0->scale * 800.0f, param_0->scale * 600.0f, local_0);
    } else {
        _sudeflect_entrypoint_0(param_0->position, param_0->scale * 250.0f, param_0->scale * 700.0f, local_0);
    }
    _subaddieaudioloop_entrypoint_5(param_0, param_0->position, param_0->unk70_10 == 1, 2000, D_80800920_chanemone);
    switch (param_0->unk70_10) {
    case 2:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800934_chanemone, 0.2f);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 3);
            param_0->unk58 = 6.0f;
        }
        break;
    case 3:
        if (func_800D9078(&param_0->unk58)) func_80102424(param_0, 4);
        break;
    case 4:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800944_chanemone, 0.6f);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 1);
            _subaddieDll_entrypoint_4(param_0, 0);
            func_8010A590(param_0);
        }
        break;
    }
}

void func_80800260_chanemone(Actor *param_0)
{
    func_80102FDC(param_0, param_0->scale * 0.5f);
    param_0->unk54 = 0.0f;
    *(f32 *)&param_0->actorData[4] = 0.0f;
    param_0->unk50 = 0.0f;
    *(f32 *)&param_0->actorData[5] = 0.0f;
    *(f32 *)&param_0->actorData[7] = func_800DC178(0.5f, 2.0f);
    param_0->actorData[6] = _subaddiesect_entrypoint_1(param_0);
    _subaddiesect_entrypoint_2(param_0, param_0->actorData[6], 0);
}

s32 func_808002E8_chanemone(void *param_0, s32 param_1, volatile int param_2)
{
  s32 temp_v0;
  switch (param_1)
  {
    case 0x3F:
      func_808005A0_chanemone(param_0, param_2);
      goto block_9;

    case 0x95:
      _subaddiecustomhits_entrypoint_0(param_0, &_chanemone_entrypoint_1);
      goto block_9;

    case 0x9C:
      temp_v0 = func_8010262C(*((s32 *) param_0), 1);
      if (temp_v0 != 0)
    {
      func_800E0AFC(temp_v0, 0x64, 1.0f, *((s32 *) (((u8 *) param_0) + 0x2C)), *((f32 *) (((u8 *) param_0) + 0x28)), 0.0f);
    }
      goto block_9;

    default:
      return 0;

  }

  block_9:
  return 1;

}

void func_808003A8_chanemone(param_0) Actor *param_0;
{
    f32 local_0;
    Vec3f local_1;
    Vec3f local_2;
    f32 local_3[2];


    local_0 = func_800D8FF8();
    if (func_8010D23C()) {
        func_8010D254(&local_1);
        func_800EE7F8(&local_2, param_0->position);
        local_2.f[1] += param_0->scale + 200.0f;
        func_800EF1B8(&local_2, param_0->rotation[1], param_0->scale * 300.0f);
        if (func_800EEB40(&local_1, &local_2) < 2250000.0f) {
            func_800F18FC(&local_2, &local_1, local_3);
            param_0->unk54 = local_3[1] - param_0->rotation[1];
            param_0->unk50 = -local_3[0];
        } else if (func_800D9078(&((f32 *)param_0->actorData)[7])) {
            param_0->unk54 = func_800DC178(-60.0f, 60.0f);
            param_0->unk50 = func_800DC178(-50.0f, 50.0f);
            ((f32 *)param_0->actorData)[7] = func_800DC178(0.5f, 2.0f);
        }
    } else {
        param_0->unk54 = 0.0f;
        param_0->unk50 = 0.0f;
    }
    param_0->unk54 = func_800F0D50(func_80013728(param_0->unk54), -60.0f, 60.0f);
    param_0->unk50 = func_800F0D50(func_80013728(param_0->unk50), -50.0f, 50.0f);
    ((f32 *)param_0->actorData)[4] = func_800F1FF0(((f32 *)param_0->actorData)[4], param_0->unk54, 0.1f, (4.0f * local_0), (60.0f * local_0));
    ((f32 *)param_0->actorData)[5] = func_800F1FF0(((f32 *)param_0->actorData)[5], param_0->unk50, 0.1f, (4.0f * local_0), (60.0f * local_0));
}

void func_808005A0_chanemone(param_0, param_1) Actor *param_0; s32 param_1;
{
    if (param_0->unk6C_0 == 1) {
        switch ((s32)param_0->unk70_10) {
            case 1:
            case 4:
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800954_chanemone);
                func_80102424(param_0, 2);
                _subaddieDll_entrypoint_4(param_0, 1);
                func_8010A570(param_0);
                break;
            case 3: param_0->unk58 = 6.0f; break;
        }
    }
}

s32 func_80800648_chanemone(Unk80132ED0 *param_0, f32 *param_1, f32 param_2, s32 param_3, s32 param_4)
{
    f32 local_6;
    s32 local_7;
    s32 local_0;
    f32 local_1[3];
    void *local_2;
    Actor *local_4;
    void *local_3;

    local_4 = func_80106790(param_0);
    switch (func_800CB854(&local_0)) {
    case 2:
        func_800EE88C(local_1, (s16 *)((u8 *)param_0 + 0x1E));
        func_800EF04C(local_1, local_4->position);
        return func_800EFFB4(local_1, (u32)*(u16 *)((u8 *)local_4 + 0x68) * 0.8f * local_4->scale + param_2, param_1);
    case 5:
        local_2 = (void *)func_80103D98(param_0);
        if (!local_2) return 0;
        local_7 = func_800B1F8C(local_2, local_4->position, local_4->rotation, local_4->scale, 0, func_801040A8(local_4), param_1, param_2, param_3, 30);
        break;
    default:
        local_3 = (void *)func_80103D98(param_0);
        if (!local_3) return 0;
        local_6 = func_800136E4(func_800F1DCC(func_800F1DF4(local_4->position, param_1), local_4->rotation[1]));
        if (local_6 < 90.0f) param_4 = 12;
        else if (local_6 < 180.0f) param_4 = 24;
        else if (local_6 < 270.0f) param_4 = 18;
        else param_4 = 6;
        local_7 = func_800B1F8C(local_3, local_4->position, local_4->rotation, local_4->scale, 0, func_801040A8(local_4), param_1, param_2, param_3, param_4);
        break;
    }
    if (local_7) local_4->unk6C_0 = local_7;
    return local_7;
}

u8 *chanemone_entrypoint_1(void) {
    return D_80800964_chanemone;
}
