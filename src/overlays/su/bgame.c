#include "common.h"

#define SG ((SubGameView *)sg)
extern u8 D_80800970_susubgame[];
extern s32 _gcdialogcamera_entrypoint_0(s32, s32);
typedef struct { u8 state; u8 pad1; s16 unk2; f32 unk4; f32 unk8[4]; } SubGameView;
extern s32 func_800D3948(void);
extern void *func_800A93E4(s32);
extern void *func_80110024(void *);
extern void _ncpod_entrypoint_12(void *, s32);
extern void _ncpod_entrypoint_22(void *, s32, f32 *);
extern void _ncpod_entrypoint_23(void *, s32, f32 *);
extern f32 func_8010CD50(Actor *, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _ncpod_entrypoint_24(void *, s32, f32 *);
extern void _ncpod_entrypoint_21(void *, s32, s32);
extern void func_8010D5DC();
extern void func_800F4A58(s32, f32 *, f32);
extern u8 unk4[];
extern u8 unk1[];
void susubgame_entrypoint_5();
void func_8080078C_susubgame();
int func_80800814_susubgame();
int func_808008DC_susubgame();
void susubgame_entrypoint_12();

void susubgame_entrypoint_0(s32 param_0, u8 *param_1, unsigned long param_2)
{
  u8 *new_var;
  *((s8 *) param_1) = 0;
  *((s16 *) (param_1 + 2)) = param_2;
  *((s8 *) (param_1 + 1)) = 0;
  *((s16 *) (param_1 + 4)) = 0x15;
  new_var = param_1;
  susubgame_entrypoint_12(new_var, &D_80800970_susubgame);
}

void susubgame_entrypoint_1(void *param_0, void *param_1, int param_2)
{
  u16 local_0 = 0;
  if (local_0 != ((long long) 0))
  {
    return;
  }
  *((u16 *) (((char *) param_1) + 4)) = param_2;
}

s32 susubgame_entrypoint_2(s32 param_0, u8 *param_1){
    return param_1[0];
}

int susubgame_entrypoint_3(void *param_0, u8 *param_1, s32 param_2, s32 param_3)
{
    if (_gcdialogcamera_entrypoint_0(param_2, param_3)) {
        if (*param_1 != 2) susubgame_entrypoint_5(param_0, param_1, 5, 1, 0);
        return 2;
    }
    return 1;
}

int susubgame_entrypoint_4(s32 param_0, u8 *param_1)
{
  u8 *local_0;
  s32 local_1;
  local_1 = 0;
  local_0 = param_1;
  if ((*param_1) != 0)
  {
    for (local_1 = 0; local_1 < 8; local_1++)
    {
      if (func_808008DC_susubgame(local_1 | 0) != 0)
      {
        _ncpod_entrypoint_17(func_800A93E4(local_1 | 0), 0);
      }
    }

    *param_1 = 0;
    if ((*(param_1 + 1)) != 0)
    {
      *param_1 = 0;
      *(param_1 + 1) = 0;
      _glcutDll_entrypoint_17();
    }
    return 1;
  }
  return 0;
}

void susubgame_entrypoint_5(this, sg, arg2, arg3, flags) Actor *this; u8 *sg; s32 arg2; s32 arg3; s32 flags;
{
    s32 i;
    void *a;
    void *p;
    f32 scaled[4];
    f32 vec[3];

    if (func_800D3948()) {
        flags |= 4;
    }
    switch (SG->state) {
    case 0:
        func_80800814_susubgame(this, sg, flags);
    case 1:
    case 3:
        for (i = 0; i < 4; i++) {
            scaled[i] = SG->unk8[i] * this->scale;
        }
        for (i = 0; i < 8; i++) {
            if (func_808008DC_susubgame(i)) {
                a = func_800A93E4(i);
                p = func_80110024(func_800A93E4(i));
                _ncpod_entrypoint_12(p, 1);
                _ncpod_entrypoint_22(p, 0, scaled);
                _ncpod_entrypoint_23(p, 0, this->position);
                if (SG->unk2 & 1) {
                    func_800EFA4C(vec, 0.0f, func_8010CD50(this, i), 0.0f);
                    _ncpod_entrypoint_24(p, 0, vec);
                } else {
                    _ncpod_entrypoint_24(p, 0, this->rotation);
                }
                func_8080078C_susubgame(a, i);
            }
        }
        SG->state = 2;
    case 2:
        for (i = 0; i < 8; i++) {
            if (func_808008DC_susubgame(i)) {
                _ncpod_entrypoint_21(func_800A93E4(i), arg2, arg3);
            }
        }
        break;
    }
}

void susubgame_entrypoint_6(s32 *param_0, u8 *param_1, s32 param_2, s32 param_3, s32 param_4)
{
    if (param_4 == 0) {
        param_4 = *param_0;
    }
    switch (*param_1) {
    case 0:
        func_80800814_susubgame(param_0, param_1, param_3);
        /* fallthrough */
    case 2:
    case 3:
        *param_1 = 1;
        /* fallthrough */
    case 1:
        _ncpod_entrypoint_20(func_800A93E4(func_800F54E4()), param_4, param_2, param_3 | 0x800);
        return;
    }
}

void susubgame_entrypoint_7(Actor *param_0, u8 *param_1, s32 *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    s32 local_0;

    if (param_4 == NULL) {
        param_4 = param_0->unk0;
    }
    switch (param_1[0]) {
        case 0:
            func_80800814_susubgame(param_0, param_1, param_3);
        case 2:
        case 3:
            param_1[0] = 1;
        case 1:
            for (local_0 = 0; local_0 < 8; local_0++) {
                if (func_808008DC_susubgame(local_0)) {
                    _ncpod_entrypoint_20(func_800A93E4(local_0), param_4, param_2[local_0], param_3 | 0x800);
                }
            }
            break;
    }
}

void susubgame_entrypoint_8(s32 *param_0, u8 *param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 local_0;

    if (param_4 == 0) {
        param_4 = *param_0;
    }
    switch (*param_1) {
        case 0:
            func_80800814_susubgame(param_0, param_1, param_3);
        case 1:
        case 2:
            *param_1 = 3;
        case 3:
            local_0 = 0;
            do {
                if (func_808008DC_susubgame(local_0)) {
                    _ncpod_entrypoint_32(func_800A93E4(local_0), param_4, param_2, param_3 | 0x800);
                }
                local_0++;
            } while (local_0 != 8);
            break;
    }
}

int susubgame_entrypoint_9()
{
  s32 local_0;
  for (local_0 = 0; local_0 < 8; local_0++)
  {
    if (func_808008DC_susubgame(local_0) && !func_800F6F00(local_0))
      return 0;
  }

  return 1;
}

int susubgame_entrypoint_10(Actor *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    f32 local_0[6];
    s32 local_1;
    s32 local_3;
    f32 local_2[3];

    local_1 = !func_800DA9E4(param_3, 1);
    local_3 = func_800F54E4();
    if (!_subaddiemarker_entrypoint_0(param_0, param_2, local_0, 1)) return 0;
    if (local_1) {
        func_800F608C(local_3, param_1);
        func_800F497C(local_3);
        func_800F49A8(local_3, 1);
        func_800F49D4(local_3, func_8010D5DC, param_0->unk0);
        func_800F4A58(local_3, local_0, 200.0f);
    } else {
        func_800EFA4C(local_2, 0.0f, local_0[4], 0.0f);
        func_800F608C(local_3, param_1);
        func_800F8294(local_3, local_0);
        func_800F832C(local_3, local_2);
        func_800F497C(local_3);
    }
    return local_1;
}

s32 susubgame_entrypoint_11(s32 param_0){
    if(func_800CEAA8(param_0) != 0){
        func_800CE88C(param_0, 0);
    }
}

void func_8080078C_susubgame(param_0, param_1) s32 param_0; s32 param_1;
{
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp20[4];
    s32 sp1C;

    sp1C = func_80110024(func_800A93E4(param_1));
    func_800F5A00(param_1, sp3C);
    func_800F5DC8(param_1, sp30);
    _ncpod_entrypoint_23(sp1C, 1, sp3C);
    _ncpod_entrypoint_24(sp1C, 1, sp30);
    _gcdialogcamera_entrypoint_7(param_1, sp20);
    _ncpod_entrypoint_22(sp1C, 1, sp20);
}

int func_80800814_susubgame(param_0, param_1, param_2) s32 param_0[2]; s32 *param_1; u32 param_2;
{
  s32 local_0;
  s32 local_1;
  Gtexture *local_2 = &*param_1;
  local_1 = 0;
  while (local_1 < 8)
  {
    if (func_808008DC_susubgame(local_1) != 0)
    {
      local_0 = func_800A93E4(local_1);
      _ncpod_entrypoint_16(local_0, param_0[0], (*(s16 *)((char *)(local_2) + 0x4)), param_2 | 0x800);
    }
    local_1++;
  }

  if (param_2 & 0x800)
  {
    (*(u8 *)((char *)(local_2) + 0x1)) = 0;
  }
  else
  {
    (*(u8 *)((char *)(local_2) + 0x1)) = 1;
  }
  if ((*(u8 *)((char *)(local_2) + 0x1)) != 0)
  {
    _glcutDll_entrypoint_6(func_800EA05C(), 0x79);
  }
}

int func_808008DC_susubgame(param_0) s32 param_0;
{
    if (func_800D3948()) {
        return func_800F6438(param_0) != 0 && func_800A9420(param_0) != 0;
    }
    return func_800F54E4() == param_0;
}

void susubgame_entrypoint_12(param_0, param_1) float param_0[4]; float param_1[4];
{
  param_0[2] = param_1[0];
  param_0[3] = param_1[1];
  param_0[4] = param_1[2];
  param_0[5] = param_1[3];
}
