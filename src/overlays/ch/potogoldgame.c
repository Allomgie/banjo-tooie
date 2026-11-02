#include "common.h"

extern void func_800D1000();
extern void *func_80100094(Actor *, u32);
extern void _subaddielink_entrypoint_0(void *);
typedef struct { u8 pad_0[0xC]; u8 local_0[8]; u8 local_1; u8 pad_1[3]; } Mass69PotGoldLink;
extern void func_800FC660();
extern u8 D_808024FC_chpotogoldgame[];
extern void func_800BBCB8(s32, s32, f32, s32, void *);
typedef struct { f32 ranges[4][2]; } PotGoldHeightRanges;
extern PotGoldHeightRanges D_80802558_chpotogoldgame;
extern void func_800F1EA4(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern f32 func_800F13C4(f32, f32);
extern void _glid_entrypoint_0();
extern s32 _chpotogoldgame_entrypoint_1;
extern s32 func_800BEA88();
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chpotogoldgame_entrypoint_3();
extern s32 func_800D91EC(f32 *, f32);
extern f32 func_800F5F24(s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern int D_80802578_chpotogoldgame;
typedef struct { u8 pad_0[0x64]; u8 local_0; u8 local_1; u8 local_2; } PotGameData88;
extern void func_800CE8D8(s32, f32, s32);
extern void func_800F7C0C(s32, s32, f32);
typedef struct { f32 local_0[3]; } PotoVector1238;
extern PotoVector1238 D_808024F0_chpotogoldgame;
extern void _chpotogoldgame_entrypoint_0();
typedef struct { u8 pad[0x72]; u16 st : 6; u16 rest : 10; } PgD;
typedef struct { u8 pad[0x65]; u8 hi : 3; u8 f : 1; u8 lo : 4; } PgC;
typedef struct { u8 pad[0x64]; u32 hi : 11; u32 b20 : 1; u32 lo : 20; } PgB;
extern void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
typedef struct { s32 value[3]; } PotGoldVector;
extern s32 D_80802540_chpotogoldgame;
extern s32 D_8080254C_chpotogoldgame;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F3214(s32 *, s32 *, s32 *, f32);
extern void func_800BF48C(s32, s32, s32);
typedef struct { s16 ob[3]; u16 flag; s16 tc[2]; u8 cn[4]; } PotVtx;
void func_808011DC_chpotogoldgame();
void func_808013BC_chpotogoldgame();
void func_80801494_chpotogoldgame();
int func_808016E8_chpotogoldgame();
void func_80801870_chpotogoldgame();
int func_80801998_chpotogoldgame();
s32 func_80801A7C_chpotogoldgame();
s32 func_8080206C_chpotogoldgame();
void func_80802124_chpotogoldgame();
int func_80800434_chpotogoldgame();
void func_80801558_chpotogoldgame();

void func_80800000_chpotogoldgame(u8 *param_0) {
    func_808011DC_chpotogoldgame();
    param_0[0x65] &= 0xFFEF;
    if (func_800DA298(0x6B6) != 0) {
        func_80800434_chpotogoldgame(param_0, 0xF);
    } else if ((func_800D0A9C(0x49, 1) != 0) || (func_800D0A9C(0x17, 4) != 0) || (func_800DA298(0x1DB) != 0) || (func_800D395C() != 0)) {
        *(f32 *)&param_0[0x18] = 2.0f;
        *(f32 *)&param_0[0x2C] = 2.0f;
        *(f32 *)&param_0[0x28] = 2.0f;
        *(f32 *)&param_0[0x30] = 2.0f;
        *(f32 *)&param_0[0x1C] = 2.0f;
        if (func_800D395C() != 0) {
            func_80800434_chpotogoldgame(param_0, 0xD);
        } else {
            func_80800434_chpotogoldgame(param_0, 4);
        }
    } else {
        *(f32 *)&param_0[0x18] = 0.0f;
        *(f32 *)&param_0[0x2C] = 0.0f;
        *(f32 *)&param_0[0x28] = 0.0f;
        *(f32 *)&param_0[0x30] = 0.0f;
        *(f32 *)&param_0[0x1C] = 0.0f;
    }
    func_80801A7C_chpotogoldgame(param_0);
    func_80801494_chpotogoldgame(param_0, 1);
    func_80801558_chpotogoldgame(param_0);
    *(s32 *)&param_0[0x34] = 0;
    _sueggmisc_entrypoint_3();
}

void func_80801244_chpotogoldgame();

void func_80800124_chpotogoldgame(Actor *param_0)
{
    s32 local_0;
    PotGameData88 *local_1;

    local_1 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
        case 1:
            func_80801A7C_chpotogoldgame((u8 *)param_0);
            if (func_800DA298(0x9F6) && func_800DA298(0x9F7) &&
                func_800DA298(0x9F8) && func_800DA298(0x9F9)) {
                func_80800434_chpotogoldgame(param_0, 2);
            }
            break;
        case 2:
            if (func_80801A7C_chpotogoldgame((u8 *)param_0)) {
                func_808013BC_chpotogoldgame(param_0, local_1->local_0,
                    local_1->local_1, local_1->local_2, 0, 0);
                if (++local_1->local_1 == 4) {
                    local_1->local_1 = 0;
                    if (++local_1->local_2 == 5) {
                        local_1->local_2 = 0;
                        if (++local_1->local_0 == 5) {
                            func_80800434_chpotogoldgame(param_0, 4);
                        }
                    }
                }
            }
            break;
        case 4:
            if (param_0->unk64_20 && !_subaddiefind_entrypoint_2(0x1CD, 0)) {
                param_0->unk64_20 = 0;
                if (func_800F64A4(func_800F54E4(), 0x10220)) {
                    func_80800434_chpotogoldgame(param_0, 12);
                } else {
                    func_80800434_chpotogoldgame(param_0, 5);
                }
            }
            break;
        case 5:
            if (local_1->local_0 < 5) {
                func_808011DC_chpotogoldgame(param_0);
                for (local_0 = 0; local_0 != 4; local_0++) {
                    func_808013BC_chpotogoldgame(param_0, local_1->local_0,
                        local_0, local_1->local_2, 0, 0);
                }
                if (++local_1->local_2 == 5) {
                    local_1->local_2 = 0;
                    local_1->local_0++;
                }
            }
            break;
        case 7:
            func_80801244_chpotogoldgame(param_0);
            local_0 = func_8080206C_chpotogoldgame(param_0);
            func_800D2498(0xEB, local_0, 0);
            if (local_0 == 100) {
                param_0->actorData[2] = (s32)(45.0f - func_800CEA84(0));
                if (func_800D395C()) {
                    func_80800434_chpotogoldgame(param_0, 14);
                } else {
                    func_80800434_chpotogoldgame(param_0, 8);
                }
                func_800CE88C(0, 0);
            }
            break;
        case 12:
            if (!func_8010CB84(param_0->position, 500) &&
                !func_800F64A4(func_800F54E4(), 0x10220)) {
                func_80108B04(param_0, 0);
                func_80800434_chpotogoldgame(param_0, 4);
            }
            break;
    }
    func_80801558_chpotogoldgame(param_0);
}

void func_8080219C_chpotogoldgame();

s32 func_8080117C_chpotogoldgame();

int func_80800434_chpotogoldgame(param_0, param_1) Actor *param_0; s32 param_1;
{
  s32 local_1;
  s32 local_2;
  PotoVector1238 local_0;
  s32 local_3;
  s32 local_5;
  s32 local_4;
  s32 local_6;
  s32 local_7;
  s32 local_8;
  u8 *local_9;
  local_9 = func_80100094(param_0, 0);
  switch (param_1)
  {
    case 2:
      func_800DA544(0x1DB);
      func_80108B04(param_0, 0);
      *((s8 *) (((s8 *) local_9) + 0x65)) = 0;
      *((s8 *) (((s8 *) local_9) + 0x66)) = 0;
      *((s8 *) (((s8 *) local_9) + 0x64)) = 0;
      func_80802124_chpotogoldgame(param_0, 0, 0x10);
      break;

    case 5:
      if (func_800D211C(0x84) == 0x64)
    {
      local_3 = 0x1425;
    }
    else
      if (func_800D0A9C(0x49, 1) != 0)
    {
      local_3 = 0x13D1;
    }
    else
      if (func_800D0A9C(0x17, 4) != 0)
    {
      local_3 = 0x13D0;
    }
    else
    {
      local_3 = (func_800DA298(0x1E2) != 0) ? (0x13CF) : (0x13CD);
    }
      func_800F8294(func_800F54E4(), ((u8 *) param_0) + 4);
      func_8080219C_chpotogoldgame(param_0, local_3, 0x4E);
      *((s8 *) (((s8 *) local_9) + 0x65)) = 0;
      *((s8 *) (((s8 *) local_9) + 0x66)) = 0;
      *((s8 *) (((s8 *) local_9) + 0x64)) = 0;
      *((u8 *) (((s8 *) param_0) + 0x65)) = (u8) ((*((u8 *) (((s8 *) param_0) + 0x65))) & 0xFFEF);
      break;

    case 6:
      func_8080219C_chpotogoldgame(param_0, 0xCEC, 0xE);
      func_800CE8D8(0, 45.0f, 45);
      func_800CE928(0, &_chpotogoldgame_entrypoint_0, *((s32 *) (((s8 *) param_0) + 0)));
      _gcfrontend_entrypoint_9(0x71);
      break;

    case 7:
      local_0 = D_808024F0_chpotogoldgame;
      for (local_8 = 0; local_8 < 5; local_8++)
    {
      for (local_7 = 0; local_7 < 4; local_7++)
      {
        for (local_6 = 0; local_6 < 5; local_6++)
        {
          func_808013BC_chpotogoldgame(param_0, local_8, local_7, local_6, 0, 0);
        }

      }

    }

      func_808011DC_chpotogoldgame(param_0);
      func_8080227C_chpotogoldgame(param_0);
      func_800F7C0C(func_800F54E4(), 0x5F, -1.0f);
      func_800F7CF4(func_800F54E4(), 0x5E, local_0.local_0);
      func_800CE88C(0, 1);
      func_800FDC28(0xC);
      func_800DA544(0x1E2);
      break;

    case 8:
      local_4 = func_8080206C_chpotogoldgame(param_0);
      if (func_800D211C(0x84) == 0x64)
    {
      if (local_4 < 0x64)
      {
        func_800FC6B0(0x17);
        local_1 = 0x141E;
      }
      else
        if ((*((s32 *) (((s8 *) param_0) + 0x20))) < func_800D211C(0x89))
      {
        func_800FC6B0(0x16);
        local_1 = 0x1421;
      }
      else
        if (func_800D211C(0x89) == (*((s32 *) (((s8 *) param_0) + 0x20))))
      {
        func_800FC6B0(0x17);
        local_1 = 0x1420;
      }
      else
      {
        func_800FC6B0(0x17);
        local_1 = 0x141F;
      }
    }
    else
      if (func_800D0A9C(0x49, 1) != 0)
    {
      if (func_800D211C(0x84) == local_4)
      {
        func_800FC6B0(0x17);
        local_1 = 0x13D9;
      }
      else
        if (local_4 < func_800D211C(0x84))
      {
        func_800FC6B0(0x17);
        local_1 = 0x13D7;
      }
      else
        if (local_4 == 0x64)
      {
        func_800FC6B0(0x16);
        local_1 = 0x1422;
      }
      else
      {
        func_800FC6B0(0x16);
        local_1 = 0x13D8;
      }
    }
    else
      if (func_800D0A9C(0x17, 4) != 0)
    {
      if (local_4 < 0x5A)
      {
        func_800FC6B0(0x17);
        local_1 = 0x13D5;
      }
      else
        if (local_4 == 0x64)
      {
        func_800FC6B0(0x16);
        local_1 = 0x1423;
      }
      else
      {
        func_800FC6B0(0x16);
        local_1 = 0x13D6;
      }
    }
    else
      if (local_4 < 0x4B)
    {
      func_800FC6B0(0x17);
      local_1 = 0x13D2;
    }
    else
      if (local_4 < 0x5A)
    {
      func_800FC6B0(0x16);
      local_1 = 0x13D3;
    }
    else
      if (local_4 == 0x64)
    {
      func_800FC6B0(0x16);
      local_1 = 0x1424;
    }
    else
    {
      func_800FC6B0(0x16);
      local_1 = 0x13D4;
    }
      func_8080219C_chpotogoldgame(param_0, local_1, 0xE);
      func_800F7C0C(func_800F54E4(), 0x5F, 0.0f);
      func_800FDC28(0);
      break;

    case 9:
      func_8080117C_chpotogoldgame(param_0);
      break;

    case 10:
      func_8080111C_chpotogoldgame(param_0);
      break;

    case 11:
      func_8080117C_chpotogoldgame(param_0);
      break;

    case 12:
      if (func_800F64A4(func_800F54E4(), 0x10220) == 0)
    {
      func_8080219C_chpotogoldgame(param_0, 0x141D, 0xE);
    }
      break;

    case 4:
      func_8080227C_chpotogoldgame(param_0);
      func_80108B04(param_0, 1);
      break;

    case 13:
      func_800F8294(func_800F54E4(), ((u8 *) param_0) + 4);
      if (func_800D211C(0x84) == 0x64)
    {
      func_8080219C_chpotogoldgame(param_0, 0x1439, 0xE);
    }
    else
    {
      func_8080219C_chpotogoldgame(param_0, 0x1438, 0xE);
    }
      break;

    case 14:
      local_5 = func_8080206C_chpotogoldgame(param_0);
      if (func_800D211C(0x84) == 0x64)
    {
      if (local_5 < 0x64)
      {
        func_800FC6B0(0x17);
        local_2 = 0x143A;
      }
      else
        if ((*((s32 *) (((s8 *) param_0) + 0x20))) < func_800D211C(0x89))
      {
        func_800FC6B0(0x16);
        local_2 = 0x143D;
      }
      else
        if (func_800D211C(0x89) == (*((s32 *) (((s8 *) param_0) + 0x20))))
      {
        func_800FC6B0(0x17);
        local_2 = 0x143C;
      }
      else
      {
        func_800FC6B0(0x17);
        local_2 = 0x143B;
      }
    }
    else
      if (func_800D211C(0x84) == local_5)
    {
      func_800FC6B0(0x17);
      local_2 = 0x1440;
    }
    else
      if (local_5 < func_800D211C(0x84))
    {
      func_800FC6B0(0x17);
      local_2 = 0x143F;
    }
    else
      if (local_5 == 0x64)
    {
      func_800FC6B0(0x16);
      local_2 = 0x143E;
    }
    else
    {
      func_800FC6B0(0x16);
      local_2 = 0x1441;
    }
      func_8080219C_chpotogoldgame(param_0, local_2, 0xE);
      func_800FDC28(0);
      break;

  }

  func_80101FDC(param_0, param_1);
}

void func_808010A0_chpotogoldgame();

s32 func_80800A94_chpotogoldgame(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    s16 *local_1;
    s32 code;
    s32 value;

    local_1 = (s16 *)&param_2;

    switch (param_1) {
        case 0x3D:
            if (!((PgB *)param_0)->b20) {
                local_0 = (Actor *)func_80108528(
                    0x1CD,
                    (char *)param_0 + 4,
                    0,
                    &param_0
                );

                *(u16 *)((char *)local_0 + 0x76) =
                    (*(u16 *)((char *)local_0 + 0x76) & 0x7F) | 0x1900;

                ((PgC *)param_0)->f = 1;

                if (param_2 == 0) {
                    _chappearfx_entrypoint_1(local_0, 0x20, 0, 1.0f);
                }

                return 1;
            }
            return 0;

        case 0x30:
            code = local_1[0];

            switch (code) {
                case 0x141F:
                case 0x1420:
                case 0x1421:
                    if (local_1[1] != 0) {
                        return func_800D211C(0x89);
                    }
                    return *(s32 *)((char *)param_0 + 0x20);

                case 0x1422:
                case 0x1423:
                case 0x1424:
                    return *(s32 *)((char *)param_0 + 0x20);

                case 0x1425:
                    return func_800D211C(0x89);

                case 0x13D2:
                case 0x13D3:
                case 0x13D4:
                case 0x13D5:
                case 0x13D6:
                case 0x13D9:
                case 0x141E:
                    return func_8080206C_chpotogoldgame(param_0);

                case 0x13D7:
                case 0x13D8:
                    if (local_1[1] != 0) {
                        return func_800D211C(0x84);
                    }
                    return func_8080206C_chpotogoldgame(param_0);

                case 0x13CD:
                case 0x13CF:
                    value = local_1[1];

                    switch (value) {
                        case 1:
                            return 0x2D;
                        case 2:
                            return 0x5A;
                    }
                    return 0x4B;

                case 0x13D0:
                    if (local_1[1] != 0) {
                        return 0x2D;
                    }
                    return 0x5A;

                case 0x13D1:
                    return func_800D211C(0x84);

                case 0x1438:
                    if (local_1[1] != 0) {
                        return func_800D211C(0x84);
                    }
                    return 0x2D;

                case 0x1439:
                    if (local_1[1] != 0) {
                        return func_800D211C(0x89);
                    }
                    return 0x2D;

                case 0x143A:
                    return func_8080206C_chpotogoldgame(param_0);

                case 0x143D:
                    if (local_1[1] != 0) {
                        return func_800D211C(0x89);
                    }
                    return *(s32 *)((char *)param_0 + 0x20);

                case 0x143C:
                    return *(s32 *)((char *)param_0 + 0x20);

                case 0x143B:
                    if (local_1[1] != 0) {
                        return func_800D211C(0x89);
                    }
                    return *(s32 *)((char *)param_0 + 0x20);

                case 0x1440:
                    return func_8080206C_chpotogoldgame(param_0);

                case 0x143F:
                    if (local_1[1] != 0) {
                        return func_800D211C(0x84);
                    }
                    return func_8080206C_chpotogoldgame(param_0);

                case 0x143E:
                    return *(s32 *)((char *)param_0 + 0x20);

                case 0x1441:
                    if (local_1[1] != 0) {
                        return func_800D211C(0x84);
                    }
                    return func_8080206C_chpotogoldgame(param_0);

                default:
                    return 1;
            }

        case 0x2E:
            code = local_1[0];

            switch (code) {
                case 0xCEC:
                    func_80800434_chpotogoldgame(param_0, 7);
                    return 1;

                case 0x13CD:
                case 0x13CF:
                case 0x13D0:
                case 0x13D1:
                case 0x1425:
                    if (local_1[1] != 0) {
                        func_80800434_chpotogoldgame(param_0, 6);
                    } else {
                        func_80800434_chpotogoldgame(param_0, 0xC);
                    }
                    return 1;

                case 0x13D3:
                    func_808010A0_chpotogoldgame(param_0);
                    func_80800434_chpotogoldgame(param_0, 9);
                    return 1;

                case 0x13D6:
                case 0x1423:
                    func_808010A0_chpotogoldgame(param_0);
                    func_80800434_chpotogoldgame(param_0, 0xA);
                    return 1;

                case 0x13D4:
                case 0x1424:
                    func_808010A0_chpotogoldgame(param_0);
                    func_80800434_chpotogoldgame(param_0, 0xB);
                    return 1;

                case 0x13D2:
                case 0x13D5:
                case 0x13D7:
                case 0x13D8:
                case 0x13D9:
                case 0x141E:
                case 0x141F:
                case 0x1420:
                case 0x1421:
                case 0x1422:
                    func_808010A0_chpotogoldgame(param_0);
                    func_80800434_chpotogoldgame(param_0, 5);
                    return 1;

                case 0x141D:
                    func_8080227C_chpotogoldgame(param_0);
                    value = func_800F54E4();
                    func_800F7B9C(value, 0x93);
                    return 1;

                case 0x1438:
                case 0x1439:
                    func_80800434_chpotogoldgame(param_0, 6);
                    return 1;

                case 0x143A:
                case 0x143B:
                case 0x143C:
                case 0x143D:
                case 0x143E:
                case 0x143F:
                case 0x1440:
                case 0x1441:
                    func_808010A0_chpotogoldgame(param_0);
                    func_8080219C_chpotogoldgame(
                        param_0,
                        0x1442,
                        0x4E
                    );
                    return 1;

                case 0x1442:
                    if (local_1[1] != 0) {
                        func_80800434_chpotogoldgame(param_0, 6);
                    } else {
                        func_8080227C_chpotogoldgame(param_0);
                        func_800C0850();
                        _gcfrontend_entrypoint_10();
                    }
                    return 1;

                default:
                    if (local_1) {
                    } /* probe: empty test in the default case - makes as1 fill `lw a0` into the bne delay slot of the 0xCEC comparison */
                    return 1;
            }

        case 0x0B:
            if (param_2 == 5 && ((PgD *)param_0)->st == 0xB) {
                {
                    func_8080111C_chpotogoldgame(param_0);
                    return 4;
                }
            }

            if (param_2 == 0) {
                func_80800434_chpotogoldgame(param_0, 4);
                return 4;
            }
            if (param_2 == 3 || param_2 == 5) {
                func_80800434_chpotogoldgame(param_0, 5);
                return 4;
            }
            func_80800434_chpotogoldgame(param_0, 5);
            return 4;

        case 0x95:
            if (((PgD *)param_0)->st == 4) {
                func_80108B04(param_0, 1);
                ((PgC *)param_0)->f = 0;
            }

            return 1;

        default:
            return 0;
    }
}

int chpotogoldgame_entrypoint_0(s32 param_0, s32 param_1)
{
  if (func_800D395C())
  {
    return func_80800434_chpotogoldgame(func_80106790(param_1), 0xE);
  }
  else
  {
    return func_80800434_chpotogoldgame(func_80106790(param_1), 8);
  }
}

void func_808010A0_chpotogoldgame(Actor *param_0)
{
    s32 local_0;
    local_0 = func_8080206C_chpotogoldgame(param_0);
    if (func_800D211C(0x84) == 100) {
        func_800D2054(1, 0x89, param_0->actorData[2]);
    } else {
        if (local_0 == 100) {
            func_800D2054(1, 0x89, param_0->actorData[2]);
        }
        func_800D2054(0, 0x84, local_0);
    }
}

int func_8080111C_chpotogoldgame(s32 param_0)
{
  f32 local_1[3];
  _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x1F6, param_0 + 4), local_1);
  func_800D1000(0x49, 1, local_1, 1, 0);
  func_80802124_chpotogoldgame(param_0, 3, 0x10);
}

