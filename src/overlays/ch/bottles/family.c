#include "common.h"

extern int D_80800DE0_chbottlesfamily;
extern int D_80800E28_chbottlesfamily;
extern int D_80800E70_chbottlesfamily;
typedef struct { u8 pad[0x38]; f32 f38; u8 pad3C[0x29]; u8 pad65:3; u8 flag:1; u8 rest:4; } BottlesS;
extern void func_80102FDC(BottlesS *, f32);
extern s32 _glcutDll_entrypoint_20();
extern s32 D_80800EB8_chbottlesfamily;
extern s32 D_80800ECC_chbottlesfamily;
extern s32 D_80800EDC_chbottlesfamily;
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, void *, void *);
extern void *_suexpression_entrypoint_20(Actor *);
extern void _suexpression_entrypoint_10(void *, Unk80132ED0 *, s32);
extern void *func_80100094(Actor *, u32);
extern f32 func_800DC178(f32, f32);
extern void _subaddierouteDll_entrypoint_1(void *);
extern s16 D_80800F08_chbottlesfamily;
extern int D_80800F04_chbottlesfamily;
extern int _subaddierouteDll_entrypoint_7(void *param_0, int param_1, float param_2, float param_3, float param_4, int param_5);
extern void func_80102424(void *param_0, int param_1);
extern u8 D_80800F20_chbottlesfamily[];
extern void _subaddieaudioquick_entrypoint_3(s32, s32, void *, f32);
extern s32 D_80800F2C_chbottlesfamily;
extern f32 D_80800F68_chbottlesfamily[];
extern s32 D_80800F48_chbottlesfamily;
extern s32 D_80800F58_chbottlesfamily;
extern s32 D_80800F78_chbottlesfamily;
extern int func_80101E4C(Actor *, f32 *);
extern int _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
extern void func_800C4350(s32, f32 *, void *);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern s32 func_800DC298(f32);
extern void func_800FC6B0(s32);
extern void _glcutDll_entrypoint_6(s32, s32);
extern u8 D_80800F88_chbottlesfamily[];
extern u8 D_80800F98_chbottlesfamily[];
extern u8 D_80800FA8_chbottlesfamily[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern f32 func_8010CD28(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int _gcdialogcamera_entrypoint_0(int, int);
extern void _capod_entrypoint_3(int, void *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern u8 D_80800EF8_chbottlesfamily[];
extern void func_8010B990(Actor *, s32);
extern s32 func_80102CF4(Actor *, f32);
extern s32 func_800D90A4(f32 *);
s32 func_80800720_chbottlesfamily();
void func_8080088C_chbottlesfamily();
s32 func_8080099C_chbottlesfamily();
int func_808009F0_chbottlesfamily();
s32 func_80800A44_chbottlesfamily();
void func_80800A84_chbottlesfamily();
int func_80800B64_chbottlesfamily();
void func_80800BC0_chbottlesfamily();
void func_80800C08_chbottlesfamily();
void func_80800CA4_chbottlesfamily();

int chbottlesfamily_entrypoint_0()
{
    return (int)&D_80800DE0_chbottlesfamily;
}

int chbottlesfamily_entrypoint_1()
{
    return (int)&D_80800E28_chbottlesfamily;
}

int *chbottlesfamily_entrypoint_2()
{
    return &D_80800E70_chbottlesfamily;
}

void func_80800024_chbottlesfamily(BottlesS *param_0) {
    func_80102FDC(param_0, param_0->f38 / 3.0f);
    param_0->flag = 1;
    if (_glcutDll_entrypoint_20(param_0)) {
        func_80102424(param_0, 5);
    }
}

void func_80800080_chbottlesfamily(Actor *param_0)
{

    _sudeflect_entrypoint_0(param_0->position, param_0->scale * 50.0f, param_0->scale * 50.0f, 10);
    _subaddieaudioquick_entrypoint_4(param_0, param_0->position, &D_80800EB8_chbottlesfamily, &D_80800ECC_chbottlesfamily);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(param_0), param_0->unk0, 0);
    if (param_0->unk70_10 == 1) func_808009F0_chbottlesfamily(param_0, &D_80800EDC_chbottlesfamily);
}

void func_80800124_chbottlesfamily(Actor *param_0)
{
    f32 *local_0;
    local_0 = func_80100094(param_0, 0);
    _subaddierouteDll_entrypoint_3(param_0, local_0, param_0->position);
    local_0[3] = func_800DC178(2.5f, 5.0f);
    param_0->unk58 = func_800DC178(5.0f, 10.0f);
    if (_glcutDll_entrypoint_20()) func_80102424(param_0, 5);
}

void func_808005D0_chbottlesfamily();

void func_80800520_chbottlesfamily();

void func_808001B0_chbottlesfamily(Actor *param_0)
{


    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    _sudeflect_entrypoint_0(param_0->position, (param_0->scale * 50.0f), (param_0->scale * 50.0f), 0xA);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(param_0), param_0->unk0, 0);
    switch (param_0->unk70_10) {
    case 1:
        func_808005D0_chbottlesfamily(param_0);
        if (!func_808004B4_chbottlesfamily(param_0) && func_800D90A4(&param_0->unk58)) func_80800520_chbottlesfamily(param_0);
        break;
    case 2:
        param_0->unk54 = func_8010CD28(param_0);
        func_80102BF8(param_0, 0.1f, 4.0f, 120.0f);
        break;
    case 3:
        if (func_800D9078((f32 *)(local_0 + 0xC))) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800EF8_chbottlesfamily);
            *(f32 *)(local_0 + 0xC) = func_800DC178(2.5f, 5.0f);
        }
        func_80105230(param_0, 0);
        _subaddierouteDll_entrypoint_7(param_0, local_0, param_0->rotation[1], param_0->unk54, 200.0f, 0x401);
        _subaddierouteDll_entrypoint_6(param_0, local_0, *(u16 *)(local_0 + 6), 7, 0.7f, 8, 0xC);
        _subaddierouteDll_entrypoint_5(param_0, local_0, *(u16 *)(local_0 + 6), 0.1f, 4.0f, 120.0f);
        ((f32 *)param_0->actorData)[3] = func_800F15F8(((f32 *)param_0->actorData)[3], 200.0f, func_800D8FF8() * 300.0f);
        func_8010B990(param_0, 0x1305);
        if (!func_808004B4_chbottlesfamily(param_0) && func_800D90A4(&param_0->unk58)) {
            func_80102424(param_0, 1);
            param_0->unk58 = func_800DC178(5.0f, 10.0f);
        }
        break;
    case 4:
        func_80105230(param_0, 0);
        func_80102BF8(param_0, 0.1f, 4.0f, 120.0f);
        if (!func_808004B4_chbottlesfamily(param_0) && func_80102CF4(param_0, 10.0f)) func_80102424(param_0, 3);
        break;
    case 5:
        func_808005D0_chbottlesfamily(param_0);
        break;
    }
}

