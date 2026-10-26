#include "common.h"
#include "playerstate.h"
extern void func_800C51A4(s32, f32);

extern void func_800F3E84(PlayerState *, f32 *);
extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern f32 baroll_get(PlayerState *);
extern PlayerState *func_800A4CA8(PlayerState *);
extern f32 func_800D8FF8(void);
extern f32 bastick_getY(PlayerState *);
extern f32 bastick_getX(PlayerState *);
extern f32 _bsdronelook_entrypoint_2(f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void _ncba1p_entrypoint_8(PlayerState *, f32 *);
typedef struct { u32 unk0; u8 pad4[0x10]; u8 unk14; u8 unk15; u8 unk16; } FpCtrl;
typedef struct { u8 pad0[0x90]; FpCtrl *unk90; } FpOwner;
extern u8 D_808010D0_bafpctrl[];
extern u8 D_808010C0_bafpctrl[];
extern s32 func_8009E674(FpOwner *, s32);
extern void func_8010D930(s32, s32, s32, void *);
extern void _baeggaim_entrypoint_1(FpOwner *);
extern void _baeggaim_entrypoint_2(FpOwner *);
extern s32 func_8009E71C(FpOwner *, s32);
extern s32 func_800C6E38(s32);
extern void func_800F3BD0(s32, s32, f32 *);
extern f32 yaw_get(s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern u8 D_808010B0_bafpctrl[];
extern s32 D_808010A0_bafpctrl;
extern void _ncba1p_entrypoint_12(PlayerState *, f32);
extern f32 _ncba1p_entrypoint_11(PlayerState *);
extern void func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_800EE7F8;
extern s32 baflag_isTrue(PlayerState *, s32);
extern s32 bakey_held(PlayerState *, s32);
extern f32 func_800139F8(f32);
f32 bafpctrl_entrypoint_3();
s32 bafpctrl_entrypoint_4();
s32 bafpctrl_entrypoint_6();
void bafpctrl_entrypoint_9();
void bafpctrl_entrypoint_10();
void bafpctrl_entrypoint_13();
void bafpctrl_entrypoint_14();
void func_80800114_bafpctrl();

s32 bafpctrl_entrypoint_0() 
{
    return 0x1C;
}

s32 func_80800008_bafpctrl(PlayerState *param_0)
{
    if (bakey_pressed(param_0, 12) && bafpctrl_entrypoint_6(param_0) &&
        !(**(u32 **)((u8 *)param_0 + 0x90) & 2)) return 1;
    if (player_inWater(param_0)) {
        if (func_8008FD48() == 1 && !func_8008FF94()) return 1;
    } else {
        if (!func_8008DF8C(param_0, 0x19)) {
            if (bafpctrl_entrypoint_4(param_0) != 1) return 0;
            return 1;
        }
    }
    return 0;
}

void func_808000DC_bafpctrl(s32 param_0, f32 param_1, f32 param_2)
{
  s32 local_0;
  ;
  *((f32 *) ((*((s32 *) (param_0 + 0x90))) + 0x18)) = param_2;
  func_800C51A4(func_800A4C68(param_0), param_1);
}

void func_80800114_bafpctrl(param_0) PlayerState *param_0;
{
    f32 local_0;

    if (baflag_isTrue(param_0, 0x3A)) {
        return;
    }
    if (baflag_isTrue(param_0, 0x2E) || !func_800C6E38(0x2B)) {
        return;
    }
    local_0 = *(f32 *)(*(u8 **)((u8 *)param_0 + 0x90) + 0x18);
    if (bakey_held(param_0, 10) && local_0 < 40.0f) {
        local_0 += 1.5f;
    }
    if (bakey_held(param_0, 13) && 5.21f < local_0) {
        local_0 -= 1.5f;
    }
    func_808000DC_bafpctrl(param_0, 0.36397022f / func_800139F8(local_0 * 0.5f), local_0);
}

void func_8080022C_bafpctrl(PlayerState *param_0)
{
    f32 local_0[3];
    func_800F3E84(param_0, local_0);
    local_0[0] = -func_8009BFCC(param_0);
    local_0[1] = yaw_getIdeal(param_0) + 180.0f;
    local_0[2] = -baroll_get(param_0);
    _ncba1p_entrypoint_7(func_800A4CA8(param_0), local_0);
}

void func_808002A4_bafpctrl(PlayerState *param_0)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    if (_ncba1p_entrypoint_10(func_800A4CA8(param_0)) == 2) {
        _ncba1p_entrypoint_8(func_800A4CA8(param_0), local_0);
        if (!baflag_isTrue(param_0, 0x25)) {
            local_1 = func_800D8FF8();
            local_2 = bafpctrl_entrypoint_3(param_0) * 90.0f;
            local_0[0] -= bastick_getY(param_0) * local_2 * local_1;
            local_0[1] -= bastick_getX(param_0) * local_2 * local_1;
            local_0[2] = 0.0f;
            local_0[0] = _bsdronelook_entrypoint_2(local_0[0]);
        }
        _ncba1p_entrypoint_7(func_800A4CA8(param_0), local_0);
        yaw_setIdeal(param_0, local_0[1] + 180.0f);
    }
}

void func_808003BC_bafpctrl(PlayerState *param_0)
{
    f32 local_0[3];

    if (_ncba1p_entrypoint_10(func_800A4CA8(param_0)) == 2) {
        _ncba1p_entrypoint_8(func_800A4CA8(param_0), local_0);
        yaw_setIdeal(param_0, local_0[1] + 180.0f);
    }
}

void func_80800424_bafpctrl(FpOwner *this, s32 state)
{
    s32 prev;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 r;

    prev = this->unk90->unk14;
    switch (prev) {
    case 0:
        this->unk90->unk16 = 0;
        break;
    case 2:
        if (state == 1) {
            func_8010D930(0xC, func_8009E674(this, 2), 0, D_808010D0_bafpctrl);
        }
        _baeggaim_entrypoint_1(this);
        break;
    }
    this->unk90->unk14 = state;
    switch (state) {
    case 2:
        if (this->unk90->unk16) {
            func_8010D930(0xC, func_8009E674(this, 2), 0, D_808010C0_bafpctrl);
        } else {
            this->unk90->unk16++;
        }
        _baeggaim_entrypoint_2(this);
        break;
    case 1:
        a = func_8009E71C(this, 9);
        b = func_8009E71C(this, 0xB);
        c = (a == 0) && (b == 0);
        d = func_800C6E38(0x1B);
        e = func_800C6E38(0x1F);
        f = func_800C6E38(0x16);
        r = (a && d) || (b && e) || (c && f);
        if (prev == 0 && r && !(this->unk90->unk0 & 4)) {
            this->unk90->unk15 = 1;
        } else {
            this->unk90->unk15 = 0;
        }
        break;
    }
}

void func_808005FC_bafpctrl(s32 param_0, f32 *param_1) {
    f32 local_0[3];
    func_800F3BD0(param_0, 5, param_1);
    func_800EEB9C(local_0, yaw_get(param_0), 5.0f);
    func_800EF04C(param_1, local_0);
}

void func_8080064C_bafpctrl(s32 param_0)
{
    if (!func_8009CC68(param_0)) {
        func_8010D930(0xC, func_8009E674(param_0, 2), 0, D_808010B0_bafpctrl);
    }
    func_80110C2C(func_800A4CA8(param_0));
    baflag_clear(param_0, 0x24);
    baflag_clear(param_0, 0x25);
    baflag_clear(param_0, 0x2E);
    baflag_clear(param_0, 0x17);
    baflag_clear(param_0, 0x3A);
    func_80800424_bafpctrl(param_0, 0);
    func_808000DC_bafpctrl(param_0, 1.0f, 40.0f);
}

void func_80800704_bafpctrl(PlayerState *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];

    if (!((**(s32 **)((u8 *)param_0 + 0x90)) & 8)) {
        func_8010D930(0xC, func_8009E674(param_0, 2), 0, &D_808010A0_bafpctrl);
    }
    func_80110BF0(func_800A4CA8(param_0));
    func_808005FC_bafpctrl(param_0, local_0);
    _ncba1p_entrypoint_6(func_800A4CA8(param_0), local_0);
    if (baflag_isTrue(param_0, 0x25)) {
        func_80099A7C(param_0, local_2);
        _badrone_entrypoint_33(param_0, local_2);
        func_800A516C(local_1, local_2, local_0);
    } else {
        func_800F3E84(param_0, local_1);
        local_1[0] = 0.0f;
        local_1[2] = 0.0f;
        local_1[1] += 180.0f;
    }
    _ncba1p_entrypoint_7(func_800A4CA8(param_0), local_1);
    yaw_setIdeal(param_0, 180.0f + local_1[1]);
    if ((**(s32 **)((u8 *)param_0 + 0x90)) & 8) {
        yaw_applyIdeal(param_0);
        _ncba1p_entrypoint_12(func_800A4CA8(param_0), 0.01f);
    }
    baflag_set(param_0, 0x17);
    (*(u8 **)((u8 *)param_0 + 0x90))[0x14] = 0;
    func_80800424_bafpctrl(param_0, 1);
}

