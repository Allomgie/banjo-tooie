#include "common.h"

extern int D_808010E8_chnastycavemen[];
extern s32 func_80090178(s32);
extern s32 _plsu_entrypoint_1(s32);
extern s32 func_800F640C(s32, s32);
extern s32 func_800F54E4(void);
extern s32 func_8008FE14(void);
typedef struct {
    f32 start_pos[3];
    f32 start_rot[3];
    f32 walk_pos[3];
    f32 walk_rot[3];
} CavemanMovementSnapshots;
extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern int D_80127194[];
extern void func_80105A9C(Actor *, f32);
extern void func_80108A30(s32, f32 *, f32, s32);
typedef struct {
    u32 pad : 1;
    u32 flag : 1;
    u32 pad2 : 30;
} BitTest1;
typedef struct {
    u32 pad : 2;
    u32 flag : 1;
    u32 pad2 : 29;
} BitTest2;
typedef struct {
    u32 pad : 15;
    u32 flag : 1;
    u32 pad2 : 16;
} BitTest15;
extern int D_808011BC_chnastycavemen[];
extern u8 D_80801204_chnastycavemen[];
extern s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, void *, s32);
extern f32 func_800F1DCC(f32, f32);
extern void _subaddiedialog_entrypoint_11();
extern void _suexpression_entrypoint_10();
extern void func_80102424();
extern void func_80105230();
extern void func_80105834();
extern void func_80105BAC();
extern void func_801017D0(void);
extern void func_8010573C(Actor *, f32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern s32 D_80801130_chnastycavemen[];
extern void func_800EF334(f32 *, f32);
extern void func_800E0C20(s32, s32, f32, f32, f32, f32);
extern void func_800E0AFC(s32, s32, f32, f32, f32, f32);
extern int func_8008FB10(f32[3], f32, f32, f32);
extern int func_800902E4(f32[3], f32, s32, Actor **);
extern int _subaddieaudioquick_entrypoint_3(Actor *, f32[3], void *, f32);
extern int func_80101E14(Actor *, f32);
extern int _chbadshad_entrypoint_1(Actor *, f32[3], f32);
extern u8 D_80801138_chnastycavemen[];
extern u8 D_80801144_chnastycavemen[];
extern u8 D_80801150_chnastycavemen[];
extern u8 D_80801158_chnastycavemen[];
extern u8 D_80801164_chnastycavemen[];
extern u8 D_80801174_chnastycavemen[];
extern u8 D_8080117C_chnastycavemen[];
extern u8 D_8080118C_chnastycavemen[];

int chnastycavemen_entrypoint_0()
{
    return (int) &D_808010E8_chnastycavemen;
}

int func_8080000C_chnastycavemen(void)
{
    return func_80090178(0x10000) != 0 && _plsu_entrypoint_1(1) == -1 &&
           _plsu_entrypoint_1(0xB) == -1;
}

int func_80800060_chnastycavemen(void)
{
    return func_8008FE14() == 0x1D9 || func_800F640C(func_800F54E4(), 0x1D9) != 0;
}

// Maps the stored level byte to the warp target (map id, entry).
s32 func_808000AC_chnastycavemen(s32 slot, s32 *out_map, s32 *out_entry)
{
    switch (slot) {
        default:
        case 1:
            *out_map = 0xC5;
            *out_entry = 3;
            break;
        case 2:
            *out_map = 0x112;
            *out_entry = 5;
            break;
        case 5:
            *out_map = 0x112;
            *out_entry = 0xD;
    }
    return 1;
}

s32 func_8080010C_chnastycavemen(s32 unk_0)
{
    s32 map_id;
    s32 entry;
    s32 temp_v0;

    if (func_80800060_chnastycavemen() != 0) {
        func_800900D0(0x1D9);
    }
    temp_v0 = func_8008FD48();
    switch (temp_v0) {
        case 0xA:
        case 0xB:
            func_800904C8(0x97);
        case 0x11:
            break;
        default:
            func_808000AC_chnastycavemen(*(s16 *) ((s8 *) (s16 *) D_80127194 + 0x436), &map_id,
                                         &entry);
            _gcgoto_entrypoint_1(map_id, entry);
    }
    return 1;
}

int func_80800194_chnastycavemen(s32 unk_0, s32 player)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = !func_800F64A4(player, 0x10000);
    local_1 = func_800F651C(player);
    local_2 = func_800F6C5C(player);
    local_3 = func_800F72DC(player);
    local_4 = func_800F56AC(player) == 0x10;
    return func_800F6478(player) && local_0 && local_4 && (local_3 || (local_2 && !local_1));
}

