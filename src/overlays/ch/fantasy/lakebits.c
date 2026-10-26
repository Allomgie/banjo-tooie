#include "common.h"

extern Actor *func_80106790();
extern s32 D_80800920_chfantasylakebits;
extern s32 D_80800928_chfantasylakebits;
extern s32 D_80800934_chfantasylakebits;
extern s32 D_80800940_chfantasylakebits;
extern s32 D_80800980_chfantasylakebits;
extern s32 D_808009B8_chfantasylakebits;
extern s32 D_808009C4_chfantasylakebits;
extern s32 D_808009D0_chfantasylakebits;
extern s32 D_808009DC_chfantasylakebits;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, void *, void *, f32);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern void func_800D91EC(f32 *, f32);
extern void func_800D90A4();
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern void _subaddieaudioloop_entrypoint_4(Actor *, void *, s32, void *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800DF500(f32, f32, f32);
extern int D_80800A30_chfantasylakebits;
extern s32 D_80800A78_chfantasylakebits;
extern s32 D_80800AB4_chfantasylakebits;
extern s32 D_80800ADC_chfantasylakebits;
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern int D_80800AF0_chfantasylakebits;
extern f32 func_800F5628(void *);
extern void _chfantasylakebits_entrypoint_0(void);
void func_80800300_chfantasylakebits();
void func_80800344_chfantasylakebits();

void chfantasylakebits_entrypoint_0(void *param_0, Vtx *param_1, Vtx *param_2,
                                  s32 param_3, Unk80132ED0 *param_4)
{
    Actor *local_0;
    Vtx *local_1;
    local_0 = func_80106790(param_4);
    local_1 = param_2 + param_3;
    for (; param_2 < local_1; param_2++, param_1++) {
        param_2->v.cn[0] = 0xFF;
        param_2->v.cn[1] = 0xFF;
        param_2->v.cn[2] = 0;
        param_2->v.ob[1] = param_1->v.ob[1] + local_0->actorData[3];
    }
}

void func_8080007C_chfantasylakebits(Actor *param_0)
{
    s16 local_0;

    switch ((u32)*(u16 *)((u8 *)param_0 + 0x72) >> 10) {
    case 2:
        if (!func_800DB9B0()) {
            _capod_entrypoint_13(param_0->unk0, 0, 0x23, 0x30);
        }
        func_800D91EC(&param_0->unk58, 12.0f);
        func_80800300_chfantasylakebits(param_0, (s16)func_800F10B4(param_0->unk58, 0.0f, 12.0f, 0, -3200.0f));
        _subaddieaudioloop_entrypoint_4(param_0, &D_80800934_chfantasylakebits, 1, &D_80800920_chfantasylakebits);
        break;
    case 3:
        if (param_0->unk58 < 6.0f) {
            func_800BBCB8(&D_80800934_chfantasylakebits, &D_80800934_chfantasylakebits, 1.0f, 2, &D_80800940_chfantasylakebits);
        }
        func_800D91EC(&param_0->unk58, 12.0f);
        local_0 = func_800F10B4(param_0->unk58, 0.0f, 12.0f, 0, -3200.0f);
        _subaddieaudioloop_entrypoint_4(param_0, &D_80800934_chfantasylakebits, 1, &D_80800920_chfantasylakebits);
        func_80800300_chfantasylakebits(param_0, local_0);
        break;
    case 4:
        func_800BBCB8(&D_808009B8_chfantasylakebits, 0, 1.0f, 2, &D_80800980_chfantasylakebits);
        func_800D90A4((f32 *)((u8 *)param_0 + 0x34));
        func_800EFE50(param_0->position, &D_808009C4_chfantasylakebits, &D_808009D0_chfantasylakebits, func_800F10B4(*(f32 *)((u8 *)param_0 + 0x34), 5.0f, 0.0f, 0.0f, 1.0f));
        param_0->unk54 = func_800F10B4(*(f32 *)((u8 *)param_0 + 0x34), 5.0f, 0.0f, 1.0f, 2.0f);
        _subaddieaudioloop_entrypoint_4(param_0, &D_80800934_chfantasylakebits, 1, &D_80800928_chfantasylakebits);
        _subaddieaudioloop_entrypoint_0(param_0, 1.0f);
        if (*(f32 *)((u8 *)param_0 + 0x34) > 2.0f) {
            func_800BBCB8(&D_808009B8_chfantasylakebits, 0, 1.0f, 1, &D_808009DC_chfantasylakebits);
        }
        func_800F8418(func_800F54E4(), (f32 *)((u8 *)param_0 + 0x28));
        break;
    }
}

void func_80800300_chfantasylakebits(param_0, param_1) s32 param_0; s16 param_1;
{
  s32 local_0;
  local_0 = func_800BEA88(1);
  local_0 = _idworld_entrypoint_4(local_0, 1);
  if (local_0 != 0)
  {
    _idwibble_entrypoint_5(local_0, param_1);
  }
}

void func_80800344_chfantasylakebits(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    s32 local_2;
    s32 local_1;

    switch (param_1) {
    case 1:
        local_0 = func_800BEA88(1);
        param_0->unk58 = 0.0f;
        func_800BF744(1, 1);
        *(s32 *)((u8 *)param_0 + 0x24) = 0;
        _idworldmake_entrypoint_1(local_0, 0x654, 1, 1);
        _glid_entrypoint_0(local_0, 1, _chfantasylakebits_entrypoint_0, param_0->unk0);
        if (func_800EA05C() == 0x13A) {
            local_2 = func_800BEA88(0);
            *(s32 *)((u8 *)param_0 + 0x24) = 0;
            _idworldmake_entrypoint_1(local_2, 0x59B, 2, 1);
        }
        param_0->unk64_16 = 0;
        func_80103110(param_0, 0);
        break;
    case 2:
        func_800F9C38();
        func_80103110(param_0, 1);
        param_0->unk58 = 0.0f;
        _subaddieDll_entrypoint_0(param_0);
        param_0->unk54 = 1.0f;
        func_80103140(param_0, 0x8DE, param_0->unk0->unk16);
        break;
    case 3:
        func_8010A800(param_0, 2);
        func_800F5A00(func_800F54E4(), (f32 *)((u8 *)param_0 + 0x28));
        *(f32 *)((u8 *)param_0 + 0x2C) = func_800F5628(func_800F54E4());
        break;
    case 4:
        func_800BF744(1, 0);
        param_0->unk64_16 = 1;
        *(f32 *)((u8 *)param_0 + 0x34) = 5.0f;
        _subaddieaudioloop_entrypoint_2(param_0);
        break;
    case 5:
        local_1 = func_800BEA88(1);
        func_800BF744(1, 0);
        *(s32 *)((u8 *)param_0 + 0x24) = -3200;
        _glid_entrypoint_0(local_1, 1, _chfantasylakebits_entrypoint_0, param_0->unk0);
        _idworldmake_entrypoint_1(local_1, 0x654, 1, 1);
        func_800DA544(0x327);
        func_800DA524(0x9FC);
        param_0->unk64_16 = 0;
        _subaddieaudioloop_entrypoint_2(param_0);
        func_800FFAB0(param_0);
        break;
    }
    func_80101FDC(param_0, param_1);
}

int func_80800570_chfantasylakebits(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    switch (param_1) {
    case 0xB:
        if (param_2 == 0x23) {
            _capod_entrypoint_14();
            func_80800344_chfantasylakebits(param_0, 5);
            _glcutDll_entrypoint_6(0x112, 0x36);
            return 4;
        }
        return 3;
    case 0xC:
        if (param_0->unk70_10 == 2) func_80800344_chfantasylakebits(param_0, 3);
        else if (param_0->unk70_10 == 3) func_80800344_chfantasylakebits(param_0, 4);
        return 3;
    case 0x36:
        func_80800344_chfantasylakebits(param_0, 2);
        return 1;
    case 0x1F:
        if (*(u16 *)((u8 *)param_0 + 0x64) & 1) {
            func_801015D0(param_0);
            func_800E3980(local_0);
            param_0->rotation[1] = func_800F1DF4(param_0->position, local_0);
            func_800DF500(*(f32 *)((u8 *)param_0 + 0x54), 4.0f, *(f32 *)((u8 *)param_0 + 0x54));
        }
        return 1;
    case 0x95:
        if (func_800DA298(0x327)) func_80800344_chfantasylakebits(param_0, 5);
        else func_80800344_chfantasylakebits(param_0, 1);
        return 1;
    default: return 0;
    }
}

int chfantasylakebits_entrypoint_1()
{
    return (int)&D_80800A30_chfantasylakebits;
}

int func_808006F4_chfantasylakebits(s32 param_0[3])
{
  if (!func_800DA298(0x327) && !func_800DA298(0x9FC))
  {
    return;
  }
  func_800FFA88(param_0[0]);
}

s32 func_8080073C_chfantasylakebits(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    Actor *local_1;

    switch (param_1) {
    case 0x40:
        if (func_8008FCC8(param_0->unk0) == 20) {
            local_0 = _fxairbub_entrypoint_1((param_0->position), 200.0f, param_0->position[1] + 500.0f, 3.0f);
            func_800BA930(local_0, -60, -250, -60, 60, 0, 60);
            func_800BA22C(local_0, 10);
            func_800BBCB8((param_0->position), (param_0->position), param_0->scale, 3, &D_80800A78_chfantasylakebits);
            func_800BBCB8((param_0->position), (param_0->position), param_0->scale, 8, &D_80800AB4_chfantasylakebits);
            func_800C4AF0((param_0->position), &D_80800ADC_chfantasylakebits);
            func_80101180(0x415, 0x36, 0);
            _chskeletonexplode_entrypoint_7(param_0, (param_0->position));
            func_800DA544(0x9FC);
            return 1;
        } else {}
        return 0;
    case 0x1F:
        func_801015D0(param_0);
        func_800DF744(1, 1);
        func_800DF744(2, 1);
        return 1;
    case 0xF:
        local_1 = (Actor *)func_80106790(func_80101080());
        _chskeletonexplode_entrypoint_3(local_1, 1, 2);
        _chskeletonexplode_entrypoint_3(local_1, 2, 1);
        _chskeletonexplode_entrypoint_4(local_1, 1);
        func_800FFA88(param_0->unk0);
        return 1;
    default:
        return 0;
    }
}

int chfantasylakebits_entrypoint_2()
{
    return (int)&D_80800AF0_chfantasylakebits;
}
