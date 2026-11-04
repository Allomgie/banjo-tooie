#include "common.h"

typedef struct {
    s16 flag;
    s16 text;
} DialogEntry;
extern int D_808000E0_sudialog[];
extern int D_808000E2_sudialog[];

// Returns the table index of flag_id, or -1. The table ends with a negative flag.
s32 func_80800000_sudialog(DialogEntry *entries, s32 flag_id)
{
    s32 i;
    for (i = 0; entries[i].flag >= 0; i++) {
        if (entries[i].flag == flag_id) {
            return i;
        }
    }
    return -1;
}

// Shows the first-time text for flag_id once; the flag is set when the text starts.
int sudialog_entrypoint_0(s32 flag_id, s32 unk_0)
{
    s32 index;
    if (func_800DA298(flag_id)) {
        return 0;
    }
    index = func_80800000_sudialog(&D_808000E0_sudialog, flag_id);
    if (index != -1) {
        if (func_800C05B8(*(s16 *) ((char *) D_808000E2_sudialog + index * 4), unk_0, 0, 0, 0,
                          0, 0)) {
            func_800DA544(flag_id);
        }
        func_800DA298(flag_id);
    } else {
        return 0;
    }
}

// TU-NOTE: .data is defined here in C (values from the ROM). Table of {s16 flag, s16 text}
// entries. D_808000E2_sudialog = D_808000E0_sudialog + 0x2 (linker symbol); the extern of
// D_808000E0_sudialog is declared int[] to match the object.
int D_808000E0_sudialog[20] = {0x290CDB,  0x2A0CDC,  0x2B0CDD, 0x2C0CDE,  0x2D0CDF,
                               0x2F0CE0,  0x320CE1,  0xE80D8C, 0x19F10C4, 0x1651013,
                               0x3641369, 0x4F50D81, 0x5011E7, 0x4E121F,  0x4F1220,
                               0x2E0D04,  -0x1,      0x0,      0x0,       0x0};
