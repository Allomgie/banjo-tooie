// Egg firing logic: per-egg-type fire-rate state machine, shot queue with delayed follow-up shots,
// shot ray from the cursor through the camera, egg spawn, shot sound and usage count.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern void *func_800A4C68(void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
typedef struct {
    u8 pad_0[0x10];
    u8 egg_type;
    u8 unk_11;
    u8 unk_12;
    u8 callback_pending;
} EggFireQueue;
typedef struct {
    u8 pad_0[0x6C];
    EggFireQueue *fire;
} EggFirePlayer;
extern void _baeggfire_entrypoint_1(s32);
extern void _baeggfire_entrypoint_2(s32);
extern void func_800C9DE4(f32, void (*)(s32), s32);

typedef struct {
    f32 cooldown;
    s32 burst_count;
    s32 state;
    s32 fire_request;
    u8 egg_type;
} EggFireState;
typedef struct {
    u8 pad_0[0x6C];
    EggFireState *fire;
} EggFireModePlayer;

s32 baeggfire_entrypoint_0()
{
    return 0x14;
}

// Queues one follow-up shot of the given kind.
void func_80800008_baeggfire(player, kind) Actor *player;
s32 kind;
{
    u8 *fire;

if (kind == 1) {
    fire = *(u8 **) ((char *) player + 0x6C);
    *(u8 *) ((char *) fire + 0x12) = *(u8 *) ((char *) fire + 0x12) + 1;
    return;
}

fire = *(u8 **) ((char *) player + 0x6C);
*(u8 *) ((char *) fire + 0x11) = *(u8 *) ((char *) fire + 0x11) + 1;
}

// Clears the follow-up queues.
void func_80800040_baeggfire(u8 *player)
{
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x6C)))) + (0x12))) = 0;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x6C)))) + (0x11))) = 0;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x6C)))) + (0x13))) = 0;
}

void baeggfire_entrypoint_1()
{
    s32 player = func_800F53D0();
    // Matching: the redundant masks are needed for the match.
    s32 fire = (((((*((s32 *) (player + 0x6C))) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
                    0xFFFFFFFFFFFFFFFFu) &
                   0xFFFFFFFFFFFFFFFFu) &
                  0xFFFFFFFFFFFFFFFFu;
    *((u8 *) (fire + 0x13)) = 0;
    func_80800008_baeggfire(player, 0);
}

void baeggfire_entrypoint_2(void)
{
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (func_800F53D0()) + (0x6C)))) + (0x13))) = 0;
}

// Starts the next queued follow-up shot and schedules its timed callback.
void func_808000B8_baeggfire(player) PlayerState *player;
{
    EggFireQueue *queue;

    queue = ((EggFirePlayer *) player)->fire;

if (!queue->callback_pending) {
    if (queue->unk_12) {
        func_800C9DE4(0.25f, _baeggfire_entrypoint_1, player->unk184);
        ((EggFirePlayer *) player)->fire->callback_pending = 1;
        _baeggsetup_entrypoint_10(player);
        ((EggFirePlayer *) player)->fire->unk_12--;
    } else if (queue->unk_11) {
        func_800C9DE4(0.17f, _baeggfire_entrypoint_2, player->unk184);
        ((EggFirePlayer *) player)->fire->callback_pending = 1;
        _baeggsetup_entrypoint_8(player, ((EggFirePlayer *) player)->fire->egg_type);
        ((EggFirePlayer *) player)->fire->unk_11--;
    }
}

}

// Sets the fire state and its cooldown.
void func_80800180_baeggfire(player, mode) EggFireModePlayer *player;
s32 mode;
{
    player->fire->state = mode;

switch (mode) {
    case 1:
        player->fire->cooldown = 0.0f;
        player->fire->burst_count = 0;
        player->fire->fire_request = 0;
        break;
    case 2:
        if (func_800944F8(player, player->fire->egg_type))
            player->fire->cooldown = 0.15f;
        else
            player->fire->cooldown = 0.28f;
        break;
    case 3:
        player->fire->cooldown = 0.2f;
        break;
    case 4:
        player->fire->cooldown = 0.5f;
}

}

void baeggfire_entrypoint_3();

