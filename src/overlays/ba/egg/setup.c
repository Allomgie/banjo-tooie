// Egg spawning: stores spawn position, velocity and egg type, then spawns the right egg actor
// (deferred); variants for beak shots, rear laying and first person, plus shot/lay sounds.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_8009C128(PlayerState *, f32 *);
extern void func_800F3E84(PlayerState *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern f32 func_800DC0C0(void);
extern void _baeggsetup_entrypoint_1(s32);
extern u8 _baeggsetup_entrypoint_4[];
extern void func_80094C0C();
extern void _chbaddiesetup_entrypoint_1();
extern void func_800C4B64(f32);
extern void func_800C4B70(s32);
extern void func_800C4B7C(s32);
extern void func_8010D930(s32, s32, f32 *, void *);
extern u8 D_80800860_baeggsetup[];

s32 baeggsetup_entrypoint_0()
{
    return 0x28;
}

int func_80800008_baeggsetup(s32 param_0)
{
    return func_8009E674(param_0, 2) == 0;
}

// Deferred spawn callback: creates the egg actor for the stored egg type.
void baeggsetup_entrypoint_1(s32 param_0)
{
    f32 origin[3];
    f32 velocity[3];
    f32 pos[3];
    PlayerState *player;

    player = (PlayerState *) func_800F53D0();
    func_800EE7F8(origin, *(f32 **) ((u8 *) player + 0x70));
    func_800EE7F8(pos, *(f32 **) ((u8 *) player + 0x70) + 3);
    func_800EE7F8(velocity, *(f32 **) ((u8 *) player + 0x70) + 6);
    switch ((*(u8 **) ((u8 *) player + 0x70))[0x24]) {
        case 1:
            _cheggnormal_entrypoint_1(origin, pos, velocity, param_0);
            break;
        case 2:
            _cheggfire_entrypoint_1(origin, pos, velocity, param_0);
            break;
        case 3:
            _cheggice_entrypoint_1(origin, pos, velocity, param_0);
            break;
        case 4:
            _chegggrenade_entrypoint_2(origin, pos, velocity, param_0);
            break;
        case 5:
            _bababykaz_entrypoint_13(player);
            _cheggclockwork_entrypoint_1(origin, pos, velocity, param_0,
                                         func_80800008_baeggsetup(player));
            break;
        case 7:
            _chegggolden_entrypoint_1(origin, pos, velocity, param_0);
            break;
    }
}

// Lays an egg from the rear: stores position and velocity, spawn is deferred.
void baeggsetup_entrypoint_2(PlayerState *player, s32 egg_type, f32 height_offset, f32 distance)
{
    f32 origin[3];
    f32 rotation[3];
    f32 velocity[3];
    f32 pos[3];

    func_80094C0C(player);
    func_8009C128(player, pos);
    pos[1] += height_offset;
    func_800EE7F8(origin, pos);
    func_800F3E84(player, rotation);
    rotation[1] = func_800136E4(rotation[1] + 180.0f);
    func_800EEB9C(velocity, rotation[1], distance);
    func_800EF04C(pos, velocity);
    rotation[1] += func_800DC0C0() * 6.0f - 3.0f;
    func_800EEB9C(velocity, rotation[1], 200.0f);
    velocity[1] = func_800DC0C0() * 20.0f + 700.0f;
    func_800EE7F8(*(f32 **) ((u8 *) player + 0x70), origin);
    func_800EE7F8(*(f32 **) ((u8 *) player + 0x70) + 3, pos);
    func_800EE7F8(*(f32 **) ((u8 *) player + 0x70) + 6, velocity);
    (*(u8 **) ((u8 *) player + 0x70))[0x24] = egg_type;
    _chbaddiesetup_entrypoint_1(&_baeggsetup_entrypoint_1, *(s32 *) ((u8 *) player + 0x184));
}

// Spawns the egg actor for the given egg type.
void baeggsetup_entrypoint_3(param_0, egg_type, origin, pos, velocity) s32 param_0;
s32 egg_type;
s32 origin;
s32 pos;
s32 velocity;
{
    s32 player;
    // Matching: the copy of param_0 is needed for the match.
    s32 param_copy;
    param_copy = param_0;
    player = func_800F53D0();
    switch (egg_type) {
        case 1:
            _cheggnormal_entrypoint_2(origin, pos, velocity, param_copy);
            return;

        case 2:
            _cheggfire_entrypoint_2(origin, pos, velocity, param_0);
            return;

        case 3:
            _cheggice_entrypoint_2(origin, pos, velocity, param_copy);
            return;

        case 4:
            _chegggrenade_entrypoint_3(origin, pos, velocity, param_0);
            return;

        case 5:
            _bababykaz_entrypoint_13(player);
            _cheggclockwork_entrypoint_1(origin, pos, velocity, param_copy,
                                         func_80800008_baeggsetup(player));
            return;

        case 7:
            _chegggolden_entrypoint_2(origin, pos, velocity, param_copy);
            return;

        case 6:
            _cheggproximity_entrypoint_1(origin, pos, velocity, param_copy);
    }
}

// Deferred spawn callback: spawns from the position and velocity stored in the player state.
void baeggsetup_entrypoint_4(s32 param_0)
{
    u8 *spawn;

    spawn = *(u8 **) ((s8 *) func_800F53D0() + 0x70);
    baeggsetup_entrypoint_3(param_0, *(u8 *) ((s8 *) spawn + 0x24), spawn, spawn + 0xC,
                            spawn + 0x18);
}

// Shoots an egg from the beak: stores position and velocity, spawn is deferred.
void baeggsetup_entrypoint_5(PlayerState *player, s32 egg_type, f32 height_offset, f32 distance)
{
    f32 origin[3];
    f32 rotation[3];
    f32 velocity[3];
    f32 pos[3];

    func_80094C0C(player);
    func_8009C128(player, pos);
    pos[1] += height_offset;
    func_800EE7F8(origin, pos);
    func_800F3E84(player, rotation);
    func_800EEB9C(velocity, rotation[1], distance);
    func_800EF04C(pos, velocity);
    // Matching: self-assignment is needed for the match.
    rotation[1] = rotation[1];
    func_800EEB9C(velocity, rotation[1], 800.0f);
    velocity[1] = 0.0f;
    func_800EE7F8(*(f32 **) ((u8 *) player + 0x70), origin);
    func_800EE7F8(*(f32 **) ((u8 *) player + 0x70) + 3, pos);
    func_800EE7F8(*(f32 **) ((u8 *) player + 0x70) + 6, velocity);
    (*(u8 **) ((u8 *) player + 0x70))[0x24] = egg_type;
    _chbaddiesetup_entrypoint_1(_baeggsetup_entrypoint_4, *(s32 *) ((u8 *) player + 0x184));
}

// Same as above with caller-supplied position and velocity.
void baeggsetup_entrypoint_6(u8 *player, s32 egg_type, s32 origin, s32 pos, s32 velocity)
{
    func_80094C0C();
    func_800EE7F8(*(u8 **) ((s8 *) player + 0x70), origin);
    func_800EE7F8(*(u8 **) ((s8 *) player + 0x70) + 0xC, pos);
    func_800EE7F8(*(u8 **) ((s8 *) player + 0x70) + 0x18, velocity);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x70) + 0x24) = (s8) egg_type;
    _chbaddiesetup_entrypoint_1((s32 *) _baeggsetup_entrypoint_4,
                                *(s32 *) ((s8 *) player + 0x184));
}

