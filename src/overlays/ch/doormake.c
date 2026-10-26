#include "common.h"
#include "memory.h"

#define DOOR_MAKE_STATE_1527
typedef struct { u8 local_0; u8 pad_0; u8 local_1:1; u8 pad_1:7; u8 pad_2[5]; } DoorMakeChannel1527;
typedef struct { s32 local_0; s16 local_1; u8 pad_0[2]; u8 local_2:6; u8 pad_1:2; u8 pad_2; s16 local_3; s16 local_4; s16 local_5; s16 local_6[3]; s16 local_7[3]; u8 pad_3[4]; DoorMakeChannel1527 local_8[2]; } DoorMakeState1527;
extern void *func_80100074(Actor *, u32, u32);
extern void func_80103110(Actor *, s32);
extern f32 func_800136E4(f32);
extern void func_800EE940();
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern s16 D_808009A0_chdoormake[][3];
extern s16 D_80800A0C_chdoormake[][5];
extern s16 D_80800AC0_chdoormake[][5];
extern void rare_memcpy();
typedef struct { u8 unused[0x1C]; s16 unused1; s16 value; u8 unused2; u8 type; u16 active : 1; u16 state : 15; } DoorMakeEventRecord;
typedef struct { u8 a; u8 b; u16 flag:1; u16 val:15; u8 pad[4]; } DoorEnt;
typedef struct { u8 pad[0x20]; DoorEnt e[1]; } DoorData;
extern DoorData *func_80100094(s32, s32);
typedef struct { s32 local_0; s16 local_1; } DoorMakeFlags60;
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_80103EAC(Actor *);
int func_808008C4_chdoormake();

s16 *func_80800000_chdoormake(param_0, param_1, param_2, param_3)
Actor *param_0;
s32 param_1;
s32 param_2;
s32 param_3;
{
    DoorMakeState1527 *local_0;
    s32 local_1;

    local_0 = func_80100074(param_0, 0, 0x48);
    local_0->local_2 = param_1;
    local_0->local_0 = param_2;
    local_0->local_1 = param_3;
    local_0->local_3 = 0x200;
    local_0->local_4 = 0;
    local_0->local_5 = 0;
    for (local_1 = 0; local_1 != 2; local_1++) {
        local_0->local_8[local_1].local_1 = 0;
        local_0->local_8[local_1].local_0 = 0;
    }
    if (param_2 & 4) func_80103110(param_0, 1);
    return (s16 *)local_0;
}

void func_808000B8_chdoormake(Actor *param_0)
{
    s32 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (param_0->unk70_10 != 1) {
        if (param_0->unk70_10 == 4) {
            if (*local_0 & 0x800) func_8010A624(param_0);
            if (*local_0 & 0x2000) param_0->unk64_16 = 0;
        }
    } else {
        if (*local_0 & 0x800) func_8010A63C(param_0);
        if (*local_0 & 0x2000) param_0->unk64_16 = 1;
    }
}

s32 chdoormake_entrypoint_0(Actor *param_0, f32 param_1, s32 param_2)
{
    s16 *local_0;

    local_0 = func_80800000_chdoormake(param_0, 1);
    local_0[8] = func_800136E4(param_0->rotation[1] + param_1);
    local_0[9] = param_0->rotation[1];
    if (func_808008C4_chdoormake(param_0) || param_0->unk70_10 == 4) {
        if (param_2 & 1) {
            func_800FFAB0(param_0);
            return 0;
        }
        param_0->rotation[1] = local_0[8];
        func_80101FDC(param_0, 4);
        func_808000B8_chdoormake(param_0);
        return 2;
    }
    func_808000B8_chdoormake(param_0);
    return 1;
}

s32 chdoormake_entrypoint_1(Actor *param_0, f32 param_1, s32 param_2)
{
    s16 *local_0;

    local_0 = func_80800000_chdoormake(param_0, 3);
    local_0[8] = func_800136E4(param_0->rotation[0] + param_1);
    local_0[9] = param_0->rotation[0];
    if (func_808008C4_chdoormake(param_0) || param_0->unk70_10 == 4) {
        if (param_2 & 1) {
            func_800FFAB0(param_0);
            return 0;
        }
        param_0->rotation[0] = local_0[8];
        func_80101FDC(param_0, 4);
        func_808000B8_chdoormake(param_0);
        return 2;
    }
    func_808000B8_chdoormake(param_0);
    return 1;
}

s32 chdoormake_entrypoint_2(Actor *param_0, f32 param_1, f32 param_2,
    f32 param_3, s32 param_4, s32 param_5)
{
    s16 *local_0;
    f32 local_1[3];
    f32 local_2;

    local_0 = func_80800000_chdoormake(param_0, 4, param_4, param_5);
    func_800EE940(local_0 + 8, param_0->position);
    func_800EE7F8(local_1, param_0->position);
    func_800EF214(local_1, param_2, param_1, param_3);
    func_800EE940(local_0 + 11, local_1);
    local_2 = func_800EEAD4(param_0->position, local_1);
    local_0[14] = ((local_2 / (func_80103EAC(param_0) * 6.2831855f)) * -360.0f) * 256.0f;
    if (func_808008C4_chdoormake(param_0) || param_0->unk70_10 == 4) {
        if (param_4 & 1) {
            func_800FFAB0(param_0);
            return 0;
        }
        func_800EE7F8(param_0->position, local_1);
        param_0->rotation[2] = local_0[14] * 0.00390625f;
        func_80101FDC(param_0, 4);
        func_80103014(param_0);
        func_808000B8_chdoormake(param_0);
        return 2;
    }
    func_808000B8_chdoormake(param_0);
    return 1;
}

