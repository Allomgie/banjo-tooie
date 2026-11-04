// Sky manager: D_80128770 holds up to two sky layer models drawn around the camera with a
// widened far plane, plus the rotation timer, light/texture hooks and gcsky overlay wrappers.
#include "common.h"

extern int D_80128774[];
extern void func_800E3CB8(f32 *, f32 *);
extern void func_800E3C8C(f32, f32);
extern void func_800E3980(f32 *);
extern void func_800E44FC(s32);
extern void func_800DF738(s32);
extern void func_800DF7DC(s32);
extern void func_800DF818(s32);
extern void func_800DF4B0(s32);
extern void func_800DE448(f32 *, f32 *, f32, void *, s32);
extern s32 func_800EA340(void);
extern void _glid_entrypoint_6(s32, s32);
extern void _glid_entrypoint_5(s32, s32);
extern f32 func_800D8FF8(void);
extern s32 D_80128778[];
extern void func_800DBEFC(s32, s32, s32);

typedef struct {
    s32 unk_0[2], unk_8[2], model[2], unk_18[2], vertex_sets[2][2];
    u8 pad_30[0xF0];
    f32 height_scale[2], unk_128[2], far_plane, timer;
    s32 buffer_index[2];
} D_80128770_unk;

typedef union {
    D_80128770_unk D_80128770_unk;
    s32 arr[1];
} Union_D_80128770;
// Sky manager state: up to two sky layers.
extern Union_D_80128770 D_80128770;

int func_800BFCD0(s32 param_0, s32 param_1)
{
    D_80128770.arr[param_0 + 0xC] = param_1;
    if (param_0 > D_80128770.arr[0xC]) {
        D_80128770.arr[0xC] = param_0;
    }
}

int func_800BFD00()
{
    s32 *entry;
    s32 i;
    i = 1;
    if (((int *) D_80128770.arr)[12] > 0) {
        entry = &D_80128774[0];
        do {
            func_800DF744(i, *(s32 *) ((char *) entry + 48));
            i++;
            entry++;
        } while (i <= ((int *) D_80128770.arr)[12]);
    }
}

// Draws the sky layers around the camera with a widened far plane.
void func_800BFD6C(s32 param_0, s32 param_1)
{
    s32 i;
    f32 cam_pos[3];
    f32 offset[3];
    f32 saved_near;
    f32 saved_far;
    if (D_80128770.D_80128770_unk.model[0]) {
        func_800E3CB8(&saved_near, &saved_far);
        func_800E3C8C(5.0f, D_80128770.D_80128770_unk.far_plane);
        func_800E3980(cam_pos);
        func_800E44FC(param_0);
        for (i = 0; i < 2; i++) {
            if (D_80128770.D_80128770_unk.model[i]) {
                offset[0] = 0.0f;
                offset[1] =
                    D_80128770.D_80128770_unk.height_scale[i] * D_80128770.D_80128770_unk.timer;
                offset[2] = 0.0f;
                func_800BFD00();
                func_800DF738(D_80128770.D_80128770_unk.unk_0[i]);
                func_800DF7DC(D_80128770.D_80128770_unk.unk_18[i]);
                func_800DF818(D_80128770.D_80128770_unk
                                  .vertex_sets[i][D_80128770.D_80128770_unk.buffer_index[i]]);
                func_800DF4B0(2);
                func_800DE448(cam_pos, offset, D_80128770.D_80128770_unk.unk_128[i], 0,
                              D_80128770.D_80128770_unk.model[i]);
                if (D_80128770.D_80128770_unk.vertex_sets[i][1] && func_800EA340()) {
                    if (D_80128770.D_80128770_unk.unk_8[i])
                        _glid_entrypoint_6(
                            D_80128770.D_80128770_unk.unk_8[i],
                            D_80128770.D_80128770_unk
                                .vertex_sets[i][D_80128770.D_80128770_unk.buffer_index[i]]);
                    D_80128770.D_80128770_unk.buffer_index[i] ^= 1;
                    if (D_80128770.D_80128770_unk.unk_8[i])
                        _glid_entrypoint_5(
                            D_80128770.D_80128770_unk.unk_8[i],
                            D_80128770.D_80128770_unk
                                .vertex_sets[i][D_80128770.D_80128770_unk.buffer_index[i]]);
                }
            }
        }
        func_800E3C8C(saved_near, saved_far);
    }
}

void func_800BFF28()
{
    _gcskyDll_entrypoint_0(&D_80128770);
}

void func_800BFF4C()
{
    _gcskyDll_entrypoint_1(&D_80128770);
}

// Advances the sky timer by the frame delta.
void func_800BFF70(void)
{
    ((f32 *) D_80128770.arr)[0x4D] += func_800D8FF8();
}

int func_800BFFA0(s32 param_0)
{
    return D_80128778[param_0];
}

s32 func_800BFFB4(s32 param_0, s32 param_1, s32 param_2)
{
    s32 handle = D_80128770.arr[param_0];
    if (handle) {
        func_800DBEFC(handle, param_1, param_2);
        return 1;
    }
    return 0;
}

// Matching: the line breaks in this function are needed for the match.
void func_800BFFF4(void)
{
    s32 *entry;
    s32 *list_end;
    s32 unk_0;
    s32 unk_1;
    do { list_end = (s32 *) D_80128778; entry = (s32 *) D_80128770.arr; do { unk_0 = *(s32 *) ((s8 *) entry + 8); if (unk_0 != 0) { *(s32 *) ((s8 *) entry + 8) = func_800EE5D8(unk_0); } unk_1 = *(s32 *) ((s8 *) entry + 0); if (unk_1 != 0) { *(s32 *) ((s8 *) entry + 0) = func_800DC060(unk_1); } entry += 1; } while (entry != list_end); } while (0);
}

int func_800C0064(s32 param_0)
{
    u32 unk_0;
    // Matching: the OR with 0 is needed for the match.
    unk_0 = param_0 | 0;
    _gcskyDll_entrypoint_2((s32 *) D_80128770.arr, unk_0);
}
