#include "common.h"
#include "vector.h"

typedef struct {s32 local_0, local_1;} local_type;
extern Vector *D_8012B7F0;
extern void *vector_begin();
extern void *vector_end();
extern void *D_8012B7F8;
extern s32 D_8012B7F4;
extern void vector_clear();
extern u8 D_8012B7E4;
extern u8 D_8012B7E5;
extern void *D_8012B450[];
extern u8 D_8012B658[];
extern s16 D_8012B6E0[];
extern void heap_free(void *);
extern s32 D_8011B900;

extern u32 D_8012B444;
extern s32 D_8012B448;
extern u8 D_8012B7E6;
typedef struct { u32 local_0:26; u32 local_1:2; u32 local_2:4; } AssetD5B34;
extern s32 func_800E4AF0(s32);
extern void *func_800E4BF4(s32);
extern void *_gldbDll_entrypoint_0(s32, s32 *);
extern void *func_800E6950(s32, s32, s32);
extern void *heap_alloc(s32);
extern void rom_dma_read(void *, s32, s32);
extern u8 assets_ROM_START[];
typedef struct { u32 offset:26; u32 flags:2; u32 pad:4; } LocalRomEntry;
typedef union {
    AssetD5B34 AssetD5B34;
    LocalRomEntry LocalRomEntry;
    u32 raw;
} Union_D_8012B440;
extern Union_D_8012B440 D_8012B440;
extern s32 rom_read_word(u32, void *);
s32 func_800D56C4();

extern s32 D_8012B7E8;

void func_800D5440(param_0) s32 param_0; {
    local_type *local_0;
    local_type *local_1;
    local_1 = vector_end(D_8012B7F0);
    for (local_0 = vector_begin(D_8012B7F0); local_0 < local_1 && param_0 != local_0->local_1; local_0++) {}
    if (local_0 < local_1) local_0->local_0++;
    else {
        local_0 = vector_push_back(&D_8012B7F0);
        local_0->local_0 = 1;
        local_0->local_1 = param_0;
    }
}

int func_800D54F0(param_0) s32 param_0;
{
  void *local_3;
  void **local_2;
  void *local_4;
  void *local_5;
  s32 *local_6;
 local_2 = ((void * *) &D_8012B7F0); local_3 = &D_8012B7F8; loop_1: local_4 = vector_end(*local_2);
  local_5 = vector_begin(*local_2);
  local_6 = (s32 *) local_5;
  if (local_5 < local_4)
  {
    if (param_0 != (*((s32 *) ((char *) local_5 + 4))))
    {
      loop_3:
      local_6 += 2;

      if (local_6 < ((s32 *) local_4))
      {
        if (param_0 != (*((s32 *) (((char *) local_6) + 4))))
        {
          goto loop_3;
        }
      }
    }
  }
  local_2 += 1;
  if (local_6 < ((s32 *) local_4))
  {
    return 1;
  }
  if (local_2 == local_3)
  {
    return 0;
  }
  goto loop_1;
}

void func_800D55A0()
{
  D_8012B7F0 = vector_new(8, 0x10);
  D_8012B7F4 = vector_new(8, 0x10);
}

void func_800D55DC(void)
{
  s32 i;
  u32 end;
  s32 tmp;
  s32 *it;
  tmp = ((s32 *) &D_8012B7F0)[0];
  ((s32 *) &D_8012B7F0)[0] = ((s32 *) &D_8012B7F0)[1];
  ((s32 *) &D_8012B7F0)[1] = tmp;
  end = vector_end(((s32 *) &D_8012B7F0)[0]);
  for (it = (s32 *)vector_begin(((s32 *) &D_8012B7F0)[0]); (u32)it < end; it += 2)
  {
    for (i = 0; i < it[0]; i++)
    {
      func_800D56C4(it[1]);
    }
  }
  vector_clear(((s32 *) &D_8012B7F0)[0]);
}

int func_800D5688()
{
  D_8012B7F0 = vector_defrag(((int) D_8012B7F0));
  D_8012B7F4 = vector_defrag(*((((int *) &D_8012B7F0)) + 1));
}

