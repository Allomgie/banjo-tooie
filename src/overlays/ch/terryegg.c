#include "common.h"
#include <types.h>
// TU-NOTE: .data tables (below) are defined in C so IDO schedules the functions they point to as in the original; .bss B_80801460_chterryegg is defined before its first use for IDO placement.

#define EGGBIT(p) (((EggBit75 *) (p))->f1)
extern int D_80801328_chterryegg[];
extern int D_80801370_chterryegg[];
extern s32 D_808013B8_chterryegg[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void *func_80100094(Actor *, u32);
extern Actor *func_80106790(Unk80132ED0 *);
extern Unk80132ED0 *func_80101080(void);
extern void func_80102FDC(Actor *, f32);
extern void func_80102424(Actor *, s32);
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern u8 D_80801400_chterryegg[];
extern s32 _chterryegg_entrypoint_0;
typedef struct {
    u8 pad0[0x64];
    u32 pad64_17 : 15;
    u32 unk64_16 : 1;
    u32 pad64_0 : 16;
    u8 pad68[0xC];
    u32 pad74_21 : 11;
    u32 unk74_20 : 1;
    u32 pad74_0 : 20;
    u32 pad78_6 : 26;
    u32 unk78_5 : 1;
    u32 pad78_0 : 5;
} TerryEggFlags;
typedef union {
    s32 local_0;
    void *local_1;
} TerryEggEvent60;
extern f32 func_800DC0C0(void);
extern void func_80101EE4(Actor *, f32);
extern u8 _subaddietaxi_entrypoint_16[];
typedef struct {
    u8 local_0[0x74];
    u32 : 11;
    u32 local_1 : 1;
    u32 : 20;
} TerryEggFlags36;
typedef struct {
    float unk4;
    float unk58;
} ChTerryEgg;
extern ChTerryEgg D_80801410_chterryegg[];
int func_800D9078(int param_0);
void _subaddieaudioquick_entrypoint_2(ChTerryEgg *param_0, float *param_1, ChTerryEgg *param_2);
float func_800DC178(float param_0, float param_1);
extern s32 D_80801424_chterryegg[];
extern s32 D_8080126C_chterryegg[];
extern s32 D_80801438_chterryegg[];
extern void _subaddieaudioquick_entrypoint_4(s32, s32, s32 *, s32 *);
extern s32 D_80801450_chterryegg[];
extern void _subaddieaudioquick_entrypoint_3(u8 *, u8 *, void *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
typedef struct {
    u32 pad : 19;
    u32 flag : 1;
    u32 pad2 : 12;
} TerryEggBits;
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} EggState;
typedef struct {
    u8 pad_0[0x75];
    u8 f0 : 3;
    u8 f1 : 1;
    u8 f2 : 4;
} EggBit75;
extern void *D_80801260_chterryegg[];
extern void func_801058C4(Actor *, s32, f32, s32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_800F4F34(s32, f32 *, f32, f32);
extern f32 func_80102D78(Actor *, f32 *);
typedef struct {
    u8 pad_0[0x74];
    u32 a : 8;
    u32 b0 : 3;
    u32 f1 : 1;
    u32 b1 : 20;
} EggW74;
s32 func_80800BD0_chterryegg();
s32 func_80800C08_chterryegg();
s32 func_80800CF4_chterryegg(s32 param_0, f32 param_1);
void func_80800E88_chterryegg();
s32 func_80801138_chterryegg();
f32 func_80801188_chterryegg();
extern void func_80101870(), func_80107C2C(), func_80108ED0(), func_808009B4_chterryegg();

int *chterryegg_entrypoint_0()
{
    return (int *) D_80801260_chterryegg;
}

int chterryegg_entrypoint_1()
{
    return (int) &D_80801328_chterryegg;
}

int chterryegg_entrypoint_2()
{
    return (int) &D_80801370_chterryegg;
}

int chterryegg_entrypoint_3()
{
    return D_808013B8_chterryegg;
}

int func_80800030_chterryegg(Actor *param_0)
{
    if (func_800DA298(((u32) *(u16 *) ((char *) param_0 + 0x76) >> 7) + 0x143) ||
        func_80801138_chterryegg(param_0)) {
        func_800FFAB0(param_0);
    } else {
        _glsplinefind_entrypoint_0(0x357, (void *) ((char *) param_0 + 0x4));
        func_80103014(param_0);
        func_80800CF4_chterryegg(param_0, 4.0f);
    }
}

void func_808010B0_chterryegg();

// Egg actor: palette fade and hatch sequence.
void func_808000A8_chterryegg(Actor *actor)
{
    s32 player;
    s32 player_b;
    switch (actor->unk70_10) {
        case 1:
            player = _plsu_entrypoint_3(actor->unk0);
            if (player != -1) {
                func_800F7BC8(player, 0x53, actor->unk0);
            }
            break;
        case 3:
            if (((TerryEggBits *) ((u8 *) actor + 0x7C))->flag &&
                func_800D9078(&actor->unk58)) {
                _subaddiepalette_entrypoint_2(actor, func_80100094(actor, 1), 0x7BE,
                                              0x40200000);
                func_80102424(actor, 4);
                actor->unk58 = 2.5f;
            }
            break;
        case 4:
            if (func_800D9078(&actor->unk58)) {
                func_80102424(actor, 5);
                _subaddieDll_entrypoint_4(actor, 0);
            }
            *(f32 *) ((u8 *) actor + 0x28) = func_800F10B4(actor->unk58, 0.0f, 2.5f, 0, 255.0f);
            break;
        case 5:
            player_b = _plsu_entrypoint_3(actor->unk0);
            if (player_b != -1) {
                func_800F7BC8(player_b, 0x53, actor->unk0);
            }
            break;
        case 6:
            func_808010B0_chterryegg(actor);
            if (func_80101E14(actor, 0.3f)) {
                _chexploder_entrypoint_3(actor, actor->position, 8);
                func_80102424(actor, 7);
            }
    }
    _subaddiepalette_entrypoint_1(actor, func_80100094(actor, 1));
}

s32 func_8080023C_chterryegg(Actor *actor, s32 event, s32 arg)
{
    Actor *target;
    f32 pos[3];
    s32 not_defeated;
    f32 *actor_pos;

    switch (event) {
        case 0x18:
            actor_pos = actor->position;
            func_800EE7F8(pos, actor_pos);
            func_800EF1B8(pos, actor->rotation[1] - 40.0f, 150.0f);
            func_800F77E8(func_800F54E4(), pos);
            func_800F8300(func_800F54E4(), 2, actor_pos);
            func_80102424(actor, 6);
            target = func_80106790(actor->unk3C);
            func_80102424(target, 2);
            func_80102FDC(target, func_80801188_chterryegg(target, 1));
            break;
        case 0xA0:
            not_defeated = !func_800DA298(0xE5);
            if (arg && not_defeated) {
                if (!func_800DA9E4(0x39, 1)) {
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x180B, 14, NULL, 0x57);
                } else {
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x180C, 15, NULL, 0x57);
                }
                func_80102424(actor, 2);
            }
            return not_defeated;
        case 0x2E:
            func_80102424(actor, 1);
            break;
        case 0x90:
            target = func_80106790(func_80101080());
            _chexploder_entrypoint_6(target, 600.0f, 800.0f);
            _chexploder_entrypoint_12(target, 10);
            _chexploder_entrypoint_9(target, 1, 2);
            break;
        case 0x1F:
            func_801015D0(actor);
            func_800DF6BC((s32) *(f32 *) &actor->actorData[4], 255);
            _subaddiepalette_entrypoint_3(actor, func_80100094(actor, 1), arg);
            break;
        case 0x29:
            _subaddiepalette_entrypoint_4(actor, func_80100094(actor, 1));
            break;
        case 0x95:
            if (_glcutDll_entrypoint_19(0x33)) {
                _subaddiepalette_entrypoint_0(actor, func_80100094(actor, 1), 0x7BD);
                func_80102424(actor, 3);
                _subaddieDll_entrypoint_4(actor, 1);
                actor->unk58 = 3.0f;
                *(f32 *) &actor->actorData[4] = 255.0f;
            } else if (func_800DA298(0xE5)) {
                func_80102424(actor, 5);
                _subaddiepalette_entrypoint_0(actor, func_80100094(actor, 1), 0x7BE);
                *(f32 *) &actor->actorData[4] = 0.0f;
            } else {
                _subaddiepalette_entrypoint_0(actor, func_80100094(actor, 1), 0x7BD);
                *(f32 *) &actor->actorData[4] = 255.0f;
            }
            _subaddiefind_entrypoint_7(actor, 0x3D6, 100);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_8080057C_chterryegg(this) Actor *this;
{
    func_80102FDC(this, func_80801188_chterryegg(this, 0));
    func_801088A8(this, 0x10002000, 0, 0);
}

s32 func_808010DC_chterryegg();

void func_80801080_chterryegg();

void func_80800FE0_chterryegg();

// Matching: the line breaks in this function are needed for the match.
void func_808005C4_chterryegg(Actor *actor)
{
    s32 draw_shadow;
    s32 *spline;
    f32 target_pos[3];
 // Matching: needed for the match.
    s32 k0 = 1;
    draw_shadow = 1;

    switch (((EggState *)actor)->st) {
        case 1:
        draw_shadow = 0;
        actor->unk64_16 = 0; EGGBIT(actor) = 0;
        if (func_800DA298(0xE5)) {
            func_80800FE0_chterryegg(actor);
        }
        break;
        case 2:
        actor->unk64_16 = 1;
        ((EggW74 *)actor)->f1 = actor->unk64_16;
        draw_shadow = 0;
        if (func_80101DDC(actor)) {
            func_800F82D4(func_800F54E4(), 0);
            if (func_808010DC_chterryegg() == k0) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17FE, 0xF, actor->position, 0);
                func_800DA7A8(0x361, actor->unk74_7 - 0x31, 3);
                func_80102424(actor, 4);
                func_8010A590(actor);
            } else {
                spline = func_80100094(actor, 0);
                func_800DA544(actor->unk74_7 + 0x143);
                func_800CB698(actor->unk74_7 - 0x2B, 6);
                func_80102424(actor, 5);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17E1, 0x44, actor->position, 0);
                _subaddieDll_entrypoint_4(actor, 1);
                if (*spline != -1) {
                    _capod_entrypoint_13(actor->unk0, 0, ((u8 *)D_80801260_chterryegg + 8)[actor->unk74_7 - 0x32], 0x31);
                    func_801058C4(actor, *spline, 200.0f, 1);
                }
            }
        }
        break;
        case 3:
        func_80801080_chterryegg(actor);
        break;
        case 4:
        func_80801050_chterryegg(actor);
        break;
        case 5:
        func_800FFAB0(actor);
        break;
        case 6:
        func_80801050_chterryegg(actor);
        break;
        case 7:
        func_80801050_chterryegg(actor);
        break;
        case 8:
        draw_shadow = 0;
        break;
        case 9:
        draw_shadow = 0;
        func_80801080_chterryegg(actor);
        if (_subaddietaxi_entrypoint_1(actor, actor->unk74_7 - 0x2B)) {
            func_80102424(actor, 0xB);
            func_800DA544(actor->unk74_7 + 0x143);
            func_80101180(0x36F, 0x31, actor->unk74_7 - 0x32);
        }
        break;
        case 10:
        func_80801050_chterryegg(actor);
        if (_subaddietaxi_entrypoint_11(actor, actor->unk74_7 - 0x2B)) {
            if (_subaddietaxi_entrypoint_5(actor, actor->unk74_7 - 0x2B)) {
                _subaddietaxi_entrypoint_14(actor, actor->unk74_7 - 0x2B);
                func_80102424(actor, 0xC);
            }
        }
        draw_shadow = _subaddietaxi_entrypoint_12(actor, actor->unk74_7 - 0x2B);
        break;
        case 11:
        func_800EFD24(target_pos);
        actor->unk54 = func_80102D78(actor, target_pos);
        func_80102BF8(actor, 0.1f, 4.0f, 80.0f);
        func_80801080_chterryegg(actor);
        break;
        case 12:
        if (_subaddietaxi_entrypoint_15(actor, actor->unk74_7 - 0x2B)) {
            func_80102424(actor, 6);
            func_8010A590(actor);
        }
    }

    _subaddietaxi_entrypoint_9(actor, actor->unk74_7 - 0x2B);

    if (draw_shadow) {
        func_800F4F34(func_800F54E4(), actor->position, actor->scale * 20.0f,
        actor->scale * 20.0f);
    }

}

