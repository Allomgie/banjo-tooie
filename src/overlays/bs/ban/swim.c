// Banjo-solo underwater swimming: dive from the surface, tread water, and three paddle states.
#include "common.h"
// TU-NOTE: the .data of this overlay (the four BsScript tables at the end) is defined in this
// file; the tables point at functions of this file, and IDO's assembler schedules some of these
// functions differently unless the tables are in the same unit. Values come from the ROM.
extern void func_8009BF5C(Actor *a0, f32 a1);

extern void func_8009FFD8(s32, s32, s32, s32, s32);
void baphysics_set_gravity(s32, f32);
void _baswim_entrypoint_10(s32, f32);
extern s32 D_80800A30_bsbanswim[];
extern void anctrl_setDuration(void *ctrl, float duration);
extern void *baanim_getAnimCtrlPtr(void);
extern s32 D_80800A40_bsbanswim[];
extern s32 D_80800A50_bsbanswim[];
extern s32 D_80800A60_bsbanswim[];

void func_80800000_bsbanswim(s32 self)
{
    func_8009FFD8(self, 1, 3, 3, 9);
}

extern void func_80093360(Actor *a0, f32 a1);

int func_80800030_bsbanswim(Actor *self)
{
    // Matching: the u32 mask on the negated flag test is needed for the match.
    if (!func_8009E77C(self, 0xB) & 0xFFFFFFFFu) {
        _baswim_entrypoint_5(self);
        baroll_setAngularVelocity(self, 0x43020000, 0x3F666666);
        // Matching: the long long cast is needed for the match.
        baphysics_set_gravity(self, (long long) 0);
        baphysics_set_terminal_velocity(self, 0xC3C7FEB8);
        if (func_800F8B88() != 3) {
            func_800A0CF4(self, 1);
        }
        func_800961AC(self, 3);
        func_80093360(self, 6e+01f);
        func_8009BC5C(self, 0x40000000);
        _baswim_entrypoint_6(self, 1);
        if (bs_getCurrentState(self) != 0x4C) {
            _baairbar_entrypoint_0(self, 2);
        }
    }
}

int func_80800104_bsbanswim(self)
Actor *self;
{
    extern void baroll_setIdeal(Actor * a0, f32 a1);
    // Matching: the extra copy of the parameter is needed for the match.
    Actor *copy = self;
    if (!func_8009E74C(copy, 0xB)) {
        func_8009BF5C(self, 0);
        baroll_setIdeal(self, 0);
        func_8009BC34(self);
        func_800A0CF4(self, 0);
        func_800961AC(self, 1);
        func_80093360(self, 0);
        _baswim_entrypoint_6(self, 0);
        if (bs_getCurrentState(self) != 0x4C) {
            _baairbar_entrypoint_0(self, 1);
        }
        _baswim_entrypoint_4(self);
    }
}

void func_808001A8_bsbanswim()
{
    func_80800104_bsbanswim();
}

void func_808001C8_bsbanswim(u8 *self)
{
    // Matching: the long long temporary for the initial substate is needed for the match.
    long long init_substate;
    func_800C6DA0(0x3F);
    baanim_playForDuration_onceSmoothStartingAt(self, 0x27D, 0x3FD9999A, 0x3DCCCCCD);
    func_80800000_bsbanswim(self);
    yaw_setVelocityBounded(self, 0x43FA0000, 0x40A00000);
    func_80800030_bsbanswim(self);
    init_substate = 0;
    _baswim_entrypoint_10(self, 0);
    _baswim_entrypoint_8(self, 0x44160000);
    func_8009BFE4(self, 0x43480000, 0x40200000);
    *(s8 *) ((s8 *) self + 0x164) = init_substate;
}

void func_8080025C_bsbanswim(u8 *self)
{
    s32 next_state;
    s32 anctrl;
    s32 substate;

    next_state = 0;
    anctrl = baanim_getAnimCtrlPtr();
    substate = *(u8 *) ((char *) self + 0x164);
    switch (substate) {
        case 0:
            func_8009BF5C(self, 5e+01f);
            if (anctrl_isAt(anctrl, 0x3EBD70A4) != 0) {
                if (_baswim_entrypoint_1(self) != 0) {
                    func_800A0E64(self);
                }
                _baswim_entrypoint_10(self, 3e+02f);
                _baswim_entrypoint_8(self, 0x43480000);
                *(u8 *) ((char *) self + 0x164) = 1U;
            }
            break;
        case 1:
            _baswim_entrypoint_11(self);
            _baswim_entrypoint_13(self);
            if (anctrl_isAt(anctrl, 0x3F428F5C) != 0) {
                next_state = 0x2B;
            }
    }
    if (anctrl_isAt(anctrl, 0x3F19999A) != 0) {
        func_8009DE38(self, 0x3FD, 0x3F800000);
    }
    if (player_inWater(self) == 0) {
        next_state = 1;
    }
    bs_setState(self, next_state);
}

