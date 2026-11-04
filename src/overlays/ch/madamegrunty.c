#include "common.h"

extern int D_80800B50_chmadamegrunty[];
extern int D_80800B98_chmadamegrunty[];
typedef union {
    s32 word;
    s16 halves[2];
} MadameMessage1417;
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800F4AC0(s32, f32 *, f32);
extern s32 func_800DC298(f32);
extern void func_8010D5DC();
extern void _capod_entrypoint_14(void);
extern void func_800F7C0C(s32, s32, f32);
typedef struct {
    s16 reward;
    s16 flag;
    s16 count;
    s16 pad_0;
    f32 weight;
} MadameReward;
extern MadameReward D_80800AF0_chmadamegrunty[8];
extern f32 func_800DC178(f32, f32);
extern s32 func_800C6E38(s32);
typedef struct {
    s32 sound_id;
    f32 time;
    f32 pitch;
} MadameEntry;
extern MadameEntry D_80800BE0_chmadamegrunty[9];
extern s32 func_800D9078();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_7(Actor *, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_80800C4C_chmadamegrunty[];
extern void func_800C31DC(u8, f32);
extern void func_800C301C(u8, s32);
extern void func_800C3BDC();
void func_80800460_chmadamegrunty();
void func_80800784_chmadamegrunty();
void func_8080082C_chmadamegrunty();
void func_808009AC_chmadamegrunty(Actor *actor, s32 pitch_id, f32 pitch);

int chmadamegrunty_entrypoint_0()
{
    return (int) &D_80800B50_chmadamegrunty;
}

int chmadamegrunty_entrypoint_1()
{
    return (int) &D_80800B98_chmadamegrunty;
}

int func_80800018_chmadamegrunty(Actor *actor)
{
    if (func_800DA298(0xA02)) {
        func_80101FDC(actor, 7);
        actor->unk58 = 20.0f;
    }
}

s32 func_808008D4_chmadamegrunty();

void func_808003B0_chmadamegrunty();

void func_80800200_chmadamegrunty();

void func_8080005C_chmadamegrunty(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            func_80800200_chmadamegrunty(actor);
        case 4:
            break;
        case 5:
            if (!func_808008D4_chmadamegrunty(actor)) {
                func_800F4924(func_800F54E4(), -1);
                func_808003B0_chmadamegrunty(actor);
            }
            break;
        case 6:
            if (func_800D9078(&actor->unk58)) {
                func_8080082C_chmadamegrunty(actor, actor->unk64_20 ? 7 : 1);
                actor->unk64_20 = 0;
            }
            break;
        case 7:
            if (func_800D90A4(&actor->unk58) && _subaddiedialog_entrypoint_16() &&
                _subaddiedialog_entrypoint_11(actor->unk0, 0x10CB, 0, 0, 0x43)) {
                func_8080082C_chmadamegrunty(actor, 1);
                func_80101180(0x3D4, 7, 0);
                _subaddieDll_entrypoint_4(actor, 0);
            }
    }
}

