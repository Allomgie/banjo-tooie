#include "common.h"

extern void *func_800F5EF8(void *);
extern void *func_80100094(Actor *, u32);
typedef struct {
    u8 unk0[3][4];
    s32 unkC;
    s32 unk10;
    u8 pad14[0xC];
    s32 unk20;
    u8 pad24[0x31];
    u8 unk55;
    u8 pad56[2];
    u8 unk58;
    u8 unk59;
    u8 pad5A[2];
    u8 unk5C;
    u8 unk5D;
    u8 unk5E;
    u8 unk5F;
    u8 unk60;
} DragonData_80800070_chdragonbrothers;
typedef struct {
    u8 pad0[0x16];
    u16 unk16;
} DragonModel;
extern f32 D_80805570_chdragonbrothers[];
extern s32 _glcutDll_entrypoint_20(void);
extern s32 func_800EA05C(void);
extern void func_801032B0(Actor *, s32, s32);
extern s32 func_800DA298(s32);
extern void func_800D1000(s32, s32, f32 *, s32, Unk80132ED0 *);
extern void _chintrotext_entrypoint_2(s32);
extern void func_800FFAB0(Actor *);
extern s32 func_800D395C(void);
extern void _suexpression_entrypoint_7(Actor *, s32, s16);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800EF030(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct {
    u8 pad_0[0x20];
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    u8 pad_1[9];
    u8 local_7;
} DragonBrotherCamera;
extern f32 D_8080557C_chdragonbrothers[3];
extern f32 func_800F1DF4(f32 *, f32 *);
typedef struct {
    u8 unused0[0x20];
    void *player;
    u8 unused24[0x3B];
    u8 active;
} DragonCameraState;
extern void func_80090734(s32, s32);
extern void func_80090708(s32);
extern f32 func_800F2094(f32, f32);
typedef struct {
    u8 pad_0[0x18];
    f32 local_0;
    f32 local_1;
} DragonYaw1482;
extern s32 func_80090248(void);
extern s32 func_8008FA2C(s32, s32);
extern int D_808056A8_chdragonbrothers[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern void func_800EFCD8(f32 *, f32, f32);
typedef struct {
    u8 pad[0x7A];
    u8 p7 : 7;
    u8 b0 : 1;
} B7A;
typedef struct {
    u8 pad[4];
    u8 a[4];
    s8 b[4];
} DrbS;
extern Actor *func_80106790(Unk80132ED0 *);
extern u8 D_8080543C_chdragonbrothers[];
extern int D_8080574C_chdragonbrothers[];
typedef union {
    s32 local_0;
    Unk80132ED0 *local_1;
} DragonMessage1804;
extern u8 D_80805870_chdragonbrothers[];
extern u8 D_80805840_chdragonbrothers[];
extern void _chexploder_entrypoint_15(Actor *, s32, f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern void *D_808058A8_chdragonbrothers;
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 21;
    u32 local_0 : 1;
    u32 pad_2 : 10;
} DragonMarker1864;
extern s16 D_808058F0_chdragonbrothers[];
extern void func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_800DC178(f32, f32);
typedef struct {
    u8 pad_0[4];
    f32 local_0;
    u8 pad_1[4];
    s32 local_1;
} DragonFrameState;
typedef struct {
    u8 pad_0[10];
    u8 local_0 : 5;
    u8 pad_1 : 3;
} DragonFrameModel;
extern f32 func_800D8FF8(void);
extern f32 func_800F13C4(f32, f32);
extern int D_80805918_chdragonbrothers[];
extern int D_80805960_chdragonbrothers[];
extern int D_808059A8_chdragonbrothers[];
extern int D_808059D8_chdragonbrothers[];
extern void func_800EFA20(f32 *, f32 *, f32);
extern u8 D_808059EC_chdragonbrothers[];
extern s32 D_80805A08_chdragonbrothers[];
extern s32 D_80805A50_chdragonbrothers[];
extern int D_80805488_chdragonbrothers[];
extern int D_80805A5C_chdragonbrothers[];
extern void func_800EF334(f32 *, f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800C3FC0(s32, f32, s32);
extern u8 D_80805588_chdragonbrothers[];
extern u8 D_808055C0_chdragonbrothers[];
extern u8 D_808055DC_chdragonbrothers[];
extern f32 func_80101F24(Actor *);
extern void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0xC];
    s32 unk20;
    u8 pad24[0x34];
    u8 unk58;
    u8 pad59[2];
    u8 unk5B;
} DragonData_80800D98_chdragonbrothers;
extern s32 _plsu_entrypoint_1(s32);
extern void _gcfrontend_entrypoint_9(s32);
extern s32 func_800DA9E4(s32, s32);
extern void func_800DA544(s32);
extern void func_800DA524(s32);
extern void func_800FDC28(s32);
typedef struct {
    u8 pad0[0x18];
    f32 unk18;
    u8 pad1C[0x38];
    u8 unk54;
    u8 pad55[4];
    u8 unk59;
    u8 unk5A;
    u8 unk5B;
    u8 pad5C;
    u8 unk5D;
    u8 unk5E;
} DragonData_808012B4_chdragonbrothers;
extern u32 D_80805558_chdragonbrothers[];
extern u32 D_808053B0_chdragonbrothers[];
extern void func_80102424(Actor *, s32);
extern void _chintrotext_entrypoint_1(s32, s32, s32, s32);
extern void func_80101EE4(Actor *, f32);
extern void func_8010A570(Actor *);
extern void func_8010A590(Actor *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern int func_800DC298(f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
typedef struct {
    u8 pad_0[0xC];
    s32 field_C;
    s32 field_10;
    s32 field_14;
    f32 field_18;
    u8 pad_1[4];
    s32 field_20;
    u8 pad_2[0x34];
    u8 field_58;
    u8 field_59;
    u8 field_5A;
    u8 field_5B;
    u8 field_5C;
    u8 field_5D;
    s8 field_5E;
    u8 field_5F;
    s8 field_60;
    u8 field_61;
    u8 field_62;
    u8 field_63;
    u8 field_64;
} DragonUpdateData;
extern void func_800F5A00(s32, f32 *);
extern void func_800F1EA4(f32 *, f32 *);
extern s32 func_80090178(s32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
typedef struct {
    u8 pad[0x7C];
    u32 pre : 19;
    u32 f : 1;
    u32 rest : 12;
} W7C;
typedef struct {
    u8 pad[0x79];
    u8 hi : 4;
    u8 lo : 4;
} Nib79;
typedef struct {
    u8 pad[0x76];
    u16 idx : 9;
    u16 rest : 7;
} DbIdx76;
typedef struct {
    u8 pad[0x65];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS101;
extern s32 func_80101DDC(void *);
extern void func_80108B04(void *, s32);
extern void _subaddieaudioloop_entrypoint_4(void *, void *, s32, void *);
extern Vec3f D_80805740_chdragonbrothers;
extern Actor *func_801084B0(s32, Actor **);
extern f32 func_800F1828(f32 *, f32 *);
extern void func_800EE780(void *, void *, void *);
extern s32 func_800C6A7C(void *, void *, void *, s32);
extern void func_800EE7F8(void *, void *);
extern void _chexploder_entrypoint_3(void *, void *, s32);
extern void func_800E1610(s32, f32, f32, void *);
extern void _subaddieaudioquick_entrypoint_2(void *, void *, void *);
extern void _subaddiefade_entrypoint_3(void *);
extern void func_800EF04C(void *, void *);
extern u8 D_80805794_chdragonbrothers[];
extern u8 D_80805448_chdragonbrothers[];
extern u8 D_808057A8_chdragonbrothers[];
extern u8 D_808057E0_chdragonbrothers[];
extern u8 D_80805810_chdragonbrothers[];
extern u8 D_80805460_chdragonbrothers[];
extern u8 D_80805474_chdragonbrothers[];
extern f32 func_800DC0C0(void);
extern s32 _fxegg_entrypoint_1(f32 *, f32);
extern s32 _fxegg_entrypoint_2(f32 *, f32);
extern s32 _fxegg_entrypoint_3(f32 *, f32);
extern s32 _fxegg_entrypoint_5(f32 *, f32 *, f32);
extern s32 _fxegg_entrypoint_6(f32 *, f32, f32 *);
extern u8 D_80805900_chdragonbrothers[];
extern s32 _subaddiecustomhits_entrypoint_2(Unk80132ED0 *, f32 *, f32, f32 *, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
void func_808012B4_chdragonbrothers();
extern void func_80105834(), func_80107C2C(), func_80108EE8(), func_80800070_chdragonbrothers(),
    func_80802574_chdragonbrothers(), func_808034DC_chdragonbrothers();

void func_808049D4_chdragonbrothers(u8 *param_0);
extern s32 func_80101E14(Actor *, f32);
extern Vec3f D_80805608_chdragonbrothers;
extern Vec3f D_80805614_chdragonbrothers;
extern u8 D_80805620_chdragonbrothers[];
extern u8 D_80805630_chdragonbrothers[];
extern u8 D_80805640_chdragonbrothers[];
extern u8 D_80805650_chdragonbrothers[];
extern u8 D_8080565C_chdragonbrothers[];
extern u8 D_80805668_chdragonbrothers[];
extern u8 D_808053C8_chdragonbrothers[];
extern u8 D_808053E0_chdragonbrothers[];
extern u8 D_80805678_chdragonbrothers[];
extern u8 D_80805410_chdragonbrothers[];
extern u8 D_80805694_chdragonbrothers[];
extern u8 D_80805424_chdragonbrothers[];
extern u8 D_808053A0_chdragonbrothers[];

void func_80800000_chdragonbrothers(Actor *actor, s32 value)
{
    u8 *pod_cmd;
    s32 i;
    pod_cmd = func_80100094(actor, 0);
    for (i = 0; i < 4; i++) {
        if (pod_cmd[i] != 2)
            pod_cmd[i] = value;
    }
}

void func_80800070_chdragonbrothers(actor) Actor *actor;
{
    DragonData_80800070_chdragonbrothers *data;
    s32 unk_0;

    data = func_80100094(actor, 0);
    unk_0 = _glcutDll_entrypoint_20();
    data->unk20 = -1;
    actor->unk74_7 = actor->unk74_7 - 0x32;
    if (func_800EA05C() == 0x12B) {
        actor->unk7A_8 = 0;
    } else {
        actor->unk7A_8 = 1;
    }
    if (actor->unk7A_8) {
        func_801032B0(actor, 0x7FD, ((DragonModel *) actor->unk0)->unk16);
    }
    data->unk0[0][1] = 0;
    data->unk0[1][1] = 0;
    data->unk0[2][1] = 0;
    data->unk0[0][2] = 0;
    data->unk0[1][2] = 0;
    data->unk0[2][2] = 0;
    data->unk0[0][3] = 0;
    data->unk0[1][3] = 0;
    data->unk0[2][3] = 0;
    data->unk0[0][0] = 0;
    data->unk0[1][0] = 0;
    data->unk0[2][0] = 0;
    data->unk5C = 8;
    data->unk10 = 4;
    if (!unk_0) {
        if (func_800DA298(0x1D5) && func_800DA298(0x1D6)) {
            if ((actor->unk7A_8 && func_800DA298(0x1D2)) ||
                (!actor->unk7A_8 && !func_800DA298(0x1D2))) {
                func_800D1000(0x3D, 1, D_80805570_chdragonbrothers, 0, actor->unk0);
            }
        }
        if ((actor->unk7A_8 && func_800DA298(0x1D5)) ||
            (!actor->unk7A_8 && func_800DA298(0x1D6))) {
            _chintrotext_entrypoint_2(1);
            func_800FFAB0(actor);
            return;
        }
        if (func_800D395C()) {
            if (actor->unk7A_8) {
                actor->unk64_19 = 1;
            }
        } else if ((actor->unk7A_8 && func_800DA298(0x1D6)) ||
                   (!actor->unk7A_8 && func_800DA298(0x1D5))) {
            actor->unk64_19 = 1;
        }
    }
    if (actor->unk64_19) {
        data->unkC = 12;
    } else {
        data->unkC = 6;
    }
    data->unk58 = 0;
    data->unk59 = 0;
    data->unk5D = 0;
    data->unk5E = 0;
    data->unk60 = 0;
    data->unk5F = 0;
    data->unk55 = 0;
    _suexpression_entrypoint_7(actor, 1, actor->unk7A_8 ? 0x75 : 0x76);
    if (unk_0) {
        func_808012B4_chdragonbrothers(actor, 1);
        return;
    }
    actor->unk64_16 = 0;
    if ((actor->unk7A_8 && func_800DA298(0x1D3)) || (!actor->unk7A_8 && func_800DA298(0x1D4))) {
        func_808012B4_chdragonbrothers(actor, 4);
    }
}

void func_808003D8_chdragonbrothers(Actor *actor)
{
    _suexpression_entrypoint_8(actor, 1);
}

int func_808003F8_chdragonbrothers(actor)
Actor *actor;
{
    switch (actor->unk70_10) {
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            return 1;
    }
    return 0;
}

int func_80800438_chdragonbrothers(Actor *actor)
{
    void *data;
    u8 *flags;
    data = func_80100094(actor, 0);
    if (actor->unk74_29 == 0) {
        return 0;
    } else {
        _ncpod_entrypoint_17(func_800F5EF8(*(s32 *) ((u8 *) data + 0x20)), 0);
        flags = (u8 *) actor + 0x74;
        *flags &= 0xFFDF;
        return 1;
    }
}

void func_808004A4_chdragonbrothers(Actor *actor, s32 mode)
{
    u8 *data;
    f32 cam_pos[3];
    f32 cam_rot[3];
    f32 focus_pos[3];

    data = func_80100094(actor, 0);
    if (mode) {
        func_800F5A2C(*(s32 *) (data + 0x20), 5, focus_pos);
        func_800EE7F8(cam_pos, focus_pos);
        func_800EF334(cam_pos, 1.25f);
        cam_pos[1] += 375.0f;
        func_800A516C(cam_rot, focus_pos, cam_pos);
    } else {
        func_800F5A00(*(s32 *) (data + 0x20), cam_pos);
        func_800F1EA4(cam_pos, &cam_rot[1]);
        cam_rot[2] = 0.0f;
        cam_rot[0] = 0.0f;
        func_800EEC30(cam_pos, 0.0f, cam_rot[1], 4500.0f);
        cam_rot[1] = -cam_rot[1];
    }
    func_800A5240(cam_pos);
    func_800A526C(cam_rot);
    func_800A51C0();
    func_800A5240(cam_pos);
    func_800A526C(cam_rot);
}

void func_808005A4_chdragonbrothers(out, preset) f32 out[3];
s32 preset;
{
    switch (preset) {
        case 0:
            out[0] = 5500.0f;
            out[1] = -10.0f;
            out[2] = 1200.0f;
            return;
        case 1:
            out[0] = 4750.0f;
            out[1] = -5.0f;
            out[2] = 650.0f;
            return;
        case 2:
            out[0] = 4000.0f;
            out[1] = 0.0f;
            out[2] = 300.0f;
    }
}

f32 func_8080063C_chdragonbrothers(Actor *actor)
{
    f32 yaw;
    f32 offset;
    f32 len;
    f32 vec[3];

    yaw = ((f32 *) func_80100094(actor, 0))[6];
    offset = func_800F1DCC(yaw, ((f32 *) actor->actorData)[0]) * 20.0f;
    func_8008FFBC(vec);
    len = func_800EF030(vec);
    vec[1] = len;
    offset *= func_800F10B4(vec[1], 0.0f, 5000.0f, 0.0f, 1.0f);
    return yaw + offset;
}

void func_808006C8_chdragonbrothers(actor) Actor *actor;
{
    s32 i;
    Vec3f pos;
    f32 target_yaw;
    Vec3f cam_pos;
    Vec3f cam_look;
    u8 *data;
    f32 dt;
    f32 yaw_diff;
    data = func_80100094(actor, 0);
    dt = func_800D8FF8();
    if (actor->unk74_29) {
        func_800F5A00(*(s32 *) (data + 0x20), &pos);
        target_yaw = func_8080063C_chdragonbrothers(actor);
        yaw_diff = func_800F1DCC(target_yaw, *(f32 *) (data + 0x3C));
        *(f32 *) (data + 0x44) += (yaw_diff - *(f32 *) (data + 0x44)) * 0.085f;
        *(f32 *) (data + 0x40) += *(f32 *) (data + 0x44);
        if (!func_80016B54(0, 0) && func_80016B30(0, 3) == 1) {
            switch (data[0x55]) {
                case 2:
                    data[0x55] = 1;
                    func_800C3FC0(0x488, 1.0f, 12000);
                    break;
                case 1:
                    data[0x55] = 0;
                    func_800C3FC0(0x488, 1.0f, 12000);
                    break;
                case 0:
                    data[0x55] = 2;
                    func_800C3FC0(0x487, 1.0f, 12000);
            }
            func_808005A4_chdragonbrothers(data + 0x30, data[0x55]);
        }
        for (i = 0; i != 3; i++) {
            ((f32 *) (data + 0x24))[i] +=
                (((f32 *) (data + 0x30))[i] - ((f32 *) (data + 0x24))[i]) *
                dt * 5.0f;
        }
        func_800EFCD8(cam_pos.f, *(f32 *) (data + 0x40), *(f32 *) (data + 0x24));
        cam_pos.f[1] = *(f32 *) (data + 0x2C);
        cam_look.f[0] = *(f32 *) (data + 0x28);
        cam_look.f[1] = *(f32 *) (data + 0x40);
        cam_look.f[2] = 0.0f;
        _ncpod_entrypoint_8(func_80110024(func_800F5EF8(*(s32 *) (data + 0x20))), cam_pos.f,
                            cam_look.f);
        *(f32 *) (data + 0x3C) = target_yaw;
    }
}

void func_808008C8_chdragonbrothers(Actor *actor)
{
    DragonBrotherCamera *cam;
    f32 pos[3];

    cam = func_80100094(actor, 0);
    if (!actor->unk74_29) {
        func_800F5A00(cam->local_0, pos);
        cam->local_3 = cam->local_4 = func_800F1DF4(D_8080557C_chdragonbrothers, pos);
        cam->local_5 = 0.0f;
        cam->local_6 = 0.0f;
        func_808005A4_chdragonbrothers(cam->local_1, cam->local_7);
        func_808005A4_chdragonbrothers(cam->local_2, cam->local_7);
        _ncpod_entrypoint_16(func_800F5EF8((void *) cam->local_0), actor->unk0, 3, 0x804);
        actor->unk74_29 = 1;
        func_808006C8_chdragonbrothers(actor);
        func_800A5144();
    }
}

int func_8080098C_chdragonbrothers(s32 actor[3], s32 unk_1, s32 unk_2)
{
    Actor *data;
    u8 phase;

    data = func_80100094(actor, 0);
    phase = *(u8 *) ((char *) data + 0x5F);
    switch (phase) {
        case 0:
            func_80800438_chdragonbrothers(actor);
            _ncpod_entrypoint_16(func_800F5EF8(*(s32 *) ((char *) data + 0x20)), actor[0], 3,
                                 0);
        // fallthrough
        case 1:
            _ncpod_entrypoint_12(func_80110024(func_800F5EF8(*(s32 *) ((char *) data + 0x20))),
                                 1);
            *(u8 *) ((char *) data + 0x5F) = 2;
            _gcdialogcamera_entrypoint_6(actor[0]);
            _gcdialogcamera_entrypoint_8();
            _ncpod_entrypoint_25(func_80110024(func_800F5EF8(*(s32 *) ((char *) data + 0x20))),
                                 0);
        // fallthrough
        case 2:
            _ncpod_entrypoint_21(func_800F5EF8(*(s32 *) ((char *) data + 0x20)), unk_1,
                                 unk_2);
    }
}

void func_80800A80_chdragonbrothers(Actor *actor, s32 unk_1, s32 unk_2, s32 unk_3)
{
    Actor *data;

    data = func_80100094(actor, 0);
    switch (data->unk5F) {
        case 0:
            func_80800438_chdragonbrothers(actor);
            _ncpod_entrypoint_16(func_800F5EF8((void *) data->actorData[2]), actor->unk0, 3,
                                 0);
        // fallthrough
        case 2:
            data->unk5F = 1;
        // fallthrough
        case 1:
            _ncpod_entrypoint_20(func_800F5EF8((void *) data->actorData[2]), unk_3, unk_1,
                                 unk_2);
    }
}

void func_80800B34_chdragonbrothers(Actor *actor, s32 restart)
{
    DragonCameraState *state;

    state = func_80100094(actor, 0);
    if (state->active) {
        _ncpod_entrypoint_17(func_800F5EF8(state->player), 0);
        state->active = 0;
        if (restart) {
            func_808008C8_chdragonbrothers(actor);
        }
    }
}

void func_80800B9C_chdragonbrothers(Actor *data, s32 enable, s32 unk_2)
{
    if (enable) {
        if (!*((u8 *) data + 0x64))
            func_80090734(1, unk_2);
    } else {
        if (*((u8 *) data + 0x64))
            func_80090708(0);
    }
    *((u8 *) data + 0x64) = enable;
}

void func_80800C08_chdragonbrothers(Actor *actor)
{
    f32 progress;
    f32 pos[3];
    progress = func_80101F24(actor);
    if (progress < 0.1f || progress > 0.9f)
        return;
    if (!actor->unk7C_12)
        return;
    if (func_8001210C(7)) {
        _subaddieskeleton_entrypoint_2(actor->unk0, 4, pos);
        if (!(((u8 *) actor)[0x7A] & 1)) {
            pos[1] += 100.0f;
            func_800BBCB8(pos, 0, actor->scale, 1, D_80805588_chdragonbrothers);
            _subaddieaudioloop_entrypoint_4(actor, pos, 1, D_808055C0_chdragonbrothers);
        } else {
            pos[1] += 200.0f;
            func_800BBCB8(pos, 0, actor->scale, 1, D_808055DC_chdragonbrothers);
        }
    }
}

void func_80800D20_chdragonbrothers(u8 *actor, s16 dialog_id, u32 flags)
{
    u8 *brother_byte;
    u8 speaker;
    int offset;
    flags |= 6;
    offset = 0x7A;
    brother_byte = &actor[offset];
    if ((*brother_byte & 1) != 0U) {
        speaker = 0x75;
    } else {
        speaker = 0x76;
        // Matching: empty block steers IDO's register allocation.
        if ((dialog_id && dialog_id) && dialog_id) {
        }
    }
    func_800C05B8(dialog_id, flags, actor + 4, *(s32 *) actor, 0, 0, speaker);
    actor[0x74] |= 0x40;
}

void func_80800D98_chdragonbrothers(Actor *actor, s32 state)
{
    DragonData_80800D98_chdragonbrothers *data;
    s16 intro_dialog;
    s16 outro_dialog;

    data = func_80100094(actor, 0);
    if (data->unk10 == 4) {
        data->unk20 = _plsu_entrypoint_1(1);
    }
    data->unk10 = state;
    switch (state) {
        case 1:
            _gcfrontend_entrypoint_9(actor->unk7A_8 ? 0x29 : 0x2A);
            if (actor->unk7A_8) {
                if (!func_800DA9E4(0x1D3, 1)) {
                    if (func_800DA298(0x1D6)) {
                        intro_dialog = 0x129C;
                    } else if (func_800DA298(0x1D4)) {
                        intro_dialog = 0x129A;
                    } else {
                        intro_dialog = 0x1296;
                    }
                } else {
                    intro_dialog = 0x1298;
                }
            } else {
                if (!func_800DA9E4(0x1D4, 1)) {
                    if (func_800DA298(0x1D5)) {
                        intro_dialog = 0x129D;
                    } else if (func_800DA298(0x1D3)) {
                        intro_dialog = 0x129B;
                    } else {
                        intro_dialog = 0x1297;
                    }
                } else {
                    intro_dialog = 0x1299;
                }
            }
            if (intro_dialog) {
                func_80800D20_chdragonbrothers(actor, intro_dialog, 1);
            }
            break;
        case 5:
            data->unk58 = 3;
            func_80800B9C_chdragonbrothers(data, 1, actor->position);
            func_80800A80_chdragonbrothers(actor, 2, 0x420, 0);
            break;
        case 6:
            func_80800D20_chdragonbrothers(actor, actor->unk7A_8 ? 0x12A5 : 0x12A6, 1);
            func_8080098C_chdragonbrothers(actor, 2, 1);
            break;
        case 3:
            if (actor->unk7A_8) {
                if (func_800DA298(0x1D6)) {
                    func_800DA544(0x1D2);
                    outro_dialog = 0x12A3;
                } else {
                    outro_dialog = 0x12A1;
                }
            } else if (func_800DA298(0x1D5)) {
                func_800DA524(0x1D2);
                outro_dialog = 0x12A4;
            } else {
                outro_dialog = 0x12A2;
            }
            func_8080098C_chdragonbrothers(actor, 2, 1);
            func_80800D20_chdragonbrothers(actor, outro_dialog, 1);
            break;
        case 8:
            func_800FDC28(0);
            data->unk58 = 1;
            if (func_800D395C()) {
                func_80800A80_chdragonbrothers(actor, 0x14, 0x420, 0);
            } else {
                func_80800A80_chdragonbrothers(actor, 0x14, 0x400, 0);
            }
            break;
        case 11:
            actor->unk58 = 3.0f;
            break;
        case 12:
            func_80800A80_chdragonbrothers(actor, 0x1D, 0x430, 0);
            break;
        case 13:
            func_80800B9C_chdragonbrothers(data, 1, actor->position);
            func_80800D20_chdragonbrothers(actor, actor->unk7A_8 ? 0x12AE : 0x12AF, 1);
            break;
        case 14:
        case 15:
            data->unk5B++;
        case 16:
        case 17:
            actor->unk58 = 0.0f;
    }
}

s32 func_8080110C_chdragonbrothers(Actor *actor, f32 yaw, f32 target_yaw, s32 unk_3)
{
    s32 angle;

    for (angle = 0; angle != 360; angle += 90) {
        if (func_800F2094(angle, yaw) < 10.0f) {
            return 0;
        }
    }
    if (func_800F2094(target_yaw, yaw) < 5.0f) {
        return 0;
    }
    return 1;
}

f32 func_808011C0_chdragonbrothers(Actor *actor, s32 use_target)
{
    f32 target_yaw;
    f32 start_yaw;
    f32 step;
    f32 candidate;
    s32 done;

    target_yaw = *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x18);
    step = 1.0f;
    done = 0;
    start_yaw = use_target ? target_yaw : actor->rotation[1];
    do {
        if (!use_target) {
            candidate = start_yaw + step;
            if (func_8080110C_chdragonbrothers(actor, candidate, target_yaw, use_target)) {
                return candidate;
            }
        }
        candidate = start_yaw - step;
        if (func_8080110C_chdragonbrothers(actor, candidate, target_yaw, use_target)) {
            return candidate;
        }
        step += 1.0f;
    } while (!done);
    return start_yaw;
}

void func_808012B4_chdragonbrothers(actor, state) Actor *actor;
s32 state;
{
    DragonData_808012B4_chdragonbrothers *data;
    s32 flag;
    f32 delta[3];

    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 3:
        case 4:
            actor->unk64_16 = 1;
            break;
        case 5:
            func_80800B9C_chdragonbrothers(data, 0, actor->position);
            break;
        case 6:
            func_80800B9C_chdragonbrothers(data, 0, actor->position);
            func_80800000_chdragonbrothers(actor, 1);
            data->unk5A = 0;
            data->unk59 = 1;
            break;
        case 23:
            actor->unk64_20 = 0;
            break;
        case 15:
        case 20:
        case 21:
            data->unk5A = 0;
            break;
        case 16:
        case 17:
            data->unk54 = 0;
    }
    func_80102424(actor, state);
    switch (actor->unk70_10) {
        case 5:
            func_80800A80_chdragonbrothers(actor, 0, 0x420, 0);
            func_800FDC28(1);
            if (actor->unk7A_8) {
                if (!func_800DA298(0x1D3)) {
                    _chintrotext_entrypoint_1(0x18B9, 9, 1, 0);
                }
            } else if (!func_800DA298(0x1D4)) {
                _chintrotext_entrypoint_1(0x18B9, 10, 1, 0);
            }
            break;
        case 6:
            func_80800A80_chdragonbrothers(actor, 5, 0x420, 0);
            func_80800B9C_chdragonbrothers(data, 1, actor->position);
            func_80101EE4(actor, 0.5f);
            data->unk5A = 1;
            break;
        case 8:
            actor->unk79_4--;
            break;
        case 9:
            if (actor->unk64_19) {
                actor->unk58 = 0.0f;
            } else {
                actor->unk58 = 0.5f;
            }
            break;
        case 10:
            if (actor->unk64_19) {
                actor->unk58 = 1.0f;
            } else {
                actor->unk58 = 2.0f;
            }
            break;
        case 11:
            flag = actor->unk7A_8 ? 0x406 : 0x407;
            actor->unk6C_0 = 1;
            if (actor->unk64_19) {
                actor->unk58 = 1.5f;
            } else {
                actor->unk58 = 3.0f;
            }
            data->unk5D = 1;
            if (!func_800DA9E4(flag, 1)) {
                func_80800D98_chdragonbrothers(actor, 0xC);
            }
        case 12:
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_80805558_chdragonbrothers);
            break;
        case 14:
            func_8010A570(actor);
            func_80800000_chdragonbrothers(actor, 0);
            if (!func_800DA298(actor->unk7A_8 ? 0x404 : 0x405)) {
                func_80800B9C_chdragonbrothers(data, 1, actor->position);
                func_80800A80_chdragonbrothers(actor, 0xC, 0x420, 0);
            }
            actor->unk54 = func_808011C0_chdragonbrothers(actor, 1);
            data->unk5E = 0;
            break;
        case 16:
            actor->unk6C_0 = 0;
            func_8010A590(actor);
            ((f32 *) actor->actorData)[3] = 0.0f;
            data->unk54 = 1;
            break;
        case 17:
            if (actor->unk64_19) {
                ((f32 *) actor->actorData)[7] = 45.0f;
            } else {
                ((f32 *) actor->actorData)[7] = 30.0f;
            }
            ((f32 *) actor->actorData)[1] = 0.0f;
            if (func_800F1DCC(actor->rotation[1], data->unk18) < 0.0f) {
                func_80800D98_chdragonbrothers(actor, 0x10);
            } else {
                func_80800D98_chdragonbrothers(actor, 0xE);
            }
            data->unk5B = 0;
            data->unk54 = 1;
            break;
        case 19:
            func_8010A570(actor);
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_808053B0_chdragonbrothers);
            func_80800B9C_chdragonbrothers(data, 1, actor->position);
            func_80800A80_chdragonbrothers(actor, 9, 0x420, 0);
            func_800DA544(actor->unk7A_8 ? 0x1D5 : 0x1D6);
            func_80800000_chdragonbrothers(actor, 2);
            actor->unk54 = func_808011C0_chdragonbrothers(actor, 1);
            func_80800D98_chdragonbrothers(actor, 0xA);
            break;
        case 20:
            data->unk59 = 0;
            data->unk5A = 1;
            break;
        case 15:
        case 21:
            data->unk5A = 1;
            break;
        case 22:
            actor->unk64_20 = 1;
            actor->rotation[1] = 0.0f;
            func_80800A80_chdragonbrothers(actor, 0x18, 0x420, 0);
            break;
        case 23:
            func_80800D20_chdragonbrothers(actor, actor->unk7A_8 ? 0x12CA : 0x12CB, 1);
            delta[1] = 1500.0f;
            func_800EFCD8(delta, actor->rotation[1], -600.0f);
            func_800EF04C(actor->position, delta);
            func_80800D98_chdragonbrothers(actor, 7);
            break;
        case 2:
            actor->unk64_16 = 0;
    }
}

void func_8080183C_chdragonbrothers(Actor *actor)
{
    s8 *data;
    data = func_80100094(actor, 0);
    if (actor->unk64_19) {
        actor->unk79_4 = 3;
    } else {
        actor->unk79_4 = 3;
    }
    data[0x5E]++;
    func_8010A590(actor);
    func_808012B4_chdragonbrothers(actor, 8);
}

void func_808018BC_chdragonbrothers(Actor *actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    *(s32 *) (data + 0x14) = 0;
    if (actor->unk64_19) {
        actor->unk79_4 = 4;
    } else {
        actor->unk79_4 = 2;
    }
    func_808012B4_chdragonbrothers(actor, 14);
}

void func_80801924_chdragonbrothers(Actor *actor, Actor *egg)
{
    u8 *data;
    u32 hit_limit;

    data = func_80100094(actor, 0);
    if (actor->unk64_19) {
        hit_limit = 3;
    } else {
        hit_limit = 2;
    }
    if (actor->unk6C_0 < hit_limit) {
        (*(s32 *) (data + 0xC))--;
        (*(s32 *) (data + 0x14))++;
        if (*(s32 *) (data + 0xC) <= 0) {
            func_808012B4_chdragonbrothers(actor, 19);
            return;
        }
        data[egg->unk74_7 + 4]++;
        if ((data + 4)[egg->unk74_7] >= 3) {
            data[egg->unk74_7] = 2;
        }
        switch (actor->unk70_10) {
            case 8:
            case 9:
            case 10:
                func_808012B4_chdragonbrothers(actor, 11);
                break;
            case 11:
            case 12:
            case 13:
                actor->unk6C_0++;
                func_808012B4_chdragonbrothers(actor, 12);
        }
    }
}

void func_80801A4C_chdragonbrothers(Actor *actor, f32 turn)
{
    f32 dt;
    f32 max_speed;

    dt = func_800D8FF8();
    if (turn > 2.0f) {
        max_speed = turn * 15.5f;
        if (max_speed < actor->unk50) {
            actor->unk50 -= ((actor->unk50 - turn) * 0.006f) * 60.0f;
        } else {
            actor->unk50 += (turn * 0.015f) * 60.0f;
            if (max_speed < actor->unk50) {
                actor->unk50 = max_speed;
            }
        }
    } else if (turn < -2.0f) {
        max_speed = turn * 15.5f;
        if (actor->unk50 < max_speed) {
            actor->unk50 -= ((actor->unk50 - turn) * 0.006f) * 60.0f;
        } else {
            actor->unk50 += (turn * 0.015f) * 60.0f;
            if (actor->unk50 < max_speed) {
                actor->unk50 = max_speed;
            }
        }
    } else {
        actor->unk50 *= 0.9f;
    }
    if (actor->unk50 > 75.0f) {
        actor->unk50 = 75.0f;
    } else if (actor->unk50 < -75.0f) {
        actor->unk50 = -75.0f;
    }
    actor->rotation[1] += actor->unk50 * dt;
}

void func_80801C44_chdragonbrothers(Actor *actor, s32 offset)
{
    f32 yaw_diff;
    f32 base_yaw;
    f32 lead = 0.0f;
    DragonYaw1482 *data;

    data = func_80100094(actor, 0);
    base_yaw = data->local_0 + offset;
    if (!offset)
        lead = func_800F1DCC(base_yaw, ((f32 *) actor->actorData)[0]) * 10.0f;
    data->local_1 = base_yaw + lead;
    yaw_diff = func_800F1DCC(data->local_1, actor->rotation[1]);
    actor->unk54 = base_yaw;
    func_80801A4C_chdragonbrothers(actor, yaw_diff);
}

void func_80801CEC_chdragonbrothers(u8 *actor)
{
    func_80801A4C_chdragonbrothers(
        actor, func_800F1DCC(*(f32 *) (actor + 0x54), *(f32 *) (actor + 0x48)));
    func_80801A4C_chdragonbrothers(
        actor, func_800F1DCC(*(f32 *) (actor + 0x54), *(f32 *) (actor + 0x48)));
}

s32 func_80801D40_chdragonbrothers(Actor *actor, s32 msg, s32 msg_data)
{
    s8 *dragon_data;
    Actor *spawned;
    Vec3f spawn_offset;
    Actor *projectile;
    s32 player;
    s16 *msg_words;
    Vec3f spawn_pos;
    f32 yaw;

    dragon_data = func_80100094(actor, 0);
    switch (msg) {
        default:
            return 0;
        case 0x96:
            dragon_data[0x63] = 1;
            if (!func_800D395C()) {
                return 0;
            }
            func_80800D20_chdragonbrothers(actor, 0xCEB, 0x40);
            break;
        case 0x9F:
            func_800FDC28(0);
            dragon_data[0x59] = 0;
            if (func_80800438_chdragonbrothers(actor)) {
                func_808004A4_chdragonbrothers(actor, 1);
            }
            break;
        case 0x3D: {
            spawn_offset = D_80805608_chdragonbrothers;
            func_800EF934(spawn_offset.f, spawn_offset.f, actor->rotation[1]);
            spawned = func_80108528(0x379, spawn_offset.f, (s32) actor->rotation[1], &actor);
            spawned->unk64_19 = actor->unk64_19;
            spawned->unk3C = actor->unk0;
            break;
        }
        case 0x54: {
            projectile = func_80106790((Unk80132ED0 *) msg_data);
            if (*(s32 *) (dragon_data + 0xC) <= 0) {
                return 1;
            }
            (dragon_data + 8)[projectile->unk74_7]--;
            if ((projectile->unk79_4 == 2 && actor->unk7A_8) ||
                (projectile->unk79_4 == 3 && !actor->unk7A_8)) {
                func_80801924_chdragonbrothers(actor, projectile);
                return 1;
            }
            switch (actor->unk70_10) {
                case 8:
                case 9:
                case 10:
                case 13:
                    if (actor->unk7A_8) {
                        if (!func_800DA9E4(0x1D7, 1)) {
                            func_80800D20_chdragonbrothers(actor, 0x129E, 1);
                        }
                    } else {
                        if (!func_800DA9E4(0x1D8, 1)) {
                            func_80800D20_chdragonbrothers(actor, 0x129F, 1);
                        }
                    }
            }
            break;
        }
        case 0x3E: {
            if (!actor->unk64_16) {
                break;
            }
            if (((Unk80132ED0 *) msg_data)->unk24 >> 22) {
                break;
            }
            switch (actor->unk70_10) {
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                    player = func_800F54E4();
                    if (func_800F6438(player) && !func_800F6AA4(player) &&
                        func_800F6478(player)) {
                        func_800F7B9C(player, 0x51);
                    }
            }
            break;
        }
        case 0x2E: {
            msg_words = (s16 *) &msg_data;
            if (msg_words[0] == 0xCEB) {
                if (msg_words[1] == 1) {
                    _gcfrontend_entrypoint_11();
                } else {
                    _gcfrontend_entrypoint_10();
                }
                break;
            }
            switch (*(s32 *) (dragon_data + 0x10)) {
                case 7:
                    return 1;
                case 1:
                    switch (msg_words[0]) {
                        case 0x1296:
                        case 0x1297:
                        case 0x1298:
                        case 0x1299:
                        case 0x129A:
                        case 0x129B:
                        case 0x129C:
                        case 0x129D:
                            if (actor->unk7A_8) {
                                func_800FDC28(8);
                            } else {
                                func_800FDC28(9);
                            }
                            func_80800B34_chdragonbrothers(actor, 1);
                            func_808012B4_chdragonbrothers(actor, 10);
                            goto dialog_done;
                        default:
                            return 1;
                    }
                case 2:
                    return 1;
                case 3:
                    switch (msg_words[0]) {
                        case 0x12A1:
                        case 0x12A2:
                            func_808012B4_chdragonbrothers(actor, 0x16);
                        case 0x12A3:
                        case 0x12A4:
                            goto dialog_done;
                        default:
                            return 1;
                    }
                case 6:
                    if (msg_words[0] == 0x12A5 || msg_words[0] == 0x12A6) {
                        func_808012B4_chdragonbrothers(actor, 16);
                        func_80800B34_chdragonbrothers(actor, 1);
                        func_80800B9C_chdragonbrothers(dragon_data, 0, actor->position);
                    }
                    break;
                case 12:
                case 13:
                    if (msg_words[0] == 0x12AE || msg_words[0] == 0x12AF) {
                        func_80800B34_chdragonbrothers(actor, 1);
                        func_80800B9C_chdragonbrothers(dragon_data, 0, actor->position);
                        break;
                    }
                    return 1;
                default:
                    return 1;
            }
        dialog_done:
            func_80800D98_chdragonbrothers(actor, 0);
            actor->unk74_30 = 0;
            break;
        }
        case 0x2F: {
            msg_words = (s16 *) &msg_data;
            if (msg_words[1] != 1 || func_800D395C() || func_800D0A9C(0x3D, 1)) {
                break;
            }
            spawn_pos = D_80805614_chdragonbrothers;
            yaw = *(f32 *) (dragon_data + 0x18);
            if (func_800F2094(0.0f, yaw) < 10.0f) {
                func_800EEB9C(spawn_pos.f, (func_800DC298(0.5f) ? 4 : -4) + yaw, 3100.0f);
            }
            func_800D1000(0x3D, 1, spawn_pos.f, 1, actor->unk0);
            break;
        }
        case 0xD: {
            func_80800A80_chdragonbrothers(actor, 0x16, 0x400, func_80101080());
            break;
        }
        case 0xB:
            switch (msg_data) {
                case 0x1A:
                    func_80800D98_chdragonbrothers(actor, 8);
                    return 4;
                case 0x14:
                    if (func_800D395C()) {
                        _gcfrontend_entrypoint_10();
                    } else {
                        func_80800B34_chdragonbrothers(actor, 0);
                        func_80800B9C_chdragonbrothers(dragon_data, 0, actor->position);
                        func_808004A4_chdragonbrothers(actor, 1);
                    }
                    return 4;
                case 0x16:
                    func_808012B4_chdragonbrothers(actor, 0x16);
                    return 4;
                default:
                    return 3;
            }
        case 0x52:
            switch (actor->unk70_10) {
                case 15: {
                    f32 cam_pos[3];

                    func_800EE7F8(cam_pos, actor->position);
                    func_800EF1B8(cam_pos, actor->rotation[1], actor->scale * 650.0f);
                    _gcdialogcamera_entrypoint_3(D_80805620_chdragonbrothers, actor->scale);
                    _gcdialogcamera_entrypoint_4(cam_pos);
                    break;
                }
                case 19: {
                    f32 cam_pos[3];

                    func_800EE7F8(cam_pos, actor->position);
                    func_800EF1B8(cam_pos, actor->rotation[1], actor->scale * 600.0f);
                    _gcdialogcamera_entrypoint_3(D_80805630_chdragonbrothers, actor->scale);
                    _gcdialogcamera_entrypoint_4(cam_pos);
                    break;
                }
                default:
                    _gcdialogcamera_entrypoint_3(D_80805640_chdragonbrothers, actor->scale);
            }
    }
    return 1;
}

int func_80802534_chdragonbrothers(s32 actor)
{
    return func_80090248() && func_8008FA2C(-1, 0);
}

void func_80802574_chdragonbrothers(actor) Actor *actor;
{
    f32 dt;
    DragonUpdateData *data;
    f32 target_pos[3];
    f32 new_pos[3];
    f32 sound_pos[3];
    s32 hits_needed;
    f32 ramp_time;
    f32 loop_pos[3];
    f32 breath_pos[3];

    dt = func_800D8FF8();
    data = func_80100094(actor, 0);
    if ((s32) actor->unk70_10 >= 5 && data->field_63 == 0) {
        func_800F5A00(data->field_20, target_pos);
        func_800F1EA4(target_pos, &data->field_18);
        ((f32 *) actor->actorData)[0] = ((f32 *) actor->actorData)[2];
        ((f32 *) actor->actorData)[2] = data->field_18;
        if (data->field_61) {
            if (func_80090178(0x10000)) {
                if (data->field_62) {
                    data->field_62 = 0;
                    func_80800438_chdragonbrothers(actor);
                }
            } else if (data->field_62 == 0) {
                data->field_62 = 1;
                func_808008C8_chdragonbrothers(actor);
            }
        }
        switch (actor->unk70_10) {
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 16:
            case 17:
            case 18:
                if (target_pos[1] < -200.0f ||
                    (target_pos[1] < -10.0f && func_800EF030(target_pos) > 10824100.0f)) {
                    if (data->field_61) {
                        data->field_61 = 0;
                        func_80800438_chdragonbrothers(actor);
                        func_808004A4_chdragonbrothers(actor, 0);
                    }
                } else if (data->field_61 == 0) {
                    data->field_61 = 1;
                    func_808008C8_chdragonbrothers(actor);
                }
                break;
        }
    }

    if (actor->unk70_10 == 23) {
        func_800EFCD8(new_pos, actor->rotation[1], 1000.0f * dt);
        new_pos[1] = 800.0f * dt;
        func_800EF04C(actor->position, new_pos);
    } else {
        func_800EEB9C(actor->position, actor->rotation[1], 250.0f);
        actor->position[1] = -200.0f;
    }

    if (actor->unk7A_8) {
        if (data->field_5C == 2 && !func_800DA298(0x406)) {
            func_80800B9C_chdragonbrothers(data, 1, actor->position);
            data->field_5C = 10;
            func_800C067C(0x129E);
        }
    } else {
        if (data->field_5C == 3 && !func_800DA298(0x407)) {
            func_80800B9C_chdragonbrothers(data, 1, actor->position);
            data->field_5C = 10;
            func_800C067C(0x129F);
        }
    }

    switch (actor->unk70_10) {
        case 3:
            switch (data->field_10) {
                case 4:
                    if (func_8010CB0C(D_80805650_chdragonbrothers, 0x8FC, 10, -10) &&
                        func_8008FA2C(1, 0)) {
                        func_80800D98_chdragonbrothers(actor, 5);
                    }
                    break;
                case 5:
                    if (data->field_58 == 2) {
                        func_80800D98_chdragonbrothers(actor, 0);
                        func_808012B4_chdragonbrothers(actor, 5);
                    }
                    break;
            }
            break;
        case 4:
            if (data->field_10 == 4 &&
                func_8010CB0C(D_8080565C_chdragonbrothers, 0x8FC, 10, -10) && func_8008FA2C(1, 0)) {
                data->field_58 = 3;
                func_80800D98_chdragonbrothers(actor, 1);
                func_808012B4_chdragonbrothers(actor, 6);
            }
            break;
        case 5:
            if (func_80101DDC(actor)) {
                func_80800D98_chdragonbrothers(actor, 1);
                func_808012B4_chdragonbrothers(actor, 6);
            }
            func_80801C44_chdragonbrothers(actor, 0);
            break;
        case 6:
            if (func_80101E4C(actor, D_80805668_chdragonbrothers)) {
                if (actor->unk7C_12) {
                    _subaddieskeleton_entrypoint_2(actor->unk0, 4, sound_pos);
                } else {
                    func_800EE7F8(sound_pos, actor->position);
                }
                _subaddieaudioquick_entrypoint_2(actor, sound_pos, D_808053C8_chdragonbrothers);
            }
            break;
        case 7:
            if (func_800F2094(actor->rotation[1], data->field_18) < 10.0f) {
                func_8080183C_chdragonbrothers(actor);
            }
            func_80801C44_chdragonbrothers(actor, 0);
            break;
        case 8:
            func_80801C44_chdragonbrothers(actor, 0);
            if (func_80101E14(actor, 0.1f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808053E0_chdragonbrothers);
            } else if (func_80101E14(actor, 0.25f)) {
                func_80108B04(actor, 0);
            } else if (func_80101DDC(actor)) {
                if ((s32) actor->unk79_4 > 0) {
                    func_808012B4_chdragonbrothers(actor, 9);
                } else if (data->field_5D && data->field_5E == 3 && data->field_61) {
                    func_808018BC_chdragonbrothers(actor);
                } else {
                    func_808012B4_chdragonbrothers(actor, 10);
                }
            }
            break;
        case 9:
            if (actor->unk58 > 0.0f) {
                actor->unk58 -= func_800D8FF8();
            } else if (data->field_61 && data->field_63 == 0) {
                func_808012B4_chdragonbrothers(actor, 8);
            }
            func_80801C44_chdragonbrothers(actor, 0);
            break;
        case 10:
            if (actor->unk58 > 0.0f) {
                actor->unk58 -= func_800D8FF8();
            } else if (data->field_61 && data->field_63 == 0) {
                func_8080183C_chdragonbrothers(actor);
            }
            func_80801C44_chdragonbrothers(actor, 0);
            break;
        case 11:
        case 12:
            if (func_80101DDC(actor)) {
                if (data->field_10 == 12) {
                    func_80800D98_chdragonbrothers(actor, 13);
                }
                func_808012B4_chdragonbrothers(actor, 13);
            }
            if (data->field_10 == 0 && actor->unk58 > 0.0f) {
                actor->unk58 -= dt;
            }
            func_80801C44_chdragonbrothers(actor, 0);
            break;
        case 13:
            func_80801C44_chdragonbrothers(actor, 0);
            if (data->field_10 == 0) {
                hits_needed = actor->unk64_19 ? 3 : 2;
                if ((actor->unk6C_0 >= hits_needed || data->field_14 >= hits_needed) &&
                    (func_80802534_chdragonbrothers(actor) ||
                     func_800DA298(actor->unk7A_8 ? 0x404 : 0x405))) {
                    func_808018BC_chdragonbrothers(actor);
                    break;
                }
                if (actor->unk58 > 0.0f) {
                    actor->unk58 -= dt;
                } else if (data->field_60 > 0) {
                    func_80800000_chdragonbrothers(actor, 0);
                } else if (func_80802534_chdragonbrothers(actor) ||
                           func_800DA298(actor->unk7A_8 ? 0x404 : 0x405)) {
                    func_808018BC_chdragonbrothers(actor);
                }
            }
            break;
        case 14:
            if (func_80101DDC(actor)) {
                if (!func_800DA9E4(actor->unk7A_8 ? 0x404 : 0x405, 1)) {
                    func_808012B4_chdragonbrothers(actor, 15);
                    func_80800D98_chdragonbrothers(actor, 6);
                } else {
                    func_808012B4_chdragonbrothers(actor, 16);
                }
            }
            func_80801CEC_chdragonbrothers(actor);
            break;
        case 15:
            func_80801CEC_chdragonbrothers(actor);
            break;
        case 16:
            if (func_80101DDC(actor)) {
                func_808012B4_chdragonbrothers(actor, 17);
            }
            func_80801CEC_chdragonbrothers(actor);
            break;
        case 17:
            func_800EEB9C(loop_pos, actor->rotation[1], 2300.0f);
            _subaddieaudioloop_entrypoint_4(actor, loop_pos, 1, D_80805678_chdragonbrothers);
            actor->unk58 += dt;
            actor->unk54 = data->field_18;
            switch (data->field_10) {
                case 14:
                    ramp_time = actor->unk64_19 ? 0.6499938965f : 1.299987793f;
                    ((f32 *) actor->actorData)[3] = func_800F10B4(
                        actor->unk58, 0.0f, ramp_time, 0.0f, ((f32 *) actor->actorData)[7]);
                    if ((actor->unk64_19 ? 1.0f : 1.5f) < actor->unk58 &&
                        func_800F1DCC(actor->rotation[1], actor->unk54) <= 0.0f) {
                        func_80800D98_chdragonbrothers(actor, 15);
                    }
                    break;
                case 15:
                    ramp_time = actor->unk64_19 ? 0.4499969482f : 0.8499908447f;
                    ((f32 *) actor->actorData)[3] = func_800F10B4(
                        actor->unk58, 0.0f, ramp_time, ((f32 *) actor->actorData)[7], 0.0f);
                    if ((actor->unk64_19 ? 0.4499969482f : 0.8499908447f) < actor->unk58) {
                        func_80800D98_chdragonbrothers(actor, 16);
                    }
                    break;
                case 16:
                    ramp_time = actor->unk64_19 ? 0.6499938965f : 1.299987793f;
                    ((f32 *) actor->actorData)[3] = func_800F10B4(
                        actor->unk58, 0.0f, ramp_time, 0.0f, -((f32 *) actor->actorData)[7]);
                    if ((actor->unk64_19 ? 1.0f : 1.5f) < actor->unk58 &&
                        func_800F1DCC(actor->rotation[1], actor->unk54) >= 0.0f) {
                        func_80800D98_chdragonbrothers(actor, 17);
                    }
                    break;
                case 17:
                    ramp_time = actor->unk64_19 ? 0.4499969482f : 0.8499908447f;
                    ((f32 *) actor->actorData)[3] = func_800F10B4(
                        actor->unk58, 0.0f, ramp_time, -((f32 *) actor->actorData)[7], 0.0f);
                    if ((actor->unk64_19 ? 0.4499969482f : 0.8499908447f) < actor->unk58) {
                        func_80800D98_chdragonbrothers(actor, 14);
                    }
            }
            actor->rotation[1] -= ((f32 *) actor->actorData)[3] * dt;
            if ((actor->unk64_19 ? 4 : 2) < data->field_5B || data->field_63) {
                func_80800D98_chdragonbrothers(actor, 0);
                func_808012B4_chdragonbrothers(actor, 18);
            }
            break;
        case 18:
            func_80801C44_chdragonbrothers(actor, 0);
            if (func_80101E14(actor, 0.999f)) {
                func_808012B4_chdragonbrothers(actor, 7);
                func_80800000_chdragonbrothers(actor, 1);
            }
            break;
        case 19:
            func_80800C08_chdragonbrothers(actor);
            func_80801CEC_chdragonbrothers(actor);
            switch (data->field_10) {
                case 10:
                    if (func_80101E14(actor, 0.92f)) {
                        func_800EEB9C(breath_pos, actor->rotation[1], 3100.0f);
                        func_800E1610(2, 150.0f, 0.85f, breath_pos);
                        _subaddieaudioquick_entrypoint_2(actor, breath_pos,
                                                         D_80805410_chdragonbrothers);
                    } else if (func_80101DDC(actor)) {
                        func_80800D98_chdragonbrothers(actor, 3);
                    }
                    break;
                case 3:
                    if (actor->unk58 > 0.0f) {
                        actor->unk58 -= func_800D8FF8();
                    } else {
                        func_808012B4_chdragonbrothers(actor, 20);
                    }
            }
            break;
        case 20:
            if (func_80101DDC(actor)) {
                func_808012B4_chdragonbrothers(actor, 21);
            }
            break;
        case 22:
            if (func_80101E4C(actor, D_80805694_chdragonbrothers)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80805424_chdragonbrothers);
            }
            if (func_80101DDC(actor)) {
                func_808012B4_chdragonbrothers(actor, 23);
                func_80800A80_chdragonbrothers(actor, 0x1A, 0x420, 0);
            }
            break;
        case 23:
            _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                             D_80805424_chdragonbrothers, 0.1f);
            switch (data->field_10) {
                case 7:
                    break;
                case 8:
                    if (data->field_58 == 0) {
                        func_80800D98_chdragonbrothers(actor, 9);
                    }
                    break;
                case 9:
                    func_808012B4_chdragonbrothers(actor, 2);
                    func_80800D98_chdragonbrothers(actor, 0);
            }
    }

    if (data->field_5A == 0) {
        _suexpression_entrypoint_9(func_80100094(actor, 1));
    }
    _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
    func_808006C8_chdragonbrothers(actor);
    if (data->field_59 == 1) {
        func_800D2498(actor->unk7A_8 ? 0xF9 : 0xFA, data->field_C, 0);
    }
}

