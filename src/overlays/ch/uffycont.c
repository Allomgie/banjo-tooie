// Chuffy's cab controls: the actor that opens the station selection menu, plus hooks that resolve
// the map the player arrives in when leaving the cab or the wagon.
#include "common.h"

typedef union {
    s32 word;
    s16 half[2];
} ChuffyControlEvent;
extern void _gcnewoption_entrypoint_0(void *);
extern void func_8010A828();
// Station table row: map, "Chuffy is here" flag, destination flag, then unlock flag (+6) and menu text id (+8).
typedef struct {
    s16 map;
    s16 here_flag;
    s16 dest_flag;
    s16 pad_6[2];
} ChuffyStationRecord;
extern ChuffyStationRecord D_80800B20_chchuffycont[];
extern ChuffyStationRecord D_80800B66_chchuffycont[];
typedef struct {
    s16 unused0;
    s16 here_flag;
    s16 unused4;
    s16 prerequisite;
    s16 unused8;
} ChuffyTravelRecord;
typedef struct {
    s16 map;
    s16 here_flag;
    u8 pad_4[6];
} ChuffyStop;
extern u8 D_8012762C;
extern s32 func_800EA05C(void);
extern s32 func_800DA298(s32);
extern void func_800A7A5C(void);
extern s32 _gcsectionDll_entrypoint_4(s32);
extern void func_800A8230(void);
extern void func_800DA3B8(s32, s32);
typedef struct {
    s16 map;
    s16 here_flag;
    s16 pad_4[3];
} TrainStop62;
extern int D_80800B78_chchuffycont[];
extern int D_80800B68_chchuffycont[];
extern int D_80800B84_chchuffycont[];
typedef struct {
    s16 map;
    s16 here_flag;
    s16 pad_4[3];
} ChuffEnt;
s32 func_8080046C_chchuffycont();

extern void *func_80100094(Actor *, u32);
extern void _gcnewoption_entrypoint_35();
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern void _gcnewoption_entrypoint_40(void *, s32, s32, s32, f32, f32);
extern void _gcnewoption_entrypoint_42(void *, f32);
extern void _gcnewoption_entrypoint_10();
extern void _gcnewoption_entrypoint_11();
extern void _gcnewoption_entrypoint_4();
extern void _gcnewoption_entrypoint_8();
extern void _gcnewoption_entrypoint_9();
extern void _subaddiedialog_entrypoint_11();
extern void func_80090708();
extern void func_80102424();
void func_80800494_chchuffycont();
void func_80800620_chchuffycont();
int func_808006A4_chchuffycont();
s32 func_8080070C_chchuffycont();
void func_80800A7C_chchuffycont();
extern void func_80105834(), func_80107C2C(), func_80800440_chchuffycont(),
    func_80800768_chchuffycont();

