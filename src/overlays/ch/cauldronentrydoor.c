// Cauldron Keep entrance: an electrified door plus the drawbridge, which lowers once both
// drawbridge switches have fired and sets the drawbridge-open flag.
#include "ch/cauldronentrydoor.h"

extern void *func_80100094(Actor *, s32);
extern int D_80800550_chcauldronentrydoor[];
extern u8 D_80800520_chcauldronentrydoor[];
extern s32 func_800D9078(f32 *);
extern s32 func_800DC298(f32);
typedef union {
    s32 word;
    void *pointer;
} CauldronEntryDoorPayload;
extern f32 func_800EC75C(s32, f32 *);
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);
extern u8 D_80800534_chcauldronentrydoor[];
extern u8 D_80800540_chcauldronentrydoor[];
extern void _chcauldronentrydoor_entrypoint_0(void);
extern s32 func_800E15CC(s32, f32, f32);
extern void func_800C9DE4(f32, void (*)(void), s32);

// Sets up the door; removes it if the drawbridge is already open.
void func_80800000_chcauldronentrydoor(s32 actor)
{
    u8 *door_data;

    door_data = func_80100094(actor, 1);
    if (_chdoormake_entrypoint_4(actor, 1, 0x58E) != 0) {
        _chdoormake_entrypoint_5(actor, 0x3F800000);
        _chdoormake_entrypoint_6(actor, 0x40000000);
        _chdoormake_entrypoint_8(actor, 0xB);
        _chdoormake_entrypoint_9(actor, 0, 0x56, 0x14);
    }
    func_8010A800(actor, 0);
    func_80104004(actor, door_data, door_data + 0xC);
    *(f32 *) ((s8 *) door_data + 0x14) = (f32) (*(f32 *) ((s8 *) door_data + 8) + 40.0f);
    if (_glcutDll_entrypoint_19(0x5B) != 0) {
        func_800FFAB0(actor);
    }
}

// Shocks the player at the door while flag 0x436 is set.
void func_808000C8_chcauldronentrydoor(Actor *actor)
{
    u8 *door_data;
    _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80800520_chcauldronentrydoor);
    if (func_800D9078((f32 *) &actor->actorData[4]))
        func_8010A590(actor);
    if (actor->unk7C_12 && func_800DA298(0x436) && func_800DC298(0.2f)) {
        door_data = func_80100094(actor, 1);
        _chelectricfence_entrypoint_2(actor, door_data, door_data + 0xC);
    }
    _chdoor_entrypoint_0(actor);
}

s32 func_80800168_chcauldronentrydoor(Actor *actor, s32 msg, CauldronEntryDoorPayload data)
{
    s32 raw;
    f32 shock_pos[3];
    switch (msg) {
        case 7:
            func_800FC6B0(0xE);
            return _chdoor_entrypoint_1(actor, msg, data.word);
        case 0x3F:
            raw = data.word;
            func_800EC75C(raw, shock_pos);
            _chelectricfence_entrypoint_1(actor, shock_pos);
            func_8010A570(actor);
            *(f32 *) (actor->actorData + 4) = 0.2f;
            return 1;
        default:
            return 0;
    }
}

// Drawbridge init: rotation 360 if already open, otherwise 270.
void func_808001FC_chcauldronentrydoor(Actor *actor)
{
    *(u16 *) ((char *) actor + 0x6E) = *(u16 *) ((char *) actor + 0x6E) & 0xFE00;
    *(f32 *) ((char *) actor + 0x18) = 0.0f;
    if (func_800DA298(0x436, actor) != 0) {
        *(f32 *) ((char *) actor + 0x1C) = 360.0f;
    } else {
        *(f32 *) ((char *) actor + 0x1C) = 270.0f;
    }
    *(f32 *) ((char *) actor + 0x20) = 0.5f;
    *(f32 *) ((char *) actor + 0x44) = *(f32 *) ((char *) actor + 0x1C);
}

