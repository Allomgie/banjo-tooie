#include "common.h"

extern int D_80800A10_chbadshad[];
typedef struct {
    u8 pad[0x78];
    u32 pad1 : 16;
    u32 mode : 2;
    u32 pad2 : 14;
} BadShadFlags97;
extern void func_8010A800(Actor *, s32);
extern Actor *func_80106790();
extern s32 func_80102F74(Actor *, u32);
typedef struct {
    u8 pad[0x18];
    s32 f18;
    u8 pad1C[0x48];
    u32 pad64 : 14;
    u32 flag : 1;
    u32 rest : 17;
} BadShadS;
typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 12;
    u32 local_0 : 1;
    u32 pad_2 : 19;
    u8 pad_3[4];
    u32 pad_4 : 28;
    u32 local_1 : 1;
    u32 pad_5 : 3;
} Mass45ShadowActorFlags;
typedef struct {
    u8 pad0[0x7E];
    u16 f : 1;
    u16 pad : 15;
} SignBf7E_0;
extern Actor *func_801084B0(s32, void *);
extern s32 func_8001211C(void);
extern void _chbaddiesetup_entrypoint_5(s32, s32, f32, s32, s32, s32);
extern s32 _chbadshad_entrypoint_4;
typedef struct {
    u8 pad0[0x7E];
    u16 unk7E_15 : 1;
    u16 pad7E_0 : 15;
} BadShadFlag;
typedef struct {
    u8 pad0[0x7A];
    u16 unk7A_14 : 2;
    u16 pad7A_0 : 14;
    u8 pad7C[2];
    s16 unk7E;
} BadShadActor;
typedef struct {
    u8 pad0[0x1A];
    u16 unk1A_5 : 11;
    u16 pad1A_0 : 5;
} BadShadInfo;
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800DF428(f32);
extern s32 func_80101918(f32);
extern s32 func_800DE448(void *, void *, f32, s32, s32);
typedef struct {
    u32 pad : 5;
    u32 flag : 1;
    u32 pad2 : 26;
} BitTest5;
typedef struct {
    u32 pad : 19;
    u32 flag : 1;
    u32 pad2 : 12;
} BitTest19;
u8 *func_80800664_chbadshad(u8 *param_0, f32 *param_1, f32 param_2);
s32 func_8080078C_chbadshad();
void func_8080082C_chbadshad();
int func_8080086C_chbadshad();

int chbadshad_entrypoint_0()
{
    return (int) &D_80800A10_chbadshad;
}

void func_8080000C_chbadshad(Actor *param_0)
{
    Actor *local_0;

    func_8010A800(param_0, 5);
    local_0 = *(void **) ((u8 *) param_0 + 0x40) ? func_80106790(*(void **) ((u8 *) param_0 + 0x40))
                                                 : NULL;
    if (local_0) {
        if (func_80102F74(local_0, 0x82000000)) {
            ((BadShadFlags97 *) param_0)->mode = 3;
        } else {
            ((BadShadFlags97 *) param_0)->mode = 2;
        }
    }
}

void func_80800090_chbadshad(BadShadS *param_0)
{
    if (!param_0->flag && param_0->f18 < func_8001211C() - 1) {
        func_8080082C_chbadshad(param_0);
    }
}

void func_808000E0_chbadshad(Actor *param_0, s32 param_1)
{
    f32 local_0;
    Actor *local_1;

    local_1 = 0;
    if (param_0->unk64_17) {
        return;
    }
    local_0 = param_0->scale;
    if (param_0->pad40) {
        local_1 = func_80106790(param_0->pad40);
    }
    if (local_1) {
        func_800DF410(_subaddiefade_entrypoint_0(local_1));
    }
    if (!local_1 || !((BitTest5 *) ((u8 *) local_1 + 0x74))->flag) {
        local_0 *= func_800F10B4(((f32 *) param_0->actorData)[3], 0.0f, 800.0f, 0.53f, 0.18f);
    } else {
        local_0 *= 0.5f;
    }
    func_800DF470(1);
    func_800DF428(4000.0f);
    func_800DF830((u32) *(u16 *) ((u8 *) param_0 + 0x7A) >> 14);
    if (((u32) *(u16 *) ((u8 *) param_0 + 0x7A) >> 14) == 3) {
        if (func_800DE448(param_0->position, param_0->rotation, local_0, 0,
                          func_801039E4(param_0->unk0))) {
            ((BitTest19 *) ((u8 *) param_0 + 0x7C))->flag = 1;
        } else {
            ((BitTest19 *) ((u8 *) param_0 + 0x7C))->flag = 0;
        }
    } else {
        if (func_800DE448(param_0->position, param_0->rotation, local_0, func_80101918(local_0),
                          func_801039E4(param_0->unk0))) {
            ((BitTest19 *) ((u8 *) param_0 + 0x7C))->flag = 1;
        } else {
            ((BitTest19 *) ((u8 *) param_0 + 0x7C))->flag = 0;
        }
    }
}

