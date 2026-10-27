#include "common.h"

typedef struct { s16 local_0; s16 local_1; f32 local_2[3]; s32 local_3; s16 local_4; u8 pad_0[2]; s32 local_5; s32 local_6; s32 local_7; s32 local_8; u8 pad_1[4]; } DialogInitRecord;
typedef struct { u8 local_0 : 2; u8 local_1 : 2; u8 pad_0 : 4; } DialogInitChannelFlags;
typedef struct { u32 local_0 : 8; u32 local_1 : 8; u32 local_2 : 1; u32 local_3 : 1; u32 local_4 : 1; u32 pad_0 : 1; u32 local_5 : 1; u32 pad_1 : 3; u8 local_6 : 2; u8 local_7 : 2; u8 local_8 : 2; u8 local_9 : 2; } DialogInitFlags;
typedef struct { s16 local_0 : 8; u16 local_1 : 4; u16 local_2 : 4; } DialogInitMode;
typedef struct { u8 pad_0[0x100]; s32 local_0; s32 local_1[2]; s32 local_2[2]; u8 local_3[2]; u8 local_4[2]; s16 local_5[2]; DialogInitChannelFlags local_6[2]; u8 pad_1[2]; s32 local_7[2]; u8 pad_2[0x30]; s8 local_8; u8 local_9; u16 local_10; DialogInitFlags local_11; DialogInitMode local_12; s16 local_13; s16 local_14; u8 local_15; u8 pad_3; s32 local_16; u8 pad_4[4]; s32 local_17; s32 local_18; s32 local_19; u8 pad_5[4]; u8 local_20; u8 pad_6[3]; DialogInitRecord local_21[4]; } DialogInitState;
extern void func_800EFD24(f32 *);

void gcdialogDll_entrypoint_0(DialogInitState *param_0)
{
    s32 local_0;

    param_0->local_0 = 0;
    for (local_0 = 0; local_0 < 2; local_0++) {
        param_0->local_1[local_0] = 0;
        param_0->local_3[local_0] = 0;
        param_0->local_7[local_0] = 0;
        param_0->local_4[local_0] = 0;
        param_0->local_5[local_0] = -1;
        param_0->local_2[local_0] = 0;
        param_0->local_6[local_0].local_0 = 0;
        param_0->local_6[local_0].local_1 = 0;
    }
    for (local_0 = 0; local_0 < 4; local_0++) {
        param_0->local_21[local_0].local_0 = -1;
        param_0->local_21[local_0].local_1 = 0;
        param_0->local_21[local_0].local_3 = 0;
        param_0->local_21[local_0].local_4 = 0;
        param_0->local_21[local_0].local_5 = 0;
        param_0->local_21[local_0].local_6 = 0;
        param_0->local_21[local_0].local_7 = 0;
        param_0->local_21[local_0].local_8 = 0;
        func_800EFD24(param_0->local_21[local_0].local_2);
    }
    param_0->local_11.local_0 = 0;
    param_0->local_10 = param_0->local_11.local_4 = 0;
    param_0->local_11.local_6 = param_0->local_11.local_7 = param_0->local_11.local_8 = param_0->local_11.local_9 = 0;
    param_0->local_11.local_1 = param_0->local_11.local_2 = 0;
    param_0->local_11.local_3 = 1;
    param_0->local_12.local_0 = -1;
    param_0->local_12.local_1 = param_0->local_12.local_2 = 0;
    param_0->local_13 = -1;
    param_0->local_14 = -1;
    param_0->local_16 = 0;
    param_0->local_17 = 0;
    param_0->local_18 = 0;
    param_0->local_19 = 0;
    param_0->local_15 = 0xC;
    param_0->local_9 = 0;
    param_0->local_8 = -1;
    param_0->local_11.local_5 = 1;
    param_0->local_20 = 1;
}
