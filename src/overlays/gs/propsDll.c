// Most likely the cube prop loader: stores a cube's props, keeps its node props sorted and
// spawns actors from the actor-spawn props.
#include "common.h"

typedef struct {
    s16 pos[3];
    u16 unk_6;
    u16 actor_id;
    u16 pad_0;
    u32 unk_C;
    u32 unk_10;
} GsProp62;
extern Actor *func_80108DC0(s32, s32 *, s32, s32, s32, void *);
extern f32 _gspropmarker_entrypoint_3(void *);
extern void func_80102FDC(Actor *, f32);
typedef struct {
    u32 f21 : 11;
    u32 f10 : 11;
    u32 b9 : 1;
    u32 b7 : 2;
    u32 b6 : 1;
    u32 b5 : 1;
    u32 b2 : 3;
    u32 low : 2;
} GspFl;
extern void *func_800E9BF4();
extern void *func_800BE5C4();
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_0[10];
    u8 pad_1 : 7;
    u8 unk_12 : 1;
    u8 pad_2;
} StoredPropRecord;
extern void func_800EE8CC(f32 *, void *);
extern s32 func_800BDBC4(f32 *);
extern void *func_800E9A24(s32);
typedef struct {
    u32 pad_0[2];
    u32 pad_1 : 30;
    u32 selected : 1;
    u32 pad_2 : 1;
} StoredPropCondition1408;
extern void *func_800E98C0(s32);

typedef struct {
    u8 pad[4];
    u32 pad4 : 25;
    u32 f : 6;
    u32 rest : 1;
} PropState;

// Inserting props into cubes, sorting them and spawning actors from spawn props.
// Collects the actor-spawn props (kind 6) of a cube.
void gspropsDll_entrypoint_0(s16 *cube, s32 props[3], s32 *count)
{
    u32 start;
    u32 end;
    u32 it;

    if ((cube != NULL) && (cube[1] != 0)) {
        start = func_800E9D68();
        end = func_800E9D90(cube);
        it = start;
        if (it < end) {
            do {
                if (((u32) (*(u32 *) ((char *) it + 0x4) << 0x19) >> 0x1A) == 6) {
                    props[*count] = it;
                    *count += 1;
                }
                it += 0x14;
            } while (it < end);
        }
    }
}

// Sorts the props by actor id and spawns their actors.
void gspropsDll_entrypoint_1(GsProp62 **props, s32 count)
{
    s32 i;
    s32 j;
    GsProp62 *tmp;
    s32 pos[3];
    GsProp62 *prop;
    Actor *actor;

    for (i = 0; i < count; i++) {
        for (j = 0; j < i; j++) {
            if ((u32) props[i]->actor_id < (u32) props[j]->actor_id) {
                tmp = props[j];
                props[j] = props[i];
                props[i] = tmp;
            }
        }
    }
    for (i = 0; i < count; i++) {
        prop = props[i];
        pos[0] = prop->pos[0];
        pos[1] = prop->pos[1];
        pos[2] = prop->pos[2];
        actor = func_80108DC0(prop->actor_id, pos, prop->unk_C >> 23,
                                prop->unk_10 >> 21, (prop->unk_10 << 11) >> 21, prop);
        if (actor) {
            actor->unk74_7 = (u32) prop->unk_6 >> 7;
            actor->unk7A_5 = 1;
            func_80102FDC(actor, _gspropmarker_entrypoint_3(prop));
        }
    }
}

