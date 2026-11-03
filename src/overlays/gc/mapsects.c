#include "common.h"
#include "maps.h"

typedef struct { f32 local_0[3]; f32 local_1[3]; f32 local_2[3]; f32 local_3[3]; f32 local_4; f32 local_5; u8 local_6[8]; s16 local_7; s16 local_8; void *local_9; void *local_10; u32 local_11:1; u32 local_12:1; u32 local_13:1; u32 local_14:1; u32 local_15:1; u32 local_16:2; u32 local_17:1; u32 local_18:24; void *local_19; void *local_20; } MapSectionInit50;
typedef struct { u8 local_0[0x68]; MapSectionInit50 *local_1; u8 local_2[0xB]; u8 local_3; } MapSectionListInit50;
extern void *func_800BF704(void);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern f32 D_808029B0_gcmapsects[3];
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
typedef struct { u8 pad_0[0x44]; void *local_0; void *local_1; u8 pad_1[0xC]; } MapSectionTextures;
typedef struct { u8 pad_0[0x68]; MapSectionTextures *local_0; } MapSections;
typedef struct { u8 pad0[0x40]; u16 unk40; u16 unk42; u8 pad44[8]; u32 unk4C_31 : 1; u32 pad4C_30 : 1; u32 unk4C_29 : 1; u32 unk4C_28 : 1; u32 pad4C_0 : 28; s32 unk50[2]; } MapSect_808003F4_gcmapsects;
typedef struct { u8 pad0[0x68]; MapSect_808003F4_gcmapsects *sects; } MapSects;
extern s32 func_800D70F8(s32, s32);
extern s32 func_800D73CC();
extern s32 func_800D6CEC(s32);
extern s32 func_800E4AF0(s32);
extern void func_800E4BB8(s32);
extern void _idworldmake_entrypoint_2(s32);
extern void _glidmake_entrypoint_4(s32);
typedef struct { u8 pad_0[0x40]; /* passed to _glidmake_entrypoint_5 as 2nd arg (f32 * in its own match) */ u16 local_0[2]; u8 pad_1[0xC]; s32 local_1[2]; } CodexMapSectionRecord65;
typedef struct { u8 pad_0[0x68]; CodexMapSectionRecord65 *local_0; u8 pad_1[0x15]; u8 local_1; } CodexMapSectionContext65;
typedef struct { u8 pad_0[0x38]; u8 local_0[4]; u8 pad_1[0x1C]; } MapSectionNeighbors;
typedef struct { u8 pad_0[0x68]; MapSectionNeighbors *local_0; } MapSectionNeighborList;
extern void func_800D5B24();
typedef struct { u8 pad_0[0x4C]; u32 pad_1 : 3; u32 local_0 : 1; u32 pad_2 : 28; } MapSectionLoadedFlags1041;
typedef struct MapSectObject { u8 pad_0[0x40]; u16 local_0; u8 pad_1[10]; u32 local_1 : 1; u32 local_2 : 1; u32 local_3 : 1; u32 local_4 : 1; u32 pad_2 : 28; u8 pad_3[8]; } MapSectObject;
typedef struct MapSectCollection { u8 pad_0[0x68]; MapSectObject *local_0; u8 pad_1[11]; u8 local_1; } MapSectCollection;
typedef struct { u8 pad_0[0xC]; f32 first[3]; f32 second[3]; u8 pad_1[0x34]; } MapSectionBounds;
typedef struct { u8 pad_0[0x68]; MapSectionBounds *sections; u8 pad_1[0xB]; u8 count; } MapSectionBoundsList;
extern s32 func_800EFFB4(f32 *, f32, f32 *);
typedef struct Mass43CullSection { u8 pad_0[0xC]; f32 local_0[3]; f32 local_1[3]; f32 local_2[3]; f32 local_3; u8 pad_1[4]; u8 local_4[4]; u8 pad_2[0x10]; u32 local_5 : 1; u32 local_6 : 1; u32 local_7 : 1; u32 pad_3 : 1; u32 local_8 : 1; u32 pad_4 : 2; u32 local_9 : 1; u32 pad_5 : 24; u8 pad_6[8]; } Mass43CullSection;
typedef struct Mass43MapObject { u8 pad_0[0x68]; Mass43CullSection *local_0; u8 pad_1[0xF]; u8 local_1; u8 pad_2[2]; u8 local_2; } Mass43MapObject;
extern s32 func_800E3E8C(f32 *, f32);
typedef struct MapSectionSearchRecord_gcmapsects_entrypoint_6 { u8 pad_0[12]; f32 local_0[3]; f32 local_1[3]; f32 local_2[3]; f32 local_3; f32 local_4; u8 pad_1[0x20]; } MapSectionSearchRecord_gcmapsects_entrypoint_6;
typedef struct MapSectionSearchList { u8 pad_0[0x68]; MapSectionSearchRecord_gcmapsects_entrypoint_6 *local_0; u8 pad_1[8]; s16 local_1; u8 pad_2; u8 local_2; } MapSectionSearchList;
extern s32 func_800EFED0(f32 *, f32 *, f32 *);
typedef struct Mass43CullObject { u8 pad_0[0x68]; Mass43CullSection *local_0; u8 pad_1[0xF]; u8 local_1; u8 pad_2[2]; u8 local_2; } Mass43CullObject;
typedef struct MapSectionActivation { u8 pad_0[0x24]; f32 local_0[3]; f32 local_1; u8 pad_1[0x18]; u32 pad_2 : 1; u32 local_2 : 1; u32 local_3 : 1; u32 pad_3 : 29; u8 pad_4[8]; } MapSectionActivation;
typedef struct MapSectionActivationList { u8 pad_0[0x68]; MapSectionActivation *local_0; } MapSectionActivationList;
typedef struct { u8 pad_0[0x3C]; u8 local_0[4]; u8 pad_1[0xC]; u32 local_1 : 1; u32 local_2 : 1; u32 pad_2 : 30; u8 pad_3[8]; } MapSectionLinks;
typedef struct { u8 pad_0[0x68]; MapSectionLinks *local_0; } MapSectionState;
typedef struct MapSectionSearchRecord_gcmapsects_entrypoint_7 { u8 pad_0[12]; f32 local_0[3]; f32 local_1[3]; f32 local_2[3]; f32 local_3; u8 pad_1[0x24]; } MapSectionSearchRecord_gcmapsects_entrypoint_7;
extern void func_8008FE68(f32 *);
extern u32 func_800F54E4(void);
extern void func_800F4CC0(s32);
extern void func_800F4CEC(s32, s32);
typedef struct { u8 local_0[0x40]; u16 local_1; u8 local_2[0xA]; u32 local_3:1; u32 local_4:1; u32 local_5:1; u32 local_6:2; u32 local_7:1; u32 local_8:26; u8 local_9[8]; } MapSectionUpdate50;
typedef struct MapSectionListUpdate50 { u8 local_0[0x68]; MapSectionUpdate50 *local_1; void (*local_2)(struct MapSectionListUpdate50 *); u8 local_3[7]; u8 local_4; u8 local_5; u8 local_6; u8 local_7; u8 local_8; u8 local_9; u8 local_10; u8 local_11; u8 local_12; u8 local_13[3]; u8 local_14; } MapSectionListUpdate50;
extern MapId func_800EA05C(void);
extern void _gcmapsects_lagoontop_entrypoint_0(void);
extern void _gcmapsects_lagoonmid_entrypoint_0(void);
extern void _gcmapsects_lagoonbot_entrypoint_0(void);
typedef struct { u8 pad_0[0x4C]; u32 local_0 : 1; u32 local_1 : 1; u32 local_2 : 1; u32 pad_1 : 2; u32 local_3 : 1; u32 pad_2 : 26; u8 pad_3[8]; } MapSectorRecord1358;
typedef struct { u8 pad_0[0x68]; MapSectorRecord1358 *local_0; s32 local_1; f32 local_2; s16 local_3; u8 local_4; u8 local_5; u8 local_6; u8 local_7; u8 local_8; u8 local_9; u8 local_10; u8 local_11; u8 local_12; u8 local_13; u8 local_14; u8 local_15; u8 local_16; u8 local_17; } MapSectorManager1358;
typedef struct { u8 pad_0[0x40]; u16 local_0; u8 pad_1[2]; s32 local_2; u8 pad_5[4]; u32 local_3 : 1; u32 local_1 : 1; u32 pad_3 : 30; u8 pad_4[8]; } MapSectionRenderItem_gcmapsects_entrypoint_20;
typedef struct { u8 pad_0[0x68]; MapSectionRenderItem_gcmapsects_entrypoint_20 *local_0; u8 pad_1[0xB]; u8 local_1; } MapSectionRenderList;
extern void *func_800D674C(s32);
extern void *func_800B2720(void *);
extern void *func_800B2840(void *);
extern s32 func_800AD2C8(void *, void *, void *, void *, MapSectionRenderItem_gcmapsects_entrypoint_20 *, s32, s32, f32);
typedef struct MapSectCollisionQueryFlags { u32 pad_0 : 1; u32 local_0 : 1; u32 pad_1 : 30; } MapSectCollisionQueryFlags;
extern int func_800AD894(s32, s32, f32 *, f32 *, void *, f32 *, f32);
extern s32 func_800AB868(void *, void *, void *, s32, f32, void *, void *, void *, s32);
typedef struct { u8 pad_0[0x4C]; u32 pad_1 : 1; u32 local_0 : 1; u32 pad_2 : 30; } MapSectFlags;
typedef struct { u8 pad_0[0x4C]; u32 pad_1 : 1; u32 local_0 : 1; u32 pad_2 : 30; u8 pad_3[8]; } MapSection1864;
extern s32 func_800AC848(s32, s32, void *, s32, f32, s32, s32, f32, s32, s32, s32);
typedef struct { u8 pad_0[0x40]; u16 local_0; u8 pad_1[2]; s32 local_2; u8 pad_5[4]; u32 local_3 : 1; u32 local_1 : 1; u32 pad_3 : 30; u8 pad_4[8]; } MapSectionRenderItem_gcmapsects_entrypoint_26;
extern void func_800BEB58(void *);
extern void func_800D62E4(s32);
extern s32 func_800AD1AC(void *, void *, MapSectionRenderItem_gcmapsects_entrypoint_26 *, s32, f32, s32, f32, s32, s32);
typedef struct { u8 pad_0[0x40]; u16 local_0; u8 pad_1[2]; s32 local_2; u8 pad_5[4]; u32 local_3 : 1; u32 local_1 : 1; u32 pad_3 : 30; u8 pad_4[8]; } MapSectionRenderItem_gcmapsects_entrypoint_18;
extern void func_800BF774(void);
extern void func_800DF830(s32);
extern u8 func_800D731C(s32);
extern void func_800DF7E8(u8);
extern void func_800DF7DC(s32);
extern void func_800DF818(void *);
extern void func_800DF440(s32);
extern void func_800DF428(f32);
extern void func_800DF4B0(s32);
extern s32 func_800DE448(MapSectionRenderItem_gcmapsects_entrypoint_18 *, s32, f32, s32, void *);
typedef struct { f32 pos[3]; u8 padC[0x42 - 0xC]; u16 model; u8 pad44[4]; s32 unk48; u32 unk4C_31:1; u32 pad4C:31; u8 pad50[8]; } MapSect_gcmapsects_entrypoint_19;
typedef struct { u8 pad0[0x68]; MapSect_gcmapsects_entrypoint_19 *sects; u8 pad6C[0x77 - 0x6C]; u8 count; } MapSectsData;

