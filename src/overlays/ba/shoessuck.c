#include "common.h"
#include "playerstate.h"

extern void func_800EFA4C(f32 *, f32, f32, f32);

extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern f32 D_80800740_bashoessuck[];
extern u32 D_80800800_bashoessuck[];
extern void func_8009C128();
extern s32 func_800C6A7C(f32 *, f32 *, f32 *, s32);
extern void func_800EE7F8(void *, f32 *);
extern f32 yaw_get(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern void _bamovespline_entrypoint_9(PlayerState *, f32);
extern f32 func_800EEFD4(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_800C82CC(void *, f32 *);
extern void *func_800D7520(void *);
extern void *_gccubesearch_entrypoint_5(void *, f32 *);
extern void *_glsplinefind_entrypoint_3(f32 *);
extern void func_800C7A68(void *, f32, f32 *);
extern s32 func_800F1E6C(f32 *, f32 *, f32 *);

// Probe 8 directions for a steep wall; returns 1 and its normal
s32 bashoessuck_entrypoint_0(void *player, void *normal_out)
{
    s32 pad1; // Matching: unused, but it carries the stack frame
    f32 pos[3];
    f32 start[3];
    f32 end[3];
    f32 normal[3];
    s32 j;
    s32 i;

    func_8009C128(player, pos);
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 3; i++) {
            start[i] = pos[i] + D_80800740_bashoessuck[j * 6 + i];
        }
        for (i = 0; i < 3; i++) {
            end[i] = pos[i] + D_80800740_bashoessuck[j * 6 + i + 3];
        }
        if (func_800C6A7C(start, end, normal, 0x20020) != 0) {
            if (normal[1] < 0.8f) {
                func_800EE7F8(normal_out, normal);
                return 1;
            }
        }
    }
    func_800EFA4C(normal_out, 0.0f, 1.0f, 0.0f);
    return 0;
}

s32 bashoessuck_entrypoint_1(s32 player, s32 pos)
{
    s32 prop;
    func_8009C128(player);
    prop = _gccubesearch_entrypoint_1(0x16D, pos);
    if (prop) {
        _gspropctrl_entrypoint_11(prop, pos);
    }
}

void bashoessuck_entrypoint_2(s32 player)
{
    func_800932CC(player, 0);
    func_8009BF5C(player, 0);
    baroll_setIdeal(player, 0);
    func_800961AC(player, 1);
}

void bashoessuck_entrypoint_3(s32 player)
{
    func_800961AC(player, 0xA);
}

void bashoessuck_entrypoint_4(s32 player)
{
    extern f32 func_8009BB18(s32);
    extern f32 func_800EEAA4(f32 *, f32 *);
    extern f32 func_800F1C98(f32 *, f32 *);
    extern f32 func_80013AAC(f32);
    extern void func_800EFA20(f32 *, f32 *, f32);
    extern void func_800EF934(f32 *, f32 *, f32);
    extern void _bashoes_entrypoint_10(s32, f32);
    extern void func_800932BC(s32, f32);
    extern void yaw_setIdeal(s32, f32);
    f32 yaw;
    // Matching: the two pointer temporaries are needed for the match.
    f32 *axis_ptr;
    f32 pitch;
    f32 *unk_0_ptr;
    f32 unk_0;
    f32 axis[3];
    f32 rotated[3];
    f32 pos[3];
    f32 along_normal[3];
    f32 offset[3];
    f32 up[3];
    f32 normal[3];
    f32 flat_normal[3];
    s32 unk_1;
    f32 yaw_vec[3];
    unk_1 = func_80092BC4();
    func_800932CC(player, 0);
    if (!_bamovespline_entrypoint_4(player)) {
        func_800EFA4C(yaw_vec, 0.0f, func_8009BB18(player), 0.0f);
        yaw_setIdeal(player, yaw_vec[1]);
        return;
    }
    _bamovespline_entrypoint_0(player, pos);
    if (bashoessuck_entrypoint_0(player, normal)) {
        func_800932CC(player, 1);
        _bashoes_entrypoint_10(player, 1.0f);
        axis_ptr = axis;
        func_800EFA20(along_normal, normal, func_800EEAA4(pos, normal));
        func_800EFB24(offset, pos, along_normal);
        func_800EFA4C(up, 0.0f, 1.0f, 0.0f);
        unk_0_ptr = &unk_0;
        if (normal[1] > 0.99f) {
            unk_0 = 0.0f;
            pitch = 0.0f;
            yaw = 0.0f;
        } else {
            func_800EFA4C(flat_normal, normal[0], 0.0f, normal[2]);
            func_800F1EA4(flat_normal, unk_0_ptr);
            pitch = func_80013AAC(func_800F1C98(up, normal));
            func_800EE97C(axis, up, flat_normal);
            yaw = (func_80013AAC(func_800F1C98(offset, axis_ptr)) - 90.0f) + 180.0f;
            if (offset[1] < 0.0f) {
                yaw = 180.0f - yaw;
            }
            func_800EF934(rotated, offset, -unk_0);
            if (rotated[0] < 0.0f) {
                yaw = 360.0f - yaw;
            }
        }
        if (unk_1 && (func_8009BB18(player) > 180.0f)) {
            yaw += 180.0f;
        }
        func_800932BC(player, unk_0);
        func_8009BF5C(player, pitch);
        yaw_setIdeal(player, yaw);
        baroll_setIdeal(player, 0.0f);
        if (!unk_1) {
            yaw_applyIdeal(player);
        }
    }
}

