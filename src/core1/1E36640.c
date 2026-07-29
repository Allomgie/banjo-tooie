#include "common.h"
#ifndef M2C_MACROS_H
#define M2C_MACROS_H
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK() (0)
#define M2C_SYNC() (0)
#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define DMULT_HI(a, b) (0)
#define DMULTU_HI(a, b) (0)
#define CLZ(x) (0)
#define REVERSE_BITS(x) (0)
#define ROTATE_RIGHT(x, shift) (0)
#define ARM_RRX(x, carry) (0)
#define BSWAP32(x) (0)
#define BSWAP16(x) (0)
#define BSWAP16X2(x) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define M2C_MEMCPY_ALIGNED memcpy
#define M2C_MEMCPY_UNALIGNED memcpy
#define M2C_STRUCT_COPY memcpy
#endif
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct { s16 type; /* 0x0 */ u8 pad2[0xE]; } TTEvtC;
typedef struct TTSndI_s { u8 pad0[0x48]; } TTSndI;
typedef struct { s32 unk0; /* 0x00 */ void *unk4; /* 0x04 */ void *unk8; /* 0x08: Handler-Fptr */ u8 padC[8]; u8 evtq14; /* 0x14 */ u8 pad15[0x13]; TTEvtC unk28; /* 0x28 */ u8 pad38[4]; s32 unk3C; /* 0x3C */ TTSndI *unk40; /* 0x40 */ void *unk44; /* 0x44 */ s32 unk48; /* 0x48 */ s32 unk4C; /* 0x4C */ } TTCSMgr;
typedef struct { u32 unk0; /* 0x00 */ u32 unk4; /* 0x04 */ void *unk8; /* 0x08 */ void *unkC; /* 0x0C: Heap */ u16 unk10; /* 0x10 */ } TTCfgI;
extern TTSndI *D_800411D8;
extern void *func_80020EE4(s32, s32, void *, s32, s32);
extern void func_800263C0(void *, void *, s32);
extern void func_80020E40(void *, void *);
extern void func_800267F0();
extern s32 func_8002645C(void *, TTEvtC *);
typedef struct { u8 pad0[0x14]; u8 evtq; /* 0x14: Evtq-Basis */ u8 pad15[0x13]; TTEvtC unk28; /* 0x28: aktuelles Event */ u8 pad38[0x10]; s32 unk48; /* 0x48 */ s32 unk4C; /* 0x4C */ s32 unk50; /* 0x50 */ } TTCSPmp;
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
extern u8 *D_800411D4;
extern u8 *D_800411DC;
extern s16 D_800411E0;
extern u8 *D_800411F4;
extern s16 *D_8007EA24;
void func_80026CB0(u8 *, s32, f32, s32, s32, s32, s32, f32, s32, s32);
void func_80026E90(u8 *, f32);
typedef struct { s16 unk0; s16 unk2; s8 unk4; } VConfig;
typedef struct { u16 unk0; u8 pad2[2]; void *unk4; u32 unk8; u8 padC[4]; } Evt;
typedef struct { s16 type; /* 0x0 */ u8 pad2[2]; void *p; /* 0x4 */ s32 data; /* 0x8 */ u8 padC[4]; } TTEvtK2;
typedef struct TTSnd_s { struct TTSnd_s *unk0; /* 0x00 */ u8 pad4[4]; void *unk8; /* 0x08 */ u8 padC[0x38]; u8 unk44; /* 0x44 */ } TTSnd;
typedef struct { u8 pad0[0x14]; u8 evtq; /* 0x14 */ } TTSMgr;
extern TTSnd *D_800411D0;
extern void func_80026500(void *, TTEvtK2 *, s32, s32);
typedef struct { u8 pad0[0xC]; u8 unkC; /* 0x0C */ } TTSndB_800200B8;
extern void func_80026FF0(void *);
extern void func_80027090(void *);
typedef struct { u8 pad0[0x8]; void *unk8; /* 0x08 */ u8 padC[0x20]; f32 unk2C; /* 0x2C */ } TTSndP;
typedef struct { u8 pad0[0x15]; s8 unk15; /* 0x15 */ } TTWaveP;
extern f32 func_80027170(s32);
typedef struct TTLinkS_s { struct TTLinkS_s *next; struct TTLinkS_s *prev; } TTLinkS;
typedef struct { u16 type; /* 0x0 */ u8 pad2[2]; void *p; /* 0x4 */ } TTEvtF;
typedef struct TTItemS_s { struct TTItemS_s *unk0; /* 0x00 */ u8 pad4[4]; s32 unk8; /* 0x08 */ TTEvtF evt; /* 0x0C */ } TTItemS;
typedef struct { TTLinkS freeList; /* 0x00 */ TTItemS *unk8; /* 0x08 */ } TTEvtqS;
extern void func_80020E74(void *);
typedef struct TTSndL_s { struct TTSndL_s *unk0; /* 0x00 */ struct TTSndL_s *unk4; /* 0x04 */ } TTSndL;
typedef struct { u8 pad0[3]; u8 unk3; /* 0x03 */ u8 unk4; /* 0x04 */ s8 unk5; /* 0x05 */ } TTPrmSub;
typedef struct { u8 pad0[4]; s32 unk4; /* 0x04 */ u8 pad8[8]; TTPrmSub unk10; /* 0x10 */ } TTPrmA;
typedef struct TTSndA_s { struct TTSndA_s *unk0; /* 0x00 */ struct TTSndA_s *unk4; /* 0x04 */ void *unk8; /* 0x08 */ u8 padC[0x1C]; f32 unk28; /* 0x28 */ f32 unk2C; /* 0x2C */ s32 unk30; /* 0x30 */ s32 unk34; /* 0x34 */ s16 unk38; /* 0x38 */ u8 pad3A[6]; u8 unk40; /* 0x40 */ u8 unk41; /* 0x41 */ u8 unk42; /* 0x42 */ u8 pad43[1]; u8 unk44; /* 0x44 */ u8 unk45; /* 0x45 */ } TTSndA;
extern void func_800E9070(void *, s32);
typedef struct TTSndU_s { struct TTSndU_s *unk0; /* 0x00 */ struct TTSndU_s *unk4; /* 0x04 */ void *unk8; /* 0x08 */ u8 padC[0x24]; struct TTSndU_s **unk30; /* 0x30 */ u8 pad34[0x10]; u8 unk44; /* 0x44 */ u8 unk45; /* 0x45 */ } TTSndU;
extern void func_800E90A4(void *, s32);
typedef struct { s16 type; /* 0x0 */ u8 pad2[2]; void *p; /* 0x4 */ u8 pad8[8]; } TTEvtK1;
typedef struct { u8 unk0; /* 0x00: Folge-ID low */ u8 pad1[1]; u8 unk2; /* 0x02: Flags */ } TTPrmSubB;
typedef struct { u8 pad0[0x10]; TTPrmSubB unk10; /* 0x10 */ u8 unk11_pad[0]; } TTPrmB;
typedef struct { u8 pad0[0x11]; u8 unk11; /* 0x11: Dauer in Ticks */ } TTPrmB2;
typedef struct TTSndB_s { struct TTSndB_s *unk0; /* 0x00 */ u8 pad4[0x28]; f32 unk2C; /* 0x2C */ void *unk30; /* 0x30 */ u8 pad34[4]; s16 unk38; /* 0x38 */ u8 pad3A[7]; u8 unk41; /* 0x41 */ u8 unk42; /* 0x42 */ u8 unk43; /* 0x43 */ u8 unk44; /* 0x44 */ } TTSndB_80020790;
typedef struct { u8 pad0[0x14]; u8 evtq14; /* 0x14 */ u8 pad15[0x27]; TTSndB_80020790 *unk3C; /* 0x3C */ } TTSMgrB;
extern void *func_800E9320(s32, s32);
typedef struct { u8 pad0[0x12]; u8 unk12; /* 0x12 */ } TTWaveC;
extern void *D_800411F0;
extern void func_80020F70(void *);
extern void func_80027200(void);

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
s32 func_8001ED68(TTCSPmp *arg0);
void func_8001EE34(u16 *arg0);
void func_800200B8(TTSnd *p);
void func_80020128(TTSndP *snd);
void func_800201A4(TTEvtqS *evtq, void *match, u16 mask);
u16 func_80020298(u16 *outStopped, u16 *outPlaying);
void func_800205D0(TTSndU *p);
TTSndB_80020790 *func_80020790(s16 id, u16 vol, u8 pan, f32 pitchMul, u8 a4, u8 a5, TTSndB_80020790 **out);

