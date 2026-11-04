// Most likely the storage for props placed in the world's spatial cubes: insert, remove, iterate
// and fix up the two global prop arrays, plus init/free/update hooks of the world-object system.
#include "common.h"

extern int D_80132DB4;
extern s32 func_800B3CDC();
extern void func_800BE4C4(void);
// TU-NOTE: D_80132DB0 (0x14-byte node props) and D_80132DB4 (0xC-byte actor/model/sprite
// props) are variable-length arrays shared by all cubes. A cube is four s16:
// node start index, node count, prop start index, prop count.
extern s32 D_80132DB0;
// Actor/model/sprite prop (0xC bytes). unk_bitN are bits of the byte at +0xB.
typedef struct {
    u32 unk_0 : 30;
    u32 unk_3_1 : 1;
    u32 unk_3_0 : 1;
    u32 unk_4;
    u32 unk_8 : 16;
    u32 unk_A : 5;
    u32 phase : 5;
    u32 unk_bit5 : 1;
    u32 unk_bit4 : 1;
    u32 unk_bit3 : 1;
    u32 unk_bit2 : 1;
    u32 unk_bit1 : 1;
    u32 is_actor : 1;
} local_type;
extern f32 func_800DC0C0(void);
// Node prop (0x14 bytes).
typedef struct {
    u8 pad[4];
    u32 unk_4 : 16;
    u32 unk_6 : 9;
    u32 unk_7_1 : 6;
    u32 unk_7_0 : 1;
    s16 unk_8;
    u8 unk_A, unk_B;
    void *unk_C;
    u32 unk_10 : 22;
    u32 unk_12_1 : 1;
    u32 unk_12_0 : 1;
    u32 unk_13_7 : 1;
    u32 unk_13_6 : 1;
    u32 unk_13_5 : 1;
    u32 unk_13_4 : 1;
    u32 unk_13_2 : 2;
    u32 unk_13_0 : 2;
} LocalRecord;
void func_800EBE24(u32);
void *func_800B422C(u32 *, s32);
u32 *func_800BE5C4();
extern void func_800B42A0();
void func_800E9CF4();
s32 func_800E9D68();
int func_800E9DD4();
int func_800E9E88();
int func_800E9EB4();

void func_800E96E0()
{
    func_800EA3A0();
    func_800EBB6C();
}

void func_800E9708()
{
    func_800EA370();
}

// Init: creates the node prop array (0x14-byte elements) and the actor prop array (0xC).
void func_800E9728()
{
    func_800EA390();
    func_800EB70C();
    D_80132DB0 = func_800B42FC(0x14, 0xA);
    D_80132DB4 = func_800B42FC(0xC, 0xA);
}

// Free: releases both prop arrays.
void func_800E9774(void)
{
    func_800EA398();
    func_800EB750();
    func_800B42DC((int) D_80132DB0);
    D_80132DB0 = 0;
    func_800B42DC(D_80132DB4);
    D_80132DB4 = 0;
}

// Update: carry-pre, actor update, carry-post, unless the world state is 1.
int func_800E97C0()
{
    if (func_800EA09C() != 1) {
        func_800EA45C();
        func_800A5CFC();
        func_800EA51C();
    }
}

// Inserts a prop into the cube's range, clearing its is_actor flag. If the array moved, all
// cubes are re-pointed; if the cube's start moved, marker back-pointers are fixed.
u8 *func_800E9804(cube)
u8 *cube;
{
    u8 *result;
    s32 old_array;
    s32 old_start;
    u8 *prop;

    old_array = *(s32 *) (u8 *) &D_80132DB4;
    old_start = (s32) *(s16 *) (cube + 4);
    prop = func_800B3CDC((u8 *) &D_80132DB4, cube + 4, cube);
    // Matching: the extra copy of the result is needed for the match.
    result = prop;
    prop[0xB] = (u8) (prop[0xB] & 0xFFFE);
    if (old_array != *(s32 *) (u8 *) &D_80132DB4) {
        func_800BE4C4();
    } else if (old_start != *(s16 *) (cube + 4)) {
        func_800E9CF4(cube);
    }
    return result;
}

// Inserts a node prop into the cube's node range.
int func_800E9898(s32 cube)
{
    s32 cube_copy;
    // Matching: "| 0" is needed for the match.
    cube_copy = cube | 0;
    func_800B3CDC(&D_80132DB0, cube_copy);
}

// Inserts an actor prop with cleared flags and a random phase (0..31).
local_type *func_800E98C0(void)
{
    local_type *prop;
    prop = func_800E9804();
    prop->is_actor = 0;
    prop->unk_bit1 = 0;
    prop->unk_A = 0;
    prop->unk_3_1 = 0;
    prop->phase = (u32) (func_800DC0C0() * 32.0f);
    prop->unk_bit3 = 0;
    prop->unk_bit2 = 0;
    prop->unk_bit4 = 1;
    return prop;
}

// Inserts a prop with the actor flag set.
void func_800E99E0()
{
    typedef struct {
        u8 pad_0[0xB];
        u8 unk_bit7 : 1;
        u8 unk_bit6 : 1;
        u8 unk_bit5 : 1;
        u8 unk_bit4 : 1;
        u8 unk_bit3 : 1;
        u8 unk_bit2 : 1;
        u8 unk_bit1 : 1;
        u8 is_actor : 1;
    } Struct800E99E0;
    Struct800E99E0 *prop;

    prop = func_800E9804();
    prop->is_actor = 1;
    prop->unk_bit3 = 0;
    prop->unk_bit2 = 0;
    prop->unk_bit4 = 1;
}

