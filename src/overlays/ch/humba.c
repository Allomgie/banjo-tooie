#include "common.h"

extern s32 func_800EA05C(void);
extern void func_8008F8B0();
extern void func_8008F904();
extern void func_8008F938();
extern void func_8008F8D8();
extern void func_8008F990();
extern void func_800EE7F8();
extern s32 func_800F54E4(void);
extern void _capod_entrypoint_3(int);
extern int func_800DA298(int);
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct { s32 f0; s32 f4; u8 pad[0x6C]; u8 pad74:1; u8 flag:1; u8 rest:6; } FarmerState;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
extern s32 D_80802648_chhumba[];
extern s16 D_8080266E_chhumba[];
extern void func_8010D5DC(void);
extern void func_8008F9F8(f32 *, f32);
extern void func_8010D254(f32 *);
extern void func_800F1EA4(f32 *, f32 *);
extern f32 func_800F1F38(f32, f32, f32);
extern void func_800EFCD8(f32 *, f32, f32);
extern s32 func_800F20BC(f32, f32, f32);
extern f32 D_80802694_chhumba[];
extern void func_8008FB10(f32 *, f32, f32, f32);
extern f32 D_8080272C_chhumba[][3];
extern int D_80802738_chhumba;
extern void *D_80802780_chhumba;
extern s32 D_80802684_chhumba;
extern Actor *func_801084B0(s32, Actor **);
extern u8 *func_80103CB8(Actor *, s32);
extern s32 _gcdialogcamera_entrypoint_3(void *, f32);
typedef struct { u8 pad[0x17]; u8 rest:7; u8 flag:1; } HumbaBits17;
typedef union { u32 local_0; s16 local_1[2]; s32 s; } Mass64HumbaEvent;
extern s32 func_800F0064(f32 *, f32, f32 *);
extern s32 D_808026A0_chhumba[];
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern u8 D_80802590_chhumba[];
extern Vec3f D_808026F0_chhumba;
extern void func_800EF334(f32 *, f32);
extern void func_8008FE68(f32 *);
extern void func_800907C0(f32 *);
extern void func_8008FF40(f32 *);
extern void func_800906DC(f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 D_808026FC_chhumba[][3];
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800F7F50(s32, f32 *, f32 *, f32, s32, s32);
extern f32 func_800D8FF8(void);
extern s32 func_800902E4(f32 *, f32, s32, Actor **);
s32 func_8080071C_chhumba();
s32 func_80800A50_chhumba();
void func_80800E44_chhumba();
void func_808015DC_chhumba();
void func_80801DB0_chhumba();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_808015DC_chhumba(), func_808021F4_chhumba();
extern u8 D_808025A4_chhumba[];

int func_80800000_chhumba(s32 param_0[3], s32 param_1)
{
  _capod_entrypoint_2(param_0[0], 9, param_1 | 0);
}

void func_80800028_chhumba(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_0->unk74_7) {
        case 0: func_80800000_chhumba(param_0, 0);
        case 1:
        case 3:
            _capod_entrypoint_8(1);
            param_0->unk74_7 = 2;
            _gcdialogcamera_entrypoint_6(param_0->unk0);
            _gcdialogcamera_entrypoint_8();
            _capod_entrypoint_12(0);
        case 2:
            _capod_entrypoint_7(param_1, param_2);
            break;
    }
}

void func_808000D4_chhumba(Actor *param_0, s32 param_1, s32 param_2, Unk80132ED0 *param_3)
{
    switch (param_0->unk74_7) {
    case 0:
        func_80800000_chhumba(param_0, param_2);
    case 1:
    case 2:
        param_0->unk74_7 = 3;
    case 3:
        _capod_entrypoint_20(param_3, param_1, param_2);
        break;
    }
}

void func_8080015C_chhumba(Actor *param_0, s32 param_1, s32 param_2, Unk80132ED0 *param_3)
{
    switch (param_0->unk74_7) {
    case 0:
        func_80800000_chhumba(param_0, param_2);
    case 2:
    case 3:
        param_0->unk74_7 = 1;
    case 1:
        _capod_entrypoint_6(param_3, param_1, param_2);
        break;
    }
}

