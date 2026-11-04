// TU-NOTE: gc/sectionskip.h is not included as a whole: via gc/goto.h -> core2/1E80A70.h -> core2/1E99980.h
// it would declare func_800C05B8 with an s16 first parameter, but this file calls it without a prototype
// (a0 is passed on unnarrowed). The other headers of gc/sectionskip.h are included directly.
#include "common.h"
#include "core2/1EA9160.h"
#include "core2/1EAAD80.h"
#include "core2/1EB3750.h"
#include "core2/1EC3810.h"
#include "gc/sectionDll.h"
#include "ch/mrtannoy.h"
#include "gameflags.h"

extern f32 mlAbsF(f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_800D8FF8(void);
extern s32 func_800DC298(f32);
int func_80800D3C_gcsectionskip();

// Pushes pos out of the trigger volume (square or round, by shape).
int func_80800000_gcsectionskip(f32 *pos, f32 *center, f32 radius, s32 shape)
{
    f32 prev_pos[3];
    f32 dx;
    f32 scale;
    f32 local_3;
    f32 dz;
    f32 dist;
    f32 rel_x;
    f32 rel_z;
    func_800EE7F8(prev_pos, pos);
    if (!shape) {
        dx = (center[0] + radius) - pos[0];
        if (dx > radius) {
            dx -= radius + radius;
        }
        dz = (center[2] + radius) - pos[2];
        if (dz > radius) {
            dz -= radius + radius;
        }
        if (mlAbsF(dx) < mlAbsF(dz)) {
            pos[0] += dx;
        } else {
            pos[2] += dz;
        }
    } else {
        scale = (radius + radius) / sqrtf(2.0f);
        rel_x = pos[0] - center[0];
        rel_z = pos[2] - center[2];
        dist = mlAbsF(rel_x) + mlAbsF(rel_z);
        rel_x = (rel_x * scale) / dist;
        rel_z = (rel_z * scale) / dist;
        pos[0] = center[0] + rel_x;
        pos[2] = center[2] + rel_z;
    }
    if (func_800EECE0(prev_pos, pos)) {
        return 0;
    }
    return 1;
}

void func_8080019C_gcsectionskip(f32 *target, f32 *pos, f32 *center, f32 radius, f32 shape_f)
{
    f32 safe_pos[3];
    f32 test_pos[3];
    s32 shape;
    s32 step;
    f32 step_count;

    func_800EE7F8(safe_pos, pos);
    shape = shape_f;
    step = 0;
    step_count = 4.0f;
    do {
        // Matching: empty if (1) block needed for the match.
        if (1) {
        }
        func_800EFE50(test_pos, pos, target, (f32) step / step_count);
        if (!func_80800000_gcsectionskip(test_pos, center, radius, shape)) {
            break;
        }
        func_800EE7F8(safe_pos, test_pos);
        step++;
    } while (step != 4);
    func_800EE7F8(pos, safe_pos);
}

// Pushes the player back out of the trigger prop's volume.
void func_808002A0_gcsectionskip(s32 player, u8 *trigger)
{
    f32 center[3];
    f32 target[3];
    f32 velocity[3];
    f32 pos[3];
    s32 shape;
    f32 radius;

    if (trigger != NULL) {
        shape = (u32) trigger[0x13] >> 7;
        radius = (f32) ((u32) *(u16 *) (trigger + 6) >> 7);
        func_800F5D9C(player, pos);
        func_800F5D70(player, velocity);
        func_800EF334(velocity, func_800D8FF8());
        func_800EFB24(target, pos, velocity);
        func_800EE88C(center, trigger);
        func_8080019C_gcsectionskip(target, pos, center, radius, (f32) shape);
        func_800F8418(player, pos);
    }
}

s32 func_80800374_gcsectionskip(s32 player, s32 trigger)
{
    func_800F7E3C(player, 0);
    func_808002A0_gcsectionskip(player, trigger);
}

s32 gcsectionskip_entrypoint_0(s32 unk_0, s32 unk_1, s32 unk_2)
{
    if (unk_1 == 0xDAA) {
        func_800DA524(0x6C9);
    }
}

void func_80800EF8_gcsectionskip();

// Map exit handler: checks the exit's condition type and either warps or blocks the player.
s32 gcsectionskip_entrypoint_1(s32 prop, s32 map_id, s32 exit_id, s32 type, void *actor)
{
    extern u8 D_80801040_gcsectionskip[];
    extern u8 D_8012762C;

    s32 check_level;
    s32 player;
    s32 form;
    s32 cur_player;
    s32 cur_player2;
    s32 cur_level;
    s32 target_level;
    s32 same_level_form;

    check_level = 1;

    if (_gcgoto_entrypoint_15()) {
        return 0;
    }

    player = func_800F54E4();

    if (actor != 0 && player != ((u32) *(u16 *) ((char *) actor + 0x1A) >> 5)) {
        return 0;
    }

    form = func_800F5410(player);

    _gcgoto_entrypoint_0(&map_id, &exit_id);

    if (func_800F6D24(player) || func_800F8004(player) || func_800F6CC8(player) ||
        func_800F66F0(player) || func_800F70BC(func_800F54E4())) {
        func_808002A0_gcsectionskip(player, prop);
        return 0;
    }

    if (func_800F8B88() == 3 && form == 0xB) {
        func_800F7B9C(player, 0x88);
        return 0;
    }

    switch (type) {
        case 0:
            if (!func_800F4BE4(player)) {
                func_80800374_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 1:
            if (!_chchuffycont_entrypoint_0(&map_id, &exit_id)) {
                return 0;
            }
            break;

        case 2:
            if (!_chchuffycont_entrypoint_1(&map_id, &exit_id)) {
                return 0;
            }
            check_level = 0;
            break;

        case 3:
            if (!func_800DA298(0xB2)) {
                return 0;
            }
            break;

        case 4:
            if (form != 1) {
                func_80800374_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 29:
            if (form != 1) {
                func_808002A0_gcsectionskip(player, prop);
                func_800F7E3C(player, 0x1228);
                return 0;
            }
            break;

        case 5:
            if (form != 0xB) {
                func_80800374_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 6:
            if (form != 0xA) {
                func_80800374_gcsectionskip(player, prop);
                return 0;
            }
            check_level = 0;
            break;

        case 7:
            if (func_800DA298(0xB6)) {
                return 0;
            }
            break;

        case 8:
            if (func_800DA564(0xA34, 3)) {
                return 0;
            }
            break;

        case 14:
            // falls through
            exit_id = D_80801040_gcsectionskip[func_800DA564(0x3A4, 4)];

        case 10:
        case 15:
            break;

        case 11:
            if (func_800DA298(0x327)) {
                exit_id++;
            }
            break;

        case 12:
            // Cloud Cuckooland: Mumbo / Mingy Jongo redirect by skull flag
            if (!func_800DA9E4(0x409, 1)) {
                func_800DA3B8(0x40A, func_800DC298(0.5f) ? 0 : 1);
            }

            switch (func_800EA05C()) {
                case 0x136:
                    switch (map_id) {
                        case 0x13E:
                            if (!func_800DA298(0x40A)) {
                                map_id = 0x13F;
                            }
                            break;
                        case 0x13F:
                            if (!func_800DA298(0x40A)) {
                                map_id = 0x13E;
                            }
                            break;
                        default:
                            return 0;
                    }
                    break;
                case 0x13E:
                    if (!func_800DA298(0x40A)) {
                        exit_id = 9;
                    }
                    break;
                case 0x13F:
                    if (!func_800DA298(0x40A)) {
                        exit_id = 0x16;
                    }
            }
            break;

        case 13:
            if (!func_80800D3C_gcsectionskip(&map_id, &exit_id)) {
                func_80800374_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 9:
            if (form != 1) {
                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }
            if (!func_800C6E38(0x1B)) {
                func_808002A0_gcsectionskip(player, prop);
                func_80800EF8_gcsectionskip(0x10FB, 0x22);
                return 0;
            }
            break;

        case 16:
            if (form != 1 && form != 8) {
                func_80800374_gcsectionskip(player, prop);
                return 0;
            }
            check_level = 0;
            break;

        case 17:
            if (form != 0xC) {
                func_80800EF8_gcsectionskip(0x1219, 0x22);
                return 0;
            }
            break;

        case 18:
            if (form == 0xA) {
                func_80800EF8_gcsectionskip(0x1545, 0xCB);
                return 0;
            }

            if (form == 0xB) {
                func_80800EF8_gcsectionskip(0x1544, 0xCB);
                return 0;
            }
            break;

        case 19:
            if (form != 8) {
                func_80800EF8_gcsectionskip(0xF56, 0xCB);
                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 20:
            if (form != 1) {
                func_808002A0_gcsectionskip(player, prop);
                func_80800EF8_gcsectionskip(0x1221, 0x22);
                return 0;
            }

            if (!func_800C6E38(0x15)) {
                func_808002A0_gcsectionskip(player, prop);
                func_80800EF8_gcsectionskip(0x1227, 0x22);
                return 0;
            }

            if (!func_800C6E38(0x2E)) {
                func_808002A0_gcsectionskip(player, prop);
                func_80800EF8_gcsectionskip(0x122A, 0x22);
                return 0;
            }

            if (func_800DA298(0x44) && !func_800DA298(0x43)) {
                map_id = 0x19A;
                exit_id = 1;
            }
            break;

        case 21:
            if (func_800DA298(0x360)) {
                map_id = 0x19B;
            }
            break;

        case 22:
            if (!func_800F64A4(player, 0x601)) {
                func_80800EF8_gcsectionskip(0x1211, 0x6F);
                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 23:
            if (!func_800F64A4(player, 0x801)) {
                func_80800EF8_gcsectionskip(0x1223, 0x6F);
                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }

            if (!func_800C6E38(0x1F) || !func_800C6E38(0x2D)) {
                func_80800EF8_gcsectionskip(0x1226, 0x6F);
                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 24:
            if (form == 0x11) {
                func_80800374_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 25:
            cur_player = func_800F54E4();

            if (form == 0x11) {
                func_80800374_gcsectionskip(player, prop);
                return 0;
            }

            func_800F7C9C(cur_player, 0x95, func_800EA05C(), 2);
            break;

        case 26:
            cur_player2 = func_800F54E4();

            if (form == 0x11) {
                func_80800374_gcsectionskip(player, prop);
                return 0;
            }

            func_800F7C9C(cur_player2, 0x95, func_800EA05C(), 2);
            func_800F7B9C(cur_player2, 0x96);
            break;

        case 27:
            if (form == 0x11) {
                func_80800374_gcsectionskip(player, prop);
                return 0;
            }

            if (form != 1) {
                if (func_800F7E3C(player, 0x1224)) {
                    _chmrtannoy_entrypoint_0();
                }

                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }

            if (!func_800C6E38(0x2D)) {
                if (func_800F7E3C(player, 0x122B)) {
                    _chmrtannoy_entrypoint_0();
                }

                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 28:
            if (form == 8) {
                func_80800374_gcsectionskip(player, prop);
                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 30:
            if (form == 0xD) {
                func_800F7E3C(player, 0x1215);
                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 31:
            if (!func_800DA298(0x360) && !func_800DA298(0x3B)) {
                func_800F7E3C(player, 0x1566);
                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }
            break;

        case 32:
            if (!func_800C6E38(0x2F)) {
                func_800F7E3C(player, 0x122C);
                func_808002A0_gcsectionskip(player, prop);
                return 0;
            }
            break;
    }

    if (func_800D395C() || func_800D3948()) {
        func_808002A0_gcsectionskip(player, prop);
        return 0;
    }

    if (check_level && form != 1) {
        cur_level = D_8012762C;
        target_level = _gcsectionDll_entrypoint_4(map_id);
        same_level_form = target_level == cur_level && form == 0xD;

        if (cur_level != target_level || (cur_level == 0x1A && !same_level_form)) {
            func_80800374_gcsectionskip(player, prop);
            return 0;
        }
    }

    if (func_800A8264()) {
        return 0;
    }

    _gcgoto_entrypoint_3(prop, map_id, exit_id);
    return 1;
}

// Redirects some exits by progress; returns 0 unless the player is in character form 1.
int func_80800D3C_gcsectionskip(map_out, exit_out)
s32 *map_out;
s32 *exit_out;
{
    if (func_800F5410(func_800F54E4()) != 1)
        return 0;
    switch (func_800EA05C()) {
        case 0xAF:
            if (func_800DA298(0x318)) {
                *map_out = 0x142;
                *exit_out = 3;
            }
            break;
        case 0x142:
            if (func_800DA298(0x318)) {
                *map_out = 0xAF;
                *exit_out = 3;
            } else
                *exit_out = 1;
            break;
        case 0x15A:
            if (func_800DA298(0x319)) {
                *map_out = 0x154;
                *exit_out = 3;
            } else
                *exit_out = 1;
            break;
        case 0x154:
            if (func_800DA298(0x319)) {
                *map_out = 0x15A;
                *exit_out = 1;
            }
            break;
        case 0x15D:
            if (func_800DA298(0x31A)) {
                *map_out = 0x15F;
                if (func_800DA298(0x441))
                    *exit_out = 3;
                else
                    *exit_out = 1;
            }
            break;
        case 0x15F:
            if (func_800DA298(0x31A)) {
                *map_out = 0x15D;
                *exit_out = 2;
            } else
                *exit_out = 1;
            break;
    }
    return 1;
}

void func_80800EF8_gcsectionskip(s32 text_id, s32 unk_1)
{
    func_800C05B8(text_id, 0, 0, 0, 0, 0, unk_1);
}

// TU-NOTE: the .data of this overlay is defined here in C; values taken from the ROM.
u8 D_80801040_gcsectionskip[16] = {0x0,  0x16, 0x23, 0x28, 0x17, 0x13, 0x24, 0x25,
                                   0x15, 0x14, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