s32 func_800D56C4(param_0) void * param_0;
{
    s32 local_0;
    u8 local_1;
    if (param_0) {
        for (local_0 = 0; local_0 < D_8012B7E4 && param_0 != D_8012B450[local_0]; local_0++) {}
        if (local_0 == D_8012B7E4) return 2;
        D_8012B7E5 = local_0;
        if (D_8012B658[local_0] == 1) {
            heap_free(param_0);
            local_1 = D_8012B7E4 - 1;
            D_8012B7E4 = local_1;
            D_8012B658[local_0] = D_8012B658[local_1];
            D_8012B450[local_0] = D_8012B450[D_8012B7E4];
            D_8012B6E0[local_0] = D_8012B6E0[D_8012B7E4];
            return 0;
        } else {
            D_8012B658[local_0]--;
            return 1;
        }
    }
    return 3;
}

s32 func_800D5804(s32 param_0, s32 *param_1)
{
  s32 var_v1;
  s32 sp1C;
  s32 temp_v0;
  s32 *new_var;
  var_v1 = 0;
  new_var = ((s32 *) D_8012B450);
  if (((s32) D_8012B7E4) > 0)
  {
    if (param_0 != (*new_var))
    {
      loop_2:
      var_v1 += 1;

      if (var_v1 < ((s32) D_8012B7E4))
      {
        if (param_0 != (((s32 *) D_8012B450))[var_v1])
        {
          goto loop_2;
        }
      }
    }
  }
  if (var_v1 == D_8012B7E4)
  {
    return param_0;
  }
  sp1C = var_v1;
  temp_v0 = defrag(param_0);
  if (temp_v0 != param_0)
  {
    (((s32 *) D_8012B450))[sp1C] = temp_v0;
  }
  return temp_v0;
}

void func_800D58AC()
{
    func_800D5688();
}

int func_800D58CC()
{
  func_8001A2B0();
  func_800D55DC();
  func_800D55DC();
}

s32 func_800D58FC(s32 param_0)
{
  s32 new_var;
  new_var = param_0;
  rom_read_word(((long) D_8011B900) + (new_var * 4), ((s32 *) &D_8012B440.raw));
  return ((s32) D_8012B440.raw) & 0xF;
}

s32 func_800D593C() 
{
    return 0x3666;
}

s32 func_800D5944()
{
    return D_8012B7E8;
}

s32 func_800D5950(s32 param_0) {
    rom_read_word((u32) D_8011B900 + param_0 * 4, &D_8012B440.raw);
    rom_read_word((u32) D_8011B900 + param_0 * 4 + 4, &D_8012B444);
    return ((u32) D_8012B444 >> 6) - ((u32) D_8012B440.raw >> 6);
}

s32 func_800D59C0(s32 param_0)
{
  s32 *new_var;
  new_var = &D_8011B900;
  rom_read_word((*new_var) + (param_0 * 4), ((s32 *) &D_8012B440.raw));
  return (((u32) (((s32) D_8012B440.raw) << 0x1A)) >> 0x1E) & 1;
}

s32 func_800D5A04(s32 param_0) {
    s32 idx;

    idx = 0;
    if (((s32) D_8012B7E4 > 0) && (param_0 != ((s16 *) D_8012B6E0)[idx])) {
loop_2:
        idx += 1;
        if (idx < (s32) D_8012B7E4) {
            if (param_0 != ((s16 *) D_8012B6E0)[idx]) {
                goto loop_2;
            }
        }
    }
    if (idx < (s32) D_8012B7E4) {
        return 1;
    }
    return 0;
}

s32 func_800D5A6C(s32 param_0)
{
  int new_var;
  s32 *new_var2;
  new_var2 = &D_8011B900;
  new_var = (*new_var2) + (param_0 * 4);
  rom_read_word(new_var, &D_8012B440.raw);
  return D_8012B448 + (((u32) D_8012B440.raw) >> 6);
}

s32 func_800D5AB4(unsigned int param_0)
{
  s32 i;
  s16 *new_var;
  s32 new_var2;
  new_var = &D_8012B6E0[0];
  new_var2 = 0;
  if ((((s32) D_8012B7E4) > 0) && (param_0 != (*new_var)))
  {
    do
    {
      new_var2 += 1;
      if (new_var2 < ((s32) D_8012B7E4))
      {
        if (param_0 != D_8012B6E0[new_var2])
        {
          continue;
        }
      }
      break;
    }
    while (1);
  }
  D_8012B7E5 = new_var2;
  if (new_var2 == 0x82)
  {
    return -1;
  }
  return new_var2;
}

void func_800D5B24()
{
  D_8012B7E6 = 1;
}

