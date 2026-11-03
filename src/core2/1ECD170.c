#include "core2/1ECD170.h"

extern f32 bastick_distance(s32);
extern f32 func_8009BFCC(s32);
extern f32 yaw_get(s32);
extern f32 baroll_get(s32);
extern f32 func_800964DC(s32);
extern f32 func_80096364(s32);
extern s32 func_8009E674();
extern s32 func_8008E124();
extern s32 func_8008E974();
extern s32 func_800F8004();
extern s32 func_8008DAA8();
extern s32 func_800F54E4(void);
extern s32 func_800F5410(s32);
extern s32 func_800F6D24(s32);
typedef struct {
    s32 cached_size;
    s32 (*size_fn)(void);
} SizeF;
extern SizeF D_801235D0[];
extern void func_8009C128();
extern void func_800EFB24();
extern void func_8009C1F8();
extern void func_80099544(void *);
extern void *defrag(void *);
s32 func_800F3ED0();
s32 func_800F40EC();
void func_800F44DC();

// PlayerState lifecycle and queries. PlayerState is one heap block: a 0x19C-byte header
// followed by 0x56 subsystem sub-blocks. Header: +0x17C active flag, +0x180 second flag,
// +0x184 character index.
void func_800F3880(s32 block)
{
    func_80098E64();
    heap_free(block);
}

// class_mask bits: 4 and 2 match the airborne/swimming class (2 and 1), 1 matches movement mode 10.
int func_800F38A8(s32 player, s32 class_mask)
{
    return (((class_mask & 4) != 0) && func_800F40EC(player) == 2) ||
           (((class_mask & 2) != 0) && func_800F40EC(player) == 1) ||
           (((class_mask & 1) != 0) && func_800F3ED0(player) == 10);
}

s32 func_800F3930(player, allowed_transform, class_mask)
u8 *player;
s32 allowed_transform;
s32 class_mask;
{
    s32 class_match;

    class_match = func_800F38A8(player, class_mask);

if (func_800F9184() != 0) {
    return 0;
}

if (func_800F6774(*(s32 *) ((s8 *) player + 0x184)) == 0) {
    return 0;
}

if (func_800F6CC8(*(s32 *) ((s8 *) player + 0x184)) != 0) {
    return 0;
}

if (func_8008EF3C(player, 0) == 0x13) {
    return 0;
}

if ((player_isStable(player) == 0) && (class_match == 0)) {
    return 0;
}

if (func_800F64A4(*(s32 *) ((s8 *) player + 0x184), 0x12000) != 0) {
    return 0;
}

if (func_800F64A4(*(s32 *) ((s8 *) player + 0x184), allowed_transform) == 0) {
    return 0;
}

if (baflag_isTrue(player, 0x3F) != 0) {
    return 0;
}

if (func_8009CA70(player, bs_getCurrentState(player), 0x20) != 0) {
    return 0;
}

if (func_800A9C98() != 0) {
    return 0;
}

return 1;
}

int func_800F3A78(s32 player, s32 allowed_transform, f32 param_2[3])
{
    s32 class_match;

if (func_800F3930(player, allowed_transform) == 0) {
    return 0;
}

if (func_8009E674(player, 0x8000) != 0) {
    return 0;
}

class_match = func_800F38A8(player, param_2);

if (bastick_distance(player) != 0.0f) {
    if (class_match == 0) {
        return 0;
    }
}

if (func_800F5FA8(*(s32 **) (player + 0x184)) == 0) {
    return 0;
}

if (func_800A9C98() != 0) {
    return 0;
}

return 1;
}

f32 func_800F3B3C(s32 player, s32 param_1, s32 index)
{
    s32 values;

    func_8009E154(player, index, param_1);
    func_8008E9B8(player, &values);
    return (f32) ((s32 *) values)[index];
}

void func_800F3B90(s32 player, s32 param_1)
{
    func_800F3B3C(player, param_1, 0);
}

void func_800F3BB0()
{
    func_8009C128();

}

