#include "core2/1E77A20.h"

typedef struct { f32 unk0; u8 pad[36]; } E40_9E138;
typedef struct { s32 pad; s16 local_0; s16 pad1; void (*local_1)(PlayerState *, f32 *, s16); f32 local_2[3]; f32 local_3, local_4, local_5, local_6; } Attachment9E154;
typedef struct { u8 pad[0x114]; Attachment9E154 *local_0; } Player9E154;
extern void func_80092CDC();
extern void func_8009C128(PlayerState *, f32 *);
extern void func_80092D18(PlayerState *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EF8BC(f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern s32 func_800EEEA8(f32 *);
extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern f32 func_800136E4(f32);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
extern void func_80096394(PlayerState *, f32 *);
extern s32 func_8009CA70(void *, void *, s32);
extern u8 unk120[];
extern s32 func_8009CBDC(PlayerState *, s32);
typedef struct { u8 pad_0[0x120]; PlayerState *local_0; } Struct8009E74C;
typedef struct { s16 unk0; s16 unk2; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } F8009E7C8;
extern void *func_8009CB44();
void func_8009E55C(PlayerState *param_0, s32 param_1, f32 param_2);
void func_8009E5A4();

s32 func_8009E130() 
{
    return 0xF4;
}

f32 func_8009E138(PlayerState *param_0, s32 param_1) {
    return (*(E40_9E138 **)((u8 *)param_0 + 0x114))[param_1].unk0;
}

void func_8009E154(PlayerState *param_0, s32 param_1, f32 *param_2) {
    f32 local_0[3], local_1[3], local_2[3], local_3[3], local_4[3], local_5[3];
    f32 local_6;
    if (((Player9E154 *)param_0)->local_0[param_1].local_1) {
        ((Player9E154 *)param_0)->local_0[param_1].local_1(param_0, local_0, ((Player9E154 *)param_0)->local_0[param_1].local_0);
    } else {
        func_80092CDC(param_0, local_0, ((Player9E154 *)param_0)->local_0[param_1].local_0);
        func_8009C128(param_0, local_2);
        func_80092D18(param_0, local_4);
        func_800EF04C(local_2, local_4);
        if (func_800EEEA8(local_0)) {
            func_800EE7F8(local_3, ((Player9E154 *)param_0)->local_0[param_1].local_2);
            func_800EF8BC(local_3, local_3, func_8009BFCC(param_0));
            func_800EF934(local_3, local_3, yaw_get(param_0));
            func_800EE780(local_0, local_2, local_3);
        } else {
            func_800EFB24(local_3, local_0, local_2);
            func_800EF934(local_3, local_3, -yaw_get(param_0));
            func_800EF8BC(local_3, local_3, -func_8009BFCC(param_0));
            func_800EE7F8(((Player9E154 *)param_0)->local_0[param_1].local_2, local_3);
        }
    }
    local_0[1] += ((Player9E154 *)param_0)->local_0[param_1].local_3;
    if (((Player9E154 *)param_0)->local_0[param_1].local_4 != 0.0f) {
        local_6 = func_800136E4(yaw_get(param_0) + ((Player9E154 *)param_0)->local_0[param_1].local_6);
        func_800EF4E4(local_1, ((Player9E154 *)param_0)->local_0[param_1].local_5, local_6, 0.0f, 0.0f, ((Player9E154 *)param_0)->local_0[param_1].local_4);
        func_800EF04C(local_0, local_1);
    }
    func_80096394(param_0, local_5);
    func_800EF04C(local_0, local_5);
    func_800EE7F8(param_2, local_0);
}

void func_8009E388(s32 arg0) 
{
}
void func_8009E390(u8 *param_0) {
    s32 local_0;
    u8 *local_1;

    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x114)))) + (0xF0))) = 0;
    for (local_0 = 0; local_0 < 3; local_0++) {
        local_1 = (*(u8 **)((s8 *)(param_0) + (0x114))) + local_0 * 0x28;
        (*(f32 *)((s8 *)(local_1) + (0))) = 0.0f;
        (*(s16 *)((s8 *)(local_1) + (4))) = 0;
        (*(s32 *)((s8 *)(local_1) + (8))) = 0;
        (*(f32 *)((s8 *)(local_1) + (0x20))) = 0.0f;
        (*(f32 *)((s8 *)(local_1) + (0x24))) = 0.0f;
        (*(f32 *)((s8 *)(local_1) + (0x1C))) = 0.0f;
        (*(f32 *)((s8 *)(local_1) + (0x18))) = 0.0f;
        func_800EFD24(local_1 + 0xC);
    }
    func_8009E5A4(param_0, 0, 1);
    func_8009E5A4(param_0, 1, 2);
    func_8009E5A4(param_0, 2, 3);
    func_8009E55C(param_0, 0, 32.0f);
    func_8009E55C(param_0, 1, 28.0f);
    func_8009E55C(param_0, 2, 0);
}

void func_8009E474(PlayerState *param_0) {
    u8 *temp_a0;
    temp_a0 = *(u8 **)((s8 *)param_0 + 0x114);
    rare_memcpy(temp_a0, temp_a0 + 0x78, 0x78);
    *(s8 *)((s8 *)(*(u8 **)((s8 *)param_0 + 0x114)) + 0xF0) = 0;
}

void func_8009E4AC(PlayerState *param_0) {
    u8 *temp_a1;
    *(s8 *)(*(u8 **)((u8 *)param_0 + 0x114) + 0xF0) = 1;
    temp_a1 = *(u8 **)((u8 *)param_0 + 0x114);
    rare_memcpy(temp_a1 + 0x78, temp_a1, 0x78);
}

