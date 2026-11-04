#include "common.h"

extern int D_80801068_chhoneyb[];
extern void func_80102424();
typedef struct {
    f32 position[3];
    f32 yaw;
    f32 scale;
    s32 flags;
} HoneyBMarkerPose;
extern u8 D_808010B0_chhoneyb[];
extern void *func_80100094(Actor *, u32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void func_800FA9F4(s32, s32);
extern void func_800D2498(s32, s32, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C3FC0(s32, f32, s32);
typedef struct {
    s16 a, b;
} S16Pair;
extern s32 D_808010C0_chhoneyb[];
extern void func_8010D5DC();
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void func_8008F990(f32 *, f32);
extern s32 D_808010D0_chhoneyb[];
extern void _subaddieaudioloop_entrypoint_4();
extern s32 _glcutDll_entrypoint_20();
extern void func_800FFAB0(Actor *);
extern void func_8010DC50(s32);
extern void func_8010DCB4(s32);
extern void func_8010DD20(Actor *, s32, s32);
extern void func_800DF744(s32, s32);
extern void _subaddiefade_entrypoint_3(Actor *);
extern f32 _scinfobar_entrypoint_18(s32);
extern void func_800E253C(f32);
extern void *_suexpression_entrypoint_20();
extern void _suexpression_entrypoint_18(void *, s32);
extern void _suexpression_entrypoint_10(void *, Unk80132ED0 *, s32);
extern s32 func_801022E4(Actor *);
extern f32 func_80101F24(Actor *);
extern s32 func_80102320(Actor *, f32, f32);
void func_8080062C_chhoneyb();
void func_80800B2C_chhoneyb();
int func_80800B98_chhoneyb();
s32 func_80800BD8_chhoneyb();
s32 func_80800C0C_chhoneyb();
void func_80800680_chhoneyb();
void func_80800744_chhoneyb();

// TU-NOTE: the .data tables at the end of this file are defined in C so IDO schedules the functions that
// they point to correctly. Values are taken from the ROM.

int chhoneyb_entrypoint_0(void)
{
    extern int D_80801020_chhoneyb[];
    return (int) &D_80801020_chhoneyb;
}

int chhoneyb_entrypoint_1()
{
    return (int) &D_80801068_chhoneyb;
}

void func_80800018_chhoneyb(u8 *param_0, s32 param_1, s32 param_2)
{
    _subaddiedialog_entrypoint_11(*(s32 *) param_0, param_1, param_2, param_0 + 4, 0x9B);
    func_80102424(param_0, 2);
}

void func_80800058_chhoneyb(u8 *param_0)
{
    s32 combs_owned;
    s32 upgrade;
    *(s32 *) ((s8 *) param_0 + 0x28) = 0;
    *(s32 *) ((s8 *) param_0 + 0x2C) = 0;
    upgrade = func_80800B78_chhoneyb() + 1;
    if (_gcextra_entrypoint_1() >= upgrade) {
        do {
            combs_owned = func_80800B58_chhoneyb();
            if ((combs_owned - *(s32 *) ((s8 *) param_0 + 0x2C)) >= func_80800B98_chhoneyb(upgrade)) {
                *(s32 *) ((s8 *) param_0 + 0x28) = (s32) (*(s32 *) ((s8 *) param_0 + 0x28) + 1);
                *(s32 *) ((s8 *) param_0 + 0x2C) =
                    (s32) (func_80800B98_chhoneyb(upgrade) + *(s32 *) ((s8 *) param_0 + 0x2C));
            }
            upgrade += 1;
        } while (_gcextra_entrypoint_1() >= upgrade);
    }
    _subaddieitem_entrypoint_1((u8 *) func_80100094(param_0, 1) + 0x18,
                               *(s32 *) ((s8 *) param_0 + 0x2C));
}

int func_8080011C_chhoneyb(Actor *param_0)
{
    s32 local_0;

    func_80090708(2);
    func_80102424(param_0, 3);
    *(f32 *) ((char *) param_0 + 0x34) = 1.0f;
    *(f32 *) ((char *) param_0 + 0x58) = 0.25f;
    local_0 = func_8008FC28();
    *(s32 *) ((char *) param_0 + 0x30) = local_0;
    *(s32 *) ((char *) param_0 + 0x24) = (s32) (*(s32 *) ((char *) param_0 + 0x28) + local_0);
    *(u8 *) ((char *) param_0 + 0x74) = (u8) (*(u8 *) ((char *) param_0 + 0x74) & 0xFFBF);
    func_800FC6B0(0xA);
}

void func_80800194_chhoneyb(Actor *param_0)
{
    HoneyBMarkerPose marker;

    if (_subaddiemarker_entrypoint_0(param_0, 0x1C1, &marker, 1)) {
        func_800EE7F8(param_0->actorData, marker.position);
    }
    _subaddieitem_entrypoint_0((u8 *) func_80100094(param_0, 1) + 0x18, 0x4B7, 0x258, 3);
    func_80800058_chhoneyb(param_0);
    _susubgame_entrypoint_0(param_0, func_80100094(param_0, 1), 0);
    _susubgame_entrypoint_12(func_80100094(param_0, 1), D_808010B0_chhoneyb);
    func_800A16BC(1);
}

void func_80800240_chhoneyb(Actor *param_0)
{
    if (_suexpression_entrypoint_20(param_0)) {
        _suexpression_entrypoint_8(param_0, 0);
    }
    if (_susubgame_entrypoint_2(param_0, func_80100094(param_0, 1))) {
        _susubgame_entrypoint_4(param_0, func_80100094(param_0, 1));
    }
}

void func_808002AC_chhoneyb(Actor *param_0)
{
    f32 local_0[3];

    func_80800680_chhoneyb(param_0);
    _sudeflect_entrypoint_1(param_0->position, 400.0f, 0.0f, 80.0f, 14);
    func_80800B2C_chhoneyb(param_0);
    func_8008FBE0(param_0->unk70_10 == 1);
    switch (param_0->unk70_10) {
        case 1:
            if (!_glcutDll_entrypoint_20()) {
                func_800D1824(0x49);
                if (!param_0->actorData[4]) {
                    if (func_80800B78_chhoneyb() < _gcextra_entrypoint_1()) {
                        func_800D2498(0x107, func_80800C0C_chhoneyb(), 0);
                    }
                }
            }
            if (_subaddiedialog_entrypoint_5(param_0->position, 600, 60, 0)) {
                if (func_80800B78_chhoneyb() >= _gcextra_entrypoint_1()) {
                    _susubgame_entrypoint_5(param_0, func_80100094(param_0, 1), 3, 0, 0);
                    func_80800018_chhoneyb(param_0, 0x1521, 15);
                } else if (func_800DA298(0)) {
                    func_80800744_chhoneyb(param_0, 0x1519, 0);
                } else {
                    _susubgame_entrypoint_5(param_0, func_80100094(param_0, 1), 3, 0, 0);
                    func_80800018_chhoneyb(param_0, 0x1519, 15);
                }
            }
            break;
        case 4:
            if (param_0->unk74_29) {
                _susubgame_entrypoint_5(param_0, func_80100094(param_0, 1), 3, 0, 0);
                func_80800018_chhoneyb(param_0, 0x1518, 15);
            }
            break;
        case 5:
            func_80103DFC(param_0, local_0);
            if (_subaddieitem_entrypoint_3(param_0, local_0,
                                           (u8 *) func_80100094(param_0, 1) + 0x18)) {
                func_80800018_chhoneyb(param_0, 0x1553, 15);
            }
            break;
        case 3:
            func_800FA9F4(0, param_0->actorData[7]);
            func_800D2498(0x119, param_0->actorData[6], param_0->actorData[3]);
            if (func_800D27F4(0x119)) {
                if (*(f32 *) &param_0->actorData[7] < 1.0f) {
                    *(f32 *) &param_0->actorData[7] += func_800D8FF8() * 2;
                    if (*(f32 *) &param_0->actorData[7] > 1.0f) {
                        *(f32 *) &param_0->actorData[7] = 1.0f;
                        func_800C3FC0(0x66C,
                                      func_800F10B4((f32) (s32) param_0->actorData[6], 1.0, 10.0f,
                                                    0.8f, 1.5f),
                                      0x7D00);
                    }
                }
                if (func_800D9078(&param_0->unk58)) {
                    if ((s32) param_0->actorData[6] >= (s32) param_0->actorData[3]) {
                        func_8080062C_chhoneyb(param_0);
                        func_80090708(0);
                        func_80102424(param_0, 1);
                    } else {
                        param_0->actorData[6]++;
                        *(f32 *) &param_0->actorData[7] = 0.0f;
                        param_0->unk58 = 0.75f;
                    }
                }
            }
    }
}

void func_8080062C_chhoneyb(param_0) u8 *param_0;
{
    _gcextra_entrypoint_2(*(s32 **) (param_0 + 0x28));
    func_800A1658(func_8008FD48());
    func_80800058_chhoneyb(param_0);
    func_80101180(0x4B8, 0x23, func_80800B78_chhoneyb());
}

void func_80800680_chhoneyb(param_0) Actor *param_0;
{
    void *expression;
    s32 blink;
    f32 progress;

    expression = _suexpression_entrypoint_20();
    blink = 0;
    if (expression != NULL) {
        if (func_801022E4(param_0) == 0x4AD &&
            ((progress = func_80101F24(param_0)) < 0.12f || progress > 0.97f ||
             func_80102320(param_0, 0.55f, 0.7f))) {
            blink = 1;
        }
        if (blink) {
            _suexpression_entrypoint_18(expression, 1);
        }
        _suexpression_entrypoint_10(expression, param_0->unk0, 0);
    }
}

void func_80800744_chhoneyb(param_0, param_1, param_2) u8 *param_0;
s32 param_1;
s32 param_2;
{
    s32 next_dialog;
    s32 next_arg;
    s32 upgrades_taken;
    next_dialog = 0;
    next_arg = 0xF;
    switch (param_1) {
        case 0x1518:
            func_800DA544(0x4E9);

        case 0x1519:
            func_800DA544(0);
            // Matching: empty block steers IDO's register allocation.
            if (0) {
            }
            upgrades_taken = *(s32 *) ((s8 *) param_0 + 0x28);
            if (upgrades_taken == 0) {
                if (func_80800BD8_chhoneyb() == 1) {
                    next_dialog = 0x151F;
                } else {
                    next_dialog = 0x1520;
                }
            } else if (upgrades_taken == 1) {
                next_dialog = 0x151A;
            } else {
                next_dialog = 0x151B;
            }
            _susubgame_entrypoint_5(param_0, func_80100094(param_0, 1), 3, 1, 0);
            break;

        case 0x151A:

        case 0x151B:
            next_dialog = 0x151C;
            break;

        case 0x151C:
            if (param_2 == 1) {
                next_dialog = 0x151D;
            } else {
                next_dialog = 0x151E;
            }
            next_arg = 0x4E;
            break;

        case 0x151D:
            _subaddieitem_entrypoint_2((u8 *) func_80100094(param_0, 1) + 0x18);
            _susubgame_entrypoint_5(param_0, func_80100094(param_0, 1), 2, 1, 0);
            func_80102424(param_0, 5);
            break;

        case 0x1553:
            _susubgame_entrypoint_4(param_0, func_80100094(param_0, 1));
            func_8080011C_chhoneyb(param_0);
            break;

        default:
            _susubgame_entrypoint_4(param_0, func_80100094(param_0, 1));
            func_80102424(param_0, 1);
    }

    if (next_dialog != 0) {
        func_80800018_chhoneyb(param_0, next_dialog, next_arg);
    }
}

s32 func_80800920_chhoneyb(param_0, param_1, param_2)
u8 *param_0;
s32 param_1;
S16Pair param_2;
{

if (param_1 == 0x1520) {
    return func_80800BD8_chhoneyb(param_0);
}

if (param_1 == 0x151B) {
    return *(s32 *) (param_0 + 0x28);
}

return -1;

}

int func_80800968_chhoneyb(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x2E:
            func_80800744_chhoneyb(param_0, ((s16 *) &param_2)[0], ((s16 *) &param_2)[1]);
            break;
        case 0x30:
            return func_80800920_chhoneyb(param_0, ((s16 *) &param_2)[0], ((s16 *) &param_2)[1]);
        case 0x32:
            func_800904C8(0x8D);
            param_0->unk74_29 = 1;
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_808010C0_chhoneyb, *(s32 *) &param_0->scale);
            break;
        case 0xB:
            return 3;
        case 0x95:
            _suexpression_entrypoint_12(_suexpression_entrypoint_7(param_0, 0, 0x9B), 60.0f, 20.0f);
            if (!func_800DA298(0x4E9) && !_glcutDll_entrypoint_20()) {
                func_8008F8B0();
                func_8008F904(func_8010D5DC, param_0->unk0);
                func_8008F8D8(1);
                func_8008F990((f32 *) param_0->actorData, 300.0f);
                _susubgame_entrypoint_6(param_0, func_80100094(param_0, 1), 1, 0x60, 0);
                func_80102424(param_0, 4);
            }
            break;
        case 0x57:
            return _susubgame_entrypoint_3(param_0, func_80100094(param_0, 1), param_2 & 0xFFFF,
                                           (u32) (param_2 & 0xFFFF0000) >> 16);
        default:
            return 0;
    }

return 1;
}

