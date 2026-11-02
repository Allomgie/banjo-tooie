#include "common.h"

#define CODEX_VERTEX_SHIFT_RECORD
typedef struct { u8 pad_0[0xC6]; s16 local_0; } IntroExpressionBuffer1506;
extern u8 D_80804790_chintrochar[];
extern void *func_80100094(Actor *, u32);
extern void _suexpression_entrypoint_7();
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _suexpression_entrypoint_3();
extern void _suexpression_entrypoint_6();
extern void _suexpression_entrypoint_5(void *, s32);
extern s16 func_8001B668(s32, s32);
extern void *func_8001B798();
typedef struct { u8 pad[0x7B]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS123;
typedef struct { u8 pad[0x70]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS112;
typedef struct { u8 pad[0x71]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS113;
typedef struct { u8 pad[0x94]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS148;
typedef struct { u32 flags; u8 pad_0[0x1C]; } IntroActorFlags;
extern IntroActorFlags func_80804158_chintrochar[];
extern u8 func_80804160_chintrochar[];
extern void func_80105BE0(Actor *, s32);
extern void func_800ADFE0();
extern void _chanim_entrypoint_6(Actor *);
extern void _anseq_entrypoint_5();
extern void _chblink_entrypoint_3();
extern void func_8001B754();
typedef struct { u8 pad_0[0xCC]; s32 local_0; } IntroContactState;
typedef struct { u8 pad_0[8]; void *local_0; } IntroContact;
extern void func_800EE7F8(f32 *, f32 *);
extern IntroContact *func_800C6A7C(f32 *, f32 *, f32 *, void *);
extern s32 func_800C84B0(void *);
typedef struct { u8 pad[0xCC]; s32 step; } IntroCharacterStep;
extern u8 D_808052F8_chintrochar[];
extern void func_800C4B64(f32);
extern void func_800C4B70(s32);
extern void func_800C4B7C(s32);
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
extern u8 func_8080416C_chintrochar[];
extern u8 D_80805308_chintrochar[];
extern u8 D_8080530E_chintrochar[];
extern u8 D_80805310_chintrochar[];
extern u8 D_80805316_chintrochar[];
extern void func_800E0AFC(s32, s32, f32, f32, f32, f32);
typedef struct { u32 pad_0 : 15; s32 local_0 : 1; u32 pad_1 : 16; u8 pad_2[28]; } IntroCharOption;
extern void func_800B8C50(void);
extern s32 _subaddiefade_entrypoint_0(Actor *);
extern void func_800B8C8C(s32);
extern void func_800B8C98(s32);
extern void func_800B8CB0(s32);
extern void func_800B7F14(Gfx **);
extern void func_800B8F88(Gfx **, s32, void *);
extern void func_800B811C(Gfx **);
extern void func_80102FDC(Actor *, f32);
extern int D_8080532C_chintrochar;
typedef struct { f32 local_0[3]; f32 local_1; } IntroPose1257;
typedef struct { u8 pad_0[0xD0]; f32 local_0[2]; u8 pad_1[0xC]; IntroPose1257 local_1[2]; } IntroInterpolation1257;
typedef struct { u8 **f0; u8 pad[0x78]; u32 pad7C:19; u32 flag:1; u32 rest:12; } IntroS;
extern s32 D_80805374_chintrochar[];
extern void func_800DBEFC();
extern void func_80103014();
typedef struct { u8 pad_0[0xE4]; f32 local_0[3]; f32 local_1; f32 local_2[3]; f32 local_3; } IntroPairedPose;
extern f32 func_800F1DF4(f32 *, f32 *);
extern u8 D_80805388_chintrochar[];
extern u8 D_8080537C_chintrochar[];
extern s32 func_801065A4(Actor *);
extern void _chintrochar_entrypoint_1();
extern void _glid_entrypoint_0(s32, s32, void (*)(), Unk80132ED0 *);
typedef struct { s16 position[3]; u16 unk6; s16 unk8; s16 unkA; u8 padC[4]; } VertexShiftRecord;
extern Actor *func_80106790();
extern void _anseq_entrypoint_2(s16 *, f32, void *, s32, s32);
extern void _anseq_entrypoint_3(s16 *, f32, void *, s32, s32, s32);
typedef struct { u32 b31:1; u32 b30:1; u32 rest:30; } ICBits94;
extern u8 func_80804168_chintrochar[];
extern s32 D_80805318_chintrochar[];
extern void func_801017D0();
typedef struct { f32 local_0[2]; } IntroCharDrawPair;
typedef struct { u8 pad_0[0xD0]; f32 local_0[2]; f32 local_1[2]; s16 local_2[2]; f32 local_3[3]; f32 local_4; f32 local_5[3]; f32 local_6; } IntroTextureScroll1210;
extern f32 func_800D8FF8(void);
extern void func_800EF934(f32 *, void *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
void func_80803E98_chintrochar();
void func_80803F24_chintrochar();
void func_80803F7C_chintrochar();
void func_80804238_chintrochar();
void func_8080071C_chintrochar();
void func_80804054_chintrochar(Actor *param_0, s32 param_1, f32 param_2, void *param_3);

void func_80800000_chintrochar(Actor *param_0)
{
    IntroExpressionBuffer1506 *local_0;
    s32 pad0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_9;
    void *local_5;
    u8 *local_6;
    s16 local_7;

    local_0 = func_80100094(param_0, 2);
    local_6 = D_80804790_chintrochar + param_0->unk74_7 * 0x20;
    local_7 = *(s16 *)(local_6 - 0x63A);
    local_1 = *(s32 *)(local_6 - 0x630);
    _suexpression_entrypoint_7(param_0, 1, local_7);
    if (local_1 & 0x40000) _suexpression_entrypoint_12(func_80100094(param_0, 1), 160.0f, 120.0f);
    if (local_1 & 0x2000) {
        _suexpression_entrypoint_3(0x7B, &local_2, &local_3, &local_4);
        local_9 = local_2 + local_3 + local_4;
        local_0->local_0 = func_8001B668(0, local_9);
        local_5 = func_8001B798(local_0->local_0);
        _suexpression_entrypoint_6(local_5, 0x7B, local_4, local_2, local_3);
        _suexpression_entrypoint_5(local_5, 2);
    }
}

void func_808000FC_chintrochar(param_0) Actor *param_0;
{
    u32 local_0;
    u32 local_1;
    s32 local_2[3];

    local_0 = *(u32 *)(D_80804790_chintrochar + param_0->unk74_7 * 32 - 0x638) & 0x3FFFFFFF;
    local_1 = *(u32 *)(D_80804790_chintrochar + param_0->unk74_7 * 32 - 0x634) & 0x3FFFFFFF;
    if (local_0 & 0x400) { _subaddieDll_entrypoint_0(param_0); }
    if (local_1 & 0x80800000) { ((BitS148 *)(param_0))->b6 = 1; }
    if (local_0 & 0x800000) { ((BitS113 *)(param_0))->b5 = 1; }
    if (local_0 & 8) { ((BitS112 *)(param_0))->b0 = 1; }
    if (local_1 & 0x80000010) {
        ((BitS123 *)(param_0))->b1 = 1;
        local_2[0] = *(D_80804790_chintrochar + param_0->unk74_7 * 32 - 0x62C);
        local_2[1] = *(D_80804790_chintrochar + param_0->unk74_7 * 32 - 0x62B);
        local_2[2] = *(D_80804790_chintrochar + param_0->unk74_7 * 32 - 0x62A);
        _subaddiefade_entrypoint_11(param_0, local_2);
    }
    if ((local_0 & 0x20000)) { func_8010A800(param_0, 2); }
    if ((local_0 & 0x400000)) { func_8010A800(param_0, 3); }
    if (local_0 & 0x100) {
        *((u8 *)param_0 + 0x77) = (*((u8 *)param_0 + 0x77) & ~0xF) | 1;
    }
    func_80108658(param_0, local_0, local_1, 0);
    if ((local_0 & 0x20000)) {
        func_8010A800(param_0, 2);
    } else if ((local_0 & 0x400000)) {
        func_8010A800(param_0, 3);
    } else {
        func_8010A800(param_0, 0);
    }
    if (local_0 & 0x800) { func_8010A63C(param_0); }
}

void func_808002FC_chintrochar(Actor *param_0)
{
    u32 local_0;
    local_0 = func_80804158_chintrochar[param_0->unk74_7].flags & 0x3FFFFFFF;
    if (local_0 & 0x40) param_0->unk0->unk4 = func_800DBFF8();
    if (local_0 & 0x1000) func_80105DFC(param_0);
    if (local_0 & 0x20) *(u16 *)&param_0->unk0->unk10 = func_800AE020();
}

void func_80800398_chintrochar(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 2);
    local_1 = _gldbstring_entrypoint_0(0, 0x186C);
    switch (param_0->unk74_7 - 0x32) {
        case 12:
            func_800E715C(local_0, _gldbstring_entrypoint_1(local_1, 0));
            func_800E715C(local_0 + 0x40, _gldbstring_entrypoint_1(local_1, 1));
            break;
        case 3:
            func_800E715C(local_0, _gldbstring_entrypoint_1(local_1, 2));
            func_800E715C(local_0 + 0x40, _gldbstring_entrypoint_1(local_1, 4));
            func_800E715C(local_0 + 0x80, _gldbstring_entrypoint_1(local_1, 5));
            break;
    }
    _gldbstring_entrypoint_2(0x186C);
}

void func_80800484_chintrochar(u8 *param_0)
{
  s32 temp_s1;
  u8 *temp_v0;
  temp_s1 = *((s32 *) (((char *) (&func_80804160_chintrochar)) + (((((u16) (*((u16 *) (((s8 *) param_0) + 0x76)))) & 0xFFFFFFFFu) >> 7) << 5)));
  func_808000FC_chintrochar();
  temp_v0 = (u8 *) (((char *) (&D_80804790_chintrochar)) + ((((u32) (*((u16 *) (((s8 *) param_0) + 0x76)))) >> 7) << 5));
  func_80103140(param_0, *((u16 *) (((s8 *) temp_v0) - 0x640)), *((u16 *) (((s8 *) temp_v0) - 0x63E)));
  if (temp_s1 & 0x40)
  {
    func_80800000_chintrochar(param_0);
  }
  if (temp_s1 & 0x1000)
  {
    func_80800398_chintrochar(param_0);
  }
  if (temp_s1 & 0x10000)
  {
    func_80803E98_chintrochar(param_0);
  }
  if (temp_s1 & 0x80000)
  {
    func_800DA544(0xD);
  }
}

void func_80800540_chintrochar(Actor *param_0)
{
    u8 *local_1;
    u32 local_0;
    u32 local_2;

    param_0->unk64_19 = 1;
    local_2 = param_0->unk74_7;
    local_0 = *(u32 *)(D_80804790_chintrochar - 0x630 + local_2 * 0x20);
    _chanim_entrypoint_7(param_0, *(s16 *)(D_80804790_chintrochar - 0x63C + local_2 * 0x20));
    func_80100074(param_0, 2, 0x10C);
    local_1 = func_80100094(param_0, 2);
    *(s16 *)(local_1 + 0xC0) = _anseq_entrypoint_6();
    *(s32 *)(local_1 + 0xC8) = 0;
    func_80800484_chintrochar(param_0);
    func_80105BE0(param_0, 1);
    *(s16 *)(local_1 + 0xC2) = local_0 & 1 ? _chblink_entrypoint_1(0) : 0;
    if (local_0 & 0x400) {
        *(s16 *)(local_1 + 0xC4) = _chblink_entrypoint_1(1);
    } else if (local_0 & 0x4000) {
        *(s16 *)(local_1 + 0xC4) = _chblink_entrypoint_1(2);
    } else {
        *(s16 *)(local_1 + 0xC4) = 0;
    }
    func_80108B04(param_0, 0);
}

void func_80800648_chintrochar(Actor *param_0)
{
    u8 *local_0;
    u32 local_1;

    local_0 = func_80100094(param_0, 2);
    local_1 = func_80804158_chintrochar[param_0->unk74_7].flags & 0x3FFFFFFF;
    if ((local_1 & 0x20) && *(s16 *)&param_0->unk0->unk10 != 0) {
        func_800ADFE0(*(s16 *)&param_0->unk0->unk10);
        *(s16 *)&param_0->unk0->unk10 = 0;
    }
    _chanim_entrypoint_6(param_0);
    if (*(s16 *)(local_0 + 0xC0) != 0) {
        _anseq_entrypoint_5(*(s16 *)(local_0 + 0xC0));
    }
    if (*(s16 *)(local_0 + 0xC2) != 0) {
        _chblink_entrypoint_3(*(s16 *)(local_0 + 0xC2));
    }
    if (*(s16 *)(local_0 + 0xC4) != 0) {
        _chblink_entrypoint_3(*(s16 *)(local_0 + 0xC4));
    }
    if (*(s16 *)(local_0 + 0xC6) != 0) {
        func_8001B754(*(s16 *)(local_0 + 0xC6));
    }
}

void func_8080071C_chintrochar(Actor *param_0, s32 param_1)
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

    char *local_0;
    s16 *local_1;
    void *local_2;

    local_0 = (char *)func_80100094(param_0, 2);
    local_1 = _anseq_entrypoint_9(*(s16 *)(local_0 + 0xC0));
    local_2 = param_0->unk0;
    _anseq_entrypoint_0(local_1);

    switch (param_1) {
        case 0x39B:
            {
                s32 local_3;
                for (local_3 = 0; local_3 < 3; local_3++) {
                    _anseq_entrypoint_2(local_1, D_80805270_chintrochar[local_3], _inantab_entrypoint_2, *(s32 *)&local_2, 0);
                }
            }
            {
                s32 local_3;
                for (local_3 = 0; local_3 < 3; local_3++) {
                    _anseq_entrypoint_2(local_1, D_8080527C_chintrochar[local_3], _inantab_entrypoint_2, *(s32 *)&local_2, 1);
                }
            }
            return;

        case 0x39C:
            _anseq_entrypoint_3(local_1, 0.294200003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 6, -1);
            _anseq_entrypoint_3(local_1, 0.905300021f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 7, -1);
            return;

        case 0x264:
            _anseq_entrypoint_2(local_1, 0.0295000002f, _inantab_entrypoint_2, *(s32 *)&local_2, 0);
            _anseq_entrypoint_2(local_1, 0.519900024f, _inantab_entrypoint_2, *(s32 *)&local_2, 1);
            return;

        case 0x44C:
            _anseq_entrypoint_3(local_1, 0.542500019f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 10, -1);
            _anseq_entrypoint_3(local_1, 0.625400007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 10, -1);
            return;

        case 0x455:
            _anseq_entrypoint_3(local_1, 0.107799999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 11, -1);
            _anseq_entrypoint_3(local_1, 0.264299989f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 12, -1);
            _anseq_entrypoint_3(local_1, 0.294f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 13, -1);
            return;

        case 0x4F2:
            _anseq_entrypoint_3(local_1, 0.0957000032f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 136, -1);
            _anseq_entrypoint_3(local_1, 0.151299998f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 136, -1);
            _anseq_entrypoint_3(local_1, 0.223399997f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 136, -1);
            _anseq_entrypoint_3(local_1, 0.304800004f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 137, -1);
            _anseq_entrypoint_3(local_1, 0.371499985f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 137, -1);
            return;

        case 0x4F4:
            _anseq_entrypoint_3(local_1, 0.126800001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 138, -1);
            _anseq_entrypoint_3(local_1, 0.855000019f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 139, -1);
            _anseq_entrypoint_3(local_1, 0.917800009f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 140, -1);
            return;

        case 0x422:
            _anseq_entrypoint_3(local_1, 0.805100024f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 119, -1);
            return;

        case 0x474:
            {
                s32 local_3;
                for (local_3 = 0; local_3 < 7; local_3++) {
                    _anseq_entrypoint_3(local_1, D_80805288_chintrochar[local_3], _indrv_audio_entrypoint_0, *(s32 *)&local_2, 0x64, -1);
                }
            }
            return;

        case 0x40C:
            _anseq_entrypoint_3(local_1, 0.531599998f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 14, -1);
            _anseq_entrypoint_3(local_1, 0.0199999996f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 15, -1);
            return;

        case 0x40D:
            {
                s32 local_3;
                for (local_3 = 0; local_3 < 2; local_3++) {
                    _anseq_entrypoint_3(local_1, D_808052A4_chintrochar[local_3], _indrv_audio_entrypoint_0, *(s32 *)&local_2, 0xE, -1);
                }
            }
            {
                s32 local_3;
                for (local_3 = 0; local_3 < 2; local_3++) {
                    _anseq_entrypoint_3(local_1, D_808052AC_chintrochar[local_3], _indrv_audio_entrypoint_0, *(s32 *)&local_2, 0xF, -1);
                }
            }
            _anseq_entrypoint_3(local_1, 0.17f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 0x10, -1);
            return;

        case 0x463:
            _anseq_entrypoint_3(local_1, 0.570800006f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 17, -1);
            return;

        case 0x466:
            _anseq_entrypoint_3(local_1, 0.100000001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 19, -1);
            _anseq_entrypoint_3(local_1, 0.536000013f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 176, -1);
            _anseq_entrypoint_3(local_1, 0.572700024f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 177, -1);
            _anseq_entrypoint_3(local_1, 0.609200001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 178, -1);
            return;

        case 0x48C:
            _anseq_entrypoint_3(local_1, 0.00999999978f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 120, -1);
            _anseq_entrypoint_3(local_1, 0.579999983f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 103, -2);
            _anseq_entrypoint_3(local_1, 0.699999988f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 176, -2);
            _anseq_entrypoint_3(local_1, 0.730000019f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 177, -2);
            _anseq_entrypoint_3(local_1, 0.75999999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 178, -2);
            return;

        case 0x521:
            _anseq_entrypoint_3(local_1, 0.221799999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 174, -1);
            _anseq_entrypoint_3(local_1, 0.356400013f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 125, -1);
            _anseq_entrypoint_3(local_1, 0.450700015f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 175, -1);
            _anseq_entrypoint_3(local_1, 0.70539999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 126, -1);
            return;

        case 0x536:
            _anseq_entrypoint_3(local_1, 0.0469000004f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 159, -1);
            _anseq_entrypoint_3(local_1, 0.103399999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 160, -1);
            _anseq_entrypoint_3(local_1, 0.1074f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 156, -1);
            _anseq_entrypoint_3(local_1, 0.203899994f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 160, -1);
            _anseq_entrypoint_3(local_1, 0.207900003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 157, -1);
            _anseq_entrypoint_3(local_1, 0.3116f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 160, -1);
            _anseq_entrypoint_3(local_1, 0.315600008f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 158, -1);
            _anseq_entrypoint_3(local_1, 0.441000015f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 161, -1);
            _anseq_entrypoint_3(local_1, 0.444999993f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 156, -1);
            _anseq_entrypoint_3(local_1, 0.609600008f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 161, -1);
            _anseq_entrypoint_3(local_1, 0.613600016f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 157, -1);
            _anseq_entrypoint_3(local_1, 0.760599971f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 161, -1);
            _anseq_entrypoint_3(local_1, 0.764599979f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 158, -1);
            _anseq_entrypoint_3(local_1, 0.905499995f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 162, -1);
            _anseq_entrypoint_3(local_1, 0.909500003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 131, -1);
            return;

        case 0xB4:
            _anseq_entrypoint_2(local_1, 0.226199999f, _inantab_entrypoint_2, *(s32 *)&local_2, 0);
            _anseq_entrypoint_2(local_1, 0.716499984f, _inantab_entrypoint_2, *(s32 *)&local_2, 1);
            return;

        case 0x462:
            _anseq_entrypoint_2(local_1, 0.226199999f, _inantab_entrypoint_2, *(s32 *)&local_2, 0);
            _anseq_entrypoint_2(local_1, 0.716499984f, _inantab_entrypoint_2, *(s32 *)&local_2, 1);
            return;

        case 0x465:
            {
                s32 local_3;
                for (local_3 = 0; local_3 < 3; local_3++) {
                    _anseq_entrypoint_3(local_1, D_808052B4_chintrochar[local_3], _indrv_audio_entrypoint_0, *(s32 *)&local_2, 0x17, -1);
                }
            }
            return;

        case 0x467:
            _anseq_entrypoint_3(local_1, 0.0423000008f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 24, -1);
            _anseq_entrypoint_3(local_1, 0.173999995f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 25, -1);
            _anseq_entrypoint_3(local_1, 0.229200006f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 25, -1);
            return;

        case 0x468:
            _anseq_entrypoint_3(local_1, 0.67869997f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 26, -1);
            _anseq_entrypoint_3(local_1, 0.961199999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 27, -1);
            _anseq_entrypoint_3(local_1, 0.966799974f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 25, -1);
            _anseq_entrypoint_3(local_1, 0.980000019f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 28, -1);
            return;

        case 0x46A:
            _anseq_entrypoint_3(local_1, 0.108999997f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 29, -1);
            _anseq_entrypoint_3(local_1, 0.2597f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 25, -1);
            _anseq_entrypoint_3(local_1, 0.228060007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 25, -1);
            return;

        case 0x470:
            _anseq_entrypoint_3(local_1, 0.459199995f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 30, -1);
            return;

        case 0x51F:
            _anseq_entrypoint_3(local_1, 0.0588000007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 144, -1);
            _anseq_entrypoint_3(local_1, 0.063000001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 156, -1);
            _anseq_entrypoint_3(local_1, 0.220699996f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 144, -1);
            _anseq_entrypoint_3(local_1, 0.225999996f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 158, -1);
            _anseq_entrypoint_3(local_1, 0.384799987f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 144, -1);
            _anseq_entrypoint_3(local_1, 0.388999999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 157, -1);
            _anseq_entrypoint_3(local_1, 0.544499993f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 144, -1);
            _anseq_entrypoint_3(local_1, 0.549499989f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 156, -1);
            _anseq_entrypoint_3(local_1, 0.700699985f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 144, -1);
            _anseq_entrypoint_3(local_1, 0.705900013f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 157, -1);
            _anseq_entrypoint_3(local_1, 0.886699975f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 145, -1);
            _anseq_entrypoint_3(local_1, 0.890699983f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 131, -1);
            return;

        case 0x46B:
            {
                s32 local_3;
                for (local_3 = 0; local_3 < 6; local_3++) {
                    _anseq_entrypoint_3(local_1, D_808052C0_chintrochar[local_3], _indrv_audio_entrypoint_0, *(s32 *)&local_2, 0x1F, -1);
                }
            }
            return;

        case 0x46C:
            _anseq_entrypoint_3(local_1, 0.0384000018f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 32, -1);
            return;

        case 0x46E:
            _anseq_entrypoint_3(local_1, 0.803799987f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 33, -1);
            return;

        case 0x513:
            _anseq_entrypoint_3(local_1, 0.214699998f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 147, -1);
            _anseq_entrypoint_3(local_1, 0.843299985f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 148, -1);
            return;

        case 0x519:
            _anseq_entrypoint_3(local_1, 0.699999988f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 166, -1);
            _anseq_entrypoint_3(local_1, 0.915199995f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 151, -1);
            _anseq_entrypoint_3(local_1, 0.915199995f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 170, -1);
            return;

        case 0x511:
            _anseq_entrypoint_3(local_1, 0.668600023f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 152, -1);
            return;

        case 0x512:
            _anseq_entrypoint_3(local_1, 0.816399992f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 153, -1);
            _anseq_entrypoint_3(local_1, 0.905900002f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 153, -1);
            _anseq_entrypoint_3(local_1, 0.997200012f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 153, -1);
            _anseq_entrypoint_3(local_1, 0.148300007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 153, -1);
            _anseq_entrypoint_3(local_1, 0.254299998f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 153, -1);
            return;

        case 0x4B0:
            _anseq_entrypoint_2(local_1, 0.0555999987f, _inantab_entrypoint_2, *(s32 *)&local_2, 0);
            _anseq_entrypoint_2(local_1, 0.559400022f, _inantab_entrypoint_2, *(s32 *)&local_2, 1);
            return;

        case 0x3AB:
            _anseq_entrypoint_3(local_1, 0.131200001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.1602f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.217199996f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.230599999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 91, -1);
            _anseq_entrypoint_3(local_1, 0.251199991f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.257800013f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.272500008f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 91, -1);
            _anseq_entrypoint_3(local_1, 0.282700002f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.291299999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.294800013f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.310900003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 91, -1);
            _anseq_entrypoint_3(local_1, 0.317600012f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.343300015f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.353899986f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.377999991f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 91, -1);
            _anseq_entrypoint_3(local_1, 0.400299996f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.415399998f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            return;

        case 0x410:
            _anseq_entrypoint_3(local_1, 0.2456f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.261299998f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.266400009f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.277700007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 91, -1);
            _anseq_entrypoint_3(local_1, 0.288300008f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.296499997f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.314099997f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 91, -1);
            _anseq_entrypoint_3(local_1, 0.34799999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.36680001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 91, -1);
            _anseq_entrypoint_3(local_1, 0.390799999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            _anseq_entrypoint_3(local_1, 0.405200005f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 34, -1);
            return;

        case 0x40F:
            _anseq_entrypoint_3(local_1, 0.633099973f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 39, -1);
            _anseq_entrypoint_3(local_1, 0.681800008f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 39, -1);
            _anseq_entrypoint_3(local_1, 0.721700013f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 39, -1);
            _anseq_entrypoint_3(local_1, 0.721700013f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 39, -1);
            return;

        case 0x411:
            _anseq_entrypoint_3(local_1, 0.69630003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 41, -1);
            _anseq_entrypoint_3(local_1, 0.99000001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 43, -1);
            return;

        case 0x447:
            _anseq_entrypoint_3(local_1, 0.0f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 44, -1);
            _anseq_entrypoint_3(local_1, 0.349999994f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 45, -1);
            _anseq_entrypoint_3(local_1, 0.436300009f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 46, -1);
            _anseq_entrypoint_3(local_1, 0.791199982f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 48, -1);
            return;

        case 0x414:
            _anseq_entrypoint_2(local_1, 0.6171f, _inantab_entrypoint_2, *(s32 *)&local_2, 0);
            _anseq_entrypoint_2(local_1, 0.0604000017f, _inantab_entrypoint_2, *(s32 *)&local_2, 1);
            return;

        case 0x415:
            _anseq_entrypoint_2(local_1, 0.6171f, _inantab_entrypoint_2, *(s32 *)&local_2, 0);
            _anseq_entrypoint_2(local_1, 0.0604000017f, _inantab_entrypoint_2, *(s32 *)&local_2, 1);
            return;

        case 0x417:
            _anseq_entrypoint_3(local_1, 0.236300007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 53, -1);
            _anseq_entrypoint_3(local_1, 0.236300007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 92, -1);
            return;

        case 0x418:
            _anseq_entrypoint_3(local_1, 0.734600008f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 54, -1);
            return;

        case 0x41C:
            _anseq_entrypoint_3(local_1, 0.649999976f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 55, -1);
            return;

        case 0x421:
            _anseq_entrypoint_3(local_1, 0.0f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 56, -1);
            return;

        case 0x425:
            _anseq_entrypoint_3(local_1, 0.0975999981f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 57, -1);
            return;

        case 0x457:
            _anseq_entrypoint_3(local_1, 0.551800013f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 58, -1);
            _anseq_entrypoint_3(local_1, 0.628799975f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 58, -1);
            _anseq_entrypoint_3(local_1, 0.708700001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 58, -1);
            _anseq_entrypoint_3(local_1, 0.914699972f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 60, -1);
            return;

        case 0x45A:
            _anseq_entrypoint_3(local_1, 0.360700011f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 59, -1);
            _anseq_entrypoint_3(local_1, 0.685299993f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 61, -1);
            _anseq_entrypoint_3(local_1, 0.75029999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 61, -1);
            _anseq_entrypoint_3(local_1, 0.805000007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 61, -1);
            return;

        case 0x45E:
            _anseq_entrypoint_3(local_1, 0.360700011f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 59, -1);
            _anseq_entrypoint_3(local_1, 0.685299993f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 61, -1);
            _anseq_entrypoint_3(local_1, 0.75029999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 61, -1);
            _anseq_entrypoint_3(local_1, 0.805000007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 61, -1);
            return;

        case 0x50E:
            _anseq_entrypoint_3(local_1, 0.360700011f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 59, -1);
            _anseq_entrypoint_3(local_1, 0.685299993f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 61, -1);
            _anseq_entrypoint_3(local_1, 0.75029999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 61, -1);
            _anseq_entrypoint_3(local_1, 0.805000007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 61, -1);
            return;

        case 0x4F1:
            _anseq_entrypoint_3(local_1, 0.240400001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 130, -1);
            return;

        case 0x41A:
            _anseq_entrypoint_2(local_1, 0.491699994f, _inantab_entrypoint_2, *(s32 *)&local_2, 0);
            _anseq_entrypoint_2(local_1, 0.982299984f, _inantab_entrypoint_2, *(s32 *)&local_2, 1);
            return;

        case 0x41E:
            _anseq_entrypoint_3(local_1, 0.0434999987f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 64, -1);
            _anseq_entrypoint_3(local_1, 0.374799997f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 65, -1);
            return;

        case 0x420:
            _anseq_entrypoint_3(local_1, 0.111199997f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 66, -1);
            return;

        case 0x45B:
            _anseq_entrypoint_3(local_1, 0.0f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 69, -1);
            return;

        case 0x45C:
            _anseq_entrypoint_3(local_1, 0.342299998f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 70, -1);
            _anseq_entrypoint_3(local_1, 0.631600022f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 71, -1);
            _anseq_entrypoint_3(local_1, 0.919499993f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 71, -1);
            return;

        case 0x501:
            _anseq_entrypoint_7(local_1, 1);
            _anseq_entrypoint_3(local_1, 0.747300029f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 128, -1);
            return;

        case 0x446:
            _anseq_entrypoint_3(local_1, 0.320100009f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 72, -1);
            _anseq_entrypoint_3(local_1, 0.661000013f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 72, -1);
            return;

        case 0x44F:
            _anseq_entrypoint_2(local_1, 0.0f, _inantab_entrypoint_2, *(s32 *)&local_2, 0);
            _anseq_entrypoint_2(local_1, 0.5f, _inantab_entrypoint_2, *(s32 *)&local_2, 1);
            return;

        case 0x450:
            _anseq_entrypoint_3(local_1, 0.732400000f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 0x4C, -1);
            {
                s32 local_3;
                for (local_3 = 0; local_3 < 4; local_3++) {
                    _anseq_entrypoint_2(local_1, D_808052D8_chintrochar[local_3], _inantab_entrypoint_2, *(s32 *)&local_2, 0);
                }
            }
            {
                s32 local_3;
                for (local_3 = 0; local_3 < 4; local_3++) {
                    _anseq_entrypoint_2(local_1, D_808052E8_chintrochar[local_3], _inantab_entrypoint_2, *(s32 *)&local_2, 1);
                }
            }
            return;

        case 0x451:
            _anseq_entrypoint_3(local_1, 0.0351999998f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 77, -1);
            _anseq_entrypoint_3(local_1, 0.0623000003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 78, -1);
            _anseq_entrypoint_3(local_1, 0.0623000003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 79, -1);
            _anseq_entrypoint_3(local_1, 0.440800011f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 82, -1);
            return;

        case 0x492:
            _anseq_entrypoint_3(local_1, 0.620599985f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 83, -1);
            _anseq_entrypoint_3(local_1, 0.686100006f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 83, -1);
            _anseq_entrypoint_3(local_1, 0.763100028f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 83, -1);
            _anseq_entrypoint_3(local_1, 0.932200015f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 85, -1);
            return;

        case 0x4FC:
            _anseq_entrypoint_3(local_1, 0.306400001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 121, -1);
            return;

        case 0x4FE:
            _anseq_entrypoint_3(local_1, 0.231900007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 122, -1);
            return;

        case 0x500:
            _anseq_entrypoint_7(local_1, 1);
            _anseq_entrypoint_3(local_1, 0.345600009f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 123, -1);
            return;

        case 0x190:
            _anseq_entrypoint_3(local_1, 0.550000012f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 102, -1);
            return;

        case 0x1E6:
            _anseq_entrypoint_2(local_1, 0.0f, _inantab_entrypoint_2, *(s32 *)&local_2, 0);
            _anseq_entrypoint_2(local_1, 0.5f, _inantab_entrypoint_2, *(s32 *)&local_2, 1);
            return;

        case 0x1E9:
            _anseq_entrypoint_3(local_1, 0.100000001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 101, -1);
            return;

        case 0x45F:
            _anseq_entrypoint_2(local_1, 0.400999993f, _inantab_entrypoint_2, *(s32 *)&local_2, 0);
            _anseq_entrypoint_2(local_1, 0.897800028f, _inantab_entrypoint_2, *(s32 *)&local_2, 1);
            return;

        case 0x460:
            _anseq_entrypoint_3(local_1, 0.783800006f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 89, -1);
            _anseq_entrypoint_3(local_1, 0.862600029f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 90, -1);
            return;

        case 0x538:
            _anseq_entrypoint_3(local_1, 0.0566999987f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 167, -1);
            _anseq_entrypoint_3(local_1, 0.0566999987f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 157, -1);
            _anseq_entrypoint_3(local_1, 0.245800003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 168, -1);
            _anseq_entrypoint_3(local_1, 0.245800003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 160, -1);
            _anseq_entrypoint_3(local_1, 0.245800003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 156, -1);
            _anseq_entrypoint_3(local_1, 0.344599992f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 168, -1);
            _anseq_entrypoint_3(local_1, 0.344599992f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 158, -1);
            _anseq_entrypoint_3(local_1, 0.344599992f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 160, -1);
            _anseq_entrypoint_3(local_1, 0.46540001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 168, -1);
            _anseq_entrypoint_3(local_1, 0.46540001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 156, -1);
            _anseq_entrypoint_3(local_1, 0.46540001f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 160, -1);
            _anseq_entrypoint_3(local_1, 0.584800005f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 168, -1);
            _anseq_entrypoint_3(local_1, 0.584800005f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 157, -1);
            _anseq_entrypoint_3(local_1, 0.584800005f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 160, -1);
            _anseq_entrypoint_3(local_1, 0.675800025f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 168, -1);
            _anseq_entrypoint_3(local_1, 0.675800025f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 158, -1);
            _anseq_entrypoint_3(local_1, 0.675800025f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 160, -1);
            _anseq_entrypoint_3(local_1, 0.824400008f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 169, -1);
            _anseq_entrypoint_3(local_1, 0.824400008f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 156, -1);
            _anseq_entrypoint_3(local_1, 0.824400008f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 162, -1);
            return;

        case 0x523:
            _anseq_entrypoint_3(local_1, 0.5449f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 120, -1);
            return;

        case 0x4DC:
            _anseq_entrypoint_3(local_1, 0.00999999978f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 162, -1);
            _anseq_entrypoint_3(local_1, 0.310000002f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 131, -2);
            return;

        case 0x4EC:
            _anseq_entrypoint_3(local_1, 0.0458999984f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 132, -1);
            _anseq_entrypoint_3(local_1, 0.81190002f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 133, -1);
            _anseq_entrypoint_3(local_1, 0.866100013f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 133, -1);
            return;

        case 0x4ED:
            _anseq_entrypoint_3(local_1, 0.711399972f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 134, -1);
            return;

        case 0x502:
            _anseq_entrypoint_3(local_1, 0.216900006f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 141, -1);
            _anseq_entrypoint_3(local_1, 0.554799974f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 143, -1);
            return;

        case 0x533:
            _anseq_entrypoint_3(local_1, 0.0621000007f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 163, -1);
            _anseq_entrypoint_3(local_1, 0.156900004f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 164, -1);
            _anseq_entrypoint_3(local_1, 0.554700017f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 164, -1);
            _anseq_entrypoint_3(local_1, 0.910000026f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 165, -4);
            _anseq_entrypoint_3(local_1, 0.910000026f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 171, -4);
            return;

        case 0x535:
            _anseq_entrypoint_3(local_1, 0.649999976f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 165, -1);
            _anseq_entrypoint_3(local_1, 0.649999976f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 171, -1);
            return;

        case 0x50A:
            _anseq_entrypoint_3(local_1, 0.104900002f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 155, -1);
            _anseq_entrypoint_3(local_1, 0.276600003f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 155, -1);
            _anseq_entrypoint_3(local_1, 0.449600011f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 155, -1);
            return;

        case 0x53B:
            _anseq_entrypoint_3(local_1, 0.174400002f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 172, -1);
            _anseq_entrypoint_3(local_1, 0.610700011f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 172, -1);
            return;

        case 0x540:
            _anseq_entrypoint_3(local_1, 0.660000026f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 179, -1);
            return;

        case 0x541:
            _anseq_entrypoint_3(local_1, 0.127299994f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 180, -1);
            _anseq_entrypoint_3(local_1, 0.200800002f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 180, -1);
            _anseq_entrypoint_3(local_1, 0.243799999f, _indrv_audio_entrypoint_0, *(s32 *)&local_2, 180, -1);
            return;

        case 0xB3:
            return;

        case 0x1E7:
            return;

        case 0x39D:
        case 0x39E:
        case 0x39F:
        case 0x3A0:
        case 0x3A1:
        case 0x3A2:
        case 0x3A3:
        case 0x3A4:
        case 0x3A5:
        case 0x3A6:
        case 0x3A7:
        case 0x3A8:
        case 0x3A9:
        case 0x3AA:
        case 0x4A0:
        case 0x4AF:
        case 0x408:
        case 0x445:
        case 0x4DB:
        default:
            return;
    }
}

void func_80803388_chintrochar(Actor *param_0, IntroContactState *param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    IntroContact *local_4;
    func_800EE7F8(local_1, param_0->position);
    func_800EE7F8(local_0, param_0->position);
    local_1[1] -= 100.0f;
    local_0[1] += 100.0f;
    local_4 = func_800C6A7C(local_0, local_1, local_2, param_0->unk14);
    if (local_4) param_1->local_0 = func_800C84B0(local_4->local_0);
}

void func_80803418_chintrochar(Actor *param_0, s32 param_1)
{
    IntroCharacterStep *local_0;
    s32 local_1;
    f32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 2);
    func_80803388_chintrochar(param_0, local_0);
    if (_fxstep_entrypoint_15(local_0->step, param_1 == 0 ? 0 : 1,
        &local_1, &local_3, &local_2)) {
        func_800C4B64(local_2);
        func_800C4B70(local_3);
        func_800C4B7C(local_1);
        func_8010D930(2, *(u32 *)((u8 *)param_0 + 0x70) & 1,
            param_0->position, D_808052F8_chintrochar);
    }
}

void func_808034C4_chintrochar(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    f32 local_5;
    s32 local_6;
    Vec3f local_3;
    Vec3f local_4;
    s32 local_7;
    local_0 = (u8 *)func_80100094(param_0, 2);
    local_1 = _anseq_entrypoint_9(*(s16 *)(local_0 + 0xC0));
    local_2 = *(s32 *)(func_80804160_chintrochar + param_0->unk74_7 * 0x20);
    func_8010588C(param_0);
    if (local_2 & 0x100) {
        param_0->rotation[0] = 0.0f;
    }
    if (local_2 & 0x10000) {
        func_80803F7C_chintrochar(param_0);
    }
    if (local_2 & 0x20000) {
        for (local_6 = 0; local_6 < 2; local_6++) {
            func_80803F24_chintrochar(param_0, func_80106790(((s32 *)(local_0 + 0x104))[local_6]), local_6);
        }
    }
    local_7 = func_801022E4(param_0);
    if (local_7 != *(s32 *)(local_0 + 0xC8)) {
        *(s32 *)(local_0 + 0xC8) = local_7;
        func_8080071C_chintrochar(param_0, local_7);
    }
    _anseq_entrypoint_8(local_1, func_80104248(param_0));
    if (*(s16 *)(local_0 + 0xC2)) {
        _chblink_entrypoint_2(*(s16 *)(local_0 + 0xC2));
    }
    if (*(s16 *)(local_0 + 0xC4)) {
        _chblink_entrypoint_2(*(s16 *)(local_0 + 0xC4));
    }
    _chanim_entrypoint_9(param_0);
    if (local_2 & 0x80000) {
        _chanim_entrypoint_1(param_0->unk0, 0xD, func_800DA298(0xD));
    }
    if (local_2 & 0x40) {
        if (local_2 & 0x40000) {
            func_8010FFB0(func_8008FFE8(), local_3.f, local_4.f);
            _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, local_3.f);
        } else {
            _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
        }
    }
    if (*(s16 *)(local_0 + 0xC6)) {
        _suexpression_entrypoint_10(func_8001B798(*(s16 *)(local_0 + 0xC6)), param_0->unk0, 0);
    }
    if (!_subaddiefade_entrypoint_0(param_0)) {
        param_0->unk64_16 = 0;
    } else {
        param_0->unk64_16 = param_0->unk64_19;
    }
    local_5 = *(f32 *)(func_8080416C_chintrochar + param_0->unk74_7 * 0x20);
    if (local_5 > 0.0f) {
        _chbadshad_entrypoint_1(param_0, param_0->position, local_5);
    }
}

void func_8080374C_chintrochar(Actor *param_0, s32 param_1)
{
    s32 local_2;
    u8 *local_0;
    s32 local_1;
    u8 *local_3;

    local_0 = func_80100094(param_0, 2);
    if (*(s16 *)(local_0 + 0xC6)) {
        _suexpression_entrypoint_19(func_8001B798(*(s16 *)(local_0 + 0xC6)), param_0);
    }
    if ((*(s32 *)(func_80804160_chintrochar + param_0->unk74_7 * 32) << 15) < 0) {
        local_2 = func_8010262C(param_0->unk0, 6);
        if (local_2) {
            local_3 = func_80100094(param_0, 2);
            for (local_1 = 0; local_1 < 3; local_1++) {
                func_800E0AFC(local_2, ((u8 (*)[2])D_80805308_chintrochar)[local_1][1], -1.0f, *(f32 *)(local_3 + 0xD0), 0.0f, 0.0f);
            }
            for (local_1 = 0; local_1 < 3; local_1++) {
                func_800E0AFC(local_2, ((u8 (*)[2])D_80805310_chintrochar)[local_1][1], -1.0f, *(f32 *)(local_3 + 0xD4), 0.0f, 0.0f);
            }
        }
    }
}

void func_80803888_chintrochar(u8 *param_0) {
    u8 *sp24;
    s32 sp20;
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_a0_3;

    sp24 = func_80100094(param_0, 2);
    sp20 = *(s32 *)((char *)&func_80804160_chintrochar + (((u32) (*(u16 *)((u8 *)param_0 + 0x76)) >> 7) << 5));
    func_80103D48(param_0);
    _chanim_entrypoint_8(param_0);
    temp_a0 = (*(s16 *)((u8 *)sp24 + 0xC2));
    if (temp_a0 != 0) {
        _chblink_entrypoint_4(temp_a0);
    }
    temp_a0_2 = (*(s16 *)((u8 *)sp24 + 0xC4));
    if (temp_a0_2 != 0) {
        _chblink_entrypoint_4(temp_a0_2);
    }
    func_801015D0(param_0);
    temp_a0_3 = (*(s16 *)((u8 *)sp24 + 0xC6));
    if (temp_a0_3 != 0) {
        _suexpression_entrypoint_11(func_8001B798(temp_a0_3), param_0);
    }
    if (sp20 & 0x10) {
        func_800DF830(2);
    } else if (sp20 & 8) {
        func_800DF830(0);
    } else if (sp20 & 0x20) {
        func_800DF830(3);
    }
    func_80103D70(param_0);
}

void func_80803990_chintrochar(Actor *param_0, Gfx **param_1)
{
    u8 *local_0;
    u8 *t;

    local_0 = func_80100094(param_0, 2);
    func_800B8C50();
    func_800B8C8C(_subaddiefade_entrypoint_0(param_0));
    func_800B8C98(0);
    func_800B8CB0(1);
    func_800B7F14(param_1);
    switch (param_0->unk74_7 - 50) {
    case 12:
        func_800B8F88(param_1, 0xB6, t = *(u8 **)&local_0);
        func_800B8F88(param_1, 0xC2, t + 0x40);
        break;
    case 3:
        func_800B8F88(param_1, 0xB6, t = *(u8 **)&local_0);
        func_800B8F88(param_1, 0xC2, t + 0x40);
        func_800B8F88(param_1, 0xCE, t + 0x80);
        break;
    }
    func_800B811C(param_1);
}

void func_80803A78_chintrochar(Actor *param_0, s32 param_1)
{
    extern void func_800EFA4C(f32 *, f32, f32, f32);
    extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    extern void *func_800DF944(s32, f32 *, f32, f32, f32 *, s32, void *);
    extern void func_800DF464(f32);
    s32 local_0;
    f32 local_1[3];
    IntroCharDrawPair local_2;
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    s32 local_6;
    local_0 = *(s32 *)(func_80804160_chintrochar + param_0->unk74_7 * 0x20);
    if (local_0 & 2) {
        if (local_0 & 0x8000) {
            local_2 = *(IntroCharDrawPair *)D_80805318_chintrochar;
            local_6 = param_0->unk74_7 - 0x32;
            if (local_6 == 3 || local_6 == 4) {
                local_2.local_0[1] -= 20.0f;
            }
            if (!(local_0 & 4) && param_0->rotation[1] != 0) {
                func_800EFA4C(local_1, 0.0f, param_0->rotation[1], 0.0f);
                func_800DF4CC(local_1);
            }
            func_800DF47C(func_801017D0, param_0);
            func_800DF944(param_1, local_2.local_0, 0.0f, param_0->scale * 0.35f, 0, 1, (void *)func_8010347C(param_0->unk0));
        } else {
            func_800E39A8(local_3, local_4);
            func_800EF5A0(local_5, local_4, 0, 0, -1000.0f);
            func_800EF04C(local_5, local_3);
            func_800DF47C(func_801017D0, param_0);
            if (local_0 & 4) {
                func_800DE448(local_5, local_4, param_0->scale, 0, func_801039E4(param_0->unk0));
            } else {
                func_800DE448(local_5, param_0->rotation, param_0->scale, 0, func_801039E4(param_0->unk0));
            }
        }
    } else {
        if (((ICBits94 *)&param_0->pad94)->b30) {
            func_800DF440(0);
        } else {
            func_80101970(param_0);
        }
        if (local_0 & 0x200) {
            func_800DF464(*(f32 *)(func_80804168_chintrochar + param_0->unk74_7 * 0x20));
        }
        func_800DF47C(func_801017D0, param_0);
        func_800DE448(param_0->position, param_0->rotation, param_0->scale, 0, func_801039E4(param_0->unk0));
    }
    if (local_0 & 0x1000) {
        func_80803990_chintrochar(param_0, param_1);
    }
}

int func_80803D0C_chintrochar(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    s32 local_1;
    Actor *local_2;
    s32 local_3;
    switch (param_1) {
    case 0x29: func_808002FC_chintrochar(param_0); break;
    case 0x9C: func_8080374C_chintrochar(param_0, (*(s32 *)&param_2)); break;
    case 0x1F: func_80803888_chintrochar(param_0); break;
    case 0x5A:
        if (param_2 == 0 || param_2 == 1) func_80803418_chintrochar(param_0, param_2);
        break;
    case 0x3D:
        local_3 = *(s32 *)(func_80804160_chintrochar + param_0->unk74_7 * 32);
        if ((local_3 << 14) < 0) {
            local_0 = (u8 *)func_80100094(param_0, 2);
            for (local_1 = 0; local_1 != 2; local_1++) {
                local_2 = (Actor *)func_80108528(0x50A, param_0->position, 10, &param_0);
                ((void **)(local_0 + 0x104))[local_1] = local_2->unk0;
                func_80103110(local_2, 1);
                func_80102FDC(local_2, 1.5f);
            }
            break;
        }
        break;
    default: return 0;
    }
    return 1;
}

int chintrochar_entrypoint_0()
{
    return (int)&D_8080532C_chintrochar;
}

void func_80803E98_chintrochar(param_0) Actor *param_0;
{
    IntroInterpolation1257 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 2);
    for (local_1 = 0; local_1 < 2; local_1++) {
        local_0->local_0[local_1] = 0.0f;
    }
    func_800EE7F8(local_0->local_1[1].local_0, param_0->position);
    func_800EE7F8(local_0->local_1[0].local_0, param_0->position);
    local_0->local_1[1].local_1 = param_0->rotation[1];
    local_0->local_1[0].local_1 = param_0->rotation[1];
}

void func_80803F24_chintrochar(param_0, param_1, param_2) IntroS *param_0; u8 *param_1; s32 param_2; {
    if (param_0->flag) {
        func_800DBEFC(*(s32 *)((u8 *)param_0->f0 + 4), D_80805374_chintrochar[param_2], param_1 + 4);
    }
    func_80103014(param_1);
}

void func_80803F7C_chintrochar(param_0) Actor *param_0;
{
    IntroPairedPose *local_0;
    f32 local_1[3];
    local_0 = func_80100094(param_0, 2);
    if (param_0->unk7C_12) {
        func_800DBEFC(param_0->unk0->unk4, 7, local_0->local_0);
        func_800DBEFC(param_0->unk0->unk4, 8, local_1);
        local_0->local_1 = func_800F1DF4(local_1, local_0->local_2);
    }
    func_80804054_chintrochar(param_0, 0, -1.0f, D_80805388_chintrochar);
    func_80804054_chintrochar(param_0, 1, 1.0f, D_8080537C_chintrochar);
    func_80804238_chintrochar(param_0);
    func_800EE7F8(local_0->local_2, local_0->local_0);
    local_0->local_3 = local_0->local_1;
}

void func_80804054_chintrochar(Actor *param_0, s32 param_1, f32 param_2, void *param_3)
{
    IntroTextureScroll1210 *local_5;
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    /* Unused float slots preserve the original IDO stack layout.
     * Their original source-level purpose is not yet established. */
    f32 local_7;
    f32 local_8;
    s32 local_6;

    local_5 = func_80100094(param_0, 2);
    local_0 = func_800D8FF8();
    func_800EF934(local_1, param_3, local_5->local_4);
    func_800EF04C(local_1, local_5->local_3);
    func_800EF934(local_2, param_3, local_5->local_6);
    func_800EF04C(local_2, local_5->local_5);
    local_3 = func_800EEAD4(local_1, local_2);
    if (func_800EECE0(param_0->position, local_5->local_5)) {
        local_4 = (func_800F1DCC(local_5->local_6, local_5->local_4) <= 0.0f ? 1.0f : -1.0f) * param_2;
    } else {
        local_4 = 1.0f;
    }
    local_5->local_1[param_1] += local_3 * 12.0f * local_4 * 64.0f * local_0;
    local_6 = local_5->local_1[param_1];
    if (local_6 >= 8192) {
        local_5->local_1[param_1] -= 8192.0f;
    } else if (local_6 < 0) {
        local_5->local_1[param_1] += 8192.0f;
    }
    local_5->local_2[param_1] = (s32)local_5->local_1[param_1];
    local_5->local_0[param_1] += local_3 * 0.01333333366f * local_4 * 57.29578018f;
}

void func_80804238_chintrochar(param_0) Actor *param_0;
{
    s32 local_0;

    local_0 = func_801065A4(param_0);
    if (local_0) {
        _glid_entrypoint_0(local_0, 1, _chintrochar_entrypoint_1, param_0->unk0);
        _glid_entrypoint_0(local_0, 2, _chintrochar_entrypoint_1, param_0->unk0);
    }
}

void chintrochar_entrypoint_1(s32 param_0, VertexShiftRecord *param_1, VertexShiftRecord *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    u8 *local_0;
    s32 local_2;
    VertexShiftRecord *local_1;

    local_0 = func_80100094(func_80106790(param_4), 2);
    switch (param_0) {
        case 1:
            local_2 = *(s16 *)(local_0 + 0xE0);
            local_1 = param_1 + param_3;
            for (; param_1 < local_1; param_1++, param_2++) {
                param_2->unkA = param_1->unkA + local_2;
            }
            break;
        case 2:
            local_2 = *(s16 *)(local_0 + 0xE0 + 2);
            local_1 = param_1 + param_3;
            for (; param_1 < local_1; param_1++, param_2++) {
                param_2->unkA = param_1->unkA + local_2;
            }
            break;
    }
}
