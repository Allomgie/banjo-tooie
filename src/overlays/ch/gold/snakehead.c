#include "common.h"

extern int D_80800508_chgoldsnakehead;
extern int D_80800550_chgoldsnakehead;
extern int D_80800598_chgoldsnakehead;
extern void func_800FFAB0();
extern void func_80103014();
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern Actor *_subaddiefind_entrypoint_3(s32, s32 *);
extern s16 *_gccubesearch_entrypoint_1(s32, f32 *);
extern void _gspropctrl_entrypoint_11();
typedef struct { u8 pad_0[0x28]; u32 pad_1 : 18; u32 local_0 : 1; u32 pad_2 : 13; } GoldSnakeCollisionMarker961;
extern s32 D_808004F0_chgoldsnakehead;
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
extern void func_80102B2C(Actor *, f32);
extern void func_80102B6C(Actor *, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void _chdoormake_entrypoint_8(s32, s32);
extern void _chdoormake_entrypoint_9(s32, s32, s32, s32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);

int chgoldsnakehead_entrypoint_0()
{
    return (int)&D_80800508_chgoldsnakehead;
}

int *chgoldsnakehead_entrypoint_1()
{
    return &D_80800550_chgoldsnakehead;
}

int chgoldsnakehead_entrypoint_2()
{
  return &D_80800598_chgoldsnakehead;
}

void func_80800024_chgoldsnakehead(Actor *param_0)
{
    s16 *local_2;
    f32 local_0[3];
    Actor *local_3;
    s32 local_1;

    local_2 = _gccubesearch_entrypoint_1(0x1EA, param_0->position);
    if (func_800DA298(0x18B)) {
        func_800FFAB0(param_0);
        return;
    }
    _gspropctrl_entrypoint_11(local_2, local_0);
    if (local_0[2] <= param_0->position[2]) {
        local_3 = _subaddiefind_entrypoint_2(0x10D, &local_1);
        while (local_3) {
            if (local_3->unk74_7 == param_0->unk74_7 && local_3 != param_0) {
                break;
            }
            local_3 = _subaddiefind_entrypoint_3(0x10D, &local_1);
        }
        param_0->position[0] = local_3->position[0];
        param_0->position[1] = local_3->position[1];
        param_0->position[2] = 2.0f * local_0[2] - local_3->position[2];
    }
    if ((s32)param_0->unk74_7 >= 0x33) {
        ((GoldSnakeCollisionMarker961 *)param_0->unk0)->local_0 = 1;
    } else {
        ((GoldSnakeCollisionMarker961 *)param_0->unk0)->local_0 = 0;
    }
    func_80103014(param_0);
    func_800DA7A8(6, 0, 3);
}

void func_8080015C_chgoldsnakehead(Actor *param_0)
{

    switch (param_0->unk70_10) {
        case 2:
            func_800FC63C(14, 0x7FBC);
            func_800EE7F8(param_0->actorData, param_0->position);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_808004F0_chgoldsnakehead);
            func_80101FDC(param_0, 3);
        case 3:
            param_0->unk50 = func_800DC178(-10.0f, 10.0f);
            param_0->unk54 = func_800DC178(-15.0f, 15.0f);
            func_80102B2C(param_0, 5.0f);
            func_80102B6C(param_0, 5.0f);
            func_800EF214(param_0->position, param_0->rotation[0], param_0->rotation[1] + 90.0f, func_800DC178(50.0f, 250.0f) * func_800D8FF8());
            if (*(f32 *)&param_0->actorData[0] + 125.0f < param_0->position[0]) _subaddiefade_entrypoint_3(param_0);
        case 1:
            break;
    }
}

void func_808002B4_chgoldsnakehead(Actor *param_0, void *param_1)
{
    func_800DF744(1, ((GoldSnakeCollisionMarker961 *)param_0->unk0)->local_0 ? 0 : 1);
    func_800DF744(2, ((GoldSnakeCollisionMarker961 *)param_0->unk0)->local_0);
    func_80101870(param_0, param_1);
}

int func_80800324_chgoldsnakehead(Actor *param_0, s32 param_1)
{
    s32 local_0;
    func_8010A570(param_0);
    func_80101FDC(param_0, 2);
    func_80102FE8(param_0, 0);
    func_80103110(param_0, 1);
    local_0 = func_800DA564(6, 3) + 1;
    func_800DA7A8(6, local_0, 3);
    if (local_0 == 6)
    {
        func_80101180(0x10E, 7, 0);
    }
}

s32 func_808003A8_chgoldsnakehead(unsigned int param_0, s32 param_1, s32 param_2)
{
  unsigned int *new_var;
  ;
  if ((param_1 == 0x40) ^ 0)
  {
    func_80800324_chgoldsnakehead(*(&param_0), param_2 | 0);
    if (!param_2)
    {
    }
    return 1;
  }
  return 0;
}

void func_808003E0_chgoldsnakehead(s32 param_0) {
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 200.0f, 0x41, 0x18B)) {
        _chdoormake_entrypoint_8(param_0, 5);
        _chdoormake_entrypoint_9(param_0, 0, 6, 0x10);
    }
}

void func_80800440_chgoldsnakehead(Actor *param_0)
{
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 200.0f, 0x60, 0x59C)) {
        _chdoormake_entrypoint_6(param_0, 3.0f);
        _chdoormake_entrypoint_8(param_0, 5);
        _chdoormake_entrypoint_12(param_0, 0, 0xD);
        _chdoormake_entrypoint_9(param_0, 0, 0x2B, 0x2900);
    }
    if (func_800DA298(0x59C) && !_glcutDll_entrypoint_19(0xD)) {
        func_800FFAB0(param_0);
    }
}
