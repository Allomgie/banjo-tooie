#include "common.h"
#include "vector.h"

#define CODEX_WORLD_RECORD
typedef struct { s32 unk0; s16 unk4; u8 unk6; u8 pad7; u8 unk8[0xA0]; } WorldLookupRecord;
extern Vector *D_80127EF8;
typedef struct { s32 local_0; s16 local_1; u8 local_2; u8 local_3; u8 local_4[0xA0]; } WorldItemRecord61;
typedef struct { s32 pad_0[2]; Vector *local_0; } WorldItemList61;
extern WorldItemList61 D_80127EF0;
typedef void (*WorldDrawFn)(void *, s32, s32);
extern WorldDrawFn D_808002C0_idworld[];

WorldLookupRecord *func_80800000_idworld(s32 param_0, s32 param_1)
{
    WorldLookupRecord *local_1;
    WorldLookupRecord *local_0;

    if (D_80127EF8 == NULL) {
        return NULL;
    }
    local_0 = vector_end(D_80127EF8);
    for (local_1 = vector_begin(D_80127EF8); local_1 < local_0; local_1++) {
        if (param_1 == local_1->unk6 && param_0 == local_1->unk4) {
            return local_1;
        }
    }
    return NULL;
}

int idworld_entrypoint_0(s32 param_0)
{
  int local_0;
  int v;
  v = func_80800000_idworld(param_0, 6);
  if (v)
  {
    local_0 = v + 8;
  }
  else
  {
    local_0 = 0;
  }
  return local_0 | 0;
}

int idworld_entrypoint_1(s32 param_0)
{
  int local_0;
  int v;
  v = func_80800000_idworld(param_0, 8);
  if (v)
  {
    local_0 = v + 8;
  }
  else
  {
    local_0 = 0;
  }
  return local_0 | 0;
}

int idworld_entrypoint_2(s32 param_0)
{
  int local_0;
  int v;
  v = func_80800000_idworld(param_0, 0xC);
  if (v)
  {
    local_0 = v + 8;
  }
  else
  {
    local_0 = 0;
  }
  return local_0 | 0;
}

int idworld_entrypoint_3(s32 param_0)
{
  int local_0;
  int v;
  v = func_80800000_idworld(param_0, 2);
  if (v)
  {
    local_0 = v + 8;
  }
  else
  {
    local_0 = 0;
  }
  return local_0 | 0;
}

u8 *idworld_entrypoint_4(s32 param_0, s32 param_1)
{
    WorldLookupRecord *local_1;
    WorldLookupRecord *local_0;

    if (D_80127EF8 == NULL) {
        return NULL;
    }
    local_0 = vector_end(D_80127EF8);
    for (local_1 = vector_begin(D_80127EF8); local_1 < local_0; local_1++) {
        if (local_1->unk6 == 10 && param_0 == local_1->unk0 && param_1 == local_1->unk4) {
            return local_1->unk8;
        }
    }
    return NULL;
}

void idworld_entrypoint_5(void)
{
    WorldItemRecord61 *local_0;
    WorldItemRecord61 *local_1;

    local_1 = vector_end(D_80127EF0.local_0);
    for (local_0 = vector_begin(D_80127EF0.local_0); local_0 < local_1; local_0++) {
        if (local_0->local_3) {
            D_808002C0_idworld[local_0->local_2](local_0->local_4,
                local_0->local_0, local_0->local_1);
        }
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/id/world.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM. */
extern void _idlight_entrypoint_3();
extern void _idscroll_entrypoint_3();
extern void func_800EE108();
extern void _idwater_entrypoint_4();
extern void _idglow_entrypoint_3();
extern void _idwave_entrypoint_3();
extern void _idglowa_entrypoint_4();
extern void _idflash_entrypoint_3();
extern void _idflasha_entrypoint_4();
extern void func_800EC9E0();
extern void _idwibble_entrypoint_3();
extern void _idbounce_entrypoint_5();
extern void _idtwinkle_entrypoint_5();
extern void _idflame_entrypoint_4();
extern void _idtwinklea_entrypoint_2();
extern void _idtwinklecolour_entrypoint_5();
WorldDrawFn D_808002C0_idworld[16] = { (void *)_idlight_entrypoint_3, (void *)_idscroll_entrypoint_3, (void *)func_800EE108, (void *)_idwater_entrypoint_4, (void *)_idglow_entrypoint_3, (void *)_idwave_entrypoint_3, (void *)_idglowa_entrypoint_4, (void *)_idflash_entrypoint_3, (void *)_idflasha_entrypoint_4, (void *)func_800EC9E0, (void *)_idwibble_entrypoint_3, (void *)_idbounce_entrypoint_5, (void *)_idtwinkle_entrypoint_5, (void *)_idflame_entrypoint_4, (void *)_idtwinklea_entrypoint_2, (void *)_idtwinklecolour_entrypoint_5 };
