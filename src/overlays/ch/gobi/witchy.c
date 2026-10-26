#include "common.h"

extern int D_80800410_chgobiwitchy;
extern u8 D_80800458_chgobiwitchy[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void *_suexpression_entrypoint_7(Actor *, s32, s32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _suexpression_entrypoint_14(void *, f32, f32);
extern void *func_80100094(Actor *, u32);
extern void _capod_entrypoint_22(void);
extern u8 D_80800468_chgobiwitchy[];
extern u8 D_808003C0_chgobiwitchy[];
extern s32 func_8008FB10(f32 *, f32, f32, f32);
extern void _chbadshad_entrypoint_2(Actor *, s32, f32, s32);
extern void _chgobicommon_entrypoint_0(Actor *);
void func_8080024C_chgobiwitchy();

int chgobiwitchy_entrypoint_0()
{
  return (int)&D_80800410_chgobiwitchy;
}

void func_808002DC_chgobiwitchy();

void func_8080000C_chgobiwitchy(Actor *param_0)
{
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(param_0), param_0->unk0, 0);
    _chgobicommon_entrypoint_0(param_0);
    func_8008FB10(param_0->position, 240.0f, 0.0f, 150.0f);
    switch (param_0->unk70_10) {
        case 1:
            func_808002DC_chgobiwitchy(param_0);
            break;
        case 4:
            func_80105834(param_0);
            if (func_80105A5C(param_0)) {
                func_800FFAB0(param_0);
                _capod_entrypoint_14();
                if (_gclevel_entrypoint_3(0x17)) {
                    _glcutDll_entrypoint_6(0x127, 0x47);
                }
            }
            break;
        case 2:
            break;
    }
    _chbadshad_entrypoint_2(param_0, 1, param_0->scale * 2.4f, 0);
}

s32 func_80800104_chgobiwitchy(Actor *param_0, s32 param_1, s32 param_2)
{
    void *local_0;

    switch (param_1) {
    case 0x2E:
        func_8080024C_chgobiwitchy(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800458_chgobiwitchy, param_0->scale);
        break;
    case 0x95:
        local_0 = _suexpression_entrypoint_7(param_0, 1, 0x38);
        _suexpression_entrypoint_12(local_0, 40.0f, 60.0f);
        _suexpression_entrypoint_14(local_0, 1.0f, 1.0f);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808001C8_chgobiwitchy(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
void func_808001E8_chgobiwitchy(u8 *param_0)
{
  if (func_800DA298(0x97) != 0)
  {
    func_800FFAB0(param_0);
    return;
  }
  func_80105A9C(param_0, 0x43FA0000);
  func_80102FDC(param_0, 0x3E800000);
  *((u8 *) (((s8 *) param_0) + 0x95)) = (u8) (((*((u8 *) (((s8 *) param_0) + 0x95))) & 0xFFFFu) | 1);
}

void func_8080024C_chgobiwitchy(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    _capod_entrypoint_22();
    if (param_1 == 0x107B) {
        _suexpression_entrypoint_12(func_80100094(param_0, 1), 0.0f, 0.0f);
        func_80101FDC(param_0, 4);
        _capod_entrypoint_13(param_0->unk0, 0, 1, 0x2031);
    } else func_80101FDC(param_0, 1);
}

void func_808002DC_chgobiwitchy(Actor *param_0)
{
    s32 local_0;

    local_0 = 0;
    if (func_800DA298(0x97)) {
        if (!func_800DB9B0()) {
            func_800F82D4(func_800F54E4(), 0);
            func_800DA524(0x87);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x107B, 0xE, 0, 0x38);
            func_80101FDC(param_0, 3);
            local_0 = 1;
        }
    } else {
        local_0 = _subaddiedialog_entrypoint_8(param_0, param_0->position,
                    D_80800468_chgobiwitchy, D_808003C0_chgobiwitchy, 5);
    }
    if (local_0) {
        _capod_entrypoint_21(param_0->unk0, 0, 0xA, 0);
    }
}
