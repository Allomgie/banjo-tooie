// Camera collision component of the dynamic camera: line-of-sight tests against map collision,
// push-out of geometry, alternative position search, side-wall probes and auto-rotation.
// TU-NOTE: second of three units split from the former 1EEC090 (func_80112E90..func_80113D30).
// Its .rodata (0x1EFFEA0..0x1EFFEC4) holds the constants and jump table of func_8011309C and
// the constants of func_801134F0, func_80113688 and func_80113978.
// TU-NOTE: functions defined in 1EEC090 are declared below exactly as defined there
// (prototype for ANSI, empty parameter list for K&R), so calls compile as in the combined file.
// Camera collision component of the dynamic camera (state at camera+0x28, size 0x80).
#include "core2/1EEC090.h"
#include <types.h>

extern f32 func_800136E4(f32);
typedef struct {
    u8 pad[12];
    s16 unk_C, unk_E;
    f32 unk_10, unk_14, unk_18, unk_1C, unk_20;
} State112A84;
typedef struct {
    u8 pad[0x60];
    State112A84 *unk_60;
} Actor112A84;
extern void func_801107F0(Actor112A84 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800F1A88(f32 *, f32 *);
typedef struct {
    u8 pad[0xC];
    s16 unk_C, unk_E;
    f32 unk_10, unk_14, unk_18, unk_1C, unk_20;
} Motion112D90;
typedef struct {
    u8 pad[0x60];
    Motion112D90 *unk_60;
} Actor112D90;
typedef struct {
    f32 *values;
    s32 count;
} Table112E98;
extern Table112E98 D_80124A38;
extern Table112E98 D_80124A40;
extern Table112E98 D_80124A48;
extern f32 func_800F0E00(f32, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_80110770(void *, f32 *);
extern void func_801113B8(void *);
typedef struct {
    u8 pad00[0x10];
    s32 mode;
} LocalSearch;
typedef struct {
    u8 pad00[0x28];
    LocalSearch *search;
} LocalOwner;
extern f32 func_800F5B64(s32, f32 *);
extern void func_800EF410(f32 *, f32 *);
extern void func_800EE7F8();
extern void func_800EFD24(f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
s32 func_800E8714(s32 param_0);
void func_800E8870(s32 param_0, f32 param_1);
extern s32 func_800C6C94(f32 *, f32, f32 *, s32);
extern f32 func_800EEFD4(f32 *);
extern void func_800EF174(s32 param_0, s32 param_1, f32 param_2);
typedef struct {
    s32 pad[2];
    s32 unk_8;
} Hit113688;
extern f32 func_800EEB40(f32 *, f32 *);
extern Hit113688 *func_800FAB50(f32 *, f32 *, f32 *, s32, f32);
extern Hit113688 *func_800FB3C0(f32 *, f32 *, f32, f32 *, s32, s32);
extern void func_800AAD28(f32[3][3]);
extern s32 func_80110060(s32);
f32 func_80013A7C(f32 param_0);
s32 func_800C6A7C(s32 param_0, s32 param_1, f32 *param_2, s32 param_3);
void func_800EF2A0(f32 *param_0);
extern float func_800EEF94(s32 *);
typedef struct {
    u8 pad0[0x14];
    u8 disabled;
    u8 pad15[3];
    s32 value18, value1C, value20, value24;
    u8 pad28[0x14];
    s32 count3C, count40, count44, count48;
    f32 point4C[3], point58[3], point64[3], point70[3];
    s32 direction7C;
} LocalControls;
typedef struct {
    u8 pad0[0x28];
    LocalControls *controls;
} LocalState;
extern s32 func_800F711C(s32);
extern f32 func_800F0DC0(f32, f32);
typedef struct {
    u8 pad0[0xC];
    s16 blocked_count;
    u8 padE[0xA];
    s32 unk_18[4];
    u8 pad28[0xC];
    u8 probe_id[4];
    s8 probe_result[4];
    s32 streak[4];
    f32 unk_4C[4][3];
} State113D30;
typedef struct {
    u8 pad0[0x28];
    State113D30 *state;
} Owner113D30;
extern void *func_80110840(Owner113D30 *);
extern void *func_80110898(Owner113D30 *);
extern void *func_8010FF80(void *);
extern void *func_800A940C(void *);
extern void func_800CA7E4(void *, f32 *);
extern void *func_800CA7A4(void *);
extern void mlMtxSet(void *);
extern void func_80019224(f32 *, f32 *);
extern void func_800E8830(s32, f32 *);
extern s32 func_800E8918(s32, void *, f32 *, s32);
extern s32 func_8001211C(void);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
void func_80113688();
void func_80114CF4();
void func_80112D90(Actor112D90 *param_0, f32 param_1, f32 param_2, s32 param_3, s32 param_4);
void func_80112E50(u8 *param_0, f32 param_1, s32 param_2);

// Size of the component state.
s32 func_80112E90()
{
    return 0x80;
}

// Sweeps an angle table for a camera position with a clear view of the target and applies it.
s32 func_80112E98(void *camera, f32 *target, f32 *dir, f32 dist, s32 sweep, u32 flags)
{
    f32 offset[3];
    f32 min_dist, angle;
    f32 hit[3];
    s32 unk_0; // Matching: unused local, needed for the match.
    f32 candidate[3];
    f32 *entry;
    Table112E98 *table;
    min_dist = func_800F0E00(150.0f, dist - 100.0f);
    switch (sweep) {
        case 1:
            table = &D_80124A40;
            break;
        case 2:
        case 3:
            table = &D_80124A48;
            break;
        case 0:
        default:
            table = &D_80124A38;
            min_dist = 150.0f;
            break;
    }
    for (entry = table->values; entry < table->values + table->count; entry++) {
        angle = *entry;
        if (sweep == 3)
            angle = -angle;
        func_800EFA20(offset, dir, -dist);
        func_800EF934(offset, offset, angle);
        func_800EE780(candidate, target, offset);
        func_800FAB50(target, candidate, hit, flags, 50.0f);
        func_800FB3C0(target, candidate, 50.0f, hit, 4, flags);
        if (func_800EEAD4(target, candidate) > min_dist) {
            func_80110770(camera, candidate);
            func_801113B8(camera);
            return 1;
        }
    }
    return 0;
}

s32 func_8011309C(LocalOwner *camera, s32 sweep)
{
    f32 hit[3];
    f32 dir[3];
    f32 delta[3];
    f32 target_pos[3];
    f32 anchor[3];
    f32 cam_pos[3];
    f32 side_offset[3];
    f32 ray_end[3];
    f32 dist;
    f32 unk_0;
    unk_0 = func_800F5B64(func_80110840(camera), target_pos);
    func_801107F0(camera, cam_pos);
    func_800EFB24(delta, target_pos, cam_pos);
    func_800EF410(dir, delta);
    func_800EE7F8(anchor, target_pos);
    dist = func_800EEF94(delta);
    if (1.5e+03f < dist) {
        func_800EFA20(delta, dir, 1.5e+03f);
        func_800EE780(anchor, cam_pos, delta);
    }
    switch (camera->search->mode) {
        case 0:
            func_800EFD24(side_offset);
            break;
        case 1:
            func_800EFA20(side_offset, dir, unk_0);
            func_800EF934(side_offset, side_offset, -90.0f);
            break;
        case 2:
            func_800EFA20(side_offset, dir, unk_0);
            func_800EF934(side_offset, side_offset, 90.0f);
            break;
        case 3:
            func_800EFA4C(side_offset, 0.0f, unk_0, 0.0f);
            break;
        case 4:
            func_800EFD24(side_offset);
            break;
    }
    func_800EE780(ray_end, side_offset, anchor);
    if (func_800C6A7C(cam_pos, ray_end, hit, 0x860020)) {
        camera->search->mode++;
        if (camera->search->mode >= 5) {
            camera->search->mode = 0;
            return func_80112E98(camera, target_pos, dir, dist, sweep, 0x860020);
        }
    } else {
        camera->search->mode = 0;
    }
    return 0;
}

int func_8011329C(s32 camera)
{
    f32 prev_pos[3];
    f32 pos[3];
    s32 unk_0;
    unk_0 = func_8010FFD0(func_80110898(camera));
    if (unk_0 != 0) {
        return 0;
    }
    func_801107F0(camera, &pos);
    func_800EE7F8(&prev_pos, &pos);
    func_80113688(camera, *(s32 *) (camera + 0x28), &pos);
    func_80110770(camera, &pos);
    return !func_800EECE0(&prev_pos, &pos);
}

int func_80113320(s32 camera)
{
    s32 unk_0;
    f32 target_pos[3];
    f32 hit[3];
    f32 end[3];
    s32 result;
    func_800EE7F8(end);
    unk_0 = func_800F5B64(func_80110840(camera), target_pos);
    // Matching: the dead reassignment and the extra temporary are needed for the match.
    unk_0 = 0;
    if (func_800C6A7C(target_pos, end, hit, 0x860020) != unk_0) {
        result = unk_0;
        return result;
    }
    return 1;
}

// Resets the state and creates the four side probes.
void func_8011337C(u8 *camera)
{
    s32 i;

    func_801107F0(camera, *(u8 **) ((s8 *) camera + 0x28));
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x28) + 0x10) = 0;
    i = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x28) + 0x14) = 0;
    do {
        *(u8 *) ((s8 *) (*(u8 **) ((s8 *) camera + 0x28) + i) + 0x34) = func_800E8714(1);
        func_800E8870(*(u8 *) ((s8 *) (*(u8 **) ((s8 *) camera + 0x28) + i) + 0x34), 10.0f);
        i += 1;
    } while (i != 4);
}

