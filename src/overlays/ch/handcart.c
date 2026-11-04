#include "ch/handcart.h"

#define HANDCART_DATA(arg0) ((HandcartActorData *) (arg0->actorData))

extern f32 func_80013970(f32);

void func_80801D50_chhandcart(Actor *arg0);
void func_80801FF4_chhandcart(s32 arg0);
void func_80802120_chhandcart(Actor *arg0);
s32 func_80802468_chhandcart(Actor *arg0, s32 arg1, s32 arg2);
void func_8080256C_chhandcart(Actor *arg0, u32 arg1);
void func_808028F0_chhandcart(Actor *arg0);
void func_80802B74_chhandcart(Actor *arg0);
void func_80803794_chhandcart(Actor *arg0);
s32 func_80803FC4_chhandcart(Actor *arg0, s32 arg1, u32 arg2);
void func_8080436C_chhandcart(void);
// TU-NOTE: the .data of this overlay is defined here in C. Its tables point to functions of
// this file, and IDO schedules some of them differently unless they are in the same unit.
// Strings are string literals so IDO puts them in .rodata where the original has them;
// that is why this block comes before the functions. Values are taken from the ROM.
extern void func_80107C2C();
u32 D_808046C0_chhandcart[5] = {0x1303FF, 0xD00CC, 0xE60019, 0x3E804650, 0x0};
u32 D_808046D4_chhandcart[5] = {0x130660, 0xD00E6, 0x1190019, 0x3E804650, 0x0};
u32 D_808046E8_chhandcart[3] = {0x130404, 0x164E20, 0x0};
f32 D_808046F4_chhandcart[4] = {1.74658e-39f, 1.194202e-39f, 2.5714e-38f, 4.33279e+27f};
u32 D_80804704_chhandcart[4] = {0x130436, 0xD00F3, 0x10C0018, 0x0};
u32 D_80804714_chhandcart[7] = {0x130684,     0xD00D9,      0xF30016,      0x3A980000,
                                (u32) "Wait", (u32) "Race", (u32) "Report"};
u32 D_80804730_chhandcart[54] = {
    0x0,        0x0,      0x40C00000, 0x800001, 0x40C00000, 0x800001, 0x40C00000, 0x800001,
    0x40C00000, 0x800001, 0x3ECCCCCD, 0x7D0001, 0x3ECCCCCD, 0x7D0001, 0x3ECCCCCD, 0x7D0001,
    0x3ECCCCCD, 0x7D0001, 0x3F800000, 0x890001, 0x40000000, 0x8A0042, 0x3F800000, 0x850001,
    0x3F800000, 0x890001, 0x40000000, 0x8A0042, 0x3F800000, 0x850001, 0x3F800000, 0x850001,
    0x3ECCCCCD, 0x7D0001, 0x3F800000, 0x850001, 0x3ECCCCCD, 0x7D0201, 0x3ECCCCCD, 0x7D0001,
    0x3ECCCCCD, 0x7D0001, 0x3F800000, 0x890001, 0x40000000, 0x8A0042, 0x40C00000, 0x800001,
    0x40800000, 0x7E0000, 0x40800000, 0x7E0000, 0x3ECCCCCD, 0x7D0201};
u32 D_80804808_chhandcart[48] = {
    0x0,        0x0,      0x3F800000, 0x840044, 0x3F800000, 0x840044, 0x3F800000, 0x840044,
    0x3F800000, 0x840044, 0x3F800000, 0x840044, 0x3F800000, 0x840001, 0x3F800000, 0x840004,
    0x3F800000, 0x840004, 0x3F800000, 0x840001, 0x3F800000, 0x840001, 0x3F800000, 0x840001,
    0x3F800000, 0x840004, 0x3F800000, 0x840004, 0x3F800000, 0x840004, 0x3F800000, 0x840004,
    0x3F800000, 0x840004, 0x3F800000, 0x840004, 0x3F800000, 0x840004, 0x3F800000, 0x840044,
    0x3F800000, 0x840044, 0x3F800000, 0x840044, 0x3F800000, 0x840044, 0x3F800000, 0x840044};
u32 D_808048C8_chhandcart[45] = {
    0x41700000, 0x42200000, 0x0,        0x44960000, 0x0,        0x41700000, 0x41C80000, 0x0,
    0x447A0000, 0x14A0000,  0x41700000, 0x41C80000, 0x0,        0x447A0000, 0x17C0000,  0x41C80000,
    0xC3200000, 0x0,        0x44960000, 0x1FE0000,  0x41C80000, 0xC3200000, 0x0,        0x44960000,
    0x2580000,  0x41200000, 0x432F0000, 0x0,        0x43E10000, 0x29E0000,  0x41200000, 0x432F0000,
    0x0,        0x43E10000, 0x3520000,  0x41700000, 0x41C80000, 0x0,        0x443B8000, 0x3840000,
    0x41700000, 0x41C80000, 0x0,        0x443B8000, 0x3E80000};
u32 D_8080497C_chhandcart[40] = {
    0x41700000, 0x434D0000, 0x0,        0x43FA0000, 0x0,        0x41700000, 0x434D0000, 0x0,
    0x43FA0000, 0x14A0000,  0x41700000, 0x434D0000, 0x0,        0x43FA0000, 0x17C0000,  0x41700000,
    0x434D0000, 0x0,        0x43FA0000, 0x1B80000,  0x41700000, 0x434D0000, 0x0,        0x43FA0000,
    0x2940000,  0x41700000, 0x434D0000, 0x0,        0x43FA0000, 0x3520000,  0x41700000, 0x434D0000,
    0x0,        0x43FA0000, 0x3840000,  0x41700000, 0x434D0000, 0x0,        0x43FA0000, 0x3E80000};
u32 D_80804A1C_chhandcart[50] = {
    0x41700000, 0x0,        0x0,        0x443B8000, 0x0,        0x41A00000, 0x0,        0x0,
    0x443B8000, 0xE60000,   0x41700000, 0x0,        0x0,        0x43FA0000, 0x17C0000,  0x41700000,
    0x41F00000, 0x0,        0x447A0000, 0x19A0000,  0x41700000, 0x41F00000, 0x0,        0x447A0000,
    0x1EA0000,  0x41200000, 0xC3200000, 0x0,        0x44610000, 0x2620000,  0x41200000, 0xC3200000,
    0x0,        0x44610000, 0x3200000,  0x41700000, 0xC2700000, 0x0,        0x447A0000, 0x3520000,
    0x41700000, 0xC2700000, 0x0,        0x447A0000, 0x3840000,  0x41700000, 0xC2700000, 0x0,
    0x447A0000, 0x3E80000};
u32 D_80804AE4_chhandcart[40] = {
    0x41700000, 0xC1C80000, 0x0,        0x43FA0000, 0x0,        0x41700000, 0xC1C80000, 0x0,
    0x43FA0000, 0x14A0000,  0x41700000, 0xC1C80000, 0x0,        0x43FA0000, 0x17C0000,  0x41700000,
    0xC1C80000, 0x0,        0x43FA0000, 0x1B80000,  0x41700000, 0xC1C80000, 0x0,        0x43FA0000,
    0x2940000,  0x41700000, 0xC1C80000, 0x0,        0x43FA0000, 0x3520000,  0x41700000, 0xC1C80000,
    0x0,        0x43FA0000, 0x3840000,  0x41700000, 0xC1C80000, 0x0,        0x43FA0000, 0x3E80000};
unk80804B84 *D_80804B84_chhandcart[4] = {
    (void *) &D_808048C8_chhandcart, (void *) &D_8080497C_chhandcart,
    (void *) &D_80804A1C_chhandcart, (void *) &D_80804AE4_chhandcart};
s32 D_80804B94_chhandcart[4] = {0x9, 0x8, 0xA, 0x8};
u32 D_80804BA4_chhandcart[60] = {
    0x3DF5C28F, 0x0, 0x0, 0x2000C, 0x3E3851EC, 0x0, 0x0, 0x20002, 0x3E800000, 0x0, 0x0, 0x10000,
    0x3E99999A, 0x0, 0x0, 0x2000B, 0x3EC28F5C, 0x0, 0x0, 0x20003, 0x3EDC28F6, 0x0, 0x0, 0x2000E,
    0x3EF0A3D7, 0x0, 0x0, 0x2000F, 0x3F066666, 0x0, 0x0, 0x10000, 0x3F0F5C29, 0x0, 0x0, 0x20005,
    0x3F2E147B, 0x0, 0x0, 0x10000, 0x3F428F5C, 0x0, 0x0, 0x20006, 0x3F4A3D71, 0x0, 0x0, 0x20007,
    0x3F51EB85, 0x0, 0x0, 0x20008, 0x3F570A3D, 0x0, 0x0, 0x20009, 0x3F666666, 0x0, 0x0, 0x2000A};
u32 D_80804C94_chhandcart[60] = {
    0x3E19999A, 0x0, 0x0, 0x20002, 0x3E3851EC, 0x0, 0x0, 0x20003, 0x3E570A3D, 0x0, 0x0, 0x20004,
    0x3E75C28F, 0x0, 0x0, 0x10000, 0x3E99999A, 0x0, 0x0, 0x20005, 0x3EB33333, 0x0, 0x0, 0x20006,
    0x3EC7AE14, 0x0, 0x0, 0x20007, 0x3ED70A3D, 0x0, 0x0, 0x10000, 0x3EF5C28F, 0x0, 0x0, 0x20008,
    0x3F0F5C29, 0x0, 0x0, 0x20009, 0x3F1EB852, 0x0, 0x0, 0x10000, 0x3F333333, 0x0, 0x0, 0x2000A,
    0x3F400000, 0x0, 0x0, 0x2000B, 0x3F4A3D71, 0x0, 0x0, 0x2000C, 0x3F5C28F6, 0x0, 0x0, 0x10000};
