// Probably TDL's switch-and-door set: a table configures several switch kinds built on the
// generic switch, and the doors they open. One switch runs a 35 s countdown before re-closing.
#include "common.h"

extern int D_80800C30_chdinoswitches[];
extern int D_80800C78_chdinoswitches[];
extern int D_80800CC0_chdinoswitches[];
extern s32 D_80800D08_chdinoswitches[];
extern u8 D_80800B20_chdinoswitches[];
extern u8 D_80800B48_chdinoswitches[];
extern u8 D_80800B5C_chdinoswitches[];
extern u8 D_80800B34_chdinoswitches[];
extern u8 D_80800B6C_chdinoswitches[];
extern u8 D_80800B70_chdinoswitches[];
extern u8 D_80800B44_chdinoswitches[];
extern u8 D_80800B58_chdinoswitches[];
extern u16 D_80800B28_chdinoswitches[];
extern unsigned int func_801032B0();
typedef struct {
    u16 f[10];
} E20;
extern u8 D_8011A270[];
extern u8 D_8011A248[];
typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 10;
    u32 local_0 : 1;
    u32 pad_2 : 21;
} DinoSwitchFlags;
extern void _chdinoswitches_entrypoint_4(void);
extern void (*func_800CE95C(s32))(void);
extern void func_800CE928(s32, void (*)(void), s32);
extern void func_800CE8D8(s32, f32, s32);
extern struct {
    u16 field;
    u16 pad[9];
} D_80800B22_chdinoswitches[];
typedef struct {
    u16 flag;
    u8 pad_0[0x12];
} DinoSwitchFlag;
extern s32 func_80101E14(Actor *, f32);
extern void func_80101EE4(Actor *, f32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern u16 D_80800B2C_chdinoswitches[];
s32 func_80800108_chdinoswitches();

int chdinoswitches_entrypoint_0()
{
    return (int) &D_80800C30_chdinoswitches;
}

int chdinoswitches_entrypoint_1()
{
    return (int) &D_80800C78_chdinoswitches;
}

int chdinoswitches_entrypoint_2(void)
{
    return (int) &D_80800CC0_chdinoswitches;
}

int chdinoswitches_entrypoint_3()
{
    return (int) D_80800D08_chdinoswitches;
}

void func_80800030_chdinoswitches(u8 *actor)
{
    s32 row;

    row = func_80800108_chdinoswitches();
    *(s32 *) ((char *) actor + 0x18) = row;
    if ((row == 4) && ((func_800DA298(0x676U) != 0) || (func_800D0B68(0x18, 0) != 0))) {
        func_800DA544(0xA10);
    }
    _chswitch_entrypoint_7(actor,
                           *(u16 *) ((char *) ((row * 0x14) + D_80800B20_chdinoswitches) + 2));
    _chswitch_entrypoint_8(actor,
                           *(s32 *) ((char *) ((row * 0x14) + D_80800B20_chdinoswitches) + 4));
    if (*(s32 *) ((char *) actor + 0x18) == 4) {
        if (func_800DA298(*(u16 *) ((char *) ((row * 0x14) + D_80800B20_chdinoswitches) + 2)) !=
            0) {
            func_80103110(actor, 0);
        }
    } else {
        _chswitch_entrypoint_9(actor);
    }
}

s32 func_80800108_chdinoswitches(actor)
ALCSPlayer *actor;
{
    ALCSPlayer *same_actor;
    s32 map_id;
    s32 slot;
    u16 *entry;
    map_id = func_800EA05C();
    if ((map_id == *(u16 *) D_80800B44_chdinoswitches) &&
        (((u32) (u16) *(u16 *) ((char *) actor + 0x76) >> 7) ==
         *(u16 *) D_80800B34_chdinoswitches)) {
        return 1;
    }
    if ((map_id == *(u16 *) D_80800B58_chdinoswitches) &&
        (((u32) (u16) *(u16 *) ((char *) actor + 0x76) >> 7) ==
         *(u16 *) D_80800B48_chdinoswitches)) {
        return 2;
    }
    same_actor = actor;
    if ((map_id == *(u16 *) D_80800B6C_chdinoswitches) &&
        (((u32) (u16) *(u16 *) ((char *) same_actor + 0x76) >> 7) ==
         *(u16 *) D_80800B5C_chdinoswitches)) {
        return 3;
    }
    if ((!actor && 1) && 1) {
    }
    slot = 4;
    entry = (u16 *) D_80800B70_chdinoswitches;
loop_10:
    if ((map_id == *(u16 *) (entry + 8)) &&
        (((u32) (u16) *(u16 *) ((char *) actor + 0x76) >> 7) == *(u16 *) (entry + 0))) {
        return slot;
    }

    if ((map_id == *(u16 *) (entry + 18)) &&
        (((u32) (u16) *(u16 *) ((char *) actor + 0x76) >> 7) == *(u16 *) (entry + 10))) {
        return slot + 1;
    }
    if ((map_id == *(u16 *) (entry + 28)) &&
        (((u32) (u16) *(u16 *) ((char *) actor + 0x76) >> 7) == *(u16 *) (entry + 20))) {
        return slot + 2;
    }
    if ((map_id == *(u16 *) (entry + 38)) &&
        (((u32) (u16) *(u16 *) ((char *) actor + 0x76) >> 7) == *(u16 *) (entry + 0x1E))) {
        return slot + 3;
    }
    slot += 4;
    entry += 0x28;
    if (slot == 0xC) {
        return 0;
    }
    goto loop_10;
}

void func_80800270_chdinoswitches(Actor *actor)
{
    s32 row;

    row = actor->actorData[0];
    func_801032B0(actor, *(u16 *) ((u8 *) D_80800B28_chdinoswitches + row * 0x14),
                  *(u16 *) ((u8 *) actor->unk0 + 0x16));
}

s32 func_808002B0_chdinoswitches(Actor *actor, s32 msg, s32 arg)
{
    s32 pad[2];
    Unk80132ED0 *linked;
    s32 row;

    switch (msg) {
        case 7:
            linked = actor->unk3C;
            if (linked)
                func_8010114C(linked, msg, 0);
            break;
        case 0x95:
            _subaddiefind_entrypoint_10(actor, 0x364, actor->unk74_7);
            func_80800270_chdinoswitches(actor);
            return _chswitch_entrypoint_10(actor, msg, arg);
        case 0x99:
            if (((DinoSwitchFlags *) actor)->local_0)
                row = actor->actorData[0];
            else
                row = func_80800108_chdinoswitches();
            switch (((E20 *) D_80800B28_chdinoswitches)[row].f[0]) {
                case 0x7B8:
                case 0x7B9:
                case 0x942:
                    func_80101074(D_8011A270);
                    return 1;
                default:
                    func_80101074(D_8011A248);
                    return 1;
            }
        default:
            return _chswitch_entrypoint_10(actor, msg, arg);
    }
    return 1;
}

s32 func_808003E8_chdinoswitches(Actor *actor, s32 msg, s32 arg)
{
    s32 unk_0;
    s32 unk_1;

    switch (msg) {
        case 7:
            if (!func_800D0B68(0x18, 0)) {
                func_80103110(actor, 0);
                func_8010114C(actor->unk3C, 7, 0);
                func_800CE8D8(0, 35.0f, 0x23);
                func_800CE88C(0, 1);
                func_800CE928(0, _chdinoswitches_entrypoint_4, 0);
            }
            break;
        case 0x91:
            if (func_800F64A4(arg, 0x40000) && func_800CEAA8(0) &&
                func_800CE95C(0) == _chdinoswitches_entrypoint_4) {
                func_800CE8D8(0, 35.0f, 0x23);
                func_800CE928(0, _chdinoswitches_entrypoint_4, 0);
            }
            return _chswitch_entrypoint_10(actor, msg, arg);
        case 8:
            func_80103110(actor, 1);
            break;
        case 0x99:
            func_80101074(D_8011A248);
            break;
        case 0xB7:
            if (!(arg & 0xFFFF)) {
                if (((arg >> 16) & 0xFFFF) == 0x18) {
                    if (func_800CEAA8(0) && func_800CE95C(0) == _chdinoswitches_entrypoint_4) {
                        func_800CE928(0, NULL, 0);
                        func_800CE88C(0, 0);
                    }
                    if (actor->unk3C)
                        func_8010114C(actor->unk3C, 7, 0);
                }
            }
            break;
        case 0x95:
            _subaddiefind_entrypoint_10(actor, 0x364, actor->unk74_7);
            _chswitch_entrypoint_10(actor, msg, arg);
            if (func_800DA298(
                    *(u16 *) ((u8 *) D_80800B22_chdinoswitches + actor->actorData[0] * 20)))
                func_80103110(actor, 0);
            break;
        default:
            return _chswitch_entrypoint_10(actor, msg, arg);
    }
    return 1;
}

int chdinoswitches_entrypoint_4(s32 param_0, s32 param_1)
{
    s32 actor_364;
    s32 actor_433;
    if (func_800EA05C() == 0x112) {
        actor_364 = _subaddiefind_entrypoint_11(0x364, 0x35);
        actor_433 = _subaddiefind_entrypoint_11(0x433, 0x35);
        func_80101180(0x433, 8, 0);
        func_8010108C(actor_364, 8, 0);
        func_80103110(actor_433, 1);
        return;
    }
    if (func_800DA298(0xA3A) == 0) {
        _glcutDll_entrypoint_6(0x112, 0x37);
        return;
    }
    func_800DA524(0xA10);
    func_800DA524(0x676);
}

void func_80800714_chdinoswitches(Actor *actor)
{
    s32 *row_ptr = (s32 *) ((char *) actor + 0x18);
    *(s32 *) ((char *) actor + 0x18) = func_80800108_chdinoswitches();
    if (func_800DA298(D_80800B22_chdinoswitches[*(s32 *) ((char *) actor + 0x18)].field)) {
        func_80102424(actor, 3);
        func_80101EE4(actor, 0.3f);
        func_8010A570(actor);
    }
    if (*row_ptr == 3) {
        func_80109EEC(actor, 0x44);
    }
}

void func_808007A0_chdinoswitches(Actor *actor)
{
    if (actor->unk70_10 == 2 && func_80101E14(actor, 0.3f)) {
        func_800DA544(((DinoSwitchFlag *) D_80800B22_chdinoswitches)[actor->actorData[0]].flag);
        func_80102424(actor, 3);
        func_80101EE4(actor, 0.3f);
        func_80103110(actor, 0);
        if (actor->unk3C != NULL)
            func_8010114C(actor->unk3C, 7, 0);
    }
}

int func_80800848_chdinoswitches(Actor *actor, s32 msg, u8 arg)
{
    switch (msg) {
        case 0x40:
            _gcaudiolist_entrypoint_0(0);
            func_80102424(actor, 2);
            func_8010A570(actor);
            func_80103110(actor, 1);
            goto block_6;
        case 0x95:
            _subaddiefind_entrypoint_10(actor, 0x364,
                                        (u32) (u16) *(u16 *) ((char *) actor + 0x76) >> 7);
            func_80800270_chdinoswitches(actor);
            goto block_6;
        default:
            return 0;
    }
block_6:
    return 1;
}

void func_808008F0_chdinoswitches(Actor *actor)
{
    u8 *entry;
    s32 row = func_80800108_chdinoswitches();
    s32 unk_0;

    actor->actorData[0] = row;
    entry = D_80800B20_chdinoswitches + row * 20;
    if (row == 4 && func_800D0B68(0x18, 0))
        func_800DA544(*(u16 *) (entry + 18));
    if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, actor->scale * 350.0f,
                                 *(u16 *) (entry + 14), *(u16 *) (entry + 18))) {
        _chdoormake_entrypoint_5(actor, 2.75f);
        _chdoormake_entrypoint_8(actor, 14);
        unk_0 = *(s16 *) (entry + 10);
        if (unk_0 != -1)
            _chdoormake_entrypoint_9(actor, 0, unk_0, 0x10);
    }
    switch (actor->actorData[0]) {
        case 3:
            func_8010A800(actor, 0);
            break;
        case 4:
            _chdoormake_entrypoint_9(actor, 1, 0x23, 0x810);
            _chdoormake_entrypoint_12(actor, 1, 0x37);
            _chdoormake_entrypoint_10(actor, 1, 0xA3A);
            _chdoormake_entrypoint_10(actor, 0, 0xA23);
    }
}

