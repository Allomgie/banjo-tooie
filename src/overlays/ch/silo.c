#include "common.h"
#include <types.h>

extern u32 D_808012EC_chsilo[][2];
extern void rom_read_word(u32, u32 *);
typedef struct SiloS { s32 f0; u8 pad[0x70]; u32 pad74:1; u32 flag:1; u32 rest:30; } SiloS;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
extern void *func_800F54E4(void);
extern s32 func_800DA9E4(GameFlag, s32);
extern void func_800EF1B8(f32 *, f32, f32);
typedef struct { u8 pad0[0x24]; f32 unk24; u8 pad28[0x44]; u32 unk6C; u8 pad70[2]; u16 unk72; } ChSiloStruct;
extern s32 func_80090178(s32);
extern s32 func_8010CAC0(void *, s32);
extern f32 func_800D8FF8(void);
extern int D_80801384_chsilo;
extern f32 D_808012C0_chsilo[];
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern void func_800DA544(s32);
extern void _gcnewoption_entrypoint_6(Actor *, s32);
extern void func_80090708(s32);
extern void func_8010A828(Actor *, s32);
extern void _plcamera_entrypoint_3(s32, s32);
extern void func_80102424(Actor *, s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern void func_800F82D4(s32, s32);
extern void func_8008FE68(f32 *);
extern void _gcnewoption_entrypoint_35();
extern void _gcnewoption_entrypoint_4(Actor *, s32, void *, s32, s32);
extern void *func_80100094(Actor *, s32);
extern void _gcnewoption_entrypoint_8(void *, s32);
extern void _gcnewoption_entrypoint_9(void *, s32);
extern void _gcnewoption_entrypoint_10(void *, s32);
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern void _gcnewoption_entrypoint_40(void *, s32, s32, s32, f32, f32);
extern void _gcnewoption_entrypoint_42(void *, f32);
extern void _gcnewoption_entrypoint_11(void *);
extern void func_800C964C(s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800907C0(f32 *);
typedef struct { s16 unk0; s16 pad2; s32 unk4; } SiloGoto;
extern f32 D_808012E0_chsilo[];
extern f32 D_808012D0_chsilo[];
extern SiloGoto D_808012E8_chsilo[];
extern void func_8008FB58(f32 *, f32, f32);
extern s32 func_80101DDC(Actor *);
extern s32 func_8010CB0C(f32 *, s32, s32, s32);
extern s32 func_8008FA2C(s32, s32);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, f32 *);
extern void _gcnewoption_entrypoint_0(void *);
extern void func_800A7AD4(s32, s32);
extern void _gcgoto_entrypoint_1(s32, s32);
extern s32 func_80101E14(Actor *, f32);
extern void func_800904C8(s32);
s32 func_808004C0_chsilo();

s32 func_80800000_chsilo(s32 param_0)
{
    u32 local_0;
    u32 local_3;
    u32 local_1;
    u32 local_2;
    u32 local_4;

    local_0 = D_808012EC_chsilo[param_0][0];
    local_1 = (local_0 & 0xFFFF) + 0xB0000000;
    local_2 = (local_0 & 0xFFFF0000) >> 16;
    local_0 = 0;
    if (local_1 & 2) {
        rom_read_word((local_1 >> 2) << 2, &local_3);
        local_4 = (local_3 & 0xFFFF0000) >> 16;
        local_0 += local_4;
    } else {
        rom_read_word(local_1, &local_3);
        local_4 = local_3 & 0xFFFF;
        local_0 += local_4;
    }
    if (local_2) {
        local_2 += 0xB0000000;
        if (local_2 & 2) {
            local_2 = (local_2 >> 2) << 2;
            rom_read_word(local_2, &local_3);
            local_0 += (local_3 & 0xFFFF0000) >> 16;
        } else {
            rom_read_word(local_2, &local_3);
            local_0 += local_3 & 0xFFFF;
        }
    }
    return local_0 + 0xA0;
}

void func_80800104_chsilo(SiloS *param_0, s32 param_1, s32 param_2) {
    if (!param_0->flag) {
        param_2 |= 6;
        _subaddiedialog_entrypoint_11(param_0->f0, param_1, param_2, (u8 *)param_0 + 4, 0x6F);
        param_0->flag = 1;
    }
}

s32 func_8080015C_chsilo(u8 *param_0, s32 param_1) {
    if (param_1 == ((*(s32 *)((s8 *)(param_0) + 0x6C)) & 0x1FF)) {
        return 0;
    }
    if (func_800DA298(param_1 + 0x32C) == 0) {
        return 0;
    }
    return 1;
}

s32 func_808001A8_chsilo(s32 param_0)
{
  s32 i;
  s32 j;
  j = (j = 0);
  for (i = 1, j; i < 8; i++)
  {
    if (func_8080015C_chsilo(param_0, i))
    {
      j++;
    }
  }

  return j;
}

int func_80800210_chsilo(s32 param_0, s32 param_1)
{
  _gcnewoption_entrypoint_32(param_1 | 0, 0x6F);
}

void func_80800238_chsilo(s32 param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  local_1 = 0;
  local_0 = 1;
  do {
    if (func_8080015C_chsilo(param_0, local_0) != 0) {
      _gcnewoption_entrypoint_12(param_1, local_1, (s16)(local_0 + 9));
      _gcnewoption_entrypoint_31(param_1, local_1, *(s16 *)((char *)&D_808012EC_chsilo + (local_0 * 8) - 2));
      local_1 += 1;
    }
    local_0 += 1;
  } while (local_0 != 8);
}

void func_808002E8_chsilo(void *param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  local_1 = 0;
  local_0 = 1;
  while (1)
  {
    if (func_8080015C_chsilo(param_0, local_0) != 0)
    {
      if ((!local_0) && (!local_0))
      {
      }
      if (local_1 == param_1)
      {
        ((f32 *) param_0)[0x16] = (f32) local_0;
        return;
      }
      local_1 += 1;
    }
    local_0 += 1;
    if (local_0 == 8)
    {
      return;
    }
  }

}

s32 func_80800378_chsilo(s32 param_0){
    func_800903D0(param_0 + 0x18);
}

void func_80800398_chsilo(Actor *param_0, s32 param_1)
{
    if (param_1) {
        if (!param_0->unk74_29) {
            func_800F4CEC(func_800F54E4(), 0x33);
            param_0->unk74_29 = 1;
        }
    } else {
        if (param_0->unk74_29) {
            func_800F4CC0(func_800F54E4());
            param_0->unk74_29 = 0;
        }
    }
}

int func_80800420_chsilo(Actor *param_0, s32 param_1)
{
    if (param_1) {
        if (!param_0->unk64_19) {
            if (func_800F7B9C(func_800F54E4(), 0x8B) != 2) {
                return 0;
            }
            param_0->unk64_19 = 1;
        }
    } else if (param_0->unk64_19) {
        func_800F7B9C(func_800F54E4(), 0x90);
        param_0->unk64_19 = 0;
    }
    return 1;
}

s32 func_808004C0_chsilo(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    s32 local_1;
    void *local_2;

    switch (param_0->unk70_10) {
    case 1:
        _subaddieDll_entrypoint_4(param_0, 1);
        break;
    case 2:
        func_800DA544(param_0->unk6C_0 + 0x32C);
        param_0->unk64_20 = 1;
        ((f32 *)param_0->actorData)[3] = 5.0f;
        break;
    case 6:
        ((f32 *)param_0->actorData)[3] = 0.5f;
        break;
    case 5:
        _gcnewoption_entrypoint_6(param_0, 0);
        func_80090708(0);
        func_8010A828(param_0, 2);
        break;
    case 8:
        func_80800420_chsilo(param_0, 0);
        break;
    case 11:
        _plcamera_entrypoint_3(func_800F54E4(), 1);
        break;
    }
    func_80102424(param_0, param_1);
    switch (param_0->unk70_10) {
    case 1:
        _subaddieDll_entrypoint_4(param_0, 0);
        break;
    case 2:
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808012C0_chsilo);
        break;
    case 6:
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808012C0_chsilo);
        break;
    case 4:
        local_0 = func_800F54E4();
        func_800F82D4(local_0, 1);
        _plcamera_entrypoint_3(local_0, 0);
        func_80800398_chsilo(param_0, 1);
        func_8008FE68((f32 *)&param_0->actorData[4]);
        break;
    case 5:
        local_1 = func_808001A8_chsilo(param_0);
        _gcnewoption_entrypoint_4(param_0, 0, _gcnewoption_entrypoint_35, 0, 0x184F);
        local_2 = func_80100094(param_0, 0);
        _gcnewoption_entrypoint_8(local_2, (local_1 > 5) ? 5 : local_1);
        _gcnewoption_entrypoint_9(local_2, local_1);
        _gcnewoption_entrypoint_10(local_2, 0);
        func_80800210_chsilo(param_0, local_2);
        _gcnewoption_entrypoint_14(local_2, 0, 1, 3, 4.0f);
        _gcnewoption_entrypoint_40(local_2, 0x41, 0x22, 0x20, 0.8f, 1.0f);
        _gcnewoption_entrypoint_42(local_2, 0.1f);
        _gcnewoption_entrypoint_11(local_2);
        func_8010A828(param_0, 10);
        break;
    case 10:
        func_80090708(2);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808012C0_chsilo);
        break;
    case 8:
        func_800C964C(0x10);
        func_80800420_chsilo(param_0, 1);
        func_80800398_chsilo(param_0, 1);
        func_800EE7F8((f32 *)&param_0->actorData[4], param_0->position);
        ((f32 *)param_0->actorData)[5] -= 150.0f;
        func_800907C0((f32 *)&param_0->actorData[4]);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808012C0_chsilo);
        break;
    case 11:
        func_80800398_chsilo(param_0, 1);
        func_80800420_chsilo(param_0, 1);
        func_800EE7F8((f32 *)&param_0->actorData[4], param_0->position);
        ((f32 *)param_0->actorData)[5] -= 150.0f;
        func_800907C0((f32 *)&param_0->actorData[4]);
        break;
    case 9:
        func_80800398_chsilo(param_0, 0);
        ((f32 *)param_0->actorData)[5] = param_0->position[1] - 25.0f;
        func_800907C0((f32 *)&param_0->actorData[4]);
        func_80800378_chsilo(param_0);
        break;
    }
    return 1;
}

