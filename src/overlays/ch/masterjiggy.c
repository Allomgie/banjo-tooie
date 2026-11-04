// Master Jiggywiggy in his Isle o' Hags temple: picks the first-meeting cutscene, a pending
// world-opening or idle dialog, and runs the world-opening flow. A second actor is the glow effect.
#include "common.h"

extern int D_8080164C_chmasterjiggy[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 D_80801620_chmasterjiggy[];
extern int _subaddiedialog_entrypoint_11();
extern void func_8008FE68(f32 *);
extern s32 func_80090080(void);
extern s32 func_80016B30(s32, s32);
extern int D_808016F8_chmasterjiggy[];
extern u8 D_80801790_chmasterjiggy[];
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern s32 func_800F1E6C(f32 *, f32 *, f32 *);
extern int _capod_entrypoint_14(void);
extern s32 D_8080179C_chmasterjiggy[];
extern s32 D_808017E0_chmasterjiggy[];
extern void *func_800B53A4(s32);
extern void *func_800BABB8(void *, f32 *, f32 *, f32, void *);
extern s32 _chmasterjiggy_entrypoint_2;
extern s32 func_800E15CC(s32, f32, f32);
extern void func_800E13F0(s32, f32);
extern s32 func_8010D5DC;
extern int func_80108A30(s32 param_0, s32 *param_1, f32 param_2, s32 param_3);
extern void func_8008FB10(f32 *, f32, f32, f32);
typedef union {
    s32 word;
    s16 half[2];
} MasterJiggyMessage37;
extern s16 D_80801740_chmasterjiggy[];
extern s16 D_80801750_chmasterjiggy[];
extern f32 func_800F1214(f32, f32, f32);
extern u8 D_808016E8_chmasterjiggy[];
extern u8 D_80801760_chmasterjiggy[];
extern u8 D_80801770_chmasterjiggy[];
extern u8 D_808016B0_chmasterjiggy[];
extern f32 func_800D8FF8(void);
extern f32 func_800F3780(f32, void *, s32);
extern void func_80018820(s32, f32, f32);
extern u8 D_80801690_chmasterjiggy[];
extern void func_800189A8(s32, void *, s32, f32, f32);
int func_808001D0_chmasterjiggy();
void func_80800220_chmasterjiggy();
void func_80800E58_chmasterjiggy();
extern void func_80101870(), func_80102EC0(), func_80107C2C(), func_8080000C_chmasterjiggy(),
    func_808001A8_chmasterjiggy(), func_808004FC_chmasterjiggy();

// Master Jiggywiggy NPC: podium, dialogs, world-opening flow, HUD jiggy counters.
int chmasterjiggy_entrypoint_0()
{
    return (int) &D_8080164C_chmasterjiggy;
}

void func_8080000C_chmasterjiggy(actor) Actor *actor;
{
    s32 prop;
    prop = _gccubesearch_entrypoint_0(3, actor);
    if (prop) {
        _gspropctrl_entrypoint_11(prop, actor->actorData);
    } else {
        func_800EFA4C((f32 *) actor->actorData, 1650.0f, 200.0f, 0.0f);
    }
    prop = _gccubesearch_entrypoint_0(4, actor);
    if (prop) {
        _gspropctrl_entrypoint_11(prop, (u8 *) actor + 0x28);
    } else {
        func_800EFA4C((f32 *) ((u8 *) actor + 0x28), 0.0f, 150.0f, 0.0f);
    }
    if (_glcutDll_entrypoint_20() || func_800A9C98()) {
        func_80800220_chmasterjiggy(actor, 9);
    } else if (_sujiggy_entrypoint_13()) {
        switch (_sujiggy_entrypoint_14()) {
            case 0:
                func_808001D0_chmasterjiggy(actor, 3);
                break;
            case 1:
                func_80800220_chmasterjiggy(actor, 5);
                break;
            case 2:
                func_808001D0_chmasterjiggy(actor, 9);
                break;
            case 3:
                func_80800220_chmasterjiggy(actor, 1);
                break;
        }
    } else if (!func_800DA298(0x35B)) {
        func_80800220_chmasterjiggy(actor, 2);
    } else if (!_sujiggy_entrypoint_17()) {
        func_80800220_chmasterjiggy(actor, 8);
    }
    func_800FE734(0);
}

void func_808001A8_chmasterjiggy(s32 arg0)
{
}

int func_808001B0_chmasterjiggy(s32 actor)
{
    _sujiggy_entrypoint_8();
}

int func_808001D0_chmasterjiggy(actor, dialog_index)
s32 *actor;
s32 dialog_index;
{
    u8 *entry;

    entry = (u8 *) &D_80801620_chmasterjiggy + (dialog_index * 4);
    _subaddiedialog_entrypoint_11(*actor, (*(s16 *) ((u8 *) (entry) + 0)),
                                  (*(s16 *) ((u8 *) (entry) + 2)), actor + 1, 0x97);
}

// TU-NOTE: .bss is defined here, before its first use: IDO places .bss objects used before their
// definition first, the rest in definition order.
// TU-NOTE: .bss is defined here, before its first use: IDO places .bss objects used before their
// definition first, the rest in definition order.
s32 B_808017F0_chmasterjiggy;

void func_80800220_chmasterjiggy(actor, dialog_index) u8 *actor;
s32 dialog_index;
{
    s8 _sfpad[8]; // Matching: padding local needed for the stack layout.
    s32 unk_0;

    func_80102424();

switch (dialog_index) {
    case 2:
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F904(&func_8010D5DC, *(s32 *) ((s8 *) actor + 0));
        func_8008F938(1);
        func_8008F990(actor + 0x28, 0x43FA0000);
        _capod_entrypoint_13(*(s32 *) ((s8 *) actor + 0), 0, 0x11, 0x60);
        return;
    case 3:
        func_800C0658();
        func_8008F8B0();
        func_8008F904(&func_8010D5DC, *(s32 *) ((s8 *) actor + 0));
        func_8008F9F8(actor + 0x18, 0x43960000);
        func_8008F938(0);
        func_80090658(1);
        return;
    case 4:
        func_800DBEFC(func_800BEC10(), 4, &unk_0);
        func_80090734(4, &unk_0);
        *(f32 *) ((s8 *) actor + 0x58) = 1.0f;
        return;
    case 5:
        func_80108A30(0x4B1, &B_808017F0_chmasterjiggy, 0.0f, 0x32);
        *(f32 *) ((s8 *) actor + 0x34) = 1.0f;
        return;
    case 9:
        func_80101EE4(actor, 0x3F4CCCCD);
}

}

int func_80800374_chmasterjiggy(actor)
Actor *actor;
{
    f32 player_pos[3];

    func_8008FE68(player_pos);
    return player_pos[0] >= 1576.0f && func_8008FD48() == 1;
}

int func_808003D4_chmasterjiggy(s32 actor)
{
    return func_80090080() && func_80016B30(0, 1) == 1;

}

int func_80800414_chmasterjiggy(Actor *actor)
{
    if (func_80800374_chmasterjiggy()) {
        if (!func_800DA298(0x533)) {
            if (func_808001D0_chmasterjiggy(actor, 3) != 0) {
                func_800DA544(0x533);
            }
        }
        if (func_808003D4_chmasterjiggy(actor)) {
            func_80800220_chmasterjiggy(actor, 3);
        }
    }

}

// Shows the HUD counters unless a cutscene or the final state is active.
void func_8080047C_chmasterjiggy(s32 actor)
{
    if ((func_800C0638() == 0) && (func_800DA298(0xD4E) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800D2498(0x10E, func_800D035C(1), 0);
        func_800D2498(0x106, _sujiggy_entrypoint_2(_sujiggy_entrypoint_0()), 0);
    }

}

void func_808004FC_chmasterjiggy(actor) Actor *actor;
{
    func_8008FB10(actor->position, 200.0f, 0.0f, 100.0f);

switch (actor->unk70_10) {
    case 1:
        if (_subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1], 400, 60,
                                         6)) {
            if (_sujiggy_entrypoint_21()) {
                func_808001D0_chmasterjiggy(actor, 8);
            } else {
                func_808001D0_chmasterjiggy(actor, 1);
            }
        } else {
            func_80800414_chmasterjiggy(actor);
        }
        func_8080047C_chmasterjiggy(actor);
        return;
    case 2:
    case 3:
        func_8080047C_chmasterjiggy(actor);
        return;
    case 4:
        if (!func_800C0638() && func_800D9078(&actor->unk58)) {
            func_808001B0_chmasterjiggy(actor);
        }
        func_8080047C_chmasterjiggy(actor);
        return;
    case 5:
        if (func_800D90A4(&((f32 *) actor->actorData)[7])) {
            func_80800220_chmasterjiggy(actor, 6);
        }
        break;
    case 6:
        if (func_80101DDC(actor)) {
            func_80800220_chmasterjiggy(actor, 7);
        }
        break;
    case 8:
        if (func_80800374_chmasterjiggy(actor) && func_808003D4_chmasterjiggy(actor)) {
            func_808001D0_chmasterjiggy(actor, 5);
        } else if (_subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1], 400,
                                                60, 6)) {
            func_808001D0_chmasterjiggy(actor, 2);
        }
        func_8080047C_chmasterjiggy(actor);
        return;
    case 9:
    case 10:
        if (func_80101DDC(actor)) {
            func_80800220_chmasterjiggy(actor, actor->unk70_10 + 1);
        }
}

}

