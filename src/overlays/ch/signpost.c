// Hint signposts: the first read shows a tutorial text; later, facing a sign and pressing talk
// shows its hint text (some texts are replaced unless cheat 6 is active).
#include "common.h"

extern void *D_808002E0_chsignpost;
typedef struct {
    u8 pad_0[0x28];
    s32 unk_28;
    u8 pad_2C[0xC];
    f32 unk_38;
    u8 pad_3C[0x3A];
    u16 variant : 9;
    u16 pad_76 : 7;
} SignState;
extern void func_80102FDC(SignState *, f32);
extern s32 func_8010CD88(Actor *, f32, f32);
typedef union {
    s32 word;
    s16 half[2];
} SignpostMessage1482;
extern u8 D_80800328_chsignpost[];
extern void func_80800264_chsignpost(s32, s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
void func_80800230_chsignpost();
// Shows hint text 0x1686 + index; texts 0x16B7-0x16BE become 0x16BF unless cheat 6 is active.
int func_80800274_chsignpost();

int chsignpost_entrypoint_0()
{
    return &D_808002E0_chsignpost;
}

void func_8080000C_chsignpost(SignState *actor)
{
    func_80102FDC(actor, actor->unk_38 * 0.75f);
    actor->unk_28 = actor->variant - 0x32;
}

// First read of any sign plays tutorial text 0x16C2; afterwards facing a sign and pressing talk shows its hint.
void func_80800058_chsignpost(Actor *actor)
{
    s32 unk_0;
    s32 state;

    state = actor->unk70_10;
    switch (state) {
        case 1:
            if (!func_800DA298(0x3A)) {
                if (func_8010CAC0(actor->position, 0x15E) &&
                    func_8010CD88(actor, 360.0f, 70.0f) &&
                    func_800F4B8C(func_800F54E4(), -1, 0)) {
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x16C2, 0xE, actor->position,
                                                  0x28);
                    func_80101FDC(actor, 2);
                    func_800DA544(0x3A);
                }
            } else {
                unk_0 = (*(u32 *) ((u8 *) actor + 0x70) & 1) ? 4 : 0;
                if (_subaddiedialog_entrypoint_6(
                        actor->position, (s32) actor->rotation[1],
                        (*(u32 *) ((u8 *) actor + 0x70) & 1) ? 0x15E : 0xFA, 70, unk_0)) {
                    actor->unk70_10 = 2;
                    func_80800274_chsignpost(actor);
                }
            }
        case 2:
            break;
    }
}

s32 func_8080019C_chsignpost(Actor *actor, s32 msg, SignpostMessage1482 payload)
{
    switch (msg) {
        case 0x2E:
            func_80800230_chsignpost(actor, payload.half[0], payload.half[1]);
            break;
        case 0x2F:
            func_80800264_chsignpost((s32) actor, payload.half[0], payload.half[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800328_chsignpost, actor->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800230_chsignpost(actor, unk_1, unk_2) u8 *actor;
s32 unk_1;
s32 unk_2;
{
    {
        if ((((u16) *(u16 *) ((u8 *) actor + 0x72) & 0xFFFFFFFF) >> 10) == 2) {
            *(u8 *) ((u8 *) actor + 0x72) = (*(u8 *) ((u8 *) actor + 0x72) & 0xFF03) | 4;
        }
    }
}

void func_80800264_chsignpost(s32 actor, s32 unk_1, s32 unk_2)
{
}

int func_80800274_chsignpost(actor) volatile s32 actor[3];
{
    s32 unk_0;
    s32 text_id;

    text_id = actor[10] + 0x1686;
    if ((text_id >= 0x16B7) && (text_id < 0x16BF)) {
        if (func_800D3E40(6, text_id) == 0) {
            text_id = 0x16BF;
        }
    }
    _subaddiedialog_entrypoint_11(actor[0], text_id, 0xF, &actor[1], 0x28);
    return 1;
}

extern void func_80101870();
extern void func_80107C2C();
// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to functions of
// this file; IDO's assembler schedules some of them differently unless the tables are in the same
// unit.
void *D_808002E0_chsignpost =(void *) 0x022D0198;
static u32 D_808002E0_chsignpost_rest[17] = {0x7A20001,
                                             0x0,
                                             (u32) func_80800058_chsignpost,
                                             0x0,
                                             (u32) func_80101870,
                                             0x1C20000,
                                             0x3FC00000,
                                             0x0,
                                             0x40000800,
                                             0x0,
                                             0x0,
                                             0x0,
                                             (u32) func_8080000C_chsignpost,
                                             (u32) func_80107C2C,
                                             0x82082452,
                                             (u32) func_8080019C_chsignpost,
                                             0x0};
u8 D_80800328_chsignpost[24] = {0x43, 0x82, 0x0, 0x0, 0x43, 0x2F, 0x0, 0x0, 0x43, 0x2F, 0x0, 0x0,
                                0x42, 0x96, 0x0, 0x0, 0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0, 0x0};
