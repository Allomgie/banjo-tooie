// Underwater breath bubbles (PlayerState+0x30): random bursts from Banjo's or Kazooie's mouth,
// plus a speed-proportional bubble trail used by the Kazooie torpedo state.
#include "core2/1E6A730.h"

extern s32 D_80117DB0[];
extern f32 func_800DC178(f32, f32);
extern void func_8009DF94(s32, s32, f32, s32);
extern s32 func_8008FD48();
extern void func_80092E5C();
extern void func_80092DE4();
extern void func_800BABB8(s32, s32, s32, s32, s32 *);
int func_800DC128(int, int);
extern f32 func_800D8FF8(void);
extern void func_800D9078(void *);
extern f32 func_800DC0C0(void);
extern s32 func_800F40EC(void *);
typedef struct {
    u8 pad_0[0x10];
    f32 bubble_accum, unk_14;
} ParticleTimers91290;
typedef struct {
    u8 pad_0[0x30];
    ParticleTimers91290 *timers;
} Player91290;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80092C90(PlayerState *, f32 *, s32);
extern void *func_8009FBB0(PlayerState *, f32 *, f32);
extern void func_800BA930(void *, s32, s32, s32, s32, s32, s32);
extern void func_800BA6B0(void *, s32, s32, s32, s32, s32, s32);
extern void func_800BA7C4(void *, f32, f32);
extern void func_800BA7FC(void *, f32, f32);
extern void func_800BA8F8(void *, f32, f32);
extern void func_800BA22C(void *, s32);

s32 func_80090E40(void)
{
    return 0x18;
}

// Emits a bubble puff at the mouth bone; plays the bubble SFX (0x3ED) when the 0.12 s cooldown is clear.
void func_80090E48(u8 *player)
{
    s32 pad1;
    s32 pad2;
    s32 mouth_pos;
    u8 *emitter;
    if ((*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 0xD) == 0) ||
        (func_8008FD48(player) != 1)) {
        func_80092E5C(player, &mouth_pos);
    } else {
        func_80092DE4(player, &mouth_pos);
    }
    // Matching: "* 0" and the early read of emitter are needed for the match.
    func_800BABB8(func_8009FBB0(player, &mouth_pos, 0.0f),
                  (*(f32 *) ((s8 *) emitter + 0) == 0.0f) * 0, 0, 0x3F800000, D_80117DB0);
    emitter = *(u8 **) ((s8 *) player + 0x30);
    if ((*(u8 *) ((s8 *) emitter + 0xF) != 0) && (*(f32 *) ((s8 *) emitter + 0) == 0.0f)) {
        *(f32 *) ((s8 *) emitter + 0) = 0.12f;
        func_8009DF94(player, 0x3ED, func_800DC178(0.5, 0.7f), 0x1770);
    }
}

// Rolls the next burst: 1, 1-4 or 6-15 bubbles after a random delay.
void func_80090F38(u8 *player)
{
    f32 roll;

    *(f32 *) (*(u8 **) (player + 0x30) + 8) = 0.0f;
    roll = func_800DC0C0();
    if (roll < 0.5f) {
        *(f32 *) (*(u8 **) (player + 0x30) + 4) = func_800DC178(0.6f, 0.7f);
        *(s8 *) (*(u8 **) (player + 0x30) + 0xC) = 1;
        return;
    }
    if (roll < 0.7f) {
        *(f32 *) (*(u8 **) (player + 0x30) + 4) = func_800DC178(0.7, 1.0f);
        *(s8 *) (*(u8 **) (player + 0x30) + 0xC) = func_800DC128(1, 4);
        return;
    }
    *(f32 *) (*(u8 **) (player + 0x30) + 4) = func_800DC178(2.3f, 2.6f);
    *(s8 *) (*(u8 **) (player + 0x30) + 0xC) = func_800DC128(6, 0xF);
}

void func_80091030(u8 *player)
{
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 8) = 0.0f;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 4) = 0.0f;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 0xC) = 1;
}

void func_80091054(s32 arg0)
{
}

void func_8009105C(PlayerState *player)
{
    (*(s8 **) ((u8 *) player + 0x30))[0xC] = 0;
    (*(f32 **) ((u8 *) player + 0x30))[1] = 2.0f;
    (*(s8 **) ((u8 *) player + 0x30))[0xE] = 0;
    (*(f32 **) ((u8 *) player + 0x30))[4] = 0.0f;
    (*(f32 **) ((u8 *) player + 0x30))[5] = 0.0f;
    (*(s8 **) ((u8 *) player + 0x30))[0xF] = 1;
    func_800910BC(player, 1);
}

