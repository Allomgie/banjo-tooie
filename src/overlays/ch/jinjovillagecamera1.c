// Controller of the Jinjo family return cutscene: in Jinjo Village it frames the family's house,
// inside a family house it plays the thank-you dialog and spawns the returning Jinjos.
#include "common.h"

extern u8 D_80800470_chjinjovillagecamera1[];
extern u8 D_8080047C_chjinjovillagecamera1[];
extern u8 D_80800488_chjinjovillagecamera1[];
extern int D_80800494_chjinjovillagecamera1[];

// Dialog callback: ends the cutscene or switches the camera pod state.
void func_80800000_chjinjovillagecamera1(Actor *actor, s32 msg, s32 data)
{
    switch (msg) {
        case 0x1522:
            _glcutDll_entrypoint_17();
            return;
        case 0x1523:
        case 0x1524:
        case 0x1565:
            func_80101FDC(actor, 2);
            actor->unk58 = 1.5f;
    }
}

// Message 0xB: start cutscene. 0x49: play thank-you dialog. 0x2E: forward to the dialog handler above.
int func_80800078_chjinjovillagecamera1(Actor *actor, s32 msg, s32 data)
{
    s32 family;
    s32 unk_1;
    s32 family_id;
    s32 returned;
    s32 dialog_id;
    s32 total;
    switch (msg) {
        case 0xB:
            family = func_800DA564(0x6D0, 4);
            if (func_800EA05C() == 0x142) {
                unk_1 = _chjinjo_entrypoint_3(family);
                _glcutDll_entrypoint_24(unk_1, _glcutDll_entrypoint_9(), 0x84);
                return 3;
            }
            if (data == D_8080047C_chjinjovillagecamera1[family])
                func_800DA544(0x39E);
            return 3;
        case 0x49:
            family_id = func_800DA564(0x6D0, 4);
            if (!_glcutDll_entrypoint_19(0x84))
                return 0;
            if (func_800EA05C() == 0x142)
                _capod_entrypoint_13(actor->unk0, 0, D_80800470_chjinjovillagecamera1[family_id],
                                     0x810);
            else {
                _capod_entrypoint_13(actor->unk0, 0, D_8080047C_chjinjovillagecamera1[family_id],
                                     0x2830);
                if (!func_800DA9E4(0x43C, 1)) {
                    total = func_800D1338(family_id);
                    returned = func_800D129C(family_id);
                    if (returned == total) {
                        func_800DA544(0x43D);
                        _subaddiedialog_entrypoint_11(actor->unk0, 0x1524, 4, 0,
                                                      _chjinjo_entrypoint_0(family_id));
                    } else
                        _subaddiedialog_entrypoint_11(actor->unk0, 0x1522, 4, 0,
                                                      _chjinjo_entrypoint_0(family_id));
                } else if (!func_800DA9E4(0x43D, 1)) {
                    dialog_id = family_id == 0 ? 0x1565 : 0x1523;
                    _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, 4, 0,
                                                  _chjinjo_entrypoint_0(family_id));
                }
            }
            break;
        case 0x2E:
            func_80800000_chjinjovillagecamera1(actor, ((s16 *) &data)[0],
                                                ((s16 *) &data)[1]);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808002BC_chjinjovillagecamera1(unused) s32 unused;
{
    s32 family;
    family = _chjinjo_entrypoint_2(-1);
    if (family != -1) {
        func_800BF744(9, 0);
        func_800BF744(D_80800488_chjinjovillagecamera1[family], 1);
    }
}

int func_80800310_chjinjovillagecamera1()
{
    s32 family;
    s32 total;
    s32 returned;
    s32 all_returned;

    func_808002BC_chjinjovillagecamera1();
    if (func_800EA05C() != 0x142) {
        family = _chjinjo_entrypoint_2(-1);
        total = func_800D1338(family);
        returned = func_800D129C(family);
        all_returned = total == returned;
        if (_glcutDll_entrypoint_19(0x84) != 0) {
            if ((all_returned == 0) || (returned == 1)) {
                func_80101180(0x48F, 0x7E, 0);
            }
        } else if (all_returned != 0) {
            func_800FDC28(0x12);
        }
    }
}

// Frames the family house with a camera pod and ends the cutscene.
void func_808003C0_chjinjovillagecamera1(u8 *actor)
{
    u32 state;
    state = (u16) *(u16 *) ((s8 *) actor + 0x72);
    state = state >> 0xA;
    switch (state) {
        case 2:
            if (func_800D9078(actor + 0x58) != 0) {
                _chjinjo_entrypoint_1(_chjinjo_entrypoint_2(-1), 0);
                func_80101FDC(actor, 3);
                *(f32 *) ((s8 *) actor + 0x58) = 2.5f;
            }
            return;

        case 3:
            if (func_800D9078(actor + 0x58) != 0) {
                _glcutDll_entrypoint_17();
            }
    }
}

int chjinjovillagecamera1_entrypoint_0()
{
    return (int) &D_80800494_chjinjovillagecamera1;
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
u8 D_80800470_chjinjovillagecamera1[12] = {0x10, 0x18, 0x0,  0x16, 0xD, 0x6,
                                           0x3,  0xA,  0x13, 0x0,  0x0, 0x0};
u8 D_8080047C_chjinjovillagecamera1[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                                           0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
u8 D_80800488_chjinjovillagecamera1[12] = {0x4, 0x5, 0x1, 0x9, 0x6, 0x8,
                                           0x3, 0x7, 0x2, 0x0, 0x0, 0x0};
int D_80800494_chjinjovillagecamera1[19] = {0x158048E,
                                            0x1,
                                            0x0,
                                            (u32) func_808003C0_chjinjovillagecamera1,
                                            (u32) func_80105834,
                                            (u32) func_8010A730,
                                            0x0,
                                            0x0,
                                            0x0,
                                            0x80404,
                                            0x0,
                                            0x0,
                                            0x0,
                                            (u32) func_80800310_chjinjovillagecamera1,
                                            (u32) func_80107C2C,
                                            -0x7FFFDFFE,
                                            (u32) func_80800078_chjinjovillagecamera1,
                                            0x0,
                                            0x0};
