// Probably Loggo, the talking toilet of Grunty Industries: talks depending on whether its Jiggy
// was taken, reacts to touch and egg hits, and hands out the Jiggy. Also a breakable object.
#include "common.h"

extern int D_80800648_chloggo[];
extern int D_80800690_chloggo[];
extern f32 *_gccubesearch_entrypoint_0(s32, Actor *);
extern void func_800EE88C(f32 *, f32 *);
extern s32 D_80800610_chloggo[];
extern s32 D_808006D8_chloggo[];
typedef struct {
    u8 pad[0x94];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS148;
typedef union {
    s32 local_0;
    s16 local_1;
    Unk80132ED0 *local_2;
} Mass45LoggoEventArgs;
extern u8 D_808006E8_chloggo[];
extern u8 D_808005E0_chloggo[];
extern int func_800F54E4(void);
extern void func_800EE7F8(f32 *param_0, s32 *param_1);
extern void func_800EF1B8(f32 *param_0, f32 param_1, u32 param_2);
extern int func_800F77E8(s32 param_0, f32 *param_1);
extern s32 func_800F64A4(s32 param_0, s32 param_1);
extern void _subaddiedialog_entrypoint_11(s32 param_0, s32 param_1, s32 param_2, s32 *param_3,
                                          s32 param_4);
extern void func_80102424(s32 param_0, s32 param_1);
extern void func_8010A570(s32 param_0);
extern void _capod_entrypoint_13(s32 param_0, s32 param_1, s32 param_2, s32 param_3);
extern int D_808006F8_chloggo[];
extern int D_80800740_chloggo[];
extern int D_80800710_chloggo[];
extern int D_80800728_chloggo[];
extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
void func_80800398_chloggo();
int func_80800460_chloggo();

// Loggo NPC: dialogs, jiggy reward, sounds.
void *chloggo_entrypoint_0()
{
    return &D_80800648_chloggo;
}

// Breakable object next to Loggo (explodes on an egg hit, FLAG_181).
int chloggo_entrypoint_1()
{
    return (int) &D_80800690_chloggo;
}

// Init: points the actor at its cube-search position and picks the state.
void func_80800018_chloggo(Actor *actor)
{
    func_800EE88C((f32 *) actor->actorData, _gccubesearch_entrypoint_0(0x201, actor));
    if (_glcutDll_entrypoint_20())
        func_80102424(actor, 4);
    else if (func_800D0A9C(0x10, 4))
        func_8010A570(actor);
    else
        func_8010A5B0(actor, func_800DA298(0x169));
}

void func_808000AC_chloggo(u8 *actor)
{
    u32 state;

    state = (u32) (u16) *(u16 *) ((s8 *) actor + 0x72) >> 0xA;
    switch (state) {
        case 1:
            func_80800460_chloggo(actor);
            if (func_800D0A9C(0x10, 4) != 0) {
                _subaddiedialog_entrypoint_8(actor, actor + 4, &D_808006D8_chloggo,
                                             &D_80800610_chloggo, 2);
            } else {
                _subaddiedialog_entrypoint_8(actor, actor + 4, &D_808006D8_chloggo,
                                             (s32 *) D_808005E0_chloggo, 6);
            }
            break;
        case 2:;
        case 4:
            func_80800460_chloggo(actor);
            break;
        case 3:
            if (func_800F52B8(func_800F54E4(), *(s32 *) ((s8 *) actor + 0)) != 0xB) {
                func_80800398_chloggo(actor);
            }
    }
    *(u8 *) ((s8 *) actor + 0x94) = (u8) (*(u8 *) ((s8 *) actor + 0x94) & 0xFFBF);
}

// Event handler: dialogs, touch, egg hits.
s32 func_808001B8_chloggo(Actor *actor, s32 event, Mass45LoggoEventArgs event_arg)
{
    switch (event) {
        case 0x2E:
            switch (*(s16 *) &event_arg) {
                case 0x1343:
                case 0x1380:
                    func_800D1000(0x10, 4, actor->actorData, 1, 0);
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_808006E8_chloggo);
                    _capod_entrypoint_14();
                    _capod_entrypoint_13(actor->unk0, 0, 6, 0x2030);
                    break;
                case 0x1367:
                    _capod_entrypoint_14();
                    func_80102424(actor, 1);
                    break;
                default:
                    if (_subaddiedialog_entrypoint_9(actor, *(s16 *) &event_arg, D_808005E0_chloggo,
                                                     6) == 1) {
                        func_8010A590(actor);
                    }
                    func_80102424(actor, 1);
            }
            return 1;
        case 0x3E:
            if (*(u16 *) ((u8 *) *(Unk80132ED0 **) &event_arg + 0x18) & 1)
                return 0;
            if (func_800F52B8((u32) *(u16 *) ((u8 *) *(Unk80132ED0 **) &event_arg + 0x1A) >> 5,
                              actor->unk0) == 11 &&
                actor->unk70_10 != 3)
                func_80102424(actor, 3);
            break;
        case 0x40:
            func_80800398_chloggo(actor);
            return 1;
        case 0xB:
            if (*(s32 *) &event_arg == 6) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1367, 6, actor->position, 0xAD);
            }
            return 3;
        case 0x91:
            ((BitS148 *) actor)->b6 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800398_chloggo(actor) u8 *actor;
{
    f32 pos[3];
    s32 dialog_id;
    s32 player;

    player = func_800F54E4();
    func_800EE7F8(pos, actor + 4);
    func_800EF1B8(pos, *(f32 *) ((char *) actor + 0x48) - 40.0f, 0x43480000);
    func_800F77E8(player, pos);
    if (func_800F64A4(player, 0x201) != 0) {
        dialog_id = 0x1343;
    } else {
        dialog_id = 0x1380;
    }
    _subaddiedialog_entrypoint_11(*(s32 *) actor, dialog_id, 6, actor + 4, 0xAD);
    func_80102424(actor, 2);
    func_8010A570(actor);
    _capod_entrypoint_13(*(s32 *) actor, 0, 3, 0x30);
}

