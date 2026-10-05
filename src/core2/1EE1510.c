#include "common.h"

#define reinterpret_cast(type, var) (*((type *)&var))
extern s32 D_80124580;
extern void func_8010A3E8(void *, f32);
typedef struct { u32 top:31; u32 flag:1; } CtorTailDest;
typedef struct { u32 top:30; u32 flag:1; u32 tail:1; } CtorTailSource;
typedef struct { u32 top:15; u32 flag:1; u32 tail:16; } CtorDestFlag;
typedef struct { u32 top:11; u32 flag:1; u32 tail:20; } CtorCopyFlag;
typedef struct { u32 node:11; u32 id:12; u32 rest:9; } ActorIdBits;
typedef struct { u8 state:6; u8 rest:2; } ActorStateBits;
typedef struct { u8 rest:4; u8 mode:4; } ActorModeBits;
typedef struct { u8 mode:2; u8 rest:6; } ActorDrawBits;
typedef union { u8 raw; struct { u8 bit_7:1, bit_6:1, bit_5:1, bit_4:1, bit_3:1, bit_2:1, bit_1:1, bit_0:1; } bits; } CtorFlagByte;
typedef union { u32 raw; u16 half[2]; CtorFlagByte byte[4]; ActorIdBits id; } CtorFlagWord;
typedef struct { u8 *marker; f32 position[3]; s32 entry; s32 render; u8 data18[0x1C]; f32 value34; f32 scale; u8 data3C[0xC]; f32 yaw; u8 data4C[8]; f32 ideal_yaw; u32 data58; s8 color[3]; u8 data5F[5]; CtorFlagByte flags64[8]; CtorFlagWord flags6C; CtorFlagByte flags70[4]; CtorFlagWord flags74; CtorFlagByte flags78[4]; u16 value7C; CtorFlagByte flags7E[2]; u8 data80[0x14]; CtorFlagWord flags94; u8 color98[4]; } CtorActor;
typedef struct { s16 marker_id, actor_id; u16 model_id; s16 state; u8 data08[0x10]; u16 value18; u8 data1A[2]; f32 scale; u8 data20[2]; u16 value22; s32 flags; u8 data28[4]; s32 *draw; u16 value30, value32; u8 data34[8]; s32 flags3C; s32 value40; } CtorInfo;
void func_800EE904(f32* param_0, s32 param_1);
s32 func_80106790(s32);
typedef struct { u8 b70_a : 7; u8 f70_01 : 1; u8 b71_a : 2; u8 f71_20 : 1; u8 b71_b : 5; u8 b72; u8 b73_a : 4; u8 f73_08 : 1; u8 b73_b : 3; } Bytes70;
typedef struct { u32 w70_a : 7; u32 f70_01 : 1; u32 w70_b : 2; u32 f71_20 : 1; u32 w70_c : 17; u32 f73_08 : 1; u32 w70_d : 3; } Word70;
typedef struct { u8 b74_a : 6; u8 f74 : 1; u8 b74_b : 1; u8 b75; u8 b76; u8 b77_a : 1; u8 f77 : 1; u8 b77_b : 6; } Bytes74;
typedef struct { u32 w74_a : 6; u32 f74 : 1; u32 w74_b : 1; u32 w75 : 16; u32 w77_a : 1; u32 f77 : 1; u32 w77_b : 6; } Word74;
typedef struct { u8 b78[3]; u8 f7B : 2; u8 b7B_a : 4; u8 g7B : 1; u8 b7B_b : 1; } Bytes78;
typedef struct { u32 w78 : 24; u32 f7B : 2; u32 w7B_a : 4; u32 g7B : 1; u32 w7B_b : 1; } Word78;
typedef struct { /* 0x00 */ u8 pad00[0x70]; /* 0x70 */ union { Word70 w; Bytes70 b; } u70; /* 0x74 */ union { Word74 w; Bytes74 b; } u74; /* 0x78 */ union { Word78 w; Bytes78 b; } u78; /* 0x7C */ u8 pad7C[0x1A]; /* 0x96 */ u16 f96 : 1; /* */ u16 u96_b : 15; } ObjE1510;
typedef struct { /* 0x00 */ u8 pad00[0x10]; /* 0x10 */ u32 unk10_a : 11; /* */ u32 unk10_19: 11; /* */ u32 unk10_b : 5; /* */ u32 unk10_4 : 1; /* */ u32 unk10_3 : 2; /* */ u32 unk10_c : 2; } NodeE1510;
extern void func_8010381C(void);
extern s32 func_800BF8E4(ObjE1510 *);
extern void _subaddiefade_entrypoint_9(ObjE1510 *, f32 *);
extern void _subaddiefade_entrypoint_11(ObjE1510 *, f32 *);
typedef struct { /* 0x00 */ u8 pad00[0x48]; /* 0x48 */ f32 unk48; /* 0x4C */ u8 pad4C[0x2A]; /* 0x76 */ u16 unk76 : 9; /* */ u16 unk76b : 7; } ActorA8C;
typedef struct { /* 0x00 */ u8 pad00[4]; /* 0x04 */ u32 unk04 : 31; /* */ u32 bit0 : 1; /* 0x08 */ u8 pad08[8]; /* 0x10 */ u32 unk10_a : 11; /* */ u32 unk10_19: 11; /* */ u32 unk10_b : 10; } NodePropE1510;
extern NodePropE1510 *_gccubesearch_entrypoint_17(s32, s32);
typedef struct { /* 0x00 */ u8 pad00[0x77]; /* 0x77 */ u8 unk77_a : 3; /* */ u8 unk77_4 : 1; /* */ u8 unk77_b : 4; } ActorE1510;
typedef struct { /* 0x00 */ u8 pad00[2]; /* 0x02 */ s16 unk2_a : 5; /* */ s16 index : 10; /* */ s16 unk2_b : 1; /* 0x04 */ u8 pad04[8]; /* 0x0C */ f32 unk0C; } PropE1510;
extern void _gspropctrl_entrypoint_9(void *, s32 *);
extern s32 _glsplinefind_entrypoint_4(s32 *, s32 *);
extern s32 _glsplinefind_entrypoint_2(s32 *);
extern PropE1510 *func_8010556C(ActorE1510 *);
extern s32 func_800D7520(s32);
extern f32 func_800C82CC(s32, f32 *);
void func_80108658(ObjE1510 *p, s32 flags, s32 flags2, NodeE1510 *np);
void func_80108A8C();
int func_80108B44(u16 *param_0, u32 param_1, int param_2);
int func_80108C90(s32 param_0, s32 param_1, s32 param_2, void *param_3);
ActorE1510 *func_80108DC0(s32 arg0, s32 *position, s32 yaw, s32 arg3, s32 arg4, s32 arg5);