void gcmapsects_entrypoint_0(s16 param_0, s16 param_1, f32 *param_2, f32 *param_3, f32 *param_4, f32 param_5)
{
    MapSectionListInit50 *local_0;
    s32 local_1;
    local_0 = func_800BF704();
    local_1 = local_0->local_3;
    func_800EE7F8(local_0->local_1[local_1].local_0, param_2);
    func_800EE7F8(local_0->local_1[local_1].local_1, param_3);
    func_800EE7F8(local_0->local_1[local_1].local_2, param_4);
    func_800EF3DC(local_0->local_1[local_1].local_1, D_808029B0_gcmapsects);
    func_800EF04C(local_0->local_1[local_1].local_2, D_808029B0_gcmapsects);
    func_800EE780(local_0->local_1[local_1].local_3, local_0->local_1[local_1].local_1, local_0->local_1[local_1].local_2);
    func_800EF334(local_0->local_1[local_1].local_3, 0.5f);
    local_0->local_1[local_1].local_4 = func_800EEAD4(local_0->local_1[local_1].local_3, local_0->local_1[local_1].local_1);
    local_0->local_1[local_1].local_7 = param_0;
    local_0->local_1[local_1].local_8 = param_1;
    local_0->local_1[local_1].local_6[0] = 255;
    local_0->local_1[local_1].local_6[1] = 255;
    local_0->local_1[local_1].local_6[2] = 255;
    local_0->local_1[local_1].local_6[3] = 255;
    local_0->local_1[local_1].local_6[4] = 255;
    local_0->local_1[local_1].local_6[5] = 255;
    local_0->local_1[local_1].local_6[6] = 255;
    local_0->local_1[local_1].local_6[7] = 255;
    local_0->local_1[local_1].local_11 = 0;
    local_0->local_1[local_1].local_12 = 0;
    local_0->local_1[local_1].local_13 = 0;
    local_0->local_1[local_1].local_14 = 0;
    local_0->local_1[local_1].local_15 = 1;
    local_0->local_1[local_1].local_17 = 1;
    local_0->local_1[local_1].local_9 = 0;
    local_0->local_1[local_1].local_10 = 0;
    local_0->local_1[local_1].local_5 = param_5;
    local_0->local_1[local_1].local_19 = 0;
    local_0->local_1[local_1].local_20 = 0;
    local_0->local_3++;
}

