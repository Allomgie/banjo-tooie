#include "common.h"

extern void _subaddielink_entrypoint_0(void *);
extern s32 _subaddiefind_entrypoint_4(s32, Actor **, s32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int func_800D0B68(int, int);
extern void *func_80100094(Actor *, u32);
extern int _subaddielink_entrypoint_4(void *);
extern void func_8010C964(void *);
extern int D_80801F28_chfantasyeyeball[];
extern void func_800BA3FC();
extern void func_800EFDE8();
extern f32 func_800D8FF8(void);
extern s32 func_800D91EC(f32 *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800BF340(f32 *, f32 *, f32 *, s32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_80801F70_chfantasyeyeball[];
extern u8 D_80801FB0_chfantasyeyeball[];
extern Actor *func_80106790();
extern f32 func_800DC178(f32, f32);
typedef union {
    Unk80132ED0 *local_0;
    s32 local_1;
} FantasyEyeEvent39;
extern u8 D_80801FC0_chfantasyeyeball[];
extern int D_80802008_chfantasyeyeball[];
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 29;
    u32 unk_78 : 1;
    u32 pad_2 : 2;
} EyeballFlags561;
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800D90A4(f32 *);
extern void _subaddiefade_entrypoint_1(s32, s32);
extern void func_8010C93C(Actor *, f32 *, f32);
extern s32 D_80801E98_chfantasyeyeball[];
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_8010D12C(s32, f32 *, f32, s32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_800DC0C0(void);
extern f32 func_800136E4(f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern int func_800E0AF0(s32, f32);
extern int func_800E0AFC(s32, s32, f32, f32, f32, f32);
extern int func_800E0B8C(s32, s32, f32, f32, f32, f32);
extern int func_8010C754(Actor *);
void func_80801740_chfantasyeyeball();
void func_80801BC4_chfantasyeyeball();
void func_80800950_chfantasyeyeball();
void func_808010B0_chfantasyeyeball();
void func_80801290_chfantasyeyeball(Actor *param_0, f32 param_1, s32 param_2);
void func_808013F8_chfantasyeyeball();
s32 func_808017B4_chfantasyeyeball();

void func_80800000_chfantasyeyeball(Actor *actor)
{
    if (func_800D0B68(0x4C, 1)) {
        func_800FFAB0(actor);
        return;
    }
    if (!(actor->unk74_7 - 0x32) && !func_800D0B68(0x4C, 1)) {
        actor->unk64_20 = 1;
    } else {
        actor->unk64_20 = 0;
    }
    func_808010B0_chfantasyeyeball(actor, (f32 *) &actor->actorData[2],
                                   (f32 *) &actor->actorData[4]);
    func_808010B0_chfantasyeyeball(actor, (f32 *) &actor->actorData[0],
                                   (f32 *) &actor->actorData[1]);
    actor->unk64_19 = 0;
    _subaddielink_entrypoint_0(func_80100094(actor, 0));
    *(f32 *) &actor->actorData[6] = 0.0f;
}

void func_80801378_chfantasyeyeball();

void func_80801314_chfantasyeyeball();

void func_808011D0_chfantasyeyeball(Actor *param_0, f32 param_1, f32 param_2, f32 param_3);

// Eyeball plant: per-frame state machine.
void func_808000D8_chfantasyeyeball(Actor *actor)
{
    extern u8 D_80801EEC_chfantasyeyeball[];

    f32 eye_pos[3];
    s32 i;
    s32 particle;
    s32 result;
    s32 link;
    f32 blend;
    s32 next_state;
    u16 sfx_pitch;

    _sudeflect_entrypoint_0((char *) actor + 4, *(f32 *) ((char *) actor + 0x38) * 456.0f,
                            *(f32 *) ((char *) actor + 0x38) * 224.0f, 0xE);

    if (((EyeballFlags561 *) actor)->unk_78) {
        return;
    }

    switch (actor->unk70_10) {
        case 1:
            if (func_8010C9B0((char *) actor + 4, 0x1388) && func_800F6720(func_800F54E4())) {
                func_80800950_chfantasyeyeball(actor, 2);
            }
            break;

        case 2:
            if (func_80101DDC(actor)) {
                func_80800950_chfantasyeyeball(actor, 3);
            }

            if (!func_800DA298(0x6EC)) {
                func_800D90A4((char *) actor + 0x58);

                blend = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 2.707999945f, 0.0f,
                                        1.0f, 0.0f);

                func_808011D0_chfantasyeyeball(actor, *(f32 *) ((char *) actor + 0x20),
                                               *(f32 *) ((char *) actor + 0x28), blend);
            }

            if (func_80101E14(actor, 0.4f)) {
                func_800C4140(0x8CBB5C1E, (char *) actor + 4, 0x1B5801F4);
            } else if (func_80101E14(actor, 0.0f)) {
                func_800C4140(0x7FFB5C1D, (char *) actor + 4, 0x1B5801F4);
            }
            break;

        case 3:
            if (!func_800DA298(0x6EC)) {
                result = func_800D90A4((char *) actor + 0x58);

                if (!result || actor->unk64_19) {
                    blend = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 2.707999945f, 0.0f,
                                            1.0f, 0.0f);

                    func_808011D0_chfantasyeyeball(actor, *(f32 *) ((char *) actor + 0x20),
                                                   *(f32 *) ((char *) actor + 0x28), blend);
                } else {
                    func_80801314_chfantasyeyeball(actor);
                    func_800DA544(0x6EC);
                }
            } else if (func_8010C9B0((char *) actor + 4, 0x1388)) {
                if (!func_800F6720(func_800F54E4())) {
                    func_80800950_chfantasyeyeball(actor, 4);
                } else if (func_800D90A4((char *) actor + 0x24) &&
                           func_808017B4_chfantasyeyeball(actor)) {
                    func_80800950_chfantasyeyeball(actor, 5);
                }
            }
            break;

        case 4:
            if (func_80101DDC(actor)) {
                func_80800950_chfantasyeyeball(actor, 1);
            }
            break;

        case 5:
            if (func_80101E14(actor, 0.55f)) {
                sfx_pitch = (u16) (u32) (func_800DC178(1.15f, 1.25f) * 1023.0f);

                func_800C4140((sfx_pitch << 21) + 0x1B5E3D, (char *) actor + 4, 0x1B5801F4);

                func_80108B04(actor, 1);
            } else if (func_80101DDC(actor)) {
                func_80800950_chfantasyeyeball(actor, 3);
            }
            break;

        case 7:
        case 10:
            if (func_80101DDC(actor)) {
                if (actor->unk64_20) {
                    if (*(s32 *) ((char *) actor + 0x34) != 0) {
                        if (actor->unk70_10 == 7) {
                            next_state = 8;
                        } else {
                            next_state = 0xB;
                        }

                        func_80800950_chfantasyeyeball(actor, next_state);
                    } else {
                        result = _subaddielink_entrypoint_4(func_80100094(actor, 0));

                        func_8010A590(result);

                        if (actor->unk70_10 == 7) {
                            next_state = 9;
                        } else {
                            next_state = 0xC;
                        }

                        func_80800950_chfantasyeyeball(actor, next_state);
                    }
                } else {
                    if (actor->unk70_10 == 7) {
                        next_state = 9;
                    } else {
                        next_state = 0xC;
                    }

                    func_80800950_chfantasyeyeball(actor, next_state);
                }
            }

            if (actor->unk64_20) {
                func_800D90A4((char *) actor + 0x58);

                blend = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 2.707999945f, 0.0f,
                                        1.0f, 0.0f);

                func_808011D0_chfantasyeyeball(actor, *(f32 *) ((char *) actor + 0x20),
                                               *(f32 *) ((char *) actor + 0x28), blend);
            }

            if (func_80101E14(actor, 0.35f)) {
                func_80801740_chfantasyeyeball(actor, eye_pos);

                i = 0;

                do {
                    particle = func_800B53A4(3);

                    func_800BA3FC(particle, i + 0x9DF);

                    func_800BABB8(particle, eye_pos, eye_pos, 3.0f, D_80801EEC_chfantasyeyeball);

                    i++;
                } while (i != 8);

                func_800C4140(0xBFDB5C13, (char *) actor + 4, 0x1B5801F4);

                func_80108B04(actor, 2);
            }
            break;

        case 8:
        case 11:
            result = _subaddielink_entrypoint_4(func_80100094(actor, 0));

            if (func_800D90A4((char *) actor + 0x58)) {
                func_80800950_chfantasyeyeball(actor, actor->unk70_10 == 8 ? 9 : 0xC);
            } else {
                blend = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 2.707999945f, 0.0f,
                                        1.0f, 0.0f);

                func_808011D0_chfantasyeyeball(actor, *(f32 *) ((char *) actor + 0x20),
                                               *(f32 *) ((char *) actor + 0x28), blend);
            }

            blend = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 1.5f, 0.0f, 255.0f, 0.0f);

            _subaddiefade_entrypoint_1(result, (s32) blend);
            break;

        case 6:
            link = _subaddielink_entrypoint_4(func_80100094(actor, 0));

            if (func_800D90A4((char *) actor + 0x58)) {
                func_80801314_chfantasyeyeball(actor);
                func_80800950_chfantasyeyeball(actor, 1);
            }

            blend = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 1.5f, 0.0f, 0.0f, 1.0f);

            _subaddiefade_entrypoint_1(link, (s32) (blend * 255.0f));

            func_808011D0_chfantasyeyeball(actor, *(f32 *) ((char *) actor + 0x18),
                                           *(f32 *) ((char *) actor + 0x1C), blend);
            break;

        case 9:
        case 12:
            if (actor->unk64_20) {
                func_800D90A4((char *) actor + 0x58);
                func_800D90A4((char *) actor + 0x2C);

                if (!actor->unk64_19) {
                    func_80801314_chfantasyeyeball(actor);
                    func_800FC6B0(0x18);
                    func_800FFA88(*(s32 *) ((char *) actor + 0));
                    return;
                }

                blend = func_800F10B4(*(f32 *) ((char *) actor + 0x58), 2.707999945f, 0.0f,
                                        1.0f, 0.0f);

                func_808011D0_chfantasyeyeball(actor, *(f32 *) ((char *) actor + 0x20),
                                               *(f32 *) ((char *) actor + 0x28), blend);
            } else if (func_800D90A4((char *) actor + 0x2C)) {
                func_800FFA88(*(s32 *) ((char *) actor + 0));
            }

            blend = func_800F10B4(*(f32 *) ((char *) actor + 0x2C), 1.5f, 0.0f, 255.0f, 0.0f);

            *(u8 *) ((char *) actor + 0x9B) = (u32) blend;
    }

    func_808013F8_chfantasyeyeball(actor);

    func_8010C93C(actor, (char *) actor + 4, 0.75f);

    if (actor->unk70_10 != 9 && actor->unk70_10 != 0xC && actor->unk64_20) {
        func_80801378_chfantasyeyeball(actor);
    }
}

