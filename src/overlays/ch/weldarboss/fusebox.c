#include "common.h"

extern void *D_80800670_chweldarbossfusebox;
extern void *D_808006B8_chweldarbossfusebox;
extern void *D_80800700_chweldarbossfusebox;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern int D_80800660_chweldarbossfusebox[];
typedef struct {
    f32 position[3];
    f32 yaw;
    f32 scale;
    s32 flags;
} WeldarFuseBoxMarkerPose;
extern s32 func_80101080();
extern s32 func_80106790(s32);
extern void _chexploder_entrypoint_15(s32, s32, f32);
extern void _subaddieaudioquick_entrypoint_2();
extern void func_800BF744(s32, s32);
extern u8 D_80800748_chweldarbossfusebox[];
typedef struct {
    s32 words[2];
} FuseboxLight30;
extern u8 D_80800790_chweldarbossfusebox[];
extern u8 D_80800798_chweldarbossfusebox[];
extern u8 D_808007B0_chweldarbossfusebox[];
extern s32 D_808007BC_chweldarbossfusebox[];
extern void func_80105A9C(Actor *, f32);
int func_80800140_chweldarbossfusebox();
void func_8080032C_chweldarbossfusebox();
int func_80800384_chweldarbossfusebox();
int func_808005F8_chweldarbossfusebox();

void *chweldarbossfusebox_entrypoint_0()
{
    return &D_80800670_chweldarbossfusebox;
}

void *chweldarbossfusebox_entrypoint_1()
{
    return &D_808006B8_chweldarbossfusebox;
}

void *chweldarbossfusebox_entrypoint_2(void)
{
    return &D_80800700_chweldarbossfusebox;
}

// First fuse box at a fixed position; removed once Weldar is beaten.
void func_80800024_chweldarbossfusebox(Actor *fuse_box)
{
    func_800BF744(2, func_800DA298(0x18C));
    func_800EFA4C(fuse_box->position, -1800.0f, 1200.0f, -2200.0f);
    func_80103014(fuse_box);
    _subaddiefade_entrypoint_14(fuse_box);
    if (func_800DA298(0x18C)) {
        func_800FFAB0(fuse_box);
    }
}

