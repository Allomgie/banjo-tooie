#include "common.h"

extern u8 D_80800250_chdinoroargrill[];
extern int D_80800258_chdinoroargrill[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);

void func_80800000_chdinoroargrill(u8 *grill)
{
    *(f32 *) ((char *) grill + 0x28) = 0.0f;
    func_8010A800(grill, 0);
}

// Opens the grill once the roar sequence is complete (actorData[4] is the table index).
void func_80800028_chdinoroargrill(Actor *grill)
{
    if (!D_80800250_chdinoroargrill[(s32) *(f32 *) &grill->actorData[4]]) {
        if (!func_80102F44(grill)) {
            func_80101FDC(grill, 3);
            grill->unk58 = 1.9f;
            _capod_entrypoint_13(grill->unk0, grill->unk0, 0x4C, 0x810);
            if (_chdoormake_entrypoint_3(grill, 0.0f, 90.0f, grill->scale * 170.0f, 0, -1)) {
                _chdoormake_entrypoint_8(grill, 14);
            }
        }
        _chdoor_entrypoint_0(grill);
    } else if (func_8010C710(grill) >= 0xC5C11) {
        *(f32 *) &grill->actorData[4] = 0.0f;
    }
}

// Roar sequence: msgs 0x1D/0x1E must match the table in order; a wrong one resets it.
s32 func_80800124_chdinoroargrill(Actor *grill, s32 msg, s32 msg_arg)
{
    switch (msg) {
        case 0xB:
            if (msg_arg == 0x4C) {
                func_800DA544(0xA22);
                func_800FFAB0(grill);
            }
            return 3;
        case 0x1D:
        case 0x1E:
            if (D_80800250_chdinoroargrill[(s32) *(f32 *) &grill->actorData[4]]) {
                if (msg == D_80800250_chdinoroargrill[(s32) *(f32 *) &grill->actorData[4]]) {
                    *(f32 *) &grill->actorData[4] += 1.0f;
                    if (!D_80800250_chdinoroargrill[(s32) *(f32 *) &grill->actorData[4]]) {
                        func_800FC63C(0x10, -1);
                    }
                } else {
                    *(f32 *) &grill->actorData[4] = 0.0f;
                }
            }
            return 1;
        case 0x95:
            grill->unk79_2 = 0;
            return 1;
    }
    return 0;
}

int *chdinoroargrill_entrypoint_0()
{
    return &D_80800258_chdinoroargrill;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u8 D_80800250_chdinoroargrill[8] = {0x1D, 0x1D, 0x1E, 0x1D, 0x1E, 0x1E, 0x0, 0x0};
int D_80800258_chdinoroargrill[18] = {0xAC04A2,
                                      0x7C40001,
                                      0x0,
                                      (u32) func_80800028_chdinoroargrill,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0xA220000,
                                      0x40000800,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800000_chdinoroargrill,
                                      (u32) func_80107C2C,
                                      -0x7FFFDBEE,
                                      (u32) func_80800124_chdinoroargrill,
                                      0x0};
