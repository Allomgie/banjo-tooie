// Glowbo collectible (normal and Mega): a wandering Glowbo following a route with a pulsing light.
// Other entrypoints are probably the Glowbo props shown when paying Mumbo or Humba, plus helpers.
#include "ch/glowbo.h"

#define GLOWBO_DATA(arg0) ((GlowboActorData *) (arg0->actorData))

extern u32 D_808013B0_chglowbo[];
extern u32 D_80801420_chglowbo[];
extern u32 D_80801430_chglowbo[];
extern u32 D_8080143C_chglowbo[];
extern u32 D_80801448_chglowbo[];
extern u32 D_80801454_chglowbo[];
extern s32 D_80801460_chglowbo[3];
extern f32 D_8080146C_chglowbo[18];
extern Vec3f D_808014B4_chglowbo;
extern u32 D_808014C0_chglowbo[];
extern u32 D_80801508_chglowbo[];
extern u32 D_80801540_chglowbo[];
extern u32 D_80801588_chglowbo[];
extern u32 D_808015D0_chglowbo[];
extern f32 D_80801618_chglowbo[];
extern u32 _chglowbo_entrypoint_5;

// Pulse the point light colour between 60% and 100%.
void func_80800000_chglowbo(Actor *actor)
{
    glowboStruct *glow = (glowboStruct *) func_80100094(actor, 0U);
    s32 color[3] = D_80801460_chglowbo;

    if (glow->unk16 == 1) {
        glow->unk8 = (f32) (glow->unk8 + 0.02f);
        if (glow->unk8 > 1.0f) {
            glow->unk8 = 1.0f;
            glow->unk16 = 0U;
        }
    } else {
        glow->unk8 = (f32) (glow->unk8 - 0.02f);
        if (glow->unk8 < 0.6f) {
            glow->unk8 = 0.6f;
            glow->unk16 = 1U;
        }
    }
    color[0] = (s32) color[0] * glow->unk8;
    color[1] = (s32) color[1] * glow->unk8;
    color[2] = (s32) color[2] * glow->unk8;
    func_800C8E84(glow->unk4, color);
}

void func_8080013C_chglowbo(Actor *actor)
{
    glowboStruct *glow;

    glow = (glowboStruct *) func_80100094(actor, 0U);
    if (actor->scale == 2.0f) {
        actor->unk74_29 = 1;
    } else {
        actor->unk74_29 = 0;
    }
    if (actor->unk74_29) {
        actor->unk74_17 = 1;
        actor->scale = 0.75f;
    } else {
        actor->scale = 0.4f;
    }
    if (actor->unk74_29 && (func_800DA298(FLAG_056_STATE_MEGA_GLOWBO) != 0)) {
        func_800FFAB0(actor);
        return;
    }

    if (_subaddieDll_entrypoint_1(actor) == 0) {
        actor->unk58 = 0.0f;
        func_80101FDC(actor, 0xA);
        func_800EE7F8(&GLOWBO_DATA(actor)->unk10, actor->position);
    } else if (actor->unk74_29) {
        actor->unk58 = D_8080146C_chglowbo[0];
    } else {
        actor->unk58 = D_8080146C_chglowbo[glow->unk0];
    }
    GLOWBO_DATA(actor)->unkC = 100.0f;

    switch (func_800EA05C()) {
        case MAP_1A7_JRL_JOLLY_ROGERS_LAGOON:
        case MAP_1A8_JRL_ATLANTIS:
        case MAP_1A9_JRL_SEA_BOTTOM:

            actor->unk64_19 = 1;
            glow->unk17 = _subaddiesect_entrypoint_1(actor);
    }
    _subaddierouteDll_entrypoint_3(actor, func_80100094(actor, 1U), actor->position);
}

