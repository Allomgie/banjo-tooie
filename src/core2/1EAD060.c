// Most likely the session state D_8012B3F0: save slot, game mode byte and flags, a snapshot/restore
// of game data, and a queue of deferred commands run later by func_800D37FC.
#include "common.h"

extern u8 D_8012762C;
extern s8 D_8012B3F1;
// TU-NOTE: both structs overlay the session state D_8012B3F0.
typedef struct {
    s8 pending_slot;
    s8 slot;
    u8 game_mode;
    u8 unk_3;
    u8 pad_4[2];
    s16 heap_block;
    s8 saved_slot;
    u8 state;
    u8 saved_mode;
    u8 saved_unk_3;
} S8012B3F0;
typedef struct {
    u8 pending_slot;
    s8 slot;
    u8 game_mode;
    u8 unk_3;
    u8 pad_4[2];
    s16 heap_block;
    u8 saved_slot;
    u8 state;
    u8 saved_mode;
    u8 saved_unk_3;
} G_D389C;
extern void _glsavegame_entrypoint_7();
extern s16 func_8001B668(s32, s32);
extern s32 func_8001B798();
extern void _glgamedata_entrypoint_1(s32);
extern u8 D_8012B3F2;
extern s16 D_8012B3FC;
extern int func_800B2DC0(int a0, int a1);
extern u8 D_8012B3F3;
extern s32 func_800DA544;
extern void func_800C70B0(void);
extern void func_800D1864();
extern void func_800DC324();
typedef void (*func_ptr_t)();
extern u8 D_8012B3F4;
extern u8 D_8012B3F5;
extern u8 D_8012B3F0;
int func_800D3A14();
int func_800D3B6C();
void func_800D3C70();
int func_800D3CF8();
int func_800D3D10();

int func_800D3770(void)
{
    s32 unk_0 = D_8012762C;
    s32 in_range = unk_0 >= 0xF && unk_0 < 0x1C;
    if (unk_0 == 0x11)
        in_range = 0;
    return D_8012B3F1 + 1 != 0 && in_range;
}

void func_800D37C0(s32 slot)
{
    ((u8 *) &D_8012B3F0)[0] = slot;
    ((u8 *) &D_8012B3F0)[1] = slot;
}

int func_800D37D4()
{
    ((s8 *) &D_8012B3F0)[1] = -1;
    ((s8 *) &D_8012B3F0)[0] = ((s8 *) &D_8012B3F0)[1];
}

s8 func_800D37F0()
{
    return D_8012B3F1;
}

// Restores the game-data snapshot (state 3), applies the pending slot, runs queued commands.
void func_800D37FC(void)
{
    if ((*(S8012B3F0 *) &D_8012B3F0).state == 3) {
        _glgamedata_entrypoint_2(func_8001B798((*(S8012B3F0 *) &D_8012B3F0).heap_block));
        func_8001B754((*(S8012B3F0 *) &D_8012B3F0).heap_block);
        (*(S8012B3F0 *) &D_8012B3F0).slot = (*(S8012B3F0 *) &D_8012B3F0).saved_slot;
        (*(S8012B3F0 *) &D_8012B3F0).unk_3 = (*(S8012B3F0 *) &D_8012B3F0).saved_unk_3;
        (*(S8012B3F0 *) &D_8012B3F0).game_mode = (*(S8012B3F0 *) &D_8012B3F0).saved_mode;
        (*(S8012B3F0 *) &D_8012B3F0).state = 0;
        (*(S8012B3F0 *) &D_8012B3F0).saved_slot = -1;
        (*(S8012B3F0 *) &D_8012B3F0).heap_block = 0;
    }
    if ((*(S8012B3F0 *) &D_8012B3F0).pending_slot != -1) {
        _glsavegame_entrypoint_8((*(S8012B3F0 *) &D_8012B3F0).pending_slot);
        (*(S8012B3F0 *) &D_8012B3F0).pending_slot = -1;
    }
    func_800D3C70();
}

// Snapshots the game data into a heap block (state 1 -> 2).
void func_800D389C(void)
{
    if (func_800D3770() != 0) {
        _glsavegame_entrypoint_7((*(G_D389C *) &D_8012B3F0).slot);
    }
    if ((*(G_D389C *) &D_8012B3F0).state == 1) {
        (*(G_D389C *) &D_8012B3F0).heap_block = func_8001B668(0, 0x1C0);
        _glgamedata_entrypoint_1(func_8001B798((*(G_D389C *) &D_8012B3F0).heap_block));
        (*(G_D389C *) &D_8012B3F0).saved_slot = (*(G_D389C *) &D_8012B3F0).slot;
        (*(G_D389C *) &D_8012B3F0).saved_unk_3 = (*(G_D389C *) &D_8012B3F0).unk_3;
        (*(G_D389C *) &D_8012B3F0).saved_mode = (*(G_D389C *) &D_8012B3F0).game_mode;
        (*(G_D389C *) &D_8012B3F0).slot = -1;
        (*(G_D389C *) &D_8012B3F0).state = 2;
    }
}

// Game mode == 1.
int func_800D3934()
{
    u8 *mode = &D_8012B3F2;
    return *mode == 1;
}

// Game mode == 3.
int func_800D3948()
{
    u8 *mode = &D_8012B3F2;
    return *mode == 3;
}

// Game mode == 2.
int func_800D395C()
{
    u8 *mode = &D_8012B3F2;
    return *mode == 2;
}

