#include "core2/1EB5E70.h"
#include "types.h"


typedef struct { s32 pad[2]; s16 unk8; } Knoten_800DC634;
extern f32 D_8012CEAC;
extern f32 D_8012CEA8;
void func_800193C4(void *param_0, void *param_1);
void mlMtx_push_translation(f32 param_0, f32 param_1, f32 param_2);
void mlMtxRotYaw(f32 param_0);
void mlMtxRotPitch(f32 param_0);
void mlMtxTranslate(f32 param_0, f32 param_1, f32 param_2);
void mlMtxScale(f32 param_0);
void mlMtxPop(void);
typedef struct { s32 pad[2]; s16 unk8; } Knoten_800DC740;
typedef struct { s32 unk0; s32 unk4; s16 unk8; } Knoten_800DC84C;
extern s32 D_8012CE58;
extern s32 D_8012CE98;
extern f32 D_8012CEC8;
extern s32 D_8012CED0;
extern s32 D_8012CEE0;
extern s32 D_8012CEF0;
extern f32 D_8012CEFC;
extern s32 D_8012CF00;
extern s32 D_8012CF10;
extern s32 D_8012CF20;
extern f32 D_8012CF2C;
extern f32 D_8012CF30;
extern f32 D_8012CF40;
extern f32 D_8012CF50;
extern s32 D_8012C820;
typedef struct { s32 cmd_0; s32 size_4; u8 unk8; s8 unk9; } GeoCmd2;
extern void *D_8012C968;
void *func_800ADE2C(void *, s32);
void func_80019AA0(void *, void *);
void mlMtxApply();
typedef struct { s32 w0; s32 w1; } Gfx2;
typedef struct { s32 unk0; s32 unk4; Gfx2 list[1]; } GfxList;
extern GfxList *D_8012C960;
extern u32 osVirtualToPhysical();
typedef struct { f32 scale; s32 pad04[5]; GfxList *dlist; s32 pad1C; void *animList; } RenderCtx_800DD07C;
typedef struct { s32 cmd_0; s32 size_4; s16 unk8[1]; } GeoCmd5;
typedef struct { s32 pad[7]; s32 unk1C; } Knoten_800DD214;
extern s16 D_8012CA38;
extern s32 D_8012CF60;
extern u8 D_8012CF70[];
extern s32 D_8012CF80;
extern f32 func_800EEB40(s32 *, s32 *);
extern s32 D_8012C844;
void func_800DC028();
void func_800EFA20(f32 *, f32 *, f32);
extern f32 *D_8012C94C;
void func_800EF04C(f32 *, f32 *);
typedef struct { s32 cmd_0; s32 size_4; s16 unk8; s16 unkA; s32 unkC[]; } GeoCmdC;
typedef struct { s32 cmd_0; s32 size_4; s16 unk8[6]; s16 unk14[6]; s16 unk20[6]; s16 unk2C; s16 unk2E; } GeoCmdX;
typedef void (*D_8012CEC4_func_t)(void *, void *, s16);
extern D_8012CEC4_func_t D_8012CEC4;
void *mlMtx_get_stack_pointer(void);
void *func_80018BB4(void);
void func_8010F070();
typedef struct { f32 scale; s32 pad04[5]; GfxList *dlist; s32 pad1C; void *animList; } RenderCtx_800DDB38;
typedef struct { s32 pad[5]; s16 unk14; } Knoten_800DDC28;
typedef struct { s32 cmd_0; s32 size_4; s16 unk8[3]; s16 unkE; s16 unk10; s16 unk12; } GeoCmdE;
typedef struct { f32 scale; s32 pad04[7]; void *animList; } RenderCtx_800DDDC4;
void func_800EE88C();
void func_800EF334(f32 *, f32);
s32 func_800E3E8C(f32 *, f32);
void func_80019224(f32 *, f32 *);
extern int D_8012C970;
typedef struct { f32 scale; s32 pad04[5]; GfxList *dlist; s32 pad1C; void *animList; } RenderCtx_800DE0D8;
typedef union {
    RenderCtx_800DD07C RenderCtx_800DD07C;
    RenderCtx_800DDB38 RenderCtx_800DDB38;
    RenderCtx_800DDDC4 RenderCtx_800DDDC4;
    RenderCtx_800DE0D8 RenderCtx_800DE0D8;
    f32 raw;
} Union_D_8012C948;
extern Union_D_8012C948 D_8012C948;
typedef struct { s16 unk0; s16 unk2; } Eintrag;
typedef struct { s32 cmd_0; s32 size_4; s16 unk8; s16 unkA; Eintrag unkC[1]; } GeoCmdB;
typedef struct { s32 cmd_0; s32 size_4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } GeoCmdY;
struct SomeStruct { s32 unk0; s32 unk4; };
extern s32 D_8012C828;
extern s32 D_8012C834;
extern s32 D_8012C838;
extern s32 D_8012C83C;
extern s32 D_8012C848;
extern s32 (*D_8012C9A8)(s32);
extern s32 D_8012C9B8;
extern s32 D_8012CA18;
extern s32 D_8012CA28;
extern void (**D_8012CF8C)(s32, void *);
extern void func_80018C50(void *);
extern f32 func_800EEF94(f32 *);
extern f32 mlAbsF(f32);
extern void mlMtxGet(void *);
extern void mlMtxRotatePYR(f32, f32, f32);
extern void mlMtxScale_xyz(f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800E42C0(void);
extern void func_80013C80(void *, void *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_80019750(f32 *, f32 *, f32, f32 *);
extern void _dbzone_entrypoint_1(void *, void *, f32, f32 *);
extern s32 D_80122DB0;
extern s32 D_80122DC8;
extern s32 D_80122DCC;
extern s32 D_80122DF0;
extern s32 D_80122EB0;
extern s32 D_80122F70;
extern s32 D_80123030;
extern s32 D_80123038;
extern s32 D_8012C840;
extern s32 D_8012C9A4;
extern s32 D_8012C9AC;
extern s32 (*D_8012C9B0)(s32);
extern s32 D_8012C9B4;
extern s32 D_8012C9BC;
extern s32 D_8012C9C8;
extern s32 D_8012CA0C;
extern u8 D_8012CA11;
extern f32 D_8012CA1C;
extern f32 D_8012CA20;
extern s32 D_8012CA40[];
extern u8 *D_8012CE40;
extern u8 *D_8012CE44;
extern f32 D_8012CEB8[3];
typedef struct { s32 unk0; s32 unk4; s16 texture_list_offset_8; s16 geo_typ_A; s32 gfx_list_offset_C; s32 vtx_list_offset_10; s32 unk14; s32 animation_list_offset_18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; } ModelBinHeader;
typedef struct { s32 m[16]; } FixedMatrixWords;
typedef struct { Gfx2 *gfx; FixedMatrixWords *mtx; } RenderBuffers;
extern int D_8012CE48;
extern float D_8012C82C;
extern float D_8012C830;
extern s32 D_80123198[];
extern void func_800EFA4C(void *, f32, f32, f32);
extern u8 D_8012CA08[];
struct __OSBlockInfo { u32 field_0x0; void *field_0x4; void *field_0x8; u32 field_0xc; u32 field_0x10; u32 field_0x14[4]; };
extern struct __OSBlockInfo D_8012C988;
extern s32 D_8012C980;
extern s32 D_8012C974;
s32 D_8012C850[60];
extern s32 D_8012C95C;
extern u8 D_8012C96C;
extern s32 D_8012C964;
extern s32 D_8012C978;
struct Struct_800DF8CC { s32 unk30; };
extern void func_8001980C(s32 a, s32 b, s32 c, s32 d);
extern s16 widescreen_enabled;
void func_800E42F0(u32, s32);
void func_800EFD24(f32 *);
void func_800E4640(u32);
void *func_800A89F8(void);
f32 func_800A8AF0(void *);
void func_800DE2A4();
void func_800DF744();

extern s32 D_8012C824;
extern s32 D_8012C940;

void func_800DC580(f32 *param_0, f32 *param_1)
{
    param_0[0] = param_1[0] * D_8012C948.raw;
    param_0[1] = param_1[1] * D_8012C948.raw;
    param_0[2] = param_1[2] * D_8012C948.raw;
}

void func_800DC5BC(u8 *param_0, u8 *param_1) {
    (*(f32 *)((s8 *)(param_0) + (0))) = (f32) (((*(f32 *)((s8 *)(param_1) + (0))) * (*(f32 *)((s8 *)(((s32 *) &D_8012C948.raw)) + (0)))) + (*(f32 *)((s8 *)((*(u8 **)((s8 *)(((s32 *) &D_8012C948.raw)) + (4)))) + (0))));
    (*(f32 *)((s8 *)(param_0) + (4))) = (f32) (((*(f32 *)((s8 *)(param_1) + (4))) * (*(f32 *)((s8 *)(((s32 *) &D_8012C948.raw)) + (0)))) + (*(f32 *)((s8 *)((*(u8 **)((s8 *)(((s32 *) &D_8012C948.raw)) + (4)))) + (4))));
    (*(f32 *)((s8 *)(param_0) + (8))) = (f32) (((*(f32 *)((s8 *)(param_1) + (8))) * (*(f32 *)((s8 *)(((s32 *) &D_8012C948.raw)) + (0)))) + (*(f32 *)((s8 *)((*(u8 **)((s8 *)(((s32 *) &D_8012C948.raw)) + (4)))) + (8))));
}

void func_800DC61C(s32 arg0, s32 arg1) {
}
void func_800DC628(s32 arg0, s32 arg1) {
}
void func_800DC634(void *param_0, void *param_1)
{
  s16 *p1 = (s16 *) param_1;
  f32 local_0[3];
  u32 *p0 = (u32 *) param_0;
  u32 *ptr;
  if (p1[4] != 0)
  {
    func_800193C4(local_0, &p1[6]);
    mlMtx_push_translation(local_0[0], local_0[1], local_0[2]);
    mlMtxRotYaw(D_8012CEAC);
    if (p1[5] == 0)
    {
      mlMtxRotPitch(D_8012CEA8);
    }
    mlMtxScale(D_8012C948.raw);
    mlMtxTranslate(-((f32 *) param_1)[3], -((f32 *) param_1)[4], -((f32 *) param_1)[5]);
    mlMtxApply(p0[1]);
    ptr = (u32 *) p0[0];
    p0[0] += 8;
    *ptr = 0xDA380002;
    ptr[1] = p0[1];
    p0[1] += 0x40;
    func_800DE2A4(param_0, (char *) ((s32) param_1 + (s32) ((Knoten_800DC634 *) param_1)->unk8));
    mlMtxPop();
    ptr = (u32 *) p0[0];
    p0[0] += 8;
    *ptr = 0xD8380002; ptr[1] = 0x40;
  }
}

void func_800DC740(void *param_0, void *param_1)
{
  s16 *p1 = (s16 *) param_1;
  f32 local_0[3];
  u32 *p0 = (u32 *) param_0;
  u32 *ptr;
  if (p1[4] != 0)
  {
    func_800DC580(local_0, &p1[6]);
    mlMtx_push_translation(local_0[0], local_0[1], local_0[2]);
    mlMtxRotYaw(D_8012CEAC);
    if (p1[5] == 0)
    {
      mlMtxRotPitch(D_8012CEA8);
    }
    mlMtxScale(D_8012C948.raw);
    mlMtxTranslate(-((f32 *) param_1)[3], -((f32 *) param_1)[4], -((f32 *) param_1)[5]);
    mlMtxApply(p0[1]);
    ptr = (u32 *) p0[0];
    p0[0] += 8;
    *ptr = 0xDA380002;
    ptr[1] = p0[1];
    p0[1] += 0x40;
    func_800DE2A4(param_0, (char *) ((s32) param_1 + (s32) ((Knoten_800DC740 *) param_1)->unk8));
    mlMtxPop();
    ptr = (u32 *) p0[0];
    p0[0] += 8;
    *ptr = 0xD8380002; ptr[1] = 0x40;
  }
}

void func_800DC84C(u8 *param_0, u8 *param_1)
{
  volatile s32 local_1;
  f32 local_0[3];
  u64 *temp_v1;
  if ((*((s16 *) (param_1 + 8))) != 0)
  {
    u64 *temp_v1_2;
    func_800DC5BC(local_0, param_1 + 0xC);
    mlMtx_push_translation(local_0[0], local_0[1], local_0[2]);
    mlMtxRotYaw(D_8012CEAC);
    if ((*((s16 *) (param_1 + 0xA))) == 0)
    {
      mlMtxRotPitch(D_8012CEA8);
    }
    mlMtxScale(D_8012C948.raw);
    mlMtxTranslate(-(*((f32 *) (param_1 + 0xC))), -(*((f32 *) (param_1 + 0x10))), -(*((f32 *) (param_1 + 0x14))));
    mlMtxApply(*((s32 *) (param_0 + 4)));
    temp_v1 = (*((u64 **) param_0))++;
    ((s32 *) temp_v1)[0] = 0xDA380002;
    ((s32 *) temp_v1)[1] = *((s32 *) (param_0 + 4));
    *((s32 *) (param_0 + 4)) = (*((s32 *) (param_0 + 4))) + 0x40;
    func_800DE2A4(param_0, (u8 *) ((s32) param_1 + (s32) ((Knoten_800DC84C *) param_1)->unk8));
    mlMtxPop();
    temp_v1_2 = (*((u64 **) param_0))++;
 ((s32 *) temp_v1_2)[0] = 0xD8380002; ((s32 *) temp_v1_2)[1] = 0x40;
  }
}

void func_800DC958(s32 param_0, u8 *param_1)
{
  f32 local_0;
  s16 local_1;
  s16 local_2;
  s16 local_3;
  s32 local_4;
  s8 *new_var;
  s32 local_5;
  s32 local_6;
  if ((*((u8 *) (((s8 *) param_1) + 0x21))) & 2)
  {
    func_80019AA0(&D_8012CE58, func_800ADE2C(((s32) D_8012C968), *((s8 *) (((s8 *) param_1) + 0x20))));
  }
  func_800193C4(&D_8012CEE0, param_1 + 8);
  func_800193C4(&D_8012CEF0, param_1 + 0x14);
  if ((*((u8 *) (((s8 *) param_1) + 0x21))) & 2)
  {
    mlMtxPop();
  }
  func_800EFB24(&D_8012CED0, &D_8012CEF0, &D_8012CEE0);
  func_800EF3DC(&D_8012CEE0, &D_8012CE98);
 do { } while (0);
  local_0 = -(((*((f32 *) (((s8 *) (&D_8012CED0)) + 0))) * (*((f32 *) (((s8 *) (&D_8012CEE0)) + 0)))) + ((*((f32 *) (((s8 *) (&D_8012CED0)) + 4))) * (*((f32 *) (((s8 *) (&D_8012CEE0)) + 4)))) + ((*((f32 *) (((s8 *) (&D_8012CED0)) + 8))) * (*((f32 *) (((s8 *) (&D_8012CEE0)) + 8)))));
  new_var = ((s8 *) param_1) + 0x21;
  if ((*((u8 *) new_var)) & 1)
  {
    if (local_0 >= 0.0f)
    {
      local_4 = *((s32 *) (((s8 *) param_1) + 0x24));
      if (local_4 != 0)
      {
        D_8012CEC8 = local_0;
        func_800DE2A4(param_0, (s32) param_1 + local_4);
        return;
      }
    }
    D_8012CEC8 = local_0;
    if (local_0 < 0.0f)
    {
      local_1 = *((s16 *) (((s8 *) param_1) + 0x22));
      if (local_1 != 0)
      {
        func_800DE2A4(param_0, (s32) param_1 + local_1);
      }
    }
  }
  else
  {
    D_8012CEC8 = local_0;
    if (local_0 >= 0.0f)
    {
      local_2 = *((s16 *) (((s8 *) param_1) + 0x22));
      if (local_2 != 0)
      {
        func_800DE2A4(param_0, (s32) param_1 + local_2);
      }
      local_5 = *((s32 *) (((s8 *) param_1) + 0x24));
      if (local_5 != 0)
      {
        func_800DE2A4(param_0, (s32) param_1 + local_5);
      }
    }
    else
    {
      local_6 = *((s32 *) (((s8 *) param_1) + 0x24));
      if (local_6 != 0)
      {
        func_800DE2A4(param_0, (s32) param_1 + local_6);
      }
      local_3 = *((s16 *) (((s8 *) ((0, param_1))) + 0x22));
      if (local_3 != 0)
      {
        func_800DE2A4(param_0, (s32) param_1 + local_3);
      }
    }
  }
}

void func_800DCB58(s32 param_0, u8 *param_1) {
    f32 local_0;
    s16 local_1;
    s16 local_2;
    s16 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;

    func_800DC580(&D_8012CF10, param_1 + 8);
    func_800DC580(&D_8012CF20, param_1 + 0x14);
    func_800EFB24(&D_8012CF00, &D_8012CF20, &D_8012CF10);
    func_800EF3DC(&D_8012CF10, &D_8012CE98);
    
local_0 = -((((*(f32 *)((s8 *)(&D_8012CF00) + (0))) * (*(f32 *)((s8 *)(&D_8012CF10) + (0)))) + ((*(f32 *)((s8 *)(&D_8012CF00) + (4))) * (*(f32 *)((s8 *)(&D_8012CF10) + (4))))) + (((*(f32 *)((s8 *)(&D_8012CF00) + (8))) * (*(f32 *)((s8 *)(&D_8012CF10) + (8))))));
    
    if ((*(u8 *)((s8 *)(param_1) + (0x21))) & 1) {
        if (local_0 >= 0.0f) {
            local_4 = (*(s32 *)((s8 *)(param_1) + (0x24)));
            if (local_4 != 0) {
                D_8012CEFC = local_0;
                func_800DE2A4(param_0, param_1 + local_4);
                return;
            }
        }
        D_8012CEFC = local_0;
        if (local_0 < 0.0f) {
            local_1 = (*(s16 *)((s8 *)(param_1) + (0x22)));
            if (local_1 != 0) {
                func_800DE2A4(param_0, (s32)param_1 + local_1);
            }
        }
    } else {
        D_8012CEFC = local_0;
        if (local_0 >= 0.0f) {
            local_2 = (*(s16 *)((s8 *)(param_1) + (0x22)));
            if (local_2 != 0) {
                func_800DE2A4(param_0, (s32)param_1 + local_2);
            }
            local_5 = (*(s32 *)((s8 *)(param_1) + (0x24)));
            if (local_5 != 0) {
                func_800DE2A4(param_0, param_1 + local_5);
            }
        } else {
            local_6 = (*(s32 *)((s8 *)(param_1) + (0x24)));
            if (local_6 != 0) {
                func_800DE2A4(param_0, param_1 + local_6);
            }
            local_3 = (*(s16 *)((s8 *)(param_1) + (0x22)));
            if (local_3 != 0) {
                func_800DE2A4(param_0, (s32)param_1 + local_3);
            }
        }
    }
}

void func_800DCD10(s32 param_0, u8 *param_1)
{
  f32 local_0;
  s16 local_1;
  s16 local_2;
  s16 local_3;
  s32 local_4;
  s32 local_5;
  s32 local_6;
  func_800DC5BC(&D_8012CF40, param_1 + 8);
  func_800DC5BC(&D_8012CF50, param_1 + 0x14);
  func_800EFB24(&D_8012CF30, &D_8012CF50, &D_8012CF40);
  func_800EF3DC(&D_8012CF40, ((f32 *) &D_8012CE98));
  local_0 = -((((*((f32 *) (((char *) (&D_8012CF30)) + 0))) * (*((f32 *) (((char *) (&D_8012CF40)) + 0)))) + ((*((f32 *) (((char *) (&D_8012CF30)) + 4))) * (*((f32 *) (((char *) (&D_8012CF40)) + 4))))) + ((*((f32 *) (((char *) (&D_8012CF30)) + 8))) * (*((f32 *) (((char *) (&D_8012CF40)) + 8)))));
  if ((*((u8 *) (((char *) param_1) + 0x21))) & 1)
  {
    if (local_0 >= 0.0f)
    {
      local_4 = *((s32 *) (((char *) param_1) + 0x24));
      if (local_4 != 0)
      {
        D_8012CF2C = local_0;
        func_800DE2A4(param_0, param_1 + local_4);
        return;
      }
    }
    D_8012CF2C = local_0;
    if (local_0 < 0.0f)
    {
      local_1 = *((s16 *) (((char *) param_1) + (0x22 ^ 0)));
      if (local_1 != 0)
      {
        func_800DE2A4(param_0, (s32) param_1 + local_1);
 } } } else { D_8012CF2C = local_0; if (local_0 >= 0.0f) { local_2 = *((s16 *) (((char *) param_1) + 0x22));
      if (local_2 != 0)
      {
        func_800DE2A4(param_0, (s32) param_1 + local_2);
      }
      local_5 = *((s32 *) (((char *) param_1) + 0x24));
      if (local_5 != 0)
      {
        func_800DE2A4(param_0, param_1 + local_5);
      }
    }
    else
    {
      local_6 = *((s32 *) (((char *) param_1) + 0x24));
      if (local_6 != 0)
      {
        func_800DE2A4(param_0, param_1 + local_6);
      }
      local_3 = *((s16 *) (((char *) param_1) + 0x22));
      if (local_3 != 0)
      {
        func_800DE2A4(param_0, (s32) param_1 + local_3);
      }
    }
  }
}

void func_800DCEC8(u8 **param_0, u8 *param_1)
{
  switch (*((s32 *) (((char *) param_1) + 8)))
  {
    s32 v1;
    case 1:
      v1 = *((s32 *) param_0);
      *((s32 *) param_0) = (*((s32 *) param_0)) + 8;
      *((s32 *) (v1 + 0)) = 0xDE000000;
      *((s32 *) (v1 + 4)) = (s32) (D_8012C820 + 0x80000068);
      return;

    case 2:
      v1 = *((s32 *) param_0);
      *((s32 *) param_0) = (*((s32 *) param_0)) + 8;
      *((s32 *) (v1 + 0)) = 0xDE000000;
      *((s32 *) (v1 + 4)) = (s32) (D_8012C820 + 0x80000000);
      return;

  }

}

void func_800DCF48(void *param_0, void *param_1)
{
    GeoCmd2 *cmd = (GeoCmd2 *) param_1;
    u32 *p0 = (u32 *) param_0;
    u32 *ptr;

    if (D_8012C968) {
        func_80019AA0(&D_8012CE58, func_800ADE2C(D_8012C968, cmd->unk9));
        mlMtxApply(p0[1]);
        ptr = (u32 *) p0[0];
        p0[0] += 8;
        *ptr = 0xDA380002;
        ptr[1] = p0[1];
        p0[1] += 0x40;
    }
    if (cmd->unk8) {
        func_800DE2A4(param_0, (u8 *) cmd + cmd->unk8);
    }
    if (D_8012C968) {
        mlMtxPop();
        ptr = (u32 *) p0[0];
        p0[0] += 8;
        *ptr = 0xD8380002; ptr[1] = 0x40;
    }
}

void func_800DD024(Gfx2 **gfx, u8 *arg2)
{
  Gfx2 *_g;
  Gfx2 *vptr;
  vptr = &D_8012C960->list[*(s16 *) (arg2 + 8)];
  {
    Gfx2 *_h = (*gfx)++;
    _g = _h;
  }
  _g->w0 = 0xDE000000;
  _g->w1 = osVirtualToPhysical(vptr);
}

void func_800DD07C(void *param_0, void *param_1)
{
    GeoCmd5 *cmd = (GeoCmd5 *) param_1;
    u32 *p0 = (u32 *) param_0;
    Gfx2 *gfx = (Gfx2 *) p0[0];
    s32 i;

    {
        Gfx2 *_g = gfx++;
        _g->w0 = 0xDE000000;
        _g->w1 = osVirtualToPhysical(D_8012C948.RenderCtx_800DD07C.dlist->list + cmd->unk8[0]);
    }
    mlMtxApply(p0[1]);
    for (i = 1; cmd->unk8[i] != 0; i++) {
        {
            Gfx2 *_g = gfx++;
            _g->w0 = 0xDA380002;
            _g->w1 = p0[1];
        }
        {
            Gfx2 *_g = gfx++;
            _g->w0 = 0xDE000000;
            _g->w1 = osVirtualToPhysical(D_8012C948.RenderCtx_800DD07C.dlist->list + cmd->unk8[i]);
        }
    }
    p0[0] = (u32) gfx;
    p0[1] = p0[1] + 0x40;
}

void func_800DD19C(s32 param_0, u8 *param_1)
{
  s32 offset;
  offset = (unsigned long long) (*((s32 *) (((char *) param_1) + 8)));
  func_800DE2A4(param_0, param_1 + offset);
}

void func_800DD1C0(s32 **param_0, s16 *param_1)
{
  u8 *local_1;
  int new_var;
  u8 *new_var2;
  local_1 = (u8 *) (*param_0);
  *param_0 = (s32 *) (((u8 *) (*param_0)) + 8);
  *((s32 *) local_1) = 0xDE000000;
  new_var2 = local_1;
  *((s32 **) (new_var2 + 4)) = osVirtualToPhysical((((s32) D_8012C960) + (param_1[5] * 8)) + (new_var = 8));
}

void func_800DD214(u8 *param_0, u8 *param_1) {
    f32 local_0;
    f32 local_1;
    f32 local_2;

    if ((*(s32 *)((s8 *)(param_1) + (0x1C))) != 0) {
        if ((*(s16 *)((s8 *)(&D_8012CA38) + (0))) != 0) {
            (*(s16 *)((s8 *)(&D_8012CA38) + (2))) = (s16) ((*(s16 *)((s8 *)(&D_8012CA38) + (2))) + 1);
            if ((*(s16 *)((s8 *)(&D_8012CA38) + (0))) == (*(s16 *)((s8 *)(&D_8012CA38) + (2)))) {
                func_800DE2A4(param_0, (u8 *) ((s32) param_1 + (s32) ((Knoten_800DD214 *) param_1)->unk1C), param_1);
            }
        } else {
            func_800193C4(&D_8012CF60, param_1 + 0x10);
            local_0 = func_800EEB40(&D_8012CF60, &D_8012CE98);
            local_1 = (*(f32 *)((s8 *)(param_1) + (0xC)));
            if ((local_1 * local_1) < local_0) {
                local_2 = (*(f32 *)((s8 *)(param_1) + (8)));
                if (local_0 <= (local_2 * local_2)) {
                    func_800DE2A4(param_0, (u8 *) ((s32) param_1 + (s32) ((Knoten_800DD214 *) param_1)->unk1C), param_1);
                }
            }
        }
    }
}

void func_800DD2E8(s32 param_0, u8 *param_1)
{
  f32 temp_f0;
  f32 temp_f2;
  f32 temp_f2_2;
  if ((*((s32 *) (((s8 *) param_1) + 0x1C))) != 0)
  {
    func_800DC580(&D_8012CF70, param_1 + 0x10);
    temp_f0 = func_800EEB40(&D_8012CF70, ((u8 *) &D_8012CE98));
    temp_f2 = *((f32 *) (((s8 *) param_1) + 0xC));
    if ((temp_f2 * temp_f2) < temp_f0)
    {
      temp_f2_2 = *((f32 *) (((s8 *) param_1) + 8));
      if (temp_f0 <= (temp_f2_2 * temp_f2_2))
      {
        func_800DE2A4(param_0, (*((s32 *) (((s8 *) param_1) + 0x1C))) + ((0, param_1)), param_1);
      }
    }
  }
}

void func_800DD37C(s32 param_0, u8 *param_1) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    u8 *local_3;

    if (*(s32 *)(param_1 + 0x1C) != 0) {
        func_800DC5BC(&D_8012CF80, param_1 + 0x10);
        local_0 = func_800EEB40(&D_8012CF80, &D_8012CE98);
        local_1 = *(f32 *)(param_1 + 0xC);
        if ((local_1 * local_1) < local_0) {
            local_2 = *(f32 *)(param_1 + 8);
            if (local_0 <= (local_2 * local_2)) {
                local_3 = param_1;
                local_3 += *(s32 *)(param_1 + 0x1C);
                func_800DE2A4(param_0, local_3, param_1);
            }
        }
    }
}

void func_800DD410(void *param_0, s16 *param_1)
{
    s32 tot;
    f32 sp20[3];

    if (D_8012C844 != 0) {
        if (D_8012C968 != 0) {
            func_80019AA0(&D_8012CE58, func_800ADE2C(D_8012C968, param_1[5]));
            func_800193C4(sp20, param_1 + 6);
            mlMtxPop();
        } else {
            func_800193C4(sp20, param_1 + 6);
        }
        func_800DC028(D_8012C844, param_1[4], sp20);
    }
}

void func_800DD4AC(void *param_0, s16 *param_1)
{
    s32 tot;
    f32 sp18[3];

    if (D_8012C844 != 0) {
        func_800EFA20(sp18, param_1 + 6, D_8012C948.raw);
        func_800DC028(D_8012C844, param_1[4], sp18);
    }
}

void func_800DD504(void *param_0, s16 *param_1)
{
    s32 tot;
    f32 sp18[3];

    if (D_8012C844 != 0) {
        func_800EFA20(sp18, param_1 + 6, D_8012C948.raw);
        func_800EF04C(sp18, D_8012C94C);
        func_800DC028(D_8012C844, param_1[4], sp18);
    }
}

void func_800DD56C(void *param_0, void *param_1) {
    GeoCmdC *cmd = (GeoCmdC *) param_1;
    s32 sub_cmd;
    s32 indx;
    s32 s2;
    s32 s1;
    s32 *s0;

    indx = ((s32 *) D_8012C850)[cmd->unkA];

    if (cmd->unkA == 0)
        return;

    if (indx == 0)
        return;

    if (0 < indx) {
        if (indx <= cmd->unk8) {
            s0 = cmd->unkC;
            sub_cmd = (s32)cmd;
            sub_cmd += *(s32*)(s0 + (indx - 1));
            func_800DE2A4(param_0, (void *)sub_cmd);
        }
    } else {
        s1 = indx * (-1);
        s0 = cmd->unkC;
        for (s2 = 0; s2 < cmd->unk8; s2++) {
            if (s1 & 1)
            {
                sub_cmd = (s32)cmd;
                sub_cmd += s0[0];
                func_800DE2A4(param_0, (void *)sub_cmd);
            }
            s1 >>= 1;
            s0++;
        }
    }
}

void func_800DD65C(Gfx2 **param_0, s16 *param_1)
{
  Gfx2 *_g;
  s32 sp38;
  s32 var_a0;
  Gfx2 *vptr;
  s32 sp2C;
  sp38 = param_1[5];
  var_a0 = mlMtx_get_stack_pointer();
  if (param_1[7] != 0)
  {
    sp2C = sp38;
    if (param_1[7] & 1)
    {
      func_8010F070(var_a0, &sp2C, param_1[6]);
    }
  }
  if (D_8012CEC4 != 0)
  {
    D_8012CEC4(var_a0, &sp38, param_1[6]);
  }
  vptr = &D_8012C960->list[param_1[4]];
  {
    Gfx2 *_h = (*param_0)++;
    _g = _h;
  }
  _g->w0 = 0xDE000000;
  _g->w1 = osVirtualToPhysical(vptr);
}

void func_800DD728(void *param_0, void *param_1)
{
    GeoCmdX *cmd = (GeoCmdX *) param_1;
    s32 i;
    s32 sp6C;
    s32 sp68;
    void *stapel;
    void *zweit;

    sp68 = sp6C = cmd->unk2C;
    stapel = mlMtx_get_stack_pointer();
    zweit = func_80018BB4();
    mlMtxApply(((u32 *) param_0)[1]);

    if (cmd->unk2E != 0) {
        if (cmd->unk2E & 1) {
            if (cmd->unk20[0] != 0) {
                func_8010F070(stapel, &sp68, cmd->unk20[0]);
            }
            if (cmd->unk14[0] != 0) {
                func_8010F070(zweit, &sp68, cmd->unk14[0]);
            }
        }
    }
    if (D_8012CEC4 != 0) {
        if (cmd->unk20[0] != 0) {
            D_8012CEC4(stapel, &sp6C, cmd->unk20[0]);
        }
        if (cmd->unk14[0] != 0) {
            D_8012CEC4(zweit, &sp6C, cmd->unk14[0]);
        }
    }
    {
        Gfx2 *_g = (Gfx2 *) ((u32 *) param_0)[0];
        ((u32 *) param_0)[0] += 8;
        _g->w0 = 0xDE000000;
        _g->w1 = osVirtualToPhysical(D_8012C960->list + cmd->unk8[0]);
    }
    for (i = 1; cmd->unk8[i] != 0; i++) {
        if (cmd->unk2E != 0) {
            if (cmd->unk2E & 1) {
                if (cmd->unk20[i] != 0) {
                    func_8010F070(stapel, &sp68, cmd->unk20[i]);
                }
                if (cmd->unk14[i] != 0) {
                    func_8010F070(zweit, &sp68, cmd->unk14[i]);
                }
            }
        }
        if (D_8012CEC4 != 0) {
            if (cmd->unk20[i] != 0) {
                D_8012CEC4(stapel, &sp6C, cmd->unk20[i]);
            }
            if (cmd->unk14[i] != 0) {
                D_8012CEC4(zweit, &sp6C, cmd->unk14[i]);
            }
        }
        {
            Gfx2 *_g = (Gfx2 *) ((u32 *) param_0)[0];
            ((u32 *) param_0)[0] += 8;
            _g->w0 = 0xDA380002;
            _g->w1 = ((u32 *) param_0)[1];
        }
        {
            Gfx2 *_g = (Gfx2 *) ((u32 *) param_0)[0];
            ((u32 *) param_0)[0] += 8;
            _g->w0 = 0xDE000000;
            _g->w1 = osVirtualToPhysical(D_8012C960->list + cmd->unk8[i]);
        }
    }
    ((u32 *) param_0)[1] = ((u32 *) param_0)[1] + 0x40;
}

void func_800DD998(void *param_0, void *param_1)
{
    GeoCmdX *cmd = (GeoCmdX *) param_1;
    s32 i;
    s32 sp64;
    s32 sp60;
    void *sp5C;
    void *sp58;

    sp60 = sp64 = cmd->unk2C;
    sp5C = mlMtx_get_stack_pointer();
    sp58 = func_80018BB4();
    mlMtxApply(((u32 *) param_0)[1]);
    i = 0;
    do {
        if (cmd->unk2E != 0) {
            if (cmd->unk2E & 1) {
                if (cmd->unk20[i] != 0) {
                    func_8010F070(sp5C, &sp60, cmd->unk20[i]);
                }
                if (cmd->unk14[i] != 0) {
                    func_8010F070(sp58, &sp60, cmd->unk14[i]);
                }
            }
        }
        if (D_8012CEC4 != 0) {
            if (cmd->unk20[i] != 0) {
                D_8012CEC4(sp5C, &sp64, cmd->unk20[i]);
            }
            if (cmd->unk14[i] != 0) {
                D_8012CEC4(sp58, &sp64, cmd->unk14[i]);
            }
        }
        {
            Gfx2 *_g = (Gfx2 *) ((u32 *) param_0)[0];
            ((u32 *) param_0)[0] += 8;
            _g->w0 = 0xDE000000;
            _g->w1 = osVirtualToPhysical(D_8012C960->list + cmd->unk8[i]);
        }
        {
            Gfx2 *_g = (Gfx2 *) ((u32 *) param_0)[0];
            ((u32 *) param_0)[0] += 8;
            _g->w0 = 0xDA380002;
            _g->w1 = ((u32 *) param_0)[1];
        }
        i++;
    } while (cmd->unk8[i] != 0);
    ((u32 *) param_0)[1] = ((u32 *) param_0)[1] + 0x40;
}

void func_800DDB38(void *param_0, void *param_1)
{
    GeoCmd5 *cmd = (GeoCmd5 *) param_1;
    u32 *p0 = (u32 *) param_0;
    s32 i;

    mlMtxApply(p0[1]);
    i = 0;
    do {
        {
            Gfx2 *_g = (Gfx2 *) p0[0];
            p0[0] += 8;
            _g->w0 = 0xDE000000;
            _g->w1 = osVirtualToPhysical(D_8012C948.RenderCtx_800DDB38.dlist->list + cmd->unk8[i]);
        }
        {
            Gfx2 *_g = (Gfx2 *) p0[0];
            p0[0] += 8;
            _g->w0 = 0xDA380002;
            _g->w1 = p0[1];
        }
        i++;
    } while (cmd->unk8[i] != 0);
    p0[1] = p0[1] + 0x40;
}

void func_800DDC28(int param_0, s16 *param_1) {
    f32 local_0[3];
    f32 local_1[3];
    if (param_1[10]) {
        s16 *src = param_1;
        int i;
        for (i = 0; i < 3; i++) {
            local_0[i] = (f32)src[i + 4] * D_8012C948.raw;
            local_1[i] = (f32)src[i + 7] * D_8012C948.raw;
        }
        if (func_800E3D0C(local_0, local_1)) {
            func_800DE2A4(param_0, (s16 *) ((u8 *) param_1 + ((Knoten_800DDC28 *) param_1)->unk14));
        }
    }
}

void func_800DDD14(s32 param_0, u8 *param_1) {
    s32 local_0, local_1;
    s32 sp34;
    s32 local_2, local_3;
    s32 sp28;

    if ((*(s16 *)((u8 *)param_1 + 0x14)) != 0) {
        func_800EE88C(&sp34, param_1 + 8);
        func_800EE88C(&sp28, param_1 + 0xE);
        func_800EF334(&sp34, D_8012C948.raw);
        func_800EF334(&sp28, D_8012C948.raw);
        func_800EF04C(&sp34, D_8012C94C);
        func_800EF04C(&sp28, D_8012C94C);
        if (func_800E3D0C(&sp34, &sp28) != 0) {
            u8 *addr = param_1;
            addr += *(s16 *)(param_1 + 0x14);
            func_800DE2A4(param_0, addr);
        }
    }
}

void func_800DDDC4(void *param_0, void *param_1) {
    f32 sp34[3];
    f32 sp30;
    GeoCmdE *cmd = (GeoCmdE *) param_1;

    if (cmd->unk12 == -1) {
        func_800EE88C(sp34, cmd->unk8);
        func_800EF334(sp34, D_8012C948.RenderCtx_800DDDC4.scale);
        sp30 = (f32)cmd->unkE * D_8012C948.RenderCtx_800DDDC4.scale;
        if (func_800E3E8C(sp34, sp30) && cmd->unk10) {
            func_800DE2A4(param_0, (void *)((s32)cmd + cmd->unk10));
        }
    } else {
        func_800EE88C(sp34, cmd->unk8);
        sp30 = (f32)cmd->unkE * D_8012C948.RenderCtx_800DDDC4.scale;
        if (D_8012C948.RenderCtx_800DDDC4.animList) {
            func_80019AA0(&D_8012CE58,
                          func_800ADE2C(D_8012C948.RenderCtx_800DDDC4.animList, cmd->unk12));
            func_80019224(sp34, sp34);
            mlMtxPop();
        } else {
            func_80019224(sp34, sp34);
        }
        if (func_800E3E8C(sp34, sp30) && cmd->unk10) {
            func_800DE2A4(param_0, (void *)((s32)cmd + cmd->unk10));
        }
    }
}

void func_800DDF14(void *param_0, void *param_1) {
    f32 sp2C[3];
    f32 sp28;
    GeoCmdE *cmd = (GeoCmdE *) param_1;

    func_800EE88C(sp2C, cmd->unk8);
    func_800EF334(sp2C, D_8012C948.raw);
    sp28 = (f32)cmd->unkE * D_8012C948.raw;
    if (func_800E3E8C(sp2C, sp28) && cmd->unk10) {
        func_800DE2A4(param_0, (void *)((s32)cmd + cmd->unk10));
    }
}

void func_800DDFA0(void *param_0, void *param_1) {
    f32 sp2C[3];
    f32 sp28;
    GeoCmdE *cmd = (GeoCmdE *) param_1;

    func_800EE88C(sp2C, cmd->unk8);
    func_800EF334(sp2C, D_8012C948.raw);
    func_800EF04C(sp2C, D_8012C94C);
    sp28 = (f32)cmd->unkE * D_8012C948.raw;
    if (func_800E3E8C(sp2C, sp28) && cmd->unk10) {
        func_800DE2A4(param_0, (void *)((s32)cmd + cmd->unk10));
    }
}

void func_800DE03C(s32 param_0, s32 param_1)
{
  int new_var;
  u8 *local_1 = param_1;
  s32 local_2;
  local_2 = _dbzone_entrypoint_0(D_8012C970, local_1 + 0xD, local_1[0, 0xA]);
  if (((local_2 == 0) && (local_1[0xB] & 1)) || ((local_2 != 0) && (local_1[0xB] & 2)))
  {
 if (((int) D_8012C848) != 0) { if (local_1[0xC]) { _glzone_entrypoint_3(((int) D_8012C848), local_1[0xC]); } }
    new_var = (*((s16 *) (local_1 + 0x8))) & 0xFFFFFFFFFFFFFFFFu;
    func_800DE2A4(param_0, local_1 + new_var);
  }
}

void func_800DE0D8(void *param_0, void *param_1)
{
    GeoCmdB *cmd = (GeoCmdB *) param_1;
    s32 sp48;
    s32 i;

    sp48 = cmd->unkA;
    if (D_8012CEC4 != 0) {
        for (i = 0; i < cmd->unk8; i++) {
            func_80019AA0(&D_8012CE58,
                          func_800ADE2C(D_8012C948.RenderCtx_800DE0D8.animList, cmd->unkC[i].unk0));
            D_8012CEC4(mlMtx_get_stack_pointer(), &sp48, cmd->unkC[i].unk2);
            mlMtxPop();
        }
    }
}

void func_800DE1C4(void *param_0, void *param_1)
{
    GeoCmdY *cmd = (GeoCmdY *) param_1;
    s32 sp38;
    void *sp34;
    void *sp30;
    s32 sp2C;

    sp38 = cmd->unk8;
    sp34 = mlMtx_get_stack_pointer();
    sp30 = func_80018BB4();
    if (cmd->unkE != 0) {
        sp2C = sp38;
        if (cmd->unkE & 1) {
            if (cmd->unkA != 0) {
                func_8010F070(sp34, &sp2C, cmd->unkA);
            }
            if (cmd->unkC != 0) {
                func_8010F070(sp30, &sp2C, cmd->unkC);
            }
        }
    }
    if (D_8012CEC4 != 0) {
        if (cmd->unkA != 0) {
            D_8012CEC4(sp34, &sp38, cmd->unkA);
        }
        if (cmd->unkC != 0) {
            D_8012CEC4(sp30, &sp38, cmd->unkC);
        }
    }
}

void func_800DE2A4(param_0, param_1) s32 param_0; struct SomeStruct * param_1;
{
    while (1)
    {
        D_8012CF8C[param_1->unk0](param_0, param_1);
        if (param_1->unk4 == 0)
        {
            break;
        }
        param_1 = (struct SomeStruct *)((u8 *)param_1 + param_1->unk4);
    }
}

void func_800DE318(void)
{
  D_8012C824 = 0;
  D_8012C82C = 3e+04f;
  D_8012C828 = 1;
  D_8012C830 = 1.0f;
  D_8012C834 = 0;
  D_8012C838 = 0;
  D_8012C83C = 0;
  D_8012C844 = 0;
  D_8012C848 = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C948.raw))) + 0x18)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C948.raw))) + 0x20)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C948.raw))) + 0x14)) = 0;
  *((s8 *) (((char *) (((s32 *) &D_8012C948.raw))) + 0x24)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C948.raw))) + 0x1C)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C948.raw))) + 0x28)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C948.raw))) + 0x30)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C948.raw))) + 0x34)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C948.raw))) + 0x2C)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C948.raw))) + 0x38)) = 0;
  *((s32 *) (((char *) (&D_8012C9A8)) + 0)) = 0;
  *((s32 *) (((char *) (&D_8012C9A8)) + 8)) = 0;
  D_8012C9B8 = 0;
  D_8012CA18 = 0;
  D_8012CA28 = 0;
  *((s16 *) (((char *) (((s32 *) &D_8012CA38))) + 2)) = 0;
  *((s16 *) (((char *) (((s32 *) &D_8012CA38))) + 0)) = *((s16 *) (((char *) (((s32 *) &D_8012CA38))) + 2));
  D_8012CF8C = (void (**)(s32, void *)) D_80123198[0];
  func_800DF744(1, 1);
  func_800DF744(2, 0);
  *((s32 *) (((char *) (((s32 *) &D_8012C988))) + 0xC)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C988))) + 8)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C988))) + 4)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C988))) + 0)) = 0;
  *((s32 *) (((char *) (((s32 *) &D_8012C988))) + 0x10)) = (*((s32 *) (((char *) (((s32 *) &D_8012C988))) + 0x14)) = (*((s32 *) (((char *) (((s32 *) &D_8012C988))) + 0x18)) = (*((s32 *) (((char *) (((s32 *) &D_8012C988))) + 0x1C)) = 0xFF)));
}

