// Most likely the player marker and hit detection (BK's bamarker): owns the player's marker,
// collects overlaps with the hit spheres, and handles being hit (damage, knockback, rumble).
#include "core2/1E67DA0.h"
#include "common.h"

#define LOCAL_RECORD (*(local_record **) ((u8 *) param_0 + 0xC))
typedef struct {
    u8 local_0[0x18];
    u16 local_1 : 15;
    u16 local_2 : 1;
} local_marker_8008E530;
typedef struct {
    u8 local_0[0x64];
    u32 local_1 : 14;
    u32 local_2 : 1;
    u32 local_3 : 17;
    u8 local_4[0x10];
    u32 local_5 : 28;
    u32 local_6 : 1;
    u32 local_7 : 3;
} local_actor;
extern s32 _chbounce_entrypoint_10(Actor *);
extern s32 _glhittableDll_entrypoint_4(s32, Unk80132ED0 *);
extern s32 _glhittableDll_entrypoint_2(s32);
extern s32 _glhittableDll_entrypoint_8(s32);
extern s32 _glhittableDll_entrypoint_3(s32, Unk80132ED0 *, s32);
extern s32 func_800F424C(PlayerState *);
extern void func_800EB210(Unk80132ED0 *, s32, s32);
typedef struct {
    u8 local_0[8];
    void (*local_1)(void);
    u8 local_2[12];
    u32 local_3 : 16;
    u32 local_4 : 11;
    u32 local_5 : 5;
    u8 local_6[12];
    u32 local_7 : 21;
    u32 local_8 : 1;
    u32 local_9 : 10;
} local_marker_8008E618;
typedef struct {
    local_marker_8008E618 *local_0;
    u8 local_1[20];
    s32 local_2;
} local_record;
extern void func_8009C128(PlayerState *, f32 *);
extern local_marker_8008E618 *func_800EBFD4(f32 *, s32, s32);
extern void baflag_clear(PlayerState *, s32);
extern f32 D_80126D08[];
extern u8 D_80126CE0[];
typedef struct {
    u8 pad_0[0x28];
    u32 local_0 : 22;
    u32 local_1 : 1;
    u32 local_2 : 9;
} local_9;
typedef struct {
    local_9 *local_0;
} local_10;
struct Func_8008E92C_Arg0 {
    u8 pad0[12];
    struct {
        u8 pad0[24];
        s32 unk18;
    } *unkC;
};
typedef struct {
    u8 pad0[0x28];
    u32 f0 : 22;
    u32 flag : 1;
    u32 f2 : 9;
} S2_8E974;
typedef struct {
    S2_8E974 *unk0;
} S1_8E974;
typedef struct {
    u8 pad0[0xC];
    S1_8E974 *unkC;
} S0_8E974;
typedef struct {
    u8 pad00[0x1A];
    u16 id : 11;
    u16 pad1A : 5;
} LocalMarker;
typedef struct {
    u8 pad00[0x5C];
    u8 health[3];
} LocalHealth;
typedef struct {
    u8 pad00[0x24];
    u32 flags;
} LocalActorInfo;
extern s32 func_800D3948();
extern Actor *func_80106790(LocalMarker *);
extern PlayerState *func_800F53D0(s32);
extern void baflag_set(PlayerState *, s32);
extern s32 func_8009BD44();
extern void func_800A17A8(PlayerState *, s32);
extern s32 func_800A1718(PlayerState *);
extern void func_8009AD14();
extern s32 func_800F0D90();
extern void func_800F76B0();
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern LocalActorInfo *func_80100368(Actor *);
extern void func_801096C8(Actor *, void *);
extern s32 D_80117CAC[];
int func_8008ED70();

s32 func_8008E4B0(void)
{
    return sizeof(BaUnknownC);
}

s32 *func_8008E4B8(PlayerState *player)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        player->unkC->unkC[i] = (s32) func_8009E138(player, i);
    }
    return player->unkC->unkC;
}

void func_8008E530(PlayerState *player, Unk80132ED0 *marker)
{
    Actor *actor;
    s32 hit;
    if (((local_marker_8008E530 *) marker)->local_2) {
        actor = func_80106790(marker);
        if (((local_actor *) actor)->local_2)
            return;
        if (((local_actor *) actor)->local_6 && _chbounce_entrypoint_10(actor))
            return;
    }
    hit = _glhittableDll_entrypoint_4(**(s32 **) ((u8 *) player + 0xC), marker);
    if (!func_800F424C(player) && _glhittableDll_entrypoint_2(hit) &&
        _glhittableDll_entrypoint_8(hit))
        return;
    if (!_glhittableDll_entrypoint_3(**(s32 **) ((u8 *) player + 0xC), marker, hit)) {
        func_800EB210(marker, **(s32 **) ((u8 *) player + 0xC), 0);
    }
}

