#include "common.h"

extern s32 D_80801404_choildrill[];
extern void _choildrill_entrypoint_0();
extern f32 func_800C6920(f32 *, f32, f32, s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 func_800D90A4(f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800DC0C0(void);
extern u8 D_8080149C_choildrill[];
extern u8 D_80801490_choildrill[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_80013970(f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EFE50(f32 *, void *, void *, f32);
extern void func_800DE498(void *, f32 *, f32 *, f32, s32, void *);
typedef struct { u8 pad[0x65]; u8 pad65:3; u8 flag:1; u8 rest:4; } DrillS;
extern void _chswitch_entrypoint_7(DrillS *, s32);
extern void _chswitch_entrypoint_9(DrillS *);
extern int D_808014F0_choildrill;
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct { f32 v[3]; } OilVector;
typedef struct { f32 time, speed; u8 event; u8 pad[3]; f32 volume; } OilKey;
typedef struct { void *marker; f32 position[3]; u8 pad10[8]; f32 origin[3]; f32 soundTimer; f32 field28, soundPeriod, field30, speed; u8 pad38[16]; f32 angle, field4C, phase, previousPhase, timer; u8 pad5C[22]; unsigned short state:6; unsigned short stateLow:10; u16 pad74; unsigned short key:9; unsigned short keyLow:7; unsigned flags78:8; unsigned bounces:4; unsigned flags79:20; unsigned flags7C:19; unsigned sparkle:1; unsigned flags7CLow:12; } OilActor;
extern OilVector D_80801300_choildrill;
extern OilKey D_8080130C_choildrill[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern s32 func_800D91EC(f32 *,f32);
extern void func_800EF214(f32 *,f32,f32,f32);
extern void func_800E0AFC(void *,s32,f32,f32,f32,f32);
extern void *func_8010262C(void *,s32);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern u8 D_8080138C_choildrill[];
extern f32 D_808013D0_choildrill[];
extern s32 D_80801398_choildrill[];
extern void func_800C4140();
extern s32 D_80801450_choildrill[];
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
void func_808007DC_choildrill(Actor *param_0, f32 param_1, s32 param_2);
int func_808009F8_choildrill();
void func_80800CF0_choildrill(Actor *param_0, u8 param_1, f32 param_2);

void func_80800000_choildrill(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];

    if (func_800EA05C() == 0x111) {
        if (func_800D0B68(0x42, 1)) {
            func_800FFAB0(param_0);
        } else if (func_800D0A9C(0x42, 1)) {
            func_808009F8_choildrill(param_0, 8);
        } else {
            func_808009F8_choildrill(param_0, 1);
        }
    } else {
        func_808009F8_choildrill(param_0, 2);
        if (func_800DA298(0x351)) {
            func_80103110(param_0, 0);
        } else {
            _subaddieskeleton_entrypoint_0(param_0, 0x2B, local_0);
            func_800EFA4C((f32 *)param_0->actorData, local_0[0], local_0[1] - 5000.0f, local_0[2]);
            func_800BEF00(local_0, (f32 *)param_0->actorData, local_1, 0);
        }
    }
}

void func_8080097C_choildrill();

void func_808008AC_choildrill();

void func_80800104_choildrill(OilActor *param_0)
{
    s32 local_4;
    s32 local_8;
    OilVector local_0;
    s32 local_9;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    void *local_10;
    f32 local_5;
    f32 local_6;
    s32 local_11;
    f32 local_12;
    s32 local_7;

    switch (param_0->state) {
    case 1:
        func_800FFAB0(param_0);
        break;
    case 4:
        local_4 = func_800D91EC(&param_0->timer, D_8080130C_choildrill[param_0->key].time);
        param_0->speed = func_800F10B4(param_0->timer,
            D_8080130C_choildrill[param_0->key - 1].time,
            D_8080130C_choildrill[param_0->key].time,
            D_8080130C_choildrill[param_0->key - 1].speed,
            D_8080130C_choildrill[param_0->key].speed) * 180.0f;
        if (param_0->timer > 3.0f) {
            func_808007DC_choildrill(param_0,
                func_800F10B4(param_0->speed, 0.0f, 180.0f, 0.2f, 0.5f), 1);
        }
        if (local_4) {
            if (D_8080130C_choildrill[param_0->key].event) {
                func_80800CF0_choildrill(param_0, D_8080130C_choildrill[param_0->key].event,
                    D_8080130C_choildrill[param_0->key].volume);
            }
            param_0->key++;
            if (D_8080130C_choildrill[param_0->key].time == -1.0f) {
                func_808009F8_choildrill(param_0, 5);
            }
        }
        break;
    case 5:
        if (func_800D90A4(&param_0->soundTimer)) {
            func_800C3F48(0x8CBB5BE9);
            param_0->soundTimer = param_0->soundPeriod = func_800DC178(0.4f, 0.5f);
        }
        func_800D90A4(&param_0->timer);
        func_808007DC_choildrill(param_0, 0.5f, 1);
        break;
    case 6:
        local_0 = D_80801300_choildrill;
        if (func_800D90A4(&param_0->timer)) {
            param_0->bounces--;
            if (param_0->bounces == 0) {
                func_800C3F48(0x7FFFFC09);
                func_808009F8_choildrill(param_0, 7);
                func_800EE7F8(param_0->position, param_0->origin);
            } else {
                func_800C3F48(0x7FFFFC0A);
                param_0->timer = 0.75f;
            }
            func_808008AC_choildrill(param_0->position);
        }
        if (param_0->bounces) {
            local_5 = func_800F10B4(param_0->timer, 0.75f, 0.0f, 0.25f, 0.0f);
            func_800EFE50(param_0->position, param_0->origin, local_0.v,
                func_800F10B4((f32)param_0->bounces - 1, 3.0f, 0.0f, 1.0f, 0.0f) + local_5);
            local_12 = func_800F10B4(param_0->timer, 0.75f, 0.0f, 0.0f, 180.0f);
            param_0->position[1] += func_80013970(local_12) * param_0->bounces * 50.0f;
        }
        break;
    case 7:
        func_8080097C_choildrill(param_0);
        break;
    case 8:
        func_8080097C_choildrill(param_0);
        break;
    case 9:
        param_0->speed = func_800F10B4(param_0->timer, 4.0f, 0.0f, 180.0f, 0.0f);
        if (func_800D90A4(&param_0->timer)) {
            func_808009F8_choildrill(param_0, 2);
            func_80103110(param_0, 0);
        }
        break;
    }
    if (*(u16 *)((u8 *)param_0->marker + 0x14) == 0x91F) {
        local_12 = func_800D8FF8();
        param_0->phase += param_0->speed * local_12;
        if (param_0->phase >= 360.0f) param_0->phase -= 360.0f;
        local_7 = (param_0->phase > 272.0f && param_0->previousPhase < 272.0f) ? 9 : 0;         local_8 = (param_0->phase > 92.0f && param_0->previousPhase < 92.0f) ? 5 : 0;         local_9 = (param_0->phase > 180.0f && param_0->phase < 270.0f) ? 2 : 0;         func_80800CF0_choildrill(param_0, local_9 | local_8 | local_7,
            func_800F10B4(param_0->speed, 0.0f, 180.0f, 0.8f, 1.1f));
        param_0->previousPhase = param_0->phase;
        local_10 = func_8010262C(param_0->marker, 2);
        if (local_10) {
            local_12 = func_80013970(param_0->phase);
            local_1 = func_800136E4(local_12 * 20.0f);
            local_2 = func_800136E4(-local_1);
            func_800E0AFC(local_10, 0x2A, -1.0f, local_1, 0.0f, 0.0f);
            func_800E0AFC(local_10, 0x2B, -1.0f, local_2, 0.0f, 0.0f);
        }
    } else {
        if (param_0->sparkle) {
            for (local_11 = 0; local_11 != 4; local_11++) {
                if (func_800DC0C0() < 0.015f) {
                    func_80103DFC(param_0, local_3);
                    local_6 = func_800DC178(0.0f, 360.0f);
                    func_800EF214(local_3, local_6,
                        func_800DC178(0.0f, 360.0f), 40.0f);
                    _fxtwinkle_entrypoint_2(local_3, 0x9E2);
                }
            }
        }
        local_12 = func_800D8FF8();
        param_0->angle += local_12 * 230.0f;
        param_0->angle = func_800136E4(param_0->angle);
    }
}

void func_808007DC_choildrill(Actor *param_0, f32 param_1, s32 param_2)
{
    if (param_2) {
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_8080138C_choildrill);
        _subaddieaudioloop_entrypoint_0(param_0, param_1);
        if (func_800DC0C0() < 0.4f) func_800BBCB8(D_808013D0_choildrill, 0, 1.0f, 1, D_80801398_choildrill);
    } else _subaddieaudioloop_entrypoint_2(param_0);
}

int choildrill_entrypoint_0(s32 param_0, unsigned int param_1)
{
  extern f32 D_808013DC_choildrill;
  func_800BBCB8(param_1, 0, 1.0f, 1, &D_808013DC_choildrill);
}

void func_808008AC_choildrill(f32 param_0[3])
{
    s32 local_1;
    f32 local_0;

    local_1 = func_800B53A4(8);
    local_0 = param_0[1];
    param_0[1] = func_800C6920(param_0, 200.0f, -200.0f, 0) + 5.0f;
    func_800BABB8(local_1, param_0, param_0, 1.0f, D_80801404_choildrill);
    func_800BA4D0(local_1, (s16)param_0[1]);
    func_800BA544(local_1, _choildrill_entrypoint_0);
    func_800BA22C(local_1, 8);
    choildrill_entrypoint_0(0, (u32)param_0);
    param_0[1] = local_0;
}

void func_8080097C_choildrill(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1;
    if (func_800D90A4(&param_0->unk58)) {
        func_800EE7F8(local_0, param_0->position);
        local_0[1] = func_800C6920(local_0, 200.0f, -200.0f, 0) + 5.0f;
        choildrill_entrypoint_0(0, local_0);
        local_1 = func_800DC0C0();
        param_0->unk58 = local_1 + local_1;
    }
}

void func_80800B90_choildrill();

int func_808009F8_choildrill(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0;
    switch (param_1) {
        case 1:
            func_80800B90_choildrill(param_0);
            *(u8 *)((u8 *)param_0 + 0x65) &= ~1;
            break;
        case 2:
            param_0->unk50 = 0.0f;
            param_0->unk54 = 0.0f;
            *(f32 *)((u8 *)param_0 + 0x34) = 0.0f;
            break;
        case 4:
            param_0->unk58 = 0.0f;
            _capod_entrypoint_13(param_0->unk0, 0, 0x54, 0x810);
            func_800C3F48(0x7FFFFD1C);
            param_0->unk74_7 = 1;
            break;
        case 5:
            func_800FC6B0(0x18);
            *(f32 *)((u8 *)param_0 + 0x34) = 180.0f;
            local_0 = func_800DC178(0.4f, 0.5f);
            *(f32 *)((u8 *)param_0 + 0x2C) = local_0;
            *(f32 *)((u8 *)param_0 + 0x24) = local_0;
            param_0->unk58 = 5.0f;
            break;
        case 6:
            func_800EE7F8(param_0->actorData, param_0->position);
            func_80800B90_choildrill(param_0);
            param_0->unk79_4 = 4;
            param_0->unk58 = 0.75f;
            break;
        case 7: param_0->unk58 = 2.0f * func_800DC0C0(); break;
        case 8:
            func_80800B90_choildrill(param_0);
            param_0->unk58 = 2.0f * func_800DC0C0();
            break;
        case 9:
            local_0 = 0.0f;
            *(f32 *)((u8 *)param_0 + 0x34) = 180.0f;
            param_0->unk58 = 4.0f;
            func_808007DC_choildrill(param_0, 0.0f, 0);
            break;
    }
    func_80102424(param_0, param_1);
}

void func_80800B90_choildrill(u8 **param_0) {
    func_8010A624();
    func_8010A590(param_0);
    func_80103140(param_0, 0x610, (*(u16 *)((s8 *)(*param_0) + (0x16))));
}

s32 func_80800BCC_choildrill(s32 *param_0, s32 param_1, s32 param_2) {
    switch (param_1) {                                 
    case 0xB:
        if (param_2 == 0x54) {
            func_808009F8_choildrill(param_0, 9);
            func_800D1000(0x42, 1, param_0 + 1, 3, 0);
            _glcutDll_entrypoint_6(0x111, 0x85);
        }
        return 3;
    case 0x49:
        if (param_2 == 0x85) {
            func_808009F8_choildrill(param_0, 6);
            _capod_entrypoint_13(*param_0, 0, 8, 0x900);
            return 1;
        }
        return 0;
    case 0x3D:
        _chjigsawcollect_entrypoint_1(&param_0, 0x42, 0);
        func_800FFAB0(param_0);
        return 1;
    case 0x3E:
        func_80108B04(param_0, 0);
        func_800D0BD4(0x42, 1);
        return 1;
    case 0xA:
        func_808009F8_choildrill(param_0, 4);
        return 1;
    default:
        return 0;
    }
}

void func_80800CF0_choildrill(Actor *param_0, u8 param_1, f32 param_2)
{
    if (param_1 & 4) {
        func_800C4140(((u16)(u32)(param_2 * 1023.0f) << 21) + 0x9C608, param_0->position, 0x12C000FA);
    }
    if (param_1 & 8) {
        func_800C4140(((u16)(u32)(param_2 * 1023.0f) << 21) + 0x9C609, param_0->position, 0x12C000FA);
    }
    if ((param_1 & 2) && *(f32 *)&param_0->actorData[7] > 135.0f && func_8001210C(1)) {
        func_800BBCB8((f32 *)param_0->actorData, (f32 *)param_0->actorData, 1.0f, 1, D_80801450_choildrill);
    }
}

void func_80800F08_choildrill(Actor *param_0, void *param_1)
{
    void *local_0;
    f32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_6;
    f32 local_5;
    func_80101870();
    if (param_0->unk70_10 == 5) {
        local_0 = func_800D674C(0x610);
        local_1 = func_800F10B4(param_0->unk58, 5.0f, 0.0f, 0.0f, 1.0f);
        func_800EFE50(local_2, D_80801490_choildrill, D_8080149C_choildrill, local_1);
        local_3[2] = 0.0f;
        local_3[0] = local_3[2];
        local_3[1] = local_1 * 360.0f;
        local_1 = func_800F10B4(((f32 *)param_0->actorData)[3], ((f32 *)param_0->actorData)[5], 0.0f, 0.0f, 1.0f);
        local_5 = func_800F10B4(((f32 *)param_0->actorData)[5], 0.5f, 0.4f, 300.0f, 200.0f);
        local_2[1] += func_80013970(180.0f * local_1) * local_5;
        local_5 = func_800DC178(0.0f, 360.0f);
        local_6 = func_800DC178(0.0f, 360.0f);
        func_800EEC30(local_4, local_5, local_6, 40.0f);
        func_800EF04C(local_4, local_2);
        _fxtwinkle_entrypoint_0(local_4);
        func_800DF830(1);
        func_800DE498(param_1, local_2, local_3, 1.0f, 0, local_0);
    }
}

int choildrill_entrypoint_1()
{
    extern int D_808014A8_choildrill;
    return (int)&D_808014A8_choildrill;
}

void func_808010C0_choildrill(DrillS *param_0) {
    _chswitch_entrypoint_7(param_0, 0x351);
    _chswitch_entrypoint_9(param_0);
    param_0->flag = func_800DA298(0x351);
}

s32 func_80801110_choildrill(Actor *param_0, s32 param_1, s32 param_2)
{
  if (param_1 != 7) {
    if (param_1 == 0x91) {
      if (func_800F6B94(func_800F54E4()) != 0) {
        if (!param_0->unk74_29 && (func_800DA298(0x351) == 0)) {
          _subaddiedialog_entrypoint_11(param_0->unk0, 0x12BE, 0xC, (u8 *)param_0 + 4, 0x6F);
          param_0->unk74_29 = 1;
          return _chswitch_entrypoint_10(param_0, param_1, param_2);
        }
      } else if (!param_0->unk74_30 && (func_800DA298(0x351) == 0)) {
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x12BD, 4, (u8 *)param_0 + 4, 0x6F);
        param_0->unk74_30 = 1;
      }
      return 0;
    }
  } else {
    func_80101180(0x484, 0xA, 0);
  }
  return _chswitch_entrypoint_10(param_0, param_1, param_2);
}

int *choildrill_entrypoint_2()
{
    return &D_808014F0_choildrill;
}
