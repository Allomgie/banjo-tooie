#include "ch/alienkids.h"

extern int D_808020DC_chalienkids[];
extern int D_80802124_chalienkids[];
extern void *D_8080216C_chalienkids;
extern s32 D_808021B4_chalienkids[];
extern void func_80102424(Actor *, s32);
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern s32 func_800DA298(s32);
extern s32 func_800D9078(f32 *);
extern s32 func_800F54E4(void);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void *func_80100094(Actor *, s32);
extern void _capod_entrypoint_14(void);
extern void func_80101180(s32, s32, s32);
extern void func_80103110(Actor *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern Actor *func_80106790(Unk80132ED0 *);
extern Unk80132ED0 *func_80101080(void);
extern void func_80101870(Actor *, void *);
extern void func_8010A764(Actor *, s32);
extern u8 D_80801E60_chalienkids[];
extern u8 D_80801E80_chalienkids[];
extern u8 D_80801E98_chalienkids[];
extern u8 D_80801EA8_chalienkids[];
extern u8 D_80802234_chalienkids[];
typedef struct {
    u32 pad : 15;
    u32 flag : 1;
    u32 pad2 : 16;
} BitTest15;
typedef struct {
    u8 pad_0[0x1C];
    f32 angles[4];
} AlienRingState331;
extern u8 D_8080223C_chalienkids[];
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_80103EF4(Actor *);
extern f32 func_80103EAC(Actor *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern f32 func_800136E4(f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 26;
    u32 flag : 1;
    u32 pad_2 : 5;
} AlienKidFlags;
extern f32 func_8010A40C(Actor *);
extern void func_8008FB58(f32 *, f32, f32);
extern s32 D_80802260_chalienkids[];
extern f32 func_80800D68_chalienkids[];
extern u8 D_8080226C_chalienkids[];
extern s32 _subaddiedialog_entrypoint_8(Actor *, f32 *, void *, void *, s32);
typedef struct {
    u8 pad_0[0x30];
    Unk80132ED0 *marker;
} AlienKidAttachment;
extern u8 D_8080227C_chalienkids[];
extern void func_80109F08(void *param_0, int param_1);
typedef union {
    s32 word;
    void *pointer;
} ActorCallbackData;
extern s32 _subaddieDll_entrypoint_5(Actor *, void *);
extern void func_80101FDC(Actor *, s32);
extern u8 D_80802284_chalienkids[];
extern int func_80101E14(Actor *, f32);
extern u8 D_808021FC_chalienkids[];
extern s32 _plsu_entrypoint_3(Unk80132ED0 *);
extern void func_800F7BC8(s32, s32, Unk80132ED0 *);
extern void func_800F82D4(s32, s32);
extern void func_8010A624(Actor *);
extern Actor *func_801084B0(s32, Actor **);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 _chlifeforcespell_entrypoint_1(Actor **, f32 *, s32, f32, s32);
extern s32 _gcdialogcamera_entrypoint_3(f32 *, f32);
typedef struct {
    u8 pad[0x30];
    Unk80132ED0 *marker;
} AlienKidLink;
extern void _chbadshad_entrypoint_2(Actor *, s32, f32, s32);
void func_80800D58_chalienkids();
void func_80800FA4_chalienkids();
void func_80801BC4_chalienkids();
void func_80801628_chalienkids();
void func_808019C8_chalienkids();

int *chalienkids_entrypoint_0()
{
    return &D_808020DC_chalienkids;
}

int *chalienkids_entrypoint_1()
{
    return &D_80802124_chalienkids;
}

void *chalienkids_entrypoint_2(void)
{
    return &D_8080216C_chalienkids;
}

int chalienkids_entrypoint_3()
{
    return D_808021B4_chalienkids;
}

int func_80800030_chalienkids(int actor)
{
    func_80800FA4_chalienkids(actor, 0x32, 0x372, 4);
}

void func_80801884_chalienkids();

void func_8080184C_chalienkids();

void func_808016D4_chalienkids();

void func_8080158C_chalienkids();

void func_80800058_chalienkids(Actor *actor)
{
    func_808019C8_chalienkids((u8 *) actor);
    switch (actor->unk70_10) {
        case 2:
            func_80801884_chalienkids(actor);
            break;
        case 3:
            if (func_80801158_chalienkids(actor, 0x9E5)) {
                func_80102424(actor, 4);
                _subaddieDll_entrypoint_4(actor, 0);
            }
            break;
        case 5:
            if (func_80101DDC(actor)) {
                _subaddieskeleton_entrypoint_2(actor->unk0, 4, actor->position);
                func_80102424(actor, 14);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1284, 6, actor->position, 0xB7);
            }
            break;
        case 15:
            func_8010B990(actor, 0x1005);
            break;
        case 16:
            func_8080184C_chalienkids(actor, D_80801E60_chalienkids, 4);
    }
    func_808016D4_chalienkids(actor);
    func_8080158C_chalienkids(actor);
    func_80801628_chalienkids(actor);
}

int func_8080017C_chalienkids(Actor *actor)
{
    func_80800FA4_chalienkids(actor, 0x33, 0x373, 6);
    if (!func_800DA298(0x373) && !_glcutDll_entrypoint_20()) {
        func_8010A85C(actor, 2);
    }
}

void func_808001D0_chalienkids(Actor *actor)
{
    s32 unk_0;

    func_808019C8_chalienkids((u8 *) actor);
    switch (actor->unk70_10) {
        case 2:
            func_80801884_chalienkids(actor);
            break;
        case 3:
            if (func_80801158_chalienkids(actor, 0x9E5)) {
                func_80102424(actor, 6);
                _subaddieDll_entrypoint_4(actor, 0);
            }
            break;
        case 7:
            if (func_800D9078(&actor->unk58)) {
                func_80102424(actor, 8);
                ((u8 *) actor)[0x77] &= ~0x20;
            }
            break;
        case 8:
            if (func_80101E14(actor, 0.4f)) {
                func_8010A85C(actor, 1);
            }
            if (func_80101DDC(actor)) {
                _subaddieskeleton_entrypoint_2(actor->unk0, 4, actor->position);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1285, 4, actor->position, 0xB7);
                func_80102424(actor, 0xE);
            }
            break;
        case 15:
            unk_0 = 5;
            if (actor->unk6C_0) {
                actor->unk6C_0--;
            } else {
                unk_0 = 0x1005;
            }
            func_8010B990(actor, unk_0);
            break;
        case 16:
            func_8080184C_chalienkids(actor, &D_80801E80_chalienkids, 3);
    }
    func_808016D4_chalienkids(actor);
    func_8080158C_chalienkids(actor);
    func_80801628_chalienkids(actor);
}