int func_80800704_chmasterjiggy(s32 actor[3], s32 param_1, s32 param_2)
{
    s32 unk_0;
    int unk_1;
    unk_0 = _capod_entrypoint_14();
    // Matching: the redundant assignment chain is needed for the match.
    unk_1 = 0 | (unk_0 = 0);
    _capod_entrypoint_13(actor[unk_0], unk_1, param_2, 0x2030 ^ 0);

}

void func_80800744_chmasterjiggy(Actor *actor, s32 dialog_id, s32 param_2)
{
    switch (dialog_id) {
        case 0x14F6:
            _capod_entrypoint_14();
            func_800DA544(0x35B);
            func_80800220_chmasterjiggy(actor, 1);
            break;
        case 0x14FC:
        case 0x155B:
        case 0x155C:
        case 0x155D:
        case 0x155E:
            func_80800220_chmasterjiggy(actor, 1);
            break;
        case 0x1511:
            func_80800220_chmasterjiggy(actor, 8);
    }

}

s32 func_808007F0_chmasterjiggy(Actor *actor, s32 message, MasterJiggyMessage37 event)
{
    s32 tx;
    s32 ty;

switch (message) {
    case 0x2E:
        ty = event.half[1];
        tx = event.half[0];
        func_80800744_chmasterjiggy(actor, tx, ty);
        break;

    case 0x2F:
        func_80800704_chmasterjiggy(actor, event.half[0], event.half[1]);
        break;

    case 0xB:
        return 3;
    case 0x32:
        if (actor->unk70_10 == 3)
            func_80800220_chmasterjiggy(actor, 4);
        else
            func_808001D0_chmasterjiggy(actor, 0);
        break;

    case 0x31:
        func_80800220_chmasterjiggy(actor, 8);
        if (_sujiggy_entrypoint_21()) {
            func_808001D0_chmasterjiggy(actor, 7);
            return 1;
        }
        func_808001D0_chmasterjiggy(actor, _sujiggy_entrypoint_17() ? 4 : 5);
        break;

    case 0x30:
        // Matching: the empty branches are needed for the match.
        if (event.half[0] == 0x14F7) {
        } else if (event.half[0] == 0x14F8) {
        } else if (event.half[0] == 0x14F9) {
        } else if (event.half[0] == 0x14FA) {
        } else if (event.half[0] == 0x14FB) {
        }
        return _sujiggy_entrypoint_0() + 1;
    case 0x95:
        break;
    default:
        return 0;
}

return 1;
}

