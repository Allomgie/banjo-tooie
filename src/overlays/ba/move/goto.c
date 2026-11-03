#include "common.h"

#define GD (*(GotoData **) ((u8 *) param_0 + 0xC8))
extern void baphysics_set_target_horizontal_velocity(Actor *, f32);
extern void func_8009C0F8(Actor *, s32);
struct bamovegoto_unkC8 {
    u8 pad7C[0x7C];
    s32 callback;
    s32 easing;
};
struct bamovegoto {
    u8 padC8[0xC8];
    struct bamovegoto_unkC8 *data;
};
extern void baphysics_set_type();
typedef struct {
    u8 pad0[4];
    f32 pos[3];
    f32 vel[3];
    u8 pad1C[0xC];
    f32 step[3];
    f32 gravity_accel;
    f32 min_vel_y;
    u8 pad3C[0x18];
    u8 state;
    u8 timed;
    u8 gravity;
    u8 pad57;
    f32 target[3];
    f32 start[3];
    f32 duration;
    f32 time;
    f32 speed;
    void (*callback)(Actor *, f32 *, f32);
    f32 (*easing)(Actor *, f32);
} GotoData;
extern void func_8009C128(Actor *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEFFC(f32 *);
extern void func_8009BA9C(Actor *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EE7F8();
extern f32 func_800F1214(f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern f32 func_800EEF94(f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);

// Sets the mover state; idle and arrived (0, 6) also stop horizontal motion.
void func_80800000_bamovegoto(Actor *actor, s32 state)
{
    if ((state == 0) || (state == 6)) {
        baphysics_set_target_horizontal_velocity(actor, 0);
        func_8009BA9C(actor, 0);
    }
    *(s8 *) ((char *) *(u8 **) ((char *) actor + 0xC8) + 0x54) = (s8) state;
}

void bamovegoto_entrypoint_0(u8 *actor)
{
    // Matching: the offset temporary is needed for the match.
    int duration_off;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x80) = 0;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x7C) = 0;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x78) = 0.0f;
    duration_off = 0x70;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x55) = 1;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x56) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x54) = 0;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + duration_off) = 1.0f;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x74) = 0;
    func_800EFD24(*(u8 **) ((s8 *) actor + 0xC8) + 0x58, actor);
    func_800EFD24(*(u8 **) ((s8 *) actor + 0xC8) + 0x64, actor);
}

void bamovegoto_entrypoint_1(Actor *actor)
{
    s32 dst;
    s32 *data_ptr = (s32 *) ((char *) actor + 0xC8);
    dst = data_ptr[0] + 4;
    func_800EE7F8(dst, data_ptr[0] + 0x64);
    func_8009C0F8(actor, data_ptr[0] + 0x64);
    func_80800000_bamovegoto(actor, 6);
}

f32 bamovegoto_entrypoint_2(u8 *actor)
{
    return *(f32 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x74);
}

void bamovegoto_entrypoint_3(u8 *actor)
{
    s32 data;

    data = *(s32 *) ((s8 *) actor + 0xC8);
    func_800EEAD4(data + 0x58, data + 0x64);
}

s32 bamovegoto_entrypoint_4(u8 *actor)
{
    return *(u8 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x54) == 6;
}

void bamovegoto_entrypoint_5(s32 actor)
{
    func_80800000_bamovegoto(actor, 0);
}

void bamovegoto_entrypoint_6(void *actor)
{
    *(s8 *) (*(s32 **) ((char *) actor + 0xC8) + (0x54 / 4)) = 0;
}

int bamovegoto_entrypoint_7(s32 actor, f32 duration)
{
    // Matching: the copy of the parameter is needed for the match.
    int actor_copy;
    actor_copy = actor;
    *(f32 *) (*(s32 *) ((char *) actor_copy + 200) + 112) = duration;
}

int bamovegoto_entrypoint_8(s32 actor, f32 speed)
{
    // Matching: the dead expression statement is needed for the match.
    0;
    *(f32 *) (*(s32 *) (actor + 0xC8) + 0x78) = speed;
}

