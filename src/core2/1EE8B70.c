#include "common.h"

typedef struct { u8 pad_0[0x24]; s32 field_24; } LocalEntry;
typedef struct { u8 pad_0[8]; u32 field_0, field_1; } LocalBuffer_8010F280;
extern LocalBuffer_8010F280 D_80137240;
extern LocalEntry D_80137250[];
typedef struct { s32 local_0[3]; s32 local_1, local_2, local_3; s32 local_4[3]; s32 local_5; } LightF384;
typedef struct { s32 pad; s32 local_0; LightF384 *local_1, *local_2; LightF384 local_3[1]; } StateF384;
extern void *func_800DF8B4(void *);
extern void func_800B237C(void *, f32 *, f32 *);
extern f32 func_800DF8C4(void *);
extern void func_80019224();
extern void *func_800C8760();
extern void func_800C8800();
extern f32 sqrtf(f32);
extern void func_800193C4();
typedef struct { s16 xyz[3]; u16 flags; s16 uv[2]; u8 rgb[3],alpha; } LocalVertex;
typedef struct { s16 xyz[3]; u8 rgb[3],alpha; } LocalColor;
typedef struct { u8 pad0[22]; u16 unused:15; u16 dirty:1; LocalVertex vertices[1]; } LocalBuffer_8010F68C;
typedef struct { s32 xyz[3],inner,radiusSquared,falloff,rgb[3],unused; } LocalLight;
extern s32 D_80137244;
extern LocalLight *D_80137248;
typedef struct { s32 unk0; s32 unk4; u8 *unk8; } S80137240;
extern s32 func_800DF8BC(s32);

LocalEntry *func_8010F280(s32 param_0)
{
    u32 local_0;
    s32 *local_2;
    s32 *local_3;
    s32 local_4;
    local_0 = (u32)D_80137250;
    for (; (u32)local_0 < (u32)D_80137240.field_0; local_0 += sizeof(LocalEntry)) {
        if (((LocalEntry *)local_0)->field_24 < param_0) break;
    }
    if (local_0 == (u32)D_80137240.field_0) {
        if (D_80137240.field_0 < D_80137240.field_1) {
            D_80137240.field_0 = D_80137240.field_0 + sizeof(LocalEntry);
            return (LocalEntry *)local_0;
        }
        return 0;
    }
    if (D_80137240.field_0 == D_80137240.field_1) D_80137240.field_0 -= sizeof(LocalEntry);
    local_2 = (s32 *)(D_80137240.field_0 + sizeof(LocalEntry));
    local_4 = ((LocalEntry *)D_80137240.field_0 - (LocalEntry *)local_0) * sizeof(LocalEntry);
    local_2--;
    local_3 = (s32 *)(D_80137240.field_0 - 4);
    while (local_4 > 0) {
        *local_2-- = *local_3--;
        local_4 -= 4;
    }
    D_80137240.field_0 += sizeof(LocalEntry);
    return (LocalEntry *)local_0;
}

