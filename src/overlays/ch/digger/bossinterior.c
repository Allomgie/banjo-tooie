#include "common.h"

extern int D_80800230_chdiggerbossinterior[];
extern u8 D_80800278_chdiggerbossinterior[];
extern Actor *_subaddiefind_entrypoint_2(s32, void *);
extern Actor *_subaddiefind_entrypoint_3(s32, void *);
typedef union {
    s32 local_0;
    f32 local_1;
    void *local_2;
} DiggerInteriorEvent59;
typedef struct {
    f32 position[3];
    f32 unused;
    f32 yaw;
    f32 scale;
} DiggerInteriorPose;
extern s32 _subaddiemarker_entrypoint_1(Actor *, s32, s32, DiggerInteriorPose *, s32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
Actor *func_80800178_chdiggerbossinterior();

int chdiggerbossinterior_entrypoint_0()
{
    return (int) &D_80800230_chdiggerbossinterior;
}

void func_8080000C_chdiggerbossinterior(s32 param_0)
{
    func_800FE850();
}

// Per-frame: shows the HUD counter, plays the ambient loop, then activates the minions' chase AI.
void func_8080002C_chdiggerbossinterior(Actor *actor)
{
    Actor *minion;
    s32 iter;

    func_800D2498(0x10B, 2 - func_800DA980(0xA4F, 2), 0);
    _subaddieaudioloop_entrypoint_4(actor, 0, 1, D_80800278_chdiggerbossinterior);
    if (actor->unk70_10 == 2 && actor->unk79_4-- == 0) {
        for (minion = _subaddiefind_entrypoint_2(0x131, &iter); minion;
             minion = _subaddiefind_entrypoint_3(0x131, &iter)) {
            _sucoaster_entrypoint_5(minion);
        }
    }
}

s32 func_808000F4_chdiggerbossinterior(Actor *actor, s32 msg, DiggerInteriorEvent59 data)
{
    Actor *minion;

    switch (msg) {
        case 0x49:
            minion = func_80800178_chdiggerbossinterior(actor, 0x32);
            if (func_800DA980(0xA4F, 2) > 0) {
                minion = func_80800178_chdiggerbossinterior(minion, 0x33);
            }
            func_80101FDC(minion, 2);
            minion->unk79_4 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

// Spawns a digger ground minion (actor 0x131) at the given marker.
Actor *func_80800178_chdiggerbossinterior(actor, marker_id)
Actor *actor;
s32 marker_id;
{
    DiggerInteriorPose pose;
    Actor *minion;
    if (_subaddiemarker_entrypoint_1(actor, 0x154, marker_id, &pose, 1)) {
        minion = func_80108528(0x131, pose.position, (s32) pose.yaw, &actor);
        minion->unk64_20 = 1;
        minion->unk74_17 = 0;
        minion->unk74_7 = 100;
        func_80102FDC(minion, pose.scale);
        func_80108658(minion, 0x20002000, 0, 0);
    }
    return actor;
}

extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
int D_80800230_chdiggerbossinterior[18] = {0x15804F7,
                                           0x1,
                                           0x0,
                                           (u32) func_8080002C_chdiggerbossinterior,
                                           (u32) func_80102EC0,
                                           (u32) func_80101870,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x0,
                                           (u32) func_8080000C_chdiggerbossinterior,
                                           (u32) func_80107C2C,
                                           -0x7FFFFBFE,
                                           (u32) func_808000F4_chdiggerbossinterior,
                                           0x0};
u8 D_80800278_chdiggerbossinterior[24] = {0x0, 0x13, 0x5, 0xF0, 0x0, 0xE,  0x0, 0xE6,
                                          0x1, 0x0,  0x0, 0x66, 0x0, 0x18, 0x0, 0x14,
                                          0x0, 0x2,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
