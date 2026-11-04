// Probably a mine lamp prop: on init it takes over the nearest static prop, and when drawn it
// shows either the normal model or a lit version with two glow models.
#include "common.h"

extern int D_80800240_chmineproplight[];
extern void func_800FFAB0();
extern void func_80103014();
extern void func_80108944();
extern void func_8010A828();
extern f32 func_800136E4(f32);
extern void func_80102FDC(Actor *, f32);

typedef struct {
    u8 pad_0[8];
    u32 pad_1 : 26;
    u32 local_0 : 1;
    u32 local_1 : 1;
    u32 pad_2 : 4;
} MinePropLightFlags1081;

int chmineproplight_entrypoint_0()
{
    return (int) &D_80800240_chmineproplight;
}

// Takes over the nearest static prop's transform and model, then removes that prop.
void func_8080000C_chmineproplight(Actor *actor)
{
    s32 unk_0;
    u8 *found;
    s32 cell_pos[3];
    u8 *prop;

    func_800EE904(cell_pos, actor->position);
    if (_gccubesearch_entrypoint_16(cell_pos, &unk_0, &found, 2, 500)) {
        prop = found;
        ((MinePropLightFlags1081 *) prop)->local_0 = 1;
        ((MinePropLightFlags1081 *) prop)->local_1 = 0;
        func_800EE88C(actor->position, prop + 4);
        actor->rotation[1] = func_800136E4(2.0f * (f32) (u32) prop[2]);
        actor->rotation[0] = func_800136E4(2.0f * (f32) (u32) prop[3]);
        func_80103140(actor, _gsproplookup_entrypoint_0(prop) & 0xFFFF, 0);
        func_80102FDC(actor, (f32) (u32) prop[10] * 0.01f);
        func_80103014(actor);
        func_80108944(actor, actor);
        func_8010A828(actor, 5);
    } else {
        func_800FFAB0(actor);
    }
}

// Draws the normal model, or the lit one with two extra glow models (0x695/0x696).
void func_80800168_chmineproplight(u8 *actor, s32 unk_1)
{
    s32 light_state;

    light_state = func_800EB854();
    if (light_state != 0) {
        if (light_state == 2) {
            func_800DF830(1);
            func_800DE498(unk_1, actor + 4, actor + 0x44, *(s32 **) (actor + 0x38), 0,
                          func_800D674C(0x695));
            func_800DF7E8(func_800D731C(0x696) & 0xFF);
            func_800DF830(1);
            func_800DE498(unk_1, actor + 4, actor + 0x44, *(s32 **) (actor + 0x38), 0,
                          func_800D674C(0x696));
        }
    } else {
        func_80101870(actor, unk_1);
    }
}

void func_80800228_chmineproplight(s32 arg0)
{
}

extern void func_80105834();
extern void func_80107C2C();
int D_80800240_chmineproplight[20] = {0x158024C,
                                      -0xFFFF,
                                      0x0,
                                      (u32) func_80800228_chmineproplight,
                                      (u32) func_80105834,
                                      (u32) func_80800168_chmineproplight,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0xA0804,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_8080000C_chmineproplight,
                                      (u32) func_80107C2C,
                                      -0x7FF7D7EE,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0};
