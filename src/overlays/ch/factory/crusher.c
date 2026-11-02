#include "common.h"

extern int D_80800A50_chfactorycrusher;
extern int D_80800A98_chfactorycrusher;
extern void *func_80100094(Actor *, u32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800F0E00(f32, f32);
extern s32 func_800F54E4(void);
extern Actor *_subaddiefind_entrypoint_1(Actor *, s32, s32, s32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800F4D18(u32, f32 *, f32 *);
extern void func_800EFE50(u8 *, u8 *, u8 *, f32);
extern u8 D_80800AE0_chfactorycrusher[];
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern s32 func_800E1610(s32, f32, f32, f32 *);
extern s32 func_800E148C(s32, f32, f32);
extern f32 mlAbsF(f32);
extern s32 func_80018820(s32, f32, f32);
s32 func_80800898_chfactorycrusher();
s32 func_80800738_chfactorycrusher();

int chfactorycrusher_entrypoint_0()
{
  return &D_80800A50_chfactorycrusher;
}

int chfactorycrusher_entrypoint_1()
{
    return (int)&D_80800A98_chfactorycrusher;
}

void func_80800018_chfactorycrusher(Actor *param_0)
{
    s32 local_3;
    f32 local_0[3];
    f32 local_1[3];
    f32 *local_2;

    func_800EE7F8(param_0->actorData, param_0->position);
    func_800EE7F8((u8 *)param_0 + 0x28, param_0->position);
    func_800EF1B8((f32 *)((u8 *)param_0 + 0x28), param_0->rotation[1], 500.0f);
    param_0->unk58 = 0.0f;
    func_8010A63C(param_0);
    local_2 = func_80100094(param_0, 0);
    if (func_80104004(param_0, local_0, local_1)) {
        func_800EF934(local_0, local_0, param_0->rotation[1]);
        func_800EF934(local_1, local_1, param_0->rotation[1]);
        for (local_3 = 0; local_3 < 3; local_3++) {
            local_2[local_3] = func_800F13F0(local_0[local_3], local_1[local_3]);
            local_2[local_3 + 3] = func_800F0E00(local_0[local_3], local_1[local_3]);
        }
    }
    if (param_0->unk74_7 != 0x32) {
        func_80101FDC(param_0, 6);
        func_80103110(param_0, 0);
    }
}

void func_808008F0_chfactorycrusher();

void func_808008B8_chfactorycrusher(u8 *param_0, f32 param_1);

void func_808006CC_chfactorycrusher();

void func_80800150_chfactorycrusher(Actor *param_0)
{
    u8 *local_0;
    Actor *local_1;
    f32 local_2[3];
    s32 sf_t327;
    s32 local_3;
    f32 local_4[3];
    s32 local_8;
    s32 sf_t738;
    f32 local_5;
    s32 local_6;
    s32 local_7;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80800898_chfactorycrusher(param_0);
    switch (param_0->unk70_10) {
    case 1:
        if (!func_800DA298(0x329) && !param_0->unk64_19 &&
            !*(s32 *)(local_0 + 0x18) && func_800D90A4(&param_0->unk58)) {
            param_0->unk64_20 = 0;
            sf_t327 = func_80800738_chfactorycrusher(param_0, local_2);
            if (sf_t327) {
                if (func_800F64A4(func_800F54E4(), 0x10000) ||
                    func_800F5578(func_800F54E4()) >= 2) {
                    local_8 = ((f32 *)param_0->actorData)[0] < local_2[0] ? 0x22 : 0x1E;
                    _capod_entrypoint_13(param_0->unk0, 0, local_8, 0);
                    param_0->unk64_19 = 1;
                }
                sf_t738 = func_800F54E4();
                func_800F7F98(sf_t738, 1);
                param_0->unk64_20 = 1;
                func_80101180(0x3EE, 0xB9, 0);
                func_8010A624(param_0);
                func_8010A624(local_1);
            }
            func_80101FDC(param_0, 2);
            param_0->unk58 = 0.25f;
        }
        ((f32 *)param_0->actorData)[7] = 0.0f;
        break;
    case 2:
        local_3 = func_800D9078(&param_0->unk58);
        ((f32 *)param_0->actorData)[7] = func_800F12D4(param_0->unk58, 0.0f, 0.25f, 1.0f, 0.0f);
        func_808008B8_chfactorycrusher(param_0, ((f32 *)param_0->actorData)[7]);
        func_808008B8_chfactorycrusher(local_1, ((f32 *)param_0->actorData)[7]);
        if (param_0->unk64_20) {
            func_808008F0_chfactorycrusher(param_0);
        }
        if (local_3) {
            if (param_0->unk74_7 == 50) {
                func_800E148C(func_800E1610(2, 80.0f, 0.85f,
                    (f32 *)param_0->actorData + 4), 2000.0f, 8000.0f);
                func_8010D640(local_4);
                local_5 = (800.0f / func_800F0E00(800.0f, mlAbsF(local_4[2] - 4000.0f))) * 2.75f;
                if (local_5 > 0.25f) {
                    func_80018820(0, local_5, 0.35f);
                }
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800AE0_chfactorycrusher);
            }
            func_80800800_chfactorycrusher(param_0);
            func_80101FDC(param_0, 3);
            param_0->unk58 = 0.35f;
        }
        break;
    case 3:
        if (func_800D90A4(&param_0->unk58)) {
            func_80101FDC(param_0, 4);
            param_0->unk58 = 1.5f;
        }
        ((f32 *)param_0->actorData)[7] = 1.0f;
        break;
    case 4:
        local_6 = func_800D9078(&param_0->unk58);
        ((f32 *)param_0->actorData)[7] = func_800F12D4(param_0->unk58, 0.0f, 1.5f, 0.0f, 1.0f);
        func_808008B8_chfactorycrusher(param_0, ((f32 *)param_0->actorData)[7]);
        func_808008B8_chfactorycrusher(local_1, ((f32 *)param_0->actorData)[7]);
        if (local_6) {
            func_80101FDC(param_0, 1);
            param_0->unk58 = param_0->unk64_20 ? 2.0f : 0.0f;
            param_0->unk64_20 = 0;
        }
        break;
    case 5:
        func_808008B8_chfactorycrusher(param_0, ((f32 *)param_0->actorData)[7]);
        func_808008B8_chfactorycrusher(local_1, ((f32 *)param_0->actorData)[7]);
        break;
    }
    if (!param_0->unk64_19) {
        func_808006CC_chfactorycrusher(param_0);
        func_808006CC_chfactorycrusher(local_1);
        if (!param_0->unk64_20) {
            func_8010A654(param_0, param_0->unk7C_12);
            func_8010A654(local_1, local_1->unk7C_12);
        }
    }
}

s32 func_80800580_chfactorycrusher(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    Actor *local_1;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x95:
            local_1 = _subaddiefind_entrypoint_1(param_0, 0x3BA, -1, 0);
            if (local_1) {
                param_0->unk3C = local_1->unk0;
            }
            *(s32 *)(local_0 + 0x18) = 0;
            break;
        case 11:
            if (param_2 == 0x1E || param_2 == 0x22) {
                local_1 = func_80800898_chfactorycrusher(param_0);
                param_0->unk64_19 = 0;
                local_1->unk64_19 = param_0->unk64_19;
                func_800F7F98(func_800F54E4(), 0);
                func_80101180(0x3EE, 0xBA, 0);
            }
            return 3;
        default:
            return 0;
    }
    return 1;
}

