#include "common.h"

#define ZB_LIM(z) ((z)->b5 ? 0xAA : 0xFF)
#define ZB(o) ((ZbBits *) (o))
typedef struct {
    u8 unused0[0x1A4];
    f32 lower;
    f32 upper;
    u8 unused1AC[4];
    s16 center;
    u8 unused1B2[0x32];
    u32 high : 12;
    u32 large : 1;
    u32 low : 19;
} ZoomBoxBounds;
typedef struct {
    u8 pad_0[0x171];
    u8 local_0;
    u8 pad_1[0x2A];
    u8 local_1;
    u8 pad_2;
    u8 local_2;
    u8 pad_3[0x25];
    f32 local_3;
    u8 pad_4[4];
    u32 local_4 : 8;
    u32 pad_5 : 24;
    u8 pad_6[0x14];
    u32 local_5 : 1;
    u32 pad_7 : 4;
    u32 local_6 : 1;
    u32 pad_8 : 2;
    u32 local_7 : 1;
    u32 pad_9 : 23;
} ZoomBoxActivation;
typedef struct {
    u8 pad_0[0x1E4];
    u32 pad_1 : 29;
    u32 local_0 : 1;
    u32 local_1 : 1;
    u32 pad_2 : 1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
} ZoomBoxProgress;
typedef struct {
    u8 pad_0[0x1E4];
    u32 pad_1 : 29;
    u32 local_0 : 1;
    u32 pad_2 : 2;
    u8 pad_3[4];
    f32 local_1;
} ZoomBoxTimer;
typedef struct {
    u8 unused[0x170];
    u8 counter;
    u8 state;
    u8 unused172[0x72];
    u32 unused17 : 15;
    u32 enabled : 1;
    u32 unused5 : 11;
    u32 audio : 1;
    u32 unused3 : 1;
    u32 active : 1;
    u32 unused0 : 2;
} ZoomBoxOpenState;
typedef struct {
    u8 bit_7 : 1;
    u8 bit_6 : 1;
    u8 bit_5 : 1;
    u8 bit_4 : 1;
    u8 bit_3 : 1;
    u8 bit_2 : 1;
    u8 bit_1 : 1;
    u8 bit_0 : 1;
} ZoomFlags30;
extern void func_800C34CC(u8, s32);
extern void _fxdialog_entrypoint_2(f32);
extern void _fxdialog_entrypoint_3(void *, f32, s32, s32);
extern void _fxdialog_entrypoint_4(s32, s32, s32, f32, f32, s32, s32);
typedef struct {
    u8 pad0[0x140];
    u16 unk140;
    u16 unk142;
    u8 pad144[0x2D];
    u8 unk171;
    u8 pad172[4];
    u8 unk176;
    u8 pad177[0x35];
    s16 unk1AC;
    u8 pad1AE[9];
    s8 unk1B7;
    s8 unk1B8;
    s8 unk1B9;
    s8 unk1BA;
    u8 pad1BB[5];
    f32 unk1C0;
    u8 pad1C4[0x20];
    u32 pad_29 : 3;
    u32 b28 : 1;
    u32 pad_24 : 4;
    u32 b23 : 1;
    u32 pad_19 : 4;
    u32 b18 : 1;
    u32 pad_14 : 4;
    u32 b13 : 1;
    u32 pad_7 : 6;
    u32 b6 : 1;
    u32 b5 : 1;
    u32 pad_0 : 5;
} GcZoombox;
extern s32 func_800A819C(void);
extern s32 func_800DA298(s32);
typedef struct {
    u8 pad0[0x1DC];
    f32 unk1DC;
    u8 pad1E0[4];
    u32 pad1E4_20 : 12;
    u32 unk1E4_19 : 1;
    u32 pad1E4_16 : 3;
    u16 unk1E6_15 : 1;
    u16 pad1E6 : 15;
} ZoomBoxWrap;
extern s32 func_800D36C4(s32, s32);
typedef struct {
    u8 unused[0x140];
    u16 asset;
    u8 unused142[0x8D];
    u8 counter;
    u8 unused1D0;
    u8 count;
} ZoomBoxAssetState;
extern void *func_800D674C(s32);
typedef struct {
    u8 pad0[0x144];
    s8 unk144[5];
    u8 pad149[3];
    f32 unk14C[5];
    s16 unk160[5];
    u8 pad16A[0xC];
    u8 unk176;
    u8 pad177;
    u8 unk178;
    u8 pad179[0x5A];
    s8 unk1D3;
} ZoomBox;
extern void _gczoomboxdata_entrypoint_4(s32, s32, s16 *, s16 *, f32 *);
extern s32 _gczoomboxdata_entrypoint_3(s32);
typedef struct {
    u8 pad_0[0x174];
    s8 count, index;
    u8 pad_1, flags;
    u8 pad_2[4];
    char *strings[8];
} ZoomStrings1459;
typedef struct {
    u8 pad_0[0x1AE];
    s16 local_0;
    s16 pad_1;
    s16 local_1;
    u8 pad_2[0x28];
    f32 local_2;
    u8 pad_3[4];
    u32 pad_4 : 7;
    u32 local_4 : 1;
    u32 pad_5 : 8;
    u32 local_5 : 1;
    u32 pad_6 : 15;
    u8 pad_7[0xC];
    f32 local_3;
} ZoomBoxPlacement;
extern void func_800EC370(s32, s32 *);
typedef struct {
    u8 pad_0[0x140];
    u16 local_0;
    u16 local_1;
    u8 pad_1[0x2D];
    u8 local_2;
    s16 local_3;
    u8 pad_2[0x43];
    s8 local_4;
    s8 local_5;
    s8 local_6;
    s8 local_7;
    u8 pad_3[5];
    f32 local_8;
    u8 pad_4[0x22];
    u8 pad_5 : 1;
    u8 local_9 : 1;
    u8 local_10 : 1;
    u8 pad_6 : 5;
} ZoomState31;
typedef struct {
    u32 local_0 : 1;
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 local_3 : 25;
    u32 local_4 : 1;
    u32 local_5 : 3;
} Sol61ZoomFlags;
typedef struct {
    u8 pad0[0xF0];
    u8 unkF0[0xE0];
    u8 unk1D0;
    u8 unk1D1;
    u8 unk1D2;
} ZoomBoxMouth;
extern f32 func_800DC1AC(void);
typedef struct {
    u8 pad0[0x130];
    s32 unk130;
    s16 unk134[3];
    s16 unk13A;
    s32 unk13C;
    u8 pad140[4];
    u8 sfx[8];
    f32 pitch[5];
    s16 vol[5];
    u8 pad16A[8];
    s16 unk172;
    u8 pad174[4];
    u8 count;
    u8 pad179[0x5A];
    u8 last;
    u8 pad1D4[0x10];
    u32 pad1E4_12 : 20;
    u32 b11 : 1;
    u32 pad1E4_0 : 11;
} Zoombox_808009E4_gczoombox;
extern s32 func_800FCCD4();
extern void func_800FC6B0();
extern s32 func_800C3D78();
extern void func_800C3CE8();
extern s32 func_800DC214(s32, s32);
extern f32 func_80027170(s32);
extern void func_800C31DC(u8, f32);
extern f32 func_800DC264(f32, f32);
extern f32 _suexpression_entrypoint_0(u8);
extern void func_800C3058();
extern void func_800C3BDC();
extern void func_800D52CC(s32);
extern void func_800D527C(s32);
typedef struct {
    u8 str0[0x30];
    u8 str30[0x30];
    u8 buf60[0x30];
    u8 buf90[0x30];
    u8 padC0[0xB2];
    s16 unk172;
    u8 pad174[0x30];
    f32 unk1A4;
    f32 unk1A8;
    s16 unk1AC;
    s16 unk1AE;
    s16 unk1B0;
    u8 pad1B2[2];
    u32 r : 8;
    u32 g : 8;
    u32 b : 8;
    u32 pad1B7 : 8;
    u8 pad1B8[4];
    s16 unk1BC;
    u8 pad1BE[0x1E];
    f32 unk1DC;
    u8 pad1E0[4];
    u32 b31 : 1;
    u32 line1 : 1;
    u32 line2 : 1;
    u32 pad1E4_25 : 4;
    u32 b24 : 1;
    u32 pad1E4_20 : 4;
    u32 b19 : 1;
    u32 b18 : 1;
    u32 b17 : 1;
    u32 b16 : 1;
    u32 b15 : 1;
    u32 pad1E4_8 : 7;
    u32 dir : 1;
    u32 pad1E4_2 : 5;
    u32 b1 : 1;
    u32 b0 : 1;
    f32 unk1E8;
    u8 pad1EC[8];
    f32 unk1F4;
} Zoombox_80800FE0_gczoombox;
extern void func_800B7A98(void);
extern void func_800B7B8C(s32, s32, s32);
extern void func_800B7ADC(s32);
extern void func_800B7B38(s32);
extern s32 func_800A8184(void);
extern void func_800B7B2C(s32);
extern void func_800B798C(s32, s32, u8 *);
extern f32 _glintrosyncDll_entrypoint_5(void);
extern f32 func_800D8FF8(void);
typedef union {
    u32 local_0;
    u8 local_1[4];
    struct {
        u32 pad_0 : 8;
        u32 local_0 : 1;
        u32 local_1 : 1;
        u32 local_2 : 1;
        u32 pad_1 : 8;
        u32 local_3 : 1;
        u32 pad_2 : 1;
        u32 local_4 : 1;
        u32 pad_3 : 10;
    } local_2;
} ZoomInputFlags331;
typedef struct {
    u8 pad_0[0xF0];
    u8 local_0[0x50];
    u16 local_1;
    u8 pad_1[0xA];
    f32 local_2;
    u8 pad_2[0x28];
    u8 local_3;
    u8 pad_3[0x56];
    s8 local_4;
    u8 local_5;
    u8 local_6;
    u8 local_7;
    u8 pad_4[0x11];
    ZoomInputFlags331 local_8;
} ZoomInputState331;
extern void func_80015E80(s32, s32 *);
extern void func_80015F28(s32, s32 *);
extern void func_80015ECC(s32, s32 *);
extern void func_80015F5C(s32, s32 *);
typedef struct {
    u8 unk0[0x30];
    u8 unk30[0x30];
    u8 pad60[0x60];
    u8 unkC0[0x30];
    u8 padF0[0x7A];
    s16 unk16A;
    u8 pad16C[4];
    u8 unk170;
    u8 state;
    s16 unk172;
    u8 str_cnt;
    u8 current_str_index;
    u8 pad176;
    u8 unk177;
    u8 pad178[4];
    u8 *raw_str[8];
    u8 unk19C;
    u8 unk19D;
    u8 unk19E;
    u8 pad19F;
    u8 *unk1A0;
    f32 unk1A4;
    f32 unk1A8;
    u8 pad1AC[2];
    s16 unk1AE;
    s16 unk1B0;
    s16 unk1B2;
    u8 pad1B4[0xC];
    f32 unk1C0;
    f32 unk1C4;
    f32 unk1C8;
    u8 unk1CC;
    u8 unk1CD;
    s8 unk1CE;
    u8 unk1CF;
    u8 pad1D0[4];
    f32 unk1D4;
    f32 unk1D8;
    f32 unk1DC;
    f32 unk1E0;
    u32 unk1E4_31 : 1;
    u32 unk1E4_30 : 1;
    u32 unk1E4_29 : 1;
    u32 unk1E4_28 : 1;
    u32 unk1E4_27 : 1;
    u32 unk1E4_26 : 1;
    u32 unk1E4_25 : 1;
    u32 unk1E4_24 : 1;
    u32 unk1E4_23 : 1;
    u32 unk1E4_22 : 1;
    u32 unk1E4_21 : 1;
    u32 unk1E4_20 : 1;
    u32 unk1E4_19 : 1;
    u32 unk1E4_18 : 1;
    u32 unk1E4_17 : 1;
    u32 unk1E4_16 : 1;
    u32 unk1E4_15 : 1;
    u32 unk1E4_14 : 1;
    u32 unk1E4_13 : 1;
    u32 unk1E4_12 : 1;
    u32 unk1E4_11 : 1;
    u32 unk1E4_10 : 1;
    u32 unk1E4_9 : 1;
    u32 unk1E4_8 : 1;
    u32 unk1E4_7 : 1;
    u32 unk1E4_6 : 1;
    u32 unk1E4_5 : 1;
    u32 unk1E4_4 : 1;
    u32 unk1E4_3 : 1;
    u32 unk1E4_2 : 1;
    u32 unk1E4_1 : 1;
    u32 unk1E4_0 : 1;
    f32 unk1E8;
    f32 unk1EC;
    f32 unk1F0;
    f32 unk1F4;
} ZoomBoxUpdate;
extern f32 func_800D9004(void);
extern int _gldialog_entrypoint_1(void *);
extern f32 D_80803E44_gczoombox[];
extern void *heap_alloc(s32);
extern s32 func_800E6A00(void);
extern void _gczoomboxdata_entrypoint_2();
typedef struct {
    u8 pad[0x1E4];
    u32 b31 : 1;
    u32 b30 : 1;
    u32 b29 : 1;
    u32 b28 : 1;
    u32 b27 : 1;
    u32 b26 : 1;
    u32 b25 : 1;
    u32 b24 : 1;
    u32 b23 : 1;
    u32 b22 : 1;
    u32 b21 : 1;
    u32 b20 : 1;
    u32 b19 : 1;
    u32 b18 : 1;
    u32 b17 : 1;
    u32 b16 : 1;
    u16 b15 : 1;
    u16 b14 : 1;
    u32 b13 : 1;
    u32 b12 : 1;
    u32 b11 : 1;
    u32 b10 : 1;
    u32 b9 : 1;
    u32 b8 : 1;
    u32 b7 : 1;
    u32 b6 : 1;
    u32 b5 : 1;
    u32 b4 : 1;
    u32 b3 : 1;
    u32 b2 : 1;
    u32 b1 : 1;
    u32 b0 : 1;
} ZbBits;
typedef struct {
    u8 pad[0x17C];
    s32 raw[8];
} ZbA;
int gczoombox_entrypoint_15();
void gczoombox_entrypoint_16();
void gczoombox_entrypoint_17();
int gczoombox_entrypoint_18();
extern f32 func_800F3780(f32, void *, s32);

