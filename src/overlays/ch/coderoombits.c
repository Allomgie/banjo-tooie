/*
 * ch/coderoombits (overlays) -- IDO 5.3, -O2 -mips2 -G 0 (project default).
 */

#include "common.h"

extern int D_80801170_chcoderoombits[];
extern u32 D_80801308_chcoderoombits[];
typedef union { s32 local_0; s16 local_1[2]; } CodeRoomMessage;
extern void *func_80100094(Actor *, u32);
extern s32 D_808011F4_chcoderoombits[];
typedef struct { u8 *local_0; u8 local_1[6]; u8 local_2; u8 local_3; } CodeSequence49;
typedef struct { u8 local_0[0x19]; u8 local_1; u8 local_2[0x13A]; s16 local_3[1]; } CodeProgress49;
extern void _subaddiedialog_entrypoint_11();
extern void func_800DA544();
extern void func_800FC660();
typedef struct { s32 local_0; u16 local_1; u16 local_2; u16 local_3; u8 local_4; u8 local_5; } Broad42CodeEntry;
extern void _gcfrontend_entrypoint_9();
extern void func_800D3F2C();
extern int func_800F54E4();
typedef struct { s32 f0; u8 pad[6]; u8 fA; u8 padB; } CodeEnt;
typedef struct { s32 local_0; u16 local_1; u16 local_2; u16 local_3; u8 local_4; u8 pad_0; } CodexCodeRoomCondition;
typedef struct { f32 local_0; u8 pad_0[8]; } CodeRoomColorRecord1482;
typedef struct { u8 pad_0[0x10]; CodeRoomColorRecord1482 local_0[1]; } CodeRoomColors1482;
extern u8 D_80801318_chcoderoombits[];
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_800F3320(u8 *, u8 *, u8 *, f32);
extern void func_800F2EA0();
extern f32 func_800EEAD4(f32 *, f32 *);
extern s32 func_800F4A8C(s32, f32 *, f32);
extern void func_8010D5DC(void);
typedef struct { u8 local_0; u8 local_1; } CodeRoomCell1805;
extern u8 D_808011B8_chcoderoombits[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern void func_800EC398(s32, f32 *);
typedef struct { u8 local_0[0x1C]; f32 local_1; f32 local_2; s32 local_3; } Broad42CodeAnimation;
extern u8 _chcoderoombits_entrypoint_2[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern int func_800D91EC(f32 *, f32);
typedef struct { f32 local_0; f32 local_1; s32 local_2; } CodeRoomCellState;
typedef struct { u8 pad_0[0x1C]; CodeRoomCellState local_0[26]; } CodeRoomCells;

/* Forward declarations of the functions in this file. */
void func_8080040C_chcoderoombits();
int func_808004B8_chcoderoombits();
int func_8080077C_chcoderoombits();
void func_8080091C_chcoderoombits();
int func_80800B40_chcoderoombits();
void func_80800BF4_chcoderoombits();
void func_80800D90_chcoderoombits();
void func_80800E28_chcoderoombits();

int chcoderoombits_entrypoint_0();
int func_8080000C_chcoderoombits(s32 param_0);
s32 func_8080033C_chcoderoombits(Actor *param_0, s32 param_1, CodeRoomMessage param_2);
int func_8080052C_chcoderoombits(Actor *param_0, u8 *param_1);
void func_80800998_chcoderoombits();
void chcoderoombits_entrypoint_2(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4);
int func_80800FDC_chcoderoombits();
void func_80800058_chcoderoombits(Actor *param_0);
void chcoderoombits_entrypoint_1(s32 param_0, s32 param_1);
/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/coderoombits.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Pointers to strings are written as string literals; IDO places these strings in .rodata where the
 * original has them, which is why this block stands in front of the functions.
 * extern declarations adjusted to the object (same addresses): D_80801170_chcoderoombits -> int[], D_808011F4_chcoderoombits -> s32[], D_80801308_chcoderoombits -> u32[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80801170_chcoderoombits[18] = { 0x32E03CE, 0x1, 0x0, (u32)func_80800058_chcoderoombits, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1540000, (u32)func_8080000C_chcoderoombits, (u32)func_80107C2C, -0x7FFFFBFE, (u32)func_8080033C_chcoderoombits, 0x0 };
u8 D_808011B8_chcoderoombits[60] = { 0xFF, 0x0, 0x4D, 0x17, 0x54, 0x18, 0x5A, 0x19, 0x4A, 0x1A, 0xFF, 0x0, 0x4B, 0x11, 0x4F, 0x12, 0x53, 0x13, 0x42, 0x14, 0x49, 0x15, 0x59, 0x16, 0x41, 0xB, 0x58, 0xC, 0x55, 0xD, 0x48, 0xE, 0x50, 0xF, 0x46, 0x10, 0x47, 0x5, 0x56, 0x6, 0x52, 0x7, 0x45, 0x8, 0x4C, 0x9, 0x43, 0xA, 0xFF, 0x0, 0x57, 0x1, 0x51, 0x2, 0x44, 0x3, 0x4E, 0x4, 0xFF, 0x0 };
s32 D_808011F4_chcoderoombits[69] = { (u32)"IPWNBZ", 0x0, 0x0, (u32)"CWNBPWDQ", 0x10001, 0x11500000, (u32)"WSSQ", 0x10002, 0x11510000, (u32)"CNYYGDZZC", 0x10003, 0x11520000, (u32)"PZKWFENIH", 0x10004, 0x11530000, (u32)"AXHWEZU", 0x10005, 0x11540000, (u32)"SWBAOSSF", 0x10006, 0x11550000, (u32)"PZVOKS", 0x1000C, 0x11620000, (u32)"QXGWDENKAZ", 0x10007, 0x11560100, (u32)"QXGWDENTTF", 0x10008, 0x11570100, (u32)"PZKWFHOKS", 0x10009, 0x11580100, (u32)"KWQBHOKS", 0x1000A, 0x11590100, (u32)"QDWPBNWC", 0x10001, 0x11500100, (u32)"QSSW", 0x10002, 0x11510100, (u32)"CZZDGYYNC", 0x10003, 0x11520100, (u32)"HINEFWKZP", 0x10004, 0x11530100, (u32)"UZEWHXA", 0x10005, 0x11540100, (u32)"FSSOABWS", 0x10006, 0x11550100, (u32)"SKOVZP", 0x1000C, 0x11620100, (u32)"AOSSFJOSSFQGWIONY", 0x1000B, 0x115F0100, (u32)"INQBYOQB", 0x20085, 0x11600100, (u32)"GYNFOBNSNOKQZK", 0x30000, 0x11610100, 0x0, 0x0, 0x0 };
u32 D_80801308_chcoderoombits[4] = { 0x43160000, 0x43480000, 0x43960000, 0x0 };
u8 D_80801318_chcoderoombits[8] = { 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };

int chcoderoombits_entrypoint_0()
{
    return &D_80801170_chcoderoombits;
}

int func_8080000C_chcoderoombits(s32 param_0)
{
  s32 local_0;
  local_0 = func_80100074(param_0, 0, 0x182);
  _susubgame_entrypoint_0(param_0, local_0 | 0, 1);
  _susubgame_entrypoint_12(local_0, &D_80801308_chcoderoombits);
}

void func_80800058_chcoderoombits(Actor *param_0)
{
    f32 local_0[3];
    u8 *local_1;
    s32 local_2;
    s32 local_3;

    local_1 = func_80100094(param_0, 0);
    local_2 = func_800F54E4();
    func_800F5A00(local_2, local_0);
    switch (param_0->unk70_10) {
    case 1:
        if (!func_800DA298(0x6A)) {
            if (func_8010C9B0(param_0->position, 350) && func_800F64A4(local_2, 0x201)) {
                if (func_800C6E38(0x16)) local_3 = 0x1140;
                else local_3 = 0x115C;
                _susubgame_entrypoint_5(param_0, local_1, 4, 0, 0);
                _subaddiedialog_entrypoint_11(param_0->unk0, local_3, 0xE, param_0->position, 0);
                func_800DA544(0x6A);
            }
        } else if (func_800C6E38(0x16) && func_800F6478(local_2)) {
            if (func_800EEAD4(param_0->position, local_0) > 100.0f) {
                local_1[0x18] = 0;
            } else if (!local_1[0x18] && func_800F6C5C(local_2)
                       && func_800F64A4(local_2, 0x201) && func_800F52B8(local_2, 0) != 6) {
                func_800F497C(local_2);
                func_800F49D4(local_2, func_8010D5DC, param_0->unk0);
                func_800F4A8C(local_2, param_0->position, 0.6f);
                func_800F4A00(local_2, 0);
                func_800F7F98(local_2, 1);
                func_808004B8_chcoderoombits(param_0);
                func_80101FDC(param_0, 2);
                local_1[0x18] = 1;
            }
        }
        break;
    case 2:
        if (func_800F5C94(local_2) == 4) {
            if (!func_800DA298(0x6B)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1141, 6, 0, 0);
                func_800DA544(0x6B);
                func_80101FDC(param_0, 3);
            } else {
                func_80101FDC(param_0, 4);
                func_800F7F98(local_2, 0);
            }
        }
        break;
    case 3:
        break;
    case 4:
        if (func_800F5C94(local_2) != 4) {
            func_80101FDC(param_0, 1);
            func_800946C4(func_800F53D0(local_2), 0);
        }
        break;
    case 5:
        if (func_800C064C() == -1) func_80101FDC(param_0, 4);
        break;
    }
    func_80800BF4_chcoderoombits(param_0);
}

s32 func_8080033C_chcoderoombits(Actor *param_0, s32 param_1, CodeRoomMessage param_2)
{
    f32 local_0[3];

    switch (param_1) {
    case 0x2E:
        func_8080040C_chcoderoombits(param_0, param_2.local_1[0], param_2.local_1[1]);
        break;
    case 0x32:
        func_800DBEFC(func_800BEC10(), 4, local_0);
        func_800F7CF4(func_800F54E4(), 0x39, local_0);
        func_800946C4(func_800F53D0(func_800F54E4()), 1);
        break;
    case 0x95:
        func_808004B8_chcoderoombits(param_0);
        func_80101FDC(param_0, 1);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080040C_chcoderoombits(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
        case 0x1140:
        case 0x115C:
            _susubgame_entrypoint_4(param_0, func_80100094(param_0, 0));
            break;
        case 0x1141:
            func_800F7F98(func_800F54E4(), 0);
            func_80101FDC(param_0, 4);
            break;
        case 0x115B:
            break;
        default:
            func_800F7F98(func_800F54E4(), 0);
            func_80101FDC(param_0, 4);
            break;
    }
}

int func_808004B8_chcoderoombits(param_0) Actor *param_0;
{
    u8 *local_0;
    s16 *local_1;
    s32 *local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = (s16 *)((u8 *)func_80100094(param_0, 0) + 0x154);
    local_2 = &D_808011F4_chcoderoombits;
    if (local_2[0]) {
        do {
            *local_1 = 0;
            local_2 += 3;
            local_1++;
        } while (local_2[0]);
    }
    local_0[0x19] = 0;
    func_80800E28_chcoderoombits(param_0);
}

int func_8080052C_chcoderoombits(Actor *param_0, u8 *param_1)
{
    CodeSequence49 *local_0;
    CodeProgress49 *local_1;
    s16 *local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 idx;
    local_2 = ((CodeProgress49 *)func_80100094(param_0, 0))->local_3;
    local_3 = 0;
    local_4 = 0;
    local_5 = 0;
    local_1 = func_80100094(param_0, 0);
    for (local_0 = (CodeSequence49 *)&D_808011F4_chcoderoombits; local_0->local_0; local_0++, local_2++) {
        if (func_80800B40_chcoderoombits(param_0, local_0)) continue;
        idx = *local_2;
        if (param_1[0] != local_0->local_0[idx]) { *local_2 = 0; continue; }
        if (local_0->local_2 && !local_1->local_1) { *local_2 = 0; continue; }
        if (!local_0->local_2 && local_1->local_1) { *local_2 = 0; continue; }
        if (local_0->local_2) local_4 = 1;
        else local_3 = 1;
        (*local_2)++;
        if (!local_0->local_0[*local_2 * 1]) {
            func_808004B8_chcoderoombits(param_0);
            func_8080077C_chcoderoombits(param_0, local_0);
            return;
        }
        if (!local_0->local_2 && !local_5) {
            local_5 = 1;
            func_80800D90_chcoderoombits(param_0, param_1[1] - 1);
            func_800FC660(0xE);
        }
    }
    local_6 = local_1->local_1;
    if (!local_4 && local_3 && local_1->local_1) func_8080091C_chcoderoombits(param_0);
    if (local_4 && !local_3) {
        func_80800998_chcoderoombits(param_0);
        func_80800E28_chcoderoombits(param_0);
    }
    if (!local_3 && !local_4) {
        func_808004B8_chcoderoombits(param_0);
        if (!local_6) {
            func_800FC660(0xF);
            if (!func_800DA298(0x668)) {
                func_800DA544(0x668);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x115A, 6, 0, 0);
                func_800F7F98(func_800F54E4(), 1);
                return 1;
            }
        }
    }
    return 0;
}

int func_8080077C_chcoderoombits(param_0, param_1) Actor *param_0; Broad42CodeEntry *param_1;
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (param_1 == (Broad42CodeEntry *)&D_808011F4_chcoderoombits) {
        func_800FC660(0xE);
        local_0[0x19] = 1;
        return 0;
    }
    func_800FC660(0x10);
    switch (param_1->local_1) {
    case 1:
        func_800D3F2C(param_1->local_2);
        break;
    case 2:
        _gcfrontend_entrypoint_9(param_1->local_2);
        break;
    case 3:
        for (local_1 = 0x20; local_1 < 0x2D; local_1++) {
            _gcfrontend_entrypoint_9(local_1);
        }
        for (local_1 = 0x60; local_1 < 0x77; local_1++) {
            _gcfrontend_entrypoint_9(local_1);
        }
        for (local_1 = 0x80; local_1 != 0x86; local_1++) {
            _gcfrontend_entrypoint_9(local_1);
        }
        func_800DA544(0xC08);
        func_800DA544(0xC09);
        func_800DA544(0xC0A);
        func_800DA544(0xC0C);
        break;
    }
    if (param_1->local_3) {
        if (func_80800FDC_chcoderoombits() == 1 && param_1->local_4 == 0) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x115B, 6, 0, 0);
        }
        _subaddiedialog_entrypoint_11(param_0->unk0, param_1->local_3, 6, 0, 0);
        func_800F7F98(func_800F54E4(), 1);
    }
    return 1;
}