void func_8001EB10(TTCfgI *cfg)
{
    u32 i;
    void *mem;
    TTEvtC evt;
    TTSndI *s;

    ((TTCSMgr *) D_800411DC)->unk44 = cfg->unk8;
    ((TTCSMgr *) D_800411DC)->unk3C = 0;
    ((TTCSMgr *) D_800411DC)->unk48 = 0x3E80;

    mem = func_80020EE4(0, 0, cfg->unkC, 1, cfg->unk0 * 0x48);
    ((TTCSMgr *) D_800411DC)->unk40 = mem;

    mem = func_80020EE4(0, 0, cfg->unkC, 1, cfg->unk4 * 0x1C);
    func_800263C0(&((TTCSMgr *) D_800411DC)->evtq14, mem, cfg->unk4);

    D_800411D8 = ((TTCSMgr *) D_800411DC)->unk40;

    for (i = 1; i < cfg->unk0; i++) {
        s = ((TTCSMgr *) D_800411DC)->unk40;
        func_80020E40(&s[i], &s[i] - 1);
    }

    D_8007EA24 = func_80020EE4(0, 0, cfg->unkC, 2, cfg->unk10);

    for (i = 0; i < cfg->unk10; i++) {
        ((u16 *) D_8007EA24)[i] = 0x7FFF;
    }

    ((TTCSMgr *) D_800411DC)->unk0 = 0;
    ((TTCSMgr *) D_800411DC)->unk8 = func_8001ED68;
    ((TTCSMgr *) D_800411DC)->unk4 = ((TTCSMgr *) D_800411DC);

    func_800267F0(((TTCSMgr *) D_800411DC));

    evt.type = 0x20;
    func_80026500(&((TTCSMgr *) D_800411DC)->evtq14, &evt, ((TTCSMgr *) D_800411DC)->unk48, 1);
    ((TTCSMgr *) D_800411DC)->unk4C = func_8002645C(&((TTCSMgr *) D_800411DC)->evtq14, &((TTCSMgr *) D_800411DC)->unk28);
}

