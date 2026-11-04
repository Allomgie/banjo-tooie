// Generic thrown-item pickups (11 actor kinds) that an NPC tosses to the player in a ballistic arc.
// On landing they can be collected for an inventory item; while held they follow the player.
#include "ch/pickups.h"

#define PICKUPS_DATA(arg0) ((PickupsData *) (arg0->actorData))

extern s32 D_80800790_chpickups[];
extern s32 D_808007D8_chpickups[];
extern s32 D_80800820_chpickups[];
extern s32 D_80800868_chpickups[];
extern s32 D_808008B0_chpickups[];
extern s32 D_808008F8_chpickups[];
extern s32 D_80800940_chpickups[];
extern s32 D_80800988_chpickups[];
extern s32 D_808009D0_chpickups[];
extern s32 D_80800A18_chpickups[];
extern s32 D_80800A60_chpickups[];
extern s32 D_80800AA8_chpickups[];
extern s32 D_80800AB8_chpickups[];

s32 *chpickups_entrypoint_0(void)
{
    return &D_80800790_chpickups;
}

s32 *chpickups_entrypoint_1(void)
{
    return &D_808007D8_chpickups;
}

s32 *chpickups_entrypoint_2(void)
{
    return &D_80800820_chpickups;
}

s32 *chpickups_entrypoint_3(void)
{
    return &D_80800868_chpickups;
}

s32 *chpickups_entrypoint_4(void)
{
    return &D_808008B0_chpickups;
}

s32 *chpickups_entrypoint_5(void)
{
    return &D_808008F8_chpickups;
}

s32 *chpickups_entrypoint_6(void)
{
    return &D_80800940_chpickups;
}

s32 *chpickups_entrypoint_7(void)
{
    return &D_80800988_chpickups;
}

s32 *chpickups_entrypoint_8(void)
{
    return &D_808009D0_chpickups;
}

s32 *chpickups_entrypoint_9(void)
{
    return &D_80800A18_chpickups;
}

s32 *chpickups_entrypoint_10(void)
{
    return &D_80800A60_chpickups;
}

// Actor message handler; 0x3E = collected by the player.
s32 func_80800084_chpickups(Actor *actor, s32 msg, s32 arg2)
{
    switch (msg) {
        case 0x3E:
            func_80800110_chpickups(actor);
            return 1;
        case 0x95:
            if (actor->unk64_23) {
                func_800F822C(func_800F54E4(), 0, 0);
                func_80101FDC(actor, 3);
            }

            return 1;
        default:
            return 0;
    }
}

// Collect: add the mapped inventory item for this actor kind and despawn.
void func_80800110_chpickups(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
        case 2:
            if (actor->unk6C_9 == 0x1D9) {
                _fxsparkle_entrypoint_1(actor->position, 5U);
                func_800FC6B0(0xE);
            }
            func_800F6388(func_800F54E4(), actor->unk6C_9);
            func_800FFAB0(actor);
    }
}

// Start the throw: velocity so the item lands on the target in a ballistic arc.
void func_808001A0_chpickups(Unk80132ED0 *arg0, f32 *pos)
{
    Actor *actor;
    s32 target[3];
    f32 new_vy;

    f32 y;
    f32 frames;
    f32 vy;

    actor = func_80106790(arg0);
    func_800EE904(target, pos);
    switch (actor->unk6C_9) {
        default:
            func_800900D0(actor->unk6C_9);
        case 0x4E2:
        case 0x4B7:
        case 0x4E3:
        case 0x4E4:
        case 0x515:
        case 0x516:
            break;
    }
    func_80101FDC(actor, 4U);
    func_800EE7F8(PICKUPS_DATA(actor)->unk0, pos);
    PICKUPS_DATA(actor)->unk10[0] = (target[0] - actor->position[0]);
    PICKUPS_DATA(actor)->unk10[1] = 28.0f;
    PICKUPS_DATA(actor)->unk10[2] = (target[2] - actor->position[2]);
    frames = 0.0f;
    vy = 28.0f;
    y = actor->position[1];
    while (!(y < target[1] && (vy < 0.0f))) {
        new_vy = vy - 5.0f;
        vy = new_vy;
        y += new_vy;
        frames += 1.0f;
    }
    PICKUPS_DATA(actor)->unk10[0] = PICKUPS_DATA(actor)->unk10[0] / frames;
    PICKUPS_DATA(actor)->unk10[2] = PICKUPS_DATA(actor)->unk10[2] / frames;
    func_800EF334(PICKUPS_DATA(actor)->unk10, 30.0f);
    actor->unk58 = frames * 30.0f;
}

void func_80800344_chpickups(s32 actor)
{
    func_80101FDC(actor, 0x2);
}

// Ballistic flight step; lands when it falls below the ground height.
void func_80800364_chpickups(Actor *actor)
{
    f32 ground_y;
    f32 dt;

    dt = func_800D8FF8();
    ground_y = PICKUPS_DATA(actor)->unk0[1];
    PICKUPS_DATA(actor)->unk10[1] -= 150.0f * (30.0f * dt);
    actor->position[0] += PICKUPS_DATA(actor)->unk10[0] * dt;
    actor->position[1] += PICKUPS_DATA(actor)->unk10[1] * dt;
    actor->position[2] += PICKUPS_DATA(actor)->unk10[2] * dt;
    if ((actor->position[1] < ground_y) && (PICKUPS_DATA(actor)->unk10[1] < 0.0f)) {
        switch (actor->unk6C_9) {
            case 0x3CA:
            case 0x3CB:
            case 0x4B7:
            case 0x4D7:
            case 0x4E2:
            case 0x4E3:
            case 0x4E4:
                break;
            case 0x481:
                _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80800AA8_chpickups);
                break;
            default:
                _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80800AB8_chpickups);
        }
        actor->position[1] = ground_y;
        if (actor->unk70_10 == 4) {
            if ((actor->unk0->unk24 >> 0x16 != 0x37) && (actor->unk0->unk24 >> 0x16 == 0x67)) {
                func_80101180(0x4A5, 0x7D, 0);
                func_800FFAB0(actor);
            }
        }
        actor->unk64_22 = 0;
        actor->unk64_23 = actor->unk64_22;
        func_80101FDC(actor, 2U);
    }
}

