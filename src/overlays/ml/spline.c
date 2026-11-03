#include "common.h"

extern f32 func_800F0D50(f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEF94(f32[3]);
typedef void (*SplineFn)(f32, s32, f32 *, f32 *);
extern f32 mlAbsF(f32);

void mlspline_entrypoint_0(f32 param_0, s32 param_1, f32 param_2[2][3], f32 param_3[3])
{
    s32 local_0;
    f32 *local_1;
    f32 *local_2;

    for (local_0 = 0, local_1 = param_2[0], local_2 = param_3; local_0 < 3;
         local_0++, local_1++, local_2++) {
        *local_2 = local_1[0] + (local_1[3] - local_1[0]) * param_0;
    }
}

void mlspline_entrypoint_1(f32 param_0, s32 param_1, f32 *param_2, f32 *param_3)
{
    f32 local_0;
    f32 local_1;

    local_0 = param_2[0];
    local_1 = param_2[1];
    *param_3 = (local_1 - local_0) * param_0 + local_0;
}

void mlspline_entrypoint_2(f32 param_0, s32 param_1, f32 param_2[][3], f32 *param_3)
{
    s32 i;
    f32 a;
    f32 b;
    f32 c;

    for (i = 0; i < 3; i++) {
        a = param_2[0][i];
        b = param_2[1][i];
        c = param_2[2][i];
        param_3[i] = ((c + a) - 2.0f * b) * (param_0 + param_0) + ((4.0f * b - 3.0f * a) - c);
        if (1)
            param_3[i] *= param_0;
        param_3[i] += a;
    }
}

void mlspline_entrypoint_3(f32 param_0, s32 param_1, u8 *param_2, f32 *param_3)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;

    local_0 = *(f32 *) ((s8 *) param_2 + 0);
    local_2 = *(f32 *) ((s8 *) param_2 + 4);
    local_1 = *(f32 *) ((s8 *) param_2 + 8);
    *param_3 = (((((local_1 + local_0) - (2.0f * local_2)) * (2.0f * param_0)) +
                 (((4.0f * local_2) - (3.0f * local_0)) - local_1)) *
                param_0) +
               local_0;
}

void mlspline_entrypoint_4(f32 param_0, s32 param_1, f32 param_2[][3], volatile f32 *param_3)
{
    s32 local_1;
    s32 local_0;
    f32 local_2;
    f32 local_3;
    f32 local_3_b;
    f32 local_4;
    f32 local_5;
    f32 local_5_b;
    f32 local_6;

    s32 k0 = 2;
    s32 k1 = 3;
    f32 csx_local_4;
    f32 csx_local_3;
    local_0 = param_1 - 1;
    local_2 = func_800F0D50(param_0, 0.0f, 1.0f) * local_0;
    local_1 = local_2;
    param_0 = local_2 - local_1;

    if (local_1 == 0) {
        for (; local_1 < 3; local_1++) {
            local_3 = param_2[0][local_1];
            csx_local_4 = param_2[1][local_1];
            local_4 = csx_local_4;
            local_5 = param_2[2][local_1];
            param_3[local_1] = ((local_5 - local_3) * 0.5f + (local_3 - local_4) * 1.5f) * param_0 +
                               ((2.0f * local_4 - local_5 * 0.5f) - 1.5f * local_3);
            param_3[local_1] *= param_0;
            param_3[local_1] += (local_4 - local_3) * 0.5f;
            param_3[local_1] *= param_0;
            param_3[local_1] += local_3;
            continue;
        }
    } else {
        local_1--;
        if (param_1 == local_1 + k0) {
            param_2 = (f32(*)[3])((f32 *) param_2 + (param_1 - 1) * 3);
            func_800EE7F8(param_3, (f32 *) param_2);
            return;
        }
        param_2 = (f32(*)[3])((f32 *) param_2 + local_1 * 3);
        if (param_1 == local_1 + k1) {
            for (local_1 = 0; local_1 < 3; local_1++) {
                csx_local_3 = param_2[0][local_1];
                local_3 = csx_local_3;
                local_4 = param_2[1][local_1];
                local_5_b = param_2[2][local_1];
                param_3[local_1] =
                    ((local_5_b - local_3) * 0.5f + (local_4 - local_5_b) * 1.5f) * param_0 +
                    (local_3 - local_4 * 2.5f + local_5_b * 1.5f);
                param_3[local_1] *= param_0;
                param_3[local_1] += (local_5_b - local_3) * 0.5f;
                param_3[local_1] *= param_0;
                param_3[local_1] += local_4;
                continue;
            }
        } else {
            for (local_1 = 0; local_1 < 3; local_1++) {
                local_3_b = param_2[0][local_1];
                local_4 = param_2[1][local_1];
                local_5 = param_2[2][local_1];
                local_6 = param_2[3][local_1];
                param_3[local_1] =
                    ((local_6 - local_3_b) * 0.5f + (local_4 - local_5) * 1.5f) * param_0 +
                    ((local_3_b - local_4 * 2.5f + 2.0f * local_5) - local_6 * 0.5f);
                param_3[local_1] *= param_0;
                param_3[local_1] += (local_5 - local_3_b) * 0.5f;
                param_3[local_1] *= param_0;
                param_3[local_1] += local_4;
                continue;
            }
        }
    }
}

