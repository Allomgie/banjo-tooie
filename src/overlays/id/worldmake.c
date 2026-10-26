#include "common.h"

#define WORLD_MAKE_STATE_RECORD_DEFINED
#define WORLD_MAKE_CALLBACKS_DEFINED
typedef struct { s32 unk0; s16 unk4; u8 unk6; u8 unk7; u8 unk8[0xA0]; } WorldMakeStateRecord;
typedef struct { void (*unk0)(void *, s32, s32, s16, s32); void (*unk4)(void *); } WorldMakeCallbacks;
extern void *D_80127EF8;
extern WorldMakeCallbacks D_80800AB0_idworldmake[];
extern void *vector_new(u32, u32);
extern void *vector_push_back(void **);
typedef struct { s32 local_0; u8 pad_0[2]; u8 local_1; u8 pad_1; u8 local_2[0xA0]; } WorldCreationItem;
typedef struct { u8 pad_0[8]; void *local_0; } WorldCreationList;
extern WorldCreationList D_80127EF0;
extern void *vector_begin(void *);
extern void *vector_end(void *);
typedef struct { u8 pad_0[6]; u8 unk6; u8 pad_7; u8 unk8[0xA0]; } WorldMakeRecord;
extern void vector_free(void *);

void func_80800000_idworldmake(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    WorldMakeStateRecord *local_0;
    if (D_80127EF8 == NULL) D_80127EF8 = vector_new(sizeof(WorldMakeStateRecord), 2);
    local_0 = vector_push_back(&D_80127EF8);
    local_0->unk6 = param_2;
    local_0->unk0 = param_0;
    local_0->unk4 = param_1;
    local_0->unk7 = 1;
    D_80800AB0_idworldmake[local_0->unk6].unk0(local_0->unk8, param_3, param_0, local_0->unk4, param_4);
}

void idworldmake_entrypoint_0(s32 param_0, s32 param_1) {
    s16 *sp34;
    s16 *temp_v0;
    s16 *var_s2;
    s16 temp_a1;
    s32 var_s3;
    temp_v0 = _glidmake_entrypoint_1();
    sp34 = temp_v0;
    var_s2 = temp_v0 + 1;
    var_s3 = 0;
    if (*temp_v0 > 0) {
        do {
            temp_a1 = *var_s2;
            if ((temp_a1 >= 0x65) && (temp_a1 < 0xC8)) func_80800000_idworldmake(param_0, temp_a1, 1, temp_a1 - 0x64, param_1);
            else if ((temp_a1 >= 0xC8) && (temp_a1 < 0x12C)) func_80800000_idworldmake(param_0, temp_a1, 0, temp_a1 - 0xC8, param_1);
            else if ((temp_a1 >= 0x12C) && (temp_a1 < 0x190)) func_80800000_idworldmake(param_0, temp_a1, 3, temp_a1 - 0x12C, param_1);
            else if ((temp_a1 >= 0x190) && (temp_a1 < 0x1F4)) func_80800000_idworldmake(param_0, temp_a1, 2, temp_a1 - 0x190, param_1);
            else if ((temp_a1 >= 0x1F4) && (temp_a1 < 0x258)) func_80800000_idworldmake(param_0, temp_a1, 4, temp_a1 - 0x1F4, param_1);
            else if ((temp_a1 >= 0x258) && (temp_a1 < 0x2BC)) func_80800000_idworldmake(param_0, temp_a1, 2, temp_a1 - 0x258, param_1);
            else if ((temp_a1 >= 0x2BC) && (temp_a1 < 0x320)) func_80800000_idworldmake(param_0, temp_a1, 5, temp_a1 - 0x2BC, param_1);
            else if ((temp_a1 >= 0x320) && (temp_a1 < 0x384)) func_80800000_idworldmake(param_0, temp_a1, 6, temp_a1 - 0x320, param_1);
            else if ((temp_a1 >= 0x384) && (temp_a1 < 0x3E8)) func_80800000_idworldmake(param_0, temp_a1, 8, temp_a1 - 0x384, param_1);
            else if ((temp_a1 >= 0x3E8) && (temp_a1 < 0x44C)) func_80800000_idworldmake(param_0, temp_a1, 7, temp_a1 - 0x3E8, param_1);
            else if ((temp_a1 >= 0x44C) && (temp_a1 < 0x4B0)) func_80800000_idworldmake(param_0, temp_a1, 9, temp_a1 - 0x44C, param_1);
            else if ((temp_a1 >= 0x4B0) && (temp_a1 < 0x6A4)) func_80800000_idworldmake(param_0, temp_a1, 0xA, temp_a1 - 0x4B0, param_1);
            else if ((temp_a1 >= 0x6A4) && (temp_a1 < 0x708)) func_80800000_idworldmake(param_0, temp_a1, 0xB, temp_a1 - 0x6A4, param_1);
            else if ((temp_a1 >= 0x708) && (temp_a1 < 0x76C)) func_80800000_idworldmake(param_0, temp_a1, 0xC, temp_a1 - 0x708, param_1);
            else if ((temp_a1 >= 0x76C) && (temp_a1 < 0x7D0)) func_80800000_idworldmake(param_0, temp_a1, 0xD, temp_a1 - 0x76C, param_1);
            else if ((temp_a1 >= 0x7D0) && (temp_a1 < 0x834)) func_80800000_idworldmake(param_0, temp_a1, 0xE, temp_a1 - 0x7D0, param_1);
            else if ((temp_a1 >= 0x834) && (temp_a1 < 0x898)) func_80800000_idworldmake(param_0, temp_a1, 0xA, temp_a1 - 0x4B0, param_1);
            else if ((temp_a1 >= 0x898) && (temp_a1 < 0x8FC)) func_80800000_idworldmake(param_0, temp_a1, 0xF, temp_a1 - 0x898, param_1);
            var_s3 += 1;
            var_s2 += *(s16 *)((u8 *)var_s2 + 2);
            var_s2 += 2;
        } while (var_s3 < *sp34);
    }
}