void func_8080087C_chsilo(Actor *param_0)
{
    s32 local_0;

    local_0 = _gccubesearch_entrypoint_1(0x309, param_0->position);
    param_0->unk6C_0 = param_0->unk74_7 - 0x32;
    param_0->scale = 1.0f;
    if (local_0 == 0) {
        func_800EE7F8(param_0->actorData, param_0->position);
        func_800EF1B8((f32 *)param_0->actorData, *(f32 *)((u8 *)param_0 + 0x48) - 90.0f, 200.0f);
    } else _gspropctrl_entrypoint_11(local_0, param_0->actorData);
    func_8010A828(param_0, 2);
    if (func_800DA298(param_0->unk6C_0 + 0x32C)) {
        param_0->unk64_20 = 1;
        if (func_800DA9E4(0x6BF, 0)) {
            if (func_8010CB0C(param_0->position, (s32)(param_0->scale * 55.0f),
                (s32)(param_0->scale * 500.0f), (s32)(param_0->scale * -50.0f))) {
                func_808004C0_chsilo(param_0, 8);
                return;
            }
        }
        func_808004C0_chsilo(param_0, 1);
        return;
    }
    func_808004C0_chsilo(param_0, 1);
}

s32 func_808009E8_chsilo(s32 param_0) {
  if (func_80100094(param_0, 0) != 0) {
        _gcnewoption_entrypoint_6(param_0, 0);
    }
  if (((u32) *(u16 *)(param_0 + 0x72) >> 0xA) == 0xA) {
        func_80800398_chsilo(param_0, 0);
    }
}