void mlspline_entrypoint_5(f32 param_0, s32 param_1, f32 param_2[][3], volatile f32 *param_3)
{
    s32 local_1;
    s32 local_0 = param_1 - 1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 csx_local_3;
    f32 csx_local_5;
    f32 b2;
    f32 b3;
    s32 k1 = 3;
    s32 new_var;
    f32 s;

    local_2 = func_800F0D50(param_0, 0.0f, 1.0f) * local_0;
    local_1 = local_2;
    param_0 = local_2 - local_1;
    if (local_1 == 0) {
        for (; local_1 < 3; local_1++) {
            local_3 = param_2[0][local_1];
            local_4 = param_2[1][local_1];
            csx_local_5 = param_2[2][local_1];
            local_5 = csx_local_5;
            param_3[local_1] =
                ((local_5 - local_3) * 0.16666667f - (local_4 - local_3) * 0.5f) * param_0 +
                (local_4 - local_3) * 0.5f;
            param_3[local_1] *= param_0;
            param_3[local_1] += (local_4 - local_3) * 0.5f;
            param_3[local_1] *= param_0;
            param_3[local_1] += (local_3 * 5.0f + local_4) * 0.16666667f;
            if (param_2) {
            }
        }
        return;
    }
    local_1--;
    if (param_1 - 2 == local_1) {
        func_800EE7F8(param_3, &((f32 *) param_2)[(param_1 - 1) * 3]);
        return;
    }
    param_2 = (f32(*)[3])((f32 *) param_2 + local_1 * 3);
    if (param_1 == local_1 + k1) {
        for (local_1 = 0; local_1 != 3; local_1++) {
            csx_local_3 = param_2[0][local_1];
            local_3 = csx_local_3;
            local_5 = param_2[2][local_1];
            b2 = param_2[1][local_1];
            s = local_3 + local_5;
            param_3[local_1] =
                ((local_5 - local_3) * 0.16666667f + (b2 - local_5) * 0.5f) * param_0 +
                (s * 0.5f - b2);
            param_3[local_1] *= param_0;
            param_3[local_1] += (local_5 - local_3) * 0.5f;
            param_3[local_1] *= param_0;
            param_3[local_1] += s * 0.16666667f + b2 * 0.6666667f;
            local_3 = param_2[0][local_1];
        }
        return;
    }
    for (local_1 = 0; local_1 != 3; local_1++) {
        local_3 = param_2[0][local_1];
        b3 = param_2[1][local_1];
        local_5 = param_2[2][local_1];
        local_6 = param_2[3][local_1];
        param_3[local_1] = ((local_6 - local_3) * 0.16666667f + (b3 - local_5) * 0.5f) * param_0;
        param_3[local_1] += (local_3 + local_5) * 0.5f - b3;
        new_var = local_1;
        param_3[new_var] *= param_0;
        param_3[new_var] += (local_5 - local_3) * 0.5f;
        param_3[new_var] *= param_0;
        param_3[new_var] += (local_3 + local_5) * 0.16666667f + b3 * 0.6666667f;
    }
}

int mlspline_entrypoint_6(f32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    func_800EFB24(param_3 | 0, param_2 + 0xC);
}

void mlspline_entrypoint_7(f32 param_0, s32 param_1, f32 param_2[][3], f32 *param_3)
{
    s32 i;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;

    for (i = 0; i != 3; i++) {
        local_1 = param_2[0][i];
        local_2 = param_2[1][i];
        local_3 = param_2[2][i];
        local_4 = (local_1 - 2.0f * local_2 + local_3) * (4.0f * param_0);
        local_5 = 4.0f * local_2 - 3.0f * local_1 - local_3;
        param_3[i] = local_4 + local_5;
        if (param_2) {
        }
    }
}

