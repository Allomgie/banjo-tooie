// Probably the Mayahem Temple kickball stadium guard: blocks the entrance and lets only a Stony
// through, with different dialogs for Stony and non-Stony.
#include "common.h"

extern void *D_80800700_chamazonstadiumguard;
extern f32 D_808006B0_chamazonstadiumguard[];
extern u8 D_80800760_chamazonstadiumguard[];
extern void _suexpression_entrypoint_12(void *, f32, f32);
typedef union {
    s32 local_0;
    struct {
        s16 local_0;
        s16 local_1;
    } local_1;
} AmazonGuardMessage37;
extern s32 D_80800770_chamazonstadiumguard[];
extern s32 D_8080078C_chamazonstadiumguard[];
extern void _subaddiedialog_entrypoint_7(void *, void *, void *);
extern s32 func_8010D278(void);
extern s32 D_808007A8_chamazonstadiumguard[];
extern s32 D_808007C4_chamazonstadiumguard[];
extern s32 D_808007D0_chamazonstadiumguard[];
extern u8 D_80800748_chamazonstadiumguard[];
extern u8 D_80800754_chamazonstadiumguard[];
extern void *func_80100094(Actor *, s32);
extern void _suexpression_entrypoint_10(void *, Unk80132ED0 *, s32);
extern s32 func_80101DDC(Actor *);
extern void func_80102424(Actor *, s32);
extern s32 func_8010CAC0(f32 *, s32);
extern void func_80102078(Actor *, f32);
extern s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern void func_80103014(Actor *);
extern void func_801020DC(Actor *, s32);
extern s32 func_800DB9B0(void);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 _chbadshad_entrypoint_2(Actor *, s32, f32, f32 *);
extern s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _sudeflect_entrypoint_4(s32, f32 *);
extern void _sudeflect_entrypoint_3(f32 *, f32 *, void *, void *, s32);
void func_80800488_chamazonstadiumguard();

void *chamazonstadiumguard_entrypoint_0()
{
    return &D_80800700_chamazonstadiumguard;
}

void func_8080000C_chamazonstadiumguard(f32 *data)
{
    data[10] = data[1];
    data[11] = data[2];
    data[12] = data[3];
}

void func_80800648_chamazonstadiumguard();

void func_808005CC_chamazonstadiumguard();

void func_80800530_chamazonstadiumguard();

// Stadium guard main update: proximity checks, state machine, deflects the player.
void func_80800028_chamazonstadiumguard(Actor *actor)
{
    s32 solid;
    f32 skel_pos[3];
    f32 hit_pos[3];
    f32 deflect_scale;
    f32 *pos;

    solid = 0;
    if (func_80100094(actor, 1)) {
        _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
    }
    switch (actor->unk70_10) {
        case 1:
            solid = 1;
            func_80800530_chamazonstadiumguard(actor);
            func_80800648_chamazonstadiumguard(actor);
            break;
        case 2:
            solid = 1;
            if (func_80101DDC(actor)) {
                func_80102424(actor, 3);
            }
            break;
        case 3:
            solid = 1;
            if (!func_8010CAC0(actor->position, 500)) {
                func_80102078(actor, 0.5f);
                func_80102424(actor, 1);
            } else {
                func_808005CC_chamazonstadiumguard(actor);
            }
            break;
        case 4:
            solid = 1;
            break;
        case 5:
            if (func_80101DDC(actor)) {
                if (_subaddieskeleton_entrypoint_2(actor->unk0, 4, skel_pos)) {
                    actor->position[0] = skel_pos[0];
                    actor->position[2] = skel_pos[2];
                } else {
                    actor->position[0] = D_808006B0_chamazonstadiumguard[0];
                    actor->position[2] = D_808006B0_chamazonstadiumguard[1];
                }
                func_80103014(actor);
                func_801020DC(actor, 0);
                func_80102424(actor, 6);
            }
            break;
        case 6:
            func_80800620_chamazonstadiumguard(actor);
            func_80800648_chamazonstadiumguard(actor);
            pos = actor->position;
            if (!func_800DB9B0() && !func_8010CAC0(pos, 3000) && !actor->unk7C_12) {
                func_800EE7F8(pos, (f32 *) &actor->actorData[4]);
                func_80103014(actor);
                func_80102424(actor, 1);
            }
            break;
        case 7:
            func_80800648_chamazonstadiumguard(actor);
            break;
        case 8:
            func_80800648_chamazonstadiumguard(actor);
    }
    if (actor->unk7C_12) {
        if ((s32) actor->unk70_10 >= 5) {
            deflect_scale = 0.8f;
        } else {
            deflect_scale = 1.0f;
        }
        if (_chbadshad_entrypoint_2(actor, 3, 2.5f, hit_pos)) {
            if (_sudeflect_entrypoint_1(hit_pos, 350.0f, 0.0f, deflect_scale * 160.0f, 10) & 2) {
                _sudeflect_entrypoint_4(9, actor->position);
            }
        }
    }
    if (solid) {
        _sudeflect_entrypoint_3((f32 *) &actor->actorData[4], actor->rotation,
                                D_80800748_chamazonstadiumguard, D_80800754_chamazonstadiumguard,
                                2);
    }
}