s32 baeggsetup_entrypoint_7(s32 player, s32 callback)
{
    _chbaddiesetup_entrypoint_1(callback, *(s32 *) (player + 0x184));
}

// Plays the per-type egg sound.
void baeggsetup_entrypoint_8(PlayerState *player, s32 egg_type)
{
    s32 sfx_id;
    f32 unk_0;
    s32 type;
    f32 pos[3];

    sfx_id = 0;
    unk_0 = 1.0f;
    type = egg_type;
    switch (type) {
        case 1:
            sfx_id = 0x443E;
            break;
        case 2:
            sfx_id = 0x4590;
            break;
        case 3:
            sfx_id = 0x4597;
            break;
        case 4:
            sfx_id = 0x4591;
            break;
        case 5:
            sfx_id = 0x458F;
            break;
        case 6:
            sfx_id = 0x458F;
            break;
        case 7:
            sfx_id = 0x443E;
            break;
    }
    if (sfx_id) {
        func_8009C128(player, pos);
        func_8009DAAC(&sfx_id, &unk_0);
        func_800C4B64(unk_0);
        func_800C4B70(0x7FFF);
        func_800C4B7C(sfx_id);
        func_8010D930(11, -1, pos, D_80800860_baeggsetup);
    }
}

// Plays the egg sound for the player's current egg type.
void baeggsetup_entrypoint_9(PlayerState *player)
{
    s32 sfx_id = 0;
    f32 unk_0 = 1.4f;
    s32 egg_type;
    f32 pos[3];

    egg_type = func_80094510(player);
    switch (egg_type) {
        case 1:
            sfx_id = 0x42B;
            break;
        case 2:
            sfx_id = 0x42B;
            break;
        case 3:
            sfx_id = 0x42B;
            break;
        case 4:
            sfx_id = 0x42B;
            break;
        case 5:
            sfx_id = 0x42B;
            break;
        case 6:
            sfx_id = 0x42B;
            break;
        case 7:
            sfx_id = 0x42B;
            break;
    }
    if (sfx_id != 0) {
        func_8009C128(player, pos);
        func_8009DAAC(&sfx_id, &unk_0);
        func_800C4B64(unk_0);
        func_800C4B70(0x6D60);
        func_800C4B7C(sfx_id);
        func_8010D930(11, -1, pos, D_80800860_baeggsetup);
    }
}

void baeggsetup_entrypoint_10(s32 player)
{
    f32 pos[3];
    func_8009C128(player, pos);
    func_800C4B64(1.0f);
    func_800C4B70(0x7FFF);
    func_800C4B7C(0x4A5);
    func_8010D930(0xA, -1, pos, (s32 *) D_80800860_baeggsetup);
}

// TU-NOTE: the overlay .data (formerly asm/data/overlays/ba/egg/setup.data.s) is defined here in C.
// Values are from the ROM.
u8 D_80800860_baeggsetup[16] = {0x0, 0x21, 0x0, 0x1D, 0x0, 0x1E, 0x0, 0x14,
                                0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
