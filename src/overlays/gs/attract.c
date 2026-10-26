#include "common.h"

#define CODEX_ATTRACT_RECORDS_DEFINED
typedef struct { s16 id; s8 type; u8 flags; u8 count; u8 pad_1; } AttractEntry_gsattract_entrypoint_1;
typedef struct { s16 id; u8 count; u8 pad_0; AttractEntry_gsattract_entrypoint_1 *entries; u8 flags; u8 pad_1[3]; } AttractMode_gsattract_entrypoint_1;
typedef struct { u8 mode; u8 entry; u8 pad_2[2]; f32 timer; } AttractState_gsattract_entrypoint_1;
typedef struct { s32 pad_0; AttractState_gsattract_entrypoint_1 state; } AttractGlobal;
extern AttractMode_gsattract_entrypoint_1 D_80800490_gsattract[];
extern s32 func_800C95D4(void);
extern f32 func_800D9004(void);
extern s32 func_800167F4(void);
extern void _chattract_entrypoint_1(s32);
extern s32 func_80015FA0(s32);
extern void func_800A9C50(void);
extern u8 D_80135470[];
extern u8 D_80800493_gsattract[];
typedef struct { s16 id; s8 type; u8 pad_0; u8 count; u8 pad_1; } AttractEntry_808002A4_gsattract;
typedef struct { s16 id; u8 count; u8 pad_0; AttractEntry_808002A4_gsattract *entries; s32 pad_1; } AttractMode_808002A4_gsattract;
typedef struct { u8 mode; u8 entry; } AttractState_808002A4_gsattract;
typedef struct { s16 id; s8 type; u8 pad_0; u8 count; u8 pad_1; } AttractEntry_gsattract_entrypoint_5;
typedef struct { s16 id; u8 count; u8 pad_0; AttractEntry_gsattract_entrypoint_5 *entries; s32 pad_1; } AttractMode_gsattract_entrypoint_5;
typedef struct { u8 mode; u8 entry; } AttractState_gsattract_entrypoint_5;
extern AttractGlobal D_8013546C;
extern s16 widescreen_enabled;
extern void func_800FE4E4(void);
extern void func_800A9B84(void);
void func_808002A4_gsattract();

void gsattract_entrypoint_0()
{
  (*(f32 *)((u8 *)((u8 *) &D_8013546C) + 0x8)) = 0.0f;
}

void gsattract_entrypoint_1(void)
{
    f32 prev;

    prev = (*((AttractState_gsattract_entrypoint_1 *) D_80135470)).timer;
    if (func_800C95D4()) {
        (*((AttractState_gsattract_entrypoint_1 *) D_80135470)).timer += func_800D9004();
    }
    if ((D_80800490_gsattract[(*((AttractState_gsattract_entrypoint_1 *) D_80135470)).mode].flags & 1) && 6.0f <= (*((AttractState_gsattract_entrypoint_1 *) D_80135470)).timer && prev < 6.0f) {
        _chattract_entrypoint_1(func_800167F4() ? 3 : 1);
    }
    if ((D_80800490_gsattract[(*((AttractState_gsattract_entrypoint_1 *) D_80135470)).mode].flags & 2) && 0.5f <= (*((AttractState_gsattract_entrypoint_1 *) D_80135470)).timer && prev < 0.5f) {
        _chattract_entrypoint_1(2);
    }
    if ((D_80800490_gsattract[(*((AttractState_gsattract_entrypoint_1 *) D_80135470)).mode].entries[(*((AttractState_gsattract_entrypoint_1 *) D_80135470)).entry].flags & 1) && 1.0f <= (*((AttractState_gsattract_entrypoint_1 *) D_80135470)).timer && prev < 1.0f) {
        _chattract_entrypoint_1(0);
    }
    if (func_800C95D4() && func_80015FA0(0)) {
        func_800A9C50();
    }
}

void gsattract_entrypoint_2(s32 arg0) 
{
}
void gsattract_entrypoint_3(void) {
    s32 var_a0;

    if (func_800A8264() == 0) {
        var_a0 = D_80135470[1] + 1;
        if (var_a0 >= D_80800493_gsattract[D_80135470[0] * 12]) {
            var_a0 = 0;
        }
        func_808002A4_gsattract(var_a0);
    }
}

void gsattract_entrypoint_4(void)
{
  s32 local_0 = 2;
  ((u8 *) &D_8013546C)[4] = local_0;
}

void func_80800274_gsattract(s32 param_0) {
    D_80135470[0] = param_0;
    D_80135470[1] = D_80800493_gsattract[(u8)param_0 * 12];
}

void func_808002A4_gsattract(param_0) s32 param_0;
{
    AttractEntry_808002A4_gsattract *local_0;
    AttractState_808002A4_gsattract *local_1;
    local_1 = ((AttractState_808002A4_gsattract *) D_80135470);
    local_1->entry = param_0;
    local_0 = &((AttractMode_808002A4_gsattract *) D_80800490_gsattract)[local_1->mode].entries[param_0];
    if (local_0->type < 0) {
        func_800A791C(local_0->id, 1, 1);
    } else {
        func_800D3A14(local_0->count);
        func_800A9BA0(2, local_0->id, local_0->type);
    }
}

void gsattract_entrypoint_5(s32 param_0)
{
    AttractMode_gsattract_entrypoint_5 *local_0;
    if (!func_800A8264()) {
        if (widescreen_enabled) param_0 = 1;
        if (param_0 != D_8013546C.state.mode) func_80800274_gsattract(param_0);
        func_800FE4E4();
        func_800A9B84();
        local_0 = &((AttractMode_gsattract_entrypoint_5 *) D_80800490_gsattract)[D_8013546C.state.mode];
        func_800A9B8C(local_0->id, local_0->count);
        gsattract_entrypoint_3();
    }
}
