#include "common.h"

#define AF(p, i) (*(f32 *) &(p)->actorData[i])
extern s32 D_80800D3C_chgoldfish[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern u8 D_80800D4C_chgoldfish[];
extern f32 func_800BED50(void);
extern s32 _fxsplash_entrypoint_2(f32 *, f32);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_80013970(f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int D_80800D94_chgoldfish[];
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} GoldfishState;
extern u8 D_80800D20_chgoldfish[];
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800CD08C(s32, u32 *);
extern f32 func_80090010(void);
extern f32 func_80103EF4(Actor *);
extern f32 func_8010CD28(Actor *);
extern void func_800EFCD8(f32 *, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C();
extern void *func_800BEF00(f32 *, f32 *, f32 *, s32);
s32 func_80800BA8_chgoldfish();
void func_808005F0_chgoldfish();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(),
    func_80800000_chgoldfish();

void func_80800000_chgoldfish(actor) ALCSPlayer *actor;
{
    if (func_800DA298(0x1BF) != 0) {
        func_800FFA88(*(void **) ((char *) actor + 0x0));
        return;
    }

    if (func_800DA298(0x1DA) != 0) {
        func_808005F0_chgoldfish(actor, 6);
    } else if (func_800DA298(0x51E) != 0) {
        func_808005F0_chgoldfish(actor, 3);
    }
    *(f32 *) ((char *) actor + 0x24) = *(f32 *) ((char *) actor + 0x38);
    *(f32 *) ((char *) actor + 0x4C) = 90.0f;
    func_80800BA8_chgoldfish(actor, (char *) actor + 4);
}

f32 func_80800AB4_chgoldfish(Actor *actor, f32 *start, f32 *end, f32 *out_pos, f32 duration,
                             f32 height);

void func_80800964_chgoldfish();

void func_80800924_chgoldfish();

// Roysten state machine; state 5 is being carried, 7 is thrown into water, 9 is the reward dialog.
void func_8080009C_chgoldfish(Actor *actor)
{
    f32 blend[1];
    f32 progress;
    f32 prev_y;

    switch (((GoldfishState *) actor)->st) {
        case 2:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            func_8010C964(actor);
            // Matching: empty block steers IDO's codegen.
            if (1) {
            }
            break;
    }
    switch (((GoldfishState *) actor)->st) {
        case 1:
            if (func_800DA298(0x51E)) {
                func_808005F0_chgoldfish(actor, 2);
                return;
            }

            _subaddiedialog_entrypoint_7(actor, actor->position, D_80800D20_chgoldfish);
            return;

        case 2:
            if (!func_800DA298(0x1DA)) {
                func_800DA544(0x1DA);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x15BF, 0xE, actor->position, 0x67);
            }

            return;

        case 3:
            if (func_800D90A4(&actor->unk58)) {
                actor->unk54 = func_800DC178(0.0f, 360.0f);
                actor->unk50 = actor->rotation[2] == 90.0f ? 270.0f : 90.0f;
                func_800EE7F8((f32 *) &actor->actorData[4], actor->position);
                func_800CD08C((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1, actor->actorData);
                if (func_80800BA8_chgoldfish(actor, actor->actorData)) {
                    func_808005F0_chgoldfish(actor, 4);
                }
            }

            break;

        case 4:
            if (func_80800AB4_chgoldfish(actor, &actor->actorData[4], actor->actorData,
                                         actor->position, 0.5f, 50.0f) == 1.0f) {
                func_808005F0_chgoldfish(actor, 3);
            }

            return;
        case 5:
            func_8008FE94(1, actor->actorData);
            blend[0] =
                func_80800AB4_chgoldfish(actor, &actor->actorData[4], actor->actorData,
                                         actor->position, 1.0f, 150.0f);

            if (1.0f - blend[0] == 0.0f) {
                func_80090708(0);
                func_808005F0_chgoldfish(actor, 6);
            }

            actor->scale = AF(actor, 3) * (1.0f - blend[0] * 0.5f);
            func_80800924_chgoldfish(actor);
            return;
        case 6:
            func_8008FE68(actor->position);
            actor->position[1] += 200.0f;

            if (func_800D90A4(&actor->unk58)) {
                actor->unk58 = 40.0f;
                _subaddiedialog_entrypoint_11(actor->unk0, func_800DC128(0x15C2, 0x15C5), 0xE,
                                              actor->position, 0x67);
            }

            if (func_800F71D4(func_800F54E4())) {
                func_808005F0_chgoldfish(actor, 7);
            }

            break;
        case 7:
            prev_y = actor->position[1];
            progress = func_80800AB4_chgoldfish(actor, &actor->actorData[4], actor->actorData,
                                               actor->position, 1.0f, 200.0f);
            actor->rotation[0] = func_80013970(func_800F1214(progress, 270.0f, 540.0f)) * 70.0f;

            if (func_800D90A4(&actor->unk58)) {
                func_808005F0_chgoldfish(actor, 8);
            }

            if (actor->position[1] <= AF(actor, 7)) {
                if (AF(actor, 7) < prev_y) {
                    func_80800964_chgoldfish(actor->position);
                }
            }

            actor->scale = AF(actor, 3) * progress;
            break;

        case 8:
            if (func_8010CE70(actor, 6, -1)) {
                func_808005F0_chgoldfish(actor, 9);
            }

        case 10:
            break;
    }
}

s32 func_808004AC_chgoldfish(actor, msg, msg_data)
Actor *actor;
s32 msg;
s32 msg_data;
{
    switch (msg) {
        case 0x2E:
            switch (*(s16 *) &msg_data) {
                case 0x15BF:
                    func_808005F0_chgoldfish(actor, 3);
                    break;
                case 0x15C0:
                    func_800C7074(0x30, !func_800DA298(0x648));
                    func_808005F0_chgoldfish(actor, 10);
            }

            return 1;
        case 0x2F:
            if (*(s16 *) &msg_data == 0x15C0 && ((s16 *) &msg_data)[1] == 1 && func_800DA298(0x649))
                func_800CF700();
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800D3C_chgoldfish, actor->scale);
            return 1;
        case 0x3E:
            if ((actor->unk70_10 == 3 || actor->unk70_10 == 4) &&
                func_800F64A4(func_800F54E4(), 1))
                func_808005F0_chgoldfish(actor, 5);
            return 1;
        default:
            return 0;
    }
}

void func_808005F0_chgoldfish(actor, state) Actor *actor;
s32 state;
{
    Vec3f ray_start;
    Vec3f hit_normal;
    s32 attempt;
    u8 *hit;

    switch (state) {
        case 3:
            actor->unk58 = 1.0f;
            func_80102424(actor, 3);
            return;
        case 4:
            actor->unk58 = 0.5f;
            func_80102424(actor, 4);
            return;
        case 5:
            func_800FC6B0(0xE);
            func_8008FE94(1, actor->actorData);
            func_800EE7F8((f32 *) &actor->actorData[4], actor->position);
            actor->unk58 = 1.0f;
            actor->unk54 = func_80090010();
            actor->unk50 = 0;
            func_80090708(1);
            func_80102424(actor, 5);
            return;
        case 6:
            actor->unk64_16 = 0;
            actor->unk58 = 40.0f;
            func_80102424(actor, 6);
            return;
        case 7:
            actor->unk58 = 1.0f;
            func_8008FE94(1, ((f32 *) &actor->actorData[4]));
            actor->unk54 = func_80090010();
            for (attempt = 0; attempt != 4; attempt++) {
                func_800EFCD8(((f32 *) actor->actorData), actor->unk54, 300.0f);
                func_800EF04C(((f32 *) actor->actorData), ((f32 *) &actor->actorData[4]));
                func_800EE7F8(ray_start.f, ((f32 *) actor->actorData));
                ray_start.pos.y = ((f32 *) actor->actorData)[5] + 500.0f;
                actor->rotation[2] = 0.0f;
                actor->unk50 = 0.0f;
                ((f32 *) actor->actorData)[1] = ((f32 *) actor->actorData)[5] - 500.0f;
                hit = func_800BEF00(ray_start.f, ((f32 *) actor->actorData), hit_normal.f, 0);

                if (hit) {
                    if (func_800C84B0(*(s32 *) (hit + 8)) == 4) {
                        ((f32 *) actor->actorData)[7] = ((f32 *) actor->actorData)[1];
                        func_800EE7F8(ray_start.f, (f32 *) actor->actorData);
                        ((f32 *) actor->actorData)[1] -= 3.0f * func_80103EF4(actor);
                        if (func_800BEF00(ray_start.f, (f32 *) actor->actorData, hit_normal.f, 0) ==
                            NULL) {
                            actor->unk64_16 = 1;
                            func_80102424(actor, 7);
                            return;
                        }
                    }
                    actor->unk54 += 90.0f;
                }
            }
            return;
        case 8:
            func_800FC6B0(0xE);
            actor->unk54 = func_8010CD28(actor);
            func_800F8300(func_800F54E4(), 1, actor->position);
            func_80102424(actor, 8);
            return;
        case 9:
            _subaddiedialog_entrypoint_11(actor->unk0, 0x15C0, 0x4E, actor->position, 0x67);
            func_80102424(actor, 9);
            return;
        case 10:
            func_800F82D4(func_800F54E4(), 0);
            _subaddiefade_entrypoint_3(actor);
            func_80102424(actor, 10);
            return;
        default:
            func_80102424(actor, state);
    }
}

void func_80800924_chgoldfish(u8 *actor)
{
    func_800BBCB8(actor + 4, 0, *(s32 *) (actor + 0x38), 1, &D_80800D4C_chgoldfish);
}

// Splash, ripple and bubble effects when he lands in water.
void func_80800964_chgoldfish(f32 *pos)
{
    f32 splash_pos[3];
    f32 water_y;
    s32 fx;
    water_y = func_800BED50();
    splash_pos[0] = pos[0];
    splash_pos[1] = water_y;
    splash_pos[2] = pos[2];
    func_800C4140(0x7FFB5C09, pos, 0x4B000FA);
    fx = _fxsplash_entrypoint_2(splash_pos, 35.0f);
    _fxripple_entrypoint_0(3, splash_pos);
    func_800BA930(fx, -350, 300, -350, 350, 500, 350);
    func_800BA22C(fx, 10);
    func_800BA930(fx, -150, 500, -150, 150, 800, 150);
    func_800BA22C(fx, 10);
    _fxsplash25d_entrypoint_0(splash_pos);
    splash_pos[1] -= 30.0f;
    fx = _fxairbub_entrypoint_1(splash_pos, 20.0f, water_y, 1.0f);
    func_800BA930(fx, -60, -250, -60, 60, -150, 60);
    func_800BA22C(fx, 8);
}

f32 func_80800AB4_chgoldfish(Actor *actor, f32 *start, f32 *end, f32 *out_pos, f32 duration,
                             f32 height)
{
    f32 t;

    func_800D90A4(&actor->unk58);
    t = func_800F10B4(actor->unk58, duration, 0.0f, 0.0f, 1.0f);
    func_800EFE50(out_pos, start, end, t);
    out_pos[1] += func_80013970(t * 180.0f) * height;
    actor->rotation[1] = func_800F1FF0(actor->rotation[1], actor->unk54, 0.5f, 0.1f, 10.0f);
    actor->rotation[2] = func_800F1FF0(actor->rotation[2], actor->unk50, 0.5f, 0.1f, 10.0f);
    return t;
}

s32 func_80800BA8_chgoldfish(actor, pos)
Actor *actor;
f32 *pos;
{
    f32 ray_start[3];
    f32 hit_normal[3];
    func_800EFA4C(ray_start, pos[0], pos[1] + 300.0f, pos[2]);
    pos[1] -= 300.0f;
    if (func_800BEF00(ray_start, pos, hit_normal, 0)) {
        pos[1] += 20.0f;
        return 1;
    }
    return 0;
}

int chgoldfish_entrypoint_0()
{
    return (int) &D_80800D94_chgoldfish;
}

u8 D_80800CC0_chgoldfish[96] = {
    0x0,  0x0, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x40, 0x0, 0x0, 0x0, 0x1, 0xB7, 0x0, 0x49,
    0x40, 0x0, 0x0, 0x0, 0x1, 0xB7, 0x0, 0x49, 0x3F, 0x0, 0x0, 0x0, 0x1, 0xB7, 0x0, 0x49,
    0x3F, 0x0, 0x0, 0x0, 0x1, 0xB7, 0x0, 0x49, 0x0,  0x0, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0,
    0x0,  0x0, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x40, 0x0, 0x0, 0x0, 0x1, 0xB7, 0x0, 0x49,
    0x40, 0x0, 0x0, 0x0, 0x1, 0xB7, 0x0, 0x49, 0x40, 0x0, 0x0, 0x0, 0x1, 0xB7, 0x0, 0x49,
    0x40, 0x0, 0x0, 0x0, 0x1, 0xB7, 0x0, 0x49, 0x40, 0x0, 0x0, 0x0, 0x1, 0xB7, 0x0, 0x49};
u8 D_80800D20_chgoldfish[28] = {0x3, 0x3F, 0x1,  0x90, 0x15, 0xBE, 0x15, 0xC1, 0x0, 0x0,
                                0x2, 0x1,  0x12, 0x8,  0x0,  0x0,  0x0,  0x67, 0x0, 0x0,
                                0x0, 0xE,  0x2,  0x3C, 0x0,  0x0,  0x0,  0x0};
s32 D_80800D3C_chgoldfish[4] = {0x42480000, 0x42480000, 0x42480000, 0x0};
u8 D_80800D4C_chgoldfish[72] = {
    0x0,  0x1D, 0x9,  0xDE, 0x0,  0x15, 0x0,  0x19, 0x0,  0x1C, 0x0,  0xA,  0xFF, 0xF4, 0x0,
    0x0,  0xFF, 0xF4, 0x0,  0xC,  0x0,  0x2,  0x0,  0xC,  0x0,  0x1B, 0xFE, 0x70, 0xFC, 0xE0,
    0x0,  0x22, 0x0,  0x33, 0x0,  0x40, 0x0,  0xC,  0x0,  0xC,  0x0,  0x2C, 0xFF, 0xEC, 0x0,
    0x32, 0xFF, 0xEC, 0x0,  0x14, 0x0,  0xFA, 0x0,  0x14, 0x0,  0x27, 0x1,  0x90, 0x1,  0x90,
    0x3,  0x20, 0x3,  0x20, 0x0,  0x2B, 0x0,  0x66, 0x0,  0x80, 0x0,  0x0};
int D_80800D94_chgoldfish[19] = {0x10C03EF,
                                 0x6FA0001,
                                 (u32) &D_80800CC0_chgoldfish,
                                 (u32) func_8080009C_chgoldfish,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x200101,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_80800000_chgoldfish,
                                 (u32) func_80107C2C,
                                 -0x7FFFFC00,
                                 (u32) func_808004AC_chgoldfish,
                                 0x0,
                                 0x0};
