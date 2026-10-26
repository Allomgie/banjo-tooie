#include "common.h"

extern int D_80800928_chmricecube;
typedef struct { u8 pad0[0x1A]; u16 val : 11; u16 pad1A : 5; } RiceCubeMsg;
extern u8 D_808009A8_chmricecube[];
extern u8 D_808008B0_chmricecube[];
extern void func_800EE7F8();
extern void func_800EF1B8(f32 *, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern s32 D_808009B8_chmricecube;
extern void _subaddiedialog_entrypoint_8(s32, s32, s32 *, s32 *, s32);
extern s32 D_80800A00_chmricecube;
extern f32 D_80800970_chmricecube[];
extern f32 D_80800980_chmricecube[];
extern f32 D_80800990_chmricecube[];
extern s32 func_80101DDC(Actor *);
extern void func_80102424(Actor *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern void _capod_entrypoint_14(void);
extern void _glcutDll_entrypoint_6(s32, s32);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, f32 *);
extern void func_800C4AF0(f32 *, f32 *);
extern void func_80101180(s32, s32, s32);
extern s32 func_800D9078(f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_80102FDC(Actor *, f32);
extern void _subaddiefade_entrypoint_1(Actor *, s32);
extern void func_800DA544(s32);
extern void _glcutDll_entrypoint_17(void);
extern s32 func_800D90A4(f32 *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern f32 func_800DC178(f32, f32);
extern u8 D_808009C8_chmricecube[];
void func_808007B0_chmricecube();

int *chmricecube_entrypoint_0()
{
    return &D_80800928_chmricecube;
}

void func_8080000C_chmricecube(void *param_0)
{
  f32 local_0[3];
  f32 *local_1;
  local_1 = (char *) param_0;
  func_800EE7F8((void *) (local_1 + 6), (void *) (((char *) param_0) + 4));
  local_1 = (f32 *) (((char *) param_0) + 0x2C);
  *((f32 *) (((char *) param_0) + 0x2C)) = 0.f;
  *((f32 *) (((char *) param_0) + 0x54)) = *((f32 *) (((char *) param_0) + 0x48));
  local_1 = param_0;
  func_8010A5B0(param_0, func_800DA298(0x1C9));
  if (_glcutDll_entrypoint_20() != 0)
  {
    *((f32 *) (((char *) param_0) + 0x48)) = (f32) (*((f32 *) (((char *) param_0) + 0x48)) - 180.0f);
    func_80102424(param_0, 6);
    return;
  }
  if (func_800DA298(0x31B) != 0)
  {
    func_800FFAB0(local_1);
  }
}

void func_808000AC_chmricecube(Actor *param_0)
{
    f32 local_0;
    f32 local_1;
    s32 local_2;
    f32 local_3;

    switch (param_0->unk70_10) {
    case 1:
        func_80800778_chmricecube(param_0);
        break;
    case 2:
        param_0->unk64_19 = 1;
        func_80800850_chmricecube(param_0);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 3);
        }
        break;
    case 4:
        if (func_80101DDC(param_0)) {
            param_0->unk64_19 = 0;
            func_80102424(param_0, 1);
        }
        break;
    case 5:
        local_0 = func_800D8FF8();
        ((f32 *)param_0->actorData)[3] = func_800F15F8(((f32 *)param_0->actorData)[3], 200.0f, local_0 * 150.0f);
        func_800EF1B8(param_0->position, param_0->unk54, -(((f32 *)param_0->actorData)[3] * local_0));
        param_0->unk64_19 = 1;
        ((f32 *)param_0->actorData)[6] = func_800F15F8(((f32 *)param_0->actorData)[6], 100.0f, local_0 * 120.0f);
        param_0->rotation[1] += ((f32 *)param_0->actorData)[6] * local_0;
        if (160000.0f < func_800EFC7C(param_0->position, (f32 *)param_0->actorData)) {
            if (!param_0->unk64_20) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800970_chmricecube);
                param_0->unk64_20 = 1;
            }
            ((f32 *)param_0->actorData)[5] += local_0 * 800.0f;
            param_0->position[1] -= local_0 * ((f32 *)param_0->actorData)[5];
            if (param_0->position[1] < ((f32 *)param_0->actorData)[1] - 8000.0f) {
                _capod_entrypoint_14();
                _glcutDll_entrypoint_6(0x127, 0x49);
            }
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800980_chmricecube);
        }
        break;
    case 8:
        local_1 = func_800D8FF8();
        ((f32 *)param_0->actorData)[6] = func_800F15F8(((f32 *)param_0->actorData)[6], 100.0f, local_1 * 120.0f);
        ((f32 *)param_0->actorData)[5] += local_1 * 800.0f;
        param_0->position[1] -= local_1 * ((f32 *)param_0->actorData)[5];
        param_0->rotation[1] += ((f32 *)param_0->actorData)[6] * local_1;
        if (param_0->position[1] < 600.0f) {
            param_0->position[1] = 600.0f;
            func_800C4AF0(param_0->position, D_80800990_chmricecube);
            func_80102424(param_0, 9);
            param_0->unk58 = 4.0f;
            func_80101180(0x439, 10, 999);
        }
        break;
    case 9:
        local_2 = func_800D9078(&param_0->unk58);
        local_3 = func_800D8FF8();
        param_0->position[1] = func_800F12D4(param_0->unk58, 0.0f, 4.0f, 400.0f, 600.0f);
        func_80102FDC(param_0, func_800F12D4(param_0->unk58, 0.0f, 4.0f, 0.5f, 1.0f));
        _subaddiefade_entrypoint_1(param_0, func_800F12D4(param_0->unk58, 0.0f, 4.0f, 0, 255.0f));
        if (1.0f < param_0->unk58) {
            ((f32 *)param_0->actorData)[6] = func_800F15F8(((f32 *)param_0->actorData)[6], 0.0f, local_3 * 40.0f);
            func_808007B0_chmricecube(param_0);
        }
        param_0->rotation[1] += ((f32 *)param_0->actorData)[6] * local_3;
        if (local_2) {
            func_800DA544(0x31B);
            _glcutDll_entrypoint_17();
        }
        break;
    case 6:
        func_80800850_chmricecube(param_0);
        param_0->unk64_19 = 1;
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 7);
        }
        break;
    }
}