void func_80800250_gcmapsects(u8 *param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  u16 local_4;
  u16 local_5;
  u8 *local_6;
  local_1 = param_1 * 0x58;
  local_6 = (*((s32 *) (((s8 *) param_0) + 0x68))) + local_1;
  if ((*((s32 *) (((s8 *) local_6) + 0x44))) == 0)
  {
    local_4 = *((u16 *) (((s8 *) local_6) + 0x40));
    if (local_4 != 0)
    {
      local_2 = func_800D674C(local_4 & 0xFFFFFFFF);
      local_0 = local_2 ^ 0;
      if (func_800B27FC(local_2) != 0)
      {
        *((s32 *) (((s8 *) ((*((s32 *) (((s8 *) param_0) + 0x68))) + local_1)) + 0x44)) = _dbtex_entrypoint_0(func_800B27FC(local_0));
      }
      func_800D6CEC(*((u16 *) (((s8 *) ((*((s32 *) (((s8 *) param_0) + 0x68))) + local_1)) + 0x40)));
      local_6 = (*((s32 *) (((s8 *) param_0) + 0x68))) + local_1;
    }
  }
  if ((*((s32 *) (((s8 *) local_6) + 0x48))) == 0)
  {
    local_5 = *((u16 *) (((s8 *) local_6) + 0x42));
    if (local_5)
    {
      local_3 = func_800D674C(local_5);
      local_0 = local_3;
      if (func_800B27FC(local_3) != 0)
      {
        *((s32 *) (((s8 *) ((*((s32 *) (((s8 *) param_0) + 0x68))) + local_1)) + 0x48)) = _dbtex_entrypoint_0(func_800B27FC(local_0));
      }
      func_800D6CEC(*((u16 *) (((s8 *) ((*((s32 *) (((s8 *) param_0) + 0x68))) + local_1)) + 0x42)));
    }
  }
}

void func_8080035C_gcmapsects(MapSections *param_0, s32 param_1)
{
    if (param_0->local_0[param_1].local_0) {
        _dbtex_entrypoint_1(param_0->local_0[param_1].local_0);
        param_0->local_0[param_1].local_0 = NULL;
    }
    if (param_0->local_0[param_1].local_1) {
        _dbtex_entrypoint_1(param_0->local_0[param_1].local_1);
        param_0->local_0[param_1].local_1 = NULL;
    }
}

void func_808003F4_gcmapsects(MapSects *param_0, s32 param_1)
{
    s32 local_0;
    u16 local_1;

    param_0->sects[param_1].unk4C_29 = 0;
    param_0->sects[param_1].unk4C_31 = 0;
    if (param_0->sects[param_1].unk4C_28) {
        func_800D70F8(param_0->sects[param_1].unk40, 0);
        param_0->sects[param_1].unk4C_28 = 0;
    }
    if (func_800D73CC(param_0->sects[param_1].unk40)) {
        func_800D6CEC(param_0->sects[param_1].unk40);
    }
    local_1 = param_0->sects[param_1].unk42;
    if (local_1 && func_800D73CC(local_1)) {
        func_800D70F8(param_0->sects[param_1].unk42, 0);
        func_800D6CEC(param_0->sects[param_1].unk42);
    }
    if (func_800E4AF0(param_0->sects[param_1].unk40)) {
        func_800E4BB8(param_0->sects[param_1].unk40);
    }
    for (local_0 = 0; local_0 < 2; local_0++) {
        if (param_0->sects[param_1].unk50[local_0]) {
            _idworldmake_entrypoint_2(param_0->sects[param_1].unk50[local_0]);
            _glidmake_entrypoint_4(param_0->sects[param_1].unk50[local_0]);
            param_0->sects[param_1].unk50[local_0] = 0;
        }
    }
}

void func_808005D0_gcmapsects(CodexMapSectionContext65 *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    if (!param_2) {
        for (local_0 = 0; local_0 < 2; local_0++) {
            if (param_0->local_0[param_1].local_1[local_0]) {
                _idworldmake_entrypoint_2(param_0->local_0[param_1].local_1[local_0]);
                _glidmake_entrypoint_4(param_0->local_0[param_1].local_1[local_0]);
                param_0->local_0[param_1].local_1[local_0] = 0;
            }
        }
    } else {
        for (local_0 = 0; local_0 < 2; local_0++) {
            if (param_0->local_0[param_1].local_0[local_0] &&
                (param_0->local_1 & (1 << local_0)) &&
                !param_0->local_0[param_1].local_1[local_0]) {
                if (func_800B274C(local_0 ? func_800D674C(param_0->local_0[param_1].local_0[local_0]) : param_2)) {
                    param_0->local_0[param_1].local_1[local_0] = _glidmake_entrypoint_5(param_0->local_0[param_1].local_0[local_0], param_0->local_0[param_1].pad_0);
                } else {
                    param_0->local_0[param_1].local_1[local_0] = 0;
                }
                if (param_0->local_0[param_1].local_1[local_0]) {
                    _idworldmake_entrypoint_0(param_0->local_0[param_1].local_1[local_0], 2);
                }
            }
        }
        for (local_0 = 0; local_0 < 2; local_0++) {
            if (param_0->local_0[param_1].local_1[local_0]) {
                _glid_entrypoint_5(param_0->local_0[param_1].local_1[local_0],
                    func_800B2840(local_0 ? func_800D674C(param_0->local_0[param_1].local_0[1]) : param_2));
            }
        }
    }
}

