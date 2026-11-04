// Chuffy the train engine: Mumbo's levitation, the running engine with smoke and sounds,
// arrival/departure cutscenes per station, the cab door actor and the station table lookups.
#include "common.h"

extern int D_80802434_chchuffy[];
extern u32 D_808024B4_chchuffy[];
extern void rom_read_word(u32, u32 *);
extern s16 D_8080247C_chchuffy[][4];
extern Actor *func_80106790(s32);
extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800F1828();
extern f32 func_800F1DF4();
typedef struct {
    u8 pad_0[0x4C];
    f32 local_0[3];
    f32 local_1[3];
} ChuffyPositionData;
typedef struct {
    u8 pad_0[0x2A8];
    s32 local_0;
} ChuffyInitData;
typedef struct {
    u8 pad_0[0xA];
    u8 local_0 : 5;
    u8 pad_1 : 3;
} ChuffyPropFlags;
typedef struct {
    s32 f0;
    s32 f4;
    u8 pad[0x6C];
    u8 pad74 : 1;
    u8 flag : 1;
    u8 rest : 6;
} FarmerState;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
extern Actor *func_801084B0(s32, Actor **);
typedef struct {
    f32 local_0[2];
} ChuffyEffectPair;
typedef struct {
    f32 local_0[3];
} ChuffyEffectVector;
extern s32 D_80802568_chchuffy[];
extern s32 D_80802570_chchuffy[];
extern s32 D_8080257C_chchuffy[];
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern s32 D_80802588_chchuffy[];
extern s32 D_80802594_chchuffy[];
extern s16 D_8080247E_chchuffy[][4];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern s32 D_808025A0_chchuffy[];
typedef struct {
    u8 pad[0x7C];
    u32 pad7C : 19;
    u32 flag : 1;
    u32 rest : 12;
} ChuffyS;
extern s32 D_808025E4_chchuffy[];
extern u8 D_80802630_chchuffy[];
typedef struct {
    u8 pad_0[0x14];
    f32 local_0[3];
    u8 pad_1[0x1C];
    f32 local_1;
} ChuffySound1590;
extern s16 D_8080267C_chchuffy[];
extern s32 func_800C4350();
extern void func_800C3058(s32, s32);
extern s32 D_80802690_chchuffy[];
extern u8 D_808023DC_chchuffy[];
extern u8 D_808026A4_chchuffy[];
extern void func_800EF1B8(f32 *, f32, u32);
extern f32 D_808026AC_chchuffy[3];
extern f32 D_808026B0_chchuffy;
extern f32 D_808026B8_chchuffy[3];
extern f32 D_808026BC_chchuffy;
extern f32 D_808026C4_chchuffy[3];
extern f32 D_808026D0_chchuffy[3];
extern f32 D_808026DC_chchuffy[3];
extern f32 D_808026E8_chchuffy[3];
extern s32 func_800F0064(f32 *, f32, f32 *);
extern void func_800F7F00(s32, f32 *, f32 *, f32, s32, s32, f32);
extern int D_808026F4_chchuffy[];
typedef struct {
    u8 pad_0[0x14];
    f32 origin[3];
    u8 pad_1[0x44];
    f32 positions[20][3];
    f32 velocities[10][3];
    f32 acceleration[10][3];
    f32 strength[10];
    u8 frame[10];
    u8 pad_2[6];
    s32 color[10];
} ChuffySmokeVectors;
extern f32 func_800DC178(f32, f32);
typedef struct {
    u8 pad0[0x14];
    f32 unk14[3];
    u8 pad20[0x18];
    f32 unk38;
    f32 unk3C;
    u8 pad40[0x24];
    f32 pos[10][3]; // 0x64
    f32 out[10][3]; // 0xDC
    f32 vel[10][3]; // 0x154
    f32 rise[10][3]; // 0x1D0
    f32 scale[10]; // 0x244
    s32 pad26C[3];
    f32 unk278;
    s32 timer[10]; // 0x27C
} ChuffySmoke;
extern f32 func_800D8FF8(void);
extern void func_800EFD24(f32 *);
extern s32 func_800DC128(s32, s32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern s32 D_80802320_chchuffy[];
extern s32 D_80802334_chchuffy[];
extern s32 D_80802348_chchuffy[];
extern s32 D_8080235C_chchuffy[];
extern s32 D_80802374_chchuffy[];
extern void _chchuffyglow_entrypoint_0(void);
extern void func_800E1610(s32, f32, f32, f32 *);
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800DC0C0(void);
extern f32 _sumumbofx_entrypoint_22(void *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, void *, void *, f32);
extern u8 D_8080238C_chchuffy[];
extern u8 D_808023A0_chchuffy[];
extern u8 D_808023C8_chchuffy[];
extern u8 D_808024D0_chchuffy[];
extern u8 D_808024E8_chchuffy[];
extern s32 func_80102320(Actor *, f32, f32);
extern s32 D_80802534_chchuffy[];
extern s32 D_808024FC_chchuffy[];
extern void func_80102424(Actor *, s32);
void func_808013E8_chchuffy();
void func_80802060_chchuffy();
void func_80800FBC_chchuffy();
void func_8080115C_chchuffy();
void func_808017D4_chchuffy();

// Chuffy engine actor, its smoke/sound effects, Mumbo levitation and the cab door actor.
int chchuffy_entrypoint_0()
{
    return (int) &D_80802434_chchuffy;
}

// Station table: decodes station map ids, finds the current/target station, sets "here" flags.
// Station index to map id: sum of two ROM halfwords from the table, plus 0xA0.
s32 func_8080000C_chchuffy(s32 station_idx)
{
    u32 acc;
    u32 rom_word;
    u32 rom_addr;
    u32 rom_addr2;
    u32 half;

    acc = D_808024B4_chchuffy[station_idx];
    rom_addr = (acc & 0xFFFF) + 0xB0000000;
    rom_addr2 = (acc & 0xFFFF0000) >> 16;
    acc = 0;
    if (rom_addr & 2) {
        rom_read_word((rom_addr >> 2) << 2, &rom_word);
        half = (rom_word & 0xFFFF0000) >> 16;
        acc += half;
    } else {
        rom_read_word(rom_addr, &rom_word);
        half = rom_word & 0xFFFF;
        acc += half;
    }
    if (rom_addr2) {
        rom_addr2 += 0xB0000000;
        if (rom_addr2 & 2) {
            rom_addr2 = (rom_addr2 >> 2) << 2;
            rom_read_word(rom_addr2, &rom_word);
            acc += (rom_word & 0xFFFF0000) >> 16;
        } else {
            rom_read_word(rom_addr2, &rom_word);
            acc += rom_word & 0xFFFF;
        }
    }
    return acc + 0xA0;
}

// Returns a station table index, or -1.
int func_80800110_chchuffy(s32 mode)
{
    u32 i;
    s16 *entry;
    s32 map_id;
    switch (mode) {
        case 4:
            map_id = func_800EA05C();
            for (i = 0; i < 7; i++) {
                if (func_8080000C_chchuffy(i) == map_id) {
                    break;
                }
            }

            break;

        case 0:

        case 1:
            entry = (s16 *) ((u8 *) D_8080247C_chchuffy + (mode * 2));
            for (i = 0; i < 7; i++, entry += 4) {
                if (func_800DA298(*entry)) {
                    break;
                }
            }
    }

    if (i >= 7) {
        return -1;
    }
    return i;
}

void func_808001DC_chchuffy(void)
{
    s32 *entry;
    s32 map_id;
    s32 i;

    map_id = func_800EA05C();
    entry = (s32 *) D_8080247C_chchuffy;
    i = 0;
    do {
        if (func_8080000C_chchuffy(i) == map_id) {
            func_800DA544(*(s16 *) ((s8 *) entry + 0));
            func_800DA524(*(s16 *) ((s8 *) entry + 2));
        } else {
            func_800DA524(*(s16 *) ((s8 *) entry + 0));
        }
        i += 1;
        entry += 2;
    } while (i != 7);
}

int func_80800264_chchuffy(void)
{
    s32 i;
    s32 map_id;

    map_id = func_800EA05C();
    for (i = 0; i < 7; i++) {
        if (func_8080000C_chchuffy(i) != map_id) {
            if (func_800DA298(D_8080247C_chchuffy[i][1])) {
                return 1;
            }
        }
    }
    return 0;
}

s32 chchuffy_entrypoint_1(s32 actor_id, f32 *pos, f32 *angles)
{
    Actor *actor;
    s32 data;

    actor = func_80106790(actor_id);
    data = (s32) func_80100094(actor, 0);
    func_800EE7F8(pos, (f32 *) (data + 0x4C));
    angles[0] = 90.0f - func_800F1828((f32 *) (data + 0x4C), (f32 *) (data + 0x58));
    angles[1] = func_800F1DF4((f32 *) (data + 0x4C), (f32 *) (data + 0x58));
    angles[2] = 0.0f;
    if ((s32) actor->unk70_10 < 4) {
        return 1;
    }
    return 0;
}

void func_80800398_chchuffy(Actor *actor)
{
    ChuffyPositionData *data;
    f32 angles[3];
    data = func_80100094(actor, 0);
    angles[0] = 90.0f - func_800F1828(data->local_0, data->local_1);
    angles[1] = func_800F1DF4(data->local_0, data->local_1);
    angles[2] = 0.0f;
    func_808013E8_chchuffy(actor, data->local_0, angles);
}

// Respawns one smoke puff.
void func_80800410_chchuffy(actor, idx) Actor *actor;
s32 idx;
{
    ChuffySmokeVectors *smoke;
    smoke = (ChuffySmokeVectors *) func_80100094(actor, 0);
    smoke->velocities[idx][0] = func_800DC178(-13.0f, 13.0f);
    smoke->velocities[idx][1] = func_800DC178(10.0f, 20.0f);
    smoke->velocities[idx][2] = func_800DC178(-13.0f, 13.0f);
    smoke->acceleration[idx][1] = func_800DC178(250.0f, 450.0f);
    func_800EE7F8(smoke->positions[idx], smoke->origin);
    smoke->positions[idx][2] += 25.0f;
    smoke->strength[idx] = func_800DC178(0.2f, 0.4f);
    smoke->color[idx] = func_800DC128(185, 250);
    smoke->frame[idx] = func_800DC128(0, 6);
}

void func_80800524_chchuffy(Actor *actor)
{
    ChuffyInitData *init;
    s32 i;
    init = func_80100094(actor, 0);
    init->local_0 = 0x9DD;
    for (i = 0; i < 10; i++) {
        func_80800410_chchuffy(actor, i);
    }
    ((ChuffyPropFlags *) actor->unk0->unk0)->local_0 = 3;
}

// Updates the smoke puffs.
void func_8080059C_chchuffy(Actor *actor)
{
    f32 dt;
    ChuffySmoke *smoke;
    s32 i;

    dt = func_800D8FF8();
    smoke = func_80100094(actor, 0);
    for (i = 0; i != 10; i++) {
        if (smoke->timer[i] < 10) {
            if (0.0f < smoke->unk278) {
                func_80800410_chchuffy(actor, i);
            } else {
                smoke->rise[i][1] = 0.0f;
                func_800EFD24(smoke->vel[i]);
                func_800EE7F8(smoke->pos[i], smoke->unk14);
                smoke->scale[i] = 0.0f;
            }
        }
        if (smoke->timer[i] >= 0x3D) {
            smoke->scale[i] += 0.12f;
        } else {
            smoke->rise[i][1] -= 10.0f;
            smoke->scale[i] *= 0.9f;
        }
        smoke->timer[i] -= func_800DC128(6, 12);
        smoke->vel[i][0] += smoke->rise[i][1] * dt;
        smoke->vel[i][1] *= 1.1f;
        smoke->vel[i][2] *= 1.1f;
        func_800EE780(smoke->out[i], smoke->pos[i], smoke->vel[i]);
    }
    if (0.0f < smoke->unk38) {
        func_80800410_chchuffy(actor, actor->unk6C_0);
        actor->unk6C_0++;
        if (actor->unk6C_0 == 10) {
            smoke->unk278 = 0.2f;
            actor->unk6C_0 = 0;
        }
        smoke->unk3C = func_800DC178(27000.0f, 30000.0f);
    } else {
        smoke->unk278 -= func_800D8FF8();
    }
}

void func_80800818_chchuffy(FarmerState *state, s32 text_id, s32 flags)
{
    flags |= 4;
    _subaddiedialog_entrypoint_11(state->f0, text_id, flags, &state->f4, 0x6f);
    state->flag = 1;
}

// Cab door actor: event 0x3D spawns the door (actor 0x316), 0x3E section-skips the player.
int func_80800864_chchuffy(Actor *actor, s32 event, void *info)
{
    Actor *door;

    switch (event) {
        case 0x3D:
            door = func_801084B0(0x316, &actor);
            *(s32 *) ((u8 *) actor + 0x3C) = (s32) door->unk0;
            *(s32 *) ((u8 *) door + 0x3C) = (s32) actor->unk0;
            break;
        case 0x3E:
            if (*(s32 *) ((u8 *) actor + 0x3C)) {
                door = func_80106790(*(s32 *) ((u8 *) actor + 0x3C));
                if ((*(u32 *) ((u8 *) info + 0x24) >> 22) == 0) {
                    switch ((*(u32 *) ((u8 *) actor->unk0 + 0x18) << 11) >> 28) {
                        case 1:
                            door->unk64_20 = 1;
                            if (func_80090178(1))
                                _gcsectionskip_entrypoint_1(0, 0, 0, 1, 0);
                            else if (!actor->unk74_30)
                                func_80800818_chchuffy(actor, 0x121E, 0);
                            break;
                        case 2:
                            door->unk64_19 = 1;
                            if (func_80090178(-1))
                                _gcsectionskip_entrypoint_1(0, 0, 0, 2, 0);
                    }
                }
            }
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_808016D0_chchuffy();

void func_8080130C_chchuffy();

// Per-frame state machine.
void func_808009CC_chchuffy(Actor *actor)
{
    u8 *data;
    Actor *linked;

    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            if (func_800DA298(0x9DE)) {
                func_800DA3B8(0x9DE, 0);
                _capod_entrypoint_13(actor->unk0, 0, 0, 0);
                func_80090734(2, data + 0x2C);
                func_8080130C_chchuffy(actor);
                func_808017D4_chchuffy(actor, 2);
                *(f32 *) (data + 4) = 0.0f;
                _chbaddiesetup_entrypoint_1(_chchuffyglow_entrypoint_0, actor->unk0);
            }
            break;
        case 2:
            func_80800398_chchuffy(actor);
            break;
        case 3:
            func_80800398_chchuffy(actor);
            func_800DA544(0x95);
            func_800DA544(0x4ED);
            linked = func_80106790((s32) actor->unk3C);
            func_80103140(linked, 0x87A, linked->unk0->unk16);
            func_8010A590(linked);
            if (func_80101E14(actor, 0.73f) || func_80101E14(actor, 0.75f)) {
                func_800E1610(2, 100.0f, 0.65f, (f32 *) (data + 0x20));
                _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80802320_chchuffy);
            }
            _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_80802334_chchuffy,
                                             0.9f);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_80802348_chchuffy,
                                             0.95f);
            if (func_80101F24(actor) < 0.1f) {
                if (func_800DC0C0() < 0.04f) {
                    _subaddieaudioquick_entrypoint_2(actor, (f32 *) (data + 0x4C),
                                                     &D_8080235C_chchuffy);
                }
            } else if (func_80101F24(actor) < 0.95f && func_800DC0C0() < 0.04f) {
                _subaddieaudioquick_entrypoint_2(actor, (f32 *) (data + 0x4C),
                                                 &D_80802374_chchuffy);
            }
            if (func_80101E14(actor, 0.95f)) {
                func_800DA3B8(0x9DF, 1);
            }
            break;
        case 4:
            func_80800398_chchuffy(actor);
            if (_sumumbofx_entrypoint_22(func_80100094(actor, 1)) < 0.05f) {
                _sumumbofx_entrypoint_1(actor, 1);
                func_808017D4_chchuffy(actor, 5);
            }
        case 5:
            if (*(f32 *) (data + 4) < 20000.0f) {
                *(f32 *) (data + 4) = *(f32 *) (data + 4) + 250.0f;
            }
            break;
        case 6:
            if (*(f32 *) (data + 0x38) <= 0.0f) {
                func_808017D4_chchuffy(actor, 7);
            }
            break;
        case 7:
            if (*(f32 *) (data + 4) > 10000.0f) {
                *(f32 *) (data + 4) = *(f32 *) (data + 4) - 250.0f;
            }
            if (func_80101DDC(actor)) {
                func_800DA3B8(0x66B, 1);
                if (func_800DA298(0x6B7)) {
                    _glcutDll_entrypoint_17();
                    _capod_entrypoint_14();
                } else {
                    _glcutDll_entrypoint_24(func_8080000C_chchuffy(func_80800110_chchuffy(1)), -1,
                                            0x70);
                    func_800FE844(0);
                    func_800FE734(0);
                }
            }
            break;
        case 8:
            if (func_80101F24(actor) > 0.75f) {
                if (*(f32 *) (data + 4) < 20000.0f) {
                    *(f32 *) (data + 4) = *(f32 *) (data + 4) + 250.0f;
                }
            }
            if (actor->unk74_30) {
                if (actor->unk58 > 0.0f) {
                    actor->unk58 -= func_800D8FF8();
                } else {
                    if (!func_808016D0_chchuffy(actor)) {
                        _glcutDll_entrypoint_17();
                        _capod_entrypoint_14();
                    }
                    func_808017D4_chchuffy(actor, 5);
                }
            } else if (func_80101DDC(actor)) {
                actor->unk74_30 = 1;
                actor->unk58 = 2.0f;
            }
    }
    switch (func_801022E4(actor)) {
        case 0x99:
            func_8080115C_chchuffy(actor);
            break;
        case 0x9A:
            func_80800FBC_chchuffy(actor);
    }
    *(f32 *) (data + 0x38) -= func_800D8FF8();
}

