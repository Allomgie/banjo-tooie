#include "core2/1E7D460.h"
struct Actor {
    u8 _[0x38];
    void *unk38;
};

#define CAMERA (((LocalCameraPlayer *) param_0)->camera)
#define QQ (*(S_A4E30 **) ((u8 *) param_0 + 0x38))
// Overlapping views of the camera controller block at PlayerState+0x38 (0x40 bytes).
typedef struct {
    u8 pad[2];
    u8 zoom;
    u8 pad1[5];
    s32 preset_1[3], preset_2[3], preset_3[3];
    f32 scale_xy, scale_z;
    s16 unk_34;
} ScaleA3BA8;
typedef struct {
    u8 pad[0x38];
    ScaleA3BA8 *ctrl;
} OwnerA3BA8;
extern void func_80110CC0(void *, f32, f32, f32, f32);
extern void func_80115564(void *);
extern f32 _batimer_get();
typedef struct LocalCameraControl {
    u8 pad00[2], zoom, saved_zoom, request_zoom, unk_5;
    u8 pad06[0x30];
    s16 volume_index;
    u8 loaded_volume;
} LocalCameraControl;
typedef struct LocalCameraPlayer {
    u8 pad00[0x38];
    LocalCameraControl *camera;
} LocalCameraPlayer;
extern s32 func_80090E24(PlayerState *);
extern s32 func_80090E30(PlayerState *);
extern s32 func_800A5854(s32);
extern s32 func_800A5904(s32);
extern s32 func_800A5B9C(void);
extern s32 func_800A5B7C(void);
extern s32 func_800A5BBC(void);
extern s32 func_800A5BAC(void);
extern s32 func_800A5BCC(void);
extern s32 func_800A5B6C(void);
extern f32 func_800A5B8C(void);
extern void func_80110F44(PlayerState *);
extern void func_80110D80(PlayerState *, s32);
extern void func_80110D28(PlayerState *, s32);
extern void func_80110D58(PlayerState *, f32);
extern void func_800A5800(s32);
extern void _cadbfunc_entrypoint_26(s32 *);
extern void _cadbfunc_entrypoint_29(s32, s32 *);
extern void _cadbfunc_entrypoint_22(s32 *);
extern void _cadbfunc_entrypoint_24(s32 *);
extern void _cadbfunc_entrypoint_34(s32 *);
extern void _cadbfunc_entrypoint_32(f32 *);
extern void _cadbfunc_entrypoint_0(f32 *);
extern void _cadbfunc_entrypoint_2(f32 *);
extern void _ncbadolly_entrypoint_4(PlayerState *, s32);
extern void _ncbafixpos_entrypoint_4(PlayerState *, s32);
extern void _ncbaspiral_entrypoint_5(PlayerState *, s32);
extern void func_800CA628(f32 *, f32 *, f32 *);
extern void func_801108A0(PlayerState *);
extern s32 func_80110EFC(PlayerState *, s32);
extern s32 func_800A3274(void *);
extern s32 func_800F40EC(void);
typedef struct {
    u8 forced_type, pad0[5], mode, pad1[0x34], block_input;
} LocalState;
typedef struct {
    u8 pad0[0x38];
    LocalState *ctrl;
    u8 pad1[0x148];
    s32 index;
} LocalPlayer;
extern void func_80090C34(LocalPlayer *);
extern void func_80090C28(LocalPlayer *, s32);
extern void func_800A940C(s32 arg);
typedef struct {
    char pad[0x184];
    s32 unk184;
} Actor;
extern void func_800A93E4(int param_0);
extern void func_800CA7E4(f32 *, s32);
typedef struct {
    u8 unk0;
    u8 pad1[5];
    u8 unk6;
} S_A4E30;
f32 mlAbsF(f32 param_0);
struct unk_struct_38 {
    char pad[60];
    int unk3C;
};
struct unk_struct_0 {
    char pad[56];
    struct unk_struct_38 *unk38;
};
void func_800A4074();
int func_800A4D40();

// Size of the camera controller block.
s32 func_800A3B70()
{
    return 0x40;
}

