#include "common.h"

extern int D_80800664_chcrystalbaddie;
typedef union { s32 local_0; Actor *local_1; } CrystalMessage1410;
extern f32 func_800DC178(f32, f32);
extern void func_80102424();
typedef struct { u8 pad[0x64]; u8 pad64:7; u8 flag:1; } CrystS;
extern void _subaddiejoy_entrypoint_10(CrystS *, f32, f32);
extern void _chexploder_entrypoint_4(CrystS *, s32, s32);
extern int D_808006CC_chcrystalbaddie;
extern int D_808006BC_chcrystalbaddie;
extern u8 D_808006AC_chcrystalbaddie[];
extern void *func_80100094(Actor *, u32);
extern u8 func_800D9078(f32 *);
extern void func_8010D254(f32 *);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 func_80102D78(Actor *, void *);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
extern int func_800DC298(f32);
typedef struct { u32 pad_0 : 2; u32 local_0 : 1; u32 pad_1 : 29; } Broad51CrystalFlags;
void func_808004D4_chcrystalbaddie();
void func_8080052C_chcrystalbaddie();

int chcrystalbaddie_entrypoint_0()
{
    return (int)&D_80800664_chcrystalbaddie;
}

void func_8080000C_chcrystalbaddie(u8 *param_0) {
    _subaddierouteDll_entrypoint_3(param_0, func_80100094(param_0, 0), param_0 + 4);
    *(f32 *)(param_0 + 0x2C) = 0.0f;
    *(f32 *)(param_0 + 0x24) = 0.0f;
}

void func_808004B4_chcrystalbaddie();

void func_808003C4_chcrystalbaddie();

void func_80800054_chcrystalbaddie(Actor *param_0)
{
    u8 *local_0;
    f32 local_1;
    local_0 = func_80100094(param_0, 0);
    func_8010D254((f32 *)param_0->actorData);
    func_800D9078(&param_0->unk58);
    switch (param_0->unk70_10) {
    case 1:
        if (((Broad51CrystalFlags *)((u8 *)param_0 + 0x64))->local_0) {
            func_808003C4_chcrystalbaddie(param_0, 2);
        } else if (func_80800424_chcrystalbaddie(param_0)) {
            func_808003C4_chcrystalbaddie(param_0, 2);
        }
        break;
    case 2:
        {
            extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_808006AC_chcrystalbaddie, 0.0f);
        }
        if (func_80101DDC(param_0)) {
            func_808003C4_chcrystalbaddie(param_0, 3);
        }
        break;
    case 3:
        if (((Broad51CrystalFlags *)((u8 *)param_0 + 0x64))->local_0) {
            local_1 = _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3);
            *(f32 *)((u8 *)param_0 + 0x24) = *(f32 *)((u8 *)param_0 + 0x2C);
            func_80102BF8(param_0, 0.2f, 8.0f, 500.0f);
            func_8010C3A8(param_0, 0x205015, local_1);
        } else {
            if (_subaddierouteDll_entrypoint_4(param_0)) {
                param_0->unk54 = func_80102D78(param_0, (f32 *)param_0->actorData);
                _subaddierouteDll_entrypoint_7(param_0, local_0, param_0->rotation[1], param_0->unk54, 200.0f, 0x5800);
                *(s32 *)(local_0 + 0xC) = *(u16 *)(local_0 + 6);
            }
            _subaddierouteDll_entrypoint_5(param_0, local_0, *(s32 *)(local_0 + 0xC), 0.15f, 8.0f, 200.0f);
            *(f32 *)((u8 *)param_0 + 0x24) = func_800F15F8(*(f32 *)((u8 *)param_0 + 0x24), *(f32 *)((u8 *)param_0 + 0x2C), func_800D8FF8() * 400.0f);
            func_8010B990(param_0, 0x305115);
            if (_subaddierouteDll_entrypoint_4(param_0) && func_800DC298(0.2f) &&
                (!func_8010C9B0(param_0->position, 1200) || !func_8010C500(param_0))) {
                func_808003C4_chcrystalbaddie(param_0, 4);
            }
        }
        func_808004B4_chcrystalbaddie((s32)param_0);
        break;
    case 4:
        if (func_80101DDC(param_0)) {
            func_808003C4_chcrystalbaddie(param_0, 1);
            param_0->unk58 = 1.4f;
        }
        break;
    }
}

int func_808002E0_chcrystalbaddie(Actor *param_0, s32 param_1, CrystalMessage1410 param_2)
{
    switch (param_1) {
        case 0x90:
            func_8080052C_chcrystalbaddie(param_0);
            break;
        case 0x40:
            func_808004D4_chcrystalbaddie(param_0, param_2.local_1);
            break;
        case 2:
            if (!_subaddieDll_entrypoint_3(param_0)) {
                func_80107070(param_0, 1);
            }
            break;
        case 0x95:
            _subaddierouteDll_entrypoint_1(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800384_chcrystalbaddie(s32 arg0) 
{
}
s32 func_8080038C_chcrystalbaddie(s32 param_0, s32 param_1){
    func_800DF744(3, 1);
    func_80101870(param_0, param_1);
}

void func_808003C4_chcrystalbaddie(u8 *param_0, s32 param_1) {
    func_80102424(param_0, param_1);
    switch (param_1) {
    case 1:
        break;
    case 3:
        *(f32 *)(param_0 + 0x2C) = func_800DC178(400.0f, 450.0f);
        *(f32 *)(param_0 + 0x24) = 0.0f;
        break;
    }
}

int func_80800424_chcrystalbaddie(f32 param_0[3])
{
  if (param_0[0x16] > 0.0f)
  {
    return 0;
  }
  if (_subaddierouteDll_entrypoint_4(param_0) && func_8010C9B0(&param_0[1], 0x4B0) != 0 && _suchase_entrypoint_1(param_0) != 0 && func_8010C500(param_0) != 0)
  {
    return 1;
  }
  return 0;
}

void func_808004B4_chcrystalbaddie(s32 arg0)
{
    func_80105230(arg0,0);
}

void func_808004D4_chcrystalbaddie(param_0, param_1) CrystS *param_0; s32 *param_1; {
    _subaddiejoy_entrypoint_10(param_0, 1.0f, 0.3f);
    _chexploder_entrypoint_4(param_0, *param_1 + 4, 4);
    param_0->flag = 0;
}

void func_8080052C_chcrystalbaddie(param_0) s32 param_0;
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  local_0 = func_80106790(func_80101080());
  _chexploder_entrypoint_12(local_0, 0x14);
  _chexploder_entrypoint_14(local_0, 3);
  _chexploder_entrypoint_9(local_0, 2, 0);
  _chexploder_entrypoint_9(local_0, 3, 2);
  _chexploder_entrypoint_15(local_0, 2, 0x3F000000);
  local_1 = local_0 + 0x18;
  func_800BBCB8(local_1, local_1, 0x3F800000, 4, &D_808006CC_chcrystalbaddie);
  _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_808006BC_chcrystalbaddie);
  if (func_80107070(param_0, 3) == 0)
  {
    func_800FFAB0(param_0);
  }
}