unk80804D84 *D_80804D84_chhandcart[4] = {(void *) &D_80804BA4_chhandcart, 0,
                                         (void *) &D_80804C94_chhandcart, 0};
s32 D_80804D94_chhandcart[4] = {0xF, 0x0, 0xF, 0x0};
s32 D_80804DA4_chhandcart[5] = {0x2060013, 0x4BF0016, 0x46500001, 0x1F409C4, 0x0};
f32 D_80804DB8_chhandcart[3] = {0.0f, 0.0f, 0.0f};
void *D_80804DC4_chhandcart = (void *) 0x0158038A;
static u32 D_80804DC4_chhandcart_rest[17] = {0x67C0002,
                                             (u32) &D_80804808_chhandcart,
                                             (u32) func_80801D50_chhandcart,
                                             (u32) func_80801D50_chhandcart,
                                             (u32) func_8080256C_chhandcart,
                                             0x5DC0000,
                                             0x0,
                                             0x0,
                                             0x80064,
                                             (u32) func_80801FF4_chhandcart,
                                             0x0,
                                             0x9400000,
                                             (u32) func_80802120_chhandcart,
                                             (u32) func_80107C2C,
                                             0x80000002,
                                             (u32) func_80802468_chhandcart,
                                             0x0};
u32 D_80804E0C_chhandcart[3] = {0x3E0F5C29, 0x3F266666, 0xBF800000};
u32 D_80804E18_chhandcart[5] = {0x3D8F5C29, 0x3E99999A, 0x3F0F5C29, 0x3F51EB85, 0xBF800000};
u32 D_80804E2C_chhandcart[3] = {0x0, 0x3F000000, 0xBF800000};
u32 D_80804E38_chhandcart[5] = {0x3F266666, 0x3F400000, 0x3F4CCCCD, 0x3F59999A, 0xBF800000};
u32 D_80804E4C_chhandcart[4] = {0x430C0000, 0x43590000, 0x43590000, 0x0};
u32 D_80804E5C_chhandcart[4] = {0x43590000, 0x43590000, 0x43590000, 0x42D90000};
void *D_80804E6C_chhandcart = (void *) 0x0158051E;

static u32 D_80804E6C_chhandcart_rest[20] = {0x67B0002,
                                             (u32) &D_80804730_chhandcart,
                                             (u32) func_80803794_chhandcart,
                                             (u32) func_80803794_chhandcart,
                                             (u32) func_8080436C_chhandcart,
                                             0x9C42710,
                                             0x0,
                                             0x0,
                                             0x880564,
                                             (u32) func_80802B74_chhandcart,
                                             0x0,
                                             0x100000,
                                             (u32) func_808028F0_chhandcart,
                                             (u32) func_80107C2C,
                                             0x84000002,
                                             (u32) func_80803FC4_chhandcart,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x0};

s32 func_80800000_chhandcart(void)
{
    return func_800DA564(FLAG3_A4C_UNK, 3);
}

// Stores the race result (1 = lose, 2 = win).
void func_80800024_chhandcart(s32 race_state)
{
    func_800DA7A8(FLAG3_9DC_UNK, race_state, 2);
    func_800FDC28(0U);
    switch (race_state) {
        case 1: // Lose
            func_800FC660(0x17U);
            return;
        case 2: // Win
            func_800FC660(0x16U);
    }
}

s32 func_80800090_chhandcart(void)
{
    return func_800DA564(FLAG3_9DC_UNK, 2);
}

// Warps to the race map or back to Glitter Gulch Mine.
void func_808000B4_chhandcart(Actor *actor)
{
    switch (((CanaryMaryMemory *) func_80100094(actor, 0U))->RaceState) {
        case 1:
            // Choose which race map to enter.
            _gcgoto_entrypoint_1(actor->unk64_19 > 0 ? MAP_170_GGM_RACE_2 : MAP_16F_GGM_RACE_1, 1);
            return;
        case 0:
        case 2:
            if (func_80800090_chhandcart() == 2) {
                // Success: warp back.
                _gcgoto_entrypoint_1(MAP_C7_GGM_GLITTER_GULCH_MINE,
                                     actor->unk64_19 > 0 ? 0x15 : 0x16);
                return;
            }
            // Matching: bare block instead of else.
            {
                // Failure: warp back.
                _gcgoto_entrypoint_1(MAP_C7_GGM_GLITTER_GULCH_MINE,
                                     actor->unk64_19 > 0 ? 0x16 : 0x15);
            }
    }
}

// Loads the race state into the actor's memory.
s32 func_80800194_chhandcart(Actor *actor)
{
    CanaryMaryMemory *memory;
    u8 race_state;
    memory = (CanaryMaryMemory *) func_80100094(actor, 0U);
    race_state = func_800DA564(FLAG3_A4C_UNK, 3);
    return memory->RaceState = race_state;
}

// Sets the race state.
void func_808001D0_chhandcart(Actor *actor, s32 race_state)
{
    CanaryMaryMemory *memory;

    memory = (CanaryMaryMemory *) func_80100094(actor, 0U);
    func_800DA7A8(FLAG3_A4C_UNK, race_state, 3);
    memory->RaceState = (u8) race_state;
}

// Advances the race: start, finish, reset.
void func_80800214_chhandcart(Actor *actor)
{
    switch (((CanaryMaryMemory *) func_80100094(actor, 0U))->RaceState) {
        case 0:
            func_808001D0_chhandcart(actor, 1);
            func_808000B4_chhandcart(actor);
            return;
        case 1:
            func_808001D0_chhandcart(actor, 2);
            _gcintrotext_entrypoint_0();
            func_808000B4_chhandcart(actor);
            return;
        case 2:
            func_808001D0_chhandcart(actor, 0);
            func_80800024_chhandcart(0);
    }
}

// Builds the camera spline for a race track.
void func_808002B8_chhandcart(Actor *actor, s32 track)
{
    Vec3f *knot_pos[1];
    f32 *unk_0[1];
    s16 *unk_1;
    s16 *unk_2;
    s32 i;
    SplineMemory *spline;
    u32 track_index;
    s32 pad;
    HandcartMemory *handcart;

    track_index = track - 1;
    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    spline = (SplineMemory *) func_80100074(
        actor, 1U, _susplinet_entrypoint_18(D_80804B94_chhandcart[track_index], 1, 1));
    _susplinet_entrypoint_19(spline, D_80804B94_chhandcart[track_index], 1, 1);
    for (i = 0; i <= 0; i++) {
        knot_pos[i] = _susplinet_entrypoint_14(spline, i);
    }

    for (i = 0; i <= 0; i++) {
        unk_0[i] = _susplinet_entrypoint_15(spline, i);
    }

    unk_1 = _susplinet_entrypoint_12(spline);
    unk_2 = _susplinet_entrypoint_13(spline);
    for (i = 0; i < D_80804B94_chhandcart[track_index]; i++) {
        func_800EE7F8(unk_0[1], D_80804B84_chhandcart[track_index][i].unk0);
        unk_1[0] = D_80804B84_chhandcart[track_index][i].unk10;
        unk_2[0] = -1;
        *unk_0[0] = D_80804B84_chhandcart[track_index][i].unk0[3];
        _susplinet_entrypoint_0(spline, i, 2,
                                ((D_80804B84_chhandcart[track_index][i].unk12 & 1) != 0) ? 1 : 0);
        _susplinet_entrypoint_0(spline, i, 4,
                                ((D_80804B84_chhandcart[track_index][i].unk12 & 2) != 0) ? 1 : 0);
        unk_1++;
        unk_2++;
        unk_0[0]++;
        knot_pos[0]++;
    }

    for (i = 0; i <= 0; i++) {
        knot_pos[i] = _susplinet_entrypoint_14(spline, i);
    }

    for (i = 0; i <= 0; i++) {
        unk_0[i] = _susplinet_entrypoint_15(spline, i);
    }

    func_800F0EF0(D_80804B94_chhandcart[track_index], knot_pos[0]->f);
    handcart->unk8F5 = track;
    handcart->unk8F6 = 0;
}

