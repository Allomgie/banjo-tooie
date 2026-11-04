#include "common.h"

extern int D_80800468_chboggykidshome[];
extern int D_808004B0_chboggykidshome[];
extern int D_808004F8_chboggykidshome[];
typedef union {
    s32 word;
    void *pointer;
} BoggyHomeMessage29;
typedef struct {
    u8 pad_0[0x6C];
    u32 pad_1 : 11;
    u32 actor : 12;
    u32 pad_2 : 9;
} BoggyHomeKind29;
extern u8 D_80800540_chboggykidshome[];
extern u8 D_80800550_chboggykidshome[];
extern u8 D_80800560_chboggykidshome[];
extern void *_suexpression_entrypoint_7(Actor *, s32, s32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern u8 D_80800570_chboggykidshome[];
extern u8 D_808003C0_chboggykidshome[];
extern u8 D_80800580_chboggykidshome[];
extern u8 D_808003E8_chboggykidshome[];
extern u8 D_80800590_chboggykidshome[];
extern u8 D_80800408_chboggykidshome[];
extern s32 func_801022E4(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_80101E4C(Actor *, f32 *);
extern s32 func_800DC128(s32, s32);
extern void func_800C4B7C(s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern s16 D_808005A0_chboggykidshome[];
extern f32 D_808005AC_chboggykidshome[];
extern u8 D_808005BC_chboggykidshome[];
extern u8 D_808005CC_chboggykidshome[];
extern u8 D_808005E8_chboggykidshome[];
void func_80800214_chboggykidshome();
int func_808002C0_chboggykidshome();
void func_80800300_chboggykidshome();

int chboggykidshome_entrypoint_0()
{
    return &D_80800468_chboggykidshome;
}

int chboggykidshome_entrypoint_1()
{
    return (int) &D_808004B0_chboggykidshome;
}

int chboggykidshome_entrypoint_2()
{
    return (int) &D_808004F8_chboggykidshome;
}

int func_80800024_chboggykidshome(s32 actor)
{
    // Despawn while flag 0x1CD is clear outside cutscenes.
    if (!func_800DA298(0x1CD) && !_glcutDll_entrypoint_20() && !func_800FFAB0(actor)) {
    }
}

void func_80800068_chboggykidshome(Actor *actor)
{
    s8 *flags_ptr;
    flags_ptr = (s8 *) actor + 0x72;
    if ((((u16) *(u16 *) flags_ptr & 0xFFFFFFFF) >> 0xA) == 1) {
        func_80800214_chboggykidshome();
    }
    _sudeflect_entrypoint_0((u8 *) actor + 4, 0x42C80000, 0x42480000, 0xA);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(actor), *(s32 *) ((s8 *) actor + 0),
                                0);
    func_80800300_chboggykidshome(actor);
}

void func_808000DC_chboggykidshome(Actor *arg0)
{
    _suexpression_entrypoint_8(arg0, 1);
}

s32 func_808000FC_chboggykidshome(Actor *actor, s32 msg_type, BoggyHomeMessage29 msg)
{
    void *expression;
    switch (msg_type) {
        case 0x2E:
            func_80102424(actor, 1);
            break;
        // Expression id per kid: 0x3B, 0x3C, 0x3D.
        case 0x95:
            expression = _suexpression_entrypoint_7(actor, 1,
                                                 (s16) func_808002C0_chboggykidshome(actor));
            _suexpression_entrypoint_12(expression, 60.0f, 20.0f);
            _suexpression_entrypoint_17(expression, 1000);
            break;
        // Dialog camera preset per kid.
        case 0x52:
            switch (((BoggyHomeKind29 *) actor)->actor) {
                case 0x41D:
                    _gcdialogcamera_entrypoint_3(D_80800540_chboggykidshome, actor->scale);
                    break;
                case 0x3E4:
                    _gcdialogcamera_entrypoint_3(D_80800550_chboggykidshome, actor->scale);
                    break;
                case 0x34E:
                    _gcdialogcamera_entrypoint_3(D_80800560_chboggykidshome, actor->scale);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800214_chboggykidshome(actor) Actor *actor;
{
    switch (actor->unk6C_9) {
        case 0x41D:
            // Dialog per kid actor id.
            _subaddiedialog_entrypoint_8(actor, actor->position, D_80800570_chboggykidshome,
                                         D_808003C0_chboggykidshome, 5);
            break;
        case 0x3E4:
            _subaddiedialog_entrypoint_8(actor, actor->position, D_80800580_chboggykidshome,
                                         D_808003E8_chboggykidshome, 4);
            break;
        case 0x34E:
            _subaddiedialog_entrypoint_8(actor, actor->position, D_80800590_chboggykidshome,
                                         D_80800408_chboggykidshome, 3);
    }
}

int func_808002C0_chboggykidshome(data)
s32 *data;
{
    s32 kid_id = data[0x1B];
    kid_id = ((u32) kid_id << 11) >> 20;
    if (kid_id == 0x41D) {
        return 0x3B;
    }
    if (kid_id == 0x3E4) {
        return 0x3C;
    }
    return 0x3D;
}

void func_80800300_chboggykidshome(actor) Actor *actor;
{
    if (func_801022E4(actor) == 0x246) {
        if (func_80101E14(actor, 0.0f)) {
            func_800C4B7C(D_808005A0_chboggykidshome[func_800DC128(0, 5)]);
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_808005BC_chboggykidshome);
        }
        if (func_80101E14(actor, 0.5f)) {
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_808005CC_chboggykidshome);
        }
        if (func_80101E4C(actor, D_808005AC_chboggykidshome)) {
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_808005E8_chboggykidshome);
        }
    }
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u8 D_808003C0_chboggykidshome[40] = {0x0,  0x0,  0x6,  0x1,  0x12, 0xB5, 0x1,  0x0, 0x0,  0x0,
                                     0x0,  0x1,  0x12, 0xB6, 0x2,  0x0,  0x0,  0x0, 0x2,  0x0,
                                     0x12, 0xB6, 0x2,  0x0,  0x0,  0x0,  0x4,  0x0, 0x12, 0xB6,
                                     0x2,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
u8 D_808003E8_chboggykidshome[32] = {0x0, 0x0,  0x2,  0x1,  0x12, 0xB7, 0x1,  0x0, 0x0, 0x0,  0x6,
                                     0x1, 0x12, 0xB8, 0x2,  0x0,  0x0,  0x0,  0x4, 0x0, 0x12, 0xB7,
                                     0x1, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0};
u8 D_80800408_chboggykidshome[24] = {0x0,  0x0,  0x6,  0x1,  0x12, 0xB9, 0x1, 0x0,
                                     0x0,  0x0,  0x6,  0x1,  0x12, 0xBA, 0x2, 0x0,
                                     0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB,  0x3, 0x0};
u32 D_80800420_chboggykidshome[6] = {0x0, 0x0, 0x4089999A, 0x2420000, 0x4089999A, 0x2420000};
u32 D_80800438_chboggykidshome[6] = {0x0, 0x0, 0x40133333, 0x2440000, 0x40133333, 0x2440000};
u32 D_80800450_chboggykidshome[6] = {0x0, 0x0, 0x409CCCCD, 0x2460000, 0x409CCCCD, 0x2460000};
int D_80800468_chboggykidshome[18] = {0x158041D,
                                      0x7590001,
                                      (u32) &D_80800420_chboggykidshome,
                                      (u32) func_80800068_chboggykidshome,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x3F800000,
                                      0x0,
                                      0x120,
                                      (u32) func_808000DC_chboggykidshome,
                                      0x0,
                                      0x0,
                                      (u32) func_80800024_chboggykidshome,
                                      (u32) func_80107C2C,
                                      -0x7FFFFBFE,
                                      (u32) func_808000FC_chboggykidshome,
                                      0x0};
int D_808004B0_chboggykidshome[18] = {0x15803E4,
                                      0x75A0001,
                                      (u32) &D_80800438_chboggykidshome,
                                      (u32) func_80800068_chboggykidshome,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x3F800000,
                                      0x0,
                                      0x128,
                                      (u32) func_808000DC_chboggykidshome,
                                      0x0,
                                      0x0,
                                      (u32) func_80800024_chboggykidshome,
                                      (u32) func_80107C2C,
                                      -0x7FFFFBFE,
                                      (u32) func_808000FC_chboggykidshome,
                                      0x0};
int D_808004F8_chboggykidshome[18] = {0x158034E,
                                      0x75B0001,
                                      (u32) &D_80800450_chboggykidshome,
                                      (u32) func_80800068_chboggykidshome,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x40000000,
                                      0x0,
                                      0x120,
                                      (u32) func_808000DC_chboggykidshome,
                                      0x0,
                                      0x0,
                                      (u32) func_80800024_chboggykidshome,
                                      (u32) func_80107C2C,
                                      -0x7FFFFBFE,
                                      (u32) func_808000FC_chboggykidshome,
                                      0x0};
u8 D_80800540_chboggykidshome[16] = {0x43, 0x20, 0x0, 0x0, 0x43, 0xC,  0x0, 0x0,
                                     0x43, 0xC,  0x0, 0x0, 0x42, 0x8C, 0x0, 0x0};
u8 D_80800550_chboggykidshome[16] = {0x43, 0x20, 0x0, 0x0, 0x43, 0xC,  0x0, 0x0,
                                     0x43, 0xC,  0x0, 0x0, 0x42, 0x8C, 0x0, 0x0};
u8 D_80800560_chboggykidshome[16] = {0x43, 0x34, 0x0, 0x0, 0x43, 0xC,  0x0, 0x0,
                                     0x43, 0xC,  0x0, 0x0, 0x42, 0xA0, 0x0, 0x0};
u8 D_80800570_chboggykidshome[16] = {0x0, 0xB8, 0x0, 0x0, 0x1, 0x2C, 0x0, 0x3B,
                                     0x0, 0x0,  0x0, 0xC, 0x6, 0x3C, 0x2, 0x0};
u8 D_80800580_chboggykidshome[16] = {0x0, 0xB9, 0x0, 0x0, 0x1, 0x2C, 0x0, 0x3C,
                                     0x0, 0x0,  0x0, 0xC, 0x6, 0x3C, 0x2, 0x0};
u8 D_80800590_chboggykidshome[16] = {0x0, 0xBA, 0x0, 0x0, 0x1, 0x2C, 0x0, 0x3D,
                                     0x0, 0x0,  0x0, 0xC, 0x6, 0x3C, 0x2, 0x0};
s16 D_808005A0_chboggykidshome[6] = {0x540, 0x42B, 0x558, 0x559, 0x557, 0x0};
f32 D_808005AC_chboggykidshome[4] = {0.6f, 0.72f, 0.86f, -1.0f};
u8 D_808005BC_chboggykidshome[16] = {0x0, 0x21, 0x0,  0xD,  0x0,  0xD9, 0x0, 0xF3,
                                     0x0, 0x19, 0x4E, 0x20, 0x5D, 0xC0, 0x0, 0x0};
u8 D_808005CC_chboggykidshome[28] = {0x0, 0x13, 0x4,  0x86, 0x0,  0xD, 0x0, 0xC0, 0x0, 0xD9,
                                     0x0, 0x19, 0x6D, 0x60, 0x7D, 0x0, 0x0, 0x15, 0x0, 0xC,
                                     0x0, 0xCC, 0x0,  0x33, 0x0,  0x0, 0x0, 0x0};
u8 D_808005E8_chboggykidshome[24] = {0x0, 0x13, 0x5, 0xCA, 0x0, 0xD, 0x0, 0xD9,
                                     0x0, 0xF3, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0,
                                     0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