// World-opening glow sequence: mesh tint, fade, shake, music, opening the next world.
int chmasterjiggy_entrypoint_1()
{
    return (int) &D_808016F8_chmasterjiggy;
}

unsigned long long func_8080095C_chmasterjiggy(void *actor)
{
    f32 *scale;
    scale = (f32 *) ((char *) actor + 0x38);
    *scale = 1.0f;
}

void func_8080096C_chmasterjiggy(Actor *actor)
{
    s32 glow_on;

    glow_on = actor->unk64_20 != 0;
    if (glow_on)
        glow_on = ((f32 *) actor->actorData)[0] > 0.0f;
    _subaddieaudioloop_entrypoint_4(actor, actor->position, glow_on, D_80801740_chmasterjiggy);
    _subaddieaudioloop_entrypoint_1(
        actor, (s32) func_800F1214(((f32 *) actor->actorData)[0], 5000.0f, 13000.0f));
    ((u8 *) actor->actorData)[0xC] = _subaddieaudioloop_entrypoint_7(
        ((u8 *) actor->actorData)[0xC], actor->position, ((f32 *) actor->actorData)[0] > 0.0f,
        D_80801750_chmasterjiggy, 0);
}

void func_80801488_chmasterjiggy();

void func_80801448_chmasterjiggy();

