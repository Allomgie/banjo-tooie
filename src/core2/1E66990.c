// Player move-precondition predicates: about 60 small checks combining learned abilities,
// player flags, state, ground/water, transformation and shoes.
#include "core2/1E66990.h"

// Move preconditions: mostly "ability learned" (func_800C6E38(ability id)) combined with a
// player-state check (func_800A3304).
// TU-NOTE: player_isStable, func_8008E0C8 and a few others have no prototype; some callers
// omit the argument.

extern s32 func_800C6E38(s32);
extern s32 func_800A3304(s32);
extern f32 func_800964DC(s32);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800F65D0(int param_0);
extern f32 func_80090010(void);
extern f32 mlAbsF(f32);
extern s32 func_800F20BC(f32, f32, s32);
f32 func_8009C150(PlayerState *);
f32 func_80096364(PlayerState *);
extern f32 func_800A3378(PlayerState *);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void func_800963C0(PlayerState *, f32 *);
extern s32 func_800954E8(PlayerState *, s32 *);
extern f32 yaw_getIdeal(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
int player_isStable();

// Beak barge available.
int func_8008D0A0(s32 self)
{
    return func_800C6E38(0) && func_800A3304(self);
}

int func_8008D0E0(PlayerState *self)
{
    return (func_800C6E38(1) != 0) && (baflag_isFalse(self, 0x39) != 0) &&
           ((func_800A3304(self) != 0) || func_800A3274(self) == 11);
}

// Beak bust available.
int func_8008D14C(s32 self)
{
    return func_800C6E38(2) && func_800A3304(self);
}

void func_8008D18C(s32 arg0)
{
    // The ability check result is discarded.
    func_800C6E38(0x3);
}

int func_8008D1B0(s32 self)
{
    return func_800C6E38(0x4) && func_800A3304(self);
}

void func_8008D1F0(s32 arg0)
{
    // The ability check result is discarded.
    func_800C6E38(0x5);
}

// Dive available: ability learned and height above ground over 100.
int func_8008D214(s32 self)
{
    return func_800C6E38(0xF) != 0 && 100.0f < func_800964DC(self) - func_80096364(self);
}

// Egg shoot/poop available.
s32 func_8008D280(s32 self)
{
    s32 unk_0;

    if (func_800C6E38(6) == 0) {
        return 0;
    }
    if (func_800DA298(0x6B6) != 0) {
        return 0;
    }
    unk_0 = func_800A3274(self);
    if (((unk_0 == 1) || (unk_0 == 0xA)) && (func_800A3304(self) == 0)) {
        return 0;
    }
    return 1;
}

// Feathery flap available: not flapped or pecked yet.
int func_8008D304(PlayerState *self)
{
    return (baflag_isFalse(self, 0x12) != 0) && (baflag_isFalse(self, 5) != 0) &&
           (func_800C6E38(7) != 0) && (func_800A3304(self) != 0);
}

// Flap flip available.
int func_8008D370(s32 self)
{
    return func_800C6E38(0x8) && func_800A3304(self);
}

int func_8008D3B0(PlayerState *self)
{
    return baflag_isTrue(self, 1) != 0 && func_800C6E38(9) != 0 &&
           func_800F64A4(*(s32 *) ((u8 *) self + 0x184), 0x401) != 0;
}

int func_8008D40C(s32 self)
{
    f32 other_pos[3];
    s32 unk_0;
    f32 pos[3];
    s32 state;
    if (func_800F8B88() == 2 && _plsu_entrypoint_2()) {
        if (func_8008E0C8(self))
            return 0;
        if (func_800F99E8())
            return 0;
        state = bs_getCurrentState(self);
        if (state == 0xB9 || state == 0xBA)
            return 0;
        unk_0 = _baduo_entrypoint_2(self);
        if (!player_isStable(self) || !func_800F6C5C(unk_0))
            return 0;
        if (!func_800F6774(func_800F54E4()))
            return 0;
        func_8009C128(self, pos);
        func_800F5A00(_baduo_entrypoint_2(self), other_pos);
        // Squared distance under 90 * 90.
        return func_800EEB40(pos, other_pos) < 8.1e+03f;
    }
    return 0;
}

s32 func_8008D544(PlayerState *arg0)
{
    return func_800C6E38(0xA);
}

int func_8008D568(s32 self)
{
    return func_800C6E38(0x29) && baflag_isFalse(self, 5) && baflag_isFalse(self, 0x12);
}

int func_8008D5C4(PlayerState *self)
{
    return (baflag_isFalse(self, 5) != 0) && (baflag_isFalse(self, 0x12) != 0) &&
           (func_800C6E38(11) != 0) && (func_800A3304(self) != 0);
}

s32 func_8008D630(s32 self)
{
    if ((baflag_isTrue(self, 0x14) != 0) || (baflag_isTrue(self, 0x19) != 0)) {
        return 0;
    }
    if (bs_getCurrentState(self) == 0x56) {
        return 0;
    }
    return 1;
}

int func_8008D694(s32 self)
{
    return func_800C6E38(0xC) && func_800A3304(self);
}

int func_8008D6D4(s32 self)
{
    return func_800C6E38(0xd) && func_800A3304(self);
}

int func_8008D714(s32 self)
{
    s32 self_copy;
    s32 tmp;
    // Matching: the copies and the goto to a dummy label are needed for the match.
    self_copy = (tmp = self);
    goto dummy_label_426559;
dummy_label_426559:;
    return _baduo_entrypoint_3(tmp) && func_800A3304(self_copy);
}

int func_8008D750(s32 self)
{
    s32 learned;
    // Matching: the local for the ability check is needed for the match.
    learned = func_800C6E38(0xE);
    return (learned != 0) && func_800A3304(self);
}

int func_8008D790(PlayerState *self)
{
    return _baduo_entrypoint_4(self) != 0 && !func_8008E39C(self) &&
           player_isStable(self) != 0 && !func_800C954C() && !func_800DB9B0() &&
           !func_800F8004(*(s32 *) ((u8 *) self + 0x184)) &&
           !func_800F6D24(*(s32 *) ((u8 *) self + 0x184)) && baflag_isFalse(self, 0x34) != 0;
}

int func_8008D850(s32 self)
{
    f32 pos[3];
    if (func_800C6E38(0x1E)) {
        if (func_800A3304(self) && !_bafpctrl_entrypoint_5(self)) {
            func_8009C128(self, pos);
            // On map 0x117 the move is blocked when z is below -6130.
            if ((func_800EA05C() == 0x117) && (pos[2] < (-6.13e+03f))) {
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

// Trot available.
int func_8008D8E4(s32 self)
{
    return func_800C6E38(0x10) && func_800A3304(self);
}

// Same check as func_8008D8E4.
int func_8008D924(s32 self)
{
    return func_800C6E38(0x10) && func_800A3304(self);
}

// Wonderwing available.
int func_8008D964(s32 self)
{
    return func_800C6E38(0x12) && func_800A3304(self);
}

s32 player_inWater();

// First-person entry allowed.
int func_8008D9A4(Actor *self)
{
    s32 unk_0;
    unk_0 = func_800A4CA8();
    // Matching: the "| 0" is needed for the match.
    if (_ncba1p_entrypoint_10(unk_0 | 0) == 3) {
        return 0;
    }
    if (!func_800A4D40(self)) {
        return 0;
    }
    if (!player_isStable(self) && !player_inWater(self)) {
        return 0;
    }
    return 1;
}

int func_8008DA24(Actor *self)
{
    return func_800C6E38(0x14) != 0 && baphysics_get_vertical_velocity(self) < 100.0f &&
           func_800A0FCC(self) == 0 && func_800976DC(self) != 0;
}

void func_8008DAA8(int *self)
{
    func_800F65D0(self[97]);
}

int func_8008DAC8(s32 self)
{
    func_800DB9B0(self);
    // Matching: the empty if is needed for the match.
    if (self) {
    }
}

int func_8008DAE8(s32 self, s32 target, f32 tolerance)
{
    f32 pos[3];
    f32 target_yaw;
    u16 rel_yaw;
    f32 yaw;
    func_8009C128(self, pos);
    func_800F1E6C(target, pos, &target_yaw);
    // 182.04445 = 65536 / 360: degrees to 16-bit angle.
    rel_yaw = (u16) (target_yaw * 182.04445f);
    yaw = func_80090010();
    rel_yaw -= (u16) (yaw * 182.04445f);
    return mlAbsF(0x8000 - rel_yaw) < tolerance * 182.04445f;
}

int func_8008DC90(s32 self, s32 target, s32 tolerance)
{
    f32 unk_0[3];
    f32 pos[3];
    f32 unk_1[2];
    func_8009C128(self, pos);
    func_8008FF40(unk_0);
    func_800F18FC(pos, target, unk_1);
    return (func_800F20BC(unk_0[0], unk_1[0], tolerance) != 0) &&
           (func_800F20BC(unk_0[1], unk_1[1], tolerance) != 0);
}

s32 func_8008DD04(PlayerState *self)
{
    f32 y = func_8009C150(self);
    int is_high;
    is_high = (y - func_80096364(self)) > 60.0f;
    if (is_high != 0) {
        // Matching: the redundant empty if is needed for the match.
        if (!is_high) {
        }
        return player_isStable(self) == 0;
    }
}

void func_8008DD70(s32 arg0)
{
    func_8009E71C(arg0, 0x5);
}

int func_8008DD90(s32 self)
{
    s32 unk_0;
    if (func_8009E674(self, 0x10)) {
        return 1;
    }
    if (func_8009E674(self, 8)) {
        unk_0 = _badrone_entrypoint_1(self);
        return !unk_0;
    }
    return 0;
}

int func_8008DDEC(s32 self, s32 param_1, s32 param_2)
{
    f32 pos[3];
    func_8009C128(self, pos);
    func_800F0064(param_1, param_2, pos);
}

s32 func_8008DE24(PlayerState *arg0)
{
    func_80096568(arg0, 0xE00);
}

func_8008DE44(s32 param_0)
{
    return 0;
}

int func_8008DE50()
{
    return func_80096694() == 3;
}

int func_8008DE74(Actor *self)
{
    // Matching: the "| 0" is needed for the match.
    func_8009CA70(self, bs_getCurrentState() | 0, 0x4000);
}

// True when the player's height is within tolerance of ref_pos[1].
int func_8008DEA4(void *self, f32 ref_pos[3], f32 tolerance)
{
    f32 pos[3];
    func_8009C128(self, pos);
    return ref_pos[1] - tolerance <= pos[1] && pos[1] <= ref_pos[1] + tolerance;
}

int func_8008DF18(PlayerState *self)
{
    return bastatetimer_isActive(self, 6) != 0 ||
           (func_800A3378(self) == 1.0f && func_8009659C(self, 0x40) != 0);
}

int func_8008DF8C(PlayerState *self, s32 max_height)
{
    f32 unk_0[3];
    if (player_isStable(self))
        return 1;
    func_800963C0(self, unk_0);
    if (unk_0[1] < 0.35f && unk_0[1] >= 0.0f)
        return 0;
    return baphysics_get_vertical_velocity(self) < 0.0f &&
           func_8009C150(self) - func_80096364(self) < (f32) max_height;
}

int player_isStable(self)
PlayerState *self;
{
    return func_800A0FCC(self) && (baphysics_get_vertical_velocity(self) < 0.0f);
}

int func_8008E0C8()
{
    _bapackctrl_entrypoint_1();
}

int func_8008E0E8(PlayerState *self)
{
    return func_8008E23C(self) && (func_8008E0C8(self) == 0);
}

s32 func_8008E124(PlayerState *self)
{
    return func_8009CC68(self) != 0;
}

int func_8008E148(s32 self)
{
    return bastatetimer_isActive(self, 5) != 0 || func_800A3378(self) == 1.0f;
}

int func_8008E1A0()
{
    return func_80096694() == 0x18;
}

int func_8008E1C4(s32 self)
{
    s32 unk_0;
    s32 unk_1;
    unk_0 = func_8009659C(self, 0x10) && baflag_isFalse(self, 3);
    unk_1 = func_8009659C(self, 0x40) && baflag_isFalse(self, 4);
    if (unk_0 || unk_1) {
        return 1;
    }
    return 0;
}

s32 func_8008E23C(self)
PlayerState *self;
{
    s32 *self_addr;
    s32 unk_0;
    // Matching: going through the parameter's address is needed for the match.
    self_addr = &self;
    unk_0 = func_800F8B88(*self_addr);
    return unk_0 == 2;
}

s32 func_8008E260(PlayerState *self)
{
    s32 result;
    if (player_isStable()) {
        return 0;
    }
    // Matching: the bare block and the reuse of result as its own output are needed for the match.
    {
        result = func_800954E8(self, &result);
        if (!result) {
            return 0;
        }
    }
    return 1;
}

s32 func_8008E2AC(void)
{
    s32 state;
    s32 result;

    state = bs_getCurrentState();
    // Matching: the empty statements after some case labels are needed for the match.
    switch (state) {
        case 0x2B:;
        case 0x2C:
        case 0x2D:;
        case 0x2E:
        case 0x30:;
        case 0x39:
        case 0x4C:
            result = 1;
            break;
        default:
            result = 0;
    }
    return result;
}

// Angle between ideal and current yaw is over 135 degrees.
s32 func_8008E300(PlayerState *self)
{
    return mlAbsF(func_800F1DCC(yaw_getIdeal(self), yaw_get(self))) > 135.0f;
}

s32 player_inWater()
{
    return func_800A0FD8();
}

void func_8008E37C()
{
    func_800A0FE4();
}

int func_8008E39C(self)
PlayerState *self;
{
    s32 shoes = _bashoes_entrypoint_1(self);
    return !(shoes == 1) && !(shoes == 0) && !(shoes == 2);
}

s32 func_8008E3E8(PlayerState *self)
{
    return _bashoes_entrypoint_1(self) == 3;
}

int func_8008E40C()
{
    return _bashoes_entrypoint_1() == 4;
}

s32 func_8008E430()
{
    return _bashoes_entrypoint_1() == 5;
}

int func_8008E454(s32 self)
{
    f32 pos[3];

if ((func_800DB9B0() != 0) && (func_800BFAA4() != 0)) {
    func_8009C128(self, pos);
    return (_gcmapsects_entrypoint_4(pos) + 1) != 0;
}

return 1;
}