void func_808009B4_chterryegg(param_0) u8 *param_0;
{
    if (((((((u16) *(u16 *) ((s8 *) param_0 + 0x72) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) &
          0xFFFFFFFF) >>
         0xA) == 5) {
        func_80105834();
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80801400_chterryegg, 0.25f);
        if (func_80105A5C(param_0) != 0) {
            _capod_entrypoint_14();
            func_800FFAB0(param_0);
        }
    }
}

int func_80800A2C_chterryegg(param_0, param_1, param_2)
Actor *param_0;
s32 param_1;
s32 param_2;
{
    switch (param_1) {
        case 0x3E:
            if (_subaddietaxi_entrypoint_2(param_0, param_0->unk74_7 - 0x2B)) {
                func_80102424(param_0, 8);
            }
            break;
        case 0x2E:
            func_80800BD0_chterryegg(param_0, ((s16 *) &param_2)[0], ((s16 *) &param_2)[1]);
            break;
        case 0x44:
            func_80800E88_chterryegg(param_0, param_2);
            break;
        case 0x95:
            if (_glcutDll_entrypoint_19(0x33)) {
                _subaddieDll_entrypoint_4(param_0, 1);
            }
            if (_subaddietaxi_entrypoint_13(param_0, param_0->unk74_7 - 0x2B,
                                            &_chterryegg_entrypoint_0, 3)) {
                func_80800C08_chterryegg(param_0);
                if (func_80801138_chterryegg(param_0)) {
                    ((TerryEggFlags *) param_0)->unk64_16 = 1;
                    ((TerryEggFlags *) param_0)->unk74_20 = ((TerryEggFlags *) param_0)->unk64_16;
                    func_80102424(param_0, 6);
                } else {
                    func_8010A570(param_0);
                    ((TerryEggFlags *) param_0)->unk64_16 = 0;
                    ((TerryEggFlags *) param_0)->unk74_20 = ((TerryEggFlags *) param_0)->unk64_16;
                }
            } else if (((TerryEggFlags *) param_0)->unk78_5) {
                func_800FFAB0(param_0);
            }
            break;
        default:
            return 0;
    }

    return 1;
}

s32 func_80800BD0_chterryegg(param_0, param_1, param_2)
s32 param_0;
s32 param_1;
s32 param_2;
{
    switch (param_1) {
        case 0x17E1:
            break;
        case 0x17FE:
            func_80102424(param_0, 6);
    }
}

s32 func_80800C08_chterryegg(param_0)
s32 param_0;
{
    s32 *local_0;
    local_0 = func_80100094(param_0, 0);
    *local_0 = _glsplinefind_entrypoint_0(0x357, param_0 + 4);
}

void func_80800C48_chterryegg(s32 arg0)
{
    func_8010C964();
    func_80801080_chterryegg(arg0);
}

s32 func_80800C70_chterryegg(Actor *param_0, s32 param_1, TerryEggEvent60 param_2)
{
    if (param_1 == 0x95) {
        func_80800CF4_chterryegg(param_0, func_80801188_chterryegg(param_0, 0));
        func_80101EE4(param_0, func_800DC0C0());
        if (!func_800DA298(param_0->unk74_7 + 0x143)) {
            func_800FFAB0(param_0);
        }
        return 1;
    }

    return 0;
}

s32 func_80800CF4_chterryegg(s32 param_0, f32 param_1)
{
    func_80102FDC(param_0, param_1);
    return 1;
}

int func_80800D20_chterryegg(s32 param_0, s32 *param_1, s32 param_2, s32 param_3)
{
    if (!func_800DA298(param_0 + 0x16E)) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, param_0, param_1[0], param_1[1],
                                    param_1[2], param_2, param_3);
    }
}

