#include "common.h"

// TU-NOTE: D_80127F28 is a cache of 44 shared emitters (index 0 unused); both structs below view the same entries.
typedef struct {
    f32 keepalive;
    s32 emitter;
    unsigned in_use : 1;
    unsigned sprite_id : 10;
    unsigned unk_8 : 21;
} local_type_800B56D0;
typedef struct {
    s32 keepalive, emitter;
    u32 in_use : 1;
    u32 sprite_id : 10;
    u32 unk_8 : 21;
} local_type_800B5758;
extern local_type_800B5758 D_80127F28[45];
typedef struct {
    int unk0;
    int unk4;
    int unk8;
} Struct800B5824;
extern Struct800B5824 D_80127F34[528];
typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[3];
} Sub_B5884;
typedef struct {
    Sub_B5884 sub[4];
} E_B5884;
typedef struct {
    u8 pad0[4];
    void *unk4;
    u8 unk8;
    u8 pad9[3];
} S_B58D4;
extern void func_800B5450();
extern u32 D_80128144[];
extern f32 func_800D8FF8(void);
extern int func_800BA28C(u32);
extern u8 D_80127F20[];
extern s32 func_800B5548(s32);
void func_800B58D4();

// Returns the emitter for a slot, creating it on first use; resets the keepalive timer.
s32 func_800B56D0(slot)
u8 slot;
{

if ((local_type_800B56D0 *) D_80127F28[slot].emitter == 0) {
    *(u8 *) D_80127F20 = slot;
    ((local_type_800B56D0 *) D_80127F28)[slot].emitter =
        func_800B53A4((local_type_800B56D0 *) D_80127F28[slot].sprite_id);
    func_800B5534((local_type_800B56D0 *) D_80127F28[slot].emitter);
    *(u8 *) D_80127F20 = 0;
}

((local_type_800B56D0 *) D_80127F28)[slot].keepalive = 1.0f;
return ((local_type_800B56D0 *) D_80127F28)[slot].emitter;
}

// Reserves a free slot for the given sprite id; returns 0 if none is free.
u8 func_800B5758(s32 sprite_id)
{
    s32 i;
    for (i = 1; i < 45; i++) {

if (!D_80127F28[i].in_use) {
    D_80127F28[i].in_use++;
    D_80127F28[i].emitter = 0;
    D_80127F28[i].sprite_id = sprite_id;
    return i;
}

}
return 0;
}

void func_800B5824()
{
    int i;
    Struct800B5824 *entry;
    entry = D_80127F34;
    for (i = 1; i < 0x2D; i++) {
        if ((u32) entry->unk8 >> 31) {
            func_800B58D4(i & 0xFF);
        }

entry++;
}
}

void func_800B5884(void)
{
    s32 i;
    s32 j;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 4; j++) {
            ((E_B5884 *) D_80127F34)[i].sub[j].unk8 &= 0xFF7F;

}
}
}

// Releases one slot, freeing its emitter if present.
void func_800B58D4(slot) u8 slot; {
    if (((S_B58D4 *) D_80127F28)[slot].unk4 != 0) { func_800B5450(((S_B58D4 *) D_80127F28)[slot].unk4); }
    ((S_B58D4 *) D_80127F28)[slot].unk8 &= ~0x80;
}

// Per frame: frees emitters whose keepalive timer has run out while empty.
void func_800B592C(void)
{
    u32 *entry;
    u32 *end;
    f32 delta = func_800D8FF8();
    entry = &((u32 *) D_80127F34)[0]; end = &D_80128144[0];
    do {
        if ((entry[2] >> 31) && entry[1]) {
            if (func_800BA28C(entry[1])) {
                *(f32 *)entry -= delta;
                if (*(f32 *)entry <= 0.0f) {
                    func_800B5450(entry[1]);
                    entry[1] = 0;
                }
            }

}
entry += 3;
} while (entry != end);
}

// Frees all slot emitters except the one currently being created.
// Matching: the empty if, empty do-while and comma expression in the body are needed for the match.
void func_800B59E0(void)
{
    u32 *entry;
    s32 i;
    char *flags;
    do { entry = (u32 *) (((u8 *) D_80127F34)); i = 1; do { flags = ((char *) entry) + 0x8; if (((*((u32 *) flags)) >> 0x1F) != 0) { if (((*((u32 *) (((char *) entry) + 0x4))) != 0) && (i != (*((u8 *) D_80127F20)))) { if (entry) { } do { } while (0); func_800B5450(*((u32 *) (((char *) entry) + 0x4))); *((u32 *) ((0, ((char *) entry) + 0x4))) = 0; } } i += 1; entry += 3; } while (i != 0x2D); } while (0);
}

void func_800B5A6C()
{
    s32 *entry;
    entry = ((s32 *) D_80127F34); do {

if (((u32) entry[2] >> 0x1F) != 0) {
    if (entry[1] != 0) {
        entry[1] = func_800B5548(entry[1]);
    }
}

entry += 3;
}
while (entry != (((s32 *) D_80128144)))
    ;
}

// Group init.
int func_800B5AD4()
{
    _fxsparkle_entrypoint_2();
    func_800B4428();
    func_800B5B40();
}

// Group teardown.
int func_800B5B04()
{
    func_800B5B88();
    _fxsparkle_entrypoint_3();
    func_800B43E0();
}
