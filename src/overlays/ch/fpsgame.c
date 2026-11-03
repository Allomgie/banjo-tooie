#include "common.h"
#include "overlays/ba/playerstate.h"
typedef struct {
    s32 local_0;
    u8 pad_0[0x10];
    u8 local_1[1];
} FpsGamePlayers;

extern int D_808021A0_chfpsgame[];
extern unsigned int func_80016BBC(s32, u16);
extern void *func_80100094(Actor *, u32);
extern PlayerState *func_800F53D0(s32);
extern void _sumultiscore_entrypoint_11(void *, s32, s32, f32);
extern f32 func_800D8FF8(void);
typedef struct {
    s32 a;
    f32 b;
} FpsE;
extern s32 func_800F1574(f32 *, f32);
typedef struct {
    u8 pad_0[0x558];
    u8 local_0;
    u8 local_1;
    u8 local_2;
    u8 local_3;
    u8 pad_1[4];
    f32 local_4;
} FpsClock1590;
extern void _fxdialog_entrypoint_1(s32, s32);
extern void _fxdialog_entrypoint_2(f32);
extern void _fxdialog_entrypoint_4(void *, s32, s32, f32, f32, s32, s32);
extern void func_800B8C50(void);
extern void func_800B8C8C(s32);
extern void func_800B8C98(s32);
extern void func_800B8CBC(s32, s32, s32);
extern void func_800B7F14(void *);
extern void func_800B8E28();
extern void func_800B811C(void *);
typedef struct {
    s32 x;
    s32 y;
} FPSPushItem1274_80801C9C_chfpsgame;
typedef struct {
    s32 count;
    FPSPushItem1274_80801C9C_chfpsgame it[10];
} FpsList;
extern s32 func_8010114C(s32, s32, s32);
typedef struct {
    s32 local_0;
    s32 local_1;
} FPSPushItem1274_80801D40_chfpsgame;
typedef struct {
    s32 local_0;
    FPSPushItem1274_80801D40_chfpsgame local_1[10];
} FPSPushList1274;
typedef struct {
    Unk80132ED0 *local_0;
    u32 local_1;
} FpsTimedActor;
typedef struct {
    s32 local_0;
    FpsTimedActor local_1[10];
} FpsTimedActorList;
extern u32 func_8001211C(void);
typedef struct {
    s32 local_0;
    s32 local_1;
} FPSPushItem1274_80802020_chfpsgame;
typedef struct {
    s32 local_0;
    FPSPushItem1274_80802020_chfpsgame local_1[10];
} FpsItemList;
typedef struct {
    u8 pad_0[0x568];
    FpsItemList local_0[4];
} FpsItemLists;
typedef struct {
    u8 pad0[6];
    u16 unk6_7 : 9;
    u16 unk6_0 : 7;
    u8 pad8[4];
    u32 unkC_23 : 9;
    u32 unkC_0 : 23;
} FpsCube;
extern s32 _gccubesearch_entrypoint_9(s32, FpsCube **, s32);
extern s32 func_800EA05C(void);
extern s32 _gcstatusDll_entrypoint_19(void);
extern s32 _bsfirstp_entrypoint_3(s32, s32, s32);
extern Actor *func_801085CC(s32, FpsCube *, u32);
extern Actor *func_80106790(s32);
typedef union {
    s32 word;
    s16 halves[2];
} FpsEvent88;
extern void func_800F7C0C(s32, s32, f32);
typedef struct {
    s32 count;
    u8 pad4[0x10];
    u8 score[0x53C];
    s32 state;
    f32 timer;
} FpsGameCtrl;
extern void func_8010A828(Actor *, s32);
extern s32 func_800F54E4(void);
extern s32 func_800F5410(s32);
extern void func_800FDC28(s32);
extern void func_80101238(s32, s32);
extern void func_800FC6B0(s32);
extern s32 _sumultiscore_entrypoint_8(void *, s32, s32);
extern void _sumultiscore_entrypoint_4(void *, s32, s32, s32);
extern s32 _gcstatusDll_entrypoint_11(void);
extern void _sumultiscore_entrypoint_9(void *, s32, s32, s32);
extern void _sumultiscore_entrypoint_10(void *, s32);
extern void func_800AA20C(s32, s32);
extern void _gcfrontend_entrypoint_10(void);
typedef struct {
    s32 unk530;
    f32 unk534;
} FpsPlayerSlot;
typedef struct {
    u8 pad0[0x530];
    FpsPlayerSlot slot[4];
} FpsGameLocal;
extern s32 func_800A4C68(void *);
extern void func_800C968C(s32, s32);
extern void _bainvisible_entrypoint_8(void *, s32, f32, f32);
extern void func_800A38F0(void *, s32, s32);
extern void func_800F44DC(void *, s32);
extern void func_80093370(void *, s32);
extern s32 _sudeathmatch_entrypoint_0(s32, f32 *, f32 *);
extern void func_800F832C(s32, f32 *);
extern void func_800F8294(s32, f32 *);
extern s32 func_800A1760(void *);
extern void func_800A1870(void *, s32);
extern void _bainvisible_entrypoint_3(void *);
extern void func_8009337C(void *, s32);
extern void func_800F7F98(s32, s32);
typedef struct {
    u8 pad_0[0x55A];
    u8 local_0;
    u8 local_1;
    f32 local_2;
    f32 local_3;
} FpsTimer61;
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct {
    s32 id;
    s32 w;
} FpsEl;
typedef struct {
    s32 count;
    FpsEl el[10];
} FpsEntry;
typedef struct {
    s32 n;
    u8 pad[0x564];
    FpsEntry e[1];
} FpsBase;
void func_808015EC_chfpsgame();
s32 func_80801758_chfpsgame();
void func_80801B30_chfpsgame();
void func_80801F34_chfpsgame();
void func_80800CF8_chfpsgame();
void func_80800FF4_chfpsgame();
void func_808013DC_chfpsgame();
void func_80801814_chfpsgame();
void func_808018E0_chfpsgame();
void func_80801DF0_chfpsgame();

