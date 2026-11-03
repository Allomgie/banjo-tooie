#include "core2/1E7BFA0.h"

extern s32 D_80119320[];
extern void func_80095870(s32, f32 *, f32 *);
extern s32 _fxsplash_entrypoint_2(f32 *, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_8009FC34(void *, s32);
extern f32 func_8009BB5C();
extern void func_8008FE94();
extern void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
extern void func_800BA22C(s32, s32);
extern PlayerState *func_800F53D0(s32);
extern s32 player_inWater(PlayerState *);
extern s32 func_8008FD48();
extern f32 _basnowball_entrypoint_5(PlayerState *);
extern void _basnowball_entrypoint_10(PlayerState *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern void func_8009DBF0(PlayerState *, s32, f32);
extern void func_8009DC98(PlayerState *, s32, f32, f32);
extern void _bashake_entrypoint_0(PlayerState *, s32, s32);
extern void _fxstep_entrypoint_10(s32, s32);
extern void _fxstep_entrypoint_13(s32, s32);
extern void _bsvan_entrypoint_2(PlayerState *);
extern void _bswasher_entrypoint_0(PlayerState *);
extern s32 func_8009E674(PlayerState *, s32);
extern s32 _bashoes_entrypoint_1(PlayerState *);
extern void func_8009C128(void *, f32 *);
extern void _fxstep_entrypoint_6(void *, f32 *);
extern f32 func_800964DC();
extern void _fxstep_entrypoint_5(void *, s32, f32);
extern void *baanim_getAnimCtrlPtr(void);
extern s32 anctrl_isAt(void *, f32);
extern void _fxstep_entrypoint_8(s32, f32, s32);
extern void _fxstep_entrypoint_9(s32 param_0);
extern void _fxstep_entrypoint_11(s32 param_0, f32 param_1, s32 param_2);
extern f32 D_801194D0[];
extern void func_800EFA4C(s32 param_0, f32 param_1, f32 param_2, f32 param_3);
extern u8 D_80119340[];
extern void _bsfirstp_entrypoint_6();
extern f32 _basnowball_entrypoint_4(void);
extern s32 D_80119430[];
struct AnotherStruct {
    char pad_0[0x44];
    int unk_44;
};
struct SomeStruct {
    char pad_0[0xA0];
    struct AnotherStruct *unk_A0;
};
extern s32 func_8008EF3C(s32, s32);
extern f32 func_8009C150(void);
extern s32 func_800F3ED0(s32);
extern s32 player_isStable(s32);
extern void bastatetimer_set(void *param_0, s32 param_1, f32 param_2);
extern f32 func_800963E4(void *param_0);
extern s32 func_80096434(void *param_0);
extern s32 func_8009650C(void *param_0);
extern s32 func_80096518(void *param_0);
extern s32 func_80096628(void *param_0);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
extern f32 func_800F13F0(f32 param_0, f32 param_1);
int func_800A2EDC(s32 param_0, f32 param_1);
void func_800A2EEC();
void func_800A2FCC();
void func_800A3148();

// Size of the footstep block (PlayerState+0x124).
s32 func_800A26B0()
{
    return 0xC;
}

// Spawns a water splash at the player.
void func_800A26B8(s32 player)
{
    f32 pos[3];
    f32 unk_1;
    f32 unk_2;
    f32 unk_3;
    func_8009C128(player, pos);
    unk_1 = func_800964DC(player);
    func_80095870(player, &unk_2, &unk_3);
    if (!(unk_2 + unk_3 < unk_1 - pos[1])) {
        pos[1] = unk_1;
        func_8009FC34(player, 1);
        func_800BABB8(_fxsplash_entrypoint_2(pos, 25.0f), 0, 0, 1.0f, D_80119320);
    }
}

// Spawns a splash at the footstep position.
void func_800A275C(u8 *player, s32 param_1)
{
    // Matching: unused pad local and volatile are needed for the match.
    s32 pad0;
    volatile f32 sp38;
    s32 pos;
    f32 extent;
    s32 splash;

    func_8009FC34(player, 2);
    extent = func_800F10B4(func_8009BB5C(player), 0.0f, 500.0f, 70.0f, 250.0f);
    func_8008FE94(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x124) + 4), &pos);
    if (param_1 == 0) {
        sp38 = func_800964DC(player);
    }
    splash = _fxsplash_entrypoint_2(&pos, 8.0f);
    func_800BA930(splash, (s16) -extent, 0x12C, (s16) -extent, (s16) extent, 0x15E, (s16) extent);
    func_800BA22C(splash, 5);
}

