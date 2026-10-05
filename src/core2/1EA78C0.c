#include "core2/1EA78C0.h"
extern f32 D_801259B0;

typedef struct { u8 pad[0x24]; u32 local_0; } ActorCDFD0;
typedef struct { u8 pad[19]; u8 local_0:1; u8 pad1:7; } PropCDFD0;
extern s32 D_8012B020[];
extern s32 func_800DAB54(s32 *, s32);
extern void func_800EC370();
extern void **func_800BDD24(s32 *);
extern PropCDFD0 *func_800E9D68(void *);
extern s32 func_800E9DD4(void *);
extern s32 _gspropctrl_entrypoint_0(PropCDFD0 *);
extern s32 _gspropctrl_entrypoint_1(PropCDFD0 *, s32 *);
extern void func_800D5318(PropCDFD0 *, ActorCDFD0 *);
extern u16 D_8011AA10[7][2];
extern void func_800DAA8C(void *, s32, s32);
extern void func_800BE52C(s32 *, s32 *);
extern void func_800DAAF8();
extern void func_800DAB8C();
extern s32 func_800E9D90(s32);
typedef struct { u8 unk4; u8 unkA; } Struct_800CE308;
typedef struct { s16 x; s16 y; s16 z; } E_CE3F4;
extern void func_800D2498();
typedef struct { f32 unk0; u8 pad4[6]; s16 unkA; f32 unkC; s16 unk10; } S_CE438;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_8011AA34;
typedef struct { f32 field_0, field_4; s16 field_8, field_A; u8 pad_C[6]; s8 field_12; u8 field_13, field_14, pad_15[3]; void (*field_18)(s32, s32); s32 field_1C; } LocalTimer;
typedef struct { s16 field_0, field_2, field_4; } LocalConfig_800CE628;
extern LocalConfig_800CE628 D_8011AA30[];
extern s32 func_800EA09C(void);
extern s32 func_800DB9B0(void);
extern f32 func_800D9004(void);
extern s32 func_800F6D24(s32);
extern s32 func_800F8004(s32);
extern s32 func_800F68B8(s32);
extern u8 D_8012B030[];
typedef struct { f32 unk0; f32 unk4; s16 unk8; s16 unkA; f32 unkC; s16 unk10; u8 pad12[3]; u8 unk15; u8 pad16[2]; s32 unk18; } S_CE8D8;
extern u8 unk12[];
typedef struct { f32 unk0; u8 pad[0xE]; s8 unk12; u8 unk13, unk14, unk15, unk16; } ControlCEC94;
typedef struct { u8 pad[0x120]; u8 unk120, unk121; } AudioCEC94;
extern s16 D_8011AA68[];
extern void func_800FC6B0(u32);
extern void func_800FC74C(u32);
extern void func_800FCD14(s32, s32);
extern void func_800C3BDC(s32);
extern void func_800C2FDC(s32);
extern s32 func_800C4350();
typedef struct { f32 unk0; u8 pad4[0x10]; } E_CEF00;
typedef struct { s16 unk0; u8 pad[18]; } E20_CEF48;
extern E20_CEF48 D_8011AA8E[];
extern f32 D_8012B170;
typedef struct { s16 a[4]; s16 b; s16 c; u8 d; u8 pad[3]; f32 e; } StateCEF7C;
StateCEF7C D_8012B160;
typedef struct { s32 pad; s16 local_0, local_1; f32 local_2; s32 pad2[2]; } EntryCF01C;
extern s16 D_8012B168;
extern s16 D_8012B16A;
extern f32 func_800D8FF8(void);
extern void func_800C3FF0(s32, f32, s32);
extern void func_800FC63C(s32, s32);
extern u8 D_8012B16C;
extern void func_8008FBC0(void);
extern void func_8008FBE0(u32);
extern u32 func_8008FC00(void);
extern void func_800D9078(void *);
extern void func_800F7B9C(u32, void *);
extern f32 D_8012B178;
extern f32 D_8012B174;
extern u32 D_8012B17C;
extern s32 func_800D3E40(s32);
extern void *func_800F54E4(void);
extern s32 func_800F6604(void *);
extern short D_8012B15E[];
typedef struct { u8 pad_0[0xC]; s16 field_C; u8 pad_E[2]; f32 field_10; } LocalConfig_800CF734;
extern LocalConfig_800CF734 D_8011AA80[];
int func_800CE1A8();
int func_800CE21C();
void func_800CEC94();
s32 func_800CF580();
s32 func_800CF640();
f32 func_800CF67C();
int func_800CF6D0();
void func_800CF734();
void func_800CF7F4();

