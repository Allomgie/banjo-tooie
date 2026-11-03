#include "core2/1E78170.h"

// TU-NOTE: bss of this unit, in address order (0x80127040-0x80127080). The (map, entrance)
// return point stack lives at D_80127040+0x10 (4 entries), its count at D_80127060[0].
f32 D_80127040;
f32 D_80127044;
f32 D_80127048;
u8 D_8012704C;
s32 D_80127050[4];
u8 D_80127060[8];
f32 D_80127068;
f32 D_8012706C;
f32 D_80127070;
u8 D_80127074;
u8 D_80127075;
u8 D_80127076;
u8 D_80127077;
u8 D_80127078;
u8 D_80127079;
u8 D_8012707A;
u8 D_8012707B;
s16 D_8012707C;
void func_8009E9FC(f32 param_0);
void func_8009EAE8();
void func_8009EB0C(f32 param_0);
void func_8009EC3C();
void func_8009EC60();

extern s32 D_80127080;

// Resets the per-session floats and flags.
void func_8009E880(void)
{
    *(s8 *) ((s8 *) (s32 *) &D_80127068 + 0xC) = 1;
    *(s8 *) ((s8 *) (s32 *) &D_80127068 + 0xD) = 0;
    *(s8 *) ((s8 *) (s32 *) &D_80127040 + 0xC) = 1;
    *(f32 *) ((s8 *) (s32 *) &D_80127040 + 0) = 0.0f;
    *(f32 *) ((s8 *) (s32 *) &D_80127040 + 4) = 0.0f;
    *(f32 *) ((s8 *) (s32 *) &D_80127040 + 8) = 0.0f;
}

void func_8009E8B4(void)
{
    func_800C6E58();
}

// Resets the player globals on game start.
void func_8009E8D4(void)
{
    func_800C6E60();
    *(u8 *) ((u8 *) &D_80127040 + 0xC) = func_800D3B60();
    *(f32 *) (u8 *) &D_80127040 = 0.0f;
    *(f32 *) ((u8 *) &D_80127040 + 4) = 0.0f;
    *(f32 *) ((u8 *) &D_80127040 + 8) = 0.0f;
    *(s32 *) ((u8 *) &D_80127068 + 0x18) = 0;
    *(u8 *) ((u8 *) &D_80127068 + 0xC) = 0;
    *(u8 *) ((u8 *) &D_80127068 + 0xD) = 0;
    *(u8 *) ((u8 *) &D_80127068 + 0xE) = 0;
    *(u8 *) ((u8 *) &D_80127068 + 0xF) = 0;
    *(u8 *) ((u8 *) &D_80127068 + 0x10) = 1;
    *(f32 *) (u8 *) &D_80127068 = 0.0f;
    *(f32 *) ((u8 *) &D_80127068 + 4) = 0.0f;
    *(f32 *) ((u8 *) &D_80127068 + 8) = 0.0f;
    func_800DA524(0x3EC);
    func_8009EAE8(0);
}

s32 func_8009E958(void)
{
    return D_8012704C;
}

s32 func_8009E964(void)
{
    return *(u8 *) &D_80127078;
}

f32 func_8009E970(void)
{
    return (f32) D_80127048;
}

float func_8009E97C()
{
    return D_80127040;
}

float func_8009E988()
{
    return D_80127044;
}

u8 func_8009E994()
{
    return D_80127075;
}

void func_8009E9A0(void)
{
}

void func_8009E9A8(void)
{
    func_8009E9FC(0.0f);
    func_8009EB0C(0.0f);
}

void func_8009E9D8(s32 transformation_id)
{
    D_8012704C = transformation_id;
}

// Matching: the temporary is needed for the match.
void func_8009E9E4(unsigned int unk_0)
{
    unsigned int value;
    value = unk_0;
    D_80127078 = value;
}

void func_8009E9F0(f32 unk_0)
{
    D_80127048 = unk_0;
}

void func_8009E9FC(f32 unk_0)
{
    D_80127040 = unk_0;
}

void func_8009EA08(f32 unk_0)
{
    D_80127070 = unk_0;
}

float func_8009EA14()
{
    return (float) D_8012706C;
}

u8 func_8009EA20()
{
    return D_80127077;
}

// Returns the Dragon Kazooie ability flag.
s32 func_8009EA2C()
{
    return func_800DA298(FLAG_3EC_ABILITY_DRAGON_KAZOOIE);
}

