// Probably the world-unlock cutscene actor (spawned with message 0x49 and a world index): flies a
// giant jiggy to the world's entrance with camera, rumble and sound, shrinks it into the door,
// then sends 'open' (7) to that world's entrance actor and ends the cutscene.
#include "common.h"
extern void func_800EF214(f32 *, f32, f32, f32);

extern s32 D_80800990_chworlddoors[];
extern s32 _sujiggy_entrypoint_22(s32);
extern s32 _gccubesearch_entrypoint_9(s32, s32 *, s32);
extern s32 _gspropctrl_entrypoint_8(s32);
extern void _gspropctrl_entrypoint_11(s32, f32 *);
extern s32 _gspropctrl_entrypoint_12(s32);
extern s32 _gspropctrl_entrypoint_13(s32);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern int D_80800A04_chworlddoors[];
extern u8 D_808009D8_chworlddoors[];
extern u8 D_808009E8_chworlddoors[];
extern f32 _capod_entrypoint_18(void);
extern s32 func_800E15CC(s32, f32, f32);
extern void func_800E13F0(s32, f32);
extern void func_80018820(s32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800EE7F8();
extern u8 D_808009F8_chworlddoors[];
extern f32 func_80103EAC(Actor *);
extern void func_800DE498(s32, void *, void *, f32, s32, s32);

// TU-NOTE: .data is defined in this C file; IDO schedules the functions differently otherwise.

// Draws the flying jiggy trail.
void func_80800000_chworlddoors(u8 *actor)
{
    f32 unk_0[3];

    func_800EE7F8(unk_0, actor + 0x28);
    func_800EF214(unk_0, *(f32 *) ((s8 *) actor + 0x44), *(f32 *) ((s8 *) actor + 0x48),
                  -5e+01f);
    func_800BBCB8(actor + 0x28, unk_0, 0x3F800000, 6, &D_80800990_chworlddoors);
}

// Finds the start/end props of the world entrance.
s32 func_80800068_chworlddoors(Actor *actor)
{
    s32 prop_ids[2];
    f32 rot[2];
    s32 unk_0;
    s32 count;
    s32 i;
    s32 world_prop;
    s32 *prop;

    world_prop = _sujiggy_entrypoint_22(actor->unk79_4);
    count = _gccubesearch_entrypoint_9(0x4DC, prop_ids, 2);
    i = 0;
    if (count > 0) {
        prop = prop_ids;
        do {
            if (_gspropctrl_entrypoint_8(*prop) == world_prop + 0x32) {
                _gspropctrl_entrypoint_11(*prop, (f32 *) &actor->actorData[0]);
                unk_0 = _gspropctrl_entrypoint_13(*prop) - 1;
                *(f32 *) &actor->actorData[13] = _gspropctrl_entrypoint_12(*prop);
            }
            i++;
            prop++;
        } while (i != count);
        i = 0;
    }
    count = _gccubesearch_entrypoint_9(0x4DD, prop_ids, 2);
    if (count > 0) {
        prop = prop_ids;
        do {
            if (_gspropctrl_entrypoint_8(*prop) == world_prop + 0x32) {
                _gspropctrl_entrypoint_11(*prop, (f32 *) &actor->actorData[4]);
                actor->unk54 = _gspropctrl_entrypoint_13(*prop) / 10.0f;
                actor->unk50 = _gspropctrl_entrypoint_12(*prop) / 10.0f;
            }
            i++;
            prop++;
        } while (i != count);
    }
    func_800F18FC((f32 *) &actor->actorData[4], (f32 *) &actor->actorData[0], rot);
    actor->rotation[0] = rot[0];
    actor->rotation[1] = rot[1];
    func_800EEBF0((f32 *) &actor->actorData[0], rot, 4000.0f);
    func_800EF04C((f32 *) &actor->actorData[0], (f32 *) &actor->actorData[4]);
    return unk_0;
}

void func_80800214_chworlddoors(actor, state) void *actor;
s32 state;
{
    s32 unk_0;
    float unk_1;
    s32 unk_2;

    switch (state) {
        case 1:
            unk_0 = func_80800068_chworlddoors(actor);
            func_800EE7F8((s32 *) ((char *) actor + 0x4), (s32 *) ((char *) actor + 0x18));
            unk_2 = *(s32 *) ((char *) actor + 0x0);
            _capod_entrypoint_13(unk_2, unk_2, unk_0, 0x6830);
            *(float *) ((char *) actor + 0x58) = 0.0f;
            break;
        case 2:
            unk_1 = 1.0f;
            *(s8 *) ((char *) actor + 0x34) = 0;
            *(float *) ((char *) actor + 0x58) = unk_1;
            break;
        case 3:
            *(float *) ((char *) actor + 0x58) = 0.8f;
            *(s8 *) ((char *) actor + 0x34) = 0;
            func_800C3F48(0x7FFFFC90);
            break;
        case 4:
            func_800E1720(*(s32 *) ((char *) actor + 0x24) - 1);
            _subaddieaudioloop_entrypoint_2(actor);
            *(float *) ((char *) actor + 0x58) = 2.0f;
            func_8010A800(actor, 3);
            break;
        case 5:
            func_80101180(_sujiggy_entrypoint_23((u32) *(u8 *) ((char *) actor + 0x79) >> 4), 7,
                          (s32) *(float *) ((char *) actor + 0x50));
            *(float *) ((char *) actor + 0x58) = *(float *) ((char *) actor + 0x50);
            break;
        case 6:
            if ((((u32) *(u8 *) ((char *) actor + 0x79) >> 4) == 0)) {
                *(s32 *) ((char *) actor + 0x24) = func_800E15CC(2, 5e+01f, 0.5f);
                func_80018820(0, 1.0f, 0.4f);
            }
            *(float *) ((char *) actor + 0x58) = *(float *) ((char *) actor + 0x54);
    }
    func_80101FDC(actor, state);
}

// Update: runs the cutscene phases (fly, shrink, open, end).
void func_80800388_chworlddoors(Actor *actor)
{
    f32 unk_0;

    switch (actor->unk70_10) {
        case 1:
            unk_0 = _capod_entrypoint_18();
            if (unk_0 < 0.1f) {
                unk_0 = 0.1f;
            }
            if (actor->actorData[3] == 0) {
                actor->actorData[3] = func_800E15CC(0, 0.0f, 1.0f) + 1;
            }
            func_800E13F0(actor->actorData[3] - 1, unk_0 * 10.0f);
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_808009E8_chworlddoors);
            func_800C4B70((s32) (24000.0f * unk_0));
            func_80018820(0, unk_0, 0.1f);
            break;
        case 2:
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_808009E8_chworlddoors);
            func_800C4B70(24000);
            func_80018820(0, 1.0f, 0.1f);
            if (func_800D90A4(&actor->unk58)) {
                func_80800214_chworlddoors(actor, 3);
                func_800EE7F8(actor->position, (f32 *) &actor->actorData[4]);
            } else {
                func_800EFE50(actor->position, (f32 *) actor->actorData,
                              (f32 *) &actor->actorData[4],
                              func_800F10B4(actor->unk58, 1.0f, 0.0f, 0.0f, 1.0f));
            }
            *(u8 *) &actor->actorData[7] = _subaddieaudioloop_entrypoint_7(
                *(u8 *) &actor->actorData[7], actor->position, 1, D_808009D8_chworlddoors, 0);
            break;
        case 3:
            if (func_800D90A4(&actor->unk58)) {
                func_80800214_chworlddoors(actor, 4);
                *(u8 *) &actor->actorData[7] =
                    _subaddieaudioloop_entrypoint_3(*(u8 *) &actor->actorData[7]);
                _subaddieaudioloop_entrypoint_2(actor);
            } else {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                D_808009E8_chworlddoors);
                func_800C4B70(24000);
                func_80018820(0, 1.0f, 0.1f);
                func_80800000_chworlddoors(actor);
                actor->scale = func_800F10B4(actor->unk58, 0.8f, 0.0f, 1.0f, 0.001f);
                *(u8 *) &actor->actorData[7] = _subaddieaudioloop_entrypoint_7(
                    *(u8 *) &actor->actorData[7], actor->position, 1, D_808009D8_chworlddoors,
                    0);
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                D_808009E8_chworlddoors);
                func_800C4B70(24000);
            }
            break;
        case 4:
            if (func_800D90A4(&actor->unk58)) {
                func_80800214_chworlddoors(actor, 5);
            }
            break;
        case 5:
            if (func_800D90A4(&actor->unk58)) {
                func_80800214_chworlddoors(actor, 6);
            }
            break;
        case 6:
            if (func_800D90A4(&actor->unk58)) {
                _glcutDll_entrypoint_17();
            }
    }
}

