#include "common.h"

extern void *D_808004F0_chweldarhead;
extern void *func_80100094(Actor *, s32);
extern u8 D_808004E0_chweldarhead[];
extern void func_8010D5DC(void);
extern void func_800F4A58(s32, f32 *, f32);
typedef struct { f32 local_0[3]; s32 local_1; f32 local_2; f32 local_3; } WeldarMarker37;
extern s16 D_8080053E_chweldarhead;
extern s32 D_80800538_chweldarhead;
typedef struct { f32 pos[3]; s32 unkC; f32 unk10; f32 unk14; u8 unk18[1]; } WeldarHeadLocal;
typedef union { u32 w; s32 s; struct { s16 a; s16 b; } h; } WeldarHeadArg;
extern s32 _susubgame_entrypoint_3(Actor *, void *, s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);

void *chweldarhead_entrypoint_0()
{
    return &D_808004F0_chweldarhead;
}

void func_8080000C_chweldarhead(Actor *param_0)
{
    u8 *local_0 = func_80100094(param_0, 0);
    WeldarMarker37 local_1;
    WeldarMarker37 local_2;
    s32 local_3;

    _susubgame_entrypoint_0(param_0, local_0 + 0x18, 0);
    _susubgame_entrypoint_12(local_0 + 0x18, D_808004E0_chweldarhead);
    if (!func_800DA298(0x18C)) {
        func_800FFAB0(param_0);
        return;
    }
    _subaddiemarker_entrypoint_1(param_0, 0x320, 0x32, local_0, 1);
    if (func_800DA9E4(0x9C9, 0)) {
        local_3 = func_800F54E4();
        _subaddiemarker_entrypoint_1(param_0, 0x320, 0x33, &local_1, 1);
        _subaddiemarker_entrypoint_1(param_0, 0x320, 0x34, &local_2, 1);
        func_800F8294(local_3, local_1.local_0);
        func_800F497C(local_3);
        func_800F49D4(local_3, func_8010D5DC, param_0->unk0);
        func_800F4A58(local_3, local_2.local_0, 250.0f);
        _susubgame_entrypoint_6(param_0, local_0 + 0x18, 0x44, 0x2030, 0);
        func_80102424(param_0, 2);
    } else {
        param_0->unk64_20 = 0;
        func_80108B04(param_0, 0);
    }
}

void func_80800170_chweldarhead(Actor *param_0)
{
    extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);

    if (param_0->unk70_10 == 1) {
        D_8080053E_chweldarhead = func_800DC128(0, 4) + 0x1361;
        _subaddiedialog_entrypoint_7(param_0, param_0->position, &D_80800538_chweldarhead);
    }
    _sudeflect_entrypoint_0(param_0->position, 20.0f, 120.0f, 10);
}

void func_8080038C_chweldarhead();

s32 func_808001E4_chweldarhead(Actor *this, s32 msg, WeldarHeadArg arg)
{
    WeldarHeadLocal *local;
    Actor *v;

    local = func_80100094(this, 0);
    switch (msg) {
    case 0x2E:
        func_8080038C_chweldarhead(this, ((s16 *)&arg)[0], ((s16 *)&arg)[1]);
        break;
    case 0x57:
        return _susubgame_entrypoint_3(this, local->unk18, arg.s & 0xFFFF, (arg.w & 0xFFFF0000) >> 16);
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808004E0_chweldarhead, this->scale);
        break;
    case 0x32:
        _subaddiedialog_entrypoint_11(this->unk0, 0x1360, 0xE, this->position, 0xB5);
        break;
    case 0xB:
        if (arg.w == 0x48) {
            _subaddiedialog_entrypoint_11(this->unk0, 0x1384, 0xE, this->position, 0xB5);
            return 4;
        }
        return 3;
    case 0x3D:
        v = func_80108528(0x210, local->pos, local->unk10, &this);
        func_80102FDC(v, local->unk14);
        if (this->unk64_20) {
            _chappearfx_entrypoint_1(v, 0x22, 1, 1.0f);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080038C_chweldarhead(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x1360:
        _susubgame_entrypoint_6(param_0, local_0 + 0x18, 0x48, 0x30, 0);
        func_80108B04(param_0, 0);
        param_0->unk64_20 = 1;
        break;
    case 0x1384:
        _susubgame_entrypoint_4(param_0, local_0 + 0x18);
    default:
        func_80102424(param_0, 1);
        break;
    }
}
