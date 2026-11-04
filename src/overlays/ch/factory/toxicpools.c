// Probably the toxic water of Waste Disposal: a switch lowers the water over 8 s, a valve drops it
// further and plays the clean-water cutscene, and a hazard controller knocks the player back to
// the last safe spot on contact.
#include "common.h"

extern int D_80800940_chfactorytoxicpools[];
extern int D_80800988_chfactorytoxicpools[];
extern int D_808009D0_chfactorytoxicpools[];
typedef struct {
    s16 level;
    s16 state;
    f32 timer;
} ToxicPoolSwitchState;
extern void *func_80100094(Actor *, u32);
extern s32 func_800D9078(f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern s32 D_80800A18_chfactorytoxicpools[];
extern void func_80103110();
extern void func_8010A570(Actor *);
extern void _capod_entrypoint_13(void *, s32, s32, s32);
extern void func_800C4AF0(f32 *, s32 *);
extern s32 func_800BEA88(s32);
extern void _idworldmake_entrypoint_1(s32, s32, s32, s32);
extern s32 _chswitch_entrypoint_10(Actor *, s32, s32);
typedef struct {
    s16 pad_0;
    s16 state;
    f32 timer;
} ToxicPoolState;
typedef struct {
    s16 pad_0;
    s16 state;
} ToxicPoolInteraction;
extern u8 _chfactorytoxicpools_entrypoint_3[];
extern s32 D_80800A38_chfactorytoxicpools[];
extern s32 D_80800A74_chfactorytoxicpools[];
extern s32 D_80800AB0_chfactorytoxicpools[];
extern s32 D_80800AC8_chfactorytoxicpools[];
typedef struct ToxicPoolItem {
    s16 zone;
    s16 pad_2;
    f32 pos[3];
    f32 unk_10[3];
} ToxicPoolItem;
typedef struct ToxicPoolNodes {
    s16 unk_0;
    s16 count;
    ToxicPoolItem items[8];
} ToxicPoolNodes;
extern f32 func_800F5628(void *);
extern s32 func_800CC338(f32 *, s32, s32);
typedef struct {
    s16 sel;
    s16 cnt;
    s16 id;
    s16 pad_6;
    f32 src[3];
    f32 dst[2];
} TPEntry;
int func_80800270_chfactorytoxicpools();
void func_808004A4_chfactorytoxicpools();

int chfactorytoxicpools_entrypoint_0()
{
    return &D_80800940_chfactorytoxicpools;
}

int chfactorytoxicpools_entrypoint_1()
{
    return (int) &D_80800988_chfactorytoxicpools;
}

int *chfactorytoxicpools_entrypoint_2()
{
    return &D_808009D0_chfactorytoxicpools;
}

// Init of the toxic water switch (flag 0x18E).
void func_80800024_chfactorytoxicpools(s32 actor)
{
    u8 *data;
    s32 switch_on;

    data = func_80100094(actor, 1);
    switch_on = func_800DA298(0x18E);
    if (_chswitch_entrypoint_7(actor, 0x18E) != 0) {
        func_80103110(actor, 0, switch_on);
    }
    *(f32 *) (data + 4) = 8.0f;
    if (switch_on != 0) {
        *(s16 *) (data + 0) = 0x384;
    } else {
        *(s16 *) (data + 0) = 0;
    }
    if (switch_on != 0) {
        *(s16 *) (data + 2) = 2;
    } else {
        *(s16 *) (data + 2) = 0;
    }
    if (switch_on != 0) {
        func_8010A570(actor);
    }
}

// Update of the 0x18E switch: lowers the toxic water mesh over 8 s.
void func_808000D0_chfactorytoxicpools(Actor *actor)
{
    ToxicPoolSwitchState *sw;
    s32 finished;

    sw = func_80100094(actor, 1);
    switch (sw->state) {
        case 0:
            _chswitch_entrypoint_6(actor);
            break;
        case 1:
            finished = func_800D9078(&sw->timer);
            sw->level = (s32) func_800F12D4(sw->timer, 0.0f, 8.0f, 900.0f, 0.0f);
            if (finished) {
                sw->state = 2;
                func_80103110(actor, 0);
            }
    }
    func_80800270_chfactorytoxicpools(actor);
}

s32 func_80800190_chfactorytoxicpools(Actor *actor, s32 event, s32 param_2)
{
    s16 *data;

    switch (event) {
        case 7:
            data = func_80100094(actor, 1);
            func_80103110(actor, 1);
            func_8010A570(actor);
            data[1] = 1;
            _capod_entrypoint_13(actor->unk0, 0, 0, 0x10);
            func_800C4AF0(actor->position, &D_80800A18_chfactorytoxicpools);
            break;
        case 0x95:
            _idworldmake_entrypoint_1(func_800BEA88(1), 0x659, 1, 1);
            func_80800270_chfactorytoxicpools(actor);
        default:
            return _chswitch_entrypoint_10(actor, event, param_2);
    }
    return 1;
}

int func_80800270_chfactorytoxicpools(actor)
s32 actor;
{
    s16 *data;

    data = func_80100094(actor, 1);
    _idwibble_entrypoint_5(_idworld_entrypoint_4(func_800BEA88(1), 1), *data);
}

// Init of the second switch/valve (flag 0x166).
void func_808002B8_chfactorytoxicpools(s32 actor)
{
    u8 *data;
    s32 switch_on;

    data = func_80100094(actor, 1);
    switch_on = func_800DA298(0x166);
    _chswitch_entrypoint_14(actor, 0x166);
    *(f32 *) (data + 4) = 1.0f;
    if (switch_on != 0) {
        *(s16 *) (data + 2) = 2;
    } else {
        *(s16 *) (data + 2) = 0;
    }
    if (switch_on != 0) {
        func_8010A570(actor);
    }
    func_80105010(actor);
}

void func_80800338_chfactorytoxicpools(Actor *actor)
{
    ToxicPoolState *data;
    data = func_80100094(actor, 1);
    switch (data->state) {
        case 0:
            _chswitch_entrypoint_13(actor);
            break;
        case 1:
            if (func_800D9078(&data->timer)) {
                func_80103110(actor, 0);
                data->state = 2;
                func_800F82D4(func_800F54E4(), 0);
                _capod_entrypoint_13(actor->unk0, 0, 0x12, 0x2030);
            }
    }
}

// Valve events; event 11 starts the clean-water cutscene.
s32 func_808003DC_chfactorytoxicpools(Actor *actor, s32 event, s32 param_2)
{
    ToxicPoolInteraction *data;

    switch (event) {
        case 0x95:
            func_808004A4_chfactorytoxicpools(actor);
            break;
        case 7:
            data = func_80100094(actor, 1);
            func_80103110(actor, 1);
            func_8010A570(actor);
            data->state = 1;
            func_800F8300(func_800F54E4(), 2, actor->position);
            break;
        case 11:
            _capod_entrypoint_14();
            _glcutDll_entrypoint_6(0x1A7, 0x2A);
            return 4;
        default:
            return 0;
    }
    return 1;
}

void func_808004A4_chfactorytoxicpools(args) s32 args[3];
{
    s32 world;
    world = func_800BEA88(1);
    if (world != 0) {
        _idworldmake_entrypoint_1(world, 0x7D, 2, 1);
        _glid_entrypoint_0(world, 2, &_chfactorytoxicpools_entrypoint_3, args[0]);
    }
}

// Vertex callback: drops the water by 300 units once flag 0x166 is set.
void chfactorytoxicpools_entrypoint_3(void *param_0, Vtx *src, Vtx *dst, s32 count)
{
    s32 offset;
    Vtx *end;
    if (func_800DA298(0x166))
        offset = -300;
    else
        offset = 0;
    end = src + count;
    for (; src < end; src++, dst++) {
        dst->v.ob[1] = src->v.ob[1] + offset;
    }
}

// Hazard controller init: records the safe position of each zone marker (0x154).
void func_8080057C_chfactorytoxicpools(Actor *actor)
{
    ToxicPoolNodes *nodes;
    void *markers[8];
    s32 i;
    f32 pos[3];

    nodes = func_80100094(actor, 0);
    nodes->count = _gccubesearch_entrypoint_9(0x154, markers, 8);
    for (i = 0; i < nodes->count; i++) {
        func_800EE88C(pos, markers[i]);
        nodes->items[i].zone = func_800CBC3C(pos);
        func_800EFD24(nodes->items[i].unk_10);
        func_800EE7F8(nodes->items[i].pos, pos);
    }
    nodes->unk_0 = -1;
    actor->unk58 = 1.2f;
}

void func_80800898_chfactorytoxicpools();

// Hazard controller: knocks the player back to the last safe spot on toxic water.
void func_80800670_chfactorytoxicpools(Actor *actor)
{
    s32 unk_0;
    s32 unk_1;
    s32 i;
    f32 floor_y;
    f32 pos[3];
    TPEntry *entries;
    void *player;
    s32 has_floor;

    entries = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            player = func_800F54E4();
            if (func_800F6A38(player)) {
                unk_0 = func_800F5C94(player);
                unk_1 = func_800F5D18(player);
                if (unk_0 != 12 && unk_0 != 14 && unk_1 && func_800D9078(&actor->unk58)) {
                    func_800F7D90(player, 0x52, entries[entries->sel].dst, 1);
                    func_80101FDC(actor, 2);
                    func_80800898_chfactorytoxicpools(actor);
                    actor->unk58 = 2.5f;
                }
                return;
            }
            func_800F5A00(player, pos);
            for (i = 0; i < entries->cnt; i++) {
                floor_y = func_800F5628(player);
                has_floor = floor_y != -18000.0f;
                if (has_floor) {
                    pos[1] = floor_y;
                } else {
                    pos[1] = entries[i].dst[1];
                }
                if (func_800CC338(pos, entries[i].id, 0) != -1) {
                    if (!has_floor) {
                        func_800EE7F8(entries[i].dst, entries[i].src);
                    } else {
                        func_800EE7F8(entries[i].dst, pos);
                    }
                    entries->sel = i;
                }
            }
            actor->unk58 = 1.2f;
            return;
        case 2:
            if (func_800D9078(&actor->unk58) && func_800F5578(func_800F54E4()) > 0) {
                func_80101FDC(actor, 1);
                actor->unk58 = 1.2f;
            }
    }
}

