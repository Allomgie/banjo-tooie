#include "common.h"

extern int D_8080092C_chstarspinnerctrl[];
extern int D_80800974_chstarspinnerctrl[];
extern s32 D_80800900_chstarspinnerctrl[];
extern s32 D_8080090C_chstarspinnerctrl[3];
extern s32 D_80800918_chstarspinnerctrl[];
extern void *func_80100094(Actor *, u32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800F3214(s32 *, s32 *, s32 *, f32);
extern s32 _chpowerhut_entrypoint_4(Actor *, f32, void *);
extern u8 _chstarspinnerctrl_entrypoint_2[];
extern Actor *func_80106790();
extern void func_800F2FD0(u8 *, u8 *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern s32 D_808009BC_chstarspinnerctrl[];
extern void func_801015D0(void);
extern int D_80800A50_chstarspinnerctrl[];
extern int D_80800A00_chstarspinnerctrl[];
extern int D_80800A98_chstarspinnerctrl[];
extern int D_80800AA8_chstarspinnerctrl[];
extern int D_808008E0_chstarspinnerctrl[];
typedef struct {
    u8 pad_0[0x14];
    f32 blend;
} StarSpinnerColor1506;
extern void func_800F2E60(s32 *, s32 *);
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern Actor *_subaddiefind_entrypoint_3(s32, s32 *);
extern void _subaddiefade_entrypoint_11(Actor *, s32 *);
extern s32 D_808008E8_chstarspinnerctrl[];
extern s32 D_808008F4_chstarspinnerctrl[];
void func_808002B4_chstarspinnerctrl();
void func_80800554_chstarspinnerctrl();
// Apply the current light colour to all star actors (0x336).
void func_8080069C_chstarspinnerctrl();

int chstarspinnerctrl_entrypoint_0()
{
    return (int) &D_8080092C_chstarspinnerctrl;
}

int chstarspinnerctrl_entrypoint_1()
{
    return (int) &D_80800974_chstarspinnerctrl;
}

void func_80800018_chstarspinnerctrl(s32 actor)
{
    _chpowerhut_entrypoint_0(actor, (s32 *) D_80800918_chstarspinnerctrl);
}

// Controller update: swaps map-model layers and fades lighting while the spell is active.
void func_8080003C_chstarspinnerctrl(Actor *actor)
{
    s32 color[3];

    _chpowerhut_entrypoint_1(actor, D_80800918_chstarspinnerctrl);
    switch (actor->unk70_10) {
        case 1:
            break;
        case 3:
            if (*(s16 *) ((u8 *) func_80100094(actor, 0) + 0xC) == 2) {
                func_800BF744(2, 0);
                func_800BF744(1, 1);
            }
            if (*(s16 *) ((u8 *) func_80100094(actor, 0) + 0xC) == 3) {
                *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x18) = func_800F10B4(
                    *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x14), 0.0f, 1.0f, 0.3f, 1.0f);
                func_800F3214(color, D_80800900_chstarspinnerctrl, D_8080090C_chstarspinnerctrl,
                              *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x18));
                func_800C8F08(color, 0);
                func_808002B4_chstarspinnerctrl(actor);
            }
            if (_chpowerhut_entrypoint_4(actor, 10.75f, D_80800918_chstarspinnerctrl))
                func_800DA544(0);
    }
    func_8080069C_chstarspinnerctrl(actor);
}

s32 func_80800184_chstarspinnerctrl(Actor *actor, s32 msg, s32 arg)
{
    s32 powered;

    if (msg == 0x95) {
        powered = func_800DA298(0xEA) != 0 || _glcutDll_entrypoint_20() != 0;
        func_800BF744(2, !powered);
        func_800BF744(1, powered);
        *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x18) = func_800F10B4(
            *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x14), 0.0f, 1.0f, 0.3f, 1.0f);
        if (!powered) {
            func_808002B4_chstarspinnerctrl(actor);
            func_800C8F08(D_80800900_chstarspinnerctrl, 0);
        } else {
            func_800DA544(0);
        }
        _chpowerhut_entrypoint_3(actor, msg, arg, D_80800918_chstarspinnerctrl);
        func_80103110(actor, 1);
        return 1;
    }
    return _chpowerhut_entrypoint_3(actor, msg, arg, D_80800918_chstarspinnerctrl);
}

