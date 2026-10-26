#include "common.h"

#define AF(p, i) (*(f32 *)&(p)->actorData[i])
extern int D_80800B1C_chbadbeehive;
extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern u8 D_80800AEC_chbadbeehive[];
extern u8 D_80800B64_chbadbeehive[];
extern u8 D_80800B74_chbadbeehive[];
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern void func_800C31DC(s32, f32);
extern void func_800C3584(s32, f32, f32);
extern s32 D_80800ABC_chbadbeehive;
extern s32 D_80800AFC_chbadbeehive;
extern s32 D_80800B0C_chbadbeehive;
extern s32 D_80800BE4_chbadbeehive;
extern Actor *func_80106790();
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void _chexploder_entrypoint_15(Actor *, s32, f32);
extern u8 D_8012762C;
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } BHState;
typedef struct { u8 pad_0[0x64]; u32 a : 2; u32 b : 1; u32 c : 29; } BHBits;
typedef struct { s32 a; s32 b; s32 c; } BH12;
typedef struct { u8 pad_0[0x78]; u32 a : 29; u32 f : 1; u32 b : 2; } BH78;
extern u8 D_80800B90_chbadbeehive[];
extern u8 D_80800BD8_chbadbeehive[];
extern f32 func_800F3780(f32, u8 *, s32);
extern f32 func_80102D78(Actor *, u32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void func_801026CC(Actor *, BH12, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, u8 *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, u8 *, f32, f32, f32, f32);
extern s32 func_800DC298(f32);
extern s32 func_800EFFB4();
extern void func_8010D254(u32 *);
extern u8 func_800D9078(f32*);
extern void func_8010C908(Actor *, f32 *);
void func_808008F8_chbadbeehive();
f32 func_8080000C_chbadbeehive();

int chbadbeehive_entrypoint_0()
{
  return (int)&D_80800B1C_chbadbeehive;
}

f32 func_8080000C_chbadbeehive(void)
{
    switch (D_8012762C) {
    case 19:
        return 420.0f;
    case 16:
        return 440.0f;
    case 15:
        return 460.0f;
    case 18:
        return 480.0f;
    case 20:
        return 500.0f;
    case 21:
        return 550.0f;
    case 22:
        return 600.0f;
    case 23:
        return 650.0f;
    case 24:
        return 700.0f;
    case 25:
        return 630.0f;
    case 26:
        return 700.0f;
    default:
        return 0.0f;
    }
}

void func_808000EC_chbadbeehive(Actor *param_0)
{
    f32 *local_0;

    local_0 = func_80100094(param_0, 0);
    _subaddierouteDll_entrypoint_3(param_0, local_0, param_0->position);
    *(f32 *)&param_0->actorData[3] = 0.0f;
    *(f32 *)&param_0->actorData[5] = 0.0f;
    func_800EE7F8(local_0 + 4, param_0->position);
    *(f32 *)&param_0->actorData[6] = func_8080000C_chbadbeehive();
}

void func_80800158_chbadbeehive(Actor *param_0)
{
    s32 local_0 = 0;

    switch (func_801022E4(param_0)) {
        case 0x1C7:
            if (func_80101E14(param_0, 0.48f) || func_80101E14(param_0, 0.98f)) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800AEC_chbadbeehive);
            }
            if (func_80101E4C(param_0, D_80800B74_chbadbeehive)) local_0 = 1;
            break;
        case 0x54:
            if (func_80101E4C(param_0, D_80800B64_chbadbeehive)) local_0 = 1;
            break;
    }
    if (local_0) {
        func_800C3CE8(param_0->unk5F);
        func_800C301C(param_0->unk5F, 0x447);
        func_800C3058(param_0->unk5F, 0x2EE0);
        func_800C31DC(param_0->unk5F, func_80101F24(param_0) + 0.5f);
        func_800C35E8(param_0->unk5F, param_0->position);
        func_800C3584(param_0->unk5F, 300.0f, 1500.0f);
        func_800C330C(param_0->unk5F, 3);
        func_800C3BDC(param_0->unk5F);
    }
}

