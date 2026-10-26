#include "ch/crusher.h"

typedef struct { s16 a, b; } S16Pair;
extern s32 func_80108474(s32, f32 *, s32);
extern int D_80800B98_chcrusher;
extern s32 D_80800B30_chcrusher;
extern f32 D_80800B48_chcrusher[][4];
extern s32 D_80800BE0_chcrusher;
extern f32 func_800D8FF8(void);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800E1610(s32, f32, f32, f32 *);
extern s32 func_80018820(s32, f32, f32);
typedef struct CrusherBounds { f32 local_0[3]; f32 local_1[3]; } CrusherBounds;
extern void func_8008FE94(s32, f32 *);
extern int D_80800C40_chcrusher;
extern s32 D_80800C88_chcrusher[3];
extern s32 D_80800C94_chcrusher[3];
extern s32 D_80800CA0_chcrusher[3];
typedef struct { s32 local_0[3]; } local_struct;
extern int D_80800CC8_chcrusher;
extern void func_800EFA4C(u8 *, f32, f32, f32);
extern s32 D_80800D20_chcrusher[];
extern int D_80800D68_chcrusher;
extern void func_800BABB8(int, void *, int, float, void *);
extern float D_80800BF0_chcrusher;
typedef struct { u8 local_0[0x74]; u32 local_1 : 4; u32 local_2 : 1; u32 local_3 : 27; } CrusherFlagsView;
extern u32 D_80800D10_chcrusher;
extern void func_80101CDC(Actor *, f32);
void func_808003E4_chcrusher();
void func_80800508_chcrusher();
void func_80800394_chcrusher();

s32 func_80800000_chcrusher(f32 *param_0, s32 param_1, S16Pair param_2) {
    f32 local_0[3];
    if (param_1 == 0x49) {
        local_0[0] = param_0[1];
        local_0[2] = param_0[3];
        local_0[1] = 0.0f;
        func_80108474(0x386, local_0, -0x5A);
    } else {
        return 0;
    }
    return 1;
}

int *chcrusher_entrypoint_0()
{
    return &D_80800B98_chcrusher;
}

int func_80800068_chcrusher(Actor *param_0)
{
  func_80101870();
  if (param_0->unk7C_12) {
    func_800DBEFC(func_80104130(), 6, (u8 *)param_0 + 0x18);
    func_800DBEFC(func_80104130(), 4, (u8 *)param_0 + 0x28);
  }
}

void func_808000D4_chcrusher(Actor *param_0)
{
    f32 *local_0;

    switch (param_0->unk70_10) {
    default:
        local_0 = param_0->position;
        break;
    case 1:
        if (!func_800DA298(0x4FB)) {
            func_80101FDC(param_0, 3);
        }
        local_0 = param_0->position;
        break;
    case 2:
        if (param_0->unk7C_12 && func_80101E14(param_0, 0.75f)) {
            func_80800394_chcrusher(param_0);
        }
        if (func_80101E14(param_0, 0.9f)) {
            local_0 = param_0->position;
            _subaddieaudioquick_entrypoint_2(param_0, local_0, &D_80800B30_chcrusher);
            func_800E1610(2, 80.0f, 0.85f, local_0);
            func_80018820(0, 2.5f, 0.25f);
        }
        local_0 = param_0->position;
        if (func_80101E14(param_0, 0.48f)) {
            if (func_800DA298(0x4FB)) {
                func_80101FDC(param_0, 1);
            } else {
                func_80101FDC(param_0, 3);
                param_0->unk58 = 0.0f;
            }
        }
        break;
    case 3:
        param_0->unk64_20 = 0;
        param_0->unk58 += func_800D8FF8();
        if (D_80800B48_chcrusher[param_0->unk6C_0][(s32)((f32 *)param_0->actorData)[7]] <= param_0->unk58) {
            if ((s32)((f32 *)param_0->actorData)[7] < 3) {
                ((f32 *)param_0->actorData)[7] += 1.0f;
            } else {
                ((f32 *)param_0->actorData)[7] = 0.0f;
            }
            if (func_800DA298(0x4FB)) {
                func_80101FDC(param_0, 1);
            } else {
                func_80101FDC(param_0, 2);
            }
        }
        local_0 = param_0->position;
        break;
    }
    if (param_0->unk7C_12 && !param_0->unk64_20 && param_0->unk70_10 == 2) {
        func_808003E4_chcrusher(param_0);
    }
    if (param_0->unk7C_12) {
        func_80800508_chcrusher(param_0);
    }
    _subaddieaudioloop_entrypoint_4(param_0, local_0,
        ((f32 *)param_0->actorData)[3] > 0.0f, &D_80800BE0_chcrusher);
    if (((f32 *)param_0->actorData)[3] > 0.0f) {
        ((f32 *)param_0->actorData)[3] -= func_800D8FF8();
    }
}