int func_80107C20()
{
  return (int)&D_80124580;
}

u8 *func_80107C2C(u8 *param_0, s32 param_1, u8 *param_2, s32 param_3, u8 *param_4)
{
  u8 *local_11; /* Allocated actor; raw pointer for the packed Tooie layout. */
  s32 local_0; /* Actor-array index returned by the allocator. */
  s32 local_1; /* Color component index, separate from the allocator output. */
  local_11 = func_80106668(&local_0);
  ((CtorActor *)local_11)->entry = param_3;
  ((ActorStateBits *)(local_11 + 0x72))->state = *(s16 *)(param_2 + 6);
  ((CtorActor *)local_11)->position[0] = (f32) (((s32 *)param_0)[0]);
  ((CtorActor *)local_11)->position[1] = (f32) (((s32 *)param_0)[1]);
  ((CtorActor *)local_11)->position[2] = (f32) (((s32 *)param_0)[2]);
  ((CtorActor *)local_11)->yaw = (f32)param_1;
  ((CtorActor *)local_11)->ideal_yaw = (f32)param_1;
  ((CtorActor *)local_11)->flags64[1].bits.bit_0 = 1;
  ((CtorActor *)local_11)->scale = 1.0f;
  ((ActorIdBits *)(local_11 + 0x6C))->id = *(s16 *)(param_2 + 2);
  ((CtorActor *)local_11)->value34 = 0.f;
  ((ActorModeBits *)(local_11 + 0x77))->mode = 0;
  ((ActorDrawBits *)(local_11 + 0x7A))->mode = 1;
  ((CtorActor *)local_11)->flags64[1].bits.bit_2 = 1;
  ((CtorActor *)local_11)->value7C = (u16) (((CtorInfo *)param_2)->value18);
  if ((((CtorInfo *)param_2)->scale) != 0.0f)
  {
    ((CtorFlagByte *)(local_11 + 0x75))->bits.bit_4 = 1;
  }
  else
  {
    ((CtorFlagByte *)(local_11 + 0x75))->bits.bit_4 = 0;
  }
  ((CtorDestFlag *)(local_11 + 0x94))->flag = ((CtorCopyFlag *)(local_11 + 0x74))->flag;
  func_80100074(local_11, 0, ((CtorInfo *)param_2)->value30);
  func_80100074(local_11, 1, ((CtorInfo *)param_2)->value32);
  /* Select the marker representation from the model's asset type. */
  if ((((CtorInfo *)param_2)->model_id) == 0xFFFF)
  {
    *((u8 **) (((s8 *) local_11) + 0)) = func_800EBED4(param_0, 1, ((CtorInfo *)param_2)->marker_id, ((((CtorInfo *)param_2)->flags) & 0x400) ? (1) : (0));
  }
  else
  {
    *((u8 **) (((s8 *) local_11) + 0)) = func_800EBED4(param_0, (func_800D738C(((CtorInfo *)param_2)->model_id) == 7) ? (0) : (1), ((CtorInfo *)param_2)->marker_id, ((((CtorInfo *)param_2)->flags) & 0x400) ? (1) : (0));
  }
  ((CtorDestFlag *)(*(u8 **)local_11 + 0x18))->flag = 1;
  if ((*((s32 **) (((s8 *) param_2) + 0x2C))) != 0)
  {
    *((s32 **) (((s8 *) (*((u8 **) (((s8 *) local_11) + 0)))) + 8)) = *((s32 **) (((s8 *) param_2) + 0x2C));
  }
  else
  {
    *((s32 **) (((s8 *) (*((u8 **) (((s8 *) local_11) + 0)))) + 8)) = &func_80107C20;
  }
  func_800EC340(*((u8 **) (((s8 *) local_11) + 0)), local_0);
  func_800EC360(*((u8 **) (((s8 *) local_11) + 0)), ((CtorInfo *)param_2)->model_id);
  func_800EC368(*((u8 **) (((s8 *) local_11) + 0)), ((CtorInfo *)param_2)->value22);
  ((CtorFlagByte *)(local_11 + 0x75))->bits.bit_0 = 1;
  ((CtorFlagByte *)(local_11 + 0x75))->bits.bit_3 = *(u16 *)(local_11 + 0x74);
  /* Transfer actor-info options into Tooie's actor and marker bitfields.
   * High-bit selectors are passed through unchanged to func_80102FA0. */
  if (func_80102FA0(param_2, 1) != 0)
  {
    _subaddieDll_entrypoint_1(local_11);
  }
  if (func_80102FA0(param_2, 0x800000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x71))->bits.bit_5 = 1;
  }
  if (func_80102FA0(param_2, 8) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x70))->bits.bit_0 = 1;
  }
  if (func_80102FA0(param_2, 0x100) != 0)
  {
    ((ActorModeBits *)(local_11 + 0x77))->mode = 1;
  }
  if (func_80102FA0(param_2, 0x200000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x64))->bits.bit_1 = 1;
  }
  if (func_80102FA0(param_2, 0x04000000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x71))->bits.bit_6 = 1;
  }
  if (func_80102FA0(param_2, 4) == 0)
  {
    ((CtorFlagByte *)(local_11 + 0x75))->bits.bit_1 = 1;
  }
  if (func_80102FA0(param_2, 0x100000) == 0)
  {
    ((CtorFlagByte *)(local_11 + 0x71))->bits.bit_4 = 1;
  }
  if (func_80102FA0(param_2, 0x08000000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x71))->bits.bit_2 = 1;
  }
  if (func_80102FA0(param_2, 0x80000002) != 0)
  {
    *((u8 *) (((s8 *) (*((u8 **) (((s8 *) local_11) + 0)))) + 0x2A)) = (u8) ((*((u8 *) (((s8 *) (*((u8 **) (((s8 *) local_11) + 0)))) + 0x2A))) & 0xFFFD);
  }
  if (func_80102FA0(param_2, 0x80000004) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x64))->bits.bit_7 = 1;
  }
  if (func_80102FA0(param_2, 0x80000008) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x64))->bits.bit_6 = 1;
  }
  if (func_80102FA0(param_2, 0x80000400) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x71))->bits.bit_1 = 1;
  }
  if (func_80102FA0(param_2, 0x80001000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x71))->bits.bit_0 = 1;
  }
  if (func_80102FA0(param_2, 0x80002000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x77))->bits.bit_5 = 1;
  }
  if (func_80102FA0(param_2, 0x80004000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x7E))->bits.bit_5 = 1;
  }
  if (func_80102FA0(param_2, 0x80000100) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x74))->bits.bit_2 = 1;
  }
  if (func_80102FA0(param_2, 0x80100000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x75))->bits.bit_7 = 1;
  }
  if (func_80102FA0(param_2, 0x80000001) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x64))->bits.bit_0 = 1;
  }
  if (func_80102FA0(param_2, 0x80000010) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x7B))->bits.bit_1 = 1;
  }
  if (func_80102FA0(param_2, 0x80400000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x94))->bits.bit_7 = 1;
  }
  if (func_80102FA0(param_2, 0x80800000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x94))->bits.bit_6 = 1;
  }
  if (func_80102FA0(param_2, 0x80000040) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x73))->bits.bit_2 = 1;
  }
  if (func_80102FA0(param_2, 0x80040000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x79))->bits.bit_3 = 1;
  }
  if (func_80102FA0(param_2, 0x80200000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x95))->bits.bit_1 = 1;
  }
  if (func_80102FA0(param_2, 0x84000000) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x96))->bits.bit_6 = 1;
  }
  if (func_80102FA0(param_2, 0x80000080) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x71))->bits.bit_3 = 1;
  }
  if (func_80102FA0(param_2, 0x82000000) != 0)
  {
    ((CtorDestFlag *)(local_11 + 0x94))->flag = 0;
  }
  func_8010A800(local_11, 0);
  if (func_80102FA0(param_2, 0x800) != 0)
  {
    func_8010A800(local_11, 1);
    func_8010A63C(local_11);
  }
  if (func_80102FA0(param_2, 0x20000) != 0)
  {
    func_8010A800(local_11, 2);
  }
  else
    if (func_80102FA0(param_2, 0x400000) != 0)
  {
    func_8010A800(local_11, 3);
  }
  else
    if (func_80102FA0(param_2, 0x80008000) != 0)
  {
    func_8010A800(local_11, 4);
  }
  if (func_80102FA0(param_2, 0x80000800) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x7E))->bits.bit_6 = 0;
  }
  else
  {
    ((CtorFlagByte *)(local_11 + 0x7E))->bits.bit_6 = 1;
  }
  if (func_80102FA0(param_2, 0x80000200) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x65))->bits.bit_0 = 0;
  }
  else
  {
    ((CtorFlagByte *)(local_11 + 0x65))->bits.bit_0 = 1;
  }
  /* Placement metadata supplies an 11-bit node index and an extra flag. */
  if (param_4 != 0)
  {
    ((ActorIdBits *)(local_11 + 0x6C))->node = ((ActorIdBits *)(param_4 + 0x10))->node;
    ((CtorFlagByte *)(local_11 + 0x73))->bits.bit_0 = ((CtorTailSource *)(param_4 + 0x10))->flag;
  }
  func_80108658(local_11, ((CtorInfo *)param_2)->flags, ((CtorInfo *)param_2)->flags3C, param_4);
  /* Install rendering/color defaults before the remaining actor setup. */
  ((CtorActor *)local_11)->render = 0x4A0021;
  for (local_1 = 0; local_1 < 3; local_1++)
  {
    ((CtorActor *)local_11)->color[local_1] = 0x63;
  }
  func_800F31FC(local_11 + 0x98, 0xFF, 0xFF, 0xFF, 0xFF);
  if ((((CtorInfo *)param_2)->value40) != 0)
  {
    ((CtorFlagByte *)(local_11 + 0x74))->bits.bit_4 = 1;
  }
  else
  {
    ((CtorFlagByte *)(local_11 + 0x74))->bits.bit_4 = 0;
  }
  ((CtorFlagByte *)(local_11 + 0x74))->bits.bit_3 = 1;
  func_80102424(local_11, ((u32) (*((u16 *) (((s8 *) local_11) + 0x72)))) >> 0xA);
  func_80103930(local_11);
  func_8010A3E8(local_11, 1.0f);
  func_80106E88(local_11);
  func_80104F2C(local_11, func_80102FA0(param_2, 0x40000000), func_80102FA0(param_2, 0x10));
  if (func_800BEC1C() != 0)
  {
    _subaddiezone_entrypoint_0(local_11);
  }
  return local_11;
}