void func_80800898_chfactorytoxicpools(s32 actor)
{
    f32 puff_pos[3];
    f32 player_pos[3];

    func_800F5A00(func_800F54E4(), player_pos);
    func_800BBCB8(player_pos, NULL, 0x3F800000, 8, &D_80800A38_chfactorytoxicpools);
    func_800EE780(puff_pos, player_pos, &D_80800AC8_chfactorytoxicpools);
    func_800BBCB8(player_pos, puff_pos, 0x3F800000, 4, &D_80800A74_chfactorytoxicpools);
    _subaddieaudioquick_entrypoint_2(actor, player_pos, &D_80800AB0_chfactorytoxicpools);
}

// TU-NOTE: the .data tables below are defined in this file because IDO's assembler
// schedules the functions they point to differently otherwise. Values come from the ROM.
extern u8 D_8011A270[];
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
extern void _chswitch_entrypoint_0();
extern void func_8010A730();
int D_80800940_chfactorytoxicpools[18] = {0x34303C4,
                                          0x7C10001,
                                          (u32) &D_8011A270,
                                          (u32) func_808000D0_chfactorytoxicpools,
                                          (u32) func_80102EC0,
                                          (u32) func_80101870,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x40000808,
                                          0x0,
                                          0x0,
                                          0x8,
                                          (u32) func_80800024_chfactorytoxicpools,
                                          (u32) func_80107C2C,
                                          -0x7FF7D3EE,
                                          (u32) func_80800190_chfactorytoxicpools,
                                          0x0};