void func_808010E4_chmasterjiggy();

// Glow actor update: advances the blend and runs the world-opening states.
void func_80800A40_chmasterjiggy(Actor *actor)
{
    f32 delta_time;
    s32 blend_done;
    delta_time = func_800D8FF8();
    blend_done = 0;

if (((f32 *) actor->actorData)[2] < 1.0f) {
    ((f32 *) actor->actorData)[2] += delta_time * ((f32 *) actor->actorData)[4];
    if (((f32 *) actor->actorData)[2] >= 1.0f) {
        ((f32 *) actor->actorData)[2] = 1.0f;
        blend_done = 1;
    }
}

func_808010E4_chmasterjiggy(actor);
func_80801448_chmasterjiggy(actor);
func_80801488_chmasterjiggy(actor);
func_8080096C_chmasterjiggy(actor);

switch (actor->unk70_10) {
    case 2:
        if (func_800D90A4(&((f32 *) actor->actorData)[7]))
            func_80800E58_chmasterjiggy(actor, 3);
        break;
    case 3:
        ((f32 *) actor->actorData)[0] =
            func_800F3780(((f32 *) actor->actorData)[2], D_808016B0_chmasterjiggy, 7);
        if (blend_done)
            func_80800E58_chmasterjiggy(actor, 4);
        break;
    case 4:
        ((f32 *) actor->actorData)[0] =
            func_800F3780(((f32 *) actor->actorData)[2], D_80801760_chmasterjiggy, 2);
        func_80018820(0, 0.75f, 0.5f);
        if (blend_done)
            func_808001D0_chmasterjiggy(actor, 6);
        break;
    case 5:
        ((f32 *) actor->actorData)[1] =
            func_800F3780(((f32 *) actor->actorData)[2], D_80801770_chmasterjiggy, 4);
        if (blend_done) {
            _capod_entrypoint_14();
            _sujiggy_entrypoint_15(_sujiggy_entrypoint_0() - 1, 1);
        }
        break;
    case 6:
        ((f32 *) actor->actorData)[1] =
            func_800F3780(((f32 *) actor->actorData)[2], D_808016E8_chmasterjiggy, 2);
        ((f32 *) actor->actorData)[0] = ((f32 *) actor->actorData)[1];
}

}

