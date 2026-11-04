#include "common.h"

extern int D_80800930_chhotwaterpoolbits[];
extern int D_80800978_chhotwaterpoolbits[];
extern int D_808009C0_chhotwaterpoolbits[];
extern s32 D_80800A08_chhotwaterpoolbits[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern u8 D_80800A5C_chhotwaterpoolbits[];
extern u8 D_80800A50_chhotwaterpoolbits[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800F3214(f32 *, void *, void *, f32);
extern u8 D_80800A68_chhotwaterpoolbits[];
extern u8 _chhotwaterpoolbits_entrypoint_4[];
typedef struct {
    s16 position[3];
    u16 flags;
    s16 uv[2];
    u8 color[4];
} HotWaterVertex1805;
extern Actor *func_80106790();
typedef struct {
    u8 pad_0[0x76];
    u16 subtype : 9;
    u16 pad_76 : 7;
} PoolS;
extern void func_800FFAB0(PoolS *);
extern void func_800EE7F8();
extern s32 D_80800A88_chhotwaterpoolbits[];
extern s32 D_80800AC0_chhotwaterpoolbits[];
extern s32 D_80800AD8_chhotwaterpoolbits[];
extern f32 func_800F5628(s32);
// Registers the vertex recolour callback on the map layer.
void func_80800528_chhotwaterpoolbits();
extern void func_80102EC0(), func_80107C2C(), func_8010A730(), func_80800204_chhotwaterpoolbits();

int chhotwaterpoolbits_entrypoint_0()
{
    return (int) &D_80800930_chhotwaterpoolbits;
}

int chhotwaterpoolbits_entrypoint_1()
{
    return (int) &D_80800978_chhotwaterpoolbits;
}

int *chhotwaterpoolbits_entrypoint_2()
{
    return &D_808009C0_chhotwaterpoolbits;
}

s32 chhotwaterpoolbits_entrypoint_3()
{
    return D_80800A08_chhotwaterpoolbits;
}

// Drain switch (flag 0x167).
s32 func_80800030_chhotwaterpoolbits(Actor *this)
{
    s32 pressed = _chswitch_entrypoint_7(this, 0x167);
    _chswitch_entrypoint_8(this, 0x200);
    if (pressed)
        _chswitch_entrypoint_9(this);
}

s32 func_80800078_chhotwaterpoolbits(Actor *actor, s32 msg)
{
    if (msg == 7) {
        if (!func_800DA298(0x31B)) {
            _subaddiedialog_entrypoint_11(actor->unk0, 0x12B0, 15, actor->position, 0);
        } else {
            func_80101180(0x428, msg, 0);
            func_80101180(0x439, 10, 0x427);
            func_80103110(actor, 0);
            _chswitch_entrypoint_9(actor);
        }
    } else {
        return _chswitch_entrypoint_10(actor);
    }
    return 1;
}

// Drain door/plug.
void func_80800124_chhotwaterpoolbits(Actor *actor)
{
    if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, 300.0f, 0x60, 0x167)) {
        _chdoormake_entrypoint_5(actor, 2.0f);
        _chdoormake_entrypoint_6(actor, 0.15f);
        _chdoormake_entrypoint_9(actor, 0, 0xD, 0x10);
        _chdoormake_entrypoint_8(actor, 0xD);
    }
}

// Door message handler: plays the opening cutscene.
s32 func_808001A8_chhotwaterpoolbits(s32 actor, s32 msg, s32 unk_2)
{
    if ((msg == 0xb) && (unk_2 == 0xd)) {
        _capod_entrypoint_14();
        _glcutDll_entrypoint_6(0x1a7, 0x29);
        func_800FFAB0(actor);
        return 4;
    }
    return _chdoor_entrypoint_1(actor);
}