void func_800A3B78(s32 player, s32 type)
{
    s32 camera;
    camera = func_800A4CA8(player);
    if (camera != 0) {
        // Matching: the no-op "| 0" is needed for the match.
        func_801106A8(camera | 0, type);
    }
}

// Apply the zoom preset of the current zoom level to the camera instance.
void func_800A3BA8(PlayerState *player, s32 unk_1)
{
    void *camera;
    camera = func_800A4CA8(player);
    if (camera) {
        switch (((OwnerA3BA8 *) player)->ctrl->zoom) {
            case 1:
                func_80110CC0(camera,
                              ((OwnerA3BA8 *) player)->ctrl->preset_1[0] *
                                  ((OwnerA3BA8 *) player)->ctrl->scale_xy,
                              ((OwnerA3BA8 *) player)->ctrl->preset_1[1] *
                                  ((OwnerA3BA8 *) player)->ctrl->scale_xy,
                              ((OwnerA3BA8 *) player)->ctrl->preset_1[2] *
                                  ((OwnerA3BA8 *) player)->ctrl->scale_z,
                              ((OwnerA3BA8 *) player)->ctrl->unk_34);
                break;
            case 2:
                func_80110CC0(camera,
                              ((OwnerA3BA8 *) player)->ctrl->preset_2[0] *
                                  ((OwnerA3BA8 *) player)->ctrl->scale_xy,
                              ((OwnerA3BA8 *) player)->ctrl->preset_2[1] *
                                  ((OwnerA3BA8 *) player)->ctrl->scale_xy,
                              ((OwnerA3BA8 *) player)->ctrl->preset_2[2] *
                                  ((OwnerA3BA8 *) player)->ctrl->scale_z,
                              ((OwnerA3BA8 *) player)->ctrl->unk_34);
                break;
            case 3:
                func_80110CC0(camera,
                              ((OwnerA3BA8 *) player)->ctrl->preset_3[0] *
                                  ((OwnerA3BA8 *) player)->ctrl->scale_xy,
                              ((OwnerA3BA8 *) player)->ctrl->preset_3[1] *
                                  ((OwnerA3BA8 *) player)->ctrl->scale_xy,
                              ((OwnerA3BA8 *) player)->ctrl->preset_3[2] *
                                  ((OwnerA3BA8 *) player)->ctrl->scale_z,
                              ((OwnerA3BA8 *) player)->ctrl->unk_34);
                break;
            case 4:
                func_80110CC0(camera, 250.0f, 300.0f, 50.0f,
                              ((OwnerA3BA8 *) player)->ctrl->unk_34);
                break;
        }
        if (unk_1)
            func_80115564(camera);
    }
}

// Set the zoom level and apply it.
void func_800A3D78(player, zoom, unk_2) struct Actor *player;
s32 zoom;
s32 unk_2;
{
    u8 *ctrl = player->unk38;

if (ctrl[2] != zoom) {
    ctrl[2] = zoom;
    func_800A3BA8(player, unk_2);
}

}

// Current zoom level.
s32 func_800A3DAC(void *player)
{
    return ((u8 *) (*(void **) ((char *) player + 0x38)))[2];
}

// Load the per-map zoom presets; zoom 3 falls back to 2 if unavailable.
void func_800A3DB8(u8 *player, s32 preset, s32 unk_2, s32 no_far_zoom, s32 unk_4)
{
    u8 *ctrl;
    u8 *ctrl2;

if (((preset != *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 1)) ||
     (unk_2 != *(s16 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 0x34))) ||
    (no_far_zoom != *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 0x39))) {
    *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 1) = (u8) preset;
    ctrl = *(u8 **) ((s8 *) player + 0x38);
    func_800A59B8(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 1),
                  *(u8 **) ((s8 *) player + 0x38) + 8, *(u8 **) ((s8 *) player + 0x38) + 0xC,
                  *(u8 **) ((s8 *) player + 0x38) + 0x10, *(u8 **) ((s8 *) player + 0x38) + 0x14,
                  *(u8 **) ((s8 *) player + 0x38) + 0x18, *(u8 **) ((s8 *) player + 0x38) + 0x1C,
                  *(u8 **) ((s8 *) player + 0x38) + 0x20, *(u8 **) ((s8 *) player + 0x38) + 0x24,
                  ctrl + 0x28);
    *(s16 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 0x34) = (s16) unk_2;
    *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 0x39) = (u8) no_far_zoom;
    if ((func_800A3DAC(player) == 3) &&
        ((ctrl2 = *(u8 **) ((s8 *) player + 0x38), *(s32 *) ((s8 *) ctrl2 + 0x20) == 0) ||
         (*(u8 *) ((s8 *) ctrl2 + 0x39) != 0))) {
        func_800A3D78(player, 2, unk_4);
        return;
    }
    func_800A3BA8(player, unk_4);
}

}

