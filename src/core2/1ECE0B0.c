// Player roster (up to 8 PlayerState pointers) and per-index player API: spawn, despawn, per-frame
// update and draw, plus ~200 wrappers f(index, ...) used instead of touching PlayerState directly.
// TU-NOTE: This file is the first of two translation units split from one yaml entry
// (1ECE0B0 and 1ED2190). The ROM .rodata shows two objects: the jump table of func_800F608C
// ends at 0x1EFF974 and is padded to 0x1EFF980, where the next jump tables start. IDO
// aligns each object's .rodata to 16 bytes and never pads inside one, so this gap is the
// boundary. The second object starts at func_800F88A0 (ROM 0x1ED2190): the functions before
// it use the state block D_80135490..D_801354DC, the ones after it D_801354F0..D_80135521.

#include "core2/1ECE0B0.h"
#include "types.h"

extern void func_800F4200(void *, f32 *);
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800F4648(void *, f32 *);
extern void _badrone_entrypoint_14(s32, s32, f32);
extern void _badrone_entrypoint_15(s32 *param_0, s32 param_1, f32 param_2);
extern void _badrone_entrypoint_16(s32 *param_0, s32 param_1, f32 param_2);
extern f32 func_800A3048(s32);
extern void func_8009F678(PlayerState *, f32 *, f32 *, f32);
extern void func_8009F440(s32, s32, s32, s32, s32, f32);
extern void func_8009F860(PlayerState *, f32 *, f32, f32, f32, f32);
extern void func_8009FA20(s32, s32, s32, s32, f32);
typedef struct {
    u8 pad[0x17C];
    s32 active;
} LocalPlayer;
typedef struct {
    LocalPlayer *players[8];
    u8 pad[8];
    LocalPlayer *pending[8];
    u8 count;
} LocalState_800F5008;
extern u8 func_80092258(LocalPlayer *);
extern void func_80098BA8(LocalPlayer *, s32);
extern u8 D_801354B8[];
extern void func_80093528();
extern void func_80093584();
extern void func_80098BE0();
extern s32 _bafpctrl_entrypoint_5(void);
extern u32 _bafpctrl_entrypoint_4();
extern f32 bastatetimer_get(s32, s32);
extern s32 *func_80106790(s32);
extern void *_bahold_entrypoint_5();
extern void func_8008E9B8(void *, f32 *);
extern void func_800A3148();
extern f32 func_80092B8C(PlayerState *);
extern void func_8009C128(PlayerState *, f32 *);
extern f32 _basnowball_entrypoint_4(s32);
extern f32 func_8009BFD8(s32);
extern f32 baroll_getIdeal(s32);
s32 _badata_entrypoint_35(u32 param);
extern s32 func_800A907C(s32, s32, s32);
extern PlayerState *func_800F43A8(s32);
extern void func_800F3BB0(PlayerState *, f32 *);
extern void func_800F452C(PlayerState *, f32 *);
extern void func_800A92A8(s32, s32);
extern s32 func_800F4244(u32, u32);
extern f32 baphysics_get_target_horizontal_velocity(s32);
extern s32 bs_getCurrentState();
extern u8 D_8012762C;
extern void func_8008DAE8(s32 *param_0, s32 param_1, f32 param_2);
extern int baflag_isTrue(s32 param_0, s32 param_1);
extern f32 func_800964DC(s32);
extern s32 func_800966BC(s32);
extern f32 func_8009C150();
int _badata_entrypoint_14();
extern s32 func_8008DDEC(s32, s32, f32);
extern s32 func_8008DEA4(void *, f32 *, f32);
typedef struct {
    void *local_0[8];
    u8 local_1[8];
    u8 pad[0x21];
    u8 local_2, local_3;
    u8 pad2[5];
    s16 local_4, local_5;
} StateF73C4;
extern void func_800F80D8(u32);
void func_800F8128(s32 arg0);
u8 func_800F8B88(void);
extern s32 func_800DB9B0(void);
extern s32 _glcutDll_entrypoint_1(void);
extern s32 _plsu_entrypoint_1(s32);
extern void _basetup_entrypoint_2(void *);
extern u8 D_801354D9;
extern s32 D_801354B0[];
extern void _bamotor_entrypoint_1(void *param_0, f32 param_1, f32 param_2);
void func_8009AD20(s32, s32);
extern void func_8009AD04(s32 arg0, f32 arg1);
extern void func_8009AD44(s32 arg0, s32 arg1);
extern s32 func_8009E7C8(s32 arg0, s32 arg1);
extern void func_8009AD38(PlayerState *, s32);
extern void func_8009AD2C(PlayerState *, s32);
extern void func_8009ACF4(s32 param_0, f32 param_1);
extern void func_8009AD14(s32, Unk80132ED0 *);
extern void bastatetimer_set(s32, s32, f32);
extern void func_80098778(s32 a, s32 b, s32 c, f32 d, s32 e, s32 f, f32 g);
extern int func_80098730(int, int, int, f32, int, int);
void _bahold_entrypoint_7(s32 *param_0, f32 param_1, f32 param_2);
extern void baphysics_set_vertical_velocity(s32, f32);
extern void func_8009BD18(s32, f32);
typedef struct {
    void *players[8];
    u8 flags[8];
    u8 pad28[0x21];
    u8 updating;
    u8 pad4A[6];
    s16 previous, previous_state;
} LocalState_800F84FC;
extern s32 func_800F46D8(s32);
extern s32 func_8009E674(Unk80132ED0 *, s32);
void func_800EFA4C(f32 *param_0, f32 param_1, f32 param_2, f32 param_3);
s32 func_800F68B8();
s32 func_800F6C1C();
int func_800F6CC8();
s32 func_800F7B1C(s32 param_0, s32 param_1, f32 param_2, f32 param_3);
void func_800F7E64(s32 param_0, f32 param_1[3]);
int func_800F8088();
void func_800F8B94();
void func_800F9198();
int func_800F99E8();

// Player slot table: 8 PlayerState pointers. D_801354DC is the character in control.
extern int D_80135490[];
extern u8 D_801354DA;

extern u32 D_801354DC;

// Group: the 8-slot player roster (spawn, despawn, iterate, controlled index, update, draw).
// Calls callback for every active player.
// Matching: the line breaks in this function are needed for the match.
void func_800F47C0(s32 (*callback)(u8 *))
{
    s32 *slot;
    s32 *end;
    u8 *player;
    end = (u8 *) D_801354B0; slot = (u8 *) D_80135490;
    do
    {
        player = *slot;
        if ((player != 0) && (*(s32 *) ((char *) player + 0x17C) != 0))
        {
            callback(player);
        }
        slot++;
    }
    while (slot != end);
}

// Despawns the players of the given character, or all players when 0.
void func_800F482C(s32 character)
{
    s32 *slot;
    s32 player;
    s32 index;
    slot = &D_80135490;
    index = 0;
    do {
        player = *slot;
        if (player != 0) {
            if (character != 0) {
                if (func_800A3274(player) == character) {
                    goto block_5;
                }
            } else {
            // Matching: the goto into the else branch is needed for the match.
            block_5:
                func_800F3880(player = *slot);

                func_800A91F4(index);
                *slot = 0;
            }
        }
        index += 1;
        slot += 1;
    } while (index != 8);
}

// Group: index-based wrappers over PlayerState (position, state, ability, input, item queries).
void func_800F48BC(s32 player_index, f32 *unk_1)
{
    f32 unk_2[3];
    f32 unk_3[3];
    void *player = (void **) D_80135490[player_index];
    func_800F4200(player, unk_2);
    func_800EFA20(unk_3, unk_1, func_800D8FF8());
    func_800EF04C(unk_2, unk_3);
    func_800F4648(player, unk_2);
}

void func_800F4924(s32 player_index, s32 unk_1)
{
    func_800A17A8(((PlayerState **) D_80135490)[player_index], unk_1);
}

