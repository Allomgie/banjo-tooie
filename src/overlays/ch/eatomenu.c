#include "common.h"

extern void *D_8080089C_chcheatomenu;
typedef struct {
    s16 a;
    s16 b;
    s16 c;
} Opt6;
extern Opt6 D_808008E4_chcheatomenu;
extern Opt6 D_808008EC_chcheatomenu;
extern Opt6 D_808008F4_chcheatomenu;
extern u8 _gcnewoption_entrypoint_35[];
extern u8 _gcnewoption_entrypoint_15[];
extern u8 D_80800880_chcheatomenu[];
extern u8 D_80800890_chcheatomenu[];
extern void _capod_entrypoint_3(int, void *);
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern void _gcnewoption_entrypoint_40(void *, s32, s32, s32, f32, f32);
// TU-NOTE: the data tables at the end are defined in this file because they point to functions here;
// IDO schedules some of these functions differently otherwise. Values come from the ROM.
int func_8080052C_chcheatomenu();
void func_8080058C_chcheatomenu();
int func_80800668_chcheatomenu();
void func_80800720_chcheatomenu();
void func_808007B8_chcheatomenu();
s32 func_80800800_chcheatomenu();

int chcheatomenu_entrypoint_0()
{
    return &D_8080089C_chcheatomenu;
}

void func_8080000C_chcheatomenu(s32 arg0)
{
}

void func_80800014_chcheatomenu(void *actor)
{
    s32 state;

    state = (u32) *(u16 *) ((char *) actor + 0x72) >> 10;
    switch (state) {
        case 1:
            func_8080058C_chcheatomenu(actor);
            return;

        case 3:
            func_80800668_chcheatomenu(actor);
            func_80800720_chcheatomenu(actor);
            return;

        case 4:
            _gcnewoption_entrypoint_0(func_80100094(actor, 0));
            return;

        case 5:
            _gcnewoption_entrypoint_6(actor, 0);
            func_808007B8_chcheatomenu(actor);
            func_80090708(0);
            func_80101FDC(actor, 1);
    }
}

