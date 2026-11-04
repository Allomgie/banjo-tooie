// Possibly a breakable statue next to a Mumbo pad: a static prop that explodes into pieces
// (ch/exploder) with particles and a sound when hit (message 0x40).
#include "common.h"

typedef union {
    s32 word;
    void *ptr;
} MumboPadStatueEvent;
extern s32 D_808000A0_chmumbopadstatue[];
extern u8 D_8080010C_chmumbopadstatue[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern int D_80800120_chmumbopadstatue[];

void func_80800000_chmumbopadstatue(s32 actor)
{
}

// Hit (message 0x40): explodes into pieces with a particle burst and a sound.
s32 func_80800008_chmumbopadstatue(Actor *actor, s32 msg, MumboPadStatueEvent event)
{
    f32 *pos;
    if (msg == 0x40) {
        pos = actor->position;
        _chexploder_entrypoint_3(actor, pos, 0xC);
        func_800BABB8(0, pos, pos, actor->scale, D_808000A0_chmumbopadstatue);
        func_800C4AF0(pos, D_8080010C_chmumbopadstatue);
        return 1;
    }
    return 0;
}

int *chmumbopadstatue_entrypoint_0()
{
    return &D_80800120_chmumbopadstatue;
}

extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to functions of
// this file; IDO's assembler schedules some of them differently unless the tables are in the same
// unit. D_80800120_chmumbopadstatue is declared as int[] above.
s32 D_808000A0_chmumbopadstatue[27] = {
    0x610001D, 0x9DD002B, 0x2000300, 0x220180, 0x2000480,  0x6000015, 0x26,
    0x190000,  0x7002D,   0x320064,  0x20DEA7, 0x71C0000A, -0x63FFE7, -0x63FF9C,
    0x4B0064,  0x61A1910, 0x1D06A0,  0x14002D, 0x1900258,  0x1BFCE0,  -0x257FFDE,
    0xB300CC,  0xB300B3,  0x1E0032,  0x32000D, 0x4B191A,   0x0};
u8 D_8080010C_chmumbopadstatue[20] = {0x0,  0x13, 0x4, 0x13, 0x0,  0xA,  0x0,  0xE6, 0x0, 0x16,
                                      0x6D, 0x60, 0x0, 0x1,  0x19, 0x64, 0x19, 0x64, 0x0, 0x0};
int D_80800120_chmumbopadstatue[20] = {0xAC0202,
                                       0x6820001,
                                       0x0,
                                       (u32) func_80102EC0,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x800,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_80800000_chmumbopadstatue,
                                       (u32) func_80107C2C,
                                       -0x7FFFD800,
                                       (u32) func_80800008_chmumbopadstatue,
                                       0x0,
                                       0x0,
                                       0x0};
