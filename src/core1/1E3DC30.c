// Probably Rare's extensions to the sequence player: channel mask and state reset, and
// helpers that send custom MIDI controller messages (0xFC, 0xFF, 0x41) to a channel.
#include "common.h"

typedef struct {
    u8 pad0[0x9];
    u8 unk9;
    u8 unkA;
    u8 padB[0x38 - 0xB];
} TTVc38;
typedef struct {
    u8 pad0[0x30];
    s32 chan_mask; // 0x30
    u8 pad34[2];
    u8 num_chans; // 0x36
    u8 pad37[0x60 - 0x37];
    TTVc38 *chans; // 0x60, stride 0x38
} TTSeqObj;
extern void func_8002ACE0(TTSeqObj *, s32, s32, s32, s32, s32);

// Resets the channel mask and per-channel state bytes.
void func_80026100(TTSeqObj *seqp)
{
    s32 i;

    seqp->chan_mask = -1;
    for (i = 0; i < seqp->num_chans; i++) {
        seqp->chans[i].unkA = 0xFF;
        seqp->chans[i].unk9 = 0xFF;
    }
}

// Sends MIDI controller 0xFC (Rare custom) with value 0.
void func_80026188(TTSeqObj *seqp, s32 chan)
{
    func_8002ACE0(seqp, 0, 0xB0, chan, 0xFC, 0);
}

// Sets the channel's mask bit, then sends controller 0xFC with 0xFF.
void func_800261D0(TTSeqObj *seqp, s32 chan)
{
    seqp->chan_mask = seqp->chan_mask | (1 << chan);
    func_8002ACE0(seqp, 0, 0xB0, chan, 0xFC, 0xFF);
}

// Sends MIDI controller 0xFF (Rare custom).
void func_80026238(TTSeqObj *seqp, s32 chan, u8 val, s32 unused)
{
    func_8002ACE0(seqp, 0, 0xB0, chan, 0xFF, val);
}

// Sends MIDI controller 0x41.
void func_8002628C(TTSeqObj *seqp, s32 chan, u8 val)
{
    func_8002ACE0(seqp, 0, 0xB0, chan, 0x41, val);
}

// Sends MIDI controller 0xFC (Rare custom).
void func_800262DC(TTSeqObj *seqp, s32 chan, u8 val)
{
    func_8002ACE0(seqp, 0, 0xB0, chan, 0xFC, val);
}