f32 func_808016B4_chfantasyeyeball();

s32 func_80800FEC_chfantasyeyeball();

void func_80800F78_chfantasyeyeball();

// Enter a new state.
void func_80800950_chfantasyeyeball(actor, state) Actor *actor;
s32 state;
{
    s32 partner_id;

    switch (state) {
        case 2:
            if (!func_800DA298(0x6EC)) {
                func_80801290_chfantasyeyeball(actor, 4.0f, 0);
            }
            if (!func_800DA298(0x6D4)) {
                func_800DA544(0x6D4);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x141A, 0xF, actor->position, 0x22);
            }
            break;
        case 3:
            *(f32 *) &actor->actorData[3] = func_808016B4_chfantasyeyeball(actor);
            break;
        case 7:
        case 10:
            if (actor->unk64_20 && !func_800DA298(0x6D5)) {
                func_800DA544(0x6D5);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x141B, 0xF, actor->position, 0x22);
            }
            func_800C4140(0xB31B5DB8, actor->position, 0x1B5801F4);
            if (actor->unk64_20) {
                func_80800FEC_chfantasyeyeball(actor);
                func_80801290_chfantasyeyeball(actor, 2.708f, 0);
            }
            break;
        case 8:
        case 11:
            func_800C3F48(0x4CBB5CEE);
            break;
        case 6:
            func_800C3F48(0x4CBB5CED);
            _subaddieDll_entrypoint_4(actor, 1);
            func_80801290_chfantasyeyeball(actor, 1.5f, 1);
            break;
        case 9:
        case 12:
            if (actor->unk64_20) {
                partner_id = actor->actorData[7];
                if (partner_id) {
                    func_80800F78_chfantasyeyeball(actor, func_80106790((Unk80132ED0 *) partner_id));
                } else if (!func_800DA298(0x6BD)) {
                    func_800DA544(0x6BD);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x141C, 0xF, actor->position,
                                                  0x22);
                }
            }
            actor->unk64_19 = 0;
            *(f32 *) &actor->actorData[5] = 1.5f;
    }
    func_80102424(actor, state);
}