s32 func_808000D4_chcheatomenu(Actor *actor, s32 msg, s32 msg_data)
{
    switch (msg) {
        case 0x2E:
            func_80101FDC(actor, 1);
            func_808007B8_chcheatomenu(actor);
            break;
        case 0x20:
            func_8080052C_chcheatomenu(actor, func_80101080(), ((s16 *) &msg_data)[0],
                                       ((s16 *) &msg_data)[1]);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_80800150_chcheatomenu(s32 param_0, s32 param_1)
{
    if ((u32) ((u16 *) param_0)[0x39] >> 0xA == 4) {
        _gcnewoption_entrypoint_1(func_80100094(param_0, 0), param_1);
    }
}

// Toggles the cheat on the given row and updates the row look.
void func_80800194_chcheatomenu(s32 actor, s32 menu, s32 row, s32 apply_capacities)
{
    s32 i;
    s32 count;
    s32 pad;
    Opt6 on_color;
    Opt6 off_color;
    Opt6 other_color;

    count = 0;
    i = 1;
    do {
        if (func_800D3E14(i) || func_800D3DD0(i)) {
            if (count == row)
                break;
            count++;
        }
        i++;
    } while (i != 13);
    if (_gcnewoption_entrypoint_17(*(s32 *) &menu, row)) {
        on_color = D_808008E4_chcheatomenu;
        count = i - 1;
        _gcnewoption_entrypoint_13(menu, row, &on_color);
        _gcnewoption_entrypoint_12(menu, row, (s16) (count * 3 + 4));
        func_800D3F58(count + 1, 1);
    } else if (_gcnewoption_entrypoint_18(menu, row)) {
        off_color = D_808008EC_chcheatomenu;
        count = i - 1;
        _gcnewoption_entrypoint_13(menu, row, &off_color);
        _gcnewoption_entrypoint_12(menu, row, (s16) (count * 3 + 5));
        func_800D3F58(count + 1, 0);
    } else if (_gcnewoption_entrypoint_19(menu, row)) {
        other_color = D_808008F4_chcheatomenu;
        _gcnewoption_entrypoint_13(menu, row, &other_color);
        _gcnewoption_entrypoint_12(menu, row, (s16) (i * 3 + 3));
    }
    if (apply_capacities) {
        func_800D3FD4(1);
    }
}

void func_80800364_chcheatomenu(actor, menu) Actor *actor;
void *menu;
{
    s32 visible_rows;
    s32 i;

    visible_rows = func_800F1418(5, func_80800800_chcheatomenu());
    _gcnewoption_entrypoint_14(menu, 0, 1, 3, 4.0f);
    _gcnewoption_entrypoint_40(menu, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(menu, 0x37);
    for (i = 0; i < visible_rows; i++)
        _gcnewoption_entrypoint_31(menu, i, 0x37);
}

void func_80800428_chcheatomenu(actor, menu) s32 actor;
s32 menu;
{
    s32 row;
    s32 cheat_id;
    s32 text_id;

    row = 0;
    cheat_id = 1;
    do {
        text_id = func_800D3FC0(cheat_id);
        text_id = (text_id << 16) >> 16;
        _gcnewoption_entrypoint_31(menu, row, text_id);
        if (func_800D3E14(cheat_id) != 0) {
            if (func_800D3E40(cheat_id) != 0) {
                _gcnewoption_entrypoint_21(menu, row);
            } else {
                _gcnewoption_entrypoint_22(menu, row);
            }
            func_80800194_chcheatomenu(actor, menu, row, 0);
            goto block_8;
        }
        if (func_800D3DD0(cheat_id) != 0) {
            _gcnewoption_entrypoint_23(menu, row);
            func_80800194_chcheatomenu(actor, menu, row, 0);
        block_8:
            row += 1;
        }
        cheat_id += 1;
    } while (cheat_id != 0xD);
}

// Handles menu events: toggle, rebuild, close.
int func_8080052C_chcheatomenu(actor, menu, row, event)
s32 actor;
s32 menu;
s32 row;
s32 event;
{
    s32 actor_copy;
    actor_copy = actor;

switch (event) {
    case 1:
        func_80800194_chcheatomenu(actor_copy, menu, row, 1);
        break;

    case 0:
        func_80800428_chcheatomenu();
        break;

    case 2:
        func_80101FDC(actor_copy, 5);
}

}

void func_8080058C_chcheatomenu(actor) s32 *actor;
{
    s32 dialog_done;

if (func_80090178(0xFFFEFFFF) != 0) {
    if (func_800DA298(0xD3) == 0) {
        dialog_done = _subaddiedialog_entrypoint_2(actor + 1, 0xC8, 0x32, 0);
    } else {
        dialog_done = _subaddiedialog_entrypoint_5(actor + 1, 0xC8, 0x32, 0);
    }
    if (dialog_done != 0) {
        func_800DA544(0xD3);
        if (func_80800800_chcheatomenu() == 0) {
            _subaddiedialog_entrypoint_11(*actor, 0x1149, 0xF, actor + 1, 0x37);
            func_80101FDC(actor, 2);
            func_80800720_chcheatomenu(actor);
            return;
        }
        func_80101FDC(actor, 3);
    }
}

}

// Opens the cheat toggle list.
int func_80800668_chcheatomenu(actor)
s32 actor;
{
    f32 unused[2];
    s32 cheat_count;
    s32 menu;
    cheat_count = func_80800800_chcheatomenu();
    _gcnewoption_entrypoint_4(actor, 0, &_gcnewoption_entrypoint_15, &_gcnewoption_entrypoint_35,
                              0x1848);
    menu = func_80100094(actor, 0);
    _gcnewoption_entrypoint_8(menu, func_800F1418(5, cheat_count));
    _gcnewoption_entrypoint_9(menu, cheat_count);
    _gcnewoption_entrypoint_10(menu, 1);
    func_80800364_chcheatomenu(actor, menu);
    _gcnewoption_entrypoint_11(menu);
    func_80101FDC(actor, 4);
    func_80090708(2);

}

void func_80800720_chcheatomenu(actor) Actor *actor;
{
    if (!actor->unk6C_0) {
        _capod_entrypoint_2(actor->unk0, 0x19, 0);
        _capod_entrypoint_8(1);
        _capod_entrypoint_9(0, D_80800880_chcheatomenu);
        _capod_entrypoint_10(0, D_80800890_chcheatomenu);
        _capod_entrypoint_11(0, actor->rotation);
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_7(3, 0);
        actor->unk6C_0 = 1;
    }

}

void func_808007B8_chcheatomenu(actor) void *actor;
{
    if ((s32) ((s32 *) ((char *) actor + 0x6C))[0] & 0x1FF) {
        _capod_entrypoint_3(0, actor);
        *(u16 *) ((char *) actor + 0x6E) &= ~0x1FF;
    }

}

// Counts known cheats (unlocked or entered).
s32 func_80800800_chcheatomenu(void)
{
    s32 i;
    s32 count = 0;

    for (i = 1; i < 13; i++) {

if (func_800D3DD0(i) || func_800D3E14(i)) {
    count++;
}

}
return count;
}

extern void func_80105834();
extern void func_80107C2C();
u8 D_80800880_chcheatomenu[16] = {0x43, 0x7A, 0x0, 0x0, 0x43, 0x20, 0x0, 0x0,
                                  0x42, 0x70, 0x0, 0x0, 0x42, 0x70, 0x0, 0x0};
u8 D_80800890_chcheatomenu[12] = {0x44, 0xCE, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
void *D_8080089C_chcheatomenu = (void *) 0x0221018A;
static u32 D_8080089C_chcheatomenu_rest[17] = {0xFFFF0001,
                                               0x0,
                                               (u32) func_80800014_chcheatomenu,
                                               (u32) func_80105834,
                                               (u32) func_80800150_chcheatomenu,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x400000,
                                               0x0,
                                               0x0,
                                               0x0,
                                               (u32) func_8080000C_chcheatomenu,
                                               (u32) func_80107C2C,
                                               0x80000402,
                                               (u32) func_808000D4_chcheatomenu,
                                               0x0};
Opt6 D_808008E4_chcheatomenu = {0x0, 0xFF, 0x0};
Opt6 D_808008EC_chcheatomenu = {0xFF, 0x0, 0x0};
Opt6 D_808008F4_chcheatomenu = {0xFF, 0xFF, 0xFF};
