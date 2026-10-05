#include "common.h"
#include "memory.h"
#include "core2/1EC8070.h"
#include "core2/1ECB9F0.h"
#include "core2/1EB2840.h"
#include "core2/1EB5980.h"

extern int func_800BEF00(s32, f32 *, f32 *, u32);
typedef struct { s16 local_0[3]; /* 0x00: acceleration */ s16 local_1[3]; /* 0x06: position */ f32 local_2; /* 0x0C: fade */ f32 local_3[3]; /* 0x10: rotation */ f32 local_4; /* 0x1C: age in seconds */ s16 local_5[3]; /* 0x20: angular velocity */ s16 local_6[3]; /* 0x26: velocity */ s16 local_7; /* 0x2C: animation frame, eight fractional bits */ s16 local_8; /* 0x2E: frame rate in the same fixed-point units */ s16 local_9; /* 0x30: scale, eight fractional bits */ s16 local_10; /* 0x32: initial size, eight fractional bits */ s16 local_11; /* 0x34: final size minus initial size, same units */ s16 local_12; /* 0x36: lifetime, eight fractional bits */ u8 local_13; /* 0x38: remaining bounces */ u8 local_14 : 1; /* 0x39: visibility latch, consumed/reset by update */ u8 local_16 : 7; u8 local_15[2]; } Struct800B4790Particle;
typedef struct Struct800B4790Emitter { u16 local_0; /* Flags: 0x2000 velocity damping, 0x4000 rotation damping. */ u8 local_1[5]; u8 local_2; /* Spawn mode: 0 continuous, 1 finite batch, 2 stopped. */ u8 local_3[2]; u8 local_4; /* Asset type; 7 selects sprite animation. */ u8 local_5; /* Sprite frame count. */ u8 local_6[0xC]; f32 local_7; /* Normalized fade-in end. */ f32 local_8; /* Normalized fade-out start. */ f32 local_9; /* Time until next spawn. */ f32 local_10; /* Remaining emission duration, if positive. */ u8 local_11[0x2A]; u8 local_12; /* Animation: 0 unchanged, 1 loop, 2 hold final frame. */ u8 local_13; f32 local_14; /* Minimum spawn interval. */ f32 local_15; /* Maximum spawn interval. */ u8 local_16[0x2C]; s32 local_17; /* Optional water-height source. */ Struct800B4790Particle *local_18; /* Live range start. */ Struct800B4790Particle *local_19; /* Live range end (exclusive). */ Struct800B4790Particle *local_20; /* Spawn limit; shrinks in batch mode. */ s16 local_21; /* Offset from water height. */ u8 local_22[0x10]; s16 local_23; /* Bounce sound ID; zero disables it. */ u8 local_24[4]; f32 local_25; /* Bounce attenuation/restitution. */ f32 local_26; /* Minimum bounce-sound pitch. */ f32 local_27; /* Maximum bounce-sound pitch. */ s32 local_28; /* Bounce-sound base volume. */ void (*local_29)(struct Struct800B4790Emitter *, f32 *); /* Last-bounce callback. */ u8 local_30[0xC]; f32 local_31; /* Per-update damping multiplier. */ } Struct800B4790Emitter;
extern s32 _idwater_entrypoint_1(s32);
extern void func_800C3FC0(s32, f32, s32);
extern f32 D_80127F14;
extern u8 D_80127F1C;
extern s16 D_80127F18;
extern s32 *D_80127F10;
extern u8 D_80127F1D;
f32 func_800D8FF8(void);
extern void *defrag();
extern s16 D_80127F1A;
void func_800B5450();

int func_800B46B0(s16 *param_0, f32 *param_1, f32 *param_2, f32 *param_3)
{
    f32 local_0[3];

    param_1 = param_3;

    if (param_0[0x56] == -0x8000 && param_0[0x57] == 0x7FFF)
    {
        return func_800BEF00(
            param_2,
            param_1,
            local_0,
            (*(u16 *)param_0 & 0x100) ? 0x420021 : 0x400000
        );
    }

    if (param_0[0x57] != 0x7FFF && param_0[0x57] < param_1[1])
    {
        param_1[1] = param_0[0x57];
        return 1;
    }

    if (param_0[0x56] != -0x8000 && param_1[1] < param_0[0x56])
    {
        param_1[1] = param_0[0x56];
        return 1;
    }

    return 0;
}

