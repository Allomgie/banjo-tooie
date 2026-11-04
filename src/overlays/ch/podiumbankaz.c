// The Split-Up pads (one podium for Banjo, one for Kazooie): once the Split Up ability is known
// they light up and stepping on one starts the split-up state; first visit shows dialog 0xD82.
#include "common.h"

extern s32 _subaddiedialog_entrypoint_1(f32 *, s32, s32);
extern s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, void *);
extern void func_80101FDC(Actor *, u32);
extern s32 func_800F6BE4(s32);
extern s32 func_800F7B9C(s32, u32);
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_800F7D38(s32, s32, f32 *, f32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void *D_80800500_chpodiumbankaz;
extern int D_80800548_chpodiumbankaz[];

// Pad is fully opaque once the Split Up ability is known.
s32 func_80800000_chpodiumbankaz(s32 actor)
{
    if (func_800C6E38(0x1C)) {
        _subaddiefade_entrypoint_1(actor, 0xFF);
    } else {
        _subaddiefade_entrypoint_1(actor, 0x87);
    }
}

// Shows the first-time Split Up dialog when the player is near.
void func_80800044_chpodiumbankaz(Actor *actor)
{
    if (!func_800DA298(0x4F4)) {
        if (_subaddiedialog_entrypoint_1(actor->position, 250, 0)) {
            if (_subaddiedialog_entrypoint_11(actor->unk0, 0xD82, 0xE, actor->position, 0)) {
                func_800DA544(0x4F4);
            }
        }
    }
}

// Banjo pad update.
void func_808000B8_chpodiumbankaz(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            func_80800044_chpodiumbankaz(actor);
            break;
        case 2:
            func_80101FDC(actor, 3);
            break;
        case 3:
            if (!func_800F6BE4(actor->unk79_4) || func_800F7B9C(actor->unk79_4, 4) == 2) {
                func_80101FDC(actor, 1);
            }
    }
}

// Kazooie pad update.
void func_80800170_chpodiumbankaz(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            func_80800044_chpodiumbankaz(actor);
            break;
        case 2:
            func_80101FDC(actor, 3);
            break;
        case 3:
            if (!func_800F6BE4(actor->unk79_4) || func_800F7B9C(actor->unk79_4, 5) == 2) {
                func_80101FDC(actor, 1);
            }
    }
}

// Player steps on the Banjo pad: Banjo-Kazooie or Banjo starts split-up state 0x3A.
void func_80800228_chpodiumbankaz(Unk80132ED0 *handle, s32 player)
{
    Actor *actor;
    s32 transformation;
    f32 player_pos[3];

    if (func_800C6E38(0x1C)) {
        transformation = func_800F5410(player);
        actor = func_80106790(handle);
        if (transformation == 1 || transformation == 10) {
            if (actor->unk70_10 == 3 ||
                func_800F7D38(player, 0x3A, actor->position, actor->rotation[1]) == 2) {
                if (transformation == 10) {
                    func_800F5A00(player, player_pos);
                    _sudeflect_entrypoint_1(player_pos, 125.0f, 0.0f, 40.0f, 0x1C);
                }
                actor->unk79_4 = player;
                func_80101FDC(actor, 2);
            }
        }
    }
}

// Player steps on the Kazooie pad: Kazooie triggers split-up state 0x3B.
void func_80800318_chpodiumbankaz(Unk80132ED0 *handle, s32 player)
{
    Actor *actor;
    s32 transformation;

    if (func_800C6E38(0x1C)) {
        transformation = func_800F5410(player);
        actor = func_80106790(handle);
        if (transformation == 0xB &&
            (actor->unk70_10 == 3 || func_800F7CF4(player, 0x3B, actor->position) == 2)) {
            actor->unk79_4 = player;
            func_80101FDC(actor, 2);
        }
    }
}

s32 func_808003C4_chpodiumbankaz(s32 actor, s32 ability)
{
    if (ability == 0x1C) {
        _subaddiefade_entrypoint_1(actor, 0xFF);
    }
}

// Banjo pad message handler.
int func_808003EC_chpodiumbankaz(s32 actor, s32 msg, s32 arg)
{
    s32 result;
    switch (msg) {
        case 0x1A:
            // Matching: the self-OR casts are needed for the match.
            func_808003C4_chpodiumbankaz(actor | actor, arg | arg);
            return 1;
        case 0x91:
            if (func_800DA298(0xa84)) {
                func_80800228_chpodiumbankaz(*(void **) actor, arg | arg);
            }
            return 1;
    }
    result = 0;
    return result;
}

// Kazooie pad message handler.
int func_80800464_chpodiumbankaz(s32 actor, s32 msg, s32 arg)
{
    s32 result;
    switch (msg) {
        case 0x1A:
            // Matching: the self-OR casts are needed for the match.
            func_808003C4_chpodiumbankaz(actor | actor, arg | arg);
            return 1;
        case 0x91:
            if (func_800DA298(0xAC2)) {
                func_80800318_chpodiumbankaz(*(void **) actor, arg | arg);
            }
            return 1;
    }
    result = 0;
    return result;
}

int chpodiumbankaz_entrypoint_0()
{
    return &D_80800500_chpodiumbankaz;
}

int chpodiumbankaz_entrypoint_1()
{
    return &D_80800548_chpodiumbankaz;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
// TU-NOTE: the overlay .data is defined here in C. The tables hold pointers to functions of this
// file, and IDO's assembler schedules some of them differently unless they are in the same unit.
// Values are taken from the ROM; D_80800548_chpodiumbankaz is declared as int[] (same address).
void *D_80800500_chpodiumbankaz = (void *) 0x02690157;
static u32 D_80800500_chpodiumbankaz_rest[17] = {0x7E20001,
                                                 0x0,
                                                 (u32) func_808000B8_chpodiumbankaz,
                                                 (u32) func_80105834,
                                                 (u32) func_80101870,
                                                 0x1F40000,
                                                 0x0,
                                                 0x0,
                                                 0x40000814,
                                                 0x0,
                                                 (u32) func_80108ED0,
                                                 0x0,
                                                 (u32) func_80800000_chpodiumbankaz,
                                                 (u32) func_80107C2C,
                                                 0x80082412,
                                                 (u32) func_808003EC_chpodiumbankaz,
                                                 0x0};
int D_80800548_chpodiumbankaz[18] = {0x2680156,
                                     0x7E10001,
                                     0x0,
                                     (u32) func_80800170_chpodiumbankaz,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x1F40000,
                                     0x0,
                                     0x0,
                                     0x40000814,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_80800000_chpodiumbankaz,
                                     (u32) func_80107C2C,
                                     -0x7FF7DBEE,
                                     (u32) func_80800464_chpodiumbankaz,
                                     0x0};
