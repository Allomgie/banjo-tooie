#include "common.h"

extern int D_80800B58_chphlegm;
extern int D_80800BA0_chphlegm;
extern s32 func_800DC298(f32);
typedef union { s32 word; void *pointer; } PhlegmMessage;
typedef struct { u8 pad0[0x24]; u32 unk24_22 : 10; u32 unk24_0 : 22; } PhlegmData;
typedef struct { u8 pad0[0x64]; u32 unk64_21 : 11; u32 unk64_20 : 1; u32 unk64_0 : 20; } PhlegmBits;
extern s32 func_801084B0(s32, Actor **);
extern void func_8010A570(Actor *);
extern void func_800FFAB0(Actor *);
extern void func_80103140(Actor *, u16, s32);
typedef struct { u8 local_0[0x64]; u32 local_1:1; u32 local_2:1; u32 local_3:1; u32 local_4:29; } PhlegmFlags49;
extern f32 D_80800C30_chphlegm[];
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 func_8010CD28(Actor *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, f32 *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
typedef union { s32 word; Actor **actors; } PhlegmEvent30;
extern u8 D_80800C50_chphlegm[];
extern void _chbaddiesetup_entrypoint_10();
extern void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
extern Actor *func_80106790();
extern void _subaddiefade_entrypoint_3();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 func_800B53A4(s32);
extern s32 D_80800C5C_chphlegm[];
extern u8 D_80800C88_chphlegm[];
extern u8 D_80800C98_chphlegm[];
extern void func_8010D254();
extern f32 func_800DC178(f32, f32);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
typedef union { s32 local_0; void *local_1; } PhlegmEvent9DC;
extern f32 func_800136E4(f32);
extern f32 func_800EEF94(f32 *);
extern u8 D_80800CD8_chphlegm[];
extern u8 D_80800CC4_chphlegm[];
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern void func_800EF368(f32 *, f32);
void func_80800748_chphlegm(Actor *param_0, f32 param_1, s32 param_2);
void func_80800A58_chphlegm();

int chphlegm_entrypoint_0()
{
    return (int)&D_80800B58_chphlegm;
}

int chphlegm_entrypoint_1()
{
    return (int)&D_80800BA0_chphlegm;
}

void *chphlegm_entrypoint_2(void)
{
    extern void *D_80800BE8_chphlegm;
    return &D_80800BE8_chphlegm;
}

void func_80800024_chphlegm(Actor *param_0)
{
    if (func_800DC298(0.5f)) param_0->unk50 = 600.0f;
    else param_0->unk50 = -600.0f;
    if (func_800DC298(0.5f)) param_0->unk54 = 50.0f;
    else param_0->unk54 = -50.0f;
    if (param_0->unk64_20) func_8010A570(param_0);
}

void func_808000C4_chphlegm(Actor *param_0)
{
    s32 local_0;
    f32 local_1;
    s32 local_2;
    switch (param_0->unk70_10) {
        case 1:
            local_0 = func_8010B990(param_0, 0x404007);
            local_1 = func_800D8FF8();
            local_2 = param_0->unk64_20 ? 0x95C : 0x95D;
            func_808007EC_chphlegm(param_0, local_2);
            param_0->rotation[0] = func_800136E4(param_0->rotation[0] + local_1 * param_0->unk50);
            param_0->rotation[1] = func_800136E4(param_0->rotation[1] + local_1 * param_0->unk54);
            if (local_0 & 0x28) {
                func_80800748_chphlegm(param_0, -20.0f, local_2);
                func_8010A570(param_0);
                func_80101FDC(param_0, 2);
                _subaddiefade_entrypoint_3(param_0);
                if (param_0->unk64_20) { func_80108B04(param_0, 0); }
            }
            if (!param_0->unk64_19 &&
                (param_0->position[1] < -2000.0f || func_800EEF94(param_0->position) > 20000.0f)) {
                func_800FFAB0(param_0);
            }
            break;
        case 2:
            param_0->position[1] -= (param_0->scale * func_800D8FF8()) * 25.0f;
            break;
    }
}

s32 func_8080026C_chphlegm(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 pad;
    PhlegmData *local_0;

    switch (param_1) {
    case 0x3D:
        func_80102FDC(func_801084B0(0x399, &param_0), *(f32 *)((u8 *)param_0 + 0x38));
        return 1;
    case 0x40:
        local_0 = *(PhlegmData **)&param_2;
        func_8010A570(param_0);
        func_80800748_chphlegm(param_0, 0.0f, 0x95D);
        if (local_0->unk24_22 != 0) {
            func_800FFAB0(param_0);
        }
        break;
    case 0x95:
        func_80103140(param_0, ((PhlegmBits *)param_0)->unk64_20 ? 0x6DC : 0x876, 0);
        return 1;
    default:
        return 0;
    }
    return 1;
}

void func_80800354_chphlegm(u8 *param_0) {
    *(f32 *)(param_0 + 0x48) = *(f32 *)(param_0 + 0x54) = func_8010CD28(param_0);
    *(f32 *)(param_0 + 0x24) = *(f32 *)(param_0 + 0x38) * 150.0f;
    *(f32 *)(param_0 + 0x58) = func_800DC178(0.8f, 1.0f);
}

void func_808003B4_chphlegm(Actor *param_0)
{
    f32 local_9[3];
    f32 local_8[3];
    f32 local_7[3];
    f32 local_6;
    Actor *local_0[10];
    s32 local_1;
    s32 local_2;
    s32 local_3;
    f32 local_4;
    switch (param_0->unk70_10) {
    case 1:
        if (func_80101DDC(param_0)) {
            func_8010A590(param_0);
            func_80102424(param_0, 2);
        }
        break;
    case 2:
        if (func_8010D248()) {
            if (((PhlegmFlags49 *)param_0)->local_3) local_4 = _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3);
            else {
                local_4 = 1.0f;
                param_0->unk54 = func_8010CD28(param_0);
            }
            func_80102BF8(param_0, 0.15f, 120.0f, 360.0f);
            if (func_800DA298(0) && func_800D90A4(&param_0->unk58)) {
                local_2 = _subaddiefind_entrypoint_4(0x399, local_0, 10);
                local_3 = local_2;
                for (local_1 = 0; local_1 < local_2; local_1++) {
                    if (!((PhlegmFlags49 *)local_0[local_1])->local_2) local_3--;
                }
                if (!((PhlegmFlags49 *)param_0)->local_3 && local_3 >= 4 && !_suchase_entrypoint_1(param_0)) return;
                local_6 = (func_800D8FF8() * ((*((f32 *) (&param_0->actorData[3]))) * local_4)) * func_800F3780(func_80101F24(param_0), D_80800C30_chphlegm, 4);
                func_800EE7F8(local_8, param_0->position);
                func_800EF1B8(local_8, param_0->rotation[1], local_6);
                local_8[1] -= 80.0f;
                func_800EE7F8(local_9, local_8);
                local_9[1] = param_0->position[1] + 100.0f;
                if (func_800C6A7C(local_9, local_8, local_7, param_0->unk14)) func_800EE7F8(param_0->position, local_8);
            }
        }
        break;
    }
}