void func_80800394_chcrusher(param_0) void *param_0;
{
    func_800BABB8(0, (void *)((char *)param_0 + 0x28), 0, 1.0f, &D_80800BF0_chcrusher);
    *(f32 *)((char *)param_0 + 0x24) = 0.3f;
}

void func_808003E4_chcrusher(param_0) Actor *param_0;
{
    CrusherBounds local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];

    local_1 = param_0->position[0] - *(f32 *)param_0->actorData;
    local_2 = *((f32 *)param_0->actorData + 2) - param_0->position[2];
    local_1 += 25.0f;
    local_2 += 25.0f;
    func_8008FE94(5, local_3);
    local_0.local_1[0] = param_0->position[0] + local_1;
    local_0.local_0[0] = param_0->position[0] - local_1;
    local_0.local_1[1] = *((f32 *)param_0->actorData + 1);
    local_0.local_0[1] = *((f32 *)param_0->actorData + 1) + 100.0f;
    local_0.local_1[2] = param_0->position[2] + local_2;
    local_0.local_0[2] = param_0->position[2] - local_2;
    if (local_3[2] < local_0.local_1[2] &&
        *((f32 *)param_0->actorData + 1) < local_3[1] &&
        local_3[0] < local_0.local_1[0] && local_0.local_0[0] < local_3[0]) {
        param_0->unk64_20 = 1;
        if (func_80090150()) {
            func_800904C8(0x59);
        }
    }
}

void func_80800508_chcrusher(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    f32 local_4[3];

    local_2 = param_0->position[0] - *(f32 *)&param_0->actorData[0];
    local_3 = *(f32 *)&param_0->actorData[2] - param_0->position[2];
    local_3 += 25.0f;
    func_8010D254(local_4);
    local_0[0] = param_0->position[0] - local_2;
    local_1[0] = param_0->position[0] + local_2;
    local_0[1] = *(f32 *)&param_0->actorData[1];
    local_1[1] = *(f32 *)&param_0->actorData[1] + 1000.0f;
    local_0[2] = param_0->position[2] - local_3;
    local_1[2] = param_0->position[2] + local_3;
    func_8008FA94(local_0, local_1);
}

void func_808005C0_chcrusher(s32 arg0) 
{
}
void func_808005C8_chcrusher(u16 *param_0) {
    u32 temp_t6;

    temp_t6 = (u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7;
    switch (temp_t6) {                              
    default:
        (*(u16 *)((s8 *)(param_0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(param_0) + (0x6E))) & 0xFE00);
        break;
    case 0x32:
        (*(u16 *)((s8 *)(param_0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(param_0) + (0x6E))) & 0xFE00);
        break;
    case 0x33:
        (*(u16 *)((s8 *)(param_0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(param_0) + (0x6E))) & 0xFE00) | 1);
        break;
    case 0x34:
        (*(u16 *)((s8 *)(param_0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(param_0) + (0x6E))) & 0xFE00) | 2);
        break;
    }
    (*(f32 *)((s8 *)(param_0) + (0x34))) = 0.0f;
    (*(f32 *)((s8 *)(param_0) + (0xC))) = -365.0f;
    (*(f32 *)((s8 *)(param_0) + (8))) = 10.0f;
    func_80101FDC(param_0, 1);
    func_80101EE4(param_0, 0x3EF5C28F);
}

