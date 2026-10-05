#include "core2/1ED68A0.h"

extern f32 D_80135A30[];
extern u8 D_801359D5;
extern u8 D_80135A3C[];
extern s32 D_80135A40;
extern u8 unkA[];
extern u8 unk8[];
extern u8 unk4[];
extern s32 D_80135A20[];
extern s32 func_800CBBE0();
extern f32 func_800EEAD4(void *, void *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800EFFB4(void *, f32, void *);
extern s32 _gcmapsects_entrypoint_7(void *);
extern f32 func_800D8FF8(void);
extern s32 D_80123F68;
extern s32 D_80124004;
extern s32 D_8012401C;
extern s32 D_80124028;
extern s32 D_80124034;
extern s32 D_80124040;
extern s32 D_801241D8;
extern f32 D_801241E4[4];
extern f32 D_801241F4[3];
extern f32 D_80124200[3];
extern f32 D_8012420C[3];
extern f32 D_80124218[3];
extern s8 D_801359D1;
extern u8 D_80135A1E;
extern f32 D_80135A44;
typedef struct { s32 unk0; s32 unk4; } E_FDBB8;
extern u8 D_80135A00;
extern E_FDBB8 D_80124224[];
typedef struct { u8 pad0[0x18]; u8 unk18; u8 pad19[0x27]; u8 unk40; } G_FDC28;
typedef struct { f32 value_00; /* Volume/scale passed to func_800FC934. */ f32 value_04; /* Multiplier for the tempo-derived value. */ s16 value_08; /* Main sound handle; -1 means absent. */ u8 pad_0A[5]; u8 value_0F, value_10; u8 pad_11[2]; u8 value_13, value_14, pad_15, value_16, value_17, value_18; u8 pad_19[7]; s16 value_20, value_22; u8 pad_24[4]; s32 value_28; u8 pad_2C[0x10]; f32 value_3C; u8 value_40, value_41; } FDC58State;
typedef struct { s32 local_0[2]; s16 local_1[2]; } FDC58Entry;
extern FDC58Entry D_80123E84[];
extern FDC58Entry D_80123FC8;
extern FDC58Entry D_80124064;
extern FDC58Entry D_801241CC;
extern FDC58Entry D_8012419C;
extern FDC58Entry D_80124010;
extern FDC58Entry D_80124124;
extern FDC58Entry *D_80135A04;
extern FDC58Entry *D_80135A08;
extern u8 D_801359E8[];
extern u8 D_801359EC[];
extern s32 D_80135A2C;
extern void func_8008FE68(f32 *);
extern s32 func_800CBC00(s32);
extern s32 func_800CCEF4(f32 *, void *, void *, s32, s32);
extern s32 func_800FCCD4();
extern void func_800FCAE0(s32, s32, s32);
extern void func_800FCA90();
extern void func_800FC97C(s32, f32, f32);
extern s32 func_800FCDE0(s32, s32, f32);
extern s32 func_800FCED0(s32, s32, f32);
extern void func_800FC934(s32, f32, f32);
extern s16 D_801359C8;
extern u8 D_80135A01;
extern u8 D_801359D7;
void func_800C77DC(int);
void func_800FC74C();
typedef struct { u8 local_0[0x16]; u8 local_1; u8 local_2; u8 local_3[0x1C]; u8 local_4[2]; s16 local_5[2]; u8 local_6[0x16]; } local_type;
u8 D_80135A10[14];
extern u8 D_801359D6;

extern s16 D_801359E2;
void _cothemedll_entrypoint_3(void *, s32);
s16 _cothemedll_entrypoint_1(s32);
extern u8 D_801359CE;
extern s8 D_801359CF;
extern u8 D_801359D8;
extern s16 D_801359CA;
extern s16 D_801359E4;
extern s32 D_801242DC[];
extern s32 D_80123E60;
extern f32 D_80124314[][2];
extern f32 D_80135A0C[1];
extern s32 func_80017764(s32);
extern s32 func_800FC4B0(s32, s32, s32, f32);
extern void func_800FC688(s32, s32);
extern void func_800FCB00(s32, s32, s32, s32);
extern float D_801359F0;
extern u8 D_8012762C;
typedef struct { u8 pad[0x34]; u8 field_34[2]; s16 field_36[2]; } AudioState;
typedef union {
    G_FDC28 G_FDC28;
    FDC58State FDC58State;
    local_type local_type;
    AudioState AudioState;
    f32 f;
} Union_D_801359C0;
extern Union_D_801359C0 D_801359C0;
typedef struct { s16 field_0, field_2; f32 field_4; } AudioRecord;
extern s16 D_80123E5E[][4];
extern AudioRecord D_80123E64[];
extern s32 func_800EA05C(void);
extern void func_800C3648(u8, s32);
extern void func_800C3058(u8, s32);
extern void func_800C3A40(u8, f32, f32, f32);
extern void func_800C2FDC(u8);
extern s32 func_800C2E04(void);
extern void func_800C330C(u8, s32);
extern void func_800C301C(u8, s32);
extern void func_800C31DC(u8, f32);
extern void func_800C36F4(u8, s32);
extern void func_800C368C(u8, s32);
extern void func_800C33DC(u8, s32);
extern void func_800C3BDC(u8);
extern float sqrtf(float);
void func_800FE914();
void func_800FEDC4(s32 param_0, s32 param_1, f32 param_2, f32 param_3);

void func_800FCFB0(s32 param_0, s32 param_1, u8 *param_2, s32 param_3, f32 param_4)
{
  if (param_1 == D_80135A20[param_0])
  {
    if (param_3 != 0)
    {
      if (*((s16 *) (((s8 *) param_2) + 0xA)) != (-1))
      {
        func_800FCED0(param_1, 0x03938700 / *((s16 *) (((s8 *) param_2) + 0xA)), param_4);
      }
      func_800FCDE0(param_1, *((s32 *) (((s8 *) param_2) + 4)), param_4);
    }
    else
    {
      if (*((s16 *) (((s8 *) param_2) + 8)) != (-1))
      {
        func_800FCED0(param_1, 0x03938700 / *((s16 *) (((s8 *) param_2) + 8)), param_4);
      }
      func_800FCDE0(param_1, *((s32 *) (((s8 *) param_2) + 0)), param_4);
    }
    D_80135A3C[param_0] = 1;
    return;
  }
  if (D_80135A20[param_0] == 0)
  {
    D_80135A20[param_0] = param_1;
    if (func_800FCCD4(param_1) == 0)
    {
      func_800FC688(param_1, func_80017764(param_1));
      D_801359D5 = 1;
    }
    if (param_1 == 0x4B)
    {
      func_800FC97C(param_1, 0.125f, 1.0f);
    }
    else
    {
      func_800FC97C(param_1, 0.25f, 1.0f);
    }
    if (param_3 != 0)
    {
      if (*((s16 *) (((s8 *) param_2) + 0xA)) != (-1))
      {
        func_800FCED0(param_1, 0x03938700 / *((s16 *) (((s8 *) param_2) + 0xA)), param_4);
      }
      func_800FCDE0(param_1, *((s32 *) (((s8 *) param_2) + 4)), param_4);
    }
    else
    {
      if (*((s16 *) (((s8 *) param_2) + 8)) != (-1))
      {
        func_800FCED0(param_1, 0x03938700 / *((s16 *) (((s8 *) param_2) + 8)), param_4);
      }
      func_800FCDE0(param_1, *((s32 *) (((s8 *) param_2) + 0)), param_4);
    }
    D_80135A3C[param_0] = 1;
    D_80135A30[param_0] = param_4;
    if (D_80135A40 == (-1))
    {
      D_80135A40 = 1;
      return;
    }
    D_80135A40 += 1;
  }
}

void func_800FD2A0(u8 *param_0, s32 param_1) {
    f32 local_1;
    f32 local_0;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    s32 local_8;
    s32 local_9;
    s32 local_10;

    switch ((*(s16 *)((s8 *)(((u8 *) &D_801359C0)) + (0x20)))) {
    case 1:
        local_5 = func_800CBBE0((*(s32 *)((s8 *)(((u8 *) &D_801359C0)) + (0x28))));
        if (local_5 != 2) {
            if (local_5 == 3) {
                if (((*(f32 *)((s8 *)(&D_801241E4) + (8))) > (local_1 = *(f32 *)param_0)) || (local_3 = (*(f32 *)((s8 *)(param_0) + (8))), (local_3 < (*(f32 *)((s8 *)(&D_801241E4) + (4))))) || ((*(f32 *)((s8 *)(&D_801241E4) + (0))) < local_1) || ((*(f32 *)((s8 *)(&D_801241E4) + (0xC))) < local_3)) {
                    local_6 = 0;
                } else {
                    local_7 = 2;
                    if ((*(f32 *)((s8 *)(&D_801241E4) + (0))) < ((local_1 + local_3) - (*(f32 *)((s8 *)(&D_801241E4) + (4))))) {
                        local_7 = 1;
                    } else {
                        local_7 = 2;
                    }
                    local_6 = local_7;
                }
                if (local_6 == 2) {
                    D_80135A04 = &D_80123F68;
                    return;
                }
            }
        } else {
            if ((*(f32 *)((s8 *)(param_0) + (4))) > 2000.0f) {
                func_800FCFB0(0, 0x4A, ((s32 *) D_80123E84), param_1, 1.75f);
                ((s32 *) D_80135A04) = ((s32 *) &D_80123FC8);
                return;
            }
        default:
            return;
        }
        break;
    case 7:
        func_800FEDC4(0, 1, 1.0f, 1.75f);
        return;
    case 12:
        func_800FEDC4(0, 2, 1.0f, 1.75f);
        func_800FEDC4(1, 3, 1.0f, 1.75f);
        return;
    case 13:
        func_800FEDC4(0, 2, 0.9f, 1.75f);
        func_800FEDC4(1, 3, 0.9f, 1.75f);
        return;
    /* Distance-dependent strengths; the helper's bounds remain explicit. */
    case 14:
        local_2 = func_800F10B4(func_800EEAD4(param_0, &D_801241F4), 2500.0f, 3500.0f, 0.8f, 0.0f);
        local_0 = local_2;
        func_800FEDC4(0, 2, local_2, 1.75f);
        func_800FEDC4(1, 3, local_0, 1.75f);
        return;
    case 21:
        func_800FEDC4(0, 4, func_800F10B4(func_800EEAD4(param_0, &D_80124200), 2500.0f, 5000.0f, 1.0f, 0.0f), 1.75f);
        return;
    case 23:
        func_800FEDC4(0, 2, 0.7f, 1.75f);
        func_800FEDC4(1, 3, 0.7f, 1.75f);
        return;
    case 20:
        func_800FEDC4(0, 2, func_800F10B4(func_800EEAD4(param_0, &D_8012420C), 2500.0f, 3500.0f, 0.5f, 0.0f), 1.75f);
        return;
    /* States 17-19 retain the previous map section when the query returns -1.
     * D_80135A1E records which of the two section-transition paths was used. */
    case 17:
        local_8 = _gcmapsects_entrypoint_7(param_0);
        if (local_8 != -1) {
            D_801359D1 = local_8;
        }
        switch (*(u8 *)((s8 *)((u8 *) &D_801359C0) + 0x11)) {
        case 2:
        case 3:
        case 4:

            func_800FCFB0(0, 0x4B, &D_8012401C, param_1, 1.75f);
            ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
            return;
        }
        break;
    case 18:
        local_9 = _gcmapsects_entrypoint_7(param_0);
        if (local_9 != -1) {
            D_801359D1 = local_9;
        }
        switch ((*(u8 *)((s8 *)(((u8 *) &D_801359C0)) + 0x11))) {
        case 3:
            if (param_1 != 0) {
                func_800FCFB0(0, 0x4B, &D_8012401C, param_1, 1.75f);
            } else {
                func_800FCFB0(0, 0x4B, &D_80124004, param_1, 1.75f);
            }
            ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
            break;
        case 0:
        case 2:
            func_800FCFB0(0, 0x4B, &D_8012401C, param_1, 1.75f);
            ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
            D_80135A1E = 0;
            break;
        case 1:
            if (D_80135A1E != 0) {
                func_800FCFB0(0, 0x4B, &D_80124028, param_1, 1.75f);
            } else {
                func_800FCFB0(0, 0x4B, &D_8012401C, param_1, 1.75f);
            }
            ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
            break;
        }
        break;
    case 19:
        local_10 = _gcmapsects_entrypoint_7(param_0);
        if (local_10 != -1) {
            D_801359D1 = local_10;
        }
        switch (*(u8 *)((s8 *)((u8 *) &D_801359C0) + 0x11)) {
        case 0:
        case 1:
        case 2:
        case 3:

            if (param_1 != 0) {
                func_800FCFB0(0, 0x4B, &D_80124028, param_1, 1.75f);
            } else {
                func_800FCFB0(0, 0x4B, &D_80124004, param_1, 1.75f);
            }
            ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
            D_80135A1E = 1;
            return;
        }
        break;
    case 22:
        if (param_1 != 0) {
            func_800FCFB0(0, 0x4B, &D_8012401C, param_1, 1.75f);
        } else {
            func_800FCFB0(0, 0x4B, &D_80124004, param_1, 1.75f);
        }
        ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
        return;
    case 5:
        if ((*(u8 *)((s8 *)(((u8 *) &D_801359C0)) + (0x40))) == 0) {
            func_800FCFB0(0, 0x4B, &D_80124004, param_1, 1.75f);
        }
        ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
        return;
    case 6:
        func_800FCFB0(0, 0x4B, &D_80124040, param_1, 1.75f);
        ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
        return;
    case 8:
        if (func_800DA298(0x9F0) != 0) {
            func_800FCFB0(1, 0x50, ((s32 *) D_80123E84), param_1, 1.75f);
        } else {
            func_800FCFB0(0, 0x4F, ((s32 *) D_80123E84), param_1, 1.75f);
        }
        ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
        return;
    case 9:
        func_800FCFB0(0, 0x4B, &D_80124034, param_1, 1.75f);
        ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
        return;
    case 10:
        func_800FCFB0(0, 0x4B, &D_8012401C, param_1, 1.75f);
        ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
        return;
    case 11:
        func_800FCFB0(0, 0x4B, &D_80124028, param_1, 1.75f);
        ((s32 *) D_80135A04) = ((s32 *) &D_80124010);
        return;
    /* Advance/retreat the blend by delta time inside/outside the test region.
     * This is threshold gating, not a clamp: a step may cross 0 or 0.5. */
    case 15:
        if (func_800DA298(0x360)) {
            if (func_800EFFB4(param_0, 1750.0f, &D_80124218)) {
                if (D_80135A44 < 0.5f) {
                    D_80135A44 += func_800D8FF8();
                }
            } else {
                if (D_80135A44 > 0.0f) {
                    D_80135A44 -= func_800D8FF8();
                }
            }
            if (D_80135A44 > 0.0f) {
                if (D_80135A44 >= 0.5f) {
                    ((s32 *) D_80135A04) = ((s32 *) &D_801241CC);
                } else {
                    D_80135A04 = &D_801241D8;
                }
            }
        }
        break;
    case 16:
        if (D_80135A44 >= 1.0f) {
            func_800FCFB0(0, 0x8D, ((s32 *) D_80123E84), param_1, 1.75f);
        }
        D_80135A44 = 1.0f;
        break;
    }
}

void func_800FDBB8(s32 param_0) {
    if (D_80124224[D_80135A00].unk0 != -1) {
        func_800FCFB0(D_80124224[D_80135A00].unk0, D_80124224[D_80135A00].unk4, ((u8 *) D_80123E84), param_0, 0.0f);
        ((u8 *) D_80135A04) = ((u8 *) &D_80124010);
    }
}

u32 func_800FDC28(u32 param_0) {
    if (param_0 != D_801359C0.G_FDC28.unk40) {
        D_801359C0.G_FDC28.unk40 = param_0;
        if ((param_0 & 0xFF) == 0) { D_801359C0.G_FDC28.unk18 = 1; }
    }
}

void func_800FDC58(s32 param_0)
{
    f32 local_0[3];
    s32 local_1;
    s32 local_3;
    s32 local_2;
    /* local_4 keeps an otherwise unused stack home; local_5 carries 666.0f so it stays a
     * runtime conversion from this function's .rodata. */
    s32 *local_4;
    f32 local_5;
    FDC58State *local_6 = (FDC58State *)(u32)((FDC58State *) &D_801359C0);

    /* Preserve the pre-update counter for func_800FE914, even if it changes. */
    local_1 = D_801359C0.FDC58State.value_0F;
    if (D_801359C0.FDC58State.value_41 != 0) return;
    if (D_801359C0.FDC58State.value_16 == 0) return;
    if (D_801359C0.FDC58State.value_3C > 0.0f) {
        D_801359C0.FDC58State.value_3C -= func_800D8FF8();
    }
    if (func_80090200() == 0) return;
    if (func_8008FF94() == 2) param_0 = 1;
    else param_0 = 0;

    if (D_801359C0.FDC58State.value_17 == 0) {
        if (D_801359C0.FDC58State.value_22 != -1) {
            D_80135A04 = &D_80123E84[D_801359C0.FDC58State.value_22];
        } else D_80135A04 = 0;
        func_8008FE68(local_0);
        /* Region processing must mark any auxiliary slots still required. */
        for (local_3 = 0; local_3 < 3; local_3++) D_80135A3C[local_3] = 0;
        if (func_800CCEF4(local_0, D_801359E8, D_801359EC, 0, 0)) {
            local_2 = func_800CBBE0(D_801359C0.FDC58State.value_28);
            if (!func_800CBC00(D_801359C0.FDC58State.value_28)) {
                D_80135A04 = &D_80123E84[local_2];
            } else {
                switch (func_800CBBE0(D_801359C0.FDC58State.value_28)) {
                case 0:
                    func_800FCFB0(0, 0x47, D_80123E84, param_0, 1.75f);
                    D_80135A04 = &D_80123FC8;
                    break;
                case 1:
                    func_800FCFB0(0, 0x4A, D_80123E84, param_0, 1.75f);
                    D_80135A04 = &D_80123FC8;
                    break;
                case 7: D_80135A1E = 1; break;
                case 8: D_80135A1E = 0; break;
                case 9:
                    func_800FCFB0(0, 0x4A, D_80123E84, param_0, 1.75f);
                    D_80135A04 = &D_80124064;
                    break;
                case 12:
                    if (func_800DA298(0x360)) D_80135A04 = &D_801241CC;
                    break;
                case 13: D_80135A44 = 0.0f; break;
                case 14:
                    func_800FCFB0(0, 0x4A, D_80123E84, param_0, 1.75f);
                    break;
                case 15:
                    func_800FCFB0(0, 0x8D, D_80123E84, param_0, 1.75f);
                    D_80135A04 = &D_8012419C;
                    break;
                case 16:
                    if (func_800DA298(0x3B) && !func_800DA298(0x43)) {
                        func_800FCFB0(0, 0x9A, D_80123E84, param_0, 1.75f);
                        D_80135A04 = &D_80124010;
                    } else D_80135A04 = &D_80124124;
                    break;
                case 17:
                    if (func_800DA298(0x3B) && !func_800DA298(0x43)) {
                        func_800FCFB0(0, 0x9A, D_80123E84, param_0, 1.75f);
                        D_80135A04 = &D_80124010;
                    }
                    break;
                }
            }
        }
        if (D_801359C0.FDC58State.value_20) func_800FD2A0(local_0, param_0);
        func_800FDBB8(param_0);
        /* Retire unmarked or finished slots, clearing ID, flag and fade value. */
        if (D_80135A40 > 0) {
            for (local_3 = 0; local_3 != 3; local_3++) {
                if (D_80135A20[local_3]) {
                    if (!D_80135A3C[local_3] || !func_800FCCD4(D_80135A20[local_3])) {
                        local_5 = 666.0f;
                        func_800FCAE0(D_80135A20[local_3], 0, (s32)local_5);
                        func_800FCA90(D_80135A20[local_3]);
                        D_80135A20[local_3] = 0;
                        D_80135A3C[local_3] = 0;
                        D_80135A30[local_3] = 0.0f;
                        D_80135A40--;
                    }
                }
            }
        }
    }
    func_800FE914(local_1);
    if (D_801359C0.FDC58State.value_17 == 0) {
        /* Reapply settings after an entry/mode change or pending retry. */
        if (D_80135A04 != D_80135A08 || param_0 != D_801359C0.FDC58State.value_10 || D_801359C0.FDC58State.value_0F || D_801359C0.FDC58State.value_18) {
            if (!D_801359C0.FDC58State.value_0F) local_2 = 1;
            else {
                D_801359C0.FDC58State.value_0F--;
                local_2 = 0;
                if (D_801359C0.FDC58State.value_08 != -1) func_800FC97C(D_801359C0.FDC58State.value_08, 0.25f, 1.0f);
            }
            D_80135A08 = D_80135A04;
            D_801359C0.FDC58State.value_10 = param_0;
            /* Failed updates request another tick. Tempo conversion divides
             * 60,000,000 as integers before multiplying by the float scale. */
            if (D_80135A04 &&D_801359C0.FDC58State.value_08 != -1) {
                if (param_0) {
                    if (!func_800FCDE0(D_801359C0.FDC58State.value_08, D_80135A04->local_0[1], (f32)local_2)) D_801359C0.FDC58State.value_0F = 1;
                    if (D_80135A04->local_1[1] != -1) {
                        if (!func_800FCED0(D_801359C0.FDC58State.value_08, (s32)((60000000 / D_80135A04->local_1[1]) * D_801359C0.FDC58State.value_04), (f32)local_2)) D_801359C0.FDC58State.value_0F = 1;
                    }
                } else {
                    if (!func_800FCDE0(D_801359C0.FDC58State.value_08, D_80135A04->local_0[0], (f32)local_2)) D_801359C0.FDC58State.value_0F = 1;
                    if (D_80135A04->local_1[0] != -1) {
                        if (!func_800FCED0(D_801359C0.FDC58State.value_08, (s32)((60000000 / D_80135A04->local_1[0]) * D_801359C0.FDC58State.value_04), (f32)local_2)) D_801359C0.FDC58State.value_0F = 1;
                    }
                }
            }
            D_801359C0.FDC58State.value_18 = D_801359C0.FDC58State.value_0F;
        }
        /* Refresh main and auxiliary volumes once, then clear the dirty flag.
         * D_80135A2C is the linker symbol immediately after the three IDs;
         * the loop uses its address as the endpoint, never its contents. */
        if (D_801359C0.FDC58State.value_14) {
            if (D_801359C0.FDC58State.value_13) {
                if (D_801359C0.FDC58State.value_08 != -1) func_800FC934(D_801359C0.FDC58State.value_08, D_801359C0.FDC58State.value_00, 1.0f);
                local_2 = 0;
                do {
                    if (D_80135A20[local_2]) func_800FC934(D_80135A20[local_2], D_801359C0.FDC58State.value_00, 1.0f);
                    local_2++;
                } while (&D_80135A2C != &D_80135A20[local_2]);
            } else {
                if (D_801359C0.FDC58State.value_08 != -1) func_800FC934(D_801359C0.FDC58State.value_08, 0, 1.0f);
                local_2 = 0;
                do {
                    if (D_80135A20[local_2]) func_800FC934(D_80135A20[local_2], 0, 1.0f);
                    local_2++;
                } while (&D_80135A2C != &D_80135A20[local_2]);
            }
            D_801359C0.FDC58State.value_14 = 0;
        }
    }
}

void func_800FE3EC()
{
  if (D_801359C8 != -1)
  {
    func_800FCA90(D_801359C8);
  }
  if (D_80135A40 <= 0)
  {
    return;
  }
  {
    s32 i;
    for (i = 0; i < 3; i++)
    {
      if (D_80135A20[i] != 0)
      {
        if (D_80135A3C[i] != 0)
        {
          func_800FCA90(D_80135A20[i]);
          D_80135A20[i] = 0;
          D_80135A3C[i] = 0;
          D_80135A30[i] = 0.0f;
          D_80135A40 -= 1;
        }
      }
    }
  }
}

int func_800FE4E4(void) {
    s32 local_0;
    if (D_801359D7 != 0) return 0;
    {
        func_800C77DC(1);
        func_800FDC28(0);
        if (D_801359C8 != -1) {
            func_800FC74C(D_801359C8);
        }
        if (((int) D_80135A40) > 0) {
            for (local_0 = 0; local_0 < 3; local_0++) {
                if (((int *) D_80135A20)[local_0] && D_80135A3C[local_0]) {
                    func_800FC74C(((int *) D_80135A20)[local_0]);
                    ((int *) D_80135A20)[local_0] = 0;
                    D_80135A3C[local_0] = 0;
                    D_80135A30[local_0] = 0.0f;
                    ((int) D_80135A40)--;
                }
            }
        }
        D_80135A01 = 1;
        return 1;
    }
}

void func_800FE614(void) {
    s32 local_0;
    D_801359C0.local_type.local_1 = 1;
    D_801359C0.local_type.local_2 = 0;
    D_80135A40 = -1;
    for (local_0 = 0; local_0 < 2; local_0++) {
        D_801359C0.local_type.local_4[local_0] = 0;
        D_801359C0.local_type.local_5[local_0] = 0;
    }
    for (local_0 = 0; local_0 < 3; local_0++) {
        D_80135A20[local_0] = 0;
        D_80135A30[local_0] = 0.0f;
        D_80135A3C[local_0] = 0;
    }
    for (local_0 = 0; local_0 < 14; local_0++) {
        D_80135A10[local_0] = 0;
    }
    func_800FDC28(0);
}

void func_800FE6F8(long param_0)
{
  if ((param_0 == 0) && (D_801359D6 != 0))
  {
    func_800FE4E4();
  }
  D_801359D6 = param_0;
}

void func_800FE734(u32 param_0)
{
  D_801359D7 = param_0;
}

void func_800FE740(void)
{
    s32 local_0;

    local_0 = func_800EA05C();
    if (D_80135A10[6] != 0) {
        D_80135A10[6] = 0;
    }
    D_80135A08 = 0;
    (*((f32 *) D_80135A0C)) = 0.0f;
    _cothemedll_entrypoint_3(&D_801359C0, local_0);
    D_801359E2 = _cothemedll_entrypoint_1(local_0);
}

s32 func_800FE7A8(s32 param_0)
{
  s32 i;
  u8 *ptr;
  if (param_0 == D_801359C8)
  {
    i = 1;
    return i;
  }
  if (D_80135A40 > 0)
  {
    ptr = D_80135A3C;
    for (i = 0; i < 3; i++)
    {
      if (*ptr)
      {
        if (param_0 == D_80135A20[i])
        {
          return 1;
        }
      }
      ptr++;
    }

  }
  return 0;
}

func_800FE820(f32 param_0){
    ((f32 *) &D_801359C0)[1] = 1.0f / param_0;
    *(u8*)&((f32 *) &D_801359C0)[4] = 0xFF;
}

void func_800FE844(u32 param_0)
{
  D_801359CE = param_0;
}

void func_800FE850()
{
    func_800DA544(FLAG2_674_UNK);
}

void func_800FE870()
{
    func_800DA544(FLAG2_675_UNK);
}

u8 func_800FE890()
{
  return D_801359CE;
}

void func_800FE89C()
{
  D_801359CF = 1;
}

void func_800FE8AC()
{
  D_801359D8 = 1;
}

int func_800FE8BC(unsigned long param_0, s32 param_1)
{
  u32 local_0;
  local_0 = param_0 | 0;
  _cothemedll_entrypoint_5(&D_801359C0, local_0, param_1 | 0);
  local_0 = param_0 | 0;
}

int func_800FE8EC(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _cothemedll_entrypoint_4(&D_801359C0, local_0);
}

void func_800FE914(param_0) s32 param_0;
{
    s32 local_0;
    f32 local_1;
    s32 local_2;
    f32 local_4;
    s32 local_5;
    s32 local_6;

    local_0 = D_801359CA;
    local_1 = 1.75f;
    for (local_2 = 0; local_2 != 14; local_2++) {
        if (D_80135A10[local_2]) {
            switch (local_2) {
                case 3:
                    local_4 = D_801359CA * D_801359F0;
                    if (local_4 < local_0) local_0 = local_4;
                    break;
                default:
                    if (D_801242DC[local_2] < local_0) local_0 = D_801242DC[local_2];
                    break;
            }
            if (D_80124314[local_2][0] < local_1) local_1 = D_80124314[local_2][0];
            if (D_80135A0C[0] < D_80124314[local_2][1]) D_80135A0C[0] = D_80124314[local_2][1];
        }
    }
    if (D_801359E4 < local_0) local_1 = D_80135A0C[0];
    if (local_0 != D_801359E4 || D_80123E60) {
        s16 *local_7 = &D_801359C8;
        if (*local_7 != -1) {
            if (!func_800FCCD4(D_801359C8)) {
                func_800FC688(*local_7, func_80017764(*local_7));
            }
            local_5 = func_800FC4B0(*local_7, -1, local_0, param_0 ? 0.0f : local_1);
            if (local_5) func_800FCB00(*local_7, local_0, local_5, 0);
        }
        D_80123E60 = 0;
    }
    if (local_0 != D_801359E4 || D_801359D5 || D_80123E60) {
        if (D_80135A40 > 0) {
            for (local_6 = 0; local_6 != 3; local_6++) {
                if (D_80135A20[local_6] && D_80135A3C[local_6] && func_800FCCD4(D_80135A20[local_6])) {
                    if (param_0) local_1 = 0.0f;
                    else local_1 = (local_4 = local_1 < D_80135A30[local_6] ? local_1 : D_80135A30[local_6]);
                    local_5 = func_800FC4B0(D_80135A20[local_6], -1, local_0, local_1);
                    if (local_5) func_800FCB00(D_80135A20[local_6], local_0, local_5, 0);
                }
            }
        } else {
            D_80135A0C[0] = 0.0f;
        }
        D_801359D5 = 0;
    }
    D_801359E4 = local_0;
}

void func_800FEC1C(f32 param_0)
{
  D_801359F0 = param_0;
}

int func_800FEC28(s32 param_0)
{
  int new_var2;
  int new_var;
  u8 *local_0 = &D_8012762C;
  new_var = 0xFFFFFFFFFFFFFFFF;
  new_var = param_0 & new_var;
  if (!new_var)
  {
    new_var = 0;
    new_var2 = new_var;
    new_var = new_var2;
    if ((*local_0) == 0xD)
    {
      return 7;
    }
    else
    {
      return 0 | new_var;
    }
  }
  return new_var;
}

void func_800FEC60(u32 param_0) {
    s32 i = func_800FEC28(param_0);
    D_80135A10[i] += 1;
    if (i == 3) { D_801359F0 = 1.0f; }
    D_80123E60 = 1;
}

void func_800FECB8(u32 param_0) {
    s32 local_0;
    D_80135A10[func_800FEC28(param_0)]--;
    for (local_0 = 0; local_0 < 14; local_0++) {}
    D_80123E60 = 1;
}

void func_800FED0C(u32 param_0, u32 param_1) {
    u32 idx;
    switch (param_0 - 1) {
        case 0:
        default:
            return;
        case 1:
            idx = 0xC;
            break;
        case 4:  case 9:  case 10: case 11: case 12: case 17: case 21:
        case 22: case 23: case 26: case 45: case 48: case 57: case 67:
        case 82: case 95: case 118: case 130:
            idx = 0xD;
            break;
        case 42: case 103:
            idx = 0xD;
            break;
    }
    D_80135A10[idx] += param_1;
    D_80123E60 = 1;
}

void func_800FED70(s32 arg0)
{
    func_800FED0C(arg0,1);
}

int func_800FED90(s32 param_0)
{
  int local_0;
  func_800FED0C(param_0, -1);
  for (local_0 = 2; local_0 < 0xE; local_0 += 4)
  {}
}

void func_800FEDC4(s32 param_0, s32 param_1, f32 param_2, f32 param_3) {
    if (param_1 == D_801359C0.AudioState.field_36[param_0] && param_1 != 0) {
        func_800C3648(D_801359C0.AudioState.field_34[param_0], func_800EA05C());
        func_800C3058(D_801359C0.AudioState.field_34[param_0], (s32)(D_80123E5E[param_1][0] * param_2));
        return;
    }
    if (D_801359C0.AudioState.field_34[param_0]) {
        if (param_3 != 0.0f) func_800C3A40(D_801359C0.AudioState.field_34[param_0], 0.0f, 0.0f, param_3);
        else func_800C2FDC(D_801359C0.AudioState.field_34[param_0]);
        D_801359C0.AudioState.field_34[param_0] = 0;
    }
    if (param_1) {
        D_801359C0.AudioState.field_34[param_0] = func_800C2E04();
        func_800C330C(D_801359C0.AudioState.field_34[param_0], 3);
        func_800C301C(D_801359C0.AudioState.field_34[param_0], D_80123E64[param_1 - 1].field_0);
        func_800C3058(D_801359C0.AudioState.field_34[param_0], (s32)(D_80123E64[param_1 - 1].field_2 * param_2));
        func_800C31DC(D_801359C0.AudioState.field_34[param_0], D_80123E64[param_1 - 1].field_4);
        func_800C36F4(D_801359C0.AudioState.field_34[param_0], 255);
        func_800C368C(D_801359C0.AudioState.field_34[param_0], 0);
        func_800C33DC(D_801359C0.AudioState.field_34[param_0], 0);
        func_800C3BDC(D_801359C0.AudioState.field_34[param_0]);
    }
    D_801359C0.AudioState.field_36[param_0] = param_1;
}

void func_800FEF94(s32 param_0, s32 param_1, s32 param_2, s32 *param_3, s16 *param_4) {
    u8 *temp_v0;

    if (param_2 != 0) {
        temp_v0 = (param_1 * 12) + ((u8 *) D_80123E84);
        *param_3 = (*(s32 *)((s8 *)temp_v0 + 4));
        *param_4 = (*(s16 *)((s8 *)temp_v0 + 0xA));
        return;
    }
    temp_v0 = (param_1 * 12) + ((u8 *) D_80123E84);
    *param_3 = (*(s32 *)((s8 *)temp_v0 + 0));
    *param_4 = (*(s16 *)((s8 *)temp_v0 + 8));
}

func_800FF000(s32 param_0){
    *(u8*)((char*)((u8 *) &D_801359C0) + 0x13) = param_0;
    *(f32*)((char*)((u8 *) &D_801359C0) + 0x0) = 0.2f;
}

void func_800FF01C(f32 param_0)
{
  ((u8 *)((f32 *) &D_801359C0))[0x13] = 1;
  ((u8 *)((f32 *) &D_801359C0))[0x14] = 1;
  D_801359C0.f = param_0;
}

int func_800FF038(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _cothemedll_entrypoint_2(&D_801359C0, local_0);
  return;
}

f32 func_800FF060(f32 param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5)
{
  f32 local_18;
  f32 local_8;
  f32 local_0;
  f32 local_1;
  f32 local_2;
  f32 local_14;
  f32 local_16;
  f32 local_19;
  f32 local_20;
  f32 local_5;
  volatile f32 local_3;
  f32 local_7;
  f32 local_11;
  f32 local_21;
  f32 local_22;
  s32 local_23;
  local_5 = param_3;
  if (param_0 < 0.0f)
  {
    local_23 = -1;
  }
  else
  {
    local_23 = 1;
  }
  param_0 *= (f32) local_23;
  local_16 = (*param_1) * ((f32) local_23);
  if (local_16 < 0.0f)
  {
    local_5 = -local_5;
    if (local_5 < param_2)
    {
      local_21 = param_2;
    }
    else
    {
      local_21 = local_5;
    }
    local_18 = 0.0f - (local_16 / local_21);
    if (param_5 < local_18)
    {
      local_18 = param_5;
    }
    local_14 = (local_21 * local_18) + local_16;
    local_0 = ((local_16 + local_14) * local_18) * 0.5f;
  }
  else
  {
    local_18 = 0;
    local_14 = local_16;
    local_0 = local_18;
  }

  local_16 = local_14;
  local_14 *= local_14;
  local_21 = local_14;
  local_8 = 2.0f;
  param_0 -= local_0;
  param_5 -= local_18;
  local_20 = ((local_21 * .5f) + (param_3 * param_0)) / (param_3 - param_2);
  local_3 = local_20;
  if (local_20 > 0.0f)
  {
    local_14 = local_8 * param_2;
    local_21 += local_14 * local_3;
    local_14 = sqrtf(local_21);
    if (param_4 <= local_14)
    {
      local_14 = param_4;
    }
    local_20 = (local_14 - local_16) / param_2;
    if (param_5 < local_20)
    {
      local_20 = param_5;
    }
    local_22 = (param_2 * local_20) + local_16;
    local_1 = ((local_16 + local_22) * 0.5f) * local_20;
  }
  else
  {
    local_22 = local_16;
    local_20 = 0.0f;
    local_1 = 0.0f;
  }

  if (local_22 == 0.0f)
  {
    *param_1 = 0.0f;
    return ((f32) local_23) * local_0;
  }
  param_5 -= local_20;
  local_16 = local_22;
  param_0 -= local_1;
  if (param_5 > 0.0f)
  {
    local_21 = (0.0f - (local_22 * local_22)) / (local_8 * param_3);
    if (local_21 < param_0)
    {
      local_19 = (param_0 - local_21) / local_22;
      if (param_5 < local_19)
      {
        local_19 = param_5;
      }
      local_2 = local_19 * local_22;
    }
    else
    {
      local_2 = 0.0f;
      local_19 = 0.0f;
    }
  }
  else
  {
    local_2 = 0.0f;
    local_19 = 0.0f;
  }
  param_0 -= local_2;
  param_5 -= local_19;
  if (param_5 > 0.0f)
  {
    local_7 = param_5;
    local_22 = (param_3 * param_5) + local_16;
    if (local_22 < 0.0f)
    {
      local_22 = 0.0f;
      local_19 = (-local_16) / param_3;
      local_7 = local_19;
    }
    local_11 = ((local_16 + local_22) * 0.5f) * local_7;
  }
  else
  {
    local_11 = 0.0f;
  }
  param_0 -= local_11;
  *param_1 = ((f32) local_23) * local_22;
  return (((local_0 + local_1) + local_2) + local_11) * ((f32) local_23);
}
