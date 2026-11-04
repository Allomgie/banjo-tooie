// Data-driven character actor for the story cutscenes: a per-subtype table sets model, animation,
// blink and expression; plays an/seq sequences with sound cues, shadows and texture scrolling.
#include "common.h"

typedef struct {
    u8 pad_0[0xC6];
    s16 local_0;
} IntroExpressionBuffer1506;
extern u8 D_80804790_chintrochar[];
extern void *func_80100094(Actor *, u32);
extern void _suexpression_entrypoint_7();
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _suexpression_entrypoint_3();
extern void _suexpression_entrypoint_6();
extern void _suexpression_entrypoint_5(void *, s32);
extern s16 func_8001B668(s32, s32);
extern void *func_8001B798();
typedef struct {
    u8 pad[0x7B];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS123;
typedef struct {
    u8 pad[0x70];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS112;
typedef struct {
    u8 pad[0x71];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS113;
typedef struct {
    u8 pad[0x94];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS148;
typedef struct {
    u32 flags;
    u8 pad_0[0x1C];
} IntroActorFlags;
extern IntroActorFlags func_80804158_chintrochar[];
extern u8 func_80804160_chintrochar[];
extern void func_80105BE0(Actor *, s32);
extern void func_800ADFE0();
extern void _chanim_entrypoint_6(Actor *);
extern void _anseq_entrypoint_5();
extern void _chblink_entrypoint_3();
extern void func_8001B754();
typedef struct {
    u8 pad_0[0xCC];
    s32 local_0;
} IntroContactState;
typedef struct {
    u8 pad_0[8];
    void *local_0;
} IntroContact;
extern void func_800EE7F8(f32 *, f32 *);
extern IntroContact *func_800C6A7C(f32 *, f32 *, f32 *, void *);
extern s32 func_800C84B0(void *);
typedef struct {
    u8 pad[0xCC];
    s32 step;
} IntroCharacterStep;
extern u8 D_808052F8_chintrochar[];
extern void func_800C4B64(f32);
extern void func_800C4B70(s32);
extern void func_800C4B7C(s32);
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
extern u8 func_8080416C_chintrochar[];
extern u8 D_80805308_chintrochar[];
extern u8 D_80805310_chintrochar[];
extern void func_800E0AFC(s32, s32, f32, f32, f32, f32);
extern void func_800B8C50(void);
extern s32 _subaddiefade_entrypoint_0(Actor *);
extern void func_800B8C8C(s32);
extern void func_800B8C98(s32);
extern void func_800B8CB0(s32);
extern void func_800B7F14(Gfx **);
extern void func_800B8F88(Gfx **, s32, void *);
extern void func_800B811C(Gfx **);
extern void func_80102FDC(Actor *, f32);
extern int D_8080532C_chintrochar[];
typedef struct {
    f32 local_0[3];
    f32 local_1;
} IntroPose1257;
typedef struct {
    u8 pad_0[0xD0];
    f32 local_0[2];
    u8 pad_1[0xC];
    IntroPose1257 local_1[2];
} IntroInterpolation1257;
typedef struct {
    u8 **f0;
    u8 pad[0x78];
    u32 pad7C : 19;
    u32 flag : 1;
    u32 rest : 12;
} IntroS;
extern s32 D_80805374_chintrochar[];
extern void func_800DBEFC();
extern void func_80103014();
typedef struct {
    u8 pad_0[0xE4];
    f32 local_0[3];
    f32 local_1;
    f32 local_2[3];
    f32 local_3;
} IntroPairedPose;
extern f32 func_800F1DF4(f32 *, f32 *);
extern u8 D_80805388_chintrochar[];
extern u8 D_8080537C_chintrochar[];
extern s32 func_801065A4(Actor *);
extern void _chintrochar_entrypoint_1();
extern void _glid_entrypoint_0(s32, s32, void (*)(), Unk80132ED0 *);
typedef struct {
    s16 position[3];
    u16 unk6;
    s16 unk8;
    s16 unkA;
    u8 padC[4];
} VertexShiftRecord;
extern Actor *func_80106790();
extern void _anseq_entrypoint_2(s16 *, f32, void *, s32, s32);
extern void _anseq_entrypoint_3(s16 *, f32, void *, s32, s32, s32);
typedef struct {
    u32 b31 : 1;
    u32 b30 : 1;
    u32 rest : 30;
} ICBits94;
extern u8 func_80804168_chintrochar[];
extern s32 D_80805318_chintrochar[];
extern void func_801017D0();
typedef struct {
    f32 local_0[2];
} IntroCharDrawPair;
typedef struct {
    u8 pad_0[0xD0];
    f32 local_0[2];
    f32 local_1[2];
    s16 local_2[2];
    f32 local_3[3];
    f32 local_4;
    f32 local_5[3];
    f32 local_6;
} IntroTextureScroll1210;
extern f32 func_800D8FF8(void);
extern void func_800EF934(f32 *, void *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
void func_80803E98_chintrochar();
void func_80803F24_chintrochar();
void func_80803F7C_chintrochar();
void func_80804238_chintrochar();
void func_80804054_chintrochar(Actor *param_0, s32 param_1, f32 param_2, void *param_3);

void func_80800000_chintrochar(Actor *actor)
{
    IntroExpressionBuffer1506 *expr_buf;
    s32 pad0;
    s32 flags;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 total;
    void *expression;
    u8 *entry;
    s16 unk_3;

    expr_buf = func_80100094(actor, 2);
    entry = D_80804790_chintrochar + actor->unk74_7 * 0x20;
    unk_3 = *(s16 *) (entry - 0x63A);
    flags = *(s32 *) (entry - 0x630);
    _suexpression_entrypoint_7(actor, 1, unk_3);
    if (flags & 0x40000)
        _suexpression_entrypoint_12(func_80100094(actor, 1), 160.0f, 120.0f);
    if (flags & 0x2000) {
        _suexpression_entrypoint_3(0x7B, &unk_0, &unk_1, &unk_2);
        total = unk_0 + unk_1 + unk_2;
        expr_buf->local_0 = func_8001B668(0, total);
        expression = func_8001B798(expr_buf->local_0);
        _suexpression_entrypoint_6(expression, 0x7B, unk_2, unk_0, unk_1);
        _suexpression_entrypoint_5(expression, 2);
    }
}

void func_808000FC_chintrochar(actor) Actor *actor;
{
    u32 flags_a;
    u32 flags_b;
    s32 fade_color[3];

    flags_a = *(u32 *) (D_80804790_chintrochar + actor->unk74_7 * 32 - 0x638) & 0x3FFFFFFF;
    flags_b = *(u32 *) (D_80804790_chintrochar + actor->unk74_7 * 32 - 0x634) & 0x3FFFFFFF;
    if (flags_a & 0x400) {
        _subaddieDll_entrypoint_0(actor);
    }
    if (flags_b & 0x80800000) {
        ((BitS148 *) actor)->b6 = 1;
    }
    if (flags_a & 0x800000) {
        ((BitS113 *) actor)->b5 = 1;
    }
    if (flags_a & 8) {
        ((BitS112 *) actor)->b0 = 1;
    }
    if (flags_b & 0x80000010) {
        ((BitS123 *) actor)->b1 = 1;
        fade_color[0] = *(D_80804790_chintrochar + actor->unk74_7 * 32 - 0x62C);
        fade_color[1] = *(D_80804790_chintrochar + actor->unk74_7 * 32 - 0x62B);
        fade_color[2] = *(D_80804790_chintrochar + actor->unk74_7 * 32 - 0x62A);
        _subaddiefade_entrypoint_11(actor, fade_color);
    }
    if ((flags_a & 0x20000)) {
        func_8010A800(actor, 2);
    }
    if ((flags_a & 0x400000)) {
        func_8010A800(actor, 3);
    }
    if (flags_a & 0x100) {
        *((u8 *) actor + 0x77) = (*((u8 *) actor + 0x77) & ~0xF) | 1;
    }
    func_80108658(actor, flags_a, flags_b, 0);
    if ((flags_a & 0x20000)) {
        func_8010A800(actor, 2);
    } else if ((flags_a & 0x400000)) {
        func_8010A800(actor, 3);
    } else {
        func_8010A800(actor, 0);
    }
    if (flags_a & 0x800) {
        func_8010A63C(actor);
    }
}

void func_808002FC_chintrochar(Actor *actor)
{
    u32 flags;
    flags = func_80804158_chintrochar[actor->unk74_7].flags & 0x3FFFFFFF;
    if (flags & 0x40)
        actor->unk0->unk4 = func_800DBFF8();
    if (flags & 0x1000)
        func_80105DFC(actor);
    if (flags & 0x20)
        *(u16 *) &actor->unk0->unk10 = func_800AE020();
}

void func_80800398_chintrochar(Actor *actor)
{
    u8 *text_buf;
    s32 text_bank;

    text_buf = func_80100094(actor, 2);
    text_bank = _gldbstring_entrypoint_0(0, 0x186C);
    switch (actor->unk74_7 - 0x32) {
        case 12:
            func_800E715C(text_buf, _gldbstring_entrypoint_1(text_bank, 0));
            func_800E715C(text_buf + 0x40, _gldbstring_entrypoint_1(text_bank, 1));
            break;
        case 3:
            func_800E715C(text_buf, _gldbstring_entrypoint_1(text_bank, 2));
            func_800E715C(text_buf + 0x40, _gldbstring_entrypoint_1(text_bank, 4));
            func_800E715C(text_buf + 0x80, _gldbstring_entrypoint_1(text_bank, 5));
    }
    _gldbstring_entrypoint_2(0x186C);
}

void func_80800484_chintrochar(u8 *actor)
{
    s32 flags;
    u8 *entry;
    flags = *(s32 *) ((char *) &func_80804160_chintrochar +
                        ((((u16) *(u16 *) ((s8 *) actor + 0x76) & 0xFFFFFFFFu) >> 7) << 5));
    func_808000FC_chintrochar();
    entry = (u8 *) ((char *) &D_80804790_chintrochar +
                      (((u32) *(u16 *) ((s8 *) actor + 0x76) >> 7) << 5));
    func_80103140(actor, *(u16 *) ((s8 *) entry - 0x640), *(u16 *) ((s8 *) entry - 0x63E));
    if (flags & 0x40) {
        func_80800000_chintrochar(actor);
    }
    if (flags & 0x1000) {
        func_80800398_chintrochar(actor);
    }
    if (flags & 0x10000) {
        func_80803E98_chintrochar(actor);
    }
    if (flags & 0x80000) {
        func_800DA544(0xD);
    }
}

void func_80800540_chintrochar(Actor *actor)
{
    u8 *state;
    u32 flags;
    u32 subtype;

    actor->unk64_19 = 1;
    subtype = actor->unk74_7;
    flags = *(u32 *) (D_80804790_chintrochar - 0x630 + subtype * 0x20);
    _chanim_entrypoint_7(actor, *(s16 *) (D_80804790_chintrochar - 0x63C + subtype * 0x20));
    func_80100074(actor, 2, 0x10C);
    state = func_80100094(actor, 2);
    *(s16 *) (state + 0xC0) = _anseq_entrypoint_6();
    *(s32 *) (state + 0xC8) = 0;
    func_80800484_chintrochar(actor);
    func_80105BE0(actor, 1);
    *(s16 *) (state + 0xC2) = flags & 1 ? _chblink_entrypoint_1(0) : 0;
    if (flags & 0x400) {
        *(s16 *) (state + 0xC4) = _chblink_entrypoint_1(1);
    } else if (flags & 0x4000) {
        *(s16 *) (state + 0xC4) = _chblink_entrypoint_1(2);
    } else {
        *(s16 *) (state + 0xC4) = 0;
    }
    func_80108B04(actor, 0);
}

void func_80800648_chintrochar(Actor *actor)
{
    u8 *state;
    u32 flags;

    state = func_80100094(actor, 2);
    flags = func_80804158_chintrochar[actor->unk74_7].flags & 0x3FFFFFFF;
    if ((flags & 0x20) && *(s16 *) &actor->unk0->unk10 != 0) {
        func_800ADFE0(*(s16 *) &actor->unk0->unk10);
        *(s16 *) &actor->unk0->unk10 = 0;
    }
    _chanim_entrypoint_6(actor);
    if (*(s16 *) (state + 0xC0) != 0) {
        _anseq_entrypoint_5(*(s16 *) (state + 0xC0));
    }
    if (*(s16 *) (state + 0xC2) != 0) {
        _chblink_entrypoint_3(*(s16 *) (state + 0xC2));
    }
    if (*(s16 *) (state + 0xC4) != 0) {
        _chblink_entrypoint_3(*(s16 *) (state + 0xC4));
    }
    if (*(s16 *) (state + 0xC6) != 0) {
        func_8001B754(*(s16 *) (state + 0xC6));
    }
}

// Attaches sound (drv_audio) and animation-table (antab) cues at normalised times per animation id.
void func_8080071C_chintrochar(Actor *actor, s32 anim_id)
{
    extern f32 D_80805270_chintrochar[];
    extern f32 D_8080527C_chintrochar[];
    extern f32 D_80805288_chintrochar[];
    extern f32 D_808052A4_chintrochar[];
    extern f32 D_808052AC_chintrochar[];
    extern f32 D_808052B4_chintrochar[];
    extern f32 D_808052C0_chintrochar[];
    extern f32 D_808052D8_chintrochar[];
    extern f32 D_808052E8_chintrochar[];
    extern void _inantab_entrypoint_2();
    extern void _indrv_audio_entrypoint_0();

    char *state;
    s16 *seq;
    void *model;

    state = (char *) func_80100094(actor, 2);
    seq = _anseq_entrypoint_9(*(s16 *) (state + 0xC0));
    model = actor->unk0;
    _anseq_entrypoint_0(seq);

    switch (anim_id) {
        case 0x39B: {
            s32 i;
            for (i = 0; i < 3; i++) {
                _anseq_entrypoint_2(seq, D_80805270_chintrochar[i], _inantab_entrypoint_2,
                                    *(s32 *) &model, 0);
            }
        }
            {
                s32 i;
                for (i = 0; i < 3; i++) {
                    _anseq_entrypoint_2(seq, D_8080527C_chintrochar[i],
                                        _inantab_entrypoint_2, *(s32 *) &model, 1);
                }
            }
            return;

        case 0x39C:
            _anseq_entrypoint_3(seq, 0.294200003f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                6, -1);
            _anseq_entrypoint_3(seq, 0.905300021f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                7, -1);
            return;

        case 0x264:
            _anseq_entrypoint_2(seq, 0.0295000002f, _inantab_entrypoint_2, *(s32 *) &model,
                                0);
            _anseq_entrypoint_2(seq, 0.519900024f, _inantab_entrypoint_2, *(s32 *) &model, 1);
            return;

        case 0x44C:
            _anseq_entrypoint_3(seq, 0.542500019f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                10, -1);
            _anseq_entrypoint_3(seq, 0.625400007f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                10, -1);
            return;

        case 0x455:
            _anseq_entrypoint_3(seq, 0.107799999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                11, -1);
            _anseq_entrypoint_3(seq, 0.264299989f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                12, -1);
            _anseq_entrypoint_3(seq, 0.294f, _indrv_audio_entrypoint_0, *(s32 *) &model, 13,
                                -1);
            return;

        case 0x4F2:
            _anseq_entrypoint_3(seq, 0.0957000032f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 136, -1);
            _anseq_entrypoint_3(seq, 0.151299998f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                136, -1);
            _anseq_entrypoint_3(seq, 0.223399997f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                136, -1);
            _anseq_entrypoint_3(seq, 0.304800004f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                137, -1);
            _anseq_entrypoint_3(seq, 0.371499985f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                137, -1);
            return;

        case 0x4F4:
            _anseq_entrypoint_3(seq, 0.126800001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                138, -1);
            _anseq_entrypoint_3(seq, 0.855000019f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                139, -1);
            _anseq_entrypoint_3(seq, 0.917800009f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                140, -1);
            return;

        case 0x422:
            _anseq_entrypoint_3(seq, 0.805100024f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                119, -1);
            return;

        case 0x474: {
            s32 i;
            for (i = 0; i < 7; i++) {
                _anseq_entrypoint_3(seq, D_80805288_chintrochar[i],
                                    _indrv_audio_entrypoint_0, *(s32 *) &model, 0x64, -1);
            }
        }
            return;

        case 0x40C:
            _anseq_entrypoint_3(seq, 0.531599998f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                14, -1);
            _anseq_entrypoint_3(seq, 0.0199999996f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 15, -1);
            return;

        case 0x40D: {
            s32 i;
            for (i = 0; i < 2; i++) {
                _anseq_entrypoint_3(seq, D_808052A4_chintrochar[i],
                                    _indrv_audio_entrypoint_0, *(s32 *) &model, 0xE, -1);
            }
        }
            {
                s32 i;
                for (i = 0; i < 2; i++) {
                    _anseq_entrypoint_3(seq, D_808052AC_chintrochar[i],
                                        _indrv_audio_entrypoint_0, *(s32 *) &model, 0xF, -1);
                }
            }
            _anseq_entrypoint_3(seq, 0.17f, _indrv_audio_entrypoint_0, *(s32 *) &model, 0x10,
                                -1);
            return;

        case 0x463:
            _anseq_entrypoint_3(seq, 0.570800006f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                17, -1);
            return;

        case 0x466:
            _anseq_entrypoint_3(seq, 0.100000001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                19, -1);
            _anseq_entrypoint_3(seq, 0.536000013f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                176, -1);
            _anseq_entrypoint_3(seq, 0.572700024f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                177, -1);
            _anseq_entrypoint_3(seq, 0.609200001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                178, -1);
            return;

        case 0x48C:
            _anseq_entrypoint_3(seq, 0.00999999978f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 120, -1);
            _anseq_entrypoint_3(seq, 0.579999983f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                103, -2);
            _anseq_entrypoint_3(seq, 0.699999988f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                176, -2);
            _anseq_entrypoint_3(seq, 0.730000019f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                177, -2);
            _anseq_entrypoint_3(seq, 0.75999999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                178, -2);
            return;

        case 0x521:
            _anseq_entrypoint_3(seq, 0.221799999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                174, -1);
            _anseq_entrypoint_3(seq, 0.356400013f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                125, -1);
            _anseq_entrypoint_3(seq, 0.450700015f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                175, -1);
            _anseq_entrypoint_3(seq, 0.70539999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                126, -1);
            return;

        case 0x536:
            _anseq_entrypoint_3(seq, 0.0469000004f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 159, -1);
            _anseq_entrypoint_3(seq, 0.103399999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                160, -1);
            _anseq_entrypoint_3(seq, 0.1074f, _indrv_audio_entrypoint_0, *(s32 *) &model, 156,
                                -1);
            _anseq_entrypoint_3(seq, 0.203899994f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                160, -1);
            _anseq_entrypoint_3(seq, 0.207900003f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                157, -1);
            _anseq_entrypoint_3(seq, 0.3116f, _indrv_audio_entrypoint_0, *(s32 *) &model, 160,
                                -1);
            _anseq_entrypoint_3(seq, 0.315600008f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                158, -1);
            _anseq_entrypoint_3(seq, 0.441000015f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                161, -1);
            _anseq_entrypoint_3(seq, 0.444999993f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                156, -1);
            _anseq_entrypoint_3(seq, 0.609600008f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                161, -1);
            _anseq_entrypoint_3(seq, 0.613600016f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                157, -1);
            _anseq_entrypoint_3(seq, 0.760599971f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                161, -1);
            _anseq_entrypoint_3(seq, 0.764599979f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                158, -1);
            _anseq_entrypoint_3(seq, 0.905499995f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                162, -1);
            _anseq_entrypoint_3(seq, 0.909500003f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                131, -1);
            return;

        case 0xB4:
            _anseq_entrypoint_2(seq, 0.226199999f, _inantab_entrypoint_2, *(s32 *) &model, 0);
            _anseq_entrypoint_2(seq, 0.716499984f, _inantab_entrypoint_2, *(s32 *) &model, 1);
            return;

        case 0x462:
            _anseq_entrypoint_2(seq, 0.226199999f, _inantab_entrypoint_2, *(s32 *) &model, 0);
            _anseq_entrypoint_2(seq, 0.716499984f, _inantab_entrypoint_2, *(s32 *) &model, 1);
            return;

        case 0x465: {
            s32 i;
            for (i = 0; i < 3; i++) {
                _anseq_entrypoint_3(seq, D_808052B4_chintrochar[i],
                                    _indrv_audio_entrypoint_0, *(s32 *) &model, 0x17, -1);
            }
        }
            return;

        case 0x467:
            _anseq_entrypoint_3(seq, 0.0423000008f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 24, -1);
            _anseq_entrypoint_3(seq, 0.173999995f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                25, -1);
            _anseq_entrypoint_3(seq, 0.229200006f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                25, -1);
            return;

        case 0x468:
            _anseq_entrypoint_3(seq, 0.67869997f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                26, -1);
            _anseq_entrypoint_3(seq, 0.961199999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                27, -1);
            _anseq_entrypoint_3(seq, 0.966799974f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                25, -1);
            _anseq_entrypoint_3(seq, 0.980000019f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                28, -1);
            return;

        case 0x46A:
            _anseq_entrypoint_3(seq, 0.108999997f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                29, -1);
            _anseq_entrypoint_3(seq, 0.2597f, _indrv_audio_entrypoint_0, *(s32 *) &model, 25,
                                -1);
            _anseq_entrypoint_3(seq, 0.228060007f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                25, -1);
            return;

        case 0x470:
            _anseq_entrypoint_3(seq, 0.459199995f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                30, -1);
            return;

        case 0x51F:
            _anseq_entrypoint_3(seq, 0.0588000007f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 144, -1);
            _anseq_entrypoint_3(seq, 0.063000001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                156, -1);
            _anseq_entrypoint_3(seq, 0.220699996f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                144, -1);
            _anseq_entrypoint_3(seq, 0.225999996f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                158, -1);
            _anseq_entrypoint_3(seq, 0.384799987f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                144, -1);
            _anseq_entrypoint_3(seq, 0.388999999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                157, -1);
            _anseq_entrypoint_3(seq, 0.544499993f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                144, -1);
            _anseq_entrypoint_3(seq, 0.549499989f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                156, -1);
            _anseq_entrypoint_3(seq, 0.700699985f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                144, -1);
            _anseq_entrypoint_3(seq, 0.705900013f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                157, -1);
            _anseq_entrypoint_3(seq, 0.886699975f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                145, -1);
            _anseq_entrypoint_3(seq, 0.890699983f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                131, -1);
            return;

        case 0x46B: {
            s32 i;
            for (i = 0; i < 6; i++) {
                _anseq_entrypoint_3(seq, D_808052C0_chintrochar[i],
                                    _indrv_audio_entrypoint_0, *(s32 *) &model, 0x1F, -1);
            }
        }
            return;

        case 0x46C:
            _anseq_entrypoint_3(seq, 0.0384000018f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 32, -1);
            return;

        case 0x46E:
            _anseq_entrypoint_3(seq, 0.803799987f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                33, -1);
            return;

        case 0x513:
            _anseq_entrypoint_3(seq, 0.214699998f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                147, -1);
            _anseq_entrypoint_3(seq, 0.843299985f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                148, -1);
            return;

        case 0x519:
            _anseq_entrypoint_3(seq, 0.699999988f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                166, -1);
            _anseq_entrypoint_3(seq, 0.915199995f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                151, -1);
            _anseq_entrypoint_3(seq, 0.915199995f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                170, -1);
            return;

        case 0x511:
            _anseq_entrypoint_3(seq, 0.668600023f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                152, -1);
            return;

        case 0x512:
            _anseq_entrypoint_3(seq, 0.816399992f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                153, -1);
            _anseq_entrypoint_3(seq, 0.905900002f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                153, -1);
            _anseq_entrypoint_3(seq, 0.997200012f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                153, -1);
            _anseq_entrypoint_3(seq, 0.148300007f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                153, -1);
            _anseq_entrypoint_3(seq, 0.254299998f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                153, -1);
            return;

        case 0x4B0:
            _anseq_entrypoint_2(seq, 0.0555999987f, _inantab_entrypoint_2, *(s32 *) &model,
                                0);
            _anseq_entrypoint_2(seq, 0.559400022f, _inantab_entrypoint_2, *(s32 *) &model, 1);
            return;

        case 0x3AB:
            _anseq_entrypoint_3(seq, 0.131200001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.1602f, _indrv_audio_entrypoint_0, *(s32 *) &model, 34,
                                -1);
            _anseq_entrypoint_3(seq, 0.217199996f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.230599999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                91, -1);
            _anseq_entrypoint_3(seq, 0.251199991f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.257800013f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.272500008f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                91, -1);
            _anseq_entrypoint_3(seq, 0.282700002f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.291299999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.294800013f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.310900003f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                91, -1);
            _anseq_entrypoint_3(seq, 0.317600012f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.343300015f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.353899986f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.377999991f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                91, -1);
            _anseq_entrypoint_3(seq, 0.400299996f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.415399998f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            return;

        case 0x410:
            _anseq_entrypoint_3(seq, 0.2456f, _indrv_audio_entrypoint_0, *(s32 *) &model, 34,
                                -1);
            _anseq_entrypoint_3(seq, 0.261299998f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.266400009f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.277700007f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                91, -1);
            _anseq_entrypoint_3(seq, 0.288300008f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.296499997f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.314099997f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                91, -1);
            _anseq_entrypoint_3(seq, 0.34799999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.36680001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                91, -1);
            _anseq_entrypoint_3(seq, 0.390799999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            _anseq_entrypoint_3(seq, 0.405200005f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                34, -1);
            return;

        case 0x40F:
            _anseq_entrypoint_3(seq, 0.633099973f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                39, -1);
            _anseq_entrypoint_3(seq, 0.681800008f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                39, -1);
            _anseq_entrypoint_3(seq, 0.721700013f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                39, -1);
            _anseq_entrypoint_3(seq, 0.721700013f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                39, -1);
            return;

        case 0x411:
            _anseq_entrypoint_3(seq, 0.69630003f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                41, -1);
            _anseq_entrypoint_3(seq, 0.99000001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                43, -1);
            return;

        case 0x447:
            _anseq_entrypoint_3(seq, 0.0f, _indrv_audio_entrypoint_0, *(s32 *) &model, 44,
                                -1);
            _anseq_entrypoint_3(seq, 0.349999994f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                45, -1);
            _anseq_entrypoint_3(seq, 0.436300009f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                46, -1);
            _anseq_entrypoint_3(seq, 0.791199982f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                48, -1);
            return;

        case 0x414:
            _anseq_entrypoint_2(seq, 0.6171f, _inantab_entrypoint_2, *(s32 *) &model, 0);
            _anseq_entrypoint_2(seq, 0.0604000017f, _inantab_entrypoint_2, *(s32 *) &model,
                                1);
            return;

        case 0x415:
            _anseq_entrypoint_2(seq, 0.6171f, _inantab_entrypoint_2, *(s32 *) &model, 0);
            _anseq_entrypoint_2(seq, 0.0604000017f, _inantab_entrypoint_2, *(s32 *) &model,
                                1);
            return;

        case 0x417:
            _anseq_entrypoint_3(seq, 0.236300007f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                53, -1);
            _anseq_entrypoint_3(seq, 0.236300007f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                92, -1);
            return;

        case 0x418:
            _anseq_entrypoint_3(seq, 0.734600008f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                54, -1);
            return;

        case 0x41C:
            _anseq_entrypoint_3(seq, 0.649999976f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                55, -1);
            return;

        case 0x421:
            _anseq_entrypoint_3(seq, 0.0f, _indrv_audio_entrypoint_0, *(s32 *) &model, 56,
                                -1);
            return;

        case 0x425:
            _anseq_entrypoint_3(seq, 0.0975999981f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 57, -1);
            return;

        case 0x457:
            _anseq_entrypoint_3(seq, 0.551800013f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                58, -1);
            _anseq_entrypoint_3(seq, 0.628799975f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                58, -1);
            _anseq_entrypoint_3(seq, 0.708700001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                58, -1);
            _anseq_entrypoint_3(seq, 0.914699972f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                60, -1);
            return;

        case 0x45A:
            _anseq_entrypoint_3(seq, 0.360700011f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                59, -1);
            _anseq_entrypoint_3(seq, 0.685299993f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                61, -1);
            _anseq_entrypoint_3(seq, 0.75029999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                61, -1);
            _anseq_entrypoint_3(seq, 0.805000007f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                61, -1);
            return;

        case 0x45E:
            _anseq_entrypoint_3(seq, 0.360700011f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                59, -1);
            _anseq_entrypoint_3(seq, 0.685299993f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                61, -1);
            _anseq_entrypoint_3(seq, 0.75029999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                61, -1);
            _anseq_entrypoint_3(seq, 0.805000007f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                61, -1);
            return;

        case 0x50E:
            _anseq_entrypoint_3(seq, 0.360700011f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                59, -1);
            _anseq_entrypoint_3(seq, 0.685299993f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                61, -1);
            _anseq_entrypoint_3(seq, 0.75029999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                61, -1);
            _anseq_entrypoint_3(seq, 0.805000007f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                61, -1);
            return;

        case 0x4F1:
            _anseq_entrypoint_3(seq, 0.240400001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                130, -1);
            return;

        case 0x41A:
            _anseq_entrypoint_2(seq, 0.491699994f, _inantab_entrypoint_2, *(s32 *) &model, 0);
            _anseq_entrypoint_2(seq, 0.982299984f, _inantab_entrypoint_2, *(s32 *) &model, 1);
            return;

        case 0x41E:
            _anseq_entrypoint_3(seq, 0.0434999987f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 64, -1);
            _anseq_entrypoint_3(seq, 0.374799997f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                65, -1);
            return;

        case 0x420:
            _anseq_entrypoint_3(seq, 0.111199997f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                66, -1);
            return;

        case 0x45B:
            _anseq_entrypoint_3(seq, 0.0f, _indrv_audio_entrypoint_0, *(s32 *) &model, 69,
                                -1);
            return;

        case 0x45C:
            _anseq_entrypoint_3(seq, 0.342299998f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                70, -1);
            _anseq_entrypoint_3(seq, 0.631600022f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                71, -1);
            _anseq_entrypoint_3(seq, 0.919499993f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                71, -1);
            return;

        case 0x501:
            _anseq_entrypoint_7(seq, 1);
            _anseq_entrypoint_3(seq, 0.747300029f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                128, -1);
            return;

        case 0x446:
            _anseq_entrypoint_3(seq, 0.320100009f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                72, -1);
            _anseq_entrypoint_3(seq, 0.661000013f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                72, -1);
            return;

        case 0x44F:
            _anseq_entrypoint_2(seq, 0.0f, _inantab_entrypoint_2, *(s32 *) &model, 0);
            _anseq_entrypoint_2(seq, 0.5f, _inantab_entrypoint_2, *(s32 *) &model, 1);
            return;

        case 0x450:
            _anseq_entrypoint_3(seq, 0.732400000f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                0x4C, -1);
            {
                s32 i;
                for (i = 0; i < 4; i++) {
                    _anseq_entrypoint_2(seq, D_808052D8_chintrochar[i],
                                        _inantab_entrypoint_2, *(s32 *) &model, 0);
                }
            }
            {
                s32 i;
                for (i = 0; i < 4; i++) {
                    _anseq_entrypoint_2(seq, D_808052E8_chintrochar[i],
                                        _inantab_entrypoint_2, *(s32 *) &model, 1);
                }
            }
            return;

        case 0x451:
            _anseq_entrypoint_3(seq, 0.0351999998f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 77, -1);
            _anseq_entrypoint_3(seq, 0.0623000003f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 78, -1);
            _anseq_entrypoint_3(seq, 0.0623000003f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 79, -1);
            _anseq_entrypoint_3(seq, 0.440800011f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                82, -1);
            return;

        case 0x492:
            _anseq_entrypoint_3(seq, 0.620599985f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                83, -1);
            _anseq_entrypoint_3(seq, 0.686100006f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                83, -1);
            _anseq_entrypoint_3(seq, 0.763100028f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                83, -1);
            _anseq_entrypoint_3(seq, 0.932200015f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                85, -1);
            return;

        case 0x4FC:
            _anseq_entrypoint_3(seq, 0.306400001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                121, -1);
            return;

        case 0x4FE:
            _anseq_entrypoint_3(seq, 0.231900007f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                122, -1);
            return;

        case 0x500:
            _anseq_entrypoint_7(seq, 1);
            _anseq_entrypoint_3(seq, 0.345600009f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                123, -1);
            return;

        case 0x190:
            _anseq_entrypoint_3(seq, 0.550000012f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                102, -1);
            return;

        case 0x1E6:
            _anseq_entrypoint_2(seq, 0.0f, _inantab_entrypoint_2, *(s32 *) &model, 0);
            _anseq_entrypoint_2(seq, 0.5f, _inantab_entrypoint_2, *(s32 *) &model, 1);
            return;

        case 0x1E9:
            _anseq_entrypoint_3(seq, 0.100000001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                101, -1);
            return;

        case 0x45F:
            _anseq_entrypoint_2(seq, 0.400999993f, _inantab_entrypoint_2, *(s32 *) &model, 0);
            _anseq_entrypoint_2(seq, 0.897800028f, _inantab_entrypoint_2, *(s32 *) &model, 1);
            return;

        case 0x460:
            _anseq_entrypoint_3(seq, 0.783800006f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                89, -1);
            _anseq_entrypoint_3(seq, 0.862600029f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                90, -1);
            return;

        case 0x538:
            _anseq_entrypoint_3(seq, 0.0566999987f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 167, -1);
            _anseq_entrypoint_3(seq, 0.0566999987f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 157, -1);
            _anseq_entrypoint_3(seq, 0.245800003f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                168, -1);
            _anseq_entrypoint_3(seq, 0.245800003f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                160, -1);
            _anseq_entrypoint_3(seq, 0.245800003f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                156, -1);
            _anseq_entrypoint_3(seq, 0.344599992f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                168, -1);
            _anseq_entrypoint_3(seq, 0.344599992f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                158, -1);
            _anseq_entrypoint_3(seq, 0.344599992f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                160, -1);
            _anseq_entrypoint_3(seq, 0.46540001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                168, -1);
            _anseq_entrypoint_3(seq, 0.46540001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                156, -1);
            _anseq_entrypoint_3(seq, 0.46540001f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                160, -1);
            _anseq_entrypoint_3(seq, 0.584800005f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                168, -1);
            _anseq_entrypoint_3(seq, 0.584800005f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                157, -1);
            _anseq_entrypoint_3(seq, 0.584800005f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                160, -1);
            _anseq_entrypoint_3(seq, 0.675800025f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                168, -1);
            _anseq_entrypoint_3(seq, 0.675800025f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                158, -1);
            _anseq_entrypoint_3(seq, 0.675800025f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                160, -1);
            _anseq_entrypoint_3(seq, 0.824400008f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                169, -1);
            _anseq_entrypoint_3(seq, 0.824400008f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                156, -1);
            _anseq_entrypoint_3(seq, 0.824400008f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                162, -1);
            return;

        case 0x523:
            _anseq_entrypoint_3(seq, 0.5449f, _indrv_audio_entrypoint_0, *(s32 *) &model, 120,
                                -1);
            return;

        case 0x4DC:
            _anseq_entrypoint_3(seq, 0.00999999978f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 162, -1);
            _anseq_entrypoint_3(seq, 0.310000002f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                131, -2);
            return;

        case 0x4EC:
            _anseq_entrypoint_3(seq, 0.0458999984f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 132, -1);
            _anseq_entrypoint_3(seq, 0.81190002f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                133, -1);
            _anseq_entrypoint_3(seq, 0.866100013f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                133, -1);
            return;

        case 0x4ED:
            _anseq_entrypoint_3(seq, 0.711399972f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                134, -1);
            return;

        case 0x502:
            _anseq_entrypoint_3(seq, 0.216900006f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                141, -1);
            _anseq_entrypoint_3(seq, 0.554799974f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                143, -1);
            return;

        case 0x533:
            _anseq_entrypoint_3(seq, 0.0621000007f, _indrv_audio_entrypoint_0,
                                *(s32 *) &model, 163, -1);
            _anseq_entrypoint_3(seq, 0.156900004f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                164, -1);
            _anseq_entrypoint_3(seq, 0.554700017f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                164, -1);
            _anseq_entrypoint_3(seq, 0.910000026f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                165, -4);
            _anseq_entrypoint_3(seq, 0.910000026f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                171, -4);
            return;

        case 0x535:
            _anseq_entrypoint_3(seq, 0.649999976f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                165, -1);
            _anseq_entrypoint_3(seq, 0.649999976f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                171, -1);
            return;

        case 0x50A:
            _anseq_entrypoint_3(seq, 0.104900002f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                155, -1);
            _anseq_entrypoint_3(seq, 0.276600003f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                155, -1);
            _anseq_entrypoint_3(seq, 0.449600011f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                155, -1);
            return;

        case 0x53B:
            _anseq_entrypoint_3(seq, 0.174400002f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                172, -1);
            _anseq_entrypoint_3(seq, 0.610700011f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                172, -1);
            return;

        case 0x540:
            _anseq_entrypoint_3(seq, 0.660000026f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                179, -1);
            return;

        case 0x541:
            _anseq_entrypoint_3(seq, 0.127299994f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                180, -1);
            _anseq_entrypoint_3(seq, 0.200800002f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                180, -1);
            _anseq_entrypoint_3(seq, 0.243799999f, _indrv_audio_entrypoint_0, *(s32 *) &model,
                                180, -1);

        case 0xB3:

        case 0x1E7:

        case 0x39D:
        case 0x39E:
        case 0x4A0:
        case 0x408:
        case 0x445:
        case 0x4DB:
            return;
    }
}

// Raycasts 100 units up and down from the actor and stores the hit result in the contact state.
void func_80803388_chintrochar(Actor *actor, IntroContactState *contact_state)
{
    f32 top[3];
    f32 bottom[3];
    f32 hit_pos[3];
    IntroContact *contact;
    func_800EE7F8(bottom, actor->position);
    func_800EE7F8(top, actor->position);
    bottom[1] -= 100.0f;
    top[1] += 100.0f;
    contact = func_800C6A7C(top, bottom, hit_pos, actor->unk14);
    if (contact)
        contact_state->local_0 = func_800C84B0(contact->local_0);
}

void func_80803418_chintrochar(Actor *actor, s32 mode)
{
    IntroCharacterStep *state;
    s32 unk_0;
    f32 unk_1;
    s32 unk_2;

    state = func_80100094(actor, 2);
    func_80803388_chintrochar(actor, state);
    if (_fxstep_entrypoint_15(state->step, mode == 0 ? 0 : 1, &unk_0, &unk_2, &unk_1)) {
        func_800C4B64(unk_1);
        func_800C4B70(unk_2);
        func_800C4B7C(unk_0);
        func_8010D930(2, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                      D_808052F8_chintrochar);
    }
}

void func_808034C4_chintrochar(Actor *actor)
{
    u8 *state;
    s32 seq;
    s32 flags;
    f32 shadow_size;
    s32 i;
    Vec3f cam_pos;
    Vec3f unk_0;
    s32 anim_id;
    state = (u8 *) func_80100094(actor, 2);
    seq = _anseq_entrypoint_9(*(s16 *) (state + 0xC0));
    flags = *(s32 *) (func_80804160_chintrochar + actor->unk74_7 * 0x20);
    func_8010588C(actor);
    if (flags & 0x100) {
        actor->rotation[0] = 0.0f;
    }
    if (flags & 0x10000) {
        func_80803F7C_chintrochar(actor);
    }
    if (flags & 0x20000) {
        for (i = 0; i < 2; i++) {
            func_80803F24_chintrochar(actor, func_80106790(((s32 *) (state + 0x104))[i]),
                                      i);
        }
    }
    anim_id = func_801022E4(actor);
    if (anim_id != *(s32 *) (state + 0xC8)) {
        *(s32 *) (state + 0xC8) = anim_id;
        func_8080071C_chintrochar(actor, anim_id);
    }
    _anseq_entrypoint_8(seq, func_80104248(actor));
    if (*(s16 *) (state + 0xC2)) {
        _chblink_entrypoint_2(*(s16 *) (state + 0xC2));
    }
    if (*(s16 *) (state + 0xC4)) {
        _chblink_entrypoint_2(*(s16 *) (state + 0xC4));
    }
    _chanim_entrypoint_9(actor);
    if (flags & 0x80000) {
        _chanim_entrypoint_1(actor->unk0, 0xD, func_800DA298(0xD));
    }
    if (flags & 0x40) {
        if (flags & 0x40000) {
            func_8010FFB0(func_8008FFE8(), cam_pos.f, unk_0.f);
            _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, cam_pos.f);
        } else {
            _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
        }
    }
    if (*(s16 *) (state + 0xC6)) {
        _suexpression_entrypoint_10(func_8001B798(*(s16 *) (state + 0xC6)), actor->unk0, 0);
    }
    if (!_subaddiefade_entrypoint_0(actor)) {
        actor->unk64_16 = 0;
    } else {
        actor->unk64_16 = actor->unk64_19;
    }
    shadow_size = *(f32 *) (func_8080416C_chintrochar + actor->unk74_7 * 0x20);
    if (shadow_size > 0.0f) {
        _chbadshad_entrypoint_1(actor, actor->position, shadow_size);
    }
}

void func_8080374C_chintrochar(Actor *actor, s32 unused)
{
    s32 unk_0;
    u8 *state;
    s32 i;
    u8 *state2;

    state = func_80100094(actor, 2);
    if (*(s16 *) (state + 0xC6)) {
        _suexpression_entrypoint_19(func_8001B798(*(s16 *) (state + 0xC6)), actor);
    }
    if ((*(s32 *) (func_80804160_chintrochar + actor->unk74_7 * 32) << 15) < 0) {
        unk_0 = func_8010262C(actor->unk0, 6);
        if (unk_0) {
            state2 = func_80100094(actor, 2);
            for (i = 0; i < 3; i++) {
                func_800E0AFC(unk_0, ((u8(*)[2]) D_80805308_chintrochar)[i][1], -1.0f,
                              *(f32 *) (state2 + 0xD0), 0.0f, 0.0f);
            }
            for (i = 0; i < 3; i++) {
                func_800E0AFC(unk_0, ((u8(*)[2]) D_80805310_chintrochar)[i][1], -1.0f,
                              *(f32 *) (state2 + 0xD4), 0.0f, 0.0f);
            }
        }
    }
}

void func_80803888_chintrochar(u8 *actor)
{
    u8 *state;
    s32 flags;
    s16 blink_a;
    s16 blink_b;
    s16 expression_id;

    state = func_80100094(actor, 2);
    flags = *(s32 *) ((char *) &func_80804160_chintrochar +
                     (((u32) *(u16 *) ((u8 *) actor + 0x76) >> 7) << 5));
    func_80103D48(actor);
    _chanim_entrypoint_8(actor);
    blink_a = *(s16 *) ((u8 *) state + 0xC2);
    if (blink_a != 0) {
        _chblink_entrypoint_4(blink_a);
    }
    blink_b = *(s16 *) ((u8 *) state + 0xC4);
    if (blink_b != 0) {
        _chblink_entrypoint_4(blink_b);
    }
    func_801015D0(actor);
    expression_id = *(s16 *) ((u8 *) state + 0xC6);
    if (expression_id != 0) {
        _suexpression_entrypoint_11(func_8001B798(expression_id), actor);
    }
    if (flags & 0x10) {
        func_800DF830(2);
    } else if (flags & 8) {
        func_800DF830(0);
    } else if (flags & 0x20) {
        func_800DF830(3);
    }
    func_80103D70(actor);
}

void func_80803990_chintrochar(Actor *actor, Gfx **gfx)
{
    u8 *state;
    u8 *base;

    state = func_80100094(actor, 2);
    func_800B8C50();
    func_800B8C8C(_subaddiefade_entrypoint_0(actor));
    func_800B8C98(0);
    func_800B8CB0(1);
    func_800B7F14(gfx);
    switch (actor->unk74_7 - 50) {
        case 12:
            func_800B8F88(gfx, 0xB6, base = *(u8 **) &state);
            func_800B8F88(gfx, 0xC2, base + 0x40);
            break;
        case 3:
            func_800B8F88(gfx, 0xB6, base = *(u8 **) &state);
            func_800B8F88(gfx, 0xC2, base + 0x40);
            func_800B8F88(gfx, 0xCE, base + 0x80);
    }
    func_800B811C(gfx);
}

void func_80803A78_chintrochar(Actor *actor, s32 gfx)
{
    extern void func_800EFA4C(f32 *, f32, f32, f32);
    extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    extern void *func_800DF944(s32, f32 *, f32, f32, f32 *, s32, void *);
    extern void func_800DF464(f32);
    s32 flags;
    f32 rot[3];
    IntroCharDrawPair pair;
    f32 unk_0[3];
    f32 unk_1[3];
    f32 unk_2[3];
    s32 sub_id;
    flags = *(s32 *) (func_80804160_chintrochar + actor->unk74_7 * 0x20);
    if (flags & 2) {
        if (flags & 0x8000) {
            pair = *(IntroCharDrawPair *) D_80805318_chintrochar;
            sub_id = actor->unk74_7 - 0x32;
            if (sub_id == 3 || sub_id == 4) {
                pair.local_0[1] -= 20.0f;
            }
            if (!(flags & 4) && actor->rotation[1] != 0) {
                func_800EFA4C(rot, 0.0f, actor->rotation[1], 0.0f);
                func_800DF4CC(rot);
            }
            func_800DF47C(func_801017D0, actor);
            func_800DF944(gfx, pair.local_0, 0.0f, actor->scale * 0.35f, 0, 1,
                          (void *) func_8010347C(actor->unk0));
        } else {
            func_800E39A8(unk_0, unk_1);
            func_800EF5A0(unk_2, unk_1, 0, 0, -1000.0f);
            func_800EF04C(unk_2, unk_0);
            func_800DF47C(func_801017D0, actor);
            if (flags & 4) {
                func_800DE448(unk_2, unk_1, actor->scale, 0, func_801039E4(actor->unk0));
            } else {
                func_800DE448(unk_2, actor->rotation, actor->scale, 0,
                              func_801039E4(actor->unk0));
            }
        }
    } else {
        if (((ICBits94 *) &actor->pad94)->b30) {
            func_800DF440(0);
        } else {
            func_80101970(actor);
        }
        if (flags & 0x200) {
            func_800DF464(*(f32 *) (func_80804168_chintrochar + actor->unk74_7 * 0x20));
        }
        func_800DF47C(func_801017D0, actor);
        func_800DE448(actor->position, actor->rotation, actor->scale, 0,
                      func_801039E4(actor->unk0));
    }
    if (flags & 0x1000) {
        func_80803990_chintrochar(actor, gfx);
    }
}

int func_80803D0C_chintrochar(Actor *actor, s32 cmd, s32 arg)
{
    u8 *state;
    s32 i;
    Actor *spawned;
    s32 flags;
    switch (cmd) {
        case 0x29:
            func_808002FC_chintrochar(actor);
            break;
        case 0x9C:
            func_8080374C_chintrochar(actor, *(s32 *) &arg);
            break;
        case 0x1F:
            func_80803888_chintrochar(actor);
            break;
        case 0x5A:
            if (arg == 0 || arg == 1)
                func_80803418_chintrochar(actor, arg);
            break;
        case 0x3D:
            flags = *(s32 *) (func_80804160_chintrochar + actor->unk74_7 * 32);
            if ((flags << 14) < 0) {
                state = (u8 *) func_80100094(actor, 2);
                for (i = 0; i != 2; i++) {
                    spawned = (Actor *) func_80108528(0x50A, actor->position, 10, &actor);
                    ((void **) (state + 0x104))[i] = spawned->unk0;
                    func_80103110(spawned, 1);
                    func_80102FDC(spawned, 1.5f);
                }
            }
            break;
        default:
            return 0;
    }
    return 1;
}

int chintrochar_entrypoint_0()
{
    return (int) &D_8080532C_chintrochar;
}

void func_80803E98_chintrochar(actor) Actor *actor;
{
    IntroInterpolation1257 *state;
    s32 i;

    state = func_80100094(actor, 2);
    for (i = 0; i < 2; i++) {
        state->local_0[i] = 0.0f;
    }
    func_800EE7F8(state->local_1[1].local_0, actor->position);
    func_800EE7F8(state->local_1[0].local_0, actor->position);
    state->local_1[1].local_1 = actor->rotation[1];
    state->local_1[0].local_1 = actor->rotation[1];
}

void func_80803F24_chintrochar(owner, out, index) IntroS *owner;
u8 *out;
s32 index;
{

if (owner->flag) {
    func_800DBEFC(*(s32 *) ((u8 *) owner->f0 + 4), D_80805374_chintrochar[index], out + 4);
}

func_80103014(out);
}

void func_80803F7C_chintrochar(actor) Actor *actor;
{
    IntroPairedPose *pose;
    f32 unk_0[3];
    pose = func_80100094(actor, 2);

if (actor->unk7C_12) {
    func_800DBEFC(actor->unk0->unk4, 7, pose->local_0);
    func_800DBEFC(actor->unk0->unk4, 8, unk_0);
    pose->local_1 = func_800F1DF4(unk_0, pose->local_2);
}

func_80804054_chintrochar(actor, 0, -1.0f, D_80805388_chintrochar);
func_80804054_chintrochar(actor, 1, 1.0f, D_8080537C_chintrochar);
func_80804238_chintrochar(actor);
func_800EE7F8(pose->local_2, pose->local_0);
pose->local_3 = pose->local_1;
}

void func_80804054_chintrochar(Actor *actor, s32 index, f32 direction, void *axis)
{
    IntroTextureScroll1210 *scroll;
    f32 dt;
    f32 vec_a[3];
    f32 vec_b[3];
    f32 dist;
    f32 sign;
    f32 unk_0;
    f32 unk_1;
    s32 pos_int;

    scroll = func_80100094(actor, 2);
    dt = func_800D8FF8();
    func_800EF934(vec_a, axis, scroll->local_4);
    func_800EF04C(vec_a, scroll->local_3);
    func_800EF934(vec_b, axis, scroll->local_6);
    func_800EF04C(vec_b, scroll->local_5);
    dist = func_800EEAD4(vec_a, vec_b);

if (func_800EECE0(actor->position, scroll->local_5)) {
    sign = (func_800F1DCC(scroll->local_6, scroll->local_4) <= 0.0f ? 1.0f : -1.0f) * direction;
} else {

sign = 1.0f;
}
scroll->local_1[index] += dist * 12.0f * sign * 64.0f * dt;
pos_int = scroll->local_1[index];
if (pos_int >= 8192) {
    scroll->local_1[index] -= 8192.0f;
} else if (pos_int < 0) {
    scroll->local_1[index] += 8192.0f;
}
scroll->local_2[index] = (s32) scroll->local_1[index];
scroll->local_0[index] += dist * 0.01333333366f * sign * 57.29578018f;
}

void func_80804238_chintrochar(actor) Actor *actor;
{
    s32 model;

    model = func_801065A4(actor);
    if (model) {
        _glid_entrypoint_0(model, 1, _chintrochar_entrypoint_1, actor->unk0);
        _glid_entrypoint_0(model, 2, _chintrochar_entrypoint_1, actor->unk0);
    }
}

void chintrochar_entrypoint_1(s32 which, VertexShiftRecord *src, VertexShiftRecord *dst,
                              s32 count, Unk80132ED0 *owner)
{
    u8 *state;
    s32 offset;
    VertexShiftRecord *end;

    state = func_80100094(func_80106790(owner), 2);
    switch (which) {
        case 1:
            offset = *(s16 *) (state + 0xE0);
            end = src + count;
            for (; src < end; src++, dst++) {
                dst->unkA = src->unkA + offset;
            }
            break;
        case 2:
            offset = *(s16 *) (state + 0xE0 + 2);
            end = src + count;
            for (; src < end; src++, dst++) {
                dst->unkA = src->unkA + offset;
            }
    }
}

extern void func_80107C2C();
u8 D_80804790_chintrochar[2784] = {
    0x6, 0x31, 0x0,  0x0,  0x0,  0x1,  0x0,  0x0,  0x0,  0x0,  0x0,  0x48, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x6,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xA4, 0x0,  0x0,  0x0,  0x2,  0x0,  0x0,  0x0,  0x0,  0x10, 0x48, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x6,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x6, 0x32, 0x0,  0x0,  0x0,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,  0x48, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x6,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xA8, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x90, 0x6,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xA8, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x80, 0xE,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xA7, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x10, 0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x9, 0xAE, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x10, 0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xA6, 0x0,  0x0,  0x0,  0x4,  0x0,  0x0,  0x0,  0x0,  0x10, 0x48, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0xE,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xA5, 0x0,  0x0,  0x0,  0x3,  0x0,  0x0,  0x0,  0x0,  0x10, 0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x7, 0x7,  0x0,  0x0,  0x0,  0x0,  0x0,  0x7F, 0x20, 0x0,  0x5,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0xA,  0x40, 0x0,  0x0,  0x0,  0x0,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xA9, 0x0,  0x0,  0x0,  0x12, 0x0,  0x0,  0x20, 0x0,  0x4,  0x48, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xAB, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x2,  0x14, 0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0xE,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xAC, 0x0,  0x0,  0x0,  0x0,  0x0,  0x7C, 0x0,  0x40, 0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x90, 0x6,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xAC, 0x0,  0x0,  0x0,  0x5,  0x0,  0x0,  0x0,  0x0,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x6,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xAD, 0x0,  0x0,  0x0,  0x6,  0x0,  0x0,  0x0,  0x0,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xAE, 0x0,  0x0,  0x0,  0x7,  0x0,  0x79, 0x20, 0x0,  0x1,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x8,  0x0,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xB0, 0x0,  0x0,  0x0,  0xC,  0x0,  0x7A, 0x20, 0x0,  0x1,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2C, 0x41, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xB5, 0x0,  0x0,  0x0,  0xD,  0x0,  0x7C, 0x20, 0x0,  0x1,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0xA,  0x40, 0x0,  0x0,  0x0,  0x0,  0x41, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xAF, 0x0,  0x0,  0x0,  0x7,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xAD, 0x0,  0x0,  0x0,  0x8,  0x0,  0x0,  0x0,  0x0,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xB1, 0x0,  0x0,  0x0,  0x9,  0x0,  0x0,  0x20, 0x0,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xB2, 0x0,  0x0,  0x0,  0xF,  0x0,  0x0,  0x20, 0x0,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xB3, 0x0,  0x0,  0x0,  0xE,  0x0,  0x0,  0x30, 0x0,  0x4,  0x48, 0x80, 0x1,  0x0,  0x10,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xB4, 0x0,  0x0,  0x0,  0xB,  0x0,  0x0,  0x0,  0x0,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xAD, 0x0,  0x0,  0x0,  0xA,  0x0,  0x0,  0x0,  0x0,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xB7, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x20, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xB8, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xBA, 0x0,  0x0,  0x0,  0x10, 0x0,  0x0,  0x0,  0x0,  0x18, 0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xBB, 0x0,  0x0,  0x0,  0x11, 0x0,  0x7D, 0x0,  0x0,  0x1,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x9,  0xC0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xBD, 0x0,  0x0,  0x0,  0x0,  0x0,  0x7E, 0x0,  0x0,  0x1,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x48, 0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xA9, 0x0,  0x0,  0x0,  0x13, 0x0,  0x0,  0x0,  0x0,  0x4,  0x40, 0x80, 0x80, 0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xBE, 0x0,  0x0,  0x0,  0x17, 0x0,  0x80, 0x0,  0x0,  0x5,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x8,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xAD, 0x0,  0x0,  0x0,  0x14, 0x0,  0x0,  0x0,  0x0,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x6, 0x5E, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x4,  0x8,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x6, 0x71, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x4,  0x8,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x8,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xBF, 0x0,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x0,  0x4,  0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0xF0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xBF, 0x0,  0x0,  0x0,  0x16, 0x0,  0x0,  0x0,  0x0,  0x4,  0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xC2, 0x0,  0x0,  0x0,  0x18, 0x0,  0x0,  0x0,  0x0,  0x4,  0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xC3, 0x0,  0x0,  0x0,  0xD,  0x0,  0x7C, 0x0,  0x0,  0x1,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x8,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0xCC, 0xCC, 0xCD,
    0x8, 0xBF, 0x0,  0x0,  0x0,  0x19, 0x0,  0x0,  0x0,  0x0,  0x4,  0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x7, 0x7,  0x0,  0x0,  0x0,  0x0,  0x0,  0x7F, 0x0,  0x0,  0x1,  0x28, 0x80, 0x0,  0x0,  0x10,
    0x0, 0x0,  0x0,  0x40, 0xAA, 0xAA, 0xAA, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xC5, 0x0,  0x0,  0x0,  0xC,  0x0,  0x7A, 0x20, 0x0,  0x1,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xBA, 0x0,  0x0,  0x0,  0x10, 0x0,  0x0,  0x30, 0x0,  0xC,  0x48, 0x80, 0x1,  0x0,  0x0,
    0x0, 0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xC6, 0x0,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x0,  0x14, 0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xC7, 0x0,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x0,  0x14, 0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0x97, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x5,  0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0x80, 0x0,  0x0,
    0x8, 0x98, 0x0,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x0,  0x5,  0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xC8, 0x0,  0x0,  0x0,  0x1A, 0x0,  0x0,  0x20, 0x0,  0x14, 0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0x40, 0x0,  0x0,
    0x8, 0xB0, 0x0,  0x0,  0x0,  0xC,  0x0,  0x7A, 0x20, 0x0,  0x1,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x8,  0x2D, 0x41, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,
    0x8, 0xC9, 0x0,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x0,  0x14, 0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xCA, 0x0,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x2,  0x14, 0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0x96, 0x0,  0x0,  0x0,  0x1C, 0x0,  0xAE, 0x0,  0x0,  0x5,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0x80, 0x0,  0x0,
    0x9, 0xE,  0x0,  0x0,  0x0,  0xD,  0x0,  0x0,  0x0,  0x0,  0x1,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x8,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,
    0x9, 0xB,  0x0,  0x0,  0x0,  0xD,  0x0,  0xAF, 0x20, 0x0,  0x1,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x8,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,
    0x9, 0xD,  0x0,  0x0,  0x0,  0x0,  0x0,  0x7F, 0x20, 0x0,  0x5,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0xA,  0x40, 0x0,  0x0,  0x0,  0x0,  0x40, 0x0,  0x0,  0x0,  0x40, 0x0,  0x0,  0x0,
    0x8, 0xBB, 0x0,  0x0,  0x0,  0x11, 0x0,  0x7D, 0x20, 0x0,  0x1,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x9,  0xC0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,
    0x8, 0xBD, 0x0,  0x0,  0x0,  0x0,  0x0,  0x7E, 0x20, 0x0,  0x1,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x48, 0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0x40, 0x0,  0x0,
    0x8, 0xBE, 0x0,  0x0,  0x0,  0x17, 0x0,  0x80, 0x20, 0x0,  0x5,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x8,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0x20, 0x0,  0x0,
    0x9, 0x39, 0x0,  0x0,  0x0,  0x1B, 0x0,  0x0,  0x0,  0x0,  0x4,  0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xBF, 0x0,  0x0,  0x0,  0x1B, 0x0,  0x0,  0x0,  0x0,  0x4,  0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0xF0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x9, 0x3A, 0x0,  0x0,  0x0,  0x1B, 0x0,  0x0,  0x0,  0x0,  0x4,  0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x9, 0x3B, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x1,  0x40, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,
    0x7, 0xD6, 0x0,  0x0,  0x0,  0xD,  0x0,  0x6F, 0x20, 0x0,  0x1,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x8,  0x8,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,
    0x6, 0x75, 0x0,  0x0,  0x0,  0x1D, 0x0,  0x40, 0x20, 0x0,  0x1,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x8,  0x9,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,
    0x9, 0xB5, 0x0,  0x0,  0x0,  0x0,  0x0,  0x80, 0x20, 0x0,  0x5,  0x68, 0x80, 0x80, 0x0,  0x0,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x6, 0xDB, 0x0,  0x0,  0x0,  0x0,  0x0,  0x7C, 0x0,  0x0,  0x5,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0xA,  0x0,  0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x6, 0x42, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x2,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x80, 0xE,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x9, 0xB4, 0x0,  0x0,  0x0,  0x1E, 0x0,  0x7F, 0x20, 0x0,  0x5,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0xA,  0x0,  0x0,  0x0,  0x0,  0x0,  0x41, 0x0,  0x0,  0x0,  0x40, 0x0,  0x0,  0x0,
    0x5, 0xFD, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x20, 0x0,  0x4,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x8, 0xAE, 0x0,  0x0,  0x0,  0x7,  0x0,  0x79, 0x20, 0x0,  0x1,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x8,  0x0,  0x40, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0xA6, 0x66, 0x66,
    0x8, 0xB0, 0x0,  0x0,  0x0,  0xC,  0x0,  0x7A, 0x20, 0x0,  0x1,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x8,  0x2C, 0x41, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,
    0x6, 0x90, 0x0,  0x0,  0x0,  0x0,  0x0,  0x7C, 0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2,  0x0,  0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x9, 0xAF, 0x0,  0x0,  0x0,  0x1F, 0x0,  0x0,  0x0,  0x0,  0x4,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2,  0x0,  0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x9, 0xAD, 0x0,  0x0,  0x0,  0x20, 0x0,  0x0,  0x0,  0x0,  0x4,  0x60, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2,  0x6,  0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x6, 0x43, 0xC,  0x33, 0x0,  0x0,  0x0,  0x11, 0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x4,  0x2,  0x40, 0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x6, 0x43, 0xC,  0x35, 0x0,  0x0,  0x0,  0x11, 0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x4,  0x2,  0x40, 0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x6, 0x43, 0xC,  0x37, 0x0,  0x0,  0x0,  0x11, 0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x4,  0x2,  0x40, 0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x6, 0x43, 0xC,  0x38, 0x0,  0x0,  0x0,  0x11, 0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x4,  0x2,  0x40, 0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x6, 0x43, 0xC,  0x39, 0x0,  0x0,  0x0,  0x11, 0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x4,  0x2,  0x40, 0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x6, 0x43, 0xC,  0x32, 0x0,  0x0,  0x0,  0x11, 0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x4,  0x2,  0x40, 0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x6, 0x43, 0xC,  0x31, 0x0,  0x0,  0x0,  0x11, 0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x4,  0x2,  0x40, 0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x6, 0x43, 0xC,  0x36, 0x0,  0x0,  0x0,  0x11, 0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x4,  0x2,  0x40, 0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x6, 0x43, 0xC,  0x34, 0x0,  0x0,  0x0,  0x11, 0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x4,  0x2,  0x40, 0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x9, 0x19, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x4,  0x68, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0xA,  0x0,  0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x9, 0xB3, 0x0,  0x0,  0x0,  0x21, 0x0,  0x0,  0x0,  0x2,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2,  0x0,  0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x6, 0x1C, 0x0,  0x0,  0x0,  0xC,  0x0,  0x0,  0x0,  0x0,  0x5,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2,  0x0,  0x0,  0x0,  0x0,  0x0,  0x42, 0x48, 0x0,  0x0,  0x3F, 0x4C, 0xCC, 0xCD,
    0x8, 0xB0, 0x0,  0x0,  0x0,  0x22, 0x0,  0x7A, 0x20, 0x0,  0x1,  0x28, 0x0,  0x0,  0x0,  0x0,
    0x0, 0x0,  0x2C, 0x41, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
f32 D_80805270_chintrochar[3] = {0.166f, 0.5f, 0.833f};
f32 D_8080527C_chintrochar[3] = {0.333f, 0.666f, 1.0f};
f32 D_80805288_chintrochar[7] = {0.2064f, 0.276f, 0.5012f, 0.6554f, 0.9045f, 0.9581f, 0.9987f};
f32 D_808052A4_chintrochar[2] = {0.02f, 0.5316f};
f32 D_808052AC_chintrochar[2] = {0.252f, 0.75f};
f32 D_808052B4_chintrochar[3] = {0.1147f, 0.1985f, 0.28f};
f32 D_808052C0_chintrochar[6] = {0.0522f, 0.0963f, 0.1513f, 0.5267f, 0.5678f, 0.6142f};
f32 D_808052D8_chintrochar[4] = {0.0f, 0.253f, 0.5065f, 0.7577f};
f32 D_808052E8_chintrochar[4] = {0.1247f, 0.385f, 0.6286f, 0.8795f};
u8 D_808052F8_chintrochar[16] = {0x0, 0x21, 0x0, 0x1D, 0x0, 0x1E, 0x0, 0x1,
                                 0x5, 0xDC, 0xD, 0xAC, 0x0, 0x0,  0x0, 0x0};
u8 D_80805308_chintrochar[8] = {0x0, 0x44, 0x0, 0x45, 0x0, 0x46, 0x0, 0x0};
u8 D_80805310_chintrochar[8] = {0x0, 0x47, 0x0, 0x48, 0x0, 0x49, 0x0, 0x0};
s32 D_80805318_chintrochar[5] = {0x43180000, 0x42E40000, 0x0, 0x0, 0x0};
int D_8080532C_chintrochar[18] = {0x40317,
                                  -0xFFFE,
                                  0x0,
                                  0x0,
                                  (u32) func_808034C4_chintrochar,
                                  (u32) func_80803A78_chintrochar,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x4,
                                  (u32) func_80800648_chintrochar,
                                  0x0,
                                  0x0,
                                  (u32) func_80800540_chintrochar,
                                  (u32) func_80107C2C,
                                  -0x7FFFFFFE,
                                  (u32) func_80803D0C_chintrochar,
                                  0x0};
s32 D_80805374_chintrochar[2] = {0x9, 0xC};
u8 D_8080537C_chintrochar[12] = {0xC3, 0x96, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC2, 0xC8, 0x0, 0x0};
u8 D_80805388_chintrochar[24] = {0x43, 0x96, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC2, 0xC8, 0x0, 0x0,
                                 0x0,  0x0,  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  0x0,  0x0, 0x0};
