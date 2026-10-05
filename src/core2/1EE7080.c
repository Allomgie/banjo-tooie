#include "common.h"

typedef struct { u8 local_0; u8 pad1[3]; s32 unk4; } SoundEntry;
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

void func_8010D790(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < D_80124730[i]; j++) {
            D_80136F90[i][j].local_0 = 0;
            D_80136F90[i][j].unk4 = -1;
        }
    }
}

void func_8010D7EC(void) {
    SoundEntry *local_0;
    s32 local_1;
    s32 local_2;
    for (local_1 = 0; local_1 < 13; local_1++) {
        for (local_2 = 0; local_2 < D_80124730[local_1]; local_2++) {
            local_0 = &D_80136F90[local_1][local_2];
            if (local_0->local_0 && !func_800C3D78(local_0->local_0)) func_8010DA30(local_0);
        }
    }
}

void func_8010D89C(void) {
    SoundEntry *local_0;
    s32 local_1;
    s32 local_2;
    for (local_1 = 0; local_1 < 13; local_1++) {
        for (local_2 = 0; local_2 < D_80124730[local_1]; local_2++) {
            local_0 = &D_80136F90[local_1][local_2];
            func_8010DA30(local_0);
        }
    }
}

s32 func_8010D930(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    u8 *temp_v0;

    temp_v0 = func_8010DA70(param_0);
    if (*(u8 *)temp_v0 == 0) {
        *(u8 *)temp_v0 = func_800C2E04();
    } else {
        func_800C2E40(*(u8 *)temp_v0);
    }
    if (param_2 != 0) {
        func_800C3584(*(u8 *)temp_v0, 0x43480000, 0x453B8000);
    }
    func_800C330C(*(u8 *)temp_v0, 3);
    if (param_1 >= 0) {
        if (param_1 != 0) {
            func_800C3418(*(u8 *)temp_v0, 1);
            func_800C32C4(*(u8 *)temp_v0, 0x40);
        } else {
            func_800C3418(*(u8 *)temp_v0, 2);
        }
    } else {
        func_800C3418(*(u8 *)temp_v0, 0);
    }
    func_800C4350(*(u8 *)temp_v0, param_2, param_3);
    func_800C3B8C(*(u8 *)temp_v0, 0);
    func_800C3BDC(*(u8 *)temp_v0);
    *(s32 *)(temp_v0 + 4) = func_8001211C();
    return 1;
}

void func_8010DA30(param_0) u8 * param_0;
{
  unsigned int local_0;
 local_0 = *((u8 *) param_0); do { if (local_0 != 0) { func_800C2FDC(local_0 & 0xFF, param_0, local_0); *((u8 *) (((s8 *) param_0) + 0)) = 0; } *((s32 *) (((s8 *) param_0) + 4)) = -1; } while (0);
}

SoundEntry *func_8010DA70(param_0) s32 param_0; {
    SoundEntry *local_0;
    s32 local_1;
    local_0 = &D_80136F90[param_0][0];
    for (local_1 = 1; local_1 < D_80124730[param_0]; local_1++) {
        if (D_80136F90[param_0][local_1].unk4 < local_0->unk4) local_0 = &D_80136F90[param_0][local_1];
    }
    return local_0;
}
