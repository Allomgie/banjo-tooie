#include "ba/hold.h"
#include "playerstate.h"

extern void func_8009ADF0(void *, s32, s32);
// Held actor, as returned by the actor array lookup
typedef struct {
    u8 pad_0[4];
    f32 pos_x;
    f32 pos_y;
    f32 pos_z;
    u8 pad_10[0x38];
    f32 yaw;
    u8 pad_4C[0x19];
    u8 flag : 1;
    u8 rest : 7;
} HoldS;
extern HoldS *func_80106790(s32);
// Carry component at PlayerState+0x9C
typedef struct {
    f32 y_offset;
    f32 unk_4;
    void *held_actor;
} HoldData;
extern void func_8008FF40(f32 *);
extern void func_80092D44(PlayerState *, f32 *);
extern f32 func_800136E4(f32);
void bahold_entrypoint_7(Actor *player, f32 y_offset, f32 unk_4);

s32 bahold_entrypoint_0()
{
    return 0x10;
}

// Sets the carried actor and player flag 0xE (carrying)
void func_80800008_bahold(player, held) u8 *player;
s32 held;
{
    *(s32 *) (*(u8 **) (player + 0x9C) + 8) = held;
    func_8009ADF0(player, 0xE, held != 0 ? 1 : 0);
}

void bahold_entrypoint_1(u8 *player)
{
    func_80800008_bahold(player, 0);
    (*(u8 **) (player + 0x9C))[0xC] = 0;
    bahold_entrypoint_7(player, 0.0f, 0.0f);
}

void bahold_entrypoint_2(s32 arg0)
{
}

// Moves the held actor to the given position and yaw
void func_80800088_bahold(s32 handle, f32 *pos, f32 *rot)
{
    HoldS *held = func_80106790(handle);
    if (held->flag) {
        held->pos_x = pos[0];
        held->pos_y = pos[1];
        held->pos_z = pos[2];
        held->yaw = rot[1];
    }
}

// Places the held actor at the player's carry bone
void func_808000E0_bahold(player) PlayerState *player;
{
    f32 bone_pos[3];
    f32 rot[3];
    func_8008FF40(rot);
    func_80092D44(player, bone_pos);
    rot[1] = func_800136E4(rot[1] + ((HoldData *) player->unk9C)->unk_4);
    bone_pos[1] += ((HoldData *) player->unk9C)->y_offset;
    func_80800088_bahold(((HoldData *) player->unk9C)->held_actor, bone_pos, rot);
}

void bahold_entrypoint_3(void *player)
{
    if (*(s32 *) ((char *) *(void **) ((char *) player + 0x9C) + 8) != 0) {
        if (*(u8 *) ((char *) *(void **) ((char *) player + 0x9C) + 0xC) == 0) {
            func_80800008_bahold(player, 0);
            return;
        }
        func_808000E0_bahold();
        *(u8 *) ((char *) *(void **) ((char *) player + 0x9C) + 0xC) = 0;
    }
}

void bahold_entrypoint_4(s32 player)
{
    func_80800008_bahold(player, 0);
}

Unk80132ED0 *bahold_entrypoint_5(PlayerState *player)
{
    return *(s32 *) (*(s32 *) ((char *) player + 0x9C) + 0x8);
}

void bahold_entrypoint_6(u8 *player)
{
    func_80800008_bahold();
    func_808000E0_bahold(player);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x9C) + 0xC) = 1;
}

void bahold_entrypoint_7(Actor *player, f32 y_offset, f32 unk_4)
{
    *(f32 *) ((u8 *) *(void **) ((u8 *) player + 0x9C) + 0) = y_offset;
    *(f32 *) ((u8 *) *(void **) ((u8 *) player + 0x9C) + 4) = unk_4;
}