void func_808002F4_chglowbo(Actor *actor)
{
    glowboStruct *glow;
    glowboStruct2 *route;
    f32 gamespeed;
    f32 twinkle_pos[3];
    f32 light_pos[3];
    f32 light_pos2[3];
    glow = (glowboStruct *) func_80100094(actor, 0U);
    route = (glowboStruct2 *) func_80100094(actor, 1U);
    if (!actor->unk64_19 || (_subaddiesect_entrypoint_0(actor, glow->unk17, 0xB) != 0)) {
        gamespeed = func_800D8FF8();
        if (actor->unk7C_12 && (func_800DC298(0.05f) != 0)) {
            func_800EFA4C(twinkle_pos, actor->position[0] + func_800DC178(-30.0f, 30.0f),
                          actor->position[1] + func_800DC178(25.0f, 55.0f),
                          actor->position[2] + func_800DC178(-30.0f, 30.0f));
            _fxtwinkle_entrypoint_1(twinkle_pos, RED_SPARKLE);
        }
        func_8010D254(GLOWBO_DATA(actor)->unk0);
        if (actor->unk70_10 != 1) {
            switch (actor->unk70_10) {
                case 2:
                    if (_subaddierouteDll_entrypoint_4(actor) != 0) {
                        if ((func_80090128() != 0) &&
                            ((func_8010C500(actor) != 0) || (func_8010C710(actor) < 0x9C400))) {
                            actor->unk54 = func_8010CD50(actor, func_800F54E4()) - 180.0f;
                        } else {
                            _subaddierouteDll_entrypoint_6(actor, route, glow->unk14, 0x3F, 0.4f,
                                                           0x14, 0x28);
                        }
                        _subaddierouteDll_entrypoint_7(actor, route, actor->rotation[1], actor->unk54,
                                                       75.0f, 0x4803);
                        glow->unk14 = (u16) route->unk6;
                    }
                    _subaddierouteDll_entrypoint_5(actor, route, glow->unk14, 0.15f, 8.0f, 200.0f);
                    if (func_8010CB84(actor->position, 0x320) != 0) {
                        glow->unk10 = (f32) actor->unk58;
                    } else {
                        glow->unk10 = 100.0f;
                    }
                    GLOWBO_DATA(actor)->unkC =
                        func_800F15F8(GLOWBO_DATA(actor)->unkC, glow->unk10, gamespeed * 250.0f);
                    func_801026CC(actor, D_808014B4_chglowbo, GLOWBO_DATA(actor)->unkC);
                    func_8010C3A8(actor, 0x305425,
                                  func_800F3780(func_80101F24(actor), D_808013B0_chglowbo, 3));
                    if (glow->unk4 != 0) {
                        func_800EE7F8(light_pos, actor->position);
                        light_pos[1] += 150.0f;
                        func_800C8CB8(glow->unk4, light_pos);
                        func_80800000_chglowbo(actor);
                    }
                    if (((glow->unkC <= 0.0f) && (func_800DC298(0.1f) != 0)) &&
                        (func_8010CAC0(actor->position, 0x5DCU) != 0)) {
                        glow->unkC = 4.0f;
                        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801420_chglowbo);
                    } else {
                        glow->unkC = (f32) (glow->unkC - func_800D8FF8());
                    }
                    _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801430_chglowbo,
                                                     0.3f);
                    _subaddieaudioquick_entrypoint_3(actor, actor->position, D_8080143C_chglowbo,
                                                     0.8f);
                    break;

                case 0xa:
                    func_800EE7F8(actor->position, &GLOWBO_DATA(actor)->unk10);
                    func_800EF1B8(actor->position, actor->rotation[1] - 90.0f, actor->unk74_7);
                    actor->rotation[1] += (func_800D8FF8() * 100.0f) *
                                         func_800F3780(func_80101F24(actor), D_808013B0_chglowbo, 3);
                    if (glow->unk4 != 0) {
                        light_pos2[0] = actor->position[0];
                        light_pos2[1] = actor->position[1] + 150.0f;
                        light_pos2[2] = actor->position[2];
                        func_800C8CB8(glow->unk4, light_pos2);
                        func_80800000_chglowbo(actor);
                    }
                    if (func_80101E14(actor, 0.3f) != 0) {
                        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801430_chglowbo);
                    }
                    if (func_80101E14(actor, 0.8f) != 0) {
                        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_8080143C_chglowbo);
                    }
            }

        } else {
            if (glow->unk4 != 0) {
                func_800C8B84(glow->unk4);
            }
            func_800FFAB0(actor);
        }
    }
}

s32 func_80800880_chglowbo(Actor *actor, s32 msg, s32 data)
{
    glowboStruct *glow;

    glow = (glowboStruct *) func_80100094(actor, 0U);
    switch (msg) {
        case 0x95:
            _subaddierouteDll_entrypoint_1(actor);
            func_8010A5B0(actor, func_800DA298(FLAG2_64E_UNK));
            break;
        case 0x3E: // collected
            _fxsparkle_entrypoint_1(actor->position, 6U);
            if (actor->unk74_29) {
                // Mega Glowbo: dialog, set state flag, item 0x54
                _subaddiedialog_entrypoint_11(actor->unk0, 0xD03U, 0U, actor->position, 0U);
                func_800DA544(FLAG_056_STATE_MEGA_GLOWBO);
                func_800D1844(0x54U);
            } else {
                // normal Glowbo: mark collected, item 0x48
                _sudialog_entrypoint_0(0x2A, 0);
                func_800D0BD4(glow->unk0, 3U);
                func_800D1844(0x48U);
            }
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801454_chglowbo);
            func_80101FDC(actor, 1U);
            if (glow->unk4) {
                func_800C8E54(glow->unk4, 0.0f, 0.0f);
                func_800C8FB0(glow->unk4, 0U, 0U, 0U);
            }
            break;
        case 0x13:
            glow->unk0 = data;
            break;
        // attach light
        case 0x55:
            glow->unk4 = func_800C8A98();
            func_800C8E54(glow->unk4, 100.0f, 750.0f);
            glow->unk16 = 1;
            glow->unk8 = 0.5f;
            break;
        default:
            return 0;
    }
    return 1;
}