void func_80800A48_chdinoswitches(actor) Actor *actor;
{
    s32 row;

    row = actor->actorData[0];
    func_80103140(actor, *(u16 *) ((u8 *) D_80800B2C_chdinoswitches + row * 0x14),
                  *(u16 *) ((u8 *) actor->unk0 + 0x16));
}

s32 func_80800A88_chdinoswitches(u8 *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0xB:
            if ((*(s32 *) ((s8 *) actor + 0x18) == 4) && (arg == 0x23) &&
                (_glcutDll_entrypoint_19(0x37) != 0)) {
                _glcutDll_entrypoint_17();
            }
            return 3;
        case 0x95:
            func_80800A48_chdinoswitches();

        default:
            return _chdoor_entrypoint_1(actor, msg, arg);
    }
}

extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_80108ED0();
extern void _bsbtrot_entrypoint_8();
extern void _chdoor_entrypoint_0();
u8 D_80800B20_chdinoswitches[8] = {0x0, 0x32, 0x0, 0xC6, 0x0, 0x0, 0x4, 0x0};
u16 D_80800B28_chdinoswitches[2] = {0x7B9, 0x5};
u16 D_80800B2C_chdinoswitches[4] = {0x7C4, 0x821, 0x11A, 0xC6};
u8 D_80800B34_chdinoswitches[16] = {0x0, 0x33, 0x0, 0xC7, 0x0, 0x0,  0x2, 0x0,
                                    0x7, 0xB8, 0x0, 0x7,  0x7, 0xC4, 0x8, 0x21};
