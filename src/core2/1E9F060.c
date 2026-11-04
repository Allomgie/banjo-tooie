// Probably two things: a timed fade of the map model tint colour, and the 0xA0-byte
// ground/water tracker the player physics allocates (floor and water height from vertical
// ray probes, 4-mode state machine).
#include "common.h"

extern u8 D_8012AA20[];
void func_800BF48C();
typedef struct {
    f32 time_left;
    f32 duration;
    u8 color[3];
    u8 target[3];
    u8 start[3];
    u8 active;
} StateC57F0;
extern f32 func_800D8FF8(void);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
// Heights: -18000 means no floor, -19000 means no water.
typedef struct {
    s32 unk_0;
    s16 unk_4[3], unk_A;
    s32 unk_C;
    s16 unk_10[3], unk_16;
    s32 unk_18;
    f32 unk_1C[3][3];
    u8 unk_40[3][4];
    f32 pos[3], prev_pos[3], floor_normal[3];
    f32 floor_height, water_height, ray_top;
    s32 floor_flags, water_flags;
    u32 floor_filter, water_filter;
    s16 unk_8C;
    u8 floor_found, water_found, prev_floor_found, prev_water_found, unk_92, search_timer, mode, unk_95;
    u8 pad_96[6];
    u8 fixed_water;
    u8 pad_9D[3];
} GroundState;
extern void func_800EE7F8();
extern s32 func_8001210C(s32);
extern void func_800EFD24(f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct CollisionC5 CollisionC5;
typedef struct HitC5 HitC5;
extern f32 mlAbsF(f32);
extern void func_800AAAE0();
extern void func_800AAD28();
extern int D_8011A890[];
// Views of GroundState used by some functions.
typedef struct {
    u8 pad_0[0x10];
    u8 unk_10;
    u8 pad_11[0x63];
    f32 water_height;
    u8 pad_78[8];
    u32 water_flags;
    u8 pad_84[0xB];
    u8 water_found;
    u8 pad_90[8];
    f32 fixed_water_height;
    u8 fixed_water;
} S_C5FCC;
typedef struct {
    u8 pad_0[8];
    u32 flags;
} T_C5FCC;
extern void func_800FB508();
typedef struct {
    u8 pad_0[0x4C];
    f32 pos[3];
    s32 pad_58;
    f32 prev_y;
    u8 pad_60[0x10];
    f32 floor_height, water_height, ray_top;
    u8 pad_7C[8];
    u32 floor_filter, water_filter;
    u8 pad_8C[0x10];
    u8 fixed_water;
} StateC6060;
typedef struct {
    u8 pad_0[8];
    s32 flags;
} TriangleC6060;
extern s32 func_800DA298(s32);
// Result buffer filled by func_800C5BE4.
typedef struct {
    f32 normal[3];
    f32 height;
    u32 flags;
    u16 unk_14, unk_16;
    void *unk_18;
} GroundHit;
extern void func_800C6320(GroundState *), func_800C6420(GroundState *);

// Map model tint colour with a timed fade (ticked from the main loop in 1EC3810).
void func_800C5770(void)
{
}

// Resets the tint to white with no fade running.
void func_800C5778(void)
{
    f32 zero = 0.0f;
    // Matching: the (int *) cast is needed for the match.
    u8 *fade = (u8 *) (int *) D_8012AA20;
    fade[0x11] = 0;
    fade[0x10] = 0xFF;
    *(f32 *) (fade + 4) = zero;
    fade[8] = (fade[9] = (fade[0xA] =
                              (fade[0xB] = (fade[0xC] = (fade[0xD] = (fade[0xE] = (fade[0xF] = 0xFF)))))));
    *(f32 *) fade = *(f32 *) (fade + 4);
}

// Applies the current tint to the map model.
void func_800C57C0()
{
    func_800BF48C(D_8012AA20[8], D_8012AA20[9], D_8012AA20[10]);
}

// Per-frame step of the tint fade.
void func_800C57F0(void)
{
    s32 i;
    if ((*(StateC57F0 *) D_8012AA20).active) {
        (*(StateC57F0 *) D_8012AA20).time_left =
            func_800F0E00(0.0f, (*(StateC57F0 *) D_8012AA20).time_left - func_800D8FF8());
        for (i = 0; i < 3; i++) {
            (*(StateC57F0 *) D_8012AA20).color[i] = (u32) func_800F10B4(
                (*(StateC57F0 *) D_8012AA20).time_left, (*(StateC57F0 *) D_8012AA20).duration, 0.0f,
                (f32) (u32) (*(StateC57F0 *) D_8012AA20).start[i],
                (f32) (u32) (*(StateC57F0 *) D_8012AA20).target[i]);
        }
        func_800C57C0();
        if ((*(StateC57F0 *) D_8012AA20).time_left == 0.0f)
            (*(StateC57F0 *) D_8012AA20).active = 0;
    }
}

// Sets the map tint; a nonzero duration fades from the current color.
void func_800C5968(int r, int g, int b, f32 duration)
{
    if (duration != 0.0f) {
        *(u8 *) ((u8 *) &D_8012AA20 + 0x11) = 1;
        *(f32 *) ((u8 *) &D_8012AA20 + 0) = duration;
        *(f32 *) ((u8 *) &D_8012AA20 + 4) = duration;
        *(u8 *) ((u8 *) &D_8012AA20 + 0xB) = r;
        *(u8 *) ((u8 *) &D_8012AA20 + 0xC) = g;
        *(u8 *) ((u8 *) &D_8012AA20 + 0xD) = b;
        *(u8 *) ((u8 *) &D_8012AA20 + 0xE) = (u8) *(u8 *) ((u8 *) &D_8012AA20 + 8);
        *(u8 *) ((u8 *) &D_8012AA20 + 0xF) = (u8) *(u8 *) ((u8 *) &D_8012AA20 + 9);
        *(u8 *) ((u8 *) &D_8012AA20 + 0x10) = (u8) *(u8 *) ((u8 *) &D_8012AA20 + 0xA);
        return;
    }
    *(u8 *) ((u8 *) &D_8012AA20 + 0x11) = 0;
    *(u8 *) ((u8 *) &D_8012AA20 + 8) = r;
    *(u8 *) ((u8 *) &D_8012AA20 + 9) = g;
    *(u8 *) ((u8 *) &D_8012AA20 + 0xA) = b;
    func_800C57C0();
}

// Sets the map tint immediately.
s32 func_800C59F0(s32 r, s32 g, s32 b)
{
    func_800C5968(r, g, b, 0);
}

// Player ground/water tracker: alloc/free, update state machine, getters/setters.
// Switches the tracker mode (1 searching, 2 airborne, 3 grounded, 4 swimming).
func_800C5A10(u8 *ground, s32 mode)
{
    if (mode == 1) {
        ground[0x93] = 5;
    }
    if (mode == 4) {
        ground[0x92] = 1;
    }
    ground[0x94] = mode;
}

GroundState *func_800C5A38(void)
{
    GroundState *ground;
    s32 i, j;
    ground = heap_alloc(sizeof(GroundState));
    func_800EFD24(ground->pos);
    func_800EFD24(ground->prev_pos);
    for (i = 0; i < 3; i++)
        func_800EFD24(ground->unk_1C[i]);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            ground->unk_40[i][j] = 255;
        }
    }
    for (i = 0; i < 3; i++) {
        ground->unk_4[i] = 0;
        ground->unk_10[i] = 0;
    }
    ground->unk_A = ground->unk_16 = 0;
    ground->unk_18 = 0;
    ground->unk_C = 0;
    func_800EFA4C(ground->floor_normal, 0.0f, 1.0f, 0.0f);
    ground->floor_height = (-1.8e+04f); // no floor
    ground->floor_flags = 0;
    ground->unk_8C = 0;
    ground->water_height = (-1.9e+04f); // no water
    ground->ray_top = 100.0f;
    ground->water_flags = 0;
    ground->floor_found = ground->prev_floor_found = 0;
    ground->water_found = ground->prev_water_found = 0;
    ground->floor_filter = 0;
    ground->unk_0 = 0;
    ground->water_filter = 0x1F00;
    ground->unk_95 = 0;
    ground->fixed_water = 0;
    ground->mode = 0;
    func_800C5A10(ground, 1);
    return ground;
}