void mlspline_entrypoint_8(f32 param_0, s32 param_1, f32 *param_2, volatile f32 *param_3)
{
    s32 local_1;
    s32 local_4;
    f32 local_2;
    s32 local_1_b;
    f32 a;
    f32 b;
    f32 a1;
    f32 b1;
    f32 c1;
    f32 a3;
    f32 b3;
    f32 c3;
    f32 a4;
    f32 b4;
    f32 c4;
    f32 d4;
    s32 k0 = 2;
    s32 k1 = 3;

    local_4 = param_1 - 1;
    local_2 = func_800F0D50(param_0, 0.0f, 1.0f) * local_4;
    local_1 = local_2;
    param_0 = local_2 - local_1;
    if (local_1 == 0) {
        for (; local_1 < 3; local_1++) {
            a1 = param_2[local_1];
            b1 = param_2[local_1 + 3];
            c1 = param_2[local_1 + 6];
            param_3[local_1] = (((a1 - b1) * 4.5f + 1.5f * (c1 - a1)) * param_0) +
                               (((4.0f * b1) - c1) - (3.0f * a1));
            param_3[local_1] *= param_0;
            param_3[local_1] += 0.5f * (b1 - a1);
        }
        return;
    }
    local_1--;
    param_2 += local_1 * 3;
    if (param_1 == local_1 + k0) {
        for (local_1 = 0; local_1 != 3; local_1++) {
            a = param_2[local_1];
            b = param_2[local_1 + 3];
            param_3[local_1] = (b - a) * 0.5f;
        }
    } else if (param_1 == local_1 + k1) {
        for (local_1_b = 0; local_1_b != 3; local_1_b++) {
            a3 = param_2[local_1_b];
            b3 = param_2[local_1_b + 3];
            c3 = param_2[local_1_b + 6];
            param_3[local_1_b] = ((b3 - c3) * 4.5f + 1.5f * (c3 - a3)) * param_0 +
                                 (((a3 + a3) - 5.0f * b3) + 3.0f * c3);
            param_3[local_1_b] *= param_0;
            param_3[local_1_b] += 0.5f * (c3 - a3);
        }
    } else {
        for (local_1_b = 0; local_1_b != 3; local_1_b++) {
            a4 = param_2[local_1_b];
            b4 = param_2[local_1_b + 3];
            c4 = param_2[local_1_b + 6];
            d4 = param_2[local_1_b + 9];
            param_3[local_1_b] = ((b4 - c4) * 4.5f + 1.5f * (d4 - a4)) * param_0 +
                                 ((((a4 + a4) - 5.0f * b4) + 4.0f * c4) - d4);
            param_3[local_1_b] *= param_0;
            param_3[local_1_b] += 0.5f * (c4 - a4);
        }
    }
}

void mlspline_entrypoint_9(f32 param_0, s32 param_1, f32 param_2[][1], volatile f32 *param_3)
{
    s32 local_1;
    s32 local_0;
    f32 local_2;
    f32 local_3;
    f32 local_3_b;
    f32 local_4;
    f32 local_5;
    f32 local_5_b;
    f32 local_6;

    s32 k0 = 2;
    s32 k1 = 3;
    f32 csx_local_4;
    f32 csx_local_3;
    local_0 = param_1 - 1;
    local_2 = func_800F0D50(param_0, 0.0f, 1.0f) * local_0;
    local_1 = local_2;
    param_0 = local_2 - local_1;

    if (local_1 == 0) {
        for (; local_1 < 1; local_1++) {
            local_3 = param_2[0][local_1];
            csx_local_4 = param_2[1][local_1];
            local_4 = csx_local_4;
            local_5 = param_2[2][local_1];
            param_3[local_1] = ((local_5 - local_3) * 0.5f + (local_3 - local_4) * 1.5f) * param_0 +
                               ((2.0f * local_4 - local_5 * 0.5f) - 1.5f * local_3);
            param_3[local_1] *= param_0;
            param_3[local_1] += (local_4 - local_3) * 0.5f;
            param_3[local_1] *= param_0;
            param_3[local_1] += local_3;
            continue;
        }
    } else {
        local_1--;
        if (param_1 == local_1 + k0) {
            param_2 = (f32(*)[1])((f32 *) param_2 + (param_1 - 1) * 1);
            param_3[0] = param_2[0][0];
            return;
        }
        param_2 = (f32(*)[1])((f32 *) param_2 + local_1 * 1);
        if (param_1 == local_1 + k1) {
            for (local_1 = 0; local_1 < 1; local_1++) {
                csx_local_3 = param_2[0][local_1];
                local_3 = csx_local_3;
                local_4 = param_2[1][local_1];
                local_5_b = param_2[2][local_1];
                param_3[local_1] =
                    ((local_5_b - local_3) * 0.5f + (local_4 - local_5_b) * 1.5f) * param_0 +
                    (local_3 - local_4 * 2.5f + local_5_b * 1.5f);
                param_3[local_1] *= param_0;
                param_3[local_1] += (local_5_b - local_3) * 0.5f;
                param_3[local_1] *= param_0;
                param_3[local_1] += local_4;
                continue;
            }
        } else {
            for (local_1 = 0; local_1 < 1; local_1++) {
                local_3_b = param_2[0][local_1];
                local_4 = param_2[1][local_1];
                local_5 = param_2[2][local_1];
                local_6 = param_2[3][local_1];
                param_3[local_1] =
                    ((local_6 - local_3_b) * 0.5f + (local_4 - local_5) * 1.5f) * param_0 +
                    ((local_3_b - local_4 * 2.5f + 2.0f * local_5) - local_6 * 0.5f);
                param_3[local_1] *= param_0;
                param_3[local_1] += (local_5 - local_3_b) * 0.5f;
                param_3[local_1] *= param_0;
                param_3[local_1] += local_4;
                continue;
            }
        }
    }
}