void gczoombox_entrypoint_14(u8 *param_0);
void gczoombox_entrypoint_20(u8 *param_0, f32 param_1, s32 param_2, s32 param_3, f32 param_4,
                             s32 param_5, s32 param_6);
void gczoombox_entrypoint_30(u8 *param_0, int param_1);

void func_80800000_gczoombox(u8 *param_0)
{
    s32 local_0;
    s32 local_1;

    if (*(f32 *) (param_0 + 0x14C) == -1.0f) {
        if (func_800FCCD4(param_0[0x144])) {
            func_800FC74C(param_0[0x144]);
        }
    } else {
        for (local_0 = 0; local_0 < 5; local_0++) {
            local_1 = param_0[local_0 + 0x144];
            if (local_1) {
                func_800C2FDC(local_1);
                param_0[0x178]--;
            }
        }
    }
    for (local_0 = 0; local_0 < 5; local_0++) {
        param_0[local_0 + 0x144] = 0;
    }
}

void func_808000C4_gczoombox(void *param_0)
{
    if (*(u16 *) ((char *) param_0 + 0x142) != 0) {
        *(u16 *) ((char *) param_0 + 0x142) = 0;
    }
}

void func_808000DC_gczoombox(u8 *param_0)
{
    if (*(u16 *) (param_0 + 0x140) != 0) {
        *(u16 *) (param_0 + 0x140) = 0;
    }
    func_808000C4_gczoombox(param_0);
}

int gczoombox_entrypoint_0(void *param_0)
{
    if (param_0 != 0) {
        func_800D52B0();
        func_80800000_gczoombox(param_0);
        func_808000DC_gczoombox(param_0);
        heap_free(param_0);
    }
}

void func_8080014C_gczoombox(u8 *param_0, u8 *param_1, s32 start, s32 end)
{
    s32 i;

    for (i = start; i < end; i++) {
        param_1[i - start] = param_0[i];
    }
}

void func_808001D4_gczoombox(u8 *self, s32 param_1)
{
    s32 i;

    for (i = 0; i < param_1; i++) {
        self[i] = 0;
    }
}

void func_80800228_gczoombox(ZoomBoxBounds *param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = param_0->large;
    local_1 = local_0 ? 15 : 12;
    param_0->lower = (f32) (param_0->center - local_1 / 2);
    local_1 = local_0 ? 15 : 12;
    param_0->upper = (f32) local_1 + param_0->lower;
}

void func_80800294_gczoombox(Actor *param_0)
{
    if (((u32) *(s32 *) ((char *) param_0 + 0x1E4) >> 0x1F) &&
        (((*(s32 *) ((char *) param_0 + 0x1E4) << 4) << 1) >= 0)) {
        *(f32 *) ((char *) param_0 + 0x1A4) = *(s16 *) ((char *) param_0 + 0x1B0);
    } else {
        func_80800228_gczoombox(param_0);
    }
}

void func_808002E4_gczoombox(ZoomBoxActivation *param_0)
{
    if (param_0->local_6 || param_0->local_5) {
        param_0->local_0 = 3;
        param_0->local_3 = (f32) param_0->local_4 / 60.0f;
    } else {
        param_0->local_0 = 4;
    }
    param_0->local_2 = param_0->local_1;
    param_0->local_7 = 0;
}

void func_80800358_gczoombox(void *param_0, f32 param_1)
{
    *(f32 *) ((char *) param_0 + 0x1F0) = param_1;
}

f32 func_80800364_gczoombox(ZoomBoxProgress *param_0)
{
    f32 local_0;
    f32 local_1;

    local_0 = param_0->local_3;
    if (param_0->local_1) {
        local_1 = _glintrosyncDll_entrypoint_5();
    } else {
        local_1 = func_800D8FF8();
    }
    local_1 /= param_0->local_4;
    if (!param_0->local_0) {
        local_1 = -local_1;
    }
    param_0->local_3 += local_1;
    return local_0;
}

int func_808003D8_gczoombox(ZoomBoxTimer *param_0, f32 param_1, f32 param_2)
{
    if (param_0->local_0)
        return param_1 <= param_2 && param_2 < param_0->local_1;
    return param_2 <= param_1 && param_0->local_1 < param_2;
}

void func_80800470_gczoombox(ZoomBoxOpenState *param_0)
{
    param_0->state = 5;
    param_0->active = 1;
    param_0->enabled = 1;
    if (param_0->audio) {
        func_80800358_gczoombox(param_0, 0.2f);
    }
    param_0->counter = 0;
    gczoombox_entrypoint_17(param_0);
}

