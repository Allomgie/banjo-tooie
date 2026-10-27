#include "common.h"

typedef struct { s32 a[6]; u8 b[200]; s32 c; } BoundS;
extern u8 unkE0[];
extern u8 unk4[];
extern u8 unkC[];
extern void func_800B42DC(s32);
typedef struct { u8 pad_0[0xC]; s16 local_0; s16 local_1; u8 pad_1[4]; u16 local_2 : 11; u16 local_3 : 1; u16 local_4 : 3; u16 local_5 : 1; } BoundItemProperties;
extern void *func_800B3CDC(void *, void *);
typedef struct { u32 local_0 : 23; u32 local_1 : 1; u32 local_2 : 8; u8 pad_0[0x10]; u32 local_3; u32 local_4; } BoundNewRecord;
extern void *heap_realloc(void *, s32);
typedef struct { f32 x; f32 y; f32 z; s16 r; s16 padE; f32 rsq; s32 pad14; } BoundPt;
typedef struct { s32 unk0; f32 cx; f32 cy; f32 cz; f32 rsq; s32 pad14[2]; } BoundSet;
typedef struct { f32 a; f32 b; } BoundV2;
extern BoundV2 D_808015B0_gcboundDll;
extern BoundV2 D_808015B8_gcboundDll;
extern BoundV2 D_808015C0_gcboundDll;
extern BoundV2 D_808015C8_gcboundDll;
extern f32 sqrtf(f32);
typedef struct { u8 pad_0[0x18]; s16 id; u8 pad_1[2]; } BoundRecord1446;
typedef struct { u8 pad_0[0x14]; u32 pad_1 : 11; u32 local_0 : 1; u32 pad_2 : 20; } BoundHistory;
typedef struct { u32 local_0 : 23; u32 pad_0 : 1; u32 local_1 : 8; u8 pad_1[0x16]; s16 local_2; } BoundHistoryRecord;
typedef struct { u32 unk0 : 23; u32 pad0 : 1; u32 unk3 : 8; u8 pad4[0x10]; s32 unk14; u8 unk18[2]; s16 unk1A; } GcBoundElem;
extern void func_800B422C(void *, void *);
extern void func_800B4290(void *);
extern void rare_memcpy(void *, void *, s32);
typedef struct { u8 unused[0x14]; s32 type; s32 unused18; } BoundRecord;
typedef struct { f32 pad_0; f32 height; s32 pad_1; s16 radius; u8 pad_2[10]; } BoundaryCircle;
extern s32 func_800F0064(f32 *, f32, void *);
int func_80800E6C_gcboundDll();
void func_80800EBC_gcboundDll();
void func_80800F6C_gcboundDll();
s32 func_8080132C_gcboundDll();
int func_808013D4_gcboundDll();
int func_8080141C_gcboundDll();
int func_80801450_gcboundDll();
int func_80801484_gcboundDll();

void gcboundDll_entrypoint_0(BoundS *param_0) {
    s32 i;
    param_0->a[0] = param_0->a[1] = 0;
    param_0->a[2] = param_0->a[3] = 0;
    param_0->a[4] = param_0->a[5] = 0;
    for (i = 0; i < 200; i++) {
        param_0->b[i] = 1;
    }
    param_0->c = 0;
}

int gcboundDll_entrypoint_1(Actor *param_0)
{
  (*(s32 *)((char *)(param_0) + 0x4)) = heap_alloc(0);
  (*(s32 *)((char *)(param_0) + 0xC)) = heap_alloc(0);
  (*(s32 *)((char *)(param_0) + 0x14)) = heap_alloc(0);
  (*(s32 *)((char *)(param_0) + 0xE0)) = func_800B42FC(0x18, 0xA);
}

void func_808000AC_gcboundDll(s32 param_0, s32 *param_1, u32 *param_2) {
    u32 local_0;
    u32 local_1;
    u32 local_2;

    local_1 = *param_2;
    if (local_1 != 0) {
        local_2 = local_1;
        local_0 = (*param_1 * 0x1C) + local_1;
        if (local_1 < local_0) {
            do {
                func_800B422C(param_0 + 0xE0, local_2 + 0x18);
                local_2 += 0x1C;
            } while (local_2 < local_0);
            local_1 = *param_2;
        }
        heap_free(local_1);
        *param_2 = 0;
        *param_1 = 0;
    }
}