typedef struct {
    Gfx* gfx;
    Mtx* mtx;
} GraphicsBuffers;

GraphicsBuffers* func_800A7180();


int func_800DE498(RenderBuffers *, f32 *, f32 *, f32, f32 *, u8 *);

// modelRender_draw?
void* func_800DE448(f32* position, f32* arg1, f32 scale, f32* arg3, s32 arg4) {
    return (void *) func_800DE498((RenderBuffers *) func_800A7180(), position, arg1, scale, arg3, (u8 *) arg4);
}

// the real modelRender_draw?
int func_800DE498(RenderBuffers *render_buffers, f32 *position, f32 *rotation, f32 scale, f32 *transform_arg5, u8 *model_bin)
{
  /* Keep padding, declaration order and mixed-role carriers: they affect IDO allocation. */
  f32 camera_focus[3];
  f32 object_position[3];
  f32 camera_focus_distance;
  f32 local_norm;
  f32 global_norm;
  s32 lookat_cmd_or_anim_matrices;
  s32 gfx_cursor;
  void (**render_callback_entry)(s32 *, s32, s32, s32 *);
  s32 (*render_end_callback)();
  void (*render_begin_callback)(s32 *, s32, s32, s32 *);
  u8 *unused_ptr_20;
  s32 vertex_segment_cmd;
  s32 texture_cmd_or_callback_arg;
  s32 segment_index_or_cmd;
  s32 texture_offset;
  s32 segment_cmd_or_anim_matrices;
  f32 tmp_f0;
  f32 pad_22;
  f32 scaled_draw_distance;
  f32 pad_4;
  u8 **lookat_cursor_pair = &D_8012CE40;
  f32 pad_5;
  s16 geometry_flags;
  s8 *unused_ptr;
  s32 opaque_segment_cmd;
  s32 translucent_segment_cmd;
  s32 pad_75;
  f32 unused_float;
  s32 pad_52;
  s32 cmd_or_animation_offset;
  s32 saved_matrix_cursor;
  s32 matrix_segment_cmd;
  s32 setup_segment_cmd;
  s32 cmd_or_model_offset;
  s32 pad_55;
  u8 *unused_ptr_60;
  u8 *verts;
  s32 color_cmd_or_callback; /* Shared across disjoint lifetimes; not one semantic game variable. */
  /* Reject distant or invisible models. Names follow BK's modelRender_draw where applicable. */
  D_8012C940 = 0;
  func_800E39A8(&D_8012CE98, ((s32 *) &D_8012CEA8));
  if (position)
    func_800EE7F8(object_position, position);
  else
    func_800EFD24(object_position);
  func_800EFB24(camera_focus, object_position, &D_8012CE98);
  if (3e+04f < mlAbsF(camera_focus[0]) || 3e+04f < mlAbsF(camera_focus[1]) || 3e+04f < mlAbsF(camera_focus[2]))
  {
    func_800DE318();
    return 0;
  }
  if (model_bin)
  {
    if (*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x1C))
      verts = *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x1C);
    else
    {
      verts = model_bin;
      verts += *(s32 *) (model_bin + 16);
    }
    global_norm = *(u16 *) (verts + 20);
    local_norm = *(u16 *) (verts + 18);
  }
  else
  {
    global_norm = D_8012CA20;
    local_norm = D_8012CA1C;
  }
  tmp_f0 = func_800EEF94(camera_focus);
  camera_focus_distance = tmp_f0;
  if (tmp_f0 >= 4000.0f && D_8012C82C == 3e+04f)
  {
    scaled_draw_distance = local_norm * scale * D_8012C830 * 50.0f;
    if (scaled_draw_distance < D_8012C82C)
      D_8012C82C = scaled_draw_distance;
  }
  tmp_f0 = func_800E42C0();
  D_8012C82C *= tmp_f0;
  if (D_8012C82C <= camera_focus_distance)
  {
    func_800DE318();
    return 0;
  }
  D_8012C940 = D_8012C828 ? func_800E3E8C(object_position, global_norm * scale) : 1;
  if (D_8012C940 == 0)
  {
    func_800DE318();
    return 0;
  }
  /* Pre-draw hook, optional asset lookup, and lazy model-section pointers. */
  if (D_8012C9A8)
    D_8012C9A8(D_8012C9AC);
  if (model_bin == 0)
  {
    model_bin = func_800D674C(D_8012CA18);
    if (model_bin == 0)
    {
      func_800DE318();
      return 0;
    }
  }
  if (*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x18) == 0)
    *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x18) = (u8 *) ((s32) model_bin + ((ModelBinHeader *) model_bin)->gfx_list_offset_C);
  if (*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x14) == 0)
    *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x14) = (u8 *) ((s32) model_bin + ((ModelBinHeader *) model_bin)->texture_list_offset_8);
  if (*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x1C) == 0)
    *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x1C) = (u8 *) ((s32) model_bin + ((ModelBinHeader *) model_bin)->vtx_list_offset_10);
  cmd_or_model_offset = *(s32 *) (model_bin + 32);
  if (cmd_or_model_offset == 0)
    *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x28) = 0;
  else
    *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x28) = model_bin + cmd_or_model_offset;
  /* Tooie adds an optional section at model +0x38, cached in render context +0x30. */
  if (*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x30) == 0)
  {
    cmd_or_model_offset = *(s32 *) (model_bin + 56);
    if (cmd_or_model_offset == 0)
      *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x30) = 0;
    else
      *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x30) = model_bin + cmd_or_model_offset;
  }
  /* Tooie fades over 700 units using 8-bit fixed-point alpha; BK uses a different fade. */
  if (D_8012C834)
  {
    tmp_f0 = D_8012C82C - 700.0f;
    if (tmp_f0 < camera_focus_distance)
    {
      cmd_or_model_offset = (s32) ((1 - ((camera_focus_distance - tmp_f0) / 700.0f)) * 256.0f);
      *(s32 *) ((u8 *) &D_8012C9A8 - 4) = (D_8012C9A4 * cmd_or_model_offset) / 256;
    }
  }
  /* Macro candidates: gSPSegment for vertex segment 1 and texture segment 2. */
  gfx_cursor = (s32) render_buffers->gfx;
  vertex_segment_cmd = gfx_cursor;
  gfx_cursor = gfx_cursor + 8;
  *(s32 *) vertex_segment_cmd = 0xDB060004;
  *(s32 *) (vertex_segment_cmd + 4) = osVirtualToPhysical(*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x1C) + 24);
  texture_cmd_or_callback_arg = gfx_cursor;
  gfx_cursor = texture_cmd_or_callback_arg + 8;
  *(s32 *) texture_cmd_or_callback_arg = 0xDB060008;
  *(s32 *) (texture_cmd_or_callback_arg + 4) = osVirtualToPhysical(*(s16 *) (*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x14) + 4) * 8 + *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x14) + 8);
  /* Animated textures: Tooie visits seven slots (segments 15..9), unlike BK's four. */
  if (*((u8 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x24)))
  {
    segment_index_or_cmd = 0;
    do
    {
      if (func_800DB9FC(*((u8 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x24)), segment_index_or_cmd, &texture_offset))
      {
        segment_cmd_or_anim_matrices = gfx_cursor;
        gfx_cursor = segment_cmd_or_anim_matrices + 8;
        *(s32 *) segment_cmd_or_anim_matrices = ((((-segment_index_or_cmd) * 4) + 60) & 65535) | 0xDB060000;
        *(s32 *) (segment_cmd_or_anim_matrices + 4) = osVirtualToPhysical(*(s16 *) (*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x14) + 4) * 8 + *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x14) + texture_offset + 8);
      }
      segment_index_or_cmd = segment_index_or_cmd + 1;
    }
    while (segment_index_or_cmd != 7);
  }
  /* Merge primitive alpha into environment alpha unless the color mode preserves it. */
  color_cmd_or_callback = ((s32 *) &D_8012C988)[3];
  if (((s32 *) &D_8012C988)[3] && D_8012C83C != 3)
  {
    ((s32 *) &D_8012C988)[3] = 0;
    ((s32 *) &D_8012C988)[7] = ((s32 *) &D_8012C988)[7] + (((255 - ((s32 *) &D_8012C988)[7]) * color_cmd_or_callback) / 255);
  }
  cmd_or_model_offset = gfx_cursor;
  gfx_cursor = cmd_or_model_offset + 8;
  *(s32 *) (cmd_or_model_offset + 4) = 0;
  *(s32 *) cmd_or_model_offset = 0xE7000000; /* gDPPipeSync candidate. */
  color_cmd_or_callback = gfx_cursor;
  gfx_cursor = color_cmd_or_callback + 8;
  *(s32 *) color_cmd_or_callback = 0xE3000800; *(s32 *) (color_cmd_or_callback + 4) = 8388608; /* Candidate: gDPPipelineMode(G_PM_1PRIMITIVE), F3DEX2 encoding. */
  cmd_or_model_offset = gfx_cursor;
  segment_index_or_cmd = gfx_cursor;
  gfx_cursor = segment_index_or_cmd + 8;
  *(s32 *) segment_index_or_cmd = 0xE3000A01; *(s32 *) (segment_index_or_cmd + 4) = 1048576; /* Candidate: gDPSetCycleType(G_CYC_2CYCLE), F3DEX2 encoding. */
  cmd_or_animation_offset = gfx_cursor;
  gfx_cursor = cmd_or_animation_offset + 8;
  *(s32 *) cmd_or_animation_offset = 0xF9000000; *(s32 *) (cmd_or_animation_offset + 4) = 128; /* gDPSetBlendColor candidate. */
  cmd_or_model_offset = gfx_cursor;
  texture_cmd_or_callback_arg = gfx_cursor;
  gfx_cursor = texture_cmd_or_callback_arg + 8;
  *(s32 *) texture_cmd_or_callback_arg = 0xFA000000; /* gDPSetPrimColor candidate. */
  *(s32 *) (texture_cmd_or_callback_arg + 4) = (((((s32 *) &D_8012C988)[1] & 255) << 16) | ((((s32 *) &D_8012C988)[2] & 255) << 8)) | (((((s32 *) &D_8012C988)[0] << 12) << 12) | (((s32 *) &D_8012C988)[3] & 255));
  cmd_or_animation_offset = gfx_cursor;
  gfx_cursor = cmd_or_animation_offset + 8;
  *(s32 *) cmd_or_animation_offset = 0xFB000000; /* gDPSetEnvColor candidate. */
  *(s32 *) (cmd_or_animation_offset + 4) = (((((s32 *) &D_8012C988)[5] & 255) << 16) | ((((s32 *) &D_8012C988)[6] & 255) << 8)) | (((((s32 *) &D_8012C988)[4] << 18) << 6) | (((s32 *) &D_8012C988)[7] & 255));
  /* gSPSet/ClearGeometryMode candidates: enable or disable G_ZBUFFER. */
  if (D_8012CA28)
  {
    cmd_or_model_offset = gfx_cursor;
    gfx_cursor = cmd_or_model_offset + 8;
  *(s32 *) cmd_or_model_offset = 0xD9FFFFFF; *(s32 *) (cmd_or_model_offset + 4) = 1;
  }
  else
  {
    cmd_or_model_offset = gfx_cursor;
    color_cmd_or_callback = cmd_or_model_offset;
    gfx_cursor = color_cmd_or_callback + 8;
    *(s32 *) ((cmd_or_model_offset) + 4) = 0;
    *(s32 *) color_cmd_or_callback = 0xD9FFFFFE;
  }
  /* Segment 3 selects the opaque/translucent render-mode table for the depth mode. */
  if (((s32 *) &D_8012C988)[7] == 255)
  {
    opaque_segment_cmd = gfx_cursor;
    gfx_cursor = opaque_segment_cmd + 8;
    *(s32 *) opaque_segment_cmd = 0xDB06000C;
    *(s32 *) (opaque_segment_cmd + 4) = osVirtualToPhysical(*(&D_80122DC8 + D_8012CA28 * 2));
  }
  else
  {
    translucent_segment_cmd = gfx_cursor;
    gfx_cursor = translucent_segment_cmd + 8;
    *(s32 *) translucent_segment_cmd = 0xDB06000C;
    *(s32 *) (translucent_segment_cmd + 4) = osVirtualToPhysical(*(&D_80122DCC + D_8012CA28 * 2));
  }
  /* BK identifies bit 0x2 as mipmapping; the extra 0x80/0x100 setup variants need review. */
  geometry_flags = *(s16 *) (model_bin + 10);
  if (geometry_flags & 2)
    D_8012C820 = &D_80122DF0;
  else
    if (geometry_flags & 128)
    D_8012C820 = &D_80122EB0;
  else
    if (geometry_flags & 256)
    D_8012C820 = &D_80122F70;
  else
    D_8012C820 = 0;
  if (((u8 *) D_8012C820))
  {
    cmd_or_animation_offset = gfx_cursor;
    gfx_cursor = cmd_or_animation_offset + 8;
    *(s32 *) cmd_or_animation_offset = 0xDE000000;
    *(u8 **) (cmd_or_animation_offset + 4) = ((u8 *) D_8012C820) + 2147483648;
  }
  /* Environment mapping: guLookAtReflect equivalent, then expanded gSPLookAt X/Y commands. */
  if (*(s16 *) (model_bin + 10) & 4)
  {
    if (camera_focus[2] == 0.0f)
      camera_focus[2] = (-0.1f);
    func_80013C80((s32) render_buffers->mtx, D_8012CA40[0x100], *(f32 *) &D_8012CA40[0x102], *(f32 *) &D_8012CA40[0x103], *(f32 *) &D_8012CA40[0x104], camera_focus[0], camera_focus[1], camera_focus[2], 0.0f, 1, 0.0f);
    cmd_or_model_offset = gfx_cursor;
    color_cmd_or_callback = cmd_or_model_offset;
    gfx_cursor = cmd_or_model_offset + 8;
    *(s32 *) color_cmd_or_callback = 0xDC08000A;
    *(s32 *) (cmd_or_model_offset + 4) = D_8012CA40[0x100];
    lookat_cmd_or_anim_matrices = gfx_cursor;
    gfx_cursor = lookat_cmd_or_anim_matrices + 8;
    *(s32 *) lookat_cmd_or_anim_matrices = 0xDC08030A;
    *(s32 *) (lookat_cmd_or_anim_matrices + 4) = D_8012CA40[0x100] + 16;
    osWritebackDCache(D_8012CA40[0x100], 32);
    D_8012CE40 += 32;
    if (lookat_cursor_pair[1] == *lookat_cursor_pair)
      *lookat_cursor_pair = (u8 *) &D_8012CA40;
  }
  /* Tooie-only flag 0x20 emits additional commands through a cursor-updating helper. */
  if (*(s16 *) (model_bin + 10) & 32)
    func_800D2C54((u8 **) (&gfx_cursor));
  /* Resolve animation matrices; parallels BK's boneless/boned animation setup. */
  if ((segment_cmd_or_anim_matrices = *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x20)) && *(s32 *) (model_bin + 24) == 0)
    *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x20) = 0;
  else
    if (segment_cmd_or_anim_matrices == 0 && *(s32 *) (model_bin + 24))
  {
    if (D_8012C824 == 0)
      func_800ADCD0(&D_8012C840, func_800B27E0(model_bin));
    else
      func_800AE160(&D_8012C840, func_800B27E0(model_bin), D_8012C824);
    *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x20) = D_8012C840;
  }
  /* Tooie zone processing; the precise optional glzone state is not yet named. */
  if (*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x28))
  {
    _dbzone_entrypoint_1(*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x28), &D_8012CE98, scale, object_position);
    if (D_8012C848)
      _glzone_entrypoint_2(D_8012C848);
  }
  /* Tooie chooses between two dbanim paths using the extra section and render mode. */
  cmd_or_animation_offset = *(s32 *) (model_bin + 40);
  if (cmd_or_animation_offset && (segment_cmd_or_anim_matrices = *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x20)))
  {
    *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x34) = model_bin + cmd_or_animation_offset;
    if (*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x30) && D_8012C838 == 1 && D_8012CA11 != 2 && D_8012CA11 != 3)
      _dbanim_entrypoint_1((s32) (*(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x34)), *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x1C), segment_cmd_or_anim_matrices, *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x30));
    else
    {
      cmd_or_model_offset = *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x34);
      _dbanim_entrypoint_0(cmd_or_model_offset, *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x1C), segment_cmd_or_anim_matrices, *(u8 **) ((char *) ((s32 *) &D_8012C948.raw) + 0x30));
    }
  }
  /* Build the model transform. Tooie supports extra rotation, scale, or matrix modes. */
  func_80019CD4();
  func_80019750(object_position, rotation, scale, transform_arg5);
  switch (D_8012C9B8)
  {
    case 1:
      mlMtxRotatePYR(*(f32 *) ((char *) &D_8012C9B8 + 0x4), *(f32 *) ((char *) &D_8012C9B8 + 0x8), *(f32 *) ((char *) &D_8012C9B8 + 0xC));
      break;
    case 2:
      mlMtxScale_xyz(*(f32 *) ((char *) &D_8012C9B8 + 0x4), *(f32 *) ((char *) &D_8012C9B8 + 0x8), *(f32 *) ((char *) &D_8012C9B8 + 0xC));
      break;
    case 3:
      func_80018C50(&D_8012C9C8);
  }
  mlMtxGet(&D_8012CE58);
  mlMtxApply((s32) render_buffers->mtx);
  /* Tooie flag 0x40 uses a matrix-buffer path, plausibly skeletal rendering. */
  /* Check custom gSPMatrix wrappers: 0xDA380005 differs from the ordinary 0xDA380002 path. */
  if (*(s16 *) (model_bin + 10) & 64)
  {
    cmd_or_model_offset = gfx_cursor;
    color_cmd_or_callback = cmd_or_model_offset;
    gfx_cursor = cmd_or_model_offset + 8;
    *(s32 *)color_cmd_or_callback = 0xDA380005;
    *(s32 *)(cmd_or_model_offset + 4) = (s32)render_buffers->mtx + 2147483648;
    render_buffers->mtx++;
    /* Cache the generated matrix range; segment 5 references it, segment 6 the setup list. */
    if (*(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x38) == 0)
    {
      saved_matrix_cursor = (s32)render_buffers->mtx;
      lookat_cmd_or_anim_matrices = *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x20);
      func_800AE598(lookat_cmd_or_anim_matrices, (s32) &render_buffers->mtx, render_buffers);
      *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x38) = saved_matrix_cursor + 64;
    }
    matrix_segment_cmd = gfx_cursor;
    gfx_cursor = matrix_segment_cmd + 8;
    *(s32 *) matrix_segment_cmd = 0xDB060014;
    *(s32 *) (matrix_segment_cmd + 4) = osVirtualToPhysical(*(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x38));

    if (((u8 *) D_8012C820))
    {
      setup_segment_cmd = gfx_cursor;
      gfx_cursor = setup_segment_cmd + 8;
      *(s32 *) setup_segment_cmd = 0xDB060018;
      *(s32 *) (setup_segment_cmd + 4) = osVirtualToPhysical(((u8 *) D_8012C820));
    }
  }
  else
  {
    cmd_or_model_offset = gfx_cursor;
    gfx_cursor = cmd_or_model_offset + 8;
    *(s32 *) cmd_or_model_offset = 0xDA380002;
    *(s32 *) (cmd_or_model_offset + 4) = (s32) render_buffers->mtx++;
  }
  /* Publish per-draw state for the geometry interpreter and Tooie callbacks. */
  *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x4) = object_position;
  *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x8) = rotation;
  *((f32 *) (((s32 *) &D_8012C948.raw))) = scale;
  *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0xC) = transform_arg5;
  if (D_8012C9B8 == 1)
    *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x10) = &D_8012C9BC;
  else
    *(s32 *) ((char *) ((s32 *) &D_8012C948.raw) + 0x10) = 0;
  if (rotation)
    func_800EE7F8(D_8012CEB8, rotation);
  else
    func_800EFD24(D_8012CEB8);
  render_buffers->gfx = (Gfx2 *) gfx_cursor;
  if (*(s16 *) (model_bin + 10) & 16)
    func_8010EF70(((s32 *) &D_8012C948.raw), 0, 0, &D_8012CE98);
  /* Tooie callback records are 12 bytes: begin, geometry callback, end. */
  /* Re-read after begin: the callback may change the selected record. */
  if (D_8012C838 == 1)
  {
    render_callback_entry = (void *)((u8 *)&D_80123030 + (12 * D_8012CA11));
    render_begin_callback = (void (*)(s32 *, s32, s32, s32 *))(color_cmd_or_callback = (s32)*render_callback_entry);
    if (render_begin_callback)
      render_begin_callback(((s32 *) &D_8012C948.raw), (*((s32 *) D_8012CA08)), texture_cmd_or_callback_arg = D_8012CA0C, &D_8012CE98);
    render_callback_entry = (void *)((u8 *)&D_80123030 + (12 * D_8012CA11));
    (*((D_8012CEC4_func_t *) &D_8012CEC4)) = *((D_8012CEC4_func_t *) (((s8 *) render_callback_entry) + 4));
  }
  /* Interpret the model's geometry list; keep the apparently redundant carriers for IDO. */
  texture_cmd_or_callback_arg = *(s32 *) (model_bin + 4);
  color_cmd_or_callback = *(s32 *) (model_bin + 4);
  func_800DE2A4(render_buffers, model_bin + color_cmd_or_callback);
  if (*(s16 *) (model_bin + 10) & 64)
    func_800E4640(render_buffers);
  else
  {
    cmd_or_model_offset = (s32) render_buffers->gfx++;
  *(s32 *) cmd_or_model_offset = 0xD8380002; *(s32 *) (cmd_or_model_offset + 4) = 64; /* gSPPopMatrix candidate. */
  }
  if (386 & *(s16 *) (model_bin + 10))
  {
    cmd_or_model_offset = (s32) render_buffers->gfx++;
  *(s32 *) cmd_or_model_offset = 0xDE000000; *(u8 **) (cmd_or_model_offset + 4) = (u8 *)&D_80122DB0 - 0x80000000; /* gSPDisplayList candidate; physical address is required. */
  }
  if (D_8012C838 == 1)
  {
    render_end_callback = *((s32 (**)())((u8 *)&D_80123038 + 12 * D_8012CA11));
    if (render_end_callback)
      render_end_callback();
    (*((D_8012CEC4_func_t *) &D_8012CEC4)) = 0;
  }
  if (*(s16 *) (model_bin + 10) & 16)
    func_8010F270();
  /* End of the optional render path, then the caller's post-draw hook. */
  if (D_8012C9B0)
    D_8012C9B0(D_8012C9B4);
  if (*(s16 *) (model_bin + 10) & 4)
    if (D_8012CE40 >= (u8 *)&D_8012CA40 && D_8012CE40 < lookat_cursor_pair[1]) /* Match-preserving empty guard; original intent is not established. */
    ;
  func_800DE318();
  return model_bin;
}

