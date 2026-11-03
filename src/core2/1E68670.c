#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 func_8010D5DC;
extern int func_8008E938(void *param_0);
extern void *func_800CB840(int param_1, int param_2);
extern void func_800CB870(void);
extern void func_80109C4C(int param_1, int param_2, int param_3, void *param_4, int param_5,
                          int param_6, int param_7);
extern s32 bs_getCurrentState(PlayerState *);
extern s32 func_800A3274(PlayerState *);
extern s32 baflag_isTrue(PlayerState *, s32);
extern s32 func_8008DC90(PlayerState *, f32 *, f32);
extern s32 func_8008DAE8(PlayerState *, f32 *, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_8008E92C(PlayerState *);
extern s32 _bstrexsmall_entrypoint_7(PlayerState *, f32 *);
extern s32 _bstrexlarge_entrypoint_7(PlayerState *, f32 *);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern s32 player_isStable(PlayerState *);
extern void func_8008E9A0(s32, s32);
extern s32 func_800D1B34(s32);
extern s32 func_800D1C38(s32);
extern void func_800904C8(s32);
typedef struct {
    void *marker;
    u8 pad[0x60];
    u32 unused : 8, flag : 1, rest : 23;
} LocalObject;
extern f32 yaw_get(s32);
extern LocalObject *func_80108474(s32, f32 *, s32);
typedef struct {
    u8 pad0[0x6C];
    u32 f1 : 11;
    u32 item_id : 12;
    u32 f3 : 9;
} S_8F6B8;
extern void *_bahold_entrypoint_5();
extern void _bahold_entrypoint_6(void *, void *);
extern s32 func_8008E9AC(void *);
extern void _chbaddiesetup_entrypoint_2(void *, s32, s32);
void func_8008EEC4();

s32 func_8008ED80(void)
{
    return 0x1;
}

void func_8008ED88(u8 *param_0, s32 param_1, s32 param_2)
{
    s32 *actor;
    s8 *base;
    base = (s8 *) param_0;
    actor = func_80106790(param_2);
    func_800F497C(*(s32 *) (base + 0x184));
    func_800F49A8(*(s32 *) ((s8 *) param_0 + 0x184), 1);
    func_800F49D4(*(s32 *) ((s8 *) param_0 + 0x184), &func_8010D5DC, *actor);
    base = actor; // Matching: base is reused for a second pointer.
    func_800F4A58(*(s32 *) ((s8 *) param_0 + 0x184), base + 4, 0x43FA0000);
}

func_8008EE04(s32 cond, s32 value)
{
    if (cond != 0)
        return value | 0; // Matching: needed for the match.
    return 0;
}

s32 func_8008EE1C(Actor *actor, u32 player_id)
{
    struct ActorMarker *player;
    s32 state;

    player = func_800F53D0(player_id);
    state = bs_getCurrentState(player);
    switch (state) {
        case 15:
            return ((u32) (s32) (*(s32 *) ((char *) actor + 0x74) << 12) >> 31) == 0;
        case 19:
            return (*(u16 *) ((char *) actor + 0x74) & 1) == 0;
        default:
            return 1;
    }
}

int func_8008EE88(s32 param_0, s32 param_1)
{
    f32 pos[3];
    func_8009C128(param_0, pos);
    func_8008EEC4(param_0, pos, param_1, 0x270);
}

// Area damage around pos, filtered per player state.
void func_8008EEC4(param_0, pos, param_2, param_3) void *param_0;
s32 pos;
s32 param_2;
s32 param_3;
{
    func_800CB840(1, *(s32 *) ((char *) param_0 + 0x184));
    func_80109C4C(pos, param_2, 2, &func_8008EE1C, *(s32 *) ((char *) param_0 + 0x184),
                  func_8008E938(param_0), param_3);
    func_800CB870();
}

// Returns the current attack type of the player, 0 if none.
s32 func_8008EF3C(player, target)
PlayerState *player;
Unk80132ED0 *target;
{
    struct {
        s32 predicate, flag, state, result;
    } info; // Matching: locals grouped in a struct.

    info.state = bs_getCurrentState(player);
    switch (func_800A3274(player)) {
        case 2:
            return func_8008EE04(baflag_isTrue(player, 0x3C), 9);
        case 0xD:
            if (info.state == 0xF7)
                return func_8008EE04(baflag_isTrue(player, 0x2C), 0xF);
            return 0;
        case 0xE:
            if (info.state == 0xFC)
                return func_8008EE04(baflag_isTrue(player, 0x2B), 0xE);
            if (info.state == 0xFB)
                return func_8008EE04(baflag_isTrue(player, 0x2D), 0x10);
            return 0;
        case 0xF:
            if (info.state == 0x10E)
                return func_8008EE04(baflag_isTrue(player, 0x32), 0x11);
            return 0;
        case 0x10:
            return 0x12;
        case 0xB:
            switch (info.state) {
                case 0xC2:
                case 0xC4:
                    return func_8008EE04(baflag_isTrue(player, 0x36), 0x15);
                case 0x18A:
                case 0x18B:
                    return 0x19;
            }
            if (baflag_isTrue(player, 0x35)) {
                if (target) {
                    if (func_8008DC90(player, func_80106790(target)->position, 90.0f))
                        return 0x14;
                    return 0;
                }
                return 0x14;
            }
            return 0;
        case 9:
            info.flag = baflag_isTrue(player, 0x3B);
            info.predicate = !func_8008E92C(player);
            if (info.flag && info.predicate)
                return 0x16;
            return 0;
        case 0x12:
            if (target && _bstrexsmall_entrypoint_7(player, func_80106790(target)->position))
                return 0x18;
            return 0;
        case 0x13:
            if (target && _bstrexlarge_entrypoint_7(player, func_80106790(target)->position))
                return 0x17;
            return 0;
    }

    if (**(u8 **) ((u8 *) player + 0x18))
        return 3;
    switch (info.state) {
        case 0x189:
            return func_8008EE04(baflag_isTrue(player, 0x3E), 0xD);
        case 0xE4:
            return func_8008EE04(baflag_isTrue(player, 0x28), 0xC);
        case 0xA9:
            return 5;
        case 0xB6:
            return func_8008EE04(baflag_isTrue(player, 0x22), 0xB);
        case 0xF:
            return func_8008EE04(baflag_isTrue(player, 0x21), 1);
        case 0x13:
            return func_8008EE04(baflag_isTrue(player, 0x20), 2);
        case 0xB4:
            return func_8008EE04(baflag_isTrue(player, 0x20), 2);
        case 0x2A:
            return func_8008EE04(baflag_isTrue(player, 0x1C), 3);
        case 6:
            if (target && !func_8008DAE8(player, func_80106790(target)->position, 90.0f))
                return 0;
            info.result = func_8008EE04(baflag_isTrue(player, 0x1F), 4);
            if (info.result)
                return info.result;
            return 8;
        case 0x11:
            if (target && !func_8008DAE8(player, func_80106790(target)->position, 60.0f))
                return 0;
            return func_8008EE04(baflag_isTrue(player, 0x2A), 5);
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0xA4:
        case 0xA5:
            return 6;
        case 0x31:
            return func_8008EE04(baflag_isTrue(player, 0x29), 7);
        case 5:
        case 0x3D:
            if (baphysics_get_vertical_velocity(player) < 0.0f && !player_isStable(player))
                return 0xA;
        case 0x2F:
            if (baphysics_get_vertical_velocity(player) < -1400.0f && !player_isStable(player))
                return 0xA;
        case 0x124:
            return func_8008EE04(baflag_isTrue(player, 0x33), 0x13);
        case 0x18A:
            return 0x19;
    }
    return 0;
}

int func_8008F4F0(s32 param_0)
{
    s32 attack;
    attack = func_8008EF3C();
    if (attack == 0xB && baflag_isTrue(param_0, 0x26)) {
        return attack | 0; // Matching: needed for the match.
    }
    if (attack == 1 && baflag_isTrue(param_0, 0x27)) {
        return attack | 0; // Matching: needed for the match.
    }
    return 0;
}

s32 func_8008F568(s32 param_0, s32 item_id, s32 **param_2)
{
    s32 saved_id;
    s32 held;
    s32 *held_actor;

    saved_id = **param_2;
    held = _bahold_entrypoint_5();
    if (held != 0) {
        held_actor = func_80106790(held);
    }
    if ((held != 0) && (item_id != ((u32) (*(s32 *) ((char *) held_actor + 0x6C) << 11) >> 20))) {
        return 0;
    }
    func_8008E9A0(param_0, item_id);
    if (func_800D1C38(func_800D1B34(item_id)) != 0) {
        goto L_8008F600;
    }
    func_800904C8(0x12);
    goto L_8008F608; // Matching: goto layout needed for the match.
L_8008F600:
    return 0;
L_8008F608:
    *param_2 = func_80106790(saved_id);
    return 1;
}

void func_8008F62C(s32 param_0, s32 param_1)
{
    s32 player;
    LocalObject *held;
    f32 pos[3];
    player = func_800F53D0(param_0);
    func_80092D44(player, pos);
    held = func_80108474(param_1, pos, (s32) yaw_get(player));
    held->flag = 1;
    _bahold_entrypoint_6(player, held->marker);
    if (!func_8009E674(player, 0x400))
        bs_setState(player, 0x3A);
}

void func_8008F6B8(void *param_0, s32 item_id)
{
    void *held;
    S_8F6B8 *held_actor;
    held = _bahold_entrypoint_5(param_0);
    if (held != 0) {
        held_actor = func_80106790(held);
    }
    if ((held != 0) && (item_id == held_actor->item_id)) {
        _bahold_entrypoint_6(param_0, held);
    } else {
        _chbaddiesetup_entrypoint_2(func_8008F62C, *(s32 *) ((u8 *) param_0 + 0x184),
                                    func_8008E9AC(param_0));
    }
}

void func_8008F748(s32 param_0, s32 param_1, s32 param_2)
{
    f32 pos[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(param_1, param_2), pos);
    func_800A3514(param_0, pos);
}

s32 func_8008F788(s32 param_0, s32 item_id)
{
    func_800D1844(func_800D1B34(item_id));
}

void func_8008F7B4(s32 param_0, s32 item_id)
{
    s32 held;
    u8 *held_actor;

    held = _bahold_entrypoint_5();
    if (held != 0) {
        held_actor = func_80106790(held);
    }
    if ((held != 0) && (item_id == ((u32) (*(s32 *) ((s8 *) held_actor + 0x6C) << 0xB) >> 0x14))) {
        _bahold_entrypoint_4(param_0);
    }
    func_800D1804(func_800D1B34(item_id));
}

s32 func_8008F828(s32 param_0, s32 item_id)
{
    func_800D1A04(func_800D1B34(item_id));
}

int func_8008F854(s32 param_0, s32 item_id)
{
    int item; // Matching: self-assignment inside the call needed for the match.
    func_800D1824(func_800D1B34(item | (item = item_id)));
}

int func_8008F880(s32 param_0, s32 param_1)
{
    s32 actor;
    actor = func_80106790(param_0);
    func_800EE7F8(param_1, actor + 4);
}