void gcboundDll_entrypoint_2(u8 *param_0) {
    func_808000AC_gcboundDll(param_0, param_0, param_0 + 4);
    func_808000AC_gcboundDll(param_0, param_0 + 8, param_0 + 0xC);
    func_808000AC_gcboundDll(param_0, param_0 + 0x10, param_0 + 0x14);
    func_800B42DC(*(s32 *)(param_0 + 0xE0));
    *(s32 *)(param_0 + 0xE0) = 0;
}

void func_808001A8_gcboundDll(u8 *param_0, u8 *param_1, void *param_2, s32 param_3,
    s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8)
{
    BoundItemProperties *local_0;

    local_0 = func_800B3CDC(param_0 + 0xE0, param_1 + 0x18);
    func_800EE88C(local_0, param_2);
    local_0->local_0 = param_3;
    local_0->local_1 = (s32)((f32)param_4 * 0.5f);
    local_0->local_2 = param_5;
    local_0->local_5 = param_6;
    local_0->local_3 = param_7;
    local_0->local_4 = param_8;
}

BoundNewRecord *func_80800280_gcboundDll(s32 *param_0, BoundNewRecord **param_1, u32 param_2)
{
    BoundNewRecord *local_0;

    (*param_0)++;
    *param_1 = heap_realloc(*param_1, *param_0 * 0x1C);
    local_0 = *param_1 + *param_0 - 1;
    local_0->local_0 = 0;
    local_0->local_2 = 0;
    local_0->local_3 = param_2;
    local_0->local_1 = 1;
    func_800B4290(&local_0->local_4);
    return local_0;
}

void gcboundDll_entrypoint_3(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7)
{
    s32 local_0;
    s32 local_1 = 0;

    local_0 = func_808013D4_gcboundDll(param_0, param_1, param_7, 0);
    while (local_0) {
        if (func_80801484_gcboundDll(param_0, local_0, param_1, param_2, param_3)) {
            func_808001A8_gcboundDll(param_0, local_0, param_2, param_3, param_4, param_5, param_6, param_7, 0);
            if (!param_7) return;
            local_1 = 1;
        }
        local_0 = func_808013D4_gcboundDll(param_0, param_1, param_7, local_0);
    }
    if (!param_7 || !local_1) {
        func_808001A8_gcboundDll(param_0, func_80800280_gcboundDll(param_0, param_0 + 4, param_1), param_2, param_3, param_4, param_5, param_6, param_7, 0);
    }
}

void gcboundDll_entrypoint_4(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    void *local_0;
    s32 local_1;

    local_0 = func_8080141C_gcboundDll(param_0, param_1, NULL);
    while (local_0) {
        if (func_80801484_gcboundDll(param_0, local_0, param_1, param_2, param_3)) break;
        local_0 = func_8080141C_gcboundDll(param_0, param_1, local_0);
    }
    if (!local_0) local_0 = func_80800280_gcboundDll((s32 *)(param_0 + 8), (BoundNewRecord **)(param_0 + 12), param_1);
    local_1 = func_8080132C_gcboundDll(param_4);
    func_808001A8_gcboundDll(param_0, local_0, param_2, param_3, param_5, 0, 0, 0, local_1);
}

void gcboundDll_entrypoint_5(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    void *local_0;

    local_0 = func_80801450_gcboundDll(param_0, param_1, NULL);
    while (local_0) {
        if (func_80801484_gcboundDll(param_0, local_0, param_1, param_2, param_3)) break;
        local_0 = func_80801450_gcboundDll(param_0, param_1, local_0);
    }
    if (!local_0) local_0 = func_80800280_gcboundDll((s32 *)(param_0 + 16), (BoundNewRecord **)(param_0 + 20), param_1);
    func_808001A8_gcboundDll(param_0, local_0, param_2, param_3, param_4, 0, param_6, 0, param_5);
}

int func_80800630_gcboundDll(param_0, param_1) Actor *param_0; s32 param_1;
{
    func_800B42A0(*(void **)((char *)param_0 + 0xE0), param_1 + 0x18);
}

u8 *func_80800654_gcboundDll(param_0, param_1)
Actor *param_0;
u8 *param_1;
{
    return *(s16 *)(param_1 + 0x1A) * 24 + func_80800630_gcboundDll(param_0, param_1);
}

int func_80800688_gcboundDll()
{
    func_80800630_gcboundDll();
}