void func_808034DC_chdragonbrothers(actor, arg) Actor *actor;
s32 arg;
{
    if (actor->unk64_20) {
        func_800DF744(3, 1);
        func_800DF744(4, 1);
        func_800DF744(5, 1);
    } else {
        func_800DF744(3, 0);
        func_800DF744(4, 0);
        func_800DF744(5, 0);
    }
    func_80101870(actor, arg);
}

int chdragonbrothers_entrypoint_0()
{
    return (int) &D_808056A8_chdragonbrothers;
}

void func_80803574_chdragonbrothers(actor) Actor *actor;
{
    s32 unk_0;
    actor->unk74_7 = actor->unk74_7 - 50;

    func_800EE7F8(actor->actorData, actor->position);
    actor->position[1] = *(f32 *) ((u8 *) actor + 0x1C) - 310.0f;
    if (func_800EA05C() == 0x12B)
        ((B7A *) actor)->b0 = 0;
    else
        ((B7A *) actor)->b0 = 1;
    if ((((B7A *) actor)->b0 && func_800DA298(0x1D5)) ||
        (!((B7A *) actor)->b0 && func_800DA298(0x1D6))) {
        func_800FFAB0(actor);
        return;
    }
    *(Unk80132ED0 **) ((u8 *) actor + 0x3C) = _subaddiefind_entrypoint_2(0x377, 0)->unk0;
    func_800EFCD8(actor->position, (s32) actor->unk74_7 * 90, 2700.0f);
    actor->rotation[1] = (s32) actor->unk74_7 * 90;
}

