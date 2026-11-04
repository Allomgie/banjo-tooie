#include "common.h"

extern void func_8010D5DC(void);
extern s32 D_80801A0C_chnewmumbo[];
extern u8 D_80801AC8_chnewmumbo[];
extern u8 D_80801AB8_chnewmumbo[];
extern void _gcdialogcamera_entrypoint_3(u32 *, f32);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64 : 12;
    u32 flag : 1;
    u32 rest : 19;
} MumboState;
extern s32 func_800F54E4(void);
extern void func_800F82D4(s32, s32);
extern void func_801017D0(Actor *);
extern f32 D_80801A00_chnewmumbo[3];
extern f32 D_808019F4_chnewmumbo[];
extern int D_80801B14_chnewmumbo[];
extern void func_80102424();
typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 28;
    u32 local_0 : 4;
} MumboRenderMode1081;
typedef struct {
    u8 pad_0[0x7A];
    u8 pad_1 : 2;
    u8 local_0 : 2;
    u8 local_1 : 3;
    u8 pad_2 : 1;
} MumboActionFlags1081;
typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 9;
    u32 local_0 : 1;
    u32 pad_2 : 22;
} MumboPhaseFlag1081;
typedef struct {
    s32 local_0[3];
} MumboTableTop50;
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 18;
    u32 local_0 : 2;
    u32 local_1 : 3;
    u32 pad_2 : 9;
} MumboActionTop50;
extern u8 *func_80100094(void *, u32);
extern f32 func_800D8FF8(void);
extern void func_8008FB10(f32 *, f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800DC298(f32);
extern s32 func_800902E4(f32 *, f32, s32, Actor **);
extern Actor *func_80106790(Unk80132ED0 *);
extern Unk80132ED0 *func_8008FDEC(void);
extern void _suexpression_entrypoint_10(void *, Unk80132ED0 *, s32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern f32 func_80013728(f32);
extern f32 func_80090010(void);
extern f32 func_8008FEF0(void);
void func_8080073C_chnewmumbo();
void func_808014FC_chnewmumbo();

// Starts the dialog camera, then updates it on later calls (cases fall through on purpose).
void func_80800000_chnewmumbo(s32 *actor, s32 unk_0, s32 unk_1)
{
    u8 *data;
    u8 cam_state;
    u8 *actor_data;

    actor_data = func_80100094(actor, 0);
    // Matching: the redundant pointer copy is needed for the match.
    data = actor_data;
    cam_state = *(u8 *) ((s8 *) actor_data + 0x24);
    switch (cam_state) {
        case 0:
            _capod_entrypoint_2(*actor, 0xA, 0);

        case 1:
            _capod_entrypoint_8(1);
            *(s8 *) ((s8 *) data + 0x24) = 2;
            _gcdialogcamera_entrypoint_6(*actor);
            _gcdialogcamera_entrypoint_8();

        case 2:
            _capod_entrypoint_7(unk_0, unk_1);
    }
}

// Stops the camera pod if it is active.
void func_8080009C_chnewmumbo(s32 actor)
{
    u8 *data;
    u8 *data_tmp;

    data = func_80100094(actor, 0);
    if (*(u8 *) ((char *) data + 0x24) != 0) {
        // Matching: extra temporary needed for the match.
        data_tmp = data;
        _capod_entrypoint_3(0);
        *(u8 *) ((char *) data_tmp + 0x24) = 0;
    }
}

// Starts dialog dialog_id on the actor.
void func_808000DC_chnewmumbo(Actor *actor, u32 dialog_id, u32 unk_0)
{
    actor->unk74_30 = 1;
    _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, unk_0, actor->position, 0x10);
}

// Returns the "Mumbo paid" flag (0x37F..0x387) of the current world, or 0 if none.
int func_8080011C_chnewmumbo()
{
    s32 map_id;
    if (!func_800DA298(0x9C5)) {
        return 0;
    }
    map_id = func_800EA05C();
    switch (map_id) {
        case 0xB7:
            return 0x37F;

        case 0xD9:
            return 0x380;

        case 0x176:
            return 0x381;

        case 0xEF:
            return 0x382;

        case 0x171:
            return 0x383;

        case 0x172:
            return 0x387;

        case 0x134:
            return 0x384;

        case 0x13E:
        case 0x13F:
            return 0x385;

        case 0x156:
            return 0x386;

        default:
            return 0;
    }
}

void func_80800210_chnewmumbo(s32 actor[3])
{
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, actor[0]);
    func_8008F990(&D_80801A0C_chnewmumbo, 0x43480000);
}

