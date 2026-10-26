#include "common.h"

extern void func_800DBE60(u8, s32, s32);
extern int D_808015B4_chfiregen;
extern int D_808015FC_chfiregen;
extern int D_80801644_chfiregen;
extern s32 D_8080168C_chfiregen[];
extern int D_808016D4_chfiregen;
extern int D_8080171C_chfiregen;
typedef struct { u8 pad_0[0x72]; u8 local_0 : 6; u8 pad_1 : 2; } FireGeneratorMode;
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
extern int D_808017BC_chfiregen;
extern s32 D_80801804_chfiregen[];
extern int D_8080184C_chfiregen;
extern int D_80801894_chfiregen;
extern int D_808018DC_chfiregen;
extern s32 D_80801924_chfiregen[];
extern int D_8080196C_chfiregen;
extern int D_808019B4_chfiregen;
extern int D_808019FC_chfiregen;
extern int D_80801A44_chfiregen[];
extern s32 D_80801A8C_chfiregen[];
extern void *D_80801AD4_chfiregen;
extern void *_idworld_entrypoint_3(s32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800DC0C0(void);
extern void func_80101CDC(Actor *, f32);
extern s32 func_80101E14(Actor *, f32);
extern void func_800C31DC(u8, f32);
extern s32 func_800C4350();
extern f32 func_800D9004(void);
extern f32 func_80101D0C(Actor *);
extern u8 D_80801784_chfiregen[];
extern void *func_800B53A4(s32);
extern void *func_800BABB8(void *, f32 *, f32 *, f32, void *);
extern f32 func_800D8FF8(void);
extern void func_800EDDDC(void *, f32 *, f32 *, f32);
void func_80800978_chfiregen();
s32 func_80800824_chfiregen();
s32 func_80800890_chfiregen();
void func_80800B4C_chfiregen();

s32 func_80800000_chfiregen(Actor *param_0, s32 param_1, void *param_2)
{
    u8 local_0;
    switch (param_1) {
    case 0x1F:
        local_0 = func_800D731C(param_0->unk0->unk14);
        func_801015D0(param_0);
        if (local_0) func_800DBE60(local_0, 0, param_0->unk79_4);
        break;
    case 0x40:
        func_80800978_chfiregen(param_0, (*(void * *)&param_2));
        break;
    default: return 0;
    }
    return 1;
}

int chfiregen_entrypoint_0()
{
    return &D_808015B4_chfiregen;
}

int chfiregen_entrypoint_1()
{
  return (int)&D_808015FC_chfiregen;
}

int chfiregen_entrypoint_2()
{
    return &D_80801644_chfiregen;
}

int chfiregen_entrypoint_3()
{
    return (int)D_8080168C_chfiregen;
}

int chfiregen_entrypoint_4()
{
  return (int)&D_808016D4_chfiregen;
}

int *chfiregen_entrypoint_5()
{
    return &D_8080171C_chfiregen;
}

void func_808008F4_chfiregen();

void func_808000EC_chfiregen(Actor *param_0)
{
    extern u8 D_80801570_chfiregen[];
    extern s16 D_80801580_chfiregen[];

    f32 local_1;
    f32 local_0;
    s32 local_2;
    s32 local_3;

    local_0 = func_800D9004();

    _sudeflect_entrypoint_1(
        param_0->position,
        80.0f,
        0,
        75.0f,
        10
    );

    if (param_0->unk64_19) {
        ((f32 *)param_0->actorData)[0] -= local_0;

        if (((f32 *)param_0->actorData)[0] < 0.0f) {
            ((f32 *)param_0->actorData)[0] = 0.0;
            param_0->unk64_19 = 0;
        }
    } else {
        ((f32 *)param_0->actorData)[0] += local_0;

        if (((f32 *)param_0->actorData)[0] > 0.3f) {
            ((f32 *)param_0->actorData)[0] = 0.3f;
            param_0->unk64_19 = 1;
        }
    }

    param_0->unk79_4 = (s32)func_800F10B4(
        ((f32 *)param_0->actorData)[0],
        0.0,
        0.3f,
        0.0f,
        4.49f
    );

    if (local_0 < param_0->unk58) {
        param_0->unk58 -= local_0;
    } else {
        param_0->unk58 = 0.0f;
        ((f32 *)param_0->actorData)[5] = 0.0f;
    }

    param_0->unk6C_0++;

    switch (param_0->unk70_10) {
    case 2:
        if (((f32 *)param_0->actorData)[6] <= 0.95f) {
            ((f32 *)param_0->actorData)[6] += 0.05f;
        }

        if (((f32 *)param_0->actorData)[7] <= (1.0f - 0.16f)) {
            ((f32 *)param_0->actorData)[7] += 0.16f;
        }

        param_0->unk54 += 0.0075f;

        if (param_0->unk54 > (f32)1.0) {
            param_0->unk54 = 1.0;
        }

        if (param_0->unk54 < 0.6f) {
            param_0->unk54 = 0.6f;
        }

        if (param_0->unk5F == 0) {
            param_0->unk5F = func_800C4350(
                0,
                param_0->position,
                D_80801580_chfiregen
            );

        }

        func_800C31DC(
            param_0->unk5F,
            param_0->unk54
        );

        func_800C4350(param_0->unk5F, 0, 0);

        if (param_0->unk58 <= 0.0f) {
            _subaddieaudioloop_entrypoint_2(param_0);
            func_808008F4_chfiregen((s32 *)param_0, 0);

            param_0->unk70_10 = 1;
        }

        if (func_800DC0C0() < 0.005f) {
            param_0->unk70_10 = 3;

            param_0->rotation[0] = 1.0f;

            func_808008F4_chfiregen((s32 *)param_0, 0);
            func_80101CDC(param_0, 0.7f);
        }

        if (func_800DC0C0() < 0.08f &&
            func_80101E14(param_0, 0.1f)) {
            func_80800B4C_chfiregen(param_0, 3);

            _subaddieaudioquick_entrypoint_2(
                param_0,
                param_0->position,
                D_80801570_chfiregen
            );
        }

        if (func_800DC0C0() < 0.25f) {
            func_80800B4C_chfiregen(param_0, 1);
        }
        break;
    case 1:
        if (((f32 *)param_0->actorData)[6] > 0.02f) {
            ((f32 *)param_0->actorData)[6] -= 0.02f;
        }

        if (((f32 *)param_0->actorData)[7] >= 0.16f) {
            ((f32 *)param_0->actorData)[7] -= 0.16f;
        }

        if (param_0->unk58 != 0.0f) {
            func_808008F4_chfiregen((s32 *)param_0, 1);

            param_0->unk70_10 = 2;

            func_80101CDC(param_0, 0.4f);
            param_0->unk54 = 0.6f;
        }

        local_1 = func_80101D0C(param_0);

        if (local_1 != 10000000.0f) {
            param_0->unk54 -= 0.02f;

            if (param_0->unk54 < 0.6f) {
                param_0->unk54 = 0.6f;
            }

            if (param_0->unk5F == 0) {
                param_0->unk5F = func_800C4350(
                    0,
                    param_0->position,
                    D_80801580_chfiregen
                );

            }
            func_800C31DC(
                param_0->unk5F,
                param_0->unk54
            );

            func_800C4350(param_0->unk5F, 0, 0);

            local_1 += func_800DC178(0.05f, 0.15f);

            if (local_1 > 4.0f) {
                func_80800B4C_chfiregen(param_0, 3);

                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    param_0->position,
                    D_80801570_chfiregen
                );

                local_1 = 10000000.0f;

                _subaddieaudioloop_entrypoint_2(param_0);
            }

            func_80101CDC(param_0, local_1);
        }
        break;
    case 3:
        if (((f32 *)param_0->actorData)[6] > 0.02f) {
            ((f32 *)param_0->actorData)[6] -= 0.02f;
        }

        if (((f32 *)param_0->actorData)[7] >= 0.16f) {
            ((f32 *)param_0->actorData)[7] -= 0.16f;
        }

        if (func_800DC0C0() < 0.03f &&
            func_80101E14(param_0, 0.1f)) {
            _subaddieaudioquick_entrypoint_2(
                param_0,
                param_0->position,
                D_80801570_chfiregen
            );
        }

        if (param_0->unk54 < 0.6f) {
            param_0->unk54 = 0.6f;
        }

        if (param_0->unk5F == 0) {
            param_0->unk5F = func_800C4350(
                0,
                param_0->position,
                D_80801580_chfiregen
            );

        } else {
            func_800C31DC(
                param_0->unk5F,
                param_0->unk54 - 0.2f
            );

            func_800C4350(param_0->unk5F, 0, 0);
        }

        param_0->unk70_10 = 2;

        func_808008F4_chfiregen((s32 *)param_0, 1);
        break;
    }

    if (param_0->rotation[2] != ((f32 *)param_0->actorData)[6] &&
        (s32)param_0->unk50 != -1) {
        if (((f32 *)param_0->actorData)[3] < 0.0f) {
            param_0->rotation[2] = ((f32 *)param_0->actorData)[6];
            ((f32 *)param_0->actorData)[3] = 0.25f;
        } else {
            ((f32 *)param_0->actorData)[3] -= local_0;
        }
    }

    if (((f32 *)param_0->actorData)[7] > 0.02f) {
        local_2 = func_801039E4(
            param_0->unk0
        );

        local_3 = func_80103CB8(param_0, local_2);

        _dbmorph_entrypoint_3(
            func_800B2768(local_2),
            local_3,
            func_800B2840(local_2),
            1,
            &((f32 *)param_0->actorData)[7]
        );
    }
}

