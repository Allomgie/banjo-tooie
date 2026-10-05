#include "common.h"

extern f32 func_800DC178(f32, f32);
typedef struct { s32 field_0, field_4, field_8, field_C; s32 field_10[2]; s32 field_18, field_1C, field_20, field_24; u8 field_28, field_29, field_2A, field_2B; } MapRecord;
typedef struct { MapRecord record[2]; u8 pad_58[0x1F]; u8 field_77; u8 pad_78[13]; u8 field_85, field_86, field_87; u8 pad_88[0x128]; s32 field_1B0; } MapState;
void func_800DF428(float param_0);
extern void _gcmapsects_entrypoint_17(s32*);
extern s32 D_801285B4[];
extern u8 D_80128627;
extern int D_801285BC[];
typedef struct { u8 pad0[0x14]; void *unk14; u8 pad18[0x14]; } E_BEB98;
extern int D_801285D0[];
extern s32 D_80128734;
extern s32 D_80128730;
extern s32 D_8012873C;
extern s32 D_80128748;
extern s32 D_80128754;
extern void func_800EFD24(f32 *);
extern int func_800AD2C8(s32, s32, s32, s32, f32 *, s32, s32, f32);
extern int _gcmapsects_entrypoint_20(void *, s32, s32, s32, s32, f32);
extern s32 func_800AD894(s32, s32, s32, s32, s32, s32 *, f32);
extern s32 _gcmapsects_entrypoint_21(s32 *, s32, s32, s32, f32);
extern s32 func_800AC638(s32, s32, s32, s32, f32, s32, s32, s32);
extern s32 _gcmapsects_entrypoint_23(void *, s32, s32, f32, s32, s32, s32);
extern void _gcmapDll_entrypoint_3(void*);
extern void func_800C6A28(void*, void*, void*, void*);
extern u8 D_801285B1;
extern u8 D_801285B2;
typedef struct { u8 pad0[4]; s32 unk4; u8 pad8[0x23]; u8 unk2B; } E_BF4DC;
extern void _idworldmake_entrypoint_6(s32, s32, s32);
void *func_800DC060(void *);
void *func_800EE5D8(void *);
void *func_800F9F90(void *, void *);
void *defrag(void *);
extern u8 D_80128634;
extern int _gcmapsects_entrypoint_24();
typedef struct {s32 local_0[11];} local_record;
extern s32 _dbvpl_entrypoint_0(s32, s32);
int func_800BECE0();
s32 func_800BEF00();
void func_800BF774();

typedef struct { u8 _0[4]; void *f2; void *f6; u8 _1[0xc]; void *f11; void *f4; u8 _2[0x10]; void *f3; void *f7; u8 _3[0xc]; void *f12; void *f5; u8 _4[0x1c]; void *f8; u8 _5[0xb]; u8 f10; u8 _6[0x100]; void *f0; void *f1; void *f9; } D_801285B0_unk;

typedef union {
    MapState MapState;
    D_801285B0_unk D_801285B0_unk;
    s32 raw;
    struct { struct { s32 local_0[11]; } local_0[3]; s8 local_1; } BF8E4;
    s8 b[1];
    u8 u[1];
} Union_D_801285B0;
extern Union_D_801285B0 D_801285B0;
extern s32 D_80128728;
extern s32 D_8012872C;
extern s32 D_80128760;


