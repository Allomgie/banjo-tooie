#include "core2/1E9A960.h"

#define MIN_C(a,b) ((a) < (b) ? (a) : (b))
#define MAX_C(a,b) ((a) > (b) ? (a) : (b))
#define C4350_FLOAT(off) (*(f32 *)((u8 *)local_1 + (off)))
#define C4350_MODE(mode) (local_1->flags.half.lower = (local_1->flags.half.lower & 0xFC3F) | ((mode) << 6))
#define C4350_IMM ((local_3 & 0xFF00) >> 8)
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[7]; } Sub_C13E4;
typedef struct { Sub_C13E4 sub[4]; } E_C13E4;
extern s32 D_80128B08[];
typedef struct { u8 local_0[0x78]; u8 local_1; u8 local_2[7]; } local_type_800C145C;
extern s32 D_80128B0C[];
typedef struct { s32 local_0; s32 local_1; } local_type_800C15BC;
extern local_type_800C15BC D_80128B10[16];
extern u8 D_80128C08[];
typedef struct { u8 pad0[0x1B]; u8 field1B; u8 field1C; u8 pad1D[3]; s32 field20; s32 field24; u8 pad28[0x30]; s16 field58; u16 field5A; u8 pad5C[4]; u8 field60; u8 field61; u8 pad62[10]; s32 field6C; u8 pad70[9]; u8 field79; } LocalSound_800C16F8;
extern f32 D_8011A878;
extern void func_800DC454(s32, s32);
extern void func_800EFB24(void *arg0, void *arg1, void *arg2);
extern f32 func_800EEFD4(void *arg0);
typedef struct SoundC { f32 local_0[3], local_1, local_2, local_3; s16 local_4; u8 local_5[6]; u8 pad20[0x20]; f32 local_6, local_7, local_8; s16 local_9, local_10; f32 local_11, local_12; s16 local_13, local_14, local_15, local_16; u8 local_17, local_18, local_19, local_20; void (*local_21)(u8, s32); s32 local_22; f32 local_23; u8 pad70[8]; union { struct { u8 local_0, local_1; u16 local_2; } local_0; struct { u32 local_0:16; u32 local_1:3; u32 local_2:3; u32 local_3:4; u32 local_4:1; u32 local_5:1; u32 local_6:1; u32 local_7:1; u32 local_8:1; u32 local_9:1; } local_1; } local_24; } SoundC;
extern void func_800E3980(f32 *);
extern void func_800E3A58(f32 *);
extern void func_800EF7B0(f32 *, f32 *, f32, f32, f32);
extern void func_800F1EA4(f32 *, f32 *);
typedef struct { char pad[0x70]; f32 unk70; f32 unk74; } Struct_800C1CCC;
extern s32 func_800EA05C(void);
extern s32 func_800EA068(s32);
extern s32 func_800A8184(void);
typedef struct { u8 pad_0[0x28]; f32 field_28, field_2C, field_30, field_34, field_38, field_3C; f32 attack, decay, hold; s16 minimum, maximum; f32 drift, elapsed; s16 sound, volume, limit, context; u8 pad_60[0xC]; f32 pitch; u8 pad_70[8]; union { struct { u8 pad_78, handle; u16 pad_7A; } bytes; struct { u32 pad_78:16, policy:3, state:3, mode:4; u32 stopping:1, timed:1, envelope:1, pad_7B:1, release:1, pad_7C:1; } bits; } flags; } LocalSound_800C2000;
extern f32 func_800D8FF8(void);
extern f32 func_800DC264(f32, f32);
extern s32 func_800F0E28(s32, s32);
extern s32 func_800F1418(s32, s32);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct { u8 local_0[0x78]; u32 local_1:8; u32 local_2:11; u32 local_3:3; u32 local_4:10; u32 local_5; } local_type_800C2718;
extern s32 func_800C0638(void);
typedef struct { u8 pad[0x78]; u8 local_0; u8 pad79[7]; } SoundSlotC;
extern s32 D_80128C10;
typedef struct { u8 local_0[0x54]; f32 local_1; u8 local_2[10]; u8 local_3; u8 local_4[21]; u32 local_5:8; u32 local_6:11; u32 local_7:3; u32 local_8:4; u32 local_9:1; u32 local_10:5; u32 local_11; } local_type_800C2B80;
extern local_type_800C2B80 D_80128B90[60];
extern void func_800EFD24(f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct { u8 pad0[0x4C]; s16 unk4C; s16 unk4E; f32 unk50; u8 pad54[6]; s16 unk5A; u8 pad5C[0x1C]; u32 pad78 : 28; u32 flag : 1; u32 pad78b : 3; } S800C316C;
struct SomeStruct { u8 pad[0x28]; f32 unk28; f32 unk2C; f32 unk30; f32 unk34; u8 pad2[0x42]; u16 unk7A; };
typedef struct { u8 pad0[0x7B]; u8 f0 : 6; u8 bit : 1; u8 f2 : 1; } S_C3B8C;
typedef struct { u8 local_0[0x58]; s16 local_1; u8 local_2[0x1E]; u32 local_3:16; u32 local_4:3; u32 local_5:3; u32 local_6:7; u32 local_7:1; u32 local_8:2; } local_type_800C3BDC;
extern void func_800FECB8(s32);
extern float D_8011A870;
extern float D_8011A874;
typedef struct { f32 position[3]; f32 radiusSquared[2]; u8 pad14[6]; s8 field1A; u8 field1B, field1C, field1D; u8 pad1E[10]; f32 field28, field2C, field30, field34, field38, field3C; u8 pad40[24]; s16 field58; u8 pad5A[4]; s16 field5E; u8 field60, field61, field62, field63; void (*callback)(u8, s32); s32 callbackArgument; f32 field6C, field70, field74; union { u32 word; struct { unsigned pad:29; unsigned enabled:1; unsigned low:2; } bits; struct { u16 upper, lower; } half; struct { u8 a, b, c, d; } byte; } flags; } C4350State;
extern void func_800EE7F8(void *, void *);
extern s32 func_800DC214(s32, s32);
typedef struct { f32 local_0; s16 local_1, local_2; } C4350Defaults;
extern float D_8012A990;
extern s16 D_8012A994;
extern s16 D_8012A996;
void func_800C2B80();
u8 func_800C2E04();
int func_800C3058(u8, unsigned int);
void func_800C31DC(u8 param_0, f32 param_1);
void func_800C32C4(u8, s32);
void func_800C368C(u8, s32);
void func_800C36F4(u8, s32);
void func_800C3798(u8 param_0, f32 param_1, f32 param_2);
f32 func_800C395C(u8);
int func_800C42E0();
void func_800C4308(f32 param_0, f32 param_1);
void func_800C4B64(f32 param_0);
int func_800C4B70();
void func_800C4B7C();

void func_800C1070(s32 param_0, s32 param_1) {
    s32 pad;
    s32 local_0;
    f32 local_1[3];

    if (func_800F5310() != 0) {
        if (func_800EA068(0x20) != 0) {
            _plsu_entrypoint_0(param_0, param_1);
            return;
        }
        local_0 = func_800F5EF8(_plsu_entrypoint_0(param_0, param_1));
        if (func_8010FFA8(local_0) != 2) {
            func_8010FFB0(local_0, param_0, local_1);
        }
    } else {
        func_800E3980(param_0);
    }
}

s32 func_800C1104(s32 param_0) {
    f32 sp24[3];
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    if (func_800F5310() != 0) {
        if (func_800EA068(0x20) != 0) {
            sp20 = _plsu_entrypoint_0(sp24, param_0);
            if (func_800F5D18(sp20) == 2) {
                return 1;
            }
            return 0;
        }
        sp1C = _plsu_entrypoint_0(sp24, param_0);
        sp18 = func_800F5EF8(sp1C);
        if (func_8010FFA8(sp18) == 2) {
            if (func_800F5D18(sp1C) == 2) {
                return 1;
            }
            return 0;
        }
        if (func_8010FFD8(sp18) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_800A5490() != 0) {
        return 1;
    }
    return 0;
}

void func_800C11F8(u8 *a0, s32 a1)
{
  short new_var2;
  s32 new_var;
  new_var = a1;
  a0[0x7A] = (a0[0x7A] & (~0xE0)) | ((new_var2 = new_var) << 5);
}

int func_800C1210(volatile u8 *param_0, u32 param_1)
{
  u32 new_var;
  unsigned short new_var3;
  u32 new_var2;
 if (0) { }
  new_var3 = param_1;
  ;
  param_0[0x7A] = (param_0[0x7A] & 0xFFE3) | (((new_var = new_var3) << 2) & 0x1C);
}

s32 func_800C122C(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    f32 local_0;
    if (param_3) {
        if (!param_1 || !param_2) return param_0;
        return param_0 + 128;
    }
    if (!param_1 || !param_2) {
        local_0 = (param_0 + ((f32) D_8011A870) * 127.0f) * ((f32) D_8011A874);
        return MAX_C(0.0f, MIN_C(127.0f, local_0));
    }
    local_0 = (param_0 + ((f32) D_8011A870) * 127.0f) * ((f32) D_8011A874);
    return MAX_C(0.0f, MIN_C(127.0f, local_0)) + 128.0f;
}

void func_800C13A0(u16 *param_0, unsigned int param_1)
{
  param_0[0x3E] |= param_1;
}

void func_800C13B0(u16 *param_0, unsigned long param_1)
{
  param_0[0x3E] &= ~param_1;
}

int func_800C13C4(u16 *param_0, unsigned long param_1)
{
  return param_0[0x3E] & param_1;
}

s32 func_800C13D0(u8 *param_0, s32 param_1) {
    return ((*(u16 *)((s8 *)(param_0) + (0x7C))) & param_1) == 0;
}

void func_800C13E4(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 4; j++) {
            ((E_C13E4 *) D_80128B90)[i].sub[j].unk78 = 0;
        }
    }
}