// Actor event handler.
s32 func_80800B68_chfantasyeyeball(Actor *actor, s32 event, s32 param)
{
    Actor *jiggy;
    Actor *seed;
    f32 angles[2];
    f32 spawn_pos[3];
    f32 dist;
    f32 burst_pos[3];
    Actor *burst_actor;

    switch (event) {
        case 0x3F:
            switch (actor->unk70_10) {
                case 1:
                case 2:
                case 4:
                case 6:
                    func_80800950_chfantasyeyeball(actor, 7);
                    break;
                case 3:
                case 5:
                    func_80800950_chfantasyeyeball(actor, 0xA);
            }
            if (!func_800D0B68(0x4C, 1)) {
                func_800FC6B0(0xE);
            }
            return 1;
        case 0x40:
            if (((f32 *) actor->actorData)[6] <= 0.0f &&
                !((EyeballFlags561 *) actor)->unk_78) {
                func_800C4140(0x3FEFA49D, actor->position, 0x04B000FA);
            }
            ((f32 *) actor->actorData)[6] = 2.0f;
            return 1;
        case 0x38:
            func_80101074(&D_80801E98_chfantasyeyeball);
            return 7;
        case 0x3D:
            switch (param) {
                case 0:
                    if (!func_800D0B68(0x4C, 1) && !func_800D0A9C(0x4C, 1)) {
                        jiggy = func_80106790(func_800D10D4(0x4C, 1, actor->position, 3, 0));
                        _subaddielink_entrypoint_1(func_80100094(actor, 0), jiggy->unk0,
                                                   jiggy);
                        ((u8 *) jiggy)[0x77] &= ~0x20;
                        func_8010A570(jiggy);
                    }
                    return 1;
                case 1:
                    func_80801740_chfantasyeyeball(actor, spawn_pos);
                    seed = func_80108528(0x483, spawn_pos, 0, &actor);
                    func_800F5A00(func_800F54E4(), spawn_pos);
                    spawn_pos[1] += 40.0f;
                    seed->unk58 = func_800EEAD4(seed->position, spawn_pos) / 1200.0f;
                    func_8010D12C(func_800F54E4(), spawn_pos, seed->unk58, 0);
                    dist = func_800EEAD4(seed->position, spawn_pos);
                    seed->unk58 = dist / 1200.0f;
                    ((f32 *) seed->actorData)[7] =
                        func_800F10B4(dist, 500.0f, 5000.0f, 100.0f, 600.0f);
                    func_800F18FC(seed->position, spawn_pos, angles);
                    func_800EEBF0((f32 *) &seed->actorData[4], angles, 1200.0f);
                    return 1;
                case 2:
                    func_80801740_chfantasyeyeball(actor, burst_pos);
                    burst_actor = func_80108528(0x483, burst_pos, 0, &actor);
                    burst_actor->scale = 3.0f;
                    _chskeletonexplode_entrypoint_7(burst_actor, burst_actor->position);
                    return 1;
            }
            return 0;
        case 0xF:
            burst_actor = func_80106790(func_80101080());
            _chskeletonexplode_entrypoint_3(burst_actor, 3, 2);
            _chskeletonexplode_entrypoint_4(burst_actor, 6);
            return 1;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(3, 1);
            return 1;
        case 0x2E:
            if (((s16 *) &param)[0] == 0x141A || ((s16 *) &param)[0] == 0x141B ||
                ((s16 *) &param)[0] == 0x141C) {
                actor->unk64_19 = 0;
            }
            return 1;
        case 0x95:
            if (!_subaddielink_entrypoint_3(func_80100094(actor, 0)) && !func_800D0B68(0x4C, 1) &&
                actor->unk64_20) {
                func_80108B04(actor, 0);
            }
            return 1;
    }
    return 0;
}