void func_80800C08_chmasterjiggy(Actor *actor, s32 param_1)
{
    f32 cam_rot[3];
    f32 yaw;
    f32 cam_pos[3];
    f32 angle_factor;

    func_800E3A58(cam_rot);
    actor->rotation[1] = cam_rot[1];
    *((u8 *) actor + 0x9B) = (u32) (*((f32 *) &actor->actorData[0]) * 255.0f);

if (actor->unk64_20) {
    func_80101870(actor, param_1);
}

if (*(f32 *) &actor->actorData[1] > 0.0f) {
    _sufade_entrypoint_0((s32) (*(f32 *) &actor->actorData[1] * 255.0f),
                         D_80801790_chmasterjiggy);
}

if (*(f32 *) &actor->actorData[0] > 0.0f && actor->unk64_20) {
    func_800E3980(cam_pos);
    if (func_800F1E6C(actor->position, cam_pos, &yaw)) {
        angle_factor = mlAbsF(func_800F1DCC(yaw, cam_rot[1])) / 25.0f;
        if (angle_factor < 1.0f) {
            _sufade_entrypoint_0(
                (s32) (*(f32 *) &actor->actorData[0] * ((1.0f - angle_factor) * 100.0f)),
                D_80801790_chmasterjiggy);
        }
    }
}

}

int func_80800DDC_chmasterjiggy(Actor *actor)
{
    float zero;
    zero = 0.0f;

if (*(s32 *) ((char *) actor + 0x2C) != 0) {
    func_800B5450(*(s32 *) ((char *) actor + 0x2C));
    *(s32 *) ((char *) actor + 0x2C) = 0;
}

if (*(s32 *) ((char *) actor + 0x30) != 0) {
    func_800E1720(*(s32 *) ((char *) actor + 0x30) - 1);
    *(s32 *) ((char *) actor + 0x30) = 0;
}

if (*(u8 *) ((char *) actor + 0x24) != 0) {
    *(u8 *) ((char *) actor + 0x24) =
        _subaddieaudioloop_entrypoint_3(*(u8 *) ((char *) actor + 0x24));
}

*((f32 *) (((char *) actor) + 0x54)) = zero;
}

void func_80800E58_chmasterjiggy(actor, state) Actor *actor;
s32 state;
{
    f32 duration;

    func_80101FDC(actor, state);
    *((f32 *) &actor->actorData[2]) = 0.0f;

if (state > 0) {
    duration = ((f32 *) D_80801690_chmasterjiggy)[state];
    if (duration > 0.0f) {
        *(f32 *) &actor->actorData[4] = 1.0f / duration;
    } else {
        *(f32 *) &actor->actorData[4] = 0.0f;
    }
}

switch (state) {
    case 2:
        _capod_entrypoint_13(actor->unk0, 0, 9, 0x6030);
        actor->unk64_20 = 0;
        *(f32 *) &actor->actorData[7] = 7.5f;
        break;
    case 3:
        actor->unk64_20 = 0;
        func_800189A8(0, D_808016B0_chmasterjiggy, 7, duration, 2.0f);
        actor->unk54 = 0.0f;
        break;
    case 4:
        actor->unk64_20 = 1;
        func_800FC660(0x1C);
        break;
    case 5:
        actor->unk64_20 = 1;
        break;
    case 6:
        _capod_entrypoint_13(actor->unk0, 0, 0x17, 0x2030);
        actor->unk64_20 = 1;
        func_800189A8(0, D_808016E8_chmasterjiggy, 2, duration, 2.0f);
        func_800FCAE0(0x1C, 0, 0x1BC);
        break;
    case 7:
        actor->unk64_20 = 0;
        func_80101180(0x1E1, 0x31, 0);
        func_800FFAB0(actor);
        _subaddieaudioloop_entrypoint_2(actor);
        func_800FC74C(0x1C);
}

}

int func_80801030_chmasterjiggy(Actor *actor, s32 message, s32 param_2)
{
    switch (message) {
        case 0x95:
            if (actor->unk70_10 == 1) {
                func_80800E58_chmasterjiggy(actor, 2);
            } else {
                func_80800E58_chmasterjiggy(actor, 6);
            }
            break;
        case 0x2E:
            func_80800E58_chmasterjiggy(actor, 5);
            break;
        case 0xB:
            if (param_2 == 0x17) {
                _capod_entrypoint_14();
                func_80800E58_chmasterjiggy(actor, 7);
                return 4;
            }
            return 3;
        default:
            return 0;
    }

return 1;
}

