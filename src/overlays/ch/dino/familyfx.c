// Shared effects for the Styracosaurus family and baby dinos: footstep sounds and dust particles
// at the feet on set animation frames, with variants for the family cave and train station.
#include "common.h"

extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 func_801022E4(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800EA05C(void);
extern f32 func_800DC178(f32, f32);
extern void func_800C4140(s32, f32 *, s32);
extern void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
typedef struct {
    f32 times[4];
} DinoFamilyFxTimes;

void func_80800A28_chdinofamilyfx(f32 *param_0, f32 param_1, s32 param_2, void *param_3);

// Plays footstep sounds and spawns dust at the feet, depending on the current animation.
// Map 0x118 (family cave) adds extra dust; 0x114 (train station) uses the dust too.
void chdinofamilyfx_entrypoint_0(Actor *actor)
{
    extern u8 D_80800BD0_chdinofamilyfx[];
    extern u8 D_80800BF8_chdinofamilyfx[];
    extern u8 D_80800C20_chdinofamilyfx[];
    extern DinoFamilyFxTimes D_80800BC0_chdinofamilyfx;

    switch (func_801022E4(actor)) {
        case 0x3F7: {
            f32 bone_pos[3];
            f32 foot_pos[3];
            s32 in_cave;
            if (func_80101E14(actor, 0.04f)) {
                func_800C4140(0x7FEDAD02, (char *) actor + 4, 0x07D0012C);
            } else if (func_80101E14(actor, 0.17f)) {
                func_800C4140(0x930DAD02, (char *) actor + 4, 0x07D0012C);
            }

            if (func_80101E14(actor, 0.37f)) {
                _subaddieskeleton_entrypoint_0(actor, 0x2B, bone_pos);

                func_80800A28_chdinofamilyfx(bone_pos, *(f32 *) ((char *) actor + 0x48), 2,
                                             D_80800BD0_chdinofamilyfx);

                func_800C4140(0xA62FA503, (char *) actor + 4, 0x07D0012C);
            }

            if (func_80101E14(actor, 0.4f)) {
                in_cave = func_800EA05C() == 0x118;

                _subaddieskeleton_entrypoint_0(actor, 0x10, foot_pos);

                func_80800A28_chdinofamilyfx(foot_pos, *(f32 *) ((char *) actor + 0x48) + 45.0f, 1,
                                             D_80800BF8_chdinofamilyfx);

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(foot_pos,
                                                 *(f32 *) ((char *) actor + 0x48) + 45.0f, 1,
                                                 D_80800C20_chdinofamilyfx);
                }

                _subaddieskeleton_entrypoint_0(actor, 6, foot_pos);

                func_80800A28_chdinofamilyfx(foot_pos, *(f32 *) ((char *) actor + 0x48) + 135.0f,
                                             1, D_80800BF8_chdinofamilyfx);

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(foot_pos,
                                                 *(f32 *) ((char *) actor + 0x48) + 135.0f, 1,
                                                 D_80800C20_chdinofamilyfx);
                }

                _subaddieskeleton_entrypoint_0(actor, 0x14, foot_pos);

                func_80800A28_chdinofamilyfx(foot_pos, *(f32 *) ((char *) actor + 0x48) + 225.0f,
                                             1, D_80800BF8_chdinofamilyfx);

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(foot_pos,
                                                 *(f32 *) ((char *) actor + 0x48) + 225.0f, 1,
                                                 D_80800C20_chdinofamilyfx);
                }

                _subaddieskeleton_entrypoint_0(actor, 0x1E, foot_pos);

                func_80800A28_chdinofamilyfx(foot_pos, *(f32 *) ((char *) actor + 0x48) + 315.0f,
                                             1, D_80800BF8_chdinofamilyfx);

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(foot_pos,
                                                 *(f32 *) ((char *) actor + 0x48) + 315.0f, 1,
                                                 D_80800C20_chdinofamilyfx);
                }

                func_800C4140(0x7FF38C4A, (char *) actor + 4, 0x07D0012C);
            }
            break;
        }
        case 0x14D: {
            DinoFamilyFxTimes times = D_80800BC0_chdinofamilyfx;

            if (func_80101E14(actor, 0.34f) || func_80101E14(actor, 0.64f)) {
                func_800C4140(0x99738D51, (char *) actor + 4, 0x07D0012C);
                break;
            }

            if (func_80101E14(actor, 0.76f)) {
                func_800C4140(((u16) (u32) (func_800DC178(1.0f, 1.1f) * 1023.0f) << 21) + 0xDAD33,
                              (char *) actor + 4, 0x07D0012C);
            }
            break;
        }
        case 0x14C: {
            s32 in_cave;
            s32 has_dust_map;
            f32 pos_bone_1e[3];
            f32 pos_bone_14[3];
            f32 pos_bone_10[3];
            f32 pos_bone_6[3];
            in_cave = func_800EA05C() == 0x118;
            has_dust_map = func_800EA05C() == 0x114 || in_cave;

            if (func_80101E14(actor, 0.49f)) {
                _subaddieskeleton_entrypoint_0(actor, 0x1E, pos_bone_1e);

                if (has_dust_map) {
                    func_80800A28_chdinofamilyfx(pos_bone_1e,
                                                 *(f32 *) ((char *) actor + 0x48) + 180.0f, 1,
                                                 D_80800BF8_chdinofamilyfx);
                }

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(pos_bone_1e,
                                                 *(f32 *) ((char *) actor + 0x48) + 180.0f, 3,
                                                 D_80800C20_chdinofamilyfx);
                }

                func_800C4140(0x7FF38C4B, pos_bone_1e, 0x07D0012C);
                break;
            }

            if (func_80101E14(actor, 0.72f)) {
                _subaddieskeleton_entrypoint_0(actor, 0x14, pos_bone_14);

                if (has_dust_map) {
                    func_80800A28_chdinofamilyfx(pos_bone_14,
                                                 *(f32 *) ((char *) actor + 0x48) + 180.0f, 1,
                                                 D_80800BF8_chdinofamilyfx);
                }

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(pos_bone_14,
                                                 *(f32 *) ((char *) actor + 0x48) + 180.0f, 3,
                                                 D_80800C20_chdinofamilyfx);
                }

                func_800C4140(0x7FF38C4B, pos_bone_14, 0x07D0012C);
                break;
            }

            if (func_80101E14(actor, 0.55f)) {
                _subaddieskeleton_entrypoint_0(actor, 0x10, pos_bone_10);

                if (has_dust_map) {
                    func_80800A28_chdinofamilyfx(pos_bone_10,
                                                 *(f32 *) ((char *) actor + 0x48) + 180.0f, 1,
                                                 D_80800BF8_chdinofamilyfx);
                }

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(pos_bone_10,
                                                 *(f32 *) ((char *) actor + 0x48) + 180.0f, 3,
                                                 D_80800C20_chdinofamilyfx);
                }
                break;
            }

            if (func_80101E14(actor, 0.6f)) {
                _subaddieskeleton_entrypoint_0(actor, 6, pos_bone_6);

                if (has_dust_map) {
                    func_80800A28_chdinofamilyfx(pos_bone_6,
                                                 *(f32 *) ((char *) actor + 0x48) + 180.0f, 1,
                                                 D_80800BF8_chdinofamilyfx);
                }

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(pos_bone_6,
                                                 *(f32 *) ((char *) actor + 0x48) + 180.0f, 3,
                                                 D_80800C20_chdinofamilyfx);
                }
            }
            break;
        }
        case 0x3F8: {
            s32 sound_variant;
            s32 burst_kind;
            f32 bone_pos[3];
            s32 in_cave;

            if (func_80101E14(actor, 0.19f) || func_80101E14(actor, 0.46f)) {
                sound_variant = 0x44B;
                burst_kind = 1;
            } else if (func_80101E14(actor, 0.8f)) {
                sound_variant = 0x44A;
                burst_kind = 2;
            } else {
                sound_variant = 0;
            }

            if (sound_variant != 0) {
                in_cave = func_800EA05C() == 0x118;

                _subaddieskeleton_entrypoint_0(actor, 0x10, bone_pos);

                func_80800A28_chdinofamilyfx(bone_pos, *(f32 *) ((char *) actor + 0x48) + 45.0f,
                                             burst_kind, D_80800BF8_chdinofamilyfx);

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(bone_pos,
                                                 *(f32 *) ((char *) actor + 0x48) + 45.0f, 3,
                                                 D_80800C20_chdinofamilyfx);
                }

                _subaddieskeleton_entrypoint_0(actor, 6, bone_pos);

                func_80800A28_chdinofamilyfx(bone_pos, *(f32 *) ((char *) actor + 0x48) + 135.0f,
                                             burst_kind, D_80800BF8_chdinofamilyfx);

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(bone_pos,
                                                 *(f32 *) ((char *) actor + 0x48) + 135.0f, 3,
                                                 D_80800C20_chdinofamilyfx);
                }

                _subaddieskeleton_entrypoint_0(actor, 0x14, bone_pos);

                func_80800A28_chdinofamilyfx(bone_pos, *(f32 *) ((char *) actor + 0x48) + 225.0f,
                                             burst_kind, D_80800BF8_chdinofamilyfx);

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(bone_pos,
                                                 *(f32 *) ((char *) actor + 0x48) + 225.0f, 3,
                                                 D_80800C20_chdinofamilyfx);
                }

                _subaddieskeleton_entrypoint_0(actor, 0x1E, bone_pos);

                func_80800A28_chdinofamilyfx(bone_pos, *(f32 *) ((char *) actor + 0x48) + 315.0f,
                                             burst_kind, D_80800BF8_chdinofamilyfx);

                if (in_cave) {
                    func_80800A28_chdinofamilyfx(bone_pos,
                                                 *(f32 *) ((char *) actor + 0x48) + 315.0f, 3,
                                                 D_80800C20_chdinofamilyfx);
                }

                func_800C4140((sound_variant & 0x7FF) + 0x7FF38800, (char *) actor + 4, 0x07D0012C);
            }

            if (func_80101E14(actor, 0.65f)) {
                func_800C4140(0x7FEDAE1F, (char *) actor + 4, 0x07D0012C);
            }
        }
    }
}

