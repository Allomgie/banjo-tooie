#include "common.h"

extern int D_808001F0_chmrsboggyhome[];
extern void _sudeflect_entrypoint_1(u32 *, s32, f32, s32, s32);
extern int _suexpression_entrypoint_10();
extern int _suexpression_entrypoint_20();
typedef union {
    s32 local_0;
    f32 local_1;
    void *local_2;
} BoggyHomeEvent59;
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern u8 D_80800238_chmrsboggyhome[];
extern u8 D_808001B0_chmrsboggyhome[];
int func_80800174_chmrsboggyhome();

int *chmrsboggyhome_entrypoint_0()
{
    return &D_808001F0_chmrsboggyhome;
}

// Init: deletes the actor unless the Witchyworld quest flag is set.
s32 func_8080000C_chmrsboggyhome(s32 actor)
{
    if (_glcutDll_entrypoint_20()) {
        func_80102424(actor, 3);
    } else {
        if (func_800DA298(0x1CD) == 0) {
            func_800FFAB0(actor);
        }
    }
}

void func_8080005C_chmrsboggyhome(s32 *actor)
{
    _sudeflect_entrypoint_1((u32 *) actor + 1, 0x43480000, 0, 0x42C80000, 0xA);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(actor), actor[0], 0);
    if (((u32) *(u16 *) ((char *) actor + 114) >> 10) == 1) {
        func_80800174_chmrsboggyhome(actor);
    }
}

void func_808000D0_chmrsboggyhome(Actor *arg0)
{
    _suexpression_entrypoint_8(arg0, 1);
}

// Event handler.
s32 func_808000F0_chmrsboggyhome(Actor *actor, s32 event, BoggyHomeEvent59 event_arg)
{
    s32 expression;

    switch (event) {
        case 0x2E:
            func_80102424(actor, 1);
            break;
        case 0x95:
            expression = _suexpression_entrypoint_7(actor, 1, 0x3E);
            _suexpression_entrypoint_12(expression, 60.0f, 20.0f);
            _suexpression_entrypoint_17(expression, 1000);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80800174_chmrsboggyhome(actor)
s32 actor;
{
    s32 dialog_count;
    dialog_count = 4;
    _subaddiedialog_entrypoint_8(actor, actor + 4, &D_80800238_chmrsboggyhome,
                                 &D_808001B0_chmrsboggyhome, dialog_count);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u8 D_808001B0_chmrsboggyhome[32] = {0x0, 0x0,  0x2,  0x1,  0x12, 0xBB, 0x1,  0x0, 0x0, 0x0,  0x6,
                                    0x1, 0x12, 0xBC, 0x2,  0x0,  0x0,  0x0,  0x4, 0x0, 0x12, 0xBB,
                                    0x1, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0};
u32 D_808001D0_chmrsboggyhome[8] = {0x0,        0x0,       0x40066666, 0x3EE0000,
                                    0x40066666, 0x3EE0000, 0x40066666, 0x3EE0001};
int D_808001F0_chmrsboggyhome[18] = {0x1580430,
                                     0x6B70001,
                                     (u32) &D_808001D0_chmrsboggyhome,
                                     (u32) func_8080005C_chmrsboggyhome,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x3FE00000,
                                     0x0,
                                     0x120,
                                     (u32) func_808000D0_chmrsboggyhome,
                                     0x0,
                                     0x0,
                                     (u32) func_8080000C_chmrsboggyhome,
                                     (u32) func_80107C2C,
                                     -0x7FFFFBFE,
                                     (u32) func_808000F0_chmrsboggyhome,
                                     0x0};
u8 D_80800238_chmrsboggyhome[24] = {0x0, 0x8B, 0x0, 0x0, 0x1, 0x90, 0x0, 0x3E, 0x0, 0x0, 0x0, 0xC,
                                    0x6, 0x3C, 0x2, 0x0, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
