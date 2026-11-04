#include "ch/heggy.h"

extern s32 D_80801E08_chheggy[];
extern s32 D_80801E38_chheggy[];
extern s32 D_80801E60_chheggy[];
extern u32 D_80801E8C_chheggy[];
extern s32 D_80801E9C_chheggy[];
extern s32 D_80801EE4_chheggy[14];
extern s32 D_80801F1C_chheggy[15];
extern s32 D_80801F58_chheggy[];

extern void *func_8010D5DC;

typedef struct Unk80100094 {
    Vec3f unk0[1];
    u8 padC[0x3C - 0xC];
    Vec3f unk3C;
    s32 unk48[7];
    f32 unk64[3];
    f32 unk70[3];
} Unk80100094;

void func_80800ECC_chheggy(Actor *, s32);

void func_80800000_chheggy(Actor *actor, Unk80100094 *path_data, s32 index)
{
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F904(&func_8010D5DC, actor->unk0);
    func_8008F938(1);
    func_8008F990(path_data->unk0[index].f, 500.0f);
}

// Number of eggs the player has handed over.
s32 func_8080006C_chheggy(void)
{
    return (func_800DA298(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE) != 0 ? 1 : 0) +
           (func_800DA298(FLAG_3E5_SNS_EGG_ACQUIRED_PINK) != 0 ? 1 : 0);
}

// Walks along the current spline; returns nonzero when finished.
s32 func_808000C0_chheggy(Actor *actor)
{
    f32 saved_yaw;

    saved_yaw = actor->rotation[1];
    func_80105A9C(actor, func_800F3780(func_80101F24(actor), D_80801E08_chheggy, 6) * 500.0f);
    func_80105834(actor);
    actor->unk54 = actor->rotation[1];
    actor->rotation[1] = saved_yaw;
    func_80102BAC(actor, 0.1f, 0.1f, 6.0f);
    return func_80105A5C(actor);
}

// Footstep and effect sounds keyed to the animation frame.
void func_8080015C_chheggy(Actor *actor)
{
    f32 emit_pos[3];
    s32 has_emit;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 emitter_a;
    s32 emitter_b;
    f32 vec_a[3];
    f32 vec_b[3];

    has_emit = 0;
    unk_0 = 0;
    unk_1 = 0;
    unk_2 = 0;
    switch (func_801022E4(actor)) {
        case 0x4A5:
            unk_2 = func_80101E14(actor, 0.0f) != 0 || func_80101E14(actor, 0.8f) != 0;
            unk_1 = func_80101E14(actor, 0.35f);
            unk_0 = func_80101E14(actor, 0.45f) != 0 || func_80101E14(actor, 0.5f) != 0 ||
                   func_80101E14(actor, 0.56f) != 0;
            break;
        case 0x4A7:
            unk_0 = func_80101E14(actor, 0.4f) != 0 || func_80101E14(actor, 0.9f) != 0;
            if (func_80101E14(actor, 0.0f) != 0) {
                _subaddieskeleton_entrypoint_0(actor, 0x2F, emit_pos);
                has_emit = 1;
            } else if (func_80101E14(actor, 0.5f) != 0) {
                _subaddieskeleton_entrypoint_0(actor, 0x2C, emit_pos);
                has_emit = 1;
            }
            break;
        case 0x4A6:
            unk_2 = func_80101E14(actor, 0.07f);
            unk_1 = func_80101E14(actor, 0.88f);
            unk_0 = func_80101E14(actor, 0.46f) != 0 || func_80101E14(actor, 0.54f) != 0 ||
                   func_80101E14(actor, 0.6f) != 0;
            if (func_80101E14(actor, 0.035f) != 0) {
                func_800EE7F8(emit_pos, actor->position);
                has_emit = 1;
            } else if (func_80101E14(actor, 0.92f) != 0) {
                func_800EE7F8(emit_pos, actor->position);
                has_emit = 1;
            }
    }
    if (has_emit != 0) {
        emitter_a = func_800B53A4(2);
        emitter_b = func_800B53A4(3);
        func_800EEC30(vec_a, 10.0f, actor->rotation[1] - 180.0f, 50.0f);
        func_800EEC30(vec_b, 25.0f, actor->rotation[1] - 180.0f, 150.0f);
        func_800BA930(emitter_a, (s16) vec_a[0], (s16) vec_a[1], (s16) vec_a[2], vec_b[0], vec_b[1], vec_b[2]);
        func_800BA930(emitter_b, (s16) vec_a[0], (s16) vec_a[1], (s16) vec_a[2], vec_b[0], vec_b[1], vec_b[2]);
        func_800EF334(vec_a, -0.5f);
        func_800EF334(vec_b, -0.5f);
        func_800BA450(emitter_a, (s16) vec_a[0], -0xC8, (s16) vec_a[2], vec_b[0], -0x190, vec_b[2]);
        func_800BA450(emitter_b, (s16) vec_a[0], -0xC8, (s16) vec_a[2], vec_b[0], -0x190, vec_b[2]);
        func_800BABB8(emitter_a, emit_pos, NULL, 1.0f, D_80801E38_chheggy);
        func_800BA22C(emitter_a, 2);
        func_800BABB8(emitter_b, emit_pos, NULL, 1.0f, D_80801E60_chheggy);
        func_800BA22C(emitter_b, 3);
        func_800C4140(0xA62FA404, actor->position, 0x0FA00064);
    }
    if (func_800C0638() == 0) {
        if (unk_0 != 0) {
            func_800C4140(((func_800DC0C0() < 0.5f) ? 0x674 : 0x675) + 0x7FEBB800, actor->position,
                          0x0FA00064);
        }
        if (unk_1 != 0) {
            func_800C4140(0x7FEBBE76, actor->position, 0x0FA00064);
        }
        if (unk_2 != 0) {
            func_800C4140(0x7FEBBE77, actor->position, 0x0FA00064);
        }
    }
}