void func_800CDFD0(ActorCDFD0 *param_0) {
    s32 local_8;
    s32 local_0[3];
    s32 local_1[3];
    s32 local_2;
    s32 local_3;
    s16 local_4[3];
    PropCDFD0 *local_5;
    PropCDFD0 *local_6;
    void **local_7;
    local_2 = func_800CE21C(param_0->local_0 >> 22);
    if (local_2 == -1) return;
    if (func_800DAB54(D_8012B020, local_2) != 1) return;
    func_800EC370(param_0, local_4);
    local_0[0] = local_4[0];
    local_0[1] = local_4[1];
    local_0[2] = local_4[2];
    for (local_7 = func_800BDD24(local_0); *local_7; local_7++) {
        local_5 = func_800E9D68(*local_7);
        local_6 = func_800E9DD4(*local_7) + local_5;
        for (; local_5 < local_6; local_5++) {
            if (_gspropctrl_entrypoint_0(local_5) == local_2) {
                local_3 = _gspropctrl_entrypoint_1(local_5, local_1);
                if (local_1[1] - local_3 < local_0[1] && local_0[1] < local_1[1] + local_3) {
                    if (local_5->local_0) {
                        if (func_800CE1A8(local_0, local_1, local_3)) {
                            func_800D5318(local_5, param_0);
                        }
                    } else {
                        if (local_1[0] - local_3 < local_0[0] && local_0[0] < local_1[0] + local_3 && local_1[2] - local_3 < local_0[2] && local_0[2] < local_1[2] + local_3) {
                            func_800D5318(local_5, param_0);
                        }
                    }
                }
            }
        }
    }
}

int func_800CE1A8(param_0, param_1, param_2) int * param_0; int * param_1; int param_2;
{
    int local_0;
    int local_1;
    int local_2;
    int local_3;
    int local_4;
    local_0 = param_2 * D_801259B0;
    local_1 = param_0[0] - param_1[0] + local_0;
    local_2 = param_0[2] - param_1[2];
    local_4 = local_1 - local_2;
    local_3 = local_0 * 2;
    if (local_1 + local_2 < 0 || local_3 < local_1 + local_2) return 0;
    return local_4 > 0 && local_4 < local_3;
}

int func_800CE21C(param_0) s32 param_0; {
    s32 local_0;
    for (local_0 = 0; local_0 < 7; local_0++) {
        if (param_0 == D_8011AA10[local_0][0]) return D_8011AA10[local_0][1];
    }
    return -1;
}

void func_800CE2DC(void) {
    func_800DAA8C(((u8 *) D_8012B020), 7, 2);
}

void func_800CE308()
{
    u32 local_0;
    u32 local_1;
    u32 local_4;
    Struct_800CE308 *local_2;

    func_800DAB8C(((u8 *) D_8012B020), 0);
    func_800BE52C(&local_0, &local_1);
    if (local_0 < local_1) {
        do {
            if (func_800E9DD4(local_0) != 0) {
                local_2 = (Struct_800CE308 *) func_800E9D68(local_0);
                local_4 = func_800E9D90(local_0);
                if (local_2 < (Struct_800CE308 *) local_4) {
                    do {
                        if (!(*(s32 *)((char *)local_2 + 4) & 1)) {
                            func_800DAAF8(((u8 *) D_8012B020), *(u8 *)((char *)local_2 + 10), 1);
                        }
                        local_2 = (Struct_800CE308 *) ((u32)local_2 + 0x14);
                    } while (local_2 < (Struct_800CE308 *) local_4);
                }
            }
            local_0 += 8;
        } while (local_0 < local_1);
    }
}