void func_80800EF4_chchuffy(s32 *actor)
{
    s32 station;

    station = func_80800110_chchuffy(4);
    if (*(s16 *) ((char *) &D_8080247C_chchuffy + (station * 8) + 4) != -1) {
        _capod_entrypoint_13(*actor, 0,
                             *(s16 *) ((char *) &D_8080247C_chchuffy + (station * 8) + 4), 0x2830);
    }
}

void func_80800F54_chchuffy(s32 *actor)
{
    s32 station;
    station = func_80800110_chchuffy(4);
    if (D_8080247C_chchuffy[station][3] != -1) {
        _capod_entrypoint_13(*actor, 0, D_8080247C_chchuffy[station][3], 0x2830);
        _chintrotext_entrypoint_2(1);
    }
}

void func_80801EAC_chchuffy();

void func_80801DDC_chchuffy();

void func_80801D94_chchuffy();

void func_80801D3C_chchuffy();

void func_80801CF8_chchuffy();

void func_80800FBC_chchuffy(actor) Actor *actor;
{
    u8 *data;
    data = func_80100094(actor, 0);
    if (func_800DC0C0() < 0.25f) {
        func_80801D3C_chchuffy(actor, 1);
    }
    func_8080059C_chchuffy(actor);
    if (func_80102320(actor, 0.65f, 0.72f)) {
        func_80801EAC_chchuffy(actor);
    }
    func_80801F04_chchuffy(actor);
    func_80801DDC_chchuffy(actor);
    if (func_80101E4C(actor, D_808024D0_chchuffy)) {
        _subaddieaudioquick_entrypoint_2(actor, data + 8, D_8080238C_chchuffy);
        func_80801D94_chchuffy(actor, 5);
        *(f32 *) (data + 0x38) = 0.3f;
    }
    if (func_80101E4C(actor, D_808024E8_chchuffy)) {
        _subaddieaudioquick_entrypoint_2(actor, data + 8, D_8080238C_chchuffy);
    }
    if (func_80101E14(actor, 0.925f) || func_80101E14(actor, 0.965f)) {
        _subaddieaudioquick_entrypoint_2(actor, data + 0x2C, D_808023A0_chchuffy);
        func_80801CF8_chchuffy(actor, 5);
    }
    if (func_80101E14(actor, 0.7f)) {
        *(f32 *) (data + 0x38) = 3.0f;
    }
    _subaddieaudioquick_entrypoint_3(actor, data + 0x4C, D_808023C8_chchuffy, 0.88f);
}

