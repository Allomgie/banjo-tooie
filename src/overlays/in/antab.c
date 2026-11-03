#include "common.h"

extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800DC178(f32, f32);
extern void func_80101CDC(Actor *, f32);
typedef struct { f32 local_0; f32 local_1; f32 local_2; f32 local_3; s32 local_4; u8 local_5; u8 local_6; u8 pad_0[2]; } AntabEffectPreset;
extern AntabEffectPreset D_80806E30_inantab[];
extern s32 func_800E1540(s32);
extern s32 func_800E1664(s32, f32, f32, s32, s32, s16);
extern void func_800E13F0(s32, f32);
extern void func_800E1410(s32, f32, f32);
extern void func_800E144C(s32, f32);
extern u32 *D_80806D5C_inantab;
extern void _anseq_entrypoint_2(s16 *, f32, void *, s32, s32);
extern void _anseq_entrypoint_3(s16 *, f32, void *, s32, s32, s32);
extern void _chanim_entrypoint_4(void *, f32, s32, s32, s32);
extern void _anseq_entrypoint_4(s16 *, f32, void *, s32, s32, s32, s32);
extern void _chanim_entrypoint_5(void *, f32, s32, s32, s32);
s32 func_80800020_inantab();
s32 func_808057BC_inantab();

void inantab_entrypoint_0()
{
    func_800BF744();
}

s32 func_80800020_inantab(param_0, param_1, param_2) s32 param_0; s32 param_1; void *param_2;
{
    extern f32 D_80806F80_inantab[];
    extern f32 D_80806F8C_inantab[];
    extern f32 D_80806F98_inantab[];
    extern f32 D_80806FA4_inantab[];
    extern f32 D_80806FB0_inantab[];
    extern f32 D_80806FD8_inantab[];
    extern f32 D_80806FE0_inantab[];
    extern f32 D_80807038_inantab[];
    extern f32 D_80807040_inantab[];
    extern f32 D_8080704C_inantab[];
    extern f32 D_80807058_inantab[];
    extern f32 D_80807064_inantab[];
    extern f32 D_80807070_inantab[];
    extern f32 D_8080707C_inantab[];
    extern f32 D_80807088_inantab[];
    extern f32 D_80807094_inantab[];
    extern f32 D_808070A0_inantab[];
    extern f32 D_808070C8_inantab[];
    extern f32 D_808070D0_inantab[];
    extern f32 D_808070D4_inantab[];
    extern f32 D_808070F8_inantab[];
    extern f32 D_80807120_inantab[];
    extern f32 D_80807144_inantab[];
    extern f32 D_8080716C_inantab[];
    extern f32 D_80807190_inantab[];
    extern f32 D_808071B8_inantab[];
    extern f32 D_808071C0_inantab[];
    extern f32 D_808071C8_inantab[];
    extern f32 D_80807238_inantab[];
    extern f32 D_80807248_inantab[];
    extern f32 D_80807250_inantab[];
    extern f32 D_80807260_inantab[];
    extern f32 D_8080726C_inantab[];
    extern f32 D_80807274_inantab[];
    extern f32 D_80807280_inantab[];
    extern f32 D_8080728C_inantab[];
    extern f32 D_80807298_inantab[];
    extern f32 D_808072A4_inantab[];
    extern f32 D_808072B0_inantab[];
    extern f32 D_808072D8_inantab[];
    extern f32 D_808072E0_inantab[];
    extern f32 D_8080730C_inantab[];
    extern f32 D_80807354_inantab[];
    extern f32 D_808073A8_inantab[];
    extern f32 D_80807458_inantab[];
    extern f32 D_808074AC_inantab[];
    extern f32 D_808074DC_inantab[];
    extern f32 D_808074E8_inantab[];
    extern f32 D_80807534_inantab[];
    extern f32 D_8080755C_inantab[];
    extern f32 D_80807560_inantab[];
    extern f32 D_8080756C_inantab[];
    extern f32 D_80807578_inantab[];
    extern f32 D_80807584_inantab[];
    extern f32 D_80807590_inantab[];
    extern f32 D_808075B8_inantab[];
    extern f32 D_808075C0_inantab[];
    extern f32 D_808075CC_inantab[];
    extern f32 D_808075F0_inantab[];
    extern f32 D_80807614_inantab[];
    extern f32 D_80807618_inantab[];
    extern f32 D_8080761C_inantab[];
    extern f32 D_80807640_inantab[];
    extern f32 D_80807664_inantab[];
    extern f32 D_80807684_inantab[];

    extern void func_800BFCD0();
    extern void _indrv_audio_entrypoint_0();
    extern void _indrv_fx_entrypoint_0();
    extern void _indrv_lights_entrypoint_0();
    extern void _inantab_entrypoint_0();
    extern void _inantab_entrypoint_3();


#define AN2(t, cb, a, b) \
    _anseq_entrypoint_2((s16 *)param_1, (t), (cb), (a), (b))

#define AN3(t, cb, a, b, c) \
    _anseq_entrypoint_3((s16 *)param_1, (t), (cb), (a), (b), (c))

#define CH(t, a, b) \
    _chanim_entrypoint_4((void *)param_1, (t), *(s32 *)&param_2, (a), (b))

#define FOR_AN2(first, count, cb, a, b) { \
    s32 local_0; \
    for (local_0 = 0; local_0 < (count); local_0++) { \
        AN2((first)[local_0], cb, a, b); \
    } \
}

#define FOR_AN3(first, count, cb, a, b, c) { \
    s32 local_0; \
    for (local_0 = 0; local_0 < (count); local_0++) { \
        AN3((first)[local_0], cb, a, b, c); \
    } \
}

