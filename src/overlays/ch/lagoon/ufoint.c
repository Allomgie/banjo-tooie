#include "common.h"

extern int D_80801948_chlagoonufoint;
extern int D_808019C0_chlagoonufoint;
extern int D_80801A28_chlagoonufoint;
extern s32 D_80801A90_chlagoonufoint[];
extern s32 D_80801AF4_chlagoonufoint;
extern s32 D_80801AD8_chlagoonufoint;
extern f32 func_800DC0C0(void);
extern void func_80101EE4(Actor *, f32);
extern s16 D_80801B10_chlagoonufoint[];
extern s32 func_800C4350(u8, f32 *, s16 *);
extern void func_800C4104(s32, f32, s32, u8 *, f32, f32);
extern s32 D_80801B58_chlagoonufoint;
extern int D_80801B68_chlagoonufoint;
extern void _glid_entrypoint_0(s32, s32, void *, void *);
extern void func_800C8D4C(s32, f32 *);
extern void func_800C8E84(s32, f32 *);
extern f32 func_800D8FF8(void);
extern int func_800F3214(s32 *, s32 *, s32 *, f32);
extern s32 D_80801BB0_chlagoonufoint[3];
extern s32 D_80801BBC_chlagoonufoint[3];
extern void _chlagoonufoint_entrypoint_6();
extern s16 D_80801940_chlagoonufoint[];
typedef struct { s16 a, b; } S16Pair;
extern void func_800CE8D8(s32, f32, s32);
extern void *func_80100094(Actor *, u32);
extern u8 D_80801990_chlagoonufoint[];
extern void _chlagoonufoint_entrypoint_5();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C3FC0(s32, f32, s32);
extern Actor *func_80106790(Unk80132ED0 *);
extern u8 D_80801B1C_chlagoonufoint[];
extern u8 D_80801B2C_chlagoonufoint[];
extern u8 D_80801B38_chlagoonufoint[];
extern u8 D_80801B44_chlagoonufoint[];
extern u8 D_80801B50_chlagoonufoint[];
extern void func_8008FB10(f32 *, f32, f32, f32);
extern f32 func_80101F24(Actor *);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
typedef struct { u8 pad_0[0x72]; u8 local_0 : 6; u8 pad_1 : 2; } LagoonUfoState;
void func_8080000C_chlagoonufoint();
void func_80800E80_chlagoonufoint();

int chlagoonufoint_entrypoint_0()
{
    return &D_80801948_chlagoonufoint;
}

void func_8080000C_chlagoonufoint(param_0, param_1) Actor *param_0; s32 param_1;
{
    switch (param_1) {
        case 1: func_800DA524(0); break;
        case 2:
            func_800CE8D8(0, 20.0f, 0x14);
            func_800CE88C(0, 1);
            break;
        case 4:
            func_800CE88C(0, 0);
            func_800FC63C(0x10, 0x6D60);
            _susubgame_entrypoint_6(param_0, func_80100094(param_0, 0), 8, 0x30, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xFF5, 8, param_0->position, 0x62);
            func_800DA544(0x9F0);
            break;
        case 3:
            param_0->unk79_4 = 0;
            func_800FC63C(0x17, 0x6D60);
            func_800DA544(0);
            *(f32 *)((u8 *)param_0 + 0x28) = 0.0f;
            *(f32 *)((u8 *)param_0 + 0x2C) = -0.33333334f;
            if (!func_800DA298(0x9EF)) {
                _susubgame_entrypoint_6(param_0, func_80100094(param_0, 0), 4, 0x30, 0);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0xFF4, 8, param_0->position, 0x62);
            }
            param_0->unk58 = 3.0f;
            break;
    }
    param_0->unk70_10 = param_1;
}