void func_8080115C_chchuffy(actor) Actor *actor;
{
    u8 *data;

    data = func_80100094(actor, 0);

if (func_800DC0C0() < 0.25f) {
    func_80801D3C_chchuffy(actor, 1);
}

func_80801F04_chchuffy(actor);
func_8080059C_chchuffy(actor);

if (((u32) *(u16 *) ((s8 *) actor + 0x72) >> 0xA) != 5) {
    if (func_80102320(actor, 0.21f, 0.31f) != 0) {
        func_80801EAC_chchuffy(actor);
    }
    func_80801DDC_chchuffy(actor);
    if (func_80101E4C(actor, &D_808024FC_chchuffy) != 0) {
        _subaddieaudioquick_entrypoint_2(actor, data + 8, &D_8080238C_chchuffy);
        func_80801D94_chchuffy(actor, 5);
        *(f32 *) ((s8 *) data + 0x38) = 0.3f;
    }
    if (func_80101E4C(actor, &D_80802534_chchuffy) != 0) {
        _subaddieaudioquick_entrypoint_2(actor, data + 8, &D_8080238C_chchuffy);
    }
    if ((func_80101E14(actor, 0.02f) != 0) || (func_80101E14(actor, 0.035f) != 0)) {
        _subaddieaudioquick_entrypoint_2(actor, data + 0x2C, &D_808023A0_chchuffy);
        func_80801CF8_chchuffy(actor, 5);
    }
    if ((func_80101E14(actor, 0.59f) != 0) || (func_80101E14(actor, 0.49f) != 0)) {
        _subaddieaudioquick_entrypoint_2(actor, data + 0x20, &D_808023C8_chchuffy);
    }
}

}

