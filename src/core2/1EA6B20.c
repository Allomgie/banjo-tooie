#include "common.h"

extern float D_8012B010;
extern void func_800BD708(s32 *, s32 *, f32 *, f32 *, f32);
extern s32 func_800BDAD4(s32 *);
extern s32 func_800BDC44(void);
extern s32 func_800EA628(s32, f32 *, f32 *, s32, s32);
typedef struct CollisionCD CollisionCD;
extern CollisionCD *func_800EAA2C(void *, f32 *, f32 *, f32, f32 *, s32, u32);
extern s32 func_800EADFC(s32, f32 *, f32, s32, s32);
typedef struct LocalMarker LocalMarker;
typedef struct { u8 pad_0[0xC]; s32 (*field_C)(LocalMarker *, f32 *, f32, f32 *, u32); } LocalCallbacks_800CD6B4;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EC75C(LocalMarker *, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct { u8 pad_0[0x10]; s32 (*field_10)(LocalMarker *, LocalMarker *); } LocalCallbacks_800CD820;
typedef struct { LocalMarker *field_0; u8 pad_4[4]; u32 pad_8:27, field_B4:1, pad_B:3, field_B0:1; } LocalEntry;
typedef struct { u8 pad_0[0x64]; u32 pad_64:14, field_65:1, pad_65:1, field_66:16; } LocalActor;
extern s32 func_800CB854(s32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF410(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void **func_800BE444(f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EE88C(f32 *, s16 *);
extern LocalEntry *func_800E9E88(void *);
extern LocalEntry *func_800E9EB4(void *);
extern LocalActor *func_80106790(LocalMarker *);
extern f32 _subaddiecustomhits_entrypoint_5(LocalActor *, f32 *);
extern LocalCallbacks_800CD820 *func_800EC3C4(LocalMarker *);
extern f32 D_801259A0;
typedef struct { u8 pad_0[0xC]; s32 (*field_C)(LocalMarker *, f32 *, f32, f32 *, u32); s32 (*field_10)(LocalMarker *, LocalMarker *); } LocalCallbacks_800CDBA8;
typedef struct { LocalMarker *field_0[32]; u8 field_80[32]; } LocalResults;
extern LocalResults D_8012AF70;
extern u8 D_8012AFF0[];
extern f32 D_801259A4;
extern void func_800EF334(f32 *, f32);
extern f32 func_800EEAD4(f32 *, f32 *);

void func_800CD230(f32 param_0)
{
  D_8012B010 = param_0;
}

s32 func_800CD23C(f32 *param_0, f32 *param_1, s32 param_2, s32 param_3) {
    s32 local_0[3];
    s32 local_1[3];
    s32 local_2[3];
    s32 local_3;
    s32 local_4;
    local_4 = 0;
    func_800BD708(local_1, local_2, param_0, param_1, D_8012B010);
    local_1[1]--;
    for (local_0[2] = local_1[2]; local_0[2] <= local_2[2]; local_0[2]++) {
        for (local_0[1] = local_1[1]; local_0[1] <= local_2[1]; local_0[1]++) {
            for (local_0[0] = local_1[0]; local_0[0] <= local_2[0]; local_0[0]++) {
                local_3 = func_800EA628(func_800BDAD4(local_0), param_0, param_1, param_2, param_3);
                if (local_3) local_4 = local_3;
            }
        }
    }
    local_3 = func_800EA628(func_800BDC44(), param_0, param_1, param_2, param_3);
    if (local_3) local_4 = local_3;
    return local_4;
}

CollisionCD *func_800CD3A8(f32 *param_0, f32 *param_1, f32 param_2, f32 *param_3, s32 param_4, u32 param_5)
{
    s32 local_0[3];
    s32 local_1[3];
    s32 local_2[3];
    void *local_5;
    void *local_6;
    CollisionCD *local_3;
    CollisionCD *local_4 = 0;
    func_800BD708(local_1, local_2, param_0, param_1, param_2 + D_8012B010);
    local_1[1]--;
    for (local_0[0] = local_1[0]; local_0[0] <= local_2[0]; local_0[0]++) {
        for (local_0[1] = local_1[1]; local_0[1] <= local_2[1]; local_0[1]++) {
            for (local_0[2] = local_1[2]; local_0[2] <= local_2[2]; local_0[2]++) {
                local_6 = func_800BDAD4(local_0);
                local_3 = func_800EAA2C(local_6, param_0, param_1, param_2, param_3, param_4, param_5);
                local_4 = local_3 ? local_3 : local_4;
            }
        }
    }
    local_5 = func_800BDC44();
    local_3 = func_800EAA2C(local_5, param_0, param_1, param_2, param_3, param_4, param_5);
    local_4 = local_3 ? local_3 : local_4;
    return local_4;
}

s32 func_800CD544(f32 *param_0, f32 param_1, s32 param_2, s32 param_3) {
    s32 local_0[3];
    s32 local_1[3];
    s32 local_2[3];
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    local_4 = 0;
    func_800BD708(local_1, local_2, param_0, param_0, param_1 + D_8012B010);
    local_1[1]--;
    for (local_0[0] = local_1[0]; local_0[0] <= local_2[0]; local_0[0]++) {
        for (local_0[1] = local_1[1]; local_0[1] <= local_2[1]; local_0[1]++) {
            for (local_0[2] = local_1[2]; local_0[2] <= local_2[2]; local_0[2]++) {
                local_3 = func_800EADFC(func_800BDAD4(local_0), param_0, param_1, param_2, param_3);
                if (local_3) local_4 = local_3;
            }
        }
    }
    local_3 = func_800EADFC(func_800BDC44(), param_0, param_1, param_2, param_3);
    if (local_3) local_4 = local_3;
    return local_4;
}

struct LocalMarker {
    u8 pad_0[0xC];
    LocalCallbacks_800CD6B4 *(*field_C)(void);
    u8 pad_10[8];
    u32 pad_18:11, field_19:4, pad_19:12, field_1B:4, pad_1B:1;
};

s32 func_800CD6B4(LocalMarker *param_0, f32 *param_1, f32 param_2, f32 *param_3, s32 param_4)
{
    s32 local_6;
    f32 local_0[3];
    s32 local_1;
    f32 local_2[3];
    LocalCallbacks_800CD6B4 *local_3;
    f32 local_4;
    f32 local_5[3];
    local_3 = param_0->field_C ? param_0->field_C() : 0;
    func_800EE7F8(local_0, param_1);
    for (local_6 = 0; local_6 < param_4; local_6++) {
        if (local_3 && local_3->field_C) {
            local_1 = local_3->field_C(param_0, local_0, param_2, local_2, param_0->field_1B);
            if (local_1) {
                param_0->field_19 = local_1;
                return 1;
            }
        } else {
            local_4 = func_800EC75C(param_0, local_5);
            if (func_800EEB40(local_0, local_5) < (local_4 + param_2) * (local_4 + param_2)) return 1;
        }
        func_800EF04C(local_0, param_3);
    }
    return 0;
}

struct LocalMarker_800CD820 {
    u8 pad_0[0x14];
    u16 field_14, pad_16;
    u16 pad_18:15, field_19:1;
    u8 pad_1A[4];
    s16 field_1E[3];
    u8 pad_24[4];
    u32 pad_28:22, field_2A:1, pad_2A:9;
};

struct LocalMarker_800CD820 *func_800CD820(struct LocalMarker_800CD820 *param_0, f32 *param_1, f32 *param_2, f32 param_3)
{
    f32 local_17;
    f32 local_18;
    f32 local_19;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_21;
    f32 local_4[3];
    f32 local_5[3];
    void **local_6;
    f32 local_7[3];
    f32 local_22[2];
    u32 local_8;
    LocalEntry *local_10;
    LocalEntry *local_11;
    struct LocalMarker_800CD820 *local_12;
    struct LocalMarker_800CD820 *local_13;
    LocalActor *local_14;
    LocalCallbacks_800CD820 *local_15;
    f32 local_9[3];
    s32 local_16;
    f32 local_20;
    if (func_800CB854(0)) local_8 = 1 << (func_800CB854(0) + 31);
    else local_8 = 0;
    func_800EFB24(local_0, param_2, param_1);
    local_17 = func_800EEF94(local_0);
    func_800EF410(local_1, local_0);
    local_18 = param_3 + param_3;
    local_19 = local_17 / local_18;
    local_16 = (s32)local_19;
    local_20 = (s32)local_19;
    if (local_20 <= local_19) local_16++;
    func_800EFE50(local_7, param_1, param_2, 0.5f);
    local_6 = func_800BE444(local_7);
    local_13 = 0;
    local_21 = 0.0f;
    func_800EFA20(local_3, local_1, local_18);
    func_800EFA20(local_2, local_3, (local_19 - local_20) * 0.5f);
    func_800EE7F8(local_4, local_2);
    func_800EE88C(local_5, param_0->field_1E);
    func_800EF04C(local_5, param_1);
    func_800EF04C(local_5, local_4);
    func_800EE7F8(local_4, local_3);
    while (*local_6) {
        local_10 = func_800E9E88(*local_6);
        local_11 = func_800E9EB4(*local_6);
        for (; local_10 < local_11; local_10++) {
            if (!local_10->field_B4 || !local_10->field_B0) continue;
            local_12 = local_10->field_0;
            if (!local_12->field_2A || param_0 == local_12 || !local_12->field_14 || local_12->field_14 == 0xFFFF || !local_12->field_19) continue;
            local_14 = func_80106790(local_12);
            if (local_14->field_65 || (local_14->field_66 & local_8)) continue;
            local_18 = local_16 * param_3 * D_801259A0;
            local_19 = _subaddiecustomhits_entrypoint_5(local_14, local_9);
            if ((local_19 + local_18) * (local_19 + local_18) < func_800EEB40(local_9, local_7)) continue;
            local_18 = func_800EEB40(local_9, local_5);
            if (local_13 && local_21 < local_18) continue;
            local_15 = func_800EC3C4(local_12);
            if (local_15->field_10 && !local_15->field_10(local_12, param_0)) continue;
            if (func_800CD6B4(local_12, local_5, param_3, local_4, local_16)) {
                local_13 = local_12;
                local_21 = local_18;
            }
        }
        local_6++;
    }
    return local_13;
}

struct LocalMarker_800CDBA8 {
    u8 pad_0[0xC];
    LocalCallbacks_800CDBA8 *(*field_C)(void);
    u8 pad_10[4];
    u16 field_14, pad_16;
    u32 pad_18:11, field_19:4, field_19b:1, pad_1A:11, field_1B:4, pad_1B:1;
    u8 pad_1C[0xC];
    u32 pad_28:22, field_2A:1, pad_2A:9;
};

s32 func_800CDBA8(struct LocalMarker_800CDBA8 *param_0, f32 param_1[][3], f32 *param_2, s32 param_3)
{
    f32 local_16;
    void **local_0;
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    f32 local_4[3];
    s32 local_14;
    u32 local_5;
    LocalCallbacks_800CDBA8 *local_6;
    struct LocalMarker_800CDBA8 *local_7;
    LocalActor *local_8;
    LocalEntry *local_9[1];
    LocalEntry *local_10;
    s32 local_11;
    LocalCallbacks_800CDBA8 *local_12;
    f32 local_13[3];
    s32 local_15 = 0;
    if (func_800CB854(0)) local_5 = 1 << (func_800CB854(0) + 31);
    else local_5 = 0;
    func_800EE7F8(local_1, param_1[0]);
    for (local_14 = 1; local_14 < param_3; local_14++) func_800EF04C(local_1, param_1[local_14]);
    func_800EF334(local_1, 1.0f / param_3);
    local_2 = param_2[0] + func_800EEAD4(local_1, param_1[0]);
    for (local_14 = 1; local_14 < param_3; local_14++) {
        local_16 = param_2[local_14] + func_800EEAD4(local_1, param_1[local_14]);
        if (local_2 < local_16) local_2 = local_16;
    }
    local_2 *= D_801259A4;
    local_0 = func_800BE444(local_1);
    while (*local_0) {
        local_9[0] = func_800E9E88(*local_0);
        local_10 = func_800E9EB4(*local_0);
        for (; local_9[0] < local_10; local_9[0]++) {
            if (!local_9[0]->field_B4 || !local_9[0]->field_B0) continue;
            local_7 = local_9[0]->field_0;
            if (!local_7->field_2A || param_0 == local_7 || !local_7->field_14 || local_7->field_14 == 0xFFFF || !local_7->field_19b) continue;
            local_8 = func_80106790(local_7);
            if (local_8->field_65 || (local_8->field_66 & local_5)) continue;
            local_3 = _subaddiecustomhits_entrypoint_5(local_8, local_4);
            if ((local_3 + local_2) * (local_3 + local_2) < func_800EEB40(local_4, local_1)) continue;
            local_6 = func_800EC3C4(local_7);
            if (local_6->field_10 && !local_6->field_10(local_7, param_0)) continue;
            local_12 = local_7->field_C ? local_7->field_C() : 0;
            for (local_14 = 0; local_14 < param_3; local_14++) {
                if (local_12 && local_12->field_C) {
                    local_11 = local_12->field_C(local_7, param_1[local_14], param_2[local_14], local_13, local_7->field_1B);
                    if (local_11) {
                        local_7->field_19 = local_11;
                        D_8012AFF0[local_15] = local_14;
                        D_8012AF70.field_0[local_15] = local_7;
                        local_15++;
                        break;
                    }
                } else {
                    local_3 = func_800EC75C(local_7, local_4);
                    if (func_800EEB40(param_1[local_14], local_4) < (param_2[local_14] + local_3) * (param_2[local_14] + local_3)) {
                        D_8012AF70.field_80[local_15] = local_14;
                        D_8012AF70.field_0[local_15] = local_7;
                        local_15++;
                        break;
                    }
                }
            }
        }
        local_0++;
    }
    return local_15;
}

int func_800CDFA8(s32 param_0, u8 *param_1)
{
  u8 t7;
  *((s32 *) param_1) = ((u8 *) &D_8012AF70)[param_0 + 0x80];
  return ((s32 *) ((u8 *) &D_8012AF70))[param_0];
}
