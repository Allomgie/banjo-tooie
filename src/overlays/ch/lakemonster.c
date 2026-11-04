#include "common.h"

extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800DBEFC(void *, s32, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_80101E4C(Actor *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern u8 D_80802108_chlakemonster[];
extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_8080212C_chlakemonster[];
extern u8 D_80802150_chlakemonster[];
extern void func_800BA994();
typedef struct {
    u8 pad_0[0xC];
    f32 local_0[3];
    u8 pad_1[0x26];
    u8 local_1;
    u8 local_2;
} LakeMonsterEffectState;
typedef struct {
    s32 local_0;
    s32 local_1;
} LakeMonsterEffectBones;
extern LakeMonsterEffectBones D_80802174_chlakemonster[];
extern void *func_801039E4(Unk80132ED0 *);
extern u8 *func_800D674C(s32);
extern f32 func_80101F24(Actor *);
extern void func_800E02F8(u8 *, f32, s32, s32, s32, f32 *);
extern void *func_800B2768(void *);
extern void *func_80103CB8(Actor *, void *);
extern void *func_800B2840(void *);
extern void _dbmorph_entrypoint_3(void *, void *, void *, s32, f32 *);
typedef struct {
    u8 pad_0[0x14];
    u32 pad_1 : 31;
    u32 local_0 : 1;
} LakeMonsterMorph;
extern void func_801015D0();
extern f32 func_800D8FF8(void);
extern u8 D_80802030_chlakemonster[];
extern float D_80802044_chlakemonster[];
extern void func_8008F8B0(void);
extern void func_8008F8D8(s32);
extern void func_8008F904(void *, s32);
extern void func_8008F938(s32);
extern void func_8008F964(void *);
extern void func_8008F9C4(void *, f32);
extern f32 D_808020D4_chlakemonster[];
extern void *func_8010D5DC;
typedef struct {
    s32 f0;
    s32 f4;
    u8 pad[0x6C];
    u8 pad74 : 1;
    u8 flag : 1;
    u8 rest : 6;
} FarmerState;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
typedef union {
    s32 local_0;
    s16 local_1[2];
} LakeMonsterEvent;
extern int D_80802204_chlakemonster[];
extern u8 D_8080224C_chlakemonster[];
extern void _chlakemonster_entrypoint_1();
extern s32 func_800DC298(f32);
extern int D_8080229C_chlakemonster[];
extern int D_808022E0_chlakemonster[];
extern int D_80802328_chlakemonster[];
extern u8 D_808020E0_chlakemonster[];
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
typedef struct {
    s32 local_0[5];
} LakeMonsterEventRange;
typedef struct {
    s32 local_0[2];
} LakeMonsterEventPair;
extern s32 D_808021B4_chlakemonster[];
extern s32 D_808021C8_chlakemonster[];
extern s32 D_808021D0_chlakemonster[];
extern s32 D_808021E4_chlakemonster[];
extern s32 D_80802058_chlakemonster[];
extern s32 D_8080207C_chlakemonster[];
typedef struct {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    u8 pad_2C[0x11];
    u8 local_7;
    u8 local_8;
    u8 local_9;
} LakeMonsterLocal;
typedef struct {
    f32 local_0[3];
} LakeMonsterAnimationPoints;
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1828(f32 *, f32 *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_801022E4(Actor *);
extern s32 func_8010CAC0(f32 *, u32);
extern s32 func_8010CB84(f32 *, u32);
extern void func_80101EE4(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern s32 func_8001210C(s32);
extern s32 func_800DC128(s32, s32);
extern s32 func_800C4350(u32, void *, void *);
extern void func_800C31DC(s32, f32);
extern void func_800C3058(s32, s32);
extern void func_800C2FDC(s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern u8 D_808020BC_chlakemonster[];
extern u8 D_808022C8_chlakemonster[];
void func_80801494_chlakemonster();

void func_80800000_chlakemonster(Actor *actor)
{
    func_800EFA4C(actor->position, 0.0f, -3050.0f, 0.0f);
    if (_glcutDll_entrypoint_20()) {
        func_80801494_chlakemonster(actor, 7);
    } else {
        func_80801494_chlakemonster(actor, 1);
    }
}

int func_80800064_chlakemonster(s32 actor)
{
    func_80100074(actor, 0, 0);
    func_800FDC28(0);
}

void func_80800090_chlakemonster(actor, from, to, count) Actor *actor;
s32 from;
s32 to;
s32 count;
{
    s32 emitter;
    f32 value;

    emitter = func_800B53A4(count);
    value = actor->scale;
    func_800BA7C4(emitter, value * 0.02f, value * 0.15f);
    value = actor->scale;
    func_800BA7FC(emitter, value * 0.05f, value * 0.1f);
    value = actor->rotation[1];
    func_800BA994(emitter, -45, (s16) (s32) (value - 25.0f), 25, -25, (s32) (value + 25.0f),
                  75);
    func_800BABB8(emitter, actor->position, 0, 1.0f, D_808020E0_chlakemonster);
    func_800BA1D0(emitter, from, to, count);
}

void func_808001C0_chlakemonster(Actor *actor)
{
    // Matching: unused local needed for the match.
    s32 pad0;
    s32 emitter;
    f32 pos[3];
    u8 *state;
    state = func_80100094(actor, 0);
    emitter = func_800B53A4(2);
    func_800EE7F8(pos, (u8 *) actor + 0x28);
    func_800EF214(pos, *(f32 *) (state + 0x20), *(f32 *) (state + 0x1C) - 30.0f, 150.0f);
    // Matching: `0x20 * 0` is needed for the match.
    func_800BABB8(emitter, pos, 0x20 * 0, 1.0f, D_80802108_chlakemonster);
    func_800BA994(emitter, (s16) (s32) (*(f32 *) (state + 0x20) - 10.0f),
                  (s16) (s32) (*(f32 *) (state + 0x1C) - 10.0f),
                  (s16) (s32) (actor->scale * 150.0f), (s32) (*(f32 *) (state + 0x20) + 10.0f),
                  (s32) (*(f32 *) (state + 0x1C) + 10.0f), (s32) (actor->scale * 300.0f));
    func_800BA22C(emitter, 2);
}

void func_808002FC_chlakemonster(Actor *actor)
{
    s32 emitter;
    f32 *state;

    emitter = func_800B53A4(6);
    state = func_80100094(actor, 0);
    func_800BABB8(emitter, (f32 *) &actor->actorData[4], NULL, 1.0f, D_8080212C_chlakemonster);
    func_800BA994(emitter, (s16) (state[8] - 10.0f), (s16) (state[7] - 10.0f),
                  (s16) (actor->scale * 100.0f), (s32) (state[8] + 10.0f),
                  (s32) (state[7] + 10.0f), (s32) (actor->scale * 200.0f));
    func_800BA22C(emitter, 6);
}

void func_80800404_chlakemonster(Actor *actor)
{
    Vec3f pos;
    s32 emitter;
    f32 *state;
    emitter = func_800B53A4(3);
    state = func_80100094(actor, 0);
    func_800DBEFC(actor->unk0->unk4, 0xC, pos.f);
    func_800BABB8(emitter, pos.f, 0, 1.0f, D_80802150_chlakemonster);
    func_800BA994(emitter, (s16) (state[8] - 5.0f - 15.0f), (s16) (state[7] - 5.0f - 25.0f),
                  (s16) (actor->scale * 50.0f), (s32) (state[8] + 5.0f - 15.0f),
                  (s32) (state[7] + 5.0f - 25.0f), (s32) (actor->scale * 100.0f));
    func_800BA22C(emitter, 3);
    emitter = func_800B53A4(3);
    func_800DBEFC(actor->unk0->unk4, 0xD, pos.f);
    func_800BABB8(emitter, pos.f, 0, 1.0f, D_80802150_chlakemonster);
    func_800BA994(emitter, (s16) (state[8] - 5.0f - 15.0f), (s16) (state[7] - 5.0f + 25.0f),
                  (s16) (actor->scale * 50.0f), (s32) (state[8] + 5.0f - 15.0f),
                  (s32) (state[7] + 5.0f + 25.0f), (s32) (actor->scale * 100.0f));
    func_800BA22C(emitter, 3);
}

void func_8080064C_chlakemonster(Actor *actor)
{
    LakeMonsterEffectState *state;
    f32 start[3];
    f32 end[3];
    s32 index;

    state = func_80100094(actor, 0);
    index = func_800DC128(4, 7);
    func_800DBEFC(actor->unk0->unk4, D_80802174_chlakemonster[index].local_0, start);
    func_800DBEFC(actor->unk0->unk4, D_80802174_chlakemonster[index].local_1, end);
    if (state->local_2) {
        func_800EF04C(start, state->local_0);
        func_800EF04C(end, state->local_0);
    }
    func_80800090_chlakemonster(actor, start, end, func_800DC128(1, 3) + state->local_1);
}

void func_80800724_chlakemonster(Actor *actor)
{
    void *base;
    s16 text_id;
    u8 *state;

    base = func_801039E4(actor->unk0);
    text_id = 0;
    state = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 2:
            text_id = 0x1F2;
            break;
        case 3:
            text_id = 0x1F3;
            break;
        case 4:
            text_id = 0x1F4;
            break;
    }
    if (text_id) {
        func_800E02F8(func_800D674C(text_id), func_80101F24(actor), 0, 0x2A, 0x2D,
                      (f32 *) (state + 0x2C));
    }
    _dbmorph_entrypoint_3(func_800B2768(base), func_80103CB8(actor, base),
                          func_800B2840(base), 1, (f32 *) (state + 0x2C));
}

void func_80800838_chlakemonster(Actor *actor)
{
    void *base;
    void *unk_0;
    LakeMonsterMorph *morph;
    void *unk_1;

    base = func_801039E4(actor->unk0);
    unk_0 = func_800B2768(base);
    morph = func_80103CB8(actor, base);
    unk_1 = func_800B2840(base);
    func_80800724_chlakemonster(actor);
    func_801015D0(actor);
    morph->local_0 = 1;
    if (func_800AE0E8(*(s16 *) &actor->unk0->unk10)) {
        _dbmorph_entrypoint_4(unk_0, morph, unk_1, 1,
                              func_800AE080(*(s16 *) &actor->unk0->unk10));
    }
}

void func_808008E8_chlakemonster(Actor *actor)
{
    f32 *state;
    state = func_80100094(actor, 0);
    if (state[9] <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(actor, (f32 *) actor->actorData + 4,
                                         D_80802030_chlakemonster);
        state[9] = 2.5f;
    } else {
        state[9] -= func_800D8FF8();
    }
}

void func_80800968_chlakemonster(s32 actor)
{
    u8 *state;

    state = func_80100094(actor, 0);
    if (*(f32 *) ((s8 *) state + 0x28) <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(actor, actor + 0x28, &D_80802044_chlakemonster);
        *(f32 *) ((s8 *) state + 0x28) = 1.5f;
    }
}

// Swallows the player and warps into Chompa's belly.
s32 func_808009CC_chlakemonster(void)
{
    func_800F7C9C(func_800F54E4(), 0x95, 0x116, 0xA);
    _gcgoto_entrypoint_1(0x123, 1);
    func_800DA544(0x6E8);
}

void func_80800A14_chlakemonster(Actor *actor, s32 param_1, s32 do_effect)
{
    extern void func_80018820(s32, f32, f32);
    u8 *state;
    LakeMonsterEventRange range_0;
    LakeMonsterEventPair pair_0;
    LakeMonsterEventRange range_1;
    LakeMonsterEventPair pair_1;
    f32 anim_time;
    state = (u8 *) func_80100094(actor, 0);
    if (do_effect) {
        func_8080064C_chlakemonster(actor);
    }
    if (actor->unk7C_12) {
        range_0 = *(LakeMonsterEventRange *) D_808021B4_chlakemonster;
        pair_0 = *(LakeMonsterEventPair *) D_808021C8_chlakemonster;
        range_1 = *(LakeMonsterEventRange *) D_808021D0_chlakemonster;
        pair_1 = *(LakeMonsterEventPair *) D_808021E4_chlakemonster;
        anim_time = func_80101F24(actor);
        if (func_80101E4C(actor, &range_1)) {
            _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 0x28,
                                             D_80802058_chlakemonster);
            *(f32 *) (state + 0x18) = 0.85f;
        } else if (func_80101E4C(actor, &pair_0)) {
            func_808008E8_chlakemonster(actor);
            func_808001C0_chlakemonster(actor);
        } else if (func_80101E4C(actor, &range_0)) {
            func_80800968_chlakemonster(actor);
        } else if (!func_80101E4C(actor, &pair_1)) {
            if (func_80101E14(actor, 0.965f)) {
                _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 0x28,
                                                 D_8080207C_chlakemonster);
                func_80018820(0, 2.0f, 0.25f);
                if (param_1) {
                    func_80101180(0x501, 0xBC, 0);
                } else {
                    state[0x3D] = 1;
                    func_8009086C(0);
                }
            } else if (func_80101DDC(actor) && param_1 == 0) {
                func_808009CC_chlakemonster();
            }
        }
        if (anim_time > 0.24f && anim_time < 0.31f && func_8001210C(0xF)) {
            func_808001C0_chlakemonster(actor);
        }
    }
}

void func_80800C88_chlakemonster(Actor *actor)
{
    extern f32 D_808021EC_chlakemonster[];
    extern u8 D_808021F8_chlakemonster[];
    extern u8 D_8080208C_chlakemonster[];
    extern u8 D_808020A4_chlakemonster[];

    LakeMonsterLocal *state;
    s32 splash;

    state = func_80100094(actor, 0);
    splash = 0;

    if (state != 0) {
        if (actor->unk7C_12) {
            f32 vec_a[3];
            f32 vec_b[3];
            f32 vec_c[3];
            f32 vec_d[3];
            func_800DBEFC(actor->unk0->unk4, 8, vec_a);

            func_800DBEFC(actor->unk0->unk4, 0xB, vec_b);

            if (func_800EEB40(vec_a, vec_b) > 12000.0f) {
                if (state->local_8 == 0) {
                    state->local_8 = 10;
                }

                splash = 1;
            }

            func_800DBEFC(actor->unk0->unk4, 5, (f32 *) &actor->actorData[4]);

            func_800DBEFC(actor->unk0->unk4, 4, vec_c);

            func_800EF04C((f32 *) &actor->actorData[4], vec_c);

            func_800EF334((f32 *) &actor->actorData[4], 0.5f);

            if (state->local_9 != 0) {
                func_800EFB24(state->local_1, (f32 *) &actor->actorData[4], state->local_0);

                func_800EE7F8(state->local_0, (f32 *) &actor->actorData[4]);

                func_800EF334(state->local_1, 2.0f);

                func_800EF04C((f32 *) &actor->actorData[4], state->local_1);
            } else {
                func_800EE7F8(state->local_0, (f32 *) &actor->actorData[4]);

                state->local_9 = 1;
            }

            func_800DBEFC(actor->unk0->unk4, 0xB, vec_c);

            func_800DBEFC(actor->unk0->unk4, 8, vec_d);

            func_800EF04C(vec_c, vec_d);
            func_800EF334(vec_c, 0.5f);

            state->local_3 = func_800F1DF4((f32 *) &actor->actorData[4], vec_c);

            state->local_4 = -func_800F1828((f32 *) &actor->actorData[4], vec_c);
        }

        if (state->local_8 > 0) {
            state->local_8--;
        }
    }

    switch (actor->unk70_10) {
        case 1: {
            s32 next_state;
            s32 is_ready;
            s32 has_ability;
            if (func_8010CAC0(D_808020D4_chlakemonster, 0xBE)) {
                if (func_80090248()) {
                    next_state = 6;

                    is_ready = func_8008FD70() == 1;
                    has_ability = func_800C6E38(0x15);
                    if (is_ready && has_ability) {
                        if (!func_800DA298(0x1B9)) {
                            _chintrotext_entrypoint_1(0x18B9, 2, 1, 0);

                            func_800DA544(0x1B9);
                            next_state = 2;
                        } else {
                            next_state = 4;
                        }
                    }

                    func_80801494_chlakemonster(actor, next_state);
                }
            }
            break;
        }
        case 2:
            if (func_80090298()) {
                func_80090840((f32 *) &actor->actorData[4]);
            }

            func_80800A14_chlakemonster(actor, 0, splash);

            if (actor->unk7C_12 && state->local_7 != 0) {
                func_800907C0((f32 *) &actor->actorData[4]);
            }
            break;

        case 3: {
            LakeMonsterAnimationPoints points;
            f32 offset[3];

            points = *(LakeMonsterAnimationPoints *) D_808021EC_chlakemonster;

            if (splash != 0) {
                func_8080064C_chlakemonster(actor);
            }

            if (func_80101E14(actor, 0.4f)) {
                func_808008E8_chlakemonster(actor);
                func_808001C0_chlakemonster(actor);
            } else if (func_80101E4C(actor, points.local_0)) {
                func_80800968_chlakemonster(actor);
                func_808001C0_chlakemonster(actor);
            }

            if (func_80101DDC(actor)) {
                func_80801494_chlakemonster(actor, 5);
            }

            if (actor->unk7C_12 && state->local_7 != 0) {
                func_800EE7F8(offset, (f32 *) &actor->actorData[4]);

                offset[1] -= 275.0f;

                func_800906B0(offset);

                if (func_80101E14(actor, 0.4f)) {
                    func_80090708(0);
                    func_80090590(0x2F, D_808021F8_chlakemonster);
                    func_8009086C(1);

                    state->local_7 = 0;
                }
            }
            break;
        }
        case 4:
            if (func_80090298()) {
                func_80090840((f32 *) &actor->actorData[4]);
            }

            if (splash != 0) {
                func_8080064C_chlakemonster(actor);
            }

            if (func_80101E14(actor, 0.07f)) {
                func_80800968_chlakemonster(actor);
            } else if (func_80101E14(actor, 0.8f)) {
                _subaddieaudioquick_entrypoint_2(actor, (f32 *) &actor->actorData[4],
                                                 D_8080207C_chlakemonster);

                state->local_7 = 1;

                func_8009086C(0);
            } else if (func_80101E14(actor, 0.7f)) {
                func_808008E8_chlakemonster(actor);
            } else if (func_80101DDC(actor)) {
                func_808009CC_chlakemonster();
            }

            if (actor->unk7C_12 && state->local_7 != 0) {
                func_800907C0((f32 *) &actor->actorData[4]);
            }
            break;

        case 5:
            if (!func_8010CB84(D_808020D4_chlakemonster, 0xC8)) {
                func_80801494_chlakemonster(actor, 1);
            }

            break;

        case 7:
            func_80800A14_chlakemonster(actor, 1, splash);
    }

    if (state != 0) {
        if (state->local_5 > 0.0f) {
            state->local_5 -= func_800D8FF8();
        }

        if (state->local_6 > 0.0f) {
            state->local_6 -= func_800D8FF8();
        }

        if (actor->unk7C_12) {
            f32 dt;
            f32 anim_time;
            s32 play_step;

            dt = func_800D8FF8();
            anim_time = func_80101F24(actor);

            if (state->local_5 <= 0.0f && state->local_6 <= 0.0f) {
                play_step = 0;

                switch (func_801022E4(actor)) {
                    case 0x169:
                        if (anim_time < 0.61f || anim_time > 0.77f) {
                            play_step = 1;
                        }
                        break;

                    case 0x1FD:
                    case 0x1FE:
                        play_step = 1;
                }

                if (play_step != 0) {
                    if (state->local_2 > 0.0f) {
                        state->local_2 -= dt;
                    } else {
                        state->local_2 = 2.5f;

                        if (actor->unk64_19) {
                            _subaddieaudioquick_entrypoint_2(
                                actor, (f32 *) &actor->actorData[4], D_8080208C_chlakemonster);

                            if (splash != 0) {
                                func_808002FC_chlakemonster(actor);
                            } else {
                                func_80800404_chlakemonster(actor);
                            }

                            actor->unk64_19 = 0;
                        } else {
                            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                             D_808020A4_chlakemonster);

                            actor->unk64_19 = 1;
                        }
                    }
                }
            }
        }
    }
}

void func_808013E8_chlakemonster(s32 data[3])
{
    func_8008F8B0();
    func_8008F964(&D_808020D4_chlakemonster);
    func_8008F8D8(0);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, data[0]);
    func_8008F9C4(&D_808020D4_chlakemonster, 0.75f);
}