void func_80800298_chbadbeehive(Actor *param_0)
{
    u8 *local_0;
    f32 local_1;
    f32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800F3780(func_80101F24(param_0), D_80800B90_chbadbeehive, 9);
    if (((BH78 *)param_0)->f) {
        return;
    }
    func_800D9078(&param_0->unk58);
    switch (((BHState *)param_0)->st) {
    case 1:
        if (((BHBits *)param_0)->b) {
            if (0.1f < _subaddiejoy_entrypoint_9(param_0, 0, 0)) {
                func_808008F8_chbadbeehive(param_0, 2);
            }
        } else if (func_80800990_chbadbeehive(param_0)) {
            func_808008F8_chbadbeehive(param_0, 2);
        }
        break;
    case 2:
        func_801026CC(param_0, *(BH12 *)D_80800BD8_chbadbeehive, AF(param_0, 3));
        func_8010D254(param_0->actorData);
        if (((BHBits *)param_0)->b) {
            local_2 = _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3);
            AF(param_0, 3) = AF(param_0, 5);
            func_80102BF8(param_0, 0.2f, 8.0f, 500.0f);
            func_8010C3A8(param_0, 0x205015, local_2 * local_1);
            if (_subaddiejoy_entrypoint_9(param_0, 0, 0) == 0.0f) {
                func_808008F8_chbadbeehive(param_0, 1);
            }
        } else {
            if (_subaddierouteDll_entrypoint_4(param_0)) {
                param_0->unk54 = func_80102D78(param_0, param_0->actorData);
                _subaddierouteDll_entrypoint_7(param_0, local_0, param_0->rotation[1], param_0->unk54, 200.0f, 0x5800);
                *(s32 *)(local_0 + 0xC) = *(u16 *)(local_0 + 6);
            }
            _subaddierouteDll_entrypoint_5(param_0, local_0, *(f32 *)(local_0 + 0xC), 0.15f, 8.0f, 200.0f);
            AF(param_0, 3) = func_800F15F8(AF(param_0, 3), AF(param_0, 5), func_800D8FF8() * 400.0f);
            func_8010C3A8(param_0, 0x305115, local_1);
            if (_subaddierouteDll_entrypoint_4(param_0) && func_800DC298(0.2f) && (!func_8010C9B0(param_0->position, 1000) || !func_8010C500(param_0))) {
                func_808008F8_chbadbeehive(param_0, 3);
            }
        }
        break;
    case 3:
        func_801026CC(param_0, *(BH12 *)D_80800BD8_chbadbeehive, AF(param_0, 3));
        if (func_80800990_chbadbeehive(param_0)) {
            func_808008F8_chbadbeehive(param_0, 2);
        }
        if (_subaddierouteDll_entrypoint_4(param_0)) {
            param_0->unk54 = func_80102D78(param_0, param_0->actorData);
            _subaddierouteDll_entrypoint_7(param_0, local_0, param_0->rotation[1], param_0->unk54, 200.0f, 0x5800);
            *(s32 *)(local_0 + 0xC) = *(u16 *)(local_0 + 6);
        }
        _subaddierouteDll_entrypoint_5(param_0, local_0, *(f32 *)(local_0 + 0xC), 0.15f, 8.0f, 200.0f);
        AF(param_0, 3) = func_800F15F8(AF(param_0, 3), AF(param_0, 5), func_800D8FF8() * 400.0f);
        func_8010C3A8(param_0, 0x305115, local_1);
        if (_subaddierouteDll_entrypoint_4(param_0) && func_800DC298(0.2f) && func_800EFFB4(param_0->position, 0x42C80000, local_0 + 0x10)) {
            func_808008F8_chbadbeehive(param_0, 1);
        }
        break;
    }
    if (((BHState *)param_0)->st < 4) {
        func_8010C908(param_0, param_0->position);
    }
    func_80800158_chbadbeehive(param_0);
}

s32 func_8080070C_chbadbeehive(Actor *param_0, s32 param_1, Actor **param_2)
{
    f32 local_0[3];
    Actor *local_1;

    switch (param_1) {
    case 0x95:
        param_0->unk5F = func_800C2E04();
        _subaddierouteDll_entrypoint_1(param_0);
        break;
    case 0x40:
        func_800EE88C(local_0, (*param_2)->position);
        local_0[1] = param_0->position[1];
        _chexploder_entrypoint_3(param_0, local_0, 0x20);
        break;
    case 0x90:
        local_1 = func_80106790(func_80101080());
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800AFC_chbadbeehive);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800B0C_chbadbeehive);
        func_800BBCB8(param_0->position, NULL, param_0->scale, 1, &D_80800BE4_chbadbeehive);
        if (!func_80107070(param_0, 3)) func_800FFAB0(param_0);
        _chexploder_entrypoint_15(local_1, 2, 1.0f);
        _chexploder_entrypoint_9(local_1, 3, 2);
        break;
    case 1:
        func_808008F8_chbadbeehive(param_0, 2);
        break;
    case 2:
        if (!_subaddieDll_entrypoint_3(param_0)) {
            if (!func_80107070(param_0, 1)) _subaddiefade_entrypoint_3(param_0);
        } else {
            func_808008F8_chbadbeehive(param_0, 3);
        }
        break;
    case 0x1F:
        func_801015D0(param_0);
        func_800DF744(3, 2);
        break;
    case 0x38:
        func_80101074(&D_80800ABC_chbadbeehive);
        return 4;
    default:
        return 0;
    }
    return 1;
}

void func_808008F0_chbadbeehive(s32 arg0) 
{
}
void func_808008F8_chbadbeehive(param_0, param_1) u8 *param_0; s32 param_1; {
    s32 local_0;

    local_0 = func_80100094(param_0, 0);
    func_80102424(param_0, param_1);
    switch (param_1) {                                 
    case 2:
        (*(f32 *)((s8 *)(param_0) + (0x2C))) = (f32) (*(f32 *)((s8 *)(param_0) + (0x30)));
        return;
    case 3:
        func_800EE7F8(param_0 + 0x18, local_0 + 0x10);
        (*(f32 *)((s8 *)(param_0) + (0x2C))) = (f32) ((*(f32 *)((s8 *)(param_0) + (0x2C))) * 0.5f);
        
    case 1:
        return;
    }
}

int func_80800990_chbadbeehive(f32 param_0[3])
{
  f32 local_0;
  if (param_0[0x16] > 0.0f)
  {
    return 0;
  }
  if (_subaddierouteDll_entrypoint_4(param_0) && func_8010C9B0(&param_0[1], 1000) != 0 && _suchase_entrypoint_1(param_0) != 0 && func_8010C500(param_0) != 0)
  {
    return 1;
  }
  return 0;
}
