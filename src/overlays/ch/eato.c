#include "common.h"
#include "gc/newoption.h"
#include "gc/newoption.h"

extern int D_80800E98_chcheato;
extern s32 D_80800E50_chcheato;
extern int func_800EB854(void);
extern void func_80101870(Actor *, s32);
extern s32 D_80800EE0_chcheato;
extern s16 D_80800EE6_chcheato;
extern s16 D_80800EF4_chcheato;
typedef struct { f32 local_0[2]; } CheatoSoundTimes;
typedef struct { s16 local_0[2]; } CheatoSoundIds;
extern CheatoSoundTimes D_80800EFC_chcheato;
extern CheatoSoundIds D_80800F04_chcheato;
extern s16 D_80800F08_chcheato[];
extern s32 func_80101E14(Actor *, f32);
extern void func_800D3EF4();
extern s32 _gcnewoption_entrypoint_17(s32, u32);
typedef struct { s16 local_0[3]; } CheatoOptionDescriptor;
extern CheatoOptionDescriptor D_80800F20_chcheato;
extern CheatoOptionDescriptor D_80800F28_chcheato;
extern u8 _gcnewoption_entrypoint_35[];
extern u8 _gcnewoption_entrypoint_16[];
extern u8 unk6A[];
extern void _capod_entrypoint_3(int param_0, Actor *param_1);
typedef struct { int unk6C; int unk6E; } ChcheatoState;
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern f32 func_8010CD28(Actor *);
extern void func_80102B2C(Actor *, f32);
s32 func_80800824_chcheato();
int func_80800AB4_chcheato();
s32 func_80800BB8_chcheato();
int func_80800C0C_chcheato();
int func_80800C64_chcheato();
void func_80800D08_chcheato();
void func_80800434_chcheato();
void func_8080098C_chcheato();

int *chcheato_entrypoint_0()
{
    return &D_80800E98_chcheato;
}

s32 func_8080000C_chcheato(Actor *this){
    _subaddieitem_entrypoint_0(func_80100094(this, 1), 0x4E3, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(this, 1), 0x5);
    func_8010A828(this, 0x9);
}

void func_80800CC0_chcheato();

void func_80800B00_chcheato();

void func_8080078C_chcheato();

void func_808006B8_chcheato();

void func_808003C4_chcheato();

void func_80800068_chcheato(Actor *param_0)
{
    f32 local_0[3];
    _sudeflect_entrypoint_0(param_0->position, 150.0f, 150.0f, 0xA);
    func_808006B8_chcheato(param_0);
    func_8080078C_chcheato(param_0);
    func_800D1824(0x4A);
    switch (param_0->unk70_10) {
        case 1:
            if (!param_0->unk64_19 && func_8010D23C()) {
                param_0->unk54 = func_8010CD28(param_0);
                func_80102B2C(param_0, 4.0f);
                func_808003C4_chcheato(param_0);
            }
            break;
        case 3:
            func_80103DFC(param_0, local_0);
            if (_subaddieitem_entrypoint_3(param_0, local_0, func_80100094(param_0, 1))) {
                func_80102424(param_0, 2);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x115D, 0xE, param_0->position, 0x37);
            }
            break;
        case 4:
            if (!func_800C0638()) {
                func_80800D08_chcheato(param_0, 2, 1);
                func_80800B00_chcheato(param_0);
            }
            break;
        case 5: _gcnewoption_entrypoint_0(func_80100094(param_0, 0)); break;
        case 6:
            _gcnewoption_entrypoint_6(param_0, 0);
            func_80090708(0);
            func_80102424(param_0, 1);
            func_80800CC0_chcheato(param_0);
            break;
    }
}

s32 func_80800204_chcheato(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x2E:
            func_80800434_chcheato(param_0, *(s16 *)&param_2, ((s16 *)&param_2)[1]);
            break;
        case 0x49:
            if (param_2 == 1) {
                param_0->unk64_19 = 1;
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1143, 4, param_0->position, 0x37);
                _capod_entrypoint_13(param_0->unk0, 0, 1, 0x830);
            }
            break;
        case 0x20:
            func_80800AB4_chcheato(param_0, func_80101080(), *(s16 *)&param_2, ((s16 *)&param_2)[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800E50_chcheato, *(s32 *)&param_0->scale);
            break;
        case 0x95:
            param_0->unk64_20 = 0;
            break;
        case 0x57:
            return func_80800C64_chcheato(param_0, param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 16);
        default:
            return 0;
    }
    return 1;
}

