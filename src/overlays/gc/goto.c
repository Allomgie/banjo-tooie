// Map warp requests: warp to a (map, exit) with a lock against double requests, JRL map remapping,
// and warp-pad transitions that place player and camera at a nearby warp marker.
#include "gc/goto.h"

extern s16 D_80800710_gcgoto[];
extern s16 D_80800720_gcgoto[];
extern s16 D_8080072C_gcgoto[];
extern s16 D_8080073C_gcgoto[];
extern u8 D_80800740_gcgoto[];
extern void *_gccubesearch_entrypoint_5(void *, void *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_80090358(f32 *, f32, s32, s32);
extern void func_8008FE68(f32 *);
extern void _plcamera_entrypoint_11(s32, f32 *);
extern void func_800EE88C(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern int D_801275C0[];
void gcgoto_entrypoint_4(s32 param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4);

// TU-NOTE: warp_lock is the byte at D_80127194 + 0x42C (D_801275C0).
typedef struct {
    u8 pad_0[0x42C];
    u8 warp_lock;
} UNKD_80127194;

extern UNKD_80127194 D_80127194;

// Whether value is in the -1 terminated list.
s32 func_80800000_gcgoto(s8 *list, s16 value)
{
    s32 i = 0;
    while (list[i] != -1) {
        if (value == list[i++]) {
            return 1;
        }
    }
    return 0;
}

// Remap the old JRL map 0xFB to 0x1A6-0x1A9 depending on the exit.
void gcgoto_entrypoint_0(s32 *map, s32 *exit)
{
    if (*map == 0xFB) {
        if (func_80800000_gcgoto(D_80800710_gcgoto, ((s16 *) exit)[1]))
            *map = 0x1A7;
        else if (func_80800000_gcgoto(D_80800720_gcgoto, ((s16 *) exit)[1]))
            *map = 0x1A8;
        else if (func_80800000_gcgoto(D_8080072C_gcgoto, ((s16 *) exit)[1]))
            *map = 0x1A9;
        else if (func_80800000_gcgoto(D_8080073C_gcgoto, ((s16 *) exit)[1]))
            *map = 0x1A6;
    }
}

// Request a warp unless the lock is set.
void func_8080011C_gcgoto(s32 map, s32 exit, s32 unk_0, s32 unk_1)
{
    if (D_80127194.warp_lock == 0) {
        // MT kickball exit 4 sets a flag.
        if ((map == 0xCE) && (exit == 4)) {
            func_800DA544(FLAG_503_UNK);
        }
        gcgoto_entrypoint_0(&map, &exit);
        func_800A7990(map, exit, unk_1);
        func_800EA334(unk_0);
        gcgoto_entrypoint_14(1);
    }
}

void gcgoto_entrypoint_1(u32 map, u32 exit)
{
    func_8080011C_gcgoto(map, exit, 0, 1);
}

s32 gcgoto_entrypoint_2(s32 map, s32 exit, s32 unk_0)
{
    func_8080011C_gcgoto(map, exit, 0, unk_0);
}

// Warp, placing the player and camera first when a warp marker
// (types 0x24D-0x24F) is near pos.
void func_808001E0_gcgoto(f32 *pos, s32 map, s32 exit, s32 unk_0)
{
    f32 player_pos[3];
    f32 marker_pos[3];
    u8 *marker;
    f32 max_dist;

    if (!*((u8 *) &D_80127194 + 0x42C)) {
        marker = pos ? _gccubesearch_entrypoint_5(D_80800740_gcgoto, pos) : NULL;
        func_8008FE68(player_pos);
        if (marker) {
            _gspropctrl_entrypoint_11(marker, marker_pos);
            if (unk_0) {
                max_dist = 500.0f;
                if (*(u16 *) (marker + 8) == 0x24F) {
                    max_dist = 1000.0f;
                }
            } else {
                max_dist = 1000.0f;
            }
            if (func_800EEAD4(pos, marker_pos) < max_dist) {
                if (*(u16 *) (marker + 8) == 0x24D) {
                    _plcamera_entrypoint_11(func_800F54E4(), marker_pos);
                    func_8080011C_gcgoto(map, exit, 1, 1);
                    func_800A1618(1);
                    func_80090358(marker_pos, 1.0f, 0, 0);
                    return;
                }
                if (*(u16 *) (marker + 8) == 0x24E) {
                    gcgoto_entrypoint_4(map, exit, marker_pos[1],
                                        (f32) (*(u32 *) (marker + 0xC) >> 23),
                                        *(u32 *) (marker + 0xC) & 0x7FFFFF);
                    return;
                }
                gcgoto_entrypoint_4(map, exit, player_pos[1],
                                    (f32) (*(u32 *) (marker + 0xC) >> 23),
                                    *(u32 *) (marker + 0xC) & 0x7FFFFF);
                return;
            }
        }
        func_8080011C_gcgoto(map, exit, 0, 1);
    }
}

// Warp to a packed (map << 8) | exit, using a warp marker near unk_0 if given.
void func_808003D0_gcgoto(s32 unk_0, s32 map_exit)
{
    f32 pos[3];
    s32 pad[2];

    if (!*(u8 *) D_801275C0) {
        if (unk_0 != 0) {
            func_800EE88C(pos, (f32 *) unk_0);
            func_808001E0_gcgoto(pos, map_exit >> 8, map_exit & 0xFF, 0);
        } else {
            func_808001E0_gcgoto(NULL, map_exit >> 8, map_exit & 0xFF, 1);
        }
    }
}

// Same as func_808003D0_gcgoto with separate map and exit.
s32 gcgoto_entrypoint_3(s32 unk_0, s32 map, s32 exit)
{
    s32 map_exit = map << 8;
    map_exit += exit;
    func_808003D0_gcgoto(unk_0, map_exit);
}

// Place the player and camera, then warp.
void gcgoto_entrypoint_4(s32 map, s32 exit, f32 cam_y, f32 unk_0, s32 unk_1)
{
    f32 player_pos[3];
    f32 cam_pos[3];
    f32 target[3];

    func_8008FE68(player_pos);
    func_800EEB9C(target, unk_0, func_800F10B4(unk_1, 0.0f, 200.0f, 10.0f, 800.0f));
    target[0] += player_pos[0];
    target[1] += player_pos[1];
    target[2] += player_pos[2];
    cam_pos[0] = target[0];
    cam_pos[1] = cam_y;
    cam_pos[2] = target[2];
    _plcamera_entrypoint_11(func_800F54E4(), cam_pos);
    func_8080011C_gcgoto(map, exit, 1, 1);
    func_800A1618(1);
    func_80090358(cam_pos, 1.0f, 0, 0);
}

void gcgoto_entrypoint_5(s32 map, s32 exit, f32 unk_0)
{
    f32 player_pos[3];
    func_8008FE68(player_pos);
    gcgoto_entrypoint_4(map, exit, player_pos[1], unk_0, 0x25);
}

void gcgoto_entrypoint_6(s32 map, s32 exit)
{
    func_8080011C_gcgoto(map, exit, 0, 1);
}

void gcgoto_entrypoint_7(s32 unk_0, s32 unk_1)
{
}

// Soft reset: leave the game and fade out the music.
s32 gcgoto_entrypoint_8(s32 unk_0, s32 unk_1)
{
    if (func_80015FA0(0) == 1) {
        func_800A7AD4(1, 2);
        func_800FC1CC(0, 0x320);
        func_800FE3EC();
        gcgoto_entrypoint_7(unk_0, unk_1);
    }
}

s32 gcgoto_entrypoint_9(s32 unk_0, s32 unk_1)
{
    if (func_8008FD48(unk_0) == 8) {
        // Map 0xBC (MT code chamber), exit 2.
        func_808003D0_gcgoto(unk_0, 0xBC02);
    }
}

s32 gcgoto_entrypoint_10(s32 unk_0, s32 unk_1)
{
    if (func_8008FD48(unk_0) == 8) {
        // Map 0xC4 (MT Jade Snake Grove), exit 3.
        func_808003D0_gcgoto(unk_0, 0xC403);
    }
}

// Warp to the exit given by the temple boss.
void gcgoto_entrypoint_11(s32 unk_0, u32 unk_1)
{
    s32 map;
    s32 exit;

    _sutempleboss_entrypoint_0(unk_0, &map, &exit);
    if (map != 0) {
        func_808003D0_gcgoto(unk_0, (map << 8) + exit);
    }
}

void gcgoto_entrypoint_12(void)
{
}

// Clear the warp lock.
int gcgoto_entrypoint_13()
{
    *(s8 *) ((char *) D_801275C0 + 0x0) = 0;
    D_801275C0[1] = 0;
}

// Set the warp lock.
void gcgoto_entrypoint_14(long lock)
{
    *(u8 *) ((u8 *) (u8 *) &D_80127194 + 0x42c) = lock;
}

// Get the warp lock.
int gcgoto_entrypoint_15()
{
    u8 *lock = &((u8 *) &D_80127194)[0x42C];
    return *lock;
}

// TU-NOTE: the .data of this overlay is defined here in C. Values are taken from the ROM.
s16 D_80800710_gcgoto[8] = {0x30F, 0x102, 0xE0D, 0x1E04, 0x500, 0x609, -0x100, 0x0};
s16 D_80800720_gcgoto[6] = {0x2720, 0xA11, 0x120C, 0x1F07, -0x100, 0x0};
s16 D_8080072C_gcgoto[8] = {0x1B14, 0x1322, 0x2425, 0x1517, 0x2823, 0x1621, 0x100B, -0x100};
s16 D_8080073C_gcgoto[2] = {0x826, -0x100};
u8 D_80800740_gcgoto[16] = {0x0, 0x0, 0x2, 0x4D, 0x0,  0x0,  0x2,  0x4E,
                            0x0, 0x0, 0x2, 0x4F, 0xFF, 0xFF, 0xFF, 0xFF};
