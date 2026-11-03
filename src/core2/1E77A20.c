#include "core2/1E77A20.h"

// Two units: collision spheres (PlayerState+0x114, three entries of 0x28 bytes)
// and the player state machine core (PlayerState+0x120).

typedef struct {
    f32 radius;
    u8 pad_4[36];
} E40_9E138;
typedef struct {
    s32 pad_0;
    s16 bone;
    s16 pad_6;
    void (*callback)(PlayerState *, f32 *, s16);
    f32 offset[3];
    f32 height, unk_1C, unk_20, unk_24;
} Attachment9E154;
typedef struct {
    u8 pad_0[0x114];
    Attachment9E154 *spheres;
} Player9E154;
extern void func_80092CDC();
extern void func_8009C128(PlayerState *, f32 *);
extern void func_80092D18(PlayerState *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EF8BC(f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern s32 func_800EEEA8(f32 *);
extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern f32 func_800136E4(f32);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
extern void func_80096394(PlayerState *, f32 *);
extern s32 func_8009CA70(void *, void *, s32);
extern s32 func_8009CBDC(PlayerState *, s32);
typedef struct {
    u8 pad_0[0x120];
    PlayerState *state;
} Struct8009E74C;
typedef struct {
    s16 unk_0;
    s16 unk_2;
    s32 current;
    s16 unk_8;
    s16 unk_A;
    s16 interrupt;
    s16 result;
} F8009E7C8;
extern void *func_8009CB44();

s32 func_8009E130()
{
    return 0xF4;
}

// Returns the collision sphere radius.
f32 func_8009E138(PlayerState *player, s32 sphere)
{
    return (*(E40_9E138 **) ((u8 *) player + 0x114))[sphere].radius;
}

// World position of a collision sphere: bone anchor (or callback) plus the rotated local offset, extra height and orbit.
void func_8009E154(PlayerState *player, s32 sphere, f32 *out_pos)
{
    f32 pos[3], orbit[3], base[3], rel_pos[3], unk_0[3], unk_1[3];
    f32 angle;
    if (((Player9E154 *) player)->spheres[sphere].callback) {
        ((Player9E154 *) player)
            ->spheres[sphere]
            .callback(player, pos, ((Player9E154 *) player)->spheres[sphere].bone);
    } else {
        func_80092CDC(player, pos, ((Player9E154 *) player)->spheres[sphere].bone);
        func_8009C128(player, base);
        func_80092D18(player, unk_0);
        func_800EF04C(base, unk_0);
        if (func_800EEEA8(pos)) {
            func_800EE7F8(rel_pos, ((Player9E154 *) player)->spheres[sphere].offset);
            func_800EF8BC(rel_pos, rel_pos, func_8009BFCC(player));
            func_800EF934(rel_pos, rel_pos, yaw_get(player));
            func_800EE780(pos, base, rel_pos);
        } else {
            func_800EFB24(rel_pos, pos, base);
            func_800EF934(rel_pos, rel_pos, -yaw_get(player));
            func_800EF8BC(rel_pos, rel_pos, -func_8009BFCC(player));
            func_800EE7F8(((Player9E154 *) player)->spheres[sphere].offset, rel_pos);
        }
    }
    pos[1] += ((Player9E154 *) player)->spheres[sphere].height;
    if (((Player9E154 *) player)->spheres[sphere].unk_1C != 0.0f) {
        angle =
            func_800136E4(yaw_get(player) + ((Player9E154 *) player)->spheres[sphere].unk_24);
        func_800EF4E4(orbit, ((Player9E154 *) player)->spheres[sphere].unk_20, angle, 0.0f,
                      0.0f, ((Player9E154 *) player)->spheres[sphere].unk_1C);
        func_800EF04C(pos, orbit);
    }
    func_80096394(player, unk_1);
    func_800EF04C(pos, unk_1);
    func_800EE7F8(out_pos, pos);
}

void func_8009E388(s32 arg0)
{
}

// Resets the three spheres to the defaults: bones 1/2/3, radii 32/28/0.
void func_8009E390(u8 *player)
{
    s32 i;
    u8 *entry;

    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x114) + 0xF0) = 0;
    for (i = 0; i < 3; i++) {
        entry = *(u8 **) ((s8 *) player + 0x114) + i * 0x28;
        *(f32 *) ((s8 *) entry + 0) = 0.0f;
        *(s16 *) ((s8 *) entry + 4) = 0;
        *(s32 *) ((s8 *) entry + 8) = 0;
        *(f32 *) ((s8 *) entry + 0x20) = 0.0f;
        *(f32 *) ((s8 *) entry + 0x24) = 0.0f;
        *(f32 *) ((s8 *) entry + 0x1C) = 0.0f;
        *(f32 *) ((s8 *) entry + 0x18) = 0.0f;
        func_800EFD24(entry + 0xC);
    }
    func_8009E5A4(player, 0, 1);
    func_8009E5A4(player, 1, 2);
    func_8009E5A4(player, 2, 3);
    func_8009E55C(player, 0, 32.0f);
    func_8009E55C(player, 1, 28.0f);
    func_8009E55C(player, 2, 0);
}

// Restores the saved sphere set.
void func_8009E474(PlayerState *player)
{
    u8 *spheres;
    spheres = *(u8 **) ((s8 *) player + 0x114);
    rare_memcpy(spheres, spheres + 0x78, 0x78);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x114) + 0xF0) = 0;
}

// Saves the current sphere set.
void func_8009E4AC(PlayerState *player)
{
    u8 *spheres;
    *(s8 *) (*(u8 **) ((u8 *) player + 0x114) + 0xF0) = 1;
    spheres = *(u8 **) ((u8 *) player + 0x114);
    rare_memcpy(spheres + 0x78, spheres, 0x78);
}

