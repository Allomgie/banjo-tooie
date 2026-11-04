// Most likely the map-level glue of the collectible registry: jiggy ranges per world, resetting
// collected/spawned flags, spawning uncollected jiggies, saving/restoring jiggy positions.
#include "gc/collectDLL.h"

extern s16 D_80800BE2_gccollectDll;
extern s16 D_80800BE4_gccollectDll[];
extern s16 D_80800BE6_gccollectDll;
extern s16 D_80800BE8_gccollectDll[];
extern s16 D_80800BEA_gccollectDll;
extern s32 D_80800BEC_gccollectDll[];

extern s16 D_80800BE0_gccollectDll[];

extern s32 D_80800C0C_gccollectDll[3];
extern u32 D_80800C18_gccollectDll[10];
extern u8 D_8012762C;

// First jiggy index of the current level (SM: 0x5B), -1 if none.
s32 func_80800000_gccollectDll(void)
{
    s32 jiggy;
    u32 level;

    level = D_8012762C;
    // SM
    if (level == 0x13) {
        return 0x5B;
    }
    jiggy = func_800D0820(1);
    if (func_800D0894(1) >= jiggy) {
        do {
            if (func_800D06D4(jiggy, 1) == level) {
                return jiggy;
            }
            jiggy += 1;
        } while (func_800D0894(1) >= jiggy);
    }
    return -1;
}

// Clears the collected and spawned flags of a category.
void gccollectDll_entrypoint_0(s32 category)
{
    s32 flag;
    s32 flag_2;
    s32 i;

    i = func_800D0820(category);
    if (i < func_800D0894(category)) {
        do {
            flag = func_800D0A80(i, category);
            if (flag != 0) {
                func_800DA524(flag);
            }
            flag_2 = func_800D0908(i, category);
            if (flag_2 != 0) {
                func_800DA524(flag_2);
            }
            i += 1;
        } while (i < func_800D0894(category));
    }
}

// Clears the flags of all 9 categories.
void gccollectDll_entrypoint_1(void)
{
    s32 category;

    category = 0;
    do {
        gccollectDll_entrypoint_0(category);
        category += 1;
    } while (category != 9);
}

void gccollectDll_entrypoint_2(void)
{
    gccollectDll_entrypoint_1();
}

void gccollectDll_entrypoint_3(void)
{
}

// Map start: registers the level's 10 jiggies and runs the save fix.
void gccollectDll_entrypoint_4(void)
{
    s32 pad1;
    s32 pad2;
    s32 fix_arg;
    s32 first_jiggy = func_80800000_gccollectDll();
    s32 i;

    func_800CF870(first_jiggy);
    if (first_jiggy != -1) {
        fix_arg = func_800CFA90();
        for (i = first_jiggy; i < first_jiggy + 0xA; i++) {
            func_800D0778(i, 1, D_80800C0C_gccollectDll);
            func_800D05E4(i, 1, 0);
            func_800D0594(i, 1, 0);
        }
        // Outside a cutscene.
        if (func_800DB9B0() == 0) {
            _gcgamefix_entrypoint_1(fix_arg);
        }
    }
}

// Clears the spawned flag of virtual (non-placed) collectibles that are not collected.
void gccollectDll_entrypoint_5(void)
{
    u32 i = 0;

    if (func_800CF87C() != -1) {
        for (i = 0; i < 0x16; i += 2) {
            if ((func_800D0B68((u32) D_80800BE0_gccollectDll[i],
                               (u32) D_80800BE0_gccollectDll[i + 1]) == 0) &&
                (func_800D0A9C((u32) D_80800BE0_gccollectDll[i],
                               (u32) D_80800BE0_gccollectDll[i + 1]) != 0)) {
                func_800D0B38(D_80800BE0_gccollectDll[i], D_80800BE0_gccollectDll[i + 1]);
            }
        }
    }
}