void func_800B4790(Struct800B4790Emitter *param_0)
{
  Struct800B4790Particle *local_0;
  f32 local_6 = func_800D8FF8();
  f32 local_7;
  s32 local_4;
  f32 local_1[3];
  f32 local_2[3];
  s32 local_3;
  if (D_80127F1C != 0)
  {
    for (local_0 = param_0->local_18; local_0 < param_0->local_19;)
    {
      local_0->local_4 += local_6;
      if ((((f32) local_0->local_12) * 0.00390625f) <= local_0->local_4)
      {
        rare_memcpy(local_0, --param_0->local_19, sizeof(Struct800B4790Particle));
        if (param_0->local_2 == 1)
        {
          param_0->local_20--;
        }
      }
      else
      {
        f32 local_8;
        local_7 = local_0->local_4 / (((f32) local_0->local_12) * 0.00390625f);
        if (local_7 < param_0->local_7)
        {
          local_0->local_2 = local_7 / param_0->local_7;
        }
        else
          if (local_7 <= param_0->local_8)
        {
          local_0->local_2 = 1.0f;
        }
        else
        {
          local_0->local_2 = 1.0f - ((local_7 - param_0->local_8) / (1.0f - param_0->local_8));
        }
        local_0->local_9 = local_0->local_10 + ((s32) (((local_7 * ((f32) local_0->local_11)) * 0.00390625f) * 256.0f));
        if (param_0->local_4 == 7)
        {
          switch (param_0->local_12)
          {
            case 0: break;
            case 1:
              local_0->local_7 += (s32) (((f32) local_0->local_8) * local_6);
              if ((local_0->local_7 >> 8) >= param_0->local_5)
            {
              local_0->local_7 = 0;
            }
              break;

            case 2:
              local_0->local_7 += (s32) (((f32) local_0->local_8) * local_6);
              if ((local_0->local_7 >> 8) >= param_0->local_5)
            {
              local_0->local_7 = (param_0->local_5 << 8) - 0x100;
            }
              break;

          }

        }
        /* Add in floating point before narrowing back to the packed s16.
         * Casting the delta first would change both rounding and codegen. */
        for (local_4 = 0; local_4 < 3; local_4++)
        {
          local_0->local_1[local_4] += ((f32) local_0->local_6[local_4]) * local_6;
          local_0->local_3[local_4] += ((f32) local_0->local_5[local_4]) * local_6;
          local_0->local_6[local_4] += ((f32) local_0->local_0[local_4]) * local_6;
        }

        if (param_0->local_0 & 0x2000)
        {
          for (local_4 = 0; local_4 < 3; local_4++)
          {
            local_0->local_6[local_4] = (s32) (((f32) local_0->local_6[local_4]) * param_0->local_31);
          }

        }
        if (param_0->local_0 & 0x4000)
        {
          for (local_4 = 0; local_4 < 3; local_4++)
          {
            local_0->local_3[local_4] *= param_0->local_31;
          }

        }
        if (param_0->local_17 != 0)
        {
          local_0->local_1[1] = _idwater_entrypoint_1(param_0->local_17) + param_0->local_21;
        }
        func_800EE88C(local_1, local_0->local_1);
        if ((param_0->local_0 & 0x1000) && (local_0->local_14 == 0))
        {
          rare_memcpy(local_0, --param_0->local_19, sizeof(Struct800B4790Particle));
          if (param_0->local_2 == 1)
          {
            param_0->local_20--;
          }
        }
        else
        {
          local_0->local_14 = 0;
          if (local_0->local_13 > 0)
          {
            func_800EFA4C(local_2, (f32) local_0->local_1[0], ((f32) local_0->local_1[1]) + 50.0f, (f32) local_0->local_1[2]);
            local_3 = func_800B46B0(param_0, local_0, local_2, local_1);
            func_800EE940(local_0->local_1, local_1);
            if (local_3 != 0) {
            if (param_0->local_23 != 0)
            {
              local_8 = mlAbsF((f32) local_0->local_6[1]) * 0.1f;
              if (local_8 > 1)
              {
                local_8 = 1;
              }
              /* Shared cooldown suppresses simultaneous bounce sounds. */
              if (D_80127F14 == 0.0f)
              {
                func_800C3FC0(param_0->local_23, func_800DC178(param_0->local_26, param_0->local_27), (s32) (((f32) param_0->local_28) * local_8));
                D_80127F14 = 0.25f;
              }
            }
            local_0->local_1[1] += 2;
            local_1[1] += 2.0f;
            local_0->local_6[1] = (s32) (mlAbsF((f32) local_0->local_6[1]) * param_0->local_25);
            if (param_0->local_0 & 0x80)
            {
              local_0->local_6[0] = (s32) (((f32) local_0->local_6[0]) * param_0->local_25);
              local_0->local_6[2] = (s32) (((f32) local_0->local_6[2]) * param_0->local_25);
            }
            if (!(param_0->local_0 & 2))
            {
              local_0->local_10 = (s32) (((f32) local_0->local_10) * param_0->local_25);
              local_0->local_11 = (s32) (((f32) local_0->local_11) * param_0->local_25);
            }
            local_0->local_5[0] = (s32) (((f32) local_0->local_5[0]) * param_0->local_25);
            local_0->local_5[1] = (s32) (((f32) local_0->local_5[1]) * param_0->local_25);
            local_0->local_5[2] = (s32) (((f32) local_0->local_5[2]) * param_0->local_25);
            if (!(local_0->local_13 = local_0->local_13 - 1))
            {
              if (param_0->local_29 != 0)
              {
                param_0->local_29(param_0, local_1);
              }
              rare_memcpy(local_0, --param_0->local_19, sizeof(Struct800B4790Particle));
              if (param_0->local_2 == 1)
              {
                param_0->local_20--;
              }
              continue;
            }
            }
          }
          local_0++;
        }
      }
    }

    if (param_0->local_10 > 0.0f)
    {
      param_0->local_10 -= local_6;
      if (param_0->local_10 <= 0.0f)
      {
        param_0->local_2 = 2;
      }
    }
    switch (param_0->local_2)
    {
      case 0:
        param_0->local_9 -= local_6;
        if (param_0->local_9 <= 0.0f)
      {
        param_0->local_9 = func_800DC178(param_0->local_14, param_0->local_15);
        {
          if (param_0->local_19 < param_0->local_20)
          {
            func_800B9B50(param_0, param_0->local_19++);
            return;
          }
        }
      }
        break;

      case 1:
        param_0->local_9 -= local_6;
        if (param_0->local_9 <= 0.0f)
      {
        param_0->local_9 = func_800DC178(param_0->local_14, param_0->local_15);
        {
          if ((param_0->local_20 - param_0->local_19) > 0)
          {
            func_800B9B50(param_0, param_0->local_19++);
            return;
          }
          param_0->local_2 = 2;
        }
      }
        break;

    }

  }
}

