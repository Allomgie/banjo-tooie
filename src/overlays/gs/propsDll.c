#include "common.h"

typedef struct { s16 local_0[3]; u16 local_1; u16 local_2; u16 pad_0; u32 local_3; u32 local_4; } GsProp62;
extern Actor *func_80108DC0(s32, s32 *, s32, s32, s32, void *);
extern f32 _gspropmarker_entrypoint_3(void *);
extern void func_80102FDC(Actor *, f32);
typedef struct { u32 f21 : 11; u32 f10 : 11; u32 b9 : 1; u32 b7 : 2; u32 b6 : 1; u32 b5 : 1; u32 b2 : 3; u32 low : 2; } GspFl;
extern void *func_800E9BF4();
extern void *func_800BE5C4();
typedef struct { u32 local_0; u32 local_1; u8 pad_0[10]; u8 pad_1 : 7; u8 local_2 : 1; u8 pad_2; } StoredPropRecord;
extern void func_800EE8CC(f32 *, void *);
extern s32 func_800BDBC4(f32 *);
extern void *func_800E9A24(s32);
typedef struct { u32 pad_0[2]; u32 pad_1:30; u32 selected:1; u32 pad_2:1; } StoredPropCondition1408;
extern void *func_800E98C0(s32);
typedef struct { u8 pad[4]; u32 pad4:25; u32 f:6; u32 rest:1; } PropState;
s32 func_808004E0_gspropsDll();

void gspropsDll_entrypoint_0(s16 *param_0, s32 param_1[3], s32 *param_2)
{
    u32 local_0;
    u32 local_1;
    u32 local_2;

    if ((param_0 != NULL) && (param_0[1] != 0)) {
        local_0 = func_800E9D68();
        local_1 = func_800E9D90(param_0);
        local_2 = local_0;
        if (local_2 < local_1) {
            do {
                if (((u32) (*(u32 *)((char *)local_2 + 0x4) << 0x19) >> 0x1A) == 6) {
                    param_1[*param_2] = local_2;
                    *param_2 += 1;
                }
                local_2 += 0x14;
            } while (local_2 < local_1);
        }
    }
}

void gspropsDll_entrypoint_1(GsProp62 **param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    GsProp62 *local_2;
    s32 local_5[3];
    GsProp62 *local_3;
    Actor *local_4;

    for (local_0 = 0; local_0 < param_1; local_0++) {
        for (local_1 = 0; local_1 < local_0; local_1++) {
            if ((u32)param_0[local_0]->local_2 < (u32)param_0[local_1]->local_2) {
                local_2 = param_0[local_1];
                param_0[local_1] = param_0[local_0];
                param_0[local_0] = local_2;
            }
        }
    }
    for (local_0 = 0; local_0 < param_1; local_0++) {
        local_3 = param_0[local_0];
        local_5[0] = local_3->local_0[0];
        local_5[1] = local_3->local_0[1];
        local_5[2] = local_3->local_0[2];
        local_4 = func_80108DC0(local_3->local_2, local_5, local_3->local_3 >> 23,
                              local_3->local_4 >> 21, (local_3->local_4 << 11) >> 21, local_3);
        if (local_4) {
            local_4->unk74_7 = (u32)local_3->local_1 >> 7;
            local_4->unk7A_5 = 1;
            func_80102FDC(local_4, _gspropmarker_entrypoint_3(local_3));
        }
    }
}