s32 func_80108454(s32 map, s32 exit, s32 direction){
    func_80108C90(map, exit, direction, 0);
}

int func_80108474(s32 param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    func_800EE904(local_0, param_1);
    func_80108C90(param_0, local_0, param_2, 0);
}

s32 func_801084B0(s32 param_0, s32 **param_1)
{
    s32 ergebnis;
    s32 gesichert;
    f32 sp1C[3];
    s32 *p;

    p = *param_1;
    gesichert = *p;
    func_800EE904(sp1C, p + 1);
    ergebnis = func_80108C90(param_0, sp1C,
                             (s32) *(f32 *)((s8 *) (*param_1) + 0x48), 0);
    *param_1 = (s32 *) func_80106790(gesichert);
    return ergebnis;
}

s32 func_80108528(s32 param_0, s32 param_1, s32 param_2, s32 **param_3)
{
    s32 gesichert;
    s32 ergebnis;

    gesichert = **param_3;
    ergebnis = func_80108474(param_0, param_1, param_2);
    *param_3 = (s32 *) func_80106790(gesichert);
    return ergebnis;
}

void func_8010856C(s32 param_0, u8 *param_1, u8 *param_2)
{
  s8 local_1[8];
  s32 local_0;

  func_800EE904((s32 *) ((u8 *) &local_0 - 4), param_1);
  *((f32 *) ((u8 *) func_80108DC0(param_0, (s32 *) ((u8 *) &local_0 - 4), (s32) *((f32 *) (param_2 + 4)), 0, 0, 0) + 0x44)) = *((f32 *) param_2);
}