void gcmapsects_entrypoint_1(param_0, param_1) s16 param_0; s32 param_1;
{
  int new_var2;
  u8 *temp_v1;
  s8 *new_var;
  new_var = ((s8 *) func_800BF704()) + 0x68;
  temp_v1 = (*((s32 *) new_var)) + (param_0 * 0x58);
  *((u8 *) (((s8 *) temp_v1) + 0x4C)) = (u8) (((*((u8 *) (((s8 *) temp_v1) + 0x4C))) & 0xFFF7) | ((new_var2 = (param_1 & 0xFFFFu) * 8) & 8));
}

void gcmapsects_entrypoint_2(param_0, param_1) s16 param_0; s32 param_1;
{
  short new_var2;
  int new_var;
  u8 *temp_v1;
  temp_v1 = (*((s32 *) (((s8 *) func_800BF704()) + 0x68))) + (param_0 * 0x58);
  new_var2 = 0xFFFFu;
  new_var = ((*((u8 *) (((s8 *) temp_v1) + 0x4C))) & 0xFFFFu) & new_var2;
  *((u8 *) (((s8 *) temp_v1) + 0x4C)) = (u8) ((param_1 & 1) | (((((((new_var & new_var2) & new_var2) & new_var2) & 0xFFFFu) & new_var2) & new_var2) & 0xFFFE));
}

void gcmapsects_entrypoint_3(param_0, param_1) s16 param_0; s16 param_1;
{
    MapSectionNeighborList *local_0;
    s32 local_1;

    local_0 = func_800BF704();
    for (local_1 = 0; local_1 < 4; local_1++) {
        if (local_0->local_0[param_0].local_0[local_1] == 0xFF) {
            local_0->local_0[param_0].local_0[local_1] = param_1;
            break;
        }
    }
    for (local_1 = 0; local_1 < 4; local_1++) {
        if (local_0->local_0[param_1].local_0[local_1] == 0xFF) {
            local_0->local_0[param_1].local_0[local_1] = param_0;
            break;
        }
    }
}

void func_80800A08_gcmapsects(u8 *param_0, s32 param_1)
{
    s32 local_0 = 0;
    s32 local_1;
    u8 *local_2;
    u16 local_3;
    while (local_0 < param_0[0x77]) {
        local_1 = local_0 * 88;
        local_2 = *(u8 **)(param_0 + 0x68) + local_1;
        if (((*(u32 *)(local_2 + 0x4C) << 2) >> 31) || param_1) {
            local_3 = *(u16 *)(local_2 + 0x40);
            if (local_3 && !func_800D73CC(local_3)) {
                func_800D5B24();
                func_800D674C(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_1 + 0x40));
                func_800D70F8(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_1 + 0x40), 1);
                ((MapSectionLoadedFlags1041 *)(*(u8 **)(param_0 + 0x68) + local_1))->local_0 = 1;
            }
            local_3 = *(u16 *)(*(u8 **)(param_0 + 0x68) + local_1 + 0x42);
            if (local_3 && !func_800D73CC(local_3)) {
                func_800D5B24();
                func_800D674C(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_1 + 0x42));
                func_800D70F8(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_1 + 0x42), 1);
            }
        }
        func_80800250_gcmapsects(param_0, local_0);
        local_0++;
    }
    if (!func_800DB9B0()) param_0[0x78] = 1;
}

void func_80800B58_gcmapsects(MapSectCollection *param_0)
{
    s32 local_0;

    for (local_0 = 0; local_0 < param_0->local_1; local_0++) {
        if (param_0->local_0[local_0].local_3 && !func_800D73CC(param_0->local_0[local_0].local_0)) {
            if (func_800E488C(param_0->local_0[local_0].local_0)) {
                func_800D674C(param_0->local_0[local_0].local_0);
                func_800D70F8(param_0->local_0[local_0].local_0, 1);
                param_0->local_0[local_0].local_4 = 1;
            } else {
                param_0->local_0[local_0].local_1 = 0;
                param_0->local_0[local_0].local_2 = 0;
            }
        }
    }
}

int func_80800C54_gcmapsects(u8 *param_0)
{
  s32 local_0;
  u8 *local_1 = param_0;
  for (local_0 = 0; local_0 < param_0[0x77]; local_0++)
  {
    func_808003F4_gcmapsects(local_1, local_0);
    func_8080035C_gcmapsects(local_1, local_0);
  }

}

s32 gcmapsects_entrypoint_4(f32 *param_0)
{
    MapSectionBoundsList *local_0;
    s32 local_1;
    local_0 = func_800BF704();
    if (!local_0->count) return -1;
    for (local_1 = 0; local_1 < local_0->count; local_1++) {
        if (func_800EFED0(local_0->sections[local_1].first, local_0->sections[local_1].second, param_0)) return local_1;
    }
    return -1;
}

u32 gcmapsects_entrypoint_5(s32 param_0) {
    u8 *local_0;

    if (param_0 == -1) {
        return 1U;
    }
    local_0 = func_800BF704();
    if ((*(u8 *)((s8 *)(local_0) + (0x77))) == 0) {
        return 1U;
    }
    return (u32) ((*(s32 *)((s8 *)(((*(s32 *)((s8 *)(local_0) + (0x68))) + (param_0 * 0x58))) + (0x4C))) * 2) >> 0x1F;
}

