#include "common.h"

extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern int D_80800480_chLagoonInnBlockedWall[];
extern u32 D_80800570_chLagoonInnBlockedWall[];
extern u8 D_8080046C_chLagoonInnBlockedWall[];
extern u8 D_80800400_chLagoonInnBlockedWall[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef union {
    u32 word;
    s16 halves[2];
} LagoonWallEvent;
extern u8 D_80800528_chLagoonInnBlockedWall[];
extern u8 D_808004C8_chLagoonInnBlockedWall[];
extern u8 D_8080054C_chLagoonInnBlockedWall[];
extern u8 D_80800514_chLagoonInnBlockedWall[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_80109704(Actor *, s32, s32, s32, f32, s32, s32, s32);

// Wall update: explodes and sets the destroyed flag; inside Jolly's warps to the lagoon.
void func_80800000_chLagoonInnBlockedWall(Actor *actor)
{
    f32 pos[3];

    switch (actor->unk70_10) {
        case 3:
            if (func_800D9078(&actor->unk58)) {
                func_800EE7F8(pos, actor->position);
                func_800EF1B8(pos, actor->rotation[1], -100.0f);
                _chexploder_entrypoint_3(actor, pos, 3);
                func_800DA544(0x3A9);
            }
            break;
        case 2:
            if (func_800D9078(&actor->unk58)) {
                func_800F82D4(func_800F54E4(), 0);
                _glcutDll_entrypoint_6(0x1A7, 0x32);
                func_800FFAB0(actor);
            }
    }
}

void func_808000C0_chLagoonInnBlockedWall()
{
    func_8010A63C();
}

int func_808000E0_chLagoonInnBlockedWall(Actor *actor, s32 msg, LagoonWallEvent arg)
{
    f32 pos[3];

    switch (msg) {
        case 0x49:
            if (_glcutDll_entrypoint_19(0x32)) {
                actor->unk58 = 0.4f;
                func_80103110(actor, 1);
                func_80101FDC(actor, 3);
                _capod_entrypoint_13(actor->unk0, 0, 0x1C, 0x910);
                return 1;
            }
            break;
        case 5:
            func_8010A570(actor);
            func_800EE7F8(pos, actor->position);
            func_800EF1B8(pos, *(f32 *) ((u8 *) actor + 0x48), 100.0f);
            _chexploder_entrypoint_3(actor, pos, 3);
            func_800F8300(func_800F54E4(), 2, actor->position);
            return 1;
        case 0x90:
            if (func_800EA05C() == 0xED) {
                func_80101FDC(actor, 2);
                func_80103110(actor, 1);
                actor->unk58 = 0.8f;
            } else
                func_800FFAB0(actor);
            func_800BABB8(0, actor->position, actor->position, actor->scale,
                          D_80800400_chLagoonInnBlockedWall);
            func_800C4AF0(actor->position, D_8080046C_chLagoonInnBlockedWall);
            return 1;
    }
    return 0;
}

int chLagoonInnBlockedWall_entrypoint_0()
{
    return &D_80800480_chLagoonInnBlockedWall;
}

// Wall destroyed: spawns particles and debris, plays sound 0x488.
void func_8080025C_chLagoonInnBlockedWall(actor, msg) Actor *actor;
s32 msg;
{
    f32 pos[3];

    func_800EE7F8(pos, actor->position);
    pos[1] += 80.0f;
    func_800BBCB8(pos, 0, actor->scale * 1.2f, 8, D_80800528_chLagoonInnBlockedWall);
    func_800BBCB8(pos, 0, actor->scale * 1.2f, 0x10, D_808004C8_chLagoonInnBlockedWall);
    func_800BBCB8(pos, pos, actor->scale, 0xF, D_8080054C_chLagoonInnBlockedWall);
    func_80109704(actor, 8, -0x28, 0xC8, 1.85f, 0xB4, 0x3C, 0x50);
    _subaddieaudioquick_entrypoint_2(actor, pos, D_80800514_chLagoonInnBlockedWall);
    func_800FFAB0(actor);
    func_80101180(0x488, 5, 0);
}

s32 func_80800398_chLagoonInnBlockedWall(s32 actor, s32 msg, s32 arg)
{
    if ((msg == 0x40) ^ 0) {
        func_8080025C_chLagoonInnBlockedWall(*&actor, arg | 0);
        // Matching: empty block needed for the match.
        if (!arg) {
        }
        return 1;
    }
    return 0;
}

u8 *chLagoonInnBlockedWall_entrypoint_1(void)
{
    return D_80800570_chLagoonInnBlockedWall;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void func_80102EC0();
extern void _bsbtrot_entrypoint_8();
u8 D_80800400_chLagoonInnBlockedWall[108] = {
    0x6,  0x10, 0x0, 0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x2, 0x0,  0x3,  0x0,  0x0,  0x22, 0x1,  0x80,
    0x2,  0x0,  0x4, 0x80, 0x6,  0x0,  0x0,  0x15, 0x0, 0x0,  0x0,  0x26, 0x0,  0x19, 0x0,  0x0,
    0x0,  0x7,  0x0, 0x2D, 0x0,  0x32, 0x0,  0x64, 0x0, 0x20, 0xDE, 0xA7, 0x71, 0xC0, 0x0,  0xA,
    0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0,  0x64, 0x0, 0x4B, 0x0,  0x64, 0x6,  0x1A, 0x19, 0x10,
    0x0,  0x1D, 0x6, 0xA0, 0x0,  0x14, 0x0,  0x2D, 0x1, 0x90, 0x2,  0x58, 0x0,  0x1B, 0xFC, 0xE0,
    0xFD, 0xA8, 0x0, 0x22, 0x0,  0xB3, 0x0,  0xCC, 0x0, 0xB3, 0x0,  0xB3, 0x0,  0x1E, 0x0,  0x32,
    0x0,  0x32, 0x0, 0xD,  0x0,  0x4B, 0x19, 0x1A, 0x0, 0x0,  0x0,  0x0};
u8 D_8080046C_chLagoonInnBlockedWall[20] = {0x0,  0x13, 0x4,  0x13, 0x0,  0xA, 0x0,
                                            0xE6, 0x0,  0x16, 0x6D, 0x60, 0x0, 0x1,
                                            0x19, 0x64, 0x19, 0x64, 0x0,  0x0};
int D_80800480_chLagoonInnBlockedWall[18] = {0xAC0488,
                                             0x8EF0001,
                                             0x0,
                                             (u32) func_80800000_chLagoonInnBlockedWall,
                                             (u32) func_80105834,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x3A90000,
                                             0x400,
                                             0x0,
                                             (u32) func_80108ED0,
                                             0x0,
                                             (u32) func_808000C0_chLagoonInnBlockedWall,
                                             (u32) func_80107C2C,
                                             -0x7FF7D3FE,
                                             (u32) func_808000E0_chLagoonInnBlockedWall,
                                             0x0};
u8 D_808004C8_chLagoonInnBlockedWall[76] = {
    0x0,  0x2C, 0xFE, 0x5C, 0x1, 0x9A, 0xFE, 0x5C, 0x1, 0xE0, 0x3, 0x5C, 0x1, 0xE0, 0x0, 0x1B,
    0xFB, 0x50, 0xFC, 0x18, 0x0, 0x1E, 0xFF, 0xEC, 0x0, 0x14, 0x0, 0x24, 0x0, 0x35, 0x0, 0x63,
    0x0,  0x2A, 0x0,  0x0,  0x0, 0x2,  0x0,  0xCC, 0x1, 0x33, 0x0, 0x15, 0x0, 0x0,  0x0, 0x59,
    0x0,  0x16, 0x0,  0x4,  0x0, 0x1D, 0x9,  0xEA, 0x0, 0x19, 0x0, 0x1,  0x0, 0x6,  0x0, 0x27,
    0xFE, 0xD4, 0xFE, 0xD4, 0x1, 0x2C, 0x1,  0x2C, 0x0, 0x0,  0x0, 0x0};
u8 D_80800514_chLagoonInnBlockedWall[20] = {0x0, 0x13, 0x4, 0x13, 0x0,  0xD,  0x0, 0xE6, 0x1, 0x0,
                                            0x0, 0x1,  0x3, 0xE8, 0x19, 0x64, 0x0, 0x0,  0x0, 0x0};
u8 D_80800528_chLagoonInnBlockedWall[36] = {0x0,  0xC,  0x0,  0x50, 0x0,  0x23, 0x3,  0x0,  0x0,
                                            0x2B, 0x1,  0x80, 0x1,  0xA6, 0x0,  0x15, 0x0,  0xB3,
                                            0x0,  0xCC, 0x0,  0x1D, 0x9,  0xBB, 0x0,  0x18, 0x0,
                                            0x0,  0x0,  0x9,  0xC,  0x0,  0xC,  0x0,  0x0,  0x0};
u8 D_8080054C_chLagoonInnBlockedWall[36] = {0x0,  0x1D, 0x6,  0xA3, 0x0,  0x14, 0x0,  0x2D, 0x2,
                                            0x58, 0x3,  0x20, 0x0,  0x22, 0x0,  0x66, 0x0,  0x80,
                                            0x0,  0x33, 0x0,  0x4C, 0x0,  0x1E, 0x0,  0x14, 0x0,
                                            0x14, 0x0,  0xD,  0x0,  0x3C, 0x0,  0x0,  0x0,  0x0};
u32 D_80800570_chLagoonInnBlockedWall[20] = {0x3760491,
                                             0x6AA0001,
                                             0x0,
                                             (u32) func_80102EC0,
                                             (u32) func_80105834,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x3A90000,
                                             0x800,
                                             0x0,
                                             (u32) func_80108ED0,
                                             0x0,
                                             0x0,
                                             (u32) func_80107C2C,
                                             (u32) _bsbtrot_entrypoint_8,
                                             (u32) func_80800398_chLagoonInnBlockedWall,
                                             0x0,
                                             0x0,
                                             0x0};
