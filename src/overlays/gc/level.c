#include "gc/level.h"

typedef struct { s16 local_0; u16 local_1; s16 local_2; s8 local_3; s8 local_4; } LevelRule1322;
typedef struct { s16 unk0; s16 unk2; s32 unk4; } GcLevelEntry;
extern GcLevelEntry D_808003D0_gclevel[10];
GcLevelEntry *func_80800314_gclevel();

extern u8 D_8012762C;
extern s8 D_8012762D;
extern u8 D_808003C0_gclevel[];

void func_8080016C_gclevel(s32, s32, s32, s32);
s32 func_80800270_gclevel(s32, s32, s32);

void gclevel_entrypoint_0(s32 arg0, s32 arg1)
{
    s32 sp1C;
    s32 sp18;

    sp1C = D_8012762C;
    sp18 = gclevel_entrypoint_2(arg0);
    if (func_800A824C() != 0)
    {
        func_800A8240();
        return;
    }
    if (func_80800270_gclevel(arg0, arg1, sp18) != 0)
    {
        D_8012762D = sp18;
    }
    _cosectionstor_entrypoint_0();
    func_800A13A0();
    func_800CE524();
    func_800CEF7C();
    func_800DA104();
    func_8009E9A8();
    func_8080016C_gclevel(sp1C, sp18, arg0, arg1);
    func_800C75E8();
}

void gclevel_entrypoint_1(void)
{
    if (func_800A824C() == 0)
    {
        func_8009E9A0();
        func_800CF2B0();
        func_800CE7DC();
        _cosectionstor_entrypoint_1();
        func_800C75C0();
    }
}

s32 gclevel_entrypoint_2(s32 arg0)
{
    return D_8012762C = _gcsectionDll_entrypoint_4(arg0);
}

u32 gclevel_entrypoint_3(u32 param_0)
{
    void *local_0;

    local_0 = func_80800314_gclevel(param_0);
    if (local_0 == NULL) {
        return 1;
    }
    return func_800DA298(*(u16 *)((u8 *)local_0 + 2));
}

void func_8080016C_gclevel(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s16 local_0;
  s16 local_1;
  if ((param_0 != param_1) && ((func_8009E958() == 1) || (func_800D395C() != 0)))
  {
    if (param_1 != 0xD)
    {
      if (param_1 != 0x19)
      {
        if (param_1 == 0x1A)
        {
          param_2 = 0x142;
          param_3 = 3;
        }
        goto block_8;
      }
      if (param_0 != 0xD)
      {
        block_8:
        func_8009EB8C((s16) param_2, (s16) param_3);

        goto block_9;
      }
    }
  }
  else
  {
    block_9:
    if (func_8009EC7C() == 0)
    {
      local_0 = (s16) param_2;
      if (param_2 == 0x194)
      {
        param_3 = 1;
        local_0 = 0x15D;
        local_1 = 1;
      }
      else
      {
        ;
      }
      func_8009EB8C(local_0, (s16) param_3);
    }

  }
}

s32 gclevel_entrypoint_4(s32 arg0)
{
    if (D_8012762C >= 0xD && D_8012762C < 0x1C)
    {
        return (D_808003C0_gclevel[D_8012762C - 0xD]) & arg0;
    }
    return 0;
}

s32 func_80800270_gclevel(s32 param_0, s32 param_1, s32 param_2)
{
    LevelRule1322 *local_0;
    s32 local_1;

    local_0 = func_80800314_gclevel(param_2);
    if (!local_0) {
        return 1;
    }
    local_1 = local_0->local_2;
    if (local_1 == -1) {
        func_800DA544(local_0->local_1);
    } else if (param_0 == local_1 &&
               (param_1 == local_0->local_3 || param_1 == local_0->local_4)) {
        func_800DA544(local_0->local_1);
    } else {
        return func_800DA298(local_0->local_1);
    }
    return 1;
}

GcLevelEntry *func_80800314_gclevel(param_0) s32 param_0;
{
    s32 i;

    for (i = 0; i < 10; i++) {
        if (param_0 == D_808003D0_gclevel[i].unk0) {
            return &D_808003D0_gclevel[i];
        }
    }
    return NULL;
}