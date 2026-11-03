#include "common.h"
#include "overlays/ba/playerstate.h"

extern s16 D_80117EC0[];
extern void func_800BED18(void *, void *);
extern s32 func_800EA05C(void);
extern void func_800EE84C(void *, void *);
struct Unknown {
    s16 map_id;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    s16 unk_A;
    s16 unk_C;
};
typedef struct {
    f32 first[3], second[3];
    u8 active, disabled;
} LocalBounds;
typedef struct {
    u8 pad_0[0xBC];
    LocalBounds *bounds;
    u8 pad_C0[0xC4];
    s32 index;
} LocalPlayer;
extern f32 bastatetimer_get(PlayerState *, s32);
extern void func_8009EB0C(f32);
extern void func_8009E9FC(f32);

// Size of the world-bounds component.
s32 func_80098890()
{
    return 0x1C;
}

// Loads the per-map world bounds, adjusted by the D_80117EC0 table.
void func_80098898(u8 *player)
{
    f32 corner_a[3];
    f32 corner_b[3];
    s32 map_id;
    struct Unknown *adjust;

    map_id = func_800EA05C();
    func_800BED18(corner_b, corner_a);
    func_800EE84C(*(u8 **) (player + 0xBC) + 0xC, corner_b);
    func_800EE84C(*(u8 **) (player + 0xBC), corner_a);

    adjust = (struct Unknown *) D_80117EC0;
    while (adjust->map_id != 0 && map_id != adjust->map_id)
        adjust++;

    *(f32 *) (*(u8 **) (player + 0xBC) + 12) -= adjust->unk_2;

    *(f32 *) (*(u8 **) (player + 0xBC) + 16) -= adjust->unk_4;

    *(f32 *) (*(u8 **) (player + 0xBC) + 20) -= adjust->unk_6;

    *(f32 *) *(u8 **) (player + 0xBC) += adjust->unk_8;

    *(f32 *) (*(u8 **) (player + 0xBC) + 4) += adjust->unk_A;

    *(f32 *) (*(u8 **) (player + 0xBC) + 8) += adjust->unk_C;

    *(s8 *) (*(u8 **) (player + 0xBC) + 0x18) = 0;
    *(s8 *) (*(u8 **) (player + 0xBC) + 0x19) = 0;
}

// Handles the player leaving the world bounds.
void func_800989E4(LocalPlayer *player)
{
    f32 pos[3];
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    if (!func_8008DAA8() || player->bounds->disabled)
        return;
    unk_0 = func_800BF6B8();
    if (unk_0 == 1)
        return;
    func_8009C128(player, pos);
    if (unk_0 == 2 || !func_800EFED0(player->bounds->second, player->bounds->first, pos)) {
        if (!player->bounds->active) {
            player->bounds->active = 1;
            if (func_800D3948() || func_800D395C()) {
                _gcfrontend_entrypoint_12();
                return;
            }
            unk_1 = 0;
            unk_2 = 0;
            switch (func_800A3274(player)) {
                case 0x11:
                    unk_1 = 1;
                    break;
                case 0xB:
                    if (func_800F8B88() == 3)
                        unk_2 = 1;
                    break;
            }
            if (unk_1) {
                func_800F7B9C(player->index, 0x1F);
                return;
            }
            if (unk_2) {
                func_800F7B9C(player->index, 0x88);
                return;
            }
            func_800A05DC(player);
        } else
            baphysics_set_type(player, 7);
    }
}

// Enables or disables the bounds check.
int func_80098B4C(s32 player[3], s32 enabled)
{
    s32 *ptr = player;
    s32 disabled = !enabled;
    *(u8 *) ((char *) ptr[0x2F] + 25) = (u8) disabled;
}

int func_80098B5C(s32 player[3], s32 unk_0, s32 unk_1)
{
    func_800EE7F8(unk_0 | 0, player[0x2F] + 0xC);
    func_800EE7F8(unk_1, player[0x2F]);
}

// Size of the lifecycle component.
s32 func_80098BA0()
{
    return 0xC;
}

int func_80098BA8(s32 player, s32 unk_0)
{
    if (func_80091E80(player, 1)) {
        func_80092444(player, unk_0);
    }
}

void func_80098BE0(s32 player)
{
    if (func_800A9420(*(s32 *) (player + 0x184))) {
        if (func_8009AD78(player, 8) != 0) {
            _baeggcursor_entrypoint_1(player);
        }
        if (func_8009AD78(player, 0xB) != 0) {
            _bsfirstp_entrypoint_37(player);
        }
    }
}

