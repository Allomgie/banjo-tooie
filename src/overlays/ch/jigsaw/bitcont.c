#include "common.h"

typedef struct {
    s16 jiggy_index;
    s16 piece_count;
    u8 pad_4[8];
    s16 unk_C;
    s16 flag_base;
} JigsawInfo;
typedef struct {
    u8 pad_0[0x24];
    s16 collected;
} JigsawData;
typedef struct {
    u8 pad0[0x74];
    u32 pad74 : 10;
    u32 unk74_21 : 1;
    u32 pad74_0 : 21;
} JigsawActor;
extern void _chjigsawcollect_entrypoint_1(Actor **, s32, s32);
extern s32 func_800DA298(s32);
extern void func_80100120(Actor *);
typedef struct {
    u8 pad_0[0x24];
    s16 collected;
} JigsawBitCounter;
typedef struct {
    s16 piece_count;
    u8 pad_2[0xE];
} JigsawBitThreshold;
extern JigsawBitThreshold D_808009AA_chjigsawbitcont[];
extern void func_80108B04(Actor *, s32);
extern s32 D_808009B4_chjigsawbitcont;
typedef struct JigsawBitSettings {
    s16 jiggy_index;
    s16 piece_count;
    f32 delay_min;
    f32 delay_max;
    s16 unk_C;
    s16 flag_base;
} JigsawBitSettings;
extern JigsawBitSettings D_808009A8_chjigsawbitcont[];
extern s16 D_808009B6_chjigsawbitcont[][8];
extern Actor *func_80106790(Unk80132ED0 *);
extern void *func_80100094(Actor *, u32);
extern void func_800DA544(s32);
extern void func_800D0BD4(s32, s32);
extern void func_800FC660(s32);
extern void func_800FCAE0(s32, s32, s32);
extern int D_808009B8_chjigsawbitcont[];
extern f32 func_800DC178(f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern u8 D_808009A0_chjigsawbitcont[];
extern f32 func_800D8FF8(void);
extern Actor *func_801084B0(s32, Actor **);
extern int D_80800A28_chjigsawbitcont[];
extern s32 D_80800A00_chjigsawbitcont[];
f32 func_800DC0C0(void);
s32 func_800E3E8C(s32, s32);
s32 func_8001211C(void);
s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
s32 func_8010C9B0(s32, s32);
void func_800FFAB0(s32);
void func_80800890_chjigsawbitcont();
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_808002E4_chjigsawbitcont();

void func_80800000_chjigsawbitcont(u8 *actor, s32 mode)
{
    func_80101FDC();
    if ((mode == 2) &&
        (func_800DA298(*(s16 *) ((u8 *) &D_808009B4_chjigsawbitcont +
                                 (((u32) *(u16 *) ((u8 *) actor + 0x76) >> 7) * 0x10))) == 0)) {
        func_800DA544(*(s16 *) ((u8 *) &D_808009B4_chjigsawbitcont +
                                (((u32) *(u16 *) ((u8 *) actor + 0x76) >> 7) * 0x10)));
        func_80108B04(actor, 0);
    }
}

// Messages: 0x3D spawns the missing pieces, or gives the jiggy when arg is -1.
s32 func_80800084_chjigsawbitcont(actor, msg, arg)
Actor *actor;
s32 msg;
s32 arg;
{
    JigsawData *data;
    s32 i;

    data = func_80100094(actor, 0);
    switch (msg) {
        case 0x3D:
            if (arg == -1) {
                _chjigsawcollect_entrypoint_1(
                    &actor, ((JigsawInfo *) D_808009A8_chjigsawbitcont)[actor->unk74_7].jiggy_index,
                    0);
            } else {
                for (i = 0; i < ((JigsawInfo *) D_808009A8_chjigsawbitcont)[actor->unk74_7].piece_count;
                     i++) {
                    if (!func_800DA298(
                            ((JigsawInfo *) D_808009A8_chjigsawbitcont)[actor->unk74_7].flag_base +
                            i)) {
                        func_80800890_chjigsawbitcont(actor, i, arg);
                    } else {
                        data->collected++;
                    }
                }
            }
            break;
        case 0xA:
            if (!((JigsawActor *) actor)->unk74_21) {
                func_80100120(actor);
            }
            if (arg == actor->unk74_7 &&
                !func_800DA298(
                    ((JigsawInfo *) D_808009A8_chjigsawbitcont)[actor->unk74_7].unk_C)) {
                func_80800000_chjigsawbitcont(actor, 2);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

// Per frame: counts down the music cue; on expiry fades out track 5 while pieces are still missing.
void func_80800214_chjigsawbitcont(Actor *actor)
{
    JigsawBitCounter *counter;

    counter = func_80100094(actor, 0);
    // Matching: empty triple test burns temporaries.
    if (actor->unk74_7 && actor->unk74_7 && actor->unk74_7) {
    }
    if (actor->unk64_20) {
        ((f32 *) actor->actorData)[4] -= func_800D8FF8();
        if (((f32 *) actor->actorData)[4] < 0.0f) {
            ((f32 *) actor->actorData)[4] = 0.0f;
            actor->unk64_20 = 0;
            if (counter->collected < D_808009AA_chjigsawbitcont[actor->unk74_7].piece_count &&
                func_800FCCD4(5)) {
                func_800FCAE0(5, 0, 0x1F40);
                func_800FCA90(5);
            }
        }
    }
}

// Init: stores the piece positions found at markers 0x312.
void func_808002E4_chjigsawbitcont(actor) Actor *actor;
{
    f32 *marker_pos[3];
    u8 *data;
    s32 count;
    s32 i;

    data = func_80100094(actor, 0);
    actor->unk74_7 = actor->unk74_7 - 50;
    if (actor->unk74_7 != 0) {
        func_800FFAB0(actor);
        return;
    }
    if (func_800D0B68(*(s16 *) ((u8 *) (struct JigsawBitSettings *) D_808009A8_chjigsawbitcont +
                                actor->unk74_7 * 0x10),
                      1, actor->unk74_7)) {
        func_800FFAB0(actor);
        return;
    }
    *(s16 *) (data + 0x24) = 0;
    count = _gccubesearch_entrypoint_9(0x312, marker_pos, 3);
    for (i = 0; i < count; i++) {
        func_800EE88C((f32 *) (data + i * 0xC), marker_pos[i]);
    }
    if (func_800DA298(*(s16 *) ((u8 *) &D_808009B4_chjigsawbitcont + actor->unk74_7 * 0x10))) {
        func_80108B04(actor, 1);
    }
}

// Piece collected: sets its flag and raises the music cue; the last piece gives the jiggy.
void func_8080040C_chjigsawbitcont(Actor *piece)
{
    Actor *container;
    JigsawBitCounter *counter;
    JigsawBitSettings *settings;
    s16 collected;
    f32 ratio;

    container = func_80106790(piece->unk3C);
    counter = func_80100094(container, 0);
    counter->collected++;
    func_800DA544(D_808009B6_chjigsawbitcont[container->unk74_7][0] + piece->unk6C_0);
    collected = counter->collected;
    settings = &D_808009A8_chjigsawbitcont[container->unk74_7];
    // Matching: empty block needed for the match.
    if (settings) {
    }
    if (collected == D_808009A8_chjigsawbitcont[container->unk74_7].piece_count) {
        func_800D0BD4((&D_808009A8_chjigsawbitcont[container->unk74_7])->jiggy_index, 1);
        func_800FC660(5);
        func_80108B04(container, -1);
        return;
    }
    if (!container->unk64_20) {
        ratio = (f32) collected / (f32) D_808009A8_chjigsawbitcont[container->unk74_7].piece_count;
        ((f32 *) container->actorData)[4] = 1.75f * ratio;
        func_800FC660(5);
    } else {
        ratio = 1.0f / (f32) D_808009A8_chjigsawbitcont[container->unk74_7].piece_count;
        ((f32 *) container->actorData)[4] += 1.75f * ratio;
        func_800FCAE0(5, 0x7FFF, 8000);
    }
    container->unk64_20 = 1;
}

int chjigsawbitcont_entrypoint_0()
{
    return (int) &D_808009B8_chjigsawbitcont;
}

void func_80800570_chjigsawbitcont(Actor *actor, s32 state)
{
    func_80101FDC(actor, state);
    switch (actor->unk70_10) {
        case 2:
            actor->unk79_4 = 3;
            *(f32 *) &actor->actorData[3] = func_800DC178(0.0f, 250.0f);
            _subaddiebounce_entrypoint_0(actor);
            actor->unk64_16 = 1;
            break;
        case 3:
            func_800EE7F8(actor->position, (f32 *) actor->actorData);
            _subaddieDll_entrypoint_4(actor, 0);
            break;
        case 4:
            func_800EE7F8(actor->position, (f32 *) actor->actorData);
            actor->unk64_16 = 1;
    }
}

// Collects the piece when the player is within 50 units.
void func_80800634_chjigsawbitcont(actor) s32 actor;
{
    s32 pos;
    s32 pos_addr;

    pos_addr = actor + 4;
    // Matching: duplicate temporary needed for the match.
    pos = pos_addr;

if ((func_800E3E8C(pos_addr, 0x42480000) != 0) && !(func_8001211C() & 3) &&
    (func_800DC0C0() < 0.1f)) {
    func_800BBCB8(pos, 0, 0x3F800000, 2, &D_80800A00_chjigsawbitcont);
}

if (func_8010C9B0(pos, 0x32) != 0) {
    func_8080040C_chjigsawbitcont(actor);
    func_800FFAB0(actor);
}

}

// Piece update: state 1 waits for the spawn delay, 2 bounces and spins, 3 and 4 only check pickup.
void func_808006D8_chjigsawbitcont(Actor *actor)
{
    f32 dt;
    f32 spin;

switch (actor->unk70_10) {
    case 1:
        *(u8 *) ((u8 *) actor + 0x65) &= ~1;
        if (actor->unk58 > 0.0f) {
            actor->unk58 -= func_800D8FF8();
        } else {
            func_80800570_chjigsawbitcont(actor, 2);
        }
        return;
    case 2:
        dt = func_800D8FF8();
        func_80800634_chjigsawbitcont(actor);
        if (actor->unk79_4 >= 3) {
            if (_subaddiebounce_entrypoint_1(actor)) {
                actor->unk79_4 = 2;
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808009A0_chjigsawbitcont);
            }
            spin = 360.0f * dt;
            actor->rotation[1] += spin;
            actor->rotation[0] += spin;
        } else if (_subaddiebounce_entrypoint_2(actor)) {
            actor->unk79_4--;
            if (actor->unk79_4 <= 0) {
                func_80800570_chjigsawbitcont(actor, 3);
            }
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_808009A0_chjigsawbitcont);
        }
        return;
    case 3:
    case 4:
        func_80800634_chjigsawbitcont(actor);
}

}

void func_80800868_chjigsawbitcont(void *actor)
{
    (*(f32 *) ((char *) (actor) + 0x38)) = 0.2f;
    (*(f32 *) ((char *) (actor) + 0x34)) = -1500.0f;
    (*(f32 *) ((char *) (actor) + 0x24)) = 840.0f;
}

// Spawns one piece actor (0x17F) for the stored position index.
void func_80800890_chjigsawbitcont(container, index, mode) Actor *container;
s32 index;
s32 mode;
{
    Actor *piece;
    f32(*positions)[3];

    piece = func_801084B0(0x17F, &container);
    positions = func_80100094(container, 0);
    piece->unk6C_0 = index;
    func_800EE7F8((f32 *) ((u8 *) piece + 0x18), positions[piece->unk6C_0]);
    piece->unk3C = container->unk0;
    piece->unk58 = func_800DC178(D_808009A8_chjigsawbitcont[container->unk74_7].delay_min,
                                   D_808009A8_chjigsawbitcont[container->unk74_7].delay_max);

switch (mode) {
    case 0:
        _subaddieDll_entrypoint_4(piece, 1);
        break;
    case 1:
        func_80800570_chjigsawbitcont(piece, 4);
}

}

int chjigsawbitcont_entrypoint_1()
{
    return (int) &D_80800A28_chjigsawbitcont;
}

// TU-NOTE: the .data of this overlay is defined here in C; its tables point to functions of this file,
// and IDO schedules some of them differently unless they are in the same unit. Values come from the ROM.
// TU-NOTE: linker symbols (undefined_syms.us.txt): D_808009AA = D_808009A8 + 0x2, D_808009B4 = D_808009A8 + 0xC,
// D_808009B6 = D_808009A8 + 0xE. Externs retyped to the objects: D_808009B8 int[], D_80800A00 s32[], D_80800A28 int[].
extern void func_80101870();
u8 D_808009A0_chjigsawbitcont[8] = {0x0, 0x13, 0x3, 0xE9, 0x0, 0x18, 0x0, 0x0};
JigsawBitSettings D_808009A8_chjigsawbitcont[1] = {0x11, 0x3, 0.5f, 2.5f, 0x40F, 0x410};
int D_808009B8_chjigsawbitcont[18] = {0x2640180,
                                      0x1,
                                      0x0,
                                      (u32) func_80800214_chjigsawbitcont,
                                      (u32) func_80105834,
                                      (u32) func_8010A730,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x80004,
                                      0x0,
                                      0x0,
                                      0x280000,
                                      (u32) func_808002E4_chjigsawbitcont,
                                      (u32) func_80107C2C,
                                      -0x7FFFFDFE,
                                      (u32) func_80800084_chjigsawbitcont,
                                      0x0};
s32 D_80800A00_chjigsawbitcont[10] = {0x1D09E2, 0xC0014,  0x22004C, 0x660019, 0xC002A,
                                      0x2,      0x8000C0, 0x150000, 0x20016,  0x40000};
int D_80800A28_chjigsawbitcont[18] = {0x263017F,
                                      0x6A50001,
                                      0x0,
                                      (u32) func_808006D8_chjigsawbitcont,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x5DC0000,
                                      0x3F4CCCCD,
                                      0x0,
                                      0x4,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800868_chjigsawbitcont,
                                      (u32) func_80107C2C,
                                      -0x7FFFFFFE,
                                      0x0,
                                      0x0};
