#include "common.h"
#include "playerstate.h"

extern void bastatetimer_set(void *, s32, f32);
extern f32 bastatetimer_getPrevious(void *, s32);
extern f32 bastatetimer_get(void *, s32);
extern void _baalarm_entrypoint_3(void *, f32, f32);
extern void func_8009DE38(void *, s32, f32);
extern int func_8008DAA8(void);
extern int func_8009EA4C(void *param_0);
extern int func_8009EA70(void *param_0);
extern struct ActorMarker { struct ActorMarker *marker; u8 unk10; };
extern u32 *param_0;
extern u8 param_1;
extern s32 D_80800AD0_bashoes;
extern s32 D_80800B4C_bashoes;
extern s32 D_80800B90_bashoes[];
extern s32 func_800B53A4(s32);
extern void func_80092E08(PlayerState *, f32 *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_80092E2C(PlayerState *, f32 *);
extern s32 D_80800BD4_bashoes;
extern void func_8009C128(PlayerState *, f32 *);
extern f32 func_8009BB5C(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80090010(void);
extern void func_800EFCD8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
typedef struct { s32 local_0; u8 local_1; u8 pad_0[3]; void (*local_2)(PlayerState *, s32, s32); } ShoeState40;
typedef struct Mass44Shoes { u8 pad_0[4]; u8 local_0; u8 pad_1[7]; void (*local_1)(PlayerState *, u8); u8 pad_2[4]; f32 local_2; } Mass44Shoes;
int bashoes_entrypoint_6();

s32 bashoes_entrypoint_0() 
{
    return 0x18;
}

s32 bashoes_entrypoint_1(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x10c)))[4];
}

s32 bashoes_entrypoint_2(s32 param_0)
{
    return ((u8 **)(param_0 + 0x10c))[0][0x10];
}

void func_80800020_bashoes(u8 *param_0)
{
    bastatetimer_set(param_0, 3, **(f32 **)(param_0 + 0x10C));
    if (func_800EA068(0x800)) {
        if ((*(u8 **)(param_0 + 0x10C))[4] == 3) func_800FC660(0x2B);
    } else {
        switch ((*(u8 **)(param_0 + 0x10C))[4]) {
        case 3: func_800C77DC(3); break;
        case 4: func_800C77DC(6); break;
        case 5: func_800C77DC(5); break;
        }
    }
}

int func_808000D4_bashoes(Actor *param_0, s32 param_1)
{
  long long new_var;
  _baalarm_free();
  func_800A0DB8(param_0, 1);
  if (param_1)
  {
    func_800C77DC(1);
    new_var = 0;
    bastatetimer_set(param_0, 3, 0);
  }
}

int func_80800128_bashoes(Actor *param_0, s32 param_1, s32 param_2, s32 param_3)
{
  _baalarm_new();
  baflag_clear(param_0, param_1);
  func_800A0DB8(param_0, param_2);
  if (param_3 != 0)
  {
    func_80800020_bashoes(param_0);
  }
}

void func_80800180_bashoes(u8 *param_0, s32 param_1)
{
    f32 local_0;
    f32 local_1;
    s32 local_2;

    local_0 = bastatetimer_getPrevious(param_0, 3);
    local_1 = bastatetimer_get(param_0, 3);
    if (!(*(u8 **)(param_0 + 0x10C))[5]) {
        _baalarm_entrypoint_3(param_0, local_0, local_1);
        if (local_1 == 0.0f && local_0 != local_1 && baflag_isFalse(param_0, 0x14)) {
            if (func_800A3274(param_0) == 11) {
                local_2 = 0x459D;
            } else {
                local_2 = 0x3EB;
            }
            func_8009DE38(param_0, local_2, 1.0f);
        }
    }
    if (baflag_isTrue(param_0, param_1)) {
        baflag_clear(param_0, param_1);
        func_80800020_bashoes(param_0);
        bastatetimer_set(param_0, 3, **(f32 **)(param_0 + 0x10C));
    }
    if (bastatetimer_isDone(param_0, 3) && !(*(u8 **)(param_0 + 0x10C))[5]) {
        bashoes_entrypoint_6(param_0, 2);
    }
}

void bashoes_entrypoint_3(s32 arg0)
{
    bashoes_entrypoint_6(arg0,0);
}

