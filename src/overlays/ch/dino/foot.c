// Probably the giant stomping dinosaur foot of Stomping Plains: follows the player's x/z, stomps
// down with camera shake and dust, and hurts or flattens the player. First approach shows an intro.
#include "common.h"

extern void *D_80800818_chdinofoot;
extern f32 func_8010CD28(Actor *);
extern f32 func_800136E4(f32);
extern void func_80102FDC(Actor *, f32);
extern u8 D_80800860_chdinofoot[];
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern void func_8010D09C(void *, void *, f32);
extern f32 func_800F3780(f32, void *, s32);
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
extern void func_8010D254(f32 *);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800D8FF8(void);
extern void func_800EF368(f32 *, f32);
extern u8 D_80800880_chdinofoot[];
extern u8 D_80800890_chdinofoot[];
extern u8 D_808008A0_chdinofoot[];
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
void func_8080035C_chdinofoot();
s32 func_80800480_chdinofoot();
s32 func_808006BC_chdinofoot();

int chdinofoot_entrypoint_0()
{
    return &D_80800818_chdinofoot;
}

void func_8080000C_chdinofoot(Actor *actor)
{
    if (_glcutDll_entrypoint_20()) {
        func_80102424(actor, 5);
        actor->unk58 = 1.4f;
    }
    _subaddiefade_entrypoint_12(actor, 0x60, 0x80, 0x60);
    func_80102FDC(actor, actor->scale * 4.0f);
}

s32 func_8080055C_chdinofoot();

// State machine: first-approach intro, tracking, stomp.
void func_80800084_chdinofoot(Actor *actor)
{
    if (func_800F6438(func_800F54E4())) {
        func_8010D09C(func_800F54E4(), &actor->actorData, 0.79998779296875f);
        *(f32 *) &actor->actorData[1] = actor->position[1];
    }
    switch (actor->unk70_10) {
        case 1:
            if (!func_80800480_chdinofoot(actor) && !actor->unk64_20 &&
                func_800D90A4(&actor->unk58)) {
                func_80102424(actor, 3);
            }
            break;
        case 2:
            if (func_800D90A4(&actor->unk58)) {
                _chintrotext_entrypoint_1(0x18B9, 7, 1, 0);
                func_80102424(actor, 4);
                func_8010A590(actor);
            }
            break;
        case 3:
            if (actor->unk64_20 || func_8080055C_chdinofoot(actor)) {
                func_80102424(actor, 4);
                func_8010A590(actor);
            }
            break;
        case 4:
            func_808006BC_chdinofoot(actor);
            if (func_80101E14(actor, 0.6f)) {
                func_8010A570(actor);
            }
            if (func_80101DDC(actor)) {
                func_80102424(actor, 1);
                actor->unk58 = 1.399993896484375f;
            }
            break;
        case 5:
            if (func_800D9078(&actor->unk58)) {
                func_80102424(actor, 6);
            }
            break;
        case 6:
            func_808006BC_chdinofoot(actor);
            if (func_80101DDC(actor)) {
                func_80102424(actor, 5);
                actor->unk58 = 1.4f;
            }
    }
    _subaddiefade_entrypoint_1(
        actor, (s32) (func_800F3780(func_80101F24(actor), D_80800860_chdinofoot, 4) * 255.0f));
    _chbadshad_entrypoint_1(actor, actor->position, 8.5f);
}

s32 func_808002A8_chdinofoot(Actor *actor, s32 message, s32 data)
{
    switch (message) {
        case 0x3F:
            func_8080035C_chdinofoot(actor, *(Unk80132ED0 **) &data);
            break;
        case 0xB:
            actor->unk64_20 = 0;
            func_800FDC28(0);
            return 3;
        default:
            return 0;
    }
    return 1;
}

s32 func_80800310_chdinofoot(Actor *this, s32 param_1)
{
    s32 fade_alpha;
    fade_alpha = _subaddiefade_entrypoint_0(this);
    _subaddiefade_entrypoint_1(this, 0xFF);
    func_80101870(this, param_1);
    _subaddiefade_entrypoint_1(this, fade_alpha);
}

// Foot lands on player: flatten if mid-stomp, else hurt.
void func_8080035C_chdinofoot(actor, msg) Actor *actor;
Unk80132ED0 *msg;
{
    if ((msg->unk24 >> 22) == 0) {
        if (actor->unk70_10 == 4 && func_80101F24(actor) < 0.4f) {
            func_800F7B9C(func_800F54E4(), 0x5A);
            func_8010A570(actor);
            return;
        }
        func_800F79DC(func_800F54E4(), 0xA, actor->unk0);
        func_8010A570(actor);
    }
}

// Player within the z tracking range.
int func_80800408_chdinofoot(actor)
Actor *actor;
{
    f32 player_pos[3];
    if (!func_8010D248())
        return 0;
    func_8010D254(player_pos);
    if (player_pos[2] > 3500.0f || player_pos[2] < -4000.0f)
        return 0;
    return 1;
}