void func_808004D0_gczoombox(u8 *param_0)
{
    s32 local_0;
    param_0[0x171] = 6;
    ((ZoomFlags30 *) (param_0 + 0x1E7))->bit_2 = 0;
    ((ZoomFlags30 *) (param_0 + 0x1E5))->bit_0 = 1;
    ((ZoomFlags30 *) (param_0 + 0x1E5))->bit_7 = 0;
    func_808001D4_gczoombox(param_0, 0x30);
    func_808001D4_gczoombox(param_0 + 0x30, 0x30);
    ((ZoomFlags30 *) (param_0 + 0x1E4))->bit_6 = 0;
    ((ZoomFlags30 *) (param_0 + 0x1E4))->bit_5 = 0;
    ((ZoomFlags30 *) (param_0 + 0x1E4))->bit_3 = 0;
    ((ZoomFlags30 *) (param_0 + 0x1E4))->bit_2 = 0;
    ((ZoomFlags30 *) (param_0 + 0x1E4))->bit_7 = 0;
    if (*(f32 *) (param_0 + 0x14C) == -1.0f) {
        if (func_800FCCD4(param_0[0x144]))
            func_800FC74C(param_0[0x144]);
    } else if (param_0[0x178]) {
        for (local_0 = 0; local_0 < (s32) param_0[0x178]; local_0++) {
            if (func_800C3D78(param_0[0x144 + local_0]))
                func_800C3CE8(param_0[0x144 + local_0]);
        }
    }
    param_0[0x170] = 0;
    gczoombox_entrypoint_18(param_0);
}

int func_808005F0_gczoombox(u8 param_0, u8 param_1)
{
    if (param_1 == 0) {
        return param_0 == '.' || param_0 == '!' || param_0 == ',' || param_0 == '-' ||
               param_0 == '?';
    } else {
        return param_0 == '\1' || param_0 == '4' || param_0 == '@' || param_0 == 'B';
    }
}

int gczoombox_entrypoint_1()
{
    func_800E7188();
}

int func_808006B4_gczoombox(u16 *param_0, u32 param_1)
{
    s32 ret;
    if (param_1 == -1) {
        ret = 0;
    } else {
        ret = (param_1 == ((u32) *(u16 *) (param_0 + 9) >> 1));
    }
    return ret;
}

u8 D_80803E80_gczoombox[32];

void func_808006E0_gczoombox(ZoomBoxMouth *this, s32 count)
{
    s32 n;
    s32 i;
    s32 k;

    n = 0;
    for (i = 0; i < count && n < 0x20; i++) {
        if (n) {
            if (func_800DC1AC() < 0.5f) {
                if (func_800DC1AC() < 0.8f) {
                    D_80803E80_gczoombox[n] = 1;
                } else {
                    D_80803E80_gczoombox[n] = 0;
                }
                n++;
            }
        } else {
            D_80803E80_gczoombox[n] = 1;
            n++;
        }
    }
    D_80803E80_gczoombox[n++] = 0;
    i = 0;
    for (k = 0; k < n; k++) {
        if (D_80803E80_gczoombox[k] == 1) {
            if (D_80803E80_gczoombox[k + 1] == 1) {
                if (D_80803E80_gczoombox[k + 2] == 1) {
                    if (func_800DC1AC() < 0.3f) {
                        this->unkF0[i] = 1;
                    } else {
                        this->unkF0[i] = 2;
                    }
                } else {
                    if (func_800DC1AC() < 0.5f) {
                        this->unkF0[i] = 2;
                    } else {
                        this->unkF0[i] = (this->unk1D1 - 4) / 2;
                    }
                }
            } else {
                this->unkF0[i] = this->unk1D1 - 6;
            }
            i++;
        }
        this->unkF0[i] = 0;
        i++;
    }
    this->unk1D2 = i;
    this->unk1D0 = 0;
}

u8 func_808008F4_gczoombox(void *param_0, s32 param_1, s32 param_2)
{
    u8 local_0;
    s16 local_1;
    local_0 = func_800C429C(param_1, param_2);
    func_800C3418(local_0, 0);
    func_800C34CC(local_0, 0);
    local_1 = *(s16 *) ((u8 *) param_0 + 0x172);
    if (local_1 == 0x80 || local_1 == 0xBB) {
        func_800C32C4(local_0, 0x40);
    }
    return local_0;
}

void func_80800964_gczoombox(u8 *param_0)
{
    s32 local_0;
    u8 *local_1;

    func_800D52B0();
    func_80800000_gczoombox(param_0);
    func_808000DC_gczoombox(param_0);
    local_0 = 0;
    local_1 = param_0;
    do {
        local_0 += 4;
        *(s32 *) ((s8 *) local_1 + 0x180) = 0;
        *(s32 *) ((s8 *) local_1 + 0x184) = 0;
        *(s32 *) ((s8 *) local_1 + 0x188) = 0;
        local_1 += 0x10;
        *(s32 *) ((s8 *) local_1 + 0x16C) = 0;
    } while (local_0 != 8);
    *(s8 *) ((s8 *) param_0 + 0x171) = 0;
    *(u8 *) ((s8 *) param_0 + 0x1E5) = (u8) (*(u8 *) ((s8 *) param_0 + 0x1E5) & 0xFFEF);
    *(s8 *) ((s8 *) param_0 + 0x174) =
        (s8) ((u32) (*(s32 *) ((s8 *) param_0 + 0x1E4) << 0xB) >> 0x1F);
}

void func_808009E4_gczoombox(Zoombox_808009E4_gczoombox *param_0, s32 param_1)
{
    s32 i;
    s32 cur;
    f32 f12;
    f32 f14;
    f32 p;
    f32 d2;
    f32 d18;
    s32 k2;
    f32 local_2[3];

    cur = 0;
    if (param_0 == NULL || !param_0->count || !param_0->b11) {
        return;
    }
    if (param_0->pitch[0] == -1.0f) {
        if (!func_800FCCD4(param_0->sfx[0])) {
            func_800FC6B0(param_0->sfx[0]);
        }
        return;
    }
    for (i = 0; i < param_0->count; i++) {
        if (func_800C3D78(param_0->sfx[i])) {
            func_800C3CE8(param_0->sfx[i]);
        }
    }
    if (param_0->count != 1) {
        do {
            cur = func_800DC214(0, param_0->count);
        } while (cur == param_0->last || param_0->vol[cur] == 0);
    }
    param_0->last = cur;
    k2 = 0;
    d2 = 0.2f;
    d18 = 0.0f;
    if ((p = param_0->pitch[cur]) < -1.0f) {
        do {
            f12 = func_800DC214(-12, 0);
        } while (f12 == -11.0f || f12 == -9.0f || f12 == -7.0f || f12 == -6.0f || f12 == -4.0f ||
                 f12 == -2.0f || f12 == -1.0f);
        p = param_0->pitch[cur];
        if (p < -2.0f) {
            f12 -= (p - -2.0f);
        }
        func_800C31DC(param_0->sfx[cur], func_80027170(f12 * 100.0f));
    } else {
        f12 = (p - d2 < 0.1f) ? 0.1f : p - d2;
        f12 = (f12 >= 2.0f) ? 1.99f : f12;
        f14 = (p - d18 < 2.0f) ? p - d18 : 2.0f;
        f14 = (0.1f < f14) ? f14 : 0.1f;
        func_800C31DC(param_0->sfx[cur], func_800DC264(f12, f14));
    }
    if (param_0->unk172 == param_0->unk13A) {
        if (func_808006B4_gczoombox(param_0->unk130, param_0->unk13C)) {
            func_800EC370(param_0->unk130, param_0->unk134);
            param_0->unk134[1] += _suexpression_entrypoint_0(param_0->unk172);
        }
        local_2[0] = param_0->unk134[0];
        local_2[1] = param_0->unk134[1];
        local_2[2] = param_0->unk134[2];
        func_800C3058(param_0->sfx[cur],
                      func_800DC214((param_0->vol[cur] - 6000 < 0) ? 0 : param_0->vol[cur] - 6000,
                                    (param_0->vol[cur] - k2 < 0) ? 0 : param_0->vol[cur] - k2));
    } else {
        func_800C3058(param_0->sfx[cur],
                      func_800DC214((param_0->vol[cur] - 6000 < 0) ? 0 : param_0->vol[cur] - 6000,
                                    (param_0->vol[cur] - k2 < 0) ? 0 : param_0->vol[cur] - k2));
    }
    func_800C3BDC(param_0->sfx[cur]);
    func_800D52CC(param_0->unk172);
    func_800D527C(cur);
}

int func_80800E24_gczoombox(param_0)
u8 param_0;
{
    return (param_0 >= 0x7F) && (param_0 < 0x88);
}

void func_80800E44_gczoombox(u8 *param_0, u8 *param_1, u8 *param_2)
{
    f32 local_1;
    u8 *local_2;
    s32 local_0[3];
    u8 *p2;
    local_2 = param_1;
    p2 = param_2;
    local_1 = *(s16 *) (param_0 + 0x1AC) / 255.0f;
    local_0[0] = param_0[0x1B4] * local_1;
    local_0[1] = param_0[0x1B5] * local_1;
    local_0[2] = param_0[0x1B6] * local_1;
    *param_1 = 0;
    while (*p2 != 0) {
        if (func_80800E24_gczoombox(*p2)) {
            *local_2 = 0;
            _fxfontstring_entrypoint_3(param_1, ((s16 *) D_80803E80_gczoombox)[0x5F - *p2],
                                       (s32) *(f32 *) (param_0 + 0x1E8));
            local_2 = param_1;
            while (*local_2) {
                local_2++;
            }
        } else {
            *local_2++ = *p2;
        }
        p2++;
    }
    *local_2 = 0;
}