void bamovegoto_entrypoint_9(void *actor, s32 timed)
{
    ((s8 *) *(void **) ((char *) actor + 0xC8))[85] = timed;
}

void bamovegoto_entrypoint_10(void *actor, s32 gravity)
{
    ((s8 *) *(void **) ((char *) actor + 0xC8))[86] = gravity;
}

void bamovegoto_entrypoint_11(struct bamovegoto *actor, s32 easing, s32 callback)
{
    actor->data->easing = easing;
    actor->data->callback = callback;
}

void bamovegoto_entrypoint_12(Actor *actor)
{
    // Matching: the extra pointer temporaries are needed for the match.
    char *base_copy;
    char *offset_ptr;
    char *base;
    offset_ptr = (base = (char *) actor) + 0x58;
    base_copy = base;
    func_800EE7F8(*(s32 *) ((char *) base_copy + 200) + 100);
}

void bamovegoto_entrypoint_13(u8 *actor)
{
    baphysics_set_type(actor, 0xC);
    if ((*(u8 **) (actor + 0xC8))[0x55] == 1) {
        func_80800000_bamovegoto(actor, 2);
    } else {
        func_80800000_bamovegoto(actor, 4);
    }
}

// Per-frame update. States 2-3: timed interpolation; 4-5: constant speed; 6: arrived.
void bamovegoto_entrypoint_14(Actor *param_0)
{
    f32 t;
    f32 eased;
    f32 delta[3];
    f32 prev_pos[3];
    f32 dt;
    f32 to_start[3];

    switch (GD->state) {
        case 2:
            func_8009C128(param_0, GD->target);
            if (GD->speed != 0) {
                func_800EFB24(delta, GD->start, GD->target);
                GD->duration = func_800EEFFC(delta) / GD->speed;
            }
            GD->time = 0.0f;
            func_8009BA9C(param_0, 0);
            baphysics_set_target_horizontal_velocity(param_0, 0);
            func_80800000_bamovegoto(param_0, 3);
            break;
        case 3:
            GD->time += func_800D8FF8();
            t = func_800F10B4(GD->time, 0.0f, GD->duration, 0.0f, 1.0f);
            if (GD->easing != NULL) {
                eased = GD->easing(param_0, t);
            } else {
                eased = t;
            }
            func_800EE7F8(prev_pos, GD->pos);
            GD->pos[0] = func_800F1214(eased, GD->target[0], GD->start[0]);
            GD->pos[1] = func_800F1214(eased, GD->target[1], GD->start[1]);
            GD->pos[2] = func_800F1214(eased, GD->target[2], GD->start[2]);
            if (GD->callback != NULL) {
                GD->callback(param_0, GD->pos, t);
            }
            func_800EFB24(GD->vel, GD->pos, prev_pos);
            func_800EF334(GD->vel, 1.0f / func_800D8FF8());
            baphysics_set_target_horizontal_velocity(param_0, func_800EEF94(GD->vel));
            if (t == 1.0f) {
                func_80800000_bamovegoto(param_0, 6);
            }
            break;
        case 4:
            func_8009C128(param_0, GD->target);
            func_80800000_bamovegoto(param_0, 5);
            break;
        case 5:
            dt = func_800D8FF8();
            func_800EFB24(to_start, GD->start, GD->pos);
            to_start[1] = 0;
            if (func_800EEFFC(to_start) <= GD->speed * dt) {
                func_80800000_bamovegoto(param_0, 6);
            } else {
                func_800EF368(to_start, GD->speed);
            }
            GD->vel[0] = to_start[0];
            GD->vel[2] = to_start[2];
            if (GD->gravity) {
                GD->vel[1] += GD->gravity_accel * dt;
                if (GD->vel[1] < GD->min_vel_y) {
                    GD->vel[1] = GD->min_vel_y;
                }
            }
            func_800EFA20(GD->step, GD->vel, dt);
            baphysics_set_target_horizontal_velocity(param_0, func_800EEF94(GD->vel));
            func_800EF04C(GD->pos, GD->step);
        case 0:
        case 6:
            break;
    }
}
