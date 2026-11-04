// The three Mayahem Temple kickball stadium doors (index 0x33-0x35).
// Each opens once its round is unlocked (flags 0x576, 0x5E, 0x5F) and unlocks replay
// entries 0x60-0x62.
#include "common.h"

typedef struct StadiumDoorState {
    u8 pad_0[0x72];
    u8 unk_72 : 6;
    u8 pad_1 : 2;
} StadiumDoorState;
extern s32 D_80800270_chstadiumdoors[];
extern int D_80800280_chstadiumdoors[];

// Opens each door once Stony has unlocked its round and unlocks the matching replay entry.
void func_80800000_chstadiumdoors(Actor *door)
{
    switch (door->unk74_7) {
        case 0x33:
            if (func_800DA298(0x576)) {
                ((StadiumDoorState *) door)->unk_72 = 3;
                door->rotation[1] = -85.0f;
                _gcfrontend_entrypoint_9(0x60);
            }
            break;
        case 0x34:
            if (func_800DA298(0x5E)) {
                ((StadiumDoorState *) door)->unk_72 = 3;
                door->rotation[1] = -85.0f;
                _gcfrontend_entrypoint_9(0x61);
            }
            break;
        case 0x35:
            if (func_800DA298(0x5F)) {
                ((StadiumDoorState *) door)->unk_72 = 3;
                door->rotation[1] = -85.0f;
                _gcfrontend_entrypoint_9(0x62);
            }
    }
}

void func_808000FC_chstadiumdoors(u8 *door)
{
    switch ((u32) (u16) *(u16 *) ((s8 *) door + 0x72) >> 0xA) {
        case 1:
            switch ((u32) (u16) *(u16 *) ((s8 *) door + 0x76) >> 7) {
                case 0x33:
                    if (func_800DA298(0x576) != 0) {
                        *(u8 *) ((s8 *) door + 0x72) =
                            (s8) (((u8) *((s8 *) door + 0x72) & 0xFF03) | 8);
                        *(f32 *) ((s8 *) door + 0x54) = -85.0f;
                    }
                    return;

                case 0x34:
                    if (func_800DA298(0x5E) != 0) {
                        *(u8 *) ((s8 *) door + 0x72) =
                            (s8) (((u8) *(u8 *) ((s8 *) door + 0x72) & 0xFF03) | 8);
                        *(f32 *) ((s8 *) door + 0x54) = -85.0f;
                    }
                    break;

                case 0x35:
                    if (func_800DA298(0x5F) != 0) {
                        *(u8 *) ((s8 *) door + 0x72) =
                            (s8) (((u8) *(u8 *) ((s8 *) door + 0x72) & 0xFF03) | 8);
                        *(f32 *) ((s8 *) door + 0x54) = -85.0f;
                    }
            }

            break;

        case 2:
            _subaddieaudioloop_entrypoint_4(door, door + 4, 1, &D_80800270_chstadiumdoors);
            if (func_80102CF4(door, 0x3F800000) == 0) {
                func_80102B2C(door, 0x3F800000);
                return;
            }
            func_800C4140(0x665194CC, door + 4, 0x138809C4);
            *(u8 *) ((s8 *) door + 0x72) =
                (s8) (((u8) *(u8 *) ((s8 *) door + 0x72) & 0xFF03) | 0xC);
    }
}

int *chstadiumdoors_entrypoint_0()
{
    return &D_80800280_chstadiumdoors;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
s32 D_80800270_chstadiumdoors[4] = {0x1304AD, 0x1661A8, 0x100FA, 0xA8C0000};
int D_80800280_chstadiumdoors[20] = {0x2550172,
                                     0x65D0001,
                                     0x0,
                                     (u32) func_808000FC_chstadiumdoors,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x13880000,
                                     0x0,
                                     0x0,
                                     0x80804,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800000_chstadiumdoors,
                                     (u32) func_80107C2C,
                                     -0x7FF7FFFE,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0};
