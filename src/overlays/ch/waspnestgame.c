#include "common.h"

extern void *D_80801F80_chwaspnestgame;
extern void *D_80801FC8_chwaspnestgame;
extern void func_800CE8D8(s32, f32, s32);
typedef struct { f32 positions[2][3]; f32 timers[2]; u8 pad_0[0x1C]; f32 nests[3][3]; } WaspNestGameState;
extern void func_800EE7F8(f32 *, f32 *);
typedef struct { u8 pad_0[0x20]; u8 local_0[2]; u8 pad_1[2]; u8 local_1[1]; } WaspNestReset1302;
extern s16 D_80801F76_chwaspnestgame[];
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80103140();
extern u16 D_80801F70_chwaspnestgame[];
extern void func_8008FE68(f32 *);
extern f32 func_80090010(void);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800EF368(f32 *, f32);
extern u8 unk24[];
extern u8 unk34[];
extern u8 *func_80106790(s32);
extern void func_8010D600(f32 *);
extern f32 func_80102D78();
extern void func_80102BF8(u8 *, f32, f32, f32);
extern void func_800EF334(s32, f32);
extern f32 func_800D8FF8(void);
extern u8 D_80802044_chwaspnestgame[];
extern u8 D_80802068_chwaspnestgame[];
extern f32 func_800EEF94(f32 *);
extern int func_800BABB8(s32, f32 *, s32, f32, void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct { u8 pad[0x72]; u16 f72:6; u16 pad72:10; } WaspState;
extern void func_8010DCB4(s32);
extern u8 D_8080207C_chwaspnestgame[];
typedef struct { f32 position[2][3]; f32 distance[2]; } WaspNestClosest32;
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct { f32 pos[2][3]; f32 timer[2]; u8 sfx[2]; u8 pad22[2]; u8 unk24[1]; } WaspNestLocal;
extern u8 D_80802010_chwaspnestgame[];
extern void *func_80100094(Actor *, s32);
extern u8 func_800C4350(s32, f32 *, void *);
extern void func_800C3224(s32, f32, f32, f32);
extern void func_800D24E8(s32, s32, s32);
extern s32 func_800DC298(f32);
extern f32 func_800DC0C0(void);
extern void func_80108B04(Actor *, s32);
extern s32 func_800CEAD0(s32);
extern s32 func_800D0A9C(s32, s32);
extern s32 func_800D0B68(s32, s32);
extern s32 func_800D90A4(f32 *);
extern void func_80090708(s32);
extern void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, s32, s32);
extern void func_80101FDC(Actor *, s32);
extern void func_800EE7B4(f32 *, f32 *, f32 *, f32);
extern s32 func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
extern u8 D_80802024_chwaspnestgame[];
extern u8 D_80802038_chwaspnestgame[];
extern void func_800C4AF0(f32 *, void *);
void func_80800B80_chwaspnestgame();
void func_80800D7C_chwaspnestgame();
s32 func_80800DE4_chwaspnestgame();
void func_80800C7C_chwaspnestgame();
s32 func_80800EB8_chwaspnestgame();
void func_80800F98_chwaspnestgame();
void func_80801364_chwaspnestgame();

void *chwaspnestgame_entrypoint_0()
{
    return &D_80801F80_chwaspnestgame;
}

void *chwaspnestgame_entrypoint_1()
{
    return &D_80801FC8_chwaspnestgame;
}