f32 func_8080028C_chbadshad(Actor *param_0, Actor *param_1, f32 *param_2)
{
    f32 local_1[3];
    f32 local_0;

    local_0 = 0.0f;
    if (!((Mass45ShadowActorFlags *) param_0)->local_1 && !(param_1->actorData[1] & 0x80008000) &&
        ((SignBf7E_0 *) param_1)->f) {
        if ((s32) param_1->position[0] == (s32) param_2[0] &&
            (s32) param_1->position[2] == (s32) param_2[2]) {
            param_1->position[0] = param_2[0];
            param_1->position[2] = param_2[2];
            goto done;
        }
    }
    if (((Mass45ShadowActorFlags *) param_0)->local_0) {
        func_800EE7F8(param_1->position, param_2);
        return 0.0f;
    }
    if (*(s16 *) ((u8 *) param_0 + 0x8E) && !func_80105494(param_0) &&
        func_80104668(param_0, param_2, param_1->position, local_1, &local_0)) {
        param_1->actorData[1] = func_8010518C(param_0);
        func_8010279C(param_1, local_1);
        if ((param_1->actorData[1] & 0x80000000)) {
            param_1->unk64_16 = 0;
        } else {
            param_1->unk64_16 = 1;
        }
        return local_0;
    } else if (!func_8080086C_chbadshad(param_1, param_0, &local_0, param_2)) {
        param_1->unk64_16 = 0;
    } else if ((param_1->actorData[1] & 0x80000000)) {
        param_1->unk64_16 = 0;
    } else {
        param_1->unk64_16 = 1;
    }
done:
    return local_0;
}

void chbadshad_entrypoint_1(s32 param_0, s32 param_1, f32 param_2)
{
    u8 *local_0 = func_80800664_chbadshad(param_0, param_1, param_2);
    if (local_0 != NULL) {
        *(f32 *) (local_0 + 0x38) = param_2;
    }
}

s32 chbadshad_entrypoint_2(Actor *param_0, s32 param_1, f32 param_2, f32 *param_3)
{
    f32 local_0[3];

    if (!param_3)
        param_3 = local_0;
    if (_subaddieskeleton_entrypoint_0(param_0, param_1, param_3)) {
        chbadshad_entrypoint_1(param_0, param_3, param_2);
        if (param_0->pad40) {
            func_800EE7F8(param_3, func_80106790(param_0->pad40)->position);
        }
        return 1;
    }
    return 0;
}

void chbadshad_entrypoint_3(Actor *param_0, s32 param_1, s32 param_2, f32 param_3, s16 *param_4)
{
    while (*param_4 != -1) {
        if (param_0->unk70_10 == *param_4) {
            chbadshad_entrypoint_2(param_0, param_2, param_3, 0);
            return;
        }
        param_4++;
    }
    chbadshad_entrypoint_1(param_0, param_1, param_3);
}

void chbadshad_entrypoint_4(s32 param_0, s32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
    f32 local_0[3];
    s32 local_1;
    Actor *local_2;
    f32 local_3;
    Actor *local_4;

    local_1 = param_0;
    if (&param_0) {
    }
    local_2 = func_80106790(local_1);
    local_0[0] = param_2;
    local_0[1] = param_3;
    local_0[2] = param_4;
    if (!local_2->unk64_17) {
        local_3 = *(f32 *) &param_1;
        local_4 = func_801084B0(0x243, &local_2);
        if (local_4) {
            local_4->unk14 = local_2->unk14;
            ((f32 *) local_4->actorData)[3] = func_8080028C_chbadshad(local_2, local_4, local_0);
            if (!local_4->unk64_17) {
                local_2->pad40 = (s32) local_4->unk0;
                local_4->scale = local_3;
                local_4->pad40 = local_1;
                local_4->actorData[0] = func_8001211C();
            }
        }
    }
}

