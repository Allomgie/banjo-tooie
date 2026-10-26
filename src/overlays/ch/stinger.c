#include "common.h"

extern s32 D_808007D0_chstinger;
extern s32 D_808007FC_chstinger;
extern s32 D_80800844_chstinger;
extern f32 func_800DC178(f32, f32);
extern void func_800EFA98(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern void func_800CB840();
extern void func_80101FDC();
typedef struct { u8 pad_0[0x28]; u8 local_0; } StingerLife;
extern void func_80109BEC(f32 *, f32, s32, s32, s32, Unk80132ED0 *);
extern void func_800F1A88(int, f32 *);
extern void func_800F5A00(s32, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern int D_80800870_chstinger;
extern void _sumissilehome_entrypoint_6();
extern void func_800FFAB0();
extern void func_80103014();
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern s32 func_800CD820(Unk80132ED0 *, f32 *, f32 *, f32);

void func_80800000_chstinger(Actor *param_0)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    if (param_0->unk7C_12) {
        local_0 = func_800B5BE4(0x1B);
        local_0 = func_800BABB8(local_0,
            param_0->position, param_0->position, 1.0f, &D_808007D0_chstinger);
        func_800EFA98(local_1, (f32 *)((u8 *)param_0 + 0x28),
            func_800DC178(-200.0f, -400.0f));
        func_800BA930(local_0, (s16)local_1[0], (s16)local_1[1], (s16)local_1[2], (s16)local_1[0], (s16)local_1[1], (s16)local_1[2]);
        func_800BA22C(local_0, 3);
        func_800EFA98(local_1, (f32 *)((u8 *)param_0 + 0x28), -25.0f);
        func_800EE780(local_2, param_0->position, local_1);
        func_800BBCB8(local_2, 0, 1.0f, 1, &D_80800844_chstinger);
        func_800EF04C(local_2, local_1);
        local_0 = func_800B5BE4(8);
        func_800BABB8(local_0, local_2, NULL, 1.0f, &D_808007FC_chstinger);
    }
}

void func_8080015C_chstinger(Actor *param_0, s32 param_1)
{
    StingerLife *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    if (param_1 != param_0->unk70_10) {
        func_80101FDC(param_0, param_1);
        local_1 = param_0->unk70_10;
        switch (local_1) {
        case 2: local_0->local_0 = 1; break;
        case 3:
            func_800CB840(4, param_0);
            func_80109BEC(param_0->position, 120.0f, 2, 0, 0, param_0->unk0);
            func_800CB870();
            func_80800000_chstinger(param_0);
            break;
        }
    }
}

void func_80800218_chstinger(s32 param_0)
{
    f32 local_0[2];
    func_800F1A88(param_0 + 0x28, local_0);
    *(f32 *)(param_0 + 0x44) = -local_0[0];
    *(f32 *)(param_0 + 0x48) = local_0[1];
}

void func_8080025C_chstinger(s32 arg0) 
{
}
s32 func_80800264_chstinger(Actor *param_0, f32 *param_1)
{
    f32 local_2;
    f32 local_3;
    s32 local_6;
    s32 local_7;
    f32 local_0[3];
    u8 *local_4;
    f32 *local_5;
    s32 local_8;
    s32 local_9;
    f32 local_1[3];
    local_4 = func_80100094(param_0, 0);
    local_2 = 0.0f;
    local_5 = (f32 *)(local_4 + 0x18);
    local_7 = -1;
    local_8 = *(s8 *)local_4;
    for (local_6 = 0; local_6 < func_800F5898(); local_6++) {
        if (func_800F6438(local_6) && local_6 != local_8) {
            func_800F5A00(local_6, local_1);
            local_3 = func_800EEB40(local_1, local_5);
            if (local_7 < 0 || local_3 < local_2) {
                local_9 = func_800F0734(local_5, param_0->position, local_1, 55.0f, 120.0f, local_0, local_0);
                if (local_9) {
                    local_7 = local_6;
                    local_2 = local_3;
                    func_800EE7F8(param_1, local_0);
                }
            }
        }
    }
    return local_7;
}

s32 func_808003B0_chstinger(s32 param_0) {
    f32 local_1[3];
    s32 local_0;
    s32 local_2;
    if (func_800EA068(0x4000) != 0) {
        local_2 = func_80800264_chstinger(param_0, local_1);
        local_0 = local_2;
        if (local_2 >= 0) {
            func_800F7A7C(local_0, *(s8*)((char*)func_80100094(param_0, 0) + 0x0), 1, 3, local_1);
            return 1;
        }
    }
    return 0;
}

void func_80800420_chstinger(Actor *param_0)
{
    f32 local_0;
    f32 local_1;
    s32 local_3;
    s32 local_2;
    s32 sf_t989;
    u8 *local_6;

    local_6 = func_80100094(param_0, 0);
    local_0 = *(f32 *)(local_6 + 0x14);
    local_1 = func_800D8FF8();
    switch (param_0->unk70_10) {
    case 2:
        if (local_6[0x28]) {
            local_6[0x28] = 0;
            local_2 = 0;
        } else {
            _sumissilehome_entrypoint_6(param_0, local_6);
            local_2 = func_8010B990(param_0, 0x100004);
        }
        if (local_2 == 0x20) func_8010AA78(param_0->position);
        func_80800218_chstinger(param_0);
        param_0->rotation[2] = func_800136E4(param_0->rotation[2] + local_1 * 1200.0f);
        func_80103014(param_0);
        func_8010A590(param_0);
        func_800CB840(4, param_0);
        local_3 = func_800CD820(param_0->unk0, (f32 *)(local_6 + 0x18), param_0->position, 80.0f);
        func_800CB870();
        func_8010A570(param_0);
        if (local_2 == 0x20 || (local_3 != 0) != 0 || *(f32 *)(local_6 + 0x24) > 5000.0f) {
            func_8080015C_chstinger(param_0, 3);
        }
        sf_t989 = func_808003B0_chstinger(param_0);
        if (sf_t989) func_8080015C_chstinger(param_0, 3);
        break;
    case 3:
        func_800FFAB0(param_0);
        break;
    default:
        break;
    }
    *(f32 *)(local_6 + 0x14) = local_0 + local_1;
    *(f32 *)(local_6 + 0x24) += func_800EEAD4(param_0->position, (f32 *)(local_6 + 0x18));
    func_800EE7F8((f32 *)(local_6 + 0x18), param_0->position);
}

s32 chstinger_entrypoint_0(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    u8 *local_4;
    f32 local_0[3];
    f32 local_1[3];
    u8 *local_3;
    f32 local_2[3];

    func_800EFA98(local_0, param_2, 3e+01f);
    func_800EF04C(param_0, local_0);
    if (func_800C6A7C(param_1, param_0, local_1, 0x20020) != 0) {
        func_800EFB24(local_2, param_1, param_0);
        func_800EF368(local_2, 0x3F800000);
        func_800EF04C(param_0, local_2);
    }
    local_4 = func_80108474(0x16F, param_0, 0);
    local_3 = func_80100094(local_4, 0);
    (*(f32 *)((s8 *)(local_4) + (0x34))) = 0.0f;
    func_800EE7F8(local_4 + 0x28, param_2);
    func_80800218_chstinger(local_4);
    (*(f32 *)((s8 *)(local_3) + (0x24))) = 0.0f;
    func_800EE7F8(local_3 + 0x18, param_0);
    (*(f32 *)((s8 *)(local_3) + (0x14))) = 0.0f;
    func_8010A570(local_4);
    _sumissilehome_entrypoint_0(local_4, local_3);
    _sumissilehome_entrypoint_3(local_4, local_3, param_4);
    if (func_800EA068(0x20) != 0) {
        _sumissilehome_entrypoint_4(local_4, local_3, 1);
    } else {
        _sumissilehome_entrypoint_1(local_4, local_3, -1);
    }
    _sumissilehome_entrypoint_5(local_4, local_3, 0x458CA000, 0x44960000);
    func_8080015C_chstinger(local_4, 2);
    return (*(s32 *)((s8 *)(local_4) + (0)));
}

s32 func_80800774_chstinger(Actor *this, s32 param_1, s32 param_2)
{
  Actor *new_var;
  if (param_1 == 0x95)
  {
    new_var = this;
    func_80109EEC(new_var, 16);
  }
  else
  {
    return 0;
  }
  return 1;
}

int chstinger_entrypoint_1()
{
    return (int)&D_80800870_chstinger;
}
