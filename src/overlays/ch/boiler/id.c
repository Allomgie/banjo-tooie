#include "common.h"

extern int D_80800D5C_chboilerid[];
typedef struct {
    s16 values[15];
} BoilerSettings29;
extern BoilerSettings29 D_80800D00_chboilerid[];
extern void *func_80100094(Actor *, u32);
extern void _mlwave_entrypoint_0(void *, f32, f32);
extern s32 D_80800DA4_chboilerid[];
extern s32 D_80800DB0_chboilerid[];
extern s32 D_80800DE8_chboilerid[];
extern void _chboilerid_entrypoint_1(void);
extern void _chboilerid_entrypoint_2(void);
extern void _chboilerid_entrypoint_3(void);
extern void _chboilerid_entrypoint_4(void);
extern f32 func_800D8FF8(void);
extern s32 func_800D9078();
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern Actor *func_80106790(Unk80132ED0 *);
typedef struct {
    u8 pad_0[0x20];
    f32 unk_20;
    f32 unk_24;
    u8 pad_28[0x32];
    s16 unk_5A;
} BoilerMotion1312;
extern f32 func_800EEF94(f32 *);
extern f32 func_800136D0(f32);
extern f32 func_800138BC(f32);
typedef struct {
    u8 pad_0[0x3C];
    u8 wave[0x20];
    s16 amp;
} BoilerWave1472;
extern f32 _mlwave_entrypoint_4(void *, f32, f32, f32);
extern void _mlwave_entrypoint_3(void *, f32, f32);
extern u8 D_80800DFC_chboilerid[];
extern void func_800F3320(u32 *, void *, void *, f32);
extern void func_800F2FD0(void *, u32 *, f32);
void func_80800418_chboilerid();
s32 func_80800440_chboilerid();
s32 func_80800468_chboilerid();
int func_8080079C_chboilerid();
void func_8080084C_chboilerid();
void func_80800918_chboilerid();
void chboilerid_entrypoint_5();
s32 func_80800C48_chboilerid();
int func_80800CB0_chboilerid();
int func_80800700_chboilerid();

int chboilerid_entrypoint_0()
{
    return &D_80800D5C_chboilerid;
}

// Init: sets up the three waves and effect amounts from the per-map settings.
void func_8080000C_chboilerid(Actor *actor)
{
    u8 *data;
    s32 cfg;
    data = func_80100094(actor, 0);
    *(s16 *) (data + 0x5E) = func_800EA05C();
    _subaddielink_entrypoint_0(data + 0x60);
    func_80800C48_chboilerid(actor);
    *(f32 *) (data + 0x1C) = 0.0f;
    cfg = func_80800CB0_chboilerid(data);
    _mlwave_entrypoint_0(data, 500.0f, D_80800D00_chboilerid[cfg].values[0]);
    _mlwave_entrypoint_0(data + 0x3C, 200.0f, D_80800D00_chboilerid[cfg].values[4]);
    _mlwave_entrypoint_0(data + 0x20, 300.0f, D_80800D00_chboilerid[cfg].values[8]);
    *(s16 *) (data + 0x58) = D_80800D00_chboilerid[cfg].values[13];
    *(s16 *) (data + 0x5A) = D_80800D00_chboilerid[cfg].values[12];
    *(s16 *) (data + 0x5C) = D_80800D00_chboilerid[cfg].values[14];
    func_800DA524(0x66F);
}

void func_80800998_chboilerid();