// Message 0x49 starts the cutscene for world 0x7A..0x83.
s32 func_808006A8_chworlddoors(Actor *actor, s32 msg, s32 value)
{
    switch (msg) {
        case 0x49:
            if (value >= 0x7A && value < 0x84) {
                actor->unk79_4 = value - 0x7A;
                func_8010A800(actor, 0);
                func_80800214_chworlddoors(actor, 1);
                return 1;
            }
            func_800FFAB0(actor);
            return 0;
        case 0xB:
            if (actor->unk70_10 == 1)
                func_80800214_chworlddoors(actor, 2);
            return 3;
    }
    return 0;
}

int func_80800750_chworlddoors(Actor *actor)
{
    if (*(s32 *) ((char *) actor + 0x24) != 0) {
        func_800E1720(*(s32 *) ((char *) actor + 0x24) - 1);
    }
    if (*(u8 *) ((char *) actor + 0x5F) != 0) {
        _subaddieaudioloop_entrypoint_2(actor);
    }
}

void func_80800798_chworlddoors(Actor *actor, s32 gfx)
{
    f32 prev_pos[3];
    f32 unk_0;
    s32 alpha;
    f32 unk_1;
    func_800EE7F8(prev_pos, actor->position);
    func_800EF214(actor->position, actor->rotation[0], actor->rotation[1],
                  func_80103EAC(actor));
    switch (actor->unk70_10) {
        case 3:
            unk_0 = func_800F10B4(actor->unk58, 0.8f, 0.0f, 0.0001f, 20.0f);
            alpha = func_800F10B4(actor->unk58, 0.8f, 0.0f, 0.0f, 255.0f);
            func_800DF830(0);
            func_800DE498(gfx, (u8 *) actor + 0x28, actor->rotation, unk_0, 0,
                          func_800D674C(0x8CB));
            func_80101870(actor, gfx);
            func_800B99CC(gfx, alpha, D_808009F8_chworlddoors);
            break;
        case 2:
            func_80101870(actor, gfx);
            break;
        case 4:
            func_800B99CC(gfx, (s32) func_800F10B4(actor->unk58, 2.0f, 0.0f, 255.0f, 0.0f),
                          D_808009F8_chworlddoors);
    }
    func_800EE7F8(actor->position, prev_pos);
}