#define FOR_CH(first, count, a, b) { \
    s32 local_0; \
    for (local_0 = 0; local_0 < (count); local_0++) { \
        CH((first)[local_0], a, b); \
    } \
}

    switch (param_0) {
        case 1:
            FOR_AN2(D_80806F80_inantab, 3, func_800BFCD0, 1, 1);
            FOR_AN2(D_80806F8C_inantab, 3, func_800BFCD0, 1, 0);
            FOR_AN2(D_80806F80_inantab, 3, func_800BFCD0, 2, 1);
            FOR_AN2(D_80806F8C_inantab, 3, func_800BFCD0, 2, 0);
            FOR_AN2(D_80806F80_inantab, 3, func_800BFCD0, 3, 1);
            FOR_AN2(D_80806F8C_inantab, 3, func_800BFCD0, 3, 0);

            FOR_AN2(D_80806F98_inantab, 3, func_800BFCD0, 4, 1);
            FOR_AN2(D_80806FA4_inantab, 3, func_800BFCD0, 4, 0);
            FOR_AN2(D_80806F98_inantab, 3, func_800BFCD0, 5, 1);
            FOR_AN2(D_80806FA4_inantab, 3, func_800BFCD0, 5, 0);
            FOR_AN2(D_80806F98_inantab, 3, func_800BFCD0, 6, 1);
            FOR_AN2(D_80806FA4_inantab, 3, func_800BFCD0, 6, 0);

            FOR_AN3(D_80806F80_inantab, 3, _indrv_lights_entrypoint_0, 0x10000, 0x7CCBFF00, 0);
            FOR_AN3(D_80806F8C_inantab, 3, _indrv_lights_entrypoint_0, 0x10000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80806F98_inantab, 3, _indrv_lights_entrypoint_0, 0x10000, 0x7CCBFF00, 0);
            FOR_AN3(D_80806FA4_inantab, 3, _indrv_lights_entrypoint_0, 0x10000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80806F80_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x7CCBFF00, 0);
            FOR_AN3(D_80806F8C_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0, 0x19);
            FOR_AN3(D_80806F98_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x7CCBFF00, 0);
            FOR_AN3(D_80806FA4_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0, 0x19);

            FOR_AN3(D_80806F80_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0x7CCBFF00, 0);
            FOR_AN3(D_80806F8C_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0, 0x19);
            FOR_AN3(D_80806F98_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0x7CCBFF00, 0);
            FOR_AN3(D_80806FA4_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0, 0x19);

            FOR_AN3(D_80806F80_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x7CCBFF00, 0);
            FOR_AN3(D_80806F8C_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0, 0x19);
            FOR_AN3(D_80806F98_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x7CCBFF00, 0);
            FOR_AN3(D_80806FA4_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0, 0x19);

            FOR_AN3(D_80806F80_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0x7CCBFF00, 0);
            FOR_AN3(D_80806F8C_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0, 0x19);
            FOR_AN3(D_80806F98_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0x7CCBFF00, 0);
            FOR_AN3(D_80806FA4_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0, 0x19);

            FOR_AN3(D_80806FD8_inantab, 2, _indrv_audio_entrypoint_0, *(s32 *)&param_2, 1, -2);
            return 1;

        case 43:
            CH(0.0f, 5, 0);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 0);
            return 1;

        case 44:
            CH(0.0f, 5, 0);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 0);
            return 1;

        case 45:
            CH(0.0f, 5, 0);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 0);
            return 1;

        case 46:
            CH(0.0f, 5, 0);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 0);
            return 1;

        case 47:
            CH(0.0f, 5, 0);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 0);
            return 1;

        case 48:
            CH(0.0f, 5, 1);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 1);
            return 1;

        case 49:
            CH(0.0f, 5, 1);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 1);
            return 1;

        case 50:
            CH(0.0f, 5, 1);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 1);
            return 1;

        case 51:
            CH(0.0f, 5, 1);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 1);
            return 1;

        case 90:
            CH(0.0f, 5, 0);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 0);
            CH(0.0f, 9, 1);
            CH(0.980000019f, 9, 0);
            return 1;

        case 91:
            CH(0.0f, 5, 0);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 0);
            CH(0.0f, 9, 0);
            return 1;

        case 7:
            FOR_AN3(D_80807038_inantab, 2, _indrv_audio_entrypoint_0, *(s32 *)&param_2, 2, -2);
            return 1;

        case 8:
            FOR_CH(D_80807040_inantab, 3, 1, 1);
            FOR_CH(D_8080704C_inantab, 3, 1, 0);
            FOR_CH(D_80807058_inantab, 3, 1, 1);
            FOR_CH(D_80807064_inantab, 3, 1, 0);
            return 1;

        case 9:
            FOR_AN2(D_80807070_inantab, 3, func_800BFCD0, 1, 1);
            FOR_AN2(D_8080707C_inantab, 3, func_800BFCD0, 1, 0);
            FOR_AN2(D_80807070_inantab, 3, func_800BFCD0, 2, 1);
            FOR_AN2(D_8080707C_inantab, 3, func_800BFCD0, 2, 0);
            FOR_AN2(D_80807070_inantab, 3, func_800BFCD0, 3, 1);
            FOR_AN2(D_8080707C_inantab, 3, func_800BFCD0, 3, 0);
            FOR_AN2(D_80807070_inantab, 3, func_800BFCD0, 4, 1);
            FOR_AN2(D_8080707C_inantab, 3, func_800BFCD0, 4, 0);
            FOR_AN2(D_80807070_inantab, 3, func_800BFCD0, 5, 1);
            FOR_AN2(D_8080707C_inantab, 3, func_800BFCD0, 5, 0);
            FOR_AN2(D_80807070_inantab, 3, func_800BFCD0, 6, 1);
            FOR_AN2(D_8080707C_inantab, 3, func_800BFCD0, 6, 0);

            FOR_AN2(D_80807088_inantab, 3, func_800BFCD0, 1, 1);
            FOR_AN2(D_80807094_inantab, 3, func_800BFCD0, 1, 0);
            FOR_AN2(D_80807088_inantab, 3, func_800BFCD0, 2, 1);
            FOR_AN2(D_80807094_inantab, 3, func_800BFCD0, 2, 0);
            FOR_AN2(D_80807088_inantab, 3, func_800BFCD0, 3, 1);
            FOR_AN2(D_80807094_inantab, 3, func_800BFCD0, 3, 0);
            FOR_AN2(D_80807088_inantab, 3, func_800BFCD0, 4, 1);
            FOR_AN2(D_80807094_inantab, 3, func_800BFCD0, 4, 0);
            FOR_AN2(D_80807088_inantab, 3, func_800BFCD0, 5, 1);
            FOR_AN2(D_80807094_inantab, 3, func_800BFCD0, 5, 0);
            FOR_AN2(D_80807088_inantab, 3, func_800BFCD0, 6, 1);
            FOR_AN2(D_80807094_inantab, 3, func_800BFCD0, 6, 0);

            FOR_AN3(D_80807070_inantab, 3, _indrv_lights_entrypoint_0, 0x10000, 0x95AFFF00, 0);
            FOR_AN3(D_8080707C_inantab, 3, _indrv_lights_entrypoint_0, 0x10000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807088_inantab, 3, _indrv_lights_entrypoint_0, 0x10000, 0x95AFFF00, 0);
            FOR_AN3(D_80807094_inantab, 3, _indrv_lights_entrypoint_0, 0x10000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807070_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x95AFFF00, 0);
            FOR_AN3(D_8080707C_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807088_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x95AFFF00, 0);
            FOR_AN3(D_80807094_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807070_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0x95AFFF00, 0);
            FOR_AN3(D_8080707C_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807088_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0xAECBFF00, 0);
            FOR_AN3(D_80807094_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807070_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x95AFFF00, 0);
            FOR_AN3(D_8080707C_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807088_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x7CCBFF00, 0);
            FOR_AN3(D_80807094_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807070_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x95AFFF00, 0);
            FOR_AN3(D_8080707C_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807088_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x7CCBFF00, 0);
            FOR_AN3(D_80807094_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807070_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0x95AFFF00, 0);
            FOR_AN3(D_8080707C_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807088_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0x95AFFF00, 0);
            FOR_AN3(D_80807094_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807070_inantab, 3, _indrv_lights_entrypoint_0, 0x80000, 0x95AFFF00, 0);
            FOR_AN3(D_8080707C_inantab, 3, _indrv_lights_entrypoint_0, 0x80000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807088_inantab, 3, _indrv_lights_entrypoint_0, 0x80000, 0x95AFFF00, 0);
            FOR_AN3(D_80807094_inantab, 3, _indrv_lights_entrypoint_0, 0x80000, 0x6D87FF00, 0x19);

            FOR_AN3(D_808070C8_inantab, 2, _indrv_audio_entrypoint_0, *(s32 *)&param_2, 1, -2);
            return 1;

        case 10:
            FOR_AN3(D_808070D0_inantab, 1, _indrv_lights_entrypoint_0, 0x60000, 0x00FF0000, 0x100);
            return 1;

        case 25:
            AN3(0.01f, _inantab_entrypoint_3, *(s32 *)&param_2, 6, -1);
            return 1;

        case 11:
            CH(0.01f, 3, 1);
            CH(0.01f, 4, 1);
            CH(0.01f, 9, 1);
            CH(0.01f, 10, 0);
            CH(0.01f, 11, 0);
            CH(0.01f, 5, 1);
            CH(0.01f, 6, 1);
            CH(0.01f, 7, 0);
            return 1;

        case 52:
            CH(0.01f, 3, 1);
            CH(0.01f, 4, 1);
            CH(0.01f, 9, 1);
            CH(0.01f, 10, 0);
            CH(0.01f, 11, 0);
            CH(0.01f, 5, 1);
            CH(0.01f, 6, 1);
            CH(0.01f, 7, 0);
            return 1;

        case 53:
            CH(0.01f, 3, 1);
            CH(0.01f, 4, 1);
            CH(0.01f, 9, 1);
            CH(0.01f, 10, 0);
            CH(0.01f, 11, 0);
            CH(0.01f, 5, 1);
            CH(0.01f, 6, 1);
            CH(0.01f, 7, 0);
            return 1;

        case 56:
            CH(0.01f, 3, 1);
            CH(0.01f, 4, 1);
            CH(0.01f, 9, 1);
            CH(0.01f, 10, 0);
            CH(0.01f, 11, 0);
            CH(0.01f, 5, 1);
            CH(0.01f, 6, 1);
            CH(0.01f, 7, 0);
            return 1;

        case 54:
            CH(0.01f, 3, 1);
            CH(0.01f, 4, 1);
            CH(0.01f, 9, 1);
            CH(0.01f, 10, 0);
            CH(0.01f, 11, 0);
            CH(0.01f, 5, 0);
            CH(0.01f, 6, 0);
            CH(0.01f, 7, 0);
            return 1;

        case 98:
            CH(0.0f, 3, 1);
            CH(0.0f, 4, 1);
            CH(0.0f, 9, 1);
            CH(0.0f, 10, 0);
            CH(0.0f, 11, 0);
            CH(0.0f, 5, 0);
            CH(0.0f, 6, 0);
            CH(0.0f, 7, 1);
            return 1;

        case 106:
            CH(0.01f, 3, 1);
            CH(0.01f, 4, 1);
            CH(0.01f, 5, 1);
            CH(0.01f, 6, 1);
            CH(0.01f, 7, 1);
            CH(0.01f, 0x32, 1);
            CH(0.01f, 0x33, 1);
            return 1;

        case 107:
            CH(0.01f, 3, 1);
            CH(0.01f, 4, 0);
            CH(0.01f, 9, 0);
            CH(0.01f, 10, 0);
            CH(0.01f, 11, 0);
            CH(0.01f, 5, 0);
            CH(0.01f, 6, 0);
            CH(0.01f, 7, 0);
            return 1;
        case 12:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 1);
            CH(0.01f, 4, 0);
            CH(0.01f, 5, 1);
            CH(0.01f, 6, 0);
            return 1;

        case 92:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 0);
            CH(0.01f, 4, 0);
            CH(0.01f, 5, 0);
            CH(0.01f, 6, 0);
            return 1;

        case 93:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 0);
            CH(0.01f, 4, 0);
            CH(0.01f, 5, 0);
            CH(0.01f, 6, 0);
            FOR_AN3(D_808070D4_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 23, 6);
            FOR_AN3(D_808070F8_inantab, 10, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 23, 6);
            AN3(0.915199995f, _inantab_entrypoint_3, *(s32 *)&param_2, 3, -1);
            return 1;

        case 29:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 0);
            CH(0.01f, 4, 0);
            CH(0.01f, 5, 0);
            CH(0.01f, 6, 0);
            FOR_AN3(D_80807120_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 13, 5);
            FOR_AN3(D_80807120_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 13, 6);
            FOR_AN3(D_80807144_inantab, 10, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 13, 5);
            FOR_AN3(D_80807144_inantab, 10, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 13, 6);
            return 1;

        case 30:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 0);
            CH(0.01f, 4, 0);
            CH(0.01f, 5, 0);
            CH(0.01f, 6, 0);
            FOR_AN3(D_8080716C_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 13, 5);
            FOR_AN3(D_8080716C_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 13, 6);
            FOR_AN3(D_80807190_inantab, 10, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 13, 5);
            FOR_AN3(D_80807190_inantab, 10, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 13, 6);
            return 1;

        case 86:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 2);
            CH(0.01f, 4, 1);
            CH(0.01f, 5, 0);
            CH(0.01f, 6, 0);
            return 1;

        case 89:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 0);
            CH(0.01f, 4, 0);
            CH(0.01f, 5, 0);
            CH(0.01f, 6, 0);
            CH(0.08f, 3, 1);
            CH(0.970000029f, 3, 0);
            return 1;

        case 87:
            CH(0.0f, 4, 0);
            CH(0.0f, 3, 0);
            CH(0.0f, 4, 0);
            CH(0.0f, 5, 0);
            CH(0.0f, 6, 1);
            return 1;

        case 100:
            CH(0.0f, 4, 0);
            CH(0.0f, 3, 0);
            CH(0.0f, 4, 0);
            CH(0.0f, 5, 0);
            CH(0.0f, 6, 1);
            FOR_AN3(D_808071B8_inantab, 2, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 25, 4);
            return 1;

        case 74:
            CH(0.01f, 1, 0);
            CH(0.01f, 2, 0);
            CH(0.01f, 3, 0);
            CH(0.01f, 4, 0);
            CH(0.01f, 5, 1);
            CH(0.01f, 6, 1);
            CH(0.01f, 7, 0);
            CH(0.01f, 8, 0);
            return 1;

        case 75:
            CH(0.0f, 1, 0);
            CH(0.0f, 2, 0);
            CH(0.0f, 3, 0);
            CH(0.0f, 4, 0);
            CH(0.0f, 5, 1);
            CH(0.0f, 6, 1);
            CH(0.0f, 7, 0);
            CH(0.0f, 8, 1);
            return 1;

        case 83:
            CH(0.01f, 3, 2);
            return 1;

        case 101:
            FOR_AN3(D_808071C0_inantab, 2, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 25, 4);
            return 1;

        case 102:
            AN2(0.660000026f, _inantab_entrypoint_0, 4, 1);
            AN2(0.660000026f, _inantab_entrypoint_0, 3, 0);
            return 1;

        case 13:
            FOR_AN3(D_808071C8_inantab, 28, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 1, 4);
            FOR_AN3(D_808071C8_inantab, 28, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 1, 13);
            FOR_AN3(D_808071C8_inantab, 28, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 3, 5);
            FOR_AN3(D_80807238_inantab, 4, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 2, 7);
            FOR_AN3(D_80807248_inantab, 2, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 2, 8);
            FOR_AN3(D_80807250_inantab, 4, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 2, 9);
            FOR_AN3(D_80807260_inantab, 3, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 2, 10);
            FOR_AN3(D_8080726C_inantab, 2, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 2, 11);
            FOR_AN3(D_80807274_inantab, 3, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 2, 12);
            return 1;

        case 14:
            CH(0.0f, 3, 1);
            return 1;

        case 96:
            CH(0.0f, 3, 0);
            return 1;

        case 99:
            CH(0.0f, 3, 0);
            AN3(0.001f, _inantab_entrypoint_3, *(s32 *)&param_2, 1, -1);
            return 1;

        case 15:
            FOR_AN2(D_80807280_inantab, 3, func_800BFCD0, 1, 1);
            FOR_AN2(D_8080728C_inantab, 3, func_800BFCD0, 1, 0);
            FOR_AN2(D_80807280_inantab, 3, func_800BFCD0, 2, 1);
            FOR_AN2(D_8080728C_inantab, 3, func_800BFCD0, 2, 0);
            FOR_AN2(D_80807280_inantab, 3, func_800BFCD0, 3, 1);
            FOR_AN2(D_8080728C_inantab, 3, func_800BFCD0, 3, 0);
            FOR_AN2(D_80807280_inantab, 3, func_800BFCD0, 4, 1);
            FOR_AN2(D_8080728C_inantab, 3, func_800BFCD0, 4, 0);
            FOR_AN2(D_80807280_inantab, 3, func_800BFCD0, 5, 1);
            FOR_AN2(D_8080728C_inantab, 3, func_800BFCD0, 5, 0);
            FOR_AN2(D_80807280_inantab, 3, func_800BFCD0, 6, 1);
            FOR_AN2(D_8080728C_inantab, 3, func_800BFCD0, 6, 0);

            FOR_AN2(D_80807298_inantab, 3, func_800BFCD0, 1, 1);
            FOR_AN2(D_808072A4_inantab, 3, func_800BFCD0, 1, 0);
            FOR_AN2(D_80807298_inantab, 3, func_800BFCD0, 2, 1);
            FOR_AN2(D_808072A4_inantab, 3, func_800BFCD0, 2, 0);
            FOR_AN2(D_80807298_inantab, 3, func_800BFCD0, 3, 1);
            FOR_AN2(D_808072A4_inantab, 3, func_800BFCD0, 3, 0);
            FOR_AN2(D_80807298_inantab, 3, func_800BFCD0, 4, 1);
            FOR_AN2(D_808072A4_inantab, 3, func_800BFCD0, 4, 0);
            FOR_AN2(D_80807298_inantab, 3, func_800BFCD0, 5, 1);
            FOR_AN2(D_808072A4_inantab, 3, func_800BFCD0, 5, 0);
            FOR_AN2(D_80807298_inantab, 3, func_800BFCD0, 6, 1);
            FOR_AN2(D_808072A4_inantab, 3, func_800BFCD0, 6, 0);

            FOR_AN3(D_80807280_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x95AFFF00, 0);
            FOR_AN3(D_8080728C_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807298_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x95AFFF00, 0);
            FOR_AN3(D_808072A4_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807280_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x95AFFF00, 0);
            FOR_AN3(D_8080728C_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807298_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x7CCBFF00, 0);
            FOR_AN3(D_808072A4_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807280_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x95AFFF00, 0);
            FOR_AN3(D_8080728C_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807298_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x7CCBFF00, 0);
            FOR_AN3(D_808072A4_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807280_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0x95AFFF00, 0);
            FOR_AN3(D_8080728C_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807298_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0x95AFFF00, 0);
            FOR_AN3(D_808072A4_inantab, 3, _indrv_lights_entrypoint_0, 0x70000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807280_inantab, 3, _indrv_lights_entrypoint_0, 0x80000, 0x95AFFF00, 0);
            FOR_AN3(D_8080728C_inantab, 3, _indrv_lights_entrypoint_0, 0x80000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807298_inantab, 3, _indrv_lights_entrypoint_0, 0x80000, 0x95AFFF00, 0);
            FOR_AN3(D_808072A4_inantab, 3, _indrv_lights_entrypoint_0, 0x80000, 0x6D87FF00, 0x19);

            FOR_AN3(D_808072D8_inantab, 2, _indrv_audio_entrypoint_0, *(s32 *)&param_2, 1, -2);
            return 1;

        case 16:
            CH(0.0f, 5, 1);
            AN3(0.001f, _inantab_entrypoint_3, *(s32 *)&param_2, 2, -1);
            FOR_AN3(D_808072E0_inantab, 11, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 4, 4);
            FOR_AN3(D_8080730C_inantab, 18, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 4, 5);
            FOR_AN3(D_80807354_inantab, 21, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 4, 6);
            FOR_AN3(D_808073A8_inantab, 44, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 5, 7);
            return 1;

        case 17:
            AN3(0.697000027f, _inantab_entrypoint_3, *(s32 *)&param_2, 3, -1);
            AN3(0.99000001f, _inantab_entrypoint_3, *(s32 *)&param_2, 3, -1);
            FOR_AN3(D_80807458_inantab, 21, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 5, 8);
            FOR_AN3(D_808074AC_inantab, 12, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 5, 8);
            CH(0.0f, 5, 1);
            return 1;

        case 18:
            FOR_AN3(D_808074DC_inantab, 3, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 5, 8);
            CH(0.0f, 5, 1);
            return 1;

        case 26:
            FOR_AN3(D_808074E8_inantab, 19, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 10, 10);
            FOR_AN3(D_808074E8_inantab, 19, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 10, 11);
            CH(0.0f, 5, 1);
            return 1;

        case 19:
            CH(0.0f, 3, 1);
            return 1;

        case 20:
            CH(0.0f, 3, 1);
            return 1;

        case 21:
            CH(0.0f, 3, 1);
            AN3(0.44f, _inantab_entrypoint_3, *(s32 *)&param_2, 4, -1);
            return 1;

        case 81:
            CH(0.0f, 3, 0);
            return 1;

        case 82:
            CH(0.0f, 3, 0);
            return 1;

        case 22:
            FOR_AN3(D_80807534_inantab, 10, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x15, 4);
            AN3(0.8f, _inantab_entrypoint_3, *(s32 *)&param_2, 5, -1);
            FOR_AN3(D_8080755C_inantab, 1, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 8, 4);
            FOR_AN3(D_8080755C_inantab, 1, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 8, 4);
            return 1;

        case 23:
            FOR_AN2(D_80807560_inantab, 3, func_800BFCD0, 1, 1);
            FOR_AN2(D_8080756C_inantab, 3, func_800BFCD0, 1, 0);
            FOR_AN2(D_80807560_inantab, 3, func_800BFCD0, 2, 1);
            FOR_AN2(D_8080756C_inantab, 3, func_800BFCD0, 2, 0);
            FOR_AN2(D_80807560_inantab, 3, func_800BFCD0, 3, 1);
            FOR_AN2(D_8080756C_inantab, 3, func_800BFCD0, 3, 0);
            FOR_AN2(D_80807560_inantab, 3, func_800BFCD0, 4, 1);
            FOR_AN2(D_8080756C_inantab, 3, func_800BFCD0, 4, 0);
            FOR_AN2(D_80807560_inantab, 3, func_800BFCD0, 5, 1);
            FOR_AN2(D_8080756C_inantab, 3, func_800BFCD0, 5, 0);
            FOR_AN2(D_80807560_inantab, 3, func_800BFCD0, 6, 1);
            FOR_AN2(D_8080756C_inantab, 3, func_800BFCD0, 6, 0);

            FOR_AN2(D_80807578_inantab, 3, func_800BFCD0, 1, 1);
            FOR_AN2(D_80807584_inantab, 3, func_800BFCD0, 1, 0);
            FOR_AN2(D_80807578_inantab, 3, func_800BFCD0, 2, 1);
            FOR_AN2(D_80807584_inantab, 3, func_800BFCD0, 2, 0);
            FOR_AN2(D_80807578_inantab, 3, func_800BFCD0, 3, 1);
            FOR_AN2(D_80807584_inantab, 3, func_800BFCD0, 3, 0);
            FOR_AN2(D_80807578_inantab, 3, func_800BFCD0, 4, 1);
            FOR_AN2(D_80807584_inantab, 3, func_800BFCD0, 4, 0);
            FOR_AN2(D_80807578_inantab, 3, func_800BFCD0, 5, 1);
            FOR_AN2(D_80807584_inantab, 3, func_800BFCD0, 5, 0);
            FOR_AN2(D_80807578_inantab, 3, func_800BFCD0, 6, 1);
            FOR_AN2(D_80807584_inantab, 3, func_800BFCD0, 6, 0);

            FOR_AN3(D_80807560_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x95AFFF00, 0);
            FOR_AN3(D_8080756C_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807578_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x7CCBFF00, 0);
            FOR_AN3(D_80807584_inantab, 3, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807560_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0x95AFFF00, 0);
            FOR_AN3(D_8080756C_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807578_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0x95AFFF00, 0);
            FOR_AN3(D_80807584_inantab, 3, _indrv_lights_entrypoint_0, 0x30000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807560_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x95AFFF00, 0);
            FOR_AN3(D_8080756C_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807578_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x95AFFF00, 0);
            FOR_AN3(D_80807584_inantab, 3, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807560_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x95AFFF00, 0);
            FOR_AN3(D_8080756C_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807578_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x95AFFF00, 0);
            FOR_AN3(D_80807584_inantab, 3, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);

            FOR_AN3(D_80807560_inantab, 3, _indrv_lights_entrypoint_0, 0x60000, 0x95AFFF00, 0);
            FOR_AN3(D_8080756C_inantab, 3, _indrv_lights_entrypoint_0, 0x60000, 0x6D87FF00, 0x19);
            FOR_AN3(D_80807578_inantab, 3, _indrv_lights_entrypoint_0, 0x60000, 0x95AFFF00, 0);
            FOR_AN3(D_80807584_inantab, 3, _indrv_lights_entrypoint_0, 0x60000, 0x6D87FF00, 0x19);

            FOR_AN3(D_808075B8_inantab, 2, _indrv_audio_entrypoint_0, *(s32 *)&param_2, 1, -2);
            return 1;

        case 24:
            FOR_AN3(D_808075C0_inantab, 3, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 9, 4);
            return 1;

        case 27:
            FOR_AN3(D_808075CC_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 11, 4);
            return 1;

        case 40:
            AN3(0.01f, _inantab_entrypoint_3, *(s32 *)&param_2, 7, -1);
            return 1;

        case 41:
            FOR_AN3(D_808075F0_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 16, 4);
            return 1;

        case 42:
            AN3(0.01f, _inantab_entrypoint_3, *(s32 *)&param_2, 3, -1);
            return 1;

        case 58:
            AN3(0.01f, _inantab_entrypoint_3, *(s32 *)&param_2, 8, -1);
            return 1;

        case 59:
            AN3(0.01f, _inantab_entrypoint_3, *(s32 *)&param_2, 9, -1);
            return 1;

        case 60:
            AN3(0.01f, _inantab_entrypoint_3, *(s32 *)&param_2, 10, -1);
            return 1;

        case 61:
            AN3(0.01f, _inantab_entrypoint_3, *(s32 *)&param_2, 11, -1);
            return 1;

        case 62:
            AN3(0.01f, _inantab_entrypoint_3, *(s32 *)&param_2, 12, -1);
            return 1;

        case 68:
            AN3(0.01f, _inantab_entrypoint_3, *(s32 *)&param_2, 13, -1);
            return 1;

        case 69:
            FOR_AN3(D_80807614_inantab, 1, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 17, 4);
            return 1;

        case 70:
            FOR_AN3(D_80807618_inantab, 1, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 18, 4);
            return 1;

        case 28:
            FOR_AN3(D_8080761C_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 12, 4);
            return 1;

        case 88:
            FOR_AN3(D_80807640_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 22, 4);
            return 1;

        case 94:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 2);
            return 1;

        case 95:
            CH(0.0f, 4, 1);
            CH(0.0f, 3, 1);
            return 1;

        case 31:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 1);
            AN3(0.330000013f, _inantab_entrypoint_3, *(s32 *)&param_2, 3, -1);
            AN3(0.66900003f, _inantab_entrypoint_3, *(s32 *)&param_2, 3, -1);
            return 1;

        case 32:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 1);
            return 1;

        case 33:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 1);
            return 1;

        case 34:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 1);
            CH(0.03f, 3, 0);
            CH(0.426f, 4, 1);
            CH(0.934000015f, 3, 1);
            CH(0.934000015f, 4, 0);
            return 1;

        case 35:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 1);
            return 1;

        case 36:
            CH(0.01f, 4, 0);
            CH(0.01f, 3, 1);
            FOR_AN3(D_80807664_inantab, 8, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 14, 4);
            FOR_AN3(D_80807664_inantab, 8, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 14, 5);
            return 1;

        default:
        case 37:
        case 38:
        case 39:
        case 55:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 71:
        case 72:
        case 73:
        case 76:
        case 77:
        case 78:
        case 79:
        case 80:
        case 84:
        case 85:
        case 97:
        case 103:
        case 104:
        case 105:
            return 0;

        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 57:
            return 1;

    }

