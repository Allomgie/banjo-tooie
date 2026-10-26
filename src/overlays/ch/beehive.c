#include "common.h"

extern void func_800EE7F8(f32 *, f32 *);
typedef struct { u8 pad[0x18]; s32 f18; u8 pad1C[0x5C]; u32 pad78:29; u32 flag:1; u32 rest:2; } HiveS;
extern s32 _subaddiesect_entrypoint_0(HiveS *, s32, s32);
extern u8 D_808002F0_chbeehive[];
extern u8 D_80800300_chbeehive[];
extern u8 D_80800320_chbeehive[];
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern u8 D_80800364_chbeehive[];
extern u8 func_800C2E04(void);
extern void func_800C301C();
extern void func_800C3584(u8, f32, f32);
extern void func_800C31DC(u8, f32);
extern f32 func_80101F24(Actor *);
extern int D_80800374_chbeehive;
void func_80800180_chbeehive();

void func_80800000_chbeehive(Actor *param_0)
{
    s32 local_0;
    func_800EE7F8((f32 *)&param_0->actorData[4], param_0->position);
    param_0->unk50 = param_0->rotation[1];
    local_0 = _subaddiesect_entrypoint_1(param_0);
    param_0->actorData[0] = local_0;
    param_0->unk74_7 = (u16)(param_0->unk74_7 - 0x32);
    if (local_0 != -1) {
        _subaddiesect_entrypoint_2(param_0, local_0, 0);
    }
}

void func_80800078_chbeehive(HiveS *param_0) {
    if (!param_0->flag) {
        if (param_0->f18 == -1 || _subaddiesect_entrypoint_0(param_0, param_0->f18, 0xB)) {
            func_80800180_chbeehive(param_0);
        }
    }
}

void func_808000CC_chbeehive(Actor *param_0, Actor **param_1)
{
    f32 local_0[3];

    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808002F0_chbeehive);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800300_chbeehive);
    func_800BBCB8(param_0->position, 0, param_0->scale, 1, D_80800320_chbeehive);
    if (param_0->unk3C) func_8010114C(param_0->unk3C, 0x53, 0);
    func_800EE88C(local_0, (*param_1)->position);
    local_0[1] = param_0->position[1];
    _chexploder_entrypoint_3(param_0, local_0, 0x2C);
}

void func_80800180_chbeehive(param_0) Actor *param_0;
{
    if (func_80101E4C(param_0, D_80800364_chbeehive)) {
        if (param_0->unk5F == 0) {
            param_0->unk5F = func_800C2E04();
            func_800C301C(param_0->unk5F, 0x447);
            func_800C3058(param_0->unk5F, 12000);
            func_800C35E8(param_0->unk5F, param_0->position);
            func_800C3584(param_0->unk5F, 300.0f, 1500.0f);
        }
        if (param_0->unk5F != 0) {
            func_800C3CE8(param_0->unk5F);
            func_800C31DC(param_0->unk5F, func_80101F24(param_0) + 0.5f);
            func_800C330C(param_0->unk5F, 3);
            _subaddieaudioquick_entrypoint_0(param_0->unk5F, *(u32 *)((u8 *)param_0 + 0x70) & 1);
            func_800C3BDC(param_0->unk5F);
        }
    }
}

s32 func_80800268_chbeehive(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x40:
        func_808000CC_chbeehive(param_0, param_2);
        break;
    case 0x1F:
        func_801015D0(param_0);
        func_800DF744(3, 1);
        break;
    case 0x90:
        break;
    default:
        return 0;
    }
    return 1;
}

int chbeehive_entrypoint_0()
{
    return &D_80800374_chbeehive;
}
