// Probably assorted actor helpers: ActorInfo flag tests, actor flag bit set/clear, zone test,
// marker position/rotation sync and the blob shadow draw.
#include "common.h"

typedef struct {
    u8 pad_0[0x74];
    union {
        struct {
            u32 unk_0 : 13;
            u32 unk_1 : 1;
            u32 unk_2 : 18;
        } word;
        struct {
            u8 unk_4;
            u8 unk_5 : 5;
            u8 unk_6 : 1;
            u8 unk_7 : 2;
        } bytes;
    } flags;
} Struct80102F14_80102F14;
typedef struct {
    u8 pad_0[0x78];
    union {
        struct {
            u32 unk_0 : 13;
            u32 unk_1 : 1;
            u32 unk_2 : 18;
        } word;
        struct {
            u8 unk_4;
            u8 unk_5 : 5;
            u8 unk_6 : 1;
            u8 unk_7 : 2;
        } bytes;
    } flags;
} Struct80102F14_80102F44;
typedef struct {
    u8 pad0[4];
    f32 pos[3];
    u8 pad10[0x28];
    f32 unk38;
    u8 pad3C[4];
    Unk80132ED0 *unk40;
    u8 pad44[0x20];
    u16 pad64_0 : 15;
    u16 unk64_15 : 1;
    u16 pad66;
    u8 pad68[0xC];
    u32 pad74_0 : 11;
    u32 unk74_11 : 1;
    u32 pad74_12 : 20;
    u8 pad78[4];
    u32 pad7C_0 : 19;
    u32 unk7C_19 : 1;
    u32 pad7C_20 : 12;
} S80103040;
typedef struct {
    u8 pad0[0x1C];
    f32 unk1C;
} R80103040;
extern R80103040 *func_80100368(S80103040 *);
extern void _chbadshad_entrypoint_1(S80103040 *, f32 *, f32);
extern S80103040 *func_80106790(Unk80132ED0 *);
int func_80102FA0();

void func_80102EC0(s32 arg0)
{
}

// Returns whether the actor is inside the zone.
s32 func_80102EC8(u8 *actor, s32 param_1)
{
    s32 unk_0;
    u32 unk_1;
    u32 packed;
    packed = *(u32 *) ((char *) actor + 0x70);
    unk_1 = packed >> 0x19;
    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }
    unk_0 = unk_1 == 0;
    unk_1 = packed >> 0x19;
    if (unk_0 == 0) {
        unk_0 = 0;
        return (func_800CC338(param_1, unk_1 - 1, ((u32) (packed << 0x16) >> 0x1A) - 1,
                              unk_1) +
                1) != unk_0;
    }
}

s32 func_80102F14(void *param_0)
{
    Struct80102F14_80102F14 *actor;

    actor = param_0;
    if (actor->flags.word.unk_1) {
        return 1;
    }
    actor->flags.bytes.unk_6 = 1;
    return 0;
}

s32 func_80102F44(void *param_0)
{
    Struct80102F14_80102F44 *actor;

    actor = param_0;
    if (actor->flags.word.unk_1) {
        return 1;
    }
    actor->flags.bytes.unk_6 = 1;
    return 0;
}

int func_80102F74(s32 param_0, s32 param_1)
{
    func_80102FA0(func_80100368(param_0), param_1);
}

// Tests ActorInfo flag bits; the high bit of the mask selects +0x3C instead of +0x24.
int func_80102FA0(info, mask)
s32 *info;
s32 mask;
{
    s32 flags;

    if (mask & 0x80000000) {
        flags = info[15];
    } else {
        flags = info[9];
    }
    return (flags & 0x7FFFFFFF & mask) ? 1 : 0;
}

int func_80102FDC(f32 *param_0, f32 param_1)
{
    int index;
    index = 14;
    param_0[index] = param_1;
}

// Sets or clears actor flag bit 0x20 at +0x77.
int func_80102FE8(u8 *actor, s32 set)
{
    // Matching: empty block steers IDO's register allocation.
    if ((!(set & 0xFF) && !set) && !set) {
    }
    if (set != 0) {
        actor[0x77] |= 0x20;
    } else {
        actor[0x77] &= ~0x20;
    }
}

// Syncs the marker rotation from the actor.
void func_80103014(s32 actor)
{
    s32 *marker = (s32 *) (actor + 4);
    int index;
    // Matching: needed for the match.
    index = 0xFFFFFFFFu;
    func_800EC124(actor + 4, marker[index], actor + 0x44);
}

// Draws the actor's blob shadow, scaled by ActorInfo+0x1C.
void func_80103040(S80103040 *actor)
{
    S80103040 *parent;
    if (actor->unk74_11) {
        if (actor->unk7C_19) {
            R80103040 *info = func_80100368(actor);
            _chbadshad_entrypoint_1(actor, actor->pos, actor->unk38 * info->unk1C);
        } else if (actor->unk40 != NULL) {
            parent = func_80106790(actor->unk40);
            if (parent->unk7C_19 || !parent->unk64_15) {
                R80103040 *info = func_80100368(actor);
                _chbadshad_entrypoint_1(actor, actor->pos, actor->unk38 * info->unk1C);
            }
        }
    }
}

// Sets or clears actor flag bit 0x40 at +0x7E.
int func_80103110(u8 *actor, s32 set)
{
    int value;
    value = set;
    if (value) {
        // Matching: empty block steers IDO's register allocation.
        if ((!(value & 0xFF) && !value) && !value) {
        }
        actor[0x7E] |= (long) 0x40;
    } else {
        actor[0x7E] &= ~0x40;
    }
}
