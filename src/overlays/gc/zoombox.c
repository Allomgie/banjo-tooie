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
    u16 unk1E6_15 : 1; // sign bit of 0x1E6 as a 1-bit bitfield (lh; bgez)
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

void func_80800000_gczoombox(u8 *zoombox)
{
    s32 i;
    s32 sfx_id;

    if (*(f32 *) (zoombox + 0x14C) == -1.0f) {
        if (func_800FCCD4(zoombox[0x144])) {
            func_800FC74C(zoombox[0x144]);
        }
    } else {
        for (i = 0; i < 5; i++) {
            sfx_id = zoombox[i + 0x144];
            if (sfx_id) {
                func_800C2FDC(sfx_id);
                zoombox[0x178]--;
            }
        }
    }
    for (i = 0; i < 5; i++) {
        zoombox[i + 0x144] = 0;
    }
}

void func_808000C4_gczoombox(void *zoombox)
{
    if (*(u16 *) ((char *) zoombox + 0x142) != 0) {
        *(u16 *) ((char *) zoombox + 0x142) = 0;
    }
}

void func_808000DC_gczoombox(u8 *zoombox)
{
    if (*(u16 *) (zoombox + 0x140) != 0) {
        *(u16 *) (zoombox + 0x140) = 0;
    }
    func_808000C4_gczoombox(zoombox);
}

int gczoombox_entrypoint_0(void *zoombox)
{
    if (zoombox != 0) {
        func_800D52B0();
        func_80800000_gczoombox(zoombox);
        func_808000DC_gczoombox(zoombox);
        heap_free(zoombox);
    }
}

void func_8080014C_gczoombox(u8 *src, u8 *dst, s32 start, s32 end)
{
    s32 i;

    for (i = start; i < end; i++) {
        dst[i - start] = src[i];
    }
}

void func_808001D4_gczoombox(u8 *buf, s32 size)
{
    s32 i;

    for (i = 0; i < size; i++) {
        buf[i] = 0;
    }
}

void func_80800228_gczoombox(ZoomBoxBounds *bounds)
{
    s32 is_large;
    s32 height;

    is_large = bounds->large;
    height = is_large ? 15 : 12;
    bounds->lower = (f32) (bounds->center - height / 2);
    height = is_large ? 15 : 12;
    bounds->upper = (f32) height + bounds->lower;
}

void func_80800294_gczoombox(Actor *zoombox)
{
    if (((u32) *(s32 *) ((char *) zoombox + 0x1E4) >> 0x1F) &&
        (((*(s32 *) ((char *) zoombox + 0x1E4) << 4) << 1) >= 0)) {
        *(f32 *) ((char *) zoombox + 0x1A4) = *(s16 *) ((char *) zoombox + 0x1B0);
    } else {
        func_80800228_gczoombox(zoombox);
    }
}

void func_808002E4_gczoombox(ZoomBoxActivation *zoombox)
{
    if (zoombox->local_6 || zoombox->local_5) {
        zoombox->local_0 = 3;
        zoombox->local_3 = (f32) zoombox->local_4 / 60.0f;
    } else {
        zoombox->local_0 = 4;
    }
    zoombox->local_2 = zoombox->local_1;
    zoombox->local_7 = 0;
}

void func_80800358_gczoombox(void *zoombox, f32 value)
{
    *(f32 *) ((char *) zoombox + 0x1F0) = value;
}

f32 func_80800364_gczoombox(ZoomBoxProgress *zoombox)
{
    f32 prev;
    f32 delta;

    prev = zoombox->local_3;
    if (zoombox->local_1) {
        delta = _glintrosyncDll_entrypoint_5();
    } else {
        delta = func_800D8FF8();
    }
    delta /= zoombox->local_4;
    if (!zoombox->local_0) {
        delta = -delta;
    }
    zoombox->local_3 += delta;
    return prev;
}

int func_808003D8_gczoombox(ZoomBoxTimer *zoombox, f32 progress, f32 mark)
{
    if (zoombox->local_0)
        return progress <= mark && mark < zoombox->local_1;
    return mark <= progress && zoombox->local_1 < mark;
}

void func_80800470_gczoombox(ZoomBoxOpenState *zoombox)
{
    zoombox->state = 5;
    zoombox->active = 1;
    zoombox->enabled = 1;
    if (zoombox->audio) {
        func_80800358_gczoombox(zoombox, 0.2f);
    }
    zoombox->counter = 0;
    gczoombox_entrypoint_17(zoombox);
}

void func_808004D0_gczoombox(u8 *zoombox)
{
    s32 i;
    zoombox[0x171] = 6;
    ((ZoomFlags30 *) (zoombox + 0x1E7))->bit_2 = 0;
    ((ZoomFlags30 *) (zoombox + 0x1E5))->bit_0 = 1;
    ((ZoomFlags30 *) (zoombox + 0x1E5))->bit_7 = 0;
    func_808001D4_gczoombox(zoombox, 0x30);
    func_808001D4_gczoombox(zoombox + 0x30, 0x30);
    ((ZoomFlags30 *) (zoombox + 0x1E4))->bit_6 = 0;
    ((ZoomFlags30 *) (zoombox + 0x1E4))->bit_5 = 0;
    ((ZoomFlags30 *) (zoombox + 0x1E4))->bit_3 = 0;
    ((ZoomFlags30 *) (zoombox + 0x1E4))->bit_2 = 0;
    ((ZoomFlags30 *) (zoombox + 0x1E4))->bit_7 = 0;
    if (*(f32 *) (zoombox + 0x14C) == -1.0f) {
        if (func_800FCCD4(zoombox[0x144]))
            func_800FC74C(zoombox[0x144]);
    } else if (zoombox[0x178]) {
        for (i = 0; i < (s32) zoombox[0x178]; i++) {
            if (func_800C3D78(zoombox[0x144 + i]))
                func_800C3CE8(zoombox[0x144 + i]);
        }
    }
    zoombox[0x170] = 0;
    gczoombox_entrypoint_18(zoombox);
}

// Returns whether ch is a punctuation character.
int func_808005F0_gczoombox(u8 ch, u8 mode)
{
    if (mode == 0) {
        return ch == '.' || ch == '!' || ch == ',' || ch == '-' ||
               ch == '?';
    } else {
        return ch == '\1' || ch == '4' || ch == '@' || ch == 'B';
    }
}

int gczoombox_entrypoint_1()
{
    func_800E7188();
}

int func_808006B4_gczoombox(u16 *entry, u32 id)
{
    s32 ret;
    if (id == -1) {
        ret = 0;
    } else {
        ret = (id == ((u32) *(u16 *) (entry + 9) >> 1));
    }
    return ret;
}

// TU-NOTE: this .bss is defined in C ahead of its first use: IDO places .bss objects used
// before their definition first, the rest in definition order.
u8 D_80803E80_gczoombox[32];

