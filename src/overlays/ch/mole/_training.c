#include "common.h"

typedef struct { u8 pad[0x72]; u16 f72:6; u16 rest:10; } MoleS;
extern void _gcnewoption_entrypoint_1(void *, s32);
extern void _gcnewoption_entrypoint_32(void *, s16);
extern void _gcnewoption_entrypoint_31(void *, s32, s16);
extern void *func_80100094(Actor *, u32);
extern void _chmole_training_entrypoint_0(void);
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern int D_80800F30_chmole_training;
extern u8 D_80800E34_chmole_training[];
extern u8 D_80800E32_chmole_training[];
extern s32 _sumole_entrypoint_6(Actor *, s32, f32);
typedef struct MoleTrainingState { u8 pad_0[0x72]; u8 local_0 : 6; u8 pad_1 : 2; } MoleTrainingState;
extern s16 D_80800F08_chmole_training[];
extern s16 D_80800F10_chmole_training[];
extern s16 D_80800F18_chmole_training[];
extern s16 D_80800F20_chmole_training[];
extern s16 D_80800F24_chmole_training[];
extern s16 D_80800F28_chmole_training[];
extern s16 D_80800F2C_chmole_training[];
extern Actor *func_80106790(Unk80132ED0 *);
void func_80800270_chmole_training();
void func_808003D4_chmole_training();
void func_80800A48_chmole_training();
void func_80800BA8_chmole_training();

s32 func_80800000_chmole_training(Actor *this) {
    if (func_80100094(this, 0)) {
        _gcnewoption_entrypoint_6(this, 0);
    }
}

void func_80800034_chmole_training(MoleS *param_0, s32 param_1) {
    u32 local_0 = param_0->f72;
    if (local_0 == 5 || local_0 == 7 || local_0 == 6) {
        _gcnewoption_entrypoint_1(func_80100094(param_0, 0), param_1);
    }
}

void func_80800C3C_chmole_training();

void func_80800C28_chmole_training();

void func_80800088_chmole_training(Actor *param_0)
{
    s32 local_0;
    if (param_0->unk3C != NULL) {
        switch (param_0->unk70_10) {
            case 1:
                func_80800270_chmole_training(param_0);
                break;
            case 2:
                func_808003D4_chmole_training(param_0);
                break;
            case 3:
                *((u8 *)param_0 + 0x72) = (*((u8 *)param_0 + 0x72) & 0xFF03) | 0x10;
                break;
            case 4:
                func_80800A48_chmole_training(param_0);
                break;
            case 5:
                _gcnewoption_entrypoint_0(func_80100094(param_0, 0));
                break;
            case 7:
                _gcnewoption_entrypoint_6(param_0, 0);
                local_0 = *(s8 *)(D_80800E34_chmole_training + (s32)param_0->unk54 * 8);
                if (local_0 != -1 && !func_800C6E38(local_0)) {
                    func_80101FDC(param_0, 8);
                    return;
                }
                func_80101FDC(param_0, 10);
                break;
            case 6:
                _gcnewoption_entrypoint_6(param_0, 0);
                func_80101FDC(param_0, 11);
                break;
            case 10:
                if (_sumole_entrypoint_17(param_0,
                    *(s16 *)(D_80800E32_chmole_training + (s32)param_0->unk54 * 8), -1, 0)) {
                    _sumole_entrypoint_19(param_0, 0);
                    func_80101FDC(param_0, 12);
                }
                break;
            case 9:
                func_80800BA8_chmole_training(param_0);
                break;
            case 11:
                func_80800C28_chmole_training(param_0);
                break;
            case 12:
                func_80800C3C_chmole_training(param_0);
                break;
            case 13:
                _sumole_entrypoint_19(param_0, 0);
                *((u8 *)param_0 + 0x72) = (*((u8 *)param_0 + 0x72) & 0xFF03) | 0x30;
                break;
        }
    }
}

void func_80800270_chmole_training(param_0) Actor *param_0;
{
    switch ((u32)param_0->unk54) {
        case 6:
            if (!func_800DA298(0x53)) {
                if (_sumole_entrypoint_6(param_0, -1, 350.0f)) func_80101FDC(param_0, 2);
            } else if ((func_8008FD70() & 0x701) && _sumole_entrypoint_1(param_0, -1, 0, 0)) {
                func_80101FDC(param_0, 2);
            }
            break;
        case 0: case 1: case 2: case 3: case 4: case 5: case 7:
            if ((func_8008FD70() & 0x701) && _sumole_entrypoint_1(param_0, -1, 0, 0)) func_80101FDC(param_0, 2);
            break;
    }
}

void func_808003D4_chmole_training(param_0) Actor *param_0;
{
    switch ((u32)param_0->unk54) {
        case 6:
            if (!func_800DA298(0x53)) {
                func_800DA3B8(0x53, 1);
            }
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
            _sumole_entrypoint_19(param_0, 3);
            ((MoleTrainingState *)param_0)->local_0 = 3;
            break;
    }
}