s32 func_80800824_chfiregen(param_0) Actor *param_0;
{
    switch (param_0->unk6C_9) {
    case 0x1AA: return 0;
    case 0x1AC: return 1;
    case 0x1AE: return 2;
    case 0x1B0: return 3;
    case 0x1B2: return 4;
    case 0x1B4: return 5;
    }
    return 0;
}

s32 func_80800890_chfiregen(param_0) Actor *param_0;
{
    switch (param_0->unk6C_9) {
    case 0x1AA:
        return 0;
    case 0x1AC:
        return 5;
    case 0x1AE:
        return 8;
    case 0x1B0:
        return 11;
    case 0x1B2:
        return 15;
    default:
        return -1;
    }
}

void func_808008F4_chfiregen(s32 *param_0, s32 param_1) {
    s32 local_1;

    func_800DA3B8(func_80800824_chfiregen((Actor *)param_0), param_1);
    if ((param_1 != 0) && (func_800DA298(0x678) == 0)) {
        local_1 = func_80800890_chfiregen(param_0);
        if (local_1 != -1) {
            func_800DA3B8(0x678, 1);
            _capod_entrypoint_13(*param_0, 0, local_1, 0x10);
        }
    }
}

void func_80800978_chfiregen(param_0, param_1) Actor *param_0; void *param_1;
{
    if ((*(u32 *)((u8 *)param_1 + 0x24) >> 22) == 0x26D) {
        if ((s32)*(f32 *)&param_0->actorData[5] == 0) {
            param_0->unk6C_0 = 0;
        }
        if ((s32)*(f32 *)&param_0->actorData[5] < 2) {
            *(f32 *)&param_0->actorData[5] += 1.0f;
            param_0->unk58 = (s32)param_0->unk74_7 - 50;
        } else if ((s32)*(f32 *)&param_0->actorData[5] == 2) {
            *(f32 *)&param_0->actorData[5] += 1.0f;
            if (param_0->unk6C_0 < 40) {
                func_800FC63C(14, 0x7FBC);
                param_0->unk58 = ((s32)param_0->unk74_7 - 50) * 1.5f;
            }
        }
    }
}