s32 func_80800DC8_gcmapsects(Mass43MapObject *param_0, s32 param_1, f32 *param_2)
{
    s32 local_0;
    
    if (func_800EFFB4(param_0->local_0[param_1].local_2, param_0->local_0[param_1].local_3, param_2) && func_800EFED0(param_0->local_0[param_1].local_0, param_0->local_0[param_1].local_1, param_2)) {
        param_0->local_0[param_1].local_5 = 1;
        param_0->local_0[param_1].local_7 = 1;
        param_0->local_0[param_1].local_6 = 1;
        if (param_0->local_0[param_1].local_8) param_0->local_1 = 1;
        if (param_0->local_0[param_1].local_9) param_0->local_2 = 1;
        for (local_0 = 0; local_0 < 4; local_0++) {
            if (param_0->local_0[param_1].local_4[local_0] == 0xFF) break;
            param_0->local_0[param_0->local_0[param_1].local_4[local_0]].local_5 = 1;
            param_0->local_0[param_0->local_0[param_1].local_4[local_0]].local_7 = 1;
        }
        return param_1;
    }
    return -1;
}

s32 gcmapsects_entrypoint_6(MapSectionSearchList *param_0, f32 *param_1, f32 *param_2)
{
    f32 k0 = -1.0f;
    s32 local_1;
    s32 flag;
    s32 idx;
    f32 best;
    f32 f;
    flag = 1;
    best = -1.0f;
    idx = param_0->local_1;
    if (idx != -1 && func_800EFED0(param_0->local_0[idx].local_0, param_0->local_0[idx].local_1, param_1)) {
        flag = 0;
        f = param_0->local_0[idx].local_4;
        if (k0 != f && (best < f || best == -1.0f)) {
            best = f;
        }
    }
    if (local_1) {} // PROBE: empty test; the counter is read before its initialisation, so its live range overlaps flag
    if (flag) {
        for (local_1 = 0; local_1 < param_0->local_2; local_1++) {
            if (func_800EFFB4(param_0->local_0[local_1].local_2, param_0->local_0[local_1].local_3, param_1) && func_800EFED0(param_0->local_0[local_1].local_0, param_0->local_0[local_1].local_1, param_1)) {
                f = param_0->local_0[local_1].local_4;
                if (k0 != f && (best < f || best == -1.0f)) {
                    best = f;
                }
            }
        }
    }
    if (best != -1.0f) {
        if (best - 2000.0f < param_1[1] && param_1[1] < best + 2000.0f) {
            return 0;
        }
        *param_2 = best;
        return 1;
    }
    return 0;
}

int func_80801174_gcmapsects(Mass43CullObject *param_0, s32 param_1)
{
    s32 local_0;
    if (param_0->local_0[param_1].local_5) return 1;
    if (func_800E3E8C(param_0->local_0[param_1].local_2, param_0->local_0[param_1].local_3) && func_800E3D0C(param_0->local_0[param_1].local_0, param_0->local_0[param_1].local_1)) {
        param_0->local_0[param_1].local_5 = 1;
        param_0->local_0[param_1].local_7 = 1;
        
        if (param_0->local_0[param_1].local_8) param_0->local_1 = 1;
        if (param_0->local_0[param_1].local_9) param_0->local_2 = 1;
        for (local_0 = 0; local_0 < 4; local_0++) {
            if (param_0->local_0[param_1].local_4[local_0] == 0xFF) break;
            param_0->local_0[param_0->local_0[param_1].local_4[local_0]].local_5 = 1;
            param_0->local_0[param_0->local_0[param_1].local_4[local_0]].local_7 = 1;
        }
        return 1;
    }
    return 0;
}

s32 func_80801320_gcmapsects(MapSectionActivationList *param_0, s32 param_1, f32 *param_2)
{
    if (param_0->local_0[param_1].local_2) {
        return 1;
    }
    if (func_800EFFB4(param_0->local_0[param_1].local_0,
        param_0->local_0[param_1].local_1, param_2)) {
        param_0->local_0[param_1].local_3 = 1;
        param_0->local_0[param_1].local_2 = 1;
        return 1;
    }
    return 0;
}

void func_808013C0_gcmapsects(MapSectionState *param_0, s32 param_1)
{
    s32 local_0;
    u8 local_1;
    if (param_0->local_0[param_1].local_2) {
        for (local_0 = 0; local_0 < 4; local_0++) {
            local_1 = param_0->local_0[param_1].local_0[local_0];
            if (local_1 == 0xFF) break;
            param_0->local_0[local_1].local_1 = 0;
        }
    }
}

s32 gcmapsects_entrypoint_7(f32 *param_0)
{
    MapSectionSearchList *local_0;
    s32 local_1;

    local_0 = func_800BF704();
    local_1 = local_0->local_1;
    if (local_1 != -1 && func_800EFED0(local_0->local_0[local_1].local_0, local_0->local_0[local_1].local_1, param_0)) {
        return local_1;
    }
    for (local_1 = 0; local_1 < local_0->local_2; local_1++) {
        if (func_800EFFB4(local_0->local_0[local_1].local_2, local_0->local_0[local_1].local_3, param_0) && func_800EFED0(local_0->local_0[local_1].local_0, local_0->local_0[local_1].local_1, param_0)) {
            return local_1;
        }
    }
    return -1;
}

s32 gcmapsects_entrypoint_8(Actor *this){
    this->unk78 = 0;
}

void func_80801554_gcmapsects(u8 *param_0)
{
    s32 local_0;
    f32 local_3[3];
    s32 local_1;
    s32 local_2;

    func_8008FE68(local_3);
    if (func_80090128()) {
        if (!param_0[0x80]) {
            local_1 = -1;
            for (local_0 = 0; local_0 < param_0[0x77]; local_0++) {
                local_2 = func_80800DC8_gcmapsects(param_0, local_0, local_3);
                if (local_2 != -1) {
                    local_1 = local_2;
                }
            }
            *(s16 *)(param_0 + 0x74) = local_1;
            param_0[0x82] = 1;
        } else {
            for (local_0 = 0; local_0 < param_0[0x77]; local_0++) {
                func_80801320_gcmapsects(param_0, local_0, local_3);
            }
        }
    }
}

