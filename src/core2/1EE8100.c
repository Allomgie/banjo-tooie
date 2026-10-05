#include "common.h"

typedef struct { u8 pad_0[0x24]; f32 field_24; } LocalEntry;
typedef struct { u8 pad_0[0x14]; u32 field_0, field_1; } LocalBuffer;
extern LocalEntry D_8013709C[];
typedef struct { s32 position[3], inner, radius2, inverse, color[3]; f32 distance; } LocalLight;
extern void func_800C8800(void *, f32 *);
extern void func_800C883C(void *, f32 *);
extern void func_800C8900(void *, s32 *);
extern void func_800193C4(f32 *, f32 *);
extern f32 sqrtf(f32);
typedef struct { u8 pad[40]; } Entry10EACC;
typedef struct { u8 pad[17]; u8 local_0; u8 pad2[2]; Entry10EACC *local_1, *local_2; Entry10EACC local_3[1]; } State10EACC;
extern s32 func_800DF8B4(s32);
extern f32 func_800DF8C4(s32);
extern void func_800DF900(s32);
extern void func_800B237C(s32, f32 *, f32 *);
extern void func_80019224(f32 *, f32 *);
extern s32 func_800C8760(s32, s32);
extern s32 func_800C878C(s32, s32, s32);
typedef struct { s32 unused, ambient[3]; u8 flags[4]; LocalLight *end, *limit; } LocalLights;
typedef struct {
    s32 unused;
    s32 ambient[3];
    u8 flags[4];
    union { u32 field_0; Entry10EACC *local_1; LocalLight *end; } u14;
    union { u32 field_1; Entry10EACC *local_2; LocalLight *limit; } u18;
    Entry10EACC local_3[1];
} Struct80137080;
extern Struct80137080 D_80137080;
typedef struct { s16 position[3]; u8 color[4]; } LocalPackedVertex;
typedef struct { s16 position[3]; u16 flags; s16 texture[2]; u8 color[4]; } LocalVertex;
extern s32 func_800B2344(void *);
extern s32 D_80137084;

int func_8010E810()
{
    return (int)&D_80137080;
}

LocalEntry *func_8010E81C(f32 param_0)
{
    u32 local_0;
    s32 *local_2;
    s32 *local_3;
    s32 local_4;
    local_0 = (u32)D_8013709C;
    for (; (u32)local_0 < (u32)D_80137080.u14.field_0; local_0 += sizeof(LocalEntry)) {
        if (param_0 < ((LocalEntry *)local_0)->field_24) break;
    }
    if (local_0 == (u32)D_80137080.u14.field_0) {
        if (D_80137080.u14.field_0 < D_80137080.u18.field_1) {
            D_80137080.u14.field_0 = D_80137080.u14.field_0 + sizeof(LocalEntry);
            return (LocalEntry *)local_0;
        }
        return 0;
    }
    if (D_80137080.u14.field_0 == D_80137080.u18.field_1) D_80137080.u14.field_0 -= sizeof(LocalEntry);
    local_2 = (s32 *)(D_80137080.u14.field_0 + sizeof(LocalEntry));
    local_4 = ((LocalEntry *)D_80137080.u14.field_0 - (LocalEntry *)local_0) * sizeof(LocalEntry);
    local_2--;
    local_3 = (s32 *)(D_80137080.u14.field_0 - 4);
    while (local_4 > 0) {
        *local_2-- = *local_3--;
        local_4 -= 4;
    }
    D_80137080.u14.field_0 += sizeof(LocalEntry);
    return (LocalEntry *)local_0;
}

LocalLight *func_8010E924(void *param_0, f32 *param_1, f32 param_2, f32 param_3)
{
    LocalLight *local_0;
    f32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[2];
    func_800C8800(param_0, local_3);
    func_800C883C(param_0, local_4);
    local_2[0] = local_3[0] - param_1[0];
    local_2[1] = local_3[1] - param_1[1];
    local_2[2] = local_3[2] - param_1[2];
    local_1 = sqrtf(local_2[0] * local_2[0] + local_2[1] * local_2[1] + local_2[2] * local_2[2]);
    if (local_1 >= local_4[1] + param_2) return 0;
    local_0 = func_8010E81C(local_1);
    if (!local_0) return 0;
    local_0->distance = local_1;
    func_800193C4(local_2, local_3);
    local_0->position[0] = local_2[0];
    local_0->position[1] = local_2[1];
    local_0->position[2] = local_2[2];
    local_4[0] /= param_3;
    local_4[1] /= param_3;
    local_0->inner = local_4[0] * 256.0f;
    local_0->radius2 = local_4[1] * local_4[1];
    local_0->inverse = 16384.0f / (local_4[1] - local_4[0]);
    func_800C8900(param_0, local_0->color);
    return local_0;
}