int func_80800198_chmadamegrunty(Actor *actor, s32 msg, MadameMessage1417 arg)
{
    switch (msg) {
        case 0x2E:
            func_80800784_chmadamegrunty(actor, arg.halves[0], arg.halves[1]);
            break;
        case 0x32:
            func_80800460_chmadamegrunty(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800200_chmadamegrunty(s32 *actor)
{
    s32 player;

    player = func_800F54E4();
    if ((func_800F6438(player) != 0) && (func_800F6478(player) != 0) &&
        (func_8010C500(actor) != 0) && (func_800F64A4(player, 0x10000) == 0)) {
        func_800F497C(player);
        func_800F49D4(player, &func_8010D5DC, *actor);
        func_800F4AC0(player, actor + 1, 1.7e+02f);
        func_8080082C_chmadamegrunty(actor, 2);
        _capod_entrypoint_13(*actor, 0, 0xAE, 0x20);
    }
}

void func_808002BC_chmadamegrunty(actor) Actor *actor;
{
    f32 offset[3];

    func_800EEB9C(offset, actor->rotation[1], 400.0f);
    func_800EF04C(offset, actor->position);
    func_800F82D4(func_800F54E4(), 0);
    func_800F497C(func_800F54E4());
    func_800F49D4(func_800F54E4(), func_8010D5DC, actor->unk0);
    func_800F4AC0(func_800F54E4(), offset, 170.0f);
    func_8080082C_chmadamegrunty(actor, 4);
    actor->unk64_20 = func_800DC298(0.25f);
    if (actor->unk64_20) {
        func_80101180(0x3D4, 8, 0);
    }
    _capod_entrypoint_14();
}

void func_808003B0_chmadamegrunty(Actor *actor)
{
    func_800F82D4(func_800F54E4(), 0);
    func_800F7C0C(func_800F54E4(), 0x44, actor->rotation[1]);
    func_8080082C_chmadamegrunty(actor, 6);
    actor->unk58 = 1.5f;
    actor->unk64_20 = func_800DC298(0.25f);
    if (actor->unk64_20)
        func_80101180(0x3D4, 8, 0);
    _capod_entrypoint_14();
}

void func_80800460_chmadamegrunty(actor) Actor *actor;
{
    switch (actor->unk70_10) {
        case 2:
            if (!func_800F64A4(func_800F54E4(), 0x201)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x10A0, 15, 0, 0x43);
                func_8080082C_chmadamegrunty(actor, 3);
            } else {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x109F, 15, 0, 0x43);
                func_8080082C_chmadamegrunty(actor, 3);
            }
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 4:
            func_8080082C_chmadamegrunty(actor, actor->unk64_20 ? 7 : 1);
            actor->unk64_20 = 0;
    }
}

s32 func_80800564_chmadamegrunty(actor)
Actor *actor;
{
    f32 roll;
    f32 sum;
    s32 i;

    roll = 0.0f;
    sum = 0.0f;
    for (i = 0; i < 8; i++) {
        if (D_80800AF0_chmadamegrunty[i].flag == -1 ||
            func_800C6E38(D_80800AF0_chmadamegrunty[i].flag)) {
            roll += D_80800AF0_chmadamegrunty[i].weight;
        }
    }
    roll = func_800DC178(0.0f, roll);
    for (i = 0; i < 8; i++) {
        if (D_80800AF0_chmadamegrunty[i].flag == -1 ||
            func_800C6E38(D_80800AF0_chmadamegrunty[i].flag)) {
            sum += D_80800AF0_chmadamegrunty[i].weight;
            if (roll <= sum) {
                *(s32 *) &actor->unk50 = i;
                return i + 0x10A1;
            }
        }
    }
    return 0;
}

void func_80800670_chmadamegrunty(actor) Actor *actor;
{
    f32 pos[3];
    s32 reward_idx;
    reward_idx = *(s32 *) &actor->unk50;
    func_800EE7F8(pos, actor->position);
    func_800EF1B8(pos, actor->rotation[1], 400.0f);
    switch (reward_idx) {
        case 0:
            func_800D3EF4(6);
            func_800FC660(0xE);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x10A9, 0xE, 0, 0x43);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            func_800D175C((MadameReward *) D_80800AF0_chmadamegrunty[reward_idx].reward,
                          (MadameReward *) D_80800AF0_chmadamegrunty[reward_idx].count);
            func_808002BC_chmadamegrunty(actor);
            break;
        case 6:
            func_800F4924(func_800F54E4(), 1);
            func_808002BC_chmadamegrunty(actor);
            break;
        case 7:
            func_80101FDC(actor, 5);
            actor->unk58 = 4.0f;
    }
}

void func_80800784_chmadamegrunty(actor_ref, dialog_id, unused) s32 *actor_ref;
s32 dialog_id;
s32 unused;
{
    switch (dialog_id) {
        case 0x109F:
            _subaddiedialog_entrypoint_11(*actor_ref, func_80800564_chmadamegrunty(), 0xE, 0, 0x43);
            return;

        case 0x10A9:
            func_808002BC_chmadamegrunty();
            return;

        case 0x10A0:
            func_808002BC_chmadamegrunty();
            return;

        default:
            if (!actor_ref && !actor_ref) {
            }
            func_80800670_chmadamegrunty();

        case 0x10CA:

        case 0x10CB:
            return;
    }
}

