#include "common.h"

#define FRONTEND_TEXT_RECORD_1548
typedef struct { u8 pad_0; u8 local_0; s16 local_1; u8 pad_1[8]; } FrontendTextSpan;
typedef struct { u8 a; u8 unk1; s16 b; u8 pad4[8]; } FrontEnt;
extern FrontEnt D_80800D80_gcfrontend[];
typedef struct { u8 pad[0xC]; u8 fC; u8 padD[3]; } GfEnt;
typedef struct { u8 a; u8 pad; s16 b; GfEnt *ptr; s32 x; } FrontEnt2;
typedef struct { u8 first; u8 unused[3]; u8 *text; s16 *values; } FrontendTextRecord;
extern FrontendTextRecord D_80800DA4_gcfrontend;
extern void func_800D3CF8(s32);
extern void func_800D3D10(s32);
typedef struct { s32 a; s32 b; u8 pad[5]; u8 c; u8 pad2[2]; } FrontendEntry;
extern FrontendEntry D_80800C9C_gcfrontend[];
extern void func_800DA544(s32);
typedef struct { u8 a; u8 b; u8 pad[10]; } FrR;
typedef struct { s16 map; s16 replacement; s16 level; s16 entrance; } FrontendMapRecord;
extern FrontendMapRecord D_80800DB0_gcfrontend[16];
typedef struct { u16 type; s16 arg; } FrontendCmd;
typedef struct { s32 count; FrontendCmd *cmds; } FrontendScript;
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
void func_80800520_gcfrontend();

void gcfrontend_entrypoint_0(void) {
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

int gcfrontend_entrypoint_2(void) {
    return gcfrontend_entrypoint_1(0) != 0 || gcfrontend_entrypoint_1(1) != 0 || gcfrontend_entrypoint_1(2) != 0;
}

s32 gcfrontend_entrypoint_3(s32 param_0) {
    FrontEnt *local_0 = &((FrontEnt *) D_80800D80_gcfrontend)[func_80800450_gcfrontend()];
    return func_800DA298(local_0->b + param_0 - local_0->a);
}

u8 gcfrontend_entrypoint_4(param_0) s32 param_0;
{
  return D_80800D80_gcfrontend[param_0].unk1;
}

u8 gcfrontend_entrypoint_5(param_0) s32 param_0;
{
  return ((u8 *) D_80800D80_gcfrontend)[param_0 * 12];
}

u8 gcfrontend_entrypoint_6(s32 param_0) {
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
        local_5 = (&((FrontendTextRecord *)D_80800D80_gcfrontend)[local_0])->text;
        param_0 -= (&((FrontendTextRecord *)D_80800D80_gcfrontend)[local_0])->first;
        if (local_0 != 2) local_3 = local_5 + param_0 * 16 + 4;
        local_2 = (s16 *)(local_5 + param_0 * 16);
        if ((void *)&D_80800DA4_gcfrontend == (&D_80800D80_gcfrontend[local_0])) local_1 = 3;
        func_800D3D10(param_1);
        func_80800738_gcfrontend(local_2, local_3, 0, local_1);
    }
}

void func_808002DC_gcfrontend(s32 param_0, s32 param_1) {
    FrontendEntry *local_0 = &D_80800C9C_gcfrontend[param_0 - 0xA0];
    func_80800738_gcfrontend(&local_0->a, &local_0->b, local_0->c, param_1);
}

s32 gcfrontend_entrypoint_8(s32 param_0, s32 param_1) {
    if (param_1 != 0) {
        param_1 = 1;
    }
    else{
        param_1 = 0;
    }
    func_808002DC_gcfrontend(param_0, param_1);
}

void gcfrontend_entrypoint_9(param_0) s32 param_0; {
    FrontEnt *local_0 = &((FrontEnt *) D_80800D80_gcfrontend)[func_80800450_gcfrontend()];
    func_800DA544(local_0->b + param_0 - local_0->a);
}

s32 gcfrontend_entrypoint_10(void){
    func_800D3CF8(0);
    func_808002DC_gcfrontend(0xA0, -1);
}

s32 gcfrontend_entrypoint_11(void) {
    gcfrontend_entrypoint_7(func_800D3D04(), 0);
}

s32 gcfrontend_entrypoint_12(void) {
    func_800AA074();
    func_800AA00C();
    gcfrontend_entrypoint_10();
}

s32 gcfrontend_entrypoint_13(void){
    func_800D37D4();
    func_808002DC_gcfrontend(0xA6, -1);
}

s32 func_80800450_gcfrontend(param_0) s32 param_0;
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

void func_80800738_gcfrontend(param_0, param_1, param_2, param_3) u8 *param_0; s32 param_1; s32 param_2; s32 param_3; {
    s32 sp1C;
    s32 sp18;

    sp1C = (s32) (*(s16 *)((s8 *)(param_0) + (2)));
    sp18 = (s32) (*(s16 *)((s8 *)(param_0) + (0)));
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