int func_808006A8_gcboundDll(param_0, param_1) s32 param_0[3]; u32 *param_1;
{
  s32 local_0;
  ;
  param_1 += 0;
  return (((*param_1) >> 9) * 0x18) + func_80800688_gcboundDll(param_0);
}

int func_808006E0_gcboundDll()
{
    func_808006A8_gcboundDll();
}

int func_80800700_gcboundDll()
{
    func_80800654_gcboundDll();
}

void func_80800720_gcboundDll(s32 param_0, s32 param_1, u32 param_2) {
    u32 local_0;
    u32 local_1;

    local_0 = (param_1 * 0x1C) + param_2;
    local_1 = param_2;
    if (param_2 < local_0) {
        do {
            func_80800EBC_gcboundDll(param_0, local_1);
            local_1 += 0x1C;
        } while (local_1 < local_0);
    }
}

void gcboundDll_entrypoint_6(u8 *param_0)
{
    s32 local_0;
    s32 local_1;
    u8 *local_2;
    u8 *local_3;
    u8 *local_4;
    u8 *local_5;
    u8 *local_6;
    u8 *local_7;
    local_0 = *(s32 *)param_0;
    local_2 = *(u8 **)(param_0 + 4);
    for (local_1 = 0; local_1 < local_0; local_1++, local_2 += 28) {
        local_3 = (u8 *)func_80800630_gcboundDll(param_0, local_2);
        local_4 = (u8 *)func_80800654_gcboundDll(param_0, local_2);
        for (local_5 = local_4 - 48; local_5 >= local_3; local_5 -= 24) {
            local_6 = local_5;
            local_7 = local_5 + 24;
            while (local_6 < local_4 &&
                ((*(u32 *)(local_6 + 20) << 11) >> 31) &&
                !((*(u32 *)(local_7 + 20) << 11) >> 31)) {
                func_80800E6C_gcboundDll(local_6, local_7);
                local_6 += 24;
                local_7 += 24;
            }
        }
        func_80800EBC_gcboundDll(param_0, local_2);
    }
    func_80800720_gcboundDll(param_0, *(s32 *)(param_0 + 8), *(s32 *)(param_0 + 12));
    func_80800720_gcboundDll(param_0, *(s32 *)(param_0 + 16), *(s32 *)(param_0 + 20));
}

void func_808008D8_gcboundDll(void *param_0, s32 param_1, BoundSet *param_2)
{
    BoundSet *local_1;
    BoundPt *local_2;
    BoundPt *local_3;
    BoundPt *local_4;
    BoundV2 local_5;
    BoundV2 local_6;
    BoundV2 local_7;
    BoundV2 local_8;
    BoundSet *local_0;
    f32 local_9;

    if (param_2 == NULL || param_1 == 0) {
        return;
    }
    for (local_0 = param_2; local_0 < &param_2[param_1]; local_0++) {
        local_5 = D_808015B0_gcboundDll;
        local_6 = D_808015B8_gcboundDll;
        local_7 = D_808015C0_gcboundDll;
        local_8 = D_808015C8_gcboundDll;
        local_3 = func_80800688_gcboundDll(param_0, local_0);
        local_4 = func_808006A8_gcboundDll(param_0, local_0);
        for (local_2 = local_3; local_2 < local_4; local_2++) {
            local_7.a = local_2->x - local_2->r;
            local_7.b = local_2->z - local_2->r;
            local_8.a = local_2->x + local_2->r;
            local_8.b = local_2->z + local_2->r;
            if (local_2 == local_3 || local_7.a < local_5.a) {
                local_5.a = local_7.a;
            }
            if (local_2 == local_3 || local_7.b < local_5.b) {
                local_5.b = local_7.b;
            }
            if (local_2 == local_3 || local_6.a < local_8.a) {
                local_6.a = local_8.a;
            }
            if (local_2 == local_3 || local_6.b < local_8.b) {
                local_6.b = local_8.b;
            }
            local_2->rsq = (f32)local_2->r * (f32)local_2->r;
        }
        local_4 = func_80800700_gcboundDll(param_0, local_0);
        for (local_2 = func_808006E0_gcboundDll(param_0, local_0); local_2 < local_4; local_2++) {
            local_2->rsq = (f32)local_2->r * (f32)local_2->r;
        }
        local_0->cx = (local_5.a + local_6.a) * 0.5f;
        local_0->cz = (local_5.b + local_6.b) * 0.5f;
        local_0->cy = 0.0f;
        local_0->rsq = 0;
        local_4 = func_808006A8_gcboundDll(param_0, local_0);
        for (local_2 = local_3; local_2 < local_4; local_2++) {
            local_7.a = local_2->x - local_0->cx;
            local_7.b = local_2->z - local_0->cz;
            local_9 = sqrtf(local_7.b * local_7.b + local_7.a * local_7.a);
            local_9 = local_2->r + local_9;
            if (local_0->rsq < local_9 * local_9) {
                local_0->rsq = local_9 * local_9;
            }
        }
    }
}