int func_80800370_chalienkids(s32 actor, s32 arg)
{
    Actor *data;
    f32 unk_1[3];
    f32 unk_0[3];
    data = func_80100094(actor, 0);
    if (*(s32 *) ((char *) data + 0x2C) != 0) {
        _subaddiefade_entrypoint_9(actor, unk_0);
        _chlifeforcespell_entrypoint_2(actor, *(s32 *) ((char *) data + 0x2C), unk_1);
        _subaddiefade_entrypoint_11(actor, unk_1);
        func_80800D58_chalienkids(actor, arg);
        _subaddiefade_entrypoint_11(actor, unk_0);
    } else {
        func_80800D58_chalienkids(actor, arg);
    }
}

void func_80800408_chalienkids(Actor *actor)
{
    func_80800FA4_chalienkids(actor, 0x34, 0x374, 9);
    if (((u32) (u16) *(u16 *) ((char *) actor + 0x72) >> 0xA) == 9) {
        func_8010A63C(actor);
    }
}

void func_80801520_chalienkids();

void func_80800454_chalienkids(Actor *actor)
{
    s32 index;

    func_808019C8_chalienkids(actor);
    switch (actor->unk70_10) {
        case 2:
            func_80801884_chalienkids(actor);
            break;
        case 3:
            if (func_80801158_chalienkids(actor, 0x9E5)) {
                func_80102424(actor, 9);
                _subaddieDll_entrypoint_4(actor, 0);
            }
            break;
        case 9:
            if (!_subaddiedialog_entrypoint_8(actor, actor->position, D_808021FC_chalienkids,
                                              D_80801E98_chalienkids, 2)) {
                index = _plsu_entrypoint_3(actor->unk0);
                if (index != -1 && func_800DA298(0x371)) {
                    func_800F7BC8(index, 0x53, actor->unk0);
                }
            }
            break;
        case 0xB:
            if (func_800D9078(&actor->unk58)) {
                func_800F82D4(func_800F54E4(), 0);
                func_80102424(actor, 0xE);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1286, 6, actor->position, 0xB7);
                func_8010A624(actor);
            }
            break;
        case 0xC:
            if (func_80801158_chalienkids(actor, 0x9E6)) {
                func_80801520_chalienkids(actor, 0x374);
            }
            break;
        case 0xD:
            if (func_80801158_chalienkids(actor, 0x9E6)) {
                _capod_entrypoint_14();
                _subaddieDll_entrypoint_4(actor, 0);
                func_80102424(actor, 0x10);
                func_80101180(0x45A, 0x31, actor->unk6C_9);
            }
            break;
        case 0x10:
            func_8080184C_chalienkids(actor, D_80801EA8_chalienkids, 3);
    }
    func_808016D4_chalienkids(actor);
    func_8080158C_chalienkids(actor);
}

s32 func_8080193C_chalienkids();

void func_808014B0_chalienkids();