u8 D_80800B44_chdinoswitches[4] = {0x1, 0x1A, 0x0, 0xC7};
u8 D_80800B48_chdinoswitches[16] = {0x0, 0x34, 0x0, 0xC8, 0x0, 0x0,  0x0, 0x1,
                                    0x9, 0x42, 0x0, 0x9,  0x7, 0xC4, 0x8, 0x21};
u8 D_80800B58_chdinoswitches[4] = {0x1, 0x1A, 0x0, 0xC8};
u8 D_80800B5C_chdinoswitches[16] = {0x0, 0x34, 0x1, 0x80, 0x0, 0x0,  0x0, 0x0,
                                    0x9, 0x48, 0x0, 0x4,  0x7, 0xC4, 0x8, 0x21};
u8 D_80800B6C_chdinoswitches[4] = {0x1, 0x12, 0x1, 0x80};
u8 D_80800B70_chdinoswitches[160] = {
    0x0,  0x35, 0xA,  0x10, 0x0,  0x4,  0x0,  0x0,  0x7,  0x84, 0x0,  0x20, 0x7,  0xC4, 0x18, 0x82,
    0x1,  0x12, 0x6,  0x76, 0x0,  0x37, 0x3,  0x2A, 0x0,  0x0,  0x0,  0x0,  0x7,  0xCE, 0x0,  0x3F,
    0x7,  0xC4, 0x8,  0x21, 0x1,  0x12, 0x3,  0x2A, 0x0,  0x32, 0x1,  0x6A, 0xFF, 0xFF, 0xFF, 0xFF,
    0x7,  0xCD, 0xFF, 0xFF, 0x7,  0xC4, 0x8,  0x21, 0x1,  0x15, 0x1,  0x6A, 0x0,  0x32, 0x1,  0x84,
    0xFF, 0xFF, 0xFF, 0xFF, 0x7,  0xCD, 0xFF, 0xFF, 0x7,  0xC4, 0x8,  0x21, 0x1,  0x19, 0x1,  0x84,
    0x0,  0x33, 0x1,  0x85, 0xFF, 0xFF, 0xFF, 0xFF, 0x7,  0xCD, 0xFF, 0xFF, 0x7,  0xC4, 0x8,  0x21,
    0x1,  0x19, 0x1,  0x85, 0x0,  0x32, 0x1,  0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0x7,  0xCD, 0x0,  0x17,
    0x7,  0xC4, 0x8,  0x21, 0x1,  0x16, 0x1,  0x83, 0x0,  0x32, 0x1,  0x82, 0xFF, 0xFF, 0xFF, 0xFF,
    0x7,  0xCD, 0xFF, 0xFF, 0x7,  0xC4, 0x8,  0x21, 0x0,  0xBB, 0x1,  0x82, 0x0,  0x32, 0x0,  0xE3,
    0xFF, 0xFF, 0xFF, 0xFF, 0x7,  0xCD, 0x0,  0x8,  0x7,  0xC4, 0x8,  0x21, 0x0,  0xC5, 0x0,  0xE3};
