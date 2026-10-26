#include "common.h"

extern int D_80800458_chcrate;
extern int D_808004A0_chcrate;
extern f32 func_800EC708(void *);
extern u8 D_808004F8_chcrate[];
extern void _chcrate_entrypoint_3();
extern u8 D_80800508_chcrate[];
extern u8 D_808004E8_chcrate[];
extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_12(Actor *, s32);
extern void func_800BBCB8(f32 *, void *, f32, s32, void *);
extern void func_801096C8(Actor *, s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void _chbaddiesetup_entrypoint_5(void (*)(), s32, s32, s32, s32, s32);
extern void func_800DA544(s32);
extern void func_800FFAB0(Actor *);
extern void func_80101FDC(Actor *, s32);
extern void func_80103110(Actor *, s32);
extern void func_8010A570(Actor *);
extern void func_8010A624(Actor *);
extern s16 D_8080053C_chcrate[];
extern Actor *func_80108474(s32, f32 *, s32);
typedef struct { u8 pad_0[0x70]; u32 pad_1 : 14; u32 local_0 : 1; u32 pad_2 : 17; } CrateSpawnFlags;
void func_80800104_chcrate();
s32 func_80800380_chcrate();

int chcrate_entrypoint_0()
{
  extern int D_80800410_chcrate;
  return (int)&D_80800410_chcrate;
}

int chcrate_entrypoint_1()
{
  return (int)&D_80800458_chcrate;
}

int *chcrate_entrypoint_2()
{
    return &D_808004A0_chcrate;
}

int func_80800024_chcrate(s32 param_0)
{
  s32 new_var;
  new_var = func_80800380_chcrate();
  if ((new_var != 0) && (func_800DA298(new_var) != 0))
  {
    func_800FFAB0(param_0);
  }
}

s32 func_80800064_chcrate(Actor *param_0, s32 param_1, void *param_2)
{
    void *local_0;
    switch (param_1) {
    case 0x40:
        local_0 = (*(void * *)&param_2);
        func_800EC398(local_0, (f32 *)param_0->actorData);
        ((f32 *)param_0->actorData)[1] += func_800EC708(local_0);
        _chexploder_entrypoint_4(param_0, (u8 *)*(void **)local_0 + 4, 4);
        break;
    case 0x90:
        func_80800104_chcrate(param_0);
        break;
    default: return 0;
    }
    return 1;
}

void func_80800104_chcrate(param_0) Actor *param_0;
{
    Actor *local_0;
    s32 local_1;
    s32 local_2[1];
    s32 local_3[1];
    s32 local_4[1];
    s32 local_5[1];
    s32 local_6[1];

    local_0 = func_80106790(func_80101080());
    local_1 = func_80800380_chcrate(param_0);
    _chexploder_entrypoint_12(local_0, 0x32);
    func_800BBCB8(param_0->position, param_0->actorData, param_0->scale, 0xA, D_80800508_chcrate);
    func_801096C8(param_0, 0);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808004E8_chcrate);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808004F8_chcrate);
    if ((s32)param_0->unk74_7 >= 0x33) {
        local_2[0] = param_0->position[0];
        local_3[0] = param_0->position[1];
        local_4[0] = param_0->position[2];
        local_5[0] = param_0->rotation[1];
        local_6[0] = param_0->unk74_7;
        _chbaddiesetup_entrypoint_5(_chcrate_entrypoint_3, local_2[0], local_3[0], local_4[0], local_5[0], local_6[0]);
    } else if (local_1) {
        func_800DA544(local_1);
    }
    if (local_1) {
        func_800FFAB0(param_0);
        return;
    }
    func_80101FDC(param_0, 2);
    func_80103110(param_0, 0);
    func_8010A570(param_0);
    func_8010A624(param_0);
    param_0->unk64_16 = 0;
}

s16 func_808003AC_chcrate();

void chcrate_entrypoint_3(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    f32 local_0[3];
    Actor *local_1;

    local_1 = NULL;
    local_0[0] = param_0;
    local_0[1] = param_1;
    local_0[2] = param_2;
    switch (param_4) {
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x3A:
        case 0x3B:
            local_1 = func_80108474(func_808003AC_chcrate(param_4), local_0, param_3);
            local_1->unk74_7 = 0x32;
            break;
        case 0x39:
            if (!func_800D0B68(6, 2)) {
                func_800D1000(6, 2, local_0, 3, 0);
            }
            break;
    }
    if (local_1 != NULL) {
        ((CrateSpawnFlags *)local_1)->local_0 = 1;
    }
}

s32 func_80800380_chcrate(param_0) u16 *param_0;
{
  u32 local_0;
  int new_var;
  local_0 = ((u32) ((u16) param_0[0x3B])) >> 7;
  if (((s32) local_0) < 0x32)
  {
    return (new_var = 0x31 - (((u32) ((u16) param_0[0x3B])) >> 7)) + 0xA40;
  }
  return 0;
}

s16 func_808003AC_chcrate(s32 param_0) {
    s32 local_0 = param_0 - 0x32;
    if (local_0 > 0) {
        return D_8080053C_chcrate[local_0];
    }
    return 0;
}
