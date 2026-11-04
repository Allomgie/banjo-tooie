// Probably the player health front-end and the auto-show logic of the health HUD. Health get, max,
// add and refill go to per-player or per-transformation storage; damage honors no-damage and cheats.
#include "core2/1E7AB30.h"

// D_80127090 is a byte block of health HUD state; it decides when to show/hide HUD items
// 0xCF/0xCD/0xC9.
extern u8 D_80127090[];
extern s32 func_800D5210(void);
extern void func_800D2748();
extern u8 D_80127094;
extern u8 D_80127097;
extern void func_800D284C(u32);
extern u8 D_80127092;
extern u8 D_80127099;
extern void func_800F9EC0(s32, s32);
extern s32 func_800A3274(PlayerState *);
extern u8 func_800D4EB8(s32);
extern void func_800D4E18(s32, s32);
extern void _batimer_set(PlayerState *, s32, f32);
int func_800A1624();

// Health HUD visibility: show on damage, low health or level entry, with suppression counters.
void func_800A1240(s32 param_0)
{
    D_80127090[9] = func_800D5210();
    D_80127090[6] = (u8) param_0;
    func_800D2748(0xcf, D_80127090[9]);
    func_800D2748(0xcd, D_80127090[9]);
}

void func_800A1294(s32 param_0)
{
    s32 character;
    s32 max_health;

    if ((D_80127094 == 0) && (func_800D3948() == 0) && (func_800DA298(0x6B6) == 0) &&
        (func_800D3E40(9) == 0) && (D_80127097 == 0) &&
        (character = func_8008FD48(), max_health = func_800D4EB8(character), (max_health != 0))) {
        if (param_0 != 0) {
            func_800D2498(0xCF, func_800D4E7C(character), max_health);
            return;
        }
        func_800D24E8(0xCF, func_800D4E7C(character), max_health);
    }
}

void func_800A1364()
{
    ((unsigned char *) D_80127090)[1] = 0;
    ((unsigned char *) D_80127090)[0] = 0;
    func_800D517C();
    func_800A1240(func_8009E958());
}

void func_800A13A0(void)
{
    *(u8 *) D_80127090 = 1;
}

void func_800A13B0(s32 param_0)
{
    *(s8 *) ((s8 *) (s32 *) D_80127090 + 2) =
        _gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(), 0x1000);
    *(s8 *) ((s8 *) (s32 *) D_80127090 + 1) = 0;
    if (func_800F8B64() != 0) {
        *(s8 *) ((s8 *) (s32 *) D_80127090 + 1) = 1;
        *(s8 *) ((s8 *) (s32 *) D_80127090 + 3) = 1;
    }
    if (func_800F99E8() != 0) {
        *(s8 *) ((s8 *) (s32 *) D_80127090 + 1) = 1;
    }
    *(s8 *) ((s8 *) (s32 *) D_80127090 + 4) = 1;
    if (_gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(param_0), 0x1000) != 0) {
        *(s8 *) ((s8 *) (s32 *) D_80127090 + 5) = 1;
        return;
    }
    *(s8 *) ((s8 *) (s32 *) D_80127090 + 5) = 0;
}

// Per-frame health HUD update: applies pending show/hide requests and auto-shows at low health.
void func_800A1450(void)
{
    s32 show_hud;
    s32 health;
    s32 unk_2;
    u8 pending;

    show_hud = 0;
    if (D_80127090[3] != 0) {
        func_800D5034(0, func_8008FD48());
        D_80127090[3] = 0;
    }
    if (D_80127090[0] != 0) {
        if (func_80090128() != 0 && D_80127090[2] == 0) {
            D_80127090[1] = 1;
        }
        D_80127090[0] = 0;
    }
    if (D_80127090[4] != 0) {
        func_800A1240(func_8008FD48());
        D_80127090[4] = 0;
    }
    if (D_80127090[1] != 0) {
        if (func_800C95D4() != 0) {
            show_hud = 1;
            D_80127090[1] = 0;
        }
    } else {
        health = func_800D4E7C(func_8008FD48());
        if (health != 0 && health < 3) {
            show_hud = 1;
        }
    }
    if (D_80127090[7] != 0) {
        show_hud = 0;
        func_800A1624(0);
        func_800CE864(1);
        func_800CF7F4(0);
        unk_2 = func_800D2820(0xCF) || func_800D2820(0xCD);
        if (D_80127090[8] != 0x11) {
            func_800D284C(0xC9);
            unk_2 |= func_800D2820(0xC9);
        }
        if (unk_2 == 0) {
            pending = D_80127090[7];
            D_80127090[7] = 0;
            if (pending == 1) {
                func_800A1240(D_80127090[8]);
                func_800A1294(1);
                D_80127090[8] = 0;
            } else {
                D_80127090[6] = 0;
            }
        }
    }
    if (func_80090128() != 0 && show_hud != 0 && D_80127090[5] == 0) {
        func_800A1294(0);
    }
}

