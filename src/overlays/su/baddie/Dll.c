// Probably a grab-bag of baddie utilities: one-time actor freeze, zone route/node choice, a
// "player is standing on this actor" test, despawn helpers, and random points in a rectangle.
#include "common.h"

typedef struct {
    u8 pad_0[0x70];
    u32 route : 7;
    u32 pad_1 : 15;
    u32 node : 6;
    u32 pad_2 : 4;
} SubaddieRoute;
typedef struct {
    u8 pad_0[0x70];
    u32 route : 7;
    u32 : 15;
    u32 node : 6;
    u32 : 4;
} SubaddieSelectors1269;
extern int func_800CC338(f32 *, s32, s32);
extern s32 func_8001210C(s32);
extern void _gccubesearch_entrypoint_7();
extern void func_800EF1B8(f32 *, f32, f32);
s32 subaddieDll_entrypoint_2();

// One-time freeze: marks the actor collidable and syncs its marker.
void subaddieDll_entrypoint_0(u8 **actor)
{
    s32 saved;
    u8 *actor_data;
    if (!(*(s32 *) ((s8 *) *actor + 0x10) & 1)) {
        saved = func_8010A698();
        actor_data = *actor;
        // Matching: the redundant `& 0xFFFFu` is needed for the match.
        *(u8 *) ((s8 *) actor_data + 0x13) = (u8) ((*(u8 *) ((s8 *) actor_data + 0x13) & 0xFFFFu) | 1);
        func_80103014(actor);
        func_8010A654(actor, saved);
    }
}

s32 subaddieDll_entrypoint_1(Actor *actor)
{
    Actor *pos = (Actor *) ((s32) actor + 4);
    subaddieDll_entrypoint_2(actor, pos);
}

// Picks the zone route and node for pos; returns 0 if outside every zone.
s32 subaddieDll_entrypoint_2(actor, pos)
SubaddieRoute *actor;
f32 *pos;
{
    actor->route = func_800CBC3C(pos) + 1;
    if (actor->route == 0)
        return 0;
    actor->node = func_800CC338(pos, actor->route - 1, 0) + 1;
    return 1;
}

// Re-validates the actor zone node at its position; returns 1 and updates the node on success.
s32 subaddieDll_entrypoint_3(Actor *actor)
{
    u32 bits;
    u32 route;
    u32 node;
    int new_node;

    bits = *(u32 *) ((u8 *) actor + 0x70);
    route = bits >> 25;
    if (route == 0 || (node = (bits << 22) >> 26) == 0)
        return 0;
    new_node = func_800CC338(actor->position, route - 1, node - 1);
    if (new_node != -1) {
        ((SubaddieSelectors1269 *) actor)->node = new_node + 1;
        return 1;
    }
    return 0;
}

// Sets the actor sound timer from its ActorInfo, or clears it.
void subaddieDll_entrypoint_4(u8 *actor, s32 clear)
{
    if (clear != 0) {
        *(u16 *) ((char *) actor + 0x7C) = 0;
        return;
    }
    *(u16 *) ((char *) actor + 0x7C) = *(u16 *) ((char *) func_80100368() + 0x18);
}

// Returns 1 if the player is riding (state 0xB) on the target of the actor.
s32 subaddieDll_entrypoint_5(s32 *target, u8 *actor)
{
    u32 player_index;
    u32 player;

    if (((u32) *(u32 *) ((s8 *) actor + 0x24) >> 0x16) != 0) {
        return 0;
    }
    player_index = (u32) (u16) *(u16 *) ((s8 *) actor + 0x1A) >> 5;
    player = player_index;
    if (func_800F52B8(player_index, *target, actor) != 0xB) {
        return 0;
    }
    if (func_800F55D0(player) != *target) {
        return 0;
    }
    return 1;
}

// Shifts rect[1] and rect[3] by +/- amount, sign chosen at random.
void func_80800260_subaddieDll(rect, amount) f32 *rect;
{
    s32 offset;
    f32 offset_f;

    if (func_8001210C(1)) {
        offset = amount;
    } else {
        offset = -amount;
    }
    offset_f = (f32) offset;
    rect[1] += offset_f;
    rect[3] += offset_f;
}

// Returns 1 unless the player is riding on rect[0]; in that case wobbles the rectangle and returns 0.
int subaddieDll_entrypoint_6(s32 rect[3], s32 amount)
{
    s32 player;
    player = func_800F54E4();
    // Matching: `| 0` is needed for the match.
    if (func_800F52B8(player | 0, rect[0]) != 0xB) {
        return 1;
    }
    {
        func_80800260_subaddieDll(rect, amount);
        return 0;
    }
}

void subaddieDll_entrypoint_7()
{
    func_80800260_subaddieDll();
}

// Despawns the actor of the current marker and returns it.
s32 subaddieDll_entrypoint_8()
{
    s32 actor;

    actor = func_80106790();
    // Matching: `| 0` is needed for the match.
    func_8010A570(actor | 0);
    return actor;
}

// Sets the flag, then despawns the actor of the current marker.
s32 subaddieDll_entrypoint_9(Actor *actor, s32 flag)
{
    func_800DA544(flag);
    subaddieDll_entrypoint_8(actor);
}

// Writes the min/max cube-search bounds of a marker id into bounds[0..3].
void subaddieDll_entrypoint_10(s32 marker_id, s16 *bounds)
{
    s32 query[2];
    s32 pad0;
    s16 *coords[2];
    s32 i;
    s16 a;
    s16 b;

    query[0] = marker_id;
    query[1] = -1;
    _gccubesearch_entrypoint_7(query, coords, 2);
    for (i = 0; i < 2; i++) {
        a = coords[0][i * 2];
        b = coords[1][i * 2];
        bounds[i] = a < b ? a : b;
        bounds[i + 2] = b < a ? a : b;
    }
}

// Returns 0 if the actor is in a zone and its position, shifted by the offsets, lies outside it.
int subaddieDll_entrypoint_11(Actor *actor, s32 offset_a, s32 offset_b)
{
    f32 point[3];
    u32 bits;

    if ((*(u32 *) ((u8 *) actor + 0x70) >> 25) == 0)
        return 1;
    func_800EE7F8(point, actor->position);
    func_800EF1B8(point, (f32) offset_a, (f32) offset_b);
    bits = *(u32 *) ((u8 *) actor + 0x70);
    if (func_800CC338(point, (bits >> 25) - 1, ((bits << 22) >> 26) - 1) == -1)
        return 0;
    return 1;
}

// Random point inside a rectangle: out[0] in x range, out[1] in y range.
int subaddieDll_entrypoint_12(s16 rect[3], s16 *out)
{
    out[0] = func_800DC128(rect[0], rect[2]);
    out[1] = func_800DC128(rect[1], rect[3]);
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/su/baddie/Dll.data.s) is defined in C, with values taken from the ROM.
