#include "common.h"

extern s32 D_808008F4_chtorpedo[];
extern s32 D_80800918_chtorpedo[];
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern u8 D_808008B4_chtorpedo[];
extern u8 D_80800840_chtorpedo[];
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_800EFA98(f32 *, f32 *, f32);
extern u8 D_80800950_chtorpedo[];
extern s32 func_800C8A98(void);
extern void func_800C8E54(s32, f32, f32);
extern void func_80109BEC(f32 *, f32, s32, s32, s32, Unk80132ED0 *);
extern s32 func_8010CC10(f32 *, f32);
extern void *func_80100094(Actor *, u32);
extern void func_800F7A7C(s32, s32, s32, s32, f32 *);
extern void _chlightfader_entrypoint_1(s32, f32, s32);
extern u8 unk2C[];
typedef struct { s8 unk0; u8 pad1[0x13]; f32 unk14[3]; f32 unk20; } ActorLocal_Torpedo;
extern f32 func_800D8FF8(void);
extern void _sumissilehome_entrypoint_6(Actor *, ActorLocal_Torpedo *);
extern s32 func_8010B990(Actor *, s32);
extern void func_8010AA78(f32 *);
extern void func_8010A590(Actor *);
extern void func_800CB840(s32, Actor *);
extern s32 func_800CD820(Unk80132ED0 *, f32 *, f32 *, f32);
extern void func_800CB870(void);
extern void func_8010A570(Actor *);
extern s32 func_8010D350(f32 *, f32 *, f32, s32);
extern void func_800FFAB0(Actor *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void _sumissilehome_entrypoint_2(Actor *, void *, f32);
extern void _sumissilehome_entrypoint_5(Actor *, void *, f32, f32);
typedef struct { u8 pad_0[0x28]; s32 active; void (*callback)(Unk80132ED0 *, s32, s32); s32 argument; } TorpedoEvents;
extern int D_8080095C_chtorpedo;

void func_80800000_chtorpedo(Actor *param_0, u8 *param_1)
{
    f32 *local_0;

    local_0 = param_0->position;
    if (param_0->position[1] < *(f32 *)(param_1 + 0x24)) {
        func_800BABB8(_fxairbub_entrypoint_1(local_0, 5.0f, param_0->position[1] + 200.0f, 1.0f), local_0, 0, 1.0f, D_808008F4_chtorpedo);
    } else {
        func_800BABB8(_fxdlsmoke_entrypoint_0(local_0), local_0, 0, 1.0f, D_80800918_chtorpedo);
    }
}

void func_808000B8_chtorpedo(Actor *param_0)
{
    u8 *local_0;
    f32 local_1[3];

    local_0 = func_80100094(param_0, 0);
    if (!*(s32 *)(local_0 + 0x28)) {
        func_800E1610(0, 20.0f, 0.6f, param_0->position);
        func_800EFA98(local_1, (f32 *)((u8 *)param_0 + 0x28), -70.0f);
        func_800EF04C(local_1, param_0->position);
        func_800BABB8(0, local_1, 0, 1.0f, (s32 *)D_808008B4_chtorpedo);
        func_800EFA98(local_1, (f32 *)((u8 *)param_0 + 0x28), -50.0f);
        func_800EF04C(local_1, param_0->position);
        if (param_0->position[1] < *(f32 *)(local_0 + 0x24)) {
            func_800BABB8(_fxairbub_entrypoint_1(local_1, 100.0f, local_1[1] + 200.0f, 1.0f),
                local_1, param_0->position, 1.0f, (s32 *)D_80800840_chtorpedo);
        }
    }
}

void func_808001E0_chtorpedo(Actor *param_0, s32 param_1)
{
    s32 local_1;
    s32 local_2;
    f32 local_0[3];

    if (param_1 == param_0->unk70_10) return;
    func_80101FDC();
    if (param_0->unk70_10 == 3) {
        local_1 = func_800C8A98();
        func_800C8E84(local_1, D_80800950_chtorpedo);
        func_800C8CB8(local_1, param_0->position);
        func_800C8E54(local_1, 300.0f, 750.0f);
        func_800CB840(6, param_0);
        func_80109BEC(param_0->position, 150.0f, 2, 0, 0, param_0->unk0);
        if (func_8010CC10(param_0->position, 150.0f)) {
            func_800EFA98(local_0, (f32 *)((u8 *)param_0 + 0x28), -200.0f);
            func_800EF04C(local_0, param_0->position);
            func_8010CCE0();
            local_2 = func_8010CCEC();
            while (local_2 != -1) {
                func_800F7A7C(local_2, *(s8 *)func_80100094(param_0, 0), 1, 7, local_0);
                local_2 = func_8010CCEC();
            }
        }
        _chlightfader_entrypoint_1(local_1, 1.0f, 1);
        func_800CB870();
        func_808000B8_chtorpedo(param_0);
    }
}

int func_80800350_chtorpedo(s32 param_0)
{
  f32 local_0[2];
  func_800F1A88(param_0 + 0x28, local_0);
  (*(f32 *)((char *)(param_0) + 0x44)) = -local_0[0];
  (*(f32 *)((char *)(param_0) + 0x48)) = local_0[1];
}

void func_80800394_chtorpedo(s32 param_0)
{
  Actor *local_0;
  char *new_var;
  local_0 = func_80100094(param_0, 0);
  new_var = (char *) local_0;
  if ((*((s32 *) (((char *) local_0) + 0x2C))) != 0)
  {
    (*((void (*)(s32, s32, s32)) (*((s32 *) (new_var + 0x2C)))))(*((s32 *) (((char *) param_0) + 0x0)), 5, *((s32 *) (new_var + 0x30)));
  }
}

void func_808003DC_chtorpedo(Actor *this)
{
    f32 timer;
    f32 dt;
    s32 hit;
    s32 msg;
    s32 done;
    ActorLocal_Torpedo *local;
    s32 pad;

    local = func_80100094(this, 0);
    timer = local->unk20;
    dt = func_800D8FF8();
    switch (this->unk70_10) {
    case 2:
        _sumissilehome_entrypoint_6(this, local);
        msg = func_8010B990(this, 0x100004);
        if (msg == 0x20) {
            func_8010AA78(this->position);
        }
        func_80800350_chtorpedo(this);
        this->rotation[2] += dt * 1200.0f;
        func_80800000_chtorpedo(this, local);
        func_8010A590(this);
        func_800CB840(6, this);
        hit = func_800CD820(this->unk0, local->unk14, this->position, 40.0f);
        func_800CB870();
        func_8010A570(this);
        done = (hit != 0);
        if (func_8010D350(local->unk14, this->position, 40.0f, local->unk0) != -1) {
            done = 1;
        }
        if (msg == 0x20 || done || 3.0f < timer) {
            func_808001E0_chtorpedo(this, 3);
        }
        break;
    case 3:
        func_800FFAB0(this);
        break;
    }
    local->unk20 = timer + dt;
    func_800EE7F8(local->unk14, this->position);
}

void *chtorpedo_entrypoint_0(f32 *param_0, f32 *param_1, f32 *param_2, s32 param_3, s32 param_4, f32 param_5)
{
    Actor *local_2;
    f32 local_0[3];
    u8 *local_3;
    f32 local_1[3];
    if (func_800C6A7C(param_1, param_0, local_0, 0x20020)) {
        func_800EFB24(local_1, param_1, param_0);
        func_800EF368(local_1, 1.0f);
        func_800EF04C(param_0, local_1);
    }
    local_2 = (Actor *)func_80108474(0x168, param_0, 0);
    local_3 = (u8 *)func_80100094(local_2, 0);
    if (1) {}
    *(f32 *)((u8 *)local_2 + 0x34) = 0.0f;
    func_800EE7F8((u8 *)local_2 + 0x28, param_2);
    func_80800350_chtorpedo(local_2);
    func_800EE7F8(local_3 + 0x14, param_0);
    *(f32 *)(local_3 + 0x20) = 0.0f;
    *(s32 *)(local_3 + 0x2C) = param_3;
    *(s32 *)(local_3 + 0x30) = param_4;
    *(f32 *)(local_3 + 0x24) = param_5;
    *(s32 *)(local_3 + 0x28) = 0;
    func_8010A570(local_2);
    _sumissilehome_entrypoint_0(local_2, local_3);
    _sumissilehome_entrypoint_3(local_2, local_3, param_4);
    if (func_800EA05C() == 0x181) _sumissilehome_entrypoint_1(local_2, local_3, 0x1C7);
    else if (func_800EA068(0x20)) _sumissilehome_entrypoint_4(local_2, local_3, 1);
    _sumissilehome_entrypoint_2(local_2, local_3, 4000.0f);
    _sumissilehome_entrypoint_5(local_2, local_3, 4000.0f, 1200.0f);
    func_808001E0_chtorpedo(local_2, 2);
    return local_2->unk0;
}

s32 func_80800720_chtorpedo(Actor *param_0, s32 param_1, s32 param_2)
{
    TorpedoEvents *local_0;
    local_0 = (TorpedoEvents *)func_80100094(param_0, 0);
    switch (param_1) {
    case 0x2C:
        local_0->callback = 0;
        func_800FFAB0(param_0);
        return 1;
    case 5:
        func_808001E0_chtorpedo(param_0, 3);
        return 1;
    case 0x95:
        func_80109EEC(param_0, 0x10);
        return 1;
    case 0x78:
        if (local_0->callback) {
            local_0->callback(param_0->unk0, 0x78, local_0->argument);
            local_0->callback = 0;
        }
        func_800FFAB0(param_0);
        return 1;
    case 0x98:
        local_0->active = 1;
        break;
    default:
        return 0;
    }
    return 1;
}

int *chtorpedo_entrypoint_1()
{
    return &D_8080095C_chtorpedo;
}
