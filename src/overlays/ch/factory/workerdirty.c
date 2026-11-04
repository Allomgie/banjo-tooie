// Skivvies, the six dirty GI factory workers: friendly talking NPCs with their own clothing item
// (workerwear.c); Washer Banjo cleans them, and once all are washed one hands out the reward.
#include "ch/factory/workerdirty.h"

extern int D_80800EF8_chfactoryworkerdirty[];
extern s32 D_80800F90_chfactoryworkerdirty[];
extern void _subaddieaudioquick_entrypoint_2(s32, s32, void *);
extern s32 D_80800FD0_chfactoryworkerdirty;
extern u16 D_80800FD4_chfactoryworkerdirty[];
extern u16 D_80800FD6_chfactoryworkerdirty;
extern s32 D_80800FEC_chfactoryworkerdirty[];
extern s16 D_8080100C_chfactoryworkerdirty[];
extern u8 D_80801008_chfactoryworkerdirty[];
extern void func_80101010(s32);
extern void func_8010105C(f32);
extern u8 D_80800F80_chfactoryworkerdirty[];
extern u8 D_80800FA0_chfactoryworkerdirty[];
extern u8 D_80800FB0_chfactoryworkerdirty[];
extern u8 D_80800FC0_chfactoryworkerdirty[];
extern u8 D_80800F40_chfactoryworkerdirty[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _sudeflect_entrypoint_1(u8 *, f32, f32, f32, s32);
extern void _subaddieaudioquick_entrypoint_3();
extern s32 func_80101E14(Actor *, f32);
extern void func_800BBCB8(u8 *, u8 *, f32, s32, u8 *);
typedef union DirtyWorkerEvent {
    u32 local_0;
    s16 local_1[2];
} DirtyWorkerEvent;
extern f32 D_80801024_chfactoryworkerdirty[];
extern f32 D_80801034_chfactoryworkerdirty[];
extern void _gcdialogcamera_entrypoint_3(f32 *, f32);
s32 func_808009C0_chfactoryworkerdirty();
int func_80800A14_chfactoryworkerdirty();
s32 func_80800A54_chfactoryworkerdirty();
int func_80800AB4_chfactoryworkerdirty();
s32 func_80800B40_chfactoryworkerdirty();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080025C_chfactoryworkerdirty(),
    func_80800340_chfactoryworkerdirty();

// Returns the ActorInfo of the skivvy.
int chfactoryworkerdirty_entrypoint_0()
{
    return &D_80800EF8_chfactoryworkerdirty;
}

void func_8080000C_chfactoryworkerdirty(Actor *actor)
{
    func_80108B04(actor, 1);
}

void func_8080002C_chfactoryworkerdirty(Actor *actor)
{
    void *state = func_80100094(actor, 0);
    func_8010114C(*(s32 **) ((char *) state + 0x0), 0x2C, 0);
    *(s32 **) ((char *) state + 0x0) = 0;
}

// Sends message 0x21 to the linked clothing actor, if any.
void func_80800068_chfactoryworkerdirty(s32 *clothing, s32 sub_cmd, s32 value)
{
    s16 packed_value;
    s16 packed_cmd;

    if (*clothing != 0) {
        packed_cmd = sub_cmd;
        packed_value = value;
        func_8010114C(*clothing, 0x21, *(s32 *) &packed_cmd);
    }
}

void func_808000AC_chfactoryworkerdirty(actor, new_state) Actor *actor;
s32 new_state;
{
    u8 *state;
    state = func_80100094(actor, 0);
    switch (new_state) {
        case 3:
            func_8080000C_chfactoryworkerdirty(actor);
            func_801032B0(actor, 0x83B, actor->unk0->unk16);
            func_80102424(actor, 2);
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_80800F80_chfactoryworkerdirty);
            break;
        case 4:
            func_80800068_chfactoryworkerdirty(state, 1, 1);
            break;
        case 5:
            func_80800068_chfactoryworkerdirty(state, 1, 2);
            break;
        case 6:
            func_80800068_chfactoryworkerdirty(state, 1, 3);
            break;
        case 7:
        case 8:
            func_80102424(actor, 4);
            func_801032B0(actor, 0x803, actor->unk0->unk16);
            switch (state[0x10]) {
                case 6:
                    func_8080002C_chfactoryworkerdirty(actor);
                    *(f32 *) (state + 8) = 8.0f;
                    *(f32 *) (state + 0xC) = 0.0f;
                    func_80800AF8_chfactoryworkerdirty(actor);
                    actor->unk74_30 = 0;
                    break;
                case 1:
                    if (_glcutDll_entrypoint_20()) {
                        *(f32 *) (state + 8) = 8.0f;
                        *(f32 *) (state + 0xC) = 0.0f;
                    } else {
                        *(f32 *) (state + 8) = 0.0f;
                    }
                    actor->unk74_30 = 1;
                    func_801032B0(actor, 0x803, actor->unk0->unk16);
            }
    }
    state[0x10] = new_state;
}

