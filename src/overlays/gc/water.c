// Map-load hook: checks the map model for water triangles and stores the result in game flag 0x6B5.
#include "common.h"

// Map-load hook: sets game flag 0x6B5 if the map model has water triangles
// (translucent layer checked first, then opaque).
int gcwater_entrypoint_0()
{
    s32 found;
    s32 translucent;
    s32 translucent_coll;
    s32 opaque;
    s32 opaque_coll;

    found = 0;
    translucent = func_800BEB28(1);
    if (translucent != 0) {
        translucent_coll = func_800B2720(translucent);
        if (translucent_coll != 0) {
            found = func_800AAD80(translucent_coll);
        }
    }
    if (found == 0) {
        opaque = func_800BEB28(0);
        if (opaque != 0) {
            opaque_coll = func_800B2720(opaque);
            if (opaque_coll != 0) {
                found = func_800AAD80(opaque_coll);
            }
        }
    }
    func_800DA3B8(0x6B5, found ? 1 : 0);
}
