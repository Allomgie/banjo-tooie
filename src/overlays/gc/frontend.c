#include "common.h"

typedef struct {
    u8 pad_0;
    u8 count;
    s16 flag_base;
    u8 pad_4[8];
} FrontendTextSpan;
typedef struct {
    u8 first;
    u8 count;
    s16 flag_base;
    void *items;
    void *values;
} FrontEnt;
extern FrontEnt D_80800D80_gcfrontend[];
typedef struct {
    u8 pad_0[0xC];
    u8 unk_C;
    u8 pad_D[3];
} GfEnt;
typedef struct {
    u8 first;
    u8 pad_1;
    s16 flag_base;
    GfEnt *items;
    s32 values;
} FrontEnt2;
typedef struct {
    u8 first;
    u8 unused[3];
    u8 *items;
    s16 *values;
} FrontendTextRecord;
extern FrontendTextRecord D_80800DA4_gcfrontend;
extern void func_800D3CF8(s32);
extern void func_800D3D10(s32);
typedef struct {
    s32 location;
    s32 script;
    u8 pad_8[5];
    u8 unk_D;
    u8 pad_E[2];
} FrontendEntry;
extern FrontendEntry D_80800C9C_gcfrontend[];
extern void func_800DA544(s32);
typedef struct {
    u8 first;
    u8 count;
    u8 pad_2[10];
} FrR;
typedef struct {
    s16 item;
    s16 replacement;
    s16 level;
    s16 entrance;
} FrontendMapRecord;
extern FrontendMapRecord D_80800DB0_gcfrontend[16];
typedef struct {
    u16 type;
    s16 arg;
} FrontendCmd;
typedef struct {
    s32 count;
    FrontendCmd *cmds;
} FrontendScript;
extern FrontendScript D_808008FC_gcfrontend[];
extern void func_800D3A54(s32, s32);
extern void func_800D3A88(void);
extern void func_800D3AF0(s32);
extern void func_800D3A14(s32);
extern void func_800D3A20(s32);
extern s32 func_800DC298(f32);
u8 gcfrontend_entrypoint_4();
u8 gcfrontend_entrypoint_5();
void gcfrontend_entrypoint_9();
s32 func_80800450_gcfrontend();
void func_80800738_gcfrontend();

// Unlocks every entry of the last group (group 3).
void gcfrontend_entrypoint_0(void)
{
    s32 count;
    s32 first;
    s32 i;
    s32 index;

    func_800D3970();
    first = gcfrontend_entrypoint_5(3);
    count = gcfrontend_entrypoint_4(3);
    i = 0;
    if (count > 0) {
        index = first;
        do {
            gcfrontend_entrypoint_9(index);
            i += 1;
            index += 1;
        } while (i < count);
    }
}

// Returns 1 if any entry of the group is unlocked.
s32 gcfrontend_entrypoint_1(s32 group)
{
    s32 flag;
    s32 end_flag;
    FrontendTextSpan *info;
    info = &D_80800D80_gcfrontend[group];
    flag = info->flag_base;
    end_flag = info->count + flag;
    for (; flag < end_flag; flag++) {
        if (func_800DA298(flag)) {
            return 1;
        }
    }
    return 0;
}

// Returns 1 if any entry of groups 0-2 is unlocked.
int gcfrontend_entrypoint_2(void)
{
    return gcfrontend_entrypoint_1(0) != 0 || gcfrontend_entrypoint_1(1) != 0 ||
           gcfrontend_entrypoint_1(2) != 0;
}

// Returns the unlock flag of an entry of the current group.
s32 gcfrontend_entrypoint_3(s32 offset)
{
    FrontEnt *group = &((FrontEnt *) D_80800D80_gcfrontend)[func_80800450_gcfrontend()];
    return func_800DA298(group->flag_base + offset - group->first);
}

// Returns the entry count of a group.
u8 gcfrontend_entrypoint_4(group)
s32 group;
{
    return D_80800D80_gcfrontend[group].count;
}

// Returns the first entry index of a group.
u8 gcfrontend_entrypoint_5(group)
s32 group;
{
    return ((u8 *) D_80800D80_gcfrontend)[group * 12];
}

u8 gcfrontend_entrypoint_6(s32 item)
{
    FrontEnt2 *group = &((FrontEnt2 *) D_80800D80_gcfrontend)[func_80800450_gcfrontend()];
    return group->items[item - group->first].unk_C;
}

