// Probably environment-map (reflection) texture coordinates for models: builds a view-relative
// basis, then writes per-vertex S/T from the transformed normals (sphere-map look).
#include "common.h"

// TU-NOTE: D_80137220 / D_8013722C hold the right / up basis vectors.
extern s32 D_80137210;
extern s32 D_80137214;
extern u8 D_80137238;
extern void func_800EFA4C(s32 *param_0, float param_1, float param_2, float param_3);
typedef struct {
    s16 pos[4];
    s16 st[2];
    u8 pad[4];
} Vertex10F070;
typedef struct {
    u8 pad[0x18];
    Vertex10F070 vertices[1];
} Mesh10F070;
extern f32 D_80137220[3];
extern f32 D_8013722C[3];
extern u32 *func_800DF8CC(void *);
extern Mesh10F070 *func_800DF8B4(void *);
extern void *func_80100480(s32, s32);
extern void func_800F24D0(void *, f32 *, f32 *);
extern void func_800EF2A0();
extern void func_800EE7F8(f32 *, f32 *);
extern void func_801164E0(f32 *, u32 *, f32 (*)[3], f32 *, s32);
extern void func_8011649C(f32 *, f32 (*)[3], s32);

// Builds the view-relative right/up basis used for environment mapping.
void func_8010EF70(s32 model, s32 param_1, s32 param_2, s32 param_3)
{
    D_80137210 = model;
    D_80137238 = func_800DF8D4();
    func_800EFB24(&D_80137214, func_800DF8F8(model), param_3);
    func_800EF368(&D_80137214, 0xBF800000);
    func_800EFA4C((s32 *) D_8013722C, 0.0f, 1.0f, 0.0f);
    func_800EE97C((s32 *) D_80137220, (s32 *) D_8013722C, &D_80137214);
    func_800EF2A0((s32 *) D_80137220);
    func_800EE97C((s32 *) D_8013722C, &D_80137214, (s32 *) D_80137220);
    func_800EF2A0((s32 *) D_8013722C);
    if (D_80137238 == 0) {
        func_800192FC((s32 *) D_8013722C, (s32 *) D_8013722C);
        func_800192FC((s32 *) D_80137220, (s32 *) D_80137220);
    }
}

// Transforms vertex normals and writes S/T = dot * 992 + 992 (sphere-map look).
void func_8010F070(void *param_0, s32 *offset, s32 count)
{
    u32 *normals;
    Vertex10F070 *vertex;
    f32(*t_buf)[3];
    f32 *s_buf;
    void **model_ptr;
    f32 right[3];
    f32 up[3];
    Vertex10F070 *vertex_end;
    model_ptr = (void **) &D_80137210;
    normals = func_800DF8CC(*model_ptr);
    normals = *offset + normals;
    vertex = (Vertex10F070 *) func_800DF8B4(*model_ptr);
    vertex = (Vertex10F070 *) (*offset * 16 + (u8 *) vertex + 0x18);
    vertex_end = count + vertex;
    *offset += count;
    t_buf = func_80100480(2, count);
    s_buf = func_80100480(1, count);
    if (D_80137238) {
        func_800F24D0(param_0, right, D_80137220);
        func_800EF2A0(right);
        func_800F24D0(param_0, up, D_8013722C);
        func_800EF2A0(up);
    } else {
        func_800EE7F8(right, D_80137220);
        func_800EE7F8(up, D_8013722C);
    }
    func_801164E0(right, normals, t_buf, s_buf, count);
    func_8011649C(up, t_buf, count);
    for (; vertex < vertex_end; vertex++, t_buf++, s_buf++) {
        vertex->st[0] = *s_buf * 992.0f + 992.0f;
        vertex->st[1] = *t_buf[0] * 992.0f + 992.0f;
    }
}

// Clears the environment-map state.
int func_8010F270()
{
    D_80137210 = 0;
}
