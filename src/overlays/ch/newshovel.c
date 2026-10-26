#include "common.h"

extern int D_80800FB4_chnewshovel;
extern u8 object_properties_bitfield[];
extern u8 D_80801024_chnewshovel[];
extern u8 D_80801018_chnewshovel[];
extern u8 D_80801008_chnewshovel[];
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 disabled : 1; u32 pad_2 : 29; } ShovelFlags;
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 local_0 : 1; u32 pad_2 : 29; } ShovelActorFlags;
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
typedef struct { u8 pad_0[0x64]; u32 : 2; u32 local_0 : 1; u32 : 29; } ShovelFlags1274;
typedef struct { u8 pad_0[0x10]; s16 local_0; } ShovelState1274;
extern void *func_80100094(Actor *, u32);
extern s32 D_80801064_chnewshovel;
extern void func_800C4B7C(s32);
extern void _subaddieaudioquick_entrypoint_2();
extern s32 func_800DC298(f32);
extern u8 D_80801074_chnewshovel[];
extern void *func_800B53A4(s32);
extern void *func_800BABB8(void *, f32 *, f32 *, f32, void *);
extern u32 D_808010B0_chnewshovel;
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 29; u32 local_0 : 1; u32 pad_2 : 2; } Mass64NewShovelFlags;
extern u8 D_80800FFC_chnewshovel[];
extern void _suexpression_entrypoint_14(void *, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, void *, s32);
extern u8 D_80801034_chnewshovel[];
extern u8 D_8080104C_chnewshovel[];
extern f32 func_800EEB40(f32 *, f32 *);
void func_80800CC4_chnewshovel();
void func_80800D18_chnewshovel();
int func_808006B0_chnewshovel();
s32 func_808007F8_chnewshovel();
s32 func_80800930_chnewshovel();
s32 func_80800B5C_chnewshovel();
s32 func_80800C58_chnewshovel();
extern void func_801018A4(), func_80102EC0(), func_80107C2C(), func_80108ED0(), func_8080004C_chnewshovel(), func_80800310_chnewshovel();
extern u8 D_80800F50_chnewshovel[], D_80800FA0_chnewshovel[];

int chnewshovel_entrypoint_0()
{
    return (int)&D_80800FB4_chnewshovel;
}

s32 func_8080000C_chnewshovel(param_0) s32 param_0; {
    s32 local_0 = func_80100094(param_0, 0);
    _subaddierouteDll_entrypoint_3(param_0, local_0, param_0 + 4);
    func_808007F8_chnewshovel(param_0, 0);
}

s32 func_80800BC0_chnewshovel();

s32 func_80800610_chnewshovel();

void func_80800570_chnewshovel();

void func_8080004C_chnewshovel(param_0) Actor *param_0;
{
    s32 local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    if (!((Mass64NewShovelFlags *)param_0)->local_0) {
        _suexpression_entrypoint_10(_suexpression_entrypoint_20(param_0), param_0->unk0, 0);
        local_0 = func_80800930_chnewshovel(param_0);
        func_80800570_chnewshovel(param_0);
        switch (param_0->unk70_10) {
        case 1:
            if (func_80800610_chnewshovel(param_0)) {
                func_808006B0_chnewshovel(param_0, 2);
            }
            break;
        case 2:
            if (func_80101DDC(param_0)) {
                func_808006B0_chnewshovel(param_0, func_80800610_chnewshovel(param_0) ? 3 : 1);
            }
            break;
        case 3:
            func_80800BC0_chnewshovel(param_0);
            if (func_80800610_chnewshovel(param_0)) {
                func_800F5A00(func_8010D290(0x10000), (f32 *)param_0->actorData);
                if (*(s16 *)(local_1 + 0xC) == 2) {
                    func_808006B0_chnewshovel(param_0, func_80800C58_chnewshovel(param_0) ? 4 : 3);
                }
            } else if (*(s16 *)(local_1 + 0xC) == 2) {
                func_808006B0_chnewshovel(param_0, 6);
            }
            break;
        case 4:
            if (func_80800610_chnewshovel(param_0)) {
                func_800F5A00(func_8010D290(0x10000), (f32 *)param_0->actorData);
            }
            if (local_0 & 8) {
                ((f32 *)param_0->actorData)[3] = 0.0f;
            }
            if (*(s16 *)(local_1 + 0xC) == 2) {
                func_808006B0_chnewshovel(param_0, 5);
            }
            break;
        case 5:
            if (func_80101DDC(param_0)) {
                func_808006B0_chnewshovel(param_0, func_80800610_chnewshovel(param_0) ? 3 :
                    (func_80800B5C_chnewshovel(param_0) ? 1 : 6));
            }
            break;
        case 6:
            if (func_80800610_chnewshovel(param_0)) {
                if (*(s16 *)(local_1 + 0xC) == 2) {
                    func_808006B0_chnewshovel(param_0, 3);
                }
            } else {
                if (func_80800B5C_chnewshovel(param_0)) {
                    ((f32 *)param_0->actorData)[3] *= 0.9f;
                }
                if (*(s16 *)(local_1 + 0xC) == 2) {
                    func_808006B0_chnewshovel(param_0, func_80800B5C_chnewshovel(param_0) ? 1 : 6);
                }
            }
            break;
        }
    }
}