// Creates the player's actor marker and installs the hit callback.
void func_8008E618(PlayerState *param_0)
{
    f32 pos[3];
    func_8009C128(param_0, pos);
    LOCAL_RECORD->local_0 = func_800EBFD4(pos, 1, 0);
    LOCAL_RECORD->local_0->local_8 = 1;
    LOCAL_RECORD->local_0->local_1 = func_8008ED70;
    LOCAL_RECORD->local_0->local_4 = *(s32 *) ((u8 *) param_0 + 0x184);
    baflag_clear(param_0, 8);
    LOCAL_RECORD->local_2 = -1;
}

// Frees the player's actor marker.
void func_8008E6BC(s32 *player)
{
    s32 *player_copy;
    s32 *player_copy_2;
    {
        player_copy = player;
        func_800EBFF4(**(s32 **) (player + 3));
        player_copy_2 = player_copy;
        // Matching: the extra copies and the empty statement are needed for the match.
        ;
        **(s32 **) (player_copy_2 + 3) = 0;
    }
}

// Per frame: finds markers overlapping the player's hit spheres and dispatches each hit.
void func_8008E6F0(PlayerState *player)
{
    f32 pos[3];
    // Matching: the unused locals are needed for the match.
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 unk_4;
    s32 unk_5;
    s32 unk_6;
    s32 unk_7;
    s32 unk_8;
    s32 i;
    f32 unk_9;
    func_8009C128(player, pos);
    func_800EC0EC(pos, *(u8 **) *(u8 **) ((char *) player + 0xC));
    baflag_clear(player, 8);
    if (((local_10 *) *(u8 **) ((char *) player + 0xC))->local_0->local_1) {
        if (func_80091E80(player, 8) != 0) {
            if (func_800EA068(0x20) == 0) {
                if (func_8008DAA8(player) == 0) {
                    unk_8 = func_800F54E4();
                    unk_5 = func_800F5410(unk_8);
                    if (unk_5 == 9) {
                        goto block_16;
                    }
                    if (unk_5 != 0xB) {
                        if (unk_5 == 0x11) {
                            if (func_800F6D24(unk_8) != 0) {
                                return;
                            }
                            goto block_16;
                        }
                    } else if (func_800F8B88() == 3) {
                        if (func_800F6D24(unk_8) != 0) {
                            return;
                        }
                        goto block_16;
                    }
                } else {
                    goto block_16;
                }
            } else {
                unk_8 = func_800EA068(8);
                unk_3 = func_800EA068(0x4000);
                unk_5 = baflag_isTrue(player, 0x3B);
                if (((unk_8 != 0) && (unk_3 != 0)) && (unk_5 != 0)) {
                    _bsfirstp_entrypoint_14(player);
                }
            block_16:
                func_800CB840(1, *(s32 **) ((char *) player + 0x184));

                unk_8 = 0;
            loop_17:
                unk_9 = func_8009E138(player, unk_8);

                if (unk_9 != 0) {
                    D_80126D08[unk_8] = unk_9;
                    func_8009E154(player, unk_8, (unk_8 * 0xC) + D_80126CE0);
                    unk_8 += 1;
                    if (unk_8 != 3) {
                        goto loop_17;
                    }
                }
                unk_5 = func_800CDBA8(*(u8 **) *(u8 **) ((char *) player + 0xC), D_80126CE0,
                                        D_80126D08, unk_8);
                i = 0;
                if (unk_5 > 0) {
                    do {
                        unk_3 = func_800CDFA8(i, &unk_7);
                        *(s32 *) ((char *) *(u8 **) ((char *) player + 0xC) + 0x18) = unk_7;
                        func_8008E530(player, unk_3);
                        i += 1;
                    } while (i < unk_5);
                }
                func_800CB870();
                *(s32 *) ((char *) *(u8 **) ((char *) player + 0xC) + 0x18) = -1;
            }
        }
    }
}

s32 func_8008E92C(struct Func_8008E92C_Arg0 *player)
{
    return player->unkC->unk18;
}

s32 func_8008E938(void *player)
{
    return *(s32 *) *(u32 *) ((u8 *) player + 0xC);
}

// Clears the marker collision bit.
void func_8008E944(PlayerState *player)
{
    u8 *marker = *(u8 **) *(u8 **) ((u8 *) player + 0xC);
    *(u8 *) (marker + 0x2A) &= ~2;
}

