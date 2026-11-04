#include "common.h"

extern Vec3f D_808004A8_chlifeforcespell;
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_20(void *, f32);
extern u8 D_808004C0_chlifeforcespell[];
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F3214(f32 *, f32 *, void *, f32);
extern f32 _sumumbofx_entrypoint_22(void *);
extern void _subaddiefade_entrypoint_9();
extern s32 D_808004B4_chlifeforcespell[];
extern int func_80100094();
extern void func_800EFD24(f32 *);
extern f32 _sumumbofx_entrypoint_21(void *);
extern s32 _sumumbofx_entrypoint_5(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_7();
extern Actor *func_80108528(s32, f32 *, s32, Actor **);

int chlifeforcespell_entrypoint_0()
{
    extern int D_80800460_chlifeforcespell[];
    return (int) &D_80800460_chlifeforcespell;
}

// Init: mumbofx glow for the life force spell (pad 0xD).
void func_8080000C_chlifeforcespell(Actor *actor)
{
    Vec3f origin = D_808004A8_chlifeforcespell;
    void *fx;
    _sumumbofx_entrypoint_0(actor, 1, 0x14, (s16) _chmumbopad_entrypoint_0(0xD));
    fx = func_80100094(actor, 1);
    _sumumbofx_entrypoint_2(fx);
    _sumumbofx_entrypoint_25(fx, 150, origin.f);
    _sumumbofx_entrypoint_24(fx, 0.7f);
    _sumumbofx_entrypoint_15(fx, 2.0f);
    _sumumbofx_entrypoint_20(fx, 3.0f);
}

// Grows and flashes the glow, then notifies the target (message 0x4C) and sets flag 0x9DF.
void func_808000C8_chlifeforcespell(Actor *actor)
{
    f32 glow_pos[3];
    void *fx;
    Actor *target;
    fx = (void *) func_80100094(actor, 1);
    target = func_80106790(actor->unk3C);
    func_800EFD24(glow_pos);
    if (func_800DA298(0x9DE)) {
        _subaddieskeleton_entrypoint_0(target, actor->unk6C_0, actor->position);
        _sumumbofx_entrypoint_7(fx, actor->actorData[3], 0, 20, glow_pos, actor->position,
                                &D_808004B4_chlifeforcespell);
        switch (actor->unk70_10) {
            case 1:
                if (_sumumbofx_entrypoint_21(fx) == 0.0f) {
                    func_800D9078(&actor->unk58);
                    if (_sumumbofx_entrypoint_5(fx, 1.85f)) {
                        _sumumbofx_entrypoint_17(fx, ((f32 *) actor->actorData)[4]);
                        func_80101FDC(actor, 2);
                        actor->unk58 = ((f32 *) actor->actorData)[4];
                    }
                }
                break;
            case 2:
                if (func_800D9078(&actor->unk58)) {
                    _chglowbo_entrypoint_6();
                    _sumumbofx_entrypoint_16(fx, 1.5f);
                    func_80101FDC(actor, 3);
                }
                break;
            case 3:
                if (_sumumbofx_entrypoint_22(fx) < 0.05f) {
                    _sumumbofx_entrypoint_1(actor, 1);
                    func_8010114C(actor->unk3C, 0x4C, 0);
                    func_800FFA88(actor->unk0);
                    func_800DA544(0x9DF);
                    func_800DA524(0x9DE);
                    return;
                }
        }
        _sumumbofx_entrypoint_14(fx);
    }
}

s32 func_8080028C_chlifeforcespell(s32 actor, s32 frame)
{
    _sumumbofx_entrypoint_9(func_80100094(actor, 1), frame);
    _sumumbofx_entrypoint_8(func_80100094(actor, 1), frame);
}

// Spawns the spell actor (0x45C) on a target.
Unk80132ED0 *chlifeforcespell_entrypoint_1(Actor **owner, f32 *pos, s32 param_2, f32 param_3,
                                           s32 param_4)
{
    Actor *spell;

    spell = func_80108528(0x45C, pos, 0, owner);
    *(f32 *) &spell->actorData[3] = param_2;
    spell->unk6C_0 = param_4;
    *(f32 *) &spell->actorData[4] = param_3;
    spell->unk58 = 1.85f;
    spell->unk3C = (*owner)->unk0;
    return spell->unk0;
}

// Tints the target while the spell runs.
int chlifeforcespell_entrypoint_2(void *param_0, Unk80132ED0 *param_1, f32 *out)
{
    Actor *target;
    void *fx;
    f32 target_pos[3];
    f32 blend;

    target = func_80106790(param_1);
    fx = (void *) func_80100094(target, 1);
    if (func_800DA298(0x9DE) && fx) {
        _subaddiefade_entrypoint_9(param_0, target_pos);
        if (target->unk70_10 == 1) {
            blend = func_800F10B4(target->unk58, 0.0f, 1.85f, 1.0f, 0.0f);
            func_800F3214(out, target_pos, D_808004C0_chlifeforcespell, blend);
            return 1;
        }
        func_800F3214(out, target_pos, D_808004C0_chlifeforcespell,
                      _sumumbofx_entrypoint_22(fx));
        return 1;
    }
    _subaddiefade_entrypoint_9(param_0, out);
    return 0;
}

extern void func_80105834();
extern void func_80107C2C();
int D_80800460_chlifeforcespell[18] = {0x158045C,
                                       -0xFFFF,
                                       0x0,
                                       (u32) func_808000C8_chlifeforcespell,
                                       (u32) func_80105834,
                                       (u32) func_8080028C_chlifeforcespell,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x400,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_8080000C_chlifeforcespell,
                                       (u32) func_80107C2C,
                                       -0x7FFFFBFE,
                                       0x0,
                                       0x0};
Vec3f D_808004A8_chlifeforcespell = {0.0f, 0.0f, 0.0f};
s32 D_808004B4_chlifeforcespell[3] = {0x0, 0x42B40000, 0x0};
u8 D_808004C0_chlifeforcespell[16] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x60,
                                      0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x0};
