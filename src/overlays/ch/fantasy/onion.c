#include "common.h"

#define OD(n) (((f32 *)param_0->actorData)[n])
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern int func_800E8714(s32);
extern void func_800E8870(u8, f32);
extern void func_800E8830();
extern f32 func_800F13C4(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C7A68(s32, f32, f32 *);
extern s32 func_800EEDE8(f32 *, f32 *, f32);
extern f32 func_800DC0C0(void);
extern void func_80101EE4(Actor *, f32);
typedef struct { u32 pad : 12; u32 flag : 1; u32 pad2 : 19; } BitTest12;
typedef struct { u32 pad : 27; u32 flag : 1; u32 pad2 : 4; } BitTest27;
extern s32 _plsu_entrypoint_3(Unk80132ED0 *);
extern s32 func_80015184(void);
extern void func_80015178(s32);
extern s32 func_800F5C94(s32);
extern void func_800F79DC(s32, s32, Unk80132ED0 *);
extern s32 func_800F54E4(void);
extern void func_800F5A00(s32, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern s32 func_800D90A4(f32 *);
extern s32 func_800D7520(s32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_800F5B38(s32, f32 *);
extern void func_800F832C(s32, f32 *);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800F8418(s32, f32 *);
extern u8 D_80800748_chfantasyonion[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800DE498(s32, f32 *, void *, f32, s32, s32);
extern int D_80800754_chfantasyonion;

f32 func_80800000_chfantasyonion(Actor *param_0)
{
    Vec3f local_1;
    Vec3f local_0;
    Vec3f local_2;

    func_800EE7F8(local_0.f, param_0->position);
    func_800EE7F8(local_1.f, param_0->position);
    local_1.f[1] += 250.0f;
    local_0.f[1] -= 1400.0f;
    func_800BEF00(local_1.f, local_0.f, local_2.f, 0);
    if (param_0->actorData[0] == 0) {
        param_0->actorData[0] = func_800E8714(1);
        func_800E8870((u8)param_0->actorData[0], 300.0f);
    }
    func_800E8830((u8)param_0->actorData[0], local_0.f);
    return local_0.f[1];
}

void func_808000BC_chfantasyonion(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    if (func_8010568C(param_0, 0)) {
        func_80105634(param_0);
        ((BitTest27 *)((u8 *)param_0 + 0x74))->flag = 0;
        if (param_0->rotation[1] > 99.0f) { param_0->unk64_20 = 1; }
        else { param_0->unk64_20 = 0; }
        *(f32 *)((u8 *)param_0 + 0x24) = func_800F10B4(func_800F13C4(param_0->rotation[1], 100.0f),
            0.0f, 99.0f, 0.0f, (f32)((s32)param_0->unk74_7 / 10));
        *(f32 *)((u8 *)param_0 + 0x34) = _glsplinefind_entrypoint_3(param_0->position);
        func_800C7A68(func_800D7520((s32)*(f32 *)((u8 *)param_0 + 0x34)), 0.0f, local_0);
        func_800C7A68(func_800D7520((s32)*(f32 *)((u8 *)param_0 + 0x34)), 1.0f, local_1);
        if (func_800EEDE8(local_0, local_1, 200.0f)) {
            ((BitTest12 *)((u8 *)param_0 + 0x64))->flag = 1;
            func_800D8648((s32)*(f32 *)((u8 *)param_0 + 0x34), local_1);
        } else {
            ((BitTest12 *)((u8 *)param_0 + 0x64))->flag = 0;
        }
        func_80101FDC(param_0, 2);
    }
    *(f32 *)((u8 *)param_0 + 0x28) = func_80800000_chfantasyonion(param_0);
    func_80101EE4(param_0, func_800DC0C0());
}

void func_80800254_chfantasyonion(Actor *param_0)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    f32 local_4[3];
    s32 local_5;
    f32 local_6;
    f32 local_7[3];

    local_0 = _plsu_entrypoint_3(param_0->unk0);
    if (local_0 != -1) {
        if (OD(5) == -1.0f && OD(6) == 0.0f) {
            param_0->unk79_4 = func_80015184();
            func_80015178(4);
            OD(6) = 3.0f;
        }
        if (func_800F5C94(local_0) != 0xC) {
            func_800F79DC(local_0, 4, param_0->unk0);
            local_0 = -1;
        }
        if (local_0 != -1) {
            func_800F5A00(func_800F54E4(), local_1);
            func_800EF3DC(local_1, param_0->position);
            local_2 = param_0->rotation[1];
        }
    } else if (OD(5) != -1.0f) {
        func_80015178(param_0->unk79_4);
    }
    switch (param_0->unk70_10) {
    case 1:
        break;
    case 2:
        local_5 = param_0->unk64_20;
        func_800EE7F8(local_4, param_0->position);
        if (func_800D90A4(&OD(3))) {
            if (!param_0->unk64_19) {
                param_0->unk64_20 = !param_0->unk64_20;
            }
            OD(3) = (s32)param_0->unk74_7 / 10;
        }
        if (param_0->unk64_20) {
            local_3 = func_800F10B4(OD(3), 0.0f, (s32)param_0->unk74_7 / 10, 0.0f, 1.0f);
        } else {
            local_3 = func_800F10B4(OD(3), 0.0f, (s32)param_0->unk74_7 / 10, 1.0f, 0.0f);
        }
        func_800C7A68(func_800D7520(OD(7)), local_3, param_0->position);
        if (local_5) {
            param_0->unk54 = func_800F1DF4(local_4, param_0->position);
        } else {
            param_0->unk54 = func_800F1DF4(param_0->position, local_4);
        }
        func_80102BAC(param_0, 0.05f, 0.01f, 4.0f);
        break;
    }
    if (!func_800D90A4(&OD(6))) {
        local_6 = func_800F10B4(OD(6), 3.0f, 0.0f, 1.0f, 0.0f);
        param_0->position[1] += func_80013970(local_6 * 2160.0f) * (20.0f * local_6);
    }
    if (local_0 != -1) {
        local_2 -= param_0->rotation[1];
        func_800F5B38(func_800F54E4(), local_7);
        local_7[1] -= local_2;
        func_800F832C(func_800F54E4(), local_7);
        func_800EF934(local_1, local_1, -local_2);
        func_800EF04C(local_1, param_0->position);
        func_800F8418(func_800F54E4(), local_1);
    }
    OD(5) = local_0;
    OD(4) = func_80800000_chfantasyonion(param_0);
}

void func_80800624_chfantasyonion(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1;
    if (func_800E88E4((u8)param_0->actorData[0])) {
        local_1 = *(f32 *)&param_0->actorData[4];
        func_800EFA4C(local_0, param_0->position[0], local_1, param_0->position[2]);
        func_800DF830(0);
        func_800DE498(param_1, local_0, D_80800748_chfantasyonion,
            func_800F10B4(param_0->position[1] - local_1, 1400.0f, 0.0f, 0.25f, 1.0f),
            0, func_800D674C(0x637));
    }
    func_80101870(param_0, param_1);
}

void func_808006E0_chfantasyonion(u8 *param_0)
{
    s32 temp_v0;

    temp_v0 = (*(s32 *)((char *)(param_0) + 0x18));
    if (temp_v0 != 0)
    {
        func_800E87E0(temp_v0 & 0xFF, param_0);
        (*(s32 *)((char *)(param_0) + 0x18)) = 0;
    }
}

int chfantasyonion_entrypoint_0()
{
  return (int)&D_80800754_chfantasyonion;
}
