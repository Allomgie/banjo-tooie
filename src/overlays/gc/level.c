// Level (world) change handling: on a change it resets per-map storage, timers, triggers and
// flags, records 'level entered' flags and updates the return point. Also per-level feature queries.

#include "gc/level.h"

typedef struct {
    s16 level;
    u16 flag;
    s16 map;
    s8 exit_a;
    s8 exit_b;
} LevelRule1322;
typedef struct {
    s16 level;
    s16 flag;
    s32 unk_4;
} GcLevelEntry;
extern GcLevelEntry D_808003D0_gclevel[10];
GcLevelEntry *func_80800314_gclevel();

extern u8 D_8012762C;
extern s8 D_8012762D;
extern u8 D_808003C0_gclevel[];

void func_8080016C_gclevel(s32, s32, s32, s32);
s32 func_80800270_gclevel(s32, s32, s32);

// Map enter: resets per-map state and records level-entered flags.
void gclevel_entrypoint_0(s32 map, s32 exit_id)
{
    s32 old_level;
    s32 new_level;

    old_level = D_8012762C;
    new_level = gclevel_entrypoint_2(map);
    if (func_800A824C() != 0) {
        func_800A8240();
        return;
    }
    if (func_80800270_gclevel(map, exit_id, new_level) != 0) {
        D_8012762D = new_level;
    }
    _cosectionstor_entrypoint_0();
    func_800A13A0();
    func_800CE524();
    func_800CEF7C();
    func_800DA104();
    func_8009E9A8();
    func_8080016C_gclevel(old_level, new_level, map, exit_id);
    func_800C75E8();
}

// Map leave.
void gclevel_entrypoint_1(void)
{
    if (func_800A824C() == 0) {
        func_8009E9A0();
        func_800CF2B0();
        func_800CE7DC();
        _cosectionstor_entrypoint_1();
        func_800C75C0();
    }
}

// Maps a map id to its level id.
s32 gclevel_entrypoint_2(s32 map)
{
    return D_8012762C = _gcsectionDll_entrypoint_4(map);
}

// Returns whether the level is opened; 1 if it has no rule.
u32 gclevel_entrypoint_3(u32 level)
{
    void *entry;

    entry = func_80800314_gclevel(level);
    if (entry == NULL) {
        return 1;
    }
    return func_800DA298(*(u16 *) ((u8 *) entry + 2));
}

// Pushes or updates the return point after a level change.
void func_8080016C_gclevel(s32 old_level, s32 new_level, s32 map, s32 exit_id)
{
    s16 return_map;
    if ((old_level != new_level) && ((func_8009E958() == 1) || (func_800D395C() != 0))) {
        if (new_level != 0xD) {
            if (new_level != 0x19) {
                if (new_level == 0x1A) {
                    map = 0x142;
                    exit_id = 3;
                }
                goto block_8;
            }
            if (old_level != 0xD) {
            block_8:
                func_8009EB8C((s16) map, (s16) exit_id);

                goto block_9;
            }
        }
    } else {
    block_9:
        if (func_8009EC7C() == 0) {
            return_map = (s16) map;
            if (map == 0x194) {
                exit_id = 1;
                return_map = 0x15D;
            } else {
                // Matching: empty else block needed for the match.
            }
            func_8009EB8C(return_map, (s16) exit_id);
        }
    }
}

// Returns the masked feature bits of the current level (levels 0xD-0x1B).
s32 gclevel_entrypoint_4(s32 feature_mask)
{
    if (D_8012762C >= 0xD && D_8012762C < 0x1C) {
        return D_808003C0_gclevel[D_8012762C - 0xD] & feature_mask;
    }
    return 0;
}

// Records the level-entered flag from the rule table, if the rule applies.
s32 func_80800270_gclevel(s32 map, s32 exit_id, s32 level)
{
    LevelRule1322 *rule;
    s32 rule_map;

    rule = func_80800314_gclevel(level);
    if (!rule) {
        return 1;
    }
    rule_map = rule->map;
    if (rule_map == -1) {
        func_800DA544(rule->flag);
    } else if (map == rule_map && (exit_id == rule->exit_a || exit_id == rule->exit_b)) {
        func_800DA544(rule->flag);
    } else {
        return func_800DA298(rule->flag);
    }
    return 1;
}

GcLevelEntry *func_80800314_gclevel(level)
s32 level;
{
    s32 i;

    for (i = 0; i < 10; i++) {
        if (level == D_808003D0_gclevel[i].level) {
            return &D_808003D0_gclevel[i];
        }
    }
    return NULL;
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM). Labels inside an object are
// linker symbols: D_808003D8_gclevel = D_808003D0_gclevel + 0x8, D_808003E0_gclevel = D_808003D0_gclevel + 0x10.
u8 D_808003C0_gclevel[16] = {0x45, 0x0,  0x0, 0x0, 0x0, 0x0, 0x0,  0x10,
                             0x0,  0x80, 0x0, 0x0, 0x0, 0x0, 0x40, 0x0};
GcLevelEntry D_808003D0_gclevel[10] = {
    0x10, 0x1E3, 0xB80AFF,  0xF,  0x1E4, 0xC71110,  0x12, 0x1E5, 0xD612FF,  0x14, 0x1E6, 0x1A703FF,
    0x15, 0x1E7, 0x11217FF, 0x16, 0x1E8, 0x10009FF, 0x17, 0x1E9, 0x12715FF, 0x18, 0x1EA, 0x13614FF,
    0x19, 0x1EB, 0x15D01FF, 0x1A, 0x1EC, 0x14203FF};
