#include "common.h"

extern int D_808001A0_chproplighter[];
extern void func_80103014();
extern void func_80108944();
extern f32 func_800136E4(f32);
extern void func_80102FDC(Actor *, f32);

typedef struct {
    u8 pad_0[8];
    u32 pad_1 : 26;
    u32 unk_8A : 1;
    u32 unk_8B : 1;
    u32 pad_2 : 4;
} PropLightFlags1001;

int chproplighter_entrypoint_0()
{
    return (int) &D_808001A0_chproplighter;
}

// Replaces the nearest type-2 cube prop with a lit actor; removes itself if none is found.
void func_8080000C_chproplighter(Actor *actor)
{
    s32 cube;
    u8 *found;
    s32 search_pos[3];
    u8 *prop;

    func_800EE904(search_pos, actor->position);
    if (_gccubesearch_entrypoint_16(search_pos, &cube, &found, 2, 500)) {
        prop = found;
        // Mark the prop as replaced.
        ((PropLightFlags1001 *) prop)->unk_8A = 1;
        ((PropLightFlags1001 *) prop)->unk_8B = 0;
        // Take over position, yaw, pitch, model and scale of the prop.
        func_800EE88C(actor->position, prop + 4);
        *(f32 *) ((u8 *) actor + 0x48) = func_800136E4(2.0f * (f32) (u32) prop[2]);
        *(f32 *) ((u8 *) actor + 0x44) = func_800136E4(2.0f * (f32) (u32) prop[3]);
        func_80103140(actor, _gsproplookup_entrypoint_0(prop) & 0xFFFF, 0);
        func_80102FDC(actor, (f32) (u32) prop[0xA] * 0.01f);
        func_80103014(actor);
        func_80108944(actor, actor);
        if (!func_80105010(actor))
            func_80104E78(actor);
        func_8010A63C(actor);
    } else
        func_800FFAB0(actor);
}

s32 func_8080017C_chproplighter(s32 param_0)
{
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
// TU-NOTE: .data is defined here (values from the ROM) because IDO schedules some functions differently otherwise.
int D_808001A0_chproplighter[20] = {0x158044B,
                                    -0xFFFF,
                                    0x0,
                                    (u32) func_8080017C_chproplighter,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x4,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_8080000C_chproplighter,
                                    (u32) func_80107C2C,
                                    -0x7FF7D3EE,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0};
