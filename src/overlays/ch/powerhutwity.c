#include "common.h"

extern int D_80800B28_chpowerhutwitchy;
extern int D_80800B70_chpowerhutwitchy;
extern int D_80800BB8_chpowerhutwitchy;
extern s32 D_80800C00_chpowerhutwitchy[];
extern u8 D_80800B00_chpowerhutwitchy[];
extern void _chpowerhut_entrypoint_0(s32, void *);
extern u8 *func_80100094(s32, s32);
extern u8 _chpowerhutwitchy_entrypoint_4[];
extern Actor *func_80106790(void *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F2FD0(f32 *, f32 *, f32);
extern int func_800F3320(u8 *, u8 *, u8 *, f32);
extern u8 D_80800C48_chpowerhutwitchy[];
extern u8 D_80800B14_chpowerhutwitchy[];
extern void _chpowerhutwitchy_entrypoint_5(void);
typedef struct { u8 pad_0[0xC]; f32 local_0; } PowerHutVertex;
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
void func_8080024C_chpowerhutwitchy();
void func_80800890_chpowerhutwitchy();
void func_808009FC_chpowerhutwitchy();

int chpowerhutwitchy_entrypoint_0()
{
    return (int)&D_80800B28_chpowerhutwitchy;
}

int chpowerhutwitchy_entrypoint_1()
{
    return (int)&D_80800B70_chpowerhutwitchy;
}

int chpowerhutwitchy_entrypoint_2(void)
{
    return &D_80800BB8_chpowerhutwitchy;
}

int chpowerhutwitchy_entrypoint_3()
{
    return (int)D_80800C00_chpowerhutwitchy;
}

void func_80800030_chpowerhutwitchy(s32 param_0) {
    _chpowerhut_entrypoint_0(param_0, D_80800B00_chpowerhutwitchy);
    func_80100094(param_0, 0)[0x18] = 0;
}

void func_80800068_chpowerhutwitchy(Actor *param_0)
{
    _chpowerhut_entrypoint_1(param_0, D_80800B00_chpowerhutwitchy);
    switch (param_0->unk70_10) {
        case 1:
        case 2:
            break;
        case 3:
            if (*(s16 *)((u8 *)func_80100094(param_0, 0) + 0xC) == 2) {
                func_800BF744(1, 0);
                func_800BF744(2, 1);
                func_800BF744(3, 0);
                func_800BF744(4, 1);
                func_800BF744(7, 0);
                func_800BF744(8, 1);
                *((u8 *)func_80100094(param_0, 0) + 0x18) = 1;
            }
            if (*(s16 *)((u8 *)func_80100094(param_0, 0) + 0xC) == 3) {
                *(f32 *)&param_0->actorData[4] = *(f32 *)((u8 *)func_80100094(param_0, 0) + 0x14);
                func_8080024C_chpowerhutwitchy(param_0);
            }
            break;
    }
}

void func_80800168_chpowerhutwitchy(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    if (param_1 == 0x95) {
        local_0 = func_800DA298(0xEB) || _glcutDll_entrypoint_20();
        func_800BF744(1, !local_0);
        func_800BF744(2, local_0);
        func_800BF744(3, !local_0);
        func_800BF744(4, local_0);
        func_800BF744(7, !local_0);
        func_800BF744(8, local_0);
        *(f32 *)((u8 *)param_0 + 0x28) = *(f32 *)((u8 *)func_80100094(param_0, 0) + 0x14);
        if (!local_0) {
            func_8080024C_chpowerhutwitchy(param_0);
        }
    }
    _chpowerhut_entrypoint_3(param_0, param_1, param_2, D_80800B00_chpowerhutwitchy);
}

void func_8080024C_chpowerhutwitchy(param_0) s32 *param_0;
{
  s32 temp_v0;
  s32 temp_v0_2;
  temp_v0 = func_800BEA88(0);
 if (1) { } if (1) { } _glid_entrypoint_0(temp_v0, 1, &_chpowerhutwitchy_entrypoint_4, *param_0); _glid_entrypoint_0(temp_v0, 2, &_chpowerhutwitchy_entrypoint_4, *param_0);
  _glid_entrypoint_0(temp_v0, 3, &_chpowerhutwitchy_entrypoint_4, *param_0);
  _glid_entrypoint_0(temp_v0, 6, &_chpowerhutwitchy_entrypoint_4, *param_0);
  temp_v0_2 = func_800BEA88(1);
  _glid_entrypoint_0(temp_v0_2, 1, &_chpowerhutwitchy_entrypoint_4, *param_0);
  _glid_entrypoint_0(temp_v0_2, 2, &_chpowerhutwitchy_entrypoint_4, *param_0);
  _glid_entrypoint_0(temp_v0_2, 6, &_chpowerhutwitchy_entrypoint_4, *param_0);
  if (param_0)
  {
  }
}

void chpowerhutwitchy_entrypoint_4(s32 param_0, u8 *param_1, u8 *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    f32 local_0;
    f32 local_1;

    local_0 = ((f32 *)func_80106790(param_4)->actorData)[4];
    switch (param_0) {
    case 1:
        for (; param_3 > 0; param_3--, param_1 += 0x10, param_2 += 0x10) {
            func_800F2FD0((f32 *)(param_2 + 0xC), (f32 *)(param_1 + 0xC), local_0);
        }
        break;
    case 2:
        for (; param_3 > 0; param_3--, param_1 += 0x10, param_2 += 0x10) {
            func_800F3320(param_2 + 0xC, D_80800C48_chpowerhutwitchy, param_1 + 0xC, local_0);
        }
        break;
    case 3:
        local_1 = func_800F10B4(local_0, 0.0f, 1.0f, 0.3f, 1.0f);
        for (; param_3 > 0; param_1 += 0x10, param_3--, param_2 += 0x10) {
            param_2[0xF] = (u32)((f32)(u32)param_1[0xF] * local_1);
        }
        break;
    case 6:
        for (; param_3 > 0; param_1 += 0x10, param_3--, param_2 += 0x10) {
            param_2[0xF] = (u32)((f32)(u32)param_1[0xF] * local_0);
        }
        break;
    }
}

void func_808005C8_chpowerhutwitchy(s32 param_0) {
    s32 local_0 = param_0;
    _chpowerhut_entrypoint_0(local_0, ((int *) D_80800B14_chpowerhutwitchy));
    (*(s8 *)((s8 *)(func_80100094(local_0, 0)) + 0x18)) = 0;
    (*(s8 *)((s8 *)(func_80100094(local_0, 0)) + 0x19)) = 0;
}

void func_80800610_chpowerhutwitchy(Actor *param_0)
{
    f32 local_0;

    _chpowerhut_entrypoint_1(param_0, D_80800B14_chpowerhutwitchy);
    if (param_0->unk70_10 == 3 || param_0->unk70_10 == 4) {
        if (*(s16 *)((u8 *)func_80100094(param_0, 0) + 0xC) == 2) {
            func_800BF744(5, 0);
            func_800BF744(6, 1);
            *((u8 *)func_80100094(param_0, 0) + 0x18) = 1;
        }
        if (!*((u8 *)func_80100094(param_0, 0) + 0x19)) {
            local_0 = *(f32 *)((u8 *)func_80100094(param_0, 0) + 0x14);
            if (*(s16 *)((u8 *)func_80100094(param_0, 0) + 0xC) == 4) {
                func_808009FC_chpowerhutwitchy(param_0);
            }
            if (*(s16 *)((u8 *)func_80100094(param_0, 0) + 0xC) == 3) {
                *(f32 *)&param_0->actorData[4] = func_800F10B4(local_0, 0.0f, 1.0f, 0.3f, 1.0f);
                func_80800890_chpowerhutwitchy(param_0);
            }
        }
    }
}

s32 func_8080073C_chpowerhutwitchy(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    switch (param_1) {
        case 0xB:
            if (param_2 == 0x31) {
                _capod_entrypoint_14();
                _capod_entrypoint_13(param_0->unk0, 0, 0x35, 0x2010);
                func_80101180(0x39E, 7, 0);
                func_80101180(0x39F, 7, 0);
                return 4;
            }
            return 3;
        case 0x95:
            local_0 = func_800DA298(0xEC) || _glcutDll_entrypoint_20();
            func_800BF744(5, !local_0);
            func_800BF744(6, local_0);
            *(f32 *)&param_0->actorData[4] = func_800F10B4(*(f32 *)((u8 *)func_80100094(param_0, 0) + 0x14), 0.0f, 1.0f, 0.3f, 1.0f);
            if (!local_0) func_80800890_chpowerhutwitchy(param_0);
            else func_808009FC_chpowerhutwitchy(param_0);
            break;
    }
    return _chpowerhut_entrypoint_3(param_0, param_1, param_2, D_80800B14_chpowerhutwitchy);
}

void func_80800890_chpowerhutwitchy(param_0) Actor *param_0;
{
    s32 local_0;
    local_0 = func_800BEA88(0);
    _glid_entrypoint_0(local_0, 4, _chpowerhutwitchy_entrypoint_5, param_0->unk0);
    _glid_entrypoint_0(local_0, 5, _chpowerhutwitchy_entrypoint_5, param_0->unk0);
    local_0 = func_800BEA88(1);
    _glid_entrypoint_0(local_0, 4, _chpowerhutwitchy_entrypoint_5, param_0->unk0);
    _glid_entrypoint_0(local_0, 5, _chpowerhutwitchy_entrypoint_5, param_0->unk0);
}

void chpowerhutwitchy_entrypoint_5(s32 param_0, PowerHutVertex *param_1, PowerHutVertex *param_2, s32 param_3, void *param_4)
{
    f32 local_0;

    local_0 = *(f32 *)&func_80106790(param_4)->actorData[4];
    switch (param_0) {
    case 4:
        while (param_3 > 0) {
            func_800F2FD0(&param_2->local_0, &param_1->local_0, local_0);
            param_3--;
            param_1++;
            param_2++;
        }
        break;
    case 5:
        while (param_3 > 0) {
            func_800F2FD0(&param_2->local_0, &param_1->local_0, local_0);
            param_3--;
            param_1++;
            param_2++;
        }
        break;
    }
}

void func_808009FC_chpowerhutwitchy(this) Actor *this; {
    if (func_800EA05C() == 0xD6) {
        _idworldmake_entrypoint_1(func_800BEA88(0), 0x89D, 4, 1);
    }
    *(s8 *)((char *)func_80100094(this, 0) + 0x19) = 1;
}

void func_80800A58_chpowerhutwitchy(Actor *param_0)
{
    f32 local_1 = -90.0f;
    s32 local_0 = 0;
    if (param_0->unk6C_9 == 0x39E) {
        local_1 = 90.0f;
        local_0 = 1;
    }
    if (_chdoormake_entrypoint_3(param_0, local_1, 0.0f, 100.0f, 1, 0xEC)) {
        _chdoormake_entrypoint_6(param_0, 0.75f);
        if (local_0) _chdoormake_entrypoint_8(param_0, 0x10);
    }
}