void func_80801640_gcmapsects(param_0) u8 *param_0; {
    s32 var_s0;
    f32 sp30[3];
    s32 var_s0_2;

    func_800E3980(sp30);
    if ((*(u8 *)((char *)param_0 + 0x80)) == 0) {
        var_s0 = 0;
        if ((s32)*(u8 *)((char *)param_0 + 0x77) > 0) {
            do {
                func_80800DC8_gcmapsects(param_0, var_s0, sp30);
                var_s0 += 1;
            } while (var_s0 < (s32)*(u8 *)((char *)param_0 + 0x77));
        }
    } else {
        var_s0_2 = 0;
        if ((s32)*(u8 *)((char *)param_0 + 0x77) > 0) {
            do {
                func_80801174_gcmapsects(param_0, var_s0_2);
                func_80801320_gcmapsects(param_0, var_s0_2, sp30);
                var_s0_2 += 1;
            } while (var_s0_2 < (s32)*(u8 *)((char *)param_0 + 0x77));
            var_s0_2 = 0;
        }
        if ((s32)*(u8 *)((char *)param_0 + 0x77) > 0) {
            do {
                func_808013C0_gcmapsects(param_0, var_s0_2);
                var_s0_2 += 1;
            } while (var_s0_2 < (s32)*(u8 *)((char *)param_0 + 0x77));
        }
    }
}

void func_80801724_gcmapsects(u8 *param_0, s32 param_1)
{
    switch (param_0[0x7F]) {
        case 1:
            break;
        case 2:
            func_800F4CC0(func_800F54E4());
            break;
    }
    param_0[0x7F] = param_1;
    switch (param_0[0x7F]) {
        case 1:
            break;
        case 2:
            func_800F4CEC(func_800F54E4(), 0x77);
            break;
    }
}

void gcmapsects_entrypoint_9(MapSectionListUpdate50 *param_0)
{
    s32 local_0;
    param_0->local_8 = param_0->local_6;
    param_0->local_11 = param_0->local_10;
    for (local_0 = 0; local_0 < param_0->local_4; local_0++) {
        param_0->local_1[local_0].local_3 = 0;
        param_0->local_1[local_0].local_4 = 0;
        param_0->local_1[local_0].local_7 = param_0->local_1[local_0].local_5;
        param_0->local_1[local_0].local_5 = param_0->local_14;
    }
    switch (param_0->local_12) {
    case 1:
        if (func_800DB9B0()) func_80801724_gcmapsects(param_0, 2);
        break;
    case 2:
        if (!func_800DB9B0()) func_80801724_gcmapsects(param_0, 1);
        break;
    }
    switch (param_0->local_12) {
    case 1:
        func_80801554_gcmapsects(param_0);
        func_80801640_gcmapsects(param_0);
        break;
    case 2:
        param_0->local_5 = 0;
        break;
    }
    if (param_0->local_2) param_0->local_2(param_0);
    for (local_0 = 0; local_0 < param_0->local_4; local_0++) {
        if (!param_0->local_1[local_0].local_5) func_808003F4_gcmapsects(param_0, local_0);
    }
    if (!param_0->local_5) func_80800A08_gcmapsects(param_0, param_0->local_14);
    else func_80800B58_gcmapsects(param_0);
    for (local_0 = 0; local_0 < param_0->local_4; local_0++) {
        if (param_0->local_1[local_0].local_5)
            func_808005D0_gcmapsects(param_0, local_0, func_800D6B0C(param_0->local_1[local_0].local_1));
    }
}

void gcmapsects_entrypoint_10(s32 param_0) {
    u8 *temp_v0;
    u8 *sp1C;

    temp_v0 = func_800BF704();
    if (param_0 != 0) {
        (*(s8 *)((s8 *)(temp_v0) + (0x76))) = (s8) param_0;
        sp1C = temp_v0;
        (*(s32 *)((s8 *)(sp1C) + (0x68))) = heap_alloc((param_0 & 0xFF) * 0x58, param_0);
    }
}

void gcmapsects_entrypoint_11(void *param_0, s32 param_1)
{
    u8 *v0;
    v0 = func_800BF704();
    v0[0x79] = (s8) param_0;
    v0[0x7D] = (s8) param_1;
}

void gcmapsects_entrypoint_12(s32 param_0)
{
    *(s32 *)((char *)func_800BF704() + 0x6C) = param_0;
}

void gcmapsects_entrypoint_13(s32 param_0)
{
    s32 local_0;

    local_0 = func_800BF704();
    *(u8 *)(local_0 + 0x80) = param_0;
}

void gcmapsects_entrypoint_14(s32 arg0) {
    s8 *local_0 = func_800BF704();
    local_0[0x81] = (s8) arg0;
}

void gcmapsects_entrypoint_15(MapSectorManager1358 *param_0)
{
    s32 local_0;
    s32 local_1;

    param_0->local_0 = NULL;
    param_0->local_5 = 0;
    param_0->local_4 = 0;
    param_0->local_6 = 0;
    param_0->local_10 = 0;
    param_0->local_9 = 1;
    param_0->local_12 = 1;
    param_0->local_8 = 1;
    param_0->local_13 = 3;
    param_0->local_3 = -1;
    param_0->local_16 = 0;
    param_0->local_1 = 0;
    param_0->local_7 = 0;
    param_0->local_11 = 0;
    param_0->local_14 = 0;
    param_0->local_15 = 0;
    param_0->local_2 = 0.0f;
    local_1 = func_800EA05C();
    switch (local_1) {
    case 0x1A7:
        _gcmapsects_lagoontop_entrypoint_0();
        param_0->local_17 = 1;
        break;
    case 0x1A8:
        _gcmapsects_lagoonmid_entrypoint_0();
        param_0->local_17 = 1;
        break;
    case 0x1A9:
        _gcmapsects_lagoonbot_entrypoint_0();
        param_0->local_17 = 1;
        break;
    }
    if (param_0->local_5) {
        func_80801724_gcmapsects(param_0, 1);
    }
    for (local_0 = 0; local_0 < param_0->local_5; local_0++) {
        param_0->local_0[local_0].local_0 = 0;
        param_0->local_0[local_0].local_1 = 1;
        param_0->local_0[local_0].local_3 = param_0->local_0[local_0].local_2;
        param_0->local_0[local_0].local_2 = param_0->local_17;
    }
    func_80800A08_gcmapsects(param_0, param_0->local_17);
}

