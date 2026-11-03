#include "core2/1E80A70.h"
extern u32 D_80127650;

extern void func_800E3BFC(f32, f32, f32);
extern void func_800E3C58(f32, f32, f32);
extern void func_800E3900(f32);
extern void func_800E3CE8(void);
extern u8 D_8012762C;
extern s16 D_80127632;
extern u8 D_80127647;
extern f32 D_8012763C;
typedef struct {
    s16 field0;
    s16 field2;
    s16 field4;
    u8 pad6[2];
    f32 field8;
    u8 padC[4];
    s16 field10;
    u8 field12, field13, field14, field15, field16, field17;
    u8 pad18[2];
    u8 field1A, field1B, field1C;
} LocalState;
extern s32 func_8001BD50(f32);
extern s16 D_80127634;
typedef struct {
    u8 pad0[0x10];
    s16 unk10;
    u8 pad12;
    u8 unk13;
    u8 pad14;
    u8 unk15;
    u8 unk16;
    u8 pad17;
    u8 unk18;
} G_A7A6C;
extern f32 D_80127638;
extern s32 D_8011A418;
extern s32 D_8011A3F8[];
extern void func_80015E80(s32, s32 *);
extern void func_80015F28(s32, s32 *);
extern void func_80015FFC(s32, s32 *);
extern s32 func_80015F84(s32);
extern struct {
    s32 local_0, local_1, local_2;
} D_80127670;
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} Struct_8011A420;
extern Struct_8011A420 D_8011A420[];
extern void func_800158E4(s32);
extern void func_80015CE8(s32, s32);
extern s32 func_8001592C(s32, s32, s32, s32);
extern void func_800C54CC(s32, f32, f32);
extern s32 D_80127678[];
extern void func_800C5464(void);
extern s32 func_800CA334(void);
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} T8670;
typedef struct {
    s32 local_0;
    s32 local_1;
    s32 local_2;
} local_type;
extern void func_800CA558(s32, f32, s32);
extern void func_800C5668(s32, s32);
void func_800A7A18();
void func_800A7A6C();
void func_800A861C();
int func_800A8670();
void func_800A8710();
s32 func_800A8BD4();

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    s16 mapValue;
    u8 unk12;
    s8 entranceIndex;
    s32 unk14;
    s8 unk18;
    s8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
} D_80127630_unk;
extern s32 D_8011A3F0;
extern s32 D_8011A3F4;

typedef union {
    LocalState LocalState;
    D_80127630_unk D_80127630_unk;
    G_A7A6C G_A7A6C;
    u8 arr[1];
} Union_D_80127630;
// Global game state; game mode at +2.
extern Union_D_80127630 D_80127630;
extern s32 D_80127658;
extern s32 D_80127674;
extern void *D_801276BC;
typedef struct {
    s32 unk0, unk4;
    f32 unk8;
} unk_D_80127688;
// Viewport table: 4 player viewports plus the full-screen one at index 4.
extern unk_D_80127688 D_80127688[];

s32 *func_800A7180(void)
{
    return &D_80127658;
}

void func_800A718C(void)
{
    func_800E3BFC(0.0f, 0.0f, 0.0f);
    func_800E3C58(-30.0f, 30.0f, 0.0f);
    func_800E3900(6e+03f);
    func_800E3CE8();
}

int func_800A71E0()
{
    s32 i;
    func_800D58CC();
    func_8001A570();
    func_8001B840();
    for (i = 0; i < 0xf; i++) {
        func_8001B518(1);
        func_800DF874();
        _cosectionstor_entrypoint_2();
        func_800C9484();
        func_800B5E3C();
        func_800D58AC();
        func_800E4C7C();
        func_800CA174();
        func_800FCD5C();
        func_800A9D00();
        func_800C9484();
        func_800B4380();
        func_8008BA5C();
        func_800DA1E0();
        func_800D15CC();
    }
}

