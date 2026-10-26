#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getX(PlayerState *);
extern f32 bastick_getY(PlayerState *);
extern void _baeggcursor_entrypoint_10(PlayerState *, f32, f32);
extern f32 func_800F1344(f32, f32, f32, f32, f32);
extern PlayerState *func_800A4CA8(PlayerState *);
extern void _ncba1p_entrypoint_8(PlayerState *, f32 *);
extern void _ncba1p_entrypoint_7(PlayerState *, f32 *);
extern f32 _bafpctrl_entrypoint_3(PlayerState *);
extern f32 func_800D8FF8(void);
extern f32 _bsdronelook_entrypoint_2(f32);
extern u32 func_800D8FEC(void);
extern f32 func_800F0DC0(f32, f32);
f32 func_80800008_baeggaim(f32 param_0, f32 param_1, f32 param_2);

s32 baeggaim_entrypoint_0() 
{
    return 0x4;
}

f32 func_80800008_baeggaim(f32 param_0, f32 param_1, f32 param_2)
{
    s32 local_0;
    for (local_0 = 0; local_0 < (s32)(func_800D8FEC() * 5); local_0++) {
        param_0 += func_800F0DC0((param_1 - param_0) * 0.04f, param_2);
    }
    return param_0;
}

void func_808000B4_baeggaim(PlayerState *param_0, f32 *param_1)
{
    f32 local_0;
    f32 local_1;
    _baeggcursor_entrypoint_3(param_0, param_1, param_1 + 1);
    local_0 = bastick_getX(param_0) * 114.0f + 114.0f + 38.0f;
    local_1 = bastick_getY(param_0) * 85.5f + 85.5f + 28.5f;
    param_1[0] = func_80800008_baeggaim(param_1[0], local_0, 7.4f);
    param_1[1] = func_80800008_baeggaim(param_1[1], local_1, 5.5f);
    _baeggcursor_entrypoint_10(param_0, param_1[0], param_1[1]);
}

void func_80800170_baeggaim(f32 *param_0, f32 *param_1, f32 param_2)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;

    local_2 = 0;
    local_1 = 0;
    local_0 = 78.0f - param_0[0];
    if (local_0 > 0.0f) local_1 = local_0;
    local_0 = 226.0f - param_0[0];
    if (local_0 < 0.0f) local_1 = local_0;
    local_0 = 61.0f - param_0[1];
    if (local_0 > 0.0f) local_2 = local_0;
    local_0 = 167.0f - param_0[1];
    if (local_0 < 0.0f) local_2 = local_0;
    param_1[0] = func_800F1344(local_1, 0, 40.0f, 0.0f, param_2);
    param_1[1] = func_800F1344(local_2, 0, 32.5f, 0.0f, param_2);
}

void func_80800264_baeggaim(PlayerState *param_0, PlayerState *param_1)
{
    s32 pad;
    f32 local_3;
    f32 local_2[3];
    f32 local_1[2];
    PlayerState *local_0;

    local_0 = func_800A4CA8(param_0);
    _ncba1p_entrypoint_8(local_0, local_2);
    local_3 = _bafpctrl_entrypoint_3(param_0) * 70.0f;
    func_80800170_baeggaim(param_1, local_1, local_3);
    local_3 = func_800D8FF8();
    local_2[1] += local_1[0] * local_3;
    if (!baflag_isTrue(param_0, 0x3A)) {
        local_2[0] += local_1[1] * local_3;
        local_2[0] = _bsdronelook_entrypoint_2(local_2[0]);
    }
    local_2[2] = 0.0f;
    _ncba1p_entrypoint_7(local_0, local_2);
}

void baeggaim_entrypoint_1(s32 arg0)
{
    _baeggcursor_entrypoint_7(arg0,0x4);
    _baeggfire_entrypoint_4(arg0);
}

void baeggaim_entrypoint_2(s32 arg0)
{
    _baeggcursor_entrypoint_7(arg0,0x3);
    _baeggfire_entrypoint_5(arg0);
}

void baeggaim_entrypoint_3(s32 param_0) {
    f32 local_0[2];
    s32 local_1;

    if (_bafpctrl_entrypoint_2() == 0) {
        func_80094AB4(param_0);
    }
    func_808000B4_baeggaim(param_0, local_0);
    if ((baflag_isTrue(param_0, 0x2E) == 0) && (_bafpctrl_entrypoint_1(param_0) == 0)) {
        func_80800264_baeggaim(param_0, local_0);
    }
    local_1 = 0;
    if (func_80094510(param_0) == 7) {
        if (bakey_held(param_0, 1) != 0) {
            local_1 = 1;
        }
    } else if (bakey_pressed(param_0, 1) != 0) {
        local_1 = 1;
    }
    if ((local_1 != 0) && (_bafpctrl_entrypoint_2(param_0) == 0) && (func_80094B14(param_0) != 0)) {
        _baeggfire_entrypoint_7(param_0);
    }
    _baeggfire_entrypoint_6(param_0);
}