void func_808036E4_chdragonbrothers(s32 unused)
{
}

void func_808036EC_chdragonbrothers(actor, state) Actor *actor;
s32 state;
{
    if (actor->unk70_10 == 4)
        func_8010A570(actor);
    func_80102424(actor, state);
    switch (actor->unk70_10) {
        case 2:
            *(f32 *) &actor->actorData[3] = 200.0f;
            break;
        case 4:
            func_8010A590(actor);
            break;
        case 5:
            actor->unk58 = 0.0f;
            break;
        case 8:
            *(f32 *) &actor->actorData[3] = 400.0f;
            break;
        case 9:
            *(f32 *) &actor->actorData[3] = 400.0f;
    }
}

void func_808037B0_chdragonbrothers(Actor *actor, s32 egg_id)
{
    Actor *dragon;
    s8 *dragon_data;

    // Matching: empty block steers IDO's register allocation.
    if (dragon) {
    }

    dragon = func_80106790(actor->unk3C);
    // Matching: empty blocks for IDO register allocation.
    if (1) {
    }
    dragon_data = func_80100094(dragon, 0);
    if (((DrbS *) dragon_data)->a[actor->unk74_7] + ((DrbS *) dragon_data)->b[actor->unk74_7] < 3) {
        if (actor->unk70_10 == 4 || actor->unk70_10 == 5) {
            if (func_808003F8_chdragonbrothers(dragon)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_8080543C_chdragonbrothers);
                actor->unk79_4 = egg_id - 0x26B;
                dragon_data[0x5C] = actor->unk79_4;
                func_808036EC_chdragonbrothers(actor, 5);
                ((DrbS *) dragon_data)->b[actor->unk74_7]++;
            }
        }
    }
}