void func_80800FE0_gczoombox(param_0) Zoombox_80800FE0_gczoombox *param_0;
{
    s32 local_1[3];
    f32 local_0;
    s32 local_2;
    s32 local_5;
    f32 local_4;
    f32 local_3;

    local_0 = param_0->unk1AC / 255.0f;
    local_1[0] = param_0->r * local_0;
    local_1[1] = param_0->g * local_0;
    local_1[2] = param_0->b * local_0;
    func_800B7A98();
    func_800B7B8C(local_1[0], local_1[1], local_1[2]);
    func_800B7ADC(param_0->unk1BC);
    if (param_0->b15) {
        func_800B7B38(1);
    } else if (param_0->b19) {
        func_800B7B38(2);
    }
    if (param_0->unk172 == 0x44) {
        local_2 = param_0->unk1AE + 4.0f * param_0->unk1DC;
    } else if (param_0->b24) {
        if (func_800A8184() == 4) {
            local_2 = param_0->unk1AE - param_0->unk1F4 * (216.0f * param_0->unk1DC);
        } else {
            local_2 = (0x130 - param_0->unk1AE) + 8.0f * param_0->unk1DC;
        }
    } else if (param_0->b15) {
        local_2 = param_0->unk1AE + (24.0f * param_0->unk1DC + 8.0f);
    } else {
        local_2 = param_0->unk1AE + (24.0f * param_0->unk1DC + 4.0f);
    }
    if (param_0->line1) {
        if (param_0->b17) {
            local_5 = param_0->b19 ? 15 : 12;
            func_800B7B2C(param_0->unk1B0 - local_5 / 2);
        }
        func_80800E44_gczoombox(param_0, param_0->buf60, param_0->str0);
        func_800B798C(local_2, param_0->unk1A4, param_0->buf60);
    }
    if (param_0->line2) {
        func_800B7B2C(-0x7FFF);
        func_80800E44_gczoombox(param_0, param_0->buf90, param_0->str30);
        func_800B798C(local_2, param_0->unk1A8, param_0->buf90);
    }
    local_3 = param_0->dir ? 1.0f : -1.0f; if (param_0->b1) {
        local_4 = _glintrosyncDll_entrypoint_5();
    } else {
        local_4 = func_800D8FF8();
    }
    param_0->unk1E8 += local_4 * 10.0f * local_3;
    if (4.0f <= param_0->unk1E8) {
        param_0->unk1E8 = 3.999f;
        param_0->dir = (param_0->dir ^ 1) & 1;
    } else if (param_0->unk1E8 < 0.0f) {
        param_0->dir = (param_0->dir ^ 1) & 1;
        param_0->unk1E8 = 0;
    }
}

void func_80801424_gczoombox(u8 *param_0, void *param_1)
{
    _fxdialog_entrypoint_0();
    _fxdialog_entrypoint_1(*(s16 *) (param_0 + 0x1AE), *(s16 *) (param_0 + 0x1B0));
    _fxdialog_entrypoint_2(*(f32 *) (param_0 + 0x1DC));
    _fxdialog_entrypoint_3(param_1,
                           (216.0f * *(f32 *) (param_0 + 0x1DC)) * *(f32 *) (param_0 + 0x1EC),
                           (param_0[0x1E4] & 1) ? 2 : 0, *(s16 *) (param_0 + 0x1BC));
}

void func_808014A8_gczoombox(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4,
                             f32 param_5)
{
    s32 new_var2;
    f32 new_var3;
    f32 temp_f0;
    if (*(s16 *) ((s8 *) param_0 + 0x172) != 0x44) {
        u8 *new_var;
        temp_f0 = *(f32 *) ((s8 *) param_0 + 0x1DC);
        new_var = (u8 *) ((s8 *) param_0 + 0x1E4);
        new_var3 = *(f32 *) ((s8 *) param_0 + 0x1DC);
        new_var2 = param_4;
        _fxdialog_entrypoint_4(
            param_1, new_var2, *(s8 *) ((s8 *) param_0 + 0x1CF), (f32) param_2 * temp_f0,
            (f32) param_3 * temp_f0,
            (s32) (((f32) (*(s16 *) ((s8 *) param_0 + 0x1BC) * *(s16 *) ((s8 *) param_0 + 0x1AC)) *
                    param_5) /
                   255.0f),
            *new_var & 1);
    }
}

void func_8080156C_gczoombox(param_0, param_1) ZoomInputState331 *param_0;
s32 param_1;
{
    s32 local_0[6];
    s32 local_1[3];

    if (!param_0->local_8.local_2.local_4) {
        func_80015E80(0, local_0);
        func_80015F28(0, local_1);
    } else {
        func_80015ECC(0, local_0);
        func_80015F5C(0, local_1);
    }
    if (param_0->local_1) {
        if (param_1 && param_0->local_8.local_2.local_3 && local_0[0]) {
            if (param_0->local_2 == -1.0f) {
                func_808009E4_gczoombox(param_0, 1);
            } else {
                param_0->local_4++;
                param_0->local_4 %= 4;
                if (param_0->local_4 == 0) {
                    func_808009E4_gczoombox(param_0, 1);
                }
            }
        } else if (param_0->local_8.local_2.local_1) {
            if (param_0->local_8.local_2.local_2) {
                param_0->local_4--;
                if (param_0->local_4 <= param_0->local_6 - 4) {
                    param_0->local_4 = 0;
                    param_0->local_8.local_2.local_2 = 0;
                    param_0->local_8.local_2.local_1 = 0;
                }
            } else {
                param_0->local_4++;
                if (param_0->local_4 >= param_0->local_6) {
                    param_0->local_8.local_2.local_2 = 1;
                    param_0->local_4--;
                }
            }
        } else if (param_1) {
            if (!param_0->local_8.local_2.local_3 || !local_1[0] || !(func_8001211C() & 1)) {
                if (param_0->local_2 == -1.0f) {
                    func_808009E4_gczoombox(param_0, 1);
                } else if (param_0->local_3 && param_0->local_4 == 0 &&
                           param_0->local_4 < param_0->local_0[param_0->local_5]) {
                    func_808009E4_gczoombox(param_0, 0);
                }
                param_0->local_8.local_2.local_1 = 0;
                param_0->local_8.local_2.local_2 = 0;
                if (param_0->local_4 == param_0->local_0[param_0->local_5]) {
                    param_0->local_5++;
                    if (param_0->local_5 >= param_0->local_7) {
                        param_0->local_5 = 0;
                        param_0->local_8.local_2.local_0 = 0;
                        if (func_800DC1AC() < 0.4f) {
                            param_0->local_8.local_2.local_1 = 1;
                            param_0->local_4 = param_0->local_6 - 4;
                        }
                    }
                } else if (param_0->local_4 < param_0->local_0[param_0->local_5]) {
                    param_0->local_4++;
                } else {
                    param_0->local_4--;
                }
            } else {
                return;
            }
        } else if (!param_0->local_8.local_2.local_1) {
            if (param_0->local_4 > 0) {
                param_0->local_4--;
            } else if (func_800DC1AC() < 0.01f) {
                param_0->local_8.local_2.local_1 = 1;
                param_0->local_4 = param_0->local_6 - 4;
            }
        }
        if (param_0->local_4 < 0) {
            param_0->local_4 = 0;
        } else if (param_0->local_4 >= param_0->local_6) {
            param_0->local_4 = param_0->local_6 - 1;
        }
    }
}

void gczoombox_entrypoint_2(GcZoombox *this, s32 arg1)
{
    s32 target;

    if (this != NULL && this->b28 && this->unk171 != 0) {
        if (this->b6) {
            target = 0xAA;
        } else {
            target = 0x80;
        }
        func_80800FE0_gczoombox(this);
        func_80801424_gczoombox(this, arg1);
        if (this->unk176 == 2 || (!func_800A819C() && !func_800DA298(0x650))) {
            func_8080156C_gczoombox(this, 0);
        } else {
            func_8080156C_gczoombox(this, this->b23);
        }
        if (!this->b13) {
            func_808014A8_gczoombox(this, arg1, this->unk1B7, this->unk1B8, this->unk140, 1.0f);
        } else {
            func_808014A8_gczoombox(this, arg1, this->unk1B7, this->unk1B8, this->unk140,
                                    1.0f - this->unk1C0);
            func_808014A8_gczoombox(this, arg1, this->unk1B9, this->unk1BA, this->unk142,
                                    this->unk1C0);
        }
        if (!this->b18 && target < this->unk1AC) {
            this->unk1AC -= 0x10;
            this->unk1AC = (target < this->unk1AC) ? this->unk1AC : target;
        }
        if (this->b18 && this->unk1AC < ZB_LIM(this)) {
            this->unk1AC += 0x10;
            this->unk1AC = (this->unk1AC < ZB_LIM(this)) ? this->unk1AC : ZB_LIM(this);
        }
        if (this->unk1AC == 0xFF && this->b5) {
            this->unk1AC = 0xAA;
        }
    }
}

void func_80801B30_gczoombox(u8 *param_0)
{
    param_0[0x171] = 8;
    gczoombox_entrypoint_15(param_0);
    *(f32 *) (param_0 + 0x1E0) = 0.0f;
    if (param_0[0x1E4] & 1) {
        *(s16 *) (param_0 + 0x1AE) = *(s16 *) (param_0 + 0x1B2) + 0x8C;
    } else {
        *(s16 *) (param_0 + 0x1AE) = *(s16 *) (param_0 + 0x1B2) - 0x8C;
    }
}

void func_80801B90_gczoombox(s32 param_0)
{
    s32 local_0;
    local_0 = param_0;
    *(u8 *) (local_0 + 369) = 9;
    gczoombox_entrypoint_16(local_0);
    {
        float f4 = 0.0f;
        *(float *) (local_0 + 0x1E0) = f4;
    }
}