void func_80800204_chhotwaterpoolbits(actor) s32 actor;
{
    func_800F2E60(actor + 0x28, (int *) D_80800A50_chhotwaterpoolbits, actor);
    *(f32 *) ((char *) actor + 0x1C) = 0.0f;
    *(f32 *) ((char *) actor + 0x18) = 127.0f;
}

void func_8080024C_chhotwaterpoolbits(Actor *actor)
{
    switch (actor->unk70_10) {
        case 2:
            if (func_800D9078(&actor->unk58)) {
                func_80101FDC(actor, 3);
                func_80103110(actor, 0);
            }
            func_800F3214((f32 *) ((u8 *) actor + 0x28), D_80800A50_chhotwaterpoolbits,
                          D_80800A5C_chhotwaterpoolbits,
                          func_800F10B4(actor->unk58, 0.0f, 4.0f, 1.0f, 0.0f));
            ((f32 *) actor->actorData)[1] = 0.0;
            break;
        case 3:
            func_800F2E60((u8 *) actor + 0x28, D_80800A5C_chhotwaterpoolbits);
            ((f32 *) actor->actorData)[1] = 0.0;
            ((f32 *) actor->actorData)[0] = 100.0f;
            break;
        case 4:
            if (func_800D9078(&actor->unk58)) {
                func_80101FDC(actor, 3);
                func_80103110(actor, 0);
            }
            ((f32 *) actor->actorData)[1] =
                func_800F12D4(actor->unk58, 0.0f, 10.0f, -800.0f, 0.0f);
            ((f32 *) actor->actorData)[0] =
                func_800F12D4(actor->unk58, 0.0f, 10.0f, 100.0f, 127.0f);
            func_800F2E60((u8 *) actor + 0x28, D_80800A5C_chhotwaterpoolbits);
            break;
        case 5:
            func_800F2E60((u8 *) actor + 0x28, D_80800A5C_chhotwaterpoolbits);
            ((f32 *) actor->actorData)[0] = 100.0f;
            ((f32 *) actor->actorData)[1] = -800.0f;
            func_800FFAB0(actor);
    }
    func_80800528_chhotwaterpoolbits(actor);
}

int func_808003E0_chhotwaterpoolbits(actor, msg, payload)
s32 actor;
s32 msg;
u32 payload;
{
    switch (msg) {
        case 0xA:
            if (payload == 0x3E7) {
                func_80101FDC(actor, 2);
                func_80103110(actor, 1);
                *(f32 *) ((char *) actor + 0x58) = 4.0f;
            } else {
                _subaddieaudioquick_entrypoint_2(actor, actor + 4,
                                                 D_80800A68_chhotwaterpoolbits);
                func_80101FDC(actor, 4);
                func_80103110(actor, 1);
                *(f32 *) ((char *) actor + 0x58) = 10.0f;
            }

            break;

        case 0x95:
            if (func_800DA298(0x167)) {
                func_800F2E60(actor + 0x28, D_80800A5C_chhotwaterpoolbits);
                *(f32 *) ((char *) actor + 0x18) = 100.0f;
                *(f32 *) ((char *) actor + 0x1C) = -800.0f;
                func_800FFAB0(actor);
            } else {
                if (func_800DA298(0x31B)) {
                    func_800F2E60(actor + 0x28, D_80800A5C_chhotwaterpoolbits);
                    *(f32 *) ((char *) actor + 0x1C) = 0.0f;
                    *(f32 *) ((char *) actor + 0x18) = 100.0f;
                    func_80101FDC(actor, 3);
                }
            }
            func_80800528_chhotwaterpoolbits(actor);
            return 1;

        default:
            return 0;
    }

    return 1;
}

// Registers the vertex recolour callback on the map layer.
void func_80800528_chhotwaterpoolbits(handle) s32 *handle;
{
    s32 map_layer;

    map_layer = func_800BEA88(1);

if (map_layer != 0) {
    _glid_entrypoint_0(map_layer, 0xA, &_chhotwaterpoolbits_entrypoint_4, *handle);
}

}