s32 func_800DF324()
{
    return D_8012C824;
}

int func_800DF330()
{
  return (int)&D_8012C840;
}

int func_800DF33C(s32 param_0)
{
  return ((s32 *) D_8012C850)[param_0];
}

s32 func_800DF350()
{
    return D_8012C940;
}

int func_800DF35C()
{
  func_800ADF5C(((int) D_8012C840));
  D_8012C840 = 0;
  func_8010E390();
}

void func_800DF38C(void)
{
    func_800DE318();
    ((int *) D_8012CA40)[0x100] = (int)((int *) D_8012CA40);
    ((int *) D_8012CA40)[0x101] = ((int *) D_8012CA40)[0x100] + 0x400;
    func_800EFD24(&D_8012CE48);
    D_8012C840 = func_800ADF98();
    func_8010E334();
}

void func_800DF3E0(void)
{
  s32 i;
  for (i = 0; i < 60; i++)
    ((s32 *) D_8012C850)[i] = 0;
}

void func_800DF410(s32 param_0)
{
  D_8012C9A4 = param_0;
}

void func_800DF41C(s32 param_0)
{
  D_8012C824 = param_0;
}

f32 func_800DF428(f32 param_0)
{
  f32 local_0 = D_8012C82C;
  D_8012C82C = param_0;
  return local_0;
}