void func_8010F384(void *param_0, s32 param_1, s32 param_2)
{
    f32 local_12;
    f32 local_0[3];
    f32 local_1;
    void *local_9;
    LightF384 *local_10;
    f32 local_11;
    s32 local_3;
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[2];
    s32 local_8[4];
    (*((StateF384 *) &D_80137240)).local_2 = (*((StateF384 *) &D_80137240)).local_1 + (param_1 < 0 ? -param_1 : param_1);
    func_800B237C(func_800DF8B4(param_0), local_0, &local_1);
    local_12 = func_800DF8C4(param_0);
    func_80019224(local_0, local_0);
    local_1 *= local_12;
    func_800DF900(param_0);
    for (local_9 = func_800C8760(0, 2); local_9; local_9 = func_800C878C(local_9, 0, 2)) {
        func_800C8800(local_9, local_5);
        func_800C883C(local_9, local_6);
        local_4[0] = local_5[0] - local_0[0];
        local_4[1] = local_5[1] - local_0[1];
        local_4[2] = local_5[2] - local_0[2];
        local_11 = sqrtf(local_4[0] * local_4[0] + local_4[1] * local_4[1] + local_4[2] * local_4[2]);
        if (local_11 >= local_6[1] + local_1) continue;
        func_800C8900(local_9, local_8);
        local_3 = (local_8[0] + local_8[1] + local_8[2]) * (1.0f - local_11 / (local_6[1] + local_1));
        local_10 = func_8010F280(local_3);
        if (local_10) {
            local_10->local_5 = local_3;
            func_800193C4(local_4, local_5);
            local_10->local_0[0] = local_4[0];
            local_10->local_0[1] = local_4[1];
            local_10->local_0[2] = local_4[2];
            local_6[0] /= local_12;
            local_6[1] /= local_12;
            local_10->local_1 = local_6[0] * 256.0f;
            local_10->local_2 = local_6[1] * local_6[1];
            local_10->local_3 = 16384.0f / (local_6[1] - local_6[0]);
            func_800EE830(local_10->local_4, local_8);
        }
    }
    (*((StateF384 *) &D_80137240)).local_0 = (*((StateF384 *) &D_80137240)).local_1 - (*((StateF384 *) &D_80137240)).local_3;
    mlMtxPop();
}

void func_8010F68C(LocalBuffer_8010F68C *param_0, LocalColor *param_1)
{
    LocalVertex *local_1;
    LocalColor *local_0;
    LocalLight *local_2;
    s32 local_3,local_4,local_5;
    s32 local_6,local_7,local_8;
    s32 local_9,local_10,local_11,local_12;
    local_0=param_1+func_800B2344(param_0);
    local_1=param_0->vertices;
    if (D_80137244) {
        for (;param_1<local_0;param_1++,local_1++) {
            if (local_1->flags&0x1000) continue;
            {
                local_3=param_1->rgb[0]; local_4=param_1->rgb[1]; local_5=param_1->rgb[2];
                for (local_2=((LocalLight *) D_80137250);(u32)local_2<(u32)D_80137248;local_2++) {
                    local_6=local_2->xyz[0]-local_1->xyz[0];
                    local_7=local_2->xyz[1]-local_1->xyz[1];
                    local_8=local_2->xyz[2]-local_1->xyz[2];
                    local_9=local_6*local_6+local_7*local_7+local_8*local_8;
                    local_11=local_9;
                    if (local_9>=local_2->radiusSquared) continue;
                    {
                        if (local_9) local_11=sqrtf(local_9)*256.0f;
                        if (local_2->inner<local_11) { local_12=0x4000-((local_2->falloff*(local_11-local_2->inner))>>8); local_10=local_12<<2; }
                        else local_10=0x10000;
                        local_3+=(local_2->rgb[0]*local_10)>>16;
                        local_4+=(local_2->rgb[1]*local_10)>>16;
                        local_5+=(local_2->rgb[2]*local_10)>>16;
                    }
                }
                if (local_3>=256) local_3=255;
                local_1->rgb[0]=local_3;
                if (local_4>=256) local_4=255;
                local_1->rgb[1]=local_4;
                if (local_5>=256) local_5=255;
                local_1->rgb[2]=local_5;
            }
        }
        param_0->dirty=1;
    } else if (param_0->dirty) {
        for (;param_1<local_0;param_1++,local_1++) {
            if (local_1->flags&0x1000) continue;
            {
                local_1->rgb[0]=param_1->rgb[0];
                local_1->rgb[1]=param_1->rgb[1];
                local_1->rgb[2]=param_1->rgb[2];
            }
        }
        param_0->dirty=0;
    }
}

void func_8010F950(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*((S80137240 *) &D_80137240)).unk0 = arg0;
    (*((S80137240 *) &D_80137240)).unk8 = ((u8 *) D_80137250);
    func_8010F384(arg0, arg1, arg3);
    func_8010F68C(func_800DF8B4((*((S80137240 *) &D_80137240)).unk0), func_800DF8BC((*((S80137240 *) &D_80137240)).unk0));
}