s32 func_8080117C_chpotogoldgame(s32 a0) {
    f32 vec[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x201, a0 + 0x4), vec);
    func_800D1000(0x17, 0x4, vec, 1, 0);
    func_80802124_chpotogoldgame(a0, 5, 0x10);
}

void func_808011DC_chpotogoldgame(param_0) Actor *param_0;
{
    s32 local_0;
    Mass69PotGoldLink *local_1;

    local_1 = func_80100094(param_0, 1);
    for (local_0 = 0; local_0 < 10; local_0++) {
        local_1[local_0].local_1 = 0;
        _subaddielink_entrypoint_0(local_1[local_0].local_0);
    }
}

void func_80801244_chpotogoldgame(s32 param_0)
{
    s32 off;
    s32 n;
    s32 *objs[10];
    u8 *base;
    s32 x;
    s32 y;
    s32 z;
    s32 i;

    base = func_80100094(param_0, 1);
    off = 0;
    if (base[0x14] != 0) {
        do {
            if (_subaddielink_entrypoint_4(base + off + 0xC) == 0 && func_808016E8_chpotogoldgame(base + off, &x, &y, &z) != 0) {
                func_808013BC_chpotogoldgame(param_0, y, x, z, 1, base + off);
                if (off) {}
            }
            off += 0x18;
        } while (off < 0xF0 && base[off + 0x14] != 0);
    }
    n = _subaddiefind_entrypoint_4(0x15F, objs, 10);
    i = 0;
    if (n > 0) {
        do {
            if (1) {}
            off = i * 0x18;
            func_800EE7F8(base + off, objs[i] + 1);
            _subaddielink_entrypoint_1(base + off + 0xC, *objs[i]);
            i += 1;
            base[i * 0x18 - 4] = 1;
        } while (i < n);
    }
    if (i < 10) {
        do {
            i += 1;
            base[i * 0x18 - 4] = 0;
        } while (i < 10);
    }
}

