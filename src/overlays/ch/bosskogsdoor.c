// Most likely the heavy sliding door in Grunty Industries leading to the basement: it opens
// via a cutscene once the electromagnet flag is set and remembers that it is open.
#include "common.h"

extern int D_80800918_chbosskogsdoor[];
typedef struct {
    u8 pad0[0x74];
    u8 unk74_7 : 1;
    u8 unk74_6 : 1;
    u8 unk74_0 : 6;
} BossKogsDoor;
extern int D_808009EC_chbosskogsdoor[];
extern s32 D_808008B0_chbosskogsdoor[];
extern u8 D_8080090C_chbosskogsdoor[];
extern u8 D_80800904_chbosskogsdoor[];
extern u8 D_808008F8_chbosskogsdoor[];
extern u8 D_808008E8_chbosskogsdoor[];
extern f32 func_800D8FF8(void);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 func_800D91EC(f32 *, f32);
extern f32 func_80103EF4(Actor *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_80800988_chbosskogsdoor[];
extern s32 D_80800994_chbosskogsdoor[];
extern s32 D_808009A0_chbosskogsdoor[];
extern s32 D_808009B0_chbosskogsdoor[];
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);

void func_80800000_chbosskogsdoor(Actor *door)
{
    if (func_800DA298(0x1B8)) {
        door->unk58 = door->unk74_7 / 10.0f;
        func_80101FDC(door, 9);
    } else
        door->unk58 = 0.0f;
    ((f32 *) door->actorData)[7] = door->position[1];
}

void func_80800090_chbosskogsdoor(Actor *door)
{
    switch (door->unk70_10) {
        case 1:
            break;
        case 2:
            if (func_800D90A4(&door->actorData[5])) {
                func_80101FDC(door, 3);
                func_800DA544(0x1B8);
            }
            break;
        case 3:
            _subaddieaudioloop_entrypoint_4(door, door->position, 1,
                                            D_8080090C_chbosskogsdoor);
            ((f32 *) door->actorData)[2] += 1200.0f * func_800D8FF8();
            if (((f32 *) door->actorData)[2] > -220.0f) {
                ((f32 *) door->actorData)[2] = -220.0f;
                func_80101FDC(door, 4);
            }
            func_800BBCB8((f32 *) door->actorData, (f32 *) door->actorData, 1.0f, 1,
                          &D_808008B0_chbosskogsdoor);
            break;
        case 4:
            _subaddieaudioloop_entrypoint_4(door, door->position, 1,
                                            D_8080090C_chbosskogsdoor);
            ((f32 *) door->actorData)[1] += 1200.0f * func_800D8FF8();
            if (((f32 *) door->actorData)[1] > 2480.0f) {
                ((f32 *) door->actorData)[1] = 2480.0f;
                func_80101FDC(door, 5);
            }
            func_800BBCB8((f32 *) door->actorData, (f32 *) door->actorData, 1.0f, 1,
                          &D_808008B0_chbosskogsdoor);
            break;
        case 5:
            _subaddieaudioloop_entrypoint_4(door, door->position, 1,
                                            D_8080090C_chbosskogsdoor);
            ((f32 *) door->actorData)[2] += 1200.0f * func_800D8FF8();
            if (((f32 *) door->actorData)[2] > 0.0f) {
                ((f32 *) door->actorData)[2] = 0.0f;
                func_80101FDC(door, 6);
            }
            func_800BBCB8((f32 *) door->actorData, (f32 *) door->actorData, 1.0f, 1,
                          &D_808008B0_chbosskogsdoor);
            break;
        case 6:
            _subaddieaudioloop_entrypoint_4(door, door->position, 1,
                                            D_8080090C_chbosskogsdoor);
            ((f32 *) door->actorData)[1] -= 1200.0f * func_800D8FF8();
            if (((f32 *) door->actorData)[1] < 2204.0f) {
                func_80101FDC(door, 7);
                _subaddieaudioquick_entrypoint_2(door, door->position,
                                                 D_80800904_chbosskogsdoor);
                _subaddieaudioloop_entrypoint_2(door);
            }
            func_800BBCB8((f32 *) door->actorData, (f32 *) door->actorData, 1.0f, 4,
                          &D_808008B0_chbosskogsdoor);
            break;
        case 7:
            if (func_800D91EC(&door->unk58, (f32) door->unk74_7 / 10.0f)) {
                func_80101FDC(door, 8);
                _subaddieaudioloop_entrypoint_2(door);
                _subaddieaudioquick_entrypoint_2(door, door->position,
                                                 D_808008F8_chbosskogsdoor);
            } else {
                _subaddieaudioloop_entrypoint_4(door, door->position, 1,
                                                D_808008E8_chbosskogsdoor);
            }
            break;
        case 9:
            func_80103110(door, 0);
    }
    door->position[1] = ((f32 *) door->actorData)[7] +
                           func_800F10B4(door->unk58, 0.0f, (f32) door->unk74_7 / 10.0f, 0.0f,
                                         func_80103EF4(door));
}

