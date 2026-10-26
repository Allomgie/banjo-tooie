#include "common.h"
extern void func_800EF214(f32 *, f32, f32, f32);

extern s32 D_80800990_chworlddoors;
extern s32 _sujiggy_entrypoint_22(s32);
extern s32 _gccubesearch_entrypoint_9(s32, s32 *, s32);
extern s32 _gspropctrl_entrypoint_8(s32);
extern void _gspropctrl_entrypoint_11(s32, f32 *);
extern s32 _gspropctrl_entrypoint_12(s32);
extern s32 _gspropctrl_entrypoint_13(s32);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern int D_80800A04_chworlddoors;
extern u8 D_808009D8_chworlddoors[];
extern u8 D_808009E8_chworlddoors[];
extern f32 _capod_entrypoint_18(void);
extern s32 func_800E15CC(s32, f32, f32);
extern void func_800E13F0(s32, f32);
extern void func_80018820(s32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800EE7F8();
extern u8 D_808009F8_chworlddoors[];
extern f32 func_80103EAC(Actor *);
extern void func_800DE498(s32, void *, void *, f32, s32, s32);
void func_80800214_chworlddoors();

void func_80800000_chworlddoors(u8 *param_0) {
    f32 local_0[3];

    func_800EE7F8(local_0, param_0 + 0x28);
    func_800EF214(local_0, (*(f32 *)((s8 *)(param_0) + (0x44))), (*(f32 *)((s8 *)(param_0) + (0x48))), -5e+01f);
    func_800BBCB8(param_0 + 0x28, local_0, 0x3F800000, 6, &D_80800990_chworlddoors);
}

s32 func_80800068_chworlddoors(Actor *param_0)
{
    s32 local_0[2];
    f32 local_1[2];
    s32 local_2;
    s32 local_6;
    s32 local_7;
    s32 local_5;
    s32 *local_8;

    local_5 = _sujiggy_entrypoint_22(param_0->unk79_4);
    local_6 = _gccubesearch_entrypoint_9(0x4DC, local_0, 2);
    local_7 = 0;
    if (local_6 > 0) {
        local_8 = local_0;
        do {
            if (_gspropctrl_entrypoint_8(*local_8) == local_5 + 0x32) {
                _gspropctrl_entrypoint_11(*local_8, (f32 *)&param_0->actorData[0]);
                local_2 = _gspropctrl_entrypoint_13(*local_8) - 1;
                *(f32 *)&param_0->actorData[13] = _gspropctrl_entrypoint_12(*local_8);
            }
            local_7++;
            local_8++;
        } while (local_7 != local_6);
        local_7 = 0;
    }
    local_6 = _gccubesearch_entrypoint_9(0x4DD, local_0, 2);
    if (local_6 > 0) {
        local_8 = local_0;
        do {
            if (_gspropctrl_entrypoint_8(*local_8) == local_5 + 0x32) {
                _gspropctrl_entrypoint_11(*local_8, (f32 *)&param_0->actorData[4]);
                param_0->unk54 = _gspropctrl_entrypoint_13(*local_8) / 10.0f;
                param_0->unk50 = _gspropctrl_entrypoint_12(*local_8) / 10.0f;
            }
            local_7++;
            local_8++;
        } while (local_7 != local_6);
    }
    func_800F18FC((f32 *)&param_0->actorData[4], (f32 *)&param_0->actorData[0], local_1);
    param_0->rotation[0] = local_1[0];
    param_0->rotation[1] = local_1[1];
    func_800EEBF0((f32 *)&param_0->actorData[0], local_1, 4000.0f);
    func_800EF04C((f32 *)&param_0->actorData[0], (f32 *)&param_0->actorData[4]);
    return local_2;
}

void func_80800214_chworlddoors(param_0, param_1) void *param_0; s32 param_1;
{
    s32 local_0;
    float local_1;
    s32 local_2;

    switch (param_1) {
    case 1:
        local_0 = func_80800068_chworlddoors(param_0);
        func_800EE7F8((s32 *)((char *)param_0 + 0x4), (s32 *)((char *)param_0 + 0x18));
        local_2 = *(s32 *)((char *)param_0 + 0x0);
        _capod_entrypoint_13(local_2, local_2, local_0, 0x6830);
        *(float *)((char *)param_0 + 0x58) = 0.0f;
        break;
    case 2:
        local_1 = 1.0f;
        *(s8 *)((char *)param_0 + 0x34) = 0;
        *(float *)((char *)param_0 + 0x58) = local_1;
        break;
    case 3:
        *(float *)((char *)param_0 + 0x58) = 0.8f;
        *(s8 *)((char *)param_0 + 0x34) = 0;
        func_800C3F48(0x7FFFFC90);
        break;
    case 4:
        func_800E1720(*(s32 *)((char *)param_0 + 0x24) - 1);
        _subaddieaudioloop_entrypoint_2(param_0);
        *(float *)((char *)param_0 + 0x58) = 2.0f;
        func_8010A800(param_0, 3);
        break;
    case 5:
        func_80101180(_sujiggy_entrypoint_23((u32)(*(u8 *)((char *)param_0 + 0x79)) >> 4), 7, (s32)*(float *)((char *)param_0 + 0x50));
        *(float *)((char *)param_0 + 0x58) = *(float *)((char *)param_0 + 0x50);
        break;
    case 6:
        if ((((u32)(*(u8 *)((char *)param_0 + 0x79)) >> 4) == 0)) {
            *(s32 *)((char *)param_0 + 0x24) = func_800E15CC(2, 5e+01f, 0.5f);
            func_80018820(0, 1.0f, 0.4f);
        }
        *(float *)((char *)param_0 + 0x58) = *(float *)((char *)param_0 + 0x54);
        local_1 = *(float *)((char *)param_0 + 0x54);
        break;
    }
    func_80101FDC(param_0, param_1);
}

void func_80800388_chworlddoors(Actor *param_0)
{
    f32 local_0;

    switch (param_0->unk70_10) {
    case 1:
        local_0 = _capod_entrypoint_18();
        if (local_0 < 0.1f) {
            local_0 = 0.1f;
        }
        if (param_0->actorData[3] == 0) {
            param_0->actorData[3] = func_800E15CC(0, 0.0f, 1.0f) + 1;
        }
        func_800E13F0(param_0->actorData[3] - 1, local_0 * 10.0f);
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808009E8_chworlddoors);
        func_800C4B70((s32)(24000.0f * local_0));
        func_80018820(0, local_0, 0.1f);
        break;
    case 2:
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808009E8_chworlddoors);
        func_800C4B70(24000);
        func_80018820(0, 1.0f, 0.1f);
        if (func_800D90A4(&param_0->unk58)) {
            func_80800214_chworlddoors(param_0, 3);
            func_800EE7F8(param_0->position, (f32 *)&param_0->actorData[4]);
        } else {
            func_800EFE50(param_0->position, (f32 *)param_0->actorData, (f32 *)&param_0->actorData[4],
                func_800F10B4(param_0->unk58, 1.0f, 0.0f, 0.0f, 1.0f));
        }
        *(u8 *)&param_0->actorData[7] = _subaddieaudioloop_entrypoint_7(
            *(u8 *)&param_0->actorData[7], param_0->position, 1, D_808009D8_chworlddoors, 0);
        break;
    case 3:
        if (func_800D90A4(&param_0->unk58)) {
            func_80800214_chworlddoors(param_0, 4);
            *(u8 *)&param_0->actorData[7] = _subaddieaudioloop_entrypoint_3(*(u8 *)&param_0->actorData[7]);
            _subaddieaudioloop_entrypoint_2(param_0);
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808009E8_chworlddoors);
            func_800C4B70(24000);
            func_80018820(0, 1.0f, 0.1f);
            func_80800000_chworlddoors(param_0);
            param_0->scale = func_800F10B4(param_0->unk58, 0.8f, 0.0f, 1.0f, 0.001f);
            *(u8 *)&param_0->actorData[7] = _subaddieaudioloop_entrypoint_7(
                *(u8 *)&param_0->actorData[7], param_0->position, 1, D_808009D8_chworlddoors, 0);
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808009E8_chworlddoors);
            func_800C4B70(24000);
        }
        break;
    case 4:
        if (func_800D90A4(&param_0->unk58)) {
            func_80800214_chworlddoors(param_0, 5);
        }
        break;
    case 5:
        if (func_800D90A4(&param_0->unk58)) {
            func_80800214_chworlddoors(param_0, 6);
        }
        break;
    case 6:
        if (func_800D90A4(&param_0->unk58)) {
            _glcutDll_entrypoint_17();
        }
        break;
    }
}