void func_80800F78_chfantasyeyeball(u8 *from, u8 *to)
{
    u8 *to_copy;
    s32 from_link;
    *(u8 *) ((s8 *) from + 0x65) = (u8) (*(u8 *) ((s8 *) from + 0x65) & 0xFFEF);
    to_copy = to;
    *(u8 *) ((s8 *) to + 0x65) = (u8) ((*(u8 *) ((s8 *) to_copy + 0x65) & 0xFFFFu) | 0x10);
    func_80800950_chfantasyeyeball(to, 6);
    from_link = func_80100094(from, 0);
    _subaddielink_entrypoint_5(from_link, func_80100094(to, 0));
}

// Find the lowest-keyed other plant that is still alive.
s32 func_80800FEC_chfantasyeyeball(Actor *actor)
{
    Actor *plants[15];
    s32 count;
    s32 best;
    s32 best_key;
    s32 i;
    s32 key;

    count = _subaddiefind_entrypoint_4(0x482, plants, 15);
    best = -1;
    best_key = 255;
    for (i = 0; i < count; i++) {
        if ((s32) plants[i]->unk70_10 < 7 && actor != plants[i]) {
            key = plants[i]->unk74_7;
            if (key < best_key) {
                best = i;
                best_key = key;
            }
        }
    }
    if (best == -1) {
        actor->actorData[7] = 0;
        return 0;
    }
    actor->actorData[7] = (s32) plants[best]->unk0;
    return 1;
}

