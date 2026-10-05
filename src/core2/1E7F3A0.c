#include "common.h"

typedef struct { s16 local_0; s16 local_1[5]; } local_type;
typedef struct { s32 local_0; local_type *local_1; } local_table;
extern local_type D_8011A1B0[];
extern local_table D_8011A1BC[];
extern u8 D_8012762C;
extern s32 func_800EA05C(s32);
extern u8 *D_80127100;

void func_800A5AB0(void) {
    s32 local_0;
    s32 local_1;
    s32 local_3;
    local_type *local_2;
    s32 local_5;
    local_5 = D_8012762C;
    local_2 = D_8011A1B0;
    for (local_0 = 0; D_8011A1BC[local_0].local_0; local_0++) {
        if (local_5 == D_8011A1BC[local_0].local_0) local_2 = D_8011A1BC[local_0].local_1;
    }
    local_0 = 0;
    local_3 = func_800EA05C(local_5);
    for (local_0 = 0; local_2[local_0].local_0; local_0++) {
        if (local_3 == local_2[local_0].local_0) break;
    }
    D_80127100 = &local_2[local_0];
}

s8 func_800A5B6C(void)
{
  return *(s8*)(((int) D_80127100) + 2);
}

s32 func_800A5B7C()
{
  return ((s8 *) D_80127100)[3];
}

float func_800A5B8C(void)
{
    return *(volatile f32*)((u8*)((void*) D_80127100) + 4);
}

s32 func_800A5B9C()
{
  return D_80127100[8];
}

s32 func_800A5BAC()
{
  return D_80127100[9];
}

s32 func_800A5BBC()
{
  return D_80127100[0xA];
}

s32 func_800A5BCC(void)
{
  return D_80127100[0xb];
}