s32 func_8080046C_chbottlesfamily(void *param_0, s32 param_1) {
    if (param_1 == 0x95) {
        func_80800720_chbottlesfamily(param_0);
        _subaddierouteDll_entrypoint_1(param_0);
    } else {
        return func_80800720_chbottlesfamily(param_0);
    }
    return 1;
}

int func_808004B4_chbottlesfamily(Actor *param_0)
{
  if (func_800DA298(0x3B))
  {
    return 0;
  }
  if (func_800DA298(0x1A5))
  {
    D_80800F08_chbottlesfamily = 0x1539;
  }
  else
  {
    D_80800F08_chbottlesfamily = 0x1501;
  }
  func_808009F0_chbottlesfamily(param_0, &D_80800F04_chbottlesfamily);
}

void func_80800520_chbottlesfamily(void *param_0)
{
    f32 temp_f0;
    s32 temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    temp_f0 = *((f32 *)(((char *)param_0) + 0x48));
    *((f32 *)(((char *)param_0) + 0x54)) = temp_f0;
    if (_subaddierouteDll_entrypoint_7(param_0, temp_v0, temp_f0, temp_f0 + 180.0f, 200.0f, 0x401) == 0)
    {
        func_80102424(param_0, 3);
    }
    else
    {
        func_80102424(param_0, 4);
    }
    *((f32 *)(((char *)param_0) + 0x58)) = func_800DC178(5.0f, 10.0f);
    *((f32 *)(((char *)param_0) + 0x24)) = 0.0f;
}