void func_808003D0_chfpsgame(Actor *param_0, s32 param_1);
void func_808004E0_chfpsgame(Actor *param_0);
void func_808005B0_chfpsgame(Actor *param_0);
void func_808006A8_chfpsgame(Actor *param_0);
void func_8080075C_chfpsgame(Actor *param_0);
void func_80800BCC_chfpsgame(Actor *param_0, s32 param_1, s32 param_2);
int func_8080121C_chfpsgame(s32 param_0);
s32 func_808012CC_chfpsgame(Actor *param_0);
void func_8080135C_chfpsgame(s32 param_0);
void func_808018B0_chfpsgame(s32 param_0);
int func_80801A8C_chfpsgame(Actor *param_0, f32 param_1);
s32 func_80801ADC_chfpsgame();
void func_80801C5C_chfpsgame(s32 param_0);
void func_80801C9C_chfpsgame(Actor *param_0);
void func_80801D40_chfpsgame(Actor *param_0, s32 param_1, s32 param_2);
void func_80802020_chfpsgame(Actor *param_0, s32 param_1, s32 param_2);

int *chfpsgame_entrypoint_0()
{
    return &D_808021A0_chfpsgame;
}

int func_8080000C_chfpsgame(s32 param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    local_0 = func_80100094(param_0, 0);
    if (param_2 != 0) {
        *(s32 *) ((char *) local_0 + 0x4) |= 1 << param_1;
    } else {
        *(s32 *) ((char *) local_0 + 0x4) &= ~(1 << param_1);
    }
}

int func_80800074_chfpsgame(s32 param_0, s32 param_1)
{
    Actor *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    if (*(s32 *) ((char *) local_0 + 0x4) & 1 << param_1) {
        local_1 = 1;
    } else {
        local_1 = 0;
    }
    return local_1;
}

int func_808000BC_chfpsgame(u32 param_0)
{
    s32 local_0;
    s32 local_1;
    local_1 = 0;
    for (local_0 = 0; local_0 < _gcstatusDll_entrypoint_11(); local_0++) {
        local_1 |= func_80016BBC(local_0, (u16) param_0);
    }
    return local_1 ? 1 : 0;
}

void func_80800138_chfpsgame(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    local_1 = param_0;
    for (local_0 = 0; local_0 < func_800F5898(); local_0++) {
        if (func_800F6BE4(local_0)) {
            func_800F7F98(local_0, local_1);
        }
    }
}

void func_8080019C_chfpsgame(s32 **param_0)
{
    s32 local_2;
    Actor *local_1;
    FpsCube *local_0[28];
    s32 local_3;
    s32 local_4;
    s32 local_5;
    Actor *local_7;
    s32 i;
    s32 local_6;

    local_1 = (Actor *) *param_0;
    local_2 = *(s32 *) local_1;
    local_3 = _gccubesearch_entrypoint_9(0x2BA, local_0, 28);
    local_4 = func_800EA05C();
    local_5 = _gcstatusDll_entrypoint_19();
    for (i = 0; i < local_3; i++) {
        switch (_bsfirstp_entrypoint_3(local_4, local_5, local_0[i]->unk6_7 - 0x32)) {
            case 0:
                local_6 = 0;
                break;
            case 1:
                local_6 = 0x1C8;
                break;
            case 2:
                local_6 = 0x1C9;
                break;
            case 3:
                local_6 = 0x1CA;
                break;
            case 4:
                local_6 = 0x1CB;
                break;
            case 5:
                local_6 = 0x1CC;
                break;
            case 6:
                local_6 = 0x2B8;
                break;
            case 7:
                local_6 = 0x1CD;
        }
        if (local_6 != 0) {
            local_7 = func_801085CC(local_6, local_0[i], local_0[i]->unkC_23);
            local_7->unk74_7 = 0x33;
            local_1 = func_80106790(local_2);
        }
    }
    *param_0 = (s32 *) local_1;
}

