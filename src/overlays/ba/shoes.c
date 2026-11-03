#include "common.h"
#include "playerstate.h"

extern void bastatetimer_set(void *, s32, f32);
extern f32 bastatetimer_getPrevious(void *, s32);
extern f32 bastatetimer_get(void *, s32);
extern void _baalarm_entrypoint_3(void *, f32, f32);
extern void func_8009DE38(void *, s32, f32);
extern int func_8008DAA8(void);
extern int func_8009EA4C(void *param_0);
extern int func_8009EA70(void *param_0);
extern s32 D_80800AD0_bashoes[];
extern s32 D_80800B4C_bashoes[];
extern s32 D_80800B90_bashoes[];
extern s32 func_800B53A4(s32);
extern void func_80092E08(PlayerState *, f32 *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_80092E2C(PlayerState *, f32 *);
extern s32 D_80800BD4_bashoes[];
extern void func_8009C128(PlayerState *, f32 *);
extern f32 func_8009BB5C(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80090010(void);
extern void func_800EFCD8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
// Shoe state at PlayerState+0x10C
typedef struct {
    s32 duration;
    u8 mode;
    u8 pad_5[3];
    void (*on_mode_change)(PlayerState *, s32, s32);
} ShoeState40;
typedef struct Mass44Shoes {
    u8 pad_0[4];
    u8 mode;
    u8 pad_5[7];
    void (*update_callback)(PlayerState *, u8);
    u8 pad_10[4];
    f32 unk_14;
} Mass44Shoes;
int bashoes_entrypoint_6();

s32 bashoes_entrypoint_0()
{
    return 0x18;
}

s32 bashoes_entrypoint_1(s32 player)
{
    return ((u8 *) *(u8 **) (player + 0x10c))[4];
}

s32 bashoes_entrypoint_2(s32 player)
{
    return ((u8 **) (player + 0x10c))[0][0x10];
}

// Start the shoe timer and pick the music for the current mode
void func_80800020_bashoes(u8 *player)
{
    bastatetimer_set(player, 3, **(f32 **) (player + 0x10C));
    if (func_800EA068(0x800)) {
        if ((*(u8 **) (player + 0x10C))[4] == 3)
            func_800FC660(0x2B);
    } else {
        switch ((*(u8 **) (player + 0x10C))[4]) {
            case 3:
                func_800C77DC(3);
                break;
            case 4:
                func_800C77DC(6);
                break;
            case 5:
                func_800C77DC(5);
                break;
        }
    }
}

int func_808000D4_bashoes(Actor *player, s32 new_mode)
{
    _baalarm_free();
    func_800A0DB8(player, 1);
    if (new_mode) {
        func_800C77DC(1);
        bastatetimer_set(player, 3, 0);
    }
}

int func_80800128_bashoes(Actor *player, s32 flag, s32 feet_model, s32 old_mode)
{
    _baalarm_new();
    baflag_clear(player, flag);
    func_800A0DB8(player, feet_model);
    if (old_mode != 0) {
        func_80800020_bashoes(player);
    }
}

void func_80800180_bashoes(u8 *player, s32 flag)
{
    f32 prev_time;
    f32 time;
    s32 sfx_id;

    prev_time = bastatetimer_getPrevious(player, 3);
    time = bastatetimer_get(player, 3);
    if (!(*(u8 **) (player + 0x10C))[5]) {
        _baalarm_entrypoint_3(player, prev_time, time);
        if (time == 0.0f && prev_time != time && baflag_isFalse(player, 0x14)) {
            if (func_800A3274(player) == 11) {
                sfx_id = 0x459D;
            } else {
                sfx_id = 0x3EB;
            }
            func_8009DE38(player, sfx_id, 1.0f);
        }
    }
    if (baflag_isTrue(player, flag)) {
        baflag_clear(player, flag);
        func_80800020_bashoes(player);
        bastatetimer_set(player, 3, **(f32 **) (player + 0x10C));
    }
    if (bastatetimer_isDone(player, 3) && !(*(u8 **) (player + 0x10C))[5]) {
        bashoes_entrypoint_6(player, 2);
    }
}

void bashoes_entrypoint_3(s32 player)
{
    bashoes_entrypoint_6(player, 0);
}

void bashoes_entrypoint_4(u8 *player)
{
    s32 mode;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x10C) + 0x10) = 0;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x10C) + 0x14) = 0.0f;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x10C) + 5) = 0;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x10C) + 8) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x10C) + 4) = 0;
    if ((func_8008DAA8() != 0) && (func_8009EA4C(player) == 2)) {
        mode = func_8009EA70(player);
        if (mode != 0) {
            bashoes_entrypoint_6(player, mode);
            return;
        }
        // Matching: the empty blocks are needed for the match.
        if (1) {
        }
        if (1) {
        }
        if (1) {
        }
        if (1) {
        }
        if (1) {
        }
        bashoes_entrypoint_6(player, 1);
        return;
    }
    bashoes_entrypoint_6(player, 1);
}

