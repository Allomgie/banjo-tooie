// Per-view camera lens helpers for up to 5 views: world/screen projection, FOV, aspect and zoom,
// and the cinematic letterbox bars.
#include "common.h"

extern f32 func_80015D14(s32);
extern s32 func_800A89A0();
extern f32 func_800A8AD4(s32);
extern s32 func_800A8984();
extern void func_800CA7E4(s32, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void *func_800CA7AC(s32);
extern void func_800F23D0(void *, f32 *, f32 *);
extern void func_800A8A04(s32, s32 *, s32 *, s32 *, s32 *);
extern f32 func_800CA79C(s32);
extern f32 func_800CA6FC(s32);
extern f32 func_800F214C(f32, f32);
extern void func_800EFD24(f32 *);
extern f32 func_800CA7B4(s32);
extern void *func_800CA7A4(s32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800139F8(f32);
extern f32 func_80013B7C(f32, f32);
extern void func_800A8A88(s32, f32);
extern float D_8012AA04[10];
// Letterbox bar state: 0 off, 1 opening, 2 open, 3 closing.
typedef struct {
    s32 value, step, target;
    u8 state;
    u8 pad_D[3];
} LocalView;
extern void func_800A8A44(s32, s32 *, s32 *, s32 *, s32 *);
typedef struct {
    s32 value, step, target;
    u8 state;
    u8 pad_D[3];
} EntryC54F0;
typedef struct {
    EntryC54F0 bars[5];
    f32 fov[5];
    s32 zoom[5];
    f32 aspect_offset;
    f32 fov_offset;
} State_8012A9A0;
// TU-NOTE: per-view state for 5 views, also accessed through casts (LocalView, LocalEntry,
// f32 index). D_8012AA04 is D_8012A9A0 + 0x64 (the zoom array).
State_8012A9A0 D_8012A9A0;
extern void func_80015CE8(s32, s32);
extern void func_800CA6F0(s32, s32);
extern void func_800CA558(s32, f32);
extern void func_800CA510(s32, f32);
extern void func_800CAF34(s32);
typedef struct {
    s32 current, step, maximum;
    u8 mode, pad_D[3];
} LocalEntry;
extern u8 D_8011A880[];
void func_800C54CC(s32 view_index, f32 fov, f32 zoom);

// Project/unproject, FOV and zoom per view, per-frame lens update into the view object.
// Adds camera-shake offsets to the per-frame FOV and aspect accumulators.
void func_800C4B90(s32 view_index, f32 fov_delta, f32 aspect_delta)
{
    s32 viewport_copy;
    f32 fov;
    s32 view;
    s32 viewport;
    f32 aspect_shift;
    view = func_800A8984();
    viewport = func_800A89A0(view_index);
    if ((viewport != 0) && (view != 0)) {
        viewport_copy = viewport;
        fov = func_800A8AD4(view_index);
        aspect_shift = func_80015D14(viewport_copy);
        aspect_shift = aspect_delta * aspect_shift;
        // Matching: the offset casts are needed for the match.
        *(f32 *) ((s8 *) (f32 *) &D_8012A9A0 + 0x7C) += (fov_delta * fov) / 40.0f;
        *(f32 *) ((s8 *) (f32 *) &D_8012A9A0 + 0x78) += aspect_shift / 1.3333334f;
    }
}

// World to screen projection. Returns 1 if the point is on screen; *in_front tells whether it is
// in front of the camera.
s32 func_800C4C34(s32 view_index, f32 *world_pos, f32 *screen_pos, s32 *in_front)
{
    f32 rel[3];
    f32 cam_pos[3];
    f32 focal;
    f32 inv_depth;
    f32 aspect;
    s32 x, y, width, height;
    s32 view;
    view = func_800A8984(view_index);
    func_800CA7E4(view, cam_pos);
    func_800EFB24(rel, world_pos, cam_pos);
    func_800F23D0(func_800CA7AC(view), rel, rel);
    *in_front = rel[2] < (-1e-05f);
    if (!*in_front) {
        screen_pos[0] = screen_pos[1] = 0.0f;
        return 0;
    }
    func_800A8A04(view_index, &x, &y, &width, &height);
    focal = func_800CA79C(view) * height * 0.5f;
    inv_depth = 1.0f / rel[2];
    aspect = (f32) width / height / func_800CA6FC(view);
    screen_pos[0] = width * 0.5f - rel[0] * focal * inv_depth * aspect;
    screen_pos[1] = rel[1] * focal * inv_depth + height * 0.5f;
    if (screen_pos[0] < 0 || width < screen_pos[0] || screen_pos[1] < 0 || height < screen_pos[1])
        return 0;
    screen_pos[0] += x;
    screen_pos[1] += y;
    return 1;
}

// Screen to world unprojection.
void func_800C4E58(s32 view_index, f32 *screen_pos, f32 *world_pos)
{
    f32 cam_pos[3];
    f32 inv_focal;
    f32 focal;
    f32 aspect;
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    s32 view;
    view = func_800A8984(view_index);
    func_800A8A04(view_index, &x, &y, &width, &height);
    focal = func_800CA79C(view) * height * 0.5f;
    if (func_800F214C(focal, 1e-05f) == 0.0f) {
        func_800EFD24(world_pos);
        return;
    }
    inv_focal = 1.0f / focal;
    aspect = (f32) width / height / func_800CA6FC(view);
    world_pos[2] = -func_800CA7B4(view) - screen_pos[2];
    world_pos[1] = (screen_pos[1] - height * 0.5f) * world_pos[2] * inv_focal;
    world_pos[0] = -(screen_pos[0] - width * 0.5f) * world_pos[2] * inv_focal / aspect;
    func_800F23D0(func_800CA7A4(view), world_pos, world_pos);
    func_800CA7E4(view, cam_pos);
    func_800EF04C(world_pos, cam_pos);
}

// Scales a position from 304x228 screen units to the viewport size.
void func_800C5008(s32 view_index, f32 *pos, f32 *scaled)
{
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    func_800A8A04(view_index, &x, &y, &width, &height);
    scaled[0] = pos[0] * ((f32) width / 304.0f);
    scaled[1] = pos[1] * ((f32) height / 228.0f);
}

// Sets the view FOV, compensating for a viewport height that differs from the full height.
void func_800C5094(s32 view_index, f32 fov)
{
    f32 x;
    f32 y;
    f32 width;
    s32 full_height;
    s32 height;

    func_800A8A44(view_index, &x, &y, &width, &full_height);
    func_800A8A04(view_index, &x, &y, &width, &height);
    if (full_height != height) {
        fov = 2.0f * func_80013B7C((f32) height, (f32) full_height / func_800139F8(fov * 0.5f));
    }
    func_800A8A88(view_index, fov);
}

// Sets the base FOV of a view and applies it.
void func_800C5148(s32 view_index, f32 fov)
{
    // Matching: extra copy of the parameter.
    f32 fov_copy;
    fov_copy = fov;
    D_8012A9A0.fov[view_index] = fov;
    func_800C5094(view_index, fov_copy);
}

// Gets the base FOV.
float func_800C517C(s32 view_index)
{
    return D_8012A9A0.fov[view_index];
}

// Gets the zoom.
float func_800C5190(s32 view_index)
{
    return D_8012AA04[view_index];
}

// Sets the zoom and re-applies the FOV.
void func_800C51A4(s32 view_index, f32 zoom)
{
    // Matching: extra copy of the parameter.
    f32 zoom_copy = zoom;
    f32 fov;
    f32 half_fov;
    D_8012AA04[view_index] = zoom_copy;
    if (zoom_copy != 1.0f) {
        fov = func_800C517C(view_index);
        half_fov = func_80013B7C(func_800139F8(fov * 0.5f), zoom);
        func_800C5094(view_index, half_fov + half_fov);
    } else {
        fov = func_800C517C(view_index);
        func_800C5094(view_index, fov);
    }
}

// Cinematic letterbox bars: start/stop state machine, viewport inset, bar drawing.
// Shrinks the viewport by bar_height at the top and bottom, then re-applies the FOV.
void func_800C524C(s32 view_index, s32 bar_height)
{
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    // Matching: stack padding needed for the match.
    s8 _sfpad[8];
    s32 viewport;
    s32 view;
    viewport = func_800A89A0(view_index);
    view = func_800A8984(view_index);
    func_800A8A44(view_index, &x, &y, &width, &height);
    func_80015B34(viewport, x, y + bar_height, width, height - (bar_height * 2));
    func_80015CE8(viewport, view);
    func_800C5148(view_index, D_8012A9A0.fov[view_index]);
}

// Starts opening the letterbox bars. Returns 0 if they are already opening or open. A step of 0
// opens them immediately.
s32 func_800C52F4(s32 view_index, s32 step)
{
    s32 content_height;
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    LocalView *bars;
    bars = &((LocalView *) &D_8012A9A0)[view_index];
    if (bars->state == 1 || bars->state == 2)
        return 0;
    bars->state = 1;
    bars->value = 0;
    bars->step = step;
    func_800A8A44(view_index, &x, &y, &width, &height);
    content_height = width * 0.5625f;
    if (content_height & 1)
        content_height++;
    bars->target = (height - content_height) / 2;
    if (!step) {
        bars->value = bars->target;
        bars->state = 2;
        func_800C524C(view_index, bars->target);
    }
    return 1;
}

// Starts closing the letterbox bars. Returns 0 if they are already closed or closing.
s32 func_800C53EC(s32 view_index, s32 step)
{
    u8 *bars;
    // Matching: the offset casts are needed for the match.
    bars = (view_index * 0x10) + (u8 *) (s32 *) &D_8012A9A0;
    if ((*(u8 *) ((s8 *) bars + 0xC) == 0) || (3 == *(u8 *) ((s8 *) bars + 0xC))) {
        return 0;
    }
    *(u8 *) ((s8 *) bars + 0xC) = 3U;
    *(s32 *) ((s8 *) bars + 4) = step;
    func_800C524C(view_index, 0);
    if (step == 0) {
        *(s32 *) ((s8 *) bars + 0) = 0;
    }
    return 1;
}

// Resets FOV to 40 and zoom to 1 for all 5 views.
void func_800C5464(void)
{
    float fov;
    float zoom;
    s32 i;
    s32 count;

    fov = 40.0f;
    zoom = 1.0f;
    i = 0;
    count = 5;

    do {
        func_800C54CC(i, fov, zoom);
        i += 1;
    } while (i != count);
}

// Sets FOV and zoom of a view without applying them.
void func_800C54CC(s32 view_index, f32 fov, f32 zoom)
{
    float *base = &((f32 *) &D_8012A9A0)[view_index];
    base[20] = fov;
    base[25] = zoom;
}

// Per-frame update: advances the letterbox bars, then applies FOV and aspect including the
// accumulated shake offsets.
void func_800C54F0(s32 view_index)
{
    f32 aspect;
    s32 viewport;
    s32 view;
    EntryC54F0 *bar;
    f32 fov, aspect_fov, final_fov;
    viewport = func_800A89A0();
    view = func_800A8984(view_index);
    bar = &D_8012A9A0.bars[view_index];
    switch (bar->state) {
        case 1:
            bar->value += bar->step;
            if (bar->value >= bar->target) {
                bar->value = bar->target;
                bar->state = 2;
                func_800C524C(view_index, bar->value);
            }
            break;
        case 3:
            bar->value -= bar->step;
            if (bar->value < 0) {
                bar->value = 0;
                bar->state = 0;
            }
    }
    if (viewport && view) {
        func_80015CE8(viewport, view);
        func_800CA6F0(view, ((s32 *) D_8012AA04)[view_index]);
        fov = func_800A8AD4(view_index);
        aspect = func_800CA6FC(view);
        final_fov = fov + D_8012A9A0.fov_offset;
        aspect_fov = aspect * fov + D_8012A9A0.aspect_offset;
        func_800CA558(view, final_fov);
        func_800CA510(view, aspect_fov / final_fov);
        func_800CAF34(view);
    }
    D_8012A9A0.fov_offset = 0.0f;
    D_8012A9A0.aspect_offset = D_8012A9A0.fov_offset;
}

// Draws the top and bottom letterbox bars as fill rectangles.
void func_800C5668(s32 view_index, void *gfx)
{
    f32 progress;
    LocalEntry *bar;
    s32 x, y, width, height;
    s32 bar_height;
    s32 alpha;
    bar = &((LocalEntry *) &D_8012A9A0)[view_index];
    if (bar->mode == 3 || bar->mode == 1) {
        func_800A8A04(view_index, &x, &y, &width, &height);
        bar_height = bar->current;
        progress = (f32) bar->current / bar->maximum;
        alpha = progress * 255.0f;
        func_800B9A24(gfx, alpha, D_8011A880, x, y, width, bar_height);
        func_800B9A24(gfx, alpha, D_8011A880, x, y + height - bar_height, width,
                      bar_height);
    }
}

// TU-NOTE: this .data object (formerly asm/data/core2/1E9E480.data.s) is defined here in C;
// values are taken from the ROM.
u8 D_8011A880[16] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                     0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