// Spawns a dust burst at pos.
void func_80800A28_chdinofamilyfx(f32 *pos, f32 param_1, s32 param_2, void *particle_cfg)
{
    s32 emitter;
    f32 range_a[3];
    f32 range_b[3];
    emitter = func_800B53A4(param_2);
    func_800EEC30(range_a, 10.0f, param_1, 200.0f);
    func_800EEC30(range_b, 25.0f, param_1, 300.0f);
    func_800BA930(emitter, (s16) (s32) range_a[0], (s16) (s32) range_a[1], (s16) (s32) range_a[2],
                  (s32) range_b[0], (s32) range_b[1], (s32) range_b[2]);
    func_800EF334(range_a, -0.5f);
    func_800EF334(range_b, -0.5f);
    func_800BA450(emitter, (s16) (s32) range_a[0], -200, (s16) (s32) range_a[2], (s32) range_b[0],
                  -400, (s32) range_b[2]);
    func_800BABB8(emitter, pos, NULL, 1.0f, particle_cfg);
    func_800BA22C(emitter, param_2);
}

// TU-NOTE: the .data of this overlay is defined here in C. Values are taken from the ROM.
DinoFamilyFxTimes D_80800BC0_chdinofamilyfx = {0.34f, 0.7f, 0.82f, -1.0f};
u8 D_80800BD0_chdinofamilyfx[40] = {0x0, 0x1D, 0x9, 0xDC, 0x0,  0x2B, 0x1,  0x0,  0x1, 0x80,
                                    0x0, 0x22, 0x0, 0x80, 0x1,  0x0,  0x2,  0x0,  0x4, 0x0,
                                    0x0, 0x15, 0x0, 0x33, 0x0,  0x33, 0x0,  0x19, 0x0, 0x0,
                                    0x0, 0x12, 0x0, 0x20, 0xC8, 0xC8, 0x64, 0x73, 0x0, 0x0};
u8 D_80800BF8_chdinofamilyfx[40] = {0x0, 0x1D, 0x9, 0xC9, 0x0,  0x2B, 0x1,  0x0,  0x1, 0x80,
                                    0x0, 0x22, 0x0, 0x80, 0x1,  0x0,  0x2,  0x0,  0x2, 0x0,
                                    0x0, 0x15, 0x0, 0x33, 0x0,  0x33, 0x0,  0x19, 0x0, 0x0,
                                    0x0, 0x7,  0x0, 0x20, 0x8C, 0x78, 0x28, 0x82, 0x0, 0x0};
u8 D_80800C20_chdinofamilyfx[48] = {
    0x0, 0x1D, 0x8, 0xA2, 0x0, 0x16, 0x14, 0x4,  0x0, 0x2B, 0x1, 0x80, 0x2, 0x0,  0x0, 0x22,
    0x2, 0x0,  0x1, 0x80, 0x1, 0x0,  0x1,  0x0,  0x0, 0x15, 0x0, 0x19, 0x0, 0xE6, 0x0, 0x27,
    0x0, 0x64, 0x0, 0x64, 0x0, 0xC8, 0x0,  0xC8, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