// Fires one egg: updates the burst state and spawns the shot along the cursor ray.
void func_80800250_baeggfire(player) PlayerState *player;
{
    f32 speed;
    f32 origin[3];
    f32 dir[3];
    f32 spawn_pos[3];
    s32 burst_size;
    s32 unk_0;
    unk_0 = func_800944F8(player, ((u8 *) (*(void **) ((u8 *) player + 0x6C)))[0x10]);
    if (!*(s32 *) ((u8 *) (*(void **) ((u8 *) player + 0x6C)) + 4))
        ((u8 *) (*(void **) ((u8 *) player + 0x6C)))[0x10] = func_80094510(player);
    burst_size = func_800944E0(player, ((u8 *) (*(void **) ((u8 *) player + 0x6C)))[0x10]);

if (!*(s32 *) ((u8 *) *(void **) ((u8 *) player + 0x6C) + 4)) {
    func_80800008_baeggfire(player, 1, burst_size);
    if (burst_size == 1)
        func_80800180_baeggfire(player, 4);
    else
        func_80800180_baeggfire(player, 2);
} else if (unk_0 || *(s32 *) ((u8 *) *(void **) ((u8 *) player + 0x6C) + 4) < burst_size - 1) {

func_80800008_baeggfire(player, 0, burst_size);
func_80800180_baeggfire(player, 2);
}
else
{
    func_80800008_baeggfire(player, 0, burst_size);
    func_80800180_baeggfire(player, 4);
}
if (unk_0)
    *(s32 *) ((u8 *) (*(void **) ((u8 *) player + 0x6C)) + 4) = 1;
else
    (*(s32 *) ((u8 *) (*(void **) ((u8 *) player + 0x6C)) + 4))++;
*(s32 *) ((u8 *) (*(void **) ((u8 *) player + 0x6C)) + 0xC) = 0;
baeggfire_entrypoint_3(player, origin, dir);
func_800EF368(dir, 100.0f);
func_800EE780(spawn_pos, origin, dir);
if (((u8 *) (*(void **) ((u8 *) player + 0x6C)))[0x10] == 7)
    speed = 5000.0f;
else
    speed = 3000.0f;
func_800EF368(dir, speed);
_baeggsetup_entrypoint_6(player, ((u8 *) (*(void **) ((u8 *) player + 0x6C)))[0x10], origin,
                         spawn_pos, dir);
_baeggcursor_entrypoint_8(player);
func_800C6DA0(0x43);
}

// Computes the shot origin and direction from the cursor through the camera.
void baeggfire_entrypoint_3(void *player, f32 origin[3], f32 dir[3])
{
    f32 cursor[2];
    f32 unk_0[2];
    f32 world_point[3];
    f32 unk_1[3];

    if (_baeggcursor_entrypoint_2(player) != 1)
        _baeggcursor_entrypoint_3(player, &cursor[0], &cursor[1]);
    else {
        cursor[0] = 152.0f;
        cursor[1] = 114.0f;

}
func_800C5008(func_800A4C68(player), cursor, unk_0);
func_800EFA4C(unk_1, unk_0[0], unk_0[1], 100.0f);
func_800C4E58(func_800A4C68(player), unk_1, world_point);
func_800A4CE8(player, origin);
func_800EFB24(dir, world_point, origin);
func_800EF368(dir, 1.0f);
}

void baeggfire_entrypoint_4(s32 player)
{
    func_8009E0AC(player, 1);
}

// Resets the fire state.
void baeggfire_entrypoint_5(u8 *player)
{
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x6C) + 0) = 0.0f;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x6C) + 0xC) = 0;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x6C) + 8) = 0;
    func_80800180_baeggfire(player, 1);
    func_8009E0AC(player, 0);
    func_80800040_baeggfire(player);
}

// Per-frame update of the fire state machine.
void baeggfire_entrypoint_6(PlayerState *player)
{
    func_808000B8_baeggfire(player);
    switch (*(s32 *) (*(u8 **) ((u8 *) player + 0x6C) + 8)) {
        case 1:
            if (*(s32 *) (*(u8 **) ((u8 *) player + 0x6C) + 0xC)) {
                func_80800250_baeggfire(player);
            }

break;

case 2:
    if (func_800D9078(*(void **) ((u8 *) player + 0x6C))) {
        func_80800180_baeggfire(player, 3);
    }

break;

case 3:
    if (func_800D9078(*(void **) ((u8 *) player + 0x6C))) {
        func_80800180_baeggfire(player, 1);
    }

if (*(s32 *) (*(u8 **) ((u8 *) player + 0x6C) + 0xC)) {
    func_80800250_baeggfire(player);
}

break;

case 4:
    if (func_800D9078(*(void **) ((u8 *) player + 0x6C))) {
        func_80800180_baeggfire(player, 1);
    }

}
}

void baeggfire_entrypoint_7(void *player)
{
    char *fire_slot;
    fire_slot = ((char *) player) + 0x6C;
    // Matching: the empty block is needed for the match.
    {} * ((u32 *) (((char *) (*((void **) fire_slot))) + 0xC)) = 1;
}

int baeggfire_entrypoint_8(void *player)
{
    return ((*((int **) (((char *) player) + 108)))[0x8 / 4] < 2) ^ 0x1;
}
