// Score board for multiplayer and score-based minigames: ranks players with tie detection,
// stores tournament results, and lays out, animates and draws the per-viewport score cards.
#include "common.h"

typedef struct {
    u8 pad_0;
    u8 type;
    s16 icon;
    u8 visible;
    u8 finished;
    u8 value;
    u8 pad_1;
    s16 score;
    u8 pad_2[6];
    f32 amount;
    f32 progress;
    s32 pad_3;
    s32 selection;
} MultiScoreCard;
typedef struct {
    u8 pad_0[0x18];
    MultiScoreCard cards[9];
    s32 owner;
} MultiScoreCardRow;
extern s32 D_808014B0_sumultiscore[];
extern f32 func_800D8FF8(void);
extern s32 func_800F1418(s32 param_0, s32 param_1);
typedef struct {
    u8 pad[8];
    s16 f8;
    u8 padA[0xA];
    f32 f14;
    u8 pad18[8];
} ScoreSub;
typedef struct {
    u8 pad[0x40];
    ScoreSub sub[7];
    u8 pad2[0x13C - 0x40 - 0xE0];
} ScorePl;
typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    u8 padE[0xE];
    f32 unk1C;
} MultiScoreEntry;
typedef struct {
    u8 pad0[0x3C];
    MultiScoreEntry unk3C[8];
} MultiScoreRow;
typedef struct {
    u8 pad0[6];
    u8 unk6;
    u8 pad7[0x19];
} ScoreEntry;
typedef struct {
    u8 pad0[0x18];
    ScoreEntry entries[9];
    u8 pad138[4];
} ScorePlayer;
typedef struct {
    s32 unk0;
    u8 pad4[0x24];
    ScorePlayer players[4];
    s32 unk518;
} MultiScore;
extern void func_800B8C50(void);
extern void func_800B8C98();
extern void func_800B8CBC(s32, s32, s32);
extern void func_800B7F14(s32);
extern void func_800B811C(s32);
typedef struct {
    u8 pad_0;
    u8 pos_index;
    u16 sprite;
    u8 unk_4;
    u8 unk_5;
    u8 pad_1[6];
    s8 offset_x;
    s8 offset_y;
    u8 pad_2[2];
    f32 unk_10;
} MultiScoreDrawItem;
extern int _fxdialog_entrypoint_2(f32);
extern void _fxdialog_entrypoint_4(s32, s32, s32, f32, f32, s32, s32);
typedef struct {
    u16 x;
    u16 y;
} MultiScorePosition;
extern f32 mlAbsF(f32);
extern f32 func_800138D0(f32);
typedef struct {
    u8 pad[0x13C];
} E13C;
extern int func_800F1574(f32 *, f32);
extern f32 func_80013970(f32);
typedef struct {
    s16 pad_0, sound;
    u8 pad_1[6];
    s8 offset;
    u8 pad_2;
    s8 adjustment;
    u8 pad_3[3];
    f32 duration;
} MultiScoreState1436;
extern int _gcstatusDll_entrypoint_13(s32);
void sumultiscore_entrypoint_9();
void func_80801160_sumultiscore();
void sumultiscore_entrypoint_4();
void func_80800BFC_sumultiscore();
void func_808011E0_sumultiscore();
void func_80801340_sumultiscore();

// Insertion sort of keys, descending; values move along.
void sumultiscore_entrypoint_0(s32 *keys, s32 *values, s32 count)
{
    s32 i;
    s32 j;
    s32 tmp;
    for (i = 1; i < count; i++) {
        for (j = i; j > 0 && keys[j - 1] < keys[j]; j--) {
            tmp = keys[j];
            keys[j] = keys[j - 1];
            keys[j - 1] = tmp;
            tmp = values[j];
            values[j] = values[j - 1];
            values[j - 1] = tmp;
        }
    }
}

// Insertion sort of keys, ascending; values move along.
void sumultiscore_entrypoint_1(s32 *keys, s32 *values, s32 count)
{
    s32 i;
    s32 j;
    s32 tmp;
    for (i = 1; i < count; i++) {
        for (j = i; j > 0 && keys[j] < keys[j - 1]; j--) {
            tmp = keys[j];
            keys[j] = keys[j - 1];
            keys[j - 1] = tmp;
            tmp = values[j];
            values[j] = values[j - 1];
            values[j - 1] = tmp;
        }
    }
}

