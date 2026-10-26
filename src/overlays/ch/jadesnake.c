#include "common.h"

extern void func_8010A85C(Actor *, s32);
extern void func_80102424(Actor *, s32);
extern s32 D_80800938_chjadesnake;
extern void func_800D1000(s32, s32, f32 *, s32, Unk80132ED0 *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern int func_800F54E4(void);
extern int func_800F651C(s32);
extern int func_800F6C5C(s32);
extern int func_800F72DC(s32);
extern int func_800F56AC(s32);
extern int func_800F6478(s32);
typedef struct { s16 a, b; } S16Pair;
typedef union JadeSnakeEvent { s32 local_0; s16 local_1[2]; } JadeSnakeEvent;
extern Actor *func_80106790(Unk80132ED0 *);
extern Unk80132ED0 *func_80101080(void);
extern f32 D_808009E4_chjadesnake[];
extern void _gcdialogcamera_entrypoint_3(f32 *, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern int D_808009F4_chjadesnake;
extern u8 D_80800910_chjadesnake[];
extern u8 D_80800920_chjadesnake[];
extern u8 D_8080092C_chjadesnake[];
extern u8 D_80800948_chjadesnake[];
extern u8 D_80800958_chjadesnake[];
extern u8 D_80800964_chjadesnake[];
extern f32 D_808009C0_chjadesnake[];
extern f32 D_808009DC_chjadesnake[];
extern s32 func_800D0B68(u32, u32);
extern s32 func_800D0A9C(u32, u32);
extern s32 func_800D0634(u32, u32);
extern void func_8010D254(f32 *);
extern s32 func_80101E4C(Actor *, f32 *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_80101DDC(Actor *);
extern f32 func_80101F24(Actor *);
extern void func_80101EE4(Actor *, f32);
extern void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, void *, f32 *);
extern s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, void *);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_80090734(s32, f32 *);
extern void func_80090708(s32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);

void func_80800000_chjadesnake(Actor *param_0)
{
    func_8010A85C(param_0, 2);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(param_0, 9);
        func_8010A85C(param_0, 1);
    }
}

void func_80800048_chjadesnake(Actor *param_0) {
    func_800D1000(0xA, 1, (f32 *)&param_0->actorData[4], 3, param_0->unk0);
    _subaddieaudioquick_entrypoint_2(param_0, (f32 *)&param_0->actorData[4], &D_80800938_chjadesnake);
}

int func_8080009C_chjadesnake(Actor *param_0)
{
    s32 local_4;
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_5;
    s32 local_6;

    local_4 = func_800F54E4();
    local_0 = func_800F651C(local_4);
    local_1 = func_800F6C5C(local_4);
    local_2 = func_800F72DC(local_4);
    local_3 = func_800F56AC(local_4) == 0x10;
    local_5 = func_800F6478(local_4);
    local_6 = local_5 != 0;
    if (!local_3) return 0;
    return local_5 && (local_2 || (local_1 && !local_0));
}