void func_80800DB8_chalienkids();

s32 func_80800648_chalienkids(Actor *actor, s32 msg, s32 msg_arg)
{
    extern Vec3f D_8080220C_chalienkids;
    extern Vec3f D_80802218_chalienkids;
    extern f32 D_80802224_chalienkids[];
    char *info;
    Actor *helper;
    f32 spell_pos[3];
    Actor *spawned;
    Vec3f pos_a;
    Vec3f pos_b;
    f32 cam_pos[3];
    s16 *halves;
    s32 actor_id;
    char *info2;

    info = func_80100094(actor, 0);
    switch (msg) {
        case 0x3D:
            switch (msg_arg) {
                case 0:
                case 1:
                    helper = func_801084B0(0x459, &actor);
                    *(s32 *) (info + 0x30) = (s32) helper->unk0;
                    helper->unk3C = actor->unk0;
                    *(f32 *) ((char *) helper + 0x48) = 0.0f;
                    *(s32 *) &helper->unk50 = msg_arg == 1 ? 0x6B4 : 0;
                    if (!func_800DA298(0x376)) {
                        func_8010A570(helper);
                    } else {
                        *((u8 *) helper + 0x65) &= ~1;
                    }
                    break;
                case 2:
                    func_800EE7F8(spell_pos, actor->position);
                    spell_pos[1] -= 120.0f;
                    *(s32 *) (info + 0x2C) =
                        _chlifeforcespell_entrypoint_1(&actor, spell_pos, 100, 4.0f, 0x12);
                    break;
                case 3:
                    spawned = func_80108528(0x466, actor->position, 0, &actor);
                    actor->unk3C = spawned->unk0;
            }
            break;
        case 0x0A:
            actor_id = actor->unk6C_9;
            if (actor_id == 0x456) {
                pos_a = D_8080220C_chalienkids;
                func_800F77E8(func_800F54E4(), &pos_a);
                func_80102424(actor, 5);
                *((u8 *) actor + 0x77) &= ~0x20;
                _capod_entrypoint_13(actor->unk0, 0, 0x60, 0x30);
            } else if (actor_id == 0x457) {
                pos_b = D_80802218_chalienkids;
                func_800F77E8(func_800F54E4(), &pos_b);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x12CE, 6, actor->position, 0xB7);
                _capod_entrypoint_13(actor->unk0, 0, 0x5D, 0x30);
            }
            *(s32 *) (info + 0x30) = 0;
            break;
        case 0x18:
            func_800EE7F8(cam_pos, actor->position);
            func_800EF1B8(cam_pos, actor->rotation[1] + 40.0f, 150.0f);
            func_800F77E8(func_800F54E4(), cam_pos);
            func_800F8300(func_800F54E4(), 2, actor->position);
            _capod_entrypoint_13(actor->unk0, 0, 0x65, 0x30);
            func_80102424(actor, 0xB);
            actor->unk58 = 2.0f;
            break;
        case 0x2E:
            halves = (s16 *) &msg_arg;
            func_80800DB8_chalienkids(actor, halves[0], halves[1]);
            break;
        case 0x0B:
            switch (msg_arg) {
                case 0xC:
                    func_80101180(0x457, 0x4A, 0);
                    return 4;
                case 0xF:
                    func_80101180(0x458, 0x4A, 0);
                    return 4;
                case 0x13:
                    func_808014B0_chalienkids(actor, 0x372);
                    _subaddieDll_entrypoint_4(actor, 0);
                    func_80102424(actor, 0x10);
                    _capod_entrypoint_14();
                    func_80101180(0x45A, 0x31, actor->unk6C_9);
                    return 4;
                case 0x16:
                    func_808014B0_chalienkids(actor, 0x373);
                    _subaddieDll_entrypoint_4(actor, 0);
                    func_80102424(actor, 0x10);
                    _capod_entrypoint_14();
                    func_80101180(0x45A, 0x31, actor->unk6C_9);
                    return 4;
            }
            return 2;
        case 0x4A:
            func_80102424(actor, 2);
            func_80103110(actor, 1);
            _subaddieDll_entrypoint_4(actor, 1);
            switch (actor->unk6C_9) {
                case 0x456:
                    actor->unk58 = 4.0f;
                    _capod_entrypoint_13(actor->unk0, 0, 0xC, 0x2030);
                    break;
                case 0x457:
                    actor->unk58 = 2.5f;
                    _capod_entrypoint_14();
                    _capod_entrypoint_13(actor->unk0, 0, 0xF, 0x2030);
                    break;
                case 0x458:
                    actor->unk58 = 2.0f;
                    func_8010A63C(actor);
                    _capod_entrypoint_14();
                    _capod_entrypoint_13(actor->unk0, 0, 0x12, 0x2010);
            }
            break;
        case 0x4B:
            func_80108B04(actor, 2);
            _capod_entrypoint_13(actor->unk0, 0, 0x31, 0x30);
            _subaddieDll_entrypoint_4(actor, 1);
            actor->unk58 = 6.0f;
            func_80102424(actor, 7);
            break;
        case 0x4C:
            info2 = func_80100094(actor, 0);
            *(s32 *) (info2 + 0x2C) = 0;
            break;
        case 0x4E:
            if (actor->unk70_10 == 0x10) {
                _subaddieDll_entrypoint_4(actor, 1);
                func_80102424(actor, 0x12);
                func_80108B04(actor, 3);
                actor->unk58 = 1.2f;
            }
            break;
        case 0x29:
            func_8080193C_chalienkids(actor);
            break;
        case 0x2A:
            func_80801994_chalienkids(actor);
            break;
        case 0x95:
            info2 = func_80100094(actor, 0);
            *(s32 *) (info2 + 0x30) = 0;
            switch (actor->unk6C_9) {
                case 0x456:
                    if (!func_800DA298(0x372) && !_glcutDll_entrypoint_20()) {
                        func_80108B04(actor, 0);
                    }
                    break;
                case 0x457:
                    if (!func_800DA298(0x373) && !func_800DA298(0x6B4) &&
                        !_glcutDll_entrypoint_20()) {
                        func_80108B04(actor, 1);
                    }
            }
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80802224_chalienkids, actor->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800D58_chalienkids(actor, arg) Actor *actor;
s32 arg;
{
    u8 *info;

    func_80101870(actor, (void *) arg);
    if (actor->unk7C_12) {
        info = func_80100094(actor, 0);
        if (*(Unk80132ED0 **) (info + 0x30)) {
            func_8010A764(func_80106790(*(Unk80132ED0 **) (info + 0x30)), arg);
        }
    }
}

void func_80800DB8_chalienkids(Actor *actor, s32 dialog_id, s32 arg)
{
    s32 in_table_a;
    s32 in_table_b;
    switch (dialog_id) {
        case 0x1284:
            ((f32 *) actor->actorData)[3] = 200.0f;
            func_80102424(actor, 15);
            _subaddieDll_entrypoint_4(actor, 1);
            _capod_entrypoint_14();
            _capod_entrypoint_13(actor->unk0, 0, 0x13, 0x2010);
            break;
        case 0x1285:
            actor->unk6C_0 = 5;
            ((f32 *) actor->actorData)[3] = 200.0f;
            func_80102424(actor, 15);
            _subaddieDll_entrypoint_4(actor, 1);
            _capod_entrypoint_14();
            _capod_entrypoint_13(actor->unk0, 0, 0x16, 0x2010);
            break;
        case 0x1286:
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80802234_chalienkids);
            func_80102424(actor, 12);
            _subaddiefade_entrypoint_5(actor);
            actor->unk58 = 2.0f;
            break;
        case 0x12CE:
            _capod_entrypoint_14();
            break;
        default:
            in_table_a =
                _subaddiedialog_entrypoint_9(actor, dialog_id, D_80801E60_chalienkids, 4) != 0;
            in_table_b =
                _subaddiedialog_entrypoint_9(actor, dialog_id, D_80801E80_chalienkids, 3) != 0;
            if (in_table_a || in_table_b) {
                func_80102424(actor, 16);
            } else if (_subaddiedialog_entrypoint_9(actor, dialog_id, D_80801EA8_chalienkids, 3)) {
                func_80102424(actor, 16);
            } else if (_subaddiedialog_entrypoint_9(actor, dialog_id, D_80801E98_chalienkids, 2)) {
                func_80102424(actor, 9);
            }
    }
}