void func_808001A0_chlagoonufoint(u8 *param_0) {
    u8 *local_1;
    f32 local_0;

    local_1 = param_0 + 0x28;
    local_0 = 0.0f;
    *(f32 *)(local_1 - 4) = local_0;
    func_800EFD24(local_1);
    if ((func_800DA298(0x9F0) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        param_0[0x79] = (param_0[0x79] & 0xFF0F) | 0x40;
        *(f32 *)(param_0 + 0x24) = 1.0f;
    } else {
        func_8080000C_chlagoonufoint(param_0, 1);
    }
    _susubgame_entrypoint_0(param_0, func_80100094(param_0, 0), 0);
    _susubgame_entrypoint_11(0);
}

void func_80800240_chlagoonufoint(s32 param_0) {
    if (_susubgame_entrypoint_2(param_0, func_80100094(param_0, 0)) != 0) {
        _susubgame_entrypoint_4(param_0, func_80100094(param_0, 0));
    }
    _susubgame_entrypoint_11(0);
}

void func_80800294_chlagoonufoint(Actor *param_0)
{
    f32 local_0;
    local_0 = func_800D8FF8();
    if (*(f32 *)&param_0->actorData[5] != 0.0f) {
        *(f32 *)&param_0->actorData[3] += *(f32 *)&param_0->actorData[5] * local_0;
        if ((*(f32 *)&param_0->actorData[5] > 0.0f && *(f32 *)&param_0->actorData[4] < *(f32 *)&param_0->actorData[3]) ||
            (*(f32 *)&param_0->actorData[5] < 0.0f && *(f32 *)&param_0->actorData[3] < *(f32 *)&param_0->actorData[4])) {
            *(f32 *)&param_0->actorData[3] = *(f32 *)&param_0->actorData[4];
            *(f32 *)&param_0->actorData[5] = 0.0f;
        }
    }
    if (*(f32 *)&param_0->actorData[3] != 0) {
        func_800C4B70((s32)func_800F10B4(*(f32 *)&param_0->actorData[4], 0.0f, 1.0f, 12000.0f, 20000.0f));
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80801990_chlagoonufoint);
        if (*(f32 *)&param_0->actorData[6] <= 0) {
            func_800C3FC0(0x67A, func_800F10B4(*(f32 *)&param_0->actorData[4], 0.0f, 1.0f, 0.4f, 1.0f), 0x4650);
            *(f32 *)&param_0->actorData[6] = func_800F10B4(*(f32 *)&param_0->actorData[4], 0.0f, 1.0f, 0.95f, 0.25f);
        } else *(f32 *)&param_0->actorData[6] -= local_0;
    }
    switch (param_0->unk70_10) {
    case 2:
        if (param_0->unk79_4 == 4) func_8080000C_chlagoonufoint(param_0, 4);
        else if (func_800CEAD0(0)) func_8080000C_chlagoonufoint(param_0, 3);
        break;
    case 3:
        param_0->unk58 -= func_800D8FF8();
        if (param_0->unk58 < 0.0f) func_8080000C_chlagoonufoint(param_0, 1);
        break;
    }
    _glid_entrypoint_0(func_800BEA88(0), 0x11, _chlagoonufoint_entrypoint_5, param_0->unk0);
}

void func_808004D8_chlagoonufoint(Unk80132ED0 *param_0, s32 param_1)
{
    Actor *local_0;
    f32 local_1 = 4.0f;

    local_0 = func_80106790(param_0);
    local_0->unk79_4++;
    *(f32 *)((u8 *)local_0 + 0x28) = local_0->unk79_4 / local_1;
    *(f32 *)((u8 *)local_0 + 0x2C) = 0.33333334f;
    if (local_0->unk79_4 == 1) {
        if (!func_800DA298(0x9EE)) {
            _susubgame_entrypoint_6(local_0, func_80100094(local_0, 0), 0, 0x38, param_1);
            _subaddiedialog_entrypoint_11(local_0->unk0, 0xFF3, 0, local_0->position, 0x62);
        } else {
            func_8080000C_chlagoonufoint(local_0, 2);
        }
    }
}

s32 func_808005D0_chlagoonufoint(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0xB:
        if (param_2) {
            if (param_2 == 4) func_800DA3B8(0x9EF, 1);
            _susubgame_entrypoint_5((*(Actor * *)&param_0), func_80100094(param_0, 0), 5, 1, 0);
            return 4;
        }
        return 3;
    case 0x2E:
        switch (*(s16 *)&param_2) {
        case 0xFF4:
        case 0xFF5: _susubgame_entrypoint_4(param_0, func_80100094(param_0, 0)); break;
        case 0xFF3:
            func_800DA3B8(0x9EE, 1);
            func_8080000C_chlagoonufoint(param_0, 2);
            _susubgame_entrypoint_4(param_0, func_80100094(param_0, 0));
            break;
        }
        break;
    case 0x57:
        return _susubgame_entrypoint_3(param_0, func_80100094(param_0, 0), param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 16);
    default: return 0;
    }
    return 1;
}

