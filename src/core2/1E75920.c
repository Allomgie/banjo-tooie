#include "core2/1E75920.h"

extern void func_800EFD24();
// Position block at +0xE4: position, previous, two frames ago, pending delta (+0x24).
typedef struct {
    u8 pad_0[0xE4];
    s32 pos_block;
} ActorLocal_CC_510;
typedef struct {
    ActorLocal_CC_510 local;
} Actor_8009C08C;
typedef struct {
    u8 pad_0[0xE4];
    void *pos_block;
} Actor_8009C0BC;
extern void func_800EE7F8();

typedef struct {
    u8 pad_0[0xE4];
    void *pos_block;
} Actor_8009C0F8;
s32 func_8009C030()
{
    return 0x30;
}

void func_8009C038(void *player)
{
    func_800EFD24(*(s32 *) ((char *) player + 0xe4) + 0x24);
    func_800EFD24(*(s32 *) ((char *) player + 0xe4));
    func_800EFD24(*(s32 *) ((char *) player + 0xe4) + 0xc);
    func_800EFD24(*(s32 *) ((char *) player + 0xe4) + 0x18);
}

void func_8009C08C(Actor_8009C08C *player)
{
    ActorLocal_CC_510 *local;
    local = &player->local;
    func_8009C21C();
    func_800EFD24((void *) (local->pos_block + 0x24));
}

void func_8009C0BC(Actor_8009C0BC *player, s32 pos)
{
    func_800EE7F8(player->pos_block);
    func_800EE7F8((void *) ((char *) player->pos_block + 0xC), pos);
}

void func_8009C0F8(Actor_8009C0F8 *player)
{
    func_800EE7F8(player->pos_block);
}

// Sets the Y coordinate of the position.
int func_8009C118(s32 player, f32 y)
{
    // Matching: the do-while, the temporaries and the `^ 0` are needed for the match.
    int addr;
    unsigned int offset;
    int addr_copy;
    do {
        offset = 0xE4;
        addr = (player ^ 0) + offset;
        addr_copy = addr;
        *(f32 *) (*(s32 *) addr_copy + 4) = y;
        0;
    } while (0);
}

void func_8009C128(PlayerState *player, f32 pos[3])
{
    func_800EE7F8(pos, *(s32 *) ((char *) player + 0xE4));
}

f32 func_8009C150(PlayerState *player)
{
    return *(f32 *) (*(s32 *) ((char *) player + 0xE4) + 0x4);
}

void func_8009C15C(PlayerState *player, f32 *out)
{
    char *ptr;
    // Matching: `if (1)` and the reused temporary are needed for the match.
    if (1) {
        ptr = out;
    }
    func_800EE7F8(ptr,
                  ptr = (char *) *(struct ba_unknown_C0_s **) ((char *) player + 0xE4) + 12);
}

s32 func_8009C188(s32 player, s32 out)
{
    func_800EE7F8(out, *(s32 *) (player + 228) + 0x18);
}

// Adds dy to the Y coordinate of the position.
void func_8009C1B4(s32 player, f32 dy)
{
    f32 *pos = *(f32 **) (player + 0xE4);
    pos[1] += dy;
}

int func_8009C1CC(s32 player, s32 out)
{
    func_800EE7F8(out, *(s32 *) (player + 228) + 0x24);
}

void func_8009C1F8(struct Actor *player)
{
    func_800EE7F8((void *) ((s32) (void *) *(s32 *) ((char *) player + 0xE4) + 0x24));
}

// Shifts position -> previous -> two frames ago.
// Old-style declaration and int return so it matches the implicit declaration
// of the earlier call (no arguments; s32 is long here).
int func_8009C21C(player)
s32 *player;
{
    s32 *block_ptr;
    s32 block;
    s32 block2;
    block_ptr = &player[57];
    block = *block_ptr;
    func_800EE7F8(block + 0x18, block + 0xC, block);
    block2 = player[57];
    func_800EE7F8(block2 + 0xC, block2 ^ 0, block2);
}

// Adds the pending displacement (+0x24) to the position, then clears it.
void func_8009C25C(u8 *player)
{
    s32 block;

    block = *(s32 *) ((s8 *) player + 0xE4);
    func_800EF04C(block, block + 0x24);
    func_800EFD24(*(s32 *) ((s8 *) player + 0xE4) + 0x24);
}
