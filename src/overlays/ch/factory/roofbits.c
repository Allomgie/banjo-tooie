#include "ch/factory/roofbits.h"

extern void func_800EE7F8(void *param_0, s32 param_1);
extern void func_800EF1B8(void *param_0, s32 param_1, s32 param_2);
extern void _chexploder_entrypoint_3(void *param_0, void *param_1, s32 param_2);
extern Actor *func_80106790();
extern u8 D_80800920_chfactoryroofbits[];
extern u8 D_80800968_chfactoryroofbits[];
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern int D_80800974_chfactoryroofbits[];
extern u8 D_808009FC_chfactoryroofbits[];
extern u8 D_808009BC_chfactoryroofbits[];
extern void func_800DF500(f32, f32, s32);
extern void func_80101870();
extern int D_80800A08_chfactoryroofbits[];
extern f32 func_80103EF4(Actor *);
extern int _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern int D_80800A50_chfactoryroofbits[];
extern Vec3f D_80800A98_chfactoryroofbits;
extern s32 D_80800AA4_chfactoryroofbits[];
extern int D_80800AEC_chfactoryroofbits[];
extern int D_80800B34_chfactoryroofbits[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
void func_808000D4_chfactoryroofbits();

int func_80800000_chfactoryroofbits(s32 actor)
{
    func_800EFA4C(actor + 4, -1124.0f, 9002.0f, 1596.0f);
}

int func_8080003C_chfactoryroofbits(s32 actor, s32 msg, f32 param_2)
{
    f32 pos[3];
    if (msg == 0x40) {
        func_800EE7F8(pos, actor + 4);
        func_800EF1B8(pos, *(s32 *) (actor + 0x48), 0xC3160000);
        pos[1] -= 50.0f;
        _chexploder_entrypoint_3((void *) actor, pos, 0xC);
        return 1;
    } else if (msg == 0x90) {
        func_808000D4_chfactoryroofbits(actor);
        return 1;
    }
    return 0;
}

// Roof piece breaks: explosion, flag 0x196 and debris.
void func_808000D4_chfactoryroofbits(actor) Actor *actor;
{
    _chexploder_entrypoint_6(func_80106790(func_80101080(actor)), 600.0f, 800.0f);
    func_800DA544(0x196);
    func_800BABB8(0, actor->position, actor->position, actor->scale,
                  D_80800920_chfactoryroofbits);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800968_chfactoryroofbits);
}

int chfactoryroofbits_entrypoint_0()
{
    return (int) &D_80800974_chfactoryroofbits;
}

// Maps marker id to the flag of the breakable piece.
s32 func_8080015C_chfactoryroofbits(s32 marker_id)
{
    switch (marker_id) {
        case 0x4B:
            return 0x197;
        case 0x4C:
            return 0x198;
        case 0x4D:
            return 0x199;
        case 0x4E:
            return 0x19A;
        case 0xE:
            return 0x19B;
        default:
            return 0;
    }
}

// Hard-coded position and scale per breakable piece; returns its flag state.
s32 func_808001C0_chfactoryroofbits(marker_id, pos, scale, unk_3)
s32 marker_id;
f32 *pos;
f32 *scale;
f32 *unk_3;
{
    switch (marker_id) {
        case 0x4B:
            func_800EFA4C(pos, -1397.0f, 8063.0f, -632.0f);
            func_800EFA4C(scale, 0.94f, 0.73f, 1.0f);
            *unk_3 = 312.0f;
            break;
        case 0x4C:
            func_800EFA4C(pos, 174.0f, 8066.0f, -1017.0f);
            func_800EFA4C(scale, 0.94f, 0.73f, 1.0f);
            *unk_3 = 312.0f;
            break;
        case 0x4D:
            func_800EFA4C(pos, -1138.0f, 2148.0f, 2300.0f);
            func_800EFA4C(scale, 1.8f, 1.8f, 1.8f);
            *unk_3 = 0.0f;
            break;
        case 0x4E:
            func_800EFA4C(pos, 2303.0f, 2143.0f, -376.0f);
            func_800EFA4C(scale, 1.8f, 1.8f, 1.8f);
            *unk_3 = 0.0f;
            break;
        case 0xE:
            func_800EFA4C(pos, 2645.0f, 1494.0f, 2645.0f);
            func_800EFA4C(scale, 1.14f, 1.0f, 1.0f);
            *unk_3 = 0.0f;
            break;
        default:
            return 1;
    }
    return func_800DA298(func_8080015C_chfactoryroofbits(marker_id));
}