void func_808002FC_chfpsgame(Actor *param_0)
{
    s32 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = _gcstatusDll_entrypoint_14();
    local_0[1] = 0;
    func_80800CF8_chfpsgame(param_0, 0);
    func_80801C5C_chfpsgame(param_0);
    local_0[0] = _gcstatusDll_entrypoint_11();
    switch (local_1) {
        case 1:
        case 4:
            func_808003D0_chfpsgame(param_0, local_1);
            break;
        case 3:
            func_808004E0_chfpsgame(param_0);
            break;
        case 2:
            func_808005B0_chfpsgame(param_0);
            break;
        case 6:
            func_808006A8_chfpsgame(param_0);
            break;
        case 5:
            func_8080075C_chfpsgame(param_0);
            break;
    }
}

void func_808003D0_chfpsgame(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    PlayerState *local_3;
    s32 local_4;
    u8 *local_5;

    local_0 = func_80100094(param_0, 0);
    local_5 = local_0 + 0x14;
    local_1 = _gcstatusDll_entrypoint_19();
    for (local_2 = 0; local_2 < *(s32 *) local_0; local_2++) {
        local_3 = func_800F53D0(local_2);
        local_4 = _gcstatusDll_entrypoint_13(local_2);
        _bsfirstp_entrypoint_4(local_3, local_1);
        _bsfirstp_entrypoint_5(local_3, 1, local_4);
    }
    _sumultiscore_entrypoint_3(local_5);
    _sumultiscore_entrypoint_4(local_5, 1, 0, 1);
    _sumultiscore_entrypoint_4(local_5, 2, 1, 1);
    _sumultiscore_entrypoint_4(local_5, 3, 2, 1);
    _sumultiscore_entrypoint_4(local_5, 4, 3, 0);
}

void func_808004E0_chfpsgame(Actor *param_0)
{
    s32 local_3;
    void *local_4;
    s32 local_2;
    void *local_1;
    FpsGamePlayers *local_0;

    local_0 = func_80100094(param_0, 0);
    local_4 = local_0->local_1;
    for (local_3 = 0; local_3 < local_0->local_0; local_3++) {
        local_1 = func_800F53D0(local_3);
        local_2 = _gcstatusDll_entrypoint_13(local_3);
        _bsfirstp_entrypoint_4(local_1, 0);
        _bsfirstp_entrypoint_5(local_1, 3, local_2);
    }
    _sumultiscore_entrypoint_3(local_4);
    _sumultiscore_entrypoint_4(local_4, 2, 0, 1);
    _sumultiscore_entrypoint_4(local_4, 3, 2, 1);
}

void func_808005B0_chfpsgame(Actor *param_0)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_3;
    PlayerState *local_4;
    s32 local_5;

    local_0 = func_80100094(param_0, 0);
    local_1 = local_0 + 0x14;
    local_2 = _gcstatusDll_entrypoint_19();
    for (local_3 = 0; local_3 < *(s32 *) local_0; local_3++) {
        local_4 = func_800F53D0(local_3);
        local_5 = _gcstatusDll_entrypoint_13(local_3);
        _bsfirstp_entrypoint_4(local_4, local_2);
        _bsfirstp_entrypoint_5(local_4, 2, local_5);
    }
    _sumultiscore_entrypoint_3(local_1);
    _sumultiscore_entrypoint_4(local_1, 2, 0, 1);
    _sumultiscore_entrypoint_4(local_1, 3, 2, 1);
    _sumultiscore_entrypoint_4(local_1, 4, 3, 0);
}

void func_808006A8_chfpsgame(Actor *param_0)
{
    s32 local_3;
    u8 *local_0;
    PlayerState *local_2;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    local_0 = local_1 + 0x14;
    for (local_3 = 0; local_3 < *(s32 *) local_1; local_3++) {
        local_2 = func_800F53D0(local_3);
        func_800A18C8(local_2, 1);
        func_800A1870(local_2, 1);
        _badeathmatch_entrypoint_11(local_2, 1, 1);
    }
    _sumultiscore_entrypoint_3(local_0);
    _sumultiscore_entrypoint_4(local_0, 2, 0, 1);
}

