#include "common.h"

extern int D_80801154_chvolcanobits;
extern int D_8080119C_chvolcanobits;
extern int D_808011E4_chvolcanobits;
extern s32 D_8080122C_chvolcanobits[];
extern void *func_80100094(Actor *, u32);
typedef struct { s16 local_0; s16 local_1; } VolcanoMessage;
typedef struct { s32 local_0; f32 local_1; s32 local_2; } VolcanoTimer;
typedef struct { VolcanoTimer local_0[8]; s32 local_1; f32 local_2; } VolcanoTimers;
extern u8 D_80801274_chvolcanobits[];
typedef struct { u8 pad[0x64]; u32 pad64:11; u32 flag:1; u32 rest:20; } BitsState;
extern void func_800CF494(BitsState *);
extern u8 D_80801288_chvolcanobits[];
extern u8 D_8080129C_chvolcanobits[];
extern u8 D_808012AC_chvolcanobits[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern void func_800BBCB8(f32 *, s32, f32, s32, s32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef struct { u8 pad[0x76]; u16 f76:9; u16 pad76:7; } VolcS;
extern void _subaddiefind_entrypoint_10(VolcS *, s32, s32);
extern void _chswitch_entrypoint_7(VolcS *, s32);
extern void _chswitch_entrypoint_9(VolcS *);
extern Actor *func_80106790();
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern u8 unk76[];
extern u8 _chvolcanobits_entrypoint_4[];
extern f32 D_8080110C_chvolcanobits[][3];
typedef struct { s32 local_0; f32 local_1; f32 local_2; } VolcanoSplashPoint;
typedef struct { VolcanoSplashPoint local_0[8]; u32 local_1; f32 local_2; } VolcanoSplashState;
extern f32 func_800DC178(f32, f32);
typedef struct { s32 unk0; f32 unk4; f32 unk8; } VolcEntry;
extern void func_800CD08C(s32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_80102FDC(Actor *, f32);
extern s32 func_800DC298(f32);
extern s32 func_800EA05C(void);
extern void func_800CF2D4(s32);
extern void *func_800C8A98(void);
extern void func_800C8E54(void *, f32, f32);
extern void func_800F2F60(s32 *, s32 *, f32);
extern s32 D_80801100_chvolcanobits[3];
typedef struct { f32 duration; s32 pad_0; s16 camera; s16 pad_1; } VolcanoSequence;
extern void *func_800E1540(s32);
extern void func_800E13F0(void *, f32);
extern void func_800E1410(void *, f32, f32);
extern void func_800187B4(s32, f32, f32, f32);
extern u8 D_808012EC_chvolcanobits[];
int func_80801040_chvolcanobits();
f32 *func_8080108C_chvolcanobits();
void func_80800914_chvolcanobits();
void func_80800D6C_chvolcanobits();

int chvolcanobits_entrypoint_0()
{
    return &D_80801154_chvolcanobits;
}

int chvolcanobits_entrypoint_1()
{
    return (int)&D_8080119C_chvolcanobits;
}

int *chvolcanobits_entrypoint_2()
{
    return &D_808011E4_chvolcanobits;
}

int chvolcanobits_entrypoint_3()
{
  return (int)D_8080122C_chvolcanobits;
}

void func_80800030_chvolcanobits(Actor *param_0)
{
    s32 local_0[8];
  s32 pad0;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    f32 local_1[3];
    VolcanoSplashState *local_6;

    local_6 = func_80100094(param_0, 0);
    local_2 = _gccubesearch_entrypoint_9(0x154, local_0, 8);
    local_6->local_1 = 0;
    for (local_4 = 0; local_4 < local_2; local_4++) {
            func_800EE88C(local_1, local_0[local_4]);
            local_3 = func_800CBC3C(local_1);
            if (local_3 != -1) {
                local_6->local_0[local_6->local_1].local_2 = local_1[1];
                local_6->local_0[local_6->local_1].local_1 = func_800DC178(3.0f, 5.0f);
                local_6->local_0[local_6->local_1].local_0 = local_3;
                local_6->local_1++;
            }
    }
    local_6->local_2 = 6.4f;
}

void func_80800170_chvolcanobits(Actor *param_0)
{
    VolcanoTimers *local_0;
    s32 local_1;
    VolcanoMessage local_2;
    VolcanoMessage local_3;

    local_0 = (VolcanoTimers *)func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < local_0->local_1; local_1++) {
        if (func_800D9078(&local_0->local_0[local_1].local_1)) {
            local_2.local_0 = local_1;
            local_2.local_1 = 0;
            func_80108B04(param_0, *(s32 *)&local_2);
        }
    }
    _subaddieaudioloop_entrypoint_4(param_0, 0, 1, D_80801274_chvolcanobits);
    switch (func_800EA05C()) {
    case 0x129:
        if (_glcutDll_entrypoint_19(0x70) && func_800D9078(&local_0->local_2)) {
            local_3.local_0 = -1;
            local_3.local_1 = 1;
            func_80108B04(param_0, *(s32 *)&local_3);
        }
        break;
    case 0x133:
        break;
    }
}

s32 func_8080027C_chvolcanobits(Actor *param_0, s32 param_1, s32 param_2)
{
    VolcEntry *local_0;
    s32 local_5;
    f32 local_1[3];
    Actor *local_3;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x3D:
        switch (((s16 *)&param_2)[1]) {
        case 0:
            local_5 = ((s16 *)&param_2)[0];
            func_800CD08C(local_0[local_5].unk0, local_1);
            local_1[1] = local_0[local_5].unk8;
            local_0[local_5].unk4 = func_800DC178(3.0f, 5.0f);
            local_3 = func_80108528(0x425, local_1, 0, &param_0);
            func_800EFA4C((f32 *)&local_3->actorData[4], func_800DC178(-200.0f, 200.0f), func_800DC178(600.0f, 1200.0f), func_800DC178(-200.0f, 200.0f));
            func_80102FDC(local_3, func_800DC178(0.8f, 1.2f));
            local_3->unk54 = (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(100.0f, 200.0f);
            local_3->unk50 = (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(60.0f, 120.0f);
            local_3->unk64_20 = func_800DC298(0.6f);
            local_3->unk58 = func_800DC178(0.8f, 1.2f);
            break;
        case 1:
            func_800EFA4C(local_1, 250.0f, -815.0f, -400.0f);
            local_3 = func_80108528(0x425, local_1, 0, &param_0);
            func_800EFA4C((f32 *)&local_3->actorData[4], 0.0f, 1200.0f, 0.0f);
            func_80102FDC(local_3, func_800DC178(0.8f, 1.2f));
            local_3->unk54 = (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(100.0f, 200.0f);
            local_3->unk50 = (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(60.0f, 120.0f);
            local_3->unk64_20 = 1;
            local_3->unk64_19 = 1;
            local_3->unk58 = 2.0f;
            break;
        }
        break;
    case 0x95:
        if (func_800EA05C() == 0x133) {
            func_800CF2D4(5);
            param_0->unk64_20 = 1;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080061C_chvolcanobits(BitsState *param_0) {
    if (param_0->flag) {
        func_800CF494(param_0);
        ((u8 *)param_0)[0x65] &= ~0x10;
    }
}

void func_8080065C_chvolcanobits(s32 arg0) 
{
}
void func_80800664_chvolcanobits(Actor *param_0)
{
    f32 local_0;
    f32 local_1[3];
    f32 *local_2;

    local_0 = func_800D8FF8();
    param_0->rotation[1] = func_800136E4(param_0->rotation[1] + param_0->unk54 * local_0);
    param_0->rotation[0] = func_800136E4(param_0->rotation[0] + param_0->unk50 * local_0);
    if (param_0->unk70_10 == 1) {
        local_2 = param_0->position;
        if (!func_800BFA1C(local_2) && *(f32 *)&param_0->actorData[5] < 0.0f) {
            func_800FFAB0(param_0);
            return;
        }
        *(f32 *)&param_0->actorData[5] -= local_0 * 800.0f;
        func_80800914_chvolcanobits(param_0);
        if ((func_8010B990(param_0, 0x400007) & 0x20) ||
            (param_0->unk64_20 && func_800D9078(&param_0->unk58))) {
            func_800C8E54(param_0->actorData[0], 400.0f, 1000.0f);
            func_800C8E84(param_0->actorData[0], ((u8 *) D_80801100_chvolcanobits));
            param_0->actorData[0] = _chlightfader_entrypoint_1(param_0->actorData[0], 1.8f, 2);
            func_800BBCB8(local_2, 0, 1.0f, 1, _fxgenlist_entrypoint_2());
            _subaddieaudioquick_entrypoint_2(param_0, local_2,
                param_0->unk64_19 ? D_8080129C_chvolcanobits : D_80801288_chvolcanobits);
            func_800EE7F8(local_1, local_2);
            local_1[1] -= param_0->scale * 10.0f;
            _chexploder_entrypoint_3(param_0, local_1, 0x1C);
            func_80101FDC(param_0, 2);
        }
        if (!func_8001210C(1)) {
            func_800BABB8(func_800B5BE4(0x18), local_2, NULL, 1.0f,
                         D_808012AC_chvolcanobits);
        }
    }
}

void func_8080086C_chvolcanobits(Actor *param_0)
{
  s32 *local_0 = (s32 *) (((char *) param_0) + 0x18);
  if ((*local_0) != 0)
  {
    func_800C8B84(*((s32 *) (((char *) param_0) + 0x18)));
    *((s32 *) (((char *) param_0) + 0x18)) = 0;
  }
}

int func_808008A4_chvolcanobits(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 *local_0;
    if (param_1 == 0x90) {
        local_0 = func_80101080();
        local_0 = func_80106790(local_0);
        _chexploder_entrypoint_6(local_0, 0x44960000, 0x44AF0000);
        _subaddiefade_entrypoint_3(local_0);
        return 1;
    }
    if (param_1 == 0x95) {
        *(s32 *)((char *)param_0 + 0x18) = 0;
        return 1;
    }
    return 0;
}

void func_80800914_chvolcanobits(param_0) Actor *param_0;
{
    s32 local_0[3];
    if (!*(void **)&param_0->actorData[0]) {
        *(void **)&param_0->actorData[0] = func_800C8A98();
        func_800C8E54(*(void **)&param_0->actorData[0], 200.0f, 800.0f);
    }
    func_800C8CB8(*(void **)&param_0->actorData[0], param_0->position);
    func_800F2F60(local_0, D_80801100_chvolcanobits, func_800DC178(0.8f, 1.0f));
    func_800C8E84(*(void **)&param_0->actorData[0], local_0);
}

void func_808009A8_chvolcanobits(VolcS *param_0) {
    u8 *local_0 = func_8080108C_chvolcanobits(param_0);
    _subaddiefind_entrypoint_10(param_0, 0x42A, param_0->f76);
    _chswitch_entrypoint_7(param_0, *(s16 *)(local_0 + 6));
    _chswitch_entrypoint_9(param_0);
}

s32 func_80800A04_chvolcanobits(Actor *param_0, s32 param_1)
{
    s32 local_1;
    s32 local_2;

    switch (param_1) {
        case 7:
            if (param_0->unk74_7 == 0x37) {
                func_800D1000(0x3E, 1, NULL, 1, 0);
            }
            func_8010114C(param_0->unk3C, 0xA, 0);
            break;
        case 31:
            local_1 = param_0->unk74_7 - 0x32;
            func_801015D0(param_0);
            for (local_2 = 0; local_2 < 6; local_2++) {
                func_800DF744(local_2 + 1, local_1 == local_2);
            }
            break;
        default:
            return _chswitch_entrypoint_10(param_0);
    }
    return 1;
}

s32 func_80800AEC_chvolcanobits(s32 param_0){
    func_800EE7F8(func_80100094(param_0, 0), param_0 + 4);
}

void func_80800B20_chvolcanobits(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    Actor *local_2;

    local_0 = func_8080108C_chvolcanobits(param_0);
    switch (param_0->unk70_10) {
        case 1:
        case 3:
            if (--param_0->unk79_4 == 0) func_80103110(param_0, 0);
            break;
        case 2:
            local_1 = func_800D9078(&param_0->unk58);
            func_800EFE50(param_0->position, (f32 *)((u8 *)param_0 + 0x28), (f32 *)param_0->actorData,
                func_800F12D4(param_0->unk58, 0.0f, *(f32 *)local_0, 1.0f, 0.0f));
            if (param_0->unk3C) {
                local_2 = func_80106790(param_0->unk3C);
                local_2->position[1] = param_0->position[1] + param_0->unk54;
            }
            if (local_1) {
                func_800DA544(*(s16 *)(local_0 + 6));
                param_0->unk79_4 = 2;
                func_80101FDC(param_0, 3);
                func_800C2FDC(param_0->unk5F);
                param_0->unk5F = 0;
            } else {
                func_80800D6C_chvolcanobits(param_0);
            }
            break;
    }
    func_80801040_chvolcanobits(param_0);
}

void func_80800EF0_chvolcanobits();

s32 func_80800C5C_chvolcanobits(Actor *param_0, s32 param_1, s32 param_2)
{
    VolcanoSequence *local_0;
    void *local_1;
    if (param_1 == 0xA) {
        local_0 = (VolcanoSequence *)func_8080108C_chvolcanobits(param_0);
        local_1 = func_800E1540(0);
        func_800E1378(local_1);
        func_800E13F0(local_1, 5.0f);
        func_800E1410(local_1, -5.0f, local_0->duration * 0.95f);
        func_800187B4(0, 3.0f, 1.0f, local_0->duration * 0.95f);
        func_80101FDC(param_0, 2);
        func_80103110(param_0, 1);
        param_0->unk58 = local_0->duration;
        if (local_0->camera != -1) _capod_entrypoint_13(param_0->unk0, 0, local_0->camera, 0x10);
        return 1;
    }
    if (param_1 == 0x95) {
        func_80800EF0_chvolcanobits(param_0);
        return 1;
    }
    return 0;
}

void func_80800D6C_chvolcanobits(param_0) Actor *param_0;
{
    void *local_0;
    local_0 = func_80100094(param_0, 0);
    if (_subaddieaudioloop_entrypoint_4(param_0, local_0, 1, D_808012EC_chvolcanobits)) {
        _subaddieaudioloop_entrypoint_1(param_0, (s32)func_800F12D4(param_0->unk58, 0.0f, func_8080108C_chvolcanobits(param_0)[0] * 0.6f, 32767.0f, 22000.0f));
    }
}

void chvolcanobits_entrypoint_4(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    Actor *local_0;
    Vtx *local_1;
    s32 local_2;

    local_0 = func_80106790(param_4);
    local_1 = param_2 + param_3;
    for (; param_2 < local_1; param_2++, param_1++) {
        for (local_2 = 0; local_2 < 3; local_2++) {
            param_2->v.ob[local_2] = param_1->v.ob[local_2] + local_0->position[local_2];
        }
    }
}

void func_80800EF0_chvolcanobits(u8 *param_0) {
    u8 *sp34;
    u8 *sp30;

    sp34 = func_8080108C_chvolcanobits();
    sp30 = NULL;
    _subaddiefind_entrypoint_10(param_0, 0x429, ((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7) + 1);
    func_800EFD24(param_0 + 4);
    func_800EFD24(param_0 + 0x18);
    func_800EFD24(param_0 + 0x28);
    (*(f32 *)((s8 *)(param_0) + (0x2C))) = (f32) ((*(f32 *)((s8 *)(param_0) + (0x2C))) - (f32) (*(s16 *)((s8 *)(sp34) + (4))));
    if ((*(s32 *)((s8 *)(param_0) + (0x3C))) != 0) {
        sp30 = func_80106790((*(s32 *)((s8 *)(param_0) + (0x3C))));
    }
    if (sp30 != NULL) {
        (*(f32 *)((s8 *)(param_0) + (0x54))) = (f32) ((*(f32 *)((s8 *)(sp30) + (8))) - (*(f32 *)((s8 *)(param_0) + (8))));
    }
    if (func_800DA298((*(s16 *)((s8 *)(sp34) + (6)))) != 0) {
        func_800EE7F8(param_0 + 4, param_0 + 0x18);
        func_80101FDC(param_0, 3);
        func_800FFAB0(param_0);
    } else {
        func_800EE7F8(param_0 + 4, param_0 + 0x28);
        func_80101FDC(param_0, 1);
        func_80103110(param_0, 1);
        (*(u8 *)((s8 *)(param_0) + (0x79))) = (u8) (((*(u8 *)((s8 *)(param_0) + (0x79))) & 0xFF0F) | 0x20);
    }
    if (sp30 != NULL) {
        (*(f32 *)((s8 *)(sp30) + (8))) = (f32) ((*(f32 *)((s8 *)(param_0) + (0x54))) + (*(f32 *)((s8 *)(param_0) + (8))));
    }
    (*(s8 *)((s8 *)(param_0) + (0x5F))) = 0;
    func_80801040_chvolcanobits(param_0);
}

int func_80801040_chvolcanobits(param_0) Actor *param_0;
{
  s32 local_0;
  local_0 = func_800BEA88(0);
  if (local_0 != 0)
  {
    _glid_entrypoint_0(local_0 | local_0, ((u32)(*(u16 *)((char *)(param_0) + 0x76)) >> 7) - 0x31, &_chvolcanobits_entrypoint_4, *(s32 *)((char *)(param_0) + 0x0));
  }
}

f32 *func_8080108C_chvolcanobits(param_0) Actor *param_0;
{
    s32 local_0;

    local_0 = param_0->unk74_7 - 0x32;
    return D_8080110C_chvolcanobits[local_0];
}
