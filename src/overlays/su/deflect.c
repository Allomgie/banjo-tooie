#include "common.h"

#define CODEX_DEFLECT_ITEM31_DEFINED
extern s32 B_80801020_sudeflect;
extern s32 func_800F4F34(s32, f32 *, f32, f32);
extern void func_800A52E0(f32 *, f32, f32);
extern s32 func_800F4EC8(s32, void *, f32, f32, f32);
extern void func_800A5298(void *, f32, f32, f32);
typedef struct { Unk80132ED0 *local_0; s32 pad_0; u32 local_1; } DeflectItem31;
extern DeflectItem31 *func_800E9E88(void *);
extern DeflectItem31 *func_800E9EB4(void *);
extern Actor *func_80106790();
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
typedef struct { Unk80132ED0 *marker; s32 pad4; u32 flags; } DeflectRecord32;
extern s32 func_800F0064(f32 *, f32, f32 *);
int func_80800630_sudeflect();
int func_808006A4_sudeflect(f32 *param_0, f32 param_1, f32 param_2);
int func_808007F4_sudeflect(void *param_0, f32 param_1, f32 param_2, f32 param_3);
int func_80800940_sudeflect(f32 *param_0, f32 param_1, f32 param_2);
int func_80800A98_sudeflect(void *param_0, f32 param_1, f32 param_2, f32 param_3);
s32 func_80800BEC_sudeflect();
s32 func_80800D14_sudeflect();
s32 func_80800E44_sudeflect(f32 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 *param_4, f32 param_5);
s32 func_80800ECC_sudeflect(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3);

s32 sudeflect_entrypoint_0(f32 *param_0, f32 param_1, f32 param_2, s32 param_3)
{
    s32 local_0;
    s32 local_1;
    local_1 = 0;
    ((s32 *)&B_80801020_sudeflect)[9] = 0;
    if (param_3 & 0x18) B_80801020_sudeflect = func_800BE3F8();
    if (param_3 & 2) {
        for (local_0 = 0; local_0 < 8; local_0++) {
            if (func_800F6438(local_0) && func_800F4F34(local_0, param_0, param_1, param_2)) {
                ((s32 *)&B_80801020_sudeflect)[((s32 *)&B_80801020_sudeflect)[9] + 1] = local_0;
                ((s32 *)&B_80801020_sudeflect)[9]++;
                local_1 |= 2;
            }
        }
    }
    if (param_3 & 4) func_800A52E0(param_0, param_1, param_2);
    if (param_3 & 8) {
        if (func_808006A4_sudeflect(param_0, param_1, param_2)) local_1 |= 8;
    }
    if (param_3 & 0x10) {
        if (func_80800940_sudeflect(param_0, param_1, param_2)) local_1 |= 0x10;
    }
    B_80801020_sudeflect = 0;
    return local_1;
}

int sudeflect_entrypoint_1(void *param_0, f32 param_1, f32 param_2, f32 param_3, u32 param_4)
{
    s32 local_0;
    s32 local_1;
    local_1 = 0;
    ((s32 *)&B_80801020_sudeflect)[9] = 0;
    if (param_4 & 0x18) { B_80801020_sudeflect = func_800BE3F8(); }
    if (param_4 & 2) {
        for (local_0 = 0; local_0 < 8; local_0++) {
            if (func_800F6438(local_0) && func_800F4EC8(local_0, param_0, param_1, param_2, param_3)) {
                ((s32 *)&B_80801020_sudeflect)[((s32 *)&B_80801020_sudeflect)[9] + 1] = local_0;
                (((s32 *)&B_80801020_sudeflect)[9])++;
                local_1 |= 2;
            }
        }
    }
    if (param_4 & 4) { func_800A5298(param_0, param_1, param_2, param_3); }
    if ((param_4 & 8) && func_808007F4_sudeflect(param_0, param_1, param_2, param_3)) { local_1 |= 8; }
    if ((param_4 & 0x10) && func_80800A98_sudeflect(param_0, param_1, param_2, param_3)) { local_1 |= 0x10; }
    B_80801020_sudeflect = 0;
    return local_1;
}

int sudeflect_entrypoint_2(f32 *param_0, f32 *param_1, s32 param_2)
{
    f32 local_0[3];
    s32 local_1;
    s32 i0;
    s32 local_2 = 0;
    for (i0 = 0; i0 != 3; i0++) {
        if (1) {} /* SONDE (tragend, ohne: 14) */
        local_0[i0] = param_0[i0] + (param_1[i0] - param_0[i0]) * 0.5f;
    }
    *(s32 *)((u8 *)&B_80801020_sudeflect + 0x24) = 0;
    if (param_2 & 0x18) B_80801020_sudeflect = func_800BE3F8(local_0);
    if (param_2 & 2) {
        for (local_1 = 0; local_1 < 8; local_1++) {
            if (func_800F6438(local_1) && func_800F4D18(local_1, param_0, param_1)) {
                ((s32 *)&B_80801020_sudeflect)[*(s32 *)((u8 *)&B_80801020_sudeflect + 0x24) + 1] = local_1;
                (*(s32 *)((u8 *)&B_80801020_sudeflect + 0x24))++;
                local_2 |= 2;
            }
        }
    }
    if ((param_2 & 8) && func_80800BEC_sudeflect(param_0, param_1)) local_2 |= 8;
    if ((param_2 & 0x10) && func_80800D14_sudeflect(param_0, param_1)) local_2 |= 0x10;
    B_80801020_sudeflect = 0;
    return local_2;
}