// Assigns ranks over sorted scores; equal scores share a rank and are flagged in tied.
void func_80800140_sumultiscore(s32 *scores, s32 *tied, s32 *ranks, s32 count)
{
    s32 i;
    s32 rank;

    rank = 1;
    for (i = 0; i < count; i++) {
        if (rank >= 2 && scores[i] == scores[i - 1]) {
            ranks[i] = ranks[i - 1];
            tied[i] = 1;
            tied[i - 1] = 1;
        } else {
            ranks[i] = rank;
        }
        rank++;
    }
}

// Ranks the players by score. Returns the winning player number (1-based), or 0 on a tie for first.
s32 sumultiscore_entrypoint_2(s32 *scores, s32 *ranks, s32 *tied, s32 ascending, s32 count)
{
    s32 order[4];
    s32 sorted_ranks[4];
    s32 sorted_scores[4];
    s32 sorted_tied[4];
    s32 i;
    s32 num_players;

    for (i = 0; i < count; i++) {
        order[i] = i;
        sorted_scores[i] = scores[i];
        sorted_tied[i] = 0;
    }
    if (ascending == 0) {
        sumultiscore_entrypoint_0(sorted_scores, order, count);
        func_800AA200(0);
    } else {
        sumultiscore_entrypoint_1(sorted_scores, order, count);
        func_800AA200(1);
    }
    func_80800140_sumultiscore(sorted_scores, sorted_tied, sorted_ranks, count);
    for (i = 0; i < count; i++) {
        ranks[order[i]] = sorted_ranks[i];
        tied[order[i]] = sorted_tied[i];
    }
    if (func_800D3948()) {
        num_players = _gcstatusDll_entrypoint_11();
        for (i = 0; i < num_players; i++) {
            func_800AA20C(i, scores[i]);
        }
    }
    if (sorted_ranks[0] == sorted_ranks[1]) {
        return 0;
    }
    return order[0] + 1;
}

// Sets up the board: per-player card positions from each viewport, then adds the first card.
void sumultiscore_entrypoint_3(u8 *board)
{
    s32 i;
    u8 *player_row;
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    u8 *next_row;

    *(s32 *) ((s8 *) board + 0x518) = _gcstatusDll_entrypoint_11();
    i = 0;
    if (*(s32 *) ((s8 *) board + 0x518) > 0) {
        next_row = board + 0x28;
        do {
            player_row = next_row;
            func_800A8A04(func_800A940C(i), &x, &y, &width, &height);
            i += 1;
            next_row += 0x13C;
            *(s16 *) ((s8 *) next_row + -0x13C) = (s16) (x + 0x1C);
            *(s16 *) ((s8 *) next_row + -0x13A) = (s16) (y + 0xE);
            *(s16 *) ((s8 *) next_row + -0x138) = (s16) ((width / 2) + x);
            *(s16 *) ((s8 *) next_row + -0x136) = (s16) (y + 0xE);
            *(s16 *) ((s8 *) next_row + -0x134) = (s16) ((width + x) - 0x1C);
            *(s16 *) ((s8 *) next_row + -0x132) = (s16) (y + 0xE);
            *(s16 *) ((s8 *) next_row + -0x130) = (s16) (x + 0x1C);
            *(s16 *) ((s8 *) next_row + -0x12E) = (s16) ((height + y) - 0xE);
            *(s16 *) ((s8 *) next_row + -0x12C) = (s16) ((width + x) - 0x1C);
            *(s16 *) ((s8 *) player_row + 0x12) = (s16) ((height + y) - 0xE);
            *(s16 *) ((s8 *) player_row + 0x14) = (s16) ((width / 2) + x);
            *(s16 *) ((s8 *) player_row + 0x16) = (s16) ((height / 2) + y);
        } while (i < *(s32 *) ((s8 *) board + 0x518));
    }
    *(s32 *) ((s8 *) board + 0) = 0;
    sumultiscore_entrypoint_4(board, 0, 5, 0);
}

