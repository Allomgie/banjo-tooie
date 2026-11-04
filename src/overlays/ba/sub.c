#include "common.h"
#include "playerstate.h"

typedef struct {
    u8 pad_0[0x54];
    f32 timer;
    u8 pad_1[4];
    u8 remaining;
    u8 state;
    u8 queued;
    u8 burst_size;
    f32 burst_delay;
    f32 shot_interval;
} SubmarineSequence;
typedef struct {
    u8 pad_0[0x130];
    SubmarineSequence *seq;
} SubmarinePlayerView;
extern f32 func_800D8FF8(void);
typedef struct {
    u8 pad[0x28];
    s32 f28;
    s32 arr[10];
} SubS;
extern void _basub_entrypoint_4(void);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern s32 D_80800C10_basub[];
extern PlayerState *func_800F53D0(s32);
extern s32 func_80092CDC(PlayerState *, f32 *, s32);
extern s32 func_80092EB0(PlayerState *);
extern void func_800F3BD0(PlayerState *, s32, f32 *);
extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void _baeggfire_entrypoint_3(PlayerState *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern f32 func_800964DC(PlayerState *);
extern s32 _basub_entrypoint_6(s32, s32, s32);
extern s32 _chtorpedo_entrypoint_0(f32 *, f32 *, f32 *, s32 (*)(s32, s32, s32), s32, f32);
extern u8 D_80800C24_basub[];
extern void _basub_entrypoint_7(void);
extern void func_8009C128();
extern void func_8010D930(s32, s32, f32 *, void *);
extern void _chbaddiesetup_entrypoint_2(void (*)(void), s32, f32);
extern s32 D_80800C30_basub[];
extern void func_800E0AF0(s32, f32);
extern void func_800F1574(f32 *, f32);
extern void func_800E0AFC(s32, s32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
void func_80800834_basub();
int basub_entrypoint_15();

s32 basub_entrypoint_0()
{
    return 0x6C;
}

void func_80800008_basub(PlayerState *player, s32 new_state)
{
    switch (new_state) {
        case 1:
            if (((SubmarinePlayerView *) player)->seq->state == 2) {
                ((SubmarinePlayerView *) player)->seq->queued = 0;
                ((SubmarinePlayerView *) player)->seq->timer =
                    ((SubmarinePlayerView *) player)->seq->burst_delay -
                    ((SubmarinePlayerView *) player)->seq->shot_interval;
            }
            break;
        case 2:
            if (((SubmarinePlayerView *) player)->seq->state == 1) {
                ((SubmarinePlayerView *) player)->seq->remaining =
                    ((SubmarinePlayerView *) player)->seq->burst_size - 1;
            } else {
                ((SubmarinePlayerView *) player)->seq->remaining--;
            }
            ((SubmarinePlayerView *) player)->seq->timer +=
                ((SubmarinePlayerView *) player)->seq->shot_interval;
            func_80800834_basub(player);
    }
    ((SubmarinePlayerView *) player)->seq->state = new_state;
}

void func_808000CC_basub(u8 *player)
{
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x130) + 0x58) = 0.0f;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x130) + 0x5E) = 0;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x130) + 0x54) = 0.0f;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x130) + 0x5D) = 0;
    func_80800008_basub(player, 1);
}

void func_80800110_basub(PlayerState *player)
{
    f32 dt;

    dt = func_800D8FF8();
    if (*(f32 *) ((SubmarinePlayerView *) player)->seq->pad_1 > 0.0f) {
        *(f32 *) ((SubmarinePlayerView *) player)->seq->pad_1 -= dt;
        if (*(f32 *) ((SubmarinePlayerView *) player)->seq->pad_1 <= 0.0f)
            ((SubmarinePlayerView *) player)->seq->queued = 0;
    }
    switch (((SubmarinePlayerView *) player)->seq->state) {
        case 1:
            if (((SubmarinePlayerView *) player)->seq->timer > 0.0f)
                ((SubmarinePlayerView *) player)->seq->timer -= dt;
            if (((SubmarinePlayerView *) player)->seq->timer <= 0 &&
                ((SubmarinePlayerView *) player)->seq->queued)
                func_80800008_basub(player, 2);
            break;
        case 2:
            ((SubmarinePlayerView *) player)->seq->timer -= dt;
            if (((SubmarinePlayerView *) player)->seq->timer <= 0) {
                if (((SubmarinePlayerView *) player)->seq->remaining) {
                    if (((SubmarinePlayerView *) player)->seq->queued)
                        func_80800008_basub(player, 2);
                    else
                        func_80800008_basub(player, 1);
                } else
                    func_80800008_basub(player, 1);
            }
    }
}