void func_800F4950(s32 player_index)
{
    _baattach_entrypoint_2((PlayerState **) D_80135490[player_index]);
}

void func_800F497C(s32 player_index)
{
    _badrone_entrypoint_5((PlayerState **) D_80135490[player_index]);
}

void func_800F49A8(s32 player_index)
{
    _badrone_entrypoint_10((PlayerState **) D_80135490[player_index]);
}

void func_800F49D4(s32 player_index, void *unk_1, s32 unk_2)
{
    _badrone_entrypoint_11(((PlayerState **) D_80135490)[player_index], unk_1, unk_2);
}

void func_800F4A00(s32 player_index)
{
    _badrone_entrypoint_12((PlayerState **) D_80135490[player_index]);
}

void func_800F4A2C(s32 player_index)
{
    _badrone_entrypoint_13((PlayerState **) D_80135490[player_index]);
}

void func_800F4A58(s32 player_index, s32 unk_1, f32 unk_2)
{
    _badrone_entrypoint_14((PlayerState **) D_80135490[player_index], unk_1, unk_2);
}

void func_800F4A8C(s32 player_index, s32 unk_1, f32 unk_2)
{
    _badrone_entrypoint_15((PlayerState **) D_80135490[player_index], unk_1, unk_2);
}

void func_800F4AC0(s32 player_index, s32 unk_1, f32 unk_2)
{
    _badrone_entrypoint_16((PlayerState **) D_80135490[player_index], unk_1, unk_2);
}

void func_800F4AF4(s32 player_index)
{
    func_800A4DA4((PlayerState **) D_80135490[player_index]);
}

void func_800F4B20(s32 player_index)
{
    func_800A4E30((PlayerState **) D_80135490[player_index]);
}

s32 func_800F4B4C(s32 player_index)
{
    u32 player;
    u32 result;
    player = ((u32 *) D_80135490)[player_index];
    if (func_8009E674(player, 0x200000)) {
        result = 0;
    } else {
        result = 1;
    }
    // Matching: the no-op `| 0` is needed for the match.
    return result | 0;
}

s32 func_800F4B8C(u32 player_index, u32 unk_1, s32 unk_2)
{
    return func_800F3930((PlayerState **) D_80135490[player_index], unk_1, unk_2);
}

s32 func_800F4BB8(u32 player_index, u32 unk_1, s32 unk_2)
{
    return func_800F3A78((PlayerState **) D_80135490[player_index], unk_1, unk_2);
}

s32 func_800F4BE4(s32 player_index)
{
    u32 player;
    u32 result;
    player = ((u32 *) D_80135490)[player_index];
    if (func_8009E674(player, 0x20000)) {
        result = 0;
    } else {
        result = 1;
    }
    // Matching: the no-op `| 0` is needed for the match.
    return result | 0;
}

s32 func_800F4C24(s32 player_index)
{
    s32 player;
    s32 state;
    // Matching: empty block steers IDO's code generation.
    if (!player_index) {
    }
    player = D_80135490[player_index];
    if (func_800F6D24() != 0) {
        return 0;
    }
    if (func_800F68B8(player_index) != 0) {
        return 0;
    }
    if (func_800F6CC8(player_index) != 0) {
        return 0;
    }
    state = bs_getCurrentState(player);
    if ((state == 0xED) || (state == 0x157)) {
        return 0;
    }
    return 1;
}

void func_800F4CC0(s32 player_index)
{
    func_80091E6C((PlayerState **) D_80135490[player_index]);
}

void func_800F4CEC(s32 player_index, u32 unk_1)
{
    func_80091E48((PlayerState **) D_80135490[player_index], unk_1);
}

void func_800F4D18(s32 player_index, f32 box_min[3], f32 box_max[3])
{
    s32 player = (PlayerState **) D_80135490[player_index];
    func_8009F678(player, box_min, box_max, func_800A3048(player) * 1000.0f);
}

void func_800F4D74(s32 player_index, f32 *center, f32 half_x, f32 half_y, f32 half_z)
{
    f32 box_min[3];
    f32 box_max[3];
    PlayerState *player;
    player = ((PlayerState **) D_80135490)[player_index];
    func_800EFA4C(box_min, center[0] - half_x, center[1] - half_y, center[2] - half_z);
    func_800EFA4C(box_max, center[0] + half_x, center[1] + half_y, center[2] + half_z);
    func_8009F678(player, box_min, box_max, func_800A3048(player) * 1000.0f);
}

void func_800F4E5C(s32 player_index, s32 unk_1, s32 unk_2, s32 unk_3, s32 unk_4)
{
    s32 player;

    player = D_80135490[player_index];
    func_8009F440(player, unk_1, unk_2, unk_3, unk_4, func_800A3048(player) * 1000.0f);
}

void func_800F4EC8(s32 player_index, f32 *unk_1, f32 unk_2, f32 unk_3, f32 unk_4)
{
    PlayerState *player = ((PlayerState **) D_80135490)[player_index];
    func_8009F860(player, unk_1, unk_2, unk_3, unk_4, func_800A3048(player) * 1000.0f);
}

void func_800F4F34(s32 player_index, s32 unk_1, s32 unk_2, s32 unk_3)
{
    s32 player;
    f32 unk_4;
    s32 *unk_1_ptr;
    // Matching: taking the address of unk_1 is needed for the match.
    unk_1_ptr = &unk_1;
    player = (PlayerState **) D_80135490[player_index];
    unk_4 = func_800A3048(player) * 1000.0f;
    func_8009FA20(player, *unk_1_ptr, unk_2, unk_3, unk_4);
}

void func_800F4F98(s32 player_index)
{
    _baattach_entrypoint_5((PlayerState **) D_80135490[player_index]);
}

int func_800F4FC4()
{
    s32 unk_0;
    unk_0 = _plsu_entrypoint_1(0x11);
    if (unk_0 != -1) {
        // Matching: the no-op `| 0` is needed for the match.
        func_800F7B9C(unk_0 | 0, 0x1F);
    }
    func_80101180(0x15E, 0x2C, 0);
}

void func_800F5008(s32 unk_0)
{
    s32 i;
    s32 pending_count;
    LocalPlayer *player;
    for (pending_count = 0, i = 0; i < 8; i++) {
        player = (*(LocalState_800F5008 *) D_80135490).players[i];
        if (player && player->active) {
            if (0xFF == func_80092258(player)) {
                func_80098BA8(player, unk_0);
            } else {
                (*(LocalState_800F5008 *) D_80135490).pending[pending_count++] = player;
            }
        }
    }
    (*(LocalState_800F5008 *) D_80135490).count = pending_count;
}

void func_800F50D0(s32 unk_0)
{
    volatile long long *unk_1_ptr;
    volatile long long unk_1;
    s32 i;
    if (((u8 *) D_80135490)[0x48] != 0) {
        // Matching: pointer to a volatile local is needed for the match.
        unk_1_ptr = &unk_1;
        func_800CA7E4(func_800A8984(func_800A89F8()), unk_1_ptr);
        _bainvisible_entrypoint_9(&D_801354B8, ((u8 *) D_80135490)[0x48], unk_1_ptr);
        for (i = 0; i < ((u8 *) D_80135490)[0x48]; i++) {
            func_80098BA8(*(s32 *) (((u8 *) D_80135490 + (i * 4)) + 0x28), unk_0);
        }
    }
}

int func_800F5184()
{
    func_800F47C0(&func_80093528);
}

int func_800F51A8()
{
    func_800F47C0(&func_80093584);
}

int func_800F51CC()
{
    func_800F47C0(&func_80098BE0);
}

void func_800F51F0(s32 player_index)
{
    func_80093504((PlayerState **) D_80135490[player_index]);
}

