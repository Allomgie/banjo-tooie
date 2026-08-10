#include "core2/1EDD9C0.h"

extern u8 D_80135AB8[];
extern u8 D_80135AB0[];
extern s32 D_80136BC0;
extern s32 D_80136BE8;
extern s32 D_80124400;
extern s32 D_80136BF8;
extern s32 D_80136D10;
typedef struct { u8 pad[20]; } E20_104148;
extern E20_104148 D_80136D88[];

s32 func_801040D0(void) {
    *(u32*)((char*)&D_80135AB0 + 0x0) = (u32)&D_80135AB8;
    *(s32*)((char*)&D_80135AB0 + 0x4) = 0x6D;
    func_800DFAD0(&D_80135AB0);
    return (s32)&D_80135AB0;
}

int func_8010410C()
{
  return (int)&D_80136BC0;
}

int func_80104118()
{
  return (int)&D_80136BE8;
}

int func_80104124()
{
    return (int)&D_80124400;
}

int func_80104130()
{
  return (int)&D_80136BF8;
}

int func_8010413C()
{
    return (int)&D_80136D10;
}

E20_104148 *func_80104148(s32 param_0) { return &D_80136D88[param_0]; }
