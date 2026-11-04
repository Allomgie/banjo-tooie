#include "common.h"

typedef struct {
    u32 script_id : 8;
    u32 script_pos : 13;
    s32 path_index : 10;
    u32 unk_3 : 1;
    f32 script_time;
    f32 unk_5;
    f32 path_t;
    f32 unk_7;
    f32 speed;
    f32 unk_9;
    f32 anim_duration;
    f32 unk_11;
    u32 anim_id : 15;
    u32 pad_0 : 1;
    u32 unk_13 : 1;
    u32 unk_14 : 1;
    u32 unk_15 : 1;
    u32 unk_16 : 4;
    u32 unk_17 : 3;
    u32 pad_1 : 6;
    u16 unk_18 : 3;
    u16 unk_24 : 1;
    u16 follow_mode : 2;
    u16 unk_19 : 8;
    u16 pad_3 : 2;
    u32 unk_20 : 9;
    u32 unk_21 : 1;
    u32 unk_22 : 6;
    f32 unk_23;
    f32 seg_speed_start;
    f32 seg_speed_end;
    f32 seg_t_start;
    f32 seg_t_end;
    u32 seg_yaw_end : 9;
    u32 seg_yaw_start : 9;
    u32 seg_pitch_start : 9;
    u32 pad_4 : 5;
    u32 unk_33 : 1;
    u32 seg_flags : 2;
    u32 seg_pitch_end : 9;
    u32 pad_5 : 20;
} SplineNodeState;
typedef struct {
    f32 t;
    union {
        struct {
            u16 target_id : 11;
            u16 pad_0 : 1;
            u16 speed_class : 2;
            u16 seg_flags : 2;
            u32 pitch : 9;
            u32 unk_4 : 3;
            u32 type : 3;
            u32 pad_1 : 1;
        } common;
        struct {
            u32 unk_0 : 1;
            u32 unk_1 : 15;
            u32 unk_2 : 8;
            u32 unk_3 : 4;
            u32 pad_0 : 4;
        } event;
        u16 raw[2];
    } data1;
    u32 anim_seq : 10;
    u32 anim_time : 11;
    u32 set_anim : 1;
    u32 unk_5 : 1;
    u32 unk_6 : 1;
    u32 pad_0 : 8;
    union {
        struct {
            u32 yaw : 9;
            u32 unk_1 : 11;
            u32 value : 11;
            u32 is_event : 1;
        } common;
        struct {
            u32 script_id : 8;
            u32 pad_0 : 2;
            u32 unk_1 : 1;
            u32 unk_2 : 8;
            u32 pad_1 : 13;
        } event;
    } data2;
    union {
        struct {
            u32 id : 11;
            u32 pad_0 : 12;
            u32 unk_1 : 1;
            u32 unk_2 : 1;
            u32 pad_1 : 3;
            u32 unk_3 : 1;
            u32 pad_2 : 3;
        } common;
        struct {
            u32 pad_0 : 22;
            u32 unk_0 : 6;
            u32 pad_1 : 4;
        } event;
    } data3;
} SplineNode;
typedef struct {
    s32 count;
    SplineNode nodes[1];
} SplineNodeList;
typedef struct {
    u8 pad_0[0x190];
    f32 unk_190;
} SplineNodeContext;
typedef struct {
    u8 pad_0[0x78];
    u16 pad_1 : 14;
    u16 unk_78 : 2;
    u32 pad_2 : 16;
} SplineNodeActorFlags;
typedef struct {
    f32 unk_0;
    f32 unk_4;
} SplineNodeActorMotionData;
extern void *func_80105494(Actor *);
extern s32 _glsplinefuncs_entrypoint_0(s32, s32 *, f32 *, f32 *, s32, f32 *, f32 *);
extern void _glsplinenode_entrypoint_0();
extern s16 D_808009B0_glsplinenode[];
extern void *func_80104248(Actor *);
extern void *func_801042B8(Actor *);
extern void anctrl_reset(void *);
extern void anctrl_setIndex(void *, s32);
extern void anctrl_setDuration(void *, f32);
extern void anctrl_start(void *);
extern void func_8008B188(void *, s32);
extern void func_800D7754(Actor *, s32);
extern void func_80101D4C(Actor *);
extern void func_80101D7C(Actor *);
extern void func_800DA3B8(s32, s32);
extern void func_800C04C8(s32, s32, s32, s32, void (*)());
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800D7708(s32, f32, s32);
extern f32 func_800C7AE4(s32, f32, f32);

