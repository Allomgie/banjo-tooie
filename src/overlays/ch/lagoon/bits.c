// Most likely small scenery actors of Jolly Roger's Lagoon: explodable walls and rocks that set
// flags when destroyed, and a randomised Jinjo hiding spot (one of four chosen on first visit).
#include "common.h"

extern int D_80800804_chlagoonbits[];
extern int D_8080084C_chlagoonbits[];
extern s32 D_808008DC_chlagoonbits[];
extern int D_80800924_chlagoonbits[];
extern int D_8080096C_chlagoonbits[];
typedef struct {
    u8 pad[0x6C];
    u32 pad6C : 11;
    u32 kind : 12;
    u32 rest : 9;
} LagoonS;
extern s32 func_800DA298();
extern void func_800FFAB0();
extern u8 D_808007D0_chlagoonbits[];
extern u8 D_808009B4_chlagoonbits[];
extern s32 D_808009CC_chlagoonbits[];
extern u8 D_808009FC_chlagoonbits[];
extern u8 D_808009E4_chlagoonbits[];
extern u8 D_80800A64_chlagoonbits[];
extern s32 D_80800A30_chlagoonbits[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
extern u8 D_80800A7C_chlagoonbits[];
extern u8 D_80800A88_chlagoonbits[];
typedef union LagoonMessage1601 {
    s32 word;
    s16 halves[2];
    f32 real;
} LagoonMessage1601;
extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern void _chexploder_entrypoint_7(Actor *, f32, f32);
void func_80800730_chlagoonbits();
void func_8080023C_chlagoonbits();

int *chlagoonbits_entrypoint_0()
{
    return &D_80800804_chlagoonbits;
}

int chlagoonbits_entrypoint_1()
{
    return (int) &D_8080084C_chlagoonbits;
}

int chlagoonbits_entrypoint_2(void)
{
    extern void *D_80800894_chlagoonbits;
    return (int) &D_80800894_chlagoonbits;
}

int chlagoonbits_entrypoint_3()
{
    return D_808008DC_chlagoonbits;
}

int chlagoonbits_entrypoint_4()
{
    return (int) &D_80800924_chlagoonbits;
}

int chlagoonbits_entrypoint_5()
{
    return (int) &D_8080096C_chlagoonbits;
}

void func_80800048_chlagoonbits(s32 arg0)
{
}

void func_80800050_chlagoonbits(LagoonS *actor)
{
    if (func_800DA298(actor->kind == 0x368 ? 0xCB : 0xCC)) {
        func_800FFAB0(actor);
    }
}

void func_808000A4_chlagoonbits(s32 arg0)
{
}

void func_808000AC_chlagoonbits(Actor *actor)
{
    *(s32 **) ((char *) actor + 0x28) = _subaddiesect_entrypoint_1();
    if (func_800DA298(0xCF) != 0) {
        func_80108B04(actor, 0);
        func_80101FDC(actor, 3);
        *(u8 *) ((char *) actor + 0x65) = *(u8 *) ((char *) actor + 0x65) & 0xFFFE;
    }
}

// Jinjo #20 spawns only at the spot picked by flag 0xD1.
void func_80800108_chlagoonbits(u8 *actor)
{
    s32 chosen_spot;
    s32 spot;

    *(s32 *) ((s8 *) actor + 0x28) = _subaddiesect_entrypoint_1();
    func_80102FDC(actor, 0x3F19999A);
    if (func_800DA9E4(0xD0, 1) == 0) {
        func_800DA7A8(0xD1, func_800DC128(0, 4), 2);
    }
    chosen_spot = func_800DA564(0xD1, 2);
    spot = ((u32) (u16) *(u16 *) ((s8 *) actor + 0x76) >> 7) - 0x32;
    if ((func_800DA298(0x45, spot) != 0) || (chosen_spot != spot)) {
        if ((chosen_spot == spot) && (func_800D0B68(0x14, 0) == 0)) {
            func_800D1000(0x14, 0, actor + 4, 3, 0);
        }
        func_800FFAB0(actor);
        return;
    }
    _subaddiesect_entrypoint_2(actor, *(s32 *) ((s8 *) actor + 0x28), 1);
}

int func_808001F4_chlagoonbits(s32 actor)
{
    if ((2 == ((*(u16 *) ((u8 *) actor + 0x72) & 0xFFFFFFFFu) >> 10)) &&
        _subaddieDll_entrypoint_6(actor, 11)) {
        func_8080023C_chlagoonbits(actor);
    }
}

void func_80800548_chlagoonbits();

void func_808004B0_chlagoonbits();

void func_80800360_chlagoonbits();

void func_808002CC_chlagoonbits();

void func_8080023C_chlagoonbits(actor) u8 *actor;
{
    u32 kind;
    kind = ((u32) (*(s32 *) ((s8 *) actor + 0x6C) << 0xB) >> 0x14) & 0xFFFFFFFFFFFFFFFF;
    switch (kind) {
        case 0x366:
            func_808002CC_chlagoonbits();
            return;

        case 0x367:

        case 0x368:
            func_80800360_chlagoonbits();
            return;

        case 0x369:
            func_8080041C_chlagoonbits();
            return;

        case 0x36C:
            func_808004B0_chlagoonbits();
            return;

        case 0x36D:
            func_80800548_chlagoonbits();
    }
}

void func_808002CC_chlagoonbits(actor) Actor *actor;
{
    f32 pos[3];
    func_800EE7F8(pos, (s32 *) ((char *) actor + 0x4));
    func_800EF1B8(pos, *(s32 **) ((char *) actor + 0x48), 0xC2C80000);
    _chexploder_entrypoint_3(actor, pos, 0xE);
    func_800BBCB8((s32 *) ((char *) actor + 0x4), pos, 0.8f, 5, &D_808007D0_chlagoonbits);
    _subaddieaudioquick_entrypoint_2(actor, (s32 *) ((char *) actor + 0x4),
                                     &D_808009B4_chlagoonbits);
    func_800DA544(0xCE);
}

void func_80800360_chlagoonbits(actor) u8 *actor;
{
    s32 flag;
    f32 pos[3];

if (((u32) (*(s32 *) ((s8 *) actor + 0x6C) << 0xB) >> 0x14) == 0x368) {
    flag = 0xCB;
} else {

flag = 0xCC;
}
func_800EE7F8(pos, actor + 4);
func_800EF1B8(pos, (*(s32 *) ((s8 *) (actor) + (0x48))), 0xC2C80000);
_subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_808009CC_chlagoonbits);
func_800BBCB8(actor + 4, pos, 0.8f, 5, ((s32 *) D_808007D0_chlagoonbits));
_chexploder_entrypoint_3(actor, pos, 0xE);
func_800DA544(flag);
}