void func_808013BC_chpotogoldgame(param_0, param_1, param_2, param_3, param_4, param_5) Actor *param_0; s32 param_1; s32 param_2; s32 param_3; s32 param_4; s32 param_5;
{
    u8 (*local_0)[4][5];
    local_0 = func_80100094(param_0, 0);
    if (param_4 && !local_0[param_1][param_2][param_3]) {
        if (param_5) func_800BBCB8(param_5, param_5, 1.0f, 30, D_808024FC_chpotogoldgame);
        func_800FC660(14);
    }
    local_0[param_1][param_2][param_3] = param_4;
    func_80801870_chpotogoldgame(param_2, param_1, param_3, param_4);
}

void func_80801494_chpotogoldgame(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 (*local_0)[4][5];
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 5; local_1++) {
        for (local_2 = 0; local_2 < 4; local_2++) {
            for (local_3 = 0; local_3 < 5; local_3++) {
                local_0[local_1][local_2][local_3] = param_1;
                func_80801870_chpotogoldgame(local_2, local_1, local_3, param_1);
            }
        }
    }
}

void func_80801558_chpotogoldgame(param_0) Actor *param_0;
{
    s32 local_0[3];
    PotGoldVector local_1;
    PotGoldVector local_2;
    f32 local_3;
    local_1 = *(PotGoldVector *)&D_80802540_chpotogoldgame;
    local_2 = *(PotGoldVector *)&D_8080254C_chpotogoldgame;
    local_3 = func_800F10B4((f32)func_8080206C_chpotogoldgame(), 100.0f, 0.0f, 0.0f, 0.5f);
    local_3 += func_800F10B4(*(f32 *)((u8 *)param_0 + 0x2C), 0.0f, 2.0f, 0.0f, 0.1f);
    local_3 += func_800F10B4(*(f32 *)((u8 *)param_0 + 0x30), 0.0f, 2.0f, 0.0f, 0.1f);
    local_3 += func_800F10B4(((f32 *)param_0->actorData)[0], 0.0f, 2.0f, 0.0f, 0.1f);
    local_3 += func_800F10B4(*(f32 *)((u8 *)param_0 + 0x28), 0.0f, 2.0f, 0.0f, 0.1f);
    local_3 += func_800F10B4(((f32 *)param_0->actorData)[1], 0.0f, 2.0f, 0.0f, 0.1f);
    func_800F3214(local_0, local_1.value, local_2.value, local_3);
    func_800BF48C(local_0[0], local_0[1], local_0[2]);
    func_800C8C90(local_0);
}

