// Jinjo collectible (45 Jinjos in 9 colour families): idles and waves, dances when collected
// and triggers the family cutscene once its family is complete. Also has map/colour lookups.
#include "common.h"

extern void func_800FFAB0(Actor *);
extern int func_800D0CC8(int);
extern s16 D_80801368_chjinjo[];
extern void func_800FC74C(s32);
extern void _suexpression_entrypoint_8();
// Maps a map id to its Jinjo family colour.
typedef struct {
    s16 map_id;
    s16 family;
} JinjoLookup;
extern s16 D_80801300_chjinjo[];
extern s16 D_80801302_chjinjo;
extern JinjoLookup D_80801304_chjinjo[8];
extern void _subaddieaudioquick_entrypoint_3(void *, void *, void *, f32);
extern s32 D_80801358_chjinjo[];
extern void _subaddieaudioquick_entrypoint_2(void *param_0, void *param_1, void *param_2);
extern int func_80101E14(void *param_0, float param_1);
extern float D_8080133C_chjinjo[];
extern float D_80801348_chjinjo[];
extern s32 D_80801330_chjinjo[];
extern u16 D_80801390_chjinjo[];
extern s32 func_800C05B8();
extern int D_808013A4_chjinjo[];
extern int D_808013EC_chjinjo[];
extern f32 func_800D8FF8(void);
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void *func_80100094(Actor *, u32);
extern f32 func_800F1DCC(f32, f32);
extern s32 func_800901CC(f32 *, f32);
extern f32 func_80101F24(Actor *);
extern void func_80102424(Actor *, s32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_800C4244(s32, f32, s32, f32 *, f32, f32);
typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 28;
    u32 active : 1;
    u32 pad_2 : 3;
    u32 pad_3 : 11;
    u32 visible : 1;
    u32 pad_4 : 20;
} JinjoActorFlags;
extern u8 D_80801324_chjinjo[];
extern void func_80108A30(s32, f32 *, f32, s32);
extern void _chjinjo_entrypoint_4(void);
typedef union {
    u32 value;
    Unk80132ED0 *ptr;
} JinjoEventWord;
s16 chjinjo_entrypoint_0();
s16 chjinjo_entrypoint_2();
int func_8080102C_chjinjo();

void func_80800000_chjinjo(Actor *actor)
{
    s32 config;
    s32 family;
    *(u8 *) ((u8 *) actor + 0x79) = (u8) ((*(u8 *) ((u8 *) actor + 0x79) & 0xFF0F) | 0x10);
    if (func_800DA298(0x653) != 0)
        func_800FFAB0(actor);
    config = *(s32 *) ((u8 *) actor + 0x6C);
    // 0x48F: variant placed in the Jinjo houses.
    if (((u32) (config << 11) >> 20) == 0x48F) {
        family = chjinjo_entrypoint_2(-1);
    } else {
        family = func_800D0CC8(config & 0x1FF);
    }
    if ((((u32) (*(s32 *) ((u8 *) actor + 0x6C) << 11) >> 20) == 0x48F) &&
        ((f32) func_800D1338(family) <= *(f32 *) ((u8 *) actor + 0x48))) {
        func_800FFAB0(actor);
    }
    if (actor->unk64_20)
        func_800FC660(0x10);
}

int func_808000DC_chjinjo(int actor)
{
    s32 family;
    int family_copy;
    family = *(int *) (actor + 0x6C) & 0x1FF;
    family = func_800D0CC8(family);
    // Matching: needed for the match.
    family_copy = family | family;
    return chjinjo_entrypoint_0(family_copy);
}

s16 chjinjo_entrypoint_0(family)
s32 family;
{
    return D_80801368_chjinjo[family];

}

void func_80800120_chjinjo(u8 *actor)
{
    if (*(s32 *) (actor + 0x2C)) {
        func_800FC74C(0x1C);
        *(s32 *) (actor + 0x2C) = 0;
    }

func_8080102C_chjinjo(actor, 1);
_suexpression_entrypoint_8(actor, 1);
}

s32 chjinjo_entrypoint_1(s32 family, s32 value)
{
    // Matching: needed for the match.
    func_800D0C78(family + 0x51, 1, value | 0);
}

