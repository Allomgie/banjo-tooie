#include "common.h"

extern int D_80800308_chfairgroundworker[];
extern void *D_80800350_chfairgroundworker;
extern int D_80800398_chfairgroundworker[];
extern s32 D_808003E0_chfairgroundworker[];
extern u8 D_80800430_chfairgroundworker[];
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_80102FDC(Actor *, f32);
extern void func_8010A3E8(Actor *, f32);
typedef struct { u8 unused[0x95]; u8 reserved : 7; u8 enabled : 1; } FairgroundWorkerFlags;
extern u8 D_80800428_chfairgroundworker[];
extern void _chbadshad_entrypoint_3(Actor *, f32 *, s32, f32, void *);
void func_8080013C_chfairgroundworker();

int chfairgroundworker_entrypoint_0()
{
    return (int)&D_80800308_chfairgroundworker;
}

int chfairgroundworker_entrypoint_1()
{
  return &D_80800350_chfairgroundworker;
}

void *chfairgroundworker_entrypoint_2(void)
{
    return &D_80800398_chfairgroundworker;
}

int chfairgroundworker_entrypoint_3()
{
  return D_808003E0_chfairgroundworker;
}

void func_80800030_chfairgroundworker(Actor *param_0)
{
    _sucoaster_entrypoint_0(param_0, 0);
    func_80102FDC(param_0, param_0->scale * 0.85f);
    func_8010A3E8(param_0, 0.7f);
    ((FairgroundWorkerFlags *)param_0)->enabled = 1;
}

void func_80800098_chfairgroundworker(Actor *param_0)
{
    _sucoaster_entrypoint_2(param_0);
    if (param_0->unk7C_12) {
        _chbadshad_entrypoint_3(param_0, param_0->position, 3, param_0->scale * 1.529411674f, D_80800428_chfairgroundworker);
    }
}

s32 func_808000FC_chfairgroundworker(s32 param_0, s32 param_1, s32 param_2){
    if(param_1 == 0xB6){
        func_8080013C_chfairgroundworker(param_0, param_1, param_2);
    }
    _sucoaster_entrypoint_21(param_0, param_1, param_2);
}

void func_8080013C_chfairgroundworker(param_0) Actor *param_0;
{
    s32 local_2;
    f32 local_0[3];
    f32 local_1[3];
    s32 local_3;
    func_800EE7F8(local_1, param_0->position);
    func_800EF1B8(local_1, param_0->rotation[1], param_0->scale * 300.0f);
    local_2 = func_800B53A4(5);
    for (local_3 = 0; local_3 < 5; local_3++) {
        func_800EEB9C(local_0, (f32)local_3 * 72.0f, 5.0f);
        func_800EF04C(local_0, local_1);
        func_800BABB8(local_2, local_0, local_1, 1.0f, D_80800430_chfairgroundworker);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/fair/groundworker.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800308_chfairgroundworker -> int[], D_80800398_chfairgroundworker -> int[] */
extern void func_80105834();
extern void _sucoaster_entrypoint_20();
extern void _sucoaster_entrypoint_1();
extern void _sucoasterhit_entrypoint_0();
extern void func_80107C2C();
u32 D_80800270_chfairgroundworker[38] = { 0x0, 0x0, 0x4129999A, 0xF90001, 0x4129999A, 0xF90001, 0x3FAA3D71, 0xDE0001, 0x3F333333, 0xF80001, 0x3FAA3D71, 0xDE0001, 0x3FAA3D71, 0xDE0001, 0x3FAE147B, 0xDF0002, 0x3F333333, 0xF80001, 0x3FD5C28F, 0x4280002, 0x3F333333, 0xF80001, 0x3F947AE1, 0x4270002, 0x3FD70A3D, 0xF70002, 0x3FD70A3D, 0xF70084, 0x4129999A, 0xF90001, 0x3FAA3D71, 0xDE0020, 0x0, 0x0, 0x4129999A, 0xF90001, 0x3F333333, 0xF80001 };
int D_80800308_chfairgroundworker[18] = { 0x1900327, 0x6B10001, (u32)&D_80800270_chfairgroundworker, (u32)func_80800098_chfairgroundworker, (u32)func_80105834, (u32)_sucoaster_entrypoint_20, 0xBB80000, 0x0, 0x0, 0x43050329, (u32)_sucoaster_entrypoint_1, (u32)_sucoasterhit_entrypoint_0, 0x0, (u32)func_80800030_chfairgroundworker, (u32)func_80107C2C, -0x7BCDAFE3, (u32)func_808000FC_chfairgroundworker, -0x7FEDBAB0 };
void *D_80800350_chfairgroundworker = (void *)0x01900328;
static u32 D_80800350_chfairgroundworker_rest[17] = { 0x6B30001, (u32)&D_80800270_chfairgroundworker, (u32)func_80800098_chfairgroundworker, (u32)func_80105834, (u32)_sucoaster_entrypoint_20, 0xBB80000, 0x0, 0x0, 0x43050329, (u32)_sucoaster_entrypoint_1, (u32)_sucoasterhit_entrypoint_0, 0x0, (u32)func_80800030_chfairgroundworker, (u32)func_80107C2C, 0x8432501D, (u32)func_808000FC_chfairgroundworker, 0x80124550 };
int D_80800398_chfairgroundworker[18] = { 0x1900329, 0x6B20001, (u32)&D_80800270_chfairgroundworker, (u32)func_80800098_chfairgroundworker, (u32)func_80105834, (u32)_sucoaster_entrypoint_20, 0xBB80000, 0x0, 0x0, 0x43050329, (u32)_sucoaster_entrypoint_1, (u32)_sucoasterhit_entrypoint_0, 0x0, (u32)func_80800030_chfairgroundworker, (u32)func_80107C2C, -0x7BCDAFE3, (u32)func_808000FC_chfairgroundworker, -0x7FEDBAB0 };
s32 D_808003E0_chfairgroundworker[18] = { 0x190032A, 0x6B40001, (u32)&D_80800270_chfairgroundworker, (u32)func_80800098_chfairgroundworker, (u32)func_80105834, (u32)_sucoaster_entrypoint_20, 0xBB80000, 0x0, 0x0, 0x43050329, (u32)_sucoaster_entrypoint_1, (u32)_sucoasterhit_entrypoint_0, 0x0, (u32)func_80800030_chfairgroundworker, (u32)func_80107C2C, -0x7BCDAFE3, (u32)func_808000FC_chfairgroundworker, -0x7FEDBAB0 };
u8 D_80800428_chfairgroundworker[8] = { 0x0, 0xC, 0x0, 0xD, 0xFF, 0xFF, 0x0, 0x0 };
u8 D_80800430_chfairgroundworker[64] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2B, 0x0, 0x99, 0x0, 0xCC, 0x0, 0x22, 0x0, 0x4C, 0x0, 0x66, 0x1, 0x0, 0x1, 0x33, 0x0, 0x15, 0x0, 0x0, 0x0, 0x66, 0x0, 0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x64, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x32, 0x0, 0x0, 0x0, 0x2D, 0x0, 0x96, 0x0, 0xFA, 0x0, 0x20, 0xDE, 0xA7, 0x71, 0xC0, 0x1, 0x1A, 0x0, 0x0, 0x0, 0x0 };
