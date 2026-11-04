// Most likely the inflatable bouncy castle of Witchyworld's Crazy Castle: it inflates during the
// pump cutscene, spawns a jump pad once inflated, and rebuilds its collision mesh.
#include "common.h"

extern int D_80800930_chbouncycastle[];
extern int D_80800978_chbouncycastle[];
extern int D_808009C0_chbouncycastle[];
extern s32 D_80800A08_chbouncycastle[];
typedef struct {
    u8 pad_0[0x70];
    u32 pad_5 : 7;
    u32 active : 1;
    u32 pad_6 : 2;
    u32 triggered : 1;
    u32 pad_7 : 21;
    u32 pad_8;
    u32 pad_1 : 8;
    u32 kind : 4;
    u32 pad_2 : 20;
    u32 pad_3 : 19;
    u32 done : 1;
    u32 pad_4 : 12;
} BounceCastleFlags29;
extern void *func_801039E4(Unk80132ED0 *);
extern void *func_80104248(Actor *, void *);
extern void *func_80100094(Actor *, u32);
typedef struct {
    s32 local_0;
} BounceTransform;
typedef struct {
    u8 pad_0[0x28];
    s32 local_0;
} BounceRenderTransform;
extern void _chbouncycastle_entrypoint_4(void);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern void *func_80103AA0(Unk80132ED0 *);
extern void func_80102424();
typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 9;
    u32 local_0 : 1;
    u32 pad_2 : 22;
} BounceCastleUpdateFlags;
typedef struct {
    u8 pad[0x76];
    u16 hi : 9;
    u16 lo : 7;
} BccBits;
extern void func_80101EE4(Actor *, f32);
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
typedef struct {
    u8 pad_0[4];
    f32 local_0[3];
    s32 local_1;
    s32 local_2;
} BounceCastleCheckpoint;
extern s32 func_800BF744(s32, s32);
extern s32 func_8010D278(s32);
extern s32 D_80800A5C_chbouncycastle[];
extern u8 D_80800A50_chbouncycastle[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C3868(u8, f32, f32, f32, f32);
void func_8080051C_chbouncycastle();

int chbouncycastle_entrypoint_0()
{
    return (int) &D_80800930_chbouncycastle;
}

int chbouncycastle_entrypoint_1()
{
    return (int) &D_80800978_chbouncycastle;
}

int chbouncycastle_entrypoint_2(void)
{
    return (int) &D_808009C0_chbouncycastle;
}

int chbouncycastle_entrypoint_3()
{
    return (int) D_80800A08_chbouncycastle;
}

void chbouncycastle_entrypoint_4(Actor *actor)
{
    s32 pad0;
    u8 *model;
    s32 *saved_ptr;
    void *mesh;
    model = func_801039E4(actor->unk0);
    saved_ptr = func_80100094(actor, 0);
    func_80103D48(actor);
    *saved_ptr = *(s32 *) (model + 0x28);
    if (*(s16 *) ((u8 *) actor + 0x8C) &&
        (actor->unk70_10 == 2 || ((BounceCastleFlags29 *) actor)->kind)) {
        mesh = func_80104248(actor, model);
        func_8008B304(mesh);
        func_800DF41C(func_8008B4D4(mesh));
    } else {
        *(s32 *) (model + 0x28) = 0;
    }
    if (((BounceCastleFlags29 *) actor)->kind != 1 &&
        (((BounceCastleFlags29 *) actor)->active || ((BounceCastleFlags29 *) actor)->triggered))
        func_800DF818(func_80103CDC(actor, model));
    func_800DF830(1);
    func_80103D70(actor);
    ((BounceCastleFlags29 *) actor)->done = 1;
}

// Rebuilds the map-collision mesh from the model.
void func_80800148_chbouncycastle(u8 **actor)
{
    s32 old_mesh;

    old_mesh = func_801065A4();
    if (old_mesh != 0) {
        _glidmake_entrypoint_4(old_mesh);
    }
    func_8010647C(actor, _glidmake_entrypoint_5(*(u16 *) ((char *) *actor + 0x14), 0));
}

void func_80800198_chbouncycastle(Actor *actor, s32 unk_1)
{
    BounceTransform *transform;
    transform = func_80100094(actor, 0);
    func_800DF47C(_chbouncycastle_entrypoint_4, actor);
    func_800DE448(0, 0, actor->scale, 0, func_8010347C(actor->unk0));
    if (actor->unk7C_12) {
        ((BounceRenderTransform *) func_80103AA0(actor->unk0))->local_0 = transform->local_0;
        if (actor->unk79_4) {
            actor->unk79_4--;
            if (!actor->unk79_4)
                func_80800148_chbouncycastle(actor);
        }
    }
}

void func_80800254_chbouncycastle(Actor *actor)
{
    s32 state;

    state = actor->unk70_10;
    if (state == 2) {
        func_8080051C_chbouncycastle();
        if (func_80101DDC(actor)) {
            func_80102424(actor, 3);
            func_800DA544(0xB2);
            actor->unk79_4 = 3;
        }
        state = actor->unk70_10;
    }
    if (state == 2 || actor->unk79_4) {
        ((BounceCastleUpdateFlags *) actor)->local_0 = 1;
    } else {
        ((BounceCastleUpdateFlags *) actor)->local_0 = 0;
    }
}

s32 func_80800308_chbouncycastle(Actor *actor, s32 msg, s32 arg)
{
    u8 *checkpoint;
    Actor *jump_pad;

    switch (msg) {
        case 0xB:
            if (arg == 1) {
                _capod_entrypoint_14();
                _capod_entrypoint_13(actor->unk0, 0, 0xA, 0x2910);
                func_80108B04(actor, 0x210);
                return 4;
            }
            return 3;
        case 0x49:
            if (arg == 0x20) {
                func_80102424(actor, 2);
                func_80101EE4(actor, 0.21590909f);
                actor->unk79_4 = 0;
                _capod_entrypoint_13(actor->unk0, 0, 1, 0x2830);
                break;
            }
            return 0;
        case 0x3D:
            checkpoint = func_80100094(actor, 0);
            jump_pad = func_80108528(0x210, (f32 *) (checkpoint + 4), (s32) *(f32 *) (checkpoint + 0x14),
                                    &actor);
            ((BccBits *) jump_pad)->hi = *(s32 *) (checkpoint + 0x10);
            _chappearfx_entrypoint_1(jump_pad, 0x22, 1, 1.0f);
            return 1;
        default:
            return 0;
    }
    return 1;
}

void func_8080045C_chbouncycastle(Actor *actor)
{
    BounceCastleCheckpoint *checkpoint;

    checkpoint = (BounceCastleCheckpoint *) func_80100094(actor, 0);
    _subaddiemarker_entrypoint_0(actor, 0x154, checkpoint->local_0, 1);
    if (!func_800DA298(0xB2)) {
        func_80102424(actor, 1);
        func_80101EE4(actor, 0.2159091f);
    } else {
        func_80108A30(0x210, checkpoint->local_0, checkpoint->local_2, checkpoint->local_1);
        func_80102424(actor, 3);
    }
    actor->unk79_4 = 3;
    if (func_800EA05C() != 0xE1)
        func_8010A624(actor);
}

// Plays the inflation sounds, one per step.
void func_8080051C_chbouncycastle(Actor *actor)
{
    s32 i;
    s32 *flag_ptr;
    f32 pitch;
    u8 sound;
    s32 count = 4;
    for (i = 0, flag_ptr = D_80800A5C_chbouncycastle; i < count;
         i++, flag_ptr++) {
        if (func_80101E14(actor, *flag_ptr)) {
            pitch = func_800F10B4((f32) i, 0.0f, (f32) (count - 1), 0.3f, 0.5f);
            sound = _subaddieaudioquick_entrypoint_1(actor, actor->position);
            func_800C3868(sound, 0.15f, 0.25f, pitch, pitch + 0.12f);
            func_800C4350((u8) (s32) sound, actor->position, D_80800A50_chbouncycastle);
        }
    }
}

void func_80800670_chbouncycastle(s32 data[3])
{
    s32 handle;
    handle = func_800CBDD4(&data[1], 0x64, 1);
    data[10] = handle;
    if (handle != -1) {
        // Matching: "| 0" is needed for the match.
        func_800CBB80(data[10], func_800DA298(0xB2) | 0);
    }
}

int func_808006C4_chbouncycastle(Actor *actor)
{
    u16 bits;
    bits = *(u16 *) ((char *) actor + 0x72);
    switch ((bits & 0xFFFFu) >> 10) {
        case 2:
            if (func_800D9078((void *) ((char *) actor + 0x58))) {
                func_800D1000(0x19, 1, 0, 1, 0);
                func_80101FDC(actor, 1);
            }
            break;

        case 3:
            if (func_800D9078((void *) ((char *) actor + 0x58))) {
                func_800D1000(0x15, 1, 0, 1, 0);
                func_80101FDC(actor, 1);
            }
    }
}

// Pump cutscene start.
int func_80800774_chbouncycastle(s32 param_0, s32 msg, s32 arg)
{
    Actor *actor = param_0;
    if (msg == 0x49) {
        if (_glcutDll_entrypoint_19(0x22)) {
            _capod_entrypoint_13(actor->unk0, 0, 0xF, 0x2910);
            func_80101FDC(actor, 2);
            actor->unk58 = 0.15f;
            return 1;
        }
        if (_glcutDll_entrypoint_19(0x21)) {
            _capod_entrypoint_13(actor->unk0, 0, 0xC, 0x2910);
            func_80101FDC(actor, 3);
            actor->unk58 = 0.15f;
            return 1;
        }
    }
    return 0;
}

void func_80800828_chbouncycastle(s32 arg0)
{
}

s32 func_80800830_chbouncycastle(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    if (param_1 == 0x95) {
        local_0 = param_0->unk6C_9 == 0x3C7 ? 1 : 0xB;
        local_1 = param_0->unk6C_9 == 0x3C7 ? 2 : 1;
        if (func_8010D278(local_1) == local_0) {
            func_800BF744(local_1, 0);
            func_8010A624(param_0);
            param_0->unk64_16 = 0;
            return 1;
        }
        func_800BF744(local_1, 1);
        return 1;
    }
    return 0;
}

extern void func_80105834();
extern void func_80107C2C();
extern void func_80101870();
extern void func_80102EC0();
extern void func_8010A73C();
u32 D_80800910_chbouncycastle[8] = {0x0,        0x0,       0x40E00000, 0x1120044,
                                    0x40E00000, 0x112000A, 0x40E00000, 0x1120084};
int D_80800930_chbouncycastle[18] = {0x2AE034C,
                                     0x6BD0001,
                                     (u32) &D_80800910_chbouncycastle,
                                     (u32) func_80800254_chbouncycastle,
                                     (u32) func_80105834,
                                     (u32) func_80800198_chbouncycastle,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x1C08,
                                     0x0,
                                     0x0,
                                     0x1C0000,
                                     (u32) func_8080045C_chbouncycastle,
                                     (u32) func_80107C2C,
                                     -0x7FFFDBFE,
                                     (u32) func_80800308_chbouncycastle,
                                     0x0};
int D_80800978_chbouncycastle[18] = {0x2B30351,
                                     0x1,
                                     0x0,
                                     (u32) func_808006C4_chbouncycastle,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x4,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800670_chbouncycastle,
                                     (u32) func_80107C2C,
                                     -0x7FFFF9FE,
                                     (u32) func_80800774_chbouncycastle,
                                     0x0};
int D_808009C0_chbouncycastle[18] = {0xAC03C7,
                                     0x7A00001,
                                     0x0,
                                     (u32) func_80102EC0,
                                     (u32) func_80105834,
                                     (u32) func_8010A73C,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x800,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800828_chbouncycastle,
                                     (u32) func_80107C2C,
                                     -0x7FFFF3FE,
                                     (u32) func_80800830_chbouncycastle,
                                     0x0};
s32 D_80800A08_chbouncycastle[18] = {0xAC03C8,
                                     0x7A00001,
                                     0x0,
                                     (u32) func_80102EC0,
                                     (u32) func_80105834,
                                     (u32) func_8010A73C,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x800,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800828_chbouncycastle,
                                     (u32) func_80107C2C,
                                     -0x7FFFF3FE,
                                     (u32) func_80800830_chbouncycastle,
                                     0x0};
u8 D_80800A50_chbouncycastle[12] = {0x0, 0x13, 0x4, 0xFA, 0x0, 0x18, 0x0, 0x2, 0x0, 0x11, 0x0, 0x0};
s32 D_80800A5C_chbouncycastle[5] = {0x3E5D1746, 0x3ECCCCCD, 0x3F266666, 0x3F6147AE, 0x0};
