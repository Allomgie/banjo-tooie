#include "common.h"

extern int D_8080164C_chmasterjiggy;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 D_80801620_chmasterjiggy[];
extern int _subaddiedialog_entrypoint_11();
extern void func_8008FE68(f32 *);
extern s32 func_80090080(void);
extern s32 func_80016B30(s32, s32);
extern int D_808016F8_chmasterjiggy;
extern u8 D_80801790_chmasterjiggy[];
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern s32 func_800F1E6C(f32 *, f32 *, f32 *);
extern int _capod_entrypoint_14(void);
extern s32 D_8080179C_chmasterjiggy;
extern s32 D_808017E0_chmasterjiggy;
extern void *func_800B53A4(s32);
extern void *func_800BABB8(void *, f32 *, f32 *, f32, void *);
extern s32 _chmasterjiggy_entrypoint_2;
extern s32 func_800E15CC(s32, f32, f32);
extern void func_800E13F0(s32, f32);
extern s32 B_808017F0_chmasterjiggy;
extern s32 func_8010D5DC;
extern int func_80108A30(s32 param_0, s32 *param_1, f32 param_2, s32 param_3);
extern void func_8008FB10(f32 *, f32, f32, f32);
typedef union { s32 local_0; s16 local_1[2]; } MasterJiggyMessage37;
extern s16 D_80801740_chmasterjiggy[];
extern s16 D_80801750_chmasterjiggy[];
extern f32 func_800F1214(f32, f32, f32);
extern u8 D_808016E8_chmasterjiggy[];
extern u8 D_80801760_chmasterjiggy[];
extern u8 D_80801770_chmasterjiggy[];
extern u8 D_808016B0_chmasterjiggy[];
extern f32 func_800D8FF8(void);
extern f32 func_800F3780(f32, void *, s32);
extern void func_80018820(s32, f32, f32);
extern u8 D_80801690_chmasterjiggy[];
extern void func_800189A8(s32, void *, s32, f32, f32);
int func_808001D0_chmasterjiggy();
void func_80800220_chmasterjiggy();
void func_80800E58_chmasterjiggy();
extern void func_80101870(), func_80102EC0(), func_80107C2C(), func_8080000C_chmasterjiggy(), func_808001A8_chmasterjiggy(), func_808004FC_chmasterjiggy();
extern u8 D_808015C0_chmasterjiggy[];

int chmasterjiggy_entrypoint_0()
{
  return (int)&D_8080164C_chmasterjiggy;
}

void func_8080000C_chmasterjiggy(param_0) Actor *param_0;
{
    s32 local_0;
    local_0 = _gccubesearch_entrypoint_0(3, param_0);
    if (local_0) { _gspropctrl_entrypoint_11(local_0, param_0->actorData); }
    else { func_800EFA4C((f32 *)param_0->actorData, 1650.0f, 200.0f, 0.0f); }
    local_0 = _gccubesearch_entrypoint_0(4, param_0);
    if (local_0) { _gspropctrl_entrypoint_11(local_0, (u8 *)param_0 + 0x28); }
    else { func_800EFA4C((f32 *)((u8 *)param_0 + 0x28), 0.0f, 150.0f, 0.0f); }
    if (_glcutDll_entrypoint_20() || func_800A9C98()) {
        func_80800220_chmasterjiggy(param_0, 9);
    } else if (_sujiggy_entrypoint_13()) {
        switch (_sujiggy_entrypoint_14()) {
            case 0: func_808001D0_chmasterjiggy(param_0, 3); break;
            case 1: func_80800220_chmasterjiggy(param_0, 5); break;
            case 2: func_808001D0_chmasterjiggy(param_0, 9); break;
            case 3: func_80800220_chmasterjiggy(param_0, 1); break;
        }
    } else if (!func_800DA298(0x35B)) {
        func_80800220_chmasterjiggy(param_0, 2);
    } else if (!_sujiggy_entrypoint_17()) {
        func_80800220_chmasterjiggy(param_0, 8);
    }
    func_800FE734(0);
}

void func_808001A8_chmasterjiggy(s32 arg0) 
{
}
int func_808001B0_chmasterjiggy(s32 param_0)
{
  _sujiggy_entrypoint_8();
}

