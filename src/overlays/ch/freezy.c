#include "common.h"

extern void *D_80800700_chfreezy;
typedef union {
    s32 value;
    Actor *actor;
} FreezyMessage1425;
extern void *func_80100094(Actor *, u32);
typedef struct FreezyFlags74 {
    u8 pad_0 : 7;
    u8 unk_0 : 1;
} FreezyFlags74;
typedef struct FreezyFlags78 {
    u32 pad_0 : 29;
    u32 spawned : 1;
    u32 pad_1 : 2;
} FreezyFlags78;
extern u8 D_80800748_chfreezy[];
extern void _chfreezy_entrypoint_2();
extern Actor *func_80106790(void *);
extern Actor *func_801084B0(s32, Actor **);
extern Actor *_chnewfreezy_entrypoint_0(void *, s32, s32, s32);
typedef struct {
    u8 pad_0[0x24];
    u32 model : 10;
    u32 flags : 22;
} FreezyMarkerView;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80103DFC(Actor *, f32 *);
extern f32 func_800EC708(void *);
extern void _sufreezy_entrypoint_1(void);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 29;
    u32 active : 1;
    u32 pad_2 : 2;
} FreezyLinkFlags;
extern Actor *_subaddielink_entrypoint_4(void *);
extern f32 func_800F15F8(f32, f32, f32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _fxtwinkle_entrypoint_1();
extern void func_800F18FC();
extern f32 func_800DC178(f32, f32);
extern s32 func_800D9058(f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
void func_8080044C_chfreezy();
int func_808004B8_chfreezy();
s32 func_808006C0_chfreezy();
void func_80800538_chfreezy();

int chfreezy_entrypoint_0()
{
    return &D_80800700_chfreezy;
}

void func_8080000C_chfreezy(Actor *actor)
{
    _sufreezy_entrypoint_1();
    *(f32 *) ((char *) actor + 0x38) = 0.2f;
}

// Restores the frozen actor's saved state.
void func_8080003C_chfreezy(u8 *actor)
{
    s32 frozen;
    s32 saved_state;

    frozen = _subaddielink_entrypoint_4(func_80100094(actor, 1));
    saved_state = (u32) actor[0x79] >> 4;
    func_8010A828(frozen, saved_state);
}

// Per frame: scales the ice to the target size, sparkles, and releases the enemy when the link ends.
void func_80800080_chfreezy(Actor *actor)
{
    Actor *frozen;
    frozen = _subaddielink_entrypoint_4((void *) func_80100094(actor, 1));
    if (actor->unk64_17)
        return;
    if (!frozen || frozen->unk64_17) {
        func_808006C0_chfreezy(actor);
        return;
    }
    actor->scale =
        func_800F15F8(actor->scale, actor->unk50, (actor->unk50 - actor->scale) * 0.1f);
    if (!((FreezyLinkFlags *) frozen)->active) {
        func_808006C0_chfreezy(actor);
        return;
    }
    _sudeflect_entrypoint_0(actor->position, 0.0f, actor->scale * 100.0f, 2);
    func_80800538_chfreezy(actor);
    if (func_800D9078(&actor->unk58)) {
        _sufreezy_entrypoint_4(actor->unk0, 0x10);
        func_808006C0_chfreezy(actor);
    }
}

int func_80800190_chfreezy(Actor *actor, s32 msg, FreezyMessage1425 arg)
{
    switch (msg) {
        case 0x3E:
            func_8080003C_chfreezy((u8 *) actor);
            _sufreezy_entrypoint_5(actor->unk0, arg.value);
            _sufreezy_entrypoint_4(actor->unk0, 0x10);
            func_808006C0_chfreezy((s32) actor);
            return 1;
        case 0x3F:
            _sufreezy_entrypoint_6(actor->unk0, arg.value);
            return 1;
        case 0x40:
            func_8080003C_chfreezy((u8 *) actor);
            _sufreezy_entrypoint_7(actor->unk0, arg.value);
            _sufreezy_entrypoint_4(actor->unk0, 0x10);
            func_800FFAB0(actor);
            return 1;
        case 0x95:
            if (!_subaddielink_entrypoint_3(func_80100094(actor, 1))) {
                func_800FFAB0(actor);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

// Called from the damage code: links to the frozen actor and queues the ice spawn.
void chfreezy_entrypoint_1(Actor *actor, s16 *hit_pos)
{
    s32 x;
    s32 y;
    s32 z;

    if (!actor->unk64_17) {
        if (((FreezyFlags74 *) ((u8 *) actor + 0x74))->unk_0) {
            ((FreezyFlags74 *) ((u8 *) actor + 0x74))->unk_0 = 0;
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800748_chfreezy);
        } else if (!actor->unk64_17 && !((FreezyFlags78 *) ((u8 *) actor + 0x78))->spawned) {
            x = hit_pos[0];
            y = hit_pos[1];
            z = hit_pos[2];
            ((FreezyFlags78 *) ((u8 *) actor + 0x78))->spawned = 1;
            func_80102190(actor, 1);
            func_8010A570(actor);
            func_8010108C(actor, 3, 0);
            _sufreezy_entrypoint_3(actor);
            _chbaddiesetup_entrypoint_5(_chfreezy_entrypoint_2, actor->unk0, 0, x, y,
                                        z);
        }
    }
}

void chfreezy_entrypoint_2(void *frozen_handle, s32 snap_scale, s32 x, s32 y, s32 z)
{
    Actor *frozen;
    Actor *ice;

    frozen = func_80106790(frozen_handle);
    ice = _chnewfreezy_entrypoint_0(frozen->unk0, x, y, z);
    if (!ice)
        ice = func_801084B0(0x363, &frozen);
    else
        frozen = func_80106790(frozen_handle);
    if (ice) {
        _subaddielink_entrypoint_1(func_80100094(ice, 1), frozen_handle);
        func_8080044C_chfreezy(ice, frozen, snap_scale);
        ice->unk79_4 = func_8010A848(frozen);
        func_8010A828(frozen, 1);
    }
}

void func_8080044C_chfreezy(ice, frozen, snap_scale) Actor *ice;
Actor *frozen;
s32 snap_scale;
{
    if (((FreezyMarkerView *) ice->unk0)->model == 0x2F6) {
        func_800EE7F8(ice->rotation, frozen->rotation);
        func_80103DFC(frozen, ice->position);
        func_808004B8_chfreezy(ice, frozen, snap_scale);
    }
}

int func_808004B8_chfreezy(ice, frozen, snap_scale)
Actor *ice;
Actor *frozen;
s32 snap_scale;
{
    f32 frozen_size;
    f32 unit_size;
    if ((*(u32 *) ((u8 *) ice->unk0 + 0x24) >> 22) == 0x2F6) {
        frozen_size = func_800EC708(frozen->unk0);
        unit_size = func_800EC708(ice->unk0) / ice->scale;
        ice->unk50 = frozen_size / unit_size;
        if (snap_scale) {
            ice->scale = ice->unk50;
        }
    }
}

// Spawns sparkles around the ice at random intervals.
void func_80800538_chfreezy(actor) Actor *actor;
{
    f32 sparkle_pos[3];
    f32 unk_0[3];
    f32 offset[3];
    f32 unk_1[2];
    s32 i;
    if (actor->unk6C_0)
        --actor->unk6C_0;
    if (actor->unk7C_12 && !(*(f32 *) ((u8 *) actor + 0x58) < 1.0f) && actor->unk6C_0 == 0) {
        func_800E3980(unk_0);

        func_800F18FC(actor->position, unk_0, unk_1);
        for (i = 0; i < 2; i++)
            unk_1[i] += func_800DC178(0.0f, 160.0f) - 80.0f;
        func_800EEBF0(offset, unk_1, actor->scale * 100.0f);
        func_800EE780(sparkle_pos, actor->position, offset);
        _fxtwinkle_entrypoint_1(sparkle_pos, 0x9E5);
        actor->unk6C_0 = func_800D9058(func_800DC178(0.5f, 0.8f));
    }
}

s32 func_808006C0_chfreezy(actor)
s32 actor;
{
    _sufreezy_entrypoint_2();
    func_800FFAB0(actor);
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file,
// and IDO schedules some of them differently unless they share the unit. Values come from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
void *D_80800700_chfreezy = (void *) 0x02F60363;
static u32 D_80800700_chfreezy_rest[17] = {0x75D0001,
                                           0x0,
                                           (u32) func_80800080_chfreezy,
                                           (u32) func_80105834,
                                           (u32) func_80101870,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x100000,
                                           0x0,
                                           (u32) func_80108ED0,
                                           0x8,
                                           (u32) func_8080000C_chfreezy,
                                           (u32) func_80107C2C,
                                           0x80200000,
                                           (u32) func_80800190_chfreezy,
                                           0x0};
u8 D_80800748_chfreezy[24] = {0x0, 0x13, 0x4, 0xDC, 0x0, 0xD,  0x1, 0x0, 0x1, 0x4C, 0x0, 0x15,
                              0x0, 0x0,  0x0, 0x80, 0x0, 0x66, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0};