s32 func_80800098_chweldarbossfusebox(Actor *fuse_box, s32 msg, s32 arg)
{
    f32 explosion_pos[3];
    switch (msg) {
        case 5:
            func_800EE7F8(explosion_pos, fuse_box->position);
            func_800EF1B8(explosion_pos, fuse_box->rotation[1], -400.0f);
            _chexploder_entrypoint_3(fuse_box, explosion_pos, 11);
            func_80101180(0x33D, 10, 0);
            break;
        case 0x90:
            func_80800140_chweldarbossfusebox(fuse_box);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80800140_chweldarbossfusebox(fuse_box)
s32 fuse_box;
{
    s32 exploder;
    exploder = func_80106790(func_80101080());
    _chexploder_entrypoint_6(exploder, 0x44E10000, 0x44FA0000);
    _chexploder_entrypoint_7(exploder, 0xC4AF0000, 0xC4960000);
    _chexploder_entrypoint_15(exploder, 2, 1.5f);
    _subaddieaudioquick_entrypoint_2(fuse_box, fuse_box + 4, &D_80800660_chweldarbossfusebox);
    func_800BF744(2, 1);
}

// Second fuse box; explodes on its second hit.
void func_808001BC_chweldarbossfusebox(Actor *fuse_box)
{
    WeldarFuseBoxMarkerPose marker;

    func_800BF744(4, func_800DA298(0x18C));
    func_800EFA4C(fuse_box->position, 0.0f, 4900.0f, -2300.0f);
    func_80103014(fuse_box);
    _subaddiefade_entrypoint_14(fuse_box);
    if (func_800DA298(0x18C)) {
        func_800FFAB0(fuse_box);
        return;
    }
    if (_subaddiemarker_entrypoint_1(fuse_box, 0x320, 0x35, &marker, 1)) {
        func_800EE7F8(fuse_box->actorData, marker.position);
    }
}

s32 func_80800268_chweldarbossfusebox(Actor *fuse_box, s32 msg, s32 arg)
{
    switch (msg) {
        case 5:
            if (++fuse_box->unk6C_0 == 2) {
                _chexploder_entrypoint_3(fuse_box, fuse_box->position, 0xB);
                func_80101180(0x465, 7, 0);
                func_80101180(0x3B3, 0x4F, 0);
                func_80800384_chweldarbossfusebox(fuse_box);
            }
            break;
        case 0x90:
            func_8080032C_chweldarbossfusebox(fuse_box);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080032C_chweldarbossfusebox(fuse_box) u8 *fuse_box;
{
    _chexploder_entrypoint_15(func_80106790(func_80101080(fuse_box)), 2, 1.5f);
    _subaddieaudioquick_entrypoint_2(fuse_box, fuse_box + 4,
                                     ((s32 *) &D_80800660_chweldarbossfusebox));
    func_800BF744(4, 1);
}

int func_80800384_chweldarbossfusebox(fuse_box)
Actor *fuse_box;
{
    extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
    f32 effect_end[3];

    func_800EE7F8(effect_end, (f32 *) ((u8 *) fuse_box + 0x18));
    effect_end[1] += 400.0f;
    effect_end[2] -= 100.0f;
    func_800BABB8(0, (f32 *) ((u8 *) fuse_box + 0x18), effect_end, 1.0f,
                  (s32 *) D_80800748_chweldarbossfusebox);

}

void func_808003F8_chweldarbossfusebox(Actor *fuse)
{
    if (func_800DA298(0x18C)) {
        func_800FFAB0(fuse);
    } else {

if (fuse->unk74_7 == 0x32)
    fuse->unk58 = 0.0f;
else
    fuse->unk58 = 0.5f;
func_80105A9C(fuse, fuse->unk74_7 == 0x32 ? 750.0f : 700.0f);

}
}

// Falling fuse with a point light; on landing it notifies actor 0x3AE.
void func_8080049C_chweldarbossfusebox(Actor *fuse)
{
    f32 light_pos[3];
    FuseboxLight30 light_params;
    if (func_800D90A4(&fuse->unk58)) {
        if (!fuse->actorData[4]) {
            light_params = *(FuseboxLight30 *) D_80800790_chweldarbossfusebox;
            fuse->actorData[4] = func_800C8A98();
            func_800C8D4C(fuse->actorData[4], &light_params);
        }

func_800EE7F8(light_pos, fuse->position);
light_pos[2] += 200.0f;
func_800C8CB8(fuse->actorData[4], light_pos);
func_800C8E84(fuse->actorData[4], D_80800798_chweldarbossfusebox + func_8001210C(1) * 12);
func_80105834(fuse);
func_808005F8_chweldarbossfusebox(fuse);
_subaddieaudioloop_entrypoint_4(fuse, fuse->position, 1, D_808007B0_chweldarbossfusebox);

if (func_80105A5C(fuse)) {
    func_800C8B84(fuse->actorData[4]);
    fuse->actorData[4] = 0;
    func_80101180(0x3AE, 5, 0);
    func_800FFAB0(fuse);
}

}
}

s32 func_808005C0_chweldarbossfusebox(s32 fuse, s32 msg, s32 arg)
{
    if (msg == 0xA) {
        func_80103110(fuse, 1);
        return TRUE;
    }
    return FALSE;
}

int func_808005F8_chweldarbossfusebox(fuse)
s32 fuse;
{
    if (func_8001210C(3)) {
        func_800BBCB8(fuse + 4, 0, 0x3F800000, 2, &D_808007BC_chweldarbossfusebox);
    }
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file and the
// assembler schedules them differently otherwise. Values are taken from the ROM.
extern void func_80102EC0();
extern int func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_8010A730();
int D_80800660_chweldarbossfusebox[4] = {0x130413, 0xA00E6, 0x166D60, 0x20000};
void *D_80800670_chweldarbossfusebox = (void *) 0x01580345;
static u32 D_80800670_chweldarbossfusebox_rest[17] = {0x86C0001,
                                                      0x0,
                                                      (u32) func_80102EC0,
                                                      (u32) func_80105834,
                                                      (u32) func_80101870,
                                                      0x0,
                                                      0x0,
                                                      0x0,
                                                      0x404,
                                                      0x0,
                                                      0x0,
                                                      0x0,
                                                      (u32) func_80800024_chweldarbossfusebox,
                                                      (u32) func_80107C2C,
                                                      0x80082C12,
                                                      (u32) func_80800098_chweldarbossfusebox,
                                                      0x0};
void *D_808006B8_chweldarbossfusebox = (void *) 0x015803AE;
static u32 D_808006B8_chweldarbossfusebox_rest[17] = {0x8710001,
                                                      0x0,
                                                      (u32) func_80102EC0,
                                                      (u32) func_80105834,
                                                      (u32) func_80101870,
                                                      0x0,
                                                      0x0,
                                                      0x0,
                                                      0x404,
                                                      0x0,
                                                      0x0,
                                                      0x0,
                                                      (u32) func_808001BC_chweldarbossfusebox,
                                                      (u32) func_80107C2C,
                                                      0x80082C12,
                                                      (u32) func_80800268_chweldarbossfusebox,
                                                      0x0};
void *D_80800700_chweldarbossfusebox = (void *) 0x0158046A;
static u32 D_80800700_chweldarbossfusebox_rest[17] = {0x1,
                                                      0x0,
                                                      (u32) func_80102EC0,
                                                      (u32) func_8080049C_chweldarbossfusebox,
                                                      (u32) func_8010A730,
                                                      0x0,
                                                      0x0,
                                                      0x0,
                                                      0x4,
                                                      0x0,
                                                      0x0,
                                                      0x0,
                                                      (u32) func_808003F8_chweldarbossfusebox,
                                                      (u32) func_80107C2C,
                                                      0x80000E02,
                                                      (u32) func_808005C0_chweldarbossfusebox,
                                                      0x0};
u8 D_80800748_chweldarbossfusebox[72] = {
    0x8,  0x10, 0x0,  0x16, 0x2,  0x0,  0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2D, 0x0,  0xFA, 0x1,
    0x2C, 0x0,  0x1B, 0x0,  0x3C, 0x0,  0x50, 0x0,  0xA,  0xFF, 0x6,  0x0,  0x0,  0x0,  0x0,
    0x0,  0xFA, 0x0,  0xA,  0x0,  0xA,  0x60, 0x2,  0x0,  0x22, 0x1,  0x80, 0x2,  0x0,  0x4,
    0x0,  0x5,  0x80, 0x0,  0x15, 0x0,  0x0,  0x0,  0x99, 0x0,  0x2A, 0x0,  0x19, 0x0,  0x26,
    0x1,  0x99, 0x2,  0x0,  0x0,  0x28, 0x6,  0x0,  0x0,  0x0,  0x0,  0x0};
u8 D_80800790_chweldarbossfusebox[8] = {0x43, 0x96, 0x0, 0x0, 0x44, 0x16, 0x0, 0x0};
u8 D_80800798_chweldarbossfusebox[24] = {0x0, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0xC0,
                                         0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x80,
                                         0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 0x0, 0xA0};
u8 D_808007B0_chweldarbossfusebox[12] = {0x0,  0x13, 0x5, 0x2E, 0x0, 0x16,
                                         0x6D, 0x60, 0x0, 0x2,  0x0, 0x0};
s32 D_808007BC_chweldarbossfusebox[13] = {0x1D09CD, 0x1BFF6A, -0x63FFF2, 0x500064, 0x230066,
                                          0x2B0080, 0x990015, 0x80,      0x161200, 0x0,
                                          0x0,      0x0,      0x0};