void func_808002B4_chstarspinnerctrl(actor) s32 *actor;
{
    _glid_entrypoint_0(func_800BEA88(0), 1, &_chstarspinnerctrl_entrypoint_2, *actor);
}

void chstarspinnerctrl_entrypoint_2(void *unk_0, Vtx *param_1, Vtx *param_2, s32 param_3,
                                    Unk80132ED0 *param_4)
{
    f32 blend;
    blend = *(f32 *) ((u8 *) func_80100094(func_80106790(param_4), 0) + 0x18);

while (param_3 > 0) {
    func_800F2FD0(param_2->v.cn, param_1->v.cn, blend);
    param_3--;
    param_1++;
    param_2++;
}

}

// Egg target hit effect (flag 0x679 set: stars move slower).
void func_80800374_chstarspinnerctrl(u8 *actor)
{
    if (func_800DA298(0x679) != 0) {
        func_8010A570(actor);
        actor[0x65] = 0x10 | (actor[0x65] & 0xFF);
    }

}

void func_808003B8_chstarspinnerctrl(Actor *actor)
{
    f32 pos[3];

if (actor->unk64_20 && !func_8001210C(3)) {
    func_800EE7F8(pos, actor->position);
    func_800EF1B8(pos, actor->rotation[1], 40.0f);
    pos[1] += 30.0f;
    func_800BBCB8(pos, pos, 0.8f, 1, D_808009BC_chstarspinnerctrl);
}

}

void func_8080044C_chstarspinnerctrl(Actor *actor, void *param_1)
{
    func_800DF744(1, actor->unk64_20 ? 0 : 1);
    func_800DF744(2, actor->unk64_20 ? 1 : 0);
    func_80101808(actor, func_801015D0);

}

// Message 0x40: egg target hit; sets flag 0x679, particles, shake, dialog 0x10F4.
int func_808004CC_chstarspinnerctrl(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x40:
            func_8010A570(actor);
            actor->unk64_20 = 1;
            func_800DA544(0x679);
            func_80800554_chstarspinnerctrl(actor);
            func_800FC660(14);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x10F4, 4, actor->position, 0x22);
            break;
        default:
            return 0;
    }

return 1;
}

void func_80800554_chstarspinnerctrl(actor) s32 actor;
{
    func_800BBCB8(actor + 4, 0, 1.0f, 8, &D_80800A50_chstarspinnerctrl);
    func_800BBCB8(actor + 4, 0, 1.0f, 0xC, &D_80800A00_chstarspinnerctrl);
    func_800C4AF0(actor + 4, &D_80800A98_chstarspinnerctrl);
    func_800C4AF0(actor + 4, &D_80800AA8_chstarspinnerctrl);
    func_800E1610(0, 0x41200000, 0x3F666666, actor + 4);
    func_80018820(0, 0x40000000, 0x3E800000);
}

int chstarspinnerctrl_entrypoint_3(s32 unk_0, s32 arg)
{
    s32 handle;

if (!func_800DA298(0xEA) && !_glcutDll_entrypoint_20()) {
    return 0;
}

handle = func_800C8A98();
func_800C8D4C(handle, &D_808008E0_chstarspinnerctrl);
func_800C8E84(handle, &D_808008F4_chstarspinnerctrl);
func_800C8CB8(handle, arg);
func_800C8F64(handle, 9);
return handle;
}

// Apply the current light colour to all star actors (0x336).
void func_8080069C_chstarspinnerctrl(actor) Actor *actor;
{
    Actor *star;
    s32 iter;
    s32 color[3];
    f32 blend;

switch (actor->unk70_10) {
    case 1:
    case 2:
        func_800F2E60(color, &D_808008E8_chstarspinnerctrl);
        break;
    case 3:
        blend = ((StarSpinnerColor1506 *) func_80100094(actor, 0))->blend;
        func_800F3214(color, &D_808008E8_chstarspinnerctrl, &D_808008F4_chstarspinnerctrl,
                      blend);
        break;
    case 4:
    case 5:
        func_800F2E60(color, &D_808008F4_chstarspinnerctrl);
}

star = _subaddiefind_entrypoint_2(0x336, &iter);

while (star) {
    _subaddiefade_entrypoint_11(star, color);
    star = _subaddiefind_entrypoint_3(0x336, &iter);
}

}