// Add a torpedo to the list of tracked torpedoes (max 10).
void func_80800254_basub(PlayerState *player, s32 torpedo)
{
    s32 i;

    for (i = 0; i < 10; i++) {
        if (((s32 *) *(void **) ((u8 *) player + 0x130))[11 + i] == 0) {
            ((s32 *) *(void **) ((u8 *) player + 0x130))[11 + i] = torpedo;
            ((s32 *) *(void **) ((u8 *) player + 0x130))[10]++;
            return;
        }
    }
}

// Remove a torpedo from the tracked list.
void func_80800358_basub(PlayerState *player, s32 torpedo)
{
    s32 i;

    for (i = 0; i < 10; i++) {
        if (((s32 *) *(void **) ((u8 *) player + 0x130))[11 + i] == torpedo) {
            ((s32 *) *(void **) ((u8 *) player + 0x130))[11 + i] = 0;
            ((s32 *) *(void **) ((u8 *) player + 0x130))[10]--;
            return;
        }
    }
}

// Send a message to all tracked torpedoes.
void func_80800458_basub(u8 *player, s32 msg)
{
    s32 torpedo;
    s32 offset;

    offset = 0;
    do {
        torpedo = *(s32 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x130) + offset) + 0x2C);
        if (torpedo != 0) {
            func_8010114C(torpedo, msg, *(s32 *) ((s8 *) player + 0x184));
        }
        offset += 4;
    } while (offset != 0x28);
}

void func_808004C8_basub(u8 *player)
{
    s32 i;
    for (i = 0; i < 10; i++) {
        (*(SubS **) (player + 0x130))->arr[i] = 0;
    }
    (*(SubS **) (player + 0x130))->f28 = 0;
}

void basub_entrypoint_1(s32 player)
{
    func_80800458_basub(player, 0x5);
}

f32 basub_entrypoint_2(u8 *player)
{
    u8 *comp;

    comp = *(u8 **) ((s8 *) player + 0x130);
    if (*(f32 *) ((s8 *) comp + 4) > 0.0f) {
        return *(f32 *) ((s8 *) comp + 0);
    }
    return 0.0f;
}

void basub_entrypoint_3(u8 *player, f32 param_1, f32 param_2)
{
    u8 *comp;
    u8 *comp_again;
    comp = *(u8 **) ((s8 *) player + 0x130);
    if (!(*(f32 *) ((s8 *) comp + 4) > 0.0f)) {
        *(f32 *) ((s8 *) comp + 0) = param_1;
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x130) + 4) = param_2;
        // Matching: dummy do-while(0) block needed for the match.
        do {
            comp_again = *(u8 **) ((s8 *) player + 0x130);
            *(f32 *) ((s8 *) comp_again + 8) = (f32) *(f32 *) ((s8 *) comp_again + 4);
        } while (0);
    }
}

// Spawn the sonar ping.
void basub_entrypoint_4(s32 player_id)
{
    int player;
    player = func_800F53D0(player_id);
    _chping_entrypoint_0(*(int *) (player + 0x184));
}

// Start a sonar ping unless the cooldown (3 s) is running.
void basub_entrypoint_5(PlayerState *player)
{
    f32 *comp = *(f32 **) ((u8 *) player + 0x130);

    if (comp[7] == 0.0f) {
        comp[7] = 3.0f;
        func_8009DB04(player, 0x52A, 1.0f, 0x7FFF);
        _chbaddiesetup_entrypoint_1(_basub_entrypoint_4, player->unk184);
    }
}

