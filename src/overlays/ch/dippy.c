#include "common.h"

#define AF(p, i) (*(f32 *)&(p)->actorData[i])
extern int D_80801580_chdippy;
extern int D_808015C8_chdippy;
typedef struct { u8 pad_0[0x70]; u8 local_0 : 7; u8 pad_1 : 1; u8 pad_2; u16 pad_3 : 6; u16 local_1 : 6; u16 pad_4 : 4; } DippyState1548;
extern int _glcutDll_entrypoint_20(void);
extern int _chcredits_entrypoint_1(void);
extern void _gccubesearch_entrypoint_3(s32, f32 *);
extern int func_800CBC3C(f32 *);
extern int func_800DA298(s32);
extern void func_800DA544(s32);
extern f32 func_800F5F24(s32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern s32 func_800F20BC(f32, f32, f32);
extern void func_8010D254(f32 *);
extern float D_80801490_chdippy;
extern void *D_808014B0_chdippy;
typedef struct { u8 pad[0x64]; u32 pad64:11; u32 flag:1; u32 rest:20; } BitsState;
extern void _capod_entrypoint_14();
extern u8 position_x[];
extern u8 unk65[];
extern Actor *func_80106790();
extern u8 D_80801610_chdippy[];
extern u8 D_808014A0_chdippy[];
extern u8 D_80801688_chdippy[];
extern u8 D_80801480_chdippy[];
extern u8 D_8080164C_chdippy[];
extern u8 D_80801698_chdippy[];
extern u8 D_8080165C_chdippy[];
extern u8 D_8080166C_chdippy[];
extern s32 D_80801620_chdippy[];
extern f32 func_80101F24(Actor *);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800BA544();
extern u8 D_808016E8_chdippy[];
extern u8 D_808016C4_chdippy[];
extern u8 D_808016DC_chdippy[];
extern s32 D_808014D8_chdippy[];
extern u8 D_808016B4_chdippy[];
extern u8 D_808016A4_chdippy[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } DippyState;
typedef struct { u8 pad_0[0x79]; u8 cnt : 4; u8 low : 4; } DippyCnt;
extern u8 D_808016F0_chdippy[];
extern u8 D_80801734_chdippy[];
extern void _chdippy_entrypoint_2(void);
extern void _chdippy_entrypoint_3(void);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800DC0C0(void);
extern void func_8010D930();
typedef struct DippyVisibilityFlags { u16 pad_0 : 15; u16 local_0 : 1; } DippyVisibilityFlags;
typedef union DippyEvent { s32 local_0; f32 local_1; } DippyEvent;
extern void func_800DF500(f32, f32, f32);
extern u8 D_8080174C_chdippy[];
void func_80800CBC_chdippy();
void func_80800D44_chdippy();
int func_8080047C_chdippy();
void func_80800654_chdippy();
void func_80800800_chdippy();
void func_808009D8_chdippy();
void func_80801200_chdippy();

int chdippy_entrypoint_0()
{
  return (int)&D_80801580_chdippy;
}

int chdippy_entrypoint_1()
{
    return (int)&D_808015C8_chdippy;
}

void func_80800018_chdippy(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;

    local_1 = _glcutDll_entrypoint_20() && _chcredits_entrypoint_1() == 0x61;
    _gccubesearch_entrypoint_3(0x3AD, local_0);
    ((DippyState1548 *)param_0)->local_0 = func_800CBC3C(local_0) + 1;
    ((DippyState1548 *)param_0)->local_1 = 1;
    if (func_800DA298(0x327)) func_800DA544(0x328);
    func_80800654_chdippy(param_0, local_1 ? 14 : 1);
}

void func_80800990_chdippy();

void func_80800530_chdippy();

void func_808000D8_chdippy(u8 *param_0)
{
  unsigned int new_var;
  u32 local_0;
  new_var = *((u16 *) (((s8 *) param_0) + 0x72));
  local_0 = (u16) new_var;
  local_0 = local_0 >> 0xA;
  switch (local_0)
  {
    case 1:
      func_80800530_chdippy(param_0);
      return;

    case 3:
      if (func_80101E14(param_0, 0x3F19999A) != 0)
    {
      _chintrotext_entrypoint_1(0x18B9, 0xE, 1, 0);
    }
      func_80800800_chdippy(param_0);
      if (func_80101DDC(param_0) != 0)
    {
      _subaddiedialog_entrypoint_11(*((s32 *) (((s8 *) param_0) + 0)), 0x17E9, 6, param_0 + 4, 0xAC);
      func_80800654_chdippy(param_0, 5);
      return;
    }

    default:
      return;

    case 4:
      func_80800948_chdippy(param_0);
      if (func_80101DDC(param_0) != 0)
    {
      if (func_800DA298(0x327) != 0)
      {
        func_80800654_chdippy(param_0, 0xA);
        return;
      }
      _subaddiedialog_entrypoint_11(*((s32 *) (((s8 *) param_0) + 0)), 0x17EA, 7, param_0 + 4, 0xAC);
      func_80800654_chdippy(param_0, 5);
      return;
    }
      break;

    case 6:
      if (func_80101DDC(param_0) != 0)
    {
      func_80800D44_chdippy(param_0);
      func_80800654_chdippy(param_0, 1);
      return;
    }
      break;

    case 7:
      func_80800990_chdippy(param_0);
      if (func_80101DDC(param_0) != 0)
    {
      _subaddiedialog_entrypoint_11(*((s32 *) (((s8 *) param_0) + 0)), 0x17EB, 6, param_0 + 4, 0xAC);
      func_80800654_chdippy(param_0, 8);
      return;
    }
      break;

    case 9:
      if (func_80101DDC(param_0) != 0)
    {
      func_80800D44_chdippy(param_0);
      func_80800654_chdippy(param_0, 1);
      return;
    }
      break;

    case 10:
      func_808009D8_chdippy(param_0);
      if (func_80101DDC(param_0) != 0)
    {
      _subaddiedialog_entrypoint_11(*((s32 *) (((s8 *) param_0) + 0)), 0x17EC, 6, param_0 + 4, 0xAC);
      func_80800654_chdippy(param_0, 8);
      return;
    }
      break;

    case 11:
      if (func_80101DDC(param_0) != 0)
    {
      _subaddiedialog_entrypoint_11(*((s32 *) (((s8 *) param_0) + 0)), 0x17ED, 7, param_0 + 4, 0xAC);
      func_80800654_chdippy(param_0, 0xC);
      return;
    }
      break;

    case 13:
      if (func_80101DDC(param_0) != 0)
    {
      func_80800D44_chdippy(param_0);
      func_80800654_chdippy(param_0, 1);
      return;
    }
      break;

    case 14:
      func_80800990_chdippy(param_0);
      if (func_80101DDC(param_0) != 0)
    {
      func_80800654_chdippy(param_0, 0xF);
    }
      break;

  }

}

s32 func_80800374_chdippy(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x2E:
        func_8080047C_chdippy(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        return 1;
    case 0xB:
        switch (param_2) {
        case 0x47:
            func_80800654_chdippy(param_0, 7);
            return 4;
        case 0x37:
            func_80800D44_chdippy(param_0);
            if (_glcutDll_entrypoint_19(0x36)) {
                _glcutDll_entrypoint_17();
            }
            return 4;
        }
        return 3;
    case 0x95:
        if (_glcutDll_entrypoint_19(0x36)) {
            _subaddieDll_entrypoint_4(param_0, 1);
            func_80800654_chdippy(param_0, 2);
            func_80800CBC_chdippy(param_0, 0x47, 0x2030);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

int func_8080047C_chdippy(param_0, param_1, param_2) s32 param_0; u32 param_1; Actor *param_2;
{
  switch (param_1 - 0x17E9)
  {
    case 0 :
      func_80800654_chdippy(param_0 | 0, 6);
      return;

    case 1 :
      func_80800654_chdippy(param_0 | 0, 6);
      return;

    case 2 :
      func_80800654_chdippy(param_0 | 0, 0xA);
      return;

    case 3 :
      func_800D0C78(0x2A, 1, 0);
      func_80800654_chdippy(param_0 | 0, 9);
      return;

    case 4 :
      func_80800654_chdippy(param_0 | 0, 0xD);
      return;

    default:
      return;
  }
}

void func_80800530_chdippy(u8 *param_0)
{
    s32 local_0;
    f32 local_1[3];
    local_0 = func_800F54E4();
    if (func_8010D23C() && func_800F6C5C(local_0) && func_800F64A4(local_0, 0x601) && func_8010C500(param_0)) {
        if (!func_800DA298(0x328)) {
            func_80800654_chdippy(param_0, 3);
            return;
        }
        if (func_80016B30(0, 1) == 1 && func_800F4BB8(local_0, -1, 0)) {
            func_8010D254(local_1);
            if (!func_800F20BC(func_800F5F24(local_0), func_800F1DF4(local_1, (f32 *)(param_0 + 4)), 60.0f)) {
                func_800F5FE0(local_0);
                return;
            }
            if (func_800DA298(0x327)) func_80800654_chdippy(param_0, 11);
            else func_80800654_chdippy(param_0, 4);
        }
    }
}

void func_80800654_chdippy(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0[3];
    _subaddieskeleton_entrypoint_3(param_0->unk0, 5, local_0, param_0);
    func_80102424(param_0, param_1);
    param_0->unk64_16 = 1;
    switch (param_1) {
        case 1: case 2: param_0->unk64_16 = 0; break;
        case 3:
            func_800DA544(0x328);
            func_80800CBC_chdippy(param_0, 0x29, 0x30);
            break;
        case 4: func_80800CBC_chdippy(param_0, 0x2E, 0x30); break;
        case 5: func_80800CBC_chdippy(param_0, 0x31, 0x30); break;
        case 6:
            func_80800CBC_chdippy(param_0, 0x37, 0x30);
            _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80801610_chdippy);
            break;
        case 7: func_80800CBC_chdippy(param_0, 0x2E, 0x30); break;
        case 8: func_80800CBC_chdippy(param_0, 0x31, 0x30); break;
        case 9: func_80800CBC_chdippy(param_0, 0x37, 0x30); break;
        case 10: func_80800CBC_chdippy(param_0, 0x34, 0x30); break;
        case 11: func_80800CBC_chdippy(param_0, 0x2E, 0x30); break;
        case 12: func_80800CBC_chdippy(param_0, 0x31, 0x30); break;
        case 13: func_80800CBC_chdippy(param_0, 0x37, 0x30); break;
    }
}

void func_80800800_chdippy(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1;
    s32 local_2;
    local_1 = func_80101F24(param_0);
    local_2 = func_8001211C();
    _subaddieskeleton_entrypoint_3(param_0->unk0, 5, local_0);
    _subaddieaudioquick_entrypoint_4(param_0, local_0, D_808014A0_chdippy, D_80801688_chdippy);
    _subaddieaudioquick_entrypoint_3(param_0, local_0, D_80801480_chdippy, 0.43f);
    _subaddieaudioquick_entrypoint_4(param_0, local_0, D_8080164C_chdippy, D_80801698_chdippy);
    _subaddieaudioquick_entrypoint_3(param_0, local_0, D_8080165C_chdippy, 0.9f);
    _subaddieaudioquick_entrypoint_3(param_0, local_0, D_8080166C_chdippy, 0.61f);
    if (local_1 > 0.61f && local_1 < 0.66f && !(local_2 & 1) &&
        _subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_0))
        func_800BBCB8(local_0, 0, 1.0f, 1, D_80801620_chdippy);
}

int func_80800948_chdippy(Actor *param_0)
{
    s32 local_0[3];
    _subaddieskeleton_entrypoint_3(param_0->unk0, 5, local_0);
    _subaddieaudioquick_entrypoint_3(param_0, local_0, ((int *) D_80801480_chdippy), 0.4f);
}

void func_80800990_chdippy(Actor *param_0)
{
    f32 local_0[3];

    _subaddieskeleton_entrypoint_3(param_0->unk0, 5, local_0);
    _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80801490_chdippy, 0.15f);
}

void func_808009D8_chdippy(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2[3];
    s32 local_3;
    f32 local_4[4][3];
    s32 local_5;
    s32 local_6;
    u8 *local_8;

    local_1 = func_80101F24(param_0);
    _subaddieskeleton_entrypoint_3(param_0->unk0, 5, local_0);
    _subaddieaudioquick_entrypoint_4(param_0, local_0, D_808016A4_chdippy, D_808016C4_chdippy);
    _subaddieaudioquick_entrypoint_4(param_0, local_0, D_808016B4_chdippy, D_808016DC_chdippy);
    if (_subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_2) && local_2[1] < 1500.0f) {
        _subaddieskeleton_entrypoint_2(param_0->unk0, 5, local_0);
        local_0[1] = 1500.0f;
        func_800BBCB8(local_0, 0, 1.5f, 1, ((s32 *) &D_808014B0_chdippy));
        _subaddieskeleton_entrypoint_2(param_0->unk0, 7, local_0);
        local_0[1] = 1500.0f;
        func_800BBCB8(local_0, 0, 1.5f, 1, ((s32 *) &D_808014B0_chdippy));
    }
    if (local_1 > 0.3f && param_0->unk7C_12 && local_2[1] > 1500.0f) {
        local_3 = func_800DC128(0, 3);
        for (local_5 = 0; local_5 < 4; local_5++) {
            _subaddieskeleton_entrypoint_2(param_0->unk0, local_5 + 5, local_4[local_5]);
        }
        local_6 = func_800B53A4(1);

        func_800BA994(local_6, -45, (s16)((param_0->rotation[1]) - 25.0f), 25, -25, (s32)((param_0->rotation[1]) + 25.0f), 75);
        func_800BA5A8(local_6, 0x1200);
        func_800BABB8(local_6, local_2, 0, 1.0f, D_808014D8_chdippy);
        func_800BA4D0(local_6, 1500);
        func_800BA544(local_6, _chdippy_entrypoint_2);
        local_8 = &D_808016E8_chdippy[local_3 * 2];
        func_800BA1D0(local_6, local_4[local_8[0]], local_4[local_8[1]], 1);
    }
}

