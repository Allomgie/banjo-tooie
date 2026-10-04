#include "core2/1ED3900.h"

typedef struct { s16 unk0; s16 unk2; u8 unk4; u8 unk5; s16 unk12; s16 unk13; s8 unkA; s8 unkB; u8 unkF; u8 unkD; u8 unkE2; u8 unkF2; u8 unkE; u8 unk10; u8 unk11; u8 unk14; u8 unk15; u8 unk16; u8 unk17; u8 unk18; u8 unk19; u8 unk1A; u8 unk1B; } D_80123880_t;
extern u8 D_801357B0;
extern s32 _scinfobar_entrypoint_0(s32, s32, s32);
extern void _scinfobar_entrypoint_6(s32, s32);
typedef struct { s16 local_0; s16 local_1; u8 local_2; u8 local_3; s16 local_4; s16 local_5; u8 local_6; u8 local_7; u8 local_8; u8 local_9; s8 local_10; u8 local_11; u8 local_12; u8 local_13; u8 local_14; u8 local_15; u8 local_16; u8 local_17; u8 local_18; u8 local_19; s32 local_20; } D_80123880_type;
typedef struct { u8 pad[6]; s16 local_0, local_1; s8 local_2, local_3; u8 local_4; s8 local_5, local_6; u8 padF; u8 local_7, local_8; u8 pad12[2]; f32 local_9; void *local_10; } EntryFA2C0;
extern f32 func_800D8FF8(void);
extern void _scinfobar_entrypoint_2(void *);
extern s32 _scinfobar_entrypoint_21(void *);
extern s32 D_801239B4;
extern s32 D_80123998;
extern s32 D_80123D6C;
extern s8 D_80123DC0[10];
typedef struct { s16 field_0, field_2; u8 field_4, field_5; s16 field_6, field_8; s8 field_A, field_B; u8 field_C, field_D; s8 field_E; u8 field_F, field_10, field_11, field_12, field_13; f32 field_14; s32 field_18; } InfobarState;
extern s32 defrag(s32);
extern void _scinfobar_entrypoint_1(s32);
typedef struct { u8 pad[24]; int unk18; } local_struct;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; } Struct_80123880;
typedef struct { s16 local_0; s16 local_1; u8 local_2; u8 local_3; s16 local_4; s16 local_5; u8 local_6[4]; s8 local_7; u8 local_8[2]; u8 local_9; u8 local_10; u8 local_11; f32 local_12; s32 local_13; } local_type;
extern int _scinfobar_entrypoint_23(s32);
extern int _scinfobar_entrypoint_7(s32, s32);
extern s32 _scinfobar_entrypoint_16(s32);
extern int _scinfobar_entrypoint_22(s32);
typedef struct { s32 pad0[3]; s8 pad0C[2]; s8 unkE; s8 padF; s32 pad10[2]; s32 unk18; } S80123880;
typedef struct { u8 pad[0xC]; u8 local_0; u8 pad1; s8 local_1; u8 pad2[9]; s32 local_2; } EntryFA;
typedef union {
    InfobarState i;
    D_80123880_t t;
    D_80123880_type ty;
    EntryFA2C0 e2;
    EntryFA ea;
    S80123880 s;
    Struct_80123880 st;
    local_type lt;
    local_struct ls;
} Elem80123880;
extern Elem80123880 D_80123880[48];
extern u8 D_80123898[];
extern void _scinfobar_entrypoint_5(s32, s32);
int func_800FA874();