// Moves the race camera along the spline.
void func_80800528_chhandcart(Actor *actor)
{
    SplineMemory *spline;
    HandcartMemory *handcart;
    f32 game_speed;
    Actor *target;
    f32 unk_0;
    f32 blend;
    f32 track_pos;
    f32 cam_pos[3];
    f32 unk_1;
    f32 unk_2;
    f32 cam_rot;
    f32 unk_3;
    f32 unk_4;
    f32 cam_target;
    f32 unk_5;
    s32 follows_mary;
    f32 cam_offset[3];
    spline = (SplineMemory *) func_80100094(actor, 1U);
    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    game_speed = func_800D8FF8();
    target = NULL;
    if (handcart->unk8F4 == 3) {
        switch (handcart->unk8F5) {
            case 1:

            case 3:
                follows_mary = 0;
                target = actor;
                break;

            case 2:

            case 4:
                target = func_80106790(actor->unk3C);
                follows_mary = 1;
        }

        _susplinet_entrypoint_11(spline, _susplinet_entrypoint_9(spline));
        _susplinet_entrypoint_10(spline, func_80105AE8(target) * 1000.0f);
        _susplinet_entrypoint_17(spline);
        _susplinet_entrypoint_7(spline, 0, &track_pos);
        func_800EF5A0(cam_pos, &track_pos, 0.0f, 0.0f, -_susplinet_entrypoint_8(spline, 0.0f));
        if (follows_mary == 1) {
            func_800EFA4C(cam_offset, 0.0f, 75.0f, 150.0f);
        } else {
            func_800EFA4C(cam_offset, 0.0f, 75.0f, 0.0f);
        }
        if (_susplinet_entrypoint_6(spline) != 0) {
            handcart->unk8F6 = 0U;
        }
        if (handcart->unk8F6 != 0) {
            blend = 3.0f * game_speed;
            handcart->unk904 +=
                (func_800F1DCC(target->rotation[0], handcart->unk904) * blend);
            handcart->unk908 +=
                (func_800F1DCC(target->rotation[1], handcart->unk908) * blend);
        } else {
            handcart->unk904 = target->rotation[0];
            handcart->unk908 = target->rotation[1];
            handcart->unk8F6 = 1U;
        }
        func_800EF4E4(cam_pos, handcart->unk904, handcart->unk908, cam_pos[0], cam_pos[1],
                      cam_pos[2]);
        func_800EF4E4(&cam_target, handcart->unk904, handcart->unk908, cam_offset[0], cam_offset[1],
                      // Matching: the * 1.0f is needed for the match.
                      cam_offset[2] * 1.0f);
        func_800EF04C(cam_pos, target->position);
        func_800EF04C(&cam_target, target->position);
        func_800A516C(&cam_rot, &cam_target, cam_pos);
        _capod_entrypoint_1(cam_pos, &cam_rot);
    }
}

void func_808007BC_chhandcart(Actor *actor, s32 arg1)
{
    _capod_entrypoint_2(actor->unk0, 0x1D, arg1 | 0x800);
}

void func_808007F0_chhandcart(Actor *actor)
{
    if (((HandcartMemory *) func_80100094(actor, 0U))->unk8F4 == 3) {
        func_80100074(actor, 1, 0);
    }
}

void func_80800830_chhandcart(Actor *actor)
{
    func_8008FB58(actor->position, -25.0f, 100.0f);
}

void func_80800858_chhandcart(Actor *actor, Actor *speaker, s32 arg2, s32 arg3)
{
    HandcartMemory *handcart;
    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    func_808007F0_chhandcart(actor);
    if (speaker == NULL) {
        speaker = actor;
    }
    switch (handcart->unk8F4) {
        case 0:
            func_808007BC_chhandcart(actor, 0);
        case 1:
        case 3:
        case 4:
            _capod_entrypoint_8(1);
            handcart->unk8F4 = 2U;
            _gcdialogcamera_entrypoint_6(speaker->unk0);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg2, arg3);
    }
}

void func_8080090C_chhandcart(Actor *actor, s32 arg1, s32 arg2, Unk80132ED0 *arg3)
{
    HandcartMemory *handcart;
    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    func_808007F0_chhandcart(actor);
    switch (handcart->unk8F4) {
        case 0:
            func_808007BC_chhandcart(actor, arg2);
        case 2:
        case 3:
        case 4:
            handcart->unk8F4 = 1U;
        case 1:
            _capod_entrypoint_6(arg3, arg1, arg2);
    }
}

void func_80800998_chhandcart(Actor *actor, u32 arg1, u32 arg2, Unk80132ED0 *arg3)
{
    HandcartMemory *handcart;

    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    func_808007F0_chhandcart(actor);
    switch (handcart->unk8F4) {
        case 0:
            func_808007BC_chhandcart(actor, (s32) arg2);
        case 1:
        case 2:
        case 3:
            handcart->unk8F4 = 4U;
        case 4:
            _capod_entrypoint_20(arg3, arg1, arg2);
    }
}

void func_80800A24_chhandcart(Actor *actor, s32 track, s32 arg2)
{
    HandcartMemory *handcart;

    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    func_808007F0_chhandcart(actor);
    switch (handcart->unk8F4) {
        case 0:
            func_808007BC_chhandcart(actor, arg2);
        case 1:
        case 2:
        case 4:
            handcart->unk8F4 = 3U;
        case 3:
            _capod_entrypoint_8(0);
            func_808002B8_chhandcart(actor, track);
    }
}

void func_80800AB0_chhandcart(Actor *actor)
{
    HandcartMemory *handcart;

    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    func_808007F0_chhandcart(actor);
    if (handcart->unk8F4 != 0) {
        _capod_entrypoint_3(0);
        handcart->unk8F4 = 0U;
    }
}

void func_80800B00_chhandcart(Actor *actor)
{
    s32 track_index;
    s32 i;
    HandcartMemory *handcart;

    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    track_index = handcart->unk8F5 - 1;
    if (D_80804D84_chhandcart[track_index] != 0) {
        if (actor->unk7C_0) {
            for (i = 0; i < D_80804D94_chhandcart[track_index]; i++) {
                if (func_80105998(actor, D_80804D84_chhandcart[track_index][i].unk0) != 0) {
                    switch (D_80804D84_chhandcart[track_index][i].unkC) {
                        case 1:
                            if (handcart->unk8F8 != 0) {
                                func_80800A24_chhandcart(actor, handcart->unk8F5, 4);
                            }
                            break;
                        case 2:
                            if (handcart->unk8F8 != 0) {
                                func_80800998_chhandcart(
                                    actor, D_80804D84_chhandcart[track_index][i].unkE, 5U,
                                    actor->unk0);
                            }
                            break;
                        case 3:
                            if (handcart->unk8F8 != 0) {
                                handcart->unk8FC = D_80804D84_chhandcart[track_index][i].unk4;
                                handcart->unk900 = D_80804D84_chhandcart[track_index][i].unk8;
                                func_8080090C_chhandcart(
                                    actor, D_80804D84_chhandcart[track_index][i].unkE, 4,
                                    actor->unk0);
                            }
                            break;
                    }
                    handcart->unk8F9 = D_80804D84_chhandcart[track_index][i].unkC;
                }
            }
        }
    }
}

void func_80800CD0_chhandcart(Actor *actor)
{
    HandcartMemory *handcart;

    Unkfunc_800E0960_1 *unk_0;

    f32 rate;
    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    // Matching: empty block needed for the match.
    if (!actor->unk5F) {
    }
    unk_0 = (Unkfunc_800E0960_1 *) func_8010262C(actor->unk0, 2);
    handcart->unk918 = func_800136E4(handcart->unk918 + (HANDCART_DATA(actor)->unkC * 0.5f));
    if (unk_0 != 0) {
        func_800E0AFC(unk_0, 0x2B, -1.0f, handcart->unk918, 0.0f, 0.0f);
        func_800E0AFC(unk_0, 0x2C, -1.0f, handcart->unk918, 0.0f, 0.0f);
    }
    if (HANDCART_DATA(actor)->unkC > 10.0f) {
        rate =
            func_800F10B4(1.0f - (HANDCART_DATA(actor)->unkC / 90.0f), 0.0f, 1.f, 0.5f, 3.0f);
        func_80101CDC(actor, rate);
        if (actor->unk5F == 0) {
            actor->unk5F = func_800C4350(actor->unk5F, actor->position, &D_80804DA4_chhandcart);
            return;
        }
        func_800C31DC(actor->unk5F, func_800F10B4(rate, 0.5f, 3.0f, 1.2f, 0.8f));
        func_800C4350(actor->unk5F, actor->position, 0);
        return;
    }
    func_80101CDC(actor, 1e7f);
}

void func_80800E58_chhandcart(Actor *actor, s32 arg1)
{
    HandcartMemory *handcart;

    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    func_800904C8(0x28);
    if (arg1 != 0) {
        func_800903D0(handcart->unk928);
    }
}

void func_80800EA0_chhandcart(Actor *actor)
{
    _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80804704_chhandcart);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80804714_chhandcart);
}

void func_80800EE4_chhandcart(Actor *actor, s32 arg1)
{
    HandcartMemory *handcart;

    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    if ((func_8009EA64() == 0x38A) && (handcart->unk8FA != 0)) {
        handcart->unk8FA = 0U;
        func_80800E58_chhandcart(actor, arg1);
        HANDCART_DATA(actor)->unkC = 0;
        func_80800CD0_chhandcart(actor);
    }
}

void func_80800F4C_chhandcart(Actor *actor)
{
    u32 state;

    state = actor->unk70_10;
    if ((state == 0) || (state == 1) || (state == 2)) {
        _subaddieDll_entrypoint_4(actor, 0);
        return;
    }
    _subaddieDll_entrypoint_4(actor, 1);
}

void func_80800FA0_chhandcart(Actor *actor, s32 arg1)
{
    HandcartMemory *handcart;
    u32 state;

    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    state = actor->unk70_10;
    switch (state) {
        case 11:
            break;
        case 4:
            func_800F4CC0(func_800F54E4());
            break;
        case 23:
            func_80103140(actor, 0x67C, actor->unk0->unk16);
    }
    func_80102424(actor, arg1);
    switch (actor->unk70_10) {
        case 15:
            break;
        case 3:
            func_800903D0(actor->position);
            break;
        case 4:
            handcart->unk8FA = 1;
            func_800904F4(0x27, actor->unk0);
            func_800F4CEC(func_800F54E4(), 0x3B);
            break;
        case 5:
            handcart->unk8FA = 1;
            func_800904F4(0x27, actor->unk0);
            break;
        case 7:
            func_80800EE4_chhandcart(actor, 1);
    }
    func_80800F4C_chhandcart(actor);
}