// Adds a card of the given kind for every player.
void sumultiscore_entrypoint_4(board, kind, type, value) u8 *board;
u32 kind;
s32 type;
s32 value;
{
    s32 i;
    u8 *card;
    u8 *player_row;

    i = 0;
    player_row = board;
    for (; i < *(s32 *) (board + 0x518); i++, player_row += 0x13C) {
        card = player_row;
        card += (*(s32 *) board << 5);
        card[0x40] = kind;
        card = card + 0x40;
        card[1] = type;
        card[6] = value;
        card[4] = 0;
        card[5] = 255;
        *(s16 *) (card + 8) = 0;
        card[0xA] = 5;
        card[0xB] = 0;
        *(s8 *) (card + 0xC) = -5;
        card[0xD] = 0;
        switch (kind) {
            case 0:
                card[5] = 0;
                break;
            case 1:
                *(s16 *) (card + 2) = 0xB4D;
                *(f32 *) (card + 0x10) = 0.4f;
                break;
            case 2:
            case 5:
                func_80801340_sumultiscore(card, i);
                break;
            case 3:
                *(s16 *) (card + 2) = 0xB81;
                *(f32 *) (card + 0x10) = 0.5f;
                break;
            case 4:
                *(s16 *) (card + 2) = 0xC14;
                *(f32 *) (card + 0x10) = 0.5f;
                break;
            case 6:
                *(s16 *) (card + 2) = 0xB89;
                *(f32 *) (card + 0x10) = 0.75f;
                card[0xA] = 10;
                *(s8 *) (card + 0xC) -= 5;
                break;
            case 7:
                *(s16 *) (card + 2) = 0xB8B;
                *(f32 *) (card + 0x10) = 0.75f;
                *(s8 *) (card + 0xC) -= 5;
                break;
            case 8:
                func_80801340_sumultiscore(card, i);
                break;
        }
    }
    *(s32 *) (board + kind * 4 + 4) = *(s32 *) board;
    (*(s32 *) board)++;
}

void sumultiscore_entrypoint_5(u8 *board, s32 player, s32 kind, s32 selection)
{
    MultiScoreCardRow *row;
    MultiScoreCard *src;
    MultiScoreCard *dst;
    MultiScoreCard *prev;

    row = &((MultiScoreCardRow *) (board + 0x28))[player];
    src = ((s32 *) (board + 4))[kind] + row->cards;
    dst = *(s32 *) (board + 4) + row->cards;
    if (row->owner) {
        prev = ((s32 *) (board + 4))[row->owner] + row->cards;
        prev->value = dst->value;
    }
    row->owner = kind;
    dst->type = src->type;
    dst->amount = src->amount;
    dst->selection = selection;
    dst->value = src->value;
    src->value = 0;
    if (kind == 3) {
        dst->icon = D_808014B0_sumultiscore[selection];
        dst->visible = 0;
        dst->score = _badeathmatch_entrypoint_9(func_800F53D0(player), selection);
        dst->finished = 0;
        dst->progress = 1.0f;
    }
}

void func_80800E84_sumultiscore();

void func_80800DD0_sumultiscore();

void func_80800D64_sumultiscore();

void func_80800D54_sumultiscore();

// Per-frame update: animates card blinking and runs each card's type handler.
void sumultiscore_entrypoint_6(u8 *board)
{
    s32 player;
    s32 slot;
    u8 *player_row;
    u8 *raw;
    u8 *card;
    f32 phase;

    player = 0;
    if (*(s32 *) (board + 0x518) > 0) {
        do {
            slot = 0;
            if (*(s32 *) board > 0) {
                player_row = board + 0x28 + player * 0x13C;
                do {
                    raw = (u8 *) ((s32) player_row + (slot << 5));
                    card = raw + 0x18;
                    if (*(f32 *) (raw + 0x30) != 0.0f) {
                        func_800F1574((f32 *) (card + 0x18), func_800D8FF8());
                        phase = *(f32 *) (card + 0x18);
                        phase = phase - (f32) (s32) phase;
                        *(u8 *) (card + 5) =
                            (s32) (mlAbsF(func_800138D0(phase * 720.0f)) * 255.99f);
                    }
                    switch (*card) {
                        case 0:
                            func_80800BFC_sumultiscore(board, player, card);
                            break;
                        case 1:
                            func_80800D24_sumultiscore(board, player, card);
                            break;
                        case 2:
                            func_80800D54_sumultiscore(board, player, card);
                            break;
                        case 3:
                            func_80800D64_sumultiscore(board, player, card);
                            break;
                        case 4:
                            func_80800DD0_sumultiscore(board, player, card);
                            break;
                        case 5:
                            func_80800E84_sumultiscore(board, player, card);
                    }
                    slot++;
                } while (slot < *(s32 *) board);
            }
            player++;
        } while (player < *(s32 *) (board + 0x518));
    }
}

