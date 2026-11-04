// Probably the big falling icicles: placement and flag come from a table by marker id. When hit
// (message 0x40) one shakes, falls, lands with rumble and sound and sets its flag.
#include "common.h"

extern void *D_808003A0_chiciclebits;
typedef struct {
    s16 pos[3];
    u16 flag;
    u16 pad_0;
} IciclePlacement;
extern IciclePlacement D_808003E8_chiciclebits[];
extern void func_800EE88C();
extern void func_800EF334(f32 *, f32);
extern u8 D_808003EE_chiciclebits[];
extern s32 D_80800430_chiciclebits[];
extern s32 D_80800468_chiciclebits[];
extern s32 D_808004A8_chiciclebits[];
extern f32 func_800D8FF8(void);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_80018820(s32, f32, f32);
extern u16 D_808003F0_chiciclebits[][5];
extern u8 D_808004B8_chiciclebits[];
extern u8 D_808004C8_chiciclebits[];

int chiciclebits_entrypoint_0()
{
    return (int) &D_808003A0_chiciclebits;
}

// Init: placement and progress flag come from the table by marker id; fallen icicles start on the ground.
void func_8080000C_chiciclebits(Actor *actor)
{
    s32 index;

    index = actor->unk74_7 - 0x32;
    func_800EE88C(actor->position, (&D_808003E8_chiciclebits[index])->pos);
    func_800EF334(actor->position, 100.0f);
    actor->actorData[4] = index;
    *(f32 *) &actor->actorData[5] = actor->position[1];
    *(f32 *) &actor->actorData[7] = 600.0f;
    actor->position[1] += 2500.0f;
    if (func_800DA298((&D_808003E8_chiciclebits[index])->flag)) {
        actor->position[1] = *(f32 *) &actor->actorData[5];
        func_8010A570(actor);
        func_80101FDC(actor, 4);
    }
}

// Per-frame: waits for a hit, then falls with gravity and lands with sound and rumble.
void func_808000D0_chiciclebits(Actor *actor)
{
    f32 dt;

    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            _subaddieDll_entrypoint_7(actor, 8);
            if (func_800D9078(&actor->unk58)) {
                func_800BBCB8(actor->position, actor->position, 1.0f, 6,
                              &D_80800430_chiciclebits);
                func_800BBCB8(actor->position, actor->position, 1.0f, 8,
                              &D_80800468_chiciclebits);
                func_80101FDC(actor, 3);
            }
            break;
        case 3:
            dt = func_800D8FF8();
            actor->position[1] -= *(f32 *) ((u8 *) actor + 0x34) * dt;
            *(f32 *) ((u8 *) actor + 0x34) += 2500.0f * dt;
            if (actor->position[1] < *(f32 *) ((u8 *) actor + 0x2C)) {
                actor->position[1] = *(f32 *) ((u8 *) actor + 0x2C);
                *(f32 *) ((u8 *) actor + 0x34) = 600.0f;
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 &D_808004A8_chiciclebits);
                func_80101FDC(actor, 4);
                func_80103110(actor, 0);
                func_800DA544(
                    *(u16 *) (D_808003EE_chiciclebits + *(s32 *) ((u8 *) actor + 0x28) * 10));
                func_80018820(0, 5.0f, 0.4f);
            }
    }
}

// Message handler: 0x40 (hit) starts the shake.
s32 func_80800240_chiciclebits(Actor *actor, s32 msg, s32 msg_data)
{
    s32 show_dialog;
    switch (msg) {
        case 0x40:
            show_dialog = !func_80101180(0x41C, 0x43, 0);
            _subaddieaudioquick_entrypoint_2(actor, NULL, D_808004B8_chiciclebits);
            _subaddieaudioquick_entrypoint_2(actor, NULL, D_808004C8_chiciclebits);
            func_8010A570(actor);
            func_80101FDC(actor, 2);
            func_80103110(actor, 1);
            func_80018820(0, 3.0f, 0.5f);
            *(f32 *) ((u8 *) actor + 0x58) = 1.4f;
            if (show_dialog)
                _capod_entrypoint_13(actor->unk0, 0, 0, 0x11);
            break;
        case 0x43:
            if (actor->unk70_10 == 1)
                return 0;
            break;
        case 0x95:
            func_80103140(actor, D_808003F0_chiciclebits[*(s32 *) ((u8 *) actor + 0x28)][0],
                          *(u16 *) ((u8 *) actor->unk0 + 0x16));
            break;
        default:
            return 0;
    }
    return 1;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
void *D_808003A0_chiciclebits = (void *) 0x00AF041C;
static u32 D_808003A0_chiciclebits_rest[17] = {0x7B10001,
                                               0x0,
                                               (u32) func_808000D0_chiciclebits,
                                               (u32) func_80105834,
                                               (u32) func_80101870,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x800,
                                               0x0,
                                               (u32) func_80108ED0,
                                               0x0,
                                               (u32) func_8080000C_chiciclebits,
                                               (u32) func_80107C2C,
                                               0x80000C00,
                                               (u32) func_80800240_chiciclebits,
                                               0x0};
IciclePlacement D_808003E8_chiciclebits[7] = {
    0x35,  0x14,  -0x12, 0x1ED, 0x7B1, 0x35,  0x15,  -0xE,  0x1EE, 0x7B2, 0x35, 0x16,
    -0x9,  0x1EF, 0x7B3, 0x35,  0x17,  -0x5,  0x1F0, 0x7B4, 0x35,  0x18,  -0x1, 0x1F1,
    0x7B5, 0x35,  0x19,  0x2,   0x1F2, 0x7B6, 0x35,  0x1A,  0x8,   0x1F3, 0x7B7};
s32 D_80800430_chiciclebits[14] = {0x1D09DD,  0x2080FF, -0x3F7FFFEA, 0x2080022, 0x19901CC,
                                   0x2800300, 0x150033, 0x99002B,    0x1330166, 0xB003C,
                                   0x500014,  0x2D,     0x640096,    0x0};
s32 D_80800468_chiciclebits[16] = {0x1D075E, 0x160200,  0x2B0133,   0x1660027, 0xC800C8,  0x1900190,
                                   0x2D015E, 0x1C2001B, -0x3E70320, 0x220180,  0x20000C0, 0x1000015,
                                   0xCC,     0xB003C,   0x500014,   0x0};
s32 D_808004A8_chiciclebits[4] = {0x1305B8, 0xD00F3, 0x10C0018, 0x20000};
u8 D_808004B8_chiciclebits[16] = {0x0, 0x13, 0x5, 0x2B, 0x0, 0x18, 0x0, 0x2,
                                  0x0, 0xD,  0x0, 0xE6, 0x1, 0x19, 0x0, 0x0};
u8 D_808004C8_chiciclebits[24] = {0x0, 0x13, 0x4, 0x7, 0x0, 0x2, 0x0, 0xD, 0x1, 0x4C, 0x1, 0x66,
                                  0x0, 0x0,  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0};