void func_808038AC_chdragonbrothers(Actor *actor)
{
    f32 dt;
    f32 unk_0;
    char *dragon_data;
    f32 low_y;
    f32 mid_y;
    s32 dragon_cmd;

    dt = func_800D8FF8();

    dragon_data = (char *) func_80100094(func_80106790(*(void **) ((char *) actor + 0x3C)), 0);

    if (*(f32 *) ((char *) actor + 0x8) <= *(f32 *) ((char *) actor + 0x1C) - 450.0f) {
        *(u8 *) ((char *) actor + 0x65) &= ~1;
    } else {
        ((BitS101 *) actor)->b0 = 1;
    }

    if (*(f32 *) ((char *) actor + 0x8) <= *(f32 *) ((char *) actor + 0x1C) - 310.0f) {
        *(u8 *) ((char *) actor + 0x65) &= ~0x10;
    } else {
        ((BitS101 *) actor)->b4 = 1;
    }

    switch (((u32) *(u16 *) ((char *) actor + 0x72) >> 10)) {
        case 1:
            dragon_cmd = *(char *) ((s32) dragon_data + ((DbIdx76 *) actor)->idx);

            switch (dragon_cmd) {
                case 0:
                    break;
                case 2:
                    func_808036EC_chdragonbrothers(actor, 9);
                    break;
                case 1:
                    func_808036EC_chdragonbrothers(actor, 2);
            }
            break;

        case 2:
            if (*(f32 *) ((char *) actor + 0x8) < *(f32 *) ((char *) actor + 0x1C)) {
                *(f32 *) ((char *) actor + 0x8) += *(f32 *) ((char *) actor + 0x24) * dt;

                if ((*(f32 *) ((char *) actor + 0x1C) - 40.0f) <
                    *(f32 *) ((char *) actor + 0x8)) {
                    *(f32 *) ((char *) actor + 0x24) *= 1.0f - (3.5f * dt);
                }

                _subaddieaudioloop_entrypoint_4(actor, (char *) actor + 4, 1,
                                                D_808053A0_chdragonbrothers);
            } else {
                func_808036EC_chdragonbrothers(actor, 3);
            }
            break;

        case 3:
            if (func_80101DDC(actor)) {
                func_808036EC_chdragonbrothers(actor, 4);
            }
            break;

        case 4:
            dragon_cmd = *(char *) ((s32) dragon_data + ((DbIdx76 *) actor)->idx);

            switch (dragon_cmd) {
                case 2:
                    func_808036EC_chdragonbrothers(actor, 9);
                    break;
                case 0:
                    func_808036EC_chdragonbrothers(actor, 6);
            }
            break;

        case 5:
            if (func_80101E14(actor, 0.5f)) {
                if (((W7C *) actor)->f) {
                    func_80108B04(actor, ((Nib79 *) actor)->hi);
                }
            }

            if (func_80101DDC(actor)) {
                if (*(f32 *) ((char *) actor + 0x58) > 0.0f) {
                    *(f32 *) ((char *) actor + 0x58) -= func_800D8FF8();
                } else {
                    func_808036EC_chdragonbrothers(actor, 4);
                }
            }
            break;

        case 6:
        case 7:
            if (func_80101DDC(actor)) {
                dragon_cmd = *(char *) ((s32) dragon_data + ((DbIdx76 *) actor)->idx);

                switch (dragon_cmd) {
                    case 2:
                        func_808036EC_chdragonbrothers(actor, 9);
                        break;
                    case 0:
                        func_808036EC_chdragonbrothers(actor, 8);
                }
            }
            break;

        case 8:
            mid_y = *(f32 *) ((char *) actor + 0x1C) - 310.0f;

            if (mid_y < *(f32 *) ((char *) actor + 0x8)) {
                *(f32 *) ((char *) actor + 0x8) -= *(f32 *) ((char *) actor + 0x24) * dt;

                if ((*(f32 *) ((char *) actor + 0x1C) - 75.0f) <
                    *(f32 *) ((char *) actor + 0x8)) {
                    *(f32 *) ((char *) actor + 0x24) *= 1.0f + (1.5f * dt);

                    // Matching: ^ 0 forces a fresh base, so IDO reloads 0x1C instead of reusing the compare load.
                    mid_y = *(f32 *) ((char *) ((s32) actor ^ 0) + 0x1C) - 310.f;
                }

                if (*(f32 *) ((char *) actor + 0x8) < mid_y) {
                    *(f32 *) ((char *) actor + 0x8) = mid_y;
                }

                _subaddieaudioloop_entrypoint_4(actor, (char *) actor + 4, 1,
                                                D_808053A0_chdragonbrothers);
            }

            dragon_cmd = *(char *) ((s32) dragon_data + ((DbIdx76 *) actor)->idx);

            switch (dragon_cmd) {
                case 2:
                    func_808036EC_chdragonbrothers(actor, 9);
                    break;
                case 1:
                    func_808036EC_chdragonbrothers(actor, 2);
            }
            break;

        case 9:
            // Matching: this case uses its own local so 450.0f stays in f14.
            low_y = *(f32 *) ((char *) actor + 0x1C) - 450.0f;

            if (low_y < *(f32 *) ((char *) actor + 0x8)) {
                *(f32 *) ((char *) actor + 0x8) -= *(f32 *) ((char *) actor + 0x24) * dt;

                if ((low_y - 150.0f) < *(f32 *) ((char *) actor + 0x8)) {
                    *(f32 *) ((char *) actor + 0x24) *= 1.0f + (1.5f * dt);

                    // Matching: reuses the local so 450.0f stays in f14.
                    low_y = *(f32 *) ((char *) actor + 0x1C) - 450.f;
                }

                if (*(f32 *) ((char *) actor + 0x8) < low_y) {
                    *(f32 *) ((char *) actor + 0x8) = low_y;
                }

                _subaddieaudioloop_entrypoint_4(actor, (char *) actor + 4, 1,
                                                D_808053A0_chdragonbrothers);
            }

            dragon_cmd = *(char *) ((s32) dragon_data + ((DbIdx76 *) actor)->idx);

            switch (dragon_cmd) {
                case 1:
                    func_808036EC_chdragonbrothers(actor, 2);
                    break;
                case 0:
                    func_808036EC_chdragonbrothers(actor, 6);
            }
    }
}