void func_80800A78_chfiregen(Actor *param_0)
{
    param_0->scale = 3.0f;
    param_0->unk50 = -1.0f;
    param_0->unk64_20 = 0;
    ((f32 *)param_0->actorData)[3] = func_800DC178(0.0f, 0.25f);
    ((f32 *)param_0->actorData)[0] = func_800DC178(0.0f, 1.0f);
    param_0->unk64_19 = func_800DC298(0.5f);
    if (func_800DA298(func_80800824_chfiregen(param_0))) {
        param_0->unk58 = (s32)param_0->unk74_7 - 0x32;
        ((FireGeneratorMode *)param_0)->local_0 = 2;
    }
}

void func_80800B4C_chfiregen(param_0, param_1) Actor *param_0; s32 param_1;
{
    void *local_0;
    f32 local_1[3];

    if (param_0->unk7C_12) {
        func_800DBEFC(param_0->unk0->unk4, 4, local_1);
        local_1[1] -= 100.0f;
        local_0 = func_800B53A4(param_1);
        func_800BA3FC(local_0, func_800DC298(0.7f) ? 0x9DC : 0x9CA);
        func_800BABB8(local_0, local_1, NULL, 1.0f, D_80801784_chfiregen);
        func_800BA22C(local_0, param_1);
    }
}

