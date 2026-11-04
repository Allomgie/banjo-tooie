#include "common.h"

extern void func_80103110();
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int D_80800288_chfantasysafeswitch[];

void func_80800000_chfantasysafeswitch(u8 *actor)
{
    actor[0x65] &= ~0x10;
    func_80103110(actor, 0);
}

s32 func_8080002C_chfantasysafeswitch(s32 actor)
{
    if (((((u16) *(u16 *) (actor + 0x72) & 0xFFFFFFFF) >> 0xA) == 2) && (func_80101DDC() != 0)) {
        func_80102424(actor, 3);
    }
}

// Attack (0x40) only counts with line of sight to the safe (actor 0x2B2); then the switch
// notifies the safe or plays the reveal cutscene. Flag 0x357+id keeps it pressed.
s32 func_80800070_chfantasysafeswitch(Actor *actor, s32 msg, s32 arg)
{
    Actor *safe;
    f32 safe_pos[3];
    f32 ray_origin[3];

    switch (msg) {
        case 0x40:
            if (actor->unk70_10 == 1) {
                safe = _subaddiefind_entrypoint_2(0x2B2, 0);
                if (safe != NULL) {
                    func_800EE7F8(safe_pos, safe->position);
                    func_800EFA4C(ray_origin, actor->position[0], actor->position[1] + 40.0f,
                                  actor->position[2]);
                    if (func_800C6A7C(safe_pos, ray_origin, &actor->actorData[4], 0)) {
                        return 0;
                    }
                }
                func_80102424(actor, 2);
                func_80103110(actor, 1);
                actor->unk64_20 = 1;
            }
            return 1;
        case 0x39:
            if (actor->unk64_20) {
                if (func_800EA05C() == 0x13A) {
                    func_80101180(0x417, 0x49, actor->unk74_7 + 0x1F);
                } else {
                    _glcutDll_entrypoint_6(0x13A, actor->unk74_7 + 0x1F);
                }
                actor->unk64_20 = 0;
                func_80102424(actor, 3);
                return 1;
            }
            return 0;
        case 0x95:
            if (func_800DA298(actor->unk74_7 + 0x357)) {
                func_80102424(actor, 3);
                return 1;
            }
            func_80102424(actor, 1);
            return 1;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(1, actor->unk74_7 - 0x31);
            return 1;
        default:
            return 0;
    }
}

int *chfantasysafeswitch_entrypoint_0()
{
    return &D_80800288_chfantasysafeswitch;
}

// TU-NOTE: the overlay .data is defined here in C (from the ROM); its tables point to functions of
// this file, and IDO's assembler schedules them differently otherwise.
// D_80800288_chfantasysafeswitch is int[].
extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800260_chfantasysafeswitch[10] = {0x0,      0x0,        0x3F800000, 0xD40044,   0x3F800000,
                                          0xD40002, 0x3F800000, 0xD40084,   0x3F800000, 0xD40084};
int D_80800288_chfantasysafeswitch[18] = {0x1210418,
                                          0x8DB0001,
                                          (u32) &D_80800260_chfantasysafeswitch,
                                          (u32) func_8080002C_chfantasysafeswitch,
                                          (u32) func_80105834,
                                          (u32) func_801018A4,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x808,
                                          0x0,
                                          (u32) func_80108ED0,
                                          0x0,
                                          (u32) func_80800000_chfantasysafeswitch,
                                          (u32) func_80107C2C,
                                          -0x7FFFDC00,
                                          (u32) func_80800070_chfantasysafeswitch,
                                          0x0};