f32 func_800BE600(f32 *param_0, s32 param_1) {
    s32 local_6;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3, local_4, local_5;
    local_1[0] = param_0[0];
    local_1[1] = param_0[1];
    local_1[2] = param_0[2];
    local_1[1] += 200.0f;
    local_2[0] = param_0[0];
    local_2[1] = param_0[1];
    local_2[2] = param_0[2];
    local_2[1] -= 2000.0f;
    if (func_800BEF00(local_1, local_2, local_0, param_1)) return local_2[1];
    for (local_3 = 150, local_4 = 1000; local_4 < 51000; local_3 += 300, local_4 += 2000) {
        local_1[0] = param_0[0];
        local_1[1] = param_0[1];
        local_1[2] = param_0[2];
        local_1[0] += func_800DC178(-1.0f, 1.0f);
        local_1[1] += local_3;
        local_1[2] += func_800DC178(-1.0f, 1.0f);
        local_2[0] = param_0[0];
        local_2[1] = param_0[1];
        local_2[2] = param_0[2];
        local_2[0] += func_800DC178(-1.0f, 1.0f);
        local_2[1] -= local_4;
        local_2[2] += func_800DC178(-1.0f, 1.0f);
        if (func_800BEF00(local_1, local_2, local_0, param_1)) return local_2[1];
    }
    return 0.0f;
}

void func_800BE7F8(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;
    s32 local_3;
    s32 local_4;
    s32 local_6;
    MapRecord *local_5;

    local_5 = &D_801285B0.MapState.record[param_1];
    if ((local_5->field_C != 0) && (local_5->field_2B != 0)) {
        func_800BF774();
        func_800DF738(D_80128728);
        if (local_5 == &D_801285B0.MapState.record[0]) {
            func_800DF83C(D_8012872C);
        }
        if (local_5 != &D_801285B0.MapState.record[0]) {
            local_0 = 2;
        } else {
            local_0 = 1;
        }
        func_800DF830(local_0);
        local_3 = local_5->field_28;
        if (local_3 != 0) {
            func_800DF7E8(local_3);
        }
        local_6 = (s32)((MapState *) &D_801285B0.raw);
        func_800DF5D8(*(u8 *)(local_6 + 0x85), *(u8 *)(local_6 + 0x86), *(u8 *)(local_6 + 0x87), 0xFF);
        func_800DF7DC(local_5->field_24);
        func_800DF818(local_5->field_10[local_5->field_29]);
        func_800DF428(29999.0f);
        func_800DF440(0);
        func_800DF4B0(1);
        func_800DE448(0, 0, 0x3F800000, 0, local_5->field_C);
        local_1 = local_5->field_1C;
        if (local_1 != 0) {
            _vpmodule_entrypoint_3(local_1, local_5->field_18, local_5->field_10[local_5->field_29]);
        }
        if ((local_5->field_10[1] != 0) && (func_800EA340() != 0)) {
            if (local_5->field_4 != 0) {
                _glid_entrypoint_6(local_5->field_4, local_5->field_10[local_5->field_29]);
            }
            local_5->field_29 ^= 1;
            if (local_5->field_4 != 0) {
                _glid_entrypoint_5(local_5->field_4, local_5->field_10[local_5->field_29]);
            }
        }
    }
}

void func_800BE9B0()
{
  if ((unsigned char) ((s8 *) (D_801285B0.u))[0x77])
  {
    _gcmapsects_entrypoint_17(D_801285B0.u);
  }
}

s32 func_800BE9E4(Actor *this)
{
 ;
  func_800BE7F8(this, 0);
  if ((unsigned char) (*(u8 *)((char *)(((int *) &D_801285B0.raw)) + 119)))
  {
    _gcmapsects_entrypoint_18(((int *) &D_801285B0.raw), this);
  }
}

int func_800BEA24(Actor *param_0)
{
    func_800BE7F8(param_0, 1);
    if (((u8 *)((int *) &D_801285B0.raw))[0x77] != 0) {
        _gcmapsects_entrypoint_19(((int *) &D_801285B0.raw), param_0);
    }
}

void func_800BEA64(s32 param_0)
{
  func_800BE600(param_0, 0x20020);
}

s32 func_800BEA88(s32 arg0)
{
  return *(s32 *)((char *)D_801285B4 + arg0 * 0x2C);
}

int func_800BEAAC(u32 param_0, u32 param_1)
{
  if (D_80128627 != 0)
  {
    return _gcmapsects_entrypoint_6(&D_801285B0.raw, param_0 | param_0, param_1 | param_1);
  }
  return 0;
}