s32 func_80803DC4_chdragonbrothers(actor, msg, msg_data)
Actor *actor;
s32 msg;
s32 msg_data;
{
    Actor *egg;
    Vec3f spawn_offset;
    Unk80132ED0 *player_egg;

    switch (msg) {
        case 0x3D:
            spawn_offset = D_80805740_chdragonbrothers;
            func_800EF934(spawn_offset.f, spawn_offset.f, actor->rotation[1]);
            egg = func_801084B0(0x37A, &actor);
            egg->rotation[0] = 153.5f;
            egg->unk50 = 63.5f;
            egg->unk79_4 = actor->unk79_4;
            egg->unk74_7 = actor->unk74_7;
            func_800EE780(egg->position, actor->position, spawn_offset.f);
            return 1;
        case 0x3E:
            player_egg = (Unk80132ED0 *) *(s32 *) &msg_data;
            if (_sueggmisc_entrypoint_0(player_egg)) {
                func_8010114C(player_egg, 0x2C, 0);
                func_808037B0_chdragonbrothers(actor, player_egg->unk24 >> 22);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_80803EFC_chdragonbrothers(s32 actor, volatile int arg)
{
    func_800DF744(1, (u32) (*(s32 *) ((char *) actor + 0x64) << 0xb) >> 0x1F);
    func_80101870(actor, arg);
}

int chdragonbrothers_entrypoint_1()
{
    return (int) &D_8080574C_chdragonbrothers;
}

void func_80803F4C_chdragonbrothers(Actor *actor)
{
    Actor *dragon = func_80106790(actor->unk3C);
    u8 *dragon_data = func_80100094(dragon, 0);
    f32 target_pos[3];

    actor->unk74_7 = actor->unk74_7 - 0x32;
    func_800F5A00(*(s32 *) (dragon_data + 0x20), target_pos);
    target_pos[1] += 30.0f;
    actor->rotation[0] = func_800F1828(actor->position, target_pos);
    func_800EEBF0((f32 *) &actor->actorData[4], actor->rotation,
                  actor->unk64_19 ? 6000.0f : 4000.0f);
    if (func_800EA05C() == 0x12B)
        actor->unk7A_8 = 0;
    else
        actor->unk7A_8 = 1;
    if (actor->unk7A_8)
        func_801032B0(actor, 0x814, *(u16 *) ((u8 *) actor->unk0 + 0x16));
    *(f32 *) &actor->actorData[0] = func_800DC178(50.0f, 100.0f);
    *(f32 *) &actor->actorData[1] = func_800DC178(5.0f, 10.0f);
    *(f32 *) &actor->actorData[2] = func_800DC178(5.0f, 10.0f);
}

void func_808040A0_chdragonbrothers(s32 unused)
{
}

void func_808040A8_chdragonbrothers(u8 *actor)
{
    f32 dt;
    s32 hit;
    s32 step[3];
    s32 next_pos[3];
    s32 unk_0[3];
    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }

    dt = func_800D8FF8();
    *(f32 *) (actor + 0x58) = *(f32 *) (actor + 0x58) + dt;
    if (((Actor *) actor)->unk70_10 == 1) {
        func_800EFA20(step, actor + 0x28, dt);
        func_800EE780(next_pos, actor + 4, step);
        hit = func_800C6A7C(actor + 4, next_pos, unk_0, 0x20020);
        func_800EE7F8(actor + 4, next_pos);
        if (hit != 0) {
            _chexploder_entrypoint_3(actor, next_pos, 8);
            func_800E1610(2, 100.0f, 0.85f, next_pos);
            if (actor[0x7A] & 1) {
                _subaddieaudioquick_entrypoint_2(actor, 0, D_80805794_chdragonbrothers);
            } else {
                _subaddieaudioquick_entrypoint_2(actor, actor + 4, D_80805448_chdragonbrothers);
            }
        } else {
            if (*(f32 *) (actor + 8) < -400.0f) {
                _subaddiefade_entrypoint_3(actor);
            }
        }
        func_800EFA20(next_pos, actor + 0x18, dt);
        func_800EF04C(actor + 0x44, actor + 0x18);
        if (0.25f < *(f32 *) (actor + 0x58)) {
            if (!(actor[0x7A] & 1)) {
                func_800BBCB8(actor + 4, 0, *(f32 *) (actor + 0x38), 1,
                              D_808057A8_chdragonbrothers);
                if (!((Actor *) actor)->unk64_20) {
                    if (0.3f < *(f32 *) (actor + 0x58)) {
                        _subaddieaudioquick_entrypoint_2(actor, actor + 4,
                                                         D_80805460_chdragonbrothers);
                        ((Actor *) actor)->unk64_20 = 1;
                    }
                }
            } else {
                func_800BBCB8(actor + 4, 0, *(f32 *) (actor + 0x38), 1,
                              D_808057E0_chdragonbrothers);
                func_800BBCB8(actor + 4, 0, *(f32 *) (actor + 0x38), 2,
                              D_80805810_chdragonbrothers);
                if (!((Actor *) actor)->unk64_20) {
                    if (0.3f < *(f32 *) (actor + 0x58)) {
                        _subaddieaudioquick_entrypoint_2(actor, actor + 4,
                                                         D_80805474_chdragonbrothers);
                        ((Actor *) actor)->unk64_20 = 1;
                    }
                }
            }
        }
    }
}

s32 func_80804318_chdragonbrothers(s32 actor, s32 arg)
{
    func_800DF744(1, 1);
    func_80101870(actor, arg);
}

s32 func_80804350_chdragonbrothers(Actor *actor, s32 msg, DragonMessage1804 msg_data)
{
    Actor *parent;

    switch (msg) {
        case 15:
        case 0x90:
            parent = func_80106790(func_80101080());
            _chexploder_entrypoint_9(parent, 1, 2);
            _chexploder_entrypoint_13(parent, 6);
            if (((u8 *) actor)[0x7A] & 1)
                _chexploder_entrypoint_15(parent, 2, 1.0f);
            else
                _chexploder_entrypoint_15(parent, 4, 1.0f);
            if (((u8 *) actor)[0x7A] & 1)
                func_800BBCB8(actor->position, actor->position, actor->scale, 6,
                              D_80805840_chdragonbrothers);
            else
                func_800BBCB8(actor->position, actor->position, actor->scale, 6,
                              D_80805870_chdragonbrothers);
            break;
        case 0x3E:
            if (msg_data.local_1->unk24 >> 22 == 0)
                func_800F7B9C(func_800F54E4(), 0x51);
            break;
        default:
            return 0;
    }
    return 1;
}

void *chdragonbrothers_entrypoint_2(void)
{
    return &D_808058A8_chdragonbrothers;
}

void func_8080449C_chdragonbrothers(Actor *actor)
{
    Actor *dragon;
    u8 *state;
    u8 *dragon_state;
    state = func_80100094(actor, 0);
    func_800EEBF0((f32 *) ((u8 *) actor + 0x28), actor->rotation, 2500.0f);
    *(f32 *) ((u8 *) actor + 0x58) = 0.5f;
    func_8010A590(actor);
    ((DragonMarker1864 *) actor->unk0)->local_0 = 1;
    dragon = _subaddiefind_entrypoint_2(0x377, 0);
    dragon_state = func_80100094(dragon, 0);
    *(Unk80132ED0 **) ((u8 *) actor + 0x3C) = dragon->unk0;
    if (func_800EA05C() == 0x12B)
        actor->unk7A_8 = 0;
    else
        actor->unk7A_8 = 1;
    *(s16 *) ((u8 *) actor->unk0 + 0x14) = D_808058F0_chdragonbrothers[actor->unk79_4];
    *(f32 *) ((u8 *) actor + 0x18) = func_800DC178(50.0f, 100.0f);
    *(f32 *) ((u8 *) actor + 0x1C) = func_800DC178(5.0f, 10.0f);
    *(f32 *) ((u8 *) actor + 0x20) = func_800DC178(5.0f, 10.0f);
    *(f32 *) (state + 4) = 0.0f;
    *(s32 *) (state + 0xC) = func_800AF5A0(func_800EC3E8(actor->unk0));
    actor->unk64_20 = 1;
    actor->scale = 1.5f;
    (*(s8 *) (dragon_state + 0x60))++;
}

// Advances the frame counter of the model.
void func_80804610_chdragonbrothers(Actor *actor)
{
    DragonFrameState *frame_state;

    frame_state = func_80100094(actor, 0);
    frame_state->local_0 =
        func_800F13C4(func_800D8FF8() * 30.0f + frame_state->local_0, (f32) frame_state->local_1);
    ((DragonFrameModel *) actor->unk0->unk0)->local_0 = (s32) frame_state->local_0 % frame_state->local_1;
}

void func_808046CC_chdragonbrothers(actor) Actor *actor;
{
    u8 *state;
    Vec3f pos;
    f32 interval;
    s32 trail;
    Vec3f velocity;

    state = func_80100094(actor, 0);
    *(f32 *) (state + 0x10) -= func_800D8FF8();
    interval = func_800F10B4(*(f32 *) (state + 8), 0.0, 2.0f, 0.03330000117f, 0.1f);
    while (*(f32 *) (state + 0x10) <= 0.0f) {
        *(f32 *) (state + 0x10) += interval;
        trail = 0;
        func_800EE7F8(pos.f, actor->position);
        switch (actor->unk79_4) {
            case 1:
            case 3:
            case 5:
                if (func_800DC0C0() < 0.5f) {
                    trail = _fxegg_entrypoint_2(pos.f, actor->scale);
                } else {
                    trail = _fxegg_entrypoint_1(pos.f, actor->scale);
                }
                break;
            case 7:
                func_800EFA20(velocity.f, (f32 *) &actor->actorData[4], 0.5f);
                trail = _fxegg_entrypoint_6(actor->position, actor->scale, velocity.f);
                break;
            case 4:
                trail = _fxegg_entrypoint_5(actor->position, (f32 *) &actor->actorData[4],
                                              actor->scale);
        }
        if (trail != 0) {
            func_800BA5A8(trail, 0x200);
        }
    }
    if (actor->unk79_4 == 2 && !func_8001210C(1)) {
        _fxegg_entrypoint_3(actor->position, actor->scale);
    }
}

void func_808048A4_chdragonbrothers(s32 arg0)
{
}

s32 func_808048AC_chdragonbrothers(actor)
Actor *actor;
{
    f32 hit_pos[3];
    f32 delta[3];
    Actor *dragon;
    u8 *dragon_state;

    if (_subaddiecustomhits_entrypoint_2(actor->unk3C, actor->position, 90.0f, hit_pos, 0)) {
        dragon = func_80106790(actor->unk3C);
        dragon_state = func_80100094(dragon, 0);
        func_800EE780(delta, actor->position, (f32 *) ((u8 *) actor + 0x28));
        func_808049D4_chdragonbrothers((u8 *) actor);
        actor->unk64_20 = 0;
        (*(s8 *) (dragon_state + 0x60))--;
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80805900_chdragonbrothers);
        func_800FFAB0(actor);
        switch (dragon->unk70_10) {
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
                func_8010114C(actor->unk3C, 0x54, actor->unk0);
                return 1;
            default:
                if (*(s8 *) (dragon_state + 8 + actor->unk74_7) > 0) {
                    (*(s8 *) (dragon_state + 8 + actor->unk74_7))--;
                }
                return 1;
        }
    }
    return 0;
}

void func_808049D4_chdragonbrothers(u8 *actor)
{
    u8 flags;
    u8 *pos = actor + 4;
    int egg_type;
    flags = actor[121];
    if (((flags & 0xFFu) >> 4) == 4) {
        func_800BABB8(0, pos, 0, *(s32 *) (actor + 0x38), &D_80805918_chdragonbrothers);
        func_800BABB8(0, pos, 0, *(s32 *) (actor + 0x38), &D_80805960_chdragonbrothers);
        func_800BABB8(0, pos, 0, *(s32 *) (actor + 0x38), &D_808059A8_chdragonbrothers);
        func_8010D930(6, -1, pos, &D_808059D8_chdragonbrothers);
        return;
    }
    do {
    } while (0);
    egg_type = (flags & 0xFFu) >> 4;
    _fxegg_entrypoint_0(egg_type, pos, *(s32 *) (actor + 0x38), (flags & 0xFFu) >> 4);
}

void func_80804AA4_chdragonbrothers(Actor *actor)
{
    u8 *state;
    f32 dt;
    f32 *pos;
    f32 step[3];
    f32 next_pos[3];
    f32 hit_normal[3];
    f32 *data_vec;

    state = func_80100094(actor, 0);
    dt = func_800D8FF8();
    *(f32 *) (state + 8) += dt;
    if (actor->unk70_10 != 1)
        return;
    if (!(actor->unk58 > 0.0f) && func_808048AC_chdragonbrothers(actor))
        return;
    {
        data_vec = (f32 *) actor->actorData;
        pos = actor->position;
        func_800EE7F8(data_vec, pos);
        func_800EFA20(step, (f32 *) &actor->actorData[4], dt);
        func_800EE780(next_pos, pos, step);
        *(f32 *) &actor->actorData[5] -= 25.0f;
        if (actor->unk58 > 0.0f) {
            actor->unk58 -= dt;
        } else if (func_800C6A7C(pos, next_pos, hit_normal, 0x20020)) {
            func_808049D4_chdragonbrothers(actor);
            func_800FFAB0(actor);
        }
        func_800EE7F8(pos, next_pos);
        func_800EFA20(next_pos, data_vec, dt);
        func_800EF04C(actor->rotation, data_vec);
    }
    func_80804610_chdragonbrothers(actor);
    func_808046CC_chdragonbrothers(actor);
    if (actor->unk79_4 == 2) {
        _subaddieaudioloop_entrypoint_4(actor, pos, 1, D_808059EC_chdragonbrothers);
    }
    if (actor->position[1] < -1000.0f) {
        state = func_80100094(func_80106790(actor->unk3C), 0);
        actor->unk64_20 = 0;
        (*(s8 *) (state + 0x60))--;
        _subaddiefade_entrypoint_3(actor);
    }
}

s32 func_80804C6C_chdragonbrothers(s32 param_0, s32 msg, s32 param_2)
{
    if (msg != 0xF)
        return FALSE;
    return TRUE;
}

s32 func_80804C90_chdragonbrothers(s32 param_0, s32 param_1)
{
    func_800E24D8(1);
    _subaddiedraw25d_entrypoint_2(param_0, param_1);
}

s32 chdragonbrothers_entrypoint_3()
{
    return D_80805A08_chdragonbrothers;
}

void func_80804CD0_chdragonbrothers(Actor *actor)
{
    func_800EFA4C(actor->position, 0.0f, -500.0f, 3150.0f);
    actor->rotation[2] = 180.0f;
    actor->scale = 1.68f;
    if (func_800EA05C() == 0x12B)
        actor->unk7A_8 = 0;
    else
        actor->unk7A_8 = 1;
    if ((actor->unk7A_8 && !func_800DA298(0x1D5)) ||
        (!actor->unk7A_8 && !func_800DA298(0x1D6))) {
        actor->unk3C = _subaddiefind_entrypoint_2(0x377, NULL)->unk0;
        func_80103110(actor, 1);
    }
}

void func_80804DB0_chdragonbrothers(s32 arg0)
{
}

void func_80804DB8_chdragonbrothers(actor, state) Actor *actor;
s32 state;
{
    switch ((*(Actor **) &actor)->unk70_10) {
        case 1:
            break;
        case 2:
        case 4:
            _subaddieaudioquick_entrypoint_2(actor, &D_80805A50_chdragonbrothers,
                                             &D_80805488_chdragonbrothers);
    }
    func_80101FDC(actor, state);
}

void func_80804E1C_chdragonbrothers(Actor *actor)
{
    Actor *boss;
    u8 *boss_state;
    f32 dt;
    dt = func_800D8FF8();
    if (actor->unk3C) {
        boss = func_80106790(actor->unk3C);
        boss_state = func_80100094(boss, 0);
        switch ((s32) actor->unk70_10) {
            case 1:
                if (boss_state[0x58] == 1) {
                    func_80804DB8_chdragonbrothers(actor, 2, boss_state);
                }
                break;
            case 2:
                if (actor->position[1] > -500.0f) {
                    actor->position[1] -= 150.0f * dt;
                    _subaddieaudioloop_entrypoint_4(actor, (s32 *) &D_80805A50_chdragonbrothers,
                                                    1, &D_808053A0_chdragonbrothers);
                } else {
                    func_80804DB8_chdragonbrothers(actor, 3, boss_state);
                    boss_state[0x58] = 0;
                }
                break;
            case 3:
                if (boss_state[0x58] == 3) {
                    func_80804DB8_chdragonbrothers(actor, 4, boss_state);
                }
                break;
            case 4:
                if (actor->position[1] < -200.0f) {
                    actor->position[1] += 150.0f * dt;
                    _subaddieaudioloop_entrypoint_4(actor, (s32 *) &D_80805A50_chdragonbrothers,
                                                    1, &D_808053A0_chdragonbrothers);
                } else {
                    func_80804DB8_chdragonbrothers(actor, 1, boss_state);
                    boss_state[0x58] = 2;
                }
        }
    }
}

int chdragonbrothers_entrypoint_4()
{
    return (int) &D_80805A5C_chdragonbrothers;
}

extern void func_80108ED0();
extern int func_80101870();
u8 D_808053A0_chdragonbrothers[16] = {0x0, 0x13, 0x4, 0xAD, 0x0,  0x16, 0x46, 0x50,
                                      0x0, 0x1,  0x7, 0xD0, 0x13, 0x88, 0x0,  0x0};
u32 D_808053B0_chdragonbrothers[6] = {0x130605, 0xD00F3, 0x10C0016, 0x7FFF0001, 0x1F402710, 0x0};
u8 D_808053C8_chdragonbrothers[24] = {0x0,  0x13, 0x6,  0x30, 0x0,  0xD,  0x0, 0xF3,
                                      0x1,  0xC,  0x0,  0x16, 0x5D, 0xC0, 0x0, 0x1,
                                      0x1F, 0x40, 0x27, 0x10, 0x0,  0x0,  0x0, 0x0};
u8 D_808053E0_chdragonbrothers[48] = {
    0x0,  0x13, 0x6,  0x0,  0x0,  0xD,  0x0, 0xF3, 0x1,  0xC,  0x0,  0x16, 0x5D, 0xC0, 0x0, 0x1,
    0x13, 0x88, 0x27, 0x10, 0x0,  0x0,  0x0, 0x0,  0x0,  0x13, 0x4,  0x9E, 0x0,  0xD,  0x0, 0xF3,
    0x1,  0xC,  0x0,  0x16, 0x46, 0x50, 0x0, 0x1,  0x13, 0x88, 0x1D, 0x4C, 0x0,  0x0,  0x0, 0x0};
u8 D_80805410_chdragonbrothers[20] = {0x0,  0x13, 0x4, 0x16, 0x0,  0xA,  0x0,  0xC0, 0x0, 0x16,
                                      0x5D, 0xC0, 0x0, 0x1,  0x1F, 0x40, 0x27, 0x10, 0x0, 0x0};
u8 D_80805424_chdragonbrothers[24] = {0x0, 0x13, 0x3,  0xFF, 0x0,  0xD,  0x0,  0xCC,
                                      0x0, 0xE6, 0x0,  0x19, 0x46, 0x50, 0x5D, 0xC0,
                                      0x0, 0x1,  0x13, 0x88, 0x27, 0x10, 0x0,  0x0};
u8 D_8080543C_chdragonbrothers[12] = {0x0, 0x13, 0x6, 0x86, 0x0, 0x18,
                                      0x0, 0x2,  0x0, 0x0,  0x0, 0x0};
u8 D_80805448_chdragonbrothers[24] = {0x0,  0x13, 0x4,  0x13, 0x0,  0xD,  0x0, 0xF3,
                                      0x1,  0xC,  0x0,  0x16, 0x6D, 0x60, 0x0, 0x1,
                                      0x27, 0x10, 0x3A, 0x98, 0x0,  0x0,  0x0, 0x0};
u8 D_80805460_chdragonbrothers[20] = {0x0, 0x13, 0x6, 0x1, 0x0,  0xD,  0x0,  0xF3, 0x1, 0xC,
                                      0x0, 0x18, 0x0, 0x1, 0x13, 0x88, 0x27, 0x10, 0x0, 0x0};
u8 D_80805474_chdragonbrothers[20] = {0x0, 0x13, 0x6, 0x3, 0x0,  0xD,  0x0,  0xF3, 0x1, 0xC,
                                      0x0, 0x18, 0x0, 0x1, 0x13, 0x88, 0x27, 0x10, 0x0, 0x0};
int D_80805488_chdragonbrothers[4] = {0x1304CC, 0x162EE0, 0x109C4, 0x13880000};
u8 D_80805498_chdragonbrothers[192] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x41, 0x40, 0x0,  0x0,  0x4, 0xB6, 0x0, 0x1,
    0x41, 0x40, 0x0,  0x0,  0x4, 0xB6, 0x0, 0x1,  0x3F, 0x80, 0x0,  0x0,  0x3, 0x44, 0x0, 0x44,
    0x41, 0x40, 0x0,  0x0,  0x4, 0xB6, 0x0, 0x1,  0x40, 0xA4, 0x0,  0x0,  0x3, 0x44, 0x0, 0x42,
    0x41, 0x40, 0x0,  0x0,  0x4, 0xB6, 0x0, 0x1,  0x3F, 0x95, 0x60, 0x42, 0x3, 0x5C, 0x0, 0x41,
    0x3F, 0xA5, 0x3F, 0x7D, 0x3, 0x34, 0x0, 0x42, 0x3F, 0x95, 0x60, 0x42, 0x3, 0x5C, 0x0, 0x41,
    0x3F, 0x95, 0x60, 0x42, 0x3, 0x5C, 0x0, 0x41, 0x3F, 0x55, 0x3F, 0x7D, 0x3, 0x35, 0x0, 0x42,
    0x3F, 0x55, 0x3F, 0x7D, 0x3, 0x35, 0x0, 0x2,  0x3F, 0x55, 0x3F, 0x7D, 0x3, 0x36, 0x0, 0x41,
    0x3F, 0x85, 0x1E, 0xB8, 0x3, 0x42, 0x0, 0x42, 0x41, 0x40, 0x0,  0x0,  0x3, 0x46, 0x0, 0x41,
    0x3F, 0xA8, 0x72, 0xB0, 0x3, 0x43, 0x0, 0x42, 0x3F, 0x28, 0xF5, 0xC3, 0x3, 0x37, 0x0, 0x41,
    0x3F, 0x11, 0xEB, 0x85, 0x3, 0x47, 0x0, 0x42, 0x40, 0x4E, 0xB8, 0x52, 0x3, 0x51, 0x0, 0x42,
    0x41, 0x34, 0xCC, 0xCD, 0x3, 0x52, 0x0, 0x42, 0x41, 0x1A, 0xB8, 0x52, 0x3, 0x53, 0x0, 0x41,
    0x40, 0x40, 0x0,  0x0,  0x3, 0x5F, 0x0, 0x42, 0x3F, 0x7,  0xAE, 0x14, 0x3, 0x38, 0x2, 0x41};