int func_800DF440(s32 param_0)
{
  if (param_0 != 0)
  {
    D_8012C828 = 1;
  }
  else
  {
    D_8012C828 = 0;
  }
}

void func_800DF464(f32 param_0)
{
  D_8012C830 = param_0;
}

int func_800DF470(s32 param_0)
{
  D_8012C834 = param_0;
}

void func_800DF47C(s32 param_0, s32 param_1)
{
  *(s32*)&D_8012C9A8 = param_0;
  *(s32*)((char*)&D_8012C9A8 + 4) = param_1;
}

void func_800DF490(s32 param_0, s32 param_1)
{
  *((s32 *) ((s8*)(&D_8012C9A8) + 8)) = param_0;
  *((s32 *) ((s8*)(&D_8012C9A8) + 12)) = param_1;
}

int func_800DF4A4(s32 param_0)
{
  D_8012C960 = param_0;
}

void func_800DF4B0(s32 param_0)
{
  D_8012CF8C = (void (**)(s32, void *)) D_80123198[param_0];
}

void func_800DF4CC(s32 param_0)
{
  D_8012C9B8 = 1;
  func_800EE7F8(&D_8012C9BC, param_0 | 0);
}

void func_800DF500(f32 x, f32 y, f32 w)
{
  D_8012C9B8 = 2;
  func_800EFA4C(((f32 *) &D_8012C9BC), x, y, w);
}

