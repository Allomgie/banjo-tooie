#include "common.h"

extern u8 D_8080079C_chwallsnakebaddy[];
extern u8 D_808007A8_chwallsnakebaddy[];
extern void _chbaddiesetup_entrypoint_10(void);
extern void func_800EF1B8(f32 *, f32, f32);
extern void _chbaddiesetup_entrypoint_5(void (*)(void), s32, s32, s32, s32, s32);
extern void func_800EEB9C(f32 *, f32, f32);
typedef union {
    s32 local_0;
    void *local_1;
} WallSnakeEvent;
extern void *D_808007B4_chwallsnakebaddy;
typedef struct {
    u32 pad64_30 : 2;
    u32 unk64_29 : 1;
    u32 pad64_0 : 29;
} ActorFlags64;
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
                if ((((ActorFlags64 *) (&this->pad60 + 1))->unk64_29 &&
                     _subaddiejoy_entrypoint_6(this, 1) == 1) ||
                    (!((ActorFlags64 *) (&this->pad60 + 1))->unk64_29 &&
                     func_8010CA74(this->position, this->unk74_7))) {
                    if ((d <= this->position[1]) ? (this->position[1] - 500.0f <= d)
                                                 : (d <= this->position[1] + 360.0f)) {
                        func_80102424(this, (d <= this->position[1]) ? 2 : 3);
                        _subaddieaudioquick_entrypoint_2(this, this->position,
                                                         D_808006F4_chwallsnakebaddy);
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
        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3, *(s32 *) &local_0[0],
                                    *(s32 *) &local_0[1], *(s32 *) &local_0[2],
                                    *(s32 *) &param_0->rotation[1]);
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

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_808006A0_chwallsnakebaddy[16] = {
    0x0,        0x0,       0x400CCCCD, 0x1A50044, 0x400CCCCD, 0x1A50002, 0x400CCCCD, 0x1A60002,
    0x402CCCCD, 0x1A40002, 0x402CCCCD, 0x1AB0002, 0x0,        0x0,       0x0,        0x0};
u32 D_808006E0_chwallsnakebaddy[5] = {0x10000, 0x0, 0x0, 0x60004, 0x70000};
u8 D_808006F4_chwallsnakebaddy[12] = {0x0,  0x13, 0x4, 0xB7, 0x0, 0x16,
                                      0x7D, 0x0,  0x0, 0x0,  0x0, 0x0};
u8 D_80800700_chwallsnakebaddy[16] = {0x0, 0x13, 0x4, 0xB6, 0x0, 0x16, 0x7D, 0x0,
                                      0x0, 0xD,  0x0, 0xF3, 0x1, 0xC,  0x0,  0x0};
u8 D_80800710_chwallsnakebaddy[16] = {0x0, 0x13, 0x4, 0xB7, 0x0, 0x16, 0x7F, 0xF8,
                                      0x0, 0xA,  0x0, 0xCC, 0x0, 0x0,  0x0,  0x0};
s32 D_80800720_chwallsnakebaddy[12] = {0x1D09DD,  0x2B0199, 0x1CC0022, 0x1800200,
                                       0x2000280, 0x150000, 0x260019,  0x7,
                                       0x2CFFCE,  0xAFFCE,  0x320032,  0x320000};
s16 D_80800750_chwallsnakebaddy[6] = {0x6E0, 0x6E1, 0x6E2, 0x6E4, 0x6E3, 0x0};
u8 D_8080075C_chwallsnakebaddy[8] = {0x8, 0x2, 0x2, 0x2, 0x1, 0x0, 0x0, 0x0};
s32 D_80800764_chwallsnakebaddy[10] = {0x2B0200,  0x280002D,  0x15E01C2, 0x2700C8, 0xC80190,
                                       0x190001B, -0x3E70320, 0x2300CC,  0xC0014,  0x0};
s32 D_8080078C_chwallsnakebaddy[3] = {0xC0064, 0x20468E, 0xBE0000};
u8 D_80800798_chwallsnakebaddy[4] = {0x5F, 0x96, 0xA, 0xE6};
u8 D_8080079C_chwallsnakebaddy[12] = {0x0,  0x13, 0x4, 0x1F, 0x0, 0x16,
                                      0x42, 0x68, 0x0, 0x0,  0x0, 0x0};
u8 D_808007A8_chwallsnakebaddy[12] = {0x0,  0x13, 0x4, 0x15, 0x0, 0x16,
                                      0x42, 0x68, 0x0, 0x0,  0x0, 0x0};
void *D_808007B4_chwallsnakebaddy = (void *) 0x01590111;
static u32 D_808007B4_chwallsnakebaddy_rest[18] = {0x6660001,
                                                   (u32) &D_808006A0_chwallsnakebaddy,
                                                   (u32) func_80800000_chwallsnakebaddy,
                                                   (u32) func_80105834,
                                                   (u32) func_8080027C_chwallsnakebaddy,
                                                   0x7D00000,
                                                   0x0,
                                                   0x0,
                                                   0x22,
                                                   0x0,
                                                   (u32) func_80108ED0,
                                                   0x0,
                                                   (u32) func_80800650_chwallsnakebaddy,
                                                   (u32) func_80107C2C,
                                                   0x80302411,
                                                   (u32) func_808005D8_chwallsnakebaddy,
                                                   (u32) &D_808006E0_chwallsnakebaddy,
                                                   0x0};
