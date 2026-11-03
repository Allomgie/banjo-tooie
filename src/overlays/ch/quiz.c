#include "common.h"

#define QUIZ_FLAG_VIEW_1214
extern void *func_800A89F8(void);
extern void *func_800A9478(void *);
extern void *func_800F5EF8(void *);
extern void func_80102424(Actor *, s32);
extern Actor *_subaddiefind_entrypoint_11(s32, Actor *);
typedef struct { s32 local_0; f32 unk4; s32 unk8; f32 unkC; void *unk10; f32 unk14; } QuizRecord1351;
extern QuizRecord1351 D_80807000_chquiz[];
extern f32 D_80807004_chquiz[5];
extern s32 D_80807008_chquiz[];
extern float D_8080700C_chquiz[];
extern s32 D_80807010_chquiz[];
extern float D_80807014_chquiz[];
extern u8 D_808070A8_chquiz[];
typedef struct { u8 pad0[0x94]; s32 unk94; u8 unk98; u8 unk99; } QuizData;
extern QuizData *func_80100094(Actor *, s32);
extern void _gcnewoption_entrypoint_0(s32);
extern void _gcnewoption_entrypoint_1(s32, s32);
typedef struct { s32 values[3]; } QuizOptions32;
extern QuizOptions32 D_808070B8_chquiz;
typedef struct { u8 pad_0[0x9C]; u8 local_0[30]; u8 local_1[18]; } QuizFlagView1214;
extern u8 *_gldbstring_entrypoint_0(s32, s32);
typedef struct { u8 pad_0[0x60]; s8 local_0[3]; } QuizOrderState;
extern void _gldbstring_entrypoint_2();
extern void func_800A5800();
typedef struct { s8 b0; s8 b1; s8 b2; s8 pad; f32 w4; } QuizEnt;
extern QuizEnt D_808070E4_chquiz[];
typedef struct QuizCamera29 { f32 position[3]; f32 rotation[3]; u8 pad_0[4]; f32 targetPosition[3]; f32 targetRotation[3]; u8 pad_1[4]; f32 cameraPosition[3]; f32 cameraRotation[3]; s16 camera; s16 pad_2; f32 elapsed; f32 duration; s8 moving; } QuizCamera29;
struct QuizCamera29;
extern s8 D_808070C4_chquiz[];
extern void func_8010FFB0(void *, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct QuizTimerState { u8 pad_0[0x84]; f32 local_0; f32 local_1; u8 pad_1[4]; u8 local_2; } QuizTimerState;
extern f32 func_800D9004(void);
extern f32 func_800F13C4(f32, f32);
extern void func_800C3FC0(s32, f32, s32);
extern s8 D_808071B1_chquiz[];
extern int D_808072CC_chquiz[];
extern void func_800C8CB8();
extern void func_800C8D4C();
extern void func_800C8E84();
extern void func_800C8F64();
extern void func_800C8FE0();
extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_80103EF4(Actor *);
extern u8 D_80807314_chquiz[];
extern u8 D_8080731C_chquiz[];
extern s32 func_800F6438(u32);
extern void func_800F8294(s32, f32 *);
extern void func_800F832C(s32, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int D_80807334_chquiz[];
extern u8 D_80807474_chquiz[];
extern u8 D_8080746C_chquiz[];
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800D90A4(f32 *);
extern u8 unk24[];
extern int D_80807480_chquiz[];
extern void func_80101FDC();
extern void func_80103110();
extern u8 D_808074C8_chquiz[];
extern u8 D_808074D0_chquiz[];
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 D_808074DC_chquiz[];
extern s32 D_8080755C_chquiz[];
extern s32 D_80807564_chquiz[];
typedef struct { u8 pad_0[0x74]; u32 pad_1 : 10; u32 local_0 : 1; u32 pad_2 : 21; } QuizActorFlags;
extern int D_80807684_chquiz[];
extern void _gcnewoption_entrypoint_35(void);
extern void *heap_alloc(s32);
extern void _gcnewoption_entrypoint_40(void *, s32, s32, s32, f32, f32);
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern void _gcnewoption_entrypoint_37(s32, s32);
extern void _gcnewoption_entrypoint_46(s32, s32);
extern void _gcnewoption_entrypoint_25(s32, s32);
extern void _gcnewoption_entrypoint_26(s32, s32);
extern void _gcnewoption_entrypoint_29(s32, s32);
extern void _gcnewoption_entrypoint_44(s32, s32);
extern void _gcnewoption_entrypoint_41(s32, s32);
extern void _gcnewoption_entrypoint_43(s32, s32, s32);
extern void _gcnewoption_entrypoint_13(s32, s32, void *);
extern s32 _suquiz_entrypoint_6(void);
extern s32 _suquiz_entrypoint_10(s32);
extern u8 D_808070B0_chquiz[];
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern f32 _ncpod_entrypoint_10(s32);
extern void _ncpod_entrypoint_9(s32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800F16AC(f32 *, f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800C3F48(u32 param_0);
extern void func_800E1720(s32 param_0);
extern void func_8010C908(s32 param_0, s32 param_1);
typedef struct { u16 local_0; u8 pad_0[6]; } QuizAnimation271;
extern QuizAnimation271 D_80807220_chquiz[];
extern u8 D_8080723C_chquiz[];
extern u8 D_80807274_chquiz[];
extern u8 D_808072BC_chquiz[];
extern f32 func_80101F24(Actor *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800138D0(f32);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800187B4(s32, f32, f32, f32);
extern s32 func_800E15CC(s32, f32, f32);
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
extern u8 D_80807328_chquiz[];
extern void func_80102FDC(Actor *, f32);
typedef struct { u8 pad_0[0x70]; u32 pad_1:28; u32 local_0:1; u32 pad_2:3; } QuizExpressionFlag481;
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800DF500(f32, f32, f32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void func_8010A800(Actor *, s32);
extern void _suquiz_entrypoint_21(s32, u32);
extern void _chblink_entrypoint_2();
extern void _chblink_entrypoint_4();
extern void func_801015D0(Actor *);
extern u8 D_8080737C_chquiz[];
extern u8 D_808073A4_chquiz[];
extern u8 D_808073CC_chquiz[];
extern u8 D_8080741C_chquiz[];
extern u8 D_80807444_chquiz[];
extern s32 func_80101DDC(void *);
extern s32 func_800DC298(f32);
extern f32 func_800DC0C0(void);
extern f32 func_80103EAC(void *);
extern void _subaddieaudioquick_entrypoint_3(void *, void *, void *, f32);
extern u8 R_808067F4_chquiz[];
extern u8 D_808075EC_chquiz[];
extern f32 R_808067E4_chquiz;
extern f32 R_808067F8_chquiz;
extern f32 R_808067EC_chquiz;
extern u8 D_808075C0_chquiz[];
extern f32 R_808067FC_chquiz;
extern f32 R_808067F0_chquiz;
extern f32 R_808067E8_chquiz;
extern f32 R_808067DC_chquiz;
extern f32 R_808067E0_chquiz;
extern f32 R_808067D8_chquiz;
extern u8 D_8080765C_chquiz[];
extern u8 D_80807624_chquiz[];
extern u8 D_80807640_chquiz[];
extern u8 D_80807598_chquiz[];
extern u8 D_80807580_chquiz[];
extern u8 unk62[];
extern u8 D_808075B0_chquiz[];
extern u8 D_80807570_chquiz[];
typedef struct { u16 id; u16 pad[3]; } QEnt3;
extern QEnt3 D_80807528_chquiz[];
typedef struct { s32 w[4]; } S16;
typedef struct { s32 w[6]; } S24;
extern s32 _capod_entrypoint_17(f32);
int func_80800B90_chquiz();
int func_80800BD4_chquiz();
void func_80800C24_chquiz();
void func_80800DA8_chquiz();
int func_80800E38_chquiz();
int func_80800E44_chquiz();
int func_80801784_chquiz();
int func_808005C0_chquiz();
s32 func_80801170_chquiz();
void func_80804170_chquiz();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80108ED0();
extern void func_80105834(), func_80107C2C(), func_80108ED0();
extern u8 D_80807524_chquiz[];

s32 func_80800000_chquiz(s32 param_0);
f32 func_80800070_chquiz(s32 param_0);
int func_8080008C_chquiz(s32 param_0);
float func_808000A8_chquiz(s32 param_0);
int func_808000C4_chquiz(s32 param_0);
float func_808000E0_chquiz(s32 param_0);
void * func_808000FC_chquiz(Actor *param_0, s32 param_1);
void func_80800218_chquiz(s32 param_0, s32 param_1);
void func_80800298_chquiz(s32 param_0);
void func_808002F0_chquiz(s32 param_0, s32 param_1);
void func_8080034C_chquiz(Actor *param_0, s32 param_1);
void func_80800728_chquiz(Actor *param_0, s32 param_1);
void func_8080085C_chquiz(s32 param_0);
void func_808008B0_chquiz(s32 param_0);
void func_808008D4_chquiz(s32 param_0);
s32 func_80800944_chquiz(Actor *param_0, s32 param_1);
void func_808009D8_chquiz(Actor *param_0, s32 param_1);
s32 func_80800A70_chquiz(Actor *param_0);
s32 func_80800B6C_chquiz(s32 param_0);
s32 func_80800C00_chquiz();
s16 func_80800C8C_chquiz(u8 *param_0, s32 *param_1);
void func_80800CE8_chquiz(Actor *param_0, s32 *param_1, s32 *param_2);
void func_80800EF4_chquiz(s16 param_0, f32 *param_1, f32 *param_2);
int func_80800F34_chquiz(s32 param_0[3], s32 *param_1);
s32 func_80800FBC_chquiz(void *arg);
void func_8080100C_chquiz(s32 param_0, struct QuizCamera29 *param_1, u8 param_2);
void func_80801058_chquiz(s32 param_0, QuizCamera29 *param_1, f32 param_2, s8 param_3, s8 param_4, s8 param_5);
s32 func_808013E0_chquiz(s32 param_0, u8 *param_1);
void func_80801408_chquiz(Actor *param_0, u8 *param_1, s32 param_2, u32 param_3);
void func_80801470_chquiz(s32 param_0, u8 *param_1);
void func_808014F8_chquiz(s32 param_0, s32 param_1);
s32 func_80801544_chquiz(s32 param_0);
int func_8080154C_chquiz(s32 param_0);
s32 func_80801600_chquiz(Actor *param_0);
void func_808016F8_chquiz(u8 *param_0, s32 param_1, f32 param_2);
void func_80801710_chquiz(void *param_0);
void func_80801724_chquiz(u8 *param_0);
void func_80801758_chquiz(u8 *param_0, s32 param_1);
int func_80801760_chquiz(s32 *param_0, s32 param_1, s32 param_2);
void func_80801794_chquiz(u8 *param_0);
int func_80801930_chquiz(OSPiHandle *param_0, OSIoMesg *param_1);
s32 func_80801A54_chquiz(s32 param_0, s32 *param_1);
s32 func_80801B7C_chquiz(s32 param_0);
s32 func_80801C08_chquiz(s32 param_0, s32 param_1);
s32 func_80801C7C_chquiz(s32 param_0);
void func_80801CC4_chquiz(Actor *param_0);
int chquiz_entrypoint_0();
void func_80802004_chquiz(Actor *param_0);
s32 func_80802108_chquiz(s32 param_0, s32 param_1);
void func_8080216C_chquiz(s32 *param_0);
void func_808021C8_chquiz(Actor *param_0, s32 param_1, f32 *param_2);
void func_80802250_chquiz(Actor *param_0);
void func_80802434_chquiz(u8 *param_0, s32 param_1);
int func_80802628_chquiz(Actor *param_0);
void func_80802664_chquiz(Actor *param_0);
void func_808029A4_chquiz(Actor *param_0);
s32 func_80802A2C_chquiz(Actor *param_0, s32 param_1, s32 param_2);
int chquiz_entrypoint_1();
int func_80803320_chquiz(s32 param_0, s32 param_1);
void func_80803368_chquiz(Actor *param_0, s32 param_1);
s32 func_80803588_chquiz(u8 *param_0, s32 param_1, s32 param_2);
int * chquiz_entrypoint_2();
void func_80803954_chquiz(Actor *param_0);
int func_808039D4_chquiz(Actor *param_0, s32 param_1, s32 param_2);
s32 chquiz_entrypoint_3();
int func_80803B54_chquiz(s32 param_0[4], s32 param_1, s32 param_2);
int func_80803B88_chquiz(s32 param_0);
void func_80803BFC_chquiz(u8 *param_0);
void func_808040D4_chquiz(u8 *param_0);
void func_80804110_chquiz(u8 *param_0);
s32 func_8080414C_chquiz(u8 *param_0);
s32 func_808058F0_chquiz(Actor *param_0, s32 param_1, s32 param_2);
int * chquiz_entrypoint_4();
s32 func_80800000_chquiz(s32 param_0)
{
    if (param_0 == 2) {
        return func_8009EA2C() ? 0x838 : D_80807000_chquiz[param_0].local_0;
    }
    return D_80807000_chquiz[param_0].local_0;
}
f32 func_80800070_chquiz(s32 param_0)
{
    int new_var2;
    int new_var;
    new_var2 = ((((param_0 * 6) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF;
    new_var = (new_var2 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF;
    return D_80807004_chquiz[(((new_var & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF];
}

int func_8080008C_chquiz(s32 param_0)
{
    return *(s32 *) ((char *) D_80807008_chquiz + param_0 * 24);
}

float func_808000A8_chquiz(s32 param_0)
{
    return *(f32 *) ((char *) D_8080700C_chquiz + param_0 * 24);
}

int func_808000C4_chquiz(s32 param_0)
{
    return *(s32 *) ((char *) D_80807010_chquiz + param_0 * 24);
}

float func_808000E0_chquiz(s32 param_0)
{
    return *(f32 *) ((char *) D_80807014_chquiz + param_0 * 24);
}

void *func_808000FC_chquiz(Actor *param_0, s32 param_1)
{
    void *local_0;
    local_0 = heap_alloc(_gcnewoption_entrypoint_2());
    bzero(local_0, _gcnewoption_entrypoint_2());
    _gcnewoption_entrypoint_5(local_0, _gcnewoption_entrypoint_35, 0, param_1, param_0->unk0);
    *(void **) ((u8 *) func_80100094(param_0, 0) + 0x94) = local_0;
    _gcnewoption_entrypoint_40(local_0, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_8(local_0, 3);
    _gcnewoption_entrypoint_9(local_0, 3);
    _gcnewoption_entrypoint_10(local_0, 2);
    _gcnewoption_entrypoint_32(local_0, 0x4D);
    _gcnewoption_entrypoint_14(local_0, 0, 0, 0, 0.0f);
    _gcnewoption_entrypoint_28(local_0);
    _gcnewoption_entrypoint_25(local_0, 0);
    _gcnewoption_entrypoint_26(local_0, 0);
    _gcnewoption_entrypoint_11(local_0);
    return local_0;
}

void func_80800218_chquiz(s32 param_0, s32 param_1)
{
    s32 local_0;
    _gcnewoption_entrypoint_30(param_0, D_808070A8_chquiz);
    for (local_0 = 0; local_0 < 3; local_0++) {
        _gcnewoption_entrypoint_12(param_0, local_0,
        (s16)(func_80800E38_chquiz(param_1, local_0) + 0xA));
    }
}

void func_80800298_chquiz(s32 param_0)
{
    s32 local_0 = *(s32 *) ((u8 *) func_80100094(param_0, 0) + 0x94);
    if (local_0 != 0 && ((u8 *) func_80100094(param_0, 0))[0x99] != 0) {
        _gcnewoption_entrypoint_0(local_0);
    }
}

void func_808002F0_chquiz(s32 param_0, s32 param_1)
{
    s32 local_0 = *(s32 *) ((u8 *) func_80100094(param_0, 0) + 0x94);
    if (local_0 != 0 && ((u8 *) func_80100094(param_0, 0))[0x99] != 0) {
        _gcnewoption_entrypoint_1(local_0, param_1);
    }
}

void func_8080034C_chquiz(Actor *param_0, s32 param_1)
{
    s32 local_0;

    local_0 = func_80100094(param_0, 0)->unk94;
    if (!func_80100094(param_0, 0)->unk98) {
        if (param_1 == 0) {
            return;
        }
        local_0 = func_808000FC_chquiz(param_0, func_80800B6C_chquiz(param_0));
    }
    switch (param_1) {
        case 0:
            if (local_0) {
                _gcnewoption_entrypoint_37(func_80100094(param_0, 0)->unk94, 1);
            }
            func_80100094(param_0, 0)->unk99 = 0;
            break;
        case 1:
            func_80100094(param_0, 0)->unk99 = 1;
            _gcnewoption_entrypoint_46(local_0, -1);
            break;
        case 2:
            _gcnewoption_entrypoint_25(local_0, 1);
            _gcnewoption_entrypoint_26(local_0, 1);
            _gcnewoption_entrypoint_29(local_0, 1);
            _gcnewoption_entrypoint_46(local_0, _suquiz_entrypoint_10(_suquiz_entrypoint_6()));
            _gcnewoption_entrypoint_44(local_0, 1);
            _gcnewoption_entrypoint_41(local_0, 0);
            func_80100094(param_0, 0)->unk99 = 1;
            break;
        case 3:
            _gcnewoption_entrypoint_25(local_0, 1);
            _gcnewoption_entrypoint_26(local_0, 0);
            _gcnewoption_entrypoint_29(local_0, 0);
            _gcnewoption_entrypoint_46(local_0, -1);
            _gcnewoption_entrypoint_44(local_0, 0);
            if (func_80800C00_chquiz(param_0) != -1) {
                _gcnewoption_entrypoint_43(local_0, func_80800C00_chquiz(param_0), 0);
                _gcnewoption_entrypoint_13(local_0, func_80800C00_chquiz(param_0),
                                           D_808070B0_chquiz);
            }
            func_80100094(param_0, 0)->unk99 = 1;
            break;
        case 4:
            _gcnewoption_entrypoint_26(local_0, 1);
            _gcnewoption_entrypoint_29(local_0, 1);
            _gcnewoption_entrypoint_41(local_0, !func_80800C00_chquiz(param_0) ? 1 : 0);
            _gcnewoption_entrypoint_46(local_0, _suquiz_entrypoint_10(_suquiz_entrypoint_6()));
            func_80100094(param_0, 0)->unk99 = 1;
            break;
    }
    func_80100094(param_0, 0)->unk98 = param_1;
}

int func_808005C0_chquiz(param_0, param_1, param_2)
Actor *param_0;
s32 param_1;
u32 param_2;
{
    void *local_0;

    local_0 = *(void **) ((u8 *) func_80100094(param_0, 0) + 0x94);
    switch (param_2) {
        case 4:
            if (func_8080414C_chquiz(param_0)) {
                if (func_80800C00_chquiz(param_0) == param_1) {
                    func_800C3FC0(0x42B, 1.0f, 32000);
                    return;
                }
                if (func_80800E44_chquiz(func_80100094(param_0, 0)) == param_1) {
                    func_808040D4_chquiz(param_0);
                    return;
                }
                func_80804110_chquiz(param_0);
                func_80800BD4_chquiz(param_0, param_1);
                return;
            }
            break;
        case 0:
            func_80800218_chquiz(local_0, func_80100094(param_0, 0));
            break;
        case 9:
            func_80801710_chquiz(func_80100094(param_0, 0));
            if (_suquiz_entrypoint_4() != 2) {
                _gcnewoption_entrypoint_25(local_0, 1);
                if (((u8 *) func_80100094(param_0, 0))[0x98] == 1) {
                    _suquiz_entrypoint_19(3);
                    return;
                }
            }
            break;
        case 2:
        case 3:
            func_808008D4_chquiz(param_0);
            break;
    }
}

void func_80800728_chquiz(Actor *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    QuizOptions32 local_2;
    s32 local_3;

    local_0 = *(s32 *) ((u8 *) func_80100094(param_0, 0) + 0x94);
    local_1 = func_80800E44_chquiz(func_80100094(param_0, 0));
    local_2 = D_808070B8_chquiz;
    if (!_suquiz_entrypoint_15(param_1)) {
        local_3 = func_800DC128(0, 3);
        local_2.values[local_1] = -1;
        if (func_80800C00_chquiz(param_0) != -1) {
            local_2.values[func_80800C00_chquiz(param_0)] = -1;
        }
        while (local_2.values[local_3]) {
            local_3 = func_800DC128(0, 3);
        }
        _gcnewoption_entrypoint_41(local_0, local_3);
    } else {
        _gcnewoption_entrypoint_41(local_0, local_1);
    }
    _gcnewoption_entrypoint_26(local_0, 1);
}

void func_8080085C_chquiz(s32 param_0)
{
    if ((*(u8 *) ((s8 *) (func_80100094(param_0, 0)) + (0x98))) != 0) {
        func_808005C0_chquiz(
            param_0,
            _gcnewoption_entrypoint_45((*(s32 *) ((s8 *) (func_80100094(param_0, 0)) + (0x94)))),
            4);
    }
}

void func_808008B0_chquiz(s32 param_0)
{
    s8 *var = func_80100094(param_0, 0);
    var[0x99] = 0;
}

void func_808008D4_chquiz(s32 param_0)
{
    s32 local_1;

    local_1 = (*(s32 *) ((s8 *) (func_80100094(param_0, 0)) + (0x94)));
    if (local_1 != 0) {
        _gcnewoption_entrypoint_7(local_1);
        heap_free(local_1);
        (*(s32 *) ((s8 *) (func_80100094(param_0, 0)) + (0x94))) = 0;
        (*(s8 *) ((s8 *) (func_80100094(param_0, 0)) + (0x98))) = 0;
        (*(s8 *) ((s8 *) (func_80100094(param_0, 0)) + (0x99))) = 0;
    }
}

s32 func_80800944_chquiz(Actor *param_0, s32 param_1)
{
    QuizFlagView1214 *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    switch (func_80800B90_chquiz(param_1)) {
        case 0:
            local_1 = param_1 - 0x1910;
            local_2 = local_0->local_0[local_1 >> 3];
            return (1 << (local_1 & 7)) & local_2;
        case 1:
            local_1 = param_1 - 0x1A00;
            local_2 = local_0->local_1[local_1 >> 3];
            return (1 << (local_1 & 7)) & local_2;
    }
    return 0;
}

void func_808009D8_chquiz(Actor *param_0, s32 param_1)
{
    QuizFlagView1214 *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    switch (func_80800B90_chquiz(param_1)) {
        case 0:
            local_1 = param_1 - 0x1910;
            local_2 = local_0->local_0[local_1 >> 3];
            local_2 = (1 << (local_1 & 7)) | local_2;
            local_0->local_0[local_1 >> 3] = local_2;
            break;
        case 1:
            local_1 = param_1 - 0x1A00;
            local_2 = local_0->local_1[local_1 >> 3];
            local_2 = (1 << (local_1 & 7)) | local_2;
            local_0->local_1[local_1 >> 3] = local_2;
            break;
    }
}

s32 func_80800A70_chquiz(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    func_80800DA8_chquiz(param_0, local_0);
    if (_suquiz_entrypoint_12()) {
        local_3 = 0x1A00;
        local_4 = 0x1A88;
    } else {
        local_3 = 0x1910;
        local_4 = 0x19FF;
    }
    local_2 = local_4 - local_3;
    while (func_80800944_chquiz(param_0, local_1 = func_800DC128(local_3, local_4 + 1))) {
        local_2--;
        if (!local_2) {
            func_80800C24_chquiz(param_0);
        }
    }
    func_808009D8_chquiz(param_0, local_1);
    func_80800BD4_chquiz(param_0, -1);
    *(s32 *) (local_0 + 0xCC) = local_1;
    return local_1;
}

s32 func_80800B6C_chquiz(s32 param_0)
{
    return (*(s32 *) ((s8 *) (func_80100094(param_0, 0)) + (0xCC)));
}

int func_80800B90_chquiz(param_0)
s32 param_0;
{
    if (param_0 >= 0x1910 && param_0 < 0x1A00) {
        return 0;
    }
    if (param_0 >= 0x1A00 && param_0 < 0x1A89) {
        return 1;
    }
    return 2;
}

int func_80800BD4_chquiz(param_0, param_1)
s32 param_0;
int param_1;
{
    *(s32 *) ((char *) func_80100094(param_0, 0) + 0xD0) = param_1;
}

s32 func_80800C00_chquiz(param_0)
s32 param_0;
{
    return (*(s32 *) ((s8 *) (func_80100094(param_0, 0)) + (0xD0)));
}

void func_80800C24_chquiz(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 30; local_1++) {
        local_0[0x9C + local_1] = 0;
    }
    for (local_1 = 0; local_1 < 17; local_1++) {
        local_0[0xBA + local_1] = 0;
    }
}

s16 func_80800C8C_chquiz(u8 *param_0, s32 *param_1)
{
    s32 local_1;
    u8 local_2;

    local_1 = *param_1 * 0;
    local_2 = param_0[*param_1];
    do {
        local_1 = local_2 + local_1 * 10 - '0';
        local_2 = param_0[++*param_1];
    } while (local_2 != ',' && local_2 != 0);
    return local_1;
}

void func_80800CE8_chquiz(Actor *param_0, s32 *param_1, s32 *param_2)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;

    local_2 = func_80800B6C_chquiz(param_0);
    local_0 = _gldbstring_entrypoint_0(0, local_2);
    local_1 = 3;
    while (local_0[local_1] != 0x8E) {
        local_1 += local_0[local_1 + 1] + 2;
    }
    local_1 += 3;
    *param_1 = func_80800C8C_chquiz(local_0, &local_1);
    local_1++;
    *param_2 = func_80800C8C_chquiz(local_0, &local_1);
    _gldbstring_entrypoint_2(local_2);
}

void func_80800DA8_chquiz(param_0, param_1) Actor *param_0;
QuizOrderState *param_1;
{
    s32 local_0;
    s32 local_1;
    s8 local_2;
    for (local_0 = 0; local_0 < 3; local_0++)
        param_1->local_0[local_0] = local_0;
    for (local_0 = 0; local_0 < 3; local_0++) {
        local_1 = func_800DC128(0, 3);
        local_2 = param_1->local_0[local_0];
        param_1->local_0[local_0] = param_1->local_0[local_1];
        param_1->local_0[local_1] = local_2;
    }
}

int func_80800E38_chquiz(param_0, param_1)
s32 param_0;
s32 param_1;
{
    return *(s8 *) (param_0 + param_1 + 0x60);
}

int func_80800E44_chquiz(param_0)
Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    s32 local_3;
    s32 local_4;
    local_0 = _gldbstring_entrypoint_0(0, *(s32 *) ((u8 *) param_0 + 0xCC));
    local_1 = 3;
    while (local_0[local_1] != 0x8D) {
        local_1 += local_0[local_1 + 1] + 2;
    }
    local_3 = local_0[local_1 + 2] - 0x31;
    _gldbstring_entrypoint_2(*(s32 *) ((u8 *) param_0 + 0xCC));
    local_4 = 0;
    do {
        if (local_3 == ((s8 *) param_0)[0x60 + local_4])
            return local_4;
        local_4++;
    } while (local_4 != 3);
    return local_4;
}

void func_80800EF4_chquiz(s16 param_0, f32 *param_1, f32 *param_2)
{
    func_800A5800(param_0);
    _cadbfunc_entrypoint_0(param_1);
    _cadbfunc_entrypoint_2(param_2);
}

int func_80800F34_chquiz(s32 param_0[3], s32 *param_1)
{
    s32 local_1;
    local_1 = func_800F5EF8(func_800A9478(func_800A89F8()));
    *(u8 *) (param_1 + 0x17) = 3;
    *(s16 *) (param_1 + 0x14) = 0;
    _ncpod_entrypoint_16(local_1, param_0[0], 0x2C, 0x804);
    _ncpod_entrypoint_12(func_80110024(local_1), 0);
    func_80801170_chquiz(param_0, param_1);
    func_8010FD88(local_1);
}

s32 func_80800FBC_chquiz(void *arg)
{
    s32 new_var;
    unsigned long pad;
    s32 local_0;
    local_0 = func_800A89F8();
    local_0 = func_800A9478(local_0);
    local_0 = func_800F5EF8(local_0);
    ;
    new_var = local_0;
    if (0x2C == _ncpod_entrypoint_18(local_0)) {
        _ncpod_entrypoint_17(new_var, 0);
    }
}

void func_8080100C_chquiz(s32 param_0, struct QuizCamera29 *param_1, u8 param_2)
{
    QuizEnt *local_0 = &D_808070E4_chquiz[param_2];
    func_80801058_chquiz(param_0, param_1, local_0->w4, local_0->b2, local_0->b0, local_0->b1);
}

void func_80801058_chquiz(s32 param_0, QuizCamera29 *param_1, f32 param_2, s8 param_3, s8 param_4,
                          s8 param_5)
{
    s16 local_0;
    void *local_1;
    void *local_2;

    f32 *local_4;
    f32 local_5;
    local_0 = D_808070C4_chquiz[param_3 * 10 + param_4];
    local_1 = func_800F5EF8(func_800A9478(func_800A89F8()));
    local_2 = func_80110024(local_1);
    if (_ncpod_entrypoint_13(local_2)) {
        func_8010FFB0(local_1, param_1->cameraPosition, param_1->cameraRotation);
        _ncpod_entrypoint_12(local_2, 0);
    }
    if (local_0 != param_1->camera) {
        local_4 = param_1->cameraRotation;
        func_80800EF4_chquiz(local_0, param_1->targetPosition, param_1->targetRotation);
        func_800EE7F8(param_1->position, param_1->cameraPosition);
        func_800EE7F8(param_1->rotation, local_4);
        if (param_5 == 0)
            local_5 = 0.0f;
        else
            local_5 = param_2;
        param_1->duration = local_5;
        param_1->elapsed = local_5;
        param_1->moving = param_5;
        param_1->camera = local_0;
    }
}

s32 func_80801170_chquiz(param_0, param_1)
s32 param_0;
u8 *param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    f32 local_3;
    f32 local_7;
    s32 local_4;
    void *local_x;

    local_2 = func_800D90A4((f32 *) (param_1 + 0x54));
    local_3 = func_800F12D4(*(f32 *) (param_1 + 0x54), *(f32 *) (param_1 + 0x58), 0.0f, 0.0f, 1.0f);
    local_x = func_800A9478(func_800A89F8());
    local_4 = func_80110024(func_800F5EF8(local_x));
    if (param_1[0x5C] != 4) {
        local_7 = _ncpod_entrypoint_10(local_4);
        if (local_7 != 40.0f)
            _ncpod_entrypoint_9(local_4, func_800F15F8(local_7, 40.0f, 0.5f));
    }
    switch (param_1[0x5C]) {
        case 0:
            func_800EE7F8((f32 *) (param_1 + 0x38), ((f32 *) (param_1 + 0x1C)));
            func_800EE7F8((f32 *) (param_1 + 0x44), ((f32 *) (param_1 + 0x28)));
            _ncpod_entrypoint_8(local_4, ((f32 *) (param_1 + 0x1C)), ((f32 *) (param_1 + 0x28)));
            break;
        case 1:
            func_800EFE50(local_0, (f32 *) param_1, (f32 *) (param_1 + 0x1C), local_3);
            func_800F16AC(local_1, (f32 *) (param_1 + 0xC), (f32 *) (param_1 + 0x28), local_3);
            func_800EE7F8((f32 *) (param_1 + 0x38), local_0);
            func_800EE7F8((f32 *) (param_1 + 0x44), local_1);
            _ncpod_entrypoint_8(local_4, local_0, local_1);
            break;
        case 2:
            func_800EFE50(local_0, (f32 *) param_1, (f32 *) (param_1 + 0x1C), 0.5f);
            func_800EFB24(local_1, (f32 *) param_1, local_0);
            func_800EF934(local_1, local_1, 180.0f * local_3);
            func_800EF04C(local_0, local_1);
            local_0[1] = func_800F1214(local_3, *(f32 *) (param_1 + 4), *(f32 *) (param_1 + 0x20));
            func_800F16AC(local_1, (f32 *) (param_1 + 0xC), (f32 *) (param_1 + 0x28), local_3);
            func_800EE7F8((f32 *) (param_1 + 0x38), local_0);
            func_800EE7F8((f32 *) (param_1 + 0x44), local_1);
            _ncpod_entrypoint_8(local_4, local_0, local_1);
            break;
        case 3:
        case 4:
            break;
    }
    if (local_2 && param_1[0x5C] != 3 && param_1[0x5C] != 4) {
        param_1[0x5C] = 3;
        func_800EE7F8((f32 *) param_1, (f32 *) (param_1 + 0x1C));
        func_800EE7F8(((f32 *) (param_1 + 0xC)), ((f32 *) (param_1 + 0x28)));
    }
    return local_2;
}

s32 func_808013E0_chquiz(s32 param_0, u8 *param_1)
{
    s32 local_0;
    int new_var;
    local_0 = (param_1[0x5C] == 3) || (new_var = param_1[0x5C] == 4);
    return;
}

void func_80801408_chquiz(Actor *param_0, u8 *param_1, s32 param_2, u32 param_3)
{
    _ncpod_entrypoint_20(func_800F5EF8(func_800A9478(func_800A89F8())), param_0->unk0, param_2,
                         param_3 | 0x20);
    param_1[0x5C] = 4;
}

void func_80801470_chquiz(s32 param_0, u8 *param_1)
{
    if (param_1[0x5C] == 4) {
        func_8010FFB0(func_800F5EF8(func_800F54E4()), param_1 + 0x38, param_1 + 0x44);
        param_1[0x5C] = 3;
        _ncpod_entrypoint_12(func_80110024(func_800F5EF8(func_800A9478(func_800A89F8()))), 0);

    }
}

void func_808014F8_chquiz(s32 param_0, s32 param_1) {
    _ncpod_entrypoint_15(func_80110024(func_800F5EF8(func_800A9478(func_800A89F8()))), param_0, param_1);
}

s32 func_80801544_chquiz(s32 param_0){
    return param_0 | 0;
}

int func_8080154C_chquiz(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  if (func_800D3948(param_0))
  {
    if (_gcstatusDll_entrypoint_17())
    {
      return _suquiz_entrypoint_16();
    }
    {
      local_0 = _gcstatusDll_entrypoint_18();
      local_1 = 0;
      for (local_2 = 3; local_2 < 7; local_2++)
      {
        local_1 |= func_80801784_chquiz(param_0 | 0, local_2) >= local_0;
      }

      return local_1;
    }
}
return _suquiz_entrypoint_16();
}

s32 func_80801600_chquiz(Actor *param_0)
{
    s32 local_0;

    if (((QuizTimerState *) param_0)->local_2) {
        ((QuizTimerState *) param_0)->local_1 = ((QuizTimerState *) param_0)->local_0;
        ((QuizTimerState *) param_0)->local_0 -= func_800D9004();
        local_0 = ((QuizTimerState *) param_0)->local_0 <= 0.0f;

if (!local_0) {
    if (func_800F13C4(((QuizTimerState *) param_0)->local_1, 1.0f) <
        func_800F13C4(((QuizTimerState *) param_0)->local_0, 1.0f)) {
        func_800C3FC0(0x3E9, 1.2f, 32000);
    }
} else {

func_800C3FC0(0x4D5, 1.0f, 10000);
}
func_800D2498(0x116, (s32)((QuizTimerState *)param_0)->local_0, 0);
return local_0;
}
return 0;
}

void func_808016F8_chquiz(u8 *param_0, s32 param_1, f32 param_2) {
    param_0[0x90] = param_1;
    *(f32 *)(param_0 + 0x8C) = param_2;
    *(f32 *)(param_0 + 0x88) = param_2;
    *(f32 *)(param_0 + 0x84) = param_2;
}

void func_80801710_chquiz(void *param_0) {
    ((u8 *)param_0)[0x90] = 1;
}

func_8080171C_chquiz(u8 *param_0) {
    return param_0[0x90];
}

void func_80801724_chquiz(u8 *param_0)
{
    s32 local_0;

    for (local_0 = 0; local_0 < 7; local_0++) {
        ((s32 *)(param_0 + 0x64))[local_0] = 0;
    }
    *(s32 *)(param_0 + 0x80) = -1;
}

void func_80801758_chquiz(u8 *param_0, s32 param_1) {
    *(s32 *)(param_0 + 0x80) = param_1;
}

int func_80801760_chquiz(s32 *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    local_0 = (s32)param_0 + param_2 * 4;
    (*(s32 *)((char *)(local_0) + 0x64)) += D_808071B1_chquiz[param_1];
}

int func_80801784_chquiz(param_0, param_1) s32 param_0[4]; s32 param_1;
{
    return ((s32 *)param_0)[param_1 + 0x19];
}

void func_80801794_chquiz(u8 *param_0) {
    s32 local_0;

    if (func_800D3948() != 0) {
        local_0 = (*(s32 *)((s8 *)(param_0) + (0x80))) >= 0;
        switch (local_0) {
            case 3:
            func_800D28A0(0x112);
            break;
            case 4:
            func_800D28A0(0x114);
            break;
            case 5:
            func_800D28A0(0x115);
            break;
            case 6:
            func_800D28A0(0x113);
        }
        func_800D2498(0x112, func_80801784_chquiz(param_0, 3), 0);
        func_800D2498(0x114, func_80801784_chquiz(param_0, 4), 0);
        func_800D2498(0x115, func_80801784_chquiz(param_0, 5), 0);
        func_800D2498(0x113, func_80801784_chquiz(param_0, 6), 0);
        return;
    }
    if (func_800DA298(0x582) == 0) {
        func_800D2498(0x10F, func_80801784_chquiz(param_0, 1), 0);
    }
    if (func_800DA298(0x583) == 0) {
        func_800D2498(0x110, func_80801784_chquiz(param_0, 0), 0);
    }
    func_800D2498(0x111, func_80801784_chquiz(param_0, 2), 0);
    if (_suquiz_entrypoint_4() == 2) {
        func_800D2498(0x118, 0xF, 0);
    }
}

int func_80801930_chquiz(OSPiHandle *param_0, OSIoMesg *param_1)
{
    int new_var;
    s32 local_0 = 0x186A0;
    s32 local_1 = 1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    *((s32 *) (((char *) param_1) + 0x8)) = -1;
    *((s32 *) (((char *) param_1) + 0x4)) = -1;
    *((s32 *) (((char *) param_1) + 0x0)) = -1;
    local_2 = 0;
    do
    {
        new_var = 1;
        if (_suquiz_entrypoint_9(local_2) == 0)
        {
            local_4 = func_80801784_chquiz(param_0, local_2);

if (local_4 < local_0) {
    local_0 = local_4;
    *(s32 *) ((char *) param_1 + 0x0) = local_2;
}

}
local_2 += new_var;
}
while (local_2 < 3)
    ;
local_3 = *(s32 *) ((char *) param_1 + 0x0) + 1;
if (local_3 < 3) {
    do {
        if (((((_suquiz_entrypoint_9(local_3) == 0) &&
               (func_80801784_chquiz(param_0, local_3) == local_0)) &&
              (local_3 != (*((s32 *) (((char *) param_1) + 0x0))))) &&
             (local_3 != (*((s32 *) (((char *) param_1) + 0x4))))) &&
            (local_3 != (*((s32 *) (((char *) param_1) + 0x8))))) {
            *(s32 *) ((char *) param_1 + (local_1 * 4)) = local_3;
            local_1 += 1;
        }

local_3 += 1;
}
while (local_3 != 3)
    ;
}
return local_1;
}

s32 func_80801A54_chquiz(s32 param_0, s32 *param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_1 = -100000;
    local_2 = 1;
    param_1[0] = -1;
    param_1[1] = -1;
    param_1[2] = -1;
    param_1[3] = -1;
    for (local_0 = 3; local_0 < 7; local_0++) {
        local_3 = func_80801784_chquiz(param_0, local_0);
        if (local_3 > local_1) {
            local_1 = local_3;
            param_1[0] = local_0;
        }
    }
    for (local_0 = 3; local_0 < 7; local_0++) {
        if (func_80801784_chquiz(param_0, local_0) == local_1 && local_0 != param_1[0] &&
            local_0 != param_1[1] && local_0 != param_1[2]) {
            for (local_4 = 1; param_1[local_4] != -1; local_4++) {
            }
            param_1[local_4] = local_0;
            local_2++;
        }
    }
    return local_2;
}

s32 func_80801B7C_chquiz(s32 param_0)
{
    s32 local_2;
    s32 local_1;
    s32 local_4;

    local_2 = 0x186A0;
    local_1 = 0;
    do {
        local_4 = func_80801784_chquiz(param_0, local_1);
        if ((local_4 < local_2) && (_suquiz_entrypoint_9(local_1) == 0)) {
            local_2 = local_4;
        }
        local_1 += 1;
    } while (local_1 != 3);
    return local_2;
}

s32 func_80801C08_chquiz(s32 param_0, s32 param_1)
{
    s32 quiz_question;
    s32 local_0;

    quiz_question = 3;
    for (local_0 = 3; quiz_question < 7; quiz_question++) {
        if (func_80801784_chquiz(param_0, quiz_question) >= param_1) {
            return quiz_question;
        }
    }
    return -1;
}

s32 func_80801C7C_chquiz(s32 param_0)
{
    u8 *sp1C;
    u8 *temp_v0;
    temp_v0 = _subaddiefind_entrypoint_11(0x52C, param_0);
    sp1C = temp_v0;
    func_80102424(temp_v0, 2);
    *((u8 *) (((s8 *) sp1C) + 0x65)) = (u8) (((*((u8 *) (((s8 *) sp1C) + 0x65))) & 0xFFu) | 1);
    return *((s32 *) (((s8 *) sp1C) + 0));
}

void func_80801CC4_chquiz(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    f32 local_5;

    local_2 = func_80101F24(param_0);
    func_800EE7F8(local_0, (f32 *) &param_0->actorData[4]);
    switch (D_80807220_chquiz[param_0->unk70_10].local_0) {
        case 0x596:
            func_800EEB9C(local_3, param_0->rotation[1] - 90.0f,
                          func_800138D0(func_800F10B4(local_2, 0.0f, 1.0f, 0.0f, 360.0f)) * 30.0f);
            func_800EF04C(local_0, local_3);
            local_1 = 2.0f;
            func_800EFA4C(param_0->position, *(f32 *) &param_0->actorData[4],
                          *(f32 *) &param_0->actorData[5] + -80.0f,
                          *(f32 *) &param_0->actorData[6]);
            break;
        case 0x597:
            if (local_2 < 0.65f) {
                local_1 = func_800F10B4(local_2, 0.0f, 0.65f, 2.0f, 3.0f);
                local_5 = func_800F10B4(local_2, 0.0f, 0.65f, 0.0f, 0.0f);
            } else {
                local_1 = 3.0f;
                local_5 = 0.0f;
            }
            func_800EFA4C(param_0->position, *(f32 *) &param_0->actorData[4],
                          *(f32 *) &param_0->actorData[5] + local_5 + -80.0f,
                          *(f32 *) &param_0->actorData[6]);
    }
    _chbadshad_entrypoint_1(param_0, local_0, local_1);
    switch (param_0->unk70_10) {
        case 1:
            break;
        case 2:
            if (func_80101E14(param_0, 0.1f)) {
                func_80101180(0x528, 0x6C, 0);
            } else if (func_80101E14(param_0, 0.65f)) {
                func_800BBCB8((f32 *) &param_0->actorData[4], (f32 *) &param_0->actorData[4], 1.0f,
                              4, D_8080723C_chquiz);
                func_800BBCB8((f32 *) &param_0->actorData[4], (f32 *) &param_0->actorData[4], 1.0f,
                              20, D_80807274_chquiz);
                func_800C3F48(0x7FFB5E84);
                func_800187B4(0, 1.0f, 0.2f, 0.3f);
                param_0->actorData[3] = func_800E15CC(0, 10.0f, 0.6f);
                _subaddieaudioloop_entrypoint_2(param_0);
            } else if (func_80101DDC(param_0)) {
                func_80101238(0x88, 0);
                func_80102424(param_0, 3);
                if (param_0->actorData[3]) {
                    func_800E1720(param_0->actorData[3] - 1);
                }
            }
            if (func_80101F24(param_0) < 0.65f) {
                _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808072BC_chquiz);
            }
            break;
        case 3:
            func_8010C908((s32) param_0, (s32) param_0->position);
    }
}

int chquiz_entrypoint_0()
{
    return (int) &D_808072CC_chquiz;
}

void func_80802004_chquiz(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;

    func_800EE7F8(local_0, param_0->position);
    func_800EEB9C(local_1, param_0->rotation[1], 50.0f);
    func_800EF04C(local_0, local_1);
    for (local_2 = 0; local_2 < 2; local_2++) {
        param_0->actorData[local_2 + 4] = func_800C8A98();
        func_800C8F64(param_0->actorData[local_2 + 4], 0xF);
        func_800C8E84(param_0->actorData[local_2 + 4], D_8080731C_chquiz);
        func_800C8D4C(param_0->actorData[local_2 + 4], D_80807314_chquiz);
        func_800C8CB8(param_0->actorData[local_2 + 4], local_0);
        func_800C8FE0(param_0->actorData[local_2 + 4], 1);
        local_0[1] += func_80103EF4(param_0);
    }
}

s32 func_80802108_chquiz(s32 param_0, s32 param_1)
{
    s32 i;
    s32 *local_0;

    i = 0;
    local_0 = (s32 *) param_0;
    do {
        if (local_0[0x28 / 4] != 0) {
            func_800C8FE0(local_0[0x28 / 4], param_1);
        }
        i += 4;
        local_0 += 1;
    } while (i != 8);
}

void func_8080216C_chquiz(s32 *param_0)
{
    s32 i;
    int new_var;
    int new_var2;
    for (i = 0; i < 2; i++) {
        new_var = 0;
        if (param_0[i + 10] != new_var) {
            new_var2 = 0;
            func_800C8B84(param_0[i + 10]);
            param_0[i + 10] = new_var2;
        }
    }
}

void func_808021C8_chquiz(Actor *param_0, s32 param_1, f32 *param_2)
{
    f32 local_0[3];
    if (param_1 < _gcstatusDll_entrypoint_11()) {
        if (func_800F6438(param_1)) {
            func_800F8294(param_1, param_2);
            func_800EFA4C(local_0, 0.0f, param_0->rotation[1], 0.0f);
            func_800F832C(param_1, local_0);
            func_800F4CEC(param_1, 0);
        }
    }
}

void func_80802250_chquiz(Actor *param_0)
{
    u16 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (_suquiz_entrypoint_9(param_0->unk74_7)) {
        func_800FFAB0(param_0);
        return;
    }
    switch (param_0->unk74_7) {
        case 2:
            if (func_800DA298(0x441)) {
                func_800FFAB0(param_0);
                return;
            }
            local_0[0] = _chblink_entrypoint_1(0);
            local_0[1] = _chblink_entrypoint_1(1);
            func_808021C8_chquiz(param_0, 0, D_80807328_chquiz);
            break;
        case 1:
            local_0[0] = _chblink_entrypoint_1(2);
            local_0[1] = 0;
            param_0->unk64_24 = 1;
            break;
        case 0:
            param_0->unk64_24 = 1;
            break;
        case 3:
            func_808021C8_chquiz(param_0, 0, param_0->position);
            break;
        case 4:
            func_808021C8_chquiz(param_0, 1, param_0->position);
            break;
        case 5:
            local_0[0] = _chblink_entrypoint_1(3);
            local_0[1] = _chblink_entrypoint_1(1);
            func_808021C8_chquiz(param_0, 2, param_0->position);
            break;
        case 6:
            func_808021C8_chquiz(param_0, 3, param_0->position);
            break;
        default:
            local_0[0] = 0;
            local_0[1] = 0;
    }
    func_80103140(param_0, func_80800000_chquiz(param_0->unk74_7) & 0xFFFF,
                  *((u16 *) ((u8 *) param_0->unk0 + 0x16)));
    func_80102FDC(param_0, func_80800070_chquiz(param_0->unk74_7));
    func_80802004_chquiz(param_0);
    func_80102424(param_0, param_0->unk70_10);
}

void func_80802434_chquiz(u8 *param_0, s32 param_1)
{
    s32 local_0;

    switch (param_1) {
        case 1:
            func_80802108_chquiz(param_0, 1);
            break;
        case 3:
            func_80802108_chquiz(param_0, 1);
            break;
        case 4:
            func_80802108_chquiz(param_0, 1);
            break;
        case 5:
            func_80803368_chquiz((u32) ((u16) (*(u16 *) ((s8 *) (param_0) + (0x76)))) >> 7, 1);
            break;
        case 7:
            func_80802108_chquiz(param_0, 0);
            break;
        case 8:
            func_80802108_chquiz(param_0, 1);
            break;
        case 11:
            func_80802108_chquiz(param_0, 1);
            break;
        case 10:
            func_80802108_chquiz(param_0, 0);
            break;
        case 12:
            func_8080216C_chquiz(param_0);
            break;
        case 13:
            local_0 =
                func_80801C7C_chquiz((u32) ((u16) (*(u16 *) ((s8 *) (param_0) + (0x76)))) >> 7);
            (*(s32 *) ((s8 *) (param_0) + (0x3C))) = local_0;
            func_80803320_chquiz((u32) ((u16) (*(u16 *) ((s8 *) (param_0) + (0x76)))) >> 7,
                                 local_0);
            break;
        case 14:
            func_80802108_chquiz(param_0, 1);
            break;
        case 15:
            func_800FFAB0(_subaddiefind_entrypoint_11(
                0x52B, (u32) ((u16) (*(u16 *) ((s8 *) (param_0) + (0x76)))) >> 7));
            func_800FFAB0(param_0);
            if ((((u32) ((u16) (*(u16 *) ((s8 *) (param_0) + (0x76)))) >> 7) == 2) &&
                (func_800D395C() == 0)) {
                func_800F4CC0(func_800F54E4());
                func_800F4CEC(func_800F54E4(), 0x20);
                func_800F7B9C(func_800F54E4(), 0x91);
            }
            break;
        case 16:
            func_800F4CC0(func_800F54E4());
            func_800FFAB0(param_0);
    }
    func_80102424(param_0, param_1);
}

int func_80802628_chquiz(Actor *param_0)
{
    u16 local_0;
    local_0 = *((u16 *) (((char *) param_0) + 0x76));
    local_0 = ((unsigned short) ((((((u32) local_0) >> 7) - 0x32) << 5) << 2)) | (local_0 & 0x7F);
    *((u16 *) (((char *) param_0) + 0x76)) = local_0;
    func_80108B04(param_0, 0);
}

void func_80802664_chquiz(Actor *param_0)
{
    void *local_1;

    switch (param_0->unk70_10) {
        case 1:
            break;
        case 3:
        case 4:
            if (_suquiz_entrypoint_6() == param_0->unk74_7) {
                func_80802434_chquiz(param_0, 5);
            }
            break;
        case 5:
            if (func_80101E14(param_0, func_808000E0_chquiz(param_0->unk74_7))) {
                func_80101180(0x529, 0x83, param_0->unk74_7);
                if (func_80101180(0x528, 0x83, param_0->unk74_7)) {
                    func_80802434_chquiz(param_0, 8);
                } else {
                    func_80802434_chquiz(param_0, 7);
                }
            } else if (func_80101DDC(param_0)) {
                func_80802434_chquiz(param_0, 6);
            }
            break;
        case 2:
        case 14:
            if (func_80101DDC(param_0)) {
                func_80802434_chquiz(param_0, 1);
            } else if (func_80101E14(param_0, 0.3f)) {
                _suquiz_entrypoint_28(1, param_0->unk74_7, param_0->position);
            }
            break;
        case 11:
            if (func_80101DDC(param_0)) {
                func_80802434_chquiz(param_0, 1);
            } else if (func_80101E14(param_0, 0.3f)) {
                _suquiz_entrypoint_28(1, param_0->unk74_7, param_0->position);
            }
            break;
        case 9:
            if (func_80101DDC(param_0)) {
                func_80802434_chquiz(param_0, 10);
            } else if (func_80101E14(param_0, 0.3f)) {
                _suquiz_entrypoint_28(2, param_0->unk74_7, param_0->position);
            }
            break;
        case 12:
            if (func_80101DDC(param_0)) {
                func_80802434_chquiz(param_0, 13);
            }
            break;
        case 13:
            if (func_80101E14(func_80106790(param_0->unk3C), 0.85f)) {
                _suquiz_entrypoint_28(3, param_0->unk74_7, param_0->position);
                _suquiz_entrypoint_28(3, param_0->unk74_7, param_0->position);
            } else if (func_80101E14(func_80106790(param_0->unk3C), 0.9f) &&
                       param_0->unk74_7 == 1) {
                func_800C3F48(0x7FFFFE70);
            }
    }
    if (param_0->unk74_7 == 3 || param_0->unk74_7 == 4 || param_0->unk74_7 == 5 ||
        param_0->unk74_7 == 6) {
        func_801039E4(param_0->unk0);
    }
    local_1 = func_80100094(param_0, 1);
    if (((QuizExpressionFlag481 *) param_0)->local_0 && local_1) {
        _suexpression_entrypoint_10(local_1, param_0->unk0, 0);
    }
}

void func_808029A4_chquiz(Actor *param_0)
{
    s16 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 2; local_1++) {
        if (local_0[local_1] != 0) {
            _chblink_entrypoint_3(local_0[local_1]);
        }
    }
    if (func_80100094(param_0, 1) != 0) {
        _suexpression_entrypoint_8(param_0, 1);
    }
    func_8080216C_chquiz(param_0);
}

s32 func_80802A2C_chquiz(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x3D: {
            Actor *local_1;
            s32 local_5;
            local_1 = (Actor *) _subaddiefind_entrypoint_11(0x52C, param_0->unk74_7);

            if (local_1 == 0) {
                local_1 =
                    (Actor *) func_80108528(0x52C, (char *) param_0 + 4,
                                            (s32) *(f32 *) ((char *) param_0 + 0x48), &param_0);

                func_800EFA4C((char *) local_1 + 0x28, *(f32 *) ((char *) param_0 + 4),
                              *(f32 *) ((char *) param_0 + 8), *(f32 *) ((char *) param_0 + 0xC));

                func_800EFA4C((char *) local_1 + 4, *(f32 *) ((char *) param_0 + 4),
                              param_0->position[1] + -80.0f, *(f32 *) ((char *) param_0 + 0xC));

                func_8010A800(local_1, 1);

                local_1->unk74_7 = param_0->unk74_7;
            }

            if (func_800D3948()) {
                local_5 = 0;
            } else if (!func_800D395C() && func_800DA298(0x441)) {
                local_5 = 1;
            } else {
                local_5 = _suquiz_entrypoint_9(param_0->unk74_7);
            }

            if (local_5 != 0) {
                func_80102424(local_1, 3);
                func_800FFAB0(param_0);
                return 1;
            }

            local_1 = (Actor *) func_80108528(0x52B, (char *) param_0 + 4,
                                              (s32) *(f32 *) ((char *) param_0 + 0x48), &param_0);

            local_1->unk74_7 = param_0->unk74_7;

            return 1;
        }
        case 0x99:
            func_80101074(func_808000C4_chquiz(param_0->unk74_7));
            return 1;

        case 0x95:
            func_80802250_chquiz(param_0);
            return 1;

        case 0x82:
            func_80802434_chquiz(param_0, 3);
            return 1;

        case 0x83:
            if (param_2 != param_0->unk74_7) {
                func_80802434_chquiz(param_0, 7);
            }
            return 1;

        case 0x84:
            if (param_2 == param_0->unk74_7) {
                func_80802434_chquiz(param_0, 0xB);
            }
            return 1;

        case 0x85:
            if (param_2 == param_0->unk74_7) {
                func_80802434_chquiz(param_0, 9);
            }
            return 1;

        case 0x86:
            if (param_0->unk70_10 != 0xA && param_0->unk70_10 != 9) {
                func_80802434_chquiz(param_0, 4);
            }
            return 1;

        case 0x87:
            if (func_800D3948()) {
                if (param_2 == param_0->unk74_7) {
                    func_80802434_chquiz(param_0, 0xE);
                } else {
                    func_80802434_chquiz(param_0, 0xC);
                }
            } else {
                if (param_2 == param_0->unk74_7) {
                    func_80802434_chquiz(param_0, 0xC);
                } else {
                    func_80802434_chquiz(param_0, 0xE);
                }
            }
            return 1;

        case 0x88:
            if ((param_0->unk70_10) == 0xD) {
                func_80802434_chquiz(param_0, 0xF);
            }
            return 1;

        case 0x89:
            if (_suquiz_entrypoint_6() == param_0->unk74_7) {
                func_80802434_chquiz(param_0, 6);
                func_80803368_chquiz(param_0->unk74_7, 0);
            } else {
                func_80802434_chquiz(param_0, 7);
            }
            return 1;

        case 0x8A:
            if (param_2 == param_0->unk74_7) {
                func_80802434_chquiz(param_0, 0x10);
            }
            return 1;

        case 0x8B:
            if (param_2 == param_0->unk74_7) {
                func_80802434_chquiz(param_0, 2);
            }
            return 1;

        case 0x3B:
            func_80802434_chquiz(param_0, 1);
            return 1;

        case 1:
            if (_suquiz_entrypoint_11(param_0->unk74_7)) {
                return 0;
            }

            _suquiz_entrypoint_21(param_0->unk74_7, 1);
            return 1;

        case 2:
            if ((s32) param_0->unk74_7 != 2) {
                _suquiz_entrypoint_21(param_0->unk74_7, -1);
            }
            return 1;

        case 0x97: {
            f32 local_3[3];

            func_800EFA4C(local_3, 0, (1.0f / param_0->scale) * 400.0f, 0);
            func_80101010(local_3);
            return 1;
        }

        case 0x1F: {
            s16 *local_0;
            s32 local_5;
            Actor *local_1;
            f32 local_4;

            local_0 = func_80100094(param_0, 0);

            func_801015D0(param_0);

            switch (param_0->unk74_7) {
                case 2:
                    func_800DF744(3, 1);
                    func_800DF744(4, 1);
                    func_800DF744(9, 1);
                    func_800DF744(0xF, 1);
                    break;

                case 0:
                    func_800DF744(3, 0);
                    break;

                case 3:
                    func_800DF744(4, 0);
                    func_800DF744(5, 0);
                    break;

                case 4:
                    func_800DF744(3, 0);
                    func_800DF744(4, 0);
                    func_800DF744(5, 1);
                    func_800DF744(6, 1);
                    func_800DF744(7, 0);
                    func_800DF744(8, 0);
                    break;

                case 5:
                    func_800DF744(7, 1);
                    func_800DF744(0xF, 1);
                    func_800DF744(0x12, 1);
                    break;

                case 6:
                    func_800DF744(3, 0);
                    func_800DF744(5, 0);

}

for (local_5 = 0; local_5 < 2; local_5++) {
    if (local_0[local_5] != 0) {
        _chblink_entrypoint_2(local_0[local_5]);
        _chblink_entrypoint_4(local_0[local_5]);
    }

}

if ((param_0->unk70_10) == 0xD) {
    local_1 = (Actor *) func_80106790(*(void **) ((char *) param_0 + 0x3C));

if (local_1) {
    local_4 = func_80101F24(local_1);
} else {

return 1;

}

if (local_4 > 0.5f) {
    if (local_4 < 0.65f) {
        local_4 = func_800F10B4(local_4, 0.5f, 0.65f, 1.0f, 0.01f);
    } else {

local_4 = 0.01f;
}

func_800DF500(1.0f, local_4, 1.0f);
}
}

return 1;
}
case 0x29:
    switch (param_0->unk74_7) {
        case 0:
            _suexpression_entrypoint_7(param_0, 1, 0x7D);
            _suexpression_entrypoint_12(func_80100094(param_0, 1), 60.0f, 15.0f);
            return 1;

        case 1:
            _suexpression_entrypoint_7(param_0, 1, 0x7E);
            _suexpression_entrypoint_12(func_80100094(param_0, 1), 60.0f, 15.0f);
            return 1;

        case 3:
            _suexpression_entrypoint_7(param_0, 1, 0x10);
            _suexpression_entrypoint_12(func_80100094(param_0, 1), 60.0f, 15.0f);
            return 1;

        case 4:
            _suexpression_entrypoint_7(param_0, 1, 0x6F);
            _suexpression_entrypoint_12(func_80100094(param_0, 1), 60.0f, 15.0f);
            return 1;

        case 6:
            _suexpression_entrypoint_7(param_0, 1, 0x40);
            _suexpression_entrypoint_12(func_80100094(param_0, 1), 60.0f, 15.0f);
            return 1;

        default:
            return 0;
    }

case 0x2A:
    switch (param_0->unk74_7) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 6:
            _suexpression_entrypoint_8(param_0, 1);
            return 1;

        default:
            return 0;
    }

default:
    return 0;
    }
    }

    int chquiz_entrypoint_1()
    {
        return (int) &D_80807334_chquiz;
    }

    int func_80803320_chquiz(s32 param_0, s32 param_1)
    {
        Actor *local_0;
        local_0 = _subaddiefind_entrypoint_11(0x52B, param_0 | param_0);
        func_80102424(local_0, 4);
        local_0->unk3C = param_1;
    }

    void func_80803368_chquiz(Actor *param_0, s32 param_1)
    {
        Actor *local_1;
        f32 local_0[3];

        local_1 = _subaddiefind_entrypoint_11(0x52B, param_0);
        if (param_1) {
            local_1->unk64_20 = 1;
        } else {
            local_1->unk64_20 = 0;
        }
        func_80102424(local_1, 2);
        if (!_subaddieskeleton_entrypoint_2(local_1->unk0, 4, local_0)) {
            func_800EFA4C(local_0, local_1->position[0],
                          local_1->position[1] + func_80103EF4(local_1) * 0.5f,
                          local_1->position[2]);
        }
        local_1->actorData[3] = func_800C8A98();
        func_800C8F64(local_1->actorData[3], 0xF);
        func_800C8E84(local_1->actorData[3], D_80807474_chquiz);
        func_800C8D4C(local_1->actorData[3], D_8080746C_chquiz);
        func_800C8CB8(local_1->actorData[3], local_0);
        func_800C8FE0(local_1->actorData[3], 0);
    }

    void func_80803470_chquiz(param_0) Actor *param_0;
    {
        switch (param_0->unk70_10) {
            case 1:
                break;
            case 2:
                if (func_80101DDC(param_0)) {
                    param_0->unk58 = 1.0f;
                    func_80102424(param_0, 3);
                    return;
                }
                if (func_80101E14(param_0, func_808000E0_chquiz(param_0->unk74_7))) {
                    if (param_0->unk64_20)
                        _suquiz_entrypoint_28(0, param_0->unk74_7, param_0->position);
                    if (param_0->actorData[3])
                        func_800C8FE0(param_0->actorData[3], 1);
                }
                break;
            case 3:
                if (func_800D90A4(&param_0->unk58)) {
                    if (param_0->actorData[3]) {
                        func_800C8B84(param_0->actorData[3]);
                        param_0->actorData[3] = 0;
                    }
                    func_80102424(param_0, 1);
                }
        }
    }

    s32 func_80803588_chquiz(u8 *param_0, s32 param_1, s32 param_2)
    {
        u8 *sp34;
        f32 sp30;
        s32 pad2c;
        s32 pad28;
        f32 sp24;

        switch (param_1) {
            case 0x95:
                func_80103140(param_0,
                              (u16) func_8080008C_chquiz((u32) *(u16 *) (param_0 + 0x76) >> 7),
                              *(u16 *) (*(u8 **) param_0 + 0x16));
                func_80102FDC(param_0, func_808000A8_chquiz((u32) *(u16 *) (param_0 + 0x76) >> 7));
                func_80102424(param_0, (u32) *(u16 *) (param_0 + 0x72) >> 10);
                return 1;
            case 0x99:
                switch ((u32) *(u16 *) (param_0 + 0x76) >> 7) {
                    case 1:
                        func_80101074(D_8080737C_chquiz);
                        return 1;
                    case 0:
                        func_80101074(D_808073A4_chquiz);
                        return 1;
                    case 2:
                        func_80101074(D_808073CC_chquiz);
                        return 1;
                    case 3:
                        func_80101074(D_808073CC_chquiz);
                        return 1;
                    case 4:
                        func_80101074(D_8080741C_chquiz);
                        return 1;
                    case 5:
                        func_80101074(D_808073CC_chquiz);
                        return 1;
                    case 6:
                        func_80101074(D_80807444_chquiz);
                        return 1;
                    default:
                        return 0;
                }
            case 0x1F:
                func_801015D0(param_0);
                switch ((u32) *(u16 *) (param_0 + 0x76) >> 7) {
                    case 1:
                        func_800DF744(1, 2);
                        break;
                    case 0:
                        func_800DF744(1, 1);
                        break;
                    case 2:
                        func_800DF744(1, 3);
                        break;
                    case 3:
                        func_800DF744(1, 1);
                        break;
                    case 4:
                        func_800DF744(1, 2);
                        break;
                    case 5:
                        func_800DF744(1, 3);
                        break;
                    case 6:
                        func_800DF744(1, 4);
                }
                switch ((u32) *(u16 *) (param_0 + 0x72) >> 10) {
                    case 1:
                        func_800DF744(2, 1);
                        return 1;
                    case 2:
                        sp24 = func_80101F24(param_0);
                        func_800DF744(
                            2, func_808000E0_chquiz((u32) *(u16 *) (param_0 + 0x76) >> 7) < sp24
                                   ? 2
                                   : 1);
                        return 1;
                    case 3:
                        func_800DF744(2, 2);
                        return 1;
                    case 4:
                        sp34 = func_80106790(*(s32 *) (param_0 + 0x3C));
                        func_800DF744(2, 1);
                        if (sp34 != 0) {
                            sp30 = func_80101F24(sp34);
                        } else {
                            return 1;
                        }
                        if (sp30 > 0.5f) {
                            if (sp30 < 0.65f) {
                                sp30 = func_800F10B4(sp30, 0.5f, 0.65f, 1.0f, 0.01f);
                            } else {
                                sp30 = 0.01f;
                            }
                            func_800DF500(1.0f, sp30, 1.0f);
                        }
                    default:
                        return 1;
                }
            default:
                return 0;
        }
    }

    int func_80803910_chquiz(param_0)
    Actor *param_0;
    {
        if ((*(s32 *) ((char *) (param_0) + 0x24)) != 0) {
            func_800C8B84((*(s32 *) ((char *) (param_0) + 0x24)));
            (*(s32 *) ((char *) (param_0) + 0x24)) = 0;
        }
    }

    int *chquiz_entrypoint_2()
    {
        return &D_80807480_chquiz;
    }

    void func_80803954_chquiz(Actor *param_0)
    {
        switch (param_0->unk70_10) {
            case 1:
                func_80103110(param_0, 0);
                break;
            case 2:
                if (func_800D90A4(&param_0->unk58)) {
                    func_800C8B84(param_0->actorData[7]);
                    param_0->actorData[7] = 0;
                    func_80101FDC(param_0, 1);
                }
        }
    }

    int func_808039D4_chquiz(Actor *param_0, s32 param_1, s32 param_2)
    {
        f32 local_0[3];
        switch (param_1) {
            case 0x8C:
                if (param_2 != 2) {
                    func_800EE7F8(local_0, param_0->position);
                    func_800EF1B8(local_0, param_0->rotation[1], 10.0f);
                    *(s32 *) ((u8 *) param_0 + 0x34) = func_800C8A98();
                    func_800C8F64(*(s32 *) ((u8 *) param_0 + 0x34), 0xF);
                    func_800C8E84(*(s32 *) ((u8 *) param_0 + 0x34), &D_808074D0_chquiz);
                    func_800C8D4C(*(s32 *) ((u8 *) param_0 + 0x34), &D_808074C8_chquiz);
                    func_800C8CB8(*(s32 *) ((u8 *) param_0 + 0x34), local_0);
                    func_800C8FE0(*(s32 *) ((u8 *) param_0 + 0x34), 1);
                    if (((u32) *(u16 *) ((u8 *) param_0 + 0x76)) >> 7 == 0x33)
                        func_800C3F48(0x7FFFFD3B);
                    *(f32 *) ((u8 *) param_0 + 0x58) = 1.5f;
                    func_80103110(param_0, 1);
                    func_80101FDC(param_0, 2);
                } else
                    func_800C3F48(0x7FFFFD3A);
                return 1;
            case 0x1F:
                func_801015D0(param_0);
                switch (param_0->unk70_10) {
                    case 1:
                        func_800DF744(1, 1);
                        func_800DF744(2, 0);
                        return 1;
                    case 2:
                        func_800DF744(1, 0);
                        func_800DF744(2, 1);
                    default:
                        return 1;
                }
            default:
                return 0;
        }
    }

    s32 chquiz_entrypoint_3()
    {
        return D_808074DC_chquiz;
    }

    int func_80803B54_chquiz(s32 param_0[4], s32 param_1, s32 param_2)
    {
        u32 local_0;
        local_0 = param_0[0];
        return _subaddiedialog_entrypoint_11(local_0, param_1, param_2, param_0 + 1, 0x4d);
    }

    int func_80803B88_chquiz(s32 param_0)
    {
        s32 local_0;
        local_0 = func_800C8A98();
        func_800C8CB8(local_0, param_0);
        func_800C8F64(local_0, 0xF);
        func_800C8D4C(local_0, &D_8080755C_chquiz);
        func_800C8E84(local_0, &D_80807564_chquiz);
        _chlightfader_entrypoint_1(local_0, 0x40000000, 1);
    }

    void func_80803BFC_chquiz(u8 *param_0)
    {
        S16 sp90;
        S24 sp78;
        S24 sp60;
        s32 sp54[3];
        f32 sp50;
        s32 var_s1;
        s32 sp48;
        u16 temp_t1;
        s32 sp44;
        s32 sp3C;
        if ((*((u16 *) (((s8 *) param_0) + 0x64))) & 1) {
            switch (D_80807528_chquiz[((Actor *) param_0)->unk70_10].id) {
                case 0x4C4:
                    if (func_80101DDC(param_0) != 0) {
                        func_80102424(param_0, 1);
                    }
                    break;

                case 0x4C5:
                    sp90 = *(S16 *) &D_80807570_chquiz;
                    _subaddieaudioquick_entrypoint_4(param_0, param_0 + 4, &D_808075B0_chquiz,
                                                     &sp90);
                    if (func_80101DDC(param_0) != 0) {
                        func_80102424(param_0, 5);
                    }
                    break;

                case 0x4C7:
                    sp78 = *(S24 *) &D_80807580_chquiz;
                    sp60 = *(S24 *) &D_80807598_chquiz;
                    sp50 = func_80101F24(param_0);
                    _subaddieskeleton_entrypoint_0(param_0, 0x44, sp54);
                    _subaddieaudioquick_entrypoint_3(param_0, (param_0 + 4), &D_80807640_chquiz,
                                                     0.33f);
                    _subaddieaudioquick_entrypoint_3(param_0, (param_0 + 4), &D_8080765C_chquiz,
                                                     0.88f);
                    _subaddieaudioquick_entrypoint_3(param_0, (param_0 + 4), &D_80807624_chquiz,
                                                     0.09f);
                    if (func_80101E14(param_0, 0.09f) != 0) {
                        func_800C3F48(0x7FFFFE87);
                    } else if (func_80101E14(param_0, 0.2f) != 0) {
                        func_800C3F48(0x7FFFFE88);
                    } else if (func_80101E14(param_0, 0.33f) != 0) {
                        func_800C3F48(0x7FFFFE89);
                    }
                    if ((sp50 > 0.09f) && (func_800DC298(func_800F1214(sp50, 0.5f, 1.0f)) != 0)) {
                        sp48 = 0;
                        if (sp50 < 0.33f) {
                            sp48 = func_800DC298(0.75f);
                        } else if (sp50 < 0.58f) {
                            sp48 = 2;
                        } else if (sp50 < 0.88f) {
                            sp48 = 3;
                        }
                        var_s1 = 0;
                        if (sp48 > 0) {
                            do {
                                func_800EEB9C(&sp3C, (func_800DC0C0()) * 360.0f,
                                              func_80103EAC(param_0) * 0.7f);
                                func_800EF04C(&sp3C, sp54);
                                func_800BBCB8(&sp3C, &sp3C, 1.0f, 1, D_808075C0_chquiz);
                                var_s1 += 1;
                            } while (var_s1 != sp48);
                        }
                    }
                    if (((((sp50 > 0.575f) && (sp50 < 0.62f)) ||
                          ((sp50 > 0.69f) && (sp50 < 0.79f))) ||
                         ((sp50 > 0.82f) && (sp50 < 0.86f))) ||
                        ((sp50 > 0.9f) && (sp50 < 0.99f))) {
                        func_800BBCB8(sp54, sp54, 2.5f, 8, D_808075EC_chquiz);
                    }
                    if (func_80101E4C(param_0, &sp78) != 0) {
                        func_80803B88_chquiz(sp54);
                    }
                    if (func_80101DDC(param_0) != 0) {
                        if (func_800D395C() != 0) {
                            func_80804170_chquiz(param_0, 0x2C);

                        } else {
                            func_80804170_chquiz(param_0, 0x21);
                        }
                        func_80102424(param_0, 1);
                    }

                case 0x4C2:

                case 0x4C3:

                    break;
            }
        }
    }

    void func_808040D4_chquiz(u8 *param_0)
    {
        func_80804170_chquiz(param_0, *(s32 *) (param_0 + 0x34) == 15 ? 23 : 24);
    }

    void func_80804110_chquiz(u8 *param_0)
    {
        func_80804170_chquiz(param_0, *(s32 *) (param_0 + 0x34) == 15 ? 17 : 18);
    }

    s32 func_8080414C_chquiz(u8 *param_0)
    {
        s32 temp_v1;
        s32 var_v0;
        temp_v1 = *((s32 *) (((s8 *) param_0) + 0x34));
        var_v0 = temp_v1 == 0xF;
        if (var_v0 == ((temp_v1 == 0xF) * 0)) {
            var_v0 = temp_v1 == 0x10;
            return var_v0;
        }
    }

    void func_80804170_chquiz(param_0, param_1) Actor *param_0;
    s32 param_1;
    {
        extern u8 D_80807678_chquiz[];
        extern void func_8010D5DC(void);
        extern f32 _suquiz_entrypoint_8(s32);
        extern f32 func_800DC178(f32, f32);
        extern void func_8008F990(void *, f32);

        char *local_0;

        local_0 = (char *) func_80100094(param_0, 0);
        switch (param_1) {
            case 1:
                func_80801408_chquiz(param_0, local_0, 9, 0);
                func_80102424(param_0, 1);
                func_808014F8_chquiz(1, 1);
                break;

            case 2:
                func_80803B54_chquiz(param_0, 0x1460, 4);
                break;

            case 3:
                func_80803B54_chquiz(param_0, 0x1461, 4);
                break;

            case 4:
                func_80803B54_chquiz(param_0, 0x1463, 4);
                func_8080100C_chquiz(param_0, local_0, 0);
                break;

            case 5:
                func_80803B54_chquiz(param_0, 0x1465, 4);
                func_8080100C_chquiz(param_0, local_0, 1);
                break;

            case 6:
                func_80803B54_chquiz(param_0, 0x1464, 4);
                func_8080100C_chquiz(param_0, local_0, 2);
                break;

            case 7:
                if (func_800DA298(0x584)) {
                    func_80803B54_chquiz(param_0, 0x146A, 0x46);
                } else {
                    func_800DA544(0x584);
                    func_80803B54_chquiz(param_0, 0x1466, 4);
                }

                func_80801724_chquiz(local_0);
                func_8080100C_chquiz(param_0, local_0, 3);
                func_80102424(param_0, 1);
                _suquiz_entrypoint_18(1);
                _chintrotext_entrypoint_1(0x1A89, 0, 0, 2);
                break;

            case 8:
                if (func_800DA298(0x585)) {
                    func_80803B54_chquiz(param_0, 0x146B, 0x46);
                } else {
                    func_800DA544(0x585);
                    func_80803B54_chquiz(param_0, 0x1467, 4);
                }

                func_80801724_chquiz(local_0);
                func_80102424(param_0, 1);
                func_8080100C_chquiz(param_0, local_0, 4);
                _suquiz_entrypoint_18(2);
                _chintrotext_entrypoint_1(0x1A89, 1, 0, 2);
                break;

            case 9:
                func_80102424(param_0, 1);
                func_80803B54_chquiz(param_0, 0x1462, 4);
                func_8080100C_chquiz(param_0, local_0, 6);
                _suquiz_entrypoint_18(3);
                break;

            case 10:
                if (func_800DA298(0x586)) {
                    func_80803B54_chquiz(param_0, 0x146C, 0x46);
                } else {
                    func_800DA544(0x586);
                    func_80803B54_chquiz(param_0, 0x1468, 4);
                }

                func_80801724_chquiz(local_0);
                func_80102424(param_0, 1);

                func_8080100C_chquiz(param_0, local_0,
                                     *(s32 *) ((char *) param_0 + 0x34) == 9 ? 5 : 6);
                _suquiz_entrypoint_18(3);
                _chintrotext_entrypoint_1(0x1A89, 2, 0, 2);
                break;

            case 11:
                if (func_8080154C_chquiz(local_0)) {
                    if (func_800D3948()) {
                        func_80804170_chquiz(param_0, 0x35);
                        return;
                    } else {
                        func_80804170_chquiz(param_0, 0x1A);
                        return;
                    }
                }
                func_808008D4_chquiz(param_0);
                func_80800A70_chquiz(param_0);
                func_80102424(param_0, 1);
                switch (func_80800B90_chquiz(func_80800B6C_chquiz(param_0))) {
                    case 0:
                        func_80804170_chquiz(param_0, 0xD);
                        return;
                    case 1:
                        func_8080100C_chquiz(param_0, local_0, 8);
                        func_80803B54_chquiz(param_0, func_800DC128(0x14A1, 0x14A4), 0x46);
                }
                break;

            case 13: {
                s32 local_1;

                if (param_0->unk70_10 != 0xC) {
                    local_1 = 2;
                } else {
                    local_1 = 1;
                }

                func_8080100C_chquiz(param_0, local_0, 9);
                func_8080034C_chquiz(param_0, 1);
                _suquiz_entrypoint_19(local_1);
                func_808016F8_chquiz(local_0, 0, _suquiz_entrypoint_8(local_1));
                func_80101180(0x529, 0x82, 0);
                break;
            }

            case 15: {
                s32 local_1;

                local_1 = _suquiz_entrypoint_6();
                func_8080034C_chquiz(param_0, 2);
                func_80801058_chquiz(param_0, local_0, 0.5f, 0, func_80801544_chquiz(local_1), 1);

                if (!_suquiz_entrypoint_11(local_1)) {
                    *(f32 *) ((char *) param_0 + 0x18) = func_800DC178(1.0f, 2.0f);
                    *(u8 *) ((char *) param_0 + 0x65) &= ~0x10;
                    *(f32 *) ((char *) param_0 + 0x1C) = 1.0f;
                }

                _suquiz_entrypoint_19(3);
                func_808016F8_chquiz(local_0, 1, _suquiz_entrypoint_8(3));
                break;
            }

            case 17:
                func_80102424(param_0, 2);
                func_800FC660(0xF);
                func_8080100C_chquiz(param_0, local_0, 0xD);

                if (_suquiz_entrypoint_4() == 2) {
                    func_80803B54_chquiz(param_0, func_800DC128(0x1485, 0x148B), 0x46);
                    func_8080034C_chquiz(param_0, 0);
                } else {
                    func_80803B54_chquiz(param_0, func_800DC128(0x1479, 0x147F), 0x46);
                }

                func_808008B0_chquiz(param_0);
                func_80801760_chquiz(local_0, 0x63, _suquiz_entrypoint_6());
                break;

            case 19:
                func_8080100C_chquiz(param_0, local_0, 0xB);

                if (_suquiz_entrypoint_4() == 2) {
                    func_80803B54_chquiz(param_0, func_800DC128(0x14B0, 0x14B6), 0x46);
                } else {
                    func_80803B54_chquiz(param_0, func_800DC128(0x14AA, 0x14B0), 0x46);
                }
                func_808008B0_chquiz(param_0);
                func_80801760_chquiz(local_0, 0x67, _suquiz_entrypoint_6());
                break;

            case 14:
                func_8080100C_chquiz(param_0, local_0, 0xA);
                func_80101180(0x529, 0x85, _suquiz_entrypoint_6());
                _suquiz_entrypoint_19(4);
                func_80101180(0x529, 0x86, 0);
                func_8080034C_chquiz(param_0, 3);
                func_808016F8_chquiz(
                    local_0,
                    _gcnewoption_entrypoint_47(*(s32 *) ((u8 *) func_80100094(param_0, 0) + 0x94)),
                    _suquiz_entrypoint_8(4));
                break;

            case 16: {
                s32 local_1;

                local_1 = _suquiz_entrypoint_6();
                func_8080034C_chquiz(param_0, 4);
                func_80801058_chquiz(param_0, local_0, 0.5f, 0, func_80801544_chquiz(local_1), 1);

                if (!_suquiz_entrypoint_11(local_1)) {
                    *(f32 *) ((char *) param_0 + 0x18) = func_800DC178(1.0f, 2.0f);
                    *(u8 *) ((char *) param_0 + 0x65) &= ~0x10;
                    *(f32 *) ((char *) param_0 + 0x1C) = 2.0f;
                }

                _suquiz_entrypoint_19(5);
                func_808016F8_chquiz(local_0, 1, _suquiz_entrypoint_8(5));
                break;
            }

            case 18:
                func_80102424(param_0, 2);
                func_8080100C_chquiz(param_0, local_0, 0xA);
                func_800FC660(0xF);

                if (_suquiz_entrypoint_4() == 2) {
                    func_80803B54_chquiz(param_0, func_800DC128(0x14B6, 0x14BC), 0x46);
                } else {
                    func_80803B54_chquiz(param_0, func_800DC128(0x147F, 0x1485), 0x46);
                }

                func_808008B0_chquiz(param_0);
                func_8080034C_chquiz(param_0, 0);
                func_80801760_chquiz(local_0, 0x64, _suquiz_entrypoint_6());
                break;

            case 20:
                func_8080100C_chquiz(param_0, local_0, 0xB);
                func_80803B54_chquiz(param_0, func_800DC128(0x14DA, 0x14E0), 0x46);
                func_808008B0_chquiz(param_0);
                func_80801760_chquiz(local_0, 0x68, _suquiz_entrypoint_6());
                func_8080034C_chquiz(param_0, 0);
                break;

            case 22:
                func_8080100C_chquiz(param_0, local_0, 0xC);

                if (_suquiz_entrypoint_4() == 2) {
                    func_80803B54_chquiz(param_0, func_800DC128(0x14BC, 0x14C2), 0x46);
                } else {
                    func_80803B54_chquiz(param_0, func_800DC128(0x146D, 0x1473), 0x46);
                }
                func_8080034C_chquiz(param_0, 0);
                break;

            case 21:
                func_8080100C_chquiz(param_0, local_0, 0x11);
                func_80803B54_chquiz(param_0, func_800DC128(0x149A, 0x14A0), 0x46);
                func_8080034C_chquiz(param_0, 0);
                break;

            case 23:
                func_80102424(param_0, 3);
                func_800FC660(0xE);
                func_808008B0_chquiz(param_0);
                func_8080100C_chquiz(param_0, local_0, 0xF);
                func_80803B54_chquiz(param_0, func_800DC128(0x1473, 0x1479), 0x46);
                func_8080034C_chquiz(param_0, 0);
                func_80801760_chquiz(local_0, 0x65, _suquiz_entrypoint_6());
                break;

            case 24:
                func_80102424(param_0, 3);
                func_800FC660(0xE);
                func_808008B0_chquiz(param_0);
                func_8080100C_chquiz(param_0, local_0, 0x10);
                func_80803B54_chquiz(param_0, func_800DC128(0x14A4, 0x14AA), 0x46);
                func_8080034C_chquiz(param_0, 0);
                func_80801760_chquiz(local_0, 0x66, _suquiz_entrypoint_6());
                break;

            case 25:
                func_80102424(param_0, 1);

                func_80101180(0x529, 0x84, _suquiz_entrypoint_6());

                func_80101180(0x52E, 0x8C, _suquiz_entrypoint_6());

                func_80801058_chquiz(param_0, local_0, 1.0f, 0,
                                     func_80801544_chquiz(_suquiz_entrypoint_6()), 0);

                *(f32 *) ((char *) param_0 + 0x18) = 2.0f;
                break;

            case 26: {
                s32 local_1 = 0;
                s32 local_2[3];
                s32 local_3;

                func_80101180(0x529, 0x3B, 0);
                func_8080100C_chquiz(param_0, local_0, 0x12);
                if (_suquiz_entrypoint_4() == 2) {
                    func_80804170_chquiz(param_0, 0x1F);
                    if (func_80801784_chquiz(local_0, 2) < 0xF) {
                        local_1 = 0x1491;
                    } else {
                        func_808014F8_chquiz(1, 1);
                        local_1 = 0x1492;
                    }
                    func_80803B54_chquiz(param_0, local_1, 0x4E);
                    param_0->unk6C_0 = 2;
                    return;
                }
                local_3 = func_80801930_chquiz(local_0, local_2);
                if (local_3 == 1) {
                    param_0->unk6C_0 = local_2[0];
                    switch (param_0->unk6C_0) {
                        case 1:
                            local_1 = _suquiz_entrypoint_4() == 0 ? 0x148D : 0x1490;
                            break;
                        case 0:
                            local_1 = _suquiz_entrypoint_4() == 0 ? 0x148B : 0x148E;
                            break;
                        case 2:
                            local_1 = _suquiz_entrypoint_4() == 0 ? 0x148C : 0x148F;
                    }
                } else {
                    local_1 = _suquiz_entrypoint_4() == 0 ? 0x14C7 : 0x14C8;
                    param_0->unk6C_0 = local_2[func_800DC128(0, local_3)];
                }
                func_80803B54_chquiz(param_0, local_1, 0x46);
                break;
            }

            case 27:
                func_8080100C_chquiz(param_0, local_0, 0x13);
                break;

            case 28:
                func_80101180(0x529, 0x87, param_0->unk6C_0);
                _suquiz_entrypoint_20(param_0->unk6C_0);
                break;

            case 29:
                *(f32 *) ((char *) param_0 + 0x18) = 2.0f;
                break;

            case 30:
                func_8080100C_chquiz(param_0, local_0, 0x14);
                func_80102424(param_0, 4);
                break;

            case 32:
                func_80102424(param_0, 6);
                func_8080100C_chquiz(param_0, local_0, 0x19);
                break;

            case 33:
                _suquiz_entrypoint_18(4);
                _suquiz_entrypoint_2();
                func_80101180(0x4CD, 7, 0);

                func_80801408_chquiz(param_0, func_80100094(param_0, 0), 0x13, 0x10);

                *(u8 *) ((char *) param_0 + 0x65) &= ~1;
                break;

            case 34:
                func_80101180(0x529, 0x8A, 2);

                func_80801058_chquiz(param_0, local_0, 1.5f, 0, 9, 1);

                _subaddiedialog_entrypoint_11(*(s32 *) ((char *) param_0 + 0), 0x14A0, 0xC,
                                              (char *) param_0 + 4, 0xC);
                break;

            case 35:
                func_8008F8B0();
                func_8008F8D8(1);
                func_8008F990(D_80807678_chquiz, 500.0f);
                func_8008F904(func_8010D5DC, *(s32 *) ((char *) param_0 + 0));

                func_80801408_chquiz(param_0, local_0, 0x15, 0x40);

                *(f32 *) ((char *) param_0 + 0x18) = 0.3f;
                break;

            case 36:
                func_80801058_chquiz(param_0, local_0, 2.5f,
                                     _glglobalsettings_entrypoint_3() ? 2 : 0, 7, 1);
                func_808014F8_chquiz(0, 1);
                break;

            case 37:
                _gcgoto_entrypoint_2(0x19C, 0, 0);
                break;

            case 38:
                _suquiz_entrypoint_18(1);
                func_8080100C_chquiz(param_0, local_0, 0x21);
                func_80803B54_chquiz(param_0, 0x14CC, 0x46);
                break;

            case 39:
                _suquiz_entrypoint_18(2);
                func_8080100C_chquiz(param_0, local_0, 0x22);
                func_80803B54_chquiz(param_0, 0x14CD, 0x46);
                break;

            case 40:
                _suquiz_entrypoint_18(3);
                func_8080100C_chquiz(param_0, local_0, 0x23);
                func_80803B54_chquiz(param_0, 0x14CE, 0x46);
                break;

            case 41:
                func_80801724_chquiz(local_0);
                func_8080100C_chquiz(param_0, local_0, 3);
                func_80803B54_chquiz(param_0, 0x14D3, 0x46);
                break;

            case 42:
                func_80801724_chquiz(local_0);
                func_8080100C_chquiz(param_0, local_0, 3);
                func_80803B54_chquiz(param_0, 0x14D4, 0x46);
                break;

            case 43:
                func_80801724_chquiz(local_0);
                func_8080100C_chquiz(param_0, local_0, 3);
                func_80803B54_chquiz(param_0, 0x14D5, 0x46);
                break;

            case 44:
                func_8080100C_chquiz(param_0, local_0, 0x24);
                func_80803B54_chquiz(param_0, 0x14CF, 0x46);
                break;

            case 45:
                func_8080100C_chquiz(param_0, local_0, 0x25);
                func_80803B54_chquiz(param_0, 0x14D0, 0x46);
                break;

            case 46:
                func_8080100C_chquiz(param_0, local_0, 0x1A);
                func_80803B54_chquiz(param_0, 0x1469, 0x46);
                break;

            case 47:
                func_8080100C_chquiz(param_0, local_0, 0x1B);
                func_80803B54_chquiz(param_0, 0x14D6, 0x46);
                break;

            case 48:
                func_8080100C_chquiz(param_0, local_0, 0x1C);
                func_80803B54_chquiz(param_0, 0x14C2, 0x46);
                break;

            case 49:
                func_8080100C_chquiz(param_0, local_0, 0x1D);
                func_80803B54_chquiz(param_0, 0x14C3, 0x46);
                break;

            case 50:
                func_8080100C_chquiz(param_0, local_0, 0x1E);
                func_80803B54_chquiz(param_0, 0x14C4, 0x46);
                break;

            case 51:
                func_8080100C_chquiz(param_0, local_0, 0x1F);
                func_80803B54_chquiz(param_0, 0x14C5, 0x46);
                break;

            case 52:
                func_8080100C_chquiz(param_0, local_0, 0x1B);
                func_80803B54_chquiz(
                    param_0, (f32) _gcstatusDll_entrypoint_17() == 0.0f ? 0x14C6 : 0x14D9, 0x46);
                break;

            case 53: {
                s32 local_1;
                s32 local_2;
                s32 local_3[3];
                s32 local_4;

                func_8080100C_chquiz(param_0, local_0, 0x1A);
                if ((f32) _gcstatusDll_entrypoint_17() != 0.0f) {
                    local_2 = func_80801A54_chquiz(local_0, local_3);
                    if (local_2 == 1) {
                        param_0->unk6C_0 = local_3[0];
                        local_1 = 0x1493;
                    } else {
                        local_1 = 0x1495;
                        local_4 = func_800DC128(0, local_2);
                        param_0->unk6C_0 = local_3[local_4];
                    }
                } else {
                    param_0->unk6C_0 = func_80801C08_chquiz(local_0, _gcstatusDll_entrypoint_18());
                    local_1 = 0x1494;
                }
                func_80801758_chquiz(local_0, param_0->unk6C_0);
                func_80803B54_chquiz(param_0, local_1, 0x46);
                func_800FC660(0x10);
                break;
            }

            case 54:
                func_8080100C_chquiz(param_0, local_0, 0x13);
                break;

            case 55:
                func_80101180(0x529, 0x87, param_0->unk6C_0);
        }

        *(s32 *) ((char *) param_0 + 0x34) = param_1;
    }

    int func_808053BC_chquiz(param_0)
    Actor *param_0;
    {
        u8 *local_0;

        local_0 = func_80100094(param_0, 0);
        func_8010A828(param_0, 9);
        *(u8 *) ((char *) local_0 + 0x98) = 0;
        _suquiz_entrypoint_0();
        func_80800C24_chquiz(param_0);
    }

    void func_80805404_chquiz(param_0) Actor *param_0;
    {
        Actor *local_0;
        s32 local_2;
        s32 local_1;

        local_0 = func_80100094(param_0, 0);
        switch (param_0->actorData[7]) {
            case 1:
                if (_capod_entrypoint_17(0.095f)) {
                    func_80804170_chquiz(param_0, 2);
                }
                break;
            case 0xB:
                func_80801794_chquiz(local_0);
                break;
            case 0xC:
                if (func_808013E0_chquiz(param_0, local_0)) {
                    func_80800CE8_chquiz(param_0, &local_1, &local_2);
                    _suquiz_entrypoint_19(0);
                    _suquiz_entrypoint_22((u8 *) local_0 + 0x38, (u8 *) local_0 + 0x44);
                    _suquiz_entrypoint_24(local_1, local_2);
                }
                func_80801794_chquiz(local_0);
                break;
            case 0xD:
                if (_suquiz_entrypoint_4() == 2 && func_80016B54(0, 0) &&
                    func_8080171C_chquiz(local_0)) {
                    func_80804170_chquiz(param_0, 0x15);
                }
                if (func_80801600_chquiz(local_0)) {
                    func_80804170_chquiz(param_0, 0x16);
                }
                func_80801794_chquiz(local_0);
                break;
            case 0xE:
                if (func_80801600_chquiz(local_0)) {
                    func_80804170_chquiz(param_0, 0x16);
                }
                func_80801794_chquiz(local_0);
                break;
            case 0xF:
            case 0x10:
                if (_suquiz_entrypoint_4() == 2) {
                    if (func_80016B54(0, 0)) {
                        func_80804170_chquiz(param_0, 0x15);
                    }
                } else if (!_suquiz_entrypoint_11(_suquiz_entrypoint_6()) &&
                           func_800D90A4(&param_0->actorData[0])) {
                    if (!param_0->unk64_20) {
                        func_80800728_chquiz(param_0, _suquiz_entrypoint_6());
                        param_0->unk64_20 = 1;
                    } else if (func_800D90A4(&param_0->actorData[1])) {
                        func_8080085C_chquiz(param_0);
                    }
                }
                if (func_80801600_chquiz(local_0)) {
                    func_80804170_chquiz(param_0, param_0->actorData[7] == 0x10 ? 0x14 : 0x13);
                }
                func_80801794_chquiz(local_0);
                break;
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x16:
                func_80801794_chquiz(local_0);
                break;
            case 0x17:
            case 0x18:
                if (func_80101DDC(param_0)) {
                    func_80804170_chquiz(param_0, 0x19);
                }
                func_80801794_chquiz(local_0);
                break;
            case 0x19:
                func_80801794_chquiz(local_0);
                break;
            case 0x1A:
                func_80801794_chquiz(local_0);
                break;
            case 0x1B:
                if (func_808013E0_chquiz(param_0, local_0)) {
                    func_80804170_chquiz(param_0, 0x1C);
                    func_80801794_chquiz(local_0);
                }
                break;
            case 0x1D:
                if (param_0->unk6C_0 != 2 && func_800D90A4(&param_0->actorData[0])) {
                    if (func_800D395C()) {
                        func_80804170_chquiz(param_0, 0x2C);
                    } else {
                        switch (_suquiz_entrypoint_4()) {
                            case 2:
                                break;
                            case 0:
                                func_80804170_chquiz(param_0, 8);
                                break;
                            case 1:
                                func_80804170_chquiz(param_0, func_800DA298(0x586) ? 0xA : 9);
                        }
                    }
                }
                break;
            case 0x1E:
                if (func_80101DDC(param_0)) {
                    func_80804170_chquiz(param_0, 0x1F);
                }
                break;
            case 0x23:
                if (func_800D90A4(&param_0->actorData[0])) {
                    func_80801C7C_chquiz(2);
                    *(f32 *) &param_0->actorData[0] = 10000.0f;
                }
                break;
            case 0x24:
                if (func_808013E0_chquiz(param_0, local_0)) {
                    func_80804170_chquiz(param_0, 0x25);
                }
                break;
            case 0x36:
                if (func_808013E0_chquiz(param_0, local_0)) {
                    func_80804170_chquiz(param_0, 0x37);
                }
            case 0x37:
                break;
        }
        if (func_800D3948()) {
            func_801039E4(param_0->unk0);
        }
        _suquiz_entrypoint_1();
        func_80801170_chquiz(param_0, local_0);
        func_80800298_chquiz(param_0);
        func_80803BFC_chquiz(param_0);
        if (((QuizExpressionFlag481 *) param_0)->local_0) {
            _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
        }
    }

    void func_80805878_chquiz(param_0) Actor *param_0;
    {
        if (((QuizActorFlags *) param_0)->local_0) {
            func_80800FBC_chquiz(param_0);
            func_808008D4_chquiz(param_0);
            if (func_80100094(param_0, 1))
                _suexpression_entrypoint_8(param_0, 1);
            if (!_suquiz_entrypoint_17())
                _suquiz_entrypoint_2();
        }
    }

    s32 func_808058F0_chquiz(Actor *param_0, s32 param_1, s32 param_2)
    {
        extern f32 _suquiz_entrypoint_8(s32);
        typedef struct {
            u16 local_0;
        } QuizCharacterEntry;

        char *local_0;
        s32 local_3;
        s32 local_2;
        s16 *local_1;

        local_0 = (char *) func_80100094(param_0, 0);
        local_1 = (s16 *) &param_2;

        switch (param_1) {
            case 0x95:
                func_80800F34_chquiz(param_0, local_0);

                switch (_suquiz_entrypoint_3()) {
                    case 5:
                        if (_suquiz_entrypoint_5()) {
                            if (_suquiz_entrypoint_6() == 8) {
                                func_80804170_chquiz(param_0, 0x15);
                                return 1;
                            }

                            func_80101180(0x529, 0x89, 0);

                            func_808016F8_chquiz(local_0, 1, _suquiz_entrypoint_8(1));

                            func_80804170_chquiz(param_0, 0xF);
                        } else {
                            func_80804170_chquiz(param_0, 0xD);
                            _suquiz_entrypoint_19(1);
                        }

                        return 1;
                    case 0:
                        if (func_800D395C()) {
                            switch (func_800D3D04()) {
                                case 0x74:
                                    func_80804170_chquiz(param_0, 0x26);
                                    break;
                                case 0x75:
                                    func_80804170_chquiz(param_0, 0x27);
                                    break;
                                case 0x76:
                                    func_80804170_chquiz(param_0, 0x28);
                            }
                            return 1;
                        }

                        if (func_800D3948()) {
                            func_80804170_chquiz(param_0, 0x2E);
                        } else {
                            func_80804170_chquiz(param_0, 1);
                        }
                        return 1;

                    case 1:
                        func_80804170_chquiz(param_0, 7);
                        return 1;

                    case 2:
                        func_80804170_chquiz(param_0, 8);
                        return 1;

                    case 3:
                        func_80804170_chquiz(param_0, 0xA);
                }
                return 1;

            case 0x30:
                switch (local_1[0]) {
                    case 0x148B:
                    case 0x148C:
                    case 0x148D:
                        return func_80801B7C_chquiz(local_0);

                    case 0x14C6:
                        return _gcstatusDll_entrypoint_18();

                    case 0x14D9:
                        return _gcstatusDll_entrypoint_17();
                    case 0x1493:
                        if (((s16 *) &param_2)[1] != 0) {
                            return func_80801784_chquiz(local_0, param_0->unk6C_0);
                        }

                        return _gcstatusDll_entrypoint_17();

                    case 0x1494:
                        return _gcstatusDll_entrypoint_18();
                }
                return 0;

            case 0x2F:
                switch (local_1[1]) {
                    case 1:
                        func_80804170_chquiz(param_0, 0x1E);
                        return 1;

                    case 2:
                        func_8080100C_chquiz(param_0, local_0, 0x15);
                        return 1;

                    case 3:
                        func_8080100C_chquiz(param_0, local_0, 0x16);
                        return 1;

                    case 4:
                        func_8080100C_chquiz(param_0, local_0, 0x17);
                        return 1;

                    case 5:
                        func_8080100C_chquiz(param_0, local_0, 0x18);
                        return 1;

                    case 6:
                        func_80804170_chquiz(param_0, 0x20);
                        return 1;

                    case 7:
                        func_80101180(0x52E, 0x8C, 1);
                        func_80101180(0x529, 0x8B, 0);
                        return 1;

                    case 8:
                        func_80101180(0x52E, 0x8C, 2);
                        func_80101180(0x529, 0x8B, 2);
                        return 1;

                    case 9:
                        func_80101180(0x52E, 0x8C, 1);
                        func_80101180(0x529, 0x8B, 1);
                        return 1;

                    case 10:
                        func_80101180(0x52E, 0x8C, 3);
                        func_80101180(0x529, 0x8B, 3);
                        return 1;

                    case 11:
                        func_80101180(0x52E, 0x8C, 4);
                        func_80101180(0x529, 0x8B, 4);
                        return 1;

                    case 12:
                        func_80101180(0x52E, 0x8C, 5);
                        func_80101180(0x529, 0x8B, 5);
                        return 1;

                    case 13:
                        func_80101180(0x52E, 0x8C, 6);
                        func_80101180(0x529, 0x8B, 6);
                        return 1;
                }

                return 0;

            case 0x2E:
                switch (local_1[0]) {
                    case 0x1461:
                        func_80801470_chquiz(param_0, local_0);
                    case 0x1460:
                    case 0x1463:
                    case 0x1465:
                        func_80804170_chquiz(param_0, *(s32 *) ((char *) param_0 + 0x34) + 1);
                        return 1;

                    case 0x1464:
                        func_808014F8_chquiz(0, 1);
                        func_80804170_chquiz(param_0, 7);
                        return 1;

                    case 0x1466:
                    case 0x146A:
                        _suquiz_entrypoint_23();
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x1467:
                    case 0x146B:
                        _suquiz_entrypoint_23();
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x1468:
                    case 0x146C:
                        _suquiz_entrypoint_23();
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x1479:
                    case 0x147A:
                    case 0x147B:
                    case 0x147C:
                    case 0x147D:
                    case 0x147E:
                        func_80804170_chquiz(param_0, 0xE);
                        return 1;

                    case 0x147F:
                    case 0x1480:
                    case 0x1481:
                    case 0x1482:
                    case 0x1483:
                    case 0x1484:
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x1473:
                    case 0x1474:
                    case 0x1475:
                    case 0x1476:
                    case 0x1477:
                    case 0x1478:
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x14A4:
                    case 0x14A5:
                    case 0x14A6:
                    case 0x14A7:
                    case 0x14A8:
                    case 0x14A9:
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x146D:
                    case 0x146E:
                    case 0x146F:
                    case 0x1470:
                    case 0x1471:
                    case 0x1472:
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x14BC:
                    case 0x14BD:
                    case 0x14BE:
                    case 0x14BF:
                    case 0x14C0:
                    case 0x14C1:
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x14A1:
                    case 0x14A2:
                    case 0x14A3:
                        func_80804170_chquiz(param_0, 0xC);
                        return 1;

                    case 0x14AA:
                    case 0x14AB:
                    case 0x14AC:
                    case 0x14AD:
                    case 0x14AE:
                    case 0x14AF:
                        func_80804170_chquiz(param_0, 0xE);
                        return 1;

                    case 0x14DA:
                    case 0x14DB:
                    case 0x14DC:
                    case 0x14DD:
                    case 0x14DE:
                    case 0x14DF:
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x14B0:
                    case 0x14B1:
                    case 0x14B2:
                    case 0x14B3:
                    case 0x14B4:
                    case 0x14B5:
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x148B:
                    case 0x148C:
                    case 0x148D:
                    case 0x148E:
                    case 0x148F:
                    case 0x1490:
                    case 0x1491:
                        func_80804170_chquiz(param_0, 0x1B);
                        return 1;

                    case 0x1462:
                        func_80804170_chquiz(param_0, 0xA);
                        return 1;

                    case 0x149A:
                    case 0x149B:
                    case 0x149C:
                    case 0x149D:
                    case 0x149E:
                    case 0x149F:
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x1485:
                    case 0x1486:
                    case 0x1487:
                    case 0x1488:
                    case 0x1489:
                    case 0x148A:
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x14C7:
                    case 0x14C8:
                        switch (param_0->unk6C_0) {
                            case 0:
                                func_80803B54_chquiz(param_0, 0x14C9, 0x46);
                                break;
                            case 1:
                                func_80803B54_chquiz(param_0, 0x14CA, 0x46);
                                break;
                            case 2:
                                func_80803B54_chquiz(param_0, 0x14CB, 0x46);
                        }
                        return 1;

                    case 0x14C9:
                    case 0x14CA:
                    case 0x14CB:
                        func_80804170_chquiz(param_0, 0x1B);
                        return 1;

                    case 0x14CC:
                        if (local_1[1] != 0) {
                            func_80804170_chquiz(param_0, 3);
                        } else {
                            func_80804170_chquiz(param_0, 0x29);
                        }
                        return 1;

                    case 0x14CD:
                        if (local_1[1] != 0) {
                            func_80803B54_chquiz(param_0, 0x14D1, 0x46);
                        } else {
                            func_80804170_chquiz(param_0, 0x2A);
                        }
                        return 1;

                    case 0x14CE:
                        if (local_1[1] != 0) {
                            func_80803B54_chquiz(param_0, 0x14D2, 0x46);
                        } else {
                            func_80804170_chquiz(param_0, 0x2B);
                        }
                        return 1;

                    case 0x14D1:
                        func_80804170_chquiz(param_0, 0x2A);
                        return 1;

                    case 0x14D2:
                        func_80804170_chquiz(param_0, 0x2B);
                        return 1;

                    case 0x14D3:
                    case 0x14D4:
                    case 0x14D5:
                        _suquiz_entrypoint_23();
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;
                    case 0x14CF:
                    case 0x14D0:
                        if (local_1[1] != 0) {
                            _gcfrontend_entrypoint_11();
                        } else {
                            _gcfrontend_entrypoint_10();
                        }
                        return 1;

                    case 0x1469:
                        if (local_1[1] != 0) {
                            func_80804170_chquiz(param_0, 0x2F);
                        } else {
                            func_80804170_chquiz(param_0, 0x34);
                        }
                        return 1;

                    case 0x14C2:
                    case 0x14C3:
                    case 0x14C4:
                    case 0x14C5:
                    case 0x14D6:
                        func_80804170_chquiz(param_0, *(s32 *) ((char *) param_0 + 0x34) + 1);
                        return 1;

                    case 0x14C6:
                    case 0x14D9:
                        _suquiz_entrypoint_23();
                        func_80804170_chquiz(param_0, 0xB);
                        return 1;

                    case 0x1496:
                    case 0x1497:
                    case 0x1498:
                    case 0x1499:
                        func_80804170_chquiz(param_0, 0x36);
                        return 1;

                    case 0x1493:
                    case 0x1494:
                    case 0x1495:
                        switch (param_0->unk6C_0) {
                            case 3:
                                local_3 = 0x1498;
                                break;
                            case 4:
                                local_3 = 0x1497;
                                break;
                            case 5:
                                local_3 = 0x1496;
                                break;
                            case 6:
                                local_3 = 0x1499;
                                break;
                        }
                        func_80803B54_chquiz(param_0, local_3, 0x46);
                        return 1;

                    case 0x14A0:
                        func_80804170_chquiz(param_0, 0x23);
                        return 1;
                }
                return 1;

            case 0xB:
                func_80801470_chquiz(param_0, local_0);

                if (param_2 == 0x13) {
                    func_80804170_chquiz(param_0, 0x22);
                } else if (param_2 == 0x15) {
                    func_80804170_chquiz(param_0, 0x24);
                }

                return 4;

            case 0x20:
                func_808005C0_chquiz(param_0, local_1[0], local_1[1]);
                return 1;

            case 0x83:
                if (*(s32 *) ((char *) param_0 + 0x34) == 0xD ||
                    *(s32 *) ((char *) param_0 + 0x34) == 0xE) {
                    func_80804170_chquiz(param_0,
                                         *(s32 *) ((char *) param_0 + 0x34) == 0xD ? 0xF : 0x10);
                    return 1;
                }

                return 0;

            case 0x88:
                if (func_800D395C() && ((param_0->unk6C_0) == 2)) {
                    func_80804170_chquiz(param_0, 0x2D);
                    return 1;
                }

                if (func_800D3948()) {
                    if (*(s32 *) ((char *) param_0 + 0x34) != 0x38) {
                        local_2 = 3;

                        do {
                            func_800AA20C(local_2 - 3, func_80801784_chquiz(local_0, local_2));

                            local_2++;
                        } while (local_2 != 7);

                        _gcfrontend_entrypoint_10();
                        *(s32 *) ((char *) param_0 + 0x34) = 0x38;
                    }

                } else {
                    func_80804170_chquiz(param_0, 0x1D);
                }
                return 1;

            case 0x6C:
                if (!func_800D3948() && func_800DA298(0x6B6)) {
                    func_80801058_chquiz(param_0, local_0, 0.5f, 0,
                                         func_80801544_chquiz(param_0->unk6C_0), 1);
                }

                return 1;

            case 0x1F:
                func_801015D0(param_0);

                switch (D_80807528_chquiz[param_0->unk70_10].id) {
                    case 0x4C2:
                    case 0x4C3:
                    case 0x4C4:
                        func_800DF744(3, 1);
                        break;

                    case 0x4C5:
                    case 0x4C6:
                    case 0x4C7:
                        func_800DF744(3, 0);
                }

                return 1;

            case 0x29:
                _suexpression_entrypoint_7(param_0, 1, 0x4D);
                return 1;

            case 0x2A:
                _suexpression_entrypoint_8(param_0, 1);
                return 1;

            case 0x32:
                func_800F82D4(func_800F54E4(), 2);
                return 1;
        }

        return 0;
    }

    s32 func_808064F4_chquiz(this, param_1)
    Actor *this;
    s32 param_1;
    {
        do {
        } while (0);
        if (func_800EB854(this) == 0) {
            func_801018A4(this, param_1);
        } else {
            func_808002F0_chquiz(this, param_1);
        }
    }

    int *chquiz_entrypoint_4()
    {
        return &D_80807684_chquiz;
    }

    extern void func_80101870();
    u32 D_80806D00_chquiz[32] = {
        0x0,        0x0,       0x40C00000, 0x3B70009, 0x3F800000, 0x3B8004A, 0x40C00000, 0x3B70009,
        0x40C00000, 0x3B70009, 0x3F666666, 0x3B5004A, 0x40C00000, 0x3B70009, 0x40C00000, 0x3B70009,
        0x40C00000, 0x3B70009, 0x3FA66666, 0x3B9004A, 0x40C00000, 0x3B70009, 0x3F800000, 0x3B8004A,
        0x3F000000, 0x3BA004A, 0x3DCCCCCD, 0x3BB0049, 0x3F800000, 0x3B8004A, 0x40C00000, 0x3B70009};
    u32 D_80806D80_chquiz[32] = {
        0x0,        0x0,       0x40E947AE, 0x4BA0009, 0x3FD5C28F, 0x4BC004A, 0x40E947AE, 0x4BA0009,
        0x40E947AE, 0x4BA0009, 0x3F733333, 0x4BB004A, 0x40E947AE, 0x4BA0009, 0x40E947AE, 0x4BA0009,
        0x40E947AE, 0x4BA0009, 0x406147AE, 0x4BD004A, 0x40E947AE, 0x4BA0009, 0x3FD5C28F, 0x4BC004A,
        0x401EB852, 0x4BE004A, 0x3F000000, 0x4BF0049, 0x3FD5C28F, 0x4BC004A, 0x40E947AE, 0x4BA0009};
    u32 D_80806E00_chquiz[32] = {
        0x0,        0x0,       0x41100000, 0x3B00009, 0x3F8CCCCD, 0x3B1004A, 0x41100000, 0x3B00009,
        0x41100000, 0x3B00009, 0x3F800000, 0x3AE004A, 0x41100000, 0x3B00009, 0x41100000, 0x3B00009,
        0x41100000, 0x3B00009, 0x3FB33333, 0x3B2004A, 0x41100000, 0x3B00009, 0x3F8CCCCD, 0x3B1004A,
        0x3ECCCCCD, 0x3B3004A, 0x3DCCCCCD, 0x3B40049, 0x3F8CCCCD, 0x3B1004A, 0x41100000, 0x3B00009};
    u32 D_80806E80_chquiz[32] = {
        0x0,        0x0,       0x41000000, 0x3BE0009, 0x3F800000, 0x3BF004A, 0x41000000, 0x3BE0009,
        0x41000000, 0x3BE0009, 0x3F666666, 0x3BC004A, 0x41000000, 0x3BE0009, 0x41000000, 0x3BE0009,
        0x41000000, 0x3BE0009, 0x3FA66666, 0x3C0004A, 0x41000000, 0x3BE0009, 0x3F800000, 0x3BF004A,
        0x3ECCCCCD, 0x3C1004A, 0x3DCCCCCD, 0x3C20049, 0x3F800000, 0x3BF004A, 0x41000000, 0x3BE0009};
    u32 D_80806F00_chquiz[32] = {
        0x0,        0x0,       0x41000000, 0x3C30009, 0x3F800000, 0x3C6004A, 0x41000000, 0x3C30009,
        0x41000000, 0x3C30009, 0x3F666666, 0x3C4004A, 0x41000000, 0x3C30009, 0x41000000, 0x3C30009,
        0x41000000, 0x3C30009, 0x3FA66666, 0x3C5004A, 0x41000000, 0x3C30009, 0x3F800000, 0x3C6004A,
        0x3ECCCCCD, 0x3C7004A, 0x3DCCCCCD, 0x3C80049, 0x3F800000, 0x3C6004A, 0x41000000, 0x3C30009};
    u32 D_80806F80_chquiz[32] = {
        0x0,        0x0,       0x41000000, 0x20D0009, 0x3F800000, 0x210004A, 0x41000000, 0x20D0009,
        0x41000000, 0x20D0009, 0x3F666666, 0x20E004A, 0x41000000, 0x20D0009, 0x41000000, 0x20D0009,
        0x41000000, 0x20D0009, 0x3FA66666, 0x20F004A, 0x41000000, 0x20D0009, 0x3F800000, 0x210004A,
        0x3ECCCCCD, 0x211004A, 0x3DCCCCCD, 0x2150049, 0x3F800000, 0x210004A, 0x41000000, 0x20D0009};
    QuizRecord1351 D_80807000_chquiz[7] = {
        0x8BB, 0.3f,   0x91B, 0.31f, (void *) &D_80806D80_chquiz, 0.3f,
        0x8BD, 1.0f,   0x91D, 1.2f,  (void *) &D_80806D00_chquiz, 0.3f,
        0x62A, 1.0f,   0x91D, 1.0f,  (void *) &D_80806E00_chquiz, 0.3f,
        0x665, 0.5f,   0x933, 0.5f,  (void *) &D_80806F00_chquiz, 0.3f,
        0x7D6, 0.575f, 0x91E, 1.15f, (void *) &D_80806E80_chquiz, 0.3f,
        0x62B, 1.0f,   0x91D, 1.0f,  (void *) &D_80806E00_chquiz, 0.3f,
        0x675, 0.08f,  0x934, 0.08f, (void *) &D_80806F80_chquiz, 0.3f};
    u8 D_808070A8_chquiz[8] = {0x0, 0x9D, 0x0, 0x9F, 0x0, 0x4D, 0xFF, 0xFF};
    u8 D_808070B0_chquiz[8] = {0x0, 0x3C, 0x0, 0x3C, 0x0, 0x3C, 0x0, 0x0};
    QuizOptions32 D_808070B8_chquiz = {0x0, 0x0, 0x0};
    s8 D_808070C4_chquiz[32] = {0x7, 0x8, 0x6, 0x5, 0x6, 0x7,  0x8, 0x3, 0x0, 0x4, 0x7,
                                0x8, 0x5, 0x5, 0x6, 0x7, 0x8,  0x3, 0x1, 0x4, 0x7, 0x8,
                                0x5, 0x5, 0x6, 0x7, 0x8, 0x20, 0x2, 0x4, 0x0, 0x0};
    QuizEnt D_808070E4_chquiz[39] = {
        0x0, 0x1, 0x0, 0x0, 2.0f, 0x1, 0x2, 0x0, 0x0, 2.0f, 0x2,  0x0,  0x0, 0x0, 1.0f,
        0x8, 0x0, 0x1, 0x0, 1.0f, 0x8, 0x0, 0x1, 0x0, 1.0f, 0x8,  0x1,  0x0, 0x0, 1.0f,
        0x8, 0x0, 0x1, 0x0, 1.0f, 0x9, 0x1, 0x1, 0x0, 1.5f, 0x7,  0x1,  0x1, 0x0, 1.5f,
        0x9, 0x0, 0x2, 0x0, 1.0f, 0x9, 0x0, 0x2, 0x0, 1.0f, 0x9,  0x1,  0x2, 0x0, 3.0f,
        0x9, 0x1, 0x2, 0x0, 1.0f, 0x8, 0x0, 0x1, 0x0, 1.0f, 0x8,  0x0,  0x1, 0x0, 1.0f,
        0x8, 0x0, 0x0, 0x0, 1.0f, 0x8, 0x0, 0x0, 0x0, 1.0f, 0x8,  0x1,  0x1, 0x0, 1.0f,
        0x8, 0x0, 0x1, 0x0, 2.0f, 0x9, 0x1, 0x2, 0x0, 2.0f, 0x8,  0x1,  0x1, 0x0, 2.0f,
        0x2, 0x0, 0x1, 0x0, 1.0f, 0x8, 0x0, 0x1, 0x0, 1.0f, 0x2,  0x0,  0x1, 0x0, 1.0f,
        0x8, 0x0, 0x1, 0x0, 1.0f, 0x8, 0x1, 0x2, 0x0, 1.5f, 0x8,  0x0,  0x1, 0x0, 1.0f,
        0x8, 0x0, 0x1, 0x0, 1.0f, 0x3, 0x1, 0x0, 0x0, 1.5f, 0x4,  0x1,  0x0, 0x0, 1.5f,
        0x5, 0x1, 0x0, 0x0, 1.5f, 0x6, 0x1, 0x0, 0x0, 1.5f, 0x8,  0x1,  0x1, 0x0, 1.5f,
        0x8, 0x0, 0x1, 0x0, 1.5f, 0x8, 0x0, 0x1, 0x0, 1.5f, 0x8,  0x0,  0x1, 0x0, 1.5f,
        0x8, 0x0, 0x1, 0x0, 1.5f, 0x8, 0x0, 0x1, 0x0, 1.5f, -0x2, -0x1, 0x2, 0x1, -1.6947657e+38f};
    u32 D_8080721C_chquiz[1] = {0x0};
    QuizAnimation271 D_80807220_chquiz[3] = {0x0,   0x0, 0x0,  0x40, 0x0,  0x0,  0x0,
                                             0x596, 0x0, 0x9,  0x3F, 0x4C, 0xCC, 0xCD,
                                             0x597, 0x0, 0x4A, 0x3F, 0x4C, 0xCC, 0xCD};
    static u32 D_80807220_chquiz_rest[1] = {0x5970084};
    u8 D_8080723C_chquiz[56] = {0x0, 0x1D, 0x9, 0xDD, 0x0,  0x2B, 0x2,  0xCC, 0x3, 0x66, 0x0, 0x15,
                                0x0, 0x0,  0x0, 0x99, 0x0,  0x22, 0x1,  0x80, 0x2, 0x0,  0x4, 0x80,
                                0x6, 0x0,  0x0, 0x19, 0x0,  0x0,  0x0,  0x7,  0x0, 0x2D, 0x0, 0x32,
                                0x0, 0x64, 0x0, 0x20, 0xA7, 0xA7, 0xA7, 0xC0, 0x0, 0xB,  0x0, 0x96,
                                0x0, 0x96, 0x0, 0x5,  0xFF, 0xFB, 0x0,  0x0};
    u8 D_80807274_chquiz[72] = {0x0, 0x1D, 0x6, 0x79, 0x0, 0x1B, 0xFC, 0xE0, 0xFD, 0x44, 0x0, 0x2E,
                                0x0, 0x0,  0x0, 0x0,  0x2, 0xBC, 0x0,  0x3C, 0x1,  0x67, 0x3, 0x20,
                                0x0, 0xB,  0x0, 0x64, 0x0, 0xC8, 0x0,  0x5,  0xFF, 0xFB, 0x0, 0x16,
                                0x4, 0x0,  0x0, 0x27, 0x1, 0x2C, 0x1,  0x2C, 0x2,  0x58, 0x2, 0x58,
                                0x0, 0x22, 0x0, 0x80, 0x0, 0x80, 0x0,  0x80, 0x0,  0x80, 0x0, 0x15,
                                0x0, 0x0,  0x0, 0xE6, 0x0, 0x2B, 0x2,  0x0,  0x3,  0x0,  0x0, 0x0};
    u8 D_808072BC_chquiz[16] = {0x0, 0x13, 0x6,  0x85, 0x0, 0xA, 0x1, 0x19,
                                0x0, 0x16, 0x7D, 0x0,  0x0, 0x0, 0x0, 0x0};
    int D_808072CC_chquiz[18] = {0x158052C,
                                 0x99A0001,
                                 (u32) &D_8080721C_chquiz,
                                 (u32) func_80801CC4_chquiz,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x20800000,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 0x0,
                                 (u32) func_80107C2C,
                                 -0x7FFFBB7E,
                                 0x0,
                                 0x0};
    u8 D_80807314_chquiz[8] = {0x42, 0xF0, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0};
    u8 D_8080731C_chquiz[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF};
    u8 D_80807328_chquiz[12] = {0x44, 0xA5, 0x0, 0x0, 0x42, 0xE2, 0x0, 0x0, 0x42, 0xB0, 0x0, 0x0};
    int D_80807334_chquiz[18] = {0x1580529,
                                 0x1,
                                 0x0,
                                 (u32) func_80802664_chquiz,
                                 (u32) func_80105834,
                                 (u32) func_801018A4,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x168,
                                 (u32) func_808029A4_chquiz,
                                 (u32) func_80108ED0,
                                 0x40000,
                                 (u32) func_80802628_chquiz,
                                 (u32) func_80107C2C,
                                 -0x7FFBFBFE,
                                 (u32) func_80802A2C_chquiz,
                                 0x0};
    u8 D_8080737C_chquiz[40] = {0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x73,
                                0x33, 0x33, 0x3,  0xAF, 0x0,  0x44, 0x3F, 0x73, 0x33, 0x33,
                                0x3,  0xAF, 0x0,  0x4A, 0x3F, 0x73, 0x33, 0x33, 0x3,  0xAF,
                                0x0,  0x44, 0x3F, 0x73, 0x33, 0x33, 0x3,  0xAF, 0x0,  0x44};
    u8 D_808073A4_chquiz[40] = {0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x73,
                                0x33, 0x33, 0x4,  0xC0, 0x0,  0x44, 0x3F, 0x73, 0x33, 0x33,
                                0x4,  0xC0, 0x0,  0x4A, 0x3F, 0x73, 0x33, 0x33, 0x4,  0xC0,
                                0x0,  0x44, 0x3F, 0x73, 0x33, 0x33, 0x4,  0xC0, 0x0,  0x44};
    u8 D_808073CC_chquiz[80] = {
        0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x3F, 0x73, 0x33, 0x33, 0x3, 0xAF, 0x0, 0x44,
        0x3F, 0x73, 0x33, 0x33, 0x3, 0xAF, 0x0, 0x4A, 0x3F, 0x73, 0x33, 0x33, 0x3, 0xAF, 0x0, 0x44,
        0x3F, 0x73, 0x33, 0x33, 0x3, 0xAF, 0x0, 0x44, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,
        0x3F, 0x73, 0x33, 0x33, 0x3, 0xAF, 0x0, 0x44, 0x3F, 0x73, 0x33, 0x33, 0x3, 0xAF, 0x0, 0x4A,
        0x3F, 0x73, 0x33, 0x33, 0x3, 0xAF, 0x0, 0x44, 0x3F, 0x73, 0x33, 0x33, 0x3, 0xAF, 0x0, 0x44};
    u8 D_8080741C_chquiz[40] = {0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x73,
                                0x33, 0x33, 0x3,  0xAF, 0x0,  0x44, 0x3F, 0x73, 0x33, 0x33,
                                0x3,  0xAF, 0x0,  0x4A, 0x3F, 0x73, 0x33, 0x33, 0x3,  0xAF,
                                0x0,  0x44, 0x3F, 0x73, 0x33, 0x33, 0x3,  0xAF, 0x0,  0x44};
    u8 D_80807444_chquiz[40] = {0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x73,
                                0x33, 0x33, 0x2,  0x16, 0x0,  0x44, 0x3F, 0x73, 0x33, 0x33,
                                0x2,  0x16, 0x0,  0x4A, 0x3F, 0x73, 0x33, 0x33, 0x2,  0x16,
                                0x0,  0x44, 0x3F, 0x73, 0x33, 0x33, 0x2,  0x16, 0x0,  0x44};
    u8 D_8080746C_chquiz[8] = {0x42, 0xC8, 0x0, 0x0, 0x43, 0x7A, 0x0, 0x0};
    u8 D_80807474_chquiz[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xC8, 0x0, 0x0, 0x0, 0x0};
    int D_80807480_chquiz[18] = {0x158052B,
                                 0x1,
                                 0x0,
                                 (u32) func_80803470_chquiz,
                                 (u32) func_80105834,
                                 (u32) func_801018A4,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x20800040,
                                 (u32) func_80803910_chquiz,
                                 (u32) func_80108ED0,
                                 0x0,
                                 0x0,
                                 (u32) func_80107C2C,
                                 -0x7FFBFBFE,
                                 (u32) func_80803588_chquiz,
                                 0x0};
    u8 D_808074C8_chquiz[8] = {0x42, 0xF0, 0x0, 0x0, 0x43, 0x7A, 0x0, 0x0};
    u8 D_808074D0_chquiz[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xC8, 0x0, 0x0, 0x0, 0x96};
    s32 D_808074DC_chquiz[18] = {0x158052E,
                                 0x9A20001,
                                 0x0,
                                 (u32) func_80803954_chquiz,
                                 (u32) func_80105834,
                                 (u32) func_801018A4,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 0x0,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBFE,
                                 (u32) func_808039D4_chquiz,
                                 0x0};
    u8 D_80807524_chquiz[4] = {0x0, 0x0, 0x0, 0x0};
    QEnt3 D_80807528_chquiz[6] = {0x0,   0x0,  0x4100, 0x0,    0x4C2, 0x9,  0x3FCC, 0xCCCD,
                                  0x4C4, 0x4A, 0x3FCC, 0xCCCD, 0x4C3, 0x4A, 0x4118, 0x0,
                                  0x4C5, 0x4A, 0x3FA6, 0x6666, 0x4C6, 0x9,  0x40D0, 0x0};
    static u32 D_80807528_chquiz_rest[1] = {0x4C7000A};
    s32 D_8080755C_chquiz[2] = {0x43FA0000, 0x443B8000};
    s32 D_80807564_chquiz[3] = {0xFF, 0xC8, 0x0};
    u8 D_80807570_chquiz[16] = {0x3E, 0xDC, 0x28, 0xF6, 0x3E, 0xFA, 0xE1, 0x48,
                                0x3F, 0x14, 0x7A, 0xE1, 0xBF, 0x80, 0x0,  0x0};
    u8 D_80807580_chquiz[24] = {0x3F, 0x14, 0x7A, 0xE1, 0x3F, 0x2E, 0x14, 0x7B,
                                0x3F, 0x47, 0xAE, 0x14, 0x3F, 0x57, 0xA,  0x3D,
                                0x3F, 0x61, 0x47, 0xAE, 0xBF, 0x80, 0x0,  0x0};
    u8 D_80807598_chquiz[24] = {0x3F, 0xF,  0x5C, 0x29, 0x3F, 0x28, 0xF5, 0xC3,
                                0x3F, 0x42, 0x8F, 0x5C, 0x3F, 0x51, 0xEB, 0x85,
                                0x3F, 0x5C, 0x28, 0xF6, 0xBF, 0x80, 0x0,  0x0};
    u8 D_808075B0_chquiz[16] = {0x0, 0x13, 0x5,  0x64, 0x0, 0xA, 0x1, 0x0,
                                0x0, 0x16, 0x7F, 0xFF, 0x0, 0x0, 0x0, 0x0};
    u8 D_808075C0_chquiz[44] = {0x0,  0x1D, 0x9,  0xDD, 0x0,  0x19, 0x0,  0x0,  0x0,  0xE, 0x0,
                                0x1B, 0x0,  0xC8, 0x1,  0x2C, 0x9D, 0x2,  0x0,  0x22, 0x0, 0x33,
                                0x0,  0x33, 0x2,  0x0,  0x4,  0x0,  0x0,  0x15, 0x0,  0x0, 0x0,
                                0x4C, 0x0,  0x2B, 0x1,  0x80, 0x2,  0x80, 0x0,  0x0,  0x0, 0x0};
    u8 D_808075EC_chquiz[56] = {0x0, 0x1D, 0x9, 0xCE, 0x0, 0x18, 0x0, 0x0,  0x0,  0x0,  0xC,  0x0,
                                0xF, 0x0,  0x0, 0xB,  0x0, 0xA,  0x0, 0x1E, 0xFF, 0xEC, 0xFF, 0xE2,
                                0x0, 0x21, 0x0, 0x0,  0x0, 0x0,  0x0, 0xB4, 0x0,  0x22, 0x1,  0x0,
                                0x1, 0x0,  0x1, 0x99, 0x1, 0xCC, 0x0, 0x15, 0x0,  0x4C, 0x0,  0xC0,
                                0x0, 0x2B, 0x0, 0x19, 0x0, 0x33, 0x0, 0x0};
    u8 D_80807624_chquiz[28] = {0x0, 0x13, 0x4, 0xDC, 0x0, 0xC,  0x0,  0x0,  0x3, 0x0,
                                0x0, 0xCC, 0x1, 0x33, 0x0, 0x16, 0x7F, 0xFF, 0x0, 0x15,
                                0x1, 0x0,  0x3, 0x80, 0x1, 0x80, 0x0,  0x0};
    u8 D_80807640_chquiz[28] = {0x0, 0x13, 0x4, 0xA9, 0x0, 0xC,  0x0,  0x0,  0x3, 0x0,
                                0x0, 0xB3, 0x1, 0x19, 0x0, 0x16, 0x7F, 0xFF, 0x0, 0x15,
                                0x1, 0x0,  0x4, 0x0,  0x1, 0x0,  0x0,  0x0};
    u8 D_8080765C_chquiz[28] = {0x0, 0x13, 0x6, 0x6,  0x0, 0xC,  0x0,  0x0,  0x3, 0x0,
                                0x0, 0xB3, 0x1, 0x33, 0x0, 0x16, 0x7F, 0xFF, 0x0, 0x15,
                                0x0, 0x80, 0x1, 0x0,  0x0, 0x80, 0x0,  0x0};
    u8 D_80807678_chquiz[12] = {0xC4, 0x98, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    int D_80807684_chquiz[19] = {0x1580528,
                                 0x9360001,
                                 (u32) &D_80807524_chquiz,
                                 (u32) func_80805404_chquiz,
                                 (u32) func_80105834,
                                 (u32) func_808064F4_chquiz,
                                 0x0,
                                 0x0,
                                 0x4410000,
                                 0x20000528,
                                 (u32) func_80805878_chquiz,
                                 (u32) func_80108ED0,
                                 0xD40000,
                                 (u32) func_808053BC_chquiz,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBFE,
                                 (u32) func_808058F0_chquiz,
                                 0x0,
                                 0x0};