// Switches the NPC to a new state and runs that state's entry actions.
void func_80800264_chnewmumbo(actor, state) Actor *actor;
s32 state;
{
    u8 *data;
    data = (u8 *) func_80100094(actor, 0);
    if (actor->unk70_10 == 6) {
        ((MumboRenderMode1081 *) actor)->local_0 = 1;
    }
    if (func_800DA298(0x9C6)) {
        func_80102424(actor, state);
        switch (actor->unk70_10) {
            case 1:
                data[1] = 1;
                data[2] = 0;
                break;
            case 2:
            case 3:
            case 4:
                func_80800210_chnewmumbo(actor);
                break;
            case 5:
                func_8080073C_chnewmumbo(actor, func_80090178(1));
                func_80800000_chnewmumbo(actor, 2, 1);
                break;
            case 6:
                ((MumboRenderMode1081 *) actor)->local_0 = 1;
                ((MumboActionFlags1081 *) actor)->local_1 = 3;
                ((MumboActionFlags1081 *) actor)->local_0 = 3;
                actor->unk6C_0 = 0;
                ((MumboPhaseFlag1081 *) actor)->local_0 = 1;
                break;
            case 7:
                ((MumboRenderMode1081 *) actor)->local_0 = 1;
                if (!func_800DA9E4(0x7D, 1)) {
                    func_808000DC_chnewmumbo(actor, 0x11D6, 7);
                } else {
                    func_808000DC_chnewmumbo(actor, 0x11E4, 7);
                }
                _suexpression_entrypoint_12(func_80100094(actor, 1), 60.0f, 0.0f);
                break;
            case 8:
                // The dialog depends on whether the player has a Glowbo (item 0x48).
                if (func_800D1A04(0x48) > 0) {
                    func_808000DC_chnewmumbo(actor, 0x11D7, 0x46);
                } else {
                    func_808000DC_chnewmumbo(actor, 0x11DA, 7);
                }
                break;
            case 18:
                data[1] = 0;
                func_800EE7F8(actor->position, D_808019F4_chnewmumbo);
                break;
            case 19:
                data[2] = 1;
                data[1] = 0;
                break;
            case 14:
                func_8080009C_chnewmumbo(actor);
                func_800904C8(0x8D);
                func_80090590(0x3C, actor->position);
                data[0] = 1;
                if (!func_800DA9E4(0x429, 1)) {
                    func_80800000_chnewmumbo(actor, 5, 1);
                    func_808000DC_chnewmumbo(actor, 0x11E6, 0xF);
                }
                break;
            case 10:
            case 11:
                data[1] = 1;
                data[2] = 0;
                func_8080009C_chnewmumbo(actor);
        }
    }
}