// Starts a replay item: runs its setup script and warps to its map.
void gcfrontend_entrypoint_7(s32 item, s32 param_1)
{
    s32 group_idx;
    s32 mode;
    s16 *dest;
    u8 *script;

    u8 *items;

    group_idx = func_80800450_gcfrontend();
    if (group_idx < 4) {
        script = NULL;
        func_800D3CF8(item);
        mode = 2;
        items = (&((FrontendTextRecord *) D_80800D80_gcfrontend)[group_idx])->items;
        item -= (&((FrontendTextRecord *) D_80800D80_gcfrontend)[group_idx])->first;
        if (group_idx != 2)
            script = items + item * 16 + 4;
        dest = (s16 *) (items + item * 16);
        if ((void *) &D_80800DA4_gcfrontend == &D_80800D80_gcfrontend[group_idx])
            mode = 3;
        func_800D3D10(param_1);
        func_80800738_gcfrontend(dest, script, 0, mode);
    }
}

void func_808002DC_gcfrontend(s32 item, s32 param_1)
{
    FrontendEntry *entry = &D_80800C9C_gcfrontend[item - 0xA0];
    func_80800738_gcfrontend(&entry->location, &entry->script, entry->unk_D, param_1);
}

s32 gcfrontend_entrypoint_8(s32 item, s32 param_1)
{
    if (param_1 != 0) {
        param_1 = 1;
    } else {
        param_1 = 0;
    }
    func_808002DC_gcfrontend(item, param_1);
}

// Unlocks the replay entry of an item (bosses and minigames call this).
void gcfrontend_entrypoint_9(item) s32 item;
{
    FrontEnt *group = &((FrontEnt *) D_80800D80_gcfrontend)[func_80800450_gcfrontend()];
    func_800DA544(group->flag_base + item - group->first);
}

s32 gcfrontend_entrypoint_10(void)
{
    func_800D3CF8(0);
    func_808002DC_gcfrontend(0xA0, -1);
}

// Returns to the replay menu after an item is finished.
s32 gcfrontend_entrypoint_11(void)
{
    gcfrontend_entrypoint_7(func_800D3D04(), 0);
}

s32 gcfrontend_entrypoint_12(void)
{
    func_800AA074();
    func_800AA00C();
    gcfrontend_entrypoint_10();
}

s32 gcfrontend_entrypoint_13(void)
{
    func_800D37D4();
    func_808002DC_gcfrontend(0xA6, -1);
}

// Returns the group an item index belongs to, or 4 if none.
s32 func_80800450_gcfrontend(index)
s32 index;
{
    s32 i;
    s32 end;
    for (i = 0; i < 4; i++) {
        end = ((FrR *) D_80800D80_gcfrontend)[i].first + ((FrR *) D_80800D80_gcfrontend)[i].count;

if (index >= ((FrR *) D_80800D80_gcfrontend)[i].first && index < end) {
    return i;
}

}
return 4;
}

// Runs the commands of a setup script (flags, abilities, transformation, random choice).
void func_80800520_gcfrontend(script) FrontendScript *script;
{
    s32 i;
    s16 arg;

    for (i = 0; i < script->count; i++) {
        arg = script->cmds[i].arg;

switch (script->cmds[i].type) {
    case 0:
        func_800D3A54(arg, 1);
        continue;
    case 1:
        func_800D3A88();
        continue;
    case 2:
        func_800D3AF0(arg);
        continue;
    case 3:
        func_800D3A14(arg);
        continue;
    case 4:
        func_800D3A20(arg);
        continue;
    case 5:
        func_80800520_gcfrontend(&D_808008FC_gcfrontend[arg]);
        continue;
    case 6:
        func_800D3A54(arg, 0);
        continue;
    case 7:
        if (func_800DC298(0.5f)) {
            func_800D3A20(arg);
        } else {
            func_800D3A20(arg + 1);
        }
        continue;
}

}
}

// Applies map overrides for the current item to the destination.
void func_8080068C_gcfrontend(s32 *map, s32 *entrance)
{
    s32 i;
    s16 value;
    s32 item;

    if (!func_800D3D1C()) {
        item = func_800D3D04();
        for (i = 0; i < 16; i++) {

if (item == D_80800DB0_gcfrontend[i].item) {
    func_800D3A20(D_80800DB0_gcfrontend[i].replacement);
    value = D_80800DB0_gcfrontend[i].level;
    if (value) {
        *map = value;
    }
    value = D_80800DB0_gcfrontend[i].entrance;
    if (value) {
        *entrance = value;
    }
}

}
}
}

void func_80800738_gcfrontend(location, script, param_2, mode) u8 *location;
s32 script;
s32 param_2;
s32 mode;
{
    s32 entrance;
    s32 map;

    entrance = (s32) (*(s16 *) ((s8 *) (location) + (2)));
    map = (s32) (*(s16 *) ((s8 *) (location) + (0)));
    func_800D39A8();
    func_800D39DC(mode);
    if (script != 0) {
        func_800D3B24();
        func_80800520_gcfrontend(script);
        func_8080068C_gcfrontend(&map, &entrance);
    }
    if (param_2 == 0) {
        func_800EA334(0);
    }
    func_800A791C(map, entrance, 1);
}

