#include "common.h"

typedef struct {
    u8 pad_0;
    u8 local_0;
    s16 local_1;
    u8 pad_1[8];
} FrontendTextSpan;
typedef struct {
    u8 a;
    u8 unk1;
    s16 b;
    void *unk4;
    void *unk8;
} FrontEnt;
extern FrontEnt D_80800D80_gcfrontend[];
typedef struct {
    u8 pad[0xC];
    u8 fC;
    u8 padD[3];
} GfEnt;
typedef struct {
    u8 a;
    u8 pad;
    s16 b;
    GfEnt *ptr;
    s32 x;
} FrontEnt2;
typedef struct {
    u8 first;
    u8 unused[3];
    u8 *text;
    s16 *values;
} FrontendTextRecord;
extern FrontendTextRecord D_80800DA4_gcfrontend;
extern void func_800D3CF8(s32);
extern void func_800D3D10(s32);
typedef struct {
    s32 a;
    s32 b;
    u8 pad[5];
    u8 c;
    u8 pad2[2];
} FrontendEntry;
extern FrontendEntry D_80800C9C_gcfrontend[];
extern void func_800DA544(s32);
typedef struct {
    u8 a;
    u8 b;
    u8 pad[10];
} FrR;
typedef struct {
    s16 map;
    s16 replacement;
    s16 level;
    s16 entrance;
} FrontendMapRecord;
extern FrontendMapRecord D_80800DB0_gcfrontend[16];
typedef struct {
    u16 type;
    s16 arg;
} FrontendCmd;
typedef struct {
    s32 count;
    FrontendCmd *cmds;
} FrontendScript;
extern FrontendScript D_808008FC_gcfrontend[];
extern void func_800D3A54(s32, s32);
extern void func_800D3A88(void);
extern void func_800D3AF0(s32);
extern void func_800D3A14(s32);
extern void func_800D3A20(s32);
extern s32 func_800DC298(f32);
u8 gcfrontend_entrypoint_4();
u8 gcfrontend_entrypoint_5();
void gcfrontend_entrypoint_9();
s32 func_80800450_gcfrontend();
void func_80800738_gcfrontend();

void gcfrontend_entrypoint_0(void)
{
    s32 local_1;
    s32 local_0;
    s32 local_2;
    s32 local_3;

    func_800D3970();
    local_0 = gcfrontend_entrypoint_5(3);
    local_1 = gcfrontend_entrypoint_4(3);
    local_2 = 0;
    if (local_1 > 0) {
        local_3 = local_0;
        do {
            gcfrontend_entrypoint_9(local_3);
            local_2 += 1;
            local_3 += 1;
        } while (local_2 < local_1);
    }
}

s32 gcfrontend_entrypoint_1(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    FrontendTextSpan *local_2;
    local_2 = &D_80800D80_gcfrontend[param_0];
    local_0 = local_2->local_1;
    local_1 = local_2->local_0 + local_0;
    for (; local_0 < local_1; local_0++) {
        if (func_800DA298(local_0)) {
            return 1;
        }
    }
    return 0;
}

int gcfrontend_entrypoint_2(void)
{
    return gcfrontend_entrypoint_1(0) != 0 || gcfrontend_entrypoint_1(1) != 0 ||
           gcfrontend_entrypoint_1(2) != 0;
}

s32 gcfrontend_entrypoint_3(s32 param_0)
{
    FrontEnt *local_0 = &((FrontEnt *) D_80800D80_gcfrontend)[func_80800450_gcfrontend()];
    return func_800DA298(local_0->b + param_0 - local_0->a);
}

u8 gcfrontend_entrypoint_4(param_0)
s32 param_0;
{
    return D_80800D80_gcfrontend[param_0].unk1;
}

u8 gcfrontend_entrypoint_5(param_0)
s32 param_0;
{
    return ((u8 *) D_80800D80_gcfrontend)[param_0 * 12];
}

u8 gcfrontend_entrypoint_6(s32 param_0)
{
    FrontEnt2 *local_0 = &((FrontEnt2 *) D_80800D80_gcfrontend)[func_80800450_gcfrontend()];
    return local_0->ptr[param_0 - local_0->a].fC;
}

void gcfrontend_entrypoint_7(s32 param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    s16 *local_2;
    u8 *local_3;

    u8 *local_5;

    local_0 = func_80800450_gcfrontend();
    if (local_0 < 4) {
        local_3 = NULL;
        func_800D3CF8(param_0);
        local_1 = 2;
        local_5 = (&((FrontendTextRecord *) D_80800D80_gcfrontend)[local_0])->text;
        param_0 -= (&((FrontendTextRecord *) D_80800D80_gcfrontend)[local_0])->first;
        if (local_0 != 2)
            local_3 = local_5 + param_0 * 16 + 4;
        local_2 = (s16 *) (local_5 + param_0 * 16);
        if ((void *) &D_80800DA4_gcfrontend == &D_80800D80_gcfrontend[local_0])
            local_1 = 3;
        func_800D3D10(param_1);
        func_80800738_gcfrontend(local_2, local_3, 0, local_1);
    }
}

