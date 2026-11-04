#include "common.h"

extern s32 func_800F4F34(s32, f32 *, f32, f32);
extern void func_800A52E0(f32 *, f32, f32);
extern s32 func_800F4EC8(s32, void *, f32, f32, f32);
extern void func_800A5298(void *, f32, f32, f32);
typedef struct {
    Unk80132ED0 *marker;
    s32 pad_4;
    u32 flags;
} DeflectItem31;
extern DeflectItem31 *func_800E9E88(void *);
extern DeflectItem31 *func_800E9EB4(void *);
extern Actor *func_80106790();
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
typedef struct {
    Unk80132ED0 *marker;
    s32 pad4;
    u32 flags;
} DeflectRecord32;
extern s32 func_800F0064(f32 *, f32, f32 *);
int func_80800630_sudeflect();
int func_808006A4_sudeflect(f32 *center, f32 y_offset, f32 radius);
int func_808007F4_sudeflect(void *center, f32 y_max, f32 y_min, f32 radius);
int func_80800940_sudeflect(f32 *center, f32 y_offset, f32 radius);
int func_80800A98_sudeflect(void *center, f32 y_max, f32 y_min, f32 radius);
s32 func_80800BEC_sudeflect();
s32 func_80800D14_sudeflect();
s32 func_80800E44_sudeflect(f32 *center, f32 y_max, f32 y_min, f32 radius, f32 *pos,
                            f32 margin);
s32 func_80800ECC_sudeflect(f32 *box_min, f32 *box_max, f32 *pos, f32 margin);

// TU-NOTE: .bss is defined here in C, ahead of its first use: IDO places .bss objects used
// before their definition first, the rest in definition order. The _tail objects fill bytes
// that no code names.
s32 B_80801020_sudeflect;
u8 B_80801020_sudeflect_tail[4];
u8 B_80801020_sudeflect_tail1[40];

// Sphere keep-out. mask bits: 2 players, 4 camera, 8 eggs, 0x10 actor 0x27A.
// Returns the mask bits that hit something.
s32 sudeflect_entrypoint_0(f32 *center, f32 y_offset, f32 radius, s32 mask)
{
    s32 player;
    s32 hit_mask;
    hit_mask = 0;
    ((s32 *) &B_80801020_sudeflect)[9] = 0;
    if (mask & 0x18)
        B_80801020_sudeflect = func_800BE3F8();
    if (mask & 2) {
        for (player = 0; player < 8; player++) {
            if (func_800F6438(player) && func_800F4F34(player, center, y_offset, radius)) {
                ((s32 *) &B_80801020_sudeflect)[((s32 *) &B_80801020_sudeflect)[9] + 1] = player;
                ((s32 *) &B_80801020_sudeflect)[9]++;
                hit_mask |= 2;
            }
        }
    }
    if (mask & 4)
        func_800A52E0(center, y_offset, radius);
    if (mask & 8) {
        if (func_808006A4_sudeflect(center, y_offset, radius))
            hit_mask |= 8;
    }
    if (mask & 0x10) {
        if (func_80800940_sudeflect(center, y_offset, radius))
            hit_mask |= 0x10;
    }
    B_80801020_sudeflect = 0;
    return hit_mask;
}

// Cylinder keep-out; same mask bits as sudeflect_entrypoint_0.
int sudeflect_entrypoint_1(void *center, f32 y_max, f32 y_min, f32 radius, u32 mask)
{
    s32 player;
    s32 hit_mask;
    hit_mask = 0;
    ((s32 *) &B_80801020_sudeflect)[9] = 0;
    if (mask & 0x18) {
        B_80801020_sudeflect = func_800BE3F8();
    }
    if (mask & 2) {
        for (player = 0; player < 8; player++) {
            if (func_800F6438(player) &&
                func_800F4EC8(player, center, y_max, y_min, radius)) {
                ((s32 *) &B_80801020_sudeflect)[((s32 *) &B_80801020_sudeflect)[9] + 1] = player;
                ((s32 *) &B_80801020_sudeflect)[9]++;
                hit_mask |= 2;
            }
        }
    }
    if (mask & 4) {
        func_800A5298(center, y_max, y_min, radius);
    }
    if ((mask & 8) && func_808007F4_sudeflect(center, y_max, y_min, radius)) {
        hit_mask |= 8;
    }
    if ((mask & 0x10) && func_80800A98_sudeflect(center, y_max, y_min, radius)) {
        hit_mask |= 0x10;
    }
    B_80801020_sudeflect = 0;
    return hit_mask;
}

