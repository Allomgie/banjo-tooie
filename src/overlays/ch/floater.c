#include "common.h"

extern void *D_808002A0_chfloater;
extern void *func_80100094(Actor *, s32);
extern f32 _mlwave_entrypoint_5(void *, f32, f32);
extern f32 func_800136E4(f32);
typedef struct {
    u8 pad_0[8];
    u32 pad_8 : 26;
    u32 unk_8 : 1;
    u32 unk_8_1 : 1;
    u32 pad_8_2 : 4;
} FloaterNodeFlags;
extern void func_80102FDC(Actor *, f32);
extern void _mlwave_entrypoint_0(void *, f32, f32);
extern void _mlwave_entrypoint_2(void *, f32, f32);

int chfloater_entrypoint_0()
{
    return &D_808002A0_chfloater;
}

// Update: advance the three wave oscillators and apply roll, pitch and bobbing height.
void func_8080000C_chfloater(Actor *actor)
{
    u8 *waves;

    waves = func_80100094(actor, 0);
    _mlwave_entrypoint_1(waves);
    _mlwave_entrypoint_1(waves + 0x1C);
    _mlwave_entrypoint_1(waves + 0x38);
    actor->rotation[2] = func_800136E4(((f32 *) actor->actorData)[4] +
                                         _mlwave_entrypoint_5(waves + 0x1C, -7.5f, 7.5f));
    actor->rotation[0] =
        func_800136E4(((f32 *) actor->actorData)[5] + _mlwave_entrypoint_5(waves, -3.0f, 3.0f));
    actor->position[1] =
        ((f32 *) actor->actorData)[6] + _mlwave_entrypoint_5(waves + 0x38, -20.0f, 20.0f);
}

// Init: snap to the nearest cube node prop within 500 units and take model, yaw, pitch and scale from it.
void func_808000C0_chfloater(Actor *actor)
{
    u8 *waves;
    s32 unk_0;
    u8 *found;
    s32 pos[3];
    u8 *prop;
    waves = func_80100094(actor, 0);
    func_800EE904(pos, actor->position);
    if (_gccubesearch_entrypoint_16(pos, &unk_0, &found, 2, 500)) {
        prop = found;
        ((FloaterNodeFlags *) prop)->unk_8 = 1;
        ((FloaterNodeFlags *) prop)->unk_8_1 = 0;
        func_800EE88C(actor->position, prop + 4);
        actor->rotation[1] = func_800136E4(2.0f * (f32) (u32) prop[2]);
        actor->rotation[0] = func_800136E4(2.0f * (f32) (u32) prop[3]);
        ((f32 *) actor->actorData)[5] = actor->rotation[0];
        ((f32 *) actor->actorData)[4] = 0.0f;
        ((f32 *) actor->actorData)[6] = actor->position[1];
        func_80102FDC(actor, (f32) (u32) prop[0xA] * 0.01f);
        func_80103140(actor, _gsproplookup_entrypoint_0(prop) & 0xFFFF, 0);
        _mlwave_entrypoint_0(waves, 100.0f, 30.0f);
        prop = waves + 0x1C;
        _mlwave_entrypoint_0(prop, 100.0f, 20.0f);
        _mlwave_entrypoint_0(waves + 0x38, 100.0f, 20.0f);
        _mlwave_entrypoint_2(waves, 0.0f, 5.0f);
        _mlwave_entrypoint_2(prop, 5.0f, 10.0f);
        _mlwave_entrypoint_2(waves + 0x38, 3.0f, 7.0f);
        func_8010A800(actor, 2);
        func_80104E78(actor);
    }
}

// TU-NOTE: the .data of this overlay is defined here in C, values taken from the ROM.
// Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
// functions differently unless the tables are defined in the same unit.
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
void *D_808002A0_chfloater = (void *) 0x02AB0349;
static u32 D_808002A0_chfloater_rest[19] = {0xFFFF0001,
                                            0x0,
                                            (u32) func_8080000C_chfloater,
                                            (u32) func_80102EC0,
                                            (u32) func_80101870,
                                            0x28A0000,
                                            0x0,
                                            0x0,
                                            0x4804,
                                            0x0,
                                            0x0,
                                            0x540000,
                                            (u32) func_808000C0_chfloater,
                                            (u32) func_80107C2C,
                                            0x80004412,
                                            0x0,
                                            0x0,
                                            0x0,
                                            0x0};
