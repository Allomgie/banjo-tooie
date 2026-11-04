// State of Grunty's quiz (Tower of Tragedy): quiz block, which contestant or player buzzes in,
// the answer timer on the HUD, round and progress flags, and the cutscene calls.
#include "su/quiz.h"

extern f32 D_80801050_suquiz[][3][2];
extern f32 D_80801054_suquiz[][3][2];
extern s8 *D_80127614;
extern s32 func_800DC298(f32);
typedef struct {
    s32 ids[4];
} Broad50QuizList;
extern Broad50QuizList D_808010E0_suquiz;
extern f32 func_800D9004(void);
extern f32 D_80800F94_suquiz[][6][2];
extern f32 D_80800F74_suquiz[][2];
extern f32 D_80800F70_suquiz[];
extern int D_808010F0_suquiz[];
typedef struct {
    u8 pad_0[0x18];
    f32 buzz_delay;
    f32 elapsed;
    u8 pad_20[5];
    u8 round;
    s8 unk_26;
    s8 unk_27;
    s8 buzzed;
    s8 last_buzzed;
} QuizState;
typedef struct {
    f32 unk_0;
    f32 unk_4;
} QPair;
typedef struct {
    QPair p[6];
} QRow;
extern QRow D_80800F90_suquiz[];
extern s32 func_800D3948();
extern f32 func_800DC0C0();
extern f32 func_800DC178(f32, f32);
typedef struct {
    s32 unk_0;
    f32 unk_4;
    s32 unk_8;
} QuizPackedColor27;
extern QuizPackedColor27 D_808010FC_suquiz[][4];
int suquiz_entrypoint_10();
int suquiz_entrypoint_11();
void suquiz_entrypoint_21();
void suquiz_entrypoint_28();

s32 func_80800000_suquiz(u32 contestant)
{
    u8 result;

    switch (contestant) {
        case 0:
        case 1:
            if (suquiz_entrypoint_4() == 0) {
                result = (D_80127614 + contestant)[0x31];
            } else {
                result = 2;
            }
            return result;
        case 3:
        case 4:
        case 5:
        case 6:
            return 1;
        default:
            return 0;
    }
}

f32 func_80800074_suquiz(s32 contestant, s32 round, s32 kind)
{
    return D_80801050_suquiz[round][kind][0];
}

f32 func_8080009C_suquiz(s32 contestant, s32 round, s32 kind)
{
    return D_80801054_suquiz[round][kind][0];
}

int func_808000C4_suquiz(s32 player)
{
    // Matching: needed for the match.
    s8 _sfpad[16];
    s32 arr[2];
    func_80015E80(player, &arr[0]);
    return arr[1] == 1;
}

void suquiz_entrypoint_0(void)
{
    func_800DA544(0x6B6);
    if (!D_80127614)
        D_80127614 = (u8 *) heap_alloc(0x38);
    rare_memset(D_80127614, 0, 0x38);
    if (func_800D3948()) {
        suquiz_entrypoint_21(3, 0);
        suquiz_entrypoint_21(4, 1);
        suquiz_entrypoint_21(5, _gcstatusDll_entrypoint_11() < 3 ? -1 : 2);
        suquiz_entrypoint_21(6, _gcstatusDll_entrypoint_11() < 4 ? -1 : 3);
    } else {
        suquiz_entrypoint_21(0, -1);
        suquiz_entrypoint_21(1, -1);
        suquiz_entrypoint_21(2, 0);
        if (func_800DC298(0.5f))
            D_80127614[0x31] = 0;
        else
            D_80127614[0x31] = 1;
        if (!(u8) D_80127614[0x31])
            D_80127614[0x32] = 1;
        else
            D_80127614[0x32] = 0;
    }
}