void idworldmake_entrypoint_1(s32 param_0, s32 param_1, volatile unsigned int param_2, s32 param_3)
{
  s16 *sp3C;
  int new_var;
  s16 *temp_v0;
  s16 *var_s3;
  s16 temp_a1;
  s32 var_s4;
  temp_v0 = _glidmake_entrypoint_1();
  sp3C = temp_v0;
  var_s3 = temp_v0 + 1;
  var_s4 = 0;
  if ((*temp_v0) > 0)
  {
    do
    {
      temp_a1 = *((s16 *) (((s8 *) var_s3) + 0));
      if (param_2 == temp_a1)
      {
        if ((param_1 >= 0x65) && (param_1 < 0xC8))
        {
          func_80800000_idworldmake(param_0, temp_a1, 1, param_1 - 0x64, param_3);
        }
        else
          if ((param_1 >= 0xC8) && (param_1 < 0x12C))
        {
          func_80800000_idworldmake(param_0, temp_a1, 0, param_1 - 0xC8, param_3);
        }
        else
          if ((param_1 >= 0x12C) && (param_1 < 0x190))
        {
          func_80800000_idworldmake(param_0, temp_a1, 3, param_1 - 0x12C, param_3);
        }
        else
          if ((param_1 >= 0x190) && (param_1 < 0x1F4))
        {
          func_80800000_idworldmake(param_0, temp_a1, 2, param_1 - 0x190, param_3);
        }
        else
          if ((param_1 >= 0x1F4) && (param_1 < 0x258))
        {
          func_80800000_idworldmake(param_0, temp_a1, 4, param_1 - 0x1F4, param_3);
        }
        else
          if ((param_1 >= 0x258) && (param_1 < 0x2BC))
        {
          func_80800000_idworldmake(param_0, temp_a1, 2, param_1 - 0x258, param_3);
        }
        else
          if ((param_1 >= 0x320) && (param_1 < 0x384))
        {
          func_80800000_idworldmake(param_0, temp_a1, 6, param_1 - 0x320, param_3);
        }
        else
          if ((param_1 >= 0x384) && (param_1 < 0x3E8))
        {
          func_80800000_idworldmake(param_0, temp_a1, 8, param_1 - 0x384, param_3);
        }
        else
          if ((param_1 >= 0x3E8) && (param_1 < 0x44C))
        {
          func_80800000_idworldmake(param_0, temp_a1, 7, param_1 - 0x3E8, param_3);
        }
        else
          if ((param_1 >= 0x44C) && (param_1 < 0x4B0))
        {
          func_80800000_idworldmake(param_0, temp_a1, 9, param_1 - 0x44C, param_3);
        }
        else
          if ((param_1 >= 0x6A4) && (param_1 < 0x708))
        {
          func_80800000_idworldmake(param_0, temp_a1, 0xB, param_1 - 0x6A4, param_3);
        }
        else
          if ((param_1 >= 0x708) && (param_1 < 0x76C))
        {
          func_80800000_idworldmake(param_0, temp_a1, 0xC, param_1 - 0x708, param_3);
        }
        else
          if ((param_1 >= 0x76C) && (param_1 < 0x7CF))
        {
          func_80800000_idworldmake(param_0, temp_a1, 0xD, param_1 - 0x76C, param_3);
        }
        else
          if ((param_1 >= 0x2BC) && (param_1 < 0x320))
        {
          func_80800000_idworldmake(param_0, temp_a1, 5, param_1 - 0x2BC, param_3);
        }
        else
          if ((param_1 >= 0x4B0) && (param_1 < 0x6A4))
        {
          func_80800000_idworldmake(param_0, temp_a1, 0xA, param_1 - 0x4B0, param_3);
        }
        else
          if ((param_1 >= 0x898) && (param_1 < 0x8FC))
        {
          func_80800000_idworldmake(param_0, temp_a1, 0xF, param_1 - 0x898, param_3);
        }
      }
      var_s4 += 1;
      var_s3 = (&var_s3[*((s16 *) (((s8 *) var_s3) + 2))]) + (new_var = 2);
    }
    while (var_s4 < (*sp3C));
  }
}