void *chfiregen_entrypoint_6(void)
{
    return &D_808017BC_chfiregen;
}

s32 chfiregen_entrypoint_7()
{
    return D_80801804_chfiregen;
}

int chfiregen_entrypoint_8()
{
    return (int)&D_8080184C_chfiregen;
}

int *chfiregen_entrypoint_9()
{
    return &D_80801894_chfiregen;
}

int chfiregen_entrypoint_10()
{
    return (int)&D_808018DC_chfiregen;
}

s32 chfiregen_entrypoint_11()
{
    return D_80801924_chfiregen;
}

void func_80800C44_chfiregen(Actor *param_0)
{
    f32 local_1;
    s32 local_2;
    s32 local_0[3];

    local_1 = func_800D8FF8();
    if (*(f32 *)&param_0->actorData[3] > 0.0f) {
        *(f32 *)&param_0->actorData[3] -= local_1;
        return;
    }
    if (func_800DA298(param_0->unk6C_0)) {
        if (param_0->unk70_10 != 3) {
            param_0->unk70_10 = 2;
        }
    } else {
        if (param_0->unk70_10 != 1) {
            param_0->unk70_10 = 4;
        }
    }
    switch (param_0->unk70_10) {
    case 2:
        if (*(f32 *)&param_0->actorData[6] <= 0.85f) {
            *(f32 *)&param_0->actorData[6] += 0.15f;
        } else {
            param_0->unk70_10 = 3;
        }
        break;
    case 4:
        if (*(f32 *)&param_0->actorData[6] >= 0.08f) {
            *(f32 *)&param_0->actorData[6] -= 0.08f;
        } else {
            param_0->unk70_10 = 1;
        }
        break;
    }
    if (param_0->rotation[2] != *(f32 *)&param_0->actorData[6]) {
        for (local_2 = 0; local_2 < 3; local_2++) {
            local_0[local_2] = (s32)(((f32 *)param_0->actorData)[local_2] * *(f32 *)&param_0->actorData[6]);
        }
        func_800C8E84((s32)param_0->unk50, local_0);
        param_0->rotation[2] = *(f32 *)&param_0->actorData[6];
        *(f32 *)&param_0->actorData[3] = 0.15f;
    }
}

void func_80800E54_chfiregen(Actor *param_0)
{
  f32 local_0[3];
  if ((s32) param_0->unk50 != -1)
  {
    func_800EE904(local_0, (u8 *)param_0 + 0x18);
    func_800C8E84((s32) param_0->unk50, local_0);
  }
}

void func_80800EB8_chfiregen(Actor *param_0)
{
    s32 local_0;
    f32 local_1[3];
    s32 local_2[3];

    *(f32 *)&param_0->actorData[3] = func_800DC178(0.0f, 0.15f);
    param_0->unk50 = -1.0f;
    switch (param_0->unk6C_9) {
        case 0x1AB: param_0->unk6C_0 = 0; break;
        case 0x1AD: param_0->unk6C_0 = 1; break;
        case 0x1AF: param_0->unk6C_0 = 2; break;
        case 0x1B1: param_0->unk6C_0 = 3; break;
        case 0x1B3: param_0->unk6C_0 = 4; break;
        case 0x1B5: param_0->unk6C_0 = 5; break;
    }
    local_0 = func_800C9128(param_0->position);
    param_0->unk50 = (f32)local_0;
    func_800C8800(local_0, local_1);
    func_800EE7F8((f32 *)param_0->actorData, local_1);
    func_800C8900(local_0, local_2);
    func_800EE84C((f32 *)param_0->actorData, local_2);
    func_800EFA88(local_2, 0, 0, 0);
    func_800C8E84((s32)param_0->unk50, local_2);
}

int chfiregen_entrypoint_12()
{
    return &D_8080196C_chfiregen;
}

int chfiregen_entrypoint_13()
{
  return (int)&D_808019B4_chfiregen;
}

int chfiregen_entrypoint_14()
{
    return (int)&D_808019FC_chfiregen;
}

int chfiregen_entrypoint_15()
{
    return (int)D_80801A44_chfiregen;
}

int chfiregen_entrypoint_16()
{
    return (int)D_80801A8C_chfiregen;
}