void func_8080130C_chchuffy(Actor *actor)
{
    void *effect;
    ChuffyEffectPair unk_0;
    ChuffyEffectVector unk_1;
    ChuffyEffectVector unk_2;
    _sumumbofx_entrypoint_0(actor, 1, 0x41, (s16) _chmumbopad_entrypoint_0(0));
    effect = func_80100094(actor, 1);
    _sumumbofx_entrypoint_2(effect);
    _sumumbofx_entrypoint_24(effect, 2.25f);
    _sumumbofx_entrypoint_15(effect, 3.0f);
    unk_0 = *(ChuffyEffectPair *) D_80802568_chchuffy;
    unk_1 = *(ChuffyEffectVector *) D_80802570_chchuffy;
    unk_2 = *(ChuffyEffectVector *) D_8080257C_chchuffy;
    _sumumbofx_entrypoint_12(effect, &unk_1, &unk_0, &unk_2);
}

void func_808013E8_chchuffy(actor, pos, angles) Actor *actor;
s32 pos;
s32 angles;
{
    extern void _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, void *, s32, s32);
    extern s32 _sumumbofx_entrypoint_5(void *, f32);
    extern void _sumumbofx_entrypoint_18(void *, f32);
    extern void _sumumbofx_entrypoint_16(void *, f32);
    void *effect;
    ChuffyEffectVector vec;
    ChuffyEffectVector unk_0;
    f32 player_pos[3];
    f32 target[3];
    effect = func_80100094(actor, 1);
    vec = *(ChuffyEffectVector *) D_80802588_chchuffy;
    unk_0 = *(ChuffyEffectVector *) D_80802594_chchuffy;
    func_8010D254(player_pos);
    func_800EFA4C(vec.local_0, 0.0f, -675.0f, -155.0f);
    _sumumbofx_entrypoint_6(effect, 700.0f, 300.0f, 0, 20, &vec, pos, angles);
    func_800EFD24(&vec);
    _sumumbofx_entrypoint_6(effect, 900.0f, 150.0f, 20, 45, &vec, pos, angles);
    func_800EFA4C(vec.local_0, 160.0f, -150.0f, 260.0f);
    _sumumbofx_entrypoint_6(effect, 750.0f, 45.0f, 45, 55, &vec, pos, angles);
    func_800EFA4C(vec.local_0, 160.0f, 650.0f, 235.0f);
    _sumumbofx_entrypoint_6(effect, 275.0f, 90.0f, 55, 65, &vec, pos, angles);

