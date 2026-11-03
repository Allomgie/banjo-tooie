#include "common.h"

typedef struct {
    s32 ground_tracker;
    f32 y_offset;  // raised sweep offset
    f32 radius;  // collision radius
    u8 pad_C[8];
    s32 filter;  // collision filter, ORed with 0x20020
    u8 pad_18[4];
    u8 *contact_tri;  // last contact triangle
    u8 unk_20[0x24];
    f32 contact_normal[3];  // last contact normal
    u8 pad_50[4];
    s8 stuck;
    u8 contact_count;
    u8 on_ground;
    u8 unk_57;
} CollisionStateD4584;
extern f32 func_800C6784(s32);
extern void func_800C675C(s32, f32 *);
extern f32 mlAbsF(f32);
typedef struct {
    f32 dest[3];  // corrected destination
    f32 start[3];  // sweep start
    u8 *tri;  // contact triangle
    f32 normal[3];  // contact normal
    f32 raised_dest[3];  // destination plus y_offset
    f32 raised_start[3];  // start plus y_offset
    s32 pre_hit;  // preliminary sweep hit
    f32 pre_data[3][3];  // preliminary collision data, row 0 is the normal
    f32 tri_verts[3][3];  // contact triangle vertices
    s32 on_ground;  // snapshot of the state flag
} CollisionRecordD4584;
extern void func_800FAE44(void *, void *, f32, f32, s32, s32);
extern s32 func_800FABF4(void *, void *, void *, s32, f32, f32);
extern void *func_800C6B78(void *, void *, f32, void *, s32, s32);
extern void *func_800FB434(void *, void *, f32, f32, void *, s32, s32);
extern void func_800FAF78(void *, void *, void *, void *, void *);
extern void func_800F0524(void *, void *, void *);
extern void func_800F0410(void *, void *, void *);
extern s32 func_800F0CB4(void *, void *, void *, void *);
extern void func_800EE7F8(void *, void *);
extern void func_800EE780(void *, void *, void *);
extern void func_800EFB24(void *, void *, void *);
extern void func_800EF2A0(void *);
extern void func_800EF368(void *, f32);
extern void func_800EFA20(void *, void *, f32);
extern void func_800EFA4C(void *, f32, f32, f32);
extern s32 func_800EEF24(void *);
extern void func_800EF04C(void *, void *);
extern f32 func_800C673C(s32);
extern void func_800EA600();
extern void func_800C68AC(s32 param_0, s32 param_1);
extern void func_800C68CC();
extern void func_800C65E0();
extern void func_800EA614(void);
void func_800D4D5C();

// Snaps pos to the tracked ground surface when it is close enough.
void func_800D4400(CollisionStateD4584 *state, f32 *pos, f32 *delta)
{
    f32 ground_normal[3];
    f32 ground;
    s32 was_on_ground;

    func_800D4D5C(pos, state);
    ground = func_800C6784(state->ground_tracker);
    func_800C675C(state->ground_tracker, ground_normal);
    was_on_ground = state->on_ground;
    state->on_ground = 0;
    // Too steep to snap to.
    if (ground_normal[1] < 0.432f) {
        return;
    }
    if (pos[1] <= ground) {
        pos[1] = ground;
        state->on_ground = 1;
        return;
    }
    if (was_on_ground == 0) {
        return;
    }
    if (!(delta[1] < 0.0f)) {
        return;
    }
    // Snap range above ground: 30 on gentle slopes, 5 on steeper ones.
    if (ground_normal[1] < 0.9f) {
        if (pos[1] < ground + 30.0f) {
            pos[1] = ground;
            state->on_ground = 1;
        }
    } else {
        if (pos[1] < ground + 5.0f) {
            pos[1] = ground;
            state->on_ground = 1;
        }
    }
}

int func_800D4534(s32 verts, u8 *tri)
{
    if (!tri) {
        return 0;
    }
    func_800AAD28(verts);
    return 1;
}

void func_800D4564()
{
    func_800AAD28();
}