// Torpedo callback: message 5 (explode) plays the hit sound.
int basub_entrypoint_6(s32 torpedo, s32 msg, s32 player_id)
{
    f32 pos[3];
    s32 player;

    player = func_800F53D0(player_id);
    switch (msg) {
        case 5:
            func_8008F880(torpedo, pos);
            func_8010D930(6, -1, pos, &D_80800C10_basub);
        case 0x78:
            break;
    }
    func_80800358_basub(player, torpedo);
}

// Spawn one torpedo, aimed by the egg cursor or by pitch/yaw.
void basub_entrypoint_7(s32 player_id, s32 param_1)
{
    f32 unk_0[3];
    f32 pos[3];
    f32 velocity[3];
    s32 unk_1;
    s32 unk_2;
    PlayerState *player;

    player = func_800F53D0(player_id);
    unk_1 = func_80092CDC(player, pos, 5);
    unk_2 = func_80092EB0(player);
    if (unk_1 && unk_2) {
        func_800F3BD0(player, 5, unk_0);
        func_800EEC30(velocity, -func_8009BFCC(player), yaw_get(player),
                      *(f32 *) ((u8 *) *(void **) ((u8 *) player + 0x130) + 0x68));
    } else {
        _baeggfire_entrypoint_3(player, unk_0, velocity);
        func_800EF368(velocity, 100.0f);
        func_800EE780(pos, unk_0, velocity);
        func_800EF368(velocity, *(f32 *) ((u8 *) *(void **) ((u8 *) player + 0x130) + 0x68));
        _baeggcursor_entrypoint_8(player);
    }
    (*(u8 *) ((u8 *) *(void **) ((u8 *) player + 0x130) + 0x5E))--;
    func_80800254_basub(player,
                        _chtorpedo_entrypoint_0(pos, unk_0, velocity, _basub_entrypoint_6,
                                                player->unk184, func_800964DC(player)));
}

// Queue one more torpedo of the burst (max 10 live or queued).
void basub_entrypoint_8(u8 *player, s32 param_1)
{
    u8 queued;
    u8 *comp;

    comp = *(u8 **) ((s8 *) player + 0x130);
    queued = *(u8 *) ((s8 *) comp + 0x5E);
    if ((*(s32 *) ((s8 *) comp + 0x28) + queued) < 0xA) {
        *(u8 *) ((s8 *) comp + 0x5E) = (u8) (queued + 1);
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x130) + 0x58) = 0.35f;
    }
}

void func_80800834_basub(player) u8 *player;
{
    f32 pos[4];
    pos[3] = 0.0f;
    func_8009C128(player, pos);
    func_8010D930(0xB, -1, pos, D_80800C24_basub);
    _chbaddiesetup_entrypoint_2(_basub_entrypoint_7, *(s32 *) (player + 0x184), pos[3]);
}

void basub_entrypoint_9(u8 *player)
{
    func_80800458_basub(player, 0x2C);
    func_800C2FDC((*(u8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x130)))) + (0xC))));
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x130)))) + (0xC))) = 0;
    _bawobble_entrypoint_2(player);
}

void basub_entrypoint_10(u8 *player)
{
    u8 *comp;
    _bawobble_entrypoint_3();
    func_808000CC_basub(player);
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x130)))) + 0)) = 0.0f;
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x130)))) + 8)) = 0.0f;
    comp = *((u8 **) (((s8 *) player) + 0x130));
    *((f32 *) (((s8 *) comp) + 4)) = (f32) (*((f32 *) (((s8 *) comp) + 8)));
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x130)))) + 0xC)) =
        func_8009D454(player, 0, &D_80800C30_basub);
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x130)))) + 0x10)) = 1.0f;
    // Matching: "* 1.0f" is needed for the match.
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x130)))) + 0x18)) = 0.0f * 1.0f;
    comp = *((u8 **) (((s8 *) player) + 0x130));
    *((f32 *) (((s8 *) comp) + 0x14)) = (f32) (*((f32 *) (((s8 *) comp) + 0x18)));
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x130)))) + 0x1C)) = 0.0f;
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x130)))) + 0x20)) = 0.0f;
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x130)))) + 0x24)) = 0.0f;
    func_808004C8_basub(player);
    basub_entrypoint_15(player, 0);
}