void func_808010B0_chfantasyeyeball(actor, elevation, yaw) Actor *actor;
f32 *elevation;
f32 *yaw;
{
    f32 hit[3];
    f32 start_yaw;
    f32 cam_pos[3];
    f32 end_yaw;
    start_yaw = func_800DC0C0() * 360.0f;
    *elevation = func_800DC0C0() * 20.0f + 20;
    end_yaw = start_yaw + 360.0f;
    *yaw = start_yaw;
    while (*yaw < end_yaw) {
        func_800EEC30(cam_pos, *elevation, *yaw, 2500.0f);
        func_800EF04C(cam_pos, actor->position);
        if (!func_800BEF00(actor->position, cam_pos, hit, 0))
            break;
        *yaw += 30.0f;
    }
}

void func_808011D0_chfantasyeyeball(Actor *actor, f32 pitch, f32 yaw, f32 blend)
{
    f32 cam_rot[3];
    f32 cam_pos[3];
    f32 target[3];

    func_800EEC30(cam_pos, pitch, yaw, 500.0f * blend + 2000.0f);
    func_800EF04C(cam_pos, actor->position);
    func_800EFA4C(target, actor->position[0], actor->position[1] + actor->scale * 224.0f,
                  actor->position[2]);
    func_800A516C(cam_rot, target, cam_pos);
    func_800E39D8(cam_pos, cam_rot);
}

void func_80801290_chfantasyeyeball(Actor *actor, f32 unk_1, s32 skip_lock)
{
    _subaddieDll_entrypoint_4(actor, 1);
    actor->unk58 = 2.708f;
    actor->unk64_19 = 1;
    if (skip_lock == 0) {
        func_800F7B9C(func_800F54E4(), 0x6B);
        func_800A50B0(1);
        func_800F82D4(func_800F54E4(), 2);
    }
}

void func_80801314_chfantasyeyeball(u8 *actor)
{
    func_800F82D4(func_800F54E4(), 0);
    _subaddieDll_entrypoint_4(actor, 0);
    func_800F7B9C(func_800F54E4(), 0x6C);
    func_800A50B0(2);
    actor[0x65] = actor[0x65] & 0xFFF7;
}

void func_80801378_chfantasyeyeball(Actor *actor)
{
    Actor *linked;
    if (!func_800D0B68(0x4C, 1) && actor->unk7C_12) {
        linked = (Actor *) _subaddielink_entrypoint_4(func_80100094(actor, 0));
        if (linked) {
            func_80801740_chfantasyeyeball(actor, linked->position);
            linked->position[1] -= 48.0f;
            func_8010C964(linked);
        }
    }
}