void func_800DF540(s32 param_0)
{
  D_8012C9B8 = 3;
  func_800F293C(&D_8012C9C8, param_0 | 0);
}

void func_800DF574(s32 param_0)
{
    D_8012CA38 = param_0;
}

int func_800DF580(OSViCommonRegs *param_0, OSViCommonRegs *param_1)
{
  D_8012C83C = 1;
  *(s32*)((char*)((u8 *) &D_8012C988) + 0x10) = *(s32*)((char*)param_0 + 0x0);
  *(s32*)((char*)((u8 *) &D_8012C988) + 0x14) = *(s32*)((char*)param_0 + 0x4);
  *(s32*)((char*)((u8 *) &D_8012C988) + 0x18) = *(s32*)((char*)param_0 + 0x8);
  *(s32*)((char*)((u8 *) &D_8012C988) + 0x1C) = *(s32*)((char*)param_0 + 0xC);
  *(s32*)((char*)((u8 *) &D_8012C988) + 0x0) = *(s32*)((char*)param_1 + 0x0);
  *(s32*)((char*)((u8 *) &D_8012C988) + 0x4) = *(s32*)((char*)param_1 + 0x4);
  *(s32*)((char*)((u8 *) &D_8012C988) + 0x8) = *(s32*)((char*)param_1 + 0x8);
  *(s32*)((char*)((u8 *) &D_8012C988) + 0xC) = *(s32*)((char*)param_1 + 0xC);
}