// Group: interrupt and state request helpers that pack arguments and call the state's handler.
int func_800F521C(s32 player_index, f32 unk_1[3])
{
    s32 player;
    player = *(s32 *) ((char *) D_80135490 + player_index * 4);
    // Matching: the no-op `| 0` is needed for the match.
    bs_setState(player, _badata_entrypoint_35(player) | 0);
    func_800F457C(player, unk_1);
}

int func_800F5268(int player_index)
{
    if (_bafpctrl_entrypoint_4((u32 *) D_80135490[player_index]) != 3) {
        return 0;
    }
    if (_bafpctrl_entrypoint_5 != 0) {
        return 2;
    }
    return 1;
}

void func_800F52B8(s32 player_index)
{
    func_8008EF3C((PlayerState **) D_80135490[player_index]);
}

void func_800F52E4(s32 player_index)
{
    func_8008F4F0((PlayerState **) D_80135490[player_index]);
}

// Number of occupied player slots.
s32 func_800F5310(void)
{
    s32 count = 0;
    s32 i;
    for (i = 0; i < 8; i++) {
        if ((void **) D_80135490[i] != 0) {
            count++;
        }
    }
    return count;
}

AnimCtrl *func_800F5378(s32 player_index)
{
    return baanim_getAnimCtrlPtr(((PlayerState **) D_80135490)[player_index]);
}

void func_800F53A4(s32 player_index)
{
    func_8008E938((PlayerState **) D_80135490[player_index]);
}

PlayerState *func_800F53D0(s32 player_index)
{
    return D_80135490[player_index];
}

// Returns the player in a slot, or 0 for an out-of-range index.
PlayerState *func_800F53E4(s32 player_index)
{
    if (player_index >= 0 && player_index < 8) {
        return D_80135490[player_index];
    }
    return 0;
}

s32 func_800F5410(player_index)
s32 player_index;
{
    return func_800A3274(((PlayerState **) D_80135490)[player_index]);
}

s32 func_800F543C(s32 player_index)
{
    return 1 << (func_800A3274(((PlayerState **) D_80135490)[player_index]) + 0x1F);
}

void func_800F5470(s32 player_index)
{
    func_80098590((PlayerState **) D_80135490[player_index]);
}

f32 func_800F549C(s32 player_index, s32 unk_1)
{
    s32 player = (PlayerState **) D_80135490[player_index];
    if (player)
        return bastatetimer_get(player, unk_1);
    return 0.0f;
}

u32 func_800F54E4(void)
{
    return D_801354DC;
}

s32 func_800F54F0(s32 player_index)
{
    return bakey_getControllerIndex(((PlayerState **) D_80135490)[player_index]);
}

void func_800F551C(s32 player_index)
{
    // Matching: the extra temporaries and the empty if are needed for the match.
    s32 *players;
    s32 index = player_index;
    s32 index_copy;
    players = D_80135490;
    index_copy = index;
    func_800A3148(players[index_copy]);
    if (!index) {
    }
}

void func_800F554C(s32 player_index)
{
    func_80092BDC((PlayerState **) D_80135490[player_index]);
}

s32 func_800F5578(s32 player_index)
{
    return func_800A1718(((PlayerState **) D_80135490)[player_index]);
}

void func_800F55A4(s32 player_index)
{
    func_800A1760((PlayerState **) D_80135490[player_index]);
}

void func_800F55D0(s32 player_index)
{
    func_800965D4((PlayerState **) D_80135490[player_index]);
}

int func_800F55FC(s32 player_index)
{
    func_80096628((PlayerState **) D_80135490[player_index]);
}

void func_800F5628(s32 player_index)
{
    func_80096364((PlayerState **) D_80135490[player_index]);
}

void func_800F5654(s32 player_index)
{
    func_80096670((PlayerState **) D_80135490[player_index]);
}

void func_800F5680(s32 player_index)
{
    func_800963C0((PlayerState **) D_80135490[player_index]);
}

void func_800F56AC(s32 player_index)
{
    func_80096694((PlayerState **) D_80135490[player_index]);
}

Unk80132ED0 *func_800F56D8(s32 player_index)
{
    return _bahold_entrypoint_5((PlayerState **) D_80135490[player_index]);
}

s32 func_800F5704(s32 player_index)
{
    s32 player, held;
    s32 *field;
    player = ((volatile s32 *) D_80135490)[player_index];
    held = _bahold_entrypoint_5(player);
    if (held != 0) {
        field = (s32 *) ((u32) func_80106790(held) + 0x6c);
        return (s32) (((u32) *field << 11) >> 20);
    }
    return 0;
}

int func_800F5754(s32 player_index)
{
    void *held;
    held = _bahold_entrypoint_5((void **) D_80135490[player_index]);
    if (held != 0) {
        return *(u32 *) ((char *) held + 0x24) >> 0x16;
    }
    return 0;
}

void func_800F5794(s32 player_index)
{
    func_800F3B3C((PlayerState **) D_80135490[player_index]);
}

void func_800F57C0(s32 player_index)
{
    f32 unk_1[2];
    func_8008E9B8(D_80135490[player_index], unk_1);
}

void func_800F57F0(s32 player_index)
{
    func_800F3B90((PlayerState **) D_80135490[player_index]);
}

s32 func_800F581C(s32 player_index)
{
    s32 player = D_80135490[player_index];
    s32 result;

    if (func_8009650C(player)) {
        result = func_80096434(player);
    } else {
        result = 0;
    }
    return result;
}

void func_800F586C(s32 player_index)
{
    func_80098B5C((PlayerState **) D_80135490[player_index]);
}

// Maximum number of players.
s32 func_800F5898(void)
{
    return 8;
}

void func_800F58A0(s32 player_index)
{
    _bswalk_entrypoint_0((PlayerState **) D_80135490[player_index]);
}

void func_800F58CC(player_index) s32 player_index;
{
    func_80096394((PlayerState **) D_80135490[player_index]);
}

int func_800F58F8(s32 player_index)
{
    func_800A3354((PlayerState **) D_80135490[player_index]);
}

int func_800F5924(s32 player_index)
{
    return func_800A3360((PlayerState **) D_80135490[player_index]);
}

void func_800F5950(s32 player_index, f32 *top, f32 *bottom, f32 *unk_3)
{
    f32 unk_4;
    f32 mid;
    f32 span;
    f32 upper;
    func_800A3148(*(f32 **) ((f32 *) D_80135490 + player_index), &unk_4, &mid, &span);
    upper = (span * 0.5f) + mid;
    *top = upper;
    *bottom = mid - (span * 0.5f);
    *unk_3 = unk_4;
}

void func_800F59D4(s32 player_index)
{
    _bapackctrl_entrypoint_1((PlayerState **) D_80135490[player_index]);
}

void func_800F5A00(s32 player_index, f32 *pos)
{
    func_800F3BB0(((PlayerState **) D_80135490)[player_index], pos);
}

void func_800F5A2C(s32 player_index)
{
    func_800F3BD0((PlayerState **) D_80135490[player_index]);
}

void func_800F5A58(s32 player_index, s32 *out)
{
    f32 pos[3];
    s32 *player;
    player = &D_80135490[player_index];
    player = (s32 *) *player;
    func_800F3BB0(player, pos);
    out[0] = (s32) pos[0];
    out[1] = (s32) pos[1];
    out[2] = (s32) pos[2];
}

f32 func_800F5AD0(s32 player_index)
{
    return 4.0f;
}

void func_800F5AE0(s32 player_index)
{
    func_8009BFCC((PlayerState **) D_80135490[player_index]);
}

void func_800F5B0C(s32 player_index)
{
    func_8009CC68((PlayerState **) D_80135490[player_index]);
}

void func_800F5B38(player_index) s32 player_index;
{
    func_800F3E84((PlayerState **) D_80135490[player_index]);
}

