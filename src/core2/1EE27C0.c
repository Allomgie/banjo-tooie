#include "common.h"

extern s32 D_801245D0[];
extern s32 D_801245E4[];
extern s32 D_801245F8[];
typedef struct {
    u8 pad00[0x5C];
    u8 health[3];
} LocalHealth;
typedef struct {
    void *data;
    void *bones;
    u8 pad08[0x12];
    u16 id : 11;
    u16 pad1A : 5;
    u8 pad1C[8];
    u32 kind : 10;
    u32 pad24 : 22;
} LocalMarker_80108F08;
extern s32 _glhittableDll_entrypoint_10(s32);
extern s32 _glhittableDll_entrypoint_7(s32);
extern s32 _glhittableDll_entrypoint_9(s32);
extern s32 _glhittableDll_entrypoint_6(s32);
extern s32 _glhittableDll_entrypoint_8(s32);
extern void *func_80100368(Actor *);
extern s32 func_800F70EC(s32);
extern s32 func_800F6C1C(s32);
extern s32 func_80102FA0(void *, u32);
extern void func_800EC398(LocalMarker_80108F08 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void _chbounce_entrypoint_3(f32);
extern void _chbounce_entrypoint_2(f32);
extern void _chbounce_entrypoint_5(s32, Actor *);
extern void _chflamer_entrypoint_1(Actor *, LocalMarker_80108F08 *);
extern void _chfreezy_entrypoint_1();
extern void func_800EC370();
extern f32 func_8010CD28(Actor *);
extern void func_800EE904(s32 *, f32 *);
extern void func_800DBEFC(void *, s32, f32 *);
extern void func_800EB860();
extern void func_800EB874(void);
extern void _chbaddiesetup_entrypoint_10(void);
extern void _chbaddiesetup_entrypoint_5(void (*)(void), s32, s32, s32, s32, s32);
extern f32 func_800EC708(LocalMarker_80108F08 *);
extern s32 _gccubesearch_entrypoint_16(s32 *, void **, s32 **, s32, s32);
extern void func_800EE88C(f32 *, s32 *);
extern void func_800C4B7C(s32);
extern void func_8010D930(s32, s32, f32 *, void *);
extern u8 D_8012460C[];
extern void _subaddiejoy_entrypoint_10(Actor *, f32, f32);
extern void func_800BBCB8(s32, s32, f32, s32, void *);
extern u8 D_8012461C[];
extern s32 D_8012464C[];
extern u8 D_801245A0[];
typedef struct {
    u8 pad[0x24];
    u32 kind : 10, unused : 22;
} LocalMarker_80109538;
extern s32 _subaddiecustomhits_entrypoint_4(void *, f32 *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800B53A4();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern f32 D_80124688[];
extern f32 func_800DC178(f32, f32);
extern u8 func_800DC128(s32, s32);
extern void func_800B4470(f32 *, f32 *, f32 *, s32, f32, f32, s32, s32, s32);
typedef struct local_marker local_marker;
typedef struct {
    u8 pad_00[12];
    s32 (*hit_test)(local_marker *, f32 *, f32, f32 *, u32);
} local_info;
struct local_marker {
    u8 pad_00[12];
    local_info *(*get_info)(void);
    u8 pad_10[8];
    u32 unk_18_a : 11;
    u32 unk_18_b : 4;
    u32 unk_18_c : 12;
    u32 unk_18_d : 4;
    u32 unk_18_e : 1;
};
extern f32 func_800EC75C(local_marker *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern f32 func_800EEFD4(f32 *);
typedef struct Marker1099D0 Marker1099D0;
struct Marker1099D0 {
    u8 pad[0x14];
    u16 id;
    u8 pad1[2];
    u16 flags;
    u8 pad2[10];
    u32 kind_word;
    u32 pad3 : 22;
    u32 enabled : 1;
    u32 pad4 : 9;
};
typedef struct {
    Marker1099D0 *marker;
    s32 pad;
    u32 pad1 : 27;
    u32 selected : 1;
    u32 pad2 : 3;
    u32 valid : 1;
} Entry1099D0;
typedef struct {
    u8 pad[0x64];
    union {
        struct {
            u32 pad : 14;
            u32 disabled : 1;
            u32 pad1 : 17;
        } bits;
        struct {
            u16 pad;
            u16 mask;
        } halves;
    } flags;
    u8 pad1[11];
    u8 unk_6F;
} Actor1099D0_801099D0;
typedef struct {
    u8 pad[0x10];
    s32 (*can_hit)(Marker1099D0 *, Marker1099D0 *);
} Handler1099D0;
extern void **func_800BE444();
extern s32 func_800CB854(s32);
extern Entry1099D0 *func_800E9E88(void *);
extern Entry1099D0 *func_800E9EB4(void *);
extern Actor1099D0_801099D0 *func_80106790(Marker1099D0 *);
extern Handler1099D0 *func_800EC3C4(Marker1099D0 *);
extern s32 _glhittableDll_entrypoint_1(Marker1099D0 *, Marker1099D0 *);
extern void func_800EB210(Marker1099D0 *, Marker1099D0 *, s32);
typedef struct {
    u8 pad_00[0x24];
    u32 kind : 10;
    u32 pad_24 : 22;
} local_type;
typedef struct {
    u8 pad[0x64];
    union {
        struct {
            u32 pad : 14;
            u32 disabled : 1;
            u32 pad1 : 17;
        } bits;
        struct {
            u16 pad;
            u16 mask;
        } halves;
    } flags;
    u8 pad1[11];
    u8 pad2 : 6;
    u8 unk_6F : 1;
    u8 pad3 : 1;
} Actor1099D0_80109CC4;
typedef struct LocalMarker_8010A01C {
    u8 pad00[0x14];
    u16 id;
    u8 pad16[2];
    u16 flags18;
    u8 pad1A[0xA];
    u32 kind : 10, pad24 : 22;
    u32 pad28 : 22, enabled : 1, tail28 : 9;
} LocalMarker_8010A01C;
typedef struct LocalEntry {
    LocalMarker_8010A01C *marker;
    u32 unknown;
    u32 pad08 : 27, selected : 1, tail08 : 3, valid : 1;
} LocalEntry;
typedef struct LocalActor {
    u8 pad00[0x64];
    union {
        struct {
            u32 upper : 14, disabled : 1, lower : 17;
        } bits;
        struct {
            u16 upper, mask;
        } halves;
    } flags;
    u8 pad68[0x2C];
    u32 upper94 : 14, enabled : 1, lower94 : 17;
} LocalActor;
extern s32 func_8010108C(Actor *, s32, s32);
extern Unk80132ED0 *func_80101080(void);
extern f32 func_800F0C68(f32 *, f32 *, f32, f32);
extern void func_80103DFC(Actor *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern s32 func_800F0BD0(f32 *, f32 *, f32, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern u8 D_8012762C;
int func_800DC298(f32 param_0);
int func_80102F74(int param_0, int param_1);
typedef struct {
    u8 pad0[8];
    u32 f0 : 28;
    u32 bit : 1;
    u32 f2 : 3;
} S2_10A654;
typedef struct {
    S2_10A654 *unk0;
} S1_10A654;
int func_80109600();
void func_80109748(f32 *param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4, s32 param_5,
                   s32 param_6, s32 param_7);
int func_8010A430();
int func_8010A610();

int func_80108ED0()
{
    return (int) D_801245D0;
}

int func_80108EDC()
{
    return (int) D_801245E4;
}

int func_80108EE8()
{
    return (int) D_801245F8;
}

func_80108EF4(u16 *param_0, u16 param_1)
{
    return param_0[4] == 0x23A;
}

// Applies a hit to one of three health counters at actor+0x5C; knockback, reactions, drop on death.
void func_80108F08(LocalMarker_80108F08 *victim, LocalMarker_80108F08 *attacker, s32 hit)
{
    Actor *actor;
    s32 drop_type;
    s32 knockback;
    s32 damage;
    s32 health_idx;
    void *info;
    s32 temp;
    s32 attacker_id;
    s32 amount;
    f32 unk_0;
    f32 attacker_pos[3];
    s16 unk_1[3];
    f32 unk_2;
    f32 drop_pos[3];
    void *unk_3;
    s32 *unk_4;
    s32 unk_5[3];
    f32 drop_y;
    f32 unk_6;

    actor = func_80106790(victim);
    drop_type = _glhittableDll_entrypoint_10(hit);
    knockback = _glhittableDll_entrypoint_7(hit);
    damage = _glhittableDll_entrypoint_9(hit);
    health_idx = _glhittableDll_entrypoint_6(hit);
    info = func_80100368(actor);
    temp = attacker->kind == 0;
    if (temp) {
        attacker_id = attacker->id;
        if (!func_800F70EC(attacker_id) || !func_800F6C1C(attacker_id)) {
            if (_glhittableDll_entrypoint_8(hit))
                return;
        }
    }
    if (!health_idx) {
        if (!damage && attacker->kind)
            return;
        if (damage <= 0)
            damage = 1;
    }
    if (damage) {
        amount = func_80102FA0(info, 0x80000020) ? damage : 100 / damage;
        temp = ((LocalHealth *) actor)->health[health_idx] - amount;
        amount = temp < 0 ? 0 : temp;
        if ((((LocalHealth *) actor)->health[health_idx] = amount) && damage >= 2)
            knockback /= 2;
    }
    if (knockback) {
        func_800EC398(attacker, attacker_pos);
        unk_0 = func_800F1DF4(attacker_pos, actor->position);
        _chbounce_entrypoint_3(unk_0);
        _chbounce_entrypoint_2(unk_0);
        if (actor->unk64_25)
            _chbounce_entrypoint_5(knockback + 10, actor);
        else
            _chbounce_entrypoint_5(knockback + 5, actor);
    }
    if (damage) {
        switch (health_idx) {
            case 2:
                if (func_80102FA0(info, 0x2000000))
                    func_80109600(actor, attacker);
                break;
            case 1:
                if (func_80102FA0(info, 0x1000000))
                    func_80109600(actor, attacker);
        }
        if (func_80102FA0(info, 0x80020000) && attacker->kind == 0x26D) {
            _chflamer_entrypoint_1(actor, attacker);
        }
        if (func_80102FA0(info, 0x200) && attacker->kind == 0x26E) {
            func_800EC370(attacker, unk_1);
            _chfreezy_entrypoint_1(actor, unk_1);
        }
        if (!((LocalHealth *) actor)->health[health_idx] ||
            (health_idx && func_80102FA0(info, 0x10000))) {
            if (((LocalHealth *) actor)->health[health_idx])
                health_idx--;
            if (health_idx != 2)
                ((LocalHealth *) actor)->health[health_idx] = 99;
            if (health_idx == 2 && drop_type && func_8010A430(actor)) {
                unk_2 = func_8010CD28(actor) + 180.0f;
                func_800EE904(unk_5, actor->position);
                if (victim->bones)
                    func_800DBEFC(victim->bones, 14, drop_pos);
                func_800EB860(func_80108EF4, actor);
                if (victim->bones &&
                    !(drop_pos[0] == 0.0f && drop_pos[1] == 0.0f && drop_pos[2] == 0.0f)) {
                    _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, drop_type + 2,
                                                *(s32 *) &drop_pos[0], *(s32 *) &drop_pos[1],
                                                *(s32 *) &drop_pos[2], *(s32 *) &unk_2);
                } else if (func_80102FA0(info, 0x81000000) &&
                           // Matching: the temporary assigned inside the argument is needed.
                           _gccubesearch_entrypoint_16(
                               unk_5, &unk_3, &unk_4, 3,
                               (s32) (unk_6 = func_800EC708(victim) * 4.0f))) {
                    func_800EE88C(drop_pos, unk_4);
                    _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, drop_type + 2,
                                                *(s32 *) &drop_pos[0], *(s32 *) &drop_pos[1],
                                                *(s32 *) &drop_pos[2], *(s32 *) &unk_2);
                } else {
                    drop_y = actor->position[1] + func_800EC708(victim);
                    _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, drop_type + 2,
                                                *(s32 *) &actor->position[0], *(s32 *) &drop_y,
                                                *(s32 *) &actor->position[2], *(s32 *) &unk_2);
                }
                func_800EB874();
            }
            func_800EB210(victim, attacker, health_idx);
        }
        if (health_idx && knockback) {
            func_800C4B7C(actor->unk6C_9 == 0x31E ? 0x41F : 0x415);
            func_8010D930(1, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position, D_8012460C);
            if (func_80102FA0(info, 0x2000000) || func_80102FA0(info, 0x1000000)) {
                _subaddiejoy_entrypoint_10(actor, 1.0f, 0.25f);
            }
        }
    }
}

void func_801094E0(s32 pos, f32 unk_0)
{
    func_800BBCB8(pos, pos, unk_0, 3, D_8012461C);
}

int func_80109518()
{
    return (int) D_8012464C;
}

int func_80109524(s32 index)
{
    s16 *entry;
    entry = &D_801245A0[index << 4];
    return *entry;
}

void func_80109538(void *actor, f32 *fallback_pos, LocalMarker_80109538 *attacker, s32 spawn_spark)
{
    f32 hit_pos[3];
    s32 variant;
    s32 emitter;
    if (!_subaddiecustomhits_entrypoint_4(actor, hit_pos, 0))
        func_800EE7F8(hit_pos, fallback_pos);
    if (attacker != NULL) {
        variant = attacker->kind == 0 ? 0 : 1;
    } else {
        variant = 0;
    }
    if (spawn_spark) {
        emitter = func_800B53A4(10, variant);
        func_800BA3FC(emitter, func_80109524(variant));
        func_800BABB8(emitter, hit_pos, hit_pos, 1.0f, func_80109518());
    }
    func_801094E0(hit_pos, 1.0f);
}

int func_80109600(actor, attacker)
s32 actor;
s32 attacker;
{
    f32 pos[3];
    func_80103DFC(actor, pos);
    func_80109538(actor, pos, attacker, 1);
}

s32 func_8010963C(s32 actor, s32 pos, s32 attacker)
{
    func_80109538(actor, pos, attacker, 1);
}

void func_8010965C(s32 actor)
{
    f32 hit_pos[3];
    s32 result;

    result = _subaddiecustomhits_entrypoint_4(actor, hit_pos, 0);
    if (result != 0) {
        result = func_800B53A4(0xA);
        func_800BA3FC(result, func_80109524(2));
        func_800BABB8(result, hit_pos, hit_pos, 1.0f, func_80109518());
    }
}

int func_801096C8(s32 actor, s32 attacker)
{
    f32 pos[3];
    func_80103DFC(actor, pos);
    func_80109538(actor, pos, attacker, 0);
}

void func_80109704(s32 base, s32 count, s32 y_min, s32 y_max, f32 unk_0, s32 unk_1,
                   s32 rand_min, s32 rand_max)
{
    func_80109748(base + 4, count, y_min, y_max, unk_0, unk_1, rand_min, rand_max);
}

void func_80109748(f32 *base, s32 count, s32 y_min, s32 y_max, f32 unk_0, s32 unk_1,
                   s32 rand_min, s32 rand_max)
{
    f32 velocity[3];
    f32 pos[3];
    s32 i;
    s32 rand_val;
    pos[0] = base[0];
    pos[2] = base[2];
    for (i = 0; i < count; i++) {
        pos[1] = base[1] + func_800DC178(y_min, y_max);
        velocity[1] = func_800DC178(4.0f, 10.0f);
        velocity[0] = func_800DC178(-8.0f, 8.0f);
        velocity[2] = func_800DC178(-8.0f, 8.0f);
        rand_val = func_800DC128(rand_min, rand_max);
        func_800B4470(pos, velocity, D_80124688, 1, unk_0, 50.0f, unk_1, rand_val, 0);
    }
}

// Tests whether the marker lies within radius of pos (custom hit test if the marker has one).
s32 func_801098D0(f32 *pos, f32 radius, local_marker *marker)
{
    f32 marker_pos[3];
    f32 reach;
    local_info *info;
    f32 unk_0[3];
    s32 result;
    if (marker->get_info) {
        info = marker->get_info();
        if (info->hit_test) {
            result = info->hit_test(marker, pos, radius, unk_0, marker->unk_18_d);
            if (result) {
                marker->unk_18_b = result;
                return 1;
            }
            return 0;
        }
    }
    reach = func_800EC75C(marker, marker_pos) + radius;
    func_800EF3DC(marker_pos, pos);
    return func_800EEFD4(marker_pos) < reach * reach ? 1 : 0;
}

s32 func_801099D0(f32 *pos, f32 radius, s32 hit_type,
                  s32 (*filter)(Actor1099D0_801099D0 *, void *), void *filter_arg,
                  Marker1099D0 *attacker)
{
    // Matching: unused local is needed for the match.
    s32 unk_0;
    void **cubes;
    Entry1099D0 *entry, *end;
    Marker1099D0 *marker;
    Actor1099D0_801099D0 *actor;
    Handler1099D0 *handler;
    s32 hit_any = 0;
    u32 mask;
    cubes = func_800BE444(pos);
    mask = func_800CB854(0) ? 1 << (func_800CB854(0) - 1) : 0;
    for (; *cubes; cubes++) {
        entry = func_800E9E88(*cubes);
        end = func_800E9EB4(*cubes);
        for (; entry < end; entry++) {
            if (!entry->selected || !entry->valid)
                continue;
            marker = entry->marker;
            if (marker == attacker || !marker->enabled || !(marker->flags & 1))
                continue;
            if (marker->id == 0 || marker->id == 0xFFFF)
                continue;
            actor = func_80106790(marker);
            if (actor->flags.bits.disabled || (actor->flags.halves.mask & mask))
                continue;
            if (filter && !filter(actor, filter_arg))
                continue;
            if (!func_801098D0(pos, radius, marker))
                continue;
            handler = func_800EC3C4(marker);
            if (handler->can_hit && !handler->can_hit(marker, attacker))
                continue;
            hit_any = 1;
            if (!_glhittableDll_entrypoint_1(attacker, marker))
                func_800EB210(marker, attacker, hit_type);
        }
    }
    return hit_any;
}

void func_80109BEC(s32 pos, f32 radius, s32 hit_type, s32 filter, s32 filter_arg, s32 attacker)
{
    func_801099D0(pos, radius, hit_type, filter, filter_arg, attacker);
}

void func_80109C20(s32 pos, f32 radius, s32 hit_type, s32 filter)
{
    func_801099D0(pos, radius, hit_type, filter, 0, 0);
}

void func_80109C4C(s32 pos, f32 radius, s32 hit_type, s32 filter, s32 filter_arg,
                   local_type *attacker, s32 kind)
{
    // Matching: the copy of the radius is needed for the match.
    f32 radius_copy = radius;
    u32 old_kind;
    old_kind = attacker->kind;
    attacker->kind = kind;
    func_801099D0(pos, radius_copy, hit_type, filter, filter_arg, attacker);
    attacker->kind = old_kind;
}

s32 func_80109CC4(f32 *pos, f32 radius, Marker1099D0 *attacker)
{
    // Matching: unused local is needed for the match.
    s32 unk_0;
    void **cubes;
    Entry1099D0 *entry, *end;
    Marker1099D0 *marker;
    Actor1099D0_80109CC4 *actor;
    Handler1099D0 *handler;
    s32 hit_any = 0;
    u32 mask;
    cubes = func_800BE444(pos);
    mask = func_800CB854(0) ? 1 << (func_800CB854(0) - 1) : 0;
    for (; *cubes; cubes++) {
        entry = func_800E9E88(*cubes);
        end = func_800E9EB4(*cubes);
        for (; entry < end; entry++) {
            if (!entry->selected || !entry->valid)
                continue;
            marker = entry->marker;
            if (marker == attacker || !marker->enabled || !(marker->flags & 1))
                continue;
            if (marker->id == 0 || marker->id == 0xFFFF)
                continue;
            if ((marker->kind_word >> 22) == (attacker->kind_word >> 22))
                continue;
            actor = func_80106790(marker);
            if (actor->flags.bits.disabled || (actor->flags.halves.mask & mask))
                continue;
            if (!func_801098D0(pos, radius, marker))
                continue;
            handler = func_800EC3C4(marker);
            if (handler->can_hit && !handler->can_hit(marker, attacker))
                continue;
            hit_any = 1;
            actor->unk_6F = 1;
            if (!_glhittableDll_entrypoint_1(attacker, marker))
                func_800EB210(marker, attacker, 1);
        }
    }
    return hit_any;
}

// Actor flags at actor+0x66: read, write, clear and set.
int func_80109EE0(u16 *actor, unsigned long mask)
{
    return *(u16 *) ((s8 *) actor + 102) & mask;
}

void func_80109EEC(void *actor, unsigned int flags)
{
    ((s16 *) actor)[0x33] = flags;
}

int func_80109EF4(u16 *actor, unsigned long mask)
{
    actor[0x33] &= ~mask;
}

int func_80109F08(u16 *actor, unsigned int mask)
{
    actor[0x33] |= mask;
}

int func_80109F18(s32 actor, s32 *arg)
{
    // Matching: the all-ones mask chain and the address-taken parameter are needed for the match.
    int all_ones;
    s32 **arg_ptr;
    arg_ptr = &arg;
    all_ones = 0xFFFFFFFFFFFFFFFF;
    func_8010114C(
        actor,
        ((((((0x3E & all_ones) & all_ones) & all_ones) & all_ones) & all_ones) & all_ones) &
            all_ones,
        *arg_ptr);
}

int func_80109F40(s32 actor, s32 volatile arg)
{
    func_8010114C(actor, 0x3F, arg);
}

int func_80109F68(s32 actor, s32 volatile arg)
{
    func_8010114C(actor, 0x40, arg);
}

int func_80109F90(s32 actor, s32 volatile arg)
{
    func_8010114C(actor, 0x41, arg);
}

int func_80109FB8(s32 value, s32 marker)
{
    typedef struct {
        char pad[58];
        s32 unk3A;
    } Actor;
    Actor *actor;
    actor = (Actor *) func_80106790((Marker1099D0 *) marker);
    // Matching: empty block is needed for the match.
    if (!marker) {
    }
    actor->unk3A = value;
}

// Matching: the redundant masks and casts are needed for the match.
void func_80109FE8(u8 **handle, s32 clear_flag)
{
    u8 *flags_ptr;
    u8 *data_clr;
    u8 *data_set;
    if (clear_flag != 0) {
        data_clr = *handle;
        flags_ptr = (u8 *) ((s8 *) data_clr + 0x1B);
        *(u8 *) ((s8 *) data_clr + 0x1B) = (u8) (*flags_ptr & 0xFFFE);
        return;
    }
    data_set = *handle;
    *(u8 *) ((s8 *) data_set + 0x1B) = (u8) ((*(u8 *) ((s8 *) data_set + 0x1B) & 0xFFFF) | 1);
}

// Nearest marker of the given kind (-1 = any) whose target point lies inside the cone.
LocalMarker_8010A01C *func_8010A01C(f32 *origin, f32 *dir, f32 unk_0, f32 unk_1,
                                    s32 kind)
{
    void **cubes;
    s32 mask;
    f32 best_dist_sq;
    f32 unk_2;
    f32 dir_copy[3];
    s32 count;
    LocalActor *actor;
    LocalEntry *entry;
    LocalEntry *end;
    f32 *point;
    f32 dist_sq;
    LocalMarker_8010A01C *marker;
    LocalMarker_8010A01C *best;
    f32 actor_pos[3];
    f32 point_pos[3];
    f32 offset[3];
    u16 id;

    cubes = func_800BE444();
    if (func_800CB854(0))
        mask = 1 << (func_800CB854(0) + 0x1F);
    else
        mask = 0;
    func_800EE7F8(dir_copy, dir);
    unk_2 = func_800F0C68(origin, dir_copy, unk_0, unk_1);
    best_dist_sq = 1e+08f;
    best = 0;
    while (*cubes) {
        entry = func_800E9E88(*cubes);
        end = func_800E9EB4(*cubes);
        for (; entry < end; entry++) {
            if (!(entry->selected && entry->valid))
                continue;
            marker = entry->marker;
            if (!(!(kind + 1) || kind == (s32) marker->kind) || !marker->enabled)
                continue;
            id = marker->id;
            if (!(id && id != 0xFFFF && (marker->flags18 & 1)))
                continue;
            actor = (LocalActor *) func_80106790((Unk80132ED0 *) marker);
            if (!actor->enabled)
                continue;
            if (actor->flags.bits.disabled || (actor->flags.halves.mask & mask))
                continue;
            count = func_8010108C((Actor *) actor, 0xA2, 0);
            if (count > 0) {
                point = (f32 *) func_80101080();
            } else {
                func_80103DFC((Actor *) actor, actor_pos);
                point = actor_pos;
                count = 1;
            }
            while (count--) {
                func_800EE7F8(point_pos, point);
                func_800EFB24(offset, point_pos, origin);
                dist_sq = func_800EEFD4(offset);
                if (dist_sq < best_dist_sq && func_800F0BD0(offset, dir_copy, unk_0, unk_2)) {
                    best_dist_sq = dist_sq;
                    best = marker;
                }
                point += 3;
            }
        }
        cubes++;
    }
    return best;
}

// Finds the actor's point nearest to ref_pos; falls back to the marker position.
void func_8010A2FC(void **actor, f32 *out_pos, f32 *ref_pos)
{
    s32 count;
    f32 *point;
    f32 best_dist_sq;
    f32 point_pos[3];
    f32 dist_sq;
    count = func_8010108C(actor, 0xA2, 0);
    if (count > 0) {
        point = func_80101080();
        best_dist_sq = 1e+08f;
        while (count--) {
            func_800EE7F8(point_pos, point);
            dist_sq = func_800EEB40(point_pos, ref_pos);
            if (dist_sq < best_dist_sq) {
                func_800EE7F8(out_pos, point_pos);
                best_dist_sq = dist_sq;
            }
            point += 3;
        }
    } else
        func_800EC75C(*actor, out_pos);
}

// Collision size scale, stored as 8.8 fixed point at actor+0x92.
void func_8010A3E8(Actor *actor, f32 scale)
{
    s16 scale_fixed;
    scale_fixed = 256.0f * scale;
    *(s16 *) ((char *) actor + 0x92) = scale_fixed;
}

f32 func_8010A40C(u8 *actor)
{
    return (f32) *(s16 *) (actor + 0x92) * 0.00390625f;
}

// Whether a drop spawns; the chance depends on the level (D_8012762C).
int func_8010A430(actor)
int actor;
{
    if (func_80102F74(actor, 0x8000) != 0)
        return 1;
    switch (D_8012762C - 0xF) {
        case 4:
            return func_800DC298(1.0f);
        case 1:
            return func_800DC298(0.8999939f);
        case 0:
            return func_800DC298(0.7999878f);
        case 3:
            return func_800DC298(0.69999695f);
        case 5:
            return func_800DC298(0.59999084f);
        case 6:
            return func_800DC298(0.5f);
        case 7:
            return func_800DC298(0.3999939f);
        case 8:
            return func_800DC298(0.2999878f);
        case 9:
            return func_800DC298(0.19999695f);
        case 10:
            return func_800DC298(0.099990845f);
        case 11:
            return func_800DC298(0.8999939f);
    }
    return 1;
}

s32 func_8010A5B0();

void func_8010A570(s32 handle)
{
    func_8010A5B0(handle, 0);
}

void func_8010A590(s32 handle)
{
    func_8010A5B0(handle, 1);
}

// Sets or clears a flag (bit 1 of byte 0x2A) and returns its previous value.
// Matching: the redundant masks and casts are needed for the match.
s32 func_8010A5B0(u8 **handle, s32 set)
{
    s32 old;
    u8 *data_set;
    u8 *data_clr;
    u8 **handle_alias;
    old = func_8010A610();
    handle_alias = &*handle;
    if (set != 0) {
        data_set = *handle_alias;
        *(u8 *) ((s8 *) data_set + 0x2A) = (u8) (*(u8 *) ((s8 *) *handle + 0x2A) | 2);
    } else {
        data_clr = *handle;
        *(u8 *) ((s8 *) data_clr + 0x2A) = (u8) (*(u8 *) ((s8 *) data_clr + 0x2A) & 0xFFFD);
    }
    return old;
}

int func_8010A610(handle) void *handle;
{
    return ((u32) (*(s32 *) ((char *) ((*(s32 **) ((char *) handle + 0x0))) + 0x28)) << 0x16) >>
           31;
}

void func_8010A624(handle) void *handle;
{
    // Matching: the copy of the parameter is needed for the match.
    void *handle_copy;
    handle_copy = handle;
    ((u8 *) (*((void **) (*((void **) handle_copy)))))[0xb] &= ~8U;
}

void func_8010A63C(void *handle)
{
    typedef struct {
        u8 pad_0[0xB];
        u8 unk_0B : 4;
        u8 flag : 1;
    } Struct8010A63C_0;
    typedef struct {
        Struct8010A63C_0 *unk_0;
    } Struct8010A63C_1;
    typedef struct {
        Struct8010A63C_1 *unk_0;
    } Struct8010A63C_2;

    ((Struct8010A63C_2 *) handle)->unk_0->unk_0->flag = 1;
}

s32 func_8010A654(S1_10A654 **handle, s32 set)
{
    S2_10A654 *data = (*handle)->unk0;
    s32 old = data->bit;

if (set != 0) {
    data->bit = 1;
}

else
{
    data->bit = 0;
}
return old;
}

u32 func_8010A698(u8 ***handle)
{
    return (u32) ((*(s32 *) ((s8 *) (**handle) + (8))) << 0x1C) >> 0x1F;
}

// Line of sight between the player and the actor.
int func_8010A6B0(s32 actor, s32 player)
{
    f32 actor_pos[3];
    f32 player_pos[3];
    f32 hit_pos[3];

if (!func_800F4B4C(player)) {
    return 0;
}

func_800F57F0(player, player_pos);
func_80103DFC(actor, actor_pos);

if (func_800C6A7C(player_pos, actor_pos, hit_pos, 0x4A0021) != 0) {
    return 0;
}

return 1;
}

// TU-NOTE: The .data of this file is defined here in C. The tables hold pointers to functions of
// this file, and IDO's assembler schedules some of them differently unless the tables are in the
// same unit. Values are taken from the ROM. The externs for D_801245D0, D_801245E4, D_801245F8 and
// D_8012464C are declared as s32[] and used as NAME[0].
u8 D_801245A0[48] = {0x9, 0xE4, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0,
                     0x0, 0x0,  0x0, 0x0, 0x9, 0xE5, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0,
                     0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x9, 0xE2, 0x0, 0x0,
                     0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0};
s32 D_801245D0[5] = {(u32) func_80109F18, (u32) func_80109F40, (u32) func_80109F68,
                     (u32) func_80108F08, 0x0};
s32 D_801245E4[5] = {(u32) func_80109F18, (u32) func_80109F40, (u32) func_80109F68,
                     (u32) func_80108F08, (u32) func_80109F90};
s32 D_801245F8[5] = {(u32) func_80109F18, (u32) func_80109F40, (u32) func_80109F68, 0x0, 0x0};
u8 D_8012460C[16] = {0x0, 0x21, 0x0,  0x16, 0x65, 0x90, 0x0, 0x1,
                     0x3, 0x20, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
u8 D_8012461C[48] = {0x0, 0x1D, 0x9,  0xDD, 0x0, 0x2B, 0x0, 0x66, 0x0, 0x80, 0x0, 0x22,
                     0x0, 0xCC, 0x1,  0x33, 0x1, 0x66, 0x1, 0x99, 0x0, 0x15, 0x0, 0x19,
                     0x0, 0x99, 0x0,  0x19, 0x0, 0x0,  0x0, 0x7,  0x0, 0x2D, 0x0, 0x32,
                     0x0, 0x50, 0x80, 0x2,  0x0, 0xE,  0x0, 0xA,  0x0, 0x14, 0x0, 0x0};
s32 D_8012464C[15] = {0x150066, 0xCC0027,  0xC8,     0xF0,     0x161000,
                      0x150019, 0x660022,  0x660080, 0x400059, 0x2B0066,
                      0x80002D, 0x12C0190, 0xE000A,  0x140A1A, 0x0};
f32 D_80124688[2] = {-2.0392256e-34f, 0.0f};
