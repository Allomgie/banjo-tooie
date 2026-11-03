#include "common.h"
#include "playerstate.h"

extern s32 func_800EE7F8(s32);
extern f32 yaw_get(PlayerState *);
extern f32 func_800F1F0C(f32 *, f32 *, f32);
extern f32 mlAbsF(f32);
extern PlayerState *func_800F53D0(s32);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_set(PlayerState *, f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void yaw_applyIdeal(PlayerState *);
extern void func_800F90EC(f32);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern f32 func_800EEB40(f32 *, f32 *);
void baduo_entrypoint_7();
void baduo_entrypoint_10();
void baduo_entrypoint_11();
s32 func_80800C78_baduo();
int func_80800CA8_baduo();

s32 baduo_entrypoint_0()
{
    return 0x14;
}

// Camera handover between two players.
int func_80800008_baduo(s32 player_a, s32 player_b)
{
    s32 unk_0;
    s32 unk_1;
    unk_1 = func_800A4C88(player_b);
    unk_0 = func_800A4C88(player_a);
    func_801100E4(unk_1, unk_0);
}

s32 baduo_entrypoint_1(s32 player)
{
    return ((u8 *) *(u8 **) (player + 0x58))[0];
}

// Returns the slot of the other of Banjo/Kazooie, 0 if neither is active.
int baduo_entrypoint_2()
{
    // Matching: no return on the Banjo/Kazooie paths, needed for the match.
    switch (func_800A3274()) {
        case 0xA:
            _plsu_entrypoint_1(0xB);
            break;
        case 0xB:
            _plsu_entrypoint_1(0xA);
            break;
        default:
            return 0;
    }
}

s32 baduo_entrypoint_3(s32 player)
{
    return ((u8 *) *(u8 **) (player + 0x58))[1];
}

s32 baduo_entrypoint_4(s32 player)
{
    return ((u8 *) *(u8 **) (player + 0x58))[2];
}

void baduo_entrypoint_5(s32 player)
{
}

void baduo_entrypoint_6(u8 *player)
{
    s32 xform;

    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x58) + 1) = 0;
    baduo_entrypoint_11(player, 0);
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x58) + 4) = 0.0f;
    func_800EFD24(*(u8 **) ((s8 *) player + 0x58) + 8);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x58) + 0) = 0;
    xform = func_800A3274(player);
    if ((xform == 0xA) || (xform == 0xB)) {
        if (func_800F8B88() == 2) {
            baduo_entrypoint_7(player, 3);
            return;
        }
        baduo_entrypoint_7(player, 1);
        return;
    }
    baduo_entrypoint_7(player, 1);
}

// Sets the duo pad state (1 normal, 2 split, 3 can rejoin, 4 rejoining) and runs its entry actions.
// Matching: the old-style parameter declarations are needed for the match.
void baduo_entrypoint_7(player, state) u8 *player;
int state;
{
    **(u8 **) ((s8 *) player + 0x58) = state;
    switch (**(u8 **) ((s8 *) player + 0x58)) {
        case 1:
            baduo_entrypoint_11(player, 0);
            func_8009ADF0(player, 2, 0);
            return;

        case 2:
            baduo_entrypoint_10(player, 0);
            baduo_entrypoint_11(player, 1);
            return;

        case 3:
            if (func_8008DAA8(player) != 0) {
                func_800A38F0(player, 1, 1);
            } else {
                func_800A38F0(player, 0, 1);
            }
            func_8009ADF0(player, 2, 1);
            return;

        case 4:
            _bashoes_entrypoint_6(player, 1);
            func_800F82D4(func_800F54E4(), 2);
    }
}

s32 baduo_entrypoint_8(s32 player)
{
    return func_800EE7F8(*(s32 *) (player + 0x58) + 0x8);
}

void baduo_entrypoint_9(s32 player, f32 value)
{
    *(f32 *) (*(s32 *) (player + 0x58) + 0x4) = value;
}

// Matching: the old-style parameter declarations are needed for the match.
void baduo_entrypoint_10(player, value) void *player;
s32 value;
{
    ((s8 *) *(void **) ((char *) player + 0x58))[1] = value;
}

// Matching: the old-style parameter declarations are needed for the match.
void baduo_entrypoint_11(player, value) void *player;
s32 value;
{
    ((s8 *) *(void **) ((char *) player + 0x58))[2] = value;
}

int baduo_entrypoint_12(Actor *player)
{
    if (func_8008E39C()) {
        _bashoes_entrypoint_6(player, 2);
    }
    func_800F9A6C();
}