void func_808002F4_chamazonstadiumguard(Actor *arg0)
{
    if (func_80100094(arg0, 1) != 0) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}

s32 func_80800328_chamazonstadiumguard(Actor *actor, s32 msg, AmazonGuardMessage37 msg_data)
{
    switch (msg) {
        case 0x2E:
            func_80800488_chamazonstadiumguard(actor, msg_data.local_1.local_0,
                                               msg_data.local_1.local_1);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800760_chamazonstadiumguard, *(s32 *) &actor->scale);
            break;
        case 0x95:
            if (_glcutDll_entrypoint_20()) {
                func_80102424(actor, 8);
            } else if (func_800EA090() == 4) {
                actor->position[0] = D_808006B0_chamazonstadiumguard[0];
                actor->position[2] = D_808006B0_chamazonstadiumguard[1];
                func_80103014(actor);
                func_801020DC(actor, 0);
                func_80102424(actor, 6);
            }
            break;
        case 0x29:
            _suexpression_entrypoint_7(actor, 1, 0x30);
            _suexpression_entrypoint_12((void *) func_80100094(actor, 1), 65.0f, 15.0f);
            break;
        case 0x2A:
            if (func_80100094(actor, 1))
                _suexpression_entrypoint_8(actor, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

// Dialog callback: 0xF0A starts the event camera and steps aside, 0xF0C/0xF09/0xF0B end dialog.
void func_80800488_chamazonstadiumguard(actor, dialog_id, unk_2) s32 *actor;
s32 dialog_id;
s32 unk_2;
{
    switch (dialog_id) {
        case 0xF0A:
            func_800C01A8(0x64, 0, actor);
            _capod_entrypoint_13(*actor, 0, 0x24, 0x2010);
            func_80102424(actor, 5);
            return;

        case 0xF0C:
            func_80102424(actor, 6);
            return;

        case 0xF09:
            // Matching: empty block with dummy label needed for the match.
            if (1) {
                goto dummy_label_907775;
            dummy_label_907775:;
            }

        case 0xF0B:
            func_80102424(actor, 3);
    }
}

// Idle check: only a Stony (transformation 8) is let through; flag 0x59 picks state 5 vs 2.
void func_80800530_chamazonstadiumguard(s32 actor)
{
    s32 state;
    if (func_8010CAC0(actor + 4, 0x1F4)) {
        state = func_8010D284();
        if (state == 5) {
            return;
        }
        if (func_8010D284() == 10) {
            return;
        }
        state = func_8010D278();
        if (state == 8) {
            if (func_800DA298(0x59) != 0) {
                state = 5;
            } else {
                state = 2;
            }
            func_80102424(actor, state);
        } else {
            func_80102424(actor, 2);
        }
    }
}

// Pick the dialog set for Stony or non-Stony.
void func_808005CC_chamazonstadiumguard(s32 actor)
{
    s32 transform;
    transform = func_8010D278();
    if (transform == 8) {
        _subaddiedialog_entrypoint_7(actor, actor + 4, &D_80800770_chamazonstadiumguard);
    } else {
        _subaddiedialog_entrypoint_7(actor, actor + 4, &D_8080078C_chamazonstadiumguard);
    }
}

int func_80800620_chamazonstadiumguard(s32 actor)
{
    s32 pos;
    pos = actor + 4;
    _subaddiedialog_entrypoint_7(actor, pos, &D_808007A8_chamazonstadiumguard);
}

void func_80800648_chamazonstadiumguard(s32 actor)
{
    _subaddieaudioquick_entrypoint_4(actor, actor + 4, &D_808007C4_chamazonstadiumguard,
                                     &D_808007D0_chamazonstadiumguard);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
f32 D_808006B0_chamazonstadiumguard[2] = {-6221.0f, -5709.0f};
u32 D_808006B8_chamazonstadiumguard[18] = {
    0x0,        0x0,       0x40E00000, 0x1990000, 0x3F8CCCCD, 0x19A004A,
    0x40800000, 0x19B0049, 0x40800000, 0x19B0000, 0x40400000, 0x19C004A,
    0x40E00000, 0x1990249, 0x40E00000, 0x1990000, 0x40E00000, 0x1990000};
void *D_80800700_chamazonstadiumguard = (void *) 0x015F0116;
static u32 D_80800700_chamazonstadiumguard_rest[17] = {0x6610001,
                                                       (u32) &D_808006B8_chamazonstadiumguard,
                                                       (u32) func_80800028_chamazonstadiumguard,
                                                       (u32) func_80105834,
                                                       (u32) func_80101870,
                                                       0x1F400000,
                                                       0x0,
                                                       0x0,
                                                       0x160,
                                                       (u32) func_808002F4_chamazonstadiumguard,
                                                       0x0,
                                                       0x0,
                                                       (u32) func_8080000C_chamazonstadiumguard,
                                                       (u32) func_80107C2C,
                                                       0x86006502,
                                                       (u32) func_80800328_chamazonstadiumguard,
                                                       0x0};
u8 D_80800748_chamazonstadiumguard[12] = {0xC3, 0x48, 0x0,  0x0, 0xC2, 0xC8,
                                          0x0,  0x0,  0xC4, 0x9, 0x80, 0x0};
u8 D_80800754_chamazonstadiumguard[12] = {0x43, 0x48, 0x0,  0x0,  0x43, 0xE1,
                                          0x0,  0x0,  0xC2, 0x48, 0x0,  0x0};
u8 D_80800760_chamazonstadiumguard[16] = {0x43, 0x66, 0x0, 0x0, 0x43, 0x20, 0x0, 0x0,
                                          0x42, 0xC8, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0};
s32 D_80800770_chamazonstadiumguard[7] = {0x59012C, 0xF0A0000, -0x1,     0x0,
                                          0x300000, 0xE0000,   0x4000000};
s32 D_8080078C_chamazonstadiumguard[7] = {0x58012C, 0xF090F0B, 0x201,    0x120E0000,
                                          0x300000, 0xE0000,   0x4000000};
s32 D_808007A8_chamazonstadiumguard[7] = {0x12C, 0xF0C, 0x80, 0x0, 0x300000, 0xE0000, 0x7000000};
s32 D_808007C4_chamazonstadiumguard[3] = {0x130564, 0xD00F3, 0x10C0000};
s32 D_808007D0_chamazonstadiumguard[4] = {0x3F2E147B, 0x3F4CCCCD, 0x3F6B851F, -0x40800000};