void func_80800018_chwaspnestgame(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_1;
    s32 local_6;
    s32 local_2;
    s32 local_3;
    s32 local_5;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 2:
        func_800DA524(0);
        _susubgame_entrypoint_4(param_0, local_0 + 0x24);
        func_800DA544(0x6E6);
        _gcfrontend_entrypoint_9(0x73);
        func_800FDC28(12);
        func_80090708(0);
        param_0->actorData[7] = 0;
        param_0->actorData[3] = 0;
        func_800CE8D8(0, 60.0f, 60);
        func_800CE88C(0, 1);
        func_800D2770(0xF5, 0);
        break;
    case 3:
        local_3 = func_800D2054(0, 0x87, param_0->actorData[3]);
        func_80090708(2);
        _susubgame_entrypoint_5(param_0, local_0 + 0x24, 5, 1, 0);
        func_80101180(0x1E4, 0x45, 0);
        if (func_800D395C()) {
            if (local_3 == 1) {
                local_1 = 0x144E;
                local_2 = 0x16;
            } else if (local_3 == 0) {
                local_1 = 0x144F;
                local_2 = 0x17;
            } else {
                local_1 = 0x1450;
                local_2 = 0x17;
            }
        } else if (!func_800D0A9C(0x18, 4) && (s32)param_0->actorData[3] >= 40) {
            local_1 = 0x140A;
            local_2 = 0x16;
        } else if (!func_800D0A9C(0x4B, 1) && (s32)param_0->actorData[3] >= 50) {
            local_1 = 0x140C;
            local_2 = 0x16;
        } else {
            local_4 = func_800D0A9C(0x4B, 1) == 0;
            local_6 = func_800D0A9C(0x18, 4) == 0;
            if (local_6 + local_4) {
                local_5 = param_0->actorData[3];
                switch (local_5) {
                case 0:
                    local_1 = 0x1410;
                    break;
                case 1:
                    local_1 = 0x144C;
                    break;
                default:
                    local_1 = 0x140E;
                    break;
                }
                local_2 = 0x17;
            } else if (local_3 == 1) {
                local_1 = 0x140D;
                local_2 = 0x16;
            } else {
                local_1 = param_0->actorData[3] ? 0x140F : 0x1410;
                local_2 = 0x17;
            }
        }
        func_800FDC28(0);
        func_800FC6B0(local_2);
        _subaddiedialog_entrypoint_11(param_0->unk0, local_1, 6, 0, 0x99);
        break;
    case 5:
        func_80090708(0);
        _susubgame_entrypoint_4(param_0, local_0 + 0x24);
        param_0->unk58 = 0.5f;
        break;
    }
    func_80101FDC(param_0, param_1);
}

void func_808002EC_chwaspnestgame(Actor *param_0)
{
    WaspNestGameState *local_1;
    s32 local_2;
    f32 local_0[6];
    local_1 = (WaspNestGameState *)func_80100094(param_0, 0);
    _subaddiemarker_entrypoint_0(param_0, 0x201, local_0, 1);
    func_800EE7F8((f32 *)param_0->actorData, local_0);
    for (local_2 = 0; local_2 < 2; local_2++) {
        func_800EFD24(local_1->positions[local_2]);
        local_1->timers[local_2] = -1.0f;
    }
    for (local_2 = 0; local_2 < 3; local_2++) {
        _subaddiemarker_entrypoint_1(param_0, 0x1C0, local_2 + 0x33, local_0, 1);
        func_800EE7F8(local_1->nests[local_2], local_0);
    }
    _susubgame_entrypoint_0(param_0, (u8 *)local_1 + 0x24, 0);
    _susubgame_entrypoint_11(0);
}

void func_80800400_chwaspnestgame(Actor *param_0)
{
    WaspNestReset1302 *local_0;
    s32 local_2;

    local_0 = (WaspNestReset1302 *)func_80100094(param_0, 0);
    for (local_2 = 0; local_2 < 2; local_2++) {
        local_0->local_0[local_2] = 0;
    }
    _susubgame_entrypoint_11(0);
    if (_susubgame_entrypoint_2(param_0, local_0->local_1)) {
        _susubgame_entrypoint_4(param_0, local_0->local_1);
    }
    func_800FDC28(0xC);
}