// Matching: needed for the match.
typedef union {
    Actor *ptr;
    s32 word;
} SplineActorArg;

// Jiggy-count dialog callback.
s32 glsplinenode_entrypoint_0(s32 unk_0, s32 unk_1, s32 unk_2)
{
    func_800D035C(1);
}

// Handles one node passed by the path follower; returns 2 when the actor was moved to another node.
s32 glsplinenode_entrypoint_1(SplineNodeContext *set, SplineActorArg actor,
                              SplineNode *node, SplineNodeList *list)
{
    SplineNodeState *state;
    s32 result;
    s32 new_path_index;
    s32 has_angles;
    // Matching: constant kept in a local for the match.
    s32 one = 1;
    f32 new_t;
    f32 new_pos[3];
    f32 new_yaw;
    f32 new_pitch;
    void *anim;
    SplineNode *target;
    SplineNode *nodes_end;

    state = func_80105494(actor.ptr);
    result = 0;
    if (node->data2.common.is_event) {
        switch (node->data1.common.type) {
            case 0:
                if (node->data2.event.script_id) {
                    state->script_id = node->data2.event.script_id;
                    state->script_time = set->unk_190;
                    state->script_pos = 0;
                    state->unk_5 = 0.0f;
                }
                break;
            case 7:
                if (node->data3.common.unk_3 == 1) {
                    ((SplineNodeActorFlags *) actor.ptr)->unk_78 =
                        node->data1.event.unk_0 == 0
                            ? 2
                            : (one == node->data1.event.unk_0 ? 1 : 0);
                    if (node->data1.event.unk_1) {
                        ((SplineNodeActorMotionData *) actor.ptr->actorData)->unk_0 =
                            node->data1.event.unk_1 * 0.25f;
                    } else {
                        ((SplineNodeActorMotionData *) actor.ptr->actorData)->unk_0 = 0.0f;
                    }
                    ((SplineNodeActorMotionData *) actor.ptr->actorData)->unk_4 = 0.0f;
                }
                if (node->data2.event.unk_1 == 1) {
                    func_800C04C8(node->data2.event.unk_2,
                                  node->data3.event.unk_0,
                                  node->data1.event.unk_2,
                                  node->data1.event.unk_3, _glsplinenode_entrypoint_0);
                }
                break;
            case 6:
                func_800DA3B8(node->data1.raw[0], 1);
            case 2:
            case 3:
            case 4:
            case 5:
                break;
        }
        if (node->data2.common.value) {
            has_angles =
                _glsplinefuncs_entrypoint_0(node->data2.common.value, &new_path_index, &new_t,
                                            new_pos, state->path_index, &new_yaw, &new_pitch);
            result = 2;
            state->path_index = new_path_index;
            state->path_t = new_t;
            func_800EE7F8(actor.ptr->position, new_pos);
            if (has_angles) {
                if (new_yaw != -9999.0f) {
                    actor.ptr->rotation[1] = new_yaw;
                    actor.ptr->unk54 = actor.ptr->rotation[1];
                }
                if (new_pitch != -9999.0f) {
                    actor.ptr->rotation[0] = new_pitch;
                    actor.ptr->unk50 = actor.ptr->rotation[0];
                }
            }
        }
    } else {
        if (node->unk_6) {
            if (node->data3.common.unk_2) {
                state->unk_16 = node->data2.common.value - 0x69;
            } else {
                state->unk_11 = (f32) node->data2.common.value / 4;
            }
        }
        if (node->set_anim) {
            anim = func_80104248(actor.ptr);
            state->anim_duration = (f32) node->anim_time / 4;
            state->anim_id = _seqdat_entrypoint_0(node->anim_seq, 0);
            if (!anim) {
                anim = func_801042B8(actor.ptr);
                anctrl_reset(anim);
            }
            anctrl_setIndex(anim, state->anim_id);
            anctrl_setDuration(anim, state->anim_duration);
            func_8008B188(anim, 1);
            if (anim) {
                anctrl_start(anim);
            }
        }
        func_800D7754(actor.ptr, node->data1.common.unk_4);
        // Matching: the self-assignments in the branches below are needed for the match.
        switch (node->data1.common.type) {
            case 2:
                state->follow_mode = 0;
                if (state->speed < 0.0f) {
                    state->speed = -state->speed;
                } else {
                    state->speed = state->speed;
                }
                func_80101D4C(actor.ptr);
                break;
            case 3:
                state->follow_mode = 0;
                if (state->speed < 0.0f) {
                    state->speed = state->speed;
                } else {
                    state->speed = -state->speed;
                }
                func_80101D4C(actor.ptr);
                break;
            case 4:
                state->follow_mode = 1;
                if (state->speed < 0.0f) {
                    state->speed = -state->speed;
                } else {
                    state->speed = state->speed;
                }
                func_80101D7C(actor.ptr);
                break;
            case 5:
                state->follow_mode = 1;
                if (state->speed < 0.0f) {
                    state->speed = state->speed;
                } else {
                    state->speed = -state->speed;
                }
                func_80101D7C(actor.ptr);
                break;
            case 6:
                state->follow_mode = 2;
        }
        if (node->data1.common.speed_class) {
            state->unk_18 = D_808009B0_glsplinenode[node->data1.common.speed_class];
        }
        if (state->unk_24 != node->data3.common.unk_1) {
            state->unk_24 = node->data3.common.unk_1;
        }
        if (node->unk_5) {
            state->speed =
                func_800D7708(state->path_index, state->path_t, node->data2.common.unk_1);
        }
        if (node->data1.common.target_id) {
            nodes_end = list->count + &list->nodes[0];
            for (target = &list->nodes[0];
                 target->data3.common.id != node->data1.common.target_id &&
                 target < nodes_end;
                 target++) {
            }
            state->seg_flags = node->data1.common.seg_flags;
            state->unk_33 = 0;
            state->seg_t_start = node->t;
            state->seg_t_end = target->t;
            if (node->data1.common.seg_flags & 1) {
                state->seg_yaw_start = node->data2.common.yaw;
                state->seg_yaw_end = target->data2.common.yaw;
                state->seg_pitch_start = node->data1.common.pitch;
                state->seg_pitch_end = target->data1.common.pitch;
                actor.ptr->rotation[1] = actor.ptr->unk54 = state->seg_yaw_start;
                actor.ptr->rotation[0] = actor.ptr->unk50 = state->seg_pitch_start;
            }
            if (node->data1.common.seg_flags & 2) {
                state->seg_speed_start = state->speed;
                state->seg_speed_end =
                    func_800C7AE4(func_800D7520(state->path_index), target->t, 1.0f) /
                    ((f32) target->data2.common.unk_1 / 4);
            }
        }
        if (!state->unk_15 && !state->unk_22 && !state->unk_17) {
            if (state->unk_13) {
                actor.ptr->unk54 = node->data2.common.yaw;
            }
            if (state->unk_14) {
                actor.ptr->unk50 = node->data1.common.pitch;
            }
        }
    }
    return result;
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
s16 D_808009B0_glsplinenode[8] = {0x0, 0x5, 0x6, 0x7, 0x0, 0x0, 0x0, 0x0};