// Vertex callback: tints water vertices, sets alpha and shifts height.
void chhotwaterpoolbits_entrypoint_4(void *unk_0, HotWaterVertex1805 *src_vtx,
                                     HotWaterVertex1805 *dst_vtx, s32 count, Unk80132ED0 *ctx)
{
    Actor *actor;
    u8 alpha;
    s16 y_offset;
    s32 i;
    HotWaterVertex1805 *end;
    actor = func_80106790(ctx);
    alpha = (u8) *(f32 *) ((u8 *) actor + 0x18);
    y_offset = *(f32 *) ((u8 *) actor + 0x1C);
    end = dst_vtx + count;
    for (; dst_vtx < end; src_vtx++, dst_vtx++) {
        for (i = 0; i != 3; i++) {
            dst_vtx->color[i] =
                src_vtx->color[i] * ((s32 *) ((u8 *) actor + 0x28))[i] >> 8;
        }
        dst_vtx->color[3] = alpha;
        dst_vtx->position[1] = src_vtx->position[1] + y_offset;
    }
}

void func_808006BC_chhotwaterpoolbits(PoolS *pool)
{
    if (pool->subtype == 0x33 && func_800DA298(0x31B)) {
        func_800FFAB0(pool);
    } else {
        func_800EE7F8((u8 *) pool + 0x18, (u8 *) pool + 4);
    }
}

void chhotwaterpoolbits_entrypoint_5();