void func_80800FA4_chalienkids(actor, marker_id, saved_flag, default_state) Actor *actor;
s32 marker_id;
s32 saved_flag;
s32 default_state;
{
    u8 *info;
    s32 all_saved;
    info = func_80100094(actor, 0);
    all_saved = func_800DA298(0x372) != 0;
    if (all_saved) {
        all_saved = func_800DA298(0x373) != 0;
        if (all_saved) {
            all_saved = func_800DA298(0x374) != 0;
        }
    }
    if (all_saved && !_glcutDll_entrypoint_20()) {
        func_800FFAB0(actor);
        return;
    }
    ((BitTest15 *) ((u8 *) actor + 0x94))->flag = 1;
    _subaddiemarker_entrypoint_1(actor, 0x154, marker_id, info, 1);
    if (_glcutDll_entrypoint_20()) {
        func_8010A85C(actor, 1);
        func_800EE7F8(actor->position, info);
        actor->rotation[1] = *(f32 *) (info + 0x10);
        func_80102424(actor, 0x10);
        func_80103014(actor);
        return;
    }
    if (!func_800DA298(0x376)) {
        ((BitTest15 *) ((u8 *) actor + 0x64))->flag = 0;
        func_80103110(actor, 0);
        return;
    }
    if (func_800DA298(saved_flag)) {
        func_8010A85C(actor, 1);
        func_800EE7F8(actor->position, info);
        actor->rotation[1] = *(f32 *) (info + 0x10);
        func_80102424(actor, 0x10);
        func_80103014(actor);
        return;
    }
    func_80102424(actor, default_state);
}