f32 func_800F5B64(s32 player_index, f32 *unk_1)
{
    f32 unk_2;
    f32 unk_3;
    s32 player;

    player = D_80135490[player_index];
    func_80095870(player, &unk_3, &unk_2);
    func_8009C128(player, unk_1);
    unk_1[1] += unk_3;
    return unk_2;
}

void func_800F5BC4(s32 player_index)
{
    func_80092B8C(((PlayerState **) D_80135490)[player_index]);
}

f32 func_800F5BF0(s32 player_index, s32 unk_1)
{
    f32 ret;
    f32 unk_2[3];
    PlayerState *player = ((PlayerState **) D_80135490)[player_index];
    ret = func_80092B8C(player);
    func_8009C128(player, unk_2);
    func_800EF04C(unk_1, unk_2);
    return ret;
}

f32 func_800F5C44(s32 player_index)
{
    s32 player;

    player = *(s32 *) (D_80135490 + player_index);
    if (func_800A3274(player) != 2) {
        return 0.0f;
    }
    return _basnowball_entrypoint_4(player);
}

void func_800F5C94(s32 player_index)
{
    func_800F3ED0((PlayerState **) D_80135490[player_index]);
}

void func_800F5CC0(s32 player_index)
{
    bastick_getAngle((PlayerState **) D_80135490[player_index]);
}

void func_800F5CEC(s32 player_index)
{
    bastick_distance((PlayerState **) D_80135490[player_index]);
}

void func_800F5D18(s32 player_index)
{
    func_800F40EC((PlayerState **) D_80135490[player_index]);
}

void func_800F5D44(s32 player_index, f32 *unk_1)
{
    func_800A33CC((PlayerState **) D_80135490[player_index], unk_1);
}

void func_800F5D70(player_index) s32 player_index;
{
    func_8009BB24((PlayerState **) D_80135490[player_index]);
}

void func_800F5D9C(s32 player_index, f32 *unk_1)
{
    func_800F4200((PlayerState **) D_80135490[player_index], unk_1);
}

void func_800F5DC8(s32 player_index, f32 *rot)
{
    s32 player;
    player = *(s32 *) ((char *) D_80135490 + player_index * 4);
    rot[0] = func_8009BFD8(player);
    rot[1] = yaw_getIdeal(player);
    rot[2] = baroll_getIdeal(player);
}

void func_800F5E24(s32 player_index)
{
    func_800966BC((PlayerState **) D_80135490[player_index]);
}

void func_800F5E50(s32 player_index)
{
    func_800966E0((PlayerState **) D_80135490[player_index]);
}

void func_800F5E7C(s32 player_index)
{
    s32 player;
    player = (PlayerState **) D_80135490[player_index];
    if (func_80096544(player)) {
        func_800964DC(player);
    } else {
        func_8009C150();
    }
}

void func_800F5ECC(s32 player_index)
{
    func_800A4C68((PlayerState **) D_80135490[player_index]);
}

void func_800F5EF8(s32 player_index)
{
    func_800A4C88((PlayerState **) D_80135490[player_index]);
}

f32 func_800F5F24(u32 player_index)
{
    return yaw_get(((PlayerState **) D_80135490)[player_index]);
}

f32 func_800F5F50(s32 player_index)
{
    return yaw_getIdeal(((PlayerState **) D_80135490)[player_index]);
}

void func_800F5F7C(s32 player_index)
{
    func_8009C150((PlayerState **) D_80135490[player_index]);
}

int func_800F5FA8(s32 player_index)
{
    u32 *slot = &D_80135490[player_index];
    bakey_setState(*slot, 9, 2);
    return 1;
}

s32 func_800F5FE0(s32 player_index)
{
    u32 *slot;
    slot = &((PlayerState **) D_80135490)[player_index];
    bakey_setState((PlayerState *) *slot, 9, 0);
    return 1;
}

void func_800F6018(s32 player_index)
{
    u32 slot_addr = (u32) (u8 *) D_80135490 + (player_index << 2);
    bakey_setState(*(u8 **) slot_addr, 8, 2);
}

int func_800F604C(s32 player, s32 unk_1)
{
    // Matching: the `^ 0` and the extra temporary are needed for the match.
    int unk_2;
    unk_2 = unk_1 ^ 0;
    func_8009EAD0(unk_2);
    bs_setState(player, _badata_entrypoint_35(player) | 0);
    func_8009EAD0(1);
}

void func_800F608C(s32 player_index, s32 unk_1)
{
    u32 player = ((u32 *) D_80135490)[player_index];
    switch (unk_1 - 1) {
        case 0:
            bs_setState(player, _badata_entrypoint_35(player));
            break;
        case 1:
            func_800F604C(player, 4);
            break;
        case 2:
            func_800F604C(player, 3);
            break;
        case 3:
            func_800F604C(player, 2);
            break;
        case 4:
            func_800F604C(player, 5);
    }
}

// Spawns a player in the first free slot and returns its index (0 if none).
s32 func_800F6140(controller_index)
s32 controller_index;
{
    // Matching: the limit variable and the index copy are needed for the match.
    s32 limit = 8;
    s32 controller;
    s32 *slot;
    s32 index_copy;
    s32 mapped;
    s32 index;
    slot = &D_80135490;
    index = 0;
    while (1) {
        index_copy = index;
        if (*slot == 0) {
            mapped = func_800A907C(index, controller_index, -1);
            controller = mapped;
            func_800A9768(mapped);
            func_800A93F8(index);
            func_800A93E4(index_copy);
            // Matching: empty block is needed for the match.
            if (index && index) {
            }
            *slot = func_800F43A8(index);
            ((s8 *) D_801354B0)[index] = 0;
            bakey_setControllerIndex(*slot, controller);
            return index;
        }
        index += 1;
        slot += 1;
        if (index == limit) {
            return 0;
        }
    }
}

int func_800F61E4()
{
    func_800F6140(-1);
}

int func_800F6204()
{
    func_800F6140();
}

// Spawns a copy of an existing player in a free slot and returns its index (0 if none).
s32 func_800F6224(s32 src_index)
{
    f32 pos[3];
    s32 i;
    PlayerState *new_player;
    PlayerState *src;
    s32 controller;
    for (i = 0; i < 8; i++) {
        if (!(PlayerState **) D_80135490[i]) {
            src = ((PlayerState **) D_80135490)[src_index];
            controller = func_800A907C(i, bakey_getControllerIndex(src), -1);
            ((PlayerState **) D_80135490)[i] = new_player = func_800F43A8(i);
            bakey_setControllerIndex(new_player, controller);
            func_800F3BB0(src, pos);
            func_800F452C(new_player, pos);
            yaw_setIdeal(new_player, yaw_getIdeal(src));
            yaw_applyIdeal(new_player);
            func_800A92A8(2, 2);
            return i;
        }
    }
    return 0;
}

// Spawns a player in a given slot at pos.
s32 func_800F6308(s32 player_index, s32 controller_index, s32 pos)
{
    s32 player;
    s32 unk_3;
    unk_3 = func_800A8FDC();
    func_800A907C(player_index, controller_index, unk_3);
    player = func_800F43A8(player_index);
    D_80135490[player_index] = player;
    bakey_setControllerIndex(player, controller_index);
    func_800F452C(player, pos);
    func_800A92A8(2, 2);
    return player;
}

void func_800F6388(s32 player_index, s32 unk_1)
{
    func_8008F788((PlayerState **) D_80135490[player_index], unk_1);
}

void func_800F63B4(s32 player_index)
{
    func_8008F7B4((PlayerState **) D_80135490[player_index]);
}

void func_800F63E0(s32 player_index, u32 unk_1)
{
    func_8008F854((PlayerState **) D_80135490[player_index], unk_1);
}

void func_800F640C(s32 player_index)
{
    func_8008F828((PlayerState **) D_80135490[player_index]);
}

