#include "common.h"

extern int D_808008F4_choctopus;
extern void _subaddieDll_entrypoint_4();
extern void _subaddieaudioloop_entrypoint_5();
extern void func_80102424();
extern f32 D_808008D4_choctopus;
extern s32 D_8080093C_choctopus;
extern void *func_80100094();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80101CDC(Actor *, f32);
extern s32 D_80800950_choctopus[][3];
extern s32 D_80800980_choctopus[];
extern void func_800F3214(s32 *, s32 *, s32 *, f32);
extern u8 D_808008C0_choctopus[];
extern u8 D_8080098C_choctopus[];
extern int D_80800998_choctopus;
extern void func_80102FDC(u8 *, f32);
extern s32 _subaddiesect_entrypoint_1();
extern void _choctopus_entrypoint_1(void);
typedef union { s32 local_0; void *local_1; } OctopusEventPayload;
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_80103F38(Actor *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern s32 _subaddiecustomhits_entrypoint_3(Actor *, f32 *, f32);
extern s32 func_800B1F8C(void *, f32 *, f32 *, f32, s32, s32, f32 *, f32, s32, s32);

int choctopus_entrypoint_0()
{
    return (int)&D_808008F4_choctopus;
}

void func_8080000C_choctopus(u8 *param_0) {
    func_80102FDC(param_0, *(f32 *)(param_0 + 0x38) * 0.8f);
    *(s32 *)(param_0 + 0x30) = _subaddiesect_entrypoint_1(param_0);
}

void func_80800054_choctopus(Actor *param_0)
{
    void *local_0;
    f32 *local_1;
    local_0 = func_80100094(param_0, 1);
    _subaddiesect_entrypoint_0(param_0, param_0->actorData[6], 2);
    if (local_0) { _suexpression_entrypoint_10(local_0, param_0->unk0, 0); }
    local_1 = param_0->position;
    _subaddieaudioloop_entrypoint_5(param_0, local_1, param_0->unk70_10 == 1, 0x1194, &D_8080093C_choctopus);
    switch ((int)param_0->unk70_10) {
    case 1: break;
    case 2:
        func_80101CDC(param_0, func_800F10B4(param_0->unk58, 0.0f, 1.25f, 30.0f, D_808008D4_choctopus));
        if (func_800D9078(&param_0->unk58)) {
            func_80102424(param_0, 3);
            param_0->unk58 = 8.0f;
        }
        break;
    case 3:
        if (func_800D9078(&param_0->unk58)) {
            _subaddieaudioquick_entrypoint_2(param_0, local_1, ((s32 *) D_808008C0_choctopus));
            func_80102424(param_0, 4);
            func_80101CDC(param_0, 30.0f);
            param_0->unk58 = 3.75f;
        }
        break;
    case 4:
        func_80101CDC(param_0, func_800F10B4(param_0->unk58, 0.0f, 3.75f, D_808008D4_choctopus, 30.0f));
        if (func_800D9078(&param_0->unk58)) {
            func_80102424(param_0, 1);
            if (local_0) { _suexpression_entrypoint_18(local_0, 0); }
            _subaddieDll_entrypoint_4(param_0, 0);
        }
        break;
    }
}

s32 func_808007E4_choctopus();

void func_80800210_choctopus()
{
    func_808007E4_choctopus();
}

void func_80800230_choctopus(Actor *param_0, s32 param_1)
{
    s32 local_1;
    s32 local_0[3];
    func_801015D0(param_0);
    switch (param_0->unk70_10) {
    case 2:
        local_1 = (s32)func_800F10B4(param_0->unk58, 0.0f, 1.25f, 255.0f, 0);
        break;
    case 3:
        local_1 = 255;
        break;
    case 4:
        local_1 = (s32)func_800F10B4(param_0->unk58, 0.0f, 3.75f, 0, 255.0f);
        break;
    default:
        local_1 = 0;
        break;
    }
    func_800F3214(local_0, D_80800950_choctopus[param_0->unk74_7 - 50], D_80800980_choctopus, (f32)local_1 / 255.0f);
    func_800DF5D8(local_0[0], local_0[1], local_0[2], 255);
}

void func_80800790_choctopus();

void func_80800428_choctopus();

s32 func_80800348_choctopus(Actor *param_0, s32 param_1, OctopusEventPayload param_2)
{
    switch (param_1) {
    case 0x40: func_80800428_choctopus(param_0, param_2.local_0); break;
    case 0x1F: func_80800230_choctopus(param_0, param_2.local_0); break;
    case 0x29: func_80800790_choctopus(param_0); break;
    case 0x2A: func_808007E4_choctopus(param_0); break;
    case 0x1C:
        if (param_0->unk70_10 == 1) return 2;
        return 1;
    case 0x95: _subaddiecustomhits_entrypoint_0(param_0, _choctopus_entrypoint_1); break;
    default: return 0;
    }
    return 1;
}

void func_80800428_choctopus(Actor *param_0, s32 param_1)
{
  s32 local_0;
  s32 local_5;
  u8 *local_4;
  local_0 = ((*((s32 *) (((char *) param_0) + 0x6C))) & 0x1FF) == 1;
  local_5 = func_800CB854(0) == 5;
  if ((local_0 != 0) || (local_5 != 0))
  {
    local_4 = func_80100094(param_0, 1);
    switch (((u32) (*((u16 *) (((char *) param_0) + 0x72)))) >> 0xA)
    {
      case 1:
        func_80102424(param_0, 2, local_4);
        _subaddieDll_entrypoint_4(param_0, 1);
        *((f32 *) (((char *) param_0) + 0x58)) = 1.25f;
        if (local_4 != 0)
      {
        _suexpression_entrypoint_18(local_4, 2);
      }
        _subaddieaudioquick_entrypoint_2(param_0, ((u8 *) param_0) + 4, &D_808008C0_choctopus);
        if (local_5 == 0)
      {
        _subaddieaudioquick_entrypoint_2(param_0, ((u8 *) param_0) + 4, &D_8080098C_choctopus);
        return;
      }
        break;

      case 3:
        *((f32 *) (((char *) param_0) + 0x58)) = 8.0f;
        break;

    }

  }
}

s32 func_80800540_choctopus(Unk80132ED0 *param_0, f32 *param_1, f32 param_2, s32 param_3, s32 param_4)
{
    Actor *local_6;
    s32 local_0;
    f32 local_8;
    f32 local_1[3];
    s32 local_7;
    f32 local_2[3];
    s32 local_9;
    f32 local_3;
    f32 *local_5;
    void *local_4;
    local_6 = func_80106790(param_0);
    if (_subaddiecustomhits_entrypoint_3(local_6, param_1, param_2)) return 0;
    switch (func_800CB854(&local_0)) {
    case 2:
        local_3 = func_80103F38(local_6, local_1) * 0.8f;
        return func_800EFFB4(local_1, param_2 + local_3, param_1);
    case 5:
        local_3 = func_80103F38(local_6, local_2) * 0.8f;
        local_7 = func_800EFFB4(local_2, param_2 + local_3, param_1);
        break;
    default:
        local_4 = (void *)func_80103D98(param_0);
        if (!local_4) return 0;
        local_5 = local_6->position;
        local_3 = func_800F1DCC(local_6->rotation[1], func_800F1DF4(local_5, param_1));
        local_8 = mlAbsF(local_3);
        param_4 = 0;
        if (local_8 < 90.0f) param_4 = 8;
        if (local_8 > 35.0f) param_4 |= 2;
        if (local_3 < 35.0f) param_4 |= 0x10;
        if (local_3 > -35.0f) param_4 |= 4;
        if (func_800EFC7C(local_5, param_1) > SQ(local_6->scale * 800.0f)) param_4 |= 0x201;
        local_7 = func_800B1F8C(local_4, local_5, local_6->rotation, local_6->scale, 0, func_801040A8(local_6), param_1, param_2, param_3, param_4);
        break;
    }
    if (local_7) local_6->unk6C_0 = local_7;
    return local_7;
}

int choctopus_entrypoint_1()
{
    return (int)&D_80800998_choctopus;
}

void func_80800790_choctopus(Actor *param_0)
{
    if (!func_80100094(param_0, 1))
    {
        _suexpression_entrypoint_7(param_0, 1, 0xB6);
        _suexpression_entrypoint_12(func_80100094(param_0, 1), 0x42A00000, 0x41F00000);
    }
}

s32 func_808007E4_choctopus(s32 param_0) {
    if (func_80100094(param_0, 1)) {
        _suexpression_entrypoint_8(param_0, 1);
    }
}
