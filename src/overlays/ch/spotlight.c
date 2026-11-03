#include "common.h"

extern int D_808009B0_chspotlight[];
extern void *func_80100094(Actor *, u32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern u8 func_801017D0[];
typedef struct {
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
} CodexSpotlightData;
extern s32 D_80800998_chspotlight[];
extern s32 D_808009A4_chspotlight[];
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern int func_800F3214(s32 *, s32 *, s32 *, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 D_80800990_chspotlight[];
extern void func_800C8D4C(s32, f32 *);
typedef struct {
    u8 pad_0[4];
    f32 local_0[3];
    u8 pad_1[0x18];
    f32 local_1;
    u8 pad_2[4];
    f32 local_2;
    u8 pad_3[4];
    f32 local_3;
} SpotlightAim;
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_80102B2C(Actor *, f32);
extern void func_80102B6C(Actor *, f32);
typedef struct {
    s32 local_0;
    u8 local_1[12];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    s32 local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;
    f32 local_9;
    f32 local_10;
} Mass47Spotlight;
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
extern f32 func_80102D78(Actor *, f32 *);
typedef struct {
    s32 local_0;
    u8 pad_0[0x18];
    f32 local_1;
    f32 local_2;
    s32 local_3;
} SpotlightState;
extern s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern f32 func_800D8FF8(void);
typedef struct {
    u8 pad_0[0x28];
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
} SpotlightMotion;
int func_808008A4_chspotlight();
extern void func_80105834(), func_80107C2C(), func_80800210_chspotlight();

int chspotlight_entrypoint_0()
{
    return (int) &D_808009B0_chspotlight;
}

s32 func_808008EC_chspotlight();

void func_8080000C_chspotlight(Actor *param_0)
{
    Mass47Spotlight *local_3;
    Actor *local_0;
    s32 local_4;
    f32 local_1;
    f32 *local_2[1];

    local_3 = func_80100094(param_0, 0);
    func_800EE7F8(local_3->local_2, param_0->position);
    if (func_800DA298(0x9C) || !func_808008EC_chspotlight(param_0)) {
        func_80101FDC(param_0, 5);
    } else if (func_808008A4_chspotlight(param_0)) {
        local_0 = func_80106790(param_0->unk3C);
        func_800EE7F8(local_3->local_2, local_0->position);
        param_0->rotation[1] = param_0->unk54 = func_80102D78(param_0, local_0->position);
    }
    if ((s32) param_0->unk74_7 < 0x34) {
        local_2[0] = local_3->local_2;
        local_3->local_0 = func_800C8A98();
        local_3->local_3 = param_0->rotation[1];
        local_3->local_5 = 0;
        local_3->local_4 = 0.0f;
        func_800C8D4C(local_3->local_0, D_80800990_chspotlight);
        func_800C8E84(local_3->local_0, (u8 *) D_80800998_chspotlight);
        func_800C8CB8(local_3->local_0, local_2[0]);
        func_800C8FE0(local_3->local_0, 0);
    } else {
        local_3->local_0 = 0;
    }
    local_3->local_6 = func_800DC178(0.0f, 360.0f);
    local_1 = func_800DC178(20.0f, 60.0f);
    local_3->local_7 = (func_800DC298(0.5f) ? 1.0f : -1.0f) * local_1;
    local_3->local_8 = func_800DC178(0.0f, 360.0f);
    local_1 = func_800DC178(20.0f, 60.0f);
    local_3->local_9 = (func_800DC298(0.5f) ? 1.0f : -1.0f) * local_1;
    local_3->local_10 = 525.0f;
}

void func_808007F4_chspotlight(u8 *param_0, f32 param_1);

void func_80800210_chspotlight(param_0) Actor *param_0;
{
    SpotlightState *local_0;
    s32 pad0;
    f32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    _sudeflect_entrypoint_1(param_0->position, param_0->scale * 200.0f, 0.0f,
                            param_0->scale * 125.0f, 10);
    switch (param_0->unk70_10) {
        case 1:
            local_2 = param_0->unk74_7 == 0x33 ? 2 : 4;
            if (func_800DA298(local_2)) {
                func_80101FDC(param_0, 2);
                local_0->local_3 = 1;
                if (local_0->local_0)
                    func_800C8FE0(local_0->local_0, 1);
            }
            break;
        case 2:
            local_1 = local_0->local_2;
            local_1 += 0.06f;
            if (local_1 > 1.0f) {
                local_1 = 1.0f;
                local_0->local_2 = local_1;
                func_80101FDC(param_0, 3);
            } else {
                local_0->local_2 = local_1;
                if (local_1 < 0.9f && func_800DC298(0.6f)) {
                    local_1 *= func_800DC178(0.25f, 0.5f);
                    local_0->local_3 = 0;
                } else {
                    local_0->local_3 = 1;
                }
            }
            func_808007F4_chspotlight(param_0, local_1);
            break;
        case 3:
            func_808007F4_chspotlight(param_0, 1.0f);
            break;
        case 4:
            func_80102B2C(param_0, func_800D8FF8() * 60.0f);
            func_80102B6C(param_0, func_800D8FF8() * 60.0f);
            if (func_80102CCC(param_0) && func_80102CA4(param_0)) {
                param_0->rotation[1] = local_0->local_1;
                param_0->rotation[0] = 0.0f;
                func_80101FDC(param_0, 5);
            }
    }
}

void func_8080047C_chspotlight(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    f32 local_2[3];
    f32 local_3[4];

    local_0 = func_80100094(param_0, 0);
    local_1 = func_801040D0();
    func_801015D0(param_0);
    func_800DF41C(local_1);
    func_800EFA4C(local_2, param_0->rotation[0] + 90.0f, 0.0f, 0.0f);
    func_800D93A0(local_3, local_2);
    func_800DFF2C(local_1, 1, local_3);
    func_800DF744(1, *(s32 *) (local_0 + 0x24));
}

int func_80800518_chspotlight(param_0, param_1)
s32 param_0;
s32 param_1;
{
    f32 local_0[3];
    func_80102780(param_0, local_0);
    local_0[0] = 0.0f;
    func_800DF47C(&func_801017D0, param_0);
    func_800DE448(param_0 + 4, local_0, *(s32 **) (param_0 + 0x38), 0,
                  func_8010347C(*(s32 *) param_0));
}

void func_80800580_chspotlight(param_0) Actor *param_0;
{
    SpotlightMotion *local_0;
    Actor *local_1;
    f32 local_2;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_80106790(param_0->unk3C);
    local_2 = func_800D8FF8();
    local_0->local_0 += local_0->local_1 * local_2;
    local_0->local_2 += local_0->local_3 * local_2;
    local_0->local_4 = *(f32 *) ((u8 *) local_1 + 0x28) * 1500.0f;
}

void func_80800600_chspotlight(Actor *param_0, f32 param_1)
{
    CodexSpotlightData *local_3;
    s32 local_0[3];

    local_3 = func_80100094(param_0, 0);
    func_800EEC30(local_3->local_2, -param_0->rotation[0], param_0->rotation[1],
                  func_800EEAD4(param_0->position, local_3->local_1));
    func_800EF04C(local_3->local_2, param_0->position);
    if (local_3->local_0) {
        func_800F3214(local_0, D_80800998_chspotlight, D_808009A4_chspotlight, param_1);
        func_800C8E84(local_3->local_0, local_0);
        func_800C8CB8(local_3->local_0, local_3->local_2);
    }
}

void func_808006B8_chspotlight(Actor *param_0)
{
    s32 *local_0;
    f32 local_1[2];
    Actor *local_2;
    local_0 = func_80100094(param_0, 0);
    if (local_0[0]) {
        local_2 = func_80106790(param_0->unk3C);
        local_1[0] = D_80800990_chspotlight[0] * *(f32 *) &local_2->actorData[4];
        local_1[1] = D_80800990_chspotlight[1] * *(f32 *) &local_2->actorData[4];
        func_800C8D4C(local_0[0], local_1);
    }
}

void func_80800730_chspotlight(Actor *param_0)
{
    f32 local_0[2];
    SpotlightAim *local_1;

    local_1 = func_80100094(param_0, 0);
    if (!func_800DA298(0)) {
        if (func_8010114C(param_0->unk3C, 6, 4))
            func_80101038(local_1->local_0);
        if (func_800DA298(4))
            func_800EF214(local_1->local_0, local_1->local_1, local_1->local_2, local_1->local_3);
        func_800F18FC(param_0->position, local_1->local_0, local_0);
        param_0->unk50 = -local_0[0];
        param_0->unk54 = local_0[1];
        func_80102B2C(param_0, 2.0f);
        func_80102B6C(param_0, 2.0f);
    }
}

void func_808007F4_chspotlight(u8 *param_0, f32 param_1)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (func_808008A4_chspotlight(param_0) == 0) {
        func_80101FDC(param_0, 4);
        *(f32 *) ((s8 *) param_0 + 0x50) = 0.0f;
        *(f32 *) ((s8 *) param_0 + 0x54) = (f32) *(f32 *) ((s8 *) local_0 + 0x1C);
        local_1 = *(s32 *) ((s8 *) local_0 + 0);
        *(s32 *) ((s8 *) local_0 + 0x24) = 0;
        *(f32 *) ((s8 *) local_0 + 0x20) = 0.0f;
        if (local_1 != 0) {
            func_800C8FE0(local_1, 0);
        }
    } else {
        func_80800580_chspotlight(param_0);
        func_80800730_chspotlight(param_0);
        func_80800600_chspotlight(param_0, param_1);
        func_808006B8_chspotlight(param_0);
    }
}

int func_808008A4_chspotlight(param_0)
Actor *param_0;
{
    s32 local_0;
    if (!param_0->unk3C) {
        return 0;
    }
    local_0 = func_800DA298(3);
    if (local_0 != 0) {
        return 0;
    }
    return 1;
}

s32 func_808008EC_chspotlight(Actor *this)
{
    Actor *local_0 = _subaddiefind_entrypoint_0(this->position, 0x13C, -1, 0);
    if (local_0) {
        this->unk3C = local_0->unk0;
    }
    return local_0;
}

int func_80800934_chspotlight(param_0, param_1, param_2)
s32 param_0;
s32 param_1;
s32 param_2;
{
    if (param_1 == 0x1F) {
        func_8080047C_chspotlight(param_0);
        return 1;
    }
    return 0;
}

f32 D_80800990_chspotlight[2] = {8e+02f, 1.6e+03f};
s32 D_80800998_chspotlight[3] = {0x0, 0x0, 0x0};
s32 D_808009A4_chspotlight[3] = {0xC0, 0xC0, 0xC0};
int D_808009B0_chspotlight[20] = {0x2AF034D,
                                  0x7550001,
                                  0x0,
                                  (u32) func_80800210_chspotlight,
                                  (u32) func_80105834,
                                  (u32) func_80800518_chspotlight,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x21400,
                                  0x0,
                                  0x0,
                                  0x3C0000,
                                  (u32) func_8080000C_chspotlight,
                                  (u32) func_80107C2C,
                                  -0x7FFFFBFE,
                                  (u32) func_80800934_chspotlight,
                                  0x0,
                                  0x0,
                                  0x0};
