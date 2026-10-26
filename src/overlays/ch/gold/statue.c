#include "common.h"

extern void *func_80100094(Actor *, u32);
extern Vec3f D_80800910_chgoldstatue;
extern Vec3f D_8080091C_chgoldstatue;
extern Vec3f D_80800928_chgoldstatue;
extern Vec3f D_80800934_chgoldstatue;
extern f32 _sumumbofx_entrypoint_21(void *);
extern s32 _sumumbofx_entrypoint_5(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, Vec3f *, Vec3f *, Vec3f *);
extern void _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, Vec3f *, Vec3f *, Vec3f *);
extern int D_80800990_chgoldstatue;
extern void func_800F7D38(s32, s32, f32 *, f32);
extern u8 D_80800890_chgoldstatue[];
extern u8 D_808008A0_chgoldstatue[];
extern u8 D_808008B8_chgoldstatue[];
extern u8 D_80800940_chgoldstatue[];
extern u8 D_80800954_chgoldstatue[];
extern u8 D_80800968_chgoldstatue[];
extern u8 D_8080097C_chgoldstatue[];
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern u8 _subaddieaudioloop_entrypoint_7();
void func_80800150_chgoldstatue();

int func_80800000_chgoldstatue(s32 param_0)
{
  s32 local_1;
  s16 local_0;
  local_0 = _chmumbopad_entrypoint_0(2);
  local_1 = _sumumbofx_entrypoint_0(param_0, 1, 0x2D, local_0 | 0);
  local_1 = func_80100094(param_0, 1);
  _sumumbofx_entrypoint_2(local_1);
  _sumumbofx_entrypoint_24(local_1, 0x3F266666);
  if (func_800DA298(0x57C) == 0)
  {
    _sumumbofx_entrypoint_15(local_1, 0x40400000);
    return;
  }
  _sumumbofx_entrypoint_15(local_1, 0x3E800000);
}

void func_80800094_chgoldstatue(s32 arg0)
{
    _sumumbofx_entrypoint_1(arg0,1);
}

void func_808000B4_chgoldstatue(s32 param_0, s32 param_1) {
    Actor *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 1);
    func_80101870(param_0, param_1);
    if (local_0 != 0) {
        local_1 = _sumumbofx_entrypoint_10(local_0);
        _sumumbofx_entrypoint_8(local_0, param_1);
        func_800DF5D8(0xFF, (s32) (((f32) local_1 * 0.5f) + 128.0f), 0xFF, 0xFF);
    }
}

void func_80800150_chgoldstatue(param_0, param_1) Actor *param_0; s32 param_1;
{
    func_80102424(param_0, param_1);
    switch (param_0->unk70_10) {
    case 2:
        _subaddieDll_entrypoint_4(param_0, 1);
        func_801032B0(param_0, 0x673, param_0->unk0->unk16);
        if (!func_800DA298(0x57C)) _capod_entrypoint_13(param_0->unk0, 0, 2, 0x20);
        else _capod_entrypoint_13(param_0->unk0, 0, 8, 0x20);
        func_80101180(0x2B0, 0xBB, 2);
        func_80800000_chgoldstatue(param_0);
        func_80090734(2, param_0->position);
        break;
    case 3: func_800DA3B8(0x57C, 1); break;
    case 4: break;
    case 5:
        _capod_entrypoint_14();
        func_80800094_chgoldstatue(param_0);
        func_800F7D38(func_800F54E4(), 0x3F, param_0->position, param_0->rotation[1]);
        func_800DA524(0x9DE);
        func_8010381C(param_0);
        *((u8 *)param_0 + 0x65) &= ~1;
        break;
    case 6:
        if (*(u16 *)((u8 *)param_0 + 0x64) & 1) {
            func_8010381C(param_0);
            *((u8 *)param_0 + 0x65) &= ~1;
        }
        break;
    case 7: func_801032B0(param_0, 0x673, param_0->unk0->unk16); break;
    }
}

void func_808002C8_chgoldstatue(Actor *param_0) {
    _subaddieDll_entrypoint_1();
    if (func_8010D278() == 0xE) {
        func_80800150_chgoldstatue(param_0, 6);
        return;
    }
    func_800DA524(0x9DE);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800150_chgoldstatue(param_0, 7);
    }
}

