#include "common.h"

typedef struct { u8 pad_0[4]; u32 pad_1 : 25; u32 local_0 : 6; u32 local_1 : 1; u16 local_2; u8 pad_2[8]; u8 pad_3 : 7; u8 local_3 : 1; u8 pad_4; } PropMarkerRecord;
extern PropMarkerRecord *func_800E9D68(s32);
extern PropMarkerRecord *func_800E9D90(s32);
typedef struct { s32 word0; u32 pad4:25; u32 kind:6; u32 enabled:1; u16 id; u8 padA[8]; u8 pad12:7; u8 enabled12:1; u8 pad13; } PropMarkerRecord32;

PropMarkerRecord *gspropmarker_entrypoint_0(s32 param_0, s32 param_1)
{
    PropMarkerRecord *local_0;
    PropMarkerRecord *local_1;

    if (param_0 && func_800E9DC4(param_0)) {
        local_0 = func_800E9D68(param_0);
        local_1 = func_800E9D90(param_0);
        for (; local_0 < local_1; local_0++) {
            if ((local_0->local_1 == 1 || (local_0->local_1 == 0 && local_0->local_3 == 1)) &&
                local_0->local_0 == 6 && param_1 == local_0->local_2) return local_0;
        }
    }
    return 0;
}

s32 gspropmarker_entrypoint_1(s32 param_0, s32 *param_1, PropMarkerRecord32 **param_2, s32 param_3)
{
    s32 local_0;
  s32 pad0;
    PropMarkerRecord32 *local_1;
    PropMarkerRecord32 *local_2;
    s32 *local_3;

    local_0 = 0;
    if (!param_3) {
        return 0;
    }
    if (param_0 && func_800E9DC4(param_0)) {
        local_1 = (PropMarkerRecord32 *)func_800E9D68(param_0);
        local_2 = (PropMarkerRecord32 *)func_800E9D90(param_0);
        for (; local_1 < local_2 && local_0 < param_3; local_1++) {
            if ((local_1->enabled == 1 || local_1->enabled == 0 &&
                 local_1->enabled12 == 1) && local_1->kind == 6) {
                for (local_3 = param_1; *local_3 != -1; local_3++) {
                    if (local_1->id == *local_3) {
                        param_2[local_0++] = local_1;
                        break;
                    }
                }
            }
        }
    }
    return local_0;
}

s32 gspropmarker_entrypoint_2(s32 param_0, s32 param_1, f32 param_2[][3], s32 param_3)
{
    s32 local_0;
    PropMarkerRecord *local_1;
    PropMarkerRecord *local_2;

    local_0 = 0;
    if (param_0 && func_800E9DC4(param_0)) {
        local_1 = func_800E9D68(param_0);
        local_2 = func_800E9D90(param_0);
        while (local_1 < local_2 && local_0 < param_3) {
            if ((local_1->local_1 == 1 || (local_1->local_1 == 0 && local_1->local_3 == 1)) &&
                local_1->local_0 == 6 && param_1 == local_1->local_2) {
                param_2[local_0][0] = ((s16 *)local_1)[0];
                param_2[local_0][1] = ((s16 *)local_1)[1];
                param_2[local_0][2] = ((s16 *)local_1)[2];
                local_0++;
            }
            local_1++;
        }
    }
    return local_0;
}

f32 gspropmarker_entrypoint_3(u32 *param_0)
{
    u32 local_0 = param_0[3] & 0x7FFFFF;
    f32 local_1;

    if (local_0 != 0) {
        local_1 = local_0 * 0.01f;
    } else {
        local_1 = 1.0f;
    }
    return local_1;
}
