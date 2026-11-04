// Core of the player-following dynamic camera: allocates it with 25 components, runs the mode
// table (enter/update/exit) and per-frame update, and owns the damped position spring.
#include "core2/1EE9AB0.h"
#include "types.h"

extern s16 D_80137340[25];
extern s16 D_80137372;
typedef s32 (*D_80124950Entry)(void);
extern D_80124950Entry D_80124950[25];
extern void *heap_alloc(s32);
extern void func_8010FFB0(int, void *, void *);
extern void _ncba1p_entrypoint_1(void *);
extern void _ncbaspline_entrypoint_1(void *);
extern void func_8011337C(void *);
extern void func_80115FB0(void *);
extern void func_801125B8(void *);
extern void func_800EFD24(void *);
extern void func_80112398(void *);
extern void func_80113410();
extern void heap_free(void *ptr);
typedef void (*D_801247A0_func_t)(void *);
extern D_801247A0_func_t D_801247A0[][4];
typedef struct {
    char pad_0[0x68];
    void *unk68;
} Actor;
extern f32 func_800136E4(f32);
extern void func_800CA3A4(s32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800F5A00();
extern void func_8010FE14(s32, f32 *, f32 *);
extern s32 func_8010FF80(s32);
extern s32 func_800F6BE4(void *);
extern s32 func_800F6438(void *);
extern s32 func_800F6640(void *);
extern s32 func_800F6690(void *);
extern f32 func_80112550(void *, f32 *);
extern void func_80115D08(void *, f32, f32, f32, f32);
extern void func_8011539C(void *, f32, f32, f32);
extern void func_80116050(s32, f32);
extern void func_801125D8(s32, f32);
typedef struct {
    u8 local_0[14];
    s16 local_1;
} local_type;
extern void func_80114D98(void *);
extern f32 func_800F5AE0(s32);
extern f32 func_80115E88(void *);
extern void func_80112524(void *param_0, f32 *param_1);
extern s32 func_800F53D0(s32 param_0);
extern f32 func_800EEFFC(f32 *param_0);
extern void func_800A4EFC(s32 param_0, f32 param_1);
extern void _ncbastring_entrypoint_4(void *param_0);
extern void func_80115DEC(s32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800F1EA4(f32 *, f32 *);
extern s32 func_80112E84(void *);
extern s32 func_8011349C(f32 *, f32 *);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_80112D90(void *, f32, f32, s32, s32);
extern s32 func_80092BC4(void *);
extern f32 func_80092BD0(void *);
extern f32 func_800F5F24(s32);
typedef struct {
    u8 pad[0x34];
    f32 *local_0;
} State111410;
extern f32 func_80013728(f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F212C(f32, f32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF2A0(f32 *);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern s32 func_800EEEA8(f32 *);
extern s32 func_800D8FEC(void);
extern f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
extern f32 func_800A3048(s32 param_0);
void func_801106A8();
int func_80110720();
void func_80110790(u8 *, f32 *);
void func_80110970(s32 param_0, f32 param_1);
int func_80110A68();
void func_80110C88();
void func_80110CC0(void *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
s32 func_80111154(s32 param_0, f32 param_1);
s32 func_80111198(s32 param_0, f32 param_1);
int func_801111D0(void *param_0, f32 param_1);
f32 func_801112B0();
void func_80111348();
void func_801113B8();
void func_80111590(u8 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
void func_80111B8C(u8 *param_0, f32 param_1, f32 param_2);
void func_801120CC(u8 *param_0, f32 param_1, f32 param_2, f32 param_3);

// TU-NOTE: .rodata of this file starts with this 16-byte constant; its zero words belong
// to it (alignment in the ROM).
const struct {
    f32 x;
    f32 pad[3];
} D_80126540 = {0.2f};

// Dynamic camera object: allocation, modes, per-frame update, accessors, spring, 1p hooks.
// Computes the size of every camera component and the total block size.
void func_801101C0(void)
{
    s32 i, size, pad;
    D_80137372 = 0x98;
    for (i = 0; i < 25; i++) {
        D_80137340[i] = D_80124950[i]();
        size = D_80137340[i];
        if (size % 4)
            pad = 4 - size % 4;
        else
            pad = 0;
        D_80137372 = D_80137372 + size + pad;
    }
}

// Points the 25 component pointers of the header at their structs behind it.
void func_80110280(void **block)
{
    s32 offset, i, size, pad;
    offset = 0x98;
    for (i = 0; i < 25; i++) {
        *(void **) ((u32) block + (i << 2)) = (u8 *) block + offset;
        size = ((s16 *) D_80137340)[i];
        if (size % 4)
            pad = 4 - size % 4;
        else
            pad = 0;
        offset = offset + size + pad;
    }
}

u8 *func_80110424(s32 camera, s32 player)
{
    s32 size;
    u8 *dyn_cam;

    size = D_80137372;
    dyn_cam = heap_alloc(size);
    bzero(dyn_cam, size);
    func_80110280(dyn_cam);
    *(s32 *) ((s8 *) dyn_cam + 0x64) = camera;
    *(s32 *) ((s8 *) dyn_cam + 0x68) = player;
    func_80110720(dyn_cam, 1);
    func_8010FFB0(*(s32 *) ((s8 *) dyn_cam + 0x64), dyn_cam + 0x74, dyn_cam + 0x80);
    _ncba1p_entrypoint_1(dyn_cam);
    func_80112398(dyn_cam);
    _ncbaspline_entrypoint_1(dyn_cam);
    func_8011337C(dyn_cam);
    func_80111348(dyn_cam);
    func_80115FB0(dyn_cam);
    func_801125B8(dyn_cam);
    func_80110C88(dyn_cam);
    *(s32 *) ((s8 *) dyn_cam + 0x6C) = 0;
    *(s8 *) ((s8 *) dyn_cam + 0x72) = 0;
    *(s8 *) ((s8 *) dyn_cam + 0x71) = 0;
    func_800EFD24(dyn_cam + 0x8C);
    return dyn_cam;
}

void func_801104F4(Actor *dyn_cam)
{
    func_801106A8(dyn_cam, 0);
    func_80113410(dyn_cam);
    heap_free(dyn_cam);
}

int func_80110528(s32 dyn_cam)
{
    f32 focus[3];
    f32 rot[3];
    if (func_801138A0(dyn_cam)) {
        func_801138F4(dyn_cam);
    }
    func_80112524(dyn_cam, &focus);
    func_80110A68(dyn_cam, &rot, &focus);
    func_80110790(dyn_cam, &rot);
}

// Per-frame update.
void func_80110588(u8 *dyn_cam)
{
    f32 pos[3];
    f32 rot[3];
    s32 (*update_fn)(u8 *);

    if (*(u8 *) ((s8 *) dyn_cam + 0x70) != 0) {
        func_8011607C(dyn_cam, 0);
        if (*(u8 *) ((s8 *) dyn_cam + 0x72) == 0) {
            func_8011347C(dyn_cam);
            func_801123D4(dyn_cam);
            func_80115A9C(dyn_cam);
            func_80112A84(dyn_cam);
            func_801154A4(dyn_cam);
            func_80112648(dyn_cam);
            func_80114DD8(dyn_cam);
            func_80113D30(dyn_cam);
            update_fn = *(s32(**)(u8 *))((u8 *) (s32 *) D_801247A0 +
                                         (*(s32 *) ((s8 *) dyn_cam + 0x6C) * 0x10) + 4);
            if (update_fn != NULL) {
                update_fn(dyn_cam);
            }
        }
        func_800EFD24(dyn_cam + 0x8C);
        func_800EE7F8(pos, dyn_cam + 0x74);
        func_800EE7F8(rot, dyn_cam + 0x80);
        if (*(u8 *) ((s8 *) dyn_cam + 0x71) != 0) {
            _ncba1p_entrypoint_3(dyn_cam, pos, rot);
        }
        func_80116024(dyn_cam, rot);
        func_8010FE14(*(s32 *) ((s8 *) dyn_cam + 0x64), pos, rot);
        if (**(s32 **) ((s8 *) dyn_cam + 0x5C) != 0) {
            _ncbawaypoint_entrypoint_1(dyn_cam);
        }
    }
}

int func_801106A0(s32 dyn_cam[5])
{
    s32 mode;
    int result;
    mode = *(s32 *) ((s8 *) dyn_cam + 108);
    result = mode;
    return result;
}

// Switches the camera mode, calling the old mode's exit and the new mode's enter callback.
void func_801106A8(dyn_cam, new_mode) void *dyn_cam;
s32 new_mode;
{
    s32 old_mode;
    D_801247A0_func_t exit_fn;
    D_801247A0_func_t enter_fn;

    old_mode = *(s32 *) ((u8 *) dyn_cam + 0x6c);

    if (new_mode == old_mode) {
        return;
    }

    exit_fn = D_801247A0[old_mode][2];

    if (exit_fn) {
        exit_fn(dyn_cam);
    }

    enter_fn = D_801247A0[new_mode][0];

    if (enter_fn) {
        enter_fn(dyn_cam);
    }

    *(s32 *) ((u8 *) dyn_cam + 0x6c) = new_mode;
}

// Sets the active flag.
int func_80110720(dyn_cam, active)
s32 dyn_cam;
unsigned int active;
{
    int offset;
    u8 value;
    s32 addr;
    value = active;
    addr = dyn_cam;
    offset = 0x70;
    addr += offset;
    *((u8 *) addr) = value;
}

// Sets the first-person flag.
func_80110728(s32 dyn_cam, s32 enabled)
{
    u8 *base = dyn_cam;
    base[0x71] = enabled;
}

// Sets the frozen flag.
void func_80110730(u16 *dyn_cam, s32 frozen)
{
    ((u8 *) dyn_cam)[0x72] = frozen;
    func_80113410(dyn_cam);

    if (frozen != 0) {
        return;
    }

    func_8011337C(dyn_cam);
}

// Sets the position.
void func_80110770(u8 *dyn_cam, f32 *pos)
{
    func_800EE7F8(dyn_cam + 0x74, pos);
}

// Sets the rotation.
void func_80110790(u8 *dyn_cam, f32 *rot)
{
    func_800EE7F8(dyn_cam + 0x80, rot);
}

void func_801107B0(s32 dyn_cam)
{
    func_800F5A00(*(s32 *) (dyn_cam + 0x68));
}

void func_801107D0(Actor *dyn_cam)
{
    func_800F5B38(dyn_cam->unk68);
}

// Gets the position.
void func_801107F0(u8 *dyn_cam, f32 *out_pos)
{
    func_800EE7F8(out_pos, dyn_cam + 0x74);
}

// Gets the rotation.
void func_80110818(s32 dyn_cam, s32 out_rot)
{
    func_800EE7F8(out_rot, dyn_cam + 0x80);
}

// Gets the player.
int func_80110840(dyn_cam) void *dyn_cam;
{
    return ((int *) dyn_cam)[0x1A];
}

// Gets position and rotation.
int func_80110848(s32 dyn_cam, s32 out_pos, s32 out_rot)
{
    // Matching: `| 0` is needed for the match.
    func_800EE7F8(out_pos | 0, dyn_cam + 0x74);
    func_800EE7F8(out_rot, dyn_cam + 0x80);
}

// Gets the first-person flag.
func_80110888(u8 *dyn_cam)
{
    return dyn_cam[0x71];
}

// Gets the frozen flag.
func_80110890(u8 *dyn_cam)
{
    return dyn_cam[0x72];
}

// Gets the owner camera.
int func_80110898(dyn_cam)
s32 dyn_cam[5];
{
    return dyn_cam[25];
}

// Resets position and rotation from the owner camera and re-enters the current mode.
void func_801108A0(s32 dyn_cam)
{
    s32 mode;
    f32 pos[3];
    f32 rot[3];
    func_8010FFB0(*((s32 *) (dyn_cam + 0x64)), &pos, &rot);
    func_80110770(dyn_cam, &pos);
    func_80110790(dyn_cam, &rot);
    func_80111348(dyn_cam);
    mode = func_801106A0(dyn_cam);
    func_801106A8(dyn_cam, 0);
    func_801106A8(dyn_cam, mode);
    _ncba1p_entrypoint_1(dyn_cam);
    func_80112398(dyn_cam);
}

void func_80110928(void *dyn_cam)
{
    s32 pad0;
    f32 yaw;
    s32 unk_0;

    func_800F5B38(*(s32 *) ((u8 *) dyn_cam + 0x68), &unk_0);
    func_80110970(dyn_cam, func_800136E4(yaw + 180.0f));
}

// Repositions the camera at the player; only modes 2, 8, 0x11 and 0x13.
void func_80110970(s32 dyn_cam, f32 yaw)
{
    f32 pos[3];
    f32 rot[3];
    s32 mode = *(s32 *) (dyn_cam + 0x6C);

    if (mode == 8 || mode == 0x11 || mode == 0x13 || mode == 2) {
        func_800F5A00(*(s32 *) (dyn_cam + 0x68), pos);
        pos[1] += 100.0f;
        func_800EFA4C(rot, 0.0f, yaw, 0.0f);
        func_8010FE14(*(s32 *) (dyn_cam + 0x64), pos, rot);
        func_800CA3A4(func_8010FF80(*(s32 *) (dyn_cam + 0x64)), 300.0f);
        func_801108A0(dyn_cam);
    }
}

s32 func_80110A24(s32 dyn_cam, f32 out_rot[3], f32 pos[3])
{
    f32 focus[3];

    func_80112524(dyn_cam, focus);
    func_800A516C(out_rot, focus, pos);
    out_rot[2] = 0.0f;
}

int func_80110A68(dyn_cam, out_rot, focus)
s32 dyn_cam;
s32 out_rot;
s32 focus;
{
    // Matching: `| 0` is needed for the match.
    func_800A516C(out_rot | 0, focus | 0, dyn_cam + 0x74);
}

// Distance of a point from the camera center, minus the radius.
s32 func_80110A9C(void *dyn_cam, s32 point, f32 *out_dist)
{
    s8 _sfpad[8];
    s32 center;
    f32 delta[3];
    f32 radius;

    if ((((func_800F6BE4(*(s32 *) ((u8 *) dyn_cam + 0x68)) == 0) ||
          (func_800F6438(*(s32 *) ((u8 *) dyn_cam + 0x68)) == 0)) ||
         (func_800F6640(*(s32 *) ((u8 *) dyn_cam + 0x68)) == 0)) ||
        (func_800F6690(*(s32 *) ((u8 *) dyn_cam + 0x68)) == 0)) {
        return 0;
    }

    radius = func_80112550(dyn_cam, &center);
    func_800EFB24(delta, point, &center);
    *out_dist = sqrtf(((delta[0] * delta[0]) + (delta[1] * delta[1])) + (delta[2] * delta[2])) - radius;
    return 1;
}

void func_80110B68(void *dyn_cam, s32 enable)
{
    // Matching: the extra copy of the parameter is needed for the match.
    void *cam;
    cam = dyn_cam;

    if (enable != 0) {
        if (func_800F6BE4(*(void **) ((char *) cam + 0x68)) != 0) {
            func_800F7B9C(*(void **) ((char *) cam + 0x68), 0x6C);
            func_80093700(func_800F53D0(*(void **) ((char *) cam + 0x68)), 1);
        }
    }

    else {
        if (func_800F6BE4(*(void **) ((char *) cam + 0x68)) != 0) {
            func_800F7B9C(*(void **) ((char *) cam + 0x68), 0x6B);
            func_80093700(func_800F53D0(*(void **) ((char *) cam + 0x68)), 0);
        }
    }
}

void func_80110BF0(PlayerState *dyn_cam)
{
    s32 addr;
    addr = (s32) dyn_cam;
    _ncba1p_entrypoint_5(addr, 1);
    _ncba1p_entrypoint_6(addr, addr + 0x74);
    _ncba1p_entrypoint_7(addr, addr + 0x80);
}

void func_80110C2C(PlayerState *dyn_cam)
{
    s32 state;
    state = _ncba1p_entrypoint_10();

    if (state != 0 && state != 3) {
        if (*(u8 *) ((char *) dyn_cam + 0x72)) {
            _ncba1p_entrypoint_13(dyn_cam, (void *) ((char *) dyn_cam + 0x74),
                                  (void *) ((char *) dyn_cam + 0x80));
        }
        _ncba1p_entrypoint_5(dyn_cam, 3);
    }
}

// Sets the default camera presets.
void func_80110C88(dyn_cam) s32 dyn_cam;
{
    func_80110CC0(dyn_cam, 550.0f, 620.0f, 150.0f, 10.0f);
}

void func_80110CC0(void *dyn_cam, f32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
    func_8011539C(dyn_cam, param_1, param_2, param_3);
    func_80115D08(dyn_cam, param_1, param_2, param_3, param_4);
}

void func_80110D08()
{
    func_80115864();
}

void func_80110D28(s32 dyn_cam, s32 param_1)
{
    s32 value = param_1;
    func_80116050(dyn_cam, value);
}

int func_80110D58(s32 dyn_cam, f32 param_1)
{
    f32 value;
    value = param_1;
    func_801125D8(dyn_cam, value);
}

void func_80110D80()
{
    func_8011396C();
}

void func_80110DA0()
{
    func_80115460();
}

void func_80110DC0()
{
    func_8011546C();
}

void func_80110DE0()
{
    func_80115478();
}

// Action 0/1 rotates the camera by -45/+45 degrees, 2 resets it behind the player.
int func_80110E00(dyn_cam, action) void *dyn_cam;
s32 action;
{
    func_80114D98(dyn_cam);

    switch (action) {
        case 2:
            switch (((local_type *) D_801247A0)[*(s32 *) ((u8 *) dyn_cam + 0x6C)].local_1) {
                case 1:
                    func_80111198(dyn_cam, func_800F5AE0(*(s32 *) ((u8 *) dyn_cam + 0x68)));
                    break;
                case 2:
                    func_80111198(dyn_cam, func_80115E88(dyn_cam));
                    break;
            }
            return func_80111154(dyn_cam, func_801112B0(dyn_cam) + 180.0f);
        case 0:
            return func_801111D0(dyn_cam, -45.0f);
            break;
        case 1:
            return func_801111D0(dyn_cam, 45.0f);
            break;
    }

    return 0;
}

s32 func_80110EFC(s32 *dyn_cam)
{
    s32 mode;
    mode = dyn_cam[0x1b];

    if (((s16 *) D_801247A0)[mode * 8 + 6]) {
        return func_80110E00();
    }

    return 0;
}

void func_80110F44(void *dyn_cam)
{
    f32 focus[3];
    f32 pos[3];
    f32 offset[3];
    s32 unk_0;
    func_80112524(dyn_cam, focus);
    func_801107F0(dyn_cam, pos);
    func_800EFB24(offset, pos, focus);
    unk_0 = func_800F53D0((s32) func_80110840(dyn_cam));
    // Matching: the comma expression is needed for the match.
    func_800A4EFC((0, unk_0), func_800EEFFC(offset));

    if (((s32 *) dyn_cam)[27] == 0x11) {
        _ncbastring_entrypoint_4(dyn_cam);
    }
}

// Reallocates the block after defragmentation, relinking components if it moved.
void *func_80110FCC(void *dyn_cam, s32 camera)
{
    void *old;

    old = dyn_cam;
    dyn_cam = defrag(dyn_cam);

    if (old != dyn_cam) {
        func_80110280(dyn_cam);
    }

    *((s32 *) (((char *) dyn_cam) + 0x64)) = camera;
    return dyn_cam;
}

void func_80111018(s32 dyn_cam, s32 src)
{
    func_80113410();
    rare_memcpy(dyn_cam + 0x98, src + 0x98, D_80137372 - 0x98);
    func_8011337C(dyn_cam);
    _ncba1p_entrypoint_1(dyn_cam);
}

// Gets the velocity.
void func_8011106C(s32 dyn_cam, s32 out_vel)
{
    func_800EE7F8(out_vel, dyn_cam + 0x8C);
}

int func_80111094(s32 dyn_cam, s32 out_pos)
{
    // Matching: `| 0` is needed for the match.
    func_800EE780(out_pos | 0, dyn_cam + 0x74, dyn_cam + 0x8C);
}

// Sets the velocity to the vector from the position to target_pos.
void func_801110C4(s32 dyn_cam, s32 target_pos)
{
    func_800EFB24(dyn_cam + 0x8C, target_pos, dyn_cam + 0x74);
}

int func_801110EC(s32 dyn_cam, s32 param_1, s32 param_2)
{
    if (((s32 *) dyn_cam)[0x1B] == 0x14) {
        _ncbatarget_entrypoint_5(dyn_cam, param_1);
        _ncbatarget_entrypoint_4(dyn_cam, param_2);
    } else {
        return 0;
    }
    return 1;
}

// Matching: the `| 0` in the next three functions is needed for the match.
int func_8011113C()
{
    s32 result = 0;
    return result | 0;
}

int func_80111144()
{
    s32 result;
    result = 0;
    return result | 0;
}

int func_8011114C()
{
    s32 result;
    result = 0;
    return result | 0;
}

s32 func_80111154(s32 dyn_cam, f32 yaw)
{
    func_80112D90(dyn_cam, func_800136E4(yaw), 75.0f, 2, 2);
    return 1;
}

s32 func_80111198(s32 dyn_cam, f32 yaw)
{
    func_80115DEC(dyn_cam, func_800136E4(yaw), 75.0f);
    return 1;
}

// Turns the camera around the center by angle degrees.
int func_801111D0(void *dyn_cam, f32 angle)
{
    f32 pos[3];
    f32 offset[3];
    f32 center[3];
    f32 yaw;
    f32 new_yaw;
    f32 probe[3];
    func_801107F0(dyn_cam, pos);
    func_80112550(dyn_cam, center);
    func_800EFB24(offset, pos, center);
    func_800F1EA4(offset, &yaw);
    new_yaw = func_800136E4(yaw + angle);
    if (func_80112E84(dyn_cam) != 1) {
        func_800EF934(probe, offset, angle * D_80126540.x);
        func_800EF04C(probe, center);
        if (!func_8011349C(pos, probe))
            return 0;
    }
    func_80112D90(dyn_cam, new_yaw, 45.0f, 1, 2);
    return 1;
}

f32 func_801112B0(dyn_cam) void *dyn_cam;
{
    void *unk_0 = func_800F53D0(*(s32 *) ((u8 *) dyn_cam + 0x68));
    f32 yaw;
    if (func_80092BC4(unk_0) != 0) {
        yaw = func_80092BD0(unk_0) - 180.0f;
    } else {
        yaw = func_800F5F24(*(s32 *) ((u8 *) dyn_cam + 0x68));
    }
    return yaw;
}

int func_80111310()
{
    func_800A509C(func_800F53D0(func_80110840()) | 0);
}

s32 func_80111340()
{
    return 0x8C;
}

// Resets the spring component to its default parameters.
void func_80111348(dyn_cam) void *dyn_cam;
{
    func_801113B8(dyn_cam);
    func_80111590(dyn_cam, 10.0f, 10.0f, 120.0f, 120.0f);
    func_80111B8C(dyn_cam, 1.4f, 14.0f);
    func_801120CC(dyn_cam, 2000.0f, 4000.0f, -4000.0f);
}

void func_801113B8(dyn_cam) u8 *dyn_cam;
{
    func_800EFD24((*(s32 *) ((s8 *) (dyn_cam) + (0x34))) + 0x10);
    func_800EFD24((*(s32 *) ((s8 *) (dyn_cam) + (0x34))) + 0x24);
    func_800EFD24((*(s32 *) ((s8 *) (dyn_cam) + (0x34))) + 0x38);
    func_800EFD24((*(s32 *) ((s8 *) (dyn_cam) + (0x34))) + 0x44);
}

// Moves pos toward target; the per-axis speeds come from the spring component, speed_z is
// the z axis.
void func_80111410(State111410 *dyn_cam, f32 *target, f32 *pos, f32 speed_z)
{
    f32 delta[3];
    f32 dt;
    f32 dist;
    f32 step[3];
    f32 inv_dist;
    delta[0] = func_80013728(target[0] - pos[0]);
    delta[1] = func_80013728(target[1] - pos[1]);
    delta[2] = func_80013728(target[2] - pos[2]);
    dist = sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);

    if (dist != 0.0f) {
        dt = func_800D8FF8();
        inv_dist = 1.0f / dist;
        step[0] = (dyn_cam->local_0[2] * dt) * (delta[0] * inv_dist);
        step[1] = (dyn_cam->local_0[3] * dt) * (delta[1] * inv_dist);
        step[2] = (speed_z * dt) * (delta[2] * inv_dist);
        step[0] = func_800F212C(step[0], delta[0]);
        step[1] = func_800F212C(step[1], delta[1]);
        step[2] = func_800F212C(step[2], delta[2]);
        pos[0] += step[0];
        pos[1] += step[1];
        pos[2] += step[2];
    }
}

void func_80111590(u8 *dyn_cam, f32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
    (*(f32 **) (dyn_cam + 0x34))[0] = param_1;
    (*(f32 **) (dyn_cam + 0x34))[1] = param_2;
    (*(f32 **) (dyn_cam + 0x34))[2] = param_3;
    (*(f32 **) (dyn_cam + 0x34))[3] = param_4;
}

// Pure helpers: segment/plane crossing fraction and a frame-time 1D damped spring.
// Segment/plane test: plane normal and distance, segment start and end. On a crossing stores
// the crossing fraction in out_t and returns 1.
s32 func_801115C8(f32 *normal, f32 plane_dist, f32 *start, f32 *end, f32 *out_t)
{
    f32 start_dot;
    f32 end_dot;

    start_dot = func_800EEAA4(normal, start);
    end_dot = func_800EEAA4(normal, end);

    if ((((start_dot < plane_dist) && (plane_dist < end_dot)) || ((plane_dist < start_dot) && (end_dot < plane_dist))) &&
        (end_dot != start_dot)) {
        *out_t = (plane_dist - start_dot) / (end_dot - start_dot);
        return 1;
    }

    return 0;
}

// Damped spring toward target, integrated in 1/300 s substeps (5 per frame).
void func_80111680(f32 *target, f32 *pos, f32 *anchor, f32 *vel, f32 stiffness, f32 damping,
                   f32 *last_target)
{
    f32 displacement[3];
    f32 accel[3];
    f32 old_vel[3];
    f32 new_vel[3];
    f32 old_pos[3];
    f32 new_pos[3];
    f32 step[3];
    s32 i;
    s32 steps;
    // Matching: unk_0 and unk_1 are unused accumulators, needed for the match.
    f32 unk_0 = 0.0f;
    f32 unk_1 = 0.0f;
    f32 half;
    f32 side[3];
    f32 side_dist;
    f32 front_dist;
    f32 front[3];
    f32 up[3];
    s32 side_active = 0;
    s32 front_active = 0;
    f32 hit_t;

    if (func_800EEAD4(target, pos) < 0.01f) {
        func_800EE7F8(pos, target);
        func_800EFD24(vel);
    }

    if (func_800EEAD4(target, last_target) < 0.01f) {
        func_800EFB24(front, anchor, target);
        if (func_800EEEA8(front))
            func_800EFA4C(front, 1.0f, 0.0f, 0.0f);
        func_800EFA4C(up, 0.0f, 1.0f, 0.0f);
        func_800EE97C(side, front, up);
        func_800EF2A0(side);
        side_dist = func_800EEAA4(side, target);
        func_800EF2A0(front);
        front_dist = func_800EEAA4(front, target);
        side_active = front_active = 1;
    }

    steps = func_800D8FEC() * 5;
    half = 0.5f;
    for (i = 0; i < steps; i++) {
        func_800EFB24(displacement, target, pos);
        func_800EF334(displacement, stiffness);
        func_800EFB24(accel, displacement, vel);
        func_800EF334(accel, damping);
        func_800EE7F8(old_vel, vel);
        func_800EE7F8(new_vel, old_vel);
        func_800EF174(new_vel, accel, 0.0033333334f);
        func_800EE7F8(old_pos, pos);
        func_800EE780(step, old_vel, new_vel);
        func_800EF334(step, half * 0.0033333334f);

        if (side_active || front_active) {
            func_800EE780(new_pos, old_pos, step);
            if (side_active && func_801115C8(side, side_dist, pos, new_pos, &hit_t)) {
                func_800EF334(step, hit_t);
                side_active = 0;
                func_800EF174(new_vel, side, -func_800EEAA4(new_vel, side));
            } else if (front_active && func_801115C8(front, front_dist, pos, new_pos, &hit_t)) {
                func_800EF334(step, hit_t);
                front_active = 0;
                func_800EF174(new_vel, front, -func_800EEAA4(new_vel, side));
            }
        }

        func_800EE780(new_pos, old_pos, step);
        unk_1 += func_800EEAD4(vel, new_vel) / steps;
        func_800EE7F8(pos, new_pos);
        func_800EE7F8(vel, new_vel);
        unk_0 += func_800EEF94(step);
    }
    func_800EE7F8(last_target, target);
}

void func_80111A38(u8 *dyn_cam, f32 *target, f32 *pos)
{
    f32 center[3];
    u8 *spring;

    func_80112550(dyn_cam, center);
    spring = *(u8 **) (dyn_cam + 0x34);
    func_80111680(target, pos, center, spring + 0x24, *(f32 *) (spring + 0x30),
                  *(f32 *) (spring + 0x34), spring + 0x38);
}

void func_80111A98(u8 *dyn_cam)
{
    func_801107F0(dyn_cam, (f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x5C));
}

void func_80111ABC(u8 *dyn_cam, f32 *target)
{
    func_800EE7F8((f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x68), target);
}

extern void func_80113640(void *, f32 *, f32 *);

void func_80111AE0(u8 *dyn_cam, f32 *target)
{
    f32 pos[3];
    s32 camera;

    camera = func_80110898();
    func_801107F0(dyn_cam, pos);
    if (func_8010FFD0(camera) != 0) {
        func_800EFD24((*(s32 *) ((s8 *) (dyn_cam) + (0x34))) + 0x24);
        func_80113640(dyn_cam, pos, target);
        func_80110770(dyn_cam, target);
        return;
    }
    func_80111A98(dyn_cam);
    func_80111ABC(dyn_cam, target);
    func_80111A38(dyn_cam, target, pos);
    func_80110770(dyn_cam, pos);
}

// Scales the spring stiffness and damping by a factor from the player.
void func_80111B8C(u8 *dyn_cam, f32 stiffness, f32 damping)
{
    f32 scale;
    s32 unk_0;
    unk_0 = func_800F53E4(func_80110840());
    if (unk_0 != 0) {
        scale = func_800A3048(unk_0);
    } else {
        scale = 1.0f;
    }
    *(f32 *) ((char *) *(u8 **) ((char *) dyn_cam + 0x34) + 0x30) = (f32) (stiffness * scale);
    *(f32 *) ((char *) *(u8 **) ((char *) dyn_cam + 0x34) + 0x34) = (f32) (damping * scale);
}

void func_80111C04(u8 *dyn_cam)
{
    f32 unk_0;
    f32 unk_1;
    f32 dir_b;
    f32 unk_2;
    f32 unk_3;
    f32 dir_a;
    f32 dot;

    func_801107F0(dyn_cam, (*(u8 **) (dyn_cam + 0x34)) + 0x50);
    func_800EFB24(&dir_a, (*(u8 **) (dyn_cam + 0x34)) + 0x68, (*(u8 **) (dyn_cam + 0x34)) + 0x5C);
    func_800EFB24(&dir_b, (*(u8 **) (dyn_cam + 0x34)) + 0x50, (*(u8 **) (dyn_cam + 0x34)) + 0x5C);
    func_800EF2A0(&dir_a);
    func_800EF2A0(&dir_b);
    dot = func_800EEAA4(&dir_a, &dir_b);
    if ((dot < 0.0f) || (*(f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x74) < 0.0f)) {
        func_80110770(dyn_cam, (*(u8 **) (dyn_cam + 0x34)) + 0x5C);
    }
    *(f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x74) = dot;
}

int func_80111CC8(s32 dyn_cam, s32 target)
{
    f32 pos[3];
    f32 vel[3];
    s32 camera;
    camera = func_80110898(dyn_cam);
    func_801107F0(dyn_cam, pos);
    if (func_8010FFD0(camera) != 0) {
        func_800EFD24(*(u8 **) (dyn_cam + 0x34) + 0x24);
        func_80113640(dyn_cam, pos, target);
        func_80110770(dyn_cam, target);
        goto block_4;
    }
    func_80111A98(dyn_cam);
    func_80111ABC(dyn_cam, target);
    func_80111A38(dyn_cam, target, pos);
    func_8011106C(dyn_cam, vel);
    func_800EF04C(pos, vel);
    func_80110770(dyn_cam, pos);
    if (func_8011329C(dyn_cam) != 0) {
        func_80111C04(dyn_cam);
        return 1;
    }
block_4:
    return 0;
}

// Moves pos toward target at a limited speed.
void func_80111DB0(u8 *dyn_cam, f32 *target, f32 *pos, f32 *speed)
{
    f32 delta[3];
    f32 dist;
    f32 step;
    func_800EFB24(delta, target, pos);
    dist = func_800EEF94(delta);
    if (0.01f < dist) {
        step = func_800FF060(dist, speed, *(f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x80),
                             *(f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x84),
                             *(f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x7C), func_800D8FF8());

        if (dist < step) {
            step = dist;
            *speed = 0.0f;
        }

        func_800EF174(pos, delta, step / dist);
        return;
    }
    *speed = 0.0f;
}

// Damped spring on one value toward target.
void func_80111E88(f32 target, f32 *value, f32 *velocity, f32 stiffness, f32 damping)
{
    f32 dt;
    f32 next;
    f32 target_vel;
    f32 accel;
    dt = func_800D8FF8();
    if (target == *value) {
        *velocity = 0.0f;
        return;
    }
    target_vel = (target - *value) * stiffness;
    accel = (target_vel - *velocity) * damping;
    *velocity += accel * dt;
    next = *value + *velocity * dt;
    if (target < *value) {
        if (next < target) {
            next = target;
            *velocity = 0.0f;
        }

    } else {
        if (target < next) {
            next = target;
            *velocity = 0.0f;
        }
    }
    *value = next;
}

void func_80111F70(u8 *dyn_cam, u8 *target, f32 *pos, s32 speed, s32 y_velocity)
{
    f32 saved_y;

    saved_y = pos[1];
    func_80111DB0(dyn_cam, target, pos, speed);
    pos[1] = saved_y;
    func_80111E88(*(f32 *) (target + 4), &pos[1], y_velocity,
                  *(f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x30),
                  *(f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x34));
}

s32 func_80111FD4(u8 *dyn_cam, s32 *target)
{
    f32 pos[3];
    f32 vel[3];
    s32 camera;
    u8 *spring;
    camera = func_80110898();
    func_801107F0(dyn_cam, &pos);
    if (func_8010FFD0(camera) != 0) {
        *((f32 *) (((s8 *) (*((u8 **) (((s8 *) dyn_cam) + 0x34)))) + 0x78)) = 0.0f;
        func_80113640(dyn_cam, &pos, target);
        func_80110770(dyn_cam, target);
        goto block_4;
    }
    func_80111A98(dyn_cam);
    func_80111ABC(dyn_cam, target);
    {
        spring = *((u8 **) (((s8 *) dyn_cam) + 0x34));
        func_80111F70(dyn_cam, target, &pos, spring + 0x78, spring + 0x88);
    }
    func_8011106C(dyn_cam, &vel);
    func_800EF04C(&pos, &vel);
    func_80110770(dyn_cam, &pos);
    if (func_8011329C(dyn_cam) != 0) {
        func_80111C04(dyn_cam);
        return 1;
    }
block_4:
    return 0;
}

void func_801120CC(u8 *dyn_cam, f32 param_1, f32 param_2, f32 param_3)
{
    s32 unk_0;
    f32 scale;

    unk_0 = func_800F53E4(func_80110840());
    if (unk_0 != 0) {
        scale = func_800A3048(unk_0);
    } else {
        scale = 1.0f;
    }
    *(f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x7C) = param_1 * scale;
    *(f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x80) = param_2 * scale;
    *(f32 *) (*(u8 **) (dyn_cam + 0x34) + 0x84) = param_3 * scale;
}

// TU-NOTE: .data of this file is defined here in C. Its tables point to functions of this
// file, and IDO's assembler schedules some of those differently unless the tables are in the
// same unit. Values are taken from the ROM.
extern void _ncbaswim_entrypoint_2();
extern void _ncbaswim_entrypoint_3();
extern void _ncbaswim_entrypoint_1();
extern void _ncbafly_entrypoint_1();
extern void _ncbafly_entrypoint_3();
extern void _ncbafly_entrypoint_2();
extern void _ncbadive_entrypoint_1();
extern void _ncbadive_entrypoint_3();
extern void _ncbadive_entrypoint_2();
extern void _ncbafixpos_entrypoint_1();
extern void _ncbafixpos_entrypoint_3();
extern void _ncbafixpos_entrypoint_2();
extern void _ncbapan_entrypoint_1();
extern void _ncbapan_entrypoint_3();
extern void _ncbapan_entrypoint_2();
extern void _ncbadie_entrypoint_1();
extern void _ncbadie_entrypoint_4();
extern void _ncbadie_entrypoint_2();
extern void _ncbaclimb_entrypoint_1();
extern void _ncbaclimb_entrypoint_3();
extern void _ncbaclimb_entrypoint_2();
extern void _ncbadolly_entrypoint_1();
extern void _ncbadolly_entrypoint_3();
extern void _ncbadolly_entrypoint_2();
extern void _ncbaspline_entrypoint_2();
extern void _ncbaspline_entrypoint_4();
extern void _ncbaspline_entrypoint_3();
extern void _ncbaspiral_entrypoint_1();
extern void _ncbaspiral_entrypoint_3();
extern void _ncbaspiral_entrypoint_2();
extern void _ncbapivot_entrypoint_1();
extern void _ncbapivot_entrypoint_3();
extern void _ncbapivot_entrypoint_2();
extern void _ncbatarget_entrypoint_1();
extern void _ncbatarget_entrypoint_3();
extern void _ncbatarget_entrypoint_2();
extern void _ncbaledge_entrypoint_0();
extern void _ncbaledge_entrypoint_2();
extern void _ncbaledge_entrypoint_1();
extern void _ncbabee_entrypoint_0();
extern void _ncbabee_entrypoint_2();
extern void _ncbabee_entrypoint_1();
extern void _ncbaglide_entrypoint_0();
extern void _ncbaglide_entrypoint_2();
extern void _ncbaglide_entrypoint_1();
extern void _ncbasub_entrypoint_1();
extern void _ncbasub_entrypoint_2();
extern void _ncbasub_entrypoint_0();
extern void _ncbasuck_entrypoint_0();
extern void _ncbasuck_entrypoint_2();
extern void _ncbasuck_entrypoint_1();
extern void _ncbakaztorp_entrypoint_1();
extern void _ncbakaztorp_entrypoint_2();
extern void _ncbakaztorp_entrypoint_0();
extern void _ncba1p_entrypoint_0();
extern void func_80115EA0();
extern void func_80114D90();
extern void _ncbaclimb_entrypoint_0();
extern void _ncbadie_entrypoint_0();
extern void func_80115350();
extern void _ncbadive_entrypoint_0();
extern void _ncbadolly_entrypoint_0();
extern void _ncbafixpos_entrypoint_0();
extern void _ncbafly_entrypoint_0();
extern void func_80112E90();
extern void _ncbajig_entrypoint_0();
extern void func_80112160();
extern void _ncbapan_entrypoint_0();
extern void func_80115610();
extern void _ncbapivot_entrypoint_0();
extern void _ncbaspline_entrypoint_0();
extern void _ncbaspiral_entrypoint_0();
extern void func_801125B0();
extern void _ncbastring_entrypoint_0();
extern void _ncbaswim_entrypoint_0();
extern void _ncbatarget_entrypoint_0();
extern void _ncbawaypoint_entrypoint_0();
extern void func_801127A0();
// Camera mode table: 27 entries of {enter, update, exit, flags}.
D_801247A0_func_t D_801247A0[27][4] = {0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       (void *) _ncbaswim_entrypoint_2,
                                       (void *) _ncbaswim_entrypoint_3,
                                       (void *) _ncbaswim_entrypoint_1,
                                       (void *) 0x00010001,
                                       (void *) _ncbafly_entrypoint_1,
                                       (void *) _ncbafly_entrypoint_3,
                                       (void *) _ncbafly_entrypoint_2,
                                       0,
                                       (void *) _ncbadive_entrypoint_1,
                                       (void *) _ncbadive_entrypoint_3,
                                       (void *) _ncbadive_entrypoint_2,
                                       0,
                                       0,
                                       (void *) func_80110528,
                                       0,
                                       0,
                                       (void *) _ncbafixpos_entrypoint_1,
                                       (void *) _ncbafixpos_entrypoint_3,
                                       (void *) _ncbafixpos_entrypoint_2,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       (void *) _ncbapan_entrypoint_1,
                                       (void *) _ncbapan_entrypoint_3,
                                       (void *) _ncbapan_entrypoint_2,
                                       (void *) 0x00010000,
                                       0,
                                       0,
                                       0,
                                       0,
                                       (void *) _ncbadie_entrypoint_1,
                                       (void *) _ncbadie_entrypoint_4,
                                       (void *) _ncbadie_entrypoint_2,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       (void *) _ncbaclimb_entrypoint_1,
                                       (void *) _ncbaclimb_entrypoint_3,
                                       (void *) _ncbaclimb_entrypoint_2,
                                       (void *) 0x00010002,
                                       (void *) _ncbadolly_entrypoint_1,
                                       (void *) _ncbadolly_entrypoint_3,
                                       (void *) _ncbadolly_entrypoint_2,
                                       0,
                                       (void *) _ncbaspline_entrypoint_2,
                                       (void *) _ncbaspline_entrypoint_4,
                                       (void *) _ncbaspline_entrypoint_3,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       0,
                                       (void *) _ncbaspiral_entrypoint_1,
                                       (void *) _ncbaspiral_entrypoint_3,
                                       (void *) _ncbaspiral_entrypoint_2,
                                       0,
                                       (void *) _ncbapivot_entrypoint_1,
                                       (void *) _ncbapivot_entrypoint_3,
                                       (void *) _ncbapivot_entrypoint_2,
                                       (void *) 0x00010000,
                                       (void *) _ncbatarget_entrypoint_1,
                                       (void *) _ncbatarget_entrypoint_3,
                                       (void *) _ncbatarget_entrypoint_2,
                                       0,
                                       (void *) _ncbaledge_entrypoint_0,
                                       (void *) _ncbaledge_entrypoint_2,
                                       (void *) _ncbaledge_entrypoint_1,
                                       (void *) 0x00010000,
                                       (void *) _ncbabee_entrypoint_0,
                                       (void *) _ncbabee_entrypoint_2,
                                       (void *) _ncbabee_entrypoint_1,
                                       (void *) 0x00010001,
                                       (void *) _ncbaglide_entrypoint_0,
                                       (void *) _ncbaglide_entrypoint_2,
                                       (void *) _ncbaglide_entrypoint_1,
                                       (void *) 0x00010001,
                                       (void *) _ncbasub_entrypoint_1,
                                       (void *) _ncbasub_entrypoint_2,
                                       (void *) _ncbasub_entrypoint_0,
                                       (void *) 0x00010001,
                                       (void *) _ncbasuck_entrypoint_0,
                                       (void *) _ncbasuck_entrypoint_2,
                                       (void *) _ncbasuck_entrypoint_1,
                                       (void *) 0x00010002,
                                       (void *) _ncbakaztorp_entrypoint_1,
                                       (void *) _ncbakaztorp_entrypoint_2,
                                       (void *) _ncbakaztorp_entrypoint_0,
                                       (void *) 0x00010001};
// Component size getters.
D_80124950Entry D_80124950[25] = {(void *) _ncba1p_entrypoint_0,
                                  (void *) func_80115EA0,
                                  (void *) func_80114D90,
                                  (void *) _ncbaclimb_entrypoint_0,
                                  (void *) _ncbadie_entrypoint_0,
                                  (void *) func_80115350,
                                  (void *) _ncbadive_entrypoint_0,
                                  (void *) _ncbadolly_entrypoint_0,
                                  (void *) _ncbafixpos_entrypoint_0,
                                  (void *) _ncbafly_entrypoint_0,
                                  (void *) func_80112E90,
                                  (void *) _ncbajig_entrypoint_0,
                                  (void *) func_80112160,
                                  (void *) func_80111340,
                                  (void *) _ncbapan_entrypoint_0,
                                  (void *) func_80115610,
                                  (void *) _ncbapivot_entrypoint_0,
                                  (void *) _ncbaspline_entrypoint_0,
                                  (void *) _ncbaspiral_entrypoint_0,
                                  (void *) func_801125B0,
                                  (void *) _ncbastring_entrypoint_0,
                                  (void *) _ncbaswim_entrypoint_0,
                                  (void *) _ncbatarget_entrypoint_0,
                                  (void *) _ncbawaypoint_entrypoint_0,
                                  (void *) func_801127A0};
