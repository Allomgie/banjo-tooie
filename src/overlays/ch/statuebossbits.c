// Probably the helper actors of the Targitzan fight (four ActorInfo getters): the dart he shoots,
// the shields that rise from the floor and break after three hits, and the arena door.
#include "common.h"

extern int D_808006F0_chstatuebossbits[];
extern int D_80800738_chstatuebossbits[];
extern int D_80800780_chstatuebossbits[];
extern s32 D_808007C8_chstatuebossbits[];
extern int D_80800810_chstatuebossbits[];
extern int D_8080084C_chstatuebossbits[];
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, void *, void *, f32);
typedef struct {
    u8 pad_0[0x54];
    s32 local_0;
} StatueBossSelector;
extern u8 D_8080085C_chstatuebossbits[];
typedef union {
    s32 word;
    s16 half;
} StatueBitsPayload31;
extern s32 D_80800864_chstatuebossbits[];
extern void func_800EC398(s32, f32 *);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void func_80109FB8();
extern f32 func_800D8FF8(void);
extern Actor *func_80106790(void *);
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
void func_80800270_chstatuebossbits();
void func_80800604_chstatuebossbits();

// Registration of the four part actor kinds (ActorInfo getters).
int chstatuebossbits_entrypoint_0()
{
    return (int) &D_808006F0_chstatuebossbits;
}

int chstatuebossbits_entrypoint_1()
{
    return (int) &D_80800738_chstatuebossbits;
}

int *chstatuebossbits_entrypoint_2()
{
    return &D_80800780_chstatuebossbits;
}

int chstatuebossbits_entrypoint_3()
{
    return D_808007C8_chstatuebossbits;
}

// Arena door via chdoormake (open when flag 0x88 or in a cutscene); empty update.
void func_80800030_chstatuebossbits(s32 arg0)
{
}

// Dart: flies with roll spin, collides, sends 0x40 to shield 0x449, impact effects, fade-out.
// Dart Targitzan shoots: spins, hits player or shield, then fades.
void func_80800038_chstatuebossbits(Actor *dart)
{
    s32 hit;
    s32 shield_done;
    Actor *target;
    s32 finished;
    s32 spin_dir;

    switch (dart->unk70_10) {
        case 1:
            *(s32 *) &dart->unk3C = 0;
            func_800EA600(func_80109FB8, dart->unk0);
            hit = func_8010B990(dart, 0x100005);
            func_800EA614();
            dart->rotation[2] += func_800D8FF8() * 150.0f;
            if (hit) {
                shield_done = 0;
                if (*(void **) &dart->unk3C) {
                    target = func_80106790(*(void **) &dart->unk3C);
                    if (target->unk6C_9 == 0x449) {
                        func_8010108C(target, 0x40, dart->unk0);
                        if (*(s32 *) &target->unk54 >= 3) {
                            shield_done = 1;
                        }
                    }
                }
                func_800EF1B8(dart->position, dart->rotation[1] + 180.0f, 100.0f);
                func_80800270_chstatuebossbits(dart);
                func_8010A570(dart);
                if (shield_done) {
                    func_80101FDC(dart, 3);
                    _subaddiefade_entrypoint_3(dart);
                } else {
                    func_80101FDC(dart, 2);
                    dart->unk58 = 1.4f;
                }
            }
            break;
        case 2:
            finished = func_800D9078(&dart->unk58);
            spin_dir = func_8001210C(1) ? -1 : 1;
            dart->rotation[0] =
                func_800F10B4(dart->unk58, 0.0f, 1.4f, 0.0f, 10.0f) * (f32) spin_dir;
            if (finished) {
                _subaddiefade_entrypoint_3(dart);
            }
    }
}

int func_80800224_chstatuebossbits(s32 *actor, s32 msg, s32 param_2)
{
    if (msg == 0x40) {
        func_80800270_chstatuebossbits();
        func_800FFA88(actor[0]);
    } else {
        return 0;
    }
    return 1;
}

void func_80800270_chstatuebossbits(actor) u8 *actor;
{
    func_800BBCB8(actor + 4, 0, *(s32 *) (actor + 0x38), 2, &D_80800810_chstatuebossbits);
    func_8010D930(4, -1, actor + 4, &D_8080084C_chstatuebossbits);
}

// Shield/cover block: rises on message 7, damage parts by hit count, breaks after 3 hits.
// Shield init: rises from the floor unless the boss was already beaten/retried.
void func_808002CC_chstatuebossbits(Actor *shield)
{
    s32 retry;
    retry = func_800DA298(0x88);
    func_800EE7F8((f32 *) shield->actorData, shield->position);
    func_800EE7F8((f32 *) (shield->actorData + 4), shield->position);
    ((f32 *) shield->actorData)[5] -= 180.0f;
    *(s32 *) &shield->unk54 = 0;
    if (retry) {
        func_80101FDC(shield, 1);
        func_8010A590(shield);
    } else
        shield->position[1] = ((f32 *) shield->actorData)[5];
}

// Shield update: rises to its home position.
void func_80800360_chstatuebossbits(Actor *shield)
{
    s32 finished;

    switch (shield->unk70_10) {
        case 1:
        case 2:
            break;
        case 3:
            finished = func_800D9078(&shield->unk58);
            func_800EFE50(shield->position, &shield->actorData[4], shield->actorData,
                          func_800F12D4(shield->unk58, 0.0f, 3.0f, 1.0f, 0.0f));
            if (finished) {
                func_80101FDC(shield, 1);
                func_80103110(shield, 0);
                func_8010A590(shield);
            }
    }
}