s32 func_80800458_chbosskogsdoor(u8 *actor, s32 event, s32 arg)
{
    if (event == 0x49) {
        if (arg == 0x40) {
            _capod_entrypoint_13(*(s32 *) actor, 0, 1, 0x930);
            func_80101FDC(actor, 2);
            func_800EFA4C(actor + 0x18, -7472.0f, 2405.0f, -1.24e+03f);
            *(f32 *) (actor + 0x2C) = 5.0f;
            return 1;
        }
        return 0;
    }
    return 0;
}

int *chbosskogsdoor_entrypoint_0()
{
    return &D_80800918_chbosskogsdoor;
}

void func_808004F4_chbosskogsdoor(BossKogsDoor *door)
{
    if (func_800DA298(0x1B8)) {
        func_80102424(door, 4);
        door->unk74_6 = 1;
    } else {
        func_80102424(door, 1);
    }
}

void func_80800544_chbosskogsdoor(Actor *door)
{
    f32 dust_pos[3];

    switch (door->unk70_10) {
        case 1:
            if (door->unk64_20) {
                func_80102424(door, 2);
                _subaddieaudioquick_entrypoint_2(door, door->position,
                                                 &D_80800994_chbosskogsdoor);
                *(f32 *) &door->actorData[4] = 0.0f;
            } else {
                func_80103110(door, 0);
            }
            break;
        case 2:
            if (func_80101E14(door, 0.35f)) {
                _subaddieaudioquick_entrypoint_2(door, door->position,
                                                 &D_80800988_chbosskogsdoor);
            } else if (func_80101E14(door, 0.4f)) {
                _subaddieaudioquick_entrypoint_2(door, door->position,
                                                 &D_808009A0_chbosskogsdoor);
                func_800BBCB8(door->position, NULL, door->scale, 4,
                              &D_808009B0_chbosskogsdoor);
            }
            if (func_80101F24(door) > 0.4f) {
                func_800EFA4C(dust_pos, -247.0f, *(f32 *) &door->actorData[4] + 150.0f, 1720.0f);
                *(f32 *) &door->actorData[4] += 1200.0f * func_800D8FF8();
                func_800BBCB8(dust_pos, dust_pos, 1.0f, 2, &D_808008B0_chbosskogsdoor);
            }
            if (func_80101DDC(door)) {
                door->unk58 = 2.0f;
                func_80102424(door, 3);
            }
        case 3:
        case 4:
            break;
    }
}