void func_80801138_chalienkids(Actor *actor)
{
    func_80801994_chalienkids(actor);
}

// Spawns the rotating ring of particles around the kid during beam-up; returns the timer-done flag.
int func_80801158_chalienkids(Actor *actor, s32 arg)
{
    f32 height;
    s32 done;
    f32 center[3];
    f32 ring_pos[3];
    f32 offset[3];
    f32 radius;
    f32 y_a;
    f32 y_b;
    f32 dt;
    f32 target[3];
    f32 angle;
    s32 emitter;
    s32 i;
    AlienRingState331 *ring;

    ring = func_80100094(actor, 0);
    done = func_800D9078(&actor->unk58);
    if (!_subaddieskeleton_entrypoint_0(actor, 3, center)) {
        func_800EE7F8(center, actor->position);
    }
    dt = func_800D8FF8();
    emitter = func_800B53A4(8);
    height = func_80103EF4(actor);
    radius = func_80103EAC(actor) * 1.25f;
    func_800EE7F8(target, center);
    target[1] += 0.5f * height;
    y_a = func_800F12D4(actor->unk58, 0.0f, 2.0f, height, 0.5f * height);
    y_b = func_800F12D4(actor->unk58, 0.0f, 2.0f, 0.5f * height, height);
    radius = func_800F12D4(actor->unk58, 0.0f, 2.0f, 0.25f * radius, radius);
    func_800BA3FC(emitter, arg);
    for (i = 0, angle = 0.0f; i != 4; i++, angle += 90.0f) {
        func_800EEB9C(offset, ring->angles[0] + angle, radius);
        func_800EE780(ring_pos, center, offset);
        ring_pos[1] += y_a + 10.0f * func_80013970(ring->angles[2] + angle);
        func_800BABB8(emitter, ring_pos, target, 1.0f, D_8080223C_chalienkids);
        func_800EEB9C(offset, ring->angles[1] + angle, radius);
        func_800EE780(ring_pos, center, offset);
        ring_pos[1] += y_b + 10.0f * func_80013970(ring->angles[3] + angle);
        func_800BABB8(emitter, ring_pos, target, 1.0f, D_8080223C_chalienkids);
    }
    ring->angles[0] = func_800136E4(ring->angles[0] - dt * 380.0f);
    ring->angles[1] = func_800136E4(ring->angles[1] + dt * 380.0f);
    ring->angles[2] += dt * 100.0f;
    ring->angles[3] += dt * 150.0f;
    if (done) {
        func_800FCAE0(0x1C, 0, 500);
    } else {
        func_800FCAE0(0x1C, -1, 500);
    }
    return done;
}

void func_808014B0_chalienkids(Actor *actor, s32 progress_flag)
{
    f32 *info;
    info = func_80100094(actor, 0);
    func_800EE7F8(actor->position, info);
    actor->rotation[1] = info[4];
    ((AlienKidFlags *) actor)->flag = 1;
    func_80103014(actor);
    func_80104E78(actor);
    func_800DA544(progress_flag);
}

void func_80801520_chalienkids(void *actor, s32 progress_flag)
{
    f32 timer_value;

    timer_value = 2.0f;
    *(f32 *) ((u8 *) actor + 0x58) = timer_value;
    _subaddiefade_entrypoint_2();
    _subaddieDll_entrypoint_4(actor, 1);
    func_8010A3E8(actor, 0x3F19999A);
    func_80102424(actor, 0xD);
    func_808014B0_chalienkids(actor, progress_flag);
}

void func_8080158C_chalienkids(Actor *actor)
{
    f32 pos[3];
    f32 size;
    f32 base_scale;

    base_scale = func_80103EAC(actor);
    size = func_8010A40C(actor) * base_scale;
    if (actor->unk64_16 && !func_8010A698(actor)) {
        if (_subaddieskeleton_entrypoint_0(actor, 3, pos)) {
            func_8008FB58(pos, 0.5f * size, size);
        }
    }
}

void func_80801628_chalienkids(actor) Actor *actor;
{
    s32 pad0;
    s32 saved;
    AlienKidLink *link;
    Actor *marker_actor;
    if (actor->unk7C_12) {
        link = func_80100094(actor, 0);
        saved = 0;
        if (link->marker) {
            marker_actor = func_80106790(link->marker);
        } else {
            marker_actor = 0;
        }
        if (marker_actor) {
            saved = func_8010A654(marker_actor, 0);
        }
        _chbadshad_entrypoint_2(actor, 3, (float) actor->scale * 1.4f, 0);
        if (marker_actor) {
            func_8010A654(marker_actor, saved);
        }
    }
}