// Initializes all player subsystems.
void func_80098C48(u8 *player)
{
    *(s8 *) ((s8 *) *(s32 **) ((s8 *) player + 0xB8) + 8) = 1;
    func_8009AD90();
    _badronemem_entrypoint_3(player);
    _bastatemem_entrypoint_3(player);
    func_800A3820(player);
    **(s32 **) ((s8 *) player + 0xB8) = 0;
    bakey_init(player);
    func_8009FE78(player);
    func_8009C038(player);
    _badrone_entrypoint_32(player);
    _badust_entrypoint_11(player);
    func_800955CC(player);
    baflag_clearAll(player);
    func_800A0FF0(player);
    bastick_reset(player);
    bainput_init(player);
    _bainvisible_entrypoint_3(player);
    func_80098408(player);
    func_8009CBFC(player);
    func_8009E7AC(player);
    func_800A16F4(player);
    func_80091E20(player);
    func_80094644(player);
    _baeggcursor_entrypoint_5(player);
    _bafpctrl_entrypoint_8(player);
    _bapackctrl_entrypoint_3(player);
    _bababykaz_entrypoint_2(player);
    func_800A4168(player);
    _bacough_entrypoint_3(player);
    func_80091EC8(player);
    _badeathmatch_entrypoint_1(player);
    _baduo_entrypoint_6(player);
    _baattach_entrypoint_4(player);
    func_80098898(player);
    func_8009AC6C(player);
    func_8009B4FC(player);
    func_8009BD50(player);
    func_8009BF04(player);
    func_80098538(player);
    func_8009CC90(player);
    baroll_reset(player);
    func_8009CF98(player);
    func_80094F38(player);
    func_800A0C44(player);
    func_80095068(player);
    func_80090938(player);
    func_8009105C(player);
    bastatetimerlist_init(player);
    _bahold_entrypoint_1(player);
    func_80095AD0(player);
    _bamum_entrypoint_2(player);
    baanim_init(player);
    func_800A21C8(player);
    func_80092898(player);
    func_8008E618(player);
    _basetup_entrypoint_4(player);
    func_8009D4D8(player);
    func_800A1F78(player);
    _bashoes_entrypoint_4(player);
    func_8009E390(player);
    _basquash_entrypoint_2(player);
    func_800A2D94(player);
    _batranslate_entrypoint_2(player);
}

// Saves persistent player state and frees all player subsystems.
void func_80098E64(PlayerState *player)
{
    s32 state;
    s32 unk_0;
    f32 timer;
    s32 unk_1;
    if (func_800A3274(player) == 0xE) {
        if (baflag_isTrue(player, 0x40)) {
            func_800A3410(player, 0xD);
            func_800F8EBC(player->unk184);
        }
    }
    state = bs_getCurrentState(player);
    unk_0 = func_8009CBDC(player, state);
    if (func_8008DAA8(player)) {
        func_8009E880();
        if (func_800A81C4() || func_800EA068(0x800))
            _bashoes_entrypoint_6(player, 1);
        timer = 0.0f;
        unk_1 = 0;
        if (func_8008E39C(player)) {
            timer = bastatetimer_get(player, 3);
            unk_1 = 1;
        } else if (func_8009E674(player, 0x40)) {
            unk_1 = 1;
        }
        if (unk_1)
            func_8009EAD0(2);
        func_8009EB0C(timer);
        func_8009EAF4(_bashoes_entrypoint_1(player));
        func_8009E9D8(func_800A3274(player));
        func_8009E9FC(0.0f);
        switch (unk_0) {
            case 8:
                func_8009E9FC(bastatetimer_get(player, 2));
                break;
            case 9:
                if (func_800A3274(player) == 6)
                    func_8009EAD0(4);
                break;
            case 18:
                func_8009EAD0(3);
                break;
            case 19:
                func_8009EAD0(6);
                break;
            case 20:
                func_8009EAD0(7);
                break;
        }
    }
    {
        s32 flag;
        flag = func_8009E71C(player, 5) ? 1 : 0;
        flag &= func_800EA068(8) ? 1 : 0;
        func_8009EB18(flag);
    }
    bs_setState(player, 0x5A);

    _baattach_entrypoint_3(player);
    func_8008E6BC(player);
    func_80091054(player);
    _bababykaz_entrypoint_1(player);
    bastatetimerlist_free(player);
    _baeggcursor_entrypoint_4(player);
    func_80094538(player);
    func_80092A1C(player);
    func_800A22A8(player);
    baanim_free(player);
    func_80095C10(player);
    _bahold_entrypoint_2(player);
    _bamum_entrypoint_1(player);
    _basetup_entrypoint_3(player);
    func_8009D5E0(player);
    func_800A2058(player);
    _bashoes_entrypoint_3(player);
    _basquash_entrypoint_1(player);
    func_800A2D70(player);
    _batranslate_entrypoint_1(player);
    _bastatemem_entrypoint_2(player);
    _badronemem_entrypoint_2(player);
    _bapackctrl_entrypoint_2(player);
    _baduo_entrypoint_5(player);
    func_8009E388(player);
    _bafpctrl_entrypoint_7(player);
    func_80091E18(player);
    bakey_free(player);
    _bacough_entrypoint_2(player);
    _badeathmatch_entrypoint_2(player);
    func_80091EA8(player);
    _bainvisible_entrypoint_4(player);
    func_8009AD88(player);
    func_800A4160(player);

    (*(u8 **) ((u8 *) player + 0xB8))[8] = 0;
}