// Per-frame: counts down the answer timer and picks who buzzes in.
void suquiz_entrypoint_1(void)
{
    f32 dt;
    s32 count;
    s32 start;
    s32 end;
    s32 i;
    Broad50QuizList list;
    s32 active;
    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }

    dt = func_800D9004();
    list = D_808010E0_suquiz;
    count = 0;
    if (D_80127614) {
        active = (u8) D_80127614[0x24];
        if (func_800D3948())
            active = active && (f32) _gcstatusDll_entrypoint_17() > 0.0f;
        if (active) {
            *(f32 *) (D_80127614 + 0x20) -= dt;
            if (*(f32 *) (D_80127614 + 0x20) <= 0.0f) {
                func_800C3F48(0x7FFFFE90);
                D_80127614[0x24] = 0;
            }
            func_800D2498(0x117, (s32) *(f32 *) (D_80127614 + 0x20), 0);
        }
        *(f32 *) (D_80127614 + 0x1C) += dt;
        if (D_80127614[0x28] == -1) {
            if (func_800D3948()) {
                start = 3;
                end = 6;
            } else {
                start = 0;
                end = 2;
            }
            for (i = start; i <= end; i++) {
                if (i != D_80127614[0x29] && suquiz_entrypoint_11(i) &&
                    func_808000C4_suquiz(suquiz_entrypoint_10(i))) {
                    list.ids[count++] = i;
                }
            }
            if (count)
                D_80127614[0x28] = list.ids[func_800DC128(0, count)];
            if (D_80127614[0x28] == -1 &&
                *(f32 *) (D_80127614 + 0x18) <= *(f32 *) (D_80127614 + 0x1C)) {
                D_80127614[0x28] = D_80127614[0x26];
            }
            if (func_800DB9B0() && D_80127614[0x28] != -1)
                suquiz_entrypoint_28(0, D_80127614[0x28], 0);
        }
    }
}

s32 suquiz_entrypoint_2(void)
{
    if ((s32) D_80127614) {
        func_800DA524(0x6B6);
        heap_free((s32) D_80127614);
        D_80127614 = FALSE;
    }
}

// Current quiz round from flags 0x441/0x442.
int suquiz_entrypoint_3()
{
    if (func_800DA298(0x441)) {
        return 4;
    }
    if (func_800DA298(0x6E3)) {
        func_800DA524(0x6E3);
        func_800DA524(0x6EB);
        return 5;
    }
    switch (func_800DA564(0x442, 3)) {
        case 0:
            return 0;

        case 1:
            return 1;

        case 2:
            return 2;

        case 3:
            return 3;

        case 4:
            return 6;
    }

    return 0;
}

int suquiz_entrypoint_4()
{
    switch (func_800DA564(0x442, 3)) {
        case 2:
            return 1;

        case 3:
            return 2;

        case 4:
            return 3;

        default:
            return 0;
    }
}

int suquiz_entrypoint_5()
{
    if (func_800DA298(0x6B6)) {
        // Matching: needed for the match.
        int *ptr = &((int *) &D_80127614)[0];
        return *(s8 *) (*ptr + 0x28) + 1 != 0;
    }
    // Matching: needed for the match.
    {
        return 0;
    }
}

s8 suquiz_entrypoint_6(void)
{
    if (func_800DA298(0x6B6) != 0) {
        return *(s8 *) ((char *) (u8 *) D_80127614 + 0x28);
    }
    return -1;
}

u8 suquiz_entrypoint_7(void)
{
    if (func_800DA298(0x6B6) != 0) {
        return ((u8 *) D_80127614)[0x25];
    }
    return 6U;
}

f32 suquiz_entrypoint_8(s32 param_0)
{
    return D_80800F94_suquiz[suquiz_entrypoint_4()][param_0][0];
}

s32 suquiz_entrypoint_9(s32 param_0)
{
    switch (param_0) {
        case 1:
            return func_800DA298(0x582);
        case 0:
            return func_800DA298(0x583);
    }
    return 0;
}

int suquiz_entrypoint_10(contestant)
s32 contestant;
{
    if (func_800DA298(0x6B6))
        return *(D_80127614 + contestant + 0x2A);
    return 0;
}

int suquiz_entrypoint_11(contestant)
s32 contestant;
{
    if (func_800DA298(0x6B6)) {
        return (suquiz_entrypoint_10(contestant) + 1) != 0;
    }
    return 0;
}

void suquiz_entrypoint_12(void)
{
    func_800DC298(D_80800F74_suquiz[suquiz_entrypoint_4()][0]);
}

int suquiz_entrypoint_13(int param_0)
{
    func_800EE7F8(param_0, (int) D_80127614);
}

void suquiz_entrypoint_14(s32 param_0)
{
    func_800EE7F8(param_0, (s32) D_80127614 + 0xC);
}

s8 suquiz_entrypoint_15(s32 param_0)
{
    if (func_800DA298(0x6B6) != 0) {
        return ((u8 *) D_80127614)[0x27];
    }
    return 0;
}

s32 suquiz_entrypoint_16(void)
{
    if (func_800DA298(0x6B6)) {
        return *(f32 *) ((u8 *) D_80127614 + 0x20) <= 0.0f;
    }
    return 1;
}

