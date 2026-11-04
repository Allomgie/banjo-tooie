#include "common.h"

typedef union {
    s32 local_0;
    s16 local_1[2];
} CodeRoomMessage;
extern void *func_80100094(Actor *, u32);
typedef struct {
    u8 *local_0;
    u8 local_1[6];
    u8 local_2;
    u8 local_3;
} CodeSequence49;
typedef struct {
    u8 local_0[0x19];
    u8 local_1;
    u8 local_2[0x13A];
    s16 local_3[1];
} CodeProgress49;
extern void _subaddiedialog_entrypoint_11();
extern void func_800DA544();
extern void func_800FC660();
typedef struct {
    s32 local_0;
    u16 local_1;
    u16 local_2;
    u16 local_3;
    u8 local_4;
    u8 local_5;
} Broad42CodeEntry;
extern void _gcfrontend_entrypoint_9();
extern void func_800D3F2C();
extern int func_800F54E4();
typedef struct {
    s32 f0;
    u8 pad[6];
    u8 fA;
    u8 padB;
} CodeEnt;
typedef struct {
    s32 local_0;
    u16 local_1;
    u16 local_2;
    u16 local_3;
    u8 local_4;
    u8 pad_0;
} CodexCodeRoomCondition;
typedef struct {
    f32 local_0;
    u8 pad_0[8];
} CodeRoomColorRecord1482;
typedef struct {
    u8 pad_0[0x10];
    CodeRoomColorRecord1482 local_0[1];
} CodeRoomColors1482;
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_800F3320(u8 *, u8 *, u8 *, f32);
extern void func_800F2EA0();
extern f32 func_800EEAD4(f32 *, f32 *);
extern s32 func_800F4A8C(s32, f32 *, f32);
extern void func_8010D5DC(void);
typedef struct {
    u8 local_0;
    u8 local_1;
} CodeRoomCell1805;
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern void func_800EC398(s32, f32 *);
typedef struct {
    u8 local_0[0x1C];
    f32 local_1;
    f32 local_2;
    s32 local_3;
} Broad42CodeAnimation;
extern u8 _chcoderoombits_entrypoint_2[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern int func_800D91EC(f32 *, f32);
typedef struct {
    f32 local_0;
    f32 local_1;
    s32 local_2;
} CodeRoomCellState;
typedef struct {
    u8 pad_0[0x1C];
    CodeRoomCellState local_0[26];
} CodeRoomCells;

void func_8080040C_chcoderoombits();
int func_808004B8_chcoderoombits();
int func_8080077C_chcoderoombits();
void func_8080091C_chcoderoombits();
int func_80800B40_chcoderoombits();
void func_80800BF4_chcoderoombits();
void func_80800D90_chcoderoombits();
void func_80800E28_chcoderoombits();

int func_8080000C_chcoderoombits(s32 param_0);
s32 func_8080033C_chcoderoombits(Actor *param_0, s32 param_1, CodeRoomMessage param_2);
void func_80800998_chcoderoombits();
int func_80800FDC_chcoderoombits();
void func_80800058_chcoderoombits(Actor *param_0);
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();

// TU-NOTE: the data tables below are defined in this file because they point to functions here;
// IDO schedules some of these functions differently otherwise. Values come from the ROM.
int D_80801170_chcoderoombits[18] = {0x32E03CE,
                                     0x1,
                                     0x0,
                                     (u32) func_80800058_chcoderoombits,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x1540000,
                                     (u32) func_8080000C_chcoderoombits,
                                     (u32) func_80107C2C,
                                     -0x7FFFFBFE,
                                     (u32) func_8080033C_chcoderoombits,
                                     0x0};
u8 D_808011B8_chcoderoombits[60] = {
    0xFF, 0x0,  0x4D, 0x17, 0x54, 0x18, 0x5A, 0x19, 0x4A, 0x1A, 0xFF, 0x0,  0x4B, 0x11, 0x4F,
    0x12, 0x53, 0x13, 0x42, 0x14, 0x49, 0x15, 0x59, 0x16, 0x41, 0xB,  0x58, 0xC,  0x55, 0xD,
    0x48, 0xE,  0x50, 0xF,  0x46, 0x10, 0x47, 0x5,  0x56, 0x6,  0x52, 0x7,  0x45, 0x8,  0x4C,
    0x9,  0x43, 0xA,  0xFF, 0x0,  0x57, 0x1,  0x51, 0x2,  0x44, 0x3,  0x4E, 0x4,  0xFF, 0x0};
s32 D_808011F4_chcoderoombits[69] = {(u32) "IPWNBZ",
                                     0x0,
                                     0x0,
                                     (u32) "CWNBPWDQ",
                                     0x10001,
                                     0x11500000,
                                     (u32) "WSSQ",
                                     0x10002,
                                     0x11510000,
                                     (u32) "CNYYGDZZC",
                                     0x10003,
                                     0x11520000,
                                     (u32) "PZKWFENIH",
                                     0x10004,
                                     0x11530000,
                                     (u32) "AXHWEZU",
                                     0x10005,
                                     0x11540000,
                                     (u32) "SWBAOSSF",
                                     0x10006,
                                     0x11550000,
                                     (u32) "PZVOKS",
                                     0x1000C,
                                     0x11620000,
                                     (u32) "QXGWDENKAZ",
                                     0x10007,
                                     0x11560100,
                                     (u32) "QXGWDENTTF",
                                     0x10008,
                                     0x11570100,
                                     (u32) "PZKWFHOKS",
                                     0x10009,
                                     0x11580100,
                                     (u32) "KWQBHOKS",
                                     0x1000A,
                                     0x11590100,
                                     (u32) "QDWPBNWC",
                                     0x10001,
                                     0x11500100,
                                     (u32) "QSSW",
                                     0x10002,
                                     0x11510100,
                                     (u32) "CZZDGYYNC",
                                     0x10003,
                                     0x11520100,
                                     (u32) "HINEFWKZP",
                                     0x10004,
                                     0x11530100,
                                     (u32) "UZEWHXA",
                                     0x10005,
                                     0x11540100,
                                     (u32) "FSSOABWS",
                                     0x10006,
                                     0x11550100,
                                     (u32) "SKOVZP",
                                     0x1000C,
                                     0x11620100,
                                     (u32) "AOSSFJOSSFQGWIONY",
                                     0x1000B,
                                     0x115F0100,
                                     (u32) "INQBYOQB",
                                     0x20085,
                                     0x11600100,
                                     (u32) "GYNFOBNSNOKQZK",
                                     0x30000,
                                     0x11610100,
                                     0x0,
                                     0x0,
                                     0x0};
u32 D_80801308_chcoderoombits[4] = {0x43160000, 0x43480000, 0x43960000, 0x0};
u8 D_80801318_chcoderoombits[8] = {0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

int chcoderoombits_entrypoint_0()
{
    return &D_80801170_chcoderoombits;
}

int func_8080000C_chcoderoombits(s32 actor)
{
    s32 unk_0;
    unk_0 = func_80100074(actor, 0, 0x182);
    // Matching: the "| 0" is needed for the match.
    _susubgame_entrypoint_0(actor, unk_0 | 0, 1);
    _susubgame_entrypoint_12(unk_0, &D_80801308_chcoderoombits);
}

// Code chamber podium state machine.
void func_80800058_chcoderoombits(Actor *actor)
{
    f32 player_pos[3];
    u8 *state;
    s32 player;
    s32 dialog_id;

    state = func_80100094(actor, 0);
    player = func_800F54E4();
    func_800F5A00(player, player_pos);
    switch (actor->unk70_10) {
        case 1:
            if (!func_800DA298(0x6A)) {
                if (func_8010C9B0(actor->position, 350) && func_800F64A4(player, 0x201)) {
                    if (func_800C6E38(0x16))
                        dialog_id = 0x1140;
                    else
                        dialog_id = 0x115C;
                    _susubgame_entrypoint_5(actor, state, 4, 0, 0);
                    _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, 0xE, actor->position,
                                                  0);
                    func_800DA544(0x6A);
                }
            } else if (func_800C6E38(0x16) && func_800F6478(player)) {
                if (func_800EEAD4(actor->position, player_pos) > 100.0f) {
                    state[0x18] = 0;
                } else if (!state[0x18] && func_800F6C5C(player) &&
                           func_800F64A4(player, 0x201) && func_800F52B8(player, 0) != 6) {
                    func_800F497C(player);
                    func_800F49D4(player, func_8010D5DC, actor->unk0);
                    func_800F4A8C(player, actor->position, 0.6f);
                    func_800F4A00(player, 0);
                    func_800F7F98(player, 1);
                    func_808004B8_chcoderoombits(actor);
                    func_80101FDC(actor, 2);
                    state[0x18] = 1;
                }
            }
            break;
        case 2:
            if (func_800F5C94(player) == 4) {
                if (!func_800DA298(0x6B)) {
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x1141, 6, 0, 0);
                    func_800DA544(0x6B);
                    func_80101FDC(actor, 3);
                } else {
                    func_80101FDC(actor, 4);
                    func_800F7F98(player, 0);
                }
            }
        case 3:
            break;
        case 4:
            if (func_800F5C94(player) != 4) {
                func_80101FDC(actor, 1);
                func_800946C4(func_800F53D0(player), 0);
            }
            break;
        case 5:
            if (func_800C064C() == -1)
                func_80101FDC(actor, 4);
    }
    func_80800BF4_chcoderoombits(actor);
}

