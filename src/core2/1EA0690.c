#include "core2/1EA0690.h"
#include "core2/1EB3750.h"

void func_800C70D0(s32, s32 set);
extern s32 D_8012AAE0;
s32 D_8012AAD0[4];
s32 func_800C6E18();

/* The 0x30 frame of func_800C6DA0 (ra at 0x24) holds an outgoing-argument
 * area for eight arguments, but no call in the function passes more than
 * two. The original must have had an eight-argument call behind a local
 * flag that is always zero, which IDO removes only after it has laid out
 * the frame. The callee is unknown; debug_call stands in for it and never
 * reaches the object file. */
extern void debug_call();

void func_800C6DA0(s32 param_0)
{
  s32 debug = 0;
  s32 local_0;
  local_0 = 1;
  if (func_800C6E18(param_0))
  {
    return;
  }
  switch (param_0 - 0x3C)
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      break;

    case 6:
      local_0 = 0;
      break;

    case 7:
    case 8:
    case 9:
      break;
  }
  if (local_0)
  {
    func_800FC6B0(0xE);
  }
  func_800C70D0(param_0, 1);
  if (debug) debug_call(1, 2, 3, 4, 5, 6, 7, 8);
}

s32 func_800C6E18(param_0) s32 param_0;{
    func_800DA298(param_0 + 0xEE);
}

//Has Ability
s32 func_800C6E38(s32 AbilityID) {
    return func_800DA298(AbilityID + FLAG_0ED_ABILITY_BK_BEAK_BARGE);
}

//Immediate Return
void func_800C6E58(void) {
}

void func_800C6E60(void) {
    func_800C70B0(0, 1);
    func_800C70B0(1, 1);
    func_800C70B0(2, 1);
    func_800C70B0(3, 1);
    func_800C70B0(4, 1);
    func_800C70B0(5, 1);
    func_800C70B0(6, 1);
    func_800C70B0(7, 1);
    func_800C70B0(8, 1);
    func_800C70B0(9, 1);
    func_800C70B0(0xA, 1);
    func_800C70B0(0xB, 1);
    func_800C70B0(0xC, 1);
    func_800C70B0(0xD, 1);
    func_800C70B0(0xE, 1);
    func_800C70B0(0xF, 1);
    func_800C70B0(0x10, 1);
    func_800C70B0(0x11, 1);
    func_800C70B0(0x12, 1);
    func_800C70B0(0x13, 1);
    func_800C70B0(0x31, 1);
    func_800C70D0(0x3C, 1);
    func_800C70D0(0x3D, 1);
    func_800C70D0(0x3E, 1);
    func_800C70D0(0x3F, 1);
    func_800C70D0(0x40, 1);
    func_800C70D0(0x41, 1);
    func_800C70D0(0x42, 1);
    func_800C70D0(0x43, 1);
    func_800C70D0(0x44, 1);
    func_800C70D0(0x45, 1);
    func_800C70D0(0x46, 1);
    func_800C70D0(0x47, 1);
    func_800C70D0(0x48, 1);
}

//Give all Abilities
void func_800C7010(void) {
    s32 var_s0 = 0;
    while (var_s0 < 0x3C)
    {
        func_800C70B0(var_s0, 1);
        var_s0++;
    }
    var_s0 = 0x3C;
    while (var_s0 < 0x50)
    {
        func_800C70D0(var_s0, 1);
        var_s0 += 1;
    }
}

void func_800C7074(s32 arg0, s32 arg1) {
    func_800C70B0(arg0, arg1);
    if (arg1 != 0) {
        func_80101238(0x1A, arg0);
    }
}

//Set Ability Flag
void func_800C70B0(s32 arg0, s32 set) {
    func_800DA3B8(arg0 + FLAG_0ED_ABILITY_BK_BEAK_BARGE, set);
}

//Set Ability Flag offset by 1
void func_800C70D0(s32 arg0, s32 set) {
    func_800DA3B8(arg0 + FLAG_0EE_ABILITY_BK_BEAK_BOMB, set);
}

int func_800C70F0(s32 param_0)
{
  ((s32 *) D_8012AAD0)[param_0] = D_8012AAE0;
}

int func_800C710C(s32 param_0)
{
  s32 *ptr = (s32 *) (((char *) (((s32 *) D_8012AAD0))) + (param_0 << 2));
  if ((((*ptr) + 5) & 0xFFFFFFFFu) < D_8012AAE0)
  {
    *ptr = D_8012AAE0;
    return 1;
  }
  return 0;
}

void* func_800C7150(void* arg0) 
{
    return defrag(arg0);
}
void func_800C7170(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        D_8012AAD0[i] = 0;
    }
}

void func_800C718C()
{
  D_8012AAE0++;
}