// Loads a map via the gcsection/gclevel/gcgame overlays.
void func_800A72A4(s32 map, s32 entrance, s32 unk_2, s32 unk_3)
{
    s32 old_section;
    s32 new_section;

    old_section = (s32) D_8012762C;
    new_section = _gcsectionDll_entrypoint_4();
    func_800E96E0();
    _gcsectionDll_entrypoint_1(1);
    if ((unk_3 != 0) || (unk_2 != 0) || (new_section != old_section)) {
        _gclevel_entrypoint_1();
        if (unk_3 != 0) {
            _gcgame_entrypoint_1();
            _gcgame_entrypoint_0(1);
        }
        _gclevel_entrypoint_0(map, entrance);
    }
    _gcsectionDll_entrypoint_0(map, entrance);
    func_801101C0();
    func_800A8D70(map, entrance);
    func_80081724();
    func_800EA0CC(map, entrance, 0);
    func_800A718C();
}

// Unloads the current map.
int func_800A7380(s32 unk_0)
{
    func_800EA0A8();
    func_800A8F68();
    func_800C2AB8();
    func_800FB968();
    func_8001A2B0();
    func_800D6C64();
    func_800D58CC();
    func_8008B768();
    func_80081724();
    if (unk_0 != 0) {
        func_800A71E0();
    }
}

void func_800A8CCC();

void func_800A8BA8();

s32 func_800A89F8();

// Draws the scene once per viewport, then HUD and writeback.
void func_800A73F4(s32 unk_0, s32 unk_1)
{
    s32 start_4;
    s32 start_8;
    start_4 = *(s32 *) ((s8 *) &D_80127658 + 4);
    start_8 = *(s32 *) ((s8 *) &D_80127658 + 8);
    func_800A8670();
    func_800A9378();
    func_800F5184();
    func_800A8BA8(&D_80127658, unk_1);
    if (func_800A8BD4(&D_80127658, -1, unk_1) != 0) {
        do {
            func_800E9F20(func_800A89F8(), unk_1);
        } while (func_800A8BD4(&D_80127658, -1, unk_1) != 0);
    }
    func_800A8CCC(&D_80127658, unk_1);
    if (D_80127632 == 5) {
        func_800A9AA4(&D_80127658);
    }
    if (func_800EA358() != 0) {
        func_800EB51C(3, &D_80127658);
    }
    func_800C0984(&D_80127658);
    func_800C9358(&D_80127658, unk_1);
    func_800C0130(&D_80127658);
    if (func_800EA358() != 0) {
        func_800EB51C(4, &D_80127658);
    }
    func_800FA508(&D_80127658);
    func_800B7448(&D_80127658);
    func_800C940C(&D_80127658, unk_1);
    func_800E7EF4(&D_80127658);
    osWritebackDCache(start_4, ((s32) (*(s32 *) ((s8 *) &D_80127658 + 4) - start_4) >> 6) << 6);
    osWritebackDCache(start_8, ((s32) (*(s32 *) ((s8 *) &D_80127658 + 8) - start_8) >> 4) * 0x10);
    func_800F51A8();
    func_800D36A8();
    func_800FFC90();
    // Matching: the "* 0" argument is needed for the match.
    func_800A89BC((((s32) (*(s32 *) ((s8 *) &D_80127658 + 8) - start_8) >> 4) * 0x10) * 0);
}

// Queues a mode change; applied on the next update.
void func_800A7584(mode, unk_1) s32 mode;
s32 unk_1;
{
    D_80127630.arr[0x1a] = mode + 1;
    D_80127630.arr[0x1b] = unk_1;
}

// Switches the game mode (2 loading, 3 playing, 4 paused, 5 special sequence).
// Header: core2/1E80A70.h must declare this and func_800A76F4 with s32 arguments.
void func_800A759C(s32 mode, s32 unk_1)
{
    s32 prev_mode;
    prev_mode = D_80127632;
    if ((D_80127632 == 3 && mode != 4) || (D_80127632 == 4 && mode != 3))
        func_800C9B84();
    if (D_80127632 == 4 && mode != 4)
        func_800C0920();
    if (D_80127632 == 5)
        func_800A9AF8();
    D_80127632 = mode;
    switch (D_80127632) {
        case 2:
            func_800EA148(3);
            break;
        case 5:
            func_800A9998();
        case 3:
            if (prev_mode != 4)
                func_800EA148(2);
            if (unk_1 && !D_80127647)
                func_800C9598();
            D_8012763C = 0.0f;
            break;
        case 4:
            func_800EA334(0);
            func_8001608C();
            func_800C08F8();
    }
}

