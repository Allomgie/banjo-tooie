#include "common.h"

typedef struct { s32 *p; s32 t; } Ent8001B4B0;
extern Ent8001B4B0 D_8007BF18[];
typedef struct { u8 unk0[0x20]; } Cell8001B4E8;
extern Cell8001B4E8 D_8007BF20[];
extern Cell8001B4E8 D_8007C6E0[];
typedef struct { s32 *local_0; s32 local_1; } Struct8001B518;
extern s32 D_8007C6E4;
extern s32 *defrag(s32 *param_0);
typedef struct { void *local_0; s32 local_1; } Struct8001B668;
extern void *heap_alloc_sided(s32, s32);
extern void func_8001B3A0(void *);
typedef union {
    s32 pair[2];
    double value;
} Union8007BF10;
extern Union8007BF10 D_8007BF10[];

void func_8001B4B0(void)
{
    s32 i;
    for (i = 0; i < 249; i++) {
        D_8007BF18[i].p = NULL;
    }
}

void func_8001B4E8(void)
{
    s32 i;

    i = 0;
    do {
        i++;
    } while (D_8007C6E0 != &D_8007BF20[i]);
}

void func_8001B50C()
{
  (*((int *) D_8007C6E0)) = 0;
}

void func_8001B518(s32 param_0)
{
  s32 *local_1;
  s32 *local_0;
  s32 local_2;
  s32 local_3;
  s32 local_4;
  s32 *new_var;
  s32 local_5;
  Struct8001B518 *local_6;
  if (((*((s32 *) D_8007C6E0)) == 0) || (param_0 != 0))
  {
    local_3 = param_0 != 0;
    (*((s32 *) D_8007C6E0)) = 1;
    local_4 = (local_3) ? (0xFA) : (0x14);
    local_3 = 1;
    if (local_4 >= 2)
    {
      do
      {
        local_5 = ++D_8007C6E4;
        if (local_5 >= 0xFA)
        {
          D_8007C6E4 = 0;
          local_5 = 0;
        }
        if ((local_0 = ((Struct8001B518 *) D_8007BF10)[local_5].local_0) != 0)
        {
          local_1 = defrag(new_var = local_0);
          local_0 = local_1;
          local_6 = &((Struct8001B518 *) D_8007BF10)[D_8007C6E4];
          local_6->local_0 = local_0;
          if (local_1 != new_var)
          {
            local_2 = local_6->local_1;
            if (local_2 != 0)
            {
              switch (local_2)
              {
                case 1:
                  func_800E0040(local_6->local_0);
                  break;

                case 3:
                  func_800E0AC0(local_6->local_0);
                  break;

                case 5:
                  vector_update_pointers(local_6->local_0);
                  break;

              }

            }
          }
        }
        local_3 += 1;
      }
      while (local_3 != local_4);
    }
  }
}

s16 func_8001B668(s32 param_0, s32 param_1)
{
    s32 local_0;

    local_0 = 1;
    if ((*((s32 *) D_8007BF18)) != 0) {
        do {
            local_0++;
        } while (((Struct8001B668 *) D_8007BF10)[local_0].local_0 != NULL);
    }

    if (local_0 < 0xFA) {
        ((Struct8001B668 *) D_8007BF10)[local_0].local_0 = heap_alloc_sided(param_1, 2);
        ((Struct8001B668 *) D_8007BF10)[local_0].local_1 = param_0;
        func_8001B3A0(((Struct8001B668 *) D_8007BF10)[local_0].local_0);
        return local_0;
    }

    return 0;
}

/* param_1 is passed through in $a1 untouched. That keeps $a1 live, which is
 * why IDO uses $a2 as the scratch of the s16 sign extension. No local
 * variable: locals are assigned downward from the top of the frame and
 * compiler temporaries go below them, so one local would push the spill of
 * the base pointer from 0x1C to 0x18. */
void func_8001B710(param_0, param_1) s16 param_0; s32 param_1;
{
  *(void **)&D_8007BF10[param_0].value =
      heap_realloc(*(void **)&D_8007BF10[param_0].value, param_1);
}

void func_8001B754(param_0) s16 param_0; {
    heap_free((void *)D_8007BF10[param_0].pair[0]);
    D_8007BF10[param_0].pair[0] = 0;
}

s32 func_8001B798(param_0) s16 param_0;
{
    return D_8007BF10[param_0].pair[0];
}

void func_8001B7B8(param_0) s16 param_0;
{
    heap_get_allocation_size(D_8007BF10[param_0].pair[0]);
}

void func_8001B7F0(param_0, param_1, param_2) s16 param_0; u8 param_1; s32 param_2; {
    u8 *local_0;
    u32 local_1;
    u32 local_2;

    local_1 = param_1;
    local_2 = param_0;
    local_0 = (u8 *)&((s64 *) D_8007BF10)[local_2];
    local_0 = (u8 *)*(s32 *)local_0;
    rare_memset(local_0, local_1, param_2);
}