// Footstep callback: per-terrain sfx, screen shake and splashes.
void func_800A2848(s32 step, s32 event, s32 player_index)
{
    s32 unk_1;
    s32 in_water;
    s32 is_splash_event;
    PlayerState *player;
    player = func_800F53D0(player_index);
    is_splash_event = event == 4 || event == 11 || ((event == 21) != 0);
    in_water = player_inWater(player);
    if (is_splash_event)
        func_800A275C(player, event == 21);
    switch (func_8008FD48(player)) {
        case 15:
            if (is_splash_event || in_water)
                _fxstep_entrypoint_13(step, 14);
            else
                func_8009DB04(player, 0x448, 1.0f, 5000);
            break;
        case 14:
            _bashake_entrypoint_0(player, 0, 0);
            _fxstep_entrypoint_13(step, 19);
            if (event == 20)
                _fxstep_entrypoint_13(step, 20);
            break;
        case 19:
            _bashake_entrypoint_0(player, 0, 0);
            _fxstep_entrypoint_13(step, 22);
            break;
        case 1:
        case 11:
            if (func_8009E674(player, 0x80)) {
                switch (_bashoes_entrypoint_1(player)) {
                    case 4:
                        _fxstep_entrypoint_13(step, 23);
                        break;
                    case 5:
                        _fxstep_entrypoint_13(step, 26);
                        break;
                }
            }
    }
}

// Second footstep callback; same terrain handling with other step effects.
void func_800A2A00(s32 step, s32 event, s32 player_index)
{
    PlayerState *player;
    s32 terrain;
    f32 snow_amount;
    s32 shoe_type;
    s32 is_splash;
    f32 sfx_volume;

    player = func_800F53D0(player_index);
    is_splash = event == 4;
    if (is_splash == 0) {
        is_splash = event == 0xB;
        if (is_splash == 0) {
            is_splash = player_inWater(player) != 0;
        }
    }
    if (is_splash != 0) {
        func_800A26B8(player);
    }
    terrain = func_8008FD48();
    switch (terrain) {
        case 2:
            snow_amount = _basnowball_entrypoint_5(player);
            _basnowball_entrypoint_10(player);
            sfx_volume = func_800F10B4(snow_amount, 0.0f, 1.0f, 1.5f, 0.85f);
            func_8009DB04(player, 0x56E, sfx_volume,
                          (s32) func_800F10B4(snow_amount, 0.0f, 1.0f, 8000.0f, 32767.0f));
            if (snow_amount == 1.0f) {
                _bashake_entrypoint_0(player, 1, 2);
            }
            return;
        case 14:
            _fxstep_entrypoint_10(step, 0x13);
            if (event == 0x14) {
                _fxstep_entrypoint_13(step, 0x14);
            }
            _bashake_entrypoint_0(player, 3, 3);
            return;
        case 19:
            _fxstep_entrypoint_10(step, 0x16);
            _bashake_entrypoint_0(player, 3, 3);
            return;
        case 18:
            _bashake_entrypoint_0(player, 1, 2);
            return;
        case 16:
            func_8009DBF0(player, 0x4C7, 1.3f);
            _bashake_entrypoint_0(player, 1, 2);
            _bsvan_entrypoint_2(player);
            return;
        case 7:
            func_8009DC98(player, 0x4C1, 0.9f, 0.92f);
            _bashake_entrypoint_0(player, 1, 2);
            _bswasher_entrypoint_0(player);
            return;
        // Matching: stray empty statement after the case label.
        case 1:;
        case 11:
            if (func_8009E674(player, 0x80) != 0) {
                shoe_type = _bashoes_entrypoint_1(player);
                switch (shoe_type) {
                    case 4:
                        _fxstep_entrypoint_10(step, 0x17);
                        return;
                    case 5:
                        _fxstep_entrypoint_10(step, 0x1A);
                }
            }
    }
}