void func_808001E4_chhumba(void *param_0)
{
  if (func_800DA298(0x9C7) != 0) {
    if (((u32)(*(u16 *)((char *)param_0 + 0x76)) >> 7) != 0) {
      _capod_entrypoint_3(0);
      *(u16 *)((char *)param_0 + 0x76) = (*(u16 *)((char *)param_0 + 0x76)) & 0x7F;
    }
  }
}

void func_80800238_chhumba(u8 *param_0, f32 *param_1) {
    func_800EFA4C(param_1, 0.0f, *(f32 *)(param_0 + 0x38) * 5.0f * -50.0f, 0.0f);
}

int func_80800294_chhumba(s32 param_0, s32 param_1)
{
  if ((param_1 != 0) && func_800DA298(0x9C8))
  {
    func_800904C8(0x8D);
  }
  if (func_800EA05C() != 0x122)
  {
    if (param_1 != 0)
    {
      func_80090734(1, param_0 + 4);
      return;
    }
    if (func_800DA298(0x9C8) != 0)
    {
      func_80090708(0);
    }
  }
  else
  {
    if (func_800DA298(0x9C8) != 0)
    {
      func_80090658(param_1);
    }
  }
}

void func_80800338_chhumba(FarmerState *param_0, s32 param_1, s32 param_2) {
    param_2 |= 4;
    _subaddiedialog_entrypoint_11(param_0->f0, param_1, param_2, &param_0->f4, 0x40);
    param_0->flag = 1;
}

int func_80800384_chhumba(Actor *param_0)
{
  switch (func_800EA05C())
  {
    case 0x122 :
      return 0x13;

    default :
      return D_80802648_chhumba[((*(s32 *)((char *)param_0 + 0x6C)) & 0x1FF)];

  }

}

s32 func_808003CC_chhumba(u8 *param_0) {
    if (func_800EA05C() == 0x122) {
        return 0x11AA;
    }
    return D_8080266E_chhumba[*(s32 *)(param_0 + 0x6C) & 0x1FF];
}

int func_80800414_chhumba(Actor *param_0)
{
    s32 local_0;
    local_0 = func_800EA05C();
    if (local_0 == 0x122) {
        return 0x346;
    }
    return (*(s32 *)((char *)param_0 + 0x6C) & 0x1FF) + 0x346;
}

void func_80801F74_chhumba();