void func_808006C4_chheggy(Actor *actor, Unk80132ED0 *arg1, s32 arg2, s32 arg3)
{
    switch (actor->actorData[4]) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 0x28U, 0);
        case 1:
            actor->actorData[4] = 2;
        case 3:
            actor->actorData[4] = 2;
        case 2:
            _capod_entrypoint_6(arg1, arg2, arg3);
    }
}

void func_80800750_chheggy(Actor *actor, Unk80132ED0 *arg1, s32 arg2, s32 arg3)
{
    switch (actor->actorData[4]) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 0x28U, 0);
        case 1:
        case 2:
            actor->actorData[4] = 3;
        case 3:
            _capod_entrypoint_20(arg1, arg2, arg3);
    }
}

void func_808007D4_chheggy(Actor *actor, s32 arg1, s32 arg2)
{
    switch (actor->actorData[4]) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 0x28U, 0);
        case 2:
        case 3:
            actor->actorData[4] = 1;
            _capod_entrypoint_8(1);
            arg1 = 2;
            arg2 = 1;
            _gcdialogcamera_entrypoint_6(actor->unk0);
            _gcdialogcamera_entrypoint_8();
        case 1:
            _capod_entrypoint_7(arg1, arg2);
    }
}

void func_8080087C_chheggy(Actor *actor)
{
    if ((actor->actorData[4] != 0) && (func_800DA298(FLAG2_64B_UNK) != 0)) {
        _capod_entrypoint_3(0);
        actor->actorData[4] = 0;
    }
}

void func_808008C4_chheggy(Actor *actor)
{
    Prop *path_props[10];
    s32 pad[2];
    s32 i;
    s32 path_index;
    Unk80100094 *path_data;
    s32 num_found;
    f32 spline_pos;

    path_data = func_80100094(actor, 0);
    num_found = _gccubesearch_entrypoint_9(0x299, path_props, 6);
    for (i = 0; i < num_found; i++) {
        _gspropctrl_entrypoint_11(
            path_props[i],
            &path_data->unk0[_gspropctrl_entrypoint_8(path_props[i]) - 50]);
    }
    num_found = _gccubesearch_entrypoint_9(0x511, path_props, 5);
    for (i = 0; i < num_found; i++) {
        path_index = _gspropctrl_entrypoint_8(path_props[i]) - 0x32;
        _gspropctrl_entrypoint_11(path_props[i], &spline_pos);
        path_data->unk48[path_index] = _glsplinefind_entrypoint_3(&spline_pos);
    }
    func_800EE7F8(&path_data->unk3C, actor->position);
}