void func_8080075C_chfpsgame(Actor *param_0)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_3;
    void *local_4;
    u8 *local_5;
    local_0 = func_80100094(param_0, 0);
    local_1 = local_0 + 0x14;
    local_2 = _gcstatusDll_entrypoint_15();
    switch (*(s32 *) local_0) {
        case 2:
            *(f32 *) (local_0 + 0x10) = 6.0f;
            break;
        case 3:
            *(f32 *) (local_0 + 0x10) = 4.0f;
            break;
        case 4:
            *(f32 *) (local_0 + 0x10) = 2.0f;
            break;
    }
    *(f32 *) (local_0 + 0xC) = *(f32 *) (local_0 + 0x10);
    _sumultiscore_entrypoint_3(local_1);
    _sumultiscore_entrypoint_4(local_1, 2, 0, 1);
    _sumultiscore_entrypoint_4(local_1, 3, 2, 1);
    for (local_3 = 0; local_3 < *(s32 *) local_0; local_3++) {
        local_4 = (void *) func_800F53D0(local_3);
        if (local_3 == local_2) {
            _badeathmatch_entrypoint_10(local_4, 3, 0x19, 0x19);
            _badeathmatch_entrypoint_7(local_4, 3);
        } else {
            local_5 = local_1;
            local_5 += local_3 * 0x13C;
            _badeathmatch_entrypoint_10(local_4, 1, 1, -1);
            local_5[0x86] = 0;
        }
    }
}

s32 func_808008D4_chfpsgame(s32 param_0)
{
    func_808015EC_chfpsgame(param_0);
    func_80800FF4_chfpsgame(param_0);
    func_80801758_chfpsgame(param_0);
    func_808018E0_chfpsgame(param_0);
}

void func_8080090C_chfpsgame(s32 arg0)
{
}

s32 func_80800914_chfpsgame(Actor *param_0, s32 param_1, FpsEvent88 param_2)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_5;
    s32 local_6;
    s32 local_3;
    s32 pad;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x49:
            func_8080019C_chfpsgame(&param_0);
            return 1;
        case 0x70:
            local_1 = param_2.word & 0xF;
            local_2 = param_2.word >> 4;
            switch (_gcstatusDll_entrypoint_14()) {
                case 5:
                    if (_gcstatusDll_entrypoint_15() == local_2) {
                        func_800FC660(0x19);
                        func_80800BCC_chfpsgame(param_0, local_1, local_2);
                        *(f32 *) (local_0 + 0xC) = *(f32 *) (local_0 + 0x10);
                    } else {
                        (*(s32 *) (local_0 + 8))++;
                    }
                    break;
                case 3:
                    func_800FC660(0x19);
                    func_80800BCC_chfpsgame(param_0, local_1, local_2);
                    return 1;
                case 6:
                    func_80800BCC_chfpsgame(param_0, local_1, local_2);
                    if (func_800F5410(local_2) == 0xC) {
                        (*(s32 *) (local_0 + 8))++;
                    }
                    break;
                default:
                    func_80800BCC_chfpsgame(param_0, local_1, local_2);
                    (*(s32 *) (local_0 + 8))++;
            }
            break;
        case 0x71:
            if (_gcstatusDll_entrypoint_14() == 6) {
                func_800F7C0C(param_2.word, 0x83, 4.0f);
            } else {
                func_808013DC_chfpsgame(param_0, param_2.word, 1);
            }
            (*(s32 *) (local_0 + 8))--;
            break;
        case 0x72:
            _sumultiscore_entrypoint_5(local_0 + 0x14, param_2.word & 0xF, 3,
                                       (param_2.word >> 4) & 0xF);
            return 1;
        case 0x73:
            local_3 = param_2.word;
            local_5 = _suegg_entrypoint_7(local_3);
            func_80801D40_chfpsgame(param_0, local_5, local_3);
            return 1;
        case 0x74:
            local_4 = param_2.word;
            local_6 = _suegg_entrypoint_7(local_4);
            func_80802020_chfpsgame(param_0, local_6, local_4);
            return 1;
        case 0x75:
            _sumultiscore_entrypoint_9(local_0 + 0x14, param_2.word & 0xFFFF, 4,
                                       (param_2.word >> 16) & 0xFFFF);
            return 1;
        case 0x2E:
            if (param_2.halves[0] == 0xCEC) {
                func_80800CF8_chfpsgame(param_0, 2);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800BCC_chfpsgame(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    local_1 = _gcstatusDll_entrypoint_16(param_1);
    local_2 = 1;
    if (param_2 >= 0 && _gcstatusDll_entrypoint_16(param_2) == local_1) {
        local_2 = -1;
    }
    if (local_1 < 4) {
        _sumultiscore_entrypoint_7(local_0 + 0x14, param_1, 2, local_2);
        _sumultiscore_entrypoint_11(local_0 + 0x14, param_1, 2, 0.75f);
    } else {
        for (local_3 = 0; local_3 < *(s32 *) local_0; local_3++) {
            if (_gcstatusDll_entrypoint_16(local_3) == local_1) {
                _sumultiscore_entrypoint_7(local_0 + 0x14, local_3, 2, local_2);
                _sumultiscore_entrypoint_11(local_0 + 0x14, local_3, 2, 0.75f);
            }
        }
    }
}

void func_80800CF8_chfpsgame(this, state) Actor *this;
s32 state;
{
    FpsGameCtrl *local;
    s32 j;
    s32 i;
    s32 i3;
    s32 v;
    s32 best;

    local = func_80100094(this, 0);
    switch (state) {
        case 0:
            func_80800138_chfpsgame(1);
            break;
        case 1:
            func_8080000C_chfpsgame(this, 0, 0);
            break;
        case 2:
            func_80800138_chfpsgame(0);
            func_8010A828(this, 0x18);
            func_80801814_chfpsgame(this);
            v = func_800F5410(func_800F54E4());
            if (v == 6 || v == 0xC) {
                func_800FDC28(0xC);
            }
            break;
        case 3:
            local->timer = 2.0f;
            func_8080000C_chfpsgame(this, 0, 1);
            break;
        case 4:
            func_80800138_chfpsgame(1);
            func_8080000C_chfpsgame(this, 0, 1);
            func_808018B0_chfpsgame(this);
            func_80801C9C_chfpsgame(this);
            func_80101238(0x78, 0);
            break;
        case 5:
            for (j = 0; j < local->count; j++) {
                func_808013DC_chfpsgame(this, j, 4);
            }
            func_800FC6B0(0x16);
            v = func_800F5410(func_800F54E4());
            if (v == 6 || v == 0xC) {
                func_800FDC28(0);
            }
            break;
        case 6:
            best = _sumultiscore_entrypoint_8(local->score, 0, 2);
            if (1) {
            }
            local->timer = 5.0f;
            _sumultiscore_entrypoint_4(local->score, 5, 5, 2);
            for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
                v = _sumultiscore_entrypoint_8(local->score, i, 2);
                _sumultiscore_entrypoint_9(local->score, i, 5, v);
                if (v != best && best < v) {
                    best = v;
                }
            }
            for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
                if (_sumultiscore_entrypoint_8(local->score, i, 2) == best) {
                    _sumultiscore_entrypoint_10(local->score, i);
                }
            }
            break;
        case 7:
            for (i3 = 0; i3 < _gcstatusDll_entrypoint_11(); i3++) {
                func_800AA20C(i3, _sumultiscore_entrypoint_8(local->score, i3, 2));
            }
            _gcfrontend_entrypoint_10();
    }
    local->state = state;
}

