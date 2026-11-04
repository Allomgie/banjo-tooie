#include "su/restart.h"

typedef struct {
    s16 respawn_map;
    s16 home_map_id; // map the Mumbo transformation is in; 0 = any
    u8 transformation;
    u8 entrance_id;
} RestartData;

extern RestartData D_808000D0_surestart[];

// Warps to the respawn map for a transformation; form 1 uses the normal return point.
void surestart_entrypoint_0(s32 transformation_id)
{
    s32 home_map;
    s32 current_map;
    s32 map_id;
    s32 entrance_id;
    s32 i = 0;
    current_map = func_800EA05C();
    if (transformation_id == 1) {
        func_8009EBD0();
        return;
    }
    for (i = 0; i < 20; i++) {
        if ((transformation_id == D_808000D0_surestart[i].transformation) &&
            (home_map = D_808000D0_surestart[i].home_map_id,
             (home_map == 0) || (current_map == home_map))) {
            map_id = D_808000D0_surestart[i].respawn_map;
            entrance_id = D_808000D0_surestart[i].entrance_id;
            if ((home_map == MAP_13E_CCL_MUMBO) ||
                (home_map == MAP_13F_CCL_MINGY_JONGO)) {
                // Cloud Cuckooland skull special case
                if (func_800DA298(FLAG_40A_RANDOMISER_CCL_SKULL_1) == 0) {
                    entrance_id = 9;
                }
            }
            func_8009EB24(map_id, entrance_id);
            return;
        }
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; values taken from the ROM.
RestartData D_808000D0_surestart[20] = {
    0xB8,  0xB7,  0xD,   0x5,   0xC7,  0xD9,  0xD,   0x8,   0xE7,  0x176, 0xD,   0x2,   0x1A7, 0xEF,
    0xD,   0xE,   0x112, 0x171, 0xD,   0x4,   0x108, 0x172, 0xD,   0xA,   0x127, 0x134, 0xD,   0x3,
    0x136, 0x13E, 0xD,   0x16,  0x136, 0x13F, 0xD,   0x16,  0x155, 0x156, 0xD,   0x8,   0x128, 0x0,
    0x2,   0x8,   0x136, 0x0,   0x6,   0x19,  0x106, 0x0,   0x7,   0xA,   0xC4,  0x0,   0x8,   0x4,
    0x1A8, 0x0,   0xC,   0x12,  0xC7,  0x0,   0xF,   0xE,   0xD6,  0x0,   0x10,  0xA,   0x112, 0x0,
    0x12,  0x6,   0x112, 0x0,   0x13,  0x16,  0xB8,  0x0,   0xE,   0x9};
u32 D_80800148_surestart[2] = {0x0, 0x0};