void func_80800A40_chsilo(volatile ChSiloStruct *param_0)
{
    s32 local_1;
    local_1 = func_80090178(1);
    if ((func_8010CAC0((char *)param_0 + 4, 0x1F4) != 0) && (local_1 != 0) && ((*(f32 *)((char *)(param_0) + 36)) <= 0.0f))
    {
        switch ((u32)param_0->unk72 >> 10)
        {
            case 2:
            case 3:
            case 7:
                break;
            default:
                if (func_800DA9E4(0x334, 1) == 0)
                {
                    func_80800104_chsilo((struct SiloS *)param_0, 0xDA6, 8);
                }
                if ((*(s32 *)((char *)(param_0) + 108)) & 0x1FF)
                {
                    func_808004C0_chsilo(param_0, 2);
                }
                break;
        }
    }
    else if (((*(f32 *)((char *)(param_0) + 36)) <= 0.0f) || (local_1 == 0))
    {
        switch ((u32)param_0->unk72 >> 10)
        {
            case 1:
            case 6:
                break;
            default:
                func_808004C0_chsilo(param_0, 6);
                break;
        }
    }
    else
    {
        (*(f32 *)((char *)(param_0) + 36)) = (*(f32 *)((char *)(param_0) + 36)) - func_800D8FF8();
    }
}

