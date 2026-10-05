#include "common.h"

extern s32 D_80137210;
extern s32 D_80137214;
extern u8 D_80137238;
extern void func_800EFA4C(s32 *param_0, float param_1, float param_2, float param_3);
typedef struct { s16 local_0[4]; s16 local_1[2]; u8 pad[4]; } Vertex10F070;
typedef struct { u8 pad[0x18]; Vertex10F070 local_0[1]; } Mesh10F070;
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

void func_8010EF70(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    D_80137210 = param_0;
    D_80137238 = func_800DF8D4();
    func_800EFB24(&D_80137214, func_800DF8F8(param_0), param_3);
    func_800EF368(&D_80137214, 0xBF800000);
    func_800EFA4C(((s32 *) D_8013722C), 0.0f, 1.0f, 0.0f);
    func_800EE97C(((s32 *) D_80137220), ((s32 *) D_8013722C), &D_80137214);
    func_800EF2A0(((s32 *) D_80137220));
    func_800EE97C(((s32 *) D_8013722C), &D_80137214, ((s32 *) D_80137220));
    func_800EF2A0(((s32 *) D_8013722C));
    if (D_80137238 == 0) {
        func_800192FC(((s32 *) D_8013722C), ((s32 *) D_8013722C));
        func_800192FC(((s32 *) D_80137220), ((s32 *) D_80137220));
    }
}

void func_8010F070(void *param_0, s32 *param_1, s32 param_2) {
    u32 *local_0;
    Vertex10F070 *local_1;
    f32 (*local_2)[3];
    f32 *local_3;
    void **local_7;
    f32 local_4[3];
    f32 local_5[3];
    Vertex10F070 *local_6;
    local_7 = ((void * *) &D_80137210);
    local_0 = func_800DF8CC(*local_7);
    local_0 = *param_1 + local_0;
    local_1 = (Vertex10F070 *)func_800DF8B4(*local_7);
    local_1 = (Vertex10F070 *)(*param_1 * 16 + (u8 *)local_1 + 0x18);
    local_6 = param_2 + local_1;
    *param_1 += param_2;
    local_2 = func_80100480(2, param_2);
    local_3 = func_80100480(1, param_2);
    if (D_80137238) {
        func_800F24D0(param_0, local_4, D_80137220);
        func_800EF2A0(local_4);
        func_800F24D0(param_0, local_5, D_8013722C);
        func_800EF2A0(local_5);
    } else {
        func_800EE7F8(local_4, D_80137220);
        func_800EE7F8(local_5, D_8013722C);
    }
    func_801164E0(local_4, local_0, local_2, local_3, param_2);
    func_8011649C(local_5, local_2, param_2);
    for (; local_1 < local_6; local_1++, local_2++, local_3++) {
        local_1->local_1[0] = *local_3 * 992.0f + 992.0f;
        local_1->local_1[1] = (*local_2)[0] * 992.0f + 992.0f;
    }
}

int func_8010F270()
{
  D_80137210 = 0;
}