void func_80800B2C_chhoneyb(param_0) u8 *param_0;
{
    _subaddieaudioloop_entrypoint_4(param_0, param_0 + 4, 1, &D_808010D0_chhoneyb);
}

int func_80800B58_chhoneyb()
{
    func_800D1A04(0x49);
}

int func_80800B78_chhoneyb()
{
    _gcextra_entrypoint_0();

}

int func_80800B98_chhoneyb(param_0)
s32 param_0;
{
    if ((param_0 <= 0) || (_gcextra_entrypoint_1() < param_0)) {
        return -1;
    }

return (param_0 * 2) - 1;
}

s32 func_80800BD8_chhoneyb(void)
{
    s32 local_0 = func_80800B78_chhoneyb();
    local_0 = func_80800B98_chhoneyb(local_0 + 1);
    return local_0 - func_80800B58_chhoneyb();
}

s32 func_80800C0C_chhoneyb(void)
{
    func_80800B98_chhoneyb(func_80800B78_chhoneyb() + 1);
}

void func_80800C34_chhoneyb(s32 param_0)
{
    func_8010A3E8(param_0, 0x3F333333);
}

void func_80800C58_chhoneyb()
{
    func_8010C964();

}

s32 func_80800C78_chhoneyb(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x95:
            if (func_80800B78_chhoneyb(param_0) >= (s32) param_0->unk74_7 - 0x32 ||
                _glcutDll_entrypoint_20(param_0)) {
                func_800FFAB0(param_0);
            }
            break;
        case 0x29:
            func_8010DC50(2);
            return 1;
        case 0x2A:
            func_8010DCB4(2);
            return 1;
        case 0x1F:
            func_8010DD20(param_0, 2, *(s32 *) &param_2);
            func_800DF744(3, 0);
            return 1;
        case 0x23:
            if (*(s32 *) &param_2 >= (s32) param_0->unk74_7 - 0x32) {
                _subaddiefade_entrypoint_3(param_0);
            }
            break;
        default:
            return 0;
    }