void func_80800BFC_sumultiscore(board, player, card) u8 *board;
s32 player;
u8 *card;
{
    f32 phase;
    s32 selection;
    u8 *player_row;
    u8 *unk_0;

    if (card[6]) {
        player_row = (u8 *) &((E13C *) board)[player];
        if (*(s32 *) (player_row + 0x160) == 3) {
            selection = *(s32 *) (card + 0x1C);
            *(s16 *) (card + 8) = _badeathmatch_entrypoint_9(func_800F53D0(player), selection);
        }
        if (func_800F1574((f32 *) (card + 0x14), func_800D8FF8())) {
            u8 *dst = player_row + ((s32 *) board)[*(s32 *) (player_row + 0x160) + 1] * 0x20 + 0x40;
            dst[6] = card[6];
            *(s32 *) (player_row + 0x160) = 0;
            card[6] = 0;
        } else {
            phase = *(f32 *) (card + 0x14);
            phase -= (s32) phase;
            card[5] = (s32) (mlAbsF(func_80013970(phase * 720.0f)) * 255.99f);
        }
    }
}

int func_80800D24_sumultiscore(s32 board, s32 player, s16 *card)
{
    s32 score;
    // Matching: "| 0" is needed for the match.
    score = func_800F5578(player | 0);
    card[4] = score;
}

void func_80800D54_sumultiscore(s32 arg0, s32 arg1, s32 arg2)
{
}

void func_80800D64_sumultiscore(s32 board, s32 player, u8 *card)
{
    s32 selection;

    selection = _badeathmatch_entrypoint_6(func_800F53D0(player));
    ((s16 *) card)[1] = D_808014B0_sumultiscore[selection];
    ((s16 *) card)[4] = _badeathmatch_entrypoint_9(func_800F53D0(player), selection);
}

void func_80800DD0_sumultiscore(s32 board, s32 player, u8 *card)
{
    u8 alpha;

    if (*(f32 *) ((u8 *) card + 0x14) != 0.0f) {
        func_800F1574(card + 0x14, func_800D8FF8());
        if (*(u8 *) ((u8 *) card + 6) == 0) {
            *(u8 *) ((u8 *) card + 6) = 1U;
            *(u8 *) ((u8 *) card + 5) = 0U;
            return;
        }
        *(u8 *) ((u8 *) card + 5) = func_800F1418(*(u8 *) ((u8 *) card + 5) + 0x20, 0xFF);
        return;
    }
    if (*(u8 *) ((u8 *) card + 6) != 0) {
        alpha = *(u8 *) ((u8 *) card + 5);
        if ((s32) alpha >= 0x21) {
            *(u8 *) ((u8 *) card + 5) = (u8) (alpha - 0x20);
            return;
        }
        *(u8 *) ((u8 *) card + 6) = 0U;
    }
}

void func_80800E84_sumultiscore(s32 arg0, s32 arg1, s32 arg2)
{
}

void sumultiscore_entrypoint_7(ScorePl *board, s32 player, s32 slot, s32 delta)
{
    s32 card = ((s32 *) ((u8 *) board + 4))[slot];
    delta += board[player].sub[card].f8;
    sumultiscore_entrypoint_9(board, player, slot, delta);
}

s16 sumultiscore_entrypoint_8(MultiScoreRow *board, s32 player, s32 slot)
{
    s32 card;

    card = ((s32 *) ((u8 *) board + 4))[slot];
    return board[player].unk3C[card].unkC;
}

// Matching: the extra temporaries (card_ptr, player_offset) are needed for the match.
void sumultiscore_entrypoint_9(board, player, slot, score) u8 *board;
s32 player;
s32 slot;
u32 score;
{
    u8 *card_ptr;
    s32 card;
    u8 *player_row;
    int player_offset;
    player_offset = player * 316;
    player_row = board + player_offset;
    card = *((s32 *) (board + 4) + slot);
    *(s16 *) ((player_row + (card * 32)) + 0x48) = score;
    if (slot == 4) {
        u32 card_offset = card * 32;
        card_ptr = player_row + card_offset;
        *(f32 *) (card_ptr + 0x54) = 1.0f;
    }
}