gczoombox_entrypoint_3(u8 *param_0)
{
    return param_0[0x170];
}

void func_80801BD0_gczoombox(u8 *param_0, u32 param_1)
{
    if (param_1 != param_0[0x170]) {
        param_0[0x170] = param_1;
        if (*(void **) (param_0 + 0x16C)) {
            (*(void (**)(s32))(param_0 + 0x16C))(*(s16 *) (param_0 + 0x172));
        }
    }
}

s32 func_80801C0C_gczoombox(ZoomBoxWrap *this, u8 *str)
{
    s32 maxw;
    s32 brk;
    s32 font;
    s32 i;
    s32 w;
    s32 cw;

    maxw = this->unk1DC * 216.0f - 24.0f * this->unk1DC;
    brk = 0;
    font = this->unk1E4_19 ? 2 : this->unk1E6_15 ? 1 : 0;
    for (i = 0, w = 0; str[i] != 0; i++) {
        if (str[i] == 0xFD) {
            i++;
        } else {
            if (func_80800E24_gczoombox(str[i])) {
                cw = 0x18;
            } else {
                cw = func_800D36C4(font, str[i]);
            }
            w += cw;
            if (maxw < w) {
                if (brk == 0) {
                    brk = i;
                }
                if (str[i] == ' ') {
                    w -= cw;
                    break;
                }
            }
        }
    }
    if (brk != 0 && !((f32) (w - maxw) < 6.0f * this->unk1DC)) {
        for (i--; i > 0 && str[i] != ' '; i--)
            ;
        if (i == 0) {
            i = gczoombox_entrypoint_1(str);
        }
    }
    return i;
}

void gczoombox_entrypoint_4(ZoomBoxUpdate *param_0)
{
    s32 local_0[6];
    s32 local_1[3];
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;

    if (!param_0) {
        return;
    }
    if (!param_0->unk1E4_10) {
        func_80015E80(0, local_0);
        func_80015F28(0, local_1);
        if (param_0->unk1E4_1) {
            local_3 = _glintrosyncDll_entrypoint_5();
        } else {
            local_3 = func_800D8FF8();
        }
    } else {
        func_80015ECC(0, local_0);
        func_80015F5C(0, local_1);
        local_3 = func_800D9004();
    }

    switch (param_0->state) {
        case 1:
            if (param_0->unk19D) {
                param_0->unk1A0 += param_0->unk19C + 1;
            } else {
                param_0->unk1A0 = param_0->raw_str[param_0->current_str_index];
                param_0->unk1E4_19 = _gldialog_entrypoint_1(param_0->unk1A0);
            }
            param_0->unk19C = func_80801C0C_gczoombox(param_0, param_0->unk1A0);
            if (param_0->unk1A0[param_0->unk19C]) {
                param_0->unk19D = 1;
            } else {
                param_0->unk19D = 0;
            }
            func_8080014C_gczoombox(param_0->unk1A0, param_0->unkC0, 0, param_0->unk19C);
            param_0->unkC0[param_0->unk19C] = 0;
            if (!param_0->unk19D) {
                param_0->current_str_index++;
            }
            if (param_0->unk19D || param_0->current_str_index < param_0->str_cnt) {
                param_0->unk1E4_25 = 0;
                param_0->unk1E4_31 = 0;
            } else {
                param_0->unk1E4_25 = 1;
                param_0->unk1E4_31 = 1;
            }
            if (param_0->unk1E4_27) {
                param_0->unk1E4_26 = 1;
                param_0->unk1E4_30 = 1;
                param_0->unk1E4_29 = 0;
            } else {
                param_0->unk1E4_26 = 0;
            }
            func_808006E0_gczoombox(param_0, param_0->unk19C);
            param_0->state = 2;
            param_0->unk1CE = param_0->unk19E = 0;
            param_0->unk1D4 = 0.0f;
            if (param_0->unk1E4_19) {
                param_0->unk19E += 2;
            }
            param_0->unk1E4_23 = 1;
            func_80800294_gczoombox(param_0);
            break;
        case 2:
            local_2 = param_0->unk1D8;
            if (param_0->unk1E4_19) {
                local_2 *= 1.5f;
            }
            if (param_0->unk1E4_4) {
                local_2 *= 0.01998901367f;
                param_0->unk1E4_4 = 0;
            } else if (local_0[0] && param_0->unk1E4_12) {
                local_2 *= 0.4499969482f;
            } else if (local_1[0] && param_0->unk1E4_12) {
                local_2 *= (f32) 2.0;
            }
            param_0->unk1D4 += local_3;
            while (local_2 < param_0->unk1D4 && param_0->unk19C >= param_0->unk19E) {
                param_0->unk19E++;
                if (func_808005F0_gczoombox(param_0->unkC0[param_0->unk19E], param_0->unk1E4_19)) {
                    param_0->unk1D4 -=
                        (local_0[0] && param_0->unk1E4_12) ? 0.04999542236f : 0.09999084473f;
                }
                param_0->unk1D4 -= local_2;
            }
            if (param_0->unk1E4_26) {
                if (param_0->unk1E4_3) {
                    param_0->unk30[0] = 0xFD;
                    param_0->unk30[1] = 0x68;
                    func_8080014C_gczoombox(param_0->unkC0, param_0->unk30 + 2, 0, param_0->unk19E);
                    param_0->unk30[param_0->unk19E + 2] = 0;
                } else {
                    func_8080014C_gczoombox(param_0->unkC0, param_0->unk30, 0, param_0->unk19E);
                }
                param_0->unk1E4_29 = 1;
            } else {
                if (param_0->unk1E4_3) {
                    param_0->unk0[0] = 0xFD;
                    param_0->unk0[1] = 0x68;
                    func_8080014C_gczoombox(param_0->unkC0, param_0->unk0 + 2, 0, param_0->unk19E);
                    param_0->unk0[param_0->unk19E + 2] = 0;
                } else {
                    func_8080014C_gczoombox(param_0->unkC0, param_0->unk0, 0, param_0->unk19E);
                }
                param_0->unk1E4_27 = 1;
                param_0->unk1E4_30 = 1;
            }
            if (param_0->unk19C < param_0->unk19E) {
                func_808002E4_gczoombox(param_0);
            }
            break;
        case 3:
            if ((local_0[0] && param_0->unk1E4_12) || param_0->unk1C4 < 0.0f) {
                param_0->state = 4;
                param_0->unk1C8 = 60.0f * local_3 * param_0->unk1CD;
            } else {
                param_0->unk1C4 -= local_3;
            }
            break;
        case 4:
            if (local_0[0] && param_0->unk1E4_12) {
                param_0->unk1C8 = 60.0f * local_3 * (param_0->unk1CD + 2);
                param_0->unk1E4_23 = 0;
            } else if (param_0->unk1E4_12 && local_1[0]) {
                param_0->unk1C8 = 60.0f * local_3 * (param_0->unk1CD - 1);
            }
            param_0->unk1E4_17 = 0;
            if (param_0->unk1E4_26 || param_0->unk1E4_31) {
                if (param_0->unk1E4_25) {
                    if (param_0->unk1E4_6 && param_0->state != 10 && param_0->unk1E4_26) {
                        func_80101238(0x6D, 0);
                    }
                    gczoombox_entrypoint_14(param_0);
                    param_0->state = 10;
                }
                if (!param_0->unk1E4_23 && !param_0->unk1E4_25) {
                    param_0->unk1E4_17 = 1;
                    param_0->unk1A4 -= param_0->unk1C8;
                    param_0->unk1A8 -= param_0->unk1C8;
                }
                if (!param_0->unk1E4_25) {
                    if (param_0->unk1B0 - (param_0->unk1E4_19 ? 15 : 12) * 3 / 2 >=
                        param_0->unk1A4) {
                        func_8080014C_gczoombox(param_0->unk30, param_0->unk0, 0, 0x30);
                        func_808001D4_gczoombox(param_0->unk30, 0x30);
                        func_80800228_gczoombox(param_0);
                        param_0->unk1E4_30 = 1;
                        param_0->unk1E4_29 = 0;
                        param_0->state = 1;
                    }
                }
            } else if (!param_0->unk1E4_23) {
                param_0->state = 1;
            }
            break;
        case 10:
            func_80801BD0_gczoombox(param_0, 3);
            if (param_0->unk177 & 8) {
                param_0->unk1E4_27 = 0;
                func_808004D0_gczoombox(param_0);
            } else if (param_0->unk177 & 4) {
                param_0->unk170 = 0;
                param_0->unk1E4_25 = 0;
                param_0->state = 4;
            }
            break;
        case 5:
            local_4 = -1.0f;
            if (param_0->unk1E4_16) {
                local_4 = func_80800364_gczoombox(param_0);
                if (param_0->unk1E4_14) {
                    param_0->unk1C0 = 1.0f - param_0->unk1EC / param_0->unk1F4;
                }
            }
            if (param_0->unk1E4_11 && param_0->unk1E4_16 &&
                func_808003D8_gczoombox(param_0, local_4, param_0->unk1F4 * 0.1f)) {
                if (func_800C710C(0)) {
                    _gcaudiolist_entrypoint_1(2, param_0->unk16A);
                }
            }
            if (param_0->unk1E4_16 && func_808003D8_gczoombox(param_0, local_4, param_0->unk1F4)) {
                param_0->unk1EC = param_0->unk1F4;
                if (param_0->unk1E4_14) {
                    func_808000C4_gczoombox(param_0);
                }
                param_0->unk1E4_14 = param_0->unk1E4_13 = 0;
                param_0->unk1E4_16 = 0;
            }
            if (!param_0->unk1E4_16) {
                func_80801BD0_gczoombox(param_0, 2);
                if (param_0->unk177 & 4) {
                    param_0->state = 1;
                } else if (param_0->unk177 & 8) {
                    func_808004D0_gczoombox(param_0);
                }
            }
            break;
        case 6:
            local_5 = -1.0f;
            if (param_0->unk1E4_16) {
                local_5 = func_80800364_gczoombox(param_0);
                if (param_0->unk1E4_14) {
                    param_0->unk1C0 = param_0->unk1EC / param_0->unk1F4;
                }
            }
            if (param_0->unk1E4_11 && param_0->unk1E4_16 &&
                func_808003D8_gczoombox(param_0, local_5, param_0->unk1F4 * 0.9f)) {
                if (func_800C710C(1)) {
                    _gcaudiolist_entrypoint_1(3, param_0->unk16A);
                }
            }
            if (param_0->unk1E4_16 && param_0->unk1EC <= 0) {
                param_0->unk1EC = 0;
                if (param_0->unk1E4_14) {
                    func_808000C4_gczoombox(param_0);
                }
                param_0->unk1E4_14 = param_0->unk1E4_13 = 0;
                param_0->unk1E4_16 = 0;
            }
            if (!param_0->unk1E4_16) {
                func_80801BD0_gczoombox(param_0, 4);
                if (param_0->unk177 & 0x10) {
                    func_80801B90_gczoombox(param_0);
                } else if (param_0->unk177 & 2) {
                    func_80800470_gczoombox(param_0);
                }
            }
            break;
        case 7:
            func_80800964_gczoombox(param_0);
            func_80801BD0_gczoombox(param_0, 6);
            break;
        case 8:
            if (param_0->unk1E0 == 0.0f) {
                param_0->unk1E4_28 = 1;
            }
            if (param_0->unk1E4_11 && param_0->unk1E0 == 0) {
                if (func_800C710C(2)) {
                    _gcaudiolist_entrypoint_1(4, param_0->unk16A);
                }
            }
            if (param_0->unk1E4_24) {
                param_0->unk1AE =
                    func_800F3780(param_0->unk1E0, D_80803E44_gczoombox, 7) + param_0->unk1B2;
            } else {
                param_0->unk1AE =
                    param_0->unk1B2 - func_800F3780(param_0->unk1E0, D_80803E44_gczoombox, 7);
            }
            if (param_0->unk1E0 >= 1.0f) {
                param_0->unk1AE = param_0->unk1B2;
                func_80801BD0_gczoombox(param_0, 1);
                if (param_0->unk177 & 2) {
                    func_80800470_gczoombox(param_0);
                } else if (param_0->unk177 & 0x10) {
                    func_80801B90_gczoombox(param_0);
                }
            } else {
                param_0->unk1E0 += 5.0f * local_3;
            }
            break;
        case 9:
            if (param_0->unk1E4_11 && param_0->unk1E0 == 0) {
                if (func_800C710C(3)) {
                    _gcaudiolist_entrypoint_1(5, param_0->unk16A);
                }
            }
            if (param_0->unk1E4_24) {
                param_0->unk1AE = func_800F3780(1.0f - param_0->unk1E0, D_80803E44_gczoombox, 7) +
                                  param_0->unk1B2;
            } else {
                param_0->unk1AE = param_0->unk1B2 -
                                  func_800F3780(1.0f - param_0->unk1E0, D_80803E44_gczoombox, 7);
            }
            if (param_0->unk1E0 >= 1.0f) {
                param_0->unk1E4_28 = 0;
                func_80801BD0_gczoombox(param_0, 5);
                if (param_0->unk177 & 0x20) {
                    param_0->state = 7;
                } else if (param_0->unk177 & 1) {
                    func_80801B30_gczoombox(param_0);
                }
            } else {
                param_0->unk1E0 += 5.0f * local_3;
            }
            break;
        case 11:
            if (param_0->unk177 & 1) {
                func_80801B30_gczoombox(param_0);
            }
    }
}