// Per-frame update: egg-handling state machine.
void func_808009DC_chheggy(Actor *actor)
{
    void *aux_data;
    Unk80100094 *path_data;
    Actor *egg;
    Unk80100094 *walk_data;
    f32 walk_t;
    Unk80100094 *carry_data;
    f32 carry_t;
    u32 dialog_id;

    switch (actor->unk70_10) {
        case 7:
            if (func_800D90A4(&actor->unk58) != 0) {
                func_80800ECC_chheggy(actor, 8);
            }
            break;

        case 8:
            aux_data = func_80100094(actor, 1U);
            path_data = func_80100094(actor, 0U);
            egg = _subaddiefind_entrypoint_2(actor->actorData[7], 0);
            if (egg != NULL) {
                if (actor->unk3C != NULL) {
                    func_80106790(actor->unk3C)->rotation[1] = egg->rotation[1];
                }
            }
            if (_subaddieitem_entrypoint_3(actor, path_data->unk0[actor->actorData[7] == 0x515 ? 3 : 4].f,
                                           aux_data) != 0) {
                if (actor->actorData[7] == 0x515) {
                    func_800DA524(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE);
                    actor->unk64_20 = 1;
                    if (func_800DA298(FLAG_3E5_SNS_EGG_ACQUIRED_PINK) != 0) {
                        func_80800ECC_chheggy(actor, 6);
                    } else {
                        func_80800ECC_chheggy(actor, 9);
                    }
                } else {
                    func_800DA524(FLAG_3E5_SNS_EGG_ACQUIRED_PINK);
                    actor->unk64_19 = 1;
                    func_80800ECC_chheggy(actor, 9);
                }
            }
            break;
        case 10:
            if (func_800D90A4(&actor->unk58) != 0) {
                func_80800ECC_chheggy(actor, 0xB);
            }
            break;
        case 12:

            if (func_808000C0_chheggy(actor) != 0) {
                func_80800ECC_chheggy(actor, 0xD);
            }
            break;
        case 13:
            walk_data = func_80100094(actor, 0U);
            walk_t = func_80101F24(actor);
            if (walk_t < 0.035f) {
                walk_t = 0.0f;
            } else if (walk_t <= 0.16f) {
                walk_t = func_800F10B4(func_80101F24(actor), 0.035f, 0.16f, 0.0f, 1.0f);
            } else {
                walk_t = 1.0f;
                func_80800ECC_chheggy(actor, 0xE);
            }
            func_800EFE50(actor->position, (u8 *) walk_data + 0x64, (u8 *) walk_data + 0x70, walk_t);
            break;
        case 14:
            if (func_80101E14(actor, 0.84f) != 0) {
                func_80800ECC_chheggy(actor, 0xF);
            }
            break;
        case 15:
            carry_data = func_80100094(actor, 0U);
            if (func_80101F24(actor) <= 0.92f) {
                carry_t = func_800F10B4(func_80101F24(actor), 0.84f, 0.92f, 0.0f, 1.0f);
            } else {
                carry_t = 1.0f;
                func_80800ECC_chheggy(actor, 0x10);
            }
            func_800EFE50(actor->position, (u8 *) carry_data + 0x64, (u8 *) carry_data + 0x70, carry_t);
            func_800D1804(0x52);
            break;
        case 16:
            if (func_800D90A4(&actor->unk58) != 0) {
                func_80800ECC_chheggy(actor, 0x11);
            }
            func_80102BAC(actor, 0.2f, 0.1f, 8.0f);
            break;
        case 18:
            if (func_808000C0_chheggy(actor) != 0) {
                func_80800ECC_chheggy(actor, 0x13);
            }
            break;
        case 19:
            _sudeflect_entrypoint_1(actor->position, func_80103EF4(actor), 0.0f,
                                    func_80103EAC(actor) * 0.8f, 0xE);
            if (_subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1], 0x258U, 0x3CU,
                                             0) != 0) {
                if ((func_800DA298(FLAG_3E4_SNS_EGG_HATCHED_BLUE) == 0) &&
                    (func_800DA298(FLAG_3E6_SNS_EGG_HATCHED_PINK) == 0)) {
                    dialog_id = 0x1546;
                } else if ((func_800DA298(FLAG_3E4_SNS_EGG_HATCHED_BLUE) != 0) &&
                           (func_800DA298(FLAG_3E6_SNS_EGG_HATCHED_PINK) != 0)) {
                    if (func_800DA298(FLAG_3E7_SNS_EGG_HATCHED_YELLOW) != 0) {
                        dialog_id = 0x1549;
                    } else {
                        dialog_id = 0x1548;
                    }
                } else {
                    dialog_id = 0x1547;
                }
                _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, 0xEU, actor->position, 0xCBU);
            }
        case 3:
        case 20:
            break;
    }
    func_8080015C_chheggy(actor);
    if (((func_800DA298(FLAG_3E4_SNS_EGG_HATCHED_BLUE) == 0) ||
         (func_800DA298(FLAG_3E6_SNS_EGG_HATCHED_PINK) == 0)) &&
        (_glcutDll_entrypoint_20() == 0)) {
        func_800D1824(0x52);
    }
}

