// Probably the target of Mumbo's Enlarge spell: small swamp platforms that grow from scale
// 2 to 7 with a wobble. At the end it spawns the spent Glowbo prop and sets flags 0x160
// and 0x9DF.
#include "common.h"

typedef struct {
    u8 pad_0[0x6C];
    u32 prop_index : 11;
    u32 pad_1 : 21;
} SwampPlatformKind;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_80103EF4(Actor *);
extern void func_800DF500(f32, f32, f32);
extern f32 func_80103EAC(Actor *);
extern s32 _subaddiefind_entrypoint_4(s32, Actor **, s32);
extern void func_80103DFC(Actor *, f32 *);
extern void *func_80100094(Actor *, s32);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, f32 *, f32 *);
extern int D_808009F8_chswampplatform[];
extern f32 D_808009D0_chswampplatform[];
extern f32 D_808009E4_chswampplatform[];
extern void func_80103110(Actor *, s32);
extern s32 func_800DA298(s32);
extern s32 _chmumbopad_entrypoint_0(s32);
extern void _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
extern void _sumumbofx_entrypoint_2(s32);
extern void _sumumbofx_entrypoint_25(s32, s32, s32 *);
extern void _sumumbofx_entrypoint_24(s32, f32);
extern void _sumumbofx_entrypoint_15(s32, f32);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_80101FDC(Actor *, s32);
extern void func_8010A800(Actor *, s32);
extern void _sumumbofx_entrypoint_14(s32);
extern s32 _sumumbofx_entrypoint_27(s32);
extern void _sumumbofx_entrypoint_18(s32, f32);
extern void _sumumbofx_entrypoint_5(s32, f32);
extern void _sumumbofx_entrypoint_17(s32, f32);
extern f32 _sumumbofx_entrypoint_21(s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern f32 func_800138D0(f32);
extern f32 mlAbsF(f32);
extern void _chglowbo_entrypoint_6(void);
extern void _sumumbofx_entrypoint_16(s32, f32);
extern void _sumumbofx_entrypoint_1(Actor *, s32);
extern void func_800DA524(s32);
extern void func_800DA544(s32);

// Small swamp platform: init scale 7 if flag 0x160 (enlarged) is set, else 2.
void func_80800000_chswampplatform(Actor *actor)
{
    if (!func_800DA298(0x160)) {
        if (!_gccubesearch_entrypoint_10(0x28E, ((SwampPlatformKind *) actor)->prop_index))
            func_80101FDC(actor, 0);
        actor->scale = 2.0f;
    } else
        actor->scale = 7.0f;
    func_800EE7F8((f32 *) &actor->actorData[0], actor->position);
    func_800EFA4C((f32 *) &actor->actorData[4], 1.0f, 1.0f, 1.0f);
    actor->unk64_20 = 0;
    actor->unk64_19 = 0;
    *(f32 *) &actor->actorData[7] = 0.0f;
}

void func_80800804_chswampplatform();

// Mumbo Enlarge spell (flag 0x9DE): grows the platforms from scale 2 to 7, then sets 0x160 and 0x9DF.
void func_808000BC_chswampplatform(Actor *actor)
{
    s32 zero_vec[3];
    f32 ease_in;
    f32 ease_out;

    switch (actor->unk70_10) {
        case 0:
            func_80103110(actor, 0);
            break;
        case 1:
            if (func_800DA298(0x9DE)) {
                zero_vec[0] = 0;
                zero_vec[1] = 0;
                zero_vec[2] = 0;
                _sumumbofx_entrypoint_0(actor, 1, 0x32, _chmumbopad_entrypoint_0(8));
                _sumumbofx_entrypoint_2(func_80100094(actor, 1));
                _sumumbofx_entrypoint_25(func_80100094(actor, 1), 0x7D, zero_vec);
                _sumumbofx_entrypoint_24(func_80100094(actor, 1), 0.65f);
                _sumumbofx_entrypoint_15(func_80100094(actor, 1), 3.0f);
                _capod_entrypoint_13(actor->unk0, 0, 10, 0x210);
                func_80101FDC(actor, 2);
                func_8010A800(actor, 2);
            }
            break;
        case 2:
            func_80800804_chswampplatform(actor);
            _sumumbofx_entrypoint_14(func_80100094(actor, 1));
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                _sumumbofx_entrypoint_18(func_80100094(actor, 1), 4.0f);
                func_80101FDC(actor, 3);
            }
            break;
        case 3:
            func_80800804_chswampplatform(actor);
            _sumumbofx_entrypoint_14(func_80100094(actor, 1));
            _sumumbofx_entrypoint_5(func_80100094(actor, 1), 2.0f);
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                _sumumbofx_entrypoint_17(func_80100094(actor, 1), 4.0f);
                func_80101FDC(actor, 4);
            }
            break;
        case 4:
            if (2.0f < _sumumbofx_entrypoint_21(func_80100094(actor, 1))) {
                if (!actor->unk64_20) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_808009D0_chswampplatform);
                    actor->unk64_20 = 1;
                }
                ease_in = func_800138D0(
                    (_sumumbofx_entrypoint_21(func_80100094(actor, 1)) - 2.0f) * 0.5f * 90.0f);
                actor->unk58 = ease_in;
                actor->scale = actor->unk58 * 5.0f * 0.5f + 2.0f;
                ((f32 *) actor->actorData)[4] = actor->unk58 * 2.0f + 1.0f;
                ((f32 *) actor->actorData)[5] = actor->unk58 * 2.0f + 1.0f;
                ((f32 *) actor->actorData)[6] = actor->unk58 * 2.0f + 1.0f;
            } else {
                if (!actor->unk64_19) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_808009E4_chswampplatform);
                    actor->unk64_19 = 1;
                }
                ease_out = 1.0f - func_800138D0(_sumumbofx_entrypoint_21(func_80100094(actor, 1)) *
                                               0.5f * 90.0f);
                actor->unk58 = ease_out;
                actor->scale = (1.0f - actor->unk58) * 5.0f * 0.5f + 2.0f + 2.5f;
                ((f32 *) actor->actorData)[4] =
                    mlAbsF(func_800138D0(actor->unk58 * 1.5f * 360.0f)) *
                        (actor->unk58 * 2.0f) +
                    1.0f;
                ((f32 *) actor->actorData)[5] =
                    mlAbsF(func_800138D0(actor->unk58 * 2.5f * 360.0f)) *
                        (actor->unk58 * 2.0f) +
                    1.0f;
                ((f32 *) actor->actorData)[6] =
                    mlAbsF(func_800138D0(actor->unk58 * 2.0f * 360.0f)) *
                        (actor->unk58 * 2.0f) +
                    1.0f;
            }
            func_80800804_chswampplatform(actor);
            _sumumbofx_entrypoint_14(func_80100094(actor, 1));
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                _chglowbo_entrypoint_6();
                func_80101FDC(actor, 5);
                _sumumbofx_entrypoint_16(func_80100094(actor, 1), 3.0f);
            }
            break;
        case 5:
            func_80800804_chswampplatform(actor);
            _sumumbofx_entrypoint_14(func_80100094(actor, 1));
            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80101FDC(actor, 6);
            }
            break;
        case 6:
            _sumumbofx_entrypoint_1(actor, 1);
            func_800DA524(0x9DE);
            func_800DA544(0x9DF);
            func_8010A800(actor, 0);
            func_800DA544(0x160);
            func_80101FDC(actor, 7);
            break;
        case 7:
            func_80103110(actor, 0);
    }
}

