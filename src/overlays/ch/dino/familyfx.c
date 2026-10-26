#include "common.h"

extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 func_801022E4(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800EA05C(void);
extern f32 func_800DC178(f32, f32);
extern void func_800C4140(s32, f32 *, s32);
extern void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
typedef struct { f32 times[4]; } DinoFamilyFxTimes;





































void func_80800A28_chdinofamilyfx(f32 *param_0, f32 param_1, s32 param_2, void *param_3);

void chdinofamilyfx_entrypoint_0(Actor *param_0)
{
    extern u8 D_80800BD0_chdinofamilyfx[];
    extern u8 D_80800BF8_chdinofamilyfx[];
    extern u8 D_80800C20_chdinofamilyfx[];
    extern DinoFamilyFxTimes D_80800BC0_chdinofamilyfx;

    switch (func_801022E4(param_0)) {
        case 0x3F7: {
            f32 local_0[3];
            f32 local_1[3];
            s32 local_10;
            if (func_80101E14(param_0, 0.04f)) {
                func_800C4140(
                    0x7FEDAD02,
                    (char *)param_0 + 4,
                    0x07D0012C
                );
            } else if (func_80101E14(param_0, 0.17f)) {
                func_800C4140(
                    0x930DAD02,
                    (char *)param_0 + 4,
                    0x07D0012C
                );
            }

            if (func_80101E14(param_0, 0.37f)) {
                _subaddieskeleton_entrypoint_0(
                    param_0,
                    0x2B,
                    local_0
                );

                func_80800A28_chdinofamilyfx(
                    local_0,
                    *(f32 *)((char *)param_0 + 0x48),
                    2,
                    D_80800BD0_chdinofamilyfx
                );

                func_800C4140(
                    0xA62FA503,
                    (char *)param_0 + 4,
                    0x07D0012C
                );
            }

            if (func_80101E14(param_0, 0.4f)) {
                local_10 = func_800EA05C() == 0x118;

                _subaddieskeleton_entrypoint_0(
                    param_0,
                    0x10,
                    local_1
                );

                func_80800A28_chdinofamilyfx(
                    local_1,
                    *(f32 *)((char *)param_0 + 0x48) + 45.0f,
                    1,
                    D_80800BF8_chdinofamilyfx
                );

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_1,
                        *(f32 *)((char *)param_0 + 0x48) + 45.0f,
                        1,
                        D_80800C20_chdinofamilyfx
                    );
                }

                _subaddieskeleton_entrypoint_0(
                    param_0,
                    6,
                    local_1
                );

                func_80800A28_chdinofamilyfx(
                    local_1,
                    *(f32 *)((char *)param_0 + 0x48) + 135.0f,
                    1,
                    D_80800BF8_chdinofamilyfx
                );

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_1,
                        *(f32 *)((char *)param_0 + 0x48) + 135.0f,
                        1,
                        D_80800C20_chdinofamilyfx
                    );
                }

                _subaddieskeleton_entrypoint_0(
                    param_0,
                    0x14,
                    local_1
                );

                func_80800A28_chdinofamilyfx(
                    local_1,
                    *(f32 *)((char *)param_0 + 0x48) + 225.0f,
                    1,
                    D_80800BF8_chdinofamilyfx
                );

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_1,
                        *(f32 *)((char *)param_0 + 0x48) + 225.0f,
                        1,
                        D_80800C20_chdinofamilyfx
                    );
                }

                _subaddieskeleton_entrypoint_0(
                    param_0,
                    0x1E,
                    local_1
                );

                func_80800A28_chdinofamilyfx(
                    local_1,
                    *(f32 *)((char *)param_0 + 0x48) + 315.0f,
                    1,
                    D_80800BF8_chdinofamilyfx
                );

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_1,
                        *(f32 *)((char *)param_0 + 0x48) + 315.0f,
                        1,
                        D_80800C20_chdinofamilyfx
                    );
                }

                func_800C4140(
                    0x7FF38C4A,
                    (char *)param_0 + 4,
                    0x07D0012C
                );
            }
            break;

        }
        case 0x14D: {
            DinoFamilyFxTimes local_8 = D_80800BC0_chdinofamilyfx;

            if (func_80101E14(param_0, 0.34f) ||
                func_80101E14(param_0, 0.64f)) {
                func_800C4140(
                    0x99738D51,
                    (char *)param_0 + 4,
                    0x07D0012C
                );
                break;
            }

            if (func_80101E14(param_0, 0.76f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(1.0f, 1.1f) * 1023.0f) << 21) + 0xDAD33,
                    (char *)param_0 + 4,
                    0x07D0012C
                );
            }
            break;

        }
        case 0x14C: {
            s32 local_10;
            s32 local_11;
            f32 local_2[3];
            f32 local_3[3];
            f32 local_4[3];
            f32 local_5[3];
            local_10 = func_800EA05C() == 0x118;
            local_11 = func_800EA05C() == 0x114 || local_10;

            if (func_80101E14(param_0, 0.49f)) {
                _subaddieskeleton_entrypoint_0(
                    param_0,
                    0x1E,
                    local_2
                );

                if (local_11) {
                    func_80800A28_chdinofamilyfx(
                        local_2,
                        *(f32 *)((char *)param_0 + 0x48) + 180.0f,
                        1,
                        D_80800BF8_chdinofamilyfx
                    );
                }

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_2,
                        *(f32 *)((char *)param_0 + 0x48) + 180.0f,
                        3,
                        D_80800C20_chdinofamilyfx
                    );
                }

                func_800C4140(
                    0x7FF38C4B,
                    local_2,
                    0x07D0012C
                );
                break;
            }

            if (func_80101E14(param_0, 0.72f)) {
                _subaddieskeleton_entrypoint_0(
                    param_0,
                    0x14,
                    local_3
                );

                if (local_11) {
                    func_80800A28_chdinofamilyfx(
                        local_3,
                        *(f32 *)((char *)param_0 + 0x48) + 180.0f,
                        1,
                        D_80800BF8_chdinofamilyfx
                    );
                }

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_3,
                        *(f32 *)((char *)param_0 + 0x48) + 180.0f,
                        3,
                        D_80800C20_chdinofamilyfx
                    );
                }

                func_800C4140(
                    0x7FF38C4B,
                    local_3,
                    0x07D0012C
                );
                break;
            }

            if (func_80101E14(param_0, 0.55f)) {
                _subaddieskeleton_entrypoint_0(
                    param_0,
                    0x10,
                    local_4
                );

                if (local_11) {
                    func_80800A28_chdinofamilyfx(
                        local_4,
                        *(f32 *)((char *)param_0 + 0x48) + 180.0f,
                        1,
                        D_80800BF8_chdinofamilyfx
                    );
                }

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_4,
                        *(f32 *)((char *)param_0 + 0x48) + 180.0f,
                        3,
                        D_80800C20_chdinofamilyfx
                    );
                }
                break;
            }

            if (func_80101E14(param_0, 0.6f)) {
                _subaddieskeleton_entrypoint_0(
                    param_0,
                    6,
                    local_5
                );

                if (local_11) {
                    func_80800A28_chdinofamilyfx(
                        local_5,
                        *(f32 *)((char *)param_0 + 0x48) + 180.0f,
                        1,
                        D_80800BF8_chdinofamilyfx
                    );
                }

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_5,
                        *(f32 *)((char *)param_0 + 0x48) + 180.0f,
                        3,
                        D_80800C20_chdinofamilyfx
                    );
                }
            }
            break;

        }
        case 0x3F8: {
            s32 local_13;
            s32 local_12;
            f32 local_6[3];
            s32 local_10;

            if (func_80101E14(param_0, 0.19f) ||
                func_80101E14(param_0, 0.46f)) {
                local_13 = 0x44B;
                local_12 = 1;
            } else if (func_80101E14(param_0, 0.8f)) {
                local_13 = 0x44A;
                local_12 = 2;
            } else {
                local_13 = 0;
            }

            if (local_13 != 0) {
                local_10 = func_800EA05C() == 0x118;

                _subaddieskeleton_entrypoint_0(
                    param_0,
                    0x10,
                    local_6
                );

                func_80800A28_chdinofamilyfx(
                    local_6,
                    *(f32 *)((char *)param_0 + 0x48) + 45.0f,
                    local_12,
                    D_80800BF8_chdinofamilyfx
                );

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_6,
                        *(f32 *)((char *)param_0 + 0x48) + 45.0f,
                        3,
                        D_80800C20_chdinofamilyfx
                    );
                }

                _subaddieskeleton_entrypoint_0(
                    param_0,
                    6,
                    local_6
                );

                func_80800A28_chdinofamilyfx(
                    local_6,
                    *(f32 *)((char *)param_0 + 0x48) + 135.0f,
                    local_12,
                    D_80800BF8_chdinofamilyfx
                );

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_6,
                        *(f32 *)((char *)param_0 + 0x48) + 135.0f,
                        3,
                        D_80800C20_chdinofamilyfx
                    );
                }

                _subaddieskeleton_entrypoint_0(
                    param_0,
                    0x14,
                    local_6
                );

                func_80800A28_chdinofamilyfx(
                    local_6,
                    *(f32 *)((char *)param_0 + 0x48) + 225.0f,
                    local_12,
                    D_80800BF8_chdinofamilyfx
                );

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_6,
                        *(f32 *)((char *)param_0 + 0x48) + 225.0f,
                        3,
                        D_80800C20_chdinofamilyfx
                    );
                }

                _subaddieskeleton_entrypoint_0(
                    param_0,
                    0x1E,
                    local_6
                );

                func_80800A28_chdinofamilyfx(
                    local_6,
                    *(f32 *)((char *)param_0 + 0x48) + 315.0f,
                    local_12,
                    D_80800BF8_chdinofamilyfx
                );

                if (local_10) {
                    func_80800A28_chdinofamilyfx(
                        local_6,
                        *(f32 *)((char *)param_0 + 0x48) + 315.0f,
                        3,
                        D_80800C20_chdinofamilyfx
                    );
                }

                func_800C4140(
                    (local_13 & 0x7FF) + 0x7FF38800,
                    (char *)param_0 + 4,
                    0x07D0012C
                );
            }

            if (func_80101E14(param_0, 0.65f)) {
                func_800C4140(
                    0x7FEDAE1F,
                    (char *)param_0 + 4,
                    0x07D0012C
                );
            }
            break;
        }
    }
}

void func_80800A28_chdinofamilyfx(f32 *param_0, f32 param_1, s32 param_2, void *param_3)
{
    s32 local_2;
    f32 local_0[3];
    f32 local_1[3];
    local_2 = func_800B53A4(param_2);
    func_800EEC30(local_0, 10.0f, param_1, 200.0f);
    func_800EEC30(local_1, 25.0f, param_1, 300.0f);
    func_800BA930(local_2, (s16)(s32)local_0[0], (s16)(s32)local_0[1], (s16)(s32)local_0[2], (s32)local_1[0], (s32)local_1[1], (s32)local_1[2]);
    func_800EF334(local_0, -0.5f);
    func_800EF334(local_1, -0.5f);
    func_800BA450(local_2, (s16)(s32)local_0[0], -200, (s16)(s32)local_0[2], (s32)local_1[0], -400, (s32)local_1[2]);
    func_800BABB8(local_2, param_0, NULL, 1.0f, param_3);
    func_800BA22C(local_2, param_2);
}
