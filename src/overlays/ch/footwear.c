#include "common.h"

typedef struct { u8 pad0[0x79]; u8 unk79_4 : 4; u8 unk79_0 : 4; } FootActor;
typedef struct { u8 pad0[0x1A]; u16 unk1A_5 : 11; u16 unk1A_0 : 5; u8 pad1C[0x24 - 0x1C]; u32 unk24_22 : 10; u32 unk24_0 : 22; } FootData;
extern s32 func_800DA298(s32);
extern s16 D_808006E6_chfootwear[][5];
extern s16 D_808006E0_chfootwear[][5];
extern s16 D_808006E2_chfootwear[][5];
extern s16 D_808006E8_chfootwear[][5];
extern s32 func_800F7C0C(s32, s32, f32);
extern void *D_80800788_chfootwear;
extern int D_808007D0_chfootwear;
extern int D_80800818_chfootwear;
extern s32 D_80800860_chfootwear[];
extern int D_808008A8_chfootwear;
extern s16 D_808006E4_chfootwear[][5];
extern u8 D_80800754_chfootwear[];
extern u8 D_80800768_chfootwear[];
extern u8 D_80800774_chfootwear[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern int func_800EFCD8(f32 *, f32, f32);
extern f32 func_80102D78(Actor *, f32 *);
extern int func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_800F549C(s32, s32);
extern int _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
void func_80800424_chfootwear();

void func_80800000_chfootwear(Actor *param_0)
{
  u32 local_0;
  local_0 = ((u32) ((*((s32 *) (((char *) param_0) + 0x6C))) << 0xB)) >> 0x14;
  switch (local_0)
  {
    case 0x21A:
      *((s32 *) (((char *) param_0) + 0x2C)) = 0;
      break;

    case 0x22E:
      *((s32 *) (((char *) param_0) + 0x2C)) = 1;
      break;

    case 0x3DB:
      *((s32 *) (((char *) param_0) + 0x2C)) = 2;
      break;

    case 0x16A:
      if ((!param_0) && (!param_0))
    {
    }
      *((s32 *) (((char *) param_0) + 0x2C)) = 3;
      break;

    case 0x471:
      *((s32 *) (((char *) param_0) + 0x2C)) = 4;
      break;

  }

  func_800EE7F8((f32 *) (((char *) param_0) + 0x18), (f32 *) (((char *) param_0) + 4), param_0);
  *((f32 *) (((char *) param_0) + 0x50)) = *((f32 *) (((char *) param_0) + 0x48));
  *((f32 *) (((char *) param_0) + 0x34)) = 0.0f;
  func_80800424_chfootwear(param_0, 1);
}

int func_80800644_chfootwear();

void func_808000B8_chfootwear(Actor *param_0)
{


    f32 local_0[3];
    f32 local_1[3];

    switch (((s32 *)param_0->actorData)[6]) {
    case 1:
        switch (((u32 *)param_0->actorData)[5]) {
        case 0:
        case 4:
            _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80800754_chfootwear, D_80800768_chfootwear);
            func_800EFCD8(local_0, ((f32 *)param_0->actorData)[7], 40.0f);
            local_0[1] = 0.0f;
            func_800EE780(param_0->position, (f32 *)param_0->actorData, local_0);
            ((f32 *)param_0->actorData)[7] += 70.0f * func_800D8FF8();
            param_0->rotation[1] = func_800136E4(((f32 *)param_0->actorData)[7] + 90.0f);
            break;
        case 1:
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800774_chfootwear, 0.25f);
            break;
        case 2:
        case 3:
            if (func_8010D23C()) {
                func_8010D254(local_1);
            } else {
                func_800E3980(local_1);
            }
            func_8010D600(local_1);
            param_0->unk54 = func_80102D78(param_0, local_1);
            func_80102BF8(param_0, 0.1f, 3.0f, 120.0f);
            break;
        }
        if (func_80800644_chfootwear(param_0, func_800F54E4()) || _glcutDll_entrypoint_20()) {
            ((s32 *)param_0->actorData)[4] = 255;
        } else {
            ((s32 *)param_0->actorData)[4] = 120;
        }
        if ((s32)(*(u8 *)((u8 *)param_0 + 0x9B)) < (((s32 *)param_0->actorData)[4]) - 5) {
            *(u8 *)((u8 *)param_0 + 0x9B) = (*(u8 *)((u8 *)param_0 + 0x9B)) + 5;
        } else if ((((s32 *)param_0->actorData)[4]) + 5 < (s32)(*(u8 *)((u8 *)param_0 + 0x9B))) {
            *(u8 *)((u8 *)param_0 + 0x9B) = (*(u8 *)((u8 *)param_0 + 0x9B)) - 5;
        } else {
            *(u8 *)((u8 *)param_0 + 0x9B) = (((s32 *)param_0->actorData)[4]);
        }
        break;
    case 2:
        if (func_800D90A4(&((f32 *)param_0->actorData)[3])) {
            func_80800424_chfootwear(param_0, D_808006E4_chfootwear[((u32 *)param_0->actorData)[5]][0] ? 3 : 4);
        }
        break;
    case 3:
        if (func_800F549C(param_0->unk79_4, D_808006E4_chfootwear[((u32 *)param_0->actorData)[5]][0]) == 0.0f) {
            func_80800424_chfootwear(param_0, 4);
        }
        break;
    case 4:
        if (func_800D90A4(&((f32 *)param_0->actorData)[3])) {
            func_80800424_chfootwear(param_0, 1);
        }
        break;
    }
}





