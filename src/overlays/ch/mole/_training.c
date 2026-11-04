// Most likely Bottles' move training in Spiral Mountain: opens a move-category menu, checks the
// chosen move is known and runs the practice through the mole entrypoints.
#include "common.h"

typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 rest : 10;
} MoleS;
extern void _gcnewoption_entrypoint_1(void *, s32);
extern void _gcnewoption_entrypoint_32(void *, s16);
extern void _gcnewoption_entrypoint_31(void *, s32, s16);
extern void *func_80100094(Actor *, u32);
extern void _chmole_training_entrypoint_0(void);
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern int D_80800F30_chmole_training[];
extern u8 D_80800E34_chmole_training[];
extern u8 D_80800E32_chmole_training[];
extern s32 _sumole_entrypoint_6(Actor *, s32, f32);
typedef struct MoleTrainingState {
    u8 pad_0[0x72];
    u8 local_0 : 6;
    u8 pad_1 : 2;
} MoleTrainingState;
extern s16 D_80800F08_chmole_training[];
extern s16 D_80800F10_chmole_training[];
extern s16 D_80800F18_chmole_training[];
extern s16 D_80800F20_chmole_training[];
extern s16 D_80800F24_chmole_training[];
extern s16 D_80800F28_chmole_training[];
extern s16 D_80800F2C_chmole_training[];
extern Actor *func_80106790(Unk80132ED0 *);
void func_80800270_chmole_training();
void func_808003D4_chmole_training();
void func_80800A48_chmole_training();
void func_80800BA8_chmole_training();

s32 func_80800000_chmole_training(Actor *actor)
{
    if (func_80100094(actor, 0)) {
        _gcnewoption_entrypoint_6(actor, 0);
    }
}

void func_80800034_chmole_training(MoleS *actor, s32 unk_1)
{
    u32 state = actor->f72;
    if (state == 5 || state == 7 || state == 6) {
        _gcnewoption_entrypoint_1(func_80100094(actor, 0), unk_1);
    }
}

void func_80800C3C_chmole_training();

void func_80800C28_chmole_training();

void func_80800088_chmole_training(Actor *actor)
{
    s32 ability;
    if (actor->unk3C != NULL) {
        switch (actor->unk70_10) {
            case 1:
                func_80800270_chmole_training(actor);
                break;
            case 2:
                func_808003D4_chmole_training(actor);
                break;
            case 3:
                *((u8 *) actor + 0x72) = (*((u8 *) actor + 0x72) & 0xFF03) | 0x10;
                break;
            case 4:
                func_80800A48_chmole_training(actor);
                break;
            case 5:
                _gcnewoption_entrypoint_0(func_80100094(actor, 0));
                break;
            case 7:
                _gcnewoption_entrypoint_6(actor, 0);
                ability = *(s8 *) (D_80800E34_chmole_training + (s32) actor->unk54 * 8);
                if (ability != -1 && !func_800C6E38(ability)) {
                    func_80101FDC(actor, 8);
                    return;
                }
                func_80101FDC(actor, 10);
                break;
            case 6:
                _gcnewoption_entrypoint_6(actor, 0);
                func_80101FDC(actor, 11);
                break;
            case 10:
                if (_sumole_entrypoint_17(
                        actor, *(s16 *) (D_80800E32_chmole_training + (s32) actor->unk54 * 8),
                        -1, 0)) {
                    _sumole_entrypoint_19(actor, 0);
                    func_80101FDC(actor, 12);
                }
                break;
            case 9:
                func_80800BA8_chmole_training(actor);
                break;
            case 11:
                func_80800C28_chmole_training(actor);
                break;
            case 12:
                func_80800C3C_chmole_training(actor);
                break;
            case 13:
                _sumole_entrypoint_19(actor, 0);
                *((u8 *) actor + 0x72) = (*((u8 *) actor + 0x72) & 0xFF03) | 0x30;
        }
    }
}

void func_80800270_chmole_training(actor) Actor *actor;
{
    switch ((u32) actor->unk54) {
        case 6:
            if (!func_800DA298(0x53)) {
                if (_sumole_entrypoint_6(actor, -1, 350.0f))
                    func_80101FDC(actor, 2);
            } else if ((func_8008FD70() & 0x701) && _sumole_entrypoint_1(actor, -1, 0, 0)) {
                func_80101FDC(actor, 2);
            }
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
            if ((func_8008FD70() & 0x701) && _sumole_entrypoint_1(actor, -1, 0, 0))
                func_80101FDC(actor, 2);
    }
}