void func_808013F8_chfantasyeyeball(actor) Actor *actor;
{
    s32 bone;
    f32 eye_pos[3];
    f32 player_pos[3];
    f32 angles[2];
    f32 dt;
    f32 wilt;

    bone = func_8010262C(actor->unk0, 3);
    if (bone) {
        dt = func_800D8FF8();
        if ((s32) actor->unk70_10 < 7) {
            func_800F5A00(func_800F54E4(), player_pos);
            func_80801740_chfantasyeyeball(actor, eye_pos);
            func_800F18FC(eye_pos, player_pos, angles);
            if (angles[0] < 310.0f && angles[0] > 180.0f) {
                angles[0] = 320.0f;
            }
            if (actor->unk70_10 == 1 || actor->unk70_10 == 4) {
                angles[0] = func_800136E4(80.0f - angles[0]);
            } else {
                angles[0] = func_800136E4(45.0f - angles[0]);
            }
            angles[1] = func_800136E4(angles[1] - actor->rotation[1]);
            actor->unk54 =
                func_800F1FF0(actor->unk54, angles[1], 0.75f, dt * 2.0f, 90.0f * dt);
            actor->unk50 =
                func_800F1FF0(actor->unk50, angles[0], 0.75f, dt * 2.0f, 90.0f * dt);
            func_800E0ACC(bone);
            func_800E0AF0(bone, 1.0f);
            func_800E0AFC(bone, 0x2C, -1.0f, actor->unk50, 0.0f, 0.0f);
            func_800E0AFC(bone, 1, -1.0f, 0.0f, actor->unk54, 0.0f);
            if (!func_800D90A4(&((f32 *) actor->actorData)[6])) {
                wilt = func_800F10B4(((f32 *) actor->actorData)[6], 2.0f, 0.0f, 1.0f, 0.0f);
                func_800E0B8C(bone, 1, -1.0f,
                              func_80013970(1800.0f * wilt) * 0.25f * wilt + 1.0f,
                              func_80013970(2520.0f * wilt) * 0.25f * wilt + 1.0f,
                              func_80013970(1080.0f * wilt) * 0.25f * wilt + 1.0f);
            }
        }
    }
}

// Half a unit per plant still alive.
f32 func_808016B4_chfantasyeyeball(Actor *actor)
{
    Actor *plants[10];
    s32 alive = 0;
    s32 i;
    for (i = _subaddiefind_entrypoint_4(0x482, plants, 10) - 1; i >= 0; i--) {
        if ((s32) plants[i]->unk70_10 < 7)
            alive++;
    }
    return alive * 0.5f;
}

void func_80801740_chfantasyeyeball(actor, out_pos) Actor *actor;
f32 out_pos[3];
{
    if (actor->unk7C_12) {
        _subaddieskeleton_entrypoint_1(actor, 4, out_pos);
    } else {
        func_800EE7F8(out_pos, actor->position);
        out_pos[1] += actor->scale * 224.0f;
    }
}

s32 func_808017B4_chfantasyeyeball(actor)
Actor *actor;
{
    f32 dist;

    dist = (f32) func_8010C754(actor);

if ((dist > 5000.0f) || (dist < 500.0f)) {
    return 0;
}

return func_8010D248();
}

int chfantasyeyeball_entrypoint_0()
{
    return (int) &D_80801F28_chfantasyeyeball;
}

// Seed projectile: per-frame update.
void func_8080182C_chfantasyeyeball(Actor *actor)
{
    f32 prev_pos[3];
    f32 hit_normal[3];
    s32 particle;

if (func_800D91EC(&*(f32 *) ((u8 *) actor + 0x24), 5.0f)) {
    func_80801BC4_chfantasyeyeball(actor, NULL);
    return;
}

func_800EE7F8(prev_pos, actor->position);

if (*(f32 *) ((u8 *) actor + 0x24) <= actor->unk58) {
    func_800EF174((f32 *) actor->actorData, (f32 *) &actor->actorData[4], func_800D8FF8());
    func_800EFA4C(actor->position, *(f32 *) &actor->actorData[0],
                  *(f32 *) &actor->actorData[1] +
                      *(f32 *) &actor->actorData[7] *
                          func_80013970(func_800F10B4(*(f32 *) ((u8 *) actor + 0x24), 0.0f,
                                                      actor->unk58, 0.0f, 180.0f)),
                  *(f32 *) &actor->actorData[2]);
} else {

*(f32 *) &actor->actorData[5] += -2000.0f * func_800D8FF8();
func_800EF174(actor->position, (f32 *) &actor->actorData[4], func_800D8FF8());
}
if (func_800BF340(prev_pos, actor->position, hit_normal, 0x20020, actor->scale * 33.0f)) {
    func_800EFB24(((f32 *) actor->actorData), actor->position, prev_pos);
    func_800EFDE8(((f32 *) actor->actorData), ((f32 *) actor->actorData), hit_normal);
    func_800EFB24(((f32 *) actor->actorData), actor->position, ((f32 *) actor->actorData));
    func_80801BC4_chfantasyeyeball(actor, ((f32 *) actor->actorData));
    return;
}
_subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80801FB0_chfantasyeyeball);
particle = func_800B53A4(1);
func_800BA3FC(particle, func_800DC128(0, 9) + 0x9DF);
func_800BABB8(particle, actor->position, NULL, 1.0f, D_80801F70_chfantasyeyeball);
(*(f32 *) ((u8 *) actor + 0x44)) += (*(f32 *) ((u8 *) actor + 0x50)) * func_800D8FF8();
(*(f32 *) ((u8 *) actor + 0x48)) += (*(f32 *) ((u8 *) actor + 0x54)) * func_800D8FF8();
}

