// Backpack pose control: sets the backpack bone swing mode for walking, swimming, climbing and
// other states, and enlarges the backpack while something rides in it (Taxi Pack).
#include "common.h"
#include "playerstate.h"

extern void func_8009EA58(s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800984F0(PlayerState *, f32 *);
typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 offset[3];
    u8 mode;
} PackState48;
extern void func_80098494(void *, f32, f32, f32, f32);
extern void func_800984CC(void *, f32 *);
int bapackctrl_entrypoint_5();

s32 bapackctrl_entrypoint_0()
{
    return 0x20;
}

int bapackctrl_entrypoint_1();

// Scale the backpack up to (1.7, 1.7, 2.6) while something rides in it.
void func_80800008_bapackctrl(player) PlayerState *player;
{
    f32 scale[3];
    if (bapackctrl_entrypoint_1(player)) {
        func_800EFA4C(scale, 1.7f, 1.7f, 2.6f);
    } else {
        func_800EFA4C(scale, 1.0f, 1.0f, 1.0f);
    }
    func_800984F0(player, scale);
}

int bapackctrl_entrypoint_1(s32 player)
{
    s32 value;
    s32 *player_ptr;
    s32 copy;
    s32 *player_addr;
    // Matching: the pointer round trip, comma operator, label and extra copy are needed for the match.
    player_ptr = (0, player_addr = &player);
    value = *player_ptr;
dummy_label_706621:;
    func_8009EA58(copy = value);
}

void bapackctrl_entrypoint_2(s32 arg0)
{
    bapackctrl_entrypoint_5(arg0, 0);
}

void bapackctrl_entrypoint_3(u8 *player)
{
    f32 value;
    u8 *pack;

    pack = *(u8 **) ((s8 *) player + 0xD8);
    value = *(f32 *) ((s8 *) pack + 0xC);
    *(f32 *) ((s8 *) pack + 8) = value;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xD8) + 4) = value;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xD8) + 0) = value;
    func_800EFD24(*(u8 **) ((s8 *) player + 0xD8) + 0x10);
    func_80800008_bapackctrl(player);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xD8) + 0x1C) = 0;
    bapackctrl_entrypoint_5(player, 1);
}

// Set the taxi-pack occupied flag and refresh the backpack scale.
int bapackctrl_entrypoint_4(s32 player, s32 occupied)
{
    // Matching: `| 0` needed for the match.
    func_8009EADC(occupied | 0);
    func_80800008_bapackctrl(player);
}

// Select the backpack bone override mode (0-5) and apply spring constants and offset.
int bapackctrl_entrypoint_5(player, mode)
u8 *player;
u32 mode;
{
    f32 value;

    (*(PackState48 **) (player + 0xD8))->mode = mode;
    switch (mode) {
        case 0:
            func_80098480(player, 0, 0);
            break;
        case 1:
            func_80098480(player, 0, 0);
            break;
        case 2:
            func_80098480(player, 1, 0);
            (*(PackState48 **) (player + 0xD8))->unk_0 = 80.0f;
            (*(PackState48 **) (player + 0xD8))->unk_4 = 13.0f;
            (*(PackState48 **) (player + 0xD8))->unk_8 = 50.0f;
            (*(PackState48 **) (player + 0xD8))->unk_C = 40.0f;
            break;
        case 3:
            func_80098480(player, 1, 1);
            (*(PackState48 **) (player + 0xD8))->unk_0 = 80.0f;
            (*(PackState48 **) (player + 0xD8))->unk_4 = 13.0f;
            (*(PackState48 **) (player + 0xD8))->unk_8 = 50.0f;
            (*(PackState48 **) (player + 0xD8))->unk_C = 40.0f;
            func_800EFA4C((*(PackState48 **) (player + 0xD8))->offset, 0.0f, -0.2f, -0.4f);
            break;
        case 4:
            func_80098480(player, 1, 1);
            (*(PackState48 **) (player + 0xD8))->unk_0 = 50.0f;
            (*(PackState48 **) (player + 0xD8))->unk_4 = 13.0f;
            (*(PackState48 **) (player + 0xD8))->unk_8 = 50.0f;
            (*(PackState48 **) (player + 0xD8))->unk_C = 40.0f;
            func_800EFA4C((*(PackState48 **) (player + 0xD8))->offset, 0.0f, -0.2f, -0.4f);
            break;
        case 5:
            func_80098480(player, 1, 1);
            (*(PackState48 **) (player + 0xD8))->unk_C = 0.0f;
            value = (*(PackState48 **) (player + 0xD8))->unk_C;
            (*(PackState48 **) (player + 0xD8))->unk_8 = value;
            (*(PackState48 **) (player + 0xD8))->unk_4 = value;
            (*(PackState48 **) (player + 0xD8))->unk_0 = value;
            func_800EFD24((*(PackState48 **) (player + 0xD8))->offset);
    }
    func_80098494(player, (*(PackState48 **) (player + 0xD8))->unk_0,
                  (*(PackState48 **) (player + 0xD8))->unk_4,
                  (*(PackState48 **) (player + 0xD8))->unk_8,
                  (*(PackState48 **) (player + 0xD8))->unk_C);
    func_800984CC(player, (*(PackState48 **) (player + 0xD8))->offset);
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM).