// Inserts a node prop with default values.
void func_800E9A24(s32 cube)
{
    LocalRecord *node;
    node = func_800E9898(cube);
    node->unk_B = 0;
    node->unk_6 = 50;
    node->unk_7_1 = 0;
    node->unk_7_0 = 0;
    node->unk_A = 0;
    node->unk_8 = 0;
    node->unk_C = 0;
    node->unk_12_1 = 0;
    node->unk_12_0 = 1;
    node->unk_13_7 = 0;
    node->unk_13_6 = 0;
    node->unk_13_5 = 0;
    node->unk_13_4 = 0;
    node->unk_13_2 = 0;
    node->unk_13_0 = 0;
}

// Removes a prop from the cube; returns the prop's unk_bit1 flag.
u32 func_800E9AC0(u8 *cube, u8 *prop)
{
    u32 flag;
    s32 index;
    s32 old_array;
    s32 old_start;

    flag = (u32) (*(s32 *) ((char *) prop + 0x8) << 0x1E) >> 0x1F;
    index = (s32) (prop - func_800E9E88()) / 12;
    old_array = (s32) D_80132DB4;
    old_start = (s32) *(s16 *) ((char *) cube + 0x4);
    func_800B3FD0((s32 *) &D_80132DB4, cube + 4, index, cube);
    if (old_array != (s32) D_80132DB4) {
        func_800BE4C4();
    } else if ((old_start + 1) != *(s16 *) ((char *) cube + 0x4)) {
        func_800E9CF4(cube);
    }
    return flag;
}

// Removes a node prop from the cube.
int func_800E9B74(s32 cube, s32 node)
{
    s32 index;
    u8 *unk_0;
    index = (node - func_800E9D68()) / 0x14;
    if (index < func_800E9DD4(cube)) {
        unk_0 = func_800BE5C4(cube);
        --*unk_0;
    }
    func_800B3FD0(&D_80132DB0, cube, index);
}

// Returns the cube's node prop at index, or 0 if out of range.
int func_800E9BF4(s16 *cube, s32 index)
{
    if ((index < 0) || (index >= cube[1])) {
        return 0;
    }
    return func_800E9D68(cube) + (index * 0x14);
}

// Frees the markers of the cube's actor props, then releases its prop ranges.
void func_800E9C44(s32 cube)
{
    s32 first_check;
    s32 *prop;
    s32 *end;
    s32 *unk_0;
    first_check = func_800E9E88(cube);
    if (first_check != 0) {
        prop = func_800E9E88(cube);
        end = func_800E9EB4(cube);
        while (prop < end) {
            if (prop[2] & 1) {
                func_800EBE24(prop[0]);
            }
            prop += 3;
        }

        func_800B422C((u32 *) &D_80132DB4, cube + 4);
    }
    func_800B422C((u32 *) &D_80132DB0, cube);
    unk_0 = func_800BE5C4(cube);
    *(u8 *) unk_0 = 0;
}

// Rewrites the marker->prop back-pointers of the cube's props that have the is_actor flag.
void func_800E9CF4(cube) u8 *cube;
{
    u32 begin;
    u32 end;
    u32 prop;

    if (*(s16 *) ((s8 *) cube + 6) != 0) {
        begin = func_800E9E88();
        end = func_800E9EB4(cube);
        prop = begin;
        if (prop < end) {
            do {
                if ((*(s32 *) ((s8 *) prop + 8) & 1) == 1) {
                    **(u32 **) (s8 *) prop = prop;
                }
                prop += 0xC;
            } while (prop < end);
        }
    }
}

// Returns the node prop at index.
s32 func_800E9D68(index)
s32 index;
{
    s32 index_copy = index;
    func_800B42A0(D_80132DB0, index_copy);
}

// Returns the end of the cube's node props.
s32 func_800E9D90(u8 *cube)
{
    return ((*((s16 *) (((s8 *) cube) + 2))) * 0x14) + func_800E9D68();
}

// Returns the cube's node prop count.
func_800E9DC4(s16 *cube)
{
    return cube[1];
}

// Returns the cube's actor prop count.
func_800E9DCC(s16 *cube)
{
    return cube[3];
}

int func_800E9DD4()
{
    u8 *unk_0;
    unk_0 = func_800BE5C4();
    return *unk_0;
}

// Defragments both prop arrays; re-points the cubes if the actor prop array moved.
void func_800E9DF8(void)
{
    void *new_array;
    D_80132DB0 = defrag(((void *) D_80132DB0));
    new_array = defrag(((void *) D_80132DB4));

if (new_array != (void *) D_80132DB4) {
    D_80132DB4 = new_array;
    func_800BE4C4();
}

}

int func_800E9E4C(s32 cube[3], s32 unused)
{
    u8 *unk_0;
    unk_0 = func_800B4290(cube + 1);
    unk_0 = func_800B4290(cube);
    unk_0 = (s32 *) func_800BE5C4(cube);
    *unk_0 = 0;
}

// Returns the cube's first actor prop.
int func_800E9E88(cube)
u32 cube;
{
    func_800B42A0(((u32) D_80132DB4), cube + 4, cube);
}

// Returns the end of the cube's actor props (0xC bytes each).
int func_800E9EB4(cube)
s16 *cube;
{
    char zero;
    zero = 0;
    // Matching: the zero index built from "zero ^ zero ^ zero" and "- -6" are needed for the match.
    return ((unsigned int) ((*((s16 *) (((s8 *) (&cube[(zero ^ zero) ^ zero])) - -6))) *
                            0xC)) +
           func_800E9E88();
}

// Removes the node prop found by _gccubesearch_entrypoint_17.
void func_800E9EE8(s32 query)
{
    s32 node;
    s32 cube;

    node = _gccubesearch_entrypoint_17(query, &cube);

if (node != 0) {
    func_800E9B74(cube, node);
}

}
