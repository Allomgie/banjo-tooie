#include "common.h"

extern int D_80800330_chlagoonbilldrillcover[];
extern void func_800EE7F8(void *param_0, void *param_1);
extern void _chexploder_entrypoint_3(Actor *param_0, void *param_1, int param_2);
extern void func_800BBCB8(void *param_0, void *param_1, int param_2, int param_3, void *param_4);
extern void _subaddieaudioquick_entrypoint_2(Actor *param_0, void *param_1, void *param_2);
extern void func_8010A624(Actor *param_0);
extern void func_80108B04(Actor *param_0, int param_1);
extern void func_800DA544(int param_0);
extern int D_80800378_chlagoonbilldrillcover[];
extern int D_808003B0_chlagoonbilldrillcover[];
extern s32 func_80101080(void);
extern void _chexploder_entrypoint_12();
extern void func_800FFAB0();
extern void func_80101FDC();
void func_8080024C_chlagoonbilldrillcover();

int *chlagoonbilldrillcover_entrypoint_0()
{
    return &D_80800330_chlagoonbilldrillcover;
}

void func_8080000C_chlagoonbilldrillcover(u8 *actor)
{
    if (func_800DA298(((u32) (u16) *(u16 *) ((s8 *) actor + 0x76) >> 7) + 0x3C2) != 0) {
        if ((s32) ((u32) (u16) *(u16 *) ((s8 *) actor + 0x76) >> 7) >= 0x35) {
            func_8010A570(actor);
            func_8010A624(actor);
            *(u8 *) ((s8 *) actor + 0x65) = (u8) (*(u8 *) ((s8 *) actor + 0x65) & 0xFFFE);
            func_80108B04(actor, 0);
            return;
        }
        func_800FFAB0(actor);
    }
}

int func_80800094_chlagoonbilldrillcover(s32 actor)
{
    if ((2 == ((*(u16 *) ((u8 *) actor + 0x72) & 0xFFFFFFFFu) >> 10)) &&
        _subaddieDll_entrypoint_6(actor, 11)) {
        func_8080024C_chlagoonbilldrillcover(actor);
    }
}

int func_808000DC_chlagoonbilldrillcover(Actor *actor, s32 msg, s32 arg)
{
    s32 pad[2];
    f32 spawn_pos[3];
    u32 variant;

    // msg 0x40: Bill Drill hit, 0x3D: release content
    switch (msg) {
        case 0x40:
            if (_subaddieDll_entrypoint_5(actor, *(s32 *) &arg)) {
                func_80103110(actor, 1);
                func_80101FDC(actor, 2);
            } else
                func_8080024C_chlagoonbilldrillcover(actor);
            break;
        case 0x90:
            _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x28);
            break;
        case 0x3D:
            variant = actor->unk74_7 - 0x32;
            func_800EE7F8(spawn_pos, actor->position);
            spawn_pos[1] -= 100.0f;
            func_800FFAB0(actor);
            switch (variant) {
                case 0:
                case 1:
                case 2:
                    func_800D10D4(variant + 0x13, 7, spawn_pos, 3, 0);
                    break;
                case 3:
                    func_80108474(0x210, spawn_pos, 0x10E);
                    break;
                case 4:
                    func_80108474(0x210, spawn_pos, 0);
                    break;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080024C_chlagoonbilldrillcover(actor) Actor *actor;
{
    f32 spawn_pos[3];
    func_800EE7F8(spawn_pos, (char *) actor + 4);
    spawn_pos[1] -= 200.0f;
    _chexploder_entrypoint_3(actor, spawn_pos, 5);
    func_800BBCB8((char *) actor + 4, spawn_pos, 0x3F800000, 3, &D_80800378_chlagoonbilldrillcover);
    _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4,
                                     &D_808003B0_chlagoonbilldrillcover);
    func_8010A624(actor);
    *(u8 *) ((char *) actor + 0x65) &= ~1;
    func_80108B04(actor, 0);
    func_800DA544(((u32) (u16) *(u16 *) ((char *) actor + 0x76) >> 7) + 0x3C2);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800330_chlagoonbilldrillcover[18] = {0x305036B,
                                             0x7640001,
                                             0x0,
                                             (u32) func_80800094_chlagoonbilldrillcover,
                                             (u32) func_80105834,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x800,
                                             0x0,
                                             (u32) func_80108ED0,
                                             0x0,
                                             (u32) func_8080000C_chlagoonbilldrillcover,
                                             (u32) func_80107C2C,
                                             -0x7FFFD400,
                                             (u32) func_808000DC_chlagoonbilldrillcover,
                                             0x0};
int D_80800378_chlagoonbilldrillcover[14] = {0x1D09DD,  0x2B0200, 0x3000022, 0x1800200, 0x4800600,
                                             0x150000,  0x990019, 0x7,       0x2D0032,  0x4B0020,
                                             -0x1F7F88, 0xB0032,  0x50FFFB,  0x50000};
int D_808003B0_chlagoonbilldrillcover[8] = {0x1304F4,  0xD0099, 0xB30016, 0x6D600001,
                                            0x4E209C4, 0x0,     0x0,      0x0};