void func_80802B94_gczoombox(ZoomBoxAssetState *param_0, s32 param_1)
{
    if (param_1 != 0x44) {
        param_0->asset = _gczoomboxdata_entrypoint_1(param_1);
        param_0->count = func_800AF5A0(func_800D674C(param_0->asset));
        param_0->counter = 0;
    } else {
        param_0->asset = 0;
        param_0->count = 0;
    }
}

void func_80802BF4_gczoombox(u8 *param_0)
{
    s32 local_0;

    local_0 = 0;
    if ((s32) *(u8 *) ((s8 *) param_0 + 0x178) > 0) {
        do {
            if (*(u8 *) ((s8 *) param_0 + 0x1E6) & 1) {
                func_800C431C(*(u8 *) ((s8 *) (param_0 + local_0) + 0x144), 0);
            }
            if (*(s32 *) ((s8 *) param_0 + 0x1E4) & 1) {
                func_800C3528(*(u8 *) ((s8 *) (param_0 + local_0) + 0x144), 1);
            }
            local_0 += 1;
        } while (local_0 < (s32) *(u8 *) ((s8 *) param_0 + 0x178));
    }
}

void func_80802C80_gczoombox(ZoomBox *param_0, s32 param_1)
{
    s32 local_2;
    s16 local_0;
    s32 local_3;
    s16 local_1;

    param_0->unk178 = 0;
    for (local_3 = 0; local_3 < 5; local_3++) {
        param_0->unk144[local_3] = 0;
        param_0->unk160[local_3] = 0;
        param_0->unk14C[local_3] = 0.0f;
    }
    if (param_0->unk176 != 2) {
        _gczoomboxdata_entrypoint_4(param_1, 0, &local_0, &param_0->unk160[0], &param_0->unk14C[0]);
        if (param_0->unk14C[0] == -1.0f) {
            param_0->unk144[0] = local_0;
        } else {
            local_2 = _gczoomboxdata_entrypoint_3(param_1);
            for (local_3 = 0; local_3 < local_2; local_3++) {
                _gczoomboxdata_entrypoint_4(param_1, local_3, &local_1, &param_0->unk160[local_3],
                                            &param_0->unk14C[local_3]);
                if (param_0->unk160[local_3] != 0) {
                    param_0->unk144[local_3] = func_808008F4_gczoombox(param_0, local_1, 3);
                    param_0->unk178++;
                }
            }
            param_0->unk1D3 = func_800DC214(0, param_0->unk178);
        }
    }
    func_80802BF4_gczoombox(param_0);
}

u8 *gczoombox_entrypoint_5(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4)
{
    u8 *s0;
    s32 i;
    s32 t;

    s0 = (u8 *) heap_alloc(0x1F8);
    *(s32 *) (s0 + 0x16C) = p4;
    *(u8 *) (s0 + 0x171) = 11;
    *(s16 *) (s0 + 0x172) = p1;
    *(u8 *) (s0 + 0x170) = *(u8 *) (s0 + 0x174) = *(u8 *) (s0 + 0x175) = 0;
    *(u8 *) (s0 + 0x176) = p2;
    *(u8 *) (s0 + 0x177) = 0x20;
    *(s32 *) (s0 + 0x130) = 0;
    *(s16 *) (s0 + 0x13A) = 0;
    *(s32 *) (s0 + 0x13C) = -1;
    for (i = 0; i < 8; i++) {
        ((ZbA *) s0)->raw[i] = 0;
    }
    *(u8 *) (s0 + 0x19E) = 0;
    *(u8 *) (s0 + 0x19D) = 0;
    *(u8 *) (s0 + 0x19C) = 0;
    ZB(s0)->b19 = 0;
    *(s32 *) (s0 + 0x1A0) = 0;
    *(s16 *) (s0 + 0x1AC) = 0xFF;
    *(s16 *) (s0 + 0x1BC) = 0xFF;
    *(u8 *) (s0 + 0x1B4) = 0xFF;
    *(u8 *) (s0 + 0x1B5) = 0xFF;
    *(u8 *) (s0 + 0x1B6) = 0xFF;
    ZB(s0)->b24 = p3;
    ZB(s0)->b9 = 0;
    *(u8 *) (s0 + 0x179) = 0;
    ZB(s0)->b8 = 1;
    ZB(s0)->b7 = 1;
    *(f32 *) (s0 + 0x1E8) = 0.0f;
    if (ZB(s0)->b24) {
        *(s16 *) (s0 + 0x1B2) = 0x104;
        *(s16 *) (s0 + 0x1AE) = 0x190;
    } else {
        *(s16 *) (s0 + 0x1B2) = 0x2C;
        *(s16 *) (s0 + 0x1AE) = -0x60;
    }
    *(s16 *) (s0 + 0x1B0) = p0;
    *(f32 *) (s0 + 0x1A4) = 0.0f;
    *(f32 *) (s0 + 0x1A8) = 0.0f;
    *(f32 *) (s0 + 0x1C4) = *(s8 *) (s0 + 0x1CF) = *(u8 *) (s0 + 0x1D0) = *(u8 *) (s0 + 0x1D2) = 0;
    *(f32 *) (s0 + 0x1E0) = 0.0f;
    *(f32 *) (s0 + 0x1D4) = 0.0f;
    *(u8 *) (s0 + 0x1CE) = (s32) *(f32 *) (s0 + 0x1C4);
    *(f32 *) (s0 + 0x1DC) = 1.0f;
    t = func_800E6A00();
    ZB(s0)->b1 = t;
    ZB(s0)->b31 = ZB(s0)->b30 = ZB(s0)->b29 = ZB(s0)->b28 = ZB(s0)->b27 = ZB(s0)->b26 =
        ZB(s0)->b25 = ZB(s0)->b23 = ZB(s0)->b22 = ZB(s0)->b21 = ZB(s0)->b20 = ZB(s0)->b17 =
            ZB(s0)->b16 = ZB(s0)->b15 = ZB(s0)->b14 = ZB(s0)->b13 = 0;
    ZB(s0)->b0 = 0;
    ZB(s0)->b11 = ZB(s0)->b18 = 1;
    ZB(s0)->b6 = 0;
    ZB(s0)->b5 = 0;
    ZB(s0)->b4 = 0;
    ZB(s0)->b3 = 0;
    func_80802B94_gczoombox(s0, p1);
    ZB(s0)->b2 = 1;
    *(f32 *) (s0 + 0x1EC) = 0.0f;
    *(f32 *) (s0 + 0x1F4) = 1.0f;
    gczoombox_entrypoint_20(s0, 15.0f, 5, 2, 0.4f, 0, 0);
    _gczoomboxdata_entrypoint_2(p1, (s8 *) (s0 + 0x1B7), (s8 *) (s0 + 0x1B8));
    *(s8 *) (s0 + 0x1BA) = 0;
    *(s8 *) (s0 + 0x1B9) = *(s8 *) (s0 + 0x1BA);
    *(f32 *) (s0 + 0x1C0) = 1.0f;
    *(s16 *) (s0 + 0x142) = 0;
    func_80802C80_gczoombox(s0, p1);
    gczoombox_entrypoint_30(s0, 0x4650);
    func_808001D4_gczoombox(s0, 0x30);
    func_808001D4_gczoombox(s0 + 0x30, 0x30);
    func_808001D4_gczoombox(s0 + 0xC0, 0x30);
    func_808001D4_gczoombox(s0 + 0xF0, 0x40);
    return s0;
}

