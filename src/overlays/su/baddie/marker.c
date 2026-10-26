#include "common.h"

#define MARKER_SEARCH_RESULT_DEFINED
typedef struct MarkerSearchResult { f32 local_0[3]; s32 local_1; f32 local_2; f32 local_3; } MarkerSearchResult;
extern u8 *B_808001E0_subaddiemarker[];
extern f32 _gspropmarker_entrypoint_3(void *);

s32 subaddiemarker_entrypoint_0(s32 param_0, void *param_1, MarkerSearchResult *param_2, s32 param_3)
{
    s32 local_0;
    s32 local_1;
    local_0 = _gccubesearch_entrypoint_9(param_1, B_808001E0_subaddiemarker, 40);
    for (local_1 = 0; local_1 < local_0; local_1++) {
        param_2->local_3 = _gspropmarker_entrypoint_3(B_808001E0_subaddiemarker[local_1]);
        param_2->local_2 = (f32)(*(u32 *)(B_808001E0_subaddiemarker[local_1] + 0xC) >> 23);
        param_2->local_1 = (u32)*(u16 *)(B_808001E0_subaddiemarker[local_1] + 6) >> 7;
        func_800EE88C(param_2->local_0, B_808001E0_subaddiemarker[local_1]);
        param_2++;
    }
    return local_0;
}

s32 subaddiemarker_entrypoint_1(s32 param_0, f32 *param_1, s32 param_2, MarkerSearchResult *param_3)
{
    s32 local_1;
    s32 local_2;
    s32 local_0;

    local_2 = _gccubesearch_entrypoint_9(param_1, B_808001E0_subaddiemarker, 40);
    local_1 = 0;
    for (local_0 = 0; local_0 < local_2; local_0++) {
            if (((u32)*(u16 *)(B_808001E0_subaddiemarker[local_0] + 6) >> 7) == param_2) {
                param_3->local_3 = _gspropmarker_entrypoint_3(B_808001E0_subaddiemarker[local_0]);
                param_3->local_2 = (f32)(*(u32 *)(B_808001E0_subaddiemarker[local_0] + 0xC) >> 23);
                param_3->local_1 = (u32)*(u16 *)(B_808001E0_subaddiemarker[local_0] + 6) >> 7;
                func_800EE88C(param_3->local_0, B_808001E0_subaddiemarker[local_0]);
                param_3++;
                local_1++;
            }
    }
    return local_1;
}
