#include "common.h"

extern int D_80800994_cheggsplode;
typedef struct { u8 pad_0[6]; s16 local_0; u8 pad_1[8]; s32 local_1; } CodexEggSplodeData;
extern u32 D_808009DC_cheggsplode[];
extern void *func_80100094(Actor *, s32);
typedef struct { u8 pad_0[0x10]; s32 local_0; } ExplosiveEggLight;
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern s32 D_808008B0_cheggsplode;
extern s32 D_80800980_cheggsplode;
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_800187B4(s32, f32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 func_800F6BE4(s32);
extern s32 func_800F693C(s32);
extern Actor *func_801084B0(s32, f32 *);
typedef struct { s32 local_0; s16 local_1; s16 local_2; s32 pad_0; f32 local_3; } EggExplosion;
extern Actor *func_80108474(s32, f32 *, s32);
extern u8 D_808009E8_cheggsplode[];
extern s32 func_800B53A4(s32);
extern void func_800BA670(s32, s32);
extern void func_800BA22C(s32, s32);
extern int func_800D3948(void);
extern int func_800F6CC8(int);
typedef struct { s32 unk0; s16 unk4; s16 unk6; f32 unk8; f32 unkC; s32 unk10; } EggSplodeLocal;
extern u8 D_80800820_cheggsplode[];
extern u8 D_80800868_cheggsplode[];
extern u8 D_808008E0_cheggsplode[];
extern f32 func_800D8FF8(void);
extern s32 func_8010CC10(f32 *, f32);
extern void func_80109C4C(f32 *, f32, s32, s32, s32, s32, s32);
extern void func_800C8E54(s32, f32, f32);
void func_808006F0_cheggsplode();
void func_80800778_cheggsplode();
void func_8080000C_cheggsplode();

int cheggsplode_entrypoint_0()
{
    return (int)&D_80800994_cheggsplode;
}

s32 func_808007D4_cheggsplode();

void func_8080000C_cheggsplode(this, arg1) Actor *this; s32 arg1;
{
    f32 dist;
    f32 old;
    f32 scale;
    EggSplodeLocal *local;
    s32 s2;
    s32 s3;
    s32 id;

    local = func_80100094(*(Actor **)&this, 0);
    old = local->unk8;
    local->unk8 += func_800D8FF8();
    scale = local->unk8 * 2.2222223f;
    if (0.12f < local->unk8 && old < 0.12f) {
        func_800BABB8(0, this->position, 0, 1.0f, D_80800820_cheggsplode);
        func_800BABB8(0, this->position, 0, 1.0f, D_80800868_cheggsplode);
        if (!func_800D3948()) {
            func_800BABB8(0, this->position, 0, 1.0f, D_808008E0_cheggsplode);
        }
    }
    if (1.0f < scale) {
        scale = 1.0f;
        this->unk70_10 = 5;
    }
    dist = (local->unkC - 50.0f) * scale + 50.0f;
    if (local->unk6 == 0 && func_800F6BE4(local->unk0) && func_8010CC10(this->position, dist)) {
        s2 = local->unk0;
        s3 = _gcegg_entrypoint_7(local->unk4);
        func_8010CCE0();
        for (id = func_8010CCEC(); id != -1; id = func_8010CCEC()) {
            if (func_808007D4_cheggsplode(this, id)) {
                func_800F7A7C(id, s2, s3, 5, this->position);
                func_80800778_cheggsplode(this, id);
            }
        }
    }
    if (local->unk6 == 0) {
        func_800CB840(7, this);
        func_80109C4C(this->position, dist, 2, 0, 0, *(s32 *)this, arg1);
        func_800CB870();
    }
    if (local->unk10 != 0) {
        func_800C8E54(local->unk10, 1.5f * dist, 3.5f * dist);
    }
}

s32 func_808002A8_cheggsplode(Actor *param_0, s32 param_1, s32 param_2)
{
    CodexEggSplodeData *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x9F:
        if (!func_800D3948()) {
            local_0->local_0 = 1;
        }
        return 1;
    case 0x95:
        if (func_800BF8E4() > 0) {
            local_0->local_1 = func_800C8A98();
            func_800C8E84(local_0->local_1, D_808009DC_cheggsplode);
            func_800C8CB8(local_0->local_1, param_0->position);
        }
        return 1;
    }
    return 0;
}