// Restarts the ground search.
void func_800C5B84(s32 ground)
{
    func_800C5A10(ground, 1);
}

void func_800C5BA4(void *ground)
{
    heap_free(ground);
}

void *func_800C5BC4(void *ground)
{
    return defrag(ground);
}

// Vertical ray probe (map only or all providers), split into 500-unit segments.
// Casts one vertical ray from pos (y offsets y_start to y_end) and fills hit.
int func_800C5BE4(s32 pos, f32 y_start, f32 y_end, s32 filter, Actor *hit)
{
    f32 from[3];
    f32 to[3];
    s32 tri;
    func_800EE7F8(from, pos);
    from[1] += y_start;
    func_800EE7F8(to, pos);
    to[1] += y_end;
    if (filter == 0x1F00) {
        tri = func_800BEF00(from, to, hit, filter);
    } else {
        tri = func_800C6A7C(from, to, hit, filter);
    }
    if (tri != 0) {
        *(s32 *) ((char *) hit + 0x10) = *(s32 *) ((char *) tri + 0x8);
        *(u16 *) ((char *) hit + 0x14) = 0;
    } else {
        *(s32 *) ((char *) hit + 0x10) = 0;
        *(u16 *) ((char *) hit + 0x14) = 0;
    }
    *(f32 *) ((char *) hit + 0xC) = to[1];
    *(s32 *) ((char *) hit + 0x18) = func_800C69FC();
    return tri;
}