s32 func_808009E4_chfactoryworkerdirty();

void func_8080025C_chfactoryworkerdirty(actor) Actor *actor;
{
    void *state;
    f32 pos[3];
    state = func_80100094(actor, 0);
    *(u8 *) ((char *) state + 0x10) = 1;
    *(s32 *) state = 0;
    if (func_808009E4_chfactoryworkerdirty() && func_80800A14_chfactoryworkerdirty(actor) &&
        _glcutDll_entrypoint_20() == 0 && func_800D0B68(0x36, 1) == 0) {
        func_800EEB9C(&pos, *(f32 **) ((char *) actor + 0x48), 0x42C80000);
        func_800EF04C(&pos, (f32 *) ((char *) actor + 4));
        func_800D1000(0x36, 1, &pos, 3, 0);
    }
    if (_glcutDll_entrypoint_20()) {
        func_808000AC_chfactoryworkerdirty(actor, 8);
    } else {
        if (func_80800AB4_chfactoryworkerdirty(actor)) {
            func_808000AC_chfactoryworkerdirty(actor, 7);
        }
    }
    *(f32 *) ((char *) actor + 0x54) = *(f32 *) ((char *) actor + 0x48);
}

void func_80800340_chfactoryworkerdirty(Actor *actor)
{
    func_80100094(actor, 0);
    func_80800DB4_chfactoryworkerdirty(actor);
}

void func_8080036C_chfactoryworkerdirty(s32 actor)
{
    _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_80800F90_chfactoryworkerdirty);
}

void func_80800C98_chfactoryworkerdirty();

void func_80800700_chfactoryworkerdirty();

void func_8080061C_chfactoryworkerdirty();

void func_80800394_chfactoryworkerdirty(Actor *actor)
{
    u8 *state;
    s32 whole_steps;
    u8 **pos_ref;
    u8 *pos;

    state = func_80100094(actor, 0);
    func_80800C98_chfactoryworkerdirty(actor);
    if ((u32) *(u16 *) ((u8 *) actor + 0x72) >> 10 == 2) {
        _subaddieaudioquick_entrypoint_3(actor, (u8 *) actor + 4,
                                         D_80800FA0_chfactoryworkerdirty, 0x3F000000);
        if (func_80101DDC(actor) != 0) {
            func_80102424(actor, 3);
        }
    }
    switch (state[0x10]) {
        case 1:
            pos = (u8 *) actor + 4;
            if (func_800C0638() == 0) {
                if (func_80101E14(actor, 0.13f) != 0 || func_80101E14(actor, 0.215f) != 0 ||
                    func_80101E14(actor, 0.27f) != 0 || func_80101E14(actor, 0.34f) != 0) {
                    func_8080036C_chfactoryworkerdirty(actor);
                }
                _subaddieaudioquick_entrypoint_3(actor, pos, D_80800FB0_chfactoryworkerdirty,
                                                 0x3ECCCCCD);
            }
            _sudeflect_entrypoint_1(pos, 120.0f, 0.0f, 70.0f, 0xA);
            func_8080061C_chfactoryworkerdirty(actor);
            return;

        case 2:
            _sudeflect_entrypoint_1((u8 *) actor + 4, 120.0f, 0.0f, 70.0f, 0xA);
            return;

        case 3:
            func_808000AC_chfactoryworkerdirty(actor, 4);
            return;

        case 7:
        case 8:
            pos = (u8 *) actor + 4;
            // Matching: extra pointer to pos needed for the match.
            pos_ref = &pos;
            if (func_800C0638() == 0 && func_80101E14(actor, 0.46f) != 0) {
                _subaddieaudioquick_entrypoint_2(actor, *pos_ref,
                                                 D_80800FC0_chfactoryworkerdirty);
            }
            if (*(f32 *) (state + 8) > 0) {
                *(f32 *) (state + 0xC) += func_800F10B4(*(f32 *) (state + 8), 0, 8.0f, 0, 5.0f);
                whole_steps = (s32) *(f32 *) (state + 0xC);
                func_800BBCB8(*pos_ref, 0, 1.0f, whole_steps, D_80800F40_chfactoryworkerdirty);
                *(f32 *) (state + 0xC) = *(f32 *) (state + 0xC) - (f32) whole_steps;
                func_800D9078(state + 8);
            }
            _sudeflect_entrypoint_1(*pos_ref, 120.0f, 0.0f, 70.0f, 0xA);
            func_80800994_chfactoryworkerdirty(actor);
            func_80800700_chfactoryworkerdirty(actor);
    }
}

