#include "common.h"
#include "playerstate.h"

typedef struct { s16 local_0; s16 pad_0; } PreloadAnimation;
extern PreloadAnimation D_808002A0_bapreload[];
extern u8 D_8012762C;
extern s16 D_80800310_bapreload[][2];
extern s16 D_80800320_bapreload[][2];
extern s16 D_80800300_bapreload[][2];
extern s16 D_808002F0_bapreload[][2];
void func_80800000_bapreload();

void func_80800000_bapreload(param_0, param_1, param_2, param_3) PlayerState *param_0; s32 param_1; s16 *param_2; s16 *param_3;
{
    s16 (*local_0)[2];

    switch (param_1) {
        case 6: local_0 = D_80800310_bapreload; break;
        case 12: local_0 = D_80800320_bapreload; break;
        case 11: local_0 = D_80800300_bapreload; break;
        case 1: local_0 = D_808002F0_bapreload; break;
        case 17:
            *param_2 = 0x60E;
            *param_3 = 0;
            return;
        default:
            *param_2 = 0x607;
            *param_3 = 0;
            return;
    }
    local_0 += func_800EA068(0x20) ? func_800A940C(param_0->unk184) : param_0->unk184;
    *param_2 = (*local_0)[0];
    *param_3 = (*local_0)[1];
}

void bapreload_entrypoint_0(void *param_0, s32 param_1, s16 *param_2, s16 *param_3)
{
    if (func_800D3948()) {
        func_80800000_bapreload(param_0, param_1, param_2, param_3);
        return;
    }
    if (param_1 == 11) {
        if (func_8009EA2C()) *param_2 = 0x83A;
        else *param_2 = 0x61C;
        *param_3 = 0;
    } else {
        *param_2 = D_808002A0_bapreload[param_1].local_0;
        *param_3 = 0;
        if (!*param_2) {
            if (D_8012762C == 13) *param_2 = 0;
            else *param_2 = 0x607;
        }
    }
}

s32 bapreload_entrypoint_1(s32 param_0, s32 *param_1)
{
    s32 local_0;
    /* TU-only match: uses PreloadAnimation and D_808002A0_bapreload from bapreload_entrypoint_0. */
    local_0 = D_808002A0_bapreload[param_0].pad_0;
    *param_1 = 0;
    switch (param_0) {
        case 11:
            if (func_8009EA2C()) local_0 = 0x62E;
            break;
        case 1:
        case 10:
            if (func_8009EA2C()) *param_1 = 1;
            break;
    }
    return local_0;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ba/preload.data.s) is defined here in C.
 * Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_808002A2_bapreload = D_808002A0_bapreload + 0x2 */
PreloadAnimation D_808002A0_bapreload[20] = { 0x0, -0x4D2, 0x0, 0x853, 0x60B, 0x858, 0x0, -0x4D2, 0x61F, -0x4D2, 0x0, -0x4D2, 0x613, 0x85E, 0x60C, 0x800, 0x61D, 0x6BF, 0x0, 0x853, 0x0, 0x853, 0x0, 0x855, 0x626, 0x6C2, 0x665, 0x854, 0x673, 0x856, 0x623, 0x6C0, 0x624, 0x6C1, 0x60E, 0x80A, 0x609, 0x7FA, 0x60D, 0x809 };
s16 D_808002F0_bapreload[4][2] = { 0x992, 0xC5E, 0x992, 0xC5F, 0x992, 0xC60, 0x992, 0xC61 };
s16 D_80800300_bapreload[4][2] = { 0x993, 0xC5A, 0x993, 0xC5B, 0x993, 0xC5C, 0x993, 0xC5D };
s16 D_80800310_bapreload[4][2] = { 0x994, 0x0, 0x995, 0x0, 0x996, 0x0, 0x997, 0x0 };
s16 D_80800320_bapreload[4][2] = { 0x998, 0xC62, 0x998, 0xC63, 0x998, 0xC64, 0x998, 0xC65 };