int func_8080041C_chlagoonbits(actor)
Actor *actor;
{
    f32 pos[3];
    func_800EE7F8(pos, (u8 *) actor + 4);
    pos[1] -= 100.0f;
    _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4, D_808009E4_chlagoonbits);
    func_800BBCB8((u8 *) actor + 4, pos, 0.8f, 5, D_808009FC_chlagoonbits);
    _chexploder_entrypoint_3(actor, pos, 0xe);
    func_800DA544(0xcd);
}

void func_808004B0_chlagoonbits(actor) Actor *actor;
{
    f32 *pos;
    pos = actor->position;
    _chexploder_entrypoint_3(actor, pos, 7);
    _subaddieaudioquick_entrypoint_2(actor, pos, D_80800A64_chlagoonbits);
    func_800BBCB8(pos, pos, 2.0f, 6, D_80800A30_chlagoonbits);
    func_80108B04(actor, 0);
    func_80101FDC(actor, 3);
    actor->unk64_16 = 0;
    func_800DA544(0xCF);
}

void func_80800548_chlagoonbits(actor) Actor *actor;
{
    f32 *pos = actor->position;
    func_800D1000(20, 0, pos, 1, 0);
    _chexploder_entrypoint_3(actor, pos, 7);
    func_800BBCB8(pos, pos, 0.8f, 5, D_808007D0_chlagoonbits);
    func_800DA544(0x45);
    func_800FFAB0(actor);
}