s32 func_8080033C_chcoderoombits(Actor *actor, s32 msg, CodeRoomMessage msg_data)
{
    f32 pos[3];

    switch (msg) {
        case 0x2E:
            func_8080040C_chcoderoombits(actor, msg_data.local_1[0], msg_data.local_1[1]);
            break;
        case 0x32:
            func_800DBEFC(func_800BEC10(), 4, pos);
            func_800F7CF4(func_800F54E4(), 0x39, pos);
            func_800946C4(func_800F53D0(func_800F54E4()), 1);
            break;
        case 0x95:
            func_808004B8_chcoderoombits(actor);
            func_80101FDC(actor, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080040C_chcoderoombits(actor, dialog_id, unused) Actor *actor;
s32 dialog_id;
s32 unused;
{
    switch (dialog_id) {
        case 0x1140:
        case 0x115C:
            _susubgame_entrypoint_4(actor, func_80100094(actor, 0));
            break;
        case 0x1141:
            func_800F7F98(func_800F54E4(), 0);
            func_80101FDC(actor, 4);
        case 0x115B:
            break;
        default:
            func_800F7F98(func_800F54E4(), 0);
            func_80101FDC(actor, 4);
    }
}

int func_808004B8_chcoderoombits(actor)
Actor *actor;
{
    u8 *state;
    s16 *progress;
    s32 *seq;

    state = func_80100094(actor, 0);
    progress = (s16 *) ((u8 *) func_80100094(actor, 0) + 0x154);
    seq = &D_808011F4_chcoderoombits;
    if (seq[0]) {
        do {
            *progress = 0;
            seq += 3;
            progress++;
        } while (seq[0]);
    }
    state[0x19] = 0;
    func_80800E28_chcoderoombits(actor);
}

// Matches a hit letter against the code table.
int func_8080052C_chcoderoombits(Actor *actor, u8 *cell)
{
    CodeSequence49 *seq;
    CodeProgress49 *progress;
    s16 *step;
    s32 plain_match;
    s32 alt_match;
    s32 glow_started;
    s32 alt_mode;
    s32 idx;
    step = ((CodeProgress49 *) func_80100094(actor, 0))->local_3;
    plain_match = 0;
    alt_match = 0;
    glow_started = 0;
    progress = func_80100094(actor, 0);
    for (seq = (CodeSequence49 *) &D_808011F4_chcoderoombits; seq->local_0;
         seq++, step++) {
        if (func_80800B40_chcoderoombits(actor, seq))
            continue;
        idx = *step;
        if (cell[0] != seq->local_0[idx]) {
            *step = 0;
            continue;
        }
        if (seq->local_2 && !progress->local_1) {
            *step = 0;
            continue;
        }
        if (!seq->local_2 && progress->local_1) {
            *step = 0;
            continue;
        }
        if (seq->local_2)
            alt_match = 1;
        else
            plain_match = 1;
        (*step)++;
        // Matching: the "* 1" is needed for the match.
        if (!seq->local_0[*step * 1]) {
            func_808004B8_chcoderoombits(actor);
            func_8080077C_chcoderoombits(actor, seq);
            return;
        }
        if (!seq->local_2 && !glow_started) {
            glow_started = 1;
            func_80800D90_chcoderoombits(actor, cell[1] - 1);
            func_800FC660(0xE);
        }
    }
    alt_mode = progress->local_1;
    if (!alt_match && plain_match && progress->local_1)
        func_8080091C_chcoderoombits(actor);
    if (alt_match && !plain_match) {
        func_80800998_chcoderoombits(actor);
        func_80800E28_chcoderoombits(actor);
    }
    if (!plain_match && !alt_match) {
        func_808004B8_chcoderoombits(actor);
        if (!alt_mode) {
            func_800FC660(0xF);
            if (!func_800DA298(0x668)) {
                func_800DA544(0x668);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x115A, 6, 0, 0);
                func_800F7F98(func_800F54E4(), 1);
                return 1;
            }
        }
    }
    return 0;
}

// Applies a finished code: toggles a cheat or unlocks frontend entries.
int func_8080077C_chcoderoombits(actor, entry)
Actor *actor;
Broad42CodeEntry *entry;
{
    u8 *state;
    s32 i;

    state = func_80100094(actor, 0);
    if (entry == (Broad42CodeEntry *) &D_808011F4_chcoderoombits) {
        func_800FC660(0xE);
        state[0x19] = 1;
        return 0;
    }
    func_800FC660(0x10);
    switch (entry->local_1) {
        case 1:
            func_800D3F2C(entry->local_2);
            break;
        case 2:
            _gcfrontend_entrypoint_9(entry->local_2);
            break;
        case 3:
            for (i = 0x20; i < 0x2D; i++) {
                _gcfrontend_entrypoint_9(i);
            }
            for (i = 0x60; i < 0x77; i++) {
                _gcfrontend_entrypoint_9(i);
            }
            for (i = 0x80; i != 0x86; i++) {
                _gcfrontend_entrypoint_9(i);
            }
            func_800DA544(0xC08);
            func_800DA544(0xC09);
            func_800DA544(0xC0A);
            func_800DA544(0xC0C);
    }
    if (entry->local_3) {
        if (func_80800FDC_chcoderoombits() == 1 && entry->local_4 == 0) {
            _subaddiedialog_entrypoint_11(actor->unk0, 0x115B, 6, 0, 0);
        }
        _subaddiedialog_entrypoint_11(actor->unk0, entry->local_3, 6, 0, 0);
        func_800F7F98(func_800F54E4(), 1);
    }
    return 1;
}

void func_8080091C_chcoderoombits(actor) Actor *actor;
{
    u8 *state;
    s16 *progress;
    s32 *seq;

    state = func_80100094(actor, 0);
    progress = (s16 *) (state + 0x154);
    state = func_80100094(actor, 0);
    *progress = 0;
    state[0x19] = 0;
    seq = &D_808011F4_chcoderoombits;
    while (seq[0]) {
        if (((u8 *) seq)[0xA]) {
            *progress = 0;
        }
        seq += 3;
        progress++;
    }
}

void func_80800998_chcoderoombits(actor) s32 actor;
{
    s16 *progress = (s16 *) ((u8 *) func_80100094(actor, 0) + 0x154);
    CodeEnt *seq;
    for (seq = ((CodeEnt *) &D_808011F4_chcoderoombits); seq->f0 != 0;
         seq++, progress++) {

if (seq->fA == 0) {
    *progress = 0;
}

}
}

// Egg hit: maps the hit position to the 6x5 letter grid.
void chcoderoombits_entrypoint_1(s32 unused, s32 hit)
{
    f32 base_pos[3];
    f32 hit_pos[3];
    s32 col;
    s32 row;
    s32 pad0; // Matching: padding local, the frame is 8 bytes too small without it.
    Actor *chamber;

    chamber = _subaddiefind_entrypoint_2(0x3CE, 0);
    if (chamber->unk70_10 == 4) {
        func_800DBEFC(func_800BEC10(), 4, base_pos);
        base_pos[0] -= 510.0f;
        base_pos[1] -= 425.0f;
        func_800EC398(hit, hit_pos);
        col = (s32) ((hit_pos[0] - base_pos[0]) * 0.005882353f);
        row = (s32) ((hit_pos[1] - base_pos[1]) * 0.005882353f);

if (col >= 0 && col < 6 && row >= 0 && row < 5) {
    if (((CodeRoomCell1805(*)[6]) D_808011B8_chcoderoombits)[row][col].local_0 != 0xFF &&
        func_8080052C_chcoderoombits(
            chamber, &((CodeRoomCell1805(*)[6]) D_808011B8_chcoderoombits)[row][col])) {
        func_80101FDC(chamber, 5);
        func_808004B8_chcoderoombits(chamber);
    }
}

}
}

// Returns 1 to skip this table entry.
int func_80800B40_chcoderoombits(actor, entry)
Actor *actor;
CodexCodeRoomCondition *entry;
{
    switch (entry->local_1) {
        case 1:
            if (entry->local_4) {
                if (func_800D3EC8(entry->local_2) == 0) {
                    return 1;
                }
            } else {

if (func_800D3E6C(entry->local_2) == 0) {
    return 1;
}

}
break;
case 2:
    if (_gcfrontend_entrypoint_3(entry->local_2)) {
        return 1;
    }
    break;
case 3:
    if (func_800DA298(0xC0C)) {
        return 1;
    }
    }
    return 0;
    }

// Updates per-letter glow and registers the vertex colour callback.
    void func_80800BF4_chcoderoombits(actor) Actor *actor;
    {
        Broad42CodeAnimation *cell;
        u8 *state;
        s32 i;
        s32 glid;
        s32 actor_id;

        state = func_80100094(actor, 0);
        actor_id = (s32) actor->unk0;
        glid = func_800BEA88(0);
        for (i = 0, cell = (Broad42CodeAnimation *) state; i != 0x1A;
             i++, cell = (Broad42CodeAnimation *) ((u8 *) cell + 0xC)) {
            switch (cell->local_3) {
                case 0:
                    cell->local_1 = 0.0f;
                    break;

case 1:
    if (func_800D91EC(&cell->local_2, 0.2f)) {
        cell->local_3 = 2;
    }

cell->local_1 = func_800F10B4(cell->local_2, 0.0f, 0.2f, 0.0f, 1.0f);
break;
case 2:
    cell->local_1 = 1.0f;
    break;

case 3:
    if (func_800D91EC(&cell->local_2, 0.6f)) {
        cell->local_3 = 0;
    }

cell->local_1 = func_800F10B4(cell->local_2, 0.0f, 0.6f, 1.0f, 0.0f);
}
if (glid) {
    _glid_entrypoint_0(glid, i + 1, _chcoderoombits_entrypoint_2, actor_id);
}
}
}

void func_80800D90_chcoderoombits(actor, index) u8 *actor;
s32 index;
{
    u8 *entry;
    s32 state;
    f32 q;
    int t;
    entry = (u8 *) func_80100094(actor, 0) + index * 12;
    state = *((s32 *) (entry + 0x24));
    switch (state) {
        case 3:
            // Matching: empty triple test keeps the constant 1 in a1 early.
            t = !entry;
            if (t && t && t) {
            }
            *((s32 *) (entry + 0x24)) = 1;
            q = (0.6f - *((f32 *) (entry + 0x20))) / 0.6f;
            *((f32 *) (entry + 0x20)) = q * 0.2f;
            break;
        case 0:
            *((s32 *) (entry + 0x24)) = 1;
            *((f32 *) (entry + 0x20)) = 0.0f;
        case 1:
        case 2:
            break;
    }
}

void func_80800E28_chcoderoombits(actor) Actor *actor;
{
    CodeRoomCells *cells;
    s32 i;
    f32 progress;

    cells = (CodeRoomCells *) func_80100094(actor, 0);
    for (i = 0; i < 26; i++) {
        switch (cells->local_0[i].local_2) {
            case 0:
            case 3:
                break;
            case 1:
                progress = (0.2f - cells->local_0[i].local_1) / 0.2f;
                cells->local_0[i].local_2 = progress * 0.6f;
                break;
            case 2:
                cells->local_0[i].local_2 = 3;
                cells->local_0[i].local_1 = 0.0f;
        }
    }
}
// Vertex colour callback: tints a letter by its glow value.
void chcoderoombits_entrypoint_2(s32 index, Vtx *src, Vtx *dst, s32 count,
                                 Unk80132ED0 *glid_ctx)
{
    Actor *actor;
    Vtx *end;
    CodeRoomColors1482 *colors;
    u8 color[4];

    actor = func_80106790(glid_ctx);
    colors = func_80100094(actor, 0);
    func_800F3320(color, src->v.cn, D_80801318_chcoderoombits,
                  colors->local_0[index].local_0);
    end = count + src;
    while (src < end) {
        func_800F2EA0(dst->v.cn, color);
        src++;
        dst++;
    }
}
// Counts unlocked cheats (ids 1..12).
int func_80800FDC_chcoderoombits()
{
    s32 i;
    s32 count = 0;
    for (i = 1; i < 0xD; i++) {
        // Matching: the "| 0" is needed for the match.
        if (func_800D3E14(i | 0)) {
            count++;
        }
    }

    return count;
}
