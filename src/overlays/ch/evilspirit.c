#include "common.h"

#define TEXTURE_RECT48(pkt, xl, yl, xh, yh) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = _SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12); \
    _g->words.w1 = _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12); \
    gImmp1(pkt, 0xE1, 0); \
    gImmp1(pkt, 0xF1, 0x01000100); \
}
extern void *D_80802270_chevilspirit;
extern void *func_80100094(Actor *, u32);
extern f32 func_800DC178(f32, f32);
extern u8 D_808021D0_chevilspirit[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern int _susubgame_entrypoint_3(Actor *, void *, s32, s32);
typedef struct { u8 local_0[0x10]; u32 local_1 : 31; u32 local_2 : 1; } local_marker;
typedef struct { local_marker *local_0; } local_actor;
extern s32 func_801017D0;
extern u8 D_808022D4_chevilspirit[];
extern u8 D_808022D8_chevilspirit[];
extern u8 D_808022DC_chevilspirit[];
extern Actor *_subaddielink_entrypoint_4(void *);
extern Actor *func_80106790();
typedef struct { u32 w0, w1; } GfxW;
extern u16 D_808022E0_chevilspirit[];
extern s32 func_800EA05C(void);
extern s32 func_800D3934(void);
extern u16 D_808022E4_chevilspirit[];
extern void func_8008FE94();
extern f32 func_80090010(void);
extern f32 func_8010CD28(Actor *);
extern void func_8010105C(f32);
extern f32 func_80101068(void);
extern void func_800EF334(f32 *, f32);
extern u8 local[];
extern u8 D_808022E8_chevilspirit[];
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
typedef struct { u8 pad_0[8]; s16 count; s16 cur; s32 ids[1]; } EvilList;
extern int func_800BDC5C(void);
typedef struct { u8 pad_0[0x64]; u8 pad_1 : 2; u8 local_0 : 1; u8 local_1 : 2; u8 pad_2 : 3; } EvilSpiritActorFlags;
extern s16 D_808021E0_chevilspirit[];
extern int func_8010108C(void *, int, int);
extern void _subaddielink_entrypoint_0(void *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_808022F4_chevilspirit[];
extern int func_800EE7F8(f32 *, f32 *);
extern void func_800C8E54(s32, f32, f32);
extern void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
extern f32 D_80802320_chevilspirit[];
extern f32 D_8080232C_chevilspirit[];
extern f32 D_80802338_chevilspirit[];
extern f32 func_800F0F9C(f32, f32);
extern f32 func_800F3780(f32, f32 *, s32);
extern void func_800F3214(f32 *, f32 *, f32 *, f32);
extern f32 func_800D8FF8(void);
extern u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
extern s32 func_800C3058(u8, u32);
extern void func_800C330C(u8, s32);
extern void func_800C31DC(u8, f32);
extern s32 func_800C4350(u8, f32 *, s16 *);
extern void func_800C3BDC(u8);
extern s16 D_808022C8_chevilspirit[];
extern s16 D_808021EC_chevilspirit[];
extern s16 D_808022B8_chevilspirit[];
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern void func_8010297C(Actor *, f32, f32, f32);
extern f32 sqrtf(f32);
extern f32 func_80013B70(f32, f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
typedef struct { u8 pad_0[8]; s16 local_0; s16 local_1; Unk80132ED0 *local_2[1]; } EvilSpiritTargetList;
typedef struct { Unk80132ED0 *local_0; s32 local_1; u32 local_2; } EvilSpiritCubeEntry;
extern u8 D_80802350_chevilspirit[];
void func_808007B4_chevilspirit();
void func_80800E20_chevilspirit();
s32 func_80800F8C_chevilspirit();
void func_80801344_chevilspirit();
void func_80801458_chevilspirit();
s32 func_808015E0_chevilspirit(Actor *param_0, f32 param_1);
s32 func_80801988_chevilspirit();
int func_80801A6C_chevilspirit();
void func_80801B00_chevilspirit();
void func_80801C04_chevilspirit();
void func_80801E18_chevilspirit();
s32 func_80801EC4_chevilspirit();
void func_80802024_chevilspirit();
void func_80802090_chevilspirit();
void func_80800A4C_chevilspirit(s32 param_0, s32 param_1, f32 *param_2, f32 *param_3, Actor *param_4, f32 param_5, u8 *param_6);
Unk80132ED0 *func_8080104C_chevilspirit();
void func_808013DC_chevilspirit();
void func_80801F1C_chevilspirit();

void *chevilspirit_entrypoint_0()
{
  return &D_80802270_chevilspirit;
}

void func_8080000C_chevilspirit(Actor *param_0)
{
    void *local_0;

    local_0 = func_80100094(param_0, 0);
    if (func_80800F8C_chevilspirit(param_0)) {
        _subaddieDll_entrypoint_0(param_0);
        func_8010A828(param_0, 9);
    }
    func_80801344_chevilspirit(param_0);
    func_800EE7F8(param_0->position, (f32 *)((u8 *)param_0 + 0x18));
    param_0->unk58 = func_800DC178(5.0f, 8.0f);
    _subaddielink_entrypoint_0(local_0);
    *(s32 *)((u8 *)param_0 + 0x24) = 0;
    if (func_800EA068(16)) {
        if (func_800EA05C() == 0x141 && !func_800DA298(0x38)) {
            func_80102424(param_0, 2);
            param_0->unk58 = 3.0f;
        } else {
            func_80102424(param_0, 3);
            param_0->unk58 = 2.0f;
        }
    }
}

void func_80802118_chevilspirit();

s32 func_80801684_chevilspirit();

void func_808015A4_chevilspirit();

void func_80801398_chevilspirit();

void func_80800104_chevilspirit(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 1:
        func_80801344_chevilspirit(param_0);
        func_808012CC_chevilspirit(param_0);
        break;
    case 2:
        func_80801344_chevilspirit(param_0);
        if (func_800DB9B0()) {
            func_800DA544(0x38);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x15CA, 0x44, 0, 0xBB);
            func_80102424(param_0, 3);
        }
        break;
    case 3:
        func_80801344_chevilspirit(param_0);
        if (func_800D9078(&param_0->unk58)) {
            s32 local_2 = param_0->actorData[3];

            if (local_2) {
                param_0->actorData[3] = _chlightfader_entrypoint_1(local_2, 1.0f, 2);
            }
            func_80802090_chevilspirit(param_0, D_808022B8_chevilspirit);
            _subaddiefade_entrypoint_3(param_0);
            func_8010A828(param_0, 0xC);
            func_80102424(param_0, 4);
            func_800DA524(0x6A7);
        }
        break;
    case 4:
        func_801078DC(param_0, local_0 + 0x3C);
        break;
    case 5:
        if (func_800C9510()) {
            func_80801A6C_chevilspirit(param_0, 0);
        } else if (!func_80801840_chevilspirit(param_0) || !func_80801EC4_chevilspirit(param_0)) {
            func_80102424(param_0, 8);
        } else {
            func_808015A4_chevilspirit(param_0);
        }
        break;
    case 6:
        func_80116088(func_80110014(func_8008FFE8()), param_0->position);
        if (func_800C9510()) {
            func_80801A6C_chevilspirit(param_0, 0);
        } else if (!func_80801840_chevilspirit(param_0)) {
            func_80102424(param_0, 7);
            *(f32 *)&param_0->actorData[4] = 1.5f;
        } else if (!func_80801EC4_chevilspirit(param_0) && func_80801A6C_chevilspirit(param_0, 3)) {
            func_80802090_chevilspirit(param_0, D_808021EC_chevilspirit);
            func_80102424(param_0, 8);
            *(f32 *)&param_0->actorData[4] = 1.5f;
        } else if (!func_808018DC_chevilspirit(param_0)) {
            func_80802090_chevilspirit(param_0, D_808021EC_chevilspirit);
            func_80102424(param_0, 8);
            *(f32 *)&param_0->actorData[4] = 1.5f;
        } else {
            func_80801684_chevilspirit(param_0);
            func_80801398_chevilspirit(param_0);
        }
        break;
    case 7:
        if (!func_8001210C(7)) {
            func_8010297C(param_0, param_0->unk54, 40.0f, 60.0f);
        }
        func_80102BF8(param_0, 0.2f, 15.0f, 1200.0f);
        if (func_800D9078(&param_0->actorData[4])) {
            func_80802090_chevilspirit(param_0, D_808021EC_chevilspirit);
            func_80102424(param_0, 8);
        }
        func_808012CC_chevilspirit(param_0);
        break;
    case 8:
        func_80801534_chevilspirit(param_0);
        func_808012CC_chevilspirit(param_0);
        break;
    case 10:
        func_801078DC(param_0, local_0 + 0x3C);
        if (_subaddiefade_entrypoint_0(param_0) == 0) {
            func_80802090_chevilspirit(param_0, D_808022C8_chevilspirit);
            func_80103140(param_0, 0x90F, param_0->unk0->unk16);
            func_80102424(param_0, 0xB);
            _subaddiefade_entrypoint_2(param_0);
        }
        break;
    case 11:
        func_801078DC(param_0, local_0 + 0x3C);
        if (_subaddiefade_entrypoint_0(param_0) == 0xFF) {
            func_80102424(param_0, 0xC);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x15CB, 6, param_0->position, 0xBB);
        }
        break;
    case 13:
        local_1 = func_800D90A4(&param_0->unk58);
        if (func_8010D23C()) {
            param_0->unk54 = func_8010CD28(param_0);
            func_80102BF8(param_0, 0.2f, 15.0f, 1200.0f);
        }
        if (local_1 && func_8010CAC0(param_0->position, 500)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, func_800DC128(0, 4) + 0x15C6, 0x44, param_0->position, 0xBB);
            func_80102424(param_0, 0xE);
        }
        break;
    case 14:
        if (func_8010D23C()) {
            param_0->unk54 = func_8010CD28(param_0);
            func_80102BF8(param_0, 0.2f, 15.0f, 1200.0f);
        }
        break;
    }
    func_80801E18_chevilspirit(param_0);
    func_80802118_chevilspirit(param_0);
}