void func_808005D0_chlagoonbits(u16 *actor, s32 param_1)
{
    if (((u32) ((u16) actor[57]) >> 10) == 3) {
        func_800FFAB0();
    }
    if (param_1 == 0) {
        func_80102FDC(func_80108474(0x156, &D_80800A88_chlagoonbits, 0), 0x3F666666);
        func_80102FDC(func_80108474(0x157, &D_80800A7C_chlagoonbits, 0), 0x3F666666);
    }
}

s32 func_80800658_chlagoonbits(Actor *actor, s32 msg, LagoonMessage1601 arg)
{
    Actor *target;

    switch (msg) {
        case 0x40:
            func_80800730_chlagoonbits(actor, arg.word);
            break;
        case 0x3D:
            func_808005D0_chlagoonbits(actor, arg.word);
            break;
        case 0x90:
            target = func_80106790(func_80101080());

switch (arg.word) {
    case 0x761:
        _chexploder_entrypoint_6(target, 500.0f, 600.0f);
        _chexploder_entrypoint_7(target, -500.0f, -400.0f);
        break;
    case 0x786:
        _chexploder_entrypoint_12(target, 50);
}

break;
default:
    return 0;

}
if (arg.word) {
}
return 1;
}

void func_80800730_chlagoonbits(actor) u8 *actor;
{
    s32 flags = *(s32 *) ((char *) actor + 0x6C);
    if (((u32) ((flags << 7) << 4) >> 0x14) == 0x369) {
        if (_subaddieDll_entrypoint_5() != 0) {
            func_80103110(actor, 1);
            func_80101FDC(actor, 2);
            return;
        }

func_8080023C_chlagoonbits(actor);
return;
}
func_8080023C_chlagoonbits(actor);
}

extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_808007D0_chlagoonbits[52] = {0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x3,  0x0,  0x4,  0x0,  0x0,
                                  0x22, 0x1,  0x80, 0x2,  0x0,  0x4,  0x80, 0x6,  0x0,  0x0,  0x15,
                                  0x0,  0x0,  0x0,  0x99, 0x0,  0x19, 0x0,  0x0,  0x0,  0x7,  0x0,
                                  0x2D, 0x0,  0x32, 0x0,  0x4B, 0x0,  0x20, 0x80, 0xC8, 0xC0, 0xC0,
                                  0x0,  0xE,  0x0,  0x50, 0x0,  0x64, 0x0,  0x0};
int D_80800804_chlagoonbits[18] = {0x1980366,
                                   0x75F0001,
                                   0x0,
                                   (u32) func_80102EC0,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0xCE0000,
                                   0x800,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_80800048_chlagoonbits,
                                   (u32) func_80107C2C,
                                   -0x7FFFD400,
                                   (u32) func_80800658_chlagoonbits,
                                   0x0};
int D_8080084C_chlagoonbits[18] = {0x3020367,
                                   0x7610001,
                                   0x0,
                                   (u32) func_80102EC0,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x800,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_80800050_chlagoonbits,
                                   (u32) func_80107C2C,
                                   -0x7FFFD400,
                                   (u32) func_80800658_chlagoonbits,
                                   0x0};
void *D_80800894_chlagoonbits = (void *) 0x03020368;
static u32 D_80800894_chlagoonbits_rest[17] = {0x7610001,
                                               0x0,
                                               (u32) func_80102EC0,
                                               (u32) func_80105834,
                                               (u32) func_80101870,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x800,
                                               0x0,
                                               (u32) func_80108ED0,
                                               0x0,
                                               (u32) func_80800050_chlagoonbits,
                                               (u32) func_80107C2C,
                                               0x80002C00,
                                               (u32) func_80800658_chlagoonbits,
                                               0x0};