s32 func_8001ED68(TTCSPmp *arg0)
{
    TTCSPmp *v = arg0;
    TTEvtC evt;

    do {
        switch (v->unk28.type) {
        case 0x20:
            evt.type = 0x20;
            func_80026500(&v->evtq, &evt, v->unk48, 1);
            break;
        default:
            func_8001EE34(&v->unk28);
            break;
        }

        v->unk4C = func_8002645C(&v->evtq, &v->unk28);
    } while (v->unk4C == 0);

    v->unk50 = v->unk50 + v->unk4C;
    return v->unk4C;
}

void func_8001EE34(u16 *arg0)
{
  VConfig config;
  u8 *spAC;
  u8 *spA8;
  u8 spA7;
  Evt sp94e;
  Evt sp84e;
  s32 sp80;
  s32 sp7C;
  s32 sp78;
  s32 sp74;
  s32 sp70;
  s32 sp6C;
  s32 sp68;
  s32 sp64;
  u8 *sp60;
  u8 *sp5C;
  s16 sp5A;
  s16 sp58;
  u8 *sp54;
  Evt sp44e;
  sp68 = 1;
  sp64 = 0;
  sp60 = 0;
  sp5C = 0;
  do
  {
    if (sp5C != 0)
    {
      sp84e.unk4 = sp60;
      sp84e.unk0 = *((u16 *) (((s8 *) arg0) + 0));
      sp84e.unk8 = *((u32 *) (((s8 *) arg0) + 8));
      arg0 = (u16 *) (&sp84e);
    }
    sp60 = *((u8 **) (((s8 *) arg0) + 4));
    spAC = *((u8 **) (((s8 *) sp60) + 8));
    if (spAC == 0)
    {
      func_80020298(&sp5A, &sp58);
      return;
    }
    spA8 = spAC + 0x10;
    sp5C = *((u8 **) (((s8 *) sp60) + 0));
    switch ((s32) (*((u16 *) (((s8 *) arg0) + 0))))
    {
      case 0x1:
        if (((*((u8 *) (((s8 *) sp60) + 0x45))) != 5) && ((*((u8 *) (((s8 *) sp60) + 0x45))) != 4))
      {
        return;
      }
        config.unk2 = (s16) (*((u8 *) (sp60 + 0x43)));
        config.unk0 = (s16) (*((u8 *) (((s8 *) sp60) + 0x40)));
        config.unk4 = 0;
        sp70 = D_800411E0 >= (*((s32 *) (((s8 *) D_800411DC) + 0x44)));
        if ((sp70 == 0) || ((*((u8 *) (((s8 *) sp60) + 0x44))) & 0x10))
      {
        sp64 = func_800268D0(sp60 + 0xC, &config);
      }
        if (sp64 == 0)
      {
        if (((*((u8 *) (((s8 *) sp60) + 0x44))) & 0x12) || ((*((s32 *) (((s8 *) sp60) + 0x34))) > 0))
        {
          *((u8 *) (((s8 *) sp60) + 0x45)) = 4U;
          *((s32 *) (((s8 *) sp60) + 0x34)) = (s32) ((*((s32 *) (((s8 *) sp60) + 0x34))) - 1);
          func_80026500(D_800411DC + 0x14, arg0, 0x8235, 0);
        }
        else
          if (sp70 != 0)
        {
          sp54 = D_800411D4;
          do
          {
            if (((!((*((u8 *) (((s8 *) sp54) + 0x44))) & 0x12)) && ((*((u8 *) (((s8 *) sp54) + 0x44))) & 4)) && ((*((u8 *) (((s8 *) sp54) + 0x45))) != 3))
            {
              sp70 = 0;
              sp44e.unk0 = 0x80;
              sp44e.unk4 = sp54;
              *((u8 *) (((s8 *) sp54) + 0x45)) = 3U;
              func_80026500(D_800411DC + 0x14, &sp44e, 0x3E8, 0);
              func_80026BE0(sp54 + 0xC, 0, 0x3E8);
            }
            sp54 = *((u8 **) (((s8 *) sp54) + 4));
          }
          while ((sp70 != 0) && (sp54 != 0));
          if (sp70 == 0)
          {
            *((s32 *) (((s8 *) sp60) + 0x34)) = 2;
            func_80026500(D_800411DC + 0x14, arg0, 0x3E9, 0);
          }
          else
          {
            func_800200B8(sp60);
          }
        }
        else
        {
          func_800200B8(sp60);
        }
        return;
      }
        *((u8 *) (((s8 *) sp60) + 0x44)) = (u8) ((*((u8 *) (((s8 *) sp60) + 0x44))) | 4);
        *((s16 *) (((s8 *) sp60) + 0x3A)) = (s16) (*((u8 *) (((s8 *) spAC) + 0xC)));
        *((u8 *) (((s8 *) sp60) + 0x43)) = (u8) config.unk2;
        sp80 = (s32) ((((f32) (*((s32 *) (((s8 *) spAC) + 0)))) / (*((f32 *) (((s8 *) sp60) + 0x2C)))) / (*((f32 *) (((s8 *) sp60) + 0x28))));
        *((s32 *) (((s8 *) sp60) + 0x3C)) = (s32) ((*((s32 *) (((s8 *) D_800411DC) + 0x50))) + sp80);
        if ((((s32) (((((*((s16 *) (((s8 *) sp60) + 0x3A))) * (*((s16 *) (((s8 *) sp60) + 0x38)))) * (*((u8 *) (((s8 *) spAC) + 0xD5)))) / 16129) * D_8007EA24[(*((u8 *) (((s8 *) spA8) + 2))) & 0x1F])) / 32767) <= 0)
      {
        sp78 = 0;
      }
      else
      {
        sp78 = (((s32) (((((*((s16 *) (((s8 *) sp60) + 0x3A))) * (*((s16 *) (((s8 *) sp60) + 0x38)))) * (*((u8 *) (((s8 *) spAC) + 0xD5)))) / 16129) * D_8007EA24[(*((u8 *) (((s8 *) spA8) + 2))) & 0x1F])) / 32767) - 1;
      }
        sp74 = ((*((u8 *) (((s8 *) spAC) + 0xD4))) + (*((u8 *) (((s8 *) sp60) + 0x41)))) - 0x40;
        spA7 = (u8) ((((sp74 > 0) ? (sp74) : (0)) < 0x7F) ? ((sp74 > 0) ? (sp74) : (0)) : (0x7F));
        sp7C = (((*((u8 *) (((s8 *) spA8) + 3))) & 0xF) * 8) + ((*((u8 *) (((s8 *) sp60) + 0x42))) & 0x7F);
        sp7C = (127 < ((0 > sp7C) ? (0) : (sp7C))) ? (127) : ((0 > sp7C) ? (0) : (sp7C));
        sp7C |= (*((u8 *) (((s8 *) sp60) + 0x42))) & 0x80;
        func_80026CB0(sp60 + 0xC, spAC + 0x18, (*((f32 *) (((s8 *) sp60) + 0x28))) * (*((f32 *) (((s8 *) sp60) + 0x2C))), sp78, (s32) spA7, sp7C, 0, 0.0f, 0, sp80);
        *((u8 *) (((s8 *) sp60) + 0x45)) = 1U;
        D_800411E0 += 1;
        if (!((*((u8 *) (((s8 *) sp60) + 0x44))) & 2))
      {
        if (sp80 == 0)
        {
          *((s16 *) (((s8 *) sp60) + 0x3A)) = (s16) (*((u8 *) (((s8 *) spAC) + 0xD)));
          if ((((s32) (((((*((s16 *) (((s8 *) sp60) + 0x3A))) * (*((s16 *) (((s8 *) sp60) + 0x38)))) * (*((u8 *) (((s8 *) spAC) + 0xD5)))) / 16129) * D_8007EA24[(*((u8 *) (((s8 *) spA8) + 2))) & 0x1F])) / 32767) <= 0)
          {
            sp78 = 0;
          }
          else
          {
            sp78 = (((s32) (((((*((s16 *) (((s8 *) sp60) + 0x3A))) * (*((s16 *) (((s8 *) sp60) + 0x38)))) * (*((u8 *) (((s8 *) spAC) + 0xD5)))) / 16129) * D_8007EA24[(*((u8 *) (((s8 *) spA8) + 2))) & 0x1F])) / 32767) - 1;
          }
          sp80 = (s32) ((((f32) (*((s32 *) (((s8 *) spAC) + 4)))) / (*((f32 *) (((s8 *) sp60) + 0x28)))) / (*((f32 *) (((s8 *) sp60) + 0x2C))));
          *((s32 *) (((s8 *) sp60) + 0x3C)) = (s32) ((*((s32 *) (((s8 *) D_800411DC) + 0x50))) + sp80);
          func_80026BE0(sp60 + 0xC, sp78, sp80);
          sp94e.unk0 = 2;
          sp94e.unk4 = sp60;
          func_80026500(D_800411DC + 0x14, &sp94e, sp80, 0);
          if ((*((u8 *) (((s8 *) sp60) + 0x44))) & 0x20)
          {
            func_80020128(sp60);
          }
        }
        else
        {
          sp94e.unk0 = 0x40;
          sp94e.unk4 = sp60;
          sp80 = (s32) ((((f32) (*((s32 *) (((s8 *) spAC) + 0)))) / (*((f32 *) (((s8 *) sp60) + 0x2C)))) / (*((f32 *) (((s8 *) sp60) + 0x28))));
          func_80026500(D_800411DC + 0x14, &sp94e, sp80, 0);
        }
      }
        break;

      case 0x2:
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;
        ;

      case 0x400:

      case 0x1000:
        if (((*((u16 *) (((s8 *) arg0) + 0))) != 0x1000) || ((*((u8 *) (((s8 *) sp60) + 0x44))) & 2))
      {
        switch (*((u8 *) (((s8 *) sp60) + 0x45)))
        {
          case 1:
            func_800201A4(D_800411DC + 0x14, sp60, 0x40);
            sp80 = (s32) ((((f32) (*((s32 *) (((s8 *) spAC) + 8)))) / (*((f32 *) (((s8 *) sp60) + 0x28)))) / (*((f32 *) (((s8 *) sp60) + 0x2C))));
            func_80026BE0(sp60 + 0xC, 0, sp80);
            if (sp80 != 0)
          {
            sp94e.unk0 = 0x80;
            sp94e.unk4 = sp60;
            func_80026500(D_800411DC + 0x14, &sp94e, sp80, 0);
            *((u8 *) (((s8 *) sp60) + 0x45)) = 2U;
          }
          else
          {
            func_800200B8(sp60);
          }
            break;

          case 4:
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;

          case 5:
            func_800200B8(sp60);
            break;

          default:
            break;

        }

        if ((*((u16 *) (((s8 *) arg0) + 0))) == 2)
        {
          *((u16 *) (((s8 *) arg0) + 0)) = 0x1000;
        }
      }
        break;

      case 0x4:
        *((u8 *) (((s8 *) sp60) + 0x41)) = (u8) (*((u32 *) (((s8 *) arg0) + 8)));
        if ((*((u8 *) (((s8 *) sp60) + 0x45))) == 1)
      {
        sp74 = ((*((u8 *) (((s8 *) spAC) + 0xD4))) + (*((u8 *) (((s8 *) sp60) + 0x41)))) - 0x40;
        spA7 = (u8) ((((sp74 > 0) ? (sp74) : (0)) < 0x7F) ? ((sp74 > 0) ? (sp74) : (0)) : (0x7F));
        func_80026DE0(sp60 + 0xC, spA7);
      }
        break;

      case 0x10:
        *((f32 *) (((s8 *) sp60) + 0x2C)) = *((f32 *) (((s8 *) arg0) + 8));
        if ((*((u8 *) (((s8 *) sp60) + 0x45))) == 1)
      {
        func_80026E90(sp60 + 0xC, (*((f32 *) (((s8 *) sp60) + 0x28))) * (*((f32 *) (((s8 *) sp60) + 0x2C))));
        if ((*((u8 *) (((s8 *) sp60) + 0x44))) & 0x20)
        {
          func_80020128(sp60);
        }
      }
        break;

      case 0x100:
        *((u8 *) (((s8 *) sp60) + 0x42)) = (u8) (*((u32 *) (((s8 *) arg0) + 8)));
        if ((*((u8 *) (((s8 *) sp60) + 0x45))) == 1)
      {
        sp7C = (((*((u8 *) (((s8 *) spA8) + 3))) & 0xF) * 8) + ((*((u8 *) (((s8 *) sp60) + 0x42))) & 0x7F);
        sp7C = (127 < ((0 > sp7C) ? (0) : (sp7C))) ? (127) : ((0 > sp7C) ? (0) : (sp7C));
        sp7C |= (*((u8 *) (((s8 *) sp60) + 0x42))) & 0x80;
        func_80026F40(sp60 + 0xC, sp7C);
      }
        break;

      case 0x2000:
        *((u8 *) (((s8 *) sp60) + 0x43)) = (u8) (*((u32 *) (((s8 *) arg0) + 8)));
        if (((s32) (*((u8 *) (((s8 *) sp60) + 0x43)))) >= (*((s32 *) (((s8 *) D_800411F4) + 0x3C))))
      {
        *((u8 *) (((s8 *) sp60) + 0x43)) = 0U;
      }
        if ((*((u8 *) (((s8 *) sp60) + 0x45))) == 1)
      {
        *((s16 *) (((s8 *) sp60) + 0x24)) = (s16) (*((u8 *) (((s8 *) sp60) + 0x43)));
      }
        break;

      case 0x8:
        *((s16 *) (((s8 *) sp60) + 0x38)) = (s16) (*((u32 *) (((s8 *) arg0) + 8)));
        if ((*((u8 *) (((s8 *) sp60) + 0x45))) == 1)
      {
        if ((((s32) (((((*((s16 *) (((s8 *) sp60) + 0x3A))) * (*((s16 *) (((s8 *) sp60) + 0x38)))) * (*((u8 *) (((s8 *) spAC) + 0xD5)))) / 16129) * D_8007EA24[(*((u8 *) (((s8 *) spA8) + 2))) & 0x1F])) / 32767) <= 0)
        {
          sp78 = 0;
        }
        else
        {
          sp78 = (((s32) (((((*((s16 *) (((s8 *) sp60) + 0x3A))) * (*((s16 *) (((s8 *) sp60) + 0x38)))) * (*((u8 *) (((s8 *) spAC) + 0xD5)))) / 16129) * D_8007EA24[(*((u8 *) (((s8 *) spA8) + 2))) & 0x1F])) / 32767) - 1;
        }
        func_80026BE0(sp60 + 0xC, sp78, (0x3E8 > ((*((s32 *) (((s8 *) sp60) + 0x3C))) - (*((s32 *) (((s8 *) D_800411DC) + 0x50))))) ? (0x3E8) : ((*((s32 *) (((s8 *) sp60) + 0x3C))) - (*((s32 *) (((s8 *) D_800411DC) + 0x50)))));
      }
        break;

      case 0x800:
        if ((*((u8 *) (((s8 *) sp60) + 0x45))) == 1)
      {
        sp80 = (s32) ((((f32) (*((s32 *) (((s8 *) spAC) + 8)))) / (*((f32 *) (((s8 *) sp60) + 0x28)))) / (*((f32 *) (((s8 *) sp60) + 0x2C))));
        if ((((s32) (((((*((s16 *) (((s8 *) sp60) + 0x3A))) * (*((s16 *) (((s8 *) sp60) + 0x38)))) * (*((u8 *) (((s8 *) spAC) + 0xD5)))) / 16129) * D_8007EA24[(*((u8 *) (((s8 *) spA8) + 2))) & 0x1F])) / 32767) <= 0)
        {
          sp78 = 0;
        }
        else
        {
          sp78 = (((s32) (((((*((s16 *) (((s8 *) sp60) + 0x3A))) * (*((s16 *) (((s8 *) sp60) + 0x38)))) * (*((u8 *) (((s8 *) spAC) + 0xD5)))) / 16129) * D_8007EA24[(*((u8 *) (((s8 *) spA8) + 2))) & 0x1F])) / 32767) - 1;
        }
        func_80026BE0(sp60 + 0xC, sp78, sp80);
      }
        break;

      case 0x40:
        if (!((*((u8 *) (((s8 *) sp60) + 0x44))) & 2))
      {
        *((s16 *) (((s8 *) sp60) + 0x3A)) = (s16) (*((u8 *) (((s8 *) spAC) + 0xD)));
        if ((((s32) (((((*((s16 *) (((s8 *) sp60) + 0x3A))) * (*((s16 *) (((s8 *) sp60) + 0x38)))) * (*((u8 *) (((s8 *) spAC) + 0xD5)))) / 16129) * D_8007EA24[(*((u8 *) (((s8 *) spA8) + 2))) & 0x1F])) / 32767) <= 0)
        {
          sp78 = 0;
        }
        else
        {
          sp78 = (((s32) (((((*((s16 *) (((s8 *) sp60) + 0x3A))) * (*((s16 *) (((s8 *) sp60) + 0x38)))) * (*((u8 *) (((s8 *) spAC) + 0xD5)))) / 16129) * D_8007EA24[(*((u8 *) (((s8 *) spA8) + 2))) & 0x1F])) / 32767) - 1;
        }
        sp80 = (s32) ((((f32) (*((s32 *) (((s8 *) spAC) + 4)))) / (*((f32 *) (((s8 *) sp60) + 0x28)))) / (*((f32 *) (((s8 *) sp60) + 0x2C))));
        *((s32 *) (((s8 *) sp60) + 0x3C)) = (s32) ((*((s32 *) (((s8 *) D_800411DC) + 0x50))) + sp80);
        func_80026BE0(sp60 + 0xC, sp78, sp80);
        sp94e.unk0 = 2;
        sp94e.unk4 = sp60;
        func_80026500(D_800411DC + 0x14, &sp94e, sp80, 0);
        if ((*((u8 *) (((s8 *) sp60) + 0x44))) & 0x20)
        {
          func_80020128(sp60);
        }
      }
        break;

      case 0x80:
        func_800200B8(sp60);
        break;

      case 0x200:
        if ((*((u8 *) (((s8 *) sp60) + 0x44))) & 0x10)
      {
        func_80020790(*((u32 *) (((s8 *) arg0) + 8)), *((s16 *) (((s8 *) sp60) + 0x38)), *((u8 *) (((s8 *) sp60) + 0x41)), *((f32 *) (((s8 *) sp60) + 0x2C)), (s32) (*((u8 *) (((s8 *) sp60) + 0x42))), (s32) (*((u8 *) (((s8 *) sp60) + 0x43))), *((s32 *) (((s8 *) sp60) + 0x30)));
      }
        break;
      default:
        break;

    }

    sp6C = (*((u16 *) (((s8 *) arg0) + 0))) & 0x2D1;
    if (((sp60 = sp5C) != 0) && (sp6C == 0))
    {
      sp68 = (*((u8 *) (((s8 *) sp60) + 0x44))) & 1;
    }
  }
  while (((sp68 == 0) && (sp60 != 0)) && (sp6C == 0));
}