void func_800FA010()
{
    s32 local_0;
    f32 local_2 = 0.0f;
    for (local_0 = 0; local_0 < 48; local_0++)
    {
        D_80123880[local_0].t.unkE = 0;
    }

    for (local_0 = 0; local_0 < sizeof(D_80123DC0); local_0++)
    {
        local_2 += D_80123DC0[local_0];
    }

    for (local_0 = 0; local_0 < 48; local_0++)
    {
        if (D_80123880[local_0].t.unk4 & 1)
        {
            D_80123880[local_0].t.unkA = 0;
        }
        else
        {
            D_80123880[local_0].t.unkA = 1 - D_80123880[local_0].t.unk4;
        }
        if (D_80123880[local_0].t.unk4 & 1)
        {
            D_80123880[local_0].t.unkB = D_80123880[local_0].t.unk4 - 2;
        }
        else
        {
            D_80123880[local_0].t.unkB = 0;
        }
        D_80123880[local_0].t.unkF = 0;
        D_80123880[local_0].t.unk10 = 0;
        D_80123880[local_0].t.unk11 = 0;
        D_80123880[local_0].t.unk12 = (s16)(D_80123880[local_0].t.unk0 - (D_80123880[local_0].t.unkA * local_2));
        D_80123880[local_0].t.unk13 = (s16)(D_80123880[local_0].t.unk2 - (D_80123880[local_0].t.unkB * local_2));
    }

    D_801357B0 = 1;
}

void func_800FA130(s32 param_0, s32 param_1)
{
    if (param_1 != D_80123880[param_0].ty.local_8)
    {
        D_80123880[param_0].ty.local_8 = param_1;
        switch (param_1)
        {
            case 1:
                if (D_80123880[param_0].ty.local_20)
                {
                    break;
                }
                D_80123880[param_0].ty.local_20 = _scinfobar_entrypoint_0(D_80123880[param_0].ty.local_10, D_80123880[param_0].ty.local_3, D_80123880[param_0].ty.local_14);
                break;
            case 2:
                if (D_80123880[param_0].ty.local_4 != D_80123880[param_0].ty.local_0 || D_80123880[param_0].ty.local_5 != (*(s16 *)((char *)(&D_80123880[param_0].ty) + 2)))
                {
                    D_80123880[param_0].ty.local_4 = D_80123880[param_0].ty.local_0;
                    D_80123880[param_0].ty.local_5 = D_80123880[param_0].ty.local_1;
                }
                if (D_80123880[param_0].ty.local_13)
                {
                    break;
                }
                _scinfobar_entrypoint_6(D_80123880[param_0].ty.local_20, 1);
                break;
            case 3:
                _scinfobar_entrypoint_6(D_80123880[param_0].ty.local_20, 0);
                break;
            case 0:
                if (D_80123880[param_0].ty.local_20)
                {
                    _scinfobar_entrypoint_1(D_80123880[param_0].ty.local_20);
                    D_80123880[param_0].ty.local_20 = 0;
                }
                break;
            default:
                break;
        }
    }
}

void func_800FA240(s32 param_0, long param_1)
{
  u8 *temp_v0;
  temp_v0 = ((u8 *) ((u8 *) D_80123880)) + (param_0 * 28);
  temp_v0[0x10] = param_1;
  switch (param_1)
  {
    case 0:
      if (temp_v0[0xC] != 0)
    {
      func_800FA130(param_0, 3);
      return;
    }
      return;

    case 1:
      if (temp_v0[0xC] != 2)
    {
      func_800FA130(param_0, 1);
    }
      break;

  }

}