s32 func_80800450_chhumba(Actor *param_0, s32 param_1, Mass64HumbaEvent param_2)
{
    Actor *local_0;
    f32 local_1[3];
    u8 *local_2;

    switch (param_1) {
    case 0x49:
        func_80801F74_chhumba(param_0);
        break;
    case 0xA1:
        switch (param_0->unk70_10) {
        case 10:
            func_80800E44_chhumba(param_0, 11);
            break;
        case 15:
            func_80800E44_chhumba(param_0, 16);
            break;
        }
        break;
    case 0x3D:
        func_80800238_chhumba(param_0, local_1);
        local_0 = func_801084B0(0x29F, &param_0);
        func_800EE7F8((f32 *)local_0->actorData, local_1);
        func_8010D254(local_0->position);
        local_0->unk74_30 = 1;
        param_0->unk3C = local_0->unk0;
        func_80800E44_chhumba(param_0, 6);
        break;
    case 0x2E:
        func_80801DB0_chhumba(param_0, param_2.local_1[0], param_2.local_1[1]);
        break;
    case 0x2F:
        if (param_2.local_1[1] == 1) {
            func_80090708(0);
            func_80090708(1);
        }
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80802684_chhumba, param_0->scale);
        break;
    case 0x57:
        if (_gcdialogcamera_entrypoint_0(param_2.s & 0xFFFF, (param_2.local_0 & 0xFFFF0000) >> 16)) {
            if (param_0->unk74_7 != 2) {
                func_80800028_chhumba(param_0, 2, 1);
            }
            return 2;
        }
        return 1;
    case 0x32:
        switch (param_0->unk70_10) {
        case 17:
            func_80800338_chhumba(param_0, 0x11AF, 0xF);
            break;
        case 18:
            func_80800E44_chhumba(param_0, 18);
            break;
        default:
            func_800904C8(0x8D);
            if (param_0->unk74_29) {
                func_80800338_chhumba(param_0, 0x11BD, 0xF);
            } else {
                func_80800338_chhumba(param_0, 0x11A4, 0xF);
            }
            break;
        }
        break;
    case 0x1F:
        func_801015D0(param_0);
        local_2 = func_80103CB8(param_0, func_801039E4(param_0->unk0));
        ((HumbaBits17 *)local_2)->flag = 1;
        func_800DF744(3, 0);
        func_800DF744(5, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_8080071C_chhumba(param_0) s32 param_0; {
    s32 local_0;

    local_0 = func_800EA05C();
    switch (local_0) {
    case 0xB6:
        return 1;
    case 0xD5:
        return 3;
    case 0xE9:
        return 2;
    case 0x11E:
    case 0x122:
        return 5;
    case 0x120:
        return 4;
    case 0x11F:
        return 6;
    case 0x135:
        return 7;
    case 0x140:
        return 8;
    case 0x157:
        return 9;
    default:
        return 0;
    }
}

s32 func_808007EC_chhumba(s32 param_0){
    return 1;
}

void func_808007F8_chhumba(Actor *param_0)
{
    func_800DA544(param_0->unk6C_0 + 0xD5);
    if (param_0->unk74_29) {
        func_800D175C(0x54, -func_808007EC_chhumba(param_0));
    } else {
        func_800D175C(0x48, -func_808007EC_chhumba(param_0));
    }
    param_0->unk64_20 = 1;
}

int func_80800878_chhumba(Actor *param_0)
{
  return func_800DA298(((*(s32 *)((char *)param_0 + 0x6C)) & 0x1FF) + 0xD5);
}

s32 func_808008A0_chhumba(Actor *param_0)
{
    f32 local_0[3];
    Actor *local_1;
    f32 local_2;

    local_1 = func_80106790(param_0->unk3C);
    func_80800238_chhumba(param_0, local_0);
    local_2 = param_0->scale;
    if (local_1->position[1] < -202.5f * local_2 &&
        func_800F0064(local_1->position, local_2 * 1550.0f, local_0)) {
        return 1;
    }
    return 0;
}

s32 func_80800934_chhumba(Actor *param_0, s32 param_1)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4[3];
    local_0 = param_0->scale * 500.0f;
    local_1 = param_0->scale * -500.0f;
    local_2 = param_0->scale * 1900.0f;
    local_3 = param_0->scale * 2950.0f;
    func_8010D254(local_4);
    if (local_4[0] < local_1 || local_4[0] > local_0) return 0;
    if (local_4[2] < local_2 || local_4[2] > local_3) return 0;
    if (!func_8008FA60(param_1, 6)) return 0;
    if (func_80090080()) {
        if (func_80016B30(0, 1)) return 1;
        func_800F5FE0(func_800F54E4());
    }
    return 0;
}

s32 func_80800A50_chhumba(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];

    func_80800238_chhumba(param_0, local_0);
    local_0[1] = 0.0f;
    func_8010D254(local_1);
    if (!func_8010C9FC(local_0, (s32)(param_0->scale * 1550.0f), (s32)(param_0->scale * -202.5f), (s32)(param_0->scale * -1237.5f))) {
        return 0;
    }
    if (!func_800F71D4(func_800F54E4())) {
        return 0;
    }
    if (func_800EA05C() == 0x120 && -100.0f < local_1[1]) {
        return 0;
    }
    return 1;
}

void func_80800B40_chhumba(Actor *param_0)
{
    func_8080015C_chhumba(param_0, 0, 0x60, 0);
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(func_8010D5DC, param_0->unk0);
    func_8008F9F8((f32 *)&param_0->actorData[4], 200.0f);
}

void func_80800BA8_chhumba(Actor *param_0, f32 *param_1)
{
    f32 local_0;
    f32 local_1[3];
    func_8010D254(local_1);
    func_800F1EA4(local_1, &local_0);
    func_800EFCD8(param_1, func_800F1F38(local_0, 0.0f, 10.0f), param_0->scale * 2000.0f);
    param_1[1] = local_1[1];
}

s32 func_80800C20_chhumba(s32 param_0) {
    f32 local_1;
    f32 local_0[3];
    func_8010D254(local_0);
    func_800F1EA4(local_0, &local_1);
    if (func_800F20BC(0.0f, local_1, 5.0f) == 0) {
        return 1;
    }
    return 0;
}

