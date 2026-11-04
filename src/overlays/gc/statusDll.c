// Probably the multiplayer setup block D_8012B3FC: player count, per-player character and team
// bytes, game type and options, and a map id (default 0x173), with getters, setters and defaults.
#include "common.h"

typedef struct {
    s32 unk0;
    u8 unk4;
    u8 pad5[4];
    u8 unk9;
    u8 padA[5];
    u8 unkF;
    u8 unk10;
    u8 unk11;
} StatusB400;
extern StatusB400 D_8012B400;
// D_8012B3FC: multiplayer setup block (player count, per-player character and team, game type, options, map id).
extern u8 D_80800230_gcstatusDll[4][2];
extern u8 D_8012B3FC[];
extern u8 D_8012762C;
void gcstatusDll_entrypoint_3();
void gcstatusDll_entrypoint_6();

// Set the default multiplayer setup.
void gcstatusDll_entrypoint_0(void)
{
    s32 i;

    D_8012B400.unk4 = 2;
    for (i = 0; i < 4; i++) {
        gcstatusDll_entrypoint_3(i, D_80800230_gcstatusDll[i][0]);
        gcstatusDll_entrypoint_6(i, D_80800230_gcstatusDll[i][1]);
    }
    D_8012B400.unk9 = 1;
    D_8012B400.unkF = 0;
    D_8012B400.unk10 = 0;
    D_8012B400.unk11 = 2;
    D_8012B400.unk0 = 0x173;
}

void gcstatusDll_entrypoint_1(s32 value)
{
    *(s32 *) ((u8 *) (u8 *) D_8012B3FC + 0x4) = value;
}

void gcstatusDll_entrypoint_2(long player_count)
{
    *(u8 *) ((u8 *) (u8 *) D_8012B3FC + 0x8) = player_count;
}

void gcstatusDll_entrypoint_3(player, character) s32 player;
s32 character;
{
    D_8012B3FC[player + 9] = character;
}

void gcstatusDll_entrypoint_4(long value)
{
    *(u8 *) ((u8 *) (u8 *) D_8012B3FC + 0xd) = value;
}

int gcstatusDll_entrypoint_5(s32 value)
{
    u8 *status = (u8 *) D_8012B3FC;
    status[0x12] = value;
}

void gcstatusDll_entrypoint_6(player, team) s32 player;
s32 team;
{
    D_8012B3FC[player + 0xE] = team;
}

int gcstatusDll_entrypoint_7(int value)
{
    u8 *status = &D_8012B3FC;
    status[0x13] = value;
}

void gcstatusDll_entrypoint_8(long value)
{
    *(u8 *) ((u8 *) (u8 *) D_8012B3FC + 0x14) = value;
}

int gcstatusDll_entrypoint_9(unsigned int value)
{
    D_8012B3FC[0x15] = value;
}

int gcstatusDll_entrypoint_10()
{
    u8 *status = &D_8012B3FC;
    return status[8];
}

// Player count; 1 outside the multiplayer level.
int gcstatusDll_entrypoint_11()
{
    u8 count;
    u8 *status = &D_8012B3FC;
    count = status[8];
    if (D_8012762C != 0x1B) {
        return 1;
    }
    return count;
}

int gcstatusDll_entrypoint_12()
{
    return ((int *) D_8012B3FC)[1];
}

int gcstatusDll_entrypoint_13(s32 player)
{
    u8 *status = &D_8012B3FC;
    return status[player + 9];
}

// Matching: the odd address arithmetic and `^ 0` are needed for the match.
s32 gcstatusDll_entrypoint_14(void)
{
    s32 addr;
    unsigned int value;
    u8 *status = (u8 *) (s32 *) D_8012B3FC;
    int index;
    addr = 0x0000000E;
    addr--;
    index = addr;
    return (value = status[index]) ^ 0;
}

int gcstatusDll_entrypoint_15()
{
    u8 *field = &D_8012B3FC[0x12];
    return *field;
}

int gcstatusDll_entrypoint_16(s32 player)
{
    u8 *teams = &*(u8 *) ((u8 *) (u8 *) D_8012B3FC + 0xe);
    return teams[player];
}

int gcstatusDll_entrypoint_17()
{
    u8 value;
    u8 *status = &D_8012B3FC;
    return value = status[0x13];
}

int gcstatusDll_entrypoint_18()
{
    u8 value;
    u8 *status = (u8 *) D_8012B3FC;
    value = status[0x14];
    return value;
}

unsigned int gcstatusDll_entrypoint_19(void)
{
    unsigned char value;
    value = ((s8 *) D_8012B3FC)[0x15];
    return value;
}

// Does the current game type need special first-person handling?
int gcstatusDll_entrypoint_20()
{
    int game_type;
    if (func_800D3948()) {
        game_type = gcstatusDll_entrypoint_14();
        switch (game_type) {
            case 0:

            case 4:
                break;

            case 3:
            case 5:
                return 1;

            case 6:

                break;
        }
    }
    return 0;
}

// TU-NOTE: the .data table below is defined in C so IDO schedules the functions as in the original.
u8 D_80800230_gcstatusDll[4][2] = {0x1, 0x0, 0x2, 0x1, 0x4, 0x2, 0x5, 0x3};
