#include "core2/1E76CC0.h"

// Player sfx state at PlayerState+0x104: handles at +0..+4, counters at +8, +0xC, +0x18,
// pitch at +0x14, positional flag at +0x1C.

#define SOUND(p) (*(LocalSound **) ((u8 *) (p) + 0x104))
#define QQ (*(S_9DA40 **) ((u8 *) param_0 + 0x104))
s32 func_800C4350();
extern s32 D_80119210[4];
extern void func_800C3394();
extern void func_800C330C(u8, s32);
extern void func_800C3418(u8, s32);
extern void func_800C431C(u8, s32);
typedef struct {
    u8 pad_0;
    u8 handle;
    u8 pad_2[0x12];
    f32 pitch;
} LocalSound;
extern s32 func_800C2E04(void);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F13F0(f32, f32);
extern u8 D_80119208[];
f32 func_800DC0C0();
extern s16 D_80119200[];
extern void func_800C35E8(u8, f32 *);
extern void func_800C301C(u8, s32);
extern void func_800C31DC(u8, f32);
extern void func_800C3058(u8, s32);
extern void func_800C3BDC(u8);
typedef struct {
    u8 pad_0[0xC];
    s32 unk_C;
} S_9DA40;
extern s32 _badata_entrypoint_19(PlayerState *, s32, s32 *, f32 *, s32 *);
extern s32 func_8009C128(PlayerState *param_0, f32 *param_1);
extern void func_800C4208(s32 param_0, f32 param_1, s32 param_2, f32 *param_3, f32 param_4,
                          f32 param_5);
extern f32 func_800DC178(f32, f32);
void func_800C4244(s32 param_0, f32 param_1, s32 param_2, f32 *param_3, f32 param_4, f32 param_5);
extern void func_800C2E40(u8);
extern void func_800C368C(u8, s32);
extern void func_800C33DC(u8, s32);
extern s32 func_800DC128(s32, s32);
void func_8009DAAC();

s32 func_8009D3D0()
{
    return 0x20;
}

int func_8009D3D8(s32 player)
{
    func_8009E674(player, 0x2);
}

// Callback of the looping sfx: plays the end sound and releases the loop handle.
void func_8009D3F8(s32 param_0, s32 param_1)
{
    u8 *player;
    player = func_800F53D0(param_1);
    func_8009DB04(player, 0x411, *(f32 *) (*(u8 **) (player + 0x104) + 0x14), 0x55f0);
    func_800C2FDC(*(u8 *) (*(u8 **) (player + 0x104) + 1));
    *(u8 *) (*(u8 **) (player + 0x104) + 1) = 0;
}

s32 func_8009D454(PlayerState *param_0, s32 param_1, s32 *param_2)
{
    u16 pos[5];
    s32 a0;
    func_8009C128(param_0, pos);
    a0 = (u8) ((u8 *) &param_1)[3];
    if (a0 == 0) {
        a0 = func_800C4350(a0, pos, D_80119210) & 0xFF;
    }
    return func_800C4350(a0, pos, param_2);
}

int func_8009D4A8(s32 param_0, s32 param_1)
{
    f32 pos[3];
    func_8009C128(param_0, pos);
    func_800C4AF0(pos, param_1);
}

// Allocates the sfx source handles and resets the counters.
void func_8009D4D8(u8 *player)
{
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 0x18) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 0x1C) = 1;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 8) = 0;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 0xC) = 0;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 0x10) = 0;
    *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 0) = func_800C2E04();
    func_800C330C(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 0), 3);
    func_800C3418(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 0), 0);
    func_800C431C(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 0), 0);
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 0x14) = 1.0f;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 1) = 0;
    *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 2) = func_800C2E04();
    func_800C3418(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 2), 0);
    func_800C431C(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 2), 0);
    *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 3) = func_800C2E04();
    func_800C3418(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 3), 0);
    func_800C431C(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 3), 0);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 4) = 0;
}