void func_800A2C84(player) void *player;
{
    f32 pos_buf[4];
    s32 flags;
    func_8009C128(player, &pos_buf[1]);
    _fxstep_entrypoint_6(**(void ***) ((u8 *) player + 0x124), &pos_buf[1]);
    flags = func_80096628(player);
    _fxstep_entrypoint_5(**(void ***) ((u8 *) player + 0x124), flags, func_800964DC(player));

}

void func_800A2CE8(PlayerState *player, f32 frame, s32 step_kind)
{
    if (anctrl_isAt(baanim_getAnimCtrlPtr(), frame)) {
        func_800A2EEC(player, step_kind);
    }

}

void func_800A2D2C(PlayerState *player, f32 frame, s32 step_kind)
{
    void *anim_ctrl = baanim_getAnimCtrlPtr();

if (anctrl_isAt(anim_ctrl, frame)) {
    func_800A2FCC(player, step_kind);
}

}

// Frees the footstep effect.
void func_800A2D70(u8 *player)
{
    _fxstep_entrypoint_0(*(*(s32 **) ((s8 *) (player) + (0x124))));
}

// Creates the footstep effect and registers the two step callbacks.
void func_800A2D94(u8 *player)
{
    *(*(s32 **) ((s8 *) (player) + (0x124))) = _fxstep_entrypoint_1();
    func_800A2EDC(player, 1.0f);
    _fxstep_entrypoint_3(*(*(s32 **) ((s8 *) (player) + (0x124))), func_800D3948() == 0);
    _fxstep_entrypoint_4(*(*(s32 **) ((s8 *) (player) + (0x124))), &func_800A2A00,
                         (*(s32 *) ((s8 *) (player) + (0x184))));
    _fxstep_entrypoint_7(*(*(s32 **) ((s8 *) (player) + (0x124))), &func_800A2848,
                         (*(s32 *) ((s8 *) (player) + (0x184))));
}

void func_800A2E18(Actor *player)
{
    s32 state;
    void *block;

    state = bs_getCurrentState();
    func_800A2C84(player);

if ((func_8009CBDC(player, state) == 8) || (func_8009CA70(player, state, 0x40) != 0)) {
    block = *(void **) ((char *) player + 0x124);
    _fxstep_entrypoint_8(*(s32 *) ((char *) block + 0), 0.2f, *(s32 *) ((char *) block + 8));
    return;
}

block = *(void **) ((char *) player + 0x124);
_fxstep_entrypoint_8(*(s32 *) ((char *) block + 0), 0, *(s32 *) ((char *) block + 8));
}

void func_800A2EAC(void *player)
{
    char *base;
    base = (char *) player;
    func_800A2C84();
    _fxstep_entrypoint_9(*(*((s32 **) (base + 0x124))));
}

func_800A2EDC(s32 player, f32 volume)
{
    f32 value;
    value = volume;
    *(f32 *) (*(s32 *) (player + 0x124) + 0x8) = value;
}

void func_800A2EEC(player, step_kind) u8 *player;
s32 step_kind;
{
    s32 state;
    u8 *block_a;
    u8 *block_b;

    state = bs_getCurrentState();
    func_800A2C84(player);
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x124)))) + (4))) = (s8) step_kind;

if ((func_8009CBDC(player, state) == 8) || (func_8009CA70(player, state, 0x40) != 0)) {
    block_a = *(u8 **) ((s8 *) player + 0x124);
    _fxstep_entrypoint_11(*(s32 *) ((s8 *) block_a + 0), 0.2f, *(s32 *) ((s8 *) block_a + 8));
    return;
}

