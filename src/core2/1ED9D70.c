#include "common.h"
#include "freelist.h"

extern u8 unk8[];
extern u8 unk2[];
extern void *defrag(void *arg);
typedef struct { s32 unk0; s32 unk4; s32 unk8; } D_801243A0_t;
extern D_801243A0_t D_801243A0;
extern D_801243A0_t D_801243DC;
extern FreeList *D_80135A60;
typedef struct { u8 pad_0[0x17]; u8 field_17; } LocalObject_801007B8;
typedef struct { LocalObject_801007B8 *field_0[2]; u8 field_8, field_9, field_A; } LocalInstance;
typedef struct { void *field_0; s16 field_4, field_6; u8 field_8; u8 field_9[3]; } LocalCache;
typedef struct { FreeList *field_0, *field_4; s32 field_8; } LocalPools;
extern FreeList *D_80135A64;
extern void *func_800B2840(void *);
extern void *func_800D674C(s32);
extern LocalObject_801007B8 *func_800B2400(void *, s32);
extern void *_glpackvtx_entrypoint_0();
extern void _glpackvtx_entrypoint_1(void *);
extern void func_800F2F20();
extern void func_800F31EC();
extern s32 D_80135A68;
extern void freelist_free();
typedef struct { void *local_0, *local_1; } State100B4C;
typedef struct { u8 pad_0[0x14]; u32 pad_14:31; u32 field_17:1; } LocalObject_80100D24;
struct OSPiInfo { u32 field0; u32 field4; };
typedef struct { u8 pad_0[0x17]; u8 field_17; } LocalObject_80100F0C;
void func_80100C74();

s32 func_80100480(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;
    u8 *local_2;

    local_2 = (u8 *)((s32 *) &D_801243A0) + param_0 * 12;
    local_0 = *(s32 *)((s8 *)local_2 + 8);
    if (local_0 == 0) {
        *(s16 *)((s8 *)local_2 + 2) = param_1;
        local_1 = heap_alloc(*(s16 *)((s8 *)local_2 + 2) * *(s16 *)((s8 *)local_2 + 0));
        *(s32 *)((s8 *)local_2 + 8) = local_1;
    } else if (*(s16 *)((s8 *)local_2 + 2) < param_1) {
        *(s16 *)((s8 *)local_2 + 2) = param_1;
        local_1 = heap_realloc(local_0, *(s16 *)((s8 *)local_2 + 2) * *(s16 *)((s8 *)local_2 + 0));
        *(s32 *)((s8 *)local_2 + 8) = local_1;
    }
    (*(s32 *)((s8 *)local_2 + 4)) = func_8001211C();
    return *(s32 *)((s8 *)local_2 + 8);
}

void func_8010052C(void) {
}

void func_80100534(void)
{
  s32 local_0;
  ALBank *local_1;
  local_0 = func_8001211C();
 local_1 = (ALBank *) (((u8 *) &D_801243A0)); do {
    if (((*((s32 *) (((char *) local_1) + 0x8))) != 0) && ((local_0 - (*((s32 *) (((char *) local_1) + 0x4)))) >= 0x1F))
    {
      heap_free(*((s32 *) (((char *) local_1) + 0x8)));
      *((s32 *) (((char *) local_1) + 0x8)) = 0;
      *((s16 *) (((char *) local_1) + 0x2)) = 0;
      *((s32 *) (((char *) local_1) + 0x4)) = 0;
    }
    local_1 = (ALBank *) (((char *) local_1) + 0xC);
  }
  while (local_1 != ((ALBank *) (((u8 *) &D_801243DC))));
}

void func_801005B8()
{
  D_801243A0_t *local_0 = &D_801243A0, *local_1 = &D_801243DC;
  do {
    s32 new_var3 = local_0->unk8;
    if (new_var3 != 0)
    {
      local_0->unk8 = (s32) defrag((void *)new_var3);
    }
    local_0++;
  } while (local_0 != local_1);
}

void func_80100610(void)
{
  s32 local_1;
  s8 *local_0;
 local_0 = ((s8 *) &D_801243A0); do {
    local_1 = *((s32 *) (((0, (s8 *) local_0)) - -8));
    if (local_1 != 0)
    {
      heap_free(local_1);
      *((s32 *) (8 + ((s8 *) local_0))) = 0;
      *((s16 *) (local_0 + 2)) = 0;
      *((s32 *) (((s8 *) local_0) + 4)) = 0;
    }
    local_0 += 0xC;
  }
  while (local_0 != (((s8 *) &D_801243DC)));
}

void func_80100670()
{
    func_80100610();
}

int func_80100690(s32 param_0)
{
  if (!D_80135A60)
  {
    D_80135A60 = freelist_new(0xC, 2);
  }
  freelist_next(&D_80135A60, param_0);
}

int func_801006E0(s32 param_0)
{
  s32 *new_var;
  if (!((void *) D_80135A64))
  {
 new_var = freelist_new(0xC, 2); do { D_80135A64 = new_var; } while (0);
  }
  new_var = &param_0;
  freelist_next(((void * *) &D_80135A64), *new_var);
}

