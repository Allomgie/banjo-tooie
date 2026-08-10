#include "common.h"

extern u8 unkC[];
extern s16 D_80800140_gspropctrl[];

int gspropctrl_entrypoint_0(u8 *param_0)
{
  return param_0[10];
}

u32 gspropctrl_entrypoint_1(u8 *param_0, u8 *param_1) {
    (*(s32 *)((s8 *)(param_1) + (0))) = (s32) (*(s16 *)((s8 *)(param_0) + (0)));
    (*(s32 *)((s8 *)(param_1) + (4))) = (s32) (*(s16 *)((s8 *)(param_0) + (2)));
    (*(s32 *)((s8 *)(param_1) + (8))) = (s32) (*(s16 *)((s8 *)(param_0) + (4)));
    return (u32) (*(u16 *)((s8 *)(param_0) + (6))) >> 7;
}

int gspropctrl_entrypoint_2(s32 param_0[3])
{
  u32 local_0;
  local_0 = ((u32) param_0[1]) << 0x19;
  return (((u32) param_0[1]) << 0x19) >> 26;
}

int gspropctrl_entrypoint_3(Actor *param_0) {
    return (*(s32 *)((char *)(param_0) + 0xC));
}

int gspropctrl_entrypoint_4(int param_0) {
    return *(unsigned short *)(param_0 + 8);
}

void gspropctrl_entrypoint_5(void *param_0, s32 param_1)
{
  (*(s32 *)((char *)(param_0) + 0xC)) = param_1;
}

int gspropctrl_entrypoint_6(Actor *param_0)
{
  return (((*((s32 *) (((char *) param_0) + 0x10))) & 7) * 4) + ((((u32) (*((s32 *) (((char *) param_0) + 0x8)))) << 19) >> 30);
}

s32 gspropctrl_entrypoint_7(s32 param_0)
{
  return D_80800140_gspropctrl[param_0];
}

s32 gspropctrl_entrypoint_8(void *param_0) {
    return (u32)(*(u16 *)((char *)(param_0) + 0x6)) >> 7 | 0;
}

s32 gspropctrl_entrypoint_9(s16 src[3], s32 dst[3]){
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

s32 gspropctrl_entrypoint_10(s16 param_0[3], s16 param_1[3]){
    param_1[0] = param_0[0];
    param_1[1] = param_0[1];
    param_1[2] = param_0[2];
}

s32 gspropctrl_entrypoint_11(s16 param_0[3], f32 param_1[3]){
    param_1[0] = (f32)param_0[0];
    param_1[1] = (f32)param_0[1];
    param_1[2] = (f32)param_0[2];
}

int gspropctrl_entrypoint_12(Actor *param_0)
{
  return ((*((s32 *) (((char *) param_0) + 0xC))) & 0xFFFFFFFF) >> 23;
}

int gspropctrl_entrypoint_13(Actor *param_0)
{
  u32 local_0;
  local_0 = (local_0 = (*((s32 *) (((char *) param_0) + 0xC))) & 0x007FFFFF);
}