void func_800BEAF4()
{
  if (((u8*)&D_801285B0.raw)[0x77])
  {
    _gcmapsects_entrypoint_8(D_801285B0.u);
  }
}

s32 func_800BEB28(s32 param_0)
{
  char *new_var2;
  int new_var3;
  s32 *new_var4;
  s32 *new_var;
  new_var3 = param_0 * 0x2C;
  new_var2 = ((char *) D_801285BC) + new_var3;
  new_var4 = (s32 *) new_var2;
  ;
  return *new_var4;
  new_var3 = new_var3 * 4;
}

s32 func_800BEB4C()
{
    return D_80128760;
}

int func_800BEB58(s32 param_0)
{
  D_80128760 = param_0;
}

s32 func_800BEB64(s32 param_0)
{
  u8 *local_0;
  s32 offset;
  local_0 = ((u8 *) (D_801285B0.u)) + (param_0 * 0x2C);
  offset = (local_0[0x29] & 0xFFu) * 4;
  return *((s32 *) ((local_0 + offset) + 0x10));
}

s32 func_800BEB98(s32 param_0) {
    s32 rv = 1;
    return (((E_BEB98 *) &D_801285B0.raw)[param_0].unk14 != 0) ? 2 : rv;
}

int func_800BEBD4(s32 param_0)
{
  func_800B27A0(*(s32 *)((u8 *) D_801285BC + param_0 * 44));
}

s32 func_800BEC10()
{
    return D_80128728;
}

s32 func_800BEC1C()
{
    return D_8012872C;
}

int func_800BEC28(s32 param_0)
{
  return *(s32 *)((u8 *) D_801285D0 + param_0 * 44);
}

void func_800BEC4C(s32 *param_0, s32 *param_1, s32 param_2) {
    s32 i;
    func_800BECE0(param_0, param_1, param_2);
    func_800E37E8(param_0, param_1, param_2);
    for (i = 0; i < 3; i++) {
        param_0[i] = D_801285B0.b[i + 0x5E] + param_0[i];
        param_1[i] = D_801285B0.b[i + 0x61] + param_1[i];
    }
}

float func_800BECCC(void)
{
    return (float)D_80128734;
}

int func_800BECE0(param_0, param_1) s32 param_0; s32 param_1;
{
  func_800EE830(param_0, &D_80128730);
  func_800EE830(param_1, &D_8012873C);
}

int func_800BED18(s32 param_0, s32 param_1)
{
  func_800EE830(param_0, &D_80128748);
  func_800EE830(param_1, &D_80128754);
}

void func_800BED50(s32 arg0)
{
    func_800BE600(arg0,0x1F00);
}

int func_800BED70(s32 param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4) {
    f32 local_0[3];
    int local_1;
    if (D_801285B0.u[0x2A]) {
        func_800EFD24(local_0);
        local_1 = func_800AD2C8(*(s32 *)D_801285B0.u, ((s32 *)(D_801285B0.u + 0x10))[D_801285B0.u[0x29]], param_0, param_1, local_0, param_2, param_3, param_4);
        if (local_1) return local_1;
    }
    if (D_801285B0.u[0x77]) return _gcmapsects_entrypoint_20(D_801285B0.u, param_0, param_1, param_2, param_3, param_4);
    return 0;
}