void func_808016D4_chalienkids(Actor *actor)
{
    f32 dy;
    switch (actor->unk70_10) {
        case 0x12:
            if (func_800D9078((u8 *) actor + 0x58))
                func_80102424(actor, 0x13);
            return;
        case 0x13:
            if (func_80101DDC(actor)) {
                func_80102424(actor, 0x14);
                *(f32 *) ((u8 *) actor + 0x58) = func_80800D68_chalienkids[actor->unk6C_9];
            }
            break;
        case 0x14:
            if (func_800D9078((u8 *) actor + 0x58)) {
                func_80102424(actor, 0x15);
                *(f32 *) ((u8 *) actor + 0x34) = 50.0f;
                *(f32 *) ((u8 *) actor + 0x58) = 4.0f;
                *(f32 *) ((u8 *) actor + 0x28) = 0.5f;
            }
            break;
        case 0x15: {
            s32 done = func_800D9078((u8 *) actor + 0x58);
            *(f32 *) ((u8 *) actor + 0x34) += func_800D8FF8() * 100.0f;
            dy = func_800D8FF8();
            dy *= *(f32 *) ((u8 *) actor + 0x34);
            actor->position[1] += dy;
            if (func_800D9078((u8 *) actor + 0x28))
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 &D_80802260_chalienkids);
            if (done) {
                func_8010114C(*(s32 *) ((u8 *) actor + 0x3C), 0x4F, 0);
                func_800FFAB0(actor);
            }
        }
    }
}

void func_8080184C_chalienkids(u8 *actor, s32 choices, s32 count)
{
    _subaddiedialog_entrypoint_8(actor, actor + 4, D_8080226C_chalienkids, choices, count);
}

void func_80801884_chalienkids(Actor *actor)
{
    AlienKidAttachment *link;
    Actor *marker_actor;

    if (func_800D9078(&actor->unk58)) {
        link = func_80100094(actor, 0);
        func_80102424(actor, 3);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_8080227C_chalienkids);
        actor->unk64_16 = 1;
        actor->unk58 = 2.0f;
        _subaddiefade_entrypoint_2(actor);
        func_8010A800(actor, 0);
        if (link->marker) {
            marker_actor = func_80106790(link->marker);
            marker_actor->unk64_16 = 0;
            func_8010A590(marker_actor);
        }
    }
}

s32 func_8080193C_chalienkids(s32 actor)
{
    s32 expr;

    if (!func_80100094(actor, 1)) {
        expr = _suexpression_entrypoint_7(actor, 1, 0xB7);
        _suexpression_entrypoint_12(expr, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(expr, 0x3E8);
    }
}

void func_80801994_chalienkids(Actor *actor)
{
    if (func_80100094(actor, 1) != 0) {
        _suexpression_entrypoint_8(actor, 1);
    }
}

void func_808019C8_chalienkids(actor) u8 *actor;
{
    // Matching: the extra temporary copies the expression handle.
    s32 expr;
    s32 found;
    s32 anim_id;

if (*(u16 *) ((u8 *) actor + 0x64) & 1) {
    found = func_80100094(actor, 1);
    expr = found;
    if (found != 0) {
        anim_id = func_801022E4(actor);
        switch (anim_id) {
            case 0x325:
            case 0x326:
            case 0x329:
            case 0x32C:
            case 0x32E:
                break;
            default:
                _suexpression_entrypoint_18(expr, 1);
        }
        _suexpression_entrypoint_10(expr, *(s32 *) actor, 0);
    }
}

}

int func_80801A50_chalienkids(Actor *actor)
{
    func_80109F08(actor, 0x44);
    ((u8 *) (((char *) actor) + 0x7A))[0] =
        (((u8 *) (((char *) actor) + 0x7A))[0] & 0xFF3F) | 0x80;
}

void func_80801A88_chalienkids(Actor *actor)
{
    f32 pos[3];

if (actor->unk70_10 == 2) {
    if (_subaddieDll_entrypoint_6(actor, 10)) {
        func_8010A570(actor);
        func_800EE7F8(pos, actor->position);
        pos[1] -= 100.0f;
        _chexploder_entrypoint_3(actor, pos, 0);
    }
}

}

s32 func_80801B08_chalienkids(s32 actor, s32 arg)
{
    func_800DF744(3, 1);
    func_80101870(actor, arg);

}

s32 func_80801B40_chalienkids(Actor *actor, s32 msg, ActorCallbackData data)
{
    switch (msg) {
        case 0x40:
            if (_subaddieDll_entrypoint_5(actor, data.pointer)) {
                func_80103110(actor, 1);
                func_80101FDC(actor, 2);
            }
            break;
        case 0x90:
            func_80801BC4_chalienkids(actor);
            return 0;
        default:
            return 0;
    }

return 0;
}

void func_80801BC4_chalienkids(actor) Actor *actor;
{
    s32 flag;
    _chexploder_entrypoint_9(func_80106790(func_80101080()), 3, 2);
    func_8010114C(actor->unk3C, 0xA, 0);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80802284_chalienkids);
    flag = *(s32 *) ((u8 *) actor + 0x50);

if (flag) {
    func_800DA544(flag);
}

func_800FFAB0(actor);
}