S_C3B8C * func_800C1414(u8 param_0)
{
    return (param_0 << 7) + ((u8 *) D_80128B90);
}

int func_800C1430(s32 param_0)
{
  return (int) &D_80128B10[param_0 - 1];
}

int func_800C1448(param_0) s32 param_0;
{
  return D_80128B10[param_0 - 1].local_0;
}

u8 func_800C145C(void) {
    s32 local_0;
    for (local_0 = 1; local_0 < 0x3C; local_0++) {
        if (((local_type_800C145C *) D_80128B90)[local_0].local_1 == 0) {
            ((local_type_800C145C *) D_80128B90)[local_0].local_1 = 1;
            return local_0;
        }
    }
    return 0;
}

int func_800C1568(s32 param_0)
{
  *(s32 *)((char *)D_80128B0C + param_0 * 8) = 0;
}

void func_800C157C(void) {
    s32 local_0;
    for (local_0 = 0; local_0 < 16; local_0++) {
        ((s32 (*)[2]) D_80128B10)[local_0][0] = 0;
        ((s32 (*)[2]) D_80128B10)[local_0][1] = 0;
    }
}

s32 func_800C15BC(void) {
    s32 local_0;
    s32 local_1;
    do {
        local_0 = 0;
        for (local_1 = 0; local_1 < 16; local_1++) {
            if (D_80128B10[local_1].local_1 != 0) local_0++;
            else if (D_80128B10[local_1].local_0 == 0) {
                D_80128B10[local_1].local_1 = 1;
                return local_1 + 1;
            }
        }
    } while (local_0 < 16);
    return 0;
}

void func_800C16A4(u8 param_0)
{
    u8 *temp_v0;

    temp_v0 = func_800C1414(param_0);
    if (*(u8 *)((char *)temp_v0 + 0x79) != 0) {
        func_800C1568(*(u8 *)((char *)temp_v0 + 0x79));
        *(u8 *)((char *)temp_v0 + 0x79) = 0;
    }
    D_80128C08[param_0 << 7] = 0;
}

void func_800C16F8(LocalSound_800C16F8 *param_0, s32 param_1) {
    s32 local_1;
    s32 local_0;

    if (param_1) {
        if (param_0->field79) {
            func_800C1568(param_0->field79);
        }
        param_0->field79 = (u16)param_1;
        func_800C1210(param_0, 1);
        func_800C13A0(param_0, 4);
        func_800C13A0(param_0, 8);
        func_800C13A0(param_0, 16);
        param_0->field20 = -1;
        param_0->field24 = -1;
        if (func_800CCEF4(param_0, &param_0->field20, &param_0->field24, 0, 0)) {
            if (func_800CBC00(param_0->field20)) {
                switch (func_800CBBE0(param_0->field20)) {
                case 2: param_0->field60 = 25; break;
                case 3: param_0->field60 = 20; break;
                case 4: param_0->field60 = 15; break;
                case 5: param_0->field60 = 10; break;
                case 6: param_0->field60 = 5; break;
                }
            }
        }
        local_1 = func_800C13C4(param_0, 0x400);
        local_0 = func_800C122C(param_0->field60, param_0->field1B, param_0->field1C, local_1);
        func_800DC3D4(param_0->field58 - 1001, param_0->field6C, param_0->field5A, param_0->field61, local_0, func_800C1430(param_0->field79));
    }
}

void func_800C1860(u8 *param_0)
{
  u32 *new_var;
  u32 val;
  u8 temp_v0;
  new_var = (u32 *) (((char *) param_0) + 0x78);
  val = *new_var;
  if ((((val << 7) << 12) >> 29) == 1)
  {
 func_800C13B0(param_0, 0x20); func_800C1210(param_0, 2); goto dummy_label_658801; dummy_label_658801: ;
    temp_v0 = *((u8 *) (((char *) param_0) + 0x79));
    if (temp_v0)
    {
      func_800DC4D4(func_800C1448(temp_v0));
    }
  }
}

void func_800C18C8(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
  if (param_0 != 0)
  {
    func_800DC48C(func_800C1448(param_0), func_800C122C(param_1, param_2, param_3, param_4));
  }
}

s32 func_800C191C(param_0, param_1) s32 param_0; s32 param_1;{
    if(param_0){
        func_800DC4B0(func_800C1448(param_0), param_1);
    }
}

int func_800C1950(param_0, param_1) s32 param_0; s32 param_1;
{
  if (param_0 != 0)
  {
    func_800DC42C(func_800C1448(param_0) | 0, param_1);
  }
}

void func_800C1984(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  local_0 = param_0;
  if (local_0 != 0)
  {
    if (param_2 == 0)
    {
      param_1 *= D_8011A878;
    }
    local_0 = func_800C1448(local_0);
    func_800DC454(local_0 | local_0, param_1 & 0xFFFF);
  }
}

s32 func_800C19E4(u8 *param_0, s32 param_1) {
    s8 local_1[8];
    s32 local_0;
    s32 local_2;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;
    s16 temp_v0;
    s32 var_v1;

    func_800C1070(&local_0, param_0);
    func_800EFB24((u8 *)&local_2 - 8, param_0, &local_0);
    temp_f0 = func_800EEFD4((u8 *)&local_2 - 8);
    temp_f12 = (*(f32 *)((s8 *)param_0 + 0xC));
    if (temp_f0 < temp_f12) {
        var_v1 = param_1;
    } else {
        temp_f2 = (*(f32 *)((s8 *)param_0 + 0x10));
        if (temp_f0 < temp_f2) {
            temp_v0 = (*(s16 *)((s8 *)param_0 + 0x18));
            var_v1 = (s32)((f32)temp_v0 + (((temp_f2 - temp_f0) / (temp_f2 - temp_f12)) * (f32)(param_1 - temp_v0)));
        } else {
            var_v1 = (s32)(*(s16 *)((s8 *)param_0 + 0x18));
        }
    }
    return var_v1;
}