void func_80800FF4_chfpsgame(arg0) s32 *arg0;
{
    u8 *sp34;
    s32 sp28;
    s32 var_s0;
    u8 *temp_v0;
    temp_v0 = func_80100094(arg0, 0);
    sp34 = temp_v0;
    switch (*(u32 *) ((char *) temp_v0 + 0x550)) {
        case 0:
            if (func_800C954C() == 0) {
                _subaddiedialog_entrypoint_11(*arg0, 0xCEC, 0x22, 0, 0x6F);
                func_80800CF8_chfpsgame(arg0, 1);
            }

        default:
            return;

        case 2:
            func_8080135C_chfpsgame(arg0);
            if (func_8080121C_chfpsgame(arg0) != 0) {
                func_80800CF8_chfpsgame(arg0, 4);
                return;
            }
            if (func_808012CC_chfpsgame(arg0) != 0) {
                func_80800CF8_chfpsgame(arg0, 3);
            }
            break;

        case 3:
            func_8080135C_chfpsgame(arg0);
            if (func_800F1574(sp34 + 0x554, func_800D8FF8()) != 0) {
                func_80800CF8_chfpsgame(arg0, 4);
                return;
            }
            if (func_8080121C_chfpsgame(arg0) != 0) {
                func_80800CF8_chfpsgame(arg0, 4);
            }
            break;

        case 4:
            if (*(s32 *) ((char *) temp_v0 + 8) == 0) {
                func_80800CF8_chfpsgame(arg0, 5);
            }
            break;

        case 5:
            *(s32 *) ((s8 *) &sp28 - 8) = 1;
            var_s0 = 0;
            if (*(s32 *) ((char *) temp_v0 + 0) > 0) {
            loop_15:
                if (func_800C96CC(func_800A4C68(func_800F53D0(var_s0))) == 0) {
                    *(s32 *) ((s8 *) &sp28 - 8) = 0;
                } else {
                    var_s0 += 1;
                    if (var_s0 < *(s32 *) ((char *) sp34 + 0)) {
                        goto loop_15;
                    }
                }
            }
            if (*(s32 *) ((s8 *) &sp28 - 8) != 0) {
                func_80800CF8_chfpsgame(arg0, 6);
            }

        case 6:
            if (func_800F1574(sp34 + 0x554, func_800D8FF8()) != 0) {
                func_80800CF8_chfpsgame(arg0, 7);
                return;
            }
            if ((*(f32 *) ((char *) sp34 + 0x554) < 4.5f) &&
                (func_808000BC_chfpsgame(0xD000) != 0)) {
                func_80800CF8_chfpsgame(arg0, 7);
            }
    }
}