void func_80800880_bafpctrl(u8 *param_0) {
    if (*(*(s32 **)((s8 *)(param_0) + (0x90))) & 1) {
        _ncba1p_entrypoint_7(func_800A4CA8(param_0), (*(s32 **)((s8 *)(param_0) + (0x90))) + 1, param_0);
    }
}

void func_808008CC_bafpctrl(s32 param_0) {
  s8 _sfpad[8];
  s32 sp1C;
  func_808005FC_bafpctrl(param_0, &sp1C);
  _ncba1p_entrypoint_6(func_800A4CA8(param_0), &sp1C);
}

int func_80800904_bafpctrl(PlayerState *param_0)
{
    return bakey_pressed(param_0, 0xB) &&
        func_800C6E38(0x16) &&
        bafpctrl_entrypoint_6(param_0) &&
        !(**(u32 **)((u8 *)param_0 + 0x90) & 4);
}

s32 func_80800970_bafpctrl(param_0) PlayerState *param_0;
{
    s32 local_0;
    u8 local_1;

    local_0 = 0;
    local_1 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x90)))) + (0x14)));
    switch (local_1) {
    case 1:
        if ((func_80800904_bafpctrl(param_0) != 0) || (baflag_isTrue(param_0, 0x24) != 0)) {
            (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x90)))) + (0x15))) = 1U;
        }
        if (((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x90)))) + (0x15))) != 0) && (_baeggcursor_entrypoint_2(param_0) == 1) && (_ncba1p_entrypoint_11(func_800A4CA8(param_0)) < 0.25f)) {
            func_80800424_bafpctrl(param_0, 2);
        } else if ((func_80800008_bafpctrl(param_0) != 0) && (_ncba1p_entrypoint_10(func_800A4CA8(param_0)) == 2)) {
            local_0 = 1;
        } else if (bafpctrl_entrypoint_6(param_0) != 0) {
            if ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x90)))) + (0x11))) != 0) {
                func_8080022C_bafpctrl(param_0);
            } else {
                func_808002A4_bafpctrl(param_0);
            }
            func_80800880_bafpctrl(param_0);
            func_808008CC_bafpctrl(param_0);
        }
        break;
    case 2:
        func_80094AB4(param_0);
        if ((func_80800904_bafpctrl(param_0) != 0) && (_baeggcursor_entrypoint_2(param_0) == 2)) {
            if (baflag_isTrue(param_0, 0x24) != 0) {
                local_0 = 1;
            } else {
                func_80800424_bafpctrl(param_0, 1);
            }
        } else if (func_80800008_bafpctrl(param_0) != 0) {
            local_0 = 1;
        } else if (bafpctrl_entrypoint_6(param_0) != 0) {
            if ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x90)))) + (0x11))) != 0) {
                func_8080022C_bafpctrl(param_0);
            } else {
                func_808003BC_bafpctrl(param_0);
            }
            func_808008CC_bafpctrl(param_0);
            func_80800880_bafpctrl(param_0);
            _baeggaim_entrypoint_3(param_0);
        }
        break;
    }
    func_80800114_bafpctrl(param_0);
    return local_0;
}