// Registering a cube's zone-bound volumes (node props of kinds 7, 9, 12) in two passes.
// Registers the zone-bound props (kinds 7, 9, 12) of a cube with the bound lists.
void gspropsDll_entrypoint_2(u8 *cube, s32 pass)
{
    u8 *it;
    u8 *end;
    u32 a2_1;
    s32 a3_1;
    u32 a2_2;
    s32 a3_2;
    u32 a2_3;
    s32 a3_3;
    s32 k5a;
    u32 k5b;
    s32 bit6;
    s32 want;
    u32 type;

    // Matching: the constants and the empty if are needed for the match.
    k5a = 5;
    k5b = 5;
    if (1) {
    }
    if (cube != 0 && *(s16 *) (cube + 2) != 0) {
        it = (u8 *) func_800E9D68();
        end = (u8 *) func_800E9D90(cube);
        if (it < end) {
            do {
                if (((u32) (*(u32 *) (it + 4) << 0x19) >> 0x1A) == 7) {
                    want = pass ? 1 : 0;
                    bit6 = ((GspFl *) (it + 0x10))->b6 ? 1 : 0;
                    if (bit6 == want) {
                        a2_1 = (u32) *(u16 *) (it + 6) >> 7;
                        a3_1 = (*(u32 *) (it + 0xC) >> 0x17) * k5a;
                        if (a3_1 == 0) {
                            a3_1 = 0x12C;
                        }
                        if (((GspFl *) (it + 0x10))->b5) {
                            a2_1 *= k5b;
                        }
                        func_800CBA68(*(u16 *) (it + 8), it, a2_1, a3_1,
                                      ((GspFl *) (it + 0x10))->f21, ((GspFl *) (it + 0x10))->b9,
                                      ((GspFl *) (it + 0x10))->b6);
                    }
                }
                if (pass == 0) {
                    type = ((u32) (*(u32 *) (it + 4) << 0x19) >> 0x1A);
                    if (type == 9) {
                        a2_3 = (u32) *(u16 *) (it + 6) >> 7;
                        a3_3 = (*(u32 *) (it + 0xC) >> 0x17) * k5a;
                        if (a3_3 == 0) {
                            a3_3 = 0x12C;
                        }
                        if (((GspFl *) (it + 0x10))->b5) {
                            a2_3 *= k5b;
                        }
                        func_800CBAC8(*(u16 *) (it + 8), it, a2_3, ((GspFl *) (it + 0x10))->low,
                                      a3_3);
                    // Matching: redundant test needed for the match.
                    } else if (type != 0xA && type == 0xC) {
                        a2_2 = (u32) *(u16 *) (it + 6) >> 7;
                        a3_2 = (*(u32 *) (it + 0xC) >> 0x17) * k5a;
                        if (a3_2 == 0) {
                            a3_2 = 0x12C;
                        }
                        if (((GspFl *) (it + 0x10))->b5) {
                            a2_2 *= k5b;
                        }
                        func_800CBB18(*(u16 *) (it + 8), it, a2_2, a3_2,
                                      ((GspFl *) (it + 0x10))->low, ((GspFl *) (it + 0x10))->b9);
                    }
                }
                it += 0x14;
            } while (it < end);
        }
    }
}

// Returns 0 for node props of kinds 6..12.
s32 func_808004E0_gspropsDll(prop)
PropState *prop;
{
    switch (prop->f) {
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            return 0;
    }

    return 1;
}

// Keeps the node props of a cube sorted, kinds 6..12 last.
void func_80800524_gspropsDll(s16 *cube)
{
    s32 j;
    s32 i;
    s32 plain_count;
    s32 total;
    u32 scratch[5];
    total = cube[1];
    plain_count = 0;
    for (i = 0; i < total; i++) {
        if (func_808004E0_gspropsDll(func_800E9BF4(cube, i))) {
            j = i;
            plain_count++;
            while (j > 0 && func_808004E0_gspropsDll(func_800E9BF4(cube, j)) &&
                   !func_808004E0_gspropsDll(func_800E9BF4(cube, j - 1))) {
                aligned4_memcpy(scratch, func_800E9BF4(cube, j), 0x14);
                aligned4_memcpy(func_800E9BF4(cube, j),
                                func_800E9BF4(cube, (j - 1)), 0x14);
                aligned4_memcpy(func_800E9BF4(cube, (j - 1)), scratch, 0x14);
                j -= 1;
            }
        }
    }
    *(u8 *) func_800BE5C4(cube) = plain_count;
}

// Inserts a loaded node prop into its cube's storage.
void gspropsDll_entrypoint_3(void *prop)
{
    s32 cube;
    f32 pos[3];
    StoredPropRecord *stored;
    func_800EE8CC(pos, prop);
    cube = func_800BDBC4(pos);
    stored = func_800E9A24(cube);
    aligned4_memcpy(stored, prop, 0x14);
    if (!(stored->unk_4 & 1))
        stored->unk_12 = 1;
    func_80800524_gspropsDll(cube);
}

// Inserts an actor/model prop into its cube's storage.
void gspropsDll_entrypoint_4(u8 *prop)
{
    s32 cube;
    f32 pos[3];
    u8 *stored;

    func_800EE8CC(pos, prop + 4);
    cube = func_800BDBC4(pos);
    stored = func_800E98C0(cube);
    aligned4_memcpy(stored, prop, 12);
    stored[0xB] = (stored[0xB] & 0xFFEF) | 0x10;
    if (((StoredPropCondition1408 *) stored)->selected) {
        stored[0xB] &= 0xDF;
    }
}
