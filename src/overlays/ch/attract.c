// Probably the attract-mode (title/demo) actor 0x4B5, one per scripted step. A data table gives
// model, start position, scale, spin and fade timings; the actor plays that and despawns.
#include "common.h"

extern void *D_808004F4_chattract;
extern u8 D_8080046A_chattract[];
extern u8 D_8080046C_chattract[];
extern u8 D_80800470_chattract[];
extern f32 func_800D8FF8(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_801015D0(void);
extern void func_800DF944(void *, f32 *, f32, f32, s32, s32, s32);
typedef struct {
    u16 unk_0;
    u8 unk_2;
    u8 pad_3;
    f32 unk_4;
    f32 unk_8;
    f32 scale;
    s16 pos_x;
    s16 pos_y;
    f32 rot_speed;
    u8 unk_18;
    u8 pad_19[3];
} AttractEntry26;
typedef struct {
    u8 pad_0[0x7A];
    u8 unk_7A : 2;
    u8 pad_7A : 6;
} AttractFlags26;
extern AttractEntry26 D_80800468_chattract[];
extern void _subaddiefade_entrypoint_2(Actor *);
extern void _chattract_entrypoint_2(void);
extern void _chbaddiesetup_entrypoint_1(void *, s32);
typedef struct {
    u8 pad_0[0x12];
    u16 type : 15;
    u16 enabled : 1;
} AttractMarkerType;
extern Actor *func_80108454(s32, f32 *, s32);

void *chattract_entrypoint_0()
{
    return &D_808004F4_chattract;
}

void func_8080000C_chattract(s32 unk_0)
{
}

void func_80800014_chattract(Actor *actor)
{
    u8 *entry;

    if (actor->unk54 != 0.0f) {
        actor->rotation[1] += actor->unk54 * func_800D8FF8();
    }
    if (actor->unk79_4) {
        if ((*(u16 *) ((u8 *) actor + 0x78) & 3) == 0 && func_800D9078(&actor->unk58)) {
            if (D_8080046A_chattract[actor->unk74_7 * 28]) {
                _subaddiefade_entrypoint_2(actor);
            } else {
                _subaddiefade_entrypoint_1(actor, 255);
            }
            actor->unk58 = *(f32 *) (D_8080046C_chattract + actor->unk74_7 * 28);
            actor->unk79_4 = 0;
            func_80102424(actor, actor->unk70_10);
        }
    } else {
        if ((*(u16 *) ((u8 *) actor + 0x78) & 3) == 0 && func_800D9078(&actor->unk58)) {
            entry = (u8 *) D_80800468_chattract + actor->unk74_7 * 28;
            if (*(f32 *) (entry + 8) != 0.0f) {
                if (entry[3]) {
                    _subaddiefade_entrypoint_5(actor);
                } else {
                    _subaddiefade_entrypoint_1(actor, 0);
                }
                actor->unk58 = *(f32 *) (D_80800470_chattract + actor->unk74_7 * 28);
                actor->unk79_4 = 1;
            } else if (entry[3]) {
                _subaddiefade_entrypoint_3(actor);
            } else {
                func_800FFAB0(actor);
            }
        }
    }
}

void func_80800204_chattract(Actor *actor, void *unk_1)
{
    f32 rot[3];
    if (actor->rotation[1] != 0) {
        func_800EFA4C(rot, 0.0f, actor->rotation[1], 0.0f);
        func_800DF4CC(rot);
    }
    func_800DF410(actor->alpha);
    func_800DF47C(func_801015D0, actor);
    func_800DF944(unk_1, actor->position, 0.0f, actor->scale, 0, 1,
                  func_8010347C(actor->unk0));
}

s32 func_808002AC_chattract(Actor *actor, s32 event, s32 unk_2)
{
    AttractEntry26 *entry;

    if (event == 0x95) {
        entry = &D_80800468_chattract[actor->unk74_7];
        func_80103140(actor, entry->unk_0, 0);
        func_80102424(actor, actor->unk74_7);
        actor->unk58 = entry->unk_4;
        actor->scale = entry->scale;
        ((AttractFlags26 *) actor)->unk_7A = entry->unk_18;
        if (entry->unk_2) {
            _subaddiefade_entrypoint_2(actor);
        }
        actor->position[0] = entry->pos_x;
        actor->position[1] = entry->pos_y;
        actor->unk54 = entry->rot_speed;
        actor->unk79_4 = 0;
        return 1;
    }
    return 0;
}

void chattract_entrypoint_1(s32 unk_0)
{
    _chbaddiesetup_entrypoint_1(_chattract_entrypoint_2, unk_0);
}

// TU-NOTE: .bss is defined in C ahead of its first use; IDO places bss objects used before
// their definition first, the rest in definition order.
f32 B_80800540_chattract[4];

void chattract_entrypoint_2(s32 index)
{
    Actor *marker;

    marker = func_80108454(0x4B5, B_80800540_chattract, 0);
    if (marker != NULL) {
        marker->unk74_7 = index + 1;
        ((AttractMarkerType *) marker->unk0)->type = 1;
        func_800EC828();
    }
}

// TU-NOTE: .data is defined here in C (values from the ROM). The tables point to functions
// of this file, and IDO's assembler schedules some of them differently unless the tables are
// in the same unit. Linker symbols (undefined_syms.us.txt) inside D_80800468_chattract:
// D_8080046A_chattract = +0x2, D_8080046C_chattract = +0x4, D_80800470_chattract = +0x8.
extern void func_80102EC0();
extern void func_80107C2C();
u32 D_80800440_chattract[10] = {0x0,       0x0, 0x0, 0x0,        0x3FCCCCCD,
                                0x284004A, 0x0, 0x0, 0x3F8CCCCD, 0x286004A};
AttractEntry26 D_80800468_chattract[5] = {
    0x0,   0x0, 0x0, 0.0f, 0.0f, 0.0f,  0x0,   0x0,  0.0f,     0x0, 0x0, 0x0, 0x0,
    0x8A8, 0x1, 0x1, 2.5f, 0.0f, 0.14f, 0x98,  0x5E, 0.0f,     0x1, 0x0, 0x0, 0x0,
    0x85A, 0x0, 0x1, 5.0f, 2.0f, 0.2f,  0x98,  0xAB, 0.0f,     0x0, 0x0, 0x0, 0x0,
    0x859, 0x1, 0x0, 0.0f, 0.0f, 0.1f,  0x112, 0xC6, 2.8e+02f, 0x0, 0x0, 0x0, 0x0,
    0x85B, 0x0, 0x1, 5.0f, 2.0f, 0.2f,  0x98,  0xAB, 0.0f,     0x0, 0x0, 0x0, 0x0};
void *D_808004F4_chattract = (void *) 0x015804B5;
static u32 D_808004F4_chattract_rest[18] = {0x2,
                                            (u32) &D_80800440_chattract,
                                            (u32) func_80800014_chattract,
                                            (u32) func_80102EC0,
                                            (u32) func_80800204_chattract,
                                            0x0,
                                            0x0,
                                            0x0,
                                            0x8400404,
                                            0x0,
                                            0x0,
                                            0x0,
                                            (u32) func_8080000C_chattract,
                                            (u32) func_80107C2C,
                                            0x80000002,
                                            (u32) func_808002AC_chattract,
                                            0x0,
                                            0x0};