// Matching: the extra pointer copies are needed for the match.
void func_800A3EC8(u8 *player, int unk_1)
{
    u8 *ctrl_copy;
    u8 *ctrl;
    u8 *player_copy;
    s32 camera;
    player_copy = player;
    ctrl = *((u8 **) (((char *) player) + 0x38));
    ctrl_copy = ctrl;

if (unk_1 != ctrl_copy[7]) {
    ctrl[7] = unk_1;
    camera = func_800A4CA8(player_copy);
    func_80110D08(camera, (*(u8 **) ((char *) player + 0x38))[7], player);
}

}

// Switch the camera mode (+6), running exit and enter actions for the old and new mode.
int func_800A3F14(u8 *player, s32 mode)
{
    u8 *ctrl;
    u8 **ctrl_ptr;
    u8 old_mode;
    ctrl = *((u8 **) (((s8 *) player) + 0x38));
    old_mode = *((u8 *) (((s8 *) ctrl) + 6));

if (mode != old_mode) {
    switch (old_mode) {
        case 5:
            func_80090C28(player, 1);
            break;

        case 7:
            func_800A3D78(player, *(u8 *) ((s8 *) ctrl + 0x3A), 1);
            *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 0x3A) = 0;
    }

    // Matching: this helper pointer is needed for the match.
    ctrl_ptr = (u8 **) ((s8 *) player + 0x38);
    switch (mode) {
        {
            case 2:
                func_800A3B78(player, 0x13);
                break;
        }
        case 7:
            func_800A3B78(player, 0x1A);
            *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 0x3A) = func_800A3DAC(player);
            func_800A3D78(player, 4U, 1);
            break;

        case 8:
            func_800A3B78(player, 0x18);
            break;

        case 6:
            func_800A3B78(player, 2);
    }

    ctrl = (s8 *) *ctrl_ptr;
    *(s8 *) (ctrl + 6) = (s8) mode;
}

}

// Reset the controller; stays in first-person mode if active.
void func_800A4030(u8 *player)
{
    if (*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 6) == 9) {
        func_800A4074(player, 9);
        return;
    }

func_800A4074(player, 2);
}

// Reset the controller and enter the given mode.
void func_800A4074(player, mode) u8 *player;
s32 mode;
{
    u8 *ctrl;
    int invalid_id;
    func_800A5A4C();
    func_80090B98(player);
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x38)))) + 0)) = 0;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x38)))) + 6)) = 0;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x38)))) + 3)) = 0;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x38)))) + 4)) = 0;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x38)))) + 5)) = 0;
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x38)))) + 0x30)) = 1.0f;
    ctrl = *((u8 **) (((s8 *) player) + 0x38));
    // Matching: the same-type cast is needed for the match.
    *((f32 *) (((s8 *) ctrl) + 0x2C)) = (f32) (*((f32 *) (((s8 *) ctrl) + 0x30)));
    func_800A3F14(player, mode);
    // Matching: the int temporary holding 0xFF is needed for the match.
    invalid_id = 0xFF;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x38)))) + 2)) = 2;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x38)))) + 1)) = invalid_id;
    func_800A3DB8(player, 0, 0, 0, 1);
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x38)))) + 7)) = invalid_id;
    func_800A3EC8(player, 0);
    _batimer_set(player, 7, 0x3F000000);
    *((s16 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x38)))) + 0x36)) = -1;
}