block_b = (*(u8 **) ((s8 *) (player) + (0x124)));
_fxstep_entrypoint_11((*(s32 *) ((s8 *) (block_b) + (0))), 0.0f,
                      (*(s32 *) ((s8 *) (block_b) + (8))));
}

void func_800A2F90(u8 *player, s32 step_kind)
{
    _fxstep_entrypoint_2(*(*(s32 **) ((s8 *) (player) + (0x124))), 0);
    func_800A2EEC(player, step_kind);
}

void func_800A2FCC(player, step_kind) u8 *player;
s32 step_kind;
{
    func_800A2C84();
    *((s8 *) (((char *) (*((u8 **) (player + 0x124)))) + 4)) = (s8) step_kind;
    {
        s32 *temp_var;

// Matching: empty block steers IDO's register allocation.
if (player) {
}

_fxstep_entrypoint_12(*(*((s32 **) (((char *) player) + 0x124))));
}
}

void func_800A300C(u8 *player)
{
    *(*(s32 **) ((s8 *) (player) + (0x124))) =
        func_800BC3F0(*(*(s32 **) ((s8 *) (player) + (0x124))));
}

// Size of the common player state block (PlayerState+0xA0).
s32 func_800A3040()
{
    return 0x58;
}

// Scale for the current transformation (D_801194D0).
f32 func_800A3048(u8 *player)
{
    if (func_800D3E40(7) == 0) {
        return 1.0f;
    }
    if (func_8008E40C(player) != 0) {
        return 1.2f;

}
return *(f32 *) ((u8 *) D_801194D0 + (*(u8 **) (player + 0xA0))[0x29] * 4);
}

void func_800A30B4(s32 player, s32 box_min, s32 box_max)
{
    f32 radius;
    f32 center_y;
    f32 height;
    f32 half_height;

    func_800A3148(player, &radius, &center_y, &height);
    half_height = height * 0.5f;
    func_800EFA4C(box_min, -radius, center_y - half_height, -radius);
    func_800EFA4C(box_max, radius, center_y + half_height, radius);
}

