#include "common.h"
#include "playerstate.h"

typedef struct {
    s16 model_id;
    s16 unk_2;
} PreloadAnimation;
extern PreloadAnimation D_808002A0_bapreload[];
extern u8 D_8012762C;
extern s16 D_80800310_bapreload[][2];
extern s16 D_80800320_bapreload[][2];
extern s16 D_80800300_bapreload[][2];
extern s16 D_808002F0_bapreload[][2];

// Multiplayer: model per player index from the tables; returns model id and variant flag.
void func_80800000_bapreload(player, form, model_id, variant) PlayerState *player;
s32 form;
s16 *model_id;
s16 *variant;
{
    s16(*table)[2];

    switch (form) {
        case 6:
            table = D_80800310_bapreload;
            break;
        case 12:
            table = D_80800320_bapreload;
            break;
        case 11:
            table = D_80800300_bapreload;
            break;
        case 1:
            table = D_808002F0_bapreload;
            break;
        case 17:
            *model_id = 0x60E;
            *variant = 0;
            return;
        default:
            *model_id = 0x607;
            *variant = 0;
            return;
    }
    table += func_800EA068(0x20) ? func_800A940C(player->unk184) : player->unk184;
    *model_id = *table[0];
    *variant = (*table)[1];
}

void bapreload_entrypoint_0(void *player, s32 form, s16 *model_id, s16 *variant)
{
    if (func_800D3948()) {
        func_80800000_bapreload(player, form, model_id, variant);
        return;
    }
    if (form == 11) {
        if (func_8009EA2C())
            *model_id = 0x83A;
        else
            *model_id = 0x61C;
        *variant = 0;
    } else {
        *model_id = D_808002A0_bapreload[form].model_id;
        *variant = 0;
        if (!*model_id) {
            if (D_8012762C == 13)
                *model_id = 0;
            else
                *model_id = 0x607;
        }
    }
}

s32 bapreload_entrypoint_1(s32 form, s32 *flag)
{
    s32 result;
    // TU-only match: uses PreloadAnimation and D_808002A0_bapreload from bapreload_entrypoint_0.
    result = D_808002A0_bapreload[form].unk_2;
    *flag = 0;
    switch (form) {
        case 11:
            if (func_8009EA2C())
                result = 0x62E;
            break;
        case 1:
        case 10:
            if (func_8009EA2C())
                *flag = 1;
    }
    return result;
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM). Labels inside
// D_808002A0_bapreload are linker symbols: D_808002A2_bapreload = D_808002A0_bapreload + 0x2.
PreloadAnimation D_808002A0_bapreload[20] = {
    0x0,   -0x4D2, 0x0,   0x853, 0x60B, 0x858, 0x0,   -0x4D2, 0x61F, -0x4D2,
    0x0,   -0x4D2, 0x613, 0x85E, 0x60C, 0x800, 0x61D, 0x6BF,  0x0,   0x853,
    0x0,   0x853,  0x0,   0x855, 0x626, 0x6C2, 0x665, 0x854,  0x673, 0x856,
    0x623, 0x6C0,  0x624, 0x6C1, 0x60E, 0x80A, 0x609, 0x7FA,  0x60D, 0x809};
s16 D_808002F0_bapreload[4][2] = {0x992, 0xC5E, 0x992, 0xC5F, 0x992, 0xC60, 0x992, 0xC61};
s16 D_80800300_bapreload[4][2] = {0x993, 0xC5A, 0x993, 0xC5B, 0x993, 0xC5C, 0x993, 0xC5D};
s16 D_80800310_bapreload[4][2] = {0x994, 0x0, 0x995, 0x0, 0x996, 0x0, 0x997, 0x0};
s16 D_80800320_bapreload[4][2] = {0x998, 0xC62, 0x998, 0xC63, 0x998, 0xC64, 0x998, 0xC65};