// Box keep-out; same mask bits as sudeflect_entrypoint_0 (no camera).
int sudeflect_entrypoint_2(f32 *box_min, f32 *box_max, s32 mask)
{
    f32 center[3];
    s32 player;
    s32 i;
    s32 hit_mask = 0;
    for (i = 0; i != 3; i++) {
        if (1) {
        }
        center[i] = box_min[i] + (box_max[i] - box_min[i]) * 0.5f;
    }
    *(s32 *) ((u8 *) &B_80801020_sudeflect + 0x24) = 0;
    if (mask & 0x18)
        B_80801020_sudeflect = func_800BE3F8(center);
    if (mask & 2) {
        for (player = 0; player < 8; player++) {
            if (func_800F6438(player) && func_800F4D18(player, box_min, box_max)) {
                ((s32 *) &B_80801020_sudeflect)[*(s32 *) ((u8 *) &B_80801020_sudeflect + 0x24) +
                                                1] = player;
                (*(s32 *) ((u8 *) &B_80801020_sudeflect + 0x24))++;
                hit_mask |= 2;
            }
        }
    }
    if ((mask & 8) && func_80800BEC_sudeflect(box_min, box_max))
        hit_mask |= 8;
    if ((mask & 0x10) && func_80800D14_sudeflect(box_min, box_max))
        hit_mask |= 0x10;
    B_80801020_sudeflect = 0;
    return hit_mask;
}

s32 sudeflect_entrypoint_3(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 mask)
{
    s32 hit_mask = 0;
    s32 player;
    *(s32 *) ((char *) &B_80801020_sudeflect + 0x24) = 0;
    if (mask & 2) {
        player = 0;
        do {
            if ((func_800F6438(player) != 0) &&
                (func_800F4E5C(player, param_0, param_1, param_2, param_3) != 0)) {
                *(s32 *) (((char *) &B_80801020_sudeflect +
                           (*(s32 *) ((char *) &B_80801020_sudeflect + 0x24) * 4)) +
                          4) = player;
                *(s32 *) ((char *) &B_80801020_sudeflect + 0x24) =
                    (s32) (*(s32 *) ((char *) &B_80801020_sudeflect + 0x24) + 1);
                hit_mask |= 2;
            }
            player += 1;
        } while (player != 8);
    }
    return hit_mask;
}

// Pushes back the players caught by the last keep-out call, unless in certain states.
// Pushes back the players caught by the last keep-out call, unless in certain states.
void sudeflect_entrypoint_4(s32 param_0, s32 param_1)
{
    s32 i;
    s32 player;
    for (i = 0; i < ((s32 *) &B_80801020_sudeflect)[9]; i++) {
        player = ((s32 *) &B_80801020_sudeflect)[i + 1];
        if (func_80800630_sudeflect(player))
            func_800F7700(player, param_0, param_1);
    }
}

int func_80800630_sudeflect(player)
s32 player;
{
    if (func_800F6720(player)) {
        return TRUE;
    }
    if (func_800F5410(player) == 0x11) {
        return TRUE;
    }
    switch (func_800F52B8(player, 0)) {
        case 1:
        case 0xb:
            return TRUE;
    }

    return FALSE;
}

int func_808006A4_sudeflect(f32 *center, f32 y_offset, f32 radius)
{
    DeflectItem31 *item;
    f32 sphere[5];
    DeflectItem31 *item_end;
    Actor *actor;
    s32 count;
    void **cube;
    cube = *(void ***) &B_80801020_sudeflect;
    count = 0;
    func_800EE7F8(sphere, center);
    sphere[1] += y_offset;
    while (*cube) {
        item = func_800E9E88(*cube);
        item_end = func_800E9EB4(*cube);
        while (item < item_end) {
            if (item->flags & 1) {
                actor = (Actor *) item->marker;
                if (_sueggmisc_entrypoint_0(actor)) {
                    actor = func_80106790(actor);
                    if (!actor->unk64_17 &&
                        func_800F0008(sphere, radius, actor->position, 38.0f)) {
                        count++;
                        func_8010108C(actor, 5, 0);
                    }
                }
            }
            item++;
        }
        cube++;
    }
    return count;
}

int func_808007F4_sudeflect(void *center, f32 y_max, f32 y_min, f32 radius)
{
    void **cube;
    DeflectItem31 *item;
    DeflectItem31 *item_end;
    Actor *actor;
    s32 count;
    Unk80132ED0 *marker;

    cube = *(void ***) &B_80801020_sudeflect;
    count = 0;
    while (*cube) {
        // Matching: empty block needed for the match.
        if (1) {
        }
        item =func_800E9E88(*cube);
        item_end = func_800E9EB4(*cube);
        for (; item < item_end; item++) {
            if (item->flags & 1) {
                marker = item->marker;
                if (_sueggmisc_entrypoint_0(marker)) {
                    actor = func_80106790(marker);
                    if (!actor->unk64_17 &&
                        func_80800E44_sudeflect(center, y_max, y_min, radius,
                                                actor->position, 38.0f)) {
                        count++;
                        func_8010108C(actor, 5, 0);
                    }
                }
            }
        }
        cube++;
    }
    return count;
}