int chlagoonufoint_entrypoint_1()
{
  return (int)&D_808019C0_chlagoonufoint;
}

int chlagoonufoint_entrypoint_2(void)
{
    return (int)&D_80801A28_chlagoonufoint;
}

int chlagoonufoint_entrypoint_3()
{
  return D_80801A90_chlagoonufoint;
}

void func_80800744_chlagoonufoint(s32 param_0) {
    s32 *var_a2;

    if (func_800DA298(0x9F0) != 0) {
        var_a2 = &D_80801AF4_chlagoonufoint;
    } else {
        var_a2 = &D_80801AD8_chlagoonufoint;
    }
    _subaddiedialog_entrypoint_7(param_0, param_0 + 4, var_a2);
}

int func_8080078C_chlagoonufoint()
{
    int local_0 = _subaddiefind_entrypoint_2(0x1C5, 0);
    return *(int *)local_0;
}

void func_808007B4_chlagoonufoint(Actor *param_0)
{
    s32 *local_0;

    local_0 = (s32 *)param_0;
    local_0[0x3C / 4] = func_8080078C_chlagoonufoint();
    if (_glcutDll_entrypoint_20() != 0)
    {
        func_80102424(param_0, 3);
    }
    if (((u32)(local_0[0x6C / 4] << 11) >> 20) == 0x1C7)
    {
        func_80101EE4(param_0, func_800DC0C0());
    }
}

void func_80800820_chlagoonufoint(Actor *param_0, f32 *param_1)
{
    if (param_0->unk5F == 0) {
        param_0->unk5F = func_800C4350(0, param_1, D_80801B10_chlagoonufoint);
    }
    func_800C4350(param_0->unk5F, param_1, NULL);
}

void func_80800878_chlagoonufoint(u8 *param_0, s32 param_1) {
    func_800C4104(param_1, 1.0f, 0x55F0, param_0 + 4, 500.0f, 1000.0f);
}

void func_808008C8_chlagoonufoint(Actor *param_0)
{
    f32 local_4;
    s32 *local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];

    func_8008FB10(param_0->position, 240.0f, 0.0f, 100.0f);
    switch (param_0->unk70_10) {
    case 1:
        func_80800744_chlagoonufoint(param_0);
    case 2:
        switch (param_0->unk6C_9) {
        case 0x1C6:
            if (func_80101E4C(param_0, D_80801B1C_chlagoonufoint)) {
                func_80800878_chlagoonufoint(param_0, 0x5C1);
            }
            break;
        case 0x1C7:
            if (func_80101E4C(param_0, D_80801B2C_chlagoonufoint)) {
                func_80800878_chlagoonufoint(param_0, 0x5BF);
            }
            break;
        default:
            if (func_80101E4C(param_0, D_80801B38_chlagoonufoint)) {
                func_80800878_chlagoonufoint(param_0, 0x5C0);
            }
            break;
        }
        if (func_800DA298(0x9F0)) {
            func_80102424(param_0, 3);
            if (param_0->unk6C_9 == 0x1C7) {
                func_80101EE4(param_0, func_800DC0C0());
                return;
            }
        }
        return;
    case 3:
        if (param_0->unk6C_9 == 0x1C7) {
            local_4 = func_80101F24(param_0);
            param_0->unk79_4 = 0;
            param_0->unk6C_0 = 0;
            if (local_4 > 0.05f && local_4 < 0.120000005f) {
                param_0->unk79_4 = 1;
            } else if (local_4 > 0.23f && local_4 < 0.3f) {
                param_0->unk6C_0 = 1;
            } else if ((local_4 > 0.39f && local_4 < 0.45000002f) ||
                       (local_4 > 0.48f && local_4 < 0.53999996f) ||
                       (local_4 > 0.58000004f && local_4 < 0.64f)) {
                param_0->unk6C_0 = 1;
                param_0->unk79_4 = param_0->unk6C_0;
            }
            local_0 = func_80100094(param_0, 0);
            if (!*local_0) {
                *local_0 = func_800C8A98();
                func_800C8E84(*local_0, D_80801B44_chlagoonufoint);
                func_800C8D4C(*local_0, D_80801B50_chlagoonufoint);
                func_800C8F64(*local_0, 1);
            }
            _subaddieskeleton_entrypoint_3(param_0->unk0, 4, local_2);
            _subaddieskeleton_entrypoint_3(param_0->unk0, 5, local_1);
            if (param_0->unk79_4 && param_0->unk6C_0) {
                func_800EFE50(local_3, local_1, local_2, 0.5f);
            } else if (param_0->unk79_4) {
                func_800EE7F8(local_3, local_1);
            } else {
                func_800EE7F8(local_3, local_2);
            }
            func_800C8CB8(*local_0, local_3);
            func_800C8FE0(*local_0, (param_0->unk79_4 || param_0->unk6C_0) ? 1 : 0);
            if (param_0->unk79_4 || param_0->unk6C_0) {
                func_80800820_chlagoonufoint(param_0, local_3);
            }
        }
        func_80800744_chlagoonufoint(param_0);
        break;
    }
}