// Vertical ray split into segments of at most 500 units.
CollisionC5 *func_800C5CC0(f32 *pos, f32 y_start, f32 y_end, u32 filter, HitC5 *hit)
{
    CollisionC5 *tri;
    if (mlAbsF(y_end - y_start) > 500.0f) {
        if (y_start < y_end) {
            tri = func_800C5BE4(pos, y_start, y_start + 500.0f, filter, hit);
            if (tri == 0) {
                tri =
                    func_800C5BE4(pos, y_start + 500.0f - 1.0f, y_end, filter, hit);
            }
        } else {
            tri = func_800C5BE4(pos, y_start, y_start - 500.0f, filter, hit);
            if (tri == 0) {
                tri =
                    func_800C5BE4(pos, y_start - 500.0f + 1.0f, y_end, filter, hit);
            }
        }
    } else {
        tri = func_800C5BE4(pos, y_start, y_end, filter, hit);
    }
    return tri;
}

// Picks the next mode from the probe results.
u8 func_800C5E14(s32 *ground)
{
    f32 height;
    s32 water_found;
    f32 water_height;
    int zero;
    water_found = *(u8 *) ((char *) ground + 143);
    if (water_found == 0) {
        return 2;
    }
    // Matching: the zero temporary is needed for the match.
    zero = 0;
    if ((water_found != zero) && (*((u8 *) ground + 142) == 0)) {
        return 4;
    }
    // Matching: the extra water_height temporary is needed for the match.
    water_height = *(f32 *) &ground[29];
    height = water_height;
    if (height < *(f32 *) &ground[20]) {
        return 2;
    }
    height = height - *(f32 *) &ground[28];
    if (height < -20.0f) {
        return 2;
    }
    if (height > 100.0f) {
        return 4;
    }
    return 3;
}

// Stores a floor hit: height, flags, normal and, if given, the triangle data.
void func_800C5EB8(u8 *ground, f32 height, s32 flags, s32 unk_0, s32 normal, s32 unk_1,
                   s32 tri)
{
    if (tri != 0) {
        func_800AAD28(ground + 0x1C);
        func_800AAAE0(ground + 0x40);
        func_800FB508(ground + 4, tri);
    }
    *(s8 *) ((s8 *) ground + 0x8E) = 1;
    *(s32 *) ((s8 *) ground + 0x7C) = flags;
    *(s16 *) ((s8 *) ground + 0x8C) = (s16) unk_0;
    *(f32 *) ((s8 *) ground + 0x70) = height;
    *(s32 *) ((s8 *) ground + 0) = unk_1;
    func_800EE7F8(ground + 0x64, normal);
}

// Stores the floor hit from the hit buffer.
void func_800C5F40(s32 ground, s32 *hit, s32 tri)
{
    func_800C5EB8(ground, ((f32 *) hit)[3], hit[4], ((s16 *) hit)[10], hit,
                  hit[6], tri);
}

// Stores "no floor": height -18000 and an up-facing normal.
void func_800C5F8C(int ground)
{
    func_800C5EB8(ground, (-1.8e+04f), 0, 0, D_8011A890, 0, 0);
}

// Stores a water hit; a fixed water height overrides the probed one.
void func_800C5FCC(S_C5FCC *ground, f32 height, T_C5FCC *tri)
{
    if (ground->fixed_water != 0) {
        height = ground->fixed_water_height;
    }
    if (tri != 0) {
        func_800FB508(&ground->unk_10, tri);
    }
    if (tri != 0) {
        ground->water_flags = tri->flags;
    }
    ground->water_found = 1;
    ground->water_height = height;
}

// Stores "no water": height -19000.
int func_800C6038(s32 ground)
{
    func_800C5FCC(ground, (-1.9e+04f), 0);
}