#undef FOR_CH
#undef FOR_AN3
#undef FOR_AN2
#undef CH
#undef AN3
#undef AN2

}

s32 func_808057BC_inantab(param_0, param_1, param_2) s32 param_0; s16 *param_1; void *param_2;
{
    extern void _indrv_fx_entrypoint_0();
    extern void _indrv_lights_entrypoint_0();
    extern void _indrv_audio_entrypoint_0();
    extern void _inantab_entrypoint_1();
    extern f32 D_80807684_inantab[];
    extern f32 D_808076D8_inantab[];
    extern f32 D_8080771C_inantab[];
    extern f32 D_80807740_inantab[];
    extern f32 D_80807764_inantab[];
    extern f32 D_80807768_inantab[];
    extern f32 D_8080776C_inantab[];
    extern f32 D_80807770_inantab[];
    extern f32 D_8080777C_inantab[];


#define FOR_AN3(first, count, cb, a, b, c) { \
    s32 local_0; \
    for (local_0 = 0; local_0 < (count); local_0++) { \
        _anseq_entrypoint_3(param_1, (first)[local_0], cb, a, b, c); \
    } \
}

    switch (param_0) {
        case 0x26:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 4, 0);
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 1);

            FOR_AN3(D_80807684_inantab, 21, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0xE, 4);

            FOR_AN3(D_80807684_inantab, 21, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0xE, 5);

            FOR_AN3(D_808076D8_inantab, 17, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0xE, 4);

            FOR_AN3(D_808076D8_inantab, 17, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0xE, 5);
            break;

        case 0x37:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 4, 0);
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 1);
            _chanim_entrypoint_4(param_1, 0.03f, *(s32 *)&param_2, 3, 0);
            _chanim_entrypoint_4(param_1, 0.426f, *(s32 *)&param_2, 4, 1);
            _chanim_entrypoint_4(param_1, 0.934f, *(s32 *)&param_2, 3, 1);
            _chanim_entrypoint_4(param_1, 0.934f, *(s32 *)&param_2, 4, 0);
            break;

        case 0x25:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 0);
            _chanim_entrypoint_4(param_1, 0.0348f, *(s32 *)&param_2, 3, 1);
            _chanim_entrypoint_4(param_1, 0.418f, *(s32 *)&param_2, 3, 0);
            break;

        case 0x67:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 0);
            _chanim_entrypoint_4(param_1, 0.0312f, *(s32 *)&param_2, 3, 1);
            break;

        case 0x27:
            FOR_AN3(D_8080771C_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0xF, 4);

            _anseq_entrypoint_3(param_1, 0.1f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.15f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.2f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.25f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.3f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.35f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.4f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.45f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.5f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.55f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.6f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.65f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.7f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.75f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.8f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.85f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.9f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.95f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            _anseq_entrypoint_3(param_1, 0.99f, _indrv_lights_entrypoint_0, 0x70006, *(s32 *)&param_2, 4);
            break;

        case 0x3F:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 2, 3);
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 1);
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 4, 1);
            break;

        case 0x40:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 2, 1);
            break;

        case 0x41:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 4, 2);
            break;

        case 0x42:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 2);
            break;

        case 0x43:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 2, 2);
            break;

        case 0x47:
            _anseq_entrypoint_4(
                param_1,
                0.0f,
                _inantab_entrypoint_1,
                *(s32 *)&param_2,
                0,
                0x100,
                0x200
            );
            _anseq_entrypoint_4(
                param_1,
                0.5f,
                _inantab_entrypoint_1,
                *(s32 *)&param_2,
                0,
                0x100,
                0x200
            );
            _chanim_entrypoint_4(param_1, 0.0f, *(s32 *)&param_2, 1, 0);
            _chanim_entrypoint_4(param_1, 0.5f, *(s32 *)&param_2, 1, 1);
            _chanim_entrypoint_5(param_1, -1.0f, *(s32 *)&param_2, 2, 4);
            break;

        case 0x48:
            FOR_AN3(D_80807740_inantab, 9, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x13, -1);
            break;

        case 0x49:
            FOR_AN3(D_80807764_inantab, 1, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x14, -1);

            FOR_AN3(D_80807768_inantab, 1, _indrv_lights_entrypoint_0, 0x30000, -0x100, 0);

            FOR_AN3(D_8080776C_inantab, 1, _indrv_lights_entrypoint_0, 0x30000, 0, 0x4C);
            break;

        case 0x4C:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 0);
            break;

        case 0x4D:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 0);
            break;

        case 0x4E:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 0);
            break;

        case 0x4F:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 0);
            break;

        case 0x50:
            _chanim_entrypoint_4(param_1, 0.01f, *(s32 *)&param_2, 3, 1);

            FOR_AN3(D_80807770_inantab, 3, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x18, 4);
            break;

        case 0x54:
            _chanim_entrypoint_4(param_1, 0.0f, *(s32 *)&param_2, 3, 0);
            _chanim_entrypoint_4(param_1, 0.0f, *(s32 *)&param_2, 5, 0);
            break;

        case 0x55:
            _chanim_entrypoint_4(param_1, 0.0f, *(s32 *)&param_2, 3, 1);
            _chanim_entrypoint_4(param_1, 0.0f, *(s32 *)&param_2, 5, 0);
            break;

        case 0x61:
            _chanim_entrypoint_4(param_1, 0.0f, *(s32 *)&param_2, 3, 0);
            _chanim_entrypoint_4(param_1, 0.0f, *(s32 *)&param_2, 5, 1);
            break;

        case 0x68:
            _anseq_entrypoint_3(param_1, 0.1f, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x1A, 4);
            _anseq_entrypoint_3(param_1, 0.2f, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x1B, 5);
            _anseq_entrypoint_3(param_1, 0.3f, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x1C, 6);
            _anseq_entrypoint_3(param_1, 0.4f, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x1D, 7);
            _anseq_entrypoint_3(param_1, 0.5f, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x1E, 8);
            _anseq_entrypoint_3(param_1, 0.15f, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x1A, 6);
            _anseq_entrypoint_3(param_1, 0.25f, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x1B, 9);
            _anseq_entrypoint_3(param_1, 0.35f, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x1C, 0xA);
            _anseq_entrypoint_3(param_1, 0.6f, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x1D, 0xB);
            _anseq_entrypoint_3(param_1, 0.7f, _indrv_fx_entrypoint_0, *(s32 *)&param_2, 0x1E, 0xC);

            FOR_AN3(D_8080777C_inantab, 1, _indrv_audio_entrypoint_0, *(s32 *)&param_2, 0xB5, -2);
            break;
        default:
            return 0;
    }