// Collision size for the transformation (D_80119340).
void func_800A3148(player, radius, center_y, height) u8 *player;
f32 *radius;
f32 *center_y;
f32 *height;
{
    u8 transformation;
    u8 *entry;

    transformation = *(u8 *) ((char *) *(u8 **) ((char *) player + 0xA0) + 0x29);
    entry = D_80119340 + (transformation * 12);
    *radius = *(f32 *) ((char *) entry + 0);
    *center_y = *(f32 *) ((char *) entry + 4);
    *height = *(f32 *) ((char *) entry + 8);

    switch (transformation) {
        case 2: {
            f32 scale = _basnowball_entrypoint_4();
            *radius *= scale;
            *center_y *= scale;
            *height *= scale;
        }

return;
case 9:
    _bsfirstp_entrypoint_6();
    }
    }

    // Collision size for the transformation (D_80119430).
    void func_800A3200(u8 *player, f32 *radius, f32 *height)
    {
        f32 scale;
        u32 transformation;
        u8 *entry;

        transformation = (*(u8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x29)));
        entry = (u8 *) ((transformation * 8) + (u8 *) D_80119430);
        *radius = (*(f32 *) ((s8 *) (entry) + (0)));
        *height = (*(f32 *) ((s8 *) (entry) + (4)));
        if (transformation == 2) {
            scale = _basnowball_entrypoint_4();
            *radius *= scale;
            *height *= scale;
        }
    }

    // Returns the current transformation id.
    TransformationId func_800A3274(PlayerState *player)
    {
        return ((u8 *) ((*(s32 *) ((char *) (player) + 160))))[0x29];
    }

    s32 func_800A3280(s32 player)
    {
        return ((u8 *) (*(u8 **) (player + 0xa0)))[0x2A];
    }

    f32 func_800A328C(u8 *player)
    {
        return *(f32 *) ((char *) (*(u8 **) ((char *) player + 0xA0)) + 0x48);
    }

    f32 func_800A3298(PlayerState *player)
    {
        return *(f32 *) (((u8 *) *(void **) ((u8 *) player + 0xA0)) + 0x48) - func_800964DC();
    }

    void func_800A32C4(PlayerState *player, f32 vec[3])
    {
        int new_var;
        s32 new_var2;
        int new_var5;
        s32 new_var4;
        s32 *new_var3;
        new_var = 0xA0;
        new_var3 = (s32 *) (((s32) player) + new_var);
        // Matching: dead test and temporaries are needed for the match.
        if (((new_var5 = vec && vec) && vec) != 0) {
        }
        new_var4 = *new_var3;
        new_var2 = new_var4;
        func_800EE7F8((s32) vec, new_var2);
    }

    s32 func_800A32EC(s32 player)
    {
        short new_var;
        u8 new_var2;
        new_var = 0x2B;
        new_var2 = ((u8 *) ((s32 **) (player + 0xA0))[0])[new_var];
        return new_var2;
    }

    int func_800A32F8(struct SomeStruct *player)
    {
        return player->unk_A0->unk_44;
    }

    int func_800A3304(s32 player)
    {
        s32 *new_var;
        s32 result;
        new_var = &player;
        result = func_800F8B88(*new_var);
        return result == 1;
    }

    void func_800A3328(s32 player, s32 vec)
    {
        s32 new_var;
        int new_var2;
        new_var = vec;
        new_var2 = 0x2C;
        func_800EE7F8(new_var | 0, ((s32 *) player)[0x28] + new_var2);
    }

    s32 func_800A3354(s32 player)
    {
        return ((u8 *) (*(&(*((u8 **) (player + 160))))))[84];
    }

    s32 func_800A3360(s32 player)
    {
        u8 new_var;
        new_var = ((u8 **) (player + 0xA0))[0][0x55];
        return new_var;
    }

    s32 func_800A336C(void *player)
    {
        return ((u8 *) (*(void **) ((char *) player + 0xA0)))[60];
    }

    f32 func_800A3378(f32 *player)
    {
        unsigned int new_var;
        new_var = 0x28;
        // Matching: odd casts are needed for the match.
        return ((f32 **) player)[new_var][0xE] * ((unsigned int) 1.5f);
    }

    f32 func_800A3394(PlayerState *player)
    {
        return *(f32 *) ((char *) (*(struct ba_input_s **) ((char *) player + 0xA0)) + 0x24);
    }

    void func_800A33A0(PlayerState *player, f32 *vec)
    {
        char *new_var;
        // Matching: if (1) wrapper is needed for the match.
        if (1) {
            new_var = vec;
        }
        func_800EE7F8(
            new_var,
            new_var = ((char *) (*((struct ba_unknown_C0_s **) (((char *) player) + 0xA0)))) + 12);
    }

    void func_800A33CC(PlayerState *player, f32 *vec)
    {
        char *new_var;
        // Matching: if (1) wrapper is needed for the match.
        if (1) {
            new_var = vec;
        }
        func_800EE7F8(
            new_var,
            new_var = ((char *) (*((struct ba_unknown_C0_s **) (((char *) player) + 0xA0)))) + 24);
    }

    u8 func_800A33F8(s32 player)
    {
        s32 new_var4;
        int new_var2;
        u8 new_var3;
        s32 new_var;
        u8 **new_var5;
        new_var = player;

        new_var5 = (u8 **) (new_var4 = new_var);
        new_var2 = 0x28;
        new_var3 = new_var5[new_var2][new_var2];
        return new_var3;
    }

    s32 func_800A3404(s32 player)
    {
        return ((u8 *) (*(u8 **) (player + 0xa0)))[0x3F];
    }

    // Sets the transformation id and toggles effects when entering or leaving id 0xA.
    void func_800A3410(PlayerState *player, s32 transformation)
    {
        if ((*((u8 *) (((char *) (*((s32 *) (((char *) player) + 0xA0)))) + 0x29))) == 0xA) {
            func_800947EC(player, 1, 0);
            func_800A0D68(player, 0);
        }
        *((u8 *) (((char *) (*((s32 *) (((char *) player) + 0xA0)))) + 0x29)) = transformation;
        if ((*((u8 *) (((char *) (*((s32 *) (((char *) player) + 0xA0)))) + 0x29))) == 0xA) {
            func_800947EC(player, 1, 1);
            func_800A0D68(player, 1);
        }
    }

    void func_800A34A0(void *player, s32 value)
    {
        ((s8 *) (*(void **) ((char *) player + 0xA0)))[42] = value;
    }

    void func_800A34AC(PlayerState *player, f32 vec[3])
    {
        func_800EE7F8(((s32 *) player)[0x28], vec);
    }

    void func_800A34CC(void *player, s32 value)
    {
        ((s8 *) (*(void **) ((char *) player + 0xA0)))[43] = value;
    }

    func_800A34D8(s32 player, s32 value)
    {
        *(s32 *) (*(s32 *) (player + 0xA0) + 0x44) = value;
    }

    void func_800A34E4(void *player, s32 value)
    {
        ((s8 *) (*(void **) ((char *) player + 0xA0)))[60] = value;
    }

    void func_800A34F0(Actor *player)
    {
        char *new_var;
        // Matching: the new_var temporaries are needed for the match.
        new_var = new_var + 0x58;
        func_800EE7F8((*((s32 *) ((char *) player + 160))) + 12);
    }

    void func_800A3514(Actor *player)
    {
        char *new_var;
        s32 *new_var2;
        new_var = (char *) player;
        new_var = new_var + 0x58;
        new_var = new_var + 0x48;
        new_var2 = &(*((s32 *) new_var));
        func_800EE7F8((*new_var2) + 24);
    }

    void func_800A3538(void *player, s32 value)
    {
        ((s8 *) (*(void **) ((char *) player + 0xA0)))[40] = value;
    }

    void func_800A3544(u8 *player, int value)
    {
        *((s8 *) ((*((u8 **) (player + 0xA0))) + 0x3F)) = value;
    }

    void func_800A3550(void *player, s32 value)
    {
        ((s8 *) (*(void **) ((char *) player + 0xA0)))[80] = value;
    }

    void func_800A355C(s32 player)
    {
        f32 height;
        s32 unk_1;
        height = func_8009C150();
        unk_1 = func_800F3ED0(player);
        if ((((player_isStable(player) != 0) || (player_inWater(player) != 0)) ||
             ((unk_1 == 0xA) && (func_8008EF3C(player, 0) != 3))) ||
            (unk_1 == 5)) {
            func_800A3550(player, 1);
        } else {
            func_800A3550(player, 2);
        }
        if (((*((u8 *) (((char *) (*((s32 **) (((char *) player) + 0xA0)))) + 0x50))) != 2) ||
            (!(height <=
               (*((f32 *) (((char *) (*((s32 **) (((char *) player) + 0xA0)))) + 0x4C)))))) {
            *((f32 *) (((char *) (*((s32 **) (((char *) player) + 0xA0)))) + 0x48)) =
                *((f32 *) (((char *) (*((s32 **) (((char *) player) + 0xA0)))) + 0x4C));
            *((f32 *) (((char *) (*((s32 **) (((char *) player) + 0xA0)))) + 0x4C)) = height;

}
}

