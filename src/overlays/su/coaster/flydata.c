#include "common.h"

typedef struct { u16 local_0; u8 pad_0[0x26]; } CoasterFlyRecord62;
extern CoasterFlyRecord62 D_80800290_sucoasterflydata[];
typedef struct { u8 pad[0x28]; } CoasterEntry;
extern u8 D_80800358_sucoasterflydata[];
extern u8 D_808003AC_sucoasterflydata[];
extern u8 D_808003F4_sucoasterflydata[];
extern u8 D_8080043C_sucoasterflydata[];

s32 sucoasterflydata_entrypoint_0(void **param_0)
{
    u32 local_0;
    s32 local_1;

    local_0 = *(u32 *)((u8 *)*param_0 + 0x24) >> 22;
    for (local_1 = 0; local_1 < 5; local_1++) {
        if (local_0 == D_80800290_sucoasterflydata[local_1].local_0) return local_1;
    }
    return 0;
}

CoasterEntry *sucoasterflydata_entrypoint_1(s32 param_0) {
    return &((CoasterEntry *) D_80800290_sucoasterflydata)[param_0];
}

void *sucoasterflydata_entrypoint_2(s32 param_0, s32 *param_1)
{
    switch (param_0) {
        case 0:
            *param_1 = 7;
            return D_80800358_sucoasterflydata;
        case 1:
        case 2:
            *param_1 = 6;
            return D_808003AC_sucoasterflydata;
        case 3:
            *param_1 = 6;
            return D_808003F4_sucoasterflydata;
        case 4:
            *param_1 = 6;
            return D_8080043C_sucoasterflydata;
        default:
            *param_1 = 0;
    }
    return NULL;
}

int sucoasterflydata_entrypoint_3(int param_0)
{
    switch (param_0)
    {
        case 0:
            return 0x12C;

        case 1:
            return 0xFA;

        case 2:
            return 0xFA;

        case 3:
            return 0x12C;

        case 4:
            return 0x12C;

        default:
            return 0;
    }
}

int sucoasterflydata_entrypoint_4(int param_0)
{
    switch (param_0)
    {
        case 0:
            return 0x190;

        case 1:
            return 0x12C;

        case 2:
            return 0x12C;

        case 3:
            return 0x190;

        case 4:
            return 0x190;

        default:
            break;
    }

    return 0;
}

int sucoasterflydata_entrypoint_5(int param_0)
{
    switch (param_0)
    {
        case 0:
            return 800;
        case 1:
            return 600;
        case 2:
            return 600;
        case 3:
            return 1200;
        case 4:
            return 1000;
        default:
            return 0;
    }
}