// Writes the position of the anchor point anchor_id; case 5 adds a per-transformation head height.
void func_800F3BD0(s32 player, s32 anchor_id, f32 *out_pos)
{
    switch (anchor_id) {
        case 1:
            func_80092D44(player, out_pos);
            break;
        case 2:
            func_80092E5C(player, out_pos);
            break;
        case 3:
            func_80092C00(player, out_pos);
            break;
        case 4:
            func_80092C24(player, out_pos);
            break;
        case 6:
            func_80092C48(player, out_pos);
            break;
        case 5:
            func_8009C128(player, out_pos);
            switch (func_800A3274(player)) {
                case 2:
                    out_pos[1] += 85.0f;
                    break;
                case 15:
                    out_pos[1] += 90.0f;
                    break;
                case 6:
                    out_pos[1] += 85.0f;
                    break;
                case 7:
                    out_pos[1] += 130.0f;
                    break;
                case 14:
                    out_pos[1] += 575.0f;
                    break;
                case 16:
                    out_pos[1] += 130.0f;
                    break;
                case 12:
                    out_pos[1] += 45.0f;
                    break;
                case 17:
                    out_pos[1] += 40.0f;
                    break;
                case 18:
                    out_pos[1] += 130.0f;
                    break;
                case 19:
                    out_pos[1] += 400.0f;
                    break;
                case 11:
                    out_pos[1] += 55.0f;
                    break;
                case 1:
                    if (func_800F40EC(player) == 2 ||
                        func_800F6720(*(s32 *) ((u8 *) player + 0x184)))
                        out_pos[1] += 70.0f;
                    else
                        out_pos[1] += 100.0f;
                    break;
                default:
                    out_pos[1] += 100.0f;
                    break;
            }
            break;
        case 7:
            func_80092DC0(player, out_pos);
            break;
        case 8:
            func_8009C188(player, out_pos);
            break;
        case 9:
            func_80092D9C(player, out_pos);
            break;
        case 0:
        default:
            func_800F3BB0(player, out_pos);
            break;
    }

}

// Reads the rotation as pitch, yaw, roll.
void func_800F3E84(s32 player, f32 *out_rot)
{
    out_rot[0] = func_8009BFCC(player);
    out_rot[1] = yaw_get(player);
    out_rot[2] = baroll_get(player);
}

// Movement-mode classification, 0..0x10, from bs state, flags and shoes.
s32 func_800F3ED0(player)
s32 player;
{
    s32 bs_state;
    s32 shoes;

    bs_state = bs_getCurrentState(player);

if (baflag_isTrue(player, 0x1B) != 0) {
    return 0xD;
}

if (baflag_isTrue(player, 0x17) != 0) {
    return 4;
}

if (func_8009CBDC(player, bs_state) == 9) {
    return 0xA;
}

if (func_8009CBDC(player, bs_state) == 0x12) {
    return 0xC;
}

if (func_8009CBDC(player, bs_state) == 0x13) {
    return 0xE;
}

if (func_8009CBDC(player, bs_state) == 8) {
    return 9;
}

if (func_8009CBDC(player, bs_state) == 0xA) {
    return 5;
}

if (baflag_isTrue(player, 9) != 0) {
    return 1;
}

if (func_8009E674(player, 0x80) != 0) {
    shoes = _bashoes_entrypoint_1(player);
    switch (shoes) {
        case 3:
            return 6;
        case 4:
            return 0x10;
        case 5:
            return 0xF;
    }
}
{
    switch (bs_state) {
        case 0xE:;
        case 0x34:
        case 0x3C:;
        case 0x3F:
        case 0x41:;
        case 0x44:
        case 0x120:
            return 1;
        case 0x1A:;
        case 0x1B:
        case 0x1C:;
        case 0x1D:
        case 0x1E:;
        case 0xA4:
        case 0xA5:
            return 3;
        case 0x8:;
        case 0x15:
        case 0x16:;
        case 0x17:
        case 0x45:
            if (bastatetimer_isActive(player, 3) != 0) {
                return 6;
            }
            return 8;
        case 0xB:
            return 2;
        default:
            if (func_8008EF3C(player, 0) != 0) {
                return 0xB;
            }
            return 0;
    }
}

}

// Airborne-or-swimming class: 0 none, 1 or 2.
s32 func_800F40EC(player)
s32 player;
{
    s32 state;
    f32 val1;
    f32 val2;
    state = bs_getCurrentState();

if (func_800A3274(player) != 0xC) {
    goto block_5;
}

if (func_80096544(player) == 0) {
    return 0;
}

val1 = func_800964DC(player);
val2 = func_80096364(player);

if ((val1 - val2) < 50.0f) {
    return 0;
}

goto block_5;

block_5
    : if ((func_8009CA70(player, state, 1) != 0) || (func_8009CA70(player, state, 0x40000) != 0))
{
    return 1;
}

if (state == 5) {
    if (_bsjump_entrypoint_16(player) != 0) {
        return 1;
    }
    return 0;
}

if (func_8009CA70(player, state, 2) != 0) {
    return 2;
}

return 0;
}