int func_801085CC(enum actor_e param_0, s16 param_1[3], s32 param_2)
{
  s32 local_0[3];
  int local_1;
  for (local_1 = 0; local_1 < 3; local_1++)
  {
    local_0[local_1] = param_1[local_1];
  }

  return func_80108C90(param_0, &local_0, param_2, 0);
}

int func_80108618(s32 param_0, s32 param_1)
{
  if (func_800DA298(param_1 | 0))
  {
    func_800FFAB0(param_0);
    return 1;
  }
  return 0;
}

void func_80108658(ObjE1510 *p, s32 flags, s32 flags2, NodeE1510 *np)
{
    p->f96 = 0;
    p->u74.b.f74 = p->f96; p->u74.b.f77 = p->f96; p->u78.b.f7B = p->f96;
    if (flags & 0x10000000) {
        p->u78.b.f7B = p->u78.b.f7B + 1;
        if (!p->u70.w.f71_20 && !p->u70.b.f70_01) {
            p->u70.b.f71_20 = 1;
        }
    }
    if (flags & 0x20000000) {
        p->u78.b.f7B = p->u78.b.f7B + 2;
        if (!p->u70.w.f71_20 && !p->u70.b.f70_01) {
            p->u70.b.f71_20 = 1;
        }
    }
    if (flags & 0x2000) {
        if (p->u78.b.f7B == 0) {
            p->u78.b.f7B = 1;
        }
        p->u74.b.f77 = 1;
    }
    if ((flags2 & 0x80010000) == 0x80010000) {
        p->u74.b.f74 = 1;
    }
    if ((flags2 & 0x80080000) == 0x80080000) {
        p->f96 = 1;
    }
    if (np != NULL) {
        if ((flags & 0x30002000) != 0) {
            if (np->unk10_3 != 0) {
            }
        } else {
            p->u78.b.f7B = np->unk10_3;
            p->u74.b.f77 = np->unk10_4;
            if (p->u78.b.f7B != 0 || p->u74.w.f77 != 0) {
                if (!p->u70.w.f71_20 && !p->u70.b.f70_01) {
                    p->u70.b.f71_20 = 1;
                }
            }
        }
    }
    if (p->u78.b.f7B != 0 && p->u70.w.f73_08) {
        func_8010381C();
    }
}