// Releases the sfx source handles.
void func_8009D5E0(u8 *player)
{
    u8 *sfx;
    u8 extra_handle;
    u8 loop_handle;
    sfx = *(u8 **) ((s8 *) player + 0x104);
    loop_handle = *(u8 *) ((s8 *) sfx + 1);
    if (loop_handle != 0) {
        // Matching: empty block steers IDO's code generation.
        if ((!sfx && !sfx) && !sfx) {
        }
        func_800C2FDC(loop_handle & 0xFF, loop_handle);
        sfx = *(u8 **) ((s8 *) player + 0x104);
    }
    func_800C2FDC(*sfx);
    func_800C2FDC(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 3));
    func_800C2FDC(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 2));
    extra_handle = *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 4);
    if (extra_handle != 0) {
        func_800C2FDC(extra_handle);
    }
}

// Looping sfx whose pitch drifts randomly.
void func_8009D658(PlayerState *player)
{
    f32 pos[3];
    if (SOUND(player)->handle == 0) {
        SOUND(player)->handle = func_800C2E04();
        func_800C301C(SOUND(player)->handle, 0x410);
        func_800C3394(SOUND(player)->handle, func_8009D3F8, player->unk184);
        func_800C3058(SOUND(player)->handle, 0x6D60);
        func_800C330C(SOUND(player)->handle, 2);
        func_800C3418(SOUND(player)->handle, 0);
        func_800C431C(SOUND(player)->handle, 0);
    }
    func_8009C128(player, pos);
    SOUND(player)->pitch += func_800DC0C0() * 0.1f - 0.05f;
    SOUND(player)->pitch = func_800F0E00(SOUND(player)->pitch, 0.9f);
    SOUND(player)->pitch = func_800F13F0(SOUND(player)->pitch, 1.5f);
    func_800C35E8(SOUND(player)->handle, pos);
    func_800C31DC(SOUND(player)->handle, SOUND(player)->pitch);
    func_800C3BDC(SOUND(player)->handle);
}

// Plays the next sound of D_80119208, cycling through 3 entries.
void func_8009D7A4(u8 *player, f32 pitch_min, f32 pitch_max)
{
    u8 *sfx;
    f32 pitch;

    pitch = func_800DC178(pitch_min, pitch_max);
    func_8009DF18(player,
                  *(s16 *) (D_80119208 +
                            (*(s32 *) ((char *) *(u8 **) ((char *) player + 0x104) + 0x18) * 2)),
                  pitch, 0x61A8);

    sfx = *(u8 **) ((char *) player + 0x104);
    *(s32 *) ((char *) sfx + 0x18) = *(s32 *) ((char *) sfx + 0x18) + 1;

    sfx = *(u8 **) ((char *) player + 0x104);
    if (*(s32 *) ((char *) sfx + 0x18) >= 3) {
        *(s32 *) ((char *) sfx + 0x18) = 0;
    }
}

void func_8009D820(PlayerState *player, f32 pitch)
{
    f32 rand = func_800DC0C0(player);
    s32 sound_id = rand < 0.5f ? 0x585 : 0x586;
    func_8009DE38(player, sound_id, pitch);
}

void func_8009D874(PlayerState *player)
{
    func_8009DE38(player, 0x442E, 1.1169999837875366f);
}

// Plays the next sound of D_80119200, cycling through 4 entries.
void func_8009D89C(u8 *player, f32 pitch)
{
    s32 pos[3];
    func_8009C128(player, &pos[0]);
    func_800C35E8(**(u8 **) ((s8 *) player + 0x104), &pos);
    func_800C301C(**(u8 **) ((s8 *) player + 0x104),
                  D_80119200[*(u32 *) (*(u8 **) ((s8 *) player + 0x104) + 8)]);
    func_800C31DC(**(u8 **) ((s8 *) player + 0x104), pitch);
    func_800C3BDC(**(u8 **) ((s8 *) player + 0x104));
    *(u32 *) (*(u8 **) ((s8 *) player + 0x104) + 8) =
        *(u32 *) (*(u8 **) ((s8 *) player + 0x104) + 8) + 1;
    if (*(u32 *) (*(u8 **) ((s8 *) player + 0x104) + 8) >= 4)
        *(u32 *) (*(u8 **) ((s8 *) player + 0x104) + 8) = 0;
}

void func_8009D940(s32 player, s32 sound_id, f32 pitch, s32 param_3)
{
    f32 pos[3];
    func_8009DAAC(&sound_id, &pitch);
    func_8009C128(player, pos);
    func_800C35E8(*(u8 *) *(u32 *) (player + 0x104), pos);
    func_800C301C(*(u8 *) *(u32 *) (player + 0x104), sound_id);
    func_800C31DC(*(u8 *) *(u32 *) (player + 0x104), pitch);
    func_800C3058(*(u8 *) *(u32 *) (player + 0x104), param_3);
    func_800C3BDC(*(u8 *) *(u32 *) (player + 0x104));
}

