#include "common.h"

extern f32 func_800EFC7C();
extern u8 D_80800270_chfoodwarn[];
extern u8 D_8080028C_chfoodwarn[];
extern int D_808002A8_chfoodwarn[];

// Fetches the position of marker prop 0x521 + side into out_pos.
int func_80800000_chfoodwarn(s32 actor, s32 side, s32 out_pos)
{
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(side + 0x521, actor + 4) | 0,
                              out_pos);
}

int func_8080003C_chfoodwarn(s32 actor)
{
    func_80800000_chfoodwarn(actor, 0, actor + 0x28);
    func_80800000_chfoodwarn(actor, 1, actor + 0x18);
}

// Returns 1 when the player is closer to the first marker.
s32 func_80800074_chfoodwarn(u8 *actor, f32 *player_pos)
{
    f32 dist = func_800EFC7C(player_pos, actor + 0x28);
    if (dist < func_800EFC7C(player_pos, actor + 0x18)) {
        return 1;
    }
    return 0;
}

// Warns when the player carries burgers or fries towards an exit.
void func_808000D4_chfoodwarn(Actor *actor)
{
    f32 player_pos[3];
    s32 in_range;
    s32 has_food;
    has_food = func_800D1A04(0x4B) != 0 || func_800D1A04(0x4C) != 0;
    func_8010D254(player_pos);
    in_range = func_8010C500(actor);
    if (in_range && !actor->unk6C_0)
        actor->unk64_20 = func_80800074_chfoodwarn(actor, player_pos);
    if (in_range) {
        if (actor->unk64_20 && !actor->unk6C_0 && has_food) {
            *(u16 *) D_80800270_chfoodwarn = actor->unk74_7 + 0x541;
            _subaddiedialog_entrypoint_7(actor, actor->position, D_80800270_chfoodwarn);
        } else
            _subaddiedialog_entrypoint_7(actor, actor->position, D_8080028C_chfoodwarn);
    }
    actor->unk6C_0 = (u16) in_range;
}

int func_808001F4_chfoodwarn(Actor *actor, s32 msg, s32 data)
{
    if (msg != 0x2E) {
        if (msg == 0x95) {
            if ((!(msg & 0xFF) && !msg) && !msg) {
            }
            func_80105010();
            *(u16 *) ((char *) actor + 0x6E) =
                (u16) ((*(u16 *) ((char *) actor + 0x6E) & 0xFE00) |
                       (func_8010C500(actor) & 0x1FF));
            goto block_4;
        }
        return 0;
    }
block_4:
    return 1;
}

int *chfoodwarn_entrypoint_0()
{
    return &D_808002A8_chfoodwarn;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u8 D_80800270_chfoodwarn[28] = {0x0, 0x0, 0x5,  0xDC, 0x10, 0xE9, 0x10, 0xEA, 0x0, 0x0,
                                0x0, 0x1, 0x10, 0xEA, 0x0,  0x0,  0x0,  0x22, 0x0, 0x0,
                                0x0, 0xC, 0x1,  0xFA, 0x0,  0x0,  0x0,  0x0};
u8 D_8080028C_chfoodwarn[28] = {0x0, 0x0, 0x5,  0xDC, 0x0, 0x0, 0x10, 0xEA, 0x0, 0x0,
                                0x0, 0x1, 0x10, 0xEA, 0x0, 0x0, 0x0,  0x22, 0x0, 0x0,
                                0x0, 0xC, 0x0,  0xFA, 0x0, 0x0, 0x0,  0x0};
int D_808002A8_chfoodwarn[18] = {0x15804BF,
                                 0x8DC0001,
                                 0x0,
                                 (u32) func_808000D4_chfoodwarn,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x7D00000,
                                 0x0,
                                 0x0,
                                 0x801,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_8080003C_chfoodwarn,
                                 (u32) func_80107C2C,
                                 -0x7FFFDBEE,
                                 (u32) func_808001F4_chfoodwarn,
                                 0x0};