void func_80800310_chnewshovel(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
int func_80800330_chnewshovel(Actor *param_0, s32 param_1, s32 *param_2)
{
    void *local_2;
    s32 *local_3;
    s32 pad[2];
    f32 local_0;
    f32 local_1;

    switch (param_1) {
    case 0x1F:
        func_801015D0(param_0);
        func_800DF744(3, 1);
        break;
    case 0x95:
        local_2 = _suexpression_entrypoint_7(param_0, 1, 0x5A);
        _suexpression_entrypoint_12(local_2, 0x428C0000, 0x41200000);
        _suexpression_entrypoint_14(local_2, 1.0f, 1.0f);
        _subaddierouteDll_entrypoint_1(param_0);
        break;
    case 0x40:
        local_3 = *(s32 **)&param_2;
        _chskeletonexplode_entrypoint_8(param_0, *local_3 + 4);
        func_8010A570(param_0);
        _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 4, D_80800FFC_chnewshovel);
        _subaddiejoy_entrypoint_10(param_0, 0x3F800000, 0x3E800000);
        ((u8 *)param_0)[0x64] &= ~1;
        break;
    case 0xF:
        _chskeletonexplode_entrypoint_3(func_80106790(func_80101080()), 3, 2);
        if (!func_80107070(param_0, 3)) {
            func_800FFAB0(param_0);
        }
        break;
    case 0x8F:
        if (*(s32 **)&param_2 == 0) {
            func_808006B0_chnewshovel(param_0, 1);
        }
        break;
    case 2:
        if (!_subaddieDll_entrypoint_3(param_0)) {
            if (!func_80107070(param_0, 1)) {
                _subaddiefade_entrypoint_3(param_0);
            }
        } else {
            func_808006B0_chnewshovel(param_0, 6);
        }
        break;
    case 0x38:
        return func_80800DC8_chnewshovel(param_0);
    case 0x94:
        param_0 = _suexpression_entrypoint_20(param_0);
        if (param_0 == 0) {
            return 0;
        }
        func_800EFD24(&local_1);
        _suexpression_entrypoint_13(param_0, &local_0, &local_1);
        func_80101010(&local_1);
        break;
    default:
        return 0;
    case 1:
        break;
    }
    return 1;
}

void func_80800570_chnewshovel(Actor *param_0)
{
    s32 local_0;

    local_0 = func_801022E4();
    if (local_0 != 0x1BA) {
        if (local_0 == 0x1BB) {
            _subaddieaudioquick_entrypoint_4(param_0, (u8 *)param_0 + 4, &D_80801008_chnewshovel, &D_80801018_chnewshovel);
            if (func_80101E14(param_0, 0x3F333333) != 0) {
                func_80800CC4_chnewshovel(param_0);
                func_80800D18_chnewshovel(param_0);
            }
        }
    }
    else {
        _subaddieaudioquick_entrypoint_3(param_0, (u8 *)param_0 + 4, &D_80801024_chnewshovel, 0x3ECCCCCD);
    }
}

s32 func_80800610_chnewshovel(Actor *param_0)
{
    s32 local_0;
    if (((ShovelFlags *)param_0)->disabled) return 1;
    local_0 = func_8010D290(0x10000);
    if (local_0 == -1) return 0;
    if (!func_800F6478(local_0)) return 0;
    if (!func_8010C550(param_0, local_0)) return 0;
    if (!_suchase_entrypoint_1(param_0)) return 0;
    return 1;
}

int func_808006B0_chnewshovel(param_0, param_1) Actor *param_0; s32 param_1;
{
    *(s16 *)((u8 *)func_80100094(param_0, 0) + 0x10) = 0;
    switch (param_1) {
        case 1:
            func_80102424(param_0, param_1);
            func_808007F8_chnewshovel(param_0, 0);
            break;
        case 2:
            func_80102424(param_0, param_1);
            break;
        case 3:
            func_80102424(param_0, param_1);
            func_808007F8_chnewshovel(param_0, 1);
            break;
        case 4:
            func_800F5A00(func_8010D290(0x10000), (u8 *)param_0 + 0x18);
            func_80102424(param_0, param_1);
            func_808007F8_chnewshovel(param_0, 3);
            break;
        case 5:
            func_80102424(param_0, param_1);
            func_808007F8_chnewshovel(param_0, 0);
            break;
        case 6:
            func_80107B70(param_0, (u8 *)param_0 + 0x18);
            func_80102424(param_0, param_1);
            func_808007F8_chnewshovel(param_0, 1);
            break;
        default:
            func_80102424(param_0, param_1);
            break;
    }
    return 1;
}

