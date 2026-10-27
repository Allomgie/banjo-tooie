#include "common.h"

typedef struct { s32 (*length)(void); void *read, *write; } GameDataLength1446;
extern GameDataLength1446 D_808004F0_glgamedata[];
extern GameDataLength1446 D_80800544_glgamedata[];
typedef struct GameDataCodec1627 { s32 (*local_0)(void); /* Groessenfunktion: alle Tabelleneintraege (func_800DAFC4, func_800D1C70, ...) nehmen KEINE Argumente */ void (*local_1)(u8 *); void (*local_2)(u8 *, s32, u8, s32 *); } GameDataCodec1627;
typedef struct { void (*local_0)(u8 *, s32); s32 local_1; s32 local_2; } GameDataRecord60;
extern GameDataRecord60 D_808004F4_glgamedata[];
typedef struct { s32 (*func)(void); u8 pad4[8]; } GameDataCheck;
int glgamedata_entrypoint_6();

s32 func_80800000_glgamedata() 
{
    return 0x2;
}

s32 func_80800008_glgamedata(u8 *param_0){
    *param_0 = 0x1E;
}

void glgamedata_entrypoint_0(void)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 4;
    for (local_2 = 0; local_2 < 7; local_2++) {
        local_1 = 0;
        if (D_808004F0_glgamedata[local_2].length) {
            local_1 = D_808004F0_glgamedata[local_2].length();
        } else {
            local_1 = 0;
        }
        local_0 += local_1;
        local_0 += 2;
    }
}

s32 func_80800084_glgamedata(u32 *param_0){
    *param_0 = 0x4B484A43;
    return 4;
}

void func_80800098_glgamedata(void *param_0, s32 *param_1, u8 param_2)
{
    s32 local_0;
    u8 *local_1;

    if (((GameDataCodec1627 *) D_808004F0_glgamedata)[param_2].local_0) {
        local_0 = ((GameDataCodec1627 *) D_808004F0_glgamedata)[param_2].local_0();
    } else {
        local_0 = 0;
    }
    local_1 = (u8 *)param_0 + *param_1;
    local_1[0] = param_2;
    local_1[1] = local_0;
    local_1 += 2;
    if (((GameDataCodec1627 *) D_808004F0_glgamedata)[param_2].local_2) {
        ((GameDataCodec1627 *) D_808004F0_glgamedata)[param_2].local_2(local_1, local_0, param_2, param_1);
    }
    *param_1 += local_0 + 2;
}

void glgamedata_entrypoint_1(void *param_0)
{
    s32 local_1;
    s32 local_0 = 0;
    glgamedata_entrypoint_6(param_0);
    local_0 = func_80800084_glgamedata(param_0);
    for (local_1 = 1; local_1 < 7; local_1++) func_80800098_glgamedata(param_0, &local_0, (u8)local_1);
    func_80800098_glgamedata(param_0, &local_0, 0);
    _glcrc_entrypoint_0(param_0, 0x1C0);
}

s32 func_808001E4_glgamedata(s32 param_0){
    return 4;
}

s32 func_808001F0_glgamedata(u8 *param_0, s32 *param_1)
{
    s32 local_2;
    u8 *local_0;
    u8 local_1;
    void (*local_3)(u8 *, s32);

    local_0 = param_0 + *param_1;
    local_1 = local_0[0];
    local_2 = local_0[1];
    local_0 += 2;
    local_3 = D_808004F4_glgamedata[local_1].local_0;
    if (local_3 != NULL) {
        local_3(local_0, local_2);
    }
    *param_1 += local_2 + 2;
    return local_1;
}

s32 glgamedata_entrypoint_2(enum file_e file_id) {
    u32 local_0;
    int out;

    local_0 = func_808001E4_glgamedata(file_id);
    while (func_808001F0_glgamedata(file_id, &local_0) != 0);
}

s32 func_808002CC_glgamedata(param_0) void *param_0;
{
    s32 *ptr = (s32 *) param_0;
    return (*ptr == 0x4B484A43) ? 4 : 0;
}

s32 glgamedata_entrypoint_3(u8 *param_0, u8 param_1, s32 *param_2, s32 *param_3)
{
    u8 *local_0;
    u8 local_1;

    *param_2 = func_808002CC_glgamedata(param_0);
    if (*param_2 == 0) {
        return 0;
    }
    do {
        local_0 = param_0 + *param_2;
        local_1 = *local_0++;
        *param_3 = *local_0;
        *param_2 += 2;
        if (local_1 == param_1) {
            return 1;
        }
        *param_2 += *param_3;
    } while (local_1 != 0);
    return 0;
}

int glgamedata_entrypoint_4(u8 *param_0)
{
  u32 local_0;
  u32 local_1;
  if (glgamedata_entrypoint_3(param_0, 1, &local_0, &local_1))
  {
    return param_0[local_0] == 0x1E;
  }
  else
  {
    return 0;
  }
}

s32 glgamedata_entrypoint_5(u8 *param_0)
{
    s32 local_0;
    u8 local_1;
    s32 local_2;
    u8 *local_3;
    s32 (*local_4)(void);

    local_0 = func_808002CC_glgamedata();
    if (local_0 == 0) {
        return 2;
    }
    do {
        local_1 = param_0[local_0];
        local_3 = param_0 + local_0 + 1;
        if (local_1 >= 7) {
            return 2;
        }
        if (((GameDataCheck *) D_808004F0_glgamedata)[local_1].func != NULL) {
            local_2 = ((GameDataCheck *) D_808004F0_glgamedata)[local_1].func();
        } else {
            local_2 = 0;
        }
        if (local_2 != *local_3) {
            return 1;
        }
        local_0 += *local_3 + 2;
    } while (local_1 != 0);
    return 0;
}

int glgamedata_entrypoint_6(param_0) u8 *param_0;
{
  u32 local_0;
  for (local_0 = 0; local_0 < 0x1C0; local_0++)
  {
    param_0[local_0] = 0;
  }

}