Prop *B_80801460_chterryegg[4];

void func_80800D88_chterryegg(s32 egg_id, f32 *out_pos)
{
    s32 count;
    s32 i;

    count = _gccubesearch_entrypoint_9(0x3D7, B_80801460_chterryegg, 4);
    for (i = 0; i < count; i++) {
        if (egg_id + 0x2B == B_80801460_chterryegg[i]->unk6_7) {
            func_800EE88C(out_pos, B_80801460_chterryegg[i]);
            return;
        }
    }
}

int func_80800E0C_chterryegg(s32 param_0, s32 param_1, s32 param_2)
{
    int new_var;
    if (func_800EA05C() == 0x113) {
        if (func_800CBD84(param_1) != -1) {
            func_80800D88_chterryegg(param_0, param_2);
            return 2;
        }
    }

    func_800C05B8(0x17E0, 1, 0, 0, 0, new_var = 0, 0);
    return 1 ^ 0;
}

void func_80800E88_chterryegg(param_0, param_1) Actor *param_0;
s32 param_1;
{
    f32 local_0[3];

    func_80100120();
    func_80800CF4_chterryegg(param_0, func_80801188_chterryegg(param_0, 0));
    switch (func_800CB3E0(param_1)) {
        case 1:
            if (func_800DA298(param_0->unk74_7 + 0x143) || func_80801138_chterryegg(param_0)) {
                func_80102424(param_0, 6);
                func_8010A590(param_0);
            } else {
                func_80800C08_chterryegg(param_0);
                func_80102424(param_0, 1);
                func_8010A570(param_0);
                param_0->unk64_16 = 0;
                ((TerryEggFlags36 *) param_0)->local_1 = *(u16 *) ((u8 *) param_0 + 0x64);
            }
            break;
        case 3:
            _subaddietaxi_entrypoint_10(param_0, param_1, 10);
            break;
        case 4:
            func_80800D88_chterryegg(param_1, local_0);
            func_8010A570(param_0);
            _subaddietaxi_entrypoint_0(param_0, param_1, local_0, 9);
            break;
        case 6:
            func_80102424(param_0, 11);
            func_8010A570(param_0);
    }
}