void func_800DF5D8(u32 param_0, u32 param_1, u32 param_2, s32 param_3)
{
  D_8012C83C = 2;
  if ((s32)param_0 >= 0x100)
  {
    ((int *) &D_8012C988)[4] = 0xFF;
  }
  else
  {
    ((int *) &D_8012C988)[4] = param_0;
  }
  if ((s32)param_1 >= 0x100)
  {
    ((int *) &D_8012C988)[5] = 0xFF;
  }
  else
  {
    ((int *) &D_8012C988)[5] = param_1;
  }
  if ((s32)param_2 >= 0x100)
  {
    ((int *) &D_8012C988)[6] = 0xFF;
  }
  else
  {
    ((int *) &D_8012C988)[6] = param_2;
  }
  func_800DF410(param_3);
}

void func_800DF660(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    if (param_1 == 0 && param_2 == 0) {
        D_8012C838 = 0;
        return;
    }
    D_8012C838 = 1;
    *(s32*)((char*)D_8012CA08 + 0) = param_1;
    *(s32*)((char*)D_8012CA08 + 4) = param_2;
    *(u8*)((char*)D_8012CA08 + 9) = (u8)param_0;
    func_800DF410(param_3);
}

void func_800DF6BC(s32 param_0, s32 param_1)
{
    s32 local_0;

    D_8012C83C = 3;
    if (param_0 >= 0x100) {
        local_0 = 0xff;
    }
    else {
        local_0 = param_0;
    }
    D_8012C988.field_0xc = local_0;
    D_8012C988.field_0x8 = local_0;
    D_8012C988.field_0x4 = local_0;
    D_8012C988.field_0x0 = local_0;
    func_800DF410(param_1);
}