#undef FOR_AN3

    return 1;
}

s32 func_808064DC_inantab(s32 item_id, s32 param_1, s32 param_2) {
    if (!func_80800020_inantab(item_id, param_1, (void *)param_2)) {
        func_808057BC_inantab(item_id, param_1, param_2);
    }
}

void inantab_entrypoint_1(Unk80132ED0 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    Actor *local_0;
    local_0 = func_80106790(param_0);
    if (param_1 == 0) {
        func_80101CDC(local_0, func_800DC178(param_2 * (1.0f / 256.0f), param_3 * (1.0f / 256.0f)));
    }
}

void inantab_entrypoint_2(s32 arg0,s32 arg1)
{
    func_8010114C(arg0,0x5A,arg1);
}

void inantab_entrypoint_3(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    local_0 = D_80806E30_inantab[param_1].local_6;
    if (D_80806E30_inantab[param_1].local_4 != 0) {
        func_800E1664(D_80806E30_inantab[param_1].local_6, D_80806E30_inantab[param_1].local_0, D_80806E30_inantab[param_1].local_2, 0, D_80806E30_inantab[param_1].local_4, D_80806E30_inantab[param_1].local_5);
        return;
    }
    local_1 = func_800E1540(local_0);
    if (D_80806E30_inantab[param_1].local_0 != -1.0f) {
        func_800E13F0(local_1, D_80806E30_inantab[param_1].local_0);
    }
    if (D_80806E30_inantab[param_1].local_1 != -1.0f) {
        func_800E1410(local_1, D_80806E30_inantab[param_1].local_1, D_80806E30_inantab[param_1].local_2);
    }
    if (D_80806E30_inantab[param_1].local_3 != -1.0f) {
        func_800E144C(local_1, D_80806E30_inantab[param_1].local_3);
    }
}