s32 suquiz_entrypoint_17()
{
    return func_800DA298(FLAG2_6E3_UNK);
}

// Sets the round flags 0x441/0x442.
void suquiz_entrypoint_18(u32 param_0)
{
    switch (param_0) {
        case 0:
            func_800DA524(0x441);
            func_800DA7A8(0x442, 0, 3);
            return;
        case 1:
            func_800DA524(0x441);
            func_800DA7A8(0x442, 1, 3);
            _gcfrontend_entrypoint_9(0x74);
            return;
        case 2:
            func_800DA524(0x441);
            func_800DA7A8(0x442, 2, 3);
            _gcfrontend_entrypoint_9(0x75);
            return;
        case 3:
            func_800DA524(0x441);
            func_800DA7A8(0x442, 3, 3);
            _gcfrontend_entrypoint_9(0x76);
            return;
        case 4:
            func_800DA544(0x441);
            func_800DA7A8(0x442, 4, 3);
            _gcfrontend_entrypoint_9(0x84);
    }
}

// Picks who buzzes in this round and after what delay.
void suquiz_entrypoint_19(s32 round)
{
    s32 i;
    s32 end;
    s32 start;
    s32 multi;
    s32 kind;
    s32 unused1;
    s32 unused2;
    f32 chance;
    f32 roll;
    f32 delay;

    switch (round) {
        case 0:
        case 2:
            ((QuizState *) D_80127614)->unk_26 = -1;
            ((QuizState *) D_80127614)->buzzed = -1;
            ((QuizState *) D_80127614)->last_buzzed = -1;
            break;
        case 1:
            ((QuizState *) D_80127614)->unk_26 = -1;
            break;
        case 4:
            ((QuizState *) D_80127614)->last_buzzed = ((QuizState *) D_80127614)->buzzed;
            ((QuizState *) D_80127614)->unk_26 = -1;
            ((QuizState *) D_80127614)->buzzed = -1;
            break;
        case 5:
            break;
    }
    switch (round) {
        case 0:
        case 1:
        case 2:
        case 4:
            multi = func_800D3948();
            end = 2;
            if (multi != 0) {
                start = 3;
                end = 6;
            } else {
                start = 0;
            }
            for (i = start; i <= end; i++) {
                if (i != ((QuizState *) D_80127614)->last_buzzed && suquiz_entrypoint_9(i) == 0 &&
                    suquiz_entrypoint_11(i) == 0) {
                    kind = func_80800000_suquiz(i);
                    delay = func_80800074_suquiz(i, round, kind);
                    if (func_800DC0C0() <= delay) {
                        end = suquiz_entrypoint_4();
                        delay = func_800DC178(D_80800F90_suquiz[end].p[round].unk_0,
                                            D_80800F90_suquiz[suquiz_entrypoint_4()].p[round].unk_4 -
                                                0.4f);
                        chance = func_8080009C_suquiz(i, round, kind);
                        roll = func_800DC0C0();
                        ((QuizState *) D_80127614)->unk_26 = i;
                        ((QuizState *) D_80127614)->buzz_delay = delay;
                        ((QuizState *) D_80127614)->unk_27 = roll <= chance;
                        break;
                    }
                }
            }

            break;
    }
    ((QuizState *) D_80127614)->elapsed = 0.0f;
    ((QuizState *) D_80127614)->round = round;
}

void suquiz_entrypoint_20(s32 param_0)
{
    if (param_0 != 0) {
        if (param_0 == 1) {
            func_800DA544(0x582);
        }
    } else {
        func_800DA544(0x583);
    }
}

void suquiz_entrypoint_21(contestant, value) s32 contestant;
unsigned long value;
{
    *(s8 *) ((s8 *) (D_80127614 + contestant) + 0x2A) = value;
}

int suquiz_entrypoint_22(s32 param_0, s32 param_1)
{
    func_800EE7F8((int) D_80127614, param_0);
    func_800EE7F8((int) D_80127614 + 0xC, param_1);
}

// Starts the answer timer.
void suquiz_entrypoint_23(void)
{
    if (func_800D3948() != 0) {
        *(f32 *) ((char *) (u8 *) D_80127614 + 0x20) =
            (f32) ((f32) _gcstatusDll_entrypoint_17() * 60.0f);
    } else {
        *(f32 *) ((char *) (u8 *) D_80127614 + 0x20) =
            *(f32 *) ((char *) D_80800F70_suquiz + suquiz_entrypoint_4() * 8);
    }
    *(s8 *) ((char *) (u8 *) D_80127614 + 0x24) = 1;
}

