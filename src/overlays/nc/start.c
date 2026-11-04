#include "common.h"

extern void *_gccubesearch_entrypoint_14(s32, s32);
extern f32 func_800136E4(f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);

// Finds the camera-start marker for an entrance; returns its position and a yaw-180 rotation.
s32 ncstart_entrypoint_0(s32 entrance, f32 out_pos[3], f32 out_rot[3])
{
    void *marker;
    s32 marker_id;

    marker_id = 0x29;
    if (func_800A9C98()) {
        if (entrance > 0 && entrance < 9)
            marker_id = entrance + 0xAD;
    } else {
        if (entrance > 0 && entrance < 0x29)
            marker_id = entrance + 0x29;
    }
    marker = _gccubesearch_entrypoint_14(marker_id, 0);
    if (marker) {
        _gspropctrl_entrypoint_11(marker, out_pos);
        func_800EFA4C(out_rot, 0.0f, func_800136E4(_gspropctrl_entrypoint_12(marker) - 180.0f),
                      0.0f);
        return 1;
    }
    return 0;
}
