#include "common.h"

typedef struct {
    f32 position[3];
    s32 unkC;
    f32 unk10;
    f32 unk14;
} MarkerSetupRecord;
extern s32 _subaddiemarker_entrypoint_1(Actor *, s32, s32, MarkerSetupRecord *, s32);
extern void func_800FFAB0(Actor *);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 _chswitch_entrypoint_7(Actor *, s32);
extern void _chswitch_entrypoint_9(Actor *);
extern void func_80108B04(Actor *, s32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);

int chcastleshockpadswitch_entrypoint_0()
{
    extern int D_80800170_chcastleshockpadswitch[];
    return (int) &D_80800170_chcastleshockpadswitch;
}

// Crazy Castle shock pad switch: finds its marker, binds to flag 0xA2.
void func_8080000C_chcastleshockpadswitch(Actor *actor)
{
    MarkerSetupRecord marker;

    if (!_subaddiemarker_entrypoint_1(actor, 0x4E8, 50, &marker, 1)) {
        func_800FFAB0(actor);
    } else {
        func_800EE7F8((f32 *) &actor->actorData[0], marker.position);
        *(f32 *) &actor->actorData[3] = marker.unk10;
        if (_chswitch_entrypoint_7(actor, 0xA2)) {
            func_80108B04(actor, 0);
        }
        _chswitch_entrypoint_9(actor);
    }
}

s32 func_80800094_chcastleshockpadswitch(Actor *actor, s32 msg, s32 payload)
{
    Actor *pad;

    switch (msg) {
        case 7:
            func_80108B04(actor, 1);
            _capod_entrypoint_13(actor->unk0, NULL, 6, 0x10);
            break;
        case 0x3D:
            // Spawn the shock-jump pad (actor 0x210) at the marker.
            pad = func_80108528(0x210, (f32 *) actor->actorData,
                                    (s32) *(f32 *) ((u8 *) actor + 0x24), &actor);
            if (payload != 0) {
                _subaddiefade_entrypoint_2(pad);
                _chappearfx_entrypoint_1(pad, 0x22, 1, 1.0f);
            }
            break;
        default:
            return _chswitch_entrypoint_10(actor, msg, payload);
    }
    return 1;
}

extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800170_chcastleshockpadswitch[20] = {0x3430470,
                                             0x7520001,
                                             (u32) &D_8011A270,
                                             (u32) _chswitch_entrypoint_6,
                                             (u32) func_80105834,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x808,
                                             0x0,
                                             0x0,
                                             0x0,
                                             (u32) func_8080000C_chcastleshockpadswitch,
                                             (u32) func_80107C2C,
                                             -0x7FFFD3FE,
                                             (u32) func_80800094_chcastleshockpadswitch,
                                             0x0,
                                             0x0,
                                             0x0};
