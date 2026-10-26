#include "common.h"

extern void *D_80800818_chdinofoot;
extern f32 func_8010CD28(Actor *);
extern f32 func_800136E4(f32);
extern void func_80102FDC(Actor *, f32);
extern u8 D_80800860_chdinofoot[];
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern void func_8010D09C(void *, void *, f32);
extern f32 func_800F3780(f32, void *, s32);
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
extern void func_8010D254(f32 *);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800D8FF8(void);
extern void func_800EF368(f32 *, f32);
extern u8 D_80800880_chdinofoot[];
extern u8 D_80800890_chdinofoot[];
extern u8 D_808008A0_chdinofoot[];
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
void func_8080035C_chdinofoot();
int func_80800408_chdinofoot();
s32 func_80800480_chdinofoot();
s32 func_808006BC_chdinofoot();

int chdinofoot_entrypoint_0()
{
  return &D_80800818_chdinofoot;
}

void func_8080000C_chdinofoot(Actor *param_0)
{
    if (_glcutDll_entrypoint_20()) {
        func_80102424(param_0, 5);
        param_0->unk58 = 1.4f;
    }
    _subaddiefade_entrypoint_12(param_0, 0x60, 0x80, 0x60);
    func_80102FDC(param_0, param_0->scale * 4.0f);
}

s32 func_8080055C_chdinofoot();

void func_80800084_chdinofoot(Actor *param_0)
{
    if (func_800F6438(func_800F54E4())) {
        func_8010D09C(func_800F54E4(), &param_0->actorData, 0.79998779296875f);
        *(f32 *)&param_0->actorData[1] = param_0->position[1];
    }
    switch (param_0->unk70_10) {
    case 1:
        if (!func_80800480_chdinofoot(param_0) && !param_0->unk64_20 && func_800D90A4(&param_0->unk58)) {
            func_80102424(param_0, 3);
        }
        break;
    case 2:
        if (func_800D90A4(&param_0->unk58)) {
            _chintrotext_entrypoint_1(0x18B9, 7, 1, 0);
            func_80102424(param_0, 4);
            func_8010A590(param_0);
        }
        break;
    case 3:
        if (param_0->unk64_20 || func_8080055C_chdinofoot(param_0)) {
            func_80102424(param_0, 4);
            func_8010A590(param_0);
        }
        break;
    case 4:
        func_808006BC_chdinofoot(param_0);
        if (func_80101E14(param_0, 0.6f)) {
            func_8010A570(param_0);
        }
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 1);
            param_0->unk58 = 1.399993896484375f;
        }
        break;
    case 5:
        if (func_800D9078(&param_0->unk58)) {
            func_80102424(param_0, 6);
        }
        break;
    case 6:
        func_808006BC_chdinofoot(param_0);
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 5);
            param_0->unk58 = 1.4f;
        }
        break;
    }
    _subaddiefade_entrypoint_1(param_0, (s32)(func_800F3780(func_80101F24(param_0), D_80800860_chdinofoot, 4) * 255.0f));
    _chbadshad_entrypoint_1(param_0, param_0->position, 8.5f);
}

s32 func_808002A8_chdinofoot(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x3F:
        func_8080035C_chdinofoot(param_0, *(Unk80132ED0 **)&param_2);
        break;
    case 0xB:
        param_0->unk64_20 = 0;
        func_800FDC28(0);
        return 3;
    default:
        return 0;
    }
    return 1;
}

s32 func_80800310_chdinofoot(Actor *this, s32 param_1)
{
  s32 local_0;
  local_0 = _subaddiefade_entrypoint_0(this);
  _subaddiefade_entrypoint_1(this, 0xFF);
  func_80101870(this, param_1);
  _subaddiefade_entrypoint_1(this, local_0);
}

void func_8080035C_chdinofoot(param_0, param_1) Actor *param_0; Unk80132ED0 *param_1;
{
    if ((param_1->unk24 >> 22) == 0) {
        if (param_0->unk70_10 == 4 && func_80101F24(param_0) < 0.4f) {
            func_800F7B9C(func_800F54E4(), 0x5A);
            func_8010A570(param_0);
            return;
        }
        func_800F79DC(func_800F54E4(), 0xA, param_0->unk0);
        func_8010A570(param_0);
    }
}

int func_80800408_chdinofoot(param_0) Actor *param_0;
{
    f32 local_0[3];
    if (!func_8010D248()) return 0;
    func_8010D254(local_0);
    if (local_0[2] > 3500.0f || local_0[2] < -4000.0f) return 0;
    return 1;
}

s32 func_80800480_chdinofoot(param_0) Actor *param_0;
{
    s32 local_0;
    f32 local_1[3];
    local_0 = func_800F54E4();
    if (!func_800F6438(local_0) || !func_800F6478(local_0)) return 1;
    if (!func_800DA298(0xC5)) {
        func_800F5A00(local_0, local_1);
        if (local_1[2] < 4500.0f) {
            func_800DA544(0xC5);
            param_0->unk64_20 = 1;
            func_80102424(param_0, 2);
            param_0->unk58 = 21.5f;
            _capod_entrypoint_13(param_0->unk0, 0, 1, 0x10);
            func_800FDC28(1);
        }
        return 1;
    }
    return 0;
}

s32 func_8080055C_chdinofoot(Actor *param_0)
{
    if (func_80800408_chdinofoot(param_0)) {
        param_0->position[0] = *(f32 *)&param_0->actorData[0];
        param_0->position[2] = *(f32 *)&param_0->actorData[2];
        param_0->rotation[1] = func_800136E4(func_8010CD28(param_0) + 180.0f);
        return 1;
    }
    return 0;
}

void func_808005C4_chdinofoot(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];

    if (!param_0->unk64_20 && !_glcutDll_entrypoint_20()) {
        func_800F5A00(func_800F54E4(), local_1);
        local_1[1] = -200.0f;
        func_800EFE50(local_2, (f32 *)param_0->actorData, local_1, 0.5f);
        if (func_800EEB40(param_0->position, local_2) > 10000.0f) {
            func_800EFB24(local_0, local_2, param_0->position);
            func_800EF368(local_0, func_800D8FF8() * 500.0f);
            param_0->position[0] += local_0[0];
            param_0->position[2] += local_0[2];
        }
    }
}

s32 func_808006BC_chdinofoot(param_0) Actor *param_0;
{
    f32 *local_0;

    local_0 = param_0->position;
    _subaddieaudioquick_entrypoint_3(param_0, local_0, D_80800880_chdinofoot, 0.0f);
    if (func_80101F24(param_0) < 0.4f) func_808005C4_chdinofoot(param_0);
    if (func_80101E14(param_0, 0.4f)) {
        _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80800890_chdinofoot);
        func_800BBCB8(local_0, local_0, 1.0f, 6, D_808008A0_chdinofoot);
        func_800E15CC(0, 40.0f, 0.8f);
        func_80018820(0, 3.0f, 0.25f);
        return 1;
    }
    return 0;
}