void chdippy_entrypoint_2(s32 param_0, s32 param_1)
{
  void *local_0 = &D_808014B0_chdippy;
  func_800BBCB8(param_1 | 0, 0, 1.2f, 1, local_0);
}

void func_80800CBC_chdippy(param_0, param_1, param_2) Actor *param_0; s32 param_1; u32 param_2;
{
    if (param_0->unk64_20) {
        _capod_entrypoint_14();
        param_2 |= 0x2000;
    }
    if (_glcutDll_entrypoint_19(0x36)) param_2 |= 0x800;
    _capod_entrypoint_13(param_0->unk0, 0, param_1, param_2);
    param_0->unk64_20 = 1;
}

void func_80800D44_chdippy(param_0) BitsState *param_0; {
    if (param_0->flag) {
        _capod_entrypoint_14(param_0);
        ((u8 *)param_0)[0x65] &= ~0x10;
    }
}

int func_80800D84_chdippy(Actor *param_0)
{
  u8 local_0;
  ;
  *((u8 *) (((char *) param_0) + 0x65)) = (*((u8 *) (((char *) param_0) + 0x65))) & (~1);
  *((f32 *) (((char *) param_0) + 0x1C)) = *((f32 *) (((char *) param_0) + 0x8));
}

void func_80800D9C_chdippy(Actor *param_0)
{
    s32 local_0;
    f32 local_1[3];
    s32 local_3;
    s32 local_2;
    s32 local_4;
    s32 local_7;

    switch (((DippyState *)param_0)->st) {
    case 2:
        func_800D9078(&param_0->unk58);
        AF(param_0, 0) = func_800F12D4(param_0->unk58, 0.0f, 6.0f, 0.0f, -2000.0f);
        param_0->position[1] = AF(param_0, 1) + AF(param_0, 0);
        if (1.0f < param_0->unk58) {
            func_800BBCB8(param_0->position, param_0->position, 1.0f, 2, D_808016F0_chdippy);
        } else {
            param_0->alpha = (s32)func_800F10B4(param_0->unk58, 1.0f, 0.0f, 255.0f, 0.0f);
        }
        param_0->unk64_16 = 1;
        local_7 = func_800D90A4(&param_0->actorData[2]);
        if (local_7) {
            param_0->unk64_16 = 0;
            func_80101FDC(param_0, 3);
        } else {
            if (func_800D90A4(&param_0->actorData[3])) {
                AF(param_0, 3) = func_800DC178(0.2f, 0.5f);
                func_8010D930(9, -1, param_0->position, D_80801734_chdippy);
            }
            if (AF(param_0, 2) < 15.0f) {
                if ((func_800DC0C0()) < func_800F10B4(AF(param_0, 2), 15.0f, 0.0f, 1.0f, 0.0f)) {
                    local_0 = 1;
                } else {
                    local_0 = 0;
                }
            } else {
                local_0 = func_800F10B4(AF(param_0, 2), 30.0f, 0.0f, 3.0f, 1.0f);
            }
            if (local_0 != 0) {
                local_3 = func_800B53A4(local_0);
                func_800EE7F8(local_1, param_0->position);
                local_1[1] += 6000.0f;
                func_800BA5A8(local_3, 0x200);
                func_800BA714(local_3, 0x1F4, 0x1F4);
                func_800BABB8(local_3, local_1, 0, 1.0f, ((u8 *) D_808014D8_chdippy));
                func_800BA4D0(local_3, 0x5DC);
                func_800BA544(local_3, _chdippy_entrypoint_2);
                func_800BA22C(local_3, local_0);
            }
        }
        break;
    case 1:
    case 3:
        local_2 = func_800BEA88(1);
        _glid_entrypoint_0(local_2, 1, _chdippy_entrypoint_3, param_0->unk0);
        _glid_entrypoint_0(local_2, 2, _chdippy_entrypoint_3, param_0->unk0);
        if (1) {}
        if (((DippyCnt *)param_0)->cnt-- == 0) {
            func_800FFAB0(param_0);
        }
        break;
    }
    local_4 = func_800BEA88(1);
    local_7 = _idworld_entrypoint_4(local_4, 1);
    if (local_7) {
        _idwibble_entrypoint_5(local_7, (s16)(s32)AF(param_0, 0));
    }
    _glid_entrypoint_0(local_4, 2, _chdippy_entrypoint_3, param_0->unk0);
}