void func_80800FE0_chterryegg(ChTerryEgg *param_0)
{
    func_800D9078(((int) param_0) + 0x58);
    if ((*(f32 *) ((char *) (param_0) + 88)) <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(param_0, (float *) ((char *) param_0 + 4),
                                         &D_80801410_chterryegg);
        (*(f32 *) ((char *) (param_0) + 88)) = func_800DC178(1.5f, 2.5f);
    }
}

int func_80801050_chterryegg(s32 param_0)
{
    s32 local_0;
    local_0 = param_0 + 4;
    _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80801424_chterryegg, 0.81f);
}

void func_80801080_chterryegg(s32 param_0)
{
    _subaddieaudioquick_entrypoint_4(param_0, param_0 + 4, &D_8080126C_chterryegg,
                                     &D_80801438_chterryegg);
}

void func_808010B0_chterryegg(u8 *param_0)
{
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80801450_chterryegg, 0.0f);
}

s32 func_808010DC_chterryegg()
{
    s32 returned_bits;
    s32 returned_count;

    returned_bits = func_800DA564(0x175, 4);
    returned_count = 0;
    if (returned_bits & 1) {
        returned_count++;
    }
    if (returned_bits & 2) {
        returned_count++;
    }
    if (returned_bits & 4) {
        returned_count++;
    }
    if (returned_bits & 8) {
        returned_count++;
    }
    return 4 - returned_count;
}

