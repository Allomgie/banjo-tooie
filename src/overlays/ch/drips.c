#include "common.h"

extern int D_80800610_chdrips[];
extern f32 func_800DC178(f32, f32);
extern u8 D_80800658_chdrips[];
extern void func_800BABB8(s32, void *, void *, f32, void *);
extern s32 func_800DC298(f32);
extern u8 D_80800698_chdrips[];
extern void _chdrips_entrypoint_1(void);
extern void _chdrips_entrypoint_2(void);
typedef struct {
    u8 pad_0[0x76];
    u16 count : 9;
    u16 pad_1 : 7;
} DripActorCount;
typedef struct {
    f32 pos[3];
    f32 land_y;
    u8 in_water;
    u8 pad_11[3];
} DripPoint49;
extern void *func_80100094(Actor *, u32);
extern void *func_800CC63C(s32, s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 _subaddie3d_entrypoint_0(f32 *, f32, f32, f32 *);
extern s32 _subaddie3d_entrypoint_1(f32 *, f32, f32, f32 *);
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_80800260_chdrips(),
    func_808005CC_chdrips();

int chdrips_entrypoint_0()
{
    return &D_80800610_chdrips;
}

void chdrips_entrypoint_1(Actor *actor, f32 *pos)
{
    u16 pitch;

    pitch = (u32) (func_800DC178(1.0f, 1.4f) * 1023.0f);
    func_800C4140((pitch << 21) + 0xBBD53, pos, 0x5DC012C);
    _fxripple_entrypoint_0(0, pos);
}

void chdrips_entrypoint_2(s32 unk_0, f32 *pos)
{
    s32 emitter = func_800B53A4(5);
    u16 pitch;

    func_800BA6B0(emitter, -50, 0, -50, 50, 0, 50);
    func_800BA4D0(emitter, (s16) (s32) pos[1]);
    func_800BABB8(emitter, pos, 0, 1.0f, D_80800658_chdrips);
    pitch = (u32) (func_800DC178(1.0f, 1.4f) * 1023.0f);
    func_800C4140((pitch << 21) + 0xBBD52, pos, 0x5DC012C);
}

// Per frame: randomly releases a drop from the current drip point, then picks the next point.
void func_80800260_chdrips(actor) Actor *actor;
{
    f32 chance;
    u8 *point;
    s32 emitter;

    chance = (actor->rotation[1] * 0.333f) * 0.0027777778f;
    if (func_800DC298(chance)) {
        point = func_80100094(actor, 0);
        emitter = func_800B53A4(1);
        point += actor->unk6C_0 * 0x14;
        if (point[0x10]) {
            func_800BA544(emitter, _chdrips_entrypoint_1);
        } else {
            func_800BA544(emitter, _chdrips_entrypoint_2);
        }
        func_800BA4D0(emitter, (s16) (s32) *(f32 *) (point + 0xC));
        func_800BABB8(emitter, point, 0, 1.0f, D_80800698_chdrips);
        func_800BA22C(emitter, 1);
        actor->unk6C_0 = func_800DC128(0, actor->unk74_7);
    }
}

// Allocates and fills the drip point records (0x14 bytes each).
void func_80800394_chdrips(Actor *actor)
{
    f32 angle;
    s32 i;
    s32 node_count;
    f32 water_y;
    DripPoint49 *point;
    s16 *node;
    if ((*(u32 *) ((u8 *) actor + 0x70) >> 25) == 0) {
        func_800FFA88(actor->unk0);
        return;
    }
    if (((DripActorCount *) actor)->count < 51)
        ((DripActorCount *) actor)->count = 60;
    ((DripActorCount *) actor)->count -= 50;
    func_80100074(actor, 0, ((DripActorCount *) actor)->count * sizeof(DripPoint49));
    point = func_80100094(actor, 0);
    node_count = func_800CC5F4((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1);
    for (i = 0; i < (s32) ((DripActorCount *) actor)->count; i++, point++) {
        node =
            func_800CC63C((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1, func_800DC128(0, node_count));
        angle = func_800DC178(0.0f, 359.0f);
        func_800EEB9C(point->pos, angle, func_800DC178(0.0f, (f32) node[6]));
        func_800EF04C(point->pos, node);
        if (!_subaddie3d_entrypoint_0(point->pos, 0.0f, -5000.0f, &point->land_y))
            point->land_y = *(f32 *) ((u8 *) node + 4);
        if (!_subaddie3d_entrypoint_1(point->pos, 0.0f, -5000.0f, &water_y))
            water_y = point->land_y - 50.0f;
        if (point->land_y < water_y) {
            point->land_y = water_y;
            point->in_water = 1;
        } else
            point->in_water = 0;
    }
}

void func_808005CC_chdrips(actor) s32 actor;
{
    func_80100074(actor, 0, 0);
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to functions
// of this file; IDO's assembler schedules some of these functions differently unless the tables
// are defined in the same unit. Values are taken from the ROM.
// D_80800610_chdrips is declared as int[] to match the object (same address).
int D_80800610_chdrips[18] ={0x2E80371,
                              0x1,
                              0x0,
                              (u32) func_80800260_chdrips,
                              (u32) func_80105834,
                              (u32) func_8010A730,
                              0x0,
                              0x0,
                              0x0,
                              0x80005,
                              (u32) func_808005CC_chdrips,
                              0x0,
                              0x0,
                              (u32) func_80800394_chdrips,
                              (u32) func_80107C2C,
                              -0x7FFFFDFE,
                              0x0,
                              0x0};
u8 D_80800658_chdrips[64] = {
    0x0,  0x1D, 0x9, 0xDA, 0x0,  0x20, 0xFF, 0xFF, 0xFE, 0xB4, 0x0, 0x1B, 0xFA, 0xEC, 0xFA, 0xEC,
    0x0,  0x7,  0x0, 0x1,  0x0,  0x15, 0x0,  0x0,  0x0,  0xCC, 0x0, 0x22, 0x0,  0x5,  0x0,  0xA,
    0x0,  0x5,  0x0, 0x5,  0x0,  0x2B, 0x2,  0x0,  0x2,  0x0,  0x0, 0x16, 0x10, 0x0,  0x0,  0x2C,
    0xFF, 0xA6, 0x0, 0xC8, 0xFF, 0xA6, 0x0,  0x5A, 0x1,  0x5E, 0x0, 0x5A, 0x5,  0x1A, 0x0,  0x0};
u8 D_80800698_chdrips[40] = {0x0, 0x1D, 0x9,  0xF3, 0x0,  0x20, 0xFF, 0xFF, 0xFE, 0xB4,
                             0x0, 0x1B, 0xFD, 0x44, 0xFD, 0x44, 0x0,  0x7,  0x0,  0x1,
                             0x0, 0x22, 0x0,  0x5,  0x0,  0xA,  0x0,  0x14, 0x0,  0x19,
                             0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
