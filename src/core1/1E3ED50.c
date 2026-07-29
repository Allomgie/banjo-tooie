#include "common.h"

/* func_80027220 (TU core1/1E3ED50): Voice-Param-Getter ueber globalen Audio-Manager
 * D_800411F4 (Array-Feld @0x34, Stride 0x48, Ziel-Feld @0x24). Axiom-Test TU #3. */

typedef struct {
    u8 pad0[0x24];
    s32 unk24;             /* 0x24 */
    u8 pad28[0x20];        /* -> sizeof 0x48 */
} TTVoice48;

typedef struct {
    u8 pad0[0x34];
    TTVoice48 *unk34;      /* 0x34 */
} TTAudioMgr;

extern TTAudioMgr *D_800411F4;
extern void func_80028DF0(s32 *, s32, s32, s32);

s32 func_80027220(s16 idx, s32 arg1, s32 arg2)
{
    func_80028DF0(&D_800411F4->unk34[idx].unk24, arg1, idx, arg2);
    return D_800411F4->unk34[idx].unk24;
}