void inantab_entrypoint_4(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s16 param_3; {
    s16 local_0;
    u8 *local_1;

    local_1 = *(u8 **)((u8 *)&D_80806D5C_inantab + (param_0 * 4));
    local_0 = (*(s16 *)((s8 *)(local_1) + (2)));
    if (local_0 != 0) {
loop_1:
        if (param_3 == (*(s16 *)((s8 *)(local_1) + (0)))) {
            func_808064DC_inantab(local_0, param_2, param_1);
            return;
        }
        local_0 = (*(s16 *)((s8 *)(local_1) + (6)));
        local_1 += 4;
        if (local_0 == 0) {

        } else {
            goto loop_1;
        }
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/in/antab.data.s) is defined here in C.
 * Values are taken from the ROM. */
u32 D_80806A90_inantab[6] = { 0x4DD004C, 0x4EC004D, 0x4ED0050, 0x4EE004E, 0x4EF004F, 0x0 };
u32 D_80806AA8_inantab[2] = { 0x3880004, 0x0 };
u32 D_80806AB0_inantab[2] = { 0x3880002, 0x0 };
u32 D_80806AB8_inantab[2] = { 0x3880002, 0x0 };
u32 D_80806AC0_inantab[2] = { 0x3880003, 0x0 };
u32 D_80806AC8_inantab[2] = { 0x3880001, 0x0 };
u32 D_80806AD0_inantab[2] = { 0x3880005, 0x0 };
u32 D_80806AD8_inantab[18] = { 0x3880006, 0x419002B, 0xB4002C, 0x44B002D, 0x461002E, 0x462002F, 0x4670030, 0x4650031, 0x4680032, 0x46A0033, 0x51F005A, 0x4F5005B, 0x4F6005B, 0x50F005B, 0x514005B, 0x473005B, 0xB5005B, 0x0 };
u32 D_80806B20_inantab[2] = { 0x3880007, 0x0 };
u32 D_80806B28_inantab[2] = { 0x3A50008, 0x0 };
u32 D_80806B30_inantab[4] = { 0x3880009, 0x38F000F, 0x4080017, 0x0 };
u32 D_80806B40_inantab[2] = { 0x408000A, 0x0 };
u32 D_80806B48_inantab[18] = { 0xC0036, 0x409000B, 0x4720034, 0x4710035, 0x4900036, 0x48E0038, 0x6F0036, 0xAE0036, 0xA4006A, 0x52D0036, 0x52E0036, 0x52F0036, 0x5300036, 0x5200036, 0x5210036, 0x5220036, 0x5360062, 0x0 };
u32 D_80806B90_inantab[31] = { 0x40B000C, 0x46B000C, 0x46C000C, 0x46D000C, 0x46E000C, 0x46F000C, 0x45F001D, 0x460001E, 0x5100056, 0x517005C, 0x518005C, 0x519005D, 0x51A0059, 0x51D005C, 0x5110056, 0x5120056, 0x5130064, 0x5150057, 0x5160057, 0x2C8004A, 0x51E004A, 0x524004A, 0x525004A, 0x526004A, 0x527004A, 0x537004A, 0x538004B, 0x50A0053, 0x50B0053, 0x50C0053, 0x0 };
u32 D_80806C0C_inantab[2] = { 0x3AB000D, 0x0 };
u32 D_80806C14_inantab[4] = { 0x388000E, 0x4F0060, 0x4750063, 0x0 };
u32 D_80806C24_inantab[5] = { 0x40F0010, 0x4110011, 0x4120012, 0x448001A, 0x0 };
u32 D_80806C38_inantab[9] = { 0x4150013, 0x4140014, 0x4170015, 0x4F00051, 0x4F10052, 0x45A0013, 0x45E0013, 0x50E0051, 0x0 };
u32 D_80806C5C_inantab[3] = { 0x4220016, 0x4740039, 0x0 };
u32 D_80806C68_inantab[2] = { 0x4130018, 0x0 };
u32 D_80806C70_inantab[2] = { 0x3880019, 0x0 };
u32 D_80806C78_inantab[16] = { 0x388001B, 0x38F0028, 0x3900029, 0x40C002A, 0x8F003A, 0x39B003B, 0x39C003C, 0x3A2003D, 0x3A5003E, 0x530044, 0x4170045, 0x4180046, 0x4190058, 0x3AA005F, 0x452005E, 0x0 };
u32 D_80806CB8_inantab[2] = { 0x388001C, 0x0 };
u32 D_80806CC0_inantab[9] = { 0x446001F, 0x4490020, 0x44A0021, 0x4510022, 0x44F0023, 0x4500024, 0x4920037, 0x4540026, 0x0 };
u32 D_80806CE4_inantab[3] = { 0x4520025, 0x5410067, 0x0 };
u32 D_80806CF0_inantab[2] = { 0x3880027, 0x0 };
u32 D_80806CF8_inantab[6] = { 0x388003F, 0x38F0040, 0x3900041, 0x25C0042, 0x2640043, 0x0 };
u32 D_80806D10_inantab[4] = { 0x3880047, 0x38F0048, 0x3900049, 0x0 };
u32 D_80806D20_inantab[6] = { 0x4FD0054, 0x5020055, 0x5090054, 0x5350061, 0x5330061, 0x0 };
u32 D_80806D38_inantab[2] = { 0x4F40065, 0x0 };
u32 D_80806D40_inantab[2] = { 0x5400066, 0x0 };
u32 D_80806D48_inantab[2] = { 0x3880068, 0x0 };
u32 D_80806D50_inantab[2] = { 0x3880069, 0x0 };
u32 D_80806D58_inantab[1] = { 0x6F006B };
u32 *D_80806D5C_inantab = 0;
static u32 D_80806D5C_inantab_rest[34] = { (u32)&D_80806AB8_inantab, (u32)&D_80806AC0_inantab, (u32)&D_80806AC8_inantab, (u32)&D_80806AB0_inantab, (u32)&D_80806AA8_inantab, (u32)&D_80806AD0_inantab, (u32)&D_80806AD8_inantab, (u32)&D_80806B20_inantab, (u32)&D_80806B28_inantab, (u32)&D_80806B30_inantab, (u32)&D_80806B40_inantab, (u32)&D_80806B48_inantab, (u32)&D_80806B90_inantab, (u32)&D_80806C0C_inantab, (u32)&D_80806C14_inantab, (u32)&D_80806C24_inantab, (u32)&D_80806C38_inantab, (u32)&D_80806C5C_inantab, (u32)&D_80806C68_inantab, (u32)&D_80806C70_inantab, (u32)&D_80806C78_inantab, (u32)&D_80806CB8_inantab, (u32)&D_80806CC0_inantab, (u32)&D_80806CE4_inantab, (u32)&D_80806CF0_inantab, (u32)&D_80806CF8_inantab, (u32)&D_80806D10_inantab, (u32)&D_80806A90_inantab, (u32)&D_80806D20_inantab, (u32)&D_80806D38_inantab, (u32)&D_80806D40_inantab, (u32)&D_80806D48_inantab, (u32)&D_80806D50_inantab, (u32)&D_80806D58_inantab };
u32 D_80806DE8_inantab[6] = { 0x0, 0x0, 0x3F333333, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80806E00_inantab[6] = { 0x0, 0x0, 0x3F333333, 0x3F800000, 0x3F800000, 0x3F800000 };
u32 D_80806E18_inantab[6] = { 0x0, 0x3F800000, 0x3F000000, 0x3F800000, 0x3F800000, 0x3F800000 };
AntabEffectPreset D_80806E30_inantab[14] = { 3.5f, 0.02f, 2e+01f, 0.001f, 0x0, 0x0, 0x0, 0x0, 0x0, 0.9f, 0.001f, 4e+01f, 0.001f, 0x0, 0x0, 0x0, 0x0, 0x0, 2.2f, 0.001f, 17.7f, 0.9f, 0x0, 0x0, 0x0, 0x0, 0x0, 1.8f, 0.001f, 0.28f, 0.8f, 0x0, 0x0, 0x0, 0x0, 0x0, 4.8f, 0.001f, 0.28f, 0.8f, 0x0, 0x0, 0x0, 0x0, 0x0, 24.8f, 0.001f, 0.75f, 0.7f, 0x0, 0x0, 0x2, 0x0, 0x0, 0.8f, 0.0f, 2e+01f, 0.0f, (u32)&D_80806E00_inantab, 0x3, 0x0, 0x0, 0x0, 0.2f, 0.0f, 4.0f, 0.0f, (u32)&D_80806E00_inantab, 0x3, 0x0, 0x0, 0x0, 2.2f, 0.0f, 16.0f, 0.0f, (u32)&D_80806DE8_inantab, 0x3, 0x0, 0x0, 0x0, 70.8f, 0.001f, 0.35f, 0.5f, 0x0, 0x0, 0x2, 0x0, 0x0, 5.5f, 0.0f, 9.0f, 0.0f, (u32)&D_80806E18_inantab, 0x3, 0x0, 0x0, 0x0, 8.6f, 0.0f, 9.0f, 0.0f, (u32)&D_80806E18_inantab, 0x3, 0x0, 0x0, 0x0, 5.5f, 0.0f, 3e+01f, 0.0f, (u32)&D_80806E18_inantab, 0x3, 0x0, 0x0, 0x0, 1.5f, 0.0f, 8.0f, 0.0f, (u32)&D_80806E18_inantab, 0x3, 0x0, 0x0, 0x0 };
f32 D_80806F80_inantab[3] = { 0.2f, 0.24f, 0.26f };
f32 D_80806F8C_inantab[3] = { 0.22f, 0.25f, 0.27f };
f32 D_80806F98_inantab[3] = { 0.3f, 0.33f, 0.35f };
f32 D_80806FA4_inantab[3] = { 0.31f, 0.34f, 0.36f };
f32 D_80806FB0_inantab[10] = { 0.8f, 0.83f, 0.85f, 0.81f, 0.84f, 0.86f, 0.9f, 0.93f, 0.91f, 0.93f };
f32 D_80806FD8_inantab[2] = { 0.265f, 0.865f };
f32 D_80806FE0_inantab[22] = { 0.2f, 0.24f, 0.26f, 0.22f, 0.25f, 0.27f, 0.3f, 0.33f, 0.35f, 0.31f, 0.34f, 0.36f, 0.8f, 0.83f, 0.85f, 0.81f, 0.84f, 0.86f, 0.9f, 0.93f, 0.91f, 0.93f };
f32 D_80807038_inantab[2] = { 0.265f, 0.865f };
f32 D_80807040_inantab[3] = { 0.2f, 0.24f, 0.26f };
f32 D_8080704C_inantab[3] = { 0.22f, 0.25f, 0.27f };
f32 D_80807058_inantab[3] = { 0.3f, 0.33f, 0.35f };
f32 D_80807064_inantab[3] = { 0.31f, 0.34f, 0.36f };
f32 D_80807070_inantab[3] = { 0.2f, 0.24f, 0.26f };
f32 D_8080707C_inantab[3] = { 0.22f, 0.25f, 0.27f };
f32 D_80807088_inantab[3] = { 0.3f, 0.33f, 0.35f };
f32 D_80807094_inantab[3] = { 0.31f, 0.34f, 0.36f };
f32 D_808070A0_inantab[10] = { 0.8f, 0.83f, 0.85f, 0.81f, 0.84f, 0.86f, 0.9f, 0.93f, 0.91f, 0.93f };
f32 D_808070C8_inantab[2] = { 0.265f, 0.865f };
f32 D_808070D0_inantab[1] = { 0.33f };
f32 D_808070D4_inantab[9] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_808070F8_inantab[10] = { 0.05f, 0.15f, 0.25f, 0.35f, 0.45f, 0.55f, 0.65f, 0.75f, 0.85f, 0.95f };
f32 D_80807120_inantab[9] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807144_inantab[10] = { 0.05f, 0.15f, 0.25f, 0.35f, 0.45f, 0.55f, 0.65f, 0.75f, 0.85f, 0.95f };
f32 D_8080716C_inantab[9] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807190_inantab[10] = { 0.05f, 0.15f, 0.25f, 0.35f, 0.45f, 0.55f, 0.65f, 0.75f, 0.85f, 0.95f };
f32 D_808071B8_inantab[2] = { 0.25f, 0.75f };
f32 D_808071C0_inantab[2] = { 0.25f, 0.75f };
f32 D_808071C8_inantab[28] = { 0.33f, 0.34f, 0.35f, 0.36f, 0.37f, 0.38f, 0.39f, 0.4f, 0.41f, 0.42f, 0.43f, 0.44f, 0.45f, 0.46f, 0.47f, 0.48f, 0.49f, 0.5f, 0.51f, 0.52f, 0.53f, 0.54f, 0.55f, 0.56f, 0.57f, 0.58f, 0.59f, 0.6f };
f32 D_80807238_inantab[4] = { 0.2805f, 0.2937f, 0.3076f, 0.3336f };
f32 D_80807248_inantab[2] = { 0.1247f, 0.1561f };
f32 D_80807250_inantab[4] = { 0.2551f, 0.2702f, 0.2877f, 0.3055f };
f32 D_80807260_inantab[3] = { 0.375f, 0.3806f, 0.4063f };
f32 D_8080726C_inantab[2] = { 0.2145f, 0.2459f };
f32 D_80807274_inantab[3] = { 0.3536f, 0.373f, 0.393f };
f32 D_80807280_inantab[3] = { 0.2f, 0.24f, 0.26f };
f32 D_8080728C_inantab[3] = { 0.22f, 0.25f, 0.27f };
f32 D_80807298_inantab[3] = { 0.3f, 0.33f, 0.35f };
f32 D_808072A4_inantab[3] = { 0.31f, 0.34f, 0.36f };
f32 D_808072B0_inantab[10] = { 0.8f, 0.83f, 0.85f, 0.81f, 0.84f, 0.86f, 0.9f, 0.93f, 0.91f, 0.93f };
f32 D_808072D8_inantab[2] = { 0.265f, 0.865f };
f32 D_808072E0_inantab[11] = { 0.01f, 0.01f, 0.03f, 0.05f, 0.07f, 0.09f, 0.11f, 0.13f, 0.15f, 0.17f, 0.19f };
f32 D_8080730C_inantab[18] = { 0.01f, 0.19f, 0.21f, 0.23f, 0.25f, 0.27f, 0.29f, 0.31f, 0.33f, 0.35f, 0.37f, 0.39f, 0.41f, 0.43f, 0.45f, 0.47f, 0.49f, 0.51f };
f32 D_80807354_inantab[21] = { 0.35f, 0.37f, 0.39f, 0.41f, 0.43f, 0.45f, 0.47f, 0.49f, 0.51f, 0.53f, 0.55f, 0.57f, 0.59f, 0.61f, 0.63f, 0.65f, 0.67f, 0.69f, 0.71f, 0.73f, 0.75f };
f32 D_808073A8_inantab[44] = { 0.01f, 0.01f, 0.03f, 0.05f, 0.07f, 0.09f, 0.11f, 0.13f, 0.15f, 0.17f, 0.19f, 0.21f, 0.23f, 0.25f, 0.27f, 0.29f, 0.31f, 0.33f, 0.35f, 0.37f, 0.39f, 0.41f, 0.43f, 0.45f, 0.47f, 0.49f, 0.51f, 0.53f, 0.55f, 0.57f, 0.59f, 0.61f, 0.63f, 0.65f, 0.67f, 0.69f, 0.71f, 0.73f, 0.75f, 0.77f, 0.79f, 0.81f, 0.83f, 0.85f };
f32 D_80807458_inantab[21] = { 0.35f, 0.37f, 0.39f, 0.41f, 0.43f, 0.45f, 0.47f, 0.49f, 0.51f, 0.53f, 0.55f, 0.57f, 0.59f, 0.61f, 0.63f, 0.65f, 0.67f, 0.69f, 0.71f, 0.73f, 0.75f };
f32 D_808074AC_inantab[12] = { 0.77f, 0.79f, 0.81f, 0.83f, 0.85f, 0.87f, 0.89f, 0.91f, 0.93f, 0.95f, 0.97f, 0.99f };
f32 D_808074DC_inantab[3] = { 0.3f, 0.6f, 0.9f };
f32 D_808074E8_inantab[19] = { 0.05f, 0.1f, 0.15f, 0.2f, 0.25f, 0.3f, 0.35f, 0.4f, 0.45f, 0.5f, 0.55f, 0.6f, 0.65f, 0.7f, 0.75f, 0.8f, 0.85f, 0.9f, 0.95f };
f32 D_80807534_inantab[10] = { 0.3f, 0.35f, 0.4f, 0.45f, 0.5f, 0.55f, 0.6f, 0.65f, 0.7f, 0.75f };
f32 D_8080755C_inantab[1] = { 0.8f };
f32 D_80807560_inantab[3] = { 0.2f, 0.24f, 0.26f };
f32 D_8080756C_inantab[3] = { 0.22f, 0.25f, 0.27f };
f32 D_80807578_inantab[3] = { 0.3f, 0.33f, 0.35f };
f32 D_80807584_inantab[3] = { 0.31f, 0.34f, 0.36f };
f32 D_80807590_inantab[10] = { 0.8f, 0.83f, 0.85f, 0.81f, 0.84f, 0.86f, 0.9f, 0.93f, 0.91f, 0.93f };
f32 D_808075B8_inantab[2] = { 0.265f, 0.865f };
f32 D_808075C0_inantab[3] = { 0.3f, 0.6f, 0.9f };
f32 D_808075CC_inantab[9] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_808075F0_inantab[9] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807614_inantab[1] = { 0.01f };
f32 D_80807618_inantab[1] = { 0.01f };
f32 D_8080761C_inantab[9] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807640_inantab[9] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807664_inantab[8] = { 0.68f, 0.69f, 0.7f, 0.71f, 0.72f, 0.73f, 0.74f, 0.75f };
f32 D_80807684_inantab[21] = { 0.24f, 0.26f, 0.28f, 0.3f, 0.32f, 0.34f, 0.36f, 0.38f, 0.4f, 0.42f, 0.44f, 0.46f, 0.48f, 0.5f, 0.52f, 0.54f, 0.56f, 0.58f, 0.6f, 0.62f, 0.64f };
f32 D_808076D8_inantab[17] = { 0.66f, 0.68f, 0.7f, 0.72f, 0.74f, 0.76f, 0.78f, 0.8f, 0.82f, 0.84f, 0.86f, 0.88f, 0.9f, 0.92f, 0.94f, 0.96f, 0.98f };
f32 D_8080771C_inantab[9] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807740_inantab[9] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807764_inantab[1] = { 0.1f };
f32 D_80807768_inantab[1] = { 0.1f };
f32 D_8080776C_inantab[1] = { 0.15f };
f32 D_80807770_inantab[3] = { 0.7f, 0.7025f, 0.705f };
f32 D_8080777C_inantab[1] = { 0.1f };