// Despawns if the piece flag is already set.
int func_808003C4_chfactoryroofbits(Actor *actor)
{
    if (func_808001C0_chfactoryroofbits(
            (u32) *(s32 *) ((char *) actor + 0x6C) >> 0x15, (s32 *) ((char *) actor + 0x4),
            (s32 *) ((char *) actor + 0x28), (s32 *) ((char *) actor + 0x44))) {
        func_800FFA88(*(s32 *) actor);
    }
}

// Hit handler: spawns debris, sets the piece flag and despawns.
int func_80800414_chfactoryroofbits(
    Actor *actor, s32 msg, struct { Unk80132ED0 *p; } hit)
{
    s32 emitter;
    f32 *pos;
    if (msg == 0x40) {
        if (*(u16 *) ((u8 *) hit.p + 0x18) & 1) {
            if ((((u32) *(u32 *) ((u8 *) func_80106790(hit.p) + 0x6C) << 11) >> 20) == 0x15D) {
                emitter = func_800B53A4(32);
                pos = actor->position;
                func_800BABB8(emitter, pos, 0, ((f32 *) actor->actorData)[6] * 0.5f,
                              D_808009BC_chfactoryroofbits);
                func_800BA930(emitter, -200, 400, -200, 200, 800, 200);
                func_800BA22C(emitter, 32);
            } else {
                emitter = func_800B53A4(16);
                pos = actor->position;
                func_800BABB8(emitter, pos, 0, ((f32 *) actor->actorData)[6],
                              D_808009BC_chfactoryroofbits);
                func_800BA22C(emitter, 16);
            }
        } else {
            emitter = func_800B53A4(8);
            pos = actor->position;
            func_800BABB8(emitter, pos, 0, ((f32 *) actor->actorData)[6] * 1.25f,
                          D_808009BC_chfactoryroofbits);
            func_800BA22C(emitter, 8);
        }
        _subaddieaudioquick_entrypoint_2(actor, pos, D_808009FC_chfactoryroofbits);
        func_800DA544(
            func_8080015C_chfactoryroofbits((u32) *(u32 *) ((u8 *) actor + 0x6C) >> 21));
        func_800FFAB0(actor);
        return 1;
    }
    return 0;
}

void func_808005DC_chfactoryroofbits(u8 *actor, s32 gfx)
{
    func_800DF500(*(f32 *) (actor + 0x28), *(f32 *) (actor + 0x2C), *(s32 *) (actor + 0x30));
    func_80101870(actor, gfx);
}

int *chfactoryroofbits_entrypoint_1()
{
    return &D_80800A08_chfactoryroofbits;
}

// Double door (flags 0x19C/0x19D, 0xA08).
void func_80800624_chfactoryroofbits(Actor *door)
{
    _chdoormake_entrypoint_3(door, door->rotation[1], 90.0f, func_80103EF4(door), 0x20AE,
                             0xA08);
    _chdoormake_entrypoint_5(door, 3.0f);
    _chdoormake_entrypoint_6(door, 7.0f);
    _chdoormake_entrypoint_8(door, 4);
    _chdoormake_entrypoint_9(door, 0, 1, 0x10);
    _chdoormake_entrypoint_10(door, 0, 0x19C);
    _chdoormake_entrypoint_9(door, 1, 0xB, 0x10);
    _chdoormake_entrypoint_10(door, 1, 0x19D);
}

int *chfactoryroofbits_entrypoint_2()
{
    return &D_80800A50_chfactoryroofbits;
}