// Enters a new state and runs its entry action.
void func_80800ECC_chheggy(Actor *actor, s32 state)
{
    Unk80100094 *path_data;
    Unk80132ED0 **egg_ref;

    s32 item_handle;

    path_data = func_80100094(actor, 0U);
    if (actor->unk70_10 == 8) {
        egg_ref = _subaddiefind_entrypoint_2(actor->actorData[7], 0);
        if (egg_ref != NULL) {
            func_800FFA88(*egg_ref);
        }
        func_80106790(actor->unk3C)->unk64_16 = 1;
    }
    switch (state) {
        case 1:
            func_80800000_chheggy(actor, func_80100094(actor, 0U), 0);
            func_800DA544(FLAG_3E8_FTT_IoH_HEGGY);
            func_80800750_chheggy(actor, actor->unk0, 8, 0x40);
            break;
        case 3:
            _subaddiedialog_entrypoint_11(actor->unk0, 0x153CU, 0xEU, actor->position, 0xCBU);
            break;
        case 4:
            if ((func_800DA298(FLAG_3E4_SNS_EGG_HATCHED_BLUE) != 0) ||
                (func_800DA298(FLAG_3E6_SNS_EGG_HATCHED_PINK) != 0)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x153EU, 0xEU, actor->position, 0xCBU);
            } else {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x153DU, 0xEU, actor->position, 0xCBU);
            }
            break;
        case 5:
            _subaddiedialog_entrypoint_11(actor->unk0, 0x153FU, 0xEU, actor->position, 0xCBU);
            break;
        case 6:
            if (func_800DA298(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE) != 0) {
                actor->actorData[7] = 0x515;
            } else {
                actor->actorData[7] = 0x516;
            }
            func_80800000_chheggy(actor, path_data, actor->actorData[7] == 0x515 ? 1 : 2);
            func_80800750_chheggy(actor, actor->unk0,
                                  func_800DA298(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE) != 0 ? 3 : 1, 0x40);
            break;
        case 7:
            func_80090734(2, path_data->unk0[actor->actorData[7] == 0x515 ? 3 : 4].f);
            actor->unk58 = 0.5f;
            break;
        case 8:
            item_handle = func_801000D8(actor, 1, 0x14);
            func_80090708(0);
            _subaddieitem_entrypoint_0(item_handle, actor->actorData[7], 0x3E8, 2);
            _subaddieitem_entrypoint_2(item_handle);
            func_80108B04(actor, 0U);
            break;
        case 9:
            func_80800000_chheggy(actor, func_80100094(actor, 0U), 0);
            break;
        case 10:
            func_80090734(2, path_data->unk0[actor->actorData[7] == 0x515 ? 1 : 2].f);
            actor->unk58 = 0.5f;
            break;
        case 11:
            func_80090708(0);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x1540U, 0xEU, actor->position, 0xCBU);
            break;
        case 12:
            func_800F82D4(func_800F54E4(), 2);
            if (actor->unk64_20) {
                if (func_800DA298(FLAG_3E4_SNS_EGG_HATCHED_BLUE) != 0) {
                    actor->unk3C = path_data->unk48[6];
                    func_801058C4(actor, path_data->unk48[4], 500.0f, 1U);
                    actor->unk64_20 = 0;
                    func_80800750_chheggy(actor, actor->unk0, 2, 0x11);
                } else {
                    actor->unk3C = path_data->unk48[5];
                    func_801058C4(actor, path_data->unk48[0], 500.0f, 1U);
                    func_80800750_chheggy(actor, actor->unk0, 3, 0x11);
                }
            } else if (actor->unk64_19) {
                actor->unk3C = path_data->unk48[6];
                func_801058C4(actor, path_data->unk48[2], 500.0f, 1U);
                func_80800750_chheggy(actor, actor->unk0, 2, 0x11);
            }
            func_80105BAC(actor);
            break;
        case 13:
            func_80105634(actor);
            actor->unk58 = 1.0f;
            func_800EE7F8(path_data->unk64, actor->position);
            func_800EE7F8(path_data->unk70, func_80106790(actor->unk3C)->position);
            if (actor->unk64_20) {
                func_808006C4_chheggy(actor, actor->unk0, 4, 0x30);
            } else {
                func_808006C4_chheggy(actor, actor->unk0, 6, 0x30);
            }
            break;
        case 15:
            func_8010114C(actor->unk3C, 0x18, 0);
            actor->unk58 = 1.0f;
            func_800EE7F8(path_data->unk64, actor->position);
            if (actor->unk64_20) {
                func_800C7A68(func_800D7520(path_data->unk48[1]), 0.0f, path_data->unk70);
            } else if (actor->unk64_19) {
                func_800C7A68(func_800D7520(path_data->unk48[3]), 0.0f, path_data->unk70);
            }
            break;
        case 16:
            actor->unk58 = 2.0f;
            actor->unk54 = func_8010CD50(actor, func_800F54E4());
            break;
        case 17:
            func_800F82D4(func_800F54E4(), 0);
            if (actor->unk64_20) {
                func_800DA544(FLAG_3E4_SNS_EGG_HATCHED_BLUE);
                func_800D3EF4(0xC);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1541U, 0xEU, actor->position, 0xCBU);
            } else {
                func_800DA544(FLAG_3E6_SNS_EGG_HATCHED_PINK);
                func_800C7074(0x32, 1);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1542U, 0xEU, actor->position, 0xCBU);
            }
            break;
        case 18:
            if (actor->unk64_20) {
                actor->unk64_20 = 0;
                func_801058C4(actor, path_data->unk48[1], 500.0f, 1U);
                func_80800750_chheggy(actor, actor->unk0, 3, 0x11);
            } else if (actor->unk64_19) {
                actor->unk64_19 = 0;
                func_801058C4(actor, path_data->unk48[3], 500.0f, 1U);
                func_80800750_chheggy(actor, actor->unk0, 1, 0x11);
            }
            func_80105BAC(actor);
            break;
        case 19:
            func_8080087C_chheggy(actor);
    }
    func_80102424(actor, state);
}