int D_80800988_chfactorytoxicpools[18] = {0x34303C5,
                                          0x7490001,
                                          -0x7FEE5D68,
                                          (u32) func_80800338_chfactorytoxicpools,
                                          (u32) func_80102EC0,
                                          (u32) func_80101870,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x80C,
                                          0x0,
                                          (u32) _chswitch_entrypoint_0,
                                          0x8,
                                          (u32) func_808002B8_chfactorytoxicpools,
                                          (u32) func_80107C2C,
                                          -0x7FF7DBF0,
                                          (u32) func_808003DC_chfactorytoxicpools,
                                          0x0};
int D_808009D0_chfactorytoxicpools[18] = {0x340432,
                                          0x1,
                                          0x0,
                                          (u32) func_80800670_chfactorytoxicpools,
                                          (u32) func_80102EC0,
                                          (u32) func_8010A730,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x4,
                                          0x0,
                                          0x0,
                                          0xE40000,
                                          (u32) func_8080057C_chfactorytoxicpools,
                                          (u32) func_80107C2C,
                                          -0x7FFFD9FE,
                                          0x0,
                                          0x0};
s32 D_80800A18_chfactorytoxicpools[8] = {0x13056A, 0x18000A, 0xC0000C,  0x733,
                                         0xC0010C, 0x150033, 0x74C0080, 0x140000};
s32 D_80800A38_chfactorytoxicpools[15] = {0x1D095C, 0x2C0000, 0x1E0000, 0x3C,      0x1B,
                                          0xA0014,  0x220019, 0x33000C, 0x190015,  0x3300CC,
                                          0xB0014,  0x780014, -0x4FFD5, 0x1CC0233, 0x0};
s32 D_80800A74_chfactorytoxicpools[15] = {0x1D09DD, 0x1B002B,  0x46002D,    0x1D0030,  0xB0012,
                                          0x2D001E, 0x20,      -0x3900685B, 0x160200,  0x150033,
                                          0xB3002B, 0x2020268, 0x2200CC,    0x13301CC, 0x2330000};
s32 D_80800AB0_chfactorytoxicpools[6] = {0x1304DC, 0xD0100, 0x14C0015, 0x80, 0x660002, 0x0};
s32 D_80800AC8_chfactorytoxicpools[6] = {0x0, -0x3CFE0000, 0x0, 0x0, 0x0, 0x0};
