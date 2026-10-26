#include "common.h"

extern u8 D_8080079C_chwallsnakebaddy[];
extern u8 D_808007A8_chwallsnakebaddy[];
extern void _chbaddiesetup_entrypoint_10(void);
extern void func_800EF1B8(f32 *, f32, f32);
extern void _chbaddiesetup_entrypoint_5(void (*)(void), s32, s32, s32, s32, s32);
extern void func_800EEB9C(f32 *, f32, f32);
typedef union { s32 local_0; void *local_1; } WallSnakeEvent;
extern void *D_808007B4_chwallsnakebaddy;
typedef struct { u32 pad64_30 : 2; u32 unk64_29 : 1; u32 pad64_0 : 29; } ActorFlags64;
extern u8 D_808006F4_chwallsnakebaddy[];
extern u8 D_80800700_chwallsnakebaddy[];
extern u8 D_80800710_chwallsnakebaddy[];
extern f32 func_800D8FF8(void);
extern u32 func_800F54E4(void);
extern s32 func_80101DDC(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern void func_80102424(Actor *, s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern f32 func_800F5F7C(s32);
extern s32 _subaddiejoy_entrypoint_6(Actor *, s32);
extern s32 func_8010CA74(f32 *, s32);
extern void func_80107070(Actor *, s32);
extern s16 D_80800750_chwallsnakebaddy[];
extern u8 D_8080075A_chwallsnakebaddy[];
extern u8 D_8080075C_chwallsnakebaddy[];
extern s32 D_80800764_chwallsnakebaddy[];
extern s32 D_80800720_chwallsnakebaddy[];
extern s32 D_8080078C_chwallsnakebaddy[];
extern u8 D_80800798_chwallsnakebaddy[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800DBEFC(s32, s32, f32 *);
extern s32 func_80104130(void);
extern void func_800BAB80(s32, void *);

void func_80800000_chwallsnakebaddy(Actor *this)
{
    f32 d;

    switch (this->unk70_10) {
    case 1:
        if (0.0f < this->unk58) {
            this->unk58 -= func_800D8FF8();
        } else {
            d = func_800F5F7C(func_800F54E4());
            if ((((ActorFlags64 *)(&this->pad60 + 1))->unk64_29 && _subaddiejoy_entrypoint_6(this, 1) == 1) || (!((ActorFlags64 *)(&this->pad60 + 1))->unk64_29 && func_8010CA74(this->position, this->unk74_7))) {
                if ((d <= this->position[1]) ? (this->position[1] - 500.0f <= d) : (d <= this->position[1] + 360.0f)) {
                    func_80102424(this, (d <= this->position[1]) ? 2 : 3);
                    _subaddieaudioquick_entrypoint_2(this, this->position, D_808006F4_chwallsnakebaddy);
                }
            }
        }
        break;
    case 2:
    case 3:
        if (func_80101E14(this, 0.18f) || func_80101E14(this, 0.31f)) {
            _subaddieaudioquick_entrypoint_2(this, this->position, D_80800700_chwallsnakebaddy);
        }
        if (func_80101E14(this, 0.6f)) {
            _subaddieaudioquick_entrypoint_2(this, this->position, D_80800710_chwallsnakebaddy);
        }
        if (func_80101E14(this, 0.999f)) {
            func_80102424(this, 1);
            this->unk58 = 0.4f;
        }
        break;
    case 4:
    case 5:
        if (func_80101DDC(this)) {
            func_80107070(this, 3);
        }
        if (0.7f < func_80101F24(this)) {
            this->unk64_19 = 0;
        }
        break;
    }
}

void func_8080027C_chwallsnakebaddy(Actor *param_0, s32 param_1)
{
    s32 local_0;
    s16 *local_1;
    f32 local_4[3];
    u8 *local_2;
    s32 local_3;
    s32 local_5;
    s32 local_6;

    if (param_0->unk70_10 == 4 || param_0->unk70_10 == 5) local_0 = 1;
    else local_0 = 0;
    func_800DF744(3, param_0->unk70_10 == 1 || func_801072A8(param_0) ? 0 : 1);
    func_800DF744(4, local_0 ^ 1);
    func_800DF744(5, local_0);
    func_80101870(param_0, param_1);
    if (param_0->unk7C_12) {
        if (param_0->unk64_20) {
            param_0->unk64_20 = 0;
            param_0->unk64_19 = 1;
            func_800DBEFC(func_80104130(), 4, local_4);
            local_2 = D_8080075C_chwallsnakebaddy; local_1 = D_80800750_chwallsnakebaddy;
            do {
                local_3 = func_800B53A4(*local_2);
                func_800BA670(local_3, *local_1);
                func_800BABB8(local_3, local_4, local_4, param_0->scale, D_80800764_chwallsnakebaddy);
                func_800BA22C(local_3, *local_2);
                local_2++;
                local_1++;
            } while ((u8 *)local_1 != D_8080075A_chwallsnakebaddy);
            local_3 = func_800B53A4(5);
            func_800BABB8(local_3, local_4, NULL, param_0->scale, D_80800720_chwallsnakebaddy);
            func_800BABB8(local_3, local_4, NULL, param_0->scale, D_8080078C_chwallsnakebaddy);
            func_800BA22C(local_3, 5);
            if (1) {}
        }
        if (param_0->unk64_19) {
            if (func_801072A8(param_0)) param_0->unk64_19 = 0;
            func_800DBEFC(func_80104130(), 4, local_4);
            if ((func_8001211C() & 1) == 1) {
                local_0 = func_800B53A4(1);
                func_800BABB8(local_0, local_4, NULL, param_0->scale * 0.35f, D_80800720_chwallsnakebaddy);
                func_800BAB80(local_0, D_80800798_chwallsnakebaddy);
                func_800BA22C(local_0, 1);
            }
        }
    }
}

void func_808004FC_chwallsnakebaddy(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    param_0->unk64_20 = 1;
    func_8010A570(param_0);
    func_80102424(param_0, param_0->unk70_10 == 2 ? 4 : 5);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080079C_chwallsnakebaddy);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808007A8_chwallsnakebaddy);
    if (func_8010A430(param_0)) {
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], 60.0f);
        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3, *(s32 *)&local_0[0], *(s32 *)&local_0[1], *(s32 *)&local_0[2], *(s32 *)&param_0->rotation[1]);
    }
}

s32 func_808005D8_chwallsnakebaddy(Actor *param_0, s32 param_1, WallSnakeEvent param_2)
{
    f32 local_0[3];

    switch (param_1) {
    case 0x40:
        func_808004FC_chwallsnakebaddy(param_0, param_2.local_0);
        break;
    case 0x97:
        func_800EEB9C(local_0, param_0->rotation[1], 150.0f);
        func_80101010(local_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800650_chwallsnakebaddy()
{
    func_80105010();
}

void *chwallsnakebaddy_entrypoint_0(void)
{
  return &D_808007B4_chwallsnakebaddy;
}
