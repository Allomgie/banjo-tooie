#include "core2/1E75920.h"

extern void func_800EFD24();
typedef struct { u8 pad0[0xE4]; s32 unkE4; } ActorLocal_CC_510;
typedef struct { ActorLocal_CC_510 local; } Actor_8009C08C;
typedef struct { /* 0x00 */ u8 pad0[0xE4]; /* 0xE4 */ void* unkE4; } Actor_8009C0BC;
extern void func_800EE7F8();
typedef struct { /* 0x00 */ u8 pad0[0xE4]; /* 0xE4 */ void* unkE4; } Actor_8009C0F8;
s32 func_8009C030()
{
    return 0x30;
}

void func_8009C038(void *param_0)
{
    func_800EFD24(*(s32 *)((char *)param_0 + 0xe4) + 0x24);
    func_800EFD24(*(s32 *)((char *)param_0 + 0xe4));
    func_800EFD24(*(s32 *)((char *)param_0 + 0xe4) + 0xc);
    func_800EFD24(*(s32 *)((char *)param_0 + 0xe4) + 0x18);
}

void func_8009C08C(Actor_8009C08C *param_0)
{
    ActorLocal_CC_510 *local_0;
    local_0 = &param_0->local;
    func_8009C21C();
    func_800EFD24((void*)(local_0->unkE4 + 0x24));
    return;
}

void func_8009C0BC(Actor_8009C0BC *param_0, s32 param_1)
{
    func_800EE7F8(param_0->unkE4);
    func_800EE7F8((void*)((char*)param_0->unkE4 + 0xC), param_1);
}

void func_8009C0F8(Actor_8009C0F8 *param_0)
{
    func_800EE7F8(param_0->unkE4);
}

int func_8009C118(s32 param_0, f32 param_1)
{
  int new_var2;
  unsigned int new_var;
  int new_var3;
 do { new_var = 0xE4; new_var2 = (param_0 ^ 0) + new_var; new_var3 = new_var2; *((f32 *) ((*((s32 *) new_var3)) + 4)) = param_1; new_var = 0x50; } while (0);
}

void func_8009C128(PlayerState *param_0, f32 param_1[3])
{
  func_800EE7F8(param_1, *(s32 *)((char *)param_0 + 0xE4));
}

f32 func_8009C150(PlayerState *param_0)
{
  return *(f32 *)(*(s32 *)((char *)param_0 + 0xE4) + 0x4);
}

void func_8009C15C(PlayerState *player, f32 *param_1)
{
  char *new_var;
  if (1)
  {
    new_var = param_1;
  }
  func_800EE7F8(new_var, new_var = ((char *) (*((struct ba_unknown_C0_s **) (((char *) player) + 0xE4)))) + 12);
}

s32 func_8009C188(s32 param_0, s32 param_1)
{
    func_800EE7F8(param_1, *(s32 *)(param_0 + 228) + 0x18);
}

void func_8009C1B4(s32 param_0, f32 param_1)
{
  f32 *local_0 = *(f32 **)(param_0 + 0xE4);
  local_0[1] += param_1;
}

int func_8009C1CC(s32 param_0, s32 param_1)
{
    func_800EE7F8(param_1, *(s32 *)(param_0 + 228) + 0x24);
}

void func_8009C1F8(struct Actor *param_0)
{

    func_800EE7F8((void *)((s32)((void *) (*(s32 *)((char *)param_0 + 0xE4))) + 0x24));
}

/* Old style and int, so that this matches the implicit declaration the call
   further up creates: that call passes no arguments and s32 is long here. */
int func_8009C21C(param_0) s32 *param_0;
{
  s32 *new_var;
  s32 local_0;
  s32 local_1;
  new_var = &param_0[57];
  local_0 = *new_var;
  func_800EE7F8(local_0 + 0x18, local_0 + 0xC, local_0);
  local_1 = param_0[57];
  func_800EE7F8(local_1 + 0xC, local_1 ^ 0, local_1);
}

void func_8009C25C(u8 *param_0) {
    s32 local_0;

    local_0 = (*(s32 *)((s8 *)(param_0) + (0xE4)));
    func_800EF04C(local_0, local_0 + 0x24);
    func_800EFD24((*(s32 *)((s8 *)(param_0) + (0xE4))) + 0x24);
}
