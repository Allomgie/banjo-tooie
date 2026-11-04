#include "common.h"

extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x18];
    s32 section_id;
    u8 pad_1C[0x5C];
    u32 pad_78 : 29;
    u32 flag : 1;
    u32 rest : 2;
} HiveS;
extern s32 _subaddiesect_entrypoint_0(HiveS *, s32, s32);
extern u8 D_808002F0_chbeehive[];
extern u8 D_80800300_chbeehive[];
extern u8 D_80800320_chbeehive[];
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern u8 D_80800364_chbeehive[];
extern u8 func_800C2E04(void);
extern void func_800C301C();
extern void func_800C3584(u8, f32, f32);
extern void func_800C31DC(u8, f32);
extern f32 func_80101F24(Actor *);
extern int D_80800374_chbeehive[];
void func_80800180_chbeehive();

// Init: looks up the su/baddie section and registers the hive in it.
void func_80800000_chbeehive(Actor *actor)
{
    s32 section;
    func_800EE7F8((f32 *) &actor->actorData[4], actor->position);
    actor->unk50 = actor->rotation[1];
    section = _subaddiesect_entrypoint_1(actor);
    actor->actorData[0] = section;
    actor->unk74_7 = (u16) (actor->unk74_7 - 0x32);
    if (section != -1) {
        _subaddiesect_entrypoint_2(actor, section, 0);
    }
}

// Update: plays the buzz while the hive's section is visible.
void func_80800078_chbeehive(HiveS *hive)
{
    if (!hive->flag) {
        if (hive->section_id == -1 || _subaddiesect_entrypoint_0(hive, hive->section_id, 0xB)) {
            func_80800180_chbeehive(hive);
        }
    }
}

// Hit: burst into particles, notify the parent, drop honeycomb.
void func_808000CC_chbeehive(Actor *actor, Actor **attacker)
{
    f32 drop_pos[3];

    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808002F0_chbeehive);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800300_chbeehive);
    func_800BBCB8(actor->position, 0, actor->scale, 1, D_80800320_chbeehive);
    if (actor->unk3C)
        func_8010114C(actor->unk3C, 0x53, 0);
    func_800EE88C(drop_pos, (*attacker)->position);
    drop_pos[1] = actor->position[1];
    _chexploder_entrypoint_3(actor, drop_pos, 0x2C);
}

// Looping bee buzz, timed to the animation.
// Matching: K&R-style definition, needed for the match.
void func_80800180_chbeehive(actor) Actor *actor;
{
    if (func_80101E4C(actor, D_80800364_chbeehive)) {
        if (actor->unk5F == 0) {
            actor->unk5F = func_800C2E04();
            func_800C301C(actor->unk5F, 0x447);
            func_800C3058(actor->unk5F, 12000);
            func_800C35E8(actor->unk5F, actor->position);
            func_800C3584(actor->unk5F, 300.0f, 1500.0f);
        }
        if (actor->unk5F != 0) {
            func_800C3CE8(actor->unk5F);
            func_800C31DC(actor->unk5F, func_80101F24(actor) + 0.5f);
            func_800C330C(actor->unk5F, 3);
            _subaddieaudioquick_entrypoint_0(actor->unk5F, *(u32 *) ((u8 *) actor + 0x70) & 1);
            func_800C3BDC(actor->unk5F);
        }
    }
}

s32 func_80800268_chbeehive(Actor *actor, s32 msg, s32 msg_data)
{
    switch (msg) {
        case 0x40: // hit by egg or attack
            func_808000CC_chbeehive(actor, msg_data);
            break;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(3, 1);
        case 0x90:
            break;
        default:
            return 0;
    }
    return 1;
}

int chbeehive_entrypoint_0()
{
    return &D_80800374_chbeehive;
}

// TU-NOTE: the overlay .data is defined in C here; its tables point to functions of this file,
// and IDO schedules some of them differently unless the tables are in the same unit.
extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_808002F0_chbeehive[16] = {0x0, 0x13, 0x4,  0xB,  0x0, 0xA, 0x1, 0x0,
                               0x0, 0x16, 0x6D, 0x60, 0x0, 0x0, 0x0, 0x0};
u8 D_80800300_chbeehive[16] = {0x0, 0x13, 0x4,  0x7,  0x0, 0xA, 0x1, 0x0,
                               0x0, 0x16, 0x6D, 0x60, 0x0, 0x0, 0x0, 0x0};
u32 D_80800310_chbeehive[4] = {0x0, 0x0, 0x3F266666, 0x540001};
u8 D_80800320_chbeehive[68] = {0x0, 0x1D, 0x9, 0xC9, 0x0,  0x16, 0x2,  0x38, 0x0, 0x15, 0x0, 0x13,
                               0x0, 0x66, 0x0, 0x20, 0xFA, 0xFA, 0xFA, 0x78, 0x0, 0x1E, 0x0, 0xA,
                               0x0, 0x14, 0x0, 0x2C, 0x0,  0x0,  0x0,  0x14, 0x0, 0x0,  0x0, 0x0,
                               0x0, 0x32, 0x0, 0x0,  0x0,  0x2B, 0x1,  0x33, 0x1, 0x66, 0x0, 0x22,
                               0x2, 0x0,  0x2, 0x80, 0x4,  0x0,  0x4,  0x80, 0x0, 0x18, 0x0, 0x0,
                               0x0, 0x0,  0x0, 0x80, 0x0,  0x80, 0x0,  0x0};
u8 D_80800364_chbeehive[16] = {0x3E, 0xE6, 0x66, 0x66, 0x3F, 0xC,  0xCC, 0xCD,
                               0x3F, 0x19, 0x99, 0x9A, 0xBF, 0x80, 0x0,  0x0};
int D_80800374_chbeehive[19] = {0x500211,
                                0x6150001,
                                (u32) &D_80800310_chbeehive,
                                (u32) func_80800078_chbeehive,
                                (u32) func_80105834,
                                (u32) func_801018A4,
                                0x7D00000,
                                0x0,
                                0x0,
                                0x42008908,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800000_chbeehive,
                                (u32) func_80107C2C,
                                -0x7FD7CFEC,
                                (u32) func_80800268_chbeehive,
                                0x0,
                                0x0};