s32 func_80801138_chterryegg(param_0)
u8 *param_0;
{
    s32 local_0;

    local_0 = func_800DA564(0x361, 3);
    if (local_0 == 0) {
        return 0;
    }
    return (local_0 + 0x31) == ((u32) ((u16) (*(u16 *) ((s8 *) (param_0) + (0x76)))) >> 7);
}

f32 func_80801188_chterryegg(param_0, param_1)
Actor *param_0;
s32 param_1;
{
    if (param_1) {
        return func_808010DC_chterryegg(param_0) == 1 ? 4.0f : 2.0f;
    } else {
        return func_80801138_chterryegg(param_0) ? 4.0f : 2.0f;
    }
}

extern int func_80105834();
extern void func_801018A4();
void *D_80801260_chterryegg[3] = {(void *) func_80800E0C_chterryegg,
                                  (void *) func_80800D20_chterryegg, (void *) 0x14100D4E};
s32 D_8080126C_chterryegg[5] = {0x130562, 0xD00F3, 0x10C0001, 0x19005DC, 0x0};
u32 D_80801280_chterryegg[16] = {
    0x0,        0x0,       0x0,        0x0,       0x0,        0x0,       0x0, 0x0,
    0x40B00000, 0x1D40001, 0x40B00000, 0x1D40001, 0x3F75C28F, 0x1D50002, 0x0, 0x0};