void func_800C1AA4(SoundC *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    s32 local_5;
    func_800E3980(local_0);
    func_800EFB24(local_1, param_0->local_0, local_0);
    if (local_1[0]*local_1[0] + local_1[1]*local_1[1] + local_1[2]*local_1[2] < 10.0f) {
        param_0->local_3 = 64.0f;
    } else {
        param_0->local_5[2] = param_0->local_5[3];
        if (!param_0->local_5[2]) {
            func_800E3A58(local_4);
            local_4[1] = -local_4[1];
            local_4[0] = -local_4[0];
            local_4[2] = -local_4[2];
            func_800EF7B0(local_3, local_4, local_1[0], local_1[1], local_1[2]);
            func_800F1EA4(local_3, local_2);
            local_2[0] = 180.0f - local_2[0];
            if (local_2[0] < -90.0f) {
                local_2[0] = -180.0f - local_2[0];
                if (param_0->local_5[1]) param_0->local_5[2] = 1;
            } else if (local_2[0] > 90.0f) {
                local_2[0] = 180.0f - local_2[0];
                if (param_0->local_5[1]) param_0->local_5[2] = 1;
            }
        }
        local_5 = func_800C13C4(param_0, 0x400);
        func_800C18C8(param_0->local_24.local_0.local_1, param_0->local_17, param_0->local_5[1], param_0->local_5[2], local_5);
        local_5 = local_2[0] * 0.7f + 64.0f;
        if (param_0->local_5[0]) param_0->local_3 += 0.07f * (local_5 - param_0->local_3);
        else param_0->local_3 = local_5;
    }
    func_800C191C(param_0->local_24.local_0.local_1, (s32)param_0->local_3);
}

s32 func_800C1CCC(Struct_800C1CCC *param_0, s32 param_1) {
    s32 a;
    if (func_800C13C4(param_0, 0x40) != 0) {
        a = func_800C1104(param_0);
        if (func_800C13C4(param_0, 0x80) != 0) {
            if (a == 1) {
                param_1 = param_1 * param_0->unk74;
            }
        } else if (a == 0) {
            param_1 = param_1 * param_0->unk70;
        }
    }
    return param_1;
}

s32 func_800C1D80(u8 param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_5;
    s32 local_2;
    u8 *local_4;

    local_0 = 0;
    local_4 = func_800C1414(param_0);
    if ((((u32)(*(s32 *)((s8 *)(local_4) + 0x78)) << 0x13) >> 0x1D == 1) && (*(u8 *)((s8 *)(local_4) + 0x79) != 0)) {
        local_2 = func_800EA05C() != (*(s16 *)((s8 *)(local_4) + 0x5E));
        if ((u32)(func_800C13C4(local_4, 4) - 0) > 0) {
            func_800C1950((*(u8 *)((s8 *)(local_4) + 0x79)), (*(s32 *)((s8 *)(local_4) + 0x6C)));
        }
        if ((func_800C13C4(local_4, 0x10) != 0) && ((*(u8 *)((s8 *)(local_4) + 0x1B)) == 0)) {
            func_800C18C8((*(u8 *)((s8 *)(local_4) + 0x79)), (*(u8 *)((s8 *)(local_4) + 0x60)), (*(u8 *)((s8 *)(local_4) + 0x1B)), (*(u8 *)((s8 *)(local_4) + 0x1C)), func_800C13C4(local_4, 0x400));
        }
        if (func_800C13C4(local_4, 2) != 0) {
            if (local_2 != 0) {
                func_800C1984((*(u8 *)((s8 *)(local_4) + 0x79)), (*(s16 *)((s8 *)(local_4) + 0x5C)), func_800C13C4(local_4, 0x200));
            } else {
                if ((*(u8 *)((s8 *)(local_4) + 0x63)) != 0) {
                    local_1 = func_800C19E4(local_4, (*(s16 *)((s8 *)(local_4) + 0x5A)));
                } else {
                    local_1 = (*(s16 *)((s8 *)(local_4) + 0x5A));
                }
                if (local_1 < 0x64) {
                    local_0 = 1;
                }
                local_1 = func_800C1CCC(local_4, local_1);
                (*(s16 *)((s8 *)(local_4) + 0x5C)) = local_1;
                func_800C1984((*(u8 *)((s8 *)(local_4) + 0x79)), local_1, func_800C13C4(local_4, 0x200));
                if (func_800EA068(0x20) == 0) {
                    func_800C1AA4(local_4);
                }
            }
        } else {
            if (func_800C13C4(local_4, 0x100) != 0) {
                func_800C191C((*(u8 *)((s8 *)(local_4) + 0x79)), (*(u8 *)((s8 *)(local_4) + 0x61)));
            }
            if (local_2 != 0) {
                func_800C1984((*(u8 *)((s8 *)(local_4) + 0x79)), (*(s16 *)((s8 *)(local_4) + 0x5C)), func_800C13C4(local_4, 0x200));
            } else if (func_800C13C4(local_4, 8) != 0) {
                local_1 = func_800C1CCC(local_4, (*(s16 *)((s8 *)(local_4) + 0x5A)));
                (*(s16 *)((s8 *)(local_4) + 0x5C)) = local_1;
                if (local_1 < 0x64) {
                    local_0 = 1;
                }
                func_800C1984((*(u8 *)((s8 *)(local_4) + 0x79)), local_1, func_800C13C4(local_4, 0x200));
            }
        }
        func_800C13B0(local_4, 4);
        func_800C13B0(local_4, 8);
        func_800C13B0(local_4, 0x10);
    }
    if (func_800A8184() == 4) {
        local_0 += 1;
    }
    return local_0;
}

