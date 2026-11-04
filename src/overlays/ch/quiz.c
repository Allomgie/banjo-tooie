#include "common.h"

// Tower of Tragedy: Grunty's quiz show (Cauldron Keep and the multiplayer quiz).
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
s32 func_80800000_chquiz(s32 idx)
{
    if (idx == 2) {
        return func_8009EA2C() ? 0x838 : D_80807000_chquiz[idx].local_0;
    }
    return D_80807000_chquiz[idx].local_0;
}
// Matching: the line breaks in this function are needed for the match.
f32 func_80800070_chquiz(s32 idx)
{
    int scaled;
    int offset;
    scaled = ((((idx * 6) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF; // Matching: the redundant masks are needed for the match.
    offset = (scaled & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF;
    return D_80807004_chquiz[(((offset & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF];
}

int func_8080008C_chquiz(s32 idx)
{
    return *(s32 *) ((char *) D_80807008_chquiz + idx * 24);
}

float func_808000A8_chquiz(s32 idx)
{
    return *(f32 *) ((char *) D_8080700C_chquiz + idx * 24);
}

int func_808000C4_chquiz(s32 idx)
{
    return *(s32 *) ((char *) D_80807010_chquiz + idx * 24);
}

float func_808000E0_chquiz(s32 idx)
{
    return *(f32 *) ((char *) D_80807014_chquiz + idx * 24);
}

// Creates the answer menu for a question and stores it in the quiz data.
void *func_808000FC_chquiz(Actor *actor, s32 question)
{
    void *menu;
    menu = heap_alloc(_gcnewoption_entrypoint_2());
    bzero(menu, _gcnewoption_entrypoint_2());
    _gcnewoption_entrypoint_5(menu, _gcnewoption_entrypoint_35, 0, question, actor->unk0);
    *(void **) ((u8 *) func_80100094(actor, 0) + 0x94) = menu;
    _gcnewoption_entrypoint_40(menu, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_8(menu, 3);
    _gcnewoption_entrypoint_9(menu, 3);
    _gcnewoption_entrypoint_10(menu, 2);
    _gcnewoption_entrypoint_32(menu, 0x4D);
    _gcnewoption_entrypoint_14(menu, 0, 0, 0, 0.0f);
    _gcnewoption_entrypoint_28(menu);
    _gcnewoption_entrypoint_25(menu, 0);
    _gcnewoption_entrypoint_26(menu, 0);
    _gcnewoption_entrypoint_11(menu);
    return menu;
}

void func_80800218_chquiz(s32 menu, s32 quiz)
{
    s32 i;
    _gcnewoption_entrypoint_30(menu, D_808070A8_chquiz);
    for (i = 0; i < 3; i++) {
        _gcnewoption_entrypoint_12(menu, i,
        (s16)(func_80800E38_chquiz(quiz, i) + 0xA));
    }
}

void func_80800298_chquiz(s32 actor)
{
    s32 menu = *(s32 *) ((u8 *) func_80100094(actor, 0) + 0x94);
    if (menu != 0 && ((u8 *) func_80100094(actor, 0))[0x99] != 0) {
        _gcnewoption_entrypoint_0(menu);
    }
}

void func_808002F0_chquiz(s32 actor, s32 unk_0)
{
    s32 menu = *(s32 *) ((u8 *) func_80100094(actor, 0) + 0x94);
    if (menu != 0 && ((u8 *) func_80100094(actor, 0))[0x99] != 0) {
        _gcnewoption_entrypoint_1(menu, unk_0);
    }
}

void func_8080034C_chquiz(Actor *actor, s32 mode)
{
    s32 menu;

    menu = func_80100094(actor, 0)->unk94;
    if (!func_80100094(actor, 0)->unk98) {
        if (mode == 0) {
            return;
        }
        menu = func_808000FC_chquiz(actor, func_80800B6C_chquiz(actor));
    }
    switch (mode) {
        case 0:
            if (menu) {
                _gcnewoption_entrypoint_37(func_80100094(actor, 0)->unk94, 1);
            }
            func_80100094(actor, 0)->unk99 = 0;
            break;
        case 1:
            func_80100094(actor, 0)->unk99 = 1;
            _gcnewoption_entrypoint_46(menu, -1);
            break;
        case 2:
            _gcnewoption_entrypoint_25(menu, 1);
            _gcnewoption_entrypoint_26(menu, 1);
            _gcnewoption_entrypoint_29(menu, 1);
            _gcnewoption_entrypoint_46(menu, _suquiz_entrypoint_10(_suquiz_entrypoint_6()));
            _gcnewoption_entrypoint_44(menu, 1);
            _gcnewoption_entrypoint_41(menu, 0);
            func_80100094(actor, 0)->unk99 = 1;
            break;
        case 3:
            _gcnewoption_entrypoint_25(menu, 1);
            _gcnewoption_entrypoint_26(menu, 0);
            _gcnewoption_entrypoint_29(menu, 0);
            _gcnewoption_entrypoint_46(menu, -1);
            _gcnewoption_entrypoint_44(menu, 0);
            if (func_80800C00_chquiz(actor) != -1) {
                _gcnewoption_entrypoint_43(menu, func_80800C00_chquiz(actor), 0);
                _gcnewoption_entrypoint_13(menu, func_80800C00_chquiz(actor),
                                           D_808070B0_chquiz);
            }
            func_80100094(actor, 0)->unk99 = 1;
            break;
        case 4:
            _gcnewoption_entrypoint_26(menu, 1);
            _gcnewoption_entrypoint_29(menu, 1);
            _gcnewoption_entrypoint_41(menu, !func_80800C00_chquiz(actor) ? 1 : 0);
            _gcnewoption_entrypoint_46(menu, _suquiz_entrypoint_10(_suquiz_entrypoint_6()));
            func_80100094(actor, 0)->unk99 = 1;
            break;
    }
    func_80100094(actor, 0)->unk98 = mode;
}

int func_808005C0_chquiz(actor, answer, event)
Actor *actor;
s32 answer;
u32 event;
{
    void *menu;

    menu = *(void **) ((u8 *) func_80100094(actor, 0) + 0x94);
    switch (event) {
        case 4:
            if (func_8080414C_chquiz(actor)) {
                if (func_80800C00_chquiz(actor) == answer) {
                    func_800C3FC0(0x42B, 1.0f, 32000);
                    return;
                }
                if (func_80800E44_chquiz(func_80100094(actor, 0)) == answer) {
                    func_808040D4_chquiz(actor);
                    return;
                }
                func_80804110_chquiz(actor);
                func_80800BD4_chquiz(actor, answer);
                return;
            }
            break;
        case 0:
            func_80800218_chquiz(menu, func_80100094(actor, 0));
            break;
        case 9:
            func_80801710_chquiz(func_80100094(actor, 0));
            if (_suquiz_entrypoint_4() != 2) {
                _gcnewoption_entrypoint_25(menu, 1);
                if (((u8 *) func_80100094(actor, 0))[0x98] == 1) {
                    _suquiz_entrypoint_19(3);
                    return;
                }
            }
            break;
        case 2:
        case 3:
            func_808008D4_chquiz(actor);
            break;
    }
}

void func_80800728_chquiz(Actor *actor, s32 unk_0)
{
    s32 menu;
    s32 correct;
    QuizOptions32 options;
    s32 pick;

    menu = *(s32 *) ((u8 *) func_80100094(actor, 0) + 0x94);
    correct = func_80800E44_chquiz(func_80100094(actor, 0));
    options = D_808070B8_chquiz;
    if (!_suquiz_entrypoint_15(unk_0)) {
        pick = func_800DC128(0, 3);
        options.values[correct] = -1;
        if (func_80800C00_chquiz(actor) != -1) {
            options.values[func_80800C00_chquiz(actor)] = -1;
        }
        while (options.values[pick]) {
            pick = func_800DC128(0, 3);
        }
        _gcnewoption_entrypoint_41(menu, pick);
    } else {
        _gcnewoption_entrypoint_41(menu, correct);
    }
    _gcnewoption_entrypoint_26(menu, 1);
}

void func_8080085C_chquiz(s32 actor)
{
    if ((*(u8 *) ((s8 *) (func_80100094(actor, 0)) + (0x98))) != 0) {
        func_808005C0_chquiz(
            actor,
            _gcnewoption_entrypoint_45((*(s32 *) ((s8 *) (func_80100094(actor, 0)) + (0x94)))),
            4);
    }
}

void func_808008B0_chquiz(s32 actor)
{
    s8 *data = func_80100094(actor, 0);
    data[0x99] = 0;
}

void func_808008D4_chquiz(s32 actor)
{
    s32 menu;

    menu = (*(s32 *) ((s8 *) (func_80100094(actor, 0)) + (0x94)));
    if (menu != 0) {
        _gcnewoption_entrypoint_7(menu);
        heap_free(menu);
        (*(s32 *) ((s8 *) (func_80100094(actor, 0)) + (0x94))) = 0;
        (*(s8 *) ((s8 *) (func_80100094(actor, 0)) + (0x98))) = 0;
        (*(s8 *) ((s8 *) (func_80100094(actor, 0)) + (0x99))) = 0;
    }
}

// Tests the question's flag bit.
s32 func_80800944_chquiz(Actor *actor, s32 flag_id)
{
    QuizFlagView1214 *view;
    s32 bit_idx;
    s32 byte;

    view = func_80100094(actor, 0);
    switch (func_80800B90_chquiz(flag_id)) {
        case 0:
            bit_idx = flag_id - 0x1910;
            byte = view->local_0[bit_idx >> 3];
            return (1 << (bit_idx & 7)) & byte;
        case 1:
            bit_idx = flag_id - 0x1A00;
            byte = view->local_1[bit_idx >> 3];
            return (1 << (bit_idx & 7)) & byte;
    }
    return 0;
}

// Sets the question's flag bit.
void func_808009D8_chquiz(Actor *actor, s32 flag_id)
{
    QuizFlagView1214 *view;
    s32 bit_idx;
    s32 byte;

    view = func_80100094(actor, 0);
    switch (func_80800B90_chquiz(flag_id)) {
        case 0:
            bit_idx = flag_id - 0x1910;
            byte = view->local_0[bit_idx >> 3];
            byte = (1 << (bit_idx & 7)) | byte;
            view->local_0[bit_idx >> 3] = byte;
            break;
        case 1:
            bit_idx = flag_id - 0x1A00;
            byte = view->local_1[bit_idx >> 3];
            byte = (1 << (bit_idx & 7)) | byte;
            view->local_1[bit_idx >> 3] = byte;
            break;
    }
}

// Picks a random unused question and marks it as used.
s32 func_80800A70_chquiz(Actor *actor)
{
    u8 *data;
    s32 question;
    s32 remaining;
    s32 range_start;
    s32 range_end;

    data = func_80100094(actor, 0);
    func_80800DA8_chquiz(actor, data);
    if (_suquiz_entrypoint_12()) {
        range_start = 0x1A00;
        range_end = 0x1A88;
    } else {
        range_start = 0x1910;
        range_end = 0x19FF;
    }
    remaining = range_end - range_start;
    while (func_80800944_chquiz(actor, question = func_800DC128(range_start, range_end + 1))) {
        remaining--;
        if (!remaining) {
            func_80800C24_chquiz(actor);
        }
    }
    func_808009D8_chquiz(actor, question);
    func_80800BD4_chquiz(actor, -1);
    *(s32 *) (data + 0xCC) = question;
    return question;
}

s32 func_80800B6C_chquiz(s32 actor)
{
    return (*(s32 *) ((s8 *) (func_80100094(actor, 0)) + (0xCC)));
}

int func_80800B90_chquiz(question)
s32 question;
{
    if (question >= 0x1910 && question < 0x1A00) {
        return 0;
    }
    if (question >= 0x1A00 && question < 0x1A89) {
        return 1;
    }
    return 2;
}

int func_80800BD4_chquiz(actor, value)
s32 actor;
int value;
{
    *(s32 *) ((char *) func_80100094(actor, 0) + 0xD0) = value;
}

s32 func_80800C00_chquiz(actor)
s32 actor;
{
    return (*(s32 *) ((s8 *) (func_80100094(actor, 0)) + (0xD0)));
}

// Clears the used-question flags.
void func_80800C24_chquiz(actor) Actor *actor;
{
    u8 *data;
    s32 i;

    data = func_80100094(actor, 0);
    for (i = 0; i < 30; i++) {
        data[0x9C + i] = 0;
    }
    for (i = 0; i < 17; i++) {
        data[0xBA + i] = 0;
    }
}

// Parses a decimal number from text at *pos, up to ',' or the end.
s16 func_80800C8C_chquiz(u8 *text, s32 *pos)
{
    s32 value;
    u8 ch;

    value = *pos * 0; // Matching: the "* 0" is needed for the match.
    ch = text[*pos];
    do {
        value = ch + value * 10 - '0';
        ch = text[++*pos];
    } while (ch != ',' && ch != 0);
    return value;
}

// Reads two comma-separated numbers from the question text.
void func_80800CE8_chquiz(Actor *actor, s32 *out_a, s32 *out_b)
{
    u8 *text;
    s32 pos;
    s32 question;

    question = func_80800B6C_chquiz(actor);
    text = _gldbstring_entrypoint_0(0, question);
    pos = 3;
    while (text[pos] != 0x8E) {
        pos += text[pos + 1] + 2;
    }
    pos += 3;
    *out_a = func_80800C8C_chquiz(text, &pos);
    pos++;
    *out_b = func_80800C8C_chquiz(text, &pos);
    _gldbstring_entrypoint_2(question);
}

// Shuffles the answer order.
void func_80800DA8_chquiz(actor, quiz) Actor *actor;
QuizOrderState *quiz;
{
    s32 i;
    s32 j;
    s8 tmp;
    for (i = 0; i < 3; i++)
        quiz->local_0[i] = i;
    for (i = 0; i < 3; i++) {
        j = func_800DC128(0, 3);
        tmp = quiz->local_0[i];
        quiz->local_0[i] = quiz->local_0[j];
        quiz->local_0[j] = tmp;
    }
}

int func_80800E38_chquiz(quiz, slot)
s32 quiz;
s32 slot;
{
    return *(s8 *) (quiz + slot + 0x60);
}

// Returns the slot of the correct answer.
int func_80800E44_chquiz(quiz)
Actor *quiz;
{
    u8 *text;
    s32 pos;
    s32 answer;
    s32 i;
    text = _gldbstring_entrypoint_0(0, *(s32 *) ((u8 *) quiz + 0xCC));
    pos = 3;
    while (text[pos] != 0x8D) {
        pos += text[pos + 1] + 2;
    }
    answer = text[pos + 2] - 0x31;
    _gldbstring_entrypoint_2(*(s32 *) ((u8 *) quiz + 0xCC));
    i = 0;
    do {
        if (answer == ((s8 *) quiz)[0x60 + i])
            return i;
        i++;
    } while (i != 3);
    return i;
}

void func_80800EF4_chquiz(s16 camera_id, f32 *pos, f32 *rot)
{
    func_800A5800(camera_id);
    _cadbfunc_entrypoint_0(pos);
    _cadbfunc_entrypoint_2(rot);
}

int func_80800F34_chquiz(s32 actor[3], s32 *state)
{
    s32 pod;
    pod = func_800F5EF8(func_800A9478(func_800A89F8()));
    *(u8 *) (state + 0x17) = 3;
    *(s16 *) (state + 0x14) = 0;
    _ncpod_entrypoint_16(pod, actor[0], 0x2C, 0x804);
    _ncpod_entrypoint_12(func_80110024(pod), 0);
    func_80801170_chquiz(actor, state);
    func_8010FD88(pod);
}

s32 func_80800FBC_chquiz(void *arg)
{
    s32 pod;
    unsigned long pad;
    s32 cam;
    cam = func_800A89F8();
    cam = func_800A9478(cam);
    cam = func_800F5EF8(cam);
    ; // Matching: empty statement needed for the match.
    pod = cam;
    if (0x2C == _ncpod_entrypoint_18(cam)) {
        _ncpod_entrypoint_17(pod, 0);
    }
}

void func_8080100C_chquiz(s32 unk_0, struct QuizCamera29 *cam, u8 preset)
{
    QuizEnt *entry = &D_808070E4_chquiz[preset];
    func_80801058_chquiz(unk_0, cam, entry->w4, entry->b2, entry->b0, entry->b1);
}

void func_80801058_chquiz(s32 unk_0, QuizCamera29 *cam, f32 duration, s8 group, s8 shot,
                          s8 moving)
{
    s16 camera_id;
    void *pod;
    void *pod_cam;

    f32 *rot;
    f32 time;
    camera_id = D_808070C4_chquiz[group * 10 + shot];
    pod = func_800F5EF8(func_800A9478(func_800A89F8()));
    pod_cam = func_80110024(pod);
    if (_ncpod_entrypoint_13(pod_cam)) {
        func_8010FFB0(pod, cam->cameraPosition, cam->cameraRotation);
        _ncpod_entrypoint_12(pod_cam, 0);
    }
    if (camera_id != cam->camera) {
        rot = cam->cameraRotation;
        func_80800EF4_chquiz(camera_id, cam->targetPosition, cam->targetRotation);
        func_800EE7F8(cam->position, cam->cameraPosition);
        func_800EE7F8(cam->rotation, rot);
        if (moving == 0)
            time = 0.0f;
        else
            time = duration;
        cam->duration = time;
        cam->elapsed = time;
        cam->moving = moving;
        cam->camera = camera_id;
    }
}

s32 func_80801170_chquiz(unk_0, state)
s32 unk_0;
u8 *state;
{
    f32 pos[3];
    f32 rot[3];
    s32 done;
    f32 t;
    f32 fov;
    s32 pod;
    void *pod_state;

    done = func_800D90A4((f32 *) (state + 0x54));
    t = func_800F12D4(*(f32 *) (state + 0x54), *(f32 *) (state + 0x58), 0.0f, 0.0f, 1.0f);
    pod_state = func_800A9478(func_800A89F8());
    pod = func_80110024(func_800F5EF8(pod_state));
    if (state[0x5C] != 4) {
        fov = _ncpod_entrypoint_10(pod);
        if (fov != 40.0f)
            _ncpod_entrypoint_9(pod, func_800F15F8(fov, 40.0f, 0.5f));
    }
    switch (state[0x5C]) {
        case 0:
            func_800EE7F8((f32 *) (state + 0x38), ((f32 *) (state + 0x1C)));
            func_800EE7F8((f32 *) (state + 0x44), ((f32 *) (state + 0x28)));
            _ncpod_entrypoint_8(pod, ((f32 *) (state + 0x1C)), ((f32 *) (state + 0x28)));
            break;
        case 1:
            func_800EFE50(pos, (f32 *) state, (f32 *) (state + 0x1C), t);
            func_800F16AC(rot, (f32 *) (state + 0xC), (f32 *) (state + 0x28), t);
            func_800EE7F8((f32 *) (state + 0x38), pos);
            func_800EE7F8((f32 *) (state + 0x44), rot);
            _ncpod_entrypoint_8(pod, pos, rot);
            break;
        case 2:
            func_800EFE50(pos, (f32 *) state, (f32 *) (state + 0x1C), 0.5f);
            func_800EFB24(rot, (f32 *) state, pos);
            func_800EF934(rot, rot, 180.0f * t);
            func_800EF04C(pos, rot);
            pos[1] = func_800F1214(t, *(f32 *) (state + 4), *(f32 *) (state + 0x20));
            func_800F16AC(rot, (f32 *) (state + 0xC), (f32 *) (state + 0x28), t);
            func_800EE7F8((f32 *) (state + 0x38), pos);
            func_800EE7F8((f32 *) (state + 0x44), rot);
            _ncpod_entrypoint_8(pod, pos, rot);
            break;
        case 3:
        case 4:
            break;
    }
    if (done && state[0x5C] != 3 && state[0x5C] != 4) {
        state[0x5C] = 3;
        func_800EE7F8((f32 *) state, (f32 *) (state + 0x1C));
        func_800EE7F8(((f32 *) (state + 0xC)), ((f32 *) (state + 0x28)));
    }
    return done;
}

s32 func_808013E0_chquiz(s32 unk_0, u8 *state)
{
    s32 finished;
    int is_manual;
    finished = (state[0x5C] == 3) || (is_manual = state[0x5C] == 4); // Matching: needed for the match.
    return;
}

void func_80801408_chquiz(Actor *actor, u8 *state, s32 unk_0, u32 flags)
{
    _ncpod_entrypoint_20(func_800F5EF8(func_800A9478(func_800A89F8())), actor->unk0, unk_0,
                         flags | 0x20);
    state[0x5C] = 4;
}

void func_80801470_chquiz(s32 unk_0, u8 *state)
{
    if (state[0x5C] == 4) {
        func_8010FFB0(func_800F5EF8(func_800F54E4()), state + 0x38, state + 0x44);
        state[0x5C] = 3;
        _ncpod_entrypoint_12(func_80110024(func_800F5EF8(func_800A9478(func_800A89F8()))), 0);

    }
}

void func_808014F8_chquiz(s32 unk_0, s32 unk_1) {
    _ncpod_entrypoint_15(func_80110024(func_800F5EF8(func_800A9478(func_800A89F8()))), unk_0, unk_1);
}

// Matching: the line breaks in this function are needed for the match.
s32 func_80801544_chquiz(s32 value){
    return value | 0; // Matching: the "| 0" is needed for the match.
}

// Matching: the line breaks in this function are needed for the match.
int func_8080154C_chquiz(s32 scores)
{
  s32 target;
  s32 reached;
  s32 i;
  s32 unk_0;
  if (func_800D3948(scores))
  {
    if (_gcstatusDll_entrypoint_17())
    {
      return _suquiz_entrypoint_16();
    }
    {
      target = _gcstatusDll_entrypoint_18();
      reached = 0;
      for (i = 3; i < 7; i++)
      {
        reached |= func_80801784_chquiz(scores | 0, i) >= target; // Matching: the "| 0" is needed for the match.
      }

      return reached;
    }
}
return _suquiz_entrypoint_16();
}

// Counts the round timer down with tick sounds; returns 1 when time is up.
// Matching: the line breaks in this function are needed for the match.
s32 func_80801600_chquiz(Actor *actor)
{
    s32 expired;

    if (((QuizTimerState *) actor)->local_2) {
        ((QuizTimerState *) actor)->local_1 = ((QuizTimerState *) actor)->local_0;
        ((QuizTimerState *) actor)->local_0 -= func_800D9004();
        expired = ((QuizTimerState *) actor)->local_0 <= 0.0f;

if (!expired) {
    if (func_800F13C4(((QuizTimerState *) actor)->local_1, 1.0f) <
        func_800F13C4(((QuizTimerState *) actor)->local_0, 1.0f)) {
        func_800C3FC0(0x3E9, 1.2f, 32000);
    }
} else {

func_800C3FC0(0x4D5, 1.0f, 10000);
}
func_800D2498(0x116, (s32)((QuizTimerState *)actor)->local_0, 0);
return expired;
}
return 0;
}

// Matching: the line breaks in this function are needed for the match.
void func_808016F8_chquiz(u8 *data, s32 active, f32 duration) {
    data[0x90] = active;
    *(f32 *)(data + 0x8C) = duration;
    *(f32 *)(data + 0x88) = duration;
    *(f32 *)(data + 0x84) = duration;
}

// Matching: the line breaks in this function are needed for the match.
void func_80801710_chquiz(void *data) {
    ((u8 *)data)[0x90] = 1;
}

// Matching: the line breaks in this function are needed for the match.
func_8080171C_chquiz(u8 *data) {
    return data[0x90];
}

// Clears all player scores.
void func_80801724_chquiz(u8 *data)
{
    s32 i;

    for (i = 0; i < 7; i++) {
        ((s32 *)(data + 0x64))[i] = 0;
    }
    *(s32 *)(data + 0x80) = -1;
}

// Matching: the line breaks in this function are needed for the match.
void func_80801758_chquiz(u8 *data, s32 value) {
    *(s32 *)(data + 0x80) = value;
}

// Adds the points for the given index to a player's score.
int func_80801760_chquiz(s32 *scores, s32 index, s32 player)
{
    s32 slot;
    slot = (s32)scores + player * 4;
    (*(s32 *)((char *)(slot) + 0x64)) += D_808071B1_chquiz[index];
}

// Returns a player's score.
// Matching: the line breaks in this function are needed for the match.
int func_80801784_chquiz(scores, player) s32 scores[4]; s32 player;
{
    return ((s32 *)scores)[player + 0x19];
}

// Updates the score HUD items.
// Matching: the line breaks in this function are needed for the match.
void func_80801794_chquiz(u8 *data) {
    s32 selected;

    if (func_800D3948() != 0) {
        selected = (*(s32 *)((s8 *)(data) + (0x80))) >= 0;
        switch (selected) {
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
        func_800D2498(0x112, func_80801784_chquiz(data, 3), 0);
        func_800D2498(0x114, func_80801784_chquiz(data, 4), 0);
        func_800D2498(0x115, func_80801784_chquiz(data, 5), 0);
        func_800D2498(0x113, func_80801784_chquiz(data, 6), 0);
        return;
    }
    if (func_800DA298(0x582) == 0) {
        func_800D2498(0x10F, func_80801784_chquiz(data, 1), 0);
    }
    if (func_800DA298(0x583) == 0) {
        func_800D2498(0x110, func_80801784_chquiz(data, 0), 0);
    }
    func_800D2498(0x111, func_80801784_chquiz(data, 2), 0);
    if (_suquiz_entrypoint_4() == 2) {
        func_800D2498(0x118, 0xF, 0);
    }
}

// Collects the contestants with the lowest score into out; returns the count.
// Matching: the line breaks in this function are needed for the match.
int func_80801930_chquiz(OSPiHandle *scores, OSIoMesg *out)
{
    int one;
    s32 min_score = 0x186A0;
    s32 count = 1;
    s32 i;
    s32 j;
    s32 score;
    *((s32 *) (((char *) out) + 0x8)) = -1;
    *((s32 *) (((char *) out) + 0x4)) = -1;
    *((s32 *) (((char *) out) + 0x0)) = -1;
    i = 0;
    do
    {
        one = 1; // Matching: needed for the match.
        if (_suquiz_entrypoint_9(i) == 0)
        {
            score = func_80801784_chquiz(scores, i);

if (score < min_score) {
    min_score = score;
    *(s32 *) ((char *) out + 0x0) = i;
}

}
i += one;
}
while (i < 3)
    ;
j = *(s32 *) ((char *) out + 0x0) + 1;
if (j < 3) {
    do {
        if (((((_suquiz_entrypoint_9(j) == 0) &&
               (func_80801784_chquiz(scores, j) == min_score)) &&
              (j != (*((s32 *) (((char *) out) + 0x0))))) &&
             (j != (*((s32 *) (((char *) out) + 0x4))))) &&
            (j != (*((s32 *) (((char *) out) + 0x8))))) {
            *(s32 *) ((char *) out + (count * 4)) = j;
            count += 1;
        }

j += 1;
}
while (j != 3)
    ;
}
return count;
}

// Collects the players with the highest score into out; returns the count.
s32 func_80801A54_chquiz(s32 scores, s32 *out)
{
    s32 i;
    s32 best;
    s32 count;
    s32 score;
    s32 k;

    best = -100000;
    count = 1;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    for (i = 3; i < 7; i++) {
        score = func_80801784_chquiz(scores, i);
        if (score > best) {
            best = score;
            out[0] = i;
        }
    }
    for (i = 3; i < 7; i++) {
        if (func_80801784_chquiz(scores, i) == best && i != out[0] &&
            i != out[1] && i != out[2]) {
            for (k = 1; out[k] != -1; k++) {
            }
            out[k] = i;
            count++;
        }
    }
    return count;
}

// Returns the lowest score among the contestants.
s32 func_80801B7C_chquiz(s32 scores)
{
    s32 min_score;
    s32 i;
    s32 score;

    min_score = 0x186A0;
    i = 0;
    do {
        score = func_80801784_chquiz(scores, i);
        if ((score < min_score) && (_suquiz_entrypoint_9(i) == 0)) {
            min_score = score;
        }
        i += 1;
    } while (i != 3);
    return min_score;
}

// Returns the first player whose score reaches the threshold, or -1.
s32 func_80801C08_chquiz(s32 scores, s32 threshold)
{
    s32 player;
    s32 unk_0;

    player = 3;
    for (unk_0 = 3; player < 7; player++) {
        if (func_80801784_chquiz(scores, player) >= threshold) {
            return player;
        }
    }
    return -1;
}

s32 func_80801C7C_chquiz(s32 actor)
{
    u8 *prop;
    u8 *found;
    found = _subaddiefind_entrypoint_11(0x52C, actor);
    prop = found;
    func_80102424(found, 2);
    *((u8 *) (((s8 *) prop) + 0x65)) = (u8) (((*((u8 *) (((s8 *) prop) + 0x65))) & 0xFFu) | 1);
    return *((s32 *) (((s8 *) prop) + 0));
}

void func_80801CC4_chquiz(Actor *actor)
{
    f32 target[3];
    f32 scale;
    f32 progress;
    f32 offset[3];
    f32 drop;

    progress = func_80101F24(actor);
    func_800EE7F8(target, (f32 *) &actor->actorData[4]);
    switch (D_80807220_chquiz[actor->unk70_10].local_0) {
        case 0x596:
            func_800EEB9C(offset, actor->rotation[1] - 90.0f,
                          func_800138D0(func_800F10B4(progress, 0.0f, 1.0f, 0.0f, 360.0f)) * 30.0f);
            func_800EF04C(target, offset);
            scale = 2.0f;
            func_800EFA4C(actor->position, *(f32 *) &actor->actorData[4],
                          *(f32 *) &actor->actorData[5] + -80.0f,
                          *(f32 *) &actor->actorData[6]);
            break;
        case 0x597:
            if (progress < 0.65f) {
                scale = func_800F10B4(progress, 0.0f, 0.65f, 2.0f, 3.0f);
                drop = func_800F10B4(progress, 0.0f, 0.65f, 0.0f, 0.0f);
            } else {
                scale = 3.0f;
                drop = 0.0f;
            }
            func_800EFA4C(actor->position, *(f32 *) &actor->actorData[4],
                          *(f32 *) &actor->actorData[5] + drop + -80.0f,
                          *(f32 *) &actor->actorData[6]);
    }
    _chbadshad_entrypoint_1(actor, target, scale);
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            if (func_80101E14(actor, 0.1f)) {
                func_80101180(0x528, 0x6C, 0);
            } else if (func_80101E14(actor, 0.65f)) {
                func_800BBCB8((f32 *) &actor->actorData[4], (f32 *) &actor->actorData[4], 1.0f,
                              4, D_8080723C_chquiz);
                func_800BBCB8((f32 *) &actor->actorData[4], (f32 *) &actor->actorData[4], 1.0f,
                              20, D_80807274_chquiz);
                func_800C3F48(0x7FFB5E84);
                func_800187B4(0, 1.0f, 0.2f, 0.3f);
                actor->actorData[3] = func_800E15CC(0, 10.0f, 0.6f);
                _subaddieaudioloop_entrypoint_2(actor);
            } else if (func_80101DDC(actor)) {
                func_80101238(0x88, 0);
                func_80102424(actor, 3);
                if (actor->actorData[3]) {
                    func_800E1720(actor->actorData[3] - 1);
                }
            }
            if (func_80101F24(actor) < 0.65f) {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_808072BC_chquiz);
            }
            break;
        case 3:
            func_8010C908((s32) actor, (s32) actor->position);
    }
}

int chquiz_entrypoint_0()
{
    return (int) &D_808072CC_chquiz;
}

void func_80802004_chquiz(Actor *actor)
{
    f32 pos[3];
    f32 offset[3];
    s32 i;

    func_800EE7F8(pos, actor->position);
    func_800EEB9C(offset, actor->rotation[1], 50.0f);
    func_800EF04C(pos, offset);
    for (i = 0; i < 2; i++) {
        actor->actorData[i + 4] = func_800C8A98();
        func_800C8F64(actor->actorData[i + 4], 0xF);
        func_800C8E84(actor->actorData[i + 4], D_8080731C_chquiz);
        func_800C8D4C(actor->actorData[i + 4], D_80807314_chquiz);
        func_800C8CB8(actor->actorData[i + 4], pos);
        func_800C8FE0(actor->actorData[i + 4], 1);
        pos[1] += func_80103EF4(actor);
    }
}

s32 func_80802108_chquiz(s32 data, s32 state)
{
    s32 i;
    s32 *ptr;

    i = 0;
    ptr = (s32 *) data;
    do {
        if (ptr[0x28 / 4] != 0) {
            func_800C8FE0(ptr[0x28 / 4], state);
        }
        i += 4;
        ptr += 1;
    } while (i != 8);
}

void func_8080216C_chquiz(s32 *data)
{
    s32 i;
    int zero_a;
    int zero_b;
    for (i = 0; i < 2; i++) {
        // Matching: the zero_a/zero_b temporaries are needed for the match.
        zero_a = 0;
        if (data[i + 10] != zero_a) {
            zero_b = 0;
            func_800C8B84(data[i + 10]);
            data[i + 10] = zero_b;
        }
    }
}

void func_808021C8_chquiz(Actor *actor, s32 player, f32 *pos)
{
    f32 rot[3];
    if (player < _gcstatusDll_entrypoint_11()) {
        if (func_800F6438(player)) {
            func_800F8294(player, pos);
            func_800EFA4C(rot, 0.0f, actor->rotation[1], 0.0f);
            func_800F832C(player, rot);
            func_800F4CEC(player, 0);
        }
    }
}

void func_80802250_chquiz(Actor *actor)
{
    u16 *data;

    data = func_80100094(actor, 0);
    if (_suquiz_entrypoint_9(actor->unk74_7)) {
        func_800FFAB0(actor);
        return;
    }
    switch (actor->unk74_7) {
        case 2:
            if (func_800DA298(0x441)) {
                func_800FFAB0(actor);
                return;
            }
            data[0] = _chblink_entrypoint_1(0);
            data[1] = _chblink_entrypoint_1(1);
            func_808021C8_chquiz(actor, 0, D_80807328_chquiz);
            break;
        case 1:
            data[0] = _chblink_entrypoint_1(2);
            data[1] = 0;
            actor->unk64_24 = 1;
            break;
        case 0:
            actor->unk64_24 = 1;
            break;
        case 3:
            func_808021C8_chquiz(actor, 0, actor->position);
            break;
        case 4:
            func_808021C8_chquiz(actor, 1, actor->position);
            break;
        case 5:
            data[0] = _chblink_entrypoint_1(3);
            data[1] = _chblink_entrypoint_1(1);
            func_808021C8_chquiz(actor, 2, actor->position);
            break;
        case 6:
            func_808021C8_chquiz(actor, 3, actor->position);
            break;
        default:
            data[0] = 0;
            data[1] = 0;
    }
    func_80103140(actor, func_80800000_chquiz(actor->unk74_7) & 0xFFFF,
                  *((u16 *) ((u8 *) actor->unk0 + 0x16)));
    func_80102FDC(actor, func_80800070_chquiz(actor->unk74_7));
    func_80802004_chquiz(actor);
    func_80102424(actor, actor->unk70_10);
}

// Switches a contestant to a new state and runs the entry actions.
void func_80802434_chquiz(u8 *actor, s32 state)
{
    s32 prop;

    switch (state) {
        case 1:
            func_80802108_chquiz(actor, 1);
            break;
        case 3:
            func_80802108_chquiz(actor, 1);
            break;
        case 4:
            func_80802108_chquiz(actor, 1);
            break;
        case 5:
            func_80803368_chquiz((u32) ((u16) (*(u16 *) ((s8 *) (actor) + (0x76)))) >> 7, 1);
            break;
        case 7:
            func_80802108_chquiz(actor, 0);
            break;
        case 8:
            func_80802108_chquiz(actor, 1);
            break;
        case 11:
            func_80802108_chquiz(actor, 1);
            break;
        case 10:
            func_80802108_chquiz(actor, 0);
            break;
        case 12:
            func_8080216C_chquiz(actor);
            break;
        case 13:
            prop =
                func_80801C7C_chquiz((u32) ((u16) (*(u16 *) ((s8 *) (actor) + (0x76)))) >> 7);
            (*(s32 *) ((s8 *) (actor) + (0x3C))) = prop;
            func_80803320_chquiz((u32) ((u16) (*(u16 *) ((s8 *) (actor) + (0x76)))) >> 7,
                                 prop);
            break;
        case 14:
            func_80802108_chquiz(actor, 1);
            break;
        case 15:
            func_800FFAB0(_subaddiefind_entrypoint_11(
                0x52B, (u32) ((u16) (*(u16 *) ((s8 *) (actor) + (0x76)))) >> 7));
            func_800FFAB0(actor);
            if ((((u32) ((u16) (*(u16 *) ((s8 *) (actor) + (0x76)))) >> 7) == 2) &&
                (func_800D395C() == 0)) {
                func_800F4CC0(func_800F54E4());
                func_800F4CEC(func_800F54E4(), 0x20);
                func_800F7B9C(func_800F54E4(), 0x91);
            }
            break;
        case 16:
            func_800F4CC0(func_800F54E4());
            func_800FFAB0(actor);
    }
    func_80102424(actor, state);
}

int func_80802628_chquiz(Actor *actor)
{
    u16 flags;
    flags = *((u16 *) (((char *) actor) + 0x76));
    flags = ((unsigned short) ((((((u32) flags) >> 7) - 0x32) << 5) << 2)) | (flags & 0x7F);
    *((u16 *) (((char *) actor) + 0x76)) = flags;
    func_80108B04(actor, 0);
}

void func_80802664_chquiz(Actor *actor)
{
    void *expression;

    switch (actor->unk70_10) {
        case 1:
            break;
        case 3:
        case 4:
            if (_suquiz_entrypoint_6() == actor->unk74_7) {
                func_80802434_chquiz(actor, 5);
            }
            break;
        case 5:
            if (func_80101E14(actor, func_808000E0_chquiz(actor->unk74_7))) {
                func_80101180(0x529, 0x83, actor->unk74_7);
                if (func_80101180(0x528, 0x83, actor->unk74_7)) {
                    func_80802434_chquiz(actor, 8);
                } else {
                    func_80802434_chquiz(actor, 7);
                }
            } else if (func_80101DDC(actor)) {
                func_80802434_chquiz(actor, 6);
            }
            break;
        case 2:
        case 14:
            if (func_80101DDC(actor)) {
                func_80802434_chquiz(actor, 1);
            } else if (func_80101E14(actor, 0.3f)) {
                _suquiz_entrypoint_28(1, actor->unk74_7, actor->position);
            }
            break;
        case 11:
            if (func_80101DDC(actor)) {
                func_80802434_chquiz(actor, 1);
            } else if (func_80101E14(actor, 0.3f)) {
                _suquiz_entrypoint_28(1, actor->unk74_7, actor->position);
            }
            break;
        case 9:
            if (func_80101DDC(actor)) {
                func_80802434_chquiz(actor, 10);
            } else if (func_80101E14(actor, 0.3f)) {
                _suquiz_entrypoint_28(2, actor->unk74_7, actor->position);
            }
            break;
        case 12:
            if (func_80101DDC(actor)) {
                func_80802434_chquiz(actor, 13);
            }
            break;
        case 13:
            if (func_80101E14(func_80106790(actor->unk3C), 0.85f)) {
                _suquiz_entrypoint_28(3, actor->unk74_7, actor->position);
                _suquiz_entrypoint_28(3, actor->unk74_7, actor->position);
            } else if (func_80101E14(func_80106790(actor->unk3C), 0.9f) &&
                       actor->unk74_7 == 1) {
                func_800C3F48(0x7FFFFE70);
            }
    }
    if (actor->unk74_7 == 3 || actor->unk74_7 == 4 || actor->unk74_7 == 5 ||
        actor->unk74_7 == 6) {
        func_801039E4(actor->unk0);
    }
    expression = func_80100094(actor, 1);
    if (((QuizExpressionFlag481 *) actor)->local_0 && expression) {
        _suexpression_entrypoint_10(expression, actor->unk0, 0);
    }
}

void func_808029A4_chquiz(Actor *actor)
{
    s16 *blink_ids;
    s32 i;

    blink_ids = func_80100094(actor, 0);
    for (i = 0; i < 2; i++) {
        if (blink_ids[i] != 0) {
            _chblink_entrypoint_3(blink_ids[i]);
        }
    }
    if (func_80100094(actor, 1) != 0) {
        _suexpression_entrypoint_8(actor, 1);
    }
    func_8080216C_chquiz(actor);
}

// Message handler of the contestants (0x529).
s32 func_80802A2C_chquiz(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x3D: {
            Actor *child;
            s32 removed;
            child = (Actor *) _subaddiefind_entrypoint_11(0x52C, actor->unk74_7);

            if (child == 0) {
                child =
                    (Actor *) func_80108528(0x52C, (char *) actor + 4,
                                            (s32) *(f32 *) ((char *) actor + 0x48), &actor);

                func_800EFA4C((char *) child + 0x28, *(f32 *) ((char *) actor + 4),
                              *(f32 *) ((char *) actor + 8), *(f32 *) ((char *) actor + 0xC));

                func_800EFA4C((char *) child + 4, *(f32 *) ((char *) actor + 4),
                              actor->position[1] + -80.0f, *(f32 *) ((char *) actor + 0xC));

                func_8010A800(child, 1);

                child->unk74_7 = actor->unk74_7;
            }

            if (func_800D3948()) {
                removed = 0;
            } else if (!func_800D395C() && func_800DA298(0x441)) {
                removed = 1;
            } else {
                removed = _suquiz_entrypoint_9(actor->unk74_7);
            }

            if (removed != 0) {
                func_80102424(child, 3);
                func_800FFAB0(actor);
                return 1;
            }

            child = (Actor *) func_80108528(0x52B, (char *) actor + 4,
                                              (s32) *(f32 *) ((char *) actor + 0x48), &actor);

            child->unk74_7 = actor->unk74_7;

            return 1;
        }
        case 0x99:
            func_80101074(func_808000C4_chquiz(actor->unk74_7));
            return 1;

        case 0x95:
            func_80802250_chquiz(actor);
            return 1;

        case 0x82:
            func_80802434_chquiz(actor, 3);
            return 1;

        case 0x83:
            if (arg != actor->unk74_7) {
                func_80802434_chquiz(actor, 7);
            }
            return 1;

        case 0x84:
            if (arg == actor->unk74_7) {
                func_80802434_chquiz(actor, 0xB);
            }
            return 1;

        case 0x85:
            if (arg == actor->unk74_7) {
                func_80802434_chquiz(actor, 9);
            }
            return 1;

        case 0x86:
            if (actor->unk70_10 != 0xA && actor->unk70_10 != 9) {
                func_80802434_chquiz(actor, 4);
            }
            return 1;

        case 0x87:
            if (func_800D3948()) {
                if (arg == actor->unk74_7) {
                    func_80802434_chquiz(actor, 0xE);
                } else {
                    func_80802434_chquiz(actor, 0xC);
                }
            } else {
                if (arg == actor->unk74_7) {
                    func_80802434_chquiz(actor, 0xC);
                } else {
                    func_80802434_chquiz(actor, 0xE);
                }
            }
            return 1;

        case 0x88:
            if ((actor->unk70_10) == 0xD) {
                func_80802434_chquiz(actor, 0xF);
            }
            return 1;

        case 0x89:
            if (_suquiz_entrypoint_6() == actor->unk74_7) {
                func_80802434_chquiz(actor, 6);
                func_80803368_chquiz(actor->unk74_7, 0);
            } else {
                func_80802434_chquiz(actor, 7);
            }
            return 1;

        case 0x8A:
            if (arg == actor->unk74_7) {
                func_80802434_chquiz(actor, 0x10);
            }
            return 1;

        case 0x8B:
            if (arg == actor->unk74_7) {
                func_80802434_chquiz(actor, 2);
            }
            return 1;

        case 0x3B:
            func_80802434_chquiz(actor, 1);
            return 1;

        case 1:
            if (_suquiz_entrypoint_11(actor->unk74_7)) {
                return 0;
            }

            _suquiz_entrypoint_21(actor->unk74_7, 1);
            return 1;

        case 2:
            if ((s32) actor->unk74_7 != 2) {
                _suquiz_entrypoint_21(actor->unk74_7, -1);
            }
            return 1;

        case 0x97: {
            f32 vec[3];

            func_800EFA4C(vec, 0, (1.0f / actor->scale) * 400.0f, 0);
            func_80101010(vec);
            return 1;
        }

        case 0x1F: {
            s16 *blink_ids;
            s32 i;
            Actor *prop;
            f32 progress;

            blink_ids = func_80100094(actor, 0);

            func_801015D0(actor);

            switch (actor->unk74_7) {
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

for (i = 0; i < 2; i++) {
    if (blink_ids[i] != 0) {
        _chblink_entrypoint_2(blink_ids[i]);
        _chblink_entrypoint_4(blink_ids[i]);
    }

}

if ((actor->unk70_10) == 0xD) {
    prop = (Actor *) func_80106790(*(void **) ((char *) actor + 0x3C));

if (prop) {
    progress = func_80101F24(prop);
} else {

return 1;

}

if (progress > 0.5f) {
    if (progress < 0.65f) {
        progress = func_800F10B4(progress, 0.5f, 0.65f, 1.0f, 0.01f);
    } else {

progress = 0.01f;
}

func_800DF500(1.0f, progress, 1.0f);
}
}

return 1;
}
case 0x29:
    switch (actor->unk74_7) {
        case 0:
            _suexpression_entrypoint_7(actor, 1, 0x7D);
            _suexpression_entrypoint_12(func_80100094(actor, 1), 60.0f, 15.0f);
            return 1;

        case 1:
            _suexpression_entrypoint_7(actor, 1, 0x7E);
            _suexpression_entrypoint_12(func_80100094(actor, 1), 60.0f, 15.0f);
            return 1;

        case 3:
            _suexpression_entrypoint_7(actor, 1, 0x10);
            _suexpression_entrypoint_12(func_80100094(actor, 1), 60.0f, 15.0f);
            return 1;

        case 4:
            _suexpression_entrypoint_7(actor, 1, 0x6F);
            _suexpression_entrypoint_12(func_80100094(actor, 1), 60.0f, 15.0f);
            return 1;

        case 6:
            _suexpression_entrypoint_7(actor, 1, 0x40);
            _suexpression_entrypoint_12(func_80100094(actor, 1), 60.0f, 15.0f);
            return 1;

        default:
            return 0;
    }

case 0x2A:
    switch (actor->unk74_7) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 6:
            _suexpression_entrypoint_8(actor, 1);
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

    int func_80803320_chquiz(s32 index, s32 prop)
    {
        Actor *podium;
        // Matching: `index | index` is needed for the match.
        podium = _subaddiefind_entrypoint_11(0x52B, index | index);
        func_80102424(podium, 4);
        podium->unk3C = prop;
    }

    void func_80803368_chquiz(Actor *index, s32 flag)
    {
        Actor *podium;
        f32 pos[3];

        podium = _subaddiefind_entrypoint_11(0x52B, index);
        if (flag) {
            podium->unk64_20 = 1;
        } else {
            podium->unk64_20 = 0;
        }
        func_80102424(podium, 2);
        if (!_subaddieskeleton_entrypoint_2(podium->unk0, 4, pos)) {
            func_800EFA4C(pos, podium->position[0],
                          podium->position[1] + func_80103EF4(podium) * 0.5f,
                          podium->position[2]);
        }
        podium->actorData[3] = func_800C8A98();
        func_800C8F64(podium->actorData[3], 0xF);
        func_800C8E84(podium->actorData[3], D_80807474_chquiz);
        func_800C8D4C(podium->actorData[3], D_8080746C_chquiz);
        func_800C8CB8(podium->actorData[3], pos);
        func_800C8FE0(podium->actorData[3], 0);
    }

    void func_80803470_chquiz(actor) Actor *actor;
    {
        switch (actor->unk70_10) {
            case 1:
                break;
            case 2:
                if (func_80101DDC(actor)) {
                    actor->unk58 = 1.0f;
                    func_80102424(actor, 3);
                    return;
                }
                if (func_80101E14(actor, func_808000E0_chquiz(actor->unk74_7))) {
                    if (actor->unk64_20)
                        _suquiz_entrypoint_28(0, actor->unk74_7, actor->position);
                    if (actor->actorData[3])
                        func_800C8FE0(actor->actorData[3], 1);
                }
                break;
            case 3:
                if (func_800D90A4(&actor->unk58)) {
                    if (actor->actorData[3]) {
                        func_800C8B84(actor->actorData[3]);
                        actor->actorData[3] = 0;
                    }
                    func_80102424(actor, 1);
                }
        }
    }

    s32 func_80803588_chquiz(u8 *actor, s32 msg, s32 arg)
    {
        u8 *prop;
        f32 prop_progress;
        s32 pad_2C;
        s32 pad_28;
        f32 anim_progress;

        switch (msg) {
            case 0x95:
                func_80103140(actor,
                              (u16) func_8080008C_chquiz((u32) *(u16 *) (actor + 0x76) >> 7),
                              *(u16 *) (*(u8 **) actor + 0x16));
                func_80102FDC(actor, func_808000A8_chquiz((u32) *(u16 *) (actor + 0x76) >> 7));
                func_80102424(actor, (u32) *(u16 *) (actor + 0x72) >> 10);
                return 1;
            case 0x99:
                switch ((u32) *(u16 *) (actor + 0x76) >> 7) {
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
                func_801015D0(actor);
                switch ((u32) *(u16 *) (actor + 0x76) >> 7) {
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
                switch ((u32) *(u16 *) (actor + 0x72) >> 10) {
                    case 1:
                        func_800DF744(2, 1);
                        return 1;
                    case 2:
                        anim_progress = func_80101F24(actor);
                        func_800DF744(
                            2, func_808000E0_chquiz((u32) *(u16 *) (actor + 0x76) >> 7) < anim_progress
                                   ? 2
                                   : 1);
                        return 1;
                    case 3:
                        func_800DF744(2, 2);
                        return 1;
                    case 4:
                        prop = func_80106790(*(s32 *) (actor + 0x3C));
                        func_800DF744(2, 1);
                        if (prop != 0) {
                            prop_progress = func_80101F24(prop);
                        } else {
                            return 1;
                        }
                        if (prop_progress > 0.5f) {
                            if (prop_progress < 0.65f) {
                                prop_progress = func_800F10B4(prop_progress, 0.5f, 0.65f, 1.0f, 0.01f);
                            } else {
                                prop_progress = 0.01f;
                            }
                            func_800DF500(1.0f, prop_progress, 1.0f);
                        }
                    default:
                        return 1;
                }
            default:
                return 0;
        }
    }

    int func_80803910_chquiz(actor)
    Actor *actor;
    {
        if ((*(s32 *) ((char *) (actor) + 0x24)) != 0) {
            func_800C8B84((*(s32 *) ((char *) (actor) + 0x24)));
            (*(s32 *) ((char *) (actor) + 0x24)) = 0;
        }
    }

    int *chquiz_entrypoint_2()
    {
        return &D_80807480_chquiz;
    }

    void func_80803954_chquiz(Actor *actor)
    {
        switch (actor->unk70_10) {
            case 1:
                func_80103110(actor, 0);
                break;
            case 2:
                if (func_800D90A4(&actor->unk58)) {
                    func_800C8B84(actor->actorData[7]);
                    actor->actorData[7] = 0;
                    func_80101FDC(actor, 1);
                }
        }
    }

    // Message handler of the podium lights (0x52E).
    int func_808039D4_chquiz(Actor *actor, s32 msg, s32 arg)
    {
        f32 pos[3];
        switch (msg) {
            case 0x8C:
                if (arg != 2) {
                    func_800EE7F8(pos, actor->position);
                    func_800EF1B8(pos, actor->rotation[1], 10.0f);
                    *(s32 *) ((u8 *) actor + 0x34) = func_800C8A98();
                    func_800C8F64(*(s32 *) ((u8 *) actor + 0x34), 0xF);
                    func_800C8E84(*(s32 *) ((u8 *) actor + 0x34), &D_808074D0_chquiz);
                    func_800C8D4C(*(s32 *) ((u8 *) actor + 0x34), &D_808074C8_chquiz);
                    func_800C8CB8(*(s32 *) ((u8 *) actor + 0x34), pos);
                    func_800C8FE0(*(s32 *) ((u8 *) actor + 0x34), 1);
                    if (((u32) *(u16 *) ((u8 *) actor + 0x76)) >> 7 == 0x33)
                        func_800C3F48(0x7FFFFD3B);
                    *(f32 *) ((u8 *) actor + 0x58) = 1.5f;
                    func_80103110(actor, 1);
                    func_80101FDC(actor, 2);
                } else
                    func_800C3F48(0x7FFFFD3A);
                return 1;
            case 0x1F:
                func_801015D0(actor);
                switch (actor->unk70_10) {
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

    int func_80803B54_chquiz(s32 actor[4], s32 text_id, s32 unk_2)
    {
        u32 speaker;
        speaker = actor[0];
        return _subaddiedialog_entrypoint_11(speaker, text_id, unk_2, actor + 1, 0x4d);
    }

    int func_80803B88_chquiz(s32 pos)
    {
        s32 effect;
        effect = func_800C8A98();
        func_800C8CB8(effect, pos);
        func_800C8F64(effect, 0xF);
        func_800C8D4C(effect, &D_8080755C_chquiz);
        func_800C8E84(effect, &D_80807564_chquiz);
        _chlightfader_entrypoint_1(effect, 0x40000000, 1);
    }

    void func_80803BFC_chquiz(u8 *actor)
    {
        S16 unk_0;
        S24 unk_1;
        S24 unk_2;
        s32 bone_pos[3];
        f32 progress;
        s32 i;
        s32 count;
        u16 unk_3;
        s32 pad_44;
        s32 particle_pos;
        if ((*((u16 *) (((s8 *) actor) + 0x64))) & 1) {
            switch (D_80807528_chquiz[((Actor *) actor)->unk70_10].id) {
                case 0x4C4:
                    if (func_80101DDC(actor) != 0) {
                        func_80102424(actor, 1);
                    }
                    break;

                case 0x4C5:
                    unk_0 = *(S16 *) &D_80807570_chquiz;
                    _subaddieaudioquick_entrypoint_4(actor, actor + 4, &D_808075B0_chquiz,
                                                     &unk_0);
                    if (func_80101DDC(actor) != 0) {
                        func_80102424(actor, 5);
                    }
                    break;

                case 0x4C7:
                    unk_1 = *(S24 *) &D_80807580_chquiz;
                    unk_2 = *(S24 *) &D_80807598_chquiz;
                    progress = func_80101F24(actor);
                    _subaddieskeleton_entrypoint_0(actor, 0x44, bone_pos);
                    _subaddieaudioquick_entrypoint_3(actor, (actor + 4), &D_80807640_chquiz,
                                                     0.33f);
                    _subaddieaudioquick_entrypoint_3(actor, (actor + 4), &D_8080765C_chquiz,
                                                     0.88f);
                    _subaddieaudioquick_entrypoint_3(actor, (actor + 4), &D_80807624_chquiz,
                                                     0.09f);
                    if (func_80101E14(actor, 0.09f) != 0) {
                        func_800C3F48(0x7FFFFE87);
                    } else if (func_80101E14(actor, 0.2f) != 0) {
                        func_800C3F48(0x7FFFFE88);
                    } else if (func_80101E14(actor, 0.33f) != 0) {
                        func_800C3F48(0x7FFFFE89);
                    }
                    if ((progress > 0.09f) && (func_800DC298(func_800F1214(progress, 0.5f, 1.0f)) != 0)) {
                        count = 0;
                        if (progress < 0.33f) {
                            count = func_800DC298(0.75f);
                        } else if (progress < 0.58f) {
                            count = 2;
                        } else if (progress < 0.88f) {
                            count = 3;
                        }
                        i = 0;
                        if (count > 0) {
                            do {
                                func_800EEB9C(&particle_pos, (func_800DC0C0()) * 360.0f,
                                              func_80103EAC(actor) * 0.7f);
                                func_800EF04C(&particle_pos, bone_pos);
                                func_800BBCB8(&particle_pos, &particle_pos, 1.0f, 1, D_808075C0_chquiz);
                                i += 1;
                            } while (i != count);
                        }
                    }
                    if (((((progress > 0.575f) && (progress < 0.62f)) ||
                          ((progress > 0.69f) && (progress < 0.79f))) ||
                         ((progress > 0.82f) && (progress < 0.86f))) ||
                        ((progress > 0.9f) && (progress < 0.99f))) {
                        func_800BBCB8(bone_pos, bone_pos, 2.5f, 8, D_808075EC_chquiz);
                    }
                    if (func_80101E4C(actor, &unk_1) != 0) {
                        func_80803B88_chquiz(bone_pos);
                    }
                    if (func_80101DDC(actor) != 0) {
                        if (func_800D395C() != 0) {
                            func_80804170_chquiz(actor, 0x2C);

                        } else {
                            func_80804170_chquiz(actor, 0x21);
                        }
                        func_80102424(actor, 1);
                    }

                case 0x4C2:

                case 0x4C3:

                    break;
            }
        }
    }

    void func_808040D4_chquiz(u8 *actor)
    {
        func_80804170_chquiz(actor, *(s32 *) (actor + 0x34) == 15 ? 23 : 24);
    }

    void func_80804110_chquiz(u8 *actor)
    {
        func_80804170_chquiz(actor, *(s32 *) (actor + 0x34) == 15 ? 17 : 18);
    }

    s32 func_8080414C_chquiz(u8 *actor)
    {
        s32 mode;
        s32 result;
        mode = *((s32 *) (((s8 *) actor) + 0x34));
        result = mode == 0xF;
        // Matching: the `* 0` comparison is needed for the match.
        if (result == ((mode == 0xF) * 0)) {
            result = mode == 0x10;
            return result;
        }
    }

    // Matching: the line breaks in this function are needed for the match.
    // Enters a quiz state: runs its entry actions, then stores it in the actor.
    void func_80804170_chquiz(actor, state) Actor *actor;
    s32 state;
    {
        extern u8 D_80807678_chquiz[];
        extern void func_8010D5DC(void);
        extern f32 _suquiz_entrypoint_8(s32);
        extern f32 func_800DC178(f32, f32);
        extern void func_8008F990(void *, f32);

        char *unk_0;

        unk_0 = (char *) func_80100094(actor, 0);
        switch (state) {
            case 1:
                func_80801408_chquiz(actor, unk_0, 9, 0);
                func_80102424(actor, 1);
                func_808014F8_chquiz(1, 1);
                break;

            case 2:
                func_80803B54_chquiz(actor, 0x1460, 4);
                break;

            case 3:
                func_80803B54_chquiz(actor, 0x1461, 4);
                break;

            case 4:
                func_80803B54_chquiz(actor, 0x1463, 4);
                func_8080100C_chquiz(actor, unk_0, 0);
                break;

            case 5:
                func_80803B54_chquiz(actor, 0x1465, 4);
                func_8080100C_chquiz(actor, unk_0, 1);
                break;

            case 6:
                func_80803B54_chquiz(actor, 0x1464, 4);
                func_8080100C_chquiz(actor, unk_0, 2);
                break;

            case 7:
                if (func_800DA298(0x584)) {
                    func_80803B54_chquiz(actor, 0x146A, 0x46);
                } else {
                    func_800DA544(0x584);
                    func_80803B54_chquiz(actor, 0x1466, 4);
                }

                func_80801724_chquiz(unk_0);
                func_8080100C_chquiz(actor, unk_0, 3);
                func_80102424(actor, 1);
                _suquiz_entrypoint_18(1);
                _chintrotext_entrypoint_1(0x1A89, 0, 0, 2);
                break;

            case 8:
                if (func_800DA298(0x585)) {
                    func_80803B54_chquiz(actor, 0x146B, 0x46);
                } else {
                    func_800DA544(0x585);
                    func_80803B54_chquiz(actor, 0x1467, 4);
                }

                func_80801724_chquiz(unk_0);
                func_80102424(actor, 1);
                func_8080100C_chquiz(actor, unk_0, 4);
                _suquiz_entrypoint_18(2);
                _chintrotext_entrypoint_1(0x1A89, 1, 0, 2);
                break;

            case 9:
                func_80102424(actor, 1);
                func_80803B54_chquiz(actor, 0x1462, 4);
                func_8080100C_chquiz(actor, unk_0, 6);
                _suquiz_entrypoint_18(3);
                break;

            case 10:
                if (func_800DA298(0x586)) {
                    func_80803B54_chquiz(actor, 0x146C, 0x46);
                } else {
                    func_800DA544(0x586);
                    func_80803B54_chquiz(actor, 0x1468, 4);
                }

                func_80801724_chquiz(unk_0);
                func_80102424(actor, 1);

                func_8080100C_chquiz(actor, unk_0,
                                     *(s32 *) ((char *) actor + 0x34) == 9 ? 5 : 6);
                _suquiz_entrypoint_18(3);
                _chintrotext_entrypoint_1(0x1A89, 2, 0, 2);
                break;

            case 11:
                if (func_8080154C_chquiz(unk_0)) {
                    if (func_800D3948()) {
                        func_80804170_chquiz(actor, 0x35);
                        return;
                    } else {
                        func_80804170_chquiz(actor, 0x1A);
                        return;
                    }
                }
                func_808008D4_chquiz(actor);
                func_80800A70_chquiz(actor);
                func_80102424(actor, 1);
                switch (func_80800B90_chquiz(func_80800B6C_chquiz(actor))) {
                    case 0:
                        func_80804170_chquiz(actor, 0xD);
                        return;
                    case 1:
                        func_8080100C_chquiz(actor, unk_0, 8);
                        func_80803B54_chquiz(actor, func_800DC128(0x14A1, 0x14A4), 0x46);
                }
                break;

            case 13: {
                s32 unk_1;

                if (actor->unk70_10 != 0xC) {
                    unk_1 = 2;
                } else {
                    unk_1 = 1;
                }

                func_8080100C_chquiz(actor, unk_0, 9);
                func_8080034C_chquiz(actor, 1);
                _suquiz_entrypoint_19(unk_1);
                func_808016F8_chquiz(unk_0, 0, _suquiz_entrypoint_8(unk_1));
                func_80101180(0x529, 0x82, 0);
                break;
            }

            case 15: {
                s32 unk_1;

                unk_1 = _suquiz_entrypoint_6();
                func_8080034C_chquiz(actor, 2);
                func_80801058_chquiz(actor, unk_0, 0.5f, 0, func_80801544_chquiz(unk_1), 1);

                if (!_suquiz_entrypoint_11(unk_1)) {
                    *(f32 *) ((char *) actor + 0x18) = func_800DC178(1.0f, 2.0f);
                    *(u8 *) ((char *) actor + 0x65) &= ~0x10;
                    *(f32 *) ((char *) actor + 0x1C) = 1.0f;
                }

                _suquiz_entrypoint_19(3);
                func_808016F8_chquiz(unk_0, 1, _suquiz_entrypoint_8(3));
                break;
            }

            case 17:
                func_80102424(actor, 2);
                func_800FC660(0xF);
                func_8080100C_chquiz(actor, unk_0, 0xD);

                if (_suquiz_entrypoint_4() == 2) {
                    func_80803B54_chquiz(actor, func_800DC128(0x1485, 0x148B), 0x46);
                    func_8080034C_chquiz(actor, 0);
                } else {
                    func_80803B54_chquiz(actor, func_800DC128(0x1479, 0x147F), 0x46);
                }

                func_808008B0_chquiz(actor);
                func_80801760_chquiz(unk_0, 0x63, _suquiz_entrypoint_6());
                break;

            case 19:
                func_8080100C_chquiz(actor, unk_0, 0xB);

                if (_suquiz_entrypoint_4() == 2) {
                    func_80803B54_chquiz(actor, func_800DC128(0x14B0, 0x14B6), 0x46);
                } else {
                    func_80803B54_chquiz(actor, func_800DC128(0x14AA, 0x14B0), 0x46);
                }
                func_808008B0_chquiz(actor);
                func_80801760_chquiz(unk_0, 0x67, _suquiz_entrypoint_6());
                break;

            case 14:
                func_8080100C_chquiz(actor, unk_0, 0xA);
                func_80101180(0x529, 0x85, _suquiz_entrypoint_6());
                _suquiz_entrypoint_19(4);
                func_80101180(0x529, 0x86, 0);
                func_8080034C_chquiz(actor, 3);
                func_808016F8_chquiz(
                    unk_0,
                    _gcnewoption_entrypoint_47(*(s32 *) ((u8 *) func_80100094(actor, 0) + 0x94)),
                    _suquiz_entrypoint_8(4));
                break;

            case 16: {
                s32 unk_1;

                unk_1 = _suquiz_entrypoint_6();
                func_8080034C_chquiz(actor, 4);
                func_80801058_chquiz(actor, unk_0, 0.5f, 0, func_80801544_chquiz(unk_1), 1);

                if (!_suquiz_entrypoint_11(unk_1)) {
                    *(f32 *) ((char *) actor + 0x18) = func_800DC178(1.0f, 2.0f);
                    *(u8 *) ((char *) actor + 0x65) &= ~0x10;
                    *(f32 *) ((char *) actor + 0x1C) = 2.0f;
                }

                _suquiz_entrypoint_19(5);
                func_808016F8_chquiz(unk_0, 1, _suquiz_entrypoint_8(5));
                break;
            }

            case 18:
                func_80102424(actor, 2);
                func_8080100C_chquiz(actor, unk_0, 0xA);
                func_800FC660(0xF);

                if (_suquiz_entrypoint_4() == 2) {
                    func_80803B54_chquiz(actor, func_800DC128(0x14B6, 0x14BC), 0x46);
                } else {
                    func_80803B54_chquiz(actor, func_800DC128(0x147F, 0x1485), 0x46);
                }

                func_808008B0_chquiz(actor);
                func_8080034C_chquiz(actor, 0);
                func_80801760_chquiz(unk_0, 0x64, _suquiz_entrypoint_6());
                break;

            case 20:
                func_8080100C_chquiz(actor, unk_0, 0xB);
                func_80803B54_chquiz(actor, func_800DC128(0x14DA, 0x14E0), 0x46);
                func_808008B0_chquiz(actor);
                func_80801760_chquiz(unk_0, 0x68, _suquiz_entrypoint_6());
                func_8080034C_chquiz(actor, 0);
                break;

            case 22:
                func_8080100C_chquiz(actor, unk_0, 0xC);

                if (_suquiz_entrypoint_4() == 2) {
                    func_80803B54_chquiz(actor, func_800DC128(0x14BC, 0x14C2), 0x46);
                } else {
                    func_80803B54_chquiz(actor, func_800DC128(0x146D, 0x1473), 0x46);
                }
                func_8080034C_chquiz(actor, 0);
                break;

            case 21:
                func_8080100C_chquiz(actor, unk_0, 0x11);
                func_80803B54_chquiz(actor, func_800DC128(0x149A, 0x14A0), 0x46);
                func_8080034C_chquiz(actor, 0);
                break;

            case 23:
                func_80102424(actor, 3);
                func_800FC660(0xE);
                func_808008B0_chquiz(actor);
                func_8080100C_chquiz(actor, unk_0, 0xF);
                func_80803B54_chquiz(actor, func_800DC128(0x1473, 0x1479), 0x46);
                func_8080034C_chquiz(actor, 0);
                func_80801760_chquiz(unk_0, 0x65, _suquiz_entrypoint_6());
                break;

            case 24:
                func_80102424(actor, 3);
                func_800FC660(0xE);
                func_808008B0_chquiz(actor);
                func_8080100C_chquiz(actor, unk_0, 0x10);
                func_80803B54_chquiz(actor, func_800DC128(0x14A4, 0x14AA), 0x46);
                func_8080034C_chquiz(actor, 0);
                func_80801760_chquiz(unk_0, 0x66, _suquiz_entrypoint_6());
                break;

            case 25:
                func_80102424(actor, 1);

                func_80101180(0x529, 0x84, _suquiz_entrypoint_6());

                func_80101180(0x52E, 0x8C, _suquiz_entrypoint_6());

                func_80801058_chquiz(actor, unk_0, 1.0f, 0,
                                     func_80801544_chquiz(_suquiz_entrypoint_6()), 0);

                *(f32 *) ((char *) actor + 0x18) = 2.0f;
                break;

            case 26: {
                s32 text_id = 0;
                s32 candidates[3];
                s32 candidate_count;

                func_80101180(0x529, 0x3B, 0);
                func_8080100C_chquiz(actor, unk_0, 0x12);
                if (_suquiz_entrypoint_4() == 2) {
                    func_80804170_chquiz(actor, 0x1F);
                    if (func_80801784_chquiz(unk_0, 2) < 0xF) {
                        text_id = 0x1491;
                    } else {
                        func_808014F8_chquiz(1, 1);
                        text_id = 0x1492;
                    }
                    func_80803B54_chquiz(actor, text_id, 0x4E);
                    actor->unk6C_0 = 2;
                    return;
                }
                candidate_count = func_80801930_chquiz(unk_0, candidates);
                if (candidate_count == 1) {
                    actor->unk6C_0 = candidates[0];
                    switch (actor->unk6C_0) {
                        case 1:
                            text_id = _suquiz_entrypoint_4() == 0 ? 0x148D : 0x1490;
                            break;
                        case 0:
                            text_id = _suquiz_entrypoint_4() == 0 ? 0x148B : 0x148E;
                            break;
                        case 2:
                            text_id = _suquiz_entrypoint_4() == 0 ? 0x148C : 0x148F;
                    }
                } else {
                    text_id = _suquiz_entrypoint_4() == 0 ? 0x14C7 : 0x14C8;
                    actor->unk6C_0 = candidates[func_800DC128(0, candidate_count)];
                }
                func_80803B54_chquiz(actor, text_id, 0x46);
                break;
            }

            case 27:
                func_8080100C_chquiz(actor, unk_0, 0x13);
                break;

            case 28:
                func_80101180(0x529, 0x87, actor->unk6C_0);
                _suquiz_entrypoint_20(actor->unk6C_0);
                break;

            case 29:
                *(f32 *) ((char *) actor + 0x18) = 2.0f;
                break;

            case 30:
                func_8080100C_chquiz(actor, unk_0, 0x14);
                func_80102424(actor, 4);
                break;

            case 32:
                func_80102424(actor, 6);
                func_8080100C_chquiz(actor, unk_0, 0x19);
                break;

            case 33:
                _suquiz_entrypoint_18(4);
                _suquiz_entrypoint_2();
                func_80101180(0x4CD, 7, 0);

                func_80801408_chquiz(actor, func_80100094(actor, 0), 0x13, 0x10);

                *(u8 *) ((char *) actor + 0x65) &= ~1;
                break;

            case 34:
                func_80101180(0x529, 0x8A, 2);

                func_80801058_chquiz(actor, unk_0, 1.5f, 0, 9, 1);

                _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x14A0, 0xC,
                                              (char *) actor + 4, 0xC);
                break;

            case 35:
                func_8008F8B0();
                func_8008F8D8(1);
                func_8008F990(D_80807678_chquiz, 500.0f);
                func_8008F904(func_8010D5DC, *(s32 *) ((char *) actor + 0));

                func_80801408_chquiz(actor, unk_0, 0x15, 0x40);

                *(f32 *) ((char *) actor + 0x18) = 0.3f;
                break;

            case 36:
                func_80801058_chquiz(actor, unk_0, 2.5f,
                                     _glglobalsettings_entrypoint_3() ? 2 : 0, 7, 1);
                func_808014F8_chquiz(0, 1);
                break;

            case 37:
                _gcgoto_entrypoint_2(0x19C, 0, 0);
                break;

            case 38:
                _suquiz_entrypoint_18(1);
                func_8080100C_chquiz(actor, unk_0, 0x21);
                func_80803B54_chquiz(actor, 0x14CC, 0x46);
                break;

            case 39:
                _suquiz_entrypoint_18(2);
                func_8080100C_chquiz(actor, unk_0, 0x22);
                func_80803B54_chquiz(actor, 0x14CD, 0x46);
                break;

            case 40:
                _suquiz_entrypoint_18(3);
                func_8080100C_chquiz(actor, unk_0, 0x23);
                func_80803B54_chquiz(actor, 0x14CE, 0x46);
                break;

            case 41:
                func_80801724_chquiz(unk_0);
                func_8080100C_chquiz(actor, unk_0, 3);
                func_80803B54_chquiz(actor, 0x14D3, 0x46);
                break;

            case 42:
                func_80801724_chquiz(unk_0);
                func_8080100C_chquiz(actor, unk_0, 3);
                func_80803B54_chquiz(actor, 0x14D4, 0x46);
                break;

            case 43:
                func_80801724_chquiz(unk_0);
                func_8080100C_chquiz(actor, unk_0, 3);
                func_80803B54_chquiz(actor, 0x14D5, 0x46);
                break;

            case 44:
                func_8080100C_chquiz(actor, unk_0, 0x24);
                func_80803B54_chquiz(actor, 0x14CF, 0x46);
                break;

            case 45:
                func_8080100C_chquiz(actor, unk_0, 0x25);
                func_80803B54_chquiz(actor, 0x14D0, 0x46);
                break;

            case 46:
                func_8080100C_chquiz(actor, unk_0, 0x1A);
                func_80803B54_chquiz(actor, 0x1469, 0x46);
                break;

            case 47:
                func_8080100C_chquiz(actor, unk_0, 0x1B);
                func_80803B54_chquiz(actor, 0x14D6, 0x46);
                break;

            case 48:
                func_8080100C_chquiz(actor, unk_0, 0x1C);
                func_80803B54_chquiz(actor, 0x14C2, 0x46);
                break;

            case 49:
                func_8080100C_chquiz(actor, unk_0, 0x1D);
                func_80803B54_chquiz(actor, 0x14C3, 0x46);
                break;

            case 50:
                func_8080100C_chquiz(actor, unk_0, 0x1E);
                func_80803B54_chquiz(actor, 0x14C4, 0x46);
                break;

            case 51:
                func_8080100C_chquiz(actor, unk_0, 0x1F);
                func_80803B54_chquiz(actor, 0x14C5, 0x46);
                break;

            case 52:
                func_8080100C_chquiz(actor, unk_0, 0x1B);
                func_80803B54_chquiz(
                    actor, (f32) _gcstatusDll_entrypoint_17() == 0.0f ? 0x14C6 : 0x14D9, 0x46);
                break;

            case 53: {
                s32 text_id;
                s32 candidate_count;
                s32 candidates[3];
                s32 pick;

                func_8080100C_chquiz(actor, unk_0, 0x1A);
                if ((f32) _gcstatusDll_entrypoint_17() != 0.0f) {
                    candidate_count = func_80801A54_chquiz(unk_0, candidates);
                    if (candidate_count == 1) {
                        actor->unk6C_0 = candidates[0];
                        text_id = 0x1493;
                    } else {
                        text_id = 0x1495;
                        pick = func_800DC128(0, candidate_count);
                        actor->unk6C_0 = candidates[pick];
                    }
                } else {
                    actor->unk6C_0 = func_80801C08_chquiz(unk_0, _gcstatusDll_entrypoint_18());
                    text_id = 0x1494;
                }
                func_80801758_chquiz(unk_0, actor->unk6C_0);
                func_80803B54_chquiz(actor, text_id, 0x46);
                func_800FC660(0x10);
                break;
            }

            case 54:
                func_8080100C_chquiz(actor, unk_0, 0x13);
                break;

            case 55:
                func_80101180(0x529, 0x87, actor->unk6C_0);
        }

        *(s32 *) ((char *) actor + 0x34) = state;
    }

    int func_808053BC_chquiz(actor)
    Actor *actor;
    {
        u8 *unk_0;

        unk_0 = func_80100094(actor, 0);
        func_8010A828(actor, 9);
        *(u8 *) ((char *) unk_0 + 0x98) = 0;
        _suquiz_entrypoint_0();
        func_80800C24_chquiz(actor);
    }

    // Matching: the line breaks in this function are needed for the match.
    void func_80805404_chquiz(actor) Actor *actor;
    {
        Actor *unk_0;
        s32 unk_1;
        s32 unk_2;

        unk_0 = func_80100094(actor, 0);
        switch (actor->actorData[7]) {
            case 1:
                if (_capod_entrypoint_17(0.095f)) {
                    func_80804170_chquiz(actor, 2);
                }
                break;
            case 0xB:
                func_80801794_chquiz(unk_0);
                break;
            case 0xC:
                if (func_808013E0_chquiz(actor, unk_0)) {
                    func_80800CE8_chquiz(actor, &unk_2, &unk_1);
                    _suquiz_entrypoint_19(0);
                    _suquiz_entrypoint_22((u8 *) unk_0 + 0x38, (u8 *) unk_0 + 0x44);
                    _suquiz_entrypoint_24(unk_2, unk_1);
                }
                func_80801794_chquiz(unk_0);
                break;
            case 0xD:
                if (_suquiz_entrypoint_4() == 2 && func_80016B54(0, 0) &&
                    func_8080171C_chquiz(unk_0)) {
                    func_80804170_chquiz(actor, 0x15);
                }
                if (func_80801600_chquiz(unk_0)) {
                    func_80804170_chquiz(actor, 0x16);
                }
                func_80801794_chquiz(unk_0);
                break;
            case 0xE:
                if (func_80801600_chquiz(unk_0)) {
                    func_80804170_chquiz(actor, 0x16);
                }
                func_80801794_chquiz(unk_0);
                break;
            case 0xF:
            case 0x10:
                if (_suquiz_entrypoint_4() == 2) {
                    if (func_80016B54(0, 0)) {
                        func_80804170_chquiz(actor, 0x15);
                    }
                } else if (!_suquiz_entrypoint_11(_suquiz_entrypoint_6()) &&
                           func_800D90A4(&actor->actorData[0])) {
                    if (!actor->unk64_20) {
                        func_80800728_chquiz(actor, _suquiz_entrypoint_6());
                        actor->unk64_20 = 1;
                    } else if (func_800D90A4(&actor->actorData[1])) {
                        func_8080085C_chquiz(actor);
                    }
                }
                if (func_80801600_chquiz(unk_0)) {
                    func_80804170_chquiz(actor, actor->actorData[7] == 0x10 ? 0x14 : 0x13);
                }
                func_80801794_chquiz(unk_0);
                break;
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x16:
                func_80801794_chquiz(unk_0);
                break;
            case 0x17:
            case 0x18:
                if (func_80101DDC(actor)) {
                    func_80804170_chquiz(actor, 0x19);
                }
                func_80801794_chquiz(unk_0);
                break;
            case 0x19:
                func_80801794_chquiz(unk_0);
                break;
            case 0x1A:
                func_80801794_chquiz(unk_0);
                break;
            case 0x1B:
                if (func_808013E0_chquiz(actor, unk_0)) {
                    func_80804170_chquiz(actor, 0x1C);
                    func_80801794_chquiz(unk_0);
                }
                break;
            case 0x1D:
                if (actor->unk6C_0 != 2 && func_800D90A4(&actor->actorData[0])) {
                    if (func_800D395C()) {
                        func_80804170_chquiz(actor, 0x2C);
                    } else {
                        switch (_suquiz_entrypoint_4()) {
                            case 2:
                                break;
                            case 0:
                                func_80804170_chquiz(actor, 8);
                                break;
                            case 1:
                                func_80804170_chquiz(actor, func_800DA298(0x586) ? 0xA : 9);
                        }
                    }
                }
                break;
            case 0x1E:
                if (func_80101DDC(actor)) {
                    func_80804170_chquiz(actor, 0x1F);
                }
                break;
            case 0x23:
                if (func_800D90A4(&actor->actorData[0])) {
                    func_80801C7C_chquiz(2);
                    *(f32 *) &actor->actorData[0] = 10000.0f;
                }
                break;
            case 0x24:
                if (func_808013E0_chquiz(actor, unk_0)) {
                    func_80804170_chquiz(actor, 0x25);
                }
                break;
            case 0x36:
                if (func_808013E0_chquiz(actor, unk_0)) {
                    func_80804170_chquiz(actor, 0x37);
                }
            case 0x37:
                break;
        }
        if (func_800D3948()) {
            func_801039E4(actor->unk0);
        }
        _suquiz_entrypoint_1();
        func_80801170_chquiz(actor, unk_0);
        func_80800298_chquiz(actor);
        func_80803BFC_chquiz(actor);
        if (((QuizExpressionFlag481 *) actor)->local_0) {
            _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
        }
    }

    void func_80805878_chquiz(actor) Actor *actor;
    {
        if (((QuizActorFlags *) actor)->local_0) {
            func_80800FBC_chquiz(actor);
            func_808008D4_chquiz(actor);
            if (func_80100094(actor, 1))
                _suexpression_entrypoint_8(actor, 1);
            if (!_suquiz_entrypoint_17())
                _suquiz_entrypoint_2();
        }
    }

    // Message handler of the quiz master actor.
    s32 func_808058F0_chquiz(Actor *actor, s32 msg, s32 msg_arg)
    {
        extern f32 _suquiz_entrypoint_8(s32);
        typedef struct {
            u16 local_0;
        } QuizCharacterEntry;

        char *quiz;
        s32 dialog_id;
        s32 i;
        s16 *arg_halves;

        quiz = (char *) func_80100094(actor, 0);
        // msg_arg carries two packed s16 values.
        arg_halves = (s16 *) &msg_arg;

        switch (msg) {
            case 0x95:
                func_80800F34_chquiz(actor, quiz);

                switch (_suquiz_entrypoint_3()) {
                    case 5:
                        if (_suquiz_entrypoint_5()) {
                            if (_suquiz_entrypoint_6() == 8) {
                                func_80804170_chquiz(actor, 0x15);
                                return 1;
                            }

                            func_80101180(0x529, 0x89, 0);

                            func_808016F8_chquiz(quiz, 1, _suquiz_entrypoint_8(1));

                            func_80804170_chquiz(actor, 0xF);
                        } else {
                            func_80804170_chquiz(actor, 0xD);
                            _suquiz_entrypoint_19(1);
                        }

                        return 1;
                    case 0:
                        if (func_800D395C()) {
                            switch (func_800D3D04()) {
                                case 0x74:
                                    func_80804170_chquiz(actor, 0x26);
                                    break;
                                case 0x75:
                                    func_80804170_chquiz(actor, 0x27);
                                    break;
                                case 0x76:
                                    func_80804170_chquiz(actor, 0x28);
                            }
                            return 1;
                        }

                        if (func_800D3948()) {
                            func_80804170_chquiz(actor, 0x2E);
                        } else {
                            func_80804170_chquiz(actor, 1);
                        }
                        return 1;

                    case 1:
                        func_80804170_chquiz(actor, 7);
                        return 1;

                    case 2:
                        func_80804170_chquiz(actor, 8);
                        return 1;

                    case 3:
                        func_80804170_chquiz(actor, 0xA);
                }
                return 1;

            case 0x30:
                switch (arg_halves[0]) {
                    case 0x148B:
                    case 0x148C:
                    case 0x148D:
                        return func_80801B7C_chquiz(quiz);

                    case 0x14C6:
                        return _gcstatusDll_entrypoint_18();

                    case 0x14D9:
                        return _gcstatusDll_entrypoint_17();
                    case 0x1493:
                        if (((s16 *) &msg_arg)[1] != 0) {
                            return func_80801784_chquiz(quiz, actor->unk6C_0);
                        }

                        return _gcstatusDll_entrypoint_17();

                    case 0x1494:
                        return _gcstatusDll_entrypoint_18();
                }
                return 0;

            case 0x2F:
                switch (arg_halves[1]) {
                    case 1:
                        func_80804170_chquiz(actor, 0x1E);
                        return 1;

                    case 2:
                        func_8080100C_chquiz(actor, quiz, 0x15);
                        return 1;

                    case 3:
                        func_8080100C_chquiz(actor, quiz, 0x16);
                        return 1;

                    case 4:
                        func_8080100C_chquiz(actor, quiz, 0x17);
                        return 1;

                    case 5:
                        func_8080100C_chquiz(actor, quiz, 0x18);
                        return 1;

                    case 6:
                        func_80804170_chquiz(actor, 0x20);
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
                switch (arg_halves[0]) {
                    case 0x1461:
                        func_80801470_chquiz(actor, quiz);
                    case 0x1460:
                    case 0x1463:
                    case 0x1465:
                        func_80804170_chquiz(actor, *(s32 *) ((char *) actor + 0x34) + 1);
                        return 1;

                    case 0x1464:
                        func_808014F8_chquiz(0, 1);
                        func_80804170_chquiz(actor, 7);
                        return 1;

                    case 0x1466:
                    case 0x146A:
                        _suquiz_entrypoint_23();
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x1467:
                    case 0x146B:
                        _suquiz_entrypoint_23();
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x1468:
                    case 0x146C:
                        _suquiz_entrypoint_23();
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x1479:
                    case 0x147A:
                    case 0x147B:
                    case 0x147C:
                    case 0x147D:
                    case 0x147E:
                        func_80804170_chquiz(actor, 0xE);
                        return 1;

                    case 0x147F:
                    case 0x1480:
                    case 0x1481:
                    case 0x1482:
                    case 0x1483:
                    case 0x1484:
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x1473:
                    case 0x1474:
                    case 0x1475:
                    case 0x1476:
                    case 0x1477:
                    case 0x1478:
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x14A4:
                    case 0x14A5:
                    case 0x14A6:
                    case 0x14A7:
                    case 0x14A8:
                    case 0x14A9:
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x146D:
                    case 0x146E:
                    case 0x146F:
                    case 0x1470:
                    case 0x1471:
                    case 0x1472:
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x14BC:
                    case 0x14BD:
                    case 0x14BE:
                    case 0x14BF:
                    case 0x14C0:
                    case 0x14C1:
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x14A1:
                    case 0x14A2:
                    case 0x14A3:
                        func_80804170_chquiz(actor, 0xC);
                        return 1;

                    case 0x14AA:
                    case 0x14AB:
                    case 0x14AC:
                    case 0x14AD:
                    case 0x14AE:
                    case 0x14AF:
                        func_80804170_chquiz(actor, 0xE);
                        return 1;

                    case 0x14DA:
                    case 0x14DB:
                    case 0x14DC:
                    case 0x14DD:
                    case 0x14DE:
                    case 0x14DF:
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x14B0:
                    case 0x14B1:
                    case 0x14B2:
                    case 0x14B3:
                    case 0x14B4:
                    case 0x14B5:
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x148B:
                    case 0x148C:
                    case 0x148D:
                    case 0x148E:
                    case 0x148F:
                    case 0x1490:
                    case 0x1491:
                        func_80804170_chquiz(actor, 0x1B);
                        return 1;

                    case 0x1462:
                        func_80804170_chquiz(actor, 0xA);
                        return 1;

                    case 0x149A:
                    case 0x149B:
                    case 0x149C:
                    case 0x149D:
                    case 0x149E:
                    case 0x149F:
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x1485:
                    case 0x1486:
                    case 0x1487:
                    case 0x1488:
                    case 0x1489:
                    case 0x148A:
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x14C7:
                    case 0x14C8:
                        switch (actor->unk6C_0) {
                            case 0:
                                func_80803B54_chquiz(actor, 0x14C9, 0x46);
                                break;
                            case 1:
                                func_80803B54_chquiz(actor, 0x14CA, 0x46);
                                break;
                            case 2:
                                func_80803B54_chquiz(actor, 0x14CB, 0x46);
                        }
                        return 1;

                    case 0x14C9:
                    case 0x14CA:
                    case 0x14CB:
                        func_80804170_chquiz(actor, 0x1B);
                        return 1;

                    case 0x14CC:
                        if (arg_halves[1] != 0) {
                            func_80804170_chquiz(actor, 3);
                        } else {
                            func_80804170_chquiz(actor, 0x29);
                        }
                        return 1;

                    case 0x14CD:
                        if (arg_halves[1] != 0) {
                            func_80803B54_chquiz(actor, 0x14D1, 0x46);
                        } else {
                            func_80804170_chquiz(actor, 0x2A);
                        }
                        return 1;

                    case 0x14CE:
                        if (arg_halves[1] != 0) {
                            func_80803B54_chquiz(actor, 0x14D2, 0x46);
                        } else {
                            func_80804170_chquiz(actor, 0x2B);
                        }
                        return 1;

                    case 0x14D1:
                        func_80804170_chquiz(actor, 0x2A);
                        return 1;

                    case 0x14D2:
                        func_80804170_chquiz(actor, 0x2B);
                        return 1;

                    case 0x14D3:
                    case 0x14D4:
                    case 0x14D5:
                        _suquiz_entrypoint_23();
                        func_80804170_chquiz(actor, 0xB);
                        return 1;
                    case 0x14CF:
                    case 0x14D0:
                        if (arg_halves[1] != 0) {
                            _gcfrontend_entrypoint_11();
                        } else {
                            _gcfrontend_entrypoint_10();
                        }
                        return 1;

                    case 0x1469:
                        if (arg_halves[1] != 0) {
                            func_80804170_chquiz(actor, 0x2F);
                        } else {
                            func_80804170_chquiz(actor, 0x34);
                        }
                        return 1;

                    case 0x14C2:
                    case 0x14C3:
                    case 0x14C4:
                    case 0x14C5:
                    case 0x14D6:
                        func_80804170_chquiz(actor, *(s32 *) ((char *) actor + 0x34) + 1);
                        return 1;

                    case 0x14C6:
                    case 0x14D9:
                        _suquiz_entrypoint_23();
                        func_80804170_chquiz(actor, 0xB);
                        return 1;

                    case 0x1496:
                    case 0x1497:
                    case 0x1498:
                    case 0x1499:
                        func_80804170_chquiz(actor, 0x36);
                        return 1;

                    case 0x1493:
                    case 0x1494:
                    case 0x1495:
                        switch (actor->unk6C_0) {
                            case 3:
                                dialog_id = 0x1498;
                                break;
                            case 4:
                                dialog_id = 0x1497;
                                break;
                            case 5:
                                dialog_id = 0x1496;
                                break;
                            case 6:
                                dialog_id = 0x1499;
                                break;
                        }
                        func_80803B54_chquiz(actor, dialog_id, 0x46);
                        return 1;

                    case 0x14A0:
                        func_80804170_chquiz(actor, 0x23);
                        return 1;
                }
                return 1;

            case 0xB:
                func_80801470_chquiz(actor, quiz);

                if (msg_arg == 0x13) {
                    func_80804170_chquiz(actor, 0x22);
                } else if (msg_arg == 0x15) {
                    func_80804170_chquiz(actor, 0x24);
                }

                return 4;

            case 0x20:
                func_808005C0_chquiz(actor, arg_halves[0], arg_halves[1]);
                return 1;

            case 0x83:
                if (*(s32 *) ((char *) actor + 0x34) == 0xD ||
                    *(s32 *) ((char *) actor + 0x34) == 0xE) {
                    func_80804170_chquiz(actor,
                                         *(s32 *) ((char *) actor + 0x34) == 0xD ? 0xF : 0x10);
                    return 1;
                }

                return 0;

            case 0x88:
                if (func_800D395C() && ((actor->unk6C_0) == 2)) {
                    func_80804170_chquiz(actor, 0x2D);
                    return 1;
                }

                if (func_800D3948()) {
                    if (*(s32 *) ((char *) actor + 0x34) != 0x38) {
                        i = 3;

                        do {
                            func_800AA20C(i - 3, func_80801784_chquiz(quiz, i));

                            i++;
                        } while (i != 7);

                        _gcfrontend_entrypoint_10();
                        *(s32 *) ((char *) actor + 0x34) = 0x38;
                    }

                } else {
                    func_80804170_chquiz(actor, 0x1D);
                }
                return 1;

            case 0x6C:
                if (!func_800D3948() && func_800DA298(0x6B6)) {
                    func_80801058_chquiz(actor, quiz, 0.5f, 0,
                                         func_80801544_chquiz(actor->unk6C_0), 1);
                }

                return 1;

            case 0x1F:
                func_801015D0(actor);

                switch (D_80807528_chquiz[actor->unk70_10].id) {
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
                _suexpression_entrypoint_7(actor, 1, 0x4D);
                return 1;

            case 0x2A:
                _suexpression_entrypoint_8(actor, 1);
                return 1;

            case 0x32:
                func_800F82D4(func_800F54E4(), 2);
                return 1;
        }

        return 0;
    }

    s32 func_808064F4_chquiz(actor, gfx)
    Actor *actor;
    s32 gfx;
    {
        // Matching: the empty do/while is needed for the match.
        do {
        } while (0);
        if (func_800EB854(actor) == 0) {
            func_801018A4(actor, gfx);
        } else {
            func_808002F0_chquiz(actor, gfx);
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