void func_808005D0_chbottlesfamily(s32 param_0) {
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 0x4, D_80800F20_chbottlesfamily, 0.08f);
}

s32 func_80800600_chbottlesfamily(s32 param_0) {
    if (_glcutDll_entrypoint_20()) {
        func_80102424(param_0, 5);
    }
}

void func_80800630_chbottlesfamily(Actor *param_0)
{
    f32 *local_0;
    u8 local_1;

    local_0 = param_0->position;
    _sudeflect_entrypoint_0(local_0, param_0->scale * 50.0f, param_0->scale * 50.0f, 10);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(param_0), param_0->unk0, 0);
    if (param_0->unk70_10 == 1) func_808009F0_chbottlesfamily(param_0, &D_80800F2C_chbottlesfamily);
    if (func_80101E4C(param_0, D_80800F68_chbottlesfamily)) {
        local_1 = param_0->unk5F;
        if (local_1 == 0) local_1 = param_0->unk5F = _subaddieaudioquick_entrypoint_1(param_0, local_0);
        func_800C4350(local_1, local_0, &D_80800F48_chbottlesfamily);
    }
    _subaddieaudioquick_entrypoint_4(param_0, local_0, &D_80800F58_chbottlesfamily, &D_80800F78_chbottlesfamily);
}

s32 func_80800720_chbottlesfamily(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    s32 local_0;
    switch (param_1) {
    case 0x2E: func_8080088C_chbottlesfamily(param_0, *(s16 *)&param_2, ((s16 *)&param_2)[1]); break;
    case 0x2F: func_8080099C_chbottlesfamily(param_0, *(s16 *)&param_2, ((s16 *)&param_2)[1]); break;
    case 0x52: func_80800A84_chbottlesfamily(param_0); break;
    case 0x57: return func_80800B64_chbottlesfamily(param_0, param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 16);
    case 0x95:
        local_0 = _suexpression_entrypoint_7(param_0, 1, (s16)func_80800A44_chbottlesfamily(param_0));
        _suexpression_entrypoint_12(local_0, 60.0f, 20.0f);
        _suexpression_entrypoint_17(local_0, 1000); break;
    case 0x1F: func_800DF744(3, param_0->unk64_20); func_801015D0(param_0); break;
    default: return 0;
    }
    return 1;
}

void func_8080086C_chbottlesfamily(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
void func_8080088C_chbottlesfamily(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
    case 0x1503:
        func_80800BC0_chbottlesfamily(param_0);
        func_8009032C(0x2B);
        func_800FC6B0(0xE);
        break;
    case 0x1501:
        func_80800BC0_chbottlesfamily(param_0);
        _glcutDll_entrypoint_6(0x142, 0x66);
        break;
    default:
        if (param_0->unk6C_0) func_80800BC0_chbottlesfamily(param_0);
        break;
    }
    if (param_0->unk6C_9 == 0x43C) {
        if (func_800DC298(0.5f)) func_80800520_chbottlesfamily(param_0);
        else {
            func_80101FDC(param_0, 1);
            param_0->unk58 = func_800DC178(5.0f, 10.0f) * 0.5f;
        }
    } else {
        func_80101FDC(param_0, 1);
    }
}

