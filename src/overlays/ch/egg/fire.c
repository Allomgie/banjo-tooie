// Fire egg projectile: leaves a flame trail (skipped on odd frames) and uses the shared egg
// burn/impact routine on impact.
#include "common.h"

typedef struct {
    u8 pad_0[0x30];
    f32 unk_30;
    u8 pad_34[5];
    u8 expired : 1;
    u8 pad_39 : 7;
} EggUpdateLocal;
extern void *func_80100094(Actor *, u32);
extern s32 func_800EEEA8(void *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 _suegg_entrypoint_8(Actor *);
extern void _suegg_entrypoint_16(Actor *);
extern s32 _suegg_entrypoint_14(Actor *);
extern s32 _sueggmove_entrypoint_3(Actor *);
extern void _suegg_entrypoint_23(Actor *);
extern s32 _suegg_entrypoint_13(Actor *);
extern s32 _suegg_entrypoint_12(Actor *);
extern void _sueggmisc_entrypoint_1(Actor *);
extern void _suegg_entrypoint_3(Actor *);
extern void _suegg_entrypoint_5(void);
extern void _suegg_entrypoint_21(Actor *param_0, void *param_1);
extern u8 D_808003B0_cheggfire[];
extern int D_808003BC_cheggfire[];
extern Actor *_suegg_entrypoint_11(s32, s32, s32);
extern void _suegg_entrypoint_1(Actor *, f32);
extern void _sueggmove_entrypoint_5(Actor *, s32);
extern void _sueggmove_entrypoint_6(Actor *, f32, f32);
extern void _sueggmove_entrypoint_7(Actor *, s32);
extern void _sueggmove_entrypoint_10();
extern f32 func_800D8FF8(void);
extern void _fxegg_entrypoint_3(f32 *, f32);

// Flame trail: skipped on odd frames.
void func_80800000_cheggfire(actor) Actor *actor;
{
    u8 *data;
    f32 interval;

    data = func_80100094(actor, 0);
    *(f32 *) (data + 0x28) -= func_800D8FF8();
    interval = func_800F10B4(*(f32 *) (data + 0x30), 0, 2.0f, 0.0333f, 0.1f);
    while (*(f32 *) (data + 0x28) <= 0.0f) {
        *(f32 *) (data + 0x28) += interval;
    }
    if (!func_8001210C(1)) {
        _fxegg_entrypoint_3(actor->position, actor->scale);
    }
}

void func_808000B8_cheggfire(Actor *actor)
{
    EggUpdateLocal *data;

    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            if (!_suegg_entrypoint_8(actor)) {
                if (func_800EEEA8(&actor->actorData[4])) {
                    data->expired = 1;
                } else {
                    func_80800000_cheggfire(actor);
                    _suegg_entrypoint_16(actor);
                    if (_suegg_entrypoint_14(actor)) {
                        data->expired = 1;
                    }
                }
            }
            break;
        case 2:
            if (!_suegg_entrypoint_8(actor)) {
                actor->scale = func_800F10B4(data->unk_30, 0.0f, 0.134f, 0.1f, 0.25f);
                if (_sueggmove_entrypoint_3(actor)) {
                    _suegg_entrypoint_23(actor);
                }
                if (_suegg_entrypoint_13(actor)) {
                    data->expired = 1;
                } else if (_suegg_entrypoint_12(actor)) {
                    _sueggmisc_entrypoint_1(actor);
                } else {
                    func_80800000_cheggfire(actor);
                    _suegg_entrypoint_16(actor);
                }
            }
            break;
    }
    if (data->expired) {
        _suegg_entrypoint_3(actor);
    }
}

// Impact: shared egg burn routine with this egg's own data table.
void func_80800228_cheggfire(Actor *actor)
{
    _suegg_entrypoint_5();
    _suegg_entrypoint_21(actor, &D_808003B0_cheggfire);
}

int cheggfire_entrypoint_0()
{
    return (int) &D_808003BC_cheggfire;
}

u8 *cheggfire_entrypoint_1(Actor *unk_0, s32 unk_1, f32 unk_2[3], s32 unk_3)
{
    Actor *egg;

    _sueggmove_entrypoint_10(unk_0);
    egg = _suegg_entrypoint_11(0x15B, unk_1, unk_3);
    *(f32 *) ((char *) egg + 0x38) = 0.134f;
    _suegg_entrypoint_1(egg, 3e+01f);
    _sueggmove_entrypoint_5(egg, 1);
    _sueggmove_entrypoint_6(egg, -2.2e+03f, -22000.0f);
    _sueggmove_entrypoint_7(egg, unk_2);
    *(u8 *) ((char *) egg + 0x72) = (*(u8 *) ((char *) egg + 0x72) & 0xFF03) | 8;
    return egg;
}

Actor *cheggfire_entrypoint_2(s32 unk_0, s32 unk_1, s32 unk_2, s32 unk_3)
{
    Actor *egg;

    _sueggmove_entrypoint_10(unk_0, unk_1);
    egg = _suegg_entrypoint_11(0x15B, unk_1, unk_3);
    egg->scale = 0.25f;
    _sueggmove_entrypoint_5(egg, 0);
    _sueggmove_entrypoint_6(egg, 0.0f, -100000.0f);
    _suegg_entrypoint_1(egg, 30.0f);
    _sueggmove_entrypoint_7(egg, unk_2);
    egg->unk70_10 = 1;
    return egg;
}

// TU-NOTE: .data is defined in C (values from the ROM). The tables point to functions of this file; IDO's
// assembler schedules them differently unless they are in the same unit. D_808003BC_cheggfire is int[].
extern void func_80105834();
extern void _subaddiedraw25d_entrypoint_2();
extern void _suegg_entrypoint_2();
extern void _suegg_entrypoint_0();
extern void func_80107C2C();
extern void _suegg_entrypoint_17();
u8 D_808003B0_cheggfire[12] = {0x0, 0x0, 0x0, 0xE0, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0x64};
int D_808003BC_cheggfire[21] = {0x26D015B,
                                0x9C10001,
                                0x0,
                                (u32) func_808000B8_cheggfire,
                                (u32) func_80105834,
                                (u32) _subaddiedraw25d_entrypoint_2,
                                0x0,
                                0x3F800000,
                                0x0,
                                0x4,
                                (u32) _suegg_entrypoint_2,
                                (u32) _suegg_entrypoint_0,
                                0x4C0000,
                                (u32) func_80800228_cheggfire,
                                (u32) func_80107C2C,
                                -0x78000000,
                                (u32) _suegg_entrypoint_17,
                                0x0,
                                0x0,
                                0x0,
                                0x0};