s32 func_80801110_chdippy(Actor *param_0, s32 param_1, DippyEvent param_2)
{
    f32 local_0[3];

    switch (param_1) {
        case 0x95:
            func_80801200_chdippy();
            return 1;
        case 0x1F:
            if (((DippyVisibilityFlags *)((u8 *)param_0 + 0x64))->local_0) {
                func_801015D0(param_0);
                func_800E3980(local_0);
                param_0->rotation[1] = func_800F1DF4(param_0->position, local_0);
                if (param_0->unk58 < 3.0f) {
                    func_800DF500(1.0f, func_800F10B4(param_0->unk58, 3.0f, 0.0f, 5.0f, 0.001f), 1.0f);
                } else {
                    func_800DF500(1.0f, 5.0f, 1.0f);
                }
            }
            return 1;
    }
    return 0;
}

void func_80801200_chdippy(param_0) Actor *param_0;
{
    s32 local_0 = func_800BEA88(1);

    if (_glcutDll_entrypoint_20()) {
        param_0->unk79_4 = 2;
        *(f32 *)&param_0->actorData[0] = 0.0f;
        func_80101FDC(param_0, 3);
    } else if (_glcutDll_entrypoint_19(0x36)) {
        param_0->unk58 = 6.0f;
        func_80101FDC(param_0, 2);
        param_0->unk64_16 = 1;
        *(f32 *)&param_0->actorData[2] = 30.0f;
        *(f32 *)&param_0->actorData[3] = func_800DC178(0.2f, 0.5f);
    } else {
        if (!func_800DA298(0x327)) {
            param_0->unk79_4 = 2;
            *(f32 *)&param_0->actorData[0] = -2000.0f;
            func_80101FDC(param_0, 1);
            return;
        }
        param_0->unk79_4 = 2;
        *(f32 *)&param_0->actorData[0] = 0.0f;
        func_80101FDC(param_0, 3);
    }
    _idworldmake_entrypoint_1(local_0, 0x659, 1, 1);
    if (param_0->unk70_10 == 2) func_800C4AF0(param_0->actorData, D_8080174C_chdippy);
}

void chdippy_entrypoint_3(void *param_0, Vtx *param_1, Vtx *param_2,
                        s32 param_3, Unk80132ED0 *param_4)
{
    s16 local_0;
    Vtx *local_1;
    local_0 = *(f32 *)&func_80106790(param_4)->actorData[0];
    local_1 = param_2 + param_3;
    for (; param_2 < local_1; param_2++, param_1++) {
        param_2->v.ob[1] = param_1->v.ob[1] + local_0;
    }
}