void func_80800CD4_chlagoonufoint(u8 *param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  u32 local_2;
  func_800DF3E0();
 if (1) { } if (1) { }
  local_2 = ((u32) ((*((s32 *) (((s8 *) param_0) + 0x6C))) << 0xB)) >> 0x14;
  switch (local_2)
  {
    case 0x1C6:
      func_800DF744(3, 1U);
      func_800DF744(4, 1U);
      break;

    case 0x1C7:
      func_800DF744(6, 1U);
      func_800DF744(7, 1U);
      func_800DF744(8, ((u32) ((u8) (*((u8 *) (((s8 *) param_0) + 0x79))))) >> 4);
      func_800DF744(9, (*((s32 *) (((s8 *) param_0) + 0x6C))) & 0x1FF);
      break;

    default:
      func_800DF744(5, 1U);
      break;

  }

  local_0 = *((s32 *) (((s8 *) param_0) + 0x3C));
  if (local_0 != 0)
  {
    local_1 = (s32) ((((*((f32 *) (((s8 *) func_80106790(local_0)) + 0x24))) * 0.8f) + 0.2f) * 255.0f);
    func_800DF5D8(local_1, local_1, local_1, 0xFF);
  }
 ;
  func_80101870(param_0, param_1);
}

s32 func_80800E00_chlagoonufoint(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x2E:
        func_80102424(param_0, 1);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80801B58_chlagoonufoint, *(void **)((u8 *)param_0 + 0x38));
        break;
    default:
        return 0;
    }
    return 1;
}

int chlagoonufoint_entrypoint_4()
{
  return (int)&D_80801B68_chlagoonufoint;
}

void func_80800E80_chlagoonufoint(param_0, param_1) Actor *param_0; s32 param_1;
{

    switch (param_1) {
    case 2:
        param_0->unk6C_0 = 3;
        break;
    case 3:
        func_808004D8_chlagoonufoint(param_0->unk3C, param_0->unk0);
        *(f32 *)&param_0->actorData[5] = 0.3333333433f;
        break;
    case 4:
        *(f32 *)&param_0->actorData[3] = 1.0f;
        break;
    case 5:
        *(f32 *)&param_0->actorData[5] = -0.3333333433f;
        param_0->unk79_4 = 0;
        break;
    }
    ((LagoonUfoState *)param_0)->local_0 = param_1;
}