void func_800C2000(u8 param_0) {
    LocalSound_800C2000 *local_0;
    s32 local_1;
    f32 local_2;
    s32 local_3;
    s32 local_5, local_6;
    f32 local_4;

    local_2 = func_800D8FF8();
    local_0 = func_800C1414(param_0);
    local_0->elapsed += local_2;
    if (local_0->flags.bits.stopping) {
        if (local_0->decay == 0.0f) {
            local_0->volume = 0;
        } else {
            local_0->volume -= (local_0->maximum / local_0->decay) * local_2;
            local_0->volume = func_800F0E28(0, local_0->volume);
            if (func_800EA05C() != local_0->context) {
                local_0->limit = func_800F1418(local_0->limit, local_0->volume);
            }
        }
        if (local_0->volume <= 0) {
            func_800C2FDC(param_0);
            return;
        }
        func_800C13A0(local_0, 8);
    } else if (local_0->flags.bits.envelope) {
        if (local_0->elapsed < local_0->attack) {
            local_0->volume = (local_0->elapsed / local_0->attack) * (local_0->minimum + local_0->maximum) / 2;
        } else if (local_0->elapsed <= local_0->attack + local_0->hold) {
            if (local_0->volume < local_0->minimum || local_0->maximum < local_0->volume) {
                local_0->volume = (local_0->minimum + local_0->maximum) / 2;
            }
            local_0->volume += func_800DC264(-1.0f, 1.0f) * local_0->drift;
            local_6 = local_0->volume;
            local_5 = local_0->maximum;
            local_0->volume = local_5 < local_6 ? local_5 : local_6;
            local_6 = local_0->volume;
            local_5 = local_0->minimum;
            local_0->volume = local_6 < local_5 ? local_5 : local_6;
        } else {
            local_0->volume = (1.0f - (local_0->elapsed - local_0->attack - local_0->hold) / local_0->decay) * (local_0->minimum + local_0->maximum) / 2;
        }
        if (func_800EA05C() != local_0->context) {
            local_0->limit = func_800F1418(local_0->limit, local_0->volume);
        }
        func_800C13A0(local_0, 8);
    }
    if (local_0->flags.bits.timed && local_0->attack + local_0->hold + local_0->decay <= local_0->elapsed) {
        if (local_0->flags.bits.release) {
            func_800C2FDC(param_0);
            return;
        }
        func_800C1860(local_0);
    }
    if (local_0->flags.bytes.handle && local_0->flags.bits.state == 1 && func_800C1448(local_0->flags.bytes.handle)) {
        switch (local_0->flags.bits.mode) {
        case 0:
            break;
        case 1:
            local_0->pitch += local_0->field_28 * local_2;
            if (local_0->field_28 > 0.0f) {
                local_0->pitch = func_800F13F0(local_0->pitch, local_0->field_2C);
            } else {
                local_0->pitch = func_800F0E00(local_0->pitch, local_0->field_2C);
            }
            func_800C13A0(local_0, 4);
            break;
        case 2:
            local_0->pitch += func_800DC264(-local_0->field_30, local_0->field_30) * local_2;
            local_0->pitch = func_800F0D50(local_0->pitch, local_0->field_2C, local_0->field_28);
            func_800C13A0(local_0, 4);
            break;
        case 3:
            local_0->pitch = func_800F10B4(local_0->elapsed, local_0->field_28, local_0->field_2C, local_0->field_30, local_0->field_34);
            func_800C13A0(local_0, 4);
            break;
        case 4:
            local_4 = local_0->elapsed;
            if (local_4 < local_0->field_28) {
                local_0->pitch = func_800F10B4(local_4, 0.0f, local_0->field_28, local_0->field_34, local_0->field_38);
            } else if (local_4 < local_0->field_28 + local_0->field_2C) {
                local_0->pitch = local_0->field_38;
            } else {
                local_0->pitch = func_800F10B4(local_4 - (local_0->field_28 + local_0->field_2C), 0.0f, local_0->field_30, local_0->field_38, local_0->field_3C);
            }
            func_800C13A0(local_0, 4);
            break;
        }
    }
    switch (local_0->flags.bits.policy) {
    case 1:
        if (local_0->flags.bits.state == 0 || (local_0->flags.bits.state == 1 && !local_0->flags.bytes.handle)) {
            func_800C2FDC(param_0);
            return;
        }
        break;
    case 2:
        if (local_0->flags.bits.state == 1 && func_800C13D0(local_0, 1)) func_800C3CE8(param_0);
        else func_800C13B0(local_0, 1);
        break;
    case 3:
        break;
    }
    local_1 = func_800C1D80(param_0);
    if (local_0->flags.bits.state == 1 && func_800C42E0(local_0->sound)) {
        if (func_800C13C4(local_0, 0x20)) {
            if (!local_1) {
                local_3 = func_800C15BC();
                osSetThreadPri(0, 0x33);
                func_800C16F8(local_0, local_3);
                func_800C13B0(local_0, 0x20);
                func_800C1D80(param_0);
                osSetThreadPri(0, 0x14);
            }
        } else if (local_1) {
            func_800C1860(local_0);
            func_800C1210(local_0, 1);
            func_800C13A0(local_0, 0x20);
        }
    }
    if (local_0->flags.bytes.handle && !func_800C1448(local_0->flags.bytes.handle)) {
        func_800C1568(local_0->flags.bytes.handle);
        local_0->flags.bytes.handle = 0;
    }
}

s32 func_800C269C(u8 param_0)
{
  int new_var2;
  int new_var;
  s32 new_var3;
  u8 *local_0;
  s32 local_1;
  local_0 = func_800C1414(param_0);
  new_var = 0x1D;
  local_1 = *((s32 *) (((char *) local_0) + 0x78));
  new_var2 = 0x79;
  new_var3 = *((s32 *) (((char *) local_0) + 0x78));
  local_1 = new_var3;
  if ((((u32) (local_1 << 0x13)) >> new_var) != 3)
  {
    return 0;
  }
  if ((*((u8 *) (((char *) local_0) + new_var2))) == 0)
  {
    return 1;
  }
  if (func_800C1448(*((u8 *) (((char *) local_0) + new_var2))) != 0)
  {
    return 0;
  }
  return 1;
}

void func_800C2718()
{
  s32 local_1, local_2, local_3;
  local_type_800C2718 *local_0;
  if (func_800C0638())
  {
    D_8011A878 -= func_800D8FF8();
    if (D_8011A878 < 0.5f)
    {
      D_8011A878 = 0.5f;
    }
  }
  else
  {
    D_8011A878 += func_800D8FF8();
    if (D_8011A878 > 1.0f)
    {
      D_8011A878 = 1.0f;
    }
  }
  local_0 = ((local_type_800C2718 *) &D_80128C10);
  local_1 = 1;
  do
  {
    if (local_0->local_1 != 0) {
    if (local_0->local_3 != 3)
    {
      func_800C2000(local_1);
    }
    if (func_800C269C(local_1))
    {
      func_800C16A4(local_1);
    }
    }
    local_0++;
    local_1++;
  } while (local_1 < 0x3C);
}

void func_800C2840(s32 p0, f32 p1, s32 p2, s32 p3, s32 p4) {
    s32 r;
    u8 id;
    r = func_800C2E04();
    id = r;
    if (r != 0) {
        func_800C301C(id, p0);
        func_800C3058(id, p2);
        func_800C31DC(id, p1);
        func_800C32C4(id, p3);
        func_800C330C(id, 1);
        func_800C3418(id, p4);
        func_800C36F4(id, 0);
        func_800C3BDC(id);
    }
}

void func_800C28D8()
{
    func_800C157C();
    func_800C13E4();
}

void func_800C2900(void)
{
    s32 local_0;
    s32 local_1;
    for (local_0 = 1; local_0 < 60; local_0++) {
        if (((SoundSlotC *) D_80128B90)[local_0].local_0) func_800C2FDC(local_0);
    }
    do {
        local_1 = 0;
        func_800C2718();
        for (local_0 = 1; local_0 < 60; local_0++) {
            if (((SoundSlotC *) D_80128B90)[local_0].local_0) local_1++;
        }
    } while (local_1);
}

int func_800C2A08()
{
  func_800C28D8();
  func_800C4308(0.0f, 1.0f);
  func_800C4B64(1.0f);
  func_800C4B70(0x55F0);
  func_800C4B7C(-1);
}

void func_800C2A5C(s32 arg0, s32 arg1) {
}
void func_800C2A68()
{
    func_80017244();
    func_80016E7C();
}

void func_800C2A90()
{
    func_800C2900();
    func_800C2A68();
}

void func_800C2AB8(void)
{
  s8 *local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  func_800C2B80();
  do
  {
    local_0 = (s8 *) (&D_80128C10);
    local_2 = 1;
    local_3 = 0;
    loop_2:
    if ((*((u8 *) (local_0 + 0x78))) != 0)
    {
      local_1 = local_2 & 0xFF;
      if ((((u32) (((s32) (*((s32 *) (local_0 + 0x78)))) << 0x13)) >> 0x1D) == 3)
      {
        if (func_800C269C(local_2 & 0xFF) != 0)
        {
          func_800C16A4(local_1);
        }
        else
        {
          local_3 += 1;
        }
      }
    }

    local_2 += 1;
    local_0 += 0x80;
    if (local_2 != 0x3C)
    {
      goto loop_2;
    }
  }
  while (local_3 != 0);
}