// Handles a warp: unloads the map, reloads the saved one and returns to mode `mode`.
void func_800A76F4(s32 mode)
{
    s32 unk_1, unk_2, transition, map, entrance, unk_6;
    func_800FB968();
    _glintrosyncDll_entrypoint_0(D_80127630.LocalState.field10);
    func_8001A2B0();
    unk_1 = D_80127630.LocalState.field16;
    unk_2 = D_80127630.LocalState.field15;
    transition = D_80127630.LocalState.field14;
    map = D_80127630.LocalState.field10;
    entrance = D_80127630.LocalState.field13;
    unk_6 = D_80127630.LocalState.field0;
    D_80127630.LocalState.field16 = 0;
    D_80127630.LocalState.field15 = 0;
    D_80127630.LocalState.field14 = 0;
    D_80127630.LocalState.field10 = 0;
    D_80127630.LocalState.field13 = 0;
    func_800A759C(2, 0);
    D_80127630.LocalState.field1C = mode;
    func_800A5CF0(0);
    if (!(func_800DA9E4(0x647, 0) &&
          _gcsectionDll_entrypoint_4(D_80127630.LocalState.field10) != D_8012762C) &&
        !func_800DA298(0x650))
        _cosectionstor_entrypoint_3(func_800EA05C());
    func_800A7380(1);
    func_800A72A4(map, entrance, unk_2, unk_1);
    func_800A5CF0(1);
    func_800A5C94();
    func_80081724();
    _glintrosyncDll_entrypoint_1();
    D_80127630.LocalState.field0 = unk_6;
    D_80127630.LocalState.field1C = 2;
    func_800A759C(mode, transition);
    func_80015768();
}

void func_800A7FD4();

// Per-frame draw.
void func_800A7840(s32 unk_0)
{
    s32 buf_start;
    s32 buf_end;

    func_8001A4B8((u32 *) &D_80127658);
    if (D_80127634 != 0) {
        func_8001A4B8((u32 *) &D_80127658);
    }
    buf_start = (u32) D_80127658;
    func_800A73F4(func_80014F58(), unk_0);
    if (D_80127634 == 0) {
        buf_end = (u32) D_80127658;
        func_80015410();
        if (D_80127650 == 0) {
            if (func_8001BD50(0.4f) != 0) {
                func_800A7FD4();
            }
        }
        func_800E82EC();
        func_8001A270(buf_start, buf_end);
    }
    func_80015878();
    func_800E4628();
    D_80127634 = 0;
    D_80127650 = 0;
}

void func_800A791C(s32 map, s32 entrance, s32 transition)
{
    func_800A79D4(map, entrance);
    func_800A7A90(transition);
    func_800A7B18(1U);
}

int func_800A794C(s32 map, s32 entrance, s32 transition)
{
    func_800FE8EC();
    func_800A7A18(map, entrance);
    func_800A7A90(transition);
    func_800A7B18(1);
}

void func_800A7990(s32 map, s32 entrance, s32 transition)
{
    func_800FE8EC();
    func_800A7A6C(map, entrance);
    func_800A7A90(transition);
    func_800A7B18(1);
}

void func_800A79D4(s32 map, s32 entrance)
{
    func_800FE4E4();
    *(u8 *) ((char *) &D_80127630 + 0x16) = 1;
    *(u8 *) ((char *) &D_80127630 + 0x15) = 0;
    *(s16 *) ((char *) &D_80127630 + 0x10) = map;
    *(u8 *) ((char *) &D_80127630 + 0x13) = entrance;
}

void func_800A7A18(map, entrance) s32 map;
s32 entrance;
{
    func_800FE8EC();
    // Matching: the nested casts are needed for the match.
    *(u8 *) ((char *) (u8 *) D_80127630.arr + 0x16) = 0;
    *(u8 *) ((char *) (u8 *) D_80127630.arr + 0x15) = 1;
    *(s16 *) ((char *) (u8 *) D_80127630.arr + 0x10) = map;
    *(u8 *) ((char *) (u8 *) D_80127630.arr + 0x13) = entrance;
}