// Event handler; msg is the event id, payload its argument.
s32 func_808004E8_chnewmumbo(Actor *actor, s32 msg, s32 payload)
{
    s32 unk_0;
    u32 unk_1;
    u8 *data;

    switch (msg) {
        case 0x32:
            switch (actor->unk70_10) {
                case 2:
                    func_80800264_chnewmumbo(actor, 5);
                    break;
                case 3:
                    if (func_800DA298(func_8080011C_chnewmumbo())) {
                        func_8080073C_chnewmumbo(actor, 1);
                        func_80800000_chnewmumbo(actor, 2, 1);
                        func_808000DC_chnewmumbo(actor, 0x11DB, 0x4E);
                    } else {
                        func_80800000_chnewmumbo(actor, 2, 1);
                        func_8080073C_chnewmumbo(actor, 1);
                        func_80800264_chnewmumbo(actor, 7);
                    }
                    break;
                case 4:
                    func_80800000_chnewmumbo(actor, 2, 1);
                    func_808000DC_chnewmumbo(actor, 0x11DB, 0x4E);
            }
            break;
        case 0x2E:
            // Dialog callback: dialog id and the player's answer.
            func_808014FC_chnewmumbo(actor, ((s16 *) &payload)[0], ((s16 *) &payload)[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3((u32 *) D_80801AB8_chnewmumbo, actor->scale);
            if ((s32) actor->unk70_10 < 14)
                _gcdialogcamera_entrypoint_4(D_80801AC8_chnewmumbo);
            break;
        case 0x57:
            unk_0 = payload & 0xFFFF;
            unk_1 = (u32) (payload & 0xFFFF0000) >> 16;
            if (_gcdialogcamera_entrypoint_0(unk_0, unk_1)) {
                func_80800000_chnewmumbo(actor, unk_0, unk_1);
            }
            break;
        case 0x1F:
            data = func_80100094(actor, 0);
            func_801015D0(actor);
            if (data[1])
                func_800DF744(5, 1);
            else
                func_800DF744(5, 0);
            if (data[2])
                func_800DF744(4, 1);
            else
                func_800DF744(4, 0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080073C_chnewmumbo(actor, unk_0) Actor *actor;
s32 unk_0;
{
    if (!actor->unk64_19) {
        if (unk_0) {
            func_800F7B9C(_plsu_entrypoint_1(1), 0x8D);
        }
        func_800F8300(func_800F54E4(), 2, actor->position);
        actor->unk64_19 = 1;
    }
}

void func_808007B0_chnewmumbo(MumboState *actor)
{
    if (actor->flag) {
        func_800F82D4(func_800F54E4(), 0);
        actor->flag = 0;
    }
}

void func_808007FC_chnewmumbo(Actor *actor, s32 unk_0)
{
    u8 *data;

    data = func_80100094(actor, 0);
    if (data[0] == 0) {
        func_80101808(actor, func_801017D0);
        if (data[1] && actor->unk7C_12) {
            func_800DBEFC((void *) actor->unk0->unk4, 0xB, data + 4);
        }
    }
}

void func_80800878_chnewmumbo(s32 actor)
{
    func_80800264_chnewmumbo(actor, 0xE);
}

// Eases the position toward the rest spot and damps the rotation.
void func_80800898_chnewmumbo(Actor *actor)
{
    s32 i;
    f32 target;
    f32 current;
    f32 delta;

    for (i = 0; i < 3; i++) {
        target = D_80801A00_chnewmumbo[i];
        current = actor->position[i];
        if (target != current) {
            delta = (target - current) * 0.25f;
            actor->position[i] = current + delta;
        }
    }
    if (actor->rotation[1]) {
        actor->rotation[1] *= 0.25f;
    }
    if (actor->rotation[0]) {
        actor->rotation[0] *= 0.25f;
    }
}

// Per-frame update; switches on the NPC state (unk70_10).
void func_8080092C_chnewmumbo(Actor *actor)
{
    extern MumboTableTop50 D_80801AD4_chnewmumbo;
    extern u8 D_80801990_chnewmumbo[];
    extern u8 D_8080199C_chnewmumbo[];
    extern u8 D_808019A8_chnewmumbo[];
    extern u8 D_808019B4_chnewmumbo[];
    extern u8 D_808019C0_chnewmumbo[];
    extern u8 D_808019C8_chnewmumbo[];
    extern u8 D_808019D4_chnewmumbo[];
    extern u8 D_808019E4_chnewmumbo[];
    extern u8 D_80801AE0_chnewmumbo[];
    extern u8 D_80801AF0_chnewmumbo[];
    extern f32 D_80801AFC_chnewmumbo[];
    extern f32 D_80801B08_chnewmumbo[];

    // Matching: unused local copy of the table is needed for the match.
    MumboTableTop50 table =D_80801AD4_chnewmumbo;
    f32 player_pos[3];
    u8 *data;

    data = (u8 *) func_80100094(actor, 0);

    if (func_800C0638()) {
        *(f32 *) ((u8 *) actor + 0x24) = 1.5f;
    } else if (0.0f < *(f32 *) ((u8 *) actor + 0x24)) {
        *(f32 *) ((u8 *) actor + 0x24) -= func_800D8FF8();
    }

    if (!func_800DA298(func_8080011C_chnewmumbo()) && *(f32 *) ((u8 *) actor + 0x24) <= 0.0f) {
        func_800D1824(0x48);
    }

    if (func_8010D278() == 0xD) {
        s32 player;
        f32 pos[3];
        func_8010D254(pos);

        player = _plsu_entrypoint_1(1);

        if (func_800F6D24(player)) {
            func_800F8804(player, pos);
        }
    }

    if (*(u8 *) (data + 0) == 0) {
        func_8008FB10(actor->position, actor->scale * 150.0f, actor->scale * -75.0f,
                      actor->scale * 100.0f);
    }

    func_8010D254(player_pos);

    _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);

    switch (actor->unk70_10) {
        case 19:
            switch (func_8008FD70()) {
                case 1:
                    if (!actor->unk74_30 &&
                        _subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1],
                                                     750, 90, 6)) {
                        func_80800264_chnewmumbo(actor, 4);
                    }
                    break;
                case 0x200:
                case 0x400:
                    if (!actor->unk74_30 &&
                        _subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1],
                                                     750, 90, 6)) {
                        func_80800000_chnewmumbo(actor, 2, 1);
                        func_808000DC_chnewmumbo(actor, 0x11EB, 0xF);
                    }
            }
            break;
        case 1:
            ((MumboRenderMode1081 *) actor)->local_0 = 2;

            if (func_80101E14(actor, 0.3f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801990_chnewmumbo);
            } else if (func_80101E14(actor, 0.7f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_8080199C_chnewmumbo);
            }

            switch (func_8008FD70()) {
                case 1:
                case 0x200:
                case 0x400:
                    break;
                default:
                    return;
            }

            if (_subaddiedialog_entrypoint_3(actor->position, (s32) actor->rotation[1], 0x1F4,
                                             0x5A, 6)) {
                func_80800264_chnewmumbo(actor, 2);
            }
            break;

        case 2:
            if (func_80101E14(actor, 0.3f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801990_chnewmumbo);
            } else if (func_80101E14(actor, 0.7f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_8080199C_chnewmumbo);
            }
            break;

        case 5:
            if (func_80101E14(actor, 0.999f)) {
                func_80800264_chnewmumbo(actor, 6);
            }
            break;

        case 6:
            if (func_80101E14(actor, 0.2f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808019A8_chnewmumbo);
            }

            if (actor->unk6C_0 < 100) {
                actor->unk6C_0++;
                if (actor->unk6C_0 < 20) {
                    ((MumboActionTop50 *) actor)->local_1 = 3;
                } else if (actor->unk6C_0 < 40) {
                    ((MumboActionTop50 *) actor)->local_1 = 2;
                } else if (actor->unk6C_0 < 60) {
                    ((MumboActionTop50 *) actor)->local_1 = 1;
                } else {
                    ((MumboActionTop50 *) actor)->local_1 = 0;
                    ((MumboActionTop50 *) actor)->local_0 = 1;
                }
            } else if (func_800DC298(0.3f) && (s32) ((MumboActionTop50 *) actor)->local_1 < 3) {
                ((MumboActionTop50 *) actor)->local_0 = 1;
            } else if (func_800DC298(0.05f) && (s32) ((MumboActionTop50 *) actor)->local_1 > 0) {
                ((MumboActionTop50 *) actor)->local_0 = 2;
            }

            if (func_80101E14(actor, 0.999f)) {
                switch (func_8008FD70()) {
                    case 1:
                        func_80800264_chnewmumbo(actor, 7);
                        return;
                    case 0x200:
                    case 0x400:
                        func_808007B0_chnewmumbo(actor);
                        func_808000DC_chnewmumbo(actor, 0x11EB, 0xF);
                        func_80800264_chnewmumbo(actor, 0xB);
                        return;
                    default:
                        func_80800264_chnewmumbo(actor, 0xB);
                }
            }
            break;

        case 7:
            if (func_80101E14(actor, 0.999f)) {
                func_80800264_chnewmumbo(actor, 8);
            }
            break;

        case 8:
            if (!func_800DA298(func_8080011C_chnewmumbo())) {
                switch (*(u8 *) (data + 3)) {
                    case 0:
                        break;
                    case 1:
                        func_808007B0_chnewmumbo(actor);
                        func_80090658(1);
                        *(u8 *) (data + 3) = 2;
                        break;

                    case 2:
                        if (actor->unk7C_12 &&
                            func_800902E4(actor->position, 750.0f, 0x29F, &actor) &&
                            func_8008FE14() == 0x29F && func_80090818()) {
                            actor->unk3C = func_8008FDEC();
                            func_80090768(data + 4);
                            data[3] = 3;
                        }
                        break;

                    case 3: {
                        Actor *target = func_80106790(actor->unk3C);
                        func_800EE7F8(target->actorData, (f32 *) (data + 4));
                        target->unk74_30 = 1;
                        target->unk64_19 = 1;
                        *(u8 *) (data + 3) = 4;

                        func_8080073C_chnewmumbo(actor, 1);
                        func_80090658(0);
                        return;
                    }
                    case 4:
                        func_80800264_chnewmumbo(actor, 0xD);
                        *(u8 *) (data + 3) = 0;
                }
            }
            break;

        case 13:
            if (func_80101E14(actor, 0.7f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808019C0_chnewmumbo);
                // jujubag effect
                _chjujubagfx_entrypoint_2();
            }

            if (func_80101E14(actor, 0.999f)) {
                func_800FC6B0(0x10);
                func_80800264_chnewmumbo(actor, 0x11);
                func_80800000_chnewmumbo(actor, 2, 1);
                // Set the world's "Mumbo paid" flag and take one Glowbo (item 0x48).
                func_800DA544(func_8080011C_chnewmumbo());
                func_800D175C(0x48, -1);
            }
            break;

        case 17:
            if (func_80101E14(actor, 0.05f)) {
                func_800DA544(0x9F3);
                return;
            }

            if (func_80101DDC(actor)) {
                func_80800264_chnewmumbo(actor, 0x12);
                return;
            }

            if (func_80101E14(actor, 0.87f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808019B4_chnewmumbo);
                return;
            }

            if (func_80101E14(actor, 0.76f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808019C8_chnewmumbo);
                return;
            }

            if (func_80101E4C(actor, D_80801AE0_chnewmumbo)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808019D4_chnewmumbo);
            }
            break;

        case 18:
            if (func_80101E14(actor, 0.79f)) {
                *(u8 *) (data + 2) = 1;
            } else if (func_80101E14(actor, 0.999f)) {
                func_80800878_chnewmumbo(actor);
            } else if (func_80101E4C(actor, D_80801AF0_chnewmumbo)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808019E4_chnewmumbo);
            }
            break;

        case 14:
            if (!func_8010C9FC(actor->position, 0x1C2, 0x1F4, 0x96)) {
                func_80800264_chnewmumbo(actor, 0xF);
            }
            break;

        case 15: {
            s32 player;
            f32 pos[3];
            if (!func_800EFED0(D_80801AFC_chnewmumbo, D_80801B08_chnewmumbo, player_pos)) {
                return;
            }

            if (!func_80090248()) {
                return;
            }

            func_8010D254(pos);

            player = _plsu_entrypoint_1(1);
            func_800F7B9C(player, 0x3D);

            *(u8 *) (data + 0) = 0;

            func_80800264_chnewmumbo(actor, 0x10);

            func_800EE7F8(actor->position, pos);

            func_808007B0_chnewmumbo(actor);
            return;
        }
        case 16:
            actor->rotation[1] = func_80013728(func_80090010());

            actor->rotation[0] = func_8008FEF0();

            func_80800264_chnewmumbo(actor, 9);
            return;

        case 9:
            func_80800898_chnewmumbo(actor);

            if (func_80101E14(actor, 0.21f)) {
                *(u8 *) (data + 2) = 0;
            }

            if (func_80101E14(actor, 0.83f)) {
                *(u8 *) (data + 1) = 1;
            }

            if (func_80101DDC(actor)) {
                func_80800264_chnewmumbo(actor, 0xA);

                _suexpression_entrypoint_12(func_80100094(actor, 1), 0.0f, 0.0f);
            }
            break;

        case 10: {
            f32 pos[3];
            func_8010D254(pos);
            func_80800898_chnewmumbo(actor);
            func_80800264_chnewmumbo(actor, 0xB);
            return;
        }
        case 11:
            switch (func_8008FD70()) {
                case 1:
                    if (!actor->unk74_30 &&
                        _subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1],
                                                     750, 90, 6)) {
                        func_80800264_chnewmumbo(actor, 3);
                    }
                    break;
                case 0x200:
                case 0x400:
                    if (!actor->unk74_30 &&
                        _subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1],
                                                     750, 90, 6)) {
                        func_80800000_chnewmumbo(actor, 2, 1);
                        func_808000DC_chnewmumbo(actor, 0x11EB, 0xF);
                    }
            }
    }
}