void func_808003D4_chmole_training(actor) Actor *actor;
{
    switch ((u32) actor->unk54) {
        case 6:
            if (!func_800DA298(0x53)) {
                func_800DA3B8(0x53, 1);
            }
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
            _sumole_entrypoint_19(actor, 3);
            ((MoleTrainingState *) actor)->local_0 = 3;
    }
}

// Matching: volatile return type is needed for the match.
volatile int func_808004D0_chmole_training(Actor *actor, u32 menu)
{
    // Matching: `| 0U` is needed for the match.
    u32 menu_ref = menu | 0U;
    switch ((u32) actor->unk54) {
        case 1:
            _gcnewoption_entrypoint_12(menu_ref, 0, 0xa);
            _gcnewoption_entrypoint_12(menu_ref, 1, 0x15);
            _gcnewoption_entrypoint_12(menu_ref, 2, 0x16);
            break;

        case 2:
            _gcnewoption_entrypoint_12(menu_ref, 0, 0xb);
            _gcnewoption_entrypoint_12(menu_ref, 1, 0xc);
            _gcnewoption_entrypoint_12(menu_ref, 2, 0x1a);
            break;

        case 4:
            _gcnewoption_entrypoint_12(menu_ref, 0, 0x17);
            _gcnewoption_entrypoint_12(menu_ref, 1, 0x18);
            _gcnewoption_entrypoint_12(menu_ref, 2, 0x19);
            break;

        case 0:
            _gcnewoption_entrypoint_12(menu_ref, 0, 0x14);
            _gcnewoption_entrypoint_12(menu_ref, 1, 0xd);
            break;

        case 3:
            _gcnewoption_entrypoint_12(menu_ref, 0, 0xe);
            _gcnewoption_entrypoint_12(menu_ref, 1, 0xf);
            break;

        case 7:
            _gcnewoption_entrypoint_12(menu_ref, 0, 0x10);
            _gcnewoption_entrypoint_12(menu_ref, 1, 0x11);
            break;

        case 5:
            _gcnewoption_entrypoint_12(menu_ref, 0, 0x12);
            _gcnewoption_entrypoint_12(menu_ref, 1, 0x13);
    }
}

void chmole_training_entrypoint_0(Unk80132ED0 *menu, s32 unk_1, s32 index, s32 event)
{
    Actor *actor;

    actor = func_80106790(menu);
    switch (event) {
        case 3:
            switch ((u32) actor->unk54) {
                case 1:
                    actor->unk54 = D_80800F08_chmole_training[index];
                    break;
                case 2:
                    actor->unk54 = D_80800F10_chmole_training[index];
                    break;
                case 4:
                    actor->unk54 = D_80800F18_chmole_training[index];
                    break;
                case 0:
                    actor->unk54 = D_80800F20_chmole_training[index];
                    break;
                case 3:
                    actor->unk54 = D_80800F24_chmole_training[index];
                    break;
                case 7:
                    actor->unk54 = D_80800F28_chmole_training[index];
                    break;
                case 5:
                    actor->unk54 = D_80800F2C_chmole_training[index];
                    break;
            }
            func_80101FDC(actor, 7);
            break;
        case 0:
            func_808004D0_chmole_training(actor, unk_1);
            break;
        case 2:
            func_80101FDC(actor, 6);
    }
}

void func_808008E4_chmole_training(Actor *actor, void *menu, s32 count)
{
    s32 i;
    _gcnewoption_entrypoint_32(menu, func_800DA298(0x578) ? 0xF : 0x9E);
    for (i = 0; i < count; i++) {
        _gcnewoption_entrypoint_31(menu, i, (i & 1) ? 0xD : 0xC);
    }
}

// Opens the move-category option menu.
void func_80800988_chmole_training(Actor *actor, s32 unk_1, s32 count)
{
    void *menu;

    _gcnewoption_entrypoint_4(actor, 0, _chmole_training_entrypoint_0, 0, 0x184A);
    menu = func_80100094(actor, 0);
    _gcnewoption_entrypoint_8(menu, unk_1);
    _gcnewoption_entrypoint_9(menu, count);
    _gcnewoption_entrypoint_10(menu, 0);
    func_808008E4_chmole_training(actor, menu, count);
    _gcnewoption_entrypoint_14(menu, 0, 1, 3, 4.0f);
    _gcnewoption_entrypoint_11(menu);
    func_80101FDC(actor, 5);
}