void func_8080061C_chfactoryworkerdirty(u8 *actor)
{
    s32 *dialog;

    if (func_80090178(0x40) != 0) {
        dialog = &D_80800FD0_chfactoryworkerdirty;
        if (func_808009C0_chfactoryworkerdirty() != 0) {
            D_80800FD4_chfactoryworkerdirty[0] = D_80800FD6_chfactoryworkerdirty;
        }
        *(u8 *) ((s8 *) actor + 0x74) = (u8) (*(u8 *) ((s8 *) actor + 0x74) & 0xFFBF);
    } else {
        dialog = &D_80800FEC_chfactoryworkerdirty;
    }
    switch (_subaddiedialog_entrypoint_7(actor, actor + 4, dialog)) {
        case 0x134C:
            func_80090734(1, actor + 4);
            func_808000AC_chfactoryworkerdirty(actor, 2);
            return;
        case 0x134D:
            func_80090734(1, actor + 4);
            func_808000AC_chfactoryworkerdirty(actor, 2);
            return;
        default:
            func_80090734(1, actor + 4);
        case 0x0:
            return;
    }
}

void func_80800700_chfactoryworkerdirty(Actor *actor)
{
    if (func_808009E4_chfactoryworkerdirty())
        D_8080100C_chfactoryworkerdirty[0] = 0x1350;
    else if (func_80800A54_chfactoryworkerdirty() == 1)
        D_8080100C_chfactoryworkerdirty[0] = 0x134F;
    else
        D_8080100C_chfactoryworkerdirty[0] = 0x134E;
    if (_subaddiedialog_entrypoint_7(actor, actor->position, D_80801008_chfactoryworkerdirty)) {
        func_80090734(1, actor->position);
    }
}

void func_80800788_chfactoryworkerdirty(s32 *actor, s32 dialog_id, s32 param_2)
{
    switch (dialog_id) {
        // Matching: stray empty statement after the case label.
        case 0x134C:;
        case 0x134D:
            func_80090708(0);
            func_800904F4(0x65, *actor);
            return;
        case 0x1350:
            func_80800B40_chfactoryworkerdirty(actor);
            func_80090708(0);
            func_800D1000(0x36, 1, actor + 1, 0, 0);
            return;
        default:
            func_80090708(0);
    }
}

int func_80800828_chfactoryworkerdirty(s32 actor, s32 dialog_id, s32 param_2)
{
    if (dialog_id == 0x134E) {
        return func_80800A54_chfactoryworkerdirty();
    }
    return 0;
}

void func_80800864_chfactoryworkerdirty(Actor *actor)
{
    void *state;
    state = func_80100094(actor, 0);
    _subaddielink_entrypoint_1(state, func_801084B0(0x239, &actor)->unk0);
}

s32 func_80800D48_chfactoryworkerdirty();

// Actor message handler.
s32 func_808008A4_chfactoryworkerdirty(Actor *actor, s32 msg, DirtyWorkerEvent payload)
{
    switch (msg) {
        case 0x3D:
            func_80800864_chfactoryworkerdirty(actor);
            return 0;
        case 0x52:
            if (func_801022E4(actor) == 0x35E) {
                _gcdialogcamera_entrypoint_3(D_80801024_chfactoryworkerdirty, actor->scale);
            } else {
                _gcdialogcamera_entrypoint_3(D_80801034_chfactoryworkerdirty, actor->scale);
            }
            return 1;
        case 0x2E:
            func_80800788_chfactoryworkerdirty(actor, payload.local_1[0], payload.local_1[1]);
            return 1;
        case 0x30:
            return func_80800828_chfactoryworkerdirty(actor, payload.local_1[0],
                                                      payload.local_1[1]);
        case 0x29:
            func_80800D48_chfactoryworkerdirty(actor);
            return 1;
        case 0x2A:
            func_80800DB4_chfactoryworkerdirty(actor);
            return 1;
    }
    return 0;
}

int func_80800994_chfactoryworkerdirty(int actor)
{
    func_80102BF8(actor, 0x3E99999A, 0x40400000, 0x43960000);
}

s32 func_808009C0_chfactoryworkerdirty(void)
{
    func_800DA564(0x42D, 6);
}