void func_808010D8_chhandcart(Actor *actor, s32 arg1)
{
    Actor *mary;

    mary = func_80106790(actor->unk3C);
    func_80800FA0_chhandcart(actor, arg1);
    func_80802CE8_chhandcart(mary, arg1);
}

void func_8080111C_chhandcart(Actor *actor)
{
    if (func_8009EA64() == 0x38A) {
        // Position
        func_800907C0(actor->position);
        // Rotation
        func_800906DC(actor->rotation);
    }
}

// Updates cart speed from the button presses.
f32 func_8080115C_chhandcart(f32 *pump_timer, f32 speed)
{
    f32 game_speed;
    f32 timer;
    s32 button_held;
    game_speed = func_800D8FF8();

    // Button hold time
    button_held = func_80016B30(0, 0);
    timer = *pump_timer;
    // Button not pressed for a while
    if (timer < 0.0f) {
        // Button held
        if (button_held != 0) {
            speed += func_800F10B4(timer, -1.0f, -0.01f, 0.0f, 3.0f);
            *pump_timer = 0.01f;
            return speed;
        }
        // Matching: bare block instead of else; slows the cart.
        {
            *pump_timer = timer - game_speed;
            speed *= 0.98f;
        }
    } else {
        // Button not held
        if (button_held == 0) {
            speed += func_800F10B4(timer, 1.0f, 0.01f, 0.0f, 3.0f);
            *pump_timer = -0.01f;
            return speed;
        }
        // Matching: bare block instead of else; slows the cart.
        {
            *pump_timer = timer + game_speed;
            speed *= 0.98f;
        }
    }
    // Cap speed at 90
    if (speed > 90.0f) {
        speed = 90.0f;
    }
    return speed;
}

void func_80801290_chhandcart(Actor *actor)
{
    HandcartMemory *handcart;
    f32 game_speed;
    s32 decay;
    s32 i;
    f32 spark_pos;
    f32 corner_pos[4][3];
    handcart = (HandcartMemory *) func_80100094(actor, 0);
    game_speed = func_800D8FF8();
    func_800EF5A0(corner_pos[0], actor->rotation, -52.0f, 0, -49.0f);
    func_800EF5A0(corner_pos[1], actor->rotation, -52.0f, 0, 30.0f);
    func_800EF5A0(corner_pos[2], actor->rotation, 52.0f, 0, -49.0f);
    func_800EF5A0(corner_pos[3], actor->rotation, 52.0f, 0, 30.0f);
    for (i = 0; i < 4; i++) {
        func_800EF04C(corner_pos[i], actor->position);
    }
    for (i = 0; i < 0x3C; i++) {
        if (handcart->unk87C[i] != 0) {
            func_800EE7B4(handcart->unkC[i], handcart->unkC[i], handcart->unkC[i + 0x78], game_speed);
            // Matching: the * 1.0f is needed for the match.
            if (handcart->unkC[i][1] < (0.0f * 1.0f)) {
                handcart->unk87C[i] = 0U;
            } else {
                decay = func_800DC128(8, 0xF);
                if (decay < handcart->unk87C[i]) {
                    handcart->unk87C[i] -= decay;
                }
                handcart->unkC[i + 0x78][1] += -300.0f * game_speed;
                func_800EE7F8(handcart->unkC[i + 0x3C], corner_pos[handcart->unk87C[i + 0x3C]]);
                func_800EF4E4(&spark_pos, actor->rotation[0], actor->rotation[1], handcart->unkC[i][0],
                              handcart->unkC[i][1], handcart->unkC[i][2]);
                func_800EF04C(handcart->unkC[i + 0x3C], &spark_pos);
            }
        }
    }
}

void func_808014D8_chhandcart(Actor *actor, u32 corner)
{
    s32 spawned;
    s32 i;
    HandcartMemory *handcart;
    u8 *slot_flags;
    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    spawned = 0;
    i = 0;
    slot_flags = (u8 *) handcart;
    for (; i < 0x3C; i++) {
        if (slot_flags[0x87C] == 0) {
            slot_flags[0x87C] = 0xFFU;
            slot_flags[0x87C + 0x3C] = (s8) corner;
            func_800EFD24(handcart->unkC[i]);
            func_800EFA4C(handcart->unkC[i] + 0x168, func_800DC178(-15.0f, 15.0f),
                          func_800DC178(80.0f, 120.0), func_800DC178(-50.0f, -85.0f));
            spawned += 1;
            if (spawned >= 0x4) {
                return;
            }
        }
        slot_flags++;
    }
}

void func_80801638_chhandcart(Actor *actor, s32 side)
{
    if (actor->unk7C_12) {
        if (side != 0) {
            func_808014D8_chhandcart(actor, 0);
            func_808014D8_chhandcart(actor, 1);
            return;
        }
        func_808014D8_chhandcart(actor, 2);
        func_808014D8_chhandcart(actor, 3);
    }
}

f32 func_8080169C_chhandcart(Actor *actor, u32 is_right, f32 *out_pos)
{
    f32 x_offset;

    f32 ray_start[3];
    f32 hit_normal[3];

    if (is_right != 0) {
        x_offset = 58.0f;
    } else {
        x_offset = -58.0f;
    }
    func_800EF4E4(out_pos, actor->rotation[0], actor->rotation[1], x_offset, 0.0f, 0.0f);
    func_800EF04C(out_pos, actor->position);
    func_800EE7F8(ray_start, out_pos);
    ray_start[1] += 150.0f;
    out_pos[1] -= 150.0f;
    if (func_800BEF00(ray_start, out_pos, hit_normal, 0x20020U) == 0) {
        out_pos[1] = actor->position[1];
    }
    return out_pos[1];
}

void func_8080176C_chhandcart(Actor *actor)
{
    HandcartMemory *handcart;
    f32 right_pos[3];
    f32 left_pos[3];
    f32 tilt;

    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    func_8080169C_chhandcart(actor, 0, left_pos);
    func_8080169C_chhandcart(actor, 1, right_pos);
    tilt = func_800F1828(left_pos, right_pos);
    actor->position[1] = (left_pos[1] + right_pos[1]) * 0.5f;
    actor->rotation[2] = handcart->unk934[2] + tilt;
    if (actor->rotation[2] > 0.0f) {
        actor->position[1] += func_80013970(handcart->unk934[2]) * 58.0f;
        return;
    }
    actor->position[1] -= func_80013970(handcart->unk934[2]) * 58.0f;
}

void func_80801850_chhandcart(Actor *actor)
{
    HandcartMemory *handcart;
    f32 unk_0;
    f32 game_speed;

    s32 i;
    f32 *timers;

    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    handcart->unk91C = handcart->unk934[2];
    // Matching: the (f32) casts below are needed for the match.
    if (HANDCART_DATA(actor)->unkC > 12.0f) {
        if (handcart->unk934[2] < handcart->unk920) {
            handcart->unk934[2] = (f32) (handcart->unk934[2] + 1.0f);
        } else if (handcart->unk920 < handcart->unk934[2]) {
            handcart->unk934[2] = (f32) (handcart->unk934[2] - 1.0f);
        }
        if (handcart->unk920 > 0.0f) {
            if (handcart->unk920 < handcart->unk934[2]) {
                handcart->unk934[2] = handcart->unk920;
            }
        } else if (handcart->unk934[2] < handcart->unk920) {
            handcart->unk934[2] = handcart->unk920;
        }
    } else {
        handcart->unk934[2] = (f32) (handcart->unk934[2] * 0.65f);
    }
    if (((handcart->unk934[2] < -5.0f) || (handcart->unk934[2] > 5.0f)) && (handcart->unk924 != 0)) {
        func_800C4350(handcart->unk924, actor->position, 0);
    }
    if ((handcart->unk91C >= 2.0f) && (handcart->unk934[2] < 2.0f)) {
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_808046F4_chhandcart);
        handcart->unk934[0] = 0.1f;
        if (func_800DC0C0() < 0.5f) {
            handcart->unk934[2] = -3.0f;
        }
    }
    if ((handcart->unk91C <= -2.0f) && (handcart->unk934[2] > -2.0f)) {
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_808046F4_chhandcart);
        handcart->unk934[1] = 0.1f;
        if (func_800DC0C0() < 0.5f) {
            handcart->unk934[2] = 3.0f;
        }
    }
    if ((func_800DC0C0() < 0.1f) && (HANDCART_DATA(actor)->unkC > 5.0f)) {
        if (handcart->unk934[2] < 0.0f) {
            handcart->unk934[0] = 0.1f;
        }
        if (handcart->unk934[2] > 0.0f) {
            handcart->unk934[1] = 0.1f;
        }
    }
    game_speed = func_800D8FF8();
    i = 0;
    timers = (f32 *) handcart;
    do {
        if (timers[0x24D] >= 0.0f) {
            timers[0x24D] = (timers[0x24D] - game_speed);
            func_80801638_chhandcart(actor, i);
        }
        i += 1;
        timers += 1;
    } while (i != 2);
    func_8080176C_chhandcart(actor);
}

