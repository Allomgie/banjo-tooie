#include "core2/1EAAD80.h"

extern void *heap_alloc_sided(s32, s32);
typedef struct {
    s16 *unk0;
    s32 unk4;
} G_D154C;
extern G_D154C D_8012B250;
extern s32 func_8001210C(s32);
extern void rare_memcpy(void *, void *, s32);
extern void heap_free();
s32 defrag();
extern u8 D_8011AF50[];
extern void func_800D24E8(s32, s32, s32);
typedef struct {
    s16 a;
    s16 b;
} S8011AF50;
extern void func_800D2770(s32, s32);
extern s16 D_8011AF52[][2];
extern u8 D_8011AE50[11];

void func_800D1490(void)
{
    s32 local_0;
    for (local_0 = 0; local_0 < 21; local_0++) {
        D_8012B250.unk0[local_0] = ((s16 *) &func_800D1A04)[local_0 * 4];
    }
}

s32 func_800D1510(void)
{
    D_8012B250.unk4 = 0;
    D_8012B250.unk0 = heap_alloc_sided(42, D_8012B250.unk4);
    func_800D1490();
}

void func_800D154C(void)
{
    void *old;
    s32 n;
    if (func_8001210C(0x3FF) != 0x1FF) {
        return;
    }
    old = D_8012B250.unk0;
    D_8012B250.unk4++;
    n = D_8012B250.unk4;
    if (n == 3) {
        D_8012B250.unk4 = 0;
        n = 0;
    }
    D_8012B250.unk0 = heap_alloc_sided(0x2A, n);
    rare_memcpy(D_8012B250.unk0, old, 0x2A);
    heap_free(old);
}

void func_800D15CC()
{
    if ((s32) D_8012B250.unk0 != 0) {
        D_8012B250.unk0 = defrag((s32) D_8012B250.unk0);
    }
}

void func_800D1604(void)
{
    heap_free((s32) D_8012B250.unk0);
    D_8012B250.unk0 = 0;
}

void func_800D162C(void)
{
    s32 local_0;
    u8 *local_1;
    s32 local_2;
    do { local_1 = D_8011AF50; local_0 = 0; local_2 = 0; do { func_800D2770(*(s16 *) local_1, *(s16 *) ((u8 *) D_8012B250.unk0 + local_0) ^ *(s16 *) ((u8 *) &func_800D1A04 + local_2)); local_0 += 2; local_1 += 4; local_2 += 8; } while (local_0 != 0x2A); } while (0);
}

int func_800D16C4(param_0)
s32 param_0;
{
    s32 local_0;
    local_0 = param_0 - 0x40;
    return local_0;
}

void func_800D16CC(s32 param_0, s32 param_1)
{
    s16 local_0;
    s32 local_1;

    local_1 = param_0 * 4;
    local_0 = *(s16 *) ((u8 *) (u8 *) D_8011AF52 + local_1);
    if (local_0 == -2) {
        *(s16 *) ((u8 *) D_8012B250.unk0 + param_0 * 2) =
            *(s16 *) ((u8 *) func_800D1A04 + local_1 * 2) ^ 0x3E7;
        return;
    }
    if (param_1 < 0) {
        param_1 = 0;
    }
    if (local_0 >= 0 && local_0 < param_1) {
        param_1 = local_0;
    }
    *(s16 *) ((u8 *) D_8012B250.unk0 + param_0 * 2) =
        *(s16 *) ((u8 *) func_800D1A04 + local_1 * 2) ^ param_1;
}

void func_800D175C(s32 param_0, s32 param_1)
{
    s32 local_0;
    local_0 = func_800D16C4(param_0);
    func_800D16CC(local_0,
                  (D_8012B250.unk0[local_0] ^ ((s16 *) &func_800D1A04)[local_0 * 4]) + param_1);
    func_800D24E8(((s16(*)[2]) D_8011AF50)[local_0][0],
                  D_8012B250.unk0[local_0] ^ ((s16 *) &func_800D1A04)[local_0 * 4], 0);
}

void func_800D1804(s32 param_0)
{
    func_800D175C(param_0, -1);
}