void func_8009D9D4(PlayerState *player)
{
    f32 pitch;
    s32 sound_id;
    s32 unk_0;
    if (_badata_entrypoint_17(player, *(s32 *) (*(u8 **) ((u8 *) player + 0x104) + 0xC), &sound_id, &pitch,
                              &unk_0) == 0) {
        *(s32 *) (*(u8 **) ((u8 *) player + 0x104) + 0xC) = 0;
    } else {
        *(s32 *) (*(u8 **) ((u8 *) player + 0x104) + 0xC) += 1;
    }
    func_8009D940(player, sound_id, pitch, unk_0);
}

void func_8009DA40(PlayerState *param_0)
{
    f32 pitch;
    s32 sound_id;
    s32 unk_0;
    if (_badata_entrypoint_19(param_0, QQ->unk_C, &sound_id, &pitch, &unk_0) == 0) {
        QQ->unk_C = 0;
    } else {
        QQ->unk_C = QQ->unk_C + 1;
    }
    func_8009D940(param_0, sound_id, pitch, unk_0);
}

// Strips the flag bits from the sound id; flag 0x4000 lowers the pitch by 0.2 for Dragon Kazooie.
void func_8009DAAC(sound_id, pitch) s32 *sound_id;
f32 *pitch;
{
    s32 *id_ptr;
    s32 id;
    int flags;
    id_ptr = sound_id;
    id = *id_ptr;
    flags = id & ~0xFFF;
    *id_ptr = 0xFFF;
    *id_ptr = id & *id_ptr;
    // Matching: empty block steers IDO's code generation.
    if (!flags) {
    }
    if ((flags == 0x4000) && (func_8009EA2C() != 0)) {
        *pitch -= 0.2f;
    }
}

void func_8009DB04(PlayerState *player, s32 sound_id, f32 pitch, s32 param_3)
{
    f32 pos[3];
    func_8009DAAC(&sound_id, &pitch);
    func_8009C128(player, pos);
    if (func_8009D3D8(player)) {
        func_800C4208(sound_id, pitch, param_3, pos, 250.0f, 5.4e+03f);
    } else {
        func_800C4244(sound_id, pitch, param_3, pos, 250.0f, 5.4e+03f);
    }
}

void func_8009DBB0(void *player, s32 sound_id, f32 pitch_min, f32 pitch_max, s32 param_4)
{
    func_8009DB04(player, sound_id, func_800DC178(pitch_min, pitch_max), param_4);
}

void func_8009DBF0(PlayerState *player, s32 sound_id, f32 pitch)
{
    // Matching: the unused locals are needed for the match.
    f32 unk_0;
    f32 unk_1;
    s32 pos;

    func_8009DAAC(&sound_id, &pitch);
    func_8009C128(player, &pos);
    if (func_8009D3D8(player) != 0) {
        func_800C4208(sound_id, pitch, 0x55F0, &pos, 250.0f, 5.4e+03f);
    } else {
        func_800C4244(sound_id, pitch, 0x55F0, &pos, 250.0f, 5.4e+03f);
    }
}

void func_8009DC98(s32 player, s32 sound_id, f32 pitch_min, f32 pitch_max)
{
    func_8009DBB0(player, sound_id, pitch_min, pitch_max, 0x55F0);
}

// Plays a sound on the given sfx source, positional at the player when enabled.
void func_8009DCCC(void *player, u8 handle, s32 sound_id, f32 pitch, s32 param_4)
{
    f32 pos[3];
    func_8009DAAC(&sound_id, &pitch);
    func_8009C128(player, pos);
    func_800C2E40(handle);
    func_800C431C(handle, 0);
    if (func_8009D3D8(player))
        func_800C3418(handle, 1);
    else
        func_800C3418(handle, 0);
    if ((*(u8 **) ((u8 *) player + 0x104))[0x1C])
        func_800C35E8(handle, pos);
    else
        func_800C368C(handle, 0);
    func_800C33DC(handle, 0);
    func_800C330C(handle, 3);
    func_800C301C(handle, sound_id);
    func_800C31DC(handle, pitch);
    func_800C3058(handle, param_4);
    func_800C3BDC(handle);
}