void bashoes_entrypoint_5(void *player, s32 flag)
{
    ((s8 *) *(void **) ((char *) player + 0x10C))[5] = flag;
}

// Switch mode: 1 none, 2 available, 3-5 active (one per shoe type)
int bashoes_entrypoint_6(player, new_mode)
PlayerState *player;
s32 new_mode;
{
    s32 old_mode;
    void (*callback)(PlayerState *, s32, s32);
    old_mode = (*(ShoeState40 **) ((u8 *) player + 0x10C))->mode;
    switch (old_mode) {
        case 3:
            func_808000D4_bashoes(player, new_mode);
            break;
        case 4:
            func_808000D4_bashoes(player, new_mode);
            break;
        case 5:
            func_808000D4_bashoes(player, new_mode);
            break;
    }
    (*(ShoeState40 **) ((u8 *) player + 0x10C))->mode = new_mode;
    switch (new_mode) {
        case 1:
            func_8009ADF0(player, 13, 0);
            break;
        case 2:
            func_8009ADF0(player, 13, 1);
            break;
        case 3:
            func_8009ADF0(player, 13, 1);
            func_80800128_bashoes(player, 0x10, 2, old_mode);
            break;
        case 4:
            func_8009ADF0(player, 13, 1);
            func_80800128_bashoes(player, 0x37, 3, old_mode);
            break;
        case 5:
            func_8009ADF0(player, 13, 1);
            func_80800128_bashoes(player, 0x38, 4, old_mode);
    }
    callback = (*(ShoeState40 **) ((u8 *) player + 0x10C))->on_mode_change;
    if (callback)
        callback(player, old_mode, new_mode);
}

void bashoes_entrypoint_7(s32 player, s32 callback)
{
    *(s32 *) (*(s32 *) (player + 0x10C) + 0x8) = callback;
}

int bashoes_entrypoint_8(s32 player, s32 callback)
{
    // Matching: the temporary offset and the ^ 0 are needed for the match.
    unsigned short offset;
    *(s32 *) (*(s32 *) (player + 0x10C) + (offset = (0xC ^ 0) ^ 0)) = callback;
}

s32 bashoes_entrypoint_9(u8 *player)
{
    return (*(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x10C) + 0x14) > 0.0f) ? 1 : 0;
}

void bashoes_entrypoint_10(s32 player, f32 value)
{
    *(f32 *) (*(s32 *) (player + 0x10C) + 0x14) = value;
}

void bashoes_entrypoint_11(player, value)
{
    *(u8 *) ((char *) *(u32 *) ((char *) player + 0x10C) + 0x10) = value;
}

void bashoes_entrypoint_12(void *player, float duration)
{
    *(float *) *(void **) ((char *) player + 0x10C) = duration;
}

void bashoes_entrypoint_13(PlayerState *player)
{
    void (*update_callback)(PlayerState *, u8);
    update_callback = ((Mass44Shoes *) *(void **) ((u8 *) player + 0x10C))->update_callback;
    if (update_callback)
        update_callback(player, ((Mass44Shoes *) *(void **) ((u8 *) player + 0x10C))->mode);
    switch (((Mass44Shoes *) *(void **) ((u8 *) player + 0x10C))->mode) {
        case 1:
            break;
        case 2:
            if (baflag_isTrue(player, 0x10)) {
                bashoes_entrypoint_6(player, 3);
                return;
            }
            if (baflag_isTrue(player, 0x37)) {
                bashoes_entrypoint_6(player, 4);
                return;
            }
            if (baflag_isTrue(player, 0x38)) {
                bashoes_entrypoint_6(player, 5);
                return;
            }
            break;
        case 3:
            func_80800180_bashoes(player, 0x10);
            if (baflag_isTrue(player, 0x37)) {
                bashoes_entrypoint_6(player, 4);
                return;
            }
            if (baflag_isTrue(player, 0x38)) {
                bashoes_entrypoint_6(player, 5);
                return;
            }
            break;
        case 4:
            func_800D9078(&((Mass44Shoes *) *(void **) ((u8 *) player + 0x10C))->unk_14);
            func_80800180_bashoes(player, 0x37);
            if (baflag_isTrue(player, 0x10)) {
                bashoes_entrypoint_6(player, 3);
                return;
            }
            if (baflag_isTrue(player, 0x38)) {
                bashoes_entrypoint_6(player, 5);
                return;
            }
            break;
        case 5:
            func_80800180_bashoes(player, 0x38);
            if (baflag_isTrue(player, 0x10)) {
                bashoes_entrypoint_6(player, 3);
                return;
            }
            if (baflag_isTrue(player, 0x37))
                bashoes_entrypoint_6(player, 4);
    }
}

