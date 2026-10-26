#include "common.h"

extern int D_808001C0_chtemplebossdoor;
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);

int chtemplebossdoor_entrypoint_0()
{
    return (int)&D_808001C0_chtemplebossdoor;
}

void func_8080000C_chtemplebossdoor(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    local_1 = 0;
    switch (((u32)*(u16 *)((u8 *)param_0 + 0x76) >> 7) - 50) {
        case 0: local_0 = 10; break;
        case 1: local_0 = 20; local_1 = 2; break;
    }
    if (func_800D035C(5) < local_0) {
        if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 190.0f, 0x40, -1)) {
            _chdoormake_entrypoint_5(param_0, 1.5f);
            _chdoormake_entrypoint_8(param_0, 5);
            _chdoormake_entrypoint_9(param_0, 0, local_1, 0x30);
        }
    } else func_800FFA88(param_0->unk0);
}

s32 func_808000E8_chtemplebossdoor(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    switch (param_1) {
        case 7:
            local_0 = param_0->unk74_7 - 0x32;
            if (param_2 != local_0) return 0;
            _subaddiedialog_entrypoint_11(param_0->unk0, local_0 ? 0xF3B : 0xF3A,
                0x106, param_0->position, 0xB2);
            break;
        case 0x2E:
            func_80108BD4(param_0, 0);
            return 1;
        case 0x59:
            _capod_entrypoint_14();
            func_800FFA88(param_0->unk0);
            return 1;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}