u32 *chglowbo_entrypoint_0(void)
{
    return D_808014C0_chglowbo;
}

void func_80800A48_chglowbo(Actor *actor)
{
    glowboStruct *glow;
    s32 light;

    glow = (glowboStruct *) func_80100094(actor, 0U);
    if (func_800EA05C() == MAP_157_IOH_WUMBA) {
        actor->unk74_29 = 1;
    } else {
        actor->unk74_29 = 0;
    }
    if (actor->unk74_29) {
        actor->scale = 0.75f;
    } else {
        actor->scale = 0.25f;
    }
    GLOWBO_DATA(actor)->unkC = 100.0f;
    light = func_800C8A98();
    glow->unk4 = light;
    func_800C8E54(light, 100.0f, 750.0f);
    glow->unk8 = 0.5f;
    glow->unk16 = 1;
}

void func_80800B10_chglowbo(Actor *actor)
{
    glowboStruct *glow = (glowboStruct *) func_80100094(actor, 0U);
    func_800BBCB8(actor->position, 0, 1.0f, 1, D_80801508_chglowbo);
    switch (actor->unk70_10) {
        case 4:
            if (actor->unk74_30) {
                func_80101FDC(actor, 3U);
            }
            return;
        case 3:
            actor->unk54 = func_800F1DF4(actor->position, GLOWBO_DATA(actor)->unk0);
            GLOWBO_DATA(actor)->unk14 =
                func_800EFB8C(actor->position, GLOWBO_DATA(actor)->unk0) / 25.0f;
            GLOWBO_DATA(actor)->unk1C = -80.0f;
            func_80801258_chglowbo(actor);
            GLOWBO_DATA(actor)->unk14 = 50.0f;
            actor->unk6C_0 = 0;
            func_800C9C70(0.25f, 0x4DEU, 1.0f, 0x4650U, actor->position, 500.0f, 2500.0f);
            func_80101FDC(actor, 5U);
            return;
        case 5:
            func_80801258_chglowbo(actor);
            if ((GLOWBO_DATA(actor)->unk0[1] < actor->position[1]) ||
                (GLOWBO_DATA(actor)->unk14 > 0.0f)) {
                GLOWBO_DATA(actor)->unk14 += GLOWBO_DATA(actor)->unk1C * func_800D8FF8();
                func_800EFCD8(&GLOWBO_DATA(actor)->unk10, actor->unk54, GLOWBO_DATA(actor)->unkC);
                func_800EF04C(actor->position, &GLOWBO_DATA(actor)->unk10);
                actor->unk6C_0 += 1;
            } else if (actor->unk64_19) {
                func_80101FDC(actor, 1U);
            } else {
                GLOWBO_DATA(actor)->unk0[1] -= 75.0f;
                func_80101FDC(actor, 6U);
            }
            actor->rotation[0] += 18.0f;
            func_80800000_chglowbo(actor);
            return;
        case 6:
            func_800C8FB0(glow->unk4, 0, 0, 0);
            if ((s32) actor->alpha >= 0xF) {
                actor->alpha -= 0xF;
            }
            if (GLOWBO_DATA(actor)->unk0[1] < actor->position[1]) {
                actor->position[1] += -6.0f;
                return;
            }
            if (GLOWBO_DATA(actor)->unk0[1] < actor->position[1]) {
                actor->position[1] += -6.0f;
                return;
            }
            func_80101FDC(actor, 7U);
            return;
        case 7:
            func_80101FDC(actor, 1U);
            return;
        case 1:
            func_800C8B84(glow->unk4);
            func_800FFAB0(actor);
    }
}

u32 *chglowbo_entrypoint_1(void)
{
    return D_80801540_chglowbo;
}

u32 *chglowbo_entrypoint_2(void)
{
    return D_80801588_chglowbo;
}

