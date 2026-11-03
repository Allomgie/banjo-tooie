#include "ch/introtext.h"

extern u32 D_808007D0_chintrotext[];
typedef struct {
    s16 count;
    u8 pad_0[0x14];
    s16 starts[9];
    s16 styles[9];
} IntroText30;
extern void _fxkern_entrypoint_3(f32);
typedef struct {
    f32 local_0[4];
} local_struct;
extern local_struct D_808007A4_chintrotext[];
extern local_struct D_808007A8_chintrotext[];
extern void _chbaddiesetup_entrypoint_4(void *param_0, s32 param_1, s32 param_2, s32 param_3,
                                        s32 param_4);
extern int func_800A9C98(void);
extern void *_chintrotext_entrypoint_3;
typedef struct {
    u8 pad_0[0x3E];
    u8 local_0;
    u8 local_1;
} IntroTextPlacement;
extern void func_800EFD24(f32 *);
extern Actor *func_80108474(u32, f32 *, s32);
extern void *func_80100094(Actor *, u32);
extern void *func_80100074(Actor *, u32, u32);
extern char *_gldbstring_entrypoint_1();
extern s32 func_800E7188();
extern void func_800E715C();
extern void _gldbstring_entrypoint_2(s32);
typedef struct {
    s16 local_0;
    s16 local_1[30];
    u8 local_2;
    u8 local_3;
} IntroTextState;
typedef struct {
    f32 local_0, local_1, local_2;
    s32 local_3;
} IntroTextTiming;
extern IntroTextTiming D_808007A0_chintrotext[];
extern void func_80105834(), func_80107C2C(), func_8080000C_chintrotext(),
    func_80800130_chintrotext(), func_808003EC_chintrotext();

int chintrotext_entrypoint_0()
{
    return (int) &D_808007D0_chintrotext;
}

void func_8080000C_chintrotext(param_0) Actor *param_0;
{
    IntroText30 *local_1;
    u8 *local_0;
    s32 local_2;
    s32 local_3;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_80100094(param_0, 1);
    local_1->starts[0] = 0;
    local_1->count = 1;
    local_1->styles[1] = 0xC26;
    for (local_2 = 0; local_0[local_2]; local_2++) {
        if (local_0[local_2] == '#') {
            for (local_3 = local_2 + 1; local_0[local_3]; local_3++)
                local_0[local_3 - 1] = local_0[local_3];
            local_0[local_3 - 1] = 0;
            local_1->styles[local_1->count] = 0xC25;
        }
        if (local_0[local_2] == '\n') {
            local_1->starts[local_1->count] = local_2 + 1;
            local_1->styles[local_1->count + 1] = 0xC26;
            local_1->count++;
            local_0[local_2] = 0;
            if (local_1->count == 9)
                break;
        }
    }
    func_800DA544(0x6AD);
}

void func_80800130_chintrotext(s32 arg0)
{
    func_800DA524(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
}

void func_8080051C_chintrotext();

void func_80800154_chintrotext(Actor *param_0)
{
    extern u8 func_800D9078(f32 *);
    extern f32 func_800F12D4(f32, f32, f32, f32, f32);
    IntroTextState *local_0;
    s32 local_1;
    s32 local_2;
    IntroTextState *local_3;
    s32 local_6;
    s32 local_4;
    s32 local_5;
    local_0 = (IntroTextState *) func_80100094(param_0, 1);
    local_1 = func_800D9078(&param_0->unk58);
    local_2 = D_808007A0_chintrotext[local_0->local_3].local_3;
    switch (param_0->unk70_10) {
        case 1:
            local_3 = (IntroTextState *) func_80100094(param_0, 1);
            local_6 = local_3->local_2;
            switch (local_6) {
                case 0:
                    local_4 = (228 - local_3->local_0 * local_2) >> 1;
                    local_4 += 2.5f * local_2;
                    break;
                case 1:
                    local_4 = (114 - local_3->local_0 * local_2) >> 1;
                    break;
                case 2:
                    local_4 = (228 - local_3->local_0 * local_2) >> 1;
                    break;
                default:;
            }
            for (local_5 = 0; local_5 < local_3->local_0; local_5++) {
                local_3->local_1[local_5] = local_4 + local_5 * local_2;
            }
            func_8080051C_chintrotext(param_0, 2);
            break;
        case 2:
            func_800DA544(0x6AD);
            if (!func_800C954C()) {
                func_8080051C_chintrotext(param_0, 3);
            }
            break;
        case 3:
            func_800DA544(0x6AD);
            _subaddiefade_entrypoint_1(
                param_0,
                (s32) func_800F12D4(param_0->unk58, 0.0f,
                                    D_808007A0_chintrotext[local_0->local_3].local_0, 255.0f, 0));
            if (local_1) {
                func_8080051C_chintrotext(param_0, 4);
            }
            break;
        case 4:
            func_800DA544(0x6AD);
            if (local_1) {
                func_8080051C_chintrotext(param_0, 5);
            }
            break;
        case 5:
            _subaddiefade_entrypoint_1(
                param_0, (s32) func_800F12D4(param_0->unk58, 0,
                                             D_808007A0_chintrotext[local_0->local_3].local_2, 0.0f,
                                             255.0f));
            if (local_1) {
                func_800FFAB0(param_0);
            }
    }
}

void func_808003EC_chintrotext(param_0, param_1) Actor *param_0;
s32 param_1;
{
    s16 *local_0;
    s16 *local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 1);
    if ((s32) param_0->unk70_10 >= 3 && func_800A819C()) {
        _fxkern_entrypoint_2();
        func_800B8C8C(_subaddiefade_entrypoint_0(param_0));
        for (local_2 = 0, local_1 = local_0; local_2 < *local_0; local_2++, local_1++) {
            func_800B8CE0(local_1[21]);
            _fxkern_entrypoint_3(local_1[21] == 0xC25 ? 0.75f : 1.0f);
            _fxkern_entrypoint_1(param_1, local_1[1],
                                 func_800E71B8((u8 *) func_80100094(param_0, 0) + local_1[11]));
        }
    }
}