// Per-frame rejoin handling: state 3 can switch to 4, state 4 performs the rejoin.
void baduo_entrypoint_13(PlayerState *player)
{
    s32 cur_slot;
    s32 pad;
    f32 yaw;
    f32 player_pos[3];
    f32 other_pos[3];
    s32 other_slot;
    cur_slot = func_800F54E4();
    switch (**(u8 **) ((u8 *) player + 0x58)) {
        case 3:
            if (func_800A3274(player) == 0xA && func_8008D40C(player))
                baduo_entrypoint_7(player, 4);
            return;
        case 4:
            if (func_800F5B0C(cur_slot) == 2) {
                other_slot = baduo_entrypoint_2(player);
                if (cur_slot == player->unk184)
                    func_800F8EBC(_plsu_entrypoint_1(0xB));
                else
                    func_800F8EBC(player->unk184);
                if (cur_slot == player->unk184)
                    func_800F82D4(cur_slot, 0);
                else {
                    func_800F82D4(cur_slot, 0);
                    func_800F82D4(player->unk184, 0);
                }
                _bapackctrl_entrypoint_5(player, 1);
                func_800F911C(1);
                func_800F80D8(player->unk184);
                func_800D5034(func_800A3274(player), 1);
                func_800A3410(player, 1);
                func_800F8268(player->unk184, 0, 1);
                if (cur_slot != player->unk184) {
                    func_80800008_baduo(func_800F53D0(other_slot), func_800F53D0(player->unk184));
                }
                yaw = yaw_get(player);
                func_800F5A00(other_slot, other_pos);
                func_8009C128(player, player_pos);
                func_800F759C(other_slot);
                func_800A38F0(player, 1, 1);
                func_800A91A8(player->unk184);
                baduo_entrypoint_7(player, 1);
                if (mlAbsF(func_800F1F0C(player_pos, other_pos, yaw)) > 90.0f)
                    bs_setState(player, 0x69);
                else
                    bs_setState(player, 0x6A);
                func_80101180(0x158, 0x17, 0);
            }
    }
}

void baduo_entrypoint_14(PlayerState *player, s32 pos)
{
    s32 partner_idx;
    PlayerState *partner;
    partner_idx = func_800F6224(*(s32 *) ((u8 *) player + 0x184));
    partner = func_800F53D0(partner_idx);
    func_800F452C(partner, pos);
    func_800A3410(partner, 0x11);
    func_80092778(partner);
    func_80800008_baduo(player, partner);
    _bababykaz_entrypoint_8(partner);
    bs_setState(partner, 0x139);
    yaw_set(partner, yaw_get(player));
    yaw_setIdeal(partner, yaw_getIdeal(player));
    _bababykaz_entrypoint_10(partner, *(s32 *) ((u8 *) player + 0x184));
    _bsfirstp_entrypoint_28(player, partner);
    func_800A91A8(partner_idx);
    func_800A38F0(player, 0, 1);
}

void baduo_entrypoint_15(PlayerState *player, f32 *pos)
{
    s32 partner_idx;
    PlayerState *partner;
    s32 unk_0;
    s32 i;
    Vec3f player_pos;

    partner_idx = func_800F6224(*(void **) ((u8 *) player + 0x184));
    partner = (PlayerState *) func_800F53D0(partner_idx);
    func_800F452C(partner, pos);
    func_800A3410(partner, 0x11);
    func_80092778(partner);
    _bababykaz_entrypoint_8(partner);
    func_80800008_baduo(player, partner);
    unk_0 = func_800A4CA8(partner);
    func_800F3BB0(player, player_pos.f);
    if (func_800EEB40(pos, player_pos.f) > 1000000.0f) {
        i = 0;
        do {
            func_80110588(unk_0);
            i++;
        } while (i != 60);
    }
    bs_setState(partner, 0x136);
    func_800F8128(partner_idx);
    func_800A38F0(player, 0, 1);
    func_800F8EE4(*(void **) ((u8 *) player + 0x184));
    bs_setState(player, _badrone_entrypoint_29(player));
    _sudialog_entrypoint_0(0xE8, 0xC);
    func_80800C78_baduo(partner, 0x11);
    func_80800CA8_baduo(player, partner);
    func_800F86C4(*(void **) ((u8 *) partner + 0x184), 0x11);
}

void baduo_entrypoint_16(PlayerState *player)
{
    s32 partner_idx;
    PlayerState *partner;

    partner_idx = func_800F6224(player->unk184);
    partner = func_800F53D0(partner_idx);
    yaw_setIdeal(player, yaw_get(player));
    yaw_setIdeal(partner, yaw_get(player));
    yaw_applyIdeal(partner);
    bs_setState(partner, 0xBA);
    func_80800008_baduo(player, partner);
    baduo_entrypoint_7(partner, 2);
    baduo_entrypoint_7(player, 2);
    func_800F911C(2);
    func_800F9098(10, *(u8 **) ((u8 *) player + 0x58) + 8);
    func_800F90EC(*(f32 *) (*(u8 **) ((u8 *) player + 0x58) + 4));
    func_800D5034(1, 10);
    func_800D5034(1, 11);
    func_800F8EE4(partner_idx);
    func_800F8128(player->unk184);
    func_80101180(0x158, 0x16, 0);
}

