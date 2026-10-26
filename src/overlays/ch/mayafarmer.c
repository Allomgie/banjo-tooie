#include "common.h"

extern s32 D_8080124C_chmayafarmer;
extern u8 unk6E[];
extern u8 unk6C[];
typedef struct { s32 f0; s32 f4; u8 pad[0x6C]; u8 pad74:1; u8 flag:1; u8 rest:6; } FarmerState;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
extern void *D_80801278_chmayafarmer;
extern u8 D_80801230_chmayafarmer[];
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
typedef struct { u8 pad_0[0x70]; u32 local_0 : 7; u32 pad_1 : 15; u32 local_1 : 6; u32 pad_2 : 4; } FarmerRouteKeys;
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
extern s32 D_808012E8_chmayafarmer;
extern void _subaddieaudioloop_entrypoint_4();
extern int D_808012FC_chmayafarmer;
typedef union { s32 local_0; s16 local_1[2]; } MayaFarmerEvent;
extern u8 D_8080125C_chmayafarmer[];
extern Vec3f D_8080126C_chmayafarmer;
extern f32 func_800DC178(f32, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void *func_80100094(Actor *, u32);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern u8 D_80801210_chmayafarmer[];
extern u8 D_80801220_chmayafarmer[];
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern s32 func_80101E14(Actor *, f32);
extern u8 D_8080123C_chmayafarmer[];
extern void *func_80106790(void *);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
typedef struct { f32 local_0[3]; s16 local_1; } FarmerScatterOrigin;
extern FarmerScatterOrigin *func_800CC63C(s32, s32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_80102424();
extern f32 func_800DC0C0(void);
extern f32 func_800F1828(f32 *, f32 *);
extern s32 func_80102D4C(Actor *, f32);
extern void func_80102B6C(Actor *, f32);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
void func_80800D60_chmayafarmer();

void func_80800000_chmayafarmer(u8 *param_0, s32 param_1, s32 param_2) {
    s32 local_0;

    local_0 = (*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF;
    switch (local_0) {                              
    case 0:
        _capod_entrypoint_2((*(s32 *)((s8 *)(param_0) + (0))), 8, 0);
        
    case 1:
        _capod_entrypoint_8(1);
        (*(u16 *)((s8 *)(param_0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(param_0) + (0x6E))) & 0xFE00) | 2);
        _gcdialogcamera_entrypoint_3(&D_8080124C_chmayafarmer, (*(f32 *)((s8 *)(param_0) + (0x38))));
        _gcdialogcamera_entrypoint_4(param_0 + 4);
        _gcdialogcamera_entrypoint_5(param_0 + 0x44);
        _gcdialogcamera_entrypoint_8();
        
    case 2:
        _capod_entrypoint_7(param_1, param_2);
        return;
    }
}

void func_808000B0_chmayafarmer(u8 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s32 temp_t7;

    temp_t7 = (*(s32 *)(param_0 + 0x6C)) & 0x1FF;
    switch (temp_t7)
    {
    case 0:
        _capod_entrypoint_2(*(s32 *)param_0, 8, param_2);

    case 2:
        *(u16 *)(param_0 + 0x6E) = (*(u16 *)(param_0 + 0x6E) & 0xFE00) | 1;

    case 1:
        _capod_entrypoint_6(param_3, param_1, param_2);
        return;
    }
}

int func_80800138_chmayafarmer(Actor *param_0)
{
  if ((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF)
  {
    _capod_entrypoint_3(0, param_0);
    (*(u16 *)((char *)(param_0) + 0x6E)) &= 0xFE00;
  }
}

void func_80800180_chmayafarmer(FarmerState *param_0, s32 param_1, s32 param_2) {
    param_2 |= 4;
    _subaddiedialog_entrypoint_11(param_0->f0, param_1, param_2, &param_0->f4, 0x2A);
    param_0->flag = 1;
}

int func_808001CC_chmayafarmer(param_0) Actor *param_0;
{
    func_80102424();
    if (((u32)(*(u16 *)((char *)(param_0) + 0x72)) >> 10) == 4)
    {
        func_800FC660(0x10);
        func_80800180_chmayafarmer(param_0, 0xF07, 0xB);
        (*(f32 *)((char *)(param_0) + 0x58)) = 0.0f;
    }
}

s32 func_80800228_chmayafarmer(Actor *param_0, s32 param_1, MayaFarmerEvent param_2)
{
    s32 local_0;
    s32 local_1;

    switch (param_1) {
    case 0x95:
        _suexpression_entrypoint_7(param_0, 1, 0x2A);
        _suexpression_entrypoint_12(func_80100094(param_0, 1), 80.0f, 30.0f);
        func_80108B04(param_0, 0);
        break;
    case 0x11:
        if (param_0->unk70_10 == 1) {
            func_808001CC_chmayafarmer(param_0, 3);
        }
        break;
    case 0x2E:
        param_0->unk74_30 = 0;
        switch (param_2.local_1[0]) {
        case 0xF07:
            func_800C01A8(0x64, 0);
            func_808000B0_chmayafarmer(param_0, 4, 0x2010, param_0->unk0);
            func_800D1000(4, 1, 0, 1, 0);
            break;
        case 0xF06:
            func_80800138_chmayafarmer(param_0);
            break;
        }
        break;
    case 0x2F:
        if (param_2.local_1[0] == 0xF06 && !func_800C07F4()) {
            func_800DA544(5);
        }
        break;
    case 0xB:
        switch (param_2.local_0) {
        case 0xF:
            func_80800000_chmayafarmer(param_0, 2, 1);
            return 4;
        case 4:
            func_80800138_chmayafarmer(param_0);
            return 4;
        default:
            return 3;
        }
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_8080125C_chmayafarmer, param_0->scale);
        break;
    case 0x40:
        param_0->unk74_7--;
        if ((s32)param_0->unk74_7 <= 0) {
            func_808001CC_chmayafarmer(param_0, 4);
        }
        break;
    case 0x3D:
        local_0 = func_800CBC3C(D_8080126C_chmayafarmer.f);
        if ((s32)param_0->unk74_7 >= 9) {
            param_0->unk74_7 = 8;
        }
        for (local_1 = 0; local_1 < (s32)param_0->unk74_7; local_1++) {
            func_800CD08C(local_0, D_8080126C_chmayafarmer.f);
            func_80108528(0x2F8, D_8080126C_chmayafarmer.f, (s32)func_800DC178(0.0f, 360.0f), &param_0)->unk3C = param_0->unk0;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800520_chmayafarmer(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
void func_80800540_chmayafarmer(Actor *param_0)
{
    f32 local_0[3];
    f32 *local_1;

    func_8010D254(local_0);
    if (!param_0->unk64_19 && local_0[1] < 2000.0f) {
        param_0->unk64_16 = 0;
        return;
    }
    param_0->unk64_16 = 1;
    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    local_1 = param_0->position;
    _sudeflect_entrypoint_1(local_1, 140.0f, 0.0f, 110.0f, 14);
    if (!param_0->unk74_30 && func_80090178(1) && !func_800D0A9C(4, 1)) {
        if (_subaddiedialog_entrypoint_3(local_1, (s32)param_0->rotation[1], 0x15E, 0x46, 6) &&
            !func_800DA9E4(0x4D, 1)) {
            func_80800000_chmayafarmer(param_0, 2, 0);
            func_80800180_chmayafarmer(param_0, 0xF06, 11);
        } else if (_subaddiedialog_entrypoint_6(local_1, (s32)param_0->rotation[1], 0x15E, 0x46, 6)) {
            func_80800180_chmayafarmer(param_0, 0xF08, 11);
        }
    }
    switch (param_0->unk70_10) {
        case 1:
            if ((s32)param_0->unk74_7 <= 0) {
                func_808001CC_chmayafarmer(param_0, 4);
            }
            return;
        case 3:
            param_0->unk54 *= 0.9f;
            if (func_80101E14(param_0, 0.06f) || func_80101E14(param_0, 0.8f)) {
                _subaddieaudioquick_entrypoint_2(param_0, local_1, D_80801210_chmayafarmer);
            }
            if (func_80101E14(param_0, 0.999f)) {
                _suexpression_entrypoint_12((s32)func_80100094(param_0, 1), 80.0f, 30.0f);
                if ((s32)param_0->unk74_7 <= 0) {
                    func_808001CC_chmayafarmer(param_0, 4);
                    return;
                }
                func_808001CC_chmayafarmer(param_0, 1);
                return;
            }
            break;
        case 4:
            param_0->unk58 += 1.0f;
            if (param_0->unk58 > 120.0f) {
                func_808001CC_chmayafarmer(param_0, 5);
            }
            if (func_80101E14(param_0, 0.75f)) {
                _subaddieaudioquick_entrypoint_2(param_0, local_1, D_80801220_chmayafarmer);
                return;
            }
            break;
        case 5:
            if (func_80101E14(param_0, 0.75f)) {
                _subaddieaudioquick_entrypoint_2(param_0, local_1, D_80801220_chmayafarmer);
            }
            break;
    }
}

void func_8080085C_chmayafarmer(Actor *param_0)
{
    param_0->scale = 0.375f;
    if (func_800D0A9C(4, 1)) {
        param_0->unk74_7 = 0;
        func_808001CC_chmayafarmer(param_0, 5);
    }
    if (_glcutDll_entrypoint_20()) {
        param_0->unk74_7 = 0;
        func_808001CC_chmayafarmer(param_0, 5);
        param_0->unk64_19 = 1;
    }
}

int chmayafarmer_entrypoint_0()
{
  return &D_80801278_chmayafarmer;
}

s32 func_808008F8_chmayafarmer(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    switch (param_1) {
        case 0x40:
            func_800EC398(param_2, local_0);
            func_800EFCD8((f32 *)&param_0->actorData[4], func_800F1DF4(local_0, param_0->position), 25.0f);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801230_chmayafarmer);
            func_80102424(param_0, 3);
            func_8010A570(param_0);
            func_8010114C(param_0->unk3C, param_1, param_2);
            break;
        default: return 0;
    }
    return 1;
}

void func_808010DC_chmayafarmer();

void func_80801040_chmayafarmer();

void func_808009A0_chmayafarmer(Actor *param_0)
{
    void *local_0;
    f32 local_1[3];
    f32 local_2[3];

    func_8010D254(local_1);
    if (local_1[1] < 2000.0f) {
        if (param_0->unk70_10 == 1 || param_0->unk70_10 == 2) {
            func_808010DC_chmayafarmer(param_0);
        }
        param_0->unk64_16 = 0;
    } else {
        param_0->unk64_16 = 1;
        local_0 = func_80106790(param_0->unk3C);
        if (func_800EFFB4(param_0->position, 500.0f, (f32 *)((u8 *)local_0 + 4))) {
            func_8010114C(param_0->unk3C, 0x11, 0);
        }
        switch (param_0->unk70_10) {
        case 1:
        case 2:
            if (func_800DA9E4(5, 0)) {
                func_808000B0_chmayafarmer(local_0, 0xF, 0x418, param_0->unk0);
            }
            func_80800D60_chmayafarmer(param_0, local_0);
            func_800EF04C(param_0->position, (f32 *)((u8 *)param_0 + 0x28));
            func_808010DC_chmayafarmer(param_0);
            break;
        case 3:
            if (param_0->unk58 < param_0->position[1]) {
                func_80801040_chmayafarmer(param_0);
                func_808010DC_chmayafarmer(param_0);
            } else {
                ((f32 *)param_0->actorData)[5] = 0.0f;
                func_800EF04C(param_0->position, (f32 *)((u8 *)param_0 + 0x28));
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080123C_chmayafarmer);
                func_80102424(param_0, 4);
            }
            break;
        case 4:
            if (func_80101E14(param_0, 0.75f)) {
                _subaddiefade_entrypoint_3(param_0);
            }
            break;
        }
        func_800EE7F8(local_2, param_0->position);
        local_2[1] = 2608.0f;
        _chbadshad_entrypoint_1(param_0, local_2, param_0->scale * 1.4f);
    }
}

void func_80800B9C_chmayafarmer(Actor *param_0)
{
    FarmerScatterOrigin *local_0;
    f32 local_2;
    f32 local_1;
    local_0 = func_800CC63C(((FarmerRouteKeys *)param_0)->local_0 - 1,
                          ((FarmerRouteKeys *)param_0)->local_1 - 1);
    func_800EE7F8(param_0->position, local_0->local_0);
    local_1 = func_800DC178(0.0f, 360.0f);
    local_2 = func_800DC178(local_0->local_1 * 0.3f, local_0->local_1);
    func_800EF1B8(param_0->position, local_1, local_2);
    param_0->unk58 = 2605.0f;
    param_0->scale = 0.5f;
}

s32 func_80800C58_chmayafarmer(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;

    func_800EEC30(local_0, param_0->rotation[0], param_0->rotation[1], 200.0f);
    func_800EF04C(local_0, param_0->position);
    if (local_0[1] < param_0->unk58 + 250.0f) return 0;
    local_1 = func_800CC338(local_0, ((FarmerRouteKeys *)param_0)->local_0 - 1,
                          ((FarmerRouteKeys *)param_0)->local_1 - 1);
    if (local_1 != -1) {
        ((FarmerRouteKeys *)param_0)->local_1 = local_1 + 1;
        return 1;
    }
    return 0;
}

void func_80800D18_chmayafarmer(u8 *param_0) {
    u32 local_0;
    u32 local_1;
    u32 local_2;
    u32 local_3;

    local_0 = *(u32 *)(param_0 + 0x70);
    local_1 = ((local_0 << 22) >> 26) - 1;
    local_2 = (local_0 >> 25) - 1;
    local_3 = func_800CC63C(local_2, local_1);
    func_800EE7F8(param_0 + 0x18, local_3);
}

void func_80800D60_chmayafarmer(param_0, param_1) Actor *param_0; Actor *param_1;
{
    switch (param_0->unk70_10) {
    case 1:
        if (*(f32 *)&param_0->actorData[3] < 8.0f) {
            *(f32 *)&param_0->actorData[3] += 1.0f;
        }
        if (!func_80800C58_chmayafarmer(param_0)) {
            func_80800D18_chmayafarmer(param_0);
            func_80102424(param_0, 2);
        }
        if (func_800DC0C0() < 0.05f) {
            param_0->unk50 = func_800DC178(-25.0f, 25.0f);
        }
        if (func_800DC0C0() < 0.05f) {
            param_0->unk54 += func_800DC178(-90.0f, 90.0f);
        }
        break;
    case 2:
        if (func_80800C58_chmayafarmer(param_0)) {
            func_80102424(param_0, 1);
        }
        if (6.0f < *(f32 *)&param_0->actorData[3]) {
            *(f32 *)&param_0->actorData[3] -= 2.0f;
        }
        param_0->unk54 = func_800F1DF4(param_0->position, (f32 *)&param_0->actorData[0]);
        param_0->unk50 = -func_800F1828(param_0->position, (f32 *)&param_0->actorData[0]);
        break;
    }
    if (!func_80102CF4(param_0, 16.0f)) {
        if (param_0->rotation[1] < param_0->unk54) {
            if (param_0->rotation[2] < 15.0f) {
                param_0->rotation[2] += 1.0f;
            }
        } else if (-15.0f < param_0->rotation[2]) {
            param_0->rotation[2] -= 1.0f;
        }
    } else {
        param_0->rotation[2] *= 0.75f;
    }
    if (param_1->unk6C_0 == 1) {
        *(f32 *)&param_0->actorData[3] = 2.0f;
        param_0->rotation[1] += param_0->rotation[2] * 0.02f;
        param_0->rotation[0] = 0.0f;
    } else {
        if (!func_80102D4C(param_0, 2.0f)) {
            func_80102B6C(param_0, 2.0f);
        }
        param_0->rotation[1] += param_0->rotation[2] * 0.2f;
    }
    func_800EF4E4((f32 *)&param_0->actorData[4], param_0->rotation[0], param_0->rotation[1], 0.0f, 0.0f, *(f32 *)&param_0->actorData[3]);
}

void func_80801040_chmayafarmer(Actor *param_0)
{
    if (!func_80102EC8(param_0, param_0->position)) {
        *(f32 *)&param_0->actorData[4] = 0.0f;
        *(f32 *)&param_0->actorData[6] = 0.0f;
    }
    func_800EF04C(param_0->position, (f32 *)&param_0->actorData[4]);
    *(f32 *)&param_0->actorData[5] -= 5.0f;
    if (param_0->position[1] < param_0->unk58) param_0->position[1] = param_0->unk58;
    if (!func_80102CF4(param_0, 6.0f)) func_80102B2C(param_0, 4.0f);
}

void func_808010DC_chmayafarmer(u8 *param_0) {
    _subaddieaudioloop_entrypoint_4(param_0, param_0 + 4, 1, &D_808012E8_chmayafarmer);
}

int *chmayafarmer_entrypoint_1()
{
    return &D_808012FC_chmayafarmer;
}