void func_80801448_chlakemonster(FarmerState *dialog, s32 text_id, s32 flags)
{
    flags |= 7;
    _subaddiedialog_entrypoint_11(dialog->f0, text_id, flags, &dialog->f4, 0xb3);
    dialog->flag = 1;
}

void func_80801494_chlakemonster(actor, state) Actor *actor;
s32 state;
{
    void *data;
    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            func_80100074(actor, 0, 0x40);
            data = func_80100094(actor, 0);
            *(u8 *) ((char *) data + 0x3C) = 0;
            *(u8 *) ((char *) data + 0x3D) = 0;
            *(u8 *) ((char *) data + 0x3E) = 0;
            *(float *) ((char *) data + 0x18) = 0.0f;
            func_80090658(1);
            actor->unk64_16 = 1;
            break;

        case 2:
            func_800FDC28(0);
    }

    func_80102424(actor, state);
    switch (state) {
        case 7:
            func_80101EE4(actor, 0.35f);
            return;

        case 1:
            actor->unk64_16 = 0;
            func_80090658(0);
            func_80100074(actor, 0, 0);
            return;

        case 2:
            func_808013E8_chlakemonster(actor);
            func_800FDC28(1);
            _capod_entrypoint_13(actor->unk0, 0, 6, 0x20);
            return;

        case 3:
            _capod_entrypoint_13(actor->unk0, 0, 8, 0x10);
            func_800F7B9C(func_800F54E4(), 0x96);
            *(u8 *) ((char *) data + 0x3D) = 1;
            func_8009086C(0);
            func_80090658(0);
            func_80090708(2);
            return;

        case 4:
            func_808013E8_chlakemonster(actor);
            _capod_entrypoint_13(actor->unk0, 0, 0xa, 0x20);
            return;

        case 5:
            actor->unk64_16 = 0;
            return;

        case 6:
            func_80090658(0);
            actor->unk64_16 = 0;
            if (func_800C6E38(0x15) == 0) {
                func_80801448_chlakemonster(actor, 0x1819, 0);
                return;
            }
            func_80801448_chlakemonster(actor, 0x180E, 0);

        case 0:
            return;
    }
}