void func_800200B8(TTSnd *p)
{
    if (p->unk44 & 4) {
        func_80026FF0(&((TTSndB_800200B8 *)p)->unkC);
        func_80027090(&((TTSndB_800200B8 *)p)->unkC);
    }
    func_800205D0(p);
    func_800201A4(&((TTSMgr *) D_800411DC)->evtq, p, 0xFFFF);
}

void func_80020128(TTSndP *snd)
{
    TTEvtK2 evt;
    f32 pitch;

    pitch = func_80027170(((TTWaveP *)snd->unk8)->unk15) * snd->unk2C;
    evt.type = 0x10;
    evt.p = snd;
    evt.data = *(s32 *)&pitch;
    func_80026500(&((TTSMgr *) D_800411DC)->evtq, &evt, 0x8235, 0);
}

void func_800201A4(TTEvtqS *evtq, void *match, u16 mask)
{
    TTItemS *item;
    TTItemS *next;
    TTItemS *thisItem;
    TTItemS *nextItem;
    TTEvtF *evt;
    s32 msk;

    msk = osSetIntMask(1);

    item = evtq->unk8;
    while (item != 0) {
        next = item->unk0;
        thisItem = item;
        nextItem = next;
        evt = &thisItem->evt;
        if (evt->p == match && (evt->type & mask)) {
            if (nextItem != 0) {
                nextItem->unk8 += thisItem->unk8;
            }
            func_80020E74(item);
            func_80020E40(item, evtq);
        }
        item = next;
    }

    osSetIntMask(msk);
}