// Sets the sphere's anchor callback.
void func_8009E4E0(s32 *player, s32 sphere, s32 callback)
{
    typedef struct {
        s32 pad_0[2];
        s32 callback;
        s32 pad_C[7];
    } Struct8009E4E0;

    ((Struct8009E4E0 *) player[0x45])[sphere].callback = callback;
}

void func_8009E4FC(u8 *player, s32 sphere, f32 unk_0, f32 unk_1, f32 unk_2)
{
    s32 offset;

    offset = sphere * 0x28;
    *(f32 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x114) + offset) + 0x20) = unk_0;
    *(f32 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x114) + offset) + 0x24) = unk_1;
    *(f32 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x114) + offset) + 0x1C) = unk_2;
}

// Sets the sphere's extra height.
void func_8009E53C(PlayerState *player, s32 sphere, f32 height)
{
    *(f32 *) (((u8 *) *(s32 **) ((u8 *) player + 0x114) + (sphere * 0x28)) + 0x18) = height;
}

// Sets the radius; a radius of 0 also clears the anchor callback.
void func_8009E55C(PlayerState *player, s32 sphere, f32 radius)
{
    (*(E40_9E138 **) ((u8 *) player + 0x114))[sphere].radius = radius;
    if (radius == 0.0f) {
        func_8009E4E0(player, sphere, 0);
    }
}

// Sets the model bone the sphere is anchored to.
void func_8009E5A4(player, sphere, bone) PlayerState *player;
s32 sphere;
s32 bone;
{
    s32 offset = (sphere * 5) * 8;
    *(u16 *) ((char *) (*(s32 **) ((char *) player + 0x114)) + offset + 4) = bone;
}

s32 func_8009E5C0()
{
    return 0x14;

}

void (*func_8009CAAC(PlayerState *, BanjoStateId))(PlayerState *);
void (*func_8009CAF8(PlayerState *, BanjoStateId))(PlayerState *);

// Runs the exit hook of the current state, switches state, then runs the enter hook.
void bs_setState(PlayerState *self, BanjoStateId nextState)
{
    if (nextState != BS_STATE_0_INVALID) {
        self->state->next = nextState;
        if (func_8009CAAC(self, self->state->current) != NULL) {
            func_8009CAAC(self, self->state->current)(self);
        }
        self->state->previous = self->state->current;
        self->state->current = self->state->next;
        self->state->next = NULL;
        if (func_8009CAF8(self, self->state->current) != NULL) {
            func_8009CAF8(self, self->state->current)(self);
        }
    }

}

int func_8009E674(s32 player, s32 unk_0)
{
    func_8009CA70(player, *((PlayerState ***) (*((s32 *) (((char *) player) + 0x120)) + 4)),
                  unk_0);
}

s32 func_8009E69C(PlayerState *player, s32 unk_0)
{
    func_8009CA70(player, *((void **) ((char *) *(void **) ((char *) player + 0x120) + 8)),
                  unk_0);
}

s32 func_8009E6C4(PlayerState *player, s32 unk_0)
{
    func_8009CA70(player, *((PlayerState ***) (*((s32 *) (((char *) player) + 0x120)))), unk_0);
}

// Returns the last interrupt code.
s16 func_8009E6EC(PlayerState *self)
{
    return self->state->unkC;
}

s32 bs_getCurrentState(PlayerState *self)
{
    return self->state->current;
}

s32 bs_getNextState(PlayerState *self)
{
    return self->state->next;
}

s32 bs_getPreviousState(PlayerState *self)
{
    return self->state->previous;
}

s32 func_8009E71C(PlayerState *player, s32 state_class)
{
    return func_8009CBDC(player, *(s32 *) ((*(u8 **) ((u8 *) player + 0x120)) + 4)) == state_class;
}

s32 func_8009E74C(PlayerState *player, s32 state_class)
{
    s32 cls;
    cls = func_8009CBDC(player, *(s32 *) ((u8 *) ((Struct8009E74C *) player)->state + 8));
    return cls == state_class;
}

s32 func_8009E77C(PlayerState *player, s32 state_class)
{
    return func_8009CBDC(player, *(*((s32 **) (((char *) player) + 0x120)))) == state_class;
}

// Clears the three state ids.
void func_8009E7AC(u8 *player)
{
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x120)))) + (0))) = 0;
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x120)))) + (4))) = 0;
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x120)))) + (8))) = 0;
}

// Delivers an interrupt: stores the code, calls the current state's handler, returns the result.
s32 func_8009E7C8(u8 *player, s32 code)
{
    (*(F8009E7C8 **) (player + 0x120))->interrupt = code;
    (*(F8009E7C8 **) (player + 0x120))->result = 1;

if (func_8009CB44(player, (*(F8009E7C8 **) (player + 0x120))->current) != NULL) {
    ((void (*)(u8 *)) func_8009CB44(player, (*(F8009E7C8 **) (player + 0x120))->current))(player);
}

return (*(F8009E7C8 **) (player + 0x120))->result;
}

// Sets the interrupt result.
void func_8009E830(PlayerState *player, s32 result)
{
    *(s16 *) ((char *) (*(struct bs_state_s **) ((char *) player + 0x120)) + 0xE) = result;
}

void func_8009E83C(s32 player)
{
    s32 (*handler)(s32);
    handler = (*(*(s32 **) (player + 0x120) + 1));
    handler = func_8009CB90(player, handler);

if (handler) {
    handler(player);
}

}