u8 *func_800CE3E0(param_0) s32 param_0;
{
    return (u8 *)((param_0 << 5) + (s32)((struct struct_func_8012B030 *) D_8012B030));
}

void func_800CE3F4(void *param_0, s32 param_1) {
    func_800D2498(((E_CE3F4 *) D_8011AA30)[param_1].x, *(s16 *)((u8 *)param_0 + 0xA), 0);
}

void func_800CE438(param_0, param_1) S_CE438 *param_0; s32 param_1; {
    param_0->unk0 = func_800F10B4((f32)param_0->unkA, 0.0f, (f32)param_0->unk10, 0.0f, param_0->unkC);
    func_800CE3F4(param_0, param_1);
}

void func_800CE49C(u8 *param_0, s32 param_1, s32 param_2) {
    *(s16 *)(param_0 + 0xA) = (s32)(func_800F10B4(*(f32 *)param_0, 0.0f,
        *(f32 *)(param_0 + 0xC), 1.0f, (f32)*(s16 *)(param_0 + 0x10) + 1.0f) - 0.0001f);
    if (param_2) func_800CE3F4(param_0, param_1);
}

void func_800CE524(void)
{
    s32 local_0;
    void *local_1;
    for (local_0 = 0; local_0 < 9; local_0++)
    {
        local_1 = func_800CE3E0(local_0);
        *(s16 *)((char *)local_1 + 0x8) = 0;
        *(s16 *)((char *)local_1 + 0xA) = *(s16 *)((char *)local_1 + 0x8);
        *(f32 *)((char *)local_1 + 0x0) = 0.0f;
        *(f32 *)((char *)local_1 + 0x4) = 0.0f;
        *(u8 *)((char *)local_1 + 0x16) = 0;
        *(u8 *)((char *)local_1 + 0x15) = 0;
        *(u8 *)((char *)local_1 + 0x14) = 0;
        *(u8 *)((char *)local_1 + 0x12) = 0;
        *(u8 *)((char *)local_1 + 0x13) = 0;
        *(s32 *)((char *)local_1 + 0x18) = 0;
        *(s32 *)((char *)local_1 + 0x1C) = 0;
    }
}

s32 func_800CE59C(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
  u16 local_0;
  local_0 = *(u16 *)((u8 *) &D_8011AA34 + param_0 * 6);
  if ((param_1 != 0) && (local_0 & 4))
  {
    return 0;
  }
  if ((param_2 != 0) && (local_0 & 1))
  {
    return 0;
  }
  if ((param_3 != 0) && (local_0 & 2))
  {
    return 0;
  }
  if ((param_4 != 0) && (local_0 & 8))
  {
    return 0;
  }
  return 1;
}

void func_800CE628(void)
{
    LocalTimer *local_0;
    f32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    s32 local_8;
    void (*local_9)(s32, s32);
    s32 local_10;
    if (func_800EA09C() == 2) {
        local_2 = func_800F54E4();
        local_1 = func_800D9004();
        local_3 = func_800DB9B0();
        local_4 = func_800F6D24(local_2);
        local_5 = func_800F8004(local_2);
        local_6 = func_800F68B8(local_2);
        for (local_7 = 0; local_7 != 9; local_7++) {
            local_0 = func_800CE3E0(local_7);
            local_8 = func_800CE59C(local_7, local_3, local_4, local_5, local_6);
            if (local_0->field_12 > 0 && !local_0->field_13 && !local_0->field_14 && local_8) {
                local_0->field_4 = local_0->field_0;
                local_0->field_8 = local_0->field_A;
                local_0->field_0 -= local_1;
                if (local_0->field_0 < 0.0f) {
                    local_0->field_0 = 0.0f;
                    if (local_0->field_18) {
                        local_9 = local_0->field_18;
                        local_10 = local_0->field_1C;
                        local_0->field_18 = 0;
                        local_0->field_1C = 0;
                        local_9(local_7, local_10);
                    }
                    local_0->field_12 = 0;
                }
                func_800CE49C(local_0, local_7, 1);
            }
            if (D_8011AA30[local_7].field_2) func_800CEC94(local_0, local_7, local_8);
            local_0->field_14 = 0;
        }
    }
}