// Releases the four side probes.
void func_80113410(u8 *camera)
{
    s32 i;
    u8 probe_id;

    i = 0;
    do {
        probe_id = *(u8 *) ((s8 *) (*(s32 *) ((s8 *) camera + 0x28) + i) + 0x34);
        if (probe_id != 0) {
            func_800E87E0(probe_id);
            *(s8 *) ((s8 *) (*(s32 *) ((s8 *) camera + 0x28) + i) + 0x34) = 0;
        }
        i += 1;
    } while (i != 4);
}

void func_8011347C(void *camera)
{
    func_801107F0(camera, *(s32 *) ((char *) camera + 0x28));
}

// Line-of-sight test: returns 1 if nothing blocks from -> to.
s32 func_8011349C(f32 *from, f32 *to)
{
    f32 end[3];
    f32 hit[3];

    func_800EE7F8(end, to);
    if (func_800FAB50(from, end, hit, 0x820020, 50.0f) != 0) {
        return 0;
    }
    return 1;
}

// Pushes pos out of geometry within radius.
void func_801134F0(f32 *pos, f32 radius)
{
    f32 push[3];
    s32 iter = 0;
    f32 min_len;
    if (func_800C6C94(pos, radius, push, 0x820020)) {
        min_len = 0.01f;
        for (;;) {
            if (func_800EEFD4(push) < min_len)
                return;
            func_800EF174(pos, push, 1.5f);
            iter++;
            if (!func_800C6C94(pos, radius, push, 0x820020))
                break;
            if (iter == 1)
                break;
        }
    }
}