void func_8080051C_chintrotext(Actor *param_0, s32 param_1)
{
    s32 local_0;

    local_0 = func_80100094(param_0, 1);
    func_80101FDC(param_0, param_1);
    switch (param_1) {
        case 2:
            _subaddiefade_entrypoint_1(param_0, 0, param_1);
            func_800DA544(0x6AD);
            return;
        case 3:
            param_0->unk58 =
                ((local_struct *) D_808007A0_chintrotext)[*(u8 *) (local_0 + 0x3F)].local_0[0];
            return;
        case 4:
            param_0->unk58 = D_808007A4_chintrotext[*(u8 *) (local_0 + 0x3F)].local_0[0];
            return;
        case 5:
            func_800DA524(0x6AD);
            param_0->unk58 = D_808007A8_chintrotext[*(u8 *) (local_0 + 0x3F)].local_0[0];
    }
}

int chintrotext_entrypoint_1(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    if (!func_800A9C98()) {
        _chbaddiesetup_entrypoint_4(&_chintrotext_entrypoint_3, param_0, param_1, param_3, param_2);
    }
}

s32 chintrotext_entrypoint_2(s32 param_0)
{
    s32 sp24;
    s32 sp20;
    s32 temp_v0;

    temp_v0 = _gcintrotext_entrypoint_2(-1, &sp24, &sp20);
    if ((temp_v0 != -1) && ((param_0 != 0) || (temp_v0 > 0))) {
        chintrotext_entrypoint_1(sp24, sp20, 0, 0);
        return 1;
    }
    return 0;
}

void chintrotext_entrypoint_3(param_0, param_1, param_2, param_3) s32 param_0;
s16 param_1;
s32 param_2;
s32 param_3;
{
    f32 local_0[3];
    Actor *local_1;
    IntroTextPlacement *local_2;
    char *local_3;

    func_800EFD24(local_0);
    local_1 = func_80108474(0x3B0, local_0, 0);
    if (local_1) {
        local_2 = func_80100094(local_1, 1);
        local_3 = _gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0, param_0), param_1);
        func_80100074(local_1, 0, func_800E7188(local_3) + 1);
        func_800E715C(func_80100094(local_1, 0), local_3);
        _gldbstring_entrypoint_2(param_0);
        local_2->local_0 = param_2;
        local_2->local_1 = param_3;
    }
}

IntroTextTiming D_808007A0_chintrotext[3] = {0.4f, 2.4f, 0.6f, 0x19, 0.4f, 2.4f,
                                             0.6f, 0x19, 2.5f, 3.5f, 2.5f, 0x14};
u32 D_808007D0_chintrotext[20] = {0x31503B0,
                                  0xFFFF0001,
                                  0x0,
                                  (u32) func_80800154_chintrotext,
                                  (u32) func_80105834,
                                  (u32) func_808003EC_chintrotext,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x8400404,
                                  (u32) func_80800130_chintrotext,
                                  0x0,
                                  0x40,
                                  (u32) func_8080000C_chintrotext,
                                  (u32) func_80107C2C,
                                  0x80000002,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0};
