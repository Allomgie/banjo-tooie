#include "common.h"

typedef struct {
    u8 pad0[0x24];
    s32 fx; // reverb/effect unit
    u8 pad28[0x20];
} TTVoice48;

typedef struct {
    u8 pad0[0x34];
    TTVoice48 *aux_bus; // stride 0x48
} TTAudioMgr;

extern TTAudioMgr *D_800411F4;
extern void func_80028DF0(s32 *, s32, s32, s32);

// n_alSynAllocFX: create the FX unit for aux bus idx
s32 func_80027220(s16 idx, s32 config, s32 heap)
{
    func_80028DF0(&D_800411F4->aux_bus[idx].fx, config, idx, heap);
    return D_800411F4->aux_bus[idx].fx;
}