void func_801135D0(s32 *old_start, s32 *old_end, s32 *start, s32 end, s32 normal)
{
    s32 cur_delta[3];
    s32 old_delta[3];
    s32 diff[3];
    f32 neg_val;

    func_800EFB24(cur_delta, end, start);
    func_800EFB24(old_delta, old_end, old_start);
    func_800EFB24(diff, cur_delta, old_delta);
    neg_val = -func_800EEAA4(normal, diff);
    func_800EF174(end, normal, neg_val);
}

void func_80113640(s32 camera, s32 from, s32 to)
{
    u8 hit[12];
    func_800FAB50(from, to, hit, 0x820020, 45.0f);
}

// Moves end out of geometry hit by the start -> end segment.
// TU-NOTE: K&R definition, declared without prototype in the other units.
void func_80113688(camera, start, end) s32 camera;
f32 *start;
f32 *end;
{
    f32 normal[3];
    f32 orig_start[3];
    f32 orig_end[3];
    Hit113688 *hit;
    Hit113688 *sweep_hit;
    f32 mtx[3][3];
    func_801134F0(start, 45.0f);
    if (func_800EEB40(start, end) < 0.0001f)
        return;
    func_800EE7F8(orig_start, start);
    func_800EE7F8(orig_end, end);
    hit = func_800FAB50(orig_start, orig_end, normal, 0x820020, 45.0f);
    if (!hit)
        sweep_hit = func_800FB3C0(orig_start, orig_end, 45.0f, normal, 3, 0x820020);

    if (hit || sweep_hit) {
        func_800AAD28(mtx);
        func_80114CF4(func_80110060(func_80110898(camera)), mtx,
                      hit ? hit->unk_8 : sweep_hit->unk_8, normal);
        func_801135D0(orig_start, orig_end, start, end, normal);
        func_800FAB50(start, end, normal, 0x820020, 45.0f);
    }
}

