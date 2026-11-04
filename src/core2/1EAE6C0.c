// Probably the health (honeycomb energy) of each playable character: base and extra-honeycomb max,
// clamped damage and heal with a hurt sound, and the refill policy when switching character.
#include "core2/1EAE6C0.h"

extern s32 D_8012B420;
extern u8 D_8011B641[];
extern u8 D_8011B642[];
typedef struct {
    u8 unused, current, max;
} LocalEntry;
extern LocalEntry D_8011B640[];
int func_800D4E7C();
void func_800D4FB8();

// With the shared-health flag set, 10 maps to 1 and 4/11 map to 0.
s32 func_800D4DD0(s32 character)
{
    if (D_8012B420 != 0) {
        switch (character) {
            case 10:
                character = 1;
                break;
            case 4:
            case 11:
                character = 0;
                break;
        }
    }
    return character;
}

void func_800D4E18(s32 character, s32 delta)
{
    if (character == 9) {
        character = 1;
    }
    if (delta < 0) {
        func_800FC660(0x74);
    }
    func_800D4FB8(character, func_800D4E7C(character) + delta);
}

// Current health.
int func_800D4E7C(character)
s32 character;
{
    s32 idx;
    if (character == 9) {
        character = 1;
    }
    idx = func_800D4DD0(character);
    return D_8011B641[idx * 3];
}

// Max health.
u8 func_800D4EB8(s32 character)
{
    s32 idx;
    if (character == 9) {
        character = 1;
    }
    idx = func_800D4DD0(character);
    return D_8011B642[idx * 3];
}

// Base max health per character.
int func_800D4EF4(s32 character)
{
    switch (character - 1) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 5:
            return 3;
        case 6:
            return 6;
        case 7:
            return 5;
        case 9:
            return 3;
        case 10:
            return 2;
        case 11:
            return 5;
        case 12:
            return 4;
        case 13:
            return 0;
        case 14:
            return 4;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 4;
        case 18:
            return 0;
    }
    return 0;
}

func_800D4F9C(character)
{
    if (character == 2)
        return 0;
    return 1;
}

// Sets current health, clamped to 0..max.
void func_800D4FB8(character, value) s32 character;
s32 value;
{
    s32 idx;
    u8 *entry;
    if (character == 9) {
        character = 1;
    }
    idx = func_800D4DD0(character);
    if (value < 0) {
        entry = (u8 *) D_8011B640 + idx * 3;
        value = 0;
    } else {
        entry = (u8 *) D_8011B640 + idx * 3;
        if (entry[2] < value) {
            value = entry[2];
        }
    }
    entry[1] = value;
}

// Refill policy when switching character; entries 10/11 split the health between them.
void func_800D5034(s32 param_0, s32 character)
{
    s32 new_health;
    s32 max_health;
    if (character == 9)
        character = 1;
    new_health = D_8011B640[character].current;
    max_health = D_8011B640[character].max;
    switch (character) {
        case 1:
            switch (param_0) {
                case 0:
                case 2:
                case 6:
                case 7:
                case 8:
                case 12:
                case 15:
                case 16:
                case 18:
                case 19:
                    new_health = max_health;
                    break;
                case 10:
                case 11:
                    new_health = D_8011B640[10].current + D_8011B640[11].current;
                    break;
            }
            break;
        case 2:
            new_health = 1;
            break;
        case 6:
        case 7:
        case 8:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            new_health = max_health;
            break;
        case 10:
        case 11:
            if ((param_0 == 0) != 0) {
                new_health = max_health;
                func_800D4FB8(character == 10 ? 11 : 10, max_health);
            } else {
                new_health = (s32) D_8011B640[param_0].current / 2;
                if (character == 10)
                    new_health += (s32) D_8011B640[param_0].current % 2;
                if (!new_health)
                    new_health = 1;
            }
    }
    func_800D4FB8(character, new_health);
}

// Initializes every entry: base health per character plus the extra honeycomb amount.
void func_800D517C()
{
    u8 *entry;
    u32 *shared;
    s32 i;
    s32 max_health;
    s32 base;
    s32 extra;

    extra = _gcextra_entrypoint_0();
    shared = (u32 *) &D_8012B420;
    *shared = 0;
    entry = (u8 *) D_8011B640;
    i = 0;
    do {
        base = func_800D4EF4(i);
        max_health = base;
        if ((base != 0) && (func_800D4F9C(i) != 0)) {
            max_health += extra;
        }
        i += 1;
        entry += 3;
        entry[-1] = max_health;
        entry[-2] = max_health;
    } while (i != 0x14);
}

int func_800D5210(character)
{
    if (character == 9) {
        character = 1;
    }

    return ((char *) D_8011B640)[character * 3];
}

void func_800D5234(s32 enabled)
{
    D_8012B420 = enabled;
}

int func_800D5240()
{
    return D_8012B420;
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1EAE6C0.data.s) is defined here in C.
// Values are taken from the ROM. D_8011B641 = D_8011B640 + 0x1 and D_8011B642 = D_8011B640 + 0x2
// are linker symbols in undefined_syms.us.txt.
LocalEntry D_8011B640[21] = {
    0x0,  0x0,  0x0,  0x1,  0x0,  0x0,  0x32, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0,
    0x0,  0x0,  0x31, 0x0,  0x0,  0x36, 0x0,  0x0,  0x2D, 0x0,  0x0,  0x0, 0x0, 0x0,  0x10, 0x0,
    0x0,  0x5F, 0x0,  0x0,  0x2F, 0x0,  0x0,  0x11, 0x0,  0x0,  0x35, 0x0, 0x0, 0x2E, 0x0,  0x0,
    0x34, 0x0,  0x0,  0x37, 0x0,  0x0,  0x30, 0x0,  0x0,  0x30, 0x0,  0x0, 0x0, 0x0,  0x0};
