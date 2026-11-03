#include "su/restart.h"

typedef struct {
    s16 respawnMap;
    s16 transformationMap;
    u8 transformation;
    u8 entranceId;
} RestartData;

extern RestartData D_808000D0_surestart[];

void surestart_entrypoint_0(s32 arg0)
{
    s32 transformationHome;
    s32 currentMap;
    s32 mapId;
    s32 entranceId;
    s32 i = 0;
    currentMap = func_800EA05C();
    if (arg0 == 1) {
        func_8009EBD0();
        return;
    }
    for (i = 0; i < 20; i++) {
        if ((arg0 == D_808000D0_surestart[i].transformation) &&
            (transformationHome = D_808000D0_surestart[i].transformationMap,
             (transformationHome == 0) || (currentMap == transformationHome))) {
            mapId = D_808000D0_surestart[i].respawnMap;
            entranceId = D_808000D0_surestart[i].entranceId;
            if ((transformationHome == MAP_13E_CCL_MUMBO) ||
                (transformationHome == MAP_13F_CCL_MINGY_JONGO)) {
                if (func_800DA298(FLAG_40A_RANDOMISER_CCL_SKULL_1) == 0) {
                    entranceId = 9;
                }
            }
            func_8009EB24(mapId, entranceId);
            return;
        }
    }
}

RestartData D_808000D0_surestart[20] = {
    0xB8,  0xB7,  0xD,   0x5,   0xC7,  0xD9,  0xD,   0x8,   0xE7,  0x176, 0xD,   0x2,   0x1A7, 0xEF,
    0xD,   0xE,   0x112, 0x171, 0xD,   0x4,   0x108, 0x172, 0xD,   0xA,   0x127, 0x134, 0xD,   0x3,
    0x136, 0x13E, 0xD,   0x16,  0x136, 0x13F, 0xD,   0x16,  0x155, 0x156, 0xD,   0x8,   0x128, 0x0,
    0x2,   0x8,   0x136, 0x0,   0x6,   0x19,  0x106, 0x0,   0x7,   0xA,   0xC4,  0x0,   0x8,   0x4,
    0x1A8, 0x0,   0xC,   0x12,  0xC7,  0x0,   0xF,   0xE,   0xD6,  0x0,   0x10,  0xA,   0x112, 0x0,
    0x12,  0x6,   0x112, 0x0,   0x13,  0x16,  0xB8,  0x0,   0xE,   0x9};
u32 D_80800148_surestart[2] = {0x0, 0x0};