s32 func_8009DDD0(s32 player)
{
    return ((u8 *) *(u8 **) (player + 0x104))[2];
}

void func_8009DDDC(PlayerState *player)
{
    s32 pos[3];
    func_8009C128(player, &pos);
    func_800C35E8(*(*(u8 **) ((char *) player + 0x104) + 3), &pos);
}

void func_8009DE14(void *player)
{
    func_800C3D78(*((u8 *) *(u32 **) ((u8 *) player + 0x104) + 2));
}

void func_8009DE38(PlayerState *player, s32 sound_id, f32 pitch)
{
    func_8009DCCC(player, *(u8 *) ((char *) *(void **) ((char *) player + 0x104) + 2), sound_id,
                  pitch, 0x55F0);
}

void func_8009DE74(PlayerState *player, s32 sound_id, f32 pitch_min, f32 pitch_max)
{
    func_8009DCCC(player, (*(u8 **) ((u8 *) player + 0x104))[2], sound_id,
                  func_800DC178(pitch_min, pitch_max), 0x55F0);
}

void func_8009DEC0(PlayerState *player, s32 sound_id, f32 pitch_min, f32 pitch_max, s32 param_4,
                   s32 param_5)
{
    s32 unk_0;
    f32 pitch;
    pitch = func_800DC178(pitch_min, pitch_max);
    unk_0 = func_800DC128(param_4, param_5);
    func_8009DCCC(player, (*(u8 **) ((u8 *) player + 0x104))[2], sound_id, pitch, unk_0);
}

void func_8009DF18(PlayerState *player, s32 sound_id, f32 pitch, s32 param_3)
{
    func_8009DCCC(player, (*(u8 **) ((u8 *) player + 0x104))[2], sound_id, pitch, param_3);
}

void func_8009DF58(PlayerState *player, s32 sound_id, f32 pitch)
{
    u8 handle = ((u8 *) *(s32 *) ((char *) player + 0x104))[3];
    func_8009DCCC(player, handle, sound_id, pitch, 0x55f0);
}

void func_8009DF94(PlayerState *player, s32 sound_id, f32 pitch, s32 param_3)
{
    func_8009DCCC(player, (*(u8 **) ((u8 *) player + 0x104))[3], sound_id, pitch, param_3);
}

void func_8009DFD4(PlayerState *player, s32 sound_id, f32 pitch_min, f32 pitch_max, s32 param_4,
                   s32 param_5)
{
    s32 unk_0;
    f32 pitch;
    pitch = func_800DC178(pitch_min, pitch_max);
    unk_0 = func_800DC128(param_4, param_5);
    func_8009DCCC(player, (*(u8 **) ((u8 *) player + 0x104))[3], sound_id, pitch, unk_0);
}

int func_8009E02C(int player)
{
    // Matching: the temporaries are needed for the match.
    int sound_id;
    f32 pitch;
    sound_id = 0x417;
    pitch = 0.8f;
    func_8009DF18(player, sound_id, pitch, 0x7FFF);
}

void func_8009E058(PlayerState *player)
{
    func_8009DF18(player, 0x417, 0.800000011920929f, 0x4650);
}

int func_8009E084(int player)
{
    func_8009DF18(player, 0x417, 1.0f, 14000);
}

void func_8009E0AC(u8 *player, unsigned long positional)
{
    *(s8 *) ((s8 *) *(u8 **) (0x104 + (s8 *) player) + 0x1C) = positional;
}

void func_8009E0B8(void *player)
{
    func_800C3CE8(**(u8 **) ((s8 *) player + 0x104));
}

void func_8009E0DC(PlayerState *player)
{
    func_800C3CE8(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x104) + 2));
}

void func_8009E100(PlayerState *player)
{
    func_800C3CE8(*(*(u8 **) ((u8 *) player + 0x104) + 3));
}

// TU-NOTE: the .data of this file is defined here in C; values are taken from the ROM.
s16 D_80119200[4] = {0x578, 0x579, 0x57A, 0x57B};
u8 D_80119208[8] = {0x5, 0x7C, 0x5, 0x7D, 0x5, 0x7E, 0x5, 0x7F};
s32 D_80119210[4] = {0x1060007, 0x0, 0x0, 0x0};