// Try to attach to a claw clamber marker and its spline
s32 bashoessuck_entrypoint_5(PlayerState *player, f32 *pos)
{
    f32 unk_0;
    f32 height_diff;
    f32 spline_t;
    f32 yaw;
    f32 marker_yaw;
    f32 velocity[3];
    f32 player_pos[3];
    f32 spline_pos[3];
    f32 marker_pos[3];
    void *spline_data;
    f32 unk_1;
    u8 *marker;
    void *spline;

    if (_bashoes_entrypoint_9())
        return 0;
    func_8009BB24(player, velocity);
    velocity[1] = 0.0f;
    if (func_800EEFD4(velocity) < 1.0f)
        return 0;
    yaw = yaw_get(player);
    marker = _gccubesearch_entrypoint_5((void **) D_80800800_bashoessuck, pos);
    if (!marker)
        return 0;
    _gspropctrl_entrypoint_11(marker, marker_pos);
    spline = _glsplinefind_entrypoint_3(marker_pos);
    func_800C7A68(func_800D7520(spline), 1.0f, pos);
    marker = _gccubesearch_entrypoint_5((void **) D_80800800_bashoessuck, pos);
    if (!marker)
        return 0;
    switch (*(u16 *) (marker + 8)) {
        case 0x16B:
            _bashoes_entrypoint_11(player, 1);
            break;
        case 0x16C:
            _bashoes_entrypoint_11(player, 2);
            break;
    }
    func_8009C128(player, player_pos);
    spline_data = func_800D7520(spline);
    spline_t = func_800C82CC(spline_data, player_pos);
    func_800C7A68(spline_data, spline_t, spline_pos);
    if (func_800EEB40(player_pos, spline_pos) < 1764.0f) {
        baphysics_set_type(player, 0x12);
        _bamovespline_entrypoint_7(player, spline);
        _bamovespline_entrypoint_9(player, spline_t);
        return 1;
    }
    func_800F1E6C(player_pos, marker_pos, &marker_yaw);
    if (mlAbsF(func_800F1DCC(marker_yaw, yaw)) > 45.0f)
        return 0;
    height_diff = player_pos[1] - marker_pos[1];
    if (mlAbsF(height_diff) > 20.0f)
        return 0;
    if (func_800EFB8C(player_pos, marker_pos) < height_diff)
        return 0;
    baphysics_set_type(player, 0x12);
    _bamovespline_entrypoint_7(player, spline);
    _bamovespline_entrypoint_8(player);
    return 1;
}

// TU-NOTE: the .data of this overlay is defined here in C, values taken from the ROM.
f32 D_80800740_bashoessuck[48] = {
    -24.0f, 8.0f,  0.0f,   24.0f, 8.0f,  0.0f,  24.0f, 8.0f,  0.0f,  -24.0f, 8.0f,  0.0f,
    0.0f,   8.0f,  -24.0f, 0.0f,  8.0f,  24.0f, 0.0f,  8.0f,  24.0f, 0.0f,   8.0f,  -24.0f,
    -24.0f, -8.0f, 0.0f,   24.0f, -8.0f, 0.0f,  24.0f, -8.0f, 0.0f,  -24.0f, -8.0f, 0.0f,
    0.0f,   -8.0f, -24.0f, 0.0f,  -8.0f, 24.0f, 0.0f,  -8.0f, 24.0f, 0.0f,   -8.0f, -24.0f};
u32 D_80800800_bashoessuck[4] = {0x16B, 0x16C, 0xFFFFFFFF, 0x0};
