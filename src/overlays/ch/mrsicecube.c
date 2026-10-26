#include "common.h"

extern int D_8080099C_chmrsicecube;
extern int D_808009E4_chmrsicecube;
extern s32 D_808008F0_chmrsicecube;
extern s32 D_80800A2C_chmrsicecube;
typedef union { s32 local_0; s16 local_2; s16 local_1[2]; } MrsIceCubeMessage36;
extern f32 func_80103FB8(Actor *);
extern s32 func_800E3E8C(f32 *, f32);
extern void *func_80100094(Actor *, s32);
extern Actor *_subaddielink_entrypoint_4(void *);
extern void func_8010A764(Actor *, f32 *);
extern void func_800DF744(s32, s32);
extern void func_80101870(Actor *, f32 *);
extern s32 _subaddiefind_entrypoint_0();
extern void func_800EE7F8(s32, s32);
extern s32 D_80800A3C_chmrsicecube;
extern s32 D_80800A44_chmrsicecube;
extern int _subaddiedialog_entrypoint_8();
extern u16 D_80800912_chmrsicecube[];
extern s32 D_80800A54_chmrsicecube;
typedef struct { u8 local_0[0x74]; u32 : 11; u32 local_1 : 1; u32 : 20; } MrsIceCubeFlags36;
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern void func_801094E0(f32 *, f32);
extern u8 D_80800A74_chmrsicecube[];
extern u8 D_80800A64_chmrsicecube[];
extern int D_80800AB8_chmrsicecube;
typedef struct { u8 pad_0[0x74]; u32 pad_1 : 11; u32 local_0 : 1; u32 pad_2 : 14; u32 local_1 : 1; u32 pad_3 : 5; } IceCubeFlags31;
extern s32 D_80800910_chmrsicecube;
extern f32 func_800EEB40(f32 *, f32 *);
void func_808006C4_chmrsicecube();
void func_80800818_chmrsicecube();
Unk80132ED0 *func_80800508_chmrsicecube();

int chmrsicecube_entrypoint_0()
{
  return (int)&D_8080099C_chmrsicecube;
}

int chmrsicecube_entrypoint_1()
{
    return (int)&D_808009E4_chmrsicecube;
}

void func_80800018_chmrsicecube(u8 *param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_80100094(param_0, 0);
  func_8010A800(param_0, 0);
  _subaddielink_entrypoint_0(local_0);
  if ((!local_0) && (!local_0))
  {
  }
  local_1 = (((u32) (*((u16 *) (((char *) param_0) + 0x76)))) >> 7) - 0x32;
  *((s32 *) (((char *) param_0) + 0x28)) = local_1;
  if (local_1 == 0)
  {
    func_8010A5B0(param_0, func_800DA298(0x1C5));
    if (_glcutDll_entrypoint_20() != 0)
    {
      func_80102424(param_0, 7);
      return;
    }
    if (func_800DA298(0x378) != 0)
    {
      func_800FFAB0(param_0);
    }
  }
}

void func_80800634_chmrsicecube();

void func_808000BC_chmrsicecube(Actor *param_0)
{
    void *local_0;
    Actor *local_1;
    s32 local_2;
    f32 local_3[3];
    f32 local_4[3];
    local_0 = func_80100094(param_0, 0);
    local_2 = 0;
    switch (param_0->unk70_10) {
        case 2: func_80800634_chmrsicecube(param_0); break;
        case 3:
            param_0->unk64_19 = 1;
            func_80800898_chmrsicecube(param_0);
            local_2 = 1;
            if (func_80101DDC(param_0)) { func_80102424(param_0, 4); }
            break;
        case 5:
            local_2 = 1;
            if (func_80101DDC(param_0)) {
                param_0->unk64_19 = 0;
                func_80102424(param_0, 2);
            }
            break;
        case 6:
            if (_subaddieDll_entrypoint_6(param_0, 0xA)) { func_808006C4_chmrsicecube(param_0); }
            break;
        case 7:
            func_80800898_chmrsicecube(param_0);
            local_2 = 1;
            param_0->unk64_19 = 1;
            if (func_80101DDC(param_0)) { func_80102424(param_0, 8); }
            break;
    }
    local_1 = (Actor *)_subaddielink_entrypoint_4(local_0);
    if (local_1) {
        func_8080066C_chmrsicecube(param_0, local_3);
        func_800EE7F8(local_1->position, local_3);
        if (local_2 && _subaddieskeleton_entrypoint_0(param_0, 3, local_4)) {
            local_1->position[1] += local_4[1] - param_0->position[1];
        }
    }
}