// Switches the caveman to a new state and starts its sound or dialog.
void func_80800268_chnastycavemen(actor, state, cutscene) Actor *actor;
s32 state;
s32 cutscene;
{
    s32 dialog_id;
    f32 *snapshots;
    if (state != actor->unk70_10) {
        switch (state) {
            case 2:
                if (cutscene) {
                    _capod_entrypoint_13(actor->unk0, 0, 5, 0x2830);
                } else {
                    _capod_entrypoint_13(actor->unk0, 0, 1, 0x30);
                }
                break;
            case 4:
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 &D_80801130_chnastycavemen);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17EE, 8, actor->position, 0x96);
                break;
            case 3:
                if (func_8008FD48() == 0xB) {
                    dialog_id = 0x1805;
                } else {
                    dialog_id = func_80800060_chnastycavemen() ? 0x17DB : 0x17DA;
                }
                _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, 0x6C, actor->position,
                                              0x96);
                break;
            case 5:
                snapshots = func_80100094(actor, 0);
                func_800EE7F8(snapshots, actor->position);
                func_800EE7F8(snapshots + 3, actor->rotation);
                func_800EE7F8(snapshots + 6, snapshots);
                func_800EE7F8(snapshots + 9, snapshots + 3);
                break;
            case 6:
                actor->unk64_20 = 1;
        }
        func_80102424(actor, state);
    }
}

void func_808003FC_chnastycavemen(Actor *actor)
{
    CavemanMovementSnapshots *snapshots;

    snapshots = func_80100094(actor, 0);
    func_800EE7F8(actor->position, snapshots->walk_pos);
    func_800EE7F8(actor->rotation, snapshots->walk_rot);
    func_80105BAC(actor);
    func_80105230(actor, 0);
    func_80105834(actor);
    func_800EE7F8(snapshots->walk_pos, actor->position);
    func_800EE7F8(snapshots->walk_rot, actor->rotation);
    func_800EE7F8(actor->position, snapshots->start_pos);
    func_800EE7F8(actor->rotation, snapshots->start_rot);
    if (func_80105A5C(actor)) {
        func_80800268_chnastycavemen(actor, 6, 1);
        _glcutDll_entrypoint_17();
    }
}

void func_808004C4_chnastycavemen(Actor *actor)
{
    s32 pad0;
    f32 diff[3];
    u8 *data;
    int unk_2;
    if ((s32) actor->unk70_10 < 5 || *(s16 *) ((u8 *) actor->unk0 + 0x10) == 0) {
        return;
    }
    data = func_80100094(actor, 0);
    unk_2 = func_8010262C(actor->unk0, 6);
    func_800EFB24(diff, data + 0x18, actor->position);
    func_800EF334(diff, 0.1f);
    func_800E0C20(unk_2, 3, 1.0f, diff[0], diff[1], diff[2]);
    diff[0] = func_800F1DCC(*(f32 *) (data + 0x24), actor->rotation[0]);
    diff[1] = func_800F1DCC(*(f32 *) (data + 0x28), actor->rotation[1]);
    diff[2] = func_800F1DCC(*(f32 *) (data + 0x2C), actor->rotation[2]);
    func_800E0AFC(unk_2, 3, 1.0f, diff[0], diff[1], diff[2]);
    func_800E0C20(unk_2, 0x56, -1.0f, -1.65625f, 20.34375f, -7.125f);
    func_800E0AFC(unk_2, 0x56, -1.0f, 10.59375f, 91.59375f, 0.0f);
    func_800E0C20(unk_2, 0x5A, -1.0f, -3.90625f, -13.9375f, 27.56324959f);
    func_800E0AFC(unk_2, 0x5A, -1.0f, -91.203125f, -15.09375f, 13.09375f);
}