void bashoes_entrypoint_14(s32 player)
{
    s32 unk_0;
    s32 unk_1;

    unk_0 = func_8009E69C(player, 0x80);
    unk_1 = func_800F6B34();
    if ((unk_0 == 0) && (unk_1 == 0)) {
        bashoes_entrypoint_6(player, 1);
    }
}

void bashoes_entrypoint_15(u8 *player)
{
    if ((func_8009E6C4(player, 0x80) == 0) &&
        (*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x10C) + 8) = 0,
         *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x10C) + 0xC) = 0,
         (bashoes_entrypoint_1(player) == 1))) {
        if (baflag_isTrue(player, 0x10) != 0) {
            bashoes_entrypoint_6(player, 3);
            return;
        }
        if (baflag_isTrue(player, 0x37) != 0) {
            bashoes_entrypoint_6(player, 4);
            return;
        }
        if (baflag_isTrue(player, 0x38) != 0) {
            bashoes_entrypoint_6(player, 5);
            return;
        }
        bashoes_entrypoint_6(player, 2);
    }
}

void bashoes_entrypoint_16(s32 player)
{
    f32 pos[3];
    s32 particle;

    particle = func_800B53A4(6);
    func_8009C128(player, pos);
    func_800BABB8(particle, pos, pos, 1.0f, &D_80800AD0_bashoes);
}

void bashoes_entrypoint_17(s32 player)
{
    f32 pos[3];
    s32 particle;

    particle = func_800B53A4(0x1E);
    func_8009C128(player, pos);
    func_800BABB8(particle, pos, pos, 1.0f, &D_80800B4C_bashoes);
}

void bashoes_entrypoint_18(PlayerState *player)
{
    f32 pos[3];
    s32 particle;

    particle = func_800B53A4(0xA);
    func_80092E08(player, pos);
    pos[1] -= 30.0f;
    func_800BABB8(particle, pos, pos, 1.0f, D_80800B90_bashoes);
}

void bashoes_entrypoint_19(PlayerState *player)
{
    f32 pos[3];
    s32 particle;

    particle = func_800B53A4(0xA);
    func_80092E2C(player, pos);
    pos[1] -= 30.0f;
    func_800BABB8(particle, pos, pos, 1.0f, D_80800B90_bashoes);
}

void bashoes_entrypoint_20(PlayerState *player)
{
    f32 offset[3];
    f32 pos[3];
    f32 unk_0;
    f32 distance;

    func_8009C128(player, pos);
    distance = func_800F10B4(func_8009BB5C(player), 0.0f, 1000.0f, 10.0f, 50.0f);
    unk_0 = func_80090010();
    func_800EFCD8(offset, unk_0, distance);
    offset[1] = 0.0f;
    pos[0] += offset[0];
    pos[1] += offset[1];
    pos[2] += offset[2];
    pos[1] += 6.0f;
    func_800BBCB8(pos, 0, 1.0f, 1, &D_80800BD4_bashoes);
}

// TU-NOTE: the .data of this overlay is defined here in C, values taken from the ROM.
// D_80800AD0, D_80800B4C and D_80800BD4 are declared as s32[] to match the object.
s32 D_80800AD0_bashoes[31] = {
    0x1D09DF, 0x28020016, 0x2200015, 0x19001C, 0xE0014,  0x140022,  0x590066,    0x260026,
    0x270190, 0x1900320,  0x320002B, 0x330040, 0x1BFF38, 0xC8011A,  0x5002000E,  0x180018,
    0x2B004C, 0x4C0022,   0x40004C,  0x140014, 0x1B00C8, 0x190021A, -0x4BFDFFF2, 0x200020,
    0x2B0066, 0x660022,   0x260026,  0xA000A,  0x1B0190, 0x3E8031A, 0x0};
s32 D_80800B4C_bashoes[17] = {0x1D09DF,  -0x37FDFFEA, 0x2200015,  0x190033, 0x2EFFD3, 0x1E0,
                              -0x13FE99, 0x244001B,   -0x3E703E8, 0x22004C, 0x59000C, 0x170027,
                              0x1900190, 0x3200320,   0x2B0073,   0x8C1E1A, 0x0};
s32 D_80800B90_bashoes[17] = {0x1D09DF,  -0x37FDFFEA, 0x2200015,  0x19001C, 0x2EFFE2, 0x12C,
                              -0x1DFE99, 0x12C001B,   -0x1F301F4, 0x220040, 0x40000C, 0xC0027,
                              0x1900190, 0x3200320,   0x2B005E,   0x5E0A1A, 0x0};
s32 D_80800BD4_bashoes[19] = {0x1D09DE,  0x150019, 0x1C000A,   -0xC0000, -0xBFFF4,
                              0x2000C,   0x1BFE70, -0x31FFFDE, 0x4C0059, 0x190019,
                              0x2CFFEC,  0x32FFEC, 0x1400FA,   0x140027, 0x1900190,
                              0x3200320, 0x2B0066, 0x800000,   0x0};