s32 func_80800714_chbosskogsdoor(Actor *door, s32 event, s32 arg)
{
    switch (event) {
        case 0x91:
            if (func_800F64A4(func_800F54E4(), 0x40) != 0) {
                if ((func_800DA298(0xA06) != 0) && (door->unk70_10 == 1)) {
                    door->unk64_20 = 1;
                    func_80103110(door, 1);
                    _capod_entrypoint_13(door->unk0, 0, 0x18, 0x810);
                }
            } else if (!door->unk74_30) {
                _subaddiedialog_entrypoint_11(door->unk0, 0x1354, 6, (u8 *) door + 4, 0);
                door->unk74_30 = 1;
            }
            return 1;
        case 0x95:
            func_80102424(door, door->unk70_10);
            func_80102204(door);
            return 1;
        case 0xB:
            if (arg == 0x18) {
                _capod_entrypoint_14();
                func_80102424(door, 4);
                _glcutDll_entrypoint_6(0x10F, 0x40);
                return 4;
            }
            return 3;
        default:
            return 0;
    }
}

int chbosskogsdoor_entrypoint_1()
{
    return &D_808009EC_chbosskogsdoor;
}

// TU-NOTE: the overlay .data is defined in C here (values taken from the ROM); IDO schedules some
// functions differently unless these tables share the unit. The extern declarations at the top
// were adjusted to the object types (same addresses).
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_80108ED0();
s32 D_808008B0_chbosskogsdoor[14] = {0x1D09CD, 0x1BFC18, -0x31FFFD3, 0x12C0190, 0x161100,
                                     0x180000, 0x41E00,  0x23000022, 0x400059,  0x190033,
                                     0x150000, 0xCC002B, 0x800080,   0x0};
u8 D_808008E8_chbosskogsdoor[16] = {0x0, 0x13, 0x5, 0x28, 0x0,  0xA,  0x0, 0xC0,
                                    0x0, 0x1,  0x0, 0xC8, 0x17, 0x70, 0x0, 0x0};
u8 D_808008F8_chbosskogsdoor[12] = {0x0, 0x13, 0x4, 0xA0, 0x0, 0xA, 0x0, 0x99, 0x0, 0x0, 0x0, 0x0};
u8 D_80800904_chbosskogsdoor[8] = {0x0, 0x13, 0x4, 0xCE, 0x0, 0x0, 0x0, 0x0};
u8 D_8080090C_chbosskogsdoor[12] = {0x0, 0x13, 0x4, 0xE2, 0x0, 0xA, 0x0, 0x66, 0x0, 0x0, 0x0, 0x0};
int D_80800918_chbosskogsdoor[18] = {0x11803FD,
                                     0x8800001,
                                     0x0,
                                     (u32) func_80800090_chbosskogsdoor,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0xC00,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800000_chbosskogsdoor,
                                     (u32) func_80107C2C,
                                     -0x7FF7FBFE,
                                     (u32) func_80800458_chbosskogsdoor,
                                     0x0};
u32 D_80800960_chbosskogsdoor[10] = {0x0,      0x0,        0x3F000000, 0xD40044,   0x3F800000,
                                     0xD40042, 0x3F000000, 0xD40084,   0x3F000000, 0xD40084};
s32 D_80800988_chbosskogsdoor[3] = {0x130456, 0xA00CC, 0x0};
s32 D_80800994_chbosskogsdoor[3] = {0x13051B, 0xA0080, 0x0};
s32 D_808009A0_chbosskogsdoor[4] = {0x13051C, 0xA0133, 0x100C8, 0x17700000};
s32 D_808009B0_chbosskogsdoor[15] = {0x1D09C9, 0x2B0200, 0x3000022, 0x1000180,   0x3000400,
                                     0x150000, 0x33000D, 0x640019,  0x7,         0x2CFFEC,
                                     0x140014, 0x140028, 0x140020,  -0x7D919F80, 0x0};
int D_808009EC_chbosskogsdoor[21] = {0x11903FC,
                                     0x87E0001,
                                     (u32) &D_80800960_chbosskogsdoor,
                                     (u32) func_80800544_chbosskogsdoor,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0xC08,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_808004F4_chbosskogsdoor,
                                     (u32) func_80107C2C,
                                     -0x7FF7DC00,
                                     (u32) func_80800714_chbosskogsdoor,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0};