int func_808001D0_chmasterjiggy(param_0, param_1) s32 *param_0; s32 param_1; {
    u8 *temp_v0;

    temp_v0 = (u8 *)&D_80801620_chmasterjiggy + (param_1 * 4);
    _subaddiedialog_entrypoint_11(*param_0, (*(s16 *)((u8 *)(temp_v0) + 0)), (*(s16 *)((u8 *)(temp_v0) + 2)), param_0 + 1, 0x97);
}

void func_80800220_chmasterjiggy(param_0, param_1) u8 *param_0; s32 param_1; {
  s8 _sfpad[8];
    s32 local_0;

    func_80102424();
    switch (param_1) {
    case 2:
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F904(&func_8010D5DC, (*(s32 *)((s8 *)(param_0) + (0))));
        func_8008F938(1);
        func_8008F990(param_0 + 0x28, 0x43FA0000);
        _capod_entrypoint_13((*(s32 *)((s8 *)(param_0) + (0))), 0, 0x11, 0x60);
        return;
    case 3:
        func_800C0658();
        func_8008F8B0();
        func_8008F904(&func_8010D5DC, (*(s32 *)((s8 *)(param_0) + (0))));
        func_8008F9F8(param_0 + 0x18, 0x43960000);
        func_8008F938(0);
        func_80090658(1);
        return;
    case 4:
        func_800DBEFC(func_800BEC10(), 4, &local_0);
        func_80090734(4, &local_0);
        (*(f32 *)((s8 *)(param_0) + (0x58))) = 1.0f;
        return;
    case 5:
        func_80108A30(0x4B1, &B_808017F0_chmasterjiggy, 0.0f, 0x32);
        (*(f32 *)((s8 *)(param_0) + (0x34))) = 1.0f;
        return;
    case 9:
        func_80101EE4(param_0, 0x3F4CCCCD);
        
    default:
        return;
    }
}

int func_80800374_chmasterjiggy(param_0) Actor *param_0;
{
    f32 local_0[3];

    func_8008FE68(local_0);
    return local_0[0] >= 1576.0f && func_8008FD48() == 1;
}

int func_808003D4_chmasterjiggy(s32 param_0) {
    return func_80090080() && func_80016B30(0, 1) == 1;
}

int func_80800414_chmasterjiggy(Actor *param_0)
{
  if (func_80800374_chmasterjiggy())
  {
    if (!func_800DA298(0x533))
    {
      if (func_808001D0_chmasterjiggy(param_0, 3) != 0)
      {
        func_800DA544(0x533);
      }
    }
    if (func_808003D4_chmasterjiggy(param_0))
    {
      func_80800220_chmasterjiggy(param_0, 3);
    }
  }
}

void func_8080047C_chmasterjiggy(s32 param_0) {
    if ((func_800C0638() == 0) && (func_800DA298(0xD4E) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800D2498(0x10E, func_800D035C(1), 0);
        func_800D2498(0x106, _sujiggy_entrypoint_2(_sujiggy_entrypoint_0()), 0);
    }
}

void func_808004FC_chmasterjiggy(param_0) Actor *param_0;
{
    func_8008FB10(param_0->position, 200.0f, 0.0f, 100.0f);
    switch (param_0->unk70_10) {
    case 1:
        if (_subaddiedialog_entrypoint_6(param_0->position, (s32)param_0->rotation[1], 400, 60, 6)) {
            if (_sujiggy_entrypoint_21()) {
                func_808001D0_chmasterjiggy(param_0, 8);
            } else {
                func_808001D0_chmasterjiggy(param_0, 1);
            }
        } else {
            func_80800414_chmasterjiggy(param_0);
        }
        func_8080047C_chmasterjiggy(param_0);
        return;
    case 2: case 3:
        func_8080047C_chmasterjiggy(param_0);
        return;
    case 4:
        if (!func_800C0638() && func_800D9078(&param_0->unk58)) {
            func_808001B0_chmasterjiggy(param_0);
        }
        func_8080047C_chmasterjiggy(param_0);
        return;
    case 5:
        if (func_800D90A4(&((f32 *)param_0->actorData)[7])) {
            func_80800220_chmasterjiggy(param_0, 6);
        }
        break;
    case 6:
        if (func_80101DDC(param_0)) {
            func_80800220_chmasterjiggy(param_0, 7);
        }
        break;
    case 8:
        if (func_80800374_chmasterjiggy(param_0) && func_808003D4_chmasterjiggy(param_0)) {
            func_808001D0_chmasterjiggy(param_0, 5);
        } else if (_subaddiedialog_entrypoint_6(param_0->position, (s32)param_0->rotation[1], 400, 60, 6)) {
            func_808001D0_chmasterjiggy(param_0, 2);
        }
        func_8080047C_chmasterjiggy(param_0);
        return;
    case 9: case 10:
        if (func_80101DDC(param_0)) {
            func_80800220_chmasterjiggy(param_0, param_0->unk70_10 + 1);
        }
        break;
    }
}

int func_80800704_chmasterjiggy(s32 param_0[3], s32 param_1, s32 param_2)
{
  s32 local_0;
  int new_var;
  local_0 = _capod_entrypoint_14();
  new_var = 0 | (local_0 = 0);
  _capod_entrypoint_13(param_0[local_0], new_var, param_2, 0x2030 ^ 0);
  local_0 = 0;
}

void func_80800744_chmasterjiggy(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x14F6:
            _capod_entrypoint_14();
            func_800DA544(0x35B);
            func_80800220_chmasterjiggy(param_0, 1);
            break;
        case 0x14FC:
        case 0x155B:
        case 0x155C:
        case 0x155D:
        case 0x155E:
            func_80800220_chmasterjiggy(param_0, 1);
            break;
        case 0x1511:
            func_80800220_chmasterjiggy(param_0, 8);
            break;
    }
}