s32 bafpctrl_entrypoint_1(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x90)))[0x11];
}

s32 bafpctrl_entrypoint_2(s32 param_0)
{
  u8 new_var;
  ;
  return (*((u8 **) (param_0 + 0x90)))[18];
}

f32 bafpctrl_entrypoint_3(param_0) u8 *param_0; {
    func_800F10B4(*(f32 *)(*(u8 **)(param_0 + 0x90) + 0x18), 10.0f, 40.0f, 0.2f, 1.0f);
}

s32 bafpctrl_entrypoint_4(param_0) s32 param_0; {
    return *(u8 *)(*(s32 *)(param_0 + 0x90) + 0x10);
}

int bafpctrl_entrypoint_5(Actor *param_0)
{
  u8 local_0;
  s32 *ptr;
  ;
  ;
  return (*((u8 *) (((char *) (*((s32 **) (((char *) param_0) + 0x90)))) + 0x14))) == 2;
}

s32 bafpctrl_entrypoint_6(param_0) s32 param_0;
{
    return ((u8 *)(*(u8 **)(param_0 + 0x90)))[0x13];
}

void bafpctrl_entrypoint_7(s32 arg0) 
{
}
void bafpctrl_entrypoint_8(u8 *param_0) {
    *(s8 *)((char *)*(u8 **)((char *)param_0 + 0x90) + 0x10) = 0;
    bafpctrl_entrypoint_14(param_0, 1);
    func_800EFD24(*(u8 **)((char *)param_0 + 0x90) + 4);
    *(s32 *)((char *)*(u8 **)((char *)param_0 + 0x90) + 0) = 0;
    bafpctrl_entrypoint_9(param_0, 0);
    bafpctrl_entrypoint_10(param_0, 0);
    bafpctrl_entrypoint_13(param_0, 1);
    *(f32 *)((char *)*(u8 **)((char *)param_0 + 0x90) + 0x18) = 40.0f;
}

