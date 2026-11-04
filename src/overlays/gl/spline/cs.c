// Most likely the spline "cutscene script" interpreter: each actor on a spline runs a timed
// command list of about 40 opcodes (animation, movement, spawns, flags, sound, camera, waits).
// A script is { type, (time, opcode << 16 | arg, extra words...)..., 2 }.
// type 0x10005: times in frames, type 0x10006: times in 1/4000000 units.
#include "common.h"

typedef struct {
    u8 pad_0[0x40];
    u32 unk_40_0 : 9;
    u32 unk_40_9 : 9;
    u32 unk_40_18 : 9;
    u32 pad_1 : 5;
    u32 pad_2 : 3;
    u32 unk_44_3 : 9;
    u32 pad_3 : 20;
} SplineCsBits;
extern void *func_80105494(Actor *);
typedef struct {
    u32 pad_0 : 8;
    u32 cmd_index : 13;
    u32 pad_1 : 11;
    u8 pad_2[8];
    f32 path_t;
    u8 pad_3[0x28];
    f32 start;
    f32 end;
    u8 pad_4[4];
    u8 in_frames : 1;
    u8 mode : 2;
    u8 pad_5 : 5;
} SplineCameraTransition;
typedef struct {
    s32 pad_0 : 21;
    s32 path_index : 10;
    s32 pad_1 : 1;
    u8 pad_2[0x10];
    f32 unk_14;
    u8 pad_3[0x18];
    f32 unk_30;
    f32 unk_34;
} SplineCameraDuration;
extern void *func_800D7520(s32);
extern f32 func_800C7AE4(void *, f32, f32);
typedef struct {
    u32 script_id : 8;
    u32 cmd_index : 13;
    s32 path_index : 10;
    u32 unk_0_31 : 1;
    f32 start_time;
    f32 saved_elapsed;
    f32 path_t;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 anim_duration;
    f32 wait_time;
    u32 anim_index : 15;
    u32 pad_0 : 1;
    u32 unk_24_16 : 1;
    u32 unk_24_17 : 1;
    u32 unk_24_18 : 1;
    u32 unk_24_19 : 4;
    u32 target_slot : 3;
    u32 pad_1 : 6;
    u32 unk_28_0 : 3;
    u32 pad_2 : 3;
    u32 wait_counter : 8;
    u32 pad_3 : 2;
    u32 unk_28_16 : 9;
    u32 unk_28_25 : 1;
    u32 unk_28_26 : 6;
    f32 unk_2C;
} SplineScriptState;
typedef struct {
    s32 in_use : 1;
    s32 is_prop : 1;
    u32 pad_0 : 14;
    s16 unk_2[3];
    void *handle;
} SplineScriptSlot;
typedef struct {
    u8 counters[0x80];
    u8 counter_init[0x80];
    void *actors[0x24];
    f32 time;
    u8 pad_0[4];
    s32 script_asset;
    s32 *script_offsets;
    u8 pad_1[4];
    SplineScriptSlot *slots;
} SplineScriptContext;
typedef struct {
    u8 pad_0[0x77];
    u8 pad_1 : 4;
    u8 unk_77 : 4;
    u8 pad_2;
    u8 pad_3 : 6;
    u8 unk_79 : 2;
} SplineScriptActorFlags;
extern void anctrl_setDuration(s32, f32);
extern void func_8008B10C(s32, f32);
extern void func_8008B1C8(s32, f32);
extern f32 func_800D7708(s32, f32, s32);
extern void func_8010FD38(s32, f32);
extern Actor *func_80106790(void *);
extern Actor *_subaddiefind_entrypoint_12(s32);
extern s16 *_gccubesearch_entrypoint_17(s32, s32);
extern s32 _gspropctrl_entrypoint_10();
extern void _glsplinecs_entrypoint_0();
extern void _glsplinefuncs_entrypoint_1();

// Callback for func_800C04C8 (opcode 41): returns the jiggy count.
s32 glsplinecs_entrypoint_0(s32 unk_0, s32 unk_1, s32 unk_2)
{
    func_800D035C(1);
}