// Returns 1 and writes an avoidance angle when a wall is hit along target_pos -> point.
int func_801137E4(void *camera, f32 *target_pos, f32 *cam_pos, f32 *point, f32 *out_angle)
{
    f32 hit[3];
    f32 dir[3];
    f32 dot;

    if (func_800C6A7C(target_pos, point, &hit, 0x860020)) {
        func_800EFB24(&dir, point, cam_pos);
        func_800EF2A0(&dir);
        dot = func_800EEAA4(&dir, &hit);
        if (dot < 0.0f) {
            return 0;
        }
        {
            out_angle[0] = 90.0f - func_80013A7C(dot) + 5.0f;
            return 1;
        }
    }

    return 0;
}

// True after 5 consecutive frames with the blocked-probe count at 4.
s32 func_801138A0(u8 *camera)
{
    u8 *state;

    state = (*(u8 **) ((s8 *) (camera) + (0x28)));

    if (*(u8 *) ((s8 *) state + 0x14) != 0) {
        return 0;
    }

    if (*(s16 *) ((s8 *) state + 0xC) >= 4) {
        *(s16 *) ((s8 *) state + 0xE) = (s16) (*(s16 *) ((s8 *) state + 0xE) + 1);
    } else {
        (*(s16 *) ((s8 *) (state) + (0xE))) = 0;
    }
    return (*(s16 *) ((s8 *) ((*(u8 **) ((s8 *) (camera) + (0x28)))) + (0xE))) >= 5;
}

void func_801138F4(s32 camera)
{
    s32 target_pos[3];
    s32 cam_pos[3];
    s32 delta[3];
    s32 dir[3];

    func_80112550(camera, target_pos);
    func_801107F0(camera, cam_pos);
    func_800EFB24(delta, target_pos, cam_pos);
    func_800EF410(dir, delta);
    func_80112E98(camera, target_pos, dir, func_800EEF94(delta), 0, 0x20020);
}

// Sets the disabled flag of the component.
void func_8011396C(void *camera, s32 value)
{
    ((s8 *) (*(void **) ((char *) camera + 0x28)))[20] = value;
}

// Rotates the camera away from side walls; returns a pitch correction.
f32 func_80113978(LocalState *camera, s32 do_yaw, s32 do_pitch)
{
    f32 target_pos[3];
    f32 cam_pos[3];
    s32 target_obj;
    f32 pitch;
    s32 cam_obj;
    target_obj = func_80110840(camera);
    pitch = 0.0f;
    cam_obj = func_8010FF80(func_80110898(camera));
    if (!func_800F711C(target_obj) || camera->controls->disabled)
        return 0.0f;
    func_80112550((PlayerState *) camera, target_pos);
    func_800CA7E4(cam_obj, cam_pos);
    if (do_yaw) {
        s32 side;
        s32 hits;
        s32 found;
        f32 angle;
        f32 turn;
        f32 angles[2];
        f32 new_pos[3];
        f32 to_cam[3];
        hits = 0;
        side = 0;
        found = 0;

        if (camera->controls->count40 >= 4) {
            hits++;
            side--;
        }

        if (camera->controls->count48 >= 4) {
            hits++;
            side++;
        }

        angle = 0.0f;

        if (hits) {
            if (!side)
                side = camera->controls->value24 < camera->controls->value1C ? 1 : -1;
            if (side < 0) {
                if (func_801137E4(camera, target_pos, cam_pos, camera->controls->point58, &angle))
                    found = 1;
            } else {
                if (func_801137E4(camera, target_pos, cam_pos, camera->controls->point70, &angle))
                    found = 1;
            }
        }

        if (found) {
            func_800EFB24(to_cam, cam_pos, target_pos);
            func_800F1A88(to_cam, angles);
            turn = (side < 0 ? -1.0f : 1.0f) * angle;
            func_800EF934(new_pos, to_cam, turn * 0.2f);
            func_800EF04C(new_pos, target_pos);
            if (func_8011349C(cam_pos, new_pos)) {
                func_80112D90(camera, func_800136E4(angles[1] + turn), angle * 0.25f, 1, 1);
                camera->controls->direction7C = side;
            }
        } else if (camera->controls->direction7C) {
            func_80112E50(camera, camera->controls->direction7C * 2.5f, 1);
            camera->controls->direction7C = 0;
        }
    }
    if (do_pitch) {
        s32 side;
        s32 hits;
        s32 found;
        f32 angle;
        hits = 0;
        side = 0;
        found = 0;
        if (camera->controls->count44 >= 4) {
            hits++;
            side--;
        }

        if (camera->controls->count3C >= 4) {
            hits++;
            side++;
        }

        angle = 0.0f;

        if (hits) {
            if (!side)
                side = camera->controls->value18 < camera->controls->value20 ? 1 : -1;
            if (side < 0) {
                if (func_801137E4(camera, target_pos, cam_pos, camera->controls->point64, &angle))
                    found = 1;
            } else {
                if (func_801137E4(camera, target_pos, cam_pos, camera->controls->point4C, &angle))
                    found = 1;
            }
        }

        if (found)
            pitch = func_800F0DC0(angle, 10.0f);
    }
    return pitch;
}