s32 func_808007F8_chnewshovel(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_1;
    f32 local_0;

    local_1 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0:
            local_0 = 0;
            *(f32 *)((u8 *)param_0 + 0x24) = local_0;
            *(f32 *)((u8 *)param_0 + 0x2C) = local_0;
            break;
        case 1:
            local_0 = param_0->scale * 450.0f;
            func_800EFA4C((f32 *)((u8 *)param_0 + 0x28), 0.0f, local_0, 0.0f);
            *(f32 *)((u8 *)param_0 + 0x34) = (-local_0 - local_0) / 0.6f;
            break;
        case 2:
            func_80800D18_chnewshovel(param_0);
            func_80800CC4_chnewshovel(param_0);
            local_0 = 0;
            *(f32 *)((u8 *)param_0 + 0x24) = local_0;
            *(f32 *)((u8 *)param_0 + 0x2C) = local_0;
            break;
        case 3:
            local_0 = param_0->scale * 550.0f;
            func_800EFA4C((f32 *)((u8 *)param_0 + 0x28), 0.0f, local_0, 0.0f);
            *(f32 *)((u8 *)param_0 + 0x34) = (-local_0 - local_0) / 0.765f;
            break;
    }
    *(u16 *)(local_1 + 0xC) = param_1;
    return 1;
}

s32 func_80800A50_chnewshovel();

s32 func_80800930_chnewshovel(param_0) Actor *param_0;
{
    u8 *local_1;
    s32 local_0;
    local_1 = func_80100094(param_0, 0);
    local_0 = 0;
    switch (*(s16 *)(local_1 + 0xC)) {
    case 0: case 2: break;
    case 1:
        *(f32 *)((u8 *)param_0 + 0x24) = func_800F3780(func_80101F24(param_0), D_80801034_chnewshovel, 3) * 550.0f;
        local_0 = func_80800A50_chnewshovel(param_0);
        if (func_80101DDC(param_0) && (local_0 & 8)) func_808007F8_chnewshovel(param_0, 2);
        break;
    case 3:
        *(f32 *)((u8 *)param_0 + 0x24) = func_800F3780(func_80101F24(param_0), D_8080104C_chnewshovel, 3) * 600.0f;
        local_0 = func_80800A50_chnewshovel(param_0);
        if (func_80101DDC(param_0) && (local_0 & 8)) func_808007F8_chnewshovel(param_0, 2);
        break;
    }
    return local_0;
}

s32 func_80800A50_chnewshovel(Actor *param_0)
{
    s32 local_2;
    void *local_0;
    f32 local_1;
    local_0 = (void *)func_80100094(param_0, 0);
    if (((ShovelActorFlags *)param_0)->local_0) {
        local_1 = _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3);
        func_80102BF8(param_0, 0.12f, 5.0f, 180.0f);
        local_2 = func_8010C3A8(param_0, 0x200025, local_1);
        local_2 |= func_8010B990(param_0, 0x4004);
    } else {
        param_0->unk54 = func_80102D78(param_0, (f32 *)param_0->actorData);
        _subaddierouteDll_entrypoint_7(param_0, local_0, param_0->rotation[1], param_0->unk54, 200.0f, 0x5000);
        func_80102BF8(param_0, 0.12f, 5.0f, 180.0f);
        local_2 = func_8010B990(param_0, 0x325);
        local_2 |= func_8010B990(param_0, 0x4004);
    }
    return local_2;
}

s32 func_80800B5C_chnewshovel(param_0) Actor *param_0;
{
    f32 local_0[3];

    if (func_80107B70(param_0, local_0)) {
        return func_800EEB40(param_0->position, local_0) < 10000.0f;
    }
    return 0;
}

s32 func_80800BC0_chnewshovel(Actor *param_0)
{
    ShovelState1274 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (!((ShovelFlags1274 *)param_0)->local_0) return 0;
    if (_subaddiejoy_entrypoint_6(param_0, 0) == 1 ||
        _subaddiejoy_entrypoint_6(param_0, 1) == 1 ||
        _subaddiejoy_entrypoint_7(param_0, 0) == 1) local_0->local_0 = 1;
    return local_0->local_0;
}

s32 func_80800C58_chnewshovel(param_0) Actor *param_0;
{
    f32 *local_0 = (f32 *)param_0->actorData;
    if (((ShovelActorFlags *)param_0)->local_0) {
        return func_80800BC0_chnewshovel(param_0);
    } else {
        if (func_800EEB40(param_0->position, local_0) > 40000.0f) return 0;
        return 1;
    }
}

void func_80800CC4_chnewshovel(param_0) u8 *param_0; {
    func_800C4B7C(func_800DC298(0.5f) ? 0x517 : 0x518);
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80801064_chnewshovel);
}

void func_80800D18_chnewshovel(param_0) Actor *param_0;
{
    f32 local_0[3];
    u8 local_1[4];
    void *local_2;

    if (param_0->unk7C_12) {
        func_800F2EA0(local_1, &param_0->pad98, param_0);
        local_1[3] = 0xFF;
        func_800EE7F8(local_0, param_0->position);
        local_0[1] -= 20.0f;
        local_2 = func_800B53A4(3);
        func_800BABB8(local_2, param_0->position, local_0, 0.8f, D_80801074_chnewshovel);
        func_800BAB60(local_2, local_1);
        func_800BA22C(local_2, 3);
    }
}

int func_80800DC8_chnewshovel(s32 param_0)
{
  func_80101074(&D_808010B0_chnewshovel);
  return 2;
}
