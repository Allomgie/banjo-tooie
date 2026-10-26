#include "common.h"

extern void func_8001B754();
extern void func_8001B798();
extern void func_800EF334(f32 *, f32);
typedef struct { f32 local_0[3]; f32 local_1[3]; u8 pad_0[8]; f32 local_2[3]; u32 pad_1; f32 local_3; f32 local_4; u32 pad_2; s32 local_5; } FixedCameraPod;
extern f32 func_800136E4(f32);
extern void _ncpod_entrypoint_9(s32, f32);
extern void _ncpod_entrypoint_11(s32, f32);
s32 ncpodfixpos_entrypoint_2();

int func_80800000_ncpodfixpos(u16 *param_0, u32 param_1)
{
    s32 ret;
    if (param_1 == -1) {
        ret = 0;
    } else {
        ret = (param_1 == ((u32)*(u16 *)(param_0 + 9) >> 1));
    }
    return ret;
}

s16 ncpodfixpos_entrypoint_0(void) {
    s16 temp_v0;
    s16 sp26;
    u8 *ptr;

    temp_v0 = func_8001B668(0, 0x44);
    sp26 = temp_v0;
    ptr = ncpodfixpos_entrypoint_2(temp_v0);
    *(s32 *)((u8 *)ptr + 0x18) = 0;
    func_800EFD24(ptr + 0x20);
    func_800EFD24(ptr);
    func_800EFD24(ptr + 0xC);
    *(s16 *)((u8 *)ptr + 0x2C) = 0;
    *(s16 *)((u8 *)ptr + 0x38) = -1;
    *(u8 *)((u8 *)ptr + 0x40) = 0;
    *(u8 *)((u8 *)ptr + 0x41) = 0;
    *(u8 *)((u8 *)ptr + 0x42) = 0;
    *(s32 *)((u8 *)ptr + 0x3C) = 0;
    *(s32 *)((u8 *)ptr + 0x18) = 0;
    *(s32 *)((u8 *)ptr + 0x1C) = -1;
    *(f32 *)((u8 *)ptr + 0x30) = 40.0f;
    *(f32 *)((u8 *)ptr + 0x34) = 1.0f;
    return temp_v0;
}

s32 ncpodfixpos_entrypoint_1(param_0) s16 param_0;{
    s32 temp = param_0;
    func_8001B754(temp);
}

s32 ncpodfixpos_entrypoint_2(param_0) s16 param_0;{
    s32 local_0 = param_0;
    func_8001B798(local_0);
}

void func_80800118_ncpodfixpos(s32 param_0, s32 param_1, s32 param_2)
{
  *(s32 *)((char *)param_0 + 0x3C) = param_2;
  if (param_2 == 1)
  {
    func_800A5800(*(s16 *)((char *)param_0 + 0x38));
    _cadbfunc_entrypoint_0(param_0);
    _cadbfunc_entrypoint_2((s32 *)((char *)param_0 + 0xC));
    *(s8 *)((char *)param_0 + 0x42) = 0;
  }
}

void ncpodfixpos_entrypoint_3(s32 param_0, s32 param_1, s32 param_2)
{
    *(u16 *)(param_0 + 0x38) = param_2;
    func_80800118_ncpodfixpos(param_0, param_1, 1);
}

void ncpodfixpos_entrypoint_4(s32 *param_0, u16 param_1[3])
{
    *(s32 **)(param_0 + 6) = (s32 *)param_1;
    *(s32 *)(param_0 + 7) = (u32)((u16)param_1[9]) >> 1;
}

void ncpodfixpos_entrypoint_5(void *param_0, unsigned long param_1)
{
  char *new_var;
  char *new_var2;
  new_var = ((char *) param_0) + 0x2C;
  new_var2 = new_var;
  *((s16 *) new_var2) = param_1;
}

int func_808001A8_ncpodfixpos(u8 *param_0)
{
    f32 local_0[3];
    s16 local_4;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    local_4 = *(s16 *)(param_0 + 0x2C);
    if (local_4 & 1) {
        if (func_80800000_ncpodfixpos(*(s32 *)(param_0 + 0x18), *(s32 *)(param_0 + 0x1C))) {
            func_80103DFC(func_80106790(*(s32 *)(param_0 + 0x18)), local_0);
            if ((*(s16 *)(param_0 + 0x2C) & 0x400) && param_0[0x42]) {
                func_800EFB24(local_1, local_0, (f32 *)(param_0 + 0x20));
                func_800EF334(local_1, 0.3f);
                func_800EF04C((f32 *)(param_0 + 0x20), local_1);
                return 1;
            }
            func_800EE7F8(param_0 + 0x20, local_0);
            param_0[0x42] = 1;
        }
        return 1;
    }
    if (local_4 & 0x40) {
        func_800F5BC4(func_800F54E4(), local_2);
        func_800F5A00(func_800F54E4(), local_0);
        func_800EF04C(local_0, local_2);
        if ((*(s16 *)(param_0 + 0x2C) & 0x400) && param_0[0x42]) {
            func_800EFB24(local_3, local_0, (f32 *)(param_0 + 0x20));
            func_800EF334(local_3, 0.3f);
            func_800EF04C((f32 *)(param_0 + 0x20), local_3);
            return 1;
        }
        param_0[0x42] = 1;
        func_800EE7F8(param_0 + 0x20, local_0);
        return 1;
    }
    if (local_4 & 0x80) { return 1; }
    return 0;
}

s32 ncpodfixpos_entrypoint_6(param_0, param_1) s16 param_0; s32 param_1;
{
  s32 pad0;
    s32 local_2;
    s32 local_1;
    FixedCameraPod *local_0;

    local_0 = (FixedCameraPod *)ncpodfixpos_entrypoint_2(param_0);
    local_2 = local_0->local_5;
    if (local_2 != 0 && local_2 == 1) {
        local_1 = func_80110024(param_1);
        if (func_808001A8_ncpodfixpos(local_0)) {
            func_800F18FC(local_0->local_2, local_0->local_0, local_0->local_1);
            local_0->local_1[0] = func_800136E4(-local_0->local_1[0]);
        }
        _ncpod_entrypoint_8(local_1, local_0->local_0, local_0->local_1);
        _ncpod_entrypoint_9(local_1, local_0->local_3);
        if (local_0->local_3 == 40.0f) _ncpod_entrypoint_11(local_1, local_0->local_4);
    }
    return 3;
}
