#include "common.h"

extern int D_80800480_changlerbossflare[];
typedef struct {
    u8 pad[0x54];
    s32 f54;
    u8 pad58[0x1B];
    u8 pad73 : 7;
    u8 flag : 1;
} FlareS;
extern u8 D_808004C8_changlerbossflare[];
extern void _subaddieaudioquick_entrypoint_2();
extern void func_8010A3E8(FlareS *, f32);
extern s32 func_800C8A98(void);
extern u8 D_808004DC_changlerbossflare[];
extern u8 D_808004F4_changlerbossflare[];
extern f32 func_800D8FF8(void);
extern void func_800C8E54(s32, f32, f32);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern u8 D_80800500_changlerbossflare[];
extern u8 D_8080053C_changlerbossflare[];
extern u8 D_80800550_changlerbossflare[];
extern f32 func_80103EAC(Actor *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
void func_80800190_changlerbossflare();
int func_8080021C_changlerbossflare();
void func_808003A4_changlerbossflare();

int *changlerbossflare_entrypoint_0()
{
    return &D_80800480_changlerbossflare;
}

void func_8080000C_changlerbossflare(FlareS *param_0)
{
    _subaddieaudioquick_entrypoint_2(param_0, (u8 *) param_0 + 4, D_808004C8_changlerbossflare);
    func_8010A3E8(param_0, 0.3f);
    param_0->f54 = func_800C8A98();
    param_0->flag = 1;
}

void func_80800068_changlerbossflare(Actor *param_0)
{
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808004DC_changlerbossflare);
    *(f32 *) ((u8 *) param_0 + 0x18) += func_800D8FF8() * 300.0f;
    if (param_0->unk70_10 == 1) {
        func_800C8E54(*(s32 *) ((u8 *) param_0 + 0x54), param_0->scale * 400.0f,
                      param_0->scale * 1000.0f);
        func_800C8E84(*(s32 *) ((u8 *) param_0 + 0x54), D_808004F4_changlerbossflare);
        func_800C8CB8(*(s32 *) ((u8 *) param_0 + 0x54), param_0->position);
        func_8080021C_changlerbossflare(param_0);
        func_808003A4_changlerbossflare(param_0);
        if (func_8010B990(param_0, 0x400007) & 0x20) {
            func_80800190_changlerbossflare(param_0);
        }
    }
}

s32 func_80800154_changlerbossflare(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x40) {
        func_80800190_changlerbossflare(param_0);
    } else {
        return 0;
    }
    return 1;
}

void func_80800190_changlerbossflare(param_0) Actor *param_0;
{
    if (*(s32 *) ((u8 *) param_0 + 0x54)) {
        *(s32 *) ((u8 *) param_0 + 0x54) =
            _chlightfader_entrypoint_1(*(s32 *) ((u8 *) param_0 + 0x54), 1.4f, 2);
    }
    func_800BBCB8(param_0->position, param_0->position, 1.0f, 12, D_80800500_changlerbossflare);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080053C_changlerbossflare);
    func_8010A570(param_0);
    func_800FFAB0(param_0);
}

int func_8080021C_changlerbossflare(param_0)
Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    s32 local_5;
    s32 local_6;
    func_800F1A88((u8 *) param_0 + 0x28, local_0);
    local_0[0] += 90;
    local_0[2] = 0.0f;
    if (!func_8001210C(1)) {
        local_3 = func_80103EAC(param_0) * 0.35f;
        local_5 = func_800B53A4(4);
        func_800BA3FC(local_5, 0x9E2);
        for (local_6 = 0, local_4 = 0.0f; local_6 != 4; local_6++) {
            func_800EEB9C(local_2, *(f32 *) ((u8 *) param_0 + 0x18) + local_4, local_3);
            func_800EF5A0(local_2, local_0, local_2[0], local_2[1], local_2[2]);
            func_800EE780(local_1, param_0->position, local_2);
            func_800BABB8(local_5, local_1, 0, 1.0f, D_80800550_changlerbossflare);
            local_4 += 90.0f;
        }
    }
}

void func_808003A4_changlerbossflare(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[2];

    if (param_0->unk64_20 && func_800F6438(param_0->unk6C_0)) {
        func_800F5A00(param_0->unk6C_0, local_0);
        if (func_800EEB40(param_0->position, local_0) < 1440000.0f) {
            param_0->unk64_20 = 0;
        } else {
            func_800F18FC(param_0->position, local_0, local_1);
            func_800EEBF0((f32 *) &param_0->actorData[4], local_1,
                          func_800EEF94((f32 *) &param_0->actorData[4]));
        }
    }
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800480_changlerbossflare[18] = {0x2A8045F,
                                        0x7FB0001,
                                        0x0,
                                        (u32) func_80800068_changlerbossflare,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x21004,
                                        0x0,
                                        (u32) func_80108ED0,
                                        0x0,
                                        (u32) func_8080000C_changlerbossflare,
                                        (u32) func_80107C2C,
                                        0x0,
                                        (u32) func_80800154_changlerbossflare,
                                        0x0};
u8 D_808004C8_changlerbossflare[20] = {0x0, 0x13, 0x5, 0xE0, 0x0, 0x1B, 0x0, 0x18, 0x0, 0x2,
                                       0x0, 0xD,  0x1, 0x40, 0x1, 0x59, 0x0, 0x0,  0x0, 0x0};
u8 D_808004DC_changlerbossflare[24] = {0x0, 0x13, 0x5, 0x2E, 0x0,  0x1B, 0x0, 0x18,
                                       0x0, 0x1,  0x3, 0xE8, 0x1F, 0x40, 0x0, 0xE,
                                       0x0, 0xC0, 0x0, 0xD9, 0x1,  0x80, 0x0, 0x0};
u8 D_808004F4_changlerbossflare[12] = {0x0, 0x0,  0x0, 0xFF, 0x0, 0x0,
                                       0x0, 0xFF, 0x0, 0x0,  0x0, 0x60};
u8 D_80800500_changlerbossflare[60] = {
    0x0,  0x1D, 0x9,  0xEA, 0x0,  0x16, 0x2,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x99, 0x0,
    0x2B, 0x0,  0xC0, 0x1,  0x0,  0x0,  0x22, 0x0,  0xCC, 0x1,  0x0,  0x0,  0x40, 0x0,  0x59,
    0x0,  0x2D, 0x0,  0x64, 0x0,  0xC8, 0x0,  0xE,  0x0,  0x28, 0x0,  0x3C, 0x0,  0x1B, 0xFF,
    0x6A, 0xFF, 0x9C, 0x0,  0x27, 0xFF, 0x38, 0xFF, 0x38, 0x0,  0xC8, 0x0,  0xC8, 0x0,  0x0};
u8 D_8080053C_changlerbossflare[20] = {0x0, 0x13, 0x4, 0x13, 0x0, 0x1B, 0x0, 0x18, 0x0, 0x2,
                                       0x0, 0xD,  0x1, 0x26, 0x1, 0x40, 0x0, 0x0,  0x0, 0x0};
u8 D_80800550_changlerbossflare[48] = {
    0x0, 0x16, 0x0, 0x4,  0x0, 0x22, 0x0, 0x99, 0x0, 0xCC, 0x0, 0x26, 0x0, 0x33, 0x0, 0x15,
    0x0, 0x19, 0x0, 0x99, 0x0, 0x2B, 0x0, 0x99, 0x0, 0xCC, 0x0, 0x27, 0x0, 0x14, 0x0, 0x14,
    0x0, 0x3C, 0x0, 0x3C, 0x1, 0x1A, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