int func_800DF714(s32 param_0)
{
  D_8012C980 = param_0;
}

int func_800DF720(s32 param_0)
{
  D_8012C974 = param_0;
}

int func_800DF72C(s32 param_0)
{
  D_8012C968 = param_0;
}

int func_800DF738(s32 param_0)
{
  D_8012C844 = param_0;
}

void func_800DF744(param_0, param_1) s32 param_0; s32 param_1;
{
  ((s32 *) D_8012C850)[param_0] = param_1;
}

void func_800DF758(s32 *param_0)
{
  s32 i;
  for (i = 1; i < 60; i++)
    D_8012C850[i] = param_0[i];
}

int func_800DF7C4(s32 param_0, s32 param_1)
{
  ((s32 *) D_8012C850)[param_0] = -param_1;
}

int func_800DF7DC(s32 param_0)
{
  D_8012C95C = param_0;
}

int func_800DF7E8(param_0) u8 param_0;
{
  D_8012C96C = param_0;
}

int func_800DF7F8(s32 param_0, f32 param_1, f32 param_2)
{
  D_8012CA18 = param_0;
  *(f32*)((char*)&D_8012CA18 + 4) = param_1;
  *(f32*)((char*)&D_8012CA18 + 8) = param_2;
}

int func_800DF818(s32 param_0)
{
  D_8012C964 = param_0;
}

