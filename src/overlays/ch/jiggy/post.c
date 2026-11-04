#include "ch/jiggypost.h"

extern void *D_80800380_chjiggypost;
extern void *D_808003C8_chjiggypost;

void *chjiggypost_entrypoint_0(void)
{
    return &D_80800380_chjiggypost;
}

void func_8080000C_chjiggypost(s32 arg0)
{
}

// Starts Jiggywiggy dialog (speaker 0x97).
void func_80800014_chjiggypost(Actor *actor, s32 text_id)
{
    u8 unk_0;

    if (text_id == 0x1515) {
        unk_0 = 0x4E;
    } else {
        unk_0 = 0xF;
    }
    _subaddiedialog_entrypoint_11(actor->unk0, text_id, unk_0, actor->position, 0x97);
    func_80101FDC(actor, 2);
}

// Shows the HUD jiggy counts and starts the requirement dialog when the player is near.
void func_80800068_chjiggypost(Actor *actor)
{
    s32 text_id;
    s32 missing;
    s32 required;

    if (!func_800C0638()) {
        func_800D2498(0x10E, func_800D035C(1), 0);
        if ((s32) (actor->unk74_7 - 0x33) >= _sujiggy_entrypoint_0()) {
            required = _sujiggy_entrypoint_2(actor->unk74_7 - 0x33);
            missing = required - func_800D035C(1);
            if (missing > 0)
                func_800D2498(0x106, missing, 0);
        }
    }
    if (actor->unk70_10 == 1) {
        if (!func_800DA298(0x4E8)) {
            func_80800014_chjiggypost(actor, 0x1512);
            return;
        }
        if (_subaddiedialog_entrypoint_5(actor->position, 250, 60, 0)) {
            if ((s32) (actor->unk74_7 - 0x33) < _sujiggy_entrypoint_0())
                text_id = 0x1517;
            else if (func_800D3E40(11))
                text_id = 0x155A;
            else
                text_id = _sujiggy_entrypoint_2(actor->unk74_7 - 0x33) == 1 ? 0x1513 : 0x1514;
            func_80800014_chjiggypost(actor, text_id);
        }
    }
}

void func_808001C4_chjiggypost(Actor *actor, s32 text_id, s32 response)
{
    s32 next_text;

    switch (text_id) {
        case 0x1513:
        case 0x1514:
            if (func_800DA298(FLAG_35B_FTT_CS_JIGGYWIGGY) != 0) {
                if (func_800D035C(1) >= _sujiggy_entrypoint_2(actor->unk74_7 - 0x33)) {
                    if (func_8008FD48() == TRANSFORM_1_BK) {
                        next_text = 0x1515;
                    } else {
                        next_text = 0x152E;
                    }
                } else {
                    next_text = 0x1516;
                }
                func_80800014_chjiggypost(actor, next_text);
            } else {
                func_800C0850();
                func_800C01A8(0x64, 0);
                func_80101FDC(actor, 1U);
            }
            break;

        case 0x1512:
            func_800DA544(FLAG_4E8_FTT_ALTAR_OF_KNOWLEDGE);
        default:
            func_80101FDC(actor, 1U);
    }
    if ((text_id == 0x1515) && (response == 1)) {
        _gcgoto_entrypoint_1(MAP_151_IOH_JIGGYWIGGY_TEMPLE, 4);
    }
}

s32 func_808002DC_chjiggypost(Actor *actor, s32 msg, s32 data)
{
    splitS32 *split = (splitS32 *) &data;
    switch (msg) {
        case 0x2E:
            func_808001C4_chjiggypost(actor, split->upper, split->lower);
        case 0x95:
            break;
        case 0x30:
            return _sujiggy_entrypoint_2(actor->unk74_7 - 0x33);
        case 0x52:
            _gcdialogcamera_entrypoint_3((u32 *) &D_808003C8_chjiggypost, actor->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
void *D_80800380_chjiggypost = (void *) 0x015804AF;
static u32 D_80800380_chjiggypost_rest[17] = {0x9770001,
                                              0x0,
                                              (u32) func_80800068_chjiggypost,
                                              (u32) func_80102EC0,
                                              (u32) func_80101870,
                                              0xFA0000,
                                              0x0,
                                              0x0,
                                              0x40000800,
                                              0x0,
                                              0x0,
                                              0x0,
                                              (u32) func_8080000C_chjiggypost,
                                              (u32) func_80107C2C,
                                              0x80082452,
                                              (u32) func_808002DC_chjiggypost,
                                              0x0};
void *D_808003C8_chjiggypost = (void *) 0x43820000;
static u32 D_808003C8_chjiggypost_rest[5] = {0x432F0000, 0x432F0000, 0x42960000, 0x0, 0x0};