void func_800A4160(s32 arg0)
{
}
void func_800A4168(void *player)
{
    (*((s32 **) (((char *) player) + 0x38)))[0x3C / 4] = 0;
    func_800A4074(player, 2);
}

// Handle C-button zoom input.
void func_800A4190(player) u8 *player;
{
    u8 zoom;
    u8 *ctrl;

if ((func_800A4D40() != 0) && (func_800F65D0(*(s32 *) ((s8 *) player + 0x184)) != 0) &&
    (func_8009CC68(player) == 0) && (func_800F3ED0(player) != 4) &&
    (_batimer_get(player, 7) == 0.0f) && (bainput_should_exit_first_person(player) != 0)) {
    ctrl = *(u8 **) ((s8 *) player + 0x38);
    if ((*(u8 *) ((s8 *) ctrl + 4) == 0) && (*(u8 *) ((s8 *) ctrl + 0x3B) == 0)) {
        zoom = *(u8 *) ((s8 *) ctrl + 2);
        switch (zoom) {
            case 1:
                func_8009DB04(player, 0x488, 0x3F800000, 0x2EE0);
                func_800A3D78(player, 2, 1);
                break;
            case 2:
                if ((*(s32 *) ((s8 *) ctrl + 0x20) != 0) &&
                    (*(u8 *) ((s8 *) ctrl + 0x39) == 0)) {
                    func_8009DB04(player, 0x488, 0x3F99999A, 0x2EE0);
                    func_800A3D78(player, 3, 1);
                } else {
                    func_8009DB04(player, 0x487, 0x3F800000, 0x2EE0);
                    func_800A3D78(player, 1, 1);
                }
                break;
            case 3:
                func_8009DB04(player, 0x487, 0x3F800000, 0x2EE0);
                func_800A3D78(player, 1, 1);
        }
        _batimer_set(player, 7, 0x3ECCCCCD);
    }
}

}