// Map id -> family colour (-1 = current map).
s16 chjinjo_entrypoint_2(map_id)
s32 map_id;
{
    s32 i;

if (map_id == -1) {
    map_id = func_800EA05C();
}

if (map_id == D_80801300_chjinjo[0]) {
    return D_80801302_chjinjo;
}

for (i = 0; i < 8; i++) {

if (map_id == D_80801304_chjinjo[i].map_id) {
    return D_80801304_chjinjo[i].family;
}

}
return -1;
}

// Family colour -> map id.
s32 chjinjo_entrypoint_3(s32 family)
{
    s32 i;
    if (family == D_80801302_chjinjo)
        return D_80801300_chjinjo[0];
    for (i = 0; i < 8; i++) {
        if (family == D_80801304_chjinjo[i].family)
            return D_80801304_chjinjo[i].map_id;
    }
    return -1;
}

void func_80800F80_chjinjo();

// Update: idle, wave and turn-to-player animations, collected dance in states 7 and 8.
void func_808002E0_chjinjo(Actor *actor)
{
    extern u8 D_8080137C_chjinjo[];
    f32 player_pos[3];
    f32 to_player[3];
    f32 dt;
    s32 i;
    f32 target_yaw;
    s32 is_state_7;
    f32 yaw_diff;
    f32 twinkle_pos[3];
    s32 fade;
    s32 family;

    dt = func_800D8FF8();
    if (!((JinjoActorFlags *) actor)->active) {
        return;
    }
    _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
    if (actor->unk74_29) {
        func_800E3980(player_pos);
    } else {
        func_8010D254(player_pos);
    }
    if (actor->unk6C_9 == 0x48F) {
        func_8010C908(actor, actor->position);

}
func_800F1E6C(actor->position, player_pos, &target_yaw);
yaw_diff = func_800F1DCC(actor->rotation[1], target_yaw);

switch (actor->unk70_10) {
    case 1:
        if (func_800DC0C0() < 0.015f) {
            if (func_800901CC(actor->position, 55.0f)) {
                func_80102424(actor, 3);
            } else {
                func_80102424(actor, 2);
            }
        }

break;
case 2:
    func_80800F14_chjinjo(actor);

if (func_80101E14(actor, 0.999f)) {
    func_80102424(actor, 1);
}

break;
case 3:
    func_80800F80_chjinjo(actor);

if (func_80101E14(actor, 0.999f)) {
    func_80102424(actor, 1);
}

break;
case 4:
    func_80800EE4_chjinjo(actor);

if (func_80101E14(actor, 0.999f)) {
    func_80102424(actor, 1);
} else {

if (yaw_diff >= 0.0f) {
    actor->rotation[1] -= 80.0f * dt;
} else {

actor->rotation[1] += 80.0f * dt;
}
}
break;
case 6:
    func_80800EE4_chjinjo(actor);
    if (yaw_diff >= 0.0f) {
        actor->rotation[1] -= 120.0f * dt;
    } else {
        actor->rotation[1] += 120.0f * dt;
    }
    if (func_80101E14(actor, 0.0f)) {
        actor->unk79_4--;
        if (actor->unk79_4 == 0) {
            func_80102424(actor, 7);
            func_80102FE8(actor, 0);
            func_800FC63C(2, 0x6D60);
        }
    }
    break;
case 7:
case 8:
    _suexpression_entrypoint_12(func_80100094(actor, 1), 0, 0);
    is_state_7 = actor->unk70_10 == 7;
    if (!is_state_7 || func_80101F24(actor) > 0.1f) {
        func_8008FFBC(to_player);
        func_800EF334(to_player, dt * 6.0f);
        func_800EF04C(to_player, player_pos);
        func_800EF3DC(to_player, actor->position);
        func_800EF334(to_player, dt * 3.0f);
        func_800EF04C(actor->position, to_player);
        if (is_state_7 || func_80101F24(actor) < 0.8f) {
            for (i = 0; i < 4; i++) {

if (func_800DC0C0() < 0.3f) {
    _subaddieskeleton_entrypoint_0(actor, 3, twinkle_pos);
    func_800EF214(twinkle_pos, func_800DC178(0.0f, 360.0f), func_800DC178(0.0f, 360.0f), 15.0f);
    _fxtwinkle_entrypoint_0(twinkle_pos);
}

}
}
}
if (is_state_7) {
    if (func_80101F24(actor) < 0.2f) {
        if (yaw_diff >= 0.0f) {
            actor->rotation[1] -= 120.0f * dt;
        } else {
            actor->rotation[1] += 120.0f * dt;
        }
    }
    if (func_80101E14(actor, 0.1f)) {
        _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_8080137C_chjinjo);
        actor->actorData[5] = 1;
        func_800FC63C(0x1C, 0x7FFF);
        func_800FCA90(0x1C);
        func_800C4244(0x4A2, 0.8f, 0x7FFF, actor->position, 300.0f, 2000.0f);
    } else if (func_80101E14(actor, 0.434f) || func_80101E14(actor, 0.811f)) {
        func_800C4244(0x4A2, 0.9f, 0x7FFF, actor->position, 300.0f, 2000.0f);
    }
} else {
    if (func_80101E14(actor, 0.214f)) {
        func_800C4244(0x4A2, 1.1f, 0x7FFF, actor->position, 300.0f, 2000.0f);
    } else if (func_80101E14(actor, 0.55f)) {
        func_800C4244(0x43A, 1.5f, 0x7FFF, actor->position, 300.0f, 2000.0f);
    } else if (func_80101E14(actor, 0.75f)) {
        if (func_800FCCD4(2)) {
            func_800FCAE0(2, 0, 4000);
            func_800FCA90(2);
        }
    } else if (func_80101E14(actor, 0.85f)) {
        _subaddieaudioloop_entrypoint_2(actor);
        func_800C3EB8(0x411);
        func_800FC74C(0x1C);
        actor->actorData[5] = 0;
    }
    if (func_80101F24(actor) > 0.75f) {
        fade = _subaddiefade_entrypoint_0(actor);
        if (fade >= 7) {
            fade -= 7;

}
if (func_80101F24(actor) > 0.9f) {
    if (fade >= 21) {
        fade -= 21;
    } else {

fade = 0;
}
}
_subaddiefade_entrypoint_1(actor, fade);
}
if (func_80101E14(actor, 0.999f)) {
    func_80102424(actor, 9);
    ((JinjoActorFlags *) actor)->visible = 0;
    actor->unk64_16 = ((JinjoActorFlags *) actor)->visible;
}
}
if (is_state_7) {
    if (func_80101E14(actor, 0.96f) || func_80101E14(actor, 0.999f)) {
        func_80102424(actor, 8);
    }
}
break;
case 9:
    if (actor->unk74_30) {
        family = func_800D0CC8(actor->unk6C_0);
        // Family complete: play the Jinjo Village cutscene.
        if (actor->unk64_19) {
            func_800F82D4(actor->actorData[4], 0);
            func_800DA7A8(0x6D0, family, 4);
            _glcutDll_entrypoint_6(0x142, 0x84);
        } else {
            func_8080102C_chjinjo(actor, 0);
        }
        actor->unk74_30 = 0;
        actor->unk64_19 = 0;
    }
    func_800FFAB0(actor);
    }
    if ((s32) actor->unk70_10 < 4 && (yaw_diff > 45.0f || yaw_diff < -45.0f)) {
        func_80102424(actor, 4);
    }
    }

    s32 chjinjo_entrypoint_4(s32 param_0, s32 param_1, s32 param_2)
    {
        _glcutDll_entrypoint_6(0x142, 0x84);
    }

    s32 func_80800C10_chjinjo(Actor *actor, s32 event, JinjoEventWord arg)
    {
        Unk80132ED0 *hit;
        s32 family;
        u32 config;
        s32 text_family;
        s32 family_size;

        switch (event) {
            case 0x29:
                _suexpression_entrypoint_7(actor, 1, (s16) func_808000DC_chjinjo(actor));
                _suexpression_entrypoint_12(_suexpression_entrypoint_20(actor), 65.0f, 30.0f);
                break;
            case 0x2A:
                _suexpression_entrypoint_8(actor, 1);
                break;
            case 0x3E:
                if ((s32) actor->unk70_10 < 5) {
                    hit = (*(JinjoEventWord *) &arg).ptr;
                    if (func_8010A6B0(actor, (u32) *(u16 *) ((u8 *) hit + 0x1A) >> 5)) {
                        family = func_800D0CC8(actor->unk6C_0);
                        _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                         D_80801324_chjinjo);
                        func_80102424(actor, 6);
                        _subaddieDll_entrypoint_4(actor, 1);
                        func_8010A570(actor);
                        if (!func_800DA9E4(0x35, 1)) {
                            func_800C05B8(0xCDA, 0xC, 0, 0, _chjinjo_entrypoint_4, 0,
                                          func_808000DC_chjinjo(actor));
                        }
                        func_800D0BD4(actor->unk6C_0, 0);
                        family_size = func_800D1338(family);
                        func_800D24E8(family + 0xE1, family_size, func_800D129C(family));
                        func_80801098_chjinjo(actor,
                                              (u32) *(u16 *) ((u8 *) hit + 0x1A) >> 5);
                    }
                }
                break;
            case 0x13:
                actor->unk6C_0 = arg.value;
                if (actor->unk6C_0 == 0x1E) {
                    actor->unk74_29 = 1;
                }
                break;
            case 0x7E:
                if (actor->rotation[1] == 0.0f) {
                    func_80108A30(0x4D6, actor->position, 0, 0x32);
                }
                break;
            case 0x14:
                actor->unk64_20 = 1;
                break;
            case 0x95:
                config = *(u32 *) ((u8 *) actor + 0x6C);
                if ((config << 11 >> 20) == 0x48F) {
                    text_family = chjinjo_entrypoint_2(-1);
                } else {
                    text_family = func_800D0CC8(config & 0x1FF);
                }
                func_80103140(actor, 0x643, (u16) (text_family + 0xC31));
                break;
            default:
                return 0;
        }
        return 1;
    }

    int func_80800EE4_chjinjo(s32 actor)
    {
        s32 position;
        position = actor + 4;
        _subaddieaudioquick_entrypoint_3(actor, position, &D_80801358_chjinjo, 0.6f);
    }

    int func_80800F14_chjinjo(Actor *actor)
    {
        if (func_80101E14(actor, 0.2f)) {
            if ((((*((u32 *) ((u8 *) actor + 0x6C))) << 11) >> 20) == 0x48F) {
                _subaddieaudioquick_entrypoint_2(actor, &actor->position, &D_80801348_chjinjo);
            } else {
                _subaddieaudioquick_entrypoint_2(actor, &actor->position, &D_8080133C_chjinjo);
            }
        }
    }

    void func_80800F80_chjinjo(Actor *actor)
    {
        if (actor->unk6C_9 != 0x48F) {
            _subaddieaudioquick_entrypoint_3(actor, (u8 *) actor + 4, &D_80801330_chjinjo,
                                             0.2f);
        }
    }

    void func_80800FC4_chjinjo(Actor *actor)
    {
        s32 family;

        family = func_800D0CC8(actor->unk6C_0);
        func_800C05B8(D_80801390_chjinjo[family], 0x44, NULL, NULL, 0, 0,
                      func_808000DC_chjinjo(actor));
    }

    int func_8080102C_chjinjo(actor, value)
    Actor *actor;
    s32 value;
    {
        if (actor->unk74_30) {
            chjinjo_entrypoint_1(func_800D0CC8(*(u32 *) ((u8 *) actor + 0x6C) & 0x1FF), value);
            actor->unk74_30 = 0;
            return 1;
        }
        return 0;
    }

    // After a collect: flags a pending event when the whole family is collected.
