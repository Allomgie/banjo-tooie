#include "common.h"

#define BOX ((f32 *)this->actorData)
extern int D_80801270_chbanjoctrl;
extern s32 _chbanjoctrl_entrypoint_1(s32);
extern s32 _chbanjoctrl_entrypoint_2(s32);
extern void func_800F69E8(void);
extern void func_800F6968(void);
extern f32 func_800F2094(f32, f32);
extern s32 D_808012B8_chbanjoctrl;
extern int func_8010CB0C(void *, s32, s32, s32);
extern int func_800F6C5C(s32);
extern int func_800F6478(s32);
extern f32 func_8010CD28(Actor *);
extern void func_800EFCD8(f32 *, f32, f32);
extern int func_800F7D90(s32, s32, f32 *, s32);
extern void _chhotwaterpoolbits_entrypoint_5(Actor *, f32);
extern u8 D_808012C4_chbanjoctrl[];
extern u8 D_808012E4_chbanjoctrl[];
extern u8 D_808012D4_chbanjoctrl[];
extern s32 func_800F54E4();
extern s32 func_800F6DA0(s32);
extern s32 func_800F6E40(s32);
extern s32 func_800F64A4(s32, s32);
extern u8 position_x[];
extern u8 unk70_25[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFD24(f32 *);
extern void func_800F586C(s32, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern s32 func_800F5410(s32);
extern void func_800F7E3C(s32, s32);
extern f32 mlAbsF(f32);
extern void func_800F7814(s32, f32 *);
extern void func_8008FE68(f32 *);
extern u8 D_808012F4_chbanjoctrl[];
extern s32 func_8001210C(s32);
extern s32 func_800F7058(s32);
extern s32 func_800F6590(s32);
extern s32 func_800F7018(s32);
extern s32 func_800F56AC(s32);
extern s32 func_800F6AA4(s32);
extern s32 func_800F55D0(s32);
extern s32 func_800F6438(s32);
extern f32 func_800F1DF4(void *, void *);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_800C696C(f32 *, f32, f32, s32, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800FEC1C(f32);
void func_80800098_chbanjoctrl();
void func_80800544_chbanjoctrl();
void func_80800684_chbanjoctrl(s32 *param_0, f32 param_1, s32 param_2, s32 param_3);
int func_808007D8_chbanjoctrl();
s32 func_808011F4_chbanjoctrl();
void func_80800DF8_chbanjoctrl();
void func_808010FC_chbanjoctrl();

int chbanjoctrl_entrypoint_0()
{
    return (int)&D_80801270_chbanjoctrl;
}

void func_8080000C_chbanjoctrl(f32 param_0[3])
{
  s32 local_0;
  if ((local_0 = param_0[18]) == 3)
  {
    param_0[1] = 0.0f;
    param_0[3] = 0.0f;
    if (func_800EA05C(param_0, local_0) == 0x12B)
    {
      ((u8 *) param_0)[0x65] &= ~0x10;
    }
    else
    {
      ((u8 *) param_0)[0x65] = (((u8 *) param_0)[0x65] & 0xFFFFu) | 0x10;
    }
  }
  func_80101FDC(param_0, local_0);
  func_80800098_chbanjoctrl(param_0);
}

void func_80800098_chbanjoctrl(param_0) Actor *param_0;
{
    ((u8 *)param_0)[0x70] &= ~0xFE;
    switch (param_0->unk70_10) {
    case 2:
        _subaddieDll_entrypoint_1(param_0);
        break;
    case 4:
        func_80800684_chbanjoctrl(param_0, 3.0f, func_800F69E8, _chbanjoctrl_entrypoint_1);
        break;
    case 5:
        func_80800684_chbanjoctrl(param_0, 3.0f, func_800F6968, _chbanjoctrl_entrypoint_2);
        break;
    }
}

void func_8080012C_chbanjoctrl(u32 a0)
{
  u16 local_0;
  u32 local_1;
  local_0 = *((u16 *) (a0 + 0x72));
  local_1 = (local_0 & 0xFFFFu) >> 10;
  if (local_1 != 0xb)
  {
    return;
  }
  func_808011F4_chbanjoctrl();
}

void func_80800D50_chbanjoctrl();

void func_80800D04_chbanjoctrl();

void func_80800B18_chbanjoctrl();

s32 func_80800ADC_chbanjoctrl();

void func_80800728_chbanjoctrl();

void func_808003F8_chbanjoctrl();

void func_8080025C_chbanjoctrl();

void func_80800160_chbanjoctrl(Actor *param_0)
{
    if (func_80090128()) {
        func_8008FE68((f32 *)param_0->actorData);
        switch (param_0->unk70_10) {
            case 1: break;
            case 2: func_8080025C_chbanjoctrl(param_0); break;
            case 3: func_808003F8_chbanjoctrl(param_0); break;
            case 4:
            case 5: func_80800728_chbanjoctrl(param_0); break;
            case 6: func_80800ADC_chbanjoctrl(param_0); break;
            case 7: func_80800B18_chbanjoctrl(param_0); break;
            case 8: func_80800D04_chbanjoctrl(param_0); break;
            case 9: func_80800D50_chbanjoctrl(param_0); break;
            case 10: func_80800DF8_chbanjoctrl(param_0); break;
            case 11: func_808010FC_chbanjoctrl(param_0); break;
            case 12: func_80801088_chbanjoctrl(param_0); break;
        }
    }
}

void func_8080025C_chbanjoctrl(s32 param_0)
{
 do { if (func_808007D8_chbanjoctrl()) { f32 local_f4; f32 local_f6; ; ; if ((*((f32 *) (((u8 *) param_0) + 0x1C))) < (*((f32 *) (((u8 *) param_0) + 0x8)))) { func_800904C8(0x91); } } } while (0);
}

s32 func_808002A4_chbanjoctrl(f32 param_0)
{
    s32 local_0;
    for (local_0 = 0; local_0 < 360; local_0 += 90) {
        if (func_800F2094(local_0, param_0) < 6.0f) return 0;
    }
    for (local_0 = 45; local_0 != 405; local_0 += 90) {
        if (func_800F2094(local_0, param_0) < 7.0f) return 0;
    }
    return 1;
}

f32 func_80800360_chbanjoctrl(f32 param_0)
{
    s32 local_0 = 0;
    f32 local_1 = 1.0f;
    f32 local_2;
    do {
        local_2 = param_0 + local_1;
        if (func_808002A4_chbanjoctrl(local_2)) return local_2;
        local_2 = param_0 - local_1;
        if (func_808002A4_chbanjoctrl(local_2)) return local_2;
        local_1 += 2.0f;
    } while (local_0 == 0);
    return param_0;
}

void func_808003F8_chbanjoctrl(Actor *param_0)
{
    s32 local_1;
    f32 local_x;
    f32 local_0[2];

    if (((f32 *)param_0->actorData)[1] <= param_0->position[1] &&
        func_8010CB0C(&D_808012B8_chbanjoctrl, 0xC1C, -140, -250)) {
        local_1 = func_800F54E4();
        if (func_800F6C5C(local_1) && func_800F6478(local_1)) {
            local_x = func_80800360_chbanjoctrl(func_8010CD28(param_0));
            func_800EFCD8(local_0, local_x, 3100.0f);
            local_0[1] = 0.0f;
            if (func_800F7D90(func_800F54E4(), 0x52, local_0, 1) == 2) {
                if (param_0->unk64_20) func_80800544_chbanjoctrl(param_0);
                else _chhotwaterpoolbits_entrypoint_5(param_0, 1.0f);
            }
        }
    }
}

s32 chbanjoctrl_entrypoint_1(s32 param_0) {
    if (func_800F7B9C(func_800F54E4(), 0x51) == 2) {
        _chhotwaterpoolbits_entrypoint_5(param_0, 1.0f);
        return 1;
    }
    return 0;
}

void func_80800544_chbanjoctrl(param_0) s32 param_0; {
    s32 local_0;

    local_0 = func_800F5410(func_800F54E4());
    switch (local_0) {
    case 11:
        func_800C4AF0(param_0 + 4, &D_808012C4_chbanjoctrl);
        break;
    case 13:
        func_800C4AF0(param_0 + 4, &D_808012D4_chbanjoctrl);
        break;
    default:
        func_800C4AF0(param_0 + 4, &D_808012E4_chbanjoctrl);
        break;
    }
    func_800F7620(func_800F54E4(), 0x3F800000, 0x3F000000, 0x3ECCCCCD);
}

s32 chbanjoctrl_entrypoint_2(s32 param_0) {
    s32 local_0;

    local_0 = func_800F54E4(param_0);
    if (func_800F798C(local_0, 0xD, 3)) {
        func_80800544_chbanjoctrl(param_0);
        return 1;
    }
    return 0;
}

void func_80800638_chbanjoctrl(u8 *param_0, s32 param_1) {
    if ((param_1 == 2) && ((*(s32 (**)())((s8 *)(param_0) + (0x24)))() != 0)) {
        (*(f32 *)((s8 *)(param_0) + (0x28))) = (f32) (*(f32 *)((s8 *)(param_0) + (0x2C)));
    }
    (*(s8 *)((s8 *)(param_0) + (0x30))) = (s8) param_1;
}

void func_80800684_chbanjoctrl(s32 *param_0, f32 param_1, s32 param_2, s32 param_3)
{
  param_0[9] = param_3;
  param_0[20] = param_2;
  *(s8 *)((char *)param_0 + 0x30) = 1;
  *(s8 *)((char *)param_0 + 0x30) = 1;
  *(f32 *)((char *)param_0 + 0x2C) = param_1;
  *(f32 *)((char *)param_0 + 0x28) = 0.0f;
}

int func_808006A8_chbanjoctrl(Actor *param_0)
{
    s32 local_0;

    local_0 = func_800F54E4();
    return !func_800F6DA0(local_0) && !func_800F6E40(local_0) && !func_800F64A4(local_0, 0x8000) && (*(s32 (**)(s32))((u8 *)param_0 + 0x50))(local_0);
}

void func_80800728_chbanjoctrl(s32 param_0)
{
  s32 new_var3;
  char new_var2;
  u8 local_0;
  s32 local_1;
  u8 new_var;
  local_1 = param_0;
  new_var2 = *((u8 *) (param_0 + 0x30));
  new_var = new_var2;
  local_0 = new_var;
  switch (local_0)
  {
    case 1:
      if (func_808006A8_chbanjoctrl(param_0))
    {
      func_80800638_chbanjoctrl(param_0, 2);
      return;
    }
      return;

    case 2:
      func_800D9078(param_0 + 0x28);
      if (*((f32 *) (param_0 + 0x28)) == 0.0f)
    {
      if (func_808006A8_chbanjoctrl(local_1))
      {
        func_80800638_chbanjoctrl(new_var3 = local_1, 2);
        return;
      }
      func_80800638_chbanjoctrl(param_0, 1);
    }
      break;

  }

}

int func_808007D8_chbanjoctrl(param_0) Actor *param_0;
{
    u32 local_0;
    local_0 = (u32)(*(s32 *)((char *)(param_0) + 0x70)) >> 25;
    if (local_0 == 0)
    {
        return 1;
    }
    return (func_800CC338((f32 *)((char *)(param_0) + 0x18), local_0 - 1, 0, param_0) + 1) != 0;
}

void func_80800824_chbanjoctrl(u8 *param_0, s32 param_1) {
    f32 sp24[3];
    f32 temp_f0;
    f32 temp_f2;

    func_800F5D70(param_1, sp24, param_0);
    if ((sp24[1] <= 0.0f) && (temp_f0 = (*(f32 *)((s8 *)(param_0) + (8))), temp_f2 = (*(f32 *)((s8 *)(param_0) + (0x1C))), (temp_f2 <= (temp_f0 + 200.0f)))) {
        if (temp_f2 <= temp_f0) {
            func_8080025C_chbanjoctrl(param_0);
            return;
        }
        if (func_800F6720(param_1) != 0) {
            func_800F7B9C(func_800F54E4(), 0x18);
        }
    }
}

void func_808008D8_chbanjoctrl(f32 *param_0, f32 param_1, f32 param_2) {
    func_800EFA4C(param_0, param_0[0] + param_1, param_0[1], param_0[2] + param_2);
}

void func_8080091C_chbanjoctrl(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    f32 local_4[3];
    local_3 = 0;
    func_800EFD24(local_0);
    func_800F586C(func_800F54E4(), local_1, local_2);
    local_1[0] += 1200.0f;
    local_2[0] -= 1200.0f;
    local_2[1] -= 1200.0f;
    local_1[2] += 1200.0f;
    local_2[2] -= 1200.0f;
    if (local_2[1] < ((f32 *)param_0->actorData)[1]) {
        ((f32 *)param_0->actorData)[1] = local_2[1];
        local_3 = 1;
    }
    if (((f32 *)param_0->actorData)[0] < local_1[0]) {
        ((f32 *)param_0->actorData)[0] = local_1[0];
        func_808008D8_chbanjoctrl(local_0, 1.0f, 0.0f);
    } else if (local_2[0] < ((f32 *)param_0->actorData)[0]) {
        ((f32 *)param_0->actorData)[0] = local_2[0];
        func_808008D8_chbanjoctrl(local_0, -1.0f, 0.0f);
    }
    if (((f32 *)param_0->actorData)[2] < local_1[2]) {
        ((f32 *)param_0->actorData)[2] = local_1[2];
        func_808008D8_chbanjoctrl(local_0, 0.0f, 1.0f);
    } else if (local_2[2] < ((f32 *)param_0->actorData)[2]) {
        ((f32 *)param_0->actorData)[2] = local_2[2];
        func_808008D8_chbanjoctrl(local_0, 0.0f, -1.0f);
    }
    if (func_800EEF24(local_0)) {
        local_3 = 1;
        if (func_800F6720(param_1)) {
            func_800EF368(local_0, 100.0f);
            func_800EFB24(local_4, param_0->actorData, local_0);
            func_800F7700(param_1, 10, local_4);
        }
    }
    if (local_3) func_800F8418(param_1, param_0->actorData);
}

s32 func_80800ADC_chbanjoctrl(s32 param_0) {
    s32 local_0;

    local_0 = func_800F54E4(param_0);
    func_80800824_chbanjoctrl(param_0, local_0);
    func_8080091C_chbanjoctrl(param_0, local_0);
}

void func_80800B18_chbanjoctrl(Actor *this)
{
    f32 r;
    s32 cam;
    f32 vec[3];
    f32 pad;
    f32 dx;
    f32 dz;

    r = this->unk74_7;
    cam = func_800F54E4();
    if (func_800F5410(cam) == 1) {
        return;
    }
    if (BOX[0] < this->position[0] - r || this->position[0] + r <= BOX[0]
        || BOX[1] < this->position[1] - r || this->position[1] + r - 100.0f <= BOX[1]
        || BOX[2] < this->position[2] - r || this->position[2] + r <= BOX[2]) {
        return;
    }
    func_800F7E3C(cam, 0);
    func_800EFA4C(vec, BOX[0], this->position[1] + r, BOX[2]);
    dx = this->position[0] + r - vec[0];
    if (r < dx) {
        dx -= r + r;
    }
    dz = this->position[2] + r - vec[2];
    if (r < dz) {
        dz -= r + r;
    }
    if (mlAbsF(dx) < mlAbsF(dz)) {
        vec[0] += dx;
    } else {
        vec[2] += dz;
    }
    func_800F7814(cam, vec);
}

void func_80800D04_chbanjoctrl(f32 *arg0)
{
  f32 temp_f0;
 do { temp_f0 = arg0[2]; if (temp_f0 < arg0[7]) { arg0[7] = temp_f0; func_800F8418(func_800F54E4(), arg0 + 6, arg0); } ; } while (0);
}

void func_80800D50_chbanjoctrl(Actor *param_0)
{
    if (func_800D90A4(&param_0->unk58) &&
        func_800F56AC(func_800F54E4()) == 0x19 &&
        !func_800F6DA0(func_800F54E4()) &&
        func_800F6C5C(func_800F54E4())) {
        if (func_800F7B9C(func_800F54E4(), 0x51) == 2) param_0->unk58 = 3.0f;
    }
}

void func_80800DF8_chbanjoctrl(this) Actor *this;
{
    f32 mind;
    f32 vec[3];
    f32 dist;
    f32 maxd;
    f32 yaw;
    s32 cam;
    s32 d;

    if (!func_8001210C(4)) {
        return;
    }
    cam = func_800F54E4();
    if (func_800F7058(cam) == 2) {
        return;
    }
    if (func_800F6590(cam) || func_800F7018(cam) || func_800F6DA0(cam) || func_800F6E40(cam)) {
        return;
    }
    if (func_800F56AC(cam) != 0x14) {
        return;
    }
    if (func_800F6AA4(cam) || func_800F55D0(cam)) {
        return;
    }
    if (!func_800F6478(cam) || !func_800F6438(cam) || !func_800F6C5C(cam)) {
        return;
    }
    maxd = mind = 0.0f;
    yaw = func_800F1DF4(D_808012F4_chbanjoctrl, this->actorData);
    for (d = 0; d != 600; d += 100) {
        dist = d + 3200.0f;
        func_800EEB9C(vec, yaw, dist);
        vec[1] = -3000.0f;
        if (func_800C696C(vec, 100.0f, -100.0f, 0, &vec[1])) {
            if (-3020.0f < vec[1] && vec[1] < -2980.0f) {
                maxd = dist;
                if (mind == 0.0f) {
                    mind = dist;
                }
            }
        }
    }
    func_800EEB9C(vec, yaw, (mind + maxd) * 0.5f);
    vec[1] = -3000.0f;
    func_800F7D90(func_800F54E4(), 0x52, vec, 1);
}

void func_8080102C_chbanjoctrl(param_0) Actor *param_0;
{
  if (param_0->unk64_20) {
    func_800FECB8(3);
    func_800FCAE0(0x4A, 0, 0x7D0);
    func_800FCA90(0x4A);
    *(u8 *)((u8 *)param_0 + 0x65) &= 0xFFEF;
  }
}

int func_80801088_chbanjoctrl(Actor *param_0)
{
    extern void func_800F4F34(s32, f32 *, f32, f32);
    s32 local_0;

    local_0 = func_800F54E4();
    if (func_800F6720(local_0)) {
        func_800F4F34(local_0, param_0->position, 0.0f, (f32)param_0->unk74_7);
    }
}

void func_808010FC_chbanjoctrl(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1;

    func_8008FE68(local_0);
    if (param_0->position[1] < local_0[1]) {
        if (!param_0->unk64_20) {
            func_800FEC60(3);
            param_0->unk64_20 = 1;
        }
        local_1 = func_800F10B4(local_0[1] - param_0->position[1], 0.0f, 2000.0f, 1.0f, 0.0f);
        func_800FEC1C(local_1);
        if (!func_800FCCD4(0x4A)) {
            func_800FC6B0(0x4A);
        }
        func_800FCAE0(0x4A, (s32)((1.0f - local_1) * 20000.0f), 2000);
    } else {
        func_8080102C_chbanjoctrl(param_0);
    }
}

s32 func_808011F4_chbanjoctrl(void){
    func_8080102C_chbanjoctrl();
}
