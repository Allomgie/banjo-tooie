#include "common.h"

extern void *D_808003A0_chtemplelobbydoor;
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern s32 func_800C6E38(s32);
extern void _subaddiedialog_entrypoint_7(s32, s32, void *);
extern void func_800F7B9C(s32, u32);
extern void _bsfirstp_entrypoint_18();
extern void func_800C9CD0(f32, Unk80132ED0 *, s32, s32, s32, s32);

int chtemplelobbydoor_entrypoint_0()
{
    return &D_808003A0_chtemplelobbydoor;
}

// Stays shut until 20 jade statues are broken and only opens for Banjo-Kazooie.
void func_8080000C_chtemplelobbydoor(Actor *actor)
{
    s32 too_few_statues;
    s32 not_banjo_kazooie;
    if (func_800EA090() == 1) {
        too_few_statues = func_800D035C(5) < 20;
        not_banjo_kazooie = func_800F5410(0) != 1;
        if (too_few_statues || not_banjo_kazooie)
            func_80101FDC(actor, 1);
    }
    if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, 180.0f, 8, -1)) {
        _chdoormake_entrypoint_5(actor, 1.5f);
        _chdoormake_entrypoint_8(actor, 5);
    }
}

void func_808000B4_chtemplelobbydoor(s32 arg0)
{
}

void func_808000BC_chtemplelobbydoor();
extern int func_80105834();
extern int func_80101870();
extern int func_80107C2C();
// TU-NOTE: the overlay .data is defined here in C; the table precedes func_808000E4_chtemplelobbydoor,
// whose static fills the rest of the .data (source order).
s32 func_80800248_chtemplelobbydoor();
void *D_808003A0_chtemplelobbydoor = (void *) 0x00AC02B5;
static u32 D_808003A0_chtemplelobbydoor_rest[17] = {0x8490004,
                                                    0x0,
                                                    (u32) func_808000BC_chtemplelobbydoor,
                                                    (u32) func_80105834,
                                                    (u32) func_80101870,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    0x20800,
                                                    (u32) func_808000B4_chtemplelobbydoor,
                                                    0x0,
                                                    0x0,
                                                    (u32) func_8080000C_chtemplelobbydoor,
                                                    (u32) func_80107C2C,
                                                    0x80002402,
                                                    (u32) func_80800248_chtemplelobbydoor,
                                                    0x0};

void func_808000E4_chtemplelobbydoor();

void func_808000BC_chtemplelobbydoor(s32 arg0)
{
    func_808000E4_chtemplelobbydoor();
    _chdoor_entrypoint_0(arg0);
}

void func_808000E4_chtemplelobbydoor(s32 actor)
{
    static struct {
        s32 w;
        s16 a;
        u16 b;
        s16 rest[16];
    } D_808003E8_chtemplelobbydoor = {0x190, 0xF37, 0xF38, 0,   0x101, 0x120A,
                                      0,     0xB2,  0,     0xA, 0x4000};

    if (func_800C6E38(0x15)) {
        D_808003E8_chtemplelobbydoor.a = 0xF39;
        D_808003E8_chtemplelobbydoor.b = 0xF39;
    }
    _subaddiedialog_entrypoint_7(actor, actor + 4, &D_808003E8_chtemplelobbydoor);
}

void func_80800134_chtemplelobbydoor(actor, msg_data) Actor *actor;
s32 msg_data;
{
    u8 *state;
    state = (u8 *) func_80100094(actor, 0);
    *state = 0;
    switch (func_800EA090()) {
        case 1:
            if (func_800C6E38(0x15) && func_8009E958() == 1 && !func_800DA9E4(0x6B8, 1)) {
                *state = 1;
                _capod_entrypoint_13(actor->unk0, 0, 3, 0x2020);
                func_800F49D4(func_800F54E4(), _bsfirstp_entrypoint_18, 0);
            }
            break;
        case 2:
            if (!func_800DA298(0x36F)) {
                func_800C9CD0(0.8f, actor->unk0, 0xF50, 2, 0, 0xB2);
                _capod_entrypoint_13(actor->unk0, 0, 1, 0x2020);
            }
    }
}

// Message 0x49: setup; 0x2E: dialog finished; 0x77: first-person view ended.
s32 func_80800248_chtemplelobbydoor(Actor *actor, s32 msg, s32 msg_data)
{
    u8 *state;
    s32 player;

    state = func_80100094(actor, 0);
    switch (msg) {
        case 0x49:
            func_80800134_chtemplelobbydoor(actor, msg_data);
            return 1;
        case 0x2E:
            switch (*(s16 *) &msg_data) {
                case 0xF39:
                    func_8010108C(actor, 7, 0);
                    return 1;
                case 0xF50:
                    func_800F7B9C(func_800F54E4(), 0x73);
                    func_800F7F98(func_800F54E4(), 0);
                    _capod_entrypoint_14();
                    func_800F7B9C(func_800F54E4(), 0x99);
                    return 1;
            }
        case 0x77:
            if (state[0] == 1) {
                player = msg_data;
                state[0] = 0;
                func_800F7B9C(player, 0x73);
                _capod_entrypoint_14();
                func_800F7B9C(func_800F54E4(), 0x99);
                return 1;
            }
    }
    return _chdoor_entrypoint_1(actor, msg, msg_data);
}