s32 func_800B5028(void){
    D_80127F10 = heap_alloc(0);
    D_80127F18 = 0;
}

void func_800B5054(void)
{
  s32 local_0;
  s32 local_1;
  local_0 = 0;
  if (D_80127F18 > 0)
  {
 local_1 = 0; do { func_800BA2C4(*((s32 *) (((char *) D_80127F10) + local_1)));
      local_0 += 1;
      local_1 += 4;
    }
    while (local_0 < D_80127F18);
  }
  heap_free((void *) D_80127F10);
  D_80127F10 = 0;
  D_80127F18 = 0;
  D_80127F1D = 0;
}

void func_800B50F0(void)
{
  s32 var_s1;
  s32 var_s2;
  u8 *temp_s0;
  u8 *temp_a0;
  if (D_80127F14 < func_800D8FF8())
  {
    D_80127F14 = 0.0f;
  }
  else
  {
    D_80127F14 -= func_800D8FF8();
  }
  if (D_80127F10 != 0)
  {
    var_s2 = 0;
    var_s1 = 0;
    if (D_80127F18 > 0)
    {
      do
      {
        temp_s0 = *((u8 **) ((u8 *) D_80127F10 + var_s1));
        func_800B4790(temp_s0);
        if ((((*((u8 *) (((char *) temp_s0) + 9))) != 0) && ((*((u8 *) (((char *) temp_s0) + 7))) == 2)) && ((*((s32 *) (((char *) temp_s0) + 0x8C))) == (*((s32 *) (((char *) temp_s0) + 0x90)))))
        {
          *((s8 *) (((char *) temp_s0) + 8)) = 1;
        }
        else
        {
          *((s8 *) (((char *) temp_s0) + 8)) = 0;
        }
        var_s2 += 1;
        var_s1 += 4;
      }
      while (var_s2 < D_80127F18);
    }
    temp_s0 = *((u8 **) ((u8 *) D_80127F10 + var_s1));
    var_s1 = 0;
    if (D_80127F18 > 0)
    {
      do
      {
        temp_a0 = *((u8 **) ((u8 *) D_80127F10 + var_s1));
        if ((*((u8 *) (((char *) temp_a0) + 8))) != 0)
        {
          func_800B5450(temp_a0);
        }
        else
        {
          var_s1 += 4;
        }
      }
      while (var_s1 < (D_80127F18 * 4));
    }
  }
}