void mlspline_entrypoint_10(f32 param_0, int param_1, f32 *param_2, volatile f32 *param_3)
{
    s32 local_1;
    s32 local_0 = param_1 - 1;
    f32 local_2;
    f32 new_var;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7;
    local_2 = func_800F0D50(param_0, 0.0f, 1.0f) * local_0;
    local_1 = local_2;
    param_0 = local_2 - local_1;
    if (local_1 == 0) {
        for (; local_1 < 3; local_1++) {
            local_4 = param_2[local_1];
            local_5 = param_2[local_1 + 3];
            local_6 = param_2[local_1 + 6];
            local_3 = local_5 - local_4;
            param_3[local_1] =
                ((((local_6 - local_4) * 0.5f) - ((local_5 - local_4) * 1.5f)) * param_0) + local_3;
            param_3[local_1] *= param_0;
            param_3[local_1] += (local_5 - local_4) * 0.5f;
        }

        return;
    }
    local_1--;
    param_2 += local_1 * 3;
    if (param_1 == (local_1 + 2)) {
        for (local_1 = 0; local_1 != 3; local_1++) {
            new_var = param_2[local_1];
            param_0 = (param_2[local_1 + 3] - new_var) * 0.5f;
            param_3[local_1] = param_0;
        }

        return;
    }
    if (param_1 == (local_1 + 3)) {
        for (local_1 = 0; local_1 != 3; local_1++) {
            local_4 = param_2[local_1];
            local_6 = param_2[local_1 + 6];
            local_5 = param_2[local_1 + 3];
            local_3 = (local_6 - local_4) * 0.5f;
            param_3[local_1] = ((((local_5 - local_6) * 1.5f) + local_3) * param_0) +
                               ((local_4 + local_6) - (local_5 + local_5));
            param_3[local_1] *= param_0;
            param_3[local_1] += local_3;
        }

        return;
    }
    for (local_1 = 0; local_1 != 3; local_1++) {
        local_4 = param_2[local_1];
        local_5 = param_2[local_1 + 3];
        local_6 = param_2[local_1 + 6];
        local_7 = param_2[local_1 + 9];
        param_3[local_1] =
            ((((local_7 - local_4) * 0.5f) + ((local_5 - local_6) * 1.5f)) * param_0) +
            ((local_4 + local_6) - (local_5 + local_5));
        param_3[local_1] *= param_0;
        param_3[local_1] += (local_6 - local_4) * 0.5f;
    }
}

f32 func_8080145C_mlspline(f32 param_0, s32 param_1, f32 *param_2,
                           void (*param_3)(f32, s32, f32 *, f32 *))
{
    f32 local_0[3];

    param_3(param_0, param_1, param_2, local_0);
    return func_800EEF94(local_0);
}