int func_808016E8_chpotogoldgame(param_0, param_1, param_2, param_3) f32 *param_0; s32 *param_1; s32 *param_2; s32 *param_3;
{
    f32 local_0;
    PotGoldHeightRanges local_1 = D_80802558_chpotogoldgame;
    for (*param_1 = 0; *param_1 < 4; (*param_1)++) {
        if (local_1.ranges[0][*param_1 << 1] < param_0[1]) return 0;
        if (local_1.ranges[0][(*param_1 << 1) + 1] < param_0[1]) break;
    }
    if (*param_1 >= 4) return 0;
    func_800F1EA4(param_0, &local_0);
    local_0 = func_800136E4(local_0 - 7.0f);
    *param_2 = (s32)(local_0 / 72.0f);
    local_0 = func_800F13C4(local_0, 72.0f);
    if (local_0 > 58.0f) return 0;
    *param_3 = (s32)(local_0 / 12.0f);
    if (func_800F13C4(local_0, 12.0f) > 10.0f) return 0;
    return 1;
}

void func_80801870_chpotogoldgame(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s32 param_3;
{
  s32 temp_a1;
  temp_a1 = (param_1 = ((param_3 & 1) * 0x10) | param_1);
  _glid_entrypoint_0(func_800BEA88(0, temp_a1), ((param_0 * 5) - param_2) + 5, &_chpotogoldgame_entrypoint_1, param_1);
}

void chpotogoldgame_entrypoint_1(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, s32 param_4)
{
    s32 local_1;
    Vtx *local_0;

    local_1 = param_4 & 0x10;
    param_4 &= 0xF;
    local_0 = param_2 + param_3;
    while (param_2 < local_0) {
        if (func_80801998_chpotogoldgame((s32)param_1) == param_4) {
            if (local_1) {
                param_2->v.cn[0] = 100;
                param_2->v.cn[1] = 100;
                param_2->v.cn[2] = 100;
            } else {
                param_2->v.cn[0] = 255;
                param_2->v.cn[1] = 255;
                param_2->v.cn[2] = 255;
            }
        }
        param_2++;
        param_1++;
    }
}

int func_80801998_chpotogoldgame(param_0) s32 param_0;
{
  f32 local_1;
  f32 local_0[3];
  func_800EE88C(local_0, param_0 | 0);
  func_800F1EA4(local_0, &local_1);
  return local_1 / 72.0f;
}

void chpotogoldgame_entrypoint_2(s32 param_0, Unk80132ED0 *param_1)
{
    s32 local_0;
    Actor *local_1;
    local_1 = func_80106790(param_1);
    switch (local_1->unk6C_9) {
    case 0x15A: local_0 = 0x9F6; break;
    case 0x15B: local_0 = 0x9F7; break;
    case 0x15C: local_0 = 0x9F8; break;
    case 0x15D: local_0 = 0x9F9; break;
    default: return;
    }
    if (!func_800DA298(local_0)) {
        func_800FC6B0(0xE);
        func_800DA544(local_0);
    }
}

s32 func_80801A7C_chpotogoldgame(param_0) u8 *param_0;
{
    s32 local_0;

    local_0 = 1;
    if (func_800DA298(0x9F6) || func_800DA298(0x1DB)) {
        local_0 &= func_800D91EC((f32 *)(param_0 + 0x18), 2.0f);
    }
    if (func_800DA298(0x9F7) || func_800DA298(0x1DB)) {
        local_0 &= func_800D91EC((f32 *)(param_0 + 0x2C), 2.0f);
    }
    if (func_800DA298(0x9F8) || func_800DA298(0x1DB)) {
        local_0 &= func_800D91EC((f32 *)(param_0 + 0x28), 2.0f);
    }
    if (func_800DA298(0x9F9) || func_800DA298(0x1DB)) {
        local_0 &= func_800D91EC((f32 *)(param_0 + 0x30), 2.0f);
    }
    if (func_800DA298(0x9F6) && func_800DA298(0x9F7) && func_800DA298(0x9F8) && func_800DA298(0x9F9)) {
        local_0 &= func_800D91EC((f32 *)(param_0 + 0x1C), 2.0f);
    }
    _glid_entrypoint_0(func_800BEA88(0), 0x18, _chpotogoldgame_entrypoint_3, *(s32 *)param_0);
    _glid_entrypoint_0(func_800BEA88(0), 0x15, _chpotogoldgame_entrypoint_3, *(s32 *)param_0);
    _glid_entrypoint_0(func_800BEA88(0), 0x17, _chpotogoldgame_entrypoint_3, *(s32 *)param_0);
    _glid_entrypoint_0(func_800BEA88(0), 0x16, _chpotogoldgame_entrypoint_3, *(s32 *)param_0);
    _glid_entrypoint_0(func_800BEA88(0), 0x19, _chpotogoldgame_entrypoint_3, *(s32 *)param_0);
    return local_0;
}

void chpotogoldgame_entrypoint_3(s32 param_0, s32 param_1, PotVtx *param_2, s32 param_3, s32 param_4)
{
    Actor *local_0;
    PotVtx *local_1;
    u8 local_2;

    local_0 = func_80106790(param_4);
    switch (param_0) {
    case 0x15:
        local_2 = func_800F10B4(((f32 *)local_0->actorData)[5], 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 0x16:
        local_2 = func_800F10B4(((f32 *)local_0->actorData)[6], 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 0x17:
        local_2 = func_800F10B4(((f32 *)local_0->actorData)[4], 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 0x18:
        local_2 = func_800F10B4(((f32 *)local_0->actorData)[0], 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 0x19:
        local_2 = func_800F10B4(((f32 *)local_0->actorData)[1], 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    }
    for (local_1 = param_2 + param_3; param_2 < local_1; param_2++) {
        param_2->cn[0] = local_2;
        param_2->cn[1] = local_2;
        param_2->cn[2] = local_2;
    }
}

s32 func_8080206C_chpotogoldgame(param_0) Actor *param_0;
{
    u8 (*local_0)[4][5];
    s32 local_3;
    s32 local_2;
    s32 local_1;
    s32 local_4;

    local_1 = 0;
    local_0 = func_80100094(param_0, 0);
    for (local_2 = 0; local_2 < 5; local_2++) {
        for (local_3 = 0; local_3 < 4; local_3++) {
            for (local_4 = 0; local_4 < 5; local_4++) {
                if (local_0[local_2][local_3][local_4]) {
                    local_1++;
                }
            }
        }
    }
    return local_1;
}

void func_80802124_chpotogoldgame(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2; {
    s32 temp_v0;
    temp_v0 = param_0[13];
    switch (temp_v0) {
    case 0:
        _capod_entrypoint_2(param_0[0], 0x29, 0x10, param_0);
    case 1:
        param_0[13] = 2;
    case 2:
        _capod_entrypoint_6(param_0[0], param_1, param_2, param_0);
        return;
    }
}

void func_8080219C_chpotogoldgame(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];

    switch (param_0->actorData[7]) {
    case 1: break;
    case 0: _capod_entrypoint_2(param_0->unk0, 0x29, 0x10);
    default:
        _capod_entrypoint_8(1);
        param_0->actorData[7] = 1;
        _gcdialogcamera_entrypoint_6(param_0->unk0);
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_7(5, 1);
        break;
    }
    func_800F5A00(func_800F54E4(), local_0);
    func_800EEB9C(local_1, func_800F5F24(func_800F54E4()), 300.0f);
    func_800EF04C(local_0, local_1);
    _subaddiedialog_entrypoint_11(param_0->unk0, param_1, param_2, local_0, 0x22);
}

int func_8080227C_chpotogoldgame(Actor *param_0)
{
  s32 *ptr = (s32 *)((char *)param_0 + 0x34);
  if (*ptr) {
        _capod_entrypoint_3(0, param_0);
        *ptr = 0;
    }
}

int chpotogoldgame_entrypoint_4()
{
    return (int)&D_80802578_chpotogoldgame;
}
