#include "ch/mrsboggy.h"

extern int D_80800AD8_chmrsboggy[];
extern void func_80105A9C(Actor *, f32);
extern s32 D_80800B30_chmrsboggy[];
extern s32 D_80800A20_chmrsboggy[];
extern s32 _subaddiedialog_entrypoint_8(Actor *, f32[3], void *, void *, s32);
extern s32 _subaddiedialog_entrypoint_9(Actor *, s32, void *, s32);
extern s32 _gcdialogcamera_entrypoint_0(s32, s32);
extern void _capod_entrypoint_3(s32);
extern f32 D_80800A80_chmrsboggy[];
extern void _capod_entrypoint_2();
extern void _gcdialogcamera_entrypoint_3(f32 *, f32);
extern void _gcdialogcamera_entrypoint_4(f32 *);
extern void _gcdialogcamera_entrypoint_5(f32 *);
extern void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
extern u8 D_80800A58_chmrsboggy[];
extern u8 D_80800B20_chmrsboggy[];
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void *_suexpression_entrypoint_20();
extern Actor *_subaddiefind_entrypoint_2(s32, void *);
typedef union { u32 u; s32 s; } MBArg;
void func_80800790_chmrsboggy();
void func_808007CC_chmrsboggy();
void func_80800878_chmrsboggy();
s32 func_80800990_chmrsboggy();
extern void func_80101870(), func_80102EC0(), func_80107C2C(), func_8080000C_chmrsboggy(), func_80800088_chmrsboggy(), func_80800290_chmrsboggy();
extern u8 D_80800A90_chmrsboggy[];

int chmrsboggy_entrypoint_0()
{
    return (int)&D_80800AD8_chmrsboggy;
}

void func_8080000C_chmrsboggy(param_0) Actor *param_0;
{
    if (func_800DA980(0x8C, 3) == 3) {
        if (func_800DA298(0x1CD)) {
            func_800FFAB0(param_0);
            return;
        }
        func_800DA524(0x8B);
        func_80102424(param_0, 6);
    }
    func_80105A9C(param_0, 350.0f);
    func_80105BAC(param_0);
}

void func_80800568_chmrsboggy();

void func_80800088_chmrsboggy(param_0) Actor *param_0;
{
    f32 *local_0;
    s32 local_1;

    local_0 = param_0->position;
    _sudeflect_entrypoint_1(local_0, 200.0f, 0.0f, 100.0f, 10);
    if (_suexpression_entrypoint_20(param_0)) {
        _suexpression_entrypoint_10(_suexpression_entrypoint_20(param_0), param_0->unk0, 0);
    }
    switch (param_0->unk70_10) {
    case 1:
        func_80800568_chmrsboggy(param_0);
        return;
    case 6:
        local_1 = _subaddiedialog_entrypoint_8(param_0, local_0, D_80800B20_chmrsboggy, D_80800A58_chmrsboggy, 5);
        if (local_1 && _subaddiedialog_entrypoint_9(param_0, local_1, D_80800A58_chmrsboggy, 5) != 3) {
            func_808007CC_chmrsboggy(param_0, 3, 0);
            return;
        }
        return;
    case 3:
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 4);
            return;
        }
        break;
    case 5:
        if (func_80101DDC(param_0)) {
            func_800F82D4(func_800F54E4(), 0);
            if (func_800DA980(0x8C, 3) == 3) {
                func_80800910_chmrsboggy(param_0, 0x4B, 0x10);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x109E, 0x4E, local_0, 0x3E);
                func_80102424(param_0, 7);
                return;
            }
            func_80800878_chmrsboggy(param_0, 0xE, 0x31, _subaddiefind_entrypoint_2(0x142, NULL)->unk0);
            func_80102424(param_0, 1);
            return;
        }
        break;
    case 8:
        func_80105834(param_0);
        func_80105230(param_0, 0);
        if (func_80105A5C(param_0)) {
            func_80800790_chmrsboggy(param_0);
            func_800FFAB0(param_0);
        }
        break;
    }
}

void func_80800290_chmrsboggy(Actor* arg0)
{
    func_80800548_chmrsboggy(arg0);
}

s32 func_80800738_chmrsboggy();

void func_808005D8_chmrsboggy();

s32 func_808004F4_chmrsboggy();