void func_80800E28_chglowbo(Actor *actor)
{
    f32 player_pos[3];

    if (func_800EA05C() == MAP_157_IOH_WUMBA) {
        actor->unk74_29 = 1;
    } else {
        actor->unk74_29 = 0;
    }
    if (actor->unk74_29) {
        actor->scale = 0.75f;
    } else {
        actor->scale = 0.25f;
    }
    actor->rotation[1] = (func_80090010() + func_800DC178(-110.0f, 110.0f));
    func_8010D254(player_pos);
    func_800EEB9C(GLOWBO_DATA(actor)->unk0, actor->rotation[1], 400.0f);
    func_800EF04C(GLOWBO_DATA(actor)->unk0, actor->position);
    GLOWBO_DATA(actor)->unk0[1] = (f32) (player_pos[1] + 20.0f);
    GLOWBO_DATA(actor)->unk1C = -80.0f;
    GLOWBO_DATA(actor)->unk14 = 30.0f;
    func_800C9C70(0.25f, 0x4DE, 0.5f, 0x4650, actor->position, 500.0f, 2500.0f);
}

void func_80800F64_chglowbo(Actor *actor)
{
    switch (actor->unk70_10) {
        case 8:
            func_80801258_chglowbo(actor);
            actor->rotation[0] = (f32) (actor->rotation[0] + 18.0f);
            if ((GLOWBO_DATA(actor)->unk0[1] < actor->position[1]) ||
                (GLOWBO_DATA(actor)->unk14 > 0.0f)) {
                GLOWBO_DATA(actor)->unk14 += (GLOWBO_DATA(actor)->unk1C * func_800D8FF8());
                func_800EF1B8(actor->position, actor->rotation[1], GLOWBO_DATA(actor)->unkC);
                actor->position[1] = (f32) (actor->position[1] + GLOWBO_DATA(actor)->unk14);
            }
            if ((actor->position[1] <= GLOWBO_DATA(actor)->unk0[1]) &&
                (GLOWBO_DATA(actor)->unk14 <= 0.0f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801448_chglowbo);
                actor->position[1] = (f32) GLOWBO_DATA(actor)->unk0[1];
                GLOWBO_DATA(actor)->unk14 = 0.0f;
                GLOWBO_DATA(actor)->unkC = 100.0f;
                actor->rotation[0] = func_800136E4(actor->rotation[0]);
                actor->unk58 = 6.0f;
                func_80101FDC(actor, 9);
            }
            return;
        case 9:
            actor->rotation[0] += ((360.0f - actor->rotation[0]) * 0.1f);
            if (func_8010B990(actor, 0x501105) & 0x24) {
                _subaddiefade_entrypoint_3(actor);
            }
            if (func_8010CAC0(actor->position, 0x12CU) == 0) {
                _subaddiefade_entrypoint_3(actor);
            }
    }
}

void func_80801118_chglowbo(Actor *actor, s32 param)
{
    func_800DF5D8(0x80, 0x80, 0x80, _subaddiefade_entrypoint_0(actor));
    func_80101870(actor, param);
}

s32 func_8080115C_chglowbo(Actor *actor, s32 msg, u32 data)
{
    if (msg == 0x4D) {
        func_800FFA88(actor->unk0);
        return 1;
    }
    return 0;
}

u32 *chglowbo_entrypoint_3(void)
{
    return D_808015D0_chglowbo;
}

void chglowbo_entrypoint_4(void)
{
    func_80108474(0x2A0, D_80801618_chglowbo, func_800DC178(0.0f, 359.0f));
}

void chglowbo_entrypoint_5(void)
{
    f32 player_pos[3];
    func_8008FE94(1, player_pos);
    func_80108474(0x2A0U, player_pos, (s32) func_800DC178(0.0f, 359.0f));
}

void chglowbo_entrypoint_6(void)
{
    _chbaddiesetup_entrypoint_0(&_chglowbo_entrypoint_5);
}