void func_8080002C_glsplinecs(s32 ctx, u8 *actor, s32 arg)
{
    SplineCsBits *state;

    state = func_80105494(actor);
    state->unk_40_9 = (u32) *(f32 *) (actor + 0x48);
    state->unk_40_0 = (arg >> 16) & 0x1FF;
    state->unk_40_18 = (u32) *(f32 *) (actor + 0x44);
    state->unk_44_3 = arg & 0x1FF;
    *(f32 *) (actor + 0x54) = state->unk_40_9;
    *(f32 *) (actor + 0x50) = state->unk_40_18;
}

void func_80800228_glsplinecs(void *ctx, Actor *actor, s32 end_time, s32 mode, s32 *script)
{
    SplineCameraTransition *state;

    state = (SplineCameraTransition *) func_80105494(actor);
    state->mode = mode;
    if (script[0] == 0x10006) {
        state->start = state->path_t;
        state->end = (f32) end_time / 4000000.0f;
        state->in_frames = 0;
    } else if (script[0] == 0x10005) {
        state->start = *(f32 *) ((u8 *) ctx + 0x190);
        state->end = *(f32 *) ((u8 *) ctx + 0x190) + script[state->cmd_index];
        state->in_frames = 1;
    }
}

void func_80800310_glsplinecs(s32 ctx, Actor *actor, s32 end_time, s32 unk_0)
{
    SplineCameraDuration *state;
    f32 unk_1;
    state = func_80105494(actor);
    state->unk_30 = state->unk_14;
    unk_1 = func_800C7AE4(func_800D7520(state->path_index), end_time / 4000000.0f, 1.0f);
    state->unk_34 = unk_1 / (unk_0 * 0.25f);
}

s32 func_808003A8_glsplinecs(Actor *this)
{
    s32 anctrl;
    s32 result;
    anctrl = func_80104248(this);
    if (anctrl == 0) {
        anctrl = func_801042B8(this);
        anctrl_reset(anctrl);
    }
    // Matching: extra temporary for the return value.
    result = anctrl;
    return result;
}

