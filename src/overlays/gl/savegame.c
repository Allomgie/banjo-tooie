#include "common.h"

#define SAVE_GAME_BUFFERS_DEFINED
extern s8 D_80127618[];
extern void aligned4_memcpy(s32, s32, s32);
extern void heap_free(void *);
typedef struct { s32 unused; void *buffers[3]; s32 unused10; u8 enabled; } SaveGameBuffers_glsavegame_entrypoint_1;
extern u8 D_80127614[];
typedef struct { s32 unused; void *buffers[3]; s32 unused10; u8 enabled; } SaveGameBuffers_glsavegame_entrypoint_7;
extern void _glgamedata_entrypoint_2(s32);
typedef struct { void *buffers[3]; s32 unused10; u8 enabled; } SaveGameBuffers_glsavegame_entrypoint_9;
extern void _glgamedata_entrypoint_6();

int func_80800000_glsavegame()
{
    heap_alloc(0x1C0);
}

s32 func_80800020_glsavegame(s32 param_0, s32 param_1) {
    s32 i;
    s32 ret;

    for (i = 3; i != 0; i--) {
        ret = _glgamestore_entrypoint_0(param_0, param_1);
        if (ret == 0) {
            break;
        }
    }
    if (ret == 0) {
        if (_glgamedata_entrypoint_5(param_1) == 2) {
            ret = 3;
        }
    }
    if (ret == 0) {
        if (_glgamedata_entrypoint_4(param_1) == 0) {
            ret = 3;
        }
    }
    if (ret != 0) {
        _glgamedata_entrypoint_6(param_1);
    }
    return ret;
}

int func_808000CC_glsavegame(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  if (_glgamedata_entrypoint_3(param_0, 2, &local_0, &local_1))
  {
    return *(u8 *) (param_0 + local_0) - 1;
  }
  return -1;
}

s32 glsavegame_entrypoint_0(void)
{
    s32 local_1;
    s32 local_2;
    u32 local_0[4];
    s32 local_3;
    s32 local_4;
    D_80127618[0x12] = -1;
    D_80127618[0xF] = -1;
    local_0[3] = 0;
    for (local_1 = 0; local_1 < 3; local_1++) {
        D_80127618[local_1 + 0xC] = -1;
        local_0[local_1] = 0;
        ((s32 *)D_80127618)[local_1] = func_80800000_glsavegame();
        _glgamedata_entrypoint_6(((s32 *)D_80127618)[local_1]);
    }
    local_4 = func_80800000_glsavegame();
    for (local_1 = 0; local_1 != 4; local_1++) {
        local_3 = func_80800020_glsavegame(local_1, local_4);
        if (!local_3) {
            local_2 = func_808000CC_glsavegame(local_4);
            if (D_80127618[local_2 + 0xC] == -1) {
                D_80127618[local_2 + 0xC] = local_1;
                local_0[local_1] = 1;
                aligned4_memcpy(((s32 *)D_80127618)[local_2], local_4, 0x1C0);
            } else {
                local_3 = 2;
            }
        }
        if (local_3) {
            D_80127618[0xF] = local_1;
        }
    }
    heap_free(local_4);
    local_0[D_80127618[0xF]] = 1;
    for (local_2 = 0; local_2 < 3; local_2++) {
        for (local_1 = 0; local_1 < 4 && D_80127618[local_2 + 0xC] == -1; local_1++) {
            if (!local_0[local_1]) {
                local_0[local_1] = 1;
                D_80127618[local_2 + 0xC] = local_1;
            }
        }
    }
    D_80127618[0x10] = 1;
    D_80127618[0x11] = 1;
    return 1;
}

s32 func_808002E0_glsavegame(s32 param_0, s32 param_1)
{
  s32 local_0;
  s32 new_var;
  s32 local_1;
  s32 new_var2;
  s32 local_2;
  local_2 = 3;
  local_0 = func_80800000_glsavegame(param_0, param_1);
  new_var = param_0;
  new_var2 = new_var;
  loop_1:
  local_1 = _glgamestore_entrypoint_2(new_var2, param_1);

  if (local_1 == 0)
  {
    func_80800020_glsavegame(new_var2, local_0);
  }
  local_2 -= 1;
  if ((local_1 != 0) && (local_2 != 0))
  {
 do { } while (0);
    goto loop_1;
  }
  heap_free(local_0);
  return local_1;
}

int func_8080036C_glsavegame(s32 param_0)
{
  s32 local_0;
  s32 i;
  for (i = 3; i != 0; i--)
  {
    local_0 = _glgamestore_entrypoint_4(param_0);
    if (local_0 == 0)
    {
      break;
    }
  }
  return local_0;
}