void func_801088A8(ObjE1510 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    param_0->f96 = 0;
    param_0->u74.b.f74 = param_0->f96; param_0->u74.b.f77 = param_0->f96; param_0->u78.b.f7B = param_0->f96;
    if (func_800BF8E4(param_0) != 0) {
        func_80108658(param_0, param_1, param_2, param_3);
    }
}

void func_80108944(ObjE1510 *param_0, ObjE1510 *param_1)
{
    s32 mode;
    s32 extra;
    f32 tmp[3];

    extra = 0;
    mode = 0;
    switch (param_1->u78.b.f7B) {
        case 1:
            mode = 0x10000000;
            break;
        case 2:
            mode = 0x20000000;
            break;
        case 3:
            mode = 0x30000000;
            break;
    }
    if (param_1->u74.w.f77) {
        mode |= 0x2000;
    }
    if (param_1->u78.w.g7B) {
        param_0->u78.b.g7B = 1;
        _subaddiefade_entrypoint_9(param_1, tmp);
        _subaddiefade_entrypoint_11(param_0, tmp);
    }
    if (param_1->f96) {
        extra = 0x80080000;
    }
    func_80108658(param_0, mode, extra, 0);
}

int func_80108A30(s32 param_0, s32 *param_1, s32 param_2, s32 param_3)
{
  _chbaddiesetup_entrypoint_6(&func_80108A8C, param_0 | 0, param_1[0], param_1[1], param_1[2], param_2, param_3);
}