void func_8080035C_chcheato(Actor *param_0, s32 param_1)
{
  if (func_800EB854() == 3)
  {
    if (((((*((u16 *) (((u8 *) param_0) + 0x72))) & 0xFFFFFFFFu) & 0xFFFFFFFFu) >> 10) == 5)
    {
      _gcnewoption_entrypoint_1(func_80100094(param_0, 0), param_1);
    }
  }
  else
  {
    func_80101870(param_0, param_1);
  }
}

void func_808003C4_chcheato(s32 param_0) {
    s32 local_0;
    s32 local_1;

    local_0 = 0xE;
    D_80800EE6_chcheato = func_80800824_chcheato(&local_0);
    D_80800EF4_chcheato = (s16) local_0;
    local_1 = _subaddiedialog_entrypoint_7(param_0, param_0 + 4, &D_80800EE0_chcheato);
    if ((local_1 != 0) && (local_1 != 0x1208)) {
        func_80800D08_chcheato(param_0, 3, 0);
    }
}

s32 func_80800888_chcheato();

void func_80800434_chcheato(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2; {
    s32 local_0;

    switch (param_1) {
    case 0x1144:
        _subaddieitem_entrypoint_2(func_80100094(param_0, 1));
        func_80102424(param_0, 3);
        return;
    case 0x115D:
        _subaddiedialog_entrypoint_11(*param_0, func_80800888_chcheato(), 0xE, param_0 + 1, 0x37);
        return;
    case 0x1142:
        if (func_800D1A04(0x4A) != 0) {
            local_0 = 0xE;
            _subaddiedialog_entrypoint_11(*param_0, func_80800824_chcheato(&local_0), local_0, param_0 + 1, 0x37);
            return;
        }
        func_800C01A8(0x64, 0);
        func_800C0850();
        func_80102424(param_0, 1);
        func_80800CC0_chcheato(param_0);
        return;
    case 0x1145:
        if (func_80800C0C_chcheato() != 0) {
            func_80102424(param_0, 4);
            return;
        }
        func_80102424(param_0, 1);
        func_80800CC0_chcheato(param_0);
        return;
    case 0x1147:
        func_80102424(param_0, 4);
        return;
    case 0x1148:
        func_800DA544(0x69);
        if (func_80800C0C_chcheato() != 0) {
            func_80102424(param_0, 4);
            return;
        }
        func_80102424(param_0, 1);
        func_80800CC0_chcheato(param_0);
        return;
    case 0x114B: ;
    case 0x114C:
    case 0x114D: ;
    case 0x114E:
    case 0x114F:
        if ((func_800D1A04(0x4A) >= 5) && (func_80800BB8_chcheato() != -1)) {
            _subaddieitem_entrypoint_2(func_80100094(param_0, 1));
            func_80102424(param_0, 3);
            return;
        }
        if (func_800DA298(0x69) == 0) {
            _subaddiedialog_entrypoint_11(*param_0, 0x1148, 0xE, param_0 + 1, 0x37);
            return;
        }
        _subaddiedialog_entrypoint_11(*param_0, 0x115E, 0xE, param_0 + 1, 0x37);
        return;
    case 0x1143:
        _capod_entrypoint_14();
        _glcutDll_entrypoint_17();
        return;
    case 0x115E:
        func_80102424(param_0, 4);
        return;
    default:
        func_80102424(param_0, 1);
        func_80800CC0_chcheato(param_0);
        return;
    }
}

void func_808006B8_chcheato(Actor *param_0)
{
    CheatoSoundTimes local_0;
    CheatoSoundIds local_1;
    s32 local_2;

    local_0 = D_80800EFC_chcheato;
    local_1 = D_80800F04_chcheato;
    for (local_2 = 0; local_2 < 2; local_2++) {
        if (func_80101E14(param_0, local_0.local_0[local_2])) {
            func_800C4B7C(local_1.local_0[local_2]);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800F08_chcheato);
        }
    }
}

void func_8080078C_chcheato(Actor *param_0)
{
  s32 local_0;

  local_0 = func_8010CAC0((u8 *)param_0 + 4, 0x2EE);
  if (!param_0->unk64_20) {
    if (local_0 != 0) {
      func_800FC63C(0x44, 0);
      func_800FCAE0(0x44, -1, 0x1F4);
      param_0->unk64_20 = 1;
    }
  } else if (local_0 == 0) {
    func_800FCAE0(0x44, 0, 0x1F4);
    func_800FCA90(0x44);
    param_0->unk64_20 = 0;
  }
}

s32 func_80800824_chcheato(param_0) u32 *param_0;
{
    s32 local_0;

    local_0 = func_800D1A04(0x4A);
    if (func_80800BB8_chcheato() == -1) {
        return 0x1147;
    }
    if (local_0 < 5) {
        *param_0 |= 1;
        return 0x1145;
    }
    return 0x1144;
}