// Messages 0x68..0x6B carry two 2-bit switch states; when both are set the drawbridge opens.
s32 func_80800274_chcauldronentrydoor(Actor *actor, s32 msg, s32 data)
{
    s32 state;
    s32 mask;

    if (msg == 0x95) {
        actor->rotation[0] = *(f32 *) &actor->actorData[1];
        return 1;
    }
    if (func_800DA298(0x436)) {
        return 0;
    }
    if (msg >= 0x68 && msg < 0x6C) {
        state = msg - 0x68;
        mask = state & 2 ? 2 : 1;
        actor->unk6C_0 = (actor->unk6C_0 & (3 - mask)) + ((state & 1) * mask);
        if (actor->unk6C_0 == 3) {
            func_800DA544(0x436);
            _capod_entrypoint_13(actor->unk0, 0, 4, 16);
            func_800FC6B0(14);
        }
        return 1;
    }
    return 0;
}

void func_80800370_chcauldronentrydoor(s32 arg0)
{
}

void chcauldronentrydoor_entrypoint_0()
{
    func_800E1720();
}

// Drawbridge: short delay, then lowers with accelerating speed, sound and screen shake.
void func_80800398_chcauldronentrydoor(Actor *actor)
{
    f32 speed;

    if (actor->unk6C_0 == 3) {
        switch (actor->unk70_10) {
            case 1:
                *(f32 *) &actor->actorData[0] += 1.0f;
                if (*(f32 *) &actor->actorData[0] > 25.0f)
                    func_80101FDC(actor, 2);
                break;
            case 2:
                if (*(f32 *) &actor->actorData[1] < 360.0f) {
                    speed = *(f32 *) &actor->actorData[2];
                    *(f32 *) &actor->actorData[1] += speed;
                    *(f32 *) &actor->actorData[2] = speed * 1.16f;
                    if (*(f32 *) &actor->actorData[1] > 360.0f)
                        *(f32 *) &actor->actorData[1] = 360.0f;
                    _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                    D_80800540_chcauldronentrydoor);
                } else {
                    func_80101FDC(actor, 3);
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800534_chcauldronentrydoor);
                    func_800C9DE4(0.7f, _chcauldronentrydoor_entrypoint_0,
                                  func_800E15CC(0, 20.0f, 1.0f));
                }
        }
    }
    actor->rotation[0] = *(f32 *) &actor->actorData[1];
}

int chcauldronentrydoor_entrypoint_1()
{
    return (int) &D_80800550_chcauldronentrydoor;
}

int chcauldronentrydoor_entrypoint_2(void)
{
    extern int D_80800598_chcauldronentrydoor[];
    return &D_80800598_chcauldronentrydoor;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_80800520_chcauldronentrydoor[20] = {0x0, 0x13, 0x5, 0xB7, 0x0,  0xE,  0x0, 0xF3, 0x1, 0xC,
                                         0x0, 0x19, 0x0, 0x16, 0x7F, 0xBC, 0x0, 0x0,  0x0, 0x0};
u8 D_80800534_chcauldronentrydoor[12] = {0x0, 0x13, 0x4, 0xC7, 0x0, 0x18,
                                         0x0, 0x2,  0x0, 0x0,  0x0, 0x0};
u8 D_80800540_chcauldronentrydoor[16] = {0x0, 0x13, 0x5, 0x7,  0x0, 0x18, 0x0, 0x2,
                                         0x0, 0xA,  0x0, 0x8C, 0x0, 0x0,  0x0, 0x0};
int D_80800550_chcauldronentrydoor[18] = {0x3310395,
                                          0x8ED0001,
                                          0x0,
                                          (u32) func_808000C8_chcauldronentrydoor,
                                          (u32) func_80105834,
                                          (u32) func_80101870,
                                          0x0,
                                          0x0,
                                          0x58E0000,
                                          0x1C00,
                                          (u32) func_80800370_chcauldronentrydoor,
                                          (u32) func_80108ED0,
                                          0x18,
                                          (u32) func_80800000_chcauldronentrydoor,
                                          (u32) func_80107C2C,
                                          -0x7FFFFC00,
                                          (u32) func_80800168_chcauldronentrydoor,
                                          0x0};
int D_80800598_chcauldronentrydoor[18] = {0xAC049F,
                                          0x8EE0001,
                                          0x0,
                                          (u32) func_80800398_chcauldronentrydoor,
                                          (u32) func_80105834,
                                          (u32) func_80101870,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0xC00,
                                          (u32) func_80800370_chcauldronentrydoor,
                                          0x0,
                                          0x0,
                                          (u32) func_808001FC_chcauldronentrydoor,
                                          (u32) func_80107C2C,
                                          -0x7FFFFBFE,
                                          (u32) func_80800274_chcauldronentrydoor,
                                          0x0};