void func_80800F48_chlagoonufoint(u8 *param_0) {
    s32 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    (*(s32 *)((s8 *)(param_0) + (0x3C))) = func_8080078C_chlagoonufoint();
    (*(f32 *)((s8 *)(param_0) + (0x24))) = 0.0f;
    func_800EFD24(param_0 + 0x18);
    local_1 = func_800C8A98();
    *local_0 = local_1;
    func_800C8CB8(local_1, param_0 + 4);
    if ((func_800DA298(0x9F0) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_80800E80_chlagoonufoint(param_0, 4);
    }
}

void func_80800FD4_chlagoonufoint(Actor *param_0)
{
    f32 local_0;
    f32 local_7;
    s32 local_8;
    s32 *local_1;
    f32 local_2[2];
    s32 local_3[3];
    s32 local_4;
    s32 local_5;

    local_0 = func_800D8FF8();
    local_7 = ((f32 *)param_0->actorData)[3] * local_0;
    ((f32 *)param_0->actorData)[0] += 640.0f * local_7;
    ((f32 *)param_0->actorData)[1] += 3200.0f * local_7;
    ((f32 *)param_0->actorData)[2] += 2560.0f * local_7;
    for (local_8 = 0; local_8 < 3; local_8++) {
        if (((f32 *)param_0->actorData)[local_8] > 16384.0f) {
            ((f32 *)param_0->actorData)[local_8] -= 16384.0f;
        }
    }
    local_1 = func_80100094(param_0, 0);
    local_2[0] = ((f32 *)param_0->actorData)[3] * 350.0f + 150.0f;
    local_2[1] = ((f32 *)param_0->actorData)[3] * 350.0f + 250.0f;
    func_800F3214(local_3, D_80801BB0_chlagoonufoint, D_80801BBC_chlagoonufoint, ((f32 *)param_0->actorData)[3]);
    func_800C8D4C(*local_1, local_2);
    func_800C8E84(*local_1, local_3);
    switch (param_0->unk70_10) {
    case 2:
        if (!--param_0->unk6C_0) {
            func_80800E80_chlagoonufoint(param_0, 1);
        }
        break;
    case 3:
        ((f32 *)param_0->actorData)[3] += local_0 * ((f32 *)param_0->actorData)[5];
        if (((f32 *)param_0->actorData)[3] > 1.0f) {
            func_80800E80_chlagoonufoint(param_0, 4);
        }
        break;
    case 4:
        if (func_800DA298(0)) {
            func_80800E80_chlagoonufoint(param_0, 5);
        }
        break;
    case 5:
        ((f32 *)param_0->actorData)[3] += local_0 * ((f32 *)param_0->actorData)[5];
        if (((f32 *)param_0->actorData)[3] < 0.0f) {
            func_80800E80_chlagoonufoint(param_0, 1);
        }
        break;
    }
    local_4 = func_800BEA88(0);
    local_5 = param_0->unk74_7 * 4 - 4;
    _glid_entrypoint_0(local_4, local_5 + 1, _chlagoonufoint_entrypoint_5, param_0->unk0);

    _glid_entrypoint_0(local_4, local_5 + 2, _chlagoonufoint_entrypoint_6, param_0->unk0);
    _glid_entrypoint_0(local_4, local_5 + 3, _chlagoonufoint_entrypoint_6, param_0->unk0);
    _glid_entrypoint_0(local_4, local_5 + 4, _chlagoonufoint_entrypoint_6, param_0->unk0);
}

void func_808012A4_chlagoonufoint(Actor *param_0)
{
    if (param_0->unk70_10 == 1 && !func_800DA298(0)) {
        param_0->unk79_4++;
        func_800FC63C(0xE, 0x6D60);
        if (param_0->unk79_4 == D_80801940_chlagoonufoint[param_0->unk74_7 - 1]) {
            func_80800E80_chlagoonufoint(param_0, 3);
        } else {
            func_80800E80_chlagoonufoint(param_0, 2);
        }
    }
}

s32 func_8080135C_chlagoonufoint(s32 param_0, s32 param_1, s32 param_2) {
    if (param_1 == 0x40) {
        func_808012A4_chlagoonufoint(param_0);
    } else {
        return 0;
    }
    return 1;
}

void chlagoonufoint_entrypoint_5(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, s32 param_4)
{
    Vtx *local_0;
    f32 local_1;
    local_1 = *(f32 *)((u8 *)func_80106790(param_4) + 0x24) * 0.8f + 0.2f;
    for (local_0 = param_1 + param_3; param_1 < local_0; param_1++, param_2++) {
        param_2->v.cn[0] = (u32)((u32)param_1->v.cn[0] * local_1);
        param_2->v.cn[1] = (u32)((u32)param_1->v.cn[1] * local_1);
        param_2->v.cn[2] = (u32)((u32)param_1->v.cn[2] * local_1);
    }
}

void chlagoonufoint_entrypoint_6(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    Vtx *local_0;
    Actor *local_1;
    f32 local_2;
    s16 local_3;

    local_1 = (Actor *)func_80106790(param_4);
    local_2 = ((f32 *)local_1->actorData)[3] * 0.8f + 0.2f;
    local_3 = (s32)((f32 *)((u8 *)local_1 + 0x14))[(param_0 - 1) % 4];
    local_0 = param_1 + param_3;
    for (; param_1 < local_0; param_1++, param_2++) {
        param_2->v.cn[0] = (u32)((u32)param_1->v.cn[0] * local_2);
        param_2->v.cn[1] = (u32)((u32)param_1->v.cn[1] * local_2);
        param_2->v.cn[2] = (u32)((u32)param_1->v.cn[2] * local_2);
        param_2->v.tc[1] = param_1->v.tc[1] + local_3;
    }
}