void func_80800000_chchuffycont(actor, state) Actor *actor;
s32 state;
{
    s32 station_count;
    void *menu;

    if (actor->unk70_10 == 5) {
        _gcnewoption_entrypoint_6(actor, 1);
        func_80090708(0);
        func_8010A828(actor, 2);
    }
    func_80102424(actor, state);
    switch (actor->unk70_10) {
        // Chuffy not usable yet (flag 0x86 not set).
        case 2:
            _subaddiedialog_entrypoint_11(actor->unk0, 0xF96, 0xE, &actor->position, 0x42);
            break;
        // No station reachable.
        case 3:
            _subaddiedialog_entrypoint_11(actor->unk0, 0xD80, 0xE, &actor->position, 0x42);
            break;
        // The ice station needs Chuffy's engine cooled.
        case 6:
            _subaddiedialog_entrypoint_11(actor->unk0, 0x12C5, 0xE, &actor->position, 0x42);
            break;
        // Open the station menu.
        case 5:
            station_count = func_8080070C_chchuffycont(actor);
            _gcnewoption_entrypoint_4(actor, 1, _gcnewoption_entrypoint_35, 0, 0x184B);
            menu = func_80100094(actor, 1);
            func_80090708(2);
            _gcnewoption_entrypoint_8(menu, station_count >= 6 ? 5 : station_count);
            _gcnewoption_entrypoint_9(menu, station_count);
            _gcnewoption_entrypoint_10(menu, 0);
            func_8080046C_chchuffycont(actor, menu);
            _gcnewoption_entrypoint_14(menu, 0, 1, 3, 4.0f);
            _gcnewoption_entrypoint_40(menu, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            _gcnewoption_entrypoint_42(menu, 0.1f);
            _gcnewoption_entrypoint_11(menu);
            func_8010A828(actor, 10);
    }
}

s32 func_808001F8_chchuffycont(Actor *actor, s32 msg, ChuffyControlEvent event)
{
    s32 menu;

    switch (msg) {
        case 0x91:
            actor->unk64_19 = 1;
            break;
        case 0x20:
            menu = func_80101080();
            switch (event.half[1]) {
                // Station chosen: travel there.
                case 3:
                    func_80800620_chchuffycont(actor, event.half[0]);
                    func_80800000_chchuffycont(actor, 1);
                    break;
                // Fill the menu with the reachable stations.
                case 0:
                    func_80800494_chchuffycont(actor, menu);
                    break;
                case 2:
                    func_80800000_chchuffycont(actor, 1);
            }
            break;
        case 0x2E:
            func_80800000_chchuffycont(actor, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808002C4_chchuffycont(Actor *actor)
{
    func_80800A7C_chchuffycont(actor);
    switch (actor->unk70_10) {
        case 1:
            if (!func_800DA298(0x66D) && !func_800DA298(0x86) &&
                func_8010CAC0(actor->position, 250)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0xFAC, 0xE, 0, 0x42);
                func_800DA544(0x66D);
            }
            if (actor->unk64_19 && _subaddiedialog_entrypoint_4(actor->position, 100, 0)) {
                if (!func_800DA298(0x86)) {
                    actor->unk74_30 = 0;
                    func_80800000_chchuffycont(actor, 2);
                } else if (func_8080070C_chchuffycont(actor) <= 0) {
                    actor->unk74_30 = 0;
                    func_80800000_chchuffycont(actor, 3);
                    break;
                } else
                    func_80800000_chchuffycont(actor, 5);
            }
            break;
        case 5:
            _gcnewoption_entrypoint_0(func_80100094(actor, 1));
            break;
    }
    if (actor->unk64_19)
        actor->unk64_19 = 0;
}

void func_80800440_chchuffycont(actor) u8 *actor;
{
    *(f32 *) (actor + 0x38) = 0.5f;
    func_8010A828(actor, 2);
}

s32 func_8080046C_chchuffycont(s32 actor, s32 menu)
{
    _gcnewoption_entrypoint_32(menu, 0x42);
}

void func_80800494_chchuffycont(actor, menu) s32 actor;
s32 menu;
{
    s32 i;
    s32 item;

    item = 0;
    i = 0;
    do {
        if (func_808006A4_chchuffycont(i) != 0) {
            _gcnewoption_entrypoint_12(menu, item, (s16) (i + 0xA));
            _gcnewoption_entrypoint_31(
                menu, item,
                *(s16 *) ((char *) ((s32 *) D_80800B20_chchuffycont) + (i * 0xA) + 8));
            item += 1;
        }
        i += 1;
    } while (i != 7);
}

void func_80800540_chchuffycont(Actor *actor, s32 station)
{
    ChuffyStationRecord *record;
    s32 i;

    record = &D_80800B20_chchuffycont[station];

    // The ice train station needs Chuffy's engine cooled (flag 0x171).
    if (record->map == 0x12A && !func_800DA298(0x171)) {
        func_80800000_chchuffycont(actor, 6);
        return;
    }

    func_800DA544(record->dest_flag);
    // Find the station where Chuffy is now.
    for (i = 0; i < 7; i++) {
        if (func_800DA298(D_80800B20_chchuffycont[i].here_flag))
            break;
    }
    record = &D_80800B20_chchuffycont[i];
    if (record->map == 0xEC)
        func_800DA544(0x6E7);
    _glcutDll_entrypoint_0();
    _glcutDll_entrypoint_7(record->map);
    _glcutDll_entrypoint_10(0xD0);
    _glcutDll_entrypoint_22(0x6F);
    _glcutDll_entrypoint_16();
}

// Travel to the Nth reachable station.
void func_80800620_chchuffycont(actor, selection) s32 actor;
s32 selection;
{
    s32 i;
    s32 count;
    count = 0;
    i = 0;
    // Matching: empty blocks steer IDO's register allocation.
    if (1) {
    }
    if (1) {
    }
    if (1) {
    }
    if (1) {
    }
    if (1) {
    }
    if (1) {
    }
loop_1:
    if (func_808006A4_chchuffycont(i) != 0) {
        if (count == selection) {
            func_80800540_chchuffycont(actor, i);
            return;
        }

        count += 1;
    }

    i += 1;

    if (i == 7) {
        return;
    }
    goto loop_1;
}

// Whether Chuffy can go to this station: unlocked and not already there.
int func_808006A4_chchuffycont(station)
s32 station;
{
    return (((ChuffyTravelRecord *) D_80800B20_chchuffycont)[station].prerequisite == -1 ||
            func_800DA298(
                ((ChuffyTravelRecord *) D_80800B20_chchuffycont)[station].prerequisite)) &&
           !func_800DA298(((ChuffyTravelRecord *) D_80800B20_chchuffycont)[station].here_flag);
}

// Number of reachable stations.
s32 func_8080070C_chchuffycont(actor) void *actor;
{
    s32 i;
    s32 count;
    // Matching: needed for the match.
    count = (count = 0);
    for (i = 0, count; i < 7; i++) {
        if (func_808006A4_chchuffycont(i)) {
            count++;
        }
    }

    return count;
}

void func_80800768_chchuffycont(actor, unk_0) s32 actor;
s32 unk_0;
{
    if (func_800EB854() == 3) {
        s32 menu = func_80100094(actor, 1);

        if (menu != 0) {
            _gcnewoption_entrypoint_1(menu, unk_0);
        }

    } else {
        func_80101870(actor, unk_0);
    }
}

// Section skip hook: map and exit when leaving the cab (to the station
// where Chuffy is) or a station (into the cab).
s32 chchuffycont_entrypoint_0(s32 *map, s32 *exit)
{
    s32 i;
    s32 j;
    s32 dest_section;
    s32 cur_map;

    // In the cab: leave at the station where Chuffy is.
    if (func_800EA05C() == 0xD0) {
        for (i = 0; i < 7; i++) {
            if (func_800DA298(((ChuffyStop *) D_80800B20_chchuffycont)[i].here_flag)) {
                break;
            }
        }
        *map = ((ChuffyStop *) D_80800B20_chchuffycont)[i].map;
        *exit = 2;
        if (func_800DA298(0x66B)) {
            func_800A7A5C();
        } else {
            dest_section = _gcsectionDll_entrypoint_4(*map);

            if (_gcsectionDll_entrypoint_4(0xD0) != dest_section) {
                func_800A8230();
            }
        }
        func_800DA3B8(0x66B, 0);
        return 1;
    }
    // At a station: enter the cab if Chuffy is here.
    cur_map = func_800EA05C();
    for (j = 0; j < 7; j++) {
        if (cur_map == ((ChuffyStop *) D_80800B20_chchuffycont)[j].map) {
            break;
        }
    }
    if (func_800DA298(((ChuffyStop *) D_80800B20_chchuffycont)[j].here_flag)) {
        *map = 0xD0;
        *exit = 1;
        if (_gcsectionDll_entrypoint_4(0xD0) != D_8012762C) {
            func_800A8230();
        }
        return 1;
    }
    return 0;
}

// Section skip hook: map and exit when leaving the wagon (map 0x121) or a station (into the wagon).
// Matching: the line breaks in this function are needed for the match.
s32 chchuffycont_entrypoint_1(s32 *map, s32 *exit)
{
    s32 cur_map;
    s32 result;
    TrainStop62 *stop;
    TrainStop62 *cur_stop;
    u8 *table_end;
    u8 *table_end2;
    s32 dest_section;

    cur_map = func_800EA05C();
    result = 0;
    if (cur_map == 0x121) {
        if (!func_800DA298(0x95)) {
            *map = 0xD7;
            *exit = 3;
        } else {
            stop = ((TrainStop62 *) D_80800B20_chchuffycont); table_end = ((u8 *) D_80800B66_chchuffycont);
            do {
                if (func_800DA298(stop->here_flag)) break;
                stop++;
            } while ((u8 *)stop != table_end);
            *map = stop->map;
            *exit = 3;
        }
        dest_section = _gcsectionDll_entrypoint_4(*map);
        if (_gcsectionDll_entrypoint_4(0x121) != dest_section) func_800A8230();
        result = 1;
    } else {
        cur_stop = ((TrainStop62 *) D_80800B20_chchuffycont); table_end2 = ((u8 *) D_80800B66_chchuffycont);
        do {
            if (cur_stop->map == cur_map) break;
            cur_stop++;
        } while ((u8 *)cur_stop != table_end2);
        if (func_800DA298(cur_stop->here_flag) || (cur_map == 0xD7 && !func_800DA298(0x95))) {
            *map = 0x121;
            *exit = 1;
            result = 1;
            if (_gcsectionDll_entrypoint_4(0x121) != D_8012762C) func_800A8230();
        }
    }
    return result;
}

void func_80800A7C_chchuffycont(actor) int actor;
{
    int *unk_0;
    int *unk_1;
    // Matching: the chained temporaries are needed for the match.
    unk_1 = (unk_0 = &D_80800B68_chchuffycont);
    _subaddieaudioloop_entrypoint_4(actor, &D_80800B78_chchuffycont, 1, unk_1);
}

int chchuffycont_entrypoint_2()
{
    return (int) &D_80800B84_chchuffycont;
}

// Pause menu hook: section of the map at Chuffy's station.
void chchuffycont_entrypoint_3(void)
{
    s32 i;
    for (i = 0; i < 7; i++) {
        if (func_800DA298(((ChuffEnt *) D_80800B20_chchuffycont)[i].here_flag)) {
            break;
        }
    }
    _gcsectionDll_entrypoint_4(((ChuffEnt *) D_80800B20_chchuffycont)[i].map);
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables point to functions of this file,
// and IDO schedules some of them differently unless the tables are in the same unit. Values are
// taken from the ROM. D_80800B66_chchuffycont is a linker symbol (D_80800B20_chchuffycont + 0x46)
// in undefined_syms.us.txt. D_80800B68, D_80800B78 and D_80800B84 are declared as int[].
ChuffyStationRecord D_80800B20_chchuffycont[7] = {
    0xD7,  0x4ED, 0x669, -0x1,  0x3F,  0xEC,  0x4EE, 0x66A, 0x96,  0x52,  0x155, 0x4F3,
    0x6CC, 0x403, 0x7D,  0x114, 0x4F0, 0x6AA, 0x164, 0x57,  0x102, 0x4EF, 0x6A9, 0x163,
    0xA3,  0x129, 0x4F2, 0x6BC, 0x1D0, 0xAA,  0x12A, 0x4F1, 0x6BB, 0x1CF, 0x47};
int D_80800B68_chchuffycont[4] = {0x1304E9, 0x164E20, 0x101F4, 0x13880000};
int D_80800B78_chchuffycont[3] = {0x0, 0x0, -0x3B448000};
int D_80800B84_chchuffycont[19] = {0x20602A6,
                                   0x9030001,
                                   0x0,
                                   (u32) func_808002C4_chchuffycont,
                                   (u32) func_80105834,
                                   (u32) func_80800768_chchuffycont,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0xA1804,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80800440_chchuffycont,
                                   (u32) func_80107C2C,
                                   -0x7FFFFBFE,
                                   (u32) func_808001F8_chchuffycont,
                                   0x0,
                                   0x0};