s32 func_800BEE40(s32 param_0, s32 param_1, s32 param_2, f32 param_3)
{
  char *new_var2;
  u8 *new_var;
  s32 local_0;
  s32 sp30;
  if (D_801285B0.u[0x2A] != 0)
  {
    ;
    func_800EFD24(&sp30);
    if (func_800AD894(*((s32 *) D_801285B0.u), *((s32 *) ((D_801285B0.u + (D_801285B0.u[0x29] * 4)) + (local_0 = 0x10))), param_0, param_1, param_2, &sp30, param_3) != 0)
    {
      return 1;
    }
  }
  new_var = D_801285B0.u;
  new_var2 = (char *) (&sp30);
  if (new_var[0x77] != 0)
  {
    return _gcmapsects_entrypoint_21(D_801285B0.u, *((s32 *) (((char *) (&sp30)) + 0x10)), *((s32 *) (((char *) (&sp30)) + 0x14)), *((s32 *) (new_var2 + 0x18)), param_3);
  }
  return 0;
}

s32 func_800BEF00(param_0, param_1, param_2, param_3) f32 * param_0; f32 * param_1; f32 * param_2; s32 param_3; {
    s32 local_3;
    s32 local_2;

    local_3 = 0;
    D_801285B0.MapState.field_1B0 = 0;
    if (D_801285B0.MapState.record[1].field_2A != 0) {
        if ((param_3 & 0x1F00) != 0x1F00) {
            if (D_801285B0.MapState.field_77 != 0) {
                local_3 = _gcmapsects_entrypoint_22(((MapState *) &D_801285B0.raw), param_0, param_1, param_2, param_3);
            }
            if ((local_3 == 0) && (D_801285B0.MapState.record[0].field_2A != 0)) {
                local_3 = func_800AB0BC(D_801285B0.MapState.record[0].field_0, D_801285B0.MapState.record[0].field_10[D_801285B0.MapState.record[0].field_29], param_0, param_1, param_2, param_3);
            }
        }
        local_2 = func_800AB0BC(D_801285B0.MapState.record[1].field_0, D_801285B0.MapState.record[1].field_10[D_801285B0.MapState.record[1].field_29], param_0, param_1, param_2, param_3);
        if (local_2 != 0) {
            D_801285B0.MapState.field_1B0 = (s32) D_801285B0.MapState.record[1].field_C;
            return local_2;
        }
        if (D_801285B0.MapState.field_77 != 0) {
                local_2 = _gcmapsects_entrypoint_22(((MapState *) &D_801285B0.raw), param_0, param_1, param_2, param_3);
            if (local_2 != 0) {
                return local_2;
            }
        }
        if (local_3 != 0) {
            D_801285B0.MapState.field_1B0 = (s32) D_801285B0.MapState.record[0].field_C;
        }
        return local_3;
    }
    if (D_801285B0.MapState.field_77 != 0) {
        local_3 = _gcmapsects_entrypoint_22(((MapState *) &D_801285B0.raw), param_0, param_1, param_2, param_3);
    }
    if ((local_3 == 0) && (D_801285B0.MapState.record[0].field_2A != 0)) {
        local_3 = func_800AB0BC(D_801285B0.MapState.record[0].field_0, D_801285B0.MapState.record[0].field_10[D_801285B0.MapState.record[0].field_29], param_0, param_1, param_2, param_3);
    }
    if (local_3 != 0) {
        D_801285B0.MapState.field_1B0 = (s32) D_801285B0.MapState.record[0].field_C;
        return local_3;
    }
    return 0;
}

s32 func_800BF0E0(s32 param_0, s32 param_1, f32 param_2, s32 param_3, s32 param_4, s32 param_5) {
    s32 local_0 = 0;
    s32 local_1;
    D_801285B0.MapState.field_1B0 = 0;
    if (D_801285B0.MapState.field_77) {
        local_0 = _gcmapsects_entrypoint_23(((MapState *) &D_801285B0.raw), param_0, param_1, param_2, param_3, param_4, param_5);
    }
    if (!local_0 &&D_801285B0.MapState.record[0].field_2A) {
        local_0 = func_800AC638(D_801285B0.MapState.record[0].field_0, D_801285B0.MapState.record[0].field_10[D_801285B0.MapState.record[0].field_29], param_0, param_1, param_2, param_3, param_4, param_5);
    }
    if (local_0) D_801285B0.MapState.field_1B0 = D_801285B0.MapState.record[0].field_C;
    if (!D_801285B0.MapState.record[1].field_2A) return local_0;
    local_1 = func_800AC638(D_801285B0.MapState.record[1].field_0, D_801285B0.MapState.record[1].field_10[D_801285B0.MapState.record[1].field_29], param_0, param_1, param_2, param_3, param_4, param_5);
    if (local_1) {
        D_801285B0.MapState.field_1B0 = D_801285B0.MapState.record[1].field_C;
        return local_1;
    }
    return local_0;
}

