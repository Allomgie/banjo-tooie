#include "common.h"

extern void func_8010D5DC(void);
extern s32 D_80801A0C_chnewmumbo[];
extern u8 D_80801AC8_chnewmumbo[];
extern u8 D_80801AB8_chnewmumbo[];
extern void _gcdialogcamera_entrypoint_3(u32 *, f32);
typedef struct { u8 pad[0x64]; u32 pad64:12; u32 flag:1; u32 rest:19; } MumboState;
extern s32 func_800F54E4(void);
extern void func_800F82D4(s32, s32);
extern void func_801017D0(Actor *);
extern f32 D_80801A00_chnewmumbo[3];
extern f32 D_808019F4_chnewmumbo[];
extern int D_80801B14_chnewmumbo[];
extern void func_80102424();
typedef struct { u8 pad_0[0x74]; u32 pad_1 : 28; u32 local_0 : 4; } MumboRenderMode1081;
typedef struct { u8 pad_0[0x7A]; u8 pad_1 : 2; u8 local_0 : 2; u8 local_1 : 3; u8 pad_2 : 1; } MumboActionFlags1081;
typedef struct { u8 pad_0[0x70]; u32 pad_1 : 9; u32 local_0 : 1; u32 pad_2 : 22; } MumboPhaseFlag1081;
typedef struct { s32 local_0[3]; } MumboTableTop50;
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 18; u32 local_0 : 2; u32 local_1 : 3; u32 pad_2 : 9; } MumboActionTop50;
extern u8 *func_80100094(void *, u32);
extern f32 func_800D8FF8(void);
extern void func_8008FB10(f32 *, f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800DC298(f32);
extern s32 func_800902E4(f32 *, f32, s32, Actor **);
extern Actor *func_80106790(Unk80132ED0 *);
extern Unk80132ED0 *func_8008FDEC(void);
extern void _suexpression_entrypoint_10(void *, Unk80132ED0 *, s32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern f32 func_80013728(f32);
extern f32 func_80090010(void);
extern f32 func_8008FEF0(void);
void func_8080073C_chnewmumbo();
void func_80800264_chnewmumbo();
void func_808014FC_chnewmumbo();

void func_80800000_chnewmumbo(s32 *param_0, s32 param_1, s32 param_2) {
    u8 *local_0;
    u8 local_1;
    u8 *local_2;

    local_2 = func_80100094(param_0, 0);
    local_0 = local_2;
    local_1 = (*(u8 *)((s8 *)(local_2) + (0x24)));
    switch (local_1) {                              
    case 0:
        _capod_entrypoint_2(*param_0, 0xA, 0);
        
    case 1:
        _capod_entrypoint_8(1);
        (*(s8 *)((s8 *)(local_0) + (0x24))) = 2;
        _gcdialogcamera_entrypoint_6(*param_0);
        _gcdialogcamera_entrypoint_8();
        
    case 2:
        _capod_entrypoint_7(param_1, param_2);
        return;
    }
}

void func_8080009C_chnewmumbo(s32 param_0)
{
  u8 *local_0;
    u8 *new_var;

    local_0 = func_80100094(param_0, 0);
    if (*(u8 *)((char *)local_0 + 0x24) != 0) {
        new_var = local_0;
        _capod_entrypoint_3(0);
        *(u8 *)((char *)new_var + 0x24) = 0;
  }
}

void func_808000DC_chnewmumbo(Actor *param_0, u32 param_1, u32 param_2)
{
    param_0->unk74_30 = 1;
    _subaddiedialog_entrypoint_11(param_0->unk0, param_1, param_2, param_0->position, 0x10);
}

int func_8080011C_chnewmumbo()
{
  s32 local_0;
  if (!func_800DA298(0x9C5))
  {
    return 0;
  }
  local_0 = func_800EA05C();
  switch (local_0)
  {
    case 0xB7:
      return 0x37F;

    case 0xD9:
      return 0x380;

    case 0x176:
      return 0x381;

    case 0xEF:
      return 0x382;

    case 0x171:
      return 0x383;

    case 0x172:
      return 0x387;

    case 0x134:
      return 0x384;

    case 0x13E:
    case 0x13F:
      return 0x385;

    case 0x156:
      return 0x386;

    default:
      return 0;
  }
}

void func_80800210_chnewmumbo(s32 param_0[3])
{
  func_8008F8B0();
  func_8008F8D8(1);
  func_8008F938(1);
  func_8008F904(&func_8010D5DC, param_0[0]);
  func_8008F990(&D_80801A0C_chnewmumbo, 0x43480000);
}

void func_80800264_chnewmumbo(param_0, param_1) Actor *param_0; s32 param_1;
{
    extern void _suexpression_entrypoint_12(void *, f32, f32);
    u8 *local_0;
    local_0 = (u8 *)func_80100094(param_0, 0);
    if (param_0->unk70_10 == 6) {
        ((MumboRenderMode1081 *)param_0)->local_0 = 1;
    }
    if (func_800DA298(0x9C6)) {
        func_80102424(param_0, param_1);
        switch (param_0->unk70_10) {
        case 1:
            local_0[1] = 1;
            local_0[2] = 0;
            break;
        case 2:
        case 3:
        case 4:
            func_80800210_chnewmumbo(param_0);
            break;
        case 5:
            func_8080073C_chnewmumbo(param_0, func_80090178(1));
            func_80800000_chnewmumbo(param_0, 2, 1);
            break;
        case 6:
            ((MumboRenderMode1081 *)param_0)->local_0 = 1;
            ((MumboActionFlags1081 *)param_0)->local_1 = 3;
            ((MumboActionFlags1081 *)param_0)->local_0 = 3;
            param_0->unk6C_0 = 0;
            ((MumboPhaseFlag1081 *)param_0)->local_0 = 1;
            break;
        case 7:
            ((MumboRenderMode1081 *)param_0)->local_0 = 1;
            if (!func_800DA9E4(0x7D, 1)) {
                func_808000DC_chnewmumbo(param_0, 0x11D6, 7);
            } else {
                func_808000DC_chnewmumbo(param_0, 0x11E4, 7);
            }
            _suexpression_entrypoint_12(func_80100094(param_0, 1), 60.0f, 0.0f);
            break;
        case 8:
            if (func_800D1A04(0x48) > 0) {
                func_808000DC_chnewmumbo(param_0, 0x11D7, 0x46);
            } else {
                func_808000DC_chnewmumbo(param_0, 0x11DA, 7);
            }
            break;
        case 18:
            local_0[1] = 0;
            func_800EE7F8(param_0->position, D_808019F4_chnewmumbo);
            break;
        case 19:
            local_0[2] = 1;
            local_0[1] = 0;
            break;
        case 14:
            func_8080009C_chnewmumbo(param_0);
            func_800904C8(0x8D);
            func_80090590(0x3C, param_0->position);
            local_0[0] = 1;
            if (!func_800DA9E4(0x429, 1)) {
                func_80800000_chnewmumbo(param_0, 5, 1);
                func_808000DC_chnewmumbo(param_0, 0x11E6, 0xF);
            }
            break;
        case 10:
        case 11:
            local_0[1] = 1;
            local_0[2] = 0;
            func_8080009C_chnewmumbo(param_0);
            break;
        }
    }
}

s32 func_808004E8_chnewmumbo(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    u32 local_1;
    u8 *local_2;

    switch (param_1) {
    case 0x32:
        switch (param_0->unk70_10) {
        case 2:
            func_80800264_chnewmumbo(param_0, 5);
            break;
        case 3:
            if (func_800DA298(func_8080011C_chnewmumbo())) {
                func_8080073C_chnewmumbo(param_0, 1);
                func_80800000_chnewmumbo(param_0, 2, 1);
                func_808000DC_chnewmumbo(param_0, 0x11DB, 0x4E);
            } else {
                func_80800000_chnewmumbo(param_0, 2, 1);
                func_8080073C_chnewmumbo(param_0, 1);
                func_80800264_chnewmumbo(param_0, 7);
            }
            break;
        case 4:
            func_80800000_chnewmumbo(param_0, 2, 1);
            func_808000DC_chnewmumbo(param_0, 0x11DB, 0x4E);
            break;
        }
        break;
    case 0x2E:
        func_808014FC_chnewmumbo(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3((u32 *)D_80801AB8_chnewmumbo, param_0->scale);
        if ((s32)param_0->unk70_10 < 14) _gcdialogcamera_entrypoint_4(D_80801AC8_chnewmumbo);
        break;
    case 0x57:
        local_0 = param_2 & 0xFFFF;
        local_1 = (u32)(param_2 & 0xFFFF0000) >> 16;
        if (_gcdialogcamera_entrypoint_0(local_0, local_1)) {
            func_80800000_chnewmumbo(param_0, local_0, local_1);
        }
        break;
    case 0x1F:
        local_2 = func_80100094(param_0, 0);
        func_801015D0(param_0);
        if (local_2[1]) func_800DF744(5, 1);
        else func_800DF744(5, 0);
        if (local_2[2]) func_800DF744(4, 1);
        else func_800DF744(4, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080073C_chnewmumbo(param_0, param_1) Actor *param_0; s32 param_1;
{
    if (!param_0->unk64_19) {
        if (param_1) {
            func_800F7B9C(_plsu_entrypoint_1(1), 0x8D);
        }
        func_800F8300(func_800F54E4(), 2, param_0->position);
        param_0->unk64_19 = 1;
    }
}

void func_808007B0_chnewmumbo(MumboState *param_0) {
    if (param_0->flag) {
        func_800F82D4(func_800F54E4(), 0);
        param_0->flag = 0;
    }
}

void func_808007FC_chnewmumbo(Actor *param_0, s32 param_1)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0[0] == 0) {
        func_80101808(param_0, func_801017D0);
        if (local_0[1] && param_0->unk7C_12) {
            func_800DBEFC((void *)param_0->unk0->unk4, 0xB, local_0 + 4);
        }
    }
}

void func_80800878_chnewmumbo(s32 arg0)
{
    func_80800264_chnewmumbo(arg0,0xE);
}

void func_80800898_chnewmumbo(Actor *param_0)
{
    s32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;

    for (local_0 = 0; local_0 < 3; local_0++) {
        local_1 = D_80801A00_chnewmumbo[local_0];
        local_2 = param_0->position[local_0];
        if (local_1 != local_2) {
            local_3 = (local_1 - local_2) * 0.25f;
            param_0->position[local_0] = local_2 + local_3;
        }
    }
    if (param_0->rotation[1]) {
        param_0->rotation[1] *= 0.25f;
    }
    if (param_0->rotation[0]) {
        param_0->rotation[0] *= 0.25f;
    }
}

void func_8080092C_chnewmumbo(Actor *param_0)
{
    extern MumboTableTop50 D_80801AD4_chnewmumbo;
    extern u8 D_80801990_chnewmumbo[];
    extern u8 D_8080199C_chnewmumbo[];
    extern u8 D_808019A8_chnewmumbo[];
    extern u8 D_808019B4_chnewmumbo[];
    extern u8 D_808019C0_chnewmumbo[];
    extern u8 D_808019C8_chnewmumbo[];
    extern u8 D_808019D4_chnewmumbo[];
    extern u8 D_808019E4_chnewmumbo[];
    extern u8 D_80801AE0_chnewmumbo[];
    extern u8 D_80801AF0_chnewmumbo[];
    extern f32 D_80801AFC_chnewmumbo[];
    extern f32 D_80801B08_chnewmumbo[];

    MumboTableTop50 local_7 = D_80801AD4_chnewmumbo;
    f32 local_4[3];
    u8 *local_0;

    local_0 = (u8 *)func_80100094(param_0, 0);

    if (func_800C0638()) {
        *(f32 *)((u8 *)param_0 + 0x24) = 1.5f;
    } else if (0.0f < *(f32 *)((u8 *)param_0 + 0x24)) {
        *(f32 *)((u8 *)param_0 + 0x24) -= func_800D8FF8();
    }

    if (!func_800DA298(func_8080011C_chnewmumbo()) &&
        *(f32 *)((u8 *)param_0 + 0x24) <= 0.0f) {
        func_800D1824(0x48);
    }

    if (func_8010D278() == 0xD) {
        s32 local_8;
        f32 local_3[3];
        func_8010D254(local_3);

        local_8 = _plsu_entrypoint_1(1);

        if (func_800F6D24(local_8)) {
            func_800F8804(local_8, local_3);
        }
    }

    if (*(u8 *)(local_0 + 0) == 0) {
        func_8008FB10(
            param_0->position,
            param_0->scale * 150.0f,
            param_0->scale * -75.0f,
            param_0->scale * 100.0f
        );
    }

    func_8010D254(local_4);

    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);

    switch (param_0->unk70_10) {
        case 19:
            switch (func_8008FD70()) {
            case 1:
                if (!param_0->unk74_30 &&
                    _subaddiedialog_entrypoint_6(param_0->position,
                        (s32)param_0->rotation[1], 750, 90, 6)) {
                    func_80800264_chnewmumbo(param_0, 4);
                }
                break;
            case 0x200:
            case 0x400:
                if (!param_0->unk74_30 &&
                    _subaddiedialog_entrypoint_6(param_0->position,
                        (s32)param_0->rotation[1], 750, 90, 6)) {
                    func_80800000_chnewmumbo(param_0, 2, 1);
                    func_808000DC_chnewmumbo(param_0, 0x11EB, 0xF);
                }
                break;
            }
            break;
        case 1:
            ((MumboRenderMode1081 *)param_0)->local_0 = 2;

            if (func_80101E14(param_0, 0.3f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_80801990_chnewmumbo
                );
            } else if (func_80101E14(param_0, 0.7f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_8080199C_chnewmumbo
                );
            }

            switch (func_8008FD70()) {
            case 1:
            case 0x200:
            case 0x400:
                break;
            default:
                return;
            }

            if (_subaddiedialog_entrypoint_3(
                    param_0->position,
                    (s32)param_0->rotation[1],
                    0x1F4,
                    0x5A,
                    6)) {
                func_80800264_chnewmumbo(param_0, 2);
            }
            break;

        case 2:
            if (func_80101E14(param_0, 0.3f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_80801990_chnewmumbo
                );
            } else if (func_80101E14(param_0, 0.7f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_8080199C_chnewmumbo
                );
            }
            break;

        case 5:
            if (func_80101E14(param_0, 0.999f)) {
                func_80800264_chnewmumbo(param_0, 6);
            }
            break;

        case 6:
            if (func_80101E14(param_0, 0.2f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_808019A8_chnewmumbo
                );
            }

            if (param_0->unk6C_0 < 100) {
                param_0->unk6C_0++;
                if (param_0->unk6C_0 < 20) {
                    ((MumboActionTop50 *)param_0)->local_1 = 3;
                } else if (param_0->unk6C_0 < 40) {
                    ((MumboActionTop50 *)param_0)->local_1 = 2;
                } else if (param_0->unk6C_0 < 60) {
                    ((MumboActionTop50 *)param_0)->local_1 = 1;
                } else {
                    ((MumboActionTop50 *)param_0)->local_1 = 0;
                    ((MumboActionTop50 *)param_0)->local_0 = 1;
                }
            } else if (func_800DC298(0.3f) &&
                       (s32)((MumboActionTop50 *)param_0)->local_1 < 3) {
                ((MumboActionTop50 *)param_0)->local_0 = 1;
            } else if (func_800DC298(0.05f) &&
                       (s32)((MumboActionTop50 *)param_0)->local_1 > 0) {
                ((MumboActionTop50 *)param_0)->local_0 = 2;
            }

            if (func_80101E14(param_0, 0.999f)) {
                switch (func_8008FD70()) {
                case 1:
                    func_80800264_chnewmumbo(param_0, 7);
                    return;
                case 0x200:
                case 0x400:
                    func_808007B0_chnewmumbo(param_0);
                    func_808000DC_chnewmumbo(param_0, 0x11EB, 0xF);
                    func_80800264_chnewmumbo(param_0, 0xB);
                    return;
                default:
                    func_80800264_chnewmumbo(param_0, 0xB);
                    break;
                }
                return;
            }
            break;

        case 7:
            if (func_80101E14(param_0, 0.999f)) {
                func_80800264_chnewmumbo(param_0, 8);
            }
            break;

        case 8:
            if (!func_800DA298(func_8080011C_chnewmumbo())) {
                switch (*(u8 *)(local_0 + 3)) {
                    case 0:
                        break;
                    case 1:
                        func_808007B0_chnewmumbo(param_0);
                        func_80090658(1);
                        *(u8 *)(local_0 + 3) = 2;
                        break;

                    case 2:
                        if (param_0->unk7C_12 &&
                            func_800902E4(param_0->position, 750.0f, 0x29F, &param_0) &&
                            func_8008FE14() == 0x29F && func_80090818()) {
                            param_0->unk3C = func_8008FDEC();
                            func_80090768(local_0 + 4);
                            local_0[3] = 3;
                        }
                        break;

                    case 3: {
                        Actor *local_2 = func_80106790(param_0->unk3C);
                        func_800EE7F8(local_2->actorData, (f32 *)(local_0 + 4));
                        local_2->unk74_30 = 1;
                        local_2->unk64_19 = 1;
                        *(u8 *)(local_0 + 3) = 4;

                        func_8080073C_chnewmumbo(param_0, 1);
                        func_80090658(0);
                        return;

                    }
                    case 4:
                        func_80800264_chnewmumbo(param_0, 0xD);
                        *(u8 *)(local_0 + 3) = 0;
                        break;
                }
            }
            break;

        case 13:
            if (func_80101E14(param_0, 0.7f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_808019C0_chnewmumbo
                );
                _chjujubagfx_entrypoint_2();
            }

            if (func_80101E14(param_0, 0.999f)) {
                func_800FC6B0(0x10);
                func_80800264_chnewmumbo(param_0, 0x11);
                func_80800000_chnewmumbo(param_0, 2, 1);
                func_800DA544(func_8080011C_chnewmumbo());
                func_800D175C(0x48, -1);
                return;
            }
            break;

        case 17:
            if (func_80101E14(param_0, 0.05f)) {
                func_800DA544(0x9F3);
                return;
            }

            if (func_80101DDC(param_0)) {
                func_80800264_chnewmumbo(param_0, 0x12);
                return;
            }

            if (func_80101E14(param_0, 0.87f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_808019B4_chnewmumbo
                );
                return;
            }

            if (func_80101E14(param_0, 0.76f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_808019C8_chnewmumbo
                );
                return;
            }

            if (func_80101E4C(
                    param_0,
                    D_80801AE0_chnewmumbo)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_808019D4_chnewmumbo
                );
                return;
            }
            break;

        case 18:
            if (func_80101E14(param_0, 0.79f)) {
                *(u8 *)(local_0 + 2) = 1;
            } else if (func_80101E14(param_0, 0.999f)) {
                func_80800878_chnewmumbo(param_0);
                return;
            } else if (func_80101E4C(
                           param_0,
                           D_80801AF0_chnewmumbo)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_808019E4_chnewmumbo
                );
                return;
            }
            break;

        case 14:
            if (!func_8010C9FC(
                    param_0->position,
                    0x1C2,
                    0x1F4,
                    0x96)) {
                func_80800264_chnewmumbo(param_0, 0xF);
                return;
            }
            break;

        case 15: {
            s32 local_8;
            f32 local_6[3];
            if (!func_800EFED0(
                    D_80801AFC_chnewmumbo,
                    D_80801B08_chnewmumbo,
                    local_4)) {
                return;
            }

            if (!func_80090248()) {
                return;
            }

            func_8010D254(local_6);

            local_8 = _plsu_entrypoint_1(1);
            func_800F7B9C(local_8, 0x3D);

            *(u8 *)(local_0 + 0) = 0;

            func_80800264_chnewmumbo(param_0, 0x10);

            func_800EE7F8(
                param_0->position,
                local_6
            );

            func_808007B0_chnewmumbo(param_0);
            return;

        }
        case 16:
            param_0->rotation[1] = func_80013728(func_80090010());

            param_0->rotation[0] =
                func_8008FEF0();

            func_80800264_chnewmumbo(param_0, 9);
            return;

        case 9:
            func_80800898_chnewmumbo(param_0);

            if (func_80101E14(param_0, 0.21f)) {
                *(u8 *)(local_0 + 2) = 0;
            }

            if (func_80101E14(param_0, 0.83f)) {
                *(u8 *)(local_0 + 1) = 1;
            }

            if (func_80101DDC(param_0)) {
                func_80800264_chnewmumbo(param_0, 0xA);

                _suexpression_entrypoint_12(
                    func_80100094(param_0, 1),
                    0.0f,
                    0.0f
                );
                return;
            }
            break;

        case 10: {
            f32 local_5[3];
            func_8010D254(local_5);
            func_80800898_chnewmumbo(param_0);
            func_80800264_chnewmumbo(param_0, 0xB);
            return;

        }
        case 11:
            switch (func_8008FD70()) {
            case 1:
                if (!param_0->unk74_30 &&
                    _subaddiedialog_entrypoint_6(param_0->position,
                        (s32)param_0->rotation[1], 750, 90, 6)) {
                    func_80800264_chnewmumbo(param_0, 3);
                }
                break;
            case 0x200:
            case 0x400:
                if (!param_0->unk74_30 &&
                    _subaddiedialog_entrypoint_6(param_0->position,
                        (s32)param_0->rotation[1], 750, 90, 6)) {
                    func_80800000_chnewmumbo(param_0, 2, 1);
                    func_808000DC_chnewmumbo(param_0, 0x11EB, 0xF);
                }
                break;
            }
            break;

    }
}

void func_808014FC_chnewmumbo(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2; {
    u32 temp_t1;
    u32 temp_t2;
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    (*(u8 *)((s8 *)(param_0) + (0x74))) = (u8) ((*(u8 *)((s8 *)(param_0) + (0x74))) & 0xFFBF);
    switch (param_1) {
    case 0x11D7:
        if (param_2 > 0) {
            func_808000DC_chnewmumbo(param_0, 0x11D8, 7);
            return;
        }
        func_808000DC_chnewmumbo(param_0, 0x11D9, 7);
        return;
    case 0x11D9:
        func_800EE7F8(param_0 + 0x18, param_0 + 4, param_2);
        func_808007B0_chnewmumbo(param_0);
        func_80800264_chnewmumbo(param_0, 0xA);
        return;
    case 0x11DA:
        func_800EE7F8(param_0 + 0x18, param_0 + 4, param_2);
        func_808007B0_chnewmumbo(param_0);
        func_80800264_chnewmumbo(param_0, 0xA);
        return;
    case 0x11D8:
        (*(s8 *)((s8 *)(temp_v0) + (3))) = 1;
        return;
    case 0x11EB:
        func_8080009C_chnewmumbo(param_0);
        return;
    case 0x11DB:
        temp_t1 = (u32) (*(u16 *)((s8 *)(param_0) + (0x72))) >> 0xA;
        if (temp_t1 != 3) {
            if (temp_t1 == 4) {
                if (param_2 > 0) {
                    func_80800878_chnewmumbo(param_0);
                    return;
                }
                func_808000DC_chnewmumbo(param_0, 0x11EA, 0xF);
                return;
            }
        } else {
            if (param_2 > 0) {
                func_80800000_chnewmumbo(param_0, 2, 1);
                func_80800264_chnewmumbo(param_0, 0x11);
                return;
            }
            func_808000DC_chnewmumbo(param_0, 0x11EA, 0xF);
            return;
        }
        return;
    case 0x11EA:
        temp_t2 = (u32) (*(u16 *)((s8 *)(param_0) + (0x72))) >> 0xA;
        switch (temp_t2) {
        case 3:
            func_80800264_chnewmumbo(param_0, 0xB, param_2);
            func_808007B0_chnewmumbo(param_0);
            return;
        case 4:
            func_8080009C_chnewmumbo(param_0);
            func_808007B0_chnewmumbo(param_0);
            func_80800264_chnewmumbo(param_0, 0x13);
            return;
        }
        break;
    case 0x11E6:
        func_8080009C_chnewmumbo(param_0);
        break;
    }
}

s32 chnewmumbo_entrypoint_0(s32 param_0, s32 param_1)
{
  s32 local_0;
 goto dummy_label_457575; func_80100094(param_0, 0); dummy_label_457575: ;
  local_0 = func_800EE7F8(param_1, 4 + func_80100094(param_0, 0));
}

void func_8080172C_chnewmumbo(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_80801760_chnewmumbo(Actor *param_0)
{
    s8 *local_0;
    local_0 = (s8 *)func_80100094(param_0, 0);
    func_800EE7F8(param_0->position, ((f32 *) D_80801A00_chnewmumbo));
    param_0->scale = 0.5f;
    _suexpression_entrypoint_7(param_0, 1, 0x10);
    if (func_8010D278() == 0xD) {
        *local_0 = 1;
        func_80800264_chnewmumbo(param_0, 0xF);
    } else {
        *local_0 = 0;
        if (func_800DA298(func_8080011C_chnewmumbo()) || _glcutDll_entrypoint_20()) {
            func_800EE7F8(param_0->position, D_808019F4_chnewmumbo);
            func_80800264_chnewmumbo(param_0, 0x13);
        } else if (func_800DA298(0x7D)) {
            func_80800264_chnewmumbo(param_0, 0xA);
        } else {
            func_80800264_chnewmumbo(param_0, 1);
        }
    }
    param_0->rotation[0] = 0.0f;
}

int chnewmumbo_entrypoint_1()
{
    return (int)&D_80801B14_chnewmumbo;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/newmumbo.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80801A0C_chnewmumbo -> s32[], D_80801B14_chnewmumbo -> int[] */
extern void func_80105834();
extern void func_80107C2C();
u8 D_80801990_chnewmumbo[12] = { 0x0, 0x13, 0x4, 0x41, 0x0, 0x16, 0x17, 0x70, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080199C_chnewmumbo[12] = { 0x0, 0x13, 0x4, 0x42, 0x0, 0x16, 0x17, 0x70, 0x0, 0x0, 0x0, 0x0 };
u8 D_808019A8_chnewmumbo[12] = { 0x0, 0x13, 0x5, 0x4D, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0, 0x0, 0x0 };
u8 D_808019B4_chnewmumbo[12] = { 0x0, 0x13, 0x4, 0x4, 0x0, 0x16, 0x5D, 0xC0, 0x0, 0x0, 0x0, 0x0 };
u8 D_808019C0_chnewmumbo[8] = { 0x0, 0x13, 0x4, 0x4, 0x0, 0x18, 0x0, 0x0 };
u8 D_808019C8_chnewmumbo[12] = { 0x0, 0x13, 0x5, 0x11, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0, 0x0, 0x0 };
u8 D_808019D4_chnewmumbo[16] = { 0x0, 0x13, 0x6, 0x2B, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0 };
u8 D_808019E4_chnewmumbo[16] = { 0x0, 0x13, 0x5, 0xAF, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0 };
f32 D_808019F4_chnewmumbo[3] = { 0.0f, -3e+01f, -275.0f };
f32 D_80801A00_chnewmumbo[3] = { 0.0f, 67.0f, -4.4e+02f };
s32 D_80801A0C_chnewmumbo[3] = { 0x0, -0x3D780000, -0x3D380000 };
u32 D_80801A18_chnewmumbo[40] = { 0x0, 0x0, 0x40400000, 0x1AF0001, 0x40400000, 0x1AF0001, 0x40DAA7F0, 0x3010001, 0x40C0F5C3, 0xB50001, 0x40400000, 0x1AF0001, 0x40800000, 0x1B00002, 0x3FC00000, 0x1B10002, 0x40751EB8, 0x1B20001, 0x40470A3D, 0xFD0002, 0x40DAA7F0, 0x3010001, 0x40DAA7F0, 0x3010001, 0x40DAA7F0, 0x3010001, 0x3FB33333, 0x1B30002, 0x40400000, 0x1AF0001, 0x40400000, 0x1AF0001, 0x40400000, 0x1AF0001, 0x407D70A4, 0xCE0002, 0x3FE66666, 0xCF0202, 0x40C0F5C3, 0xB50001 };
u8 D_80801AB8_chnewmumbo[16] = { 0x43, 0x98, 0x80, 0x0, 0x43, 0x6B, 0x0, 0x0, 0x43, 0x6B, 0x0, 0x0, 0x43, 0x7, 0x0, 0x0 };
u8 D_80801AC8_chnewmumbo[12] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC3, 0xC8, 0x0, 0x0 };
MumboTableTop50 D_80801AD4_chnewmumbo = { 0x0, -0x3D780000, -0x3D4C0000 };
u8 D_80801AE0_chnewmumbo[16] = { 0x3E, 0xF5, 0xA8, 0x58, 0x3F, 0x5, 0x1E, 0xB8, 0x3F, 0xF, 0x5C, 0x29, 0xBF, 0x80, 0x0, 0x0 };
u8 D_80801AF0_chnewmumbo[12] = { 0x3E, 0x8F, 0x9D, 0xB2, 0x3E, 0xEB, 0x85, 0x1F, 0xBF, 0x80, 0x0, 0x0 };
f32 D_80801AFC_chnewmumbo[3] = { -65.0f, 5e+01f, -544.0f };
f32 D_80801B08_chnewmumbo[3] = { 65.0f, 7e+01f, -4.1e+02f };
int D_80801B14_chnewmumbo[19] = { 0x2250190, 0x6650001, (u32)&D_80801A18_chnewmumbo, (u32)func_8080092C_chnewmumbo, (u32)func_80105834, (u32)func_808007FC_chnewmumbo, 0x0, 0x0, 0x0, 0x20080164, (u32)func_8080172C_chnewmumbo, 0x0, 0x280000, (u32)func_80801760_chnewmumbo, (u32)func_80107C2C, -0x7FFFFFFE, (u32)func_808004E8_chnewmumbo, 0x0, 0x0 };