int func_808005B4_chevilspirit(Actor *param_0)
{
  s32 *local_0 = (s32 *) (((char *) param_0) + 0x24);
  if ((*local_0) != 0)
  {
    func_800C8B84(*((s32 *) (((char *) param_0) + 0x24)));
    *((s32 *) (((char *) param_0) + 0x24)) = 0;
  }
}

int func_808005EC_chevilspirit(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x2E:
            func_80801F1C_chevilspirit(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
            break;
        case 0x2F:
            func_80802024_chevilspirit(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
            break;
        case 0x95:
            func_80801C04_chevilspirit(param_0);
            break;
        case 0x1F:
            func_801015D0(param_0);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(param_0, local_0 + 0x40, param_2 & 0xFFFF, (param_2 & 0xFFFF0000) >> 16);
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808021D0_chevilspirit, param_0->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800718_chevilspirit(Actor *param_0, s32 param_1)
{
  s32 local_0;

  switch (func_800EB854()) {
    case 0:
    case 2:
      local_0 = ((local_actor *)param_0)->local_0->local_2;
      ((local_actor *)param_0)->local_0->local_2 = 0;
      func_80101808(param_0, &func_801017D0);
      ((local_actor *)param_0)->local_0->local_2 = local_0;
      break;
    case 3:
      func_808007B4_chevilspirit(param_0, param_1);
      break;
  }
}

void func_808007B4_chevilspirit(param_0, param_1) Actor *param_0; Gfx **param_1;
{
    extern void func_800E253C(f32);
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_13;
    s32 local_6[3];
    f32 local_7[3];
    f32 local_8[3];
    f32 local_9[3];
    s32 local_5;
    u8 *local_0;
    Actor *local_10;
    Unk80132ED0 *local_12;
    Actor *local_11;
    local_0 = (u8 *)func_80100094(param_0, 0);
    if (!func_800DB9B0()) {
        local_5 = func_800F54E4();
        func_800F5A00(local_5, local_7);
        func_8010FFB0(func_800F5EF8(local_5), local_8, local_9);
        func_800A8A04(func_800A89F8(), &local_1, &local_2, &local_3, &local_4);
        local_6[0] = (local_3 + local_1 - 25) << 2;
        local_6[1] = (local_4 + local_2 - 21) << 2;
        func_800E253C(1.5f);
        func_800E257C((param_0->alpha * 96) >> 8);
        func_800E2434(1);
        func_800E30E0(param_1, func_800D674C(0xB81), 0, local_6);
        func_800B9990(param_1);
        func_80800E20_chevilspirit(param_0, param_1, local_6);
        local_10 = 0;
        if (*(s16 *)(local_0 + 8) >= 2) {
            local_12 = ((Unk80132ED0 **)(local_0 + 0xC))[*(s16 *)(local_0 + 0xA)];
            if (local_12 && func_801069A4(local_12)) {
                local_10 = (Actor *)func_80106790(local_12);
            }
        }
        for (local_11 = (Actor *)func_801067C4(&local_13); local_11; local_11 = (Actor *)func_8010682C(&local_13)) {
            if (local_11->unk64_24) {
                func_80800A4C_chevilspirit(param_0, param_1, local_6, local_7, local_11, local_9[1],
                    local_10 == local_11 ? D_808022D8_chevilspirit : D_808022DC_chevilspirit);
            }
        }
        local_11 = (Actor *)_subaddielink_entrypoint_4(local_0);
        if (local_11) {
            func_80800A4C_chevilspirit(param_0, param_1, local_6, local_7, local_11, local_9[1], D_808022DC_chevilspirit);
        }
        func_80800A4C_chevilspirit(param_0, param_1, local_6, local_7, param_0, local_9[1], D_808022D4_chevilspirit);
        gDPPipeSync((*param_1)++);
        gDPSetCycleType((*param_1)++, G_CYC_2CYCLE);
    }
}

void func_80800BFC_chevilspirit();

void func_80800A4C_chevilspirit(s32 param_0, s32 param_1, f32 *param_2, f32 *param_3, Actor *param_4, f32 param_5, u8 *param_6)
{
    f32 local_0[3];
    f32 local_3;
    f32 local_1;
    s16 local_2[2];
    func_800EFB24(local_0, param_3, param_4->position);
    local_0[1] = 0.0f;
    local_3 = local_0[0] * local_0[0] + local_0[2] * local_0[2];
    if (local_3 >= 4000000.0f) { return; }
    local_3 = sqrtf(local_3);
    local_1 = func_80013B70(local_0[0], local_0[2], local_3) - param_5;
    local_1 = func_800136E4(local_1);
    param_6[3] = (u8)func_800F10B4(local_3, 1600.0f, 2000.0f, 255.0f, 0.0f);
    if (param_6[3]) {
        local_3 *= 0.025f;
        local_2[0] = (s16)(s32)(-func_800137F4(local_1) * local_3);
        local_2[1] = (s16)(s32)(-func_80013788() * local_3);
        func_80800BFC_chevilspirit(param_0, param_1, param_2, local_2, param_6);
    }
}

void func_80800BFC_chevilspirit(Actor *param_0, Gfx **param_1, s32 *param_2, s16 *param_3, u8 *param_4)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = (param_2[0] + param_3[0]) & 0xFFFC;
    local_1 = (param_2[1] + param_3[1]) & 0xFFFC;
    gDPPipeSync((*param_1)++);
    local_2 = (*((u8 *)param_0 + 0x9B) * param_4[3]) >> 8;
    gDPSetFogColor((*param_1)++, param_4[0] >> 2, param_4[1] >> 2, param_4[2] >> 2,
        (local_2 >> 1) + (local_2 >> 2));
    TEXTURE_RECT48((*param_1)++, local_0 - 8, local_1 - 8, local_0 + 8, local_1 + 8);
    gDPPipeSync((*param_1)++);
    gDPSetFogColor((*param_1)++, param_4[0], param_4[1], param_4[2], local_2);
    TEXTURE_RECT48((*param_1)++, local_0 - 4, local_1 - 4, local_0 + 4, local_1 + 4);
}

void func_80800E20_chevilspirit(param_0, param_1, param_2) u8 *param_0; GfxW **param_1; u32 *param_2;
{
    s32 x;
    s32 y;
    u32 m;

    m = (u32)*(u16 *)(param_0 + 0x72) >> 10;
    if (m != 1 && m != 2 && m != 3) {
        x = param_2[0] & ~3;
        y = param_2[1] & ~3;
        { GfxW *_g = (*param_1)++; _g->w0 = 0xE7000000; _g->w1 = 0; }
        { GfxW *_g = (*param_1)++; _g->w0 = 0xF8000000; _g->w1 = ((((s32)(param_0[0x9B] << 7)) >> 8) & 0xFF) | ~0xFF; }
        { GfxW *_g = (*param_1)++; _g->w0 = (0xE4000000 | (((x + 8) & 0xFFF) << 12)) | ((y + 4) & 0xFFF); _g->w1 = (((x - 4) & 0xFFF) << 12) | (y & 0xFFF); }
        { GfxW *_g = (*param_1)++; _g->w0 = 0xE1000000; _g->w1 = 0; }
        { GfxW *_g = (*param_1)++; _g->w0 = 0xF1000000; _g->w1 = 0x01000100; }
        { GfxW *_g = (*param_1)++; _g->w0 = (0xE4000000 | (((x + 4) & 0xFFF) << 12)) | ((y + 8) & 0xFFF); _g->w1 = (((x) & 0xFFF) << 12) | ((y - 4) & 0xFFF); }
        { GfxW *_g = (*param_1)++; _g->w0 = 0xE1000000; _g->w1 = 0; }
        { GfxW *_g = (*param_1)++; _g->w0 = 0xF1000000; _g->w1 = 0x01000100; }
    }
}

s32 func_80800F8C_chevilspirit(param_0) s32 param_0; {
    s32 i;
    s32 local_0 = func_800EA05C();
    if (func_800D3934() == 0) {
        return 0;
    }
    for (i = 0; i < 1; i++) {
        if (local_0 == D_808022E0_chevilspirit[i]) {
            return 0;
        }
    }
    return 1;
}

s32 func_80800FF8_chevilspirit(s32 param_0) {
    s32 local_0 = func_800EA05C();
    s32 i;
    for (i = 0; i < 2; i++) {
        if (local_0 == D_808022E4_chevilspirit[i]) {
            return 1;
        }
    }
    return 0;
}

Unk80132ED0 *func_8080104C_chevilspirit(param_0, param_1) Actor *param_0; s32 param_1;
{
    extern f32 func_800EEB40(f32 *, f32 *);
    extern s32 *func_800BE444(f32 *);
    extern EvilSpiritCubeEntry *func_800E9E88(s32);
    extern EvilSpiritCubeEntry *func_800E9EB4(s32);
    s32 *local_2;
    EvilSpiritTargetList *local_0;
    EvilSpiritCubeEntry *local_3;
    EvilSpiritCubeEntry *local_4;
    Unk80132ED0 *local_5;
    Actor *local_6;
    f32 local_1[3];
    Actor *local_7;
    f32 local_8;
    f32 local_9;
    s32 local_10;
    s32 local_11;
    s32 local_12;
    Unk80132ED0 *local_13;
    local_0 = (EvilSpiritTargetList *)func_80100094(param_0, 0);
    func_8010D254(local_1);
    local_7 = 0;
    local_9 = 3.4028235e38f;
    local_2 = func_800BE444(local_1);
    local_0->local_0 = 0;
    for (; *local_2; local_2++) {
        local_3 = func_800E9E88(*local_2);
        local_4 = func_800E9EB4(*local_2);
        for (; local_3 < local_4; local_3++) {
            if (local_3->local_2 & 1) {
                local_5 = local_3->local_0;
                if (*(u16 *)((u8 *)local_5 + 0x18) & 1) {
                    local_6 = (Actor *)func_80106790(local_5);
                    if (local_6->unk64_24 && !func_801072A8(local_6)) {
                        local_8 = func_800EEB40(local_1, local_6->position);

                        if (local_8 < func_800BDC5C() * func_800BDC5C()) {
                            if (local_8 < local_9) {
                                local_7 = local_6;
                                local_9 = local_8;
                            }
                            if (param_1) {
                                local_0->local_2[local_0->local_0] = local_5;
                                local_0->local_0++;
                            }
                        }
                    }
                }
            }
        }
    }
    if (param_1) {
        for (local_11 = 1; local_11 < local_0->local_0; local_11++) {
            local_12 = local_11;
            while (local_12 > 0 &&
                (s32)((u32)*(u16 *)((u8 *)local_0->local_2[local_12] + 0x1A) >> 5) <
                (s32)((u32)*(u16 *)((u8 *)local_0->local_2[local_12 - 1] + 0x1A) >> 5)) {
                local_13 = local_0->local_2[local_12];
                local_0->local_2[local_12] = local_0->local_2[local_12 - 1];
                local_0->local_2[local_12 - 1] = local_13;
                local_12--;
            }
        }
    }
    return local_7 ? local_7->unk0 : 0;
}

int func_808012CC_chevilspirit(s32 param_0)
{
  if (!func_8001210C(3) && !func_800C954C() && func_80801EC4_chevilspirit(param_0))
  {
    s32 local_0 = func_8080104C_chevilspirit(param_0, 0);
    if (local_0 != 0 && func_80801988_chevilspirit(param_0, local_0, 0) != 0)
    {
      func_80102424(param_0, 5);
    }
  }
}

void func_80801344_chevilspirit(param_0) u8 *param_0; {
    func_8008FE94(5, param_0 + 0x18);
    *(f32 *)(param_0 + 0x1C) += 100.0f;
    *(f32 *)(param_0 + 0x54) = func_80090010();
    func_808013DC_chevilspirit(param_0);
}

void func_80801398_chevilspirit(Actor *this)
{
    if (_subaddielink_entrypoint_4(func_80100094(this, 0)) != 0) {
        func_80801458_chevilspirit(this);
        func_808013DC_chevilspirit(this);
    }
}

void func_808013DC_chevilspirit(param_0) Actor *param_0;
{
    param_0->position[0] += 0.3f * (((f32 *)param_0->actorData)[0] - param_0->position[0]);
    param_0->position[1] += 0.3f * (((f32 *)param_0->actorData)[1] - param_0->position[1]);
    param_0->position[2] += 0.3f * (((f32 *)param_0->actorData)[2] - param_0->position[2]);
    func_80102BF8(param_0, 0.2f, 15.0f, 1200.0f);
}

void func_80801458_chevilspirit(param_0) Actor *param_0;
{
    Actor *local_0;
    local_0 = _subaddielink_entrypoint_4(func_80100094(param_0, 0));
    func_8010105C(func_8010CD28(param_0));
    if (func_8010108C(local_0, 0x97, 0) <= 0) {
        func_800EE7F8((f32 *)&param_0->actorData[0], local_0->position);
        *(f32 *)&param_0->actorData[1] += local_0->scale * (u32)*(u16 *)((u8 *)local_0 + 0x6A) + *(f32 *)&param_0->actorData[5];
    } else {
        func_80101038((f32 *)&param_0->actorData[0]);
        func_800EF334((f32 *)&param_0->actorData[0], local_0->scale);
        func_800EF04C((f32 *)&param_0->actorData[0], local_0->position);
    }
    param_0->unk54 = func_80101068();
}

int func_80801534_chevilspirit(Actor *param_0)
{
    f32 local_0[3];

    func_8008FE94(5, (u8 *)param_0 + 24);
    *((f32 *)((char *)param_0 + 0x1C)) += 100.0f;
    if (func_808015E0_chevilspirit(param_0, 25.0f))
    {
        func_80802090_chevilspirit(param_0, &D_808022E8_chevilspirit);
        func_80102424(param_0, 1);
    }
}

void func_808015A4_chevilspirit(s32 param_0)
{
  func_80801458_chevilspirit();
  if (func_808015E0_chevilspirit(param_0, 1e+02f) != 0)
  {
    func_80102424(param_0, 6);
  }
}

s32 func_808015E0_chevilspirit(Actor *param_0, f32 param_1)
{
    f32 local_0[2];

    if (func_800EEB40(param_0->position, (f32 *)param_0->actorData) < param_1 * param_1) return 1;
    func_800F18FC(param_0->position, (f32 *)param_0->actorData, local_0);
    func_800EF214(param_0->position, local_0[0], local_0[1], param_1);
    param_0->unk54 = local_0[1];
    func_80102BF8(param_0, 0.2f, 15.0f, 1200.0f);
    return 0;
}

s32 func_80801684_chevilspirit(Actor *param_0)
{
    EvilList *local_0;
    s32 *local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    func_8080104C_chevilspirit(param_0, 1);
    local_1 = _subaddielink_entrypoint_4(func_80100094(param_0, 0));
    if (local_1) {
        local_2 = *local_1;
    } else {
        local_2 = 0;
    }
    if (!local_1) {
        _subaddielink_entrypoint_0(func_80100094(param_0, 0));
    }
    if (local_0->count >= 2) {
        local_3 = local_0->cur;
        while (local_3 >= local_0->count || local_0->ids[local_3] == local_2) {
            if (local_3 >= local_0->count) {
                local_3 = 0;
            }
            if (local_0->ids[local_3] == local_2) {
                local_3++;
            }
        }
        local_0->cur = local_3;
    }
    if (func_80016B54(1, 2) == 1 && local_0->count >= 2) {
        func_80801988_chevilspirit(param_0, local_0->ids[local_0->cur], 0);
        local_0->cur = local_0->cur + 1;
        return 1;
    }
    for (local_4 = 0; local_4 < local_0->count; local_4++) {
        if (local_2 != local_0->ids[local_4] && local_4 == local_0->cur) {
            func_80801B00_chevilspirit(param_0, func_80106790(local_0->ids[local_4]), 0x9DE);
            if (1) { /* PROBE: an empty loop inside an if (1) block, probably an empty debug macro; without it 9 words differ */
                do {} while (0);
            }
        }
    }
    return 0;
}

int func_80801840_chevilspirit(param_0) Actor *param_0;
{
    Actor *local_0;
    local_0 = _subaddielink_entrypoint_2(func_80100094(param_0, 0));
    if (!local_0)
    {
        return 0;
    }
    local_0 = _subaddielink_entrypoint_4(func_80100094(param_0, 0));
    if (!((*(u8 *)((char *)(local_0) + 0x64)) & 1))
    {
        (*(u8 *)((char *)(local_0) + 0x64)) = (*(u8 *)((char *)(local_0) + 0x64)) & 0xFFDF;
        _subaddielink_entrypoint_0(func_80100094(param_0, 0));
        func_8010108C(local_0, 2, 0);
        return 0;
    }
    return 1;
}

int func_808018DC_chevilspirit(Actor *param_0)
{
    Actor *local_0;
    f32 local_1[3];

    local_0 = _subaddielink_entrypoint_4(func_80100094(param_0, 0));
    func_8010D254(local_1);
    if (func_800EEB40(local_1, local_0->position) > (func_800BDC5C() + 300.0f) * (func_800BDC5C() + 300.0f)) {
        return func_80801A6C_chevilspirit(param_0, 1);
    }
    return 1;
}

s32 func_80801988_chevilspirit(param_0, param_1, param_2) Actor *param_0; Unk80132ED0 *param_1; s32 param_2;
{
    Actor *local_0;

    local_0 = func_80106790(param_1);
    if (param_1 == *(Unk80132ED0 **)func_80100094(param_0, 0)) {
        return 1;
    }
    if (!func_80801A6C_chevilspirit(param_0, 2)) {
        return 0;
    }
    _subaddielink_entrypoint_1(func_80100094(param_0, 0), param_1);
    *(s32 *)((u8 *)param_0 + 0x30) = 0;
    *(f32 *)((u8 *)param_0 + 0x2C) = 0.0f;
    ((EvilSpiritActorFlags *)local_0)->local_0 = 1;
    ((EvilSpiritActorFlags *)local_0)->local_1 = 1;
    if (param_2 == 0) {
        func_80802090_chevilspirit(param_0, D_808021E0_chevilspirit);
    }
    func_8010108C(local_0, 1, 0);
    return 1;
}

int func_80801A6C_chevilspirit(param_0, param_1) s32 param_0; s32 param_1;
{
    u8 *local_0;

    if (func_80801840_chevilspirit() != 0)
    {
        local_0 = _subaddielink_entrypoint_4(func_80100094(param_0, 0));
        if (func_8010108C(local_0, 0x46, param_1) > 0)
        {
            return 0;
        }
        (*(u8 *)((s8 *)local_0 + 0x64)) = (u8)((*(u8 *)((s8 *)local_0 + 0x64)) & 0xFFDF);
        func_8010108C(local_0, 2, 0);
        _subaddielink_entrypoint_0(func_80100094(param_0, 0));
        goto block_4;
    }
block_4:
    return 1;
}

void func_80801B00_chevilspirit(void *param_0, Actor *param_1, s32 param_2)
{
    f32 local_3[15][3];
    s32 local_0;
    s32 local_1;
    s32 local_2;

    s32 temp = ((u32)*(u16 *)((u8 *)param_1->unk0 + 0x12) >> 1) & 3;
    if (func_8001210C(3) == temp) {
        local_1 = _subaddievolume_entrypoint_0(param_1, local_3, 1, 15, (u8 *)param_0 + 0x30);
        if (local_1 > 0) {
            local_2 = func_800B53A4(local_1);
            func_800BA3FC(local_2, param_2);
            func_800BABB8(local_2, NULL, NULL, 1.0f, D_808022F4_chevilspirit);
            for (local_0 = 0; local_0 < local_1; local_0++) {
                func_800BABB8(local_2, local_3[local_0], NULL, 1.0f, NULL);
                func_800BA22C(local_2, 1);
            }
        }
    }
}

void func_80801C04_chevilspirit(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1[6];

    f32 *local_3;

    local_0 = func_80100094(param_0, 0);
    _susubgame_entrypoint_0(param_0, local_0 + 0x40, 0);
    _susubgame_entrypoint_12((local_0 + 0x40), D_808021D0_chevilspirit);
    if (!_subaddielink_entrypoint_3(func_80100094(param_0, 0)) &&
        param_0->unk70_10 != 1 && param_0->unk70_10 != 2 && param_0->unk70_10 != 3) {
        func_80102424(param_0, 8);
    }
    if (func_800EA05C() == 0xAF) {
        _subaddiemarker_entrypoint_1(param_0, 0x154, 0x32, local_1, 1);
        if (!func_800D3934()) {
            if (func_800DA298(0x3B)) {
                func_800FFAB0(param_0);
                return;
            }
            func_800EE7F8(param_0->position, local_1);
            param_0->rotation[1] = local_1[4];
            func_80103140(param_0, 0x90E, param_0->unk0->unk16);
            func_80102424(param_0, 0xD);
        } else if (!func_800DA298(0xCA)) {
            local_3 = param_0->position;
            func_800EE7F8(local_3, local_1);
            param_0->rotation[1] = local_1[4];
            func_80103140(param_0, 0x90E, param_0->unk0->unk16);
            func_80102424(param_0, 9);
            func_800F82D4(func_800F54E4(), 1);
            _susubgame_entrypoint_6(param_0, (local_0 + 0x40), 8, 0x20, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x15C5, 6, local_3, 0xBB);
        }
    }
    if (func_800BF8E4() && !func_80800FF8_chevilspirit(param_0)) {
        ((f32 *)param_0->actorData)[7] = 0.0f;
        param_0->actorData[3] = func_800C8A98();
        func_800C8E54(param_0->actorData[3], 150.0f, 450.0f);
        func_80801E18_chevilspirit(param_0);
    } else param_0->actorData[3] = 0;
}

void func_80801E18_chevilspirit(param_0) Actor *param_0;
{
    f32 local_2[3];
    f32 local_1[3];
    f32 local_3;
    f32 local_0;

    if (param_0->actorData[3]) {
        local_3 = func_800F0F9C(*(f32 *)&param_0->actorData[7], 0.5f);
        local_0 = func_800F3780(local_3, D_80802338_chevilspirit, 3);
        func_80103DFC(param_0, local_1);
        func_800F3214(local_2, D_80802320_chevilspirit, D_8080232C_chevilspirit, local_0);
        func_800C8CB8(param_0->actorData[3], local_1);
        func_800C8E84(param_0->actorData[3], local_2);
        *(f32 *)&param_0->actorData[7] += func_800D8FF8();
    }
}

s32 func_80801EC4_chevilspirit(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = func_800F54E4();
  if (func_800F6D24(local_0) != 0)
  {
    return 0;
  }
  if (func_800F8004(local_0) != 0)
  {
    return 0;
  }
  return 1;
}

void func_80801F1C_chevilspirit(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x15C5:
        func_80802090_chevilspirit(param_0, (s16 *)D_80802350_chevilspirit);
        func_80102424(param_0, 0xA);
        _subaddiefade_entrypoint_5(param_0);
        break;
    case 0x15CB:
        func_80102424(param_0, 8);
        _susubgame_entrypoint_4(param_0, local_0 + 0x40);
        func_800F82D4(func_800F54E4(), 0);
        _plcamera_entrypoint_8(func_800F54E4());
        func_800DA544(0xCA);
        break;
    case 0x15C6:
    case 0x15C7:
    case 0x15C8:
    case 0x15C9:
        func_80102424(param_0, 0xD);
        param_0->unk58 = func_800DC178(5.0f, 8.0f);
        break;
    case 0x15CA:
        break;
    }
}

void func_80802024_chevilspirit(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
    s32 sp24;

    sp24 = func_80100094(param_0, 0);
    if ((func_800C07F4() == 0) && (param_1 == 0x15C5) && (param_2 == 1)) {
        _susubgame_entrypoint_6(param_0, sp24 + 0x40, 5, 0x20, 0);
    }
}

void func_80802090_chevilspirit(Actor *param_0, s16 *param_1)
{
    u8 local_0;

    local_0 = param_0->unk5F;
    if (local_0 == 0) {
        param_0->unk5F = _subaddieaudioquick_entrypoint_1(param_0, param_0->position);
        func_800C330C(param_0->unk5F, 3);
        local_0 = param_0->unk5F;
    }
    func_800C3058(local_0, 0x55F0);
    func_800C31DC(param_0->unk5F, 1.0f);
    func_800C4350(param_0->unk5F, param_0->position, param_1);
    func_800C3BDC(param_0->unk5F);
}

void func_80802118_chevilspirit(u8 *param_0)
{
  u8 temp_a1;
  ;
  if ((((u8 *) param_0)[0x5F] != 0) && (func_800C3D78(((u8 *) param_0)[0x5F] & 0xFF, ((u8 *) param_0)[0x5F]) == 0))
  {
    func_800C2FDC(((u8 *) param_0)[0x5F]);
    ((u8 *) param_0)[0x5F] = 0U;
  }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/evilspirit.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_808022E2_chevilspirit = D_808022E0_chevilspirit + 0x2 */
extern void func_80105834();
extern void func_80107C2C();
u8 D_808021D0_chevilspirit[16] = { 0x43, 0x7, 0x0, 0x0, 0x42, 0xF0, 0x0, 0x0, 0x43, 0x7, 0x0, 0x0, 0x42, 0x20, 0x0, 0x0 };
s16 D_808021E0_chevilspirit[6] = { 0x13, 0x4EA, 0xD, 0xF3, 0x10C, 0x0 };
s16 D_808021EC_chevilspirit[6] = { 0x13, 0x4EB, 0xD, 0xF3, 0x10C, 0x0 };
u32 D_808021F8_chevilspirit[30] = { 0x0, 0x0, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x3EF0001, 0x40A00000, 0x3EF0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x49B0001, 0x40A00000, 0x3EF0001, 0x40A00000, 0x3EF0001 };
void *D_80802270_chevilspirit = (void *)0x018A0153;
static u32 D_80802270_chevilspirit_rest[17] = { 0x90F0001, (u32)&D_808021F8_chevilspirit, (u32)func_80800104_chevilspirit, (u32)func_80105834, (u32)func_80800718_chevilspirit, 0x0, 0x0, 0x0, 0x8001100, (u32)func_808005B4_chevilspirit, 0x0, 0x580000, (u32)func_8080000C_chevilspirit, (u32)func_80107C2C, 0x80000402, (u32)func_808005EC_chevilspirit, 0x0 };
s16 D_808022B8_chevilspirit[8] = { 0x13, 0x4EE, 0x1B, 0xD, 0xF3, 0x10C, 0x0, 0x0 };
s16 D_808022C8_chevilspirit[6] = { 0x13, 0x4ED, 0xD, 0xF3, 0x10C, 0x0 };
u8 D_808022D4_chevilspirit[4] = { 0xFF, 0x0, 0x0, 0xFF };
u8 D_808022D8_chevilspirit[4] = { 0xFF, 0xFF, 0x0, 0xFF };
u8 D_808022DC_chevilspirit[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
u16 D_808022E0_chevilspirit[2] = { 0x15F, 0x0 };
u16 D_808022E4_chevilspirit[2] = { 0x15F, 0xAF };
u8 D_808022E8_chevilspirit[12] = { 0x0, 0x13, 0x4, 0xEC, 0x0, 0xD, 0x1, 0x26, 0x1, 0x40, 0x0, 0x0 };
u8 D_808022F4_chevilspirit[44] = { 0x0, 0x15, 0x0, 0x19, 0x0, 0x99, 0x0, 0x22, 0x0, 0x28, 0x0, 0x33, 0x0, 0xF, 0x0, 0x14, 0x0, 0x16, 0x10, 0x0, 0x0, 0x2B, 0x0, 0x33, 0x0, 0x66, 0x0, 0x2C, 0x0, 0x0, 0x0, 0x46, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
f32 D_80802320_chevilspirit[3] = { 3.57e-43f, 1.35e-43f, 4.5e-44f };
f32 D_8080232C_chevilspirit[3] = { 3.57e-43f, 1.8e-43f, 4.5e-44f };
f32 D_80802338_chevilspirit[6] = { 0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 0.0f };
u8 D_80802350_chevilspirit[16] = { 0x0, 0x13, 0x4, 0xEE, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