void func_8080047C_chwaspnestgame(Actor *this)
{
    WaspNestLocal *local;
    u32 i;
    s32 n;
    f32 r;
    WaspNestLocal *local2;

    local = func_80100094(this, 0);
    for (i = 0; i < 2; i++) {
        if (0.0f < local->timer[i]) {
            if (local->sfx[i] == 0) {
                local->sfx[i] = func_800C4350(0, local->pos[i], D_80802010_chwaspnestgame);
            }
            if (this->unk70_10 == 2) {
                func_800C3224(local->sfx[i], 1.0f, 1.1f, 0.05f);
            } else {
                func_800C3224(local->sfx[i], 0.8f, 0.9f, 0.05f);
            }
            func_800C4350(local->sfx[i], local->pos[i], 0);
            local->timer[i] = -1.0f;
        }
    }
    switch (this->unk70_10) {
    case 1:
        break;
    case 2:
        func_800D24E8(0xF5, this->actorData[3], 0);
        if ((s32)this->actorData[7] < 10 && func_800DC298(0.09999084473f)) {
            n = 1;
            r = func_800DC0C0();
            if (r < 0.1666665971f) {
                n = 3;
            } else if (r < 0.5f) {
                n = 2;
            }
            func_80108B04(this, n);
        }
        if (func_800CEAD0(0)) {
            func_80800018_chwaspnestgame(this, 3);
        }
        break;
    case 5:
        if ((func_800D0A9C(0x4B, 1) && !func_800D0B68(0x4B, 1)) || (func_800D0A9C(0x18, 4) && !func_800D0B68(0x18, 4))) {
            break;
        }
        if (func_800D90A4(&this->unk58)) {
            local2 = func_80100094(this, 0);
            func_80090708(2);
            _susubgame_entrypoint_5(this, local2->unk24, 5, 1, 0);
            _subaddiedialog_entrypoint_11(this->unk0, 0xCEB, 0x46, 0, 0x99);
            func_80101FDC(this, 3);
        }
        break;
    }
}

s32 func_80800724_chwaspnestgame(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = (u8 *)func_80100094(param_0, 0);
    switch (param_1) {
    case 0x95:
        if ((func_800D0A9C(0x4B, 1) && !func_800D0B68(0x4B, 1)) ||
            (func_800D0A9C(0x18, 4) && !func_800D0B68(0x18, 4))) {
            param_0->unk58 = 0.5f;
            func_80101FDC(param_0, 5);
        } else {
            func_80090708(2);
            if (func_800D395C()) {
                _susubgame_entrypoint_5(param_0, local_0 + 0x24, 5, 1, 0);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x144D, 6, 0, 0x99);
            } else if (func_800DA298(0x6E6)) {
                _susubgame_entrypoint_5(param_0, local_0 + 0x24, 5, 1, 0);
                local_3 = !func_800D0A9C(0x4B, 1);
                local_2 = !func_800D0A9C(0x18, 4);
                _subaddiedialog_entrypoint_11(param_0->unk0,
                    -local_2 - local_3 + 0x144B, 6, 0, 0x99);
            } else {
                _susubgame_entrypoint_6(param_0, local_0 + 0x24, 8, 0x20, 0);
                local_3 = !func_800D0A9C(0x4B, 1);
                local_2 = !func_800D0A9C(0x18, 4);
                _subaddiedialog_entrypoint_11(param_0->unk0,
                    -local_2 - local_3 + 0x1407, 6, 0, 0x99);
                func_800DA544(0);
                func_80108B04(param_0, 0);
            }
            func_80800018_chwaspnestgame(param_0, 1);
        }
        break;
    case 0x3D:
        if (param_2 > 0) {
            func_80800C7C_chwaspnestgame(param_0, param_2);
        } else if (param_2 < 0) {
            func_80800D7C_chwaspnestgame(param_0, -param_2);
        } else {
            func_80800B80_chwaspnestgame(param_0);
        }
        break;
    case 0x2E:
        func_80800F98_chwaspnestgame(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x30:
        return func_80800EB8_chwaspnestgame(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
    case 0x2F:
        local_1 = ((s16 *)&param_2)[1];
        func_80101180(0x1E4, 0x45, 0);
        _susubgame_entrypoint_6(param_0, local_0 + 0x24, D_80801F76_chwaspnestgame[local_1], 0x20, 0);
        func_80108B04(param_0, -local_1);
        break;
    case 0xB:
        return func_80800DE4_chwaspnestgame(param_0, param_2);
    case 0x57:
        return _susubgame_entrypoint_3(param_0, local_0 + 0x24, param_2 & 0xFFFF,
            (u32)(param_2 & 0xFFFF0000) >> 16);
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        func_80101180(0x1E4, 0x45, 0);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEB, 0x46, 0, 0x99);
        func_80101FDC(param_0, 3);
        break;
    default:
        return 0;
    }
    return 1;
}

