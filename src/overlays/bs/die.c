#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern void _badust_entrypoint_5(s32, f32, f32);
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern void _basudie_entrypoint_4(PlayerState *, f32, f32, f32, f32, f32);
extern void func_8009D820(PlayerState *, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void _basudie_entrypoint_5(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 player_isStable(PlayerState *);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void func_8009E058(PlayerState *);
extern void func_8009E084(PlayerState *);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern f32 func_800F0E00(f32, f32);
extern void _badust_entrypoint_9(PlayerState *);
extern s32 _basudie_entrypoint_7(PlayerState *);
extern void bs_setState(PlayerState *, s32);
extern void _basudie_entrypoint_6(void);
extern void func_800A0CF4(s32, s32);
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern s32 D_80800960_bsdie[];
extern void baanim_setEnd(PlayerState *, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern s32 D_80800970_bsdie[];
extern s32 D_80800980_bsdie[];

void func_80800000_bsdie(s32 param_0) {
    f32 local_0;

    for (local_0 = 0.0f; local_0 < 360.0f; local_0 += 45.0f) {
        _badust_entrypoint_5(param_0, local_0, 230.0f);
    }
}

void bsdie_entrypoint_0(PlayerState *param_0)
{
    void *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 9);
    anctrl_setSubrange(local_0, 0.0f, 0.3356f);
    anctrl_setDuration(local_0, 2.0f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    param_0->unk16C = 250.0f;
    _basudie_entrypoint_4(param_0, 250.0f, 510.0f, -1400.0f, 25.0f, 3.5f);
    func_800A0CF4(param_0, 1);
    func_8009D820(param_0, 1.0f);
    func_8009BFE4(param_0, 1000.0f, 12.0f);
    param_0->unk15C.word = 0;
}

void bsdie_entrypoint_1(PlayerState *this)
{
    void *aCtrl;
    s32 next;

    aCtrl = baanim_getAnimCtrlPtr(this);
    next = 0;
    _basudie_entrypoint_5(this);
    baphysics_set_target_horizontal_velocity(this, this->unk16C);
    switch (this->unk15C.word) {
    case 0:
        if (player_isStable(this)) {
            anctrl_setSubrange(aCtrl, 0.0f, 1.0f);
            anctrl_setPlaybackType(aCtrl, 1);
            baphysics_set_vertical_velocity(this, 400.0f);
            func_8009E058(this);
            func_8009DF18(this, 0x428, 1.0f, 18000);
            _bamotor_entrypoint_1(this, 1.0, 1.0, 0.4f);
            func_80800000_bsdie(this);
            this->unk15C.word = 1;
        }
        break;
    case 1:
        if (player_isStable(this)) {
            func_8009E084(this);
            func_8009DF18(this, 0x427, 1.0f, 18000);
            _bamotor_entrypoint_1(this, 1.0f, 0.5f, 0.4f);
            this->unk15C.word = 2;
        }
        break;
    case 2:
        this->unk16C = func_800F0E00(this->unk16C - 12.0f, 0.0f);
        if (140.0f < this->unk16C) {
            _badust_entrypoint_9(this);
        }
        if (anctrl_isAt(aCtrl, 0.6538f)) {
            anctrl_setDuration(aCtrl, 4.0f);
        }
        if (anctrl_isStopped(aCtrl)) {
            this->unk16C = 0.0f;
            this->unk15C.word = 3;
        }
        break;
    case 3:
        break;
    }
    if (_basudie_entrypoint_7(this)) {
        next = 0x54;
    }
    bs_setState(this, next);
}

void bsdie_entrypoint_2(s32 param_0) {
    _basudie_entrypoint_6();
    func_800A0CF4(param_0, 0);
    func_8009BF5C(param_0, 0.0f);
    baroll_setIdeal(param_0, 0.0f);
}

int bsdie_entrypoint_3(s32 param_0)
{
  return D_80800960_bsdie[param_0];
}

void bsdie_entrypoint_4(PlayerState *param_0)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 0xD8);
    anctrl_setSubrange(local_0, 0.0f, 0.0932f);
    anctrl_setDuration(local_0, 4.7f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    *(f32 *)((u8 *)param_0 + 0x16C) = 250.0f;
    _basudie_entrypoint_4(param_0, *(f32 *)((u8 *)param_0 + 0x16C), 510.0f, -1400.0f, 30.0f, 4.0f);
    func_800A0CF4(param_0, 1);
    func_8009BFE4(param_0, 1000.0f, 12.0f);
    func_8009D820(param_0, 1.0f);
    *(s32 *)((u8 *)param_0 + 0x15C) = 0;
}

void bsdie_entrypoint_5(PlayerState *param_0)
{
    AnimCtrl *local_0;
    s32 local_1;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_1 = 0;
    _basudie_entrypoint_5(param_0);
    baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
    switch (param_0->unk15C.word) {
        case 3: break;
        case 0:
            if (func_8008DF8C(param_0, 0x96)) {
                baanim_setEnd(param_0, 0.1863f);
                param_0->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(param_0)) {
                func_8009DF18(param_0, 0x428, 1.0f, 0x4650);
                _bamotor_entrypoint_1(param_0, 1.0f, 1.0f, 0.4f);
                func_80800000_bsdie(param_0);
                func_8009E058(param_0);
                baanim_setEnd(param_0, 0.3333f);
                param_0->unk15C.word = 2;
            }
            break;
        case 2:
            param_0->unk16C = func_800F0E00(param_0->unk16C - 12.0f, 0.0f);
            if (param_0->unk16C > 140.0f) { _badust_entrypoint_9(param_0); }
            if (anctrl_isStopped(local_0)) {
                baanim_setEnd(param_0, 1.0f);
                param_0->unk15C.word = 3;
                param_0->unk16C = 0.0f;
            }
            break;
    }
    if (_basudie_entrypoint_7(param_0)) { local_1 = 0x54; }
    bs_setState(param_0, local_1);
}

void bsdie_entrypoint_6(s32 param_0) {
    _basudie_entrypoint_6();
    func_8009BF5C(param_0, 0.0f);
    baroll_setIdeal(param_0, 0.0f);
    func_800A0CF4(param_0, 0);
}

int bsdie_entrypoint_7(s32 param_0)
{
  return D_80800970_bsdie[param_0];
}

void bsdie_entrypoint_8(PlayerState *param_0)
{
    void *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    param_0->unk16C = 250.0f;
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 0xD7);
    anctrl_setSubrange(local_0, 0.0f, 0.0981f);
    anctrl_setDuration(local_0, 3.8f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    _basudie_entrypoint_4(param_0, param_0->unk16C, 510.0f, -1400.0f, 30.0f, 3.8f - 0.4f);
    func_8009BFE4(param_0, 1000.0f, 12.0f);
    func_8009D820(param_0, 1.0f);
    param_0->unk15C.word = 0;
}

void bsdie_entrypoint_9(PlayerState *param_0)
{
    AnimCtrl *local_0;
    s32 local_1;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_1 = 0;
    _basudie_entrypoint_5(param_0);
    baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
    switch (param_0->unk15C.word) {
        case 3: break;
        case 0:
            if (func_8008DF8C(param_0, 0xC8)) {
                baanim_setEndAndDuration(param_0, 0.1961f, 3.1f);
                param_0->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(param_0)) {
                func_8009DF18(param_0, 0x428, 1.0f, 0x4650);
                _bamotor_entrypoint_1(param_0, 1.0f, 1.0f, 0.4f);
                func_80800000_bsdie(param_0);
                func_8009E058(param_0);
                baanim_setEnd(param_0, 0.75f);
                param_0->unk15C.word = 2;
            }
            break;
        case 2:
            param_0->unk16C = func_800F0E00(param_0->unk16C - 7.0f, 0.0f);
            if (param_0->unk16C > 140.0f) { _badust_entrypoint_9(param_0); }
            if (anctrl_isStopped(local_0)) {
                baanim_setEnd(param_0, 1.0f);
                param_0->unk15C.word = 3;
                param_0->unk16C = 0.0f;
            }
            break;
    }
    if (_basudie_entrypoint_7(param_0)) { local_1 = 0x54; }
    bs_setState(param_0, local_1);
}

void bsdie_entrypoint_10(s32 param_0) {
    _basudie_entrypoint_6();
    func_8009BF5C(param_0, 0);
    baroll_setIdeal(param_0, 0);
}

int bsdie_entrypoint_11(int param_0)
{
  return D_80800980_bsdie[param_0];
}