void func_8010EACC(s32 param_0, s32 param_1, f32 *param_2) {
    s32 local_4;
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    s32 local_3;
    D_80137080.u18.local_2 = (param_1 < 0 ? -param_1 : param_1) + D_80137080.u14.local_1;
    func_800B237C(func_800DF8B4(param_0), local_0, &local_1);
    local_2 = func_800DF8C4(param_0);
    func_80019224(local_0, local_0);
    local_1 *= local_2;
    func_800DF900(param_0);
    for (local_3 = func_800C8760(0, 1); local_3; local_3 = func_800C878C(local_3, 0, 1)) {
        func_8010E924(local_3, local_0, local_1, local_2);
    }
    D_80137080.flags[1] = D_80137080.u14.local_1 - D_80137080.local_3;
    mlMtxPop();
}

void func_8010EBE4(void *param_0, void *param_1, LocalPackedVertex *param_2)
{
    LocalVertex *local_0;
    LocalPackedVertex *local_1;
    LocalLight *local_2;
    s32 local_3, local_4, local_5;
    s32 local_6, local_7, local_8;
    s32 local_9, local_10, local_12, local_11, local_16;

    local_9 = func_800B2344(param_0);
    local_0 = (LocalVertex *)((u8 *)param_0 + 0x18);
    local_1 = param_2 + local_9;
    if (D_80137080.flags[1]) {
        for (; param_2 < local_1; param_2++, local_0++) {
            if (!(local_0->flags & 0x1000)) {
                local_3 = D_80137080.ambient[0];
                local_4 = D_80137080.ambient[1];
                local_5 = D_80137080.ambient[2];
                local_2 = ((LocalLight *) D_8013709C);
                for (; (u32)local_2 < (u32)D_80137080.u14.end; local_2++) {
                    local_6 = local_2->position[0] - local_0->position[0];
                    local_7 = local_2->position[1] - local_0->position[1];
                    local_8 = local_2->position[2] - local_0->position[2];
                    local_9 = local_6 * local_6 + local_7 * local_7 + local_8 * local_8;
                    if (local_9 < local_2->radius2) {
                        local_11 = sqrtf(local_9) * 256.0f;
                        local_10 = 0x10000;
                        if (local_2->inner < local_11) {
                            local_12 = 0x4000 - ((local_2->inverse * (local_11 - local_2->inner)) >> 8);
                            local_10 = local_12 << 16;
                            local_10 >>= 14;
                        }
                        local_3 += (local_2->color[0] * local_10) >> 16;
                        local_4 += (local_2->color[1] * local_10) >> 16;
                        local_5 += (local_2->color[2] * local_10) >> 16;
                    }
                }
                local_16 = (param_2->color[0] * local_3) >> 8;
                if (local_16 >= 256) local_16 = 255;
                local_0->color[0] = local_16;
                local_16 = (param_2->color[1] * local_4) >> 8;
                if (local_16 >= 256) local_16 = 255;
                local_0->color[1] = local_16;
                local_16 = (param_2->color[2] * local_5) >> 8;
                if (local_16 >= 256) local_16 = 255;
                local_0->color[2] = local_16;
            }
        }
    } else {
        s32 local_13, local_14, local_15;
        local_13 = D_80137080.ambient[0];
        local_14 = D_80137080.ambient[1];
        local_15 = D_80137080.ambient[2];
        for (; param_2 < local_1; param_2++, local_0++) {
            if (!(local_0->flags & 0x1000)) {
                local_0->color[0] = (param_2->color[0] * local_13) >> 8;
                local_0->color[1] = (param_2->color[1] * local_14) >> 8;
                local_0->color[2] = (param_2->color[2] * local_15) >> 8;
            }
        }
    }
}

void func_8010EECC(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 pad;
  s32 sp28;
  s32 sp24;
  D_80137080.unused = param_0;
  D_80137080.flags[0] = func_800DF8D4();
  D_80137080.u14.field_0 = (u32) D_8013709C;
  func_8010EACC(param_0, param_1, param_3);
  func_800C87B8(&D_80137084);
  sp24 = func_800DF8B4(param_0);
  sp28 = func_800DF8CC(param_0);
  func_8010EBE4(sp24, sp28, func_800DF8BC(param_0));
}