int func_8080121C_chfpsgame(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    local_0 = func_80100094(param_0, 0);
    local_1 = _gcstatusDll_entrypoint_18();
    if (func_80801ADC_chfpsgame(param_0) != 0) {
        return 1;
    }
    if (local_1 != 0) {
        local_2 = 0;
        if (_gcstatusDll_entrypoint_11() > 0) {
            local_3 = local_0 + 0x14;
            do {
                if (_sumultiscore_entrypoint_8(local_3, local_2, 2) == local_1) {
                    return 1;
                }
                local_2 = local_2 + 1;
            } while (local_2 < _gcstatusDll_entrypoint_11());
        }
    }
    return 0;
}

s32 func_808012CC_chfpsgame(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    if (_gcstatusDll_entrypoint_14() == 3) {
        local_1 = 0;
        for (local_0 = 0; local_0 < _gcstatusDll_entrypoint_11(); local_0++) {
            local_1 += _badeathmatch_entrypoint_9(func_800F53D0(local_0), 1);
        }
        return local_1 ? 0 : 1;
    }
    return 0;
}

void func_8080135C_chfpsgame(s32 param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if ((_gcstatusDll_entrypoint_14() == 5) &&
        (func_800F1574(local_0 + 0xC, func_800D8FF8()) != 0)) {
        func_800FC660(0xE);
        *(f32 *) (local_0 + 0xC) = *(f32 *) (local_0 + 0x10);
        func_80800BCC_chfpsgame(param_0, _gcstatusDll_entrypoint_15(), -1);
    }
}

void func_808013DC_chfpsgame(this, player, state) Actor *this;
s32 player;
s32 state;
{
    FpsGameLocal *local;
    s32 cur;
    f32 a[3];
    f32 b[3];
    void *plyr;

    local = func_80100094(this, 0);
    plyr = func_800F53D0(player);
    switch (state) {
        case 1:
            func_800C968C(func_800A4C68(plyr), 0x13);
            _bainvisible_entrypoint_8(plyr, 1, 0.0f, 1.0f);
            _bainvisible_entrypoint_8(plyr, 2, 1.0f, 0.01f);
            break;
        case 2:
            func_800A38F0(plyr, 0, 0);
            func_800F44DC(plyr, 0);
            func_80093370(plyr, 0);
            local->slot[player].unk534 = 5.0f;
            break;
        case 3:
            func_800C968C(func_800A4C68(plyr), 0x12);
            if (_sudeathmatch_entrypoint_0(player, a, b)) {
                func_800F832C(player, b);
                func_800F8294(player, a);
            }
            func_800A1870(plyr, func_800A1760(plyr));
            func_800A38F0(plyr, 1, 1);
            _bainvisible_entrypoint_3(plyr);
            func_80093370(plyr, 1);
            func_8009337C(plyr, 1);
            func_800F44DC(plyr, 1);
            func_800F7C0C(player, 0x83, 0.0f);
            func_800F7F98(player, 1);
            break;
        case 0:
            func_800F7F98(player, 0);
            break;
        case 4:
            cur = local->slot[player].unk530;
            if (cur == 0 || cur == 3) {
                func_800C968C(func_800A4C68(plyr), 0x13);
            }
    }
    local->slot[player].unk530 = state;
}

void func_808015EC_chfpsgame(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    FpsE *local_3;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < _gcstatusDll_entrypoint_11(); local_1++) {
        if (1) {
        }
        local_2 = func_800F53D0(local_1);
        local_3 = (FpsE *) (local_0 + 0x530) + local_1;
        switch (local_3->a) {
            case 1:
                if (func_800C96CC(func_800A4C68(local_2)))
                    func_808013DC_chfpsgame(param_0, local_1, 2);
                break;
            case 2:
                if (!func_80800074_chfpsgame(param_0, 0)) {
                    if (func_800F1574(&local_3->b, func_800D8FF8()) ||
                        func_80016BBC(func_800F54F0(local_1), 0xD000)) {
                        func_808013DC_chfpsgame(param_0, local_1, 3);
                    }
                }
                break;
            case 3:
                if (func_800C9714(func_800A4C68(local_2)))
                    func_808013DC_chfpsgame(param_0, local_1, 0);
        }
    }
}

s32 func_80801758_chfpsgame(param_0)
s32 param_0;
{
    _sumultiscore_entrypoint_6((u8 *) func_80100094(param_0, 0) + 0x14);
}

