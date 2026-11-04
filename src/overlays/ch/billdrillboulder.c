// Probably the boulders Bill Drill can break (three actor kinds), each remembered as broken by a
// per-instance flag. One variant hides a reward; one instance also knocks the player back.
#include "common.h"

extern int D_80800540_chbilldrillboulder[];
extern void *D_80800588_chbilldrillboulder;
extern int D_808005D0_chbilldrillboulder[];
extern u8 _chbaddiesetup_entrypoint_9[];
extern u8 D_80800684_chbilldrillboulder[];
extern u8 D_80800618_chbilldrillboulder[];
extern u8 D_808006F0_chbilldrillboulder[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern f32 func_80103EF4(Actor *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void _chbaddiesetup_entrypoint_4(void *, s32, s32, s32, s32);
s32 func_808004D4_chbilldrillboulder();

int chbilldrillboulder_entrypoint_0()
{
    return (int) &D_80800540_chbilldrillboulder;
}

int chbilldrillboulder_entrypoint_1()
{
    return &D_80800588_chbilldrillboulder;
}

int chbilldrillboulder_entrypoint_2()
{
    return (int) &D_808005D0_chbilldrillboulder;
}

// Break: effects, sets the broken flag, spawns the reward.
// Matching: K&R-style definition, needed for the match.
void func_80800024_chbilldrillboulder(actor) Actor *actor;
{
    s32 flag_id;
    f32 *pos;
    u8 *effect;
    f32 knock_pos[3];
    s32 id;
    f32 spawn_pos[3];
    flag_id = func_808004D4_chbilldrillboulder((u8 *) actor);
    id = actor->unk6C_9;
    pos = actor->position;
    if (!(id ^ 0x322))
        effect = D_80800684_chbilldrillboulder;
    else
        effect = D_80800618_chbilldrillboulder;
    func_800BABB8(0, pos, pos, actor->scale, effect);
    _subaddieaudioquick_entrypoint_2(actor, pos, D_808006F0_chbilldrillboulder);
    if (flag_id) {
        func_800DA544(flag_id);
        // Special boulder: knocks the player back and triggers an event on actor 0x117.
        if (flag_id == 0x514) {
            if (actor->unk64_20) {
                func_800EE7F8(knock_pos, pos);
                func_800EF1B8(knock_pos, actor->rotation[1] - 70.0f, 450.0f);
                func_800F77E8(func_800F54E4(), knock_pos);
            }
            func_800F7F98(func_800F54E4(), 1);
            _capod_entrypoint_21(_subaddiefind_entrypoint_2(0x117, 0)->unk0, 0, 0x1D, 0);
            func_800DA544(0x5B);
        }
    }
    // Model 0x3CF hides a reward: a collectible or a spawned item.
    if (actor->unk6C_9 == 0x3CF) {
        id = -1;
        switch (actor->unk74_7) {
            case 0x33:
                func_800D1000(actor->unk6C_0, 4, pos, 0, 0);
                break;
            case 0x34:
                id = 2;
                break;
            case 0x35:
                id = 0x15;
                break;
            case 0x36:
                id = 0x16;
                break;
            case 0x37:
                id = 0x17;
                break;
            case 0x38:
                func_800D1000(actor->unk6C_0, 2, pos, 0, 0);
                break;
        }
        if (id != -1) {
            func_800EE7F8(spawn_pos, pos);
            spawn_pos[1] += 0.5f * func_80103EF4(actor);
            _chbaddiesetup_entrypoint_4(&_chbaddiesetup_entrypoint_9, id, ((s32 *) spawn_pos)[0],
                                        ((s32 *) spawn_pos)[1], ((s32 *) spawn_pos)[2]);
        }
    }
}

// Matching: the redundant masks and shift in the condition are needed for the match.
int func_8080026C_chbilldrillboulder(Actor *actor)
{
    if (((((((((((*(u16 *) ((char *) actor + 0x72) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) &
               0xFFFFFFFFu) &
              0xFFFFFFFFu) &
             0xFFFFFFFFu) &
            0xFFFFFFFFu) &
           0xFFFFFFFFu) &
          0xFFFFFFFFu) >>
         (10 & 0xFFFFFFFFFFFFFFFFu)) == 2) {
        if (_subaddieDll_entrypoint_6(actor, 0xB)) {
            func_8010A570(actor);
            _chexploder_entrypoint_3(actor, (Actor *) ((char *) actor + 4), 2);
        }
    }
}

// Init: removes the boulder if its flag is already set; looks up the reward prop.
void func_808002C4_chbilldrillboulder(Actor *actor)
{
    s32 flag_id;
    s32 variant;

    flag_id = func_808004D4_chbilldrillboulder();
    if ((flag_id != 0) && (func_800DA298(flag_id) != 0)) {
        func_800FFAB0(actor);
        return;
    }
    if (actor->unk6C_9 == 0x3CF) {
        variant = actor->unk74_7 - 0x32;
        switch (variant) {
            case 1:
                actor->unk6C_0 =
                    _gspropctrl_entrypoint_12(_gccubesearch_entrypoint_0(0x201, actor));
                if (func_800D0A9C(actor->unk6C_0, 4) != 0) {
                    func_800FFAB0(actor);
                }
                break;
            case 6:
                actor->unk6C_0 =
                    _gspropctrl_entrypoint_12(_gccubesearch_entrypoint_0(0x1F7, actor));
                if (func_800D0A9C(actor->unk6C_0, 2) != 0) {
                    func_800FFAB0(actor);
                }
        }
    }
}

s32 func_808003F0_chbilldrillboulder(Actor *actor, s32 msg, s32 msg_data)
{
    s32 hit_data;

    switch (msg) {
        case 0x3F: // Bill Drill hit
            hit_data = *(s32 *) &msg_data;
            if (actor->unk70_10 != 2) {
                if (_subaddieDll_entrypoint_5(actor, hit_data)) {
                    actor->unk64_20 = 1;
                    func_80103110(actor, 1);
                    func_80101FDC(actor, 2);
                }
            }
            break;
        case 0x40:
            func_8010A570(actor);
            _chexploder_entrypoint_3(actor, actor->position, 2);
            break;
        case 0x90:
            func_80800024_chbilldrillboulder(actor);
            func_800FFAB0(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

// Per-instance broken flag (0x514 + placement index); 0 for model 0x3CF or out of range.
// Matching: K&R-style definition, needed for the match.
s32 func_808004D4_chbilldrillboulder(actor)
u8 *actor;
{
    s32 index;

if (((u32) (*(s32 *) ((s8 *) actor + 0x6C) << 0xB) >> 0x14) == 0x3CF) {
    return 0;
}

index = ((u32) ((u16) (*(u16 *) ((s8 *) (actor) + (0x76)))) >> 7) - 0x33;

if ((index < 0) || (index >= 0x1E)) {
    return 0;
}

return index + 0x514;
}

// TU-NOTE: the overlay .data is defined in C here; its tables point to functions of this file,
// and IDO schedules some of them differently unless the tables are in the same unit.
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _bsbtrot_entrypoint_10();
int D_80800540_chbilldrillboulder[18] = {0x157010F,
                                         0x6820001,
                                         0x0,
                                         (u32) func_8080026C_chbilldrillboulder,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x40000800,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_808002C4_chbilldrillboulder,
                                         (u32) func_80107C2C,
                                         (u32) _bsbtrot_entrypoint_10,
                                         (u32) func_808003F0_chbilldrillboulder,
                                         0x0};
void *D_80800588_chbilldrillboulder = (void *) 0x01570322;
static u32 D_80800588_chbilldrillboulder_rest[17] = {0x7930001,
                                                     0x0,
                                                     (u32) func_8080026C_chbilldrillboulder,
                                                     (u32) func_80105834,
                                                     (u32) func_80101870,
                                                     0x0,
                                                     0x0,
                                                     0x0,
                                                     0x40000800,
                                                     0x0,
                                                     (u32) func_80108ED0,
                                                     0x0,
                                                     (u32) func_808002C4_chbilldrillboulder,
                                                     (u32) func_80107C2C,
                                                     (u32) _bsbtrot_entrypoint_10,
                                                     (u32) func_808003F0_chbilldrillboulder,
                                                     0x0};
int D_808005D0_chbilldrillboulder[18] = {0x15703CF,
                                         0x6820001,
                                         0x0,
                                         (u32) func_8080026C_chbilldrillboulder,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x40000800,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_808002C4_chbilldrillboulder,
                                         (u32) func_80107C2C,
                                         (u32) _bsbtrot_entrypoint_10,
                                         (u32) func_808003F0_chbilldrillboulder,
                                         0x0};
u8 D_80800618_chbilldrillboulder[108] = {
    0x4,  0x10, 0x0, 0x1D, 0x9,  0xDD, 0x0, 0x2B, 0x2, 0xCC, 0x3,  0x66, 0x0,  0x15, 0x0,  0x0,
    0x0,  0x99, 0x0, 0x22, 0x1,  0x80, 0x2, 0x0,  0x4, 0x80, 0x6,  0x0,  0x0,  0x19, 0x0,  0x0,
    0x0,  0x7,  0x0, 0x2D, 0x0,  0x32, 0x0, 0x64, 0x0, 0x20, 0xDE, 0xA7, 0x71, 0xC0, 0x0,  0xA,
    0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x4B, 0x0,  0x64, 0x4,  0x1A, 0xF,  0x10,
    0x0,  0x1D, 0x6, 0xA0, 0x0,  0x14, 0x0, 0x2D, 0x1, 0x90, 0x2,  0x58, 0x0,  0x1B, 0xFC, 0xE0,
    0xFD, 0xA8, 0x0, 0x22, 0x0,  0xB3, 0x0, 0xCC, 0x0, 0xB3, 0x0,  0xB3, 0x0,  0x1E, 0x0,  0x32,
    0x0,  0x32, 0x0, 0xD,  0x0,  0x4B, 0xF, 0x1A, 0x0, 0x0,  0x0,  0x0};
u8 D_80800684_chbilldrillboulder[108] = {
    0x4,  0x10, 0x0, 0x1D, 0x9,  0xDD, 0x0, 0x2B, 0x2, 0xCC, 0x3,  0x66, 0x0,  0x15, 0x0,  0x0,
    0x0,  0x99, 0x0, 0x22, 0x1,  0x80, 0x2, 0x0,  0x4, 0x80, 0x6,  0x0,  0x0,  0x19, 0x0,  0x0,
    0x0,  0x7,  0x0, 0x2D, 0x0,  0x32, 0x0, 0x64, 0x0, 0x20, 0xC0, 0xC0, 0xC0, 0x80, 0x0,  0xA,
    0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x4B, 0x0,  0x64, 0x4,  0x1A, 0xF,  0x10,
    0x0,  0x1D, 0x6, 0x59, 0x0,  0x14, 0x0, 0x2D, 0x1, 0x90, 0x2,  0x58, 0x0,  0x1B, 0xFC, 0xE0,
    0xFD, 0xA8, 0x0, 0x22, 0x0,  0xB3, 0x0, 0xCC, 0x0, 0xB3, 0x0,  0xB3, 0x0,  0x1E, 0x0,  0x32,
    0x0,  0x32, 0x0, 0xD,  0x0,  0x4B, 0xF, 0x1A, 0x0, 0x0,  0x0,  0x0};
u8 D_808006F0_chbilldrillboulder[32] = {
    0x0, 0x13, 0x4, 0x13, 0x0, 0xA, 0x0, 0xE6, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xE2,
    0x9, 0xC4, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0, 0x0, 0x0};