void baduo_entrypoint_17(PlayerState *player, s32 pos)
{
    s32 partner_idx;
    PlayerState *partner;
    f32 player_pos[3];

    func_8009C128(player, player_pos);
    partner_idx = func_800F6224(*(s32 *) ((u8 *) player + 0x184));
    partner = func_800F53D0(partner_idx);
    func_800F452C(partner, pos);
    bs_setState(partner, 1);
    func_800F45B0(partner, 2, player_pos);
}

void baduo_entrypoint_18(PlayerState *player, s32 pos)
{
    s32 partner_idx;
    PlayerState *partner;

    partner_idx = func_800F6224(*(s32 *) ((u8 *) player + 0x184));
    partner = func_800F53D0(partner_idx);
    func_800F452C(partner, pos);
    func_800A3410(partner, 13);
    func_80092778(partner);
    bs_setState(partner, 0xE5);
    func_80800008_baduo(player, partner);
    func_800A38F0(player, 0, 1);
    func_800F8128(partner_idx);
    func_800F8EE4(*(void **) ((u8 *) player + 0x184));
    func_800F45B0(player, 2, pos);
    yaw_setIdeal(partner, 0.0f);
    yaw_applyIdeal(partner);
    func_80800C78_baduo(partner, 13);
    func_80800CA8_baduo(player, partner);
    func_8009DB04(player, 0x5A2, 0.9f, 0x6D60);
}

void baduo_entrypoint_19(u8 *player)
{
    s32 slot;

    slot = _plsu_entrypoint_1(0xD);
    func_800F457C(player, 0);
    func_800A38F0(player, 1, 1);
    func_800F8EBC(*(s32 *) ((s8 *) player + 0x184));
    func_80800008_baduo(func_800F53D0(slot), player);
    func_800F8128(*(s32 *) ((s8 *) player + 0x184));
    func_80800CA8_baduo(func_800F53D0(slot), player);
    func_800F759C(slot);
    func_80800C78_baduo(player, 1);
    func_8009DB04(player, 0x5A4, 0.9f, 0x6D60);
}

// Hands control to the partner while the player becomes a statue.
void baduo_entrypoint_20(u8 *player, s32 pos, f32 yaw)
{
    s32 idx_copy;
    s32 partner_idx;
    s32 partner;

    partner_idx = func_800F6224(*(s32 *) ((s8 *) player + 0x184));
    idx_copy = partner_idx; // Matching: extra copy needed for the match.
    partner = func_800F53D0(partner_idx);
    func_800F452C(partner, pos);
    func_80800008_baduo(player, partner);
    func_800A3410(partner, 0xE);
    func_80092778(partner);
    yaw_setIdeal(partner, yaw);
    yaw_applyIdeal(partner);
    _bsstatue_entrypoint_1(player);
    bs_setState(partner, 0xF9);
    func_800F8128(idx_copy);
    func_800F8EE4(*(s32 *) ((s8 *) player + 0x184));
    func_800F45B0(player, 2, pos);
    func_800A38F0(player, 0, 1);
    _sudialog_entrypoint_0(0x50, 0xE);
    func_80800C78_baduo(partner, 0xE);
    func_80800CA8_baduo(player, partner);
}

// Splits off the partner as Kazooie in a torpedo.
void baduo_entrypoint_21(PlayerState *player)
{
    s32 partner_idx;
    PlayerState *partner;
    f32 player_pos[3];
    func_800F911C(3);
    partner_idx = func_800F6224(player->unk184);
    partner = func_800F53D0(partner_idx);
    func_8009C128(player, player_pos);
    func_800F452C(partner, player_pos);
    func_800A3410(player, 10);
    func_800A3410(partner, 11);
    func_80092778(partner);
    yaw_setIdeal(player, yaw_get(player));
    yaw_setIdeal(partner, yaw_get(player));
    yaw_applyIdeal(partner);
    func_800F80D8(partner_idx);
    bs_setState(partner, 0x153);
    func_800A91A8(partner_idx);
    func_80800008_baduo(player, partner);
    func_800F8EE4(player->unk184);
    func_800A38F0(player, 0, 1);
    func_800D5234(1);
    func_800A16BC(1);
    func_800A1694();
    _bakaztorpedo_entrypoint_3(partner);
}

// Matching: the old-style parameter declarations are needed for the match.
s32 func_80800C78_baduo(player, xform)
s32 player;
s32 xform;
{
    _surestart_entrypoint_0(xform);
    func_800A1658(xform);
}

// Matching: the old-style parameter declarations are needed for the match.
int func_80800CA8_baduo(player_a, player_b)
s32 player_a;
s32 player_b;
{
    s32 xform_b;
    s32 xform_a;
    xform_a = func_800A3274(player_a);
    xform_b = func_800A3274(player_b);
    func_800D5034(xform_a, xform_b);
}
