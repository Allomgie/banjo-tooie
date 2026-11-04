#include "common.h"
#include "types.h"
#include "macros.h"

#define OD(n) (((f32 *) param_0->actorData)[n])
extern void func_800EF3DC(f32 *, f32 *);
extern s32 func_800AA194(void);
extern void _sumultiscore_entrypoint_1(s32 *, s32 *, s32);
extern void func_800AA220(s32, s32);
extern void _gczoombox_entrypoint_27(s32, void *);
extern int func_80101E4C(Actor *, void *);
extern s32 func_800D9078(f32 *);
extern s32 func_80016B30(s32, s32);
extern s32 func_800AA0D0(void);
extern void func_8010114C(Unk80132ED0 *, s32, s32);
extern void func_800FFAB0(Actor *);
extern void func_800E39A8(f32 *, f32 *);
extern void func_80102EC0(), func_80107C2C(), func_80800D74_chgameselect();
typedef struct {
    s32 (*local_3)(Actor *);
    void (*local_4)(Actor *);
    void *unk8;
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
    void (*local_0)(Actor *, s32 *);
    s32 local_1;
    s32 local_2;
} GameSelectCallback61;
extern GameSelectCallback61 D_80807DD0_chgameselect[];
typedef struct {
    s16 sound;
    s16 unused;
} GameSelectSound;
extern GameSelectSound D_80807DB0_chgameselect[];
extern void _gcstatusDll_entrypoint_6();
extern void _gczoombox_entrypoint_18();
extern void _gczoombox_entrypoint_16();
extern void _gczoombox_entrypoint_9();
extern void _gczoombox_entrypoint_11();
extern void _cadbfunc_entrypoint_0(f32 *);
extern void _cadbfunc_entrypoint_2(f32 *);
extern void _gcfrontend_entrypoint_7(void);
extern void _gcfrontend_entrypoint_8(void);
extern void _gcnewoption_entrypoint_10();
extern s32 _gcnewoption_entrypoint_20(s32, s32);
extern void _gcnewoption_entrypoint_35(void);
extern void _gcnewoption_entrypoint_36();
extern int _gcnewoption_entrypoint_37(int, int);
extern void _gcnewoption_entrypoint_4();
extern void _gcnewoption_entrypoint_40(s32, s32, s32, s32, f32, f32);
extern void _gcnewoption_entrypoint_42(s32, f32);
extern void _gcnewoption_entrypoint_8();
extern s32 _gcstatusDll_entrypoint_10(void);
extern void _gczoombox_entrypoint_26(void *, s32, f32, f32, s32);
extern void _gczoombox_entrypoint_32(void *);
extern int _gczoombox_entrypoint_8();
extern void *_gldbstring_entrypoint_0();
extern u8 *_gldbstring_entrypoint_1();
extern void _gldbstring_entrypoint_2();
extern void func_80016BDC(s32);
extern void func_800A5800(s32);
extern void func_800AA16C(void);
extern void func_800AA1A0(void);
extern void func_800C9DAC(f32, void (*)(void));
extern void func_800C9E20(f32, u32 *, u32, u32);
extern void func_800C9F48(f32, void *, s32);
extern f32 func_800D8FF8(void);
extern void func_800E3980(f32 *);
extern void func_800E39D8(f32 *, f32 *);
extern void func_800EE7B4(f32 *, f32 *, f32 *, f32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800F16AC(f32 *, f32 *, f32 *, f32);
extern void *func_80100074(Actor *, s32, s32);
extern void *func_80100094(Actor *, u32);
extern int func_80101180(s32, s32, s32);
extern Actor *func_80106790();
extern void heap_free();
extern int D_80807FD8_chgameselect[];
extern s32 D_8011A3F0;
extern Actor *func_80108528(s32, void *, s32, Actor **);
typedef struct {
    void *unk50;
} ActorLocal_CC_5B90;
typedef struct {
    u8 pad_0[0x18];
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    Unk80132ED0 *local_4;
    s32 local_5;
} GameSelectActor1838;
typedef struct Mass44MenuCallback {
    s32 (*local_0)(Actor *, s32, s32 *);
    u8 pad_0[0x30];
} Mass44MenuCallback;
extern Mass44MenuCallback D_80807DD8_chgameselect[];
extern s16 D_80807DB2_chgameselect[][2];
typedef struct {
    s32 (*local_0)(Actor *, s32, s32);
    u8 pad_0[0x30];
} GameSelectRecord;
extern GameSelectRecord D_80807DE0_chgameselect[];
typedef struct {
    void (*fn)(s32, s32, s32, Actor *);
    u8 pad4[0x30];
} GSStateEntry;
extern GSStateEntry D_80807DE4_chgameselect[];
typedef struct {
    void (*fn)(Actor *, s32, s32, Actor *);
    u8 pad_0[48];
} GsDispatchEnt;
extern GsDispatchEnt D_80807DE8_chgameselect[];
typedef struct {
    void (*update)(Actor *);
    u8 unused[48];
} GameSelectUpdateRecord;
extern GameSelectUpdateRecord D_80807DEC_chgameselect[];
extern u8 D_80807DFC_chgameselect[];
extern u8 D_80807E00_chgameselect[];
extern int D_80808038_chgameselect[];
typedef struct {
    u8 data[12];
} GsEntry12;
typedef struct {
    u8 pad0[0x74];
    u32 unk74_22 : 10;
    u32 unk74_21 : 1;
    u32 unk74_0 : 21;
} GsBits74;
typedef struct {
    u8 pad0[0x6E];
    u16 unk6E_9 : 7;
    u16 unk6E_0 : 9;
} GsBits6E;
extern void func_80101038();
typedef struct {
    u8 pad0[0x65];
    u8 unk65_5 : 3;
    u8 unk65_4 : 1;
    u8 unk65_0 : 4;
} GameSelectActor;
extern void *D_808080C8_chgameselect;
typedef struct {
    u16 unk0;
    s16 unk2;
} GameSelectPair;
typedef struct {
    s16 unk0;
    u16 unk2;
} GameSelectPair2;
extern GameSelectPair D_808080A8_chgameselect[];
extern GameSelectPair2 D_808080AA_chgameselect[];
typedef struct {
    u8 pad[0x7A];
    u16 top : 2;
    u16 rest : 14;
} GameSelectTop;
extern void func_800DF7E8(u8);
typedef struct {
    u8 pad_0[0x18];
    u16 local_0 : 11;
    u16 pad_1 : 5;
} Mass63GameSelectMarker;
typedef union {
    u32 local_0;
    struct {
        s16 local_1;
        s16 local_2;
    } local_3;
} GameSelectEvent;
extern s32 D_80808298_chgameselect[];
extern int D_808082E0_chgameselect[];
extern void func_800E6A58();
typedef struct {
    int unk18;
    int unk1C;
    void *unk28;
    int *unk30;
} ChGameSelectState;
extern int D_80808328_chgameselect[];
typedef struct {
    s16 local_0;
    s16 local_1;
} GameSelectInputEvent;
typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s16 unk4;
} GameSelectItem1213;
typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} GameSelectActorCount1213;
extern void _gcnewoption_entrypoint_12(void *, s32, s16);
extern s32 D_80808370_chgameselect[];
extern s32 D_808083A0_chgameselect[];
extern s32 D_808083C8_chgameselect[];
typedef union {
    s32 local_0;
    struct {
        s16 local_0;
        s16 local_1;
    } local_1;
} GameSelectPacked1581;
extern s32 D_808083D0_chgameselect[];
extern s32 D_808083D8_chgameselect[];
extern s16 D_808083E0_chgameselect[];
extern s16 D_808083E8_chgameselect[][3];
typedef struct {
    u8 count;
    u8 unk1;
    u8 unk2;
    s8 unk3;
    s16 unk4;
    s16 unk6;
    u8 *unk8;
} GameSelEntry;
extern GameSelEntry D_80808424_chgameselect[];
extern u8 D_808083FC_chgameselect[];
extern u8 D_8080840C_chgameselect[];
extern u8 D_80808404_chgameselect[];
extern u8 D_80808405_chgameselect;
extern u8 D_80808406_chgameselect;
extern u8 D_80808407_chgameselect;
extern u8 D_8080841C_chgameselect[];
extern int D_808084B4_chgameselect[];
typedef struct {
    void *local_0[4];
    void *local_1[4];
    void *local_2;
} GameSelectResources1358;
typedef struct {
    s32 id;
    s32 score;
    s32 rank;
} RankEntry;
typedef struct {
    s32 zoom[4];
    s32 slot[4];
    u8 pad20[4];
    s16 unk24;
} RankData;
extern u8 D_808084FC_chgameselect[];
extern void _sumultiscore_entrypoint_0(s32 *, s32 *, s32);
extern s32 func_800AA180;
extern s32 D_80808504_chgameselect[];
typedef struct {
    s16 a, b;
} S16Pair;
typedef struct GameSelectDispatch {
    u8 pad_0[0x14];
    void (*local_0)();
    u8 pad_1[0x10];
    void (*local_1)();
    void (*local_2)();
    u8 pad_2[4];
} GameSelectDispatch;
extern GameSelectDispatch D_80807DC8_chgameselect[];
typedef struct {
    u8 pad_0[0x60];
    Vec3f local_0[8];
    u8 local_1[8];
} GameSelectState521;
extern f32 mlAbsF(f32);
extern void func_80016068(s32, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern f32 func_800DC178(f32, f32);
extern int func_800C3F48();
extern int func_80101E14(Actor *, f32);
extern u8 D_80808288_chgameselect[];
extern u8 D_80808110_chgameselect[];
extern u8 D_80808270_chgameselect[];
extern u8 D_80808280_chgameselect[];
extern void func_80015E80();
extern void _gcnewoption_entrypoint_43();
typedef struct {
    u8 local_0[4];
    f32 local_1[4];
} Mass63GameSelectInput;
extern void _gczoombox_entrypoint_4();
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_80101FDC(Actor *, s32);
void func_80800478_chgameselect();
void func_808005D4_chgameselect();
void func_808006A0_chgameselect();
void func_808013C8_chgameselect();
void func_8080145C_chgameselect(f32 *param_0, f32 param_1, f32 *param_2, f32 *param_3);
int func_808015DC_chgameselect();
int func_80801658_chgameselect();
void func_80801714_chgameselect();
void func_80801D74_chgameselect();
int func_80802070_chgameselect();
void func_808020CC_chgameselect();
void func_8080218C_chgameselect();
int func_80802620_chgameselect();
void func_80802640_chgameselect();
void func_808026C8_chgameselect();
int func_80802780_chgameselect();
void func_808030EC_chgameselect();
void func_80803604_chgameselect();
int func_80803738_chgameselect();
void func_80803D00_chgameselect();
s32 func_80803DCC_chgameselect();
int func_80803E40_chgameselect();
void func_80803E94_chgameselect();
int func_8080401C_chgameselect();
int func_8080407C_chgameselect();
int func_808040DC_chgameselect();
int func_80804948_chgameselect();
s32 func_8080499C_chgameselect();
int func_808049E8_chgameselect();
int func_80804A38_chgameselect();
void func_80804C30_chgameselect();
void func_80804D30_chgameselect();
void func_80805310_chgameselect();
int func_80805BA0_chgameselect();
s32 func_80805ECC_chgameselect();
void func_80806068_chgameselect();
extern void func_80806218_chgameselect(s32, s32, s32, s32);
int func_808062A8_chgameselect();
s32 func_808065C0_chgameselect();
void func_808065F4_chgameselect();
s32 func_808066CC_chgameselect();
void func_80806744_chgameselect();
s32 func_808068E8_chgameselect();
void func_808069C8_chgameselect();
int func_80806A30_chgameselect();
s32 func_80806AA8_chgameselect();
extern void func_80806AF4_chgameselect(void *, s32, s32);
void func_8080086C_chgameselect();
s32 func_808014F0_chgameselect();
int func_808034BC_chgameselect();
int func_80803D60_chgameselect();
void func_808051B4_chgameselect();
void func_808075D0_chgameselect();
void func_80807A10_chgameselect();
extern void func_801018A4(), func_80102EC0(), func_80107C2C(), func_80801AC4_chgameselect();

int chgameselect_entrypoint_0()
{
    return (int) &D_80807FD8_chgameselect;
}

void func_80803638_chgameselect();

void func_8080000C_chgameselect(u8 *actor)
{
    s32 unk_0;
    s32 i;

    func_80016BDC(4);
    unk_0 = func_800D395C();
    _gcfrontend_entrypoint_0();
    if (func_800AA0B8() != 0) {
        *(u8 *) ((s8 *) actor + 0x79) = (u8) ((*(u8 *) ((s8 *) actor + 0x79) & 0xFF0F) | 0x50);
        *(u16 *) ((s8 *) actor + 0x6E) = (u16) ((*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00) | 5);
    } else if (unk_0 != 0) {
        *(u8 *) ((s8 *) actor + 0x79) = (u8) ((*(u8 *) ((s8 *) actor + 0x79) & 0xFF0F) | 0x70);
        *(u16 *) ((s8 *) actor + 0x6E) = (u16) ((*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00) | 7);
        func_800AA00C();
    } else {
        *(u8 *) ((s8 *) actor + 0x79) = (u8) (*(u8 *) ((s8 *) actor + 0x79) & 0xFF0F);
        *(u16 *) ((s8 *) actor + 0x6E) = (u16) ((*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00) | 1);
        func_800AA00C();
    }
    func_80803638_chgameselect();
    func_80108B04(actor, 0x4AB);
    i = 0;
    do {
        func_80108B04(actor, i);
        i += 1;
    } while (i != 8);
    func_80108B04(actor, 0x4AA);
    func_80108B04(actor, 0x4A9);
    func_80108B04(actor, 0x4AC);
    func_80108B04(actor, 0x4B9);
    *(s32 *) ((s8 *) actor + 0x34) = 0;
    *(f32 *) ((s8 *) actor + 0x58) = 0.1f;
    (*(s32 *) ((s8 *) (actor) + (0x50))) = heap_alloc(0x100);
}

void func_80803C80_chgameselect();

s32 func_808016E8_chgameselect();

void func_8080015C_chgameselect(Actor *actor)
{
    s32 unk_0;

    switch (actor->unk70_10) {
        case 1:
            unk_0 = func_80803E40_chgameselect();
            if (unk_0 && _gcstatusDll_entrypoint_10() != unk_0)
                _gcstatusDll_entrypoint_2(unk_0);
            break;
        case 9:
            if (func_800D9078(&actor->unk58)) {
                if (D_8011A3F0)
                    func_80803C80_chgameselect();
                func_808016E8_chgameselect(actor->actorData[4], actor->unk79_4);
                func_80800478_chgameselect(actor, actor->unk6C_0);
            }
            break;
    }
}

// TU-NOTE: this .bss is defined in C ahead of its first use: IDO places .bss objects used before
// their definition first, the rest in definition order. The _pad objects fill bytes no code names.
s32 B_80808550_chgameselect;
u8 B_80808550_chgameselect_pad[4];
s32 B_80808558_chgameselect;
RankEntry B_80808560_chgameselect;
u8 B_80808560_chgameselect_pad[4];
s32 B_80808570_chgameselect;
u8 B_80808578_chgameselect[16];
s32 B_80808588_chgameselect[2];
u8 B_80808590_chgameselect[16];

// Controller actor message handler; message 0x3D spawns the menu children.
s32 func_80800228_chgameselect(Actor *this, s32 msg, s32 arg)
{
    Actor *child;

    switch (msg) {
        case 0x95:
            func_80803D00_chgameselect(0, 0);
            break;
        case 0x3D:
            if (arg >= 9) {
                child = func_80108528(arg, B_80808578_chgameselect, 0, &this);
                child->unk79_4 = this->unk79_4;
                switch (arg) {
                    default:
                        this->unk3C = child->unk0;
                        break;
                    case 0x4AB:
                        *(Unk80132ED0 **) &this->actorData[4] = child->unk0;
                        child->scale = this->scale;
                        break;
                    case 0x4AA:
                        *(Unk80132ED0 **) &this->actorData[5] = child->unk0;
                        break;
                    case 0x4A9:
                        *(Unk80132ED0 **) &this->actorData[3] = child->unk0;
                        child->unk64_20 = 1;
                        break;
                    case 0x4AC:
                        *(Unk80132ED0 **) &this->actorData[6] = child->unk0;
                        break;
                    case 0x1E8:
                        *(Unk80132ED0 **) &this->actorData[7] = child->unk0;
                        break;
                }
            } else {
                child = func_80108528(0x4A8, B_80808578_chgameselect, 0, &this);
                child->unk79_4 = arg;
                func_808020CC_chgameselect(child, func_80803D60_chgameselect(arg));
            }
            child->unk3C = this->unk0;
            break;
        case 0xA:
            func_808005D4_chgameselect(this, arg);
            break;
        case 7:
            func_808006A0_chgameselect(this, arg);
            break;
        case 8:
            func_8080086C_chgameselect(this, arg);
            break;
        case 0x23:
            if (this->unk70_10 == 5) {
                func_808065F4_chgameselect(this);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808036D8_chgameselect();

void func_80800440_chgameselect(Actor *actor)
{
    ActorLocal_CC_5B90 *state;
    state = (ActorLocal_CC_5B90 *) &actor->unk50;
    func_808036D8_chgameselect();
    if (state->unk50 != 0) {
        heap_free(state->unk50);
    }
}

// Switches the menu state machine: runs the old state's exit, then the new state's enter callback.
void func_80800478_chgameselect(actor, new_state) Actor *actor;
s32 new_state;
{
    s32 text_id = -1;
    s32 state;
    s32 (*enter_fn)(Actor *);

    state = actor->unk70_10;
    if (new_state != state) {
        if (D_80807DD0_chgameselect[state].local_4)
            D_80807DD0_chgameselect[state].local_4(actor);
        func_80101FDC(actor, new_state);
        ((GameSelectActor1838 *) actor)->local_0 = 0;
        ((GameSelectActor1838 *) actor)->local_1 = ((GameSelectActor1838 *) actor)->local_2 =
            -1;
        state = actor->unk70_10;
        enter_fn = D_80807DD0_chgameselect[state].local_3;
        if (enter_fn) {
            text_id = enter_fn(actor);
            state = actor->unk70_10;
        }
        switch (state) {
            case 8:
                func_80802780_chgameselect(((GameSelectActor1838 *) actor)->local_3, 0);
                func_8080218C_chgameselect(actor->unk79_4, 1);
                func_80801658_chgameselect(((GameSelectActor1838 *) actor)->local_4, 1);
                func_80801714_chgameselect(((GameSelectActor1838 *) actor)->local_4, 0);
                break;
            case 1:
                text_id = func_80803DCC_chgameselect(actor->unk79_4);
                func_80803D00_chgameselect(0, 1);
                break;
        }
        if (text_id != -1)
            func_808026C8_chgameselect(((GameSelectActor1838 *) actor)->local_5, text_id);
    }
}

void func_808036B8_chgameselect();

void func_80803678_chgameselect();

// Matching: the line breaks in this function are needed for the match.
void func_808005D4_chgameselect(actor, slot) Actor *actor; s32 slot;
{
    s32 state;

    actor->unk79_4 = slot;
    state = actor->unk70_10;
    if (state == 1 || state == 9) {
        switch (actor->unk79_4) {
            case 0:
            case 1:
            case 2:
            func_80803678_chgameselect(actor->unk79_4);
            break;
            default:
            func_808036B8_chgameselect(actor->unk79_4);
            break;
        }
        func_80802640_chgameselect(actor->actorData[5], D_80807DB0_chgameselect[actor->unk79_4].sound, 0);
        func_808026C8_chgameselect(actor->actorData[5], func_80803DCC_chgameselect(actor->unk79_4));
    }
}

void func_80803C60_chgameselect();

s32 func_80803718_chgameselect();

s32 func_808036F8_chgameselect();

// Matching: the line breaks in this function are needed for the match.
void func_808006A0_chgameselect(actor, item) Actor *actor; s32 item;
{
    s32 text_id;
    s32 handled;
    text_id = -1;
    handled = 0;
    if (D_80807DD8_chgameselect[actor->unk70_10].local_0) handled = D_80807DD8_chgameselect[actor->unk70_10].local_0(actor, item, &text_id);
    if (actor->unk70_10 == 1) {
        switch (item) {
            case 3:
            if (!func_80803718_chgameselect()) text_id = 5;
            else if (func_808036F8_chgameselect(0) && func_808036F8_chgameselect(1) && func_808036F8_chgameselect(2)) text_id = 7;
            break;
            case 4:
            if (!func_80803718_chgameselect()) text_id = 4;
            break;
            case 5:
            if (!func_80803D60_chgameselect(item)) text_id = 0;
            else if (func_80803E40_chgameselect() < 2) text_id = 0x23;
            break;
            case 7:
            if (!func_80803D60_chgameselect(item)) text_id = 0;
            break;
        }
        if (text_id != -1) handled = 1;
        else func_80800478_chgameselect(actor, D_80807DB2_chgameselect[actor->unk79_4][0]);
    }
    if (handled) func_80803C60_chgameselect();
    if (text_id != -1) func_808026C8_chgameselect(actor->actorData[5], text_id);
}

void func_8080086C_chgameselect(actor, item) Actor *actor;
s32 item;
{
    switch (actor->unk70_10) {
        case 1:
            func_80803D00_chgameselect(0, 3);
            break;
        case 2:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        default:
            func_80800478_chgameselect(actor, 1);
            break;
    }
}

// Calls the current state's callback from table D_80807DE0 and shows the returned text.
void func_808008D0_chgameselect(Actor *actor, s32 arg1, s32 arg2)
{
    s32 (*callback)(Actor *, s32, s32);
    s32 text_id;
    text_id = -1;
    callback = D_80807DE0_chgameselect[actor->unk70_10].local_0;
    if (callback != NULL) {
        text_id = callback(actor, arg1, arg2);
    }
    if (text_id != -1) {
        func_808026C8_chgameselect((void *) actor->actorData[5], text_id);
    }
}

// Calls the current state's callback from table D_80807DE4.
void func_80800944_chgameselect(Actor *actor, s32 arg1, s32 arg2)
{
    // Matching: `^ 0` makes the first argument a fresh value in a0, so actor lives on in the a3 copy.
    if (D_80807DE4_chgameselect[actor->unk70_10].fn != NULL) {
        D_80807DE4_chgameselect[actor->unk70_10].fn(((s32) actor ^ 0), arg1, arg2,
                                                      actor);
    }
    // Matching: the empty if keeps actor alive across the call.
    if (actor) {
    }
}

// Calls the current state's callback from table D_80807DE8.
void func_80800998_chgameselect(Actor *actor, s32 arg1, s32 arg2)
{
    // Matching: `^ 0` makes the first argument a fresh value in a0, so actor lives on in the a3 copy.
    if (D_80807DE8_chgameselect[actor->unk70_10].fn != NULL) {
        D_80807DE8_chgameselect[actor->unk70_10].fn(((s32) actor ^ 0), arg1, arg2,
                                                      actor);
    }
    // Matching: the empty if keeps actor alive across the call.
    if (actor) {
    }
}

// Per-frame update: current state's callback, or fall back to state 1.
void func_808009EC_chgameselect(Actor *actor)
{
    void (*update)(Actor *);

    update = D_80807DEC_chgameselect[actor->unk70_10].update;
    if (update != NULL) {
        update(actor);
    } else {
        func_80800478_chgameselect(actor, 1);
    }
}

void func_80800A4C_chgameselect(void *actor, s32 arg1, s32 arg2, s32 arg3)
{
    void (*callback)(void *, s32, s32, s32);
    callback = *(void (**)(void *, s32, s32, s32))(
        (char *) D_80807DFC_chgameselect +
        (((u32) *(u16 *) ((char *) actor + 0x72) >> 10) * 52));
    if (callback != 0) {
        callback(actor, arg1, arg2, arg3);
    }
}

void func_80800A9C_chgameselect(void *actor, s32 arg1, s32 arg2, s32 arg3)
{
    void (*callback)(void *, s32, s32, s32);
    callback = *(void (**)(void *, s32, s32, s32))(
        (char *) D_80807E00_chgameselect +
        (((u32) *(u16 *) ((char *) actor + 0x72) >> 10) * 52));
    if (callback != 0) {
        callback(actor, arg1, arg2, arg3);
    }
}

// Dispatches an event for the controller actor to the matching per-state handler.
void func_80800AEC_chgameselect(handle, arg1, arg2, event) s32 handle;
s32 arg1;
s32 arg2;
s32 event;
{
    Actor *actor = (Actor *) func_80106790(handle);
    switch (event) {
        case 0:
            D_80807DC8_chgameselect[actor->unk70_10].local_0(actor, arg1, arg2, event);
            break;
        case 3:
            func_80800998_chgameselect(actor, arg1, arg2);
            break;
        case 2:
            func_808009EC_chgameselect(actor);
            break;
        case 4:
            func_808008D0_chgameselect(actor, arg1, arg2);
            break;
        case 5:
            func_80800944_chgameselect(actor, arg1, arg2);
            break;
        case 6:
            func_80800A9C_chgameselect(actor, arg1, arg2, event);
            break;
        case 7:
            func_80800A4C_chgameselect(actor, arg1, arg2, event);
            break;
        case 0xFF:
            D_80807DC8_chgameselect[actor->unk70_10].local_1(actor, arg1, arg2, event);
            break;
        case 0xFC:
        case 0xFD:
        case 0xFE:
            D_80807DC8_chgameselect[actor->unk70_10].local_2(actor, arg1, arg2, event);
            break;
    }
}

void func_80800CA0_chgameselect(Unk80132ED0 *handle)
{
    s32 text_id;
    Actor *actor;

    text_id = -1;
    actor = func_80106790(handle);
    if (D_80807DD0_chgameselect[actor->unk70_10].local_0 != NULL) {
        D_80807DD0_chgameselect[actor->unk70_10].local_0(actor, &text_id);
    }
    if (text_id != -1) {
        func_808026C8_chgameselect(actor->actorData[5], text_id);
    }
}

s32 func_80800D3C_chgameselect()
{
    return ((u32) *(u16 *) ((char *) func_80106790() + 0x72) >> 10) != 9;
}

int chgameselect_entrypoint_1()
{
    return (int) &D_80808038_chgameselect;
}

void func_80800D74_chgameselect(actor) Actor *actor;
{
    u8 *data;

    data = func_80100094(actor, 0);
    func_800EFD24(actor->position);
    actor->rotation[0] = 45.0f;
    actor->rotation[2] = 45.0f;
    actor->rotation[1] = 60.0f;
    func_808015DC_chgameselect(actor->unk0, 0);
    actor->unk64_20 = 0;
    ((f32 *) actor->actorData)[7] = 1.0f;
    func_800EFA4C((f32 *) (data + 0xC8), 0.0f, 0.0f, 1.0f);
    func_800EF2A0((f32 *) (data + 0xC8));
    *(f32 *) (data + 0xD4) = 200.0f;
}

void func_80801338_chgameselect();

void func_80800E24_chgameselect(Actor *actor)
{
    GameSelectState521 *state;
    f32 dt;
    f32 stick[2];
    f32 scratch;

    state = func_80100094(actor, 0);
    dt = func_800D8FF8();
    if (func_80800D3C_chgameselect(actor->unk3C)) {
        if (actor->unk58 >= 0.0f) {
            actor->unk58 -= dt;
        }
        if (!actor->unk64_19 && actor->unk58 <= 0.0f) {
            func_80016068(0, stick);
            scratch = mlAbsF(stick[0]);
            if (mlAbsF(stick[1]) < scratch) {
                stick[1] = 0.0f;
            } else {
                stick[0] = 0.0f;
            }
            if (stick[0] < -0.1f && (actor->unk79_4 & 3)) {
                func_80801338_chgameselect(actor, -1);
            } else if (stick[0] > 0.1f && (actor->unk79_4 & 3) != 3) {
                func_80801338_chgameselect(actor, 1);
            }
            if (stick[1] < -0.1f && (actor->unk79_4 & 4) != 4) {
                func_808013C8_chgameselect(actor, actor->unk79_4 + 4);
            } else if (stick[1] > 0.1f && (actor->unk79_4 & 4)) {
                func_808013C8_chgameselect(actor, actor->unk79_4 - 4);
            }
        }
        if (func_800DA298(0x64A)) {
            if (func_80016B30(0, 1) == 1) {
                func_8010114C(actor->unk3C, 8, actor->unk79_4);
            } else if (func_80016B30(0, 0) == 1) {
                func_8010114C(actor->unk3C, 7, actor->unk79_4);
            }
        }
        if (actor->unk6C_0 == 1 && actor->unk7C_12) {
            if (state->local_1[actor->unk79_4] &&
                func_808014F0_chgameselect(actor, state->local_0[actor->unk79_4].f)) {
                actor->unk58 = 0.0f;
            }
        }
        if (actor->unk64_19 && !actor->unk64_20) {
            if (((f32 *) actor->actorData)[7] > 0.0f) {
                dt = 1;
                scratch = func_800D8FF8();
                ((f32 *) actor->actorData)[7] =
                    ((f32 *) actor->actorData)[7] - dt * scratch;
                if (((f32 *) actor->actorData)[7] < 0.0f) {
                    ((f32 *) actor->actorData)[7] = 0.0f;
                }
            }
        } else if (((f32 *) actor->actorData)[7] < 1.0f) {
            dt = 1;
            scratch = func_800D8FF8();
            ((f32 *) actor->actorData)[7] = ((f32 *) actor->actorData)[7] + dt * scratch;
            if (((f32 *) actor->actorData)[7] > 1.0f) {
                ((f32 *) actor->actorData)[7] = 1.0f;
            }
        }
    }
}

// Matching: the line breaks in this function are needed for the match.
s32 func_808011B4_chgameselect(actor, msg, arg) Actor *actor; s32 msg; s32 arg;
{
    u8 *data;
    u8 *data2;
    s32 i;

    switch (msg) {
        default:
        return 0;
        case 0x23:
        data = func_80100094(actor, 0);
        for (i = 0; i < 8; i++) {
            if (data[0xC0 + i] != 0) {
                func_8080145C_chgameselect(data + 0xC8, *(f32 *)(data + 0xD4), ((GsEntry12 *)data)[i].data + 0x60, ((GsEntry12 *)data)[i].data);
            }
        }
        ((GsBits6E *)actor)->unk6E_0 = 1;
        break;
        case 0x31:
        if (((GsBits74 *)actor)->unk74_21) {
            data2 = func_80100094(actor, 0);
            func_80101038(((GsEntry12 *)data2)[arg].data);
            data2[0xC0 + arg] = 1;
            func_8080145C_chgameselect(data2 + 0xC8, *(f32 *)(data2 + 0xD4), ((GsEntry12 *)data2)[arg].data + 0x60, ((GsEntry12 *)data2)[arg].data);
            return 1;
        }
        return 0;
    }
    return 1;
}

int func_808012E4_chgameselect(obj, arg)
f32 obj[3];
s32 arg;
{
    f32 unk_0;
    f32 *obj_copy;
    s32 alpha;
    int field_idx;
    // Matching: the index variable and the extra copy of obj are needed for the match.
    field_idx = 13;
    unk_0 = (alpha = 255.0f * obj[field_idx]);
    if (alpha != 0) {
        _subaddiefade_entrypoint_8(obj, alpha);
        func_80101870(obj_copy = obj, arg);
    }
}

void func_80801338_chgameselect(Actor *actor, s32 step)
{
    s32 target;
    u32 column;
    target = actor->unk79_4 + step;
    column = actor->unk79_4 & 3;
    if (actor->actorData[0] && target + 1 == actor->actorData[0]) {
        column = target & 3;
        if (!step)
            step = target == 0 ? 1 : -1;
        target += step;
    }
    if (step < 0 && column != 0)
        func_808013C8_chgameselect(actor, target);
    else if (step > 0 && column != 3)
        func_808013C8_chgameselect(actor, target);
}

void func_808013C8_chgameselect(actor, slot) Actor *actor;
s32 slot;
{
    if (!actor->unk64_20 || slot < 3) {
        actor->unk79_4 = slot;
        func_80101238(10, actor->unk79_4);
        actor->unk6C_0 = 1;
        func_80102424(actor, 1);
        actor->unk58 = 0.5f;
    }
}

// Intersects a ray with a plane.
void func_8080145C_chgameselect(f32 *plane_normal, f32 plane_dist, f32 *out_pos, f32 *ray_origin)
{
    f32 ray_dir[3];
    f32 t;
    func_800E3980(ray_dir);
    func_800EF3DC(ray_dir, ray_origin);
    t = func_800EEAA4(ray_dir, plane_normal);
    if (t != 0.0f) {
        t = (plane_dist - func_800EEAA4(ray_origin, plane_normal)) / t;
        func_800EE7B4(out_pos, ray_origin, ray_dir, t);
    }
}

s32 func_808014F0_chgameselect(actor, target)
Actor *actor;
f32 *target;
{
    f32 delta[3];
    f32 current[3];
    f32 speed;
    f32 dist;

    _subaddieskeleton_entrypoint_1(actor, 5, current);
    func_800EFB24(delta, target, current);
    dist = func_800EEF94(delta);
    if (dist != 0.0f) {
        speed = func_800FF060(dist, (f32 *) ((u8 *) actor + 0x24), 4000.0f, -4000.0f,
                                3000.0f, func_800D8FF8());
        func_800EF174(actor->position, delta, speed / dist);
    }
    return (dist == 0.0f || *(f32 *) ((u8 *) actor + 0x24) < 0.01f) ? 1 : 0;
}

int func_808015DC_chgameselect(handle, color)
s32 handle;
s32 color;
{
    u32 actor;
    actor = func_80106790(handle);
    switch (color) {
        case 1:
            _subaddiefade_entrypoint_12(actor, 0xff, 0, 0);
            return;
        case 2:
            _subaddiefade_entrypoint_12(actor, 0, 0xff, 0);
            return;
        default:
            _subaddiefade_entrypoint_12(actor, 0xff, 0xff, 0xff);
            return;
    }
}

int func_80801658_chgameselect(handle, enable)
s32 handle;
s32 enable;
{
    u8 *actor;
    actor = func_80106790(handle);
    if (enable != 0) {
        actor[0x65] = (actor[0x65] & 0xFFFF) | 0x8;
    } else {
        actor[0x65] &= ~0x8;
    }
}

void func_808016A0_chgameselect(s32 handle, s32 enable)
{
    GameSelectActor *actor;
    actor = func_80106790(handle);
    if (enable != 0) {
        actor->unk65_4 = 1;
    } else {
        actor->unk65_4 = 0;
    }
}

s32 func_808016E8_chgameselect(enum asset_e handle, s32 slot)
{
    func_808013C8_chgameselect(func_80106790(handle), slot);
}

void func_80801714_chgameselect(handle, arg) Unk80132ED0 *handle;
s32 arg;
{
    Actor *actor;
    actor = func_80106790(handle);
    func_80102424(actor, 2);
    actor->unk64_19 = 1;
    func_80803C80_chgameselect();
}

void func_80801758_chgameselect(s32 handle, s32 blocked_slot)
{
    u8 *actor = func_80106790(handle);
    *(s32 *) (actor + 0x18) = blocked_slot + 1;
    func_80801338_chgameselect(actor, 0);
}

int chgameselect_entrypoint_2()
{
    return &D_808080C8_chgameselect;
}

// Matching: the line breaks in this function are needed for the match.
int func_8080179C_chgameselect(actor) Actor *actor;
{
    switch (actor->unk79_4) {
        case 4:
        if (func_80101E4C(actor, D_80808288_chgameselect)) {
            func_800C3F48(((u16)(u32)(func_800DC178(0.7f, 0.8f) * 1023.0f) << 21) + 0xFA4D5);
        }
        break;
        case 6:
        if (func_80101E14(actor, 0.77f)) {
            func_800C3F48(((u16)(u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) << 21) + 0xDACD5);
        }
        break;
    }
    if (func_80101E4C(actor, D_80808110_chgameselect + actor->unk79_4 * 0x2C)) {
        func_800C3F48(((((*((u16 *) (D_80808270_chgameselect + (actor->unk79_4 * 2)))) & 0x7FF) + ((((D_80808280_chgameselect[actor->unk79_4] * 1000) >> 5) & 0x3FF) << 11)) + ((u32)(u16)(u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) << 21)));
    }
}

void func_80801AC4_chgameselect(actor) Actor *actor;
{
    s32 unk_0;
    f32 pos[3];
    f32 unk_1;

    if (!actor->unk64_20) {
        if ((unk_0 = func_80103C94()) != 0) {
            func_800B237C(unk_0, pos, &unk_1);
            func_80101010(pos);
            if (func_80101180(0x4AB, 0x31, actor->unk79_4)) {
                actor->unk64_20 = 1;
            }
        }
    }
    if (_subaddiefade_entrypoint_0(actor) < 100) {
        _subaddiefade_entrypoint_1(actor, 100);
    }
    switch (actor->unk70_10) {
        case 2:
        case 3:
            break;
        case 4:
            if (func_80101DDC(actor)) {
                func_80102424(actor, 2);
            }
    }
    func_8080179C_chgameselect(actor);
}

s32 func_80801BA8_chgameselect(Actor *actor, s32 msg, s32 arg)
{
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s16 unk_3;
    switch (msg) {
        case 0x95:
            func_801032B0(actor, D_808080A8_chgameselect[actor->unk79_4].unk0, 0);
            unk_0 = func_80104248(actor);
            func_8008B304(unk_0);
            unk_1 = func_800B27E0(func_801039E4(actor->unk0));
            func_8008C200(*(s16 *) ((u8 *) actor->unk0 + 0x10), unk_1, func_8008AEDC(unk_0));
            func_80102424(actor, 2);
            unk_2 = actor->unk79_4;
            switch (unk_2) {
                case 5:
                    if (!_gcfrontend_entrypoint_1(3))
                        _subaddiefade_entrypoint_1(actor, 100);
                    break;
                case 7:
                    if (!_gcfrontend_entrypoint_2())
                        _subaddiefade_entrypoint_1(actor, 100);
                    break;
            }
            break;
        case 0xA:
            if (arg == actor->unk79_4) {
                unk_2 = 1;
            } else {
                unk_2 = 0;
            }
            func_80802070_chgameselect(actor, unk_2);
            if (arg == actor->unk79_4) {
                unk_3 = D_808080AA_chgameselect[arg].unk0;
                if (unk_3 >= 0)
                    func_80803D00_chgameselect(unk_3, 2);
            }
            break;
        case 0x1F:
            func_80801D74_chgameselect(actor, arg);
            break;
        case 0x21:
            if (actor->unk79_4 == ((s16 *) &arg)[0]) {
                func_808020CC_chgameselect(actor, ((s16 *) &arg)[1]);
                break;
            }
        default:
            return 0;
    }
    return 1;
}

void func_80801D74_chgameselect(Actor *actor, s32 arg)
{
    s32 unk_0;
    Unk80132ED0 *handle;
    s32 unk_2;
    f32 pos[3];
    f32 unk_4;
    s32 unk_5;
    s32 i;
    s32 controllers;
    u8 unk_7;

    func_80103D48(actor);
    unk_0 = func_80104248(actor);
    handle = actor->unk0;
    if (unk_0 && !actor->unk7C_12) {
        func_8008B304(unk_0);
    }
    if (*(s16 *) ((u8 *) handle + 0x10)) {
        unk_2 = func_800B27E0(arg, unk_0);
        if (unk_0 && unk_2 && !actor->unk7C_12) {
            func_8008C200(*(s16 *) ((u8 *) handle + 0x10), unk_2, func_8008AEDC(unk_0));
        }
        func_800DF72C(func_800AE080(*(s16 *) ((u8 *) handle + 0x10)));
    }
    if (_subaddiefade_entrypoint_0(actor) < 255) {
        func_800DF410(_subaddiefade_entrypoint_0(actor));
    }
    func_800DF830(((GameSelectTop *) actor)->top);
    func_800DF738(_subaddieskeleton_entrypoint_4(actor));
    if (!actor->unk7C_12) {
        func_800B237C(func_800B2840(arg), pos, &unk_4);
        *(s16 *) ((u8 *) handle + 0x1E) = pos[0] * actor->scale;
        *(s16 *) ((u8 *) handle + 0x20) = pos[1] * actor->scale;
        *(s16 *) ((u8 *) handle + 0x22) = pos[2] * actor->scale;
        ((Mass63GameSelectMarker *) handle)->local_0 = (u32) unk_4;
    }
    unk_5 = func_800D731C(actor->unk0->unk14);
    unk_7 = unk_5;
    if (unk_5)
        func_800DF7E8(unk_7);
    func_80103D70(actor);
    actor->unk7C_12 = 1;
    switch (actor->unk79_4) {
        case 0:
        case 1:
        case 2:
            func_800DF744(actor->unk79_4 + 1, actor->unk64_19 ? 2 : 1);
            break;
        case 5:
            controllers = 0;
            for (i = 0; i < 4; i++) {
                if (func_80016800(i))
                    controllers |= 1 << i;
            }
            func_800DF7C4(3, controllers);
    }
}

int func_80802070_chgameselect(actor, active)
s32 actor[2];
s32 active;
{
    if (active != 0) {
        if (((unsigned int) (u16) *(u16 *) ((char *) actor + 114) >> 10) != 3) {
            func_80102424(actor, 3);
        }
    } else if ((((u16) *(u16 *) ((char *) actor + 114) & 0xFFFFFFFFu) >> 10) == 3) {
        func_80102424(actor, 4);
    }
}

void func_808020CC_chgameselect(actor, flag) Actor *actor;
s32 flag;
{
    if (flag != actor->unk64_19) {
        if (flag) {
            switch (actor->unk79_4) {
                case 0:
                case 1:
                case 2:
                    break;
                default:
                    _subaddiefade_entrypoint_4(actor);
            }
        } else {
            switch (actor->unk79_4) {
                case 0:
                case 1:
                case 2:
                    break;
                default:
                    _subaddiefade_entrypoint_5(actor);
            }
        }
        actor->unk64_19 = flag;
    }
}

void func_8080218C_chgameselect(slot, flag) s32 slot;
s32 flag;
{
    GameSelectEvent event;
    event.local_3.local_1 = slot;
    if (flag)
        event.local_3.local_2 = 1;
    else
        event.local_3.local_2 = 0;
    func_80101180(0x4A8, 0x21, event.local_0);
}

int chgameselect_entrypoint_3()
{
    return (int) D_80808298_chgameselect;
}

int chgameselect_entrypoint_4()
{
    return (int) &D_808082E0_chgameselect;
}

void func_808021E4_chgameselect(u8 *actor)
{
    s32 zoombox;

    zoombox = _gczoombox_entrypoint_5(0xC8, 0xC, 2, 0, 0);
    *(s32 **) ((char *) actor + 0x28) = zoombox;
    _gczoombox_entrypoint_19(zoombox);
    *(s32 **) ((char *) actor + 0x24) = heap_alloc(0x40);
    *(s32 **) ((char *) actor + 0x34) = heap_alloc(0x40);
}

void func_80802248_chgameselect(Actor *actor)
{
    u32 file_num;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;

    file_num = 0;
    if (actor->unk64_20) {
        switch (actor->unk79_4) {
            case 0:
            case 1:
            case 2:
                file_num = actor->unk79_4 + 1;
        }
    }
    if (actor->actorData[0]) {
        _gczoombox_entrypoint_18(actor->actorData[4]);
        _gczoombox_entrypoint_16(actor->actorData[4]);
        _gczoombox_entrypoint_9(actor->actorData[4]);
        _gczoombox_entrypoint_11(actor->actorData[4]);
    } else if (file_num) {
        if (file_num != actor->actorData[5]) {
            _gczoombox_entrypoint_18(actor->actorData[4]);
            _gczoombox_entrypoint_16(actor->actorData[4]);
            _gczoombox_entrypoint_9(actor->actorData[4]);
            _gczoombox_entrypoint_11(actor->actorData[4]);
            func_800E73D4(actor->actorData[3]);
            func_800E73D4(actor->actorData[7]);
            unk_3 = actor->unk79_4 + 1;
            if (func_80803738_chgameselect(actor->unk79_4, &unk_1, &unk_2)) {
                func_80803E94_chgameselect(actor->actorData[3], 0x18F3, 1, 1, &unk_3);
                func_800DB8BC(actor->actorData[3], unk_1);
                func_800E6A58(actor->actorData[3], 0x2C);
                unk_3 = unk_2;
                if (unk_2 == 1) {
                    func_80803E94_chgameselect(actor->actorData[7], 0x18F3, 3, 1, &unk_3);
                } else {
                    func_80803E94_chgameselect(actor->actorData[7], 0x18F3, 2, 1, &unk_3);
                }
            } else {
                func_80803E94_chgameselect(actor->actorData[3], 0x18F3, 0, 1, &unk_3);
            }
            _gczoombox_entrypoint_32(actor->actorData[4]);
            if (*(u8 *) actor->actorData[7]) {
                ((s32 *) &B_80808558_chgameselect)[0] = actor->actorData[3];
                ((s32 *) &B_80808558_chgameselect)[1] = actor->actorData[7];
                _gczoombox_entrypoint_7(actor->actorData[4], 2, &B_80808558_chgameselect);
            } else {
                _gczoombox_entrypoint_8(actor->actorData[4], actor->actorData[3]);
            }
        }
    } else {
        _gczoombox_entrypoint_15(actor->actorData[4]);
        _gczoombox_entrypoint_17(actor->actorData[4]);
        _gczoombox_entrypoint_12(actor->actorData[4]);
        _gczoombox_entrypoint_10(actor->actorData[4]);
    }
    actor->actorData[5] = file_num;
    _gczoombox_entrypoint_4(actor->actorData[4]);
}

int func_80802480_chgameselect(Actor *actor)
{
    if (*(void **) ((char *) actor + 0x24) != NULL) {
        heap_free((*(void **) ((char *) (actor) + 0x24)));
    }
    if (*(void **) ((char *) actor + 0x34) != NULL) {
        heap_free((*(void **) ((char *) (actor) + 0x34)));
    }
    func_80802620_chgameselect(actor);
}

void func_808024D4_chgameselect(void *actor)
{
    s32 zoombox;

    zoombox = _gczoombox_entrypoint_5(0x1C, 0xD, 2, 1, 0);
    *(s32 *) ((s8 *) actor + 0x28) = zoombox;
    _gczoombox_entrypoint_9(zoombox);
    _gczoombox_entrypoint_11((*(s32 *) ((s8 *) actor + 0x28)));
    *(s32 *) ((s8 *) actor + 0x1C) = -1;
}

void func_80802530_chgameselect(Actor *actor)
{
    s32 zoom_state;

    _gczoombox_entrypoint_4(*(s32 **) ((char *) actor + 0x28), actor);
    zoom_state = _gczoombox_entrypoint_3(*(s32 **) ((char *) actor + 0x28), actor);
    if (zoom_state != *(s32 *) ((char *) actor + 0x20)) {
        *(s32 *) ((char *) actor + 0x20) = zoom_state;
        if (zoom_state == 3) {
            func_80800CA0_chgameselect(actor->unk3C);
        }
    }
}

int func_80802588_chgameselect(Actor *actor)
{
    if (*(s32 *) ((char *) actor + 0x30) != 0) {
        _gldbstring_entrypoint_2((*(s32 *) ((char *) (actor) + 0x18)));
        *(s32 *) ((char *) actor + 0x30) = 0;
    }
    func_80802620_chgameselect(actor);
}

int func_808025CC_chgameselect(Actor *actor)
{
    _gczoombox_entrypoint_2((*(s32 *) ((char *) (actor) + 0x28)));
}

s32 func_808025EC_chgameselect(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0xA:
            actor->unk79_4 = arg;
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80802620_chgameselect(actor)
Actor *actor;
{
    _gczoombox_entrypoint_0((*(s32 *) ((char *) (actor) + 0x28)));
}

void func_80802640_chgameselect(handle, string_id, unk_2) s32 handle;
s32 string_id;
s32 unk_2;
{
    ChGameSelectState *state;
    // Matching: extra temporary needed for the match.
    int *text;
    state = (ChGameSelectState *) func_80106790(handle);
    if (string_id != *(s32 *) ((char *) state + 24)) {
        if (*(s32 *) ((char *) state + 48)) {
            _gldbstring_entrypoint_2((*(s32 *) ((char *) (state) + 24)));
            *(s32 *) ((char *) state + 48) = 0;
        }
        *(s32 *) ((char *) state + 24) = string_id;
        if (string_id) {
            text = (*(s32 *) ((char *) (state) + 48));
            (*(s32 *) ((char *) (state) + 48)) = _gldbstring_entrypoint_0(text);
        }
        *(s32 *) ((char *) state + 28) = -1;
        _gczoombox_entrypoint_32(*(void **) ((char *) state + 40));
    }
}

void func_808026C8_chgameselect(handle, text_index) s32 handle;
s32 text_index;
{
    s32 state;
    state = func_80106790(handle);
    if (text_index != *(s32 *) ((char *) state + 0x1C)) {
        *(s32 *) ((char *) state + 0x1C) = text_index;
        _gczoombox_entrypoint_32(*((s32 *) (((char *) state) + 0x28)));
        _gczoombox_entrypoint_8(*((s32 *) (((char *) state) + 0x28)),
                                _gldbstring_entrypoint_1(*((s32 *) (((char *) state) + 0x30)),
                                                         *((s16 *) (((char *) state) + 0x1E))));
        *(s32 *) ((char *) state + 0x20) = -1;
    }
}

void func_80802730_chgameselect(handle, text) s32 handle;
s32 text;
{
    s32 *state;
    state = (s32 *) func_80106790(handle);
    state[0x1C / 4] = -1;
    _gczoombox_entrypoint_32((void *) state[0x28 / 4]);
    _gczoombox_entrypoint_8((void *) state[0x28 / 4], text);
    state[0x20 / 4] = -1;
}

int func_80802780_chgameselect(handle, enable)
s32 handle;
s32 enable;
{
    u8 *actor;
    actor = func_80106790(handle);
    if (enable != 0) {
        actor[0x65] = (actor[0x65] & 0xFFFF) | 0x10;
    } else {
        actor[0x65] &= ~0x10;
    }
}

int chgameselect_entrypoint_5()
{
    return (int) &D_80808328_chgameselect;
}

void func_808027D4_chgameselect(s32 arg0)
{
}

void func_80803CE0_chgameselect();

void func_808027DC_chgameselect(Actor *actor)
{
    // Matching: needed for the match.
    s32 pad[4];
    u8 *menu;
    u8 *items;
    s32 i;
    s8 text_index;
    menu = func_80100094(actor, 0);
    if (!menu)
        return;
    if (actor->unk64_20 && _gcnewoption_entrypoint_48(menu)) {
        func_80800AEC_chgameselect(actor->unk3C, (s32) menu, -1, 0xFF);
    }
    switch (actor->unk70_10) {
        case 2:
            items = func_80100094(actor, 1);
            text_index = items[_gcnewoption_entrypoint_45(menu) * 6 + 3];
            if (text_index >= 0) {
                func_808026C8_chgameselect(((Actor *) func_80106790(actor->unk3C))->actorData[3],
                                           text_index);
            }
            break;
        case 3:
            if (func_80015FA0(0) == 1) {
                for (i = 0; i < (s32) actor->actorData[5]; i++) {
                    if (_gcnewoption_entrypoint_17(menu, i))
                        break;
                }
                if (i < (s32) actor->actorData[5])
                    _gcnewoption_entrypoint_37(menu, 0);
                else
                    func_80803C60_chgameselect();
            } else if (func_80016B54(0, 0) == 1) {
                for (i = 0; i < (s32) actor->actorData[5]; i++) {
                    func_80803604_chgameselect(menu, i, 0, 0);
                }
                func_80803CE0_chgameselect();
            }
    }
    _gcnewoption_entrypoint_0(menu);
}

s32 func_80802994_chgameselect(s32 actor, s32 unk_1)
{
    if (func_80100094(actor, 0) != 0) {
        _gcnewoption_entrypoint_1(func_80100094(actor, 0), unk_1);
    }
}

s32 func_808029D8_chgameselect(s32 actor)
{
    if (func_80100094(actor, 0)) {
        _gcnewoption_entrypoint_6(actor, 0);
    }
}

s32 func_80802A0C_chgameselect(Actor *actor, s32 msg, GameSelectInputEvent event)
{
    if (msg == 0x20) {
        switch (actor->unk70_10) {
            case 2:
                func_808030EC_chgameselect(actor, func_80101080(), event.local_0,
                                           event.local_1);
                break;
            case 3:
                func_808034BC_chgameselect(actor, func_80101080(), event.local_0,
                                           event.local_1);
                break;
            default:
                func_80800AEC_chgameselect(actor->unk3C, func_80101080(), event.local_0,
                                           event.local_1);
        }
    } else
        return 0;
    return 1;
}

void func_80802AD4_chgameselect(handle, unk_1, count, unk_3, max_rows) Unk80132ED0 *handle;
s32 unk_1;
s32 count;
s32 unk_3;
s32 max_rows;
{
    Actor *actor;
    void *menu;
    actor = func_80106790(handle);
    _gcnewoption_entrypoint_4(actor, 0, _gcnewoption_entrypoint_35, 0, unk_1);
    menu = func_80100094(actor, 0);
    _gcnewoption_entrypoint_36(menu);
    if (max_rows <= 0)
        max_rows = 5;
    _gcnewoption_entrypoint_8(menu, count < max_rows ? count : max_rows);
    _gcnewoption_entrypoint_9(menu, count);
    _gcnewoption_entrypoint_10(menu, unk_3 ? 2 : 3);
    _gcnewoption_entrypoint_40((s32) menu, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_42((s32) menu, 0.1f);
    _gcnewoption_entrypoint_11(menu);
    func_80101FDC(actor, 1);
}

void func_80802BE8_chgameselect()
{
    func_808029D8_chgameselect(func_80106790());
}

void func_80802C10_chgameselect(Unk80132ED0 *handle)
{
    Actor *actor;
    actor = func_80106790(handle);
    _gcnewoption_entrypoint_38(func_80100094(actor, 0), 1);
}

int func_80802C48_chgameselect()
{
    s32 actor;
    actor = func_80106790();
    _gcnewoption_entrypoint_39(func_80100094(actor, 0));
}

int func_80802C7C_chgameselect()
{
    u8 *actor;
    actor = func_80106790();
    actor[0x65] &= 0xFFEF;
    _gcnewoption_entrypoint_37(func_80100094(actor, 0), 1);
}

void func_80802CC0_chgameselect()
{
    u8 *actor;

    actor = func_80106790();
    actor[0x65] &= 0xFFEF;
    _gcnewoption_entrypoint_37(func_80100094(actor, 0), 0);
}

void func_80802D04_chgameselect(s32 handle, s32 busy)
{
    func_80106790(handle)->unk64_20 = busy;
}

void func_80802D40_chgameselect(Unk80132ED0 *handle, s32 count, s32 string_id)
{
    Actor *actor;

    actor = func_80106790(handle);
    *(s32 *) ((u8 *) actor + 0x28) = count;
    *(s32 *) ((u8 *) actor + 0x2C) = 0;
    func_80802640_chgameselect(*(void **) ((u8 *) func_80106790(actor->unk3C) + 0x24), string_id,
                               0);
    func_80100074(actor, 1, *(s32 *) ((u8 *) actor + 0x28) * 6);
    func_80101FDC(actor, 2);
}

void func_80802DB4_chgameselect(void *handle, s32 unk_1, s32 unk_2, s32 unk_3, s32 unk_4,
                                s32 unk_5)
{
    Actor *actor;
    GameSelectItem1213 *item;

    actor = (Actor *) func_80106790(handle);
    item = func_80100094(actor, 1);
    item = &item[((GameSelectActorCount1213 *) actor)->unk2C];
    item->unk0 = unk_1;
    item->unk1 = unk_2;
    item->unk2 = unk_3;
    item->unk3 = unk_4;
    item->unk4 = unk_5;
    ((GameSelectActorCount1213 *) actor)->unk2C++;
}

void func_80802E38_chgameselect(handle, unk_1, unk_2, max_rows) void *handle;
s32 unk_1;
s32 unk_2;
s32 max_rows;
{
    u8 *actor;
    s32 menu;
    s32 i;
    u8 *item;

    actor = (u8 *) func_80106790(handle);
    _gcnewoption_entrypoint_4(actor, 0, _gcnewoption_entrypoint_35, 0, unk_1);
    menu = func_80100094(actor, 0);
    _gcnewoption_entrypoint_36(menu);
    if (max_rows <= 0)
        max_rows = 5;
    _gcnewoption_entrypoint_8(
        menu, *(s32 *) (actor + 0x2C) < max_rows ? *(s32 *) (actor + 0x2C) : max_rows);
    _gcnewoption_entrypoint_9(menu, *(s32 *) (actor + 0x2C));
    _gcnewoption_entrypoint_10(menu, 0);
    *(s32 *) (actor + 0x30) = unk_2;
    i = 0;
    item = (u8 *) func_80100094(actor, 1);
    for (; i < *(s32 *) (actor + 0x2C); i++, item += 6) {
        _gcnewoption_entrypoint_31(menu, i, *(s16 *) (item + 4));
    }
    _gcnewoption_entrypoint_40(menu, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_42(menu, 0.1f);
    _gcnewoption_entrypoint_11(menu);
}

s32 func_80802F8C_chgameselect()
{
    u8 *actor;
    s32 result;

    actor = (u8 *) func_80106790();
    result = _gcnewoption_entrypoint_37(func_80100094((int) actor, 0), 1);
    if (result != 0) {
        actor[0x65] &= 0xFFEF;
    }
    return result;
}

void func_80802FE4_chgameselect(Actor *actor)
{
    Actor *parent;

    func_80100074(actor, 1, 0);
    actor->actorData[5] = 0;
    actor->actorData[4] = 0;
    actor->unk64_20 = 0;
    _gcnewoption_entrypoint_6(actor, 0);
    parent = (Actor *) func_80106790(actor->unk3C);
    func_80802640_chgameselect(parent->actorData[3], 0, 0);
}

void func_80803048_chgameselect(u8 *actor, s32 menu)
{
    s32 i;
    u8 *item;

    item = func_80100094(actor, 1);
    i = 0;
    if (*(s32 *) ((s8 *) actor + 0x2C) > 0) {
        do {
            _gcnewoption_entrypoint_12(menu, i, (*(u8 *) ((s8 *) (item) + (1))));
            if (*(s8 *) ((s8 *) item + 2) >= 0) {
                func_8080401C_chgameselect(menu, i, 0);
            }
            i += 1;
            item += 6;
        } while (i < *(s32 *) ((s8 *) actor + 0x2C));
    }
    _gcnewoption_entrypoint_41(menu, (*(s32 *) ((s8 *) (actor) + (0x30))));
}

void func_808030EC_chgameselect(actor, menu, index, action) u8 *actor;
s32 menu;
s32 index;
s32 action;
{
    s32 item_id;
    s32 unk_0;
    u8 *parent;
    switch (action) {
        case 0:
            func_80803048_chgameselect(actor, menu);
            return;
        case 3:
            if (_gcnewoption_entrypoint_19(menu, index) != 0) {
                func_80803C60_chgameselect();
                parent = func_80106790(*((s32 **) (((char *) actor) + 0x3C)));
                func_808026C8_chgameselect(
                    *((s32 **) (((char *) parent) + 0x2C)),
                    *(((s8 *) ((u8 *) func_80100094(actor, 1) + (index * 6))) + 2));
                return;
            }
        case 2:
            item_id = (s32) (*((u8 *) ((u8 *) func_80100094(actor, 1) + (index * 6))));
            func_80802FE4_chgameselect(actor);
            func_80800AEC_chgameselect(*((s32 **) (((char *) actor) + 0x3C)), 0, item_id, action);
    }
}

int func_808031F4_chgameselect(s32 handle, s32 count)
{
    Actor *actor;
    actor = func_80106790(handle);
    *(s32 *) ((char *) actor + 0x2C) = 0;
    *(s32 *) ((char *) actor + 0x28) = count;
    func_80100074(actor, 1, count * 6);
    func_80101FDC(actor, 3);
}

void func_80803248_chgameselect(void *handle, s32 unk_1, s32 unk_2, s32 unk_3, s32 unk_4)
{
    Actor *actor;
    GameSelectItem1213 *item;

    actor = (Actor *) func_80106790(handle);
    item = func_80100094(actor, 1);
    item = &item[((GameSelectActorCount1213 *) actor)->unk2C];
    item->unk0 = unk_1;
    item->unk1 = unk_2;
    item->unk2 = -1;
    item->unk3 = unk_3;
    item->unk4 = unk_4;
    ((GameSelectActorCount1213 *) actor)->unk2C++;
}

void func_808032CC_chgameselect(handle, unk_1, unk_2, max_rows) void *handle;
s32 unk_1;
s32 unk_2;
s32 max_rows;
{
    u8 *actor;
    s32 menu;
    s32 i;
    u8 *item;

    actor = (u8 *) func_80106790(handle);
    _gcnewoption_entrypoint_4(actor, 0, _gcnewoption_entrypoint_35, 0, unk_1);
    menu = func_80100094(actor, 0);
    _gcnewoption_entrypoint_36(menu);
    if (max_rows <= 0)
        max_rows = 5;
    _gcnewoption_entrypoint_8(
        menu, *(s32 *) (actor + 0x2C) < max_rows ? *(s32 *) (actor + 0x2C) : max_rows);
    _gcnewoption_entrypoint_9(menu, *(s32 *) (actor + 0x2C));
    _gcnewoption_entrypoint_10(menu, 2);
    *(s32 *) (actor + 0x30) = unk_2;
    i = 0;
    item = (u8 *) func_80100094(actor, 1);
    for (; i < *(s32 *) (actor + 0x2C); i++, item += 6) {
        _gcnewoption_entrypoint_31(menu, i, *(s16 *) (item + 4));
    }
    _gcnewoption_entrypoint_40(menu, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_42(menu, 0.1f);
    _gcnewoption_entrypoint_11(menu);
}

void func_80803420_chgameselect(s32 actor, s32 menu)
{
    s32 i;
    u8 *item;

    item = func_80100094(actor, 1);
    i = 0;
    if (*(s32 *) ((char *) actor + 0x2C) > 0) {
        do {
            _gcnewoption_entrypoint_12(menu, i, *(u8 *) ((char *) item + 1));
            func_80803604_chgameselect(menu, i, *(s8 *) ((char *) item + 3), 0);
            i += 1;
            item += 6;
        } while (i < *(s32 *) ((char *) actor + 0x2C));
    }
    _gcnewoption_entrypoint_41(menu, *(s32 *) ((char *) actor + 0x30));
}



int func_808034BC_chgameselect(actor, menu, index, action) s32 actor; s32 menu; u32 index; s32 action;
{
  switch (action)
  {
    case 0 :
      func_80803420_chgameselect(actor, menu);
      break;

    case 4 :
      func_80803604_chgameselect(menu, index, _gcnewoption_entrypoint_20(menu, index), 1);
      break;

    case 5 :
      _gcnewoption_entrypoint_37(menu, 1);
      break;

    case 2 :
    case 3 :
    {
      s32 i;
      u8 *items;
      u32 mode;
      u8 *item;

      items = func_80100094(actor, 1);
      func_80800AEC_chgameselect(*(s32 *)((char *)actor + 0x3C), menu, -1, 0xFC);
      i = 0;
      item = items;
      if (*(s32 *)((char *)actor + 0x2C) > 0)
      {
        do
        {
          if (_gcnewoption_entrypoint_17(menu, i) != 0)
          {
            mode = 0xFE;
          }
          else
          {
            mode = 0xFD;
          }
          func_80800AEC_chgameselect(*(s32 *)((char *)actor + 0x3C), menu, *item, mode);
          i += 1;
          item += 6;
        }
        while (i < *(s32 *)((char *)actor + 0x2C));
      }
      func_80802FE4_chgameselect(actor);
      func_80800AEC_chgameselect(*(s32 *)((char *)actor + 0x3C), 0, -1, action);
    }

  }
}
void func_80803604_chgameselect(menu, index, unk_2, play_sound) s32 menu;
s32 index;
s32 unk_2;
s32 play_sound;
{
    // Matching: `| 0` is needed for the match.
    if (unk_2) {
        func_8080407C_chgameselect(menu, index, play_sound | 0);
    } else {
        func_808040DC_chgameselect(menu, index, play_sound | 0);
    }
}

void func_80803638_chgameselect()
{
    _glsavegame_entrypoint_0();
}

void func_80803658_chgameselect()
{
    _glsavegame_entrypoint_9();
}

void func_80803678_chgameselect()
{
    func_800D37C0();
}

void func_80803698_chgameselect()
{
    _glsavegame_entrypoint_10();
}

void func_808036B8_chgameselect()
{
    func_800D37D4();
}

void func_808036D8_chgameselect()
{
    _glsavegame_entrypoint_1();
}

s32 func_808036F8_chgameselect(s32 slot)
{
    return _glsavegame_entrypoint_2(slot);
}

s32 func_80803718_chgameselect()
{
    return _glsavegame_entrypoint_3();
}


int func_80803738_chgameselect(slot, out_time, out_count) s32 slot; s32 *out_time; s32 *out_count;
{
  s32 save;
  if (func_808036F8_chgameselect(slot))
  {
    save = _glsavegame_entrypoint_4(slot);
    *out_time = func_800DB7C0(save);
    *out_count = func_800D04A0(save, 1);
    return ((*out_time) < 0) ? (0) : (1);
  }
  return 0;
}
s32 func_808037C0_chgameselect(s32 slot)
{
    s32 save;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;

    if (func_808036F8_chgameselect(slot)) {
        save = _glsavegame_entrypoint_4(slot);
        unk_0 = func_800DAC78(save, 0x441);
        unk_1 = func_800D046C(save, 0x5A, 1);
        unk_2 = func_800DAC78(save, 0x360);
        if (!unk_0 && unk_1 && !unk_2)
            return 0xA4;
        if (unk_0 && unk_2)
            return 0xA5;
        return func_800DB83C(save, 0x1A) > 0 ? 0xA3 : 0xA2;
    }
    return 0xA1;
}

void func_80803888_chgameselect(Actor *actor, u32 unk_1, u32 unk_2)
{
    func_80016BDC(unk_2 ? 2 : 1);
    func_800C9E20(1.5f, _gcfrontend_entrypoint_8, unk_1, unk_2);
    func_80800478_chgameselect(actor, 8);
}

void func_808038EC_chgameselect(s32 actor, s32 unk_1, s32 unk_2)
{
    func_80016BDC(1);
    func_800C9E20(1.5f, _gcfrontend_entrypoint_7, unk_1, unk_2);
    func_80800478_chgameselect(actor, 8);
}

s32 func_80803940_chgameselect(void)
{
    _gcstatusDll_entrypoint_6(0, 0);
    _gcstatusDll_entrypoint_6(1, 1);
    _gcstatusDll_entrypoint_6(2, 2);
    _gcstatusDll_entrypoint_6(3, 3);
}

s32 func_80803988_chgameselect(void)
{
    _gcstatusDll_entrypoint_3(0, 1);
    _gcstatusDll_entrypoint_3(1, 1);
    _gcstatusDll_entrypoint_3(2, 1);
    _gcstatusDll_entrypoint_3(3, 1);
}

s32 func_808039D0_chgameselect(void)
{
    _gcstatusDll_entrypoint_4(2);
    _gcstatusDll_entrypoint_8(0);
    _gcstatusDll_entrypoint_7(2);
    _gcstatusDll_entrypoint_9(2);
    func_80803940_chgameselect();
    func_80803988_chgameselect();
}

s32 func_80803A18_chgameselect(void)
{
    _gcstatusDll_entrypoint_4(6);
    _gcstatusDll_entrypoint_8(0xA);
    _gcstatusDll_entrypoint_7(2);
    func_80803940_chgameselect();
    func_80803988_chgameselect();
}

s32 func_80803A58_chgameselect(void)
{
    _gcstatusDll_entrypoint_4(6);
    func_80803940_chgameselect();
    func_80803988_chgameselect();
}

s32 func_80803A88_chgameselect(void)
{
    _gcstatusDll_entrypoint_8(0);
    _gcstatusDll_entrypoint_7(3);
}

void func_80803AB0_chgameselect()
{
    s32 i;
    switch (_gcstatusDll_entrypoint_14()) {
        case 4:
            break;
        case 5:
            i = 0;
            do {
                _gcstatusDll_entrypoint_6(i, _gcstatusDll_entrypoint_15() == i ? 5 : 4);
                i++;
            } while (i < 4);
        case 6:
            break;
        default:
            func_80803940_chgameselect();
    }
}

void func_80803B3C_chgameselect(s32 actor)
{
    func_80016BDC(_gcstatusDll_entrypoint_10());
    func_800C9DAC(1.5f, func_800AA1A0);
    func_80800478_chgameselect(actor, 8);
}

// Matching: the line breaks in this function are needed for the match.
void func_80803B84_chgameselect(s32 actor)
{
    s32 *entry;
    s32 key;
    key = func_800AA120();
    entry = &D_80808370_chgameselect; loop_1: if (key == (*((s32 *) (((s8 *) entry) + 0)))) {
        (*((s32 (**)()) (((s8 *) entry) + 4)))();
    }
    else
    {
        entry += 2;
        if (entry != D_808083A0_chgameselect) {
            goto loop_1;
        }

    }

    func_80803B3C_chgameselect(actor);
}

// Matching: the line breaks in this function are needed for the match.
void func_80803BE8_chgameselect(u8 *actor)
{
    s32 *entry;
    s32 key;
    s8 *handler;
    func_800AA074();
    func_800AA054(*((s32 *) (((s8 *) actor) + 0x54)));
    key = func_800AA120();
    entry = D_808083A0_chgameselect; loop_1: if (key == (*((s32 *) (((s8 *) entry) + 0)))) { key = 4;
        handler = ((s8 *) entry) + key;
        (*((s32 (**)(s32 *)) handler))(D_808083C8_chgameselect);
    }
    else
    {
        entry += 2;
        if (entry != D_808083C8_chgameselect) {
            goto loop_1;
        }

    }

    func_80803B3C_chgameselect(actor);
}

void func_80803C60_chgameselect()
{
    func_800FC660(0xF);
}

void func_80803C80_chgameselect()
{
    func_800FC660(0xE);
}

void func_80803CA0_chgameselect()
{
    func_800FC660(0x10);
}

void func_80803CC0_chgameselect()
{
    func_800FC660(0x96);
}

void func_80803CE0_chgameselect()
{
    func_800FC660(0x97);
}

void func_80803D00_chgameselect(unk_0, unk_1) s32 unk_0;
s32 unk_1;
{
    GameSelectPacked1581 packed;
    f32 pos[3];
    f32 rot[3];

    packed.local_1.local_0 = unk_1;
    packed.local_1.local_1 = unk_0;
    if (!func_80101180(0x4B9, 0x21, packed.local_0)) {
        func_800A5800(unk_0);
        _cadbfunc_entrypoint_0(pos);
        _cadbfunc_entrypoint_2(rot);
        func_800E39D8(pos, rot);
    }
}

int func_80803D60_chgameselect(index)
s32 index;
{
    switch (index) {
        case 0:
        case 1:
        case 2:
            return func_808036F8_chgameselect(index);

        case 5:
            return _gcfrontend_entrypoint_1(3);

        case 7:
            return _gcfrontend_entrypoint_2();

        default:
            return 1;
    }
}

s32 func_80803DCC_chgameselect(index)
s32 index;
{
    switch (index) {
        case 5:
            return _gcfrontend_entrypoint_1(3) ? 1 : 0;
        case 7:
            return _gcfrontend_entrypoint_2() ? 1 : 0;
        default:
            return 0;
    }
}

// Returns the index of the first player slot without a controller (4 if all are connected).
int func_80803E40_chgameselect()
{
    s32 i;
    for (i = 0; i < 4; i++) {
        if (!func_80016800(i)) {
            return i;
        }
    }

    return i;
}

// Builds a string from a text entry, substituting '~' with the given args.
void func_80803E94_chgameselect(buffer, string_id, text_index, unk_3, args) u8 *buffer;
s32 string_id;
s32 text_index;
s32 unk_3;
s32 *args;
{
    u8 *out;
    u8 *src;
    s32 arg_index;

    src = _gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0), (s16) text_index);
    out = buffer;
    arg_index = 0;
    for (; *src; src++) {
        *out = 0;

        if (*src == '~') {
            func_800E6DB4(buffer, args[arg_index++]);
            out = buffer;
            while (*out) {
                out++;
            }
        } else {
            *out++ = *src;
        }
    }
    *out = 0;
    _gldbstring_entrypoint_2(string_id);
}

void func_80803F90_chgameselect(s32 unk_0, s32 count, s16 *pairs)
{
    s32 strings;
    s32 i;
    s16 *pair;
    func_800E73D4();
    // Matching: empty condition is needed for the match.
    if ((unk_0 && unk_0) && unk_0) {
    }
    i = 0;
    if (count > 0) {
        pair = pairs;
        do {
            strings = _gldbstring_entrypoint_0(0, *((s16 *) (((char *) pair) + 0)));

            if (strings != 0) {
                func_800E6A10(unk_0,
                              _gldbstring_entrypoint_1(strings, *(s16 *) ((char *) pair + 2)));
            }

            _gldbstring_entrypoint_2(*((s16 *) (((char *) pair) + 0)));
            i += 1;
            pair += 2;
        } while (i != count);
    }
}

int func_8080401C_chgameselect(menu, index, play_sound)
s32 menu;
s32 index;
s32 play_sound;
{
    if (!_gcnewoption_entrypoint_19()) {
        _gcnewoption_entrypoint_23(menu, index);
        _gcnewoption_entrypoint_13(menu, index, D_808083C8_chgameselect);
        if (play_sound != 0) {
            func_80803CE0_chgameselect();
        }
    }
}

int func_8080407C_chgameselect(menu, index, play_sound)
s32 menu;
s32 index;
s32 play_sound;
{
    if (!_gcnewoption_entrypoint_17()) {
        _gcnewoption_entrypoint_21(menu, index);
        _gcnewoption_entrypoint_13(menu, index, &D_808083D0_chgameselect);
        if (play_sound != 0) {
            func_80803CC0_chgameselect();
        }
    }
}

int func_808040DC_chgameselect(menu, index, play_sound)
s32 menu;
s32 index;
s32 play_sound;
{
    if (!_gcnewoption_entrypoint_18()) {
        _gcnewoption_entrypoint_22(menu, index);
        _gcnewoption_entrypoint_13(menu, index, &D_808083D8_chgameselect);
        if (play_sound != 0) {
            func_80803CE0_chgameselect();
        }
    }
}

int func_8080413C_chgameselect(Actor *actor)
{
    func_8080218C_chgameselect((u32) (*(u8 *) ((char *) (actor) + 0x79)) >> 4, 1);
    func_80801658_chgameselect((*(s32 *) ((char *) (actor) + 0x28)), 1);
    func_80803D00_chgameselect(((u32) (*(u8 *) ((char *) (actor) + 0x79)) >> 4) + 8, 1);
    func_800DA3B8(0xD69, func_80803718_chgameselect());
    func_80803888_chgameselect(
        actor, func_808037C0_chgameselect((u32) (*(u8 *) ((char *) (actor) + 0x79)) >> 4), 0);
    return -1;
}

int func_808041C8_chgameselect(Actor *actor)
{
    func_808015DC_chgameselect((*(s32 *) ((char *) (actor) + 0x28)), 2);
    func_808016A0_chgameselect((*(s32 *) ((char *) (actor) + 0x28)), 1);
    func_808016E8_chgameselect((*(s32 *) ((char *) (actor) + 0x28)), 0);
    func_80803D00_chgameselect(1, 1);
    return 1;
}

// Matching: the line breaks in this function are needed for the match.
int func_80804220_chgameselect(Actor *actor)
{
    func_8080218C_chgameselect(*(s32 *)((char *)actor + 0x1C), func_80803D60_chgameselect(*(s32 *)((char *)actor + 0x1C)));
    func_8080218C_chgameselect(*(s32 *)((char *)actor + 0x20), func_80803D60_chgameselect(*(s32 *)((char *)actor + 0x20)));
    func_80801758_chgameselect(*(s32 *)((char *)actor + 0x28), -1);
    func_80801658_chgameselect(*(s32 *)((char *)actor + 0x28), 0);
    func_808015DC_chgameselect(*(s32 *)((char *)actor + 0x28), 0);
    func_808016A0_chgameselect(*(s32 *)((char *)actor + 0x28), 0);
    func_808016E8_chgameselect(*(s32 *)((char *)actor + 0x28), 3);
}

s32 func_808042A8_chgameselect(Actor *actor, s32 slot, s32 *out_state)
{
    s32 result;

    // Matching: empty block is needed for the match.
    if (1) {
    }
    result = 0;
    switch (*(s32 *) ((u8 *) actor + 0x18)) {
        case 0:
            if (func_808036F8_chgameselect(slot)) {
                *out_state = 2;
                *(s32 *) ((u8 *) actor + 0x18) = 1;
                *(s32 *) ((u8 *) actor + 0x1C) = slot;
                func_80801758_chgameselect(*(s32 *) ((u8 *) actor + 0x28), slot);
                func_8080218C_chgameselect(slot, 0);
            } else {
                *out_state = 6;
                result = 1;
            }
            break;
        case 1:
            if (func_808036F8_chgameselect(slot)) {
                *out_state = 8;
                result = 1;
            } else {
                *out_state = 3;
                *(s32 *) ((u8 *) actor + 0x18) = 2;
                *(s32 *) ((u8 *) actor + 0x20) = slot;
                func_80801658_chgameselect(*(s32 *) ((u8 *) actor + 0x28), 1);
                actor->unk64_20 = 1;
            }
            break;
        case 2:
            if (!actor->unk64_20) {
                *out_state = 4;
                *(s32 *) ((u8 *) actor + 0x18) = 3;
                func_80803698_chgameselect(*(s32 *) ((u8 *) actor + 0x20),
                                           *(s32 *) ((u8 *) actor + 0x1C));
                func_80801714_chgameselect(*(s32 *) ((u8 *) actor + 0x28), 1);
            }
    }
    return result;
}

int func_80804404_chgameselect(s32 actor[1], s32 unk_1)
{
    // Matching: temporary holding the constants is needed for the match.
    int value;
    value = 3;
    if (actor[6] >= value) {
        value = 1;
        func_80800478_chgameselect(actor, value);
    } else {
        *(u8 *) ((char *) actor + 0x65) &= 0xFFEF;
    }
}

int func_8080444C_chgameselect(Actor *actor)
{
    s32 child;
    child = (*(s32 *) ((char *) (actor) + 0x28));
    func_808015DC_chgameselect((s32 *) child, 1);
    func_808016A0_chgameselect((s32 *) (*(s32 *) ((char *) (actor) + 0x28)), 1);
    // Matching: `0 | 0` is needed for the match.
    func_808016E8_chgameselect((s32 *) (*(s32 *) ((char *) (actor) + 0x28)), 0 | 0);
    func_80803D00_chgameselect(1, 1);
    return 1;
}

int func_808044A4_chgameselect(Actor *actor)
{
    func_8080218C_chgameselect(*(s32 **) ((char *) actor + 0x1C),
                               func_80803D60_chgameselect(*(s32 **) ((char *) actor + 0x1C)));
    func_80801658_chgameselect(*(s32 **) ((char *) actor + 0x28), 0);
    func_808015DC_chgameselect(*(s32 **) ((char *) actor + 0x28), 0);
    func_808016A0_chgameselect(*(s32 **) ((char *) actor + 0x28), 0);
    func_808016E8_chgameselect(*(s32 **) ((char *) actor + 0x28), 4);
}

s32 func_8080450C_chgameselect(Actor *actor, s32 slot, s32 *next_state)
{
    s32 done;

    done = 0;
    switch (actor->actorData[0]) {
        case 0:
            if (func_808036F8_chgameselect(slot) != 0) {
                *next_state = 2;
                actor->actorData[0] = 1;
                actor->actorData[1] = slot;
                func_80801658_chgameselect(actor->actorData[4], 1);
                actor->unk64_20 = 1;
            } else {
                *next_state = 5;
                done = 1;
            }
            break;
        case 1:
            if (!actor->unk64_20) {
                *next_state = 3;
                actor->actorData[0] = 2;
                func_80803658_chgameselect(actor->actorData[1]);
                func_80801714_chgameselect(actor->actorData[4], 1);
            }
    }
    return done;
}

int func_808045E4_chgameselect(Actor *actor, s32 unused)
{
    if (*(s32 *) ((char *) actor + 0x18) >= 2) {
        func_80800478_chgameselect(actor, 1);
    } else {
        *(u8 *) ((char *) actor + 0x65) &= 0xFFEF;
    }
}

s32 func_8080462C_chgameselect(Actor *actor)
{
    func_80801658_chgameselect(actor->actorData[4], 1);
    func_80802AD4_chgameselect(actor->actorData[6],
                               D_80807DB0_chgameselect[actor->unk79_4].sound, 3, 1, 0);
    func_80803D00_chgameselect(5, 1);
    return 1;
}

void func_80804694_chgameselect(Actor *actor)
{
    func_80801658_chgameselect(*(void **) ((char *) actor + 0x28), 0);
    func_80802BE8_chgameselect(*(void **) ((char *) actor + 0x30));
    _glglobalsettings_entrypoint_2();
}

int func_808046D0_chgameselect(s32 unused, s32 menu)
{
    s32 i;
    s16 *table;
    table = (s16 *) &D_808083E0_chgameselect;
    for (i = 0; i < 3; i++) {
        func_808049E8_chgameselect(menu, i, func_80804948_chgameselect(i));
        _gcnewoption_entrypoint_31(menu, i, *table);
        table += 1;
    }
}

s32 func_80804750_chgameselect(s32 *actor, s32 menu, s32 item)
{
    s32 next_state;
    s32 value;

    next_state = -1;
    if (actor[6] == -2) {
        func_80804A38_chgameselect(actor);
    } else if (actor[6] != 0) {
        value = _gcnewoption_entrypoint_20(menu, item);
        func_80803C80_chgameselect();
        func_8080499C_chgameselect(item, value);
        if (item == 1) {
            if (value) {
                next_state = 6;
            } else {
                next_state = 7;
            }
            actor[6] = -2;
        } else {
            func_80804A38_chgameselect(actor);
        }
    } else if (actor[6] == 0) {
        func_80802C10_chgameselect(actor[12]);
        switch (item) {
            case 0:
                next_state = 2;
                actor[6] = -1;
                func_80108B04(actor, 0x1E8);
                break;
            case 1:
                next_state = 3;
                actor[6] = 2;
                break;
            case 2:
                next_state = 4;
                actor[6] = 4;
        }
    }
    return next_state;
}

void func_80804878_chgameselect(s32 *actor, s32 menu, s32 item)
{
    if (actor[6]) {
        func_80804A38_chgameselect(actor);
        if (!item) {
            _glglobalsettings_entrypoint_6(0, 0);
        } else {
            func_808049E8_chgameselect(menu, item, func_80804948_chgameselect(item));
        }
    } else {
        func_80802C7C_chgameselect(actor[12]);
    }
}

void func_808048F8_chgameselect(u8 *actor, s32 *next_state)
{
    if (*(s32 *) (actor + 0x18) < -1) {
        func_80802C48_chgameselect(*(s32 *) (actor + 0x30), next_state);
        *(s32 *) (actor + 0x18) = 0;
        *next_state = 1;
    }
}

// Reads the global setting behind an options item.
int func_80804948_chgameselect(item)
s32 item;
{
    switch (item) {
        case 1:
            return _glglobalsettings_entrypoint_3();
        case 2:
            return _glglobalsettings_entrypoint_7();
        default:
            return 0;
    }
}

// Writes the global setting behind an options item.
s32 func_8080499C_chgameselect(item, value)
s32 item;
s32 value;
{
    switch (item) {
        case 1:
            _glglobalsettings_entrypoint_4(value);
            break;
        case 2:
            _glglobalsettings_entrypoint_8(value);
    }
}

// Shows the text of the given choice on an options row.
int func_808049E8_chgameselect(menu, item, choice)
s32 menu;
s32 item;
s32 choice;
{
    s16 entry_id;
    int index;
    // Matching: the empty block and empty loop are needed for the match.
    {
    }
    do {
    } while (0);
    index = (item * 5) + choice;
    entry_id = (s16) (index + 0xA);
    _gcnewoption_entrypoint_24(menu);
    _gcnewoption_entrypoint_12(menu, item, entry_id);
}

int func_80804A38_chgameselect(actor)
Actor *actor;
{
    func_80802C48_chgameselect(*(s32 *) ((char *) actor + 0x30));
    func_808026C8_chgameselect(*(s32 *) ((char *) actor + 0x2C), 1);
    *(s32 *) ((char *) actor + 0x18) = 0;
    if (*(s32 *) ((char *) actor + 0x34) != 0) {
        func_800FFA88(*(s32 *) ((char *) actor + 0x34));
        *(s32 *) ((char *) actor + 0x34) = 0;
    }
}

// Cycles an options row to the next choice, wrapping around.
void func_80804A8C_chgameselect(Actor *actor, s32 menu, s32 item)
{
    s32 choice;

    if ((s32) actor->actorData[0] > 0) {
        choice = _gcnewoption_entrypoint_20(menu, item) + 1;
        if (choice >= (s32) actor->actorData[0]) {
            choice = 0;
        }
        func_808049E8_chgameselect(menu, item, choice);
    }
}

// Cycles an options row to the previous choice, wrapping around.
void func_80804AF0_chgameselect(u8 *actor, s32 menu, s32 item)
{
    s32 choice;
    if (*(s32 *) (actor + 0x18) > 0) {
        choice = _gcnewoption_entrypoint_20(menu, item) - 1;
        if (choice < 0) {
            choice = *(s32 *) (actor + 0x18) - 1;
        }
        func_808049E8_chgameselect(menu, item, choice);
    }
}

int func_80804B4C_chgameselect(Actor *actor)
{
    func_80801658_chgameselect(*(s32 **) ((char *) actor + 0x28), 1);
    func_80803D00_chgameselect(6, 1);
    func_80804C30_chgameselect(actor, 0);
    return -1;
}

void func_80804B90_chgameselect(u8 *actor)
{
    func_80801658_chgameselect(*(s32 **) (actor + 0x28), 0);
}

void func_80804BB4_chgameselect(s32 actor, s32 unused, s32 item)
{
    if (item < 3) {
        func_80804D30_chgameselect(actor, item);
    } else {
        func_808038EC_chgameselect(actor, item, 1);
    }
}

int func_80804BF4_chgameselect(s32 actor[3], s32 unused, s32 item)
{
    if (item < 3) {
        func_80800478_chgameselect(actor, 1);
    } else {
        func_80804C30_chgameselect(actor, actor[6]);
    }
}

// Fills the info panel with the game modes that are available.
void func_80804C30_chgameselect(actor, mode) Actor *actor;
s32 mode;
{
    s32 i;
    s32 count = 0;
    s32 selected = 0;

    func_80802D40_chgameselect(actor->actorData[6], 3, 0);
    for (i = 0; i != 3; i++) {
        if (_gcfrontend_entrypoint_1(D_808083E8_chgameselect[i][1])) {
            func_80802DB4_chgameselect(actor->actorData[6], i, i + 10, -1, -1,
                                       D_808083E8_chgameselect[i][2]);
            if (mode == D_808083E8_chgameselect[i][1]) {
                selected = count;
            }
            count++;
        }
    }
    func_80802E38_chgameselect(actor->actorData[6],
                               D_80807DB0_chgameselect[actor->unk79_4].sound, selected, 0);
    func_808026C8_chgameselect(actor->actorData[5], 2);
}

// Fills the info panel with the entries of one game mode group.
void func_80804D30_chgameselect(actor, group) Actor *actor;
s32 group;
{
    s32 i;
    s32 first;
    s32 count;
    s32 mode;

    mode = D_808083E8_chgameselect[group][1];
    count = _gcfrontend_entrypoint_4(mode);
    first = _gcfrontend_entrypoint_5(mode);
    func_80802D40_chgameselect((Unk80132ED0 *) actor->actorData[6], count, 0);
    i = 0;
    if (count > 0) {
        do {
            if (_gcfrontend_entrypoint_3((first + i))) {
                func_80802DB4_chgameselect((void *) actor->actorData[6], (first + i),
                                           i, -1, -1,
                                           _gcfrontend_entrypoint_14((first + i)));
            }
            i++;
        } while (i != count);
    }
    func_80802E38_chgameselect((void *) actor->actorData[6], D_808083E8_chgameselect[group][0],
                               0, 0);
    func_808026C8_chgameselect(actor->actorData[5], group + 3);
    actor->actorData[0] = mode;
}

int func_80804E34_chgameselect(Actor *actor)
{
    s32 *menu = (s32 *) ((char *) actor + 0x28);
    func_80801658_chgameselect(*menu, 1);
    if (_gcstatusDll_entrypoint_18() == 0xA) {
        *(s32 *) ((char *) actor + 0x20) = 0;
    } else if (_gcstatusDll_entrypoint_18() == 0x14) {
        *(s32 *) ((char *) actor + 0x20) = 1;
    } else if (_gcstatusDll_entrypoint_17() == 5) {
        *(s32 *) ((char *) actor + 0x20) = 2;
    } else if (_gcstatusDll_entrypoint_17() == 0xA) {
        *(s32 *) ((char *) actor + 0x20) = 3;
    } else {
        *(s32 *) ((char *) actor + 0x20) = 0;
    }
    *(u8 *) ((char *) actor + 0x65) &= ~0x10;
    if (func_800AA0B8()) {
        func_808065C0_chgameselect(actor);
    } else {
        func_80805310_chgameselect(actor);
        func_80803D00_chgameselect(4, 1);
    }
    return -1;
}

void func_80804F14_chgameselect(void *actor)
{
    func_80801658_chgameselect((*(void **) ((char *) actor + 0x28)), 0);
}

void func_80806A88_chgameselect();

void func_80806834_chgameselect();

void func_80806540_chgameselect();

void func_80806408_chgameselect();

void func_808061A8_chgameselect();

void func_80805FCC_chgameselect();

s32 func_80805F30_chgameselect();

void func_80805CD8_chgameselect();

void func_80805474_chgameselect();

void func_8080537C_chgameselect();

void func_80804F38_chgameselect(Actor *actor, s32 param_1, s32 item)
{
    switch (actor->actorData[0]) {
        case 0:
            func_80802BE8_chgameselect(*(s32 *) ((u8 *) actor + 0x30));
            _gcstatusDll_entrypoint_2(item + 2);
            func_808069C8_chgameselect(func_808068E8_chgameselect());
            func_80806A88_chgameselect(func_80806A30_chgameselect());
            if (_gcstatusDll_entrypoint_10() < 3 && _gcstatusDll_entrypoint_14() == 4) {
                _gcstatusDll_entrypoint_4(1);
            }
            func_80805474_chgameselect((s32) actor, 0);
            break;
        case 1:
            switch (item) {
                case 0:
                    func_80805BFC_chgameselect((s32) actor, 0);
                    break;
                case 1:
                    func_80806408_chgameselect((u8 *) actor);
                    break;
                case 2:
                    func_80806540_chgameselect((s32) actor);
            }
            break;
        case 2:
            *(s32 *) ((u8 *) actor + 0x54) = item;
            switch (_gcfrontend_entrypoint_6(item)) {
                case 1:
                    func_80805CD8_chgameselect(actor, 0);
                    break;
                case 2:
                    func_8080537C_chgameselect(actor, 10, 0);
                    break;
                case 3:
                    func_8080537C_chgameselect(actor, 11, 0);
                    break;
                default:
                    func_80803BE8_chgameselect(actor);
            }
            break;
        case 10:
            func_80805F30_chgameselect(actor, item);
            func_80803BE8_chgameselect(actor);
            break;
        case 11:
            func_80805FCC_chgameselect((s32) actor, item);
            func_80803BE8_chgameselect(actor);
            break;
        case 8:
            func_80806744_chgameselect(actor);
            break;
        case 3:
            switch (item) {
                case 0:
                    func_808061A8_chgameselect((u8 *) actor);
                    break;
                case 2:
                    func_80806834_chgameselect(actor);
                    break;
                default:
                    func_8080537C_chgameselect(actor, item + 4,
                                               func_80805ECC_chgameselect(actor, item));
            }
            break;
        case 5:
        case 6:
        case 7:
            func_80806068_chgameselect(actor, actor->actorData[0] - 4, item);
            func_808051B4_chgameselect(actor, param_1, item);
            break;
        default:
            func_80800478_chgameselect(actor, 1);
    }
}

void func_80806370_chgameselect();

void func_808051B4_chgameselect(actor, param_1, unused) Actor *actor;
s32 param_1;
s32 unused;
{
    switch (actor->actorData[0]) {
        case 0:
            func_80802BE8_chgameselect(actor->actorData[6], param_1);
            func_80800478_chgameselect(actor, 1);
            break;
        case 1:
            func_80805310_chgameselect(actor);
            break;
        case 2:
            func_80805474_chgameselect((s32) actor, 0);
            break;
        case 8:
            func_80805474_chgameselect((s32) actor, 1);
            break;
        case 3:
            if (actor->unk64_20)
                func_80803BE8_chgameselect(actor);
            else
                func_80805BFC_chgameselect(actor, 0);
            break;
        case 10:
        case 11:
            func_80805BFC_chgameselect(actor, 0);
            break;
        case 5:
            func_80805CD8_chgameselect(actor, 1);
            break;
        case 6:
            func_808068AC_chgameselect(actor);
            func_80805CD8_chgameselect(actor, 2);
            break;
        case 7:
            func_80805CD8_chgameselect(actor, 3);
            break;
        case 4:
            func_80806370_chgameselect(actor);
            func_80805CD8_chgameselect(actor, 0);
            break;
        default:
            func_80800478_chgameselect(actor, 1);
    }
}

void func_80805310_chgameselect(actor) Actor *actor;
{
    s32 panel;
    u8 byte_79;
    s16 sound;
    panel = *((s32 *) (((char *) actor) + 0x30));
    // Matching: the repeated & 0xFF masks are needed for the match.
    byte_79 = *((u8 *) (((char *) actor) + 0x79));
    sound =
        *((s16 *) (((char *) D_80807DB0_chgameselect) +
                   (((((((((((((((u32) byte_79) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) &
                          0xFF) &
                         0xFF) &
                        0xFF) &
                       0xFF) &
                      0xFF) >>
                     4) *
                    4)));
    func_80802AD4_chgameselect(panel, sound, 3, 1, 0);
    func_80802D04_chgameselect(*((s32 *) (((char *) actor) + 0x30)), 1);
    func_808026C8_chgameselect(*((s32 *) (((char *) actor) + 0x2C)), 2);
    *((s32 *) (((char *) actor) + 0x18)) = 0;
}

void func_8080537C_chgameselect(s32 *actor, s32 layout, s32 selected)
{
    s32 i;

    func_80802D40_chgameselect(actor[0x30 / 4], D_80808424_chgameselect[layout].count,
                               D_80808424_chgameselect[layout].unk6);
    for (i = 0; i < D_80808424_chgameselect[layout].count; i++) {
        func_80802DB4_chgameselect(
            actor[0x30 / 4], i, D_80808424_chgameselect[layout].unk1 + i, -1,
            (D_80808424_chgameselect[layout].unk3 >= 0)
                ? D_80808424_chgameselect[layout].unk3 + i
                : -1,
            (D_80808424_chgameselect[layout].unk8) ? D_80808424_chgameselect[layout].unk8[i]
                                                    : 0x9D);
    }
    func_80802E38_chgameselect(actor[0x30 / 4], D_80808424_chgameselect[layout].unk4, selected,
                               4);
    func_808026C8_chgameselect(actor[0x2C / 4], D_80808424_chgameselect[layout].unk2);
    actor[0x18 / 4] = layout;
}

void func_80805474_chgameselect(s32 actor, s32 selected)
{
    func_8080537C_chgameselect(actor, 0x1, selected);
}

void func_80805498_chgameselect(u8 *actor, void *menu)
{
    s32 i;
    s32 player_count;

    switch (*(s32 *) (actor + 0x18)) {
        case 0:
            for (i = 0; i != 3; i++) {
                _gcnewoption_entrypoint_12(menu, i, i + 0xC);
                _gcnewoption_entrypoint_31(menu, i, D_808083FC_chgameselect[i]);
                func_80805BA0_chgameselect(menu, i, 0);
            }
            _gcnewoption_entrypoint_41(
                menu, _gcstatusDll_entrypoint_10() >= 2 ? _gcstatusDll_entrypoint_10() - 2 : 0);
            break;
        case 4:
            player_count = _gcstatusDll_entrypoint_10();
            for (i = 0; i < player_count; i++) {
                func_80806218_chgameselect(menu, i, func_808062A8_chgameselect(i),
                                           0);
            }
            break;
        case 6:
            _gcnewoption_entrypoint_12(menu, 0, 0);
            _gcnewoption_entrypoint_12(menu, 1, 1);
            _gcnewoption_entrypoint_12(menu, 2, 2);
            func_80806AF4_chgameselect(menu, 4, func_80806A30_chgameselect());
            if (_gcstatusDll_entrypoint_10() < 3) {
                _gcnewoption_entrypoint_12(menu, 3, 0xC);
                func_8080401C_chgameselect(menu, 3, 0);
            } else {
                func_80806AF4_chgameselect(menu, 3, func_808068E8_chgameselect());
            }
            for (i = 0; i != 5; i++) {
                _gcnewoption_entrypoint_31(menu, i, D_8080840C_chgameselect[i]);
            }
            _gcnewoption_entrypoint_41(menu, func_80805ECC_chgameselect(actor, 2));
    }
}

void func_8080569C_chgameselect(u8 *actor, u32 menu)
{
    s32 player_count;
    s32 i;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 buttons[2];
    f32 stick[2];
    Mass63GameSelectInput *input;
    u8 *player_state;

    switch (*(s32 *) (actor + 0x18)) {
        case 0:
        for (i = 0; i != 3; i++) {
            func_80805BA0_chgameselect(menu, i, 1);
        }
        return;
        case 4:
        player_count = _gcstatusDll_entrypoint_10();
        input = (Mass63GameSelectInput *) func_80100094(actor, 1);
        i = 0;
        if (player_count > 0) {
            player_state = input->local_0;
            do {
                func_80016068(i, stick);
                func_80015E80(i, buttons);

                switch (*player_state) {
                    case 1:
                    if (func_800D9078(&input->local_1[i])) *player_state = 0;
                    break;
                    case 0:
                    if (1 == buttons[0]) {
                        *player_state = 2;
                        _gcnewoption_entrypoint_43(menu, i, 1);
                        func_80803CC0_chgameselect();
                    } else if (stick[0] > 0.8f) {
                        func_808062EC_chgameselect(menu, i, 1);
                        *player_state = 1;
                        input->local_1[i] = 0.5f;
                    } else if (stick[0] < -0.8f) {
                        func_808062EC_chgameselect(menu, i, -1);
                        *player_state = 1;
                        input->local_1[i] = 0.5f;
                    }
                    break;
                    case 2:
                    if (1 == buttons[1]) {
                        *player_state = 0;
                        _gcnewoption_entrypoint_43(menu, i, 0);
                        func_80803CE0_chgameselect();
                    }
                }
                i++;
                player_state++;
            } while (i != player_count);
        }
        i = 0;
        if (player_count > 0) {
            player_state = input->local_0;
            do {
                if (2 != *player_state) break;
                i++;
                player_state++;
            } while (i < player_count);
        }
        if (i == player_count && func_80802F8C_chgameselect(*(s32 *)(actor + 0x30))) {
            ((Actor *)actor)->unk64_20 = 1;
        }
        return;
        case 6:
        func_808026C8_chgameselect(*(s32 *)(actor + 0x24), _gcnewoption_entrypoint_45(menu) + 0x1E);
        return;
        default:
        if (func_80015FA0(0) && func_80802F8C_chgameselect(*(s32 *)(actor + 0x30))) {
            ((Actor *)actor)->unk64_20 = 1;
        }
    }
}


int func_8080595C_chgameselect(s32 *actor, s32 menu, s32 item)
{
    s32 choice;

    switch (actor[6]) {
    case 0:
        if (_gcnewoption_entrypoint_19(menu, item)) {
            func_80803C60_chgameselect();
            return item + 0x23;
        }
        func_80802CC0_chgameselect(actor[12]);
        return -1;
    case 6:
        if (item == 3 || item == 4) {
            if (actor[7] != -1) {
                choice = _gcnewoption_entrypoint_20(menu, item);
                if (item == 3) func_808069C8_chgameselect(choice);
                else func_80806A88_chgameselect(choice);
                actor[7] = -1;
}
else
{
    if (_gcnewoption_entrypoint_19(menu, item)) {
        func_80803C60_chgameselect();
        return 0x1E;
    }

func_80802C10_chgameselect(actor[12]);
actor[7] = item;
return (item == 3) ? 0x1F : 0x20;
}
}
func_80802CC0_chgameselect(actor[12]);
func_80803C80_chgameselect();
}
return -1;
}
void func_80805AC0_chgameselect(u8 *actor, s32 menu, s32 item)
{
    s32 state;
    s32 pending;

    state = *(s32 *) (actor + 0x18);
    switch (state) {
        case 0:
            func_80802C7C_chgameselect(*(s32 *) (actor + 0x30));
            break;
        case 6:
            pending = *(s32 *) (actor + 0x1C);
            if (pending != -1 && item == pending) {
                func_80802C48_chgameselect(*(s32 *) (actor + 0x30));
                func_808026C8_chgameselect(*(s32 *) (actor + 0x2C), 9);
                *(s32 *) (actor + 0x1C) = -1;
                if (item == 3) {
                    state = func_808068E8_chgameselect();
                } else {
                    state = func_80806A30_chgameselect();
                }
                func_80806AF4_chgameselect((void *) menu, item, state);
            } else {
                func_80802C7C_chgameselect(*(s32 *) (actor + 0x30));
            }
    }
}

int func_80805BA0_chgameselect(menu, item, flag)
s32 menu;
s32 item;
s32 flag;
{
    if (func_80803E40_chgameselect() >= (item + 2)) {
        func_8080407C_chgameselect(menu, item, flag);
        return;
    }
    func_8080401C_chgameselect(menu, item, flag);
}

int func_80805BFC_chgameselect(s32 actor, s32 selected)
{
    s32 count;
    s32 first;
    s32 i;
    s32 entry;
    count = _gcfrontend_entrypoint_4(3);
    first = _gcfrontend_entrypoint_5(3);
    func_80802D40_chgameselect(*(s32 **) ((char *) actor + 0x30), count, 0);
    i = 0;
    if (count > 0) {
        entry = first;
        do {
            if (_gcfrontend_entrypoint_3(entry) != 0) {
                func_80802DB4_chgameselect(*(s32 **) ((char *) actor + 0x30), entry, i,
                                           -1, -1, _gcfrontend_entrypoint_14(entry));
            }
            i += 1;
            entry += 1;
        } while (i != count);
    }
    func_80802E38_chgameselect(*(s32 **) ((char *) actor + 0x30), 0x18E4, selected, 0);
    func_808026C8_chgameselect(*(s32 **) ((char *) actor + 0x2C), 4);
    *(s32 **) ((char *) actor + 0x18) = 2;
}

void func_80805CD8_chgameselect(Actor *actor, s32 selected)
{
    s32 has_extra;
    s32 value;
    s32 text_id;

    has_extra = 0;
    func_80806068_chgameselect(actor, 1, actor->actorData[2]);
    if (_gcstatusDll_entrypoint_14() == 6) {
        _gcstatusDll_entrypoint_4(1);
    }
    func_80806068_chgameselect(actor, 2, _gcstatusDll_entrypoint_14() - 1);
    value = func_80805ECC_chgameselect(actor, 2);
    if (value == 2 || value == 4) {
        has_extra = 1;
    }
    switch (value) {
        case 3:
            text_id = func_808068E8_chgameselect() + 10;
            break;
        case 4:
            text_id = func_80806A30_chgameselect() + 20;
            break;
        default:
            text_id = value + 5;
            break;
    }
    func_80802D40_chgameselect(actor->actorData[6], 4, 0);
    func_80802DB4_chgameselect(actor->actorData[6], 0, 0, -1, -1, D_80808404_chgameselect[0]);
    value = func_80805ECC_chgameselect(actor, 1);
    func_80802DB4_chgameselect(actor->actorData[6], 1, value + 0x23, has_extra ? 0x26 : -1, -1,
                               D_80808405_chgameselect);
    func_80802DB4_chgameselect(actor->actorData[6], 2, text_id, -1, -1, D_80808406_chgameselect);
    value = func_80805ECC_chgameselect(actor, 3);
    func_80802DB4_chgameselect(actor->actorData[6], 3, value + 0x1B, has_extra ? 0x27 : -1, -1,
                               D_80808407_chgameselect);
    func_80802E38_chgameselect(actor->actorData[6], 0x18F4, selected, 4);
    func_808026C8_chgameselect(actor->actorData[5], 6);
    actor->actorData[0] = 3;
    func_80802D04_chgameselect(actor->actorData[6], 1);
}

// Returns the current setting for the given kind.
s32 func_80805ECC_chgameselect(actor, kind)
u8 *actor;
s32 kind;
{
    switch (kind) {
        case 1:
            return (*(s32 *) ((s8 *) (actor) + (0x20)));
        case 2:
            return _gcstatusDll_entrypoint_14() - 1;
        case 3:
            return _gcstatusDll_entrypoint_19() - 2;
        default:
            return 0;
    }
}

s32 func_80805F30_chgameselect(volatile s32 unused, s32 choice)
{
    switch (choice) {
        case 0:
            _gcstatusDll_entrypoint_8(0xA);
            _gcstatusDll_entrypoint_7(0);
            return;
        case 1:
            _gcstatusDll_entrypoint_8(0x14);
            _gcstatusDll_entrypoint_7(0);
            return;
        case 2:
            _gcstatusDll_entrypoint_8(0);
            _gcstatusDll_entrypoint_7(2);
            return;
        case 3:
            _gcstatusDll_entrypoint_8(0);
            _gcstatusDll_entrypoint_7(5);
            return;
    }
}

void func_80805FCC_chgameselect(s32 unused, s32 choice)
{
    switch (choice) {
        case 0:
            _gcstatusDll_entrypoint_8(0xF);
            _gcstatusDll_entrypoint_7(0);
            return;
        case 1:
            _gcstatusDll_entrypoint_8(0x1E);
            _gcstatusDll_entrypoint_7(0);
            return;
        case 2:
            _gcstatusDll_entrypoint_8(0);
            _gcstatusDll_entrypoint_7(5);
            return;
        case 3:
            _gcstatusDll_entrypoint_8(0);
            _gcstatusDll_entrypoint_7(0xA);
    }
}

// Applies a setting value for the given kind.
void func_80806068_chgameselect(actor, kind, value) Actor *actor;
s32 kind;
s32 value;
{
    switch (kind) {
        case 1:
            *(s32 *) ((u8 *) actor + 0x20) = value;
            switch (value) {
                case 0:
                    _gcstatusDll_entrypoint_8(10);
                    _gcstatusDll_entrypoint_7(0);
                    return;
                case 1:
                    _gcstatusDll_entrypoint_8(20);
                    _gcstatusDll_entrypoint_7(0);
                    return;
                case 2:
                    _gcstatusDll_entrypoint_8(0);
                    _gcstatusDll_entrypoint_7(5);
                    return;
                case 3:
                    _gcstatusDll_entrypoint_8(0);
                    _gcstatusDll_entrypoint_7(10);
            }
            break;
        case 2:
            _gcstatusDll_entrypoint_4(value + 1);
            switch (value) {
                case 2:
                case 4:
                    func_80806068_chgameselect(actor, 1, 2);
                    _gcstatusDll_entrypoint_9(0);
                    return;
                case 3:
                default:
                    if (!_gcstatusDll_entrypoint_19())
                        _gcstatusDll_entrypoint_9(2);
                    return;
            }
        case 3:
            _gcstatusDll_entrypoint_9(value + 2);
    }
}

void func_808061A8_chgameselect(u8 *actor)
{
    func_80802AD4_chgameselect((*(s32 *) ((s8 *) (actor) + (0x30))), 0x18EF,
                               _gcstatusDll_entrypoint_10(), 0, 0);
    func_80802D04_chgameselect((*(s32 *) ((s8 *) (actor) + (0x30))), 1);
    func_808026C8_chgameselect((*(s32 *) ((s8 *) (actor) + (0x2C))), 7);
    (*(s32 *) ((s8 *) (actor) + (0x18))) = 4;
    func_80100074(actor, 1, 0x14);
}

void func_80806218_chgameselect(menu, row, choice, refresh) s32 menu;
s32 row;
s32 choice;
s32 refresh;
{
    _gcnewoption_entrypoint_24();
    _gcnewoption_entrypoint_12(menu, row, (s16) (row * 10 + choice));
    _gcnewoption_entrypoint_31(menu, row, D_8080841C_chgameselect[choice]);
    if (refresh)
        _gczoomboxdata_entrypoint_0(D_8080841C_chgameselect[choice]);
}

int func_808062A8_chgameselect()
{
    return _gcstatusDll_entrypoint_13() - 1;
}

s32 func_808062CC_chgameselect(s32 player, s32 choice)
{
    _gcstatusDll_entrypoint_3(player, choice + 1);
}

// Steps a row's choice by delta within 0..4, skipping choice 2 while it is locked.
int func_808062EC_chgameselect(s32 menu, s32 row, s32 delta)
{
    s32 choice;
    s32 unlocked;
    choice = _gcnewoption_entrypoint_20(menu, row) + delta;
    if (choice == 2) {
        unlocked = func_800DA298(0xC0B);
        if (!unlocked) {
            choice += delta;
        }
    }
    if (choice >= 5) {
        choice = 0;
    } else if (choice < 0) {
        choice = 4;
    }
    func_80806218_chgameselect(menu, row, choice, 1);
}

void func_80806370_chgameselect(actor, menu) u8 *actor;
s32 menu;
{
    s32 limit;
    s32 player_count;
    s32 i;

    player_count = _gcstatusDll_entrypoint_10();
    limit = player_count;
    i = 0;
    (*(u8 *) ((s8 *) (actor) + (0x65))) = (u8) ((*(u8 *) ((s8 *) (actor) + (0x65))) & 0xFFEF);
    if (player_count > 0) {
        do {
            func_808062CC_chgameselect(i, _gcnewoption_entrypoint_20(menu, i));
            i += 1;
        } while (i < limit);
    }
    func_80802BE8_chgameselect((*(s32 *) ((s8 *) (actor) + (0x30))));
    func_80100074(actor, 1, 0);
}

void func_80806408_chgameselect(u8 *actor)
{
    s32 first;
    s32 unk_0;
    s32 count;
    s32 entry;
    s32 i;

    count = _gcfrontend_entrypoint_4(3);
    first = _gcfrontend_entrypoint_5(3);
    func_808031F4_chgameselect((*(s32 *) ((s8 *) (actor) + (0x30))), count);
    i = 0;
    if (count > 0) {
        entry = first;
        do {
            if (_gcfrontend_entrypoint_3(entry) != 0) {
                unk_0 = func_800AA274(entry);
                func_80803248_chgameselect((*(s32 *) ((s8 *) (actor) + (0x30))), entry, i,
                                           unk_0, _gcfrontend_entrypoint_14(entry));
            }
            i += 1;
            entry += 1;
        } while (i != count);
    }
    func_808032CC_chgameselect((*(s32 *) ((s8 *) (actor) + (0x30))), 0x18E4, 0, 0);
    func_808026C8_chgameselect((*(s32 *) ((s8 *) (actor) + (0x2C))), 5);
    (*(s32 *) ((s8 *) (actor) + (0x18))) = 8;
}

void func_808064E8_chgameselect(s32 unused_0, s32 unused_1, s32 entry, s32 kind)
{
    if (kind != 0xFC) {
        if ((kind != 0xFD) && (kind == 0xFE)) {
            func_800AA054(entry);
        }
    } else {
        func_800AA074(entry);
    }
}

void func_80806540_chgameselect(s32 actor)
{
    s32 count;
    s32 first;
    s32 cur;
    s32 i;

    func_800AA074();
    count = _gcfrontend_entrypoint_4(3);
    first = _gcfrontend_entrypoint_5(3);
    i = 0;
    if (count > 0) {
        cur = first;
        do {
            if (_gcfrontend_entrypoint_3(cur) != 0) {
                func_800AA054(cur);
            }
            i += 1;
            cur += 1;
        } while (i != count);
    }
    func_80806744_chgameselect(actor);
}

s32 func_808065C0_chgameselect(param_0)
s32 param_0;
{
    func_80803D00_chgameselect(7, 1);
    func_80108B04(param_0, 0x4B6);
}

void func_808065F4_chgameselect(actor) Actor *actor;
{
    s32 unk_0;
    s32 outcome;
    func_80802640_chgameselect(actor->actorData[5],
                               D_80807DB0_chgameselect[actor->unk79_4].sound, 0);
    if (func_800AA240()) {
        unk_0 = func_800AA0D0();
        if (unk_0 == 1) {
            outcome = 0;
            func_800AA074();
        } else if (func_808066CC_chgameselect() == unk_0) {
            outcome = 2;
            func_800AA074();
        } else
            outcome = 1;
        func_800AA00C();
        func_80805474_chgameselect(actor, outcome);
        func_80803D00_chgameselect(4, 1);
    } else
        func_80806744_chgameselect(actor);
}

s32 func_808066CC_chgameselect(void)
{
    s32 cur;
    s32 i;
    s32 active;
    s32 count;
    s32 first;
    active = 0;
    count = _gcfrontend_entrypoint_4(3);
    first = _gcfrontend_entrypoint_5(3);
    i = 0;
    if (count > 0) {
        cur = first;
        do {
            if (_gcfrontend_entrypoint_3(cur) != 0) {
                active += 1;
            }
            i += 1;
            cur += 1;
        } while (i != count);
    }
    return active;
}

void func_80806744_chgameselect(actor) u8 *actor;
{
    s32 unk_0;
    s32 unk_1;

    unk_0 = func_800AA0C4() + 1;
    (*(s16 *) ((s8 *) (&B_80808550_chgameselect) + (0))) = 0x18F2;
    if (func_800AA0D0() == (unk_0 + 1)) {
        (*(s16 *) ((s8 *) (&B_80808550_chgameselect) + (2))) = 0x27;
    } else {
        (*(s16 *) ((s8 *) (&B_80808550_chgameselect) + (2))) = (s16) unk_0;
    }
    (*(s16 *) ((s8 *) (&B_80808550_chgameselect) + (4))) = 0x18E4;
    unk_1 = func_800AA120();
    (*(s16 *) ((s8 *) (&B_80808550_chgameselect) + (6))) =
        (s16) (unk_1 - _gcfrontend_entrypoint_5(3));
    func_80803F90_chgameselect((*(s32 *) ((s8 *) (actor) + (0x50))), 2, &B_80808550_chgameselect);
    func_800E6A58((*(s32 *) ((s8 *) (actor) + (0x50))), 0x21);
    func_80802730_chgameselect((*(s32 *) ((s8 *) (actor) + (0x2C))),
                               (*(s32 *) ((s8 *) (actor) + (0x50))));
    (*(s32 *) ((s8 *) (actor) + (0x18))) = 9;
}

int func_80806800_chgameselect(s32 actor[4], s32 param_1)
{
    if (*(s32 *) ((s8 *) actor + 24) == 9) {
        func_80803B84_chgameselect((s32) actor);
    }
}

void func_80806834_chgameselect(Actor *actor)
{
    s32 unk_0;

    unk_0 = 4;
    func_80802AD4_chgameselect(*(s32 **) ((char *) actor + 0x30), 0x18F0, 5, 1, unk_0);
    func_80802D04_chgameselect(*(s32 **) ((char *) actor + 0x30), 1);
    func_808026C8_chgameselect(*(s32 **) ((char *) actor + 0x2C), 9);
    func_80802640_chgameselect(*(s32 **) ((char *) actor + 0x24), 0x18F0, 0);
    *(s32 **) ((char *) actor + 0x18) = 6;
    *(s32 **) ((char *) actor + 0x1C) = -1;
}

int func_808068AC_chgameselect(actor, param_1)
Actor *actor;
s32 param_1;
{
    s32 unk_0;
    unk_0 = *(s32 *) ((char *) (actor) + 0x30);
    func_80802BE8_chgameselect(unk_0);
    func_80802640_chgameselect(*(s32 *) ((char *) (actor) + 36), 0, 0);
}

s32 func_808068E8_chgameselect(void)
{
    s32 i;
    s32 count;
    s32 status;
    s32 limit;
    s32 mask;

    mask = 0;
    count = _gcstatusDll_entrypoint_10();
    limit = func_80806AA8_chgameselect();
    for (i = 0; i < count; i++) {
        status = _gcstatusDll_entrypoint_16(i);
        if (status < 4) {
            break;
        }
        if (status == 4) {
            mask |= 1 << i;
        }
    }
    if (i < count) {
        _gcstatusDll_entrypoint_6(0, 4);
        _gcstatusDll_entrypoint_6(1, 5);
        _gcstatusDll_entrypoint_6(2, 5);
        _gcstatusDll_entrypoint_6(3, 5);
        mask = 1;
    }
    if (mask <= 0) {
        mask = 1;
    } else if (limit < mask) {
        mask = limit;
    }
    return mask - 1;
}

void func_808069C8_chgameselect(selection) s32 selection;
{
    s32 i;
    s32 status;

    for (i = 0; i < 4; i++) {
        status = ((1 << i) & (selection + 1)) ? 4 : 5;
        _gcstatusDll_entrypoint_6(i, status);
    }
}

int func_80806A30_chgameselect()
{
    s32 index;
    index = _gcstatusDll_entrypoint_15();
    if (index < 0) {
        index = 0;
    } else {
        if (_gcstatusDll_entrypoint_10() <= index) {
            index = _gcstatusDll_entrypoint_10() - 1;
        }
    }
    return index;
}

void func_80806A88_chgameselect()
{
    _gcstatusDll_entrypoint_5();
}

s32 func_80806AA8_chgameselect(void)
{
    s32 status;
    status = _gcstatusDll_entrypoint_10();
    return (1 << (status + 0x1F)) - 1;
}

s32 func_80806AD4_chgameselect()
{
    return _gcstatusDll_entrypoint_10();
}

void func_80806AF4_chgameselect(param_0, param_1, param_2) void *param_0;
s32 param_1;
s32 param_2;
{
    s32 offset;

    offset = param_1 == 3 ? 5 : 15;
    _gcnewoption_entrypoint_24(param_0, param_1, param_2);
    _gcnewoption_entrypoint_12(param_0, param_1, (s16) (offset + param_2));
}

int func_80806B5C_chgameselect(s32 param_0, s32 param_1, s32 param_2)
{
    s32 next;
    s32 count;
    // Matching: the `| 0` operands are needed for the match.
    next = _gcnewoption_entrypoint_20(param_1 | 0, param_2 | 0) + 1;
    if (param_2 == 3) {
        count = func_80806AA8_chgameselect();
    } else {
        count = func_80806AD4_chgameselect();
    }
    if (next >= count) {
        next = 0;
    }
    func_80806AF4_chgameselect(param_1, param_2, next);
}

int func_80806BD4_chgameselect(s32 param_0, s32 param_1, s32 param_2)
{
    s32 prev;
    s32 count;
    prev = _gcnewoption_entrypoint_20(param_1, param_2) - 1;
    if (param_2 == 3) {
        count = func_80806AA8_chgameselect();
    } else {
        count = func_80806AD4_chgameselect();
    }
    if (prev < 0) {
        prev = count - 1;
    }
    func_80806AF4_chgameselect(param_1, param_2, prev);
}

int *chgameselect_entrypoint_6()
{
    return &D_808084B4_chgameselect;
}

void func_808073AC_chgameselect();

// Creates one zoombox per player for the multiplayer scoreboard.
void func_80806C54_chgameselect(actor) Actor *actor;
{
    u8 *data;
    u8 *entry;
    s32 i;
    s32 unk_0;
    data = func_80100094(actor, 0);
    actor->unk6C_0 = _gcstatusDll_entrypoint_10();
    i = 0;
    unk_0 = 66;
    entry = data;
    for (; (u32) i < actor->unk6C_0; i++) {
        *(s32 *) entry = _gczoombox_entrypoint_5(unk_0, 12, 2, 0, 0);
        _gczoombox_entrypoint_26(*(void **) entry, 65, 0.8f, 1.0f, 0);
        func_800C9F48(i * 0.1f, actor->unk0, i);
        *(void **) (entry + 0x10) = heap_alloc(0x100);
        unk_0 += 38;
        entry += 4;
    }
    *(void **) (data + 0x20) = heap_alloc(0x100);
    *(s16 *) (data + 0x26) = 0;
    *(s16 *) (data + 0x24) = *(s16 *) (data + 0x26);
    func_808073AC_chgameselect(actor);
}

void func_80807824_chgameselect();

void func_80806D98_chgameselect(Actor *this)
{
    u32 i;
    s32 *list;
    s32 *p;

    list = func_80100094(this, 0);
    for (i = 0; i < this->unk6C_0; i++) {
        p = list;
        _gczoombox_entrypoint_4(p[i]);
    }
    switch (this->unk70_10) {
        case 1:
            if (func_80807790_chgameselect(this, 3)) {
                func_80803CA0_chgameselect();
                func_808075D0_chgameselect(this, 2);
            }
            break;
        case 2:
            func_80807824_chgameselect(this);
            if (func_800D9078(&this->unk58) || func_80016B30(0, 0)) {
                func_808075D0_chgameselect(this, (func_800AA0D0() >= 2) ? 3 : 6);
            }
            break;
        case 3:
            if (func_80807790_chgameselect(this, 4)) {
                func_808075D0_chgameselect(this, 4);
            }
            break;
        case 4:
            if (func_80807790_chgameselect(this, 3)) {
                func_808075D0_chgameselect(this, this->unk64_20 ? 5 : 2);
            }
            break;
        case 5:
            func_80807824_chgameselect(this);
            if (func_800D9078(&this->unk58) || func_80016B30(0, 0) == 1) {
                func_808075D0_chgameselect(this, 6);
            } else if (func_80016B30(0, 1) == 1) {
                func_808075D0_chgameselect(this, 3);
            }
            break;
        case 6:
            if (func_80807790_chgameselect(this, 6)) {
                func_8010114C(this->unk3C, 0x23, 0);
                func_800FFAB0(this);
            }
    }
}

void func_80806FAC_chgameselect(actor, param_1) Actor *actor;
s32 param_1;
{
    void **boxes;
    s32 i;

    boxes = func_80100094(actor, 0);
    for (i = 0; i < actor->unk6C_0; i++) {
        _gczoombox_entrypoint_2(boxes[i], param_1);
    }
}

// Destroys the zoomboxes and frees their buffers.
void func_80807030_chgameselect(actor) Actor *actor;
{
    s32 i;
    GameSelectResources1358 *data;

    data = func_80100094(actor, 0);
    for (i = 0; i < 4; i++) {
        if (data->local_0[i]) {
            _gczoombox_entrypoint_0(data->local_0[i]);
        }
        if (data->local_1[i]) {
            heap_free(data->local_1[i]);
        }
    }
    if (data->local_2) {
        heap_free(data->local_2);
    }
}

int func_808070C0_chgameselect(actor, msg, index)
Actor *actor;
s32 msg;
s32 index;
{
    void **boxes;
    switch (msg) {
        case 0x22:
            boxes = func_80100094(actor, 0);
            _gczoombox_entrypoint_18(boxes[index]);
            _gczoombox_entrypoint_16(boxes[index]);
            _gczoombox_entrypoint_9(boxes[index]);
            _gczoombox_entrypoint_11(boxes[index]);
            break;
        default:
            return 0;
    }
    return 1;
}

// Ranks the players by score and updates their zoombox texts.
void func_8080714C_chgameselect(Actor *actor, s32 (*get_score)(s32), s32 param_2, s32 param_3,
                                s32 param_4, s32 param_5, s32 param_6)
{
    s32 i;
    RankData *data;
    s32 scores[4];
    s32 ids[4];

    data = func_80100094(actor, 0);
    for (i = 0; i < actor->unk6C_0; i++) {
        scores[i] = get_score(i);
        ids[i] = i + 1;
    }
    if (param_6 || !func_800AA194()) {
        _sumultiscore_entrypoint_0(scores, ids, actor->unk6C_0);
    } else {
        _sumultiscore_entrypoint_1(scores, ids, actor->unk6C_0);
    }
    for (i = 0; i < actor->unk6C_0; i++) {
        B_80808560_chgameselect.id = ids[i];
        B_80808560_chgameselect.score = scores[i];
        B_80808560_chgameselect.rank = (i > 0 && scores[i] == scores[i - 1])
                                           ? B_80808560_chgameselect.rank
                                           : 4 - i;
        if (scores[i] == scores[0]) {
            data->unk24 = i + 1;
        }
        if (param_5 && !actor->unk64_19) {
            func_800AA220(ids[i] - 1, B_80808560_chgameselect.rank);
        }
        func_80803E94_chgameselect(data->slot[i], 0x18F3,
                                   (((s32 *) &B_80808560_chgameselect)[param_2] == 1) ? param_4
                                                                                      : param_3,
                                   3, &B_80808560_chgameselect);
        _gczoombox_entrypoint_8(data->zoom[i], data->slot[i]);
        _gczoombox_entrypoint_27(data->zoom[i], D_808084FC_chgameselect);
    }
    if (param_5) {
        actor->unk64_19 = 1;
    }
}

void func_808073AC_chgameselect(u8 *actor)
{
    s32 unk_0;
    u8 *data;
    s32 unk_1;

    unk_0 = (*(s32 *) ((s8 *) (func_80106790((*(s32 *) ((s8 *) (actor) + (0x3C))))) + (0x2C)));
    data = func_80100094(actor, 0);
    if (func_800AA0D0() == 1) {
        func_8080714C_chgameselect(actor, &func_800AA180, 1, 0x1E, 0x1F, 0, 0);
    } else {
        func_8080714C_chgameselect(actor, &func_800AA180, 2, 0x20, 0x21, 1, 0);
    }
    (*(s16 *) ((s8 *) (&B_80808570_chgameselect) + (0))) = 0x18E4;
    unk_1 = func_800AA148();
    (*(s16 *) ((s8 *) (&B_80808570_chgameselect) + (2))) =
        (s16) (unk_1 - _gcfrontend_entrypoint_5(3));
    (*(s16 *) ((s8 *) (&B_80808570_chgameselect) + (4))) = 0x18F3;
    (*(s16 *) ((s8 *) (&B_80808570_chgameselect) + (6))) = 0x14;
    func_80803F90_chgameselect((*(s32 *) ((s8 *) (data) + (0x20))), 2, &B_80808570_chgameselect);
    func_80802730_chgameselect(unk_0, (*(s32 *) ((s8 *) (data) + (0x20))));
    (*(u8 *) ((s8 *) (actor) + (0x65))) = (u8) ((*(u8 *) ((s8 *) (actor) + (0x65))) & 0xFFEF);
}

void func_808074C8_chgameselect(Actor *actor)
{
    u32 unk_0;
    u8 *data;

    unk_0 = func_80106790(actor->unk3C)->actorData[5];
    func_8080714C_chgameselect(actor, func_800AA16C, 1, 0x1E, 0x1F, 0, 1);
    if (func_800AA240()) {
        func_80802640_chgameselect(unk_0, 0x18F3, 0);
        func_808026C8_chgameselect(unk_0, 0x16);
    } else {
        data = func_80100094(actor, 0);
        B_80808588_chgameselect[0] = func_800AA0C4() + 1;
        B_80808588_chgameselect[1] = func_800AA0D0();
        func_80803E94_chgameselect(*(s32 *) (data + 0x20), 0x18F3, 0x15, 2,
                                   B_80808588_chgameselect);
        func_80802640_chgameselect(unk_0, 0, 0);
        func_80802730_chgameselect(unk_0, *(s32 *) (data + 0x20));
    }
    actor->unk64_20 = 1;
}

void func_808075D0_chgameselect(actor, state) Actor *actor;
s32 state;
{
    s32 *unk_0;
    s32 *boxes;
    u32 i;
    boxes = (s32 *) func_80100094(actor, 0);
    switch (state) {
        case 5:
            if (func_800AA240() && !*(s16 *) ((u8 *) boxes + 0x26)) {
                func_80803CA0_chgameselect();
                *(s16 *) ((u8 *) boxes + 0x26) = 1;
            }
        case 2:
            actor->unk58 = 7.5f;
            break;
        case 3:
            for (i = 0; i < actor->unk6C_0; i++) {
                _gczoombox_entrypoint_17(boxes[i]);
                _gczoombox_entrypoint_12(boxes[i]);
            }
            if (actor->unk70_10 == 2)
                func_808074C8_chgameselect(actor);
            else if (actor->unk70_10 == 5)
                func_808073AC_chgameselect(actor);
            break;
        case 4:
            for (i = 0; i < actor->unk6C_0; i++) {
                _gczoombox_entrypoint_18(boxes[i]);
                _gczoombox_entrypoint_11(boxes[i]);
            }
            break;
        case 6:
            for (i = 0; i < actor->unk6C_0; i++)
                _gczoombox_entrypoint_34(boxes[i]);
    }
    func_80101FDC(actor, state);
}

int func_80807790_chgameselect(s32 actor, s32 state)
{
    s32 *boxes;
    u32 i;
    boxes = func_80100094(actor, 0);
    i = 0;
    // Matching: self-assignment is needed for the match.
    boxes = boxes;
    // Matching: the `^ 0` is needed for the match.
    if (((*((s32 *) (((char *) (actor ^ 0)) + 0x6C))) & 0x1FF) != 0) {
        do {
            if (_gczoombox_entrypoint_3(boxes[0]) != state) {
                return 0;
            }
            i++;
            boxes += 1;
        } while (i < ((*((s32 *) (((char *) actor) + 0x6C))) & 0x1FF));
    }
    return 1;
}

// Pulses the tint of the zoomboxes.
void func_80807824_chgameselect(s32 actor)
{
    s16 brightness;
    s32 *boxes;
    s32 *box;
    s32 phase;
    s32 wave;
    s32 i;

    boxes = func_80100094(actor, 0);
    phase = (func_8001211C() << 5) & 0x1FF;
    wave = phase;
    if (phase >= 0x100) {
        wave = 0x200 - phase;
    }
    brightness = (wave / 2) + 0x7F;
    *(s16 *) ((char *) &B_80808590_chgameselect + 4) = brightness;
    *(s16 *) ((char *) &B_80808590_chgameselect + 2) = brightness;
    *(s16 *) ((char *) &B_80808590_chgameselect + 0) = brightness;
    i = 0;
    box = boxes;
    if (*(s16 *) ((char *) boxes + 0x24) > 0) {
        do {
            _gczoombox_entrypoint_27(*box, &B_80808590_chgameselect);
            i += 1;
            box += 1;
        } while (i < *(s16 *) ((char *) boxes + 0x24));
    }
}

int chgameselect_entrypoint_7()
{
    return D_80808504_chgameselect;
}

void func_808078F0_chgameselect(void *actor)
{
    *(u16 *) ((u8 *) actor + 0x6E) &= 0xFE00;
}

// Interpolates the camera between the stored start and target poses.
void func_80807900_chgameselect(Actor *actor)
{
    f32 pos[3];
    f32 rot[3];

    if (actor->unk70_10 == 2) {
        *(f32 *) &actor->actorData[7] += *(f32 *) &actor->actorData[3] * func_800D8FF8();
        if (*(f32 *) &actor->actorData[7] >= 1.0f) {
            *(f32 *) &actor->actorData[7] = 1.0f;
            func_80101FDC(actor, 1);
        }
        func_800EFE50(pos, actor->position, (f32 *) &actor->actorData[0],
                      *(f32 *) &actor->actorData[7]);
        func_800F16AC(rot, actor->rotation, (f32 *) &actor->actorData[4],
                      *(f32 *) &actor->actorData[7]);
        func_800E39D8(pos, rot);
        func_80101180(0x4AB, 0x23, 0);
    }
}

void func_808079C8_chgameselect(s32 arg0)
{
}

s32 func_808079D0_chgameselect(s32 actor, s32 msg, S16Pair args)
{
    if (msg == 0x21) {
        func_80807A10_chgameselect(actor, args.b, args.a);
    } else {
        return 0;
    }
    return 1;
}

// Starts a camera move towards a camera-database node.
void func_80807A10_chgameselect(param_0, node, mode) Actor *param_0;
s32 node;
s32 mode;
{
    f32 dist;
    f32 pos[3];
    f32 rot[3];

    func_800E39A8(param_0->position, param_0->rotation);
    func_800A5800(node);
    _cadbfunc_entrypoint_0(&OD(0));
    _cadbfunc_entrypoint_2(&OD(4));
    dist = func_800EEAD4(param_0->position, &OD(0));
    switch (mode) {
        case 0:
            OD(7) = 1.0f;
            param_0->unk6C_0 = node;
            param_0->unk64_20 = 0;
            // Matching: int literal, not 1.0f, is needed for the match.
            OD(3) = 1;
            break;
        case 1:
            OD(7) = 0.0f;
            param_0->unk6C_0 = node;
            param_0->unk64_20 = 0;
            OD(3) = 1.0f;
            break;
        case 2:
            func_800A5800(param_0->unk6C_0);
            _cadbfunc_entrypoint_0(pos);
            _cadbfunc_entrypoint_2(rot);
            func_800EFE50(&OD(0), pos, &OD(0), 0.3f);
            func_800F16AC(&OD(4), rot, &OD(4), 0.3f);
            OD(7) = 0.0f;
            if (param_0->unk64_20) {
                dist = func_800EEAD4(param_0->position, &OD(0));
                OD(3) = 320.0f / dist;
            } else {
                OD(3) = 1.6666666f;
            }
            param_0->unk64_20 = 1;
            break;
        case 3:
            OD(7) = 0.0f;
            param_0->unk6C_0 = node;
            OD(3) = 1.6666666f;
            param_0->unk64_20 = 0;
    }
    if (dist < 0.01f) {
        func_80101FDC(param_0, 1);
    } else {
        func_80101FDC(param_0, 2);
    }
}

extern void func_8010A730();
GameSelectSound D_80807DB0_chgameselect[8] = {0x18DE, 0x2, 0x18DE, 0x2, 0x18DE, 0x2, 0x18DF, 0x3,
                                              0x18E0, 0x4, 0x18E1, 0x5, 0x18E2, 0x6, 0x18E3, 0x7};
GameSelectCallback61 D_80807DD0_chgameselect[10] = {0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0x0,
                                                    0x0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0x0,
                                                    0x0,
                                                    (void *) func_8080413C_chgameselect,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0x0,
                                                    0x0,
                                                    (void *) func_808041C8_chgameselect,
                                                    (void *) func_80804220_chgameselect,
                                                    (void *) func_808042A8_chgameselect,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    (void *) func_80804404_chgameselect,
                                                    0x0,
                                                    0x0,
                                                    (void *) func_8080444C_chgameselect,
                                                    (void *) func_808044A4_chgameselect,
                                                    (void *) func_8080450C_chgameselect,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    (void *) func_808045E4_chgameselect,
                                                    0x0,
                                                    0x0,
                                                    (void *) func_80804E34_chgameselect,
                                                    (void *) func_80804F14_chgameselect,
                                                    0,
                                                    (void *) func_80805498_chgameselect,
                                                    (void *) func_8080595C_chgameselect,
                                                    (void *) func_80805AC0_chgameselect,
                                                    (void *) func_80804F38_chgameselect,
                                                    (void *) func_808051B4_chgameselect,
                                                    (void *) func_8080569C_chgameselect,
                                                    (void *) func_808064E8_chgameselect,
                                                    (void *) func_80806800_chgameselect,
                                                    (u32) func_80806B5C_chgameselect,
                                                    (u32) func_80806BD4_chgameselect,
                                                    (void *) func_8080462C_chgameselect,
                                                    (void *) func_80804694_chgameselect,
                                                    0,
                                                    (void *) func_808046D0_chgameselect,
                                                    (void *) func_80804750_chgameselect,
                                                    (void *) func_80804878_chgameselect,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    (void *) func_808048F8_chgameselect,
                                                    (u32) func_80804A8C_chgameselect,
                                                    (u32) func_80804AF0_chgameselect,
                                                    (void *) func_80804B4C_chgameselect,
                                                    (void *) func_80804B90_chgameselect,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    (void *) func_80804BB4_chgameselect,
                                                    (void *) func_80804BF4_chgameselect,
                                                    0,
                                                    0,
                                                    0,
                                                    0x0,
                                                    0x0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0x0,
                                                    0x0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0x0,
                                                    0x0};
int D_80807FD8_chgameselect[18] = {0x15804A7,
                                   0x9,
                                   0x0,
                                   (u32) func_8080015C_chgameselect,
                                   (u32) func_80102EC0,
                                   (u32) func_8010A730,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80800440_chgameselect,
                                   0x0,
                                   0x0,
                                   (u32) func_8080000C_chgameselect,
                                   (u32) func_80107C2C,
                                   -0x7FFFDBFE,
                                   (u32) func_80800228_chgameselect,
                                   0x0};
u8 D_80808020_chgameselect[24] = {0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,
                                  0x3F, 0x80, 0x0,  0x0,  0x3, 0xD0, 0x0, 0x9,
                                  0x40, 0x26, 0x66, 0x66, 0x3, 0xD4, 0x0, 0x4A};
int D_80808038_chgameselect[18] = {0x15804AB,
                                   0x8620001,
                                   (u32) &D_80808020_chgameselect,
                                   (u32) func_80800E24_chgameselect,
                                   (u32) func_80102EC0,
                                   (u32) func_808012E4_chgameselect,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x444,
                                   0x0,
                                   0x0,
                                   0xD80000,
                                   (u32) func_80800D74_chgameselect,
                                   (u32) func_80107C2C,
                                   -0x7F7FFFEE,
                                   (u32) func_808011B4_chgameselect,
                                   0x0};
u8 D_80808080_chgameselect[40] = {0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,
                                  0x0, 0x0, 0x3,  0x5B, 0x0,  0x44, 0x0, 0x0,  0x0, 0x0,
                                  0x0, 0x0, 0x0,  0x0,  0x40, 0x70, 0x0, 0x0,  0x3, 0x5B,
                                  0x0, 0x9, 0x40, 0x70, 0x0,  0x0,  0x3, 0x5B, 0x0, 0xA};
GameSelectPair D_808080A8_chgameselect[8] = {0x80C, 0x8, 0x80D, 0x9, 0x80E, 0xA, 0x80F, 0x2,
                                             0x813, 0x3, 0x812, 0x4, 0x811, 0x5, 0x810, 0x6};
void *D_808080C8_chgameselect = (void *) 0x015804A8;
static u32 D_808080C8_chgameselect_rest[17] = {0x1,
                                               (u32) &D_80808080_chgameselect,
                                               (u32) func_80801AC4_chgameselect,
                                               (u32) func_80102EC0,
                                               (u32) func_801018A4,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x424,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               (u32) func_80107C2C,
                                               0x80802002,
                                               (u32) func_80801BA8_chgameselect,
                                               0x0};
u8 D_80808110_chgameselect[352] = {
    0x3F, 0x2,  0x8F, 0x5C, 0x3F, 0x19, 0x99, 0x9A, 0x3F, 0x2B, 0x85, 0x1F, 0x3F, 0x38, 0x51, 0xEC,
    0x3F, 0x45, 0x1E, 0xB8, 0x3F, 0x4A, 0x3D, 0x71, 0x3F, 0x54, 0x7A, 0xE1, 0x3F, 0x5E, 0xB8, 0x52,
    0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0x3D, 0xA3, 0xD7, 0xA,
    0x3E, 0xF,  0x5C, 0x29, 0x3E, 0x6B, 0x85, 0x1F, 0x3E, 0x8F, 0x5C, 0x29, 0x3E, 0xA6, 0x66, 0x66,
    0x3E, 0xB8, 0x51, 0xEC, 0x3E, 0xC7, 0xAE, 0x14, 0x3E, 0xDC, 0x28, 0xF6, 0xBF, 0x80, 0x0,  0x0,
    0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0x3E, 0x9E, 0xB8, 0x52, 0x3E, 0xC2, 0x8F, 0x5C,
    0x3E, 0xE1, 0x47, 0xAE, 0x3F, 0x0,  0x0,  0x0,  0x3F, 0xC,  0xCC, 0xCD, 0x3F, 0x14, 0x7A, 0xE1,
    0x3F, 0x1E, 0xB8, 0x52, 0x3F, 0x28, 0xF5, 0xC3, 0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,
    0xBF, 0x80, 0x0,  0x0,  0x3E, 0xF,  0x5C, 0x29, 0x3E, 0x61, 0x47, 0xAE, 0x3E, 0xA1, 0x47, 0xAE,
    0x3E, 0xC2, 0x8F, 0x5C, 0x3E, 0xEB, 0x85, 0x1F, 0x3F, 0x5,  0x1E, 0xB8, 0xBF, 0x80, 0x0,  0x0,
    0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,
    0x3E, 0x38, 0x51, 0xEC, 0x3F, 0x11, 0xEB, 0x85, 0x3F, 0x3A, 0xE1, 0x48, 0xBF, 0x80, 0x0,  0x0,
    0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,
    0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0x3E, 0x85, 0x1E, 0xB8,
    0x3E, 0x9F, 0xBE, 0x77, 0x3E, 0xB9, 0xDB, 0x23, 0x3E, 0xD7, 0xA,  0x3D, 0x3E, 0xF7, 0xCE, 0xD9,
    0x3F, 0x8,  0xF5, 0xC3, 0x3F, 0x17, 0xA,  0x3D, 0x3F, 0x26, 0x66, 0x66, 0x3F, 0x28, 0xF5, 0xC3,
    0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0x3E, 0x8F, 0x5C, 0x29, 0x3E, 0xBD, 0x70, 0xA4,
    0x3E, 0xEB, 0x85, 0x1F, 0x3F, 0x5,  0x1E, 0xB8, 0x3F, 0x1E, 0xB8, 0x52, 0x3F, 0x28, 0xF5, 0xC3,
    0x3F, 0x59, 0x99, 0x9A, 0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0,
    0xBF, 0x80, 0x0,  0x0,  0x3E, 0x42, 0x8F, 0x5C, 0x3E, 0x57, 0xA,  0x3D, 0x3E, 0x6B, 0x85, 0x1F,
    0x3E, 0x82, 0x8F, 0x5C, 0x3E, 0x8F, 0x5C, 0x29, 0x3E, 0x99, 0x99, 0x9A, 0x3E, 0xD1, 0xEB, 0x85,
    0x3E, 0xE6, 0x66, 0x66, 0x3F, 0x1C, 0x28, 0xF6, 0x3F, 0x26, 0x66, 0x66, 0xBF, 0x80, 0x0,  0x0};
u8 D_80808270_chgameselect[16] = {0x4, 0x11, 0x4, 0x11, 0x4, 0x11, 0x5, 0x64,
                                  0x6, 0x27, 0x5, 0x64, 0x5, 0x64, 0x5, 0x64};
u8 D_80808280_chgameselect[8] = {0x9, 0x9, 0x9, 0x12, 0x14, 0x12, 0x12, 0x12};
u8 D_80808288_chgameselect[16] = {0x3D, 0xA3, 0xD7, 0xA, 0x3E, 0xF0, 0xA3, 0xD7,
                                  0x3F, 0x23, 0xD7, 0xA, 0xBF, 0x80, 0x0,  0x0};
s32 D_80808298_chgameselect[18] = {0x15804A9,
                                   -0xFFFF,
                                   0x0,
                                   (u32) func_80802248_chgameselect,
                                   (u32) func_80102EC0,
                                   (u32) func_808025CC_chgameselect,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x20404,
                                   (u32) func_80802480_chgameselect,
                                   0x0,
                                   0x0,
                                   (u32) func_808021E4_chgameselect,
                                   (u32) func_80107C2C,
                                   -0x7FFFDFFE,
                                   (u32) func_808025EC_chgameselect,
                                   0x0};
int D_808082E0_chgameselect[18] = {0x15804AA,
                                   -0xFFFF,
                                   0x0,
                                   (u32) func_80802530_chgameselect,
                                   (u32) func_80102EC0,
                                   (u32) func_808025CC_chgameselect,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x20404,
                                   (u32) func_80802588_chgameselect,
                                   0x0,
                                   0x0,
                                   (u32) func_808024D4_chgameselect,
                                   (u32) func_80107C2C,
                                   -0x7FFFDFFE,
                                   (u32) func_808025EC_chgameselect,
                                   0x0};
int D_80808328_chgameselect[18] = {0x15804AC,
                                   -0xFFFF,
                                   0x0,
                                   (u32) func_808027DC_chgameselect,
                                   (u32) func_80102EC0,
                                   (u32) func_80802994_chgameselect,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x20404,
                                   (u32) func_808029D8_chgameselect,
                                   0x0,
                                   0x0,
                                   (u32) func_808027D4_chgameselect,
                                   (u32) func_80107C2C,
                                   -0x7FFFDFFE,
                                   (u32) func_80802A0C_chgameselect,
                                   0x0};
s32 D_80808370_chgameselect[12] = {
    0x40, (u32) func_808039D0_chgameselect, 0x42, (u32) func_808039D0_chgameselect,
    0x48, (u32) func_808039D0_chgameselect, 0x46, (u32) func_80803A18_chgameselect,
    0x4C, (u32) func_80803A18_chgameselect, 0x4D, (u32) func_80803A88_chgameselect};
s32 D_808083A0_chgameselect[10] = {
    0x40, (u32) func_80803AB0_chgameselect, 0x42, (u32) func_80803AB0_chgameselect,
    0x48, (u32) func_80803AB0_chgameselect, 0x46, (u32) func_80803A58_chgameselect,
    0x4C, (u32) func_80803A58_chgameselect};
s32 D_808083C8_chgameselect[2] = {0xFF, 0xFF0000};
s32 D_808083D0_chgameselect[2] = {0xFF00FF, 0xFF0000};
s32 D_808083D8_chgameselect[2] = {0xFF00FF, 0x0};
s16 D_808083E0_chgameselect[4] = {0xAF, 0x47, 0xA3, 0x0};
s16 D_808083E8_chgameselect[3][3] = {0x18E5, 0x0, 0x41, 0x18E6, 0x1, 0x42, 0x18E8, 0x2, 0x22};
u8 D_808083FC_chgameselect[4] = {0x10, 0x6F, 0x22, 0x0};
u32 D_80808400_chgameselect[1] = {0xC0D1000};
u8 D_80808404_chgameselect[4] = {0xC, 0x9F, 0x6F, 0x5};
u32 D_80808408_chgameselect[1] = {0x366B46AC};
u8 D_8080840C_chgameselect[8] = {0xD, 0x7E, 0x40, 0xA2, 0xCB, 0x0, 0x0, 0x0};
u32 D_80808414_chgameselect[2] = {0x5060708, 0x9000000};
u8 D_8080841C_chgameselect[8] = {0xC, 0x10, 0x13, 0x6F, 0x22, 0x0, 0x0, 0x0};
GameSelEntry D_80808424_chgameselect[12] = {
    0x0, 0x0,  0x0, 0x0,  0x0,    0x0,    0,
    0x3, 0xF,  0x3, -0x1, 0x18E1, 0x0,    (void *) &D_80808400_chgameselect,
    0x0, 0x0,  0x0, 0x0,  0x0,    0x0,    0,
    0x0, 0x0,  0x0, 0x0,  0x0,    0x0,    0,
    0x0, 0x0,  0x0, 0x0,  0x0,    0x0,    0,
    0x4, 0x14, 0x8, -0x1, 0x18F5, 0x0,    (void *) &D_80808408_chgameselect,
    0x0, 0x0,  0x0, 0x0,  0x0,    0x0,    0,
    0x5, 0x0,  0xA, 0xA,  0x18F1, 0x18F1, (void *) &D_80808414_chgameselect,
    0x0, 0x0,  0x0, 0x0,  0x0,    0x0,    0,
    0x0, 0x0,  0x0, 0x0,  0x0,    0x0,    0,
    0x4, 0x0,  0x8, -0x1, 0x18F5, 0x0,    (void *) &D_80808408_chgameselect,
    0x4, 0xA,  0x8, -0x1, 0x18F5, 0x0,    (void *) &D_80808408_chgameselect};
int D_808084B4_chgameselect[18] = {0x15804B6,
                                   -0xFFFF,
                                   0x0,
                                   (u32) func_80806D98_chgameselect,
                                   (u32) func_80102EC0,
                                   (u32) func_80806FAC_chgameselect,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x20404,
                                   (u32) func_80807030_chgameselect,
                                   0x0,
                                   0x280000,
                                   (u32) func_80806C54_chgameselect,
                                   (u32) func_80107C2C,
                                   -0x7FFFDFFE,
                                   (u32) func_808070C0_chgameselect,
                                   0x0};
u8 D_808084FC_chgameselect[8] = {0x0, 0xFF, 0x0, 0xFF, 0x0, 0xFF, 0x0, 0x0};
s32 D_80808504_chgameselect[19] = {0x15804B9,
                                   0x1,
                                   0x0,
                                   (u32) func_80807900_chgameselect,
                                   (u32) func_80102EC0,
                                   (u32) func_8010A730,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x4,
                                   (u32) func_808079C8_chgameselect,
                                   0x0,
                                   0x0,
                                   (u32) func_808078F0_chgameselect,
                                   (u32) func_80107C2C,
                                   -0x7FFFDFFE,
                                   (u32) func_808079D0_chgameselect,
                                   0x0,
                                   0x0};
