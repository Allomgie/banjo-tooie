#include "common.h"

void _sudeflect_entrypoint_1(s32, f32, f32, f32, s32);
f32 func_80103EF4(void);
f32 func_80103EAC(s32);
extern int D_808000C0_chbobpanel[];

// Init: sets up a projectile deflector from the model height and radius.
void func_80800000_chbobpanel(s32 actor)
{
    f32 unk_0;
    f32 height;
    height = func_80103EF4();
    unk_0 = 0.0f;
    _sudeflect_entrypoint_1(actor + 4, height, unk_0, func_80103EAC(actor), 0x1E);
}

// Message handler: on draw (0x1F) sets three model texture/visibility frames.
int func_8080004C_chbobpanel(s32 actor, s32 msg, s32 msg_data)
{
    if (msg == 0x1F) {
        func_801015D0(actor);
        func_800DF744(2, 3);
        func_800DF744(3, 1);
        func_800DF744(4, 1);
        return 1;
    }
    return 0;
}

int chbobpanel_entrypoint_0()
{
    return (int) &D_808000C0_chbobpanel;
}

// TU-NOTE: the overlay .data is defined in C here; its tables point to functions of this file,
// and IDO schedules some of them differently unless the tables are in the same unit.
extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808000C0_chbobpanel[20] = {0x1580532,
                                 0x8C80001,
                                 0x0,
                                 (u32) func_80800000_chbobpanel,
                                 (u32) func_80105834,
                                 (u32) func_801018A4,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x1000,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 0x0,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBFE,
                                 (u32) func_8080004C_chbobpanel,
                                 0x0,
                                 0x0,
                                 0x0};