s32 func_808016B0_chlakemonster(Actor *actor, s32 event_id, LakeMonsterEvent event_data)
{
    switch (event_id) {
        case 0x32:
            func_80090708(2);
            break;
        case 0x2E:
            actor->unk74_30 = 0;
            if (event_data.local_1[0] == 0x180E)
                func_80801494_chlakemonster(actor, 5);
            break;
        case 0x49:
            if (func_800DA9E4(0x6E8, 0))
                func_80801494_chlakemonster(actor, 3);
            break;
        case 0x1F:
            func_80800838_chlakemonster(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

int chlakemonster_entrypoint_0()
{
    return &D_80802204_chlakemonster;
}

void func_80801790_chlakemonster(Actor *actor, s32 new_state)
{
    s32 *raw = (s32 *) actor;
    u32 cur_state;

    func_80101FDC(actor, new_state);
    cur_state = (u32) (u16) *(u16 *) ((char *) raw + 0x72) >> 0xA;
    switch (cur_state) {
        case 1:
            *(f32 *) ((char *) raw + 0x8) = -1000.0f;
            return;
        case 3:
            *(u8 *) ((char *) raw + 0x7E) = (u8) (*(u8 *) ((char *) raw + 0x7E) & 0xFFBF);
            *(f32 *) ((char *) raw + 0x8) = 0.0f;
            return;
        case 2:
            _capod_entrypoint_13(*(Actor **) ((char *) raw + 0x0), 0, 0, 0x10);
            *(f32 *) ((char *) raw + 0x34) = 0.0f;
            *(f32 *) ((char *) raw + 0x50) = 50.0f;
    }
}

void func_80801834_chlakemonster(Actor *actor)
{
    func_800EE7F8((f32 *) actor->actorData, actor->position);
    func_800EFA4C(actor->position, 0.0f, 0.0f, 0.0f);
    if (func_800DA298(0x187)) {
        func_80801790_chlakemonster(actor, 3);
    } else {
        func_80801790_chlakemonster(actor, 1);
    }
}

void func_808018AC_chlakemonster(s32 arg0)
{
}

s32 chlakemonster_entrypoint_1(s32 param_0)
{
    _fxripple_entrypoint_0(0);
}

void chlakemonster_entrypoint_2(f32 *from, f32 *to, f32 param_2, f32 param_3)
{
    s32 emitter;

    emitter = func_800B53A4(6);
    func_800BA568(emitter, (s16) param_3);
    func_800BA544(emitter, _chlakemonster_entrypoint_1);
    if (func_800DC298(0.5f)) {
        to[0] -= 100.0f;
        from[0] -= 100.0f;
    } else {
        to[0] += 100.0f;
        from[0] += 100.0f;
    }
    func_800BABB8(emitter, to, NULL, 1.0f, D_8080224C_chlakemonster);
    func_800BA1D0(emitter, from, to, 6);
}

void chlakemonster_entrypoint_3(f32 *from, f32 *to, f32 param_2, f32 param_3)
{
    // Matching: extra temporary needed for the match.
    s32 emitter_saved;
    s32 emitter;

    emitter = func_800B53A4(3);
    emitter_saved = emitter;
    *(f32 *) ((s8 *) to + 4) = (f32) (*(f32 *) ((s8 *) to + 4) + 200.0f);
    *(f32 *) ((s8 *) from + 4) = (f32) (*(f32 *) ((s8 *) from + 4) + 200.0f);
    func_800BABB8(emitter, to, 0, 1.0f, &D_8080229C_chlakemonster);
    func_800BA1D0(emitter_saved, from, to, 3);
}

void func_80801A60_chlakemonster(Actor *actor)
{
    f32 pos_a[3];
    f32 pos_b[3];

    switch (actor->unk70_10) {
        case 1:
            return;
        case 2:
            if (actor->position[1] >= 0.0f) {
                func_80801790_chlakemonster((u8 *) actor, 3);
                return;
            }
            actor->position[1] = func_800D8FF8() * actor->unk50 + actor->position[1];
            actor->unk50 = actor->unk50 + 5.0f;
            if (func_8001210C(1)) {
                pos_a[1] = actor->position[1] + -3050.0f;
                pos_b[1] = pos_a[1];
                switch (func_800DC128(0, 3)) {
                    case 0:
                        pos_a[0] = 30.0f;
                        pos_a[2] = 735.0f;
                        pos_b[0] = 504.0f;
                        pos_b[2] = 1423.0f;
                        chlakemonster_entrypoint_2(pos_a, pos_b, 50.0f, -3050.0f);
                        chlakemonster_entrypoint_3(pos_a, pos_b, 50.0f, -3050.0f);
                        break;
                    case 1:
                        pos_b[0] = 504.0f;
                        pos_b[2] = 1423.0f;
                        pos_a[0] = -194.0f;
                        pos_a[2] = 2263.0f;
                        chlakemonster_entrypoint_2(pos_a, pos_b, 50.0f, -3050.0f);
                        chlakemonster_entrypoint_3(pos_a, pos_b, 50.0f, -3050.0f);
                        break;
                    case 2:
                        pos_a[0] = -194.0f;
                        pos_a[2] = 2263.0f;
                        pos_b[0] = 4.0f;
                        pos_b[2] = 3081.0f;
                        chlakemonster_entrypoint_2(pos_a, pos_b, 50.0f, -3050.0f);
                        chlakemonster_entrypoint_3(pos_a, pos_b, 50.0f, -3050.0f);
                }
                if (actor->unk58 <= 0.0f) {
                    _subaddieaudioquick_entrypoint_2(actor, pos_b, D_808020BC_chlakemonster);
                    actor->unk58 = func_800DC178(1.0f, 2.0f) * 0.15f;
                } else {
                    actor->unk58 = actor->unk58 - func_800D8FF8();
                }
            }
            if (actor->unk5F == 0) {
                actor->unk5F = func_800C4350(0, actor->position, D_808022C8_chlakemonster);
                return;
            }
            if (actor->position[1] < -750.0f) {
                *(f32 *) &actor->actorData[7] =
                    func_800F10B4(actor->position[1], -1000.0f, -850.0f, 0.0f, 32000.0f);
            }
            actor->unk54 = func_800F10B4(actor->position[1], -1000.0f, 0.0f, 0.05f, 1.0f);
            func_800C3058(actor->unk5F, (s32) *(f32 *) &actor->actorData[7]);
            func_800C31DC(actor->unk5F, actor->unk54);
            func_800C4350(actor->unk5F, (u8 *) actor->actorData, 0);
            return;
        case 3:
            if (actor->unk5F == 0) {
                return;
            }
            if (*(f32 *) &actor->actorData[7] > 500.0f) {
                *(f32 *) &actor->actorData[7] = *(f32 *) &actor->actorData[7] * 0.7f;
                if (0.05f < actor->unk54) {
                    actor->unk54 = actor->unk54 * 0.7f;
                }
                func_800C3058(actor->unk5F, (s32) *(f32 *) &actor->actorData[7]);
                func_800C31DC(actor->unk5F, actor->unk54);
                func_800C4350(actor->unk5F, (u8 *) actor->actorData, 0);
                return;
            }
            func_800C2FDC(actor->unk5F);
            actor->unk5F = 0;
    }
}

s32 func_80801E60_chlakemonster(Actor *actor, s32 event_id, s32 param_2)
{
    // Matching: extra temporary needed for the match.
    Actor *actor_copy;
    if (event_id == 0x7) {
        actor_copy = actor;
        func_80801790_chlakemonster(actor_copy, 2);
    } else {
        return 0;
    }
    return 1;
}

int chlakemonster_entrypoint_4()
{
    return (int) &D_808022E0_chlakemonster;
}

s32 func_80801EA8_chlakemonster(s32 actor)
{
    _chswitch_entrypoint_14(actor, 0x187);
    if (func_800DA298(0x187))
        func_8010A570(actor);
}

void func_80801EE4_chlakemonster(s32 arg0)
{
}

s32 func_80801EEC_chlakemonster(s32 actor, s32 event_id, s32 param_2)
{
    // Matching: extra temporary needed for the match.
    int result;
    if (event_id == 7) {
        func_80101180(0x301, 7, 0);
        result = 1;
        func_8010A570(actor);
        goto func_80801EEC_chlakemonster_end;
    }
    return 0;
func_80801EEC_chlakemonster_end:
    return result;
}

int chlakemonster_entrypoint_5()
{
    return &D_80802328_chlakemonster;
}

// TU-NOTE: the overlay .data is defined here in C. Tables holding function pointers must be
// in the same unit, otherwise IDO's assembler schedules those functions differently.
// The externs of D_80802044_chlakemonster, D_80802204_chlakemonster, D_808022E0_chlakemonster and
// D_80802328_chlakemonster are adjusted to the object type (address-neutral).
extern void func_80105834();
extern void func_801018A4();
extern void func_80107C2C();
extern void func_80101870();
extern void _chswitch_entrypoint_13();
extern void _chswitch_entrypoint_0();
u32 D_80801FF0_chlakemonster[16] = {
    0x0,        0x0,       0x424C0000, 0x1690044, 0x41880000, 0x1690042, 0x40F66666, 0x1FD0042,
    0x4019999A, 0x1FE0042, 0x40F66666, 0x1FD0084, 0x424C0000, 0x1690044, 0x41880000, 0x1690002};
u8 D_80802030_chlakemonster[20] = {0x0, 0x13, 0x5, 0x4F, 0x0, 0xD,  0x0,  0xF3, 0x1, 0x0,
                                   0x0, 0x18, 0x0, 0x1,  0x9, 0xC4, 0x13, 0x88, 0x0, 0x0};
float D_80802044_chlakemonster[5] = {1.746777e-39f, 1.194202e-39f, 2.3509954e-38f, 9.5339e-41f,
                                     3.4331227e-27f};
s32 D_80802058_chlakemonster[9] = {0x130551, 0xD00CC,  0xE60018,  0x109C4, 0x13880000,
                                   0x1304EF, 0x180001, 0x9C41388, 0x0};
s32 D_8080207C_chlakemonster[4] = {0x130554, 0x180001, 0x9C41388, 0x0};
u8 D_8080208C_chlakemonster[24] = {0x0, 0x13, 0x5,  0x50, 0x0,  0xD,  0x0, 0xD9,
                                   0x0, 0xF3, 0x0,  0x16, 0x3E, 0x80, 0x0, 0x1,
                                   0x9, 0xC4, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
u8 D_808020A4_chlakemonster[24] = {0x0, 0x13, 0x5,  0x50, 0x0,  0xD,  0x1, 0xF,
                                   0x1, 0x28, 0x0,  0x16, 0x3E, 0x80, 0x0, 0x1,
                                   0x9, 0xC4, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
u8 D_808020BC_chlakemonster[24] = {0x0, 0x13, 0x3,  0xED, 0x0,  0xD,  0x0, 0x66,
                                   0x0, 0x80, 0x0,  0x16, 0x2E, 0xE0, 0x0, 0x1,
                                   0x9, 0xC4, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
f32 D_808020D4_chlakemonster[3] = {0.0f, -1.9e+03f, 0.0f};
u8 D_808020E0_chlakemonster[40] = {0x0, 0x1D, 0x9,  0xF3, 0x0,  0x20, 0xFF, 0xFF, 0xFE, 0xB4,
                                   0x0, 0x1B, 0xF2, 0x54, 0xF2, 0x54, 0x0,  0x7,  0x0,  0x1,
                                   0x0, 0x15, 0x0,  0x0,  0x0,  0xCC, 0x0,  0x2B, 0x0,  0x80,
                                   0x1, 0x0,  0x0,  0x16, 0x10, 0x0,  0x0,  0x0,  0x0,  0x0};
u8 D_80802108_chlakemonster[36] = {0x0,  0x1D, 0x9,  0xDD, 0x0,  0x16, 0x2,  0x0,  0x80,
                                   0x2,  0x0,  0x22, 0x0,  0x80, 0x0,  0x80, 0x5,  0x80,
                                   0x7,  0x80, 0x0,  0x15, 0x0,  0x33, 0x0,  0x80, 0x0,
                                   0x2B, 0x0,  0x19, 0x0,  0x40, 0x0,  0x0,  0x0,  0x0};
u8 D_8080212C_chlakemonster[36] = {0x0,  0x1D, 0x9,  0xDD, 0x0, 0x16, 0x2, 0x0,  0x80,
                                   0x2,  0x0,  0x22, 0x0,  0x0, 0x0,  0x0, 0x1,  0xCC,
                                   0x2,  0x80, 0x0,  0x15, 0x0, 0x0,  0x0, 0x80, 0x0,
                                   0x2B, 0x1,  0x99, 0x2,  0x0, 0x0,  0x0, 0x0,  0x0};
u8 D_80802150_chlakemonster[36] = {0x0,  0x1D, 0x9,  0xDD, 0x0, 0x16, 0x2, 0x0,  0x80,
                                   0x2,  0x0,  0x22, 0x0,  0x0, 0x0,  0x0, 0x0,  0xCC,
                                   0x1,  0x80, 0x0,  0x15, 0x0, 0x0,  0x0, 0x4C, 0x0,
                                   0x2B, 0x1,  0x99, 0x2,  0x0, 0x0,  0x0, 0x0,  0x0};
LakeMonsterEffectBones D_80802174_chlakemonster[8] = {0x4, 0x9, 0x9, 0xB, 0xB, 0xA, 0xA, 0x5,
                                                      0x5, 0x7, 0x7, 0x8, 0x8, 0x6, 0x6, 0x4};
s32 D_808021B4_chlakemonster[5] = {0x3D71A9FC, 0x3ED1EB85, 0x3F47AE14, 0x3F70A3D7, -0x40800000};
s32 D_808021C8_chlakemonster[2] = {0x3E75C28F, -0x40800000};
s32 D_808021D0_chlakemonster[5] = {0x3F1C28F6, 0x3F2B851F, 0x3F326E98, 0x3F400000, -0x40800000};
s32 D_808021E4_chlakemonster[2] = {0x3CBC6A7F, -0x40800000};
f32 D_808021EC_chlakemonster[3] = {0.55f, 0.75f, -1.0f};
u8 D_808021F8_chlakemonster[12] = {0x0, 0x0, 0x0, 0x0, 0xC4, 0xED, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0};
int D_80802204_chlakemonster[18] = {0x2E50300,
                                    0x6D50001,
                                    (u32) &D_80801FF0_chlakemonster,
                                    (u32) func_80800C88_chlakemonster,
                                    (u32) func_80105834,
                                    (u32) func_801018A4,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x8046C,
                                    (u32) func_80800064_chlakemonster,
                                    0x0,
                                    0x0,
                                    (u32) func_80800000_chlakemonster,
                                    (u32) func_80107C2C,
                                    -0x7F7FFFFE,
                                    (u32) func_808016B0_chlakemonster,
                                    0x0};
u8 D_8080224C_chlakemonster[80] = {
    0x0,  0x1D, 0x9, 0xD9, 0x0,  0x16, 0x0, 0x4,  0x0, 0x1B, 0x0,  0x96, 0x0,  0x96, 0x0, 0x7,
    0x0,  0x1,  0x0, 0x15, 0x0,  0x0,  0x0, 0xCC, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0, 0x2F,
    0x0,  0x40, 0x0, 0x40, 0x0,  0x0,  0x0, 0x0,  0x0, 0x19, 0x0,  0x0,  0x0,  0x33, 0x0, 0x2B,
    0x0,  0x80, 0x0, 0xC0, 0x0,  0x22, 0x0, 0xC,  0x0, 0x19, 0x0,  0x26, 0x0,  0x59, 0x0, 0x2C,
    0xFF, 0xD8, 0x1, 0x90, 0xFF, 0xD8, 0x0, 0x28, 0x1, 0xF4, 0x0,  0x28, 0x0,  0x0,  0x0, 0x0};
int D_8080229C_chlakemonster[11] = {0x1D09DD, 0x2A0000,  0x190180, 0x1800015, 0x3300B3, 0x160200,
                                    0x20C4C4, -0x9FFFDE, 0x8000C0, 0x1800280, 0x0};
u8 D_808022C8_chlakemonster[24] = {0x2, 0x6, 0x0, 0x13, 0x3, 0xEC, 0x0,  0xA,  0x0, 0x25, 0x0, 0x16,
                                   0x0, 0x0, 0x0, 0x1,  0x9, 0xC4, 0x13, 0x88, 0x0, 0x0,  0x0, 0x0};
int D_808022E0_chlakemonster[18] = {0x2E60301,
                                    0x74B0001,
                                    0x0,
                                    (u32) func_80801A60_chlakemonster,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x17700000,
                                    0x0,
                                    0x0,
                                    0xC00,
                                    (u32) func_808018AC_chlakemonster,
                                    0x0,
                                    0x0,
                                    (u32) func_80801834_chlakemonster,
                                    (u32) func_80107C2C,
                                    -0x7FF7FBFE,
                                    (u32) func_80801E60_chlakemonster,
                                    0x0};
int D_80802328_chlakemonster[18] = {0x2E70370,
                                    0x94B0001,
                                    -0x7FEE5D68,
                                    (u32) _chswitch_entrypoint_13,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x808,
                                    (u32) func_80801EE4_chlakemonster,
                                    (u32) _chswitch_entrypoint_0,
                                    0x0,
                                    (u32) func_80801EA8_chlakemonster,
                                    (u32) func_80107C2C,
                                    -0x7FF7F400,
                                    (u32) func_80801EEC_chlakemonster,
                                    0x0};