// Updates the slope-slide accumulator and starts the slide state timers.
void func_800A3644(void *player)
{
    f32 rate;
    f32 speed;
    f32 dt;
    s32 ground_flags;
    s32 alt_flags;
    dt = func_800D8FF8();
    speed = func_800963E4(player);
    ground_flags = func_80096628(player);
    if (*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xA0) + 0x3D) != 0) {
        if (speed > 35.0f) {
            *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xA0) + 0x38) = 1.0f;
        }

else
{
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0xA0)))) + 0x38)) = 0.0f;
}
}
else
{
    rate = func_800F10B4(speed, 20.0f, 60.0f, 0.6f, 1.3f);

if ((func_80096518(player) == 0) && !(ground_flags & 0x50)) {
    alt_flags = func_80096434(player);
    if ((func_8009650C(player) != 0) && (alt_flags & 0x50)) {
        ground_flags = alt_flags;
    }
}

if ((ground_flags & 0x50) && (player_inWater(player) == 0)) {
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xA0) + 0x38) = func_800F13F0(
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xA0) + 0x38) + (dt * rate), 1.0f);
}

else
{
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xA0) + 0x38) = 0.0f;
}
if (*(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xA0) + 0x38) == 1.0f) {
    if (ground_flags & 0x10) {
        bastatetimer_set(player, 5, 0.18f);
    } else if (ground_flags & 0x40) {
        bastatetimer_set(player, 6, 0.18f);
    }
}

}
*((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0xA0)))) + 0x3D)) = 0;
}