int func_8080050C_chmricecube(Actor *param_0, s32 param_1, s32 param_2)
{
    u32 local_2;
    Vec3f local_0;
    u8 *local_1;
    s16 local_3;

    switch (param_1) {
    case 0x2E:
        local_3 = ((s16 *)&param_2)[0];
        if (_subaddiedialog_entrypoint_9(param_0, local_3, D_808008B0_chmricecube, 5) == 1) {
            func_8010A590(param_0);
        }
        local_2 = param_0->unk70_10;
        if (local_2 == 3 || local_2 == 2) {
            func_80102424(param_0, 4);
        }
        break;
    case 0x40:
        local_1 = (u8 *)param_2;
        func_8010A624(param_0);
        func_800EE7F8(local_0.f, param_0->position);
        func_800EF1B8(local_0.f, param_0->rotation[1], 300.0f);
        func_800F77E8(((RiceCubeMsg *)local_1)->val, local_0.f);
        _capod_entrypoint_13(param_0->unk0, 0, 0, 0x831);
        func_80102424(param_0, 5);
        _subaddieDll_entrypoint_4(param_0, 1);
        func_8010A570(param_0);
        func_800FC660(14);
        break;
    case 0x49:
        if (func_800EA05C() == 0x127 && _glcutDll_entrypoint_19(0x49)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x13CC, 4, 0, 0xA9);
            func_80102424(param_0, 8);
            _subaddieDll_entrypoint_4(param_0, 1);
            *(f32 *)&param_0->actorData[6] = 100.0f;
            *(f32 *)&param_0->actorData[5] = 1200.0f;
            _capod_entrypoint_13(param_0->unk0, 0, 0x13, 0x2831);
            break;
        }
        return 0;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808009A8_chmricecube, param_0->scale);
        break;
    case 0x95:
        if (func_800EA05C() == 0x127 && !_glcutDll_entrypoint_19(0x49)) {
            func_800FFAB0(param_0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800734_chmricecube(u8 *param_0, s32 param_1)
{
  s32 val;
  func_800DF744(3, ((u32) ((*((s32 *) (((char *) param_0) + 0x64))) << 0xC)) >> 0x1F);
  func_80101870(param_0, param_1);
}

int func_80800778_chmricecube(s32 param_0)
{
  s32 local_0;
  local_0 = 5;
  _subaddiedialog_entrypoint_8(param_0, param_0 + 4, &D_808009B8_chmricecube, ((s32 *) D_808008B0_chmricecube), local_0);
}

void func_808007B0_chmricecube(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    if (func_800D90A4((f32 *)&param_0->actorData[4])) {
        func_800EE7F8(local_0, param_0->position);
        local_0[1] = 200.0f;
        func_800EE7F8(local_1, param_0->position);
        local_1[1] = 600.0f;
        func_800BBCB8(local_1, local_0, param_0->scale, 5, D_808009C8_chmricecube);
        *(f32 *)&param_0->actorData[4] = func_800DC178(0.1f, 0.15f);
    }
}

int func_80800850_chmricecube(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80800A00_chmricecube, 0x3DCCCCCD);
}