s32 func_80800C6C_chhumba(f32 param_0[3]) {
    f32 local_0[3];

    func_80800BA8_chhumba(param_0, local_0);
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *(s32 *)param_0);
    func_8008F990(local_0, 0x43960000);
}

void func_80800CC8_chhumba(Actor *param_0)
{
    func_8008FB10(D_80802694_chhumba, param_0->scale * 1600.0f, param_0->scale * 72.0f, param_0->scale * 350.0f);
}

s32 func_80800D2C_chhumba(s32 param_0){
    if(func_800DA9E4(0xE2, 1) == 0){
        func_80800338_chhumba(param_0, 0x11B5, 0xF);
        return 1;
    }
    return 0;
}

void func_80800D74_chhumba(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    f32 local_2[3];

    if (func_800DC0C0() < 0.1f) {
        local_0 = func_800DC128(1, 3);
        local_1 = func_800B53A4(local_0);
        func_800EEB9C(local_2, func_800DC178(0.0f, 360.0f), func_800DC178(0.0f, 1000.0f) * param_0->scale);
        local_2[1] = -50.0f;
        func_800BABB8(local_1, local_2, NULL, 1.0f, D_808026A0_chhumba);
        func_800BA22C(local_1, local_0);
    }
}

void func_80800E44_chhumba(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0[3];
    Actor *local_1;
    f32 local_2[3];

    switch (param_0->unk70_10) {
    case 2:
        break;
    case 3:
        func_80800294_chhumba(param_0, 0);
        break;
    case 5:
    case 6:
        func_80800238_chhumba(param_0, local_0);
        func_80090658(0);
        _fxsplash_entrypoint_1(local_0);
        _fxsplash25d_entrypoint_0(local_0);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80802590_chhumba);
        func_808007F8_chhumba(param_0);
        func_800FC660(0xE);
        func_80800338_chhumba(param_0, 0x11B4, 0xF);
        break;
    }
    func_80101FDC(param_0, param_1);
    switch (param_0->unk70_10) {
    case 2:
        func_80800B40_chhumba(param_0);
        return;
    case 3:
        func_80800028_chhumba(param_0, 3, 1);
        func_80800294_chhumba(param_0, 1);
        return;
    case 18:
        if (func_80800C20_chhumba(param_0)) {
            func_80800C6C_chhumba(param_0);
            return;
        }
        func_80800E44_chhumba(param_0, 4);
        return;
    case 4:
        func_80090658(1);
        return;
    case 5:
        func_80800238_chhumba(param_0, local_2);
        func_80090768(local_2);
        param_0->unk3C = (Unk80132ED0 *)func_8008FDEC();
        local_1 = (Actor *)func_80106790(param_0->unk3C);
        func_800EE7F8((f32 *)local_1->actorData, local_2);
        local_1->unk74_30 = 1;
        func_808000D4_chhumba(param_0, 0xE, 9, param_0->unk3C);
        return;
    case 6:
        func_808000D4_chhumba(param_0, 0xE, 9, param_0->unk3C);
        return;
    case 8:
        func_80090658(1);
        func_8080015C_chhumba(param_0, 2, 0x60, 0);
        return;
    case 9:
        param_0->unk58 = 4.0f;
        func_800FC6B0(0xC);
        if (param_0->unk74_29 && !func_8009EA2C()) {
            func_8009EAAC(1);
            func_800907EC(func_8008FD48());
            return;
        }
        func_800907EC(func_80800384_chhumba(param_0));
        return;
    case 11:
        func_80090658(0);
        if (!func_800DA9E4(func_80800414_chhumba(param_0), 1)) {
            if (param_0->unk74_29) {
                func_80090708(2);
                func_80800338_chhumba(param_0, func_808003CC_chhumba(param_0), 3);
                return;
            }
            func_80800338_chhumba(param_0, func_808003CC_chhumba(param_0), 0xB);
            return;
        }
        if (!func_80800D2C_chhumba(param_0)) {
            func_808001E4_chhumba(param_0);
            func_80800E44_chhumba(param_0, 0xC);
            return;
        }
        break;
    case 13:
        func_80090658(1);
        func_8080015C_chhumba(param_0, 5, 0x60, 0);
        return;
    case 14:
        param_0->unk58 = 4.0f;
        func_800FC6B0(0xC);
        if (param_0->unk74_29 && func_8009EA2C()) {
            func_8009EAAC(0);
            func_800907EC(func_8008FD48());
            return;
        }
        func_800907EC(1);
        return;
    case 16:
        func_80090658(0);
        if (!func_800DA9E4(0x1D1, 1)) {
            func_80800338_chhumba(param_0, 0x11B6, 0xF);
            return;
        }
        func_808001E4_chhumba(param_0);
        func_80800E44_chhumba(param_0, 7);
        return;
    case 17:
        if (!func_800DA9E4(0x505, 1)) {
            func_80800B40_chhumba(param_0);
        }
        break;
    }
}

