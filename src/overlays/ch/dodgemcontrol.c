// Witchyworld Dodgems minigame (1v1 to 1v3 and multiplayer): the game controller, the coloured
// target lights collected by driving into them, and the dodgem cars with physics and AI.
#include "common.h"

#define OD(n) (((f32 *) param_0->actorData)[n])
extern int D_80804DB4_chdodgemcontrol[];
extern void *func_80100094(Actor *, u32);
extern Actor *func_80106790();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    s32 v[4];
} Quad;
extern Quad D_80804DFC_chdodgemcontrol;
extern void func_800904C8(s32);
extern s32 _sumultiscore_entrypoint_2(s32 *, s32 *, s32 *, s32, s32);
typedef struct {
    u8 pad_0[0x10];
    s32 local_0[2];
} DodgemScores;
extern s32 D_80804D20_chdodgemcontrol[];
extern s32 D_80804D34_chdodgemcontrol[];
typedef struct {
    f32 value[3];
} DodgemVector;
extern u8 D_80804E0C_chdodgemcontrol[];
extern s32 func_800F0064(f32 *, f32, f32 *);
extern f32 func_800DC178(f32, f32);
extern f32 func_800EEF94(f32 *);
extern void func_800EF368(f32 *, f32);
typedef struct {
    f32 v[4];
} DodgemF4;
extern DodgemF4 D_80804E18_chdodgemcontrol;
typedef struct {
    f32 local_0[4][3];
} DodgemPositions;
extern DodgemPositions D_80804E28_chdodgemcontrol;
extern s32 D_80804D00_chdodgemcontrol[];
typedef struct {
    u8 pad[0x64];
    u8 pad_0 : 2;
    u8 flag_20 : 1;
    u8 mode : 2;
    u8 pad_1 : 2;
    u8 flag_1 : 1;
} DodgemFlags;
typedef struct {
    s32 a[12];
    u8 b[0x92];
    u8 count;
} DodgeS;
extern Actor *func_801084B0(s32, Actor **);
typedef struct {
    Unk80132ED0 *local_0[4];
    s32 local_1[4];
    u8 pad_0[0x10];
    u8 local_2[4];
} DodgemRacers61;
extern u8 D_80804E78_chdodgemcontrol[];
extern u8 D_80804EA4_chdodgemcontrol[];
typedef struct {
    s16 a, b;
} S16Pair;
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 rest72 : 10;
} DodgemState;
extern void func_80102424();
extern void _subaddiefade_entrypoint_5(DodgemState *);
extern f32 func_800D8FF8(void);
extern u32 D_80804EB4_chdodgemcontrol[3];
extern u32 D_80804EC0_chdodgemcontrol[3];
extern s16 D_80804ECC_chdodgemcontrol[];
extern int D_80804EDC_chdodgemcontrol[];
extern s32 D_80804F64_chdodgemcontrol[];
typedef struct {
    u8 pad_0[0x1C];
    f32 local_0;
} DodgemTimer1312;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} DodgemFlags1312;
extern void func_80018820(s32, f32, f32);
extern void func_80101CDC(Actor *, f32);
extern f32 func_800F1DCC(f32, f32);
extern int D_80804FAC_chdodgemcontrol[];
typedef struct {
    u8 pad0[0x34];
    f32 unk34[10][3];
    u8 unkAC[10];
    u8 unkB6[12];
    u8 unkC2;
    u8 padC3[2];
    u8 unkC5;
} DodgemLocal;
extern s32 func_800CEB54(s32, f32);
extern s32 func_800CEAD0(s32);
extern f32 func_800EEB40(f32 *, f32 *);
extern void _chscorepoints_entrypoint_2(s32, s32, f32 *, s32);
extern void func_80108B04(Actor *, s32);
extern f32 func_800DC0C0(void);
typedef struct {
    u8 pad_0[0x34];
    f32 local_0[10][3];
    u8 local_1[10];
    u8 pad_1[0xF];
    u8 local_2;
} DodgemOccupiedPositions;
extern void func_800CE8D8(s32, f32, s32);
typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0xAC - 0x14];
    u8 unkAC[0x15];
    u8 unkC1;
    u8 padC2;
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
    u8 unkC6;
} DodgemData_80800938_chdodgemcontrol;
extern s32 _capod_entrypoint_17(f32);
extern s32 func_800EA05C(void);
extern s32 func_800DA9E4(s32, s32);
extern s32 func_800D395C(void);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_800A54F8(s32);
extern void _subaddiemulti_entrypoint_4(s32);
extern s32 func_800D211C(s32);
extern void _subaddiefade_entrypoint_2();
extern void func_800C8CB8();
extern void func_800C8FB0();
extern u16 D_80804ED4_chdodgemcontrol[];
extern void func_800C8E54(s32, f32, f32);
typedef struct {
    f32 vel[3];
    f32 unkC;
    u8 pad10[8];
    f32 unk18;
} DodgemData_80802180_chdodgemcontrol;
extern f32 func_800138D0(f32);
extern f32 mlAbsF(f32);
extern void func_80102B2C(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
typedef struct {
    u8 pad[0x64];
    u32 b31 : 1;
    u32 b30 : 1;
    u32 b29 : 1;
    u32 mid : 8;
    u32 b20 : 1;
    u32 rest : 20;
} DCFlags;
extern u8 D_80804D10_chdodgemcontrol[];
extern u8 D_80804D48_chdodgemcontrol[];
extern u8 D_80804D5C_chdodgemcontrol[];
extern u8 D_80804D74_chdodgemcontrol[];
extern u8 D_80804D8C_chdodgemcontrol[];
extern u8 D_80804DA4_chdodgemcontrol[];
extern u8 D_80804F74_chdodgemcontrol[];
extern u8 D_80804F84_chdodgemcontrol[];
extern u8 D_80804F94_chdodgemcontrol[];
extern f32 func_800F11E4(f32, f32, f32, f32, f32);
extern void _subaddieaudioloop_entrypoint_4();
extern void func_800C31DC(s32, f32);
extern s32 func_800C3058(s32, s32);
extern void func_800C4B70(s32);
extern void func_8010D930();
extern s32 _subaddiejoy_entrypoint_2(u8 *, s32, f32 *);
extern s32 func_80101E14(u8 *, f32);
extern s32 func_80101E4C();
extern void _subaddieaudioquick_entrypoint_2();
extern u8 *func_80104248();
extern s32 anctrl_isStopped();
extern Vec3f D_80804FA0_chdodgemcontrol;
extern f32 func_80102D78(Actor *, void *);
extern int func_800EFFB4(f32 *, f32, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EFD24(f32 *);
int func_80801928_chdodgemcontrol();
void func_808019C4_chdodgemcontrol();
void func_80801A3C_chdodgemcontrol();
void func_808042A4_chdodgemcontrol();
void func_80803200_chdodgemcontrol();
void func_8080349C_chdodgemcontrol();
void func_808037C8_chdodgemcontrol();
void func_808039B8_chdodgemcontrol();
void func_8080476C_chdodgemcontrol();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080010C_chdodgemcontrol(),
    func_808013D0_chdodgemcontrol();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_8080440C_chdodgemcontrol(),
    func_8080455C_chdodgemcontrol();

void func_80800CA0_chdodgemcontrol(Actor *param_0);
void func_80800FC4_chdodgemcontrol(Actor *param_0, s32 param_1, s32 param_2);
void func_8080160C_chdodgemcontrol(Actor *param_0);
void func_808017F0_chdodgemcontrol();
Actor *func_80801844_chdodgemcontrol(Actor *param_0);
void func_80801A8C_chdodgemcontrol(Actor *param_0, s32 param_1);
void func_8080422C_chdodgemcontrol(Actor *param_0, s32 param_1);
f32 func_8080458C_chdodgemcontrol(Actor *param_0);
f32 func_8080460C_chdodgemcontrol(Actor *param_0);
f32 func_808046EC_chdodgemcontrol(u8 *param_0);

// Game controller: per-map setup, car spawning, countdown, scoring, HUD, result dialogs, exit.
int *chdodgemcontrol_entrypoint_0()
{
    return &D_80804DB4_chdodgemcontrol;
}

Actor *func_8080000C_chdodgemcontrol(Actor *actor, s32 index)
{
    return func_80106790(((Unk80132ED0 **) func_80100094(actor, 0))[index]);
}

// Dodgem car: drive physics, wall bounces, AI steering, animations, player riding.
// Sets the player's ride position/rotation relative to the actor.
void func_80800044_chdodgemcontrol(Actor *actor)
{
    f32 offset[3];
    f32 rot[3];

    func_800EFA4C(offset, 0.0f, 20.0f, 5.0f);
    func_800EF934(offset, offset, actor->rotation[1]);
    func_800EF04C(offset, actor->position);
    func_800EE7F8(rot, actor->rotation);
    func_800906B0(offset);
    func_800906DC(rot);
}

void func_808000B8_chdodgemcontrol(s32 index)
{
    Quad table = D_80804DFC_chdodgemcontrol;
    func_800904C8(table.v[index]);
}

void func_8080010C_chdodgemcontrol(this) Actor *this;
{
    DodgemLocal *local;
    s32 i;
    s32 alive;
    s32 j;
    s32 cnt;

    local = func_80100094(this, 0);
    switch ((s32) this->unk70_10) {
        case 1:
            func_8080160C_chdodgemcontrol(this);
        case 2:
            break;
        case 3:
            func_80801A8C_chdodgemcontrol(this, 0);
            if (!func_800CEB54(0, 6.0f) && func_800CEAD0(0)) {
                func_80800CA0_chdodgemcontrol(this);
            }
            alive = 0;
            // Matching: empty block steers IDO's register allocation.
            if (0) {
            }
            for (i = 0; i < local->unkC5; i++) {
                switch (local->unkAC[i]) {
                    case 1:
                        cnt = local->unkC2;
                        for (j = 0; j < cnt; j++) {
                            if (func_800EEB40(func_8080000C_chdodgemcontrol(this, j)->position,
                                              local->unk34[i]) < 22500.0f) {
                                switch (this->unk79_4) {
                                    case 0:
                                    case 1:
                                    case 2:
                                        if (j != 0) {
                                            local->unkAC[i] = 3;
                                            break;
                                        }
                                    case 3:
                                        _chscorepoints_entrypoint_2(local->unkB6[i] + 1, 0,
                                                                    local->unk34[i], 1);
                                        func_80800FC4_chdodgemcontrol(this, j, local->unkB6[i] + 1);
                                        local->unkAC[i] = 2;
                                }
                            }
                        }
                        break;
                    case 0:
                        alive = 1;
                }
            }
            if (alive) {
                func_80108B04(this, -1);
            }
            break;
        case 4:
            func_80801A8C_chdodgemcontrol(this, 1);
    }
}

s32 func_80800350_chdodgemcontrol(void)
{
    f32 roll = func_800DC0C0();

    if (roll < 0.5f) {
        return 0;
    }
    if (roll < 0.8333333135f) {
        return 1;
    }
    return 2;
}

void func_808003B0_chdodgemcontrol(pos) f32 *pos;
{
    pos[0] = func_800DC178(-645.0f, 645.0f);
    pos[1] = 0.0f;
    pos[2] = func_800DC178(-645.0f, 645.0f);
}

s32 func_8080040C_chdodgemcontrol(actor, pos, skip_index)
Actor *actor;
f32 *pos;
s32 skip_index;
{
    DodgemOccupiedPositions *data;
    s32 i;

    data = func_80100094(actor, 0);
    for (i = 0; i < data->local_2; i++) {
        if (i != skip_index && data->local_1[i] == 1 &&
            func_800EEB40(data->local_0[i], pos) < 40000.0f)
            return 0;

}
return 1;
}

void func_808004E4_chdodgemcontrol(s32 *actor, s32 index)
{
    u8 *data;
    f32 pos[3];
    u8 *light;
    s32 flag;

    light = func_801084B0(0x37F, &actor);
    data = func_80100094(actor, 0);
    *(s32 *) (light + 0x3C) = *actor;
    data[index + 0xAC] = 1;
    data[index + 0xB6] = func_80800350_chdodgemcontrol();
    ((Actor *) light)->unk6C_0 = index;
    // Matching: extra temporary and if (1) shape the code.
    flag = 1;
    if (1) {
        if (flag) {
            do {
                func_808003B0_chdodgemcontrol(pos);
            } while (func_8080040C_chdodgemcontrol(actor, pos, index) == 0);
        }

}
func_800EE7F8(light + 4, pos);
func_800EE7F8(data + 0x34 + index * 12, light + 4);
}

int func_808005CC_chdodgemcontrol(s32 mode)
{
    switch (mode) {
        case 0:
            return 0x2D;
        case 1:
            return 0x2D;
        case 2:
            return 0x2D;
        case 3:
            return 0x3C;
        default:
            return 0;
    }
}

int func_8080061C_chdodgemcontrol(args, dialog_id, flags)
s32 *args;
{
    flags |= 6;
    switch (dialog_id) {
        case 0x10D9:
        case 0x10DA:
            func_800FC6B0(0x10);
            func_800FDC28(0);
            break;
        case 0x10D4:
        case 0x10D5:
        case 0x10D6:
        case 0x10EC:
        case 0x10EE:
        case 0x10F0:
            func_800FC6B0(0x16);
            func_800FDC28(0);
            break;
        case 0x10D7:
        case 0x10ED:
        case 0x10EF:
        case 0x10F1:
            func_800FC6B0(0x17);
            func_800FDC28(0);
    }
    _subaddiedialog_entrypoint_11(args[0], dialog_id, flags, &args[1], 0x22);
}

void func_808006CC_chdodgemcontrol(Actor *actor, s32 dialog_id, s32 choice)
{
    s32 pad[2];
    s32 time;
    u8 *data;

    data = func_80100094(actor, 0);
    switch (dialog_id) {
        case 0x10D9:
        case 0x10DA:
            _gcfrontend_entrypoint_10();
            return;
        case 0x10FC:
            func_8080061C_chdodgemcontrol(actor, 0x10D3, 0, dialog_id);
            return;
        case 0x10D3:
        case 0x10EB:
            time = func_808005CC_chdodgemcontrol(actor->unk79_4);
            func_800CE8D8(0, (f32) time, func_808005CC_chdodgemcontrol(actor->unk79_4));
            func_800CE88C(0, 1);
            func_808019C4_chdodgemcontrol(actor, 0);
            actor->unk70_10 = 3;
            func_800FDC28(12);
            return;
        case 0x10D4:
            func_800DA3B8(0xA9, 1);
            _gcgoto_entrypoint_1(0xDD, 5);
            return;
        case 0x10D5:
            func_800DA3B8(0xAA, 1);
            _gcgoto_entrypoint_1(0xDD, 5);
            return;
        case 0x10D6:
            func_800DA3B8(0xB0, 1);
            _gcgoto_entrypoint_1(0xDD, 5);
            return;

case 0xCEB:
    if (func_800D395C()) {
        if (choice == 1) {
            _gcfrontend_entrypoint_11();
            return;
        }
        _gcfrontend_entrypoint_10();
        return;
    }

if (choice == 1) {
    _gcgoto_entrypoint_1(func_800EA05C(), 1);
    return;
}

_gcgoto_entrypoint_1(0xDD, 5);
return;
case 0x10D7:
case 0x10EC:
case 0x10ED:
case 0x10EE:
case 0x10EF:
case 0x10F0:
case 0x10F1:
    func_8080061C_chdodgemcontrol(actor, 0xCEB, 0x40, dialog_id);
    return;
case 0x10BB:
case 0x10BC:
case 0x10BD:
    data[0xC4] = 1;
    }
    }

    s32 func_808008EC_chdodgemcontrol(u8 *actor)
    {
        u32 mode;
        mode = (unsigned short) actor[0x79];
        mode = mode >> 4;
        switch (mode) {
            case 0:
                return 0x3C;

            case 1:
                return 0x32;

            case 2:
                return 0x28;

            default:
                return 0;
        }
    }

    s32 func_80800938_chdodgemcontrol(actor, msg, msg_data)
    Actor *actor;
    s32 msg;
    s32 msg_data;
    {
        DodgemData_80800938_chdodgemcontrol *data;
        s32 map_id;
        s32 i;

        data = func_80100094(actor, 0);
        switch (msg) {
            case 0x0B:
                data->unkC3 = 1;
                return 3;

case 0x0E:
    switch (actor->unk79_4) {
        case 0:
            if (_capod_entrypoint_17(0.5f)) {
                func_80801A3C_chdodgemcontrol(actor, 1, 2);
            }
            break;
        case 1:
            if (_capod_entrypoint_17(0.5f)) {
                func_80801A3C_chdodgemcontrol(actor, 2, 2);
            }
            break;
        case 2:
            if (_capod_entrypoint_17(0.5f)) {
                func_80801A3C_chdodgemcontrol(actor, 3, 2);
            }
    }

return 3;
case 0x49:
    actor = func_80801844_chdodgemcontrol(actor);
    map_id = func_800EA05C();

if (map_id == 0xDE) {
} else if (map_id == 0xDF) {

}
else if (map_id == 0xE0)
{
}
else if (map_id == 0xE1)
{
}
else if (map_id == 0xE2)
{
}
switch (actor->unk79_4) {
    case 0:
    case 1:
    case 2:
        if (!func_800DA9E4(actor->unk79_4 + 0x419, 1) && !func_800D395C()) {
            _capod_entrypoint_13(actor->unk0, 0, 1, 0x2020);
            data->unkC6 = 1;
        } else {

data->unkC4 = 1;
data->unkC3 = 1;
func_800A54F8(0);
}
break;
case 3:
    data->unkC4 = 1;
    data->unkC3 = 1;
    _subaddiemulti_entrypoint_4(0);
    }
    break;
case 0x2E:
    func_808006CC_chdodgemcontrol(actor, ((s16 *) &msg_data)[0], ((s16 *) &msg_data)[1]);
    break;
case 0x30:
    switch (((s16 *) &msg_data)[0]) {
        case 0x10FC:
            if (((s16 *) &msg_data)[1] == 0) {
                return func_808008EC_chdodgemcontrol(actor);

}
return func_808005CC_chdodgemcontrol(actor->unk79_4);
case 0x10D9:
    return data->unkC1;
case 0x10D4:
case 0x10D5:
case 0x10D6:
case 0x10EC:
case 0x10EE:
case 0x10F0:
    return data->unk10;
case 0x10ED:
    return func_800D211C(0x8A);
case 0x10EF:
    return func_800D211C(0x8B);
case 0x10F1:
    return func_800D211C(0x8C);
case 0x10D7:
    return func_808008EC_chdodgemcontrol(actor);
    }
    break;
case 0x3D:
    if (msg_data == -1) {
        for (i = 0; i < data->unkC5; i++) {
            if (!data->unkAC[i]) {
                func_808004E4_chdodgemcontrol(actor, i);
                break;
            }

}
}
break;
default:
    return 0;
    }
    return 1;
    }

    void func_80800CA0_chdodgemcontrol(Actor *actor)
    {
        u8 *data;
        s16 dialog_id;
        s32 won[4];
        s32 unk_0[4];
        s32 winner;
        s32 i;

        data = func_80100094(actor, 0);
        actor->unk70_10 = 4;
        func_808019C4_chdodgemcontrol((s32) actor, 1);
        if (actor->unk64_19) {
            switch (actor->unk79_4) {
                case 0:
                    dialog_id =
                        func_800D2054(0, 0x8A, *(s32 *) (data + 0x10)) == 1 ? 0x10EC : 0x10ED;
                    func_8080061C_chdodgemcontrol(actor, dialog_id, 0);
                    break;
                case 1:
                    dialog_id =
                        func_800D2054(0, 0x8B, *(s32 *) (data + 0x10)) == 1 ? 0x10EE : 0x10EF;
                    func_8080061C_chdodgemcontrol(actor, dialog_id, 0);
                    break;
                case 2:
                    dialog_id =
                        func_800D2054(0, 0x8C, *(s32 *) (data + 0x10)) == 1 ? 0x10F0 : 0x10F1;
                    func_8080061C_chdodgemcontrol(actor, dialog_id, 0);
            }
        } else {
            switch (actor->unk79_4) {
                case 0:
                    if (*(s32 *) (data + 0x10) >= func_808008EC_chdodgemcontrol(actor)) {
                        dialog_id = 0x10D4;
                        func_800D2054(0, 0x8A, *(s32 *) (data + 0x10));
                    } else {
                        dialog_id = 0x10D7;
                    }
                    func_8080061C_chdodgemcontrol(actor, dialog_id, 0);
                    break;
                case 1:
                    if (*(s32 *) (data + 0x10) >= func_808008EC_chdodgemcontrol(actor)) {
                        dialog_id = 0x10D5;
                        func_800D2054(0, 0x8B, *(s32 *) (data + 0x10));
                    } else {
                        dialog_id = 0x10D7;
                    }
                    func_8080061C_chdodgemcontrol(actor, dialog_id, 0);
                    break;
                case 2:
                    if (*(s32 *) (data + 0x10) >= func_808008EC_chdodgemcontrol(actor)) {
                        dialog_id = 0x10D6;
                        func_800D2054(0, 0x8C, *(s32 *) (data + 0x10));
                    } else {
                        dialog_id = 0x10D7;

}
func_8080061C_chdodgemcontrol(actor, dialog_id, 0);
break;
case 3:
    winner =
        _sumultiscore_entrypoint_2((s32 *) (data + 0x10), won, unk_0, 0, data[0xC2]);
    for (i = 0; i < data[0xC2]; i++) {
        if (won[i] == 1) {
            ((s32 *) (data + 0x20))[i] = 1;
        } else {

((s32 *) (data + 0x20))[i] = 0;
}
}
if (winner) {
    dialog_id = 0x10D9;
    data[0xC1] = winner;
    func_800FC6B0(0x16);
} else {
    dialog_id = 0x10DA;
    func_800FC6B0(0x17);
}
func_8080061C_chdodgemcontrol(actor, dialog_id, 0);
}
}
}

void func_80800FC4_chdodgemcontrol(Actor *actor, s32 car, s32 delta)
{
    DodgemScores *scores;

    scores = func_80100094(actor, 0);
    if (actor->unk70_10 == 3 && (delta >= 0 || scores->local_0[car] >= -delta)) {
        scores->local_0[car] += delta;
        if (delta > 0) {
            if (car == 0)
                func_8010D930(4, 0, actor->position, &D_80804D34_chdodgemcontrol);
        } else {
            if (car == 0)
                func_8010D930(5, 0, actor->position, &D_80804D20_chdodgemcontrol);
        }
    }
}

s32 func_80801084_chdodgemcontrol(f32 *pos_a, f32 *pos_b, f32 radius)
{
    DodgemVector push;
    f32 orig_a[3];
    f32 orig_b[3];
    f32 y_b;
    f32 y_a;
    if (func_800F0064(pos_a, radius, pos_b)) {
        push = *(DodgemVector *) D_80804E0C_chdodgemcontrol;
        y_b = pos_b[1];
        y_a = pos_a[1];
        func_800EE7F8(orig_a, pos_a);
        func_800EE7F8(orig_b, pos_b);
        if (pos_b[0] == pos_a[0] && pos_b[2] == pos_a[2]) {
            pos_b[0] += func_800DC178(-5.0f, 5.0f);
            pos_b[2] += func_800DC178(-5.0f, 5.0f);
        }
        push.value[0] = pos_a[0] - pos_b[0];
        push.value[1] = pos_a[1] - pos_b[1];
        push.value[2] = pos_a[2] - pos_b[2];
        func_800EF368(push.value, func_800EEF94(push.value) + 5.0f);
        func_800EFB24(pos_b, orig_a, push.value);
        func_800EE780(pos_a, orig_b, push.value);
        pos_b[1] = y_b;
        pos_a[1] = y_a;
        return 1;
    }
    return 0;
}

f32 func_80801214_chdodgemcontrol(s32 index)
{
    DodgemF4 table = D_80804E18_chdodgemcontrol;
    return table.v[index];
}

void func_80801258_chdodgemcontrol(s32 index, f32 *out_pos)
{
    DodgemPositions table = D_80804E28_chdodgemcontrol;
    func_800EE7F8(out_pos, table.local_0[index]);
}

void func_808012C8_chdodgemcontrol(Actor *actor, s32 flag)
{
    if (flag || func_800D395C()) {
        actor->unk64_19 = 1;
        _chintrotext_entrypoint_1(0x18B1, actor->unk79_4 + 0x12, 0, 0);
    } else {
        actor->unk64_19 = 0;
        _chintrotext_entrypoint_2(1);
    }
}

int func_80801344_chdodgemcontrol(Actor *actor)
{
    char *mode_ptr;
    unsigned int mode;
    u32 mode_switch;
    mode_ptr = ((char *) actor) + 0x79;
    mode = *((u8 *) mode_ptr);
    mode = mode >> 4;
    mode_switch = mode;
    switch (mode_switch) {
        case 0:

        case 1:

        case 2:
            func_800D2748(0xC3, 0x5B);
            break;

        case 3:
            func_800D2748(0xC3, 0x23);
    }

    func_800D2748(0xC4, 0x24);
    func_800D2748(0xC5, 0x25);
    func_800D2748(0xC6, 0x26);
}

void func_808013D0_chdodgemcontrol(actor) Actor *actor;
{
    u8 *data;
    s32 i;

    data = func_80100094(actor, 0);
    if (!func_800D211C(0x8A)) {
        func_800D2054(0, 0x8A, 3);
        func_800D2054(0, 0x8B, 3);
        func_800D2054(0, 0x8C, 3);
    }
    switch (func_800EA05C()) {
        case 0xDE:
            actor->unk79_4 = 0;
            data[0xC5] = 3;
            func_808012C8_chdodgemcontrol(actor, func_800DA298(0xAC));
            data[0xC2] = D_80804D00_chdodgemcontrol[actor->unk79_4];
            break;
        case 0xDF:
            actor->unk79_4 = 1;
            data[0xC5] = 3;
            func_808012C8_chdodgemcontrol(actor, func_800DA298(0xAD));
            data[0xC2] = D_80804D00_chdodgemcontrol[actor->unk79_4];
            break;
        case 0xE0:
            actor->unk79_4 = 2;
            data[0xC5] = 3;
            func_808012C8_chdodgemcontrol(actor, func_800D0A9C(0x16, 1));
            data[0xC2] = D_80804D00_chdodgemcontrol[actor->unk79_4];
            break;
        case 0x186:
            for (i = 0; i < 8; i++) {
                if (func_800F6438(i)) {
                    func_800F4CEC(i, 0);
                }
            }
            actor->unk79_4 = 3;
            data[0xC2] = _gcstatusDll_entrypoint_11();
            data[0xC5] = 3;
    }
    if (data[0xC5] >= 11) {
        data[0xC5] = 10;
    }
    data[0xC3] = 0;
    func_808017F0_chdodgemcontrol(actor);
    func_800BF744(1, 1);
    func_80801344_chdodgemcontrol(actor);
}

void func_808015E8_chdodgemcontrol(actor) u8 *actor;
{
    u32 t = (u32) actor[0x79] >> 4;
    if (t != 0 && t != 1) {
        if (t && t) {
        }
    }
}

void func_8080160C_chdodgemcontrol(Actor *actor)
{
    u8 *data;
    s32 i;
    s32 dialog_id;

    data = func_80100094(actor, 0);
    if (!func_800DA298(0x6AD)) {
        for (i = 0; i < data[0xC2]; i++) {
            if (!data[0x30 + i]) {
                return;
            }
        }
        if (data[0xC3] && data[0xC4]) {
            if (data[0xC6]) {
                _capod_entrypoint_14(data[0xC2], data);
            }
            switch (actor->unk79_4) {
                case 0:
                case 1:
                case 2:
                    func_800A54F8(0);
                case 3:
                    break;
            }
            func_800BF744(1, 0);
            if (actor->unk79_4 == 3) {
                dialog_id = 0x10EB;
            } else {
                dialog_id = !actor->unk64_19 ? 0x10FC : 0x10D3;
            }
            func_8080061C_chdodgemcontrol(actor, dialog_id, 0);
            actor->unk70_10 = 2;
        }
    }
}

void func_80801744_chdodgemcontrol(Actor *controller, Actor *car)
{
    switch (controller->unk79_4) {
        case 0:
        case 1:
        case 2:
            switch (car->unk6C_0) {
                case 0:
                    ((DodgemFlags *) car)->flag_20 = 1;
                    ((DodgemFlags *) car)->mode = 0;
                    break;
                case 1:
                    ((DodgemFlags *) car)->flag_1 = 1;
            }
            break;
        case 3:
            ((DodgemFlags *) car)->flag_20 = 0;
            ((DodgemFlags *) car)->mode = car->unk6C_0;
    }
}

void func_808017F0_chdodgemcontrol(actor) Actor *actor;
{
    DodgeS *data = func_80100094(actor, 0);
    s32 i;
    for (i = 0; i < data->count; i++) {
        data->b[i] = 0;
        data->a[i] = 0;
    }
}

Actor *func_80801844_chdodgemcontrol(Actor *actor)
{
    u32 mode;
    s32 i;
    Unk80132ED0 **car_ids;
    s32 car_count;
    Actor *car;
    void *data;

    mode = actor->unk79_4;
    data = func_80100094(actor, 0);
    car_count = *(u8 *) ((u8 *) data + 0xC2);
    i = 0;
    car_ids = data;
    for (; i < car_count; i++, car_ids++) {
        car = func_801084B0(0x305, &actor);
        car->unk3C = actor->unk0;
        *car_ids = car->unk0;
        car->unk79_4 = mode;
        func_80801928_chdodgemcontrol(actor, i);
        func_80108944(car, actor);
        func_80801744_chdodgemcontrol(actor, car);
    }
    return actor;
}

int func_80801928_chdodgemcontrol(actor, index)
Actor *actor;
s32 index;
{
    DodgemRacers61 *data;
    Actor *car;

    data = func_80100094(actor, 0);
    car = func_80106790(data->local_0[index]);
    func_80801258_chdodgemcontrol(index, car->position);
    car->rotation[1] = func_80801214_chdodgemcontrol(index);
    car->unk54 = car->rotation[1];
    car->unk6C_0 = index;
    data->local_1[index] = 0;
    data->local_2[index] = 1;
}

void func_808019C4_chdodgemcontrol(actor, arg) s32 actor;
s32 arg;
{
    s32 i;
    u8 *data;

    data = func_80100094(actor, 0);
    i = 0;
    if ((s32) (*(u8 *) ((s8 *) (data) + (0xC2))) > 0) {
        do {
            func_80801A3C_chdodgemcontrol(actor, i, arg);
            i += 1;
        } while (i < (s32) (*(u8 *) ((s8 *) (data) + (0xC2))));
    }
}

void func_80801A3C_chdodgemcontrol(actor, index, arg) s32 actor;
s32 index;
s32 arg;
{
    s32 *cars;
    cars = (s32 *) func_80100094(actor, 0);
    if (cars[index] != 0) {
        func_808042A4_chdodgemcontrol((void *) cars[index], arg);
    }
}

void func_80801A8C_chdodgemcontrol(Actor *actor, s32 flag)
{
    u8 *data;
    s32 hud_count;
    s32 i;
    s32 slot;

    data = func_80100094(actor, 0);
    switch (actor->unk79_4) {
        case 0:
        case 1:
        case 2:
            hud_count = 1;
            break;
        case 3:
            hud_count = data[0xC2];
    }
    for (i = 0; i < hud_count; i++) {
        slot = i + 0xC3;
        if (!data[0xC0]) {
            func_800D2770(slot, 0);
        } else {
            func_800D24E8(slot, ((s32 *) (data + 0x10))[i], 0);
        }
        if (flag && ((s32 *) (data + 0x20))[i]) {
            func_800D28A0(slot);
        }
    }
    data[0xC0] = 1;
}

// Coloured target light: fades in and out, point light, timeout, collect burst.
void func_80801B94_chdodgemcontrol(s32 param_0, s32 param_1)
{
    s32 handle;
    f32 pos[3];

    handle = func_800B53A4(0xC);
    func_80103DFC(param_0, &pos);
    func_800BABB8(handle, &pos, &pos, 0x3F800000, &D_80804E78_chdodgemcontrol);
    func_800BA3FC(handle, param_1);
    func_800BA22C(handle, 0xC);
    _subaddieaudioquick_entrypoint_2(param_0, &pos, &D_80804EA4_chdodgemcontrol);
}

void func_80801C18_chdodgemcontrol(light, param_1, param_2) DodgemState *light;
S16Pair param_1;
s32 param_2;
{
    func_80102424(light, param_2);
    if (light->f72 == 3) {
        _subaddiefade_entrypoint_5(light);
    }
}

void func_80801C60_chdodgemcontrol(Actor *light)
{
    Actor *controller;
    u8 *data;
    u32 colors_a[3];
    u32 colors_b[3];
    u8 *slot;

    controller = func_80106790(light->unk3C);
    data = func_80100094(controller, 0);
    switch (light->unk70_10) {
        case 1:
            _subaddiefade_entrypoint_6(light, 7);
            if (_subaddiefade_entrypoint_0(light) == 255) {
                func_80801C18_chdodgemcontrol(light, controller, 2);
            }
            break;
        case 2:
            if (light->unk58 > 0.0f) {
                light->unk58 -= func_800D8FF8();
            } else {
                func_80801C18_chdodgemcontrol(light, controller, 3);
            }
            break;
        case 3:
            _subaddiefade_entrypoint_6(light, -7);
    }
    switch (light->unk70_10) {
        case 3:
            *(Vec3f *) colors_a = *(Vec3f *) D_80804EB4_chdodgemcontrol;
            colors_a[data[light->unk6C_0 + 0xB6]] = _subaddiefade_entrypoint_0(light);
            func_800C8E84(((s32 *) light)[0x50 / 4], colors_a);
            if (_subaddiefade_entrypoint_0(light) == 0) {
                data[light->unk6C_0 + 0xAC] = 0;
                func_800FFAB0(light);
            }
            break;
        case 1:
            *(Vec3f *) colors_b = *(Vec3f *) D_80804EC0_chdodgemcontrol;
            colors_b[data[light->unk6C_0 + 0xB6]] = _subaddiefade_entrypoint_0(light);
            func_800C8E84(((s32 *) light)[0x50 / 4], colors_b);
    }
    if ((s32) light->unk70_10 < 3) {
        slot = (u8 *) ((s32) data + light->unk6C_0);
        switch (slot[0xAC]) {
            case 2:
                func_80801B94_chdodgemcontrol(light, D_80804ECC_chdodgemcontrol[slot[0xB6]]);
                data[light->unk6C_0 + 0xAC] = 0;
                func_800FFAB0(light);
                break;
            case 3:
                slot[0xAC] = 0;
                func_800FFAB0(light);
        }
    }
}

void func_80801F00_chdodgemcontrol(Actor *light)
{
    s32 handle;
    handle = *((s32 *) (((char *) light) + 0x50));
    if (handle != 0) {
        func_800C8B84(handle, *((s32 *) (((char *) light) + 0x50)));
    }
}

void func_80801F2C_chdodgemcontrol(Actor *light)
{
    s32 pad0;
    u8 *data;
    data = func_80100094(func_80106790(light->unk3C), 0);
    light->scale = 0.8f;
    func_801032B0(light, D_80804ED4_chdodgemcontrol[((0, data))[0xB6 + light->unk6C_0]],
                  *((u16 *) (((u8 *) light->unk0) + 0x16)));
    *((s32 *) (((u8 *) light) + 0x50)) = func_800C8A98();
    func_800C8E54(*((s32 *) (((u8 *) light) + 0x50)), light->scale * 500.0f,
                  light->scale * 800.0f);
    func_800C8FB0(*((s32 *) (((u8 *) light) + 0x50)), 0, 0, 0);
    func_800C8CB8(*((s32 *) (((u8 *) light) + 0x50)), light->position);
    _subaddiefade_entrypoint_2(light);
    switch (light->unk6C_0) {
        case 0:
            *((f32 *) (((u8 *) light) + 0x58)) = 6.0f;
            break;

        case 1:
            *((f32 *) (((u8 *) light) + 0x58)) = 5.0f;
            break;

        case 2:
            *((f32 *) (((u8 *) light) + 0x58)) = 4.0f;
    }

    data[0xC4] = 0;
    data[0xC6] = 0;
}

int chdodgemcontrol_entrypoint_1()
{
    return (int) &D_80804EDC_chdodgemcontrol;
}

int func_8080207C_chdodgemcontrol(car, msg, msg_data)
Actor *car;
s32 msg;
s32 msg_data;
{
    switch (msg) {
        case 0x1F:
            func_801015D0(car);
            func_800DF744(3, D_80804F64_chdodgemcontrol[car->unk6C_0]);
            func_800DF744(4, D_80804F64_chdodgemcontrol[car->unk6C_0]);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80802104_chdodgemcontrol(Actor *car)
{
    DodgemTimer1312 *state;

    state = func_80100094(car, 0);
    if (!(state->local_0 > 0.0f)) {
        state->local_0 = 1.5f;
        if (car->unk6C_0 == 0 || ((DodgemFlags1312 *) car)->local_0) {
            func_80018820(car->unk6C_0, 0.5f, 1.0f);
        }
    }
}

void func_80802180_chdodgemcontrol(Actor *param_0)
{
    DodgemData_80802180_chdodgemcontrol *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[3];
    f32 local_7[3];
    f32 local_8[3];
    f32 local_9[3];
    f32 local_10[3];

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D8FF8();
    local_2 = func_800F1DCC(param_0->rotation[1], param_0->unk54);
    OD(3) *= 0.95f;
    local_2 = mlAbsF(func_800138D0(local_2));
    local_3 = func_808046EC_chdodgemcontrol(param_0) * (1.1f - local_2) * local_1;
    local_0->unkC *= 0.8f;
    func_800EEB9C(local_4, param_0->rotation[1], -40.0f);
    func_800EF04C(param_0->position, local_4);
    if (!func_80102CF4(param_0, local_3)) {
        func_80102B2C(param_0, local_3);
    }
    param_0->rotation[1] += local_0->unkC;
    func_800EEB9C(local_4, param_0->rotation[1], 40.0f);
    func_800EF04C(param_0->position, local_4);
    func_800EEB9C(local_6, param_0->rotation[1], 48.75f);
    func_800EF04C(local_6, param_0->position);
    func_800EEB9C(local_5, param_0->rotation[1], OD(3));
    func_800EF04C(local_5, local_0->vel);
    if (local_5[0] < 0.0f) {
        local_5[0] = -local_5[0];
    }
    if (local_5[2] < 0.0f) {
        local_5[2] = -local_5[2];
    }
    if (param_0->position[0] < -629.0f) {
        param_0->position[0] = -629.0f;
        func_800EEB9C(local_0->vel, 90.0f, local_5[0] * 1.25f);
        OD(3) = 0.0f;
        func_80802104_chdodgemcontrol(param_0);
    }
    if (local_6[0] < -655.0f) {
        local_6[0] = -655.0f;
        func_800EEB9C(local_7, param_0->rotation[1], 48.75f);
        param_0->position[0] = local_6[0] - local_7[0];
        func_800EEB9C(local_0->vel, 90.0f, local_5[0] * 1.25f);
        OD(3) = 0.0f;
        func_80802104_chdodgemcontrol(param_0);
    }
    if (param_0->position[0] > 629.0f) {
        param_0->position[0] = 629.0f;
        func_800EEB9C(local_0->vel, 270.0f, local_5[0] * 1.25f);
        OD(3) = 0.0f;
        func_80802104_chdodgemcontrol(param_0);
    }
    if (local_6[0] > 655.0f) {
        local_6[0] = 655.0f;
        func_800EEB9C(local_8, param_0->rotation[1], 48.75f);
        param_0->position[0] = local_6[0] - local_8[0];
        func_800EEB9C(local_0->vel, 270.0f, local_5[0] * 1.25f);
        OD(3) = 0.0f;
        func_80802104_chdodgemcontrol(param_0);
    }
    if (param_0->position[2] > 629.0f) {
        param_0->position[2] = 629.0f;
        func_800EEB9C(local_0->vel, 180.0f, local_5[2] * 1.25f);
        OD(3) = 0.0f;
        func_80802104_chdodgemcontrol(param_0);
    }
    if (local_6[2] > 655.0f) {
        local_6[2] = 655.0f;
        func_800EEB9C(local_9, param_0->rotation[1], 75.0f);
        param_0->position[2] = local_6[2] - local_9[2];
        func_800EEB9C(local_0->vel, 180.0f, local_5[2] * 1.25f);
        OD(3) = 0.0f;
        func_80802104_chdodgemcontrol(param_0);
    }
    if (param_0->position[2] < -629.0f) {
        param_0->position[2] = -629.0f;
        func_800EEB9C(local_0->vel, 0.0f, local_5[2] * 1.25f);
        OD(3) = 0.0f;
        func_80802104_chdodgemcontrol(param_0);
    }
    if (local_6[2] < -655.0f) {
        local_6[2] = -655.0f;
        func_800EEB9C(local_10, param_0->rotation[1], 48.75f);
        param_0->position[2] = local_6[2] - local_10[2];
        func_800EEB9C(local_0->vel, 0.0f, local_5[2] * 1.25f);
        OD(3) = 0.0f;
        func_80802104_chdodgemcontrol(param_0);
    }
    func_800EEB9C(&OD(4), param_0->rotation[1], OD(3));
    func_800EF04C(&OD(4), local_0->vel);
    func_800EF334(&OD(4), local_1);
    func_800EF04C(param_0->position, &OD(4));
    func_800EF334(local_0->vel, 0.7f);
    if (local_0->unk18 != 0.0f) {
        local_0->unk18 -= local_1;
    }
    func_808039B8_chdodgemcontrol(param_0);
}

void func_808026D0_chdodgemcontrol(s32 param_0)
{
    anctrl_setPlaybackType(func_80104248(), 1);
    func_8008B188(func_80104248(param_0), 1);
    anctrl_start(func_80104248(param_0));
}

void func_80802720_chdodgemcontrol(Actor *param_0)
{
    int local_0;
    local_0 = func_80104248();
    anctrl_setIndex(local_0, 0x105);
    func_80101CDC(param_0, 10000000.0f);
    func_808026D0_chdodgemcontrol(param_0);
}

void func_80802764_chdodgemcontrol(Actor *this)
{
    s32 new_var;
    int new_var2;
    int new_var3;
    anctrl_setIndex(func_80104248(), 0x10B);
    func_80101CDC(this, 0.9f);
    func_808026D0_chdodgemcontrol(this);
    new_var3 = (*((s32 *) (((char *) this) + 0x64))) & 0xFFFFFFFFFFFFFFFFu;
    new_var2 = (new_var3 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
    new_var2 = new_var2 & 0xFFFFFFFFFFFFFFFFu;
    if (0 != ((new_var =
                   ((new_var2 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
              0x100000)) {
        func_808000B8_chdodgemcontrol(0);
    }
}

void func_808027C4_chdodgemcontrol(Actor *param_0)
{
    anctrl_setIndex(func_80104248(), 0x108);
    func_80101CDC(param_0, 0.9f);
    func_808026D0_chdodgemcontrol(param_0);
    if (param_0->unk64_20) {
        func_808000B8_chdodgemcontrol(1);
    }
}

void func_80802824_chdodgemcontrol(Actor *param_0)
{
    anctrl_setIndex(func_80104248(), 0x109);
    func_80101CDC(param_0, 0.9f);
    func_808026D0_chdodgemcontrol(param_0);
    if (param_0->unk64_20) {
        func_808000B8_chdodgemcontrol(2);
    }
}

void func_80802884_chdodgemcontrol(Actor *this)
{
    int new_var;
    int new_var2;
    int new_var3;
    anctrl_setIndex(func_80104248(), 0x10A);
    func_80101CDC(this, 0.9f);
    func_808026D0_chdodgemcontrol(this);
    new_var2 =
        (((*((s32 *) (((char *) this) + 0x64))) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
        0xFFFFFFFFFFFFFFFFu;
    new_var =
        ((new_var = new_var2 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
    new_var3 = (((((new_var & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
                 0xFFFFFFFFFFFFFFFFu) &
                0xFFFFFFFFFFFFFFFFu) &
               0xFFFFFFFFFFFFFFFFu;
    if (0 != (new_var3 & 0x100000)) {
        func_808000B8_chdodgemcontrol(3);
    }
}

void func_808028E4_chdodgemcontrol(Actor *param_0)
{
    f32 local_0;

    local_0 = func_800F1DCC(param_0->rotation[1], param_0->unk54);
    if (param_0->unk64_20) {
        if (local_0 > 10.0f) {
            func_800904C8(0x75);
            return;
        }
        if (local_0 < -10.0f) {
            func_800904C8(0x76);
            return;
        }
        func_800904C8(0x74);
        return;
    }
    if (local_0 > 10.0f) {
        switch (func_801022E4(param_0)) {
            case 0x105:
                anctrl_setIndex(func_80104248(param_0), 0x106);
                func_80101CDC(param_0, 0.5f);
                anctrl_setPlaybackType(func_80104248(param_0), 1);
                func_8008B188(func_80104248(param_0), 1);
                anctrl_start(func_80104248(param_0));
                return;
            case 0x107:
                if (func_8008B28C(func_80104248(param_0))) {
                    func_8008B188(func_80104248(param_0), 0);
                    func_80101CDC(param_0, 3.0f);
                    return;
                }
                if (anctrl_isStopped(func_80104248(param_0))) {
                    func_80802720_chdodgemcontrol(param_0);
                }
                break;
            case 0x108:
            case 0x109:
            case 0x10A:
            case 0x10B:
                if (anctrl_isStopped(func_80104248(param_0))) {
                    func_80802720_chdodgemcontrol(param_0);
                }
        }
    } else if (local_0 < -10.0f) {
        switch (func_801022E4(param_0)) {
            case 0x105:
                anctrl_setIndex(func_80104248(param_0), 0x107);
                func_80101CDC(param_0, 0.5f);
                anctrl_setPlaybackType(func_80104248(param_0), 1);
                func_8008B188(func_80104248(param_0), 1);
                anctrl_start(func_80104248(param_0));
                return;
            case 0x106:
                if (func_8008B28C(func_80104248(param_0))) {
                    func_80101CDC(param_0, 3.0f);
                    func_8008B188(func_80104248(param_0), 0);
                    return;
                }
                if (anctrl_isStopped(func_80104248(param_0))) {
                    func_80802720_chdodgemcontrol(param_0);
                }
                break;
            case 0x108:
            case 0x109:
            case 0x10A:
            case 0x10B:
                if (anctrl_isStopped(func_80104248(param_0))) {
                    func_80802720_chdodgemcontrol(param_0);
                }
        }
    } else {
        switch (func_801022E4(param_0)) {
            case 0x105:
                break;
            case 0x106:
                if (func_8008B28C(func_80104248(param_0))) {
                    func_80101CDC(param_0, 3.0f);
                    func_8008B188(func_80104248(param_0), 0);
                    return;
                }
                if (anctrl_isStopped(func_80104248(param_0))) {
                    func_80802720_chdodgemcontrol(param_0);
                }
                return;
            case 0x107:
                if (func_8008B28C(func_80104248(param_0))) {
                    func_80101CDC(param_0, 3.0f);
                    func_8008B188(func_80104248(param_0), 0);
                    return;
                }
                if (anctrl_isStopped(func_80104248(param_0))) {
                    func_80802720_chdodgemcontrol(param_0);
                }
                break;
            case 0x108:
            case 0x109:
            case 0x10A:
            case 0x10B:
                if (anctrl_isStopped(func_80104248(param_0))) {
                    func_80802720_chdodgemcontrol(param_0);
                }
        }
    }
}

void func_80802D04_chdodgemcontrol(u8 *param_0)
{
    u8 *local_1;
    f32 dt;
    f32 sp44;
    f32 sp40;
    f32 f2;
    f32 sp38;
    f32 sp34;

    local_1 = func_80100094(param_0, 0);
    dt = func_800D8FF8();
    f2 = *((f32 *) (local_1 + 0x1C));
    if (0.0f <= f2) {
        *((f32 *) (local_1 + 0x1C)) = f2 - dt;
    }

    if (10.0f < *((f32 *) (param_0 + 0x24))) {
        sp38 = func_8080460C_chdodgemcontrol(param_0);
        f2 = func_8080460C_chdodgemcontrol(param_0);
        sp44 = func_800F11E4(*((f32 *) (param_0 + 0x24)), sp38 * 0.1f, f2, 2000.0f, 15000.0f);
        _subaddieaudioloop_entrypoint_4(param_0, (param_0 + 4), 1, D_80804D10_chdodgemcontrol);
        sp34 = func_8080460C_chdodgemcontrol(param_0);
        f2 = func_8080460C_chdodgemcontrol(param_0);
        f2 = func_800F11E4(*((f32 *) (param_0 + 0x24)), sp34 * 0.5f, f2, 0.85f, 1.1f);
        func_800C31DC(param_0[0x5F], f2);
        func_800C3058(param_0[0x5F], (s32) sp44);
        if (func_800DC0C0() < 0.01f) {
            func_800C4B70((s32) sp44);
            func_8010D930(8, 0, (s32) (param_0 + 4), D_80804DA4_chdodgemcontrol);
        }
    }
    if (((DCFlags *) param_0)->b20) {
        func_80800044_chdodgemcontrol(param_0);
    }

    switch (((u32) (*((u16 *) (param_0 + 0x72)))) >> 10) {
        case 4:
            *((f32 *) (param_0 + 0x24)) = *((f32 *) (param_0 + 0x24)) * 0.8f;
            break;

        case 3:
            *((f32 *) (param_0 + 0x54)) =
                (f32) _subaddiejoy_entrypoint_2(param_0, (s32) *((f32 *) (param_0 + 0x48)), &sp40);
            f2 = func_8080460C_chdodgemcontrol(param_0);
            if (*((f32 *) (param_0 + 0x24)) < f2) {
                f2 = func_8080458C_chdodgemcontrol(param_0);
                *((f32 *) (param_0 + 0x24)) = *((f32 *) (param_0 + 0x24)) + sp40 * f2;
            }
            func_80802180_chdodgemcontrol(param_0);
            if (!(((DCFlags *) param_0)->b29)) {
                param_0[0x72] = (u8) ((param_0[0x72] & 0xFF03) | 8);
            }
            func_808028E4_chdodgemcontrol(param_0);
            return;

        case 2:
            if (((DCFlags *) param_0)->b29) {
                param_0[0x72] = (u8) ((param_0[0x72] & 0xFF03) | 0xC);
            }
            f2 = *((f32 *) (local_1 + 0x10));
            if (f2 <= 0.0f) {
                func_8080476C_chdodgemcontrol(param_0);
                f2 = func_8080460C_chdodgemcontrol(param_0);
                if (*((f32 *) (param_0 + 0x24)) < f2) {
                    f2 = func_8080458C_chdodgemcontrol(param_0);
                    *((f32 *) (param_0 + 0x24)) = *((f32 *) (param_0 + 0x24)) + f2;
                }
                if (0.0f < *((f32 *) (local_1 + 0x14))) {
                    *((f32 *) (local_1 + 0x14)) = *((f32 *) (local_1 + 0x14)) - dt;
                } else {
                    *((f32 *) (param_0 + 0x50)) = *((f32 *) (param_0 + 0x50)) - dt;
                }
            } else {
                *((f32 *) (local_1 + 0x10)) = f2 - dt;
                if (0.0f < *((f32 *) (local_1 + 0x14))) {
                    *((f32 *) (local_1 + 0x14)) = *((f32 *) (local_1 + 0x14)) - dt;
                    f2 = func_8080460C_chdodgemcontrol(param_0);
                    if (*((f32 *) (param_0 + 0x24)) < f2 * 0.5f) {
                        f2 = func_8080458C_chdodgemcontrol(param_0);
                        *((f32 *) (param_0 + 0x24)) = *((f32 *) (param_0 + 0x24)) + f2;
                    }
                } else {
                    func_8080349C_chdodgemcontrol(param_0);
                    func_808037C8_chdodgemcontrol(param_0);
                    func_80803200_chdodgemcontrol(param_0);
                }
            }
            func_80802180_chdodgemcontrol(param_0);
            func_808028E4_chdodgemcontrol(param_0);
            return;

        case 5:
            if (func_80101E14(param_0, 0.7283f) != 0) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, D_80804D48_chdodgemcontrol);
            }
            if (func_80101E4C(param_0, D_80804F74_chdodgemcontrol) != 0) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, D_80804D5C_chdodgemcontrol);
            }
            if (anctrl_isStopped(func_80104248(param_0))) {
                func_8080422C_chdodgemcontrol(param_0, 4);
            }
            return;

        case 6:
            if (func_80101E4C(param_0, D_80804F84_chdodgemcontrol) != 0) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, D_80804D74_chdodgemcontrol);
            }
            if (anctrl_isStopped(func_80104248(param_0))) {
                func_8080422C_chdodgemcontrol(param_0, 4);
            }
            return;

        case 7:
            if (func_80101E4C(param_0, D_80804F94_chdodgemcontrol) != 0) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, D_80804D8C_chdodgemcontrol);
            }
            if (func_80101E14(param_0, 0.39f) != 0) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, D_80804D48_chdodgemcontrol);
            }
            if (anctrl_isStopped(func_80104248(param_0))) {
                func_8080422C_chdodgemcontrol(param_0, 4);
            }
    }
}

void func_80803200_chdodgemcontrol(param_0) Actor *param_0;
{
    u8 *local_0;
    Actor *local_1;
    u8 *local_2;
    Actor *local_3;
    s32 local_5;
    Vec3f local_4;
    local_0 = (u8 *) func_80100094(param_0, 0);
    local_1 = (Actor *) func_80106790(param_0->unk3C);
    local_2 = (u8 *) func_80100094(local_1, 0);
    for (local_5 = 0; local_5 < local_2[0xC2]; local_5++) {
        if (local_5 != param_0->unk6C_0) {
            local_3 = (Actor *) func_8080000C_chdodgemcontrol(local_1, local_5);
            func_800EEB9C(local_4.f, param_0->rotation[1] - 145.0f, 325.0f);
            func_800EF04C(local_4.f, param_0->position);
            if (func_800F0064(local_4.f, 110.0f, local_3->position)) {
                *(f32 *) (local_0 + 0x10) = 1.0f;
                if (func_800DC0C0() < 0.5f) {
                    param_0->unk54 = param_0->rotation[1] - 65.0f;
                } else {
                    param_0->unk54 = param_0->rotation[1] + 65.0f;
                }
                if (*(f32 *) ((u8 *) param_0 + 0x24) < func_8080460C_chdodgemcontrol(param_0)) {
                    *(f32 *) ((u8 *) param_0 + 0x24) += func_8080458C_chdodgemcontrol(param_0);
                }
                *(f32 *) (local_0 + 0x14) = 0.25f;
            }
            func_800EEB9C(local_4.f, param_0->rotation[1] + 145.0f, 325.0f);
            func_800EF04C(local_4.f, param_0->position);
            if (func_800F0064(local_4.f, 110.0f, local_3->position)) {
                *(f32 *) (local_0 + 0x10) = 1.0f;
                if (func_800DC0C0() < 0.5f) {
                    param_0->unk54 = param_0->rotation[1] - 65.0f;
                } else {
                    param_0->unk54 = param_0->rotation[1] + 65.0f;
                }
                if (*(f32 *) ((u8 *) param_0 + 0x24) < func_8080460C_chdodgemcontrol(param_0)) {
                    *(f32 *) ((u8 *) param_0 + 0x24) += func_8080458C_chdodgemcontrol(param_0);
                }
                *(f32 *) (local_0 + 0x14) = 0.25f;
            }
        }
    }
}

void func_8080349C_chdodgemcontrol(param_0) Actor *param_0;
{
    u8 *local_0;
    Actor *local_1;
    u8 *local_2;
    Actor *local_3;
    s32 local_5;
    f32 local_4[3];
    f32 local_6;
    local_0 = (u8 *) func_80100094(param_0, 0);
    local_1 = (Actor *) func_80106790(param_0->unk3C);
    local_2 = (u8 *) func_80100094(local_1, 0);
    for (local_5 = 0; local_5 < local_2[0xC2]; local_5++) {
        if (local_5 != param_0->unk6C_0 &&
            (*(f32 *) (local_0 + 0x10) > 0.0f ||
             *(f32 *) ((u8 *) param_0 + 0x34) != (local_6 = local_5))) {
            local_3 = (Actor *) func_8080000C_chdodgemcontrol(local_1, local_5);
            func_800EEB9C(local_4, param_0->rotation[1] + 20.0f, 325.0f);
            func_800EF04C(local_4, param_0->position);
            if (func_800F0064(local_4, 150.0f, local_3->position)) {
                *(f32 *) (local_0 + 0x10) = 1.0f;
                param_0->unk54 = param_0->rotation[1] - 65.0f;
                if (*(f32 *) ((u8 *) param_0 + 0x24) >
                    func_8080460C_chdodgemcontrol(param_0) * 0.25f) {
                    *(f32 *) ((u8 *) param_0 + 0x24) -= func_8080458C_chdodgemcontrol(param_0) * 2;
                }
                *(f32 *) (local_0 + 0x14) = 0.25f;
            }
            func_800EEB9C(local_4, param_0->rotation[1] - 20.0f, 325.0f);
            func_800EF04C(local_4, param_0->position);
            if (func_800F0064(local_4, 150.0f, local_3->position)) {
                *(f32 *) (local_0 + 0x10) = 1.0f;
                param_0->unk54 = param_0->rotation[1] + 65.0f;
                if (*(f32 *) ((u8 *) param_0 + 0x24) >
                    func_8080460C_chdodgemcontrol(param_0) * 0.25f) {
                    *(f32 *) ((u8 *) param_0 + 0x24) -= func_8080458C_chdodgemcontrol(param_0) * 2;
                }
                *(f32 *) (local_0 + 0x14) = 0.25f;
            }
        }
    }
}

void func_8080372C_chdodgemcontrol(Actor *param_0, f32 param_1, f32 param_2)
{
    f32 local_0;
    f32 local_1;

    local_0 = func_800F1DCC(param_0->rotation[1], param_1);
    local_1 = func_800F1DCC(param_0->rotation[1], param_2);
    if (local_0 < 0.0f) {
        local_0 = -local_0;
    }
    if (local_1 < 0.0f) {
        local_1 = -local_1;
    }
    if (local_0 < local_1) {
        param_0->unk54 = param_1;
    } else {
        param_0->unk54 = param_2;
    }
}

void func_808037C8_chdodgemcontrol(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_4;
    Vec3f local_1;
    f32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_4 = func_800DC178(0.6f, 0.75f);
    if (720.0f * local_4 < param_0->position[0] || param_0->position[0] < -720.0f * local_4 ||
        720.0f * local_4 < param_0->position[2] || param_0->position[2] < -720.0f * local_4) {
        local_1 = D_80804FA0_chdodgemcontrol;
        local_2 = func_80102D78(param_0, &local_1);
        func_8080372C_chdodgemcontrol(param_0, func_800DC178(15.0f, 70.0f) + local_2,
                                      local_2 - func_800DC178(15.0f, 70.0f));
        if (func_8080460C_chdodgemcontrol(param_0) * 0.5f < ((f32 *) param_0->actorData)[3]) {
            ((f32 *) param_0->actorData)[3] -= func_8080458C_chdodgemcontrol(param_0);
        }
        if (((f32 *) param_0->actorData)[3] < func_8080460C_chdodgemcontrol(param_0) * 0.5f) {
            ((f32 *) param_0->actorData)[3] += func_8080458C_chdodgemcontrol(param_0);
        }
        *(f32 *) (local_0 + 0x14) = 0.25f;
    } else if (((f32 *) param_0->actorData)[3] < func_8080460C_chdodgemcontrol(param_0) * 0.75f) {
        ((f32 *) param_0->actorData)[3] += func_8080458C_chdodgemcontrol(param_0);
    }
}

void func_808039B8_chdodgemcontrol(param_0) Actor *param_0;
{
    char *local_0;
    Actor *local_1;
    char *local_2;
    s32 local_18;
    Actor *local_3;
    char *local_4;
    f32 local_8[3];
    f32 local_6[3];
    f32 local_7[3];
    f32 local_13;
    s32 local_19;
    f32 local_14;
    f32 local_15;
    f32 local_11[3];
    f32 local_12[3];
    f32 local_9[3];
    f32 local_10[3];

    local_0 = (char *) func_80100094(param_0, 0);
    local_1 = func_80106790(param_0->unk3C);
    local_2 = (char *) func_80100094(local_1, 0);

    local_18 = 0;

    while (local_18 < *(u8 *) (local_2 + 0xC2)) {
        if (local_18 != param_0->unk6C_0) {
            local_3 = func_8080000C_chdodgemcontrol(local_1, local_18);
            local_4 = (char *) func_80100094(local_3, 0);

            local_8[0] = local_3->position[0];
            local_8[1] = local_3->position[1];
            local_8[2] = local_3->position[2];

            func_800EEB9C(local_6, *(f32 *) ((char *) param_0 + 0x48), 75.0f);
            func_800EF04C(local_6, param_0->position);

            func_800EEB9C(local_7, local_3->rotation[1], 48.75f);
            func_800EF04C(local_7, local_3->position);

            if (func_800EFFB4(param_0->position, 182.0f, local_8) ||
                func_800EFFB4(local_6, 156.0f, local_8) ||
                func_800EFFB4(param_0->position, 156.0f, local_7) ||
                func_800EFFB4(local_6, 130.0f, local_7)) {
                local_13 = func_800EEF94((char *) param_0 + 0x28);

                if (local_18 == (s32) *(f32 *) ((char *) param_0 + 0x34)) {
                    *(f32 *) ((char *) param_0 + 0x50) = 0.0f;
                }

                if (func_800EEF94((f32 *) &local_3->actorData[4]) <= local_13) {
                    local_19 = (s32) func_800F1DF4(local_3->position, param_0->position);

                    local_14 = func_800F1DCC(local_3->rotation[1], (f32) local_19);

if (*(f32 *) (local_0 + 0x18) <= 0.0f) {
    func_8010D930(1, 0, param_0->position, D_80804D5C_chdodgemcontrol);

    *(f32 *) (local_0 + 0x18) = 1.0f;
}

if (-45.0f < local_14 && local_14 < 45.0f) {
    func_80802764_chdodgemcontrol(local_3);
}

if (local_14 < -45.0f && -135.0f < local_14) {
    func_80802824_chdodgemcontrol(local_3);
}

if (45.0f < local_14 && local_14 < 135.0f) {
    func_80802884_chdodgemcontrol(local_3);
}

if (local_14 < -135.0f || 135.0f < local_14) {
    func_808027C4_chdodgemcontrol(local_3);
}

if (*(f32 *) ((char *) param_0 + 0x24) < 150.0f) {
    *(f32 *) ((char *) param_0 + 0x24) = 150.0f;
}

if ((param_0->unk6C_0 == 0) && (local_1->unk79_4 != 3)) {
    *(f32 *) ((char *) param_0 + 0x24) *= 0.8999938965f;

    local_15 = (f32) local_19;

    func_800EEB9C(local_0, local_15, *(f32 *) ((char *) param_0 + 0x24) * 0.5f);
} else {

*(f32 *) ((char *) param_0 + 0x24) *= 0.6999969482f;

local_15 = (f32) local_19;

func_800EEB9C(local_0, local_15, *(f32 *) ((char *) param_0 + 0x24) * 1);
}

if (local_18 == 0 && (local_1->unk79_4 != 3)) {
    *(f32 *) &local_3->actorData[3] *= 0.5f;

    func_800EEB9C(local_4, local_15, -(*(f32 *) ((char *) param_0 + 0x24)) * 3.0f);
} else {
    *(f32 *) &local_3->actorData[3] *= 0.6999969482f;

    func_800EEB9C(local_4, local_15, -(*(f32 *) ((char *) param_0 + 0x24)) * 1);
}

func_800EEB9C(local_9, *(f32 *) ((char *) param_0 + 0x48), 48.75f);

func_800EEB9C(local_10, local_3->rotation[1], 48.75f);

func_80801084_chdodgemcontrol(param_0->position, local_3->position, 170.625f);

func_800EE780(local_11, local_9, param_0->position);

func_80801084_chdodgemcontrol(local_11, local_3->position, 170.625f);

func_800EFB24(param_0->position, local_11, local_9);

func_800EE780(local_12, local_10, local_3->position);

func_80801084_chdodgemcontrol(param_0->position, local_12, 136.5f);

func_800EFB24(local_3->position, local_12, local_10);

func_800EE780(local_11, local_9, param_0->position);

func_800EE780(local_12, local_10, local_3->position);

func_80801084_chdodgemcontrol(local_11, local_12, 136.5f);

func_800EFB24(local_3->position, local_12, local_10);

func_800EFB24(param_0->position, local_11, local_9);

local_14 = func_800F1DCC(*(f32 *) ((char *) param_0 + 0x48), (f32) (local_19 + 180));

if (-45.0f < local_14 && local_14 < 45.0f) {
    func_80802104_chdodgemcontrol(param_0);
}

if (local_14 < -45.0f && -135.0f < local_14) {
    func_80802104_chdodgemcontrol(param_0);
}

if (45.0f < local_14 && local_14 < 135.0f) {
    func_80802104_chdodgemcontrol(param_0);
}

if (local_14 < -135.0f || 135.0f < local_14) {
    func_80802104_chdodgemcontrol(param_0);
}

local_14 = func_800F1DCC(*(f32 *) ((char *) param_0 + 0x48), local_15);

if (-80.0f < local_14 && local_14 < 10.0f) {
    *(f32 *) (local_0 + 0xC) = *(f32 *) ((char *) param_0 + 0x24) * 0.01f;
}

if (local_14 < 80.0f && 10.0f < local_14) {
    *(f32 *) (local_0 + 0xC) = *(f32 *) ((char *) param_0 + 0x24) * -0.01f;
}

if (-170.0f < local_14 && local_14 < -100.0f) {
    *(f32 *) (local_0 + 0xC) = *(f32 *) ((char *) param_0 + 0x24) * -0.01f;
}

if (local_14 < 170.0f && 80.0f < local_14) {
    *(f32 *) (local_0 + 0xC) = *(f32 *) ((char *) param_0 + 0x24) * 0.01f;
}

local_14 = func_800F1DCC(local_3->rotation[1], local_15);

if (-80.0f < local_14 && local_14 < 10.0f) {
    *(f32 *) (local_4 + 0xC) = *(f32 *) ((char *) param_0 + 0x24) * -0.01f;
}

if (local_14 < 80.0f && 10.0f < local_14) {
    *(f32 *) (local_4 + 0xC) = *(f32 *) ((char *) param_0 + 0x24) * 0.01f;
}

if (-170.0f < local_14 && local_14 < -100.0f) {
    *(f32 *) (local_4 + 0xC) = *(f32 *) ((char *) param_0 + 0x24) * 0.01f;
}

if (local_14 < 170.0f && 80.0f < local_14) {
    *(f32 *) (local_4 + 0xC) = *(f32 *) ((char *) param_0 + 0x24) * -0.01f;
}
}
}
}

local_18++;
}
}

void func_8080422C_chdodgemcontrol(Actor *param_0, s32 param_1)
{
    func_80101FDC(param_0);
    if (param_1 == 5 || param_1 == 6 || param_1 == 7) {
        anctrl_setPlaybackType(func_80104248(param_0, param_1), 2);
        return;
    }
    anctrl_setPlaybackType(func_80104248(param_0, param_1), 1);
}

void func_808042A4_chdodgemcontrol(param_0, param_1) Unk80132ED0 *param_0;
s32 param_1;
{
    Actor *local_0;

    local_0 = func_80106790(param_0);
    switch (param_1) {
        case 2:
            switch (local_0->unk6C_0) {
                case 1:
                    _subaddiedialog_entrypoint_11(local_0->unk3C, 0x10BB, 4, local_0->position,
                                                  0x78);
                    break;
                case 2:
                    _subaddiedialog_entrypoint_11(local_0->unk3C, 0x10BD, 4, local_0->position,
                                                  0x78);
                    break;
                case 3:
                    _subaddiedialog_entrypoint_11(local_0->unk3C, 0x10BC, 4, local_0->position,
                                                  0x78);
            }
        case 3:
            switch (local_0->unk6C_0) {
                case 1:
                    func_8080422C_chdodgemcontrol(local_0, 5);
                    break;
                case 2:
                    func_8080422C_chdodgemcontrol(local_0, 7);
                    break;
                case 3:
                    func_8080422C_chdodgemcontrol(local_0, 6);
                    break;
            }
            break;
        case 0:
            func_8080422C_chdodgemcontrol(local_0, 2);
            break;
        case 1:
            func_8080422C_chdodgemcontrol(local_0, 4);
    }
}

void func_8080440C_chdodgemcontrol(param_0) Actor *param_0;
{
    f32 *local_0;

    local_0 = func_80100094(param_0, 0);
    param_0->scale = 0.65f;
    func_800EFD24(local_0);
    local_0[3] = 0.0f;
    switch (param_0->unk79_4) {
        case 0:
        case 1:
        case 2:
            switch (param_0->unk6C_0) {
                case 0:
                    func_80103140(param_0, 0x828, param_0->unk0->unk16);
                    func_800904F4(0x27, param_0->unk0);
                    func_800904C8(0x74);
                    param_0->unk64_20 = 1;
                    return;
                case 1:
                    func_8080422C_chdodgemcontrol(param_0, 5);
                    return;
                case 2:
                    func_8080422C_chdodgemcontrol(param_0, 7);
                    return;
                case 3:
                    func_8080422C_chdodgemcontrol(param_0, 6);
            }
            break;
        case 3:
            if (param_0->unk6C_0 < _gcstatusDll_entrypoint_11()) {
                ((DodgemFlags1312 *) param_0)->local_0 = 1;
            }
    }
}

void func_8080455C_chdodgemcontrol(param_0) Actor *param_0;
{
    if (param_0->unk64_20)
        func_800904C8(0x28);
}

f32 func_8080458C_chdodgemcontrol(Actor *param_0)
{
    u32 temp_t6;
    temp_t6 = (u8) (*((u8 *) (((s8 *) param_0) + 0x79)));
    temp_t6 = temp_t6 >> 4;
    switch (temp_t6) {
        case 0:

        case 1:

        case 2:
            if (!((*((s32 *) (((s8 *) param_0) + 0x6C))) & 0x1FF)) {
                return 60.0f;
            }
            return 50.0f;

        case 3:
            return 60.0f;

        default:
            return 0.0f;
    }
}

f32 func_8080460C_chdodgemcontrol(Actor *param_0)
{
    switch ((u32) (*(u8 *) ((char *) (param_0) + 0x79)) >> 4) {
        case 0:
            if ((*(s32 *) ((char *) (param_0) + 0x6C) & 0x1FF) == 0) {
                return 600.0f;
            }
            return 400.0f;

        case 1:
            if ((*(s32 *) ((char *) (param_0) + 0x6C) & 0x1FF) == 0) {
                return 600.0f;
            }
            return 500.0f;

        case 2:
            if ((*(s32 *) ((char *) (param_0) + 0x6C) & 0x1FF) == 0) {
                return 600.0f;
            }
            return 600.0f;

        case 3:
            return 600.0f;

        default:
            return 0.0f;
    }
}

f32 func_808046EC_chdodgemcontrol(u8 *param_0)
{
    u32 local_0;

    local_0 = (u32) (*(u8 *) ((char *) param_0 + 0x79)) >> 4;
    switch (local_0) {
        case 0:
        case 1:
        case 2:
            if (!((*(s32 *) ((char *) param_0 + 0x6C)) & 0x1FF)) {
                return 800.0f;
            }
            return 600.0f;
        case 3:
            return 600.0f;
        default:
            return 0.0f;
    }
}

void func_8080476C_chdodgemcontrol(param_0) Actor *param_0;
{
    Actor *local_1;
    Actor *local_2;
    u8 *local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    f32 local_0[3];

    local_1 = func_80106790(param_0->unk3C);
    local_3 = func_80100094(local_1, 0);
    if (local_1->unk79_4 == 3) {
        if (*(f32 *) ((u8 *) param_0 + 0x50) <= 0.0f) {
            local_4 = func_800DC128(0, local_3[0xC5]);
            if ((s32) (*(u8 *) (local_3 + local_4 + 0xAC)) == 1) {
                (*(f32 *) ((u8 *) param_0 + 0x34)) = local_4;
            }
            *(f32 *) ((u8 *) param_0 + 0x50) = func_800DC178(3.0f, 5.0f);
        }
        *(f32 *) ((u8 *) param_0 + 0x54) =
            func_800F1DF4(param_0->position,
                          ((f32(*)[3])(local_3 + 0x34))[(s32) (*(f32 *) ((u8 *) param_0 + 0x34))]);
    } else {
        local_2 = func_8080000C_chdodgemcontrol(local_1, 0);
        local_5 = 0;
        for (local_6 = 1; local_6 < local_3[0xC2]; local_6++) {
            if (local_6 != param_0->unk6C_0 &&
                func_800EEB40(func_8080000C_chdodgemcontrol(local_1, local_6)->position,
                              local_2->position) < 90000.0f) {
                local_5++;
            }
        }
        if (local_5 >= 2) {
            if (*(f32 *) ((u8 *) param_0 + 0x50) <= 0.0f) {
                local_0[1] = 0.0f;
                local_0[0] = func_800DC178(-600.0f, 600.0f);
                local_0[2] = func_800DC178(-600.0f, 600.0f);
                *(f32 *) ((u8 *) param_0 + 0x54) = func_800F1DF4(param_0->position, local_0);
                *(f32 *) ((u8 *) param_0 + 0x50) = func_800DC178(0.5f, 1.5f);
            }
        } else {
            *(f32 *) ((u8 *) param_0 + 0x54) = func_800F1DF4(param_0->position, local_2->position);
        }
    }
}

int chdodgemcontrol_entrypoint_2()
{
    return (int) &D_80804FAC_chdodgemcontrol;
}

s32 D_80804D00_chdodgemcontrol[4] = {0x2, 0x3, 0x4, 0x4};
u8 D_80804D10_chdodgemcontrol[16] = {0x0, 0x13, 0x5, 0x16, 0x0,  0x16, 0x1, 0xF4,
                                     0x0, 0x1,  0xD, 0xAC, 0x13, 0x88, 0x0, 0x0};
s32 D_80804D20_chdodgemcontrol[5] = {0x13054C, 0xD00F3, 0x10C0018, 0x10DAC, 0x13880000};
s32 D_80804D34_chdodgemcontrol[5] = {0x13054B, 0xD00F3, 0x10C0018, 0x10DAC, 0x13880000};
u8 D_80804D48_chdodgemcontrol[20] = {0x0,  0x13, 0x6, 0x61, 0x0, 0xA,  0x0,  0xB8, 0x0, 0x16,
                                     0x46, 0x50, 0x0, 0x1,  0xD, 0xAC, 0x13, 0x88, 0x0, 0x0};
u8 D_80804D5C_chdodgemcontrol[24] = {0x0, 0x13, 0x5,  0x19, 0x0,  0xD,  0x0, 0xF3,
                                     0x1, 0xC,  0x0,  0x16, 0x46, 0x50, 0x0, 0x1,
                                     0xD, 0xAC, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
u8 D_80804D74_chdodgemcontrol[24] = {0x0, 0x13, 0x6,  0x2B, 0x0,  0xD,  0x0, 0xCC,
                                     0x0, 0xE6, 0x0,  0x16, 0x46, 0x50, 0x0, 0x1,
                                     0xD, 0xAC, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
u8 D_80804D8C_chdodgemcontrol[24] = {0x0, 0x13, 0x4,  0xB6, 0x0,  0xD,  0x0, 0xCC,
                                     0x0, 0xE6, 0x0,  0x16, 0x46, 0x50, 0x0, 0x1,
                                     0xD, 0xAC, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
u8 D_80804DA4_chdodgemcontrol[16] = {0x0, 0x13, 0x5,  0x15, 0x0, 0x1E, 0x0, 0x1,
                                     0xD, 0xAC, 0x13, 0x88, 0x0, 0x0,  0x0, 0x0};
int D_80804DB4_chdodgemcontrol[18] = {0x2CB0306,
                                      0x1,
                                      0x0,
                                      (u32) func_8080010C_chdodgemcontrol,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x4,
                                      (u32) func_808015E8_chdodgemcontrol,
                                      0x0,
                                      0xC80000,
                                      (u32) func_808013D0_chdodgemcontrol,
                                      (u32) func_80107C2C,
                                      -0x7FFFF9FE,
                                      (u32) func_80800938_chdodgemcontrol,
                                      0x0};
Quad D_80804DFC_chdodgemcontrol = {0x77, 0x78, 0x7A, 0x79};
u8 D_80804E0C_chdodgemcontrol[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
DodgemF4 D_80804E18_chdodgemcontrol = {2.7e+02f, 9e+01f, 1.8e+02f, 0.0f};
DodgemPositions D_80804E28_chdodgemcontrol = {615.0f, 0.0f, 0.0f,   -615.0f, 0.0f, 0.0f,
                                              0.0f,   0.0f, 615.0f, 0.0f,    0.0f, -615.0f};
u32 D_80804E58_chdodgemcontrol[8] = {0x0,        0x0,       0x3F0A3D71, 0x3600000,
                                     0x3F0A3D71, 0x3600000, 0x3F0A3D71, 0x3600000};
u8 D_80804E78_chdodgemcontrol[44] = {
    0x0, 0x16, 0x12, 0x0, 0x0,  0x15, 0x0,  0x0,  0x0,  0xCC, 0x0,  0x2B, 0x0,  0xC0, 0x1,
    0x0, 0x0,  0x22, 0x0, 0x4C, 0x0,  0x59, 0x0,  0x26, 0x0,  0x33, 0x0,  0x2D, 0x1,  0x90,
    0x2, 0x58, 0x0,  0xD, 0x0,  0x14, 0x0,  0x1B, 0xFC, 0xE0, 0xFD, 0xA8, 0x0,  0x0};
u8 D_80804EA4_chdodgemcontrol[16] = {0x0, 0x13, 0x4, 0xFC, 0x0, 0x18, 0x0, 0xD,
                                     0x0, 0xF3, 0x1, 0xC,  0x0, 0x0,  0x0, 0x0};
u32 D_80804EB4_chdodgemcontrol[3] = {0x0, 0x0, 0x0};
u32 D_80804EC0_chdodgemcontrol[3] = {0x0, 0x0, 0x0};
s16 D_80804ECC_chdodgemcontrol[4] = {0x9E4, 0x9E8, 0x9E0, 0x0};
u16 D_80804ED4_chdodgemcontrol[4] = {0x7C7, 0x7C6, 0x7C5, 0x0};
int D_80804EDC_chdodgemcontrol[18] = {0x1FC037F,
                                      0x7C50001,
                                      (u32) &D_80804E58_chdodgemcontrol,
                                      (u32) func_80801C60_chdodgemcontrol,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x20004,
                                      (u32) func_80801F00_chdodgemcontrol,
                                      0x0,
                                      0x0,
                                      (u32) func_80801F2C_chdodgemcontrol,
                                      (u32) func_80107C2C,
                                      -0x7FFFFFFE,
                                      0x0,
                                      0x0};
u8 D_80804F24_chdodgemcontrol[64] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0, 0x0, 0x0, 0x4B, 0x18, 0x96, 0x80, 0x1, 0x5,  0x0, 0x0,
    0x4B, 0x18, 0x96, 0x80, 0x1, 0x5, 0x0, 0x0, 0x4B, 0x18, 0x96, 0x80, 0x1, 0x5,  0x0, 0x0,
    0x4B, 0x18, 0x96, 0x80, 0x1, 0x5, 0x0, 0x0, 0x40, 0x55, 0x1E, 0xB8, 0x1, 0xE,  0x0, 0x1,
    0x40, 0x80, 0x0,  0x0,  0x1, 0xF, 0x0, 0x1, 0x40, 0x80, 0x0,  0x0,  0x1, 0x10, 0x0, 0x1};
s32 D_80804F64_chdodgemcontrol[4] = {0x4, 0x1, 0x3, 0x2};
u8 D_80804F74_chdodgemcontrol[16] = {0x3E, 0x17, 0xDB, 0xF5, 0x3E, 0x99, 0x99, 0x9A,
                                     0x3E, 0xEF, 0x9D, 0xB2, 0xBF, 0x80, 0x0,  0x0};
u8 D_80804F84_chdodgemcontrol[16] = {0x3D, 0x8F, 0x5C, 0x29, 0x3E, 0x75, 0xC2, 0x8F,
                                     0x3E, 0xCC, 0xCC, 0xCD, 0xBF, 0x80, 0x0,  0x0};
u8 D_80804F94_chdodgemcontrol[12] = {0x3D, 0xA3, 0xD7, 0xA,  0x3F, 0x61,
                                     0x47, 0xAE, 0xBF, 0x80, 0x0,  0x0};
Vec3f D_80804FA0_chdodgemcontrol = {0.0f, 0.0f, 0.0f};
int D_80804FAC_chdodgemcontrol[21] = {0x2CA0305,
                                      0x6BA0004,
                                      (u32) &D_80804F24_chdodgemcontrol,
                                      (u32) func_80802D04_chdodgemcontrol,
                                      (u32) func_80105834,
                                      (u32) func_801018A4,
                                      0x0,
                                      0x3F800000,
                                      0x0,
                                      0x4,
                                      (u32) func_8080455C_chdodgemcontrol,
                                      0x0,
                                      0x200000,
                                      (u32) func_8080440C_chdodgemcontrol,
                                      (u32) func_80107C2C,
                                      -0x7FFFFFFE,
                                      (u32) func_8080207C_chdodgemcontrol,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0};