s32 func_808007F0_chmasterjiggy(Actor *param_0, s32 param_1, MasterJiggyMessage37 param_2)
{
    s32 tx;
    s32 ty;
    switch (param_1) {
        case 0x2E:
            ty = param_2.local_1[1];
            tx = param_2.local_1[0];
            func_80800744_chmasterjiggy(param_0, tx, ty);
            break;

        case 0x2F:
            func_80800704_chmasterjiggy(param_0, param_2.local_1[0], param_2.local_1[1]);
            break;

        case 0xB:
            return 3;
        case 0x32:
            if (param_0->unk70_10 == 3) func_80800220_chmasterjiggy(param_0, 4);
            else func_808001D0_chmasterjiggy(param_0, 0);
            break;

        case 0x31:
            func_80800220_chmasterjiggy(param_0, 8);
            if (_sujiggy_entrypoint_21()) {
                func_808001D0_chmasterjiggy(param_0, 7);
                return 1;
            }
            func_808001D0_chmasterjiggy(param_0, _sujiggy_entrypoint_17() ? 4 : 5);
            break;

        case 0x30:
            if (param_2.local_1[0] == 0x14F7) {
            } else if (param_2.local_1[0] == 0x14F8) {
            } else if (param_2.local_1[0] == 0x14F9) {
            } else if (param_2.local_1[0] == 0x14FA) {
            } else if (param_2.local_1[0] == 0x14FB) {
            }
            return _sujiggy_entrypoint_0() + 1;
        case 0x95:
            break;
        default:
            return 0;
    }
    return 1;
}

int chmasterjiggy_entrypoint_1()
{
    return (int)&D_808016F8_chmasterjiggy;
}

unsigned long long func_8080095C_chmasterjiggy(void *param_0)
{
    f32 *new_var;
    new_var = (f32 *)((char *)param_0 + 0x38);
    *new_var = 1.0f;
}

void func_8080096C_chmasterjiggy(Actor *param_0)
{
    s32 local_0;

    local_0 = param_0->unk64_20 != 0;
    if (local_0) local_0 = ((f32 *)param_0->actorData)[0] > 0.0f;
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_0, D_80801740_chmasterjiggy);
    _subaddieaudioloop_entrypoint_1(param_0, (s32)func_800F1214(((f32 *)param_0->actorData)[0], 5000.0f, 13000.0f));
    ((u8 *)param_0->actorData)[0xC] = _subaddieaudioloop_entrypoint_7(
        ((u8 *)param_0->actorData)[0xC], param_0->position,
        ((f32 *)param_0->actorData)[0] > 0.0f, D_80801750_chmasterjiggy, 0);
}

void func_80801488_chmasterjiggy();

void func_80801448_chmasterjiggy();

void func_808010E4_chmasterjiggy();

