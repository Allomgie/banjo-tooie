#include "ch/transparentfish.h"

#define TRANSPARENT_FISH_ITEM_271(param_0)                                                         \
    (((param_0)->unk6C_0 && (param_0)->unk6C_0 < 13)                                               \
         ? D_80800FB4_chtransparentfish[(param_0)->unk6C_0].local_0                                \
         : 0)
extern void func_800DBEFC();
extern s32 D_80800FB8_chtransparentfish[][3];
typedef struct {
    u32 local_0;
    s32 local_1;
    s32 local_2;
} FishSpawnConfig271;
extern FishSpawnConfig271 D_80800FB4_chtransparentfish[];
extern s32 D_80800FBC_chtransparentfish[];
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_80108474(u32, f32 *, s32);
extern s32 func_800D0B68(u32, s32);
extern Unk80132ED0 *func_800D10D4(u32, u32, f32 *, s32, Unk80132ED0 *);
extern void *func_80100094(Actor *, u32);
extern Actor *_subaddielink_entrypoint_4(void *);
extern void func_800EE7F8(f32 *, f32 *);
extern int D_80801098_chtransparentfish[];
typedef struct {
    s32 local_0;
    s32 local_1;
    s32 local_2;
} CodexTransparentFishRecord65;
typedef struct {
    u32 pad_0[2];
    s32 local_0;
} TransparentFishEntry;
typedef struct Mass47FishOrigin {
    f32 local_0[3];
    s16 local_1;
    s16 local_2;
} Mass47FishOrigin;
extern Mass47FishOrigin *func_800CC63C(s32, s32);
extern void func_80102950(Actor *, f32);
extern f32 func_80102D78(Actor *, void *);
extern void func_80102924(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
typedef struct {
    f32 f0, f1, f2, f3, f4, f5, f6, f7;
} TFAD_;
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern s32 func_8010BA80(Actor *, s32, s32);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} FishJoyFlags331;
typedef struct {
    u8 pad_0[0x7C];
    u32 pad_1 : 19;
    u32 local_0 : 1;
    u32 pad_2 : 12;
} FishVisibleFlags331;
extern u8 D_80801050_chtransparentfish[];
extern f32 func_80103EAC(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_80101E14(Actor *, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA994(s32, s16, s16, s16, s32, s32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80101CDC(Actor *, f32);
extern void func_80102C58(Actor *, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F0DC0(f32, f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern void func_80800AC4_chtransparentfish(Actor *, f32 *, s32);
void func_80800B60_chtransparentfish();
s32 func_80800E10_chtransparentfish();
s32 func_80800EE0_chtransparentfish();

void func_80800000_chtransparentfish(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    Mass47FishOrigin *local_2;

    local_2 = func_800CC63C((*(u32 *) ((u8 *) param_0 + 0x70) >> 25) - 1,
                            ((*(u32 *) ((u8 *) param_0 + 0x70) << 22) >> 26) - 1);
    if (local_2->local_0[1] + local_2->local_2 <= param_0->position[1]) {
        local_1 = 1;
        func_80102950(param_0, 355.0f);
    } else if (param_0->position[1] <= local_2->local_0[1] - local_2->local_2) {
        local_1 = 1;
        func_80102950(param_0, 5.0f);
    } else {
        local_1 = 0;
    }
    if (!_subaddieDll_entrypoint_11(
            param_0, (s32) param_0->unk54,
            (s32) ((param_0->scale * 3.0f) * ((TFAD_ *) param_0->actorData)->f3))) {
        func_80102924(param_0, func_80102D78(param_0, local_2));
        param_0->unk58 = func_800DC178(1.0f, 3.0f);
    } else {
        param_0->unk58 -= func_800D8FF8();
        if (param_0->unk58 <= 0.0f) {
            param_0->unk58 = func_800DC178(1.0f, 3.0f);
            ((f32 *) param_0->actorData)[7] = func_800DC178(105.0f, 150.0f);
            if (!local_1) {
                func_80102950(param_0, func_800DC178(-8.333333f, 8.333333f));
            }
            local_0 = func_800DC178(-35.0f, 35.0f);
            if (func_80102CCC(param_0)) {
                func_80102924(param_0, param_0->rotation[1] + local_0);
            }
        }
    }
}

void func_80800204_chtransparentfish(Actor *param_0)
{
    f32 local_0;

    local_0 = _subaddiejoy_entrypoint_3(param_0) * 300.0f;
    func_80102BAC(param_0, 0.5, 0.5f, 5.0f);
    if (*(f32 *) ((u8 *) param_0 + 0x24) <= local_0) {
        *(f32 *) ((u8 *) param_0 + 0x24) = local_0;
    } else {
        *(f32 *) ((u8 *) param_0 + 0x24) -= *(f32 *) ((u8 *) param_0 + 0x24) * 0.02f;
        if (*(f32 *) ((u8 *) param_0 + 0x24) < 30.0f) {
            *(f32 *) ((u8 *) param_0 + 0x24) = 0.0f;
        }
    }
    func_8010BA80(param_0, 0x200006, 0x20);
}

void func_808002B8_chtransparentfish(Actor *param_0)
{
    if (func_800DA298(0x9F4) == 0) {
        func_800DA544(0x9F4);
        func_80800B60_chtransparentfish();
    }
    param_0->unk6C_0 = func_80800EE0_chtransparentfish(param_0->pad6C_21);
    *(f32 *) ((u8 *) param_0 + 0x24) = 150.0f;
    *(f32 *) ((u8 *) param_0 + 0x34) = 150.0f;
    *(f32 *) ((u8 *) param_0 + 0x2C) = (f32) _subaddiesect_entrypoint_1(param_0);
}

void func_80800348_chtransparentfish(Actor *param_0)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2;
    f32 local_4;
    s32 local_3;
    f32 local_5;

    _subaddiesect_entrypoint_0(param_0, (s32) *(f32 *) &param_0->actorData[5], 11);
    func_80800AC4_chtransparentfish(param_0, NULL, ((FishVisibleFlags331 *) param_0)->local_0);
    if (func_800F52B8(func_800F54E4(), param_0->unk0) != 0x14) {
        local_0 = func_800F690C(func_800F54E4());
        local_2 = func_80103EAC(param_0);
        local_4 = local_0 ? 0.5f : 0.25f;
        func_800EFA4C(local_1, param_0->position[0], param_0->position[1] + local_4 * local_2,
                      param_0->position[2]);
        local_5 = local_0 ? 0.75f : 0.5f;
        _sudeflect_entrypoint_0(local_1, 0, local_5 * local_2, 30);
    }
    if (func_80101E14(param_0, 0.01f) && func_80102CCC(param_0)) {
        local_3 = func_800B53A4(10);
        func_800BABB8(local_3, (f32 *) param_0->actorData, NULL, param_0->scale,
                      D_80801050_chtransparentfish);
        func_800BA994(local_3, (s16) (s32) param_0->rotation[0],
                      (s16) (s32) (param_0->rotation[1] - 35.0f),
                      (s16) (s32) (*(f32 *) &param_0->actorData[3] * 1.1f),
                      (s32) (s16) (s32) param_0->rotation[0], (s32) (param_0->rotation[1] + 35.0f),
                      (s32) (*(f32 *) &param_0->actorData[3] + *(f32 *) &param_0->actorData[3]));
        func_800BA22C(local_3, 10);
    }
    if (param_0->unk70_10 == 1) {
        if (((FishJoyFlags331 *) param_0)->local_0) {
            func_80800204_chtransparentfish(param_0);
            func_80101CDC(param_0,
                          func_800F10B4(*(f32 *) &param_0->actorData[3], 0, 300.0f, 3.0f, 1.5f));
        } else {
            func_80800000_chtransparentfish(param_0);
            func_80102BAC(param_0, 0.05f, 0.05f, 4.0f);
            func_80102C58(param_0, 0.05f, 0.01f, 0.5f);
            *(f32 *) &param_0->actorData[3] = func_800F15F8(*(f32 *) &param_0->actorData[3],
                                                            *(f32 *) &param_0->actorData[7], 2.0f);
            if (func_8010BA80(param_0, 0x26, 0x10)) {
                param_0->unk54 += 10.0f;
            }
        }
        *(f32 *) &param_0->actorData[4] =
            func_800F0DC0(func_800F1DCC(param_0->rotation[1], param_0->unk54) * 0.5f, 15.0f);
        param_0->rotation[2] = func_800F1FF0(param_0->rotation[2], *(f32 *) &param_0->actorData[4],
                                             0.01f, 0.005f, 0.1f);
    }
}

void func_80800690_chtransparentfish(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;

    func_80101870(param_0);
    if (param_0->unk7C_12) {
        func_800DBEFC(func_80104130(), 5, param_0->actorData);
        local_1 = param_0->unk6C_0 > 0 && param_0->unk6C_0 < 13
                      ? ((s32(*)[3]) D_80800FB4_chtransparentfish)[param_0->unk6C_0][0]
                      : 0;
        if (local_1) {
            func_800DBEFC(func_80104130(), 4, local_0);
            local_1 = param_0->unk6C_0 > 0 && param_0->unk6C_0 < 13
                          ? D_80800FB8_chtransparentfish[param_0->unk6C_0][0]
                          : 0;
            local_0[1] += local_1;
            func_80800AC4_chtransparentfish(param_0, local_0, 1);
        }
    }
}

s32 func_8080078C_chtransparentfish(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    Unk80132ED0 *local_1;

    switch (param_1) {
        case 0x3D:
            local_1 = param_0->unk0;
            if (TRANSPARENT_FISH_ITEM_271(param_0) == 0x21F) {
                if (!func_800D0B68(0x26, 1)) {
                    local_0 =
                        func_80106790(func_800D10D4(0x26, 1, param_0->position, 3, param_0->unk0));
                } else {
                    return 0;
                }
            } else if (TRANSPARENT_FISH_ITEM_271(param_0) == 0x136) {
                if (!func_800D0B68(0xB, 4)) {
                    local_0 =
                        func_80106790(func_800D10D4(0xB, 4, param_0->position, 3, param_0->unk0));
                } else {
                    return 0;
                }
            } else if (TRANSPARENT_FISH_ITEM_271(param_0) == 0x220) {
                if (!func_800D0B68(0xA, 2)) {
                    local_0 =
                        func_80106790(func_800D10D4(0xA, 2, param_0->position, 3, param_0->unk0));
                } else {
                    return 0;
                }
            } else {
                param_2 = (s32) param_0->position;
                if (param_2) {
                }
                if (param_0 && param_0 && param_0) {
                }
                local_0 = func_80108474(TRANSPARENT_FISH_ITEM_271(param_0), (f32 *) param_2, 0);
            }
            ((u8 *) local_0)[0x77] &= ~0x20;
            ((u8 *) local_0)[0x75] &= ~0x10;
            ((u8 *) local_0)[0x71] &= ~1;
            ((u8 *) local_0)[0x64] &= ~0x80;
            param_0 = func_80106790(local_1);
            _subaddielink_entrypoint_1(func_80100094(param_0, 0), local_0->unk0);
            func_80800AC4_chtransparentfish(param_0, param_0->position, 0);
            if (param_0->unk6C_0 && param_0->unk6C_0 < 13) {
                local_0->scale =
                    ((f32) *(s32 *) ((u8 *) D_80800FBC_chtransparentfish + param_0->unk6C_0 * 12) /
                     100.0f) *
                    param_0->scale;
            } else {
                local_0->scale = 0.0f;
            }
            return 1;
        case 1:
            func_80102424(param_0, 1);
            return 1;
        case 2:
            func_80107070(param_0, 1);
            return 1;
        case 0x95:
            if (!_subaddielink_entrypoint_3(func_80100094(param_0, 0))) {
                func_80108B04(param_0, 0);
            }
            return 1;
    }
    return 0;
}

void func_80800AC4_chtransparentfish(param_0, param_1, param_2) Actor *param_0;
f32 *param_1;
s32 param_2;
{
    Actor *local_0;
    local_0 = _subaddielink_entrypoint_4(func_80100094(param_0, 0));
    if (local_0) {
        if (param_1)
            func_800EE7F8(local_0->position, param_1);
        local_0->unk64_16 = param_2;
    }
}

void func_80800B30_chtransparentfish(s32 arg0)
{
    func_800DA524(FLAG3_9F4_UNK);
}

int chtransparentfish_entrypoint_0()
{
    return (int) &D_80801098_chtransparentfish;
}

CodexTransparentFishRecord65 B_808010E0_chtransparentfish[20];

void func_80800B60_chtransparentfish(void)
{
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_6;
    u32 *local_0[20];
    s32 local_5;
    s32 local_7;

    for (local_2 = 0; local_2 < 20; local_2++) {
        B_808010E0_chtransparentfish[local_2].local_0 = 0;
        B_808010E0_chtransparentfish[local_2].local_1 = -1;
        B_808010E0_chtransparentfish[local_2].local_2 = -1;
    }
    local_2 = _gccubesearch_entrypoint_9(0x295, local_0, 20);
    for (local_1 = 0; local_1 < local_2; local_1++) {
        B_808010E0_chtransparentfish[local_1].local_0 = local_0[local_1][4] >> 21;
        B_808010E0_chtransparentfish[local_1].local_1 =
            _gspropctrl_entrypoint_8(local_0[local_1]) - 50;
    }
    for (local_1 = 0; local_1 < local_2; local_1++) {
        for (local_3 = 0; local_3 < local_2; local_3++) {
            if (B_808010E0_chtransparentfish[local_1].local_0 <
                B_808010E0_chtransparentfish[local_3].local_0) {
                local_4 = B_808010E0_chtransparentfish[local_3].local_0;
                B_808010E0_chtransparentfish[local_3].local_0 =
                    B_808010E0_chtransparentfish[local_1].local_0;
                B_808010E0_chtransparentfish[local_1].local_0 = local_4;
            }
        }
    }
    if (func_800DA298(0x6C0)) {
        local_5 = func_800DA564(0x6C1, 8);
    } else {
        local_5 = func_800DC128(0, 256);
        func_800DA7A8(0x6C1, local_5, 8);
        func_800DA544(0x6C0);
    }
    local_7 = 0;
    local_6 = func_800DC090();
    func_800DC324(local_5);
    while (!func_80800E10_chtransparentfish(local_2)) {
        local_3 = func_800DC128(0, local_2);
        if (B_808010E0_chtransparentfish[local_3].local_2 == -1) {
            B_808010E0_chtransparentfish[local_3].local_2 =
                B_808010E0_chtransparentfish[local_7++].local_1;
        }
    }
    func_800DC324(local_6);
}

s32 func_80800E10_chtransparentfish(param_0)
s32 param_0;
{
    s32 local_0;
    s32 local_1;

    local_0 = 1;
    for (local_1 = 0; local_1 < param_0; local_1++) {
        local_0 &= ((TransparentFishEntry *) B_808010E0_chtransparentfish)[local_1].local_0 != -1;
    }
    return local_0;
}

s32 func_80800EE0_chtransparentfish(param_0) s32 param_0;
{
    char *new_var;
    s32 *ptr;
    int new_var2;
    ptr = &((s32 *) B_808010E0_chtransparentfish)[0]; while (1) {
        if (param_0 == *(s32 *) ((char *) ptr + 0x0))
        {
            return *(s32 *) ((char *) ptr + 0x8);
        }
        new_var2 = sizeof(s32);
        if (param_0 == *(s32 *) ((char *) ptr + 0xC))
        {
            return *(s32 *) ((char *) ptr + 0x14);
        }
        if (param_0 == *(s32 *) ((char *) ptr + 0x18))
        {
            new_var = (char *) ptr + 0x20;
            return *(s32 *) new_var;
        }
        if (param_0 == *(s32 *) ((char *) ptr + 0x24))
        {
            return *(s32 *) ((char *) ptr + 0x2C);
        }
        ptr += 0x30 / sizeof(s32);
        if (ptr == &((s32 *) B_808010E0_chtransparentfish)[0xF0 / new_var2])
        {
            return 0;
        }
    }

}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800F80_chtransparentfish[5] = {0x10000, 0x20000, 0x20000, 0x0, 0x30000};
u32 D_80800F94_chtransparentfish[8] = {0x0,        0x0,       0x40200000, 0x1580001,
                                       0x40200000, 0x1580001, 0x40200000, 0x1580001};
FishSpawnConfig271 D_80800FB4_chtransparentfish[13] = {
    0x0,   0x0,   0x64,  0x21F, -0x1E, 0x64,  0x136, -0x32, 0x64,  0x1C8, -0x32, 0x64,  0x1C9,
    -0x32, 0x64,  0x1CA, -0x32, 0x64,  0x1CB, -0x32, 0x64,  0x1CC, -0x46, 0x5A,  0x1CE, -0x46,
    0x64,  0x1CF, -0x46, 0x64,  0x1D7, -0x32, 0x64,  0x1D8, -0x46, 0x46,  0x220, -0x32, 0x5A};
u8 D_80801050_chtransparentfish[72] = {
    0x0, 0x1D, 0x9,  0xD9, 0x0, 0x16, 0x10, 0x4,  0x0,  0x1B, 0x0,  0x96, 0x0,  0x96, 0x0,
    0x7, 0x0,  0x1,  0x0,  0xE, 0x0,  0xA,  0x0,  0xA,  0x0,  0x15, 0x0,  0x0,  0x0,  0xCC,
    0x0, 0x2B, 0x3,  0x0,  0x3, 0x0,  0x0,  0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0,  0x22, 0x0,
    0xC, 0x0,  0x17, 0x0,  0xC, 0x0,  0x17, 0x0,  0x2F, 0x0,  0x40, 0x0,  0x40, 0x0,  0x0,
    0x0, 0x0,  0x0,  0x19, 0x0, 0x0,  0x0,  0x33, 0x0,  0x0,  0x0,  0x0};
int D_80801098_chtransparentfish[18] = {0x12D0295,
                                        0x6D90001,
                                        (u32) &D_80800F94_chtransparentfish,
                                        (u32) func_80800348_chtransparentfish,
                                        (u32) func_80105834,
                                        (u32) func_80800690_chtransparentfish,
                                        0x13880000,
                                        0x0,
                                        0x0,
                                        0x220123,
                                        (u32) func_80800B30_chtransparentfish,
                                        (u32) func_80108ED0,
                                        0x80000,
                                        (u32) func_808002B8_chtransparentfish,
                                        (u32) func_80107C2C,
                                        -0x7FBFAFF1,
                                        (u32) func_8080078C_chtransparentfish,
                                        (u32) &D_80800F80_chtransparentfish};