void func_808002DC_gcfrontend(s32 param_0, s32 param_1)
{
    FrontendEntry *local_0 = &D_80800C9C_gcfrontend[param_0 - 0xA0];
    func_80800738_gcfrontend(&local_0->a, &local_0->b, local_0->c, param_1);
}

s32 gcfrontend_entrypoint_8(s32 param_0, s32 param_1)
{
    if (param_1 != 0) {
        param_1 = 1;
    } else {
        param_1 = 0;
    }
    func_808002DC_gcfrontend(param_0, param_1);
}

void gcfrontend_entrypoint_9(param_0) s32 param_0;
{
    FrontEnt *local_0 = &((FrontEnt *) D_80800D80_gcfrontend)[func_80800450_gcfrontend()];
    func_800DA544(local_0->b + param_0 - local_0->a);
}

s32 gcfrontend_entrypoint_10(void)
{
    func_800D3CF8(0);
    func_808002DC_gcfrontend(0xA0, -1);
}

s32 gcfrontend_entrypoint_11(void)
{
    gcfrontend_entrypoint_7(func_800D3D04(), 0);
}

s32 gcfrontend_entrypoint_12(void)
{
    func_800AA074();
    func_800AA00C();
    gcfrontend_entrypoint_10();
}

s32 gcfrontend_entrypoint_13(void)
{
    func_800D37D4();
    func_808002DC_gcfrontend(0xA6, -1);
}

s32 func_80800450_gcfrontend(param_0)
s32 param_0;
{
    s32 i;
    s32 e;
    for (i = 0; i < 4; i++) {
        e = ((FrR *) D_80800D80_gcfrontend)[i].a + ((FrR *) D_80800D80_gcfrontend)[i].b;

if (param_0 >= ((FrR *) D_80800D80_gcfrontend)[i].a && param_0 < e) {
    return i;
}

}
return 4;
}

void func_80800520_gcfrontend(param_0) FrontendScript *param_0;
{
    s32 i;
    s16 local_0;

    for (i = 0; i < param_0->count; i++) {
        local_0 = param_0->cmds[i].arg;

switch (param_0->cmds[i].type) {
    case 0:
        func_800D3A54(local_0, 1);
        continue;
    case 1:
        func_800D3A88();
        continue;
    case 2:
        func_800D3AF0(local_0);
        continue;
    case 3:
        func_800D3A14(local_0);
        continue;
    case 4:
        func_800D3A20(local_0);
        continue;
    case 5:
        func_80800520_gcfrontend(&D_808008FC_gcfrontend[local_0]);
        continue;
    case 6:
        func_800D3A54(local_0, 0);
        continue;
    case 7:
        if (func_800DC298(0.5f)) {
            func_800D3A20(local_0);
        } else {
            func_800D3A20(local_0 + 1);
        }
        continue;
}

}
}

void func_8080068C_gcfrontend(s32 *param_0, s32 *param_1)
{
    s32 local_0;
    s16 local_1;
    s32 local_3;

    if (!func_800D3D1C()) {
        local_3 = func_800D3D04();
        for (local_0 = 0; local_0 < 16; local_0++) {

if (local_3 == D_80800DB0_gcfrontend[local_0].map) {
    func_800D3A20(D_80800DB0_gcfrontend[local_0].replacement);
    local_1 = D_80800DB0_gcfrontend[local_0].level;
    if (local_1) {
        *param_0 = local_1;
    }
    local_1 = D_80800DB0_gcfrontend[local_0].entrance;
    if (local_1) {
        *param_1 = local_1;
    }
}

}
}
}

void func_80800738_gcfrontend(param_0, param_1, param_2, param_3) u8 *param_0;
s32 param_1;
s32 param_2;
s32 param_3;
{
    s32 sp1C;
    s32 sp18;

    sp1C = (s32) (*(s16 *) ((s8 *) (param_0) + (2)));
    sp18 = (s32) (*(s16 *) ((s8 *) (param_0) + (0)));
    func_800D39A8();
    func_800D39DC(param_3);
    if (param_1 != 0) {
        func_800D3B24();
        func_80800520_gcfrontend(param_1);
        func_8080068C_gcfrontend(&sp18, &sp1C);
    }
    if (param_2 == 0) {
        func_800EA334(0);
    }
    func_800A791C(sp18, sp1C, 1);
}