u16 func_80020298(u16 *outStopped, u16 *outPlaying)
{
    s32 msk;
    u16 na;
    u16 nb;
    u16 nc;
    TTSndL *a;
    TTSndL *b;
    TTSndL *c;

    msk = osSetIntMask(1);

    a = ((TTSndL *) D_800411D0);
    b = ((TTSndL *) D_800411D8);
    c = ((TTSndL *) D_800411D4);

    for (na = 0; a != 0; na++, a = a->unk0) ;
    for (nb = 0; b != 0; nb++, b = b->unk0) ;
    for (nc = 0; c != 0; nc++, c = c->unk4) ;

    *outStopped = nb;
    *outPlaying = na;

    osSetIntMask(msk);

    return nc;
}

TTSndA *func_8002039C(TTPrmA *prm)
{
    TTSndA *s;
    TTPrmSub *pp;
    s32 flag;
    s32 msk;

    pp = &prm->unk10;
    msk = osSetIntMask(1);

    s = ((TTSndA *) D_800411D8);
    if (s != 0) {
        D_800411D8 = s->unk0;
        func_80020E74(s);

        if (((TTSndA *) D_800411D0) != 0) {
            s->unk0 = ((TTSndA *) D_800411D0);
            s->unk4 = 0;
            ((TTSndA *) D_800411D0)->unk4 = s;
            D_800411D0 = s;
        } else {
            s->unk4 = 0;
            s->unk0 = s->unk4;
            D_800411D0 = s;
            D_800411D4 = s;
        }

        osSetIntMask(msk);
        func_800E9070(prm, 0);

        flag = prm->unk4 + 1 == 0;

        s->unk8 = prm;
        s->unk40 = flag + 0x40;
        s->unk45 = 5;
        s->unk2C = 1.0f;
        s->unk34 = 2;
        s->unk44 = pp->unk3 & 0xF0;
        s->unk30 = 0;

        if (s->unk44 & 0x20) {
            s->unk28 = func_80027170(pp->unk4 * 100 - 6000);
        } else {
            s->unk28 = func_80027170(pp->unk4 * 100 + pp->unk5 - 6000);
        }

        if (flag) {
            s->unk44 = s->unk44 | 2;
        }

        s->unk42 = 0;
        s->unk41 = 0x40;
        s->unk38 = 0x7FFF;
    } else {
        osSetIntMask(msk);
    }

    return s;
}

