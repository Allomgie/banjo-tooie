#include "common.h"

extern void *D_80800410_chweldarbossfireball;
extern u8 D_80800458_chweldarbossfireball[];
extern f32 func_800DC178(f32, f32);
extern void func_800EF368(f32 *, f32);
extern void func_800C8E54(s32, f32, f32);
extern u32 D_80800468_chweldarbossfireball[];
extern u32 D_80800474_chweldarbossfireball[];
extern f32 func_800D8FF8(void);
extern void *func_801040D0(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800D93A0(f32 *, f32 *);
typedef union { s32 word; Unk80132ED0 *marker; } WeldarFireballEventPayload;
extern Actor *func_80106790();
extern u8 B_808004E0_chweldarbossfireball[];
extern u8 D_80800480_chweldarbossfireball[];
extern u8 D_808004C4_chweldarbossfireball[];
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
void func_808002E0_chweldarbossfireball();
s32 func_80800404_chweldarbossfireball();

void *chweldarbossfireball_entrypoint_0()
{
    return &D_80800410_chweldarbossfireball;
}

void func_8080000C_chweldarbossfireball(Actor *param_0)
{
    f32 local_0[2];

    param_0->actorData[7] = 0;
    param_0->unk50 = func_800DC178(0.0f, 360.0f);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800458_chweldarbossfireball);
    func_800EFB24((f32 *)&param_0->actorData[4], (f32 *)&param_0->actorData[0], param_0->position);
    func_800F18FC(param_0->position, (f32 *)&param_0->actorData[0], local_0);
    param_0->rotation[0] = -local_0[0];
    param_0->rotation[1] = local_0[1];
    func_800EF368((f32 *)&param_0->actorData[4], 1800.0f);
    param_0->actorData[7] = func_800C8A98();
    func_800C8E54(param_0->actorData[7], 500.0f, 800.0f);
}

void func_808000C4_chweldarbossfireball(Actor *param_0)
{
    param_0->unk50 += func_800D8FF8() * 500.0f;
    if (param_0->unk70_10 == 1) {
        if (func_8010B990(param_0, 0x400007) & 0x20) {
            func_808002E0_chweldarbossfireball(param_0);
        }
        func_80800404_chweldarbossfireball(param_0);
    }
    if (param_0->actorData[7]) {
        func_800C8CB8(param_0->actorData[7], param_0->position);
        func_800C8E84(param_0->actorData[7], func_8001210C(1) ? D_80800474_chweldarbossfireball : D_80800468_chweldarbossfireball);
    }
}

int func_8080017C_chweldarbossfireball(Actor *param_0)
{
  s32 new_var;
  s32 *local_0 = (s32 *) (((char *) param_0) + ((((0x34 & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu));
  new_var = *local_0;
  if (new_var != 0)
  {
    func_800C8B84(new_var);
    *local_0 = 0;
  }
}

int func_808001B4_chweldarbossfireball(Actor *param_0, s32 param_1)
{
    s32 *local_0;
    local_0 = (s32 *)((char *)param_0 + 0x38);
    func_80101970(param_0);
    func_800DF830(2);
    func_800DE448((s32 *)((char *)param_0 + 0x4), (s32 *)((char *)param_0 + 0x44), *local_0, 0, func_800D674C(0x89D));
    func_801018A4(param_0, param_1);
}

void func_80800214_chweldarbossfireball(Actor *param_0, void *param_1)
{
    void *local_0;
    f32 local_1[3];
    f32 local_2[4];
    local_0 = func_801040D0(param_0);
    func_801015D0(param_0);
    func_800DF41C(local_0);
    func_800EFA4C(local_1, param_0->unk50, 0.0f, 0.0f);
    func_800D93A0(local_2, local_1);
    func_800DFF2C(local_0, 0x2A, local_2);
}

s32 func_80800284_chweldarbossfireball(Actor *param_0, s32 param_1, WeldarFireballEventPayload param_2)
{
    switch (param_1) {
    case 64:
        func_808002E0_chweldarbossfireball(param_0);
        break;
    case 31:
        func_80800214_chweldarbossfireball(param_0, param_2.word);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808002E0_chweldarbossfireball(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 *local_4;
    Actor *local_2;
    f32 local_3[3];
    local_2 = func_80106790(param_0->unk3C);
    func_80103DFC(param_0, local_0);
    func_800EE7F8(local_1, local_0);
    if (local_2) {
        local_4 = local_2->position;
    } else {
        local_4 = (f32 *)B_808004E0_chweldarbossfireball;
    }
    func_800EF1B8(local_1, func_800F1DF4(param_0->position, local_4), 60.0f);
    local_1[1] -= 40.0f;
    func_800BBCB8(local_0, local_1, 1.0f, 10, D_80800480_chweldarbossfireball);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808004C4_chweldarbossfireball);
    if (param_0->actorData[7]) {
        func_800EE7F8(local_3, param_0->position);
        local_3[1] += 100.0f;
        func_800C8CB8(param_0->actorData[7], local_3);
        param_0->actorData[7] = _chlightfader_entrypoint_1(param_0->actorData[7], 1.4f, 1);
    }
    func_8010A570(param_0);
    func_800FFAB0(param_0);
}

s32 func_80800404_chweldarbossfireball(param_0) s32 param_0;{
    s32 local_0;
    local_0 = param_0;
}