// 1 if (jiggy, category) is in the pair tables.
s32 func_808002C4_gccollectDll(s32 jiggy, s32 category)
{
    s8 *entry;
    int one;
    if ((jiggy == D_80800BE0_gccollectDll[0]) && (category == D_80800BE2_gccollectDll)) {
        return 1;
    }
    if ((jiggy == D_80800BE4_gccollectDll[0]) && (category == D_80800BE6_gccollectDll)) {
        return 1;
    }
    entry = &D_80800BEC_gccollectDll;
    if ((jiggy == D_80800BE8_gccollectDll[0]) && (category == D_80800BEA_gccollectDll)) {
        return 1;
    }
    // Matching: extra temporary needed for the match.
    one = 1;
loop_10:
    if ((jiggy == *(s16 *) ((s8 *) entry + 0)) && (category == *(s16 *) ((s8 *) entry + 2))) {
        return 1;
    }

    if ((jiggy == *(s16 *) ((s8 *) entry + 4)) && (category == *(s16 *) ((s8 *) entry + 6))) {
        return 1;
    }
    if ((jiggy == *(s16 *) ((s8 *) entry + 8)) &&
        (category == *(s16 *) ((s8 *) entry + 0xA))) {
        return 1;
    }
    if ((jiggy == *(s16 *) ((s8 *) entry + 0xC)) &&
        (category == *(s16 *) ((s8 *) entry + 0xE))) {
        return one;
    }
    entry += 0x10;
    if (entry == (s8 *) &D_80800C0C_gccollectDll) {
        // Matching: "* 0" is needed for the match.
        return (jiggy == *(s16 *) ((s8 *) entry + 0)) * 0;
    }
    goto loop_10;
}

// Serialises positions of flag-triggered jiggies that are spawned but not collected.
s32 func_808003E0_gccollectDll(void *buffer, void *word_pos)
{
    s32 first_jiggy;
    s32 i;
    void *new_buffer;
    s32 flag;
    s32 map;
    s32 n;
    s32 flag_2;
    s32 j;
    f32 pos[3];
    u8 *cursor;
    s32 size;

    n = 0;
    first_jiggy = func_800CF87C();
    for (i = first_jiggy; i < first_jiggy + 10; i++) {
        if (!func_800D0B68(i, 1) && (flag = func_800D0908(i, 1))) {
            map = func_800D0684(i, 1);
            if (func_800EA05C() == map && !func_808002C4_gccollectDll(i, 1) &&
                func_800DA298(flag))
                n++;
        }
    }
    // Matching: reassigning n blocks propagation of size, so the +2 is not reassociated.
    size = n * 8 + 2;
    n *= 1;
    new_buffer = heap_realloc(buffer, *(s32 *) word_pos + size);
    cursor = (u8 *) new_buffer + *(s32 *) word_pos * 4;
    *(s16 *) cursor = n;
    cursor += 4;
    for (j = first_jiggy, n = 0; j < first_jiggy + 10; j++, n++) {
        if (!func_800D0B68(j, 1) && (flag_2 = func_800D0908(j, 1))) {
            map = func_800D0684(j, 1);
            if (func_800EA05C() == map && !func_808002C4_gccollectDll(j, 1) &&
                func_800DA298(flag_2)) {
                *(s16 *) cursor = n;
                cursor += 2;
                func_800D07CC(j, 1, pos);
                func_800EE940(cursor, pos);
                cursor += 6;
            }
        }
    }
    *(s32 *) word_pos = (cursor - (u8 *) new_buffer) >> 2;
    return (s32) new_buffer;
}

// Spawns a jiggy actor (0x21F) at the stored position.
void func_808005BC_gccollectDll(u32 jiggy, Prop *prop)
{
    Actor *actor;
    s32 pos[3];

    pos[0] = (s32) prop->position[0];
    pos[1] = (s32) prop->position[1];
    pos[2] = (s32) prop->position[2];
    actor = func_80108C90(0x21F, pos, 0U, NULL);
    func_800D053C(jiggy, 1);
    func_800D05E4((s32) jiggy, 1, (s32) actor->unk0);
    func_800CFBC8(actor, jiggy, 1, 0);
    if ((_glreflight_entrypoint_0() & 0xFF) != 0xFE) {
        func_8010A570(actor);
    }
}

// Restores the positions written by the serialiser above.
s32 func_80800660_gccollectDll(void *buffer, void *word_pos)
{
    s16 *cursor;
    s32 count;
    s32 i;
    s32 rel_jiggy;
    s32 jiggy;

    cursor = (s16 *) ((s32 *) buffer + *(s32 *) word_pos);
    count = *cursor;
    cursor += 2;
    for (i = 0; i < count; i++) {
        rel_jiggy = *cursor++;
        jiggy = func_800CF87C() + rel_jiggy;
        if (func_800D0A9C(jiggy, 1) && !func_800D0B68(jiggy, 1)) {
            func_808005BC_gccollectDll(jiggy, cursor);
        }
        cursor += 3;
    }
    *(s32 *) word_pos = (s32 *) cursor - (s32 *) buffer;
    return (s32) buffer;
}

s32 gccollectDll_entrypoint_6(void *buffer, void *word_pos)
{
    if (func_800CF87C() == -1) {
        return buffer;
    }
    if (func_800CF87C() == 0x5B) {
        return buffer;
    }
    return func_808003E0_gccollectDll(buffer, word_pos);
}

