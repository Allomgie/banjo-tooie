#include "common.h"

typedef struct {
    f32 local_0[3];
} Mass43ToxicVector_80800000_chtoxicroombits;
extern s32 D_80800F00_chtoxicroombits[];
extern s32 D_80800F0C_chtoxicroombits[];
extern s32 D_80800F54_chtoxicroombits[];
extern s32 D_80800FA0_chtoxicroombits[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern Actor *func_80108474(s32, f32 *, s32);
extern int D_80800FB0_chtoxicroombits[];
extern int D_80801004_chtoxicroombits[];
extern u8 D_80801005_chtoxicroombits[];
extern void func_800DA7A8();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _chmrtannoy_entrypoint_0();
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 D_80801028_chtoxicroombits[];
extern int D_80801034_chtoxicroombits[];
extern void func_800E2588();
extern void func_800E2AA4();
extern f32 func_800138D0(f32);
extern f32 mlAbsF(f32);
extern s32 _subaddiefind_entrypoint_4(s32, Actor **, s32);
extern f32 func_800D91B8(f32 *);
extern f32 func_800D8FF8(void);
extern f32 func_80103EF4(Actor *);
extern f32 func_80103EAC(Actor *);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
typedef struct Mass43ToxicVector_80800A2C_chtoxicroombits {
    f32 local_0[3];
} Mass43ToxicVector_80800A2C_chtoxicroombits;
extern Mass43ToxicVector_80800A2C_chtoxicroombits D_80801010_chtoxicroombits;
extern Mass43ToxicVector_80800A2C_chtoxicroombits D_8080101C_chtoxicroombits;
extern void func_800DE498(void *, f32 *, f32 *, f32, s32, void *);
s32 func_808004C8_chtoxicroombits();
int func_808004F0_chtoxicroombits();
void func_80800960_chtoxicroombits();

// Product actor message handler: break (0x40), remove (0xF), spawn gas fog (0x3D).
s32 func_80800000_chtoxicroombits(Actor *actor, s32 msg, s32 arg)
{
    Mass43ToxicVector_80800000_chtoxicroombits spawn_pos;
    f32 *pos;

    switch (msg) {
        case 0x40:
            pos = actor->position;
            _subaddieaudioquick_entrypoint_2(actor, pos, &D_80800FA0_chtoxicroombits);
            if (*(u16 *) ((u8 *) actor->unk0 + 0x14) == 0x884) {
                func_800BBCB8(pos, NULL, 1.0f, 5, &D_80800F54_chtoxicroombits);
                if (!func_800DA298(0x1BD)) {
                    func_800DA544(0x1BD);
                    func_80108B04(actor, 0);
                    func_80101180(0x3A7, 10, 1);
                    func_80101180(0x3EB, 0x34, 0);
                }
            } else {
                func_800BBCB8(pos, NULL, 1.0f, 5, &D_80800F0C_chtoxicroombits);
                if (!func_800D0A9C(0x38, 1)) {
                    func_808004C8_chtoxicroombits(func_808004F0_chtoxicroombits() - 1);
                    if (!func_808004F0_chtoxicroombits()) {
                        func_800FC6B0(0x10);
                        func_800D1000(0x38, 1, pos, 5, 0);
                        func_80101180(0x3EB, 0x34, 1);
                    } else {
                        func_800FC6B0(0xE);
                    }
                }
            }
            _chskeletonexplode_entrypoint_7(actor, pos);
            return 1;
        case 0xF:
            func_800FFA88(actor->unk0);
            return 1;
        case 0x3D:
            spawn_pos = *(Mass43ToxicVector_80800000_chtoxicroombits *) &D_80800F00_chtoxicroombits;
            *(f32 *) &func_80108474(0x178, spawn_pos.local_0, 0)->actorData[7] = 8.0f;
            return 1;
    }
    return 0;
}

// Product actor update: bobbing along the belt.
void func_808001D4_chtoxicroombits(Actor *actor, s32 unk_1)
{
    f32 t;
    f32 bone_pos[3];
    f32 vec[3];
    f32 blend;

    t = func_800F10B4(actor->position[2], 2000.0f, -2000.0f, 0.0f, 1.0f);
    actor->position[1] = func_800138D0(t * 360.0f * 18.0f) * 3.0f + 395.0f;
    *(f32 *) ((u8 *) actor + 0x44) = func_800138D0(t * 360.0f * 18.0f);
    func_80101870(actor, unk_1);
    if (actor->unk7C_12 && *(u16 *) ((u8 *) actor->unk0 + 0x14) == 0x885) {
        func_800E3980(vec);
        if (vec[0] < -400.0f) {
            _subaddieskeleton_entrypoint_2(actor->unk0, 5, bone_pos);
        } else {
            _subaddieskeleton_entrypoint_2(actor->unk0, 4, bone_pos);
        }
        if (bone_pos[2] < 650.0f && bone_pos[2] > 550.0f) {
            blend = mlAbsF(bone_pos[2] - 600.0f) / 50.0f;
        } else if (bone_pos[2] < -550.0f && bone_pos[2] > -650.0f) {
            blend = mlAbsF(bone_pos[2] + 600.0f) / 100.0f;
        } else {
            return;
        }
        func_800EFA4C(vec, 1.0f - blend, 1.0f - blend, 1.0f);
        func_800E2588(1);
        func_800E2AA4(unk_1, func_800D674C(0x9DE), 0, 0, bone_pos, vec);
    }
}

int chtoxicroombits_entrypoint_0()
{
    return (int) &D_80800FB0_chtoxicroombits;
}

int func_80800410_chtoxicroombits()
{
    s32 idx = func_808004F0_chtoxicroombits() ? func_808004F0_chtoxicroombits() : 6;
    return *(u8 *) ((char *) D_80801004_chtoxicroombits + -(idx << 1));
}

f32 func_80800458_chtoxicroombits(void)
{
    s32 idx;
    idx = func_808004F0_chtoxicroombits() ? func_808004F0_chtoxicroombits() : 6;
    return (f32) (u32) D_80801005_chtoxicroombits[-(idx * 2)] / 10.0f;
}

s32 func_808004C8_chtoxicroombits(count)
s32 count;
{
    func_800DA7A8(0x6DF, count, 3);

}

int func_808004F0_chtoxicroombits()
{
    if (!func_800D0A9C(0x38, 1)) {
        if (_glcutDll_entrypoint_19(0x41) == 0) {
            return func_800DA564(0x6DF, 3);
        }
    }

return 6;
}

void func_80800540_chtoxicroombits(Actor *conveyor)
{
    s32 i;
    f32 num_steps = 16.0f;

if (!func_800DA298(0x6E2)) {
    func_808004C8_chtoxicroombits(6);
    func_800DA544(0x6E2);
}

*(f32 *) ((u8 *) conveyor + 0x34) = func_80800458_chtoxicroombits();
conveyor->unk79_4 = func_80800410_chtoxicroombits();

if (func_800DB9B0()) {
    conveyor->unk6C_0 = 0;
} else {

conveyor->unk6C_0 = 8;

}
i = 16;
conveyor->unk58 = *(f32 *) ((u8 *) conveyor + 0x34) / num_steps;
*(f32 *) ((u8 *) conveyor + 0x18) = 0.0f;
for (; i != 0; i--) {
    if (--conveyor->unk79_4 == 0) {
        func_80800960_chtoxicroombits(conveyor, i);
    }

}
}

s32 func_80800BE4_chtoxicroombits();

// Conveyor update: moves products along -Z and pushes the player.
void func_80800630_chtoxicroombits(Actor *conveyor)
{
    Actor *products[20];
    f32 step;
    Vec3f player_pos;
    s32 in_push_zone;
    s32 i;
    s32 product_count;
    f32 unk_0;

    product_count = _subaddiefind_entrypoint_4(0x3EA, products, 20);
    if (*(f32 *) &conveyor->actorData[7] + 0.05f < func_80800458_chtoxicroombits()) {
        *(f32 *) &conveyor->actorData[7] += 0.05f;
    } else if (func_80800458_chtoxicroombits() < *(f32 *) &conveyor->actorData[7] - 0.05f) {
        *(f32 *) &conveyor->actorData[7] -= 0.05f;
    } else {
        *(f32 *) &conveyor->actorData[7] = func_80800458_chtoxicroombits();
    }
    _subaddieaudioloop_entrypoint_0(
        conveyor, func_800F10B4(func_808004F0_chtoxicroombits(), 6.0f, 1.0f, 0.45f, 0.7f));
    func_800E3980(player_pos.f);
    if (player_pos.pos.x > -200.0f && !func_800DA298(0xA04) && func_800DA298(0x1BD)) {
        _subaddieaudioloop_entrypoint_1(conveyor, 0x1F40);
    } else {
        _subaddieaudioloop_entrypoint_1(conveyor, 0x55F0);
    }
    _subaddieaudioloop_entrypoint_4(conveyor, conveyor->position, 1,
                                    ((u8 *) D_80801004_chtoxicroombits));
    if (*(f32 *) &conveyor->actorData[7] / 16 <= func_800D91B8(&conveyor->unk58)) {
        conveyor->unk58 -= *(f32 *) &conveyor->actorData[7] / 16;

if (--conveyor->unk79_4 == 0) {
    func_80800960_chtoxicroombits(conveyor, 0);
}

}
in_push_zone = func_80800BE4_chtoxicroombits(conveyor);
step = (func_800D8FF8() / (*(f32 *) &conveyor->actorData[7] / 16)) * 250.0f;
for (i = 0; i < product_count; i++) {
    products[i]->position[2] -= step;

if (products[i]->position[2] < -2000.0f) {
    func_800FFAB0(products[i]);
} else if (in_push_zone) {

unk_0 = func_80103EF4(products[i]);
_sudeflect_entrypoint_1(products[i]->position, unk_0, 0.0f, func_80103EAC(products[i]),
                        30);
}
}
if (*(f32 *) &conveyor->actorData[0] != 0.0f && func_800D90A4((f32 *) &conveyor->actorData[0])) {
    if (conveyor->unk64_19) {
        _capod_entrypoint_13(conveyor->unk0, 0, 5, 0x90);
        *(f32 *) &conveyor->actorData[1] = func_80106790(func_800D0634(0x38, 1))->position[1];
    } else if (!func_800DA298(0x1BE)) {
        func_800DA544(0x1BE);
        _capod_entrypoint_13(conveyor->unk0, 0, 3, 0x10);
    }
}
}

void func_80800960_chtoxicroombits(conveyor, index) Actor *conveyor;
s32 index;
{
    if (_glcutDll_entrypoint_19(0x41)) {
        if ((1 << conveyor->unk6C_0) & 0x410)
            index += 100;
        conveyor->unk6C_0++;
    } else {
        if (--conveyor->unk6C_0 == 0) {
            index += 100;
            conveyor->unk6C_0 = 8;
        }
    }
    func_80108B04(conveyor, index);
    conveyor->unk79_4 = func_80800410_chtoxicroombits();
}

void func_80800A2C_chtoxicroombits(Actor *conveyor, void *unk_1)
{
    Mass43ToxicVector_80800A2C_chtoxicroombits pos = D_80801010_chtoxicroombits;
    f32 t;
    s32 i;
    Mass43ToxicVector_80800A2C_chtoxicroombits rot;
    pos.local_0[2] +=
        func_800F10B4(conveyor->unk58, 0.0f, ((f32 *) conveyor->actorData)[7] / 16, 250.0f, 0.0f);
    for (i = 0; i < 16; i++) {
        t = func_800F10B4(pos.local_0[2], -2000.0f, 2000.0f, 0.0f, 1.0f);
        rot = D_8080101C_chtoxicroombits;
        pos.local_0[1] = func_800138D0((t * 360.0f) * 18.0f) * 3.0f + 395.0f;
        rot.local_0[0] = func_800138D0((t * 360.0f) * 18.0f);
        func_800DF830(1);
        func_800DE498(unk_1, pos.local_0, rot.local_0, 1.0f, 0, func_800D674C(0x882));
        pos.local_0[2] += 250.0f;
    }
}

// Pushes the player along the belt; returns 1 while the player is on it.
s32 func_80800BE4_chtoxicroombits(Actor *conveyor)
{
    f32 player_pos[3];

    func_800F5A00(func_800F54E4(), player_pos);
    if (-600.0f <= player_pos[0] && player_pos[0] <= -200.0f) {
        if (func_800F6C5C(func_800F54E4())) {
            func_800EFA4C(player_pos, 0.0f, 0.0f, -(4000.0f / *(f32 *) &conveyor->actorData[7]));
            func_800F48BC(func_800F54E4(), player_pos);
        }
        return 1;
    }
    return 0;
}

s32 func_80800CB0_chtoxicroombits(Actor *conveyor, s32 msg, s32 arg)
{
    f32 pos[3];
    Actor *product;

    switch (msg) {
        case 0x34:
            if (arg != 0) {
                conveyor->unk64_19 = 1;
                (*(f32 *) &conveyor->actorData[0]) = 0.25f;

}
else
{
    if (func_800DA298(0x6AB) == 0) {
        _chmrtannoy_entrypoint_0();
        _subaddiedialog_entrypoint_11(conveyor->unk0, 0x133E, 7, conveyor->position, 0xA3);
        func_800DA544(0x6AB);
    } else {

func_800CF2D4(4);
}
(*(f32 *) &conveyor->actorData[0]) = 1.5f;
conveyor->unk64_19 = 0;
}
return 1;
case 0xE:
    if (arg == 5) {
        func_800EE7F8(pos, func_80106790(func_800D0634(0x38, 1))->position);
        if ((*(f32 *) &conveyor->actorData[1]) < pos[1]) {
            pos[1] = (*(f32 *) &conveyor->actorData[1]);
        } else {
            (*(f32 *) &conveyor->actorData[1]) = pos[1];
        }
        _capod_entrypoint_19(pos);
    }
    return 3;
case 0x2E:
    if (((s16 *) &arg)[0] == 0x133E) {
        func_800CF2D4(4);
    }
    return 1;
case 0x3D:
    product = func_80108474(0x3EA, D_80801028_chtoxicroombits, 0xB4);
    func_80109F08(product, 0x40);
    if (arg >= 100) {
        func_80103140(product, 0x885, product->unk0->unk16);
        arg -= 100;
    } else {
        func_80103140(product, 0x884, product->unk0->unk16);
    }
    product->position[2] -= func_800F10B4((f32) arg, 0.0f, 16.0f, 0.0f, 4000.0f);
    return 1;
default:
    return 0;
    }
    }

    int chtoxicroombits_entrypoint_1()
    {
        return (int) &D_80801034_chtoxicroombits;
    }

    // TU-NOTE: .data is defined in C; its tables point to functions of this file, and IDO schedules
    // them differently unless they share the unit. D_80801005 = D_80801004 + 1 (linker symbol).
    extern void func_80105834();
    extern void func_80108ED0();
    extern void func_80107C2C();
    s32 D_80800F00_chtoxicroombits[3] = {-0x3C380000, 0x43C80000, 0x44FA0000};
    s32 D_80800F0C_chtoxicroombits[18] = {0x1D09DD, 0x2B0800,  0xC000022,   0x2000280, 0x8000A00,
                                          0x15000C, 0x990019,  0x7,         0x2C0000,  0xFF38,
                                          0x64,     -0x63FFE0, -0x5F5F5F80, 0xAFFEC,   -0x310014,
                                          0x140032, 0x140016,  0x40000};
    s32 D_80800F54_chtoxicroombits[19] = {0x1D09DD,  0x2B0500,  0x7000022, 0x2000280,  0x14001E00,
                                          0x15000C,  0x990019,  0x7,       0x2C0000,   0xFF38,
                                          0x64,      -0x63FFE1, 0xFF0A00,  0x5002000A, -0x130032,
                                          -0x13FFEC, 0x320014,  0x160004,  0x0};
    s32 D_80800FA0_chtoxicroombits[4] = {0x1304A0, 0x166D60, 0x100C8, 0x17700000};
    int D_80800FB0_chtoxicroombits[21] = {0x10E03EA,
                                          0x8840001,
                                          0x0,
                                          0x0,
                                          (u32) func_80105834,
                                          (u32) func_808001D4_chtoxicroombits,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x20800044,
                                          0x0,
                                          (u32) func_80108ED0,
                                          0x0,
                                          0x0,
                                          (u32) func_80107C2C,
                                          -0x7FFFF800,
                                          (u32) func_80800000_chtoxicroombits,
                                          0x0,
                                          0x44B0344,
                                          0x23D0236,
                                          0x12F0128};
    int D_80801004_chtoxicroombits[3] = {0x130527, 0x103E8, 0xFA00000};
    Mass43ToxicVector_80800A2C_chtoxicroombits D_80801010_chtoxicroombits = {-4e+02f, 395.0f,
                                                                             -2e+03f};
    Mass43ToxicVector_80800A2C_chtoxicroombits D_8080101C_chtoxicroombits = {0.0f, 0.0f, 0.0f};
    f32 D_80801028_chtoxicroombits[3] = {-4e+02f, 397.0f, 2e+03f};
    int D_80801034_chtoxicroombits[19] = {0x15803EB,
                                          -0xFFFF,
                                          0x0,
                                          (u32) func_80800630_chtoxicroombits,
                                          (u32) func_80105834,
                                          (u32) func_80800A2C_chtoxicroombits,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0xC00,
                                          0x0,
                                          0x0,
                                          0x0,
                                          (u32) func_80800540_chtoxicroombits,
                                          (u32) func_80107C2C,
                                          -0x7FFFFBFE,
                                          (u32) func_80800CB0_chtoxicroombits,
                                          0x0,
                                          0x0};
