#include "common.h"

extern f32 _scinfobar_entrypoint_18(s32);
extern void func_800E253C(f32);
extern s32 _scinfobar_entrypoint_20(s32);

void sccustom_banjo_entrypoint_0(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s32 local_0;
    s32 n;
    f32 fv;
    int lim;
    s32 cnt;
    s32 mode;
    s32 scale;
    s32 cap;
    s32 i;
    s32 pos;
    s32 sp60[2];
    s32 alpha;

    local_0 = func_800D674C(0xB4D);
    n = _scinfobar_entrypoint_11(param_1);
    fv = _scinfobar_entrypoint_18(param_1);
    lim = _scinfobar_entrypoint_19(param_1);
    cnt = _scinfobar_entrypoint_20(param_1);
    mode = _scinfobar_entrypoint_14(param_1);
    cap = (s32)(((f32)(cnt * 0 + 0x28)) * fv);
    if (n < cap) {
        if (1) {}
        if (1) {}
        scale = (s32)((1.0f - ((f32)(cap - n)) / ((f32)cap)) * 256.0f);
    } else {
        scale = 0x100;
    }
    i = cnt - 1;
    if (i >= 0) {
        do {
            pos = (s32)(((f32)(i * 0x14 + 0x28)) * fv);
            if (n < pos) {
                pos = n;
            }
            switch (mode) {
            case 1:
                if (lim == i + 1) {
                    alpha = 0xFF;
                } else {
                    alpha = 0x78;
                }
                break;
            case 2:
                alpha = 0x78;
                break;
            default:
                if (i < lim) {
                    alpha = 0xFF;
                } else {
                    alpha = 0x78;
                }
                break;
            }
            func_800E257C((alpha * scale) >> 8);
            func_800E253C(fv);
            sp60[1] = param_3 * 4;
            sp60[0] = (param_2 + pos) * 4;
            func_800E30E0(param_0, local_0, 0, sp60);
            i--;
        } while (i >= 0);
    }
}

void sccustom_banjo_entrypoint_1(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s32 local_0;
    s32 n;
    f32 fv;
    s32 lim;
    s32 cnt;
    s32 scale;
    s32 cap;
    s32 i;
    s32 pos;
    s32 sp60[2];
    s32 alpha;

    local_0 = func_800D674C(0x9DA);
    n = _scinfobar_entrypoint_11(param_1);
    fv = _scinfobar_entrypoint_18(param_1);
    lim = func_800CF6B0();
    cnt = func_800CF6D0();
    cap = (s32)(((f32)(cnt * 0 + 0x28)) * fv);
    if (n < cap) {
        scale = (s32)((1.0f - ((f32)(cap - n)) / ((f32)cap)) * 256.0f);
    } else {
        scale = 0x100;
    }
    i = cnt - 1;
    if (i >= 0) {
        do {
            pos = (s32)(((f32)(i * 0x14 + 0x28)) * fv);
            if (n < pos) {
                pos = n;
            }
            if (i < lim) {
                alpha = 0xFF;
                func_800E24F8(0x80, 0x80, 0xFF);
            } else {
                alpha = 0x78;
            }
            func_800E257C((alpha * scale) >> 8);
            func_800E253C(fv);
            sp60[0] = param_2 * 4;
            sp60[1] = (param_3 + pos) * 4;
            func_800E30E0(param_0, local_0, 0, sp60);
            i--;
        } while (i >= 0);
    }
}

s32 sccustom_banjo_entrypoint_2(s32 param_0) {
    s32 local_0 = _scinfobar_entrypoint_20(param_0) - 1;
    f32 local_1 = _scinfobar_entrypoint_18(param_0);
    return (local_0 * 20 + 0x28) * local_1;
}

s32 sccustom_banjo_entrypoint_3(s32 param_0)
{
    s32 local_0;
    f32 local_1;

    local_0 = func_800CF6D0() - 1;
    local_1 = _scinfobar_entrypoint_18(param_0);
    local_1 = (local_0 * 20 + 40) * local_1;
    return (s32)local_1;
}