void func_800C2B80(void) {
    s32 local_0;
    for (local_0 = 1; local_0 < 60; local_0++) {
        if (!D_80128B90[local_0].local_5) continue;
        if (D_80128B90[local_0].local_7 == 3) continue;
        if (D_80128B90[local_0].local_3 == 255) continue;
        {
            if (!D_80128B90[local_0].local_3) func_800C2FDC(local_0);
            else if (--D_80128B90[local_0].local_3 == 0) {
                D_80128B90[local_0].local_1 = 0.0f;
                D_80128B90[local_0].local_9 = 1;
            }
        }
    }
}

void func_800C2C4C(u8 param_0)
{
    SoundC *local_0;
    local_0 = func_800C1414(param_0);
    local_0->local_21 = 0;
    local_0->local_13 = -1;
    local_0->local_15 = 0;
    local_0->local_14 = 0x55F0;
    local_0->local_17 = 0;
    local_0->local_18 = 0x3F;
    local_0->local_24.local_0.local_1 = 0;
    local_0->local_19 = 0xFF;
    local_0->local_23 = 1.0f;
    local_0->local_16 = func_800EA05C();
    local_0->local_20 = 1;
    local_0->local_24.local_1.local_3 = 0;
    local_0->local_24.local_1.local_5 = 0;
    local_0->local_8 = 3.0f;
    local_0->local_24.local_1.local_8 = 1;
    local_0->local_24.local_1.local_6 = 0;
    local_0->local_24.local_1.local_4 = 0;
    local_0->local_24.local_1.local_7 = 0;
    local_0->local_6 = 1.0f;
    local_0->local_7 = 1.0f;
    local_0->local_12 = 0.0f;
    func_800C1210(local_0, 0);
    func_800C11F8(local_0, 0);
    func_800C13A0(local_0, 1);
    func_800C13A0(local_0, 4);
    func_800C13A0(local_0, 8);
    func_800C13A0(local_0, 0x10);
    local_0->local_1 = 6.25e+04f;
    local_0->local_2 = 1.44e+06f;
    local_0->local_3 = 64.0f;
    local_0->local_4 = 10;
    local_0->local_5[0] = 0;
    local_0->local_5[1] = 0;
    local_0->local_5[2] = 0;
    local_0->local_5[3] = 0;
    func_800EFD24(local_0->local_0);
    func_800C13B0(local_0, 2);
    func_800C13B0(local_0, 0x20);
    func_800C13B0(local_0, 0x200);
    func_800C13B0(local_0, 0x400);
    func_800C3418(param_0, 2);
    func_800C3798(param_0, 0.2f, 0.1f);
}

u8 func_800C2E04()
{
  u8 local_0;
  local_0 = func_800C145C();
  if (!local_0) {
    return 0;
  }
  func_800C2C4C(local_0);
  return local_0;
}

void func_800C2E40(u8 param_0) {
    SoundC *local_0;
    func_800C3CE8(param_0);
    local_0 = func_800C1414(param_0);
    local_0->local_21 = 0;
    local_0->local_13 = -1;
    local_0->local_15 = 0;
    local_0->local_14 = 0x55F0;
    local_0->local_17 = 0;
    local_0->local_18 = 0x3F;
    local_0->local_19 = 0xFF;
    local_0->local_23 = 1.0f;
    local_0->local_16 = func_800EA05C();
    local_0->local_20 = 1;
    local_0->local_24.local_1.local_3 = 0;
    local_0->local_24.local_1.local_5 = 0;
    local_0->local_8 = 3.0f;
    local_0->local_24.local_1.local_8 = 1;
    local_0->local_24.local_1.local_6 = 0;
    local_0->local_24.local_1.local_4 = 0;
    local_0->local_24.local_1.local_7 = 0;
    local_0->local_6 = 1.0f;
    local_0->local_7 = 1.0f;
    local_0->local_12 = 0.0f;
    func_800C1210(local_0, 0);
    func_800C11F8(local_0, 0);
    func_800C13A0(local_0, 1);
    func_800C13A0(local_0, 4);
    func_800C13A0(local_0, 8);
    func_800C13A0(local_0, 0x10);
    local_0->local_1 = 6.25e+04f;
    local_0->local_2 = 1.44e+06f;
    local_0->local_3 = 64.0f;
    local_0->local_4 = 10;
    local_0->local_5[0] = 0;
    local_0->local_5[1] = 0;
    func_800EFD24(local_0->local_0);
    func_800C13B0(local_0, 2);
    func_800C13B0(local_0, 0x20);
    func_800C3418(param_0, 2);
    func_800C3798(param_0, 0.2f, 0.1f);
}

s32 func_800C2FDC(u8 param_0) {
  volatile u8 *local_0;
  local_0 = func_800C1414(param_0);
  func_800C3CE8(param_0);
  func_800C1210(local_0, 3);
  return 0;
}

void func_800C301C(u8 arg0, s32 arg1)
{
  u8 *temp;
  if (arg0 != 0)
  {
    s8 *ptr = func_800C1414(arg0);
    *(s16 *)((char *)ptr + 0x58) = arg1;
  }
}

int func_800C3058(u8 param_0, unsigned int param_1) {
  Actor *local_0;
  if (param_0 != 0)
  {
    local_0 = func_800C1414(param_0);
    *((s16 *) (((char *) local_0) + 0x5A)) = param_1;
    if ((((u32)(*(s32 *)(((char *) local_0) + 0x78) << 28) >> 31) == 0))
    {
      *((s16 *) (((char *) local_0) + 0x4C)) = param_1;
      *((s16 *) (((char *) local_0) + 0x4E)) = param_1;
      *((f32 *) (((char *) local_0) + 0x50)) = 0.0f;
    }
    func_800C13A0(local_0, 8);
  }
}

void func_800C30B8(s32 param_0, s32 param_1, f32 *param_2, f32 param_3, f32 param_4) {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    func_800C1070(local_0, param_2);
    local_2 = func_800EEAD4(param_2, local_0);
    if (param_4 <= local_2) local_1 = 0.0f;
    else if (param_3 <= local_2) local_1 = 1.0f - (local_2 - param_3) / (param_4 - param_3);
    else local_1 = 1.0f;
    func_800C3058((u8)param_0, (s32)(param_1 * local_1));
}

void func_800C316C(u8 param_0, s32 param_1, s32 param_2, f32 param_3) {
    S800C316C *s;
    if (param_0 != 0) {
        s = func_800C1414(param_0);
        s->flag = 1;
        s->unk4C = param_1;
        s->unk4E = param_2;
        s->unk50 = param_3;
        s->unk5A = 0;
        func_800C13A0(s, 8);
    }
}

void func_800C31DC(u8 param_0, f32 param_1)
{
    u8 *temp;
    if (param_0 != 0)
    {
        temp = func_800C1414(param_0);
        *(f32*)((u8*)temp + 0x6C) = param_1;
        func_800C13A0(temp, 4);
    }
}

void func_800C3224(u8 param_0, f32 param_1, f32 param_2, f32 param_3)
{
    f32 local_0;
    local_0 = func_800C395C(param_0);
    if (local_0 < param_1) local_0 += param_3;
    else if (param_2 < local_0) local_0 -= param_3;
    else {
        local_0 += func_800DC264(-param_3, param_3);
        local_0 = func_800F0D50(local_0, param_1, param_2);
    }
    func_800C31DC(param_0, local_0);
}

void func_800C32C4(u8 param_0, s32 param_1) {
  u8 *temp;
  if (param_0 != 0)
  {
    temp = func_800C1414(param_0);
    *(u8*)(temp + 0x60) = param_1;
    func_800C13A0(temp, 0x10);
  }
}

