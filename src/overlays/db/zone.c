#include "common.h"

typedef struct { u8 pad_0[12]; u8 local_0; u8 pad_1; } DbZoneFlag27;
typedef struct { u8 pad0[12]; u8 unkC; u8 padD; } ZoneEntry;
typedef struct { u8 count; u8 pad1; ZoneEntry entries[1]; } ZoneList;
typedef struct { s16 a; s16 b[6]; } ZoneEnt;
typedef struct { s16 local_0[7]; } DbQueryZone1262_dbzone_entrypoint_3;
extern void func_800EE940();
typedef struct DbQueryZone1262_dbzone_entrypoint_4 { s16 local_0[7]; } DbQueryZone1262_dbzone_entrypoint_4;

s32 dbzone_entrypoint_0(u8 *param_0, u8 *param_1, u32 param_2)
{
    DbZoneFlag27 *local_0;

    local_0 = (DbZoneFlag27 *)(param_0 + 2);
    for (; param_2; param_2--) {
        if (local_0[*param_1].local_0) {
            return 1;
        }
        param_1++;
    }
    return 0;
}

int func_8080010C_dbzone(void *param_0, s16 *param_1)
{
    s16 *local_0;

    local_0 = param_0;
    return param_1[0] >= local_0[0] && param_1[0] <= local_0[3] &&
           param_1[1] >= local_0[1] && param_1[1] <= local_0[4] &&
           param_1[2] >= local_0[2] && param_1[2] <= local_0[5];
}

void dbzone_entrypoint_1(ZoneList *param_0, f32 *param_1, f32 param_2, f32 *param_3)
{
    s32 i;
    ZoneEntry *e;
    ZoneEntry *end;
    s32 pad;
    s16 local_0[3];

    param_2 = 1.0f / param_2;
    for (i = 0; i < 3; i++) {
        local_0[i] = (param_1[i] - param_3[i]) * param_2;
    }
    e = param_0->entries;
    end = &e[param_0->count];
    for (; e < end; e++) {
        e->unkC = func_8080010C_dbzone(e, local_0);
    }
}

void dbzone_entrypoint_2(ZoneEnt *param_0, f32 *param_1, s32 param_2) {
    s32 local_0[3];
    func_800EE940(local_0, param_1);
    func_8080010C_dbzone(param_0[param_2].b, local_0);
}

s32 dbzone_entrypoint_3(u8 *param_0, f32 *param_1)
{
    DbQueryZone1262_dbzone_entrypoint_3 *local_1;
    DbQueryZone1262_dbzone_entrypoint_3 *local_2;
    DbQueryZone1262_dbzone_entrypoint_3 *local_3;
    s16 local_0[3];

    local_2 = (DbQueryZone1262_dbzone_entrypoint_3 *)(param_0 + 2 + param_0[0] * sizeof(DbQueryZone1262_dbzone_entrypoint_3));
    func_800EE940(local_0, param_1);
    local_3 = (DbQueryZone1262_dbzone_entrypoint_3 *)(param_0 + 2);
    for (local_1 = local_3; local_1 < local_2; local_1++) {
        if (func_8080010C_dbzone(local_1, local_0)) {
            return local_1 - local_3;
        }
    }
    return -1;
}

s32 dbzone_entrypoint_4(u8 *param_0, f32 *param_1, u8 *param_2)
{
    DbQueryZone1262_dbzone_entrypoint_4 *local_1;
    DbQueryZone1262_dbzone_entrypoint_4 *local_2;
    DbQueryZone1262_dbzone_entrypoint_4 *local_3;
    s16 local_0[3];
    s32 local_4 = 0;

    local_2 = (DbQueryZone1262_dbzone_entrypoint_4 *)(param_0 + 2 + param_0[0] * sizeof(DbQueryZone1262_dbzone_entrypoint_4));
    func_800EE940(local_0, param_1);
    local_3 = (DbQueryZone1262_dbzone_entrypoint_4 *)(param_0 + 2);
    for (local_1 = local_3; local_1 < local_2; local_1++) {
        if (func_8080010C_dbzone(local_1, local_0)) {
            param_2[local_4++] = local_1 - local_3;
        }
    }
    return local_4;
}
