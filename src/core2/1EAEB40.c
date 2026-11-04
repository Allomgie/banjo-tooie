// Prop-control trigger dispatcher: probably routes trigger-prop activations to handler tables or
// section-skip warps, plus the current dialog speaker/expression and a pending-trigger state.
#include "common.h"

extern s8 D_8012B431;
extern unsigned char D_8012B430;
extern s16 D_8012B432;
typedef void (*D_8011B680Entry)(s32, s32);
extern D_8011B680Entry D_8011B680[];
typedef void (*D_8011B7C0Entry)(s32, s32);
extern D_8011B7C0Entry D_8011B7C0[];

void func_800D52B0(void);

// Current dialog speaker and facial expression: set by the dialog boxes, cleared every frame.
void func_800D5250()
{
    func_800D52B0();
}

int func_800D5270()
{
    D_8012B431 = 0;
}

// Pending-trigger state in D_8012B430: id + 1 (u8), active flag (u8), value (s16).
void func_800D527C(s32 id)
{
    int one;
    // Matching: the temporaries `one` and `value` are needed for the match.
    short value;
    value = 0xFFFFu;
    ((s8 *) &D_8012B430)[0] = (id & value) + 1;
    one = 1;
    value = one;
    ((s8 *) &D_8012B430)[one] = value;
}

u8 func_800D5298()
{
    return D_8012B431;
}

s32 func_800D52A4(void)
{
    return *(u8 *) &D_8012B430;
}

void func_800D52B0(void)
{
    *(unsigned char *) ((char *) &D_8012B430 + 1) = 0;
    *(short *) ((char *) &D_8012B430 + 2) = -1;
    *(unsigned char *) ((char *) &D_8012B430 + 0) = 0;
}

int func_800D52CC(volatile int value)
{
    func_800D52B0();
    D_8012B432 = value & 0xFFFFFFFFu;
}

s32 func_800D52F4()
{
    return D_8012B432;
}

// Dispatch of trigger-prop activations to handler tables or section-skip warps; pending trigger.
void func_800D5300(s32 prop, s32 actor)
{
}

void func_800D530C(s32 prop, s32 actor)
{
}

// Called when an actor enters a trigger prop; dispatches on the prop control type.
void func_800D5318(s32 prop, s32 actor)
{
    s32 frame;
    switch (_gspropctrl_entrypoint_2(prop)) {
        case 3:
            frame = func_8001211C();
            if ((_gspropctrl_entrypoint_3(prop) + 1) != frame) {
                D_8011B680[_gspropctrl_entrypoint_4(prop)](prop, actor);
            }
            _gspropctrl_entrypoint_5(prop, frame);
            return;
        case 5:
            _gcsectionskip_entrypoint_1(prop, *(u16 *) (prop + 8) + 0xA0,
                                        *(s32 *) (prop + 12) & 0x7FFFFF, *(u8 *) (prop + 11),
                                        actor);
            return;
        case 4:
            D_8011B7C0[_gspropctrl_entrypoint_4(prop)](prop, actor);
    }
}

func_800D5424(s32 id)
{
    s32 result;
    result = id - 0x16;
    return result;
}

func_800D542C(id)
{
    return id + 0x9A;
}

// TU-NOTE: the .data of this file is defined here in C. Its tables hold pointers to functions of
// this file; IDO's assembler schedules some of these functions differently unless the tables are
// defined in the same unit. Values are taken from the ROM.
extern void _gcgoto_entrypoint_9();
extern void _gcgoto_entrypoint_10();
extern void _gcgoto_entrypoint_11();
extern void _chcoderoombits_entrypoint_1();
extern void _chpotogoldgame_entrypoint_2();
extern void _chprisonbits_entrypoint_5();
extern void _gcgoto_entrypoint_7();
extern void func_800A5598();
extern void func_800A5550();
extern void func_80090038();
D_8011B680Entry D_8011B680[80] = {(void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) _gcgoto_entrypoint_9,
                                  (void *) _gcgoto_entrypoint_10,
                                  (void *) _gcgoto_entrypoint_11,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) _chcoderoombits_entrypoint_1,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) _chpotogoldgame_entrypoint_2,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) _chprisonbits_entrypoint_5,
                                  (void *) _gcgoto_entrypoint_7,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300,
                                  (void *) func_800D5300};
D_8011B7C0Entry D_8011B7C0[80] = {(void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5598,
                                  (void *) func_800A5550,
                                  (void *) func_80090038,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  (void *) func_800D530C,
                                  0,
                                  0};
