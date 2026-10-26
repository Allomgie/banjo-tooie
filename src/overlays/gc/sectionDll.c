#include "common.h"

extern u8 D_8012762C;
typedef struct { s16 local_0, local_1, local_2; } SectionRecord;
extern SectionRecord D_80800210_gcsectionDll[];
typedef struct { s16 unk0; s16 pad2[2]; } SectionFlagsRecord;
extern SectionFlagsRecord D_80800212_gcsectionDll[];
int gcsectionDll_entrypoint_2();
s32 gcsectionDll_entrypoint_3();

void gcsectionDll_entrypoint_0(s32 param_0, s32 param_1) {
    s32 local_0;

    local_0 = _gclevel_entrypoint_2();
    if ((local_0 >= 0xF) && (local_0 < 0x20)) {
        if (gcsectionDll_entrypoint_3(gcsectionDll_entrypoint_2(param_0), 0x20) != 0) {
            func_8001A578(_gcstatusDll_entrypoint_11());
        } else if (param_0 == 0x189) {
            func_8001A578(0);
        }
        func_800F9178();
        func_800A13B0(param_0);
    }
}

void gcsectionDll_entrypoint_1(s32 param_0)
{
    s32 local_0 = D_8012762C;

    if (param_0) {
        func_800D389C();
        _glglobalsettings_entrypoint_2();
    }
    if (local_0 > 0 && local_0 < 0x20) {
        func_8001A63C();
    }
    func_80018634();
    func_800C0A2C();
}

SectionRecord *func_808000F0_gcsectionDll(s32 param_0, s32 param_1)
{
    s32 local_1;

    SectionRecord *p;
    for (p = &D_80800210_gcsectionDll[1]; p->local_0 != 0; p++) {
        if (p->local_0 == param_0) {
            return p;
        }
    }
    if (param_1 != 0) {
        return NULL;
    }
    return NULL;
}

int gcsectionDll_entrypoint_2(param_0) s32 param_0;
{
    s32 local_0;
    local_0 = (s32)func_808000F0_gcsectionDll(param_0, 0) - (s32)&((u8 *) D_80800210_gcsectionDll)[0];
    return local_0 / 6;
}

s32 gcsectionDll_entrypoint_3(param_0, param_1) s32 param_0; u32 param_1;
{
    return (D_80800212_gcsectionDll[param_0].unk0 & param_1) ? 1 : 0;
}

int gcsectionDll_entrypoint_4(s32 param_0)
{
  u8 *local_0 = func_808000F0_gcsectionDll(param_0, 0);
  return ((u8*)local_0)[4];
}

s32 gcsectionDll_entrypoint_5(s32 param_0) {
    if (func_808000F0_gcsectionDll(param_0, 1)) {
        return 1;
    }
    return 0;
}
