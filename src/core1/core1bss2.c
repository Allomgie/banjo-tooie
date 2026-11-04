// No code: a bss-only file holding audio variables that belong to other core1 files.
#include "types.h"

// TU-NOTE: These bss variables were moved here to ease bss migration of other files;
// they all belong to other C files (core1/1E36640, 1E38AA0, 1E39740, 1E39CE0).

u8 D_8007E9C0[0x64];

// Per-channel volume table (core1/1E36640).
s32 D_8007EA24;
u8 pad1[8];

// Sound output mode and per-bus routing flags (core1/1E38AA0, read by 1E42810/1E43D60).
u8 D_8007EA30;
u8 D_8007EA31;
u8 D_8007EA32;
u8 D_8007EA33;
u8 D_8007EA34;
u8 D_8007EA35;
u8 pad2_6; // Not an array: automatic alignment would change the layout.
u8 pad2_7;
u8 pad2_8;
u8 pad2_9;
u8 pad2_A;
u8 pad2_B;
u8 pad2_C;
u8 pad2_D;
u8 pad2_E;
u8 pad2_F;

// Free lists (core1/1E39740).
s32 D_8007EA40;
s32 D_8007EA44;
u8 pad3[0x8];

// Per-channel state of the seqplayer (core1/1E39CE0).
u8 D_8007EA50[0x80];