void func_800C330C(u8 param_0, s32 param_1) {
  u8 *temp;
  if (param_0 != 0)
  {
    temp = func_800C1414(param_0);
    func_800C11F8(temp, param_1);
  }
}

void func_800C334C(u8 param_0, s32 param_1) {
  u8 *temp;
  if (param_0 != 0)
  {
    temp = func_800C1414(param_0);
    *(u8*)(temp + 97) = param_1;
    func_800C13A0(temp, 0x100);
  }
}

void func_800C3394(u8 param_0, s32 param_1, s32 param_2) {
  u8 *temp;
  if (param_0 != 0)
  {
    temp = func_800C1414(param_0);
    *(s32*)(temp + 0x64) = param_1;
    *(s32*)(temp + 0x68) = param_2;
  }
}

void func_800C33DC(u8 param_0, s32 param_1) {
  u8 *temp;
  if (param_0 != 0)
  {
    s8 *ptr = func_800C1414(param_0);
    ptr[0x1B] = (s8) param_1;
  }
}

void func_800C3418(u8 param_0, s32 param_1) {
  u8 *local_0;
  if (param_0 != 0)
  {
    local_0 = func_800C1414(param_0);
    switch (param_1)
    {
      case 0:
        func_800C13B0(local_0, 0x40);
        func_800C13B0(local_0, 0x80);
        return;

      case 1:
        func_800C13A0(local_0, 0x40);
        func_800C13B0(local_0, 0x80);
        return;

      case 2:
        func_800C13A0(local_0, 0x40);
        func_800C13A0(local_0, 0x80);
        break;

    }

  }
}

void func_800C34CC(u8 param_0, s32 param_1) {
  u8 *local_0;
  if (param_0 != 0)
  {
    local_0 = func_800C1414(param_0);
    if (param_1 != 0)
    {
      func_800C13B0(local_0, 0x200);
    }
    else
    {
      func_800C13A0(local_0, 0x200);
    }
  }
}

void func_800C3528(u8 param_0, s32 param_1) {
  u8 *local_0;
  if (param_0 != 0)
  {
    local_0 = func_800C1414(param_0);
    if (param_1 != 0)
    {
      func_800C13A0(local_0, 0x400);
    }
    else
    {
      func_800C13B0(local_0, 0x400);
    }
  }
}

void func_800C3584(u8 param_0, f32 param_1, f32 param_2)
{
    void *local_0;
    if (param_0) {
        local_0 = func_800C1414(param_0);
        *(f32 *)((char *)local_0 + 0xc) = param_1 * param_1;
        *(f32 *)((char *)local_0 + 0x10) = param_2 * param_2;
        func_800C368C(param_0, 1);
    }
}

void func_800C35E8(u8 param_0, s32 param_1) {
    void *p;
    if (param_0 != 0) {
        p = func_800C1414(param_0);
        func_800EE7F8(p, param_1);
        func_800C368C(param_0, 1);
        *(s16 *)((u8 *)p + 0x5E) = func_800EA05C();
    }
}

void func_800C3648(u8 param_0, s32 param_1) {
  u8 *temp;
  if (param_0 != 0)
  {
    temp = func_800C1414(param_0);
    *(u16 *)(temp + 0x5E) = func_800EA05C();
  }
}

void func_800C368C(u8 param_0, s32 param_1) {
  u8 *local_0;
  if (param_0 != 0)
  {
    local_0 = func_800C1414(param_0);
    if (param_1 != 0)
    {
      func_800C13A0(local_0, 0x2);
    }
    else
    {
      func_800C13B0(local_0, 0x2);
    }
    func_800C33DC(param_0, param_1);
  }
}

void func_800C36F4(u8 param_0, s32 param_1) {
  u8 *temp;
  if (param_0 != 0)
  {
    s8 *ptr = func_800C1414(param_0);
    ptr[0x62] = (s8) param_1;
  }
}

void func_800C3730(u8 param_0, f32 param_1, f32 param_2, f32 param_3)
{
  s32 *local_0;
  if (param_0 != 0)
  {
    local_0 = func_800C1414(param_0);
    *((u16 *) (((u8 *) local_0) + 0x7a)) = ((*((u16 *) (((u8 *) local_0) + ((0, 0x7a))))) & 0xfc3f) | 0x40;
    *((f32 *) (((u8 *) local_0) + 0x28)) = param_3;
    *((f32 *) (((u8 *) local_0) + 0x2c)) = param_2;
    func_800C31DC(param_0, param_1);
  }
}

void func_800C3798(u8 param_0, f32 param_1, f32 param_2)
{
  u8 *temp;
  if (param_0 != 0)
  {
    temp = func_800C1414(param_0);
    *(f32 *)(temp + 0x70) = param_1;
    *(f32 *)(temp + 0x74) = param_2;
  }
}

void func_800C37E0(u8 param_0, f32 param_1, f32 param_2, f32 param_3)
{
    void *local_0;
    if (param_0 != 0)
    {
        local_0 = func_800C1414(param_0);
        *((u16 *) (((u8 *) local_0) + 0x7A)) = ((*((u16 *) (((u8 *) local_0) + 0x7A))) & 0xFC3F) | 0x80;
        *((f32 *) (((u8 *) local_0) + 0x30)) = param_3;
        *((f32 *) (((u8 *) local_0) + 0x2C)) = param_1;
        *((f32 *) (((u8 *) local_0) + 0x28)) = param_2;
        func_800C31DC(param_0, (param_1 + param_2) * 0.5f);
    }
}

void func_800C3868(u8 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
    struct SomeStruct *local_0;

    if (param_0 != 0)
    {
        local_0 = (struct SomeStruct *)func_800C1414(param_0);
        local_0->unk7A = (local_0->unk7A & 0xFC3F) | 0xC0;
        local_0->unk28 = param_1;
        local_0->unk2C = param_2;
        local_0->unk30 = param_3;
        local_0->unk34 = param_4;
        func_800C31DC(param_0, param_3);
    }
}

s16 func_800C38E4(u8 param_0) {
    if (param_0 == 0) { return 0; }
    return *(s16 *)((u8 *)func_800C1414(param_0) + 0x58);
}

s16 func_800C3920(u8 param_0) {
    if (param_0 == 0) { return 0; }
    return *(s16 *)((u8 *)func_800C1414(param_0) + 0x5A);
}

f32 func_800C395C(u8 param_0) {
    if (param_0 == 0) {
        return 1.0f;
    }
    return *(f32 *)((u8 *)func_800C1414(param_0) + 0x6C);
}

s32 func_800C39A0(u8 param_0) {
    return (u32) *(u16 *)((u8 *)func_800C1414(param_0) + 0x7A) >> 0xD;
}

s32 func_800C39D0(u8 *param_0)
{
  int var_v1;
  if (func_800C13C4(param_0, 0x800) != 0)
  {
    return 1;
  }
  if (((*((u8 *) (((s8 *) param_0) + 0x63))) != 0) && (func_800C13C4(param_0, 2) != 0))
  {
    var_v1 = func_800C19E4(param_0, *((s16 *) (((s8 *) param_0) + 0x5A)));
  }
  else
  {
    var_v1 = *((s16 *) (((s8 *) param_0) + 0x5A));
  }
  return var_v1 >= 0x65;
}