// Runs the commands of the actor's spline script that are due. Stops at the first command that
// is not due yet, at a wait, or at the end marker.
void glsplinecs_entrypoint_1(SplineScriptContext *ctx, Actor *actor)
{
    SplineScriptState *state;
    s32 *script;
    s32 base;

    state = func_80105494(actor);
    base = (s32) func_800D674C(ctx->script_asset);
    script = (s32 *) (ctx->script_offsets[state->script_id - 1] + base);
    if (state->cmd_index == 0) {
        state->cmd_index = 1;
    }
    if (state->wait_time != 0.0f || state->unk_24_19 != 0 || state->unk_28_16 != 0 ||
        state->wait_counter != 0 || state->unk_2C > 0.0f) {
        return;
    }
    // Resuming after a wait: restore the elapsed time.
    if (state->saved_elapsed != 0.0f) {
        if (script[0] == 0x10005) {
            state->start_time = ctx->time - state->saved_elapsed;
        }
        state->saved_elapsed = 0;
    }
    while (
        script[state->cmd_index + 1] != 2 &&
        ((script[0] == 0x10005 &&
          script[state->cmd_index] <= ctx->time - state->start_time) ||
         (script[0] == 0x10006 && script[state->cmd_index] / 4000000.0f <= state->path_t)) &&
        state->wait_time == 0.0f && state->unk_24_19 == 0 && state->unk_28_16 == 0 &&
        state->wait_counter == 0 && !(state->unk_2C > 0.0f)) {
        switch (script[state->cmd_index + 1] >> 16) {
            case 9:
                func_800D7754(actor, script[state->cmd_index + 1] & 0xFFFF);
                break;
            case 7:
                if (!state->unk_24_18 && !state->unk_28_26 && !state->target_slot &&
                    state->unk_24_16) {
                    actor->unk54 = (f32) (script[state->cmd_index + 1] & 0xFFFF);
                }
                break;
            case 8:
                if (!state->unk_24_18 && !state->unk_28_26 && !state->target_slot &&
                    state->unk_24_17) {
                    actor->unk50 = (f32) (script[state->cmd_index + 1] & 0xFFFF);
                }
                break;
            case 14: {
                s32 anctrl;
                anctrl = func_808003A8_glsplinecs(actor);
                state->anim_duration = script[state->cmd_index + 2] / 4000000.0f;
                state->anim_index = _seqdat_entrypoint_0(script[state->cmd_index + 1] & 0xFFFF, 0);
                anctrl_setIndex(anctrl, state->anim_index);
                anctrl_setDuration(anctrl, state->anim_duration);
                func_8008B188(anctrl, 1);
                anctrl_start(anctrl);
                func_8008B10C(anctrl, 0.00001f);
                state->cmd_index++;
                break;
            }
            case 15: {
                s32 anctrl;
                f32 seconds;
                anctrl = func_808003A8_glsplinecs(actor);
                seconds = script[state->cmd_index + 2] / 4000000.0f;
                func_8008B1C8(anctrl, seconds);
                state->cmd_index++;
                break;
            }
            case 16: {
                s32 anctrl;
                anctrl = func_808003A8_glsplinecs(actor);
                anctrl_setPlaybackType(anctrl, 1);
                break;
            }
            case 17: {
                s32 anctrl;
                anctrl = func_808003A8_glsplinecs(actor);
                anctrl_setPlaybackType(anctrl, 2);
                break;
            }
            case 48:
                actor->unk64_19 = script[state->cmd_index + 1] & 0xFFFF;
                break;
            case 56:
                func_80105BE0(actor, script[state->cmd_index + 1] & 0xFFFF);
                break;
            case 54:
                actor->unk7A_11 = script[state->cmd_index + 1] & 0xFFFF;
                break;
            case 55:
                ((SplineScriptActorFlags *) actor)->unk_77 =
                    script[state->cmd_index + 1] & 0xFFFF;
                break;
            case 53: {
                f32 value;
                value = 0;
                if (script[state->cmd_index + 1] & 0xFFFF) {
                    value = 5.0f;
                }
                func_8010FD38(func_8008FFE8(), value);
                break;
            }
            case 52:
                func_800DA544(0);
                break;
            case 18:
                state->unk_14 = func_800D7708(state->path_index, state->path_t,
                                                 script[state->cmd_index + 1] & 0xFFFF);
                break;
            // Move the actor to the node with this event id.
            case 21: {
                s32 path;
                f32 t;
                f32 pos[3];
                s32 extra_a;
                s32 extra_b;
                _glsplinefuncs_entrypoint_0(script[state->cmd_index + 1] & 0xFFFF, &path,
                                            &t, pos, state->path_index, &extra_a,
                                            &extra_b);
                state->path_index = path;
                state->path_t = t;
                actor->position[0] = pos[0];
                actor->position[1] = pos[1];
                actor->position[2] = pos[2];
                break;
            }
            case 40: {
                int value;
                int abs_value;
                value = ((script[state->cmd_index + 1] & 0xFFFF) & 0x8000)
                               ? (script[state->cmd_index + 1] & 0xFFFF) | 0xFFFF0000
                               : (script[state->cmd_index + 1] & 0xFFFF);
                abs_value = value >= 0 ? value : -value;
                ((SplineScriptActorFlags *) actor)->unk_79 =
                    value < 0 ? 2 : (value > 0 ? 1 : 0);
                if (abs_value) {
                    ((f32 *) actor->actorData)[0] = abs_value * 0.25f;
                } else {
                    ((f32 *) actor->actorData)[0] = 0;
                }
                ((f32 *) actor->actorData)[1] = 0;
                break;
            }
            case 49:
                _subaddiefade_entrypoint_1(actor, script[state->cmd_index + 1] & 0xFFFF);
                break;
            case 41: {
                func_800C04C8(script[state->cmd_index + 1] & 0xFFFF,
                              (script[state->cmd_index + 2] >> 24) & 0x3F,
                              script[state->cmd_index + 2] & 0xFFFF,
                              (script[state->cmd_index + 2] >> 16) & 0xF,
                              _glsplinecs_entrypoint_0);
                state->cmd_index++;
                break;
            }
            case 27: {
                func_800DA3B8(
                    _seqdefine_entrypoint_0((script[state->cmd_index + 1] & 0xFFFF) & 0x3FFF),
                    (script[state->cmd_index + 1] & 0xFFFF) & 0x4000 ? 1 : 0);
                break;
            }
            case 34: {
                func_800FFA88((script[state->cmd_index + 1] & 0xFFFF) == 0
                                  ? actor->unk0
                                  : ctx->actors[(script[state->cmd_index + 1] & 0xFFFF)]);
                break;
            }
            case 35: {
                func_800FFA88((script[state->cmd_index + 1] & 0xFFFF) == 0
                                  ? actor->unk0
                                  : ctx->actors[(script[state->cmd_index + 1] & 0xFFFF)]);
                func_800A50B0(2);
                break;
            }
            // Spawn a baddie that follows the spline (glsplinefuncs_entrypoint_1).
            case 36:
                _chbaddiesetup_entrypoint_3(_glsplinefuncs_entrypoint_1,
                                            script[state->cmd_index + 1] & 0xFFFF,
                                            script[state->cmd_index + 2], state->path_index);
                state->cmd_index++;
                break;
            // Wait for arg / 4 time units.
            case 19:
                state->wait_time = (script[state->cmd_index + 1] & 0xFFFF) * 0.25f;
                if (script[0] == 0x10005) {
                    state->saved_elapsed = ctx->time - state->start_time;
                }
                break;
            case 20:
                state->unk_24_19 = (script[state->cmd_index + 1] & 0xFFFF) - 0x69;
                if (script[0] == 0x10005) {
                    state->saved_elapsed = ctx->time - state->start_time;
                }
                break;
            case 31:
                state->unk_2C = (f32) (script[state->cmd_index + 1] & 0xFFFF);
                break;
            case 28:
                state->unk_28_16 = (script[state->cmd_index + 1] & 0xFFFF) + 1;
                state->unk_28_25 = 0;
                if (script[0] == 0x10005) {
                    state->saved_elapsed = ctx->time - state->start_time;
                }
                break;
            case 29:
                state->unk_28_16 = (script[state->cmd_index + 1] & 0xFFFF) + 1;
                state->unk_28_25 = 1;
                if (script[0] == 0x10005) {
                    state->saved_elapsed = ctx->time - state->start_time;
                }
                break;
            case 30:
                func_800DA544(0x644);
                break;
            // Start script script_id on an actor (0 = this actor).
            case 42: {
                s32 script_id;
                s32 actor_id;
                SplineScriptState *target_state;
                Actor *target;
                actor_id = ((script[state->cmd_index + 1] & 0xFFFF) >> 12) & 0x3F;
                script_id = (script[state->cmd_index + 1] & 0xFFFF) & 0xFFF;
                if (actor_id == 0) {
                    target = actor;
                } else {
                    target = func_80106790(ctx->actors[actor_id]);
                }
                target_state = func_80105494(target);
                target_state->script_id = script_id;
                target_state->start_time = ctx->time;
                target_state->cmd_index = 0;
                target_state->saved_elapsed = 0;
                break;
            }
            // Store this actor's handle in actor slot arg.
            case 37:
                ctx->actors[script[state->cmd_index + 1] & 0xFFFF] = actor->unk0;
                break;
            // Pause an actor's script with a huge wait time.
            case 43: {
                SplineScriptState *target_state;
                Actor *target;
                if ((script[state->cmd_index + 1] & 0xFFFF) == 0) {
                    target = actor;
                } else {
                    target =
                        func_80106790(ctx->actors[(script[state->cmd_index + 1] & 0xFFFF)]);
                }
                target_state = func_80105494(target);
                target_state->wait_time = 1700000.0f;
                if (script[0] == 0x10005) {
                    target_state->saved_elapsed = ctx->time - state->start_time;
                }
                break;
            }
            // Resume an actor's script.
            case 44: {
                SplineScriptState *target_state;
                Actor *target;
                if ((script[state->cmd_index + 1] & 0xFFFF) == 0) {
                    target = actor;
                } else {
                    target =
                        func_80106790(ctx->actors[(script[state->cmd_index + 1] & 0xFFFF)]);
                }
                target_state = func_80105494(target);
                target_state->wait_time = 0;
                break;
            }
            case 10: {
                u32 actor_id;
                s32 unk_0;
                Actor *target;
                SplineScriptState *target_state;
                unk_0 = ((script[state->cmd_index + 1] & 0xFFFF) >> 6) & 0x3F;
                actor_id = (script[state->cmd_index + 1] & 0xFFFF) & 0x3F;
                if (actor_id == 0) {
                    target = actor;
                } else {
                    target = func_80106790(ctx->actors[actor_id]);
                }
                target_state = func_80105494(target);
                target_state->unk_28_26 = unk_0;
                target_state->target_slot = 0;
                target_state->unk_24_18 = 0;
                target_state->unk_24_16 = 0;
                target_state->unk_24_17 = 0;
                break;
            }
            case 47:
                func_80090708(script[state->cmd_index + 1] & 0xFFFF ? 0 : 2);
                break;
            // Register the actor or prop with this id in a free slot (id 0 frees the current slot).
            case 11: {
                s32 id;
                Actor *target;
                s16 *prop;
                s32 i;
                id = script[state->cmd_index + 1] & 0xFFFF;
                if (id != 0) {
                    target = _subaddiefind_entrypoint_12(id);
                    prop = 0;
                    if (target == 0) {
                        prop = _gccubesearch_entrypoint_17(id, 0);
                    }
                    state->unk_28_26 = 0;
                    state->unk_24_18 = 0;
                    state->unk_24_16 = 0;
                    state->unk_24_17 = 0;
                    for (i = 0; i < 7; i++) {
                        if (!(ctx->slots + i)->in_use) {
                            SplineScriptSlot *slot = ctx->slots + i;
                            state->target_slot = i + 1;
                            if (target != 0) {
                                slot->in_use = 1;
                                slot->is_prop = 0;
                                slot->handle = target->unk0;
                            } else if (prop != 0) {
                                slot->in_use = 1;
                                slot->is_prop = 1;
                                _gspropctrl_entrypoint_10(prop, slot->unk_2);
                            }
                            i = 7;
                        }
                    }
                } else {
                    ctx->slots[state->target_slot - 1].in_use = 0;
                    state->target_slot = 0;
                }
                break;
            }
            case 13:
                if (script[state->cmd_index + 1] & 0xFFFF) {
                    actor->unk64_18 = 1;
                } else {
                    actor->unk64_18 = 0;
                }
                break;
            // Decrement counter arg (if nonzero) and wait on it.
            case 32: {
                s32 count;
                count = ctx->counters[script[state->cmd_index + 1] & 0xFFFF];
                if (count != 0) {
                    ctx->counters[script[state->cmd_index + 1] & 0xFFFF] = count - 1;
                }
                state->wait_counter = (script[state->cmd_index + 1] & 0xFFFF) + 1;
                if (script[0] == 0x10005) {
                    state->saved_elapsed = ctx->time - state->start_time;
                }
                break;
            }
            // Reset counter arg to its initial value.
            case 33: {
                ctx->counters[(script[state->cmd_index + 1] & 0xFFFF)] =
                    ctx->counter_init[(script[state->cmd_index + 1] & 0xFFFF)];
                break;
            }
            case 12:
                state->unk_28_0 = script[state->cmd_index + 1] & 0xFFFF;
                break;
            case 45:
                func_800C84A4(func_800D7520(state->path_index),
                              script[state->cmd_index + 1] & 0xFFFF ? 1 : 0);
                break;
            case 46:
                func_8009086C(script[state->cmd_index + 1] & 0xFFFF);
                break;
            case 38:
                func_80800228_glsplinecs(ctx, actor, script[state->cmd_index + 3], 1,
                                         script);
                func_8080002C_glsplinecs(ctx, actor, script[state->cmd_index + 2]);
                state->cmd_index += 2;
                break;
            case 39:
                func_80800228_glsplinecs(ctx, actor, script[state->cmd_index + 3], 2,
                                         script);
                func_80800310_glsplinecs((s32) ctx, actor, script[state->cmd_index + 3],
                                         script[state->cmd_index + 2]);
                state->cmd_index += 2;
                break;
            case 51:
                _chintrotext_entrypoint_1(0x18BC, script[state->cmd_index + 1] & 0xFFFF, 2, 2);
        }
        // Commands with extra words skip them inside their case.
        state->cmd_index += 2;
    }
    if (script[state->cmd_index + 1] == 2) {
        state->script_id = 0;
        state->cmd_index = 0;
        state->start_time = 0;
        state->saved_elapsed = 0;
    }
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gl/spline/cs.data.s) is defined here in C; values taken from the ROM.
