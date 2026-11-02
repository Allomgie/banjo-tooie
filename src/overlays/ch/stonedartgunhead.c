#include "common.h"

#define SDF(p) (((SDFlag *)(p)->unk0)->f)
#define AF(p, i) (*(f32 *)&(p)->actorData[i])
#define BITS29(p) (((SDBits *)(p))->b)
typedef struct { u8 pad_0[0x2A]; u8 pad_1:2; u8 local_0:1; u8 pad_2:5; } DartMarkerFlags1482;
extern f32 func_800EFB8C(f32 *, f32 *);
extern void _gccubesearch_entrypoint_13(f32 *, s32, f32 *);
extern s32 _gccubesearch_entrypoint_1(s32, f32 *);
extern s32 _gspropctrl_entrypoint_12(s32);
extern s32 _gspropctrl_entrypoint_13(s32);
extern Actor *func_801084B0(s32, Actor **);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 func_80013728(f32);
extern u8 D_80800E78_chstonedartgunhead[];
typedef struct { u8 pad_0[0x18]; u32 pad_1 : 11; u32 local_0 : 4; u32 pad_2 : 17; } StoneDartMarker;
typedef union { s32 local_0; s16 local_1[2]; } StoneDartEvent;
typedef struct { u8 pad_0[0x28]; u32 pad_1 : 18; u32 local_0 : 1; u32 pad_2 : 13; } DartMarkerFlags;
extern void *D_80800F10_chstonedartgunhead;
extern void func_800EE7F8(int, int);
typedef union { s32 word; Unk80132ED0 *marker; } DartgunEventPayload;
extern int D_80800FB0_chstonedartgunhead;
extern f32 func_800136E4(f32);
extern void func_80101EE4(Actor *, f32);
extern s32 func_800E3AA4(f32);
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } SDState;
extern u8 D_80800E80_chstonedartgunhead[];
extern u8 D_80800E8C_chstonedartgunhead[];
extern u8 D_80800E9C_chstonedartgunhead[];
extern u8 D_80800EAC_chstonedartgunhead[];
extern f32 func_800D8FF8(void);
extern void func_8010C820(Actor *, s32, s32);
extern void func_80108B04(Actor *, s32);
extern int func_800D9078(f32 *);
extern f32 func_8010CD28(Actor *);
extern f32 func_800F11E4(f32, f32, f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern s32 func_8010CB0C(f32 *, s32, s32, s32);
extern void func_80016068(u32, f32 *);
extern void func_80102B2C(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern void _subaddieaudioquick_entrypoint_3();
extern void _subaddieaudioloop_entrypoint_4();
extern void _subaddieaudioloop_entrypoint_0(Actor *, s32);
typedef struct { u8 pad_0[0x2A]; u8 a : 2; u8 f : 1; u8 b : 5; } SDFlag;
typedef struct { u8 pad_0[0x64]; u32 a : 2; u32 b : 1; u32 c : 2; u32 rest : 27; } SDBits;
extern int D_80800EBC_chstonedartgunhead;
extern int D_80800EE0_chstonedartgunhead;
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern u8 D_80800F58_chstonedartgunhead[];
extern u8 D_80800FA0_chstonedartgunhead[];
void func_80800224_chstonedartgunhead();
void func_80800908_chstonedartgunhead();
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800000_chstonedartgunhead(), func_80800B6C_chstonedartgunhead();
extern u8 D_80800E20_chstonedartgunhead[];

void func_80800000_chstonedartgunhead(param_0) Actor *param_0;
{
    s32 local_1;
    f32 local_0[3];

    _gccubesearch_entrypoint_13(local_0, 0x122, param_0->position);
    ((f32 *)param_0->actorData)[0] = func_800EFB8C(param_0->position, local_0);
    local_1 = _gccubesearch_entrypoint_1(0x122, local_0);
    ((f32 *)param_0->actorData)[1] = _gspropctrl_entrypoint_12(local_1) + 1.0f;
    ((f32 *)param_0->actorData)[4] = _gspropctrl_entrypoint_13(local_1);
    param_0->unk64_24 = 1;
    ((DartMarkerFlags1482 *)param_0->unk0)->local_0 = 1;
}

void func_808000A8_chstonedartgunhead(Actor *param_0)
{
    f32 local_0[3];
    Actor *local_1;

    local_1 = func_801084B0(0x123, &param_0);
    local_1->rotation[1] = param_0->rotation[1];
    ((f32 *)local_1->actorData)[3] = ((f32 *)param_0->actorData)[4] * 0.125f * 30.0f;
    local_1->position[1] += 104.0f * param_0->scale;
    func_8010D254(local_0);
    local_0[1] += 60.0f;
    local_1->rotation[0] = func_80013728(func_800F1828(local_1->position, local_0));
    if (local_1->rotation[0] > 10.0f) {
        local_1->rotation[0] = 10.0f;
    } else if (local_1->rotation[0] < -10.0f) {
        local_1->rotation[0] = -10.0f;
    }
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800E78_chstonedartgunhead);
}

void func_808001B4_chstonedartgunhead(Actor *param_0)
{
    s32 local_0;
    local_0 = param_0->rotation[1];
    param_0->rotation[1] = func_800136E4(
        param_0->rotation[1] + *(f32 *)&param_0->actorData[5] * *(f32 *)&param_0->actorData[6]);
    if (local_0 != (s32)param_0->rotation[1]) {
        *(f32 *)&param_0->actorData[7] = 0.2f;
    }
}

void func_80800224_chstonedartgunhead(param_0, param_1) Actor *param_0; s32 param_1;
{
    if (param_0->unk70_10 == 8) _subaddieDll_entrypoint_4(param_0, 0);
    func_80102424(param_0, param_1);
    switch (param_0->unk70_10) {
        case 4: param_0->unk58 = 0.75f; break;
        case 5: func_80101EE4(param_0, 0.856f); break;
        case 3: func_80101EE4(param_0, 0.856f); break;
        case 6:
            if ((f32)func_800E3AA4(param_0->rotation[1]) < 180.0f) {
                *(f32 *)((u8 *)param_0 + 0x2C) = -1.0f;
            } else {
                *(f32 *)((u8 *)param_0 + 0x2C) = 1.0f;
            }
            *(f32 *)((u8 *)param_0 + 0x30) = 20.0f;
            param_0->unk58 = 1.1599884033203125f;
            _subaddieDll_entrypoint_4(param_0, 1);
            break;
        case 7: break;
        case 8: param_0->unk58 = 20.0f; break;
    }
}

void func_80800364_chstonedartgunhead(Actor *param_0)
{
    s32 local_3;
    f32 local_0[2];
    f32 local_1[2];
    s32 local_6;
    f32 local_2;

    func_8010C820(param_0, 0x154, 0x64);
    SDF(param_0) = 1;
    switch (((SDState *)param_0)->st) {
    case 1:
        if (func_8010CB0C(param_0->position, (s32)AF(param_0, 0), 0x190, -0x190)) {
            func_80800224_chstonedartgunhead(param_0, 2);
        }
        break;
    case 2:
        if (func_80101E14(param_0, 0.856f)) {
            func_80800224_chstonedartgunhead(param_0, 3);
        }
        break;
    case 3:
        if (!func_8010CB0C(param_0->position, (s32)AF(param_0, 0), 0x190, -0x190)) {
            func_80800224_chstonedartgunhead(param_0, 5);
            break;
        }
        local_3 = (s32)param_0->rotation[1];
        if (BITS29(param_0)) {
            func_80016068(((SDBits *)param_0)->c, local_0);
            param_0->unk54 = param_0->rotation[1] + (local_0[0] * 4.0f);
        } else {
            param_0->unk54 = func_8010CD28(param_0);
        }
        func_80102B2C(param_0, 4.0f);
        if (local_3 != (s32)param_0->rotation[1]) {
            AF(param_0, 7) = 0.2f;
        }
        if (BITS29(param_0)) {
            if (_subaddiejoy_entrypoint_6(param_0, 1)) {
                if (param_0->unk58 <= 0.0f) {
                    func_80800224_chstonedartgunhead(param_0, 4);
                }
            }
        } else if (param_0->unk58 <= 0.0f) {
            if (func_80102CF4(param_0, 15.0f)) {
                if (func_8010D248()) {
                    AF(param_0, 2) += 1.0f;
                    if (AF(param_0, 1) <= AF(param_0, 2)) {
                        AF(param_0, 2) = 0.0f;
                        func_80800224_chstonedartgunhead(param_0, 4);
                    }
                }
            }
        }
        break;
    case 4:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800E80_chstonedartgunhead, 0x3EE66666);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800E8C_chstonedartgunhead, 0x3F333333);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800E9C_chstonedartgunhead, 0x3F7D2F1B);
        if (BITS29(param_0)) {
            local_6 = (s32)param_0->rotation[1];
            if (0.2f <= func_80101F24(param_0) && param_0->unk58 <= 0.f && _subaddiejoy_entrypoint_6(param_0, 1)) {
                func_80800224_chstonedartgunhead(param_0, 4);
            }
            func_80016068(((SDBits *)param_0)->c, local_1);
            param_0->unk54 = param_0->rotation[1] + (local_1[0] * 4.0f);
            func_80102B2C(param_0, 4.0f);
            if (local_6 != (s32)param_0->rotation[1]) {
                AF(param_0, 7) = 0.2f;
            }
        }
        if (func_80101E14(param_0, 0.999f)) {
            func_80800224_chstonedartgunhead(param_0, 3);
        } else if (func_80101E14(param_0, 0.052f)) {
            func_80108B04(param_0, 0);
        }
        break;
    case 5:
        if (func_80101E14(param_0, 0.999f)) {
            func_80800224_chstonedartgunhead(param_0, 1);
        }
        break;
    case 6:
        SDF(param_0) = 0;
        func_808001B4_chstonedartgunhead(param_0);
        AF(param_0, 6) += 7.444444656f;
        if (87.0f < AF(param_0, 6)) {
            AF(param_0, 6) = 87.0f;
            func_80800224_chstonedartgunhead(param_0, 7);
        }
        break;
    case 7:
        SDF(param_0) = 0;
        func_808001B4_chstonedartgunhead(param_0);
        if (param_0->unk58 <= 0) {
            AF(param_0, 6) -= 1.74000001f;
            if (AF(param_0, 6) < 0) {
                func_80800224_chstonedartgunhead(param_0, 8);
            }
        }
        break;
    case 8:
        SDF(param_0) = 0;
        if (param_0->unk58 <= 0.0f) {
            func_80800224_chstonedartgunhead(param_0, 1);
        }
        break;
    }
    if (0.0f < AF(param_0, 7)) {
        local_2 = func_800F11E4(AF(param_0, 6), 0.0f, 87.0f, 0.7f, 1.0f);
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800EAC_chstonedartgunhead);
        _subaddieaudioloop_entrypoint_0(param_0, *(s32 *)&local_2);
        AF(param_0, 7) -= func_800D8FF8();
    }
    func_800D9078(&param_0->unk58);
}

