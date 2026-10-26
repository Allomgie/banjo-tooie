#include "common.h"

extern void func_80101FDC();
extern u8 D_8080061C_chcanarymarycage[];
extern u8 D_80800610_chcanarymarycage[];
extern void func_8010D5DC(void);
extern s32 func_800EFFB4(f32 *, f32, void *);
extern void func_800F4AC0(s32, void *, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_8008FB10(f32 *, f32, f32, f32);
extern void func_8008FAC8(f32 *, f32, f32, f32);
extern s16 D_80800668_chcanarymarycage[];
extern u8 D_80800628_chcanarymarycage[];
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern void *func_80100094(Actor *, u32);
extern void *func_80101080(void);
extern void *func_80106790(void *);
extern void *_subaddielink_entrypoint_4();
extern void _chexploder_entrypoint_6(void *, f32, f32);
extern int D_80800674_chcanarymarycage;
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_8010A730(), func_8080018C_chcanarymarycage(), func_80800284_chcanarymarycage();

void func_80800000_chcanarymarycage(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    s32 n;
    func_80101FDC(param_0, param_1);
    switch (param_0->unk70_10) {
    case 2: break;
    case 3:
        for (param_1 = 0, n = 8; param_1 != n; param_1++) {
            if (func_800F6438(param_1)) {
                func_800F5A00(param_1, local_0);
                if (func_800EFFB4(local_0, 420.0f, D_80800610_chcanarymarycage)) {
                    func_800F497C(param_1);
                    func_800F49A8(param_1, 1);
                    func_800F4A00(param_1, 1);
                    func_800F49D4(param_1, func_8010D5DC, param_0->unk0);
                    func_800F4AC0(param_1, D_8080061C_chcanarymarycage, 200.0f);
                    param_0->unk79_4++;
                }
            }
        }
        if (param_0->unk79_4 == 0) func_80800000_chcanarymarycage(param_0, 4);
        break;
    case 4:
        func_800DA3B8(0, 1);
        func_8010A570(param_0);
        break;
    }
}

void func_8080018C_chcanarymarycage(param_0) Actor *param_0;
{
    switch (param_0->unk70_10) {
        case 1:
            func_800EEB9C((f32 *)((u8 *)param_0 + 0x18), param_0->rotation[1] + 180.0f, 60.0f);
            func_800EF04C((f32 *)((u8 *)param_0 + 0x18), param_0->position);
            func_8008FB10((f32 *)((u8 *)param_0 + 0x18), 440.0f, 0.0f, 280.0f);
            func_800EEB9C((f32 *)((u8 *)param_0 + 0x18), param_0->rotation[1], 145.0f);
            func_800EF04C((f32 *)((u8 *)param_0 + 0x18), param_0->position);
            ((f32 *)((u8 *)param_0 + 0x18))[1] += 150.0f;
            func_8008FAC8((f32 *)((u8 *)param_0 + 0x18), 150.0f, 300.0f, 50.0f);
            break;
        case 2:
            func_80800000_chcanarymarycage(param_0, 3);
            break;
        case 4:
            break;
    }
}

void func_80800284_chcanarymarycage(param_0) s32 param_0; {
    s32 sp1C;

    sp1C = func_80100094(param_0, 0);
    if ((func_800DA298(0x66) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_80800000_chcanarymarycage(param_0, 4);
    }
    _subaddielink_entrypoint_0(sp1C);
}

int func_808002E0_chcanarymarycage(param_0) Actor *param_0;
{
  if (!func_800DB9B0())
  {
    if (func_800DA298(1) && !func_800DA298(0x507))
    {
      func_800DA544(0x66);
      func_800DA544(0x507);
    }
  }
}

void func_80800338_chcanarymarycage(Actor *param_0, Actor **param_1)
{
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800668_chcanarymarycage);
    func_800EEB9C((f32 *)param_0->actorData, param_0->rotation[1] - 100.0f, 300.0f);
    ((f32 *)param_0->actorData)[1] = 180.0f;
    func_800EF04C(param_0->actorData, param_0->position);
    func_800BBCB8((f32 *)param_0->actorData, 0, 1.0f, 10, D_80800628_chcanarymarycage);
    _chexploder_entrypoint_4(param_0, (*param_1)->position, 0x44);
    param_0->unk64_16 = 1;
    func_800DA544(1);
    func_80800000_chcanarymarycage(param_0, 2);
}

s32 func_80800410_chcanarymarycage(Actor *param_0, s32 param_1, Actor **param_2)
{
    void *local_0;
    void *local_1;
    void *local_2;
    void *local_3;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x90:
        local_1 = func_80106790(func_80101080());
        _chexploder_entrypoint_9(local_1, 1, 0);
        _chexploder_entrypoint_9(local_1, 2, 1);
        _chexploder_entrypoint_9(local_1, 3, 0);
        _chexploder_entrypoint_6(local_1, 200.0f, 300.0f);
        _subaddielink_entrypoint_1(local_0, *(s32 *)local_1);
        break;
    case 0xAB:
        local_2 = _subaddielink_entrypoint_4(local_0);
        local_3 = func_80101080();
        func_801018A4(param_0, local_3);
        if (1) {}
        if (local_2 != NULL) {
            func_8010114C(*(void **)local_2, 0xAB, 0);
        }
        break;
    case 0x1F:
        func_801015D0(param_0);
        if (param_0->unk70_10 == 1) {
            func_800DF744(1, 1);
        } else {
            func_800DF744(1, 2);
        }
        func_800DF744(2, 0);
        func_800DF744(3, 1);
        break;
    case 0x32:
        param_0->unk79_4--;
        if (param_0->unk79_4 == 0) {
            func_80800000_chcanarymarycage(param_0, 4);
        }
        break;
    case 0x40:
        if (!func_80090270(local_0)) {
            func_80800338_chcanarymarycage(param_0, (*(Actor ** *)&param_2));
        }
        break;
    default:
        return 0;
    }
    return 1;
}

int chcanarymarycage_entrypoint_0()
{
  return (int)&D_80800674_chcanarymarycage;
}