void func_8080082C_chmadamegrunty(actor, state) u8 *actor;
s32 state;
{
    func_80101FDC();

if (state == 7) {
    _subaddieDll_entrypoint_4(actor, 1);
    *(f32 *) ((s8 *) actor + 0x58) = 60.0f;
    _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) actor + 0), 0x10CA, 4, 0, 0x43);
}

}

int func_80800898_chmadamegrunty(f32 low, f32 high, f32 value)
{
    s32 result;
    result = 0;

if (low <= value && value < high) {
    return 1;
}

return result;
}

s32 func_808008D4_chmadamegrunty(Actor *actor)
{
    f32 prev_timer;
    s32 running;
    s32 i;

    prev_timer = *(f32 *) ((u8 *) actor + 0x58);
    running = func_800D9078((f32 *) ((u8 *) actor + 0x58));
    for (i = 0; i < 9; i++) {

if (func_80800898_chmadamegrunty(
        *(f32 *) ((u8 *) actor + 0x58), prev_timer,
        func_800F10B4(D_80800BE0_chmadamegrunty[i].time, 0.0f, 1.0f, 4.0f, 0.0f))) {
    func_808009AC_chmadamegrunty(actor, D_80800BE0_chmadamegrunty[i].sound_id,
                                 D_80800BE0_chmadamegrunty[i].pitch);
}

}
return running == 0;
}

void func_808009AC_chmadamegrunty(Actor *actor, s32 pitch_id, f32 pitch)
{
    u8 sfx;

    sfx = _subaddieaudioquick_entrypoint_1(actor, actor->position);
    func_800C4350(sfx, actor->position, D_80800C4C_chmadamegrunty);
    func_800C301C(sfx, pitch_id);
    func_800C31DC(sfx, func_800DC178(-0.05f, 0.05f) + pitch);
    func_800C3BDC(sfx);
}

void func_80800A30_chmadamegrunty(Actor *actor)
{
    if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, 200.0f * actor->scale, 0x2812, 0xA02)) {
        _chdoormake_entrypoint_5(actor, 1.0f);
        _chdoormake_entrypoint_7(actor, 1.0f);
    }
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
extern void func_80101870();
extern void _chdoor_entrypoint_1();
// TU-NOTE: the .data of this overlay is defined in this file; IDO schedules some of the
// functions differently unless the tables live in the same unit. Values are from the ROM.
MadameReward D_80800AF0_chmadamegrunty[8] = {
    -0x1,  -0x1,  0x0,  0x0,  0.01f, 0x40,  0x31,  0x14, 0x0,  0.11f, 0x41,  0x2C, 0x5,  0x0,
    0.11f, 0x43,  0x2D, 0x5,  0x0,   0.11f, 0x46,  0x9,  0xA,  0x0,   0.11f, 0x47, 0x12, 0x5,
    0x0,   0.11f, -0x1, -0x1, 0x1,   0x0,   0.11f, -0x1, -0x1, -0x1,  0x0,   0.33f};
int D_80800B50_chmadamegrunty[18] = {0x1AC014F,
                                     0x1,
                                     0x0,
                                     (u32) func_8080005C_chmadamegrunty,
                                     (u32) func_80105834,
                                     (u32) func_8010A730,
                                     0x7D00000,
                                     0x0,
                                     0x0,
                                     0x1,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800018_chmadamegrunty,
                                     (u32) func_80107C2C,
                                     -0x7FFFD9FE,
                                     (u32) func_80800198_chmadamegrunty,
                                     0x0};
int D_80800B98_chmadamegrunty[18] = {0xAC03D4,
                                     0x7010001,
                                     0x0,
                                     (u32) _chdoor_entrypoint_0,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x800,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800A30_chmadamegrunty,
                                     (u32) func_80107C2C,
                                     -0x7FFFD3FE,
                                     (u32) _chdoor_entrypoint_1,
                                     0x0};
MadameEntry D_80800BE0_chmadamegrunty[9] = {
    0x415, 0.1f,  0.9f, 0x417, 0.15f, 0.9f,  0x427, 0.2f,  1.0f, 0x40D, 0.35f, 1.0f,  0x424, 0.45f,
    1.0f,  0x415, 0.6f, 1.0f,  0x417, 0.65f, 1.0f,  0x423, 0.7f, 1.0f,  0x492, 0.85f, 1.0f};
u8 D_80800C4C_chmadamegrunty[20] = {0x0, 0x2, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                                    0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
