#include "common.h"

extern int D_808002F0_chdiggerbossbattery[];
extern void func_800FFAB0();
extern f32 func_800DC178(f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFD24(f32 *);
extern u8 D_80800338_chdiggerbossbattery[];
extern s32 func_800DC298(f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void _chexploder_entrypoint_15(Actor *, s32, f32);

int chdiggerbossbattery_entrypoint_0()
{
    return (int) &D_808002F0_chdiggerbossbattery;
}

// Init: despawns at once if this battery was already destroyed.
void func_8080000C_chdiggerbossbattery(Actor *actor)
{
    func_800EE7F8((f32 *) actor->actorData, actor->position);
    func_800EFD24(actor->position);
    func_80102FDC(actor, 0x3E800000);
    actor->unk58 = func_800DC178(1.5f, 3.0f);
    if (func_800DA298(actor->unk74_7 + 0xA1D)) {
        func_800FFAB0(actor);
    }
}

// Update: spawns an electric fence bolt every 1.5-3 s.
void func_80800090_chdiggerbossbattery(Actor *actor)
{
    f32 pos[3];
    f32 side;

    _subaddieaudioloop_entrypoint_4(actor, actor->actorData, 1, D_80800338_chdiggerbossbattery);
    if (func_800D9078(&actor->unk58)) {
        func_800EE7F8(pos, actor->actorData);
        if (func_800DC298(0.5f))
            side = 1.0f;
        else
            side = -1.0f;
        func_800EF1B8(pos, side * 90.0f, 80.0f);
        pos[1] += 300.0f;
        _chelectricfence_entrypoint_1(actor, pos);
        actor->unk58 = func_800DC178(1.5f, 3.0f);
    }
}

s32 func_80800170_chdiggerbossbattery(Actor *actor, s32 msg, s32 param_2)
{
    f32 pos[3];
    Actor *linked;
    Actor *linked_copy;
    switch (msg) {
        case 0x40:
            // Hit: explode, mark destroyed, remove the linked actor.
            func_800EE7F8(pos, (f32 *) actor->actorData);
            func_800EF1B8(pos, actor->rotation[1], -400.0f);
            pos[1] -= 80.0f;
            func_800DA544(actor->unk74_7 + 0xA1D);
            func_8010A624(actor);
            _chexploder_entrypoint_3(actor, pos, 12);
            func_800FC660(14);
            linked = (Actor *) _subaddiefind_entrypoint_1(actor, actor->unk6C_9, -1, 0);
            linked_copy = linked;
            if (!linked)
                break;
            func_8010A570(linked_copy);
            break;
        case 0x90:
            linked = func_80106790((Unk80132ED0 *) func_80101080());
            _chexploder_entrypoint_9(linked, 1, 2);
            _chexploder_entrypoint_15(linked, 2, 1.0f);
            _chexploder_entrypoint_13(linked, 1);
            break;
        case 0x95:
            // Model id per battery index, from a table before the ActorInfo.
            func_80103140(actor,
                          ((u16 *) ((u8 *) &D_808002F0_chdiggerbossbattery - 8))[actor->unk74_7],
                          0);
            break;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(1, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

extern void func_80102EC0();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808002F0_chdiggerbossbattery[18] = {0x15804F5,
                                          -0xFFFF,
                                          0x0,
                                          (u32) func_80800090_chdiggerbossbattery,
                                          (u32) func_80102EC0,
                                          (u32) func_801018A4,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0xC00,
                                          0x0,
                                          (u32) func_80108ED0,
                                          0x0,
                                          (u32) func_8080000C_chdiggerbossbattery,
                                          (u32) func_80107C2C,
                                          -0x7FFFFC00,
                                          (u32) func_80800170_chdiggerbossbattery,
                                          0x0};
u8 D_80800338_chdiggerbossbattery[24] = {0x0,  0x13, 0x5, 0xB7, 0x0, 0x1,  0x0, 0xC8,
                                         0x3,  0xE8, 0x0, 0xA,  0x1, 0x66, 0x0, 0x16,
                                         0x7D, 0x0,  0x0, 0x0,  0x9, 0x9,  0x9, 0xA};