Actor *func_80800AF8_chwaspnestgame(Actor *param_0, f32 *param_1, f32 *param_2, s32 param_3)
{
    Actor *local_0;
    local_0 = func_80108528(0x1E4, param_1, 0, &param_0);
    local_0->unk3C = param_0->unk0;
    func_800EE7F8((f32 *)local_0->actorData, param_2);
    local_0->unk6C_0 = param_3;
    func_80103140(local_0, D_80801F70_chwaspnestgame[param_3], 0);
    return local_0;
}

void func_80800B80_chwaspnestgame(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    Actor *local_2;
    func_8008FE68(local_0);
    func_800EEB9C(local_1, func_80090010(), 300.0f);
    local_1[1] = 100.0f;
    func_800EF04C(local_0, local_1);
    local_2 = func_80800AF8_chwaspnestgame(param_0, param_0->position, param_0->position, 0);
    param_0->unk3C = local_2->unk0;
    ((u8 *)local_2)[0x75] &= ~0x10;
}

void func_80800C00_chwaspnestgame(f32 *param_0, f32 param_1)
{
    param_0[0] = func_800DC178(-100.0f, 100.0f);
    param_0[1] = func_800DC178(-100.0f, 100.0f);
    param_0[2] = func_800DC178(-100.0f, 100.0f);
    func_800EF368(param_0, param_1);
}

void func_80800C7C_chwaspnestgame(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_7;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[3];

    func_80800C00_chwaspnestgame(local_4, 500.0f);
    local_4[1] += 1950.0f;
    func_80800C00_chwaspnestgame(local_5, 100.0f);
    func_800EE7B4(local_1, local_4, local_5, 100.0f);
    func_800EE7B4(local_0, local_4, local_5, -100.0f);
    func_800EFA4C(local_6, 0.0f, -600.0f, 0.0f);
    local_7 = func_800F0734(local_0, local_1, local_6, 4000.0f, 5100.0f, local_2, local_3);
    if (local_7) {
        func_800EF3DC(local_2, local_5);
        func_800EF04C(local_3, local_5);
        func_80800AF8_chwaspnestgame(param_0, local_2, local_3, param_1);
        param_0->actorData[7]++;
    }
}

void func_80800D7C_chwaspnestgame(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_2;
    f32 local_0[3];
    f32 local_1[3];

    local_2 = (u8 *)func_80100094(param_0, 0);
    func_800EE7F8(local_0, ((f32 (*)[3])(local_2 + 0x30))[param_1]);
    func_800EE7F8(local_1, local_0);
    func_80800AF8_chwaspnestgame(param_0, local_0, local_1, param_1);
}