int func_80800664_chfootwear();

s32 func_80800364_chfootwear(FootActor *param_0, s32 param_1, FootData *param_2)
{
    FootData *local_0;
    s32 local_1;

    if (param_1 == 0x3E) {
        local_0 = *(FootData **)&param_2;
        if (local_0->unk24_22 == 0) {
            if (func_800DA298(0x64F)) {
                if (func_80800664_chfootwear(param_0, local_0->unk1A_5)) {
                    param_0->unk79_4 = local_0->unk1A_5;
                    func_80800424_chfootwear(param_0, 2);
                    return 1;
                }
            }
        }
        return 0;
    }
    return 0;
}

void func_80800424_chfootwear(param_0, param_1) Actor *param_0; s32 param_1;
{
    switch (param_1) {
        case 1:
            _subaddieDll_entrypoint_4(param_0, 0);
            param_0->unk64_16 = 1;
            func_8010A590(param_0);
            break;
        case 2:
            func_8010A570(param_0);
            _fxsparkle_entrypoint_1(param_0->position, D_808006E6_chfootwear[*(s32 *)((u8 *)param_0 + 0x2C)][0]);
            _subaddieDll_entrypoint_4(param_0, 1);
            param_0->unk64_16 = 0;
            *(f32 *)((u8 *)param_0 + 0x24) = 1.0f;
            break;
        case 3:
            break;
        case 4:
            *(u8 *)((u8 *)param_0 + 0x9B) = 0;
            *(f32 *)((u8 *)param_0 + 0x24) = 1.0f;
            break;
    }
    *(s32 *)((u8 *)param_0 + 0x30) = param_1;
}

s32 func_8080050C_chfootwear(Actor *param_0, s32 param_1, s32 param_2)
{
    if (!param_0->unk64_16) {
        return 0;
    }
    if (func_800F6D24(param_1)) {
        return 0;
    }
    if (!func_800F65D0(param_1)) {
        return 0;
    }
    if (!func_800C6E38(D_808006E0_chfootwear[*(s32 *)((u8 *)param_0 + 0x2C)][0])) {
        if (param_2 && D_808006E8_chfootwear[*(s32 *)((u8 *)param_0 + 0x2C)][0]) {
            _sudialog_entrypoint_0(D_808006E8_chfootwear[*(s32 *)((u8 *)param_0 + 0x2C)][0], 0xE);
        }
        return 0;
    }
    if (!func_800F64A4(param_1, 0x501)) {
        return 0;
    }
    if (param_2 && func_800F7C0C(param_1,
        D_808006E2_chfootwear[*(s32 *)((u8 *)param_0 + 0x2C)][0], param_0->unk50) != 2) {
        return 0;
    }
    return 1;
}

int func_80800644_chfootwear(s32 param_0, s32 param_1)
{
  func_8080050C_chfootwear(param_0, param_1, 0);
}

int func_80800664_chfootwear(s32 arg0,s32 arg1)
{
    func_8080050C_chfootwear(arg0,arg1,0x1);
}

int chfootwear_entrypoint_0()
{
  return &D_80800788_chfootwear;
}

int chfootwear_entrypoint_1()
{
    return (int)&D_808007D0_chfootwear;
}

void *chfootwear_entrypoint_2()
{
    return &D_80800818_chfootwear;
}

int chfootwear_entrypoint_3()
{
  return D_80800860_chfootwear;
}

int chfootwear_entrypoint_4()
{
  return (int)&D_808008A8_chfootwear;
}