void func_80108A8C(param_0, x, y, z, yaw, param_5) s32 param_0; s32 x; s32 y; s32 z; s32 yaw; s32 param_5;
{
    f32 pos[3];
    f32 s;
    ActorA8C *a;
    pos[0] = reinterpret_cast(f32, x);
    pos[1] = reinterpret_cast(f32, y);
    pos[2] = reinterpret_cast(f32, z);
    s = reinterpret_cast(f32, yaw);
    a = func_80108474(param_0, pos, (s32) s);
    if (a != NULL) {
        a->unk48 = s;
        a->unk76 = param_5;
    }
}

void func_80108B04(u8 **param_0, s32 param_1)
{
  u8 *local_0;
  u8 **new_var;
  new_var = param_0;
  if (1)
  {
    ;
    _chbaddiesetup_entrypoint_3(&func_80108B44, *new_var, param_1, ((u32) (*((u16 *) ((*param_0) + 0x12)))) >> 1);
  }
}

int func_80108B44(u16 *param_0, u32 param_1, int param_2)
{
  if (((u32)param_0[9] >> 1) == param_2 && func_801069A4(param_0))
  {
    func_8010114C(param_0, 0x3D, param_1);
  }
}

int func_80108B8C(u16 *param_0, u32 param_1, int param_2)
{
  if (((u32)param_0[9] >> 1) == param_2 && func_801069A4(param_0))
  {
    func_8010114C(param_0, 0x59, param_1);
  }
}