s32 gcfrontend_entrypoint_14(s32 param_0)
{
    FrontendTextRecord *local_0;

    local_0 = &D_80800D80_gcfrontend[func_80800450_gcfrontend()];
    return local_0->values[param_0 - local_0->first];
}

extern u8 D_80046A88[];
u32 D_80800840_gcfrontend[3] = {0x10000, 0x60032, 0x50000};
u32 D_8080084C_gcfrontend[1] = {0x30008};
u32 D_80800850_gcfrontend[7] = {0x50002, 0x40057, 0x400E9, 0x400E8, 0x4002B, 0x4002C, 0x4002F};
u32 D_8080086C_gcfrontend[2] = {0x50002, 0x3000C};
u32 D_80800874_gcfrontend[2] = {0x50002, 0x30006};
u32 D_8080087C_gcfrontend[2] = {0x50003, 0x30009};
u32 D_80800884_gcfrontend[1] = {0x3000B};
u32 D_80800888_gcfrontend[3] = {0x50002, 0x60028, 0x3000B};
u32 D_80800894_gcfrontend[2] = {0x50002, 0x40057};
u32 D_8080089C_gcfrontend[6] = {0x400B3, 0x40094, 0x400EB, 0x400EA, 0x400EC, 0x400B2};
u32 D_808008B4_gcfrontend[2] = {0x50002, 0x70582};
u32 D_808008BC_gcfrontend[3] = {0x50002, 0x40582, 0x40583};
u32 D_808008C8_gcfrontend[3] = {0x50002, 0x60012, 0x60006};
u32 D_808008D4_gcfrontend[3] = {0x3000B, 0x60028, 0x60006};
u32 D_808008E0_gcfrontend[7] = {0x20040, 0x20041, 0x20042, 0x20043, 0x20044, 0x20046, 0x20047};
FrontendScript D_808008FC_gcfrontend[4] = {
    0x7, (void *) &D_808008E0_gcfrontend, 0x2, (void *) &D_8080087C_gcfrontend,
    0x3, (void *) &D_80800840_gcfrontend, 0x7, (void *) &D_80800850_gcfrontend};
u32 D_8080091C_gcfrontend[24] = {0xA10000,  0x3, (u32) &D_80800840_gcfrontend, 0x10000,
                                 0x18E0000, 0x3, (u32) &D_80800840_gcfrontend, 0x10000,
                                 0x1940000, 0x3, (u32) &D_80800840_gcfrontend, 0x10000,
                                 0x1910000, 0x3, (u32) &D_80800840_gcfrontend, 0x10000,
                                 0x19C0000, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x19D0000, 0x3, (u32) &D_80800840_gcfrontend, 0x0};
u32 D_8080097C_gcfrontend[52] = {0x1410003, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x15B0003, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x15E0003, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x17A0001, 0x2, (u32) &D_8080087C_gcfrontend, 0x0,
                                 0xD10001,  0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0xF90002,  0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0xFC0001,  0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x1130004, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x1100002, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x12C0002, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x12B0002, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x13F0002, 0x7, (u32) &D_80800850_gcfrontend, 0x0,
                                 0x15D0006, 0x7, (u32) &D_80800850_gcfrontend, 0x0};
u32 D_80800A4C_gcfrontend[92] = {0xC60001,  0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0xC80001,  0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0xC90001,  0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0xDC0001,  0x2, (u32) &D_8080087C_gcfrontend, 0x0,
                                 0xDE0001,  0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0xDF0001,  0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0xE00001,  0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0xE50001,  0x1, (u32) &D_80800884_gcfrontend, 0x0,
                                 0xE40001,  0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x1240008, 0x6, (u32) &D_8080089C_gcfrontend, 0x0,
                                 0x1810001, 0x2, (u32) &D_8080086C_gcfrontend, 0x0,
                                 0x1230001, 0x2, (u32) &D_80800894_gcfrontend, 0x0,
                                 0x1620001, 0x2, (u32) &D_8080087C_gcfrontend, 0x0,
                                 0x10A0001, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x12E0001, 0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0x12F0001, 0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0x1300001, 0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0x13D0002, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x1370003, 0x3, (u32) &D_80800888_gcfrontend, 0x0,
                                 0x1390001, 0x2, (u32) &D_80800874_gcfrontend, 0x0,
                                 0x15F0001, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x15F0001, 0x2, (u32) &D_808008B4_gcfrontend, 0x0,
                                 0x15F0001, 0x3, (u32) &D_808008BC_gcfrontend, 0x0};