u32 D_80800C10_chdinoswitches[8] = {0x0, 0x0, 0x0, 0x0, 0x3FA00000, 0x8E0002, 0x3FA00000, 0x8E0004};
int D_80800C30_chdinoswitches[18] = {0x3430130,
                                     -0xFFFF,
                                     0x0,
                                     (u32) _chswitch_entrypoint_6,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x40000808,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800030_chdinoswitches,
                                     (u32) func_80107C2C,
                                     -0x7FF3D3EE,
                                     (u32) func_808002B0_chdinoswitches,
                                     0x0};
int D_80800C78_chdinoswitches[18] = {0x3430433,
                                     0x7840001,
                                     0x0,
                                     (u32) _chswitch_entrypoint_6,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x40000808,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800030_chdinoswitches,
                                     (u32) func_80107C2C,
                                     -0x7FF3D3EE,
                                     (u32) func_808003E8_chdinoswitches,
                                     0x0};
int D_80800CC0_chdinoswitches[18] = {0x9C0434,
                                     0x7490001,
                                     (u32) &D_80800C10_chdinoswitches,
                                     (u32) func_808007A0_chdinoswitches,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x808,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_80800714_chdinoswitches,
                                     (u32) func_80107C2C,
                                     (u32) _bsbtrot_entrypoint_8,
                                     (u32) func_80800848_chdinoswitches,
                                     0x0};
s32 D_80800D08_chdinoswitches[18] = {0xAC0364,
                                     0x7C40001,
                                     0x0,
                                     (u32) _chdoor_entrypoint_0,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x40020800,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_808008F0_chdinoswitches,
                                     (u32) func_80107C2C,
                                     -0x7FF7D3EE,
                                     (u32) func_80800A88_chdinoswitches,
                                     0x0};