s32 gcboundDll_entrypoint_7(void *param_0){
    func_80800F6C_gcboundDll(param_0, param_0, (s32)param_0 + 4);
    func_80800F6C_gcboundDll(param_0, (s32)param_0 + 8, (s32)param_0 + 0xC);
    func_80800F6C_gcboundDll(param_0, (s32)param_0 + 0x10, (s32)param_0 + 0x14);
}

BoundRecord1446 *func_80800CA8_gcboundDll(s32 param_0, BoundRecord1446 *param_1, s32 param_2, s32 *param_3)
{
    BoundRecord1446 *local_0;
    BoundRecord1446 *local_1;
    BoundRecord1446 *local_2;

    local_0 = NULL;
    if (!param_1 || param_2 == *param_3) {
        return NULL;
    }
    local_1 = param_1;
    local_2 = param_1 + param_0;
    while (local_1 < local_2) {
        if (local_1->id >= param_2) {
            if (*param_3 == 0 || local_1->id < *param_3) {
                *param_3 = local_1->id;
                local_0 = local_1;
            }
            if (local_1->id == param_2) {
                return local_1;
            }
        }
        local_1++;
    }
    return local_0;
}

void func_80800D40_gcboundDll(Actor *param_0) {
    s32 idx;
    s32 found;
    s32 local_2C;
    s32 temp;

    idx = func_800B4374(*(s32 *)((char *)param_0 + 0xE0));
    if (idx != 0) {
        do {
            local_2C = 0;
            found = 0;
            temp = func_80800CA8_gcboundDll(*(s32 *)((char *)param_0 + 0), *(s32 *)((char *)param_0 + 4), idx, &local_2C);
            if (temp != 0) {
                found = temp;
            }
            temp = func_80800CA8_gcboundDll(*(s32 *)((char *)param_0 + 8), *(s32 *)((char *)param_0 + 0xC), idx, &local_2C);
            if (temp != 0) {
                found = temp;
            }
            temp = func_80800CA8_gcboundDll(*(s32 *)((char *)param_0 + 0x10), *(s32 *)((char *)param_0 + 0x14), idx, &local_2C);
            if (temp != 0) {
                found = temp;
            }
            if (found != 0) {
                func_800B4134((char *)param_0 + 0xE0, found + 0x18);
                idx = local_2C + 1;
            }
        } while (found != 0);
    }
    func_800B4354((char *)param_0 + 0xE0);
}

s32 gcboundDll_entrypoint_8(s32 *param_0) {
    func_808008D8_gcboundDll(param_0, param_0[0], param_0[1]);
    func_808008D8_gcboundDll(param_0, param_0[2], param_0[3]);
    func_808008D8_gcboundDll(param_0, param_0[4], param_0[5]);
    func_80800D40_gcboundDll(param_0);
}

int func_80800E6C_gcboundDll(param_0, param_1) s32 *param_0; s32 *param_1;
{
  u8 local_0[24];
  rare_memcpy(local_0, param_0, sizeof(local_0));
  rare_memcpy(param_0, param_1, sizeof(local_0));
  rare_memcpy(param_1, local_0, sizeof(local_0));
}

void func_80800EBC_gcboundDll(param_0, param_1) s32 param_0; BoundHistoryRecord *param_1;
{
    BoundHistory *local_0;
    BoundHistory *local_1;
    s32 local_2 = 0;

    local_0 = (BoundHistory *)func_80800630_gcboundDll(param_0, param_1);
    local_1 = (BoundHistory *)func_80800654_gcboundDll(param_0, param_1) - 1;
    while (local_1 >= local_0 && local_1->local_0) {
        local_2++;
        local_1--;
    }
    param_1->local_0 = param_1->local_2 - local_2;
    param_1->local_1 = local_2;
}