void glsavegame_entrypoint_1(void)
{
    void **local_0;
    void **local_1;

    for (local_0 = (*((SaveGameBuffers_glsavegame_entrypoint_1 *) D_80127614)).buffers, local_1 = (*((SaveGameBuffers_glsavegame_entrypoint_1 *) D_80127614)).buffers + 3;
         local_0 != local_1; local_0++) {
        if (*local_0 != NULL) {
            heap_free(*local_0);
            *local_0 = NULL;
        }
    }
    (*((SaveGameBuffers_glsavegame_entrypoint_1 *) D_80127614)).enabled = 0;
}

s32 glsavegame_entrypoint_2(s32 param_0) {
    return **((u8 **)(D_80127614 + 4 + param_0 * 4)) != 0;
}

s32 glsavegame_entrypoint_3(void) {
    s32 i;
    for(i = 0; i < 3; i++){
        if(glsavegame_entrypoint_2(i)){
            return TRUE;
        }
    }
    return FALSE;
}

int glsavegame_entrypoint_4(s32 param_0)
{
  return ((s32 *) D_80127614)[(param_0) + 1];
}

s32 glsavegame_entrypoint_5() 
{
    return 0x1;
}

void glsavegame_entrypoint_6(s8 *param_0)
{
    *param_0 = ((s8 *) D_80127614)[0x16] + 1;
}

void func_808004B8_glsavegame(int param_0)
{
  D_80127614[0x16] = param_0;
}

int func_808004C4_glsavegame()
{
  s8 *local_0 = ((s8 *) D_80127614);
  local_0[0x16] = -1;
}

s32 glsavegame_entrypoint_7(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    void *local_3;
    local_3 = func_80800000_glsavegame();

    local_1 = ((s8 *)D_80127618 + param_0)[0xC];
    local_2 = ((s8 *)D_80127618)[0xF];
    func_808004B8_glsavegame(param_0);
    _glgamedata_entrypoint_1(local_3);
    func_808004C4_glsavegame();
    local_0 = func_808002E0_glsavegame(local_2, local_3);
    if (!local_0) local_0 = func_8080036C_glsavegame(local_1);
    if (!local_0) {
        ((s8 *)D_80127618 + param_0)[0xC] = local_2;
        ((s8 *)D_80127614)[0x13] = local_1;
    }
    heap_free(local_3);
    return local_0;
}

s32 glsavegame_entrypoint_8(s32 param_0) {
    s32 local_0;
    s32 local_2;
    s32 local_1 = func_80800000_glsavegame(param_0);
    local_2 = ((s8 *) D_80127614)[param_0 + 0x10];
    local_0 = func_80800020_glsavegame(local_2, local_1);
    if (local_0 == 0) {
        _glgamedata_entrypoint_2(local_1);
    }
    heap_free(local_1);
    return local_0;
}

int glsavegame_entrypoint_9(s32 param_0)
{
    int local_2;
    s32 local_0;
    s32 local_1;

    local_0 = ((s8 *)(*((SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618)).buffers)[param_0 + 12];
    local_1 = ((s8 *)(*((SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618)).buffers)[15];
    local_2 = func_8080036C_glsavegame(local_0);
    if (local_2 == 0) {
        ((s8 *)(*((SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618)).buffers)[param_0 + 12] = local_1;
        ((s8 *)(*((SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618)).buffers)[15] = local_0;
        if ((*((SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618)).enabled) _glgamedata_entrypoint_6((*((SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618)).buffers[param_0]);
    }
    return local_2;
}

s32 glsavegame_entrypoint_10(s32 param_0, s32 param_1)
{
    s32 local_3;
    s32 local_5;
    s32 a;
    s32 b;
    s8 *p;
    local_3 = func_80800000_glsavegame();
    local_5 = D_80127618[param_1 + 0xC];
    p = D_80127618 + param_0;
    a = p[0xC];
    b = D_80127618[0xF];
    local_5 = func_80800020_glsavegame(local_5, local_3);
    _glgamedata_entrypoint_2(local_3);
    func_808004B8_glsavegame(param_0);
    _glgamedata_entrypoint_1(local_3);
    func_808004C4_glsavegame();
    if (local_5 == 0) {
        local_5 = func_808002E0_glsavegame(b, local_3);
    }
    if (local_5 == 0) {
        local_5 = func_8080036C_glsavegame(a);
    }
    if (local_5 == 0) {
        p[0xC] = b;
        D_80127618[0xF] = a;
        if (*(u8 *)&D_80127618[0x10] != 0) {
            aligned4_memcpy(((s32 *)D_80127618)[param_0], ((s32 *)D_80127618)[param_1], 0x1C0);
        }
    }
    heap_free(local_3);
    return local_5;
}