// Match the camera to the camera-database volume the player stands in (-1 = none).
// Returns 1 when a ncba* camera was started. param_0 keeps its name: the CAMERA macro uses it.
s32 func_800A4338(PlayerState *param_0)
{
    s32 volume;
    s32 unk_1;
    s32 zoom;
    s32 value;
    s32 unk_4;
    s32 preset;
    s32 no_far_zoom;
    s32 unk_7;
    f32 unk_8;
    s32 volume_type;

    volume = func_80090E24(param_0);
    no_far_zoom = 0;
    unk_7 = func_80090E30(param_0);
    volume_type = func_800A5854(volume);

if (volume == -1 || !func_800A5904(volume) || (CAMERA->loaded_volume && volume_type != 4)) {
    CAMERA->request_zoom = func_800A5B9C();
    if (CAMERA->request_zoom == 5) {
        no_far_zoom = 1;
        CAMERA->request_zoom = 0;
    }
    func_800A3DB8(param_0, 0, func_800A5B7C(), no_far_zoom, unk_7);
    func_800A3EC8(param_0, func_800A5BBC());
    if (CAMERA->request_zoom) {
        func_800A3D78(param_0, CAMERA->request_zoom, unk_7);
    } else if (CAMERA->loaded_volume) {
        if (CAMERA->saved_zoom) {
            func_800A3D78(param_0, CAMERA->saved_zoom, unk_7);
        } else {
            func_80110F44(func_800A4CA8(param_0));
        }
    }
    CAMERA->unk_5 = func_800A5BAC();
    func_80110D80(func_800A4CA8(param_0), func_800A5BCC());
    func_80110D28(func_800A4CA8(param_0), func_800A5B6C());
    func_80110D58(func_800A4CA8(param_0), func_800A5B8C());
    CAMERA->loaded_volume = 0;
    return 0;
}

unk_1 = bs_getCurrentState(param_0);

switch (volume_type) {
    case 4: // parameter override
        func_800A5800(volume);
        _cadbfunc_entrypoint_26(&zoom);
        unk_1 = volume + 1;
        if (!zoom && CAMERA->loaded_volume && unk_1 != CAMERA->loaded_volume && CAMERA->saved_zoom) {
            zoom = CAMERA->saved_zoom;
        }
        if (zoom == 5) {
            no_far_zoom = 1;
            zoom = 0;
        }
        if (!zoom && CAMERA->zoom == 4)
            zoom = 1;
        if (!CAMERA->loaded_volume) {
            _cadbfunc_entrypoint_29(0x10, &value);
            if (value)
                CAMERA->saved_zoom = func_800A3DAC(param_0);
            else
                CAMERA->saved_zoom = 0;
        }
        if (zoom)
            func_800A3D78(param_0, zoom, 0);
        CAMERA->request_zoom = zoom;
        _cadbfunc_entrypoint_22(&unk_4);
        _cadbfunc_entrypoint_24(&preset);
        func_800A3DB8(param_0, preset, unk_4, no_far_zoom, 0);
        _cadbfunc_entrypoint_29(0x40, &value);
        func_800A3EC8(param_0, value);
        _cadbfunc_entrypoint_29(0x20, &value);
        CAMERA->unk_5 = value;
        _cadbfunc_entrypoint_29(0x80, &value);
        func_80110D80(func_800A4CA8(param_0), value);
        _cadbfunc_entrypoint_34(&unk_4);
        func_80110D28(func_800A4CA8(param_0), unk_4);
        _cadbfunc_entrypoint_32(&unk_8);
        func_80110D58(func_800A4CA8(param_0), unk_8);
        CAMERA->loaded_volume = unk_1;
        return 0;
    case 3: // dolly
        if (func_8009CA70(param_0, unk_1, 0x4000)) {
            s32 unk_10 = 0;
            func_800A5800(volume);
            _cadbfunc_entrypoint_29(4, &unk_10);
            if (!unk_10)
                return 0;
        }
        func_800A3B78(param_0, 13);
        _ncbadolly_entrypoint_4(func_800A4CA8(param_0), volume);
        func_800A3F14(param_0, 4);
        return 1;
    case 1: // fixed pos
        if (func_8009CA70(param_0, unk_1, 0x4000)) {
            s32 unk_11 = 0;
            func_800A5800(volume);
            _cadbfunc_entrypoint_29(4, &unk_11);
            if (!unk_11)
                return 0;
        }
        func_800A3B78(param_0, 6);
        _ncbafixpos_entrypoint_4(func_800A4CA8(param_0), volume);
        func_800A3F14(param_0, 4);
        return 1;
    case 2: // static
        if (volume != CAMERA->volume_index) {
            f32 unk_12[3];
            f32 unk_13[3];
            func_800A5800(volume);
            _cadbfunc_entrypoint_0(unk_12);
            _cadbfunc_entrypoint_2(unk_13);
            func_800CA628(func_800A4C48(param_0), unk_12, unk_13);
            func_801108A0(func_800A4CA8(param_0));
            CAMERA->volume_index = volume;
        }
        return 0;
    case 7: // spiral
        func_800A3B78(param_0, 18);
        _ncbaspiral_entrypoint_5(func_800A4CA8(param_0), volume);
        func_800A3F14(param_0, 4);
        func_800A4190(param_0);
        return 1;
}

return 0;
}

// Handle camera rotate left/right input.
s32 func_800A4878(PlayerState *player)
{
    PlayerState *camera;
    camera = func_800A4CA8(player);
    if ((*(u8 **) ((u8 *) player + 0x38))[5])
        return func_80110EFC(camera, 2);
    if (!func_800A4D40(player) || func_8009CC68(player) ||
        !func_800F65D0(*(s32 *) ((u8 *) player + 0x184)) ||
        (*(u8 **) ((u8 *) player + 0x38))[0x3B])
        return 0;
    if (bainput_func_80097B4C(player))
        return func_80110EFC(camera, 2);
    if (bainput_should_rotate_camera_left(player))
        return func_80110EFC(camera, 0);
    if (bainput_should_rotate_camera_right(player))
        return func_80110EFC(camera, 1);
    return 0;
}