int func_800DF824(s32 param_0)
{
  D_8012C978 = param_0;
}

int func_800DF830(s32 param_0)
{
  D_8012CA28 = param_0;
}

int func_800DF83C(s32 param_0)
{
  D_8012C848 = param_0;
}

void func_800DF848(s32 param_0, s32 param_1)
{
  D_8012CA28 = 4;
  (&D_80122DC8)[D_8012CA28 * 2] = param_0;
  (&D_80122DC8)[D_8012CA28 * 2 + 1] = param_1;
}

int func_800DF874()
{
  if (D_8012C840 != 0)
  {
    D_8012C840 = func_800AE5F0(D_8012C840);
  }
  func_8010E358();
}

int func_800DF8B4(void *param_0) {
    return ((int *)param_0)[0x1C / 4];
}

s32 func_800DF8BC(s32 *arg0)
{
    return arg0[11];
}

f32 func_800DF8C4(f32 *arg0)
{
    return arg0[0];
}

func_800DF8CC(param_0)
struct Struct_800DF8CC *param_0;
{
    return (*(s32 *)((char *)(param_0) + 48));
}

s32 func_800DF8D4(char *param_0)
{
  s32 local_0;
  local_0 = (*((s32 *) (param_0 + 32))) != 0;
  if (local_0)
  {
    return (*((s32 *) (param_0 + 52))) == 0;
    return local_0;
  }
}

int func_800DF8F8(s32 param_0[1])
{
  return param_0[1];
}

int func_800DF900(s32 param_0[4]) {
  mlMtx_push_translation(0.0f, 0.0f, 0.0f);
  func_8001980C(param_0[1], param_0[2], param_0[0], param_0[3]);
}

ImageStruct *func_800DF944(u32 param_0, f32 *coords, f32 param_2, f32 param_3,
                           f32 *param_4, s32 param_5, ImageStruct *param_6)
{
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    func_800E42F0(param_0, param_5);
    if (coords != 0) {
        func_800EFA4C(sp44, coords[0] * 4.0f - 608.0f,
                      456.0f - coords[1] * 4.0f, -10.0f);
    } else {
        func_800EFA4C(sp44, 0.0f, 0.0f, -10.0f);
    }
    if (param_5 != 0) {
        if (widescreen_enabled != 0) {
            sp44[0] = (func_800A8AF0(func_800A89F8()) / 1.3333334f) * sp44[0];
        }
    }
    func_800EFA4C(sp38, 0.0f, 0.0f, param_2);
    if (param_4 != 0) {
        func_800EFA4C(sp2C, param_4[0], param_4[1], 0.0f);
    } else {
        func_800EFD24(sp2C);
    }
    func_800DF830(0);
    func_800DF440(0);
    param_6 = (ImageStruct *) func_800DE498((u8 *) param_0, sp44, sp38,
                                            4.0f * param_3, sp2C,
                                            (u8 *) param_6);
    func_800E4640(param_0);
    return param_6;
}