s32 func_800BF228(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
  s32 var_v1;
  s32 temp_v0;
  s32 sp2C;
  var_v1 = 0;
  *((s32 *) (&D_801285B0.u[0x1B0])) = 0;
  if (D_801285B0.u[0x77] != 0)
  {
    var_v1 = _gcmapsects_entrypoint_26(D_801285B0.u, arg0, arg1, arg2, arg3);
  }
  if ((var_v1 == 0) && (D_801285B0.u[0x2A] != 0))
  {
    var_v1 = func_800AC978(*((s32 *) (&D_801285B0.u[0])), *((s32 *) (&D_801285B0.u[(D_801285B0.u[0x29] * 4) + 0x10])), arg0, arg1, arg2, arg3);
  }
  if (var_v1 != 0)
  {
    *((s32 *) (&D_801285B0.u[0x1B0])) = *((s32 *) (&D_801285B0.u[0xC]));
  }
  if (D_801285B0.u[0x56] == 0)
  {
    return var_v1;
  }
  sp2C = var_v1;
  temp_v0 = func_800AC978(*((s32 *) (&D_801285B0.u[0x2C])), *((s32 *) (&D_801285B0.u[(D_801285B0.u[0x55] * 4) + 0x3C])), arg0, arg1, arg2, arg3);
  if (temp_v0 != 0)
  {
    *((s32 *) (&D_801285B0.u[0x1B0])) = *((s32 *) (&D_801285B0.u[0x38]));
    return temp_v0;
  }
  return var_v1;
}

s32 func_800BF340(s32 param_0, Actor *param_1, s32 param_2, s32 param_3, s32 param_4) {
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    s32 local_3;

    func_800EE7F8(local_1);
    func_800EFB24(local_0, local_1, param_0);
    func_800EF368(local_0, param_4);
    func_800EF04C(local_1, local_0);
    local_3 = func_800BEF00(param_0, local_1, param_2, param_3);
    local_2 = local_3;
    if (local_3 == 0) {
        return 0;
    }
    func_800EF3DC(local_1, local_0);
    func_800EE7F8(param_1, local_1);
    return local_2;
}

int func_800BF3E4(void) {
    return ((*(u16*)&D_801285B0.u[0x5A] != 0) || (D_801285B0.u[0x77] != 0)) && (*(u16*)&D_801285B0.u[0x5C] != 0);
}

void func_800BF420()
{
    _gcmapDll_entrypoint_4(D_801285B0.u);
}

void func_800BF444()
{
  _gcmapDll_entrypoint_3(D_801285B0.u);
  func_800C6A28(&func_800BEF00, &func_800BF0E0, &func_800BF228, &func_800BEB4C);
}

void func_800BF48C(s32 param_0, s32 param_1, s32 param_2)
{
  ((u8*)D_801285B0.u)[0x85] = param_0;
  ((u8*)D_801285B0.u)[0x86] = param_1;
  ((u8*)D_801285B0.u)[0x87] = param_2;
}

void func_800BF4A4(s32 param_0, unsigned int param_1)
{
  u8 *temp_v0;
  u8 *new_var;
  temp_v0 = ((u8 *) (D_801285B0.u)) + (param_0 * 0x2C);
  if ((*((s32 *) temp_v0)) != 0)
  {
    new_var = temp_v0 + 0x2A;
    *((s8 *) new_var) = param_1;
  }
}

