#include "common.h"

extern void *D_80800640_chvandoor;
extern s32 D_80800688_chvandoor[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800F5A00(s32, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
void func_80800388_chvandoor();
s32 func_8080044C_chvandoor();

int chvandoor_entrypoint_0()
{
    return &D_80800640_chvandoor;
}

void func_8080000C_chvandoor(Actor *actor)
{
    s32 unk_0;

    unk_0 = actor->unk74_7 + 0xA08;
    func_800EE7F8((f32 *) ((u8 *) actor + 0x18), actor->position);
    func_800EE7F8((f32 *) ((u8 *) actor + 0x28), actor->position);
    *(f32 *) ((u8 *) actor + 0x2C) += actor->scale * 300.0f;
    *(s32 *) ((u8 *) actor + 0x50) = unk_0;
    if (!func_800F64A4(func_800F54E4(), 0x8000)) {
        func_800DA524(unk_0);
    }
    if (func_800DA298(unk_0)) {
        func_80800388_chvandoor(actor, 3);
        func_800EE7F8(actor->position, (f32 *) ((u8 *) actor + 0x28));
    } else {
        func_80800388_chvandoor(actor, 1);
    }
    func_8010A800(actor, 0);
    if (func_800EA05C() == 0xE7) {
        _subaddieDll_entrypoint_0(actor);
    }
}

void func_80800104_chvandoor(Actor *actor)
{
    s32 in_progress;
    s32 finished;
    f32 *pos;
    in_progress = 0;
    switch (actor->unk70_10) {
        default:
            pos = actor->position;
            break;
        case 1:
            pos = actor->position;
            break;
        case 2:
            finished = func_800D9078((u8 *) actor + 0x58);
            pos = actor->position;
            func_800EFE50(pos, (f32 *) actor->actorData, (f32 *) ((u8 *) actor + 0x28),
                          func_800F10B4(*(f32 *) ((u8 *) actor + 0x58), 0.0f, 2.0f, 1.0f, 0.0f));
            if (finished)
                func_80800388_chvandoor(actor, 3);
            in_progress = !finished;
            break;
        case 3:
            if (func_8080044C_chvandoor(actor))
                func_80101180(0x3CC, 8, (u32) *(u16 *) ((u8 *) actor + 0x76) >> 7);
            pos = actor->position;
            break;
        case 4: {
            s32 finished_2;
            finished_2 = func_800D9078((u8 *) actor + 0x58);
            pos = actor->position;
            func_800EFE50(pos, (f32 *) actor->actorData, (f32 *) ((u8 *) actor + 0x28),
                          func_800F10B4(*(f32 *) ((u8 *) actor + 0x58), 0.0f, 2.0f, 0.0f, 1.0f));
            if (finished_2)
                func_80800388_chvandoor(actor, 1);
            in_progress = !finished_2;
        }
    }
    _subaddieaudioloop_entrypoint_4(actor, pos, in_progress, &D_80800688_chvandoor);
}

int func_80800280_chvandoor(Actor *actor, s32 msg, s32 id)
{
    f32 pos[3];

    switch (msg) {
        case 0x19:
            if (actor->unk70_10 == 1) {
                func_800F5A00(id, pos);
                if (func_800EEB40(pos, actor->position) < 250000.0f) {
                    func_80101180(0x3CC, 7, actor->unk74_7);
                }
            }
            break;
        case 7:
            if (id != actor->unk74_7) {
                return 0;
            }
            func_80800388_chvandoor(actor, 2);
            break;
        case 8:
            if (id != actor->unk74_7) {
                return 0;
            }
            func_80800388_chvandoor(actor, 4);
            break;
        default:
            return 0;
    }
    return 1;
}

// Matching: old-style (K&R) parameter list.
void func_80800388_chvandoor(actor, state) Actor *actor;
s32 state;
{
    func_80101FDC();

switch (state) {
    case 1:
        func_80103110(actor, 0);
        func_800DA524(*(s32 **) ((char *) actor + 0x50));
        return;
    case 2:
        func_80103110(actor, 1);
        *(f32 *) ((char *) actor + 0x58) = 2.0f;
        func_800DA544(*(s32 **) ((char *) actor + 0x50));
        return;
    case 3:
        func_80103110(actor, 1);
        return;
    case 4:
        *(f32 *) ((char *) actor + 0x58) = 2.0f;
}

}

// TU-NOTE: .bss is defined here, ahead of its first use: IDO places .bss objects used before
// their definition first, the rest in definition order. The _tail object fills bytes no code names.
u8 *B_80800690_chvandoor[1];
u8 *B_80800694_chvandoor;
u8 B_80800694_chvandoor_tail[24];

// Matching: the line breaks in this function are needed for the match.
// Collects doors with the same group id, sorts them by distance to the target (insertion sort),
// and returns 1 if this door is the closest and farther than 1500 units (2250000 = 1500^2).
s32 func_8080044C_chvandoor(door)
u8 *door;
{
    f32 target_pos[3];
    s32 find_state[2];
    s32 target_id;
    s32 count;
    s32 i;
    s32 j;
    u8 *other;

    target_id = func_8010D290(0x10000);
    count = 0;

if (target_id == -1) {
    return 0;
}

func_800F5A00(target_id, target_pos);
other = _subaddiefind_entrypoint_2(0x3CC, find_state);

if (other != 0) {
    do { if (((u32)*(u16 *)(other + 0x76) >> 7) == ((u32)*(u16 *)(door + 0x76) >> 7)) { B_80800690_chvandoor[count] = other; count++; } other = _subaddiefind_entrypoint_3(0x3CC, find_state); } while (other != 0);
}

for (i = 1; i < count; i++) {
    for (j = i;
         j > 0 && func_800EEB40((f32 *) (B_80800690_chvandoor[j] + 4), target_pos) <
                            func_800EEB40((f32 *) (B_80800690_chvandoor[j - 1] + 4), target_pos);
         j--) {
        other = B_80800690_chvandoor[j];
        B_80800690_chvandoor[j] = B_80800690_chvandoor[j - 1];
        B_80800690_chvandoor[j - 1] = other;
    }
}
if (door != B_80800690_chvandoor[0]) {
    return 0;
}
return func_800EEB40((f32 *) (B_80800690_chvandoor[0] + 4), target_pos) > 2250000.0f;
}

// TU-NOTE: .data is defined here in C. Its tables hold pointers to functions of this file; IDO's
// assembler schedules some of them differently unless the tables are in the same unit. Values from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
void *D_80800640_chvandoor = (void *) 0x00AC03CC;
static u32 D_80800640_chvandoor_rest[17] = {0x7A50001,
                                            0x0,
                                            (u32) func_80800104_chvandoor,
                                            (u32) func_80105834,
                                            (u32) func_80101870,
                                            0x0,
                                            0x0,
                                            0x0,
                                            0x40000800,
                                            0x0,
                                            0x0,
                                            0x0,
                                            (u32) func_8080000C_chvandoor,
                                            (u32) func_80107C2C,
                                            0x80002C12,
                                            (u32) func_80800280_chvandoor,
                                            0x0};
s32 D_80800688_chvandoor[2] = {0x130507, 0x0};