// Update: states are 1 calm, 2 and 3 raging, 4 cooling; then the four mesh layers are animated.
void func_80800128_chboilerid(Actor *actor)
{
    f32 pos[3];
    u8 *data;
    f32 dt;
    s32 active;
    s32 unk_0;
    data = func_80100094(actor, 0);
    dt = func_800D8FF8();
    func_8010D254(pos);
    active = actor->unk70_10 != 1;
    if (active || (!active && actor->unk5F)) {
        _subaddieaudioloop_entrypoint_4(actor, 0, active, &D_80800DA4_chboilerid);
    }
    switch (actor->unk70_10) {
        case 2:
            *(f32 *) (data + 0x1C) += dt;
            if (*(f32 *) (data + 0x1C) >= 1.5f) {
                *(f32 *) (data + 0x1C) = 1.5f;
                func_80101FDC(actor, 3);
            }
            break;
        case 3:
            unk_0 = func_800F54E4();
            if (func_800D9078(&actor->unk58)) {
                chboilerid_entrypoint_5(actor);
            }
            if (func_800F6C5C(unk_0) && func_800F6478(unk_0) && func_800F64A4(unk_0, 0x601) &&
                (func_800F55FC(unk_0) & 0x08000000) && func_800F7B9C(unk_0, 0x51) == 2) {
                func_800BBCB8(pos, 0, 1.0f, 1, &D_80800DB0_chboilerid);
                func_800C4AF0(pos, &D_80800DE8_chboilerid);
            }
            break;
        case 4:
            if (func_800D9078((f32 *) (data + 0x1C))) {
                *(f32 *) (data + 0x1C) = 0.0f;
                func_80101FDC(actor, 1);
                func_800DA3B8(0x66F, 0);
                func_800CF494();
            }
    }
    func_80800418_chboilerid(actor);
    func_80800440_chboilerid(actor);
    func_80800468_chboilerid(actor);
    func_80800998_chboilerid((s32) actor);
    _glid_entrypoint_0(func_800BEA88(0), 0x3C, _chboilerid_entrypoint_1, actor->unk0);
    _glid_entrypoint_0(func_800BEA88(0), 0x3D, _chboilerid_entrypoint_2, actor->unk0);
    _glid_entrypoint_0(func_800BEA88(0), 0x3E, _chboilerid_entrypoint_3, actor->unk0);
    _glid_entrypoint_0(func_800BEA88(0), 0x3F, _chboilerid_entrypoint_4, actor->unk0);
}

int func_808003AC_chboilerid(s32 actor, s32 param_1, s32 param_2)
{
    if (param_1 == 0x95) {
        _subaddielink_entrypoint_3((s32) func_80100094(actor, 0) + 0x60);
        return 1;
    }
    return 0;
}

s32 func_808003EC_chboilerid(s32 actor)
{
    func_800DA524(0x66F);
    func_800CF494();
}

void func_80800418_chboilerid(actor) s32 actor;
{
    _mlwave_entrypoint_1(func_80100094(actor, 0));
}

s32 func_80800440_chboilerid(actor)
s32 actor;
{
    _mlwave_entrypoint_1((s32) func_80100094(actor, 0) + 0x20);
}

s32 func_80800468_chboilerid(actor)
s32 actor;
{
    _mlwave_entrypoint_1((s32) func_80100094(actor, 0) + 0x3C);
}

void chboilerid_entrypoint_1(s32 param_0, Vtx *src, Vtx *dst, s32 count,
                             Unk80132ED0 *param_4)
{
    void *data;
    Vtx *end;

    data = func_80100094(func_80106790(param_4), 0);
    for (end = dst + count; dst < end; dst++, src++) {
        func_80800700_chboilerid(src, dst, data);
    }
}

void chboilerid_entrypoint_2(s32 param_0, Vtx *src, Vtx *dst, s32 count,
                             Unk80132ED0 *param_4)
{
    void *data;
    Vtx *end;
    data = func_80100094(func_80106790(param_4), 0);
    end = dst + count;
    for (; dst < end; dst++, src++) {
        func_80800700_chboilerid(src, dst, data);
        func_8080079C_chboilerid(src, dst, data);
    }
}

void chboilerid_entrypoint_3(s32 param_0, Vtx *src, Vtx *dst, s32 count,
                             Unk80132ED0 *param_4)
{
    void *data;
    Vtx *end;

    data = func_80100094(func_80106790(param_4), 0);
    for (end = dst + count; dst < end; dst++, src++) {
        func_8080079C_chboilerid(src, dst, data);
    }
}