switch (actor->unk70_10) {
    case 2:
        if (_sumumbofx_entrypoint_27(effect) && _sumumbofx_entrypoint_5(effect, 4.6f)) {
            _sumumbofx_entrypoint_18(effect, 4.0f);
            func_808017D4_chchuffy(actor, 3);
        }
        break;
    case 3:
        if (func_80101E14(actor, 0.8f)) {
            _chglowbo_entrypoint_6();
        }
        if (func_80101DDC(actor)) {
            _sumumbofx_entrypoint_16(effect, 2.0f);
            func_808017D4_chchuffy(actor, 4);
            func_80090708(0);
        }
        break;
}

func_800EE7F8(target, (u8 *) actor + 0x18);
target[1] += 500.0f;
_sumumbofx_entrypoint_11(effect, target);
_sumumbofx_entrypoint_14(effect);

}

void func_8080167C_chchuffy(s32 *out)
{
    if (_glcutDll_entrypoint_19(0x72)) {
        _capod_entrypoint_14();
        func_800D9290();
        _glcutDll_entrypoint_21();
    }

else
{
    *out = 0xD0;
}
}

// Starts a station-specific cutscene; returns 1 if one was started.
s32 func_808016D0_chchuffy(Actor *actor)
{
    s32 map_id;

    map_id = func_800EA05C();

switch (map_id) {
    case 0xEC:
        if (func_800DA298(0x98) && !func_800DA298(0x588) && !func_800DA298(0x8A)) {
            func_8080167C_chchuffy(&map_id);
            _glcutDll_entrypoint_24(0xEA, map_id, 0x1F);
            return 1;
        }
        break;
    case 0x114:
        if (func_800DA298(0x588)) {
            func_8080167C_chchuffy(&map_id);
            _glcutDll_entrypoint_24(0x114, -1, 0x35);
            return 1;
        } else if (func_800DA298(0x189) && func_800DA298(0x15E)) {
            func_8080167C_chchuffy(&map_id);
            _glcutDll_entrypoint_24(0x114, -1, 0x38);
            return 1;
        }
}

return 0;
}

void func_808017D4_chchuffy(actor, state) Actor *actor;
s32 state;
{
    u8 *data;
    u32 cur_state;

    data = func_80100094(actor, 0);

if (actor->unk70_10 == 5) {
    func_8010A570(actor);
}

func_80102424(actor, state);
cur_state = actor->unk70_10;

switch (cur_state) {
    case 6:
        func_80800EF4_chchuffy(actor);
        *(f32 *) (data + 0x38) = 1.2f;
        break;
    case 8:
        func_800DA3B8(0x6E4, func_800DA298(0x6B7));
        if (func_800DA9E4(0x6B7, 0)) {
            _glcutDll_entrypoint_6(func_800EA05C(), 0x72);
        }
        actor->unk74_30 = 0;
        func_80800F54_chchuffy(actor);
        func_808001DC_chchuffy();
        break;
    case 5:
        func_8010A590(actor);
        break;
    case 1:
        func_8010A590(actor);
}

}

void func_808018F8_chchuffy(Actor *actor)
{
    s32 station;

    station = func_80800110_chchuffy(4);

if (func_800DA298((s16(*)[4]) D_8080247C_chchuffy[station][0])) {
    if (func_80800264_chchuffy()) {
        func_808017D4_chchuffy(actor, 6);
    } else {
        func_808017D4_chchuffy(actor, 5);
    }
} else if (func_800DA298(D_8080247E_chchuffy[station][0])) {

func_808017D4_chchuffy(actor, 8);
} else {
func_800FFAB0(actor);
}
}