s32 chdoormake_entrypoint_3(Actor *param_0, f32 param_1, f32 param_2, f32 param_3, s32 param_4, s32 param_5)
{
    s16 *local_0;
    f32 local_1[3];

    local_0 = func_80800000_chdoormake(param_0, 2, param_4, param_5);
    func_800EE940(local_0 + 8, param_0->position);
    func_800EE7F8(local_1, param_0->position);
    func_800EF214(local_1, param_2, param_1, param_3);
    func_800EE940(local_0 + 11, local_1);
    if (func_808008C4_chdoormake(param_0) || param_0->unk70_10 == 4) {
        if (param_4 & 1) {
            func_800FFAB0(param_0);
            return 0;
        }
        func_800EE7F8(param_0->position, local_1);
        func_80101FDC(param_0, 4);
        func_80103014(param_0);
        func_808000B8_chdoormake(param_0);
        return 2;
    }
    func_808000B8_chdoormake(param_0);
    return 1;
}

s32 chdoormake_entrypoint_4(u8 *param_0, s32 param_1, s32 param_2) {
    func_80800000_chdoormake(param_0, 5, param_1, param_2);
    if ((func_808008C4_chdoormake(param_0) != 0) || (((u32) (*(u16 *)((s8 *)param_0 + 0x72)) >> 0xA) == 4)) {
        if (param_1 & 1) {
            func_800FFAB0(param_0);
            return 0;
        }
        _subaddiefade_entrypoint_1(param_0, 0);
        func_80101FDC(param_0, 4);
        func_808000B8_chdoormake(param_0);
        return 2;
    }
    func_808000B8_chdoormake(param_0);
    return 1;
}

void chdoormake_entrypoint_5(s32 param_0, f32 param_1)
{
  void *local_1 = func_80100094(param_0, 0);
  f32 *new_var;
  int new_var3;
  char *new_var2;
  new_var = &param_1;
  new_var3 = (s16) (256.0f * (*(&param_1)));
  ;
  *((s16 *) ((new_var2 = (char *) local_1) + 0xA)) = new_var3;
  if (1)
  {
  }
}

void chdoormake_entrypoint_6(Actor *param_0, f32 param_1)
{
  void *local_1 = func_80100094(param_0, 0);
  f32 *new_var;
  int new_var3;
  char *new_var2;
  new_var = &param_1;
  new_var3 = (s16) (256.0f * (*(&param_1)));
  ;
  *((s16 *) ((new_var2 = (char *) local_1) + 12)) = new_var3;
  if (1)
  {
  }
}

void chdoormake_entrypoint_7(s32 param_0, f32 param_1)
{
  void *local_1 = func_80100094(param_0, 0);
  f32 *new_var;
  int new_var3;
  char *new_var2;
  new_var = &param_1;
  new_var3 = (s16) (256.0f * (*(&param_1)));
  ;
  *((s16 *) ((new_var2 = (char *) local_1) + 0xe)) = new_var3;
  if (1)
  {
  }
}

void chdoormake_entrypoint_8(Actor *param_0, s32 param_1)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    rare_memcpy(local_0 + 0x2E, D_808009A0_chdoormake[param_1], 6);
    rare_memcpy(local_0 + 0x34, D_80800A0C_chdoormake[param_1], 10);
    rare_memcpy(local_0 + 0x3E, D_80800AC0_chdoormake[param_1], 10);
}

void chdoormake_entrypoint_9(Actor *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    DoorMakeEventRecord *local_0;

    local_0 = (DoorMakeEventRecord *)((u8 *)func_80100094(param_0, 0) + param_1 * 8);
    local_0->type = (u16)param_2;
    local_0->value = param_3;
    local_0->active = 1;
    local_0->state = 0;
}

void chdoormake_entrypoint_10(s32 param_0, s32 param_1, s32 param_2) {
    func_80100094(param_0, 0)->e[param_1].val = param_2;
}

void chdoormake_entrypoint_11(s32 param_0, s32 param_1, f32 param_2) {
    u8 *local_0 = func_80100094(param_0, 0);
    *(s16 *)(local_0 + param_1 * 8 + 0x24) = 256.0f * param_2;
}

int func_808008C4_chdoormake(param_0) Actor *param_0;
{
    DoorMakeFlags60 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0->local_1 == -1) {
        return 0;
    }
    if (local_0->local_0 & 0x10) {
        return func_800DA298(local_0->local_1) == 0;
    }
    return func_800DA298(local_0->local_1) != 0 && func_800DA298(0x9CC) != 0;
}

void chdoormake_entrypoint_12(param_0, param_1, param_2) s32 param_0; s32 param_1; u16 param_2; {
    u8 *local_0 = func_80100094(param_0, 0);
    local_0[param_1 * 8 + 0x20] = param_2;
}