void func_80801260_chhumba(Actor *param_0)
{
    Vec3f local_0 = D_808026F0_chhumba;
    s32 local_2;
    f32 local_1[3];

    func_800EF334(local_0.f, param_0->scale);
    func_8008FE68(local_1);
    for (local_2 = 0; local_2 < 3; local_2++) {
        local_1[local_2] += (local_0.f[local_2] - local_1[local_2]) * 0.05f;
    }
    func_800907C0(local_1);
    func_8008FF40(local_1);
    local_1[1] += func_800F1DCC(180.0f, local_1[1]) * 0.05f;
    local_1[0] += func_800F1DCC(0.0f, local_1[0]) * 0.05f;
    local_1[2] += func_800F1DCC(0.0f, local_1[2]) * 0.05f;
    func_800906DC(local_1);
}

void func_8080138C_chhumba(Actor *param_0)
{
  s32 local_0;

  if (func_80800A50_chhumba(param_0) == 0 || func_80090270() != 0) {
    return;
  }
    local_0 = func_8008FD48();
    if ((local_0 == 1) && ((func_8009EA2C() == 0) || !param_0->unk74_29)) {
      func_80800E44_chhumba(param_0, 8);
    } else if ((func_80800384_chhumba(param_0) == local_0) || ((func_8009EA2C() != 0) && param_0->unk74_29)) {
      func_80800E44_chhumba(param_0, 0xD);
    }
}

void func_8080144C_chhumba(f32 param_0)
{
    f32 (*local_7)[3];
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4[3];
    f32 local_5;
    f32 local_6;

    func_8010D254(local_1);
    local_3 = (param_0 <= 1.0f) ? 60.0f : 100.0f;
    local_5 = 610.0f * param_0;
    local_6 = (local_3 + 25.0f) * (local_3 + 25.0f);
    local_7 = D_808026FC_chhumba;
    do {
        func_800EFA20(local_0, *local_7, param_0);
        func_800EE7F8(local_2, local_0);
        local_2[1] = local_5;
        func_800EFB24(local_4, local_0, local_1);
        if (local_4[0] * local_4[0] + local_4[2] * local_4[2] < local_6 && local_0[1] < local_1[1] && local_1[1] <= local_2[1]) {
            func_800F7F50(func_800F54E4(), local_0, local_2, local_3, 2, 1);
        }
        local_7++;
    } while (local_7 != D_8080272C_chhumba);
}