s32 func_800F6438(u32 player_index)
{
    u32 player;
    u32 player_copy;
    player = ((u32 *) D_80135490)[player_index];
    player_copy = player;
    if (player_copy == 0) {
        return 0;
    }
    // Matching: the `^ 0` is needed for the match.
    return func_800F4244(player_copy ^ 0, player);
}

int func_800F6478(s32 player_index)
{
    func_800F424C((PlayerState **) D_80135490[player_index]);
}

s32 func_800F64A4(s32 player_index, AllowedTransformation transformation_type)
{
    return func_800F543C(player_index) & transformation_type ? 1 : 0;
}

void func_800F64DC(s32 player_index)
{
    s32 player;

    player = D_80135490[player_index];
    func_8009CA70(player, bs_getCurrentState(player), 0x400000);
}

int func_800F651C(s32 player_index)
{
    s32 player;
    f32 velocity;

    player = D_80135490[player_index];
    velocity = baphysics_get_target_horizontal_velocity(player);
    if (velocity == 0.0f) {
        return 1;
    }
    if (bs_getCurrentState(player) == 1) {
        return 1;
    }
    return func_8009E674(player, 0x1000);
}

s32 func_800F6590(s32 player_index)
{
    s32 player;
    player = D_80135490[player_index];
    return func_8009CBDC(player, bs_getCurrentState(player)) == 0xA;
}

int func_800F65D0(s32 player_index)
{
    return (D_8012762C == 0x1B) ? 1 : (D_801354DC == player_index);
}

int func_800F6604(s32 player_index)
{
    return _bacough_entrypoint_1(D_80135490[player_index]) == 2;
}

s32 func_800F6634(s32 player_index)
{
    return 0;
}

int func_800F6640(s32 player_index)
{
    s32 player = ((u32 *) D_80135490)[player_index];
    return func_80092EA4(player) && func_80091E80(player, 1);
}

void func_800F6690(s32 player_index)
{
    func_80092EB0((PlayerState **) D_80135490[player_index]);
}

void func_800F66BC(s32 player_index, s32 unk_1, f32 unk_2)
{
    func_8008DAE8((PlayerState **) D_80135490[player_index], unk_1, unk_2);
}

int func_800F66F0(s32 player_index)
{
    return bs_getCurrentState(D_80135490[player_index]) == 0x6F;
}

int func_800F6720(player_index)
s32 player_index;
{
    s32 player;

    player = D_80135490[player_index];
    return func_8009E71C(player, 9) || func_8008DE74(player);
}

int func_800F6774(u32 player_index)
{
    return func_800F6D24() == 0 && func_800F8088(player_index) == 0 && func_800F68B8(player_index) == 0 &&
           func_800F6CC8(player_index) == 0 && func_800A8264() == 0;
}

void func_800F67EC(s32 player_index)
{
    s32 player;

    player = D_80135490[player_index];
    func_8009CA70(player, bs_getCurrentState(player), 0x200);
}

s32 func_800F682C(s32 player_index)
{
    if (func_800F6D24() != 0) {
        return 0;
    }
    if (func_800F6478(player_index) == 0) {
        return 0;
    }
    if (func_8009BD44(*(D_80135490 + player_index)) == 3) {
        return 0;
    }
    if (func_800F6C1C(player_index) == 0) {
        return 0;
    }
    return 1;
}

s32 func_800F68B8(player_index)
s32 player_index;
{
    s32 player;
    player = *(s32 *) ((char *) D_80135490 + player_index * 4);
    if (func_8009E674(player, 8)) {
        return _badrone_entrypoint_3(player) == 1;
    }
    return 0;
}

int func_800F690C(player_index)
s32 player_index;
{
    baflag_isTrue((PlayerState **) D_80135490[player_index], 0x17);
}

void func_800F693C(s32 player_index)
{
    func_8008DD70((PlayerState **) D_80135490[player_index]);
}

int func_800F6968(s32 player_index)
{
    s32 player;
    s32 unk_0;
    f32 unk_1;
    player = (PlayerState **) D_80135490[player_index];
    unk_1 = func_800964DC(player);
    return ((s32) (unk_1 - func_8009C150(player) > 4.0f) != 0) &&
           (func_800966BC(player) & 0x2000) != 0;
}

int func_800F69E8(s32 player_index)
{
    s32 player = (PlayerState **) D_80135490[player_index];
    return player_isStable(player) && func_8009659C(player, 0x2000);
}

s32 func_800F6A38(s32 player_index)
{
    s32 player;
    s32 status_flags;

    player = D_80135490[player_index];
    if (!player_inWater(player)) {
        return 0;
    }

    status_flags = func_800966BC(player);
    if ((status_flags & 0x22000) == 0x22000) {
        status_flags = 1;
    } else {
        status_flags = 0;
    }
    return status_flags;
}

int func_800F6AA4(s32 player_index)
{
    s32 state = bs_getCurrentState((PlayerState **) D_80135490[player_index]);
    return state == 0x1B || state == 0x1C || state == 0x1D || state == 0x1E ||
           state == 0x1A || state == 0xA4 || state == 0xA5;
}

u8 func_800F6B34(void)
{
    return D_801354DA;
}

s32 func_800F6B40(s32 player_index)
{
    if (func_800F690C() != 0) {
        return 1;
    }
    return _ncba1p_entrypoint_10(func_800A4CA8(D_80135490[player_index])) == 3;
}

int func_800F6B94(int player_index)
{
    int player = D_80135490[player_index];
    return (func_800A3274(player) == 2) && (func_800A1718(player) >= 5);
}

int func_800F6BE4(s32 player_index)
{
    if (player_index >= 0 && player_index < 8) {
        if ((PlayerState **) D_80135490[player_index] != 0) {
            return 1;
        }
    }
    return 0;
}

s32 func_800F6C1C(player_index)
s32 player_index;
{
    s32 player;
    player = D_80135490[player_index];
    return func_8009CB44(player, bs_getCurrentState(player)) != 0;
}

int func_800F6C5C(s32 player_index)
{
    player_isStable((PlayerState **) D_80135490[player_index]);
}

s32 func_800F6C88(s32 player_index)
{
    s32 player;
    player = D_80135490[player_index];
    return func_8009CBDC(player, bs_getCurrentState(player)) == 2;
}

int func_800F6CC8(player_index)
s32 player_index;
{
    if (func_8009E674(D_80135490[player_index], 4)) {
        return 1;
    }
    if (func_800F8B64()) {
        return 1;
    }
    return 0;
}

int func_800F6D24(player_index)
s32 player_index;
{
    return func_8008E124((PlayerState **) D_80135490[player_index]);
}

int func_800F6D50(s32 player_index)
{
    s32 player = *(s32 *) &((u8 *) D_80135490)[player_index << 2];
    return func_8008E124(player) && func_8009E674(player, 0x10);
}

s32 func_800F6DA0(s32 player_index)
{
    s32 player;
    player = D_80135490[player_index];
    return func_8009CBDC(player, bs_getCurrentState(player)) == 0x12;
}

void func_800F6DE0()
{
    _bsbabykaz_entrypoint_14();
}

void func_800F6E00(s32 player_index)
{
    s32 player = D_80135490[player_index];
    func_8009CA70(player, bs_getCurrentState(player), 0x100000);
}

int func_800F6E40(s32 player_index)
{
    s32 player;
    player = D_80135490[player_index];
    return func_8009CBDC(player, bs_getCurrentState(player)) == 0x13;
}

void func_800F6E80(s32 player_index)
{
    func_800A336C((PlayerState **) D_80135490[player_index]);
}

s32 func_800F6EAC(s32 player_index)
{
    s32 player;
    player = (PlayerState **) D_80135490[player_index];
    if (func_8009E674(player, 8)) {
        return _badrone_entrypoint_3(player) == 9;
    }
    return 0;
}