void func_80800A40_chmasterjiggy(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    local_0 = func_800D8FF8();
    local_1 = 0;
    if (((f32 *)param_0->actorData)[2] < 1.0f) {
        ((f32 *)param_0->actorData)[2] += local_0 * ((f32 *)param_0->actorData)[4];
        if (((f32 *)param_0->actorData)[2] >= 1.0f) {
            ((f32 *)param_0->actorData)[2] = 1.0f;
            local_1 = 1;
        }
    }
    func_808010E4_chmasterjiggy(param_0);
    func_80801448_chmasterjiggy(param_0);
    func_80801488_chmasterjiggy(param_0);
    func_8080096C_chmasterjiggy(param_0);
    switch (param_0->unk70_10) {
    case 2:
        if (func_800D90A4(&((f32 *)param_0->actorData)[7])) func_80800E58_chmasterjiggy(param_0, 3);
        break;
    case 3:
        ((f32 *)param_0->actorData)[0] = func_800F3780(((f32 *)param_0->actorData)[2], D_808016B0_chmasterjiggy, 7);
        if (local_1) func_80800E58_chmasterjiggy(param_0, 4);
        break;
    case 4:
        ((f32 *)param_0->actorData)[0] = func_800F3780(((f32 *)param_0->actorData)[2], D_80801760_chmasterjiggy, 2);
        func_80018820(0, 0.75f, 0.5f);
        if (local_1) func_808001D0_chmasterjiggy(param_0, 6);
        break;
    case 5:
        ((f32 *)param_0->actorData)[1] = func_800F3780(((f32 *)param_0->actorData)[2], D_80801770_chmasterjiggy, 4);
        if (local_1) {
            _capod_entrypoint_14();
            _sujiggy_entrypoint_15(_sujiggy_entrypoint_0() - 1, 1);
        }
        break;
    case 6:
        ((f32 *)param_0->actorData)[1] = func_800F3780(((f32 *)param_0->actorData)[2], D_808016E8_chmasterjiggy, 2);
        ((f32 *)param_0->actorData)[0] = ((f32 *)param_0->actorData)[1];
        break;
    }
}

void func_80800C08_chmasterjiggy(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2[3];
    f32 local_3;

    func_800E3A58(local_0);
    param_0->rotation[1] = local_0[1];
    *((u8 *)param_0 + 0x9B) = (u32)(*((f32 *)&param_0->actorData[0]) * 255.0f);
    if (param_0->unk64_20) {
        func_80101870(param_0, param_1);
    }
    if (*((f32 *)&param_0->actorData[1]) > 0.0f) {
        _sufade_entrypoint_0((s32)(*((f32 *)&param_0->actorData[1]) * 255.0f), D_80801790_chmasterjiggy);
    }
    if (*((f32 *)&param_0->actorData[0]) > 0.0f && param_0->unk64_20) {
        func_800E3980(local_2);
        if (func_800F1E6C(param_0->position, local_2, &local_1)) {
            local_3 = mlAbsF(func_800F1DCC(local_1, local_0[1])) / 25.0f;
            if (local_3 < 1.0f) {
                _sufade_entrypoint_0((s32)(*((f32 *)&param_0->actorData[0]) *
                    ((1.0f - local_3) * 100.0f)), D_80801790_chmasterjiggy);
            }
        }
    }
}

int func_80800DDC_chmasterjiggy(Actor *param_0)
{
  float new_var;
  s32 *local_0 = (s32 *) (((char *) param_0) + 0x30);
  new_var = 0.0f;
  if ((*((s32 *) (((char *) param_0) + 0x2C))) != 0)
  {
    func_800B5450(*((s32 *) (((char *) param_0) + 0x2C)));
    *((s32 *) (((char *) param_0) + 0x2C)) = 0;
  }
  if ((*((s32 *) (((char *) param_0) + 0x30))) != 0)
  {
    func_800E1720((*((s32 *) (((char *) param_0) + 0x30))) - 1);
    *((s32 *) (((char *) param_0) + 0x30)) = 0;
  }
  if ((*((u8 *) (((char *) param_0) + 0x24))) != 0)
  {
    *((u8 *) (((char *) param_0) + 0x24)) = _subaddieaudioloop_entrypoint_3(*((u8 *) (((char *) param_0) + 0x24)));
  }
  *((f32 *) (((char *) param_0) + 0x54)) = new_var;
}