void func_800D1824(s32 arg0)
{
    func_800D175C(arg0, 0);
}

void func_800D1844(s32 arg0)
{
    func_800D175C(arg0, 1);
}

void func_800D1864(u32 param_0, u32 param_1, u32 param_2)
{
    s32 idx;
    idx = func_800D16C4(param_0);
    func_800D16CC(idx, param_1);
    if (param_2 != 0) {
        func_800D2498(((S8011AF50 *) D_8011AF50)[idx].a,
                      D_8012B250.unk0[idx] ^ ((s16 *) &func_800D1A04)[idx * 4],
                      ((S8011AF50 *) D_8011AF50)[idx].b);
        return;
    }
    func_800D2770(((S8011AF50 *) D_8011AF50)[idx].a,
                  D_8012B250.unk0[idx] ^ ((s16 *) &func_800D1A04)[idx * 4]);
}

s32 func_800D192C(s32 param_0, s32 param_1)
{
    s32 local_0 = func_800D1A04(param_0);
    func_800D1864(param_0, local_0 | 0, param_1);
}

void func_800D1960(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    local_0 = func_800D16C4();
    if (param_1 > 0) {
    } else if (param_1 != -2) {
        param_1 = 1;
    }
    *(s16 *) ((u8 *) D_8011AF52 + local_0 * 4) = param_1;
    if (param_2 != 0) {
        local_1 = func_800D1A6C(param_0);
    } else {
        local_1 = D_8012B250.unk0[local_0] ^ ((s16 *) &func_800D1A04)[local_0 * 4];
    }
    func_800D16CC(local_0, local_1);
}

s32 func_800D1A04(param_0)
s32 param_0;
{
    s32 local_0;
    local_0 = func_800D16C4(param_0);
    if (D_8011AF52[local_0][0] == -2)
        return 999;
    return D_8012B250.unk0[local_0] ^ ((s16 *) &func_800D1A04)[local_0 * 4];
}

u32 func_800D1A6C(param_0)
u32 param_0;
{
    u32 local_0;
    s16 local_1;
    local_0 = func_800D16C4(param_0);
    local_1 = *((s16 *) ((((char *) D_8011AF50) + (local_0 * 4)) + 2));

if (local_1 != -2) {
    if (local_1 == -1) {
        return 0x32;
    }
}

else
{
    return 999;
}
return *((s16 *) ((((char *) D_8011AF50) + (local_0 * 4)) + 2));

}

int func_800D1ACC(s32 param_0)
{
    switch (param_0 - 0x40) {
        case 0:
            return 0x64;

        case 1:
            return 0x32;

        case 2:
            return 0x32;

        case 3:
            return 0x19;

        case 4:
            return 0xA;

        case 6:
            return 0x64;

        case 7:
            return 0xA;

        default:
            return 0;
    }

}

int func_800D1B34(s32 param_0)
{
    switch (param_0) {
        case 0x29F:
            return 0x48;

        case 0x523:
            return 0x54;

        case 0x1D9:
            return 0x4F;

        case 0x3CA:
            return 0x4B;

        case 0x3CB:
            return 0x4C;

        case 0x40D:
        case 0x481:
            return 0x50;

        case 0x4E2:
            return 0x4D;

        case 0x4E3:
            return 0x4A;

        case 0x4E4:
            return 0x4E;

        case 0x4BA:
        case 0x4D7:
            return 0x51;

        case 0x515:
        case 0x516:
            return 0x52;

        case 0x4B7:
            return 0x49;

        default:
            return 0;
    }

}

s32 func_800D1C38(s32 param_0)
{
    s32 local_0;
    local_0 = func_800D1A04(param_0) == 0;
    return local_0 | 0;
}

s32 func_800D1C5C(u32 param_0)
{
    return (s32) *(s16 *) &D_8011AE50[param_0 * 4];
}

s32 func_800D1C70()
{
    return 0x2A;
}