s32 chstarspinnerctrl_entrypoint_4(Actor *actor, s32 msg, s32 arg)
{
    Actor *ctrl;
    s32 powered;

    powered = func_800DA298(0xEA) || _glcutDll_entrypoint_20();

if (!actor->unk3C) {
    return 0;
}

ctrl = func_80106790(actor->unk3C);

if (powered && !arg) {
    arg = chstarspinnerctrl_entrypoint_3(actor, msg);
    if (arg) {
        func_800C8E84(arg, &D_808008E8_chstarspinnerctrl);
    }
}

if (!arg) {
    return 0;
}

func_800C8CB8(arg, msg);

switch (ctrl->unk70_10) {
    case 1:
    case 2:
        func_800C8B84(arg);
        arg = 0;
        break;
    case 3:
        func_800C8E84(arg, &D_808008F4_chstarspinnerctrl);
        break;
    case 4:
    case 5:
        func_800C8E84(arg, &D_808008F4_chstarspinnerctrl);
}

return arg;
}

extern void func_80105834();
extern void _chpowerhut_entrypoint_2();
extern void func_80107C2C();
extern void func_80108ED0();
int D_808008E0_chstarspinnerctrl[2] = {0x43C80000, 0x44610000};
s32 D_808008E8_chstarspinnerctrl[3] = {0x40, 0x40, 0x40};
s32 D_808008F4_chstarspinnerctrl[3] = {0xFF, 0xFF, 0xFF};
s32 D_80800900_chstarspinnerctrl[3] = {0x60, 0x60, 0x60};
s32 D_8080090C_chstarspinnerctrl[3] = {0xFF, 0xFF, 0xFF};
s32 D_80800918_chstarspinnerctrl[5] = {0xEA0000, 0x1001F4, 0x41B00000, 0x40800000, 0x41500000};
int D_8080092C_chstarspinnerctrl[18] = {0x1C00337,
                                        -0xFFFF,
                                        0x0,
                                        (u32) func_8080003C_chstarspinnerctrl,
                                        (u32) func_80105834,
                                        (u32) _chpowerhut_entrypoint_2,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x1C0000,
                                        (u32) func_80800018_chstarspinnerctrl,
                                        (u32) func_80107C2C,
                                        -0x7FFFFBFE,
                                        (u32) func_80800184_chstarspinnerctrl,
                                        0x0};
int D_80800974_chstarspinnerctrl[18] = {0x29F0338,
                                        0x77A0001,
                                        0x0,
                                        (u32) func_808003B8_chstarspinnerctrl,
                                        (u32) func_80105834,
                                        (u32) func_8080044C_chstarspinnerctrl,
                                        0x7D00000,
                                        0x0,
                                        0x0,
                                        0xC00,
                                        0x0,
                                        (u32) func_80108ED0,
                                        0x0,
                                        (u32) func_80800374_chstarspinnerctrl,
                                        (u32) func_80107C2C,
                                        -0x7FFFBC00,
                                        (u32) func_808004CC_chstarspinnerctrl,
                                        0x0};
s32 D_808009BC_chstarspinnerctrl[17] = {
    0x1D09DC, 0x190003, 0xB002C,   0x91,      0x0,      0xB90000, 0x20FFFF,  -0xE4FFD9, -0x6A0050,
    0x38,     0x2200EE, 0x13A037A, 0x38F0015, 0x3A00C2, 0x2B0238, 0x2990016, 0x2000000};
int D_80800A00_chstarspinnerctrl[20] = {0x1D09E2, 0x1BFDA9, -0x1A0FFD2, 0x12C0000, 0x1AD0028,
                                        0x2D027D, 0xAFFF4,  0x2B0000,   0x10005A,  0x1F,
                                        -0xA000,  0x16118A, 0x220019,   0x19000C,  0xC0015,
                                        0xCC,     0x2B0119, 0x14C0004,  0x660007,  0x40000};
int D_80800A50_chstarspinnerctrl[18] = {
    0x1D09DD,    0x2E0000, 0x96,     0x2D,     0xFA000A, 0xFFF1,   0x0,      0xF0000,  0x20C0C0,
    -0x3F3FFFEA, 0x80022,  0x9900B3, 0xD900E6, 0x150000, 0x99001E, 0x4F004F, 0x2B0133, 0x1990000};
int D_80800A98_chstarspinnerctrl[4] = {0x130413, 0xA014C, 0x104E2, 0x9C40000};
int D_80800AA8_chstarspinnerctrl[6] = {0x13048D, 0xA00CC, 0x104E2, 0x9C40000, 0x0, 0x0};
