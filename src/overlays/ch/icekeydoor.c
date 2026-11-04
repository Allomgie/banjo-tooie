// Probably the Ice Key vault door (Stop 'n' Swop). With the Ice Key (item 0x53), talking to it
// plays a cutscene: the key flies into the lock and turns, the door opens, flag 0x3E2 is set
// and the key is used up.
#include "common.h"

extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800136E4(f32);
extern int D_80800930_chicekeydoor[];
extern u8 D_80800920_chicekeydoor[];
extern void func_8010D5DC(void);
extern void func_8008F990(f32 *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800F5A00(s32, f32 *);
extern void func_800F8300(s32, s32, f32 *);
extern Prop *_gccubesearch_entrypoint_0(u32, Actor *);
extern void _gspropctrl_entrypoint_11(Prop *, f32 *);
extern s32 _glsplinefind_entrypoint_3(f32 *);
extern void *func_800D7520();
extern void func_800C7A68(void *, f32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern u8 D_80800978_chicekeydoor[];
s32 func_80800640_chicekeydoor();

// Per-frame update: cutscene states 2..7 (key flies in, turns, door opens).
void func_80800000_chicekeydoor(Actor *door)
{
    f32 *door_pos;
    Actor *key;
    f32 t;

    switch (door->unk70_10) {
        case 1:
        case 8:
            break;
        case 2:
            if (func_8010C500(door)) {
                func_8008F8B0();
                func_8008F8D8(1);
                func_8008F904(func_8010D5DC, door->unk0);
                func_8008F938(1);
                func_8008F990((f32 *) door->actorData, 500.0f);
                func_80101FDC(door, 3);
            }
            break;
        case 3:
            func_800D1824(0x53);
            break;
        case 4:
            if (func_800D90A4(&door->unk58)) {
                func_80108B04(door, 0);
                door->unk58 = 5.0f;
                _capod_entrypoint_13(door->unk0, door->unk0, 0x1F, 0x10);
                func_800FC660(0xE);
                func_800D1804(0x53);
                func_80101FDC(door, 5);
            }
            func_800D1824(0x53);
            break;
        case 5:
            if (door->unk3C != NULL &&
                func_80800640_chicekeydoor(door, func_80106790(door->unk3C))) {
                func_800C4140(0x7FFB5D6D, door->position, 0x04B000FA);
                door->unk58 = 1.0f;
                func_80101FDC(door, 6);
            }
            func_800D1824(0x53);
            break;
        case 6:
            if (door->unk3C != NULL) {
                key = func_80106790(door->unk3C);
                if (func_800D90A4(&door->unk58)) {
                    door_pos = door->position;
                    func_800EFB24((f32 *) &key->actorData[4], key->position,
                                  door->position);
                    door->unk58 = 4.0f;
                    key->rotation[0] = 90.0f;
                    func_800C4140(0x7FFB5C56, door_pos, 0x04B000FA);
                    func_80101FDC(door, 7);
                } else {
                    key->rotation[0] = func_800F12D4(door->unk58, 1.0f, 0.0f, 0.0f, 90.0f);
                }
            }
            func_800D1824(0x53);
            break;
        case 7:
            if (func_800D90A4(&door->unk58)) {
                door->rotation[1] = -90.0f;
                func_800F82D4(func_800F54E4(), 0);
                func_800DA544(0x3E2);
                _subaddieaudioloop_entrypoint_2(door);
                func_800C4140(0x7FFB5CC7, door->position, 0x04B000FA);
                _subaddieDll_entrypoint_4(door, 0);
                func_80101FDC(door, 8);
            } else {
                t = func_800F12D4(door->unk58, 4.0f, 0.0f, 0.0f, 1.0f);
                _subaddieaudioloop_entrypoint_4(door, door->position, 1,
                                                D_80800920_chicekeydoor);
                door->rotation[1] = t * -90.0f;
            }
            func_800D1824(0x53);
    }
}

// Message handler: 0x95 start, 0x32 begin cutscene, 0x3D spawn the key actor.
s32 func_80800318_chicekeydoor(Actor *door, s32 msg_id, s32 msg_arg)
{
    f32 player_pos[3];
    Prop *lock_prop;
    f32 spline_pos[3];
    Actor *key;

    switch (msg_id) {
        case 0x32:
            func_800F5A00(func_800F54E4(), player_pos);
            func_800EF1B8(player_pos, ((f32 *) door->actorData)[3], 200.0f);
            func_800F8300(func_800F54E4(), 2, player_pos);
            func_80101FDC(door, 4);
            door->unk58 = 1.0f;
            _subaddieDll_entrypoint_4(door, 1);
            break;
        case 0x95:
            if (func_800DA298(0x3E2)) {
                door->rotation[1] = -90.0f;
                func_80108B04(door, 1);
                func_80101FDC(door, 8);
            } else if (func_800D1A04(0x53)) {
                lock_prop = _gccubesearch_entrypoint_0(0x299, door);
                _gspropctrl_entrypoint_11(lock_prop, (f32 *) door->actorData);
                ((f32 *) door->actorData)[3] = (f32) _gspropctrl_entrypoint_12(lock_prop);
                _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(0x511, door), spline_pos);
                ((f32 *) door->actorData)[7] = (f32) _glsplinefind_entrypoint_3(spline_pos);
                func_80101FDC(door, 2);
            } else {
                func_80103110(door, 0);
                func_80101FDC(door, 1);
            }
            break;
        case 0x3D:
            key = func_80108528(0x513, door->position, 0, &door);
            key->unk3C = door->unk0;
            door->unk3C = key->unk0;
            switch (msg_arg) {
                case 0:
                    func_800C7A68(func_800D7520((s32) ((f32 *) door->actorData)[7]), 0.0f,
                                  key->position);
                    key->scale = 0.1f;
                    break;
                case 1:
                    key->scale = 1.0f;
            }
            func_8010A570(key);
            key->unk64_16 = 0;
            return 1;
    }
    return 0;
}

void func_8080057C_chicekeydoor(Actor *door, s32 gfx)
{
    Actor *key;

    func_80101870(door, gfx);
    if (door->unk3C && door->unk7C_12) {
        key = func_80106790(door->unk3C);
        key->unk64_16 = 1;
        if ((s32) door->unk70_10 >= 6) {
            _subaddieskeleton_entrypoint_1(door, 4, key->position);
            key->rotation[1] = func_800136E4(door->rotation[1] - 180.0f);
        }
        func_80101870(key, gfx);
        key->unk64_16 = 0;
    }
}

int chicekeydoor_entrypoint_0()
{
    return (int) &D_80800930_chicekeydoor;
}

// Moves the key along the spline; returns nonzero when the timer has run out.
s32 func_80800640_chicekeydoor(door, key)
Actor *door;
Actor *key;
{
    f32 t;
    f32 prev_yaw;
    s32 done;

    prev_yaw = key->rotation[1];
    done = func_800D90A4(&door->unk58);
    t = func_800F10B4(door->unk58, 5.0f, 0.0f, 0.0f, 1.0f);
    func_800C7A68(func_800D7520((s32) ((f32 *) door->actorData)[7]), t, key->position);
    key->rotation[0] = 0.0f;
    if (t < 0.9f) {
        func_800BBCB8(key->position, key->position, 1.0f, 1, D_80800978_chicekeydoor);
        key->rotation[1] = func_800136E4(func_800F12D4(t, 0.0f, 0.9f, 0.0f, 1260.0f));
    } else {
        key->rotation[1] = 180.0f;
    }
    if (t < 0.5f) {
        key->scale = func_800F12D4(t, 0.0f, 0.5f, 0.1f, 1.0f);
    } else {
        key->scale = 1.0f;
    }
    if ((prev_yaw < 160.0f && key->rotation[1] >= 160.0f) ||
        (prev_yaw < 340.0f && key->rotation[1] >= 340.0f)) {
        func_800C4140(((u16) (u32) (func_80013970(t * 180.0f) * 0.4f + 1227.600098f) << 21) +
                          0x1B5E64,
                      key->position, 0x04B000FA);
    }
    return done;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_80800920_chicekeydoor[16] = {0x0, 0x13, 0x4,  0xAD, 0x0, 0xA, 0x1, 0x0,
                                  0x0, 0x16, 0x6D, 0x60, 0x0, 0x0, 0x0, 0x0};
int D_80800930_chicekeydoor[18] = {0x1580512,
                                   0x9650002,
                                   0x0,
                                   (u32) func_80800000_chicekeydoor,
                                   (u32) func_80105834,
                                   (u32) func_8080057C_chicekeydoor,
                                   0x7D00000,
                                   0x0,
                                   0x0,
                                   0x841,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   0x0,
                                   (u32) func_80107C2C,
                                   -0x7FFFDBFE,
                                   (u32) func_80800318_chicekeydoor,
                                   0x0};
u8 D_80800978_chicekeydoor[88] = {
    0x0,  0x1D, 0x9,  0xE0, 0x0, 0x1B, 0xFC, 0xE0, 0xFD, 0xA8, 0x0,  0x2D, 0x0,  0xC8, 0x1,
    0x5E, 0x0,  0xE,  0x0,  0x0, 0x0,  0x50, 0x0,  0x16, 0x10, 0x2,  0x0,  0x27, 0x0,  0x0,
    0x1,  0x2C, 0x0,  0x0,  0x1, 0xF4, 0x0,  0x22, 0x0,  0x4C, 0x0,  0x4C, 0x0,  0x59, 0x0,
    0x80, 0x0,  0x15, 0x0,  0x0, 0x0,  0xCC, 0x0,  0x2B, 0x1,  0x80, 0x3,  0x0,  0x0,  0x4,
    0x0,  0x99, 0x0,  0x7,  0x0, 0x4,  0x0,  0x31, 0xFF, 0xB5, 0xFF, 0xCE, 0x0,  0x0,  0x0,
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