void func_800D1C78(u8 *param_0, u32 param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    func_800D1490();
    local_1 = param_1 >> 1;
    if (local_1 > 21)
        local_1 = 21;
    for (local_0 = 0; local_0 < local_1; local_0++) {
        local_2 = (param_0[local_0 * 2] << 8) | param_0[local_0 * 2 + 1];
        D_8012B250.unk0[local_0] = local_2 ^ ((s16 *) &func_800D1A04)[local_0 * 4];
    }
}

void func_800D1DFC(u8 *param_0)
{
    s32 local_0;
    for (local_0 = 0; local_0 < 21; local_0++) {
        param_0[local_0 * 2] =
            (D_8012B250.unk0[local_0] ^ ((s16 *) &func_800D1A04)[local_0 * 4]) >> 8 & 0xFF;
        param_0[local_0 * 2 + 1] =
            (D_8012B250.unk0[local_0] ^ ((s16 *) &func_800D1A04)[local_0 * 4]) & 0xFF;
    }
}

u32 func_800D1F34(s32 param_0, s32 param_1)
{
    u32 local_0;
    u32 local_1;
    if (_glgamedata_entrypoint_3(param_0, 4, &local_0, &local_1)) {
        param_1 -= 0x40;

if ((s32) (local_1 >> 1) < param_1) {
    return -1;
}
{
    u32 addr = (u32) param_0 + local_0 + (u32) param_1 * 2;
    u32 result = ((u32) (*(u8 *) addr) << 8) | (*(u8 *) (addr + 1));
    return result;
}

}
return -1;
}

u8 D_8011AE50[11] = {0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
static u32 D_8011AE50_rest[1] = {0x1020304};
u32 D_8011AE60[1] = {0x0};
u32 D_8011AE64[2] = {0x170001, 0xA0001};
u32 D_8011AE6C[2] = {0xB0001, 0x470001};
u32 D_8011AE74[4] = {0xB0001, 0x43FA0000, 0x443B8000, 0xFFFF9603};
u32 D_8011AE84[32] = {
    0x130001, 0x43FA0000, 0x443B8000, 0xFFFF9603, 0x140001, 0x43FA0000, 0x443B8000, 0xFFFF9603,
    0x170001, 0x43FA0000, 0x443B8000, 0xFFFF9603, 0x1F0001, 0x43FA0000, 0x443B8000, 0xFFFF9603,
    0x250001, 0x43FA0000, 0x443B8000, 0xFFFF9603, 0x2D0001, 0x43FA0000, 0x443B8000, 0xFFFF9603,
    0x3B0001, 0x43FA0000, 0x443B8000, 0xFFFF9603, 0x3E0001, 0x43FA0000, 0x443B8000, 0xFFFF9603};
u32 D_8011AF04[9] = {0x1F4, 0x250, 0x222, 0x23F, 0x2DB, 0x2FC, 0x44F, 0x13F, 0x50C};
u32 D_8011AF28[10] = {0x221, 0x2AA, 0x23B, 0x250, 0x2F4, 0x0, 0x0, 0x509, 0x510, 0x0};
u8 D_8011AF50[96] = {0x0, 0xD1, 0x0, 0x64, 0x0, 0xD2, 0x0, 0x32, 0x0, 0xD3, 0x0, 0x32, 0x0, 0xD4,
                     0x0, 0x19, 0x0, 0xD5, 0x0, 0xA,  0x1, 0x1A, 0x0, 0x0,  0x0, 0xD7, 0x0, 0x64,
                     0x0, 0xD8, 0x0, 0xA,  0x0, 0xD9, 0x0, 0x10, 0x0, 0xDA, 0x0, 0x19, 0x0, 0xDB,
                     0x0, 0x19, 0x0, 0xDC, 0x0, 0x5,  0x0, 0xDD, 0x0, 0x5,  0x0, 0xDE, 0x0, 0x4,
                     0x0, 0xDF, 0x0, 0x1E, 0x0, 0xE0, 0x0, 0x1,  0x0, 0xED, 0x0, 0x2,  0x1, 0x8,
                     0x0, 0x1,  0x1, 0x9,  0x0, 0x2,  0x1, 0xC,  0x0, 0x1,  0x1, 0xD,  0x0, 0x1,
                     0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
