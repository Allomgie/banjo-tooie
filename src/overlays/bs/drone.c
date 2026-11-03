#include "common.h"

typedef struct { u8 id; u8 pad1[3]; void *fn[4]; } DroneEnt;
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

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/bs/drone.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_80800184_bsdrone = D_80800180_bsdrone + 0x4, D_80800188_bsdrone = D_80800180_bsdrone + 0x8, D_8080018C_bsdrone = D_80800180_bsdrone + 0xC, D_80800190_bsdrone = D_80800180_bsdrone + 0x10 */
extern void _bsdronegoto_entrypoint_0();
extern void _bsdronegoto_entrypoint_1();
extern void _bsdronegoto_entrypoint_2();
extern void _bsdronegoto_entrypoint_3();
extern void _bsdronelook_entrypoint_1();
extern void _bsdronelook_entrypoint_3();
extern void _bsdronelook_entrypoint_0();
extern void _bsdronelook_entrypoint_4();
extern void _bsdronesuckunder_entrypoint_1();
extern void _bsdronesuckunder_entrypoint_3();
extern void _bsdronesuckunder_entrypoint_0();
extern void _bsdronesuckunder_entrypoint_2();
extern void _bsdronexform_entrypoint_2();
extern void _bsdronexform_entrypoint_3();
extern void _bsdronexform_entrypoint_1();
extern void func_80099AA8();
extern void _bsdronevanish_entrypoint_0();
extern void _bsdronevanish_entrypoint_1();
extern void _bsdronevanish_entrypoint_2();
extern void _bsdronebitten_entrypoint_1();
extern void _bsdronebitten_entrypoint_3();
extern void _bsdronebitten_entrypoint_0();
extern void _bsdronebitten_entrypoint_7();
extern void _bsdronebitten_entrypoint_9();
extern void _bsdronebitten_entrypoint_6();
extern void _bsdronebitten_entrypoint_8();
extern void _bsdroneslide_entrypoint_0();
extern void _bsdroneslide_entrypoint_1();
extern void _bsdroneslide_entrypoint_2();
extern void func_80099B94();
extern void _bsdronejump_entrypoint_2();
extern void _bsdronejump_entrypoint_4();
extern void _bsdronejump_entrypoint_1();
extern void _bsdronejump_entrypoint_3();
extern void _bsdronefired_entrypoint_1();
extern void _bsdronefired_entrypoint_3();
extern void _bsdronefired_entrypoint_0();
extern void _bsdronefired_entrypoint_2();
extern void _bsdronebubbled_entrypoint_1();
extern void _bsdronebubbled_entrypoint_3();
extern void _bsdronebubbled_entrypoint_0();
extern void _bsdronebubbled_entrypoint_2();
extern void _bsdronebubbled_entrypoint_5();
extern void _bsdronebubbled_entrypoint_7();
extern void _bsdronebubbled_entrypoint_4();
extern void _bsdronebubbled_entrypoint_6();
extern void _bsdronewaitbabykaz_entrypoint_1();
extern void _bsdronewaitbabykaz_entrypoint_3();
extern void _bsdronewaitbabykaz_entrypoint_0();
extern void _bsdronewaitbabykaz_entrypoint_2();
extern void _bsdronefalldie_entrypoint_1();
extern void _bsdronefalldie_entrypoint_3();
extern void _bsdronefalldie_entrypoint_0();
extern void _bsdronefalldie_entrypoint_2();
DroneEnt D_80800180_bsdrone[16] = { 0x1, 0x0, 0x0, 0x0, (void *)_bsdronegoto_entrypoint_0, (void *)_bsdronegoto_entrypoint_1, (void *)_bsdronegoto_entrypoint_2, (void *)_bsdronegoto_entrypoint_3, 0x2, 0x0, 0x0, 0x0, (void *)_bsdronelook_entrypoint_1, (void *)_bsdronelook_entrypoint_3, (void *)_bsdronelook_entrypoint_0, (void *)_bsdronelook_entrypoint_4, 0x3, 0x0, 0x0, 0x0, (void *)_bsdronesuckunder_entrypoint_1, (void *)_bsdronesuckunder_entrypoint_3, (void *)_bsdronesuckunder_entrypoint_0, (void *)_bsdronesuckunder_entrypoint_2, 0x4, 0x0, 0x0, 0x0, (void *)_bsdronexform_entrypoint_2, (void *)_bsdronexform_entrypoint_3, (void *)_bsdronexform_entrypoint_1, (void *)func_80099AA8, 0x5, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0x6, 0x0, 0x0, 0x0, (void *)_bsdronevanish_entrypoint_0, (void *)_bsdronevanish_entrypoint_1, (void *)_bsdronevanish_entrypoint_2, (void *)func_80099AA8, 0x7, 0x0, 0x0, 0x0, (void *)_bsdronebitten_entrypoint_1, (void *)_bsdronebitten_entrypoint_3, (void *)_bsdronebitten_entrypoint_0, (void *)func_80099AA8, 0x8, 0x0, 0x0, 0x0, (void *)_bsdronebitten_entrypoint_7, (void *)_bsdronebitten_entrypoint_9, (void *)_bsdronebitten_entrypoint_6, (void *)_bsdronebitten_entrypoint_8, 0x9, 0x0, 0x0, 0x0, (void *)_bsdroneslide_entrypoint_0, (void *)_bsdroneslide_entrypoint_1, (void *)_bsdroneslide_entrypoint_2, (void *)func_80099B94, 0xA, 0x0, 0x0, 0x0, (void *)_bsdronejump_entrypoint_2, (void *)_bsdronejump_entrypoint_4, (void *)_bsdronejump_entrypoint_1, (void *)_bsdronejump_entrypoint_3, 0xB, 0x0, 0x0, 0x0, (void *)_bsdronefired_entrypoint_1, (void *)_bsdronefired_entrypoint_3, (void *)_bsdronefired_entrypoint_0, (void *)_bsdronefired_entrypoint_2, 0xC, 0x0, 0x0, 0x0, (void *)_bsdronebubbled_entrypoint_1, (void *)_bsdronebubbled_entrypoint_3, (void *)_bsdronebubbled_entrypoint_0, (void *)_bsdronebubbled_entrypoint_2, 0xD, 0x0, 0x0, 0x0, (void *)_bsdronebubbled_entrypoint_5, (void *)_bsdronebubbled_entrypoint_7, (void *)_bsdronebubbled_entrypoint_4, (void *)_bsdronebubbled_entrypoint_6, 0xE, 0x0, 0x0, 0x0, (void *)_bsdronewaitbabykaz_entrypoint_1, (void *)_bsdronewaitbabykaz_entrypoint_3, (void *)_bsdronewaitbabykaz_entrypoint_0, (void *)_bsdronewaitbabykaz_entrypoint_2, 0xF, 0x0, 0x0, 0x0, (void *)_bsdronefalldie_entrypoint_1, (void *)_bsdronefalldie_entrypoint_3, (void *)_bsdronefalldie_entrypoint_0, (void *)_bsdronefalldie_entrypoint_2, 0x0, 0x0, 0x0, 0x0, 0, 0, 0, 0 };