u32 D_80800BBC_gcfrontend[56] = {0x1660001, 0x2, (u32) &D_8080087C_gcfrontend, 0x1000000,
                                 0x17F0001, 0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0x1650001, 0x2, (u32) &D_8080087C_gcfrontend, 0x1000000,
                                 0x1860001, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x17C0001, 0x3, (u32) &D_808008D4_gcfrontend, 0x0,
                                 0x17B0001, 0x3, (u32) &D_80800840_gcfrontend, 0x0,
                                 0x1820001, 0x2, (u32) &D_8080086C_gcfrontend, 0x2000000,
                                 0x1830001, 0x2, (u32) &D_8080087C_gcfrontend, 0x0,
                                 0x1640001, 0x2, (u32) &D_8080087C_gcfrontend, 0x1000000,
                                 0x17D0001, 0x3, (u32) &D_808008C8_gcfrontend, 0x0,
                                 0x1800001, 0x1, (u32) &D_8080084C_gcfrontend, 0x0,
                                 0x1850001, 0x3, (u32) &D_80800888_gcfrontend, 0x0,
                                 0x1880001, 0x2, (u32) &D_80800874_gcfrontend, 0x2000000,
                                 0x1890001, 0x3, (u32) &D_80800840_gcfrontend, 0x3000000};
FrontendEntry D_80800C9C_gcfrontend[7] = {
    0x1580000, 0x0, 0x0, 0x0, 0x0, 0x0,       0x0, 0x0, 0x0, 0x0, 0xA10000,  0x0, 0x0, 0x0, 0x0,
    0x0,       0x0, 0x0, 0x0, 0x0, 0xAF0004,  0x0, 0x0, 0x0, 0x0, 0x0,       0x0, 0x0, 0x0, 0x0,
    0x1420003, 0x0, 0x0, 0x0, 0x0, 0x0,       0x0, 0x0, 0x0, 0x0, 0x1420001, 0x0, 0x0, 0x0, 0x0,
    0x0,       0x0, 0x0, 0x0, 0x0, 0x1940000, 0x0, 0x0, 0x0, 0x0, 0x0,       0x0, 0x0, 0x0, 0x0,
    0x18B0000, 0x0, 0x0, 0x0, 0x0, 0x0,       0x0, 0x0, 0x0, 0x0};
u32 D_80800D0C_gcfrontend[7] = {0xAB00AB, 0xAB00B2, 0x42003A, 0xB40057,
                                0xB50075, 0x760077, 0x220000};
u32 D_80800D28_gcfrontend[7] = {0xB20060, 0x3F0078, 0xD000C, 0x300B3, 0xA300A3, 0x60006A, 0x990022};
u32 D_80800D44_gcfrontend[12] = {0x600060, 0x60003F, 0x780078, 0x78000D, 0xC0041,  0x300B3,
                                 0xA300A3, 0x600060, 0x600022, 0x6A0099, 0x220022, 0x220000};
u32 D_80800D74_gcfrontend[3] = {0xC00AE, 0xF0022, 0x6F000D};
FrontEnt D_80800D80_gcfrontend[1] = {0x60, 0x17, 0xBE3, (void *) &D_80800A4C_gcfrontend,
                                     (void *) &D_80800D44_gcfrontend};
u32 D_80800D8C_gcfrontend[3] = {0x200D0BC8, (u32) &D_8080097C_gcfrontend,
                                (u32) &D_80800D0C_gcfrontend};
u32 D_80800D98_gcfrontend[3] = {(u32) ((u8 *) D_80046A88 + 0x1A172), (u32) &D_8080091C_gcfrontend,
                                (u32) &D_80800D74_gcfrontend};
FrontendTextRecord D_80800DA4_gcfrontend = {
    0x40, 0xE, 0xB, 0xD5, (void *) &D_80800BBC_gcfrontend, (void *) &D_80800D28_gcfrontend};
FrontendMapRecord D_80800DB0_gcfrontend[16] = {
    0x20, 0xC1,  0x0,   0x0, 0x21, 0x1BA, 0x0, 0x0, 0x22, 0xB7,  0x0, 0x0, 0x23, 0x88,  0x0, 0x0,
    0x24, 0x179, 0x0,   0x0, 0x25, 0x17F, 0x0, 0x0, 0x26, 0x1AF, 0x0, 0x0, 0x27, 0x172, 0x0, 0x0,
    0x28, 0x174, 0x0,   0x0, 0x29, 0x1D3, 0x0, 0x0, 0x2A, 0x1D4, 0x0, 0x0, 0x2B, 0x408, 0x0, 0x0,
    0x2C, 0x44,  0x19A, 0x1, 0x68, 0x1AE, 0x0, 0x0, 0x69, 0x418, 0x0, 0x0, 0x6B, 0x370, 0x0, 0x0};