int func_80800460_chloggo(actor)
s32 actor;
{
    s32 actor_copy;
    // Matching: the copy through | 0 is needed for the match.
    actor_copy = actor | 0;
    _subaddieaudioquick_entrypoint_3(actor_copy, actor_copy + 4, &D_808006F8_chloggo, 0x3DB851EC);
    _subaddieaudioquick_entrypoint_3(actor_copy, actor_copy + 4, &D_80800740_chloggo, 0x3E23D70A);
    _subaddieaudioquick_entrypoint_3(actor_copy, actor_copy + 4, &D_80800710_chloggo, 0x3E6147AE);
    _subaddieaudioquick_entrypoint_3(actor_copy, actor_copy + 4, &D_80800728_chloggo, 0x3F19999A);
}

s32 func_808004F8_chloggo(s32 actor)
{
    if (_glcutDll_entrypoint_20())
        func_800FFAB0(actor);
}

// Event handler for the breakable variant: explodes on an egg hit (FLAG_181).
s32 func_80800528_chloggo(Actor *actor, s32 event, s32 event_arg)
{
    f32 pos[3];

    switch (event) {
        case 0x40:
            func_800EE7F8(pos, actor->position);
            func_800EF1B8(pos, actor->rotation[1], 0xC3480000);
            _chexploder_entrypoint_3(actor, pos, 0xF);
            func_800DA544(0x181);
            break;
        case 0x90:
            _chexploder_entrypoint_13(func_80106790(func_80101080()), 1);
            break;
        default:
            return 0;
    }
    return 1;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void func_80102EC0();
extern void _bsbabykaz_entrypoint_11();
u8 D_808005E0_chloggo[48] = {0x0,  0x0,  0x0, 0x1, 0x13, 0x41, 0x1,  0x0,  0x0,  0x0,  0x4, 0x1,
                             0x13, 0x42, 0x2, 0x0, 0x0,  0x0,  0x2,  0x0,  0x13, 0x81, 0x1, 0x0,
                             0x0,  0x0,  0x2, 0x0, 0x13, 0x83, 0x2,  0x0,  0x0,  0x0,  0x4, 0x0,
                             0x13, 0x82, 0x1, 0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB,  0x3, 0x0};
s32 D_80800610_chloggo[4] = {0x601, 0x13680200, -0x12001, 0x120B0300};
u32 D_80800620_chloggo[10] = {0x0,       0x0,        0x3F4CCCCD, 0x2380000,  0x3F4CCCCD,
                              0x2380000, 0x3F4CCCCD, 0x2380000,  0x3F4CCCCD, 0x2380000};
int D_80800648_chloggo[18] = {0xAD0435,
                              0x63E0001,
                              (u32) &D_80800620_chloggo,
                              (u32) func_808000AC_chloggo,
                              (u32) func_80105834,
                              (u32) func_80101870,
                              0x0,
                              0x40200000,
                              0x0,
                              0x4000090C,
                              0x0,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800018_chloggo,
                              (u32) func_80107C2C,
                              -0x7FFFDB6E,
                              (u32) func_808001B8_chloggo,
                              0x0};
int D_80800690_chloggo[18] = {0x1560436,
                              0x7AF0001,
                              0x0,
                              (u32) func_80102EC0,
                              (u32) func_80105834,
                              (u32) func_80101870,
                              0x0,
                              0x0,
                              0x1810000,
                              0x40000800,
                              0x0,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_808004F8_chloggo,
                              (u32) func_80107C2C,
                              (u32) _bsbabykaz_entrypoint_11,
                              (u32) func_80800528_chloggo,
                              0x0};
s32 D_808006D8_chloggo[4] = {0x1690000, 0x12C00AD, 0xC, 0x23C0200};
u8 D_808006E8_chloggo[16] = {0x0, 0x13, 0x4, 0x2B, 0x0, 0xA, 0x0, 0x80,
                             0x0, 0x18, 0x0, 0x2,  0x0, 0x0, 0x0, 0x0};
int D_808006F8_chloggo[6] = {0x130627, 0x10190, 0x3E8000D, 0xF3010C, 0x1655F0, 0x0};
int D_80800710_chloggo[6] = {0x1305C1, 0x10190, 0x3E8000D, 0x1A601C0, 0x162EE0, 0x0};
int D_80800728_chloggo[6] = {0x130555, 0x10190, 0x3E8000D, 0xF3010C, 0x161F40, 0x0};
int D_80800740_chloggo[8] = {0x130556, 0x10190, 0x3E8000D, 0xF3010C, 0x161F40, 0x0, 0x0, 0x0};