void func_80800B80_chsilo(Actor *param_0)
{
    f32 local_0;

    local_0 = func_800D8FF8();
    if (param_0->unk6C_0 == 0) {
        return;
    }
    switch (param_0->unk70_10) {
    case 1:
        func_8008FB58(param_0->position, param_0->scale * 30.0f, param_0->scale * 60.0f);
        func_80800A40_chsilo(param_0);
        break;
    case 2:
        func_8008FB58(param_0->position, param_0->scale * 30.0f, param_0->scale * 60.0f);
        if (func_80101DDC(param_0)) {
            func_808004C0_chsilo(param_0, 3);
        }
        break;
    case 3:
        if (func_8010CB0C(param_0->position, param_0->scale * 55.0f, param_0->scale * 45.0f, param_0->scale * -50.0f) && func_8008FA2C(1, 0)) {
            if (func_808001A8_chsilo(param_0) > 0) {
                if (func_80800420_chsilo(param_0, 1)) {
                    func_808004C0_chsilo(param_0, 4);
                }
            } else {
                func_80800104_chsilo(param_0, 0xDA8, 0);
                func_80800378_chsilo(param_0);
                func_808004C0_chsilo(param_0, 7);
            }
        } else {
            func_80800A40_chsilo(param_0);
        }
        break;
    case 4:
        ((f32 *)param_0->actorData)[4] += (param_0->position[0] - ((f32 *)param_0->actorData)[4]) * 0.2f;
        ((f32 *)param_0->actorData)[6] += (param_0->position[2] - ((f32 *)param_0->actorData)[6]) * 0.2f;
        if (((f32 *)param_0->actorData)[5] < param_0->position[1] - 150.0f) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808012E0_chsilo);
            func_808004C0_chsilo(param_0, 5);
        } else {
            ((f32 *)param_0->actorData)[5] -= 300.0f * local_0;
            func_800907C0((f32 *)&param_0->actorData[4]);
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808012D0_chsilo);
        }
        break;
    case 5:
        _gcnewoption_entrypoint_0(func_80100094(param_0, 0));
        break;
    case 11:
        if (param_0->position[1] < ((f32 *)param_0->actorData)[5]) {
            func_80800398_chsilo(param_0, 0);
            func_80800420_chsilo(param_0, 0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808012E0_chsilo);
            func_80800378_chsilo(param_0);
            func_808004C0_chsilo(param_0, 7);
        } else {
            ((f32 *)param_0->actorData)[5] += 300.0f * local_0;
            func_800907C0((f32 *)&param_0->actorData[4]);
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808012D0_chsilo);
        }
        break;
    case 10:
        if (func_80101DDC(param_0)) {
            func_800DA544(0x6BF);
            func_800A7AD4(1, 0x11);
            _gcgoto_entrypoint_1(func_80800000_chsilo((s32)param_0->unk58 - 1), D_808012E8_chsilo[(s32)param_0->unk58].unk0);
        }
        break;
    case 6:
        func_8008FB58(param_0->position, param_0->scale * 30.0f, param_0->scale * 60.0f);
        func_80800A40_chsilo(param_0);
        if (func_80101DDC(param_0)) {
            func_808004C0_chsilo(param_0, 1);
        }
        break;
    case 8:
        if (func_80101E14(param_0, 0.4f)) {
            func_808004C0_chsilo(param_0, 9);
        }
        break;
    case 9:
        if (!func_8010CAC0(param_0->position, param_0->scale * 150.0f)) {
            func_808004C0_chsilo(param_0, 3);
        }
        break;
    case 7:
        if (!func_8010CB0C(param_0->position, param_0->scale * 55.0f, param_0->scale * 500.0f, param_0->scale * -50.0f)) {
            func_808004C0_chsilo(param_0, 3);
        }
        break;
    }
    if (func_80090178(0x10000) && func_8010CAC0(param_0->position, param_0->scale * 60.0f)) {
        func_800904C8(0x1F);
    }
}

s32 func_80801080_chsilo(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    switch (param_1) {
    case 0x40:
        if (param_0->unk6C_0) func_808004C0_chsilo(param_0, 2);
        break;
    case 0x1F:
        func_801015D0(param_0);
        if (param_0->unk64_20) func_800DF744(3, 2);
        else func_800DF744(3, 1);
        return 1;
    case 0x95:
        func_8080087C_chsilo(param_0);
        return 1;
    case 0x20:
        local_0 = func_80101080();
        switch (((s16 *)&param_2)[1]) {
        case 3:
            func_808002E8_chsilo(param_0, *(s16 *)&param_2);
            func_808004C0_chsilo(param_0, 10);
            return 1;
        case 0:
            func_80800238_chsilo(param_0, local_0);
            return 1;
        case 2:
            func_808004C0_chsilo(param_0, 11);
            return 1;
        }
        break;
    case 0x2E:
        *((u8 *)param_0 + 0x74) &= ~0x40;
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808011C8_chsilo(s32 param_0, s32 param_1)
{
  s32 local_0;

  if (func_800EB854() == 3)
  {
    local_0 = func_80100094(param_0, 0);
    if (local_0 != 0)
    {
      _gcnewoption_entrypoint_1(local_0, param_1);
    }
  }
  else
  {
    func_801018A4(param_0, param_1);
  }
}

int chsilo_entrypoint_0()
{
    return (int)&D_80801384_chsilo;
}