int func_80800684_chcrusher(Actor *param_0, s32 param_1, s32 param_2)
{

    switch (param_1) {
    case 0x3E:
        if (param_0->unk70_10 == 2) {
            func_8010D254((f32 *)param_0->actorData);
            if (*(f32 *)((u8 *)param_0 + 0x20) < -50.0f) {
                *(f32 *)((u8 *)param_0 + 0x18) -= 50.0f;
                func_80090494(6, (f32 *)param_0->actorData, param_0);
                return 1;
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}

int *chcrusher_entrypoint_1()
{
    return &D_80800C40_chcrusher;
}

void func_80800734_chcrusher(u8 *param_0) {
    s32 local_4;
    local_struct local_1;
    local_struct local_2;

    local_4 = func_800DA298(0x4FB);
    if (((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7) == 0x32) {
        _subaddieaudioloop_entrypoint_4(param_0, param_0 + 4, local_4, D_80800CA0_chcrusher);
        local_1 = *(local_struct *)D_80800C88_chcrusher;
        local_2 = *(local_struct *)D_80800C94_chcrusher;
        func_8008FA94(local_1.local_0, local_2.local_0);
    }
    switch ((u32) (*(u16 *)((s8 *)(param_0) + (0x72))) >> 0xA) {                              
    case 1:
        if (local_4 != 0) {
            func_80101FDC(param_0, 2, local_4);
            return;
        }
        return;
    case 2:
        if (local_4 == 0) {
            func_80101FDC(param_0, 1, local_4);
        }
        *(f32 *)((s8 *)param_0 + 0x4C) += *(f32 *)((s8 *)param_0 + 0x54);
        break;
    }
}

void func_80800838_chcrusher(Actor *param_0)
{
    if (param_0->unk74_7 != 0x32) {
        param_0->unk54 = func_800D8FF8() * -240.0f;
        param_0->position[1] = 350.0f;
        param_0->rotation[2] += 22.5f;
        param_0->position[2] = -635.0f;
    } else {
        param_0->unk54 = func_800D8FF8() * 240.0f;
        param_0->position[1] = 100.0f;
        param_0->position[2] = -660.0f;
    }
    param_0->position[0] = -2350.0f;
}

int *chcrusher_entrypoint_2()
{
    return &D_80800CC8_chcrusher;
}

void func_808008FC_chcrusher(Actor *param_0)
{
    s32 local_1;
    f32 local_0[3];
    local_1 = func_800DA298(0x4FB);
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_1, &D_80800D10_chcrusher);
    switch (param_0->unk70_10) {
        case 1:
            if (local_1) {
                func_80101FDC(param_0, 2);
                ((CrusherFlagsView *)param_0)->local_2 = 1;
            }
            break;
        case 2:
            if (!local_1) {
                func_80101FDC(param_0, 1);
                ((CrusherFlagsView *)param_0)->local_2 = 0;
            }
            func_8010D254(local_0);
            if (func_80090248() && local_0[0] < 2000.0f &&
                local_0[0] > -2300.0f && local_0[2] < 0.0f) {
                if (func_800DA298(0)) { local_0[0] -= 144.0f * func_800D8FF8(); }
                else { local_0[0] -= 504.0f * func_800D8FF8(); }
                func_800907C0(local_0);
            }
            if (func_800DA298(0)) { func_80101CDC(param_0, 33.0f); }
            else { func_80101CDC(param_0, 9.4285717f); }
            break;
    }
}

void func_80800A98_chcrusher(u8 *param_0) {
    func_800EFA4C(param_0 + 4, 0.0f, -10.0f, 0.0f);
}

void func_80800ACC_chcrusher(s32 arg0) 
{
}
void func_80800AD4_chcrusher(s32 arg0)
{
    _chswitch_entrypoint_14(arg0,FLAG_4FB_UNK);
}

int chcrusher_entrypoint_3()
{
  return D_80800D20_chcrusher;
}

int chcrusher_entrypoint_4()
{
    return (int)&D_80800D68_chcrusher;
}