int func_80801780_chfpsgame(s32 param_0, s32 param_1)
{
    s32 local_0;
    local_0 = func_80100094(param_0, 0);
    switch (func_800EB854()) {
        case 3:
            _sumultiscore_entrypoint_12(local_0 + 0x14, param_1, 1);
            _scradar_entrypoint_0();
            _scradar_entrypoint_1(param_1);
            return;
        case 4:
            func_80801B30_chfpsgame(param_0, param_1);
            _sumultiscore_entrypoint_12(local_0 + 0x14, param_1, 2);
    }
}

void func_80801814_chfpsgame(param_0) Actor *param_0;
{
    FpsTimer61 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = _gcstatusDll_entrypoint_17();
    if (local_1 != 0) {
        local_0->local_0 = local_1;
        local_0->local_1 = 0;
        local_0->local_2 = local_1 * 60.0f + 0.99f;
        func_80801A8C_chfpsgame(param_0, 10.99f);
    } else {
        local_0->local_2 = 0.0f;
        func_80801A8C_chfpsgame(param_0, 0);
    }
    local_0->local_3 = local_0->local_2;
}

void func_808018B0_chfpsgame(s32 param_0)
{
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    *(s8 *) ((s8 *) temp_v0 + 0x558) = 0;
    *(s8 *) ((s8 *) temp_v0 + 0x559) = 0;
    *(f32 *) ((s8 *) temp_v0 + 0x55C) = 0.0f;
}

void func_808018E0_chfpsgame(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1;
    f32 local_2;
    s32 local_3;
    local_0 = func_80100094(param_0, 0);
    if (*(f32 *) (local_0 + 0x55C) != 0.0f) {
        func_800F1574((f32 *) (local_0 + 0x560), func_800D8FF8());
        local_1 = *(f32 *) (local_0 + 0x560) * (1.0f / 60.0f);
        local_2 = (s32) local_1;
        local_0[0x55A] = (s32) local_2;
        local_0[0x55B] = (s32) ((local_1 - local_2) * 60.0f);
        if (local_0[0x558]) {
            local_3 = (s32) (func_800D8FF8() * 256.0f);
            if (func_800F1574((f32 *) (local_0 + 0x564), func_800D8FF8()))
                func_80801A8C_chfpsgame(param_0, 0.0f);
            if (*(f32 *) (local_0 + 0x564) > 1.0f)
                local_0[0x559] = func_800F1418(local_0[0x559] + local_3 * 4, 255);
            else if (*(f32 *) (local_0 + 0x564) < 0.5f)
                local_0[0x559] = func_800F0E28(local_0[0x559] - local_3 * 2, 0);
        } else if (*(f32 *) (local_0 + 0x560) < 10.99f)
            func_80801A8C_chfpsgame(param_0, 60.0f);
        else if (!local_0[0x55B])
            func_80801A8C_chfpsgame(param_0, 2.5f);
    }
}

int func_80801A8C_chfpsgame(Actor *param_0, f32 param_1)
{
    Actor *local_0 = func_80100094(param_0, 0);
    *(f32 *) ((char *) local_0 + 0x564) = param_1;
    if (param_1 != 0.0f) {
        *(u8 *) ((char *) local_0 + 0x558) = 1;
    } else {
        *(u8 *) ((char *) local_0 + 0x558) = 0;
    }
}

s32 func_80801ADC_chfpsgame(param_0)
s32 param_0;
{
    u8 *local_0 = func_80100094(param_0, 0);
    return (*(f32 *) (local_0 + 0x55C) != 0.0f && *(f32 *) (local_0 + 0x560) == 0.0f) ? 1 : 0;
}

void func_80801B30_chfpsgame(param_0, param_1) Actor *param_0;
void *param_1;
{
    char local_0[8];
    s32 local_3;
    FpsClock1590 *local_2;
    f32 local_1;

    local_2 = func_80100094(param_0, 0);

    if (local_2->local_0) {
        local_1 = local_2->local_4 * 0.5f;
        local_3 = (s32) local_1;
        local_1 -= local_3;
        _fxdialog_entrypoint_1(0x8F, 0x72);
        _fxdialog_entrypoint_2(0.75f);
        _fxdialog_entrypoint_4(param_1, 0xB4F, (s32) (local_1 * 20.0f), 0.0f, 0.0f,
                               local_2->local_1, 0);
        func_800B8C50();
        func_800B8C8C(local_2->local_1);
        func_800B8C98(3);
        func_800B8CBC(255, 255, 255);
        func_800B7F14(param_1);
        sprintf(local_0, "%d:%02d", local_2->local_2, local_2->local_3);
        func_800B8E28(param_1, 0x99, 0x72, local_0);
        func_800B811C(param_1);
    }
}