void func_800A7A5C(void)
{
    D_80127630.D_80127630_unk.unk18 = 1;
}

void func_800A7A6C(map, entrance) s32 map;
s32 entrance;
{
    D_80127630.G_A7A6C.unk15 = D_80127630.G_A7A6C.unk18;
    D_80127630.G_A7A6C.unk16 = 0;
    D_80127630.G_A7A6C.unk10 = map;
    D_80127630.G_A7A6C.unk13 = entrance;
    D_80127630.G_A7A6C.unk18 = 0;
}

void func_800A7A90(transition) s32 transition;
{
    D_80127630.arr[0x14] = transition;
    D_80127630.arr[0x17] = 0;

if (transition != 0 && func_800C9510() == 0) {
    func_800C9610();
}

}

void func_800A7AD4(s32 transition, s32 unk_1)
{
    // Matching: the casts are needed for the match.
    ((u8 *) ((s32 *) D_80127630.arr))[0x14] = (u8) transition;
    ((u8 *) ((s32 *) D_80127630.arr))[0x17] = (u8) unk_1;

if (transition != 0 && !func_800C9510()) {
    func_800C964C(unk_1);
}

}

// Set warp bit to on.
void func_800A7B18(u32 warpVal)
{
    D_80127630.D_80127630_unk.unk12 = warpVal;
}

// Game shutdown.
int func_800A7B24()
{
    func_800A759C(2, 0);
    func_80013430();
    func_800B5DF4();
    func_800CA060();
    func_800DF35C();
    func_800A7380(0);
    _gcsectionDll_entrypoint_1(0);
    _gclevel_entrypoint_1();
    _gcgame_entrypoint_1();
    func_8008B64C();
    func_800FB908();
    func_800C2A90();
    func_800A8710();
    func_800E4290();
    _glcutDll_entrypoint_2();
}

// Game init; loads the start map.
void func_800A7BB8(s32 map)
{
    func_800A5CF0(1);
    D_80127630.LocalState.field12 = 0;
    D_80127630.LocalState.field10 = D_80127630.LocalState.field13 = D_80127630.LocalState.field14 =
        D_80127630.LocalState.field17 = D_80127630.LocalState.field15 =
            D_80127630.LocalState.field16 = 0;
    D_80127630.LocalState.field1A = 0;
    D_80127630.LocalState.field1B = 0;
    D_80127630.LocalState.field4 = 0;
    func_800A8240();
    func_800DA238();
    func_800DA268();
    _glglobaldata_entrypoint_0();
    _glglobalsettings_entrypoint_1();
    _glgamedata_entrypoint_0();
    func_800D3970();
    func_800E4278();
    func_800A861C();
    func_800C2A08();
    func_800FB808();
    _glcutDll_entrypoint_3();
    func_800CA098();
    func_800D34A0();
    func_800B5DD4();
    func_800133A0();
    func_800DF38C();
    func_8008B610();
    func_800DC310();
    func_8001A290();
    func_800D8F84();
    _gsattract_entrypoint_4();
    func_800EBB5C();
    _gcgame_entrypoint_0(0);
    D_80127630.LocalState.field2 = 2;
    D_80127630.LocalState.field8 = 0.0f;
    func_800D8FA0(0);
    _gclevel_entrypoint_0(map, 0);
    _gcsectionDll_entrypoint_0(map, 0);
    func_800A71E0();
    func_800A72A4(map, 0, 0, 0);
    D_80127630.LocalState.field0 = 0;
    func_800A759C(3, 1);

}

int func_800A7D30()
{
    if (D_80127638 == 0) {
        func_800D8FA0(0);
    }

else
{
    // Matching: the "| 0" is needed for the match.
    func_800D8FA0(func_80014F4C() | 0);
}
}