void func_800C3A40(u8 param_0, f32 param_1, f32 param_2, f32 param_3)
{
    SoundC *local_0;
    if (!param_0) return;
    local_0 = func_800C1414(param_0);
    local_0->local_24.local_1.local_5 = 1;
    local_0->local_24.local_1.local_8 = 1;
    local_0->local_6 = param_1;
    local_0->local_7 = param_3;
    local_0->local_8 = param_2;
    local_0->local_12 = 0;
    if (!local_0->local_24.local_1.local_6) {
        local_0->local_24.local_1.local_6 = 1;
        local_0->local_9 = local_0->local_14;
        local_0->local_10 = local_0->local_14;
        local_0->local_14 = 0;
        local_0->local_11 = 0.0f;
    }
}

void func_800C3AE0(u8 param_0, f32 param_1)
{
    SoundC *local_0;
    if (!param_0) return;
    local_0 = func_800C1414(param_0);
    if (local_0->local_24.local_1.local_6) {
        local_0->local_9 *= param_1;
        local_0->local_10 *= param_1;
    } else {
        local_0->local_14 *= param_1;
    }
}

void func_800C3B8C(u8 param_0, s32 param_1) {
    if (param_0 != 0) { func_800C1414(param_0)->bit = param_1; }
}

void func_800C3BDC(u8 param_0) {
    local_type_800C3BDC *local_1;
    u32 local_2;
    if (param_0 != 0) {
        local_1 = func_800C1414(param_0);
        if (local_1->local_7) {
            func_800FEC60(4);
        }
        if ((func_800C39D0(local_1) != 0) || (func_800C42E0(*(s16 *)((char *)local_1 + 0x58)) != 0)) {
            if (local_1->local_4 == 2) {
                func_800C13A0(local_1, 1);
                if (local_1->local_5 == 1) {
                    return;
                }
                goto block_10;
            }
            if (local_1->local_5 == 1) {
                func_800C3CE8(param_0);
            }
        block_10:
            local_2 = func_800C15BC();
            osSetThreadPri(0, 0x33);
            func_800C16F8(local_1, local_2);
            func_800C1D80(param_0);
            osSetThreadPri(0, 0x14);
        }
    }
}

void func_800C3CE8(u8 param_0) {
    SoundC *local_0;
    if (!param_0) return;
    local_0 = func_800C1414(param_0);
    if (local_0->local_24.local_1.local_2 != 1) return;
    func_800C1860(local_0);
    if (local_0->local_24.local_1.local_7) func_800FECB8(4);
    if (local_0->local_21) local_0->local_21(param_0, local_0->local_22);
}

int func_800C3D78(u8 param_0) {
    SoundC *local_0;
    if (!(param_0 != 0)) return 0;
    local_0 = func_800C1414(param_0);
    return (param_0 != 0) && local_0->local_24.local_1.local_2 == 1 && local_0->local_24.local_0.local_1 && func_800C1448(local_0->local_24.local_0.local_1);
}

s32 func_800C3E00(s32 param_0)
{
  s32 *local_0;
  s32 local_1;
  local_0 = &D_80128C10;
  local_1 = 1;
  loop_1:
  if ((((*((u8 *) (((s8 *) local_0) + 0x78))) != 0) && (func_800C3D78(local_1) != 0)) && (param_0 == (*((s16 *) (((s8 *) local_0) + 0x58)))))
  {
    return 1;
  }

  local_1 += 1;
  local_0 += 0x20;
  if (local_1 == 0x3C)
  {
    local_1 = ((*((u8 *) (((s8 *) local_0) + 0x78))) != 0) * 0;
    return local_1;
  }
  goto loop_1;
}

void func_800C3E88(s32 param_0) {
    func_800C2840(param_0, 1.0f, 0x55F0, 0, 2);
}

void func_800C3EB8(int arg0)
{
  func_800C2840(arg0, 1.0f, 0x55F0, 0, 0);
}

void func_800C3EE4(s32 param_0, s32 param_1) {
    func_800C2840(param_0, 1.0f, param_1, 0, 2);
}

void func_800C3F14(s32 param_0, f32 param_1) {
    func_800C2840(param_0, param_1, 0x55F0, 0, 2);
}

void func_800C3F48(u32 param_0) {
  u32 local_1 = param_0 & 0x7FF;
  u32 local_2 = (param_0 >> 6) & 0x7FE0;
  u32 local_3 = 0;
  f32 local_0 = (f32)((param_0 >> 21) & 0x7FF);
  local_0 = local_0 / (f32)1024;
  func_800C2840(local_1, local_0, local_2, local_3, 2);
}

void func_800C3FC0(s32 param_0, f32 param_1, s32 param_2) {
    func_800C2840(param_0, param_1, param_2, 0, 2);
}

void func_800C3FF0(s32 p0, f32 p1, s32 p2) { func_800C2840(p0, p1, p2, 0, 0); }

void func_800C401C(s32 param_0, f32 param_1, s32 param_2, f32 *param_3, f32 param_4, f32 param_5, s32 param_6)
{
    u8 local_0;
    f32 local_1[3];
    func_800C1070(local_1, param_3);
    if (!(param_5 <= func_800EEAD4(local_1, param_3))) {
        local_0 = func_800C2E04();
        if (local_0) {
            func_800C3418(local_0, param_6);
            func_800C301C(local_0, param_0);
            func_800C3058(local_0, param_2);
            func_800C31DC(local_0, param_1);
            func_800C3584(local_0, param_4, param_5);
            func_800C35E8(local_0, param_3);
            func_800C330C(local_0, 1);
            func_800C33DC(local_0, 1);
            func_800C36F4(local_0, 0);
            func_800C3BDC(local_0);
        }
    }
}

void func_800C4104(s32 p0, f32 p1, s32 p2, s32 p3, f32 p4, f32 p5) {
    func_800C401C(p0, p1, p2, p3, p4, p5, 2);
}

void func_800C4140(s32 param_0, f32 *param_1, s32 param_2)
{
    func_800C401C((u32)param_0 & 0x7FF, (f32)(((u32)param_0 >> 21) & 0x7FF) / 1024, ((u32)param_0 >> 6) & 0x7FE0, param_1, (f32)((u32)param_2 & 0xFFFF), (f32)(((u32)param_2 >> 16) & 0xFFFF), 2);
}

void func_800C4208(s32 p0, f32 p1, s32 p2, s32 p3, f32 p4, f32 p5) {
    func_800C401C(p0, p1, p2, p3, p4, p5, 1);
}

void func_800C4244(s32 p0, f32 p1, s32 p2, s32 p3, f32 p4, f32 p5) {
    func_800C401C(p0, p1, p2, p3, p4, p5, 0);
}

void func_800C427C()
{
    func_800C2718();
}

int func_800C429C(s32 param_0, s32 param_1)
{
  u8 local_0;
  local_0 = func_800C2E04();
  func_800C301C(local_0, param_0);
  func_800C330C(local_0, param_1);
  return local_0;
}

int func_800C42E0(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  func_800DC548(0, local_0 - 0x3E9);
}

void func_800C4308(f32 param_0, f32 param_1)
{
  D_8011A870 = param_0;
  D_8011A874 = param_1;
}

void func_800C431C(u8 param_0, s32 param_1) {
    *(u8 *)((u8 *)func_800C1414(param_0) + 0x63) = param_1;
}