void basub_entrypoint_11(s32 player, f32 volume)
{
    *(f32 *) (*(s32 *) (player + 0x130) + 0x10) = volume;
}

int basub_entrypoint_12(s32 player, f32 target_pitch)
{
    *((f32 *) ((*((s32 *) (player + 0x130))) + 0x18)) = target_pitch;
}

void basub_entrypoint_13(void *player, f32 spin_speed)
{
    *((f32 *) (((char *) (*((void **) (((char *) player) + 0x130)))) + 0x24)) = spin_speed;
}

void basub_entrypoint_14(u8 *player)
{
    f32 dt;
    f32 step;
    f32 pos[3];
    s32 model;
    dt = func_800D8FF8();
    model = func_80092AD8(player);
    func_800E0AF0(model, 1.0f);
    func_800F1574((f32 *) (*(u8 **) (player + 0x130) + 4), dt);
    step = dt < *(f32 *) ((*(u8 **) (player + 0x130)) + 0x1C)
                  ? dt
                  : *(f32 *) ((*(u8 **) (player + 0x130)) + 0x1C);
    *(f32 *) ((*(u8 **) (player + 0x130)) + 0x1C) -= step;
    *(f32 *) ((*(u8 **) (player + 0x130)) + 0x20) +=
        *(f32 *) ((*(u8 **) (player + 0x130)) + 0x24) * dt;
    func_800E0AFC(model, 0x2A, 1.0f, 0.0f, 0.0f, *(f32 *) (*(u8 **) (player + 0x130) + 0x20));
    *(f32 *) (*(u8 **) (player + 0x130) + 0x14) =
        func_800F15F8(*(f32 *) ((*(u8 **) (player + 0x130)) + 0x14),
                      *(f32 *) ((*(u8 **) (player + 0x130)) + 0x18), 450.0f * dt);
    func_800E0AFC(model, 0x41, 1.0f, *(f32 *) (*(u8 **) (player + 0x130) + 0x14), 0.0f, 0.0f);
    func_800E0AFC(model, 0x43, 1.0f, *(f32 *) (*(u8 **) (player + 0x130) + 0x14), 0.0f, 0.0f);
    func_8009C128(player, pos);
    func_800C35E8((*(u8 **) (player + 0x130))[0xC], pos);
    func_800C33DC((*(u8 **) (player + 0x130))[0xC], 0);
    func_800C368C((*(u8 **) (player + 0x130))[0xC], 0);
    func_800C31DC((*(u8 **) (player + 0x130))[0xC],
                  *(s32 *) ((*(u8 **) (player + 0x130)) + 0x10));
    func_800C3BDC((*(u8 **) (player + 0x130))[0xC]);
    func_80800110_basub(player);
}

int basub_entrypoint_15(player, fast)
u8 *player;
s32 fast;
{
    if (fast != 0) {
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x130) + 0x68) = 3000.0f;
        *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x130) + 0x5F) = 6;
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x130) + 0x60) = 0.8f;
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x130) + 0x64) = 0.28f;
        return;
    }

    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x130)))) + (0x68))) = 1500.0f;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x130)))) + (0x5F))) = 3;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x130)))) + (0x60))) = 0.8f;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x130)))) + (0x64))) = 0.28f;
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
s32 D_80800C10_basub[5] = {0x130413, 0x167FFF, 0x1012C, 0x157C0011, 0x0};
u8 D_80800C24_basub[12] = {0x0, 0x13, 0x5, 0x29, 0x0, 0x16, 0x7F, 0xFF, 0x0, 0x11, 0x0, 0x0};
s32 D_80800C30_basub[8] = {0x2060013, 0x528001B, 0x1655F0, 0xA0100, 0x110000, 0x0, 0x0, 0x0};
