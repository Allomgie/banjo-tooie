#include "common.h"

extern s32 D_80127194[];
extern s32 defrag(s32);
extern void *heap_alloc(s32);
extern u8 *_gccollectDll_entrypoint_6(u8 *, s32 *);
extern u8 *_subaddiestore_entrypoint_0(u8 *, u8 *);
extern u8 *D_80127198[];
extern u8 *_gccollectDll_entrypoint_7();
extern void _subaddiestore_entrypoint_1();

void cosectionstor_entrypoint_0(void)
{
    s32 local_0;

    for (local_0 = 1; local_0 < 0x10B; local_0++) {
        D_80127194[local_0] = 0;
    }
}

void cosectionstor_entrypoint_1(void) {
    s32 i;
    for (i = 1; i < 0x10B; i++) {
        if (D_80127194[i] != 0) {
            heap_free(D_80127194[i]);
            D_80127194[i] = 0;
        }
    }
}

void cosectionstor_entrypoint_2(void) {
    s32 i;
    for (i = 1; i < 0x10B; i++) {
        if (D_80127194[i] != 0) {
            D_80127194[i] = defrag(D_80127194[i]);
        }
    }
}

void cosectionstor_entrypoint_3(s32 param_0)
{
    u32 wSize;
    s32 iBit = 0;
    u32 *valPtr;
    s32 iWord;

    if (param_0 >= 0xA0) {
        param_0 -= 0xA0;
        func_800FF44C(param_0);
        if (D_80127198[param_0]) {
            heap_free(D_80127198[param_0]);
        }
        wSize = 4;
        D_80127198[param_0] = heap_alloc(wSize * sizeof(u32));
        if (1) {} /* probe: block boundary, so valPtr is reloaded from D_80127198 (uses up the temp the target uses up) */
        valPtr = (u32 *)D_80127198[param_0];
        *valPtr = func_800DAA1C();
        iBit += 8 * sizeof(u32);
        iWord = iBit >> 5;
        D_80127198[param_0] = _gccollectDll_entrypoint_6(D_80127198[param_0], &iWord);
        D_80127198[param_0] = _subaddiestore_entrypoint_0(D_80127198[param_0], (u8 *)((s32 *)D_80127198[param_0] + (((iWord << 5) + 0x7F) >> 7) * 4));
    }
}

void cosectionstor_entrypoint_4(s32 param_0)
{
    s32 iBit = 0;
    u32 *flag_ptr;
    s32 iWord;

    if (param_0 >= 0xA0) {
        param_0 -= 0xA0;
        if (*(s32 *)&D_80127198[param_0]) {
            flag_ptr = (u32 *)D_80127198[param_0];
            func_800DAA28(*flag_ptr);
            iBit += 8 * sizeof(u32);
            iWord = iBit >> 5;
            D_80127198[param_0] = _gccollectDll_entrypoint_7(D_80127198[param_0], &iWord);
            _subaddiestore_entrypoint_1(D_80127198[param_0], (u8 *)((s32 *)D_80127198[param_0] + (((iWord << 5) + 0x7F) >> 7) * 4));
            heap_free(D_80127198[param_0]);
            D_80127198[param_0] = NULL;
        }
    }
}