u32 D_80805558_chdragonbrothers[6] = {0x130604, 0xD00F3, 0x10C0016, 0x7FFF0001, 0x1F402710, 0x0};
f32 D_80805570_chdragonbrothers[3] = {0.0f, 0.0f, 3.1e+03f};
f32 D_8080557C_chdragonbrothers[3] = {0.0f, 2.5e+02f, 0.0f};
u8 D_80805588_chdragonbrothers[56] = {
    0x0, 0x1D, 0x9, 0xCE, 0x0,  0x16, 0x12, 0x0,  0x0, 0x32, 0x0, 0x2,  0x0, 0x15,
    0x0, 0x0,  0x0, 0x99, 0x0,  0x22, 0x1,  0x99, 0x2, 0x0,  0x1, 0x33, 0x1, 0x99,
    0x0, 0x2B, 0x0, 0xA6, 0x0,  0xA6, 0x0,  0x1B, 0x1, 0x2C, 0x2, 0x58, 0x0, 0x18,
    0x0, 0x0,  0x0, 0x0,  0x19, 0x0,  0x19, 0x0,  0x0, 0x17, 0x0, 0x80, 0x0, 0x0};
u8 D_808055C0_chdragonbrothers[28] = {0x0,  0x13, 0x4,  0x83, 0x2,  0x6,  0x0, 0x7,  0x0, 0x16,
                                      0x46, 0x50, 0x0,  0xE,  0x1,  0x33, 0x1, 0x70, 0x1, 0x80,
                                      0x0,  0x1,  0x13, 0x88, 0x1D, 0x4C, 0x0, 0x0};
