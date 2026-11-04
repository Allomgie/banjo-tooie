// Probably the magic glow on Chuffy while Mumbo levitates him: copies five of Chuffy's bone
// positions and draws a fading additive glow model over them.
#include "common.h"

extern u8 D_80800550_chchuffyglow[];
extern u8 D_8080055C_chchuffyglow[];
extern void *func_80100094();
extern void func_800DE448(f32 *, f32 *, f32, s32, s32);
typedef struct {
    f32 v[3];
} ChuffyVector40;
extern void _subaddiefade_entrypoint_1(void *param_0, int param_1);
extern int D_808005B0_chchuffyglow[];
typedef struct {
    Vec3f vertex[5];
} ChuffyGlowVertices;
extern ChuffyGlowVertices D_80800568_chchuffyglow;
extern Vec3f D_808005A4_chchuffyglow;
extern f32 func_800D8FF8(void);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF3DC(f32 *, f32 *);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_80105834(), func_80107C2C(), func_80800484_chchuffyglow(),
    func_8080048C_chchuffyglow();

// Copies five Chuffy bone positions and draws the glow over them.
int func_80800000_chchuffyglow(actor, param_1)
Actor *actor;
s32 param_1;
{
    ChuffyVector40 unk_0;
    ChuffyVector40 unk_1;
    f32 tmp[4];
    s32 anim_ctrl;
    s32 anim_data;
    u8 *bones;
    s32 i;
    u8 *bone_ptr;
    u8 *rot_ptr;
    unk_0 = *(ChuffyVector40 *) D_80800550_chchuffyglow;
    unk_1 = *(ChuffyVector40 *) D_8080055C_chchuffyglow;
    anim_ctrl = func_80104248(actor);
    bones = func_80100094(actor, 0);
    func_80102780(actor, unk_1.v);
    func_8008B304(anim_ctrl);
    anim_data = func_8008B4D4(anim_ctrl);
    func_800DFFA0(anim_data, 3, bones);
    for (i = 0, bone_ptr = bones + 12, rot_ptr = bones + 0x48; i != 5;
         i++, bone_ptr += 12, rot_ptr += 16) {
        func_800DFFA0(anim_data, i + 0x2A, bone_ptr);
        func_800D93A0(tmp, rot_ptr);
        func_800DFF2C(anim_data, i + 0x2A, tmp);
    }
    func_800DF830(2);
    func_800DF410(_subaddiefade_entrypoint_0(actor));
    func_800DF41C(anim_data);
    func_800DE448(unk_0.v, unk_1.v, actor->scale, 0,
                  func_8010347C(actor->unk0));
}

// Follows Chuffy and fades the glow in and out.
void func_80800180_chchuffyglow(Actor *actor)
{
    ChuffyGlowVertices vertices = D_80800568_chchuffyglow;
    Vec3f offset = D_808005A4_chchuffyglow;
    Vec3f unk_0;
    s32 i;
    f32 *base;
    f32 *bone_pos;
    f32 *bone_rot;
    Vec3f *vertex;

    base = func_80100094(actor, 0);
    _chchuffy_entrypoint_1(actor->unk3C, (f32 *) actor->actorData,
                           (f32 *) &actor->actorData[4]);
    switch (actor->unk70_10) {
        case 1:
            if (actor->unk58 <= 0.0f) {
                if (_subaddiefade_entrypoint_0(actor) < 253) {
                    _subaddiefade_entrypoint_1(actor, _subaddiefade_entrypoint_0(actor) + 3);
                } else {
                    actor->unk70_10 = 2;
                }
            } else {
                actor->unk58 -= func_800D8FF8();
            }
            break;
        case 2:
            if (!actor->unk64_20) {
                actor->unk70_10 = 3;
            }
            break;
        case 3:
            if (_subaddiefade_entrypoint_0(actor) >= 7) {
                _subaddiefade_entrypoint_1(actor, _subaddiefade_entrypoint_0(actor) - 7);
            } else {
                func_800FFAB0(actor);
            }
            break;
    }
    actor->unk64_20 = _chchuffy_entrypoint_1(actor->unk3C, (f32 *) actor->actorData,
                                               (f32 *) &actor->actorData[4]);
    func_800EE7F8(base, (f32 *) actor->actorData);
    func_800EF334(base, 0.006666666828f);
    func_800EF3DC(base, offset.f);
    func_800E3980(unk_0.f);
    bone_pos = base + 3;
    bone_rot = base + 18;
    for (i = 0, vertex = vertices.vertex; i < 5;
         bone_pos += 3, i++, bone_rot += 4, vertex++) {
        func_800EF4E4(bone_pos, ((f32 *) &actor->actorData[4])[0],
                      ((f32 *) &actor->actorData[4])[1], 0.0f, (i - 1.75f) * 750.0f, 0.0f);
        func_800F18FC((f32 *) actor->actorData, unk_0.f, bone_rot);
        base[19 + i * 4] += 90.0f;
        base[20 + i * 4] = 180.0f - base[18 + i * 4];
        base[18 + i * 4] = 0.0f;
        func_800EF334(bone_pos, 0.006666666828f);
        func_800EF3DC(bone_pos, vertex->f);
    }
}

void func_80800484_chchuffyglow(s32 arg0)
{
}

void func_8080048C_chchuffyglow(actor) void *actor;
{
    float *ptr;
    _subaddiefade_entrypoint_1(actor, 0);
    ptr = (float *) ((char *) actor + 0x58);
    *ptr = 5.0f;
    ptr = (char *) actor + 0x65;
    *(char *) ((char *) actor + 0x65) = (*(char *) ptr & 0xFF) | 0x10;
}

// Spawns the glow actor and links it to the caller.
void chchuffyglow_entrypoint_0(s32 param_0)
{
    s32 *caller;
    s32 pad[2];
    caller = func_80106790();
    *(s32 *) ((s8 *) func_801084B0(0x30E, &caller) + 0x3C) = (s32) *caller;
}

int chchuffyglow_entrypoint_1()
{
    return (int) &D_808005B0_chchuffyglow;
}

u8 D_80800530_chchuffyglow[32] = {0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x4B, 0x18, 0x96,
                                  0x80, 0x2, 0xCA, 0x0,  0x0,  0x4B, 0x18, 0x96, 0x80, 0x2,  0xCA,
                                  0x0,  0x0, 0x4B, 0x18, 0x96, 0x80, 0x2,  0xCA, 0x0,  0x0};
u8 D_80800550_chchuffyglow[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
u8 D_8080055C_chchuffyglow[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
ChuffyGlowVertices D_80800568_chchuffyglow = {0.0f,   -0.052f, 7.84f,   0.0f,    -0.035f,
                                              1.66f,  0.0f,    -0.519f, -4.74f,  0.0f,
                                              -0.26f, -10.82f, 0.0f,    -0.474f, -17.03f};
Vec3f D_808005A4_chchuffyglow = {0.0f, 2.91f, 4.3f};
int D_808005B0_chchuffyglow[20] = {0x2D3030E,
                                   0x7390001,
                                   (u32) &D_80800530_chchuffyglow,
                                   (u32) func_80800180_chchuffyglow,
                                   (u32) func_80105834,
                                   (u32) func_80800000_chchuffyglow,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x140C,
                                   (u32) func_80800484_chchuffyglow,
                                   0x0,
                                   0x980000,
                                   (u32) func_8080048C_chchuffyglow,
                                   (u32) func_80107C2C,
                                   -0x7FFFFFFE,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x0};