void func_808010E4_chmasterjiggy(Actor *actor)
{
    f32 spawn_pos[3];

if (((f32 *) actor->actorData)[0] > 0.0f && actor->unk64_20) {
    if (!actor->actorData[5]) {
        func_800EE780(spawn_pos, actor->position, &D_808017E0_chmasterjiggy);
        actor->actorData[5] = (u32) func_800B53A4(0x32);
        func_800B5534(actor->actorData[5]);
        actor->actorData[5] =
            (u32) func_800BABB8((void *) actor->actorData[5], actor->position, spawn_pos, 1.0f,
                                &D_8080179C_chmasterjiggy);
    }
    func_800BA22C(actor->actorData[5], 4);
}

}

// Mesh tint callback: blends vertex colors toward white by the glow amount.
void chmasterjiggy_entrypoint_2(s32 param_0, Vtx *src, Vtx *dst, s32 count, s32 actor_id)
{
    Actor *actor;
    Vtx *end;

    actor = (Actor *) func_80106790(actor_id);
    end = src + count;
    for (; src < end; src++, dst++) {
        dst->v.cn[0] = (u32) ((u32) src->v.cn[0] +
                                  ((f32 *) actor->actorData)[0] * (255 - src->v.cn[0]));
        dst->v.cn[1] = (u32) ((u32) src->v.cn[0] +
                                  ((f32 *) actor->actorData)[0] * (255 - src->v.cn[1]));
        dst->v.cn[2] = (u32) ((u32) src->v.cn[0] +
                                  ((f32 *) actor->actorData)[0] * (255 - src->v.cn[2]));
    }
}

void func_80801448_chmasterjiggy(s32 *actor_id)
{
    _glid_entrypoint_0(func_800BEA88(0), 1, &_chmasterjiggy_entrypoint_2, *actor_id);
}

void func_80801488_chmasterjiggy(Actor *actor)
{
    if (*(f32 *) &actor->actorData[0] > 0.0f) {
        if (actor->actorData[6] == 0)
            actor->actorData[6] = func_800E15CC(0, 0.0f, 1.0f) + 1;
        func_800E13F0(actor->actorData[6] - 1, *(f32 *) &actor->actorData[0] * 10.0f);
    } else if (actor->actorData[6]) {
        func_800E1720(actor->actorData[6] - 1);
        actor->actorData[6] = 0;
    }
}

// TU-NOTE: the overlay .data is defined in C; its tables point to functions of this file, and IDO
// schedules some of them differently unless the tables are in the same unit. Values are from the ROM.
// The extern declarations of the D_ tables were adjusted to the object (same addresses).
// TU-NOTE: the overlay .data is defined in C; its tables point to functions of this file, and IDO
// schedules some of them differently unless the tables are in the same unit. Values are from the ROM.
// The extern declarations of the D_ tables were adjusted to the object (same addresses).
u8 D_808015C0_chmasterjiggy[96] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x41, 0x99, 0x99, 0x9A, 0x4, 0xC1, 0x0, 0x0,
    0x41, 0x99, 0x99, 0x9A, 0x4, 0xC1, 0x0, 0x0,  0x41, 0x99, 0x99, 0x9A, 0x4, 0xC1, 0x0, 0x0,
    0x41, 0x99, 0x99, 0x9A, 0x4, 0xC1, 0x0, 0x0,  0x41, 0x99, 0x99, 0x9A, 0x4, 0xC1, 0x0, 0x0,
    0x40, 0x28, 0x0,  0x0,  0x4, 0xCA, 0x0, 0x4A, 0x3F, 0x80, 0x0,  0x0,  0x4, 0xCB, 0x0, 0x9,
    0x41, 0x99, 0x99, 0x9A, 0x4, 0xC1, 0x0, 0x0,  0x41, 0x99, 0x99, 0x9A, 0x4, 0xC1, 0x0, 0xA,
    0x40, 0x28, 0x0,  0x0,  0x4, 0xCA, 0x0, 0xA,  0x3F, 0x80, 0x0,  0x0,  0x4, 0xCB, 0x0, 0x9};
