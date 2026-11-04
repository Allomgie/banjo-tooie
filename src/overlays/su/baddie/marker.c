#include "common.h"
// TU-NOTE: the .data of this overlay is defined here in C; values come from the ROM.

typedef struct MarkerSearchResult {
    f32 pos[3];
    s32 type;
    f32 yaw;
    f32 scale;
} MarkerSearchResult;
extern f32 _gspropmarker_entrypoint_3(void *);

// TU-NOTE: this .bss object is defined ahead of its first use because IDO places
// .bss objects used before their definition first, the rest in definition order.
u8 *B_808001E0_subaddiemarker[40];

// Collects up to 40 markers near search_pos into out; returns the count.
s32 subaddiemarker_entrypoint_0(s32 unk_0, void *search_pos, MarkerSearchResult *out,
                                s32 unk_3)
{
    s32 count;
    s32 i;
    count = _gccubesearch_entrypoint_9(search_pos, B_808001E0_subaddiemarker, 40);
    for (i = 0; i < count; i++) {
        out->scale = _gspropmarker_entrypoint_3(B_808001E0_subaddiemarker[i]);
        out->yaw = (f32) (*(u32 *) (B_808001E0_subaddiemarker[i] + 0xC) >> 23);
        out->type = (u32) *(u16 *) (B_808001E0_subaddiemarker[i] + 6) >> 7;
        func_800EE88C(out->pos, B_808001E0_subaddiemarker[i]);
        out++;
    }
    return count;
}

// Like entry 0, but only markers of the given type.
s32 subaddiemarker_entrypoint_1(s32 unk_0, f32 *search_pos, s32 type, MarkerSearchResult *out)
{
    s32 found;
    s32 count;
    s32 i;

    count = _gccubesearch_entrypoint_9(search_pos, B_808001E0_subaddiemarker, 40);
    found = 0;
    for (i = 0; i < count; i++) {
        if (((u32) *(u16 *) (B_808001E0_subaddiemarker[i] + 6) >> 7) == type) {
            out->scale = _gspropmarker_entrypoint_3(B_808001E0_subaddiemarker[i]);
            out->yaw = (f32) (*(u32 *) (B_808001E0_subaddiemarker[i] + 0xC) >> 23);
            out->type = (u32) *(u16 *) (B_808001E0_subaddiemarker[i] + 6) >> 7;
            func_800EE88C(out->pos, B_808001E0_subaddiemarker[i]);
            out++;
            found++;
        }
    }
    return found;
}