// Hot water actor: scalds the player standing in the water.
void func_80800718_chhotwaterpoolbits(Actor *actor)
{
    s32 player;
    s32 form;
    s32 unk_0;
    s32 unk_1;
    f32 player_pos[3];
    switch (actor->unk70_10) {
        case 1:
            player = func_800F54E4();
            if (func_800F6A38(player)) {
                form = func_800F5C94(player);
                unk_0 = func_800F5D18(player);
                unk_1 = func_800F64A4(player, 2);

if (form != 0xC && form != 0xE && (unk_0 || unk_1) &&
    func_800D9078((u8 *) actor + 0x58)) {
    func_800F7D90(player, 0x52, actor->actorData, 1);
    func_80101FDC(actor, 2);
    chhotwaterpoolbits_entrypoint_5(actor, 0x3F800000);
    *(f32 *) ((u8 *) actor + 0x58) = 1.0f;
}

}
else
{
    func_800F5A00(player, player_pos);
    player_pos[1] = func_800F5628(player);
    if (func_800F55FC(player) & 0x08000000)
        func_800EE7F8(actor->actorData, player_pos);
    *(f32 *) ((u8 *) actor + 0x58) = 0.04f;
}
return;
case 2:
    if (func_800D9078((u8 *) actor + 0x58) && func_800F5578(func_800F54E4()) > 0) {
        func_80101FDC(actor, 1);
        *(f32 *) ((u8 *) actor + 0x58) = 0.04f;
    }
    }
    }

    // Steam burst on the player; called from ch/banjoctrl.
    void chhotwaterpoolbits_entrypoint_5(s32 actor, s32 scale)
    {
        f32 dir[3];
        f32 pos[3];
        s32 player;

        player = func_800F54E4();
        func_800F7620(player, 0x3F800000, 0x3F000000, 0x3ECCCCCD);
        func_800F5A00(player, pos);
        func_800EE780(dir, pos, &D_80800AD8_chhotwaterpoolbits);
        func_800BABB8(0, pos, dir, scale, &D_80800A88_chhotwaterpoolbits);
        _subaddieaudioquick_entrypoint_2(actor, pos, &D_80800AC0_chhotwaterpoolbits);
    }

    extern u8 D_8011A270[];
    extern void _chswitch_entrypoint_6();
    extern void func_80105834();
    extern void func_80101870();
    extern void func_80108ED0();
    extern void _chdoor_entrypoint_0();
    int D_80800930_chhotwaterpoolbits[18] = {0x3390427,
                                             0x7B80001,
                                             (u32) &D_8011A270,
                                             (u32) _chswitch_entrypoint_6,
                                             (u32) func_80105834,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x4000080C,
                                             0x0,
                                             (u32) func_80108ED0,
                                             0x0,
                                             (u32) func_80800030_chhotwaterpoolbits,
                                             (u32) func_80107C2C,
                                             -0x7FF7D3FE,
                                             (u32) func_80800078_chhotwaterpoolbits,
                                             0x0};
    int D_80800978_chhotwaterpoolbits[18] = {0xAC0428,
                                             0x9470001,
                                             0x0,
                                             (u32) _chdoor_entrypoint_0,
                                             (u32) func_80105834,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x1670000,
                                             0x804,
                                             0x0,
                                             0x0,
                                             0x0,
                                             (u32) func_80800124_chhotwaterpoolbits,
                                             (u32) func_80107C2C,
                                             -0x7FFFD3FE,
                                             (u32) func_808001A8_chhotwaterpoolbits,
                                             0x0};
    int D_808009C0_chhotwaterpoolbits[18] = {0x1580439,
                                             0x1,
                                             0x0,
                                             (u32) func_8080024C_chhotwaterpoolbits,
                                             (u32) func_80102EC0,
                                             (u32) func_8010A730,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x4,
                                             0x0,
                                             0x0,
                                             0x0,
                                             (u32) func_80800204_chhotwaterpoolbits,
                                             (u32) func_80107C2C,
                                             -0x7FFFF1FE,
                                             (u32) func_808003E0_chhotwaterpoolbits,
                                             0x0};
    s32 D_80800A08_chhotwaterpoolbits[18] = {0x158043A,
                                             0x1,
                                             0x0,
                                             (u32) func_80800718_chhotwaterpoolbits,
                                             (u32) func_80102EC0,
                                             (u32) func_8010A730,
                                             0xBB80000,
                                             0x0,
                                             0x0,
                                             0x4,
                                             0x0,
                                             0x0,
                                             0x0,
                                             (u32) func_808006BC_chhotwaterpoolbits,
                                             (u32) func_80107C2C,
                                             -0x7FFFF9FE,
                                             0x0,
                                             0x0};
    u8 D_80800A50_chhotwaterpoolbits[12] = {0x0, 0x0,  0x0, 0xFF, 0x0, 0x0,
                                            0x0, 0x78, 0x0, 0x0,  0x0, 0x78};
    u8 D_80800A5C_chhotwaterpoolbits[12] = {0x0, 0x0,  0x0, 0xFF, 0x0, 0x0,
                                            0x0, 0xFF, 0x0, 0x0,  0x0, 0xFF};
    u8 D_80800A68_chhotwaterpoolbits[32] = {
        0x0, 0x13, 0x5, 0x6A, 0x0, 0x18, 0x0, 0xA,  0x0, 0xC0, 0x0, 0xC,  0x0, 0x0, 0x9, 0x0,
        0x0, 0xC0, 0x1, 0xC,  0x0, 0x15, 0x0, 0x33, 0x9, 0x4C, 0x0, 0x80, 0x0, 0x0, 0x0, 0x0};
    s32 D_80800A88_chhotwaterpoolbits[14] = {0xC10001D, 0x9DD002D, 0x3E804B0, 0xB0000,   0x140000,
                                             0x6002,    0x220099,  0x1000300, 0x3800015, 0x99,
                                             0x2A0000,  0xA008C,   0xA6000F,  0x0};
    s32 D_80800AC0_chhotwaterpoolbits[6] = {0x1304DC, 0xD0100, 0x14C0015, 0x80, 0x660002, 0x0};
    s32 D_80800AD8_chhotwaterpoolbits[6] = {0x0, -0x3CFE0000, 0x0, 0x0, 0x0, 0x0};