void suquiz_entrypoint_24(s32 param_0, unsigned int param_1)
{
    s32 unk_0;
    *(s16 *) ((s8 *) (s16 *) D_80127614 + 0x34) = param_1;
    func_800DA544(0x6E3);
    func_800DA524(0x6EB);
    unk_0 = param_0;
    _glcutDll_entrypoint_6(unk_0, 0x8A);
}

int suquiz_entrypoint_25()
{
    if (!func_800DA298(0x6EB)) {
        _glcutDll_entrypoint_17();
        func_800DA544(0x6EB);
    }
}

int suquiz_entrypoint_26()
{
    return *(short *) ((u32) D_80127614 + 0x34);
}

int suquiz_entrypoint_27()
{
    func_80108474(0x217, &D_808010F0_suquiz, 0);
}

void suquiz_entrypoint_28(param_0, param_1, param_2) s32 param_0;
s32 param_1;
s32 param_2;
{
    func_800C3F48(
        ((D_808010FC_suquiz[param_1][param_0].unk_0 & 0x7FF) +
         (((D_808010FC_suquiz[param_1][param_0].unk_8 >> 5) & 0x3FF) << 11)) +
        (u32) ((u16) (u32) (D_808010FC_suquiz[param_1][param_0].unk_4 * 1023.0f) << 21));
}

f32 D_80800F70_suquiz[1] = {1.8e+02f};
f32 D_80800F74_suquiz[3][2] = {0.33f, 1.8e+02f, 0.33f, 1.8e+02f, 0.0f, 0.0f};
static u32 D_80800F74_suquiz_rest[1] = {0x3EA8F5C3};
QRow D_80800F90_suquiz[4] = {3.0f,  5.0f, 2.0f,  3.0f, 2.0f,  6.0f, -1.0f, 6.0f, 2.0f,  6.0f,
                             -1.0f, 6.0f, 3.0f,  5.0f, 2.0f,  3.0f, 2.0f,  6.0f, -1.0f, 6.0f,
                             1.5f,  6.0f, -1.0f, 6.0f, 2.0f,  5.0f, 2.0f,  3.0f, 2.0f,  6.0f,
                             -1.0f, 6.0f, 1.0f,  6.0f, -1.0f, 6.0f, 2.0f,  5.0f, 2.0f,  3.0f,
                             2.0f,  6.0f, -1.0f, 6.0f, 1.0f,  6.0f, -1.0f, 6.0f};
f32 D_80801050_suquiz[6][3][2] = {0.1f, 0.9f, 0.2f, 0.9f, 0.25f, 0.9f, 0.4f, 0.8f, 0.6f,
                                  0.8f, 0.7f, 0.8f, 0.4f, 0.8f,  0.6f, 0.8f, 0.7f, 0.8f,
                                  0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  0.0f, 0.5f, 0.9f, 0.7f,
                                  0.9f, 0.8f, 0.9f, 0.0f, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f};
Broad50QuizList D_808010E0_suquiz = {-0x1, -0x1, -0x1, -0x1};
int D_808010F0_suquiz[3] = {0x0, 0x0, 0x0};
QuizPackedColor27 D_808010FC_suquiz[7][4] = {
    0x620, 1.0f, 0x7D00, 0x650, 1.0f, 0x7D00, 0x652, 1.0f, 0x7D00, 0x681, 1.0f, 0x7D00,
    0x621, 1.0f, 0x7D00, 0x64E, 1.0f, 0x7D00, 0x64F, 1.0f, 0x7D00, 0x680, 1.0f, 0x7D00,
    0x622, 1.0f, 0x7D00, 0x3EA, 1.0f, 0x7D00, 0x3EB, 1.0f, 0x7D00, 0x427, 1.0f, 0x7D00,
    0x620, 1.0f, 0x7D00, 0x5A2, 1.0f, 0x7D00, 0x5A4, 1.0f, 0x7D00, 0x50F, 1.0f, 0x7D00,
    0x621, 1.0f, 0x7D00, 0x68F, 1.0f, 0x7D00, 0x68C, 1.0f, 0x7D00, 0x683, 1.0f, 0x7D00,
    0x659, 1.0f, 0x7D00, 0x3EA, 1.0f, 0x7D00, 0x3EB, 1.0f, 0x7D00, 0x427, 1.0f, 0x7D00,
    0x622, 1.0f, 0x7D00, 0x654, 1.0f, 0x7D00, 0x655, 1.0f, 0x7D00, 0x67F, 1.0f, 0x7D00};