void func_800FA2C0(void)
{
    s32 local_0;
    f32 local_1[1];
    s32 local_2;
    local_1[0] = func_800D8FF8();
    for (local_0 = 0; local_0 < 48; local_0++) {
        if (D_80123880[local_0].e2.local_7 == 1 && func_800FA874(local_0, D_80123880[local_0].e2.local_6)) {
            if (D_80123880[local_0].e2.local_9 >= 0.0f) {
                D_80123880[local_0].e2.local_9 -= local_1[0];
                if (D_80123880[local_0].e2.local_9 < 0.0f) {
                    D_80123880[local_0].e2.local_9 = 0.0f;
                    func_800FA240(local_0, 0);
                }
            }
        }
    }
    for (local_0 = 0; local_0 < 48; local_0++) {
        if (D_80123880[local_0].e2.local_10) _scinfobar_entrypoint_2(D_80123880[local_0].e2.local_10);
        switch (D_80123880[local_0].e2.local_4) {
        case 1:
            if ((u32)D_80123880[local_0].e2.local_5 < 10) {
                local_2 = D_80123DC0[D_80123880[local_0].e2.local_5];
                D_80123880[local_0].e2.local_0 += D_80123880[local_0].e2.local_2 * local_2;
                D_80123880[local_0].e2.local_1 += D_80123880[local_0].e2.local_3 * local_2;
                D_80123880[local_0].e2.local_5++;
            }
            if ((u32)D_80123880[local_0].e2.local_5 >= 10) {
                D_80123880[local_0].e2.local_5 = 10;
                func_800FA130(local_0, 2);
            }
            break;
        case 2:
            if (_scinfobar_entrypoint_21(D_80123880[local_0].e2.local_10) && !D_80123880[local_0].e2.local_8) {
                _scinfobar_entrypoint_6(D_80123880[local_0].e2.local_10, 1);
            }
            break;
        case 3:
            if (_scinfobar_entrypoint_21(D_80123880[local_0].e2.local_10)) {
                if (D_80123880[local_0].e2.local_5 > 0) {
                    D_80123880[local_0].e2.local_5--;
                    local_2 = D_80123DC0[D_80123880[local_0].e2.local_5];
                    D_80123880[local_0].e2.local_0 -= D_80123880[local_0].e2.local_2 * local_2;
                    D_80123880[local_0].e2.local_1 -= D_80123880[local_0].e2.local_3 * local_2;
                }
                if (D_80123880[local_0].e2.local_5 <= 0) {
                    D_80123880[local_0].e2.local_5 = 0;
                    func_800FA130(local_0, 0);
                }
            }
            break;
        }
    }
}

void func_800FA508(s32 param_0) {
    InfobarState *local_0;
    s32 local_1;
    s32 local_3;
    if (D_801357B0) {
        local_1 = func_800A9C98() || func_800DB9B0();
        for (local_3 = 0; local_3 < 48; local_3++) {
            local_0 = &D_80123880[local_3];
            if (local_0->field_18) {
                s32 local_2 = local_0 != (InfobarState *)&D_801239B4 && local_0 != (InfobarState *)&D_80123998 && local_0 != (InfobarState *)&D_80123D6C;
                if (!local_1 || !local_2) _scinfobar_entrypoint_24(param_0, local_0->field_18, local_0->field_6, local_0->field_8);
            }
        }
    }
}

void func_800FA608(void)
{
  s32 *s0;
  s32 temp_a0;
 s0 = ((s32 *) D_80123880); do {
    temp_a0 = s0[6];
    if (temp_a0 != 0)
    {
      s0[6] = defrag(temp_a0);
    }
    s0 += 7;
  }
  while (s0 != ((s32 *) &D_80123DC0));
}

void func_800FA660()
{
  int new_var;
  local_struct *local_0;
  u8 *local_1;
 local_1 = ((u8 *) &D_80123DC0); local_0 = ((local_struct *) D_80123880);
  do
  {
    new_var = local_0->unk18;
    if (new_var != 0)
    {
      _scinfobar_entrypoint_1((void *) new_var);
      local_0->unk18 = 0;
    }
    local_0 += 1;
  }
  while (((u8 *) local_0) != local_1);
}

void func_800FA6B8(s32 param_0, s32 param_1, s32 param_2)
{
    _scinfobar_entrypoint_3(D_80123880[param_0].st.f18, param_1);
    _scinfobar_entrypoint_8(D_80123880[param_0].st.f18, param_2);
}

int func_800FA708(u32 param_0, s32 param_1, s32 param_2, u32 param_3) {
    local_type *local_0 = &D_80123880[param_1].lt;
    if (param_2 != local_0->local_7 || param_3 != local_0->local_10) {
        if (local_0->local_13 && _scinfobar_entrypoint_23(local_0->local_13)) return 0;
        if (local_0->local_13 && !_scinfobar_entrypoint_7(local_0->local_13, param_2)) return 0;
    }
    D_80123880[param_1].lt.local_7 = param_2;
    D_80123880[param_1].lt.local_9 = 0;
    D_80123880[param_1].lt.local_10 = param_3;
    func_800FA240(param_1, 1);
    local_0->local_12 = 2.0f;
    if (_scinfobar_entrypoint_16(local_0->local_13) != param_2 && _scinfobar_entrypoint_22(local_0->local_13)) {
        _scinfobar_entrypoint_6(local_0->local_13, 0);
    }
    func_800FA6B8(param_1, param_3, param_0);
    return 1;
}