void func_800CE7DC(void)
{
  if (D_8012B030[0x120] != 0)
  {
    func_800C2FDC(D_8012B030[0x120]);
    D_8012B030[0x120] = 0;
  }
  if (D_8012B030[0x121])
  {
    func_800FC74C(0x92);
    D_8012B030[0x121] = 0;
  }
}

void func_800CE83C(s32 param_0, s32 param_1) {
    *(u8 *)(func_800CE3E0(param_0) + 0x13) = param_1;
}

void func_800CE864() {
    s8 *ptr = func_800CE3E0();
    ptr[0x14] = 1;
}

void func_800CE88C(void *param_0, s32 param_1)
{
    s8 *local_0;

    local_0 = func_800CE3E0(param_0);
    if (param_1 != 0) {
        local_0[0x12]++;
        return;
    }
    if (local_0[0x12] != 0) {
        local_0[0x12]--;
    }
}

void func_800CE8D8(void *param_0, f32 param_1, s32 param_2) {
    S_CE8D8 *p = func_800CE3E0(param_0);
    p->unk15 = 0;
    p->unk18 = 0;
    p->unk10 = p->unkA = p->unk8 = param_2;
    p->unk0 = p->unk4 = p->unkC = param_1;
}

int func_800CE928(s32 param_0, s32 param_1, s32 param_2)
{
  typedef struct 
  {
    char pad[0x18];
    s32 unk18;
    s32 unk1C;
  } Actor;
  Actor *local_0;
  local_0 = (Actor *) func_800CE3E0(param_0);
  local_0->unk18 = param_1;
  local_0->unk1C = param_2;
}

s32 func_800CE95C(void) {
    return (*(s32 *)((s8 *)(func_800CE3E0()) + (0x18)));
}

int func_800CE980(s32 param_0, f32 param_1, s32 param_2)
{
  f32 local_0;
  f32 *local_1;
  local_1 = func_800CE3E0();
  local_0 = param_1;
  if (local_1[3] < local_0)
  {
    local_1[3] = local_0;
  }
  local_1[1] = local_0;
  local_1[0] = local_0;
  func_800CE49C(local_1, param_0, !param_2);
}

int func_800CE9E8(s32 param_0, s32 param_1)
{
    s32 local_0;
    local_0 = func_800CE3E0(param_0);
    if ((s16)*(s16*)((char*)local_0 + 0x10) < param_1) {
        *(s16*)((char*)local_0 + 0x10) = (s16)param_1;
    }
    *(s16*)((char*)local_0 + 0x8) = (s16)param_1;
    *(s16*)((char*)local_0 + 0xA) = (s16)param_1;
    func_800CE438(local_0, param_0, param_1);
}

void func_800CEA38(s32 param_0, int param_1)
{
  s32 local_0;
  local_0 = func_800CE3E0(param_0);
  *((u8 *) (local_0 + 0x15)) = param_1;
}

f32 func_800CEA60()
{
    f32 *v0 = func_800CE3E0();
    return *v0;
}

int func_800CEA84()
{
  s16 *local_0;
  local_0 = func_800CE3E0();
  return *(s16*)((s8*)local_0 + 0xA);
}