// Message handler for Heggy.
s32 func_80801570_chheggy(Actor *actor, s32 msg, s32 param)
{
    Unk80100094 *path_data;
    Actor *egg;
    s32 lo;
    u32 hi;

    switch (msg) {
        case 0x95:
            if (_glcutDll_entrypoint_20() != 0) {
                func_80800ECC_chheggy(actor, 0x14);
                return 1;
            }
            if (func_800DA298(FLAG_3E8_FTT_IoH_HEGGY) != 0) {
                if ((func_800DA298(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE) != 0) ||
                    (func_800DA298(FLAG_3E5_SNS_EGG_ACQUIRED_PINK) != 0)) {
                    func_80800ECC_chheggy(actor, 1);
                    return 1;
                }
                func_80800ECC_chheggy(actor, 0x13);
                return 1;
            }
            func_80800ECC_chheggy(actor, 1);
            return 1;
        case 0x32:
            switch (actor->unk70_10) {
                case 1:
                    func_808007D4_chheggy(actor, 2, 0);
                    _subaddiedialog_entrypoint_11(
                        actor->unk0, func_800DA298(FLAG_3E8_FTT_IoH_HEGGY) != 0 ? 0x153B : 0x153A,
                        0xEU, actor->position, 0xCBU);
                    return 1;
                case 6:
                    func_80800ECC_chheggy(actor, 7);
                    return 1;
                case 9:
                    func_80800ECC_chheggy(actor, 0xA);
                default:
                    return 1;
            }
        case 0x2E:
            switch (((s16 *) &param)[0]) {
                case 0x153A:
                case 0x153B:
                    switch (func_8080006C_chheggy()) {
                        case 0:
                            func_80800ECC_chheggy(actor, 3);
                            return 1;
                        case 1:
                            func_80800ECC_chheggy(actor, 4);
                            return 1;
                        case 2:
                            func_80800ECC_chheggy(actor, 5);
                        default:
                            return 1;
                    }
                case 0x153D:
                case 0x153E:
                case 0x153F:
                    func_80800ECC_chheggy(actor, 6);
                    return 1;
                case 0x1540:
                    func_80800ECC_chheggy(actor, 0xC);
                    return 1;
                case 0x1541:
                    func_80800ECC_chheggy(actor, actor->unk64_19 ? 0xC : 0x12);
                    func_800D3EF4(0xC);
                    return 1;
                case 0x1542:
                    func_80800ECC_chheggy(actor, 0x12);
                    func_800C7074(0x32, 1);
                    return 1;
                case 0x1543:
                    func_800DA544(GFLAG_C0B_JINJO_IN_MULTIPLAYER);
                    return 1;
                case 0x153C:
                    func_80800ECC_chheggy(actor, 0x13);
                default:
                    return 1;
            }
        case 0x3D:
            path_data = func_80100094(actor, 0U);
            egg =
                func_80108528(0x517, &path_data->unk0[actor->actorData[7] == 0x515 ? 3 : 4], 0, &actor);
            actor->unk3C = egg->unk0;
            egg->unk64_16 = 0;
            if (actor->actorData[7] == 0x515) {
                path_data->unk48[5] = (Unk80132ED0 *) egg->unk0;
                func_80103140(egg, 0x975, actor->unk0->unk16);
                func_80102424(egg, 1);
                return 1;
            }
            path_data->unk48[6] = (Unk80132ED0 *) egg->unk0;
            func_80103140(egg, 0x974, actor->unk0->unk16);
            func_80102424(egg, 1);
            return 1;
        case 0x18:
            if (param != 0) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1543U, 0xEU, actor->position, 0xCBU);
            }
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_4(actor->position);
            _gcdialogcamera_entrypoint_3(D_80801E8C_chheggy, actor->scale);
            return 3;
        case 0x57:
            lo = param & 0xFFFF;
            hi = (param & 0xFFFF0000) >> 0x10;
            if (_gcdialogcamera_entrypoint_0(lo, hi) != 0) {
                func_808007D4_chheggy(actor, lo, (s32) hi);
                return 2;
            }
            return 1;
        default:
            return 0;
    }
}