void func_800205D0(TTSndU *p)
{
    s32 msk;

    msk = osSetIntMask(1);

    if (((TTSndU *) D_800411D0) == p)
        D_800411D0 = p->unk0;

    if (((TTSndU *) D_800411D4) == p)
        D_800411D4 = p->unk4;

    func_80020E74(p);

    if (((TTSndU *) D_800411D8) != 0) {
        p->unk0 = ((TTSndU *) D_800411D8);
        p->unk4 = 0;
        ((TTSndU *) D_800411D8)->unk4 = p;
        D_800411D8 = p;
    } else {
        p->unk4 = 0;
        p->unk0 = p->unk4;
        D_800411D8 = p;
    }

    if (p->unk44 & 4) {
        D_800411E0 = D_800411E0 - 1;
    }

    p->unk45 = 0;

    if (p->unk30 != 0) {
        if (*p->unk30 == p)
            *p->unk30 = 0;
        p->unk30 = 0;
    }

    func_800E90A4(p->unk8, 0);

    osSetIntMask(msk);
}

void func_80020738(u8 *param_0, u8 param_1) {
    if (param_0 != NULL) {
        M2C_FIELD(param_0, s8 *, 0x40) = (s8) (s16) param_1;
    }
}

u8 func_80020760(u8 *param_0) {
    if (param_0 != NULL) {
        return M2C_FIELD(param_0, u8 *, 0x45);
    } else {
        return 0U;
    }
}

