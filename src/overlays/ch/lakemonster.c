#include "common.h"

extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800DBEFC(void *, s32, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_80101E4C(Actor *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern u8 D_80802108_chlakemonster[];
extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_8080212C_chlakemonster[];
extern u8 D_80802150_chlakemonster[];
extern void func_800BA994();
typedef struct { u8 pad_0[0xC]; f32 local_0[3]; u8 pad_1[0x26]; u8 local_1; u8 local_2; } LakeMonsterEffectState;
typedef struct { s32 local_0; s32 local_1; } LakeMonsterEffectBones;
extern LakeMonsterEffectBones D_80802174_chlakemonster[];
extern void *func_801039E4(Unk80132ED0 *);
extern u8 *func_800D674C(s32);
extern f32 func_80101F24(Actor *);
extern void func_800E02F8(u8 *, f32, s32, s32, s32, f32 *);
extern void *func_800B2768(void *);
extern void *func_80103CB8(Actor *, void *);
extern void *func_800B2840(void *);
extern void _dbmorph_entrypoint_3(void *, void *, void *, s32, f32 *);
typedef struct { u8 pad_0[0x14]; u32 pad_1 : 31; u32 local_0 : 1; } LakeMonsterMorph;
extern void func_801015D0();
extern f32 func_800D8FF8(void);
extern u8 D_80802030_chlakemonster[];
extern float D_80802044_chlakemonster[];
extern void func_8008F8B0(void);
extern void func_8008F8D8(s32);
extern void func_8008F904(void *, s32);
extern void func_8008F938(s32);
extern void func_8008F964(void *);
extern void func_8008F9C4(void *, f32);
extern f32 D_808020D4_chlakemonster[];
extern void *func_8010D5DC;
typedef struct { s32 f0; s32 f4; u8 pad[0x6C]; u8 pad74:1; u8 flag:1; u8 rest:6; } FarmerState;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
typedef union { s32 local_0; s16 local_1[2]; } LakeMonsterEvent;
extern int D_80802204_chlakemonster[];
extern u8 D_8080224C_chlakemonster[];
extern void _chlakemonster_entrypoint_1();
extern s32 func_800DC298(f32);
extern int D_8080229C_chlakemonster[];
extern int D_808022E0_chlakemonster[];
extern int D_80802328_chlakemonster[];
extern u8 D_808020E0_chlakemonster[];
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
typedef struct { s32 local_0[5]; } LakeMonsterEventRange;
typedef struct { s32 local_0[2]; } LakeMonsterEventPair;
extern s32 D_808021B4_chlakemonster[];
extern s32 D_808021C8_chlakemonster[];
extern s32 D_808021D0_chlakemonster[];
extern s32 D_808021E4_chlakemonster[];
extern s32 D_80802058_chlakemonster[];
extern s32 D_8080207C_chlakemonster[];
typedef struct { f32 local_0[3]; f32 local_1[3]; f32 local_2; f32 local_3; f32 local_4; f32 local_5; f32 local_6; u8 pad_2C[0x11]; u8 local_7; u8 local_8; u8 local_9; } LakeMonsterLocal;
typedef struct { f32 local_0[3]; } LakeMonsterAnimationPoints;
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1828(f32 *, f32 *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_801022E4(Actor *);
extern s32 func_8010CAC0(f32 *, u32);
extern s32 func_8010CB84(f32 *, u32);
extern void func_80101EE4(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern s32 func_8001210C(s32);
extern s32 func_800DC128(s32, s32);
extern s32 func_800C4350(u32, void *, void *);
extern void func_800C31DC(s32, f32);
extern void func_800C3058(s32, s32);
extern void func_800C2FDC(s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern u8 D_808020BC_chlakemonster[];
extern u8 D_808022C8_chlakemonster[];
void func_80800090_chlakemonster();
void func_80801494_chlakemonster();

void func_80800000_chlakemonster(Actor *param_0)
{
    func_800EFA4C(param_0->position, 0.0f, -3050.0f, 0.0f);
    if (_glcutDll_entrypoint_20()) {
        func_80801494_chlakemonster(param_0, 7);
    } else {
        func_80801494_chlakemonster(param_0, 1);
    }
}

int func_80800064_chlakemonster(s32 param_0)
{
  func_80100074(param_0, 0, 0);
  func_800FDC28(0);
}

void func_80800090_chlakemonster(param_0, param_1, param_2, param_3) Actor *param_0; s32 param_1; s32 param_2; s32 param_3;
{
    s32 local_0;
    f32 local_1;

    local_0 = func_800B53A4(param_3);
    local_1 = param_0->scale;
    func_800BA7C4(local_0, local_1 * 0.02f, local_1 * 0.15f);
    local_1 = param_0->scale;
    func_800BA7FC(local_0, local_1 * 0.05f, local_1 * 0.1f);
    local_1 = param_0->rotation[1];
    func_800BA994(local_0, -45, (s16)(s32)(local_1 - 25.0f), 25, -25, (s32)(local_1 + 25.0f), 75);
    func_800BABB8(local_0, param_0->position, 0, 1.0f, D_808020E0_chlakemonster);
    func_800BA1D0(local_0, param_1, param_2, param_3);
}

void func_808001C0_chlakemonster(Actor *param_0)
{
  s32 pad0;
  s32 local_0;
  f32 local_1[3];
  u8 *local_2;
  local_2 = func_80100094(param_0, 0);
  local_0 = func_800B53A4(2);
  func_800EE7F8(local_1, ((u8 *) param_0) + 0x28);
  func_800EF214(local_1, *((f32 *) (local_2 + 0x20)), (*((f32 *) (local_2 + 0x1C))) - 30.0f, 150.0f);
  func_800BABB8(local_0, local_1, 0x20 * 0, 1.0f, D_80802108_chlakemonster);
  func_800BA994(local_0, (s16) ((s32) ((*((f32 *) (local_2 + 0x20))) - 10.0f)), (s16) ((s32) ((*((f32 *) (local_2 + 0x1C))) - 10.0f)), (s16) ((s32) (param_0->scale * 150.0f)), (s32) ((*((f32 *) (local_2 + 0x20))) + 10.0f), (s32) ((*((f32 *) (local_2 + 0x1C))) + 10.0f), (s32) (param_0->scale * 300.0f));
  func_800BA22C(local_0, 2);
}

void func_808002FC_chlakemonster(Actor *param_0)
{
    s32 local_0;
    f32 *local_1;

    local_0 = func_800B53A4(6);
    local_1 = func_80100094(param_0, 0);
    func_800BABB8(local_0, (f32 *)&param_0->actorData[4], NULL, 1.0f, D_8080212C_chlakemonster);
    func_800BA994(local_0, (s16)(local_1[8] - 10.0f), (s16)(local_1[7] - 10.0f), (s16)(param_0->scale * 100.0f),
                 (s32)(local_1[8] + 10.0f), (s32)(local_1[7] + 10.0f), (s32)(param_0->scale * 200.0f));
    func_800BA22C(local_0, 6);
}

void func_80800404_chlakemonster(Actor *param_0)
{
    Vec3f local_2;
    s32 local_0;
    f32 *local_1;
    local_0 = func_800B53A4(3);
    local_1 = func_80100094(param_0, 0);
    func_800DBEFC(param_0->unk0->unk4, 0xC, local_2.f);
    func_800BABB8(local_0, local_2.f, 0, 1.0f, D_80802150_chlakemonster);
    func_800BA994(local_0, (s16)(local_1[8] - 5.0f - 15.0f), (s16)(local_1[7] - 5.0f - 25.0f), (s16)(param_0->scale * 50.0f),
        (s32)(local_1[8] + 5.0f - 15.0f), (s32)(local_1[7] + 5.0f - 25.0f), (s32)(param_0->scale * 100.0f));
    func_800BA22C(local_0, 3);
    local_0 = func_800B53A4(3);
    func_800DBEFC(param_0->unk0->unk4, 0xD, local_2.f);
    func_800BABB8(local_0, local_2.f, 0, 1.0f, D_80802150_chlakemonster);
    func_800BA994(local_0, (s16)(local_1[8] - 5.0f - 15.0f), (s16)(local_1[7] - 5.0f + 25.0f), (s16)(param_0->scale * 50.0f),
        (s32)(local_1[8] + 5.0f - 15.0f), (s32)(local_1[7] + 5.0f + 25.0f), (s32)(param_0->scale * 100.0f));
    func_800BA22C(local_0, 3);
}

void func_8080064C_chlakemonster(Actor *param_0)
{
    LakeMonsterEffectState *local_0;
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    local_3 = func_800DC128(4, 7);
    func_800DBEFC(param_0->unk0->unk4, D_80802174_chlakemonster[local_3].local_0, local_1);
    func_800DBEFC(param_0->unk0->unk4, D_80802174_chlakemonster[local_3].local_1, local_2);
    if (local_0->local_2) {
        func_800EF04C(local_1, local_0->local_0);
        func_800EF04C(local_2, local_0->local_0);
    }
    func_80800090_chlakemonster(param_0, local_1, local_2, func_800DC128(1, 3) + local_0->local_1);
}

void func_80800724_chlakemonster(Actor *param_0)
{
    void *local_0;
    s16 local_1;
    u8 *local_2;

    local_0 = func_801039E4(param_0->unk0);
    local_1 = 0;
    local_2 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 2: local_1 = 0x1F2; break;
    case 3: local_1 = 0x1F3; break;
    case 4: local_1 = 0x1F4; break;
    }
    if (local_1) {
        func_800E02F8(func_800D674C(local_1), func_80101F24(param_0), 0, 0x2A, 0x2D,
            (f32 *)(local_2 + 0x2C));
    }
    _dbmorph_entrypoint_3(func_800B2768(local_0),
        func_80103CB8(param_0, local_0), func_800B2840(local_0), 1,
        (f32 *)(local_2 + 0x2C));
}

void func_80800838_chlakemonster(Actor *param_0)
{
    void *local_0;
    void *local_1;
    LakeMonsterMorph *local_2;
    void *local_3;

    local_0 = func_801039E4(param_0->unk0);
    local_1 = func_800B2768(local_0);
    local_2 = func_80103CB8(param_0, local_0);
    local_3 = func_800B2840(local_0);
    func_80800724_chlakemonster(param_0);
    func_801015D0(param_0);
    local_2->local_0 = 1;
    if (func_800AE0E8(*(s16 *)&param_0->unk0->unk10)) {
        _dbmorph_entrypoint_4(local_1, local_2, local_3, 1, func_800AE080(*(s16 *)&param_0->unk0->unk10));
    }
}

void func_808008E8_chlakemonster(Actor *param_0)
{
    f32 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (local_0[9] <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(param_0, (f32 *)param_0->actorData + 4, D_80802030_chlakemonster);
        local_0[9] = 2.5f;
    } else {
        local_0[9] -= func_800D8FF8();
    }
}

void func_80800968_chlakemonster(s32 param_0)
{
    u8 *sp1C;

    sp1C = func_80100094(param_0, 0);
    if ((*(f32 *)((s8 *)(sp1C) + (0x28))) <= 0.0f)
    {
        _subaddieaudioquick_entrypoint_2(param_0, param_0 + 0x28, &D_80802044_chlakemonster);
        (*(f32 *)((s8 *)(sp1C) + (0x28))) = 1.5f;
    }
}

s32 func_808009CC_chlakemonster(void){
    func_800F7C9C(func_800F54E4(), 0x95, 0x116, 0xA);
    _gcgoto_entrypoint_1(0x123, 1);
    func_800DA544(0x6E8);
}

void func_80800A14_chlakemonster(Actor *param_0, s32 param_1, s32 param_2)
{
    extern f32 func_80101F24(Actor *);
    extern s32 func_80101E14(Actor *, f32);
    extern void func_80018820(s32, f32, f32);
    u8 *local_0;
    LakeMonsterEventRange local_1;
    LakeMonsterEventPair local_2;
    LakeMonsterEventRange local_3;
    LakeMonsterEventPair local_4;
    f32 local_5;
    local_0 = (u8 *)func_80100094(param_0, 0);
    if (param_2) { func_8080064C_chlakemonster(param_0); }
    if (param_0->unk7C_12) {
        local_1 = *(LakeMonsterEventRange *)D_808021B4_chlakemonster;
        local_2 = *(LakeMonsterEventPair *)D_808021C8_chlakemonster;
        local_3 = *(LakeMonsterEventRange *)D_808021D0_chlakemonster;
        local_4 = *(LakeMonsterEventPair *)D_808021E4_chlakemonster;
        local_5 = func_80101F24(param_0);
        if (func_80101E4C(param_0, &local_3)) {
            _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 0x28, D_80802058_chlakemonster);
            *(f32 *)(local_0 + 0x18) = 0.85f;
        } else if (func_80101E4C(param_0, &local_2)) {
            func_808008E8_chlakemonster(param_0);
            func_808001C0_chlakemonster(param_0);
        } else if (func_80101E4C(param_0, &local_1)) {
            func_80800968_chlakemonster(param_0);
        } else if (!func_80101E4C(param_0, &local_4)) {
            if (func_80101E14(param_0, 0.965f)) {
                _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 0x28, D_8080207C_chlakemonster);
                func_80018820(0, 2.0f, 0.25f);
                if (param_1) {
                    func_80101180(0x501, 0xBC, 0);
                } else {
                    local_0[0x3D] = 1;
                    func_8009086C(0);
                }
            } else if (func_80101DDC(param_0) && param_1 == 0) {
                func_808009CC_chlakemonster();
            }
        }
        if (local_5 > 0.24f && local_5 < 0.31f && func_8001210C(0xF)) {
            func_808001C0_chlakemonster(param_0);
        }
    }
}

void func_80800C88_chlakemonster(Actor *param_0)
{
    extern f32 D_808020D4_chlakemonster[];
    extern f32 D_808021EC_chlakemonster[];
    extern u8 D_808021F8_chlakemonster[];
    extern s32 D_8080207C_chlakemonster[];
    extern u8 D_8080208C_chlakemonster[];
    extern u8 D_808020A4_chlakemonster[];

    LakeMonsterLocal *local_0;
    s32 local_1;


    local_0 = func_80100094(param_0, 0);
    local_1 = 0;

    if (local_0 != 0) {
        if (param_0->unk7C_12) {
            f32 local_6[3];
            f32 local_7[3];
            f32 local_8[3];
            f32 local_9[3];
            func_800DBEFC(
                param_0->unk0->unk4,
                8,
                local_6
            );

            func_800DBEFC(
                param_0->unk0->unk4,
                0xB,
                local_7
            );

            if (func_800EEB40(local_6, local_7) > 12000.0f) {
                if (local_0->local_8 == 0) {
                    local_0->local_8 = 10;
                }

                local_1 = 1;
            }

            func_800DBEFC(
                param_0->unk0->unk4,
                5,
                (f32 *)&param_0->actorData[4]
            );

            func_800DBEFC(
                param_0->unk0->unk4,
                4,
                local_8
            );

            func_800EF04C(
                (f32 *)&param_0->actorData[4],
                local_8
            );

            func_800EF334(
                (f32 *)&param_0->actorData[4],
                0.5f
            );

            if (local_0->local_9 != 0) {
                func_800EFB24(
                    local_0->local_1,
                    (f32 *)&param_0->actorData[4],
                    local_0->local_0
                );

                func_800EE7F8(
                    local_0->local_0,
                    (f32 *)&param_0->actorData[4]
                );

                func_800EF334(
                    local_0->local_1,
                    2.0f
                );

                func_800EF04C(
                    (f32 *)&param_0->actorData[4],
                    local_0->local_1
                );
            } else {
                func_800EE7F8(
                    local_0->local_0,
                    (f32 *)&param_0->actorData[4]
                );

                local_0->local_9 = 1;
            }

            func_800DBEFC(
                param_0->unk0->unk4,
                0xB,
                local_8
            );

            func_800DBEFC(
                param_0->unk0->unk4,
                8,
                local_9
            );

            func_800EF04C(local_8, local_9);
            func_800EF334(local_8, 0.5f);

            local_0->local_3 =
                func_800F1DF4(
                    (f32 *)&param_0->actorData[4],
                    local_8
                );

            local_0->local_4 =
                -func_800F1828(
                    (f32 *)&param_0->actorData[4],
                    local_8
                );
        }

        if (local_0->local_8 > 0) {
            (local_0->local_8)--;
        }
    }

    switch (param_0->unk70_10) {
        case 1: {
            s32 local_2;
            s32 local_12;
            s32 local_13;
            if (func_8010CAC0(
                    D_808020D4_chlakemonster,
                    0xBE)) {

                if (func_80090248()) {
                    local_2 = 6;

                    local_12 = func_8008FD70() == 1;
                    local_13 = func_800C6E38(0x15);
                    if (local_12 && local_13) {

                        if (!func_800DA298(0x1B9)) {
                            _chintrotext_entrypoint_1(
                                0x18B9,
                                2,
                                1,
                                0
                            );

                            func_800DA544(0x1B9);
                            local_2 = 2;
                        } else {
                            local_2 = 4;
                        }
                    }

                    func_80801494_chlakemonster(
                        param_0,
                        local_2
                    );
                }
            }
            break;

        }
        case 2:
            if (func_80090298()) {
                func_80090840(
                    (f32 *)&param_0->actorData[4]
                );
            }

            func_80800A14_chlakemonster(
                param_0,
                0,
                local_1
            );

            if (param_0->unk7C_12
                && local_0->local_7 != 0) {
                func_800907C0(
                    (f32 *)&param_0->actorData[4]
                );
            }
            break;

        case 3: {
            LakeMonsterAnimationPoints local_10;
            f32 local_11[3];

            local_10 = *(LakeMonsterAnimationPoints *)D_808021EC_chlakemonster;

            if (local_1 != 0) {
                func_8080064C_chlakemonster(param_0);
            }

            if (func_80101E14(param_0, 0.4f)) {
                func_808008E8_chlakemonster(param_0);
                func_808001C0_chlakemonster(param_0);
            } else if (func_80101E4C(param_0, local_10.local_0)) {
                func_80800968_chlakemonster(param_0);
                func_808001C0_chlakemonster(param_0);
            }

            if (func_80101DDC(param_0)) {
                func_80801494_chlakemonster(param_0, 5);
            }

            if (param_0->unk7C_12
                && local_0->local_7 != 0) {

                func_800EE7F8(
                    local_11,
                    (f32 *)&param_0->actorData[4]
                );

                local_11[1] -= 275.0f;

                func_800906B0(local_11);

                if (func_80101E14(param_0, 0.4f)) {
                    func_80090708(0);
                    func_80090590(
                        0x2F,
                        D_808021F8_chlakemonster
                    );
                    func_8009086C(1);

                    local_0->local_7 = 0;
                }
            }
            break;

        }
        case 4:
            if (func_80090298()) {
                func_80090840(
                    (f32 *)&param_0->actorData[4]
                );
            }

            if (local_1 != 0) {
                func_8080064C_chlakemonster(param_0);
            }

            if (func_80101E14(param_0, 0.07f)) {
                func_80800968_chlakemonster(param_0);
            } else if (func_80101E14(param_0, 0.8f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    (f32 *)&param_0->actorData[4],
                    D_8080207C_chlakemonster
                );

                local_0->local_7 = 1;

                func_8009086C(0);
            } else if (func_80101E14(param_0, 0.7f)) {
                func_808008E8_chlakemonster(param_0);
            } else if (func_80101DDC(param_0)) {
                func_808009CC_chlakemonster();
            }

            if (param_0->unk7C_12
                && local_0->local_7 != 0) {
                func_800907C0(
                    (f32 *)&param_0->actorData[4]
                );
            }
            break;

        case 5:
            if (!func_8010CB84(
                    D_808020D4_chlakemonster,
                    0xC8)) {
                func_80801494_chlakemonster(
                    param_0,
                    1
                );
            }
            break;

        case 6:
            break;

        case 7:
            func_80800A14_chlakemonster(
                param_0,
                1,
                local_1
            );
            break;
    }

    if (local_0 != 0) {
        if (local_0->local_5 > 0.0f) {
            local_0->local_5 -=
                func_800D8FF8();
        }

        if (local_0->local_6 > 0.0f) {
            local_0->local_6 -=
                func_800D8FF8();
        }

        if (param_0->unk7C_12) {
            f32 local_4;
            f32 local_5;
            s32 local_3;

            local_4 = func_800D8FF8();
            local_5 = func_80101F24(param_0);

            if (local_0->local_5 <= 0.0f
                && local_0->local_6 <= 0.0f) {

                local_3 = 0;

                switch (func_801022E4(param_0)) {
                    case 0x169:
                        if (local_5 < 0.61f
                            || local_5 > 0.77f) {
                            local_3 = 1;
                        }
                        break;

                    case 0x1FD:
                    case 0x1FE:
                        local_3 = 1;
                        break;
                }

                if (local_3 != 0) {
                    if (local_0->local_2 > 0.0f) {
                        local_0->local_2 -= local_4;
                    } else {
                        local_0->local_2 = 2.5f;

                        if (param_0->unk64_19) {
                            _subaddieaudioquick_entrypoint_2(
                                param_0,
                                (f32 *)&param_0->actorData[4],
                                D_8080208C_chlakemonster
                            );

                            if (local_1 != 0) {
                                func_808002FC_chlakemonster(param_0);
                            } else {
                                func_80800404_chlakemonster(param_0);
                            }

                            param_0->unk64_19 = 0;
                        } else {
                            _subaddieaudioquick_entrypoint_2(
                                param_0,
                                param_0->position,
                                D_808020A4_chlakemonster
                            );

                            param_0->unk64_19 = 1;
                        }
                    }
                }
            }
        }
    }
}

void func_808013E8_chlakemonster(s32 param_0[3])
{
    func_8008F8B0();
    func_8008F964(&D_808020D4_chlakemonster);
    func_8008F8D8(0);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, param_0[0]);
    func_8008F9C4(&D_808020D4_chlakemonster, 0.75f);
}

void func_80801448_chlakemonster(FarmerState *param_0, s32 param_1, s32 param_2) {
    param_2 |= 7;
    _subaddiedialog_entrypoint_11(param_0->f0, param_1, param_2, &param_0->f4, 0xb3);
    param_0->flag = 1;
}

void func_80801494_chlakemonster(param_0, param_1) Actor *param_0; s32 param_1;
{
  void *local_0;
  local_0 = func_80100094(param_0, 0);
  switch (param_0->unk70_10)
  {
    case 1:
      func_80100074(param_0, 0, 0x40);
      local_0 = func_80100094(param_0, 0);
      *((u8 *) (((char *) local_0) + 0x3C)) = 0;
      *((u8 *) (((char *) local_0) + 0x3D)) = 0;
      *((u8 *) (((char *) local_0) + 0x3E)) = 0;
      *((float *) (((char *) local_0) + 0x18)) = 0.0f;
      func_80090658(1);
      param_0->unk64_16 = 1;
      break;

    case 2:
      func_800FDC28(0);
      break;

  }

  func_80102424(param_0, param_1);
  switch (param_1)
  {
    case 7:
      func_80101EE4(param_0, 0.35f);
      return;

    case 1:
      param_0->unk64_16 = 0;
      func_80090658(0);
      func_80100074(param_0, 0, 0);
      return;

    case 2:
      func_808013E8_chlakemonster(param_0);
      func_800FDC28(1);
      _capod_entrypoint_13(param_0->unk0, 0, 6, 0x20);
      return;

    case 3:
      _capod_entrypoint_13(param_0->unk0, 0, 8, 0x10);
      func_800F7B9C(func_800F54E4(), 0x96);
      *((u8 *) (((char *) local_0) + 0x3D)) = 1;
      func_8009086C(0);
      func_80090658(0);
      func_80090708(2);
      return;

    case 4:
      func_808013E8_chlakemonster(param_0);
      _capod_entrypoint_13(param_0->unk0, 0, 0xa, 0x20);
      return;

    case 5:
      param_0->unk64_16 = 0;
      return;

    case 6:
      func_80090658(0);
      param_0->unk64_16 = 0;
      if (func_800C6E38(0x15) == 0)
    {
      func_80801448_chlakemonster(param_0, 0x1819, 0);
      return;
    }
      func_80801448_chlakemonster(param_0, 0x180E, 0);
      return;

    case 0:
    default:
      return;

  }

}

s32 func_808016B0_chlakemonster(Actor *param_0, s32 param_1, LakeMonsterEvent param_2)
{
    switch (param_1) {
        case 0x32: func_80090708(2); break;
        case 0x2E:
            param_0->unk74_30 = 0;
            if (param_2.local_1[0] == 0x180E) func_80801494_chlakemonster(param_0, 5);
            break;
        case 0x49:
            if (func_800DA9E4(0x6E8, 0)) func_80801494_chlakemonster(param_0, 3);
            break;
        case 0x1F: func_80800838_chlakemonster(param_0); break;
        default: return 0;
    }
    return 1;
}

int chlakemonster_entrypoint_0()
{
    return &D_80802204_chlakemonster;
}

void func_80801790_chlakemonster(Actor *param_0, s32 param_1) {
    s32 *local_0 = (s32 *) param_0;
    u32 local_1;

    func_80101FDC(param_0, param_1);
    local_1 = (u32)((u16) (*(u16 *)((char *)(local_0) + 0x72))) >> 0xA;
    switch (local_1) {
    case 1:
        *(f32 *)((char *)(local_0) + 0x8) = -1000.0f;
        return;
    case 3:
        *(u8 *)((char *)(local_0) + 0x7E) = (u8) ((*(u8 *)((char *)(local_0) + 0x7E)) & 0xFFBF);
        *(f32 *)((char *)(local_0) + 0x8) = 0.0f;
        return;
    case 2:
        _capod_entrypoint_13(*(Actor **)((char *)(local_0) + 0x0), 0, 0, 0x10);
        *(f32 *)((char *)(local_0) + 0x34) = 0.0f;
        *(f32 *)((char *)(local_0) + 0x50) = 50.0f;
        return;
    }
}

void func_80801834_chlakemonster(Actor *param_0)
{
    func_800EE7F8((f32 *)param_0->actorData, param_0->position);
    func_800EFA4C(param_0->position, 0.0f, 0.0f, 0.0f);
    if (func_800DA298(0x187)) {
        func_80801790_chlakemonster(param_0, 3);
    } else {
        func_80801790_chlakemonster(param_0, 1);
    }
}

void func_808018AC_chlakemonster(s32 arg0) 
{
}
s32 chlakemonster_entrypoint_1(s32 param_0) {
    _fxripple_entrypoint_0(0);
}

void chlakemonster_entrypoint_2(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3)
{
    s32 local_0;

    local_0 = func_800B53A4(6);
    func_800BA568(local_0, (s16)param_3);
    func_800BA544(local_0, _chlakemonster_entrypoint_1);
    if (func_800DC298(0.5f)) {
        param_1[0] -= 100.0f;
        param_0[0] -= 100.0f;
    } else {
        param_1[0] += 100.0f;
        param_0[0] += 100.0f;
    }
    func_800BABB8(local_0, param_1, NULL, 1.0f, D_8080224C_chlakemonster);
    func_800BA1D0(local_0, param_0, param_1, 6);
}

void chlakemonster_entrypoint_3(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3)
{
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(3);
    sp24 = temp_v0;
    (*(f32 *)((s8 *)(param_1) + (4))) = (f32) ((*(f32 *)((s8 *)(param_1) + (4))) + 200.0f);
    (*(f32 *)((s8 *)(param_0) + (4))) = (f32) ((*(f32 *)((s8 *)(param_0) + (4))) + 200.0f);
    func_800BABB8(temp_v0, param_1, 0, 1.0f, &D_8080229C_chlakemonster);
    func_800BA1D0(sp24, param_0, param_1, 3);
}

void func_80801A60_chlakemonster(Actor *param_0)
{
    f32 vecA[3];
    f32 vecB[3];

    switch (param_0->unk70_10) {
    case 1:
        return;
    case 2:
        if (param_0->position[1] >= 0.0f) {
            func_80801790_chlakemonster((u8 *)param_0, 3);
            return;
        }
        param_0->position[1] = func_800D8FF8() * param_0->unk50 + param_0->position[1];
        param_0->unk50 = param_0->unk50 + 5.0f;
        if (func_8001210C(1)) {
            vecA[1] = param_0->position[1] + -3050.0f;
            vecB[1] = vecA[1];
            switch (func_800DC128(0, 3)) {
            case 0:
                vecA[0] = 30.0f;
                vecA[2] = 735.0f;
                vecB[0] = 504.0f;
                vecB[2] = 1423.0f;
                chlakemonster_entrypoint_2(vecA, vecB, 50.0f, -3050.0f);
                chlakemonster_entrypoint_3(vecA, vecB, 50.0f, -3050.0f);
                break;
            case 1:
                vecB[0] = 504.0f;
                vecB[2] = 1423.0f;
                vecA[0] = -194.0f;
                vecA[2] = 2263.0f;
                chlakemonster_entrypoint_2(vecA, vecB, 50.0f, -3050.0f);
                chlakemonster_entrypoint_3(vecA, vecB, 50.0f, -3050.0f);
                break;
            case 2:
                vecA[0] = -194.0f;
                vecA[2] = 2263.0f;
                vecB[0] = 4.0f;
                vecB[2] = 3081.0f;
                chlakemonster_entrypoint_2(vecA, vecB, 50.0f, -3050.0f);
                chlakemonster_entrypoint_3(vecA, vecB, 50.0f, -3050.0f);
                break;
            default:
                break;
            }
            if (param_0->unk58 <= 0.0f) {
                _subaddieaudioquick_entrypoint_2(param_0, vecB, D_808020BC_chlakemonster);
                param_0->unk58 = func_800DC178(1.0f, 2.0f) * 0.15f;
            } else {
                param_0->unk58 = param_0->unk58 - func_800D8FF8();
            }
        }
        if (param_0->unk5F == 0) {
            param_0->unk5F = func_800C4350(0, param_0->position, D_808022C8_chlakemonster);
            return;
        }
        if (param_0->position[1] < -750.0f) {
            (*(f32 *)&param_0->actorData[7]) = func_800F10B4(param_0->position[1], -1000.0f, -850.0f, 0.0f, 32000.0f);
        }
        param_0->unk54 = func_800F10B4(param_0->position[1], -1000.0f, 0.0f, 0.05f, 1.0f);
        func_800C3058(param_0->unk5F, (s32)(*(f32 *)&param_0->actorData[7]));
        func_800C31DC(param_0->unk5F, param_0->unk54);
        func_800C4350(param_0->unk5F, (u8 *)param_0->actorData, 0);
        return;
    case 3:
        if (param_0->unk5F == 0) {
            return;
        }
        if ((*(f32 *)&param_0->actorData[7]) > 500.0f) {
            (*(f32 *)&param_0->actorData[7]) = (*(f32 *)&param_0->actorData[7]) * 0.7f;
            if (0.05f < param_0->unk54) {
                param_0->unk54 = param_0->unk54 * 0.7f;
            }
            func_800C3058(param_0->unk5F, (s32)(*(f32 *)&param_0->actorData[7]));
            func_800C31DC(param_0->unk5F, param_0->unk54);
            func_800C4350(param_0->unk5F, (u8 *)param_0->actorData, 0);
            return;
        }
        func_800C2FDC(param_0->unk5F);
        param_0->unk5F = 0;
        return;
    default:
        return;
    }
}

s32 func_80801E60_chlakemonster(Actor *this, s32 param_1, s32 param_2)
{
  Actor *new_var;
  if (param_1 == 0x7)
  {
    new_var = this;
    func_80801790_chlakemonster(new_var, 2);
  }
  else
  {
    return 0;
  }
  return 1;
}

int chlakemonster_entrypoint_4()
{
  return (int)&D_808022E0_chlakemonster;
}

s32 func_80801EA8_chlakemonster(s32 param_0){
    _chswitch_entrypoint_14(param_0, 0x187);
    if(func_800DA298(0x187))
        func_8010A570(param_0);
}

void func_80801EE4_chlakemonster(s32 arg0) 
{
}
s32 func_80801EEC_chlakemonster(s32 param_0, s32 param_1, s32 param_2)
{
  int new_var;
  if (param_1 == 7)
  {
    func_80101180(0x301, 7, 0);
    new_var = 1;
    func_8010A570(param_0);
    goto func_80801EEC_chlakemonster_end;
    return new_var;
  }
  new_var = 0;
  return 0;
  func_80801EEC_chlakemonster_end:
  return new_var;

}

int chlakemonster_entrypoint_5()
{
    return &D_80802328_chlakemonster;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/lakemonster.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80802044_chlakemonster -> float[], D_80802204_chlakemonster -> int[], D_808022E0_chlakemonster -> int[], D_80802328_chlakemonster -> int[] */
extern void func_80105834();
extern void func_801018A4();
extern void func_80107C2C();
extern void func_80101870();
extern void _chswitch_entrypoint_13();
extern void _chswitch_entrypoint_0();
u32 D_80801FF0_chlakemonster[16] = { 0x0, 0x0, 0x424C0000, 0x1690044, 0x41880000, 0x1690042, 0x40F66666, 0x1FD0042, 0x4019999A, 0x1FE0042, 0x40F66666, 0x1FD0084, 0x424C0000, 0x1690044, 0x41880000, 0x1690002 };
u8 D_80802030_chlakemonster[20] = { 0x0, 0x13, 0x5, 0x4F, 0x0, 0xD, 0x0, 0xF3, 0x1, 0x0, 0x0, 0x18, 0x0, 0x1, 0x9, 0xC4, 0x13, 0x88, 0x0, 0x0 };
float D_80802044_chlakemonster[5] = { 1.746777e-39f, 1.194202e-39f, 2.3509954e-38f, 9.5339e-41f, 3.4331227e-27f };
s32 D_80802058_chlakemonster[9] = { 0x130551, 0xD00CC, 0xE60018, 0x109C4, 0x13880000, 0x1304EF, 0x180001, 0x9C41388, 0x0 };
s32 D_8080207C_chlakemonster[4] = { 0x130554, 0x180001, 0x9C41388, 0x0 };
u8 D_8080208C_chlakemonster[24] = { 0x0, 0x13, 0x5, 0x50, 0x0, 0xD, 0x0, 0xD9, 0x0, 0xF3, 0x0, 0x16, 0x3E, 0x80, 0x0, 0x1, 0x9, 0xC4, 0x13, 0x88, 0x0, 0x0, 0x0, 0x0 };
u8 D_808020A4_chlakemonster[24] = { 0x0, 0x13, 0x5, 0x50, 0x0, 0xD, 0x1, 0xF, 0x1, 0x28, 0x0, 0x16, 0x3E, 0x80, 0x0, 0x1, 0x9, 0xC4, 0x13, 0x88, 0x0, 0x0, 0x0, 0x0 };
u8 D_808020BC_chlakemonster[24] = { 0x0, 0x13, 0x3, 0xED, 0x0, 0xD, 0x0, 0x66, 0x0, 0x80, 0x0, 0x16, 0x2E, 0xE0, 0x0, 0x1, 0x9, 0xC4, 0x13, 0x88, 0x0, 0x0, 0x0, 0x0 };
f32 D_808020D4_chlakemonster[3] = { 0.0f, -1.9e+03f, 0.0f };
u8 D_808020E0_chlakemonster[40] = { 0x0, 0x1D, 0x9, 0xF3, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xB4, 0x0, 0x1B, 0xF2, 0x54, 0xF2, 0x54, 0x0, 0x7, 0x0, 0x1, 0x0, 0x15, 0x0, 0x0, 0x0, 0xCC, 0x0, 0x2B, 0x0, 0x80, 0x1, 0x0, 0x0, 0x16, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802108_chlakemonster[36] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x2, 0x0, 0x80, 0x2, 0x0, 0x22, 0x0, 0x80, 0x0, 0x80, 0x5, 0x80, 0x7, 0x80, 0x0, 0x15, 0x0, 0x33, 0x0, 0x80, 0x0, 0x2B, 0x0, 0x19, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080212C_chlakemonster[36] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x2, 0x0, 0x80, 0x2, 0x0, 0x22, 0x0, 0x0, 0x0, 0x0, 0x1, 0xCC, 0x2, 0x80, 0x0, 0x15, 0x0, 0x0, 0x0, 0x80, 0x0, 0x2B, 0x1, 0x99, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802150_chlakemonster[36] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x2, 0x0, 0x80, 0x2, 0x0, 0x22, 0x0, 0x0, 0x0, 0x0, 0x0, 0xCC, 0x1, 0x80, 0x0, 0x15, 0x0, 0x0, 0x0, 0x4C, 0x0, 0x2B, 0x1, 0x99, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0 };
LakeMonsterEffectBones D_80802174_chlakemonster[8] = { 0x4, 0x9, 0x9, 0xB, 0xB, 0xA, 0xA, 0x5, 0x5, 0x7, 0x7, 0x8, 0x8, 0x6, 0x6, 0x4 };
s32 D_808021B4_chlakemonster[5] = { 0x3D71A9FC, 0x3ED1EB85, 0x3F47AE14, 0x3F70A3D7, -0x40800000 };
s32 D_808021C8_chlakemonster[2] = { 0x3E75C28F, -0x40800000 };
s32 D_808021D0_chlakemonster[5] = { 0x3F1C28F6, 0x3F2B851F, 0x3F326E98, 0x3F400000, -0x40800000 };
s32 D_808021E4_chlakemonster[2] = { 0x3CBC6A7F, -0x40800000 };
f32 D_808021EC_chlakemonster[3] = { 0.55f, 0.75f, -1.0f };
u8 D_808021F8_chlakemonster[12] = { 0x0, 0x0, 0x0, 0x0, 0xC4, 0xED, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0 };
int D_80802204_chlakemonster[18] = { 0x2E50300, 0x6D50001, (u32)&D_80801FF0_chlakemonster, (u32)func_80800C88_chlakemonster, (u32)func_80105834, (u32)func_801018A4, 0x0, 0x0, 0x0, 0x8046C, (u32)func_80800064_chlakemonster, 0x0, 0x0, (u32)func_80800000_chlakemonster, (u32)func_80107C2C, -0x7F7FFFFE, (u32)func_808016B0_chlakemonster, 0x0 };
u8 D_8080224C_chlakemonster[80] = { 0x0, 0x1D, 0x9, 0xD9, 0x0, 0x16, 0x0, 0x4, 0x0, 0x1B, 0x0, 0x96, 0x0, 0x96, 0x0, 0x7, 0x0, 0x1, 0x0, 0x15, 0x0, 0x0, 0x0, 0xCC, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0, 0x2F, 0x0, 0x40, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x19, 0x0, 0x0, 0x0, 0x33, 0x0, 0x2B, 0x0, 0x80, 0x0, 0xC0, 0x0, 0x22, 0x0, 0xC, 0x0, 0x19, 0x0, 0x26, 0x0, 0x59, 0x0, 0x2C, 0xFF, 0xD8, 0x1, 0x90, 0xFF, 0xD8, 0x0, 0x28, 0x1, 0xF4, 0x0, 0x28, 0x0, 0x0, 0x0, 0x0 };
int D_8080229C_chlakemonster[11] = { 0x1D09DD, 0x2A0000, 0x190180, 0x1800015, 0x3300B3, 0x160200, 0x20C4C4, -0x9FFFDE, 0x8000C0, 0x1800280, 0x0 };
u8 D_808022C8_chlakemonster[24] = { 0x2, 0x6, 0x0, 0x13, 0x3, 0xEC, 0x0, 0xA, 0x0, 0x25, 0x0, 0x16, 0x0, 0x0, 0x0, 0x1, 0x9, 0xC4, 0x13, 0x88, 0x0, 0x0, 0x0, 0x0 };
int D_808022E0_chlakemonster[18] = { 0x2E60301, 0x74B0001, 0x0, (u32)func_80801A60_chlakemonster, (u32)func_80105834, (u32)func_80101870, 0x17700000, 0x0, 0x0, 0xC00, (u32)func_808018AC_chlakemonster, 0x0, 0x0, (u32)func_80801834_chlakemonster, (u32)func_80107C2C, -0x7FF7FBFE, (u32)func_80801E60_chlakemonster, 0x0 };
int D_80802328_chlakemonster[18] = { 0x2E70370, 0x94B0001, -0x7FEE5D68, (u32)_chswitch_entrypoint_13, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x808, (u32)func_80801EE4_chlakemonster, (u32)_chswitch_entrypoint_0, 0x0, (u32)func_80801EA8_chlakemonster, (u32)func_80107C2C, -0x7FF7F400, (u32)func_80801EEC_chlakemonster, 0x0 };