void func_808006E8_chfactoryroofbits(s32 arg0)
{
    _chswitch_entrypoint_7(arg0, FLAG3_A08_UNK);
}

// Switch handler: spawns actor 0x3F3.
s32 func_80800708_chfactoryroofbits(Actor *actor, s32 msg, s32 msg_arg)
{
    Vec3f spawn_pos;
    switch (msg) {
        case 0x3D:
            spawn_pos = D_80800A98_chfactoryroofbits;
            func_80108528(0x3F3, spawn_pos.f, 0x10E, &actor);
            break;
        case 0x95:
            if (!_subaddiefind_entrypoint_2(0x3F3, 0))
                func_80108B04(actor, 0);
    }
    return _chswitch_entrypoint_10(actor, msg, msg_arg);
}

int chfactoryroofbits_entrypoint_3()
{
    return D_80800AA4_chfactoryroofbits;
}

void func_808007B8_chfactoryroofbits(s32 arg0)
{
    _chswitch_entrypoint_7(arg0, FLAG_163_STATION_UNLOCKED_GI);
    _chswitch_entrypoint_9(arg0);
}

// Starts the GI train-station cutscene when pressed.
int func_808007E4_chfactoryroofbits(Actor *actor, s32 msg, s32 msg_arg)
{
    if (msg == 7) {
        _glcutDll_entrypoint_6(0x102, 0x44);
    }
    // Matching: `msg | msg` is needed for the match.
    _chswitch_entrypoint_10(actor, msg | msg, msg_arg);
}

int chfactoryroofbits_entrypoint_4()
{
    return (int) &D_80800AEC_chfactoryroofbits;
}

// Door opened by a cutscene (flag 0x355).
s32 func_80800840_chfactoryroofbits(Actor *this)
{
    _chdoormake_entrypoint_0(this, 0x42b40000, 0x80, 0x355);
    _chdoormake_entrypoint_5(this, 3.0f);
    _chdoormake_entrypoint_6(this, 1.0f);
    _chdoormake_entrypoint_8(this, 4);
}

// Opens on cutscene message 0x86; other 0x49 messages are ignored.
s32 func_80800890_chfactoryroofbits(Actor *actor, s32 msg, s32 msg_arg)
{
    if (msg == 0x49) {
        if (msg_arg == 0x86) {
            _capod_entrypoint_13(actor->unk0, 0, 0x12, 0x910);
            return _chdoor_entrypoint_1(actor, 7, 0);
        }
        return 0;
    }
    return _chdoor_entrypoint_1(actor, msg, msg_arg);
}

int *chfactoryroofbits_entrypoint_5()
{
    return &D_80800B34_chfactoryroofbits;
}

extern void func_80102EC0();
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
extern int _chdoor_entrypoint_1();
extern void _chswitch_entrypoint_6();
extern u8 D_8011A248[];
u8 D_80800920_chfactoryroofbits[72] = {
    0x5,  0x10, 0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x6,  0x0,  0x8,  0x0,  0x0,  0x22, 0x2,
    0x0,  0x2,  0x80, 0x6,  0x0,  0x8,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x26, 0x0,  0x19,
    0x0,  0x0,  0x0,  0x7,  0x0,  0x2C, 0xFF, 0xEC, 0x0,  0x14, 0xFF, 0xEC, 0x0,  0x14, 0x0,
    0x28, 0x0,  0x14, 0x0,  0x20, 0x60, 0x60, 0x60, 0x80, 0x0,  0xA,  0xFF, 0xEC, 0xFF, 0xCE,
    0xFF, 0xEC, 0x0,  0x14, 0x0,  0x32, 0x0,  0x14, 0x5,  0x1A, 0x0,  0x0};
u8 D_80800968_chfactoryroofbits[12] = {0x0,  0x13, 0x4, 0xA0, 0x0, 0x16,
                                       0x6D, 0x60, 0x0, 0x0,  0x0, 0x0};