// True when all six skivvies are washed (flag 0x433).
s32 func_808009E4_chfactoryworkerdirty()
{
    return func_800DA298(FLAG_433_UNK);
}

s32 func_80800A04_chfactoryworkerdirty(actor)
Actor *actor;
{
    return (((u16) *(u16 *) ((char *) actor + 0x76) & 0xFFFFFFFF) >> 7) - 0x32;
}

int func_80800A14_chfactoryworkerdirty(actor)
Actor *actor;
{
    s32 washed_count;
    s32 is_next;
    washed_count = func_800DA564(0x42D, 6);
    is_next = func_80800A04_chfactoryworkerdirty(actor) + 1 == washed_count;
    return is_next;
}

// Counts the skivvies that are not washed yet.
s32 func_80800A54_chfactoryworkerdirty(void)
{
    s32 i;
    s32 unwashed_count;
    s32 is_unwashed;

    unwashed_count = 0;
    i = 0;
    do {
        if (func_800DA298(i + 0x42D) == 0) {
            is_unwashed = 1;
        } else {
            is_unwashed = 0;
        }
        unwashed_count += is_unwashed;
        i++;
    } while (i != 6);
    return unwashed_count;
}

int func_80800AB4_chfactoryworkerdirty(actor)
s32 actor;
{
    return func_808009E4_chfactoryworkerdirty() != 0 ||
           func_800DA298(func_80800A04_chfactoryworkerdirty(actor) + 0x42D) != 0;
}

int func_80800AF8_chfactoryworkerdirty()
{
    s32 index;
    index = func_80800A04_chfactoryworkerdirty();
    func_800DA544(index + 0x42D);

if (func_800DA564(0x42D, 6) == 0x3F) {
    func_800DA544(0x433);
}

}

s32 func_80800B40_chfactoryworkerdirty(void)
{
    s32 index = func_80800A04_chfactoryworkerdirty();
    func_800DA7A8(0x42D, index + 1, 6);
}

void chfactoryworkerdirty_entrypoint_1(s32 handle, s32 cmd)
{
    s32 actor;

    actor = func_80106790(handle);

switch (cmd) {
    case 1:
        func_808000AC_chfactoryworkerdirty(actor, 3);
        return;
    case 2:
        func_808000AC_chfactoryworkerdirty(actor, 5);
        return;
    case 3:
        func_808000AC_chfactoryworkerdirty(actor, 6);
        return;
    case 4:
        func_808000AC_chfactoryworkerdirty(actor, 7);
}

}

void chfactoryworkerdirty_entrypoint_2(Unk80132ED0 *handle, s32 param_1, f32 param_2)
{
    Actor *actor = func_80106790(handle);
    void *state = func_80100094(actor, 0);
    func_80101010(param_1);
    func_8010105C(param_2);
    func_80800068_chfactoryworkerdirty(state, 3, 0);
}

void chfactoryworkerdirty_entrypoint_3(Unk80132ED0 *handle, f32 param_1)
{
    Actor *actor = func_80106790(handle);
    void *state = func_80100094(actor, 0);
    func_8010105C(param_1);
    func_80800068_chfactoryworkerdirty(state, 2, 0);

}

void func_80800C98_chfactoryworkerdirty(s32 *actor)
{
    if (func_80100094(actor, 1) != 0) {
        if (func_801022E4(actor) == 0x35D) {
            if (func_80102320(actor, 0x3ECCCCCD, 0x3F400000) != 0) {
                _suexpression_entrypoint_18(func_80100094(actor, 1), 1);
            }
        } else {
            _suexpression_entrypoint_18(func_80100094(actor, 1), 1);
        }
        _suexpression_entrypoint_10(func_80100094(actor, 1), *actor, 0);
    }

}