// Matching: the line breaks in this function are needed for the match.
void func_808019A4_chchuffy(Actor *actor, s32 gfx)
{
    u8 *sub_ptr;
    int offset;
    u8 *data;
    f32 vec[3];
    u8 *elem;
    u8 *flags;
    f32 *out_pos;
    s32 off;
    s32 unk_0;
    data = func_80100094(actor, 0);
    func_800EFD24(actor->position);
    if (func_80100094(actor, 1) != 0)
    {
        unk_0 = _sumumbofx_entrypoint_10(func_80100094(actor, 1));
        func_800DF5D8(unk_0, 255, unk_0, 255);
    }
    func_80101870(actor, gfx);
    sub_ptr = data + 8;
    func_800DBEFC(*((s32 *) (((u8 *) actor->unk0) + 4)), 7, data + 0x14);
    func_800DBEFC(*((s32 *) (((u8 *) actor->unk0) + 4)), 5, sub_ptr);
    func_800DBEFC(*((s32 *) (((u8 *) actor->unk0) + 4)), 8, data + 0x20);
    func_800DBEFC(*((s32 *) (((u8 *) actor->unk0) + 4)), 4, data + 0x2C);
    func_800DBEFC(*((s32 *) (((u8 *) actor->unk0) + 4)), 10, data + 0x4C);
    func_800DBEFC(*((s32 *) (((u8 *) actor->unk0) + 4)), 9, data + 0x58);
    if (func_80100094(actor, 1) != 0)
    {
        _sumumbofx_entrypoint_8(func_80100094(actor, 1), gfx);
    }
    if (((s32) actor->unk70_10) >= 6)
    {
        func_800E2588(1);
        func_800E2594(gfx, func_800D674C(*((s32 *) (data + 0x2A8))));
        elem = data;
        flags = data;
        off = 0; out_pos = (f32 *) (data + 0xDC); for (; off != 0x78; off += 12, elem += 4, flags++, out_pos += 3) {
            vec[0] = *((f32 *) (elem + 0x244));
            offset = 0x244;
            vec[1] = *((f32 *) (elem + offset));
            vec[2] = *((f32 *) (elem + offset));
            func_800E2720(gfx, flags[0x26C], 0, out_pos, vec, *((s32 *) (elem + 0x27C)));

}

func_800E2A14(gfx);
}
}

void func_80801B8C_chchuffy(Actor *actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    data[1] = 0;
    *(f32 *) (data + 0x3C) = 0.0f;
    *(f32 *) (data + 4) = 20000.0f;
    data[0] = 0;
    *(f32 *) (data + 0x48) = 1.0f;
    func_80800524_chchuffy(actor);
    if (func_800EA05C() == 0xD7) {
        if (func_80800110_chchuffy(0) == -1) {
            if (!func_800DA298(0x95)) {
                func_808017D4_chchuffy(actor, 1);
            } else {

func_808017D4_chchuffy(actor, 5);
}
}
else
{
    func_808018F8_chchuffy(actor);
}
}
else
{
    func_808018F8_chchuffy(actor);
}
if (!actor->unk64_17) {
    func_80108B04(actor, 0);
}
}

void func_80801C78_chchuffy(s32 actor)
{
    u8 *data;
    data = func_80100094(actor, 0);
    {
        if ((*data) != 0) {
            func_800C2FDC(*data);
            *data = 0;
        }
        if (data[1] != 0) {
            func_800C2FDC(data[1]);
            data[1] = 0;
        }
    }
    if (func_80100094(actor, 1) != 0) {
        _sumumbofx_entrypoint_1(actor, 1);
    }
}

void func_80801CF8_chchuffy(s32 actor, s32 count)
{
    func_800BBCB8((f32 *) ((u8 *) func_80100094((Actor *) actor, 0) + 0x2C), 0, 1.0f, count,
                  &D_808025A0_chchuffy);
}

void func_80801D3C_chchuffy(ChuffyS *actor, s32 count)
{
    u8 *pos = (u8 *) func_80100094((Actor *) actor, 0) + 8;
    if (actor->flag) {
        func_800BBCB8((f32 *) pos, 0, 1.0f, count, &D_808025E4_chchuffy);
    }
}

void func_80801D94_chchuffy(Actor *actor, s32 count)
{
    // Matching: taking the address of the parameter is needed for the match.
    func_800BBCB8((u8 *) func_80100094((*(Actor **) &actor), 0) + 8, 0, 1.0f, count,
                  D_80802630_chchuffy);
}

void func_80801DDC_chchuffy(Actor *actor)
{
    ChuffySound1590 *data;

    data = func_80100094(actor, 0);
    if (actor->unk5F == 0)
        actor->unk5F = func_800C4350(0, data->local_0, D_8080267C_chchuffy);
    else {
        if (data->local_1 > 2000.0f && actor->unk7C_12) {
            func_800C3058(actor->unk5F, (s32) data->local_1);
            func_800C4350(actor->unk5F, data->local_0, NULL);
        }
        data->local_1 -= 1000.0f;
    }
}

void func_80801EAC_chchuffy(u8 *actor)
{
    u8 *handle_ptr;
    u8 *data;

    data = func_80100094(actor, 0);
    handle_ptr = data;
    *handle_ptr = _subaddieaudioloop_entrypoint_7(*data, data + 0x20, 1, &D_80802690_chchuffy,
                                               (*(s32 *) ((s8 *) (actor) + (0x70))) & 1);
}

int func_80801F04_chchuffy(Actor *actor)
{
    u8 *data;
    data = func_80100094(actor, 0);
    if (data[1] == 0) {
        data[1] = func_800C4350(0, data + 0x20, D_808023DC_chchuffy);
    } else {
        func_800C3058(data[1], (s32) *(f32 *) (data + 4));
        func_800C4350(data[1], data + 0x20, 0);
    }
}

s32 func_80801F84_chchuffy(s32 actor)
{
    func_800EFD24(actor + 4);
}

