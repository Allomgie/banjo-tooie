#include "common.h"

extern Actor *func_80106790(Unk80132ED0 *);
extern s16 *func_80100368(Actor *);
void sueggmisc_entrypoint_2();

s32 sueggmisc_entrypoint_0(Unk80132ED0 *param_0)
{
    s32 local_0;

    if (!(*(u16 *)&param_0->unk18 & 1)) {
        return 0;
    }
    local_0 = param_0->unk24 >> 22;
    switch (local_0) {
    case 0x16D:
    case 0x26C:
    case 0x26D:
    case 0x26E:
        return 1;
    case 0x26F:
    case 0x270:
        return (param_0->unk24 >> 22) == *func_80100368(func_80106790(param_0));
    }
    return 0;
}

void sueggmisc_entrypoint_1(u8 *param_0) {
    s32 local_0;
    s32 local_2;
    s32 local_1;

    local_2 = _gcegg_entrypoint_1((u32) (*(s32*)((char*)param_0 + 0x6C) << 0xB) >> 0x14);
    local_0 = local_2;
    sueggmisc_entrypoint_2(param_0 + 4, local_2);
    local_1 = func_800F54E4();
    func_800F7664(local_1, _gcegg_entrypoint_5(local_0), 1);
    func_800FFAB0(param_0);
}

void sueggmisc_entrypoint_2(param_0, param_1) s32 param_0; s32 param_1;
{
    _fxsparkle_entrypoint_1(param_0, _gcegg_entrypoint_4(param_1));
    func_800FC660(_gcegg_entrypoint_3(param_1));
}

s32 sueggmisc_entrypoint_3(void){
    func_800DA544(0xA31);
}