s32 D_80801620_chmasterjiggy[11] = {0x14F6004C, 0x14F7000B, 0x1538000B, 0x14F80000,
                                    0x14FC0000, 0x15110000, 0x1510004C, 0x155B000B,
                                    0x155C000B, 0x155D000B, 0x155E000B};
int D_8080164C_chmasterjiggy[17] = {0x15801E1,
                                    0x9350001,
                                    (u32) &D_808015C0_chmasterjiggy,
                                    (u32) func_808004FC_chmasterjiggy,
                                    (u32) func_80102EC0,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x108,
                                    (u32) func_808001A8_chmasterjiggy,
                                    0x0,
                                    0x0,
                                    (u32) func_8080000C_chmasterjiggy,
                                    (u32) func_80107C2C,
                                    -0x7FFFDBFE,
                                    (u32) func_808007F0_chmasterjiggy};
u8 D_80801690_chmasterjiggy[32] = {0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0,
                                   0x0, 0x40, 0xA0, 0x0,  0x0, 0x3F, 0x0, 0x0, 0x0, 0x3F, 0x0,
                                   0x0, 0x0,  0x3F, 0xC0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
u8 D_808016B0_chmasterjiggy[56] = {
    0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3E, 0x2A, 0x99, 0x31, 0x3E, 0x80,
    0x0,  0x0,  0x3E, 0xAA, 0xA6, 0x4C, 0x0,  0x0,  0x0,  0x0,  0x3F, 0x0,  0x0,  0x0,
    0x3F, 0x0,  0x0,  0x0,  0x3F, 0x2A, 0xAC, 0xDA, 0x0,  0x0,  0x0,  0x0,  0x3F, 0x55,
    0x53, 0x26, 0x3F, 0x40, 0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
u8 D_808016E8_chmasterjiggy[16] = {0x0,  0x0,  0x0, 0x0, 0x3F, 0x80, 0x0, 0x0,
                                   0x3F, 0x80, 0x0, 0x0, 0x0,  0x0,  0x0, 0x0};
int D_808016F8_chmasterjiggy[18] = {0x15804B1,
                                    0x81B0001,
                                    0x0,
                                    (u32) func_80800A40_chmasterjiggy,
                                    (u32) func_80102EC0,
                                    (u32) func_80800C08_chmasterjiggy,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x20400,
                                    (u32) func_80800DDC_chmasterjiggy,
                                    0x0,
                                    0x0,
                                    (u32) func_8080095C_chmasterjiggy,
                                    (u32) func_80107C2C,
                                    -0x7FFFFBFE,
                                    (u32) func_80801030_chmasterjiggy,
                                    0x0};
s16 D_80801740_chmasterjiggy[8] = {0x13, 0x673, 0x20, 0x2, 0xA, 0xD9, 0x0, 0x0};
s16 D_80801750_chmasterjiggy[8] = {0x13, 0x4A9, 0x16, 0x5DC0, 0xA, 0x100, 0x0, 0x0};
u8 D_80801760_chmasterjiggy[16] = {0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0, 0x0,
                                   0x3F, 0x80, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0};
u8 D_80801770_chmasterjiggy[32] = {0x0,  0x0, 0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x3E, 0x4C, 0xCC,
                                   0xCD, 0x0, 0x0,  0x0,  0x0, 0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0x80,
                                   0x0,  0x0, 0x3F, 0x80, 0x0, 0x0,  0x3F, 0x80, 0x0,  0x0};
u8 D_80801790_chmasterjiggy[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF};
s32 D_8080179C_chmasterjiggy[17] = {0x1D09E5, 0x1BFF38,  -0x12BFFD3, 0x2BC04B0, 0xB0082,  0xBE0032,
                                    0x16,     0x2020024, 0x330059,   0x150000,  0x4C001E, 0x640064,
                                    0x2A0000, 0x190080,  0xC00004,   0x4C0007,  0x20000};
s32 D_808017E0_chmasterjiggy[4] = {0x0, -0x3C5B0000, 0x0, 0x0};
