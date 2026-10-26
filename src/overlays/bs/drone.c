#include "common.h"

typedef struct { u8 id; u8 pad[19]; } DroneEnt;
extern DroneEnt D_80800180_bsdrone[];
extern s32 _badrone_entrypoint_3(void);
extern void (*D_80800184_bsdrone[][5])(s32);
extern void _badrone_entrypoint_4(s32);
extern void (*D_80800188_bsdrone[][5])(s32);
extern void (*D_8080018C_bsdrone[][5])(s32);
extern s32 D_80800190_bsdrone;

s32 func_80800000_bsdrone() {
    s32 local_0 = _badrone_entrypoint_3();
    s32 i;
    for (i = 0; D_80800180_bsdrone[i].id != 0; i++) {
        if (local_0 == D_80800180_bsdrone[i].id) {
            return i;
        }
    }
    return 0;
}

void bsdrone_entrypoint_0(s32 param_0) {
    _badrone_entrypoint_4(param_0);
    D_80800184_bsdrone[func_80800000_bsdrone(param_0)][0](param_0);
}

void bsdrone_entrypoint_1(s32 param_0) {
    D_80800188_bsdrone[func_80800000_bsdrone()][0](param_0);
}

void bsdrone_entrypoint_2(s32 param_0) {
    D_8080018C_bsdrone[func_80800000_bsdrone()][0](param_0);
}

void bsdrone_entrypoint_3(s32 param_0) {
    s32 (*local_0)(s32);

    local_0 = *(s32 (**)(s32))((char *)&D_80800190_bsdrone + func_80800000_bsdrone() * 0x14);
    if (local_0 != NULL) {
        local_0(param_0);
    }
}