s32 sudeflect_entrypoint_3(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
  s32 local_1 = 0;
  s32 local_0;
  *((s32 *) (((char *) (&B_80801020_sudeflect)) + 0x24)) = 0;
  if (param_4 & 2)
  {
    local_0 = 0;
    do
    {
      if ((func_800F6438(local_0) != 0) && (func_800F4E5C(local_0, param_0, param_1, param_2, param_3) != 0))
      {
        *((s32 *) ((((char *) (&B_80801020_sudeflect)) + ((*((s32 *) (((char *) (&B_80801020_sudeflect)) + 0x24))) * 4)) + 4)) = local_0;
        *((s32 *) (((char *) (&B_80801020_sudeflect)) + 0x24)) = (s32) ((*((s32 *) (((char *) (&B_80801020_sudeflect)) + 0x24))) + 1);
        local_1 |= 2;
      }
      local_0 += 1;
    }
    while (local_0 != 8);
  }
  return local_1;
}

void sudeflect_entrypoint_4(s32 param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    for (local_0 = 0; local_0 < ((s32 *)&B_80801020_sudeflect)[9]; local_0++) {
        local_1 = ((s32 *)&B_80801020_sudeflect)[local_0 + 1];
        if (func_80800630_sudeflect(local_1)) func_800F7700(local_1, param_0, param_1);
    }
}

int func_80800630_sudeflect(param_0) s32 param_0;
{
  if (func_800F6720(param_0))
  {
    return TRUE;
  }
  if (func_800F5410(param_0) == 0x11)
  {
    return TRUE;
  }
  switch (func_800F52B8(param_0, 0))
  {
    case 1 :
    case 0xb :
      return TRUE;

    default :
      break;

  }

  return FALSE;
}

int func_808006A4_sudeflect(f32 *param_0, f32 param_1, f32 param_2)
{
    DeflectItem31 *local_1;
    f32 local_0[5];
    DeflectItem31 *local_2;
    Actor *local_3;
    s32 local_4;
    void **local_5;
    local_5 = *(void ***)&B_80801020_sudeflect;
    local_4 = 0;
    func_800EE7F8(local_0, param_0);
    local_0[1] += param_1;
    while (*local_5) {
        local_1 = func_800E9E88(*local_5);
        local_2 = func_800E9EB4(*local_5);
        while (local_1 < local_2) {
            if (local_1->local_1 & 1) {
                local_3 = (Actor *)local_1->local_0;
                if (_sueggmisc_entrypoint_0(local_3)) {
                    local_3 = func_80106790(local_3);
                    if (!local_3->unk64_17 && func_800F0008(local_0, param_2, local_3->position, 38.0f)) {
                        local_4++;
                        func_8010108C(local_3, 5, 0);
                    }
                }
            }
            local_1++;
        }
        local_5++;
    }
    return local_4;
}

int func_808007F4_sudeflect(void *param_0, f32 param_1, f32 param_2, f32 param_3)
{
    void **local_0;
    DeflectItem31 *local_1;
    DeflectItem31 *local_2;
    Actor *local_3;
    s32 local_4;
    Unk80132ED0 *local_5;

    local_0 = *(void ***)&B_80801020_sudeflect;
    local_4 = 0;
    while (*local_0) {
        if (1) {}
        local_1 = func_800E9E88(*local_0);
        local_2 = func_800E9EB4(*local_0);
        for (; local_1 < local_2; local_1++) {
            if (local_1->local_1 & 1) {
                local_5 = local_1->local_0;
                if (_sueggmisc_entrypoint_0(local_5)) {
                    local_3 = func_80106790(local_5);
                    if (!local_3->unk64_17 && func_80800E44_sudeflect(param_0, param_1, param_2, param_3, local_3->position, 38.0f)) {
                        local_4++;
                        func_8010108C(local_3, 5, 0);
                    }
                }
            }
        }
        local_0++;
    }
    return local_4;
}