void func_800A380C(Actor *player)
{
    *(f32 *) ((char *) (*(s32 **) ((char *) player + 0xA0)) + 0x38) = 0.98f;
}

void func_800A3820(u8 *player)
{
    extern f32 func_8009C150();
    f32 local_0;

    func_800EFD24((*(u8 **) ((s8 *) (player) + (0xA0))));
    func_800EFD24((*(u8 **) ((s8 *) (player) + (0xA0))) + 0xC);
    func_8009C128(player, (*(u8 **) ((s8 *) (player) + (0xA0))) + 0x2C);
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x3D))) = 0;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x38))) = 0.0f;
    func_800A380C(player);
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x3C))) = 1;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x40))) = 0.0f;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x50))) = 0;
    local_0 = func_8009C150(player);
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x48))) = local_0;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x4C))) = local_0;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x29))) = 0;
    func_800A3410(player, func_8009E958());
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x54))) = 1;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x55))) = 1;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xA0)))) + (0x3E))) = 1;
}

void func_800A38F0(PlayerState *player, s32 param_1, s32 param_2)
{
    *(u8 *) ((char *) ((*(s32 *) ((char *) (player) + 160))) + 0x54) = param_1;
    *(u8 *) ((char *) ((*(s32 *) ((char *) (player) + 160))) + 0x55) = param_2;
}

void func_800A3904(PlayerState *player, s32 value)
{
    *(u8 *) (*(s32 *) ((char *) player + 0xA0) + 0x3E) = value;
}

void func_800A3910(void *player, s32 value)
{
    ((s8 *) (*(void **) ((char *) player + 0xA0)))[61] = value;
}

int func_800A391C(s32 player, f32 value)
{
    int new_var;
    new_var = player;
    {
        *((f32 *) ((*((s32 *) ((char *) (new_var) + 160))) + 36)) = value;
    }
}

int func_800A392C(s32 player, s32 sound_id)
{
    f32 local_0[3];
    func_8009C128(player, local_0);
    func_800C05B8(sound_id, 2, local_0, 0, 0, 0, 0);
}

// Plays a hurt sound with a cooldown; the default depends on the transformation.
s32 func_800A3970(PlayerState *player, s32 sound_id)
{
    f32 *state;
    s32 transformation;

    state = *(f32 **) ((char *) player + 0xA0);
    if (state[0x10] != 0.0f) {
        return 0;
    }
    state[0x10] = 10.0f;
    if (func_800A3274(player) == 0x11) {
        func_8009E7C8(player, 0x1F);
    }
    if (sound_id != 0) {
        return func_800A392C(player, sound_id);
    }
    transformation = func_800A3274(player);
    switch (transformation) {
        case 10:
            return func_800A392C(player, 0x1212);
        case 11:
            return func_800A392C(player, 0x1213);
        case 13:
            return func_800A392C(player, 0x1214);
        case 17:
            return func_800A392C(player, 0x1216);
        default:
            return func_800A392C(player, 0x1217);
    }
}