// TU-NOTE: The .data of this overlay is defined in this file. Its tables point to functions
// of this file, and IDO's assembler schedules some of them differently unless the tables
// share the unit. Values come from the ROM.
extern void func_80105834();
extern void func_80107C2C();
extern void func_80108ED0();
u8 D_80801E60_chalienkids[32] = {0x0, 0x0,  0x2,  0x1,  0x12, 0xAB, 0x2,  0x0,  0x0, 0x0,  0x4,
                                 0x0, 0x12, 0xD6, 0x2,  0x0,  0x0,  0x0,  0x10, 0x0, 0x12, 0xD7,
                                 0x2, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xF,  0x3, 0x0};
u8 D_80801E80_chalienkids[24] = {0x0,  0x0,  0x6,  0x1,  0x12, 0xD6, 0x2, 0x0,
                                 0x0,  0x0,  0x10, 0x0,  0x12, 0xAC, 0x2, 0x0,
                                 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xF,  0x3, 0x0};
u8 D_80801E98_chalienkids[16] = {0x0, 0x0, 0x4, 0x0, 0x12, 0x82, 0x1, 0x0,
                                 0x0, 0x0, 0x4, 0x0, 0x12, 0x83, 0x2, 0x0};
u8 D_80801EA8_chalienkids[36] = {0x0,  0x0,  0x6,  0x1,  0x12, 0xAD, 0x2,  0x0,  0x0,
                                 0x0,  0x10, 0x0,  0x12, 0xD7, 0x2,  0x0,  0xFF, 0xFE,
                                 0xDF, 0xFF, 0x12, 0xF,  0x3,  0x0,  0x3F, 0x80, 0x0,
                                 0x0,  0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0x99, 0x99, 0x9A};
u32 D_80801ECC_chalienkids[44] = {
    0x0,        0x0,       0x0,        0x0,       0x0,        0x0,       0x40E947AE, 0x32A0001,
    0x40E947AE, 0x32A0001, 0x3FE00000, 0x32B0002, 0x0,        0x0,       0x0,        0x0,
    0x0,        0x0,       0x0,        0x0,       0x0,        0x0,       0x0,        0x0,
    0x40D8A3D7, 0x32C0001, 0x40D8A3D7, 0x32C0001, 0x40D8A3D7, 0x32C0201, 0x3F000000, 0x3290001,
    0x40D8A3D7, 0x32C0401, 0x40D8A3D7, 0x32C0001, 0x40D8A3D7, 0x32C0001, 0x40566666, 0x3280042,
    0x40566666, 0x3280084, 0x40566666, 0x3280084};
u32 D_80801F7C_chalienkids[44] = {
    0x0,        0x0,       0x0,        0x0,       0x0,        0x0,       0x41200000, 0x3230044,
    0x0,        0x0,       0x0,        0x0,       0x41200000, 0x3230044, 0x41200000, 0x3230044,
    0x41200000, 0x3240002, 0x0,        0x0,       0x0,        0x0,       0x0,        0x0,
    0x40D8A3D7, 0x3250001, 0x40D8A3D7, 0x3250001, 0x40D8A3D7, 0x3250201, 0x3F000000, 0x3260001,
    0x40D8A3D7, 0x3250001, 0x40D8A3D7, 0x3250001, 0x40D8A3D7, 0x3250001, 0x40566666, 0x3270042,
    0x40566666, 0x3270084, 0x40566666, 0x3270084};
u32 D_8080202C_chalienkids[44] = {
    0x0,        0x0,       0x0,        0x0,       0x0,        0x0,       0x40C00000, 0x32E0001,
    0x0,        0x0,       0x0,        0x0,       0x0,        0x0,       0x0,        0x0,
    0x0,        0x0,       0x40C00000, 0x32E0001, 0x40C00000, 0x32E0001, 0x4018F5C3, 0x32F0001,
    0x4018F5C3, 0x32F0001, 0x40AA8F5C, 0x32C0001, 0x4018F5C3, 0x32F0001, 0x0,        0x0,
    0x40AA8F5C, 0x32C0401, 0x40AA8F5C, 0x32C0001, 0x40AA8F5C, 0x32C0001, 0x40566666, 0x3270042,
    0x40566666, 0x3270084, 0x40566666, 0x3270084};