s32 gcfrontend_entrypoint_14(s32 item)
{
    FrontendTextRecord *group;

    group = &D_80800D80_gcfrontend[func_80800450_gcfrontend()];
    return group->values[item - group->first];
}

extern u8 D_80046A88[];
u32 D_80800840_gcfrontend[3] = {0x10000, 0x60032, 0x50000};
u32 D_8080084C_gcfrontend[1] = {0x30008};
u32 D_80800850_gcfrontend[7] = {0x50002, 0x40057, 0x400E9, 0x400E8, 0x4002B, 0x4002C, 0x4002F};
u32 D_8080086C_gcfrontend[2] = {0x50002, 0x3000C};
u32 D_80800874_gcfrontend[2] = {0x50002, 0x30006};
u32 D_8080087C_gcfrontend[2] = {0x50003, 0x30009};
u32 D_80800884_gcfrontend[1] = {0x3000B};
u32 D_80800888_gcfrontend[3] = {0x50002, 0x60028, 0x3000B};
u32 D_80800894_gcfrontend[2] = {0x50002, 0x40057};
u32 D_8080089C_gcfrontend[6] = {0x400B3, 0x40094, 0x400EB, 0x400EA, 0x400EC, 0x400B2};
u32 D_808008B4_gcfrontend[2] = {0x50002, 0x70582};
u32 D_808008BC_gcfrontend[3] = {0x50002, 0x40582, 0x40583};
u32 D_808008C8_gcfrontend[3] = {0x50002, 0x60012, 0x60006};
u32 D_808008D4_gcfrontend[3] = {0x3000B, 0x60028, 0x60006};
u32 D_808008E0_gcfrontend[7] = {0x20040, 0x20041, 0x20042, 0x20043, 0x20044, 0x20046, 0x20047};
FrontendScript D_808008FC_gcfrontend[4] = {
    0x7, (void *) &D_808008E0_gcfrontend, 0x2, (void *) &D_8080087C_gcfrontend,
    0x3, (void *) &D_80800840_gcfrontend, 0x7, (void *) &D_80800850_gcfrontend};
u32 D_8080091C_gcfrontend[24] = {0xA10000,  0x3, (u32) &D_80800840_gcfrontend, 0x10000,
                                 0x18E0000, 0x3, (u32) &D_80800840_gcfrontend, 0x10000,
                                 0x1940000, 0x3, (u32) &D_80800840_gcfrontend, 0x10000,
                                 0x1910000, 0x3, (u32) &D_80800840_gcfrontend, 0x10000,
                                 0x19C0000, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x19D0000, 0x3, (u32) &D_80800840_gcfrontend, 0x0};
u32 D_8080097C_gcfrontend[52] = {0x1410003, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x15B0003, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x15E0003, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x17A0001, 0x2, (u32) &D_8080087C_gcfrontend, 0x0,
                                 0xD10001,  0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0xF90002,  0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0xFC0001,  0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x1130004, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x1100002, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x12C0002, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x12B0002, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x13F0002, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x15D0006, 0x7, (u32) &D_80800850_gcfrontend, 0x0};
u32 D_80800A4C_gcfrontend[92] = {0xC60001,  0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0xC80001,  0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0xC90001,  0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0xDC0001,  0x2, (u32) &D_8080087C_gcfrontend, 0x0,
                                 0xDE0001,  0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0xDF0001,  0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0xE00001,  0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0xE50001,  0x1, (u32) &D_80800884_gcfrontend, 0x0,
                                 0xE40001,  0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x1240008, 0x6, (u32) &D_8080089C_gcfrontend, 0x0,
                                 0x1810001, 0x2, (u32) &D_8080086C_gcfrontend, 0x0,
                                 0x1230001, 0x2, (u32) &D_80800894_gcfrontend, 0x0,
                                 0x1620001, 0x2, (u32) &D_8080087C_gcfrontend, 0x0,
                                 0x10A0001, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x12E0001, 0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0x12F0001, 0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0x1300001, 0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0x13D0002, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x1370003, 0x3, (u32) &D_80800888_gcfrontend, 0x0,
                                 0x1390001, 0x2, (u32) &D_80800874_gcfrontend, 0x0,
                                 0x15F0001, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x15F0001, 0x2, (u32) &D_808008B4_gcfrontend, 0x0,
                                 0x15F0001, 0x3, (u32) &D_808008BC_gcfrontend, 0x0};