// Matching: the assignment inside the expression is needed for the match.
void sumultiscore_entrypoint_10(u8 *board, s32 player)
{
    s32 card_index;
    *(s8 *) ((s8 *) ((board + (player * 0x13C)) +
                     ((card_index = *(s32 *) (board - -0x18)) << 5)) +
             0x47) = 1;
}

void sumultiscore_entrypoint_11(MultiScoreRow *board, s32 player, s32 slot, f32 value)
{
    s32 card;

    card = ((s32 *) ((u8 *) board + 4))[slot];
    board[player].unk3C[card].unk1C = value;
}

void sumultiscore_entrypoint_12(MultiScore *board, s32 gfx, s32 value)
{
    s32 i;
    s32 j;
    ScorePlayer *player_row;

    for (i = 0; i < board->unk518; i++) {
        player_row = &board->players[i];
        for (j = 0; j < board->unk0; j++) {
            if (value == player_row->entries[j].unk6) {
                func_80801160_sumultiscore(player_row, player_row->entries + j, gfx);
            }
        }
    }
    func_800B8C50();
    func_800B8C98(3);
    func_800B8CBC(0xFF, 0xFF, 0xFF);
    func_800B7F14(gfx);
    for (i = 0; i < board->unk518; i++) {
        player_row = &board->players[i];
        for (j = 0; j < board->unk0; j++) {
            if (value == player_row->entries[j].unk6) {
                func_808011E0_sumultiscore(player_row, player_row->entries + j, i, gfx);
            }
        }
    }
    func_800B811C(gfx);
}

void func_80801160_sumultiscore(positions, item, gfx) MultiScorePosition *positions;
MultiScoreDrawItem *item;
s32 gfx;
{
    MultiScorePosition *pos;
    s32 draw_x;
    s32 draw_y;
    pos = positions;
    pos += item->pos_index;
    draw_x = item->offset_x + pos->x;
    draw_y = item->offset_y + pos->y;
    _fxdialog_entrypoint_1(draw_x, draw_y);
    _fxdialog_entrypoint_2(item->unk_10);
    _fxdialog_entrypoint_4(gfx, item->sprite, item->unk_4, 0.0f, 0.0f,
                           item->unk_5, 0);
}

void func_808011E0_sumultiscore(positions, card, player, gfx) u16 positions[][2];
u8 *card;
s32 player;
s32 gfx;
{
    char text[16];
    s32 x = positions[card[1]][0] + *(s8 *) (card + 10);
    s32 y = positions[card[1]][1] + *(s8 *) (card + 11);
    s32 alpha;

    if (card[0] == 5) {
        alpha = card[7] && func_8001210C(8) ? card[5] : card[5] >> 1;
        func_800B8C98(0, alpha);
        func_800B8C8C(alpha);
        func_800B80D0(gfx);
        sprintf(text, "PLAYER %d", player + 1);
        func_800B8E28(gfx, x - 32, y - 12, text);
    }
    alpha = (s32) ((f32) (u32) card[5] * 0.667f);
    func_800B8C98(3, alpha);
    func_800B8C8C(alpha);
    func_800B80D0(gfx);
    sprintf(text, "%d", *(s16 *) (card + 8));
    func_800B8E28(gfx, x, y, text);
}

// Matching: the line breaks in this function are needed for the match.
void func_80801340_sumultiscore(state, player) MultiScoreState1436 *state; s32 player;
{
    switch (_gcstatusDll_entrypoint_13(player)) {
        default:
        state->sound = 0xB50; state->offset += 10; state->duration = 0.5f;
        break;
        case 2:
        state->sound = 0xBD9;
        state->duration = 0.6f;
        state->adjustment -= 5;
        break;
        case 3:
        state->sound = 0xBD0;
        state->duration = 0.6f;
        state->adjustment -= 5;
        break;
        case 4:
        state->sound = 0xBAB;
        state->duration = 0.7f;
        state->adjustment -= 7;
        break;
        case 5:
        state->sound = 0xBA2;
        state->duration = 0.6f;
        state->adjustment -= 6;
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
s32 D_808014B0_sumultiscore[8] = {0x0, 0xB81, 0xB83, 0xB82, 0xB84, 0xB85, 0x9C5, 0x9C3};
