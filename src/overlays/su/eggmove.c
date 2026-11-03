#include "common.h"

extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void *func_80100094();
extern void _sueggmove_entrypoint_0();
extern void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800F0E00(f32, f32);
extern void func_800EE7F8();
void sueggmove_entrypoint_8();

// Integrates gravity into the vertical speed and writes the stepped position to new_pos.
void func_80800000_sueggmove(Actor *actor, f32 *pos, f32 *new_pos)
{
    f32 dt;
    f32 step[3];

    dt = func_800D8FF8();
    *(f32 *) &actor->actorData[5] += *(f32 *) &actor->actorData[7] * dt;
    if (*(f32 *) &actor->actorData[5] < actor->unk54 * dt) {
        *(f32 *) &actor->actorData[5] = actor->unk54 * dt;
    }
    func_800EFA20(step, (f32 *) &actor->actorData[4], dt);
    func_800EE780(new_pos, pos, step);
}

// Sets the owner link.
int sueggmove_entrypoint_0(s32 owner, s32 unk_1)
{
    Actor *actor;
    // Matching: the no-op `| 0` and the empty block are needed for the match.
    actor = func_80106790(unk_1 | 0);
    if (unk_1) {
    }
    actor->unk3C = owner;
}

// Returns the owner link.
int sueggmove_entrypoint_1()
{
    Actor *actor = func_80106790();
    return actor->unk3C;
}

// Returns the last surface type.
s32 sueggmove_entrypoint_2(void)
{
    return *(s32 *) ((s8 *) func_80100094(func_80106790(), 0) + 0x34);
}

// Marks contact and starts the bounce timer.
func_80800108_sueggmove(u8 *state)
{
    if (!state[0xD]) {
        state[0xC] = 1;
        state[0xD] = 8;
    }
}

// Moves the egg one step; on a hit it aligns to the surface or bounces.
void func_8080012C_sueggmove(actor) Actor *actor;
{
    u8 *state;
    f32 normal[3];
    f32 new_pos[3];
    u8 *hit;
    state = func_80100094(actor, 0);
    state[0xC] = 0;
    func_80800000_sueggmove(actor, actor->position, new_pos);
    func_800EA600(_sueggmove_entrypoint_0, actor->unk0);
    hit = func_800FAB50(actor->position, new_pos, normal, 0x24200A0, 15.0f);
    func_800EA614();
    if (hit) {
        if (!state[0xE]) {
            func_800EFD24((f32 *) ((u8 *) actor + 0x28));
            func_800F1988(normal, &actor->rotation[0], &actor->rotation[1]);
            actor->rotation[0] = func_800136E4(actor->rotation[0] - 90.0f);
        } else {
            func_800F059C((f32 *) ((u8 *) actor + 0x28), (f32 *) ((u8 *) actor + 0x28),
                          normal);
            *(f32 *) ((u8 *) actor + 0x2C) =
                func_800F0E00(*(f32 *) ((u8 *) actor + 0x2C), 250.0f);
            func_80800108_sueggmove(state);
        }
        *(s32 *) (state + 0x34) = *(s32 *) (hit + 8);
    }
    func_800EE7F8(actor->position, new_pos);
    *(f32 *) (state + 0x10) = -9000.0f;
}

int sueggmove_entrypoint_3(s32 actor)
{
    u8 *state;

    state = func_80100094(actor, 0);
    return state[12];
}

void sueggmove_entrypoint_4(u8 *actor)
{
    u8 *state;
    u8 *data;

    data = func_80100094(actor, 0);
    *(f32 *) ((s8 *) actor + 0x54) = 0.0f;
    *(f32 *) ((s8 *) actor + 0x34) = 0.0f;
    // Matching: extra temporary needed for the match.
    state = data;
    func_800EFD24(actor + 0x18);
    *(s8 *) ((s8 *) state + 0xC) = 0;
    *(s8 *) ((s8 *) state + 0xE) = 0;
    *(s8 *) ((s8 *) state + 0xF) = 0;
    *(s8 *) ((s8 *) state + 0xD) = 0;
    sueggmove_entrypoint_8(actor, 1);
}

void sueggmove_entrypoint_5(s32 actor, s32 bounce)
{
    *(s8 *) ((s32) func_80100094(actor, 0) + 0xE) = bounce;
}

void sueggmove_entrypoint_6(Actor *actor, f32 gravity, f32 terminal_speed)
{
    *(f32 *) ((char *) actor + 0x34) = gravity;
    *(f32 *) ((char *) actor + 0x54) = terminal_speed;
}

s32 sueggmove_entrypoint_7(s32 actor)
{
    func_800EE7F8(actor + 0x28);
}

void sueggmove_entrypoint_8(actor, active) s32 actor;
s32 active;
{
    *(s8 *) ((s32) func_80100094(actor, 0) + 0xF) = (s8) active;
}

int sueggmove_entrypoint_9(Actor *actor)
{
    u8 *state;
    f32 unk_0[3];
    state = func_80100094(actor, 0);

if (state[0xD] != 0) {
    state[0xD]--;
}

func_800EE7F8(unk_0, (u8 *) actor + 4, state);

if (state[0xF] == 1) {
    func_8080012C_sueggmove(actor);
}

func_800EFB24((u8 *) actor + 0x18, (u8 *) actor + 4, unk_0);
}

// Swept-sphere probe from `from` to `to`; the result is discarded.
void sueggmove_entrypoint_10(s32 from, s32 to)
{
    f32 normal[3];
    func_800FAB50(from, to, normal, 0x24200A0, 15.0f);
}
