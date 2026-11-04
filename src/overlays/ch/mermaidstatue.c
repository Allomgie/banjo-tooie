// Jolly Roger's Lagoon mermaid statue puzzle: hit six statues with eggs in one of four
// random orders. Wrong hits reset the count; the sixth correct hit sets FLAG_18D, plays a
// jingle and opens the door.
#include "common.h"

extern int D_80800354_chmermaidstatue[];
extern void *D_8080039C_chmermaidstatue;
extern s16 D_80800330_chmermaidstatue[][6];
extern int _chdoormake_entrypoint_3(s32, f32, s32, s32, s32, s32);
int func_80800150_chmermaidstatue();
void func_808001B0_chmermaidstatue();

// Statues: sequence check, randomised order, hint mesh part.
int chmermaidstatue_entrypoint_0()
{
    return (int) &D_80800354_chmermaidstatue;
}

// The door opened by the puzzle (doormake, FLAG_18D).
int chmermaidstatue_entrypoint_1()
{
    return &D_8080039C_chmermaidstatue;
}

s32 func_80800018_chmermaidstatue(s32 statue)
{
    s32 section;

    section = _subaddiesect_entrypoint_1();
    *(s32 **) (statue + 0x30) = section;
    _subaddiesect_entrypoint_2(statue, section, 0);
    func_800DA7A8(0x6B1, 0, 3);
    func_80109EEC(statue, 0x40);
    if (func_800DA298(0x18D) != 0) {
        func_8010A570(statue);
        func_80101FDC(statue, 2);
    }
}

void func_80800094_chmermaidstatue(s32 arg0)
{
}

void func_8080009C_chmermaidstatue(u8 *statue, s32 draw_arg)
{
    func_800DF744(3, ((u32) (u16) *(u16 *) ((s8 *) statue + 0x76) >> 7) - 0x31);
    func_80101870(statue, draw_arg);
}

s32 func_808000E0_chmermaidstatue(Actor *statue, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x40:
            func_808001B0_chmermaidstatue(statue);
            break;
        case 0x95:
            func_800BF744(1, func_80800150_chmermaidstatue() + 1);
            break;
        default:
            return 0;
    }
    return 1;
}

// Returns the puzzle order (0-3), chosen randomly once.
int func_80800150_chmermaidstatue()
{
    s32 order;
    if (!func_800DA298(0x6AE)) {
        order = func_800DC128(0, 3);
        func_800DA7A8(0x6AF, order, 2);
        func_800DA544(0x6AE);
        return order;
    }
    {
        return func_800DA564(0x6AF, 2);
    }
}

// A statue was hit: advance the input count if it matches the order, else reset.
void func_808001B0_chmermaidstatue(statue) Actor *statue;
{
    s32 statue_idx;
    s32 order;
    s32 input_count;
    statue_idx = statue->unk74_7 - 50;
    input_count = func_800DA564(0x6B1, 3);
    if (input_count != 6) {
        order = func_80800150_chmermaidstatue();
        if (statue_idx == D_80800330_chmermaidstatue[order][input_count]) {
            input_count++;
            func_800DA7A8(0x6B1, input_count, 3);
            if (input_count == 6) {
                if (!func_800DA298(0x18D)) {
                    func_800FC660(0x10);
                    _capod_entrypoint_13(statue->unk0, 0, 0x1E, 0x10);
                    func_80101180(0x3C1, 7, 0);
                    func_800DA544(0x18D);
                }
            } else {
                func_800FC660(0xE);
            }
        } else {
            func_800DA7A8(0x6B1, 0, 3);
            func_800FC660(0xF);
        }
    }
}

void func_808002C8_chmermaidstatue(s32 door)
{
    if (_chdoormake_entrypoint_3(door, 0, 0x42B40000, 0x43C80000, 1, 0x18D) != 0) {
        _chdoormake_entrypoint_8(door, 0xD);
        _chdoormake_entrypoint_5(door, 0x40000000);
        _chdoormake_entrypoint_6(door, 0x40400000);
    }
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
extern int func_80101870();
extern void _chdoor_entrypoint_1();
s16 D_80800330_chmermaidstatue[3][6] = {0x0, 0x3, 0x0, 0x0, 0x1, 0x2, 0x1, 0x0, 0x2,
                                        0x0, 0x3, 0x3, 0x2, 0x1, 0x3, 0x0, 0x2, 0x1};
int D_80800354_chmermaidstatue[18] = {0x32403C0,
                                      0x6E90001,
                                      0x0,
                                      (u32) func_80800094_chmermaidstatue,
                                      (u32) func_80105834,
                                      (u32) func_8080009C_chmermaidstatue,
                                      0x5DC0000,
                                      0x0,
                                      0x0,
                                      0x800,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      (u32) func_80800018_chmermaidstatue,
                                      (u32) func_80107C2C,
                                      -0x7FFFDBB0,
                                      (u32) func_808000E0_chmermaidstatue,
                                      0x0};
void *D_8080039C_chmermaidstatue = (void *) 0x00AC03C1;
static u32 D_8080039C_chmermaidstatue_rest[20] = {0x6FF0001,
                                                  0x0,
                                                  (u32) _chdoor_entrypoint_0,
                                                  (u32) func_80105834,
                                                  (u32) func_80101870,
                                                  0x0,
                                                  0x0,
                                                  0x0,
                                                  0x800,
                                                  0x0,
                                                  (u32) func_80108ED0,
                                                  0x0,
                                                  (u32) func_808002C8_chmermaidstatue,
                                                  (u32) func_80107C2C,
                                                  0x80002C02,
                                                  (u32) _chdoor_entrypoint_1,
                                                  0x0,
                                                  0x0,
                                                  0x0,
                                                  0x0};
