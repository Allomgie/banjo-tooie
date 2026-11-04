// Static (always lit) torch: probably a placed torch with a flame, a fire sound loop and a sphere
// around the flame registered through the player API, possibly a hurt zone.
#include "common.h"

extern void *func_80100094(Actor *, u32);
extern void *func_80104130(void);
extern void func_800DBEFC(void *, s32, f32 *);
extern void func_8008FB10(s32, f32, f32, f32);
typedef struct {
    u8 pad[0x7C];
    u32 pad7C : 19;
    u32 flag : 1;
    u32 rest : 12;
} TorchState;
extern u8 D_80800230_chstatictorch[];
extern void _subaddieaudioloop_entrypoint_4();
extern int D_80800248_chstatictorch[];
extern void _suflamefx_entrypoint_7(void *, f32 *, f32, f32, f32, s32, f32);
void func_80800140_chstatictorch();

void func_80800000_chstatictorch(Actor *actor, s32 unk_1)
{
    func_80101870(actor);
    // Flame position comes from model bone 5.
    if (actor->unk7C_12) {
        func_800DBEFC(func_80104130(), 5, (f32 *) actor->actorData);
        ((f32 *) actor->actorData)[1] += 10.0f;
        if (func_80100094(actor, 1))
            _suflamefx_entrypoint_3(func_80100094(actor, 1), unk_1);
    }
}

s32 func_80800090_chstatictorch(s32 actor)
{
    func_8008FB10(actor + 4, 40.0f, 0.0f, 1.0f);
    _suflamefx_entrypoint_2(func_80100094(actor, 1), actor + 0x18);
    func_80800140_chstatictorch(actor);
}

void func_808000E4_chstatictorch(s32 arg0)
{
}

void func_808000EC_chstatictorch(Actor *actor)
{
    if (func_80100094(actor, 1)) {
        _suflamefx_entrypoint_1(actor, 1);
    }
    if (actor->unk5F != 0) {
        func_800C2FDC(actor->unk5F);
        actor->unk5F = 0;
    }
}

void func_80800140_chstatictorch(torch) TorchState *torch;
{
    _subaddieaudioloop_entrypoint_4(torch,
                                    torch->flag ? (u8 *) torch + 0x18 : (u8 *) torch + 4, 1,
                                    D_80800230_chstatictorch);

}

int func_80800180_chstatictorch(Actor *actor, s32 msg, s32 unk_2)
{
    switch (msg) {
        case 0x95:
            _suflamefx_entrypoint_0(actor, 1, 15, 0x9EB);
            _suflamefx_entrypoint_7(func_80100094(actor, 1), actor->position, 0.4f, 0.5f, 11.0f,
                                    3, 0.95f);
            break;
        default:
            return 0;
    }

return 1;
}

int *chstatictorch_entrypoint_0()
{
    return &D_80800248_chstatictorch;
}

// TU-NOTE: The .data of this overlay is defined here in C. Its tables point to functions of this
// file, and IDO's assembler schedules some of them differently unless the tables are in the same
// unit. Values are taken from the ROM. D_80800248_chstatictorch is declared as int[] to match the
// object (same address).
extern void func_80105834();
extern void func_80107C2C();
u8 D_80800230_chstatictorch[24] = {0x0, 0x13, 0x4, 0x83, 0x0, 0x16, 0x27, 0x10,
                                   0x0, 0xE,  0x1, 0x33, 0x1, 0x70, 0x1,  0x80,
                                   0x0, 0x1,  0x1, 0xF4, 0x5, 0xDC, 0x0,  0x0};
int D_80800248_chstatictorch[18] = {0x20E02AE,
                                    0x6740001,
                                    0x0,
                                    (u32) func_80800090_chstatictorch,
                                    (u32) func_80105834,
                                    (u32) func_80800000_chstatictorch,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x23,
                                    (u32) func_808000EC_chstatictorch,
                                    0x0,
                                    0x0,
                                    (u32) func_808000E4_chstatictorch,
                                    (u32) func_80107C2C,
                                    0x0,
                                    (u32) func_80800180_chstatictorch,
                                    0x0};