u8 D_808012C0_chterryegg[104] = {
    0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x0,  0x3F, 0xC0, 0x0,  0x0,  0x1,  0xF9, 0x0,  0x2,  0x40, 0x7B, 0x85, 0x1F, 0x1,  0xFB,
    0x0,  0x1,  0x41, 0x9,  0x99, 0x9A, 0x1,  0xFA, 0x0,  0x1,  0x3E, 0xCC, 0xCC, 0xCD, 0x1,
    0x68, 0x0,  0x1,  0x41, 0x9,  0x99, 0x9A, 0x1,  0xFA, 0x0,  0x1,  0x41, 0x9,  0x99, 0x9A,
    0x1,  0xFA, 0x0,  0x1,  0x41, 0x9,  0x99, 0x9A, 0x1,  0xFA, 0x0,  0x1,  0x40, 0x7B, 0x85,
    0x1F, 0x1,  0xFB, 0x0,  0x1,  0x41, 0x9,  0x99, 0x9A, 0x1,  0xFA, 0x0,  0x1,  0x40, 0x7B,
    0x85, 0x1F, 0x1,  0xFB, 0x0,  0x1,  0x41, 0x9,  0x99, 0x9A, 0x1,  0xFA, 0x0,  0x1};
int D_80801328_chterryegg[18] = {0x31203AA,
                                 0x7020001,
                                 (u32) &D_80801280_chterryegg,
                                 (u32) func_808000A8_chterryegg,
                                 (u32) func_80105834,
                                 (u32) func_801018A4,
                                 0x3E80000,
                                 0x3F4CCCCD,
                                 0x7BD,
                                 0x40000808,
                                 0x0,
                                 0x0,
                                 0x810,
                                 (u32) func_80800030_chterryegg,
                                 (u32) func_80107C2C,
                                 -0x7DFEDBFE,
                                 (u32) func_8080023C_chterryegg,
                                 0x0};
int D_80801370_chterryegg[18] = {0x9E03D6,
                                 0x7030001,
                                 (u32) &D_808012C0_chterryegg,
                                 (u32) func_808005C4_chterryegg,
                                 (u32) func_808009B4_chterryegg,
                                 (u32) func_80101870,
                                 0x7D00000,
                                 0x3ECCCCCD,
                                 0x0,
                                 0x40040104,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x40000,
                                 (u32) func_8080057C_chterryegg,
                                 (u32) func_80107C2C,
                                 -0x7FFFFFF0,
                                 (u32) func_80800A2C_chterryegg,
                                 0x0};
s32 D_808013B8_chterryegg[18] = {0x9E03D7,
                                 0x703000B,
                                 (u32) &D_808012C0_chterryegg,
                                 (u32) func_80800C48_chterryegg,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x7D00000,
                                 0x3ECCCCCD,
                                 0x0,
                                 0x50802100,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_80107C2C,
                                 -0x7DFFDBEE,
                                 (u32) func_80800C70_chterryegg,
                                 0x0};
u8 D_80801400_chterryegg[16] = {0x0, 0x13, 0x3, 0xFF, 0x0,  0xD,  0x1, 0x26,
                                0x1, 0x40, 0x0, 0x16, 0x2E, 0xE0, 0x0, 0x0};
ChTerryEgg D_80801410_chterryegg[2] = {1.746807e-39f, 1.194202e-39f, 2.5713942e-38f,
                                       5.2905654e-38f};
static u32 D_80801410_chterryegg_rest[1] = {0x5A050000};
s32 D_80801424_chterryegg[5] = {0x130563, 0xD00F3, 0x10C0001, 0x19005DC, 0x0};
s32 D_80801438_chterryegg[6] = {0x3DCCCCCD, 0x3E19999A, 0x3E570A3D,
                                0x3F19999A, 0x3F75C28F, -0x40800000};
s32 D_80801450_chterryegg[4] = {0x130561, 0x20018, 0x0, 0x0};