void func_8009E4E0(s32 *param_0, s32 param_1, s32 param_2)
{
  typedef struct {
    s32 pad_0[2];
    s32 local_0;
    s32 pad_C[7];
  } Struct8009E4E0;

  ((Struct8009E4E0 *)param_0[0x45])[param_1].local_0 = param_2;
}

void func_8009E4FC(u8 *param_0, s32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    s32 temp_v0;

    temp_v0 = param_1 * 0x28;
    (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(param_0) + (0x114))) + temp_v0)) + (0x20))) = param_2;
    (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(param_0) + (0x114))) + temp_v0)) + (0x24))) = param_3;
    (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(param_0) + (0x114))) + temp_v0)) + (0x1C))) = param_4;
}

void func_8009E53C(PlayerState *param_0, s32 param_1, f32 param_2)
{
  volatile unsigned int pad;
  s32 *temp1;
  f32 *temp2;
  temp1 = *((s32 **) (((u8 *) param_0) + 0x114));
  ;
  *((f32 *) ((((u8 *) (*((s32 **) (((u8 *) param_0) + 0x114)))) + (param_1 * 0x28)) + 0x18)) = param_2;
}

void func_8009E55C(PlayerState *param_0, s32 param_1, f32 param_2) {
    (*(E40_9E138 **)((u8 *)param_0 + 0x114))[param_1].unk0 = param_2;
    if (param_2 == 0.0f) { func_8009E4E0(param_0, param_1, 0); }
}

void func_8009E5A4(player, param_1, param_2) PlayerState * player; s32 param_1; s32 param_2; {

    s32 offset = (param_1 * 5) * 8;
    *(u16 *)((char *)(*(s32 **)((char *)player + 0x114)) + offset + 4) = param_2;
}

s32 func_8009E5C0() 
{
    return 0x14;
}


void (*func_8009CAAC(PlayerState *, BanjoStateId))(PlayerState *);
void (*func_8009CAF8(PlayerState *, BanjoStateId))(PlayerState *);

void bs_setState(PlayerState *self, BanjoStateId nextState) {
    if (nextState != BS_STATE_0_INVALID) {
        self->state->next = nextState;
        if (func_8009CAAC(self, self->state->current) != NULL) {
            func_8009CAAC(self, self->state->current)(self);
        }
        self->state->previous = self->state->current;
        self->state->current = self->state->next;
        self->state->next = NULL;
        if (func_8009CAF8(self, self->state->current) != NULL) {
            func_8009CAF8(self, self->state->current)(self);
        }
    }
}

int func_8009E674(s32 param_0, s32 param_1)
{
  s32 local_0;
  ;
  func_8009CA70(param_0, *((PlayerState ***) (*((s32 *) (((char *) param_0) + 0x120)) + 4)), param_1);
}

s32 func_8009E69C(PlayerState *param_0, s32 param_1)
{
  s32 local_0;
  ;
  func_8009CA70(param_0, *((void **)((char *)*(void **)((char *)param_0 + 0x120) + 8)), param_1);
}

s32 func_8009E6C4(PlayerState *param_0, s32 param_1)
{
  s32 local_0;
  ;
  func_8009CA70(param_0, *((PlayerState ***) (*((s32 *) (((char *) param_0) + 0x120)))), param_1);
}

s16 func_8009E6EC(PlayerState *self) {
    return self->state->unkC;
}

s32 bs_getCurrentState(PlayerState *self) {
    return self->state->current;
}

s32 bs_getNextState(PlayerState *self) {
    return self->state->next;
}

s32 bs_getPreviousState(PlayerState *self) {
    return self->state->previous;
}

s32 func_8009E71C(PlayerState *param_0, s32 param_1) {
    return func_8009CBDC(param_0, *(s32 *)((*(u8 **)((u8 *)param_0 + 0x120)) + 4)) == param_1;
}

s32 func_8009E74C(PlayerState *param_0, s32 param_1)
{
  s32 local_2;
  local_2 = func_8009CBDC(param_0,
      *(s32 *)((u8 *)((Struct8009E74C *)param_0)->local_0 + 8));
  return local_2 == param_1;
}

s32 func_8009E77C(PlayerState *param_0, s32 param_1)
{
  s32 local_0;
  s32 *local_1;
 ; ;
  return func_8009CBDC(param_0, *(*((s32 **) (((char *) param_0) + 0x120)))) == param_1;
}

void func_8009E7AC(u8 *param_0) {
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x120)))) + (0))) = 0;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x120)))) + (4))) = 0;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x120)))) + (8))) = 0;
}

s32 func_8009E7C8(u8 *param_0, s32 param_1)
{
    (*(F8009E7C8 **)(param_0 + 0x120))->unkC = param_1;
    (*(F8009E7C8 **)(param_0 + 0x120))->unkE = 1;
    if (func_8009CB44(param_0, (*(F8009E7C8 **)(param_0 + 0x120))->unk4) != NULL) {
        ((void (*)(u8 *))func_8009CB44(param_0, (*(F8009E7C8 **)(param_0 + 0x120))->unk4))(param_0);
    }
    return (*(F8009E7C8 **)(param_0 + 0x120))->unkE;
}

void func_8009E830(PlayerState *param_0, s32 param_1) {

    *(s16 *)((char *)(*(struct bs_state_s **)((char *)param_0 + 0x120)) + 0xE) = param_1;
}

void func_8009E83C(s32 param_0)
{
  s32 (*local_1)(s32);
  local_1 = (*(*(s32**)(param_0 + 0x120) + 1));
  local_1 = func_8009CB90(param_0, local_1);
  if (local_1)
  {
    local_1(param_0);
  }
}
