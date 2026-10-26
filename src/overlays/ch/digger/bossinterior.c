#include "common.h"

extern int D_80800230_chdiggerbossinterior;
extern u8 D_80800278_chdiggerbossinterior[];
extern Actor *_subaddiefind_entrypoint_2(s32, void *);
extern Actor *_subaddiefind_entrypoint_3(s32, void *);
typedef union { s32 local_0; f32 local_1; void *local_2; } DiggerInteriorEvent59;
typedef struct { f32 position[3]; f32 unused; f32 yaw; f32 scale; } DiggerInteriorPose;
extern s32 _subaddiemarker_entrypoint_1(Actor *, s32, s32, DiggerInteriorPose *, s32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
Actor *func_80800178_chdiggerbossinterior();

int chdiggerbossinterior_entrypoint_0()
{
    return (int)&D_80800230_chdiggerbossinterior;
}

void func_8080000C_chdiggerbossinterior(s32 param_0){
    func_800FE850();
    return;
}

void func_8080002C_chdiggerbossinterior(Actor *param_0)
{
    Actor *local_1;
    s32 local_0;

    func_800D2498(0x10B, 2 - func_800DA980(0xA4F, 2), 0);
    _subaddieaudioloop_entrypoint_4(param_0, 0, 1, D_80800278_chdiggerbossinterior);
    if (param_0->unk70_10 == 2 && param_0->unk79_4-- == 0) {
        for (local_1 = _subaddiefind_entrypoint_2(0x131, &local_0); local_1;
             local_1 = _subaddiefind_entrypoint_3(0x131, &local_0)) {
            _sucoaster_entrypoint_5(local_1);
        }
    }
}

s32 func_808000F4_chdiggerbossinterior(Actor *param_0, s32 param_1, DiggerInteriorEvent59 param_2)
{
    Actor *local_0;

    switch (param_1) {
        case 0x49:
        local_0 = func_80800178_chdiggerbossinterior(param_0, 0x32);
        if (func_800DA980(0xA4F, 2) > 0) {
            local_0 = func_80800178_chdiggerbossinterior(local_0, 0x33);
        }
        func_80101FDC(local_0, 2);
        local_0->unk79_4 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

Actor *func_80800178_chdiggerbossinterior(param_0, param_1) Actor *param_0; s32 param_1;
{
    DiggerInteriorPose local_0;
    Actor *local_1;
    if (_subaddiemarker_entrypoint_1(param_0, 0x154, param_1, &local_0, 1)) {
        local_1 = func_80108528(0x131, local_0.position, (s32)local_0.yaw, &param_0);
        local_1->unk64_20 = 1;
        local_1->unk74_17 = 0;
        local_1->unk74_7 = 100;
        func_80102FDC(local_1, local_0.scale);
        func_80108658(local_1, 0x20002000, 0, 0);
    }
    return param_0;
}