u8 D_808055DC_chdragonbrothers[44] = {
    0x0,  0x1D, 0x9,  0xDD, 0x0, 0x16, 0x12, 0x0,  0x0,  0x15, 0x0,  0x0, 0x0,  0x4C, 0x0,
    0x22, 0x1,  0x99, 0x2,  0x0, 0x1,  0x33, 0x1,  0x99, 0x0,  0x2B, 0x0, 0x40, 0x0,  0xA6,
    0x0,  0x1B, 0x1,  0x2C, 0x2, 0x58, 0x0,  0x17, 0x0,  0x80, 0x0,  0x0, 0x0,  0x0};
Vec3f D_80805608_chdragonbrothers = {0.0f, 1.5e+03f, 1.4e+02f};
Vec3f D_80805614_chdragonbrothers = {0.0f, 0.0f, 3.1e+03f};
u8 D_80805620_chdragonbrothers[16] = {0x43, 0x96, 0x0, 0x0, 0x43, 0xAF, 0x0, 0x0,
                                      0x43, 0x7A, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0};
u8 D_80805630_chdragonbrothers[16] = {0x43, 0xAF, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0,
                                      0x43, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0};
u8 D_80805640_chdragonbrothers[16] = {0x44, 0x48, 0x0, 0x0, 0x43, 0x7A, 0x0,  0x0,
                                      0x43, 0x7A, 0x0, 0x0, 0x44, 0x22, 0x80, 0x0};