// Dialog callback: reacts to the finished dialog and the player's answer.
void func_808014FC_chnewmumbo(actor, dialog_id, answer) u8 *actor;
s32 dialog_id;
s32 answer;
{
    u32 state;
    u32 state2;
    u8 *data;

    data = func_80100094(actor, 0);
    (*(u8 *) ((s8 *) (actor) + (0x74))) = (u8) ((*(u8 *) ((s8 *) (actor) + (0x74))) & 0xFFBF);

switch (dialog_id) {
    case 0x11D7:
        if (answer > 0) {
            func_808000DC_chnewmumbo(actor, 0x11D8, 7);
            return;
        }
        func_808000DC_chnewmumbo(actor, 0x11D9, 7);
        return;
    case 0x11D9:
        func_800EE7F8(actor + 0x18, actor + 4, answer);
        func_808007B0_chnewmumbo(actor);
        func_80800264_chnewmumbo(actor, 0xA);
        return;
    case 0x11DA:
        func_800EE7F8(actor + 0x18, actor + 4, answer);
        func_808007B0_chnewmumbo(actor);
        func_80800264_chnewmumbo(actor, 0xA);
        return;
    case 0x11D8:
        *(s8 *) ((s8 *) data + 3) = 1;
        return;
    case 0x11EB:
        func_8080009C_chnewmumbo(actor);
        return;
    case 0x11DB:
        state = (u32) *(u16 *) ((s8 *) actor + 0x72) >> 0xA;
        if (state != 3) {
            if (state == 4) {
                if (answer > 0) {
                    func_80800878_chnewmumbo(actor);
                    return;
                }
                func_808000DC_chnewmumbo(actor, 0x11EA, 0xF);
            }
        } else {
            if (answer > 0) {
                func_80800000_chnewmumbo(actor, 2, 1);
                func_80800264_chnewmumbo(actor, 0x11);
                return;
            }
            func_808000DC_chnewmumbo(actor, 0x11EA, 0xF);
        }
        return;
    case 0x11EA:
        state2 = (u32) *(u16 *) ((s8 *) actor + 0x72) >> 0xA;
        switch (state2) {
            case 3:
                func_80800264_chnewmumbo(actor, 0xB, answer);
                func_808007B0_chnewmumbo(actor);
                return;
            case 4:
                func_8080009C_chnewmumbo(actor);
                func_808007B0_chnewmumbo(actor);
                func_80800264_chnewmumbo(actor, 0x13);
        }
        break;
    case 0x11E6:
        func_8080009C_chnewmumbo(actor);
}

}