void func_80800E58_chmasterjiggy(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0;

    func_80101FDC(param_0, param_1);
    *((f32 *)&param_0->actorData[2]) = 0.0f;
    if (param_1 > 0) {
        local_0 = ((f32 *)D_80801690_chmasterjiggy)[param_1];
        if (local_0 > 0.0f) {
            *((f32 *)&param_0->actorData[4]) = 1.0f / local_0;
        } else {
            *((f32 *)&param_0->actorData[4]) = 0.0f;
        }
    }
    switch (param_1) {
    case 2:
        _capod_entrypoint_13(param_0->unk0, 0, 9, 0x6030);
        param_0->unk64_20 = 0;
        *((f32 *)&param_0->actorData[7]) = 7.5f;
        break;
    case 3:
        param_0->unk64_20 = 0;
        func_800189A8(0, D_808016B0_chmasterjiggy, 7, local_0, 2.0f);
        param_0->unk54 = 0.0f;
        break;
    case 4:
        param_0->unk64_20 = 1;
        func_800FC660(0x1C);
        break;
    case 5:
        param_0->unk64_20 = 1;
        break;
    case 6:
        _capod_entrypoint_13(param_0->unk0, 0, 0x17, 0x2030);
        param_0->unk64_20 = 1;
        func_800189A8(0, D_808016E8_chmasterjiggy, 2, local_0, 2.0f);
        func_800FCAE0(0x1C, 0, 0x1BC);
        break;
    case 7:
        param_0->unk64_20 = 0;
        func_80101180(0x1E1, 0x31, 0);
        func_800FFAB0(param_0);
        _subaddieaudioloop_entrypoint_2(param_0);
        func_800FC74C(0x1C);
        break;
    }
}

int func_80801030_chmasterjiggy(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x95:
        if (param_0->unk70_10 == 1) {
            func_80800E58_chmasterjiggy(param_0, 2);
        } else {
            func_80800E58_chmasterjiggy(param_0, 6);
        }
        break;
    case 0x2E:
        func_80800E58_chmasterjiggy(param_0, 5);
        break;
    case 0xB:
        if (param_2 == 0x17) {
            _capod_entrypoint_14();
            func_80800E58_chmasterjiggy(param_0, 7);
            return 4;
        }
        return 3;
    default:
        return 0;
    }
    return 1;
}

void func_808010E4_chmasterjiggy(Actor *param_0)
{
    f32 local_0[3];

    if (((f32 *)param_0->actorData)[0] > 0.0f && param_0->unk64_20) {
        if (!param_0->actorData[5]) {
            func_800EE780(local_0, param_0->position, &D_808017E0_chmasterjiggy);
            param_0->actorData[5] = (u32)func_800B53A4(0x32);
            func_800B5534(param_0->actorData[5]);
            param_0->actorData[5] = (u32)func_800BABB8((void *)param_0->actorData[5],
                param_0->position, local_0, 1.0f, &D_8080179C_chmasterjiggy);
        }
        func_800BA22C(param_0->actorData[5], 4);
    }
}

void chmasterjiggy_entrypoint_2(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, s32 param_4)
{
    Actor *local_0;
    Vtx *local_1;

    local_0 = (Actor *)func_80106790(param_4);
    local_1 = param_1 + param_3;
    for (; param_1 < local_1; param_1++, param_2++) {
        param_2->v.cn[0] = (u32)((u32)param_1->v.cn[0] + ((f32 *)local_0->actorData)[0] * (255 - param_1->v.cn[0]));
        param_2->v.cn[1] = (u32)((u32)param_1->v.cn[0] + ((f32 *)local_0->actorData)[0] * (255 - param_1->v.cn[1]));
        param_2->v.cn[2] = (u32)((u32)param_1->v.cn[0] + ((f32 *)local_0->actorData)[0] * (255 - param_1->v.cn[2]));
    }
}

void func_80801448_chmasterjiggy(s32 *param_0) {
    _glid_entrypoint_0(func_800BEA88(0), 1, &_chmasterjiggy_entrypoint_2, *param_0);
}

void func_80801488_chmasterjiggy(Actor *param_0)
{
    if (*(f32 *)&param_0->actorData[0] > 0.0f) {
        if (param_0->actorData[6] == 0) param_0->actorData[6] = func_800E15CC(0, 0.0f, 1.0f) + 1;
        func_800E13F0(param_0->actorData[6] - 1, *(f32 *)&param_0->actorData[0] * 10.0f);
    } else if (param_0->actorData[6]) {
        func_800E1720(param_0->actorData[6] - 1);
        param_0->actorData[6] = 0;
    }
}
