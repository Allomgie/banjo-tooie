#include "common.h"

extern void _chfactoryempspell_entrypoint_0(void);
extern int D_808021BC_chfactoryempspell[];
extern int D_8080221C_chfactoryempspell[];
extern int D_80802228_chfactoryempspell[];
extern int D_808021D4_chfactoryempspell[];
extern int D_808021EC_chfactoryempspell[];
extern int D_80802234_chfactoryempspell[];
extern int D_80802204_chfactoryempspell[];
extern void _sumumbofx_entrypoint_6(s32, f32, f32, s32, s32, void *, void *, void *);
extern f32 D_808022C8_chfactoryempspell[][3];
extern f32 D_808022E0_chfactoryempspell[][3];
extern f32 D_808022F8_chfactoryempspell[][3];
extern f32 D_80802310_chfactoryempspell[][3];
extern u8 D_80802240_chfactoryempspell[];
extern u8 D_8080227C_chfactoryempspell[];
extern f32 func_800DC0C0(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800C8CB8();
extern void func_800C8F64();
extern void func_800C8FB0();
extern void *func_80100094(Actor *, u32);
extern f32 func_800DC178(f32, f32);
extern void func_800C8E54(s32, f32, f32);
typedef struct {
    f32 pos[2];
    u8 unk_8;
    u8 pad_9[3];
    s32 light;
    u16 countdown : 7;
    u16 period : 7;
    u16 flipped : 1;
    u16 pad_10 : 1;
    u16 pad_12;
} EmpLightRecord1081;
extern u8 D_80802390_chfactoryempspell[];
extern u8 D_80802384_chfactoryempspell[];
extern u8 D_80802328_chfactoryempspell[];
extern u8 D_8080239C_chfactoryempspell[];
extern u8 D_808023B4_chfactoryempspell[];
extern u8 D_80802374_chfactoryempspell[];
extern u8 D_808023A8_chfactoryempspell[];
typedef struct {
    f32 x;
    f32 y;
    u8 unk_8;
    u8 pad_9[3];
    s32 light;
    u32 countdown : 7;
    u32 period : 7;
    u32 flipped : 1;
    u32 pad_10 : 17;
} ES;
typedef struct {
    u8 pad_0[8];
    u8 unk_8;
    u8 pad_9[3];
    s32 light;
    u8 countdown : 7;
    u8 unk_10_7 : 1;
    u8 pad_11[3];
} EMPPart1262;
extern void func_800C8B84();
typedef struct {
    u8 pad_0[0x3C];
    s32 lights[4];
} FactoryEMPPlayerLights;
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_28(void *, f32 *, f32, f32);
extern int D_80802414_chfactoryempspell[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern Actor *_subaddiefind_entrypoint_3(s32, s32 *);
extern void _sumumbofx_entrypoint_5(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_18(void *, f32);
extern void _sumumbofx_entrypoint_20(void *, f32);
extern f32 _sumumbofx_entrypoint_26(void *);
typedef struct {
    struct {
        u8 pad_0[8];
        u8 unk_8;
        u8 pad_9[11];
    } parts[3];
    s32 lights[4];
    s32 selected;
    s16 handles[15];
} FactoryEMPHandlerData;
extern f32 func_800138D0(f32);

extern f32 func_800F10B4(f32, f32, f32, f32, f32);

extern void func_80100E18();
extern void *func_80100A74();
extern s16 func_80100D24();
extern void _sumumbofx_entrypoint_3(void *, f32);
extern s32 D_80802170_chfactoryempspell[];
typedef struct {
    f32 pos[2];
    u8 unk_8;
    u8 pad_9[3];
    s32 light;
    u32 countdown : 7;
    u32 period : 7;
    u32 flipped : 1;
    u32 pad_10 : 17;
} FactoryEMPDrawPart;
typedef struct {
    FactoryEMPDrawPart parts[3];
    s32 lights[4];
    s32 segment;
} FactoryEMPDrawData;
extern Vec3f D_80802180_chfactoryempspell;
extern Vec3f D_8080218C_chfactoryempspell;
extern Vec3f D_80802198_chfactoryempspell;
extern Vec3f D_808021A4_chfactoryempspell;
extern Vec3f D_808021B0_chfactoryempspell;

void func_80801F30_chfactoryempspell();

void func_80801E48_chfactoryempspell();

void func_80801AB4_chfactoryempspell();

void func_80801844_chfactoryempspell();

void func_808016AC_chfactoryempspell();

void func_808012C0_chfactoryempspell(f32 param_0, f32 param_1);

void func_80801130_chfactoryempspell(s32 param_0, s32 param_1, f32 param_2);

extern s32 func_801017D0(s32 *);
extern int func_800DE498(s32, f32 *, f32 *, f32, s32, s32);
extern f32 D_808023C0_chfactoryempspell[];
extern f32 D_808023CC_chfactoryempspell[];
extern f32 D_808023D8_chfactoryempspell[];
extern f32 D_808023E4_chfactoryempspell[];
extern s32 D_808023F0_chfactoryempspell[];
extern s32 D_808023FC_chfactoryempspell[];
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800F3214(s32 *, s32 *, s32 *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern u8 D_80802408_chfactoryempspell[];
extern void func_800C31DC(s32, f32);
void func_80800A08_chfactoryempspell();
void func_80801C00_chfactoryempspell(Actor *param_0, f32 param_1);
void func_80801E9C_chfactoryempspell(Actor *param_0, f32 param_1);
extern void func_80105834(), func_80107C2C(), func_80800000_chfactoryempspell(),
    func_80800C7C_chfactoryempspell(), func_80801FE0_chfactoryempspell();

// Wall-crusher EMP controller: update state machine (Mumbo EMP spell powers the crushers down).
void func_80800000_chfactoryempspell(actor) Actor *actor;
{
    func_80800A08_chfactoryempspell(actor);
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2: {
            void *fx;
            if (func_800DA298(0x9DE)) {
                func_80801F30_chfactoryempspell(actor);
                fx = func_80100094(actor, 0);
                _sumumbofx_entrypoint_15(fx, 3.0f);
                _capod_entrypoint_13(actor->unk0, 0, 0xA, 0x810);
                actor->unk64_20 = 0;
                func_800DA544(0xA05);
                func_80101180(0x2B0, 0xBB, 0xB);
                func_80101FDC(actor, 3);
                func_800DA544(0x57F);
            }
            break;
        }
        case 3: {
            void *fx;
            fx = func_80100094(actor, 0);
            func_80801130_chfactoryempspell(actor, fx, 1.0f);
            func_80801C00_chfactoryempspell(actor, 1.0f);
            if (_sumumbofx_entrypoint_27(fx)) {
                _sumumbofx_entrypoint_18(fx, 3.0f);
                func_80101FDC(actor, 4);
            }
            break;
        }
        case 4: {
            void *fx;
            fx = func_80100094(actor, 0);
            func_80801130_chfactoryempspell(actor, fx, 0.75f);
            _sumumbofx_entrypoint_5(fx, 1.5f);
            func_80801C00_chfactoryempspell(actor, _sumumbofx_entrypoint_26(fx));
            if (_sumumbofx_entrypoint_27(fx)) {
                _sumumbofx_entrypoint_17(fx, 5.0f);
                func_80101FDC(actor, 5);
            }
            break;
        }
        case 5: {
            s32 count;
            Actor *crusher_a;
            Actor *crusher_b;
            void *fx;
            crusher_a = _subaddiefind_entrypoint_2(0x3BA, &count);
            crusher_b = _subaddiefind_entrypoint_3(0x3BA, &count);
            fx = func_80100094(actor, 0);
            func_80801130_chfactoryempspell(actor, fx, *(f32 *) &crusher_a->actorData[7]);
            func_80801C00_chfactoryempspell(actor, *(f32 *) &crusher_a->actorData[7]);
            if (crusher_a->unk70_10 == 3) {
                func_80101FDC(crusher_a, 5);
                *(f32 *) &crusher_a->actorData[7] = 1.0f;
                func_80101FDC(crusher_b, 5);
                *(f32 *) &crusher_b->actorData[7] = 1.0f;
                func_80101FDC(actor, 6);
                _sumumbofx_entrypoint_20(fx, 5.0f);
            }
            break;
        }
        case 6: {
            void *fx;
            fx = func_80100094(actor, 0);
            func_80801130_chfactoryempspell(actor, fx, 1.0f);
            func_808012C0_chfactoryempspell(0.1f, 0.1f);
            func_80801E9C_chfactoryempspell(actor, 1.0f);
            func_80801C00_chfactoryempspell(actor, 1.0f);
            if (_sumumbofx_entrypoint_27(fx)) {
                actor->unk64_19 = 1;
                func_80101FDC(actor, 7);
                _sumumbofx_entrypoint_20(fx, 5.0f);
            }
            break;
        }
        case 7: {
            s32 count;
            Actor *crusher_a;
            Actor *crusher_b;
            void *fx;
            f32 level;
            crusher_a = _subaddiefind_entrypoint_2(0x3BA, &count);
            crusher_b = _subaddiefind_entrypoint_3(0x3BA, &count);
            fx = func_80100094(actor, 0);
            level = 1.0f - _sumumbofx_entrypoint_26(fx);
            *(f32 *) &crusher_a->actorData[7] = level;
            *(f32 *) &crusher_b->actorData[7] = level;
            func_80801130_chfactoryempspell(actor, fx, level);
            func_808012C0_chfactoryempspell(0.2f, 0.2f);
            func_80801E9C_chfactoryempspell(actor, level);
            func_80801C00_chfactoryempspell(actor, 1.0f);
            if (_sumumbofx_entrypoint_27(fx)) {
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1339, 4, actor->position, 0);
                func_800DA544(0x9DF);
                _chglowbo_entrypoint_6();
                func_808016AC_chfactoryempspell(actor);
                func_80101FDC(actor, 8);
            }
            break;
        }
        case 8: {
            s32 count;
            Actor *crusher_a;
            void *fx;
            crusher_a = _subaddiefind_entrypoint_2(0x3BA, &count);
            fx = func_80100094(actor, 0);
            func_80801130_chfactoryempspell(actor, fx, *(f32 *) &crusher_a->actorData[7]);
            func_808012C0_chfactoryempspell(0.07f, 0.05f);
            func_80801844_chfactoryempspell(actor);
            func_80801E9C_chfactoryempspell(actor, *(f32 *) &crusher_a->actorData[7]);
            if (func_800CEAA8(0)) {
                func_80101FDC(actor, 9);
            }
            break;
        }
        case 9: {
            s32 count;
            Actor *crusher_a;
            void *fx;
            crusher_a = _subaddiefind_entrypoint_2(0x3BA, &count);
            fx = func_80100094(actor, 0);
            func_80801130_chfactoryempspell(actor, fx, *(f32 *) &crusher_a->actorData[7]);
            func_808012C0_chfactoryempspell(0.07f, 0.05f);
            func_80801844_chfactoryempspell(actor);
            func_80801E9C_chfactoryempspell(actor, *(f32 *) &crusher_a->actorData[7]);
            if (!func_800DA298(0xA05) || (f32) func_800CEA84(0) < 2.0f) {
                *(u8 *) &actor->actorData[4] =
                    _subaddieaudioloop_entrypoint_3(*(u8 *) &actor->actorData[4]);
                _sumumbofx_entrypoint_16(fx, 2.0f);
                func_80101FDC(actor, 0xA);
            }
            break;
        }
        case 10: {
            s32 count;
            Actor *crusher_a;
            void *fx;
            crusher_a = _subaddiefind_entrypoint_2(0x3BA, &count);
            fx = func_80100094(actor, 0);
            func_80801130_chfactoryempspell(actor, fx, *(f32 *) &crusher_a->actorData[7]);
            func_80801C00_chfactoryempspell(actor, *(f32 *) &crusher_a->actorData[7]);
            func_80801844_chfactoryempspell(actor);
            if (_sumumbofx_entrypoint_27(fx)) {
                if (!func_800DA298(0x329)) {
                    func_808012C0_chfactoryempspell(1.0f, 1.0f);
                }
                func_80801AB4_chfactoryempspell(actor);
                func_80801E48_chfactoryempspell(actor);
                actor->unk64_19 = 0;
                func_80101FDC(actor, 0xB);
            }
            break;
        }
        case 11: {
            s32 count;
            Actor *crusher_a;
            Actor *crusher_b;
            crusher_a = _subaddiefind_entrypoint_2(0x3BA, &count);
            crusher_b = _subaddiefind_entrypoint_3(0x3BA, &count);
            _sumumbofx_entrypoint_1(actor, 0);
            func_80101FDC(crusher_a, 1);
            func_80101FDC(crusher_b, 1);
            crusher_a->unk58 = 1.2f;
            crusher_b->unk58 = 1.2f;
            _subaddieDll_entrypoint_4(actor, 0);
            func_800DA524(0x9DE);
            func_80101FDC(actor, 1);
        }
    }
}

void func_80801038_chfactoryempspell();

s32 func_80800630_chfactoryempspell(Actor *actor, s32 msg, s32 arg)
{
    FactoryEMPHandlerData *data;

    data = func_80100094(actor, 1);
    switch (msg) {
        case 0x2E:
            if (((s16 *) &arg)[0] == 0x1339) {
                func_80801038_chfactoryempspell(actor);
            }
            return 1;
        case 0x30:
            if (((s16 *) &arg)[0] == 0x1339) {
                return 0x2D;
            }
        case 0xB:
            if (arg == 0xA) {
                func_80801038_chfactoryempspell(actor);
            }
            return 3;
        case 0x4B:
            _subaddieDll_entrypoint_4(actor, 1);
            func_80101FDC(actor, 2);
            return 1;
        case 0x95: {
            s32 i;
            Actor *crusher_a;
            Actor *crusher_b;
            void *fx;
            s32 j;

            func_800DA3B8(0x9DE, func_800DA298(0xA06) || func_800DA298(0xA05));
            if (func_800DA298(0xA05)) {
                crusher_a = _subaddiefind_entrypoint_2(0x3BA, &i);
                crusher_b = _subaddiefind_entrypoint_3(0x3BA, &i);
                func_80801F30_chfactoryempspell(actor);
                func_80101FDC(actor, 9);
                func_80101FDC(crusher_a, 5);
                func_80101FDC(crusher_b, 5);
                fx = func_80100094(actor, 0);
                _sumumbofx_entrypoint_17(fx, 5.0f);
                _sumumbofx_entrypoint_4(fx);
                _sumumbofx_entrypoint_3(fx, 10.0f);
                *(f32 *) &crusher_a->actorData[7] = 0.0f;
                *(f32 *) &crusher_b->actorData[7] = 0.0f;
                *(u8 *) &actor->actorData[4] = 0;
                for (j = 0; j < 3; j++) {
                    data->parts[j].unk_8 = 0;
                }
                actor->unk5F = 0;
                actor->unk64_19 = 1;
                *(f32 *) &actor->actorData[5] = 2.0f;
            } else {
                actor->unk64_19 = 0;
                *(f32 *) &actor->actorData[5] = -2.0f;
                func_80101FDC(actor, 1);
            }
            *(f32 *) &actor->actorData[3] = 0.0f;
            for (i = 0; i < 15; i++) {
                data->handles[i] = 0;
            }
            return 1;
        }
        case 0x29: {
            s32 src;
            s32 i;
            s16 handle;
            src = arg;
            for (i = 0; i < 15; i++) {
                handle =
                    func_80100D24(src, actor->unk0->unk14, 1, 1, actor->unk0->unk16, 0);
                data->handles[i] = handle;
            }
            return 1;
        }
        case 0x2A: {
            s32 i;
            for (i = 0; i < 15; i++) {
                if (data->handles[i]) {
                    func_80100E18(data->handles[i]);
                    data->handles[i] = 0;
                }
            }
            return 1;
        }
        case 0x1F: {
            s16 handle;
            handle = data->handles[data->selected];
            func_800DF818(func_80100A74(handle, 0));
            func_800DF660(2, -1, 0, *((u8 *) actor + 0x9B));
            func_800DF720(func_80100AC4(handle));
            return 1;
        }
        case 0xB9:
            *(f32 *) &actor->actorData[5] = 0.0f;
            *(f32 *) &actor->actorData[6] = 1.0f;
            return 1;
        case 0xBA:
            *(f32 *) &actor->actorData[6] = 0;
            return 1;
        default:
            return 0;
    }
}

// Scrolls the conveyor belt and pushes the player along it (z 3700..4300).
void func_80800A08_chfactoryempspell(actor) Actor *actor;
{
    extern f32 func_800D8FF8(void);
    extern void func_800D91EC(f32 *, f32);
    extern void func_800D90F8(f32 *, f32);
    extern f32 func_800F0D50(f32, f32, f32);
    extern f32 mlAbsF(f32);
    extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    f32 player_pos[3];
    f32 push_speed;
    if (*(f32 *) ((u8 *) actor + 0x30) == 0.0f) {
        func_800F5A00(func_800F54E4(), player_pos);
        if (actor->unk64_19) {
            func_800D91EC((f32 *) ((u8 *) actor + 0x2C), 2.0f);
        } else {
            func_800D90F8((f32 *) ((u8 *) actor + 0x2C), -2.0f);
        }
        *(f32 *) ((u8 *) actor + 0x24) += func_800D8FF8() * *(f32 *) ((u8 *) actor + 0x2C);
        if (*(f32 *) ((u8 *) actor + 0x24) >= 2.6666667f) {
            *(f32 *) ((u8 *) actor + 0x24) -= 2.6666667f;
        } else if (*(f32 *) ((u8 *) actor + 0x24) < 0.0f) {
            *(f32 *) ((u8 *) actor + 0x24) += 2.6666667f;
        }
        if (player_pos[2] >= 3700.0f && player_pos[2] <= 4300.0f && player_pos[1] < 0.0f &&
            func_800F6C5C(func_800F54E4())) {
            push_speed = *(f32 *) ((u8 *) actor + 0x2C) * 297.49997f;
            func_800EFA4C(player_pos, push_speed,
                          func_800138D0(func_800F10B4(player_pos[0], -5950.0f, 5950.0f, 0.0f, 1.5f) *
                                        360.0f * 15.0f) *
                              1.5f * 5.0f,
                          0.0f);
            func_800F48BC(func_800F54E4(), player_pos);
        }
        player_pos[0] = func_800F0D50(player_pos[0], -5950.0f, 5950.0f);
        player_pos[1] = -20.0f;
        player_pos[2] = 4000.0f;
        _subaddieaudioloop_entrypoint_4(actor, player_pos, 1, D_80802170_chfactoryempspell);
        _subaddieaudioloop_entrypoint_0(
            actor,
            func_800F10B4(mlAbsF(*(f32 *) ((u8 *) actor + 0x2C)), 2.0f, 0.0f, 0.55f, 0.4f));
    }
}

void func_80800C7C_chfactoryempspell(actor, gfx) Actor *actor;
s32 gfx;
{
    Vec3f player_pos;
    Vec3f bounds_min = D_80802180_chfactoryempspell;
    Vec3f bounds_max = D_8080218C_chfactoryempspell;

    func_800F5A00(func_800F54E4(), player_pos.f);
    if (func_800EFED0(bounds_min.f, bounds_max.f, player_pos.f)) {
        FactoryEMPDrawData *data;
        void *fx;
        Vec3f belt_pos;
        s32 model;
        s32 i;

        data = func_80100094(actor, 1);
        fx = func_80100094(actor, 0);
        belt_pos = D_80802198_chfactoryempspell;
        model = func_801039E4(actor->unk0);
        belt_pos.f[0] +=
            func_800F10B4(*(f32 *) &actor->actorData[3], 0.0f, 2.6666667f, 0.0f, 793.3333f);
        // Matching: the ^ 0 is needed for the match.
        for (i = 0; (i ^ 0) < 15; i++) {
            f32 phase;
            Vec3f belt_rot;
            phase = func_800F10B4(belt_pos.f[0], -5950.0f, 5950.0f, 0.0f, 1.5f);
            belt_rot = D_808021A4_chfactoryempspell;
            belt_pos.f[1] = func_800138D0(phase * 360.0f * 15.0f) * 1.5f + -20.0f;
            belt_rot.f[0] = func_800138D0(phase * 360.0f * 15.0f);
            data->segment = i;
            func_800DF830(1);
            func_800DF47C(func_801017D0, actor);
            func_800DE498(gfx, belt_pos.f, belt_rot.f, 1.0f, 0, model);
            belt_pos.f[0] += 793.3333f;
        }
        if (fx) {
            _sumumbofx_entrypoint_9(fx, gfx);
            _sumumbofx_entrypoint_8(fx, gfx);
        }
        if (actor->unk70_10 == 9) {
            Vec3f bolt_rot = D_808021B0_chfactoryempspell;
            Vec3f bolt_pos;

            model = func_800D674C(0x8D3);
            for (i = 0; i < 3; i++) {
                func_800EFA4C(bolt_pos.f, data->parts[i].pos[0],
                              func_800F10B4(data->parts[i].countdown,
                                            data->parts[i].period, 0.0f,
                                            data->parts[i].pos[1], 1600.0f),
                              4000.0f);
                if (data->parts[i].flipped) {
                    bolt_rot.f[2] = 180.0f;
                } else {
                    bolt_rot.f[2] = 0.0f;
                }
                func_800DF744(1, func_800DC128(1, 4));
                func_800DF830(2);
                func_800DE498(gfx, bolt_pos.f, bolt_rot.f, 1.5f, 0, model);
            }
        }
    }
}

// Starts the 45 s power-down timer (expiry: chfactoryempspell_entrypoint_0).
void func_80801038_chfactoryempspell(Actor *actor)
{
    extern void func_800CE8D8(void *, f32, s32);

    if (actor->unk64_20) {
        func_800CE8D8(NULL, 45.0f, 45);
        func_800CE928(0, _chfactoryempspell_entrypoint_0, actor->unk0);
        func_800CE88C(0, 1);
    } else {
        actor->unk64_20 = 1;
    }
}

int chfactoryempspell_entrypoint_0(s32 param_0, s32 param_1)
{
    if (!func_800DA298(0x329)) {
        _chmrtannoy_entrypoint_0();
        func_800C0534(0x133A, 4, 0, 0, 0, 0, 0, 0xA3);
    }
    if (func_800EA05C() != 0x10B) {
        func_800DA524(0x9DE);
    }
    func_800DA524(0xA05);
}

void func_80801130_chfactoryempspell(s32 side, s32 fx, f32 scale)
{
    f32 player_pos[3];
    func_800E3980(player_pos);
    side = player_pos[0] < 0.0f ? 0 : 1;
    _sumumbofx_entrypoint_6(fx, 500.0f * scale, 300.0f, 0, 10, &D_8080221C_chfactoryempspell,
                            (u8 *) &D_808021BC_chfactoryempspell + side * 12,
                            &D_80802228_chfactoryempspell);
    _sumumbofx_entrypoint_6(
        fx, 500.0f * scale, 300.0f, 10, 20, &D_8080221C_chfactoryempspell,
        (u8 *) &D_808021D4_chfactoryempspell + side * 12, &D_80802228_chfactoryempspell);
    _sumumbofx_entrypoint_6(
        fx, 500.0f * scale, 300.0f, 20, 30, &D_8080221C_chfactoryempspell,
        (u8 *) &D_808021EC_chfactoryempspell + side * 12, &D_80802234_chfactoryempspell);
    _sumumbofx_entrypoint_6(
        fx, 500.0f * scale, 300.0f, 30, 40, &D_8080221C_chfactoryempspell,
        (u8 *) &D_80802204_chfactoryempspell + side * 12, &D_80802234_chfactoryempspell);
    _sumumbofx_entrypoint_14(fx);
}

void func_808012C0_chfactoryempspell(f32 chance_a, f32 chance_b)
{
    f32 offset[3];
    f32 roll;
    s32 side;

    func_800E3980(offset);
    if (offset[0] < 0.0f) {
        side = 0;
    } else {
        side = 1;
    }

    roll = func_800DC0C0();
    if (roll < chance_a) {
        func_800BBCB8(D_808022C8_chfactoryempspell[side], 0, 1.0f, 1,
                      D_80802240_chfactoryempspell);
    }
    if (roll < chance_b) {
        func_800EFA4C(offset, D_808022C8_chfactoryempspell[side][0] + 100.0f,
                      D_808022C8_chfactoryempspell[side][1] - 30.0f,
                      D_808022C8_chfactoryempspell[side][2] - 50.0f);
        func_800BBCB8(D_808022C8_chfactoryempspell[side], offset, 1.0f, 2,
                      D_8080227C_chfactoryempspell);
    }

    roll = func_800DC0C0();
    if (roll < chance_a) {
        func_800BBCB8(D_808022E0_chfactoryempspell[side], 0, 1.0f, 1,
                      D_80802240_chfactoryempspell);
    }
    if (roll < chance_b) {
        func_800EFA4C(offset, D_808022E0_chfactoryempspell[side][0] + 100.0f,
                      D_808022E0_chfactoryempspell[side][1] - 30.0f,
                      D_808022E0_chfactoryempspell[side][2] - 50.0f);
        func_800BBCB8(D_808022E0_chfactoryempspell[side], offset, 1.0f, 2,
                      D_8080227C_chfactoryempspell);
    }

    roll = func_800DC0C0();
    if (roll < chance_a) {
        func_800BBCB8(D_808022F8_chfactoryempspell[side], 0, 1.0f, 1,
                      D_80802240_chfactoryempspell);
    }
    if (roll < chance_b) {
        func_800EFA4C(offset, D_808022F8_chfactoryempspell[side][0] + 100.0f,
                      D_808022F8_chfactoryempspell[side][1] - 30.0f,
                      D_808022F8_chfactoryempspell[side][2] + 50.0f);
        func_800BBCB8(D_808022F8_chfactoryempspell[side], offset, 1.0f, 2,
                      D_8080227C_chfactoryempspell);
    }

    roll = func_800DC0C0();
    if (roll < chance_a) {
        func_800BBCB8(D_80802310_chfactoryempspell[side], 0, 1.0f, 1,
                      D_80802240_chfactoryempspell);
    }
    if (roll < chance_b) {
        func_800EFA4C(offset, D_80802310_chfactoryempspell[side][0] + 100.0f,
                      D_80802310_chfactoryempspell[side][1] - 30.0f,
                      D_80802310_chfactoryempspell[side][2] + 50.0f);
        func_800BBCB8(D_80802310_chfactoryempspell[side], offset, 1.0f, 2,
                      D_8080227C_chfactoryempspell);
    }
}

void func_808016AC_chfactoryempspell(Actor *actor)
{
    EmpLightRecord1081 *lights;
    s32 i;
    f32 pos[3];
    lights = func_80100094(actor, 1);
    for (i = 0; i < 3; i++) {
        lights[i].countdown = lights[i].period = func_800DC128(0, 9);
        lights[i].unk_8 = _subaddieaudioloop_entrypoint_3(lights[i].unk_8);
        lights[i].pos[0] = pos[0] = func_800DC178(-2400.0f, 3600.0f);
        lights[i].pos[1] = pos[1] = func_800DC178(200.0f, 1400.0f);
        lights[i].flipped = func_800DC128(0, 2);
        lights[i].light = func_800C8A98();
        func_800C8E54(lights[i].light, 400.0f, 500.0f);
        func_800C8FB0(lights[i].light, 200, 200, 255);
        func_800C8F64(lights[i].light, 1);
        pos[2] = 4000.0f;
        func_800C8CB8(lights[i].light, pos);
    }
}

void func_80801844_chfactoryempspell(Actor *actor)
{
    ES *base;
    ES *e;
    s32 i;
    s32 period;

    base = func_80100094(actor, 1);
    for (i = 0, e = base; i != 0x3C; i += 0x14, e = (ES *) ((u8 *) e + 0x14)) {
        if (e->countdown-- == 0) {
            period = func_800DC128(0, 9);
            e->countdown = e->period = period;
            e->unk_8 = _subaddieaudioloop_entrypoint_3(e->unk_8);
            e->x = *(f32 *) D_80802384_chfactoryempspell = *(f32 *) D_80802390_chfactoryempspell =
                *(f32 *) D_8080239C_chfactoryempspell = *(f32 *) D_808023A8_chfactoryempspell =
                    func_800DC178(-2400.0f, 3600.0f);
            e->y = *(f32 *) (D_80802384_chfactoryempspell + 4) =
                *(f32 *) (D_80802390_chfactoryempspell + 4) =
                    *(f32 *) (D_8080239C_chfactoryempspell + 4) =
                        *(f32 *) (D_808023A8_chfactoryempspell + 4) =
                            func_800DC178(200.0f, 1400.0f);
            e->flipped = func_800DC128(0, 2);
            func_800BBCB8((f32 *) D_80802384_chfactoryempspell,
                          (f32 *) D_80802390_chfactoryempspell, 1.0f, 2,
                          D_80802328_chfactoryempspell);
            func_800BBCB8((f32 *) D_8080239C_chfactoryempspell,
                          (f32 *) D_808023A8_chfactoryempspell, 1.0f, 2,
                          D_80802328_chfactoryempspell);
            *(f32 *) (D_80802384_chfactoryempspell + 8) = 4000.0f;
            func_800C8CB8(e->light, D_80802384_chfactoryempspell);
        } else {
            func_800EFA4C((f32 *) D_808023B4_chfactoryempspell, e->x, e->y, 4000.0f);
            func_800C8CB8(e->light, D_808023B4_chfactoryempspell);
            e->unk_8 = _subaddieaudioloop_entrypoint_7(e->unk_8, D_808023B4_chfactoryempspell, 1,
                                                    D_80802374_chfactoryempspell,
                                                    *(u32 *) ((u8 *) actor + 0x70) & 1);
        }
    }
}

void func_80801AB4_chfactoryempspell(Actor *actor)
{
    EMPPart1262 *parts;
    s32 i;

    parts = func_80100094(actor, 1);
    for (i = 0; i < 3; i++) {
        if (parts[i].light != 0) {
            func_800C8B84(parts[i].light);
        }
        parts[i].unk_8 = _subaddieaudioloop_entrypoint_3(parts[i].unk_8);
        parts[i].countdown = 0;
    }
}

void func_80801B2C_chfactoryempspell(Actor *actor)
{
    FactoryEMPPlayerLights *data;
    s32 i;
    f32 player_pos[3];

    data = func_80100094(actor, 1);
    for (i = 0; i < 4; i++) {
        func_800F5A00(func_800F54E4(), player_pos);
        data->lights[i] = func_800C8A98();
        func_800C8E54(data->lights[i], 300.0f, 400.0f);
        func_800C8FB0(data->lights[i], 0x50, 0xFF, 0xFF);
        func_800C8F64(data->lights[i], 1);
        func_800C8CB8(data->lights[i], player_pos);
    }
}

void func_80801C00_chfactoryempspell(Actor *actor, f32 t)
{
    s32 *data;
    f32 pos[3];
    s32 j;
    f32 player_pos[3];
    f32 target[3];
    s32 color[3];
    s32 i;
    f32 radii[2];
    data = func_80100094(actor, 1);
    switch (actor->unk70_10) {
        case 3:
            func_800F5A00(func_800F54E4(), pos);
            pos[1] += 200.0f;
            for (i = 0; i != 4; i++)
                func_800C8CB8(data[15 + i], pos);
            break;
        case 4:
            func_800F5A00(func_800F54E4(), player_pos);
            func_800EFE50(target, player_pos, D_808023C0_chfactoryempspell, t);
            func_800C8CB8(data[15], target);
            func_800EFE50(target, player_pos, D_808023CC_chfactoryempspell, t);
            func_800C8CB8(data[16], target);
            func_800EFE50(target, player_pos, D_808023D8_chfactoryempspell, t);
            func_800C8CB8(data[17], target);
            func_800EFE50(target, player_pos, D_808023E4_chfactoryempspell, t);
            func_800C8CB8(data[18], target);
            break;
        case 5:
            func_800C8CB8(data[15], D_808023C0_chfactoryempspell);
            func_800C8CB8(data[16], D_808023CC_chfactoryempspell);
            func_800C8CB8(data[17], D_808023D8_chfactoryempspell);
            func_800C8CB8(data[18], D_808023E4_chfactoryempspell);
            break;
        case 10:
            func_800F3214(color, D_808023F0_chfactoryempspell, D_808023FC_chfactoryempspell,
                          t);
            radii[0] = func_800F1214(t, 300.0f, 0.0f);
            radii[1] = func_800F1214(t, 400.0f, 0.0f);
            for (j = 0; j != 4; j++) {
                func_800C8D4C(data[15 + j], radii);
                func_800C8E84(data[15 + j], color);
            }
        case 11:
            break;
    }
}

void func_80801E48_chfactoryempspell(s32 actor)
{
    u8 *data = func_80100094(actor, 1);
    s32 i;
    for (i = 0; i < 4; i++) {
        func_800C8B84(((s32 *) (data + 0x3C))[i]);
    }
}

void func_80801E9C_chfactoryempspell(Actor *actor, f32 level)
{
    ((u8 *) actor->actorData)[0x10] = _subaddieaudioloop_entrypoint_7(
        ((u8 *) actor->actorData)[0x10], actor->position, 1, D_80802408_chfactoryempspell,
        *(u32 *) ((u8 *) actor + 0x70) & 1);
    func_800C31DC(((u8 *) actor->actorData)[0x10],
                  func_800F1214(level, 1.0f, 0.8f) + func_800DC0C0() * 0.1f);
}

void func_80801F30_chfactoryempspell(Actor *actor)
{
    s32 unk_0[3];
    s32 pad0;
    void *fx;

    unk_0[0] = 0;
    unk_0[1] = 0;
    unk_0[2] = 0;
    _sumumbofx_entrypoint_0(actor, 0, 0x28, (s16) _chmumbopad_entrypoint_0(0xB));
    fx = func_80100094(actor, 0);
    _sumumbofx_entrypoint_2(fx);
    _sumumbofx_entrypoint_24(fx, 0.5f);
    _sumumbofx_entrypoint_25(fx, 0x8C, unk_0);
    func_80801B2C_chfactoryempspell(actor);
    func_808016AC_chfactoryempspell(actor);
    _sumumbofx_entrypoint_28(fx, actor->position, 4000.0f, 5000.0f);
}

void func_80801FE0_chfactoryempspell(actor) u8 *actor;
{
    _subaddieaudioloop_entrypoint_2();
    *(u8 *) ((s8 *) actor + 0x28) =
        _subaddieaudioloop_entrypoint_3(*(u8 *) ((s8 *) actor + 0x28));
    func_80801AB4_chfactoryempspell(actor);
    if (*(s16 *) ((s8 *) actor + 0x82) != 0) {
        _sumumbofx_entrypoint_1(actor, 0);
    }
}

int chfactoryempspell_entrypoint_1()
{
    return (int) &D_80802414_chfactoryempspell;
}

s32 D_80802170_chfactoryempspell[4] = {0x130527, 0x1636B0, 0x100C8, 0x17700000};
Vec3f D_80802180_chfactoryempspell = {-5.2e+03f, -6.5e+02f, 7e+02f};
Vec3f D_8080218C_chfactoryempspell = {5.2e+03f, 2.2e+03f, 4.8e+03f};
Vec3f D_80802198_chfactoryempspell = {-5.95e+03f, -2e+01f, 4e+03f};
Vec3f D_808021A4_chfactoryempspell = {0.0f, 9e+01f, 0.0f};
Vec3f D_808021B0_chfactoryempspell = {0.0f, 2.7e+02f, 0.0f};
int D_808021BC_chfactoryempspell[6] = {-0x3AFA4000, 0x44A8C000, 0x454B2000,
                                       0x45584000,  0x44A8C000, 0x454B2000};
int D_808021D4_chfactoryempspell[6] = {-0x3AFA4000, 0x43660000, 0x454B2000,
                                       0x45584000,  0x43660000, 0x454B2000};
int D_808021EC_chfactoryempspell[6] = {-0x3AFA4000, 0x44A8C000, 0x45947000,
                                       0x45584000,  0x44A8C000, 0x45947000};
int D_80802204_chfactoryempspell[6] = {-0x3AFA4000, 0x43660000, 0x45947000,
                                       0x45584000,  0x43660000, 0x45947000};
int D_8080221C_chfactoryempspell[3] = {0x0, 0x0, 0x0};
int D_80802228_chfactoryempspell[3] = {0x42B40000, 0x0, 0x0};
int D_80802234_chfactoryempspell[3] = {0x43870000, 0x0, 0x0};
u8 D_80802240_chfactoryempspell[60] = {
    0x0,  0x1D, 0x9,  0xC9, 0x0,  0x2B, 0x2,  0x0,  0x3,  0x0,  0x0,  0x22, 0x2, 0x0,  0x2,
    0x80, 0x6,  0x0,  0x8,  0x0,  0x0,  0x16, 0x10, 0x0,  0x0,  0x15, 0x0,  0x0, 0x0,  0x33,
    0x0,  0x19, 0x0,  0x0,  0x0,  0x7,  0x0,  0x2C, 0xFF, 0xEC, 0x0,  0x14, 0x0, 0x14, 0x0,
    0x14, 0x0,  0x28, 0x0,  0x14, 0x0,  0x20, 0x60, 0x60, 0x60, 0x80, 0x0,  0x0, 0x0,  0x0};
u8 D_8080227C_chfactoryempspell[76] = {
    0x0, 0x1D, 0x9,  0xCD, 0x0, 0x1B, 0xFC, 0x18, 0xFC, 0xE0, 0x0, 0x2D, 0x1, 0x5E, 0x2, 0xEE,
    0x0, 0x16, 0x10, 0x0,  0x0, 0x27, 0x0,  0x0,  0x0,  0xC8, 0x0, 0x0,  0x1, 0x90, 0x0, 0x22,
    0x0, 0x19, 0x0,  0x1E, 0x0, 0x0,  0x0,  0x0,  0x0,  0x15, 0x0, 0x0,  0x0, 0x99, 0x0, 0xE,
    0x0, 0x0,  0x0,  0x32, 0x0, 0x2B, 0x1,  0x0,  0x1,  0x80, 0x0, 0x2F, 0x0, 0x80, 0x0, 0x80,
    0x0, 0x0,  0x0,  0x33, 0x0, 0x4C, 0x0,  0x0,  0x0,  0x66, 0x0, 0x0};
f32 D_808022C8_chfactoryempspell[2][3] = {-2.4e+03f, 1.35e+03f, 3.3e+03f,
                                          3.6e+03f,  1.35e+03f, 3.3e+03f};
f32 D_808022E0_chfactoryempspell[2][3] = {-2.4e+03f, 2.3e+02f, 3.3e+03f,
                                          3.6e+03f,  2.3e+02f, 3.3e+03f};
f32 D_808022F8_chfactoryempspell[2][3] = {-2.4e+03f, 1.35e+03f, 4.7e+03f,
                                          3.6e+03f,  1.35e+03f, 4.7e+03f};
f32 D_80802310_chfactoryempspell[2][3] = {-2.4e+03f, 2.3e+02f, 4.7e+03f,
                                          3.6e+03f,  2.3e+02f, 4.7e+03f};
u8 D_80802328_chfactoryempspell[76] = {
    0x0, 0x1D, 0x9,  0xCD, 0x0, 0x1B, 0xFC, 0x18, 0xFC, 0xE0, 0x0, 0x2D, 0x1, 0x5E, 0x2, 0xEE,
    0x0, 0x16, 0x10, 0x0,  0x0, 0x27, 0x0,  0x0,  0x0,  0xC8, 0x0, 0x0,  0x1, 0x90, 0x0, 0x22,
    0x0, 0x19, 0x0,  0x1E, 0x0, 0x0,  0x0,  0x0,  0x0,  0x15, 0x0, 0x0,  0x0, 0x99, 0x0, 0xE,
    0x0, 0x0,  0x0,  0x32, 0x0, 0x2B, 0x0,  0x80, 0x0,  0xB3, 0x0, 0x2F, 0x0, 0x80, 0x0, 0x80,
    0x0, 0x0,  0x0,  0x33, 0x0, 0x4C, 0x0,  0x0,  0x0,  0x66, 0x0, 0x0};
u8 D_80802374_chfactoryempspell[16] = {0x0, 0x13, 0x5,  0x2E, 0x0, 0xA, 0x0, 0xCC,
                                       0x0, 0x16, 0x7F, 0xFF, 0x0, 0x0, 0x0, 0x0};
u8 D_80802384_chfactoryempspell[12] = {0x0, 0x0, 0x0,  0x0,  0x0,  0x0,
                                       0x0, 0x0, 0x45, 0x8C, 0xA0, 0x0};
u8 D_80802390_chfactoryempspell[12] = {0x0, 0x0, 0x0,  0x0,  0x0,  0x0,
                                       0x0, 0x0, 0x45, 0x8F, 0xC0, 0x0};
u8 D_8080239C_chfactoryempspell[12] = {0x0, 0x0, 0x0,  0x0,  0x0,  0x0,
                                       0x0, 0x0, 0x45, 0x5A, 0xC0, 0x0};
u8 D_808023A8_chfactoryempspell[12] = {0x0, 0x0, 0x0,  0x0,  0x0,  0x0,
                                       0x0, 0x0, 0x45, 0x54, 0x80, 0x0};
u8 D_808023B4_chfactoryempspell[12] = {0x0,  0x0, 0x0,  0x0,  0x44, 0x54,
                                       0x80, 0x0, 0x45, 0x7A, 0x0,  0x0};
f32 D_808023C0_chfactoryempspell[3] = {-2.5e+03f, 1.35e+03f, 3.3e+03f};
f32 D_808023CC_chfactoryempspell[3] = {-2.5e+03f, 2.3e+02f, 3.3e+03f};
f32 D_808023D8_chfactoryempspell[3] = {-2.5e+03f, 1.35e+03f, 4.7e+03f};
f32 D_808023E4_chfactoryempspell[3] = {-2.5e+03f, 2.3e+02f, 4.7e+03f};
s32 D_808023F0_chfactoryempspell[3] = {0xC8, 0xC8, 0xFF};
s32 D_808023FC_chfactoryempspell[3] = {0x3C, 0x3C, 0x3C};
u8 D_80802408_chfactoryempspell[12] = {0x0, 0x13, 0x4,  0xC0, 0x0, 0x2,
                                       0x0, 0x16, 0x59, 0xD8, 0x0, 0x0};
int D_80802414_chfactoryempspell[19] = {0x15803EE,
                                        0x88A0001,
                                        0x0,
                                        (u32) func_80800000_chfactoryempspell,
                                        (u32) func_80105834,
                                        (u32) func_80800C7C_chfactoryempspell,
                                        0x1F400000,
                                        0x0,
                                        0x0,
                                        0x8020400,
                                        (u32) func_80801FE0_chfactoryempspell,
                                        0x0,
                                        0x70,
                                        0x0,
                                        (u32) func_80107C2C,
                                        -0x7FFFFBFE,
                                        (u32) func_80800630_chfactoryempspell,
                                        0x0,
                                        0x0};