void bafpctrl_entrypoint_9(arg, v) void *arg; s32 v;
{
    ((s8 *)(*(void **)((char *)arg + 0x90)))[17] = v;
}

void bafpctrl_entrypoint_10(arg, v) void *arg; s32 v;
{
    ((s8 *)(*(void **)((char *)arg + 0x90)))[18] = v;
}

void bafpctrl_entrypoint_11(int param_0, int param_1, int param_2) {
    int *ptr;
    if (param_2 != 0) {
        ptr = *(int **)(param_0 + 0x90);
        *ptr |= param_1;
    } else {
        ptr = *(int **)(param_0 + 0x90);
        *ptr &= ~param_1;
    }
}

int bafpctrl_entrypoint_12(Actor *param_0)
{
  func_800EE7F8(*(s32*)((char*)param_0 + 0x90) + 4);
}

void bafpctrl_entrypoint_13(param_0, param_1) void *param_0; s32 param_1;
{
  *(s8 *)(*(s32 *)((char *)param_0 + 0x90) + 0x13) = param_1;
  _baeggcursor_entrypoint_6(param_0);
}

void bafpctrl_entrypoint_14(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    switch ((*(u8 **)((u8 *)param_0 + 0x90))[0x10]) {
        case 1:
            if (param_1 == 1) return;
            break;
        case 3:
            func_8080064C_bafpctrl(param_0);
            break;
    }
    (*(u8 **)((u8 *)param_0 + 0x90))[0x10] = param_1;
    switch (param_1) {
        case 1:
            bafpctrl_entrypoint_9(param_0, 0);
            bafpctrl_entrypoint_10(param_0, 0);
            **(s32 **)((u8 *)param_0 + 0x90) = 0;
            func_8009ADF0(param_0, 7, 0);
            break;
        case 2:
            func_8009ADF0(param_0, 7, 1);
            break;
        case 3:
            func_8009ADF0(param_0, 7, 1);
            func_80800704_bafpctrl(param_0);
            break;
    }
}

int func_80800E30_bafpctrl(param_0) u8 *param_0;
{
    return bakey_pressed(param_0, 12) &&
        bafpctrl_entrypoint_6(param_0) &&
        func_800F6774(*(void **)(param_0 + 0x184)) &&
        _ncba1p_entrypoint_10(func_800A4CA8(param_0)) != 3;
}

void bafpctrl_entrypoint_15(u8 *param_0) {
    u8 local_0;

    local_0 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x90)))) + (0x10)));
    switch (local_0) {                              
    case 2:
        if (func_80800E30_bafpctrl() != 0) {
            bafpctrl_entrypoint_14(param_0, 3);
            return;
        }
    case 1:
        return;
    case 3:
        if (func_80800970_bafpctrl() != 0) {
            bafpctrl_entrypoint_14(param_0, 2);
        }
        break;
    }
}

void bafpctrl_entrypoint_16(u8 *param_0) {
    u8 *local_0 = *(u8 **)(param_0 + 0x90);
    if (local_0[0x13] && local_0[0x10] != 3) {
        bafpctrl_entrypoint_14(param_0);
    }
}

void bafpctrl_entrypoint_17(u8 *param_0) {
    if ((*(u8 **)(param_0 + 0x90))[0x13] != 0) {
        bafpctrl_entrypoint_14(param_0, 1);
    }
}

int bafpctrl_entrypoint_18(s32 param_0, s32 param_1)
{
  u32 local_0 = param_0 | 0;
  if (param_1 != 0)
  {
    bafpctrl_entrypoint_14((param_0 | 0) | 0, 2);
    bafpctrl_entrypoint_9(param_0 | 0, 1);
    bafpctrl_entrypoint_10(param_0 | 0, 1);
    func_800947EC(local_0, 1, 1);
    func_800947EC(param_0 | 0, 2, 1);
  }
  else
  {
    bafpctrl_entrypoint_14(param_0 | 0, 1);
    func_800947EC(param_0 | 0, 1, 0);
    func_800947EC(param_0 | 0, 2, 0);
  }
}

void bafpctrl_entrypoint_19(void *param_0)
{
    if (bafpctrl_entrypoint_4() == 3)
    {
        bafpctrl_entrypoint_14(param_0, 1);
        func_800A3544(param_0, 0);
        func_8009337C(param_0, 1);
        func_800A4EC8(param_0);
        _plcamera_entrypoint_0(((int *)param_0)[0x61]);
    }
}