// Sets the emitter mode; leaving mode 4 clears its timers and burst count.
void func_800910BC(player, mode) PlayerState *player;
s32 mode;
{
    if (*(u8 *) ((char *) *(s32 **) ((char *) player + 0x30) + 0xE) == 4) {
        *(f32 *) ((char *) *(s32 **) ((char *) player + 0x30) + 0x4) = 0.0f;
        *(u8 *) ((char *) *(s32 **) ((char *) player + 0x30) + 0xC) = 0;
        *(f32 *) ((char *) *(s32 **) ((char *) player + 0x30) + 0x14) = 0.0f;
        *(f32 *) ((char *) *(s32 **) ((char *) player + 0x30) + 0x10) =
            *(f32 *) ((char *) *(s32 **) ((char *) player + 0x30) + 0x14);
    }
    *(u8 *) ((char *) *(s32 **) ((char *) player + 0x30) + 0xE) = mode;
}

// Enables or disables the bubble SFX.
void func_80091104(void *player, s32 sfx_enabled)
{
    ((s8 *) *(void **) ((char *) player + 0x30))[15] = sfx_enabled;
}

// Per-frame update while submerged: counts down the burst and interval timers.
void func_80091110(u8 *player)
{
    f32 delta_copy;
    f32 delta;
    u8 *emitter_a;
    u8 *emitter_b;
    u8 *emitter_c;
    s8 *player_bytes;
    func_800D9078(*(u8 **) ((s8 *) player + 0x30));
    if ((func_800F40EC(player) == 2) &&
        (*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 0xE) != 4)) {
        delta = func_800D8FF8();
        // Matching: the copies of player and delta are needed for the match.
        player_bytes = (s8 *) player;
        delta_copy = delta;
        emitter_a = *(u8 **) (player_bytes + 0x30);
        if (*(u8 *) ((s8 *) emitter_a + 0xC) != 0) {
            *(f32 *) ((s8 *) *(u8 **) (player_bytes + 0x30) + 8) =
                (f32) (*(f32 *) ((s8 *) *(u8 **) (player_bytes + 0x30) + 8) - delta);
            if (*(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 8) < 0.0f) {
                *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 8) =
                    func_800DC178(0.066f, 0.1f);
                emitter_b = *(u8 **) ((s8 *) player + 0x30);
                *(u8 *) ((s8 *) emitter_b + 0xC) = (u8) (*(u8 *) ((s8 *) emitter_b + 0xC) - 1);
                func_80090E48(player);
            }
        }
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 4) =
            (f32) (*(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 4) - delta_copy);
        if (!(*(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 4) > 0.0f)) {
            if (*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 0xE) == 3) {
                func_80091030(player);
            } else {
                func_80090F38(player);
            }
            emitter_c = *(u8 **) ((s8 *) player + 0x30);
            if (*(u8 *) ((s8 *) emitter_c + 0xE) == 2) {
                *(s8 *) ((s8 *) emitter_c + 0xD) = 1;
                return;
            }
            if (func_800DC0C0() >= 0.5f) {
                *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 0xD) = 0;
                return;
            }
            *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x30) + 0xD) = 1;
        }
    }
}

// Speed-proportional bubble trail (used by the Kazooie torpedo state).
void func_80091290(PlayerState *player, f32 speed, s32 unk_0, s32 bone)
{
    f32 scale;
    f32 pos[3];
    void *particles;
    s32 count;
    f32 unk_1;
    scale = func_800F10B4(speed, 5.0f, 20.0f, 4.0f, 0.7f);
    func_80092C90(player, pos, bone);
    ((Player91290 *) player)->timers->bubble_accum += speed * func_800D8FF8();
    count = (s32) ((Player91290 *) player)->timers->bubble_accum;
    ((Player91290 *) player)->timers->bubble_accum -= count;
    particles = func_8009FBB0(player, pos, 40.0f);
    func_800BA930(particles, -60, -50, -60, 60, 100, 60);
    if (unk_0) {
        func_800BA6B0(particles, -50, -70, -50, 50, 70, 50);
        // Matching: the extra temporary is needed for the match.
        unk_1 = 0.09f;
        func_800BA7C4(particles, unk_1, 0.1f);
        func_800BA7FC(particles, 0.2f, 0.22f);
    } else {
        func_800BA7C4(particles, 0.09f, 0.09f);
        func_800BA7FC(particles, 0.12f, 0.12f);
    }
    func_800BA8F8(particles, scale, scale);
    // Matching: the bone parameter is reused as the loop counter.
    for (bone = 0; bone < count; bone++)
        func_800BA22C(particles, 1);
    if (speed > 3.0f)
        speed = func_800F10B4(speed, 3.0f, 60.0f, 3.0f, 8.0f);
    ((Player91290 *) player)->timers->unk_14 += speed * func_800D8FF8();
    count = (s32) ((Player91290 *) player)->timers->unk_14;
    ((Player91290 *) player)->timers->unk_14 -= count;
}

// Trail emitter on bone 4.
void func_800914FC(s32 player, f32 speed, s32 unk_0)
{
    func_80091290(player, speed, unk_0, 4);
}

// TU-NOTE: the .data of this file is defined here in C; values taken from the ROM.
s32 D_80117DB0[8] = {0x2CFFF1, 0xFFF1, 0xF0032, 0xF011A, 0x0, 0x0, 0x0, 0x0};