// Per-frame update of the common player state.
void func_800A3A80(Actor *player)
{
    u8 **state;

    state = (*(s32 *) ((char *) (player) + 0xA0));
    if ((*(f32 *) ((char *) (state) + 0x40)) != 0.0f) {
        func_800D9078(&(*(s32 *) ((char *) (state) + 0x40)));
    }
    if (player_isStable(player)) {
        func_8009C128(player, (*(s32 *) ((char *) (player) + 0xA0)) + 0x2C);
    }
    if ((player_isStable(player) != 0) || (func_8009E71C(player, 0xA) != 0)) {
        baflag_clear(player, 5);
        baflag_clear(player, 0x12);
    }
    if (player_inWater(player) != 0) {
        baflag_clear(player, 5);
        baflag_clear(player, 0x12);
    }
    func_800A3644(player);
    func_800A355C(player);
    if (func_80096568(player, 0x600) != 0) {
        func_8009BD18(player, 0x3F400000);
    }
}

// TU-NOTE: the .data of this file is defined here in C; values taken from the ROM.
s32 D_80119320[8] = {0x2CFEA2, 0x12CFEA2, 0x15E01F4, 0x15E0A1A, 0x0, 0x0, 0x0, 0x0};
// 12 bytes per transformation: collision size.
u8 D_80119340[240] = {
    0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0,
    0x42, 0x82, 0x0, 0x0, 0x42, 0xF0, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0,
    0x42, 0xC8, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0,
    0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0,
    0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0,
    0x42, 0xC8, 0x0, 0x0, 0x42, 0xB4, 0x0, 0x0, 0x42, 0x96, 0x0, 0x0, 0x43, 0x16, 0x0, 0x0,
    0x42, 0x48, 0x0, 0x0, 0x42, 0x34, 0x0, 0x0, 0x42, 0x8C, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0,
    0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0x82, 0x0, 0x0,
    0x42, 0xF0, 0x0, 0x0, 0x42, 0x20, 0x0, 0x0, 0x42, 0x82, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0,
    0x42, 0xAA, 0x0, 0x0, 0x42, 0x82, 0x0, 0x0, 0x43, 0x2,  0x0, 0x0, 0x42, 0x48, 0x0, 0x0,
    0x42, 0x94, 0x0, 0x0, 0x43, 0xC,  0x0, 0x0, 0x43, 0x16, 0x0, 0x0, 0x43, 0x96, 0x0, 0x0,
    0x44, 0x16, 0x0, 0x0, 0x42, 0x20, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0,
    0x42, 0xC8, 0x0, 0x0, 0x42, 0x94, 0x0, 0x0, 0x43, 0x14, 0x0, 0x0, 0x41, 0xC8, 0x0, 0x0,
    0x41, 0xF0, 0x0, 0x0, 0x42, 0x70, 0x0, 0x0, 0x42, 0xB4, 0x0, 0x0, 0x42, 0x96, 0x0, 0x0,
    0x43, 0x16, 0x0, 0x0, 0x43, 0x96, 0x0, 0x0, 0x43, 0x96, 0x0, 0x0, 0x44, 0x16, 0x0, 0x0};
// 8 bytes per transformation: collision size.
s32 D_80119430[40] = {
    0x42480000, 0x42480000, 0x42820000, 0x42820000, 0x42480000, 0x42480000, 0x42480000, 0x42480000,
    0x42480000, 0x42480000, 0x42480000, 0x42480000, 0x42480000, 0x42480000, 0x42A80000, 0x42A80000,
    0x42480000, 0x42480000, 0x42480000, 0x42480000, 0x42820000, 0x42820000, 0x42820000, 0x42820000,
    0x42B40000, 0x42B40000, 0x428C0000, 0x428C0000, 0x43960000, 0x43960000, 0x42480000, 0x42480000,
    0x42F00000, 0x42700000, 0x41C80000, 0x41C80000, 0x42A80000, 0x42A80000, 0x43960000, 0x43960000};
// Scale per transformation.
f32 D_801194D0[16] = {1.0f, 1.6f, 1.6f, 1.0f, 1.0f, 1.0f, 1.6f, 1.6f,
                      1.4f, 1.6f, 1.6f, 1.6f, 1.6f, 1.6f, 1.6f, 1.6f};