s32 func_808005E4_chphlegm(Actor *param_0, s32 param_1, PhlegmEvent30 param_2)
{
    f32 local_1[3];
    Actor *local_0;
    switch (param_1) {
    case 0x40:
        if (_subaddiefind_entrypoint_9(param_0->unk6C_9) == 1) {
            func_80103DFC(param_0, local_1);
            _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3,
                ((s32 *)local_1)[0], ((s32 *)local_1)[1], ((s32 *)local_1)[2], *(s32 *)&param_0->rotation[1]);
        }
        func_80800748_chphlegm(param_0, -10.0f, 0x95C);
        _chexploder_entrypoint_4(param_0, (*param_2.actors)->position, 0x1C);
        break;
    case 0x90:
        local_0 = func_80106790(func_80101080());
        _chexploder_entrypoint_9(local_0, 3, 0);
        _chexploder_entrypoint_9(local_0, 4, 1);
        _chexploder_entrypoint_10(local_0, D_80800C50_chphlegm);
        _subaddiefade_entrypoint_3(local_0);
        break;
    default: return 0;
    }
    return 1;
}

s32 func_80800704_chphlegm(s32 param_0, s32 param_1){
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_80101870(param_0, param_1);
}

void func_80800748_chphlegm(Actor *param_0, f32 param_1, s32 param_2)
{
    f32 local_0[3];
    s32 local_1;
    func_800EE7F8(local_0, param_0->position);
    local_0[1] += param_0->scale * param_1;
    local_1 = func_800B53A4(10);
    func_800BA3FC(local_1, param_2);
    func_800BABB8(local_1, param_0->position, local_0, param_0->scale, D_80800C5C_chphlegm);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800C88_chphlegm);
}