s32 func_808006A8_chworlddoors(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x49:
            if (param_2 >= 0x7A && param_2 < 0x84) {
                param_0->unk79_4 = param_2 - 0x7A;
                func_8010A800(param_0, 0);
                func_80800214_chworlddoors(param_0, 1);
                return 1;
            }
            func_800FFAB0(param_0);
            return 0;
        case 0xB:
            if (param_0->unk70_10 == 1) func_80800214_chworlddoors(param_0, 2);
            return 3;
    }
    return 0;
}

int func_80800750_chworlddoors(Actor *param_0)
{

    if (*((s32 *)((char *)param_0 + 0x24)) != 0)
    {
        func_800E1720(*((s32 *)((char *)param_0 + 0x24)) - 1);
    }
    if ((*(u8 *)((char *)param_0 + 0x5F)) != 0)
    {
        _subaddieaudioloop_entrypoint_2(param_0);
    }
}

void func_80800798_chworlddoors(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1;
    s32 local_2;
    f32 local_3;
    func_800EE7F8(local_0, param_0->position);
    func_800EF214(param_0->position, param_0->rotation[0], param_0->rotation[1], func_80103EAC(param_0));
    switch (param_0->unk70_10) {
        case 3:
            local_1 = func_800F10B4(param_0->unk58, 0.8f, 0.0f, 0.0001f, 20.0f);
            local_2 = func_800F10B4(param_0->unk58, 0.8f, 0.0f, 0.0f, 255.0f);
            func_800DF830(0);
            func_800DE498(param_1, (u8 *)param_0 + 0x28, param_0->rotation, local_1, 0, func_800D674C(0x8CB));
            func_80101870(param_0, param_1);
            func_800B99CC(param_1, local_2, D_808009F8_chworlddoors);
            break;
        case 2: func_80101870(param_0, param_1); break;
        case 4:
            func_800B99CC(param_1, (s32)func_800F10B4(param_0->unk58, 2.0f, 0.0f, 255.0f, 0.0f), D_808009F8_chworlddoors);
            break;
    }
    func_800EE7F8(param_0->position, local_0);
}

int chworlddoors_entrypoint_0()
{
  return &D_80800A04_chworlddoors;
}