// Places the four side probes around the target and counts how many stay blocked.
void func_80113D30(Owner113D30 *camera)
{
    f32 dir[3];
    f32 delta[3];
    f32 target_pos[3];
    f32 origin[3];
    f32 cam_pos[3];
    f32 offset[3];
    f32 probe_pos[3];
    s32 i;
    f32 dist;
    void *target_obj;
    void *cam_obj;
    void *unk_0;
    target_obj = func_80110840(camera);
    cam_obj = func_8010FF80(func_80110898(camera));
    unk_0 = func_800A940C(target_obj);
    dist = func_80112550((PlayerState *) camera, target_pos);
    func_800CA7E4(cam_obj, cam_pos);
    func_800EFB24(delta, target_pos, cam_pos);
    func_800EF410(dir, delta);
    func_800EE7F8(origin, target_pos);
    mlMtxSet(func_800CA7A4(cam_obj));
    for (i = 0; i < 4; i++) {
        switch (i) {
            case 0:
                func_800EFA4C(offset, 0.0f, -dist, 0.0f);
                break;
            case 1:
                func_800EFA4C(offset, dist, 0.0f, 0.0f);
                break;
            case 2:
                func_800EFA4C(offset, 0.0f, dist, 0.0f);
                break;
            case 3:
                func_800EFA4C(offset, -dist, 0.0f, 0.0f);
        }

        func_80019224(offset, offset);
        func_800EE780(probe_pos, offset, origin);
        func_800E8830(camera->state->probe_id[i], probe_pos);
        camera->state->probe_result[i] = func_800E8918(
            camera->state->probe_id[i], unk_0, camera->state->unk_4C[i], 0);

        if (camera->state->probe_result[i] == 0) {
            if (camera->state->unk_18[i] == 0) {
                camera->state->unk_18[i] = func_8001211C();
            }
            camera->state->streak[i]++;
        } else {
            camera->state->unk_18[i] = 0;
            // Matching: copying the zero just stored is needed for the match.
            camera->state->streak[i] = camera->state->unk_18[i];
        }
    }
    camera->state->blocked_count = 0;
    // Matching: the start value is read back from memory, needed for the match.
    for (i = camera->state->blocked_count; i < 4; i++) {
        if (camera->state->streak[i] >= 4) {
            camera->state->blocked_count++;
        }
    }
}

// TU-NOTE: the .data of this file is defined here in C; values taken from the ROM.
u32 D_801249C0[1] = {0x0};
u32 D_801249C4[11] = {0x0,        0xC1C80000, 0x41C80000, 0xC2480000, 0x42480000, 0xC2A00000,
                      0x42A00000, 0xC2F00000, 0x42F00000, 0xC30C0000, 0x430C0000};
u32 D_801249F0[18] = {0x0,        0x41A00000, 0x42200000, 0x42700000, 0x42A00000, 0x42C80000,
                      0x42F00000, 0x430C0000, 0x43200000, 0x43340000, 0x43480000, 0x435C0000,
                      0x43700000, 0x43820000, 0x438C0000, 0x43960000, 0x43A00000, 0x43AA0000};
Table112E98 D_80124A38 = {(void *) &D_801249C0, 0x1};
Table112E98 D_80124A40 = {(void *) &D_801249C4, 0xB};
Table112E98 D_80124A48 = {(void *) &D_801249F0, 0x12};