s32 *chheggy_entrypoint_0(void)
{
    return D_80801E9C_chheggy;
}

void func_808019CC_chheggy(Actor *actor)
{
    if (_subaddieDll_entrypoint_6(actor, 0xB) != 0) {
        func_80108B04(actor, 1);
    }
}

// Message handler for the breakable split-up pad cover.
s32 func_80801A00_chheggy(Actor *actor, s32 msg, s32 param)
{
    Actor *linked;

    switch (msg) {
        default:
            if (msg == 0x40) {
                func_80103110(actor, 1U);
                _subaddieDll_entrypoint_5(actor, param);
                func_80101FDC(actor, 2U);
                return 1;
            }
            break;
        case 0x3D:
            func_800DA544(FLAG_581_PHYSICAL_IoH_HeggySplitUpCoverBroken);
            _chskeletonexplode_entrypoint_7(actor, actor->position);
            func_8010A570(actor);
            func_8010A624(actor);
            return 1;
        case 0xF:
            linked = func_80106790(func_80101080());
            func_800C4140(0x59919413, actor->position, 0x04B000FA);
            func_800BBCB8(actor->position, actor->position, 1.0f, 6, &D_80801EE4_chheggy);
            func_800BBCB8(actor->position, actor->position, 1.0f, 3, &D_80801F1C_chheggy);
            _chskeletonexplode_entrypoint_3(linked, 1, 0);
            _chskeletonexplode_entrypoint_3(linked, 2, 1);
            func_800FFA88(actor->unk0);
            return 1;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(1, 1);
            func_800DF744(2, 0);
            return 1;
    }
    return 0;
}