void func_80108BD4(u8 **param_0, s32 param_1)
{
  u8 *local_0;
  u8 **new_var;
  new_var = param_0;
  if (1)
  {
    ;
    _chbaddiesetup_entrypoint_3(&func_80108B8C, *new_var, param_1, ((u32) (*((u16 *) ((*param_0) + 0x12)))) >> 1);
  }
}

void func_80108C14(void)
{
  s32 local_0;
  u16 local_1;
  s32 *local_4;
  local_4 = func_801067C4(&local_0);
  if (local_4 != 0)
  {
    do
    {
      local_1 = (*((u16 *) (((char *) func_80100368(local_4)) + 0x20))) ^ 0;
      if ((local_1 != 0) && (func_800DA298(local_1 & 0xFFFF) != 0))
      {
        func_800FFAB0(local_4);
        func_800819B4(*((s32 *) (((char *) local_4) + 0x10)));
      }
      local_4 = func_8010682C(&local_0);
    }
    while (local_4 != 0);
  }
}

int func_80108C90(s32 param_0, s32 param_1, s32 param_2, void *param_3) {
    s32 local_0;
    s32 local_1;
    local_0 = _gemarkersDll_entrypoint_0(param_0);
    if (!local_0) return 0;
    local_1 = ((s32 (*)(void))local_0)();
    return ((s32 (*)(s32, s32, s32, s32, void *))(*(s32 **)((char *)local_1 + 0x38)))(param_1, param_2, local_1, local_0, param_3);
}

NodePropE1510 *func_80108CF4(s32 arg0)
{
    NodePropE1510 *var_v0;
    u32 sp20;
    u32 var_v1;

    var_v0 = _gccubesearch_entrypoint_17(arg0, 0);
    sp20 = 1;
    while ((var_v0 != NULL) && ((sp20 == 1) || (var_v0->bit0 == 1)) && (var_v0->unk10_19 != 0)) {
        var_v1 = var_v0->unk10_19;
        var_v0 = _gccubesearch_entrypoint_17(var_v1, 0);
        sp20 = 0;
    }
    return ((sp20 == 1) || (var_v0 == NULL) || (var_v0->bit0 == 1)) ? NULL : var_v0;
}

ActorE1510 *func_80108DC0(s32 arg0, s32 *position, s32 yaw, s32 arg3, s32 arg4, s32 arg5)
{
    ActorE1510 *actor;
    s32 index;
    void *tmp;
    s32 sp38[3];
    f32 v[3];
    PropE1510 *p;

    actor = func_80108C90(arg0, position, yaw, arg5);
    if (actor != NULL) {
        tmp = func_80108CF4(arg3);
        if (tmp != NULL) {
            _gspropctrl_entrypoint_9(tmp, sp38);
            index = _glsplinefind_entrypoint_4(position, sp38);
        } else {
            index = _glsplinefind_entrypoint_2(position);
        }
        if (index >= 0) {
            p = func_8010556C(actor);
            p->index = index;
            v[0] = (f32) position[0];
            v[1] = (f32) position[1];
            v[2] = (f32) position[2];
            p->unk0C = func_800C82CC(func_800D7520(index), v);
            actor->unk77_4 = 1;
        }
    }
    return actor;
}