void bashoes_entrypoint_4(u8 *param_0)
{
  s32 temp_v0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x10C)))) + 0x10)) = 0;
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x10C)))) + 0x14)) = 0.0f;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x10C)))) + 5)) = 0;
  *((s32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x10C)))) + 8)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x10C)))) + 4)) = 0;
  if ((func_8008DAA8() != 0) && (func_8009EA4C(param_0) == 2))
  {
    temp_v0 = func_8009EA70(param_0);
    if (temp_v0 != 0)
    {
      bashoes_entrypoint_6(param_0, temp_v0);
      return;
    }
 if (1) { } if (1) { } if (1) { } if (1) { } if (1) { }
    bashoes_entrypoint_6(param_0, 1);
    return;
  }
  bashoes_entrypoint_6(param_0, 1);
}

void bashoes_entrypoint_5(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x10C)))[5] = v;
}

int bashoes_entrypoint_6(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    s32 local_0;
    void (*local_1)(PlayerState *, s32, s32);
    local_0 = (*(ShoeState40 **)((u8 *)param_0 + 0x10C))->local_1;
    switch (local_0) {
    case 3: func_808000D4_bashoes(param_0, param_1); break;
    case 4: func_808000D4_bashoes(param_0, param_1); break;
    case 5: func_808000D4_bashoes(param_0, param_1); break;
    }
    (*(ShoeState40 **)((u8 *)param_0 + 0x10C))->local_1 = param_1;
    switch (param_1) {
    case 1: func_8009ADF0(param_0, 13, 0); break;
    case 2: func_8009ADF0(param_0, 13, 1); break;
    case 3:
        func_8009ADF0(param_0, 13, 1);
        func_80800128_bashoes(param_0, 0x10, 2, local_0);
        break;
    case 4:
        func_8009ADF0(param_0, 13, 1);
        func_80800128_bashoes(param_0, 0x37, 3, local_0);
        break;
    case 5:
        func_8009ADF0(param_0, 13, 1);
        func_80800128_bashoes(param_0, 0x38, 4, local_0);
        break;
    }
    local_1 = (*(ShoeState40 **)((u8 *)param_0 + 0x10C))->local_2;
    if (local_1) local_1(param_0, local_0, param_1);
}

void bashoes_entrypoint_7(s32 param_0, s32 param_1) {
    *(s32 *)(*(s32 *)(param_0 + 0x10C) + 0x8) = param_1;
}

int bashoes_entrypoint_8(s32 param_0, s32 param_1)
{
  unsigned short new_var;
  new_var = 0x10C;
  *((s32 *) ((*((s32 *) (param_0 + 0x10C))) + (new_var = (0xC ^ 0) ^ 0))) = param_1;
}

s32 bashoes_entrypoint_9(u8 *param_0) {
    return ((*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x10C)))) + (0x14))) > 0.0f) ? 1 : 0;
}

void bashoes_entrypoint_10(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 0x10C) + 0x14) = param_1;
}

void bashoes_entrypoint_11(param_0, param_1)
u32 *param_0;
{
  *((u8*)((char*)*((u32*)((char*)param_0 + 0x10C)) + 0x10)) = param_1;
}

void bashoes_entrypoint_12(void *param_0, float param_1)
{
  void *local_0;
  local_0 = *((void **) (((char *) param_0) + 0x10C));
  *((float *) (*((void **) (((char *) param_0) + 0x10C)))) = param_1;
}

