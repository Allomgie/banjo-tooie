// Chase token: each frame finds the chasing actor nearest the player, so only one baddie at a
// time (the nearest chaser, or anyone if nobody is chasing) is allowed to hunt the player.
#include "common.h"

typedef struct {
    s32 frame;
    s32 marker;
} ChaseCache;
extern ChaseCache D_808001D0_suchase;
extern void func_8010D254(f32 *);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 1;
    u32 chasing : 1;
    u32 dead : 1;
    u32 pad_2 : 29;
} ChaseActorFlags;
typedef struct {
    Unk80132ED0 *obj;
    u32 pad_4;
    u32 flags;
} ChaseActorEntry;
extern s32 *func_800BE444(f32 *);
extern ChaseActorEntry *func_800E9E88(s32);
extern ChaseActorEntry *func_800E9EB4(s32);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800EEB40(f32 *, f32 *);
void func_808000A8_suchase();

// Returns the nearest chaser (0 if none); refreshed once per frame.
s32 suchase_entrypoint_0(void)
{
    s32 frame;
    f32 player_pos[3];

    frame = func_8001211C();
    if (frame != D_808001D0_suchase.frame) {
        func_8010D254(player_pos);
        D_808001D0_suchase.frame = frame;
        D_808001D0_suchase.marker = 0;
        func_808000A8_suchase(&D_808001D0_suchase, player_pos);
    }
    return D_808001D0_suchase.marker;
}

// An actor may chase only if nobody chases or it is the nearest chaser.
int suchase_entrypoint_1(s32 *self)
{
    s32 nearest = suchase_entrypoint_0();
    return nearest == 0 || nearest == *self;
}

// Find the chasing actor nearest to pos in the cube cells around it.
void func_808000A8_suchase(cache, pos) ChaseCache *cache;
f32 *pos;
{
    f32 best_dist;
    s32 *cell;
    ChaseActorEntry *entry;
    ChaseActorEntry *end;
    Unk80132ED0 *obj;
    Actor *actor;
    f32 dist;

    best_dist = 1e10f;
    cell = func_800BE444(pos);
    while (*cell) {
        entry = func_800E9E88(*cell);
        end = func_800E9EB4(*cell);
        for (; entry < end; entry++) {
            if (entry->flags & 1) {
                obj = entry->obj;
                if (*(u16 *) ((u8 *) obj + 0x18) & 1) {
                    actor = func_80106790(obj);
                    if (!((ChaseActorFlags *) actor)->dead &&
                        ((ChaseActorFlags *) actor)->chasing) {
                        dist = func_800EEB40(actor->position, pos);
                        if (dist < best_dist) {
                            cache->marker = (s32) obj;
                            best_dist = dist;
                        }
                    }
                }
            }
        }
        cell++;
    }
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM).
ChaseCache D_808001D0_suchase = {-0x1, 0x0};