void func_80801258_chglowbo(Actor *actor)
{
    f32 pos[3];
    f32 vel_y = GLOWBO_DATA(actor)->unk14;
    s32 steps = 0;

    func_800EE7F8(pos, actor->position);

    while ((GLOWBO_DATA(actor)->unk0[1] < pos[1]) || (vel_y > 0.0f)) {
        vel_y += GLOWBO_DATA(actor)->unk1C * func_800D8FF8();
        steps++;
        pos[1] = pos[1] + vel_y;
    }

    GLOWBO_DATA(actor)->unkC = func_800EFB8C(actor->position, GLOWBO_DATA(actor)->unk0);
    if (steps > 0) {
        GLOWBO_DATA(actor)->unkC = (f32) (GLOWBO_DATA(actor)->unkC / (f32) steps);
        return;
    }
    GLOWBO_DATA(actor)->unkC = 0.0f;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_808013B0_chglowbo[6] = {0x0, 0x0, 0x3F000000, 0x3F800000, 0x3F800000, 0x0};
u32 D_808013C8_chglowbo[22] = {0x0,        0x0,       0x3F333333, 0x2120000, 0x3F333333, 0x2120000,
                               0x3F333333, 0x2120000, 0x3F333333, 0x2120000, 0x3F333333, 0x2120000,
                               0x3F333333, 0x2120000, 0x3F333333, 0x2120000, 0x3F333333, 0x2120000,
                               0x3F666666, 0x2130000, 0x3F333333, 0x2120000};
u32 D_80801420_chglowbo[4] = {0x130661, 0x1655F0, 0x105DC, 0x9C40000};
u32 D_80801430_chglowbo[3] = {0x1304D5, 0x161770, 0x0};
u32 D_8080143C_chglowbo[3] = {0x130402, 0x162EE0, 0x0};
u32 D_80801448_chglowbo[3] = {0x130402, 0x166590, 0x0};
u32 D_80801454_chglowbo[3] = {0x1304DD, 0x1661A8, 0x0};
s32 D_80801460_chglowbo[3] = {0xFF, 0x60, 0x60};
f32 D_8080146C_chglowbo[18] = {4e+02f,   2e+02f,   2e+02f,   2.3e+02f, 2.3e+02f, 2.6e+02f,
                               2.6e+02f, 2.9e+02f, 2.9e+02f, 3.2e+02f, 3.2e+02f, 3.5e+02f,
                               3.5e+02f, 3.8e+02f, 3.8e+02f, 4.1e+02f, 4.1e+02f, 3e+02f};
Vec3f D_808014B4_chglowbo = {1.0f, -0.002f, 0.35f};
u32 D_808014C0_chglowbo[18] = {0x39021B,
                               0x7660002,
                               (u32) &D_808013C8_chglowbo,
                               (u32) func_808002F4_chglowbo,
                               (u32) func_80105834,
                               (u32) func_80101870,
                               0x13880000,
                               0x3FC00000,
                               0x0,
                               0x40144,
                               0x0,
                               (u32) func_80108ED0,
                               0x18000C,
                               (u32) func_8080013C_chglowbo,
                               (u32) func_80107C2C,
                               0x0,
                               (u32) func_80800880_chglowbo,
                               0x0};
u32 D_80801508_chglowbo[14] = {0x1D09E4, 0x220026, 0x330019, 0x140027, 0xC8,
                               0xF0,     0x161000, 0x150033, 0x99002B, 0x330066,
                               0x2CFFCE, 0x28FFCE, 0x320050, 0x320000};
u32 D_80801540_chglowbo[18] = {0x1FF029F,
                               0x7660004,
                               (u32) &D_808013C8_chglowbo,
                               (u32) func_80800B10_chglowbo,
                               (u32) func_80105834,
                               (u32) func_80101870,
                               0x0,
                               0x3FC00000,
                               0x0,
                               0x144,
                               0x0,
                               0x0,
                               0x180000,
                               (u32) func_80800A48_chglowbo,
                               (u32) func_80107C2C,
                               0x80000002,
                               0x0,
                               0x0};
u32 D_80801588_chglowbo[18] = {0x1FF0523,
                               0x7660004,
                               (u32) &D_808013C8_chglowbo,
                               (u32) func_80800B10_chglowbo,
                               (u32) func_80105834,
                               (u32) func_80101870,
                               0x0,
                               0x3FC00000,
                               0x0,
                               0x144,
                               0x0,
                               0x0,
                               0x180000,
                               (u32) func_80800A48_chglowbo,
                               (u32) func_80107C2C,
                               0x80000002,
                               0x0,
                               0x0};
u32 D_808015D0_chglowbo[18] = {0x20002A0,
                               0x7660008,
                               (u32) &D_808013C8_chglowbo,
                               (u32) func_80800F64_chglowbo,
                               (u32) func_80105834,
                               (u32) func_80801118_chglowbo,
                               0x0,
                               0x3FC00000,
                               0x0,
                               0x40104,
                               0x0,
                               0x0,
                               0x0,
                               (u32) func_80800E28_chglowbo,
                               (u32) func_80107C2C,
                               0x80000002,
                               (u32) func_8080115C_chglowbo,
                               0x0};
f32 D_80801618_chglowbo[6] = {0.0f, -26.0f, 0.0f, 0.0f, 0.0f, 0.0f};