void func_8080091C_chcoderoombits(param_0) Actor *param_0;
{
    u8 *local_0;
    s16 *local_1;
    s32 *local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = (s16 *)(local_0 + 0x154);
    local_0 = func_80100094(param_0, 0);
    *local_1 = 0;
    local_0[0x19] = 0;
    local_2 = &D_808011F4_chcoderoombits;
    while (local_2[0]) {
        if (((u8 *)local_2)[0xA]) {
            *local_1 = 0;
        }
        local_2 += 3;
        local_1++;
    }
}

void func_80800998_chcoderoombits(param_0) s32 param_0; {
    s16 *local_0 = (s16 *)((u8 *)func_80100094(param_0, 0) + 0x154);
    CodeEnt *local_1;
    for (local_1 = ((CodeEnt *) &D_808011F4_chcoderoombits); local_1->f0 != 0; local_1++, local_0++) {
        if (local_1->fA == 0) {
            *local_0 = 0;
        }
    }
}

void chcoderoombits_entrypoint_1(s32 param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    s32 local_3;
  s32 pad0; /* padding local: without it the frame is 8 bytes too small; the original variable is unknown */
    Actor *local_4;
    u8 local_5;

    local_4 = _subaddiefind_entrypoint_2(0x3CE, 0);
    if (local_4->unk70_10 == 4) {
        func_800DBEFC(func_800BEC10(), 4, local_0);
        local_0[0] -= 510.0f;
        local_0[1] -= 425.0f;
        func_800EC398(param_1, local_1);
        local_2 = (s32)((local_1[0] - local_0[0]) * 0.005882353f);
        local_3 = (s32)((local_1[1] - local_0[1]) * 0.005882353f);
        if (local_2 >= 0 && local_2 < 6 && local_3 >= 0 && local_3 < 5) {
            if (((CodeRoomCell1805 (*)[6])D_808011B8_chcoderoombits)[local_3][local_2].local_0 != 0xFF && func_8080052C_chcoderoombits(local_4, &((CodeRoomCell1805 (*)[6])D_808011B8_chcoderoombits)[local_3][local_2])) {
            func_80101FDC(local_4, 5);
            func_808004B8_chcoderoombits(local_4);
        }
        }
    }
}

