#include "ch/cauldronentrydoor.h"

extern void *func_80100094(Actor *, s32);
extern int D_80800550_chcauldronentrydoor;
extern u8 D_80800520_chcauldronentrydoor[];
extern s32 func_800D9078(f32 *);
extern s32 func_800DC298(f32);
typedef union { s32 word; void *pointer; } CauldronEntryDoorPayload;
extern f32 func_800EC75C(s32, f32 *);
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);
extern u8 D_80800534_chcauldronentrydoor[];
extern u8 D_80800540_chcauldronentrydoor[];
extern void _chcauldronentrydoor_entrypoint_0(void);
extern s32 func_800E15CC(s32, f32, f32);
extern void func_800C9DE4(f32, void (*)(void), s32);

void func_80800000_chcauldronentrydoor(s32 param_0) {
    u8 *local_0;

    local_0 = func_80100094(param_0, 1);
    if (_chdoormake_entrypoint_4(param_0, 1, 0x58E) != 0) {
        _chdoormake_entrypoint_5(param_0, 0x3F800000);
        _chdoormake_entrypoint_6(param_0, 0x40000000);
        _chdoormake_entrypoint_8(param_0, 0xB);
        _chdoormake_entrypoint_9(param_0, 0, 0x56, 0x14);
    }
    func_8010A800(param_0, 0);
    func_80104004(param_0, local_0, local_0 + 0xC);
    (*(f32 *)((s8 *)(local_0) + (0x14))) = (f32) ((*(f32 *)((s8 *)(local_0) + (8))) + 40.0f);
    if (_glcutDll_entrypoint_19(0x5B) != 0) {
        func_800FFAB0(param_0);
    }
}

void func_808000C8_chcauldronentrydoor(Actor *param_0)
{
    u8 *local_0;
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800520_chcauldronentrydoor);
    if (func_800D9078((f32 *)&param_0->actorData[4])) func_8010A590(param_0);
    if (param_0->unk7C_12 && func_800DA298(0x436) && func_800DC298(0.2f)) {
        local_0 = func_80100094(param_0, 1);
        _chelectricfence_entrypoint_2(param_0, local_0, local_0 + 0xC);
    }
    _chdoor_entrypoint_0(param_0);
}

s32 func_80800168_chcauldronentrydoor(Actor *param_0, s32 param_1, CauldronEntryDoorPayload param_2)
{
    s32 local_1;
    f32 local_0[3];
    switch (param_1) {
    case 7:
        func_800FC6B0(0xE);
        return _chdoor_entrypoint_1(param_0, param_1, param_2.word);
    case 0x3F:
        local_1 = param_2.word;
        func_800EC75C(local_1, local_0);
        _chelectricfence_entrypoint_1(param_0, local_0);
        func_8010A570(param_0);
        *(f32 *)(param_0->actorData + 4) = 0.2f;
        return 1;
    default:
        return 0;
    }
}

void func_808001FC_chcauldronentrydoor(Actor *param_0)
{
    *(u16*)((char*)param_0 + 0x6E) = *(u16*)((char*)param_0 + 0x6E) & 0xFE00;
    *(f32*)((char*)param_0 + 0x18) = 0.0f;
    if (func_800DA298(0x436, param_0) != 0)
    {
        *(f32*)((char*)param_0 + 0x1C) = 360.0f;
    }
    else
    {
        *(f32*)((char*)param_0 + 0x1C) = 270.0f;
    }
    *(f32*)((char*)param_0 + 0x20) = 0.5f;
    *(f32*)((char*)param_0 + 0x44) = *(f32*)((char*)param_0 + 0x1C);
}

s32 func_80800274_chcauldronentrydoor(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    if (param_1 == 0x95) {
        param_0->rotation[0] = *(f32 *)&param_0->actorData[1];
        return 1;
    }
    if (func_800DA298(0x436)) {
        return 0;
    }
    if (param_1 >= 0x68 && param_1 < 0x6C) {
        local_0 = param_1 - 0x68;
        local_1 = local_0 & 2 ? 2 : 1;
        param_0->unk6C_0 = (param_0->unk6C_0 & (3 - local_1)) + ((local_0 & 1) * local_1);
        if (param_0->unk6C_0 == 3) {
            func_800DA544(0x436);
            _capod_entrypoint_13(param_0->unk0, 0, 4, 16);
            func_800FC6B0(14);
        }
        return 1;
    }
    return 0;
}

void func_80800370_chcauldronentrydoor(s32 arg0) 
{
}
void chcauldronentrydoor_entrypoint_0()
{
    func_800E1720();
}

void func_80800398_chcauldronentrydoor(Actor *param_0)
{
    f32 local_1;

    if (param_0->unk6C_0 == 3) {
        switch (param_0->unk70_10) {
            case 1:
                *(f32 *)&param_0->actorData[0] += 1.0f;
                if (*(f32 *)&param_0->actorData[0] > 25.0f) func_80101FDC(param_0, 2);
                break;
            case 2:
                if (*(f32 *)&param_0->actorData[1] < 360.0f) {
                    local_1 = *(f32 *)&param_0->actorData[2];
                    *(f32 *)&param_0->actorData[1] += local_1;
                    *(f32 *)&param_0->actorData[2] = local_1 * 1.16f;
                    if (*(f32 *)&param_0->actorData[1] > 360.0f) *(f32 *)&param_0->actorData[1] = 360.0f;
                    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800540_chcauldronentrydoor);
                } else {
                    func_80101FDC(param_0, 3);
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800534_chcauldronentrydoor);
                    func_800C9DE4(0.7f, _chcauldronentrydoor_entrypoint_0, func_800E15CC(0, 20.0f, 1.0f));
                }
                break;
        }
    }
    param_0->rotation[0] = *(f32 *)&param_0->actorData[1];
}

int chcauldronentrydoor_entrypoint_1()
{
    return (int)&D_80800550_chcauldronentrydoor;
}

int chcauldronentrydoor_entrypoint_2(void)
{
    extern int D_80800598_chcauldronentrydoor;
    return &D_80800598_chcauldronentrydoor;
}