void func_808015DC_chhumba(param_0) Actor *param_0;
{
    extern void _chglowbo_entrypoint_4(void);

    f32 local_1[3];
    f32 local_4[3];
    s32 local_2;
    s32 local_3;
    s32 local_5;

    _suexpression_entrypoint_10(
        func_80100094(param_0, 1),
        *(s32 *)((char *)param_0 + 0),
        0
    );

    func_8080144C_chhumba(
        *(f32 *)((char *)param_0 + 0x38) * 5.0f
    );

    if (func_800C0638()) {
        *(f32 *)((char *)param_0 + 0x24) = 1.5f;
    } else if (*(f32 *)((char *)param_0 + 0x24) > 0.0f) {
        *(f32 *)((char *)param_0 + 0x24) -=
            func_800D8FF8();
    }

    if (func_80800878_chhumba(param_0)) {
        func_80800D74_chhumba(param_0);
    } else if (*(f32 *)((char *)param_0 + 0x24) <= 0.0f) {
        if (param_0->unk74_29) {
            func_800D1824(0x54);
        } else {
            func_800D1824(0x48);
        }
    }

    func_8008FB10(
        (char *)param_0 + 4,
        *(f32 *)((char *)param_0 + 0x38) * 1350.0f,
        *(f32 *)((char *)param_0 + 0x38) * 72.0f,
        *(f32 *)((char *)param_0 + 0x38) * 350.0f
    );

    if (func_80090178(0x10000)) {
        return;
    }

    switch (param_0->unk70_10) {
        case 1:
            if (func_800EA05C() == 0x120) {
                func_8010D254(local_1);

                if (local_1[1] > -30.0f) {
                    if (func_80090178(0x6C8E3)) {
                        if (_subaddiedialog_entrypoint_6(
                                (char *)param_0 + 4,
                                (s32)*(f32 *)((char *)param_0 + 0x48),
                                0x15E,
                                0x32,
                                6)) {
                            func_80800E44_chhumba(param_0, 3);
                        }
                    }
                }

                if (func_80800934_chhumba(param_0, 0x6C8E3)) {
                    func_80800E44_chhumba(param_0, 3);
                }
            } else {
                if (func_80090178(0x6C8E3)) {
                    if (_subaddiedialog_entrypoint_6(
                            (char *)param_0 + 4,
                            (s32)*(f32 *)((char *)param_0 + 0x48),
                            0x15E,
                            0x32,
                            0)) {
                        func_80800E44_chhumba(param_0, 3);
                    }
                }

                if (func_80800934_chhumba(param_0, 0x6C8E3)) {
                    func_80800E44_chhumba(param_0, 3);
                }
            }
            break;

        case 3:
            if (!param_0->unk74_30) {
                if (param_0->unk74_29) {
                    local_5 = func_800D1A04(0x54);
                    local_3 = func_808007EC_chhumba(param_0);
                    if (local_5 >= local_3) {
                        func_80800338_chhumba(
                            param_0,
                            0x11BE,
                            0x4E
                        );
                    } else {
                        func_80800338_chhumba(
                            param_0,
                            0x11BF,
                            0xF
                        );
                    }
                } else {
                    local_5 = func_800D1A04(0x48);
                    local_3 = func_808007EC_chhumba(param_0);
                    if (local_5 >= local_3) {
                        func_80800338_chhumba(
                            param_0,
                            0x11B0,
                            0x4E
                        );
                    } else {
                        func_80800338_chhumba(
                            param_0,
                            0x11B3,
                            0xF
                        );
                    }
                }
            }
            break;

        case 18:
            func_80800BA8_chhumba(param_0, local_4);
            func_8008F964(local_4);
            func_80800CC8_chhumba(param_0);
            break;

        case 4:
            if (func_800EA05C() == 0x120) {
                func_80108B04(param_0, 0);
            } else {
                if (param_0->unk74_29) {
                    local_2 = 0x523;
                } else {
                    local_2 = 0x29F;
                }

                if (func_800902E4(
                        (char *)param_0 + 4,
                        2500.0f,
                        local_2,
                        &param_0)) {
                    if (func_8008FE14() == local_2) {
                        if (func_80090818()) {
                            func_80800E44_chhumba(param_0, 5);
                        }
                    }
                }
            }
            break;

        case 5:
        case 6:
            if (func_808008A0_chhumba(param_0)) {
                func_80800E44_chhumba(param_0, 7);
            }
            break;

        case 7:
            if ((func_80090178(0x6C8E3) &&
                 _subaddiedialog_entrypoint_6(
                        (char *)param_0 + 4,
                        (s32)*(f32 *)((char *)param_0 + 0x48),
                        0x15E,
                        0x32,
                        6)) || func_80800934_chhumba(param_0, 0x6C8E3)) {
                func_80800338_chhumba(
                    param_0,
                    0x11B8,
                    0xF
                );
            } else {
                func_8080138C_chhumba(param_0);
            }
            break;

        case 8:
            func_80800E44_chhumba(param_0, 9);
            break;

        case 9:
            if (*(f32 *)((char *)param_0 + 0x58) > 0.0f) {
                *(f32 *)((char *)param_0 + 0x58) -=
                    func_800D8FF8();

                if (param_0->unk64_20 &&
                    *(f32 *)((char *)param_0 + 0x58) < 1.5f) {
                    _chbaddiesetup_entrypoint_0(
                        _chglowbo_entrypoint_4
                    );

                    param_0->unk64_20 = 0;
                }
            } else if (func_800903D0(
                           (char *)param_0 + 0x28)) {
                func_800904F4(
                    0x89,
                    *(s32 *)((char *)param_0 + 0)
                );

                func_80800E44_chhumba(param_0, 0xA);
            }

            func_80801260_chhumba(param_0);
            break;

        case 12:
            if ((func_80090178(0x6C8E3) &&
                 _subaddiedialog_entrypoint_6(
                        (char *)param_0 + 4,
                        (s32)*(f32 *)((char *)param_0 + 0x48),
                        0x15E,
                        0x32,
                        0)) || func_80800934_chhumba(param_0, 0x6C8E3)) {
                func_80800338_chhumba(
                    param_0,
                    0x11B9,
                    0xF
                );
            } else {
                func_8080138C_chhumba(param_0);
            }
            break;

        case 13:
            func_80800E44_chhumba(param_0, 0xE);
            break;

        case 14:
            if (*(f32 *)((char *)param_0 + 0x58) > 0.0f) {
                *(f32 *)((char *)param_0 + 0x58) -=
                    func_800D8FF8();
            } else if (func_800903D0(
                           (char *)param_0 + 0x28)) {
                func_800904F4(
                    0x89,
                    *(s32 *)((char *)param_0 + 0)
                );

                func_80800E44_chhumba(param_0, 0xF);
            }

            func_80801260_chhumba(param_0);
            break;

        case 17:
            if (_subaddiedialog_entrypoint_6(
                    (char *)param_0 + 4,
                    (s32)*(f32 *)((char *)param_0 + 0x48),
                    0x15E,
                    0x32,
                    0) ||
                func_80800934_chhumba(param_0, 0x600)) {
                func_80800338_chhumba(
                    param_0,
                    0x11BC,
                    0xF
                );
            } else if (!param_0->unk64_19) {
                if (func_80800A50_chhumba(param_0)) {
                    param_0->unk64_19 = 1;

                    func_80800338_chhumba(
                        param_0,
                        0x11BA,
                        0xF
                    );
                }
            }
            break;

        case 19:
            if (_subaddiedialog_entrypoint_6(
                    (char *)param_0 + 4,
                    (s32)*(f32 *)((char *)param_0 + 0x48),
                    0x15E,
                    0x32,
                    0) ||
                func_80800934_chhumba(param_0, 0x600)) {
                func_80800338_chhumba(
                    param_0,
                    func_80090178(0x200) ? 0x121C : 0x121D,
                    0xF
                );
            } else if (!param_0->unk64_19) {
                if (func_80800A50_chhumba(param_0)) {
                    param_0->unk64_19 = 1;

                    func_80800338_chhumba(
                        param_0,
                        0x11BB,
                        0xF
                    );
                }
            }
            break;
    }
}

