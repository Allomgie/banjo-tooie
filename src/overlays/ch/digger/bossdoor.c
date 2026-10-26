#include "common.h"

extern int D_80800430_chdiggerbossdoor;
extern u8 D_80800478_chdiggerbossdoor[];
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern u8 _chdiggerbossdoor_entrypoint_1[];
extern Actor *func_80106790();
void func_80800370_chdiggerbossdoor();

int *chdiggerbossdoor_entrypoint_0()
{
    return &D_80800430_chdiggerbossdoor;
}

void func_8080000C_chdiggerbossdoor(Actor *param_0)
{
    (*(f32 *)((char *)(param_0) + 0x28)) = 0.0f;
    if (func_800EA090() == 6)
    {
        (*(f32 *)((char *)(param_0) + 0x28)) = -500.0f;
        if (func_800DA298(0x43) != 0)
        {
            func_80800370_chdiggerbossdoor(param_0);
            func_8010108C(param_0, 7, 0);
            func_800F8294(func_800F54E4(), (f32 *)((char *)(param_0) + 4));
            _capod_entrypoint_21(*(s32 **)((char *)(param_0) + 0), 0, 0x55, 0x2010);
            (*(u16 *)((char *)(param_0) + 0x6E)) = (*(u16 *)((char *)(param_0) + 0x6E) & 0xFE00) | 1;
        }
    }
}

void func_808000B0_chdiggerbossdoor(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    f32 local_2[3];

    local_0 = 0;
    local_1 = func_800F54E4();
    switch (param_0->unk70_10) {
    case 2:
        if (func_800D9078(&param_0->unk58)) {
            if (func_800DA298(0x43)) {
                _capod_entrypoint_22();
                param_0->unk6C_0 = 0;
            }
            func_80101FDC(param_0, 3);
        } else {
            local_0 = 1;
        }
        ((f32 *)param_0->actorData)[4] = func_800F12D4(param_0->unk58, 0.0f, 6.0f, 0.0f, -500.0f);
        func_800EE7F8(local_2, param_0->position);
        local_2[1] += ((f32 *)param_0->actorData)[4];
        func_800F8294(local_1, local_2);
        break;
    case 4:
        if (func_800D9078(&param_0->unk58)) {
            _gcgoto_entrypoint_1(0x15D, 5);
            func_80101FDC(param_0, 1);
        } else {
            local_0 = 1;
        }
        ((f32 *)param_0->actorData)[4] = func_800F12D4(param_0->unk58, 0.0f, 6.0f, -500.0f, 0.0f);
        break;
    case 3:
        if ((s32)((u32)func_800F55FC(local_1) << 3) < 0 && func_80016B30(0, 1) == 1 &&
            func_800F4BB8(local_1, -1, 0)) {
            _capod_entrypoint_21(param_0->unk0, 0, 0x54, 0x10);
            func_80101FDC(param_0, 4);
            param_0->unk6C_0 = 1;
            param_0->unk58 = 6.0f;
        }
        break;
    }
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_0, D_80800478_chdiggerbossdoor);
    func_80800370_chdiggerbossdoor(param_0);
}

void func_808002A8_chdiggerbossdoor(void *param_0) {
    if ((*(s32 *)((char *)param_0 + 0x6C)) & 0x1FF) {
        _capod_entrypoint_22();
        *(u16 *)((char *)param_0 + 0x6E) &= 0xFE00;
    }
}

int func_808002E8_chdiggerbossdoor(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 7:
        if (param_0->unk70_10 == 1) {
            func_80101FDC(param_0, 2);
            param_0->unk58 = 6.0f;
        }
        break;
    case 0x95:
        func_80800370_chdiggerbossdoor(param_0);
        return 1;
    default:
        return 0;
    }
    return 1;
}

void func_80800370_chdiggerbossdoor(param_0) s32 *param_0; {
    s32 local_0;

    local_0 = func_800BEA88(0);
    if (local_0 != 0) {
        _glid_entrypoint_0(local_0, 1, &_chdiggerbossdoor_entrypoint_1, *param_0);
    }
}

void chdiggerbossdoor_entrypoint_1(void *param_0, Vtx *param_1, Vtx *param_2,
                                 s32 param_3, Unk80132ED0 *param_4)
{
    s16 local_0;
    Vtx *local_1;
    local_0 = *(f32 *)&func_80106790(param_4)->actorData[4];
    local_1 = param_1 + param_3;
    for (; param_1 < local_1; param_1++, param_2++) {
        param_2->v.ob[1] = param_1->v.ob[1] + local_0;
    }
}