s32 func_8080099C_chbottlesfamily(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    if ((param_1 != 0x1501) && (param_1 != 0x1539)) {
        return;
    }

    if ((param_2 == 1) && !func_800C07F4()) {
        func_80800CA4_chbottlesfamily(param_0, 4, 0x2020);
    }
}

int func_808009F0_chbottlesfamily(param_0, param_1) s32 param_0[3]; s32 param_1;
{
  s32 local_0;
  local_0 = _subaddiedialog_entrypoint_7(param_0, param_0 + 1, param_1 | 0);
  if (local_0 && local_0 != 0x1208)
  {
    func_80800C08_chbottlesfamily(param_0, 3, 0);
  }
  return local_0 != 0;
}

s32 func_80800A44_chbottlesfamily(param_0) void *param_0; {
    u32 temp_t7;
    temp_t7 = (u32) ((*(u32 *)((char *)param_0 + 0x6C)) << 0xB) >> 0x14;
    switch (temp_t7) {
    case 0x43C:
        return 0xB0;
    case 0x43D:
        return 0xB1;
    default:
        return 0xAF;
    }
}

void func_80800A84_chbottlesfamily(param_0) Actor *param_0;
{
    f32 local_0[3];

    switch (param_0->unk6C_9) {
    case 0x43D:
        _gcdialogcamera_entrypoint_3(D_80800F88_chbottlesfamily, param_0->scale);
        _gcdialogcamera_entrypoint_5(param_0->rotation);
        break;
    case 0x43C:
        func_800EFA4C(local_0, 0.0f, func_8010CD28(param_0), 0.0f);
        _gcdialogcamera_entrypoint_3(D_80800F98_chbottlesfamily, param_0->scale);
        _gcdialogcamera_entrypoint_5(local_0);
        break;
    case 0x43B:
        _gcdialogcamera_entrypoint_3(D_80800FA8_chbottlesfamily, param_0->scale * 3.0f);
        _gcdialogcamera_entrypoint_5(param_0->rotation);
        break;
    }
    _gcdialogcamera_entrypoint_4(param_0->position);
}

int func_80800B64_chbottlesfamily(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0))
  {
    if (((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF) != 2)
    {
      func_80800C08_chbottlesfamily(param_0, 2, 1);
    }
    return 2;
  }
  return 1;
}

void func_80800BC0_chbottlesfamily(param_0) void *param_0;
{
    if (((*(u32 *)((char *)param_0 + 0x6C)) & 0x1FF) != 0) {
        _capod_entrypoint_3(0, param_0);
        *(u16 *)((char *)param_0 + 0x6E) &= 0xFE00;
    }
}

void func_80800C08_chbottlesfamily(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2; {
    s32 local_0;

    local_0 = (*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF;
    switch (local_0) {                              
    case 0:
        _capod_entrypoint_2((*(s32 *)((s8 *)(param_0) + (0))), 0x18, 0, param_0);
        
    case 1:
        _capod_entrypoint_8(1);
        (*(u16 *)((s8 *)(param_0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(param_0) + (0x6E))) & 0xFE00) | 2);
        func_80800A84_chbottlesfamily(param_0);
        _gcdialogcamera_entrypoint_8();
        
    case 2:
        _capod_entrypoint_7(param_1, param_2);
        return;
    }
}

void func_80800CA4_chbottlesfamily(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2; {
    s32 temp_t6;

    temp_t6 = (*(s32 *)((s8 *)param_0 + 0x6C)) & 0x1FF;
    switch (temp_t6) {
    case 0:
        _capod_entrypoint_2(*(s32 *)((s8 *)param_0 + 0), 0x18, param_2, param_0);
        /* fallthrough */
    case 2:
        (*(u16 *)((s8 *)param_0 + 0x6E)) = (u16)(((*(u16 *)((s8 *)param_0 + 0x6E)) & 0xFE00) | 1);
        /* fallthrough */
    case 1:
        _capod_entrypoint_6(*(s32 *)((s8 *)param_0 + 0), param_1, param_2, param_0);
        return;
    }
}