int func_800D3970()
{
    func_800D37D4();
    func_800D3A14(1);
    // Matching: needed for the match.
    func_800D3CF8(0 | 0);
    func_800D3D10(1);
}

// Creates the deferred-command queue.
void func_800D39A8()
{
    D_8012B3FC = func_800B2DC0(0x14, 1);
}

int func_800D39D0(int mode)
{
    // Matching: needed for the match.
    int value;
    value = mode;
    D_8012B3F2 = value;
}

// Queues a game-mode change.
s32 func_800D39DC(s32 mode)
{
    // Matching: needed for the match.
    void *arg;
    if (mode >= 0) {
        arg = mode;
        func_800D3B6C(1, &func_800D39D0, arg, 0, 0);
    }
}

int func_800D3A14(value)
int value;
{
    // Matching: needed for the match.
    int copy;
    copy = value;
    D_8012B3F3 = copy;
}

void func_800D3A20(s32 arg)
{
    // Matching: the chained temporaries are needed for the match.
    int zero_copy;
    int zero;
    zero = 1 * 0;
    zero_copy = zero;
    func_800D3B6C(1, &func_800DA544, arg, zero_copy, zero);
}

void func_800D3A54(s32 arg0, s32 arg1)
{
    func_800D3B6C(2, &func_800C70B0, arg0, arg1, (s32 *) 0);
}

int func_800D3A88()
{
    extern void func_800C7010();
    func_800D3B6C(0, func_800C7010, 0, 0, 0);
}

void func_800D3ABC(s32 arg0, void *arg1)
{
    func_800D3B6C(3, &func_800D1864, arg0, arg1, 0);
}

int func_800D3AF0(s32 arg0)
{
    func_800D3B6C(3, &func_800D1864, arg0, 1000, 0);
}

// Queues an RNG reseed with the current counter.
s32 func_800D3B24(void)
{
    u32 seed = osGetCount();
    func_800D3B6C(1, &func_800DC324, seed, 0, 0);
}

u8 func_800D3B60()
{
    return D_8012B3F3;
}

// Appends a deferred command {argc, fn, args[3]} to the queue.
int func_800D3B6C(argc, fn, arg0, arg1, arg2)
s32 argc;
s32 fn;
s32 arg0;
s32 arg1;
s32 arg2;
{
    Actor *cmd = func_800B2A58(D_8012B3FC);
    *(u8 *) ((char *) cmd + 0x0) = argc;
    *(s32 *) ((char *) cmd + 0x4) = fn;
    *(s32 *) ((char *) cmd + 0x8) = arg0;
    *(s32 *) ((char *) cmd + 0xC) = arg1;
    *(s32 *) ((char *) cmd + 0x10) = arg2;
}

// Runs one queued command with its argc arguments.
void func_800D3BC8(u8 *cmd)
{
    switch (cmd[0]) {
        case 0:
            ((func_ptr_t) ((u32 *) cmd)[1])();
            break;

        case 1:
            ((func_ptr_t) ((u32 *) cmd)[1])((u32) ((u32 *) cmd)[2]);
            break;

        case 2:
            ((func_ptr_t) ((u32 *) cmd)[1])((u32) ((u32 *) cmd)[2],
                                            (u32) ((u32 *) cmd)[3]);
            break;

        case 3:
            ((func_ptr_t) ((u32 *) cmd)[1])(
                (u32) ((u32 *) cmd)[2], (u32) ((u32 *) cmd)[3], (u32) ((u32 *) cmd)[4]);
    }
}

// Runs all queued commands, then frees the queue.
void func_800D3C70(void)
{
    s32 vec;
    u32 end;
    u32 cmd;

    if (D_8012B3FC != 0) {
        vec = func_800B2890(D_8012B3FC);
        cmd = vector_begin(vec);
        end = vector_end(vec);
        if (cmd < end) {
            do {
                func_800D3BC8(cmd);
                cmd += 0x14;
            } while (cmd < end);
        }
        func_800B2D48(D_8012B3FC);
        D_8012B3FC = 0;
    }
}

int func_800D3CF8(value)
unsigned long value;
{
    D_8012B3F4 = value;
}

s32 func_800D3D04(void)
{
    return *(u8 *) &D_8012B3F4;
}

int func_800D3D10(value)
long value;
{
    // Matching: needed for the match.
    unsigned long long copy;
    copy = value;
    D_8012B3F5 = copy;
}

u8 func_800D3D1C()
{
    return D_8012B3F5;
}

// Requests a snapshot (state 0 -> 1); returns 0 if one is already in progress.
s32 func_800D3D28()
{
    u8 *p = (u8 *) &D_8012B3F0;
    if (p[9] != 0) {
        return 0;
    }
    ((u8 *) &D_8012B3F0)[9] = 1;
    return 1;
}

// Advances the snapshot state: 1 -> 0, 2 -> 3 (restore).
s32 func_800D3D58(void)
{
    switch (*(u8 *) ((s8 *) &D_8012B3F0 + 9)) {
        case 1:
            *(u8 *) ((s8 *) &D_8012B3F0 + 9) = 0U;
            return 1;
        case 2:
            *(u8 *) ((s8 *) &D_8012B3F0 + 9) = 3U;
            return 1;
        default:
            return 0;
    }
}

int func_800D3DA4()
{
    func_800F54F0();
}