// Per-frame update; returns 0 when a warp was handled, else 1.
s32 func_800A7D84(void)
{
    s32 unk_0;
    s32 warp;

    D_80127630.D_80127630_unk.unk8 += func_800D8FF8();

if (func_800C9510() == 0) {
    warp = D_80127630.D_80127630_unk.unk12;
    D_80127630.D_80127630_unk.unk12 = 0U;
    if (warp != 0) {
        // Warp request: 1 play, 2 keep current mode, 3 special sequence.
        switch (warp) {
            case 1:
                func_800A76F4(3);
                return 0;
            case 2:
                func_800A76F4(D_80127630.D_80127630_unk.unk2);
                return 0;
            case 3:
                func_800A9924(D_80127630.D_80127630_unk.mapValue,
                              D_80127630.D_80127630_unk.entranceIndex);
                func_800A76F4(5);
                return 0;
        }
    }
}

if (D_80127630.D_80127630_unk.unk1A != 0) {
    func_800A759C(D_80127630.D_80127630_unk.unk1A - 1, D_80127630.D_80127630_unk.unk1B);
    D_80127630.D_80127630_unk.unk1A = 0U;
}

unk_0 = func_800EA170();

if ((D_8011A3F4 != 0) && (D_8011A3F0 == 0)) {
    func_800A8278();
}

func_800C7900();
func_800C427C();
func_800FB968();

switch (D_80127630.D_80127630_unk.unk2) {
    case 5:
        func_800A9A14();
        break;
    case 3:
        D_80127630.D_80127630_unk.unkC += func_800D8FF8();
        if ((0.6f < D_80127630.D_80127630_unk.unkC) && (func_800C0A34() != 0)) {
            func_800A759C(4, 0U);
        } else if (unk_0 == 0) {
            func_800A759C(3, 1U);
        }
        break;
    case 4:
        if (func_800C0948() != 0) {
            func_800EA334(1);
            func_800EA34C(1);
            func_800A759C(3, 0U);
            func_800FFC14();
            func_800F8850();
        }
}

if (func_800A819C() != 0) {
    func_800CA0A8();
}

func_800C92A8();
return 1;
}

void func_800A7FB4()
{
    func_800A7584();
}

void func_8001B84C(void);
void defragment_overlays(void);
void func_801015C8(void);
void func_80017840(void);
void func_800D8674(void);
void func_800B5A6C(void);
void func_800A5654(void);
void func_800A95C4(void);
void func_800F86D8(void);
void func_800F91EC(void);
void func_800B562C(void);
void func_800BF58C(void);
void func_800BD600(void);
void func_800CCFEC(void);
void func_800A5D6C(void);
void func_8010E030(void);
void func_800C075C(void);
void func_800C08C0(void);
void func_801005B8(void);
void func_800D6D68(void);
void func_80100E54(void);
void func_800BFFF4(void);
void func_800C9074(void);
void func_800DBB64(void);
void func_800E8B3C(void);
void func_800A86D8(void);
void func_800EE670(void);
void func_800ABA20(void);
void func_800FA608(void);
void func_800E8A20(void);
void func_800EB7A8(void);
void func_800D88C0(void);
void func_800FFE08(void);
void func_8001B858(void);

// do_tidy: defragments everything; run when memory is fragmented.
void func_800A7FD4(void)
{
    D_80127650 = 1;
    func_8001B84C();
    func_8001B840();
    defragment_overlays();
    func_8001B518(0);
    func_801015C8();
    func_80017840();
    func_800D8674();
    func_8008BA5C();
    func_800B5A6C();
    func_800A5654();
    func_800DF874();
    func_800A95C4();
    func_800F86D8();
    func_800F91EC();
    func_800B562C();
    func_800BF58C();
    func_800BD600();
    func_800CCFEC();
    func_800A5D6C();
    func_800B5E3C();
    func_800DA1E0();
    func_800D15CC();
    func_8010E030();
    func_800C075C();

if (D_80127630.D_80127630_unk.unk2 == 4) {
    func_800C08C0();
}

func_801005B8();
func_800D6D68();
func_80100E54();
func_800BFFF4();
func_800C9074();
func_800DBB64();
func_800E8B3C();
func_800A86D8();
func_800EE670();
func_800ABA20();
func_800FA608();
func_800E8A20();
func_800A9D00();
func_800C9484();
func_800B4380();
func_800EB7A8();
func_800D88C0();
func_800FFE08();
func_8001B858();
}