s32 func_80800DE4_chwaspnestgame(param_0, param_1) u8 *param_0; s32 param_1;
{
    s32 temp_v1;
    s32 sp2C;

    temp_v1 = func_80100094(param_0, 0);
    switch (param_1)
    {
    case 0:
        sp2C = temp_v1;
        if ((func_800D0A9C(0x4B, 1) == 0) && ((*(s32 *)((s8 *)param_0 + 0x24)) >= 0x32))
        {
            _susubgame_entrypoint_5(param_0, temp_v1 + 0x24, 5, 1, 0);
            _subaddiedialog_entrypoint_11(*(s32 *)((s8 *)param_0), 0x140B, 4, 0, 0x99);
            return 4;
        }
        func_80800018_chwaspnestgame(param_0, 5);
        return 4;
    case 4:
        func_80800018_chwaspnestgame(param_0, 5);
        return 4;
    default:
        return 3;
    }
}

s32 func_80800EB8_chwaspnestgame(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
    case 0x1405: case 0x1449: return param_2 ? 50 : 40;
    case 0x1406: case 0x144A: return 50;
    case 0x1409: return 60;
    case 0x140E: case 0x144C: return param_0->actorData[3];
    case 0x140F: case 0x1450:
        if (!param_2) return param_0->actorData[3];
        break;
    }
    return func_800D211C(0x87);
}

void func_80800F98_chwaspnestgame(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  u8 *local_0;
  s32 local_1;
  s32 local_2;
  s32 local_4;
  s32 local_3;

  local_0 = func_80100094(param_0, 0);
  local_2 = 4;
  local_1 = 0;
  switch (param_1)
  {
    case 0x1405:

    case 0x1406:

    case 0x1407:
      _susubgame_entrypoint_5(param_0, local_0 + 0x24, 5, 1, 0);
      local_1 = 0x1408;
      local_2 = 0x46;
      break;

    case 0x1408:
      if (param_2 == 1)
    {
      local_1 = 0x1409;
      _susubgame_entrypoint_6(param_0, local_0 + 0x24, 0xC, 0x20, 0);
    }
    else
    {
      local_1 = 0xCEC;
      func_80101180(0x1E4, 0x45, 0);
    }
      break;


    case 0x1409:
      func_80101180(0x1E4, 0x45, 0);
      _susubgame_entrypoint_5(param_0, local_0 + 0x24, 5, 1, 0);

    case 0x1449:

    case 0x144A:

    case 0x144B:

    case 0x144D:
      local_1 = 0xCEC;
      break;

    case 0xCEC:
      func_80800018_chwaspnestgame(param_0, 2);
      break;

    case 0xCEB:
      if (func_800D395C() != 0)
    {
      if (param_2 == 1)
      {
        _gcfrontend_entrypoint_11();
      }
      else
      {
        _gcfrontend_entrypoint_10();
      }
    }
    else
    {
      if (param_2 == 1)
      {
        local_4 = 0x139;
        local_3 = 1;
      }
      else
      {
        local_4 = 0x136;
        local_3 = 0x13;
      }
      func_80090708(0);
      func_80800018_chwaspnestgame(param_0, 4);
      _gcgoto_entrypoint_1(local_4, local_3);
    }
      break;

    case 0x140A:
      func_800D1000(0x18, 4, param_0->actorData, 1, 0);
      _susubgame_entrypoint_6(param_0, local_0 + 0x24, 0, 0x20, 0);
      break;

    case 0x140B:

    case 0x140C:
      func_800D1000(0x4B, 1, 0, 1, 0);
      _susubgame_entrypoint_6(param_0, local_0 + 0x24, 4, 0x20, 0);
      break;

    case 0x140D:

    case 0x140E:

    case 0x140F:

    case 0x1410:

    case 0x144C:

    case 0x144E:

    case 0x144F:

    case 0x1450:
      local_1 = 0xCEB;
      local_2 = 0x46;
      break;

  }

  if (local_1 != 0)
  {
    _subaddiedialog_entrypoint_11(param_0->unk0, local_1, local_2, 0, 0x99);
  }
}

int func_80801260_chwaspnestgame(s32 param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_80106790(param_0);
  (*(s32 *)((char *)(local_0) + 0x24)) += param_1;
  (*(s32 *)((char *)(local_0) + 0x34))--;
}