f32 func_80801488_mlspline(f32 *pts, s32 cnt, f32 lo, f32 hi, s32 maxIter, f32 tol, SplineFn fn)
{
    s32 pad[2];
    f32 h6;
    f32 fsum;
    s32 pad2[3];
    f32 S;
    f32 prev;
    f32 half;
    f32 oldSum;
    f32 fm;
    f32 fa;
    f32 h;
    s32 n;
    s32 m;
    s32 i;

    n = 1;
    h = hi - lo;
    h6 = h * 0.1666666567f;
    fa = func_8080145C_mlspline(lo, cnt, pts, fn);
    fsum = func_8080145C_mlspline(hi, cnt, pts, fn) + fa;
    oldSum = 0.0f;
    half = h * 0.5f;
    fm = func_8080145C_mlspline(lo + half, cnt, pts, fn);
    S = (2.0f * oldSum + fsum + 4.0f * fm) * h6;
    prev = S + S;
    while (n < maxIter && 0.0f < mlAbsF(S) && tol < mlAbsF((S - prev) / S)) {
        m = n * 2;
        h6 *= 0.5f;
        oldSum += fm;
        half *= 0.5f;
        prev = S;
        n = m;
        fm = 0.0f;
        for (i = 1; i < n * 2; i += 2) {
            fm += func_8080145C_mlspline(i * half + lo, cnt, pts, fn);
        }
        S = (2 * oldSum + fsum + 4 * fm) * h6;
    }
    if (cnt >= 4) {
        S *= cnt - 1;
    }
    return S;
}

f32 mlspline_entrypoint_11(s32 param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
    return mlAbsF(
        func_80801488_mlspline(param_1, param_0, param_2, param_3, 0x800, 0.001f, param_4));
}

f32 mlspline_entrypoint_12(s32 param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4,
                           s32 param_5)
{
    return mlAbsF(
        func_80801488_mlspline(param_1, param_0, param_2, param_3, param_4, 0.001f, param_5));
}

f32 mlspline_entrypoint_13(s32 param_0, s32 param_1, f32 param_2, f32 param_3, f32 param_4,
                           s32 (*param_5)(f32, s32, s32, f32 *))
{
    f32 step;
    f32 val;
    f32 d;
    s32 n;
    f32 t;
    f32 cur;
    f32 vec[3];
    s32 done;
    s32 iter;
    f32 x;
    f32 target;
    done = 0;
    if (param_0 >= 4) {
        n = param_0 - 1;
    } else {
        n = 1;
    }
    iter = 0;
    if (mlAbsF(param_3) < 0.01f) {
        return param_2;
    }
    param_5(param_2, param_0, param_1, vec);
    step = param_3 / (func_800EEF94(vec) * (f32) n);
    target = mlAbsF(param_3);
    cur = param_2 + step;
    do {
        t = cur;
        if (0.0f < step) {
            if (1.0f <= t) {
                if (param_4 == 1.0f) {
                    t = 1.0f;
                    val = func_80801488_mlspline(param_1, param_0, param_2, 1.0f, 0x400, 0.01f,
                                                 (s32) param_5);
                    if (val < param_3) {
                        done = 1;
                    }
                } else {
                    t = t + param_4;
                    t = t - (f32) (s32) t;
                    val = func_80801488_mlspline(param_1, param_0, param_2, 1.0f, 0x400, 0.01f,
                                                 (s32) param_5);
                    val += func_80801488_mlspline(param_1, param_0, param_4, t, 0x400, 0.01f,
                                                  (s32) param_5);
                }
            } else {
                val = func_80801488_mlspline(param_1, param_0, param_2, t, 0x400, 0.01f,
                                             (s32) param_5);
            }
        } else if (param_4 == 1.0f) {
            if (t < 0.0f) {
                t = 0.0f;
                val = func_80801488_mlspline(param_1, param_0, param_2, 0.0f, 0x400, 0.01f,
                                             (s32) param_5);
                if (param_3 < val) {
                    done = 1;
                }
            } else {
                val = func_80801488_mlspline(param_1, param_0, param_2, t, 0x400, 0.01f,
                                             (s32) param_5);
            }
        } else if (t < param_4) {
            t = t - param_4;
            t = t - (f32) (s32) t;
            t = t + 1.0f;
            val = func_80801488_mlspline(param_1, param_0, param_2, param_4, 0x400, 0.01f,
                                         (s32) param_5);
            val += func_80801488_mlspline(param_1, param_0, 1.0f, t, 0x400, 0.01f, (s32) param_5);
        } else {
            val = func_80801488_mlspline(param_1, param_0, param_2, t, 0x400, 0.01f, (s32) param_5);
        }
        if (!done && (mlAbsF(val - target) > 0.01f)) {
            param_5(t, param_0, param_1, vec);
            d = (val - param_3) / (func_800EEF94(vec) * (f32) n);
            cur = t - d;
            if (mlAbsF(d) < 0.000001f) {
                done = 1;
            }
            if (0.0f < step) {
                if (cur < param_2) {
                    cur += 1.0f - param_4;
                }
            } else if (param_2 < cur) {
                cur -= 1.0f - param_4;
            }
        } else {
            done = 1;
        }
        iter++;
    } while (!done && (iter < 10));
    return t;
}