void func_80801BA4_chhandcart(Actor *actor)
{
    HandcartMemory *handcart;
    f32 blend;

    blend = 0.1f;
    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    func_80105A9C(actor, HANDCART_DATA(actor)->unkC * 10.0f);
    func_80105834(actor);
    handcart->unk920 = func_800F10B4(HANDCART_DATA(actor)->unkC, 0.0f, 100.0f, 0.0f,
                                    func_800F1DCC(actor->rotation[1], handcart->unk8) * 3.0f);
    handcart->unk8 = (f32) actor->rotation[1];
    if (handcart->unk8F7 == 0) {
        blend = 1.0f;
        handcart->unk8F7 = 1U;
    }
    actor->rotation[0] += func_800F1DCC(actor->unk50, actor->rotation[0]) * blend;
    actor->rotation[1] += func_800F1DCC(actor->unk54, actor->rotation[1]) * blend;
    func_80801850_chhandcart(actor);
    func_80800CD0_chhandcart(actor);
    func_80801290_chhandcart(actor);
}

void func_80801CBC_chhandcart(Actor *actor)
{
    HandcartMemory *handcart;
    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    HANDCART_DATA(actor)->unkC *= 0.95f;
    actor->rotation[0] += func_800F1DCC(0.0f, actor->rotation[0]) * 0.05f;
    handcart->unk934[2] += (func_800F1DCC(0, handcart->unk934[2]) * 0.05f);
}

void func_80801D50_chhandcart(Actor *actor)
{
    Actor *mary;
    f32 game_speed;
    HandcartMemory *handcart;

    if (actor->unk3C == 0) {
        func_80800830_chhandcart(actor);
        return;
    }
    game_speed = func_800D8FF8();
    mary = func_80106790(actor->unk3C);
    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    switch (actor->unk70_10) {
        case 2:
            func_80800830_chhandcart(actor);
            // Only as Banjo and Kazooie
            if ((func_80090178(ALLOW_BK) != 0) && (func_8010C9B0(actor->position, 0x64) != 0)) {
                // Set race intro flag
                func_800DA544(FLAG_508_FTT_GGM_CANARY_MARY_RACE_INTRO);
                func_80800214_chhandcart(mary);
            }
            break;
        case 3:
            if (func_8010CB0C(actor->position, 0x32, 0x32, 0) != 0) {
                // Set race intro flag
                func_800DA544(FLAG_508_FTT_GGM_CANARY_MARY_RACE_INTRO);
                func_808010D8_chhandcart(actor, 4);
            }
            break;
        case 4: {
            f32 look_rot[3] = D_80804DB8_chhandcart;
            f32 angle_diff;
            func_800907C0(actor->position);
            look_rot[1] = func_80090010();
            angle_diff = func_800F1DCC(actor->rotation[1], look_rot[1]);
            if ((angle_diff < -35.0f) || (angle_diff > 35.0f)) {
                look_rot[1] += angle_diff * game_speed * 5.0f;
                func_800906DC(look_rot);
            } else {
                func_80800214_chhandcart(mary);
            }
            break;
        }
        case 5:
            func_8080111C_chhandcart(actor);
            break;
        case 6:
            HANDCART_DATA(actor)->unkC =
                func_8080115C_chhandcart(&handcart->unk4, HANDCART_DATA(actor)->unkC);
            func_80801BA4_chhandcart(actor);
            func_8080111C_chhandcart(actor);
            if (func_80105A5C(actor) != 0) {
                func_80800EA0_chhandcart(actor);
                func_808010D8_chhandcart(actor, 7);
            }
            break;
        case 9:
        case 10:
        case 11:
            HANDCART_DATA(actor)->unkC =
                func_8080115C_chhandcart(&handcart->unk4, HANDCART_DATA(actor)->unkC);
            func_80801BA4_chhandcart(actor);
            func_8080111C_chhandcart(actor);
            break;
        case 7:
        case 8:
        case 12:
        case 13:
            func_80801CBC_chhandcart(actor);
            func_80801290_chhandcart(actor);
            break;
        case 14:
        case 15:
            func_80800830_chhandcart(actor);
            func_80801CBC_chhandcart(actor);
    }
    if ((handcart->unk8F5 == 1) || (handcart->unk8F5 == 3)) {
        func_80800B00_chhandcart(actor);
        func_80800528_chhandcart(actor);
    }
}

void func_80801FF4_chhandcart(s32 arg0)
{
}

void func_80801FFC_chhandcart(Actor *actor)
{
    Actor *mary;
    f32 unk_0;
    f32 spawn_pos[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x226, actor->position), spawn_pos);
    mary = func_80108528(0x51E, spawn_pos, 0, &actor);
    actor->unk3C = mary->unk0;
    mary->unk3C = actor->unk0;
    func_80100120(mary);
}

void func_80802068_chhandcart(Actor *actor, s32 arg1)
{
    Prop *prop;
    if (func_80800090_chhandcart() == 1) {
        arg1 = 1 - arg1;
    }
    if (arg1 != 0) {
        prop = _gccubesearch_entrypoint_1(0x314, actor->position);
    } else {
        prop = _gccubesearch_entrypoint_1(0x313, actor->position);
    }
    func_800EE88C(actor->position, prop->position);
    // Cart rotation when spawned in normal GGM
    actor->rotation[1] = prop->FlagOrRotation;
}

void func_80802120_chhandcart(Actor *actor)
{
    HandcartMemory *handcart;
    Prop *prop;
    Prop *reward_prop;
    handcart = (HandcartMemory *) func_80100094(actor, 0U);
    actor->scale = 0.425f;
    // Race 1 or 2, depending on whether the first reward was spawned
    actor->unk64_19 = func_800D0A9C(0xC, 1);
    handcart->unk8F4 = 0;
    handcart->unk4 = 0.0f;
    if (_glcutDll_entrypoint_20() != 0) {
        if (func_800EA05C() == MAP_C7_GGM_GLITTER_GULCH_MINE) {
            func_80108B04(actor, 0);
        }
    } else {
        if ((func_800DA298(FLAG_066_PROGRESS_GGM_CANARY_MARY_FREED_1) == 0) ||
            (func_800D0A9C(4, 4) != 0)) {
            func_80103140(actor, 0x68BU, actor->unk0->unk16);
            return;
        }
        switch (func_80800000_chhandcart()) {
            case 0:
                if (func_800DA298(FLAG_507_PROGRESS_GGM_CANARY_MARY_FREED_READY_TO_RACE) == 0) {
                    func_80103140(actor, 0x68BU, actor->unk0->unk16);
                }
                func_80802068_chhandcart(actor, 1 - actor->unk64_19);
                break;

            case 1:
                if (actor->unk64_19) {
                    handcart->unk0 = _glsplinefind_entrypoint_0(0x314, actor->position);
                    prop = _gccubesearch_entrypoint_1(0x15U, actor->position);
                } else {
                    handcart->unk0 = _glsplinefind_entrypoint_0(0x313, actor->position);
                    prop = _gccubesearch_entrypoint_1(0x16U, actor->position);
                }
                // Matching: empty block needed for the match.
                if (handcart->unk928[0]) {
                }
                func_800EE88C(handcart->unk928, prop->position);
                func_801058C4(actor, (s16) handcart->unk0, HANDCART_DATA(actor)->unkC, 0);
                func_80801BA4_chhandcart(actor);
                break;

            case 2:
                if (actor->unk64_19) {
                    reward_prop = _gccubesearch_entrypoint_0(0x201, actor);
                } else {
                    reward_prop = _gccubesearch_entrypoint_0(0x1F6, actor);
                }
                func_800EE88C(handcart->rewardSpawn, reward_prop->position);
                func_80802068_chhandcart(actor, actor->unk64_19);
                if (actor->unk64_19 && (func_80800090_chhandcart() == 2)) {
                    func_80103140(actor, 0x68BU, actor->unk0->unk16);
                }
        }

        func_80108B04(actor, 0);
    }
}

void func_80802394_chhandcart(Actor *actor)
{
    func_801015D0(actor);
}

// Plays a Canary Mary dialog.
void func_808023B4_chhandcart(Actor *actor, u32 dialog_id, u32 arg2)
{
    arg2 = arg2 | 0x4;
    _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, arg2, actor->position, 0x36);
    actor->unk74_30 = 1;
}

void func_80802400_chhandcart(Actor *actor, s32 arg1)
{
    f32 pos[3];

    func_800EE7F8(pos, actor->position);
    pos[1] += 75.0f;
    if ((arg1 == 0) || (arg1 == 0x1B) || (arg1 == 0x1F)) {
        _capod_entrypoint_19(pos);
    }
}