// Mode 2 (airborne) step: probes for the floor and the water below.
void func_800C6060(ground) StateC6060 *ground;
{
    f32 y_offset;
    s32 unk_0;
    f32 hit[6];
    s32 unk_1;
    f32 pos[3];
    TriangleC6060 *tri;
    s32 found_water = 0;
    func_800EE7F8(pos, ground->pos);
    y_offset = ground->ray_top;

if (func_800DA298(0x6B5)) {
    tri = func_800C5CC0(pos,
                            func_800F0E00(ground->prev_y - ground->pos[1], 150.0f) + 10.0f,
                            -5.0f, ground->water_filter, hit);
    if (tri || ground->fixed_water) {
        func_800C5FCC(ground, hit[3], tri);
        found_water = 1;
    }
}

tri = func_800C5CC0(pos, y_offset, -1300.0f, ground->floor_filter, hit);

if (!tri) {
    func_800C5F8C(ground);
    if (!found_water)
        func_800C6038(ground);
    else if (ground->pos[1] < ground->water_height)
        func_800C5A10(ground, 3);
} else if (tri->flags & 0x20020) {

func_800C5FCC(ground, hit[3], tri);
if (ground->floor_height < ground->water_height && ground->pos[1] < ground->water_height)
    func_800C5A10(ground, 3);
tri = func_800C5CC0(pos, y_offset, -450.0f, ground->floor_filter | 0x20020, hit);
if (!tri)
    func_800C5F8C(ground);
else if (hit[1] >= 0.0f)
    func_800C5F40(ground, hit, tri);
}
else if (hit[1] < 0.0f && !(tri->flags & 0x10000))
{
    y_offset = hit[3] - pos[1];
    tri = func_800C5CC0(pos, y_offset - 1.0f, y_offset - 1.3e+03f, ground->floor_filter | 0x20020,
                            hit);
    if (tri)
        func_800C5F40(ground, hit, tri);
    else
        func_800C5F8C(ground);
}
else
{
    func_800C5F40(ground, hit, tri);
    if (found_water)
        func_800C5A10(ground, 3);
    else
        func_800C6038(ground);
}
}

// Mode 3 (grounded or wading) step.
void func_800C6320(GroundState *ground)
{
    f32 hit[7];
    s32 new_mode;
    f32 water_y;
    f32 pos[3];
    void *tri;
    func_800EE7F8(pos, ground->pos);
    tri =
        func_800C5CC0(pos, ground->ray_top, -1300.0f, ground->floor_filter | 0x20020, hit);
    if (tri && hit[1] >= 0.0f)
        func_800C5F40(ground, hit, tri);
    water_y = ground->water_height - pos[1];
    tri = func_800C5CC0(pos, water_y + 50.0f, water_y - 50.0f, ground->water_filter, hit);
    if (tri || ground->fixed_water)
        func_800C5FCC(ground, hit[3], tri);
    new_mode = func_800C5E14(ground);
    if (new_mode != 3)
        func_800C5A10(ground, new_mode);
}

// Mode 4 (swimming) step.
void func_800C6420(ground) GroundState *ground;
{
    f32 hit[7];
    s32 above_floor;
    s32 new_mode;
    s32 unk_0;
    f32 water_y;
    f32 pos[3];
    void *tri;
    func_800EE7F8(pos, ground->pos);
    above_floor = (ground->pos[1] - ground->floor_height > 120.0f) ? 1 : 0;
    unk_0 = func_8001210C(1);
    if (!above_floor || unk_0) {
        if (above_floor)
            ground->water_found = ground->prev_water_found;
        tri = func_800C5CC0(pos, ground->ray_top, -390.0f, ground->floor_filter | 0x20020,
                                hit);

if (tri) {
    if (hit[1] >= 0.0f)
        func_800C5F40(ground, hit, tri);
} else
    func_800C5F8C(ground);

}
if (!above_floor || !unk_0) {
    if (above_floor)
        ground->floor_found = ground->prev_floor_found;
    water_y = ground->water_height - pos[1];
    tri =
        func_800C5CC0(pos, water_y + 140.0f, water_y - 140.0f, ground->water_filter, hit);

if (tri || ground->fixed_water) {
    func_800C5FCC(ground, hit[3], tri);
    ground->unk_92 = 1;
} else if (ground->unk_92) {

ground->unk_92 = 0;
ground->water_found = 1;
}
}
new_mode = func_800C5E14(ground);
if (new_mode != 4)
    func_800C5A10(ground, new_mode);
}

