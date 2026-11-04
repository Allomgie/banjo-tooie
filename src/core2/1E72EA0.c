#include "core2/1E72EA0.h"

f32 func_80090010(void);
void func_800EFCD8(f32 *, f32, f32);
extern f32 yaw_get(s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_80094430(s32, f32);
extern int func_800A391C(s32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void _bashoes_entrypoint_12(PlayerState *, f32);
extern void _baduo_entrypoint_20(void *, void *, f32);
extern void _baduo_entrypoint_9(PlayerState *, f32);
extern void _bainvisible_entrypoint_5(PlayerState *, f32);
// Interrupt payload: PlayerState+0xC0, with the 5-entry deferred queue at 0x4C.
typedef struct {
    s32 code;
    u8 pad_04[36];
} QueueEntry;
typedef struct {
    u8 pad_00[8];
    f32 pos[3];
    s32 marker;
    s32 unk_18;
    u8 pad_1C[0x30];
    QueueEntry queue[5];
} Sub;
typedef struct {
    u8 pad_00[0xC0];
    Sub *payload;
} Akteur;
void func_800EFD24(f32 *);
void func_8009ACF4(s32 param_0, f32 param_1);
int func_8009AD04(s32 param_0, f32 param_1);
void func_8009AD14();
int func_8009AD20();
void func_8009AD44();

// Size of the interrupt payload struct.
s32 func_800995B0(void)
{
    return sizeof(BaUnknownC0);
}

void func_800995B8(PlayerState *player, s32 mode)
{
    f32 buf[6]; // [0..2] offset, [3..5] position
    f32 yaw;
    func_800A34CC(player, 1);
    switch (mode) {
        case 0:
            func_800EC398(*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC0) + 0x14), &buf[3],
                          mode);
            func_800A34AC(player, &buf[3]);
            return;

        case 1:
            func_800A34AC(player, *(u8 **) ((s8 *) player + 0xC0) + 8, mode);
            return;

        case 2:
            func_8008FE68(&buf[3]);
            yaw = func_80090010();
            func_800EFCD8(&buf[0], yaw, 100.0f);
            buf[1] = 0.0f;
            buf[3] += buf[0];
            buf[4] += buf[1];
            buf[5] += buf[2];
            func_800A34AC(player, &buf[3]);
            func_800A34CC(player, *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC0) + 0x1C));
            return;

        case 3:
            func_800A34AC(player, *(u8 **) ((s8 *) player + 0xC0) + 8, mode);
    }
}

int func_800996E0(s32 player)
{
    s32 health;
    s32 delta;
    health = func_800A1718();
    if (health < 2) {
        func_800A17A8(player, -health);
        return 0;
    }
    {
        delta = 1 - health;
        func_800A17A8(player, delta);
        return 1;
    }
}

int func_80099730(s32 player, s32 param_1)
{
    // Matching: the "| 0" on player is needed for the match.
    func_8009AD20(player | 0, 0xD);
    func_800995B8(player | 0, 2);
    if (param_1 != 0) {
        func_800996E0(player | 0);
    } else {
        func_800A17A8(player | 0, -1);
    }
    if (func_800A1718(player | 0)) {
        _badata_entrypoint_26(player | 0);
    } else {
        _badata_entrypoint_20(player | 0);
    }
}

void func_800997BC(s32 player)
{
    f32 offset[3];
    f32 pos[3];

    func_8009C128(player, pos);
    func_800EEB9C(offset, yaw_get(player), 100.0f);
    pos[0] += offset[0];
    pos[1] += offset[1];
    pos[2] += offset[2];
    func_800A34AC(player, pos);
    func_800A17A8(player, -1);
}

int func_80099840(s32 player, s32 param_1)
{
    s32 health;
    s32 cond;
    int zero; // Matching: needed for the match.
    // Matching: the goto/label pair is needed for the match.
    goto dummy_label_22716;
dummy_label_22716:;
    zero = 0;
    health = func_800A1718();
    cond = param_1 == zero;
    if (cond != zero) {
        cond = health != zero;
    }
    health = cond;
    if (health != zero) {
        _badata_entrypoint_26(player);
        return;
    }
    _badata_entrypoint_20(player);
}