void *func_800D5B34(s32 param_0) {
    s32 local_0;
    s32 local_1;
    void *local_2;
    s32 local_3;
    local_3 = D_8012B7E6;
    D_8012B7E6 = 0;
    local_1 = func_800D5AB4(param_0);
    if (local_1 < 0) return 0;
    if (local_1 < D_8012B7E4) {
        D_8012B658[local_1]++;
        return D_8012B450[local_1];
    }
    local_1 = param_0 * 4;
    rom_read_word(D_8011B900 + local_1, ((AssetD5B34 *) &D_8012B440.raw));
    if (!D_8012B440.AssetD5B34.local_2 && !local_3) local_3 = 2;
    if (func_800E4AF0(param_0)) {
        local_2 = func_800E4BF4(param_0);
    } else if (D_8012B440.AssetD5B34.local_2 == 10) {
        local_2 = _gldbDll_entrypoint_0(param_0, &D_8012B7E8);
    } else if (D_8012B440.AssetD5B34.local_1 & 1) {
        local_2 = func_800E6950(param_0, local_3, 0);
    } else {
        rom_read_word(D_8011B900 + local_1 + 4, ((AssetD5B34 *) &D_8012B444));
        rom_read_word(D_8011B900 + local_1, ((AssetD5B34 *) &D_8012B440.raw));
        local_0 = (*((AssetD5B34 *) &D_8012B444)).local_0 - D_8012B440.AssetD5B34.local_0;
        D_8012B7E8 = local_0;
        if (local_0 & 1) local_0++;
        local_2 = heap_alloc(local_0);
        rom_dma_read(local_2, D_8012B448 + D_8012B440.AssetD5B34.local_0, local_0);
    }
    D_8012B7E5 = D_8012B7E4;
    D_8012B658[D_8012B7E4] = 1;
    D_8012B450[D_8012B7E4] = local_2;
    D_8012B6E0[D_8012B7E4] = param_0;
    D_8012B7E4++;
    return local_2;
}

void func_800D5D70()
{
  long long new_var3;
  u8 *new_var2;
  u8 *new_var;
  D_8012B7E6 = 0;
  new_var2 = (u8 *) assets_ROM_START;
  func_800D55A0();
  D_8012B7E4 = 0;
  new_var3 = 0xD9A4;
  new_var = new_var2;
  ((void *) D_8012B448) = (void *) (new_var + new_var3);
  func_800E4CE8();
 if (0) { }
}

s32 func_800D5DB8(s32 param_0) {
    rom_read_word((u32) D_8011B900 + param_0 * 4, &D_8012B440.raw);
    rom_read_word((u32) D_8011B900 + param_0 * 4 + 4, &D_8012B444);
    return ((u32) D_8012B444 >> 6) - ((u32) D_8012B440.raw >> 6);
}

int func_800D5E28(s32 *param_0)
{
  s32 local_0;
  local_0 = *param_0;
  func_800D5440(local_0);
  param_0[0] = 0;
}

void func_800D5E54()
{
    func_800D5440();
}

void func_800D5E74(void) 
{
    func_800D55DC();
}

void func_800D5E94()
{
    func_800D54F0();
}

s32 func_800D5EB4(s32 param_0, void *param_1, s32 param_2)
{
    s32 local_1;
    s32 local_2;
    s32 local_0;
    if (func_800D5AB4(param_0) < 0) return 0;
    local_0 = param_0 * 4;
    rom_read_word(D_8011B900 + local_0, ((LocalRomEntry *) &D_8012B440.raw));
    if (D_8012B440.LocalRomEntry.flags & 1) {
        func_800E6950(param_0, 0, param_1);
        local_0 = D_8012B7E8;
    } else {
        rom_read_word(D_8011B900 + local_0 + 4, ((LocalRomEntry *) &D_8012B444));
        local_1 = (*((LocalRomEntry *) &D_8012B444)).offset - D_8012B440.LocalRomEntry.offset;
        if (local_1 & 1) local_1++;
        local_2 = local_1 & 0xF;
        local_0 = local_1;
        if (local_2) local_0 = local_1 - local_2 + 0x10;
        if (param_2 >= local_1) rom_dma_read(param_1, D_8012B440.LocalRomEntry.offset + ((u32) D_8012B448), local_1);
        else return 0;
    }
    return local_0;
}

int func_800D5FDC(s32 param_0)
{
  D_8012B7E8 = param_0;
}

s32 func_800D5FE8(s32 param_0) {
    s32 i;
    s32 count;
    count = D_8012B7E4;
    i = 0;
    while (i < count && param_0 != D_8012B6E0[i]) {
        i++;
    }
    if (i >= count) {
        return 0;
    }
    return ((s32 *) D_8012B450)[i];
}