// Seed projectile: event handler.
int func_80801A50_chfantasyeyeball(Actor *actor, s32 event, FantasyEyeEvent39 param)
{
    f32 player_pos[3];
    Actor *burst_actor;
    switch (event) {
        case 0x3E:
            func_800F5A00(func_800F54E4(), player_pos);
            func_80801BC4_chfantasyeyeball(actor, player_pos);
            return 1;
        case 0x3F:
            if (*(u16 *) ((u8 *) (*(Unk80132ED0 **) &param) + 0x18) & 1)
                func_80801BC4_chfantasyeyeball(
                    actor, func_80106790((*(Unk80132ED0 **) &param))->position);
            else
                func_80801BC4_chfantasyeyeball(actor, NULL);
            return 1;
        case 0xF:
            burst_actor = func_80106790(func_80101080());
            _chskeletonexplode_entrypoint_3(burst_actor, 3, 2);
            _chskeletonexplode_entrypoint_4(burst_actor, 6);
            func_800FFA88(actor->unk0);
            return 1;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(3, 1);
            return 1;
        case 0x95:
            *(f32 *) ((u8 *) actor + 0x54) = func_800DC178(180.0f, 360.0f);
            *(f32 *) ((u8 *) actor + 0x50) = func_800DC178(180.0f, 360.0f);
            func_800EE7F8(actor->actorData, actor->position);
            *(f32 *) ((u8 *) actor + 0x24) = 0.0f;
            return 1;
    }
    return 0;
}

// Burst the seed into debris.
void func_80801BC4_chfantasyeyeball(actor, hit_pos) Actor *actor;
f32 *hit_pos;
{
    s32 i;
    s32 particle;
    f32 *pos = actor->position;

    for (i = 0; i < 8; i++) {
        particle = func_800BABB8(0, pos, hit_pos != NULL ? hit_pos : pos, 1.0f,
                                D_80801FC0_chfantasyeyeball);
        func_800BA3FC(particle, i + 0x9DF);
        func_800BA22C(particle, 3);
    }
    _chskeletonexplode_entrypoint_7(actor, hit_pos != NULL ? hit_pos : pos);
    func_800C4140(0x7FFF441F, pos, 0x4B000FA);
}

int chfantasyeyeball_entrypoint_1()
{
    return &D_80802008_chfantasyeyeball;
}

extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80801E30_chfantasyeyeball[26] = {
    0x0,        0x0,        0x3F5C28F6, 0x3930049,  0x3F889375, 0x396004A,  0x3F5C28F6,
    0x3970049,  0x3F666666, 0x39A004A,  0x3F666666, 0x398004A,  0x3F5C28F6, 0x393004A,
    0x3F9A9FBE, 0x395004A,  0x3F9A9FBE, 0x3950086,  0x3F9A9FBE, 0x3950086,  0x3F9A9FBE,
    0x399004A,  0x3F9A9FBE, 0x3990086,  0x3F9A9FBE, 0x3990086};
s32 D_80801E98_chfantasyeyeball[21] = {0x2B, 0x40000000, 0x1120000, 0x12, 0x40000000, 0x1030000,
                                       0x2C, 0x40733333, 0x2A0000,  0x50, 0x40000000, 0x2520000,
                                       0x55, 0x40000000, 0x2570000, 0x4B, 0x40000000, 0x24D0000,
                                       0x46, 0x40000000, 0x2480000};
