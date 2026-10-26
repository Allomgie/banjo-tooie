#include "common.h"

typedef struct LavaHandContactState { u8 pad_0[0x7A]; u8 local_0 : 2; u8 pad_1 : 6; } LavaHandContactState;
extern f32 func_800F1F0C(f32 *, f32 *, f32);
extern void func_800C8E54(s32, f32, f32);
extern s32 D_808013A0_chlavahand[];
extern s32 D_80801330_chlavahand[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_80101870(Actor *, void *);
extern Actor *func_80106790(Unk80132ED0 *);
extern int D_808013D0_chlavahand;
typedef struct { u8 pad[0x7A]; u16 top : 2; u16 rest : 14; } LavaHandTop;
extern void func_800DF830();
extern void func_800DE498(f32 *, f32 *, s32, f32, s32, f32 *);
extern void func_800DF410();
extern void *D_80801418_chlavahand;
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 local_0 : 1; u32 pad_2 : 29; } LavaHandFlags;
extern f32 func_80101F24(Actor *);
extern void func_800C4140(s32, f32 *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800DC0C0(void);
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern s32 func_800EEB9C(f32 *, f32, f32);
typedef union { u32 local_0; s16 local_1[2]; } Mass64LavaHandEvent;
typedef struct { u32 pad78_3 : 29; u32 unk78_2 : 1; u32 pad78_0 : 2; } ActorFlags78;
extern void func_800FFA88(Unk80132ED0 *);
void func_80800FB4_chlavahand();
void func_808011BC_chlavahand(s32 boneIndex, f32 position[3], f32 rotation[3], s32 param_3, f32 param_4, s32 param_5, s32 param_6);

void func_80800000_chlavahand(Actor *param_0)
{
    param_0->unk64_24 = 1;
    param_0->unk64_16 = 0;
    param_0->unk54 = param_0->scale;
}

void func_80800024_chlavahand(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1;

    ((LavaHandContactState *)param_0)->local_0 = 1;
    func_800F5A00(func_800F54E4(), local_0);
    local_1 = func_800F1F0C(param_0->position, local_0, param_0->rotation[1]);
    if (local_1 >= -90.0f && local_1 <= 0.0f) {
        func_80103140(param_0, 0x925, param_0->unk0->unk16);
        func_80102424(param_0, 2);
    } else if (local_1 <= 90.0f && local_1 > 0.0f) {
        func_80103140(param_0, 0x92C, param_0->unk0->unk16);
        func_80102424(param_0, 3);
    }
    func_8010A590(param_0);
}

void func_80800A30_chlavahand();

void func_80800910_chlavahand();

void func_80800124_chlavahand(Actor *param_0)
{
    extern u8 D_80801324_chlavahand[];

    f32 local_0;
    s32 local_1;
    f32 local_6;
    s32 local_5;
    f32 local_7;
    f32 local_2;
    s32 local_4;

    switch (param_0->unk70_10) {
        case 1:
            if (((LavaHandFlags *)param_0)->local_0) {
                if (_subaddiejoy_entrypoint_6(param_0, 1)) {
                    func_80800024_chlavahand(param_0);
                }
            } else if (func_800D90A4((char *)param_0 + 0x58)) {
                if (func_8010C9FC(
                        (char *)param_0 + 4,
                        (s32)((f32)param_0->unk74_7 * 10.0f),
                        200,
                        -200)) {
                    func_80800024_chlavahand(param_0);
                }
            }

            *(f32 *)((char *)param_0 + 0x38) = 0.1f;
            break;

        case 2:
        case 3:
            local_0 = func_80101F24(param_0);
            local_1 = func_8010C754(param_0);

            if (local_0 <= 0.09f) {
                *(f32 *)((char *)param_0 + 0x38) =
                    func_800F10B4(
                        local_0,
                        0.0f,
                        0.09f,
                        0.1f,
                        *(f32 *)((char *)param_0 + 0x54)
                    );
            } else if (local_0 >= 0.80f) {
                *(f32 *)((char *)param_0 + 0x38) =
                    func_800F10B4(
                        local_0,
                        0.80f,
                        1.0f,
                        *(f32 *)((char *)param_0 + 0x54),
                        0.1f
                    );
            } else {
                *(f32 *)((char *)param_0 + 0x38) =
                    *(f32 *)((char *)param_0 + 0x54);
            }

            _subaddieaudioloop_entrypoint_4(
                param_0,
                (char *)param_0 + 4,
                local_1 < 1000,
                D_80801324_chlavahand
            );

            local_2 = func_800F10B4(
                (f32)local_1,
                1000.0f,
                0.0f,
                0.8f,
                1.2f
            );

            _subaddieaudioloop_entrypoint_0(
                param_0,
                local_2
            );

            local_2 =
                func_80013970(func_80101F24(param_0) * 180.0f);

            _subaddieaudioloop_entrypoint_1(
                param_0,
                (s32)(local_2 * 16000.0f)
            );

            if (func_80101E14(param_0, 0.2f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0x1B5E01,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            } else if (func_80101E14(param_0, 0.52f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(1.15f, 1.25f) * 1023.0f) << 21) + 0x1B5E01,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            } else if (func_80101DDC(param_0)) {
                if (((LavaHandFlags *)param_0)->local_0) {
                    *(f32 *)((char *)param_0 + 0x58) = 1.0f;
                } else {
                    *(f32 *)((char *)param_0 + 0x58) = 2.0f;
                }

                func_80102424(param_0, 1);
                _subaddieaudioloop_entrypoint_2(param_0);
            }

            *(f32 *)((char *)param_0 + 0x2C) =
                *(f32 *)((char *)param_0 + 0x38) * 150.0f;

            *(f32 *)((char *)param_0 + 0x30) =
                *(f32 *)((char *)param_0 + 0x38) * 300.0f;
            break;

        case 4:
        case 5:
            local_6 = func_80101F24(param_0);

            if (func_800DC0C0() < 0.1f) {
                func_80800A30_chlavahand(param_0);
            }

            _subaddieaudioloop_entrypoint_4(
                param_0,
                (char *)param_0 + 4,
                1,
                D_80801324_chlavahand
            );

            local_2 = func_800F1214(
                local_6,
                0.8f,
                1.2f
            );

            _subaddieaudioloop_entrypoint_0(
                param_0,
                local_2
            );

            _subaddieaudioloop_entrypoint_1(
                param_0,
                (s32)(local_6 * 16000.0f)
            );

            *(f32 *)((char *)param_0 + 0x38) =
                func_800F15F8(
                    *(f32 *)((char *)param_0 + 0x38),
                    *(f32 *)((char *)param_0 + 0x54),
                    0.1f
                );

            if (func_80101E14(param_0, 0.02f)) {
                func_800C4140(
                    ((u16)(u32)(func_800DC178(1.4f, 1.5f) * 1023.0f) << 21) + 0x1D4E05,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            } else if (func_80101E14(param_0, 0.7f)) {
                func_800C4140(
                    0x665F4601,
                    (char *)param_0 + 4,
                    0x04B000FA
                );
            }

            if (func_80101DDC(param_0)) {
                local_5 =
                    param_0->unk70_10;

                func_8010A800(param_0, 2);
                func_80107070(param_0, 2);

                if (local_5 == 4) {
                    local_4 = 6;
                } else {
                    local_4 = 7;
                }

                func_80102424(param_0, local_4);
                break;
            }

            local_2 = 1.0f + local_6;

            *(f32 *)((char *)param_0 + 0x2C) =
                *(f32 *)((char *)param_0 + 0x54) *
                150.0f * local_2;

            *(f32 *)((char *)param_0 + 0x30) =
                *(f32 *)((char *)param_0 + 0x54) *
                300.0f * local_2;
            break;

        case 6:
        case 7:
            local_7 =
                (f32)*(u8 *)((char *)param_0 + 0x9B) /
                255.0f;

            _subaddieaudioloop_entrypoint_4(
                param_0,
                (char *)param_0 + 4,
                1,
                D_80801324_chlavahand
            );

            local_2 = func_800F1214(
                local_7,
                0.8f,
                1.2f
            );

            _subaddieaudioloop_entrypoint_0(
                param_0,
                local_2
            );

            _subaddieaudioloop_entrypoint_1(
                param_0,
                (s32)(local_7 * 16000.0f)
            );

            if (func_800DC0C0() < local_7) {
                func_80800A30_chlavahand(param_0);
            }

            *(f32 *)((char *)param_0 + 0x2C) =
                (*(f32 *)((char *)param_0 + 0x54) *
                 150.0f * 2.0f) * local_7;

            *(f32 *)((char *)param_0 + 0x30) =
                (*(f32 *)((char *)param_0 + 0x54) *
                 300.0f * 2.0f) * local_7;
            break;

        case 8:
            if (*(u8 *)((char *)param_0 + 0x5F) != 0) {
                _subaddieaudioloop_entrypoint_2(param_0);
            }
            break;

        case 9:
        default:
            break;
    }

    func_80800910_chlavahand(param_0);
}

void func_80800910_chlavahand(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;
    param_0->unk64_16 = (s32)param_0->unk70_10 >= 2 && (s32)param_0->unk70_10 <= 7;
    local_1 = param_0->actorData[4];
    if (local_1 && !(*(u16 *)((u8 *)param_0 + 0x64) & 1)) {
        func_800C8B84(local_1);
        param_0->actorData[4] = 0;
        local_1 = 0;
    } else if (!local_1 && (*(u16 *)((u8 *)param_0 + 0x64) & 1)) {
        param_0->actorData[4] = func_800C8A98();
        func_800C8CB8(param_0->actorData[4], param_0->position);
        func_800C8FB0(param_0->actorData[4], 0xFF, 0xE1, 0xF);
        func_800C8F64(param_0->actorData[4], 1);
        func_800C8E54(param_0->actorData[4], *(f32 *)((u8 *)param_0 + 0x2C), *(f32 *)((u8 *)param_0 + 0x30));
        func_800C8FE0(param_0->actorData[4], 1);
        local_1 = param_0->actorData[4];
    }
    if (local_1) {
        _subaddieskeleton_entrypoint_0(param_0, 0x2D, local_0);
        func_800C8CB8(param_0->actorData[4], local_0);
        func_800C8E54(param_0->actorData[4], *(f32 *)((u8 *)param_0 + 0x2C), *(f32 *)((u8 *)param_0 + 0x30));
    }
}

void func_80800A30_chlavahand(Actor *param_0)
{
    f32 local_0[3];
    if (param_0->unk7C_12 &&
        _subaddieskeleton_entrypoint_0(param_0,
            D_808013A0_chlavahand[func_800DC128(0, 0xD)], local_0)) {
        func_800BABB8(0, local_0, NULL, param_0->scale, D_80801330_chlavahand);
    }
}

s32 func_80800AAC_chlavahand(Actor *param_0, s32 param_1, Mass64LavaHandEvent param_2)
{
    Actor *local_0;
    f32 local_1[3];
    f32 local_2;

    switch (param_1) {
    case 0x3D:
        local_0 = func_80108528(0x400, param_0->position, 0, &param_0);
        func_80103140(local_0, 0x927, 0);
        local_0->unk3C = param_0->unk0;
        param_0->unk3C = local_0->unk0;
        *(u32 *)&local_0->unk50 = (u32)((u16 *)param_0->unk0)[9] >> 1;
        local_0 = func_80108528(0x400, param_0->position, 0, &param_0);
        func_80103140(local_0, 0x926, 0);
        local_0->unk3C = param_0->unk0;
        *(u32 *)&local_0->unk50 = (u32)((u16 *)param_0->unk0)[9] >> 1;
        *(u16 *)((u8 *)local_0 + 0x7C) = *(u16 *)((u8 *)param_0 + 0x7C);
        return 1;
    case 0x40:
        if ((s32)param_0->unk70_10 == 2) {
            func_80102424(param_0, 4);
        } else if ((s32)param_0->unk70_10 == 3) {
            func_80102424(param_0, 5);
        }
        *((u8 *)param_0 + 0x7A) = (*((u8 *)param_0 + 0x7A) & ~0xC0) | 0x80;
        func_8010A570(param_0);
        return 1;
    case 1:
        func_80102424(param_0, 1);
        return 1;
    case 2:
        param_0->unk58 = 2.0f;
        func_80102424(param_0, 1);
        return 1;
    case 0x95:
        func_80108B04(param_0, 0);
        *(u16 *)((u8 *)param_0 + 0x7C) = (u32)((param_0->unk74_7 * 10.0f) * 1.2f);
        return 1;
    case 0x97:
        local_2 = (1.0f / param_0->scale) * 200.0f;
        func_800EEB9C(local_1, param_0->rotation[1], local_2);
        local_1[1] += local_2;
        func_80101010(local_1);
        return 1;
    default:
        return 0;
    }
}

void func_80800D8C_chlavahand(Actor *param_0, s32 param_1)
{
    s32 local_0;

    func_80101870(param_0, (void *)param_1);
    if (param_0->unk3C && param_0->unk7C_12) {
        local_0 = param_0->unk70_10;
        if (local_0 >= 2 && local_0 < 8) {
            func_80800FB4_chlavahand(func_80106790(param_0->unk3C), param_1);
        }
    }
}

int chlavahand_entrypoint_0()
{
    return (int)&D_808013D0_chlavahand;
}

void func_80800E0C_chlavahand(Actor *this)
{
    Actor *parent;
    f32 t;

    if (((u32)*(u16 *)((u8 *)this->unk3C + 0x12) >> 1) == *(s32 *)&this->unk50) {
        parent = func_80106790(this->unk3C);
        if (!((ActorFlags78 *)&parent->unk78)->unk78_2 && 0.2f < parent->scale) {
            switch (parent->unk70_10) {
            case 2:
            case 3:
                this->scale = func_80013970(func_80101F24(this) * 180.0f) * parent->scale + parent->scale;
                this->alpha = 0xFF;
                break;
            case 4:
            case 5:
                t = func_80101F24(parent);
                if (t < 0.99f) {
                    this->scale = func_800F10B4(t, 0.0f, 1.0f, 1.0f, 2.0f) * parent->scale;
                }
                this->alpha = 0xFF;
                break;
            case 6:
            case 7:
                this->scale = func_800F10B4((u32)parent->alpha, 255.0f, 0.0f, 2.0f, 0.0f) * parent->scale;
                this->alpha = parent->alpha;
                break;
            default:
                return;
            }
            this->unk64_16 = 1;
        }
    } else {
        func_800FFA88(this->unk0);
    }
}

void func_80800FB4_chlavahand(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800D674C(param_0->unk0->unk14);
    local_1 = func_80106790(*(s32 *)((u8 *)param_0 + 0x3C));
    func_801015D0(param_0);
    if (param_0->unk0->unk14 == 0x927) {
        func_808011BC_chlavahand(local_1, param_1, local_0, 0x2A, param_0->scale, *(u8 *)((u8 *)param_0 + 0x9B), ((LavaHandTop *)param_0)->top);
        func_808011BC_chlavahand(local_1, param_1, local_0, 0x2C, param_0->scale, *(u8 *)((u8 *)param_0 + 0x9B), ((LavaHandTop *)param_0)->top);
        func_808011BC_chlavahand(local_1, param_1, local_0, 0x2D, param_0->scale, *(u8 *)((u8 *)param_0 + 0x9B), ((LavaHandTop *)param_0)->top);
        func_808011BC_chlavahand(local_1, param_1, local_0, 0x2F, param_0->scale, *(u8 *)((u8 *)param_0 + 0x9B), ((LavaHandTop *)param_0)->top);
        func_808011BC_chlavahand(local_1, param_1, local_0, 0x30, param_0->scale, *(u8 *)((u8 *)param_0 + 0x9B), ((LavaHandTop *)param_0)->top);
        func_808011BC_chlavahand(local_1, param_1, local_0, 0x32, param_0->scale, *(u8 *)((u8 *)param_0 + 0x9B), ((LavaHandTop *)param_0)->top);
    } else {
        func_808011BC_chlavahand(local_1, param_1, local_0, 0x33, param_0->scale, *(u8 *)((u8 *)param_0 + 0x9B), ((LavaHandTop *)param_0)->top);
        func_808011BC_chlavahand(local_1, param_1, local_0, 0x35, param_0->scale, *(u8 *)((u8 *)param_0 + 0x9B), ((LavaHandTop *)param_0)->top);
    }
    param_0->unk7C_12 = 1;
}

void func_808011BC_chlavahand(s32 boneIndex, f32 position[3], f32 rotation[3], s32 param_3, f32 param_4, s32 param_5, s32 param_6) {
    f32 local_0[3];

    _subaddieskeleton_entrypoint_0(boneIndex, param_3, local_0);
    func_800DF410(param_5);
    func_800DF830(0x2);
    func_800DE498(position, local_0, 0, param_4, 0, rotation);
}

int chlavahand_entrypoint_1()
{
  return &D_80801418_chlavahand;
}