int func_800F6F00(s32 player_index)
{
    f32 vecs[6];
    f32 unk_0;
    if (_badata_entrypoint_14(D_80135490[player_index]) == 0) {
        return 1;
    }
    func_800F58CC(player_index, &vecs[3]);
    if ((vecs[3] != 0.0f) || (vecs[5] != 0.0f)) {
        return 0;
    }
    if (func_800F6C5C(player_index) == 0) {
        return 0;
    }
    func_800F5D70(player_index, &vecs[0]);
    if ((func_800F55FC(player_index) & 0x8000) != 0) {
        if ((vecs[1] < 0.0f) && (vecs[1] >= -1.0f)) {
            return 1;
        }
        return 0;
    }
    if ((vecs[1] != -1.0f)) {
        return 0;
    }
    return 1;
}

int func_800F7018(s32 player_index)
{
    u32 player;
    // Matching: the extra block is needed for the match.
    {
        player = D_80135490[player_index];
    }
    return func_8009CBDC(player, bs_getCurrentState(player)) == 8;
}

s32 func_800F7058(s32 player_index)
{
    s32 player;
    // Matching: the redundant mask is needed for the match.
    player = *(s32 *) ((char *) D_80135490 + ((player_index * 4) & 0xFFFFFFFFFFFFFFFFu));
    if (func_8009E674(player, 128)) {
        return _bashoes_entrypoint_1(player) == 3 ? 2 : 1;
    }
    return 0;
}

void func_800F70BC(s32 player_index)
{
    func_8009E71C((PlayerState **) D_80135490[player_index], 0xE);
}

int func_800F70EC(s32 player_index)
{
    u32 unk_0;
    unk_0 = func_8009BD44(D_80135490[player_index]);
    return unk_0 != 3;
}

int func_800F711C(s32 player_index)
{
    u32 unk_0;
    unk_0 = func_8009E674(D_80135490[player_index], 8);
    return unk_0 < 1;
}

u32 func_800F7150(s32 player_index)
{
    u32 unk_0;
    unk_0 = func_80094510((u32 *) D_80135490[player_index]);
    return unk_0 == 7;
}

s32 func_800F7180(s32 player_index)
{
    s32 player;
    player = (PlayerState **) D_80135490[player_index];
    if (func_8009E674(player, 8)) {
        return _badrone_entrypoint_3(player) == 0xE;
    }
    return 0;
}

void func_800F71D4(s32 player_index)
{
    func_8008E37C((PlayerState **) D_80135490[player_index]);
}

s32 func_800F7200(s32 player_index, s32 param_1, f32 param_2, s32 param_3, s32 param_4)
{
    s32 player;
    s32 player_arg;
    // Matching: the nested assignment and comma expression are needed for the match.
    player = (PlayerState **) D_80135490[player = player_index];
    if ((param_2 < 0.0f) || (func_8008DDEC(player, param_1, param_2) != 0)) {
        player_arg = player;
        return func_8008F568((0, player_arg), param_3, param_4);
    }
    return 0;
}

s32 func_800F7270(s32 player_index, f32 *param_1, f32 param_2, f32 param_3, s32 param_4, s32 param_5)
{
    if (func_8008DEA4((void **) D_80135490[player_index], param_1, param_3) != 0) {
        return func_800F7200(player_index, param_1, param_2, param_4, param_5);
    }
    return 0;
}

int func_800F72DC(s32 player_index)
{
    s32 player = (PlayerState **) D_80135490[player_index];
    return func_8009640C(player) || baflag_isTrue(player, 0x26);
}

int func_800F732C()
{
    D_801354DA = 1;
    func_800F482C(0x11);
    func_800F482C(0);
    D_801354DA = 0;
}

void func_800F7364(s32 player_index)
{
    u32 *slot = (u32 *) ((char *) D_80135490 + (player_index << 2));
    if (*slot != 0) {
        func_80092AA4(*slot);
    }
}

int func_800F739C(s32 param_0, s32 param_1)
{
    // Matching: "| 0" is needed for the match.
    func_800C7074(param_1 | 0, 1);
}

// Resets the roster and spawns the initial players.
void func_800F73C4(s32 spawn_count)
{
    s32 i, live_count, unk_0, unk_1, control_index, unk_2;
    (*(StateF73C4 *) D_80135490).local_3 = 0;
    (*(StateF73C4 *) D_80135490).local_2 = 0;
    for (i = 0; i < 8; i++) {
        (*(StateF73C4 *) D_80135490).local_0[i] = 0;
        (*(StateF73C4 *) D_80135490).local_1[i] = 0;
    }
    (*(StateF73C4 *) D_80135490).local_5 = -1;
    (*(StateF73C4 *) D_80135490).local_4 = (*(StateF73C4 *) D_80135490).local_5;
    func_800F80D8(0);
    if (!func_800DB9B0() && !_glcutDll_entrypoint_1() && !func_800F99E8()) {
        for (i = 0; i < spawn_count; i++)
            func_800F61E4();
    }
    func_800F8B94();
    live_count = 0;
    for (i = 0; i < func_800F5898(); i++) {
        if (func_800F6BE4(i))
            live_count++;
    }
    if (!live_count)
        func_800F7E64(func_800F61E4(), 4);
    if (func_800F8B88() == 2) {
        unk_0 = _plsu_entrypoint_1(10);
        unk_1 = _plsu_entrypoint_1(11);
        if (unk_0 != -1 && unk_1 != -1) {
            if (func_800F65D0(unk_1))
                control_index = unk_1;
            else if (func_800F65D0(unk_0))
                control_index = unk_0;
            else
                control_index = _plsu_entrypoint_1(17);
            func_800F8128(control_index);
        }
    }
    for (i = 0; i < 8; i++) {
        if ((*(StateF73C4 *) D_80135490).local_0[i])
            _basetup_entrypoint_2((*(StateF73C4 *) D_80135490).local_0[i]);
    }
}

// Despawns the player now, or only flags the slot while the roster is updating.
void func_800F759C(s32 player_index)
{
    if (D_801354D9 != 0) {
        func_800F82C0(player_index);
        return;
    }
    func_80101238(0xB5, player_index);
    func_800F3880(*(s32 *) ((char *) (u8 *) D_80135490 + (player_index * 4)));
    func_800A91F4(player_index);
    *(s32 *) ((char *) (u8 *) D_80135490 + (player_index * 4)) = 0;
    *(u8 *) ((char *) D_801354B0 + player_index) = 0;
}

void func_800F7620(s32 player_index, f32 param_1, f32 param_2, s32 param_3)
{
    s32 *index_ptr;
    // Matching: going through a pointer to the parameter is needed for the match.
    index_ptr = &player_index;
    _bamotor_entrypoint_1((void **) D_80135490[*index_ptr], param_1, param_2);
}

void func_800F7664(s32 player_index, s32 p1, s32 p2)
{
    s32 player = (PlayerState **) D_80135490[player_index];
    func_8009AD20(player, p1);
    func_8009AD2C(player, p2);
    func_8009E7C8(player, 0x7D);
}

int func_800F76B0(s32 player_index, s32 param_1, f32 *param_2)
{
    s32 player;
    player = *(s32 *) ((char *) D_80135490 + player_index * 4);
    func_8009AD20(player, param_1);
    func_8009AD14(player, param_2);
    return func_8009E7C8(player, 0x24) == 2;
}

s32 func_800F7700(u32 player_index, s32 param_1, f32 *param_2)
{
    s32 player = (PlayerState **) D_80135490[player_index];
    func_8009AD20(player, param_1);
    func_8009AD44(player, param_2);
    return func_8009E7C8(player, 0x23) == 2;
}

