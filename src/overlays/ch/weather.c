#include "common.h"

extern void *D_80800440_chweather;
extern void *D_80800488_chweather;
extern void *D_808004D0_chweather;
extern s32 D_80800518_chweather[];
extern int D_80800560_chweather[];
extern int D_808005A8_chweather[];
extern void *D_808005F0_chweather;
extern int D_80800638_chweather[];
typedef struct { s16 local_0; s16 local_1; s32 local_2; } WeatherPreset;
extern void _fxrain_entrypoint_6(s32, f32, f32, f32, f32);
typedef struct { s16 state; s16 pad_0; s32 (*enabled)(Actor *); } WeatherCondition1408;
extern WeatherCondition1408 D_80800410_chweather[];

s32 func_80800000_chweather(s32 param_0){
    return 1;
}

int func_8080000C_chweather(Actor *param_0)
{
  f32 local_0[3];
  func_8010D254(local_0);
  return local_0[2] < -1700.0f;
}

int func_80800050_chweather(Actor *param_0)
{
  f32 local_0[3];
  func_8010D254(local_0);
  return 1700.0f < local_0[2];
}

int func_80800094_chweather(Actor *param_0)
{
  f32 local_0[3];
  func_8010D254(local_0);
  return 1700.0f < local_0[0];
}

int chweather_entrypoint_0()
{
  return &D_80800440_chweather;
}

int chweather_entrypoint_1()
{
  return &D_80800488_chweather;
}

int chweather_entrypoint_2()
{
  return &D_808004D0_chweather;
}

int chweather_entrypoint_3()
{
  return (int)D_80800518_chweather;
}

int chweather_entrypoint_4()
{
  return (int)&D_80800560_chweather;
}

int *chweather_entrypoint_5()
{
    return &D_808005A8_chweather;
}

void *chweather_entrypoint_6(void)
{
    return &D_808005F0_chweather;
}

int *chweather_entrypoint_7()
{
    return &D_80800638_chweather;
}

void func_80800138_chweather(Actor *param_0, s32 param_1)
{
    s32 local_0;
    WeatherPreset *local_1;

    if (param_1 == 3) _fxleaves_entrypoint_5(func_800B7C10());
    if (param_0->unk70_10 == 3) _fxleaves_entrypoint_6(func_800B7C10());
    if (param_1 == 4) {
        local_0 = func_800B7C54();
        local_1 = ((WeatherPreset *) D_80800410_chweather) + (param_0->unk6C_9 - 0x204);
        _fxrain_entrypoint_7(local_0);
        if (local_1->local_1) _fxrain_entrypoint_6(local_0, 5.0f, 30.0f, 5.0f, 30.0f);
    }
    if (param_0->unk70_10 == 4) _fxrain_entrypoint_8(func_800B7C54());
    if (param_1 == 5) {
        func_800B7CA4();
        func_800B90C8();
    }
    if (param_0->unk70_10 == 5) {
        func_800B7CA4();
        func_800B90E8();
    }
    param_0->unk70_10 = param_1;
}

void func_808002A8_chweather(Actor *param_0)
{
    WeatherCondition1408 *local_0;

    local_0 = (WeatherCondition1408 *)((u8 *)D_80800410_chweather + (((s32)param_0->unk6C_9 - 0x204) << 3));
    if (param_0->unk70_10 == 2) {
        if (local_0->enabled(param_0)) {
            func_80800138_chweather(param_0, local_0->state);
        }
    }
    if (param_0->unk70_10 != 2) {
        if (!local_0->enabled(param_0)) {
            func_80800138_chweather(param_0, 2);
        }
    }
}

s32 func_8080035C_chweather(void) {
    if (func_8010C500() != 0) {
        func_800B7D28();
    }
}

s32 func_8080038C_chweather(void){
    if(func_8010C500()){
        func_800B7DC8();
    }
}

s32 func_808003BC_chweather(s32 param_0, s32 param_1, s32 param_2){
    if(param_1 == 0x95){
        func_80800138_chweather(param_0, 2);
        return 1;
    }
    return 0;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/weather.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800560_chweather -> int[], D_808005A8_chweather -> int[], D_80800638_chweather -> int[] */
extern void func_8010A730();
extern void func_80107C2C();
WeatherCondition1408 D_80800410_chweather[6] = { 0x3, 0x1, (void *)func_80800000_chweather, 0x3, 0x0, (void *)func_8080000C_chweather, 0x4, 0x1, (void *)func_80800000_chweather, 0x4, 0x0, (void *)func_80800050_chweather, 0x5, 0x1, (void *)func_80800000_chweather, 0x5, 0x0, (void *)func_80800094_chweather };
void *D_80800440_chweather = (void *)0x01C10204;
static u32 D_80800440_chweather_rest[17] = { 0x1, 0x0, (u32)func_808002A8_chweather, 0x0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x140, 0x0, 0x0, 0x0, 0x0, (u32)func_80107C2C, 0x80000602, (u32)func_808003BC_chweather, 0x0 };
void *D_80800488_chweather = (void *)0x01C10205;
static u32 D_80800488_chweather_rest[17] = { 0x1, 0x0, (u32)func_808002A8_chweather, 0x0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x140, 0x0, 0x0, 0x0, 0x0, (u32)func_80107C2C, 0x80000602, (u32)func_808003BC_chweather, 0x0 };
void *D_808004D0_chweather = (void *)0x01C10206;
static u32 D_808004D0_chweather_rest[17] = { 0x1, 0x0, (u32)func_808002A8_chweather, 0x0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x140, 0x0, 0x0, 0x0, 0x0, (u32)func_80107C2C, 0x80000602, (u32)func_808003BC_chweather, 0x0 };
s32 D_80800518_chweather[18] = { 0x1C10207, 0x1, 0x0, (u32)func_808002A8_chweather, 0x0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x140, 0x0, 0x0, 0x0, 0x0, (u32)func_80107C2C, -0x7FFFF9FE, (u32)func_808003BC_chweather, 0x0 };
int D_80800560_chweather[18] = { 0x1C10208, 0x1, 0x0, (u32)func_808002A8_chweather, 0x0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x140, 0x0, 0x0, 0x0, 0x0, (u32)func_80107C2C, -0x7FFFF9FE, (u32)func_808003BC_chweather, 0x0 };
int D_808005A8_chweather[18] = { 0x1C10209, 0x1, 0x0, (u32)func_808002A8_chweather, 0x0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x140, 0x0, 0x0, 0x0, 0x0, (u32)func_80107C2C, -0x7FFFF9FE, (u32)func_808003BC_chweather, 0x0 };
void *D_808005F0_chweather = (void *)0x01C1020A;
static u32 D_808005F0_chweather_rest[17] = { 0x1, 0x0, (u32)func_8080035C_chweather, 0x0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, (u32)func_80107C2C, 0x80000602, (u32)func_808003BC_chweather, 0x0 };
int D_80800638_chweather[18] = { 0x1C1020B, 0x1, 0x0, (u32)func_8080038C_chweather, 0x0, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, (u32)func_80107C2C, -0x7FFFF9FE, (u32)func_808003BC_chweather, 0x0 };