TTSndB_80020790 *func_80020790(s16 id, u16 vol, u8 pan, f32 pitchMul, u8 a4, u8 a5, TTSndB_80020790 **out)
{
    TTSndB_80020790 *s;
    TTSndB_80020790 *last;
    TTPrmSubB *pp;
    TTPrmB2 *prm;
    s16 nid;
    s32 dur2;
    s32 dur;
    s32 total;
    s32 x;
    TTEvtK1 evt1;
    TTEvtK2 evt2;

    last = 0;
    nid = 0;
    total = 0;

    if (id != 0) {
        do {
            prm = func_800E9320(0, id - 1);
            s = func_8002039C(prm);

            if (s != 0) {
                ((TTSMgrB *) D_800411DC)->unk3C = s;

                evt1.type = 1;
                evt1.p = s;

                x = pan + s->unk41 - 0x40;
                if (x >= 0x80)
                    x = 0x7F;
                else if (x < 0)
                    x = 0;
                s->unk41 = x;

                s->unk38 = (u32)(vol * s->unk38) >> 15;
                s->unk2C *= pitchMul;
                s->unk42 = a4;
                s->unk43 = a5;

                dur = prm->unk11 * 33333;

                if (s->unk44 & 0x10) {
                    s->unk44 = s->unk44 & ~0x10;
                    func_80026500(&((TTSMgrB *) D_800411DC)->evtq14, &evt1, total + 1, 0);
                    dur2 = dur + 1;
                    nid = id;
                } else {
                    func_80026500(&((TTSMgrB *) D_800411DC)->evtq14, &evt1, dur + 1, 0);
                }

                last = s;
            }

            total = total + dur;

            pp = (TTPrmSubB *)((u8 *)prm + 0x10);
            id = pp->unk0 + ((pp->unk2 & 0xC0) << 2);
        } while (id != 0 && s != 0);

        if (last != 0) {
            last->unk44 = last->unk44 | 1;
            last->unk30 = out;

            if (nid != 0) {
                last->unk44 = last->unk44 | 0x10;

                evt2.type = 0x200;
                evt2.p = last;
                evt2.data = nid;
                func_80026500(&((TTSMgrB *) D_800411DC)->evtq14, &evt2, dur2, 0);
            }
        }
    }

    if (out != 0) {
        *out = last;
    }

    return last;
}