void chboilerid_entrypoint_4(s32 param_0, Vtx *src, Vtx *dst, s32 count,
                             Unk80132ED0 *param_4)
{
    void *data;
    Vtx *end;

    data = func_80100094(func_80106790(param_4), 0);
    end = count + dst;
    for (; dst < end; dst++, src++) {
        func_80800700_chboilerid(src, dst, data);
        func_8080079C_chboilerid(src, dst, data);
        func_80800918_chboilerid(src, dst, data);
    }
}

int func_80800700_chboilerid(src, dst, data)
Prop *src;
Prop *dst;
u8 *data;
{
    f32 pos[3];
    u32 color;
    f32 pulse;

    func_800EE88C(pos, src);
    pulse = _mlwave_entrypoint_4(data, func_800EEF94(pos), 0.6f, 1.0f);
    func_800F3320(&color, (u8 *) src + 0xC, D_80800DFC_chboilerid,
                  *(f32 *) (data + 0x1C) * 0.6666667f);
    func_800F2FD0((u8 *) dst + 0xC, &color, pulse);
}

int func_8080079C_chboilerid(src, dst, data)
u8 *src;
u8 *dst;
u8 *data;
{
    f32 offset[2];

    func_8080084C_chboilerid(data, src, offset);
    *(s16 *) (dst + 8) =
        (s16) (s32) ((f32) *(s16 *) (src + 8) + (f32) *(s16 *) (data + 0x58) * offset[0]);
    *(s16 *) (dst + 0xA) = (s16) (s32) ((f32) *(s16 *) (src + 0xA) +
                                            (f32) *(s16 *) (data + 0x58) * offset[1]);
}

void func_8080084C_chboilerid(data, src, offset) BoilerMotion1312 *data;
s16 *src;
f32 *offset;
{
    f32 dist;
    f32 ripple;
    f32 pos[3];
    f32 scale;

    func_800EE88C(pos, src);
    dist = func_800EEF94(pos);
    ripple = func_800138BC(func_800136D0(data->unk_24 * (dist - data->unk_20))) *
              data->unk_5A * data->unk_24;
    if (dist != 0.0f) {
        scale = ripple / dist;
        offset[0] = pos[0] * scale;
        offset[1] = pos[2] * scale;
    } else {
        offset[0] = pos[0] * ripple;
        offset[1] = pos[2] * ripple;
    }
}

void func_80800918_chboilerid(src, dst, data) Vtx *src;
Vtx *dst;
BoilerWave1472 *data;
{
    f32 pos[3];
    f32 dist;
    f32 height;

    func_800EE88C(pos, src->v.ob);
    dist = func_800EEF94(pos);
    height = _mlwave_entrypoint_4(data->wave, dist, 0.0f, data->amp);
    dst->v.ob[1] = src->v.ob[1] + (s16) (s32) height;
}

void func_80800998_chboilerid(s32 arg0)
{
}
void chboilerid_entrypoint_5(actor) Actor *actor;
{
    u8 *data;
    s32 cfg;

    data = func_80100094(actor, 0);
    if (actor->unk70_10 != 1 && actor->unk70_10 != 4) {
        cfg = func_80800CB0_chboilerid(data);
        _mlwave_entrypoint_3(data, D_80800D00_chboilerid[cfg].values[0],
                             D_80800D00_chboilerid[cfg].values[1]);
        _mlwave_entrypoint_3(data + 0x3C, D_80800D00_chboilerid[cfg].values[4],
                             D_80800D00_chboilerid[cfg].values[5]);
        _mlwave_entrypoint_3(data + 0x20, D_80800D00_chboilerid[cfg].values[8],
                             D_80800D00_chboilerid[cfg].values[9]);
        *(s16 *) (data + 0x58) = D_80800D00_chboilerid[cfg].values[13];
        *(s16 *) (data + 0x5A) = D_80800D00_chboilerid[cfg].values[12];
        *(s16 *) (data + 0x5C) = D_80800D00_chboilerid[cfg].values[14];
        func_80101FDC(actor, 4);
    }
}