void func_8080129C_chwaspnestgame(s32 param_0) {
    (*(s32 *)(func_80106790(param_0) + 0x34))--;
}

void func_808012C8_chwaspnestgame(s32 arg0) 
{
}
void func_808012D0_chwaspnestgame(u8 *param_0) {
    f32 local_0[3];
    func_8010D600(local_0);
    *(f32 *)(param_0 + 0x54) = func_80102D78(param_0, local_0);
    func_80102BF8(param_0, 0.1f, 4.0f, 180.0f);
    func_808012C8_chwaspnestgame(param_0);
}

void func_80801324_chwaspnestgame(s32 param_0, f32 param_1, f32 param_2) {
    if (param_1 != 0.0f) {
        func_800EF334(param_0, param_2 / param_1);
    }
}

void func_80801364_chwaspnestgame(param_0, param_1) Actor *param_0; s32 param_1;
{
  f32 local_0[3];
  if ((param_0->unk70_10 == 2) && (param_1 != 5))
  {
    func_8010DCB4(0xA);
  }
  switch (param_1)
  {
    case 2:
      func_8010DC50(0xA);
      break;

    case 1:
      func_8008FE68(local_0);
      *((f32 *) (((s8 *) param_0) + 0x28)) = local_0[2] - param_0->position[2];
      *((f32 *) (((s8 *) param_0) + 0x2C)) = 0;
      *((f32 *) (((s8 *) param_0) + 0x30)) = local_0[0] - param_0->position[0];
      func_800EF2A0(((s8 *) param_0) + 0x28);
      *((f32 *) (((s8 *) param_0) + 0x24)) = 0.0f;
      *((f32 *) (((s8 *) param_0) + 0x34)) = 0.0f;
      *((f32 *) (((s8 *) param_0) + 0x2C)) = 1.0f;
      func_800EE7F8(param_0->actorData, param_0->position);
      break;

    case 5:
      func_8010A570(param_0);
      break;

    case 3:
      func_800C4AF0(param_0->position, &D_80802024_chwaspnestgame);
      func_8010A570(param_0);
      break;

    case 4:
    {
      func_800C4AF0(param_0->position, &D_80802038_chwaspnestgame);
      ((Actor *) param_0)->rotation[0] = 0.0f;
      break;
    }

    case 6:
      func_800EFD24(((s8 *) param_0) + 0x28);
      break;

    case 7:
      _subaddiefade_entrypoint_3(param_0);
      break;

  }

  func_80102424(param_0, param_1);
}

void func_808014BC_chwaspnestgame(Actor *param_0, f32 *param_1)
{
    f32 local_0;

    local_0 = func_800D8FF8();
    param_0->position[0] += ((f32 *)param_0->actorData)[4] * local_0 + param_1[0] * local_0 * local_0;
    param_0->position[1] += ((f32 *)param_0->actorData)[5] * local_0 + param_1[1] * local_0 * local_0;
    param_0->position[2] += ((f32 *)param_0->actorData)[6] * local_0 + param_1[2] * local_0 * local_0;
    ((f32 *)param_0->actorData)[4] += param_1[0] * local_0;
    ((f32 *)param_0->actorData)[5] += param_1[1] * local_0;
    ((f32 *)param_0->actorData)[6] += param_1[2] * local_0;
}