int func_800F4200(s32 player, s32 param_1)
{
    f32 pos[3];
    f32 unk_1[3];
    func_8009C128(player, pos);
    func_8009C1CC(player, unk_1);
    func_800EE780(param_1, pos, unk_1);
}

s32 func_800F4244(Actor *player)
{
    return (*(s32 *) ((s8 *) (player) + (0x17C)));
}

s32 func_800F424C(u8 *player)
{
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;

if (*(s32 *) ((s8 *) player + 0x17C) == 0) {
    return 0;
}

if (func_8009E674(player, 4) != 0) {
    return 0;
}

if (func_8009E674(player, 0x2000) != 0) {
    return 0;
}

if (func_8008E124(player) != 0) {
    return 0;
}

if (func_8008E974(player) == 0) {
    return 0;
}

if (func_800F8004(*(s32 *) ((s8 *) player + 0x184)) != 0) {
    return 0;
}

if (func_8008DAA8(player) == 0) {
    unk_0 = func_800F54E4();
    if (unk_0 != -1) {
        unk_1 = unk_0;
        unk_2 = func_800F5410(unk_0) == 0x11;
        unk_3 = func_800F6D24(unk_1);
        if ((unk_2 != 0) && (unk_3 != 0)) {
            return 0;
        }
    }
}

return 1;
}

// Size of sub-block index; computed lazily via the table and cached.
s32 func_800F4354(s32 index)
{
    if (D_801235D0[index].cached_size >= 0)
        return D_801235D0[index].cached_size;
    D_801235D0[index].cached_size = D_801235D0[index].size_fn();
}

// Allocates a PlayerState: header plus 4-aligned sub-blocks, with a pointer table at the start.
u8 *func_800F43A8(s32 character_index)
{
    s32 offset;
    u8 *block;
    unsigned int i;
    s32 size;
    s32 padding;

    offset = 0x19C;
    block = heap_alloc(0x19C);
    for (i = 0; i < 0x56; i++) {
        size = func_800F4354((s32) i);
        padding = size % 4;

if (padding != 0) {
    padding = 4 - padding;
} else {

padding = 0;
}
offset = offset + size + padding;
block = heap_realloc(block, offset);
}
bzero(block, offset);
offset = 0x19C;
for (i = 0; i < 0x56; i++) {
    *(u8 **) (block + (i << 2)) = block + offset;
    size = func_800F4354((s32) i);
    padding = size % 4;
    if (padding != 0) {
        padding = 4 - padding;
    } else {
        padding = 0;
    }
    offset = offset + size + padding;
}
((s32 *) block)[0x60] = 0;
((s32 *) block)[0x61] = character_index;
func_80098C48(block);
func_800F44DC(block, 1);
return block;
}

void func_800F44DC(player, active) s32 player;
s32 active;
{
    s32 unk_0;
    s32 unk_1;
    *(s32 *) (player + 0x17c) = active;
    unk_1 = func_800A4C88(player);
    if (active != 0) {
        unk_0 = 2;
    } else {
        unk_0 = 1;
    }
    func_8010F9C0(unk_1, unk_0);
}

void func_800F4524(s32 player, s32 value)
{
    s32 *flag;
    flag = (s32 *) (player + 0x17C);
    flag++;
    *flag = value;
}

int func_800F452C(s32 player)
{
    s32 player_alias;
    // Matching: the "| 0" copy is needed for the match.
    player_alias = player | 0;
    func_8009C0BC(player_alias);
    func_80095C94(player_alias);
    func_800A10A0(player_alias);
    func_800A4030(player_alias);
    func_800A4B08(player_alias);
    func_800A380C(player_alias);
}

int func_800F457C(s32 player, s32 param_1)
{
    if (!param_1) {
        func_8009CCA4(player);
    } else {
        func_8009CCFC(player);
    }
}

s32 func_800F45B0(Actor *this, Gfx **dl, Mtx **m)
{
    func_8009CCFC(this, dl, m);
    func_8009CD70(this, m);
}

void func_800F45E0(s32 player, s32 *rot)
{
    func_8009BF5C(player, rot[0]);
    yaw_setIdeal(player, rot[1]);
    baroll_setIdeal(player, rot[2]);
    func_8009BFBC(player);
    yaw_applyIdeal(player);
    baroll_applyIdeal(player);
}

s32 func_800F4648(s32 player, s32 param_1)
{
    f32 pos[3];
    f32 unk_1[3];

    func_8009C128(player, pos);
    func_800EFB24(unk_1, param_1, pos);
    func_8009C1F8(player, unk_1);
}