s32 func_80800260_chmrsicecube(Actor *param_0, s32 param_1, MrsIceCubeMessage36 param_2)
{
    s32 local_1;
    s32 local_0;
    s16 local_2;

    switch (param_1) {
        case 0x2E:
            local_2 = param_2.local_1[0];
            if (_subaddiedialog_entrypoint_9(param_0, local_2, &D_808008F0_chmrsicecube, 4) == 1) func_8010A590(param_0);
            func_80102424(param_0, 5);
            break;
        case 0x40:
            if (_subaddieDll_entrypoint_5(param_0, param_2.local_0)) {
                func_80103110(param_0, 1);
                _subaddieDll_entrypoint_4(param_0, 1);
                func_80102424(param_0, 6);
            } else {
                func_808006C4_chmrsicecube(param_0);
            }
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800A2C_chmrsicecube, *(s32 *)&param_0->scale);
            break;
        case 0x95:
            local_0 = func_80100094(param_0, 0);
            local_1 = func_80800508_chmrsicecube(param_0);
            if (local_1) _subaddielink_entrypoint_1(local_0, local_1);
            else if (param_0->actorData[4] || !_glcutDll_entrypoint_20()) func_800FFAB0(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003BC_chmrsicecube(Actor *param_0, f32 *param_1)
{
    Actor *local_0;

    if (func_800E3E8C(param_0->position, func_80103FB8(param_0))) {
        local_0 = _subaddielink_entrypoint_4(func_80100094(param_0, 0));
        if (local_0 != NULL) {
            func_8010A764(local_0, param_1);
        }
        func_800DF744(3, param_0->unk64_19);
        func_80101870(param_0, param_1);
    }
}

s32 func_8080043C_chmrsicecube(u8 *param_0, s32 param_1, s32 param_2) {
    s32 local_0 = _subaddiefind_entrypoint_0(param_0 + 4, param_1, -1, 0);
    if (local_0) {
        func_800EE7F8(param_2, local_0 + 4);
    }
    return local_0;
}

s32 func_8080048C_chmrsicecube(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_4;
    s32 local_2;

    D_80800A3C_chmrsicecube = param_1;
    local_4 = _gccubesearch_entrypoint_6(&D_80800A3C_chmrsicecube, param_0 + 4);
    if (local_4 == 0) {
        return 0;
    }
    local_2 = _subaddiefind_entrypoint_12((u32)(*(s32*)((char*)local_4 + 0x10)) >> 0x15, local_4);
    if (local_2 != 0) {
        func_800EE88C(param_2, local_4);
    }
    return local_2;
}

Unk80132ED0 *func_80800508_chmrsicecube(param_0) Actor *param_0;
{
    s32 local_4;
    Actor *local_2;
    f32 local_0[3];
    u8 *local_1;

    local_4 = param_0->actorData[4];
    local_1 = func_80100094(param_0, 0);
    if ((*(u16 *)((u8 *)&D_80800910_chmrsicecube + local_4 * 4)) == 0x1F4) {
        local_2 = func_8080043C_chmrsicecube(param_0, (*(u16 *)((u8 *)&D_80800910_chmrsicecube + local_4 * 4)), local_0);
    } else {
        local_2 = (Actor *)func_8080048C_chmrsicecube((s32)param_0, (*(u16 *)((u8 *)&D_80800910_chmrsicecube + local_4 * 4)), (s32)local_0);
    }
    if (local_2 && func_800EEB40(local_0, param_0->position) < 40000.0f) {
        *(u32 *)(local_1 + 8) = ((IceCubeFlags31 *)local_2)->local_0;
        func_8010A570(local_2);
        func_8010A624(local_2);
        func_80102190(local_2, 1);
        func_80103110(local_2, 0);
        local_2->unk64_24 = 0;
        local_2->unk64_16 = 0;
        ((IceCubeFlags31 *)local_2)->local_0 = 0;
        func_8080066C_chmrsicecube((f32 *)param_0, local_2->position);
        if (((IceCubeFlags31 *)local_2)->local_1) {
            func_80103014(local_2);
        }
        return local_2->unk0;
    }
    return 0;
}

void func_80800634_chmrsicecube(s32 param_0)
{
  s32 local_0;
  local_0 = 4;
  _subaddiedialog_entrypoint_8(param_0, param_0 + 4, &D_80800A44_chmrsicecube, &D_808008F0_chmrsicecube, local_0);
}

int func_8080066C_chmrsicecube(f32 param_0[3], f32 param_1[3])
{
  f32 local_0;
  func_800EE7F8(param_1, &param_0[1]);
  ;
  param_1[1] += param_0[14] * 100.0f;
}

void func_808006C4_chmrsicecube(param_0) Actor *param_0;
{
    u8 *local_0 = (u8 *)func_80100094(param_0, 0);
    Actor *local_1 = (Actor *)_subaddielink_entrypoint_4(local_0);
    s32 local_2 = param_0->actorData[4];

    if (local_2 == 0) {
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x12D3, 0x44, 0, 0xA7);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800A54_chmrsicecube);
        func_800DA544(0x378);
    }
    if (local_1 != NULL) {
        _subaddielink_entrypoint_0(local_0);
        func_8010A590(local_1);
        func_8010A654(local_1, func_80102F74(local_1, 0x800));
        func_80102190(local_1, 0);
        func_80103110(local_1, func_80102F74(local_1, 0x80000800) == 0);
        local_1->unk64_24 = func_80102F74(local_1, 0x80000001);
        local_1->unk64_16 = 1;
        ((MrsIceCubeFlags36 *)local_1)->local_1 = *(u32 *)(local_0 + 8);
        _chbounce_entrypoint_5(*(u16 *)((u8 *)D_80800912_chmrsicecube + param_0->actorData[4] * 4), local_1);
    }
    func_80800818_chmrsicecube(param_0);
    func_800FFAB0(param_0);
}

void func_80800818_chmrsicecube(param_0) Actor *param_0;
{
    f32 local_0[3];
    func_8080066C_chmrsicecube(param_0, local_0);
    func_800BBCB8(local_0, param_0->position, param_0->scale, 0xC, (s32 *)D_80800A74_chmrsicecube);
    _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80800A64_chmrsicecube);
    func_801094E0(local_0, param_0->scale * 3.0f);
}

int func_80800898_chmrsicecube(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80800AB8_chmrsicecube, 0x3DCCCCCD);
}
