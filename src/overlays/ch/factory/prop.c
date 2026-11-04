#include "common.h"
#include "types.h"
#include "macros.h"

extern int D_80800C20_chfactoryprop[];
extern void *D_80800C68_chfactoryprop;
extern int D_80800CB0_chfactoryprop[];
extern void _subaddiefade_entrypoint_14(void);
extern void func_8010A63C(void *param_0);
typedef struct {
    s32 unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    f32 unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    f32 unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    s32 unk6C;
    s16 unk70;
    u16 unk72;
} ChFactoryProp;
extern void _glid_entrypoint_0(void *param_0, int param_1, f32 *param_2, void *param_3);
extern void _subaddieaudioloop_entrypoint_2(ChFactoryProp *param_0);
extern f32 func_800136E4(f32 param_0);
extern f32 func_800D8FF8(void);
extern void func_80101FDC(ChFactoryProp *param_0, int param_1);
extern s32 func_801065A4(ChFactoryProp *param_0);
extern void _chfactoryprop_entrypoint_3(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern u8 D_80800D24_chfactoryprop[];
extern s32 func_800DB9B0(void);
extern void func_8008FE68(f32 *);
extern void func_800E3980(f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800C4350();
extern s32 func_800EA05C(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C3058();
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void func_800907C0(f32 *);
extern u8 D_80800CF8_chfactoryprop[];
extern f32 func_800F15F8(f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_80800D08_chfactoryprop[];
extern u8 D_80800D14_chfactoryprop[];
extern f32 func_800DC178(f32, f32);
extern void func_800C31DC(s32, f32);
extern void func_800C4B64(f32);
extern s32 func_800D9154(f32 *, f32);
void func_80800988_chfactoryprop();
void func_80800324_chfactoryprop();
void func_80800674_chfactoryprop();

int chfactoryprop_entrypoint_0()
{
    return (int) &D_80800C20_chfactoryprop;
}

int chfactoryprop_entrypoint_1()
{
    return &D_80800C68_chfactoryprop;
}

int *chfactoryprop_entrypoint_2()
{
    return &D_80800CB0_chfactoryprop;
}

void func_80800024_chfactoryprop(void *prop)
{
    char *base;
    *(float *) ((char *) prop + 0x34) = 1.0f;
    base = (char *) prop;
    // Matching: odd offset expression is needed for the match.
    *(float *) (base - -(0x24 & 0xFFFFFFFFFFFFFFFFu)) = 1.0f;
    _subaddiefade_entrypoint_14();
    func_8010A63C(prop);
    *(float *) (base + 0x44) = 30.0f;
    // Matching: empty block steers IDO's register allocation.
    if (!prop) {
    }
}

void func_80800070_chfactoryprop(ChFactoryProp *prop)
{
    f32 dt;
    f32 speed;
    u32 state;
    dt = func_800D8FF8();
    if (prop->unk28 > 0.0f) {
        if (((u32) (prop->unk6C << 0xB) >> 0x14) == 0x3B2) {
            func_80800674_chfactoryprop(prop);
        } else {
            func_80800988_chfactoryprop(prop);
        }
    } else {
        _subaddieaudioloop_entrypoint_2(prop);
    }
    state = (u16) prop->unk72;
    state = state >> 0xA;
    switch (state) {
        case 1:
            prop->unk44 = func_800136E4((prop->unk28 * dt) + prop->unk44);
            func_80800324_chfactoryprop(prop);
            break;

        case 2:
            speed = func_800F15F8(prop->unk28, 0, 40.0f * dt);
            prop->unk28 = speed;
            prop->unk44 = func_800136E4((speed * dt) + prop->unk44);
            if (prop->unk28 == 0.0f) {
                func_80101FDC(prop, 3);
            }
    }

    state = func_801065A4(prop);
    if (state != 0) {
        _glid_entrypoint_0(func_801065A4(prop), 1, &_chfactoryprop_entrypoint_3, prop->unk0);
    }
}

void func_808001D8_chfactoryprop(u8 *prop)
{
    *(u8 *) ((char *) prop + 0x18) =
        _subaddieaudioloop_entrypoint_3(*(u8 *) ((char *) prop + 0x18));
    *(u8 *) ((char *) prop + 0x1C) =
        _subaddieaudioloop_entrypoint_3(*(u8 *) ((char *) prop + 0x1C));
}

s32 func_80800214_chfactoryprop(u8 *prop, s32 msg, s32 param_2)
{
    switch (msg) {
        case 0x49:
            if (_glcutDll_entrypoint_19(0x45) == 0) {
                return 0;
            } else {
                func_80101FDC(prop, 2);
                if (((u32) (*(s32 *) ((s8 *) prop + 0x6C) << 0xB) >> 0x14) == 0x3B2) {
                    _capod_entrypoint_13(*(s32 *) ((s8 *) prop + 0), 0, 3, 0x2910);
                }
            }
            break;
        case 0x4F:
            func_80101FDC(prop, 2);
            break;
        case 0x95:
            *(s8 *) ((s8 *) prop + 0x1C) = 0;
            *(s8 *) ((s8 *) prop + 0x18) = 0;
            if ((func_800DA298(0x18C) != 0) && (_glcutDll_entrypoint_19(0x45) == 0) &&
                (_glcutDll_entrypoint_20() == 0)) {
                func_80101FDC(prop, 3);
                *(f32 *) ((s8 *) prop + 0x28) = 0.0f;
            } else {
                *(f32 *) ((s8 *) prop + 0x28) = 400.0f;
                *(f32 *) ((s8 *) prop + 0x2C) = 0.0f;
            }
    }
    return 0;
}

// Fan variant 0x3B2: blows the player along +x with distance falloff.
void func_80800324_chfactoryprop(actor) Actor *actor;
{
    f32 velocity[3];
    f32 player_pos[3];
    f32 dx;
    f32 wind;
    f32 dt;
    s32 active;
    s32 volume;
    if (actor->unk6C_9 != 0x3B2)
        return;
    func_8008FE68(player_pos);
    if (player_pos[2] > 1700.0f || player_pos[2] < -1700.0f)
        return;
    dx = player_pos[0] - actor->position[0];
    if (dx <= -100.0f)
        wind = func_800F10B4(dx, -500.0f, -100.0f, 0.0f, 800.0f);
    else
        wind = func_800F10B4(dx, -100.0f, 4000.0f, 800.0f, 0.0f);
    dt = func_800D8FF8();
    *(f32 *) &actor->actorData[5] =
        func_800F15F8(*(f32 *) &actor->actorData[5], 0.0f, dt * 400.0f);
    if (player_pos[0] < 1300.0f && player_pos[0] > 0.0f && player_pos[1] < actor->position[1])
        *(f32 *) &actor->actorData[5] = 600.0f;
    func_80090794(velocity);
    func_800EF1B8(velocity, 90.0f, (*(f32 *) &actor->actorData[5] + wind) * dt);
    func_800907C0(velocity);
    active = *(f32 *) &actor->actorData[5] + wind > 240.0000153f;
    if (active || (!active && *((u8 *) actor + 0x1C))) {
        volume = func_800F10B4(*(f32 *) &actor->actorData[5] + wind, 0.0f, 800.0f, 8000.0f,
                                22000.0f);
        *((u8 *) actor + 0x1C) = _subaddieaudioloop_entrypoint_7(
            *((u8 *) actor + 0x1C), player_pos, active, D_80800CF8_chfactoryprop,
            *(u32 *) ((u8 *) actor + 0x70) & 1);
        if (*((u8 *) actor + 0x1C) != 0)
            func_800C3058(*((u8 *) actor + 0x1C), volume);
    }
}

// Vertex callback: sets vertex alpha from the actor's value.
void chfactoryprop_entrypoint_3(void *param_0, void *param_1, Vtx *verts, s32 count,
                                Unk80132ED0 *ctx)
{
    f32 alpha_f;
    Vtx *end;
    u8 alpha;

    alpha_f = func_800F12D4(*(f32 *) &func_80106790(ctx)->actorData[4], 0.0f, 160.0f, 0, 64.0f);
    end = verts + count;
    if (verts < end) {
        alpha = alpha_f;
        do {
            verts->v.cn[3] = alpha;
            verts++;
        } while (verts < end);
    }
}

void func_80800674_chfactoryprop(actor) Actor *actor;
{
    f32 pitch;
    Vec3f player_pos;
    f32 dx;
    f32 *pos;
    s32 volume;
    s32 flags;

    if (!func_800DB9B0()) {
        flags = func_800F55FC(func_800F54E4());
        func_8008FE68(player_pos.f);
        if (flags & 0x08000000) {
            ((f32 *) actor->actorData)[7] = 0.3f;
        } else if (flags & 0x30000000) {
            ((f32 *) actor->actorData)[7] =
                func_800F10B4(player_pos.pos.z, -1200.0f, -2400.0f, 1.0f, 0.3f);
        } else {
            ((f32 *) actor->actorData)[7] = 1.0f;
        }
    } else {
        ((f32 *) actor->actorData)[7] = 1.0f;
        func_800E3980(player_pos.f);
    }
    ((f32 *) actor->actorData)[3] = func_800F15F8(
        ((f32 *) actor->actorData)[3], ((f32 *) actor->actorData)[7], func_800D8FF8());
    dx = actor->position[0] - player_pos.pos.x;
    if (dx < 0.0f) {
        volume = func_800F10B4(dx, 0.0f, -8000.0f, 32767.0f, 14000.0f);
    } else {
        volume = func_800F10B4(dx, 0.0f, 2000.0f, 32767.0f, 0);
    }
    if (actor->unk5F == 0) {
        actor->unk5F = func_800C4350(0, actor->position, D_80800D08_chfactoryprop);
    }
    pos = actor->position;
    pitch = func_800F12D4(((f32 *) actor->actorData)[4], 0.0f, 400.0f, 0.4f, 1.0f);
    volume *= ((f32 *) actor->actorData)[3] *
               func_800F12D4(((f32 *) actor->actorData)[4], 0.0f, 400.0f, 0.4f, 1.0f);
    func_800C31DC(actor->unk5F, pitch);
    func_800C3058(actor->unk5F, volume);
    func_800C4350(actor->unk5F, pos, NULL);
    if (func_800D9154((f32 *) &actor->actorData[6],
                      func_800F10B4(((f32 *) actor->actorData)[4], 0.0f, 400.0f, 0.8f, 0.3f)) &&
        ((f32 *) actor->actorData)[4] > 80.0f && volume != 0) {
        if (*(u8 *) actor->actorData == 0) {
            *(u8 *) actor->actorData = _subaddieaudioquick_entrypoint_1(actor, pos);
        }
        pitch = func_800F12D4(((f32 *) actor->actorData)[4], 0.0f, 400.0f, 0.2f, 0.5f) +
                  func_800DC178(-0.05f, 0.05f);
        func_800C4B70((s32) (((f32 *) actor->actorData)[3] * volume));
        func_800C4B64(pitch);
        func_800C4350(*(u8 *) actor->actorData, pos, D_80800D14_chfactoryprop);
    }
}

void func_80800988_chfactoryprop(param_0) Actor *param_0;
{
#define P (*(Actor **) &param_0)
    f32 pos[3];
    f32 player_pos[3];
    f32 dist;
    s32 volume;

    if (!func_800DB9B0()) {
        func_8008FE68(player_pos);
    } else {
        func_800E3980(player_pos);
    }
    func_800EE7F8(pos, P->position);
    pos[0] = player_pos[0];
    if (P->unk5F == 0) {
        P->unk5F = func_800C4350(0, pos, D_80800D24_chfactoryprop);
    }
    switch (func_800EA05C()) {
        case 0x10F:
            dist = -1200.0f - player_pos[0];
            if (dist < 0) {
                volume = func_800F10B4(dist, 0.0f, -800.0f, 20000.0f, 0.0f);
            } else {
                volume = 20000;
            }
            break;
        case 0x110:
            dist = P->position[1] - player_pos[1];
            if (0 < dist) {
                volume = func_800F10B4(dist, 0.0f, 4000.0f, 20000.0f, 0.0f);
            } else {
                volume = 20000;
            }
            break;
    }
    volume *= func_800F12D4(((f32 *) P->actorData)[4], 0.0f, 400.0f, 0.4f, 1.0f);
    func_800C3058(P->unk5F, volume);
    func_800C4350(P->unk5F, pos, NULL);
}

void func_80800B44_chfactoryprop(Actor *door)
{
    func_8010A63C(door);
    if (_chdoormake_entrypoint_3(door, 0.0f, 90.0f, 200.0f, 0x20, 0x18C)) {
        _chdoormake_entrypoint_6(door, 2.25f);
        _chdoormake_entrypoint_12(door, 0, 0x45);
        _chdoormake_entrypoint_8(door, 0xC);
    }
    if (func_800DA298(0x18C) && !_glcutDll_entrypoint_19(0x45))
        func_800FFAB0(door);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
extern void _chdoor_entrypoint_1();
int D_80800C20_chfactoryprop[18] = {0x31703B2,
                                    0x7440001,
                                    0x0,
                                    (u32) func_80800070_chfactoryprop,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x1400,
                                    (u32) func_808001D8_chfactoryprop,
                                    0x0,
                                    0x0,
                                    (u32) func_80800024_chfactoryprop,
                                    (u32) func_80107C2C,
                                    -0x7FF7DBEE,
                                    (u32) func_80800214_chfactoryprop,
                                    0x0};
void *D_80800C68_chfactoryprop = (void *) 0x031803B3;
static u32 D_80800C68_chfactoryprop_rest[17] = {0x7450001,
                                                0x0,
                                                (u32) func_80800070_chfactoryprop,
                                                (u32) func_80105834,
                                                (u32) func_80101870,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x4400,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) func_80800024_chfactoryprop,
                                                (u32) func_80107C2C,
                                                0x80082412,
                                                (u32) func_80800214_chfactoryprop,
                                                0x0};
int D_80800CB0_chfactoryprop[18] = {0xAC04FE,
                                    0x8870001,
                                    0x0,
                                    (u32) _chdoor_entrypoint_0,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x400,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800B44_chfactoryprop,
                                    (u32) func_80107C2C,
                                    -0x7FF7D3EE,
                                    (u32) _chdoor_entrypoint_1,
                                    0x0};
u8 D_80800CF8_chfactoryprop[16] = {0x0, 0x13, 0x4, 0xA3, 0x0, 0xA, 0x0, 0xCC,
                                   0x0, 0x2,  0x0, 0x14, 0x0, 0x0, 0x0, 0x0};
u8 D_80800D08_chfactoryprop[12] = {0x2, 0x6, 0x0, 0x13, 0x6, 0x35, 0x0, 0x2, 0x0, 0x3, 0x0, 0x0};
u8 D_80800D14_chfactoryprop[16] = {0x3, 0x6,  0x0, 0x13, 0x3, 0xFF, 0x0, 0x1D,
                                   0x0, 0x1E, 0x0, 0x2,  0x0, 0x11, 0x0, 0x0};
u8 D_80800D24_chfactoryprop[28] = {0x2, 0x6, 0x0, 0x13, 0x4, 0xBF, 0x0, 0xA, 0x0, 0xB3,
                                   0x0, 0x2, 0x0, 0x3,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0,
                                   0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