s32 func_80800888_chcheato(void){
    s32 local_0 = func_80800BB8_chcheato();
    func_800D3EF4(local_0);
    return local_0 + 0x114A;
}

void func_808008B8_chcheato(OptionState *param_0, s32 param_1)
{
  s32 pad0;
    CheatoOptionDescriptor local_0;
    CheatoOptionDescriptor local_1;

    if (_gcnewoption_entrypoint_17((s32)param_0, param_1)) {
        local_0 = D_80800F20_chcheato;
        _gcnewoption_entrypoint_13(param_0, param_1, &local_0);
        _gcnewoption_entrypoint_12(param_0, param_1, (s16)(param_1 * 2 + 3));
    } else if (_gcnewoption_entrypoint_19(param_0, param_1)) {
        local_1 = D_80800F28_chcheato;
        _gcnewoption_entrypoint_13(param_0, param_1, &local_1);
        _gcnewoption_entrypoint_12(param_0, param_1, (s16)(param_1 * 2 + 4));
    }
}

void func_8080098C_chcheato(param_0, param_1) Actor *param_0; OptionState *param_1;
{
    _gcnewoption_entrypoint_14(param_1, 0, 1, 2, 4.0f);
    _gcnewoption_entrypoint_40(param_1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(param_1, 0x37);
}

void func_80800A04_chcheato(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    if (1) {}

    local_1 = func_80800C0C_chcheato(param_0);
    for (local_0 = 0; local_0 < local_1; local_0++) {
        local_2 = local_0 + 1;
        if (func_800D3E14(local_2)) _gcnewoption_entrypoint_21(param_0, local_0);
        else _gcnewoption_entrypoint_23(param_0, local_0);
        func_808008B8_chcheato(param_0, local_0);
        _gcnewoption_entrypoint_31(param_0, local_0, (s16)func_800D3FC0(local_2));
    }
}

int func_80800AB4_chcheato(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s32 param_3;
{
  switch (param_3)
  {
    case 0 :
      func_80800A04_chcheato(param_1 | 0);
      break;

    case 2 :
      func_80102424(param_0, 6);

  }

}

void func_80800B00_chcheato(Actor *param_0) {
    s32 local_1;
    s32 local_2;
    s32 local_0;

    local_0 = func_80800C0C_chcheato();
    _gcnewoption_entrypoint_4(param_0, 0, &_gcnewoption_entrypoint_16, &_gcnewoption_entrypoint_35, 0x1849);
    local_1 = func_80100094(param_0, 0);
    _gcnewoption_entrypoint_8(local_1, func_800F1418(5, local_0));
    _gcnewoption_entrypoint_9(local_1, local_0);
    _gcnewoption_entrypoint_10(local_1, 1);
    func_8080098C_chcheato(param_0, local_1);
    _gcnewoption_entrypoint_11(local_1);
    func_80102424(param_0, 5);
    func_80090708(2);
}

s32 func_80800BB8_chcheato(void){
    s32 i;
    s32 out;
    for(i = 1; i < 6; i++){
        if(func_800D3DD0(i) == 0){
            out = i;
            return out;
        }
    }
    out = -1;
    return out;
}

int func_80800C0C_chcheato()
{
  s32 local_0;
  s32 local_1 = 0;
  for (local_0 = 1; local_0 < 6; local_0++)
  {
    if (func_800D3DD0(local_0 | 0))
    {
      local_1++;
    }
  }

  return local_1;
}

int func_80800C64_chcheato(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0))
  {
    if (((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF) != 2)
    {
      func_80800D08_chcheato(param_0, 2, 1);
    }
    return 2;
  }
  return 1;
}

void func_80800CC0_chcheato(Actor *param_0)
{
    if (((*(u32 *)((char *)param_0 + 0x6C)) & 0x1FF) != 0) {
        _capod_entrypoint_3(0, param_0);
        *(u16 *)((char *)param_0 + 0x6E) &= 0xFE00;
    }
}

void func_80800D08_chcheato(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2; {
    s32 local_0;

    local_0 = (*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF;
    switch (local_0) {                              
    case 0:
        _capod_entrypoint_2((*(s32 *)((s8 *)(param_0) + (0))), 0x19, 0);
        
    case 1:
        _capod_entrypoint_8(1);
        (*(u16 *)((s8 *)(param_0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(param_0) + (0x6E))) & 0xFE00) | 2);
        _gcdialogcamera_entrypoint_3(&D_80800E50_chcheato, (*(s32 *)((s8 *)(param_0) + (0x38))));
        _gcdialogcamera_entrypoint_4(param_0 + 4);
        _gcdialogcamera_entrypoint_5(param_0 + 0x44);
        _gcdialogcamera_entrypoint_8();
        
    case 2:
        _capod_entrypoint_7(param_1, param_2);
        return;
    }
}