s32 func_80802468_chhandcart(Actor *actor, s32 event, s32 arg2)
{
    Actor *mary;
    s32 dialog_id;

    switch (event) {
        case 0x1F:
            func_80802394_chhandcart(actor);
            break;
        case 0xE:
            func_80802400_chhandcart(func_80106790(actor->unk3C), arg2);
            return 3;

        case 0xB:
            mary = func_80106790(actor->unk3C);
            dialog_id = 0;
            if (arg2 != 0x19) {
                if (arg2 == 0x1D) {
                    dialog_id = 0xF85;
                }
            } else {
                dialog_id = 0xFAF;
            }
            if (dialog_id != 0) {
                func_80800858_chhandcart(actor, mary, 2, 1);
                func_808023B4_chhandcart(mary, dialog_id, 0xB);
            }
            return 4;

        case 0x3D:
            func_80801FFC_chhandcart(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080256C_chhandcart(Actor *actor, u32 gfx)
{
    ImageStruct *image;
    s32 i;
    f32 filler;
    f32 scale[3];
    HandcartMemory *memory;
    memory = (HandcartMemory *) func_80100094(actor, 0U);
    func_801018A4(actor, gfx);
    if (actor->unk7C_12) {
        image = func_800D674C(0x9E2);
        func_800E2588(2);
        func_800E2594(gfx, image);
        func_800EFA4C(scale, 0.06f, 0.03f, 0.06f);
        for (i = 0; i != 0x3C; i++) {
            if (memory->unk87C[i] != 0) {
                func_800E2720(gfx, 0, 0, memory->unkC[i + 0x3C], scale,
                              memory->unk87C[i]);
            }
        }

        func_800E2A14(gfx);
    }
}

void *chhandcart_entrypoint_0(void)
{
    return &D_80804DC4_chhandcart;
}

// Plays Canary Mary's dialog/footstep sounds.
void func_80802690_chhandcart(Actor *actor)
{
    CanaryMaryMemory *memory;
    f32 *pad;

    memory = (CanaryMaryMemory *) func_80100094(actor, 0U);
    memory->unk0 = memory->unk0 - func_800D8FF8();
    switch (func_801022E4(actor)) {
        case 0x7D:
            _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_808046C0_chhandcart, 0.1f);
            if (((f32) memory->unk0 <= 0.0f) && (func_800DC298(0.03f) != 0) &&
                (func_800C0638() == 0)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_808046D4_chhandcart);
                memory->unk0 = 1.5f;
            }
            return;
        case 0x89:
            _subaddieaudioquick_entrypoint_4(actor, actor->position, &D_808046C0_chhandcart,
                                             &D_80804E0C_chhandcart);
            return;
        case 0x8A:
            _subaddieaudioquick_entrypoint_4(actor, actor->position, &D_808046C0_chhandcart,
                                             &D_80804E18_chhandcart);
            return;
        case 0x85:
            _subaddieaudioquick_entrypoint_4(actor, actor->position, &D_808046E8_chhandcart,
                                             &D_80804E2C_chhandcart);
            return;
        case 0x80:
            _subaddieaudioquick_entrypoint_4(actor, actor->position, &D_808046C0_chhandcart,
                                             &D_80804E38_chhandcart);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_808046E8_chhandcart, 0.9f);
    }
}

void func_8080282C_chhandcart(Actor *actor, s32 side, s32 alt)
{
    Prop *marker;

    if (func_80800090_chhandcart() == 1) {
        side = 1 - side;
    }
    if ((side != 0) || (alt != 0)) {
        marker = _gccubesearch_entrypoint_1(0x385, actor->position);
    } else {
        marker = _gccubesearch_entrypoint_1(0x384, actor->position);
    }
    func_800EE88C(actor->position, marker->position);
    actor->rotation[1] = marker->FlagOrRotation;
}

void func_808028F0_chhandcart(Actor *actor)
{
    f32 spline_pos[3];
    CanaryMaryMemory *mary_memory;
    mary_memory = (CanaryMaryMemory *) func_80100094(actor, 0U);
    actor->unk64_19 = func_800D0A9C(0xC, 1);
    if (_glcutDll_entrypoint_20() != 0) {
        if (func_800EA05C() == MAP_C7_GGM_GLITTER_GULCH_MINE) {
            func_8080282C_chhandcart(actor, 0, 1);
            func_808031D0_chhandcart(actor, 0x11);
        } else {
            func_800FFAB0(actor);
            return;
        }
    } else if (func_800DA298(FLAG_066_PROGRESS_GGM_CANARY_MARY_FREED_1) != 0) {
        if (func_800EA05C() == MAP_DB_GGM_CANARY_CAVE) {
            func_800FFAB0(actor);
            return;
        }
        switch (func_80800194_chhandcart(actor)) {
            case 0:
                func_8080282C_chhandcart(actor, 1 - actor->unk64_19, 0);
                break;

            case 1: // in race
                if (actor->unk64_19) {
                    mary_memory->unkC = _glsplinefind_entrypoint_0(0x385, spline_pos);
                } else {
                    mary_memory->unkC = _glsplinefind_entrypoint_0(0x384, spline_pos);
                }
                func_80800024_chhandcart(0);
                func_808031D0_chhandcart(actor, 5);
                break;

            case 2: // won race
                func_8080282C_chhandcart(actor, actor->unk64_19, 0);
                func_808031D0_chhandcart(actor, 0xF);
                if (actor->unk64_19) {
                    mary_memory->unkC = _glsplinefind_entrypoint_0(0x389, spline_pos);
                }
                func_80800214_chhandcart(actor);
        }

        if (func_800DA298(FLAG_507_PROGRESS_GGM_CANARY_MARY_FREED_READY_TO_RACE) == 0) {
            mary_memory->unkC = _glsplinefind_entrypoint_0(0x388, actor->position);
            func_801058C4(actor, (s16) mary_memory->unkC, HANDCART_DATA(actor)->unkC, 0);
            func_808031D0_chhandcart(actor, 0x14);
        }
    } else if (func_800EA05C() != MAP_DB_GGM_CANARY_CAVE) {
        func_800FFAB0(actor);
        return;
    } else {
        mary_memory->unkC = _glsplinefind_entrypoint_0(0x384, spline_pos);
        func_80802CE8_chhandcart(actor, 0x18);
    }
    _suexpression_entrypoint_7(actor, 1, 0x36);
    _suexpression_entrypoint_12(func_80100094(actor, 1U), 45.0f, 15.0f);
}

void func_80802B74_chhandcart(Actor *actor)
{
    if (actor->unk70_10 == 0x10) {
        func_800904C8(0x28);
    }
    if (func_80100094(actor, 1U) != NULL) {
        _suexpression_entrypoint_8(actor, 1);
    }
}

void func_80802BC8_chhandcart(Actor *actor)
{
    CanaryMaryMemory *mary;
    f32 blend;
    float target_roll;
    blend = 0.1f;
    mary = (CanaryMaryMemory *) func_80100094(actor, 0U);
    func_80105A9C(actor, HANDCART_DATA(actor)->unkC * 10.0f);
    func_80105834(actor);
    target_roll =
        (func_800F1DCC(actor->rotation[1], mary->unk4) * HANDCART_DATA(actor)->unkC) * 0.5f;
    mary->unk8 = (f32) ((target_roll - mary->unk8) * 0.02f);
    actor->rotation[2] = mary->unk8;
    mary->unk4 = (f32) actor->rotation[1];
    if (mary->unkE == 0) {
        blend = 1.0f;
        mary->unkE = 1U;
    }
    actor->rotation[0] += func_800F1DCC(actor->unk50 * 0.1f, actor->rotation[0]) * blend;
    actor->rotation[1] += func_800F1DCC(actor->unk54, actor->rotation[1]) * blend;
}

void func_80802CE8_chhandcart(Actor *actor, s32 state)
{
    Actor *linked;
    CanaryMaryMemory *mary;
    s32 dialog_id;
    s32 reply_dialog;
    s32 choice;
    s32 race_id;
    mary = (CanaryMaryMemory *) func_80100094(actor, 0U);
    if (actor->unk3C != 0) {
        linked = func_80106790(actor->unk3C);
    } else {
        linked = NULL;
    }
    switch (actor->unk70_10) {
        case 19:
            actor->unk64_16 = 1;
            break;

        case 23:
            func_80800AB0_chhandcart(linked);
            break;

        case 15:
            func_80090708(0);
    }

    func_80102424(actor, state);
    switch (actor->unk70_10) {
        case 24:
            _subaddieDll_entrypoint_0(actor);
            break;

        case 25:
            choice = func_8008FD70();
            if (choice != 1) {
                if (choice == 0x4000) {
                    func_808023B4_chhandcart(actor, 0xFA9, 0xB);
                    break;
                }
            } else {
                func_808023B4_chhandcart(actor, 0xF7F, 0xB);
                break;
            }
            func_80802CE8_chhandcart(actor, 0x1A);
            break;

        case 26:
            HANDCART_DATA(actor)->unkC = 40.0f;
            func_801058C4(actor, *(s16 *) &mary->unkC, 40.0f, 0);
            func_80802BC8_chhandcart(actor);
            func_800C01A8(0x6B, 0);
            _capod_entrypoint_13(actor->unk0, actor->unk0, 0, 0x28B0);
            break;

        case 19:
            actor->unk64_16 = 0;
            break;

        case 20:
            func_800DA544(FLAG_507_PROGRESS_GGM_CANARY_MARY_FREED_READY_TO_RACE);
            HANDCART_DATA(actor)->unkC = 40.0f;
            func_8080090C_chhandcart(linked, 0x1F, 0x28B0, actor->unk0);
            break;

        case 23:
            actor->unk58 = 1.0f;
            break;

        case 5:
            func_80800998_chhandcart(linked, 0U, 5U, linked->unk0);
            func_808023B4_chhandcart(actor, 0xCEC, 3);
            func_801058C4(actor, *(s16 *) &mary->unkC, HANDCART_DATA(actor)->unkC, 0);
            break;

        case 6:
            func_800FDC28(0x15U);
            if (actor->unk64_19) {
                HANDCART_DATA(actor)->unkC = 25.0f;
            } else {
                HANDCART_DATA(actor)->unkC = 15.0f;
            }
            break;

        case 7:
            func_80800024_chhandcart(2);
            func_80090658(1);
            break;

        case 8:
            if (func_80105AE8(actor) < 0.93f) {
                func_80800A24_chhandcart(linked, actor->unk64_19 ? 4 : 2, 4);
            } else {
                func_80800998_chhandcart(linked, 1U, 5U, actor->unk0);
            }
            break;

        case 9:
            func_80800024_chhandcart(1);
            func_800FDC28(0U);
            func_80800EE4_chhandcart(linked, 0);
            func_80800214_chhandcart(actor);
            break;

        case 10:
            if (func_80105AE8(linked) < 0.93f) {
                func_80800A24_chhandcart(linked, actor->unk64_19 ? 3 : 1, 4);
            } else {
                func_80800998_chhandcart(linked, 1U, 5U, linked->unk0);
            }
            break;

        case 14:
            actor->unk58 = 0.5f;
            break;

        case 16:
            if (func_800D0A9C(0xC, 1) != 0) {
                dialog_id = 0xF88;
            } else {
                dialog_id = 0xF83;
            }
            func_80800858_chhandcart(linked, actor, 3, 1);
            func_808023B4_chhandcart(actor, dialog_id, 3);
            func_800FDC28(0U);
            func_800FC660(0x17U);
            break;

        case 15:
            reply_dialog = 0;
            func_80090658(0);
            func_80090734(1, actor->position);
            func_80800858_chhandcart(linked, actor, 2, 1);
            race_id = func_80800090_chhandcart();
            switch (race_id) {
                case 1:
                    if (func_800D0A9C(0xC, 1) != 0) {
                        reply_dialog = 0xF87;
                    } else {
                        reply_dialog = 0xF82;
                    }
                    break;

                case 2:
                    if (func_800D0A9C(0xC, 1) != 0) {
                        reply_dialog = 0xF89;
                    } else {
                        reply_dialog = 0xF84;
                    }
            }

            func_808023B4_chhandcart(actor, reply_dialog, 0xB);
            break;

        case 18:
            HANDCART_DATA(actor)->unkC = 40.0f;
            func_801058C4(actor, *(s16 *) &mary->unkC, 40.0f, 0);
            func_80802BC8_chhandcart(actor);
            func_8080090C_chhandcart(linked, 0x1B, 0x20B0, actor->unk0);
    }

    func_80800F4C_chhandcart(actor);
}