void func_80800A48_chmole_training(actor) Actor *actor;
{
    switch ((u32) actor->unk54) {
        case 1:
            func_80800988_chmole_training(actor, 3, 3);
            break;
        case 2:
            func_80800988_chmole_training(actor, 3, 3);
            break;
        case 4:
            func_80800988_chmole_training(actor, 3, 3);
            break;
        case 0:
            func_80800988_chmole_training(actor, 2, 2);
            break;
        case 3:
            func_80800988_chmole_training(actor, 2, 2);
            break;
        case 7:
            func_80800988_chmole_training(actor, 2, 2);
            break;
        case 5:
            func_80800988_chmole_training(actor, 2, 2);
            break;
        case 6:
            func_80101FDC(actor, 4);
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
            func_80101FDC(actor, 4);
    }
}

void func_80800BA8_chmole_training(actor) Actor *actor;
{
    switch ((s32) actor->unk54) {
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
            actor->unk54 = (s32) actor->rotation[1];
            actor->unk70_10 = 4;
            break;
        default:
            actor->unk70_10 = 11;
    }
}

void func_80800C28_chmole_training(u8 *actor)
{
    actor[0x72] = (u8) ((actor[0x72] & 0xFF03) | 0x34);
}

void func_80800C3C_chmole_training(u8 *actor)
{
    *(f32 *) &actor[0x54] = (f32) (s32) *(f32 *) &actor[0x48];
    actor[0x72] = (actor[0x72] & 0xFF03) | 4;
}

void func_80800C70_chmole_training(Actor *actor)
{
    *(f32 *) ((char *) actor + 0x54) = (f32) (s32) *(f32 *) ((char *) actor + 0x48);
    _sumole_entrypoint_0(actor, 1);
}

int chmole_training_entrypoint_1()
{
    return (int) &D_80800F30_chmole_training;
}

extern void func_80107C2C();
u32 D_80800E30_chmole_training[1] = {0xFFFFFFFF};
u8 D_80800E34_chmole_training[212] = {
    0xFF, 0xFF, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0, 0x0, 0xD,  0x59, 0xD,  0x59,
    0xA,  0x3C, 0x0, 0x0, 0xD,  0x5A, 0xD,  0x5A, 0x5,  0x40, 0x0, 0x0, 0xD,  0x5D, 0xD,  0x5D,
    0xD,  0x45, 0x0, 0x0, 0xD,  0x62, 0xD,  0x62, 0xFF, 0xFF, 0x0, 0x0, 0xD,  0x5B, 0xD,  0x5B,
    0xFF, 0xFF, 0x0, 0x0, 0xD,  0x5C, 0xD,  0x5C, 0xFF, 0xFF, 0x0, 0x0, 0xD,  0x60, 0xD,  0x60,
    0xFF, 0xFF, 0x0, 0x0, 0xD,  0x61, 0xD,  0x61, 0xFF, 0xFF, 0x0, 0x0, 0xD,  0x5E, 0xD,  0x5E,
    0xFF, 0xFF, 0x0, 0x0, 0xD,  0x5F, 0xD,  0x5F, 0xFF, 0xFF, 0x0, 0x0, 0xD,  0x52, 0xD,  0x52,
    0xFF, 0xFF, 0x0, 0x0, 0xD,  0x53, 0xD,  0x53, 0xFF, 0xFF, 0x0, 0x0, 0xD,  0x54, 0xD,  0x54,
    0xFF, 0xFF, 0x0, 0x0, 0xD,  0x55, 0xD,  0x55, 0xFF, 0xFF, 0x0, 0x0, 0xD,  0x56, 0xD,  0x56,
    0xFF, 0xFF, 0x0, 0x0, 0xD,  0x57, 0xD,  0x57, 0xFF, 0xFF, 0x0, 0x0, 0xD,  0x58, 0xD,  0x58,
    0xFF, 0xFF, 0x0, 0x0};
s16 D_80800F08_chmole_training[4] = {0xA, 0x15, 0x16, 0x0};
s16 D_80800F10_chmole_training[4] = {0xB, 0xC, 0x1A, 0x0};
s16 D_80800F18_chmole_training[4] = {0x17, 0x18, 0x19, 0x0};
s16 D_80800F20_chmole_training[2] = {0x14, 0xD};
s16 D_80800F24_chmole_training[2] = {0xE, 0xF};
s16 D_80800F28_chmole_training[2] = {0x10, 0x11};
s16 D_80800F2C_chmole_training[2] = {0x12, 0x13};
int D_80800F30_chmole_training[20] = {0x2EA01A9,
                                      -0xFFFF,
                                      0x0,
                                      (u32) func_80800088_chmole_training,
                                      0x0,
                                      (u32) func_80800034_chmole_training,
                                      0x1F40000,
                                      0x0,
                                      0x0,
                                      0xA0004,
                                      (u32) func_80800000_chmole_training,
                                      0x0,
                                      0x0,
                                      (u32) func_80800C70_chmole_training,
                                      (u32) func_80107C2C,
                                      -0x7FFFDFFE,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0};