int func_80801098_chjinjo(Actor *actor, u32 unk_1)
    {
        s32 all_collected;
        s32 unk_0;
        s32 family;

        family = func_800D0CC8(actor->unk6C_0);
        actor->unk64_19 = 0;
        actor->unk74_30 = 0;
        actor->actorData[4] = unk_1;

        all_collected = func_800D1338(family) == func_800D129C(family);
        if (func_800D035C(0) == 1) {
            func_800DA7A8(0x6D0, func_800D0CC8(actor->unk6C_0), 4);
        } else if (all_collected) {
            actor->unk74_30 = 1;
            if (!func_800DA298(0x43D)) {
                actor->unk64_19 = 1;
                func_800F82D4(actor->actorData[4], 2);
            } else
                func_80800FC4_chjinjo(actor);
        }
        return actor->unk74_30;
    }

    int *chjinjo_entrypoint_5()
    {
        return &D_808013A4_chjinjo;
    }

    int chjinjo_entrypoint_6(void)
    {
        return (int) &D_808013EC_chjinjo;
    }

// TU-NOTE: the overlay .data is defined here in C. Its tables point to functions of this file,
// and IDO's assembler schedules some of them differently unless they are in the same unit.
// TU-NOTE: D_80801302_chjinjo = D_80801300_chjinjo + 0x2 (linker symbol in undefined_syms.us.txt).
// TU-NOTE: externs are typed to the objects: D_80801300 s16[] (used as NAME[0]), D_80801330 and
// D_80801358 s32[], D_8080133C and D_80801348 float[], D_808013A4 and D_808013EC int[].
extern void func_80105834();
    extern void func_80101870();
    extern void func_80108ED0();
    extern void func_80107C2C();
    u32 D_808012B0_chjinjo[20] = {0x0,        0x0,        0x3FC00000, 0x2D0044,   0x3FC00000,
                                  0x2D0042,   0x3FC00000, 0x2F0042,   0x3F400000, 0x310042,
                                  0x3FC00000, 0x2D0044,   0x3ECCCCCD, 0x310041,   0x3FE00000,
                                  0x1F0042,   0x4008887B, 0x240042,   0x0,        0x0};
    s16 D_80801300_chjinjo[2] = {0x145, 0x4};
    JinjoLookup D_80801304_chjinjo[8] = {0x146, 0x8, 0x147, 0x2, 0x148, 0x6, 0x14A, 0x3,
                                         0x14B, 0x1, 0x14C, 0x7, 0x14D, 0x5, 0x14E, 0x0};
    u8 D_80801324_chjinjo[12] = {0x0, 0x13, 0x3, 0xEE, 0x0, 0x16, 0x65, 0x90, 0x0, 0x0, 0x0, 0x0};
    s32 D_80801330_chjinjo[3] = {0x13041A, 0x1655F0, 0x0};
    float D_8080133C_chjinjo[3] = {1.74633e-39f, 2.05121e-39f, 0.0f};
    float D_80801348_chjinjo[4] = {1.74639e-39f, 9.18893e-40f, 2.066297e-39f, 0.0f};
    s32 D_80801358_chjinjo[4] = {0x130404, 0xA01CC, 0x164650, 0x0};
    s16 D_80801368_chjinjo[10] = {0x72, 0x15, 0x11, 0x74, 0x12, 0x70, 0x13, 0x14, 0x73, 0x0};
    u8 D_8080137C_chjinjo[20] = {0x3, 0x6,  0x0, 0x1B, 0x0, 0x13, 0x4,  0x10, 0x0, 0x1,
                                 0x1, 0xF4, 0x7, 0xD0, 0x0, 0x16, 0x27, 0x10, 0x0, 0x0};
    u16 D_80801390_chjinjo[10] = {0x1525, 0x1526, 0x1527, 0x1528, 0x1529,
                                  0x152A, 0x152B, 0x152C, 0x152D, 0x0};
    int D_808013A4_chjinjo[18] = {0x5A01F4,
                                  0x6430002,
                                  (u32) &D_808012B0_chjinjo,
                                  (u32) func_808002E0_chjinjo,
                                  (u32) func_80105834,
                                  (u32) func_80101870,
                                  0x9C40000,
                                  0x3F4CCCCD,
                                  0x0,
                                  0x800124,
                                  (u32) func_80800120_chjinjo,
                                  (u32) func_80108ED0,
                                  0x0,
                                  (u32) func_80800000_chjinjo,
                                  (u32) func_80107C2C,
                                  -0x7BEFA000,
                                  (u32) func_80800C10_chjinjo,
                                  0x0};
    int D_808013EC_chjinjo[21] = {0x374048F,
                                  0x6430002,
                                  (u32) &D_808012B0_chjinjo,
                                  (u32) func_808002E0_chjinjo,
                                  (u32) func_80105834,
                                  (u32) func_80101870,
                                  0x9C40000,
                                  0x3F4CCCCD,
                                  0x0,
                                  0x800120,
                                  0x0,
                                  0x0,
                                  0x0,
                                  (u32) func_80800000_chjinjo,
                                  (u32) func_80107C2C,
                                  -0x7BEF9BFE,
                                  (u32) func_80800C10_chjinjo,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0};