// Character move-and-slide: up to 5 swept-sphere passes from prev_pos towards pos,
// sliding along the contact normals. Writes the result to pos.
void func_800D4584(CollisionStateD4584 *state, f32 *prev_pos, f32 *pos, f32 *delta)
{
    f32 push[3];
    s32 hit;
    f32 pushed_pos[3];
    CollisionRecordD4584 *prev_pass;
    f32 vec[3];
    f32 tmp_pos[3];
    u8 *hit_tri;
    f32 saved_dest[3];
    s32 i;
    CollisionRecordD4584 passes[5];
    f32 *data;
    CollisionRecordD4584 *pass;
    f32 threshold;
    f32 saved_y;
    f32 probe_pos[3];
    f32 up[3];
    s32 needs_push;
    f32 tmp_f;
    s32 filter_mask;
    f32 start_pos[3];
    f32 tri_pos[3];
    f32 push_dir[3];
    // Matching: removing this unused local shifts IDO's stack slots.
    s32 unk_0;
    if (func_800DA298(0x664) == 0) {
        filter_mask = state->filter;
        func_800FAE44(prev_pos, pushed_pos, state->radius, state->y_offset, 1, filter_mask | 0x20020);
        for (i = 0; i < 5; i++) {
            pass = &passes[i];
            if (i != 0) {
                prev_pass = pass - 1;
            } else {
                prev_pass = NULL;
            }
            if (i != 0) {
                func_800EE7F8(pass, prev_pass);
                func_800EE7F8(pass->start, prev_pass->start);
            } else {
                func_800EE7F8(pass, pos);
                func_800EE7F8(pass->start, prev_pos);
            }
            func_800EE7F8(saved_dest, pass);
            func_800EFB24(vec, pass, pass->start);
            // Long moves get a preliminary sweep; outward-facing hits are rejected.
            if ((vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]) >
                100.0f) {
                saved_y = pass->dest[1];
                data = pass->pre_data[0];
                hit = func_800FABF4(pass->start, pass, data, (filter_mask | 0x20020),
                                        state->radius - 1.0f, state->y_offset);
                pass->pre_hit = hit;
                if (hit != 0) {
                    func_800EF2A0(vec);
                    tmp_f = vec[0] * pass->pre_data[0][0] +
                               vec[1] * pass->pre_data[0][1] +
                               vec[2] * pass->pre_data[0][2];
                    if (tmp_f > 0) {
                        pass->pre_hit = 0;
                        func_800EE7F8(pass, saved_dest);
                    }
                }
                if (pass->pre_hit != 0) {
                    if ((pass->pre_data[0][1] >= 0) && (pass->pre_data[0][1] < 0.02f)) {
                        if (state->ground_tracker != 0) {
                            threshold = func_800C673C(state->ground_tracker) - 1.0f;
                            if (threshold <= mlAbsF(saved_y - pass->dest[1])) {
                                pass->pre_hit = func_800FABF4(
                                    pass->start, pass, data, (filter_mask | 0x20020),
                                    (state->radius - 1.0f), state->y_offset);
                                saved_y = pass->dest[1];
                            }
                        }
                        pass->dest[1] = saved_y;
                    }
                }
            } else {
                pass->pre_hit = 0;
            }
            if (state->ground_tracker != 0) {
                func_800D4400(state, pass, delta);
            }
            pass->on_ground = (s32) state->on_ground;
            pass->raised_start[0] = pass->start[0];
            pass->raised_start[1] = pass->start[1] + state->y_offset;
            pass->raised_start[2] = pass->start[2];
            pass->raised_dest[0] = pass->dest[0];
            pass->raised_dest[1] = pass->dest[1] + state->y_offset;
            pass->raised_dest[2] = pass->dest[2];
            hit_tri = func_800C6B78(pass->raised_start, pass->raised_dest, state->radius,
                                    pass->normal, 3, (filter_mask | 0x20020));
            pass->tri = hit_tri;
            if (hit_tri != NULL) {
                func_800D4564(state->unk_20);
                state->contact_count = (u8) (state->contact_count + 1);
                state->contact_tri = (u8 *) pass->tri;
                func_800EE7F8(state->contact_normal, pass->normal);
                // Third pass: repeated contacts need a combined normal, otherwise the character
                // oscillates between the same two surfaces.
                if (i == 2) {
                    if ((pass->tri == passes[0].tri) &&
                        (pass->tri != prev_pass->tri)) {
                        func_800EE780(vec, pass->normal, prev_pass->normal);
                        func_800EF2A0(vec);
                        func_800EE7F8(pass->normal, vec);
                    }
                }
                if (i == 2) {
                    if (pass->tri == passes[0].tri) {
                        data = pass->tri_verts[0];
                        if ((pass->tri == prev_pass->tri) &&
                            (func_800D4534(data, pass->tri) != 0)) {
                            func_800F0524(vec, data, pass);
                            func_800EFB24(push, pass, vec);
                            func_800EF368(push, state->radius + 1);
                            vec[0] += push[0];
                            vec[1] += push[1];
                            vec[2] += push[2];
                            if (!(*(s32 *) ((char *) pass->tri + 8) & 0x10000)) {
                                pass->tri = func_800FB434(
                                    vec, pass, state->y_offset, state->radius,
                                    pass->normal, 3, (filter_mask | 0x20020));
                            } else {
                                func_800EE7F8(pass, vec);
                            }
                        }
                    }
                }
                if ((pass->on_ground == 0) && (pass->tri != NULL) &&
                    (*(f32 *) ((char *) delta + 4) < 0.0f)) {
                    data = pass->tri_verts[0];
                    if ((mlAbsF(pass->normal[1]) < 0.01f) &&
                        (func_800D4534(data, pass->tri) != 0)) {
                        func_800F0524(vec, data, pass);
                        func_800EFA20(push, pass->normal, state->radius + 1);
                        func_800EE780(tmp_pos, vec, push);
                        pass->tri =
                            func_800FB434(tmp_pos, vec, state->y_offset, state->radius,
                                          pass->normal, 3, (filter_mask | 0x20020));
                        pass->dest[0] = vec[0];
                        pass->dest[2] = vec[2];
                    }
                }
                // Tooie-specific slope correction: test the vertical projection, then push
                // horizontally away from the contact if necessary.
                if (0.6f < pass->normal[1]) {
                    data = pass->tri_verts[0];
                    if (state->radius != state->y_offset) {
                        if (func_800D4534(data, pass->tri) != 0) {
                            needs_push = 1;
                            func_800EE7F8(probe_pos, pass);
                            func_800EFA4C(up, 0.0f, 1.0f, 0.0f);
                            if ((func_800F0CB4(probe_pos, up, data, pass->normal) !=
                                 0) &&
                                (mlAbsF(pass->dest[1] - probe_pos[1]) < 0.01f)) {
                                needs_push = 0;
                            }
                            if (needs_push != 0) {
                                func_800EE7F8(start_pos, pass->start);
                                func_800F0410(tri_pos, data, pass->raised_dest);
                                func_800EFB24(push_dir, start_pos, tri_pos);
                                push_dir[1] = 0.0f;
                                func_800EF2A0(push_dir);
                                if (func_800EEF24(push_dir) != 0) {
                                    func_800EE7F8(pass->normal, push_dir);
                                    func_800EE7F8(pass->start, prev_pos);
                                    tmp_f = (f32) (i + 1);
                                    func_800EF368(push_dir, tmp_f * tmp_f * 2);
                                    func_800EF04C(pass, push_dir);
                                    func_800EF04C(pass->raised_dest, push_dir);
                                }
                            }
                        }
                    }
                }
                if (func_800EEF24(pass->normal) != 0) {
                    func_800FAF78(pass->start, pass, pass->raised_start, pass->raised_dest,
                                  pass->normal);
                }
            } else {
                break;
            }
        }
        if ((i == 5) && (state->on_ground == 0) && (state->contact_tri != NULL) &&
            (*(f32 *) ((char *) pos + 4) < *(f32 *) ((char *) prev_pos + 4))) {
            state->stuck = 1;
        }
        if (i == 5) {
            func_800EE7F8(pos, pushed_pos);
            return;
        }
        func_800EE7F8(pos, pass);
    }
}

// Refreshes the ground tracker attached to state.
void func_800D4D5C(pos, state) s32 pos;
u8 *state;
{
    func_800EA600(*(s32 *) ((s8 *) state + 0xC));
    (*(s32(**)(u8 *))((s8 *) state + 0x10))(state);
    func_800C68AC(*(s32 *) ((s8 *) state + 0), pos);
    func_800C68CC(*(s32 *) ((s8 *) state + 0), *(s32 *) ((s8 *) state + 0x14));
    func_800C65E0(*(s32 *) ((s8 *) state + 0));
    func_800EA614();
}