int D_808020DC_chalienkids[18] = {0x1580456,
                                  0x7F60001,
                                  (u32) &D_80801ECC_chalienkids,
                                  (u32) func_80800058_chalienkids,
                                  (u32) func_80105834,
                                  (u32) func_80800D58_chalienkids,
                                  0x7D00000,
                                  0x0,
                                  0x0,
                                  0x40040160,
                                  (u32) func_80801138_chalienkids,
                                  0x0,
                                  0x340000,
                                  (u32) func_80800030_chalienkids,
                                  (u32) func_80107C2C,
                                  -0x7FFF8BEE,
                                  (u32) func_80800648_chalienkids,
                                  0x0};
int D_80802124_chalienkids[18] = {0x1580457,
                                  0x7F50001,
                                  (u32) &D_80801F7C_chalienkids,
                                  (u32) func_808001D0_chalienkids,
                                  (u32) func_80105834,
                                  (u32) func_80800370_chalienkids,
                                  0x7D00000,
                                  0x0,
                                  0x0,
                                  0x40040160,
                                  (u32) func_80801138_chalienkids,
                                  0x0,
                                  0x340000,
                                  (u32) func_8080017C_chalienkids,
                                  (u32) func_80107C2C,
                                  -0x7FFF8BEE,
                                  (u32) func_80800648_chalienkids,
                                  0x0};
void *D_8080216C_chalienkids = (void *) 0x01580458;
static u32 D_8080216C_chalienkids_rest[17] = {0x7F70001,
                                              (u32) &D_8080202C_chalienkids,
                                              (u32) func_80800454_chalienkids,
                                              (u32) func_80105834,
                                              (u32) func_80800D58_chalienkids,
                                              0x7D00000,
                                              0x3FB33333,
                                              0x0,
                                              0x40040120,
                                              (u32) func_80801138_chalienkids,
                                              0x0,
                                              0x340000,
                                              (u32) func_80800408_chalienkids,
                                              (u32) func_80107C2C,
                                              0x80007412,
                                              (u32) func_80800648_chalienkids,
                                              0x0};
s32 D_808021B4_chalienkids[18] = {0xA80459,
                                  0x7F80001,
                                  0x0,
                                  (u32) func_80801A88_chalienkids,
                                  (u32) func_80105834,
                                  (u32) func_80801B08_chalienkids,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x804,
                                  0x0,
                                  (u32) func_80108ED0,
                                  0x0,
                                  (u32) func_80801A50_chalienkids,
                                  (u32) func_80107C2C,
                                  -0x7FFFD800,
                                  (u32) func_80801B40_chalienkids,
                                  0x0};
u8 D_808021FC_chalienkids[16] = {0x3, 0x71, 0x0, 0x0, 0x0, 0xFA, 0x0, 0xB7,
                                 0x0, 0x0,  0x0, 0xC, 0x6, 0x3C, 0xA, 0x0};
Vec3f D_8080220C_chalienkids = {-6.3e+03f, -1.8e+02f, -4.8e+03f};
Vec3f D_80802218_chalienkids = {-3.35e+03f, -3.4e+02f, -1.5e+02f};
f32 D_80802224_chalienkids[4] = {115.0f, 115.0f, 115.0f, 57.5f};
u8 D_80802234_chalienkids[8] = {0x0, 0x13, 0x4, 0xEE, 0x0, 0x2, 0x0, 0x0};
u8 D_8080223C_chalienkids[36] = {0x0, 0x16, 0x11, 0x4,  0x0, 0x22, 0x0, 0x40, 0x0, 0x59, 0x0, 0xA,
                                 0x0, 0xF,  0x0,  0x15, 0x0, 0x0,  0x0, 0x99, 0x0, 0x2B, 0x0, 0x26,
                                 0x0, 0x33, 0x0,  0x2D, 0x0, 0x32, 0x0, 0x64, 0x1, 0x1A, 0x0, 0x0};
s32 D_80802260_chalienkids[3] = {0x1305F1, 0xD00F3, 0x10C0000};
u8 D_8080226C_chalienkids[16] = {0x0, 0x0, 0x0, 0x0, 0x1, 0x5E, 0x0,  0xB7,
                                 0x0, 0x0, 0x0, 0xC, 0x6, 0x3C, 0x11, 0x0};
u8 D_8080227C_chalienkids[8] = {0x0, 0x13, 0x4, 0xED, 0x0, 0x2, 0x0, 0x0};
u8 D_80802284_chalienkids[28] = {0x0, 0x13, 0x4, 0x8D, 0x0, 0x18, 0x0, 0xD, 0x1, 0x33,
                                 0x1, 0x4C, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0,
                                 0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
