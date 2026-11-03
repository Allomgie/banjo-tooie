#include "common.h"

extern void _suegg_entrypoint_16();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C4140(s32, f32 *, u32);
typedef struct {
    u8 pad_0[0x38];
    u32 pad_38 : 8;
    u32 expired : 1;
    u32 pad_39 : 23;
} GoldenEggPendingFlags1041;
extern int D_808003F0_chegggolden[];
extern Actor *_suegg_entrypoint_11(s32, s32, s32);
extern void _suegg_entrypoint_1(Actor *, f32);
extern void _sueggmove_entrypoint_5(Actor *, s32);
extern void _sueggmove_entrypoint_6(Actor *, f32, f32);
extern void _sueggmove_entrypoint_7(Actor *, s32);
extern void _sueggmove_entrypoint_10();
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void _fxegg_entrypoint_6(f32 *, f32, f32 *);

// Spawns the gold trail particles; skipped with 3+ views active.
void func_80800000_chegggolden(actor) Actor *actor;
{
    f32 *data;
    f32 interval;
    f32 trail_dir[3];
    f32 unk_0[3];

    data = (f32 *) func_80100094(actor, 0);
    if (func_800A946C() < 3) {
        func_800EFA20(trail_dir, &((f32 *) actor->actorData)[4], 0.5f);
        data[10] -= func_800D8FF8();
        interval = func_800F10B4(data[12], 0, 1.8f, 0.0333f, 0.1f);
        while (data[10] <= 0.0f) {
            data[10] += interval;
            func_800EE7F8(unk_0, actor->position);
            _fxegg_entrypoint_6(actor->position, actor->scale, trail_dir);
        }
    }
}

void func_80800110_chegggolden(Actor *actor)
{
    u8 *data;
    data = (u8 *) func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            if (!_suegg_entrypoint_8(actor)) {
                if (func_800EEEA8((u8 *) actor + 0x28))
                    ((GoldenEggPendingFlags1041 *) data)->expired = 1;
                else {
                    func_80800000_chegggolden(actor);
                    _suegg_entrypoint_16(actor);
                    if (_suegg_entrypoint_14(actor))
                        ((GoldenEggPendingFlags1041 *) data)->expired = 1;
                }
            }
            break;
        case 2:
            if (!_suegg_entrypoint_8(actor)) {
                actor->scale =
                    func_800F10B4(*(f32 *) (data + 0x30), 0.0f, 0.134f, 0.1f, 0.25f);
                // Bounce sound on ground contact.
                if (_sueggmove_entrypoint_3(actor))
                    func_800C4140(0x7FEBBC18, actor->position, 0x04B000FA);
                if (_suegg_entrypoint_13(actor))
                    ((GoldenEggPendingFlags1041 *) data)->expired = 1;
                else if (_suegg_entrypoint_12(actor))
                    _sueggmisc_entrypoint_1(actor);
                else {
                    func_80800000_chegggolden(actor);
                    _suegg_entrypoint_16(actor);
                }
            }
            break;
    }
    if (((GoldenEggPendingFlags1041 *) data)->expired)
        _suegg_entrypoint_3(actor);
}

int *chegggolden_entrypoint_0()
{
    return &D_808003F0_chegggolden;
}

u8 *chegggolden_entrypoint_1(Actor *unk_0, s32 unk_1, f32 unk_2[3], s32 unk_3)
{
    Actor *egg;

    _sueggmove_entrypoint_10(unk_0);
    egg = _suegg_entrypoint_11(0x15f, unk_1, unk_3);
    *(f32 *) ((char *) egg + 0x38) = 0.134f;
    _suegg_entrypoint_1(egg, 3e+01f);
    _sueggmove_entrypoint_5(egg, 1);
    _sueggmove_entrypoint_6(egg, -2.2e+03f, -22000.0f);
    _sueggmove_entrypoint_7(egg, unk_2);
    *(u8 *) ((char *) egg + 0x72) = (*(u8 *) ((char *) egg + 0x72) & 0xFF03) | 8;
    return egg;
}

Actor *chegggolden_entrypoint_2(s32 unk_0, s32 unk_1, s32 unk_2, s32 unk_3)
{
    Actor *egg;

    _sueggmove_entrypoint_10(unk_0, unk_1);
    egg = _suegg_entrypoint_11(0x15F, unk_1, unk_3);
    egg->scale = 0.25f;
    _sueggmove_entrypoint_5(egg, 0);
    _sueggmove_entrypoint_6(egg, 0.0f, -100000.0f);
    _suegg_entrypoint_1(egg, 30.0f);
    _sueggmove_entrypoint_7(egg, unk_2);
    egg->unk70_10 = 1;
    return egg;
}

// TU-NOTE: .data is defined in C (values from the ROM). The table points to functions of this file; IDO's
// assembler schedules them differently unless it is in the same unit. D_808003F0_chegggolden is int[].
extern void func_80105834();
extern void _subaddiedraw25d_entrypoint_2();
extern void _suegg_entrypoint_2();
extern void _suegg_entrypoint_0();
extern void _suegg_entrypoint_5();
extern void func_80107C2C();
extern void _suegg_entrypoint_17();
int D_808003F0_chegggolden[20] = {0x26C015F,
                                  0x9C30001,
                                  0x0,
                                  (u32) func_80800110_chegggolden,
                                  (u32) func_80105834,
                                  (u32) _subaddiedraw25d_entrypoint_2,
                                  0x0,
                                  0x3F800000,
                                  0x0,
                                  0x4,
                                  (u32) _suegg_entrypoint_2,
                                  (u32) _suegg_entrypoint_0,
                                  0x4C0000,
                                  (u32) _suegg_entrypoint_5,
                                  (u32) func_80107C2C,
                                  -0x78000000,
                                  (u32) _suegg_entrypoint_17,
                                  0x0,
                                  0x0,
                                  0x0};
