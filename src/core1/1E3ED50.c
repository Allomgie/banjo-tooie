#include "common.h"

typedef struct {
    u8 pad0[0x24];
    s32 unk24;
    u8 pad28[0x20];
} TTVoice48;

typedef struct {
    u8 pad0[0x34];
    TTVoice48 *unk34;
} TTAudioMgr;

extern TTAudioMgr *D_800411F4;
extern void func_80028DF0(s32 *, s32, s32, s32);

s32 func_80027220(s16 idx, s32 arg1, s32 arg2)
{
    func_80028DF0(&D_800411F4->unk34[idx].unk24, arg1, idx, arg2);
    return D_800411F4->unk34[idx].unk24;
}