void func_80800150_chjadesnake(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;
    s32 local_2;
    s32 local_3;
    f32 local_4;
    f32 local_5[3];
    Actor *local_6;

    local_1 = func_800D0B68(10, 1);
    local_2 = func_800D0A9C(10, 1);
    func_8010D254(local_0);
    switch (param_0->unk70_10) {
    case 1:
        if (param_0->unk7C_12 && !local_1 && !local_2) {
            func_800D1000(10, 1, (f32 *)&param_0->actorData[0], 3, param_0->unk0);
        }
        local_3 = func_80101E4C(param_0, D_808009C0_chjadesnake);
        if (local_3) {
            func_800C4B7C(local_3 & 1 ? 0x5C6 : 0x5C7);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800964_chjadesnake);
        }
        if (!local_1 && local_2 && func_8080009C_chjadesnake(param_0)) {
            _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80800910_chjadesnake);
            func_80090734(2, param_0->position);
            func_8010A85C(param_0, 1);
            func_80102424(param_0, 2);
            if (!func_800DA9E4(0x677, 1)) {
                param_0->unk64_20 = 1;
                _capod_entrypoint_13(param_0->unk0, 0, 2, 0x10);
            } else {
                param_0->unk64_20 = 0;
            }
        }
        break;
    case 2:
        if (local_1) {
            func_8010A85C(param_0, 2);
            func_80102424(param_0, 1);
            func_80090708(0);
        }
        if (func_80101E14(param_0, 0.73f)) {
            func_800D119C(10, 1);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080092C_chjadesnake);
        }
        if (func_80101DDC(param_0)) {
            if (func_800DA298(0x434)) {
                func_80102424(param_0, 3);
                func_80090708(0);
            } else {
                func_800DA544(0x434);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0xF3C, 0xC, param_0->position, 0x46);
                func_80102424(param_0, 5);
            }
        }
        break;
    case 6:
        _capod_entrypoint_14();
        func_80090708(0);
        func_80102424(param_0, 3);
        break;
    case 3:
        local_4 = func_80101F24(param_0);
        func_8010D254(local_5);
        if (func_800F56AC(func_800F54E4()) != 0x10 && local_5[1] < 1160.0f) {
            func_80102424(param_0, 4);
            if (param_0->unk64_20) {
                _capod_entrypoint_13(param_0->unk0, 0, 0, 0x10);
            }
        }
        if (local_4 > 0.13f && local_4 < 0.64f) {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800948_chjadesnake);
        }
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80800958_chjadesnake, D_808009DC_chjadesnake);
        break;
    case 4:
        if (func_80101E14(param_0, 0.18f) && !local_2) {
            if (func_800DA298(0x435)) {
                func_80800048_chjadesnake(param_0);
            } else {
                func_800DA544(0x435);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0xF3D, 0xC, param_0->position, 0x46);
                func_80102424(param_0, 7);
            }
        }
        if (func_80101DDC(param_0)) {
            if (!func_800DA298(0x435)) {
                func_80102424(param_0, 7);
            } else {
                func_8010A85C(param_0, 2);
                func_80102424(param_0, 1);
            }
        }
        if (!local_1 && local_2 && func_8080009C_chjadesnake(param_0)) {
            _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80800910_chjadesnake);
            func_80090734(2, param_0->position);
            func_8010A85C(param_0, 1);
            func_80102424(param_0, 2);
            func_80101EE4(param_0, 0.57f);
        }
        break;
    case 7:
        if (!local_2) {
            func_80800048_chjadesnake(param_0);
        }
        break;
    case 8:
        if (func_80101DDC(param_0)) {
            if (local_2) {
                func_8010A85C(param_0, 2);
                func_80102424(param_0, 1);
            } else {
                func_80800048_chjadesnake(param_0);
                func_80090708(0);
                func_80102424(param_0, 4);
            }
        }
        break;
    }
    if (param_0->unk6C_0 && func_800D0634(10, 1)) {
        local_6 = func_80106790((Unk80132ED0 *)func_800D0634(10, 1));
        func_800EF04C(local_6->position, (f32 *)&local_6->actorData[4]);
        param_0->unk6C_0--;
        if (param_0->unk6C_0 == 2) {
            _subaddieaudioquick_entrypoint_2(local_6, local_6->position, D_80800920_chjadesnake);
        } else if (param_0->unk6C_0 == 0) {
            func_800EE7F8(local_6->position, (f32 *)&param_0->actorData[0]);
            func_80102FE8(local_6, 1);
            func_80103014(local_6);
        }
    }
}

void func_80800728_chjadesnake(param_0, param_1, param_2) s32 param_0; s32 param_1; S16Pair param_2; {
    if (param_1 != 0xF3C) {
        if (param_1 == 0xF3D) {
            func_80102424(param_0, 8);
        }
    } else {
        func_80102424(param_0, 6);
    }
}

int func_80800770_chjadesnake(Actor *param_0)
{
  func_80101870();
  if (param_0->unk7C_12) {
    func_800DBEFC(func_80104130(), 4, (u8 *)param_0 + 0x18);
    func_800DBEFC(func_80104130(), 5, (u8 *)param_0 + 0x28);
  }
}

s32 func_808007DC_chjadesnake(Actor *param_0, s32 param_1, JadeSnakeEvent param_2)
{
    Actor *local_0;

    if (1) {}
    if (1) {}
    if (1) {}
    switch (param_1) {
    case 13:
        if (param_0->unk70_10 != 1) {
            local_0 = func_80106790(func_80101080());
            func_800EFB24((f32 *)&local_0->actorData[4], (f32 *)&param_0->actorData[0], (f32 *)&param_0->actorData[4]);
            func_800EF334((f32 *)&local_0->actorData[4], 1.0f / 7.0f);
            param_0->unk6C_0 = 7;
            func_80102FE8(local_0, 0);
        }
        break;
    case 0x2E:
        func_80800728_chjadesnake(param_0, param_2.local_1[0], param_2.local_1[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808009E4_chjadesnake, param_0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}

int chjadesnake_entrypoint_0()
{
    return (int)&D_808009F4_chjadesnake;
}