int func_80800940_sudeflect(f32 *center, f32 y_offset, f32 radius)
{
    DeflectItem31 *item;
    f32 sphere[5];
    DeflectItem31 *item_end;
    Unk80132ED0 *marker;
    Actor *actor;
    s32 count;
    void **cube;
    cube = *(void ***) &B_80801020_sudeflect;
    count = 0;
    func_800EE7F8(sphere, center);
    sphere[1] += y_offset;
    while (*cube) {
        item = func_800E9E88(*cube);
        // Matching: this empty block is needed for the match (15 words differ without it).
        if (1) {
            do {
            } while (0);
        }
        item_end = func_800E9EB4(*cube);
        while (item < item_end) {
            if (item->flags & 1) {
                marker = item->marker;
                if ((marker->unk24 >> 22) == 0x27A) {
                    actor = func_80106790(marker);
                    if (!actor->unk64_17 &&
                        func_800F0008(sphere, radius, actor->position, 40.0f)) {
                        count++;
                        func_8010108C(actor, 5, -1);
                    }
                }
            }
            item++;
        }
        cube++;
    }
    return count;
}

int func_80800A98_sudeflect(void *center, f32 y_max, f32 y_min, f32 radius)
{
    void **cube;
    DeflectItem31 *item;
    DeflectItem31 *item_end;
    Actor *actor;
    s32 count;
    Unk80132ED0 *marker;

    cube = *(void ***) &B_80801020_sudeflect;
    count = 0;
    while (*cube) {
        item = func_800E9E88(*cube);
        item_end = func_800E9EB4(*cube);
        for (; item < item_end; item++) {
            if (item->flags & 1) {
                marker = item->marker;
                if (marker->unk24 >> 22 == 0x27A) {
                    actor = func_80106790(marker);
                    if (!actor->unk64_17 &&
                        func_80800E44_sudeflect(center, y_max, y_min, radius,
                                                actor->position, 40.0f)) {
                        count++;
                        func_8010108C(actor, 5, -1);
                    }
                }
            }
        }
        cube++;
    }
    return count;
}

s32 func_80800BEC_sudeflect(box_min, box_max)
f32 *box_min;
f32 *box_max;
{
    void **cube;
    DeflectItem31 *item;
    DeflectItem31 *item_end;
    Actor *actor;
    s32 count;
    Unk80132ED0 *marker;

    cube = *(void ***) &B_80801020_sudeflect;
    count = 0;
    while (*cube) {
        item = func_800E9E88(*cube);
        item_end = func_800E9EB4(*cube);
        for (; item < item_end; item++) {
            if (item->flags & 1) {
                marker = item->marker;
                if (_sueggmisc_entrypoint_0(marker)) {
                    actor = func_80106790(marker);
                    if (!actor->unk64_17 &&
                        func_80800ECC_sudeflect(box_min, box_max, actor->position, 38.0f)) {
                        count++;
                        func_8010108C(actor, 5, 0);
                    }
                }
            }
        }
        cube++;
    }
    return count;
}

s32 func_80800D14_sudeflect(box_min, box_max)
f32 *box_min;
f32 *box_max;
{
    void **cube;
    DeflectRecord32 *item;
    DeflectRecord32 *item_end;
    s32 count;
    Actor *actor;

    cube = *(void ***) &B_80801020_sudeflect;
    count = 0;
    while (*cube) {
        item = (DeflectRecord32 *) func_800E9E88(*cube);
        item_end = (DeflectRecord32 *) func_800E9EB4(*cube);
        for (; item < item_end; item++) {
            if ((item->flags & 1) && item->marker->unk24 >> 22 == 0x27A) {
                actor = func_80106790(item->marker);
                if (!actor->unk64_17 &&
                    func_80800ECC_sudeflect(box_min, box_max, actor->position, 40.0f)) {
                    count++;
                    func_8010108C(actor, 5, -1);
                }
            }
        }
        cube++;
    }
    return count;
}

s32 func_80800E44_sudeflect(f32 *center, f32 y_max, f32 y_min, f32 radius, f32 *pos,
                            f32 margin)
{
    f32 dy;
    dy = pos[1] - center[1];
    if (y_max < dy - margin)
        return 0;
    if (dy + margin < y_min)
        return 0;
    return func_800F0064(center, radius + margin, pos);
}

s32 func_80800ECC_sudeflect(f32 *box_min, f32 *box_max, f32 *pos, f32 margin)
{
    f32 min_diff;
    f32 max_diff;
    f32 obj_min[3];
    f32 obj_max[3];
    s32 i;

    func_800EE7F8(obj_min, pos);
    func_800EE7F8(obj_max, pos);
    for (i = 0; i < 3; i++) {
        obj_min[i] -= margin;
        obj_max[i] += margin;
    }
    if (obj_min[1] >= box_max[1] || obj_max[1] <= box_min[1])
        return 0;
    max_diff = obj_max[0] - box_min[0];
    min_diff = obj_min[0] - box_max[0];
    if (min_diff >= 0.0f || max_diff <= 0.0f)
        return 0;
    max_diff = obj_max[2] - box_min[2];
    min_diff = obj_min[2] - box_max[2];
    if (min_diff >= 0.0f || max_diff <= 0.0f)
        return 0;
    return 1;
}