void func_80800F6C_gcboundDll(param_0, param_1, param_2) u8 *param_0; s32 *param_1; GcBoundElem **param_2;
{
    GcBoundElem *cur;
    GcBoundElem *other;
    u8 *a;
    u8 *b;
    u8 *bEnd;
    u8 *aEnd;
    u8 *c;
    s32 go;

    if (param_2 == NULL || param_1 == NULL) {
        return;
    }
    for (cur = *param_2; cur < *param_2 + *param_1; cur++) {
        for (other = cur + 1; other < *param_2 + *param_1; other++) {
            if (cur->unk14 == other->unk14 && cur->unk1A != 0 && other->unk1A != 0) {
                aEnd = func_80800654_gcboundDll(param_0, cur);
                go = 1;
                for (a = func_80800630_gcboundDll(param_0, cur); a < aEnd && go; a += 0x18) {
                    bEnd = func_80800654_gcboundDll(param_0, other);
                    for (b = func_80800630_gcboundDll(param_0, other); b < bEnd && go; b += 0x18) {
                        if (func_800F0064(a, *(s16 *)(b + 0xC) + *(s16 *)(a + 0xC), b)) {
                            for (c = func_80800630_gcboundDll(param_0, other); c < bEnd; c += 0x18) {
                                rare_memcpy(func_800B3CDC(param_0 + 0xE0, cur->unk18), c, 0x18);
                            }
                            func_800B422C(param_0 + 0xE0, other->unk18);
                            other->unk0 = other->unk3 = 0;
                            other = cur;
                            go = 0;
                        }
                    }
                }
            }
        }
    }
    for (cur = *param_2; cur < *param_2 + *param_1; cur++) {
        if (cur->unk1A == 0) {
            go = 1;
            for (other = cur + 1; other < *param_2 + *param_1 && go; other++) {
                if (other->unk1A != 0) {
                    rare_memcpy(cur, other, sizeof(GcBoundElem));
                    go = 0;
                    func_800B4290(other->unk18);
                }
            }
        }
    }
    for (cur = *param_2; cur < *param_2 + *param_1 && cur->unk1A != 0; cur++) {
    }
    *param_1 = cur - *param_2;
    *param_2 = heap_realloc(*param_2, *param_1 * sizeof(GcBoundElem));
}

s32 func_8080132C_gcboundDll(param_0) s32 param_0; {
    switch (param_0) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        default:
            return 7;
    }
}

BoundRecord *func_80801370_gcboundDll(s32 param_0, BoundRecord *param_1, BoundRecord *param_2, s32 param_3, s32 param_4)
{
    BoundRecord *local_0 = param_1 + param_0;

    if (param_2 == NULL) {
        param_2 = param_1 - 1;
    }
    for (param_2++; param_2 < local_0; param_2++) {
        if (param_3 == param_2->type || param_4) {
            return param_2;
        }
    }
    return NULL;
}

int func_808013D4_gcboundDll(arg0, arg1, arg2, arg3) s32 *arg0; s32 arg1; s32 arg2; s32 arg3; {
    func_80801370_gcboundDll(*arg0, *(arg0 + 1), arg3, arg1, arg2);
}

int func_8080141C_gcboundDll(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2; {
    func_80801370_gcboundDll(*(s32 *)(param_0 + 8), *(s32 *)(param_0 + 0xC), param_2, param_1, 0);
}

int func_80801450_gcboundDll(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2; {
    func_80801370_gcboundDll(*(s32 *)(param_0 + 0x10), *(s32 *)(param_0 + 0x14), param_2, param_1, 0);
}

int func_80801484_gcboundDll(param_0, param_1, param_2, param_3, param_4) s32 param_0; s32 param_1; s32 param_2; s16 *param_3; s32 param_4;
{
    BoundaryCircle *local_1;
    BoundaryCircle *local_2;
    f32 local_0[3];
    f32 local_3;
    func_800EE88C(local_0, param_3);
    local_1 = (BoundaryCircle *)func_80800654_gcboundDll(param_0, param_1);
    local_2 = (BoundaryCircle *)func_80800630_gcboundDll(param_0, param_1);
    for (; local_2 < local_1; local_2++) {
        local_3 = param_3[1] - local_2->height;
        if (local_3 * local_3 < 250000.0f) {
            if (func_800F0064(local_0, (f32)(local_2->radius + param_4), local_2)) return 1;
        }
    }
    return 0;
}