s32 gccollectDll_entrypoint_7(void *buffer, void *word_pos)
{
    if (func_800CF87C() == -1) {
        return buffer;
    }
    if (func_800CF87C() == 0x5B) {
        return buffer;
    }
    return func_80800660_gccollectDll(buffer, word_pos);
}

void func_808007D8_gccollectDll(Prop *prop)
{
    f32 pos[3];

    if ((func_800D0A9C((u32) prop->FlagOrRotation, 1U) != 0) &&
        (func_800D0B68((u32) prop->FlagOrRotation, 1U) == 0) &&
        (func_800D0634((u32) prop->FlagOrRotation, 1) == 0)) {
        func_808005BC_gccollectDll((u32) prop->FlagOrRotation, prop);
        return;
    }
    func_800EE88C(pos, prop->position);
    func_800D0778(prop->FlagOrRotation, 1, &pos);
}

// Spawns the collectible actor if it is spawned but not collected.
Actor *func_80800890_gccollectDll(Prop *prop, u32 category)
{
    s32 pos[3];
    s32 actor;
    if ((func_800D0A9C(prop->FlagOrRotation, category) != 0) &&
        (func_800D0B68(prop->FlagOrRotation, category) == 0)) {
        pos[0] = (s32) prop->position[0];
        pos[1] = (s32) prop->position[1];
        pos[2] = (s32) prop->position[2];
        actor = func_80108C90(D_80800C18_gccollectDll[category], pos, prop->FlagOrRotation, prop);
        if ((_glreflight_entrypoint_0() & 0xFF) != 0xFE) {
            func_8010A570(actor);
        }
        return actor;
    }
    return 0;
}

// Cube setup: spawns the collectible props of the cube.
void gccollectDll_entrypoint_8(s16 *setup)
{
    u32 level = D_8012762C;
    Prop *prop;
    Prop *end;
    u32 category;
    u32 value;
    Actor *actor;

    if ((func_800CF87C() != -1) && (setup != 0) && (func_800E9DC4(setup) != 0)) {
        prop = func_800E9D68(setup);
        end = func_800E9D90(setup);
        for (prop; prop < end; prop++) {
            if (prop->unk6_1 == 6) {
                value = prop->ItemID;
                actor = NULL;
                switch (value) {
                    case 0x1F5:
                        category = 0;
                        break;
                    case 0x1F6:
                        category = 1;
                        break;
                    case 0x1F7:
                        category = 2;
                        break;
                    case 0x1F8:
                        category = 3;
                        break;
                    case 0x201:
                        category = 4;
                        break;
                    case 0x29D:
                        category = 7;
                        break;
                    case 0x4E6:
                        category = 8;
                        break;
                    default:
                        continue;
                }

                if (func_800CFFBC(prop->FlagOrRotation, category) != 0) {
                    value = func_800D06D4(prop->FlagOrRotation, category);
                    if (value == level || value == -1) {
                        switch (category) {
                            case 1:
                                func_808007D8_gccollectDll(prop);
                                break;
                            case 3:
                                actor = func_80800890_gccollectDll(prop, category);
                                if (actor != NULL) {
                                    actor->unk74_7 = prop->unk6_7;
                                }
                                break;
                            case 0:
                            case 2:
                            case 4:
                            case 7:
                            case 8:
                                actor = func_80800890_gccollectDll(prop, category);
                        }
                        if (actor != NULL) {
                            func_800CFBC8(actor, prop->FlagOrRotation, category, 0);
                        }
                    }
                }
            }
        }
    }
}

// TU-NOTE: the overlay .data is defined here in C; values are taken from the ROM.
// TU-NOTE: D_80800BE2 = D_80800BE0 + 0x2, D_80800BE6 = D_80800BE4 + 0x2, D_80800BEA = D_80800BE8 + 0x2
// (linker symbols in undefined_syms.us.txt).
// TU-NOTE: externs are typed to the objects: D_80800BE4 and D_80800BE8 s16[] (used as NAME[0]),
// D_80800BEC s32[].
s16 D_80800BE0_gccollectDll[2] = {0x31, 0x1};
s16 D_80800BE4_gccollectDll[2] = {0x26, 0x1};
s16 D_80800BE8_gccollectDll[2] = {0xB, 0x4};
s32 D_80800BEC_gccollectDll[8] = {0xA0001, 0x160002, 0x3D0001, 0x4C0001,
                                  0xA0002, 0x140000, 0x360001, 0x60002};
s32 D_80800C0C_gccollectDll[3] = {0x0, 0x0, 0x0};
u32 D_80800C18_gccollectDll[10] = {0x1F4, 0x21F, 0x220, 0x21B, 0x136, 0x0, 0x0, 0x4E5, 0x3C6, 0x0};
