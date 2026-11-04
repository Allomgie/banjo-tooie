#include "common.h"

extern void func_80102FDC(f32 *, f32);
extern s32 D_80800730_chtimetable;
extern s32 D_80800744_chtimetable;
extern s32 D_80800758_chtimetable;
extern s32 D_8080076C_chtimetable[];
// Station row: map, "Chuffy is here" flag, dialog id, destination flag, unlock flag.
typedef struct TimetableEntry {
    s32 words[5];
} TimetableEntry;
extern s32 D_8080073C_chtimetable[];
extern int D_80800738_chtimetable[];
extern s32 D_8080080C_chtimetable[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int D_808007CC_chtimetable[];
extern s32 _gccubesearch_entrypoint_1();
extern void _gspropctrl_entrypoint_11(s32, f32 *);
extern u8 D_808007BC_chtimetable[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);

// Get the position of a track trigger marker near the actor; y and z are fixed.
void func_80800000_chtimetable(actor, index, pos) u8 *actor;
s32 index;
f32 *pos;
{
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(index + 0x51F, actor + 4), pos);
    pos[2] = -1100.0f;
    pos[1] = -50.0f;
}

void func_80800058_chtimetable(f32 *actor)
{
    func_80102FDC(actor, actor[14] * 0.75f);
    func_80800000_chtimetable(actor, 0, actor + 10);
    func_80800000_chtimetable(actor, 1, actor + 6);
}

// Station table index for a map, or -1.
s32 func_808000B0_chtimetable(map)
s32 map;
{
    s8 *base;
    s32 index;

if (map == D_80800730_chtimetable) {
    return 0;
}

if (map == D_80800744_chtimetable) {
    return 1;
}

// Remaining rows, four per iteration.
base = &D_8080076C_chtimetable;
index = 3;

if (map == D_80800758_chtimetable) {
    return 2;
}

loop_7 : if (map == *(s32 *) ((s8 *) base + 0))
{
    return index;
}

if (map == *(s32 *) ((s8 *) base + 0x14)) {
    return index + 1;
}

if (map == *(s32 *) ((s8 *) base + 0x28)) {
    return index + 2;
}

if (map == *(s32 *) ((s8 *) base + 0x3C)) {
    return index + 3;
}

index += 4;
base += 0x50;

if (index == 0xB) {
    return -1;
}

goto loop_7;
}

// Whether the train can be called to this station.
s32 func_8080016C_chtimetable(s32 actor, s32 chuffy_map, s32 map)
{
    s32 index;

if (!func_800DA298(0x86)) {
    return 0;
}

if (map == 0x12A && !func_800DA298(0x171)) {
    return 0;
}

index = func_808000B0_chtimetable(map);

if (((TimetableEntry *) &D_80800730_chtimetable)[index].words[4] != -1) {
    if (!func_800DA298(((TimetableEntry *) &D_80800730_chtimetable)[index].words[4])) {
        return 0;
    }
}

if (func_800DA298(((TimetableEntry *) &D_80800730_chtimetable)[index].words[1])) {
    return 0;
}

return 1;
}

// Set the destination flag and start the arrival cutscene.
void func_8080025C_chtimetable(s32 actor, s32 chuffy_map, s32 map)
{
    s32 index = func_808000B0_chtimetable(map);
    func_800DA544(*(s32 *)((u8 *)D_8080073C_chtimetable + index * 20));
    func_800DA544(0x6B7);
    _glcutDll_entrypoint_0();
    _glcutDll_entrypoint_7(chuffy_map);
    _glcutDll_entrypoint_10(map);
    _glcutDll_entrypoint_22(0x72);
    _glcutDll_entrypoint_16();
}