void func_8080040C_chstatuebossbits(Actor *shield, s32 param_1)
{
    func_800DF744(1, ((StatueBossSelector *) shield)->local_0 == 0 ? 1 : 0);
    func_800DF744(2, ((StatueBossSelector *) shield)->local_0 == 1 ? 1 : 0);
    func_800DF744(3, ((StatueBossSelector *) shield)->local_0 == 2 ? 1 : 0);
    func_800DF744(4, ((StatueBossSelector *) shield)->local_0 == 3 ? 1 : 0);
    func_800DF744(5, 0);
    func_80101870(shield, param_1);
}

s32 func_808004D8_chstatuebossbits(Actor *shield, s32 msg, StatueBitsPayload31 payload)
{
    s32 hit_info;
    s32 pad;

    switch (msg) {
        case 0x40:
            hit_info = *(s32 *) &payload;
            (*(s32 *) &shield->unk54)++;
            func_80800604_chstatuebossbits(shield, hit_info);
            if (*(s32 *) &shield->unk54 >= 3) {
                func_800EC398(hit_info, shield->actorData);
                *(f32 *) &shield->actorData[1] = shield->position[1];
                _chexploder_entrypoint_3(shield, shield->actorData, 12);
                _subaddieaudioquick_entrypoint_2(shield, shield->position,
                                                 D_8080085C_chstatuebossbits);
            }
            break;
        case 7:
            func_80101FDC(shield, 3);
            func_80103110(shield, 1);
            shield->unk58 = 3.0f;
            break;
        case 0x90:
            shield = func_80106790(func_80101080());
            _chexploder_entrypoint_9(shield, 2, 0);
            _chexploder_entrypoint_9(shield, 5, 1);
            return 1;
        default:
            return 0;
    }
    return 1;
}

void func_80800604_chstatuebossbits(unk_0, hit_info) s32 unk_0;
s32 hit_info;
{
    f32 pos[3];
    func_800EC398(hit_info, pos);
    func_800BBCB8(pos, pos, 0x3F800000, 4, &D_80800864_chstatuebossbits);
}

void func_8080064C_chstatuebossbits(Actor *door)
{
    s32 open;
    open = func_800DA298(0x88) || _glcutDll_entrypoint_20();
    if (open)
        func_80101FDC(door, 1);
    _chdoormake_entrypoint_3(door, 0.0f, 90.0f, 180.0f, 0x102, -1);
    _chdoormake_entrypoint_5(door, 2.0f);
    _chdoormake_entrypoint_8(door, 13);
}

extern void func_80105834();
extern int func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
extern void _chdoor_entrypoint_1();
extern void func_80102EC0();
extern void func_8010A73C();
int D_808006F0_chstatuebossbits[18] = {0x1610448,
                                       0x6640001,
                                       0x0,
                                       (u32) func_80800038_chstatuebossbits,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x4,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_80800030_chstatuebossbits,
                                       (u32) func_80107C2C,
                                       -0x7FC00000,
                                       (u32) func_80800224_chstatuebossbits,
                                       0x0};
int D_80800738_chstatuebossbits[18] = {0x2A20449,
                                       0x7C20002,
                                       0x0,
                                       (u32) func_80800360_chstatuebossbits,
                                       (u32) func_80105834,
                                       (u32) func_8080040C_chstatuebossbits,
                                       0x0,
                                       0x0,
                                       0x36F0000,
                                       0xC00,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_808002CC_chstatuebossbits,
                                       (u32) func_80107C2C,
                                       -0x7FF7F3FE,
                                       (u32) func_808004D8_chstatuebossbits,
                                       0x0};
int D_80800780_chstatuebossbits[18] = {0xAC0450,
                                       0x83F0004,
                                       0x0,
                                       (u32) _chdoor_entrypoint_0,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x36F0000,
                                       0x800,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_8080064C_chstatuebossbits,
                                       (u32) func_80107C2C,
                                       -0x7FF7D3FE,
                                       (u32) _chdoor_entrypoint_1,
                                       0x0};
s32 D_808007C8_chstatuebossbits[18] = {0x158044F,
                                       0x7C30001,
                                       0x0,
                                       (u32) func_80102EC0,
                                       (u32) func_80105834,
                                       (u32) func_8010A73C,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0xC00,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80107C2C,
                                       -0x7FFFF3FE,
                                       0x0,
                                       0x0};
int D_80800810_chstatuebossbits[15] = {0x160004, 0x1D09C9, 0x20DCDC, -0x235FFFDE, 0x330066,
                                       0x9900CC, 0x2B004C, 0x800015, 0x19004C,    0x2CFFCE,
                                       0x3CFFCE, 0x320064, 0x32000E, 0x5000A,     0x0};
int D_8080084C_chstatuebossbits[4] = {0x130407, 0x1632C8, 0xD01B3, 0x1CC0000};
u8 D_8080085C_chstatuebossbits[8] = {0x0, 0x13, 0x4, 0xF4, 0x0, 0x18, 0x0, 0x0};
s32 D_80800864_chstatuebossbits[11] = {0x1D0652,   0x14002D, 0x1900258, 0x1BFCE0,
                                       -0x257FFDE, 0x260033, 0x140019,  0xE0014,
                                       0x1E0005,   0x0,      0x0};
