#include "common.h"

extern Actor *func_80106790(Unk80132ED0 *);
extern int _sulights_entrypoint_1(u32, u32[3], f32);
extern int _sulights_entrypoint_3(u32, f32[2], f32);

// cmd = light index << 16 | op; arg and arg2 depend on the op.
void indrv_lights_entrypoint_0(u32 cmd, Unk80132ED0 *arg, s32 arg2)
{
    u32 fade_color[5];
    u32 color[3];
    f32 fade_range[2];
    f32 range[2];
    Actor *target;
    s32 unk_0;
    f32 bone_pos[3];

    switch (cmd & 0xFFFF) {
        case 0:
            fade_color[0] = (u32) ((s32) arg & 0xFF000000) >> 24;
            fade_color[1] = ((s32) arg & 0xFF0000) >> 16;
            fade_color[2] = ((s32) arg & 0xFF00) >> 8;
            _sulights_entrypoint_1((cmd & 0xFFFF0000) >> 16, fade_color,
                                   (f32) arg2 * 0.00390625f);
            break;
        case 5:
            color[0] = (u32) ((s32) arg & 0xFF000000) >> 24;
            color[1] = ((s32) arg & 0xFF0000) >> 16;
            color[2] = ((s32) arg & 0xFF00) >> 8;
            func_800C8E84((cmd & 0xFFFF0000) >> 16, color);
            break;
        case 1:
            func_800C8FE0((cmd & 0xFFFF0000) >> 16, 1);
            break;
        case 2:
            func_800C8FE0((cmd & 0xFFFF0000) >> 16, 0);
            break;
        case 3:
            fade_range[0] = (u32) (arg2 & 0xFFFF);
            fade_range[1] = (u32) arg & 0xFFFF;
            _sulights_entrypoint_3((cmd & 0xFFFF0000) >> 16, fade_range,
                                   (f32) arg2 * 0.00390625f);
            break;
        case 4:
            range[0] = (u32) arg2 & 0xFFFF;
            range[1] = (u32) arg & 0xFFFF;
            func_800C8D4C((cmd & 0xFFFF0000) >> 16, range);
            break;
        case 6:
            target = func_80106790(arg);
            if (!target->unk7C_12 || arg2 == -1) {
                func_800C8CB8((cmd & 0xFFFF0000) >> 16, target->position);
            } else {
                func_800DBEFC(arg->unk4, arg2, bone_pos);
                func_800C8CB8((cmd & 0xFFFF0000) >> 16, bone_pos);
            }
            break;
    }
}
