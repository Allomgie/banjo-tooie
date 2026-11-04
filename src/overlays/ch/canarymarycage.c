#include "common.h"

extern void func_80101FDC();
extern u8 D_8080061C_chcanarymarycage[];
extern u8 D_80800610_chcanarymarycage[];
extern void func_8010D5DC(void);
extern s32 func_800EFFB4(f32 *, f32, void *);
extern void func_800F4AC0(s32, void *, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_8008FB10(f32 *, f32, f32, f32);
extern void func_8008FAC8(f32 *, f32, f32, f32);
extern s16 D_80800668_chcanarymarycage[];
extern u8 D_80800628_chcanarymarycage[];
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern void *func_80100094(Actor *, u32);
extern void *func_80101080(void);
extern void *func_80106790(void *);
extern void *_subaddielink_entrypoint_4();
extern void _chexploder_entrypoint_6(void *, f32, f32);
extern int D_80800674_chcanarymarycage[];
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_8010A730(),
    func_8080018C_chcanarymarycage(), func_80800284_chcanarymarycage();

void func_80800000_chcanarymarycage(Actor *actor, s32 state)
{
    f32 pos[3];
    s32 player_count;
    func_80101FDC(actor, state);
    switch (actor->unk70_10) {
        case 2:
            break;
        case 3:
            for (state = 0, player_count = 8; state != player_count; state++) {
                if (func_800F6438(state)) {
                    func_800F5A00(state, pos);
                    if (func_800EFFB4(pos, 420.0f, D_80800610_chcanarymarycage)) {
                        func_800F497C(state);
                        func_800F49A8(state, 1);
                        func_800F4A00(state, 1);
                        func_800F49D4(state, func_8010D5DC, actor->unk0);
                        func_800F4AC0(state, D_8080061C_chcanarymarycage, 200.0f);
                        actor->unk79_4++;
                    }
                }
            }
            if (actor->unk79_4 == 0)
                func_80800000_chcanarymarycage(actor, 4);
            break;
        case 4:
            func_800DA3B8(0, 1);
            func_8010A570(actor);
    }
}

void func_8080018C_chcanarymarycage(actor) Actor *actor;
{
    switch (actor->unk70_10) {
        case 1:
            func_800EEB9C((f32 *) ((u8 *) actor + 0x18), actor->rotation[1] + 180.0f, 60.0f);
            func_800EF04C((f32 *) ((u8 *) actor + 0x18), actor->position);
            func_8008FB10((f32 *) ((u8 *) actor + 0x18), 440.0f, 0.0f, 280.0f);
            func_800EEB9C((f32 *) ((u8 *) actor + 0x18), actor->rotation[1], 145.0f);
            func_800EF04C((f32 *) ((u8 *) actor + 0x18), actor->position);
            ((f32 *) ((u8 *) actor + 0x18))[1] += 150.0f;
            func_8008FAC8((f32 *) ((u8 *) actor + 0x18), 150.0f, 300.0f, 50.0f);
            break;
        case 2:
            func_80800000_chcanarymarycage(actor, 3);
        case 4:
            break;
    }
}

void func_80800284_chcanarymarycage(actor) s32 actor;
{
    s32 sp1C;

    sp1C = func_80100094(actor, 0);

    if ((func_800DA298(0x66) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_80800000_chcanarymarycage(actor, 4);
    }

    _subaddielink_entrypoint_0(sp1C);
}

int func_808002E0_chcanarymarycage(actor)
Actor *actor;
{
    if (!func_800DB9B0()) {
        if (func_800DA298(1) && !func_800DA298(0x507)) {
            func_800DA544(0x66);
            func_800DA544(0x507);
        }
    }
}

// Cage hit: debris, sound, sets the cage-broken flag (1).
void func_80800338_chcanarymarycage(Actor *actor, Actor **hit_by)
{
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800668_chcanarymarycage);
    func_800EEB9C((f32 *) actor->actorData, actor->rotation[1] - 100.0f, 300.0f);
    ((f32 *) actor->actorData)[1] = 180.0f;
    func_800EF04C(actor->actorData, actor->position);
    func_800BBCB8((f32 *) actor->actorData, 0, 1.0f, 10, D_80800628_chcanarymarycage);
    _chexploder_entrypoint_4(actor, (*hit_by)->position, 0x44);
    actor->unk64_16 = 1;
    func_800DA544(1);
    func_80800000_chcanarymarycage(actor, 2);
}

s32 func_80800410_chcanarymarycage(Actor *actor, s32 msg, Actor **data)
{
    void *link;
    void *exploder;
    void *linked;
    void *info;

    link = func_80100094(actor, 0);

    switch (msg) {
        case 0x90:
            exploder = func_80106790(func_80101080());
            _chexploder_entrypoint_9(exploder, 1, 0);
            _chexploder_entrypoint_9(exploder, 2, 1);
            _chexploder_entrypoint_9(exploder, 3, 0);
            _chexploder_entrypoint_6(exploder, 200.0f, 300.0f);
            _subaddielink_entrypoint_1(link, *(s32 *) exploder);
            break;
        case 0xAB:
            linked = _subaddielink_entrypoint_4(link);
            info = func_80101080();
            func_801018A4(actor, info);
            // Matching: empty block steers IDO's register allocation.
            if (1) {
            }
            if (linked != NULL) {
                func_8010114C(*(void **) linked, 0xAB, 0);
            }
            break;
        case 0x1F:
            func_801015D0(actor);
            if (actor->unk70_10 == 1) {
                func_800DF744(1, 1);
            } else {
                func_800DF744(1, 2);
            }
            func_800DF744(2, 0);
            func_800DF744(3, 1);
            break;
        case 0x32:
            actor->unk79_4--;
            if (actor->unk79_4 == 0) {
                func_80800000_chcanarymarycage(actor, 4);
            }
            break;
        case 0x40:
            if (!func_80090270(link)) {
                func_80800338_chcanarymarycage(actor, *(Actor ***) &data);
            }
            break;
        default:
            return 0;
    }

    return 1;
}

int chcanarymarycage_entrypoint_0()
{
    return (int) &D_80800674_chcanarymarycage;
}

// TU-NOTE: the overlay .data is defined in this file. Its tables point to functions here, and
// IDO's assembler schedules some of them differently unless the tables are in the same unit.
u8 D_80800610_chcanarymarycage[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44, 0xC7, 0x0, 0x0};
u8 D_8080061C_chcanarymarycage[12] = {0x43, 0x11, 0x0,  0x0,  0xC1, 0x80,
                                      0x0,  0x0,  0x43, 0xC3, 0x0,  0x0};
u8 D_80800628_chcanarymarycage[64] = {
    0x0,  0x1D, 0x9,  0xDC, 0x0, 0x19, 0x0, 0x1,  0x0, 0x6,  0x23, 0x2,  0x0,  0xA,  0xFF, 0x6A,
    0xFF, 0x38, 0xFF, 0x6A, 0x0, 0x96, 0x0, 0x32, 0x0, 0x96, 0x0,  0x2C, 0xFF, 0xB0, 0x0,  0x60,
    0xFF, 0xB0, 0x0,  0x50, 0x0, 0xD8, 0x0, 0x50, 0x0, 0x22, 0x2,  0x0,  0x4,  0x0,  0x2,  0x0,
    0x3,  0x0,  0x0,  0x2B, 0x4, 0x0,  0x7, 0x0,  0x0, 0x16, 0x0,  0x4,  0x0,  0x0,  0x0,  0x0};
s16 D_80800668_chcanarymarycage[6] = {0x13, 0x4C8, 0x16, 0x7D00, 0x0, 0x0};
int D_80800674_chcanarymarycage[19] = {0x25A0176,
                                       0x67D0001,
                                       0x0,
                                       (u32) func_8080018C_chcanarymarycage,
                                       (u32) func_80105834,
                                       (u32) func_8010A730,
                                       0x9C40000,
                                       0x0,
                                       0x0,
                                       0x80C04,
                                       (u32) func_808002E0_chcanarymarycage,
                                       (u32) func_80108ED0,
                                       0x80000,
                                       (u32) func_80800284_chcanarymarycage,
                                       (u32) func_80107C2C,
                                       -0x7FFFE000,
                                       (u32) func_80800410_chcanarymarycage,
                                       0x0,
                                       0x0};
