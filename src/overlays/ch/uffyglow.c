#include "common.h"

extern u8 D_80800550_chchuffyglow[];
extern u8 D_8080055C_chchuffyglow[];
extern void *func_80100094();
extern void func_800DE448(f32 *, f32 *, f32, s32, s32);
typedef struct { f32 local_0[3]; } ChuffyVector40;
extern void _subaddiefade_entrypoint_1(void *param_0, int param_1);
extern int D_808005B0_chchuffyglow;
typedef struct { Vec3f local_0[5]; } ChuffyGlowVertices;
extern ChuffyGlowVertices D_80800568_chchuffyglow;
extern Vec3f D_808005A4_chchuffyglow;
extern f32 func_800D8FF8(void);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF3DC(f32 *, f32 *);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_80105834(), func_80107C2C(), func_80800484_chchuffyglow(), func_8080048C_chchuffyglow();
extern u8 D_80800530_chchuffyglow[];

int func_80800000_chchuffyglow(param_0, param_1) Actor *param_0; s32 param_1;
{
    ChuffyVector40 local_0;
    ChuffyVector40 local_1;
    f32 local_2[4];
    s32 local_3;
    s32 local_4;
    u8 *local_5;
    s32 local_6;
    u8 *local_7;
    u8 *local_8;
    local_0 = *(ChuffyVector40 *)D_80800550_chchuffyglow;
    local_1 = *(ChuffyVector40 *)D_8080055C_chchuffyglow;
    local_3 = func_80104248(param_0);
    local_5 = func_80100094(param_0, 0);
    func_80102780(param_0, local_1.local_0);
    func_8008B304(local_3);
    local_4 = func_8008B4D4(local_3);
    func_800DFFA0(local_4, 3, local_5);
    for (local_6 = 0, local_7 = local_5 + 12, local_8 = local_5 + 0x48;
         local_6 != 5; local_6++, local_7 += 12, local_8 += 16) {
        func_800DFFA0(local_4, local_6 + 0x2A, local_7);
        func_800D93A0(local_2, local_8);
        func_800DFF2C(local_4, local_6 + 0x2A, local_2);
    }
    func_800DF830(2);
    func_800DF410(_subaddiefade_entrypoint_0(param_0));
    func_800DF41C(local_4);
    func_800DE448(local_0.local_0, local_1.local_0, param_0->scale, 0, func_8010347C(param_0->unk0));
}

void func_80800180_chchuffyglow(Actor *param_0)
{
    ChuffyGlowVertices local_0 = D_80800568_chchuffyglow;
    Vec3f local_1 = D_808005A4_chchuffyglow;
    Vec3f local_2;
    s32 local_4;
    f32 *local_3;
    f32 *local_5;
    f32 *local_6;
    Vec3f *local_7;

    local_3 = func_80100094(param_0, 0);
    _chchuffy_entrypoint_1(param_0->unk3C, (f32 *)param_0->actorData, ((f32 *)&param_0->actorData[4]));
    switch (param_0->unk70_10) {
    case 1:
        if (param_0->unk58 <= 0.0f) {
            if (_subaddiefade_entrypoint_0(param_0) < 253) {
                _subaddiefade_entrypoint_1(param_0, _subaddiefade_entrypoint_0(param_0) + 3);
            } else {
                param_0->unk70_10 = 2;
            }
        } else {
            param_0->unk58 -= func_800D8FF8();
        }
        break;
    case 2:
        if (!param_0->unk64_20) {
            param_0->unk70_10 = 3;
        }
        break;
    case 3:
        if (_subaddiefade_entrypoint_0(param_0) >= 7) {
            _subaddiefade_entrypoint_1(param_0, _subaddiefade_entrypoint_0(param_0) - 7);
        } else {
            func_800FFAB0(param_0);
        }
        break;
    }
    param_0->unk64_20 = _chchuffy_entrypoint_1(param_0->unk3C, (f32 *)param_0->actorData, ((f32 *)&param_0->actorData[4]));
    func_800EE7F8(local_3, (f32 *)param_0->actorData);
    func_800EF334(local_3, 0.006666666828f);
    func_800EF3DC(local_3, local_1.f);
    func_800E3980(local_2.f);
    local_5 = local_3 + 3;
    local_6 = local_3 + 18;
    for (local_4 = 0, local_7 = local_0.local_0; local_4 < 5; local_5 += 3, local_4++, local_6 += 4, local_7++) {
        func_800EF4E4(local_5, ((f32 *)&param_0->actorData[4])[0], ((f32 *)&param_0->actorData[4])[1], 0.0f, (local_4 - 1.75f) * 750.0f, 0.0f);
        func_800F18FC((f32 *)param_0->actorData, local_2.f, local_6);
        local_3[19 + local_4 * 4] += 90.0f;
        local_3[20 + local_4 * 4] = 180.0f - local_3[18 + local_4 * 4];
        local_3[18 + local_4 * 4] = 0.0f;
        func_800EF334(local_5, 0.006666666828f);
        func_800EF3DC(local_5, local_7->f);
    }
}

void func_80800484_chchuffyglow(s32 arg0) 
{
}
void func_8080048C_chchuffyglow(param_0) void *param_0;
{
  float *new_var;
  _subaddiefade_entrypoint_1(param_0, 0);
  new_var = (float *) (((char *) param_0) + 0x58);
  *new_var = 5.0f;
  new_var = ((char *) param_0) + 0x65;
  *((char *) (((char *) param_0) + 0x65)) = ((*((char *) new_var)) & 0xFF) | 0x10;
  return;
}

void chchuffyglow_entrypoint_0(s32 param_0) {
    s32 *local_0;
    s32 pad[2];
    local_0 = func_80106790();
    (*(s32 *)((s8 *)(func_801084B0(0x30E, &local_0)) + (0x3C))) = (s32) *local_0;
}

int chchuffyglow_entrypoint_1()
{
    return (int)&D_808005B0_chchuffyglow;
}