void func_80020A60(TTSnd *p)
{
    TTEvtK2 evt;

    evt.type = 0x400;
    evt.p = p;
    if (p != 0) {
        ((TTSnd *)evt.p)->unk44 = ((TTSnd *)evt.p)->unk44 & ~0x10;
        func_80026500(&((TTSMgr *) D_800411DC)->evtq, &evt, 0, 0);
    }
}

void func_80020AD0(mask) u8 mask;
{
    s32 msk;
    TTEvtK2 evt;
    TTSnd *p;

    msk = osSetIntMask(1);
    p = D_800411D0;
    while (p != 0) {
        evt.type = 0x400;
        evt.p = p;
        if ((p->unk44 & mask) == mask) {
            ((TTSnd *)evt.p)->unk44 = ((TTSnd *)evt.p)->unk44 & ~0x10;
            func_80026500(&((TTSMgr *) D_800411DC)->evtq, &evt, 0, 0);
        }
        p = p->unk0;
    }
    osSetIntMask(msk);
}

void func_80020B90(void)
{
    func_80020AD0(1);
}

void func_80020BB8(void)
{
    func_80020AD0(0x11);
}

void func_80020BE0(void)
{
    func_80020AD0(3);
}

void func_80020C08(TTSnd *p, s16 type, s32 data)
{
    TTEvtK2 evt;

    evt.type = type;
    evt.p = p;
    evt.data = data;
    if (p != 0) {
        func_80026500(&((TTSMgr *) D_800411DC)->evtq, &evt, 0, 0);
    }
}

u16 func_80020C74(param_0) u8 param_0; {
    return D_8007EA24[param_0];
}

void func_80020CA0(chan, val) u8 chan; u16 val;
{
    s32 msk;
    TTSnd *p;
    s32 i;
    TTEvtK2 evt;

    msk = osSetIntMask(1);
    p = D_800411D0;
    ((u16 *) D_8007EA24)[chan] = val;
    for (i = 0; p != 0; ) {
        if ((((TTWaveC *)p->unk8)->unk12 & 0x1F) == chan) {
            evt.type = 0x800;
            evt.p = p;
            func_80026500(&((TTSMgr *) D_800411DC)->evtq, &evt, 0, 0);
        }
        (i++, p = p->unk0);
    }
    osSetIntMask(msk);
}

void func_80020D80(void *m, void *cfg)
{
    if (D_800411F0 == 0) {
        D_800411F0 = m;
        if (((void *) D_800411F4) == 0) {
            D_800411F4 = D_800411F0;
            func_80020F70(cfg);
        }
    }
}

void func_80020DEC(s32 arg0)
{
    if (((s32) D_800411F0)) {
        func_80027200();
        D_800411F0 = 0;
        D_800411F4 = 0;
    }
}