gczoombox_entrypoint_6(u8 *param_0)
{
    return param_0[0x178];
}

int gczoombox_entrypoint_7(ZoomStrings1459 *param_0, s32 param_1, char **param_2)
{
    s32 local_0;

    if ((param_0->flags & 4) || param_2 == NULL || param_1 == 0) {
        return 0;
    }
    param_0->index = 0;
    param_0->count = param_1;
    for (local_0 = 0; local_0 < param_1; local_0++) {
        param_0->strings[local_0] = param_2[local_0];
    }
    for (local_0 = param_1; local_0 < 8; local_0++) {
        param_0->strings[local_0] = NULL;
    }
    param_0->flags |= 4;
    return 1;
}

int gczoombox_entrypoint_8(u8 *param_0, u32 param_1)
{
    u32 local_0;
    if ((param_0[0x177] & 4) || !param_1) {
        return 0;
    }
    {
        local_0 = param_1 | 0;
        return gczoombox_entrypoint_7(param_0, 1, &local_0);
    }
}

void gczoombox_entrypoint_9(void *param_0)
{
    ((char *) param_0)[0x177] |= 1;
}

void gczoombox_entrypoint_10(void *param_0)
{
    ((u8 *) param_0)[0x177] |= 0x10;
}

gczoombox_entrypoint_11(u8 *param_0)
{
    param_0[0x177] |= 0x02;
}

gczoombox_entrypoint_12(u8 *param_0)
{
    param_0[0x177] |= 0x8;
}

gczoombox_entrypoint_13(u8 *param_0)
{
    param_0[0x177] |= 0x20;
}

void gczoombox_entrypoint_14(u8 *param_0)
{
    s32 var_v0;
    u8 *var_v1;

    var_v0 = 0;
    var_v1 = param_0;
    do {
        var_v0 += 4;
        *(s32 *) ((s8 *) var_v1 + 0x180) = 0;
        *(s32 *) ((s8 *) var_v1 + 0x184) = 0;
        *(s32 *) ((s8 *) var_v1 + 0x188) = 0;
        var_v1 += 0x10;
        *(s32 *) ((s8 *) var_v1 + 0x16C) = 0;
    } while (var_v0 != 8);
    *(s8 *) ((s8 *) param_0 + 0x174) = 0;
    *(s8 *) ((s8 *) param_0 + 0x175) = 0;
    *(u8 *) ((s8 *) param_0 + 0x177) = (u8) (*(u8 *) ((s8 *) param_0 + 0x177) & 0xFB);
}

int gczoombox_entrypoint_15(param_0)
u8 *param_0;
{
    int new_var;
    char new_var2;
    new_var = 1;
    new_var2 = ~new_var;
    param_0[0x177] &= new_var2;
}

void gczoombox_entrypoint_16(param_0) void *param_0;
{
    ((char *) param_0)[0x177] &= (unsigned char) ~0x10;
}

