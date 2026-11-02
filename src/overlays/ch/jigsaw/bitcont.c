#include "common.h"

#define JIGSAW_BIT_SETTINGS_1590
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s16 unkC; s16 unkE; } JigsawInfo;
typedef struct { u8 pad0[0x24]; s16 unk24; } JigsawData;
typedef struct { u8 pad0[0x74]; u32 pad74 : 10; u32 unk74_21 : 1; u32 pad74_0 : 21; } JigsawActor;
extern void _chjigsawcollect_entrypoint_1(Actor **, s32, s32);
extern s32 func_800DA298(s32);
extern void func_80100120(Actor *);
typedef struct { u8 pad_0[0x24]; s16 local_0; } JigsawBitCounter;
typedef struct { s16 local_0; u8 pad_0[0xE]; } JigsawBitThreshold;
extern JigsawBitThreshold D_808009AA_chjigsawbitcont[];
extern void func_80108B04(Actor *, s32);
struct JigsawBitSettings;
extern s32 D_808009B4_chjigsawbitcont;
typedef struct JigsawBitSettings { s16 local_2; s16 local_3; f32 local_0; f32 local_1; s16 pad_0; s16 local_4; } JigsawBitSettings;
extern JigsawBitSettings D_808009A8_chjigsawbitcont[];
extern s16 D_808009B6_chjigsawbitcont[][8];
extern Actor *func_80106790(Unk80132ED0 *);
extern void *func_80100094(Actor *, u32);
extern void func_800DA544(s32);
extern void func_800D0BD4(s32, s32);
extern void func_800FC660(s32);
extern void func_800FCAE0(s32, s32, s32);
extern int D_808009B8_chjigsawbitcont;
extern f32 func_800DC178(f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern u8 D_808009A0_chjigsawbitcont[];
extern f32 func_800D8FF8(void);
extern Actor *func_801084B0(s32, Actor **);
extern int D_80800A28_chjigsawbitcont;
extern s32 D_80800A00_chjigsawbitcont;
f32 func_800DC0C0(void);
s32 func_800E3E8C(s32, s32);
s32 func_8001211C(void);
s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
s32 func_8010C9B0(s32, s32);
void func_800FFAB0(s32);
void func_808002E4_chjigsawbitcont();
void func_80800890_chjigsawbitcont();
void func_80800634_chjigsawbitcont();
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_808002E4_chjigsawbitcont();

void func_80800000_chjigsawbitcont(u8 *param_0, s32 param_1) {
    func_80101FDC();
    if ((param_1 == 2) && (func_800DA298(*(s16 *)(((u8 *) &D_808009B4_chjigsawbitcont) + (((u32) (*(u16 *)((u8 *)(param_0) + (0x76))) >> 7) * 0x10))) == 0)) {
        func_800DA544(*(s16 *)(((u8 *) &D_808009B4_chjigsawbitcont) + (((u32) (*(u16 *)((u8 *)(param_0) + (0x76))) >> 7) * 0x10)));
        func_80108B04(param_0, 0);
    }
}

s32 func_80800084_chjigsawbitcont(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    JigsawData *local_0;
    s32 i;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x3D:
        if (param_2 == -1) {
            _chjigsawcollect_entrypoint_1(&param_0, ((JigsawInfo *) D_808009A8_chjigsawbitcont)[param_0->unk74_7].unk0, 0);
        } else {
            for (i = 0; i < ((JigsawInfo *) D_808009A8_chjigsawbitcont)[param_0->unk74_7].unk2; i++) {
                if (!func_800DA298(((JigsawInfo *) D_808009A8_chjigsawbitcont)[param_0->unk74_7].unkE + i)) {
                    func_80800890_chjigsawbitcont(param_0, i, param_2);
                } else {
                    local_0->unk24++;
                }
            }
        }
        break;
    case 0xA:
        if (!((JigsawActor *)param_0)->unk74_21) {
            func_80100120(param_0);
        }
        if (param_2 == param_0->unk74_7 && !func_800DA298(((JigsawInfo *) D_808009A8_chjigsawbitcont)[param_0->unk74_7].unkC)) {
            func_80800000_chjigsawbitcont(param_0, 2);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800214_chjigsawbitcont(Actor *param_0)
{
    JigsawBitCounter *local_0;

    local_0 = func_80100094(param_0, 0);
    if (param_0->unk74_7 && param_0->unk74_7 && param_0->unk74_7) {} /* probe: the empty triple test uses up temps (t ring -1); the natural form is still open. func_800D8FF8 again without dummy arguments */
    if (param_0->unk64_20) {
        /* PROBE (agV20): func_800D8FF8 takes no args (core2 1EB2840.c); passing (param_0, local_0) only reproduces a1 for local_0 */
        ((f32 *)param_0->actorData)[4] -= func_800D8FF8();
        if (((f32 *)param_0->actorData)[4] < 0.0f) {
            ((f32 *)param_0->actorData)[4] = 0.0f;
            param_0->unk64_20 = 0;
            if (local_0->local_0 < D_808009AA_chjigsawbitcont[param_0->unk74_7].local_0 && func_800FCCD4(5)) {
                func_800FCAE0(5, 0, 0x1F40);
                func_800FCA90(5);
            }
        }
    }
}

void func_808002E4_chjigsawbitcont(param_0) Actor *param_0;
{
    f32 *local_0[3];
    u8 *local_1;
    s32 local_2;
    s32 local_3;

    local_1 = func_80100094(param_0, 0);
    param_0->unk74_7 = param_0->unk74_7 - 50;
    if (param_0->unk74_7 != 0) {
        func_800FFAB0(param_0);
        return;
    }
    if (func_800D0B68(*(s16 *)((u8 *)((struct JigsawBitSettings *) D_808009A8_chjigsawbitcont) + param_0->unk74_7 * 0x10), 1, param_0->unk74_7)) {
        func_800FFAB0(param_0);
        return;
    }
    *(s16 *)(local_1 + 0x24) = 0;
    local_2 = _gccubesearch_entrypoint_9(0x312, local_0, 3);
    for (local_3 = 0; local_3 < local_2; local_3++) {
        func_800EE88C((f32 *)(local_1 + local_3 * 0xC), local_0[local_3]);
    }
    if (func_800DA298(*(s16 *)((u8 *)&D_808009B4_chjigsawbitcont + param_0->unk74_7 * 0x10))) {
        func_80108B04(param_0, 1);
    }
}

void func_8080040C_chjigsawbitcont(Actor *param_0)
{
    Actor *local_0;
    JigsawBitCounter *local_1;
    JigsawBitSettings *local_2;
    s16 local_3;
    f32 r;
    f32 dead;

    local_0 = func_80106790(param_0->unk3C);
    local_1 = func_80100094(local_0, 0);
    local_1->local_0++;
    func_800DA544(D_808009B6_chjigsawbitcont[local_0->unk74_7][0] + param_0->unk6C_0);
    local_3 = local_1->local_0;
    if (1) {}
    if (1) {}
    if (1) {}
    if (1) {}
    local_2 = &D_808009A8_chjigsawbitcont[local_0->unk74_7];
    if (local_2) {}
    if (local_3 == D_808009A8_chjigsawbitcont[local_0->unk74_7].local_3) {
        func_800D0BD4((&D_808009A8_chjigsawbitcont[local_0->unk74_7])->local_2, 1);
        func_800FC660(5);
        func_80108B04(local_0, -1);
        return;
    }
    if (!local_0->unk64_20) {
        r = (f32)local_3 / (f32)D_808009A8_chjigsawbitcont[local_0->unk74_7].local_3;
        ((f32 *)local_0->actorData)[4] = 1.75f * r;
        func_800FC660(5);
    } else {
        r = 1.0f / (f32)D_808009A8_chjigsawbitcont[local_0->unk74_7].local_3;
        ((f32 *)local_0->actorData)[4] += 1.75f * r;
        if (r) {}
        func_800FCAE0(5, 0x7FFF, 8000);
    }
    local_0->unk64_20 = 1;
}

int chjigsawbitcont_entrypoint_0()
{
  return (int)&D_808009B8_chjigsawbitcont;
}

void func_80800570_chjigsawbitcont(Actor *param_0, s32 param_1)
{
    func_80101FDC(param_0, param_1);
    switch (param_0->unk70_10) {
    case 2:
        param_0->unk79_4 = 3;
        *(f32 *)&param_0->actorData[3] = func_800DC178(0.0f, 250.0f);
        _subaddiebounce_entrypoint_0(param_0);
        param_0->unk64_16 = 1;
        break;
    case 3:
        func_800EE7F8(param_0->position, (f32 *)param_0->actorData);
        _subaddieDll_entrypoint_4(param_0, 0);
        break;
    case 4:
        func_800EE7F8(param_0->position, (f32 *)param_0->actorData);
        param_0->unk64_16 = 1;
        break;
    }
}

void func_80800634_chjigsawbitcont(param_0) s32 param_0; {
    s32 sp24;
    s32 temp_a0;

    temp_a0 = param_0 + 4;
    sp24 = temp_a0;
    if ((func_800E3E8C(temp_a0, 0x42480000) != 0) && !(func_8001211C() & 3) && (func_800DC0C0() < 0.1f)) {
        func_800BBCB8(sp24, 0, 0x3F800000, 2, &D_80800A00_chjigsawbitcont);
    }
    if (func_8010C9B0(sp24, 0x32) != 0) {
        func_8080040C_chjigsawbitcont(param_0);
        func_800FFAB0(param_0);
    }
}

void func_808006D8_chjigsawbitcont(Actor *param_0)
{
    f32 local_0;
    f32 local_1;
    switch (param_0->unk70_10) {
        case 1:
            *(u8 *)((u8 *)param_0 + 0x65) &= ~1;
            if (param_0->unk58 > 0.0f) {
                param_0->unk58 -= func_800D8FF8();
            } else {
                func_80800570_chjigsawbitcont(param_0, 2);
            }
            return;
        case 2:
            local_0 = func_800D8FF8();
            func_80800634_chjigsawbitcont(param_0);
            if (param_0->unk79_4 >= 3) {
                if (_subaddiebounce_entrypoint_1(param_0)) {
                    param_0->unk79_4 = 2;
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808009A0_chjigsawbitcont);
                }
                local_1 = 360.0f * local_0;
                param_0->rotation[1] += local_1;
                param_0->rotation[0] += local_1;
            } else if (_subaddiebounce_entrypoint_2(param_0)) {
                param_0->unk79_4--;
                if (param_0->unk79_4 <= 0) {
                    func_80800570_chjigsawbitcont(param_0, 3);
                }
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808009A0_chjigsawbitcont);
            }
            return;
        case 3:
        case 4:
            func_80800634_chjigsawbitcont(param_0);
            break;
    }
}

void func_80800868_chjigsawbitcont(void *param_0) {
    (*(f32 *)((char *)(param_0) + 0x38)) = 0.2f;
    (*(f32 *)((char *)(param_0) + 0x34)) = -1500.0f;
    (*(f32 *)((char *)(param_0) + 0x24)) = 840.0f;
}

void func_80800890_chjigsawbitcont(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    Actor *local_0;
    f32 (*local_1)[3];

    local_0 = func_801084B0(0x17F, &param_0);
    local_1 = func_80100094(param_0, 0);
    local_0->unk6C_0 = param_1;
    func_800EE7F8((f32 *)((u8 *)local_0 + 0x18), local_1[local_0->unk6C_0]);
    local_0->unk3C = param_0->unk0;
    local_0->unk58 = func_800DC178(D_808009A8_chjigsawbitcont[param_0->unk74_7].local_0, D_808009A8_chjigsawbitcont[param_0->unk74_7].local_1);
    switch (param_2) {
        case 0:
            _subaddieDll_entrypoint_4(local_0, 1);
            break;
        case 1:
            func_80800570_chjigsawbitcont(local_0, 4);
            break;
    }
}

int chjigsawbitcont_entrypoint_1()
{
    return (int)&D_80800A28_chjigsawbitcont;
}