void func_808031D0_chhandcart(Actor *actor, s32 state)
{
    func_80802CE8_chhandcart(actor, state);
    if (actor->unk3C != 0) {
        func_80800FA0_chhandcart(func_80106790(actor->unk3C), state);
    }
}

void func_80803218_chhandcart(Actor *actor, Actor *rival)
{
    f32 rival_progress;
    f32 progress;
    f32 gamespeed;
    float max_speed;
    u32 variant;
    if (rival->unk7C_0) {
        rival_progress = func_80105AE8(rival);
    } else {
        rival_progress = 1.0f;
    }
    progress = func_80105AE8(actor);
    gamespeed = func_800D8FF8();
    // Matching: redundant condition with an empty body is needed for the match.
    if (gamespeed && gamespeed) {
    }
    variant = actor->unk64_19;
    if (rival_progress <= (progress - 6553 / 65536.0f)) {
        func_808031D0_chhandcart(actor, 0x10);
        return;
    }
    if (rival_progress <= (progress - ((variant != 0) ? (1310 / 65536.0f) : (655 / 65536.0f)))) {
        if ((((variant != 0) ? 80.0f : 75.0f) - 10.0f) < HANDCART_DATA(actor)->unkC) {
            HANDCART_DATA(actor)->unkC =
                HANDCART_DATA(actor)->unkC - (((variant != 0) ? 30.0f : 20.0f) * gamespeed);
        }
    } else if ((1310 / 65536.0f + progress) <= rival_progress) {
        max_speed = (variant != 0) ? 80.0f : 75.0f;
        if (HANDCART_DATA(actor)->unkC < (10.0f + max_speed)) {
            HANDCART_DATA(actor)->unkC += ((variant != 0) ? 30.0f : 20.0f) * gamespeed;
        }
    } else if (HANDCART_DATA(actor)->unkC < ((variant != 0) ? 80.0f : 75.0f)) {
        HANDCART_DATA(actor)->unkC += ((variant != 0) ? 30.0f : 20.0f) * gamespeed;
    }
}

s32 func_80803448_chhandcart(Actor *actor)
{
    u32 pad;
    f32 top[3];
    f32 bottom[3];
    f32 hit_normal[3];
    f32 gamespeed;
    gamespeed = func_800D8FF8();
    func_800EE7F8(top, actor->position);
    top[1] = top[1] + 50.0f;
    func_800EE7F8(bottom, actor->position);
    bottom[1] -= 50.0f;
    if ((func_800BEF00(top, bottom, hit_normal, 0x20020U) == 0) || bottom[1] < actor->position[1]) {
        actor->position[1] = (actor->position[1] - (250.0f * gamespeed));
        return 0;
    }
    return 1;
}

void func_80803514_chhandcart(Actor *actor)
{
    f32 turn_diff;
    f32 anim_progress;
    f32 step;
    s32 anim_id;

    actor->unk54 = func_8010CD28(actor);
    turn_diff = func_800F1DCC(actor->rotation[1], actor->unk54);
    if ((turn_diff < -10.0f) || (turn_diff > 10.0f)) {
        anim_progress = func_80101F24(actor);
        anim_id = func_801022E4(actor);
        switch (anim_id) {
            case 0x80:
                if ((anim_progress > 0.75f) && (anim_progress < 0.88f)) {
                    func_80102B2C(actor, 6.0f);
                }
                break;

            case 0x85:
                if (((anim_progress > 0.76f) && (anim_progress < 0.99f)) || ((anim_progress > 0.25f) && (anim_progress < 0.51f))) {
                    if (turn_diff > 0.0f) {
                        step = -6.0f;
                    } else {
                        step = 6.0f;
                    }

                    actor->rotation[1] = (f32) (actor->rotation[1] + step);
                }
        }
    }
}

void func_80803698_chhandcart(Actor *actor)
{
    _sudeflect_entrypoint_1(actor->position, 180.0f, 0.0f, 65.0f, 0x1E);
}

void func_808036D0_chhandcart(s32 unused, Actor *linked)
{
    HandcartMemory *memory;

    memory = (HandcartMemory *) func_80100094(linked, 0U);

    if (0) {
    }
    if (func_80105998(linked, 0.9399872f) != 0) {
        memory->unk8F8 = 0;
        func_80800998_chhandcart(linked, 1, 5, linked->unk0);
    }
}

void func_80803730_chhandcart(Actor *actor, Actor *linked)
{
    HandcartMemory *memory;
    memory = (HandcartMemory *) func_80100094(linked, 0U);
    // Matching: empty block is needed for the match.
    if (actor->unk0) {
    }
    if (func_80105998(actor, 0.9399872f) != 0) {
        memory->unk8F8 = 0;
        func_80800998_chhandcart(linked, 1, 5, actor->unk0);
    }
}