// Queue an interrupt for deferred replay; ignored if already queued.
void func_8009989C(void *player, s32 code)
{
    s32 offset;
    u8 *payload;
    u8 *slot;
    s32 entry_offset; // Matching: extra temporary, needed for the match.
    payload = *(u8 **) ((u8 *) player + 0xC0);
    offset = 0;
    slot = payload;
    do {
        if (*(s32 *) (slot + 0x4C) == code) {
            return;
        }
        offset += 0x28;
        slot += 0x28;
    } while (offset < 0xC8);
    offset = 0;
    slot = payload;
    do {
        if (*(s32 *) (slot + 0x4C) == 0) {
            *(s32 *) (slot + 0x4C) = code;
            payload = *(u8 **) ((u8 *) player + 0xC0);
            *(s32 *) ((payload + offset) + 0x40) = *(s32 *) (payload + 0x18);
            payload = *(u8 **) ((u8 *) player + 0xC0);
            *(f32 *) ((payload + offset) + 0x28) = *(f32 *) (payload + 0x0);
            entry_offset = offset;
            payload = *(u8 **) ((u8 *) player + 0xC0);
            *(f32 *) ((payload + entry_offset) + 0x2C) = *(f32 *) (payload + 0x4);
            payload = *(u8 **) ((u8 *) player + 0xC0);
            offset = 0x14;
            *(s32 *) ((payload + entry_offset) + 0x3C) = *(s32 *) (payload + offset);
            payload = *(u8 **) ((u8 *) player + 0xC0);
            func_800EE7F8((payload + entry_offset) + 0x30, payload + 0x8);
            return;
        }
        offset += 0x28;
        slot += 0x28;
    } while (offset != 0xC8);
}

// Replay one queued interrupt per call.
void func_80099970(u8 *player)
{
    s32 code;
    s32 offset;
    u8 *entry;
    u8 *slot;

    slot = *(u8 **) ((s8 *) player + 0xC0);
    offset = 0;
loop_1:
    if (*(s32 *) ((s8 *) slot + 0x4C) != 0) {
        func_8009ACF4(player, *(f32 *) ((s8 *) slot + 0x28));
        func_8009AD04(player,
                      *(f32 *) ((s8 *) (*(u8 **) ((s8 *) player + 0xC0) + offset) + 0x2C));
        func_8009AD14(player,
                      *(s32 *) ((s8 *) (*(u8 **) ((s8 *) player + 0xC0) + offset) + 0x3C));
        func_8009AD20(player,
                      *(s32 *) ((s8 *) (*(u8 **) ((s8 *) player + 0xC0) + offset) + 0x40));
        func_8009AD44(player, *(u8 **) ((s8 *) player + 0xC0) + offset + 0x30);
        entry = *(u8 **) ((s8 *) player + 0xC0) + offset;
        code = *(s32 *) ((s8 *) entry + 0x4C);
        *(s32 *) ((s8 *) entry + 0x4C) = 0;
        func_8009E7C8(player, code);
        return;
    }
    offset += 0x28;
    slot += 0x28;
    if (offset == 0xC8) {
        return;
    }
    goto loop_1;
}

// Interrupt payload getters (PlayerState+0xC0).
f32 func_80099A34(PlayerState *player)
{
    return player->unkC0->unk0;
}

f32 func_80099A40(PlayerState *player)
{
    return player->unkC0->unk4;
}

s32 func_80099A4C(PlayerState *player)
{
    return player->unkC0->unk14;
}

s32 func_80099A58(PlayerState *player)
{
    return player->unkC0->unk18;
}

s32 func_80099A64(PlayerState *player)
{
    return player->unkC0->unk1C;
}

s32 func_80099A70(PlayerState *player)
{
    return player->unkC0->unk20;
}

void func_80099A7C(PlayerState *player, f32 *out)
{
    char *tmp;
    // Matching: the if (1) and tmp reuse are needed for the match.
    if (1) {
        tmp = out;
    }
    func_800EE7F8(tmp,
                  tmp = (char *) *(struct ba_unknown_C0_s **) ((char *) player + 0xC0) + 8);
}