u32 D_80800BBC_gcfrontend[56] = {0x1660001, 0x2, (u32) &D_8080087C_gcfrontend, 0x1000000,
                                 0x17F0001, 0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0x1650001, 0x2, (u32) &D_8080087C_gcfrontend, 0x1000000,
                                 0x1860001, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x17C0001, 0x3, (u32) &D_808008D4_gcfrontend, 0x0,
                                 0x17B0001, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x1820001, 0x2, (u32) &D_8080086C_gcfrontend, 0x2000000,
                                 0x1830001, 0x2, (u32) &D_8080087C_gcfrontend, 0x0,
                                 0x1640001, 0x2, (u32) &D_8080087C_gcfrontend, 0x1000000,
                                 0x17D0001, 0x3, (u32) &D_808008C8_gcfrontend, 0x0,
                                 0x1800001, 0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0x1850001, 0x3, (u32) &D_80800888_gcfrontend, 0x0,
                                 0x1880001, 0x2, (u32) &D_80800874_gcfrontend, 0x2000000,
                                 0x1890001, 0x3, (u32) &D_80800840_gcfrontend, 0x3000000};
FrontendEntry D_80800C9C_gcfrontend[7] = {
    0x1580000, 0x0, 0x0, 0x0, 0x0, 0x0,       0x0, 0x0, 0x0, 0x0, 0xA10000,  0x0, 0x0, 0x0, 0x0,
    0x0,       0x0, 0x0, 0x0, 0x0, 0xAF0004,  0x0, 0x0, 0x0, 0x0, 0x0,       0x0, 0x0, 0x0, 0x0,
    0x1420003, 0x0, 0x0, 0x0, 0x0, 0x0,       0x0, 0x0, 0x0, 0x0, 0x1420001, 0x0, 0x0, 0x0, 0x0,
    0x0,       0x0, 0x0, 0x0, 0x0, 0x1940000, 0x0, 0x0, 0x0, 0x0, 0x0,       0x0, 0x0, 0x0, 0x0,
    0x18B0000, 0x0, 0x0, 0x0, 0x0, 0x0,       0x0, 0x0, 0x0, 0x0};
u32 D_80800D0C_gcfrontend[7] = {0xAB00AB, 0xAB00B2, 0x42003A, 0xB40057,
                                0xB50075, 0x760077, 0x220000};
u32 D_80800D28_gcfrontend[7] = {0xB20060, 0x3F0078, 0xD000C, 0x300B3, 0xA300A3, 0x60006A, 0x990022};
u32 D_80800D44_gcfrontend[12] = {0x600060, 0x60003F, 0x780078, 0x78000D, 0xC0041,  0x300B3,
                                 0xA300A3, 0x600060, 0x600022, 0x6A0099, 0x220022, 0x220000};
u32 D_80800D74_gcfrontend[3] = {0xC00AE, 0xF0022, 0x6F000D};
FrontEnt D_80800D80_gcfrontend[1] = {0x60, 0x17, 0xBE3, (void *) &D_80800A4C_gcfrontend,
                                     (void *) &D_80800D44_gcfrontend};
u32 D_80800D8C_gcfrontend[3] = {0x200D0BC8, (u32) &D_8080097C_gcfrontend,
                                (u32) &D_80800D0C_gcfrontend};
u32 D_80800D98_gcfrontend[3] = {(u32) ((u8 *) D_80046A88 + 0x1A172), (u32) &D_8080091C_gcfrontend,
                                (u32) &D_80800D74_gcfrontend};
FrontendTextRecord D_80800DA4_gcfrontend = {
    0x40, 0xE, 0xB, 0xD5, (void *) &D_80800BBC_gcfrontend, (void *) &D_80800D28_gcfrontend};
FrontendMapRecord D_80800DB0_gcfrontend[16] = {
    0x20, 0xC1,  0x0,   0x0, 0x21, 0x1BA, 0x0, 0x0, 0x22, 0xB7,  0x0, 0x0, 0x23, 0x88,  0x0, 0x0,
    0x24, 0x179, 0x0,   0x0, 0x25, 0x17F, 0x0, 0x0, 0x26, 0x1AF, 0x0, 0x0, 0x27, 0x172, 0x0, 0x0,
    0x28, 0x174, 0x0,   0x0, 0x29, 0x1D3, 0x0, 0x0, 0x2A, 0x1D4, 0x0, 0x0, 0x2B, 0x408, 0x0, 0x0,
    0x2C, 0x44,  0x19A, 0x1, 0x68, 0x1AE, 0x0, 0x0, 0x69, 0x418, 0x0, 0x0, 0x6B, 0x370, 0x0, 0x0};

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