void func_800BF4DC(s32 param_0, s32 param_1) {
    if (param_1 != ((E_BF4DC *) &D_801285B0.raw)[param_0].unk2B) {
        if (((E_BF4DC *) &D_801285B0.raw)[param_0].unk4 != 0) {
            _idworldmake_entrypoint_5(((E_BF4DC *) &D_801285B0.raw)[param_0].unk4);
        }
    }
    ((E_BF4DC *) &D_801285B0.raw)[param_0].unk2B = param_1;
}

void func_800BF544(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_0 = *(s32 *)((u8 *)D_801285B4 + param_0 * 44);
    if (local_0) _idworldmake_entrypoint_6(local_0, param_1, param_2);
}

void func_800BF58C()
{
  if (D_801285B0.D_801285B0_unk.f0 != 0)
  {
    D_801285B0.D_801285B0_unk.f0 = func_800DC060(D_801285B0.D_801285B0_unk.f0);
  }
  if (D_801285B0.D_801285B0_unk.f1 != 0)
  {
    D_801285B0.D_801285B0_unk.f1 = defrag(D_801285B0.D_801285B0_unk.f1);
  }
  if (D_801285B0.D_801285B0_unk.f2 != 0)
  {
    D_801285B0.D_801285B0_unk.f2 = func_800EE5D8(D_801285B0.D_801285B0_unk.f2);
  }
  if (D_801285B0.D_801285B0_unk.f3 != 0)
  {
    D_801285B0.D_801285B0_unk.f3 = func_800EE5D8(D_801285B0.D_801285B0_unk.f3);
  }
  if (D_801285B0.D_801285B0_unk.f4 != 0)
  {
    D_801285B0.D_801285B0_unk.f4 = func_800F9F90(D_801285B0.D_801285B0_unk.f4, D_801285B0.D_801285B0_unk.f11);
  }
  if (D_801285B0.D_801285B0_unk.f5 != 0)
  {
    D_801285B0.D_801285B0_unk.f5 = func_800F9F90(D_801285B0.D_801285B0_unk.f5, D_801285B0.D_801285B0_unk.f12);
  }
  if (D_801285B0.D_801285B0_unk.f6 != 0)
  {
    D_801285B0.D_801285B0_unk.f6 = defrag(D_801285B0.D_801285B0_unk.f6);
  }
  if (D_801285B0.D_801285B0_unk.f7 != 0)
  {
    D_801285B0.D_801285B0_unk.f7 = defrag(D_801285B0.D_801285B0_unk.f7);
  }
  if (D_801285B0.D_801285B0_unk.f10 != 0)
  {
    D_801285B0.D_801285B0_unk.f8 = defrag(D_801285B0.D_801285B0_unk.f8);
  }
}

void func_800BF68C()
{
  int new_var;
  _gcmapDll_entrypoint_1(D_801285B0.u);
  new_var = 1;
  D_80128634 = -new_var;
}

int func_800BF6B8()
{
  if (D_801285B0.u[0x77] != 0)
  {
    int result = _gcmapsects_entrypoint_24(D_801285B0.u);
    if (result != 0)
    {
      return 2;
    }
    return 1;
  }
  return 0;
}

int func_800BF704()
{
  return (int)&D_801285B0.raw;
}

void func_800BF710()
{
  if (((u8*)&D_801285B0.raw)[0x77])
  {
    _gcmapsects_entrypoint_9(D_801285B0.u);
  }
}

int func_800BF744(s32 param_0, s32 param_1)
{
    ((s32 *) &D_801285B0.raw)[param_0 + 0x22] = param_1;
    if (param_0 > ((s32 *) &D_801285B0.raw)[0x22])
    {
        ((s32 *) &D_801285B0.raw)[0x22] = param_0;
    }
}

