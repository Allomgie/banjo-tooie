// Arena doors of the three Klungo fights (actors 0x41F, 0x420): locked during the fight, hum, spark
// when touched, and open on messages 7/8. A 3-entry table keyed by map id sets model and motion.
#include "common.h"

extern int D_808004C0_chklungodoors[];
extern void func_8010A800();
// Per-fight door settings, selected by map id (3 entries).
typedef struct {
    s16 map_id;
    s16 angle;
    s32 unk_4;
    s32 unk_8;
    u16 unk_C;
    u8 locked;
    u8 unk_F;
} KlungoDoorSettings48;
extern KlungoDoorSettings48 D_80800490_chklungodoors[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern s32 _chdoormake_entrypoint_4(Actor *, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
typedef struct {
    u8 locked;
    u8 pad_1[15];
} KlungoDoorFlag;
extern KlungoDoorFlag D_8080049E_chklungodoors[];
extern u8 D_80800550_chklungodoors[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[2];
    u8 unk_6;
    u8 pad_7[9];
} KlungoDoor;
typedef struct {
    u8 pad_0[0x16];
    u16 unk_16;
} KlungoModel;
extern KlungoDoor D_80800498_chklungodoors[];
extern KlungoDoor D_8080049A_chklungodoors[];
typedef struct {
    u8 locked;
    u8 pad_1[15];
} KlungoFlag;
extern void func_80103140();
extern void func_8010A570(Actor *);
extern void func_800EC75C(s32, f32 *);
extern void _chelectricfence_entrypoint_1(Actor *, f32 *);
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);

int chklungodoors_entrypoint_0()
{
    return (int) &D_808004C0_chklungodoors;
}

int chklungodoors_entrypoint_1()
{
    extern int D_80800508_chklungodoors[];
    return (int) &D_80800508_chklungodoors;
}

void func_80800018_chklungodoors(Actor *actor)
{
    KlungoDoorSettings48 *settings;
    KlungoDoorSettings48 *entry;
    s32 i;
    s32 made;

    settings = NULL;
    for (i = 0, entry = D_80800490_chklungodoors; i < 3; i++, entry++) {
        if (func_800EA05C() == entry->map_id) {
            settings = entry;
            actor->actorData[4] = i;
            break;
        }
    }
    func_80102FDC(actor, settings->unk_4);
    func_8010A800(actor, 0);
    if (actor->unk6C_9 == 0x420) {
        if (settings->locked) {
            func_80103110(actor, 1);
            made = _chdoormake_entrypoint_4(actor, 0xA82A, settings->unk_C);
        } else {
            made = _chdoormake_entrypoint_3(actor, 0.0f, 90.0f, (f32) settings->angle, 0x122,
                                            settings->unk_C);
        }
        if (made) {
            _chdoormake_entrypoint_5(actor, 0.7f);
            _chdoormake_entrypoint_6(actor, 2.0f);
            _chdoormake_entrypoint_8(actor, settings->unk_F);
        }
    } else {
        if (settings->locked) {
            func_80103110(actor, 1);
            made = _chdoormake_entrypoint_4(actor, 0xA82A, -1);
        } else {
            made =
                _chdoormake_entrypoint_3(actor, 0.0f, 90.0f, (f32) settings->angle, 0x122, -1);
        }
        if (made) {
            _chdoormake_entrypoint_5(actor, 0.7f);
            _chdoormake_entrypoint_6(actor, 0.25f);
            _chdoormake_entrypoint_8(actor, settings->unk_F);
        }
    }
    if (settings->locked) {
        *(u16 *) &actor->unk0->unk24 = (*(u16 *) &actor->unk0->unk24 & 0x3F) | 0xCC40;
        func_80103110(actor, 1);
        func_8010A5B0(actor, made == 1);
    }
}

void func_80800234_chklungodoors(Actor *actor)
{
    s32 fade;

    _chdoor_entrypoint_0(actor);
    if (D_8080049E_chklungodoors[actor->actorData[4]].locked) {
        fade = _subaddiefade_entrypoint_0(actor);
        _subaddieaudioloop_entrypoint_4(actor, actor->position, fade > 0,
                                        D_80800550_chklungodoors);
        _subaddieaudioloop_entrypoint_0(actor,
                                        func_800F10B4((f32) fade, 0.0f, 255.0f, 0.7f, 1.4f));
        if (actor->unk70_10 == 1 && func_800D9078((f32 *) &actor->actorData[5]))
            func_8010A590(actor);
    }
}

s32 func_80800300_chklungodoors(Actor *actor, s32 msg, s32 arg)
{
    f32 pos[3];
    s32 arg_copy[1];

    switch (msg) {
        case 0x95:
            switch (actor->unk6C_9) {
                case 0x41F:
                    func_80103140(actor, D_80800498_chklungodoors[actor->actorData[4]].unk_0,
                                  (KlungoModel *) actor->unk0->unk16);
                    break;
                case 0x420:
                    func_80103140(actor, D_8080049A_chklungodoors[actor->actorData[4]].unk_0,
                                  (KlungoModel *) actor->unk0->unk16);
            }
            break;
        case 7:
            if (((KlungoFlag *) D_8080049E_chklungodoors)[actor->actorData[4]].locked) {
                func_8010A570(actor);
            }
            break;
        case 8:
            if (((KlungoFlag *) D_8080049E_chklungodoors)[actor->actorData[4]].locked) {
                func_8010A570(actor);
            }
            break;
        case 0x3F:
            // Touched: electric-fence spark at the touch position.
            arg_copy[0] = arg;
            func_800EC75C(arg_copy[0], pos);
            _chelectricfence_entrypoint_1(actor, pos);
            *(f32 *) &actor->actorData[5] = 0.2f;
            func_8010A570(actor);
            return 1;
    }
    return _chdoor_entrypoint_1(actor, msg, arg);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
KlungoDoorSettings48 D_80800490_chklungodoors[3] = {
    0x141, 0x1F4, 0x3FC00000, 0x7AE07AE, 0x318, 0x0, 0x2,
    0x15B, 0x1F4, 0x3FA00000, 0x7AE07AE, 0x319, 0x0, 0x2,
    0x15E, 0x15E, 0x3F800000, 0x94D094C, 0x31A, 0x1, 0xB};
int D_808004C0_chklungodoors[18] = {0xAC041F,
                                    0x7AE0004,
                                    0x0,
                                    (u32) func_80800234_chklungodoors,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0xC00,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    (u32) func_80800018_chklungodoors,
                                    (u32) func_80107C2C,
                                    -0x7FF7D3FE,
                                    (u32) func_80800300_chklungodoors,
                                    0x0};
int D_80800508_chklungodoors[18] = {0xAC0420,
                                    0x7AE0001,
                                    0x0,
                                    (u32) func_80800234_chklungodoors,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0xC00,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    (u32) func_80800018_chklungodoors,
                                    (u32) func_80107C2C,
                                    -0x7FF7D3FE,
                                    (u32) func_80800300_chklungodoors,
                                    0x0};
u8 D_80800550_chklungodoors[32] = {0x0, 0x13, 0x5,  0xB7, 0x0,  0x1,  0x0, 0xC8, 0x7, 0xD0, 0x0,
                                   0xA, 0x1,  0x66, 0x0,  0x16, 0x7D, 0x0, 0x0,  0x0, 0x0,  0x0,
                                   0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0};
