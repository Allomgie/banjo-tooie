#include "common.h"

extern s32 _subaddiedialog_entrypoint_1(f32 *, s32, s32);
extern s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, void *);
extern void func_80101FDC(Actor *, u32);
extern s32 func_800F6BE4(s32);
extern s32 func_800F7B9C(s32, u32);
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_800F7D38(s32, s32, f32 *, f32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void *D_80800500_chpodiumbankaz;
extern int D_80800548_chpodiumbankaz;

s32 func_80800000_chpodiumbankaz(s32 param_0) {
    if (func_800C6E38(0x1C)) {
        _subaddiefade_entrypoint_1(param_0, 0xFF);
    } else {
        _subaddiefade_entrypoint_1(param_0, 0x87);
    }
}

void func_80800044_chpodiumbankaz(Actor *param_0)
{

    if (!func_800DA298(0x4F4)) {
        if (_subaddiedialog_entrypoint_1(param_0->position, 250, 0)) {
            if (_subaddiedialog_entrypoint_11(param_0->unk0, 0xD82, 0xE, param_0->position, 0)) {
                func_800DA544(0x4F4);
            }
        }
    }
}

void func_808000B8_chpodiumbankaz(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 1:
            func_80800044_chpodiumbankaz(param_0);
            break;
        case 2:
            func_80101FDC(param_0, 3);
            break;
        case 3:
            if (!func_800F6BE4(param_0->unk79_4) ||
                func_800F7B9C(param_0->unk79_4, 4) == 2) {
                func_80101FDC(param_0, 1);
            }
            break;
    }
}

void func_80800170_chpodiumbankaz(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 1:
            func_80800044_chpodiumbankaz(param_0);
            break;
        case 2:
            func_80101FDC(param_0, 3);
            break;
        case 3:
            if (!func_800F6BE4(param_0->unk79_4) ||
                func_800F7B9C(param_0->unk79_4, 5) == 2) {
                func_80101FDC(param_0, 1);
            }
            break;
    }
}

void func_80800228_chpodiumbankaz(Unk80132ED0 *param_0, s32 param_1)
{
    Actor *local_2;
    s32 local_0;
    f32 local_1[3];

    if (func_800C6E38(0x1C)) {
        local_0 = func_800F5410(param_1);
        local_2 = func_80106790(param_0);
        if (local_0 == 1 || local_0 == 10) {
            if (local_2->unk70_10 == 3 || func_800F7D38(param_1, 0x3A, local_2->position, local_2->rotation[1]) == 2) {
                if (local_0 == 10) {
                    func_800F5A00(param_1, local_1);
                    _sudeflect_entrypoint_1(local_1, 125.0f, 0.0f, 40.0f, 0x1C);
                }
                local_2->unk79_4 = param_1;
                func_80101FDC(local_2, 2);
            }
        }
    }
}

void func_80800318_chpodiumbankaz(Unk80132ED0 *param_0, s32 param_1)
{
    Actor *local_1;
    s32 local_0;

    if (func_800C6E38(0x1C)) {
        local_0 = func_800F5410(param_1);
        local_1 = func_80106790(param_0);
        if (local_0 == 0xB && (local_1->unk70_10 == 3 ||
            func_800F7CF4(param_1, 0x3B, local_1->position) == 2)) {
            local_1->unk79_4 = param_1;
            func_80101FDC(local_1, 2);
        }
    }
}

s32 func_808003C4_chpodiumbankaz(s32 param_0, s32 param_1){
    if(param_1 == 0x1C){
        _subaddiefade_entrypoint_1(param_0, 0xFF);
    }
}

int func_808003EC_chpodiumbankaz(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    switch (param_1) {
    case 0x1A:
        func_808003C4_chpodiumbankaz(param_0 | param_0, param_2 | param_2);
        return 1;
    case 0x91:
        if (func_800DA298(0xa84)) {
            func_80800228_chpodiumbankaz(*(void **)param_0, param_2 | param_2);
        }
        return 1;
    default:
        break;
    }
    local_0 = 0;
    return local_0;
}

int func_80800464_chpodiumbankaz(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    switch (param_1) {
    case 0x1A:
        func_808003C4_chpodiumbankaz(param_0 | param_0, param_2 | param_2);
        return 1;
    case 0x91:
        if (func_800DA298(0xAC2)) {
            func_80800318_chpodiumbankaz(*(void **)param_0, param_2 | param_2);
        }
        return 1;
    default:
        break;
    }
    local_0 = 0;
    return local_0;
}

int chpodiumbankaz_entrypoint_0()
{
  return &D_80800500_chpodiumbankaz;
}

int chpodiumbankaz_entrypoint_1()
{
    return &D_80800548_chpodiumbankaz;
}
