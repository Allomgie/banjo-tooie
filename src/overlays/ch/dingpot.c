#include "common.h"

extern int D_80800500_chdingpot[];
extern void func_80102FDC(u8 *, f32);
extern int func_80101DDC(void *param_0);
extern void func_80102424(void *param_0, int param_1);
extern int func_80101E14(void *param_0, int param_1);
extern void func_800C3F48(int param_0);
extern void func_800EE7F8(void *param_0, void *param_1);
extern void func_800EF1B8(void *param_0, void *param_1, int param_2);
extern void func_800F4CC0(int param_0);
extern int func_800F54E4(void);
extern void func_800F82D4(int param_0, int param_1);
extern void func_800F7844(int param_0, void *param_1, int param_2, int param_3);
extern void func_800D175C(int param_0, int param_1);
extern void _subaddieDll_entrypoint_4(void *param_0, int param_1);
extern s32 D_80800548_chdingpot[4];
extern s32 D_80800568_chdingpot[4];
extern u8 D_808005A4_chdingpot[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
typedef union {
    s16 half[2];
    s32 word;
} DingpotNotes1559;
extern DingpotNotes1559 D_808005B4_chdingpot;
extern s32 D_808005B8_chdingpot[];
extern int func_80101E4C(Actor *, f32 *);
extern int _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
extern int func_800DC128(s32, s32);
extern void func_800C301C(s32, s32);
extern void func_800C4350(s32, f32 *, void *);
extern void func_800C3BDC(s32);
extern s32 D_808005C8_chdingpot[];
extern s32 D_808004B0_chdingpot[];
extern int D_808005D8_chdingpot[];
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800C9C04(f32, s32, s32);
void func_808002B4_chdingpot();
int func_80800350_chdingpot();
void func_80800388_chdingpot();

int chdingpot_entrypoint_0()
{
    return (int) &D_80800500_chdingpot;
}

void func_8080000C_chdingpot(u8 *actor)
{
    func_80102FDC(actor, *(f32 *) (actor + 0x38) * 0.5f);
}

void func_80800040_chdingpot(void *actor)
{
    s8 _sfpad[8];
    int launch_pos;
    switch ((u32) ((u16 *) actor)[0x39] >> 10) {
        case 1:
            func_808002B4_chdingpot(actor, &D_80800548_chdingpot);
            if (func_80800350_chdingpot(actor) == 0) {
                func_80800388_chdingpot(actor);
            }
            return;

        case 2:
            func_808002B4_chdingpot(actor, &D_80800548_chdingpot);
            break;

        case 3:
            func_808002B4_chdingpot(actor, &D_80800568_chdingpot);
            if (func_80101DDC(actor) != 0) {
                func_80102424(actor, 4);
            }
            break;

        // Refill all egg and feather counters, then launch the player.
        case 4:
            if (func_80101E14(actor, 0x3F189375)) {
                func_800C3F48(0x6CBF441E);
            }
            if (func_80101E14(actor, 0x3F2147AE)) {
                func_800EE7F8(&launch_pos, (void *) ((char *) actor + 4));
                func_800EF1B8(&launch_pos, *(s32 *) ((char *) actor + 0x48), 0x43C80000);
                func_800F4CC0(func_800F54E4());
                func_800F82D4(func_800F54E4(), 0);
                func_800F7844(func_800F54E4(), &launch_pos, 0x44CA8000, 0xC5802000);
                func_800D175C(0x40, 0x270F);
                func_800D175C(0x41, 0x270F);
                func_800D175C(0x42, 0x270F);
                func_800D175C(0x43, 0x270F);
                func_800D175C(0x44, 0x270F);
                func_800D175C(0x46, 0x270F);
                func_800D175C(0x47, 0x270F);
            }
            if (func_80101DDC(actor) != 0) {
                func_80102424(actor, 1);
                _subaddieDll_entrypoint_4(actor, 0);
            }
    }
}

s32 func_8080021C_chdingpot(Actor *actor, s32 msg_type, s32 msg)
{
    switch (msg_type) {
        case 0x2E:
            func_80102424(actor, 1);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808005A4_chdingpot, actor->scale);
            break;
        case 0xB:
            func_800F7F98(func_800F54E4(), 0);
            return 3;
        default:
            return 0;
    }
    return 1;
}

