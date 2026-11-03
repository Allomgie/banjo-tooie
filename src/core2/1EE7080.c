#include "common.h"

typedef struct {
    u8 source;
    u8 pad_1[3];
    s32 start_time;
} SoundEntry;
extern SoundEntry D_80136F90[13][2];
extern u8 D_80124730[13];
extern int func_800C3D78(u8);
extern u8 func_800C2E04(void);
extern void func_800C2E40();
extern void func_800C3584();
extern void func_800C330C();
extern void func_800C3418();
extern void func_800C32C4();
extern void func_800C4350();
extern void func_800C3B8C();
extern void func_800C3BDC();
extern s32 func_8001211C(void);
void func_8010DA30();
SoundEntry *func_8010DA70();

void func_8010D790(void)
{
    s32 i;
    s32 j;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < D_80124730[i]; j++) {
            D_80136F90[i][j].source = 0;
            D_80136F90[i][j].start_time = -1;
        }
    }
}

// Frees sources that finished playing.
void func_8010D7EC(void)
{
    SoundEntry *entry;
    s32 i;
    s32 j;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < D_80124730[i]; j++) {
            entry = &D_80136F90[i][j];
            if (entry->source && !func_800C3D78(entry->source))
                func_8010DA30(entry);
        }
    }
}

// Frees every slot.
void func_8010D89C(void)
{
    SoundEntry *entry;
    s32 i;
    s32 j;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < D_80124730[i]; j++) {
            entry = &D_80136F90[i][j];
            func_8010DA30(entry);
        }
    }
}

// Plays a sound in the category, taking over the least recently started slot.
s32 func_8010D930(s32 category, s32 pan_mode, s32 pos, s32 script)
{
    u8 *entry;

    entry = func_8010DA70(category);
    if (*(u8 *) entry == 0) {
        *(u8 *) entry = func_800C2E04();
    } else {
        func_800C2E40(*(u8 *) entry);
    }
    if (pos != 0) {
        func_800C3584(*(u8 *) entry, 0x43480000, 0x453B8000);
    }
    func_800C330C(*(u8 *) entry, 3);
    if (pan_mode >= 0) {
        if (pan_mode != 0) {
            func_800C3418(*(u8 *) entry, 1);
            func_800C32C4(*(u8 *) entry, 0x40);
        } else {
            func_800C3418(*(u8 *) entry, 2);
        }
    } else {
        func_800C3418(*(u8 *) entry, 0);
    }
    func_800C4350(*(u8 *) entry, pos, script);
    func_800C3B8C(*(u8 *) entry, 0);
    func_800C3BDC(*(u8 *) entry);
    *(s32 *) (entry + 4) = func_8001211C();
    return 1;
}

// Frees the slot's source and marks the slot unused.
void func_8010DA30(entry) u8 *entry;
{
    unsigned int source;
    source = *(u8 *) entry;
    // Matching: the do-while (0) wrapper is needed for the match.
    do {
        if (source != 0) {
            func_800C2FDC(source & 0xFF, entry, source);
            *(u8 *) ((s8 *) entry + 0) = 0;
        }
        *(s32 *) ((s8 *) entry + 4) = -1;
    } while (0);
}

// Returns the slot with the oldest start time.
SoundEntry *func_8010DA70(category)
s32 category;
{
    SoundEntry *oldest;
    s32 i;
    oldest = &D_80136F90[category][0];
    for (i = 1; i < D_80124730[category]; i++) {
        if (D_80136F90[category][i].start_time < oldest->start_time)
            oldest = &D_80136F90[category][i];
    }
    return oldest;
}

// TU-NOTE: the .data of this file is defined here in C; values are taken from the ROM.
u8 D_80124730[13] = {0x1, 0x1, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x1, 0x1, 0x1};