s32 *chheggy_entrypoint_1(void)
{
    return D_80801F58_chheggy;
}

extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80801D60_chheggy[42] = {0x0,        0x0,       0x40800000, 0x4A50009, 0x40800000, 0x4A50009,
                              0x40800000, 0x4A50009, 0x40800000, 0x4A50009, 0x40800000, 0x4A50009,
                              0x40800000, 0x4A50009, 0x40800000, 0x4A50009, 0x40800000, 0x4A50009,
                              0x40800000, 0x4A50009, 0x40800000, 0x4A50009, 0x40800000, 0x4A50009,
                              0x3F400000, 0x4A70009, 0x40B00000, 0x4A6000A, 0x40B00000, 0x4A6000A,
                              0x40B00000, 0x4A6000A, 0x40800000, 0x4A50009, 0x40800000, 0x4A50009,
                              0x3F400000, 0x4A70009, 0x40800000, 0x4A50009, 0x40800000, 0x4A50009};
s32 D_80801E08_chheggy[12] = {0x0,        0x3E4CCCCD, 0x3E4CCCCD, 0x3F000000,
                              0x3EE66666, 0x3F800000, 0x3F000000, 0x3E4CCCCD,
                              0x3F333333, 0x3F000000, 0x3F733333, 0x3F800000};
s32 D_80801E38_chheggy[10] = {0x1D09C9, 0x2B0100, 0x1800022, 0x800100, 0x1800180,
                              0x150033, 0x330019, 0x7,       0x208C78, 0x288C0000};
s32 D_80801E60_chheggy[11] = {0x1D08A2, 0x161404, 0x2B0180, 0x2000022, 0x2000180, 0x1000100,
                              0x150019, 0xE60027, 0x640064, 0xC800C8,  0x0};
u32 D_80801E8C_chheggy[4] = {0x437A0000, 0x42F00000, 0x42F00000, 0x42C80000};
s32 D_80801E9C_chheggy[18] = {0x1580514,
                              0x9140001,
                              (u32) &D_80801D60_chheggy,
                              (u32) func_808009DC_chheggy,
                              (u32) func_808009DC_chheggy,
                              (u32) func_80101870,
                              0x0,
                              0x40000000,
                              0x0,
                              0x840100,
                              0x0,
                              (u32) func_80108ED0,
                              0x7C0000,
                              (u32) func_808008C4_chheggy,
                              (u32) func_80107C2C,
                              -0x7FFFFBEE,
                              (u32) func_80801570_chheggy,
                              0x0};
s32 D_80801EE4_chheggy[14] = {0x1D0611,  0x140016,   0x1006002D, 0x2580320, 0x2B0100,
                              0x200001B, -0x3E70320, 0x220300,   0x4000100, 0x1000007,
                              0x3000D,   0x640031,   -0x310019,  0x0};
s32 D_80801F1C_chheggy[15] = {0x1D09DD,  0x2B0400,    0x5000016, 0x10000022, 0x1800200,
                              0x4800600, 0x150000,    0x260019,  0x7,        0x2D0032,
                              0x640020,  -0x21588E40, 0xD0064,   0x31FFCE,   -0x190000};
s32 D_80801F58_chheggy[18] = {0x112052A,
                              0x9990001,
                              0x0,
                              (u32) func_808019CC_chheggy,
                              (u32) func_80105834,
                              (u32) func_801018A4,
                              0x0,
                              0x0,
                              0x5810000,
                              0x800,
                              0x0,
                              (u32) func_80108ED0,
                              0x0,
                              0x0,
                              (u32) func_80107C2C,
                              -0x7FF7F400,
                              (u32) func_80801A00_chheggy,
                              0x0};