s32 func_800FA818(s32 param_0, s32 param_1) {
    S80123880 *local_0;
    local_0 = &D_80123880[param_0].s;
    if (local_0->unk18 == 0 || param_1 != local_0->unkE) {
        return 0;
    }
    func_800FA240(param_0, 0);
    return 1;
}

int func_800FA874(param_0, param_1) s32 param_0; s32 param_1; {
    InfobarState *local_0 = &D_80123880[param_0];
    if (!local_0->field_18 || param_1 != local_0->field_E) return 0;
    return local_0->field_C == 2 && _scinfobar_entrypoint_22(local_0->field_18);
}

s32 func_800FA8E8(s32 param_0, s32 param_1)
{
  s8 *new_var;
  u8 *local_0;
  local_0 = ((s32 *) D_80123880);
  local_0 = (param_0 * 0x1C) + local_0;
  new_var = (s8 *) local_0;
  if (((*((s32 *) (((s8 *) local_0) + 0x18))) == 0) || (param_1 != (*((s8 *) (new_var + 0xE)))))
  {
    return -1;
  }
  return (*((u8 *) (((s8 *) local_0) + 0xC))) != 0;
}

int func_800FA934(s32 param_0, s32 param_1) {
    /* HEADER DEPENDENCY: Also push data/header/include/core2/1ED3900.h; this function returns int, not s32 (long). */
    EntryFA *local_0 = &D_80123880[param_0].ea;
    s32 local_1 = local_0->local_2;
    if (!local_1 || param_1 != local_0->local_1) return -1;
    return local_0->local_0 == 2 && _scinfobar_entrypoint_21(local_1) != 0;
}

int func_800FA9A8(int param_0)
{
  if (1)
  {
    D_801357B0 = param_0;
  }
  do
  {
  }
  while (0);
}

void func_800FA9B4(s32 param_0, s32 param_1)
{
    s32 local_0;
    void *local_1;

    local_0 = param_0 * 28;
    local_1 = *(void **)((char *)&D_80123898 + local_0);
    if (local_1 != NULL)
    {
        _scinfobar_entrypoint_9((s32)local_1, param_1);
    }
}

void func_800FA9F4(s32 param_0, s32 param_1)
{
    s32 local_0;
    void *local_1;

    local_0 = param_0 * 28;
    local_1 = *(void **)((char *)&D_80123898 + local_0);
    if (local_1 != NULL)
    {
        _scinfobar_entrypoint_4((s32)local_1, param_1);
    }
}

void func_800FAA34(s32 param_0)
{
  s32 local_0;
  local_0 = *(s32*)&((s8 *) D_80123898)[param_0 * 0x1C];
  if (local_0 != 0)
  {
    _scinfobar_entrypoint_5(local_0, 1);
  }
}

void func_800FAA74(s32 param_0)
{
  s32 local_0;
  local_0 = *(s32*)&((s8 *) D_80123898)[param_0 * 0x1C];
  if (local_0 != 0)
  {
    _scinfobar_entrypoint_5(local_0, 2);
  }
}

int func_800FAAB4(s32 param_0, s32 param_1) {
    InfobarState *local_0 = &D_80123880[param_0];
    if (!local_0->field_18) return 0;
    local_0->field_E = param_1;
    func_800FA240(param_0, 1);
    if (!_scinfobar_entrypoint_7(local_0->field_18, param_1)) return 0;
    local_0->field_14 = 2.0f;
    _scinfobar_entrypoint_6(local_0->field_18, 0);
    local_0->field_11 = 1;
    return 1;
}