int func_8010072C(s32 *param_0, u8 *param_1) {
    if (param_0 != 0) return param_0[0] == param_1[0] && param_0[1] == param_1[1] && param_0[2] == param_1[2];
    return 255 == param_1[0] && 255 == param_1[1] && 255 == param_1[2];
}

s32 func_801007B8(void *param_0, s32 param_1, s32 param_2, u8 *param_3)
{
    LocalCache *local_0;
    void *local_1;
    s32 local_2;
    if ((*((LocalPools *) &D_80135A60)).field_4) {
        for (local_2 = 1; local_2 < freelist_capacity((*((LocalPools *) &D_80135A60)).field_4); local_2++) {
            if (freelist_is_element_alive((*((LocalPools *) &D_80135A60)).field_4, local_2)) {
                local_0 = freelist_at((*((LocalPools *) &D_80135A60)).field_4, local_2);
                if (param_1 == local_0->field_4 && param_2 == local_0->field_6 && func_8010072C(param_3, local_0->field_9)) {
                    local_0->field_8++;
                    return local_2;
                }
            }
        }
    }
    local_0 = func_801006E0(&local_2);
    if (param_2) local_1 = func_800D674C(param_2);
    else local_1 = NULL;
    local_0->field_0 = _glpackvtx_entrypoint_0(func_800B2840(param_0), local_1, param_3);
    local_0->field_4 = param_1;
    local_0->field_6 = param_2;
    local_0->field_8 = 1;
    if (param_3) func_800F2F20(local_0->field_9, param_3);
    else func_800F31EC(local_0->field_9, 0xFF, 0xFF, 0xFF);
    return local_2;
}

void func_80100938(s32 param_0)
{
  u8 *local_2;
  local_2 = freelist_at(D_80135A64, param_0);
  local_2[8]--;
  if (local_2[8] == 0)
  {
    _glpackvtx_entrypoint_1(*(s32 *)local_2);
    *(s32 *)local_2 = 0;
    *(s16 *)(local_2 + 4) = 0;
    freelist_erase(D_80135A64, param_0);
    if (freelist_used_count(D_80135A64) == 0)
    {
      freelist_free(D_80135A64);
      D_80135A64 = 0;
    }
  }
}

int func_801009C4(ALTempoEvent *param_0, s32 param_1)
{
  ALTempoEvent **local_0;
  s32 var_s0;
  s32 temp_v0;
  var_s0 = 0;
  local_0 = param_0;
  do
  {
    if (*local_0)
    {
      func_800B23E0(*local_0);
    }
    var_s0 += 4;
    local_0 += 1;
  }
  while (var_s0 != 8);
  temp_v0 = *((u8 *) (((char *) param_0) + 0x8));
  if (temp_v0 != 0)
  {
    func_80100938(temp_v0 ^ 0);
  }
  *((s8 *) (((char *) param_0) + 0x9)) = 0;
  freelist_erase(*((s32 *) ((u8 *) &D_80135A60)), param_1);
  if (freelist_used_count(*((s32 *) ((u8 *) &D_80135A60))) == 0)
  {
    freelist_free(*((s32 *) ((u8 *) &D_80135A60)));
    *((s32 *) ((u8 *) &D_80135A60)) = 0;
  }
}

int func_80100A74(param_0, param_1) s16 param_0; s32 param_1;
{
  s32 var_v1;
  u8 *temp_v0;
  int new_var;
  temp_v0 = freelist_at(((int) D_80135A60), (long) param_0);
  ;
  return (temp_v0[new_var = 9]) ? (*(((s32 *) temp_v0) + param_1)) : (0);
}

s32 func_80100AC4(param_0) s16 param_0; {
    u8 *local_0;
    u8 *local_1;
    local_0 = freelist_at(D_80135A60, param_0);
    if (local_0[8] == 0) {
        return 0;
    }
    local_1 = freelist_at(((s32) D_80135A64), local_0[8]);
    return local_1[8] ? *(s32 *)local_1 : 0;
}

void func_80100B3C()
{
  D_80135A68 = 0x3667;
}

void func_80100B4C(void) {
    s32 local_0;
    func_80100C74();
    func_80100C74();
    for (local_0 = 1; (*((State100B4C *) &D_80135A60)).local_0 && local_0 < freelist_capacity((*((State100B4C *) &D_80135A60)).local_0); local_0++) {
        if (freelist_is_element_alive((*((State100B4C *) &D_80135A60)).local_0, local_0))
            func_801009C4(freelist_at((*((State100B4C *) &D_80135A60)).local_0, local_0), local_0);
    }
    if ((*((State100B4C *) &D_80135A60)).local_0) { freelist_free((*((State100B4C *) &D_80135A60)).local_0); (*((State100B4C *) &D_80135A60)).local_0 = 0; }
    if ((*((State100B4C *) &D_80135A60)).local_1) {
        for (local_0 = 1; local_0 < freelist_capacity((*((State100B4C *) &D_80135A60)).local_1); local_0++) {
            if (freelist_is_element_alive((*((State100B4C *) &D_80135A60)).local_1, local_0))
                _glpackvtx_entrypoint_1(*(void **)freelist_at((*((State100B4C *) &D_80135A60)).local_1, local_0));
        }
        freelist_free((*((State100B4C *) &D_80135A60)).local_1); (*((State100B4C *) &D_80135A60)).local_1 = 0;
    }
}

