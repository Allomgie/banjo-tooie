// Probably Seemee, the see-through fish of Jolly Roger's Lagoon: each fish carries an item (such as
// a Jiggy) inside its body, assigned by a seeded shuffle. It wanders its territory and pushes the
// player away unless hit with the Talon Torpedo.
#include "ch/transparentfish.h"

#define TRANSPARENT_FISH_ITEM_271(param_0)                                                         \
    (((param_0)->unk6C_0 && (param_0)->unk6C_0 < 13)                                               \
         ? D_80800FB4_chtransparentfish[(param_0)->unk6C_0].local_0                                \
         : 0)
extern void func_800DBEFC();
extern s32 D_80800FB8_chtransparentfish[][3];
typedef struct {
    u32 local_0;
    s32 local_1;
    s32 local_2;
} FishSpawnConfig271;
extern FishSpawnConfig271 D_80800FB4_chtransparentfish[];
extern s32 D_80800FBC_chtransparentfish[];
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_80108474(u32, f32 *, s32);
extern s32 func_800D0B68(u32, s32);
extern Unk80132ED0 *func_800D10D4(u32, u32, f32 *, s32, Unk80132ED0 *);
extern void *func_80100094(Actor *, u32);
extern Actor *_subaddielink_entrypoint_4(void *);
extern void func_800EE7F8(f32 *, f32 *);
extern int D_80801098_chtransparentfish[];
typedef struct {
    s32 marker_id;
    s32 unk_4;
    s32 item_index;
} CodexTransparentFishRecord65;
typedef struct {
    u32 pad_0[2];
    s32 item_index;
} TransparentFishEntry;
typedef struct Mass47FishOrigin {
    f32 pos[3];
    s16 unk_C;
    s16 half_height;
} Mass47FishOrigin;
extern Mass47FishOrigin *func_800CC63C(s32, s32);
extern void func_80102950(Actor *, f32);
extern f32 func_80102D78(Actor *, void *);
extern void func_80102924(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
typedef struct {
    f32 f0, f1, f2, f3, f4, f5, f6, f7;
} TFAD_;
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern s32 func_8010BA80(Actor *, s32, s32);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 unk_64 : 1;
    u32 pad_2 : 29;
} FishJoyFlags331;
typedef struct {
    u8 pad_0[0x7C];
    u32 pad_1 : 19;
    u32 visible : 1;
    u32 pad_2 : 12;
} FishVisibleFlags331;
extern u8 D_80801050_chtransparentfish[];
extern f32 func_80103EAC(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_80101E14(Actor *, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA994(s32, s16, s16, s16, s32, s32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80101CDC(Actor *, f32);
extern void func_80102C58(Actor *, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F0DC0(f32, f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern void func_80800AC4_chtransparentfish(Actor *, f32 *, s32);
void func_80800B60_chtransparentfish();
s32 func_80800E10_chtransparentfish();
s32 func_80800EE0_chtransparentfish();

void func_80800000_chtransparentfish(Actor *fish)
{
    f32 turn;
    s32 clamped;
    Mass47FishOrigin *origin;

    origin = func_800CC63C((*(u32 *) ((u8 *) fish + 0x70) >> 25) - 1,
                            ((*(u32 *) ((u8 *) fish + 0x70) << 22) >> 26) - 1);
    if (origin->pos[1] + origin->half_height <= fish->position[1]) {
        clamped = 1;
        func_80102950(fish, 355.0f);
    } else if (fish->position[1] <= origin->pos[1] - origin->half_height) {
        clamped = 1;
        func_80102950(fish, 5.0f);
    } else {
        clamped = 0;
    }
    if (!_subaddieDll_entrypoint_11(
            fish, (s32) fish->unk54,
            (s32) ((fish->scale * 3.0f) * ((TFAD_ *) fish->actorData)->f3))) {
        func_80102924(fish, func_80102D78(fish, origin));
        fish->unk58 = func_800DC178(1.0f, 3.0f);
    } else {
        fish->unk58 -= func_800D8FF8();
        if (fish->unk58 <= 0.0f) {
            fish->unk58 = func_800DC178(1.0f, 3.0f);
            ((f32 *) fish->actorData)[7] = func_800DC178(105.0f, 150.0f);
            if (!clamped) {
                func_80102950(fish, func_800DC178(-8.333333f, 8.333333f));
            }
            turn = func_800DC178(-35.0f, 35.0f);
            if (func_80102CCC(fish)) {
                func_80102924(fish, fish->rotation[1] + turn);
            }
        }
    }
}

void func_80800204_chtransparentfish(Actor *fish)
{
    f32 target_speed;

    target_speed = _subaddiejoy_entrypoint_3(fish) * 300.0f;
    func_80102BAC(fish, 0.5, 0.5f, 5.0f);
    if (*(f32 *) ((u8 *) fish + 0x24) <= target_speed) {
        *(f32 *) ((u8 *) fish + 0x24) = target_speed;
    } else {
        *(f32 *) ((u8 *) fish + 0x24) -= *(f32 *) ((u8 *) fish + 0x24) * 0.02f;
        if (*(f32 *) ((u8 *) fish + 0x24) < 30.0f) {
            *(f32 *) ((u8 *) fish + 0x24) = 0.0f;
        }
    }
    func_8010BA80(fish, 0x200006, 0x20);
}

void func_808002B8_chtransparentfish(Actor *fish)
{
    if (func_800DA298(0x9F4) == 0) {
        func_800DA544(0x9F4);
        func_80800B60_chtransparentfish();
    }
    fish->unk6C_0 = func_80800EE0_chtransparentfish(fish->pad6C_21);
    *(f32 *) ((u8 *) fish + 0x24) = 150.0f;
    *(f32 *) ((u8 *) fish + 0x34) = 150.0f;
    *(f32 *) ((u8 *) fish + 0x2C) = (f32) _subaddiesect_entrypoint_1(fish);
}

void func_80800348_chtransparentfish(Actor *fish)
{
    s32 unk_0;
    f32 push_pos[3];
    f32 unk_1;
    f32 y_factor;
    s32 effect;
    f32 radius_factor;

    _subaddiesect_entrypoint_0(fish, (s32) *(f32 *) &fish->actorData[5], 11);
    func_80800AC4_chtransparentfish(fish, NULL, ((FishVisibleFlags331 *) fish)->visible);
    // Push the player away unless they attack with the Talon Torpedo (0x14).
    if (func_800F52B8(func_800F54E4(), fish->unk0) != 0x14) {
        unk_0 = func_800F690C(func_800F54E4());
        unk_1 = func_80103EAC(fish);
        y_factor = unk_0 ? 0.5f : 0.25f;
        func_800EFA4C(push_pos, fish->position[0], fish->position[1] + y_factor * unk_1,
                      fish->position[2]);
        radius_factor = unk_0 ? 0.75f : 0.5f;
        _sudeflect_entrypoint_0(push_pos, 0, radius_factor * unk_1, 30);
    }
    if (func_80101E14(fish, 0.01f) && func_80102CCC(fish)) {
        effect = func_800B53A4(10);
        func_800BABB8(effect, (f32 *) fish->actorData, NULL, fish->scale,
                      D_80801050_chtransparentfish);
        func_800BA994(effect, (s16) (s32) fish->rotation[0],
                      (s16) (s32) (fish->rotation[1] - 35.0f),
                      (s16) (s32) (*(f32 *) &fish->actorData[3] * 1.1f),
                      (s32) (s16) (s32) fish->rotation[0], (s32) (fish->rotation[1] + 35.0f),
                      (s32) (*(f32 *) &fish->actorData[3] + *(f32 *) &fish->actorData[3]));
        func_800BA22C(effect, 10);
    }
    if (fish->unk70_10 == 1) {
        if (((FishJoyFlags331 *) fish)->unk_64) {
            func_80800204_chtransparentfish(fish);
            func_80101CDC(fish,
                          func_800F10B4(*(f32 *) &fish->actorData[3], 0, 300.0f, 3.0f, 1.5f));
        } else {
            func_80800000_chtransparentfish(fish);
            func_80102BAC(fish, 0.05f, 0.05f, 4.0f);
            func_80102C58(fish, 0.05f, 0.01f, 0.5f);
            *(f32 *) &fish->actorData[3] = func_800F15F8(*(f32 *) &fish->actorData[3],
                                                            *(f32 *) &fish->actorData[7], 2.0f);
            if (func_8010BA80(fish, 0x26, 0x10)) {
                fish->unk54 += 10.0f;
            }
        }
        *(f32 *) &fish->actorData[4] =
            func_800F0DC0(func_800F1DCC(fish->rotation[1], fish->unk54) * 0.5f, 15.0f);
        fish->rotation[2] = func_800F1FF0(fish->rotation[2], *(f32 *) &fish->actorData[4],
                                             0.01f, 0.005f, 0.1f);
    }
}

void func_80800690_chtransparentfish(Actor *fish)
{
    f32 item_pos[3];
    s32 value;

    func_80101870(fish);
    if (fish->unk7C_12) {
        func_800DBEFC(func_80104130(), 5, fish->actorData);
        value = fish->unk6C_0 > 0 && fish->unk6C_0 < 13
                      ? ((s32(*)[3]) D_80800FB4_chtransparentfish)[fish->unk6C_0][0]
                      : 0;
        if (value) {
            func_800DBEFC(func_80104130(), 4, item_pos);
            value = fish->unk6C_0 > 0 && fish->unk6C_0 < 13
                          ? D_80800FB8_chtransparentfish[fish->unk6C_0][0]
                          : 0;
            item_pos[1] += value;
            func_80800AC4_chtransparentfish(fish, item_pos, 1);
        }
    }
}

s32 func_8080078C_chtransparentfish(Actor *fish, s32 event, s32 pos)
{
    Actor *item;
    Unk80132ED0 *actor_ref;

    switch (event) {
        case 0x3D:
            actor_ref = fish->unk0;
            if (TRANSPARENT_FISH_ITEM_271(fish) == 0x21F) {
                if (!func_800D0B68(0x26, 1)) {
                    item =
                        func_80106790(func_800D10D4(0x26, 1, fish->position, 3, fish->unk0));
                } else {
                    return 0;
                }
            } else if (TRANSPARENT_FISH_ITEM_271(fish) == 0x136) {
                if (!func_800D0B68(0xB, 4)) {
                    item =
                        func_80106790(func_800D10D4(0xB, 4, fish->position, 3, fish->unk0));
                } else {
                    return 0;
                }
            } else if (TRANSPARENT_FISH_ITEM_271(fish) == 0x220) {
                if (!func_800D0B68(0xA, 2)) {
                    item =
                        func_80106790(func_800D10D4(0xA, 2, fish->position, 3, fish->unk0));
                } else {
                    return 0;
                }
            } else {
                pos = (s32) fish->position;
                // Matching: empty blocks steer IDO's register allocation.
                if (pos) {
                }
                if (fish && fish && fish) {
                }
                item = func_80108474(TRANSPARENT_FISH_ITEM_271(fish), (f32 *) pos, 0);
            }
            ((u8 *) item)[0x77] &= ~0x20;
            ((u8 *) item)[0x75] &= ~0x10;
            ((u8 *) item)[0x71] &= ~1;
            ((u8 *) item)[0x64] &= ~0x80;
            fish = func_80106790(actor_ref);
            _subaddielink_entrypoint_1(func_80100094(fish, 0), item->unk0);
            func_80800AC4_chtransparentfish(fish, fish->position, 0);
            if (fish->unk6C_0 && fish->unk6C_0 < 13) {
                item->scale =
                    ((f32) *(s32 *) ((u8 *) D_80800FBC_chtransparentfish + fish->unk6C_0 * 12) /
                     100.0f) *
                    fish->scale;
            } else {
                item->scale = 0.0f;
            }
            return 1;
        case 1:
            func_80102424(fish, 1);
            return 1;
        case 2:
            func_80107070(fish, 1);
            return 1;
        case 0x95:
            if (!_subaddielink_entrypoint_3(func_80100094(fish, 0))) {
                func_80108B04(fish, 0);
            }
            return 1;
    }
    return 0;
}

// Moves the carried item actor to pos (if given) and sets its visibility.
void func_80800AC4_chtransparentfish(fish, pos, visible) Actor *fish;
f32 *pos;
s32 visible;
{
    Actor *item;
    item = _subaddielink_entrypoint_4(func_80100094(fish, 0));
    if (item) {
        if (pos)
            func_800EE7F8(item->position, pos);
        item->unk64_16 = visible;
    }
}

void func_80800B30_chtransparentfish(s32 arg0)
{
    func_800DA524(FLAG3_9F4_UNK);
}

int chtransparentfish_entrypoint_0()
{
    return (int) &D_80801098_chtransparentfish;
}

CodexTransparentFishRecord65 B_808010E0_chtransparentfish[20];

// One-time setup: sorts the fish markers and shuffles item assignment with a per-save seed.
void func_80800B60_chtransparentfish(void)
{
    s32 i;
    s32 count;
    s32 j;
    s32 tmp;
    s32 saved_seed;
    u32 *markers[20];
    s32 seed;
    s32 next;

    for (count = 0; count < 20; count++) {
        B_808010E0_chtransparentfish[count].marker_id = 0;
        B_808010E0_chtransparentfish[count].unk_4 = -1;
        B_808010E0_chtransparentfish[count].item_index = -1;
    }
    count = _gccubesearch_entrypoint_9(0x295, markers, 20);
    for (i = 0; i < count; i++) {
        B_808010E0_chtransparentfish[i].marker_id = markers[i][4] >> 21;
        B_808010E0_chtransparentfish[i].unk_4 =
            _gspropctrl_entrypoint_8(markers[i]) - 50;
    }
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (B_808010E0_chtransparentfish[i].marker_id <
                B_808010E0_chtransparentfish[j].marker_id) {
                tmp = B_808010E0_chtransparentfish[j].marker_id;
                B_808010E0_chtransparentfish[j].marker_id =
                    B_808010E0_chtransparentfish[i].marker_id;
                B_808010E0_chtransparentfish[i].marker_id = tmp;
            }
        }
    }
    if (func_800DA298(0x6C0)) {
        seed = func_800DA564(0x6C1, 8);
    } else {
        seed = func_800DC128(0, 256);
        func_800DA7A8(0x6C1, seed, 8);
        func_800DA544(0x6C0);
    }
    next = 0;
    saved_seed = func_800DC090();
    func_800DC324(seed);
    while (!func_80800E10_chtransparentfish(count)) {
        j = func_800DC128(0, count);
        if (B_808010E0_chtransparentfish[j].item_index == -1) {
            B_808010E0_chtransparentfish[j].item_index =
                B_808010E0_chtransparentfish[next++].unk_4;
        }
    }
    func_800DC324(saved_seed);
}

// Returns 1 once every entry has an item assigned.
s32 func_80800E10_chtransparentfish(count)
s32 count;
{
    s32 complete;
    s32 i;

    complete = 1;
    for (i = 0; i < count; i++) {
        complete &= ((TransparentFishEntry *) B_808010E0_chtransparentfish)[i].item_index != -1;
    }
    return complete;
}

// Looks up the item index for a fish marker id in B_808010E0.
// Matching: the line breaks in this function are needed for the match.
s32 func_80800EE0_chtransparentfish(marker_id) s32 marker_id;
{
    char *tail_ptr;
    s32 *entry;
    int word_size;
    entry = &((s32 *) B_808010E0_chtransparentfish)[0]; while (1) {
        if (marker_id == *(s32 *) ((char *) entry + 0x0))
        {
            return *(s32 *) ((char *) entry + 0x8);
        }
        word_size = sizeof(s32);
        if (marker_id == *(s32 *) ((char *) entry + 0xC))
        {
            return *(s32 *) ((char *) entry + 0x14);
        }
        if (marker_id == *(s32 *) ((char *) entry + 0x18))
        {
            tail_ptr = (char *) entry + 0x20;
            return *(s32 *) tail_ptr;
        }
        if (marker_id == *(s32 *) ((char *) entry + 0x24))
        {
            return *(s32 *) ((char *) entry + 0x2C);
        }
        entry += 0x30 / sizeof(s32);
        if (entry == &((s32 *) B_808010E0_chtransparentfish)[0xF0 / word_size])
        {
            return 0;
        }
    }

}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800F80_chtransparentfish[5] = {0x10000, 0x20000, 0x20000, 0x0, 0x30000};
u32 D_80800F94_chtransparentfish[8] = {0x0,        0x0,       0x40200000, 0x1580001,
                                       0x40200000, 0x1580001, 0x40200000, 0x1580001};
FishSpawnConfig271 D_80800FB4_chtransparentfish[13] = {
    0x0,   0x0,   0x64,  0x21F, -0x1E, 0x64,  0x136, -0x32, 0x64,  0x1C8, -0x32, 0x64,  0x1C9,
    -0x32, 0x64,  0x1CA, -0x32, 0x64,  0x1CB, -0x32, 0x64,  0x1CC, -0x46, 0x5A,  0x1CE, -0x46,
    0x64,  0x1CF, -0x46, 0x64,  0x1D7, -0x32, 0x64,  0x1D8, -0x46, 0x46,  0x220, -0x32, 0x5A};
u8 D_80801050_chtransparentfish[72] = {
    0x0, 0x1D, 0x9,  0xD9, 0x0, 0x16, 0x10, 0x4,  0x0,  0x1B, 0x0,  0x96, 0x0,  0x96, 0x0,
    0x7, 0x0,  0x1,  0x0,  0xE, 0x0,  0xA,  0x0,  0xA,  0x0,  0x15, 0x0,  0x0,  0x0,  0xCC,
    0x0, 0x2B, 0x3,  0x0,  0x3, 0x0,  0x0,  0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0,  0x22, 0x0,
    0xC, 0x0,  0x17, 0x0,  0xC, 0x0,  0x17, 0x0,  0x2F, 0x0,  0x40, 0x0,  0x40, 0x0,  0x0,
    0x0, 0x0,  0x0,  0x19, 0x0, 0x0,  0x0,  0x33, 0x0,  0x0,  0x0,  0x0};
int D_80801098_chtransparentfish[18] = {0x12D0295,
                                        0x6D90001,
                                        (u32) &D_80800F94_chtransparentfish,
                                        (u32) func_80800348_chtransparentfish,
                                        (u32) func_80105834,
                                        (u32) func_80800690_chtransparentfish,
                                        0x13880000,
                                        0x0,
                                        0x0,
                                        0x220123,
                                        (u32) func_80800B30_chtransparentfish,
                                        (u32) func_80108ED0,
                                        0x80000,
                                        (u32) func_808002B8_chtransparentfish,
                                        (u32) func_80107C2C,
                                        -0x7FBFAFF1,
                                        (u32) func_8080078C_chtransparentfish,
                                        (u32) &D_80800F80_chtransparentfish};