int func_808007EC_chphlegm(Actor *param_0, s32 param_1)
{
  s32 *local_0;
  local_0 = func_800B53A4(2);
  func_800BA3FC(local_0, param_1);
 do { } while (0);
  func_800BABB8(local_0, (char *)param_0 + 4, 0, *((f32 *) (((char *) param_0) + 0x38)), D_80800C98_chphlegm);
}

void func_80800848_chphlegm(s32 arg0) 
{
}
void func_80800850_chphlegm(Actor *param_0)
{
    s32 local_0;
    func_8010D254(param_0->actorData);
    switch ((u32)*(u16 *)((u8 *)param_0 + 0x72) >> 10) {
        case 1:
            if (!func_800C954C()) {
                func_80101FDC(param_0, 2);
            }
            return;
        case 2:
            local_0 = func_800F55FC(func_800F54E4());
            if (!func_800DA298(0x1A6) && func_800EFFB4(param_0->position, 1000.0f, (f32 *)param_0->actorData)) {
                func_800DA544(0x1A6);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1800, 4, 0, 0x57);
            }
            if ((s32)((u32)local_0 << 4) < 0 && func_80090150()) {
                if (!func_800DA298(0x170)) {
                    func_800DA544(0x170);
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x17FF, 4, 0, 0x57);
                    func_80101FDC(param_0, 4);
                    return;
                }
                func_80108B04(param_0, 0);
                func_80101FDC(param_0, 3);
                param_0->unk58 = func_800DC178(3.0f, 4.0f);
                return;
            }
            break;
        case 3:
            if (func_800D9078(&param_0->unk58)) {
                func_80101FDC(param_0, 2);
            }
            break;
    }
}

s32 func_808009DC_chphlegm(Actor *param_0, s32 param_1, PhlegmEvent9DC param_2)
{
    switch (param_1) {
    case 0x3D:
        func_80800A58_chphlegm(param_0);
        break;
    case 0x2E:
        func_80101FDC(param_0, 2);
        break;
    case 0x95:
        func_80101FDC(param_0, 1);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800A58_chphlegm(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    Actor *local_3;

    _subaddieaudioquick_entrypoint_2(param_0, D_80800CD8_chphlegm, D_80800CC4_chphlegm);
    func_8008FE68(local_2);
    func_800EE7F8(local_1, local_2);
    func_800EE7F8(local_0, local_2);
    local_0[1] += 2500.0f;
    local_3 = func_80108528(0x398, local_0, 0, &param_0);
    func_80102FDC(local_3, func_800DC178(3.0f, 4.0f));
    func_800EFB24((f32 *)&local_3->actorData[4], local_1, local_0);
    func_800EF368((f32 *)&local_3->actorData[4], 3500.0f);
    local_3->unk64_19 = 1;
}
