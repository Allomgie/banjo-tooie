#include "common.h"

typedef struct {s16 local_0; s16 local_1;} RouteAllocation;
extern void *func_800CC63C(s32, s32);
extern f32 func_800EFC7C(void *, void *);
typedef struct SubaddieRouteNode { u8 pad_0[0xC]; s16 local_0; } SubaddieRouteNode;
typedef struct { s16 handle; s16 count; } RouteSlot;
extern s16 *func_801015B0(void);
extern u8 *func_80106F30(Actor *);
extern s32 func_800CC5F4();
extern void *func_8001B798();
extern s16 func_8001B668(s32, s32);
typedef struct { u8 pad_0[0x70]; u32 local_0 : 7; u32 pad_1 : 25; } RouteSel;
typedef struct { s16 id; s16 count; } RouteEntry;
extern void func_8001B754();
extern void func_800EE88C(f32 *, void *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 func_80102D98(Actor *, s32, s32, s32, f32, f32);
typedef struct { f32 local_0[3]; s16 local_1; } RouteSphere1506;
typedef struct { u8 pad_0[6]; u16 local_0; } RouteResult1506;
extern s32 func_800CC61C(s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_800F13F0(f32, f32);
typedef struct { u8 local_0[0xC]; s16 local_1; } RoutePlane49;
extern s16 B_808018E0_subaddierouteDll[];
extern int func_800F05F8(f32 *, f32 *, RoutePlane49 *, f32, f32 *);
extern f32 func_800F0E00(f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 *func_800BE444(f32 *);
extern f32 func_800F1DCC(f32, f32);
typedef struct { s16 local_0; s16 pad_0; } RouteDirectory62;
extern void *func_800CC684(s32, s32);
extern s32 func_800F0064(f32 *, f32, f32 *);
typedef struct { f32 local_0[3]; s16 local_1; s16 local_2; } Broad51RouteNode;
typedef struct { u32 local_0 : 7; u32 pad_1 : 15; u32 local_1 : 6; u32 pad_0 : 4; } Broad51RouteFlags;
extern s32 func_800F00A4(void *, f32, f32, f32, f32 *);
extern s32 func_8010BFA4(f32 *, f32 *, void *, f32);
typedef struct { u8 pad_0[0x70]; u32 local_0 : 7; u32 pad_1 : 15; u32 local_1 : 6; u32 pad_2 : 4; } RouteSelection211;
typedef struct { u8 pad_0[0x18]; u16 local_0; u8 pad_1[10]; u32 local_1:10; u32 pad_2:22; } RouteContactMarker;
typedef struct { u8 pad_0[0x64]; u32 local_0:1; u32 pad_1:31; } RouteContactActor;
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800EC708(Unk80132ED0 *);
extern void func_800EF1B8(f32 *, f32, f32);
typedef struct { s32 local_0; s32 local_1; u32 local_2; } Broad42RouteRecord;
typedef struct { f32 local_0[3]; f32 local_1; } Broad42RouteSphere;
extern f32 func_800EEB40(f32 *, f32 *);
extern Broad42RouteRecord *func_800E9E88(s32);
extern Broad42RouteRecord *func_800E9EB4(s32);
extern f32 func_8008FE3C(f32 *);
extern void func_800EF11C(f32 *, void *);
extern f32 func_800EFBFC(f32 *, f32 *);
typedef struct { u8 pad_0[0x60]; u32 pad_1 : 16; u32 local_0 : 16; } RouteClampFlags;
int func_80800564_subaddierouteDll();
s32 func_80800F34_subaddierouteDll();
s32 func_8080160C_subaddierouteDll(Actor *param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4, s32 param_5);
s32 func_80800A74_subaddierouteDll(Actor *param_0, u8 *param_1, f32 param_2, f32 param_3, s32 param_4);
s32 func_80800D88_subaddierouteDll(Actor *param_0, u8 *param_1, f32 param_2, s32 param_3, s32 *param_4);
s32 func_80801784_subaddierouteDll();
f32 func_8080183C_subaddierouteDll(Actor *param_0, f32 param_1);

void func_80800000_subaddierouteDll(void)
{
    s32 local_1;
    RouteAllocation *local_0;
    local_0 = func_801015B0();
    local_0->local_1 = func_800CC5E8();
    local_1 = local_0->local_1 * 4;
    if (local_1) {
        local_0->local_0 = func_8001B668(0, local_1);
        func_8001B7F0(local_0->local_0, 0, local_1);
        func_801015BC();
    } else local_0->local_0 = 0;
}

void subaddierouteDll_entrypoint_0(void) {
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s1;
    u8 *temp_v0;

    temp_v0 = func_801015B0();
    if (*(s16 *)(temp_v0) != 0) {
        var_s1 = 0;
        var_s0 = 0;
        if (*(s16 *)(temp_v0 + 2) > 0) {
            do {
                temp_v0_2 = (s32)func_8001B798(*(s16 *)(temp_v0));
                if (*(s16 *)(temp_v0_2 + var_s0) != 0) {
                    func_8001B754(*(s16 *)(temp_v0_2 + var_s0));
                }
                var_s1 += 1;
                var_s0 += 4;
            } while (var_s1 < *(s16 *)(temp_v0 + 2));
        }
        func_8001B754(*(s16 *)(temp_v0));
        *(s16 *)(temp_v0) = 0;
    }
    *(s16 *)(temp_v0 + 2) = 0;
}

s32 func_8080011C_subaddierouteDll(s32 param_0, s16 *param_1)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;

    local_2 = func_800CC5F4();
    local_3 = (local_2 * 2 + 3) & ~3;
    for (local_4 = 0; local_4 < local_2; local_4++) {
        param_1[local_4] = local_3;
        local_0 = func_800CC63C(param_0, local_4);
        local_5 = 1;
        for (local_6 = 0; local_6 < local_2; local_6++) {
            if (local_4 != local_6) {
                local_1 = func_800CC63C(param_0, local_6);
                if (func_800EFC7C(local_0, local_1) <
                    (f32)((*(s16 *)(local_1 + 0xC) + *(s16 *)(local_0 + 0xC)) *
                          (*(s16 *)(local_1 + 0xC) + *(s16 *)(local_0 + 0xC)))) {
                    local_5++;
                }
            }
        }
        local_3 += (local_5 + 3) & ~3;
    }
    return local_3;
}

void func_8080024C_subaddierouteDll(u8 *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0 = param_0 + 1;
    SubaddieRouteNode *local_1;
    SubaddieRouteNode *local_2;
    s32 local_3;
    s32 local_4;

    local_3 = func_800CC5F4(param_1);
    local_2 = func_800CC63C(param_1, param_2);
    for (local_4 = 0; local_4 < local_3; local_4++) {
        if (param_2 != local_4) {
            local_1 = func_800CC63C(param_1, local_4);
            if (func_800EFC7C(local_2, local_1) < (f32)((local_2->local_0 + local_1->local_0) * (local_2->local_0 + local_1->local_0))) {
                *local_0++ = local_4;
            }
        }
    }
    param_0[0] = local_0 - param_0 - 1;
}

void subaddierouteDll_entrypoint_1(Actor *param_0)
{
    s16 local_0[128];
    s32 pad[2];
    s32 local_1;
    s16 *local_2;
    u8 *local_3;
    s32 local_4;
    RouteSlot *local_5;
    s16 *local_6;
    s16 *local_7;
    s32 i;

    local_1 = (*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1;
    local_2 = func_801015B0();
    if (*local_2 == 0) {
        func_80800000_subaddierouteDll();
    }
    if (local_1 < 0) {
        local_3 = func_80106F30(param_0);
        if (local_3 != NULL && (*(u32 *)(local_3 + 0xC) >> 20) != 0) {
            local_1 = (*(u32 *)(local_3 + 0xC) >> 20) - 1;
        }
    }
    local_4 = func_800CC5F4(local_1);
    local_5 = func_8001B798(*local_2);
    if (local_5[local_1].handle != 0) {
        local_5[local_1].count++;
        return;
    }
    local_5[local_1].handle = func_8001B668(0, func_8080011C_subaddierouteDll(local_1, local_0));
    local_5[local_1].count = 1;
    local_6 = func_8001B798(local_5[local_1].handle);
    for (i = 0; i < local_4; i++) {
        local_6[i] = local_0[i];
        local_7 = func_8001B798(((RouteSlot *)func_8001B798(*local_2))[local_1].handle);
        func_8080024C_subaddierouteDll((u8 *)local_7 + local_7[i], local_1, i);
    }
}

void subaddierouteDll_entrypoint_2(Actor *param_0)
{
    s32 local_0;
    RouteEntry *local_1;

    local_0 = ((RouteSel *)param_0)->local_0 - 1;
    local_1 = func_8001B798(*func_801015B0());
    local_1[local_0].count--;
    if (local_1[local_0].count == 0) {
        func_8001B754(local_1[local_0].id);
        local_1[local_0].id = 0;
    }
}

s32 subaddierouteDll_entrypoint_3(s32 param_0, s32 param_1, s32 param_2)
{
  rare_memset(param_1, 0, 0xC);
  return func_80800564_subaddierouteDll(param_0, param_1);
}

int func_80800564_subaddierouteDll(param_0, param_1) s32 param_0; s32 *param_1;
{
  *(s16 *)((char *)param_1 + 0x6) = 0;
  param_1[2] = 0;
}

s32 subaddierouteDll_entrypoint_4(u8 **param_0)
{
  s32 sp1C;
  sp1C = ((((u16) (*((u16 *) (((s8 *) (*param_0)) + 0x12)))) & 0xFFFFFFFFu) >> 1) & 3;
  return func_8001210C(3) == sp1C;
}

void func_808005B0_subaddierouteDll(Actor *param_0, void *param_1, f32 param_2, f32 param_3, f32 param_4)
{
    f32 local_0[3];
    func_800EE88C(local_0, param_1);
    param_0->unk54 = func_800136E4(func_800F1DF4(param_0->position, local_0) + 180.0f);
    if (!func_80102CF4(param_0, 40.0f)) {
        func_80102BF8(param_0, param_2, param_3, param_4);
    }
}

void subaddierouteDll_entrypoint_5(s32 param_0, s32 param_1, s32 param_2, f32 param_3, f32 param_4, f32 param_5) {
    if (param_2 & 4) {
        func_808005B0_subaddierouteDll(param_0, param_1, param_3, param_4, param_5);
    } else {
        func_80102BF8(param_0, param_3, param_4, param_5);
    }
}

s32 subaddierouteDll_entrypoint_6(Actor *param_0, s32 param_1, u32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    if (param_2 & 0x1C) {
        return 0;
    }
    return func_80102D98(param_0, param_3, 0, param_4, (f32)param_5, (f32)param_6);
}

s32 func_808006D0_subaddierouteDll(Actor *param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
    f32 local_0[3];
    f32 local_1[2];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    RouteSphere1506 *local_5;

    local_2 = (*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1;
    local_3 = func_800CC61C(local_2);
    if (!local_3) return 1;
    func_800EEB9C(local_0, param_2, param_3);
    for (local_4 = local_3 - 1; local_4 >= 0; local_4--) {
        local_5 = (RouteSphere1506 *)func_800CC684(local_2, local_4);
        if (func_800F05F8(param_0->position, local_0, local_5->local_0, local_5->local_1, local_1) == 2 &&
            local_1[0] >= 0.0f && local_1[1] >= 0.0f && func_800F13F0(local_1[0], local_1[1]) < 1.0f) {
            ((RouteResult1506 *)param_1)->local_0 |= 2;
            return 0;
        }
    }
    return 1;
}

s32 func_80800828_subaddierouteDll(Actor *param_0, u8 *param_1, f32 param_2, f32 param_3, s32 param_4)
{
    f32 local_2[3];
    f32 local_1[3];
    f32 local_0[3];
    f32 local_3[2];
    s32 local_7;
    s32 local_8;
    RoutePlane49 *local_9;
    local_8 = ((*(u32 *)((u8 *)param_0 + 0x70) << 22) >> 26) - 1;
    local_7 = (*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1;
    func_800EE7F8(local_1, param_0->position);
    func_800EEB9C(local_0, param_2, param_3);
    func_800EE7F8(local_1, param_0->position);
    local_2[0] = local_1[0] + local_0[0];
    local_2[2] = local_1[2] + local_0[2];
    B_808018E0_subaddierouteDll[0] = local_8;
    B_808018E0_subaddierouteDll[1] = -1;
    for (;;) {
        local_9 = func_800CC63C(local_7, local_8);
        if (func_800F0064(local_9, local_9->local_1, local_2)) return 1;
        switch (func_800F05F8(local_1, local_0, local_9, local_9->local_1, local_3)) {
        case 0:
            return 1;
        case 1:
                if (local_3[0] < 0.0f) return 1;
                break;
        case 2:
            local_3[0] = func_800F0E00(local_3[0], local_3[1]);
            if (local_3[0] < 0.0f) return 1;
                break;
        }
        local_1[0] += local_0[0] * local_3[0];
        local_1[2] += local_0[2] * local_3[0];
        local_0[0] -= local_0[0] * local_3[0];
        local_0[2] -= local_0[2] * local_3[0];
        local_8 = func_80800F34_subaddierouteDll(local_1, local_7, local_8, B_808018E0_subaddierouteDll);
        if (local_8 == -1) {
            *(u16 *)(param_1 + 6) |= 1;
            return 0;
        }
    }
}

s32 func_80800A74_subaddierouteDll(Actor *param_0, u8 *param_1, f32 param_2, f32 param_3, s32 param_4)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;

    f32 local_5;

    if (!(param_4 & 0x2000) &&
        !func_800CC6CC((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1,
                      ((*(u32 *)((u8 *)param_0 + 0x70) << 22) >> 26) - 1)) {
        return 1;
    }
    func_800EE7F8(local_1, param_0->position);
    func_800EE7F8(local_0, param_0->position);
    func_800EF1B8(local_0, param_2, param_3);
    local_1[1] += 0.6f * func_800EC708(param_0->unk0);
    local_0[1] = local_1[1];
    if (func_800BEF00(local_1, local_0, local_2, param_0->unk14)) {
        if (func_800F1EA4(local_2, &local_3)) {
            local_5 = func_800F1DCC(param_2 + 180.0f, local_3);
            *(u16 *)(param_1 + 6) |= (local_5 > 0.0f ? 0x10 : 8);
        }
        return 0;
    }
    return 1;
}

s32 subaddierouteDll_entrypoint_7(Actor *this, s32 arg1, f32 yaw, f32 target, f32 dist, s32 flags)
{
    s32 *node;
    Actor *self = this;
    s32 i;
    f32 a;
    f32 b;
    f32 stepA;
    f32 stepB;
    f32 t;
#define Y (*(f32 *)&yaw)

    func_80800564_subaddierouteDll();
    if (flags & 0x1000) {
        dist = func_8080183C_subaddierouteDll(this, dist);
    }
    node = func_800BE444(this->position);
    if (flags & 0x800) {
        func_80800D88_subaddierouteDll(this, arg1, Y, flags, node);
    }
    if (flags & 0x4000) {
        t = Y;
        Y = target;
        target = t;
    }
    a = func_800F1DCC(target, Y);
    if (func_8080160C_subaddierouteDll(this, arg1, Y, dist, flags, node)) {
        return 1;
    }
    if (a < 0.0f) {
        stepA = -30.0f;
        stepB = 30.0f;
    } else {
        stepA = 30.0f;
        stepB = -30.0f;
    }
    a = Y;
    b = a;
    i = 4;
    do {
        a = func_800136E4(a + stepA);
        if (func_8080160C_subaddierouteDll(this, arg1, a, dist, flags, node)) {
            return 1;
        }
        b = func_800136E4(b + stepB);
        if (func_8080160C_subaddierouteDll(this, arg1, b, dist, flags, node)) {
            return 1;
        }
    } while (--i != 0);
    return 0;
}

s32 func_80800D88_subaddierouteDll(Actor *param_0, u8 *param_1, f32 param_2, s32 param_3, s32 *param_4)
{
    f32 local_2;
    f32 local_3;
    f32 local_0[1];
    Broad42RouteRecord *local_4;
    Broad42RouteRecord *local_5;
    Broad42RouteSphere local_1;
    s32 local_6;
    s32 *local_7;

    local_2 = func_800EC708(param_0->unk0) * 0.7f;
    func_800EE7F8(local_0, param_0->position);
    func_800EF11C(local_0, (u8 *)param_0->unk0 + 0x1E);
    func_800EF1B8(local_0, param_2, 0.6f * local_2);
    local_7 = param_4;
    if (local_7 == NULL) {
        local_7 = func_800BE444(param_0->position);
    }
    while (*local_7) {
        local_4 = func_800E9E88(*local_7);
        local_5 = func_800E9EB4(*local_7);
        while (local_4 < local_5) {
            if (local_4->local_2 & 1) {
                local_6 = local_4->local_0;
                if (func_80801784_subaddierouteDll(param_0, local_6, param_3, &local_1)) {
                    local_3 = func_800EEB40(local_0, local_1.local_0);
                    if (local_3 < (local_2 + local_1.local_1) * (local_2 + local_1.local_1)) {
                        func_800EE940(param_1, &local_1);
                        *(s32 *)(param_1 + 8) = local_6;
                        *(u16 *)(param_1 + 6) |= 4;
                        return 1;
                    }
                }
            }
            local_4++;
        }
        local_7++;
    }
    return 0;
}

s32 func_80800F34_subaddierouteDll(param_0, param_1, param_2, param_3) Actor *param_0; s32 param_1; s32 param_2; s16 *param_3;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    u8 *local_5;

    local_0 = func_8001B798(((s16 *)func_801015B0())[0]);
    local_0 = func_8001B798(((RouteDirectory62 *)local_0)[param_1].local_0);
    local_0 = ((s16 *)local_0)[param_2] + local_0;
    local_1 = *local_0++;
    for (local_2 = 0; local_2 < local_1; local_2++, local_0++) {
        local_3 = 0;
        for (local_4 = 0; param_3[local_4] != -1; local_4++) {
            if (!local_3 && param_3[local_4] == *local_0) local_3 = 1;
        }
        if (!local_3) {
            local_5 = func_800CC63C(param_1, *local_0);
            if (func_800F0064(local_5, (f32)*(s16 *)(local_5 + 0xC), param_0)) {
                param_3[local_4] = *local_0;
                param_3[local_4 + 1] = -1;
                return local_2;
            }
        }
    }
    return -1;
}

s32 subaddierouteDll_entrypoint_8(Actor *param_0, f32 *param_1, s32 param_2, s32 param_3)
{
    s32 local_0;
    s32 local_2;
    s32 local_3;
    s16 *local_4;
    s32 local_1;
    u8 *local_5;
    Broad51RouteNode *local_6;
    local_0 = ((Broad51RouteFlags *)((u8 *)param_0 + 0x70))->local_0 - 1;
    local_1 = ((Broad51RouteFlags *)((u8 *)param_0 + 0x70))->local_1 - 1;
    local_4 = (s16 *)func_801015B0();
    local_2 = func_800CC61C(local_0);
    for (local_3 = 0; local_3 < local_2; local_3++) {
        local_6 = func_800CC684(local_0, local_3);
        if (local_6->local_0[1] - local_6->local_2 < param_0->position[1] &&
            param_0->position[1] < local_6->local_0[1] + local_6->local_2 &&
            func_800F0064(local_6->local_0, local_6->local_1, param_0->position)) {
            func_800EE7F8(param_0->position, param_1);
            return 1;
        }
    }
    local_6 = func_800CC63C(local_0, local_1);
    if (local_6->local_0[1] - local_6->local_2 < param_0->position[1] &&
        param_0->position[1] < local_6->local_0[1] + local_6->local_2 &&
        func_800F0064(local_6->local_0, local_6->local_1, param_0->position)) {
        return 0;
    }
    local_4 = func_8001B798(*local_4);
    local_5 = func_8001B798(*(s16 *)((u8 *)local_4 + local_0 * 4));
    local_5 = ((s16 *)local_5)[local_1] + local_5;
    local_2 = *local_5++;
    for (local_3 = 0; local_3 < local_2; local_3++, local_5++) {
        local_6 = func_800CC63C(local_0, *local_5);
        if (local_6->local_0[1] - local_6->local_2 < param_0->position[1] &&
            param_0->position[1] < local_6->local_0[1] + local_6->local_2 &&
            func_800F0064(local_6->local_0, local_6->local_1, param_0->position)) {
            ((Broad51RouteFlags *)((u8 *)param_0 + 0x70))->local_1 = *local_5 + 1;
            return 0;
        }
    }
    func_800EE7F8(param_0->position, param_1);
    return 1;
}

s32 subaddierouteDll_entrypoint_9(Actor *param_0, f32 *param_1, s32 param_2, s32 param_3)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    u8 *local_6;
    void *local_7;

    local_1 = (s32)((RouteSelection211 *)param_0)->local_0 - 1;
    local_2 = (s32)((RouteSelection211 *)param_0)->local_1 - 1;
    local_7 = func_801015B0();
    local_4 = func_800CC61C(local_1);
    for (local_3 = 0; local_3 < local_4; local_3++) {
        local_0 = func_800CC684(local_1, local_3);
        if (func_800F00A4(local_0, (f32)*(s16 *)(local_0 + 0xC),
                         (f32)*(s16 *)(local_0 + 0xE), (f32)-*(s16 *)(local_0 + 0xE),
                         param_0->position)) {
            if (param_3 & 2) {
                func_800EE7F8(param_0->position, param_1);
                return 1;
            }
            if (!func_8010BFA4(param_0->position, param_1, local_0, (f32)*(s16 *)(local_0 + 0xC))) {
                return 1;
            }
            for (local_5 = 0; local_5 < local_4; local_5++) {
                local_0 = func_800CC684(local_1, local_5);
                if (local_5 != local_3 && func_800F0064(local_0,
                        (f32)*(s16 *)(local_0 + 0xC), param_0->position)) {
                    func_800EE7F8(param_0->position, param_1);
                    return 1;
                }
            }
            break;
        }
    }
    local_0 = func_800CC63C(local_1, local_2);
    if (func_800F00A4(local_0, (f32)*(s16 *)(local_0 + 0xC),
                     (f32)*(s16 *)(local_0 + 0xE), (f32)-*(s16 *)(local_0 + 0xE),
                     param_0->position)) {
        return 0;
    }
    local_6 = func_8001B798(((s16 *)local_7)[0]);
    local_6 = func_8001B798(((RouteDirectory62 *)local_6)[local_1].local_0);
    local_6 = ((s16 *)local_6)[local_2] + local_6;
    local_4 = *local_6++;
    for (local_3 = 0; local_3 < local_4; local_3++, local_6++) {
        local_0 = func_800CC63C(local_1, *local_6);
        if (func_800F00A4(local_0, (f32)*(s16 *)(local_0 + 0xC),
                         (f32)*(s16 *)(local_0 + 0xE), (f32)-*(s16 *)(local_0 + 0xE),
                         param_0->position)) {
            ((RouteSelection211 *)param_0)->local_1 = *local_6 + 1;
            return 0;
        }
    }
    func_800EE7F8(param_0->position, param_1);
    return 1;
}

s32 func_8080160C_subaddierouteDll(Actor *param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4, s32 param_5)
{
    if (!(param_4 & 0x200) && !func_808006D0_subaddierouteDll(param_0, param_1, param_2, param_3, param_4)) {
        return 0;
    }
    if (!(param_4 & 0x100) && !func_80800828_subaddierouteDll(param_0, param_1, param_2, param_3, param_4)) {
        return 0;
    }
    if (!(param_4 & 0x400) && !func_80800A74_subaddierouteDll(param_0, param_1, (f32)func_800DC128(-20, 20) + param_2, param_3, param_4)) {
        return 0;
    }
    param_0->unk54 = param_2;
    return 1;
}

s32 func_808016F0_subaddierouteDll(RouteContactMarker **param_0, RouteContactMarker *param_1, s32 param_2)
{
    if (*param_0 == param_1) return 2;
    if ((param_2 & 2) && (param_1->local_0 & 1)) {
        return ((RouteContactActor *)func_80106790((Unk80132ED0 *)param_1))->local_0 ? 0 : 4;
    }
    if ((param_2 & 1) && !param_1->local_1) return 1;
    return 3;
}

s32 func_80801784_subaddierouteDll(param_0, param_1, param_2, param_3) RouteContactMarker **param_0; RouteContactMarker *param_1; s32 param_2; f32 *param_3;
{
    f32 local_1;
    Actor *local_0;

    switch (func_808016F0_subaddierouteDll(param_0, param_1, param_2)) {
    case 0:
        local_0 = func_80106790((Unk80132ED0 *)param_1);
        local_1 = func_800EC708((Unk80132ED0 *)*param_0) * 0.7f;
        param_3[3] = local_1;
        func_800EE7F8(param_3, local_0->position);
        func_800EF11C(param_3, (u8 *)param_1 + 0x1E);
        return 1;
    case 1:
        param_3[3] = func_8008FE3C(param_3) * 4.0f;
        return 1;
    }
    return 0;
}

f32 func_8080183C_subaddierouteDll(Actor *param_0, f32 param_1)
{
    f32 local_0;
    local_0 = func_800F13F0(param_1, func_800EFBFC(param_0->position, (f32 *)param_0->actorData));
    return func_800F0E00(local_0, (param_0->scale * 1.2f) * ((RouteClampFlags *)param_0)->local_0);
}
