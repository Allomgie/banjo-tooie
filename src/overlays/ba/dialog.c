// Player-started dialog helper: opens a dialog at the player whose close callback sends interrupt
// 0x81 to the player, plus a variant that sets a game flag once the dialog actually started.
#include "common.h"

extern s32 _badialog_entrypoint_0;
extern s32 _badialog_entrypoint_1;
extern s32 _badialog_entrypoint_2;

// Dialog close callback: sends interrupt 0x81 to the player.
int badialog_entrypoint_0(void *dialog, s32 unk_1, s32 unk_2)
{
    s32 player;
    player = func_800F53D0((*(u16 *) ((char *) dialog + 0x1A) & 0xFFFFFFFFu) >> 5);
    func_8009AD20(player, unk_1);
    func_8009AD2C(player, unk_2);
    func_8009E7C8(player, 0x81);
}

void badialog_entrypoint_1(s32 unk_0, s32 unk_1, s32 unk_2)
{
}

s32 badialog_entrypoint_2(s32 unk_0, s32 unk_1, s32 unk_2)
{
    return 0;
}

// Starts a dialog at the player's position.
int badialog_entrypoint_3(s32 player, s32 unk_1, s32 unk_2)
{
    s32 pos[3];
    s32 unk_0;
    func_8009C128(player, pos);
    // Matching: the "| 0" is needed for the match.
    unk_0 = func_8008E938(player) | 0;
    func_800C0534(unk_1, unk_2, pos, unk_0, &_badialog_entrypoint_0,
                  &_badialog_entrypoint_1, &_badialog_entrypoint_2, 0);
}

// Like entrypoint_3, but only once per game flag; the flag is set when the dialog started.
int badialog_entrypoint_4(s32 player, s32 unk_1, s32 unk_2, s32 flag)
{
    // Matching: needed for the match.
    if (func_800DA298(flag | 0) != 0) {
        return 0;
    }
    if (badialog_entrypoint_3(player, unk_1, unk_2)) {
        func_800DA3B8(flag, 1);
    }
    return func_800DA298(flag);
}
