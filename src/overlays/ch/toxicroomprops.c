#include "common.h"

#define SPEED (*(f32 *) &this->actorData[3])
extern int D_808009E8_chtoxicroomprops[];
extern int D_80800A30_chtoxicroomprops[];
extern void func_80101FDC();
struct chtoxicroomprops {
    void *unk[19];
};
extern struct chtoxicroomprops D_80800A84_chtoxicroomprops;
extern Vec3f D_808009A0_chtoxicroomprops;
extern u8 D_808009AC_chtoxicroomprops[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern f32 func_800DC0C0(void);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern f32 func_800F1214(f32, f32, f32);
extern u8 D_808009E0_chtoxicroomprops[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 func_800F13C4(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800C4140(s32, f32 *, s32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern void _subaddieaudioloop_entrypoint_1(Actor *, s32);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, void *);
extern u8 D_80800A78_chtoxicroomprops[];
extern f32 func_80103EF4(Actor *);
extern s32 func_800E1610(s32, f32, f32, f32 *);
extern void func_800E148C(s32, f32, f32);
void func_80800390_chtoxicroomprops(Actor *this, f32 delta);

// Fan update: spins up, drives particles and clears the gas cloud.
void func_80800000_chtoxicroomprops(Actor *fan)
{
    Actor *gas;
    Vec3f pos;
    s32 emitter;
    s32 spin_b;
    s32 spin_a;

    switch (fan->unk70_10) {
        case 1:
            func_80103110(fan, 0);
            break;
        case 2:
            gas = _subaddiefind_entrypoint_2(0x178, 0);
            if (!fan->unk74_30 && fan->rotation[1] == 193.0f) {
                fan->unk74_30 = 1;
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(fan->unk0, 0x133D, 7, fan->position, 0xA3);
            }
            if (func_800DC0C0() < 0.1f && _subaddiefade_entrypoint_0(gas) >= 0x51) {
                pos = D_808009A0_chtoxicroomprops;
                emitter = func_800B53A4(1);
                func_800BABB8(emitter, pos.f, NULL, 10.0f, D_808009AC_chtoxicroomprops);
                if (fan->rotation[1] == 193.0f) {
                    spin_a =
                        (s32) func_800F1214(((f32 *) fan->actorData)[3], 0.0f, 450.0f) * 10;
                } else {
                    spin_a =
                        -((s32) func_800F1214(((f32 *) fan->actorData)[3], 0.0f, 450.0f) * 10);
                }
                if (fan->rotation[1] == 193.0f) {
                    spin_b =
                        (s32) func_800F1214(((f32 *) fan->actorData)[3], 0.0f, 450.0f) * 10;
                } else {
                    spin_b =
                        -((s32) func_800F1214(((f32 *) fan->actorData)[3], 0.0f, 450.0f) * 10);
                }
                func_800BA450(emitter, 0, 0, (s16) spin_a, 0, 0, spin_b);
                func_800BA22C(emitter, 1);
            }
            if (!func_800DA298(0x1BC) && fan->rotation[1] == 193.0f) {
                func_800DA544(0x1BC);
                _capod_entrypoint_13(fan->unk0, 0, 0, 0x800);
            }
            func_80800390_chtoxicroomprops(fan, 2.0f);
            if (((f32 *) fan->actorData)[3] >= 450.0f &&
                _subaddiefade_entrypoint_0(gas) != 0 && fan->rotation[1] == 193.0f) {
                _subaddiefade_entrypoint_6(gas, -1);
            }
    }
}

int func_8080030C_chtoxicroomprops(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0xB:
            func_800DA524(0xA04);
            func_800DA524(0x1BD);
            _subaddieaudioloop_entrypoint_2(actor);
            _glcutDll_entrypoint_17();
            return 3;

        case 0x49:
            if (arg == 0x41) {
                func_80101FDC(actor, 2);
                return 1;
            }
            return 0;

        default:
            return 0;
    }
}

void func_80800390_chtoxicroomprops(Actor *this, f32 delta)
{
    SPEED += delta;
    if (450.0f < SPEED) {
        SPEED = 450.0f;
    }
    this->unk54 = this->rotation[2];
    this->rotation[2] = func_800136E4(this->rotation[2] + SPEED * func_800D8FF8());
    if (45.0f < SPEED) {
        if (func_800F13C4(this->unk54, 90.0f) > func_800F13C4(this->rotation[2], 90.0f)) {
            func_800C4140(
                ((((s32) ((s32) func_800F10B4(SPEED, 45.0f, 450.0f, 18000.0f, 24000.0f) * 0.5f) >>
                   5) &
                  0x3FF)
                 << 11) +
                    ((u16) (u32) ((func_800F10B4(SPEED, 45.0f, 450.0f, 0.3f, 0.6f) +
                                   func_800DC178(-0.02f, 0.02f)) *
                                  1023.0f)
                     << 21) +
                    0x3FF,
                this->position, 0xBB800C8);
        }
        _subaddieaudioloop_entrypoint_0(this, func_800F10B4(SPEED, 45.0f, 450.0f, 0.2f, 0.5f));
        _subaddieaudioloop_entrypoint_1(this,
                                        func_800F10B4(SPEED, 45.0f, 450.0f, 18000.0f, 24000.0f));
        _subaddieaudioloop_entrypoint_4(this, this->position, 1, D_808009E0_chtoxicroomprops);
    }
}

int chtoxicroomprops_entrypoint_0()
{
    return (int) D_808009E8_chtoxicroomprops;
}

void func_80800650_chtoxicroomprops(void *actor)
{
    *(float *) ((char *) actor + 0x24) = 0.0f;
    *(float *) ((char *) actor + 0x4C) = 0.0f;
    *(float *) ((char *) actor + 0x54) = 0.0f;
    *(float *) ((char *) actor + 0x58) = 10.0f;
}

void func_80800670_chtoxicroomprops(u8 *rotor)
{
    if (func_800D90A4(rotor + 0x58) != 0) {
        func_80800390_chtoxicroomprops(rotor, -2.0f);
        if (*(f32 *) ((s8 *) rotor + 0x24) < 45.0f) {
            _subaddieaudioloop_entrypoint_2(rotor);
            *(f32 *) ((s8 *) rotor + 0x24) = 0.0f;
            func_800FFA88(*(s32 *) ((s8 *) rotor + 0));
        }
    } else {
        func_80800390_chtoxicroomprops(rotor, 4.0f);
    }
}

void *chtoxicroomprops_entrypoint_1()
{
    return D_80800A30_chtoxicroomprops;
}

void func_80800700_chtoxicroomprops(u8 *piston)
{
    *(f32 *) (piston + 0x30) = *(f32 *) (piston + 8);
    if (func_800DA298(0x1BD) == 0) {
        func_80101FDC(piston, 3);
    } else {
        func_80101FDC(piston, 1);
    }
}

// Stamping piston update (states 1..4).
void func_80800758_chtoxicroomprops(Actor *piston)
{
    s32 pad0;
    switch (piston->unk70_10) {
        case 1:
            if (func_800DA298(0xA04) || !func_800DA298(0x1BD)) {
                func_80101FDC(piston, 2);
                ((f32 *) piston->actorData)[4] = 8.0f;
            }
            piston->position[1] = ((f32 *) piston->actorData)[6];
            return;
        case 2:
            if (func_800D90A4(&piston->actorData[4])) {
                func_80101FDC(piston, 3);
            }
            piston->position[1] = ((f32 *) piston->actorData)[6] +
                                   func_800F10B4(((f32 *) piston->actorData)[4], 8.0f, 0.0f, 0.0f,
                                                 func_80103EF4(piston) * 0.9f);
            return;
        case 3:
            if (func_800DA298(0x1BD) && !func_800DA298(0xA04)) {
                func_80101FDC(piston, 4);
                ((f32 *) piston->actorData)[4] = 0.5f;
                _subaddieaudioquick_entrypoint_2(piston, piston->position,
                                                 D_80800A78_chtoxicroomprops);
            }
            piston->position[1] = ((f32 *) piston->actorData)[6] + func_80103EF4(piston) * 0.9f;
            return;
        case 4:
            if (func_800D90A4(&piston->actorData[4])) {
                func_800E148C(func_800E1610(2, 200.0f, 0.85f, piston->position), 1000.0f, 4000.0f);
                func_80101FDC(piston, 1);
                _subaddieaudioquick_entrypoint_2(piston, piston->position,
                                                 D_80800A78_chtoxicroomprops);
            }
            piston->position[1] = ((f32 *) piston->actorData)[6] +
                                   func_800F10B4(((f32 *) piston->actorData)[4], 0.5f, 0.0f,
                                                 func_80103EF4(piston) * 0.9f, 0.0f);
    }
}

struct chtoxicroomprops *chtoxicroomprops_entrypoint_2()
{
    return &D_80800A84_chtoxicroomprops;
}

// TU-NOTE: .data is defined in C; its tables point to functions of this file, and IDO schedules
// them differently unless they share the unit.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_80108ED0();
extern void func_8010A730();
Vec3f D_808009A0_chtoxicroomprops = {1.22e+03f, 4e+02f, 0.0f};
u8 D_808009AC_chtoxicroomprops[52] = {
    0x0,  0x1D, 0x9,  0xC9, 0x0,  0x18, 0x0,  0x0,  0x0,  0xC, 0x0,  0x0, 0x0,
    0x2B, 0x0,  0xE,  0x0,  0xA,  0x0,  0x64, 0x0,  0x1F, 0x0, 0xFF, 0x4, 0x0,
    0x19, 0x2,  0x0,  0x22, 0x1,  0x0,  0x1,  0x33, 0x0,  0x0, 0x0,  0x0, 0x0,
    0x15, 0x0,  0x4C, 0x0,  0x4C, 0x0,  0x2B, 0x0,  0x80, 0x0, 0x80, 0x0, 0x0};
u8 D_808009E0_chtoxicroomprops[8] = {0x0, 0x13, 0x4, 0xB4, 0x0, 0x0, 0x0, 0x0};
int D_808009E8_chtoxicroomprops[18] = {0x15803EC,
                                       0x8860001,
                                       0x0,
                                       (u32) func_80800000_chtoxicroomprops,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x10802C00,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80107C2C,
                                       -0x7FFFDBFE,
                                       (u32) func_8080030C_chtoxicroomprops,
                                       0x0};
int D_80800A30_chtoxicroomprops[18] = {0x158047C,
                                       0x0,
                                       0x0,
                                       (u32) func_80800670_chtoxicroomprops,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x4,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_80800650_chtoxicroomprops,
                                       (u32) func_80107C2C,
                                       -0x7FFFFFFE,
                                       0x0,
                                       0x0};
u8 D_80800A78_chtoxicroomprops[12] = {0x0, 0x13, 0x4, 0xC7, 0x0, 0x18,
                                      0x0, 0x2,  0x0, 0x0,  0x0, 0x0};
struct chtoxicroomprops D_80800A84_chtoxicroomprops = {(void *) 0x01580416,
                                                       (void *) 0x08300001,
                                                       0,
                                                       (void *) func_80800758_chtoxicroomprops,
                                                       (void *) func_80105834,
                                                       (void *) func_8010A730,
                                                       0,
                                                       0,
                                                       0,
                                                       (void *) 0x00020C00,
                                                       0,
                                                       0,
                                                       0,
                                                       (void *) func_80800700_chtoxicroomprops,
                                                       (void *) func_80107C2C,
                                                       (void *) 0x80000402,
                                                       0,
                                                       0,
                                                       0};