void func_8080067C_chfactorycrusher(s32 param_0, s32 param_1) {
    f32 local_0[3];

    func_800E3980(local_0);
    if (local_0[2] > 2500.0f) {
        func_80101870(param_0, param_1);
    }
}

void func_808006CC_chfactorycrusher(Actor *param_0)
{
    f32 *local_0;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = func_80100094(param_0, 0);
    func_800EE780(local_1, local_0, param_0->position);
    func_800EE780(local_2, local_0 + 3, param_0->position);
    func_800F4D18(func_800F54E4(), local_1, local_2);
}

s32 func_80800738_chfactorycrusher(param_0, param_1) Actor *param_0; f32 *param_1;
{
    if (!func_800F6478(func_800F54E4())) return 0;
    func_800F5A00(func_800F54E4(), param_1);
    if (param_1[0] > -2350.0f && param_1[0] < 3550.0f &&
        param_1[2] > 3400.0f && param_1[2] < 4600.0f) return 1;
    return 0;
}

int func_80800800_chfactorycrusher(Actor *param_0)
{
    s32 *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    if (param_0->unk64_20) {
        local_1 = func_800F54E4();
        if (func_800F5578(local_1) == 1 && !func_800F64A4(local_1, 0x10000)) {
            func_800F7F98(local_1, 0);
            local_0[6] = 1;
        }
        func_800F7B9C(local_1, 0x5C);
        return 1;
    }
    return 0;
}

s32 func_80800898_chfactorycrusher(this) Actor *this;{
    func_80106790(this->unk3C);
}

void func_808008B8_chfactorycrusher(u8 *param_0, f32 param_1) {
    func_800EFE50(param_0 + 4, param_0 + 0x18, param_0 + 0x28, param_1);
}

void func_808008F0_chfactorycrusher(Actor *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2[3];
    s32 local_3;
    Actor *c;

    local_3 = func_800F54E4();
    c = (Actor *)func_80800898_chfactorycrusher(param_0);
    local_1 = param_0->position[2];
    local_0 = c->position[2];
    func_800F5A00(local_3, local_2);
    if (local_2[2] < local_0) {
        local_2[2] = local_0;
        func_800F8418(local_3, local_2);
    } else if (local_1 < local_2[2]) {
        local_2[2] = local_1;
        func_800F8418(local_3, local_2);
    }
}

s32 func_80800984_chfactorycrusher(Actor *this){
    _chswitch_entrypoint_7(this, 0x329);
    _chswitch_entrypoint_8(this, 1);
    _chswitch_entrypoint_9(this);
}

int func_808009BC_chfactorycrusher(s32 param_0[4], unsigned int param_1)
{
  if (param_1 == 7)
  {
    _chmrtannoy_entrypoint_0();
    _subaddiedialog_entrypoint_11(param_0[0], 0x1340, 4, param_0 + 1, 0xA3);
    return 1;
    return 0;
  }
  _chswitch_entrypoint_10(param_0);
}