void func_80803794_chhandcart(Actor *actor)
{
    f32 gamespeed;
    Actor *linked;
    HandcartMemory *linked_memory;
    s32 pad[2];

    gamespeed = func_800D8FF8();
    if (actor->unk3C != 0) {
        linked = func_80106790(actor->unk3C);
        linked_memory = (HandcartMemory *) func_80100094(linked, 0U);
    } else {
        linked = NULL;
        linked_memory = NULL;
    }
    _suexpression_entrypoint_10(func_80100094(actor, 1U), actor->unk0, 0);
    switch (actor->unk70_10) {
        case 24:
            if (func_800DA298(FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG) != 0) {
                if (func_80090270() == 0) {
                    func_80802CE8_chhandcart(actor, 0x19);
                }
            } else if (func_800DA298(FLAG0_001_STATE_CANARY_MARY_CAGE_BROKEN) == 0) {
                if ((_subaddiedialog_entrypoint_3(actor->position, (s32) actor->rotation[1], 0x1F4,
                                                  0x46, 6) != 0) &&
                    (func_80090178(ALLOW_BK | ALLOW_DETONATOR) != 0)) {
                    if (func_800DA9E4(FLAG_42A_FTT_CANARY_MARY_CANARY_CAVE, 1) == 0) {
                        func_808023B4_chhandcart(actor, 0xF7E, 0xB);
                    } else if (_subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1],
                                                            0x1F4, 0x46, 6) != 0) {
                        func_808023B4_chhandcart(actor, 0xFA7, 0xB);
                    }
                }
            }
            break;
        case 26:
            func_80802BC8_chhandcart(actor);
            if (func_80105A5C(actor) != 0) {
                func_800DA544(FLAG_066_PROGRESS_GGM_CANARY_MARY_FREED_1);
                _glcutDll_entrypoint_6(MAP_C7_GGM_GLITTER_GULCH_MINE, 0x1A);
            }
            break;
        case 20:
            func_80802BC8_chhandcart(actor);
            if (func_80105A5C(actor) != 0) {
                func_80105634(actor);
                func_808031D0_chhandcart(actor, 0x15);
            }
            break;
        case 21:
            if ((func_80803448_chhandcart(actor) != 0) && (func_80101E14(actor, 0.999f) != 0)) {
                func_808031D0_chhandcart(actor, 0x16);
            }
            break;
        case 22:
            if (func_80101DDC(actor) != 0) {
                func_808031D0_chhandcart(actor, 0x17);
            }
            break;
        case 23:
            if (actor->unk58 > 0.0f) {
                actor->unk58 = (f32) (actor->unk58 - gamespeed);
            } else {
                _glcutDll_entrypoint_17();
                func_808031D0_chhandcart(actor, 2);
            }
            break;
        case 2:
            func_80803698_chhandcart(actor);
            func_80803514_chhandcart(actor);
            if (!actor->unk74_30) {
                if (func_80090178(ALLOW_BK) != 0) {
                    if (func_800DA298(FLAG_508_FTT_GGM_CANARY_MARY_RACE_INTRO) != 0) {
                        if (_subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1],
                                                         0xC8, 0x46, 6) != 0) {
                            func_808023B4_chhandcart(actor, actor->unk64_19 ? 0xFAE : 0xFAD, 0xB);
                        }
                    } else if (_subaddiedialog_entrypoint_3(actor->position, (s32) actor->rotation[1],
                                                            0xC8, 0x46, 6) != 0) {
                        func_800DA544(FLAG_508_FTT_GGM_CANARY_MARY_RACE_INTRO);
                        func_80800858_chhandcart(linked, actor, 2, 0);
                        if (func_800DA298(FLAG_57A_PROGRESS_GGM_CANARY_MARY_FREED_3) != 0) {
                            func_808023B4_chhandcart(actor, 0xF80, 0xB);
                        } else {
                            func_808023B4_chhandcart(actor, 0xFB7, 0xB);
                        }
                    }
                } else if (func_800DA298(FLAG_054_FTT_GGM_DetonatorTalkToCanaryMary) != 0) {
                    if (_subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1], 0xC8,
                                                     0x46, 6) != 0) {
                        func_808023B4_chhandcart(actor, actor->unk64_19 ? 0xFB2 : 0xFB1, 0xB);
                    }
                } else if (_subaddiedialog_entrypoint_3(actor->position, (s32) actor->rotation[1],
                                                        0xC8, 0x46, 6) != 0) {
                    func_800DA544(FLAG_054_FTT_GGM_DetonatorTalkToCanaryMary);
                    func_808023B4_chhandcart(actor, 0xFB0, 0xB);
                }
            }
            break;
        case 5:
            func_80803514_chhandcart(actor);
            func_80803698_chhandcart(actor);
            func_80802BC8_chhandcart(actor);
            break;
        case 6:
            func_80803218_chhandcart(actor, linked);
            func_80802BC8_chhandcart(actor);
            if (func_80105998(linked, 0.05f) != 0) {
                linked_memory->unk8F8 = 1;
                func_80800A24_chhandcart(linked, linked->unk64_19 ? 3 : 1, 4);
            }
            func_808036D0_chhandcart((s32) actor, linked);
            if (func_80105A5C(actor) != 0) {
                func_808031D0_chhandcart(actor, 9);
            }
            break;
        case 7:
            func_80803218_chhandcart(actor, linked);
            func_80802BC8_chhandcart(actor);
            func_80803730_chhandcart(actor, linked);
            if (func_80090248() != 0) {
                func_808031D0_chhandcart(actor, 8);
            }
            if (func_80105A5C(actor) != 0) {
                func_808031D0_chhandcart(actor, 0xC);
            }
            break;
        case 8:
            func_80803218_chhandcart(actor, linked);
            func_80802BC8_chhandcart(actor);
            func_80803730_chhandcart(actor, linked);
            if (func_80105A5C(actor) != 0) {
                func_808031D0_chhandcart(actor, 0xC);
            }
            break;
        case 9:
            func_808036D0_chhandcart((s32) actor, linked);
            if (func_80105A5C(linked) != 0) {
                func_80800EA0_chhandcart(linked);
                func_80800EE4_chhandcart(linked, 0);
            }
            if ((func_80803448_chhandcart(actor) != 0) && (func_80101E14(actor, 0.999f) != 0)) {
                func_808031D0_chhandcart(actor, 0xA);
            }
            break;
        case 10:
            func_808036D0_chhandcart((s32) actor, linked);
            func_80803698_chhandcart(actor);
            if (func_80105A5C(linked) != 0) {
                func_80800EA0_chhandcart(linked);
                func_80800EE4_chhandcart(linked, 0);
            }
            if (func_80101DDC(actor) != 0) {
                func_808031D0_chhandcart(actor, 0xB);
            }
            break;
        case 11:
            func_808036D0_chhandcart((s32) actor, linked);
            func_80803698_chhandcart(actor);
            func_80803514_chhandcart(actor);
            if (func_80105A5C(linked) != 0) {
                func_80800EE4_chhandcart(linked, 0);
                func_808031D0_chhandcart(actor, 0xE);
            }
            break;
        case 12:
            if ((func_80803448_chhandcart(actor) != 0) && (func_80101E14(actor, 0.999f) != 0)) {
                func_808031D0_chhandcart(actor, 0xD);
            }
            break;
        case 13:
            func_80803698_chhandcart(actor);
            if (func_80101DDC(actor) != 0) {
                func_808031D0_chhandcart(actor, 0xE);
            }
            break;
        case 14:
            if (actor->unk58 > 0.0f) {
                actor->unk58 = (f32) (actor->unk58 - gamespeed);
            } else {
                func_80800214_chhandcart(actor);
            }
            break;
        case 15:
            func_80803514_chhandcart(actor);
            func_80803698_chhandcart(actor);
            break;
        case 18:
            if (HANDCART_DATA(actor)->unkC < 150.0f) {
                HANDCART_DATA(actor)->unkC = HANDCART_DATA(actor)->unkC + (50.0f * gamespeed);
            }
            func_80802BC8_chhandcart(actor);
            if (func_80105A5C(actor) != 0) {
                func_80105634(actor);
                if (_gclevel_entrypoint_3(0x18) != 0) {
                    _glcutDll_entrypoint_6(0x136, 0x55);
                } else {
                    func_80800AB0_chhandcart(linked);
                    linked->unk3C = 0;
                    func_800FFAB0(actor);
                }
            }
    }
    func_80802690_chhandcart(actor);
    if ((linked_memory != NULL)) {
        switch (linked_memory->unk8F5) {
            case 2:
            case 4:
                func_80800B00_chhandcart(linked);
                func_80800528_chhandcart(linked);
        }
    }
}

s32 func_80803FC4_chhandcart(Actor *actor, s32 event, u32 param)
{
    HandcartMemory *linked_memory;
    u32 pad;
    Actor *linked;
    Actor *linked_actor;

    if (event >= 0x30) {
        if (event == 0x52) {
            goto case52;
        }
        return 0;
    }
    switch (event) {
        case 14:
            func_80802400_chhandcart(actor, param);
            return 3;
        case 47: // dialog ended: spawn race reward
            linked_memory = (HandcartMemory *) func_80100094(func_80106790(actor->unk3C), 0U);
            switch (*(s16 *) &param) {
                case 0xF84: // won race 1: jiggy
                    func_800D1000(0xC, 0x1, linked_memory->rewardSpawn, 1, actor->unk0);
                    break;
                case 0xF89: // won race 2: cheato page
                    func_800D1000(0x4, 0x4, linked_memory->rewardSpawn, 1, actor->unk0);
            }
            break;
        case 13:
            linked = func_80106790(actor->unk3C);
            switch (param & 0xFFFF) {
                case 1:
                    func_8080090C_chhandcart(linked, 0x1D, 0x2000, func_80101080());
                    break;
                case 4:
                    func_8080090C_chhandcart(linked, 0x19, 0x2000, func_80101080());
            }
            break;
        case 46: // dialog ended
            if (actor->unk3C != 0) {
                linked_actor = func_80106790(actor->unk3C);
            } else {
                linked_actor = NULL;
            }
            switch (*(s16 *) &param) {
                case 0xF7F:
                case 0xFA9:
                    func_800DA544(FLAG_57A_PROGRESS_GGM_CANARY_MARY_FREED_3);
                    func_80802CE8_chhandcart(actor, 0x1A);
                    break;
                case 0xF80:
                case 0xFB7:
                    func_80800AB0_chhandcart(linked_actor);
                    func_808031D0_chhandcart(actor, 2);
                    break;
                case 0xCEC: // 3-2-1-Go
                    func_808031D0_chhandcart(actor, 6);
                    break;
                case 0xF83:
                case 0xF88:
                    func_808001D0_chhandcart(actor, 0);
                    func_808000B4_chhandcart(actor);
                    func_800904C8(0x28U);
                    break;
                case 0xF82:
                    func_80800AB0_chhandcart(linked_actor);
                    func_808031D0_chhandcart(actor, 2);
                    break;
                case 0xF87:
                    func_80800AB0_chhandcart(linked_actor);
                    func_808031D0_chhandcart(actor, 2);
                    break;
                case 0xF85:
                    func_80800AB0_chhandcart(linked_actor);
                    func_808031D0_chhandcart(actor, 2);
                    actor->unk64_19 = 1;
                    linked_actor->unk64_19 = 1;
                    break;
                case 0xFAF:
                    func_80800AB0_chhandcart(linked_actor);
                    func_808031D0_chhandcart(actor, 0x12);
            }
            actor->unk74_30 = 0;
            break;
        case52:
            if (func_801022E4(actor) == 0x7D) {
                _gcdialogcamera_entrypoint_3(&D_80804E4C_chhandcart, actor->scale);
            } else {
                _gcdialogcamera_entrypoint_3(&D_80804E5C_chhandcart, actor->scale);
            }
            break;
        case 31:
            func_801015D0(actor);
            if ((actor->unk70_10 == 0x18) || (actor->unk70_10 == 0x19)) {
                func_800DF744(3, 1);
            } else {
                func_800DF744(3, 0);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080436C_chhandcart(void)
{
    func_801018A4();
}

void chhandcart_entrypoint_1(Actor *actor)
{
    func_80101F24(func_80106790((Unk80132ED0 *) actor));
}

void *chhandcart_entrypoint_2(void)
{
    return &D_80804E6C_chhandcart;
}