void gczoombox_entrypoint_17(param_0) void *param_0;
{
    int new_var3;
    void *new_var;
    void *new_var2;
    u8 local_0;
    local_0 =
        ((new_var3 = ((((((((((u8 *) param_0)[0x177] & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) &
                          0xFFFFFFFFu) &
                         0xFFFFFFFFu) &
                        0xFFFFFFFFu) &
                       0xFFFFFFFFu) &
                      0xFFFFFFFFu) &
                     0xFFFFFFFFu) &
         0xFFFFFFFFu) &
        0xFFFFFFFFu;
    new_var = param_0;
    new_var2 = new_var;
    local_0 &= 0xFD;
    ((u8 *) new_var2)[0x177] = local_0;
}

int gczoombox_entrypoint_18(param_0)
u8 *param_0;
{
    param_0[0x177] &= ~0x08 & 0xFF;
}

void gczoombox_entrypoint_19(void *param_0)
{
    char new_var;
    new_var = ~0x20;
    ((char *) param_0)[0x177] &= new_var;
}

void gczoombox_entrypoint_20(u8 *param_0, f32 param_1, s32 param_2, s32 param_3, f32 param_4,
                             s32 param_5, s32 param_6)
{
    if (param_0) {
        param_0[0x1CC] = param_2;
        param_0[0x1CD] = param_3;
        *(f32 *) (param_0 + 0x1D8) = 1.0f / param_1;
        func_80800358_gczoombox(param_0, param_4);
        if (param_5) {
            ((ZoomFlags30 *) (param_0 + 0x1E6))->bit_4 = 1;
        } else {
            ((ZoomFlags30 *) (param_0 + 0x1E6))->bit_4 = 0;
        }
        if (param_6) {
            ((ZoomFlags30 *) (param_0 + 0x1E6))->bit_2 = 1;
        } else {
            ((ZoomFlags30 *) (param_0 + 0x1E6))->bit_2 = 0;
        }
    }
}

int gczoombox_entrypoint_21(u8 *param_0, s32 param_1)
{
    int new_var;
    new_var = param_1;
    if (new_var) {
        if ((!(new_var & 0xFF) && !new_var) && !new_var) {
        }
        param_0[485] |= (long) 0x4;
    } else {
        param_0[485] &= 0xFFFB;
    }
}

s32 gczoombox_entrypoint_22(s32 param_0)
{
    return (u32) (*(s32 *) ((char *) param_0 + 0x1E4) << 13) >> 31;
}

int gczoombox_entrypoint_23(u8 *param_0, unsigned int param_1)
{
    if (param_0 != 0) {
        if (param_1 != 0) {
            param_0[0x1E6] = (param_0[0x1E6] & 0xFFFFu) | 8;
        } else {
            param_0[0x1E6] &= ~8;
        }
    }
}

void gczoombox_entrypoint_24(u8 *param_0, s32 param_1)
{
    if (param_1 != 0) {
        param_0[0x1e6] = (param_0[0x1e6] & 0xFFu) | 1;
    } else {
        param_0[0x1e6] = param_0[0x1e6] & 0xFFFE;
    }
    func_80802BF4_gczoombox(param_0);
}

void gczoombox_entrypoint_25(u8 *param_0, s32 param_1)
{
    if (param_1 != 0) {
        param_0[0x1E7] = (param_0[0x1E7] & 0xFFu) | 1;
    } else {
        param_0[0x1E7] = param_0[0x1E7] & 0xFFFE;
    }
    func_80802BF4_gczoombox(param_0);
}

void gczoombox_entrypoint_26(ZoomBoxPlacement *param_0, int param_1, f32 param_2, f32 param_3,
                             s32 param_4)
{
    if (param_0) {
        if (param_0->local_4) {
            param_0->local_1 = 0x130 - param_1;
            param_0->local_0 = 0x1BC - param_1;
        } else {
            param_0->local_1 = param_1;
            param_0->local_0 = param_1 - 0x8C;
        }
        param_0->local_2 = param_2;
        param_0->local_3 = param_3;
        if (param_4) {
            param_0->local_5 = 1;
        } else {
            param_0->local_5 = 0;
        }
    }
}

void gczoombox_entrypoint_27(void *param_0, s16 param_1[3])
{
    if (param_0 != 0) {
        *(s8 *) ((char *) param_0 + 0x1B4) = param_1[0];
        *(s8 *) ((char *) param_0 + 0x1B5) = param_1[1];
        *(s8 *) ((char *) param_0 + 0x1B6) = param_1[2];
    }
}

void gczoombox_entrypoint_28(u8 *param_0, s16 param_1)
{
    if (param_0 != NULL) {
        *(s16 *) (param_0 + 0x1BC) = param_1;
    }
}

s16 gczoombox_entrypoint_29(u8 *param_0)
{
    if (param_0 == NULL) {
        return 0xFF;
    }
    return *(s16 *) (param_0 + 0x1BC);
}

void gczoombox_entrypoint_30(u8 *param_0, int param_1)
{
    s8 *new_var;
    if (param_0 != 0) {
        new_var = (s8 *) param_0;
        *(s16 *) (new_var + 0x16A) = param_1;
    }
}

void gczoombox_entrypoint_31(void *param_0)
{
    ((char *) param_0)[0x177] = 0;
}

s32 gczoombox_entrypoint_32(u8 *param_0)
{
    if (!param_0 || param_0[0x171] == 0 || param_0[0x171] == 11 || param_0[0x171] == 9) {
        return 0;
    }
    func_808001D4_gczoombox(param_0 + 0xC0, 0x30);
    func_808001D4_gczoombox(param_0, 0x30);
    func_808001D4_gczoombox(param_0 + 0x30, 0x30);
    ((ZoomFlags30 *) (param_0 + 0x1E4))->bit_6 = ((ZoomFlags30 *) (param_0 + 0x1E4))->bit_5 =
        ((ZoomFlags30 *) (param_0 + 0x1E4))->bit_3 = ((ZoomFlags30 *) (param_0 + 0x1E4))->bit_2 =
            ((ZoomFlags30 *) (param_0 + 0x1E4))->bit_7 =
                ((ZoomFlags30 *) (param_0 + 0x1E5))->bit_7 = param_0[0x19D] = 0;
    *(s32 *) (param_0 + 0x1A0) = 0;
    if (param_0[0x171] == 10 || param_0[0x171] == 1 || param_0[0x171] == 2 || param_0[0x171] == 3 ||
        param_0[0x171] == 4) {
        param_0[0x171] = 10;
        param_0[0x170] = 3;
    }
    gczoombox_entrypoint_14(param_0);
    return 1;
}

s32 gczoombox_entrypoint_33(u8 *param_0)
{
    s32 local_0;
    const s32 local_1 = 6;

    if (!param_0 || !(local_0 = param_0[0x171]) || local_0 == 7 || local_0 == 9) {
        return 0;
    }
    if (local_1 == local_0 && param_0[0x170] == 4) {
        return 0;
    }
    if (local_0 == 8) {
        ((ZoomFlags30 *) (param_0 + 0x1E5))->bit_0 = 0;
        param_0[0x171] = 6;
    } else if (local_1 != local_0) {
        func_808004D0_gczoombox(param_0);
    }
    gczoombox_entrypoint_14(param_0);
    gczoombox_entrypoint_17(param_0);
    return 1;
}

int gczoombox_entrypoint_34(u8 *param_0)
{
    if (!param_0 || param_0[0x171] == 0 || param_0[0x171] == 7 || param_0[0x171] == 9) {
        return 0;
    }
    {
        gczoombox_entrypoint_10(param_0);
        gczoombox_entrypoint_13(param_0);
        func_808004D0_gczoombox(param_0);
        return 1;
    }
}

void gczoombox_entrypoint_35(param_0, param_1, param_2, param_3) s32 param_0;
s32 param_1;
u16 param_2;
s32 param_3;
{
    int new_var2;
    s32 *new_var;
    param_2 += 0;
    new_var2 = 0x13A;
    *(s32 *) (param_0 + 0x130) = param_1;
    *(u16 *) (param_0 + new_var2) = param_2;
    *(s32 *) (param_0 + 0x13C) = param_3;
    new_var = (s32 *) (param_0 + 0x134);
    func_800EC370(param_1 | (param_1 * 0), new_var);
}

void gczoombox_entrypoint_36(u8 *param_0, s16 param_1)
{
    u8 local_0;
    if (param_1 != *(s16 *) ((s8 *) param_0 + 0x172)) {
        *(s16 *) ((s8 *) param_0 + 0x140) = 0;
        func_808000C4_gczoombox(param_0);
        func_80802B94_gczoombox(param_0, param_1);
        if (1) {
            _gczoomboxdata_entrypoint_2(param_1, param_0 + 0x1B7, param_0 + 0x1B8);
            func_80800000_gczoombox(param_0);
            func_80802C80_gczoombox(param_0, param_1);
            local_0 = (*(u8 *) ((s8 *) param_0 + 0x1E6) & 0xFF) & 0xFFBF;
            *(u8 *) ((s8 *) param_0 + 0x1E6) = local_0;
        }
        *(s16 *) ((s8 *) param_0 + 0x172) = param_1;
        *(u8 *) ((s8 *) param_0 + 0x1E6) = (u8) (local_0 & 0xDF);
        *(f32 *) ((s8 *) param_0 + 0x1C0) = 1.0f;
    }
}

s32 gczoombox_entrypoint_37(ZoomState31 *param_0, s16 param_1)
{
    if (!param_0 || param_1 == param_0->local_3 ||
        (param_0->local_2 != 6 && param_0->local_2 != 0xA && param_0->local_2 != 0xB &&
         param_0->local_2 != 9)) {
        return 0;
    }
    if (param_0->local_2 == 0xB || param_0->local_2 == 9) {
        gczoombox_entrypoint_36(param_0, param_1);
    } else {
        if (param_0->local_1) {
            param_0->local_1 = 0;
        }
        if (param_0->local_0) {
            param_0->local_1 = param_0->local_0;
        }
        param_0->local_6 = param_0->local_4;
        param_0->local_7 = param_0->local_5;
        func_80802B94_gczoombox((void *) param_0, param_1);
        _gczoomboxdata_entrypoint_2(param_1, &param_0->local_4, &param_0->local_5);
        func_80800000_gczoombox(param_0);
        func_80802C80_gczoombox(param_0, param_1);
        param_0->local_3 = param_1;
        param_0->local_8 = 1.0f;
        param_0->local_9 = 1;
        param_0->local_10 = 1;
    }
    return 1;
}

s32 gczoombox_entrypoint_38(void *texture, s32 param_1)
{
    if (texture != 0) {
        *(s16 *) ((char *) texture + 0x1B0) = param_1;
        func_80800294_gczoombox(texture);
    }
}

int gczoombox_entrypoint_39(u8 *param_0)
{
    return param_0 != NULL && param_0[0x171] == 0;
}

void gczoombox_entrypoint_40(u8 *param_0, s32 param_1)
{
    u8 local_0[0x30];
    u8 local_1[0x30];
    if (param_0) {
        if (((Sol61ZoomFlags *) (param_0 + 0x1E4))->local_1) {
            if (param_1 && !((Sol61ZoomFlags *) (param_0 + 0x1E4))->local_4) {
                if (param_0[0] == 0xFD)
                    param_0[1] = 0x68;
                else {
                    func_8080014C_gczoombox(param_0, local_0, 0, 0x30);
                    param_0[0] = 0xFD;
                    param_0[1] = 0x68;
                    func_8080014C_gczoombox(local_0, param_0 + 2, 0, 0x2E);
                }
                ((Sol61ZoomFlags *) (param_0 + 0x1E4))->local_4 = 1;
            } else if (!param_1 && ((Sol61ZoomFlags *) (param_0 + 0x1E4))->local_4) {
                if (param_0[0] == 0xFD)
                    param_0[1] = 0x6C;
                ((Sol61ZoomFlags *) (param_0 + 0x1E4))->local_4 = 0;
            }
        }
        if (((Sol61ZoomFlags *) (param_0 + 0x1E4))->local_2) {
            if (param_1) {
                if (param_0[0x30] == 0xFD)
                    param_0[0x31] = 0x68;
                else {
                    func_8080014C_gczoombox(param_0 + 0x30, local_1, 0, 0x30);
                    param_0[0x30] = 0xFD;
                    param_0[0x31] = 0x68;
                    func_8080014C_gczoombox(local_1, param_0 + 0x32, 0, 0x2E);
                }
                ((Sol61ZoomFlags *) (param_0 + 0x1E4))->local_4 = 1;
            } else {
                if (param_0[0x30] == 0xFD)
                    param_0[0x31] = 0x6C;
                ((Sol61ZoomFlags *) (param_0 + 0x1E4))->local_4 = 0;
            }
        }
    }
}

void gczoombox_entrypoint_41(void *param_0, f32 param_1)
{
    *(float *) ((char *) param_0 + 0x1D8) = 1.0f / param_1;
}

void gczoombox_entrypoint_42(s32 param_0, f32 param_1)
{
    func_80800358_gczoombox(param_0, param_1);
}

void gczoombox_entrypoint_43(u8 *param_0, s32 param_1)
{
    int new_var;
    new_var = !param_1;
    if (param_1 != 0) {
        if ((new_var && !param_1) && !param_1) {
        }
        param_0[0x1E7] |= 0x40;
    } else {
        param_0[0x1E7] &= ~0x40;
    }
}

int gczoombox_entrypoint_44(u8 *param_0, s32 param_1)
{
    int new_var;
    s16 new_var2;
    new_var = param_1;
    if (new_var) {
        if ((!(new_var & 0xFF) && !new_var) && !new_var) {
        }
        param_0[487] |= (long) 0x20;
    } else {
        new_var2 = 0xFFDF;
        param_0[487] &= new_var2;
    }
}

int gczoombox_entrypoint_45(u8 *param_0, s32 param_1)
{
    int new_var2;
    int new_var;
    new_var = param_1;
    if (new_var) {
        new_var2 = new_var & 0xFF;
        if ((!new_var2 && !new_var) && !new_var) {
        }
        param_0[487] |= (long) 0x10;
    } else {
        param_0[487] &= 65519;
    }
}

u32 D_80803E30_gczoombox[5] = {0xB580B59, 0xB5A0B5D, 0xB5C0B5B, 0xB5F0B5E, 0xB600000};
f32 D_80803E44_gczoombox[15] = {0.0f,    1.4e+02f, 0.1666f, 7e+01f, 0.3333f, 35.0f, 0.5f, 18.0f,
                                0.6666f, 9.0f,     0.8333f, 4.0f,   1.0f,    0.0f,  0.0f};