void idworldmake_entrypoint_2(s32 param_0)
{
    WorldCreationItem *local_0;
    WorldCreationItem *local_1;

    local_1 = vector_end(D_80127EF0.local_0);
    for (local_0 = vector_begin(D_80127EF0.local_0); local_0 < local_1; local_0++) {
        if (local_0->local_0 == param_0) {
            D_80800AB0_idworldmake[local_0->local_1].unk4(local_0->local_2);
            vector_erase(D_80127EF0.local_0, vector_index_of(D_80127EF0.local_0, local_0));
            local_0 = vector_begin(D_80127EF0.local_0);
            local_1 = vector_end(D_80127EF0.local_0);
        }
    }
}

void idworldmake_entrypoint_3(void)
{
    WorldMakeRecord *local_0;
    WorldMakeRecord *local_1;

    if (D_80127EF8 != 0) {
        local_0 = vector_end(D_80127EF8);
        local_1 = vector_begin(D_80127EF8);
        while (local_1 < local_0) {
            D_80800AB0_idworldmake[local_1->unk6].unk4(local_1->unk8);
            local_1++;
        }
        vector_free(D_80127EF8);
        D_80127EF8 = 0;
    }
}

void idworldmake_entrypoint_4(void) {
}

void idworldmake_entrypoint_5(s32 param_0, s32 param_1)
{
    WorldMakeStateRecord *local_1;
    WorldMakeStateRecord *local_0;

    local_0 = vector_end(D_80127EF8);
    local_1 = vector_begin(D_80127EF8);
    while (local_1 < local_0) {
        if (param_0 == local_1->unk0) {
            local_1->unk7 = param_1;
        }
        local_1++;
    }
}

void idworldmake_entrypoint_6(s32 param_0, s32 param_1, s32 param_2)
{
    WorldMakeStateRecord *local_1;
    WorldMakeStateRecord *local_0;

    local_0 = vector_end(D_80127EF8);
    local_1 = vector_begin(D_80127EF8);
    while (local_1 < local_0) {
        if (param_0 == local_1->unk0 && !((1 << local_1->unk6) & param_2)) {
            local_1->unk7 = param_1;
        }
        local_1++;
    }
}

void idworldmake_entrypoint_7(s32 param_0, s32 param_1, s32 param_2)
{
    WorldMakeStateRecord *local_1;
    WorldMakeStateRecord *local_0;

    local_0 = vector_end(D_80127EF8);
    local_1 = vector_begin(D_80127EF8);
    while (local_1 < local_0) {
        if (param_0 == local_1->unk0 && param_1 == local_1->unk4) {
            local_1->unk7 = param_2;
        }
        local_1++;
    }
}