void func_8080067C_chnastycavemen(Actor *actor)
{
    u8 *data;
    s32 cutscene;

    data = func_80100094(actor, 0);
    cutscene = _glcutDll_entrypoint_19(0x34);
    if (actor->unk70_10 != 6) {
        func_8008FB10(actor->position, 150.0f, 0.0f, 100.0f);
        if (func_800F55FC(func_800F54E4()) & 0x08000000) {
            func_800902E4(actor->position, -1.0f, 0x1D9, &actor);
        }
    }
    switch (actor->unk70_10) {
        case 1:
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801138_chnastycavemen,
                                             0.6f);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801144_chnastycavemen,
                                             0.05f);
            if (func_80800194_chnastycavemen(actor, func_800F54E4())) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80801150_chnastycavemen);
                func_80800268_chnastycavemen(actor, 2, 0);
            }
            break;
        case 2:
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801158_chnastycavemen,
                                             0.01f);
            if (func_80101DDC(actor)) {
                func_80800268_chnastycavemen(actor, cutscene ? 4 : 3, cutscene);
            }
            break;
        case 3:
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80801174_chnastycavemen,
                                             D_80801164_chnastycavemen);
            if (actor->unk74_30 && actor->unk74_29) {
                if (!func_8080010C_chnastycavemen(actor)) {
                    _capod_entrypoint_14();
                }
                actor->unk74_29 = 0;
                actor->unk74_30 = actor->unk74_29;
            }
            break;
        case 4:
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_8080118C_chnastycavemen,
                                             D_8080117C_chnastycavemen);
            if (func_80101E14(actor, 0.03669999912f)) {
                actor->unk64_20 = 1;
            }
            if (func_80101DDC(actor)) {
                func_80800268_chnastycavemen(actor, 5, cutscene);
            }
            break;
        case 5:
            func_808003FC_chnastycavemen(actor);
            break;
        case 6:
            actor->position[1] = -5000.0f;
    }
    func_808004C4_chnastycavemen(actor);
    if (actor->unk70_10 == 5) {
        _chbadshad_entrypoint_1(actor, (f32 *) (data + 0x18), 1.0f);
    } else if (actor->unk70_10 != 6) {
        _chbadshad_entrypoint_1(actor, actor->position, 1.0f);
    }
}

void func_80800968_chnastycavemen(void)
{
    s32 temp_v0;

    temp_v0 = func_800EA090();
    if ((*(s16 *) ((s8 *) &D_80127194 + 0x436) == 0) ||
        ((temp_v0 != 0) && (func_80090178(0x10000) == 0))) {
        *(s16 *) ((s8 *) &D_80127194 + 0x436) = (s16) temp_v0;
    }
}