// Dialog id of the current station.
int func_808002D4_chtimetable()
{
    // Matching: the redundant masks and the temporary are needed for the match.
    int scaled;
    int idx = func_808000B0_chtimetable();
    scaled = idx;
    scaled = (scaled * 5) & 0xFFFFFFFFFFFFFFFF;
    idx = (scaled & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF;
    return D_80800738_chtimetable[(((idx & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF];
}

// Map where Chuffy is now, or -1.
// Matching: the line breaks in this function are needed for the match.
s32 func_80800308_chtimetable(void)
{
    s32 *row;
    row = &D_80800730_chtimetable; loop_1: if (func_800DA298(*((s32 *) (((s8 *) row) + 4))) != 0) {
        return *((s32 *) (((s8 *) row) + 0));
    }

    row += 5;
    if (row == (D_8080080C_chtimetable))
    {
        return -1;

}
goto loop_1;
}

// Speak at the board; picks a dialog from Chuffy's state if none is given.
int func_80800364_chtimetable(Actor *actor, s32 dialog_id, u32 flags)
{
    s32 chuffy_map;
    s32 map;
    flags |= 6;
    if (!dialog_id) {
        if (func_800DA298(0x95) != 0) {
            chuffy_map = func_80800308_chtimetable();
            map = func_800EA05C();
            if (chuffy_map == map) {
                dialog_id = 0xCF4;
            } else {
                dialog_id = func_808002D4_chtimetable(chuffy_map);
            }
        }

else
{
    dialog_id = 0xCF3;
}
}
_subaddiedialog_entrypoint_11(*((s32 **) (((char *) actor) + 0x0)), dialog_id, flags,
                              (Actor *) (((char *) actor) + 0x4), 0x42);
actor->unk74_30 = 1;
return 1;
}

// Speak when the player steps onto the tracks in front of the board.
void func_80800404_chtimetable(Actor *actor)
{
    f32 player_pos[3];
    f32 box_min[3];
    f32 box_max[3];
    if (!actor->unk74_30) {
        func_8010D254(player_pos);
        func_800EFA4C(box_min, -500.0f, 0.0f, -700.0f);
        func_800EFA4C(box_max, 0.0f, 1500.0f, 700.0f);
        func_800EF04C(box_min, (f32 *) &actor->actorData[4]);
        func_800EF04C(box_max, (f32 *) &actor->actorData[4]);

if (func_800EFED0(box_min, box_max, player_pos)) {
    if (!actor->unk64_20) {
        func_80800364_chtimetable(actor, 0xD07, 1);
        actor->unk64_20 = 1;
    }
} else
    actor->unk64_20 = 0;

func_800EFA4C(box_min, 0.0f, 0.0f, -700.0f);
func_800EFA4C(box_max, 500.0f, 1500.0f, 700.0f);
func_800EF04C(box_min, (f32 *) actor->actorData);
func_800EF04C(box_max, (f32 *) actor->actorData);

if (func_800EFED0(box_min, box_max, player_pos)) {
    if (!actor->unk64_19) {
        func_80800364_chtimetable(actor, 0xD07, 1);
        actor->unk64_19 = 1;
    }
} else
    actor->unk64_19 = 0;

}
if (actor->unk70_10 == 1 && _subaddiedialog_entrypoint_5(actor->position, 250, 60, 0)) {
    func_80800364_chtimetable(actor, 0, 9);
}
}

s32 func_808005B8_chtimetable(Actor *actor, s32 msg, s32 data)
{
    switch (msg) {
        case 0x2E:
            actor->unk74_30 = 0;

switch (((s16 *) &data)[0]) {
    // Offered the train: on yes, start the cutscene.
    case 0xD06:
        if (((s16 *) &data)[1] == 1) {
            func_8080025C_chtimetable(actor, func_80800308_chtimetable(), func_800EA05C());
        }
        break;
    // Station dialog done: offer to call the train if possible.
    case 0xCF5:
    case 0xCF6:
    case 0xCF7:
    case 0xCF8:
    case 0xCF9:
    case 0xCFA:
    case 0xCFB:
        if (func_8080016C_chtimetable(actor, func_80800308_chtimetable(), func_800EA05C())) {
            func_80800364_chtimetable(actor, 0xD06, 0x48);
            return 1;
        }
    case 0xCF4:
        func_800C0850();
}

break;
case 0x52:
    _gcdialogcamera_entrypoint_3(D_808007BC_chtimetable, actor->scale);
    return 1;
default:
    return 0;
    }
    return 1;
    }

    int chtimetable_entrypoint_0()
    {
        return (int) D_808007CC_chtimetable;
    }

    // TU-NOTE: the .data of this overlay is defined here in C. Its tables point to functions of this file,
    // and IDO schedules some of them differently unless the tables are in the same unit. Values are
    // taken from the ROM. D_808007CC_chtimetable and D_8080080C_chtimetable are declared as arrays
    // (uses written as NAME[0]).
    extern void func_80101870();
    extern void func_80107C2C();
    s32 D_80800730_chtimetable = 0xD7;
    static u32 D_80800730_chtimetable_rest[1] = {0x4ED};
    int D_80800738_chtimetable[1] = {0xCF5};
    s32 D_8080073C_chtimetable[2] = {0x669, -0x1};
    s32 D_80800744_chtimetable = 0xEC;
    static u32 D_80800744_chtimetable_rest[4] = {0x4EE, 0xCF6, 0x66A, 0x96};
    s32 D_80800758_chtimetable = 0x155;
    static u32 D_80800758_chtimetable_rest[4] = {0x4F3, 0xCFB, 0x6CC, 0x403};
    s32 D_8080076C_chtimetable[20] = {0x114, 0x4F0, 0xCF8, 0x6AA, 0x164, 0x102, 0x4EF,
                                      0xCF7, 0x6A9, 0x163, 0x129, 0x4F2, 0xCF9, 0x6BC,
                                      0x1D0, 0x12A, 0x4F1, 0xCFA, 0x6BB, 0x1CF};
    u8 D_808007BC_chtimetable[16] = {0x43, 0x82, 0x0, 0x0, 0x43, 0x2F, 0x0, 0x0,
                                     0x43, 0x2F, 0x0, 0x0, 0x42, 0x96, 0x0, 0x0};
    int D_808007CC_chtimetable[16] = {0x1580382,
                                      0x9310001,
                                      0x0,
                                      (u32) func_80800404_chtimetable,
                                      0x0,
                                      (u32) func_80101870,
                                      0x0,
                                      0x3FC00000,
                                      0x0,
                                      0x40000800,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800058_chtimetable,
                                      (u32) func_80107C2C,
                                      -0x7FFFDBAE};
    s32 D_8080080C_chtimetable[5] = {(u32) func_808005B8_chtimetable, 0x0, 0x0, 0x0, 0x0};
