#include "common.h"

typedef struct { u8 pad0[0x9]; u8 unk9; /* 0x9 */ u8 unkA; /* 0xA */ u8 padB[0x38 - 0xB]; /* stride 0x38 */ } TTVc38;
typedef struct { u8 pad0[0x30]; s32 unk30; /* 0x30: Kanal-Bitmask */ u8 pad34[2]; u8 unk36; /* 0x36: Anzahl */ u8 pad37[0x60 - 0x37]; TTVc38 *unk60; /* 0x60 */ } TTSeqObj;
extern void func_8002ACE0(TTSeqObj *, s32, s32, s32, s32, s32);

void func_80026100(TTSeqObj *obj)
{
    s32 i;

    obj->unk30 = -1;
    for (i = 0; i < obj->unk36; i++) {
        obj->unk60[i].unkA = 0xFF;
        obj->unk60[i].unk9 = 0xFF;
    }
}

void func_80026188(TTSeqObj *obj, s32 chan)
{
    func_8002ACE0(obj, 0, 0xB0, chan, 0xFC, 0);
}

void func_800261D0(TTSeqObj *obj, s32 chan)
{
    obj->unk30 = obj->unk30 | (1 << chan);
    func_8002ACE0(obj, 0, 0xB0, chan, 0xFC, 0xFF);
}

void func_80026238(TTSeqObj *obj, s32 chan, u8 val, s32 unused)
{
    func_8002ACE0(obj, 0, 0xB0, chan, 0xFF, val);
}

void func_8002628C(TTSeqObj *obj, s32 chan, u8 val)
{
    func_8002ACE0(obj, 0, 0xB0, chan, 0x41, val);
}

void func_800262DC(TTSeqObj *obj, s32 chan, u8 val)
{
    func_8002ACE0(obj, 0, 0xB0, chan, 0xFC, val);
}