void func_8080061C_chswampplatform(Actor *actor, s32 frame)
{
    Actor *platforms[5];
    s32 count;
    s32 i;
    if (func_800DA298(0x9DE)) {
        if (func_80100094(actor, 1)) {
            count = _subaddiefind_entrypoint_4(0x28E, platforms, 5);
            _sumumbofx_entrypoint_9(func_80100094(actor, 1), frame);
            for (i = 0; i < count; i++) {
                platforms[i]->position[1] = *(f32 *) ((u8 *) platforms[i] + 0x1C) -
                                                func_80103EF4(platforms[i]) * 0.5f;
                if (*(f32 *) ((u8 *) actor + 0x28) != 0.0f &&
                    *(f32 *) ((u8 *) actor + 0x2C) != 0.0f &&
                    *(f32 *) ((u8 *) actor + 0x30) != 0.0f)
                    func_800DF500(*(f32 *) ((u8 *) actor + 0x28),
                                  *(f32 *) ((u8 *) actor + 0x2C),
                                  *(f32 *) ((u8 *) actor + 0x30));
                platforms[i]->scale = actor->scale;
                func_80101870(platforms[i], frame);
            }
            _sumumbofx_entrypoint_8(func_80100094(actor, 1), frame);
        }
    } else {
        actor->position[1] = *(f32 *) ((u8 *) actor + 0x1C) - func_80103EF4(actor) * 0.5f;
        func_80101870(actor, frame);
    }
}