// Held by the player: dropped again if another player took over.
void func_80800528_chpickups(Actor *actor)
{
    s32 pad;
    f32 player_pos[3];
    if (func_8008FDEC() != actor->unk0) {
        func_800F63E0(func_800F54E4(), actor->unk6C_9);
        func_800FFAB0(actor);
        return;
    }
    if (actor->unk64_22) {
        func_800F5D44(func_800F54E4(), player_pos);
        func_808001A0_chpickups(actor->unk0, player_pos);
    }
}

void func_808005B8_chpickups(Actor *actor, s32 arg1)
{
    s32 value;

    func_8010A5B0(actor, arg1);
    if (actor->unk70_10 == 2) {
        value = 8;
        if (arg1 == 0) {
            value = 0xA;
        }
        _sudeflect_entrypoint_1(actor->position, func_80103EF4(actor), 0, func_80103EAC(actor),
                                value);
    }
}

// Per-frame update by state; kind 0x1DD gets the deflect check.
void func_80800638_chpickups(Actor *actor)
{
    if (!actor->unk64_17) {
        switch (actor->unk70_10) {
            case 2:
                break;
            case 5:
                func_80800344_chpickups((s32) actor);
                break;
            case 1:
                func_80800364_chpickups(actor);
                break;
            case 3:
                func_80800528_chpickups(actor);
                break;
            case 4:
                func_80800364_chpickups(actor);
        }
        if (((u32) actor->unk0->unk24 >> 0x16) == 0x1DD) {
            if (func_800DA298(0x5A) != 0) {
                func_808005B8_chpickups(actor, 0);
                return;
            }
            if (func_80090178(ALLOW_BK | ALLOW_BANJO) != 0) {
                func_808005B8_chpickups(actor, 1);
                return;
            }
            func_808005B8_chpickups(actor, 0);
        }
    }
}

void func_80800734_chpickups(Actor *actor)
{
    actor->rotation[0] = 0.0f;
}

void func_80800740_chpickups(s32 actor)
{
    func_80800638_chpickups(actor);
    _chdoubloon_entrypoint_1(actor);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _chdoubloon_entrypoint_0();
s32 D_80800790_chpickups[18] = {0x1DD01D9,
                                0x9110005,
                                0x0,
                                (u32) func_80800638_chpickups,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x3F19999A,
                                0x0,
                                0x4,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_808007D8_chpickups[18] = {0x1B803CA,
                                0x7A60005,
                                0x0,
                                (u32) func_80800638_chpickups,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x3F19999A,
                                0x0,
                                0x10802004,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_80800820_chpickups[18] = {0x1BA03CB,
                                0x7A40005,
                                0x0,
                                (u32) func_80800638_chpickups,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x3F19999A,
                                0x0,
                                0x10802004,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_80800868_chpickups[18] = {0x1580481,
                                0x8CF0005,
                                0x0,
                                (u32) func_80800638_chpickups,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x3F19999A,
                                0x0,
                                0x4,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_808008B0_chpickups[18] = {0x15804E2,
                                0x7BF0005,
                                0x0,
                                (u32) func_80800638_chpickups,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x3F800000,
                                0x0,
                                0x4,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_808008F8_chpickups[18] = {0x15804E3,
                                0x7F30005,
                                0x0,
                                (u32) func_80800638_chpickups,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x3F4CCCCD,
                                0x0,
                                0x4,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_80800940_chpickups[18] = {0x15804E4,
                                0x7C00005,
                                0x0,
                                (u32) func_80800740_chpickups,
                                (u32) func_80105834,
                                (u32) _chdoubloon_entrypoint_0,
                                0x0,
                                0x3F800000,
                                0x0,
                                0x20004,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800734_chpickups,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_80800988_chpickups[18] = {0x6704D7,
                                0x8FA0005,
                                0x0,
                                (u32) func_80800638_chpickups,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x3F19999A,
                                0x0,
                                0x4,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_808009D0_chpickups[18] = {0x1580515,
                                0x9750005,
                                0x0,
                                (u32) func_80800638_chpickups,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x3F19999A,
                                0x0,
                                0x4,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_80800A18_chpickups[18] = {0x1580516,
                                0x9740005,
                                0x0,
                                (u32) func_80800638_chpickups,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x3F19999A,
                                0x0,
                                0x4,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_80800A60_chpickups[18] = {0x15804B7,
                                0x6120005,
                                0x0,
                                (u32) func_80800638_chpickups,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x3F4CCCCD,
                                0x0,
                                0x4,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800084_chpickups,
                                0x0};
s32 D_80800AA8_chpickups[4] = {0x13041F, 0xA0100, 0x1661A8, 0x0};
s32 D_80800AB8_chpickups[6] = {0x130418, 0xA00C2, 0x1661A8, 0x103E8, 0x7D00000, 0x0};
