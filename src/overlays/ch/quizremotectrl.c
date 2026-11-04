#include "common.h"
#include "types.h"

extern s32 func_800D90A4(void *arg);
extern s32 func_800D91EC(void *arg, f32 param_1);
extern f32 func_800F10B4(f32 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
extern f32 _suquiz_entrypoint_8(s32);
extern void func_80102424(Actor *, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int D_80800668_chquizremotectrl[];
typedef struct Mass45QuizDisplay {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x2C];
    f32 unk_54;
} Mass45QuizDisplay;
extern void func_800DE498(s32, void *, void *, f32, s32, void *);
extern void *func_800D674C(s32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_800E3C8C(f32, f32);
extern void func_800E39D8(f32 *, f32 *);
extern void _suquiz_entrypoint_13(f32 *);
extern void _suquiz_entrypoint_14(f32 *);
extern u8 D_80800650_chquizremotectrl[];
extern u8 D_8080065C_chquizremotectrl[];
extern f32 D_80800664_chquizremotectrl;

void func_80800000_chquizremotectrl(u8 *actor, s32 state)
{
    int flags;
    switch (state) {
        case 1:

        case 3:
            break;

        case 0:
            *(f32 *) ((s8 *) actor + 0x54) = 0.0f;
            *(f32 *) ((s8 *) actor + 0x50) = 0.5f;
            break;

        case 2:
            *(f32 *) ((s8 *) actor + 0x54) = 1.0f;
    }

    // Matching: the redundant masks and the extra temporary are needed for the match.
    flags = (*(u8 *) ((s8 *) actor + 0x79) & 0xFFFFu) & 0xFFFFu;
    *(u8 *) ((s8 *) actor + 0x79) = (u8) ((state * 0x10) | ((flags & 0xFFFFu) & 0xFF0F));
}

void func_80800068_chquizremotectrl(u8 *actor)
{
    f32 progress;
    u32 state;
    state = (u32) *(u8 *) ((u8 *) actor + 0x79) >> 4;
    switch (state) {
        case 1:
            if (func_800D90A4(actor + 0x50) != 0) {
                func_80800000_chquizremotectrl(actor, 2);
            }
            progress = func_800F10B4(*(f32 *) ((u8 *) actor + 0x50), 0.5f, 0, 0, 1.0f);
            *(f32 *) ((u8 *) actor + 0x54) = progress;
            // Matching: goto end is needed for the match.
            goto end;

        case 3:
            if (func_800D91EC(actor + 0x50, 0.5f) != 0) {
                func_80800000_chquizremotectrl(actor, 0);
            }
            // Matching: the (double) cast is needed for the match.
            progress = func_800F10B4(*(f32 *) ((u8 *) actor + 0x50), 0, 0.5f, 1.0f, (double) 0.0f);
            *(f32 *) ((u8 *) actor + 0x54) = progress;
    }

end:
    return;
}

void func_8080012C_chquizremotectrl(s32 *actor)
{
    s32 cam_node;
    s32 node_type;

    cam_node = _suquiz_entrypoint_26();
    node_type = func_800A5854(cam_node);
    if (node_type != 2) {
        if ((node_type == 5) || (node_type == 6) || (node_type == 8)) {
            _capod_entrypoint_13(*actor, 0, cam_node, 0x834);
        }
    } else {
        _capod_entrypoint_21(*actor, 0, cam_node, 0x814);
    }
    func_80800000_chquizremotectrl(actor, 0);
}

void func_808001BC_chquizremotectrl(Actor *actor, s32 state)
{
    func_80102424(actor, state);
    switch (actor->unk70_10) {
        case 1:
            if (_glglobalsettings_entrypoint_3())
                ((f32 *) actor->actorData)[3] = -300.0f;
            else
                ((f32 *) actor->actorData)[3] = -500.0f;
            func_800FC660(0x1E);
            ((f32 *) actor->actorData)[7] = 1.0f;
            func_8080012C_chquizremotectrl((s32 *) actor);
            break;
        case 2:
            func_800FC74C(0x1E);
            actor->unk58 = _suquiz_entrypoint_8(0);
            func_80800000_chquizremotectrl(actor, 1);
            break;
        case 3:
            func_800FC660(0x1D);
            ((f32 *) actor->actorData)[7] = 1.0f;
            func_80800000_chquizremotectrl(actor, 3);
            break;
        case 5:
            func_800FC74C(0x1D);
            _suquiz_entrypoint_25();
    }
}

void func_808002C8_chquizremotectrl(u8 *actor)
{
    u32 raw_state;
    u32 state;
    _suquiz_entrypoint_1();
    // Matching: the u16 round trip through two temporaries is needed for the match.
    raw_state = *(u16 *) ((s8 *) actor + 0x72);
    state = (u16) raw_state;
    state = state >> 0xA;
    raw_state = state;
    switch (raw_state) {
        case 5:
            break;

        case 1:
            if (func_800D90A4(actor + 0x34) != 0) {
                func_808001BC_chquizremotectrl(actor, 2);
            }
            break;

        case 2:
            if ((func_800D90A4(actor + 0x58) != 0) || (_suquiz_entrypoint_5() != 0)) {
                func_808001BC_chquizremotectrl(actor, 3);
            }
            break;

        case 3:
            if (func_800D90A4(actor + 0x34) != 0) {
                func_808001BC_chquizremotectrl(actor, 4);
            }
            break;

        case 4:
            func_808001BC_chquizremotectrl(actor, 5);
    }

    func_80800068_chquizremotectrl(actor);
}

void func_808003A0_chquizremotectrl(s32 arg0)
{
}

void func_808003A8_chquizremotectrl(Actor *actor)
{
    func_800CEA38(0, 1);
    func_800EFA4C(actor->position, 0.0f, 0.0f, 0.0f);
    actor->rotation[2] = 0.0f;
    actor->rotation[0] = 0.0f;
    actor->rotation[1] = 0.0f;
    func_808001BC_chquizremotectrl(actor, 1);
}

void func_80800410_chquizremotectrl(Actor *actor, s32 gfx)
{
    f32 unk_0;
    f32 cam_pos[3];
    f32 cam_rot[3];

    _suquiz_entrypoint_13(cam_pos);
    _suquiz_entrypoint_14(cam_rot);
    func_800EF214(cam_pos, -cam_rot[0], cam_rot[1],
                  ((Mass45QuizDisplay *) actor)->unk_54 *
                      ((Mass45QuizDisplay *) actor)->unk_24);
    switch (actor->unk70_10) {
        case 1:
            unk_0 = func_800F10B4(((f32 *) actor->actorData)[7], 1.0f, 0.0f, 1.0f, 0.0f);
            D_80800664_chquizremotectrl = unk_0 * 360.0f;
            break;
        case 2:
            unk_0 = 0.0f;
            break;
        case 3:
            unk_0 = func_800F10B4(((f32 *) actor->actorData)[7], 1.0f, 0.0f, 0.0f, 1.0f);
            D_80800664_chquizremotectrl = unk_0 * 360.0f;
            break;
        case 4:
        case 5:
            unk_0 = 1.0f;
            D_80800664_chquizremotectrl = 0.0f;
    }
    func_800E41CC();
    func_800E3C8C(50.0f, 2000.0f);
    func_800E39D8(cam_pos, cam_rot);
    func_800E3CE8();
    func_800E44FC(gfx);
    func_800E7C28(gfx);
    func_800E7CF4(gfx);
    if (unk_0 > 0.0f) {
        func_800DE498(gfx, D_80800650_chquizremotectrl, D_8080065C_chquizremotectrl, unk_0, 0,
                      func_800D674C(0x9A1));
    }
    func_80101870(actor, gfx);
    func_800E4208();
    func_800E44FC(gfx);
}

s32 func_808005E4_chquizremotectrl(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0xB)
        return 3;
    return 0;
}

int *chquizremotectrl_entrypoint_0()
{
    return &D_80800668_chquizremotectrl;
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/quizremotectrl.data.s) is defined here in C.
// Its tables point to functions of this file; IDO's assembler schedules some of them differently unless
// the tables are in the same unit. Values are taken from the ROM. D_80800668_chquizremotectrl is declared
// as int[] at the same address.
extern void func_80105834();
extern void func_80107C2C();
u8 D_80800650_chquizremotectrl[12] = {0x0,  0x0, 0x0,  0x0,  0x44, 0xC,
                                      0xA0, 0x0, 0xC4, 0x8C, 0xA0, 0x0};
u8 D_8080065C_chquizremotectrl[8] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
f32 D_80800664_chquizremotectrl = 0.0f;
int D_80800668_chquizremotectrl[18] = {0x1580217,
                                       0x9A00001,
                                       0x0,
                                       (u32) func_808002C8_chquizremotectrl,
                                       (u32) func_80105834,
                                       (u32) func_80800410_chquizremotectrl,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x400404,
                                       (u32) func_808003A0_chquizremotectrl,
                                       0x0,
                                       0x0,
                                       (u32) func_808003A8_chquizremotectrl,
                                       (u32) func_80107C2C,
                                       -0x7FFFFFFE,
                                       (u32) func_808005E4_chquizremotectrl,
                                       0x0};
