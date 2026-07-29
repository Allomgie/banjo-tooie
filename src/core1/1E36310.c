#include "common.h"

extern s32 D_8007E998;
extern s32 D_8007E990;
extern s32 D_8007E994;

s32 func_8001E830();

int func_8001E7E0()
{
  s32 local_0 = 0x80400000;
  return local_0;
}

void func_8001E7E8()
{
  s32 local_0;
  D_8007E998 = func_8001E7E0();
  D_8007E990 = D_8007E998 - func_8001E830();
  D_8007E994 = D_8007E990;
}

s32 func_8001E830(void){
    return 0x2C8800;
}
