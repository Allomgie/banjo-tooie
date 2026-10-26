#include "common.h"

#define GCZOOMBOXDATA_TABLE_TYPES
typedef struct { s16 a; s16 b; f32 c; } ZoomPt;
typedef struct { u16 a; s8 b; s8 c; ZoomPt *pts; u8 count; u8 pad_0[3]; } ZoomEntry;
typedef ZoomEntry ZoomEntry2;
typedef ZoomEntry ZoomBox;
extern ZoomEntry D_80800AA8_gczoomboxdata[];
extern int D_80800AB0_gczoomboxdata[];
extern s32 func_800D58FC(s32);
extern u8 func_800C2E04(void);
extern void func_800C301C(u8, s32);
extern int func_800C3058(u8, unsigned int);
extern void func_800C330C(u8, s32);
extern void func_800C3418(u8, s32);
extern void func_800C34CC(u8, s32);
extern void func_800C3BDC(u8);
extern f32 func_800DC264(f32, f32);
extern void func_800C31DC(u8, f32);
extern void func_800C3A40(u8, f32, f32, f32);

void gczoomboxdata_entrypoint_0(s32 param_0)
{
    s32 local_0;
    f32 local_1;
    f32 local_2 = 0.2f;
    s32 local_3;
    s32 local_4 = 6000;
    s32 local_5 = 0;
    f32 local_6 = 0.0f;
    f32 local_7;
    f32 local_8;
    u8 local_9;

    if (D_80800AA8_gczoomboxdata[param_0].pts && D_80800AA8_gczoomboxdata[param_0].count) {
        if (D_80800AA8_gczoomboxdata[param_0].pts[0].c == -1.0f) {
            if (!func_800FCCD4(D_80800AA8_gczoomboxdata[param_0].pts[0].a)) func_800FC6B0(D_80800AA8_gczoomboxdata[param_0].pts[0].a);
        } else {
            do {
                local_0 = func_800DC214(0, D_80800AA8_gczoomboxdata[param_0].count);
                local_3 = D_80800AA8_gczoomboxdata[param_0].pts[local_0].b;
            } while (!local_3);
            local_1 = D_80800AA8_gczoomboxdata[param_0].pts[local_0].c;
            local_7 = local_1 - local_2 < 0.1f ? 0.1f : local_1 - local_2;
            if (local_7 >= 2.0f) local_7 = 1.99f;
            local_8 = local_1 - local_6 < 2.0f ? local_1 - local_6 : 2.0f;
            if (!(local_8 > 0.1f)) local_8 = 0.1f;
            local_9 = func_800C2E04();
            if (local_9) {
                func_800C301C(local_9, D_80800AA8_gczoomboxdata[param_0].pts[local_0].a);
                func_800C3058(local_9, func_800DC214(local_3 - local_4 < 0 ? 0 : local_3 - local_4, local_3 - local_5 < 0 ? 0 : local_3 - local_5));
                func_800C31DC(local_9, func_800DC264(local_7, local_8));
                func_800C330C(local_9, 1);
                func_800C3418(local_9, 0);
                func_800C34CC(local_9, 0);
                if (func_800C42E0(D_80800AA8_gczoomboxdata[param_0].pts[local_0].a)) func_800C3A40(local_9, 0.1f, 0.5f, 0.1f);
                func_800C3BDC(local_9);
            }
        }
    }
}

u16 gczoomboxdata_entrypoint_1(s32 param_0) {
    return D_80800AA8_gczoomboxdata[param_0].a;
}

void gczoomboxdata_entrypoint_2(s32 param_0, s8 *param_1, s8 *param_2) {
    ZoomEntry2 *local_0 = &((ZoomEntry2 *) D_80800AA8_gczoomboxdata)[param_0];
    *param_1 = local_0->b;
    *param_2 = local_0->c;
}

u8 gczoomboxdata_entrypoint_3(s32 param_0)
{
    return *(u8 *)((char *)D_80800AB0_gczoomboxdata + param_0 * 12);
}

void gczoomboxdata_entrypoint_4(s32 param_0, s32 param_1, s16 *param_2, s16 *param_3, f32 *param_4) {
    ZoomBox *local_0 = &((ZoomBox *) D_80800AA8_gczoomboxdata)[param_0];
    *param_2 = local_0->pts[param_1].a;
    *param_3 = local_0->pts[param_1].b;
    *param_4 = local_0->pts[param_1].c;
}

u16 gczoomboxdata_entrypoint_5(s32 param_0)
{
    u16 local_0;

    if (param_0 == 0x44) {
        return 0;
    }
    local_0 = D_80800AA8_gczoomboxdata[param_0].a;
    if (1) {
    }
    if (local_0 == 0 || func_800D58FC(local_0) == 4) {
        return 0;
    }
    return local_0;
}

s32 gczoomboxdata_entrypoint_6(s32 param_0) {
    s32 addr = gczoomboxdata_entrypoint_5(param_0);

    if ((addr == 0) || (addr == 0xBAE)) {
        return FALSE;
    }
    return TRUE;
}
