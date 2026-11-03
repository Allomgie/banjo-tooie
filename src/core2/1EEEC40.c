#include "core2/1EEEC40.h"

typedef struct {
    u8 pad_0[0xC];
    f32 cur_min;
    f32 cur_max;
} T_115358;
typedef struct {
    u8 pad_0[0x14];
    T_115358 *state;
} S_115358;
typedef struct {
    u8 pad_0[0xC];
    f32 cur_min;
    f32 cur_max;
    f32 min_dist;
    f32 max_dist;
} S801154A4;
extern void func_801107F0();
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
f32 func_800EEB40(void *, s32);
void func_80115428(s32 *param_0, f32 param_1, f32 param_2);

s32 func_80115350()
{
    return 0x1C;
}

// Clamps dist to the current min/max distance.
f32 func_80115358(S_115358 *camera, f32 dist)
{
    T_115358 *state = camera->state;
    if (dist < state->cur_min) {
        dist = state->cur_min;
    } else if (state->cur_max < dist) {
        dist = state->cur_max;
    }
    return dist;
}

// Stores the preset distances and height and derives the min/max radial distances.
void func_8011539C(void *camera, f32 near_dist, f32 far_dist, f32 height)
{
    f32 *height_ref;
    f32 min_dist;
    f32 height_sq;
    *((f32 **) ((char *) camera + 0x14))[0] = near_dist;
    (*(f32 **) ((char *) camera + 0x14))[1] = far_dist;
    (*(f32 **) ((char *) camera + 0x14))[2] = height;
    // Matching: pointer to the parameter needed for the match.
    height_ref = &height;
    height_sq = height * *height_ref;
    min_dist = sqrtf((near_dist * near_dist) + height_sq);
    func_80115428(camera, min_dist, sqrtf((far_dist * far_dist) + height_sq));
}

void func_80115428(s32 *camera, f32 min_dist, f32 max_dist)
{
    *(f32 *) ((u8 **) camera[5] + 5) = min_dist;
    *(f32 *) ((u8 **) camera[5] + 6) = max_dist;
}

// Returns the current min/max distance.
void func_80115444(u8 *camera, f32 *min_out, f32 *max_out)
{
    *min_out = *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x14) + 0xC);
    *max_out = *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x14) + 0x10);
}

// Returns the preset height.
f32 func_80115460(void *camera)
{
    return ((f32 *) *(void **) ((char *) camera + 0x14))[2];
}

// Returns the preset near distance.
f32 func_8011546C(void *camera)
{
    return ((f32 *) *(void **) ((char *) camera + 0x14))[0];
}

// Returns the preset far distance.
f32 func_80115478(void *camera)
{
    return ((f32 *) *(void **) ((char *) camera + 0x14))[1];
}

void func_80115484(PlayerState *camera, f32 *out)
{
    func_80112524(camera, out);
}

// Lets the current min distance shrink toward the camera-target distance.
void func_801154A4(u8 *camera)
{
    f32 pos_b[3];
    f32 pos_a[3];
    f32 delta[3];
    f32 dist;

    if ((*(S801154A4 **) (camera + 0x14))->cur_min < (*(S801154A4 **) (camera + 0x14))->min_dist) {
        func_80115484(camera, pos_a);
        func_801107F0(camera, pos_b);
        func_800EFB24(delta, pos_b, pos_a);
        dist = func_800EEF94(delta);
        if ((*(S801154A4 **) (camera + 0x14))->min_dist < dist) {
            (*(S801154A4 **) (camera + 0x14))->cur_min = (*(S801154A4 **) (camera + 0x14))->min_dist;
        } else if ((*(S801154A4 **) (camera + 0x14))->cur_min < dist) {
            (*(S801154A4 **) (camera + 0x14))->cur_min = dist;
        }
    } else {
        (*(S801154A4 **) (camera + 0x14))->cur_min = (*(S801154A4 **) (camera + 0x14))->min_dist;
    }
    (*(S801154A4 **) (camera + 0x14))->cur_max = (*(S801154A4 **) (camera + 0x14))->max_dist;
}

// Resets the current min/max distance to the derived values.
void func_80115564(u8 *camera)
{
    u8 **state;
    u8 *state_copy;
    u8 **state_reload;
    // Matching: do-while (0) and the extra copy are needed for the match.
    do {
        state = *(u8 ***) ((u8 *) camera + 0x14);
        state_copy = (u8 *) state;
        *(f32 *) (state_copy + 0xC) = *(f32 *) (state_copy + 0x14);
    } while (0);
    state_reload = *(u8 ***) ((u8 *) camera + 0x14);
    *(f32 *) ((u8 *) state_reload + 0x10) = *(f32 *) ((u8 *) state_reload + 0x18);
}

// Returns whether target is farther than 1.5x the current max distance.
s32 func_80115580(u8 *camera, s32 target)
{
    f32 dist_sq;
    f32 limit;
    s32 cam_pos;

    func_801107F0(camera, &cam_pos);
    dist_sq = func_800EEB40(&cam_pos, target);
    limit = *(f32 *) ((u8 *) *(u8 **) (camera + 0x14) + 0x10) * 1.5f;
    return (limit * limit) < dist_sq;
}

// Returns 1.5x the current max distance.
f32 func_801155E8(void *camera)
{
    u32 *state = *(u32 **) ((u8 *) camera + 0x14);
    // Matching: the unused temporary is needed for the match.
    f32 cur_max = *(f32 *) ((u8 *) *(u32 **) ((u8 *) camera + 0x14) + 0x10);
    return *(f32 *) ((u8 *) state + 0x10) * 1.5f;
}