int func_80801590_chwaspnestgame(Actor *param_0, f32 param_1, f32 param_2)
{
    f32 local_5;
    f32 local_6;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    s32 local_7;
    func_800EFB24(local_0, (f32 *)param_0->actorData, param_0->position);
    local_5 = func_800EEF94(local_0);
    if (local_5 < 2.0f * param_1) func_80801324_chwaspnestgame(local_0, local_5, 8.0f * param_2);
    else func_80801324_chwaspnestgame(local_0, local_5, 2.0f * param_2);
    func_800EE7F8(local_1, param_0->position);
    func_808014BC_chwaspnestgame(param_0, local_0);
    local_6 = func_800EEF94((f32 *)&param_0->actorData[4]);
    if (param_2 < local_6) func_80801324_chwaspnestgame((f32 *)&param_0->actorData[4], local_6, param_2);
    func_800EE7F8(local_2, param_0->position);
    if (param_0->unk74_30) func_800EE7F8(local_2, param_0->position);
    else {
        func_800EE7F8(local_2, local_1);
        func_800EE7F8(local_1, param_0->position);
    }
    if (func_800BEF00(local_1, local_2, local_3, 0x20020)) {
        param_0->unk74_30 = (s32)param_0->unk74_30 ^ 1;
        func_800F1988(local_3, &local_4[0], &local_4[1]);
        local_4[2] = 0.0f;
        local_7 = func_800BABB8(0, local_2, 0, 1.0f, D_80802044_chwaspnestgame);
        func_800BA77C(local_7, (s16)(s32)local_4[0], (s16)(s32)local_4[1], (s16)(s32)local_4[2]);
        func_800BA22C(local_7, 1);
        func_800C4AF0(param_0->position, D_80802068_chwaspnestgame);
    }
    return local_5 < 0.5f * param_1;
}

s32 func_808017DC_chwaspnestgame(void *param_0, f32 param_1, s32 param_2)
{
    f32 local_vec[3];
    f32 local_out[3];
    f32 local_res[3];

    func_800EFA4C(local_vec, 0.0f, -param_1, 0.0f);
    func_800EE7F8(local_out, (f32 *)((u8 *)param_0 + 4));
    func_808014BC_chwaspnestgame(param_0, local_vec);
    return param_2 != 0 ? (func_800BEF00(local_out, (f32 *)((u8 *)param_0 + 4), local_res, 0x20020) ? 1 : 0) : 0;
}

void func_80801880_chwaspnestgame(f32 *param_0, f32 param_1, f32 param_2, f32 param_3)
{
    f32 local_0;

    local_0 = func_800D8FF8();
    param_0[13] += param_2 * local_0;
    param_0[9] += param_3 * local_0;
    param_0[1] = param_0[6] + (param_0[10] * param_1) * func_800138D0(param_0[13]);
    param_0[3] = param_0[8] + (param_0[12] * param_1) * func_800138D0(param_0[13]);
    param_0[2] = param_0[7] + (param_0[11] * param_1) * func_80013970(param_0[9]);
}

void func_80801954_chwaspnestgame(Actor *param_0)
{
    if (func_800EEB40((f32 *)param_0->actorData, param_0->position) > 1.0f) {
        func_80801364_chwaspnestgame(param_0, 2);
    } else {
        func_80801364_chwaspnestgame(param_0, 1);
    }
    if (func_800DA298(0)) {
        func_8010A570(param_0);
    }
}

void func_808019D4_chwaspnestgame(WaspState *param_0) {
    if (param_0->f72 == 2 || param_0->f72 == 5) {
        func_8010DCB4(10);
    }
}

void func_80801D28_chwaspnestgame();

