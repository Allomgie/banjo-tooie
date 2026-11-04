// GI train-station doors: shut until FLAG_163_STATION_UNLOCKED_GI, then slide up over 9 s with
// a sound loop when cutscene 0x44 sends message 0x49; despawn if already unlocked.
#include "common.h"

extern int D_80800268_chfactorystationdoors[];
extern u8 D_80800250_chfactorystationdoors[];
extern u8 D_8080025C_chfactorystationdoors[];
extern f32 func_80103EF4(Actor *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800DF500(f32, f32, f32);
extern void func_80101870(s32, s32);

int func_80800000_chfactorystationdoors(s32 actor)
{
    if (_glcutDll_entrypoint_19(0x44) == 0) {
        if (func_800DA298(0x163)) {
            func_800FFAB0(actor);
        } else {
            func_80101FDC(actor, 1);
        }
    }
}

void func_80800054_chfactorystationdoors(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            func_80103110(actor, 0);
            break;
        case 2:
            if (func_800D90A4(&actor->unk58)) {
                _subaddieaudioloop_entrypoint_2(actor);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_8080025C_chfactorystationdoors);
                func_80101FDC(actor, 3);
            } else {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                D_80800250_chfactorystationdoors);
            }
            actor->position[1] =
                *(f32 *) &actor->actorData[7] +
                func_800F10B4(actor->unk58, 9.0f, 0.0f, 0.0f, func_80103EF4(actor) * 1.65f);
            break;
        case 3:
            func_80103110(actor, 0);
    }
}

void func_80800158_chfactorystationdoors(s32 actor, s32 msg)
{
    func_800DF500(1.07f, 1.65f, 1.0f);
    func_80101870(actor, msg);
}

// Message 0x49 (sent by cutscene 0x44) starts the door sliding up over 9 s.
int func_8080019C_chfactorystationdoors(s32 actor, s32 msg, s32 arg)
{
    float door_yaw;
    if ((msg == 0x49) && _glcutDll_entrypoint_19(0x44)) {
        s32 actor_addr = actor;
        *(f32 *) ((char *) actor_addr + 0x34) = *(f32 *) ((char *) actor_addr + 8);
        func_80101FDC(actor_addr, 2);
        *(f32 *) ((char *) actor_addr + 0x58) = 9.0f;
        door_yaw = 90.0f;
        if (*(f32 *) ((char *) actor_addr + 0x48) == door_yaw) {
            _capod_entrypoint_13(*(s32 *) actor_addr, 0, 5, 0x900);
        }
        return 1;
    }
    return 0;
}

int chfactorystationdoors_entrypoint_0()
{
    return (int) &D_80800268_chfactorystationdoors;
}

// TU-NOTE: the overlay .data is defined here in C (from the ROM); its tables point to functions of
// this file, and IDO's assembler schedules them differently otherwise. D_80800268_chfactorystationdoors is int[].
extern void func_80105834();
extern void func_80107C2C();
u8 D_80800250_chfactorystationdoors[12] = {0x0, 0x13, 0x5, 0xB0, 0x0, 0x2,
                                           0x0, 0xA,  0x1, 0x33, 0x0, 0x0};
u8 D_8080025C_chfactorystationdoors[12] = {0x0, 0x13, 0x4, 0xC7, 0x0, 0x18,
                                           0x0, 0x2,  0x0, 0x0,  0x0, 0x0};
int D_80800268_chfactorystationdoors[18] = {0x1640406,
                                            0x87C0001,
                                            0x0,
                                            (u32) func_80800054_chfactorystationdoors,
                                            (u32) func_80105834,
                                            (u32) func_80800158_chfactorystationdoors,
                                            0x0,
                                            0x0,
                                            0x0,
                                            0xC04,
                                            0x0,
                                            0x0,
                                            0x0,
                                            (u32) func_80800000_chfactorystationdoors,
                                            (u32) func_80107C2C,
                                            -0x7FFFFBFE,
                                            (u32) func_8080019C_chfactorystationdoors,
                                            0x0};