int bsbanswim_entrypoint_0(s32 type)
{
    return D_80800A30_bsbanswim[type];
}

int func_80800390_bsbanswim(s32 state)
{
    switch (state) {
        case 0x81:
        case 0x82:
        case 0x90:
            return 1;

        default:
            return 0;
    }
}

void func_808003BC_bsbanswim(self) s32 self;
{
    s32 next_state;
    next_state = bs_getNextState();
    if (func_80800390_bsbanswim(next_state) == 0) {
        if (func_8008E0E8(self) != 0) {
            _bapackctrl_entrypoint_5(self, 3);
        }
        func_80800104_bsbanswim(self);
    }
}

void func_8080040C_bsbanswim(s32 self)
{
    if (func_80800390_bsbanswim(bs_getPreviousState()) == 0) {
        baanim_playForDuration_loopSmooth(self, 0x27E, 0x3F400000);
        func_80800000_bsbanswim(self);
        func_80800030_bsbanswim(self);
        // Matching: the chain of 64-bit masks around 0 is needed for the match.
        _baswim_entrypoint_10(
            self, ((((0 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) &
                      0xFFFFFFFFFFFFFFFF) &
                         0xFFFFFFFFFFFFFFFF);
        _baswim_entrypoint_8(self, 0x44160000);
        func_8009BC5C(self, 0x40000000);
        if (func_8008E0E8(self) != 0) {
            _bapackctrl_entrypoint_5(self, 4);
        }
    }
}

void func_8080049C_bsbanswim()
{
    func_808003BC_bsbanswim();
}

void func_808004BC_bsbanswim(Actor *self)
{
    void *anctrl;
    anctrl = baanim_getAnimCtrlPtr();
    func_8080040C_bsbanswim(self);
    anctrl_setDuration(anctrl, 1.0f);
}

void func_808004F4_bsbanswim(s32 self)
{
    s32 next_state;
    s32 anctrl;
    s32 paddle_mode;

    next_state = 0;
    anctrl = baanim_getAnimCtrlPtr();
    _baswim_entrypoint_11(self);
    _baswim_entrypoint_12(self);
    _baswim_entrypoint_13(self);
    if (anctrl_isAt(anctrl, 0x3F03126F) != 0) {
        _baswim_entrypoint_10(self, 3.2e+02f);
    } else {
        _baswim_entrypoint_10(self, 2.5e+02f);
    }
    if (anctrl_isAt(anctrl, 0x3E2E147B) != 0) {
        func_8009DF18(self, 0x3FD, 0x3FF33333, 0x2710);
    }
    if (anctrl_isAt(anctrl, 0x3F2B851F) != 0) {
        func_8009DF18(self, 0x3FD, 0x3FD9999A, 0x2710);
    }
    paddle_mode = _baswim_entrypoint_3(self);
    switch (paddle_mode) {
        case 1:
            break;
        case 0:
            if (anctrl_isAt(anctrl, 0x3F7D70A4) != 0) {
                next_state = 0x2B;
            }
            break;
        case 2:
            next_state = 0x82;
            break;
        case 3:
            next_state = 0x90;
    }
    if (_baswim_entrypoint_2(self) != 0) {
        next_state = 0x2D;
    }
    if (player_inWater(self) == 0) {
        next_state = 1;
    }
    bs_setState(self, next_state);
}

int bsbanswim_entrypoint_1(int type)
{
    return D_80800A40_bsbanswim[type];
}

void func_80800670_bsbanswim()
{
    func_808003BC_bsbanswim();
}

void func_80800690_bsbanswim(s32 self)
{
    s32 anctrl;

    anctrl = baanim_getAnimCtrlPtr();
    func_8080040C_bsbanswim(self);
    anctrl_setDuration(anctrl, 0.8f);
}

void func_808006CC_bsbanswim(s32 self)
{
    s32 next_state;
    s32 anctrl;
    s32 paddle_mode;

    next_state = 0;
    anctrl = baanim_getAnimCtrlPtr();
    _baswim_entrypoint_11(self);
    _baswim_entrypoint_12(self);
    _baswim_entrypoint_13(self);
    if (anctrl_isAt(anctrl, 0x3F03126F) != 0) {
        _baswim_entrypoint_10(self, 4.5e+02f);
    } else {
        _baswim_entrypoint_10(self, 3e+02f);
    }
    if (anctrl_isAt(anctrl, 0x3E2E147B) != 0) {
        func_8009DF18(self, 0x3FD, 0x3FF33333, 0x2710);
    }
    if (anctrl_isAt(anctrl, 0x3F2B851F) != 0) {
        func_8009DF18(self, 0x3FD, 0x3FD9999A, 0x2710);
    }
    paddle_mode = _baswim_entrypoint_3(self);
    switch (paddle_mode) {
        case 2:
            break;
        case 0:
            if (anctrl_isAt(anctrl, 0x3F7D70A4) != 0) {
                next_state = 0x2B;
            }
            break;
        case 1:
            next_state = 0x81;
            break;
        case 3:
            next_state = 0x90;
    }
    if (_baswim_entrypoint_2(self) != 0) {
        next_state = 0x2D;
    }
    if (player_inWater(self) == 0) {
        next_state = 1;
    }
    bs_setState(self, next_state);
}

int bsbanswim_entrypoint_2(int type)
{
    return D_80800A50_bsbanswim[type];
}

void func_80800848_bsbanswim()
{
    func_808003BC_bsbanswim();
}

void func_80800868_bsbanswim(s32 self)
{
    s32 anctrl;

    anctrl = baanim_getAnimCtrlPtr();
    func_8080040C_bsbanswim(self);
    anctrl_setDuration(anctrl, 0.7f);
}

void func_808008A4_bsbanswim(s32 self)
{
    s32 next_state;
    s32 anctrl;
    s32 paddle_mode;

    next_state = 0;
    anctrl = baanim_getAnimCtrlPtr();
    _baswim_entrypoint_11(self);
    _baswim_entrypoint_12(self);
    _baswim_entrypoint_13(self);
    if (anctrl_isAt(anctrl, 0x3F03126F) != 0) {
        _baswim_entrypoint_10(self, 6e+02f);
    } else {
        _baswim_entrypoint_10(self, 4e+02f);
    }
    if (anctrl_isAt(anctrl, 0x3E2E147B) != 0) {
        func_8009DF18(self, 0x3FD, 0x3FF33333, 0x2710);
    }
    if (anctrl_isAt(anctrl, 0x3F2B851F) != 0) {
        func_8009DF18(self, 0x3FD, 0x3FD9999A, 0x2710);
    }
    paddle_mode = _baswim_entrypoint_3(self);
    switch (paddle_mode) {
        case 3:
            break;
        case 0:
            if (anctrl_isAt(anctrl, 0x3F7D70A4) != 0) {
                next_state = 0x2B;
            }
            break;
        case 1:
            next_state = 0x81;
            break;
        case 2:
            next_state = 0x82;
    }
    if (_baswim_entrypoint_2(self) != 0) {
        next_state = 0x2D;
    }
    if (player_inWater(self) == 0) {
        next_state = 1;
    }
    bs_setState(self, next_state);
}

s32 bsbanswim_entrypoint_3(s32 type)
{
    return D_80800A60_bsbanswim[type];
}

extern void func_80099B94();
s32 D_80800A30_bsbanswim[4] = {(u32) func_808001A8_bsbanswim, (u32) func_808001C8_bsbanswim,
                               (u32) func_8080025C_bsbanswim, (u32) func_80099B94};
s32 D_80800A40_bsbanswim[4] = {(u32) func_8080049C_bsbanswim, (u32) func_808004BC_bsbanswim,
                               (u32) func_808004F4_bsbanswim, (u32) func_80099B94};
s32 D_80800A50_bsbanswim[4] = {(u32) func_80800670_bsbanswim, (u32) func_80800690_bsbanswim,
                               (u32) func_808006CC_bsbanswim, (u32) func_80099B94};
s32 D_80800A60_bsbanswim[4] = {(u32) func_80800848_bsbanswim, (u32) func_80800868_bsbanswim,
                               (u32) func_808008A4_bsbanswim, (u32) func_80099B94};