// Queues some interrupts, forwards others to the default dispatcher, else resets to state 0.
void func_80099AA8(PlayerState *player)
{
    s32 code = func_8009E6EC(player);

    switch (code) {
        case 0xF:
        case 0x13:
        case 0x26:
        case 0x2A:
        case 0x30:
            func_8009989C(player, code);
            break;

        case 0x27:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x4D:
        case 0x62:
        case 0x63:
        case 0x6B:
        case 0x6C:
        case 0x7C:
        case 0x7D:
        case 0x81:
        case 0x89:
        case 0x91:
        case 0x98:
        case 0x9A:
            func_80099B94(player);
            return;
    }

    func_8009E830(player, 1);
    bs_setState(player, 0);
}

int func_80099B54(Actor *player)
{
    Actor *marker;
    marker = func_80099A4C(player);
    func_8009EAE8((u32) (*(s32 *) ((u8 *) func_80106790(marker) + 0x6C) << 11) >> 20);
    _badata_entrypoint_33(player);
}

// Default interrupt dispatcher: maps the current interrupt code to a state change.
void func_80099B94(player) PlayerState *player;
{
    s32 state_tmp;
    s32 cur_state;
    u8 *payload_a;
    s32 result;
    s32 damage_a;
    s32 damage_b;
    s32 unk_0;
    s32 state;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 marker;
    s16 unk_4[1];
    s16 unk_5[1];
    u8 *payload_b;
    u8 *payload_c;
    s32 unk_6;
    result = 1;
    state = 0;
    cur_state = bs_getCurrentState();

switch (func_8009E6EC(player)) {
    case 57:
        baflag_set(player, 37);
        baflag_set(player, 46);
        baflag_set(player, 36);
        state = _badrone_entrypoint_24(player);
        result = 2;
        goto block_180;
    case 94:
        baflag_set(player, 37);
        baflag_set(player, 58);
        baflag_set(player, 36);
        _bafpctrl_entrypoint_11(player, 6, 1);
        state = _badrone_entrypoint_24(player);
        result = 2;
        goto block_180;
    case 105:
        baflag_set(player, 36);
        if (func_8009E71C(player, 9)) {
            baflag_set(player, 47);
            baflag_set(player, 48);
            _bafpctrl_entrypoint_11(player, 14, 1);
        } else
            state = _badrone_entrypoint_24(player);
        result = 2;
        goto block_180;
    case 10:
        result = 2;
        state = _badrone_entrypoint_28(player);
        goto block_180;
    case 81:
        if (func_8008DD90(player) == 0) {
            func_8009AD20(player, 1);
            case 106:
                damage_a = func_80099A58(player);
                if (damage_a)
                    func_800A17A8(player, -damage_a);
                if (func_800A1718(player) == 0) {
                    state = func_80099840(player, 1);
                } else
                    state = _badrone_entrypoint_17(player);
                result = 2;
        }
        goto block_180;
    case 82:
        damage_b = func_80099A58(player);
        if (damage_b)
            func_800A17A8(player, -damage_b);
        if (func_800A1718(player) == 0) {
            state = func_80099840(player, 1);
        } else
            state = _badrone_entrypoint_20(player, *(u8 **) ((s8 *) player + 192) + 8, 2);
        result = 2;
        goto block_180;
    case 111:
        state = _badrone_entrypoint_18(player, *(s32 *) (*(u8 **) ((s8 *) player + 192) + 20));
        result = 2;
        goto block_180;
    case 107:
        _bafpctrl_entrypoint_13(player, 0);
        if (func_800A3404(player))
            func_8009337C(player, 1);
        if (func_8008DAA8(player) && func_800A3274(player) != 17 && func_8008DD70(player) == 0 &&
            func_800A9420(*(s32 *) ((s8 *) player + 388)) == 0) {
            unk_0 = _plsu_entrypoint_1(17);
            if (unk_0 != -1)
                func_800F7B9C(unk_0, 148);
        }
        result = 2;
        goto block_180;
    case 108:
        _bafpctrl_entrypoint_13(player, 1);
        if (func_800A3404(player))
            func_8009337C(player, 0);
        if (func_8008E124(player) == 0 && func_8009E674(player, 16) == 0 &&
            func_8009E674(player, 8) == 0 && _bafpctrl_entrypoint_4(player) == 3)
            _bafpctrl_entrypoint_19(player);
        result = 2;
        goto block_180;
    case 93:
        if (*(s32 *) (*(u8 **) ((s8 *) player + 192) + 24)) {
            baflag_set(player, 57);
        } else
            baflag_clear(player, 57);
        result = 2;
        goto block_180;
    case 47:
        state = _badrone_entrypoint_20(player, *(u8 **) ((s8 *) player + 192) + 8, 1);
        result = 2;
        goto block_180;
    case 146:
        func_800A17A8(player, -1);
        state = _badrone_entrypoint_20(player, *(u8 **) ((s8 *) player + 192) + 8, 1);
        result = 2;
        goto block_180;
    case 36:
        if (func_8008DD90(player) == 0) {
            func_800995B8(player, 0);
            state = _badata_entrypoint_27(player);
            result = 2;
        }
        goto block_180;
    case 35:
        if (func_8008DD90(player) == 0) {
            func_800995B8(player, 1);
            state = _badata_entrypoint_27(player);
            result = 2;
        }
        goto block_180;
    case 45:
    case 152:
        func_800995B8(player, 3);
        if (player_inWater(player) && func_8009E71C(player, 11)) {
            state = 162;
        } else
            state = _badata_entrypoint_27(player);
        result = 2;
        goto block_180;
    case 137:
        _babounce_entrypoint_7(player, *(s32 *) (*(u8 **) ((s8 *) player + 192) + 20));
        result = 2;
        goto block_180;
    case 104:
        func_800995B8(player, 3);
        state = _badrone_entrypoint_22(player, *(u8 **) ((s8 *) player + 192) + 8);
        result = 2;
        goto block_180;
    case 69:
        if (func_800F64A4(*(s32 *) ((s8 *) player + 388), 513)) {
            state = 288;
        } else
            state = func_80099840(player, 1);
        result = 2;
        goto block_180;
    case 87:
        _bacough_entrypoint_4(player, 1);
        result = 2;
        goto block_180;
    case 86:
        _bacough_entrypoint_4(player, 2);
        result = 2;
        goto block_180;
    case 68:
        state = 287;
        result = 2;
        goto block_180;
    case 19:
        func_800A17A8(player, -0x3E7);
    case 11:
        func_800997BC(player);
        state = func_80099840(player, 0);
        result = 2;
        goto block_180;
    case 38:
        func_800A17A8(player, -0x3E7);
        _basudie_entrypoint_1(player);
        _basudie_entrypoint_0(player);
        result = 2;
        goto block_180;
    case 25:
        state = func_8009F354(player);
        result = 2;
        goto block_180;
    case 17:
        state = 84;
        result = 2;
        goto block_180;
    case 77:
        _bababykaz_entrypoint_14(player);
        result = 2;
        goto block_180;
    case 124:
        state = _badrone_entrypoint_19(player);
        result = 2;
        goto block_180;
    case 76:
        _baduo_entrypoint_15(player, *(u8 **) ((s8 *) player + 192) + 8);
        result = 2;
        goto block_180;
    case 62:
        _baduo_entrypoint_17(player, *(u8 **) ((s8 *) player + 192) + 8);
        result = 2;
        goto block_180;
    case 60:
        _baduo_entrypoint_18(player, *(u8 **) ((s8 *) player + 192) + 8);
        result = 2;
        goto block_180;
    case 63:
        payload_a = *(u8 **) ((s8 *) player + 192);
        _baduo_entrypoint_20(player, payload_a + 8, *(f32 *) payload_a);
        result = 2;
        goto block_180;
    case 95:
        func_80094430(player, *(f32 *) *(u8 **) ((s8 *) player + 192));
        result = 2;
        goto block_180;
    case 43:
        baflag_set(player, 56);
        _bashoes_entrypoint_12(player, *(f32 *) *(u8 **) ((s8 *) player + 192));
        if (func_8009CA70(player, cur_state, 64) == 0)
            state = func_8009F354(player);
        result = 2;
        goto block_180;
    case 41:
        baflag_set(player, 55);
        _bashoes_entrypoint_12(player, *(f32 *) *(u8 **) ((s8 *) player + 192));
        if (func_8009CA70(player, cur_state, 64) == 0)
            state = func_8009F354(player);
        result = 2;
        goto block_180;
    case 26:
        baflag_set(player, 16);
        _bashoes_entrypoint_12(player, *(f32 *) *(u8 **) ((s8 *) player + 192));
        if (func_8009CA70(player, cur_state, 64) == 0)
            state = func_8009F354(player);
        result = 2;
        goto block_180;
    case 27:
        baflag_set(player, 14);
        func_800A391C(player, *(f32 *) *(u8 **) ((s8 *) player + 192));
        state = func_8009F354(player);
        result = 2;
        goto block_180;
    case 71:
        marker = func_80099A4C(player);
        _suegg_entrypoint_6(marker, &unk_2, &unk_3);
        func_8009AD20(player, _gcegg_entrypoint_7(unk_3) + 2);
        if (func_8009BD44(player) != 3 && func_8008DD90(player) == 0) {
            func_800995B8(player, 0);
            if (func_8010114C(marker, 28, *(s32 *) ((s8 *) player + 388)) != 1)
                func_800A17A8(player, -1);
            state = func_80099840(player, 0);
            result = 2;
        }
        goto block_180;
    case 31:
        if (func_8009BD44(player) != 3 && func_8008DD90(player) == 0 && func_8008E974(player)) {
            case 49:
                func_800995B8(player, 2);
                func_800A17A8(player, -1);
                state = func_80099840(player, 0);
                result = 2;
        }
        goto block_180;
    case 33:
        if (func_8009BD44(player) != 3 && func_8008DD90(player) == 0) {
            case 51:
                func_800995B8(player, 0);
                if (func_8010114C(*(s32 *) (*(u8 **) ((s8 *) player + 192) + 20), 28,
                                  *(s32 *) ((s8 *) player + 388)) != 1)
                    func_800A17A8(player, -1);
                state = func_80099840(player, 0);
                result = 2;
        }
        goto block_180;
    case 78:
        if (func_8009BD44(player) != 3) {
            func_800995B8(player, 1);
            func_800A17A8(player, -func_80099A58(player));
            if (*(s32 *) ((s8 *) player + 344)) {
                if (func_800A1718(player) == 0)
                    func_80101180(708, 112,
                                  *(s32 *) ((s8 *) player + 388) * 16 | func_80099A70(player));
                if (func_800A3274(player) == 6) {
                    state = _badata_entrypoint_26(player);
                } else
                    state = func_80099840(player, 0);
            } else
                state = func_80099840(player, 0);
            result = 2;
        }
        goto block_180;
    case 32:
        if (func_8009BD44(player) != 3) {
            func_800995B8(player, 1);
            func_800A17A8(player, -1);
            state = func_80099840(player, 0);
            result = 2;
        }
        goto block_180;
    case 46:
        func_800995B8(player, 3);
        func_800A17A8(player, -1);
        state = func_80099840(player, 0);
        result = 2;
        goto block_180;
    case 145:
        state = _badrone_entrypoint_21(player);
        result = 2;
        goto block_180;
    case 64:
        _baduo_entrypoint_11(player, 1);
        result = 2;
        goto block_180;
    case 132:
        if (func_800A3970(player, *(s32 *) (*(u8 **) ((s8 *) player + 192) + 24)))
            result = 2;
        goto block_180;
    case 20:
        state = 5;
        result = 2;
        goto block_180;
    case 96:
        func_800F911C(1);
        _baduo_entrypoint_7(player, 1);
        func_800A0CF4(player, 1);
        func_800A3410(player, 1);
        func_800A3904(player, 1);
        goto block_180;
    case 53:
        baflag_set(player, 26);
        state = func_8009F354(player);
        result = 2;
        goto block_180;
    case 4:
    case 5:
        _baduo_entrypoint_10(player, 0);
        _baduo_entrypoint_11(player, 0);
        result = 2;
        goto block_180;
    case 58:
        if (func_8008E23C(player)) {
            _baduo_entrypoint_11(player, 1);
            result = 2;
        } else {
            _baduo_entrypoint_8(player, *(u8 **) ((s8 *) player + 192) + 8);
            _baduo_entrypoint_9(player, *(f32 *) *(u8 **) ((s8 *) player + 192) + 180.0f);
            _baduo_entrypoint_10(player, 1);
            result = 2;
        }
        goto block_180;
    case 59:
        if (func_8008E23C(player)) {
            _baduo_entrypoint_11(player, 1);
            _baduo_entrypoint_8(player, *(u8 **) ((s8 *) player + 192) + 8);
            result = 2;
        }
        goto block_180;
    case 65:
        _baduo_entrypoint_11(player, 0);
        result = 2;
        goto block_180;
    case 149:
        func_8009EC08(unk_4, unk_5);
        unk_4[1] = func_80099A58(player);
        unk_5[1] = func_80099A64(player);
        if (unk_4[0] != unk_4[1] || unk_5[0] != unk_5[1])
            func_8009EB24(unk_4[1], unk_5[1]);
        result = 2;
        goto block_180;
    case 150:
        func_8009EBD0();
        result = 2;
        goto block_180;
    case 151:
        func_800A05DC(player);
        result = 2;
        goto block_180;
    case 39:
        state = func_80099B54(player);
        result = 2;
        goto block_180;
    case 52:
        state = _badrone_entrypoint_26(player);
        result = 2;
        goto block_180;
    case 12:
        unk_1 = func_8008FD48();
        unk_6 = !(unk_1 == 1);
        if (unk_6)
            unk_6 = !(unk_1 == 10);
        if (func_8009CC68(player) == 0 && unk_6 == 0 && baflag_isTrue(player, 15) == 0 &&
            player_isStable(player) == 0) {
            state = 79;
            result = 2;
        }
        goto block_180;
    case 61:
        _baduo_entrypoint_19(player);
        result = 2;
        goto block_180;
    case 30:
        if (func_8008D630(player)) {
            result = 2;
            state = _badata_entrypoint_29(player);
        }
        goto block_180;
    case 29:
        if (func_8008D630(player)) {
            result = 2;
            state = _badata_entrypoint_31(player);
        }
        goto block_180;
    case 28:
        if (func_8008D630(player)) {
            result = 2;
            state = _badata_entrypoint_32(player);
        }
        goto block_180;
    case 21:
        result = 2;
        if (func_8009CBDC(player, cur_state) == 9)
            state = 36;
        else
            switch (func_800F40EC(player)) {
                case 1:
                    state = 45;
                    break;
                case 2:
                    state = 43;
                    break;
                case 0:
                    if (player_isStable(player))
                        state_tmp = _badata_entrypoint_34(player);
                    else
                        state_tmp = _badata_entrypoint_24(player);
                    state = state_tmp;
            }
        baphysics_set_target_horizontal_velocity(player, 0);
        func_8009BA9C(player, 0);
        goto block_180;
    case 37:
        result = 2;
        state = _badata_entrypoint_32(player);
        goto block_180;
    case 147:
        _bafpctrl_entrypoint_19(player);
        result = 2;
        goto block_180;
    case 138:
        func_80094574(player, *(s32 *) (*(u8 **) ((s8 *) player + 192) + 24));
        result = 2;
        goto block_180;
    case 56:
        result = 2;
        state = 181;
        goto block_180;
    case 89:
        _basquash_entrypoint_3(player, 1);
        state = func_80099730(player, 0);
        goto block_180;
    case 90:
        _basquash_entrypoint_3(player, 1);
        state = func_80099730(player, 1);
        goto block_180;
    case 154:
        _basquash_entrypoint_3(player, 1);
        goto block_180;
    case 91:
        _basquash_entrypoint_3(player, 2);
        state = func_80099730(player, 0);
        goto block_180;
    case 92:
        _basquash_entrypoint_3(player, 2);
        state = func_80099730(player, 1);
        goto block_180;
    case 15:
        baflag_set(player, 6);
        state = func_8009F354(player);
        result = 2;
        goto block_180;
    case 48:
        func_800A17A8(player, -0x3E7);
        baflag_set(player, 6);
        state = func_8009F354(player);
        result = 2;
        goto block_180;
    case 55:
        state = _badrone_entrypoint_27(player);
        result = 2;
        goto block_180;
    case 42:
        result = 2;
        state = func_8009F354(player);
        baflag_set(player, 20);
        goto block_180;
    case 73:
        baflag_set(player, 2);
        result = 2;
        goto block_180;
    case 74:
        baflag_set(player, 1);
        result = 2;
        goto block_180;
    case 97:
        _bsfirstp_entrypoint_26(player);
        return;
    case 139:
        state = 66;
        result = 2;
        goto block_180;
    case 98:
        func_800A3544(player, 1);
        func_8009337C(player, 0);
        result = 2;
        goto block_180;
    case 99:
        func_800A3544(player, 0);
        func_8009337C(player, 1);
        result = 2;
        goto block_180;
    case 102:
        payload_b = *(u8 **) ((s8 *) player + 192);
        func_8008ED88(player, payload_b + 8, *(s32 *) (payload_b + 20));
        result = 2;
        goto block_180;
    case 103:
        _bainvisible_entrypoint_5(player, *(f32 *) *(u8 **) ((s8 *) player + 192));
        result = 2;
        goto block_180;
    case 125:
        if (*(s32 *) ((s8 *) player + 344)) {
            _badeathmatch_entrypoint_5(
                player,
                _badeathmatch_entrypoint_4(*(s32 *) (*(u8 **) ((s8 *) player + 192) + 24)),
                *(s32 *) (*(u8 **) ((s8 *) player + 192) + 28));
            result = 2;
        } else {
            payload_c = *(u8 **) ((s8 *) player + 192);
            func_800D175C(*(s32 *) (payload_c + 24), *(s32 *) (payload_c + 28));
            result = 2;
        }
        goto block_180;
    case 140:
        func_800956B8(player);
}

block_180 : func_8009E830(player, result);
bs_setState(player, state);
}