void func_800BF774()
{
  s32 *local_0;
  s32 local_1;
  local_1 = 1;
  if (((int *) &D_801285B0.raw)[34] > 0)
  {
    local_0 = &((int *) D_801285B4)[0];
    do
    {
      func_800DF744(local_1, (*(s32 *)((char *)(local_0) + 136)));
      local_1++;
      local_0++;
    }
    while (local_1 <= ((int *) &D_801285B0.raw)[34]);
  }
}

void func_800BF7E0(void) {
    s32 local_2;
    s32 local_0;
    s32 local_1;

    if ((*(s32 *)((s8 *)(D_801285B0.u) + (8))) != 0) {
        local_1 = func_800BEB64(0);
        local_0 = func_800BEBD4(0);
        _rtlight_entrypoint_2((*(s32 *)((s8 *)(D_801285B0.u) + (8))), local_1, local_0, func_800BEB98(0));
    }
    if ((*(s32 *)((s8 *)(D_801285B0.u) + (0x34))) != 0) {
        local_1 = func_800BEB64(1);
        local_0 = func_800BEBD4(1);
        _rtlight_entrypoint_2((*(s32 *)((s8 *)(D_801285B0.u) + (0x34))), local_1, local_0, func_800BEB98(1));
    }
    if ((*(s32 *)((s8 *)(D_801285B0.u) + (0x1C))) != 0) {
        _vpmodule_entrypoint_2((*(s32 *)((s8 *)(D_801285B0.u) + (0x1C))), (*(s32 *)((s8 *)(D_801285B0.u) + (0x18))));
    }
    if ((*(s32 *)((s8 *)(D_801285B0.u) + (0x48))) != 0) {
        _vpmodule_entrypoint_2((*(s32 *)((s8 *)(D_801285B0.u) + (0x48))), (*(s32 *)((s8 *)(D_801285B0.u) + (0x44))));
    }
}

u8 func_800BF8B0()
{
  return D_80128627;
}

int func_800BF8BC(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _gcmapDll_entrypoint_6(&D_801285B0.raw, local_0);
}

s32 func_800BF8E4(void) {
    s32 local_0;
    if (D_801285B0.BF8E4.local_1 == -1) {
        D_801285B0.BF8E4.local_1 = 0;
        for (local_0 = 0; local_0 < 2; local_0++) {
            if (D_801285B0.BF8E4.local_0[local_0].local_0[2]) D_801285B0.BF8E4.local_1 = 1;
            if (D_801285B0.BF8E4.local_0[local_0].local_0[7] && _dbvpl_entrypoint_0(D_801285B0.BF8E4.local_0[local_0].local_0[6], 0)) D_801285B0.BF8E4.local_1 = 2;
        }
    }
    return D_801285B0.BF8E4.local_1;
}

void func_800BF99C(s32 param_0, s32 param_1, s32 param_2) {
    if (*(s32 *)(((param_0 * 0x2C) + D_801285B0.u) + 0x1C) != 0) {
        _vpmodule_entrypoint_4(*(s32 *)(((param_0 * 0x2C) + D_801285B0.u) + 0x1C), *(s32 *)(((param_0 * 0x2C) + D_801285B0.u) + 0x18), param_1, param_2);
    }
    if (*(s32 *)(((param_0 * 0x2C) + D_801285B0.u) + 4) != 0) {
        _idworldmake_entrypoint_7(*(s32 *)(((param_0 * 0x2C) + D_801285B0.u) + 4), param_1, param_2);
    }
}

int func_800BFA1C(f32 *param_0) {
    s32 local_0;
    for (local_0 = 0; local_0 < 3; local_0++) {
        if (param_0[local_0] < ((s32 *)D_801285B0.u)[local_0 + 0x60] - 100) return 0;
        if (param_0[local_0] > ((s32 *)D_801285B0.u)[local_0 + 0x63] + 100) return 0;
    }
    return 1;
}

int func_800BFAA4()
{
  u8 *local_0;
  local_0 = func_800BF704();
  return local_0[0x77];
}
