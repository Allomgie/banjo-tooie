#include "common.h"

extern int D_80800308_chfairgroundworker;
extern void *D_80800350_chfairgroundworker;
extern int D_80800398_chfairgroundworker;
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