// Matching: the missing return is needed for the match.
s32 chnewmumbo_entrypoint_0(s32 actor, s32 out)
{
    s32 result;
    result = func_800EE7F8(out, 4 + func_80100094(actor, 0));

}

void func_8080172C_chnewmumbo(Actor *actor)
{
    if (func_80100094(actor, 1) != 0) {
        _suexpression_entrypoint_8(actor, 1);
    }

}
void func_80801760_chnewmumbo(Actor *actor)
{
    s8 *data;
    data = (s8 *) func_80100094(actor, 0);
    func_800EE7F8(actor->position, ((f32 *) D_80801A00_chnewmumbo));
    actor->scale = 0.5f;
    _suexpression_entrypoint_7(actor, 1, 0x10);

if (func_8010D278() == 0xD) {
    *data = 1;
    func_80800264_chnewmumbo(actor, 0xF);
} else {

*data = 0;

if (func_800DA298(func_8080011C_chnewmumbo()) || _glcutDll_entrypoint_20()) {
    func_800EE7F8(actor->position, D_808019F4_chnewmumbo);
    func_80800264_chnewmumbo(actor, 0x13);
} else if (func_800DA298(0x7D)) {

func_80800264_chnewmumbo(actor, 0xA);
}
else
{
    func_80800264_chnewmumbo(actor, 1);
}
}
actor->rotation[0] = 0.0f;
}