void func_8080032C_chgoldstatue(Actor *param_0)
{
    Vec3f local_0 = D_80800910_chgoldstatue;
    Vec3f local_1;
    Vec3f local_2 = D_8080091C_chgoldstatue;
    Vec3f local_3 = D_80800928_chgoldstatue;
    Vec3f local_4 = D_80800934_chgoldstatue;
    void *local_5;

    local_5 = func_80100094(param_0, 1);
    if (param_0->unk7C_12) {
        _subaddieskeleton_entrypoint_2(param_0->unk0, 2, &local_1);
        _sumumbofx_entrypoint_7(local_5, 175.0f, 0, 20, &local_3, &local_1, &local_0);
        _sumumbofx_entrypoint_6(local_5, 150.0f, 150.0f, 21, 35, &local_4, &local_1, &local_0);
        _sumumbofx_entrypoint_6(local_5, 150.0f, 100.0f, 36, 45, &local_2, &local_1, &local_0);
        _sumumbofx_entrypoint_14(local_5);
        if (param_0->unk70_10 == 2 && _sumumbofx_entrypoint_21(local_5) == 0.0f &&
            _sumumbofx_entrypoint_5(local_5, 2.0f)) {
            _sumumbofx_entrypoint_17(local_5, 1.0f);
            if (!func_800DA298(0x57C)) {
                func_80800150_chgoldstatue(param_0, 3);
                return;
            }
            func_80800150_chgoldstatue(param_0, 4);
        }
    }
}

void func_80800528_chgoldstatue(Actor *param_0)
{
    s32 local_0;
    void *local_1;

    local_0 = 0;
    if (!param_0->unk64_17) {
        local_1 = func_80100094(param_0, 1);
        switch (param_0->unk70_10) {
            case 1:
                _sudeflect_entrypoint_1(param_0->position, 240.0f, 0.0f, 100.0f, 14);
                if (func_800DA298(0x9DE)) {
                    func_80800150_chgoldstatue(param_0, 2);
                }
                break;
            case 2:
                func_8080032C_chgoldstatue(param_0);
                break;
            case 3:
                if (func_80101E14(param_0, 0.35f)) {
                    _chglowbo_entrypoint_6();
                }
                if (func_80101F24(param_0) < 0.38f) {
                    local_0 = 1;
                }
                if (func_80101E14(param_0, 0.38f)) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800890_chgoldstatue);
                } else if (func_80101E4C(param_0, D_80800940_chgoldstatue)) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808008A0_chgoldstatue);
                } else if (func_80101E4C(param_0, D_80800954_chgoldstatue)) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808008B8_chgoldstatue);
                }
                if (func_80101E14(param_0, 0.39f)) {
                    func_800DA544(0x9DF);
                    _sumumbofx_entrypoint_16(local_1, 3.0f);
                }
                func_8080032C_chgoldstatue(param_0);
                if (func_80101DDC(param_0)) {
                    func_80800150_chgoldstatue(param_0, 5);
                }
                break;
            case 4:
                func_8080032C_chgoldstatue(param_0);
                if (func_80101F24(param_0) < 0.38f) {
                    local_0 = 1;
                }
                _subaddieaudioquick_entrypoint_3(param_0, param_0->position,
                    D_80800890_chgoldstatue, 0.38f);
                if (func_80101E14(param_0, 0.34f)) {
                    _sumumbofx_entrypoint_16(local_1, 0.25f);
                    func_800DA544(0x9DF);
                } else if (func_80101E14(param_0, 0.39f)) {
                    func_80800150_chgoldstatue(param_0, 5);
                }
                break;
            case 5:
                if (!func_8010C500(param_0)) {
                    func_80800150_chgoldstatue(param_0, 6);
                }
                break;
            case 6:
                if (func_8010C500(param_0)) {
                    func_800F7B9C(func_800F54E4(), 0x82);
                }
                break;
        }
        if (local_0) {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800968_chgoldstatue);
            param_0->unk6C_0 = _subaddieaudioloop_entrypoint_7((u8)param_0->unk6C_0,
                param_0->position, 1, D_8080097C_chgoldstatue,
                *(u32 *)((u8 *)param_0 + 0x70) & 1);
        }
    }
}

int chgoldstatue_entrypoint_0()
{
    return (int)&D_80800990_chgoldstatue;
}