int chworlddoors_entrypoint_0()
{
    return &D_80800A04_chworlddoors;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_80800990_chworlddoors[18] = {0x1D09E5,    0x1BFCE0,    -0x257FFD3, 0x32003E8, 0xE0000,
                                   0x280016,    0x10020022,  0x33004C,   0x9900E6,  0x150000,
                                   0xCC002B,    0xC00180,    0x4004C,    0x70002,   0x0,
                                   -0x3CCB0000, -0x3CF00000, -0x3CF50000};
u8 D_808009D8_chworlddoors[16] = {0x0, 0x13, 0x6, 0x73, 0x0, 0x20, 0x0, 0x2,
                                  0x0, 0xA,  0x0, 0xD9, 0x0, 0x0,  0x0, 0x0};
u8 D_808009E8_chworlddoors[16] = {0x0, 0x13, 0x4, 0xA9, 0x0, 0x2, 0x0, 0x1E,
                                  0x0, 0xA,  0x1, 0x0,  0x0, 0x0, 0x0, 0x0};
u8 D_808009F8_chworlddoors[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF};
int D_80800A04_chworlddoors[19] = {0x158051B,
                                   0x9660001,
                                   0x0,
                                   (u32) func_80800388_chworlddoors,
                                   (u32) func_80105834,
                                   (u32) func_80800798_chworlddoors,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x21000,
                                   (u32) func_80800750_chworlddoors,
                                   (u32) func_80108ED0,
                                   0x0,
                                   0x0,
                                   (u32) func_80107C2C,
                                   -0x7FBFFBFE,
                                   (u32) func_808006A8_chworlddoors,
                                   0x0,
                                   0x0};