// Builds the random mouth animation; twin of BK zoombox.c func_8031594C.
void func_808006E0_gczoombox(ZoomBoxMouth *this, s32 count)
{
    s32 len;
    s32 i;
    s32 k;

    len = 0;
    for (i = 0; i < count && len < 0x20; i++) {
        if (len) {
            if (func_800DC1AC() < 0.5f) {
                if (func_800DC1AC() < 0.8f) {
                    D_80803E80_gczoombox[len] = 1;
                } else {
                    D_80803E80_gczoombox[len] = 0;
                }
                len++;
            }
        } else {
            D_80803E80_gczoombox[len] = 1;
            len++;
        }
    }
    D_80803E80_gczoombox[len++] = 0;
    i = 0;
    for (k = 0; k < len; k++) {
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

u8 func_808008F4_gczoombox(void *zoombox, s32 sound_id, s32 unk_0)
{
    u8 sfx_id;
    s16 dialog_id;
    sfx_id = func_800C429C(sound_id, unk_0);
    func_800C3418(sfx_id, 0);
    func_800C34CC(sfx_id, 0);
    dialog_id = *(s16 *) ((u8 *) zoombox + 0x172);
    if (dialog_id == 0x80 || dialog_id == 0xBB) {
        func_800C32C4(sfx_id, 0x40);
    }
    return sfx_id;
}

void func_80800964_gczoombox(u8 *zoombox)
{
    s32 i;
    u8 *cursor;

    func_800D52B0();
    func_80800000_gczoombox(zoombox);
    func_808000DC_gczoombox(zoombox);
    i = 0;
    cursor = zoombox;
    do {
        i += 4;
        *(s32 *) ((s8 *) cursor + 0x180) = 0;
        *(s32 *) ((s8 *) cursor + 0x184) = 0;
        *(s32 *) ((s8 *) cursor + 0x188) = 0;
        cursor += 0x10;
        *(s32 *) ((s8 *) cursor + 0x16C) = 0;
    } while (i != 8);
    // Matching: the redundant (s8 *) casts are needed for the match.
    *(s8 *) ((s8 *) zoombox + 0x171) = 0;
    *(u8 *) ((s8 *) zoombox + 0x1E5) = (u8) (*(u8 *) ((s8 *) zoombox + 0x1E5) & 0xFFEF);
    *(s8 *) ((s8 *) zoombox + 0x174) =
        (s8) ((u32) (*(s32 *) ((s8 *) zoombox + 0x1E4) << 0xB) >> 0x1F);
}

// Plays a random voice blip.
void func_808009E4_gczoombox(Zoombox_808009E4_gczoombox *zoombox, s32 unk_0)
{
    s32 i;
    s32 voice;
    f32 lo;
    f32 hi;
    f32 base_pitch;
    f32 lo_delta;
    f32 hi_delta;
    // Matching: these constants held in locals are needed for the match.
    s32 vol_cut;
    f32 unk_1[3];

    voice = 0;
    if (zoombox == NULL || !zoombox->count || !zoombox->b11) {
        return;
    }
    if (zoombox->pitch[0] == -1.0f) {
        if (!func_800FCCD4(zoombox->sfx[0])) {
            func_800FC6B0(zoombox->sfx[0]);
        }
        return;
    }
    for (i = 0; i < zoombox->count; i++) {
        if (func_800C3D78(zoombox->sfx[i])) {
            func_800C3CE8(zoombox->sfx[i]);
        }
    }
    if (zoombox->count != 1) {
        do {
            voice = func_800DC214(0, zoombox->count);
        } while (voice == zoombox->last || zoombox->vol[voice] == 0);
    }
    zoombox->last = voice;
    vol_cut = 0;
    lo_delta = 0.2f;
    hi_delta = 0.0f;
    if ((base_pitch = zoombox->pitch[voice]) < -1.0f) {
        do {
            lo = func_800DC214(-12, 0);
        } while (lo == -11.0f || lo == -9.0f || lo == -7.0f || lo == -6.0f || lo == -4.0f ||
                 lo == -2.0f || lo == -1.0f);
        base_pitch = zoombox->pitch[voice];
        if (base_pitch < -2.0f) {
            lo -= (base_pitch - -2.0f);
        }
        func_800C31DC(zoombox->sfx[voice], func_80027170(lo * 100.0f));
    } else {
        lo = (base_pitch - lo_delta < 0.1f) ? 0.1f : base_pitch - lo_delta;
        lo = (lo >= 2.0f) ? 1.99f : lo;
        hi = (base_pitch - hi_delta < 2.0f) ? base_pitch - hi_delta : 2.0f;
        hi = (0.1f < hi) ? hi : 0.1f;
        func_800C31DC(zoombox->sfx[voice], func_800DC264(lo, hi));
    }
    if (zoombox->unk172 == zoombox->unk13A) {
        if (func_808006B4_gczoombox(zoombox->unk130, zoombox->unk13C)) {
            func_800EC370(zoombox->unk130, zoombox->unk134);
            zoombox->unk134[1] += _suexpression_entrypoint_0(zoombox->unk172);
        }
        unk_1[0] = zoombox->unk134[0];
        unk_1[1] = zoombox->unk134[1];
        unk_1[2] = zoombox->unk134[2];
        func_800C3058(zoombox->sfx[voice],
                      func_800DC214((zoombox->vol[voice] - 6000 < 0) ? 0 : zoombox->vol[voice] - 6000,
                                    (zoombox->vol[voice] - vol_cut < 0) ? 0 : zoombox->vol[voice] - vol_cut));
    } else {
        func_800C3058(zoombox->sfx[voice],
                      func_800DC214((zoombox->vol[voice] - 6000 < 0) ? 0 : zoombox->vol[voice] - 6000,
                                    (zoombox->vol[voice] - vol_cut < 0) ? 0 : zoombox->vol[voice] - vol_cut));
    }
    func_800C3BDC(zoombox->sfx[voice]);
    func_800D52CC(zoombox->unk172);
    func_800D527C(voice);
}

int func_80800E24_gczoombox(ch)
u8 ch;
{
    return (ch >= 0x7F) && (ch < 0x88);
}

// Copies src to dst, expanding special characters via the font string table.
void func_80800E44_gczoombox(u8 *zoombox, u8 *dst, u8 *src)
{
    f32 alpha;
    u8 *out;
    s32 rgb[3];
    u8 *cur;
    out = dst;
    cur = src;
    alpha = *(s16 *) (zoombox + 0x1AC) / 255.0f;
    rgb[0] = zoombox[0x1B4] * alpha;
    rgb[1] = zoombox[0x1B5] * alpha;
    rgb[2] = zoombox[0x1B6] * alpha;
    *dst = 0;
    while (*cur != 0) {
        if (func_80800E24_gczoombox(*cur)) {
            *out = 0;
            _fxfontstring_entrypoint_3(dst, ((s16 *) D_80803E80_gczoombox)[0x5F - *cur],
                                       (s32) *(f32 *) (zoombox + 0x1E8));
            out = dst;
            while (*out) {
                out++;
            }
        } else {
            *out++ = *cur;
        }
        cur++;
    }
    *out = 0;
}

// Draws the two text lines and updates the blinking arrow.
// Matching: the line breaks in this function are needed for the match.
void func_80800FE0_gczoombox(zoombox) Zoombox_80800FE0_gczoombox *zoombox;
{
    s32 rgb[3];
    f32 alpha;
    s32 text_x;
    s32 line_height;
    f32 dt;
    f32 step_dir;

    alpha = zoombox->unk1AC / 255.0f;
    rgb[0] = zoombox->r * alpha;
    rgb[1] = zoombox->g * alpha;
    rgb[2] = zoombox->b * alpha;
    func_800B7A98();
    func_800B7B8C(rgb[0], rgb[1], rgb[2]);
    func_800B7ADC(zoombox->unk1BC);
    if (zoombox->b15) {
        func_800B7B38(1);
    } else if (zoombox->b19) {
        func_800B7B38(2);
    }
    if (zoombox->unk172 == 0x44) {
        text_x = zoombox->unk1AE + 4.0f * zoombox->unk1DC;
    } else if (zoombox->b24) {
        if (func_800A8184() == 4) {
            text_x = zoombox->unk1AE - zoombox->unk1F4 * (216.0f * zoombox->unk1DC);
        } else {
            text_x = (0x130 - zoombox->unk1AE) + 8.0f * zoombox->unk1DC;
        }
    } else if (zoombox->b15) {
        text_x = zoombox->unk1AE + (24.0f * zoombox->unk1DC + 8.0f);
    } else {
        text_x = zoombox->unk1AE + (24.0f * zoombox->unk1DC + 4.0f);
    }
    if (zoombox->line1) {
        if (zoombox->b17) {
            line_height = zoombox->b19 ? 15 : 12;
            func_800B7B2C(zoombox->unk1B0 - line_height / 2);
        }
        func_80800E44_gczoombox(zoombox, zoombox->buf60, zoombox->str0);
        func_800B798C(text_x, zoombox->unk1A4, zoombox->buf60);
    }
    if (zoombox->line2) {
        func_800B7B2C(-0x7FFF);
        func_80800E44_gczoombox(zoombox, zoombox->buf90, zoombox->str30);
        func_800B798C(text_x, zoombox->unk1A8, zoombox->buf90);
    }
    step_dir = zoombox->dir ? 1.0f : -1.0f; if (zoombox->b1) {
        dt = _glintrosyncDll_entrypoint_5();
    } else {
        dt = func_800D8FF8();
    }
    zoombox->unk1E8 += dt * 10.0f * step_dir;
    if (4.0f <= zoombox->unk1E8) {
        zoombox->unk1E8 = 3.999f;
        zoombox->dir = (zoombox->dir ^ 1) & 1;
    } else if (zoombox->unk1E8 < 0.0f) {
        zoombox->dir = (zoombox->dir ^ 1) & 1;
        zoombox->unk1E8 = 0;
    }
}

void func_80801424_gczoombox(u8 *zoombox, void *gfx)
{
    _fxdialog_entrypoint_0();
    _fxdialog_entrypoint_1(*(s16 *) (zoombox + 0x1AE), *(s16 *) (zoombox + 0x1B0));
    _fxdialog_entrypoint_2(*(f32 *) (zoombox + 0x1DC));
    _fxdialog_entrypoint_3(gfx,
                           (216.0f * *(f32 *) (zoombox + 0x1DC)) * *(f32 *) (zoombox + 0x1EC),
                           (zoombox[0x1E4] & 1) ? 2 : 0, *(s16 *) (zoombox + 0x1BC));
}

void func_808014A8_gczoombox(u8 *zoombox, s32 gfx, s32 x, s32 y, s32 portrait,
                             f32 alpha)
{
    // Matching: the extra temporaries here are needed for the match.
    s32 portrait_id;
    f32 scale_copy;
    f32 scale;
    if (*(s16 *) ((s8 *) zoombox + 0x172) != 0x44) {
        u8 *flags;
        scale = *(f32 *) ((s8 *) zoombox + 0x1DC);
        flags = (u8 *) ((s8 *) zoombox + 0x1E4);
        scale_copy = *(f32 *) ((s8 *) zoombox + 0x1DC);
        portrait_id = portrait;
        _fxdialog_entrypoint_4(
            gfx, portrait_id, *(s8 *) ((s8 *) zoombox + 0x1CF), (f32) x * scale,
            (f32) y * scale,
            (s32) (((f32) (*(s16 *) ((s8 *) zoombox + 0x1BC) * *(s16 *) ((s8 *) zoombox + 0x1AC)) *
                    alpha) /
                   255.0f),
            *flags & 1);
    }
}

void func_8080156C_gczoombox(zoombox, input_enabled) ZoomInputState331 *zoombox;
s32 input_enabled;
{
    s32 unk_0[6];
    s32 unk_1[3];

    if (!zoombox->local_8.local_2.local_4) {
        func_80015E80(0, unk_0);
        func_80015F28(0, unk_1);
    } else {
        func_80015ECC(0, unk_0);
        func_80015F5C(0, unk_1);
    }
    if (zoombox->local_1) {
        if (input_enabled && zoombox->local_8.local_2.local_3 && unk_0[0]) {
            if (zoombox->local_2 == -1.0f) {
                func_808009E4_gczoombox(zoombox, 1);
            } else {
                zoombox->local_4++;
                zoombox->local_4 %= 4;
                if (zoombox->local_4 == 0) {
                    func_808009E4_gczoombox(zoombox, 1);
                }
            }
        } else if (zoombox->local_8.local_2.local_1) {
            if (zoombox->local_8.local_2.local_2) {
                zoombox->local_4--;
                if (zoombox->local_4 <= zoombox->local_6 - 4) {
                    zoombox->local_4 = 0;
                    zoombox->local_8.local_2.local_2 = 0;
                    zoombox->local_8.local_2.local_1 = 0;
                }
            } else {
                zoombox->local_4++;
                if (zoombox->local_4 >= zoombox->local_6) {
                    zoombox->local_8.local_2.local_2 = 1;
                    zoombox->local_4--;
                }
            }
        } else if (input_enabled) {
            if (!zoombox->local_8.local_2.local_3 || !unk_1[0] || !(func_8001211C() & 1)) {
                if (zoombox->local_2 == -1.0f) {
                    func_808009E4_gczoombox(zoombox, 1);
                } else if (zoombox->local_3 && zoombox->local_4 == 0 &&
                           zoombox->local_4 < zoombox->local_0[zoombox->local_5]) {
                    func_808009E4_gczoombox(zoombox, 0);
                }
                zoombox->local_8.local_2.local_1 = 0;
                zoombox->local_8.local_2.local_2 = 0;
                if (zoombox->local_4 == zoombox->local_0[zoombox->local_5]) {
                    zoombox->local_5++;
                    if (zoombox->local_5 >= zoombox->local_7) {
                        zoombox->local_5 = 0;
                        zoombox->local_8.local_2.local_0 = 0;
                        if (func_800DC1AC() < 0.4f) {
                            zoombox->local_8.local_2.local_1 = 1;
                            zoombox->local_4 = zoombox->local_6 - 4;
                        }
                    }
                } else if (zoombox->local_4 < zoombox->local_0[zoombox->local_5]) {
                    zoombox->local_4++;
                } else {
                    zoombox->local_4--;
                }
            } else {
                return;
            }
        } else if (!zoombox->local_8.local_2.local_1) {
            if (zoombox->local_4 > 0) {
                zoombox->local_4--;
            } else if (func_800DC1AC() < 0.01f) {
                zoombox->local_8.local_2.local_1 = 1;
                zoombox->local_4 = zoombox->local_6 - 4;
            }
        }
        if (zoombox->local_4 < 0) {
            zoombox->local_4 = 0;
        } else if (zoombox->local_4 >= zoombox->local_6) {
            zoombox->local_4 = zoombox->local_6 - 1;
        }
    }
}

void gczoombox_entrypoint_2(GcZoombox *this, s32 gfx)
{
    s32 target;

    if (this != NULL && this->b28 && this->unk171 != 0) {
        if (this->b6) {
            target = 0xAA;
        } else {
            target = 0x80;
        }
        func_80800FE0_gczoombox(this);
        func_80801424_gczoombox(this, gfx);
        if (this->unk176 == 2 || (!func_800A819C() && !func_800DA298(0x650))) {
            func_8080156C_gczoombox(this, 0);
        } else {
            func_8080156C_gczoombox(this, this->b23);
        }
        if (!this->b13) {
            func_808014A8_gczoombox(this, gfx, this->unk1B7, this->unk1B8, this->unk140, 1.0f);
        } else {
            func_808014A8_gczoombox(this, gfx, this->unk1B7, this->unk1B8, this->unk140,
                                    1.0f - this->unk1C0);
            func_808014A8_gczoombox(this, gfx, this->unk1B9, this->unk1BA, this->unk142,
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

void func_80801B30_gczoombox(u8 *zoombox)
{
    zoombox[0x171] = 8;
    gczoombox_entrypoint_15(zoombox);
    *(f32 *) (zoombox + 0x1E0) = 0.0f;
    if (zoombox[0x1E4] & 1) {
        *(s16 *) (zoombox + 0x1AE) = *(s16 *) (zoombox + 0x1B2) + 0x8C;
    } else {
        *(s16 *) (zoombox + 0x1AE) = *(s16 *) (zoombox + 0x1B2) - 0x8C;
    }
}

void func_80801B90_gczoombox(s32 zoombox)
{
    s32 addr;
    addr = zoombox;
    *(u8 *) (addr + 369) = 9;
    gczoombox_entrypoint_16(addr);
    // Matching: the block-local temporary is needed for the match.
    {
        float zero = 0.0f;
        *(float *) (addr + 0x1E0) = zero;
    }
}

gczoombox_entrypoint_3(u8 *zoombox)
{
    return zoombox[0x170];
}

// Sets the status byte and calls the callback when it changes.
void func_80801BD0_gczoombox(u8 *zoombox, u32 status)
{
    if (status != zoombox[0x170]) {
        zoombox[0x170] = status;
        if (*(void **) (zoombox + 0x16C)) {
            (*(void (**)(s32))(zoombox + 0x16C))(*(s16 *) (zoombox + 0x172));
        }
    }
}

// Returns the index at which str is wrapped to fit the box width.
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

// Per-frame update.
void gczoombox_entrypoint_4(ZoomBoxUpdate *zoombox)
{
    s32 unk_0[6];
    s32 unk_1[3];
    f32 char_time;
    f32 dt;
    f32 open_progress;
    f32 close_progress;

    if (!zoombox) {
        return;
    }
    if (!zoombox->unk1E4_10) {
        func_80015E80(0, unk_0);
        func_80015F28(0, unk_1);
        if (zoombox->unk1E4_1) {
            dt = _glintrosyncDll_entrypoint_5();
        } else {
            dt = func_800D8FF8();
        }
    } else {
        func_80015ECC(0, unk_0);
        func_80015F5C(0, unk_1);
        dt = func_800D9004();
    }

    switch (zoombox->state) {
        case 1:
            if (zoombox->unk19D) {
                zoombox->unk1A0 += zoombox->unk19C + 1;
            } else {
                zoombox->unk1A0 = zoombox->raw_str[zoombox->current_str_index];
                zoombox->unk1E4_19 = _gldialog_entrypoint_1(zoombox->unk1A0);
            }
            zoombox->unk19C = func_80801C0C_gczoombox(zoombox, zoombox->unk1A0);
            if (zoombox->unk1A0[zoombox->unk19C]) {
                zoombox->unk19D = 1;
            } else {
                zoombox->unk19D = 0;
            }
            func_8080014C_gczoombox(zoombox->unk1A0, zoombox->unkC0, 0, zoombox->unk19C);
            zoombox->unkC0[zoombox->unk19C] = 0;
            if (!zoombox->unk19D) {
                zoombox->current_str_index++;
            }
            if (zoombox->unk19D || zoombox->current_str_index < zoombox->str_cnt) {
                zoombox->unk1E4_25 = 0;
                zoombox->unk1E4_31 = 0;
            } else {
                zoombox->unk1E4_25 = 1;
                zoombox->unk1E4_31 = 1;
            }
            if (zoombox->unk1E4_27) {
                zoombox->unk1E4_26 = 1;
                zoombox->unk1E4_30 = 1;
                zoombox->unk1E4_29 = 0;
            } else {
                zoombox->unk1E4_26 = 0;
            }
            func_808006E0_gczoombox(zoombox, zoombox->unk19C);
            zoombox->state = 2;
            zoombox->unk1CE = zoombox->unk19E = 0;
            zoombox->unk1D4 = 0.0f;
            if (zoombox->unk1E4_19) {
                zoombox->unk19E += 2;
            }
            zoombox->unk1E4_23 = 1;
            func_80800294_gczoombox(zoombox);
            break;
        case 2:
            char_time = zoombox->unk1D8;
            if (zoombox->unk1E4_19) {
                char_time *= 1.5f;
            }
            if (zoombox->unk1E4_4) {
                char_time *= 0.01998901367f;
                zoombox->unk1E4_4 = 0;
            } else if (unk_0[0] && zoombox->unk1E4_12) {
                char_time *= 0.4499969482f;
            } else if (unk_1[0] && zoombox->unk1E4_12) {
                // Matching: the (f32) cast is needed for the match.
                char_time *= (f32) 2.0;
            }
            zoombox->unk1D4 += dt;
            while (char_time < zoombox->unk1D4 && zoombox->unk19C >= zoombox->unk19E) {
                zoombox->unk19E++;
                if (func_808005F0_gczoombox(zoombox->unkC0[zoombox->unk19E], zoombox->unk1E4_19)) {
                    zoombox->unk1D4 -=
                        (unk_0[0] && zoombox->unk1E4_12) ? 0.04999542236f : 0.09999084473f;
                }
                zoombox->unk1D4 -= char_time;
            }
            if (zoombox->unk1E4_26) {
                if (zoombox->unk1E4_3) {
                    zoombox->unk30[0] = 0xFD;
                    zoombox->unk30[1] = 0x68;
                    func_8080014C_gczoombox(zoombox->unkC0, zoombox->unk30 + 2, 0, zoombox->unk19E);
                    zoombox->unk30[zoombox->unk19E + 2] = 0;
                } else {
                    func_8080014C_gczoombox(zoombox->unkC0, zoombox->unk30, 0, zoombox->unk19E);
                }
                zoombox->unk1E4_29 = 1;
            } else {
                if (zoombox->unk1E4_3) {
                    zoombox->unk0[0] = 0xFD;
                    zoombox->unk0[1] = 0x68;
                    func_8080014C_gczoombox(zoombox->unkC0, zoombox->unk0 + 2, 0, zoombox->unk19E);
                    zoombox->unk0[zoombox->unk19E + 2] = 0;
                } else {
                    func_8080014C_gczoombox(zoombox->unkC0, zoombox->unk0, 0, zoombox->unk19E);
                }
                zoombox->unk1E4_27 = 1;
                zoombox->unk1E4_30 = 1;
            }
            if (zoombox->unk19C < zoombox->unk19E) {
                func_808002E4_gczoombox(zoombox);
            }
            break;
        case 3:
            if ((unk_0[0] && zoombox->unk1E4_12) || zoombox->unk1C4 < 0.0f) {
                zoombox->state = 4;
                zoombox->unk1C8 = 60.0f * dt * zoombox->unk1CD;
            } else {
                zoombox->unk1C4 -= dt;
            }
            break;
        case 4:
            if (unk_0[0] && zoombox->unk1E4_12) {
                zoombox->unk1C8 = 60.0f * dt * (zoombox->unk1CD + 2);
                zoombox->unk1E4_23 = 0;
            } else if (zoombox->unk1E4_12 && unk_1[0]) {
                zoombox->unk1C8 = 60.0f * dt * (zoombox->unk1CD - 1);
            }
            zoombox->unk1E4_17 = 0;
            if (zoombox->unk1E4_26 || zoombox->unk1E4_31) {
                if (zoombox->unk1E4_25) {
                    if (zoombox->unk1E4_6 && zoombox->state != 10 && zoombox->unk1E4_26) {
                        func_80101238(0x6D, 0);
                    }
                    gczoombox_entrypoint_14(zoombox);
                    zoombox->state = 10;
                }
                if (!zoombox->unk1E4_23 && !zoombox->unk1E4_25) {
                    zoombox->unk1E4_17 = 1;
                    zoombox->unk1A4 -= zoombox->unk1C8;
                    zoombox->unk1A8 -= zoombox->unk1C8;
                }
                if (!zoombox->unk1E4_25) {
                    if (zoombox->unk1B0 - (zoombox->unk1E4_19 ? 15 : 12) * 3 / 2 >=
                        zoombox->unk1A4) {
                        func_8080014C_gczoombox(zoombox->unk30, zoombox->unk0, 0, 0x30);
                        func_808001D4_gczoombox(zoombox->unk30, 0x30);
                        func_80800228_gczoombox(zoombox);
                        zoombox->unk1E4_30 = 1;
                        zoombox->unk1E4_29 = 0;
                        zoombox->state = 1;
                    }
                }
            } else if (!zoombox->unk1E4_23) {
                zoombox->state = 1;
            }
            break;
        case 10:
            func_80801BD0_gczoombox(zoombox, 3);
            if (zoombox->unk177 & 8) {
                zoombox->unk1E4_27 = 0;
                func_808004D0_gczoombox(zoombox);
            } else if (zoombox->unk177 & 4) {
                zoombox->unk170 = 0;
                zoombox->unk1E4_25 = 0;
                zoombox->state = 4;
            }
            break;
        case 5:
            open_progress = -1.0f;
            if (zoombox->unk1E4_16) {
                open_progress = func_80800364_gczoombox(zoombox);
                if (zoombox->unk1E4_14) {
                    zoombox->unk1C0 = 1.0f - zoombox->unk1EC / zoombox->unk1F4;
                }
            }
            if (zoombox->unk1E4_11 && zoombox->unk1E4_16 &&
                func_808003D8_gczoombox(zoombox, open_progress, zoombox->unk1F4 * 0.1f)) {
                if (func_800C710C(0)) {
                    _gcaudiolist_entrypoint_1(2, zoombox->unk16A);
                }
            }
            if (zoombox->unk1E4_16 && func_808003D8_gczoombox(zoombox, open_progress, zoombox->unk1F4)) {
                zoombox->unk1EC = zoombox->unk1F4;
                if (zoombox->unk1E4_14) {
                    func_808000C4_gczoombox(zoombox);
                }
                zoombox->unk1E4_14 = zoombox->unk1E4_13 = 0;
                zoombox->unk1E4_16 = 0;
            }
            if (!zoombox->unk1E4_16) {
                func_80801BD0_gczoombox(zoombox, 2);
                if (zoombox->unk177 & 4) {
                    zoombox->state = 1;
                } else if (zoombox->unk177 & 8) {
                    func_808004D0_gczoombox(zoombox);
                }
            }
            break;
        case 6:
            close_progress = -1.0f;
            if (zoombox->unk1E4_16) {
                close_progress = func_80800364_gczoombox(zoombox);
                if (zoombox->unk1E4_14) {
                    zoombox->unk1C0 = zoombox->unk1EC / zoombox->unk1F4;
                }
            }
            if (zoombox->unk1E4_11 && zoombox->unk1E4_16 &&
                func_808003D8_gczoombox(zoombox, close_progress, zoombox->unk1F4 * 0.9f)) {
                if (func_800C710C(1)) {
                    _gcaudiolist_entrypoint_1(3, zoombox->unk16A);
                }
            }
            if (zoombox->unk1E4_16 && zoombox->unk1EC <= 0) {
                zoombox->unk1EC = 0;
                if (zoombox->unk1E4_14) {
                    func_808000C4_gczoombox(zoombox);
                }
                zoombox->unk1E4_14 = zoombox->unk1E4_13 = 0;
                zoombox->unk1E4_16 = 0;
            }
            if (!zoombox->unk1E4_16) {
                func_80801BD0_gczoombox(zoombox, 4);
                if (zoombox->unk177 & 0x10) {
                    func_80801B90_gczoombox(zoombox);
                } else if (zoombox->unk177 & 2) {
                    func_80800470_gczoombox(zoombox);
                }
            }
            break;
        case 7:
            func_80800964_gczoombox(zoombox);
            func_80801BD0_gczoombox(zoombox, 6);
            break;
        case 8:
            if (zoombox->unk1E0 == 0.0f) {
                zoombox->unk1E4_28 = 1;
            }
            if (zoombox->unk1E4_11 && zoombox->unk1E0 == 0) {
                if (func_800C710C(2)) {
                    _gcaudiolist_entrypoint_1(4, zoombox->unk16A);
                }
            }
            if (zoombox->unk1E4_24) {
                zoombox->unk1AE =
                    func_800F3780(zoombox->unk1E0, D_80803E44_gczoombox, 7) + zoombox->unk1B2;
            } else {
                zoombox->unk1AE =
                    zoombox->unk1B2 - func_800F3780(zoombox->unk1E0, D_80803E44_gczoombox, 7);
            }
            if (zoombox->unk1E0 >= 1.0f) {
                zoombox->unk1AE = zoombox->unk1B2;
                func_80801BD0_gczoombox(zoombox, 1);
                if (zoombox->unk177 & 2) {
                    func_80800470_gczoombox(zoombox);
                } else if (zoombox->unk177 & 0x10) {
                    func_80801B90_gczoombox(zoombox);
                }
            } else {
                zoombox->unk1E0 += 5.0f * dt;
            }
            break;
        case 9:
            if (zoombox->unk1E4_11 && zoombox->unk1E0 == 0) {
                if (func_800C710C(3)) {
                    _gcaudiolist_entrypoint_1(5, zoombox->unk16A);
                }
            }
            if (zoombox->unk1E4_24) {
                zoombox->unk1AE = func_800F3780(1.0f - zoombox->unk1E0, D_80803E44_gczoombox, 7) +
                                  zoombox->unk1B2;
            } else {
                zoombox->unk1AE = zoombox->unk1B2 -
                                  func_800F3780(1.0f - zoombox->unk1E0, D_80803E44_gczoombox, 7);
            }
            if (zoombox->unk1E0 >= 1.0f) {
                zoombox->unk1E4_28 = 0;
                func_80801BD0_gczoombox(zoombox, 5);
                if (zoombox->unk177 & 0x20) {
                    zoombox->state = 7;
                } else if (zoombox->unk177 & 1) {
                    func_80801B30_gczoombox(zoombox);
                }
            } else {
                zoombox->unk1E0 += 5.0f * dt;
            }
            break;
        case 11:
            if (zoombox->unk177 & 1) {
                func_80801B30_gczoombox(zoombox);
            }
    }
}

// Load the portrait asset; 0x44 means no portrait.
void func_80802B94_gczoombox(ZoomBoxAssetState *box, s32 portrait_id)
{
    if (portrait_id != 0x44) {
        box->asset = _gczoomboxdata_entrypoint_1(portrait_id);
        box->count = func_800AF5A0(func_800D674C(box->asset));
        box->counter = 0;
    } else {
        box->asset = 0;
        box->count = 0;
    }
}

void func_80802BF4_gczoombox(u8 *box)
{
    s32 i;

    i = 0;
    if ((s32) *(u8 *) ((s8 *) box + 0x178) > 0) {
        do {
            if (*(u8 *) ((s8 *) box + 0x1E6) & 1) {
                func_800C431C(*(u8 *) ((s8 *) (box + i) + 0x144), 0);
            }
            if (*(s32 *) ((s8 *) box + 0x1E4) & 1) {
                func_800C3528(*(u8 *) ((s8 *) (box + i) + 0x144), 1);
            }
            i += 1;
        } while (i < (s32) *(u8 *) ((s8 *) box + 0x178));
    }
}

// Load the voice sfx points for the portrait.
void func_80802C80_gczoombox(ZoomBox *box, s32 portrait_id)
{
    s32 point_count;
    s16 first_sfx;
    s32 i;
    s16 sfx;

    box->unk178 = 0;
    for (i = 0; i < 5; i++) {
        box->unk144[i] = 0;
        box->unk160[i] = 0;
        box->unk14C[i] = 0.0f;
    }
    if (box->unk176 != 2) {
        _gczoomboxdata_entrypoint_4(portrait_id, 0, &first_sfx, &box->unk160[0], &box->unk14C[0]);
        if (box->unk14C[0] == -1.0f) {
            box->unk144[0] = first_sfx;
        } else {
            point_count = _gczoomboxdata_entrypoint_3(portrait_id);
            for (i = 0; i < point_count; i++) {
                _gczoomboxdata_entrypoint_4(portrait_id, i, &sfx, &box->unk160[i],
                                            &box->unk14C[i]);
                if (box->unk160[i] != 0) {
                    box->unk144[i] = func_808008F4_gczoombox(box, sfx, 3);
                    box->unk178++;
                }
            }
            box->unk1D3 = func_800DC214(0, box->unk178);
        }
    }
    func_80802BF4_gczoombox(box);
}

// Constructor: allocates and initializes a zoombox.
u8 *gczoombox_entrypoint_5(s32 unk_0, s32 portrait_id, s32 unk_1, s32 unk_2, s32 unk_3)
{
    u8 *box;
    s32 i;
    s32 unk_4;

    box = (u8 *) heap_alloc(0x1F8);
    *(s32 *) (box + 0x16C) = unk_3;
    *(u8 *) (box + 0x171) = 11;
    *(s16 *) (box + 0x172) = portrait_id;
    *(u8 *) (box + 0x170) = *(u8 *) (box + 0x174) = *(u8 *) (box + 0x175) = 0;
    *(u8 *) (box + 0x176) = unk_1;
    *(u8 *) (box + 0x177) = 0x20;
    *(s32 *) (box + 0x130) = 0;
    *(s16 *) (box + 0x13A) = 0;
    *(s32 *) (box + 0x13C) = -1;
    for (i = 0; i < 8; i++) {
        ((ZbA *) box)->raw[i] = 0;
    }
    *(u8 *) (box + 0x19E) = 0;
    *(u8 *) (box + 0x19D) = 0;
    *(u8 *) (box + 0x19C) = 0;
    ZB(box)->b19 = 0;
    *(s32 *) (box + 0x1A0) = 0;
    *(s16 *) (box + 0x1AC) = 0xFF;
    *(s16 *) (box + 0x1BC) = 0xFF;
    *(u8 *) (box + 0x1B4) = 0xFF;
    *(u8 *) (box + 0x1B5) = 0xFF;
    *(u8 *) (box + 0x1B6) = 0xFF;
    ZB(box)->b24 = unk_2;
    ZB(box)->b9 = 0;
    *(u8 *) (box + 0x179) = 0;
    ZB(box)->b8 = 1;
    ZB(box)->b7 = 1;
    *(f32 *) (box + 0x1E8) = 0.0f;
    if (ZB(box)->b24) {
        *(s16 *) (box + 0x1B2) = 0x104;
        *(s16 *) (box + 0x1AE) = 0x190;
    } else {
        *(s16 *) (box + 0x1B2) = 0x2C;
        *(s16 *) (box + 0x1AE) = -0x60;
    }
    *(s16 *) (box + 0x1B0) = unk_0;
    *(f32 *) (box + 0x1A4) = 0.0f;
    *(f32 *) (box + 0x1A8) = 0.0f;
    *(f32 *) (box + 0x1C4) = *(s8 *) (box + 0x1CF) = *(u8 *) (box + 0x1D0) = *(u8 *) (box + 0x1D2) = 0;
    *(f32 *) (box + 0x1E0) = 0.0f;
    *(f32 *) (box + 0x1D4) = 0.0f;
    *(u8 *) (box + 0x1CE) = (s32) *(f32 *) (box + 0x1C4);
    *(f32 *) (box + 0x1DC) = 1.0f;
    unk_4 = func_800E6A00();
    ZB(box)->b1 = unk_4;
    ZB(box)->b31 = ZB(box)->b30 = ZB(box)->b29 = ZB(box)->b28 = ZB(box)->b27 = ZB(box)->b26 =
        ZB(box)->b25 = ZB(box)->b23 = ZB(box)->b22 = ZB(box)->b21 = ZB(box)->b20 = ZB(box)->b17 =
            ZB(box)->b16 = ZB(box)->b15 = ZB(box)->b14 = ZB(box)->b13 = 0;
    ZB(box)->b0 = 0;
    ZB(box)->b11 = ZB(box)->b18 = 1;
    ZB(box)->b6 = 0;
    ZB(box)->b5 = 0;
    ZB(box)->b4 = 0;
    ZB(box)->b3 = 0;
    func_80802B94_gczoombox(box, portrait_id);
    ZB(box)->b2 = 1;
    *(f32 *) (box + 0x1EC) = 0.0f;
    *(f32 *) (box + 0x1F4) = 1.0f;
    gczoombox_entrypoint_20(box, 15.0f, 5, 2, 0.4f, 0, 0);
    _gczoomboxdata_entrypoint_2(portrait_id, (s8 *) (box + 0x1B7), (s8 *) (box + 0x1B8));
    *(s8 *) (box + 0x1BA) = 0;
    *(s8 *) (box + 0x1B9) = *(s8 *) (box + 0x1BA);
    *(f32 *) (box + 0x1C0) = 1.0f;
    *(s16 *) (box + 0x142) = 0;
    func_80802C80_gczoombox(box, portrait_id);
    gczoombox_entrypoint_30(box, 0x4650);
    func_808001D4_gczoombox(box, 0x30);
    func_808001D4_gczoombox(box + 0x30, 0x30);
    func_808001D4_gczoombox(box + 0xC0, 0x30);
    func_808001D4_gczoombox(box + 0xF0, 0x40);
    return box;
}

gczoombox_entrypoint_6(u8 *box)
{
    return box[0x178];
}

// Set the strings to show (up to 8); fails if strings are already set.
int gczoombox_entrypoint_7(ZoomStrings1459 *box, s32 num_strings, char **src)
{
    s32 i;

    if ((box->flags & 4) || src == NULL || num_strings == 0) {
        return 0;
    }
    box->index = 0;
    box->count = num_strings;
    for (i = 0; i < num_strings; i++) {
        box->strings[i] = src[i];
    }
    for (i = num_strings; i < 8; i++) {
        box->strings[i] = NULL;
    }
    box->flags |= 4;
    return 1;
}

// Set a single string to show.
int gczoombox_entrypoint_8(u8 *box, u32 str)
{
    u32 single;
    if ((box[0x177] & 4) || !str) {
        return 0;
    }
    // Matching: the extra block and `| 0` are needed for the match.
    {
        single = str | 0;
        return gczoombox_entrypoint_7(box, 1, &single);
    }
}

void gczoombox_entrypoint_9(void *box)
{
    ((char *) box)[0x177] |= 1;
}

void gczoombox_entrypoint_10(void *box)
{
    ((u8 *) box)[0x177] |= 0x10;
}

gczoombox_entrypoint_11(u8 *box)
{
    box[0x177] |= 0x02;
}

gczoombox_entrypoint_12(u8 *box)
{
    box[0x177] |= 0x8;
}

gczoombox_entrypoint_13(u8 *box)
{
    box[0x177] |= 0x20;
}

// Clear the string list.
void gczoombox_entrypoint_14(u8 *box)
{
    s32 i;
    u8 *chunk;

    i = 0;
    chunk = box;
    do {
        i += 4;
        *(s32 *) ((s8 *) chunk + 0x180) = 0;
        *(s32 *) ((s8 *) chunk + 0x184) = 0;
        *(s32 *) ((s8 *) chunk + 0x188) = 0;
        chunk += 0x10;
        *(s32 *) ((s8 *) chunk + 0x16C) = 0;
    } while (i != 8);
    *(s8 *) ((s8 *) box + 0x174) = 0;
    *(s8 *) ((s8 *) box + 0x175) = 0;
    *(u8 *) ((s8 *) box + 0x177) = (u8) (*(u8 *) ((s8 *) box + 0x177) & 0xFB);
}

int gczoombox_entrypoint_15(box)
u8 *box;
{
    // Matching: the temporaries are needed for the match.
    int bit;
    char mask;
    bit = 1;
    mask = ~bit;
    box[0x177] &= mask;
}

void gczoombox_entrypoint_16(box) void *box;
{
    ((char *) box)[0x177] &= (unsigned char) ~0x10;
}

void gczoombox_entrypoint_17(box) void *box;
{
    // Matching: the repeated masks and extra temporaries are needed for the match.
    int flags;
    void *box_a;
    void *box_b;
    u8 result;
    result =
        ((flags = ((((((((((u8 *) box)[0x177] & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) &
                          0xFFFFFFFFu) &
                         0xFFFFFFFFu) &
                        0xFFFFFFFFu) &
                       0xFFFFFFFFu) &
                      0xFFFFFFFFu) &
                     0xFFFFFFFFu) &
         0xFFFFFFFFu) &
        0xFFFFFFFFu;
    box_a = box;
    box_b = box_a;
    result &= 0xFD;
    ((u8 *) box_b)[0x177] = result;
}

int gczoombox_entrypoint_18(box)
u8 *box;
{
    box[0x177] &= ~0x08 & 0xFF;
}

void gczoombox_entrypoint_19(void *box)
{
    // Matching: the temporary is needed for the match.
    char mask;
    mask = ~0x20;
    ((char *) box)[0x177] &= mask;
}

void gczoombox_entrypoint_20(u8 *box, f32 unk_0, s32 unk_1, s32 unk_2, f32 unk_3,
                             s32 unk_4, s32 unk_5)
{
    if (box) {
        box[0x1CC] = unk_1;
        box[0x1CD] = unk_2;
        *(f32 *) (box + 0x1D8) = 1.0f / unk_0;
        func_80800358_gczoombox(box, unk_3);
        if (unk_4) {
            ((ZoomFlags30 *) (box + 0x1E6))->bit_4 = 1;
        } else {
            ((ZoomFlags30 *) (box + 0x1E6))->bit_4 = 0;
        }
        if (unk_5) {
            ((ZoomFlags30 *) (box + 0x1E6))->bit_2 = 1;
        } else {
            ((ZoomFlags30 *) (box + 0x1E6))->bit_2 = 0;
        }
    }
}

int gczoombox_entrypoint_21(u8 *box, s32 enable)
{
    // Matching: the copy and the empty if are needed for the match.
    int enable_copy;
    enable_copy = enable;
    if (enable_copy) {
        if ((!(enable_copy & 0xFF) && !enable_copy) && !enable_copy) {
        }
        box[485] |= (long) 0x4;
    } else {
        box[485] &= 0xFFFB;
    }
}

s32 gczoombox_entrypoint_22(s32 box)
{
    return (u32) (*(s32 *) ((char *) box + 0x1E4) << 13) >> 31;
}

int gczoombox_entrypoint_23(u8 *box, unsigned int enable)
{
    if (box != 0) {
        if (enable != 0) {
            box[0x1E6] = (box[0x1E6] & 0xFFFFu) | 8;
        } else {
            box[0x1E6] &= ~8;
        }
    }
}

void gczoombox_entrypoint_24(u8 *box, s32 enable)
{
    if (enable != 0) {
        box[0x1e6] = (box[0x1e6] & 0xFFu) | 1;
    } else {
        box[0x1e6] = box[0x1e6] & 0xFFFE;
    }
    func_80802BF4_gczoombox(box);
}

void gczoombox_entrypoint_25(u8 *box, s32 enable)
{
    if (enable != 0) {
        box[0x1E7] = (box[0x1E7] & 0xFFu) | 1;
    } else {
        box[0x1E7] = box[0x1E7] & 0xFFFE;
    }
    func_80802BF4_gczoombox(box);
}

void gczoombox_entrypoint_26(ZoomBoxPlacement *box, int unk_0, f32 unk_1, f32 unk_2,
                             s32 unk_3)
{
    if (box) {
        if (box->local_4) {
            box->local_1 = 0x130 - unk_0;
            box->local_0 = 0x1BC - unk_0;
        } else {
            box->local_1 = unk_0;
            box->local_0 = unk_0 - 0x8C;
        }
        box->local_2 = unk_1;
        box->local_3 = unk_2;
        if (unk_3) {
            box->local_5 = 1;
        } else {
            box->local_5 = 0;
        }
    }
}

void gczoombox_entrypoint_27(void *box, s16 rgb[3])
{
    if (box != 0) {
        *(s8 *) ((char *) box + 0x1B4) = rgb[0];
        *(s8 *) ((char *) box + 0x1B5) = rgb[1];
        *(s8 *) ((char *) box + 0x1B6) = rgb[2];
    }
}

void gczoombox_entrypoint_28(u8 *box, s16 alpha)
{
    if (box != NULL) {
        *(s16 *) (box + 0x1BC) = alpha;
    }
}

s16 gczoombox_entrypoint_29(u8 *box)
{
    if (box == NULL) {
        return 0xFF;
    }
    return *(s16 *) (box + 0x1BC);
}

void gczoombox_entrypoint_30(u8 *box, int unk_0)
{
    // Matching: the temporary is needed for the match.
    s8 *base;
    if (box != 0) {
        base = (s8 *) box;
        *(s16 *) (base + 0x16A) = unk_0;
    }
}

void gczoombox_entrypoint_31(void *box)
{
    ((char *) box)[0x177] = 0;
}

s32 gczoombox_entrypoint_32(u8 *box)
{
    if (!box || box[0x171] == 0 || box[0x171] == 11 || box[0x171] == 9) {
        return 0;
    }
    func_808001D4_gczoombox(box + 0xC0, 0x30);
    func_808001D4_gczoombox(box, 0x30);
    func_808001D4_gczoombox(box + 0x30, 0x30);
    ((ZoomFlags30 *) (box + 0x1E4))->bit_6 = ((ZoomFlags30 *) (box + 0x1E4))->bit_5 =
        ((ZoomFlags30 *) (box + 0x1E4))->bit_3 = ((ZoomFlags30 *) (box + 0x1E4))->bit_2 =
            ((ZoomFlags30 *) (box + 0x1E4))->bit_7 =
                ((ZoomFlags30 *) (box + 0x1E5))->bit_7 = box[0x19D] = 0;
    *(s32 *) (box + 0x1A0) = 0;
    if (box[0x171] == 10 || box[0x171] == 1 || box[0x171] == 2 || box[0x171] == 3 ||
        box[0x171] == 4) {
        box[0x171] = 10;
        box[0x170] = 3;
    }
    gczoombox_entrypoint_14(box);
    return 1;
}

s32 gczoombox_entrypoint_33(u8 *box)
{
    s32 state;
    // Matching: the constant local is needed for the match.
    const s32 state_6 = 6;

    if (!box || !(state = box[0x171]) || state == 7 || state == 9) {
        return 0;
    }
    if (state_6 == state && box[0x170] == 4) {
        return 0;
    }
    if (state == 8) {
        ((ZoomFlags30 *) (box + 0x1E5))->bit_0 = 0;
        box[0x171] = 6;
    } else if (state_6 != state) {
        func_808004D0_gczoombox(box);
    }
    gczoombox_entrypoint_14(box);
    gczoombox_entrypoint_17(box);
    return 1;
}

int gczoombox_entrypoint_34(u8 *box)
{
    if (!box || box[0x171] == 0 || box[0x171] == 7 || box[0x171] == 9) {
        return 0;
    }
    {
        gczoombox_entrypoint_10(box);
        gczoombox_entrypoint_13(box);
        func_808004D0_gczoombox(box);
        return 1;
    }
}

void gczoombox_entrypoint_35(box, unk_0, unk_1, unk_2) s32 box;
s32 unk_0;
u16 unk_1;
s32 unk_2;
{
    // Matching: the temporaries and no-op arithmetic are needed for the match.
    int offset;
    s32 *dst;
    unk_1 += 0;
    offset = 0x13A;
    *(s32 *) (box + 0x130) = unk_0;
    *(u16 *) (box + offset) = unk_1;
    *(s32 *) (box + 0x13C) = unk_2;
    dst = (s32 *) (box + 0x134);
    func_800EC370(unk_0 | (unk_0 * 0), dst);
}

void gczoombox_entrypoint_36(u8 *box, s16 portrait_id)
{
    u8 flags;
    if (portrait_id != *(s16 *) ((s8 *) box + 0x172)) {
        *(s16 *) ((s8 *) box + 0x140) = 0;
        func_808000C4_gczoombox(box);
        func_80802B94_gczoombox(box, portrait_id);
        // Matching: the always-true if is needed for the match.
        if (1) {
            _gczoomboxdata_entrypoint_2(portrait_id, box + 0x1B7, box + 0x1B8);
            func_80800000_gczoombox(box);
            func_80802C80_gczoombox(box, portrait_id);
            flags = (*(u8 *) ((s8 *) box + 0x1E6) & 0xFF) & 0xFFBF;
            *(u8 *) ((s8 *) box + 0x1E6) = flags;
        }
        *(s16 *) ((s8 *) box + 0x172) = portrait_id;
        *(u8 *) ((s8 *) box + 0x1E6) = (u8) (flags & 0xDF);
        *(f32 *) ((s8 *) box + 0x1C0) = 1.0f;
    }
}

s32 gczoombox_entrypoint_37(ZoomState31 *box, s16 portrait_id)
{
    if (!box || portrait_id == box->local_3 ||
        (box->local_2 != 6 && box->local_2 != 0xA && box->local_2 != 0xB &&
         box->local_2 != 9)) {
        return 0;
    }
    if (box->local_2 == 0xB || box->local_2 == 9) {
        gczoombox_entrypoint_36(box, portrait_id);
    } else {
        if (box->local_1) {
            box->local_1 = 0;
        }
        if (box->local_0) {
            box->local_1 = box->local_0;
        }
        box->local_6 = box->local_4;
        box->local_7 = box->local_5;
        func_80802B94_gczoombox((void *) box, portrait_id);
        _gczoomboxdata_entrypoint_2(portrait_id, &box->local_4, &box->local_5);
        func_80800000_gczoombox(box);
        func_80802C80_gczoombox(box, portrait_id);
        box->local_3 = portrait_id;
        box->local_8 = 1.0f;
        box->local_9 = 1;
        box->local_10 = 1;
    }
    return 1;
}

s32 gczoombox_entrypoint_38(void *box, s32 unk_0)
{
    if (box != 0) {
        *(s16 *) ((char *) box + 0x1B0) = unk_0;
        func_80800294_gczoombox(box);
    }
}

int gczoombox_entrypoint_39(u8 *box)
{
    return box != NULL && box[0x171] == 0;
}

// Set the 0xFD control code (0x68 on, 0x6C off) at the start of the text lines.
void gczoombox_entrypoint_40(u8 *box, s32 enable)
{
    u8 line1_copy[0x30];
    u8 line2_copy[0x30];
    if (box) {
        if (((Sol61ZoomFlags *) (box + 0x1E4))->local_1) {
            if (enable && !((Sol61ZoomFlags *) (box + 0x1E4))->local_4) {
                if (box[0] == 0xFD)
                    box[1] = 0x68;
                else {
                    func_8080014C_gczoombox(box, line1_copy, 0, 0x30);
                    box[0] = 0xFD;
                    box[1] = 0x68;
                    func_8080014C_gczoombox(line1_copy, box + 2, 0, 0x2E);
                }
                ((Sol61ZoomFlags *) (box + 0x1E4))->local_4 = 1;
            } else if (!enable && ((Sol61ZoomFlags *) (box + 0x1E4))->local_4) {
                if (box[0] == 0xFD)
                    box[1] = 0x6C;
                ((Sol61ZoomFlags *) (box + 0x1E4))->local_4 = 0;
            }
        }
        if (((Sol61ZoomFlags *) (box + 0x1E4))->local_2) {
            if (enable) {
                if (box[0x30] == 0xFD)
                    box[0x31] = 0x68;
                else {
                    func_8080014C_gczoombox(box + 0x30, line2_copy, 0, 0x30);
                    box[0x30] = 0xFD;
                    box[0x31] = 0x68;
                    func_8080014C_gczoombox(line2_copy, box + 0x32, 0, 0x2E);
                }
                ((Sol61ZoomFlags *) (box + 0x1E4))->local_4 = 1;
            } else {
                if (box[0x30] == 0xFD)
                    box[0x31] = 0x6C;
                ((Sol61ZoomFlags *) (box + 0x1E4))->local_4 = 0;
            }
        }
    }
}

void gczoombox_entrypoint_41(void *box, f32 unk_0)
{
    *(float *) ((char *) box + 0x1D8) = 1.0f / unk_0;
}

void gczoombox_entrypoint_42(s32 box, f32 unk_0)
{
    func_80800358_gczoombox(box, unk_0);
}

void gczoombox_entrypoint_43(u8 *box, s32 enable)
{
    // Matching: the temporary and the empty if are needed for the match.
    int inverted;
    inverted = !enable;
    if (enable != 0) {
        if ((inverted && !enable) && !enable) {
        }
        box[0x1E7] |= 0x40;
    } else {
        box[0x1E7] &= ~0x40;
    }
}

int gczoombox_entrypoint_44(u8 *box, s32 enable)
{
    // Matching: the copy and the empty if are needed for the match.
    int enable_copy;
    s16 mask;
    enable_copy = enable;
    if (enable_copy) {
        if ((!(enable_copy & 0xFF) && !enable_copy) && !enable_copy) {
        }
        box[487] |= (long) 0x20;
    } else {
        mask = 0xFFDF;
        box[487] &= mask;
    }
}

int gczoombox_entrypoint_45(u8 *box, s32 enable)
{
    // Matching: the copies and the empty if are needed for the match.
    int low_byte;
    int enable_copy;
    enable_copy = enable;
    if (enable_copy) {
        low_byte = enable_copy & 0xFF;
        if ((!low_byte && !enable_copy) && !enable_copy) {
        }
        box[487] |= (long) 0x10;
    } else {
        box[487] &= 65519;
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; values taken from the ROM.
u32 D_80803E30_gczoombox[5] = {0xB580B59, 0xB5A0B5D, 0xB5C0B5B, 0xB5F0B5E, 0xB600000};
f32 D_80803E44_gczoombox[15] = {0.0f,    1.4e+02f, 0.1666f, 7e+01f, 0.3333f, 35.0f, 0.5f, 18.0f,
                                0.6666f, 9.0f,     0.8333f, 4.0f,   1.0f,    0.0f,  0.0f};
