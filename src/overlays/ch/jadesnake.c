// Most likely Ssslumber, the giant jade snake in Mayahem Temple's Jade Snake Grove: a state machine
// (idle, rising, talking, sinking) that holds a jiggy and moves it out of its mouth on message 13.
#include "common.h"

extern void func_8010A85C(Actor *, s32);
extern void func_80102424(Actor *, s32);
extern s32 D_80800938_chjadesnake[];
extern void func_800D1000(s32, s32, f32 *, s32, Unk80132ED0 *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern int func_800F54E4(void);
extern int func_800F651C(s32);
extern int func_800F6C5C(s32);
extern int func_800F72DC(s32);
extern int func_800F56AC(s32);
extern int func_800F6478(s32);
typedef struct {
    s16 a, b;
} S16Pair;
typedef union JadeSnakeEvent {
    s32 word;
    s16 halves[2];
} JadeSnakeEvent;
extern Actor *func_80106790(Unk80132ED0 *);
extern Unk80132ED0 *func_80101080(void);
extern f32 D_808009E4_chjadesnake[];
extern void _gcdialogcamera_entrypoint_3(f32 *, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern int D_808009F4_chjadesnake[];
extern u8 D_80800910_chjadesnake[];
extern u8 D_80800920_chjadesnake[];
extern u8 D_8080092C_chjadesnake[];
extern u8 D_80800948_chjadesnake[];
extern u8 D_80800958_chjadesnake[];
extern u8 D_80800964_chjadesnake[];
extern f32 D_808009C0_chjadesnake[];
extern f32 D_808009DC_chjadesnake[];
extern s32 func_800D0B68(u32, u32);
extern s32 func_800D0A9C(u32, u32);
extern s32 func_800D0634(u32, u32);
extern void func_8010D254(f32 *);
extern s32 func_80101E4C(Actor *, f32 *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_80101DDC(Actor *);
extern f32 func_80101F24(Actor *);
extern void func_80101EE4(Actor *, f32);
extern void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, void *, f32 *);
extern s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, void *);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_80090734(s32, f32 *);
extern void func_80090708(s32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);

void func_80800000_chjadesnake(Actor *actor)
{
    func_8010A85C(actor, 2);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(actor, 9);
        func_8010A85C(actor, 1);
    }
}

void func_80800048_chjadesnake(Actor *actor)
{
    func_800D1000(0xA, 1, (f32 *) &actor->actorData[4], 3, actor->unk0);
    _subaddieaudioquick_entrypoint_2(actor, (f32 *) &actor->actorData[4],
                                     &D_80800938_chjadesnake);
}

int func_8080009C_chjadesnake(Actor *actor)
{
    s32 player;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 unk_4;

    player = func_800F54E4();
    unk_0 = func_800F651C(player);
    unk_1 = func_800F6C5C(player);
    unk_2 = func_800F72DC(player);
    unk_3 = func_800F56AC(player) == 0x10;
    unk_4 = func_800F6478(player);
    if (!unk_3)
        return 0;
    return unk_4 && (unk_2 || (unk_1 && !unk_0));
}