void gcmapsects_entrypoint_16(u8 *param_0)
{
    if (param_0[0x77] || param_0[0x76]) {
        func_80800C54_gcmapsects(param_0);
        heap_free(*(void **)(param_0 + 0x68));
        *(void **)(param_0 + 0x68) = NULL;
        param_0[0x77] = 0;
        param_0[0x76] = 0;
        param_0[0x78] = 0;
        param_0[0x7B] = 1;
        param_0[0x7E] = 1;
        param_0[0x7C] = 0;
        param_0[0x7F] = 3;
        *(f32 *)(param_0 + 0x70) = 0.0f;
    }
}

void gcmapsects_entrypoint_17(u8 *param_0)
{
  s8 *new_var;
  u8 local_0;
  func_80801640_gcmapsects();
  local_0 = *((u8 *) (((s8 *) param_0) + 0x7B));
  new_var = (s8 *) param_0;
  if ((*((u8 *) (((s8 *) param_0) + 0x7A))) != (*((u8 *) (((s8 *) param_0) + 0x7B))))
  {
    if ((*((u8 *) (((s8 *) param_0) + 0x7B))) != 0)
    {
      func_800BFF4C();
    }
    else
    {
      func_800BFF28();
    }
    *((u8 *) (((s8 *) param_0) + 0x7A)) = (u8) (*((u8 *) (((s8 *) param_0) + 0x7B)));
  }
  func_800BF4DC(1, *((u8 *) (new_var + 0x7E)), param_0);
}

void gcmapsects_entrypoint_18(MapSectionRenderList *param_0, s32 param_1)
{
    s32 local_0;
    void *local_1;
    void *local_2;
    s32 local_3;
    u8 local_4;

    for (local_0 = 0; local_0 < param_0->local_1; local_0++) {
        if (!param_0->local_0[local_0].local_3) {
            continue;
        }
        local_3 = param_0->local_0[local_0].local_0;
        if (!local_3) {
            continue;
        }
        local_1 = func_800D674C(local_3);
        if (!local_1) {
            continue;
        }
        local_2 = func_800B2840(local_1);
        func_800BF774();
        func_800DF830(1);
        local_4 = func_800D731C(local_3);
        if (local_4) {
            func_800DF7E8(local_4);
        }
        func_800DF7DC(param_0->local_0[local_0].local_2);
        func_800DF818(local_2);
        func_800DF440(0);
        func_800DF428(29999.0f);
        func_800DF4B0(2);
        if (!func_800DE448(&param_0->local_0[local_0], 0, 1.0f, 0, local_1)) {
            func_800D62E4(param_0->local_0[local_0].local_0);
        }
    }
}

void gcmapsects_entrypoint_19(MapSectsData *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    u16 local_3;

    for (local_0 = 0; local_0 < param_0->count; local_0++) {
        if (!param_0->sects[local_0].unk4C_31) {
            continue;
        }
        local_3 = param_0->sects[local_0].model;
        if (!local_3) {
            continue;
        }
        local_1 = func_800D674C(local_3);
        if (local_1 == 0) {
            continue;
        }
        local_2 = func_800B2840(local_1);
        func_800BF774();
        func_800DF830(2);
        func_800DF440(0);
        func_800DF428(29999.0f);
        func_800DF7DC(param_0->sects[local_0].unk48);
        func_800DF818(local_2);
        func_800DF4B0(2);
        if (!func_800DE448(&param_0->sects[local_0], 0, 1.0f, 0, local_1)) {
            func_800D62E4(param_0->sects[local_0].model);
        }
    }
}

s32 gcmapsects_entrypoint_20(MapSectionRenderList *param_0, void *param_1, void *param_2, s32 param_3, s32 param_4, f32 param_5)
{
    void *local_1;
    void *local_2;
    s32 local_0;

    for (local_0 = 0; local_0 < param_0->local_1; local_0++) {
        if (param_0->local_0[local_0].local_1) {
            local_1 = func_800D674C(param_0->local_0[local_0].local_0);
            local_2 = func_800B2720(local_1);
            return func_800AD2C8(local_2, func_800B2840(local_1), param_1, param_2,
                &param_0->local_0[local_0], param_3, param_4, param_5);
        }
    }
    return 0;
}

int gcmapsects_entrypoint_21(u8 *param_0, f32 *param_1, f32 *param_2, void *param_3, f32 param_4)
{
    s32 local_3;
    s32 local_4;
    int local_0;
    int local_1;
    u8 *local_5;
    int local_2;

    local_0 = param_0[0x77];
    local_1 = 0;
    local_2 = 0;
    if (local_0 > 0) {
        local_5 = *(u8 **)(param_0 + 0x68);
        do {
            if (((MapSectCollisionQueryFlags *)(local_5 + 0x4C))->local_0) {
                local_3 = func_800D674C(*(u16 *)(local_5 + 0x40));
                local_4 = func_800B2720(local_3);
                return func_800AD894(local_4, func_800B2840(local_3),
                    param_1, param_2, param_3, (f32 *)(*(u8 **)(param_0 + 0x68) + local_2), param_4);
            }
            local_1++;
            local_2 += 0x58;
            local_5 += 0x58;
        } while (local_1 < param_0[0x77]);
    }
    return 0;
}