void func_80100C74()
{
  s32 local_0;
  u8 *local_1;
  local_0 = 1;
  if (D_80135A60 == 0)
  {
    return;
  }
  if (freelist_capacity(D_80135A60) < 2)
  {
    return;
  }
  for (;;)
  {
    if (!freelist_is_element_alive(D_80135A60, local_0))
    {
      goto next;
    }
    local_1 = freelist_at(D_80135A60, local_0);
    if (local_1[0xA] == 0)
    {
      goto next;
    }
    if ((--local_1[0xA]) != 0)
    {
      goto next;
    }
    func_801009C4(local_1, local_0);
    next:
    local_0++;

    if ((D_80135A60 == 0) || (local_0 >= freelist_capacity(D_80135A60)))
    {
      break;
    }
  }

}

s16 func_80100D24(void *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, u8 *param_5)
{
    LocalObject_80100D24 *local_4;
    s32 local_0;
    LocalInstance *local_1;
    void *local_2;
    s32 local_3;
    local_1 = func_80100690(&local_0);
    local_2 = func_800B2840(param_0);
    for (local_3 = 0; local_3 < 2; local_3++) {
        if (local_3 < param_2) {
            local_4 = func_800B2400(local_2, 0);
            local_1->field_0[local_3] = local_4;
            local_4->field_17 = 1;
        } else {
            local_1->field_0[local_3] = NULL;
        }
    }
    if (param_3) local_1->field_8 = func_801007B8(param_0, param_1, param_4, param_5);
    else local_1->field_8 = 0;
    local_1->field_9 = 1;
    local_1->field_A = 0;
    return local_0;
}

s32 func_80100E18(indx) s16 indx;{
    s32 local_0 = freelist_at(D_80135A60, indx);
    *(u8 *)(local_0 + 0xA) = 2;
}

void func_80100E54()
{
  struct OSPiInfo *s0;
  u32 new_var;
  struct OSPiInfo *s1;
  s1 = (struct OSPiInfo *) (*((struct OSPiInfo *) &D_80135A60)).field0;
  if (s1 != 0)
  {
    (*((struct OSPiInfo *) &D_80135A60)).field0 = (new_var = (u32) freelist_defrag((void *) (*((struct OSPiInfo *) &D_80135A60)).field0));
  }
  s0 = (struct OSPiInfo *) (*((struct OSPiInfo *) &D_80135A60)).field4;
  if (s0 != 0)
  {
    int local_1;
    for (local_1 = 1; local_1 < freelist_capacity((void *) (*((struct OSPiInfo *) &D_80135A60)).field4); local_1++)
    {
      if (freelist_is_element_alive((void *) (*((struct OSPiInfo *) &D_80135A60)).field4, local_1))
      {
        s0 = (struct OSPiInfo *) freelist_at((void *) (*((struct OSPiInfo *) &D_80135A60)).field4, local_1);
        if ((((!(*((struct OSPiInfo *) &D_80135A60)).field0) && (!(*((struct OSPiInfo *) &D_80135A60)).field0)) && (!(*((struct OSPiInfo *) &D_80135A60)).field0)) != 0)
        {
        }
        s0->field0 = (u32)defrag((void *)s0->field0);
      }
      do
      {
      }
      while (0);
    }

    if (!s0)
    {
    }
    (*((struct OSPiInfo *) &D_80135A60)).field4 = (u32) freelist_defrag((void *) (*((struct OSPiInfo *) &D_80135A60)).field4);
  }
}

void func_80100F0C(s16 param_0, void *param_1)
{
    LocalInstance *local_0;
    LocalCache *local_1;
    void *local_4;
    s32 local_2;
    s32 local_3;
    local_0 = freelist_at((*((LocalPools *) &D_80135A60)).field_0, param_0);
    if (local_0->field_8) {
        local_1 = freelist_at(D_80135A64, local_0->field_8);
        if (local_1->field_8) {
            local_2 = local_1->field_4;
            if (local_1->field_6 < 0x3666) {
                func_80100938(local_0->field_8);
                local_1 = func_801006E0(&local_3);
                local_0->field_8 = local_3;
            } else {
                _glpackvtx_entrypoint_1(local_1->field_0);
            }
            local_4 = func_800D674C(local_2);
            local_1->field_0 = _glpackvtx_entrypoint_0(func_800B2840(local_4), param_1, NULL);
            local_1->field_4 = local_2;
            local_1->field_6 = (*((LocalPools *) &D_80135A60)).field_8;
            (*((LocalPools *) &D_80135A60)).field_8++;
            local_1->field_8 = 1;
        }
    }
}