s32 func_80800D48_chfactoryworkerdirty(Actor *actor)
{
    if (!func_80100094(actor, 1)) {
        _suexpression_entrypoint_7(actor, 1, 0x8F);
        _suexpression_entrypoint_12(func_80100094(actor, 1), 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(func_80100094(actor, 1), 0x4B0);
    }

}

void func_80800DB4_chfactoryworkerdirty(Actor *actor)
{
    if (func_80100094(actor, 1)) {
        _suexpression_entrypoint_8(actor, 1);
    }

}

// TU-NOTE: the .data of this overlay is defined here in C; tables holding function pointers must be
// in the same unit, otherwise IDO's assembler schedules those functions differently.
// D_80800FD6_chfactoryworkerdirty is a label inside D_80800FD4_chfactoryworkerdirty, defined in
// undefined_syms.us.txt. The extern views of D_80800EF8, D_80800F90, D_80800FD4, D_80800FEC and
// D_8080100C are arrays (address-neutral).
u8 D_80800ED0_chfactoryworkerdirty[40] = {
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0xBC, 0xCC, 0xCD, 0x3,  0x5D,
    0x0, 0x1,  0x3F, 0xF3, 0x33, 0x33, 0x1,  0x23, 0x0,  0xA,  0x3D, 0xF5, 0xC2, 0x8F,
    0x1, 0x4B, 0x0,  0x1,  0x40, 0x2C, 0xCC, 0xCD, 0x3,  0x5E, 0x0,  0x1};
int D_80800EF8_chfactoryworkerdirty[18] = {0x27E0170,
                                           0x8020001,
                                           (u32) &D_80800ED0_chfactoryworkerdirty,
                                           (u32) func_80800394_chfactoryworkerdirty,
                                           (u32) func_80105834,
                                           (u32) func_80101870,
                                           0x7D00000,
                                           0x3F800000,
                                           0x0,
                                           0x40000120,
                                           (u32) func_80800340_chfactoryworkerdirty,
                                           0x0,
                                           0x140000,
                                           (u32) func_8080025C_chfactoryworkerdirty,
                                           (u32) func_80107C2C,
                                           -0x7FFFDBEE,
                                           (u32) func_808008A4_chfactoryworkerdirty,
                                           0x0};
u8 D_80800F40_chfactoryworkerdirty[64] = {
    0x0, 0x1D, 0x9, 0xEA, 0x0, 0x15, 0x0,  0x33, 0x0, 0x80, 0x0,  0xB,  0x0, 0x32, 0x0, 0x3C,
    0x0, 0x78, 0x0, 0x0,  0x0, 0x2C, 0xFF, 0xD8, 0x0, 0x50, 0xFF, 0xD8, 0x0, 0x28, 0x0, 0x78,
    0x0, 0x28, 0x0, 0x27, 0x0, 0x0,  0x0,  0xC8, 0x0, 0x0,  0x0,  0xFA, 0x0, 0x24, 0x0, 0x23,
    0x0, 0x23, 0x0, 0x25, 0x0, 0xA,  0x0,  0xA,  0x0, 0x2B, 0x0,  0x4C, 0x0, 0x4C, 0x0, 0x0};
u8 D_80800F80_chfactoryworkerdirty[16] = {0x0, 0x13, 0x4, 0xA2, 0x0, 0x16, 0x6D, 0x60,
                                          0x0, 0xA,  0x1, 0x80, 0x0, 0x0,  0x0,  0x0};
s32 D_80800F90_chfactoryworkerdirty[4] = {0x1305CA, 0x1655F0, 0xD00D9, 0xF30000};
u8 D_80800FA0_chfactoryworkerdirty[16] = {0x0, 0x13, 0x5, 0x5E, 0x0,  0xD,  0x1, 0x4C,
                                          0x1, 0x4C, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0};
u8 D_80800FB0_chfactoryworkerdirty[16] = {0x0, 0x13, 0x4, 0xE4, 0x0, 0x16, 0x55, 0xF0,
                                          0x0, 0xD,  0x1, 0x59, 0x1, 0x66, 0x0,  0x0};
u8 D_80800FC0_chfactoryworkerdirty[16] = {0x0, 0x13, 0x4, 0xE5, 0x0, 0x16, 0x55, 0xF0,
                                          0x0, 0xD,  0x1, 0x59, 0x1, 0x66, 0x0,  0x0};
s32 D_80800FD0_chfactoryworkerdirty = 0xE6;
u16 D_80800FD4_chfactoryworkerdirty[12] = {0x134C, 0x134D, 0x0, 0x40,   0x0, 0x0,
                                           0x8F,   0x0,    0x6, 0x4732, 0x0, 0x0};
s32 D_80800FEC_chfactoryworkerdirty[7] = {0x42C00E6, 0x134A134B, -0x1, 0x0, 0x8F0000, 0x60732, 0x0};
u8 D_80801008_chfactoryworkerdirty[4] = {0x0, 0x0, 0x0, 0xE6};
s16 D_8080100C_chfactoryworkerdirty[12] = {0x0,  0x1351, 0x0, 0x40,   0x1351, 0x0,
                                           0x8E, 0x0,    0x6, 0x4732, 0x0,    0x0};
f32 D_80801024_chfactoryworkerdirty[4] = {1.8e+02f, 1e+02f, 1e+02f, 3e+01f};
f32 D_80801034_chfactoryworkerdirty[7] = {1.5e+02f, 1e+02f, 1e+02f, 3e+01f, 0.0f, 0.0f, 0.0f};