s32 gcmapsects_entrypoint_22(u8 *param_0, void *param_1, void *param_2, void *param_3, s32 param_4)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    u8 *local_3;
    void *local_4;
    void *local_5;
    void *local_6;

    local_0 = 0;
    if (param_0[0x77] == 0) {
        return 0;
    }
    func_800BEB58(0);
    local_1 = 0;
    if (local_1 < param_0[0x77]) {
        local_2 = 0;
        do {
            local_3 = *(u8 **)(param_0 + 0x68) + local_2;
            if (((MapSectFlags *)local_3)->local_0) {
                local_4 = func_800D674C(*(u16 *)(local_3 + 0x40));
                if (local_4) {
                    func_800D62E4(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_2 + 0x40));
                    if ((param_4 & 0x1F00) == 0x1F00) {
                        local_0 = 0;
                    } else {
                        local_5 = func_800B2720(local_4);
                        local_0 = func_800AB868(local_5, (void *)func_800B2840(local_4), *(u8 **)(param_0 + 0x68) + local_2,
                            0, 1.0f, param_1, param_2, param_3, param_4);
                    }
                    if (local_0) {
                        func_800BEB58(local_4);
                        return local_0;
                    }
                    if (*(u16 *)(*(u8 **)(param_0 + 0x68) + local_2 + 0x42)) {
                        local_4 = func_800D674C(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_2 + 0x42));
                        func_800D62E4(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_2 + 0x42));
                        local_6 = func_800B2720(local_4);
                        if (local_6) {
                            local_0 = func_800AB868(local_6, func_800B2840(local_4), *(u8 **)(param_0 + 0x68) + local_2,
                                0, 1.0f, param_1, param_2, param_3, param_4);
                        }
                    }
                }
            }
            local_1++;
            local_2 += 0x58;
        } while (local_1 < param_0[0x77]);
    }
    return local_0;
}

s32 gcmapsects_entrypoint_23(u8 *param_0, s32 param_1, s32 param_2, f32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    s32 local_0;
    s32 local_1;
    void *local_2;
    s32 local_3;
    s32 local_4;
    u8 *local_5;
    local_3 = 0;
    if (param_0[0x77] == 0) return 0;
    func_800BEB58(0);
    for (local_4 = 0, local_0 = 0; local_4 < param_0[0x77]; local_4++, local_0 += 0x58) {
        local_5 = *(u8 **)(param_0 + 0x68) + local_0;
        if (((MapSection1864 *)local_5)->local_0) {
            local_2 = (void *)func_800D674C(*(u16 *)(local_5 + 0x40));
            if (local_2) {
                func_800D62E4(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_0 + 0x40));
                local_1 = func_800B2720(local_2);
                local_3 = func_800AC848(local_1, func_800B2840(local_2), *(u8 **)(param_0 + 0x68) + local_0, 0, 1.0f, param_1, param_2, param_3, param_4, param_5, param_6);
                if (local_3) {
                    func_800BEB58(local_2);
                    return local_3;
                }
            }
        }
    }
    return local_3;
}

s32 gcmapsects_entrypoint_24(u8 *param_0)
{
  s32 temp_t6;
  s32 var_v0;
  s8 *new_var;
  new_var = (s8 *) param_0;
  temp_t6 = (*((u8 *) (new_var + 0x82))) != 0;
  var_v0 = temp_t6;
  if (temp_t6 != 0)
  {
    ;
    return ((*((s16 *) (((s8 *) param_0) + 0x74))) + 1) == 0;
  }
}

int gcmapsects_entrypoint_25(u8 *param_0, u32 param_1, s32 param_2, s32 param_3, s32 param_4, u32 param_5)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    local_0 = 0;
    if (!param_0[0x77]) return 0;
    func_800BEB58(0);
    local_2 = param_1 * 0x58;
    local_1 = func_800D674C(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_2 + 0x40));
    if (1) {}
    if (local_1) {
        func_800D62E4(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_2 + 0x40));
        if ((param_5 & 0x1F00) != 0x1F00) {
            local_0 = func_800AB868(func_800B2720(local_1), func_800B2840(local_1), *(u8 **)(param_0 + 0x68) + local_2, 0, 1.0f, param_2, param_3, param_4, param_5);
        }
        if (local_0) func_800BEB58(local_1);
        else if (*(u16 *)(*(u8 **)(param_0 + 0x68) + local_2 + 0x42)) {
            local_1 = func_800D674C(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_2 + 0x42));
            func_800D62E4(*(u16 *)(*(u8 **)(param_0 + 0x68) + local_2 + 0x42));
            if (func_800B2720(local_1)) local_0 = func_800AB868(func_800B2720(local_1), func_800B2840(local_1), *(u8 **)(param_0 + 0x68) + local_2, 0, 1.0f, param_2, param_3, param_4, param_5);
        }
    }
    return local_0;
}

s32 gcmapsects_entrypoint_26(MapSectionRenderList *param_0, s32 param_1, f32 param_2, s32 param_3, s32 param_4)
{
    void *local_1;
    s32 local_2;
    s32 local_0;
    void *local_3;

    local_2 = 0;
    if (param_0->local_1 == 0) {
        return 0;
    }
    func_800BEB58(0);
    for (local_0 = 0; local_0 < param_0->local_1; local_0++) {
        if (param_0->local_0[local_0].local_1) {
            local_1 = func_800D674C(param_0->local_0[local_0].local_0);
            if (local_1) {
                func_800D62E4(param_0->local_0[local_0].local_0);
                local_3 = func_800B2720(local_1);
                local_2 = func_800AD1AC(local_3, func_800B2840(local_1), &param_0->local_0[local_0], 0, 1.0f, param_1, param_2, param_3, param_4);
                if (local_2) {
                    func_800BEB58(local_1);
                    return local_2;
                }
            }
        }
    }
    return local_2;
}

s32 gcmapsects_entrypoint_27(s32 param_0) {
    u8 *temp_v0;
    s32 temp_t7;

    temp_v0 = func_800BF704();
    if ((*(u8 *)((s8 *)(temp_v0) + (0x77))) == 0) {
        return 0;
    }
    temp_t7 = param_0 * 0x58;
    if (((u32) (*(u32 *)((s8 *)(((*(s32 *)((s8 *)(temp_v0) + (0x68))) + temp_t7)) + (0x4C))) >> 0x1F) != 0) {
        if (func_800D6B0C((*(u16 *)((s8 *)(((*(s32 *)((s8 *)(temp_v0) + (0x68))) + temp_t7)) + (0x40))), temp_v0) != 0) {
            func_800D62E4((*(u16 *)((s8 *)(((*(s32 *)((s8 *)(temp_v0) + (0x68))) + temp_t7)) + (0x40))));
            return 1;
        }
    }
    return 0;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gc/mapsects.data.s) is defined here in C.
 * Values are taken from the ROM. */
f32 D_808029B0_gcmapsects[3] = { 5e+01f, 5e+01f, 5e+01f };
static u32 D_808029B0_gcmapsects_rest[1] = { 0x0 };