// Select camera mode 6, 7 or 8 (water variants); returns 1 when handled.
s32 func_800A4978(void *player)
{
    s32 mode;
    if (func_800F40EC() != 2)
        return 0;

switch (func_800A3274(player)) {
    case 11:
        mode = 7;
        if ((*(u8 **) ((u8 *) player + 0x38))[3])
            (*(u8 **) ((u8 *) player + 0x38))[3] = 4;
        break;
    case 12:
        mode = 8;
        break;
    default:
        mode = 6;
        break;
}

func_800A3F14(player, mode);
func_800A4878(player);
func_800A4190(player);
return 1;

}

void func_800A4A14(s32 player)
{
    if (!func_800A4338(player)) {
        func_800A4190(player);
        func_800A4878(player);
    }

}

void func_800A4A4C(s32 player)
{
    func_800A4190();
    func_800A4878(player);
}
void func_800A4A74(s32 player)
{
    s32 player_copy;
    // Matching: the no-op "| 0" is needed for the match.
    player_copy = player | 0;

if (!func_800A4338(player_copy)) {
    if (!func_800A4978(player_copy)) {
        func_800A4190(player_copy);
        func_800A4878(player_copy);
        func_800A3F14(player_copy, 2);
    }
}

}

void func_800A4AD0(s32 player)
{
    s32 camera;
    camera = func_800A4CA8(player);

if (_ncbaspline_entrypoint_8(camera)) {
    func_800A3F14(player, 2);
}

}

// Per-frame camera controller update; dispatches on the camera mode.
void func_800A4B08(LocalPlayer *player)
{
    _batimer_decrement(player, 7);

if (func_800F65D0(player->index)) {
    func_80090C34(player);
}

func_80090C28(player, 0);

switch (player->ctrl->mode) {
    case 4:
        if (func_800A4338(player))
            return;
        if (player->ctrl->forced_type != 0) {
            func_800A3F14(player, 1);
            func_800A3B78(player, player->ctrl->forced_type);
        } else {
            func_800A3F14(player, 2);
        }
        break;
    case 1:
        func_800A4A14(player);
        break;
    case 3:
        func_800A4A4C(player);
        break;
    case 5:
        func_800A4AD0(player);
        break;
    default:
        if (player->ctrl->forced_type) {
            func_800A3F14(player, 1);
            func_800A3B78(player, player->ctrl->forced_type);
            break;
        }
        func_800A4A74(player);
    case 0:
    case 9:
        break;
}

player->ctrl->block_input = 0;
}

f32 *func_800A4C48(player)
PlayerState *player;
{
    return func_800A93F8(player->unk184);
}

void func_800A4C68(Actor *player)
{
    func_800A940C(player->unk184);
}

// Camera slot of the player (via PlayerState+0x184).
int func_800A4C88(player)
Actor *player;
{
    func_800A93E4(player->unk184);
}

// Camera instance of the player's camera slot, or 0.
PlayerState *func_800A4CA8(player)
PlayerState *player;
{
    PlayerState *slot = func_800A4C88(player);
    PlayerState *camera;

if (slot != 0) {
    camera = func_80110014(slot);
} else {

camera = 0;
}
return camera;
}

void func_800A4CE8(PlayerState *player, s32 unk_1)
{
    func_800CA7E4(func_800A4C48(player), unk_1);
}

int func_800A4D14(s32 player, s32 unk_1)
{
    u32 cam_obj;
    cam_obj = func_800A4C48(player);
    // Matching: the no-op "| 0" is needed for the match.
    func_800CA9D8(cam_obj | 0, unk_1);
}

int func_800A4D40()
{
    s32 slot;
    slot = func_800A4C88();
    // Matching: the no-op "| 0" is needed for the match.
    return func_8010FAE4(slot | 0) == 2;
}

// Set the zoom distance scales and apply the zoom.
void func_800A4D6C(u8 *player, f32 scale_xy, f32 scale_z)
{
    *((f32 *) (((char *) (*((s32 **) (((char *) player) + 0x38)))) + 0x2c)) = scale_xy;
    *((f32 *) (((char *) (*((s32 **) (((char *) player) + 0x38)))) + 0x30)) = scale_z;
    func_800A3BA8(player, 1);
}

