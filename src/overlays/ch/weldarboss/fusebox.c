#include "common.h"

extern void *D_80800670_chweldarbossfusebox;
extern void *D_808006B8_chweldarbossfusebox;
extern void *D_80800700_chweldarbossfusebox;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern int D_80800660_chweldarbossfusebox;
typedef struct { f32 position[3]; f32 yaw; f32 scale; s32 flags; } WeldarFuseBoxMarkerPose;
extern s32 func_80101080();
extern s32 func_80106790(s32);
extern void _chexploder_entrypoint_15(s32, s32, f32);
extern void _subaddieaudioquick_entrypoint_2();
extern void func_800BF744(s32, s32);
extern u8 D_80800748_chweldarbossfusebox[];
typedef struct { s32 words[2]; } FuseboxLight30;
extern u8 D_80800790_chweldarbossfusebox[];
extern u8 D_80800798_chweldarbossfusebox[];
extern u8 D_808007B0_chweldarbossfusebox[];
extern s32 D_808007BC_chweldarbossfusebox;
extern void func_80105A9C(Actor *, f32);
int func_80800140_chweldarbossfusebox();
void func_8080032C_chweldarbossfusebox();
int func_80800384_chweldarbossfusebox();
int func_808005F8_chweldarbossfusebox();

void *chweldarbossfusebox_entrypoint_0()
{
  return &D_80800670_chweldarbossfusebox;
}

void *chweldarbossfusebox_entrypoint_1()
{
    return &D_808006B8_chweldarbossfusebox;
}

void *chweldarbossfusebox_entrypoint_2(void)
{
    return &D_80800700_chweldarbossfusebox;
}

void func_80800024_chweldarbossfusebox(Actor *param_0)
{
    func_800BF744(2, func_800DA298(0x18C));
    func_800EFA4C(param_0->position, -1800.0f, 1200.0f, -2200.0f);
    func_80103014(param_0);
    _subaddiefade_entrypoint_14(param_0);
    if (func_800DA298(0x18C)) {
        func_800FFAB0(param_0);
    }
}

s32 func_80800098_chweldarbossfusebox(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    switch (param_1) {
        case 5:
            func_800EE7F8(local_0, param_0->position);
            func_800EF1B8(local_0, param_0->rotation[1], -400.0f);
            _chexploder_entrypoint_3(param_0, local_0, 11);
            func_80101180(0x33D, 10, 0);
            break;
        case 0x90:
            func_80800140_chweldarbossfusebox(param_0);
            break;
        default: return 0;
    }
    return 1;
}

int func_80800140_chweldarbossfusebox(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = func_80106790(func_80101080());
  _chexploder_entrypoint_6(local_0, 0x44E10000, 0x44FA0000);
  _chexploder_entrypoint_7(local_0, 0xC4AF0000, 0xC4960000);
  _chexploder_entrypoint_15(local_0, 2, 1.5f);
  _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80800660_chweldarbossfusebox);
  func_800BF744(2, 1);
}

void func_808001BC_chweldarbossfusebox(Actor *param_0)
{
    WeldarFuseBoxMarkerPose local_0;

    func_800BF744(4, func_800DA298(0x18C));
    func_800EFA4C(param_0->position, 0.0f, 4900.0f, -2300.0f);
    func_80103014(param_0);
    _subaddiefade_entrypoint_14(param_0);
    if (func_800DA298(0x18C)) {
        func_800FFAB0(param_0);
        return;
    }
    if (_subaddiemarker_entrypoint_1(param_0, 0x320, 0x35, &local_0, 1)) {
        func_800EE7F8(param_0->actorData, local_0.position);
    }
}

s32 func_80800268_chweldarbossfusebox(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 5:
        if (++param_0->unk6C_0 == 2) {
            _chexploder_entrypoint_3(param_0, param_0->position, 0xB);
            func_80101180(0x465, 7, 0);
            func_80101180(0x3B3, 0x4F, 0);
            func_80800384_chweldarbossfusebox(param_0);
        }
        break;
    case 0x90:
        func_8080032C_chweldarbossfusebox(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080032C_chweldarbossfusebox(param_0) u8 *param_0; {
    _chexploder_entrypoint_15(func_80106790(func_80101080(param_0)), 2, 1.5f);
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, ((s32 *) &D_80800660_chweldarbossfusebox));
    func_800BF744(4, 1);
}

int func_80800384_chweldarbossfusebox(param_0) Actor *param_0;
{
    extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
    f32 local_0[3];

    func_800EE7F8(local_0, (f32 *)((u8 *)param_0 + 0x18));
    local_0[1] += 400.0f;
    local_0[2] -= 100.0f;
    func_800BABB8(0, (f32 *)((u8 *)param_0 + 0x18), local_0, 1.0f, (s32 *)D_80800748_chweldarbossfusebox);
}

void func_808003F8_chweldarbossfusebox(Actor *param_0)
{
    if (func_800DA298(0x18C)) {
        func_800FFAB0(param_0);
    } else {
        if (param_0->unk74_7 == 0x32) param_0->unk58 = 0.0f;
        else param_0->unk58 = 0.5f;
        func_80105A9C(param_0, param_0->unk74_7 == 0x32 ? 750.0f : 700.0f);
    }
}

void func_8080049C_chweldarbossfusebox(Actor *param_0)
{
    f32 local_0[3];
    FuseboxLight30 local_1;
    if (func_800D90A4(&param_0->unk58)) {
        if (!param_0->actorData[4]) {
            local_1 = *(FuseboxLight30 *)D_80800790_chweldarbossfusebox;
            param_0->actorData[4] = func_800C8A98();
            func_800C8D4C(param_0->actorData[4], &local_1);
        }
        func_800EE7F8(local_0, param_0->position);
        local_0[2] += 200.0f;
        func_800C8CB8(param_0->actorData[4], local_0);
        func_800C8E84(param_0->actorData[4], D_80800798_chweldarbossfusebox + func_8001210C(1) * 12);
        func_80105834(param_0);
        func_808005F8_chweldarbossfusebox(param_0);
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808007B0_chweldarbossfusebox);
        if (func_80105A5C(param_0)) {
            func_800C8B84(param_0->actorData[4]);
            param_0->actorData[4] = 0;
            func_80101180(0x3AE, 5, 0);
            func_800FFAB0(param_0);
        }
    }
}

s32 func_808005C0_chweldarbossfusebox(s32 param_0, s32 param_1, s32 param_2){
    if(param_1 == 0xA){
        func_80103110(param_0, 1);
        return TRUE;
    }
    return FALSE;
}

int func_808005F8_chweldarbossfusebox(param_0) s32 param_0;
{
  if (func_8001210C(3))
  {
    func_800BBCB8(param_0 + 4, 0, 0x3F800000, 2, &D_808007BC_chweldarbossfusebox);
  }
}
