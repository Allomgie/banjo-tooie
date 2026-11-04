#include "common.h"

extern int D_80800420_ch1pfreeze[];
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 pad72 : 10;
} FreezeState;
extern int func_800F7B9C();
extern s32 *func_80100094(FreezeState *, s32);
extern f32 func_800D8FF8(void);
extern s32 func_800F1574(f32 *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern s32 func_800A89F8(void);
extern s32 func_800F5ECC(u32);
extern f32 func_800F5794(u32, f32 *, s32);
extern void func_800B99CC(s32, s32, f32 *);
extern void func_80101870(Actor *, s32);
typedef struct {
    u32 player;
    f32 tint[3];
    s32 alpha;
    f32 timer;
    f32 duration;
    f32 fade;
} FreezeData;
typedef struct {
    s32 player;
    f32 tint[3];
    s32 alpha;
    f32 timer;
    f32 duration;
    f32 fade;
} ChFreezeState;
extern Actor *func_80108474(s32, f32 *, s32);
extern void func_800F5A00(u32, f32 *);
extern f32 func_800F5F24(u32);
void func_808002D0_ch1pfreeze();

int *ch1pfreeze_entrypoint_0()
{
    return &D_80800420_ch1pfreeze;
}

void func_8080000C_ch1pfreeze(s32 unk_0)
{
}

void func_80800014_ch1pfreeze(FreezeState *actor)
{
    if (actor->f72 < 4) {
        func_800F7B9C(*func_80100094(actor, 0), 0xF);
    }
}

void func_80800054_ch1pfreeze(Actor *actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 2:
            if (func_800F1574((f32 *) (data + 0x14), func_800D8FF8())) {
                func_808002D0_ch1pfreeze(actor, 3);
            }
            *(f32 *) (data + 0x1C) =
                1.0f - *(f32 *) (data + 0x14) / *(f32 *) (data + 0x18);
            break;
        case 4:
            if (func_800F1574((f32 *) (data + 0x14), func_800D8FF8())) {
                func_800FFAB0(actor);
                return;
            }
            *(f32 *) (data + 0x1C) = *(f32 *) (data + 0x14) / *(f32 *) (data + 0x18);
    }
    *(s32 *) (data + 0x10) = func_800F1214(*(f32 *) (data + 0x1C), 0.0f, 128.0f);
}

// Other viewports: three scaled ice passes. Own viewport: full-screen tint.
void func_8080014C_ch1pfreeze(Actor *actor, s32 gfx)
{
    FreezeData *data;
    s32 viewport;
    f32 sum;
    f32 pass_size;
    f32 size;
    s32 i;

    data = func_80100094(actor, 0);
    viewport = func_800A89F8();
    if (func_800F5ECC(data->player) != viewport) {
        sum = 0;
        if (actor->unk70_10 != 4) {
            for (i = 0; i != 3; i++) {
                pass_size = func_800F5794(data->player, actor->position, i);
                size = pass_size;
                if (i != 2) {
                    actor->rotation[0] = 0.0f;
                    sum += pass_size;
                } else {
                    size = sum * 0.25f;
                    actor->rotation[0] = 90.0f;
                }
                actor->scale = data->fade * (size / 75.0f);
                func_80101870(actor, gfx);
            }
        }
    } else {
        func_800B99CC(gfx, data->alpha, data->tint);
    }
}

s32 func_80800294_ch1pfreeze(Actor *this, s32 msg, s32 unk_2)
{
    Actor *actor_copy;
    if (msg == 0x4) {
        // Matching: extra temporary copy for the match.
        actor_copy = this;
        func_808002D0_ch1pfreeze(actor_copy, 4);
    } else {
        return 0;
    }
    return 1;
}

void func_808002D0_ch1pfreeze(actor, state) Actor *actor;
s32 state;
{
    ChFreezeState *data;

    data = func_80100094(actor, 0);
    switch (state) {
        case 2:
            func_800EFA88(data->tint, 0x80, 0xC0, 0xFF);
            data->alpha = 0;
            data->timer = 0.25f;
            data->duration = 0.25f;
            data->fade = 0.0f;
            break;
        case 3:
            func_80103110(actor, 0);
            break;
        case 4:
            _sufreezy_entrypoint_4(actor->unk0, 8);
            data->timer = 0.25f;
            data->duration = 0.25f;
            func_80103110(actor, 1);
    }
    func_80101FDC(actor, state);
}

// Spawns the ice block actor around the given player.
Unk80132ED0 *ch1pfreeze_entrypoint_1(u32 player)
{
    Actor *actor;
    f32 pos[3];

    func_800F5A00(player, pos);
    actor = func_80108474(0x2C5, pos, 0);
    *(u32 *) func_80100094(actor, 0) = player;
    actor->rotation[1] = func_800F5F24(player);
    func_808002D0_ch1pfreeze(actor, 2);
    return actor->unk0;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800420_ch1pfreeze[20] = {0x15802C5,
                                 0x75D0001,
                                 0x0,
                                 (u32) func_80800054_ch1pfreeze,
                                 (u32) func_80105834,
                                 (u32) func_8080014C_ch1pfreeze,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x20000,
                                 (u32) func_80800014_ch1pfreeze,
                                 (u32) func_80108ED0,
                                 0x240000,
                                 (u32) func_8080000C_ch1pfreeze,
                                 (u32) func_80107C2C,
                                 -0x7FFFDBEE,
                                 (u32) func_80800294_ch1pfreeze,
                                 0x0,
                                 0x0,
                                 0x0};