void func_8080035C_cheggsplode(Actor *param_0)
{
    ExplosiveEggLight *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 2:
    case 3:
        func_8080000C_cheggsplode(param_0, 0x26F);
        return;
    case 4:
        func_8080000C_cheggsplode(param_0, 0x270);
        return;
    case 5:
        if (local_0->local_0) local_0->local_0 = _chlightfader_entrypoint_1(local_0->local_0, 1.0f, 2);
        func_800FFAB0(param_0);
        return;
    }
}

void func_8080041C_cheggsplode(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = *(s32 *)local_0;
    if (!func_800F6BE4(local_1)) {
        local_1 = func_800F54E4();
    }
    *(f32 *)(local_0 + 8) = 0.0f;
    func_800E1610(0, 20.0f, 0.6f, param_0->position);
    func_800187B4(func_800F54F0(local_1), 0.85f, 0.45f, 0.6f);
    param_0->position[1] += 60.0f;
    func_800BABB8(0, param_0->position, 0, 1.0f, &D_808008B0_cheggsplode);
    if (*(s16 *)(local_0 + 4) != 5) {
        func_808006F0_cheggsplode(param_0);
    }
    func_8010D930(6, -1, param_0->position, &D_80800980_cheggsplode);
    *(s32 *)(local_0 + 0x10) = 0;
    if (func_800F6BE4(local_1)) {
        func_80800778_cheggsplode(param_0, local_1);
    }
}

f32 func_80800548_cheggsplode(s32 param_0) {
    f32 local_0;
    if (func_800F6BE4(param_0)) {
        if (func_800F693C(param_0)) {
            local_0 = 250.0f;
        } else {
            local_0 = 190.0f;
        }
        return local_0;
    }
    return 190.0f;
}

void cheggsplode_entrypoint_1(f32 *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    EggExplosion *local_1;

    local_0 = func_801084B0(0x2B2, param_0);
    local_1 = func_80100094(local_0, 0);
    local_1->local_2 = 0;
    local_1->local_1 = param_2;
    local_1->local_0 = param_1;
    switch (param_2) {
    case 6:
        local_0->unk70_10 = 3;
        local_1->local_3 = 350.0f;
        break;
    case 4:
        local_0->unk70_10 = 2;
        local_1->local_3 = func_80800548_cheggsplode(param_1);
        break;
    }
}

void cheggsplode_entrypoint_2(f32 *param_0, f32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    Actor *local_0;
    EggExplosion *local_1;

    local_0 = func_80108474(0x2B2, param_0, (s32)param_1);
    local_1 = func_80100094(local_0, 0);
    local_1->local_0 = param_2;
    local_1->local_1 = param_3;
    local_1->local_2 = param_4 == 0;
    if (param_3 == 5) {
        local_0->unk70_10 = 4;
        local_1->local_3 = func_80800548_cheggsplode(param_2);
    }
}

void func_808006F0_cheggsplode(param_0) Actor *param_0;
{
    u16 local_1;
    s32 local_0;

    local_0 = func_800B53A4(6);
    if (param_0->unk70_10 == 3) {
        local_1 = 0x875;
    } else {
        local_1 = 0x9B1;
    }
    func_800BA670(local_0, local_1);
    func_800BABB8(local_0, param_0->position, param_0->position, 0.25f, D_808009E8_cheggsplode);
    func_800BA22C(local_0, 6);
}

void func_80800778_cheggsplode(param_0, param_1) s32 param_0; s32 param_1;
{
    if (func_800D3948() == 0)
    {
        if (func_800F6BE4(param_1) && func_800F6CC8(param_1))
        {
            void *local_0 = func_80100094(param_0, 0);
            *(u16 *)((char *)local_0 + 6) = 1;
        }
    }
}

s32 func_808007D4_cheggsplode(s32 param_0, s32 param_1)
{
  s32 out;
  out = func_800F6478(param_1);
  if (out == 0)
  {
    return 0;
  }
  return 1;
}