// Player health get/max/damage/heal, no-damage flag and regeneration.
s32 func_800A1618(s32 param_0)
{
    D_80127092 = param_0;
}

int func_800A1624(param_0)
s32 param_0;
{
    if (param_0 != 0) {
        func_800A1294(0);
    } else {
        func_800D284C(0xCF);
    }
}

void func_800A1658(unsigned int param_0)
{
    if ((param_0 != D_80127090[6]) || ((D_80127090[8] != 0) && (param_0 != D_80127090[8]))) {
        D_80127090[7] = 1;
        D_80127090[8] = param_0;
    }
}

int func_800A1694()
{
    *(s8 *) &D_80127097 = 2;
}

u8 func_800A16A4()
{
    return D_80127097;
}

s32 func_800A16B0(void)
{
    return D_80127099;
}

void func_800A16BC(s32 param_0)
{
    if (param_0 != 0) {
        *(u8 *) ((char *) &D_80127090 + 0x5) += 1;
    } else {
        *(u8 *) ((char *) &D_80127090 + 0x5) -= 1;
    }
}

int func_800A16F4(int player)
{
    _batimer_set(player, 0xE, 3.0f);
}

s32 func_800A1718(PlayerState *player)
{
    if (*(s32 *) ((char *) player + 0x158) != 0) {
        func_800F9F04(*(s32 *) ((char *) player + 0x184));
    } else {
        func_800D4E7C(func_800A3274((s32) player));
    }
}

int func_800A1760(Actor *player)
{
    if (*(s32 *) ((char *) player + 0x158)) {
        func_800F9F18(*(s32 *) ((char *) player + 0x184), player);
    } else {
        func_800D4EB8(func_800A3274(player));
    }
}

// Health change entry: delta is negative for damage (-0x3E7 kills). Cheat 9 forces full health.
void func_800A17A8(PlayerState *player, s32 delta)
{
    s32 character;
    if (*(s32 *) ((char *) player + 0x158) != 0) {
        func_800F9EC0(*(s32 *) ((char *) player + 0x184), delta);
    } else {
        character = func_800A3274(player);
        if (delta < 0 && D_80127092 != 0) {
            return;
        }
        if (func_800D4EB8(character)) {
            if (func_800D3E40(9)) {
                delta = func_800D4EB8(character);
            }
            func_800D4E18(character, delta);
            func_800A1294(0);
            if (func_800D3E40(4)) {
                _batimer_set(player, 0xE, 3.0f);
            }
        }
    }
}

int func_800A1870(Actor *player, s32 param_1)
{
    s32 slot;
    if (*(s32 *) ((char *) player + 0x158)) {
        slot = *(s32 *) ((char *) player + 0x184);
        func_800F9F2C(slot);
    } else {
        func_800D4FB8(func_800A3274(player), param_1);
        // Matching: empty test steers IDO's register allocation.
        if ((!param_1 && !param_1) && !param_1) {
        }
        func_800A1294(1);
    }
}

int func_800A18C8(Actor *player)
{
    func_800F9F74(*(s32 *) ((char *) player + 0x184));
}

// Regeneration tick (cheat 4): heals 1 when below max.
void func_800A18E8(s32 player)
{
    s32 character;
    s32 health;

    if (_batimer_decrement(player, 0xE) != 0) {
        character = func_800A3274(player);
        health = func_800D4E7C(character);
        if (health != 0) {
            if (health < func_800D4EB8(character)) {
                func_800FC660(8);
                func_800A17A8(player, 1);
            }
        }
    }
}

// TU-NOTE: this .rodata holds constants used by 1E79FD0 (formerly part of its rodata). They follow
// that file's literals in the ROM, so they cannot live there: IDO places a file's const objects
// before its literals. This is the next file in link order without .rodata of its own.
const struct {
    f32 x;
    f32 pad[3];
} D_80125490 = {0.65f};