// Switches to the raging state; duration is how long it lasts.
void chboilerid_entrypoint_6(Actor *actor, f32 duration)
{
    u8 *data = func_80100094(actor, 0);
    s32 cfg;

    actor->unk58 = duration;
    if (actor->unk70_10 != 3 && actor->unk70_10 != 2) {
        cfg = func_80800CB0_chboilerid(data);
        _mlwave_entrypoint_3(data, (f32) D_80800D00_chboilerid[cfg].values[2],
                             (f32) D_80800D00_chboilerid[cfg].values[3]);
        _mlwave_entrypoint_3(data + 0x3C, (f32) D_80800D00_chboilerid[cfg].values[6],
                             (f32) D_80800D00_chboilerid[cfg].values[7]);
        _mlwave_entrypoint_3(data + 0x20, (f32) D_80800D00_chboilerid[cfg].values[10],
                             (f32) D_80800D00_chboilerid[cfg].values[11]);
        *(s16 *) (data + 0x58) = D_80800D00_chboilerid[cfg].values[13];
        *(s16 *) (data + 0x5A) = D_80800D00_chboilerid[cfg].values[12];
        *(s16 *) (data + 0x5C) = D_80800D00_chboilerid[cfg].values[14];
        func_80101FDC(actor, 2);
        func_800DA3B8(0x66F, 1);
        func_800CF2D4(3);
    }
}

s32 func_80800C48_chboilerid(actor)
s32 actor;
{
    s32 data;
    Actor *found;

    data = func_80100094(actor, 0);
    found = _subaddiefind_entrypoint_0(actor + 4, 0x118, -1, 0);
    if (found != NULL) {
        _subaddielink_entrypoint_1(data + 0x60, found->unk0);
        return 1;
    }
    _subaddielink_entrypoint_0(data + 0x60);
    return 0;
}

int func_80800CB0_chboilerid(data)
Actor *data;
{
    short map_id;
    map_id = *((s32 *) (((char *) data) + 0x5C));
    switch (map_id) {
        case 0xD1:
            return 0;

        case 0xE7:
            return 1;

        default:
            return 2;
    }
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to functions of
// this file; IDO's assembler schedules some of these functions differently unless the tables are
// in the same unit. Values are taken from the ROM.
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
// Settings per map: boiler, Inferno, other.
BoilerSettings29 D_80800D00_chboilerid[3] = {
    0x12C, 0x64, 0x226, 0xFA, 0x64, 0x28, 0x12C, 0x96, 0xC8, 0x28, 0x1F4, 0xFA, 0x19, 0x40, 0xF,
    0x12C, 0x64, 0x226, 0xFA, 0x50, 0x28, 0x96,  0x96, 0xC8, 0x28, 0x1F4, 0xFA, 0x19, 0x40, 0x32,
    0x12C, 0x64, 0x226, 0xFA, 0x64, 0x28, 0x12C, 0x96, 0xC8, 0x28, 0x1F4, 0xFA, 0x19, 0x40, 0x14};
int D_80800D5C_chboilerid[18] = {0x1AE0321,
                                 0x1,
                                 0x0,
                                 (u32) func_80800128_chboilerid,
                                 (u32) func_80102EC0,
                                 (u32) func_80101870,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_808003EC_chboilerid,
                                 0x0,
                                 0x680000,
                                 (u32) func_8080000C_chboilerid,
                                 (u32) func_80107C2C,
                                 -0x7FFFF9FE,
                                 (u32) func_808003AC_chboilerid,
                                 0x0};
s32 D_80800DA4_chboilerid[3] = {0x130486, 0xA0040, 0x140000};
s32 D_80800DB0_chboilerid[14] = {0x1D09DD, 0x20B4B4,  -0x4B3FFFD5, 0x1000133, 0x220033,
                                 0x4C0180, 0x2000015, 0x80,        0x190000,  0x7002C,
                                 0x64,     0x0,       0xC80000,    0x0};
s32 D_80800DE8_chboilerid[5] = {0x1304DC, 0xD00B3, 0xCC0015, 0x190080, 0x190000};
u8 D_80800DFC_chboilerid[4] = {0xFF, 0xAA, 0x0, 0x0};
