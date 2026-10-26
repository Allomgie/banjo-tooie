#include "common.h"

extern int D_808001F0_chidgoldhorde;
typedef struct { s16 local_0; s16 local_1; s16 local_2; s16 local_3; f32 local_4; } GoldHordeState59;
extern void *func_80100094(Actor *, u32);
extern f32 func_800DC0C0(void);
extern void _chidgoldhorde_entrypoint_1(void);
typedef struct { s16 local_0; s16 local_1; u8 pad_0[4]; f32 local_2; } GoldHordeState;
extern s32 func_800BEA88(s32);
typedef struct { u32 pad_0; s16 local_0; s16 local_1; } GoldHordeSparkles;
extern Actor *func_80106790(s32);
extern void func_800EE88C();

int chidgoldhorde_entrypoint_0()
{
  return &D_808001F0_chidgoldhorde;
}

void func_8080000C_chidgoldhorde(Actor *param_0)
{
    GoldHordeState *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_800BEA88(0);
    local_0->local_0 = param_0->unk74_7;
    local_0->local_1 = _glidmake_entrypoint_3(local_1, local_0->local_0);
    local_0->local_2 = param_0->rotation[1] * (1.0f / 360.0f);
    param_0->unk64_16 = 0;
}

void chidgoldhorde_entrypoint_1(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s8 param_3[3];
{
    s32 local_2;
    GoldHordeSparkles *local_3;
    f32 local_0[3];
    f32 local_1[3];

    local_3 = func_80100094(func_80106790(param_2), 0);
    if (local_3->local_0++ == local_3->local_1) {
        func_800EE88C(local_0, param_0);
        for (local_2 = 0; local_2 < 3; local_2++) {
            local_1[local_2] = param_3[local_2] * 0.39370078f;
        }
        func_800EF04C(local_0, local_1);
        _fxsparkle_entrypoint_1(local_0, 9);
    }
}

void func_8080015C_chidgoldhorde(Actor *param_0)
{
    GoldHordeState59 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (func_800DC0C0() < local_0->local_4) {
        local_1 = func_800BEA88(0);
        local_0->local_2 = 0;
        local_0->local_3 = func_800DC128(0, local_0->local_1);
        _glid_entrypoint_3(local_1, local_0->local_0, _chidgoldhorde_entrypoint_1, param_0->unk0);
    }
}