s32 D_808008DC_chlagoonbits[18] = {0x3030369,
                                   0x7620001,
                                   0x0,
                                   (u32) func_808001F4_chlagoonbits,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0xCD0000,
                                   0x800,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_808000A4_chlagoonbits,
                                   (u32) func_80107C2C,
                                   -0x7FFFD400,
                                   (u32) func_80800658_chlagoonbits,
                                   0x0};
int D_80800924_chlagoonbits[18] = {0x301036C,
                                   0x7860001,
                                   0x0,
                                   (u32) func_80102EC0,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x800,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_808000AC_chlagoonbits,
                                   (u32) func_80107C2C,
                                   -0x7FFFD400,
                                   (u32) func_80800658_chlagoonbits,
                                   0x0};
int D_8080096C_chlagoonbits[18] = {0x2F9036D,
                                   0x7650001,
                                   0x0,
                                   (u32) func_80102EC0,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x804,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_80800108_chlagoonbits,
                                   (u32) func_80107C2C,
                                   -0x7FFFD400,
                                   (u32) func_80800658_chlagoonbits,
                                   0x0};
u8 D_808009B4_chlagoonbits[24] = {0x0,  0x1B, 0x0, 0x13, 0x4, 0xF4, 0x0, 0xA,  0x0, 0xCC, 0x0, 0x16,
                                  0x6D, 0x60, 0x0, 0x1,  0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0,  0x0, 0x0};
s32 D_808009CC_chlagoonbits[6] = {0x1B0013, 0x4C8000D, 0xF3010C, 0x166D60, 0x104E2, 0x9C40000};
u8 D_808009E4_chlagoonbits[24] = {0x0, 0x1B, 0x0,  0x13, 0x4, 0xC8, 0x0, 0xD,  0x0, 0xF3, 0x1, 0xC,
                                  0x0, 0x16, 0x6D, 0x60, 0x0, 0x1,  0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0};
u8 D_808009FC_chlagoonbits[52] = {0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x3,  0x0,  0x4,  0x0,  0x0,
                                  0x22, 0x1,  0x80, 0x2,  0x0,  0x4,  0x80, 0x6,  0x0,  0x0,  0x15,
                                  0x0,  0x0,  0x0,  0x99, 0x0,  0x19, 0x0,  0x0,  0x0,  0x7,  0x0,
                                  0x2D, 0x0,  0x32, 0x0,  0x4B, 0x0,  0x20, 0x80, 0xC0, 0xC0, 0xC0,
                                  0x0,  0xE,  0x0,  0x50, 0x0,  0x64, 0x0,  0x0};
s32 D_80800A30_chlagoonbits[13] = {0x1D09DD,   0x2B0300, 0x4000022, 0x1800200, 0x4800600,
                                   0x150000,   0x990019, 0x7,       0x2D0032,  0x4B0020,
                                   0x788C80C0, 0xE0050,  0x640000};
u8 D_80800A64_chlagoonbits[24] = {0x0,  0x1B, 0x0, 0x13, 0x4, 0x13, 0x0, 0xA,  0x0, 0xE6, 0x0, 0x16,
                                  0x6D, 0x60, 0x0, 0x1,  0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0,  0x0, 0x0};
u8 D_80800A7C_chlagoonbits[12] = {0xC6, 0xA, 0xE8, 0x0,  0x46, 0xF,
                                  0x5C, 0x0, 0xC6, 0x1C, 0x18, 0x0};
u8 D_80800A88_chlagoonbits[24] = {0xC6, 0xE,  0x58, 0x0, 0x46, 0xF, 0x5C, 0x0,
                                  0xC6, 0x1C, 0x18, 0x0, 0x0,  0x0, 0x0,  0x0,
                                  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x0};