void func_800A8168(void)
{
    D_80127630.D_80127630_unk.unk4 = 1;
}

s16 func_800A8178(void)
{
    return D_80127630.D_80127630_unk.unk4;
}

s16 func_800A8184(void)
{
    return D_80127630.D_80127630_unk.unk2;
}

u8 func_800A8190(void)
{
    return D_80127630.D_80127630_unk.unk1C;
}

int func_800A819C(void)
{
    return D_80127630.D_80127630_unk.unk2 == 3 || D_80127630.D_80127630_unk.unk2 == 5;
}

int func_800A81C4(void)
{
    s32 map_section, unk_1;

if (D_80127630.D_80127630_unk.mapValue == 0) {
    return 0;
}

map_section = _gcsectionDll_entrypoint_4(D_80127630.D_80127630_unk.mapValue);
unk_1 = _gcsectionDll_entrypoint_4(func_800EA05C());
return unk_1 != map_section && D_80127630.D_80127630_unk.unk6 == 0;
}

void func_800A8230(void)
{
    D_80127630.D_80127630_unk.unk6 = 1;
}

void func_800A8240(void)
{
    D_80127630.D_80127630_unk.unk6 = 0;
}

s16 func_800A824C(void)
{
    return D_80127630.D_80127630_unk.unk6;
}

f32 func_800A8258(void)
{
    return D_80127630.D_80127630_unk.unk8;
}

int func_800A8264(void)
{
    return D_80127630.D_80127630_unk.unk12 != 0;
}

// Matches controller input against the secret sequence D_8011A3F8; completing it
// sets D_8011A3F0, which enables the crash debugger.
void func_800A8278(void)
{
    s32 i;
    s32 expected;
    s32 input[14];

    D_8011A3F4 -= 1;
    func_80015E80(0, input);
    func_80015F28(0, &input[6]);
    func_80015FFC(0, &input[9]);
    input[13] = func_80015F84(0);
    expected = D_8011A3F8[D_8011A418];

if (input[expected] == 1) {
    D_8011A418 += 1;
}

for (i = 0; i != 0xE; i++) {

if (i != expected && input[i] == 1) {
    D_8011A418 = 0;
    break;
}

}
if (D_8011A3F8[D_8011A418] == -1) {
    D_8011A3F0 = 1;
}
}

// Returns the D_8011A420 layout index for a viewport.
s32 func_800A8380(s32 viewport)
{
    s32 base;

    if (D_80127670.local_2 == 0) {
        base = 1;
    } else {
        base = 7;
    }
    switch (D_80127670.local_0) {
        case 2:
            return base + viewport;
        case 3:
            if (base == 1)
                return viewport ? viewport + 4 : base;
            return viewport ? viewport * 2 + 2 : base;
        case 4:
            return viewport + 3;
        default:
            return 0;
    }
}

// Computes the screen rectangle of a layout from the half-size in D_80127670.
void func_800A8424(s32 layout, s32 *left, s32 *top, s32 *right, s32 *bottom)
{
    *left = ((s32 *) &D_80127670)[3] * D_8011A420[layout].x;
    if (D_8011A420[layout].x == 1)
        (*left)++;
    *top = ((s32 *) &D_80127670)[4] * D_8011A420[layout].y;
    if (D_8011A420[layout].y != 0)
        (*top)++;
    *right = ((s32 *) &D_80127670)[3] * D_8011A420[layout].z;
    if (D_8011A420[layout].z == 1)
        (*right)--;
    *bottom = ((s32 *) &D_80127670)[4] * D_8011A420[layout].w;
    if (D_8011A420[layout].w == 1)
        (*bottom)--;
}

// (Re)creates a viewport with the given layout.
void func_800A84EC(s32 viewport, u32 layout)
{
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    if (D_80127688[viewport].unk0 != 0)
        func_800158E4(D_80127688[viewport].unk0);
    func_800A8424(layout, &left, &top, &right, &bottom);
    D_80127688[viewport].unk0 = func_8001592C(left, top, right, bottom);
    D_80127688[viewport].unk8 = 40.0f;
    if (D_80127688[viewport].unk4 != 0) {
        func_80015CE8(D_80127688[viewport].unk0, D_80127688[viewport].unk4);

}
func_800C54CC(viewport, 40.0f, 1.0f);
}