void func_800B525C(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  local_0 = 0;
  while (local_0 < D_80127F18)
  {
    local_1 = ((s32*)D_80127F10)[local_0];
    local_2 = param_0 | 0;
    local_3 = 4;
    func_800BC358(local_1, local_2, local_3);
    local_0++;
  }
}

void func_800B52EC(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  local_0 = 0;
  while (local_0 < D_80127F18)
  {
    local_1 = ((s32*)D_80127F10)[local_0];
    local_2 = param_0 | 0;
    func_800BC358(local_1, local_2, 0);
    local_0++;
  }
}

void func_800B537C(s32 arg0)
{
    func_800B525C(arg0);
    func_800B52EC(arg0);
}
s32 func_800B53A4(s32 param_0)
{
    s32 *local_0;

    local_0 = ((s32 *) D_80127F10);
    D_80127F18 += 1;
    D_80127F10 = heap_realloc(local_0, D_80127F18 * 4);

    ((s32 *) D_80127F10)[D_80127F18 - 1] = func_800BA2E8(param_0);
    *((u8 *)((s32 *) D_80127F10)[D_80127F18 - 1] + 9) = 1;

    return ((s32 *) D_80127F10)[D_80127F18 - 1];
}

void func_800B5450(param_0) int param_0;
{
    s32 local_2;

    local_2 = 0;
    while (((s32 *) D_80127F10)[local_2] != param_0 && local_2 < D_80127F18)
    {
        local_2++;
    }

    if (local_2 == D_80127F18)
    {
        return;
    }

    func_800BA2C4(param_0);
    ((s32 *) D_80127F10)[local_2] = ((s32 *) D_80127F10)[D_80127F18 - 1];
    D_80127F18--;
    D_80127F10 = heap_realloc(((s32 *) D_80127F10), D_80127F18 * 4);
}

void func_800B5534(int *param_0)
{
  unsigned char *new_var;
  new_var += 0;
  new_var = param_0;
  new_var = new_var + 9;
  *new_var = 0;
}

void func_800B553C(int *param_0)
{
  unsigned char *new_var3;
  unsigned char *new_var2;
  int *new_var;
  do
  {
    dummy_label_194045:
    ;

    ;
    ;
    new_var = param_0;
    new_var = new_var + 2;
    new_var2++;
  }
  while (0);
  new_var2 = new_var;
  new_var3 = (unsigned char *) (new_var2 + 2);
  new_var2 = new_var3;
  new_var2--;
  *new_var2 = 1;
}

u8 *func_800B5548(u8 *param_0)
{
    s32 i;
    s32 a3;
    unsigned long new_var;

    if (param_0)
    {
        a3 = (s32)param_0;
        i = 0;

        while ((((void **) D_80127F10)[i] != param_0) && (i < D_80127F18))
        {
            i++;
        }

        param_0 = (u8 *)defrag(param_0);

        *(u8 **)(param_0 + 0x8C) =
            (u8 *)(((s32)*(u8 **)(param_0 + 0x8C) - a3) +
            (new_var = (s32)param_0));

        *(u8 **)(param_0 + 0x90) =
            (u8 *)(((s32)*(u8 **)(param_0 + 0x90) - a3) +
            (new_var = (s32)param_0));

        *(u8 **)(param_0 + 0x94) =
            (u8 *)(((s32)*(u8 **)(param_0 + 0x94) - a3) +
            (new_var = (s32)param_0));

        if (i < D_80127F18)
        {
            ((void **) D_80127F10)[i] = param_0;
        }
    }

    return param_0;
}

void func_800B562C(void) {
    D_80127F10 = defrag(((void *) D_80127F10));
}

s32 func_800B5654(s32 param_0, s32 param_1){
    if(param_1 == 0x02){
        D_80127F1C = TRUE;
    }
    else{
        D_80127F1C = FALSE;
    }
}

s32 func_800B5680(enum map_e map_id){
    D_80127F1D = TRUE;
    D_80127F1A = map_id;
}

s32 func_800B5698(s16 *param_0){
    if(D_80127F1D){
        *param_0 = D_80127F1A;
        return TRUE;
    }
    return FALSE;
}