// Sets the deferred callback and its argument.
int func_8009919C(u8 *player, s32 callback, s32 arg)
{
    *(s32 *) *(u32 *) (player + 0xb8) = callback;
    *((s32 *) *(u32 *) (player + 0xb8) + 1) = arg;
}

// Per-frame update of all player subsystems.
void func_800991B0(u8 *player)
{
    s32 unk_0;
    s32 unk_1;
    s32 (*callback)(s32);
    u8 *lifecycle;
    unk_0 = func_800EA068(8) == 0;
    unk_1 = func_800DA298(0x6B5);
    if (func_80091E80(player, 0x20) != 0) {
        func_80092AB0(player);
        func_80099970(player);
        func_8009CF04(player);
        bastatetimerlist_update(player);
        func_800A0DDC(player);
        bakey_update(player);
        bastick_update(player);
        bainput_update(player);
        if (func_8009AD78(player, 2) != 0) {
            _baduo_entrypoint_13(player);
        }
        func_8009E83C(player);
        if ((func_80091E80(player, 2) != 0) && (func_8008E454(player) != 0)) {
            func_8009B590(player);
        }
        if (func_8009AD78(player, 6) != 0) {
            _batranslate_entrypoint_4(player);
        }
        func_8009C25C(player);
        if (unk_0 != 0) {
            func_8009561C(player);
        }
        func_80095C94(player);
        if (func_80091E80(player, 2) != 0) {
            func_8009BF34(player);
            baroll_update(player);
            func_8009D088(player);
        }
        if (unk_1 != 0) {
            func_80091110(player);
        }
        if (func_80091E80(player, 0x10) != 0) {
            baanim_update(player);
        }
        func_800A2060(player);
        if (unk_0 != 0) {
            func_800987CC(player);
        }
        if (func_8009AD78(player, 4) != 0) {
            func_80090A4C(player);
        }
        if (unk_0 != 0) {
            func_800951F4(player);
        }
        if (func_8009AD78(player, 3) != 0) {
            _badust_entrypoint_13(player);
        }
        func_8009C08C(player);
        func_8008E6F0(player);
        if (func_8009AD78(player, 0xE) != 0) {
            _bahold_entrypoint_3(player);
        }
        func_800A10A0(player);
        func_8009BDE4(player);
        func_800A3A80(player);
        func_800A4B08(player);
        if (*(s32 *) ((s8 *) player + 0x158) == 0) {
            func_80094864(player);
        } else {
            _badeathmatch_entrypoint_3(player);
        }
        if (func_8009AD78(player, 9) != 0) {
            _bacough_entrypoint_5(player);
        }
        if (func_8009AD78(player, 8) != 0) {
            _baeggcursor_entrypoint_11(player);
        }
        if (func_8009AD78(player, 0xC) != 0) {
            _bainvisible_entrypoint_6(player);
        }
        if (func_8009AD78(player, 5) != 0) {
            _bamum_entrypoint_3(player);
        }
        if (func_8009AD78(player, 7) != 0) {
            _bafpctrl_entrypoint_15(player);
        }
        if (func_8009AD78(player, 0xA) != 0) {
            _basquash_entrypoint_4(player);
        }
        if (func_8009AD78(player, 0xD) != 0) {
            _bashoes_entrypoint_13(player);
        }
        func_80093448(player);
        func_800A2534(player);
        if (((func_800D3E40(4) != 0) && (func_8008DAA8(player) != 0)) &&
            (func_8008E124(player) == 0)) {
            func_800A18E8(player);
        }
        func_80091F30(player);
        // Matching: goto to the next label is needed for the match.
        goto dummy_label_665677;
    dummy_label_665677:;
        lifecycle = *(u8 **) ((s8 *) player + 0xB8);
        callback = *(s32(**)(s32))((s8 *) lifecycle + 0);
        if (callback != 0) {
            callback(*(s32 *) ((s8 *) lifecycle + 4));
            *(s32(**)(s32))((s8 *) *(u8 **) ((s8 *) player + 0xB8) + 0) = 0;
        }
        func_800989E4(player);
    }
}

// Defragments the memory of the player subsystems.
void func_80099544(u8 *player)
{
    u8 *player_a;
    u8 *player_b;
    int offset;
    // Matching: extra temporaries are needed for the match.
    offset = 0xB8;
    player_a = player;
    if ((*(u8 **) (player + offset))[8]) {
        baanim_defrag();
        func_800934C4(player);
        func_80096728(player);
        func_800A300C(player_a);
        player_b = player;
        bakey_defrag(player_b);
        func_800A266C(player_b);
    }
}

// TU-NOTE: .data of this file is defined here in C, values taken from the ROM.
// D_80117EC0 is s16[]; map id followed by six bounds offsets, per entry.
s16 D_80117EC0[24] = {0x136,  0x5DC,  0x1F40, 0x5DC, 0x5DC, 0xBB8, 0x5DC, 0x155,
                      0x7D0,  0x1F40, 0x7D0,  0x7D0, 0x7D0, 0x7D0, 0x0,   0x1F4,
                      0x1F40, 0x1F4,  0x1F4,  0x3E8, 0x1F4, 0x0,   0x0,   0x0};
