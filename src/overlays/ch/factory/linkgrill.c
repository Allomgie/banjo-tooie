// Most likely three GI actors: a breakable grille (flag 0x1C0+index) that explodes on a hit,
// a floor switch for flag 0x1D9 that messages actor 0x3FA, and a grate opening with flag 0x1D9.
#include "ch/factory/linkgrill.h"

extern u8 D_80800244_chfactorylinkgrill[];
extern u8 D_80800200_chfactorylinkgrill[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern int D_80800250_chfactorylinkgrill[];
extern int D_80800298_chfactorylinkgrill[];
extern int D_808002E0_chfactorylinkgrill[];

// Breakable grille: index from cubesearch, flag 0x1C0 + index marks it destroyed.
void func_80800000_chfactorylinkgrill(Actor *actor)
{
    actor->unk79_4 = _gccubesearch_entrypoint_10(1000, actor->pad6C_21);
    if (func_800DA298(actor->unk79_4 + 0x1C0)) {
        func_800FFAB0(actor);
    }
}

// Message 0x40 breaks the grille into skeleton debris.
s32 func_8080006C_chfactorylinkgrill(Actor *actor, s32 msg, s32 param_2)
{
    f32 *pos;
    switch (msg) {
        case 0x40:
            func_800DA544(actor->unk79_4 + 0x1C0);
            pos = actor->position;
            _chskeletonexplode_entrypoint_7(actor, pos);
            _subaddieaudioquick_entrypoint_2(actor, pos, D_80800244_chfactorylinkgrill);
            func_800BBCB8(pos, pos, 1.0f, 5, D_80800200_chfactorylinkgrill);
            return 1;
        case 0xF:
            func_800FFAB0(actor);
            return 1;
    }
    return 0;
}

int chfactorylinkgrill_entrypoint_0()
{
    return &D_80800250_chfactorylinkgrill;
}

// Floor switch for flag 0x1D9.
void func_80800124_chfactorylinkgrill(s32 actor)
{
    _chswitch_entrypoint_7(actor, FLAG_1D9_UNK);
    _chswitch_entrypoint_9(actor);
}

// Message 7 is forwarded to actor 0x3FA (the grate).
int func_80800150_chfactorylinkgrill(Actor *actor, s32 msg, s32 param_2)
{
    if (msg == 7) {
        func_80101180(0x3FA, 7, 0);
    }
    _chswitch_entrypoint_10(actor, msg, param_2);
}

int chfactorylinkgrill_entrypoint_1()
{
    return &D_80800298_chfactorylinkgrill;
}

s32 func_808001B0_chfactorylinkgrill(Actor *this)
{
    _chdoormake_entrypoint_0(this, 0xC2B40000, 0, 0x1D9);
    _chdoormake_entrypoint_5(this, 0x3FC00000);
    _chdoormake_entrypoint_8(this, 2);
}

int *chfactorylinkgrill_entrypoint_2()
{
    return &D_808002E0_chfactorylinkgrill;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _bsbtrot_entrypoint_10();
extern void _chswitch_entrypoint_6();
extern void _chdoor_entrypoint_0();
extern void _chdoor_entrypoint_1();
u8 D_80800200_chfactorylinkgrill[68] = {
    0x0,  0x1D, 0x9,  0xDD, 0x0, 0x2B, 0x6,  0x0,  0x8,  0x0,  0x0,  0x22, 0x2,  0x0,
    0x2,  0x80, 0x6,  0x0,  0x8, 0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x26, 0x0,  0x19,
    0x0,  0x0,  0x0,  0x7,  0x0, 0x2C, 0xFF, 0xEC, 0x0,  0x14, 0xFF, 0xEC, 0x0,  0x14,
    0x0,  0x28, 0x0,  0x14, 0x0, 0x20, 0x60, 0x60, 0x60, 0x80, 0x0,  0xA,  0xFF, 0xEC,
    0xFF, 0xCE, 0xFF, 0xEC, 0x0, 0x14, 0x0,  0x32, 0x0,  0x14, 0x0,  0x0};
u8 D_80800244_chfactorylinkgrill[12] = {0x0,  0x13, 0x4, 0xA0, 0x0, 0x16,
                                        0x6D, 0x60, 0x0, 0x0,  0x0, 0x0};
int D_80800250_chfactorylinkgrill[18] = {0x11C03E8,
                                         0x8810001,
                                         0x0,
                                         0x0,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x40000C00,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_80800000_chfactorylinkgrill,
                                         (u32) func_80107C2C,
                                         (u32) _bsbtrot_entrypoint_10,
                                         (u32) func_8080006C_chfactorylinkgrill,
                                         0x0};
int D_80800298_chfactorylinkgrill[18] = {0x34303F1,
                                         0x8890001,
                                         -0x7FEE5DE0,
                                         (u32) _chswitch_entrypoint_6,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x40000808,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_80800124_chfactorylinkgrill,
                                         (u32) func_80107C2C,
                                         -0x7FF7D3EE,
                                         (u32) func_80800150_chfactorylinkgrill,
                                         0x0};
int D_808002E0_chfactorylinkgrill[20] = {0xAC03FA,
                                         0x8870001,
                                         -0x7FEE5DE0,
                                         (u32) _chdoor_entrypoint_0,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x9C40000,
                                         0x0,
                                         0x0,
                                         0x40000C00,
                                         0x0,
                                         0x0,
                                         0x0,
                                         (u32) func_808001B0_chfactorylinkgrill,
                                         (u32) func_80107C2C,
                                         -0x7FF7DBEE,
                                         (u32) _chdoor_entrypoint_1,
                                         0x0,
                                         0x0,
                                         0x0};