// Ssslumber state machine; holds jiggy #10 and hands it over on message 13.
void func_80800150_chjadesnake(Actor *actor)
{
    f32 sound_pos[3];
    s32 unk_1;
    s32 unk_2;
    s32 frame_event;
    f32 anim_progress;
    f32 player_pos[3];
    Actor *jiggy;

    unk_1 = func_800D0B68(10, 1);
    unk_2 = func_800D0A9C(10, 1);
    func_8010D254(sound_pos);
    switch (actor->unk70_10) {
        case 1:
            if (actor->unk7C_12 && !unk_1 && !unk_2) {
                func_800D1000(10, 1, (f32 *) &actor->actorData[0], 3, actor->unk0);
            }
            frame_event = func_80101E4C(actor, D_808009C0_chjadesnake);
            if (frame_event) {
                func_800C4B7C(frame_event & 1 ? 0x5C6 : 0x5C7);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80800964_chjadesnake);
            }
            if (!unk_1 && unk_2 && func_8080009C_chjadesnake(actor)) {
                _subaddieaudioquick_entrypoint_2(actor, sound_pos, D_80800910_chjadesnake);
                func_80090734(2, actor->position);
                func_8010A85C(actor, 1);
                func_80102424(actor, 2);
                if (!func_800DA9E4(0x677, 1)) {
                    actor->unk64_20 = 1;
                    _capod_entrypoint_13(actor->unk0, 0, 2, 0x10);
                } else {
                    actor->unk64_20 = 0;
                }
            }
            break;
        case 2:
            if (unk_1) {
                func_8010A85C(actor, 2);
                func_80102424(actor, 1);
                func_80090708(0);
            }
            if (func_80101E14(actor, 0.73f)) {
                func_800D119C(10, 1);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_8080092C_chjadesnake);
            }
            if (func_80101DDC(actor)) {
                if (func_800DA298(0x434)) {
                    func_80102424(actor, 3);
                    func_80090708(0);
                } else {
                    func_800DA544(0x434);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0xF3C, 0xC, actor->position,
                                                  0x46);
                    func_80102424(actor, 5);
                }
            }
            break;
        case 6:
            _capod_entrypoint_14();
            func_80090708(0);
            func_80102424(actor, 3);
            break;
        case 3:
            anim_progress = func_80101F24(actor);
            func_8010D254(player_pos);
            if (func_800F56AC(func_800F54E4()) != 0x10 && player_pos[1] < 1160.0f) {
                func_80102424(actor, 4);
                if (actor->unk64_20) {
                    _capod_entrypoint_13(actor->unk0, 0, 0, 0x10);
                }
            }
            if (anim_progress > 0.13f && anim_progress < 0.64f) {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                D_80800948_chjadesnake);
            }
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80800958_chjadesnake,
                                             D_808009DC_chjadesnake);
            break;
        case 4:
            if (func_80101E14(actor, 0.18f) && !unk_2) {
                if (func_800DA298(0x435)) {
                    func_80800048_chjadesnake(actor);
                } else {
                    func_800DA544(0x435);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0xF3D, 0xC, actor->position,
                                                  0x46);
                    func_80102424(actor, 7);
                }
            }
            if (func_80101DDC(actor)) {
                if (!func_800DA298(0x435)) {
                    func_80102424(actor, 7);
                } else {
                    func_8010A85C(actor, 2);
                    func_80102424(actor, 1);
                }
            }
            if (!unk_1 && unk_2 && func_8080009C_chjadesnake(actor)) {
                _subaddieaudioquick_entrypoint_2(actor, sound_pos, D_80800910_chjadesnake);
                func_80090734(2, actor->position);
                func_8010A85C(actor, 1);
                func_80102424(actor, 2);
                func_80101EE4(actor, 0.57f);
            }
            break;
        case 7:
            if (!unk_2) {
                func_80800048_chjadesnake(actor);
            }
            break;
        case 8:
            if (func_80101DDC(actor)) {
                if (unk_2) {
                    func_8010A85C(actor, 2);
                    func_80102424(actor, 1);
                } else {
                    func_80800048_chjadesnake(actor);
                    func_80090708(0);
                    func_80102424(actor, 4);
                }
            }
    }
    if (actor->unk6C_0 && func_800D0634(10, 1)) {
        jiggy = func_80106790((Unk80132ED0 *) func_800D0634(10, 1));
        func_800EF04C(jiggy->position, (f32 *) &jiggy->actorData[4]);
        actor->unk6C_0--;
        if (actor->unk6C_0 == 2) {
            _subaddieaudioquick_entrypoint_2(jiggy, jiggy->position, D_80800920_chjadesnake);
        } else if (actor->unk6C_0 == 0) {
            func_800EE7F8(jiggy->position, (f32 *) &actor->actorData[0]);
            func_80102FE8(jiggy, 1);
            func_80103014(jiggy);
        }
    }
}

void func_80800728_chjadesnake(actor, dialog_id, arg) s32 actor;
s32 dialog_id;
S16Pair arg;
{

if (dialog_id != 0xF3C) {
    if (dialog_id == 0xF3D) {
        func_80102424(actor, 8);
    }
} else {

func_80102424(actor, 6);
}
}

int func_80800770_chjadesnake(Actor *actor)
{
    func_80101870();
    if (actor->unk7C_12) {
        func_800DBEFC(func_80104130(), 4, (u8 *) actor + 0x18);
        func_800DBEFC(func_80104130(), 5, (u8 *) actor + 0x28);

}
}