void func_8009AB78(PlayerState *player)
{
    s32 cur_state;
    s32 result;
    s32 next_state;
    s32 code;

    cur_state = func_800A3274();
    result = 1;
    next_state = 0;
    code = func_8009E6EC((s32) player);

if (code != 8) {
    if (code == 0x12) {
        if ((baflag_isFalse(player, 0xF) != 0) && (bastatetimer_isDone(player, 0) != 0) &&
            ((cur_state == 1) || (cur_state == 0xA))) {
            result = 2;
            func_8008F6B8(player, func_8008E9AC(player));
        }
        goto block_9;
    }
    goto bahold;
}

next_state = 0x3C;
result = 2;
goto block_9;
bahold : _bahold_entrypoint_4(player);
func_80099B94(player);
return;
block_9 : bs_setState(player, next_state);
func_8009E830(player, result);
}

void func_8009AC6C(Akteur *player)
{
    int i;
    player->payload->unk_18 = 0;
    player->payload->marker = 0;
    func_800EFD24(player->payload->pos);

for (i = 0; i < 5; i++) {
    player->payload->queue[i].code = 0;
}

}

// Interrupt payload setters.
void func_8009ACF4(s32 player, f32 value)
{
    *((f32 *) ((s32 *) (player))[0x30]) = value;
}

func_8009AD04(s32 player, f32 value)
{
    *(f32 *) (*(s32 *) (player + 0xC0) + 4) = value;
}

void func_8009AD14(player, value) u8 *player;
s32 value;
{
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xC0)))) + (0x14))) = value;
}

func_8009AD20(player, value) s32 player;
s32 value;
{
    *(s32 *) (*(s32 *) (player + 0xC0) + 0x18) = value;
}

int func_8009AD2C(void *player, s32 value)
{
    (*((void ***) (((u8 *) player) + 0xC0)))[7] = value;
}

func_8009AD38(s32 player, s32 value)
{
    *(s32 *) (*(s32 *) (player + 0xC0) + 0x20) = value;
}

void func_8009AD44(player) Actor *player;
{
    func_800EE7F8(*(s32 *) ((char *) player + 0xc0) + 8);
}