int func_80800940_sudeflect(f32 *param_0, f32 param_1, f32 param_2)
{
    extern DeflectItem31 *func_800E9E88(void *);
    extern DeflectItem31 *func_800E9EB4(void *);
    DeflectItem31 *local_1;
    f32 local_0[5];
    DeflectItem31 *local_2;
    Unk80132ED0 *local_3;
    Actor *local_6;
    s32 local_4;
    void **local_5;
    local_5 = *(void ***)&B_80801020_sudeflect;
    local_4 = 0;
    func_800EE7F8(local_0, param_0);
    local_0[1] += param_1;
    while (*local_5) {
        local_1 = func_800E9E88(*local_5);
        if (1) { do {} while (0); } /* probe: same form as chevilspirit 1684; without it 15 words differ */
        local_2 = func_800E9EB4(*local_5);
        while (local_1 < local_2) {
            if (local_1->local_1 & 1) {
                local_3 = local_1->local_0;
                if ((local_3->unk24 >> 22) == 0x27A) {
                    local_6 = func_80106790(local_3);
                    if (!local_6->unk64_17 && func_800F0008(local_0, param_2, local_6->position, 40.0f)) {
                        local_4++;
                        func_8010108C(local_6, 5, -1);
                    }
                }
            }
            local_1++;
        }
        local_5++;
    }
    return local_4;
}

int func_80800A98_sudeflect(void *param_0, f32 param_1, f32 param_2, f32 param_3)
{
    void **local_0;
    DeflectItem31 *local_1;
    DeflectItem31 *local_2;
    Actor *local_3;
    s32 local_4;
    Unk80132ED0 *local_5;

    local_0 = *(void ***)&B_80801020_sudeflect;
    local_4 = 0;
    while (*local_0) {
        local_1 = func_800E9E88(*local_0);
        local_2 = func_800E9EB4(*local_0);
        for (; local_1 < local_2; local_1++) {
            if (local_1->local_1 & 1) {
                local_5 = local_1->local_0;
                if (local_5->unk24 >> 22 == 0x27A) {
                    local_3 = func_80106790(local_5);
                    if (!local_3->unk64_17 && func_80800E44_sudeflect(param_0, param_1, param_2, param_3, local_3->position, 40.0f)) {
                        local_4++;
                        func_8010108C(local_3, 5, -1);
                    }
                }
            }
        }
        local_0++;
    }
    return local_4;
}

s32 func_80800BEC_sudeflect(param_0, param_1) f32 *param_0; f32 *param_1;
{
    void **local_0;
    DeflectItem31 *local_1;
    DeflectItem31 *local_2;
    Actor *local_3;
    s32 local_4;
    Unk80132ED0 *local_5;

    local_0 = *(void ***)&B_80801020_sudeflect;
    local_4 = 0;
    while (*local_0) {
        local_1 = func_800E9E88(*local_0);
        local_2 = func_800E9EB4(*local_0);
        for (; local_1 < local_2; local_1++) {
            if (local_1->local_1 & 1) {
                local_5 = local_1->local_0;
                if (_sueggmisc_entrypoint_0(local_5)) {
                local_3 = func_80106790(local_5);
                if (!local_3->unk64_17 && func_80800ECC_sudeflect(param_0, param_1, local_3->position, 38.0f)) {
                    local_4++;
                    func_8010108C(local_3, 5, 0);
                }
                }
            }
        }
        local_0++;
    }
    return local_4;
}

s32 func_80800D14_sudeflect(param_0, param_1) f32 *param_0; f32 *param_1;
{
    void **local_0;
    DeflectRecord32 *local_1;
    DeflectRecord32 *local_2;
    s32 local_3;
    Actor *local_4;

    local_0 = *(void ***)&B_80801020_sudeflect;
    local_3 = 0;
    while (*local_0) {
        local_1 = (DeflectRecord32 *)func_800E9E88(*local_0);
        local_2 = (DeflectRecord32 *)func_800E9EB4(*local_0);
        for (; local_1 < local_2; local_1++) {
            if ((local_1->flags & 1) && local_1->marker->unk24 >> 22 == 0x27A) {
                local_4 = func_80106790(local_1->marker);
                if (!local_4->unk64_17 && func_80800ECC_sudeflect(param_0, param_1, local_4->position, 40.0f)) {
                    local_3++;
                    func_8010108C(local_4, 5, -1);
                }
            }
        }
        local_0++;
    }
    return local_3;
}

s32 func_80800E44_sudeflect(f32 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 *param_4, f32 param_5)
{
    f32 local_0;
    local_0 = param_4[1] - param_0[1];
    if (param_1 < local_0 - param_5) return 0;
    if (local_0 + param_5 < param_2) return 0;
    return func_800F0064(param_0, param_3 + param_5, param_4);
}

s32 func_80800ECC_sudeflect(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3)
{
    f32 local_3;
    f32 local_4;
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;

    func_800EE7F8(local_0, param_2);
    func_800EE7F8(local_1, param_2);
    for (local_2 = 0; local_2 < 3; local_2++) {
        local_0[local_2] -= param_3;
        local_1[local_2] += param_3;
    }
    if (local_0[1] >= param_1[1] || local_1[1] <= param_0[1]) return 0;
    local_4 = local_1[0] - param_0[0];
    local_3 = local_0[0] - param_1[0];
    if (local_3 >= 0.0f || local_4 <= 0.0f) return 0;
    local_4 = local_1[2] - param_0[2];
    local_3 = local_0[2] - param_1[2];
    if (local_3 >= 0.0f || local_4 <= 0.0f) return 0;
    return 1;
}