int func_80800B40_chcoderoombits(param_0, param_1) Actor *param_0; CodexCodeRoomCondition *param_1;
{
    switch (param_1->local_1) {
    case 1:
        if (param_1->local_4) {
            if (func_800D3EC8(param_1->local_2) == 0) {
                return 1;
            }
        } else {
            if (func_800D3E6C(param_1->local_2) == 0) {
                return 1;
            }
        }
        break;
    case 2:
        if (_gcfrontend_entrypoint_3(param_1->local_2)) {
            return 1;
        }
        break;
    case 3:
        if (func_800DA298(0xC0C)) {
            return 1;
        }
        break;
    }
    return 0;
}

void func_80800BF4_chcoderoombits(param_0) Actor *param_0;
{
    Broad42CodeAnimation *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_1 = func_80100094(param_0, 0);
    local_4 = (s32)param_0->unk0;
    local_3 = func_800BEA88(0);
    for (local_2 = 0, local_0 = (Broad42CodeAnimation *)local_1; local_2 != 0x1A; local_2++, local_0 = (Broad42CodeAnimation *)((u8 *)local_0 + 0xC)) {
        switch (local_0->local_3) {
        case 0:
            local_0->local_1 = 0.0f;
            break;
        case 1:
            if (func_800D91EC(&local_0->local_2, 0.2f)) {
                local_0->local_3 = 2;
            }
            local_0->local_1 = func_800F10B4(local_0->local_2, 0.0f, 0.2f, 0.0f, 1.0f);
            break;
        case 2:
            local_0->local_1 = 1.0f;
            break;
        case 3:
            if (func_800D91EC(&local_0->local_2, 0.6f)) {
                local_0->local_3 = 0;
            }
            local_0->local_1 = func_800F10B4(local_0->local_2, 0.0f, 0.6f, 1.0f, 0.0f);
            break;
        }
        if (local_3) {
            _glid_entrypoint_0(local_3, local_2 + 1, _chcoderoombits_entrypoint_2, local_4);
        }
    }
}