void gspropsDll_entrypoint_2(u8 *param_0, s32 param_1)
{
    u8 *it;
    u8 *end;
    u32 a2_1;
    s32 a3_1;
    u32 a2_2;
    s32 a3_2;
    u32 a2_3;
    s32 a3_3;
    s32 k5a;
    u32 k5b;
    s32 bit6;
    s32 want;
    u32 type;

    k5a = 5;
    k5b = 5;
    if (1) {}
    if (param_0 != 0 && *(s16 *)(param_0 + 2) != 0) {
        it = (u8 *)func_800E9D68();
        end = (u8 *)func_800E9D90(param_0);
        if (it < end) {
            do {
                if ((((u32)(*(u32 *)(it + 4) << 0x19)) >> 0x1A) == 7) {
                    want = param_1 ? 1 : 0;
                    bit6 = ((GspFl *)(it + 0x10))->b6 ? 1 : 0;
                    if (bit6 == want) {
                        a2_1 = (u32)*(u16 *)(it + 6) >> 7;
                        a3_1 = (*(u32 *)(it + 0xC) >> 0x17) * k5a;
                        if (a3_1 == 0) {
                            a3_1 = 0x12C;
                        }
                        if (((GspFl *)(it + 0x10))->b5) {
                            a2_1 *= k5b;
                        }
                        func_800CBA68(*(u16 *)(it + 8), it, a2_1, a3_1, ((GspFl *)(it + 0x10))->f21, ((GspFl *)(it + 0x10))->b9, ((GspFl *)(it + 0x10))->b6);
                    }
                }
                if (param_1 == 0) {
                    type = (((u32)(*(u32 *)(it + 4) << 0x19)) >> 0x1A);
                    if (type == 9) {
                        a2_3 = (u32)*(u16 *)(it + 6) >> 7;
                        a3_3 = (*(u32 *)(it + 0xC) >> 0x17) * k5a;
                        if (a3_3 == 0) {
                            a3_3 = 0x12C;
                        }
                        if (((GspFl *)(it + 0x10))->b5) {
                            a2_3 *= k5b;
                        }
                        func_800CBAC8(*(u16 *)(it + 8), it, a2_3, ((GspFl *)(it + 0x10))->low, a3_3);
                    } else if (type != 0xA && type == 0xC) {
                            a2_2 = (u32)*(u16 *)(it + 6) >> 7;
                            a3_2 = (*(u32 *)(it + 0xC) >> 0x17) * k5a;
                            if (a3_2 == 0) {
                                a3_2 = 0x12C;
                            }
                            if (((GspFl *)(it + 0x10))->b5) {
                                a2_2 *= k5b;
                            }
                            func_800CBB18(*(u16 *)(it + 8), it, a2_2, a3_2, ((GspFl *)(it + 0x10))->low, ((GspFl *)(it + 0x10))->b9);
                    }
                }
                it += 0x14;
            } while (it < end);
        }
    }
}

s32 func_808004E0_gspropsDll(param_0) PropState *param_0; {
    switch (param_0->f) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        return 0;
    }
    return 1;
}

void func_80800524_gspropsDll(s16 *param_0)
{
    s32 local_1;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    u32 local_0[5];
    local_6 = param_0[1];
    local_5 = 0;
    for (local_4 = 0; local_4 < local_6; local_4++) {
        if (func_808004E0_gspropsDll(func_800E9BF4(param_0, local_4))) {
            local_1 = local_4;
            local_5++;
            while (local_1 > 0 && func_808004E0_gspropsDll(func_800E9BF4(param_0, local_1)) && !func_808004E0_gspropsDll(func_800E9BF4(param_0, local_1 - 1))) {
                aligned4_memcpy(local_0, func_800E9BF4(param_0, local_1), 0x14);
                aligned4_memcpy(func_800E9BF4(param_0, local_1), func_800E9BF4(param_0, (local_1 - 1)), 0x14);
                aligned4_memcpy(func_800E9BF4(param_0, (local_1 - 1)), local_0, 0x14);
                local_1 -= 1;
            }
        }
    }
    *(u8 *)func_800BE5C4(param_0) = local_5;
}

void gspropsDll_entrypoint_3(void *param_0)
{
    s32 local_2;
    f32 local_1[3];
    StoredPropRecord *local_0;
    func_800EE8CC(local_1, param_0);
    local_2 = func_800BDBC4(local_1);
    local_0 = func_800E9A24(local_2);
    aligned4_memcpy(local_0, param_0, 0x14);
    if (!(local_0->local_1 & 1)) local_0->local_2 = 1;
    func_80800524_gspropsDll(local_2);
}

void gspropsDll_entrypoint_4(u8 *param_0)
{
    s32 local_2;
    f32 local_0[3];
    u8 *local_1;

    func_800EE8CC(local_0, param_0 + 4);
    local_2 = func_800BDBC4(local_0);
    local_1 = func_800E98C0(local_2);
    aligned4_memcpy(local_1, param_0, 12);
    local_1[0xB] = (local_1[0xB] & 0xFFEF) | 0x10;
    if (((StoredPropCondition1408 *)local_1)->selected) {
        local_1[0xB] &= 0xDF;
    }
}