// Sets the marker collision bit.
void func_8008E95C(PlayerState *player)
{
    u8 *marker;
    marker = **(u8 ***) ((s8 *) player + 0xC);
    *(u8 *) ((s8 *) marker + 0x2A) = (u8) ((*(u8 *) ((s8 *) marker + 0x2A) & 0xFFu) | 2);
}

s32 func_8008E974(S0_8E974 *player)
{
    s32 result = 0;
    return player->unkC->unk0->flag ? 1 : result;
}

func_8008E9A0(s32 player, s32 value)
{
    *(s32 *) (*(s32 *) (player + 0xC) + 0x4) = value;
}

s32 func_8008E9AC(s32 player)
{
    return *(s32 *) (*(s32 *) (player + 0xC) + 0x4);
}

int func_8008E9B8(s32 player, s32 *out)
{
    s32 spheres;
    spheres = func_8008E4B8(player);
    *out = spheres;
    return 3;
}

// Marker callback: the player was hit. Applies damage and picks the reaction.
void func_8008E9E4(LocalMarker *player_marker, LocalMarker *hit_marker, s32 hit)
{
    s32 hit_type;
    s32 damage;
    s32 reaction;
    s32 player_id;
    Actor *hitter;
    PlayerState *player;
    s32 unk_0;
    s32 unk_1;

    unk_0 = (!func_800D3948() || func_800F6774(func_800F54E4())) && !func_800F9184();
    damage = _glhittableDll_entrypoint_8(hit);
    reaction = 0;
    hitter = func_80106790(hit_marker);
    player_id = player_marker->id;
    player = func_800F53D0(player_id);
    if (_glhittableDll_entrypoint_9(hit))
        baflag_set(player, 8);
    if ((func_8009BD44(player) != 3 && func_800F6C1C(player_id)) || !damage) {
        hit_type = _glhittableDll_entrypoint_5(hit);
        if (hit_type > 0 && hit_type < 6) {
            reaction = 2;
            damage = damage - 1 < 0 ? 0 : damage - 1;
        }
        if (hit_type >= 7 && hit_type < 12 &&
            (_glhittableDll_entrypoint_9(hit) < 2 ||
             (_glhittableDll_entrypoint_6(hit) != -1 &&
              ((LocalHealth *) hitter)->health[_glhittableDll_entrypoint_6(hit)]))) {
            reaction = 1;
        }
        if (damage && unk_0) {
            if (_glhittableDll_entrypoint_8(hit) == 3)
                func_800A17A8(player, -999);
            else
                func_800A17A8(player, -damage);
        }
        if (!func_800A1718(player))
            reaction = 2;
        if (reaction != 2 || unk_0) {
            switch (reaction) {
                case 0:
                    func_8009AD14(player, hit_marker);
                    func_8009E7C8(player, 0x72);
                    break;
                case 1:
                    hit_type = func_800F0D90(hit_type, 7, 11) - 7;
                    unk_1 = func_8010108C(hitter, 0x50, (hit_type << 16) | (player_id & 0xFFFF));
                    if (unk_1 > 0)
                        hit_type = func_800F0D90(unk_1 - 1, 0, 4);
                    func_800F76B0(player_id, hit_type + 8, hit_marker);
                    _bamotor_entrypoint_1(player, 0.8f, (f32) hit_type + 0.2f, 0.3f);
                    break;
                case 2:
                    hit_type = func_800F0D90(hit_type, 1, 5) - 1;
                    unk_1 = func_8010108C(hitter, 0x50, (hit_type << 16) | (player_id & 0xFFFF));
                    if (unk_1 > 0)
                        hit_type = func_800F0D90(unk_1 - 1, 0, 4);
                    func_800F79DC(player_id, hit_type + 3, hit_marker);
                    _bamotor_entrypoint_1(player, 1.0f, (f32) hit_type + 0.3f, 0.5f);
                    if (func_80100368(hitter)->flags & 0x3000000) {
                        func_801096C8(hitter, **(void ***) ((u8 *) player + 0xC));
                    }
            }
        }
    }
}

int func_8008ED70()
{
    return (int) D_80117CAC;
}

// TU-NOTE: The .data of this file is defined here in C (values taken from the ROM). Its tables
// hold pointers to functions of this file; IDO's assembler schedules some of them differently
// unless the tables live in the same unit. D_80117CAC is declared s32[] (uses are NAME[0]).
u32 D_80117CA0[3] = {0x0, 0x0, 0x0};
s32 D_80117CAC[5] = {0x0, 0x0, 0x0, (u32) func_8008E9E4, 0x0};
