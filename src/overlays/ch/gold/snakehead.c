// Mayahem Temple golden snake heads: probably six hit targets counted in flag bits, which tell
// actor 0x10E once all are hit. Also holds two doors, one opened by flag 0x18B, one by FLAG_59C.
#include "common.h"

extern int D_80800508_chgoldsnakehead[];
extern int D_80800550_chgoldsnakehead[];
extern int D_80800598_chgoldsnakehead[];
extern void func_800FFAB0();
extern void func_80103014();
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern Actor *_subaddiefind_entrypoint_3(s32, s32 *);
extern s16 *_gccubesearch_entrypoint_1(s32, f32 *);
extern void _gspropctrl_entrypoint_11();
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 18;
    u32 local_0 : 1;
    u32 pad_2 : 13;
} GoldSnakeCollisionMarker961;
extern s32 D_808004F0_chgoldsnakehead[];
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
extern void func_80102B2C(Actor *, f32);
extern void func_80102B6C(Actor *, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void _chdoormake_entrypoint_8(s32, s32);
extern void _chdoormake_entrypoint_9(s32, s32, s32, s32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);

int chgoldsnakehead_entrypoint_0()
{
    return (int) &D_80800508_chgoldsnakehead;
}

int *chgoldsnakehead_entrypoint_1()
{
    return &D_80800550_chgoldsnakehead;
}

int chgoldsnakehead_entrypoint_2()
{
    return &D_80800598_chgoldsnakehead;
}

// Snake head init: mirrors the head across the prop plane onto its twin and sets the side flag.
void func_80800024_chgoldsnakehead(Actor *actor)
{
    s16 *cube;
    f32 plane[3];
    Actor *twin;
    s32 iter;

    cube = _gccubesearch_entrypoint_1(0x1EA, actor->position);
    if (func_800DA298(0x18B)) {
        func_800FFAB0(actor);
        return;
    }
    _gspropctrl_entrypoint_11(cube, plane);
    if (plane[2] <= actor->position[2]) {
        twin = _subaddiefind_entrypoint_2(0x10D, &iter);
        while (twin) {
            if (twin->unk74_7 == actor->unk74_7 && twin != actor) {
                break;
            }
            twin = _subaddiefind_entrypoint_3(0x10D, &iter);
        }
        actor->position[0] = twin->position[0];
        actor->position[1] = twin->position[1];
        actor->position[2] = 2.0f * plane[2] - twin->position[2];
    }
    if ((s32) actor->unk74_7 >= 0x33) {
        ((GoldSnakeCollisionMarker961 *) actor->unk0)->local_0 = 1;
    } else {
        ((GoldSnakeCollisionMarker961 *) actor->unk0)->local_0 = 0;
    }
    func_80103014(actor);
    func_800DA7A8(6, 0, 3);
}

void func_8080015C_chgoldsnakehead(Actor *actor)
{
    switch (actor->unk70_10) {
        case 2:
            func_800FC63C(14, 0x7FBC);
            func_800EE7F8(actor->actorData, actor->position);
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             &D_808004F0_chgoldsnakehead);
            func_80101FDC(actor, 3);
        case 3:
            actor->unk50 = func_800DC178(-10.0f, 10.0f);
            actor->unk54 = func_800DC178(-15.0f, 15.0f);
            func_80102B2C(actor, 5.0f);
            func_80102B6C(actor, 5.0f);
            func_800EF214(actor->position, actor->rotation[0], actor->rotation[1] + 90.0f,
                          func_800DC178(50.0f, 250.0f) * func_800D8FF8());
            if (*(f32 *) &actor->actorData[0] + 125.0f < actor->position[0])
                _subaddiefade_entrypoint_3(actor);
        case 1:
            break;
    }
}

void func_808002B4_chgoldsnakehead(Actor *actor, void *draw_arg)
{
    func_800DF744(1, ((GoldSnakeCollisionMarker961 *) actor->unk0)->local_0 ? 0 : 1);
    func_800DF744(2, ((GoldSnakeCollisionMarker961 *) actor->unk0)->local_0);
    func_80101870(actor, draw_arg);
}

// Counts hits in a 3-bit flag counter; the sixth hit messages actor 0x10E.
int func_80800324_chgoldsnakehead(Actor *actor, s32 param_1)
{
    s32 hits;
    func_8010A570(actor);
    func_80101FDC(actor, 2);
    func_80102FE8(actor, 0);
    func_80103110(actor, 1);
    hits = func_800DA564(6, 3) + 1;
    func_800DA7A8(6, hits, 3);
    if (hits == 6) {
        func_80101180(0x10E, 7, 0);
    }
}

s32 func_808003A8_chgoldsnakehead(unsigned int actor, s32 message, s32 arg)
{
    if ((message == 0x40) ^ 0) {
        func_80800324_chgoldsnakehead(*&actor, arg | 0);
        // Matching: empty block needed for the match.
        if (!arg) {
        }
        return 1;
    }
    return 0;
}

// Door opening on flag 0x18B.
void func_808003E0_chgoldsnakehead(s32 door)
{
    if (_chdoormake_entrypoint_3(door, 0.0f, 90.0f, 200.0f, 0x41, 0x18B)) {
        _chdoormake_entrypoint_8(door, 5);
        _chdoormake_entrypoint_9(door, 0, 6, 0x10);
    }
}

// Treasure chamber top door; opens on flag 0x59C with cutscene 0xD.
void func_80800440_chgoldsnakehead(Actor *door)
{
    if (_chdoormake_entrypoint_3(door, 0.0f, 90.0f, 200.0f, 0x60, 0x59C)) {
        _chdoormake_entrypoint_6(door, 3.0f);
        _chdoormake_entrypoint_8(door, 5);
        _chdoormake_entrypoint_12(door, 0, 0xD);
        _chdoormake_entrypoint_9(door, 0, 0x2B, 0x2900);
    }
    if (func_800DA298(0x59C) && !_glcutDll_entrypoint_19(0xD)) {
        func_800FFAB0(door);
    }
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
extern int func_80101870();
extern void _chdoor_entrypoint_1();
s32 D_808004F0_chgoldsnakehead[6] = {0x1303F1, 0xD00CC, 0x1000016, 0x6D600001, 0x4E21388, 0x0};
int D_80800508_chgoldsnakehead[18] = {0x155010D,
                                      0x6580001,
                                      0x0,
                                      (u32) func_8080015C_chgoldsnakehead,
                                      (u32) func_80105834,
                                      (u32) func_808002B4_chgoldsnakehead,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x800,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      (u32) func_80800024_chgoldsnakehead,
                                      (u32) func_80107C2C,
                                      -0x7FFFD400,
                                      (u32) func_808003A8_chgoldsnakehead,
                                      0x0};
int D_80800550_chgoldsnakehead[18] = {0xAC010E,
                                      0x6570001,
                                      0x0,
                                      (u32) _chdoor_entrypoint_0,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x800,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_808003E0_chgoldsnakehead,
                                      (u32) func_80107C2C,
                                      -0x7FFFD3FE,
                                      (u32) _chdoor_entrypoint_1,
                                      0x0};
int D_80800598_chgoldsnakehead[18] = {0xAC04C9,
                                      0x6570001,
                                      0x0,
                                      (u32) _chdoor_entrypoint_0,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x800,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800440_chgoldsnakehead,
                                      (u32) func_80107C2C,
                                      -0x7FFFD3FE,
                                      (u32) _chdoor_entrypoint_1,
                                      0x0};
