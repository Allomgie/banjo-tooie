// Probably the light beam of the Hailfire Peaks aliens: fades in, rises 600 units over 3 s
// and fades out on message 0x4F.
#include "common.h"

extern int D_808001A0_chalienbeam[];
extern s32 func_800D9078(f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, void *, void *, f32);

int chalienbeam_entrypoint_0()
{
    return (int) &D_808001A0_chalienbeam;
}

// Init: start/end points (end 600 units higher), 3 s timer, fade in.
void func_8080000C_chalienbeam(void *actor)
{
    func_800EE7F8((char *) actor + 0x18, (char *) actor + 4, actor);
    *(f32 *) ((char *) actor + 0x8) = *(f32 *) ((char *) actor + 0x8) + 600.0f;
    func_800EE7F8((char *) actor + 0x28, (char *) actor + 4, actor);
    *(f32 *) ((char *) actor + 0x58) = 3.0f;
    *(u8 *) ((char *) actor + 0x7A) = (u8) ((*(u8 *) ((char *) actor + 0x7A) & 0xFF3F) | 0x80);
    _subaddiefade_entrypoint_1(actor, 0xC0);
}

// Update: move from start to end over the timer.
void func_80800088_chalienbeam(Actor *actor)
{
    s32 done;
    if (actor->unk70_10 == 1) {
        done = func_800D9078(&actor->unk58);
        func_800EFE50(actor->position, &actor->actorData[4], actor->actorData,
                      func_800F12D4(actor->unk58, 0.0f, 3.0f, 1.0f, 0.0f));
        if (done)
            func_80102424(actor, 2);
    }
}

// Message 0x4F: fade out.
int func_80800110_chalienbeam(s32 actor, s32 msg, s32 param_2)
{
    if (msg == 0x4F) {
        _subaddiefade_entrypoint_3();
        func_80102424(actor, 3);
    } else {
        return 0;
    }
    return 1;
}

// Draw: set yaw field from the camera position.
void func_8080015C_chalienbeam(u8 *actor, s32 param_1)
{
    f32 cam_pos[3];

    func_800E3A58(cam_pos);
    *(f32 *) ((char *) actor + 0x48) = cam_pos[1];
    func_80101870(actor, param_1);
}

// TU-NOTE: the overlay .data is defined here in C; tables holding function pointers must be in
// the same unit, or IDO's assembler schedules those functions differently. D_808001A0_chalienbeam is int[].
extern void func_80105834();
extern void func_80107C2C();
int D_808001A0_chalienbeam[20] = {0x1580466,
                                  0x81B0001,
                                  0x0,
                                  (u32) func_80800088_chalienbeam,
                                  (u32) func_80105834,
                                  (u32) func_8080015C_chalienbeam,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x21404,
                                  0x0,
                                  0x0,
                                  0x0,
                                  (u32) func_8080000C_chalienbeam,
                                  (u32) func_80107C2C,
                                  -0x7FFFFFFE,
                                  (u32) func_80800110_chalienbeam,
                                  0x0,
                                  0x0,
                                  0x0};