s32 func_800CEAA8() {
    return (*(s8 *)((s8 *)(func_800CE3E0()) + (0x12))) > 0;
}

s32 func_800CEAD0(void) {
    f32 local_0;
    local_0 = func_800CEA60();
    return local_0 == 0.0f;
}

s32 func_800CEB08(f32 *param_0, f32 param_1) {
    if (((s8 *)param_0)[0x12] != 0) {
        if (param_1 <= param_0[1]) {
            if (param_0[0] < param_1) {
                return 1;
            }
        }
    }
    return 0;
}

int func_800CEB54(s32 param_0, f32 param_1)
{
  func_800CEB08(func_800CE3E0(param_0), param_1);
}

int func_800CEB80(s32 param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_800CE3E0(param_0);
  if ((*(s8 *)((char *)(local_0) + 0x12)) != 0 && param_1 < (*(s16 *)((char *)(local_0) + 0x8)) && param_1 >= (*(s16 *)((char *)(local_0) + 0xA)))
  {
    return 1;
  }
  return 0;
}

void func_800CEBD8(s32 param_0, s32 param_1)
{
  s32 local_0;
  short new_var;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  local_0 = func_800F54E4();
  if (param_1 != 0)
  {
    local_3 = func_800DB9B0();
    local_2 = func_800F6D24(local_0);
    local_1 = func_800F8004(local_0);
    if (func_800CE59C(param_0, local_3, local_2, local_1, func_800F68B8(local_0)) != 0)
    {
      func_800CE3F4(func_800CE3E0(param_0), param_0);
      return;
    }
  }
  new_var = *(short*)((char*)((short *) D_8011AA30) + (param_0 * 3) * 2);
  func_800D284C(new_var);
}

void func_800CEC94(param_0, param_1, param_2) ControlCEC94 * param_0; s32 param_1; s32 param_2; {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    local_0 = (param_0->unk0 > 1.0f) && (param_0->unk0 < 5.0f);
    local_1 = (param_0->unk0 > 0.0f) && (param_0->unk0 < 1.0f);
    local_2 = (param_0->unk12 > 0) && !param_0->unk13 && !param_0->unk14 && (!param_2 || param_0->unk15);
    if (!local_2) {
        local_1 = 0;
        local_0 = 0;
    }
    if (local_0 || local_1 || param_0->unk16) {
        if (local_0) {
            if (!(*((AudioCEC94 *) D_8012B030)).unk121) {
                func_800FC6B0(0x92);
                (*((AudioCEC94 *) D_8012B030)).unk121 = 1;
            }
            func_800FCD14(0x92, (s32)(((param_0->unk0 - 1.0f) * (200000.0f) / 4) + (200000.0f)));
        } else if ((*((AudioCEC94 *) D_8012B030)).unk121) {
            func_800FC74C(0x92);
            (*((AudioCEC94 *) D_8012B030)).unk121 = 0;
        }
        if (local_1) {
            local_2 = (*((AudioCEC94 *) D_8012B030)).unk120;
            if (!local_2) {
                (*((AudioCEC94 *) D_8012B030)).unk120 = func_800C4350(0, 0, D_8011AA68);
            }
            local_2 = (*((AudioCEC94 *) D_8012B030)).unk120;
            func_800C3BDC(local_2);
        } else {
            local_2 = (*((AudioCEC94 *) D_8012B030)).unk120;
            if (local_2) {
                func_800C2FDC(local_2);
                (*((AudioCEC94 *) D_8012B030)).unk120 = 0;
            }
        }
        param_0->unk16 = local_0 || local_1;
    }
}

f32 func_800CEF00(s32 param_0) {
    return ((E_CEF00 *) D_8011AA80)[param_0].unk0 * (f32)func_800CF6D0(param_0);
}

f32 func_800CEF48(s32 param_0) { return (f32)D_8011AA8E[param_0].unk0; }

void func_800CEF6C()
{
  D_8012B170 = 0.0f;
}

