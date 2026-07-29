#include "common.h"

/* func_800295D0 (TU core1/1E41100): Audio-RSP-Command-Builder (Acmd-Paar 0x0D.../0x062E...).
 * Post-Increment-Makro-Muster. -g-Axiom-Kampagne. */

typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd;

typedef struct {
    u8 pad0[0x48];
    u32 unk48;             /* 0x48 */
} TTAMgrX;

extern TTAMgrX *D_800411F4;
extern TTAcmd *func_8002C230(void *, TTAcmd *);

TTAcmd *func_800295D0(void *arg0, TTAcmd *p)
{
    TTAcmd *cmd = p;
    TTAcmd *c1;
    TTAcmd *c2;

    cmd = func_8002C230(arg0, cmd);

    c1 = cmd++;
    c1->w0 = 0x0D000000;

    c2 = cmd++;
    c2->w0 = 0x062E0000;
    c2->w1 = D_800411F4->unk48;

    return cmd;
}
