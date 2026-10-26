#include "common.h"

typedef struct { f32 local_0[3]; f32 local_1; } DrillfieldPlacement;
extern DrillfieldPlacement D_808008D0_chfantasydrillfield[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct { s32 key; s32 val; } DrillEnt;
extern s32 _gccubesearch_entrypoint_9(s32, void *, s32);
extern s32 func_800DA298(s32);
extern void func_800DA3B8(s32, s32);
extern void func_800DA544(s32);
extern s32 func_800DC128(s32, s32);
extern s32 func_800DC090(void);
extern void func_800DC324(s32);
typedef struct { s32 unused; s32 value; } DrillFieldRecord;
extern DrillFieldRecord B_80800A10_chfantasydrillfield[8];
extern void func_800DA524(s32);
extern s32 D_808008B0_chfantasydrillfield[];
extern u8 D_80800950_chfantasydrillfield[];
extern u8 D_80800988_chfantasydrillfield[];
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_80103EAC(Actor *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern Actor *func_80106790(Unk80132ED0 *);
extern Unk80132ED0 *func_800D10D4(u32, u32, f32 *, s32, Unk80132ED0 *);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 _subaddiefind_entrypoint_5(s32, Actor **, s32, f32 *, f32, f32 (*)(f32 *, f32 *));
extern int D_808009C4_chfantasydrillfield;
s32 func_80800360_chfantasydrillfield();

void func_80800000_chfantasydrillfield(param_0) Actor *param_0;
{
    Actor *local_0[8];
    s32 local_1;
    s32 local_2;

    local_1 = _subaddiefind_entrypoint_4(0x40A, local_0, 8) - 1;
    local_2 = 0;
    while (local_1 >= 0) {
        if (local_0[local_1]->pad6C_21 < param_0->pad6C_21) local_2++;
        local_1--;
    }
    func_800EFA4C(param_0->position, D_808008D0_chfantasydrillfield[local_2].local_0[0],
                 D_808008D0_chfantasydrillfield[local_2].local_0[1], D_808008D0_chfantasydrillfield[local_2].local_0[2]);
    param_0->rotation[1] = D_808008D0_chfantasydrillfield[local_2].local_1;
    func_80103014(param_0);
}

void func_808000C4_chfantasydrillfield(s32 param_0)
{
    void *sp70[8];
    s32 n;
    s32 m;
    s32 i;
    s32 sp60;
    s32 j;
    s32 s0;
    s32 s1;
    s32 sp50;
    s32 s2;
    s32 sp48;
    s32 t;

    n = _gccubesearch_entrypoint_9(0x40A, sp70, 8);
    for (s2 = 0; s2 < n; s2++) {
        ((DrillEnt *) B_80800A10_chfantasydrillfield)[s2].key = ((u32 *) sp70[s2])[4] >> 21;
        ((DrillEnt *) B_80800A10_chfantasydrillfield)[s2].val = -1;
    }
    if (n > 0) {
        s2 = 0;
        do {
            for (j = 0; j < n; j++) {
                if (((DrillEnt *) B_80800A10_chfantasydrillfield)[s2].key < ((DrillEnt *) B_80800A10_chfantasydrillfield)[j].key) {
                    t = ((DrillEnt *) B_80800A10_chfantasydrillfield)[j].key;
                    ((DrillEnt *) B_80800A10_chfantasydrillfield)[j].key = ((DrillEnt *) B_80800A10_chfantasydrillfield)[s2].key;
                    ((DrillEnt *) B_80800A10_chfantasydrillfield)[s2].key = t;
                }
            }
            s2++;
        } while (s2 != n);
    }
    s2 = 0;
    if (func_800DA298(0x1DC) != 0) {
        sp50 = 4;
        s1 = 0;
        for (s0 = 0; s0 < sp50; s0++) {
            s1 = s1 << 1;
            s1 = func_800DA298(s0 + 0x1DD) | s1;
        }
    } else {
        sp48 = 4;
        s1 = func_800DC128(0, 0x10);
        s0 = 0;
        do {
            func_800DA3B8(s0 + 0x1DD, (s1 >> (3 - s0)) & 1);
            s0++;
        } while (s0 != sp48);
        func_800DA544(0x1DC);
    }
    sp60 = func_800DC090();
    func_800DC324(s1);
    if (func_80800360_chfantasydrillfield() == 0) {
        do {
            i = func_800DC128(0, 8);
            if (((DrillEnt *) B_80800A10_chfantasydrillfield)[i].val == -1) {
                ((DrillEnt *) B_80800A10_chfantasydrillfield)[i].val = s2;
                s2++;
            }
        } while (func_80800360_chfantasydrillfield() == 0);
    }
    func_800DC324(sp60);
}

s32 func_80800360_chfantasydrillfield(void)
{
    s32 local_0 = 1;
    s32 local_1;

    for (local_1 = 0; local_1 < 8; local_1++) {
        local_0 &= B_80800A10_chfantasydrillfield[local_1].value != -1;
    }
    return local_0;
}

s32 func_808003C8_chfantasydrillfield(s32 param_0)
{
    s32 pad;
    s32 local_0 = 0;
    s32 local_1;
    s32 local_2;

    for (local_2 = 0; local_2 < 8; local_2++) {
        if (param_0 == B_80800A10_chfantasydrillfield[local_2].unused) {
            local_0 = B_80800A10_chfantasydrillfield[local_2].value;
            B_80800A10_chfantasydrillfield[local_2].unused = 0;
            break;
        }
    }
    local_1 = 1;
    for (local_2 = 0; local_2 <= 8; local_2++) {
        local_1 &= B_80800A10_chfantasydrillfield[local_2].unused == 0;
    }
    if (local_1) {
        func_800DA524(0xA0F);
    }
    return local_0;
}

void func_8080048C_chfantasydrillfield(Actor *param_0)
{
    func_80800000_chfantasydrillfield();
    if (func_800DA298(0xA0F) == 0) {
        func_800DA544(0xA0F);
        func_808000C4_chfantasydrillfield(param_0);
    }
    *(s32 *)((char *)param_0 + 0x34) = func_808003C8_chfantasydrillfield(*(u32 *)((char *)param_0 + 0x6C) >> 0x15);
}

void func_808004E8_chfantasydrillfield(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 1:
        func_80103110(param_0, 0);
        break;
    case 2:
        if (_subaddieDll_entrypoint_6(param_0, 0xB)) {
            func_80108B04(param_0, 1);
        }
        break;
    }
}

s32 func_8080054C_chfantasydrillfield(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    Actor *local_4;
    Actor *local_3;

    switch (param_1) {
    case 0x40:
        if (_subaddieDll_entrypoint_5(param_0, param_2)) {
            func_80103110(param_0, 1);
            func_80101FDC(param_0, 2);
        }
        return 1;
    case 0x3D:
        func_800EE7F8(local_1, param_0->position);
        func_800EE7F8(local_0, param_0->position);
        local_0[1] += 200.0f;
        local_1[1] -= 200.0f;
        func_800BEF00(local_0, local_1, local_2, 0);
        switch (D_808008B0_chfantasydrillfield[param_0->actorData[7]]) {
        case 0:
            func_800FFA88(param_0->unk0);
            break;
        case 0x1F7:
            func_80106790(func_800D10D4(0x16, 2, local_1, 3, NULL));
            break;
        default:
            local_4 = func_80108528(D_808008B0_chfantasydrillfield[param_0->actorData[7]], local_1, 0, &param_0);
            if (local_4->unk6C_9 == 0x3DB) {
                local_4->rotation[1] = 20.0f;
            } else if (local_4->unk6C_9 == 0x40D) {
                local_4->unk74_7 = param_0->actorData[7];
            }
            break;
        }
        if (param_2) {
            func_800DA544(param_0->actorData[7] + 0x335);
            _chskeletonexplode_entrypoint_7(param_0, param_0->position);
            func_8010A570(param_0);
            func_8010A624(param_0);
            func_800FFA88(param_0->unk0);
        }
        return 1;
    case 0xF:
        func_800C4140(0x59919413, param_0->position, 0x04B000FA);
        func_800BBCB8(param_0->position, param_0->position, 1.0f, 6, D_80800950_chfantasydrillfield);
        func_800BBCB8(param_0->position, param_0->position, 1.0f, 3, D_80800988_chfantasydrillfield);
        return 1;
    case 0x95:
        if (func_800DA298(param_0->actorData[7] + 0x335)) {
            param_0->unk64_16 = 0;
            func_8010A570(param_0);
            func_8010A624(param_0);
            switch (D_808008B0_chfantasydrillfield[param_0->actorData[7]]) {
            case 0:
                func_800FFA88(param_0->unk0);
                break;
            case 0x1F7:
                if (func_800D0B68(0x16, 2)) {
                    func_800FFA88(param_0->unk0);
                } else {
                    func_80108B04(param_0, 0);
                }
                break;
            default:
                if (!_subaddiefind_entrypoint_5(D_808008B0_chfantasydrillfield[param_0->actorData[7]],
                     &local_3, 1, param_0->position, func_80103EAC(param_0), func_800EEB40)) {
                    func_80108B04(param_0, 0);
                }
                break;
            }
        }
        func_800DA524(0xA0F);
        return 1;
    }
    return 0;
}

int chfantasydrillfield_entrypoint_0()
{
    return (int)&D_808009C4_chfantasydrillfield;
}
