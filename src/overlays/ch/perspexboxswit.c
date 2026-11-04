// Probably the switch that opens the perspex boxes: only Banjo or Banjo-Kazooie can press it
// (flag 0x43A); it then shatters all perspex boxes (actor 0x4C0) and plays a short camera pod.
#include "common.h"

extern void *D_808000D0_chperspexboxswitch;

// Message 7 (switch pressed): tells all perspex boxes (actor 0x4C0) to shatter and starts a camera pod.
int func_80800000_chperspexboxswitch(s32 actor[3], s32 msg, s32 payload)
{
    if (msg == 7) {
        func_80101180(0x4C0, 7, 0);
        _capod_entrypoint_13(actor[0], 0, 0xE, 0x10);
        _chswitch_entrypoint_10(actor, msg, payload);
    } else {
        // Matching: the `| 0` operand is needed for the match.
        _chswitch_entrypoint_10(actor, msg | 0, payload);
    }
}

// Init: generic switch (flag 0x43A) that only Banjo and Banjo-Kazooie can press.
s32 func_80800080_chperspexboxswitch(s32 actor)
{
    _chswitch_entrypoint_7(actor, 0x43A);
    _chswitch_entrypoint_8(actor, 0x201);
    _chswitch_entrypoint_9(actor);
    func_80104E78(actor);
}

int chperspexboxswitch_entrypoint_0()
{
    return &D_808000D0_chperspexboxswitch;
}

extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void _chswitch_entrypoint_2();
extern void func_80107C2C();
// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to functions of
// this file; IDO's assembler schedules some of them differently unless the tables are in the same
// unit.
void *D_808000D0_chperspexboxswitch =(void *) 0x034304C1;
static u32 D_808000D0_chperspexboxswitch_rest[19] = {0x7B80001,
                                                     0x8011A220,
                                                     (u32) _chswitch_entrypoint_6,
                                                     (u32) func_80105834,
                                                     (u32) func_80101870,
                                                     0x0,
                                                     0x0,
                                                     0x0,
                                                     0x40000808,
                                                     0x0,
                                                     (u32) _chswitch_entrypoint_2,
                                                     0x0,
                                                     (u32) func_80800080_chperspexboxswitch,
                                                     (u32) func_80107C2C,
                                                     0x80082C12,
                                                     (u32) func_80800000_chperspexboxswitch,
                                                     0x0,
                                                     0x0,
                                                     0x0};