s32 func_800F7750(s32 player_index, s32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
    s32 interrupt_id;
    s32 player;
    player = (PlayerState **) D_80135490[player_index];
    if (param_4 != 0) {
        interrupt_id = 0x98;
    } else {
        interrupt_id = 0x2D;
    }
    func_8009ACF4(player, param_2);
    func_8009AD04(player, param_3);
    func_8009AD20(player, 0xE);
    func_8009AD44(player, param_1);
    return func_8009E7C8(player, interrupt_id) == 2;
}

int func_800F77E8(int player_index, int param_1)
{
    func_800F7750(player_index, param_1, 840.0f, -1500.0f, 0);
}

void func_800F7814(s32 player_index, s32 p1)
{
    func_800F7750(player_index, p1, 840.0f, -1500.0f, 1);
}

void func_800F7844(s32 player_index, s32 param_1, f32 param_2, f32 param_3)
{
    func_800F7750(player_index, param_1, param_2, param_3, 0);
}

s32 func_800F7874(s32 player_index, s32 param_1, u32 param_2)
{
    s32 player;
    player = D_80135490[player_index];
    func_8009AD44(player, param_2);
    func_8009AD14(player, param_1);
    return func_8009E7C8(player, 0x66) == 2;
}

void func_800F78C8(s32 player_index, s32 arg1)
{
    func_800F7C58(player_index, 0x17, arg1);
}

s32 func_800F78EC(s32 player_index, f32 *param_1, f32 param_2, f32 param_3)
{
    f32 *player = ((f32 **) D_80135490)[player_index];
    func_8009ACF4(player, param_2);
    func_8009AD04(player, param_3);
    func_8009AD20(player, 0xE);
    func_8009AD44(player, param_1);
    return func_8009E7C8(player, 0x68) == 2;
}

void func_800F796C(s32 player_index, s32 arg1)
{
    func_800F798C(player_index, arg1, 0x1);
}

int func_800F798C(s32 player_index, s32 param_1, f32 *param_2)
{
    s32 player;
    player = *(s32 *) ((char *) D_80135490 + player_index * 4);
    func_8009AD20(player, param_1);
    func_8009AD2C(player, param_2);
    return func_8009E7C8(player, 0x1f) == 2;
}

int func_800F79DC(s32 player_index, s32 param_1, f32 *param_2)
{
    s32 player;
    player = *(s32 *) ((char *) D_80135490 + player_index * 4);
    func_8009AD20(player, param_1);
    func_8009AD14(player, param_2);
    return func_8009E7C8(player, 0x21) == 2;
}

int func_800F7A2C(s32 player_index, s32 param_1, f32 *param_2)
{
    s32 player;
    player = *(s32 *) ((char *) D_80135490 + player_index * 4);
    func_8009AD20(player, param_1);
    func_8009AD44(player, param_2);
    return func_8009E7C8(player, 0x20) == 2;
}

s32 func_800F7A7C(s32 player_index, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    PlayerState *player = ((PlayerState **) D_80135490)[player_index];
    func_8009AD38(player, param_1);
    func_8009AD20(player, param_2);
    func_8009AD2C(player, param_3);
    func_8009AD44(player, param_4);
    return func_8009E7C8(player, 0x4E) == 2;
}

int func_800F7AF4(int player_index, int param_1)
{
    func_800F7B1C(player_index, param_1, 840.0f, -1500.0f);
}

s32 func_800F7B1C(s32 player_index, s32 param_1, f32 param_2, f32 param_3)
{
    s32 player;
    player = D_80135490[player_index];
    func_8009ACF4(player, param_2);
    func_8009AD04(player, param_3);
    func_8009AD20(player, 0x10);
    func_8009AD44(player, param_1);
    return func_8009E7C8(player, 0x2E) == 2;
}

void func_800F7B9C(s32 player_index, u32 interrupt_id)
{
    func_8009E7C8((PlayerState **) D_80135490[player_index], interrupt_id);
}

void func_800F7BC8(s32 player_index, s32 interrupt_id, Unk80132ED0 *param_2)
{
    s32 player;
    player = *(s32 *) ((char *) (u32 *) D_80135490 + player_index * 4);
    func_8009AD14(player, param_2);
    func_8009E7C8(player, interrupt_id);
}

void func_800F7C0C(s32 player_index, f32 param_1[3], f32 param_2)
{
    s32 player;
    player = (PlayerState **) D_80135490[player_index];
    func_8009ACF4(player, param_2);
    func_8009E7C8(player, param_1);
}

int func_800F7C58(s32 player_index, f32 param_1[3], s32 param_2)
{
    s32 player;
    player = *(s32 *) ((char *) D_80135490 + player_index * 4);
    func_8009AD20(player, param_2);
    func_8009E7C8(player, param_1);
}

void func_800F7C9C(s32 player_index, s32 interrupt_id, s32 param_2, s32 param_3)
{
    s32 player;
    player = (PlayerState **) D_80135490[player_index];
    // Matching: "| 0" is needed for the match.
    func_8009AD20(player, param_2 | 0);
    func_8009AD2C(player, param_3);
    func_8009E7C8(player, interrupt_id);
}

void func_800F7CF4(s32 player_index, f32 param_1[3], s32 arg2)
{
    s32 player;
    player = *(s32 *) ((char *) D_80135490 + player_index * 4);
    func_8009AD44(player, arg2);
    func_8009E7C8(player, param_1);
}

void func_800F7D38(s32 player_index, s32 interrupt_id, u32 param_2, f32 param_3)
{
    s32 player;
    player = D_80135490[player_index];
    func_8009AD44(player, param_2);
    func_8009ACF4(player, param_3);
    func_8009E7C8(player, interrupt_id);
}

void func_800F7D90(s32 player_index, s32 interrupt_id, s32 param_2, s32 param_3)
{
    s32 player;
    player = *(s32 *) ((char *) D_80135490 + player_index * 4);
    // Matching: "| 0" is needed for the match.
    func_8009AD44(player, param_2 | 0);
    func_8009AD20(player, param_3);
    func_8009E7C8(player, interrupt_id);
}

int func_800F7DE8(s32 player_index, s32 param_1, s32 param_2)
{
    s32 player;

    player = D_80135490[player_index];
    func_8009AD20(player, param_2);
    func_8009AD14(player, param_1);
    return func_8009E7C8(player, 0x48) == 2;
}

int func_800F7E3C(s32 player_index, s32 param_1)
{
    u32 result;
    // Matching: "| 0" is needed for the match.
    result = func_800F7C58(player_index, 0x84, param_1 | 0);
    return result == 2;
}

void func_800F7E64(s32 player_index, f32 param_1[3])
{
    s32 player;
    player = (PlayerState **) D_80135490[player_index];
    func_800A3410(player, param_1);
    func_80092778(player);
}

int func_800F7E9C(s32 player_index, s32 param_1)
{
    if (param_1 != 0) {
        func_800A4E74(D_80135490[player_index]);
    }
}

void func_800F7ECC(s32 player_index, s32 param_1, f32 param_2)
{
    bastatetimer_set((PlayerState **) D_80135490[player_index], param_1, param_2);
}

void func_800F7F00(s32 player_index, s32 param_1, s32 param_2, f32 param_3, s32 param_4, s32 param_5,
                   f32 param_6)
{
    func_80098778(D_80135490[player_index], param_1, param_2, param_3, param_4, param_5, param_6);
}

int func_800F7F50(int player_index, int param_1, int param_2, f32 param_3, int param_4, int param_5)
{
    return func_80098730(D_80135490[player_index], param_1, param_2, param_3, param_4, param_5);
}

void func_800F7F98(s32 player_index, s32 enable)
{
    void *player;
    void *player_copy;
    player = (void **) D_80135490[player_index];
    if (enable != 0) {
        // Matching: the extra copy is needed for the match.
        player_copy = player;
        bakey_func_80091C14(player_copy, 1);
        bastick_func_8009F18C(player, 1);
    } else {
        player_copy = player;
        bakey_func_80091C14(player_copy, 0);
        bastick_func_8009F18C(player, 0);
    }
}

