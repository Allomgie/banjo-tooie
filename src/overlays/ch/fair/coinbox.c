// Probably the Witchyworld coin box: a talking money slot the Van pays with coins. It shows
// dialogs, then sets its flag and powers an attraction by messaging another actor.
#include "common.h"

typedef struct {
    u8 pad[0x76];
    u16 f76 : 9;
    u16 pad76 : 7;
} CoinBoxState;
extern s16 func_80800424_chfaircoinbox[];
extern void func_800DA544(s32);
extern s32 func_808002E4_chfaircoinbox[];
typedef struct {
    s32 a;
    s32 b;
} CoinEnt;
extern CoinEnt D_80800470_chfaircoinbox[];
extern s32 func_800DA298(s32);
extern s32 func_8008FB10(f32 *, f32, f32, f32);
extern u16 D_80800490_chfaircoinbox[];
extern s16 D_80800494_chfaircoinbox;
extern s32 func_808003E4_chfaircoinbox[];
typedef union {
    s32 local_0;
    s16 local_1[2];
} CoinboxMessage;
extern s32 D_808004B8_chfaircoinbox[];
extern int D_808004C8_chfaircoinbox[];
void func_808002CC_chfaircoinbox();

s16 func_80800000_chfaircoinbox(param_0)
CoinBoxState *param_0;
{
    return func_80800424_chfaircoinbox[param_0->f76];
}

void func_8080001C_chfaircoinbox(u8 *param_0)
{
    func_800DA544(*(s32 *) ((char *) func_808002E4_chfaircoinbox +
                            ((u32) ((u16) *(u16 *) (param_0 + 0x76)) >> 7) * 8));
}

s32 func_80800050_chfaircoinbox(CoinBoxState *param_0)
{
    s32 local_1 = param_0->f76 - 0x32;

if (func_800DA298(D_80800470_chfaircoinbox[local_1].b)) {
    func_800DA544(D_80800470_chfaircoinbox[local_1].a);
}

return D_80800470_chfaircoinbox[local_1].a;
}

void func_808000A4_chfaircoinbox(Actor *param_0, s32 param_1)
{
    func_80101FDC(param_0, param_1);

switch (param_0->unk70_10) {
    case 2:
        func_800904F4(0x46, param_0->unk0);
        break;
    case 3:
        func_800C01A8(100, 0);
        func_8080001C_chfaircoinbox(param_0);
        func_80090708(0);
        func_800FC660(0x10);
        switch (param_0->unk74_7 - 0x32) {
            case 0:
                func_80101180(0x340, 10, 0);
                break;
            case 1:
                func_80101180(0x307, 10, 0);
        }
}

}

void func_8080016C_chfaircoinbox(s32 arg0)
{
}
int func_80800174_chfaircoinbox(s32 param_0)
{
    func_8010A63C();

if (func_800DA298(func_80800050_chfaircoinbox(param_0)) != 0) {
    func_808000A4_chfaircoinbox(param_0, 4);
    return;
}

func_808000A4_chfaircoinbox(param_0, 1);
}

void func_808001C8_chfaircoinbox(Actor *param_0)
{
    func_8008FB10(param_0->position, 120.0f, 0.0f, 92.0f);

switch (param_0->unk70_10) {
    case 1:
        if (func_800DA298(func_80800050_chfaircoinbox(param_0))) {
            func_808000A4_chfaircoinbox(param_0, 3);
            break;
        }
        func_808002CC_chfaircoinbox(param_0);
    case 2:
    case 3:
    case 4:
        break;
}

}

void func_80800264_chfaircoinbox(param_0, param_1, param_2) Actor *param_0;
s32 param_1;
s32 param_2;
{
    switch (param_1) {
        case 0x10B4:
            func_80090708(0);
            break;
        case 0x10B5:
        case 0x10B6:
        case 0x10B7:
            func_808000A4_chfaircoinbox(param_0, 2);
            break;
        case 0x10B8:
            func_808000A4_chfaircoinbox(param_0, 3);
    }

}

void func_808002CC_chfaircoinbox(param_0) Actor *param_0;
{
    s32 dialog_id;

    D_80800494_chfaircoinbox = func_808003E4_chfaircoinbox[param_0->unk74_7];
    dialog_id = func_80800000_chfaircoinbox();
    D_80800490_chfaircoinbox[0] = dialog_id;

if (func_800DA298((u16) dialog_id)) {
    return;
}

// Matching: `^ 0` makes the first argument a new value so param_0 stays in its own register for a3.
dialog_id = _subaddiedialog_entrypoint_7((Actor *) ((s32) param_0 ^ 0), param_0->position,
                                       D_80800490_chfaircoinbox, param_0);

if (dialog_id != 0) {
    // Matching: empty else-if chain keeps the beq test for 0x10B5 (probably removed debug code).
    if (dialog_id == 0x10B5) {
    } else if (dialog_id == 0x10B6) {
    } else if (dialog_id == 0x10B7) {
    } else if (dialog_id == 0x10B4) {
    }
    func_80090734(1, param_0->position);
}

}

s32 chfaircoinbox_entrypoint_0(s32 param_0, s32 param_1)
{
    func_800EE7F8(param_1, func_80106790(param_0) + 4);
    return 1;
}

void chfaircoinbox_entrypoint_1()
{
    s32 *temp_v0;
    temp_v0 = func_80106790();
    _subaddiedialog_entrypoint_11(*temp_v0, 0x10B8, 4, temp_v0 + 1, 0x8C);

}

s32 func_808003C4_chfaircoinbox(Actor *param_0, s32 param_1, CoinboxMessage param_2)
{
    switch (param_1) {
        case 0x2E:
            func_80800264_chfaircoinbox(param_0, param_2.local_1[0], param_2.local_1[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_808004B8_chfaircoinbox,
                                         *(void **) ((u8 *) param_0 + 0x38));
            break;
        default:
            return 0;
    }

return 1;
}

int chfaircoinbox_entrypoint_2(void)
{
    return (int) &D_808004C8_chfaircoinbox;
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file and
// IDO's assembler schedules them differently otherwise. Values are taken from the ROM.
extern void func_80101870();
extern void func_80107C2C();
CoinEnt D_80800470_chfaircoinbox[4] = {0x695, 0xA4, 0x696, 0xA5, 0x697, 0xA6, 0x9E309E4, 0x9E50000};
u16 D_80800490_chfaircoinbox[2] = {0x0, 0x12C};
s16 D_80800494_chfaircoinbox = 0x0;
static u32 D_80800494_chfaircoinbox_rest[8] = {0x8000, 0x10B409E1, 0x8C0000, 0x60732,
                                               0x0,    0x10B5,     0x10B6,   0x10B7};
s32 D_808004B8_chfaircoinbox[4] = {0x42200000, 0x42480000, 0x42200000, 0x0};
int D_808004C8_chfaircoinbox[18] = {0x2770165,
                                    0x7D30001,
                                    0x0,
                                    (u32) func_808001C8_chfaircoinbox,
                                    0x0,
                                    (u32) func_80101870,
                                    0x2580000,
                                    0x0,
                                    0x0,
                                    0x40000000,
                                    (u32) func_8080016C_chfaircoinbox,
                                    0x0,
                                    0x0,
                                    (u32) func_80800174_chfaircoinbox,
                                    (u32) func_80107C2C,
                                    -0x7FF7FBEE,
                                    (u32) func_808003C4_chfaircoinbox,
                                    0x0};