s32 func_8009EA4C(void)
{
    return *(u8 *) &D_80127074;
}

s32 func_8009EA58()
{
    return D_80127080;
}

s32 func_8009EA64()
{
    return D_8012707C;
}

s32 func_8009EA70(void)
{
    return *(u8 *) &D_80127076;
}

float func_8009EA7C()
{
    return D_80127068;
}

float func_8009EA88()
{
    return D_80127070;
}

void func_8009EA94(f32 unk_0)
{
    D_8012706C = unk_0;
}

void func_8009EAA0(int unk_0)
{
    D_80127077 = unk_0;
}

// Sets the Dragon Kazooie ability flag.
int func_8009EAAC(s32 value)
{
    // Matching: | 0 is needed for the match.
    func_800DA3B8(0x3EC, value | 0);
}

void func_8009EAD0(int unk_0)
{
    D_80127074 = unk_0;
}

int func_8009EADC(s32 unk_0)
{
    D_80127080 = unk_0;
}

void func_8009EAE8(ride_state) unsigned int ride_state;
{
    D_8012707C = ride_state;
}

void func_8009EAF4(unsigned int unk_0)
{
    D_80127076 = unk_0;
}

void func_8009EB00(f32 unk_0)
{
    D_80127068 = unk_0;
}

void func_8009EB0C(f32 unk_0)
{
    D_80127044 = unk_0;
}

// Matching: the temporary and ^ 0 are needed for the match.
void func_8009EB18(int unk_0)
{
    int value;
    D_80127075 = (value = unk_0) ^ 0;
}

// Pushes a (map, entrance) return point.
void func_8009EB24(map_id, entrance_id) s16 map_id;
s16 entrance_id;
{
    s32 i;
    for (i = 3; i != 0; i--) {
        ((s32 *) &D_80127040)[i + 4] = ((s32 *) &D_80127040)[i + 3];
    }
    ((u8 *) (s32 *) &D_80127040)[0x20]++;
    func_8009EC60(map_id, entrance_id);
}

void func_8009EB8C(map_id, entrance_id) s16 map_id;
s16 entrance_id;
{
    func_8009EC3C();
    ((u8 *) (s32 *) &D_80127040)[0x20] += 1;
    func_8009EC60(map_id, entrance_id);
}

// Pops the top return point.
void func_8009EBD0()
{
    s32 i;
    for (i = 0; i < 3; i++) {
        ((s32 *) (u8 *) &D_80127040)[i + 4] = ((s32 *) (u8 *) &D_80127040)[i + 5];
    }

    ((u8 *) &D_80127040)[0x20]--;
}

s32 func_8009EC08(s16 *out_map_id, s16 *out_entrance_id)
{
    if (((s16 *) &D_80127040)[0x8] != 0) {
        *out_map_id = ((s16 *) &D_80127040)[0x8];
        *out_entrance_id = ((s16 *) &D_80127040)[0x9];
        return 1;
    }
    return 0;
}

void func_8009EC3C(void)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        D_80127050[i] = 0;
    }
    *(u8 *) &D_80127060 = 0;
}

void func_8009EC60(map_id, entrance_id) s16 map_id;
s16 entrance_id;
{
    *(s16 *) ((char *) (s16 *) &D_80127040 + 0x10) = map_id;
    *(s16 *) ((char *) (s16 *) &D_80127040 + 0x12) = entrance_id;
}

int func_8009EC7C()
{
    return D_80127060[0];
}

// Replaces the return point matching (map, entrance).
s32 func_8009EC88(s32 map_id, s32 entrance_id, s32 new_map_id, s32 new_entrance_id)
{
    s32 i;
    u8 *entry;
    int map_copy;
    map_copy = map_id;
    i = 0;
    if ((s32) *(u8 *) &D_80127060 > 0) {
        entry = (u8 *) &D_80127040;
    loop_2:
        i += 1;

        if ((map_copy == *(s16 *) ((s8 *) entry + 0x10)) &&
            (entrance_id == *(s16 *) ((s8 *) entry + 0x12))) {
            *(s16 *) ((s8 *) entry + 0x10) = new_map_id;
            *(s16 *) ((s8 *) entry + 0x12) = new_entrance_id;
            return 1;
        }
        entry += 4;
        if (i >= (s32) *(u8 *) &D_80127060) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return 0;
}