void func_808002B4_chdingpot(actor, interval) Actor *actor;
f32 *interval;
{
    DingpotNotes1559 notes;

    notes = D_808005B4_chdingpot;
    if (func_80101E4C(actor, interval)) {
        if (!actor->unk5F)
            actor->unk5F = _subaddieaudioquick_entrypoint_1(actor, actor->position);
        func_800C301C(actor->unk5F, notes.half[func_800DC128(0, 2)]);
        func_800C4350(actor->unk5F, actor->position, &D_808005B8_chdingpot);
        func_800C3BDC(actor->unk5F);
    }
}

int func_80800350_chdingpot(actor)
s32 actor;
{
    s32 dialog_count;
    dialog_count = 5;
    _subaddiedialog_entrypoint_8(actor, actor + 4, &D_808005C8_chdingpot, &D_808004B0_chdingpot,
                                 dialog_count);
}

void func_80800388_chdingpot(actor) s32 *actor;
{
    s32 player;
    f32 player_pos[3];
    f32 *self_pos;

    // Matching: empty block, needed for the match.
    if (&actor) {
    }
    // Active only once flag 0x1AC is set.
    if (func_800DA298(0x1AC)) {
        player = _plsu_entrypoint_3(actor[0]);
        if (func_800F54E4() == player && player != -1) {
            if (func_800F64A4(player, 0xB)) {
                func_800F5A00(player, player_pos);
                self_pos = (f32 *) &actor[1];
                // Matching: empty block, needed for the match.
                if (player && player && player) {
                }
                // Player within 100 units.
                if (func_800EEB40(self_pos, player_pos) < 10000.0f) {
                    _subaddieaudioquick_entrypoint_2(actor, self_pos, &D_808005D8_chdingpot);
                    _subaddieDll_entrypoint_4(actor, 1);
                    func_80102424(actor, 3);
                    func_800F82D4(player, 2);
                    func_800F7F98(player, 1);
                    _capod_entrypoint_13(actor[0], 0, 2, 0x10);
                    func_800F4CEC(player, 0x60);
                    func_800C9C04(0.5f, 0x15, 22000);
                }
            }
        }
    }
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
s32 D_808004B0_chdingpot[10] = {0x1,       0xCE90100, 0x601,     0xCEA0200, 0x200,
                                0xD080100, 0x400,     0xD090100, -0x12001,  0x120F0300};
u32 D_808004D8_chdingpot[10] = {0x0,       0x0,        0x40CCCCCD, 0x2B00001,  0x40CCCCCD,
                                0x2B00001, 0x4059999A, 0x2B10002,  0x3F800000, 0x2B20002};
int D_80800500_chdingpot[18] = {0x32F03D1,
                                0x7A70001,
                                (u32) &D_808004D8_chdingpot,
                                (u32) func_80800040_chdingpot,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x9C40000,
                                0x40800000,
                                0x0,
                                0x908,
                                0x0,
                                0x0,
                                0x0,
                                (u32) func_8080000C_chdingpot,
                                (u32) func_80107C2C,
                                -0x7FFFFBFE,
                                (u32) func_8080021C_chdingpot,
                                0x0};
s32 D_80800548_chdingpot[4] = {0x3F122D0E, 0x3F1BA5E3, 0x3F251EB8, 0x3F2F5C29};
static u32 D_80800548_chdingpot_rest[4] = {0x3F374BC7, 0x3F400000, 0x3F4A7EFA, 0xBF800000};
s32 D_80800568_chdingpot[4] = {0x3E960419, 0x3EC08312, 0x3ED70A3D, 0x3EE7EF9E};
static u32 D_80800568_chdingpot_rest[11] = {0x3EF9DB23, 0x3F05A1CB, 0x3F0E5604, 0x3F170A3D,
                                            0x3F204189, 0x3F29374C, 0x3F316873, 0x3F3A9FBE,
                                            0x3F439581, 0x3F5CED91, 0xBF800000};
u8 D_808005A4_chdingpot[16] = {0x43, 0xC8, 0x0, 0x0, 0x43, 0xC8, 0x0, 0x0,
                               0x43, 0xC8, 0x0, 0x0, 0x43, 0x34, 0x0, 0x0};
DingpotNotes1559 D_808005B4_chdingpot = {0x555, 0x556};
s32 D_808005B8_chdingpot[4] = {0x306000D, 0x1000119, 0x162AF8, 0x30000};
s32 D_808005C8_chdingpot[4] = {0x1AC0000, 0x15E00A4, 0xC, 0x63C0200};
int D_808005D8_chdingpot[6] = {0x13041F, 0xD00C0, 0xD90000, 0x0, 0x0, 0x0};