int chnewmumbo_entrypoint_1()
{
    return (int) &D_80801B14_chnewmumbo;
}

// TU-NOTE: The overlay .data is defined here in C. Tables holding function pointers must be in
// the same TU, otherwise IDO's assembler schedules those functions differently. The extern views
// above (D_80801A0C_chnewmumbo as s32[], D_80801B14_chnewmumbo as int[]) are address-neutral.
extern void func_80105834();
extern void func_80107C2C();
u8 D_80801990_chnewmumbo[12] = {0x0, 0x13, 0x4, 0x41, 0x0, 0x16, 0x17, 0x70, 0x0, 0x0, 0x0, 0x0};
u8 D_8080199C_chnewmumbo[12] = {0x0, 0x13, 0x4, 0x42, 0x0, 0x16, 0x17, 0x70, 0x0, 0x0, 0x0, 0x0};
u8 D_808019A8_chnewmumbo[12] = {0x0, 0x13, 0x5, 0x4D, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0, 0x0, 0x0};
u8 D_808019B4_chnewmumbo[12] = {0x0, 0x13, 0x4, 0x4, 0x0, 0x16, 0x5D, 0xC0, 0x0, 0x0, 0x0, 0x0};
u8 D_808019C0_chnewmumbo[8] = {0x0, 0x13, 0x4, 0x4, 0x0, 0x18, 0x0, 0x0};
u8 D_808019C8_chnewmumbo[12] = {0x0, 0x13, 0x5, 0x11, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0, 0x0, 0x0};
u8 D_808019D4_chnewmumbo[16] = {0x0, 0x13, 0x6, 0x2B, 0x0,  0xD,  0x0, 0xF3,
                                0x1, 0xC,  0x0, 0x16, 0x46, 0x50, 0x0, 0x0};