void func_80800908_chstonedartgunhead(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    s32 local_4;
    s32 local_5;
    local_2 = param_0->scale;
    func_800EC398(param_1, local_1);
    func_800EE7F8(local_0, param_0->position);
    local_0[1] += 70.0f * local_2;
    for (local_4 = 0; local_4 != 4; local_4++) {
        local_5 = func_800BABB8(0, local_0, local_1, local_2, &D_80800EBC_chstonedartgunhead);
        func_800BA4D0(local_5, (s16)(param_0->position[1] - 5.0f));
        func_800BA22C(local_5, 8);
        func_800BBCB8(local_0, local_1, local_2, 1, &D_80800EE0_chstonedartgunhead);
        local_0[1] += 115.0f;
        local_2 -= 0.19f;
    }
    func_800C4104(0x413, 0.7f, 0x7D00, param_0->position, 1250.0f, 2500.0f);
    func_800FFAB0(param_0);
}

s32 func_80800AA4_chstonedartgunhead(Actor *param_0, s32 param_1, StoneDartEvent param_2)
{
    s32 local_0;

    switch (param_1) {
    case 0x3D:
        func_808000A8_chstonedartgunhead(param_0);
        break;
    case 0x3F:
        local_0 = param_0->unk70_10;
        if (local_0 < 6 || local_0 >= 10) {
        if (((StoneDartMarker *)param_0->unk0)->local_0 == 1 && local_0 != 6 && local_0 != 7) {
            func_80800224_chstonedartgunhead(param_0, 6);
        }
        }
        break;
    case 0x40:
        func_80800908_chstonedartgunhead(param_0, param_2.local_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800B6C_chstonedartgunhead(param_0, param_1) Actor *param_0; void *param_1;
{
    func_800DF744(2, 1);
    func_800DF744(3, 0);
    func_800DF744(4, ((DartMarkerFlags *)param_0->unk0)->local_0 ? 1 : 2);
    func_80101870(param_0, param_1);
}

int chstonedartgunhead_entrypoint_0()
{
  return &D_80800F10_chstonedartgunhead;
}

void func_80800BE8_chstonedartgunhead(struct Actor *param_0)
{
    int local_0;
    local_0 = (int)param_0 + 0x18;
    func_800EE7F8(local_0, (int)param_0 + 4);
    param_0->unk58 = 4.0f;
}

void func_80800C28_chstonedartgunhead(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 1:
            func_800EF214(param_0->position, param_0->rotation[0], param_0->rotation[1],
                *(f32 *)((u8 *)param_0 + 0x24) * func_800D8FF8());
            if (func_800EEB40((f32 *)param_0->actorData, param_0->position) > 22500.0f) {
                func_80101FDC(param_0, 10);
            }
            break;
        case 10:
            if (func_800D9078(&param_0->unk58) || func_8010B990(param_0, 0x100006)) {
                func_80102424(param_0, 9);
            }
            break;
        case 9:
            func_800BBCB8(param_0->position, 0, param_0->scale, 2, D_80800F58_chstonedartgunhead);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800FA0_chstonedartgunhead);
            func_800FFAB0(param_0);
            break;
    }
}

s32 func_80800D50_chstonedartgunhead(Actor *param_0, s32 param_1, DartgunEventPayload param_2)
{
    switch (param_1) {
    case 0x40:
        if ((param_2.marker->unk24 >> 22) == 0) {
            func_80102424(param_0, 9);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

int *chstonedartgunhead_entrypoint_1()
{
    return &D_80800FB0_chstonedartgunhead;
}