return 1;
}

// HUD info-bar renderer: draws the honeycomb health row, the newest segment sliding in.
void chhoneyb_entrypoint_2(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s32 local_0;
    s32 n;
    f32 fv;
    f32 frac;
    s32 cnt;
    s32 scale;
    int tmp;
    s32 cap;
    s32 i;
    s32 pos;
    s32 sp70[2];
    s32 prev;
    s32 alpha;

    local_0 = func_800D674C(0xB4D);
    n = _scinfobar_entrypoint_11(param_1);
    fv = _scinfobar_entrypoint_18(param_1);
    tmp = _scinfobar_entrypoint_14(param_1);
    frac = *(f32 *) &tmp;
    tmp = _scinfobar_entrypoint_19(param_1);
    cnt = _scinfobar_entrypoint_20(param_1);
    // Matching: the `cnt * 0` is needed for the match.
    cap = (s32) (((f32) (cnt * 0 + 0x28)) * fv);

if (n < cap) {
    scale = (s32) ((1.0f - (f32) (cap - n) / (f32) cap) * 256.0f);
} else {

scale = 0x100;

}
alpha = 0xFF;
i = cnt - 1;
if (i >= 0) {
    do {
        pos = (s32) ((f32) (i * 0x14 + 0x28) * fv);
        if (i < tmp) {
            if (tmp == i + 1 && frac < 1.0f) {
                i--;
                prev = (s32) ((f32) (i * 0x14 + 0x28) * fv);
                i++;
                pos = (s32) (prev + frac * (pos - prev));
            }
            if (n < pos) {
                pos = n;
            }
            func_800E257C((alpha * scale) >> 8);
            func_800E253C(fv);
            sp70[0] = (param_2 + pos) * 4;
            sp70[1] = param_3 * 4;
            func_800E30E0(param_0, local_0, 0, sp70);
        }
        i--;
    } while (i >= 0);

}
}

extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
extern void func_801018A4();
u32 D_80800FF0_chhoneyb[12] = {0x0,        0x0,       0x40D570A4, 0x4AD0000, 0x40D570A4, 0x4AD0000,
                               0x40D570A4, 0x4AD0000, 0x40D570A4, 0x4AD0000, 0x40D570A4, 0x4AD0000};
int D_80801020_chhoneyb[18] = {0x15804B0,
                               0x9180001,
                               (u32) &D_80800FF0_chhoneyb,
                               (u32) func_808002AC_chhoneyb,
                               (u32) func_80102EC0,
                               (u32) func_80101870,
                               0x0,
                               0x3FB33333,
                               0x0,
                               0x120,
                               (u32) func_80800240_chhoneyb,
                               0x0,
                               0x2C,
                               (u32) func_80800194_chhoneyb,
                               (u32) func_80107C2C,
                               -0x7FFFDBFE,
                               (u32) func_80800968_chhoneyb,
                               0x0};
int D_80801068_chhoneyb[18] = {0x15804B8,
                               0x7050001,
                               0x0,
                               (u32) func_80800C58_chhoneyb,
                               (u32) func_80102EC0,
                               (u32) func_801018A4,
                               0x0,
                               0x3FCCCCCD,
                               0x0,
                               0x800000,
                               0x0,
                               0x0,
                               0x0,
                               (u32) func_80800C34_chhoneyb,
                               (u32) func_80107C2C,
                               -0x7FFFDB7E,
                               (u32) func_80800C78_chhoneyb,
                               0x0};
u8 D_808010B0_chhoneyb[16] = {0x43, 0xE1, 0x0, 0x0, 0x43, 0x7A, 0x0, 0x0,
                              0x43, 0x48, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0};
s32 D_808010C0_chhoneyb[4] = {0x43E10000, 0x437A0000, 0x43480000, 0x43480000};
s32 D_808010D0_chhoneyb[8] = {0x13049B, 0x161388, 0xE00E6, 0x1190180, 0x0, 0x0, 0x0, 0x0};
