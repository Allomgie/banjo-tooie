#include "common.h"

extern int D_80800480_chgruntyfireball;
extern u8 D_808004C8_chgruntyfireball[];
extern u32 D_808004E0_chgruntyfireball[][3];
extern void func_80018820(s32, f32, f32);
extern void func_800E15CC(s32, f32, f32);
extern void func_8010D09C(s32, f32 *, f32);
extern s32 D_808004F8_chgruntyfireball[];
extern s32 D_8080050C_chgruntyfireball[];
extern void func_800EF368(f32 *, f32);
extern s32 D_80800514_chgruntyfireball;
extern s32 D_80800524_chgruntyfireball;
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern int D_80800588_chgruntyfireball;
extern int D_80800554_chgruntyfireball;
int func_80800260_chgruntyfireball();
void func_808003D8_chgruntyfireball();

int *chgruntyfireball_entrypoint_0()
{
    return &D_80800480_chgruntyfireball;
}

void func_8080000C_chgruntyfireball(u8 *param_0) {
    (*(s32 *)((s8 *)(param_0) + (0x24))) = 0;
    func_80109EEC(param_0, 0x40);
}

void func_80800030_chgruntyfireball(Actor *param_0)
{
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808004C8_chgruntyfireball);
    switch (param_0->unk70_10) {
        case 1:
            func_808003D8_chgruntyfireball(param_0);
            break;
        case 2:
            if (func_8010B990(param_0, 0x400007) & 0x20) {
                func_80018820(0, 1.0f, 0.18f);
                func_800E15CC(0, 22.0f, 0.8f);
                func_80800260_chgruntyfireball(param_0);
            } else {
                func_808003D8_chgruntyfireball(param_0);
            }
            break;
    }
    if (param_0->actorData[3]) {
        func_800C8CB8(param_0->actorData[3], param_0->position);
        func_800C8E84(param_0->actorData[3], D_808004E0_chgruntyfireball[func_8001210C(1)]);
    }
}

s32 func_80800130_chgruntyfireball(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    s32 pad[2];

    switch (param_1) {
        case 0xA:
            func_8010A590(param_0);
            func_80101FDC(param_0, 2);
            func_8010D09C((u16)(param_2 >> 16), local_0, 0.0f);
            local_0[1] += 50.0f;
            func_800EFB24(&param_0->actorData[4], local_0, param_0->position);
            func_800EF368((f32 *)&param_0->actorData[4], param_2 & 0xFFFF);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808004F8_chgruntyfireball);
            break;
        case 0x40:
            func_80800260_chgruntyfireball(param_0);
            break;
        case 0x95:
            param_0->actorData[3] = func_800C8A98();
            func_800C8CB8(param_0->actorData[3], param_0->position);
            func_800C8D4C(param_0->actorData[3], D_8080050C_chgruntyfireball);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80800260_chgruntyfireball(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_3;
    s32 local_4;
    func_8010A570(param_0);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800514_chgruntyfireball);
    func_800EE7F8(local_0, param_0->position);
    local_0[1] += -10.0f;
    local_3 = func_800B53A4(10);
    for (local_4 = 0; local_4 < 10; local_4++) {
        func_800EEB9C(local_1, local_4 * 36.0f, func_800DC178(60.0f, 80.0f));
        func_800EF04C(local_1, param_0->position);
        func_800BABB8(local_3, local_1, local_0, 1.0f, &D_80800524_chgruntyfireball);
    }
    if (*(s32 *)((u8 *)param_0 + 0x24)) *(s32 *)((u8 *)param_0 + 0x24) = _chlightfader_entrypoint_1(*(s32 *)((u8 *)param_0 + 0x24), 1.5f, 2);
    func_800FFAB0(param_0);
}

void func_808003D8_chgruntyfireball(param_0) s32 param_0;
{
  f32 local_0[3];
  func_800BBCB8(param_0 + 4, param_0 + 4, 0x3F800000, 1, &D_80800588_chgruntyfireball);
  func_800EE7F8(local_0, param_0 + 0x28);
  func_800EF368(local_0, 1e+02f);
  func_800EF334(local_0, 0xBF800000);
  func_800EF04C(local_0, param_0 + 4);
  func_800BBCB8(local_0, param_0 + 4, 0x3F4CCCCD, 1, &D_80800554_chgruntyfireball);
}