int D_80800974_chfactoryroofbits[18] = {0x123028B,
                                        0x7100001,
                                        0x0,
                                        (u32) func_80102EC0,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x1960000,
                                        0xC00,
                                        0x0,
                                        (u32) func_80108ED0,
                                        0x0,
                                        (u32) func_80800000_chfactoryroofbits,
                                        (u32) func_80107C2C,
                                        -0x7FFFD400,
                                        (u32) func_8080003C_chfactoryroofbits,
                                        0x0};
u8 D_808009BC_chfactoryroofbits[64] = {
    0x0,  0x1D, 0x7,  0xF,  0x0, 0x16, 0x10, 0x0,  0x0, 0x2B, 0x4,  0x0,  0x6, 0x0,  0x0,  0x1B,
    0xFE, 0x70, 0xFE, 0x70, 0x0, 0x22, 0x0,  0x66, 0x0, 0x80, 0x0,  0x66, 0x0, 0x80, 0x0,  0x27,
    0xFE, 0x70, 0xFE, 0x70, 0x1, 0x90, 0x1,  0x90, 0x0, 0xA,  0xFF, 0xB5, 0x0, 0xF,  0xFF, 0xB5,
    0x0,  0x4B, 0x0,  0x32, 0x0, 0x4B, 0x0,  0x15, 0x0, 0x0,  0x0,  0xCC, 0x0, 0x0,  0x0,  0x0};
u8 D_808009FC_chfactoryroofbits[12] = {0x0,  0x13, 0x4, 0x8D, 0x0, 0x16,
                                       0x6D, 0x60, 0x0, 0x0,  0x0, 0x0};
int D_80800A08_chfactoryroofbits[18] = {0x13503F2,
                                        0x70E0001,
                                        0x0,
                                        (u32) func_80102EC0,
                                        (u32) func_80105834,
                                        (u32) func_808005DC_chfactoryroofbits,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x800,
                                        0x0,
                                        (u32) func_80108ED0,
                                        0x0,
                                        (u32) func_808003C4_chfactoryroofbits,
                                        (u32) func_80107C2C,
                                        -0x7FFFD400,
                                        (u32) func_80800414_chfactoryroofbits,
                                        0x0};
int D_80800A50_chfactoryroofbits[18] = {0xAC03F3,
                                        0x70D0001,
                                        0x0,
                                        (u32) _chdoor_entrypoint_0,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0xC04,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_80800624_chfactoryroofbits,
                                        (u32) func_80107C2C,
                                        -0x7FFFDBFE,
                                        (u32) _chdoor_entrypoint_1,
                                        0x0};
Vec3f D_80800A98_chfactoryroofbits = {-2.26e+03f, 5.5e+03f, -1139.0f};
s32 D_80800AA4_chfactoryroofbits[18] = {0x34303F4,
                                        0x8890001,
                                        -0x7FEE5DE0,
                                        (u32) _chswitch_entrypoint_6,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x808,
                                        0x0,
                                        (u32) func_80108ED0,
                                        0x0,
                                        (u32) func_808006E8_chfactoryroofbits,
                                        (u32) func_80107C2C,
                                        -0x7FFFD3FE,
                                        (u32) func_80800708_chfactoryroofbits,
                                        0x0};
int D_80800AEC_chfactoryroofbits[18] = {0x3430474,
                                        0x86D0001,
                                        (u32) &D_8011A248,
                                        (u32) _chswitch_entrypoint_6,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x40000808,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_808007B8_chfactoryroofbits,
                                        (u32) func_80107C2C,
                                        -0x7FFFD3EE,
                                        (u32) func_808007E4_chfactoryroofbits,
                                        0x0};
int D_80800B34_chfactoryroofbits[19] = {0xAC04D9,
                                        0x8CD0001,
                                        0x0,
                                        (u32) _chdoor_entrypoint_0,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x40000C00,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_80800840_chfactoryroofbits,
                                        (u32) func_80107C2C,
                                        -0x7FFFD3EE,
                                        (u32) func_80800890_chfactoryroofbits,
                                        0x0,
                                        0x0};
