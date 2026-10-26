#include "common.h"

#define CODEX_MARKER_SETUP_RECORD
typedef struct { f32 position[3]; s32 unkC; f32 unk10; f32 unk14; } MarkerSetupRecord;
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
    extern int D_80800170_chcastleshockpadswitch;
    return (int)&D_80800170_chcastleshockpadswitch;
}

void func_8080000C_chcastleshockpadswitch(Actor *param_0)
{
    MarkerSetupRecord local_0;

    if (!_subaddiemarker_entrypoint_1(param_0, 0x4E8, 50, &local_0, 1)) {
        func_800FFAB0(param_0);
    } else {
        func_800EE7F8((f32 *)&param_0->actorData[0], local_0.position);
        *(f32 *)&param_0->actorData[3] = local_0.unk10;
        if (_chswitch_entrypoint_7(param_0, 0xA2)) {
            func_80108B04(param_0, 0);
        }
        _chswitch_entrypoint_9(param_0);
    }
}

s32 func_80800094_chcastleshockpadswitch(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;

    switch (param_1) {
    case 7:
        func_80108B04(param_0, 1);
        _capod_entrypoint_13(param_0->unk0, NULL, 6, 0x10);
        break;
    case 0x3D:
        local_0 = func_80108528(0x210, (f32 *)param_0->actorData, (s32)*(f32 *)((u8 *)param_0 + 0x24), &param_0);
        if (param_2 != 0) {
            _subaddiefade_entrypoint_2(local_0);
            _chappearfx_entrypoint_1(local_0, 0x22, 1, 1.0f);
        }
        break;
    default:
        return _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
    return 1;
}