// Request a forced camera type (mode 1) unless in mode 4 or 5.
void func_800A4DA4(PlayerState *player, s32 type)
{
    PlayerState *player_copy;
    s32 unused;
    *(*((u8 **) (((u8 *) player) + 0x38))) = type;
    {
        u8 mode = *((u8 *) ((*((u8 **) (((u8 *) player) + 0x38))) + (6 & 0xFF)));

if ((mode != 4) && (mode != 5)) {
    // Matching: the unused result and the helper copy are needed for the match.
    unused = func_800A3F14(player, 1);
    func_800A3B78(player_copy = player, type);
}

}
}

// Request scripted camera mode 3 with the given camera type.
void func_800A4DFC(PlayerState *player, s32 type)
{
    func_800A3F14(player, 3);
    func_800A3B78(player, type);
}

// Clear the forced type; back to mode 2 unless in mode 4 or 5.
// param_0 keeps its name: the QQ macro uses it.
void func_800A4E30(PlayerState *param_0)
{
    QQ->unk0 = 0;
    if ((QQ->unk6 != 4) && (QQ->unk6 != 5)) {
        func_800A3F14(param_0, 2);
    }
}

void func_800A4E74(s32 player)
{
    func_800A3F14(player, 0x5);
}

// Enter first-person camera (mode 9).
int func_800A4E94(s32 player)
{
    s32 camera;
    func_800A3F14(player, 9);
    camera = func_800A4CA8(player);
    // Matching: the no-op "| 0" is needed for the match.
    func_80110BF0(camera | 0);
}

// Leave first-person camera (back to mode 2).
int func_800A4EC8(s32 player)
{
    s32 camera;
    func_800A3F14(player, 2);
    camera = func_800A4CA8(player);
    // Matching: the no-op "| 0" is needed for the match.
    func_80110C2C(camera | 0);
}

// Pick the zoom level whose preset distance is closest to the given value.
void func_800A4EFC(u8 *player, f32 distance)
{
    f32 dist[3];
    s32 best;
    s32 i;
    f32 *dist_ptr;
    u8 *ctrl;

if (player != 0) {
    ctrl = *(u8 **) (player + 0x38);
    if (*(u8 *) (ctrl + 4) == 0) {
        dist[0] = mlAbsF(distance - (f32) *(s32 *) (ctrl + 8));
        dist[1] = mlAbsF(distance - (f32) *(s32 *) (*(u8 **) (player + 0x38) + 0x14));
        dist[2] = mlAbsF(distance - (f32) *(s32 *) (*(u8 **) (player + 0x38) + 0x20));
        best = 0;
        i = 1;
        dist_ptr = &dist[1];
        do {
            if (*dist_ptr < dist[best]) {
                best = i;
            }
            i += 1;
            dist_ptr += 1;
        } while (i != 3);
        func_800A3D78(player, best + 1, func_80090E30(player), best);
    }
}

}

// Enter first-person once, keeping a handle at +0x3C.
void func_800A5004(u8 *player)
{
    if (*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 0x3C) == 0) {
        *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x38) + 0x3C) = func_800CA334();
        func_800A4E94(player);
    }

}

// Leave first-person and release the handle.
int func_800A5044(void *player)
{
    if (*(s32 *) ((u8 *) *(u8 **) ((u8 *) player + 0x38) + 0x3C) != 0) {
        func_800A4EC8(player);
        func_800CA364(*(void **) ((u8 *) *(void **) ((u8 *) player + 0x38) + 0x3C));
        *(s32 *) ((u8 *) *(void **) ((u8 *) player + 0x38) + 0x3C) = 0;
    }

}

int func_800A5090(struct unk_struct_0 *player)
{
    return player->unk38->unk3C;
}

// Block camera zoom and rotate input for this frame.
int func_800A509C(s32 *player)
{
    s32 flag = 1;
    *((u8 *) (((char *) player[14]) + 59)) = (u8) flag;
}