s32 func_800F468C(Actor *this)
{
    if (*(s32 *) ((char *) this + 0x17C) != 0 && *(s32 *) ((char *) this + 0x180) == 0 &&
        func_800EA09C() == 2) {
        func_800991B0(this);
    }
}

// Defrags the block and fixes up the sub-block pointers if it moved.
u8 *func_800F46D8(u8 *block)
{
    u8 unk_0[8];
    u8 *old_block;
    s32 delta;
    int i;
    func_80099544(block);
    old_block = block;
    block = defrag(block);
    if (old_block == block)
        return block;
    delta = block - old_block;
    for (i = 0; i < 0x56; i++) {
        *(u8 **) ((u32) block + (i << 2)) += delta;
    }
    return block;
}

// TU-NOTE: the data below (formerly asm/data/core2/1ECD170.data.s) is defined in C. The tables point
// to functions of this file; IDO's assembler schedules some of them differently unless the tables
// are in the same unit. Values are taken from the ROM.
extern void _baalarm_get_size();
extern void baanim_get_size();
extern void _baattach_entrypoint_0();
extern void func_8008E4B0();
extern void _bababykaz_entrypoint_0();
extern void _babackpack_get_size();
extern void func_8008ED80();
extern void _babee_entrypoint_0();
extern void func_800908A0();
extern void _baboost_entrypoint_0();
extern void _babounce_entrypoint_0();
extern void func_80090B90();
extern void func_80090E40();
extern void _babuzz_entrypoint_0();
extern void func_800A3B70();
extern void bastatetimerList_getSize();
extern void bakey_getStructSize();
extern void _bacough_entrypoint_0();
extern void func_80091E10();
extern void func_80091EA0();
extern void func_80092010();
extern void _badrone_entrypoint_0();
extern void _baduo_entrypoint_0();
extern void _badust_entrypoint_0();
extern void _baeggaim_entrypoint_0();
extern void func_80094340();
extern void _baeggcursor_entrypoint_0();
extern void _baeggfire_entrypoint_0();
extern void _baeggsetup_entrypoint_0();
extern void func_80094E70();
extern void func_80094F80();
extern void func_80095380();
extern void baflag_getStuctSize();
extern void _baflameline_entrypoint_0();
extern void _baflamethrower_entrypoint_0();
extern void _bafly_entrypoint_0();
extern void _bafpctrl_entrypoint_0();
extern void func_80095790();
extern void func_800967C0();
extern void _bahold_entrypoint_0();
extern void func_800A3040();
extern void bainput_getStructSize();
extern void _bainvisible_entrypoint_0();
extern void func_80098210();
extern void _bakaztorpedo_entrypoint_0();
extern void func_800A21C0();
extern void func_80098BA0();
extern void func_80098890();
extern void func_800995B0();
extern void func_8009AD70();
extern void func_8009AE00();
extern void _bamoveledge_entrypoint_0();
extern void _bamum_entrypoint_0();
extern void func_8009BD30();
extern void _bapackctrl_entrypoint_0();
extern void func_8009BE20();
extern void func_80098530();
extern void func_8009C030();
extern void _bapulse_entrypoint_0();
extern void _bareact_entrypoint_0();
extern void func_8009CC10();
extern void baroll_getStructSize();
extern void yaw_size();
extern void func_8009CF90();
extern void _basetup_entrypoint_0();
extern void func_8009D3D0();
extern void func_800A1960();
extern void _bashoes_entrypoint_0();
extern void _basnowball_entrypoint_0();
extern void func_8009E130();
extern void _baspin_entrypoint_0();
extern void _basquash_entrypoint_0();
extern void func_8009E5C0();
extern void func_800A26B0();
extern void bastick_getStructSize();
extern void func_8009F300();
extern void _basub_entrypoint_0();
extern void _baswim_entrypoint_0();
extern void func_800A06E0();
extern void _batimer_get_size();
extern void _batranslate_entrypoint_0();
extern void _bavan_entrypoint_0();
extern void _bawandglow_entrypoint_0();
extern void _bawasher_entrypoint_0();
extern void func_800A0E50();
extern void _bawobble_entrypoint_0();
SizeF D_801235D0[86] = {-0x1, (void *) _baalarm_get_size,
                        -0x1, (void *) baanim_get_size,
                        -0x1, (void *) _baattach_entrypoint_0,
                        -0x1, (void *) func_8008E4B0,
                        -0x1, (void *) _bababykaz_entrypoint_0,
                        -0x1, (void *) _babackpack_get_size,
                        -0x1, (void *) func_8008ED80,
                        -0x1, (void *) _babee_entrypoint_0,
                        -0x1, (void *) func_800908A0,
                        -0x1, (void *) _baboost_entrypoint_0,
                        -0x1, (void *) _babounce_entrypoint_0,
                        -0x1, (void *) func_80090B90,
                        -0x1, (void *) func_80090E40,
                        -0x1, (void *) _babuzz_entrypoint_0,
                        -0x1, (void *) func_800A3B70,
                        -0x1, (void *) bastatetimerList_getSize,
                        -0x1, (void *) bakey_getStructSize,
                        -0x1, (void *) _bacough_entrypoint_0,
                        -0x1, (void *) func_80091E10,
                        -0x1, (void *) func_80091EA0,
                        -0x1, (void *) func_80092010,
                        -0x1, (void *) _badrone_entrypoint_0,
                        -0x1, (void *) _baduo_entrypoint_0,
                        -0x1, (void *) _badust_entrypoint_0,
                        -0x1, (void *) _baeggaim_entrypoint_0,
                        -0x1, (void *) func_80094340,
                        -0x1, (void *) _baeggcursor_entrypoint_0,
                        -0x1, (void *) _baeggfire_entrypoint_0,
                        -0x1, (void *) _baeggsetup_entrypoint_0,
                        -0x1, (void *) func_80094E70,
                        -0x1, (void *) func_80094F80,
                        -0x1, (void *) func_80095380,
                        -0x1, (void *) baflag_getStuctSize,
                        -0x1, (void *) _baflameline_entrypoint_0,
                        -0x1, (void *) _baflamethrower_entrypoint_0,
                        -0x1, (void *) _bafly_entrypoint_0,
                        -0x1, (void *) _bafpctrl_entrypoint_0,
                        -0x1, (void *) func_80095790,
                        -0x1, (void *) func_800967C0,
                        -0x1, (void *) _bahold_entrypoint_0,
                        -0x1, (void *) func_800A3040,
                        -0x1, (void *) bainput_getStructSize,
                        -0x1, (void *) _bainvisible_entrypoint_0,
                        -0x1, (void *) func_80098210,
                        -0x1, (void *) _bakaztorpedo_entrypoint_0,
                        -0x1, (void *) func_800A21C0,
                        -0x1, (void *) func_80098BA0,
                        -0x1, (void *) func_80098890,
                        -0x1, (void *) func_800995B0,
                        -0x1, (void *) func_8009AD70,
                        -0x1, (void *) func_8009AE00,
                        -0x1, (void *) _bamoveledge_entrypoint_0,
                        -0x1, (void *) _bamum_entrypoint_0,
                        -0x1, (void *) func_8009BD30,
                        -0x1, (void *) _bapackctrl_entrypoint_0,
                        -0x1, (void *) func_8009BE20,
                        -0x1, (void *) func_80098530,
                        -0x1, (void *) func_8009C030,
                        -0x1, (void *) _bapulse_entrypoint_0,
                        -0x1, (void *) _bareact_entrypoint_0,
                        -0x1, (void *) func_8009CC10,
                        -0x1, (void *) baroll_getStructSize,
                        -0x1, (void *) yaw_size,
                        -0x1, (void *) func_8009CF90,
                        -0x1, (void *) _basetup_entrypoint_0,
                        -0x1, (void *) func_8009D3D0,
                        -0x1, (void *) func_800A1960,
                        -0x1, (void *) _bashoes_entrypoint_0,
                        -0x1, (void *) _basnowball_entrypoint_0,
                        -0x1, (void *) func_8009E130,
                        -0x1, (void *) _baspin_entrypoint_0,
                        -0x1, (void *) _basquash_entrypoint_0,
                        -0x1, (void *) func_8009E5C0,
                        -0x1, (void *) func_800A26B0,
                        -0x1, (void *) bastick_getStructSize,
                        -0x1, (void *) func_8009F300,
                        -0x1, (void *) _basub_entrypoint_0,
                        -0x1, (void *) _baswim_entrypoint_0,
                        -0x1, (void *) func_800A06E0,
                        -0x1, (void *) _batimer_get_size,
                        -0x1, (void *) _batranslate_entrypoint_0,
                        -0x1, (void *) _bavan_entrypoint_0,
                        -0x1, (void *) _bawandglow_entrypoint_0,
                        -0x1, (void *) _bawasher_entrypoint_0,
                        -0x1, (void *) func_800A0E50,
                        -0x1, (void *) _bawobble_entrypoint_0};