volatile int func_808004D0_chmole_training(Actor *param_0, u32 param_1)
{
  u32 local_0 = param_1 | 0U;
  switch ((u32)param_0->unk54)
  {
    case 1:
      _gcnewoption_entrypoint_12(local_0, 0, 0xa);
      _gcnewoption_entrypoint_12(local_0, 1, 0x15);
      _gcnewoption_entrypoint_12(local_0, 2, 0x16);
      break;

    case 2:
      _gcnewoption_entrypoint_12(local_0, 0, 0xb);
      _gcnewoption_entrypoint_12(local_0, 1, 0xc);
      _gcnewoption_entrypoint_12(local_0, 2, 0x1a);
      break;

    case 4:
      _gcnewoption_entrypoint_12(local_0, 0, 0x17);
      _gcnewoption_entrypoint_12(local_0, 1, 0x18);
      _gcnewoption_entrypoint_12(local_0, 2, 0x19);
      break;

    case 0:
      _gcnewoption_entrypoint_12(local_0, 0, 0x14);
      _gcnewoption_entrypoint_12(local_0, 1, 0xd);
      break;

    case 3:
      _gcnewoption_entrypoint_12(local_0, 0, 0xe);
      _gcnewoption_entrypoint_12(local_0, 1, 0xf);
      break;

    case 7:
      _gcnewoption_entrypoint_12(local_0, 0, 0x10);
      _gcnewoption_entrypoint_12(local_0, 1, 0x11);
      break;

    case 5:
      _gcnewoption_entrypoint_12(local_0, 0, 0x12);
      _gcnewoption_entrypoint_12(local_0, 1, 0x13);
  }

}

void chmole_training_entrypoint_0(Unk80132ED0 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    Actor *local_0;

    local_0 = func_80106790(param_0);
    switch (param_3) {
    case 3:
        switch ((u32)local_0->unk54) {
        case 1: local_0->unk54 = D_80800F08_chmole_training[param_2]; break;
        case 2: local_0->unk54 = D_80800F10_chmole_training[param_2]; break;
        case 4: local_0->unk54 = D_80800F18_chmole_training[param_2]; break;
        case 0: local_0->unk54 = D_80800F20_chmole_training[param_2]; break;
        case 3: local_0->unk54 = D_80800F24_chmole_training[param_2]; break;
        case 7: local_0->unk54 = D_80800F28_chmole_training[param_2]; break;
        case 5: local_0->unk54 = D_80800F2C_chmole_training[param_2]; break;
        }
        func_80101FDC(local_0, 7);
        break;
    case 0:
        func_808004D0_chmole_training(local_0, param_1);
        break;
    case 2:
        func_80101FDC(local_0, 6);
        break;
    }
}

void func_808008E4_chmole_training(Actor *param_0, void *param_1, s32 param_2)
{
    s32 local_0;
    _gcnewoption_entrypoint_32(param_1, func_800DA298(0x578) ? 0xF : 0x9E);
    for (local_0 = 0; local_0 < param_2; local_0++) {
        _gcnewoption_entrypoint_31(param_1, local_0, (local_0 & 1) ? 0xD : 0xC);
    }
}

void func_80800988_chmole_training(Actor *param_0, s32 param_1, s32 param_2)
{
    void *local_0;

    _gcnewoption_entrypoint_4(param_0, 0, _chmole_training_entrypoint_0, 0, 0x184A);
    local_0 = func_80100094(param_0, 0);
    _gcnewoption_entrypoint_8(local_0, param_1);
    _gcnewoption_entrypoint_9(local_0, param_2);
    _gcnewoption_entrypoint_10(local_0, 0);
    func_808008E4_chmole_training(param_0, local_0, param_2);
    _gcnewoption_entrypoint_14(local_0, 0, 1, 3, 4.0f);
    _gcnewoption_entrypoint_11(local_0);
    func_80101FDC(param_0, 5);
}

void func_80800A48_chmole_training(param_0) Actor *param_0;
{
    switch ((u32)param_0->unk54) {
        case 1: func_80800988_chmole_training(param_0, 3, 3); break;
        case 2: func_80800988_chmole_training(param_0, 3, 3); break;
        case 4: func_80800988_chmole_training(param_0, 3, 3); break;
        case 0: func_80800988_chmole_training(param_0, 2, 2); break;
        case 3: func_80800988_chmole_training(param_0, 2, 2); break;
        case 7: func_80800988_chmole_training(param_0, 2, 2); break;
        case 5: func_80800988_chmole_training(param_0, 2, 2); break;
        case 6: func_80101FDC(param_0, 4); break;
        case 10: case 11: case 12: case 13: case 14: case 15:
        case 16: case 17: case 18: case 19: case 20: case 21:
        case 22: case 23: case 24: case 25: case 26:
            func_80101FDC(param_0, 4);
            break;
    }
}

void func_80800BA8_chmole_training(param_0) Actor *param_0;
{
    switch ((s32)param_0->unk54) {
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
        param_0->unk54 = (s32)param_0->rotation[1];
        param_0->unk70_10 = 4;
        break;
    default:
        param_0->unk70_10 = 11;
        break;
    }
}

void func_80800C28_chmole_training(u8 *param_0) {
    param_0[0x72] = (u8)((param_0[0x72] & 0xFF03) | 0x34);
}

void func_80800C3C_chmole_training(u8 *param_0)
{
  *((f32 *) (&param_0[0x54])) = (f32) ((s32) (*((f32 *) (&param_0[0x48]))));
  param_0[0x72] = (param_0[0x72] & 0xFF03) | 4;
}

void func_80800C70_chmole_training(Actor *param_0)
{
    *(f32 *)((char *)param_0 + 0x54) = (f32)(s32)*(f32 *)((char *)param_0 + 0x48);
    _sumole_entrypoint_0(param_0, 1);
}

int chmole_training_entrypoint_1()
{
    return (int)&D_80800F30_chmole_training;
}