s32 func_800CEF7C(void)
{
    s32 local_1;
    s32 local_2;
    f32 local_0;
    s32 local_3;
    s32 local_4;
    local_0 = func_800CEF00(0);
    local_1 = func_800CF6D0();
    func_800CE8D8(1, local_0, local_1);
    if (D_8012B160.e != 0.0f) func_800CE980(1, D_8012B160.e, 1);
    for (local_3 = 0; local_3 < 4; local_3++) {
        D_8012B160.a[local_3] = 9;
    }
    D_8012B160.b = 0;
    local_2 = func_800CEA84(1);
    D_8012B160.c = local_2;
    D_8012B160.d = 0;
    return local_2;
}

void func_800CF01C(void) {
    s32 local_0;
    s32 local_1;
    f32 local_2;
    f32 local_3;
    EntryCF01C *local_4;
    f32 local_5;
    s32 local_6, local_7;
    local_0 = func_800CEAA8(1) + D_8012B168;
    local_2 = func_800CEA60(1);
    local_3 = func_800CEF00(0);
    if (!func_800CF580()) { func_800CE864(1); return; }
    if (local_0 == 0 && local_2 < local_3) {
        local_2 += func_800D8FF8();
        if (local_3 < local_2) local_2 = local_3;
        func_800CE980(1, local_2, 0);
    }
    local_1 = func_800CEA84(1);
    if (local_1 != D_8012B16A) {
        local_4 = &((EntryCF01C *) D_8011AA80)[func_800CF640()];
        local_5 = local_4->local_2;
        local_6 = local_4->local_0;
        local_7 = local_4->local_1;
        if (local_5 >= 0.0f) func_800C3FF0(local_6, local_5, local_7);
        else func_800FC63C(local_6, local_7);
        D_8012B16A = local_1;
    }
}

void func_800CF160(f32 param_0, s32 param_1)
{
    ((u8 *) &D_8012B160)[0xC] = 1;
    *(f32 *)&((u8 *) &D_8012B160)[0x14] = param_0;
    *(f32 *)&((u8 *) &D_8012B160)[0x18] = 0.0f;
    *(s32 *)&((u8 *) &D_8012B160)[0x1C] = param_1;
}

void func_800CF184()
{
  D_8012B16C = 0;
}

void func_800CF190(void)
{
  f32 *new_var;
  if (func_800CF67C() != 0.0f)
  {
    func_800CF184();
    return;
  }
  new_var = &D_8012B174;
  if (func_800CF580() != 0)
  {
    func_800CF7F4(1);
    func_8008FBE0(1);
    func_800D9078(&D_8012B178);
    if (D_8012B178 <= 0.0f)
    {
      if (1)
      {
        D_8012B178 = *new_var;
      }
      func_8008FBC0();
      if (func_8008FC00() == 0)
      {
        func_800F7B9C(func_800F54E4(), D_8012B17C);
        func_800CF184();
      }
    }
  }
}

void func_800CF264(void) {
    if (func_800EA09C() == 2) {
        func_800CF01C();
        if (D_8012B16C != 0) {
            func_800CF190();
        }
    }
}

void func_800CF2B0()
{
  D_8012B170 = func_800CEA60(1);
}

void func_800CF2D4(s32 param_0) {
  s32 _pad;
    f32 local_0;
    f32 local_1;

    if (func_800D3E40(9) == 0) {
        ((s16*)((s32 *) &D_8012B160))[func_800CEAA8(1)] = param_0;
        local_0 = func_800CF67C();
        local_1 = func_800CEF00(param_0);
        func_800CE8D8(1, local_1, func_800CF6D0());
        func_800CE980(1, local_0 * local_1, 0);
        func_800CE928(1, &func_800CF734, 0);
        func_800CE88C(1, 1);
        if (func_800F6604(func_800F54E4()) != 0) {
            if (func_800CEF48(param_0) == 0.0f) {
                func_800F7B9C(func_800F54E4(), 0x57);
            }
        } else if (func_800CEF48(param_0) != 0.0f) {
            func_800F7B9C(func_800F54E4(), 0x56);
        }
    }
}