// Rebuilds all active viewports and the full-screen one.
void func_800A85A8(void)
{
    u32 *entry;
    s32 i;

    entry = (u32 *) D_80127688;
    i = 0;
    do {
        if (*entry != 0) {
            func_800A84EC(i, func_800A8380(i));
        }

i += 1;
entry += 3;

}
while (i != 4)
    ;
func_800A84EC(4, 0);
}

void func_800A861C(void)
{
    s32 camera;
    u32 base;
    // Matching: the empty if with repeated tests is needed for the match.
    if ((!(u8 *) D_80127688 && !(u8 *) D_80127688) && !(u8 *) D_80127688) {
    }
    D_80127678[0] = 0;
    camera = func_800CA334();
    base = (u32) (u8 *) D_80127688;
    *(s32 *) (base + 0x34) = camera;
    func_800E42B4(camera);
    func_800A84EC(4, 0);
    func_800C5464();
    func_800A89BC(4);
}

int func_800A8670()
{
    s32 i;
    for (i = 0; i < 5; i++) {
        if (((T8670 *) D_80127688)[i].a != 0 && ((T8670 *) D_80127688)[i].b != 0) {
            func_800C54F0(i);
        }

}
}

void func_800A86D8(void)
{
    if (D_801276BC != 0) {
        D_801276BC = func_800CA384(D_801276BC);

}
}

void func_800A8710(void)
{
    s32 i;

    func_800CA364(*(s32 *) ((s8 *) (s32 *) D_80127688 + 0x34));
    *(s32 *) ((s8 *) (s32 *) D_80127688 + 0x34) = 0;
    for (i = 0; i < 5; i++) {
        if (D_80127688[i].unk0 != 0) {
            func_800158E4(D_80127688[i].unk0);
            D_80127688[i].unk0 = 0;
        }

}
}

// Adds a viewport if it does not exist yet.
int func_800A877C(s32 viewport)
{
    if (*(int *) (((char *) D_80127688) + viewport * 12) != 0) {
        return 1;
    }
    if (viewport >= (*((int *) &D_80127670))) {
        (*((int *) &D_80127670)) = viewport + 1;
        func_800A85A8();
    }
    func_800A84EC(viewport, func_800A8380(viewport));
    return 1;
}

// Removes a viewport; returns 0 if it does not exist.
s32 func_800A87FC(s32 viewport)
{
    s32 i;
    if (D_80127688[viewport].unk0 == 0)
        return 0;
    func_800158E4(D_80127688[viewport].unk0);
    D_80127688[viewport].unk0 = 0;
    D_80127688[viewport].unk4 = 0;
    if (viewport + 1 == D_80127670.local_0) {
        D_80127670.local_0 = 0;
        for (i = 0; i < 4; i++) {
            if (D_80127688[viewport].unk0 != 0)
                D_80127670.local_0++;
        }
        func_800A85A8();
    }
    if (D_80127670.local_0 == 0)
        func_800E42B4(D_801276BC);
    return 1;
}

// Binds a camera to a viewport; returns the previous camera.
s32 func_800A88C4(s32 viewport, s32 camera)
{
    s32 old_camera;
    if (((local_type *) D_80127688)[viewport].local_0 == 0)
        return 0;
    old_camera = ((local_type *) D_80127688)[viewport].local_1;
    ((local_type *) D_80127688)[viewport].local_1 = camera;
    func_80015CE8(((local_type *) D_80127688)[viewport].local_0, camera);
    if (viewport == D_80127674)
        func_800E42B4(((local_type *) D_80127688)[viewport].local_1);
    return old_camera;
}

// Unbinds the camera of a viewport and returns it.
s32 func_800A8948(s32 viewport)
{
    s32 camera;

    if (D_80127688[viewport].unk0 == 0) {
        return 0;
    }
    camera = D_80127688[viewport].unk4;
    D_80127688[viewport].unk4 = 0;
    return camera;
}

s32 func_800A8984(s32 viewport)
{
    return D_80127688[viewport].unk4;
}

s32 func_800A89A0(s32 viewport)
{
    return D_80127688[viewport].unk0;
}