s32 func_800C4350(u8 param_0, f32 *param_1, s16 *param_2)
{
    C4350State *local_1;
    s16 local_14;
    s32 local_3;
    s32 local_12;
    s32 local_13;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;
    f32 local_9;
    s32 local_10 = 0; /* Deferred finalization request, controlled by opcodes. */
    if (!param_0) {
        local_12 = func_800C2E04();
        param_0 = local_12;
        if (!local_12) return 0;
        local_1 = (C4350State *)func_800C1414(param_0);
    } else local_1 = (C4350State *)func_800C1414(param_0);
    /* A supplied position enables positional handling and records its context. */
    if (param_1) {
        func_800EE7F8(local_1, param_1);
        func_800C13A0(local_1, 2);
        local_1->field1B = 1;
        local_1->field5E = func_800EA05C();
    }
    if (!param_2) {
        if (param_0) func_800C3BDC(param_0);
        return param_0;
    }
    while ((local_3 = *param_2++) != 0) {
        switch (local_3 & 0xFF) {
        case 1: /* Two distance operands are stored squared. */
            local_4 = param_2[0];
            local_5 = param_2[1];
            if (param_1) {
                local_1->field1B = 1;
                local_1->radiusSquared[0] = local_4 * local_4;
                local_1->radiusSquared[1] = local_5 * local_5;
                func_800C13A0(local_1, 2);
            }
            param_2 += 2;
            break;
        case 2: local_1->field63 = C4350_IMM; break;
        case 32:
            if (C4350_IMM) func_800C13B0(local_1, 0x200);
            else func_800C13A0(local_1, 0x200);
            break;
        case 34:
            if (C4350_IMM) func_800C13B0(local_1, 0x400);
            else func_800C13A0(local_1, 0x400);
            break;
        case 36:
            if (C4350_IMM) func_800C13A0(local_1, 0x800);
            else func_800C13B0(local_1, 0x800);
            break;
        /* These exits deliberately bypass deferred end-of-stream handling. */
        case 3: return param_0;
        case 4: func_800C2FDC(param_0); return 0;
        case 5:
            local_1->field60 = C4350_IMM;
            func_800C13A0(local_1, 0x10);
            break;
        case 6: func_800C11F8(local_1, C4350_IMM); break;
        case 7: local_1->field62 = C4350_IMM; break;
        case 8:
            local_1->field61 = C4350_IMM;
            func_800C13A0(local_1, 0x100);
            break;
        case 9:
            if ((u8)C4350_IMM) local_1->field1A = 1;
            else local_1->field1A = 0;
            break;
        case 10:
            local_4 = *param_2++ * 0.00390625f;
            local_1->field6C = local_4;
            func_800C13A0(local_1, 4);
            break;
        /* Modes select different layouts for the fractional control operands. */
        case 11:
            local_4 = param_2[0] * 0.00390625f;
            local_5 = param_2[1] * 0.00390625f;
            local_6 = param_2[2] * 0.00390625f;
            param_2 += 3;
            C4350_MODE(1);
            local_1->field6C = local_4;
            local_1->field2C = local_5;
            local_1->field28 = local_6;
            func_800C13A0(local_1, 4);
            break;
        case 12:
            local_4 = *param_2++ * 0.00390625f;
            local_5 = *param_2++ * 0.00390625f;
            local_6 = *param_2++ * 0.00390625f;
            local_7 = *param_2++ * 0.00390625f;
            C4350_MODE(3);
            local_1->field28 = local_4;
            local_1->field2C = local_5;
            local_1->field30 = local_6;
            local_1->field34 = local_7;
            func_800C13A0(local_1, 4);
            break;
        case 13: { /* Select a random value between two /256 operands. */
            f32 local_4, local_5;
            local_4 = param_2[0] * 0.00390625f;
            local_5 = param_2[1] * 0.00390625f;
            param_2 += 2;
            local_1->field6C = func_800DC264(local_4, local_5);
            func_800C13A0(local_1, 4);
            break;

        }
        case 29:
            local_4 = (*((C4350Defaults *) &D_8012A990)).local_0;
            local_1->field6C = local_4;
            func_800C13A0(local_1, 4);
            break;
        case 14:
            local_4 = param_2[0] * 0.00390625f;
            local_5 = param_2[1] * 0.00390625f;
            local_6 = param_2[2] * 0.00390625f;
            param_2 += 3;
            C4350_MODE(2);
            local_1->field2C = local_4;
            local_1->field28 = local_5;
            local_1->field30 = local_6;
            local_1->field6C = (local_4 + local_5) * 0.5f;
            func_800C13A0(local_1, 4);
            break;
        case 15:
            func_800C11F8(local_1, 1);
            local_10 = 1;
            local_1->field62 = 0;
            break;
        case 16: func_800C2E40(param_0); break;
        case 17: local_10 = 1; break;
        case 18: /* Cancel deferred finalization; conditionally invoke callback. */
            local_10 = 0;
            if (((local_1->flags.word << 19) >> 29) == 1) {
                func_800C1860(local_1);
                if (local_1->callback) {
                    (local_1->callback)(param_0, local_1->callbackArgument);
                }
            }
            break;
        case 19: local_14 = *param_2++; local_1->field58 = local_14; break;
        case 20:
            if (param_1) {
                local_1->field1B = C4350_IMM;
                if (C4350_IMM) func_800C13A0(local_1, 2);
                else func_800C13B0(local_1, 2);
            }
            break;
        case 21: {
            f32 local_4, local_5, local_6;
            local_4 = param_2[0] * 0.00390625f;
            local_5 = param_2[1] * 0.00390625f;
            local_6 = param_2[2] * 0.00390625f;
            param_2 += 3;
            func_800C3A40(param_0, local_4, local_5, local_6);
            break;

        }
        case 31: local_1->field1D = 1; break;
        case 22: func_800C3058(param_0, *param_2++); break;
        case 23: /* Unlike fractional opcodes, the third operand is unscaled. */
            local_12 = param_2[0];
            local_13 = param_2[1];
            local_4 = param_2[2];
            param_2 += 3;
            func_800C316C(param_0, local_12, local_13, local_4);
            break;
        case 24: func_800C3058(param_0, 0x7FFF); break;
        case 25:
            func_800C3058(param_0, func_800DC214(param_2[0], param_2[1]));
            param_2 += 2;
            break;
        case 30: func_800C3058(param_0, (*((C4350Defaults *) &D_8012A990)).local_1); break;
        case 26:
            local_4 = param_2[0] * 0.00390625f;
            local_5 = param_2[1] * 0.00390625f;
            param_2 += 2;
            local_1->field70 = local_4;
            local_1->field74 = local_5;
            break;
        case 27: func_800C3418(param_0, C4350_IMM); break;
        case 28: local_1->flags.bits.enabled = 1; break;
        case 33: func_800C301C(param_0, (*((C4350Defaults *) &D_8012A990)).local_2); break;
        case 35:
            local_4 = *param_2++ * 0.00390625f;
            local_5 = *param_2++ * 0.00390625f;
            local_6 = *param_2++ * 0.00390625f;
            local_7 = *param_2++ * 0.00390625f;
            local_8 = *param_2++ * 0.00390625f;
            local_9 = *param_2++ * 0.00390625f;
            C4350_MODE(4);
            local_1->field28 = local_4;
            local_1->field2C = local_5;
            local_1->field30 = local_6;
            local_1->field34 = local_7;
            local_1->field38 = local_8;
            local_1->field3C = local_9;
            func_800C13A0(local_1, 4);
            break;
        }
    }
    /* A zero terminator finalizes only when a command requested it. */
    if (local_10) func_800C3BDC(param_0);
    return param_0;
}

void func_800C4AF0(f32 *param_0, void *param_1) {
    s32 r;
    u8 h;
    r = func_800C4350(0, param_0, param_1);
    h = r;
    if (r == 0) {
        return;
    }
    if (param_0 == 0) {
        func_800C33DC(h, 0);
    }
    func_800C330C(h, 1);
    func_800C36F4(h, 0);
    func_800C3BDC(h);
}

void func_800C4B64(f32 param_0)
{
  D_8012A990 = param_0;
}

int func_800C4B70(param_0) int param_0;
{
  if ((param_0 && param_0) && param_0)
  {
  }
  D_8012A994 = param_0;
}

void func_800C4B7C(param_0) unsigned int param_0;
{
  D_8012A996 = param_0;
}
