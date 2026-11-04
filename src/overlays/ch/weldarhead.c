// Most likely Weldar's head after the fight: it talks to the player, runs the reward flow and
// spawns a shock-jump pad.
#include "common.h"

extern void *D_808004F0_chweldarhead;
extern void *func_80100094(Actor *, s32);
extern u8 D_808004E0_chweldarhead[];
extern void func_8010D5DC(void);
extern void func_800F4A58(s32, f32 *, f32);
typedef struct {
    f32 pos[3];
    s32 unk_C;
    f32 unk_10;
    f32 unk_14;
} WeldarMarker37;
extern s16 D_8080053E_chweldarhead;
extern s32 D_80800538_chweldarhead[];
typedef struct {
    f32 pos[3];
    s32 unkC;
    f32 unk10;
    f32 unk14;
    u8 unk18[1];
} WeldarHeadLocal;
typedef union {
    u32 w;
    s32 s;
    struct {
        s16 a;
        s16 b;
    } h;
} WeldarHeadArg;
extern s32 _susubgame_entrypoint_3(Actor *, void *, s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);

void *chweldarhead_entrypoint_0()
{
    return &D_808004F0_chweldarhead;
}

void func_8080000C_chweldarhead(Actor *head)
{
    u8 *data = func_80100094(head, 0);
    WeldarMarker37 player_marker;
    WeldarMarker37 look_marker;
    s32 player;

    _susubgame_entrypoint_0(head, data + 0x18, 0);
    _susubgame_entrypoint_12(data + 0x18, D_808004E0_chweldarhead);
    if (!func_800DA298(0x18C)) {
        func_800FFAB0(head);
        return;
    }
    _subaddiemarker_entrypoint_1(head, 0x320, 0x32, data, 1);
    if (func_800DA9E4(0x9C9, 0)) {
        player = func_800F54E4();
        _subaddiemarker_entrypoint_1(head, 0x320, 0x33, &player_marker, 1);
        _subaddiemarker_entrypoint_1(head, 0x320, 0x34, &look_marker, 1);
        func_800F8294(player, player_marker.pos);
        func_800F497C(player);
        func_800F49D4(player, func_8010D5DC, head->unk0);
        func_800F4A58(player, look_marker.pos, 250.0f);
        _susubgame_entrypoint_6(head, data + 0x18, 0x44, 0x2030, 0);
        func_80102424(head, 2);
    } else {
        head->unk64_20 = 0;
        func_80108B04(head, 0);
    }
}

void func_80800170_chweldarhead(Actor *head)
{
    extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);

    if (head->unk70_10 == 1) {
        D_8080053E_chweldarhead = func_800DC128(0, 4) + 0x1361;
        _subaddiedialog_entrypoint_7(head, head->position, &D_80800538_chweldarhead);
    }
    _sudeflect_entrypoint_0(head->position, 20.0f, 120.0f, 10);
}

void func_8080038C_chweldarhead();

s32 func_808001E4_chweldarhead(Actor *this, s32 msg, WeldarHeadArg arg)
{
    WeldarHeadLocal *data;
    Actor *pad;

    data = func_80100094(this, 0);
    switch (msg) {
        case 0x2E:
            func_8080038C_chweldarhead(this, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(this, data->unk18, arg.s & 0xFFFF,
                                           (arg.w & 0xFFFF0000) >> 16);
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808004E0_chweldarhead, this->scale);
            break;
        case 0x32:
            _subaddiedialog_entrypoint_11(this->unk0, 0x1360, 0xE, this->position, 0xB5);
            break;
        case 0xB:
            if (arg.w == 0x48) {
                _subaddiedialog_entrypoint_11(this->unk0, 0x1384, 0xE, this->position, 0xB5);
                return 4;
            }
            return 3;
        case 0x3D:
            pad = func_80108528(0x210, data->pos, data->unk10, &this);
            func_80102FDC(pad, data->unk14);
            if (this->unk64_20) {
                _chappearfx_entrypoint_1(pad, 0x22, 1, 1.0f);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080038C_chweldarhead(Actor *head, s32 dialog_id, s32 arg)
{
    u8 *data;
    data = func_80100094(head, 0);
    switch (dialog_id) {
        case 0x1360:
            _susubgame_entrypoint_6(head, data + 0x18, 0x48, 0x30, 0);
            func_80108B04(head, 0);
            head->unk64_20 = 1;
            break;
        case 0x1384:
            _susubgame_entrypoint_4(head, data + 0x18);
        default:
            func_80102424(head, 1);
    }
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file and the
// assembler schedules them differently otherwise. Values are taken from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u8 D_808004E0_chweldarhead[16] = {0x43, 0x12, 0x0, 0x0, 0x43, 0x12, 0x0, 0x0,
                                  0x43, 0x12, 0x0, 0x0, 0x42, 0x92, 0x0, 0x0};
void *D_808004F0_chweldarhead = (void *) 0x01580146;
static u32 D_808004F0_chweldarhead_rest[17] = {0x8700001,
                                               0x0,
                                               (u32) func_80800170_chweldarhead,
                                               (u32) func_80105834,
                                               (u32) func_80101870,
                                               0x3E80000,
                                               0x4019999A,
                                               0x0,
                                               0x500,
                                               0x0,
                                               0x0,
                                               0x300000,
                                               (u32) func_8080000C_chweldarhead,
                                               (u32) func_80107C2C,
                                               0x80000402,
                                               (u32) func_808001E4_chweldarhead,
                                               0x0};
s32 D_80800538_chweldarhead[10] = {0x190,   0x0,       0x201, 0x120F0000, 0xB50000,
                                   0xC0000, 0x2000000, 0x0,   0x0,        0x0};