// Makes a viewport the current one and activates its camera.
void func_800A89BC(s32 viewport)
{
    D_80127674 = viewport;
    func_800E42B4(D_80127688[viewport].unk4);
}

s32 func_800A89F8()
{
    return D_80127674;
}

void func_800A8A04(s32 viewport, s32 left, s32 top, s32 right, s32 bottom)
{
    func_80015CC0(D_80127688[viewport].unk0, left, top, right, bottom);
}

int func_800A8A44(s32 viewport, s32 left, s32 top, s32 right, s32 bottom)
{
    u32 layout;
    layout = func_800A8380(viewport);
    // Matching: the "| 0" is needed for the match.
    func_800A8424(layout | 0, left, top, right, bottom);
}

void func_800A8A88(s32 viewport, f32 unk_1)
{
    s32 camera;
    u8 *entry;
    entry = (viewport * 0xC) + (((u8 *) D_80127688));
    *((f32 *) (((s8 *) entry) + 8)) = unk_1;
    camera = *((s32 *) (((s8 *) entry) + 4));
    if (camera != 0) {
        func_800CA558(camera, unk_1, *((s32 *) (((s8 *) entry) + 4)));
    }
}

f32 func_800A8AD4(s32 viewport)
{
    return D_80127688[viewport].unk8;
}

void func_800A8AF0(s32 viewport)
{
    func_80015D14(D_80127688[viewport].unk0);
}

void func_800A8B24(s32 gfx, s32 unk_1)
{
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 handle;

    handle = *(s32 *) ((char *) ((s32 *) D_80127688) + (D_80127674 * 0xC));
    func_80015CC0(handle, &left, &top, &right, &bottom);
    func_800E7FB0(left, top, right, bottom);
    func_800E7EC0(gfx);
    func_800157EC(handle, gfx);
}

void func_800A8BA8(Gfx **gfx, s32 unk_1)
{
    D_80127674 = -1;
    func_800E7E70(gfx);
}

// Steps to the next active viewport; returns 0 when none are left.
s32 func_800A8BD4(gfx, start, unk_2)
s32 gfx;
s32 start;
s32 unk_2;
{
    if (start >= 0)
        D_80127670.local_1 = start - 1;
    if (D_80127670.local_1 >= 0 && D_80127688[D_80127670.local_1].unk4 != 0) {
        func_800C5668(D_80127670.local_1, gfx);
    }
    for (D_80127670.local_1++; D_80127670.local_1 < 4; D_80127670.local_1++) {
        if (D_80127688[D_80127670.local_1].unk0 != 0)
            break;
    }
    if (D_80127670.local_1 >= 4)
        return 0;
    func_800A89BC(D_80127670.local_1);
    func_800A8B24(gfx, unk_2);
    return 1;
}

void func_800A8CCC(s32 gfx, s32 unk_1)
{
    func_800A89BC(4);
    func_800A8B24(gfx, unk_1);
}

// Sets the screen size used for viewport layouts; rebuilds viewports on change.
void func_800A8D00(s32 width, s32 height)
{
    if ((width != (((s32 *) &D_80127670)[3] << 1)) ||
        (height != (((s32 *) &D_80127670)[4] << 1))) {
        ((s32 *) &D_80127670)[3] = width / 2;
        ((s32 *) &D_80127670)[4] = height / 2;
        func_800A85A8();
    }
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1E80A70.data.s) is defined
// here in C; values taken from the ROM.
s32 D_8011A3F0 = 0x0;
s32 D_8011A3F4 = 0x258;
s32 D_8011A3F8[8] = {0x2, 0x9, 0x1, 0x5, 0x0, 0x1, 0x6, -0x1};
s32 D_8011A418 = 0x0;
static u32 D_8011A418_rest[1] = {0x0};
Struct_8011A420 D_8011A420[10] = {0x0, 0x0, 0x2, 0x2, 0x0, 0x0, 0x2, 0x1, 0x0, 0x1,
                                  0x2, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1,
                                  0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0,
                                  0x1, 0x2, 0x1, 0x0, 0x1, 0x2, 0x0, 0x0, 0x0, 0x0};