void func_80801DB0_chhumba(param_0, param_1, param_2) Actor *param_0; u32 param_1; s32 param_2;
{

  *((u8 *) (((char *) param_0) + 0x74)) = (u8) ((*((u8 *) (((char *) param_0) + 0x74))) & 0xFFBF);
  switch (param_1)
  {
    case 0x11AF:
      func_808001E4_chhumba(param_0);
      return;

    case 0x11A4:
      ;
      ;
      ;

    case 0x11BD:
      func_80800E44_chhumba(param_0, 3);
      return;

    case 0x11A5:
      ;
      ;
      ;

    case 0x11A6:

    case 0x11A7:
      ;
      ;
      ;

    case 0x11A8:

    case 0x11A9:
      ;
      ;
      ;

    case 0x11AA:

    case 0x11AB:
      ;
      ;
      ;

    case 0x11AC:

    case 0x11AD:
      ;
      ;
      ;

    case 0x11AE:

    case 0x11B7:
      ;
      if (func_80800D2C_chhumba(param_0) == 0)
    {
      func_800C0850();
      func_808001E4_chhumba(param_0);
      func_80800E44_chhumba(param_0, 0xC);
    }
      if (param_1 == 0x11B7)
    {
      func_80090708(0);
      return;
    }

    default:
      return;

    case 0x11B0:
      ;
      ;
      ;

    case 0x11BE:
      if (param_2 != 0)
    {
      func_80800338_chhumba(param_0, 0x11B1, 0xF);
      return;
    }
      func_80800338_chhumba(param_0, 0x11B2, 0xF);
      return;

    case 0x11B2:
      func_808001E4_chhumba(param_0);
      func_800EE7F8((s32 *) (((char *) param_0) + 0x18), (s32 *) (((char *) param_0) + 0x4));
      func_80800E44_chhumba(param_0, 1);
      return;

    case 0x11B1:
      if (func_80800C20_chhumba(param_0) != 0)
    {
      func_808001E4_chhumba(param_0);
    }
      func_808000D4_chhumba(param_0, 0xE, 0x40, 0);
      func_80800E44_chhumba(param_0, 0x12);
      return;

    case 0x11B3:
      ;
      ;
      ;

    case 0x11BF:
      func_808001E4_chhumba(param_0);
      func_80800E44_chhumba(param_0, 1);
      return;

    case 0x11B5:
      func_808001E4_chhumba(param_0);
      func_80800E44_chhumba(param_0, 0xC);
      return;

    case 0x11B4:
      func_808001E4_chhumba(param_0);
      return;

    case 0x11B6:
      func_808001E4_chhumba(param_0);
      func_80800E44_chhumba(param_0, 7);
      break;

  }

}