void func_80800D90_chcoderoombits(param_0, param_1) u8 *param_0; s32 param_1;
{
    u8 *entry;
    s32 state;
    f32 q;
    int t;
    entry = (u8 *)func_80100094(param_0, 0) + param_1 * 12;
    state = *((s32 *) (entry + 0x24));
    switch (state) {
    case 3:
        t = !entry; /* PROBE: the empty triple test keeps the constant 1 in a1 early; the natural form is still open */
        if (t && t && t) {}
        *((s32 *) (entry + 0x24)) = 1;
        q = (0.6f - *((f32 *) (entry + 0x20))) / 0.6f;
        *((f32 *) (entry + 0x20)) = q * 0.2f;
        break;
    case 0:
        *((s32 *) (entry + 0x24)) = 1;
        *((f32 *) (entry + 0x20)) = 0.0f;
        break;
    case 1:
    case 2:
        break;
    }
}

void func_80800E28_chcoderoombits(param_0) Actor *param_0;
{
    CodeRoomCells *local_0;
    s32 local_1;
    f32 local_2;

    local_0 = (CodeRoomCells *)func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 26; local_1++) {
        switch (local_0->local_0[local_1].local_2) {
        case 0:
        case 3:
            break;
        case 1:
            local_2 = (0.2f - local_0->local_0[local_1].local_1) / 0.2f;
            local_0->local_0[local_1].local_2 = local_2 * 0.6f;
            break;
        case 2:
            local_0->local_0[local_1].local_2 = 3;
            local_0->local_0[local_1].local_1 = 0.0f;
            break;
        }
    }
}
void chcoderoombits_entrypoint_2(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    Actor *actor;
    Vtx *local_1;
    CodeRoomColors1482 *local_2;
    u8 local_0[4];

    actor = func_80106790(param_4);
    local_2 = func_80100094(actor, 0);
    func_800F3320(local_0, param_1->v.cn, D_80801318_chcoderoombits, local_2->local_0[param_0].local_0);
    local_1 = param_3 + param_1;
    while (param_1 < local_1) {
        func_800F2EA0(param_2->v.cn, local_0);
        param_1++;
        param_2++;
    }
}
int func_80800FDC_chcoderoombits()
{
  s32 local_0;
  s32 local_1 = 0;
  for (local_0 = 1; local_0 < 0xD; local_0++)
  {
    if (func_800D3E14(local_0 | 0))
    {
      local_1++;
    }
  }

  return local_1;
}