int func_808002B0_chmrsboggy(Actor *param_0, s32 param_1, MBArg param_2)
{
    switch (param_1) {
    case 0x2E:
        func_808005D8_chmrsboggy(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        return 1;
    case 0x30:
        return func_8080070C_chmrsboggy(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
    case 0x31:
        if (param_0->unk70_10 == 2) return 0;
        func_800DA544(0x8B);
        func_80102424(param_0, 3);
        func_808007CC_chmrsboggy(param_0, 3, 1);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x109D, 6, param_0->position, 0x3E);
        func_800F82D4(func_800F54E4(), 2);
        return 1;
    case 0x29:
        func_808004F4_chmrsboggy(param_0);
        return 1;
    case 0x2A:
        func_80800548_chmrsboggy(param_0);
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800A80_chmrsboggy, param_0->scale);
        return 1;
    case 0x57:
        return func_80800738_chmrsboggy(param_0, param_2.s & 0xFFFF, (param_2.u & 0xFFFF0000) >> 16);
    case 0x4F:
        func_80800790_chmrsboggy(param_0);
        return 1;
    case 0xB8:
        return func_80800990_chmrsboggy() ? 0x109C : 0x109B;
    case 0x95:
        param_0->actorData[5] = _glsplinefind_entrypoint_0(0x357, param_0->actorData);
        break;
    case 0x23:
        if (func_800DA980(0x8C, 3) == 3) {
            func_800DA524(0x8B);
            func_80102424(param_0, 6);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_808004F4_chmrsboggy(void *this){
    s32 local_0;
    if(_suexpression_entrypoint_20() == 0){
        local_0 = _suexpression_entrypoint_7(this, 1, 0x3E);
        _suexpression_entrypoint_12(local_0, 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(local_0, 0x3E8);
    }
}

void func_80800548_chmrsboggy(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
void func_80800568_chmrsboggy(Actor *param_0)
{
    s32 local_0;

    local_0 = _subaddiedialog_entrypoint_8(param_0, param_0->position, &D_80800B30_chmrsboggy, &D_80800A20_chmrsboggy, 7);
    if (local_0 != 0) {
        if (_subaddiedialog_entrypoint_9(param_0, local_0, &D_80800A20_chmrsboggy, 7) != 3) {
            func_808007CC_chmrsboggy(param_0, 3, 0);
        }
    }
}

void func_808005D8_chmrsboggy(u8 *param_0, s32 param_1, s32 param_2) {
    s32 local_0;

    if (param_1 == 0x109D) {
        func_80102424(_subaddiefind_entrypoint_2(0x142, 0), 0xE);
        func_80102424(param_0, 5);
        func_80800878_chmrsboggy(param_0, 0x99, 0x30, 0);
        return;
    }
    local_0 = _subaddiedialog_entrypoint_9(param_0, param_1, ((s32 *) D_80800A58_chmrsboggy), 5);
    if ((local_0 != 3) && (local_0 != 0)) {
        func_80102FE8(param_0, 0);
        func_80102424(param_0, 8);
        _subaddieDll_entrypoint_4(param_0, 1);
        func_800D1000(0x1B, 1, param_0 + 4, 0, 0);
        func_800DA544(0x1CD);
        func_800DA524(0xB8);
        func_800DA524(0xB9);
        func_800DA524(0xBA);
        func_800DA524(0x8B);
        func_80800878_chmrsboggy(param_0, 0xE, 0x31, 0);
        return;
    }
    if ((*(s32 *)((s8 *)(param_0) + (0x28))) != 0) {
        func_80800790_chmrsboggy(param_0);
    }
    func_80102424(param_0, 1);
}

int func_8080070C_chmrsboggy(s32 param_0, s32 param_1, s32 param_2)
{
  s32 *new_var;
  return 3 - func_80800990_chmrsboggy(param_0 ^ 0, *(new_var = &param_1));
}

s32 func_80800738_chmrsboggy(s32 param_0, s32 param_1, s32 param_2) {
    if (_gcdialogcamera_entrypoint_0(param_1, param_2) != 0) {
        if (*(s32 *)(param_0 + 0x28) != 2) {
            func_808007CC_chmrsboggy(param_0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_80800790_chmrsboggy(param_0) s32 param_0; {
    if (*(s32 *)(param_0 + 0x28) != 0) {
        _capod_entrypoint_3(0);
        *(s32 *)(param_0 + 0x28) = 0;
    }
}

void func_808007CC_chmrsboggy(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_0->actorData[4]) {
    case 0:
        _capod_entrypoint_2(param_0->unk0, 0x12, 0);
    case 1:
    case 3:
        _capod_entrypoint_8(1);
        param_0->actorData[4] = 2;
        _gcdialogcamera_entrypoint_3(D_80800A80_chmrsboggy, param_0->scale);
        _gcdialogcamera_entrypoint_4(param_0->position);
        _gcdialogcamera_entrypoint_5(param_0->rotation);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(param_1, param_2);
        break;
    }
}

void func_80800878_chmrsboggy(param_0, param_1, param_2, param_3) Actor *param_0; s32 param_1; s32 param_2; Unk80132ED0 *param_3;
{
    if (param_3 == NULL) {
        param_3 = param_0->unk0;
    }
    switch (param_0->actorData[4]) {
        case 0:
            _capod_entrypoint_2(param_0->unk0, 18, param_2);
        case 2:
        case 3:
            param_0->actorData[4] = 1;
        case 1:
            _capod_entrypoint_6(param_3, param_1, param_2);
            break;
    }
}

int func_80800910_chmrsboggy(s32 param_0[2], s32 param_1, s32 param_2)
{
  int new_var;
  new_var = 10;
  switch (param_0[new_var])
  {
    case 0:
      _capod_entrypoint_2(param_0[0], 0x12, param_2, param_0);
      /* fallthrough */
    case 1:
    case 2:
      param_0[10] = 1;
      /* fallthrough */
    case 3:
      _capod_entrypoint_20(param_0[0], param_1, param_2, param_0);
      return;
  }
}

s32 func_80800990_chmrsboggy(void){
    func_800DA980(0x8C, 3);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/mrsboggy.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80800A20_chmrsboggy -> s32[], D_80800AD8_chmrsboggy -> int[], D_80800B30_chmrsboggy -> s32[] */
s32 D_80800A20_chmrsboggy[14] = { 0x1, 0x109A0100, 0x1, -0xFE00, 0x200, 0x110C0100, 0x200, -0xFE00, 0x400, 0x110D0100, 0x400, -0xFE00, -0x12001, 0x120B0300 };
u8 D_80800A58_chmrsboggy[40] = { 0x0, 0x0, 0x2, 0x1, 0x10, 0x9E, 0x1, 0x0, 0x0, 0x0, 0x2, 0x1, 0x10, 0x9E, 0x2, 0x0, 0x0, 0x0, 0x4, 0x0, 0x11, 0xE, 0x1, 0x0, 0x0, 0x0, 0x4, 0x0, 0x11, 0xE, 0x2, 0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0 };
f32 D_80800A80_chmrsboggy[4] = { 215.0f, 215.0f, 215.0f, 107.5f };
u8 D_80800A90_chmrsboggy[72] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x41, 0x20, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x1, 0x41, 0x20, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x1, 0x3F, 0xA6, 0x66, 0x66, 0x1, 0x2, 0x0, 0x2, 0x3F, 0xA6, 0x66, 0x66, 0x1, 0x3, 0x0, 0x1, 0x40, 0xA0, 0x0, 0x0, 0x1, 0x1, 0x0, 0x2, 0x40, 0x6, 0x66, 0x66, 0x3, 0xEE, 0x0, 0x1, 0x40, 0x6, 0x66, 0x66, 0x3, 0xEE, 0x0, 0x1, 0x3F, 0x4C, 0xCC, 0xCD, 0x1, 0x4, 0x0, 0x1 };
int D_80800AD8_chmrsboggy[18] = { 0x191013F, 0x6B70001, (u32)&D_80800A90_chmrsboggy, (u32)func_80102EC0, (u32)func_80800088_chmrsboggy, (u32)func_80101870, 0x5DC0000, 0x3FE00000, 0x0, 0x40040121, (u32)func_80800290_chmrsboggy, 0x0, 0x0, (u32)func_8080000C_chmrsboggy, (u32)func_80107C2C, -0x7BEF8BEA, (u32)func_808002B0_chmrsboggy, 0x0 };
u8 D_80800B20_chmrsboggy[16] = { 0x0, 0x8B, 0x0, 0x0, 0x1, 0x2C, 0x0, 0x3E, 0x0, 0x0, 0x0, 0xE, 0x6, 0x3C, 0x7, 0x0 };
s32 D_80800B30_chmrsboggy[4] = { 0x8B0000, 0x12C003E, 0xE, 0x63C0200 };