void func_80801F74_chhumba(Actor *param_0)
{
    extern void _suexpression_entrypoint_12(void *, f32, f32);
    s32 local_0;
    s32 local_1;
    local_0 = _gccubesearch_entrypoint_1(0x226, param_0->position);
    local_1 = func_800EA05C();
    param_0->unk74_7 = 0;
    if (!local_0) {
        func_800FFAB0(param_0);
        return;
    }
    _gspropctrl_entrypoint_11(local_0, (u8 *)param_0 + 0x28);
    param_0->unk6C_0 = func_8080071C_chhumba(param_0);
    _suexpression_entrypoint_7(param_0, 1, 0x40);
    _suexpression_entrypoint_12((void *)func_80100094(param_0, 1), 0.0f, 0.0f);
    switch (local_1) {
    case 0x135:
        func_800BF744(1, 1);
        break;
    case 0x120:
        func_800BF744(2, 1);
        break;
    case 0x157:
        param_0->unk74_29 = 1;
        break;
    }
    if (local_1 != 0x135) {
        func_80108474(0x381, D_8080272C_chhumba, 0);
    }
    if (_glcutDll_entrypoint_20()) {
        func_80800E44_chhumba(param_0, 0x14);
        return;
    }
    switch (func_8008FD70()) {
    case 0x1000:
        func_80800E44_chhumba(param_0, 0x11);
        return;
    case 0x200:
    case 0x400:
        func_80800E44_chhumba(param_0, 0x13);
        return;
    case 0x10000:
        return;
    default:
        if (param_0->unk74_29 && !func_800DA9E4(0x55, 1)) {
            func_80800E44_chhumba(param_0, 2);
            return;
        }
        if (!param_0->unk74_29 && !func_800DA9E4(0x8F, 1)) {
            func_80800E44_chhumba(param_0, 2);
            return;
        }
        if (func_80800878_chhumba(param_0)) {
            if (func_8008FD48() == 1 && (!func_8009EA2C() || !param_0->unk74_29)) {
                func_80800E44_chhumba(param_0, 7);
                return;
            }
            func_80800E44_chhumba(param_0, 0xC);
            return;
        }
        func_80800E44_chhumba(param_0, 1);
        break;
    }
}

void func_808021F4_chhumba(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
int chhumba_entrypoint_0()
{
    return (int)&D_80802738_chhumba;
}

void func_80802234_chhumba(void *param_0)
{
    s32 local_0 = func_800EA05C();
    if (local_0 == 0x122) {
        *(float *)((char *)param_0 + 0x38) = 2.0f;
    } else {
        *(float *)((char *)param_0 + 0x38) = 1.0f;
    }
}

int chhumba_entrypoint_1()
{
  return &D_80802780_chhumba;
}