// Message 0x4B with argument 8 starts the spell.
s32 func_808007A4_chswampplatform(Actor *actor, s32 msg, s32 arg)
{
    if (msg == 0x4B) {
        if (arg == 8 && actor->unk70_10 == 0) {
            func_80101FDC(actor, 1);
            func_80103110(actor, 1);
        }
        return 1;
    }
    return 0;
}

// Feeds the mumbofx ribbon with the platform positions.
void func_80800804_chswampplatform(Actor *actor)
{
    Actor *platforms[5];
    f32 base_scale;
    f32 max_scale;
    s32 count;
    s32 step;
    f32 pos[3];
    s32 i;

    base_scale = func_80103EAC(actor);
    max_scale = ((((((f32 *) actor->actorData)[4] > ((f32 *) actor->actorData)[5])
                     ? ((f32 *) actor->actorData)[4]
                     : ((f32 *) actor->actorData)[5]) > ((f32 *) actor->actorData)[6])
                   ? ((((f32 *) actor->actorData)[4] > ((f32 *) actor->actorData)[5])
                          ? ((f32 *) actor->actorData)[4]
                          : ((f32 *) actor->actorData)[5])
                   : ((f32 *) actor->actorData)[6]) *
              base_scale;
    count = _subaddiefind_entrypoint_4(0x28E, platforms, 5);
    step = 50 / count;
    if (((f32 *) actor->actorData)[7] < max_scale) {
        ((f32 *) actor->actorData)[7] = max_scale;
    } else {
        max_scale = ((f32 *) actor->actorData)[7];
    }
    for (i = 0; i < count; i++) {
        func_80103DFC(platforms[i], pos);
        _sumumbofx_entrypoint_7(func_80100094(actor, 1), max_scale, i * step, (i + 1) * step,
                                pos, NULL, NULL);
    }
}

int chswampplatform_entrypoint_0()
{
    return (int) &D_808009F8_chswampplatform;
}

extern void func_80105834();
extern void func_80107C2C();
f32 D_808009D0_chswampplatform[5] = {1.74635e-39f, 9.18534e-40f, 2.059617e-39f, 9.604e-41f,
                                     7.754818e-25f};
f32 D_808009E4_chswampplatform[5] = {1.746351e-39f, 9.18714e-40f, 2.059617e-39f, 9.604e-41f,
                                     7.754818e-25f};
int D_808009F8_chswampplatform[18] = {0x158028E,
                                      0x6E80007,
                                      0x0,
                                      (u32) func_808000BC_chswampplatform,
                                      (u32) func_80105834,
                                      (u32) func_8080061C_chswampplatform,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0xC00,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800000_chswampplatform,
                                      (u32) func_80107C2C,
                                      -0x7FFFDBFE,
                                      (u32) func_808007A4_chswampplatform,
                                      0x0};
