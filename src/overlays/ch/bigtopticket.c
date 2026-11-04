#include "common.h"

extern void *D_80800120_chbigtopticket;
extern f32 func_800D8FF8(void);
extern void func_80101870(void);
extern void func_80103110(void *param_0, int param_1);

void *chbigtopticket_entrypoint_0()
{
    return &D_80800120_chbigtopticket;
}

void func_8080000C_chbigtopticket(s32 arg0)
{
}

// Slowly sinks.
void func_80800014_chbigtopticket(u8 *actor)
{
    *(f32 *) (actor + 0x48) -= func_800D8FF8() * 175.0f;
    func_80103110(actor, 0);
}

void func_80800058_chbigtopticket(Actor *actor)
{
    func_80101870();
    func_80103110(actor, (*(u32 *) ((char *) actor + 0x7C) << 19) >> 31);
}

// Message 0x3E: touched, collect the ticket. 0x13: store registry index.
s32 func_8080008C_chbigtopticket(Actor *actor, s32 msg, s32 data)
{
    switch (msg) {
        case 0x3E:
            _sudialog_entrypoint_0(0x19F, 4);
            func_800D0BD4(*(s32 *) &actor->unk54, 8);
            func_800D1844(0x4D);
            func_800FC6B0(0x73);
            _fxsparkle_entrypoint_1(actor->position, 0x11);
            func_8010A570(actor);
            func_800FFAB0(actor);
            return 1;
        case 0x13:
            *(s32 *) &actor->unk54 = data;
            break;
        default:
            return 0;
    }
    return 1;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
void *D_80800120_chbigtopticket = (void *) 0x032903C6;
static u32 D_80800120_chbigtopticket_rest[19] = {0x7BF0001,
                                                 0x0,
                                                 (u32) func_80800014_chbigtopticket,
                                                 (u32) func_80105834,
                                                 (u32) func_80800058_chbigtopticket,
                                                 0x0,
                                                 0x3F800000,
                                                 0x0,
                                                 0x40040004,
                                                 0x0,
                                                 (u32) func_80108ED0,
                                                 0x0,
                                                 (u32) func_8080000C_chbigtopticket,
                                                 (u32) func_80107C2C,
                                                 0x80001814,
                                                 (u32) func_8080008C_chbigtopticket,
                                                 0x0,
                                                 0x0,
                                                 0x0};
