// The eight Cloud Cuckooland dirt piles broken with Bill Drill. A per-save seed shuffles which
// pile hides which item; a broken pile spawns its item, sets its flag and bursts into debris.
#include "common.h"

typedef struct {
    f32 pos[3];
    f32 yaw;
} DrillfieldPlacement;
extern DrillfieldPlacement D_808008D0_chfantasydrillfield[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct {
    s32 key;
    s32 val;
} DrillEnt;
extern s32 _gccubesearch_entrypoint_9(s32, void *, s32);
extern s32 func_800DA298(s32);
extern void func_800DA3B8(s32, s32);
extern void func_800DA544(s32);
extern s32 func_800DC128(s32, s32);
extern s32 func_800DC090(void);
extern void func_800DC324(s32);
typedef struct {
    s32 unused;
    s32 value;
} DrillFieldRecord;
extern void func_800DA524(s32);
extern s32 D_808008B0_chfantasydrillfield[];
extern u8 D_80800950_chfantasydrillfield[];
extern u8 D_80800988_chfantasydrillfield[];
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_80103EAC(Actor *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern Actor *func_80106790(Unk80132ED0 *);
extern Unk80132ED0 *func_800D10D4(u32, u32, f32 *, s32, Unk80132ED0 *);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 _subaddiefind_entrypoint_5(s32, Actor **, s32, f32 *, f32, f32 (*)(f32 *, f32 *));
extern int D_808009C4_chfantasydrillfield[];
s32 func_80800360_chfantasydrillfield();

// Places a pile by its rank among all piles.
void func_80800000_chfantasydrillfield(pile) Actor *pile;
{
    Actor *piles[8];
    s32 i;
    s32 rank;

    i = _subaddiefind_entrypoint_4(0x40A, piles, 8) - 1;
    rank = 0;
    while (i >= 0) {
        if (piles[i]->pad6C_21 < pile->pad6C_21)
            rank++;
        i--;
    }
    func_800EFA4C(pile->position, D_808008D0_chfantasydrillfield[rank].pos[0],
                  D_808008D0_chfantasydrillfield[rank].pos[1],
                  D_808008D0_chfantasydrillfield[rank].pos[2]);
    pile->rotation[1] = D_808008D0_chfantasydrillfield[rank].yaw;
    func_80103014(pile);
}

DrillFieldRecord B_80800A10_chfantasydrillfield[8];

// Assigns an item to each pile; the shuffle seed is stored in flags 0x1DD-0x1E0.
void func_808000C4_chfantasydrillfield(s32 param_0)
{
    void *piles[8];
    s32 count;
    s32 m;
    s32 i;
    s32 saved_seed;
    s32 j;
    s32 s0;
    s32 seed;
    s32 sp50;
    s32 s2;
    s32 sp48;
    s32 tmp_key;

    count = _gccubesearch_entrypoint_9(0x40A, piles, 8);
    for (s2 = 0; s2 < count; s2++) {
        ((DrillEnt *) B_80800A10_chfantasydrillfield)[s2].key = ((u32 *) piles[s2])[4] >> 21;
        ((DrillEnt *) B_80800A10_chfantasydrillfield)[s2].val = -1;
    }
    if (count > 0) {
        s2 = 0;
        do {
            for (j = 0; j < count; j++) {
                if (((DrillEnt *) B_80800A10_chfantasydrillfield)[s2].key <
                    ((DrillEnt *) B_80800A10_chfantasydrillfield)[j].key) {
                    tmp_key = ((DrillEnt *) B_80800A10_chfantasydrillfield)[j].key;
                    ((DrillEnt *) B_80800A10_chfantasydrillfield)[j].key =
                        ((DrillEnt *) B_80800A10_chfantasydrillfield)[s2].key;
                    ((DrillEnt *) B_80800A10_chfantasydrillfield)[s2].key = tmp_key;
                }
            }
            s2++;
        } while (s2 != count);
    }
    s2 = 0;
    if (func_800DA298(0x1DC) != 0) {
        sp50 = 4;
        seed = 0;
        for (s0 = 0; s0 < sp50; s0++) {
            seed = seed << 1;
            seed = func_800DA298(s0 + 0x1DD) | seed;
        }
    } else {
        sp48 = 4;
        seed = func_800DC128(0, 0x10);
        s0 = 0;
        do {
            func_800DA3B8(s0 + 0x1DD, (seed >> (3 - s0)) & 1);
            s0++;
        } while (s0 != sp48);
        func_800DA544(0x1DC);
    }
    saved_seed = func_800DC090();
    func_800DC324(seed);
    if (func_80800360_chfantasydrillfield() == 0) {
        do {
            i = func_800DC128(0, 8);
            if (((DrillEnt *) B_80800A10_chfantasydrillfield)[i].val == -1) {
                ((DrillEnt *) B_80800A10_chfantasydrillfield)[i].val = s2;
                s2++;
            }
        } while (func_80800360_chfantasydrillfield() == 0);
    }
    func_800DC324(saved_seed);
}

// Returns 1 once every pile has an item.
s32 func_80800360_chfantasydrillfield(void)
{
    s32 all_set = 1;
    s32 i;

    for (i = 0; i < 8; i++) {
        all_set &= B_80800A10_chfantasydrillfield[i].value != -1;
    }
    return all_set;
}

// Takes the item of the pile with this key; sets flag 0xA0F once every pile is taken.
s32 func_808003C8_chfantasydrillfield(s32 key)
{
    s32 pad;
    s32 result = 0;
    s32 all_taken;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (key == B_80800A10_chfantasydrillfield[i].unused) {
            result = B_80800A10_chfantasydrillfield[i].value;
            B_80800A10_chfantasydrillfield[i].unused = 0;
            break;
        }
    }
    all_taken = 1;
    for (i = 0; i <= 8; i++) {
        all_taken &= B_80800A10_chfantasydrillfield[i].unused == 0;
    }
    if (all_taken) {
        func_800DA524(0xA0F);
    }
    return result;
}

void func_8080048C_chfantasydrillfield(Actor *pile)
{
    func_80800000_chfantasydrillfield();
    if (func_800DA298(0xA0F) == 0) {
        func_800DA544(0xA0F);
        func_808000C4_chfantasydrillfield(pile);
    }
    *(s32 *) ((char *) pile + 0x34) =
        func_808003C8_chfantasydrillfield(*(u32 *) ((char *) pile + 0x6C) >> 0x15);
}

void func_808004E8_chfantasydrillfield(Actor *pile)
{
    switch (pile->unk70_10) {
        case 1:
            func_80103110(pile, 0);
            break;
        case 2:
            if (_subaddieDll_entrypoint_6(pile, 0xB)) {
                func_80108B04(pile, 1);
            }
    }
}

// Message handler: 0x40 hit, 0x3D break open (spawn item), 0xF debris effects, 0x95 init.
s32 func_8080054C_chfantasydrillfield(Actor *pile, s32 msg, s32 arg)
{
    f32 ray_top[3];
    f32 spawn_pos[3];
    f32 unk_0[3];
    Actor *spawned;
    Actor *found;

    switch (msg) {
        case 0x40:
            if (_subaddieDll_entrypoint_5(pile, arg)) {
                func_80103110(pile, 1);
                func_80101FDC(pile, 2);
            }
            return 1;
        case 0x3D:
            func_800EE7F8(spawn_pos, pile->position);
            func_800EE7F8(ray_top, pile->position);
            ray_top[1] += 200.0f;
            spawn_pos[1] -= 200.0f;
            func_800BEF00(ray_top, spawn_pos, unk_0, 0);
            switch (D_808008B0_chfantasydrillfield[pile->actorData[7]]) {
                case 0:
                    func_800FFA88(pile->unk0);
                    break;
                case 0x1F7:
                    func_80106790(func_800D10D4(0x16, 2, spawn_pos, 3, NULL));
                    break;
                default:
                    spawned = func_80108528(D_808008B0_chfantasydrillfield[pile->actorData[7]],
                                            spawn_pos, 0, &pile);
                    if (spawned->unk6C_9 == 0x3DB) {
                        spawned->rotation[1] = 20.0f;
                    } else if (spawned->unk6C_9 == 0x40D) {
                        spawned->unk74_7 = pile->actorData[7];
                    }
            }
            if (arg) {
                func_800DA544(pile->actorData[7] + 0x335);
                _chskeletonexplode_entrypoint_7(pile, pile->position);
                func_8010A570(pile);
                func_8010A624(pile);
                func_800FFA88(pile->unk0);
            }
            return 1;
        case 0xF:
            func_800C4140(0x59919413, pile->position, 0x04B000FA);
            func_800BBCB8(pile->position, pile->position, 1.0f, 6,
                          D_80800950_chfantasydrillfield);
            func_800BBCB8(pile->position, pile->position, 1.0f, 3,
                          D_80800988_chfantasydrillfield);
            return 1;
        case 0x95:
            if (func_800DA298(pile->actorData[7] + 0x335)) {
                pile->unk64_16 = 0;
                func_8010A570(pile);
                func_8010A624(pile);
                switch (D_808008B0_chfantasydrillfield[pile->actorData[7]]) {
                    case 0:
                        func_800FFA88(pile->unk0);
                        break;
                    case 0x1F7:
                        if (func_800D0B68(0x16, 2)) {
                            func_800FFA88(pile->unk0);
                        } else {
                            func_80108B04(pile, 0);
                        }
                        break;
                    default:
                        if (!_subaddiefind_entrypoint_5(
                                D_808008B0_chfantasydrillfield[pile->actorData[7]], &found, 1,
                                pile->position, func_80103EAC(pile), func_800EEB40)) {
                            func_80108B04(pile, 0);
                        }
                }
            }
            func_800DA524(0xA0F);
            return 1;
    }
    return 0;
}

int chfantasydrillfield_entrypoint_0()
{
    return (int) &D_808009C4_chfantasydrillfield;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_808008B0_chfantasydrillfield[8] = {0x40D, 0x40D, 0x229, 0x3DB, 0x1F7, 0x1E9, 0x4A6, 0x0};
DrillfieldPlacement D_808008D0_chfantasydrillfield[8] = {
    4845.53f, 2.54e+03f, -5329.37f, 0.0f,   3727.57f, 2.54e+03f, -5898.67f, 45.0f,
    3982.39f, 2.54e+03f, -6356.72f, 335.0f, 4253.13f, 2.54e+03f, -5679.16f, 345.0f,
    4760.04f, 2.54e+03f, -5970.08f, 0.0f,   5161.16f, 2.54e+03f, -5691.5f,  25.0f,
    4477.09f, 2.54e+03f, -6476.48f, 6e+01f, 5202.73f, 2.54e+03f, -6440.36f, -2e+01f};
u8 D_80800950_chfantasydrillfield[56] = {
    0x0, 0x1D, 0x9, 0x29, 0x0, 0x14, 0x0,  0x16, 0x10, 0x6,  0x0,  0x2D, 0x2,  0x58,
    0x3, 0x20, 0x0, 0x2B, 0x1, 0x0,  0x2,  0x0,  0x0,  0x1B, 0xFC, 0x18, 0xFC, 0xE0,
    0x0, 0x22, 0x1, 0x0,  0x0, 0xCC, 0x0,  0xC0, 0x0,  0xC0, 0x0,  0x7,  0x0,  0x2,
    0x0, 0xD,  0x0, 0x64, 0x0, 0x31, 0xFF, 0xCE, 0xFF, 0xE7, 0x0,  0x0,  0x0,  0x0};
u8 D_80800988_chfantasydrillfield[60] = {
    0x0,  0x1D, 0x9,  0xDD, 0x0, 0x2B, 0x4,  0x0,  0x5,  0x0,  0x0,  0x16, 0x10, 0x0,  0x0,
    0x22, 0x1,  0x80, 0x2,  0x0, 0x4,  0x80, 0x6,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x26,
    0x0,  0x19, 0x0,  0x0,  0x0, 0x7,  0x0,  0x2D, 0x0,  0x32, 0x0,  0x64, 0x0,  0x20, 0xDE,
    0xA7, 0x71, 0xC0, 0x0,  0xD, 0x0,  0x64, 0x0,  0x31, 0xFF, 0xCE, 0xFF, 0xE7, 0x0,  0x0};
int D_808009C4_chfantasydrillfield[19] = {0x354040A,
                                          0x82C0001,
                                          0x0,
                                          (u32) func_808004E8_chfantasydrillfield,
                                          (u32) func_80105834,
                                          (u32) func_80101870,
                                          0x7D00000,
                                          0x0,
                                          0x0,
                                          0x800,
                                          0x0,
                                          (u32) func_80108ED0,
                                          0x0,
                                          (u32) func_8080048C_chfantasydrillfield,
                                          (u32) func_80107C2C,
                                          -0x7FFFDC00,
                                          (u32) func_8080054C_chfantasydrillfield,
                                          0x0,
                                          0x0};
