#include "core2/1EC3810.h"

extern s16 D_80132DCC;
extern int D_80127EF4;
extern s32 D_80132DC4;
extern void _gcsectionDll_entrypoint_3();
extern s16 D_80132DC8;
extern s16 D_80132DCA;
extern s32 D_80127EF8;
extern s32 D_80127EF0;
extern u16 D_80132DCE;
extern int D_80132DD8[];
extern int D_80132E78[];
extern u8 D_80132DD0[];
extern void func_800EE7F8(s32 *, s32);
typedef struct { f32 position[3]; void *marker; s32 argument; } LocalDraw;
typedef struct { s32 count, capacity; LocalDraw entries[8]; } LocalState;
extern void *func_80103C94(Actor *);
extern void func_800F5A00(s32, f32 *);
extern void func_800D8B80(s32, s32, void *, void *, f32, s32, s32, void *, void *);
extern void func_800F8418(s32, f32 *);
extern s32 func_800D89C8(s16, s32, f32 *, f32 *, f32, f32 *, void *, f32 *, f32 *);
typedef struct MarkerEA MarkerEA;
typedef struct { s32 (*local_0)(MarkerEA *, s32 *, s32 *, f32 *, s32); } HandlerEA_800EA628;
typedef union { struct { MarkerEA *local_0; s32 pad4; u32 pad8:27; u32 local_1:1; u32 local_2:1; u32 pad:1; u32 local_3:1; u32 local_4:1; } local_0; struct { u16 pad; u8 local_0[2]; s16 local_1[3]; u8 local_2; u8 padB; } local_1; } EntryEA;
typedef struct { u32 pad; f32 local_0[3]; u8 pad10[0x28]; f32 local_1; u8 pad3C[8]; f32 local_2[3]; u8 pad50[0x14]; u32 pad64:14; u32 local_3:1; u32 pad64a:17; u16 pad68; u16 local_4; u8 pad6C[0x14]; u16 local_5; } ActorEA_800EA628;
extern EntryEA *func_800E9E88(void *);
extern EntryEA *func_800E9EB4(void *);
extern s32 _gsproplookup_entrypoint_0(EntryEA *);
extern void *func_800BFC54(s32);
extern void *func_800B2720(void *);
extern void *func_800B2840(void *);
extern s32 func_800AD1AC(void *, void *, f32 *, f32 *, f32, f32 *, f32, f32 *, s32);
extern ActorEA_800EA628 *func_80106790();
extern void func_80103508(ActorEA_800EA628 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void *func_80103AA0(MarkerEA *);
extern void *func_80103CDC(ActorEA_800EA628 *, void *);
extern void func_800D62E4(u16);
extern void *func_800BFC34(s32);
extern void func_800BFC74(s32);
extern f32 func_800B2354(void *);
extern s32 func_800AAEF4(f32 *, f32, s32 *, s32 *);
extern s32 func_800AB868(void *, void *, f32 *, f32 *, f32, s32 *, s32 *, f32 *, s32);
extern s32 D_80132DD4;
extern void func_801039E4(MarkerEA *);
typedef struct { u8 pad[4]; s32 (*local_0)(MarkerEA *, f32 *, f32 *, f32, f32 *, s32, s32); } HandlerEA_800EAA2C;
typedef struct { u32 pad; f32 local_0[3]; u8 pad10[0x28]; f32 local_1; u8 pad3C[8]; f32 local_2[3]; u8 pad50[0x14]; u32 pad64:14; u32 local_3:1; u32 pad64a:17; u16 pad68; u16 local_4; } ActorEA_800EAA2C;
extern s32 func_800AC848(void *, void *, f32 *, f32 *, f32, f32 *, f32 *, f32, f32 *, s32, s32);
extern s32 func_800CB854(s32);
typedef struct { u8 pad[8]; s32 (*local_0)(MarkerEA *, f32 *, f32, f32 *, s32); } HandlerEA_800EADFC;
typedef struct { u32 pad; f32 local_0[3]; u8 pad10[0x28]; f32 local_1; u8 pad3C[8]; f32 local_2[3]; u8 pad50[0x14]; u32 pad64:14; u32 local_3:1; u32 pad64a:17; u16 pad68; u16 local_4; } ActorEA_800EADFC;
typedef struct { u8 pad0[0xC]; void (*unkC)(void *, s32, s32); } O_EB2DC;
typedef struct { u8 pad0[0x28]; u32 f0 : 22; u32 flag : 1; u32 rest : 9; } S_EB2DC;
extern O_EB2DC *func_800EC3C4(S_EB2DC *);
typedef struct { u8 pad0[0x38]; f32 unk38; u8 pad3C[0x2E]; u16 unk6A; } S_EB350;
extern void func_80103328();
s32 func_800EB350();

extern u16 D_80132DC2;
extern s32 D_80132DC0;

int func_800E9F20(s32 param_0, s32 param_1)
{
  u32 local_0;
  u32 local_1;
  local_0 = func_800A7180();
  if (D_80132DCC == 0)
  {
    func_800E44FC(local_0);
    return;
  }
  local_1 = D_80132DCC;
  func_800BE9B0();
  func_800BFD6C(local_0, param_0);
  func_800E44FC(local_0);
  func_800D2A44(local_0);
  func_800BC8F8(local_0);
  func_800BE9E4(local_0);
  func_800BD594(local_0);
  func_800EB51C(1, local_0);
  func_800EB51C(5, local_0);
  func_800F5008(local_0);
  func_800EB51C(0, local_0);
  func_800B525C(local_0);
  if (func_800BF3E4() != 0)
  {
    func_800BEA24(local_0);
  }
  func_800B7BB0();
  func_800F50D0(local_0);
  func_800EB51C(2, local_0);
  func_800B52EC(local_0);
  func_800BC948(local_0);
  func_800EB51C(6, local_0);
  if (D_80127EF4 != 0)
  {
    _sufade_entrypoint_1(local_0);
  }
  func_800A8EF0(local_0, param_0);
  func_800F51CC();
}

// Get World Section
MapId func_800EA05C(void) 
{
	return D_80132DC2;
}

s32 func_800EA068(s32 param_0){
    s32 local_0 = param_0;
    _gcsectionDll_entrypoint_3(D_80132DC4, local_0);
}

s32 func_800EA090()
{
  return D_80132DC8;
}

int func_800EA09C()
{
  return *(s16 *) &D_80132DC0;
}

void func_800EA0A8()
{
    _gsworldDll_entrypoint_1(&D_80132DC0);
}

void func_800EA0CC(s32 param_0, s32 param_1, s32 param_2)
{
  _cothemedll_entrypoint_0();
  func_800DBB5C();
  func_800BF8BC(param_0);
  func_800C0064(param_0);
  _gsworldDll_entrypoint_2(((int *) &D_80132DC0), param_0, param_1, param_2);
}

void func_800EA124()
{
    _gsworldDll_entrypoint_4(&D_80132DC0);
}

int func_800EA148(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _gsworldDll_entrypoint_3(((s32 *) &D_80132DC0), local_0);
  return;
}

s32 func_800EA170()
{
  func_800C718C();
  func_800D8744();
  func_800FA2C0();
  if (func_800A8184() != 4)
  {
    func_800B7E38();
  }
  if (D_80132DCA == 0)
  {
    return 1;
  }
  func_800FFBE4();
  func_800EE718();
  if (D_80127EF8 != 0)
  {
    _idworld_entrypoint_5();
  }
  func_800E97C0();
  func_8010D7EC();
  func_800EE748();
  func_800F84FC();
  func_800BF710();
  func_800B592C();
  func_8008B850();
  func_800E1804();
  func_800A8E9C();
  func_800CF264();
  func_800CE628();
  func_800D2574();
  if (func_800EA09C() == 2)
  {
    func_800A1450();
    func_800DAE9C();
  }
  func_800C57F0();
  if (D_80127EF0 != 0)
  {
    _sulights_entrypoint_9();
  }
  func_800BFCC4(1);
  func_8001B50C();
  func_800D6E54(1);
  func_800ABA9C();
  func_800BFF70();
  func_800B50F0();
  func_800DBC68();
  func_800E8A68();
  func_800D5270();
  func_800C0438();
  func_800FFD10(1);
  func_800C7494();
  func_80100534();
  func_80100C74();
  func_800FFBEC();
  func_800BF7E0();
  func_800C8A08();
  func_800D154C();
  return 1;
}

void func_800EA334(s32 param_0)
{
  D_80132DCA = (s16)param_0;
}

int func_800EA340()
{
  return D_80132DCA;
}

void func_800EA34C(s32 param_0)
{
  D_80132DCC = (s16)param_0;
}

int func_800EA358()
{
  return D_80132DCC;
}

u16 func_800EA364()
{
  return D_80132DCE;
}

void func_800EA3A0();

void func_800EA370()
{
    func_800EA3A0();
}

void func_800EA390(void) {
}

void func_800EA398(void) {
}

void func_800EA3A0()
{
  int *local_0;
  int *local_1;
  local_0 = &((int *) D_80132DD0)[0];
 do { local_1 = &D_80132DD8[0]; local_0 = &((int *) D_80132DD0)[0]; do { func_800EFD24(local_1); local_1 += 5; local_0 += 5; local_0[0] = 0; local_0[1] = 0; } while (local_1 != (&D_80132E78[0])); } while (0);
}

void func_800EA400(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  func_800EE7F8((((u8 *) (&D_80132DD0)) + (param_0 * 0x14)) + 8, param_2);
  *((s32 *) ((((u8 *) (&D_80132DD0)) + (param_0 * 0x14)) + 0x14)) = param_1;
  *((s32 *) ((((u8 *) (&D_80132DD0)) + (param_0 * 0x14)) + 0x18)) = param_3;
}

void func_800EA45C(void)
{
    LocalDraw *local_0;
    f32 local_1[3];
    s32 local_2;
    Actor *local_3;
    for (local_2 = 0; local_2 < 8; local_2++) {
        if ((*((LocalState *) D_80132DD0)).entries[local_2].marker) {
            local_0 = &(*((LocalState *) D_80132DD0)).entries[local_2];
            local_3 = func_80106790((*((LocalState *) D_80132DD0)).entries[local_2].marker);
            func_800F5A00(local_2, local_1);
            func_800D8B80(*(s16 *)((u8 *)local_3 + 0x80), local_2,
                local_3->position, local_3->rotation, local_3->scale, 0,
                (*((LocalState *) D_80132DD0)).entries[local_2].argument, func_80103C94(local_3), local_0->position);
        }
    }
}

void func_800EA51C(void) {
    u8 *var_s2;
    f32 sp60[3];
    s32 var_s1;
    u8 *temp_s0;

    var_s2 = &D_80132DD0;
    var_s1 = 0;
    do {
        if ((*(s32 *)((u8 *)(var_s2) + (0x14))) != 0) {
            temp_s0 = func_80106790((*(s32 *)((u8 *)(var_s2) + (0x14))));
            func_800F5A00(var_s1, sp60);
            if (func_800D89C8((*(s16 *)((u8 *)(temp_s0) + (0x80))), var_s1, temp_s0 + 4, temp_s0 + 0x44, (*(f32 *)((u8 *)(temp_s0) + (0x38))), 0, func_80103C94(temp_s0), sp60, sp60) != 0) {
                sp60[1] -= 10.0f;
                func_800F8418(var_s1, sp60);
            }
            (*(s32 *)((u8 *)(var_s2) + (0x14))) = 0;
        }
        var_s1 += 1;
        var_s2 += 0x14;
    } while (var_s1 != 8);
}

void func_800EA600(s32 param_0, s32 param_1)
{
  *(s32*)((s32 *) D_80132DD0) = param_0;
  *(s32*)((char*)((s32 *) D_80132DD0) + 4) = param_1;
}

int func_800EA614()
{
  ((s32 *) D_80132DD0)[0] = 0;
  ((s32 *) D_80132DD0)[1] = 0;
}

struct MarkerEA { u8 pad[0xC]; HandlerEA_800EA628 *(*local_0)(void); u32 pad10; u16 local_1; u16 pad16; u16 local_2; };

s32 func_800EA628(void *param_0, s32 *param_1, s32 *param_2, f32 *param_3, s32 param_4)
{
    s32 local_0 = 0;
    s32 local_1;
    EntryEA *local_2;
    EntryEA *local_3;
    void *local_4;
    void *local_5;
    ActorEA_800EA628 *local_6;
    f32 local_7[3];
    f32 local_8[3];
    MarkerEA *local_9;
    HandlerEA_800EA628 *local_10;
    f32 local_11;
    s32 local_12;
    s32 local_13;
    void *local_14;
    s32 local_15;
    s32 local_16;
    local_2 = func_800E9E88(param_0);
    local_3 = func_800E9EB4(param_0);
    for (; local_2 < local_3; local_2++) {
        if (local_2->local_0.local_1) {
            if (!local_2->local_0.local_4) {
                if (!local_2->local_0.local_3) continue;
                local_12 = _gsproplookup_entrypoint_0(local_2);
                local_4 = func_800BFC54(local_12);
                if (!local_4) {
                    if (func_800CB854(0) != 1) continue;
                    local_4 = func_800BFC34(local_12);
                    if (!local_4) continue;
                }
                local_5 = func_800B2720(local_4);
                if (local_5) {
                    local_2->local_0.local_2 = 1;
                    local_7[0] = local_2->local_1.local_1[0];
                    local_7[1] = local_2->local_1.local_1[1];
                    local_7[2] = local_2->local_1.local_1[2];
                    local_8[0] = 0.0f;
                    local_8[1] = (u32)local_2->local_1.local_0[0] * 2.0f;
                    local_8[2] = (u32)local_2->local_1.local_0[1] * 2.0f;
                    local_11 = (u32)local_2->local_1.local_2 * 0.01f;
                    if (func_800AAEF4(local_7, func_800B2354(func_800B2840(local_4)) * local_11, param_1, param_2)) {
                        local_1 = func_800AB868(local_5, func_800B2840(local_4), local_7, local_8,
                        local_11, param_1, param_2, param_3, param_4);
                        if (local_1) local_0 = local_1;
                    }
                }
                if (local_4) func_800BFC74(local_12);
            } else {
                local_9 = local_2->local_0.local_0;
                if (!local_2->local_0.local_2) continue;
                if (!(local_9->local_2 & 1)) continue;
                if (local_9->local_0 && (local_10 = local_9->local_0())->local_0) {
                    local_1 = local_10->local_0(local_9, param_1, param_2, param_3, param_4);
                    if (local_1) local_0 = local_1;
                } else {
                    local_6 = func_80106790(local_9);
                    if (local_6->local_3) continue;
                    if (func_800EB350(local_6, param_1, param_2)) continue;
                    if (func_800CB854(0) == 1) func_80103508(local_6);
                    local_4 = func_80103AA0(local_9);
                    if (!local_4) continue;
                    local_5 = func_800B2720(local_4);
                    if (local_5) {
                        local_1 = func_800AB868(local_5, func_80103CDC(local_6, local_4), local_6->local_0,
                        local_6->local_2, local_6->local_1, param_1, param_2, param_3, param_4);
                        if (local_1 && *(void **) D_80132DD0) (*(void (**)(void *, s32)) D_80132DD0)(local_9, D_80132DD4);
                        if (local_1 && func_800CB854(&local_14) == 1) {
                            func_801039E4(local_9);
                            if (local_6->local_5) func_800EA400(local_14, local_9, param_2, local_1);
                        }
                        if (local_1) local_0 = local_1;
                    }
                    if (local_4) func_800D62E4(local_9->local_1);
                }
            }
        }
    }
    return local_0;
}

s32 func_800EAA2C(void *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 *param_4, s32 param_5, s32 param_6)
{
    s32 local_0 = 0;
    s32 local_1;
    EntryEA *local_2;
    EntryEA *local_3;
    void *local_4;
    void *local_5;
    ActorEA_800EAA2C *local_6;
    f32 local_7[3];
    f32 local_8[3];
    MarkerEA *local_9;
    HandlerEA_800EAA2C *local_10;
    s32 local_11;
    s32 local_12;
    local_2 = func_800E9E88(param_0);
    local_3 = func_800E9EB4(param_0);
    for (; local_2 < local_3; local_2++) {
        if (!(local_2->local_0.local_1)) continue;
        if (!local_2->local_0.local_4) {
            if (local_2->local_0.local_3) {
                local_11 = _gsproplookup_entrypoint_0(local_2);
                local_4 = func_800BFC54(local_11);
                local_5 = func_800B2720(local_4);
                if (local_5) {
                    local_7[0] = local_2->local_1.local_1[0];
                    local_7[1] = local_2->local_1.local_1[1];
                    local_7[2] = local_2->local_1.local_1[2];
                    local_8[0] = 0.0f;
                    local_8[1] = (u32)local_2->local_1.local_0[0] * 2.0f;
                    local_8[2] = (u32)local_2->local_1.local_0[1] * 2.0f;
                    local_1 = func_800AC848(local_5, func_800B2840(local_4), local_7, local_8,
                    (u32)local_2->local_1.local_2 * 0.01f, param_1, param_2, param_3, param_4, param_5, param_6);
                    if (local_1 && *(void **) D_80132DD0) (*(void (**)(void *, s32)) D_80132DD0)(local_2->local_0.local_0, D_80132DD4);
                    if (local_1) local_0 = local_1;
                }
                if (local_4) func_800BFC74(local_11);
        } } else {
            local_9 = local_2->local_0.local_0;
            if (!(local_2->local_0.local_2)) continue;
            if (!(local_9->local_2 & 1)) continue;
            local_6 = func_80106790(local_9);
            if (!(!local_6->local_3)) continue;
            if (local_9->local_0 && (local_10 = local_9->local_0())->local_0) {
                local_1 = local_10->local_0(local_9, param_1, param_2, param_3, param_4, param_5, param_6);
                if (local_1) local_0 = local_1;
            } else {
                func_80103328(local_6);
                if ((u32)local_6->local_4 * local_6->local_1 <= func_800EEAD4(param_2, local_6->local_0) - param_3) continue;
                if (func_800CB854(0) == 1) func_80103508(local_6);
                local_4 = func_80103AA0(local_9);
                local_5 = func_800B2720(local_4);
                if (local_5) {
                    local_1 = func_800AC848(local_5, func_80103CDC(local_6, local_4), local_6->local_0,
                    local_6->local_2, local_6->local_1, param_1, param_2, param_3, param_4, param_5, param_6);
                    if (local_1) local_0 = local_1;
                }
                if (local_4) func_800D62E4(local_9->local_1);
            }


    }  }
    return local_0;
}

s32 func_800EADFC(void *param_0, f32 *param_1, f32 param_2, f32 *param_3, s32 param_4)
{
    s32 local_0 = 0;
    s32 local_1;
    EntryEA *local_2;
    EntryEA *local_3;
    void *local_4;
    void *local_5;
    ActorEA_800EADFC *local_6;
    f32 local_7[3];
    f32 local_8[3];
    MarkerEA *local_9;
    HandlerEA_800EADFC *local_10;
    s32 local_11;
    s32 local_12;
    local_2 = func_800E9E88(param_0);
    local_3 = func_800E9EB4(param_0);
    for (; local_2 < local_3; local_2++) {
        if (local_2->local_0.local_1) {
            if (!local_2->local_0.local_4) {
                if (local_2->local_0.local_3) {
                    local_4 = func_800BFC54(_gsproplookup_entrypoint_0(local_2));
                    local_5 = func_800B2720(local_4);
                    if (local_5) {
                        local_7[0] = local_2->local_1.local_1[0];
                        local_7[1] = local_2->local_1.local_1[1];
                        local_7[2] = local_2->local_1.local_1[2];
                        local_8[0] = 0.0f;
                        local_8[1] = (u32)local_2->local_1.local_0[0] * 2.0f;
                        local_8[2] = (u32)local_2->local_1.local_0[1] * 2.0f;
                        local_1 = func_800AD1AC(local_5, func_800B2840(local_4), local_7, local_8,
                        (u32)local_2->local_1.local_2 * 0.01f, param_1, param_2, param_3, param_4);
                        if (local_1) local_0 = local_1;
                    }
            } } else {
                local_9 = local_2->local_0.local_0;
                if (local_2->local_0.local_2) {
                    if (local_9->local_2 & 1) {
                        local_6 = func_80106790(local_9);
                        if (!local_6->local_3) {
                            if (local_9->local_0 && (local_10 = local_9->local_0())->local_0) {
                                local_1 = local_10->local_0(local_9, param_1, param_2, param_3, param_4);
                                if (local_1) local_0 = local_1;
                            } else {
                                func_80103328(local_6);
                                if ((u32)local_6->local_4 * local_6->local_1 <= func_800EEAD4(param_1, local_6->local_0) - param_2) continue;
                                if (func_800CB854(0) == 1) func_80103508(local_6);
                                local_4 = func_80103AA0(local_9);
                                local_5 = func_800B2720(local_4);
                                if (local_5) {
                                    local_1 = func_800AD1AC(local_5, func_80103CDC(local_6, local_4), local_6->local_0,
                                    local_6->local_2, local_6->local_1, param_1, param_2, param_3, param_4);
                                    if (local_1) local_0 = local_1;
                                }
                                if (local_4) func_800D62E4(local_9->local_1);
                            }
                        }
                    }
    } } } }
    return local_0;
}

s32 func_800EB15C(u8 *param_0)
{
  if ((*((s32 *) (((s8 *) param_0) + 0x18))) & 1)
  {
    return 0;
  }
  if ((((u32) (*((u32 *) (((s8 *) param_0) + 0x24)))) >> 0x16) == 0)
  {
    return 1;
  }
  if ((func_800D3948() == 0) && (func_800F6774(func_800F54E4()) == 0))
  {
    if ((((u16) (*((u16 *) (((s8 *) param_0) + 0x18)))) & 1) && (func_80102F74(func_80106790(param_0), 0x88000000) != 0))
    {
      return 1;
    }
    return 0;
  }
  block_10:
  return 1;

}

void func_800EB210(s32 param_0, s32 param_1, s32 param_2) {
    u8 *temp_v0;
    u8 *temp_v1;

    if (func_800EB15C(param_0) != 0) {
        temp_v0 = func_800EC3C4(param_0);
        temp_v1 = temp_v0;
        switch (param_2) {
        case 0:
            if ((*(s32 *)((s8 *)(temp_v0) + 0)) != 0) {
                (*(s32 (**)(s32, s32))((s8 *)(temp_v1) + 0))(param_0, param_1);
                return;
            }
            break;
        case 1:
            if ((*(s32 *)((s8 *)(temp_v0) + 4)) != 0) {
                (*(s32 (**)(s32, s32))((s8 *)(temp_v1) + 4))(param_0, param_1);
                return;
            }
            break;
        case 2:
            if ((*(s32 *)((s8 *)(temp_v0) + 8)) != 0) {
                (*(s32 (**)(s32, s32))((s8 *)(temp_v1) + 8))(param_0, param_1);
            }
            break;
        }
    }
}

void func_800EB2DC(S_EB2DC *param_0, s32 param_1, s32 param_2) {
    O_EB2DC *o;
    if (func_800EB15C(param_0) == 0) {
        return;
    }
    if (param_0->flag == 0) {
        return;
    }
    o = func_800EC3C4(param_0);
    if (param_0 == 0) {
        return;
    }
    if (o->unkC == 0) {
        return;
    }
    o->unkC(param_0, param_1, param_2);
}

s32 func_800EB350(param_0, param_1, param_2) S_EB350 * param_0; s32 param_1; s32 param_2; {
    func_80103328(param_0, param_1, param_2);
    return func_800AAEF4((u8 *)param_0 + 4,
        (f32)(u32)param_0->unk6A * param_0->unk38 * 1.1f, param_1, param_2) == 0;
}
