#include "common.h"

extern int D_80800648_chloggo;
extern int D_80800690_chloggo;
extern f32 * _gccubesearch_entrypoint_0(s32, Actor *);
extern void func_800EE88C(f32 *, f32 *);
extern s32 D_80800610_chloggo;
extern s32 D_808006D8_chloggo;
typedef struct { u8 pad[0x94]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS148;
typedef union { s32 local_0; s16 local_1; Unk80132ED0 *local_2; } Mass45LoggoEventArgs;
extern u8 D_808006E8_chloggo[];
extern u8 D_808005E0_chloggo[];
extern int func_800F54E4(void);
extern void func_800EE7F8(f32 *param_0, s32 *param_1);
extern void func_800EF1B8(f32 *param_0, f32 param_1, u32 param_2);
extern int func_800F77E8(s32 param_0, f32 *param_1);
extern s32 func_800F64A4(s32 param_0, s32 param_1);
extern void _subaddiedialog_entrypoint_11(s32 param_0, s32 param_1, s32 param_2, s32 *param_3, s32 param_4);
extern void func_80102424(s32 param_0, s32 param_1);
extern void func_8010A570(s32 param_0);
extern void _capod_entrypoint_13(s32 param_0, s32 param_1, s32 param_2, s32 param_3);
extern int D_808006F8_chloggo;
extern int D_80800740_chloggo;
extern int D_80800710_chloggo;
extern int D_80800728_chloggo;
extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
void func_80800398_chloggo();
int func_80800460_chloggo();

void* chloggo_entrypoint_0()
{
    return &D_80800648_chloggo;
}

int chloggo_entrypoint_1()
{
    return (int)&D_80800690_chloggo;
}

void func_80800018_chloggo(Actor *param_0)
{
    func_800EE88C((f32 *)param_0->actorData, _gccubesearch_entrypoint_0(0x201, param_0));
    if (_glcutDll_entrypoint_20()) func_80102424(param_0, 4);
    else if (func_800D0A9C(0x10, 4)) func_8010A570(param_0);
    else func_8010A5B0(param_0, func_800DA298(0x169));
}

void func_808000AC_chloggo(u8 *param_0) {
    u32 local_0;

    local_0 = (u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x72)))) >> 0xA;
    switch (local_0) {                              
    case 1:
        func_80800460_chloggo(param_0);
        if (func_800D0A9C(0x10, 4) != 0) {
            _subaddiedialog_entrypoint_8(param_0, param_0 + 4, &D_808006D8_chloggo, &D_80800610_chloggo, 2);
        } else {
            _subaddiedialog_entrypoint_8(param_0, param_0 + 4, &D_808006D8_chloggo, ((s32 *) D_808005E0_chloggo), 6);
        }
        break;
    case 2: ;
    case 4:
        func_80800460_chloggo(param_0);
        break;
    case 3:
        if (func_800F52B8(func_800F54E4(), (*(s32 *)((s8 *)(param_0) + (0)))) != 0xB) {
            func_80800398_chloggo(param_0);
        }
        break;
    }
    (*(u8 *)((s8 *)(param_0) + (0x94))) = (u8) ((*(u8 *)((s8 *)(param_0) + (0x94))) & 0xFFBF);
}

s32 func_808001B8_chloggo(Actor *param_0, s32 param_1, Mass45LoggoEventArgs param_2)
{
    switch (param_1) {
    case 0x2E:
        switch ((*(s16 *)&param_2)) {
        case 0x1343:
        case 0x1380:
            func_800D1000(0x10, 4, param_0->actorData, 1, 0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808006E8_chloggo);
            _capod_entrypoint_14();
            _capod_entrypoint_13(param_0->unk0, 0, 6, 0x2030);
            break;
        case 0x1367:
            _capod_entrypoint_14();
            func_80102424(param_0, 1);
            break;
        default:
            if (_subaddiedialog_entrypoint_9(param_0, (*(s16 *)&param_2), D_808005E0_chloggo, 6) == 1) {
                func_8010A590(param_0);
            }
            func_80102424(param_0, 1);
            break;
        }
        return 1;
    case 0x3E:
        if (*(u16 *)((u8 *)(*(Unk80132ED0 * *)&param_2) + 0x18) & 1) return 0;
        if (func_800F52B8((u32)*(u16 *)((u8 *)(*(Unk80132ED0 * *)&param_2) + 0x1A) >> 5, param_0->unk0) == 11 &&
            param_0->unk70_10 != 3) func_80102424(param_0, 3);
        break;
    case 0x40:
        func_80800398_chloggo(param_0);
        return 1;
    case 0xB:
        if ((*(s32 *)&param_2) == 6) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1367, 6, param_0->position, 0xAD);
        }
        return 3;
    case 0x91:
        ((BitS148 *)(param_0))->b6 = 1;
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800398_chloggo(param_0) u8 *param_0;
{
    f32 local_34[3];
    s32 local_0;
    s32 local_2C;

    local_2C = func_800F54E4();
    func_800EE7F8(local_34, param_0 + 4);
    func_800EF1B8(local_34, *(f32 *)((char *)param_0 + 0x48) - 40.0f, 0x43480000);
    func_800F77E8(local_2C, local_34);
    if (func_800F64A4(local_2C, 0x201) != 0)
    {
        local_0 = 0x1343;
    }
    else
    {
        local_0 = 0x1380;
    }
    _subaddiedialog_entrypoint_11(*(s32 *)param_0, local_0, 6, param_0 + 4, 0xAD);
    func_80102424(param_0, 2);
    func_8010A570(param_0);
    _capod_entrypoint_13(*(s32 *)param_0, 0, 3, 0x30);
}

int func_80800460_chloggo(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_808006F8_chloggo, 0x3DB851EC);
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_80800740_chloggo, 0x3E23D70A);
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_80800710_chloggo, 0x3E6147AE);
  _subaddieaudioquick_entrypoint_3(local_0, local_0 + 4, &D_80800728_chloggo, 0x3F19999A);
}

s32 func_808004F8_chloggo(s32 param_0){
    if(_glcutDll_entrypoint_20())
        func_800FFAB0(param_0);
}

s32 func_80800528_chloggo(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];

    switch (param_1) {
    case 0x40:
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], 0xC3480000);
        _chexploder_entrypoint_3(param_0, local_0, 0xF);
        func_800DA544(0x181);
        break;
    case 0x90:
        _chexploder_entrypoint_13(func_80106790(func_80101080()), 1);
        break;
    default:
        return 0;
    }
    return 1;
}