// Per-frame update of the tracker.
void func_800C65E0(GroundState *ground)
{
    GroundHit hit;
    void *tri;
    u8 state;
    u8 next;
    state = ground->mode;
    next = state;
    ground->prev_floor_found = ground->floor_found;
    ground->prev_water_found = ground->water_found;
    ground->floor_found = ground->water_found = 0;
    if (state == 1 || ground->search_timer) {
        ground->search_timer--;
        tri = func_800C5BE4(ground->pos, -100.0f, 7000.0f, ground->water_filter, &hit);
        if (tri)
            func_800C5FCC(ground, hit.height, tri);
        if (tri)
            func_800C5A10(ground, 3);
        else
            func_800C5A10(ground, 2);
        next = ground->mode;
    }
    switch (next) {
        case 2:
            func_800C6060(ground);
            break;
        case 3:
            func_800C6320(ground);
            break;
        case 4:
            func_800C6420(ground);
            break;
    }
    func_800EE7F8(ground->prev_pos, ground->pos);
}

func_800C6704(u8 *ground)
{
    return ground[0x8E];
}

// Returns water_found, or 0 when the water height is the "none" value.
s32 func_800C670C(s32 *ground)
{
    if ((-1.9e+04f) == *(f32 *) (ground + 0x1D)) {
        return 0;
    }
    return (u8) ground[0x23];
}

f32 func_800C673C(f32 *ground)
{
    return ground[30];
}

int func_800C6744(Actor *ground)
{
    return (*(s32 *) ((char *) (ground) + 0x7C));
}

s16 func_800C674C(s32 ground)
{
    s16 *ptr = ground + 0x8C;
    return *ptr;
}

func_800C6754(u8 *ground)
{
    return ground[0x95];
}

// Copies the floor normal to out.
void func_800C675C(s32 ground, s32 out)
{
    func_800EE7F8(out, ground + 0x64);
}

// Floor height; with unk_95 set it is at least 15 below the water surface.
f32 func_800C6784(u8 *ground)
{
    f32 limit;
    f32 margin;
    if (ground[0x95] != 0) {
        margin = 15.0f;
        limit = (*((f32 *) (ground + 0x74))) - margin;
        if ((*((f32 *) (ground + 0x70))) < limit) {
            return limit;
        }
    }
    return *((f32 *) (ground + 0x70));
}

int func_800C67C8(s32 *ground)
{
    return ground[0];
}

func_800C67D0(u8 *ground)
{
    return ground[0x9C];
}

f32 func_800C67D8(f32 *ground)
{
    return ground[29];
}

int func_800C67E0(s32 ground[12])
{
    return ground[0x20];
}

func_800C67E8(ground)
{
    return ground + 0x10;
}

func_800C67F0(ground)
{
    return ground + 4;
}

int func_800C67F8(u8 *ground, u8 *out)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        out[(i * 4) + 0] = ground[(i * 4) + 64];
        out[(i * 4) + 1] = ground[(i * 4) + 65];
        out[(i * 4) + 2] = ground[(i * 4) + 66];
        out[(i * 4) + 3] = ground[(i * 4) + 67];
    }
}

void func_800C6840(s32 ground, s32 out)
{
    s32 offset;
    s32 dst;
    s32 src;

    offset = 0;
    dst = out;
    src = ground + 0x1C;
    do {
        func_800EE7F8(dst, src);
        offset += 0xC;
        dst += 0xC;
        src += 0xC;
    } while (offset != 0x24);
}

int func_800C68A0(f32 *ground, f32 ray_top)
{
    int index;
    // Matching: the index temporary is needed for the match.
    index = 30;
    ground[index] = ray_top;
}

int func_800C68AC(s32 ground)
{
    func_800EE7F8(ground + 0x4C);
}

func_800C68CC(s32 ground, s32 filter)
{
    s32 addr;
    // Matching: going through an integer address is needed for the match.
    addr = ground;
    addr += 0x84;
    *(s32 *) addr = filter;
}

int func_800C68D4(u8 *ground, long value)
{
    ground[0x95] = value;
}

void func_800C68DC(void *ground)
{
    ((u8 *) ground)[0x93] = 1;
}

// Enables or disables the fixed water height override.
int func_800C68E8(u8 *ground, unsigned int enable, f32 height)
{
    if (ground[0x9C] && (!enable)) {
        ground[0x93] = 1;
    }
    if (enable) {
        *((f32 *) (ground + 0x98)) = height;
    }
    ground[0x9C] = enable;
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1E9F060.data.s) is defined here in C,
// values taken from the ROM. D_8011A890 is declared int[] (uses written as NAME[0]); it holds the
// up vector (0, 1.0f, 0) used as the "no floor" normal.
int D_8011A890[4] = {0x0, 0x3F800000, 0x0, 0x0};