void func_80801C5C_chfpsgame(s32 param_0)
{
    void *local_0 = func_80100094(param_0, 0);
    *((int *) (((int) local_0) + 0x5BC)) = 0;
    *((int *) (((int) local_0) + 0x5C0)) = 0;
    *((int *) (((int) local_0) + 0x610)) = 0;
    *((int *) (((int) local_0) + 0x614)) = 0;
    *((int *) (((int) local_0) + 0x664)) = 0;
    *((int *) (((int) local_0) + 0x668)) = 0;
    *((int *) (((int) local_0) + 0x568)) = 0;
    *((int *) (((int) local_0) + 0x56C)) = 0;
}

void func_80801C9C_chfpsgame(Actor *param_0)
{
    u8 *local_0;
    s32 i;
    FpsList *l;

    local_0 = func_80100094(param_0, 0);
    for (i = 0; i < 4; i++) {
        l = &((FpsList *) (local_0 + 0x568))[i];

        if (l->count != 0) {
            do {
                func_8010114C(l->it[--l->count].x, 0x45, 0);
            } while (l->count != 0);
        }
    }
}

void func_80801D40_chfpsgame(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 pad[2];
    FPSPushItem1274_80801D40_chfpsgame *local_1;
    FPSPushList1274 *local_0;

    local_0 = &((FPSPushList1274 *) ((u8 *) func_80100094(param_0, 0) + 0x568))[param_1];
    func_80801DF0_chfpsgame(param_0, param_1, param_2);
    if (local_0->local_0 >= 10)
        func_80801F34_chfpsgame(param_0, param_1);
    local_1 = &local_0->local_1[local_0->local_0];
    local_1->local_0 = param_2;
    local_1->local_1 = func_8001211C();
    local_0->local_0++;
}

void func_80801DF0_chfpsgame(param_0, param_1, param_2) Actor *param_0;
s32 param_1;
s32 param_2;
{
    FpsBase *local_0;
    Actor *local_1;
    Actor *local_2;
    s32 local_3;
    s32 i;
    s32 j;
    FpsEntry *e;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80106790(param_2);
    local_3 = 0;
    for (i = 0; i < local_0->n; i++) {
        e = &local_0->e[i];
        for (j = 0; j < e->count; j++) {
            local_2 = func_80106790(e->el[j].id);

            if (func_800EEB40(local_1->position, local_2->position) < 90000.0f) {
                local_3 = 1;
                func_8010108C(local_2, 0x40, 0);
            }
        }
    }
    if (local_3 != 0) {
        func_8010108C(local_1, 0x40, 0);
    }
}

void func_80801F34_chfpsgame(param_0, param_1) Actor *param_0;
s32 param_1;
{
    u32 local_1;
    FpsTimedActorList *local_0;
    s32 pad[2];
    s32 local_3;
    s32 local_2;

    local_0 = (FpsTimedActorList *) ((u8 *) func_80100094(param_0, 0) + 0x568) + param_1;
    local_1 = func_8001211C();
    for (local_2 = 0; local_2 < local_0->local_0; local_2++) {
        if (local_0->local_1[local_2].local_1 < local_1) {
            local_1 = local_0->local_1[local_2].local_1;
            local_3 = local_2;
        }
    }
    func_8010114C(local_0->local_1[local_3].local_0, 0x4F, 0);
    local_0->local_0--;
    local_0->local_1[local_3].local_0 = local_0->local_1[local_0->local_0].local_0;
    local_0->local_1[local_3].local_1 = local_0->local_1[local_0->local_0].local_1;
}

void func_80802020_chfpsgame(Actor *param_0, s32 param_1, s32 param_2)
{
    FpsItemList *local_0;
    s32 local_1;

    local_0 = &((FpsItemLists *) func_80100094(param_0, 0))->local_0[param_1];
    local_0->local_0--;
    for (local_1 = 0; local_1 < local_0->local_0; local_1++) {
        if (param_2 == local_0->local_1[local_1].local_0) {
            local_0->local_1[local_1].local_0 = local_0->local_1[local_0->local_0].local_0;
            local_0->local_1[local_1].local_1 = local_0->local_1[local_0->local_0].local_1;
            break;
        }
    }
}

extern void func_80105834();
extern void func_80107C2C();
int D_808021A0_chfpsgame[20] = {0x15802C4,
                                -0xFFFF,
                                0x0,
                                (u32) func_808008D4_chfpsgame,
                                (u32) func_80105834,
                                (u32) func_80801780_chfpsgame,
                                0x0,
                                0x0,
                                0x0,
                                0x8400400,
                                (u32) func_8080090C_chfpsgame,
                                0x0,
                                0x6B80000,
                                (u32) func_808002FC_chfpsgame,
                                (u32) func_80107C2C,
                                -0x7FFF7BFE,
                                (u32) func_80800914_chfpsgame,
                                0x0,
                                0x0,
                                0x0};