u8 D_80805650_chdragonbrothers[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x45, 0x39, 0x0, 0x0};
u8 D_8080565C_chdragonbrothers[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x45, 0x39, 0x0, 0x0};
u8 D_80805668_chdragonbrothers[16] = {0x3D, 0x4C, 0xCC, 0xCD, 0x3E, 0x4C, 0xCC, 0xCD,
                                      0x3E, 0x8A, 0x3D, 0x71, 0xBF, 0x80, 0x0,  0x0};
u8 D_80805678_chdragonbrothers[28] = {0x0,  0x13, 0x6,  0x2,  0x2,  0x6,  0x0, 0x7, 0x0, 0x16,
                                      0x46, 0x50, 0x0,  0xE,  0x0,  0xF3, 0x1, 0xC, 0x0, 0x40,
                                      0x0,  0x1,  0x13, 0x88, 0x1D, 0x4C, 0x0, 0x0};
u8 D_80805694_chdragonbrothers[20] = {0x3C, 0xF5, 0xC2, 0x8F, 0x3E, 0x9E, 0xB8, 0x52, 0x3F, 0x11,
                                      0xEB, 0x85, 0x3F, 0x54, 0x7A, 0xE1, 0xBF, 0x80, 0x0,  0x0};
int D_808056A8_chdragonbrothers[18] = {0x2E0377,
                                       0x7FC0003,
                                       (u32) &D_80805498_chdragonbrothers,
                                       (u32) func_80802574_chdragonbrothers,
                                       (u32) func_80105834,
                                       (u32) func_808034DC_chdragonbrothers,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x8056C,
                                       (u32) func_808003D8_chdragonbrothers,
                                       (u32) func_80108EE8,
                                       0x680000,
                                       (u32) func_80800070_chdragonbrothers,
                                       (u32) func_80107C2C,
                                       -0x7FDFFFFE,
                                       (u32) func_80801D40_chdragonbrothers,
                                       0x0};
u8 D_808056F0_chdragonbrothers[80] = {
    0x0,  0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x3F, 0x70, 0x0,  0x0,  0x3, 0x32, 0x0, 0x44,
    0x3F, 0x70, 0x0, 0x0, 0x3, 0x32, 0x0, 0x44, 0x3F, 0x70, 0x0,  0x0,  0x3, 0x32, 0x0, 0x4A,
    0x3F, 0x0,  0x0, 0x0, 0x3, 0x33, 0x0, 0x44, 0x3E, 0x19, 0x99, 0x9A, 0x3, 0x33, 0x0, 0x2,
    0x3F, 0x70, 0x0, 0x0, 0x3, 0x32, 0x0, 0x92, 0x3F, 0x70, 0x0,  0x0,  0x3, 0x32, 0x0, 0x92,
    0x3F, 0x70, 0x0, 0x0, 0x3, 0x32, 0x0, 0x44, 0x3F, 0x70, 0x0,  0x0,  0x3, 0x32, 0x0, 0x44};
Vec3f D_80805740_chdragonbrothers = {0.0f, 264.0f, -118.0f};
int D_8080574C_chdragonbrothers[18] = {0x2F0378,
                                       0x8010001,
                                       (u32) &D_808056F0_chdragonbrothers,
                                       (u32) func_808038AC_chdragonbrothers,
                                       (u32) func_80105834,
                                       (u32) func_80803EFC_chdragonbrothers,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x80C44,
                                       (u32) func_808036E4_chdragonbrothers,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_80803574_chdragonbrothers,
                                       (u32) func_80107C2C,
                                       0x0,
                                       (u32) func_80803DC4_chdragonbrothers,
                                       0x0};
u8 D_80805794_chdragonbrothers[20] = {0x0, 0x13, 0x5, 0xB8, 0x0, 0x18, 0x0, 0x1,  0x4, 0xE2,
                                      0x9, 0xC4, 0x0, 0xD,  0x1, 0x33, 0x1, 0x4C, 0x0, 0x0};
u8 D_808057A8_chdragonbrothers[56] = {
    0x0, 0x1D, 0x9, 0xCE, 0x0,  0x16, 0x12, 0x0,  0x0, 0x32, 0x0, 0x2,  0x0, 0x15,
    0x0, 0x0,  0x0, 0x99, 0x0,  0x22, 0x1,  0x99, 0x2, 0x0,  0x1, 0x33, 0x1, 0x99,
    0x0, 0x2B, 0x0, 0xA6, 0x0,  0xA6, 0x0,  0x1B, 0x1, 0x2C, 0x1, 0x2C, 0x0, 0x18,
    0x0, 0x0,  0x0, 0x0,  0x19, 0x0,  0x19, 0x0,  0x0, 0x17, 0x0, 0x80, 0x0, 0x0};
u8 D_808057E0_chdragonbrothers[48] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x12, 0x0,  0x0, 0x32, 0x0, 0x2,  0x0, 0x15, 0x0, 0x0,
    0x0, 0x99, 0x0, 0x22, 0x1, 0x99, 0x2,  0x0,  0x1, 0x33, 0x1, 0x99, 0x0, 0x2B, 0x0, 0xA6,
    0x0, 0xA6, 0x0, 0x1B, 0x1, 0x2C, 0x1,  0x2C, 0x0, 0x17, 0x0, 0x80, 0x0, 0x0,  0x0, 0x0};
u8 D_80805810_chdragonbrothers[48] = {
    0x0,  0x1D, 0x9, 0xE0, 0x0,  0x16, 0x12, 0x0,  0x0, 0xE,  0x0, 0x60, 0x0, 0x60, 0x0, 0x15,
    0x0,  0x19, 0x0, 0x99, 0x0,  0x22, 0x1,  0x0,  0x1, 0x0,  0x0, 0x66, 0x0, 0x66, 0x0, 0x27,
    0xFE, 0x70, 0x1, 0x90, 0xFC, 0xE0, 0x3,  0x20, 0x0, 0x2B, 0x0, 0x4C, 0x0, 0x99, 0x0, 0x0};
u8 D_80805840_chdragonbrothers[48] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x12, 0x0,  0x0, 0xE,  0x0, 0x32, 0x0, 0x96, 0x0, 0x15,
    0x0, 0x40, 0x0, 0xA6, 0x0, 0x22, 0x1,  0x99, 0x2, 0x0,  0x1, 0x33, 0x1, 0x99, 0x0, 0x2B,
    0x0, 0x40, 0x1, 0xC,  0x0, 0x17, 0x0,  0x80, 0x0, 0x2D, 0x0, 0x64, 0x1, 0x2C, 0x0, 0x0};
u8 D_80805870_chdragonbrothers[56] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x12, 0x0,  0x0,  0xE,  0x0, 0x32, 0x0, 0x96,
    0x0, 0x15, 0x0, 0x40, 0x0, 0xA6, 0x0,  0x22, 0x1,  0x99, 0x2, 0x0,  0x1, 0x33,
    0x1, 0x99, 0x0, 0x2B, 0x0, 0x40, 0x1,  0xC,  0x0,  0x17, 0x0, 0x80, 0x0, 0x2D,
    0x0, 0x64, 0x1, 0x2C, 0x0, 0x1F, 0x40, 0x40, 0x40, 0x0,  0x0, 0x0,  0x0, 0x0};
void *D_808058A8_chdragonbrothers = (void *) 0x00300379;
static u32 D_808058A8_chdragonbrothers_rest[17] = {0x8150001,
                                                   0x0,
                                                   (u32) func_808040A8_chdragonbrothers,
                                                   (u32) func_80105834,
                                                   (u32) func_80804318_chdragonbrothers,
                                                   0x0,
                                                   0x3F800000,
                                                   0x0,
                                                   0x1004,
                                                   (u32) func_808040A0_chdragonbrothers,
                                                   (u32) func_80108EE8,
                                                   0x0,
                                                   (u32) func_80803F4C_chdragonbrothers,
                                                   (u32) func_80107C2C,
                                                   0x0,
                                                   (u32) func_80804350_chdragonbrothers,
                                                   0x0};
s16 D_808058F0_chdragonbrothers[8] = {0x0, 0x9D7, 0x9C1, 0x9C0, 0x9C2, 0x9C3, 0x9C4, 0x0};
u8 D_80805900_chdragonbrothers[24] = {0x0,  0x13, 0x4,  0x7,  0x0,  0xD,  0x1, 0x26,
                                      0x1,  0x40, 0x0,  0x16, 0x46, 0x50, 0x0, 0x1,
                                      0x27, 0x10, 0x3A, 0x98, 0x0,  0x0,  0x0, 0x0};
int D_80805918_chdragonbrothers[18] = {
    0x710001D, 0x9D60015, 0x20099, 0x160200, 0x1E0032, 0x32000E,  0x6E0078, 0x260000, 0xFF9C,
    0x0,       0x640019,  0x10001, 0x220099, 0xCC0199, 0x200002A, 0xA000A,  0x80008C, 0xF0000};
int D_80805960_chdragonbrothers[18] = {
    0x510001D, 0x9D60015, 0x20099, 0x160200, 0x1E0032, 0x32000E,  0x1E003C, 0x260000, 0xFF9C,
    0x0,       0x640019,  0x0,     0x220099, 0xCC0200, 0x2CC002A, 0x80008,  0x660066, 0xF0000};
int D_808059A8_chdragonbrothers[12] = {0x110001D, 0x9D60015, 0x200CC,  0x160200,
                                       0x1E0032,  0x320019,  0x0,      0x2200CC,
                                       0xCC0380,  0x380002B, 0x590059, 0x11A0000};
int D_808059D8_chdragonbrothers[5] = {0x130413, 0x166590, 0xD00F3, 0x10C0002, 0x0};
u8 D_808059EC_chdragonbrothers[28] = {0x0,  0x13, 0x4,  0x83, 0x2,  0x6,  0x0, 0x7,  0x0, 0x16,
                                      0x46, 0x50, 0x0,  0xE,  0x1,  0x33, 0x1, 0x70, 0x1, 0x80,
                                      0x0,  0x1,  0x13, 0x88, 0x1D, 0x4C, 0x0, 0x0};
s32 D_80805A08_chdragonbrothers[18] = {0x31037A,
                                       0x9D70001,
                                       0x0,
                                       (u32) func_80804AA4_chdragonbrothers,
                                       (u32) func_80105834,
                                       (u32) func_80804C90_chdragonbrothers,
                                       0x0,
                                       0x3F800000,
                                       0x0,
                                       0x404,
                                       (u32) func_808048A4_chdragonbrothers,
                                       0x0,
                                       0x140000,
                                       (u32) func_8080449C_chdragonbrothers,
                                       (u32) func_80107C2C,
                                       -0x7FFFFFFE,
                                       (u32) func_80804C6C_chdragonbrothers,
                                       0x0};
s32 D_80805A50_chdragonbrothers[3] = {0x43CF0000, -0x3C1A0000, 0x45548000};
int D_80805A5C_chdragonbrothers[21] = {0x33037B,
                                       0x8D80003,
                                       0x0,
                                       (u32) func_80804E1C_chdragonbrothers,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0xA0C04,
                                       (u32) func_80804DB0_chdragonbrothers,
                                       0x0,
                                       0x0,
                                       (u32) func_80804CD0_chdragonbrothers,
                                       (u32) func_80107C2C,
                                       -0x7FFFF7FE,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0};