int func_800F8004(s32 player_index)
{
    int has_key;
    s32 player;
    int has_stick;
    player = (PlayerState **) D_80135490[player_index];
    has_key = bakey_getBitfield(player) != 0 || bakey_func_80091964(player) != 0;
    has_stick = bastick_func_8009F1A4(player) != 0 || bastick_func_8009EEF8(player) != 0;
    return has_key && has_stick;
}

int func_800F8088(player_index)
s32 player_index;
{
    u32 keys;
    u32 stick;
    u32 player;

    player = D_80135490[player_index];
    keys = bakey_getBitfield(player);
    stick = bastick_func_8009F1A4(player);
    return keys && stick;
}

void func_800F80D8(u32 character_index)
{
    D_801354DC = character_index;
}

void func_800F80E4(s32 player_index, u32 param_1)
{
    u32 unk_0;
    u32 player;

    player = ((u32 *) D_80135490)[player_index];
    if (param_1 != 0) {
        unk_0 = 0;
    } else {
        unk_0 = 1;
    }
    func_800947EC(player, 1, unk_0);
}

void func_800F8128(s32 character_index)
{
    func_800F80D8(character_index);
    func_800A91A8(character_index);
}

void func_800F8150(s32 player_index)
{
    func_80093370((PlayerState **) D_80135490[player_index]);
}

void func_800F817C(s32 player_index)
{
    func_8009337C((PlayerState **) D_80135490[player_index]);
}

void func_800F81A8(s32 player_index)
{
    func_800A1870((PlayerState **) D_80135490[player_index]);
}

void func_800F81D4(s32 player_index)
{
    _bafpctrl_entrypoint_12((PlayerState **) D_80135490[player_index]);
}

void func_800F8200(s32 player_index)
{
    func_800F4524((PlayerState **) D_80135490[player_index]);
}

void func_800F822C(s32 player_index, f32 param_1, f32 param_2)
{
    _bahold_entrypoint_7((PlayerState **) D_80135490[player_index], param_1, param_2);
}

void func_800F8268(s32 player_index, s32 a1, s32 a2)
{
    func_800A38F0(((PlayerState **) D_80135490)[player_index], a1, a2);
}

void func_800F8294(s32 player_index, f32 *a1)
{
    func_800F452C(((PlayerState **) D_80135490)[player_index], a1);
}

void func_800F82C0(player_index) s32 player_index;
{
    ((u8 *) D_801354B0)[player_index] = 1;
}

void func_800F82D4(s32 player_index, s32 arg1)
{
    func_800F457C((PlayerState **) D_80135490[player_index], arg1);
}

void func_800F8300(s32 player_index)
{
    func_800F45B0((PlayerState **) D_80135490[player_index]);
}

void func_800F832C(s32 player_index, f32 *a1)
{
    func_800F45E0((PlayerState **) D_80135490[player_index], a1);
}

void func_800F8358(s32 player_index, s32 param_1)
{
    // Matching: the extra copy of the index is needed for the match.
    s32 slot = player_index;
    s32 player = (PlayerState **) D_80135490[slot];
    _baduo_entrypoint_7(player, 3);
}

void func_800F838C(s32 player_index)
{
    func_8008F748((PlayerState **) D_80135490[player_index]);
}

void func_800F83B8(s32 player_index)
{
    func_800A3514((PlayerState **) D_80135490[player_index]);
}

void func_800F83E4(s32 player_index, f32 param_1)
{
    baphysics_set_vertical_velocity((PlayerState **) D_80135490[player_index], param_1);
}

void func_800F8418(s32 player_index, f32 *arg1)
{
    func_800F4648((PlayerState **) D_80135490[player_index], arg1);
}

void func_800F8444(s32 player_index, s32 *param_1)
{
    s32 player;
    player = (PlayerState **) D_80135490[player_index];
    func_8009BF5C(player, param_1[0]);
    yaw_setIdeal(player, *(f32 *) &param_1[1]);
    baroll_setIdeal(player, param_1[2]);
}

void func_800F849C(s32 player_index, f32 param_1)
{
    func_8009BD18((PlayerState **) D_80135490[player_index], param_1);
}

void func_800F84D0(s32 player_index)
{
    func_8009659C((PlayerState **) D_80135490[player_index]);
}

// Per-frame update of all players.
void func_800F84FC(void)
{
    f32 unk_0, unk_1;
    f32 unk_2;
    f32 unk_3[3];
    s32 i, j;
    s32 character, character_state;
    s32 k;
    for (i = 0; i < 8; i++) {
        if ((*(LocalState_800F84FC *) D_80135490).players[i] && func_800F5924(i)) {
            func_800F5A00(i, unk_3);
            func_800F5950(i, &unk_0, &unk_1, &unk_2);
            for (j = 0; j < 8; j++) {
                if ((*(LocalState_800F84FC *) D_80135490).players[j] && i != j &&
                    func_800F58F8(j))
                    func_800F4EC8(j, unk_3, unk_0, unk_1, unk_2);
            }
        }
    }
    (*(LocalState_800F84FC *) D_80135490).updating = 1;
    for (k = 0; k < 8; k++) {
        if ((*(LocalState_800F84FC *) D_80135490).players[k])
            func_800F468C((*(LocalState_800F84FC *) D_80135490).players[k]);
    }
    (*(LocalState_800F84FC *) D_80135490).updating = 0;
    func_800F9198();
    character = func_800F54E4();
    character_state = func_800F5410(character);
    if ((*(LocalState_800F84FC *) D_80135490).previous != -1 &&
        (character != (*(LocalState_800F84FC *) D_80135490).previous ||
         character_state != (*(LocalState_800F84FC *) D_80135490).previous_state) &&
        !func_800D5240())
        func_800A1658(character_state);
    for (k = 0; k < 8; k++) {
        if ((*(LocalState_800F84FC *) D_80135490).flags[k])
            func_800F759C(k);
    }
    (*(LocalState_800F84FC *) D_80135490).previous = character;
    (*(LocalState_800F84FC *) D_80135490).previous_state = character_state;
}

void func_800F86C4(s32 param_0, s32 param_1)
{
    *(s16 *) ((char *) (s16 *) D_80135490 + 0x50) = (s16) param_0;
    *(s16 *) ((char *) (s16 *) D_80135490 + 0x52) = (s16) param_1;
}

// Matching: the line breaks in this function are needed for the match.
void func_800F86D8()
{
    s32 *end;
    s32 *entry;
    entry = D_80135490; end = D_801354B0;
    do
    {
        if (*entry != 0)
        {
            *entry = func_800F46D8(*entry);
        }
        entry++;
    }
    while (entry != end);
}

s32 func_800F8730(s32 player_index, s32 param_1)
{
    s32 player;
    s32 accepted;

    player = D_80135490[player_index];
    func_800A3538(player);
    accepted = func_8009E7C8(player, 0xA) == 2;
    if (accepted && (func_800F5410(player_index) != param_1)) {
        _surestart_entrypoint_0(param_1);
    }
    return accepted;
}

s32 func_800F87A4(s32 player_index)
{
    Unk80132ED0 *player;
    s32 result;
    player = (Unk80132ED0 *) (u32 *) D_80135490[player_index];
    if (func_800F56D8(player_index)) {
        if (func_8009E674(player, 0x400)) {
            result = func_8009E7C8(player, 0x16);
            return result == 2;
        }
    }
    return 0;
}

void func_800F8804(s32 player_index)
{
    func_8009CD70((PlayerState **) D_80135490[player_index]);
}

void func_800F8830(s32 player)
{
    func_8009E7C8(player, 0x99);
}

void func_800F8850()
{
    func_800F47C0(&func_800F8830);
}

void func_800F8874(s32 player_index)
{
    func_8009224C((PlayerState **) D_80135490[player_index]);
}
