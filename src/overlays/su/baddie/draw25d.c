#include "common.h"

extern void _subaddiedraw25d_entrypoint_0(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E24E4(void (*)(), Actor *);
typedef struct { u32 pad : 30; u32 flag : 1; u32 pad2 : 1; } BitTest30;
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 30; u32 colored : 1; u32 pad_2 : 1; } Draw25dFlags;
typedef struct { u8 pad_0[8]; u32 pad_1 : 26; u32 flipped : 1; u32 pad_2 : 5; } Draw25dMarkerInfo;
void subaddiedraw25d_entrypoint_3();

int subaddiedraw25d_entrypoint_0(u8 *param_0)
{
  param_0[0x7E] = (param_0[0x7E] & 0xFFFFu) | 0x10;
}

void subaddiedraw25d_entrypoint_1(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    Unk80132ED0 *local_2;
    s32 local_3;
    u8 *local_4;

    local_2 = param_0->unk0;
    local_3 = func_80103AE4(local_2);
    local_0[0] = local_0[1] = local_0[2] = param_0->scale;
    func_800EFA4C(local_1, param_0->rotation[0], param_0->rotation[1], 0.0f);
    if (*(u16 *)((u8 *)param_0 + 0x78) & 3) {
        func_800E257C(*((u8 *)param_0 + 0x9B));
        func_800E2588(1);
    } else if (func_800AF5A8(local_3) & 0xB00) {
        func_800E2588(1);
    } else {
        func_800E2588(3);
    }
    if (((BitTest30 *)((u8 *)param_0 + 0x78))->flag) {
        func_800E24F8(*((u8 *)param_0 + 0x98), *((u8 *)param_0 + 0x99), *((u8 *)param_0 + 0x9A));
    }
    subaddiedraw25d_entrypoint_3(param_0);
    func_800E24E4(_subaddiedraw25d_entrypoint_0, param_0);
    local_4 = *(u8 **)local_2;
    func_800E2C54(param_1, local_3, (u32)*(u16 *)(local_4 + 0xA) >> 11,
        (*(u32 *)(local_4 + 8) << 26) >> 31, param_0->position, local_1, local_0);
}

void subaddiedraw25d_entrypoint_2(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    Unk80132ED0 *local_1;
    s32 local_2;
    u8 *local_3;
    local_1 = param_0->unk0;
    local_2 = func_80103AE4(local_1);
    local_0[0] = local_0[1] = local_0[2] = param_0->scale;
    if (*(u16 *)((u8 *)param_0 + 0x78) & 3) {
        func_800E257C(param_0->alpha);
        func_800E2588(1);
    } else {
        if (func_800AF5A8(local_2) & 0xB00) func_800E2588(1);
        else func_800E2588(3);
    }
    if (((Draw25dFlags *)param_0)->colored) func_800E24F8(param_0->pad98, param_0->pad99, param_0->pad9A);
    subaddiedraw25d_entrypoint_3(param_0);
    func_800E24E4(_subaddiedraw25d_entrypoint_0, param_0);
    local_3 = *(u8 **)local_1;
    func_800E2AA4(param_1, local_2, (u32)*(u16 *)(local_3 + 0xA) >> 11,
        ((Draw25dMarkerInfo *)local_3)->flipped, param_0->position, local_0);
}

void subaddiedraw25d_entrypoint_3(param_0) u8 *param_0; {
    u16 local_0;

    func_800E24C0((u32) ((*(s32 *)((s8 *)(param_0) + (0x70))) << 0xB) >> 0x1F);
    local_0 = (*(u16 *)((s8 *)(func_80100368(param_0)) + (0x1A)));
    if (local_0 != 0) {
        func_800E249C(local_0);
        return;
    }
    if (!((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0)))) + (0x10))) & 1)) {
        func_800E249C(func_800D2F20(local_0));
    }
}