s32 func_80801FA4_chchuffy(Actor *actor, s32 event, Unk80132ED0 *info)
{
    s32 model_id;

    switch (event) {
        case 0x95:
            model_id = func_800DA298(0x95) ? 0x87A : 0x879;
            func_80103140(actor, (u16) model_id, actor->unk0->unk16);
            func_8010A5B0(actor, func_800DA298(0x95));
            break;
        case 0x2E:
            actor->unk74_30 = 0;
            break;
        case 0x3E:
            // Matching: taking the address of the parameter is needed for the match.
            func_80802060_chchuffy(actor, (*(Unk80132ED0 **) &info));
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80802060_chchuffy(actor, info) u8 *actor;
u8 *info;
{
    s32 prop;
    f32 pos[3];
    f32 dest[3];
    u32 unk_0;
    f32 angles[3];

    unk_0 = (u32) (*(u16 *) ((u8 *) info + 0x1A)) >> 5;
    if ((func_800F6C5C(unk_0) != 0) &&
        (func_800F55D0(unk_0) == (*(s32 *) ((u8 *) actor + 0)))) {
        func_800F5A00(unk_0, pos);
        prop = _gccubesearch_entrypoint_6(&D_808026A4_chchuffy, pos);
        if (prop != 0) {
            _gspropctrl_entrypoint_11(prop, dest);
        } else {
            chchuffy_entrypoint_1((*(s32 *) ((u8 *) actor + 0x3C)), dest, angles);
            if (pos[2] < dest[2]) {
                func_800EF1B8(dest, (*(f32 *) ((u8 *) actor + 0x48)) - 180.0f,
                              (u32) 0x43FA0000);
            } else {
                func_800EF1B8(dest, (*(f32 *) ((u8 *) actor + 0x48)), (u32) 0x43FA0000);
            }
            dest[0] = pos[0];
        }
        func_800F77E8(unk_0, dest);
    }
}

void func_80802164_chchuffy(Actor *actor)
{
    f32 player_pos[3];

    func_8010A654(actor, func_800DB9B0() == 0);
    if (func_800DA298(0x95)) {
        func_8010D254(player_pos);
        if (func_800F0064(player_pos, 130.0f, D_808026AC_chchuffy) &&
            D_808026B0_chchuffy < player_pos[1] && player_pos[1] <= D_808026BC_chchuffy) {
            func_800F7F00(func_800F54E4(), D_808026AC_chchuffy, D_808026B8_chchuffy, 80.0f, 2, 2,
                          0.0f);
        }
        if (actor->unk64_20 && !func_80090178(1)) {
            func_8008FA94(D_808026C4_chchuffy, D_808026D0_chchuffy);
        }
        if (actor->unk64_19 && !func_80090178(-1)) {
            func_8008FA94(D_808026DC_chchuffy, D_808026E8_chchuffy);
        }
    }
}

int *chchuffy_entrypoint_2()
{
    return &D_808026F4_chchuffy;
}

// TU-NOTE: the overlay .data is defined in C here; its tables point to functions of this file,
// and IDO's assembler schedules some of them differently unless they are in the same unit.
// Values are taken from the ROM. D_8080247E = D_8080247C + 0x2, D_808026B0 = D_808026AC + 0x4,
// D_808026BC = D_808026B8 + 0x4 (linker symbols in undefined_syms). Several externs are declared
// as s32[]/int[] to match the objects.
extern void func_80105834();
extern void func_80108EE8();
extern void func_80107C2C();
extern void func_8010A73C();
extern void func_80108ED0();
s32 D_80802320_chchuffy[5] = {0x1304C1, 0xA0099, 0x167D00, 0x101F4, 0x13880000};
s32 D_80802334_chchuffy[5] = {0x1304C1, 0xA0066, 0x167D00, 0x101F4, 0x13880000};
s32 D_80802348_chchuffy[5] = {0x1304C1, 0xA0066, 0x166D60, 0x101F4, 0x13880000};
s32 D_8080235C_chchuffy[6] = {0x1304A1, 0xD0080, 0xB30019, 0x465055F0, 0x11388, 0x27100000};
s32 D_80802374_chchuffy[6] = {0x1304A1, 0xD0080, 0xB30019, 0x465055F0, 0x11388, 0x27100000};
u8 D_8080238C_chchuffy[20] = {0x0, 0x13, 0x4, 0xE8, 0x0,  0xA,  0x0, 0xCC, 0x0, 0x18,
                              0x0, 0x1,  0x1, 0xF4, 0x13, 0x88, 0x0, 0x0,  0x0, 0x0};
u8 D_808023A0_chchuffy[40] = {0x0,  0x13, 0x4, 0xE7, 0x0, 0xA,  0x0,  0xF3, 0x0, 0x16,
                              0x7D, 0x0,  0x0, 0x1,  0x1, 0xF4, 0x13, 0x88, 0x0, 0x0,
                              0x0,  0x13, 0x4, 0xE7, 0x0, 0xA,  0x1,  0x0,  0x0, 0x16,
                              0x7D, 0x0,  0x0, 0x1,  0x1, 0xF4, 0x13, 0x88, 0x0, 0x0};
u8 D_808023C8_chchuffy[20] = {0x0,  0x13, 0x4, 0xC1, 0x0, 0xA,  0x0,  0x66, 0x0, 0x16,
                              0x7D, 0x0,  0x0, 0x1,  0x1, 0xF4, 0x13, 0x88, 0x0, 0x0};
u8 D_808023DC_chchuffy[16] = {0x2, 0x6, 0x0, 0x13, 0x4,  0xE9, 0x0, 0x7,
                              0x0, 0x1, 0x1, 0xF4, 0x1F, 0x40, 0x0, 0x0};
u32 D_808023EC_chchuffy[18] = {0x0,        0x0,      0x41600000, 0x970044, 0x41600000, 0x970044,
                               0x41600000, 0x97004A, 0x41600000, 0x990044, 0x41600000, 0x990244,
                               0x41600000, 0x990044, 0x41600000, 0x99004A, 0x41600000, 0x9A004A};
int D_80802434_chchuffy[18] = {0x20502A5,
                               0x6A90001,
                               (u32) &D_808023EC_chchuffy,
                               (u32) func_808009CC_chchuffy,
                               (u32) func_80105834,
                               (u32) func_808019A4_chchuffy,
                               0x0,
                               0x0,
                               0x0,
                               0x880464,
                               (u32) func_80801C78_chchuffy,
                               (u32) func_80108EE8,
                               0x2AC0000,
                               (u32) func_80801B8C_chchuffy,
                               (u32) func_80107C2C,
                               -0x7F7FFFFE,
                               (u32) func_80800864_chchuffy,
                               0x0};
s16 D_8080247C_chchuffy[7][4] = {
    0x4ED, 0x669, 0x2,   0x4, 0x4EE, 0x66A, 0x0,   0x2, 0x4F3, 0x6CC, 0xE,   0xC, 0x4F0, 0x6AA, 0x2,
    0x0,   0x4EF, 0x6A9, 0x2, 0x0,   0x4F2, 0x6BC, 0xF, 0xD,   0x4F1, 0x6BB, 0x6, 0x1};
u32 D_808024B4_chchuffy[7] = {0x9500CB8, 0x964, 0x5400C68, 0xDAE0CC8, 0x68A, 0xAF60CC0, 0xAF60B74};
u8 D_808024D0_chchuffy[24] = {0x3C, 0x23, 0xD7, 0xA,  0x3D, 0xA3, 0xD7, 0xA,
                              0x3E, 0x19, 0x99, 0x9A, 0x3E, 0x8F, 0x5C, 0x29,
                              0x3F, 0xC,  0xCC, 0xCD, 0xBF, 0x80, 0x0,  0x0};
u8 D_808024E8_chchuffy[20] = {0x3D, 0x38, 0x51, 0xEC, 0x3D, 0xEB, 0x85, 0x1F, 0x3E, 0x5C,
                              0x28, 0xF6, 0x3E, 0xD4, 0x7A, 0xE1, 0xBF, 0x80, 0x0,  0x0};
s32 D_808024FC_chchuffy[14] = {0x3C23D70A, 0x3E23D70A, 0x3E570A3D, 0x3E75C28F, 0x3E851EB8,
                               0x3E8F5C29, 0x3E9EB852, 0x3EC7AE14, 0x3F028F5C, 0x3F2147AE,
                               0x3F400000, 0x3F5EB852, 0x3F7851EC, -0x40800000};
s32 D_80802534_chchuffy[13] = {0x3DAE147B, 0x3E3D70A4, 0x3E666666, 0x3E800000, 0x3E8A3D71,
                               0x3E970A3D, 0x3EB33333, 0x3EE66666, 0x3F11EB85, 0x3F30A3D7,
                               0x3F4F5C29, 0x3F6B851F, -0x40800000};
s32 D_80802568_chchuffy[2] = {0x44BB8000, 0x451C4000};
s32 D_80802570_chchuffy[3] = {-0x3BD10000, 0x447A0000, -0x3CEA0000};
s32 D_8080257C_chchuffy[3] = {0x0, 0xFF, 0x0};
s32 D_80802588_chchuffy[3] = {0x0, 0x0, 0x0};
s32 D_80802594_chchuffy[3] = {0x0, 0x0, 0x0};
s32 D_808025A0_chchuffy[17] = {0x1D09DD,  0x190000,  0x7000A,  -0x180032, -0x40005,  0x190005,
                               0x2CFFC9,  0x12CFFE7, -0xEFDA8, 0x19001B,  0xA0014,   0x220080,
                               0x1800400, 0x500002A, 0xC00C0,  0x1800280, 0x64020000};
s32 D_808025E4_chchuffy[19] = {0x1D09DD,  0x190000, 0x7000A,   -0x40005,  0x500005,
                               0x50000,   0x2CFFC4, 0xC8FFC4,  0x3C0190,  0x3C001B,
                               0x5000A,   0x220080, 0x2000400, 0x500002A, 0xC00C0,
                               0x1800280, 0x150000, 0xD96402,  0x0};
u8 D_80802630_chchuffy[76] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x19, 0x0,  0x0,  0x0, 0x7,  0x0,  0xA,  0xFF, 0xFB, 0xFF, 0xFB,
    0x0, 0x50, 0x0, 0x5,  0x0, 0x5,  0x0,  0x0,  0x0, 0x2C, 0xFF, 0xC4, 0x0,  0xC8, 0xFF, 0xC4,
    0x0, 0x3C, 0x1, 0x90, 0x0, 0x3C, 0x0,  0x1B, 0x0, 0x5,  0x0,  0xA,  0x0,  0x22, 0x0,  0x80,
    0x3, 0x0,  0x6, 0x0,  0x8, 0x0,  0x0,  0x2A, 0x0, 0xC,  0x0,  0xC0, 0x1,  0x80, 0x2,  0x80,
    0x0, 0x15, 0x0, 0x0,  0x0, 0xD9, 0x64, 0x2,  0x0, 0x0,  0x0,  0x0};
s16 D_8080267C_chchuffy[10] = {0x206, 0x13, 0x4DC, 0x7, 0x16, 0x0, 0x1, 0x1F4, 0x1388, 0x0};
s32 D_80802690_chchuffy[5] = {0x1304C0, 0x167D00, 0xA00E6, 0x101F4, 0x13880000};
u8 D_808026A4_chchuffy[8] = {0x0, 0x0, 0x4, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF};
f32 D_808026AC_chchuffy[3] = {-7.5e+02f, 1e+02f, -858.0f};
f32 D_808026B8_chchuffy[3] = {-7.5e+02f, 2.2e+02f, -858.0f};
f32 D_808026C4_chchuffy[3] = {-8.7e+02f, 324.0f, -1035.0f};
f32 D_808026D0_chchuffy[3] = {-6.5e+02f, 7.7e+02f, -835.0f};
f32 D_808026DC_chchuffy[3] = {115.0f, 303.0f, -1292.0f};
f32 D_808026E8_chchuffy[3] = {465.0f, 7.6e+02f, -851.0f};
int D_808026F4_chchuffy[19] = {0x2DB0316,
                               0x1,
                               0x0,
                               (u32) func_80802164_chchuffy,
                               (u32) func_80105834,
                               (u32) func_8010A73C,
                               0x0,
                               0x0,
                               0x0,
                               0xC04,
                               0x0,
                               (u32) func_80108ED0,
                               0x0,
                               (u32) func_80801F84_chchuffy,
                               (u32) func_80107C2C,
                               -0x7FFFFFFE,
                               (u32) func_80801FA4_chchuffy,
                               0x0,
                               0x0};