u8 D_80801EEC_chfantasyeyeball[60] = {
    0x0,  0x16, 0x15, 0x86, 0x0,  0xE,  0x0,  0x32, 0x0,  0x64, 0x0,  0x2D, 0x1,  0x90, 0x2,
    0x58, 0x0,  0x1B, 0xFC, 0xE0, 0xFD, 0xA8, 0x0,  0x24, 0x0,  0x40, 0x0,  0x4C, 0x0,  0x15,
    0x0,  0x0,  0x0,  0xC0, 0x0,  0x2B, 0x1,  0x0,  0x2,  0x0,  0x0,  0x27, 0x0,  0x0,  0xFE,
    0x70, 0x0,  0x0,  0x1,  0x90, 0x0,  0x31, 0xFF, 0xCE, 0xFF, 0x9C, 0x3,  0x1A, 0x0,  0x0};
int D_80801F28_chfantasyeyeball[18] = {0x10F0482,
                                       0x8930001,
                                       (u32) &D_80801E30_chfantasyeyeball,
                                       (u32) func_808000D8_chfantasyeyeball,
                                       (u32) func_80105834,
                                       (u32) func_801018A4,
                                       0x1B580000,
                                       0x0,
                                       0x0,
                                       0x820260,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x80000,
                                       (u32) func_80800000_chfantasyeyeball,
                                       (u32) func_80107C2C,
                                       -0x7BFD8FFC,
                                       (u32) func_80800B68_chfantasyeyeball,
                                       0x0};
u8 D_80801F70_chfantasyeyeball[64] = {
    0x0, 0x1B, 0xFD, 0xA8, 0xFE, 0xC,  0x0,  0x16, 0x10, 0x0, 0x0, 0xE,  0x0, 0x1E, 0x0, 0x1E,
    0x0, 0x24, 0x0,  0x40, 0x0,  0x4C, 0x0,  0x15, 0x0,  0x0, 0x0, 0xC0, 0x0, 0x2B, 0x0, 0x4C,
    0x0, 0x4C, 0x0,  0x27, 0x0,  0x0,  0xFE, 0x70, 0x0,  0x0, 0x1, 0x90, 0x0, 0x2F, 0x0, 0x4C,
    0x0, 0x26, 0x0,  0x0,  0x0,  0x0,  0x0,  0x26, 0x0,  0x0, 0x0, 0x28, 0x1, 0x1A, 0x0, 0x0};
u8 D_80801FB0_chfantasyeyeball[16] = {0x0, 0x13, 0x6, 0x5C, 0x0, 0x16, 0x61, 0xA8,
                                      0x0, 0xA,  0x1, 0x0,  0x0, 0x0,  0x0,  0x0};
u8 D_80801FC0_chfantasyeyeball[72] = {
    0x3,  0x10, 0x0,  0x16, 0x15, 0x86, 0x0,  0xE,  0x0,  0x1E, 0x0,  0x1E, 0x0,  0x2D, 0x1,
    0x90, 0x2,  0x58, 0x0,  0x1B, 0xFC, 0xE0, 0xFD, 0xA8, 0x0,  0x24, 0x0,  0x40, 0x0,  0x4C,
    0x0,  0x15, 0x0,  0x0,  0x0,  0xC0, 0x0,  0x2B, 0x0,  0x80, 0x1,  0x0,  0x0,  0x27, 0x0,
    0x0,  0xFE, 0x70, 0x0,  0x0,  0x1,  0x90, 0x0,  0x2F, 0x0,  0x4C, 0x0,  0x26, 0x0,  0x0,
    0x0,  0x0,  0x0,  0x26, 0x0,  0x0,  0x0,  0x28, 0x0,  0x0,  0x0,  0x0};
int D_80802008_chfantasyeyeball[18] = {0x1100483,
                                       0x8940001,
                                       0x0,
                                       (u32) func_8080182C_chfantasyeyeball,
                                       (u32) func_80105834,
                                       (u32) func_801018A4,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x800004,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x0,
                                       0x0,
                                       (u32) func_80107C2C,
                                       -0x7FE00000,
                                       (u32) func_80801A50_chfantasyeyeball,
                                       0x0};
