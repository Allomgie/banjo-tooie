#include "common.h"

extern int D_80800240_chhotwatersteam;
extern int D_80800288_chhotwatersteam;
typedef struct { u8 pad[0x76]; u16 f76:9; u16 pad76:7; } SteamState;
extern s32 func_800DA298(s32);
int func_808001E8_chhotwatersteam();
void func_808000D8_chhotwatersteam();

int chhotwatersteam_entrypoint_0()
{
    return (int)&D_80800240_chhotwatersteam;
}

void func_8080000C_chhotwatersteam(ALLink *param_0)
{
  if (!((0, func_808001E8_chhotwatersteam(param_0))))
  {
    func_800FFA88(param_0->next);
    return;
  }
  else
  {
  }
}

void func_8080003C_chhotwatersteam(Actor *param_0)
{
  u32 temp_t6;
  u16 *new_var;
  u16 new_var2;
  new_var = &(*((u16 *) (((u8 *) param_0) + 0x72)));
  if (func_808001E8_chhotwatersteam() == 0)
  {
    func_800FFA88(*((s32 *) param_0));
    return;
  }
  new_var2 = (temp_t6 = *new_var);
  temp_t6 = temp_t6 >> 0xA;
  switch (temp_t6)
  {
    case 1:
      func_808000D8_chhotwatersteam(param_0);
      return;

    case 2:
      if (func_800D9078(((u8 *) param_0) + 0x58) != 0)
    {
      func_80101FDC(param_0, 1);
    }
      return;

  }

}

s32 func_808000C4_chhotwatersteam(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
s32 func_8080014C_chhotwatersteam();

void func_808000D8_chhotwatersteam(param_0) Actor *param_0;
{
    extern f32 func_800DC178(f32, f32);
    f32 local_0[3];

    func_800CD08C((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, local_0);
    local_0[1] = param_0->position[1];
    if (func_8080014C_chhotwatersteam(param_0, local_0)) {
        func_80101FDC(param_0, 2);
        param_0->unk58 = func_800DC178(0.3f, 0.4f);
    }
}

s32 func_8080014C_chhotwatersteam(s32 param_0, s32 param_1) {
    f32 local_1[3];
    f32 local_3[3];

    if (func_800E3E8C(param_1, 0x43FA0000) != 0) {
        func_800EE7F8(local_1, param_1);
        local_1[1] -= 400.0f;
        func_800EE7F8(local_3, param_1);
        local_3[1] -= 20.0f;
        func_800BBCB8(local_3, local_1, 0x3F800000, 1, &D_80800288_chhotwatersteam);
        return 1;
    }
    return 0;
}

int func_808001E8_chhotwatersteam(param_0) SteamState *param_0; {
    if (param_0->f76 == 0x33) {
        return !func_800DA298(0x31B);
    }
    return 1;
}