u8 D_808019E4_chnewmumbo[16] = {0x0, 0x13, 0x5, 0xAF, 0x0,  0xD,  0x0, 0xF3,
                                0x1, 0xC,  0x0, 0x16, 0x46, 0x50, 0x0, 0x0};
f32 D_808019F4_chnewmumbo[3] = {0.0f, -3e+01f, -275.0f};
f32 D_80801A00_chnewmumbo[3] = {0.0f, 67.0f, -4.4e+02f};
s32 D_80801A0C_chnewmumbo[3] = {0x0, -0x3D780000, -0x3D380000};
u32 D_80801A18_chnewmumbo[40] = {
    0x0,        0x0,       0x40400000, 0x1AF0001, 0x40400000, 0x1AF0001, 0x40DAA7F0, 0x3010001,
    0x40C0F5C3, 0xB50001,  0x40400000, 0x1AF0001, 0x40800000, 0x1B00002, 0x3FC00000, 0x1B10002,
    0x40751EB8, 0x1B20001, 0x40470A3D, 0xFD0002,  0x40DAA7F0, 0x3010001, 0x40DAA7F0, 0x3010001,
    0x40DAA7F0, 0x3010001, 0x3FB33333, 0x1B30002, 0x40400000, 0x1AF0001, 0x40400000, 0x1AF0001,
    0x40400000, 0x1AF0001, 0x407D70A4, 0xCE0002,  0x3FE66666, 0xCF0202,  0x40C0F5C3, 0xB50001};
u8 D_80801AB8_chnewmumbo[16] = {0x43, 0x98, 0x80, 0x0, 0x43, 0x6B, 0x0, 0x0,
                                0x43, 0x6B, 0x0,  0x0, 0x43, 0x7,  0x0, 0x0};
u8 D_80801AC8_chnewmumbo[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC3, 0xC8, 0x0, 0x0};
MumboTableTop50 D_80801AD4_chnewmumbo = {0x0, -0x3D780000, -0x3D4C0000};
u8 D_80801AE0_chnewmumbo[16] = {0x3E, 0xF5, 0xA8, 0x58, 0x3F, 0x5,  0x1E, 0xB8,
                                0x3F, 0xF,  0x5C, 0x29, 0xBF, 0x80, 0x0,  0x0};
u8 D_80801AF0_chnewmumbo[12] = {0x3E, 0x8F, 0x9D, 0xB2, 0x3E, 0xEB,
                                0x85, 0x1F, 0xBF, 0x80, 0x0,  0x0};
f32 D_80801AFC_chnewmumbo[3] = {-65.0f, 5e+01f, -544.0f};
f32 D_80801B08_chnewmumbo[3] = {65.0f, 7e+01f, -4.1e+02f};
int D_80801B14_chnewmumbo[19] = {0x2250190,
                                 0x6650001,
                                 (u32) &D_80801A18_chnewmumbo,
                                 (u32) func_8080092C_chnewmumbo,
                                 (u32) func_80105834,
                                 (u32) func_808007FC_chnewmumbo,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x20080164,
                                 (u32) func_8080172C_chnewmumbo,
                                 0x0,
                                 0x280000,
                                 (u32) func_80801760_chnewmumbo,
                                 (u32) func_80107C2C,
                                 -0x7FFFFFFE,
                                 (u32) func_808004E8_chnewmumbo,
                                 0x0,
                                 0x0};