void func_800CF40C(s32 param_0) {
    f32 local_0;
    f32 local_1;
    local_0 = func_800CEA60(1);
    local_1 = func_800CEF00(func_800CF640());
    local_0 += (f32)param_0 * local_1 / (f32)func_800CF6D0();
    if (local_1 < local_0) local_0 = local_1;
    func_800CE980(1, local_0, 0);
}

void func_800CF494(void) {
    s32 unbenutzt;
    f32 sp20;
    f32 sp1C;
    s32 temp_v0;
    s16 rest;

    if (func_800D3E40(9) == 0) {
        temp_v0 = func_800CEAA8(1);
        rest = *(s16 *)((s8 *)(((u16 *) &D_8012B160)) + 8);
        if (rest != 0) {
            *(s16 *)((s8 *)(((u16 *) &D_8012B160)) + 8) = rest - 1;
            return;
        }
        if (temp_v0 > 0) {
            *(s16 *)((s8 *)(((u16 *) &D_8012B160)) + temp_v0 * 2) = 9;
            sp20 = func_800CF67C(temp_v0, ((u16 *) &D_8012B160));
            func_800CE88C(1, 0);
            sp1C = func_800CEF00(func_800CF640());
            func_800CE8D8(1, sp1C, func_800CF6D0());

            func_800CE980(1, sp20 * sp1C, 0);
            if (func_800F6604(func_800F54E4()) != 0) {
                func_800F7B9C(func_800F54E4(), 0x57);
            }
        }
    }
}

s32 func_800CF580()
{
  s32 local_0;
  if (func_800A9C98())
  {
    return 0;
  }
  if (func_800D3E40(9))
  {
    return 0;
  }
  local_0 = func_800F54E4();
  if (!func_800F6BE4(local_0 | 0))
  {
    return 0;
  }
  if (func_800F6D24(local_0) != 0)
  {
    return 0;
  }
  if (func_800F64A4(local_0, 0x1A000) != 0)
  {
    return 0;
  }
  if (func_800F8B88() == 3)
  {
    return 0;
  }
  return 1;
}

s32 func_800CF640() {
    int local_0;
    int local_1;
    local_1 = func_800CEAA8(1);
    if (local_1) {
        local_0 = D_8012B15E[local_1];
    } else {
        local_0 = 0;
    }
    return local_0;
}

f32 func_800CF67C(void) {
    return func_800CEA60(1) / func_800CEF00(func_800CF640());
}

void func_800CF6B0()
{
    func_800CEA84(0x1);
}

int func_800CF6D0()
{
  s32 local_0;
  local_0 = func_800DA298(0x1BF) ? 0xA : 0x6;
  return local_0 | 0;
}

int func_800CF700()
{
  s32 local_0;
  func_800DA544(0x1BF);
  local_0 = func_800CF6D0();
  func_800CE9E8(1, local_0 | 0);
}

void func_800CF734(param_0, param_1) s32 param_0; s32 param_1;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    local_0 = func_800CF640();
    if (D_8011AA80[local_0].field_10 > 0.0f) func_800CF160(D_8011AA80[local_0].field_10, D_8011AA80[local_0].field_C);
    local_1 = func_800CEAA8(1);
    for (local_2 = 0; local_2 < local_1; local_2++) func_800CF494();
    D_8012B168 = local_1;
    func_800CE928(1, func_800CF734, 0);
}

void func_800CF7F4(param_0) u32 param_0; {
    if (((func_800CF580() != 0) && (func_800A16A4() == 0)) || (param_0 == 0)) {
        func_800CEBD8(1, param_0);
    }
}

int func_800CF840(s32 param_0)
{
  func_800CE83C(1, param_0 | 0);
}