s32 func_808009BC_chnastycavemen(Actor *actor, s32 msg, s32 unk_2)
{
    s32 cutscene;
    u8 *cube;

    switch (msg) {
        case 0x95:
            cutscene = _glcutDll_entrypoint_19(0x34);
            func_80800968_chnastycavemen();
            func_80105A9C(actor, 440.0f);
            ((BitTest15 *) ((u8 *) actor + 0x94))->flag = 1;
            if (cutscene == 0) {
                if (func_800DA298(0x5A)) {
                    func_800FFA88(actor->unk0);
                } else if (!func_800F640C(func_800F54E4(), 0x1D9)) {
                    cube = (u8 *) _gccubesearch_entrypoint_1(0x1C0, actor->position);
                    _gspropctrl_entrypoint_11(cube, (f32 *) actor->actorData);
                    func_80108A30(0x1D9, (f32 *) actor->actorData,
                                  (f32) (*(u32 *) (cube + 12) >> 23), 0);
                }
            } else {
                func_80800268_chnastycavemen(actor, 2, cutscene);
            }
            break;
        case 0xB:
            ((BitTest2 *) ((u8 *) actor + 0x74))->flag = 1;
            return 3;
        case 0x2E:
            ((BitTest1 *) ((u8 *) actor + 0x74))->flag = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800B10_chnastycavemen(Actor *actor, s32 unk_1)
{
    func_800DF3E0();
    func_800DF744(5, 2);
    func_800DF744(6, 2);
    func_800DF744(8, 1);
    func_800DF744(4, actor->unk64_20 ? 0 : 2);
    func_800DF744(7, actor->unk64_20 ? 2 : 0);
    if (actor->unk70_10 == 5)
        func_800DF440(0);
    func_80101870(actor, unk_1);
}

int chnastycavemen_entrypoint_1()
{
    return (int) &D_808011BC_chnastycavemen;
}

void func_80800BE0_chnastycavemen(Actor *actor)
{
    void *expression;
    f32 anim_t;
    s32 dialog_id;
    expression = func_80100094(actor, 1);
    _sudeflect_entrypoint_1(actor->position, actor->scale * 300.0f, 0.0f,
                            actor->scale * 150.0f, 14);
    _suexpression_entrypoint_10(expression, actor->unk0, 0);
    switch (actor->unk70_10) {
        case 1:
            if (func_8010C9FC(actor->position, 400, 400, -200) && !func_80090178(0x10000)) {
                s32 text_id;
                if (func_80800060_chnastycavemen()) {
                    text_id = 0x17EF;
                } else if (func_8008FF6C() == 0xF) {
                    text_id = 0x17F0;
                } else {
                    text_id = 0x17F1;
                }
                _subaddiedialog_entrypoint_11(actor->unk0, text_id, 10, actor->position, 150);
                func_80102424(actor, 2);
            }
        case 2:
            break;
        case 3:
            anim_t = func_80101F24(actor);
            func_80105A9C(actor, func_800F3780(anim_t, D_80801204_chnastycavemen, 5) *
                                       (150.0f * actor->scale));
            func_80105BAC(actor);
            func_80105834(actor);
            func_80105230(actor, 0);
            actor->rotation[1] = func_800F1DCC(actor->rotation[1], 180.0f);
            if (func_80105A5C(actor)) {
                func_80090708(0);
                func_80102424(actor, 4);
            }
            break;
        case 4:
            if (func_8010C9FC(actor->position, 600, 400, -200) && !func_80090178(0x10000)) {
                dialog_id = 0;
                if (func_80800060_chnastycavemen()) {
                    dialog_id = 0x17EF;
                } else if (func_8008FF6C() == 0xF) {
                    dialog_id = 0x17F0;
                } else if (_subaddiedialog_entrypoint_5(actor->position, 400, 45, 0)) {
                    dialog_id = 0x1804;
                }
                if (dialog_id) {
                    _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, 10, actor->position,
                                                  150);
                    func_80102424(actor, 2);
                }
            }
    }
}

void func_80800E68_chnastycavemen(s32 actor, s32 unk_1)
{
    func_80101808(actor, &func_801017D0);
}

int func_80800E90_chnastycavemen(Actor *actor, s32 msg, s32 msg_arg)
{
    void *expression;
    s32 dialog_id;
    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }
    switch (msg) {
        case 0x95:
            func_80100094(actor, 1);
            func_80800968_chnastycavemen();
            if (func_8080000C_chnastycavemen()) {
                func_80102424(actor, 1);
            } else if (func_800DA298(0x184)) {
                func_8010573C(actor, 1.0f);
                actor->rotation[1] = func_800F1DCC(actor->rotation[1], 180.0f);
                func_80102424(actor, 4);
            } else if (func_800EA090() == 5) {
                func_80102424(actor, 1);
            }
            _suexpression_entrypoint_7(actor, 1, 150);
            expression = func_80100094(actor, 1);
            _suexpression_entrypoint_12(expression, 60.0f, 15.0f);
            _suexpression_entrypoint_17(expression, 800);
            break;
        case 0x2E:
            dialog_id = ((s16 *) &msg_arg)[0];
            if (dialog_id == 0x17EF || dialog_id == 0x17F0) {
                func_8080010C_chnastycavemen(actor);
            } else {
                func_80090708(2);
                func_80102424(actor, 3);
            }
            break;
        case 0x1F:
            func_801015D0(actor);
            func_800DF3E0();
            func_800DF744(5, 2);
            func_800DF744(6, 2);
            func_800DF744(8, 2);
            func_800DF744(4, 3);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_8080103C_chnastycavemen(s32 expression)
{
    s32 result;

    result = _suexpression_entrypoint_8(expression, 1);
}

extern void func_80102EC0();
extern void func_80107C2C();
u32 D_808010B0_chnastycavemen[14] = {0x0,        0x0,        0x40466666, 0x2F10001,  0x4019999A,
                                     0x2F20002,  0x40533333, 0x2F30001,  0x40600000, 0x2F40002,
                                     0x3F28F5C3, 0x2F00001,  0x40600000, 0x2F40001};
int D_808010E8_chnastycavemen[18] = {0x1DE01DA,
                                     0x7EE0001,
                                     (u32) &D_808010B0_chnastycavemen,
                                     (u32) func_80102EC0,
                                     (u32) func_8080067C_chnastycavemen,
                                     (u32) func_80800B10_chnastycavemen,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x40420,
                                     0x0,
                                     0x0,
                                     0x580000,
                                     0x0,
                                     (u32) func_80107C2C,
                                     -0x7BFFABEE,
                                     (u32) func_808009BC_chnastycavemen,
                                     0x0};
s32 D_80801130_chnastycavemen[2] = {0x1305B6, 0x0};
u8 D_80801138_chnastycavemen[12] = {0x0, 0x13, 0x5, 0xC6, 0x0, 0xD, 0x0, 0xCC, 0x0, 0xD9, 0x0, 0x0};
u8 D_80801144_chnastycavemen[12] = {0x0, 0x13, 0x5, 0xC7, 0x0, 0xD, 0x0, 0xCC, 0x0, 0xD9, 0x0, 0x0};
u8 D_80801150_chnastycavemen[8] = {0x0, 0x13, 0x4, 0xAA, 0x0, 0x0, 0x0, 0x0};
u8 D_80801158_chnastycavemen[12] = {0x0, 0x13, 0x5, 0xCE, 0x0, 0xA, 0x0, 0xE6, 0x0, 0x0, 0x0, 0x0};
u8 D_80801164_chnastycavemen[16] = {0x3F, 0x19, 0x99, 0x9A, 0x3F, 0x3D, 0x70, 0xA4,
                                    0x3F, 0x61, 0x47, 0xAE, 0xBF, 0x80, 0x0,  0x0};
u8 D_80801174_chnastycavemen[8] = {0x0, 0x13, 0x4, 0x17, 0x0, 0x0, 0x0, 0x0};
u8 D_8080117C_chnastycavemen[16] = {0x3E, 0x74, 0x39, 0x58, 0x3E, 0xB7, 0x4B, 0xC7,
                                    0x3E, 0xCA, 0x9,  0x3,  0xBF, 0x80, 0x0,  0x0};
u8 D_8080118C_chnastycavemen[8] = {0x0, 0x13, 0x4, 0x17, 0x0, 0x0, 0x0, 0x0};
u32 D_80801194_chnastycavemen[10] = {0x0,       0x0,        0x406CCCCD, 0x2F50000,  0x406CCCCD,
                                     0x2F50000, 0x3F222222, 0x2F60000,  0x406CCCCD, 0x2F50000};
int D_808011BC_chnastycavemen[18] = {0x15801DB,
                                     0x7EE0001,
                                     (u32) &D_80801194_chnastycavemen,
                                     (u32) func_80102EC0,
                                     (u32) func_80800BE0_chnastycavemen,
                                     (u32) func_80800E68_chnastycavemen,
                                     0xBB80000,
                                     0x3F800000,
                                     0x0,
                                     0x40020,
                                     (u32) func_8080103C_chnastycavemen,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80107C2C,
                                     -0x7FFFBBEE,
                                     (u32) func_80800E90_chnastycavemen,
                                     0x0};
u8 D_80801204_chnastycavemen[44] = {0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x3E, 0x80, 0x0,
                                    0x0,  0x3F, 0x80, 0x0,  0x0, 0x3F, 0x0,  0x0,  0x0,  0x0,  0x0,
                                    0x0,  0x0,  0x3F, 0x40, 0x0, 0x0,  0x3F, 0x80, 0x0,  0x0,  0x3F,
                                    0x80, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