int chfiregen_entrypoint_17()
{
  return &D_80801AD4_chfiregen;
}

void *func_8080105C_chfiregen(u8 *param_0)
{
    s32 sp1C;
    u32 temp_t7;

    temp_t7 = (u32) ((*(s32 *)((s8 *)param_0 + 0x6C)) << 0xB) >> 0x14;
    switch (temp_t7) {
    case 0x2AA:
        sp1C = 0x1AD;
        break;
    case 0x2AB:
        sp1C = 0x1AE;
        break;
    }
    return _idworld_entrypoint_3(sp1C);
}

void *func_808010B4_chfiregen(void *param_0)
{
    s32 sp1C;
    u32 temp_t7;

    temp_t7 = (u32) ((*(s32 *)((s8 *)param_0 + 0x6C)) << 0xB) >> 0x14;
    switch (temp_t7) {
    case 0x2AA:
        sp1C = 0x1B0;
        break;
    case 0x2AB:
        sp1C = 0x1B1;
        break;
    }
    return _idworld_entrypoint_3(sp1C);
}

void func_8080110C_chfiregen(Actor *param_0)
{
    f32 local_0;
    void *local_2;
    f32 local_1[4];

    local_0 = func_800D8FF8();
    if (((f32 *)param_0->actorData)[3] > 0.0f) {
        ((f32 *)param_0->actorData)[3] -= local_0;
    } else {
        if (func_800DA298(param_0->unk6C_0)) {
            if (param_0->unk70_10 != 3) {
                param_0->unk70_10 = 2;
            }
        } else if (param_0->unk70_10 != 1) {
            param_0->unk70_10 = 4;
        }
        switch (param_0->unk70_10) {
        case 2:
            if (((f32 *)param_0->actorData)[6] <= 0.85f) {
                ((f32 *)param_0->actorData)[6] += 0.15f;
            } else {
                param_0->unk70_10 = 3;
            }
            break;
        case 4:
            if (((f32 *)param_0->actorData)[6] >= 0.08f) {
                ((f32 *)param_0->actorData)[6] -= 0.08f;
            } else {
                param_0->unk70_10 = 1;
            }
            break;
        }
        if (param_0->rotation[2] != ((f32 *)param_0->actorData)[6]) {
            local_1[0] = ((f32 *)param_0->actorData)[6];
            local_1[1] = ((f32 *)param_0->actorData)[6];
            local_1[2] = ((f32 *)param_0->actorData)[6];
            local_1[3] = ((f32 *)param_0->actorData)[6];
            local_2 = func_8080105C_chfiregen(param_0);
            if (local_2) {
                func_800EDDDC(local_2, local_1, local_1, 5.0f);
            }
            local_2 = func_808010B4_chfiregen(param_0);
            if (local_2) {
                func_800EDDDC(local_2, local_1, local_1, 5.0f);
            }
            param_0->rotation[2] = ((f32 *)param_0->actorData)[6];
            ((f32 *)param_0->actorData)[3] = 0.15f;
        }
    }
}

void func_808012F8_chfiregen(s32 arg0) 
{
}
void func_80801300_chfiregen(Actor *param_0)
{
    void *local_1;
    f32 local_0[4];

    local_0[0] = *(f32 *)((u8 *)param_0 + 0x30);
    local_0[1] = *(f32 *)((u8 *)param_0 + 0x30);
    local_0[2] = *(f32 *)((u8 *)param_0 + 0x30);
    local_0[3] = *(f32 *)((u8 *)param_0 + 0x30);
    *(f32 *)((u8 *)param_0 + 0x24) = func_800DC178(0.0f, 0.15f);
    switch (param_0->unk6C_9) {
        case 0x2A7: param_0->unk6C_0 = 0; break;
        case 0x2A8: param_0->unk6C_0 = 1; break;
        case 0x2A9: param_0->unk6C_0 = 2; break;
        case 0x2AA: param_0->unk6C_0 = 3; break;
        case 0x2AB: param_0->unk6C_0 = 4; break;
        case 0x2AC: param_0->unk6C_0 = 5; break;
    }
    local_1 = (void *)func_8080105C_chfiregen(param_0);
    if (local_1) func_800EDDDC(local_1, local_0, local_0, 5.0f);
    local_1 = (void *)func_808010B4_chfiregen(param_0);
    if (local_1) func_800EDDDC(local_1, local_0, local_0, 5.0f);
}
