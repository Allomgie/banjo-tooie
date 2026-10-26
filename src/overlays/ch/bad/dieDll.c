#include "common.h"

typedef struct { void *func; s32 arg[6]; s32 argc; } BaddieQueuedCall;
typedef struct { BaddieQueuedCall *calls; u8 count; } BaddieCallQueue;

void chbaddieDll_entrypoint_0(s32 param_0)
{
    *(u8 *)(param_0 + 4) = 0;
    *(u8 *)(param_0 + 5) = 1;
}

void chbaddieDll_entrypoint_1(u8 *param_0) {
    (*(s8 *)((s8 *)(param_0) + (4))) = 0;
    func_800CB9B4();
    func_800BDD00();
    func_800FF390();
    if (func_8001E204() == 0) {
        func_800BDCB8();
        _suautobaddies_entrypoint_0();
    }
}

void chbaddieDll_entrypoint_2(u8 *param_0) {
    func_800FF564();
    func_800CB9D8();
    heap_free((*(s32 *)((s8 *)(param_0) + (0))));
    (*(s32 *)((s8 *)(param_0) + (0))) = 0;
    (*(s8 *)((s8 *)(param_0) + (4))) = 0;
}

void chbaddieDll_entrypoint_3(BaddieCallQueue *param_0)
{
    s32 i;

    for (i = 0; i < param_0->count; i++) {
        switch (param_0->calls[i].argc) {
        case 0:
            ((void (*)(void))param_0->calls[i].func)();
            break;
        case 1:
            ((void (*)(s32))param_0->calls[i].func)(param_0->calls[i].arg[0]);
            break;
        case 2:
            ((void (*)(s32, s32))param_0->calls[i].func)(param_0->calls[i].arg[0], param_0->calls[i].arg[1]);
            break;
        case 3:
            ((void (*)(s32, s32, s32))param_0->calls[i].func)(param_0->calls[i].arg[0], param_0->calls[i].arg[1], param_0->calls[i].arg[2]);
            break;
        case 4:
            ((void (*)(s32, s32, s32, s32))param_0->calls[i].func)(param_0->calls[i].arg[0], param_0->calls[i].arg[1], param_0->calls[i].arg[2], param_0->calls[i].arg[3]);
            break;
        case 5:
            ((void (*)(s32, s32, s32, s32, s32))param_0->calls[i].func)(param_0->calls[i].arg[0], param_0->calls[i].arg[1], param_0->calls[i].arg[2], param_0->calls[i].arg[3], param_0->calls[i].arg[4]);
            break;
        case 6:
            ((void (*)(s32, s32, s32, s32, s32, s32))param_0->calls[i].func)(param_0->calls[i].arg[0], param_0->calls[i].arg[1], param_0->calls[i].arg[2], param_0->calls[i].arg[3], param_0->calls[i].arg[4], param_0->calls[i].arg[5]);
            break;
        default:
            break;
        }
    }
    param_0->count = 0;
}