s32 func_808007DC_chjadesnake(Actor *actor, s32 msg, JadeSnakeEvent msg_data)
{
    Actor *jiggy;

    // Matching: empty block steers IDO's codegen.
    if (1) {
    }
    switch (msg) {
        case 13:
            if (actor->unk70_10 != 1) {
                jiggy = func_80106790(func_80101080());
                func_800EFB24((f32 *) &jiggy->actorData[4], (f32 *) &actor->actorData[0],
                              (f32 *) &actor->actorData[4]);
                func_800EF334((f32 *) &jiggy->actorData[4], 1.0f / 7.0f);
                actor->unk6C_0 = 7;
                func_80102FE8(jiggy, 0);
            }

break;
case 0x2E:
    func_80800728_chjadesnake(actor, msg_data.halves[0], msg_data.halves[1]);
    break;
case 0x52:
    _gcdialogcamera_entrypoint_3(D_808009E4_chjadesnake, actor->scale);
    break;
default:
    return 0;
    }
    return 1;
    }

    int chjadesnake_entrypoint_0()
    {
        return (int) &D_808009F4_chjadesnake;
    }

    extern void func_80105834();
    extern void func_80108ED0();
    extern void func_80107C2C();
    u8 D_80800910_chjadesnake[16] = {0x0, 0x13, 0x4, 0xAA, 0x0,  0xD,  0x0, 0xF3,
                                     0x1, 0xC,  0x0, 0x16, 0x79, 0x18, 0x0, 0x0};
    u8 D_80800920_chjadesnake[12] = {0x0,  0x13, 0x3, 0xE9, 0x0, 0x16,
                                     0x52, 0x8,  0x0, 0x0,  0x0, 0x0};
    u8 D_8080092C_chjadesnake[12] = {0x0,  0x13, 0x4, 0xA4, 0x0, 0x16,
                                     0x79, 0x18, 0x0, 0x0,  0x0, 0x0};
    s32 D_80800938_chjadesnake[4] = {0x130430, 0xA0133, 0x167918, 0x0};
    u8 D_80800948_chjadesnake[16] = {0x0, 0x13, 0x5, 0x1F, 0x0,  0x16, 0x5D, 0xC0,
                                     0x0, 0x1,  0x1, 0xF4, 0x13, 0x88, 0x0,  0x0};
    u8 D_80800958_chjadesnake[12] = {0x0,  0x13, 0x5, 0x1E, 0x0, 0x16,
                                     0x5D, 0xC0, 0x0, 0x0,  0x0, 0x0};
    u8 D_80800964_chjadesnake[12] = {0x0, 0x21, 0x0, 0xD, 0x1, 0x26, 0x1, 0x40, 0x0, 0x0, 0x0, 0x0};
    u32 D_80800970_chjadesnake[20] = {0x0,        0x0,        0x41100000, 0x1930001,  0x3FB33333,
                                      0x1940002,  0x41000000, 0x1950001,  0x40AB851F, 0x1960002,
                                      0x41000000, 0x1950001,  0x41000000, 0x1950001,  0x40AB851F,
                                      0x1960002,  0x40AB851F, 0x1960002,  0x41000000, 0x1950001};
    f32 D_808009C0_chjadesnake[7] = {0.1f, 0.25f, 0.4f, 0.55f, 0.75f, 0.9f, -1.0f};
    f32 D_808009DC_chjadesnake[2] = {0.64f, -1.0f};
    f32 D_808009E4_chjadesnake[4] = {3.8e+02f, 0.0f, 2.7e+02f, 0.0f};
    int D_808009F4_chjadesnake[19] = {0x154010C,
                                      0x65F0001,
                                      (u32) &D_80800970_chjadesnake,
                                      (u32) func_80800150_chjadesnake,
                                      (u32) func_80105834,
                                      (u32) func_80800770_chjadesnake,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x8002E,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      (u32) func_80800000_chjadesnake,
                                      (u32) func_80107C2C,
                                      -0x7FFFE000,
                                      (u32) func_808007DC_chjadesnake,
                                      0x0,
                                      0x0};