void bashoes_entrypoint_13(PlayerState *param_0)
{
    void (*local_0)(PlayerState *, u8);
    local_0 = ((Mass44Shoes *)(*(void **)((u8 *)param_0 + 0x10C)))->local_1;
    if (local_0) local_0(param_0,
        ((Mass44Shoes *)(*(void **)((u8 *)param_0 + 0x10C)))->local_0);
    switch (((Mass44Shoes *)(*(void **)((u8 *)param_0 + 0x10C)))->local_0) {
    case 1:
        break;
    case 2:
        if (baflag_isTrue(param_0, 0x10)) { bashoes_entrypoint_6(param_0, 3); return; }
        if (baflag_isTrue(param_0, 0x37)) { bashoes_entrypoint_6(param_0, 4); return; }
        if (baflag_isTrue(param_0, 0x38)) { bashoes_entrypoint_6(param_0, 5); return; }
        break;
    case 3:
        func_80800180_bashoes(param_0, 0x10);
        if (baflag_isTrue(param_0, 0x37)) { bashoes_entrypoint_6(param_0, 4); return; }
        if (baflag_isTrue(param_0, 0x38)) { bashoes_entrypoint_6(param_0, 5); return; }
        break;
    case 4:
        func_800D9078(&((Mass44Shoes *)(*(void **)((u8 *)param_0 + 0x10C)))->local_2);
        func_80800180_bashoes(param_0, 0x37);
        if (baflag_isTrue(param_0, 0x10)) { bashoes_entrypoint_6(param_0, 3); return; }
        if (baflag_isTrue(param_0, 0x38)) { bashoes_entrypoint_6(param_0, 5); return; }
        break;
    case 5:
        func_80800180_bashoes(param_0, 0x38);
        if (baflag_isTrue(param_0, 0x10)) { bashoes_entrypoint_6(param_0, 3); return; }
        if (baflag_isTrue(param_0, 0x37)) bashoes_entrypoint_6(param_0, 4);
        break;
    }
}

void bashoes_entrypoint_14(s32 param_0) {
    s32 local_0;
    s32 local_1;

    local_0 = func_8009E69C(param_0, 0x80);
    local_1 = func_800F6B34();
    if ((local_0 == 0) && (local_1 == 0)) {
        bashoes_entrypoint_6(param_0, 1);
    }
}

void bashoes_entrypoint_15(u8 *param_0) {
    if ((func_8009E6C4(param_0, 0x80) == 0) && ((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x10C)))) + (8))) = 0, (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x10C)))) + (0xC))) = 0, (bashoes_entrypoint_1(param_0) == 1))) {
        if (baflag_isTrue(param_0, 0x10) != 0) {
            bashoes_entrypoint_6(param_0, 3);
            return;
        }
        if (baflag_isTrue(param_0, 0x37) != 0) {
            bashoes_entrypoint_6(param_0, 4);
            return;
        }
        if (baflag_isTrue(param_0, 0x38) != 0) {
            bashoes_entrypoint_6(param_0, 5);
            return;
        }
        bashoes_entrypoint_6(param_0, 2);
    }
}

void bashoes_entrypoint_16(s32 param_0) {
    f32 local_0[3];
    s32 local_1;

    local_1 = func_800B53A4(6);
    func_8009C128(param_0, local_0);
    func_800BABB8(local_1, local_0, local_0, 1.0f, &D_80800AD0_bashoes);
}

void bashoes_entrypoint_17(s32 param_0) {
    f32 local_0[3];
    s32 local_1;

    local_1 = func_800B53A4(0x1E);
    func_8009C128(param_0, local_0);
    func_800BABB8(local_1, local_0, local_0, 1.0f, &D_80800B4C_bashoes);
}

void bashoes_entrypoint_18(PlayerState *param_0)
{
    f32 local_1[3];
    s32 local_0;

    local_0 = func_800B53A4(0xA);
    func_80092E08(param_0, local_1);
    local_1[1] -= 30.0f;
    func_800BABB8(local_0, local_1, local_1, 1.0f, D_80800B90_bashoes);
}

void bashoes_entrypoint_19(PlayerState *param_0)
{
    f32 local_1[3];
    s32 local_0;

    local_0 = func_800B53A4(0xA);
    func_80092E2C(param_0, local_1);
    local_1[1] -= 30.0f;
    func_800BABB8(local_0, local_1, local_1, 1.0f, D_80800B90_bashoes);
}

void bashoes_entrypoint_20(PlayerState *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_3;
    f32 local_2;

    func_8009C128(param_0, local_1);
    local_2 = func_800F10B4(func_8009BB5C(param_0), 0.0f, 1000.0f, 10.0f, 50.0f);
    local_3 = func_80090010();
    func_800EFCD8(local_0, local_3, local_2);
    local_0[1] = 0.0f;
    local_1[0] += local_0[0];
    local_1[1] += local_0[1];
    local_1[2] += local_0[2];
    local_1[1] += 6.0f;
    func_800BBCB8(local_1, 0, 1.0f, 1, &D_80800BD4_bashoes);
}