void func_80801A10_chwaspnestgame(u8 *param_0)
{
  u32 local_0;
  local_0 = ((u16) (*((u16 *) (((s8 *) param_0) + 0x72)))) >> 0xA;
  switch ((u32)((u16) (*((u16 *) (((s8 *) param_0) + 0x72)))) >> 0xA)
  {
    case 1:
      func_80801D28_chwaspnestgame(param_0);
      func_808012D0_chwaspnestgame(param_0);
      func_80801880_chwaspnestgame(param_0, 5e+01f, 2.4e+02f, 1.9e+02f);
      return;

    case 2:
      func_80801D28_chwaspnestgame(param_0);
      func_80801CE4_chwaspnestgame(param_0);
      if (func_80801590_chwaspnestgame(param_0, 1e+02f, 5e+02f) != 0)
    {
      if (func_800DA298(0) == 0)
      {
        func_8080129C_chwaspnestgame(*((s32 *) (((s8 *) param_0) + 0x3C)));
        func_800FFA88(*((s32 *) (((s8 *) param_0) + 0)));
        return;
      }
      func_80801364_chwaspnestgame(param_0, 1);
      return;
    }

    default:
      return;

    case 5:
      func_80801D28_chwaspnestgame(param_0);
      func_80801CE4_chwaspnestgame(param_0);
      if (func_80801590_chwaspnestgame(param_0, 2e+02f, 2e+03f) != 0)
    {
      func_800FFA88(*((s32 *) (((s8 *) param_0) + 0)));
      return;
    }
      break;

    case 3:
      func_808012C8_chwaspnestgame(param_0);
      if (func_808017DC_chwaspnestgame(param_0, 1e+03f, 1) != 0)
    {
      func_80801364_chwaspnestgame(param_0, 4);
      return;
    }
      break;

    case 4:
      if (func_80101DDC(param_0) != 0)
    {
      func_80801364_chwaspnestgame(param_0, 7);
      return;
    }
      break;

    case 6:
      func_80801D28_chwaspnestgame(param_0);
      if (func_808017DC_chwaspnestgame(param_0, 5e+02f, 1) != 0)
    {
      func_80801364_chwaspnestgame(param_0, 7);
    }
      break;

  }

}

s32 func_80801B9C_chwaspnestgame(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    switch (param_1) {
    case 0x3E:
        func_800C4AF0(param_0->position, D_8080207C_chwaspnestgame);
        return 1;
    case 0x40:
        local_0 = _subaddiemulti_entrypoint_5((*(s32 *)&param_2));
        local_1 = param_0->unk6C_0;
        _chscorepoints_entrypoint_2(local_1, local_0, param_0->position, 1);
        func_80801260_chwaspnestgame(param_0->unk3C, local_1);
        func_80801364_chwaspnestgame(param_0, 3);
        return 1;
    case 0x45:
        if (param_0->unk70_10 == 2) {
            func_80801364_chwaspnestgame(param_0, 5);
            return 1;
        } else if (param_0->unk70_10 == 1) {
            func_80801364_chwaspnestgame(param_0, 6);
            return 1;
        }
        break;
    case 0x1F:
        if (param_0->unk70_10 == 2 || param_0->unk70_10 == 5)
            func_8010DD20(param_0, 10, (*(s32 *)&param_2));
        else func_801015D0(param_0);
        return 1;
    default:
        return 0;
    }
    return 1;
}

int func_80801CE4_chwaspnestgame(s32 param_0)
{
  f32 local_0[2];
  func_800F1A88(param_0 + 0x28, local_0);
  (*(f32 *)((char *)(param_0) + 0x44)) = -local_0[0];
  (*(f32 *)((char *)(param_0) + 0x48)) = local_0[1];
}

void func_80801D28_chwaspnestgame(Actor *param_0)
{
    s32 local_3;
    WaspNestClosest32 *local_0;
    s32 local_4;
    f32 local_1[3];
    f32 local_2;

    local_0 = (WaspNestClosest32 *)func_80100094(func_80106790(param_0->unk3C), 0);
    func_800E3980(local_1);
    local_2 = func_800EEAD4(param_0->position, local_1);
    for (local_3 = 0; local_3 < 2; local_3++) {
        if (local_0->distance[local_3] < 0.0f || local_2 < local_0->distance[local_3]) {
            break;
        }
    }
    if (local_3 < 2) {
        for (local_4 = 1; local_4 > local_3; local_4--) {
            func_800EE7F8(local_0->position[local_4], local_0->position[local_4 - 1]);
            local_0->distance[local_4] = local_0->distance[local_4 - 1];
        }
        func_800EE7F8(local_0->position[local_3], param_0->position);
        local_0->distance[local_3] = local_2;
    }
}
