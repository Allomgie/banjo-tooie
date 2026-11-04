// Probably a trash-compactor conveyor belt: carries the player along x with a sine wobble at a
// speed set by the actor variant, and draws 7 moving belt segments with a running sound.
#include "common.h"

extern u8 D_808005C0_chfactorytrashbelt[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800138D0(f32);
extern f32 func_800D91B8(f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_80100094(Actor *, u32);
extern Vec3f D_808005D4_chfactorytrashbelt;
extern Vec3f D_808005E0_chfactorytrashbelt;
extern void func_801017D0(void);
extern void func_800DE498(s32, f32 *, f32 *, f32, s32, void *);
typedef struct {
    s32 current;
    s16 handles[7];
} TrashBeltState;
extern s16 func_80100D24(s32, u16, s32, s32, u16, s32);
extern void func_80100E18(s16);
extern s16 func_80100A74(s16, s32);
extern void func_800DF818(void *);
extern void func_800DF660(s32, s32, s32, u8);
extern void *func_80100AC4(s16);
extern void func_800DF720(void *);
extern void *D_808005EC_chfactorytrashbelt;
extern void func_80105834(), func_80107C2C(), func_80800000_chfactorytrashbelt(),
    func_808001EC_chfactorytrashbelt();

// Carries the player along x inside the belt area with a sine wobble.
void func_80800000_chfactorytrashbelt(belt) Actor *belt;
{
    f32 player_pos[3];
    f32 unk_0;
    f32 speed;

    func_800F5A00(func_800F54E4(), player_pos);
    if (player_pos[0] < 500.0f && player_pos[0] > -500.0f && player_pos[2] < 600.0f &&
        player_pos[2] > -600.0f) {
        if (func_800F6C5C(func_800F54E4())) {
            unk_0 = func_800138D0(func_800F10B4(player_pos[0], -700.0f, 700.0f, 0.0f, 1.5f) *
                                    360.0f * 7.0f);
            func_800EFA4C(player_pos, 200.0f / ((f32) belt->unk74_7 / 70.0f), unk_0 * 1.5f * 5.0f,
                          0.0f);
            func_800F48BC(func_800F54E4(), player_pos);
        }
    }
    _subaddieaudioloop_entrypoint_4(belt, belt->position, 1, D_808005C0_chfactorytrashbelt);
    unk_0 = func_800D91B8(&belt->unk58);
    speed = (f32) belt->unk74_7 / 70.0f;
    if (unk_0 >= speed) {
        belt->unk58 -= speed;
    }
}

void func_808001EC_chfactorytrashbelt(belt, unk_1) Actor *belt;
s32 unk_1;
{
    f32 scroll;
    f32 t;
    s32 *slot;
    s32 i;
    Vec3f pos;
    Vec3f rot;

    slot = func_80100094(belt, 0);
    scroll = func_800F10B4(belt->unk58, 0.0f, (f32) belt->unk74_7 / 70.0f, 0.0f, 200.0f);
    for (i = 0; i < 7; i++) {
        pos = D_808005D4_chfactorytrashbelt;
        rot = D_808005E0_chfactorytrashbelt;
        pos.f[0] += (f32) i * 200.0f + scroll;
        t = func_800F10B4(pos.f[0], -700.0f, 700.0f, 0.0f, 1.0f);
        pos.f[1] = belt->position[1] + func_800138D0(t * 360.0f * 7.0f) * 1.5f;
        rot.f[0] = func_800138D0(t * 360.0f * 7.0f);
        *slot = i;
        func_800DF830(1);
        func_800DF47C(func_801017D0, belt);
        func_800DE498(unk_1, pos.f, rot.f, 1.0f, 0, func_8010347C(belt->unk0));
    }
}

s32 func_8080041C_chfactorytrashbelt(Actor *belt, s32 message, s32 arg)
{
    TrashBeltState *state;
    s32 j;
    s16 handle;
    s32 p2;
    s32 i;
    state = func_80100094(belt, 0);
    switch (message) {
        case 0x95:
            for (j = 0; j < 7; j++) {
                state->handles[j] = 0;
            }
            break;
        case 0x29:
            p2 = arg;
            if (&arg) {
            }
            for (i = 0; i < 7; i++) {
                state->handles[i] = func_80100D24(p2, *(u16 *) ((u8 *) belt->unk0 + 0x14), 1,
                                                    1, *(u16 *) ((u8 *) belt->unk0 + 0x16), 0);
            }
            break;
        case 0x2A:
            for (j = 0; j < 7; j++) {
                if (state->handles[j]) {
                    func_80100E18(state->handles[j]);
                    state->handles[j] = 0;
                }
            }
            break;
        case 0x1F:
            handle = state->handles[state->current];
            func_800DF818(func_80100A74(handle, 0));
            func_800DF660(2, -2, 0, *(u8 *) ((u8 *) belt + 0x9B));
            func_800DF720(func_80100AC4(handle));
            return 1;
        default:
            return 0;
    }
    return 1;
}

int chfactorytrashbelt_entrypoint_0()
{
    return &D_808005EC_chfactorytrashbelt;
}

u8 D_808005C0_chfactorytrashbelt[20] = {0x0,  0x13, 0x5, 0x27, 0x0, 0xA,  0x0,  0x80, 0x0, 0x16,
                                        0x46, 0x50, 0x0, 0x1,  0x0, 0xC8, 0x17, 0x70, 0x0, 0x0};
Vec3f D_808005D4_chfactorytrashbelt = {-7e+02f, 0.0f, 0.0f};
Vec3f D_808005E0_chfactorytrashbelt = {0.0f, 9e+01f, 0.0f};
void *D_808005EC_chfactorytrashbelt = (void *) 0x01580403;
static u32 D_808005EC_chfactorytrashbelt_rest[20] = {0x87D0001,
                                                     0x0,
                                                     (u32) func_80800000_chfactorytrashbelt,
                                                     (u32) func_80105834,
                                                     (u32) func_808001EC_chfactorytrashbelt,
                                                     0x0,
                                                     0x0,
                                                     0x0,
                                                     0x400,
                                                     0x0,
                                                     0x0,
                                                     0x140000,
                                                     0x0,
                                                     (u32) func_80107C2C,
                                                     0x80000402,
                                                     (u32) func_8080041C_chfactorytrashbelt,
                                                     0x0,
                                                     0x0,
                                                     0x0,
                                                     0x0};