// First approach (flag 0xC5): intro text and camera shot.
s32 func_80800480_chdinofoot(actor)
Actor *actor;
{
    s32 player;
    f32 player_pos[3];
    player = func_800F54E4();
    if (!func_800F6438(player) || !func_800F6478(player))
        return 1;
    if (!func_800DA298(0xC5)) {
        func_800F5A00(player, player_pos);
        if (player_pos[2] < 4500.0f) {
            func_800DA544(0xC5);
            actor->unk64_20 = 1;
            func_80102424(actor, 2);
            actor->unk58 = 21.5f;
            _capod_entrypoint_13(actor->unk0, 0, 1, 0x10);
            func_800FDC28(1);
        }
        return 1;
    }
    return 0;
}

s32 func_8080055C_chdinofoot(Actor *actor)
{
    if (func_80800408_chdinofoot(actor)) {
        actor->position[0] = *(f32 *) &actor->actorData[0];
        actor->position[2] = *(f32 *) &actor->actorData[2];
        actor->rotation[1] = func_800136E4(func_8010CD28(actor) + 180.0f);
        return 1;
    }
    return 0;
}

// Follow the player in x/z.
void func_808005C4_chdinofoot(Actor *actor)
{
    f32 step[3];
    f32 player_pos[3];
    f32 target[3];

    if (!actor->unk64_20 && !_glcutDll_entrypoint_20()) {
        func_800F5A00(func_800F54E4(), player_pos);
        player_pos[1] = -200.0f;
        func_800EFE50(target, (f32 *) actor->actorData, player_pos, 0.5f);
        if (func_800EEB40(actor->position, target) > 10000.0f) {
            func_800EFB24(step, target, actor->position);
            func_800EF368(step, func_800D8FF8() * 500.0f);
            actor->position[0] += step[0];
            actor->position[2] += step[2];
        }
    }
}

// Stomp: dust, camera shake, rumble.
s32 func_808006BC_chdinofoot(actor)
Actor *actor;
{
    f32 *pos;

    pos = actor->position;
    _subaddieaudioquick_entrypoint_3(actor, pos, D_80800880_chdinofoot, 0.0f);
    if (func_80101F24(actor) < 0.4f)
        func_808005C4_chdinofoot(actor);
    if (func_80101E14(actor, 0.4f)) {
        _subaddieaudioquick_entrypoint_2(actor, pos, D_80800890_chdinofoot);
        func_800BBCB8(pos, pos, 1.0f, 6, D_808008A0_chdinofoot);
        func_800E15CC(0, 40.0f, 0.8f);
        func_80018820(0, 3.0f, 0.25f);
        return 1;
    }
    return 0;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_808007E0_chdinofoot[14] = {0x0,        0x0,        0x3F976C8B, 0x16A0044,  0x3F976C8B,
                                 0x16A0044,  0x3F976C8B, 0x16A0044,  0x3F976C8B, 0x16A0002,
                                 0x3F976C8B, 0x16A0044,  0x3F976C8B, 0x16A0002};
void *D_80800818_chdinofoot = (void *) 0x02F50362;
static u32 D_80800818_chdinofoot_rest[17] = {0x6D30001,
                                             (u32) &D_808007E0_chdinofoot,
                                             (u32) func_80800084_chdinofoot,
                                             (u32) func_80105834,
                                             (u32) func_80800310_chdinofoot,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x420,
                                             0x0,
                                             (u32) func_80108ED0,
                                             0x0,
                                             (u32) func_8080000C_chdinofoot,
                                             (u32) func_80107C2C,
                                             0x80800490,
                                             (u32) func_808002A8_chdinofoot,
                                             0x0};
u8 D_80800860_chdinofoot[32] = {0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x3E, 0x4C, 0xCC,
                                0xCD, 0x3F, 0x80, 0x0,  0x0, 0x3F, 0x66, 0x66, 0x66, 0x3F, 0x80,
                                0x0,  0x0,  0x3F, 0x80, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0};
u8 D_80800880_chdinofoot[16] = {0x0, 0x13, 0x5, 0x4E, 0x0, 0x18, 0x0, 0xD,
                                0x0, 0xC0, 0x0, 0xD9, 0x0, 0x2,  0x0, 0x0};
u8 D_80800890_chdinofoot[16] = {0x0, 0x13, 0x5, 0x6E, 0x0, 0x18, 0x0, 0xD,
                                0x0, 0x99, 0x0, 0xCC, 0x0, 0x2,  0x0, 0x0};
u8 D_808008A0_chdinofoot[80] = {
    0x0, 0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x2, 0x0,  0x2, 0x80, 0x0, 0x22, 0x3, 0x0,  0x4, 0x0,
    0x6, 0x0,  0x8,  0x0,  0x0,  0x15, 0x0, 0x19, 0x0, 0x99, 0x0, 0x19, 0x0, 0x0,  0x0, 0x7,
    0x0, 0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x64, 0x0, 0x2D, 0x0, 0xC8, 0x1, 0x2C,
    0x0, 0x1F, 0xC8, 0x96, 0x64, 0x0,  0x0, 0xB,  0x0, 0xC8, 0x1, 0x90, 0x0, 0x64, 0x0, 0x32,
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