u8 *func_80800664_chbadshad(u8 *param_0, f32 *param_1, f32 param_2)
{
    u8 *obj;
    u8 *a0;

    if (((Actor *) param_0)->unk64_17) {
        a0 = *(u8 **) (param_0 + 0x40);
        if (a0 != 0) {
            func_8080082C_chbadshad(func_80106790(a0));
        }
        return 0;
    }
    a0 = *(u8 **) (param_0 + 0x40);
    if (a0 == 0) {
        _chbaddiesetup_entrypoint_5((s32) &_chbadshad_entrypoint_4, *(s32 *) param_0, param_2,
                                    *(s32 *) param_1, ((s32 *) param_1)[1], ((s32 *) param_1)[2]);
    } else {
        obj = func_80106790(a0);
        if (((Actor *) obj)->unk64_17) {
            return 0;
        }
        if (func_8080078C_chbadshad(obj, param_0) != 0) {
            *(f32 *) (obj + 0x24) = func_8080028C_chbadshad(param_0, obj, param_1);
        } else {
            *(f32 *) (obj + 0x4) = param_1[0];
            *(f32 *) (obj + 0xC) = param_1[2];
        }
        *(s32 *) (obj + 0x18) = func_8001211C();
        *(f32 *) (obj + 0x38) = param_2;
        return obj;
    }
    return 0;
}

s32 func_8080078C_chbadshad(param_0, param_1)
Actor *param_0;
s32 param_1;
{
    if (!((BadShadFlag *) param_0)->unk7E_15) {
        return 1;
    }
    if (func_80104544(param_1)) {
        return 1;
    }
    if (func_800DB9B0()) {
        return 1;
    }
    if (((BadShadActor *) param_0)->unk7A_14 == 3) {
        return 1;
    }
    return ((func_8001211C() ^ ((BadShadInfo *) param_0->unk0)->unk1A_5) & 3) == 0;
}

void func_8080082C_chbadshad(param_0) u8 *param_0;
{
    int new_var;
    s32 temp_a1;
    new_var = 0x40;
    temp_a1 = *(s32 *) ((s8 *) param_0 + 0x40);
    if (temp_a1 != 0) {
        *(s32 *) ((s8 *) func_80106790(temp_a1, *(s32 *) ((s8 *) param_0 + 0x40), param_0) +
                  new_var) = 0;
    }
    func_800FFAB0(param_0);
}

int func_8080086C_chbadshad(param_0, param_1, param_2, param_3)
u8 *param_0;
Actor *param_1;
f32 *param_2;
f32 *param_3;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    s32 local_4;
    u8 *local_5;
    local_4 = func_8010A654(param_1, 0);
    func_800EE7F8(local_0, param_3);
    func_800EE7F8(local_1, param_3);
    local_0[1] += 80.0f;
    local_1[1] -= 100.0f;
    local_5 = (u8 *) func_800C6A7C(local_0, local_1, local_2, *(s32 *) (param_0 + 0x14));
    if (!local_5) {
        local_1[1] = param_3[1] - 2000.0f;
        local_5 = (u8 *) func_800C6A7C(local_0, local_1, local_2, *(s32 *) (param_0 + 0x14));
        if (!local_5) {
            *param_2 = 0.0f;
            func_8010A654(param_1, local_4);
            *(s32 *) (param_0 + 0x1C) = 0;
            return 0;
        }
    }
    *(s32 *) (param_0 + 0x1C) = *(s32 *) (local_5 + 8);
    func_8010A654(param_1, local_4);
    func_800EE7F8((f32 *) (param_0 + 4), local_1);
    *param_2 = func_800F0E00(0.0f, param_3[1] - *(f32 *) (param_0 + 8));
    func_800F1988(local_2, &local_3[0], &local_3[1]);
    local_3[2] = 0.0f;
    func_8010279C(param_0, local_3);
    if (*(s16 *) ((u8 *) param_1 + 0x8E))
        func_801045AC(param_1, local_2, (f32 *) (param_0 + 4), *(s32 *) (local_5 + 8));
    return 1;
}

extern void func_80105834();
extern void func_80107C2C();
int D_80800A10_chbadshad[20] = {0x9B0243,
                                0x6370001,
                                0x0,
                                (u32) func_80800090_chbadshad,
                                (u32) func_80105834,
                                (u32) func_808000E0_chbadshad,
                                0x0,
                                0x0,
                                0x0,
                                0x4,
                                0x0,
                                0x0,
                                0x0,
                                (u32) func_8080000C_chbadshad,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0,
                                0x0,
                                0x0};
