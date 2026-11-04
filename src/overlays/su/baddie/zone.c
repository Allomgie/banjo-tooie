#include "common.h"

typedef struct {
    u8 pad[0x70];
    u32 pad_70 : 13;
    u32 unk_70 : 1;
    u32 rest : 18;
    u8 pad_74[4];
    u8 zone_index;
} ZoneS;
extern s32 _glzone_entrypoint_5();
extern s32 func_800BEC28(s32);
extern void _glzone_entrypoint_4(int, int);
extern int func_800BEC1C(void);

// Refreshes the actor's environment-zone index from its position.
void subaddiezone_entrypoint_0(ZoneS *actor)
{
    if (!actor->unk_70) {
        actor->zone_index = _glzone_entrypoint_5(func_800BEC28(0), (u8 *) actor + 4, actor->zone_index);
    }
}

// Notifies the zone system of the actor's current zone.
void subaddiezone_entrypoint_1(Actor *actor)
{
    int zone_set;
    unsigned int zone_set_copy;
    int zone_set_dup;
    // Matching: the redundant copies are needed for the match.
    zone_set = func_800BEC1C();
    zone_set_copy = zone_set;
    zone_set_dup = zone_set_copy | zone_set_copy;
    _glzone_entrypoint_4(zone_set_dup, actor->unk78);
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/su/baddie/zone.data.s) is defined in C, with values taken from the ROM.
