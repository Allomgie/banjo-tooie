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

void func_8080000C_chgameselect(u8 *param_0)
{
    s32 local_0;
    s32 local_1;

    func_80016BDC(4);
    local_0 = func_800D395C();
    _gcfrontend_entrypoint_0();
    if (func_800AA0B8() != 0) {
        *(u8 *) ((s8 *) param_0 + 0x79) = (u8) ((*(u8 *) ((s8 *) param_0 + 0x79) & 0xFF0F) | 0x50);
        *(u16 *) ((s8 *) param_0 + 0x6E) = (u16) ((*(u16 *) ((s8 *) param_0 + 0x6E) & 0xFE00) | 5);
    } else if (local_0 != 0) {
        *(u8 *) ((s8 *) param_0 + 0x79) = (u8) ((*(u8 *) ((s8 *) param_0 + 0x79) & 0xFF0F) | 0x70);
        *(u16 *) ((s8 *) param_0 + 0x6E) = (u16) ((*(u16 *) ((s8 *) param_0 + 0x6E) & 0xFE00) | 7);
        func_800AA00C();
    } else {
        *(u8 *) ((s8 *) param_0 + 0x79) = (u8) (*(u8 *) ((s8 *) param_0 + 0x79) & 0xFF0F);
        *(u16 *) ((s8 *) param_0 + 0x6E) = (u16) ((*(u16 *) ((s8 *) param_0 + 0x6E) & 0xFE00) | 1);
        func_800AA00C();
    }
    func_80803638_chgameselect();
    func_80108B04(param_0, 0x4AB);
    local_1 = 0;
    do {
        func_80108B04(param_0, local_1);
        local_1 += 1;
    } while (local_1 != 8);
    func_80108B04(param_0, 0x4AA);
    func_80108B04(param_0, 0x4A9);
    func_80108B04(param_0, 0x4AC);
    func_80108B04(param_0, 0x4B9);
    *(s32 *) ((s8 *) param_0 + 0x34) = 0;
    *(f32 *) ((s8 *) param_0 + 0x58) = 0.1f;
    (*(s32 *) ((s8 *) (param_0) + (0x50))) = heap_alloc(0x100);
}

void func_80803C80_chgameselect();

s32 func_808016E8_chgameselect();

void func_8080015C_chgameselect(Actor *param_0)
{
    s32 local_0;

    switch (param_0->unk70_10) {
        case 1:
            local_0 = func_80803E40_chgameselect();
            if (local_0 && _gcstatusDll_entrypoint_10() != local_0)
                _gcstatusDll_entrypoint_2(local_0);
            break;
        case 9:
            if (func_800D9078(&param_0->unk58)) {
                if (D_8011A3F0)
                    func_80803C80_chgameselect();
                func_808016E8_chgameselect(param_0->actorData[4], param_0->unk79_4);
                func_80800478_chgameselect(param_0, param_0->unk6C_0);
            }
            break;
    }
}

s32 B_80808550_chgameselect;
u8 B_80808550_chgameselect_pad[4];
s32 B_80808558_chgameselect;
RankEntry B_80808560_chgameselect;
u8 B_80808560_chgameselect_pad[4];
s32 B_80808570_chgameselect;
u8 B_80808578_chgameselect[16];
s32 B_80808588_chgameselect[2];
u8 B_80808590_chgameselect[16];

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

void func_80800440_chgameselect(Actor *param_0)
{
    ActorLocal_CC_5B90 *local_0;
    local_0 = (ActorLocal_CC_5B90 *) &param_0->unk50;
    func_808036D8_chgameselect();
    if (local_0->unk50 != 0) {
        heap_free(local_0->unk50);
    }
}

void func_80800478_chgameselect(param_0, param_1) Actor *param_0;
s32 param_1;
{
    s32 local_0 = -1;
    s32 local_1;
    s32 (*local_2)(Actor *);

    local_1 = param_0->unk70_10;
    if (param_1 != local_1) {
        if (D_80807DD0_chgameselect[local_1].local_4)
            D_80807DD0_chgameselect[local_1].local_4(param_0);
        func_80101FDC(param_0, param_1);
        ((GameSelectActor1838 *) param_0)->local_0 = 0;
        ((GameSelectActor1838 *) param_0)->local_1 = ((GameSelectActor1838 *) param_0)->local_2 =
            -1;
        local_1 = param_0->unk70_10;
        local_2 = D_80807DD0_chgameselect[local_1].local_3;
        if (local_2) {
            local_0 = local_2(param_0);
            local_1 = param_0->unk70_10;
        }
        switch (local_1) {
            case 8:
                func_80802780_chgameselect(((GameSelectActor1838 *) param_0)->local_3, 0);
                func_8080218C_chgameselect(param_0->unk79_4, 1);
                func_80801658_chgameselect(((GameSelectActor1838 *) param_0)->local_4, 1);
                func_80801714_chgameselect(((GameSelectActor1838 *) param_0)->local_4, 0);
                break;
            case 1:
                local_0 = func_80803DCC_chgameselect(param_0->unk79_4);
                func_80803D00_chgameselect(0, 1);
                break;
        }
        if (local_0 != -1)
            func_808026C8_chgameselect(((GameSelectActor1838 *) param_0)->local_5, local_0);
    }
}

void func_808036B8_chgameselect();

void func_80803678_chgameselect();

void func_808005D4_chgameselect(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;

    param_0->unk79_4 = param_1;
    local_0 = param_0->unk70_10;
    if (local_0 == 1 || local_0 == 9) {
        switch (param_0->unk79_4) {
            case 0:
            case 1:
            case 2:
            func_80803678_chgameselect(param_0->unk79_4);
            break;
            default:
            func_808036B8_chgameselect(param_0->unk79_4);
            break;
        }
        func_80802640_chgameselect(param_0->actorData[5], D_80807DB0_chgameselect[param_0->unk79_4].sound, 0);
        func_808026C8_chgameselect(param_0->actorData[5], func_80803DCC_chgameselect(param_0->unk79_4));
    }
}

void func_80803C60_chgameselect();

s32 func_80803718_chgameselect();

s32 func_808036F8_chgameselect();

void func_808006A0_chgameselect(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    s32 local_1;
    local_0 = -1;
    local_1 = 0;
    if (D_80807DD8_chgameselect[param_0->unk70_10].local_0) local_1 = D_80807DD8_chgameselect[param_0->unk70_10].local_0(param_0, param_1, &local_0);
    if (param_0->unk70_10 == 1) {
        switch (param_1) {
            case 3:
            if (!func_80803718_chgameselect()) local_0 = 5;
            else if (func_808036F8_chgameselect(0) && func_808036F8_chgameselect(1) && func_808036F8_chgameselect(2)) local_0 = 7;
            break;
            case 4:
            if (!func_80803718_chgameselect()) local_0 = 4;
            break;
            case 5:
            if (!func_80803D60_chgameselect(param_1)) local_0 = 0;
            else if (func_80803E40_chgameselect() < 2) local_0 = 0x23;
            break;
            case 7:
            if (!func_80803D60_chgameselect(param_1)) local_0 = 0;
            break;
        }
        if (local_0 != -1) local_1 = 1;
        else func_80800478_chgameselect(param_0, D_80807DB2_chgameselect[param_0->unk79_4][0]);
    }
    if (local_1) func_80803C60_chgameselect();
    if (local_0 != -1) func_808026C8_chgameselect(param_0->actorData[5], local_0);
}

void func_8080086C_chgameselect(param_0, param_1) Actor *param_0;
s32 param_1;
{
    switch (param_0->unk70_10) {
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
            func_80800478_chgameselect(param_0, 1);
            break;
    }
}

void func_808008D0_chgameselect(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 (*local_0)(Actor *, s32, s32);
    s32 local_1;
    local_1 = -1;
    local_0 = D_80807DE0_chgameselect[param_0->unk70_10].local_0;
    if (local_0 != NULL) {
        local_1 = local_0(param_0, param_1, param_2);
    }
    if (local_1 != -1) {
        func_808026C8_chgameselect((void *) param_0->actorData[5], local_1);
    }
}

void func_80800944_chgameselect(Actor *param_0, s32 param_1, s32 param_2)
{
    if (D_80807DE4_chgameselect[param_0->unk70_10].fn != NULL) {
        D_80807DE4_chgameselect[param_0->unk70_10].fn(((s32) param_0 ^ 0), param_1, param_2,
                                                      param_0);
    }
    if (param_0) {
    }
}

void func_80800998_chgameselect(Actor *param_0, s32 param_1, s32 param_2)
{
    if (D_80807DE8_chgameselect[param_0->unk70_10].fn != NULL) {
        D_80807DE8_chgameselect[param_0->unk70_10].fn(((s32) param_0 ^ 0), param_1, param_2,
                                                      param_0);
    }
    if (param_0) {
    }
}

void func_808009EC_chgameselect(Actor *param_0)
{
    void (*local_0)(Actor *);

    local_0 = D_80807DEC_chgameselect[param_0->unk70_10].update;
    if (local_0 != NULL) {
        local_0(param_0);
    } else {
        func_80800478_chgameselect(param_0, 1);
    }
}

void func_80800A4C_chgameselect(void *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    void (*local_1)(void *, s32, s32, s32);
    local_1 = *(void (**)(void *, s32, s32, s32))(
        (char *) D_80807DFC_chgameselect +
        (((u32) *(u16 *) ((char *) param_0 + 0x72) >> 10) * 52));
    if (local_1 != 0) {
        local_1(param_0, param_1, param_2, param_3);
    }
}

void func_80800A9C_chgameselect(void *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    void (*local_1)(void *, s32, s32, s32);
    local_1 = *(void (**)(void *, s32, s32, s32))(
        (char *) D_80807E00_chgameselect +
        (((u32) *(u16 *) ((char *) param_0 + 0x72) >> 10) * 52));
    if (local_1 != 0) {
        local_1(param_0, param_1, param_2, param_3);
    }
}

void func_80800AEC_chgameselect(param_0, param_1, param_2, param_3) s32 param_0;
s32 param_1;
s32 param_2;
s32 param_3;
{
    Actor *local_0 = (Actor *) func_80106790(param_0);
    switch (param_3) {
        case 0:
            D_80807DC8_chgameselect[local_0->unk70_10].local_0(local_0, param_1, param_2, param_3);
            break;
        case 3:
            func_80800998_chgameselect(local_0, param_1, param_2);
            break;
        case 2:
            func_808009EC_chgameselect(local_0);
            break;
        case 4:
            func_808008D0_chgameselect(local_0, param_1, param_2);
            break;
        case 5:
            func_80800944_chgameselect(local_0, param_1, param_2);
            break;
        case 6:
            func_80800A9C_chgameselect(local_0, param_1, param_2, param_3);
            break;
        case 7:
            func_80800A4C_chgameselect(local_0, param_1, param_2, param_3);
            break;
        case 0xFF:
            D_80807DC8_chgameselect[local_0->unk70_10].local_1(local_0, param_1, param_2, param_3);
            break;
        case 0xFC:
        case 0xFD:
        case 0xFE:
            D_80807DC8_chgameselect[local_0->unk70_10].local_2(local_0, param_1, param_2, param_3);
            break;
    }
}

void func_80800CA0_chgameselect(Unk80132ED0 *param_0)
{
    s32 local_0;
    Actor *local_1;

    local_0 = -1;
    local_1 = func_80106790(param_0);
    if (D_80807DD0_chgameselect[local_1->unk70_10].local_0 != NULL) {
        D_80807DD0_chgameselect[local_1->unk70_10].local_0(local_1, &local_0);
    }
    if (local_0 != -1) {
        func_808026C8_chgameselect(local_1->actorData[5], local_0);
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

void func_80800D74_chgameselect(param_0) Actor *param_0;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    func_800EFD24(param_0->position);
    param_0->rotation[0] = 45.0f;
    param_0->rotation[2] = 45.0f;
    param_0->rotation[1] = 60.0f;
    func_808015DC_chgameselect(param_0->unk0, 0);
    param_0->unk64_20 = 0;
    ((f32 *) param_0->actorData)[7] = 1.0f;
    func_800EFA4C((f32 *) (local_0 + 0xC8), 0.0f, 0.0f, 1.0f);
    func_800EF2A0((f32 *) (local_0 + 0xC8));
    *(f32 *) (local_0 + 0xD4) = 200.0f;
}

void func_80801338_chgameselect();

void func_80800E24_chgameselect(Actor *param_0)
{
    GameSelectState521 *local_0;
    f32 local_1;
    f32 local_2[2];
    f32 local_3;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D8FF8();
    if (func_80800D3C_chgameselect(param_0->unk3C)) {
        if (param_0->unk58 >= 0.0f) {
            param_0->unk58 -= local_1;
        }
        if (!param_0->unk64_19 && param_0->unk58 <= 0.0f) {
            func_80016068(0, local_2);
            local_3 = mlAbsF(local_2[0]);
            if (mlAbsF(local_2[1]) < local_3) {
                local_2[1] = 0.0f;
            } else {
                local_2[0] = 0.0f;
            }
            if (local_2[0] < -0.1f && (param_0->unk79_4 & 3)) {
                func_80801338_chgameselect(param_0, -1);
            } else if (local_2[0] > 0.1f && (param_0->unk79_4 & 3) != 3) {
                func_80801338_chgameselect(param_0, 1);
            }
            if (local_2[1] < -0.1f && (param_0->unk79_4 & 4) != 4) {
                func_808013C8_chgameselect(param_0, param_0->unk79_4 + 4);
            } else if (local_2[1] > 0.1f && (param_0->unk79_4 & 4)) {
                func_808013C8_chgameselect(param_0, param_0->unk79_4 - 4);
            }
        }
        if (func_800DA298(0x64A)) {
            if (func_80016B30(0, 1) == 1) {
                func_8010114C(param_0->unk3C, 8, param_0->unk79_4);
            } else if (func_80016B30(0, 0) == 1) {
                func_8010114C(param_0->unk3C, 7, param_0->unk79_4);
            }
        }
        if (param_0->unk6C_0 == 1 && param_0->unk7C_12) {
            if (local_0->local_1[param_0->unk79_4] &&
                func_808014F0_chgameselect(param_0, local_0->local_0[param_0->unk79_4].f)) {
                param_0->unk58 = 0.0f;
            }
        }
        if (param_0->unk64_19 && !param_0->unk64_20) {
            if (((f32 *) param_0->actorData)[7] > 0.0f) {
                local_1 = 1;
                local_3 = func_800D8FF8();
                ((f32 *) param_0->actorData)[7] =
                    ((f32 *) param_0->actorData)[7] - local_1 * local_3;
                if (((f32 *) param_0->actorData)[7] < 0.0f) {
                    ((f32 *) param_0->actorData)[7] = 0.0f;
                }
            }
        } else if (((f32 *) param_0->actorData)[7] < 1.0f) {
            local_1 = 1;
            local_3 = func_800D8FF8();
            ((f32 *) param_0->actorData)[7] = ((f32 *) param_0->actorData)[7] + local_1 * local_3;
            if (((f32 *) param_0->actorData)[7] > 1.0f) {
                ((f32 *) param_0->actorData)[7] = 1.0f;
            }
        }
    }
}

s32 func_808011B4_chgameselect(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;
    u8 *local_1;
    s32 i;

    switch (param_1) {
        default:
        return 0;
        case 0x23:
        local_0 = func_80100094(param_0, 0);
        for (i = 0; i < 8; i++) {
            if (local_0[0xC0 + i] != 0) {
                func_8080145C_chgameselect(local_0 + 0xC8, *(f32 *)(local_0 + 0xD4), ((GsEntry12 *)local_0)[i].data + 0x60, ((GsEntry12 *)local_0)[i].data);
            }
        }
        ((GsBits6E *)param_0)->unk6E_0 = 1;
        break;
        case 0x31:
        if (((GsBits74 *)param_0)->unk74_21) {
            local_1 = func_80100094(param_0, 0);
            func_80101038(((GsEntry12 *)local_1)[param_2].data);
            local_1[0xC0 + param_2] = 1;
            func_8080145C_chgameselect(local_1 + 0xC8, *(f32 *)(local_1 + 0xD4), ((GsEntry12 *)local_1)[param_2].data + 0x60, ((GsEntry12 *)local_1)[param_2].data);
            return 1;
        }
        return 0;
    }
    return 1;
}

int func_808012E4_chgameselect(param_0, param_1)
f32 param_0[3];
s32 param_1;
{
    f32 local_0;
    f32 *new_var2;
    s32 local_1;
    int new_var;
    new_var = 13;
    local_0 = (local_1 = 255.0f * param_0[new_var]);
    if (local_1 != 0) {
        _subaddiefade_entrypoint_8(param_0, local_1);
        func_80101870(new_var2 = param_0, param_1);
    }
}

void func_80801338_chgameselect(Actor *param_0, s32 param_1)
{
    s32 local_0;
    u32 local_1;
    local_0 = param_0->unk79_4 + param_1;
    local_1 = param_0->unk79_4 & 3;
    if (param_0->actorData[0] && local_0 + 1 == param_0->actorData[0]) {
        local_1 = local_0 & 3;
        if (!param_1)
            param_1 = local_0 == 0 ? 1 : -1;
        local_0 += param_1;
    }
    if (param_1 < 0 && local_1 != 0)
        func_808013C8_chgameselect(param_0, local_0);
    else if (param_1 > 0 && local_1 != 3)
        func_808013C8_chgameselect(param_0, local_0);
}

void func_808013C8_chgameselect(param_0, param_1) Actor *param_0;
s32 param_1;
{
    if (!param_0->unk64_20 || param_1 < 3) {
        param_0->unk79_4 = param_1;
        func_80101238(10, param_0->unk79_4);
        param_0->unk6C_0 = 1;
        func_80102424(param_0, 1);
        param_0->unk58 = 0.5f;
    }
}

void func_8080145C_chgameselect(f32 *param_0, f32 param_1, f32 *param_2, f32 *param_3)
{
    f32 local_0[3];
    f32 local_1;
    func_800E3980(local_0);
    func_800EF3DC(local_0, param_3);
    local_1 = func_800EEAA4(local_0, param_0);
    if (local_1 != 0.0f) {
        local_1 = (param_1 - func_800EEAA4(param_3, param_0)) / local_1;
        func_800EE7B4(param_2, param_3, local_0, local_1);
    }
}

s32 func_808014F0_chgameselect(param_0, param_1)
Actor *param_0;
f32 *param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_3;
    f32 local_2;

    _subaddieskeleton_entrypoint_1(param_0, 5, local_1);
    func_800EFB24(local_0, param_1, local_1);
    local_2 = func_800EEF94(local_0);
    if (local_2 != 0.0f) {
        local_3 = func_800FF060(local_2, (f32 *) ((u8 *) param_0 + 0x24), 4000.0f, -4000.0f,
                                3000.0f, func_800D8FF8());
        func_800EF174(param_0->position, local_0, local_3 / local_2);
    }
    return (local_2 == 0.0f || *(f32 *) ((u8 *) param_0 + 0x24) < 0.01f) ? 1 : 0;
}

int func_808015DC_chgameselect(param_0, param_1)
s32 param_0;
s32 param_1;
{
    u32 local_0;
    local_0 = func_80106790(param_0);
    switch (param_1) {
        case 1:
            _subaddiefade_entrypoint_12(local_0, 0xff, 0, 0);
            return;
        case 2:
            _subaddiefade_entrypoint_12(local_0, 0, 0xff, 0);
            return;
        default:
            _subaddiefade_entrypoint_12(local_0, 0xff, 0xff, 0xff);
            return;
    }
}

int func_80801658_chgameselect(param_0, param_1)
s32 param_0;
s32 param_1;
{
    u8 *local_0;
    local_0 = func_80106790(param_0);
    if (param_1 != 0) {
        local_0[0x65] = (local_0[0x65] & 0xFFFF) | 0x8;
    } else {
        local_0[0x65] &= ~0x8;
    }
}

void func_808016A0_chgameselect(s32 param_0, s32 param_1)
{
    GameSelectActor *local_0;
    local_0 = func_80106790(param_0);
    if (param_1 != 0) {
        local_0->unk65_4 = 1;
    } else {
        local_0->unk65_4 = 0;
    }
}

s32 func_808016E8_chgameselect(enum asset_e text_id, s32 param_1)
{
    func_808013C8_chgameselect(func_80106790(text_id), param_1);
}

void func_80801714_chgameselect(param_0, param_1) Unk80132ED0 *param_0;
s32 param_1;
{
    Actor *local_0;
    local_0 = func_80106790(param_0);
    func_80102424(local_0, 2);
    local_0->unk64_19 = 1;
    func_80803C80_chgameselect();
}

void func_80801758_chgameselect(s32 param_0, s32 param_1)
{
    u8 *local_0 = func_80106790(param_0);
    *(s32 *) (local_0 + 0x18) = param_1 + 1;
    func_80801338_chgameselect(local_0, 0);
}

int chgameselect_entrypoint_2()
{
    return &D_808080C8_chgameselect;
}

int func_8080179C_chgameselect(param_0) Actor *param_0;
{
    switch (param_0->unk79_4) {
        case 4:
        if (func_80101E4C(param_0, D_80808288_chgameselect)) {
            func_800C3F48(((u16)(u32)(func_800DC178(0.7f, 0.8f) * 1023.0f) << 21) + 0xFA4D5);
        }
        break;
        case 6:
        if (func_80101E14(param_0, 0.77f)) {
            func_800C3F48(((u16)(u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) << 21) + 0xDACD5);
        }
        break;
    }
    if (func_80101E4C(param_0, D_80808110_chgameselect + param_0->unk79_4 * 0x2C)) {
        func_800C3F48(((((*((u16 *) (D_80808270_chgameselect + (param_0->unk79_4 * 2)))) & 0x7FF) + ((((D_80808280_chgameselect[param_0->unk79_4] * 1000) >> 5) & 0x3FF) << 11)) + ((u32)(u16)(u32)(func_800DC178(0.9f, 1.1f) * 1023.0f) << 21)));
    }
}

void func_80801AC4_chgameselect(param_0) Actor *param_0;
{
    s32 local_2;
    f32 local_0[3];
    f32 local_1;

    if (!param_0->unk64_20) {
        if ((local_2 = func_80103C94()) != 0) {
            func_800B237C(local_2, local_0, &local_1);
            func_80101010(local_0);
            if (func_80101180(0x4AB, 0x31, param_0->unk79_4)) {
                param_0->unk64_20 = 1;
            }
        }
    }
    if (_subaddiefade_entrypoint_0(param_0) < 100) {
        _subaddiefade_entrypoint_1(param_0, 100);
    }
    switch (param_0->unk70_10) {
        case 2:
        case 3:
            break;
        case 4:
            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 2);
            }
    }
    func_8080179C_chgameselect(param_0);
}

s32 func_80801BA8_chgameselect(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s16 local_3;
    switch (param_1) {
        case 0x95:
            func_801032B0(param_0, D_808080A8_chgameselect[param_0->unk79_4].unk0, 0);
            local_0 = func_80104248(param_0);
            func_8008B304(local_0);
            local_1 = func_800B27E0(func_801039E4(param_0->unk0));
            func_8008C200(*(s16 *) ((u8 *) param_0->unk0 + 0x10), local_1, func_8008AEDC(local_0));
            func_80102424(param_0, 2);
            local_2 = param_0->unk79_4;
            switch (local_2) {
                case 5:
                    if (!_gcfrontend_entrypoint_1(3))
                        _subaddiefade_entrypoint_1(param_0, 100);
                    break;
                case 7:
                    if (!_gcfrontend_entrypoint_2())
                        _subaddiefade_entrypoint_1(param_0, 100);
                    break;
            }
            break;
        case 0xA:
            if (param_2 == param_0->unk79_4) {
                local_2 = 1;
            } else {
                local_2 = 0;
            }
            func_80802070_chgameselect(param_0, local_2);
            if (param_2 == param_0->unk79_4) {
                local_3 = D_808080AA_chgameselect[param_2].unk0;
                if (local_3 >= 0)
                    func_80803D00_chgameselect(local_3, 2);
            }
            break;
        case 0x1F:
            func_80801D74_chgameselect(param_0, param_2);
            break;
        case 0x21:
            if (param_0->unk79_4 == ((s16 *) &param_2)[0]) {
                func_808020CC_chgameselect(param_0, ((s16 *) &param_2)[1]);
                break;
            }
        default:
            return 0;
    }
    return 1;
}

void func_80801D74_chgameselect(Actor *param_0, s32 param_1)
{
    s32 local_0;
    Unk80132ED0 *local_1;
    s32 local_2;
    f32 local_3[3];
    f32 local_4;
    s32 local_0_b;
    s32 local_5;
    s32 local_6;
    u8 local_7;

    func_80103D48(param_0);
    local_0 = func_80104248(param_0);
    local_1 = param_0->unk0;
    if (local_0 && !param_0->unk7C_12) {
        func_8008B304(local_0);
    }
    if (*(s16 *) ((u8 *) local_1 + 0x10)) {
        local_2 = func_800B27E0(param_1, local_0);
        if (local_0 && local_2 && !param_0->unk7C_12) {
            func_8008C200(*(s16 *) ((u8 *) local_1 + 0x10), local_2, func_8008AEDC(local_0));
        }
        func_800DF72C(func_800AE080(*(s16 *) ((u8 *) local_1 + 0x10)));
    }
    if (_subaddiefade_entrypoint_0(param_0) < 255) {
        func_800DF410(_subaddiefade_entrypoint_0(param_0));
    }
    func_800DF830(((GameSelectTop *) param_0)->top);
    func_800DF738(_subaddieskeleton_entrypoint_4(param_0));
    if (!param_0->unk7C_12) {
        func_800B237C(func_800B2840(param_1), local_3, &local_4);
        *(s16 *) ((u8 *) local_1 + 0x1E) = local_3[0] * param_0->scale;
        *(s16 *) ((u8 *) local_1 + 0x20) = local_3[1] * param_0->scale;
        *(s16 *) ((u8 *) local_1 + 0x22) = local_3[2] * param_0->scale;
        ((Mass63GameSelectMarker *) local_1)->local_0 = (u32) local_4;
    }
    local_0_b = func_800D731C(param_0->unk0->unk14);
    local_7 = local_0_b;
    if (local_0_b)
        func_800DF7E8(local_7);
    func_80103D70(param_0);
    param_0->unk7C_12 = 1;
    switch (param_0->unk79_4) {
        case 0:
        case 1:
        case 2:
            func_800DF744(param_0->unk79_4 + 1, param_0->unk64_19 ? 2 : 1);
            break;
        case 5:
            local_6 = 0;
            for (local_5 = 0; local_5 < 4; local_5++) {
                if (func_80016800(local_5))
                    local_6 |= 1 << local_5;
            }
            func_800DF7C4(3, local_6);
    }
}

int func_80802070_chgameselect(param_0, param_1)
s32 param_0[2];
s32 param_1;
{
    if (param_1 != 0) {
        if (((unsigned int) (u16) *(u16 *) ((char *) param_0 + 114) >> 10) != 3) {
            func_80102424(param_0, 3);
        }
    } else if ((((u16) *(u16 *) ((char *) param_0 + 114) & 0xFFFFFFFFu) >> 10) == 3) {
        func_80102424(param_0, 4);
    }
}

void func_808020CC_chgameselect(param_0, param_1) Actor *param_0;
s32 param_1;
{
    if (param_1 != param_0->unk64_19) {
        if (param_1) {
            switch (param_0->unk79_4) {
                case 0:
                case 1:
                case 2:
                    break;
                default:
                    _subaddiefade_entrypoint_4(param_0);
            }
        } else {
            switch (param_0->unk79_4) {
                case 0:
                case 1:
                case 2:
                    break;
                default:
                    _subaddiefade_entrypoint_5(param_0);
            }
        }
        param_0->unk64_19 = param_1;
    }
}

void func_8080218C_chgameselect(param_0, param_1) s32 param_0;
s32 param_1;
{
    GameSelectEvent local_0;
    local_0.local_3.local_1 = param_0;
    if (param_1)
        local_0.local_3.local_2 = 1;
    else
        local_0.local_3.local_2 = 0;
    func_80101180(0x4A8, 0x21, local_0.local_0);
}

int chgameselect_entrypoint_3()
{
    return (int) D_80808298_chgameselect;
}

int chgameselect_entrypoint_4()
{
    return (int) &D_808082E0_chgameselect;
}

void func_808021E4_chgameselect(u8 *param_0)
{
    s32 local_0;

    local_0 = _gczoombox_entrypoint_5(0xC8, 0xC, 2, 0, 0);
    *(s32 **) ((char *) param_0 + 0x28) = local_0;
    _gczoombox_entrypoint_19(local_0);
    *(s32 **) ((char *) param_0 + 0x24) = heap_alloc(0x40);
    *(s32 **) ((char *) param_0 + 0x34) = heap_alloc(0x40);
}

void func_80802248_chgameselect(Actor *param_0)
{
    u32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = 0;
    if (param_0->unk64_20) {
        switch (param_0->unk79_4) {
            case 0:
            case 1:
            case 2:
                local_0 = param_0->unk79_4 + 1;
        }
    }
    if (param_0->actorData[0]) {
        _gczoombox_entrypoint_18(param_0->actorData[4]);
        _gczoombox_entrypoint_16(param_0->actorData[4]);
        _gczoombox_entrypoint_9(param_0->actorData[4]);
        _gczoombox_entrypoint_11(param_0->actorData[4]);
    } else if (local_0) {
        if (local_0 != param_0->actorData[5]) {
            _gczoombox_entrypoint_18(param_0->actorData[4]);
            _gczoombox_entrypoint_16(param_0->actorData[4]);
            _gczoombox_entrypoint_9(param_0->actorData[4]);
            _gczoombox_entrypoint_11(param_0->actorData[4]);
            func_800E73D4(param_0->actorData[3]);
            func_800E73D4(param_0->actorData[7]);
            local_3 = param_0->unk79_4 + 1;
            if (func_80803738_chgameselect(param_0->unk79_4, &local_1, &local_2)) {
                func_80803E94_chgameselect(param_0->actorData[3], 0x18F3, 1, 1, &local_3);
                func_800DB8BC(param_0->actorData[3], local_1);
                func_800E6A58(param_0->actorData[3], 0x2C);
                local_3 = local_2;
                if (local_2 == 1) {
                    func_80803E94_chgameselect(param_0->actorData[7], 0x18F3, 3, 1, &local_3);
                } else {
                    func_80803E94_chgameselect(param_0->actorData[7], 0x18F3, 2, 1, &local_3);
                }
            } else {
                func_80803E94_chgameselect(param_0->actorData[3], 0x18F3, 0, 1, &local_3);
            }
            _gczoombox_entrypoint_32(param_0->actorData[4]);
            if (*(u8 *) param_0->actorData[7]) {
                ((s32 *) &B_80808558_chgameselect)[0] = param_0->actorData[3];
                ((s32 *) &B_80808558_chgameselect)[1] = param_0->actorData[7];
                _gczoombox_entrypoint_7(param_0->actorData[4], 2, &B_80808558_chgameselect);
            } else {
                _gczoombox_entrypoint_8(param_0->actorData[4], param_0->actorData[3]);
            }
        }
    } else {
        _gczoombox_entrypoint_15(param_0->actorData[4]);
        _gczoombox_entrypoint_17(param_0->actorData[4]);
        _gczoombox_entrypoint_12(param_0->actorData[4]);
        _gczoombox_entrypoint_10(param_0->actorData[4]);
    }
    param_0->actorData[5] = local_0;
    _gczoombox_entrypoint_4(param_0->actorData[4]);
}

int func_80802480_chgameselect(Actor *param_0)
{
    if (*(void **) ((char *) param_0 + 0x24) != NULL) {
        heap_free((*(void **) ((char *) (param_0) + 0x24)));
    }
    if (*(void **) ((char *) param_0 + 0x34) != NULL) {
        heap_free((*(void **) ((char *) (param_0) + 0x34)));
    }
    func_80802620_chgameselect(param_0);
}

void func_808024D4_chgameselect(void *param_0)
{
    s32 temp_v0;

    temp_v0 = _gczoombox_entrypoint_5(0x1C, 0xD, 2, 1, 0);
    *(s32 *) ((s8 *) param_0 + 0x28) = temp_v0;
    _gczoombox_entrypoint_9(temp_v0);
    _gczoombox_entrypoint_11((*(s32 *) ((s8 *) param_0 + 0x28)));
    *(s32 *) ((s8 *) param_0 + 0x1C) = -1;
}

void func_80802530_chgameselect(Actor *param_0)
{
    s32 local_0;

    _gczoombox_entrypoint_4(*(s32 **) ((char *) param_0 + 0x28), param_0);
    local_0 = _gczoombox_entrypoint_3(*(s32 **) ((char *) param_0 + 0x28), param_0);
    if (local_0 != *(s32 *) ((char *) param_0 + 0x20)) {
        *(s32 *) ((char *) param_0 + 0x20) = local_0;
        if (local_0 == 3) {
            func_80800CA0_chgameselect(param_0->unk3C);
        }
    }
}

int func_80802588_chgameselect(Actor *param_0)
{
    if (*(s32 *) ((char *) param_0 + 0x30) != 0) {
        _gldbstring_entrypoint_2((*(s32 *) ((char *) (param_0) + 0x18)));
        *(s32 *) ((char *) param_0 + 0x30) = 0;
    }
    func_80802620_chgameselect(param_0);
}

int func_808025CC_chgameselect(Actor *param_0)
{
    _gczoombox_entrypoint_2((*(s32 *) ((char *) (param_0) + 0x28)));
}

s32 func_808025EC_chgameselect(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0xA:
            param_0->unk79_4 = param_2;
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80802620_chgameselect(param_0)
Actor *param_0;
{
    _gczoombox_entrypoint_0((*(s32 *) ((char *) (param_0) + 0x28)));
}

void func_80802640_chgameselect(param_0, param_1, param_2) s32 param_0;
s32 param_1;
s32 param_2;
{
    ChGameSelectState *local_0;
    int *new_var;
    local_0 = (ChGameSelectState *) func_80106790(param_0);
    if (param_1 != *(s32 *) ((char *) local_0 + 24)) {
        if (*(s32 *) ((char *) local_0 + 48)) {
            _gldbstring_entrypoint_2((*(s32 *) ((char *) (local_0) + 24)));
            *(s32 *) ((char *) local_0 + 48) = 0;
        }
        *(s32 *) ((char *) local_0 + 24) = param_1;
        if (param_1) {
            new_var = (*(s32 *) ((char *) (local_0) + 48));
            (*(s32 *) ((char *) (local_0) + 48)) = _gldbstring_entrypoint_0(new_var);
        }
        *(s32 *) ((char *) local_0 + 28) = -1;
        _gczoombox_entrypoint_32(*(void **) ((char *) local_0 + 40));
    }
}

void func_808026C8_chgameselect(param_0, param_1) s32 param_0;
s32 param_1;
{
    s32 local_0;
    local_0 = func_80106790(param_0);
    if (param_1 != *(s32 *) ((char *) local_0 + 0x1C)) {
        *(s32 *) ((char *) local_0 + 0x1C) = param_1;
        _gczoombox_entrypoint_32(*((s32 *) (((char *) local_0) + 0x28)));
        _gczoombox_entrypoint_8(*((s32 *) (((char *) local_0) + 0x28)),
                                _gldbstring_entrypoint_1(*((s32 *) (((char *) local_0) + 0x30)),
                                                         *((s16 *) (((char *) local_0) + 0x1E))));
        *(s32 *) ((char *) local_0 + 0x20) = -1;
    }
}

void func_80802730_chgameselect(param_0, param_1) s32 param_0;
s32 param_1;
{
    s32 *local_0;
    local_0 = (s32 *) func_80106790(param_0);
    local_0[0x1C / 4] = -1;
    _gczoombox_entrypoint_32((void *) local_0[0x28 / 4]);
    _gczoombox_entrypoint_8((void *) local_0[0x28 / 4], param_1);
    local_0[0x20 / 4] = -1;
}

int func_80802780_chgameselect(param_0, param_1)
s32 param_0;
s32 param_1;
{
    u8 *local_0;
    local_0 = func_80106790(param_0);
    if (param_1 != 0) {
        local_0[0x65] = (local_0[0x65] & 0xFFFF) | 0x10;
    } else {
        local_0[0x65] &= ~0x10;
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

void func_808027DC_chgameselect(Actor *param_0)
{
    s32 pad[4];
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s8 local_3;
    local_0 = func_80100094(param_0, 0);
    if (!local_0)
        return;
    if (param_0->unk64_20 && _gcnewoption_entrypoint_48(local_0)) {
        func_80800AEC_chgameselect(param_0->unk3C, (s32) local_0, -1, 0xFF);
    }
    switch (param_0->unk70_10) {
        case 2:
            local_1 = func_80100094(param_0, 1);
            local_3 = local_1[_gcnewoption_entrypoint_45(local_0) * 6 + 3];
            if (local_3 >= 0) {
                func_808026C8_chgameselect(((Actor *) func_80106790(param_0->unk3C))->actorData[3],
                                           local_3);
            }
            break;
        case 3:
            if (func_80015FA0(0) == 1) {
                for (local_2 = 0; local_2 < (s32) param_0->actorData[5]; local_2++) {
                    if (_gcnewoption_entrypoint_17(local_0, local_2))
                        break;
                }
                if (local_2 < (s32) param_0->actorData[5])
                    _gcnewoption_entrypoint_37(local_0, 0);
                else
                    func_80803C60_chgameselect();
            } else if (func_80016B54(0, 0) == 1) {
                for (local_2 = 0; local_2 < (s32) param_0->actorData[5]; local_2++) {
                    func_80803604_chgameselect(local_0, local_2, 0, 0);
                }
                func_80803CE0_chgameselect();
            }
    }
    _gcnewoption_entrypoint_0(local_0);
}

s32 func_80802994_chgameselect(s32 param_0, s32 param_1)
{
    if (func_80100094(param_0, 0) != 0) {
        _gcnewoption_entrypoint_1(func_80100094(param_0, 0), param_1);
    }
}

s32 func_808029D8_chgameselect(s32 param_0)
{
    if (func_80100094(param_0, 0)) {
        _gcnewoption_entrypoint_6(param_0, 0);
    }
}

s32 func_80802A0C_chgameselect(Actor *param_0, s32 param_1, GameSelectInputEvent param_2)
{
    if (param_1 == 0x20) {
        switch (param_0->unk70_10) {
            case 2:
                func_808030EC_chgameselect(param_0, func_80101080(), param_2.local_0,
                                           param_2.local_1);
                break;
            case 3:
                func_808034BC_chgameselect(param_0, func_80101080(), param_2.local_0,
                                           param_2.local_1);
                break;
            default:
                func_80800AEC_chgameselect(param_0->unk3C, func_80101080(), param_2.local_0,
                                           param_2.local_1);
        }
    } else
        return 0;
    return 1;
}

void func_80802AD4_chgameselect(param_0, param_1, param_2, param_3, param_4) Unk80132ED0 *param_0;
s32 param_1;
s32 param_2;
s32 param_3;
s32 param_4;
{
    Actor *local_1;
    void *local_0;
    local_1 = func_80106790(param_0);
    _gcnewoption_entrypoint_4(local_1, 0, _gcnewoption_entrypoint_35, 0, param_1);
    local_0 = func_80100094(local_1, 0);
    _gcnewoption_entrypoint_36(local_0);
    if (param_4 <= 0)
        param_4 = 5;
    _gcnewoption_entrypoint_8(local_0, param_2 < param_4 ? param_2 : param_4);
    _gcnewoption_entrypoint_9(local_0, param_2);
    _gcnewoption_entrypoint_10(local_0, param_3 ? 2 : 3);
    _gcnewoption_entrypoint_40((s32) local_0, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_42((s32) local_0, 0.1f);
    _gcnewoption_entrypoint_11(local_0);
    func_80101FDC(local_1, 1);
}

void func_80802BE8_chgameselect()
{
    func_808029D8_chgameselect(func_80106790());
}

void func_80802C10_chgameselect(Unk80132ED0 *param_0)
{
    Actor *local_0;
    local_0 = func_80106790(param_0);
    _gcnewoption_entrypoint_38(func_80100094(local_0, 0), 1);
}

int func_80802C48_chgameselect()
{
    s32 local_0;
    local_0 = func_80106790();
    _gcnewoption_entrypoint_39(func_80100094(local_0, 0));
}

int func_80802C7C_chgameselect()
{
    u8 *local_0;
    local_0 = func_80106790();
    local_0[0x65] &= 0xFFEF;
    _gcnewoption_entrypoint_37(func_80100094(local_0, 0), 1);
}

void func_80802CC0_chgameselect()
{
    u8 *local_0;

    local_0 = func_80106790();
    local_0[0x65] &= 0xFFEF;
    _gcnewoption_entrypoint_37(func_80100094(local_0, 0), 0);
}

void func_80802D04_chgameselect(s32 param_0, s32 param_1)
{
    func_80106790(param_0)->unk64_20 = param_1;
}

void func_80802D40_chgameselect(Unk80132ED0 *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;

    local_0 = func_80106790(param_0);
    *(s32 *) ((u8 *) local_0 + 0x28) = param_1;
    *(s32 *) ((u8 *) local_0 + 0x2C) = 0;
    func_80802640_chgameselect(*(void **) ((u8 *) func_80106790(local_0->unk3C) + 0x24), param_2,
                               0);
    func_80100074(local_0, 1, *(s32 *) ((u8 *) local_0 + 0x28) * 6);
    func_80101FDC(local_0, 2);
}

void func_80802DB4_chgameselect(void *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4,
                                s32 param_5)
{
    Actor *local_0;
    GameSelectItem1213 *local_1;

    local_0 = (Actor *) func_80106790(param_0);
    local_1 = func_80100094(local_0, 1);
    local_1 = &local_1[((GameSelectActorCount1213 *) local_0)->unk2C];
    local_1->unk0 = param_1;
    local_1->unk1 = param_2;
    local_1->unk2 = param_3;
    local_1->unk3 = param_4;
    local_1->unk4 = param_5;
    ((GameSelectActorCount1213 *) local_0)->unk2C++;
}

void func_80802E38_chgameselect(param_0, param_1, param_2, param_3) void *param_0;
s32 param_1;
s32 param_2;
s32 param_3;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    u8 *local_3;

    local_0 = (u8 *) func_80106790(param_0);
    _gcnewoption_entrypoint_4(local_0, 0, _gcnewoption_entrypoint_35, 0, param_1);
    local_1 = func_80100094(local_0, 0);
    _gcnewoption_entrypoint_36(local_1);
    if (param_3 <= 0)
        param_3 = 5;
    _gcnewoption_entrypoint_8(
        local_1, *(s32 *) (local_0 + 0x2C) < param_3 ? *(s32 *) (local_0 + 0x2C) : param_3);
    _gcnewoption_entrypoint_9(local_1, *(s32 *) (local_0 + 0x2C));
    _gcnewoption_entrypoint_10(local_1, 0);
    *(s32 *) (local_0 + 0x30) = param_2;
    local_2 = 0;
    local_3 = (u8 *) func_80100094(local_0, 1);
    for (; local_2 < *(s32 *) (local_0 + 0x2C); local_2++, local_3 += 6) {
        _gcnewoption_entrypoint_31(local_1, local_2, *(s16 *) (local_3 + 4));
    }
    _gcnewoption_entrypoint_40(local_1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_42(local_1, 0.1f);
    _gcnewoption_entrypoint_11(local_1);
}

s32 func_80802F8C_chgameselect()
{
    u8 *local_0;
    s32 local_1;

    local_0 = (u8 *) func_80106790();
    local_1 = _gcnewoption_entrypoint_37(func_80100094((int) local_0, 0), 1);
    if (local_1 != 0) {
        local_0[0x65] &= 0xFFEF;
    }
    return local_1;
}

void func_80802FE4_chgameselect(Actor *param_0)
{
    Actor *local_0;

    func_80100074(param_0, 1, 0);
    param_0->actorData[5] = 0;
    param_0->actorData[4] = 0;
    param_0->unk64_20 = 0;
    _gcnewoption_entrypoint_6(param_0, 0);
    local_0 = (Actor *) func_80106790(param_0->unk3C);
    func_80802640_chgameselect(local_0->actorData[3], 0, 0);
}

void func_80803048_chgameselect(u8 *param_0, s32 param_1)
{
    s32 local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 1);
    local_0 = 0;
    if (*(s32 *) ((s8 *) param_0 + 0x2C) > 0) {
        do {
            _gcnewoption_entrypoint_12(param_1, local_0, (*(u8 *) ((s8 *) (local_1) + (1))));
            if (*(s8 *) ((s8 *) local_1 + 2) >= 0) {
                func_8080401C_chgameselect(param_1, local_0, 0);
            }
            local_0 += 1;
            local_1 += 6;
        } while (local_0 < *(s32 *) ((s8 *) param_0 + 0x2C));
    }
    _gcnewoption_entrypoint_41(param_1, (*(s32 *) ((s8 *) (param_0) + (0x30))));
}

void func_808030EC_chgameselect(arg0, arg1, arg2, arg3) u8 *arg0;
s32 arg1;
s32 arg2;
s32 arg3;
{
    s32 sp2C;
    s32 sp28;
    u8 *sp24;
    switch (arg3) {
        case 0:
            func_80803048_chgameselect(arg0, arg1);
            return;
        case 3:
            if (_gcnewoption_entrypoint_19(arg1, arg2) != 0) {
                func_80803C60_chgameselect();
                sp24 = func_80106790(*((s32 **) (((char *) arg0) + 0x3C)));
                func_808026C8_chgameselect(
                    *((s32 **) (((char *) sp24) + 0x2C)),
                    *(((s8 *) ((u8 *) func_80100094(arg0, 1) + (arg2 * 6))) + 2));
                return;
            }
        case 2:
            sp2C = (s32) (*((u8 *) ((u8 *) func_80100094(arg0, 1) + (arg2 * 6))));
            func_80802FE4_chgameselect(arg0);
            func_80800AEC_chgameselect(*((s32 **) (((char *) arg0) + 0x3C)), 0, sp2C, arg3);
    }
}

int func_808031F4_chgameselect(s32 param_0, s32 param_1)
{
    Actor *local_0;
    local_0 = func_80106790(param_0);
    *(s32 *) ((char *) local_0 + 0x2C) = 0;
    *(s32 *) ((char *) local_0 + 0x28) = param_1;
    func_80100074(local_0, 1, param_1 * 6);
    func_80101FDC(local_0, 3);
}

void func_80803248_chgameselect(void *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    Actor *local_0;
    GameSelectItem1213 *local_1;

    local_0 = (Actor *) func_80106790(param_0);
    local_1 = func_80100094(local_0, 1);
    local_1 = &local_1[((GameSelectActorCount1213 *) local_0)->unk2C];
    local_1->unk0 = param_1;
    local_1->unk1 = param_2;
    local_1->unk2 = -1;
    local_1->unk3 = param_3;
    local_1->unk4 = param_4;
    ((GameSelectActorCount1213 *) local_0)->unk2C++;
}

void func_808032CC_chgameselect(param_0, param_1, param_2, param_3) void *param_0;
s32 param_1;
s32 param_2;
s32 param_3;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    u8 *local_3;

    local_0 = (u8 *) func_80106790(param_0);
    _gcnewoption_entrypoint_4(local_0, 0, _gcnewoption_entrypoint_35, 0, param_1);
    local_1 = func_80100094(local_0, 0);
    _gcnewoption_entrypoint_36(local_1);
    if (param_3 <= 0)
        param_3 = 5;
    _gcnewoption_entrypoint_8(
        local_1, *(s32 *) (local_0 + 0x2C) < param_3 ? *(s32 *) (local_0 + 0x2C) : param_3);
    _gcnewoption_entrypoint_9(local_1, *(s32 *) (local_0 + 0x2C));
    _gcnewoption_entrypoint_10(local_1, 2);
    *(s32 *) (local_0 + 0x30) = param_2;
    local_2 = 0;
    local_3 = (u8 *) func_80100094(local_0, 1);
    for (; local_2 < *(s32 *) (local_0 + 0x2C); local_2++, local_3 += 6) {
        _gcnewoption_entrypoint_31(local_1, local_2, *(s16 *) (local_3 + 4));
    }
    _gcnewoption_entrypoint_40(local_1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_42(local_1, 0.1f);
    _gcnewoption_entrypoint_11(local_1);
}

void func_80803420_chgameselect(s32 param_0, s32 param_1)
{
    s32 local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 1);
    local_0 = 0;
    if (*(s32 *) ((char *) param_0 + 0x2C) > 0) {
        do {
            _gcnewoption_entrypoint_12(param_1, local_0, *(u8 *) ((char *) local_1 + 1));
            func_80803604_chgameselect(param_1, local_0, *(s8 *) ((char *) local_1 + 3), 0);
            local_0 += 1;
            local_1 += 6;
        } while (local_0 < *(s32 *) ((char *) param_0 + 0x2C));
    }
    _gcnewoption_entrypoint_41(param_1, *(s32 *) ((char *) param_0 + 0x30));
}



int func_808034BC_chgameselect(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; u32 param_2; s32 param_3;
{
  switch (param_3)
  {
    case 0 :
      func_80803420_chgameselect(param_0, param_1);
      break;

    case 4 :
      func_80803604_chgameselect(param_1, param_2, _gcnewoption_entrypoint_20(param_1, param_2), 1);
      break;

    case 5 :
      _gcnewoption_entrypoint_37(param_1, 1);
      break;

    case 2 :
    case 3 :
    {
      s32 local_1;
      u8 *local_0;
      u32 local_2;
      u8 *local_3;

      local_0 = func_80100094(param_0, 1);
      func_80800AEC_chgameselect(*(s32 *)((char *)param_0 + 0x3C), param_1, -1, 0xFC);
      local_1 = 0;
      local_3 = local_0;
      if (*(s32 *)((char *)param_0 + 0x2C) > 0)
      {
        do
        {
          if (_gcnewoption_entrypoint_17(param_1, local_1) != 0)
          {
            local_2 = 0xFE;
          }
          else
          {
            local_2 = 0xFD;
          }
          func_80800AEC_chgameselect(*(s32 *)((char *)param_0 + 0x3C), param_1, *local_3, local_2);
          local_1 += 1;
          local_3 += 6;
        }
        while (local_1 < *(s32 *)((char *)param_0 + 0x2C));
      }
      func_80802FE4_chgameselect(param_0);
      func_80800AEC_chgameselect(*(s32 *)((char *)param_0 + 0x3C), 0, -1, param_3);
    }

  }
}
void func_80803604_chgameselect(param_0, param_1, param_2, param_3) s32 param_0;
s32 param_1;
s32 param_2;
s32 param_3;
{
    if (param_2) {
        func_8080407C_chgameselect(param_0, param_1, param_3 | 0);
    } else {
        func_808040DC_chgameselect(param_0, param_1, param_3 | 0);
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

s32 func_808036F8_chgameselect(s32 param_0)
{
    return _glsavegame_entrypoint_2(param_0);
}

s32 func_80803718_chgameselect()
{
    return _glsavegame_entrypoint_3();
}


int func_80803738_chgameselect(param_0, param_1, param_2) s32 param_0; s32 *param_1; s32 *param_2;
{
  s32 local_0;
  if (func_808036F8_chgameselect(param_0))
  {
    local_0 = _glsavegame_entrypoint_4(param_0);
    *param_1 = func_800DB7C0(local_0);
    *param_2 = func_800D04A0(local_0, 1);
    return ((*param_1) < 0) ? (0) : (1);
  }
  return 0;
}
s32 func_808037C0_chgameselect(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    if (func_808036F8_chgameselect(param_0)) {
        local_0 = _glsavegame_entrypoint_4(param_0);
        local_1 = func_800DAC78(local_0, 0x441);
        local_2 = func_800D046C(local_0, 0x5A, 1);
        local_3 = func_800DAC78(local_0, 0x360);
        if (!local_1 && local_2 && !local_3)
            return 0xA4;
        if (local_1 && local_3)
            return 0xA5;
        return func_800DB83C(local_0, 0x1A) > 0 ? 0xA3 : 0xA2;
    }
    return 0xA1;
}

void func_80803888_chgameselect(Actor *param_0, u32 param_1, u32 param_2)
{
    func_80016BDC(param_2 ? 2 : 1);
    func_800C9E20(1.5f, _gcfrontend_entrypoint_8, param_1, param_2);
    func_80800478_chgameselect(param_0, 8);
}

void func_808038EC_chgameselect(s32 param_0, s32 param_1, s32 param_2)
{
    func_80016BDC(1);
    func_800C9E20(1.5f, _gcfrontend_entrypoint_7, param_1, param_2);
    func_80800478_chgameselect(param_0, 8);
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
    s32 local_0;
    switch (_gcstatusDll_entrypoint_14()) {
        case 4:
            break;
        case 5:
            local_0 = 0;
            do {
                _gcstatusDll_entrypoint_6(local_0, _gcstatusDll_entrypoint_15() == local_0 ? 5 : 4);
                local_0++;
            } while (local_0 < 4);
        case 6:
            break;
        default:
            func_80803940_chgameselect();
    }
}

void func_80803B3C_chgameselect(s32 param_0)
{
    func_80016BDC(_gcstatusDll_entrypoint_10());
    func_800C9DAC(1.5f, func_800AA1A0);
    func_80800478_chgameselect(param_0, 8);
}

void func_80803B84_chgameselect(s32 param_0)
{
    s32 *local_0;
    s32 local_1;
    local_1 = func_800AA120();
    local_0 = &D_80808370_chgameselect; loop_1: if (local_1 == (*((s32 *) (((s8 *) local_0) + 0)))) {
        (*((s32 (**)()) (((s8 *) local_0) + 4)))();
    }
    else
    {
        local_0 += 2;
        if (local_0 != D_808083A0_chgameselect) {
            goto loop_1;
        }

    }

    func_80803B3C_chgameselect(param_0);
}

void func_80803BE8_chgameselect(u8 *param_0)
{
    s32 *local_0;
    s32 local_1;
    s8 *new_var;
    func_800AA074();
    func_800AA054(*((s32 *) (((s8 *) param_0) + 0x54)));
    local_1 = func_800AA120();
    local_0 = D_808083A0_chgameselect; loop_1: if (local_1 == (*((s32 *) (((s8 *) local_0) + 0)))) { local_1 = 4;
        new_var = ((s8 *) local_0) + local_1;
        (*((s32 (**)(s32 *)) new_var))(D_808083C8_chgameselect);
    }
    else
    {
        local_0 += 2;
        if (local_0 != D_808083C8_chgameselect) {
            goto loop_1;
        }

    }

    func_80803B3C_chgameselect(param_0);
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

void func_80803D00_chgameselect(param_0, param_1) s32 param_0;
s32 param_1;
{
    GameSelectPacked1581 local_0;
    f32 local_1[3];
    f32 local_2[3];

    local_0.local_1.local_0 = param_1;
    local_0.local_1.local_1 = param_0;
    if (!func_80101180(0x4B9, 0x21, local_0.local_0)) {
        func_800A5800(param_0);
        _cadbfunc_entrypoint_0(local_1);
        _cadbfunc_entrypoint_2(local_2);
        func_800E39D8(local_1, local_2);
    }
}

int func_80803D60_chgameselect(param_0)
s32 param_0;
{
    switch (param_0) {
        case 0:
        case 1:
        case 2:
            return func_808036F8_chgameselect(param_0);

        case 5:
            return _gcfrontend_entrypoint_1(3);

        case 7:
            return _gcfrontend_entrypoint_2();

        default:
            return 1;
    }
}

s32 func_80803DCC_chgameselect(param_0)
s32 param_0;
{
    switch (param_0) {
        case 5:
            return _gcfrontend_entrypoint_1(3) ? 1 : 0;
        case 7:
            return _gcfrontend_entrypoint_2() ? 1 : 0;
        default:
            return 0;
    }
}

int func_80803E40_chgameselect()
{
    s32 local_0;
    for (local_0 = 0; local_0 < 4; local_0++) {
        if (!func_80016800(local_0)) {
            return local_0;
        }
    }

    return local_0;
}

void func_80803E94_chgameselect(param_0, param_1, param_2, param_3, param_4) u8 *param_0;
s32 param_1;
s32 param_2;
s32 param_3;
s32 *param_4;
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;

    local_1 = _gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0), (s16) param_2);
    local_0 = param_0;
    local_2 = 0;
    for (; *local_1; local_1++) {
        *local_0 = 0;

        if (*local_1 == '~') {
            func_800E6DB4(param_0, param_4[local_2++]);
            local_0 = param_0;
            while (*local_0) {
                local_0++;
            }
        } else {
            *local_0++ = *local_1;
        }
    }
    *local_0 = 0;
    _gldbstring_entrypoint_2(param_1);
}

void func_80803F90_chgameselect(s32 param_0, s32 param_1, s16 *param_2)
{
    s32 local_0;
    s32 local_1;
    s16 *local_2;
    func_800E73D4();
    if ((param_0 && param_0) && param_0) {
    }
    local_1 = 0;
    if (param_1 > 0) {
        local_2 = param_2;
        do {
            local_0 = _gldbstring_entrypoint_0(0, *((s16 *) (((char *) local_2) + 0)));

            if (local_0 != 0) {
                func_800E6A10(param_0,
                              _gldbstring_entrypoint_1(local_0, *(s16 *) ((char *) local_2 + 2)));
            }

            _gldbstring_entrypoint_2(*((s16 *) (((char *) local_2) + 0)));
            local_1 += 1;
            local_2 += 2;
        } while (local_1 != param_1);
    }
}

int func_8080401C_chgameselect(param_0, param_1, param_2)
s32 param_0;
s32 param_1;
s32 param_2;
{
    if (!_gcnewoption_entrypoint_19()) {
        _gcnewoption_entrypoint_23(param_0, param_1);
        _gcnewoption_entrypoint_13(param_0, param_1, D_808083C8_chgameselect);
        if (param_2 != 0) {
            func_80803CE0_chgameselect();
        }
    }
}

int func_8080407C_chgameselect(param_0, param_1, param_2)
s32 param_0;
s32 param_1;
s32 param_2;
{
    if (!_gcnewoption_entrypoint_17()) {
        _gcnewoption_entrypoint_21(param_0, param_1);
        _gcnewoption_entrypoint_13(param_0, param_1, &D_808083D0_chgameselect);
        if (param_2 != 0) {
            func_80803CC0_chgameselect();
        }
    }
}

int func_808040DC_chgameselect(param_0, param_1, param_2)
s32 param_0;
s32 param_1;
s32 param_2;
{
    if (!_gcnewoption_entrypoint_18()) {
        _gcnewoption_entrypoint_22(param_0, param_1);
        _gcnewoption_entrypoint_13(param_0, param_1, &D_808083D8_chgameselect);
        if (param_2 != 0) {
            func_80803CE0_chgameselect();
        }
    }
}

int func_8080413C_chgameselect(Actor *param_0)
{
    func_8080218C_chgameselect((u32) (*(u8 *) ((char *) (param_0) + 0x79)) >> 4, 1);
    func_80801658_chgameselect((*(s32 *) ((char *) (param_0) + 0x28)), 1);
    func_80803D00_chgameselect(((u32) (*(u8 *) ((char *) (param_0) + 0x79)) >> 4) + 8, 1);
    func_800DA3B8(0xD69, func_80803718_chgameselect());
    func_80803888_chgameselect(
        param_0, func_808037C0_chgameselect((u32) (*(u8 *) ((char *) (param_0) + 0x79)) >> 4), 0);
    return -1;
}

int func_808041C8_chgameselect(Actor *param_0)
{
    func_808015DC_chgameselect((*(s32 *) ((char *) (param_0) + 0x28)), 2);
    func_808016A0_chgameselect((*(s32 *) ((char *) (param_0) + 0x28)), 1);
    func_808016E8_chgameselect((*(s32 *) ((char *) (param_0) + 0x28)), 0);
    func_80803D00_chgameselect(1, 1);
    return 1;
}

int func_80804220_chgameselect(Actor *param_0)
{
    func_8080218C_chgameselect(*(s32 *)((char *)param_0 + 0x1C), func_80803D60_chgameselect(*(s32 *)((char *)param_0 + 0x1C)));
    func_8080218C_chgameselect(*(s32 *)((char *)param_0 + 0x20), func_80803D60_chgameselect(*(s32 *)((char *)param_0 + 0x20)));
    func_80801758_chgameselect(*(s32 *)((char *)param_0 + 0x28), -1);
    func_80801658_chgameselect(*(s32 *)((char *)param_0 + 0x28), 0);
    func_808015DC_chgameselect(*(s32 *)((char *)param_0 + 0x28), 0);
    func_808016A0_chgameselect(*(s32 *)((char *)param_0 + 0x28), 0);
    func_808016E8_chgameselect(*(s32 *)((char *)param_0 + 0x28), 3);
}

s32 func_808042A8_chgameselect(Actor *param_0, s32 param_1, s32 *param_2)
{
    s32 local_0;

    if (1) {
    }
    local_0 = 0;
    switch (*(s32 *) ((u8 *) param_0 + 0x18)) {
        case 0:
            if (func_808036F8_chgameselect(param_1)) {
                *param_2 = 2;
                *(s32 *) ((u8 *) param_0 + 0x18) = 1;
                *(s32 *) ((u8 *) param_0 + 0x1C) = param_1;
                func_80801758_chgameselect(*(s32 *) ((u8 *) param_0 + 0x28), param_1);
                func_8080218C_chgameselect(param_1, 0);
            } else {
                *param_2 = 6;
                local_0 = 1;
            }
            break;
        case 1:
            if (func_808036F8_chgameselect(param_1)) {
                *param_2 = 8;
                local_0 = 1;
            } else {
                *param_2 = 3;
                *(s32 *) ((u8 *) param_0 + 0x18) = 2;
                *(s32 *) ((u8 *) param_0 + 0x20) = param_1;
                func_80801658_chgameselect(*(s32 *) ((u8 *) param_0 + 0x28), 1);
                param_0->unk64_20 = 1;
            }
            break;
        case 2:
            if (!param_0->unk64_20) {
                *param_2 = 4;
                *(s32 *) ((u8 *) param_0 + 0x18) = 3;
                func_80803698_chgameselect(*(s32 *) ((u8 *) param_0 + 0x20),
                                           *(s32 *) ((u8 *) param_0 + 0x1C));
                func_80801714_chgameselect(*(s32 *) ((u8 *) param_0 + 0x28), 1);
            }
    }
    return local_0;
}

int func_80804404_chgameselect(s32 param_0[1], s32 param_1)
{
    int new_var;
    new_var = 3;
    if (param_0[6] >= new_var) {
        new_var = 1;
        func_80800478_chgameselect(param_0, new_var);
    } else {
        *(u8 *) ((char *) param_0 + 0x65) &= 0xFFEF;
    }
}

int func_8080444C_chgameselect(Actor *param_0)
{
    s32 local_0;
    local_0 = (*(s32 *) ((char *) (param_0) + 0x28));
    func_808015DC_chgameselect((s32 *) local_0, 1);
    func_808016A0_chgameselect((s32 *) (*(s32 *) ((char *) (param_0) + 0x28)), 1);
    func_808016E8_chgameselect((s32 *) (*(s32 *) ((char *) (param_0) + 0x28)), 0 | 0);
    func_80803D00_chgameselect(1, 1);
    return 1;
}

int func_808044A4_chgameselect(Actor *param_0)
{
    func_8080218C_chgameselect(*(s32 **) ((char *) param_0 + 0x1C),
                               func_80803D60_chgameselect(*(s32 **) ((char *) param_0 + 0x1C)));
    func_80801658_chgameselect(*(s32 **) ((char *) param_0 + 0x28), 0);
    func_808015DC_chgameselect(*(s32 **) ((char *) param_0 + 0x28), 0);
    func_808016A0_chgameselect(*(s32 **) ((char *) param_0 + 0x28), 0);
    func_808016E8_chgameselect(*(s32 **) ((char *) param_0 + 0x28), 4);
}

s32 func_8080450C_chgameselect(Actor *param_0, s32 param_1, s32 *param_2)
{
    s32 local_0;

    local_0 = 0;
    switch (param_0->actorData[0]) {
        case 0:
            if (func_808036F8_chgameselect(param_1) != 0) {
                *param_2 = 2;
                param_0->actorData[0] = 1;
                param_0->actorData[1] = param_1;
                func_80801658_chgameselect(param_0->actorData[4], 1);
                param_0->unk64_20 = 1;
            } else {
                *param_2 = 5;
                local_0 = 1;
            }
            break;
        case 1:
            if (!param_0->unk64_20) {
                *param_2 = 3;
                param_0->actorData[0] = 2;
                func_80803658_chgameselect(param_0->actorData[1]);
                func_80801714_chgameselect(param_0->actorData[4], 1);
            }
    }
    return local_0;
}

int func_808045E4_chgameselect(Actor *param_0, s32 param_1)
{
    if (*(s32 *) ((char *) param_0 + 0x18) >= 2) {
        func_80800478_chgameselect(param_0, 1);
    } else {
        *(u8 *) ((char *) param_0 + 0x65) &= 0xFFEF;
    }
}

s32 func_8080462C_chgameselect(Actor *param_0)
{
    func_80801658_chgameselect(param_0->actorData[4], 1);
    func_80802AD4_chgameselect(param_0->actorData[6],
                               D_80807DB0_chgameselect[param_0->unk79_4].sound, 3, 1, 0);
    func_80803D00_chgameselect(5, 1);
    return 1;
}

void func_80804694_chgameselect(Actor *param_0)
{
    func_80801658_chgameselect(*(void **) ((char *) param_0 + 0x28), 0);
    func_80802BE8_chgameselect(*(void **) ((char *) param_0 + 0x30));
    _glglobalsettings_entrypoint_2();
}

int func_808046D0_chgameselect(s32 param_0, s32 param_1)
{
    s32 local_0;
    s16 *local_1;
    local_1 = (s16 *) &D_808083E0_chgameselect;
    for (local_0 = 0; local_0 < 3; local_0++) {
        func_808049E8_chgameselect(param_1, local_0, func_80804948_chgameselect(local_0));
        _gcnewoption_entrypoint_31(param_1, local_0, *local_1);
        local_1 += 1;
    }
}

s32 func_80804750_chgameselect(s32 *param_0, s32 param_1, s32 param_2)
{
    s32 local_1;
    s32 local_0;

    local_1 = -1;
    if (param_0[6] == -2) {
        func_80804A38_chgameselect(param_0);
    } else if (param_0[6] != 0) {
        local_0 = _gcnewoption_entrypoint_20(param_1, param_2);
        func_80803C80_chgameselect();
        func_8080499C_chgameselect(param_2, local_0);
        if (param_2 == 1) {
            if (local_0) {
                local_1 = 6;
            } else {
                local_1 = 7;
            }
            param_0[6] = -2;
        } else {
            func_80804A38_chgameselect(param_0);
        }
    } else if (param_0[6] == 0) {
        func_80802C10_chgameselect(param_0[12]);
        switch (param_2) {
            case 0:
                local_1 = 2;
                param_0[6] = -1;
                func_80108B04(param_0, 0x1E8);
                break;
            case 1:
                local_1 = 3;
                param_0[6] = 2;
                break;
            case 2:
                local_1 = 4;
                param_0[6] = 4;
        }
    }
    return local_1;
}

void func_80804878_chgameselect(s32 *param_0, s32 param_1, s32 param_2)
{
    if (param_0[6]) {
        func_80804A38_chgameselect(param_0);
        if (!param_2) {
            _glglobalsettings_entrypoint_6(0, 0);
        } else {
            func_808049E8_chgameselect(param_1, param_2, func_80804948_chgameselect(param_2));
        }
    } else {
        func_80802C7C_chgameselect(param_0[12]);
    }
}

void func_808048F8_chgameselect(u8 *param_0, s32 *param_1)
{
    if (*(s32 *) (param_0 + 0x18) < -1) {
        func_80802C48_chgameselect(*(s32 *) (param_0 + 0x30), param_1);
        *(s32 *) (param_0 + 0x18) = 0;
        *param_1 = 1;
    }
}

int func_80804948_chgameselect(param_0)
s32 param_0;
{
    switch (param_0) {
        case 1:
            return _glglobalsettings_entrypoint_3();
        case 2:
            return _glglobalsettings_entrypoint_7();
        default:
            return 0;
    }
}

s32 func_8080499C_chgameselect(param_0, param_1)
s32 param_0;
s32 param_1;
{
    switch (param_0) {
        case 1:
            _glglobalsettings_entrypoint_4(param_1);
            break;
        case 2:
            _glglobalsettings_entrypoint_8(param_1);
    }
}

int func_808049E8_chgameselect(param_0, param_1, param_2)
s32 param_0;
s32 param_1;
s32 param_2;
{
    s16 new_var;
    int new_var2;
    {
    }
    do {
    } while (0);
    new_var2 = (param_1 * 5) + param_2;
    new_var = (s16) (new_var2 + 0xA);
    _gcnewoption_entrypoint_24(param_0);
    _gcnewoption_entrypoint_12(param_0, param_1, new_var);
}

int func_80804A38_chgameselect(param_0)
Actor *param_0;
{
    func_80802C48_chgameselect(*(s32 *) ((char *) param_0 + 0x30));
    func_808026C8_chgameselect(*(s32 *) ((char *) param_0 + 0x2C), 1);
    *(s32 *) ((char *) param_0 + 0x18) = 0;
    if (*(s32 *) ((char *) param_0 + 0x34) != 0) {
        func_800FFA88(*(s32 *) ((char *) param_0 + 0x34));
        *(s32 *) ((char *) param_0 + 0x34) = 0;
    }
}

void func_80804A8C_chgameselect(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    if ((s32) param_0->actorData[0] > 0) {
        local_0 = _gcnewoption_entrypoint_20(param_1, param_2) + 1;
        if (local_0 >= (s32) param_0->actorData[0]) {
            local_0 = 0;
        }
        func_808049E8_chgameselect(param_1, param_2, local_0);
    }
}

void func_80804AF0_chgameselect(u8 *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    if (*(s32 *) (param_0 + 0x18) > 0) {
        local_0 = _gcnewoption_entrypoint_20(param_1, param_2) - 1;
        if (local_0 < 0) {
            local_0 = *(s32 *) (param_0 + 0x18) - 1;
        }
        func_808049E8_chgameselect(param_1, param_2, local_0);
    }
}

int func_80804B4C_chgameselect(Actor *param_0)
{
    func_80801658_chgameselect(*(s32 **) ((char *) param_0 + 0x28), 1);
    func_80803D00_chgameselect(6, 1);
    func_80804C30_chgameselect(param_0, 0);
    return -1;
}

void func_80804B90_chgameselect(u8 *arg0)
{
    func_80801658_chgameselect(*(s32 **) (arg0 + 0x28), 0);
}

void func_80804BB4_chgameselect(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_2 < 3) {
        func_80804D30_chgameselect(param_0, param_2);
    } else {
        func_808038EC_chgameselect(param_0, param_2, 1);
    }
}

int func_80804BF4_chgameselect(s32 param_0[3], s32 param_1, s32 param_2)
{
    if (param_2 < 3) {
        func_80800478_chgameselect(param_0, 1);
    } else {
        func_80804C30_chgameselect(param_0, param_0[6]);
    }
}

void func_80804C30_chgameselect(param_0, param_1) Actor *param_0;
s32 param_1;
{
    s32 local_0;
    s32 local_1 = 0;
    s32 local_2 = 0;

    func_80802D40_chgameselect(param_0->actorData[6], 3, 0);
    for (local_0 = 0; local_0 != 3; local_0++) {
        if (_gcfrontend_entrypoint_1(D_808083E8_chgameselect[local_0][1])) {
            func_80802DB4_chgameselect(param_0->actorData[6], local_0, local_0 + 10, -1, -1,
                                       D_808083E8_chgameselect[local_0][2]);
            if (param_1 == D_808083E8_chgameselect[local_0][1]) {
                local_2 = local_1;
            }
            local_1++;
        }
    }
    func_80802E38_chgameselect(param_0->actorData[6],
                               D_80807DB0_chgameselect[param_0->unk79_4].sound, local_2, 0);
    func_808026C8_chgameselect(param_0->actorData[5], 2);
}

void func_80804D30_chgameselect(param_0, param_1) Actor *param_0;
s32 param_1;
{
    s32 local_3;
    s32 local_2;
    s32 local_1;
    s32 local_0;

    local_0 = D_808083E8_chgameselect[param_1][1];
    local_1 = _gcfrontend_entrypoint_4(local_0);
    local_2 = _gcfrontend_entrypoint_5(local_0);
    func_80802D40_chgameselect((Unk80132ED0 *) param_0->actorData[6], local_1, 0);
    local_3 = 0;
    if (local_1 > 0) {
        do {
            if (_gcfrontend_entrypoint_3((local_2 + local_3))) {
                func_80802DB4_chgameselect((void *) param_0->actorData[6], (local_2 + local_3),
                                           local_3, -1, -1,
                                           _gcfrontend_entrypoint_14((local_2 + local_3)));
            }
            local_3++;
        } while (local_3 != local_1);
    }
    func_80802E38_chgameselect((void *) param_0->actorData[6], D_808083E8_chgameselect[param_1][0],
                               0, 0);
    func_808026C8_chgameselect(param_0->actorData[5], param_1 + 3);
    param_0->actorData[0] = local_0;
}

int func_80804E34_chgameselect(Actor *param_0)
{
    s32 *local_1 = (s32 *) ((char *) param_0 + 0x28);
    func_80801658_chgameselect(*local_1, 1);
    if (_gcstatusDll_entrypoint_18() == 0xA) {
        *(s32 *) ((char *) param_0 + 0x20) = 0;
    } else if (_gcstatusDll_entrypoint_18() == 0x14) {
        *(s32 *) ((char *) param_0 + 0x20) = 1;
    } else if (_gcstatusDll_entrypoint_17() == 5) {
        *(s32 *) ((char *) param_0 + 0x20) = 2;
    } else if (_gcstatusDll_entrypoint_17() == 0xA) {
        *(s32 *) ((char *) param_0 + 0x20) = 3;
    } else {
        *(s32 *) ((char *) param_0 + 0x20) = 0;
    }
    *(u8 *) ((char *) param_0 + 0x65) &= ~0x10;
    if (func_800AA0B8()) {
        func_808065C0_chgameselect(param_0);
    } else {
        func_80805310_chgameselect(param_0);
        func_80803D00_chgameselect(4, 1);
    }
    return -1;
}

void func_80804F14_chgameselect(void *param_0)
{
    func_80801658_chgameselect((*(void **) ((char *) param_0 + 0x28)), 0);
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

void func_80804F38_chgameselect(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_0->actorData[0]) {
        case 0:
            func_80802BE8_chgameselect(*(s32 *) ((u8 *) param_0 + 0x30));
            _gcstatusDll_entrypoint_2(param_2 + 2);
            func_808069C8_chgameselect(func_808068E8_chgameselect());
            func_80806A88_chgameselect(func_80806A30_chgameselect());
            if (_gcstatusDll_entrypoint_10() < 3 && _gcstatusDll_entrypoint_14() == 4) {
                _gcstatusDll_entrypoint_4(1);
            }
            func_80805474_chgameselect((s32) param_0, 0);
            break;
        case 1:
            switch (param_2) {
                case 0:
                    func_80805BFC_chgameselect((s32) param_0, 0);
                    break;
                case 1:
                    func_80806408_chgameselect((u8 *) param_0);
                    break;
                case 2:
                    func_80806540_chgameselect((s32) param_0);
            }
            break;
        case 2:
            *(s32 *) ((u8 *) param_0 + 0x54) = param_2;
            switch (_gcfrontend_entrypoint_6(param_2)) {
                case 1:
                    func_80805CD8_chgameselect(param_0, 0);
                    break;
                case 2:
                    func_8080537C_chgameselect(param_0, 10, 0);
                    break;
                case 3:
                    func_8080537C_chgameselect(param_0, 11, 0);
                    break;
                default:
                    func_80803BE8_chgameselect(param_0);
            }
            break;
        case 10:
            func_80805F30_chgameselect(param_0, param_2);
            func_80803BE8_chgameselect(param_0);
            break;
        case 11:
            func_80805FCC_chgameselect((s32) param_0, param_2);
            func_80803BE8_chgameselect(param_0);
            break;
        case 8:
            func_80806744_chgameselect(param_0);
            break;
        case 3:
            switch (param_2) {
                case 0:
                    func_808061A8_chgameselect((u8 *) param_0);
                    break;
                case 2:
                    func_80806834_chgameselect(param_0);
                    break;
                default:
                    func_8080537C_chgameselect(param_0, param_2 + 4,
                                               func_80805ECC_chgameselect(param_0, param_2));
            }
            break;
        case 5:
        case 6:
        case 7:
            func_80806068_chgameselect(param_0, param_0->actorData[0] - 4, param_2);
            func_808051B4_chgameselect(param_0, param_1, param_2);
            break;
        default:
            func_80800478_chgameselect(param_0, 1);
    }
}

void func_80806370_chgameselect();

void func_808051B4_chgameselect(param_0, param_1, param_2) Actor *param_0;
s32 param_1;
s32 param_2;
{
    switch (param_0->actorData[0]) {
        case 0:
            func_80802BE8_chgameselect(param_0->actorData[6], param_1);
            func_80800478_chgameselect(param_0, 1);
            break;
        case 1:
            func_80805310_chgameselect(param_0);
            break;
        case 2:
            func_80805474_chgameselect((s32) param_0, 0);
            break;
        case 8:
            func_80805474_chgameselect((s32) param_0, 1);
            break;
        case 3:
            if (param_0->unk64_20)
                func_80803BE8_chgameselect(param_0);
            else
                func_80805BFC_chgameselect(param_0, 0);
            break;
        case 10:
        case 11:
            func_80805BFC_chgameselect(param_0, 0);
            break;
        case 5:
            func_80805CD8_chgameselect(param_0, 1);
            break;
        case 6:
            func_808068AC_chgameselect(param_0);
            func_80805CD8_chgameselect(param_0, 2);
            break;
        case 7:
            func_80805CD8_chgameselect(param_0, 3);
            break;
        case 4:
            func_80806370_chgameselect(param_0);
            func_80805CD8_chgameselect(param_0, 0);
            break;
        default:
            func_80800478_chgameselect(param_0, 1);
    }
}

void func_80805310_chgameselect(param_0) Actor *param_0;
{
    s32 arg0;
    u8 arg1_tmp;
    s16 arg1;
    arg0 = *((s32 *) (((char *) param_0) + 0x30));
    arg1_tmp = *((u8 *) (((char *) param_0) + 0x79));
    arg1 =
        *((s16 *) (((char *) D_80807DB0_chgameselect) +
                   (((((((((((((((u32) arg1_tmp) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) &
                          0xFF) &
                         0xFF) &
                        0xFF) &
                       0xFF) &
                      0xFF) >>
                     4) *
                    4)));
    func_80802AD4_chgameselect(arg0, arg1, 3, 1, 0);
    func_80802D04_chgameselect(*((s32 *) (((char *) param_0) + 0x30)), 1);
    func_808026C8_chgameselect(*((s32 *) (((char *) param_0) + 0x2C)), 2);
    *((s32 *) (((char *) param_0) + 0x18)) = 0;
}

void func_8080537C_chgameselect(s32 *param_0, s32 param_1, s32 param_2)
{
    s32 local_1;

    func_80802D40_chgameselect(param_0[0x30 / 4], D_80808424_chgameselect[param_1].count,
                               D_80808424_chgameselect[param_1].unk6);
    for (local_1 = 0; local_1 < D_80808424_chgameselect[param_1].count; local_1++) {
        func_80802DB4_chgameselect(
            param_0[0x30 / 4], local_1, D_80808424_chgameselect[param_1].unk1 + local_1, -1,
            (D_80808424_chgameselect[param_1].unk3 >= 0)
                ? D_80808424_chgameselect[param_1].unk3 + local_1
                : -1,
            (D_80808424_chgameselect[param_1].unk8) ? D_80808424_chgameselect[param_1].unk8[local_1]
                                                    : 0x9D);
    }
    func_80802E38_chgameselect(param_0[0x30 / 4], D_80808424_chgameselect[param_1].unk4, param_2,
                               4);
    func_808026C8_chgameselect(param_0[0x2C / 4], D_80808424_chgameselect[param_1].unk2);
    param_0[0x18 / 4] = param_1;
}

void func_80805474_chgameselect(s32 arg0, s32 arg1)
{
    func_8080537C_chgameselect(arg0, 0x1, arg1);
}

void func_80805498_chgameselect(u8 *param_0, void *param_1)
{
    s32 local_0;
    s32 local_1;

    switch (*(s32 *) (param_0 + 0x18)) {
        case 0:
            for (local_0 = 0; local_0 != 3; local_0++) {
                _gcnewoption_entrypoint_12(param_1, local_0, local_0 + 0xC);
                _gcnewoption_entrypoint_31(param_1, local_0, D_808083FC_chgameselect[local_0]);
                func_80805BA0_chgameselect(param_1, local_0, 0);
            }
            _gcnewoption_entrypoint_41(
                param_1, _gcstatusDll_entrypoint_10() >= 2 ? _gcstatusDll_entrypoint_10() - 2 : 0);
            break;
        case 4:
            local_1 = _gcstatusDll_entrypoint_10();
            for (local_0 = 0; local_0 < local_1; local_0++) {
                func_80806218_chgameselect(param_1, local_0, func_808062A8_chgameselect(local_0),
                                           0);
            }
            break;
        case 6:
            _gcnewoption_entrypoint_12(param_1, 0, 0);
            _gcnewoption_entrypoint_12(param_1, 1, 1);
            _gcnewoption_entrypoint_12(param_1, 2, 2);
            func_80806AF4_chgameselect(param_1, 4, func_80806A30_chgameselect());
            if (_gcstatusDll_entrypoint_10() < 3) {
                _gcnewoption_entrypoint_12(param_1, 3, 0xC);
                func_8080401C_chgameselect(param_1, 3, 0);
            } else {
                func_80806AF4_chgameselect(param_1, 3, func_808068E8_chgameselect());
            }
            for (local_0 = 0; local_0 != 5; local_0++) {
                _gcnewoption_entrypoint_31(param_1, local_0, D_8080840C_chgameselect[local_0]);
            }
            _gcnewoption_entrypoint_41(param_1, func_80805ECC_chgameselect(param_0, 2));
    }
}

void func_8080569C_chgameselect(u8 *param_0, u32 param_1)
{
    s32 local_2;
    s32 local_3;
    s32 local_6;
    s32 local_7;
    s32 local_8;
    s32 local_9;
    s32 local_0[2];
    f32 local_1[2];
    Mass63GameSelectInput *local_4;
    u8 *local_5;

    switch (*(s32 *) (param_0 + 0x18)) {
        case 0:
        for (local_3 = 0; local_3 != 3; local_3++) {
            func_80805BA0_chgameselect(param_1, local_3, 1);
        }
        return;
        case 4:
        local_2 = _gcstatusDll_entrypoint_10();
        local_4 = (Mass63GameSelectInput *) func_80100094(param_0, 1);
        local_3 = 0;
        if (local_2 > 0) {
            local_5 = local_4->local_0;
            do {
                func_80016068(local_3, local_1);
                func_80015E80(local_3, local_0);

                switch (*local_5) {
                    case 1:
                    if (func_800D9078(&local_4->local_1[local_3])) *local_5 = 0;
                    break;
                    case 0:
                    if (1 == local_0[0]) {
                        *local_5 = 2;
                        _gcnewoption_entrypoint_43(param_1, local_3, 1);
                        func_80803CC0_chgameselect();
                    } else if (local_1[0] > 0.8f) {
                        func_808062EC_chgameselect(param_1, local_3, 1);
                        *local_5 = 1;
                        local_4->local_1[local_3] = 0.5f;
                    } else if (local_1[0] < -0.8f) {
                        func_808062EC_chgameselect(param_1, local_3, -1);
                        *local_5 = 1;
                        local_4->local_1[local_3] = 0.5f;
                    }
                    break;
                    case 2:
                    if (1 == local_0[1]) {
                        *local_5 = 0;
                        _gcnewoption_entrypoint_43(param_1, local_3, 0);
                        func_80803CE0_chgameselect();
                    }
                }
                local_3++;
                local_5++;
            } while (local_3 != local_2);
        }
        local_3 = 0;
        if (local_2 > 0) {
            local_5 = local_4->local_0;
            do {
                if (2 != *local_5) break;
                local_3++;
                local_5++;
            } while (local_3 < local_2);
        }
        if (local_3 == local_2 && func_80802F8C_chgameselect(*(s32 *)(param_0 + 0x30))) {
            ((Actor *)param_0)->unk64_20 = 1;
        }
        return;
        case 6:
        func_808026C8_chgameselect(*(s32 *)(param_0 + 0x24), _gcnewoption_entrypoint_45(param_1) + 0x1E);
        return;
        default:
        if (func_80015FA0(0) && func_80802F8C_chgameselect(*(s32 *)(param_0 + 0x30))) {
            ((Actor *)param_0)->unk64_20 = 1;
        }
    }
}


int func_8080595C_chgameselect(s32 *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    switch (param_0[6]) {
    case 0:
        if (_gcnewoption_entrypoint_19(param_1, param_2)) {
            func_80803C60_chgameselect();
            return param_2 + 0x23;
        }
        func_80802CC0_chgameselect(param_0[12]);
        return -1;
    case 6:
        if (param_2 == 3 || param_2 == 4) {
            if (param_0[7] != -1) {
                local_0 = _gcnewoption_entrypoint_20(param_1, param_2);
                if (param_2 == 3) func_808069C8_chgameselect(local_0);
                else func_80806A88_chgameselect(local_0);
                param_0[7] = -1;
}
else
{
    if (_gcnewoption_entrypoint_19(param_1, param_2)) {
        func_80803C60_chgameselect();
        return 0x1E;
    }

func_80802C10_chgameselect(param_0[12]);
param_0[7] = param_2;
return (param_2 == 3) ? 0x1F : 0x20;
}
}
func_80802CC0_chgameselect(param_0[12]);
func_80803C80_chgameselect();
}
return -1;
}
void func_80805AC0_chgameselect(u8 *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    local_0 = *(s32 *) (param_0 + 0x18);
    switch (local_0) {
        case 0:
            func_80802C7C_chgameselect(*(s32 *) (param_0 + 0x30));
            break;
        case 6:
            local_1 = *(s32 *) (param_0 + 0x1C);
            if (local_1 != -1 && param_2 == local_1) {
                func_80802C48_chgameselect(*(s32 *) (param_0 + 0x30));
                func_808026C8_chgameselect(*(s32 *) (param_0 + 0x2C), 9);
                *(s32 *) (param_0 + 0x1C) = -1;
                if (param_2 == 3) {
                    local_0 = func_808068E8_chgameselect();
                } else {
                    local_0 = func_80806A30_chgameselect();
                }
                func_80806AF4_chgameselect((void *) param_1, param_2, local_0);
            } else {
                func_80802C7C_chgameselect(*(s32 *) (param_0 + 0x30));
            }
    }
}

int func_80805BA0_chgameselect(param_0, param_1, param_2)
s32 param_0;
s32 param_1;
s32 param_2;
{
    if (func_80803E40_chgameselect() >= (param_1 + 2)) {
        func_8080407C_chgameselect(param_0, param_1, param_2);
        return;
    }
    func_8080401C_chgameselect(param_0, param_1, param_2);
}

int func_80805BFC_chgameselect(s32 param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    local_0 = _gcfrontend_entrypoint_4(3);
    local_1 = _gcfrontend_entrypoint_5(3);
    func_80802D40_chgameselect(*(s32 **) ((char *) param_0 + 0x30), local_0, 0);
    local_2 = 0;
    if (local_0 > 0) {
        local_3 = local_1;
        do {
            if (_gcfrontend_entrypoint_3(local_3) != 0) {
                func_80802DB4_chgameselect(*(s32 **) ((char *) param_0 + 0x30), local_3, local_2,
                                           -1, -1, _gcfrontend_entrypoint_14(local_3));
            }
            local_2 += 1;
            local_3 += 1;
        } while (local_2 != local_0);
    }
    func_80802E38_chgameselect(*(s32 **) ((char *) param_0 + 0x30), 0x18E4, param_1, 0);
    func_808026C8_chgameselect(*(s32 **) ((char *) param_0 + 0x2C), 4);
    *(s32 **) ((char *) param_0 + 0x18) = 2;
}

void func_80805CD8_chgameselect(Actor *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 0;
    func_80806068_chgameselect(param_0, 1, param_0->actorData[2]);
    if (_gcstatusDll_entrypoint_14() == 6) {
        _gcstatusDll_entrypoint_4(1);
    }
    func_80806068_chgameselect(param_0, 2, _gcstatusDll_entrypoint_14() - 1);
    local_1 = func_80805ECC_chgameselect(param_0, 2);
    if (local_1 == 2 || local_1 == 4) {
        local_0 = 1;
    }
    switch (local_1) {
        case 3:
            local_2 = func_808068E8_chgameselect() + 10;
            break;
        case 4:
            local_2 = func_80806A30_chgameselect() + 20;
            break;
        default:
            local_2 = local_1 + 5;
            break;
    }
    func_80802D40_chgameselect(param_0->actorData[6], 4, 0);
    func_80802DB4_chgameselect(param_0->actorData[6], 0, 0, -1, -1, D_80808404_chgameselect[0]);
    local_1 = func_80805ECC_chgameselect(param_0, 1);
    func_80802DB4_chgameselect(param_0->actorData[6], 1, local_1 + 0x23, local_0 ? 0x26 : -1, -1,
                               D_80808405_chgameselect);
    func_80802DB4_chgameselect(param_0->actorData[6], 2, local_2, -1, -1, D_80808406_chgameselect);
    local_1 = func_80805ECC_chgameselect(param_0, 3);
    func_80802DB4_chgameselect(param_0->actorData[6], 3, local_1 + 0x1B, local_0 ? 0x27 : -1, -1,
                               D_80808407_chgameselect);
    func_80802E38_chgameselect(param_0->actorData[6], 0x18F4, param_1, 4);
    func_808026C8_chgameselect(param_0->actorData[5], 6);
    param_0->actorData[0] = 3;
    func_80802D04_chgameselect(param_0->actorData[6], 1);
}

s32 func_80805ECC_chgameselect(param_0, param_1)
u8 *param_0;
s32 param_1;
{
    switch (param_1) {
        case 1:
            return (*(s32 *) ((s8 *) (param_0) + (0x20)));
        case 2:
            return _gcstatusDll_entrypoint_14() - 1;
        case 3:
            return _gcstatusDll_entrypoint_19() - 2;
        default:
            return 0;
    }
}

s32 func_80805F30_chgameselect(volatile s32 param_0, s32 param_1)
{
    switch (param_1) {
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

void func_80805FCC_chgameselect(s32 param_0, s32 param_1)
{
    switch (param_1) {
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

void func_80806068_chgameselect(param_0, param_1, param_2) Actor *param_0;
s32 param_1;
s32 param_2;
{
    switch (param_1) {
        case 1:
            *(s32 *) ((u8 *) param_0 + 0x20) = param_2;
            switch (param_2) {
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
            _gcstatusDll_entrypoint_4(param_2 + 1);
            switch (param_2) {
                case 2:
                case 4:
                    func_80806068_chgameselect(param_0, 1, 2);
                    _gcstatusDll_entrypoint_9(0);
                    return;
                case 3:
                default:
                    if (!_gcstatusDll_entrypoint_19())
                        _gcstatusDll_entrypoint_9(2);
                    return;
            }
        case 3:
            _gcstatusDll_entrypoint_9(param_2 + 2);
    }
}

void func_808061A8_chgameselect(u8 *param_0)
{
    func_80802AD4_chgameselect((*(s32 *) ((s8 *) (param_0) + (0x30))), 0x18EF,
                               _gcstatusDll_entrypoint_10(), 0, 0);
    func_80802D04_chgameselect((*(s32 *) ((s8 *) (param_0) + (0x30))), 1);
    func_808026C8_chgameselect((*(s32 *) ((s8 *) (param_0) + (0x2C))), 7);
    (*(s32 *) ((s8 *) (param_0) + (0x18))) = 4;
    func_80100074(param_0, 1, 0x14);
}

void func_80806218_chgameselect(param_0, param_1, param_2, param_3) s32 param_0;
s32 param_1;
s32 param_2;
s32 param_3;
{
    _gcnewoption_entrypoint_24();
    _gcnewoption_entrypoint_12(param_0, param_1, (s16) (param_1 * 10 + param_2));
    _gcnewoption_entrypoint_31(param_0, param_1, D_8080841C_chgameselect[param_2]);
    if (param_3)
        _gczoomboxdata_entrypoint_0(D_8080841C_chgameselect[param_2]);
}

int func_808062A8_chgameselect()
{
    return _gcstatusDll_entrypoint_13() - 1;
}

s32 func_808062CC_chgameselect(s32 param_0, s32 param_1)
{
    _gcstatusDll_entrypoint_3(param_0, param_1 + 1);
}

int func_808062EC_chgameselect(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    local_0 = _gcnewoption_entrypoint_20(param_0, param_1) + param_2;
    if (local_0 == 2) {
        local_1 = func_800DA298(0xC0B);
        if (!local_1) {
            local_0 += param_2;
        }
    }
    if (local_0 >= 5) {
        local_0 = 0;
    } else if (local_0 < 0) {
        local_0 = 4;
    }
    func_80806218_chgameselect(param_0, param_1, local_0, 1);
}

void func_80806370_chgameselect(param_0, param_1) u8 *param_0;
s32 param_1;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_1 = _gcstatusDll_entrypoint_10();
    local_0 = local_1;
    local_2 = 0;
    (*(u8 *) ((s8 *) (param_0) + (0x65))) = (u8) ((*(u8 *) ((s8 *) (param_0) + (0x65))) & 0xFFEF);
    if (local_1 > 0) {
        do {
            func_808062CC_chgameselect(local_2, _gcnewoption_entrypoint_20(param_1, local_2));
            local_2 += 1;
        } while (local_2 < local_0);
    }
    func_80802BE8_chgameselect((*(s32 *) ((s8 *) (param_0) + (0x30))));
    func_80100074(param_0, 1, 0);
}

void func_80806408_chgameselect(u8 *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_2 = _gcfrontend_entrypoint_4(3);
    local_0 = _gcfrontend_entrypoint_5(3);
    func_808031F4_chgameselect((*(s32 *) ((s8 *) (param_0) + (0x30))), local_2);
    local_4 = 0;
    if (local_2 > 0) {
        local_3 = local_0;
        do {
            if (_gcfrontend_entrypoint_3(local_3) != 0) {
                local_1 = func_800AA274(local_3);
                func_80803248_chgameselect((*(s32 *) ((s8 *) (param_0) + (0x30))), local_3, local_4,
                                           local_1, _gcfrontend_entrypoint_14(local_3));
            }
            local_4 += 1;
            local_3 += 1;
        } while (local_4 != local_2);
    }
    func_808032CC_chgameselect((*(s32 *) ((s8 *) (param_0) + (0x30))), 0x18E4, 0, 0);
    func_808026C8_chgameselect((*(s32 *) ((s8 *) (param_0) + (0x2C))), 5);
    (*(s32 *) ((s8 *) (param_0) + (0x18))) = 8;
}

void func_808064E8_chgameselect(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    if (param_3 != 0xFC) {
        if ((param_3 != 0xFD) && (param_3 == 0xFE)) {
            func_800AA054(param_2);
        }
    } else {
        func_800AA074(param_2);
    }
}

void func_80806540_chgameselect(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    func_800AA074();
    local_0 = _gcfrontend_entrypoint_4(3);
    local_1 = _gcfrontend_entrypoint_5(3);
    local_3 = 0;
    if (local_0 > 0) {
        local_2 = local_1;
        do {
            if (_gcfrontend_entrypoint_3(local_2) != 0) {
                func_800AA054(local_2);
            }
            local_3 += 1;
            local_2 += 1;
        } while (local_3 != local_0);
    }
    func_80806744_chgameselect(param_0);
}

s32 func_808065C0_chgameselect(param_0)
s32 param_0;
{
    func_80803D00_chgameselect(7, 1);
    func_80108B04(param_0, 0x4B6);
}

void func_808065F4_chgameselect(param_0) Actor *param_0;
{
    s32 local_1;
    s32 local_0;
    func_80802640_chgameselect(param_0->actorData[5],
                               D_80807DB0_chgameselect[param_0->unk79_4].sound, 0);
    if (func_800AA240()) {
        local_1 = func_800AA0D0();
        if (local_1 == 1) {
            local_0 = 0;
            func_800AA074();
        } else if (func_808066CC_chgameselect() == local_1) {
            local_0 = 2;
            func_800AA074();
        } else
            local_0 = 1;
        func_800AA00C();
        func_80805474_chgameselect(param_0, local_0);
        func_80803D00_chgameselect(4, 1);
    } else
        func_80806744_chgameselect(param_0);
}

s32 func_808066CC_chgameselect(void)
{
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 temp_s3;
    s32 temp_v0;
    var_s2 = 0;
    temp_s3 = _gcfrontend_entrypoint_4(3);
    temp_v0 = _gcfrontend_entrypoint_5(3);
    var_s1 = 0;
    if (temp_s3 > 0) {
        var_s0 = temp_v0;
        do {
            if (_gcfrontend_entrypoint_3(var_s0) != 0) {
                var_s2 += 1;
            }
            var_s1 += 1;
            var_s0 += 1;
        } while (var_s1 != temp_s3);
    }
    return var_s2;
}

void func_80806744_chgameselect(param_0) u8 *param_0;
{
    s32 local_2;
    s32 local_1;

    local_2 = func_800AA0C4() + 1;
    (*(s16 *) ((s8 *) (&B_80808550_chgameselect) + (0))) = 0x18F2;
    if (func_800AA0D0() == (local_2 + 1)) {
        (*(s16 *) ((s8 *) (&B_80808550_chgameselect) + (2))) = 0x27;
    } else {
        (*(s16 *) ((s8 *) (&B_80808550_chgameselect) + (2))) = (s16) local_2;
    }
    (*(s16 *) ((s8 *) (&B_80808550_chgameselect) + (4))) = 0x18E4;
    local_1 = func_800AA120();
    (*(s16 *) ((s8 *) (&B_80808550_chgameselect) + (6))) =
        (s16) (local_1 - _gcfrontend_entrypoint_5(3));
    func_80803F90_chgameselect((*(s32 *) ((s8 *) (param_0) + (0x50))), 2, &B_80808550_chgameselect);
    func_800E6A58((*(s32 *) ((s8 *) (param_0) + (0x50))), 0x21);
    func_80802730_chgameselect((*(s32 *) ((s8 *) (param_0) + (0x2C))),
                               (*(s32 *) ((s8 *) (param_0) + (0x50))));
    (*(s32 *) ((s8 *) (param_0) + (0x18))) = 9;
}

int func_80806800_chgameselect(s32 param_0[4], s32 param_1)
{
    if (*(s32 *) ((s8 *) param_0 + 24) == 9) {
        func_80803B84_chgameselect((s32) param_0);
    }
}

void func_80806834_chgameselect(Actor *param_0)
{
    s32 local_0;

    local_0 = 4;
    func_80802AD4_chgameselect(*(s32 **) ((char *) param_0 + 0x30), 0x18F0, 5, 1, local_0);
    func_80802D04_chgameselect(*(s32 **) ((char *) param_0 + 0x30), 1);
    func_808026C8_chgameselect(*(s32 **) ((char *) param_0 + 0x2C), 9);
    func_80802640_chgameselect(*(s32 **) ((char *) param_0 + 0x24), 0x18F0, 0);
    *(s32 **) ((char *) param_0 + 0x18) = 6;
    *(s32 **) ((char *) param_0 + 0x1C) = -1;
}

int func_808068AC_chgameselect(param_0, param_1)
Actor *param_0;
s32 param_1;
{
    s32 local_0;
    local_0 = *(s32 *) ((char *) (param_0) + 0x30);
    func_80802BE8_chgameselect(local_0);
    func_80802640_chgameselect(*(s32 *) ((char *) (param_0) + 36), 0, 0);
}

s32 func_808068E8_chgameselect(void)
{
    s32 local_3;
    s32 local_1;
    s32 local_2;
    s32 local_0;
    s32 local_4;

    local_4 = 0;
    local_1 = _gcstatusDll_entrypoint_10();
    local_0 = func_80806AA8_chgameselect();
    for (local_3 = 0; local_3 < local_1; local_3++) {
        local_2 = _gcstatusDll_entrypoint_16(local_3);
        if (local_2 < 4) {
            break;
        }
        if (local_2 == 4) {
            local_4 |= 1 << local_3;
        }
    }
    if (local_3 < local_1) {
        _gcstatusDll_entrypoint_6(0, 4);
        _gcstatusDll_entrypoint_6(1, 5);
        _gcstatusDll_entrypoint_6(2, 5);
        _gcstatusDll_entrypoint_6(3, 5);
        local_4 = 1;
    }
    if (local_4 <= 0) {
        local_4 = 1;
    } else if (local_0 < local_4) {
        local_4 = local_0;
    }
    return local_4 - 1;
}

void func_808069C8_chgameselect(param_0) s32 param_0;
{
    s32 local_0;
    s32 local_1;

    for (local_0 = 0; local_0 < 4; local_0++) {
        local_1 = ((1 << local_0) & (param_0 + 1)) ? 4 : 5;
        _gcstatusDll_entrypoint_6(local_0, local_1);
    }
}

int func_80806A30_chgameselect()
{
    s32 local_0;
    local_0 = _gcstatusDll_entrypoint_15();
    if (local_0 < 0) {
        local_0 = 0;
    } else {
        if (_gcstatusDll_entrypoint_10() <= local_0) {
            local_0 = _gcstatusDll_entrypoint_10() - 1;
        }
    }
    return local_0;
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
    s32 local_0;

    local_0 = param_1 == 3 ? 5 : 15;
    _gcnewoption_entrypoint_24(param_0, param_1, param_2);
    _gcnewoption_entrypoint_12(param_0, param_1, (s16) (local_0 + param_2));
}

int func_80806B5C_chgameselect(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_1;
    s32 local_0;
    local_1 = _gcnewoption_entrypoint_20(param_1 | 0, param_2 | 0) + 1;
    if (param_2 == 3) {
        local_0 = func_80806AA8_chgameselect();
    } else {
        local_0 = func_80806AD4_chgameselect();
    }
    if (local_1 >= local_0) {
        local_1 = 0;
    }
    func_80806AF4_chgameselect(param_1, param_2, local_1);
}

int func_80806BD4_chgameselect(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    local_0 = _gcnewoption_entrypoint_20(param_1, param_2) - 1;
    if (param_2 == 3) {
        local_1 = func_80806AA8_chgameselect();
    } else {
        local_1 = func_80806AD4_chgameselect();
    }
    if (local_0 < 0) {
        local_0 = local_1 - 1;
    }
    func_80806AF4_chgameselect(param_1, param_2, local_0);
}

int *chgameselect_entrypoint_6()
{
    return &D_808084B4_chgameselect;
}

void func_808073AC_chgameselect();

void func_80806C54_chgameselect(param_0) Actor *param_0;
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_3;
    local_0 = func_80100094(param_0, 0);
    param_0->unk6C_0 = _gcstatusDll_entrypoint_10();
    local_2 = 0;
    local_3 = 66;
    local_1 = local_0;
    for (; (u32) local_2 < param_0->unk6C_0; local_2++) {
        *(s32 *) local_1 = _gczoombox_entrypoint_5(local_3, 12, 2, 0, 0);
        _gczoombox_entrypoint_26(*(void **) local_1, 65, 0.8f, 1.0f, 0);
        func_800C9F48(local_2 * 0.1f, param_0->unk0, local_2);
        *(void **) (local_1 + 0x10) = heap_alloc(0x100);
        local_3 += 38;
        local_1 += 4;
    }
    *(void **) (local_0 + 0x20) = heap_alloc(0x100);
    *(s16 *) (local_0 + 0x26) = 0;
    *(s16 *) (local_0 + 0x24) = *(s16 *) (local_0 + 0x26);
    func_808073AC_chgameselect(param_0);
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

void func_80806FAC_chgameselect(param_0, param_1) Actor *param_0;
s32 param_1;
{
    void **local_1;
    s32 local_0;

    local_1 = func_80100094(param_0, 0);
    for (local_0 = 0; local_0 < param_0->unk6C_0; local_0++) {
        _gczoombox_entrypoint_2(local_1[local_0], param_1);
    }
}

void func_80807030_chgameselect(param_0) Actor *param_0;
{
    s32 local_1;
    GameSelectResources1358 *local_0;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 4; local_1++) {
        if (local_0->local_0[local_1]) {
            _gczoombox_entrypoint_0(local_0->local_0[local_1]);
        }
        if (local_0->local_1[local_1]) {
            heap_free(local_0->local_1[local_1]);
        }
    }
    if (local_0->local_2) {
        heap_free(local_0->local_2);
    }
}

int func_808070C0_chgameselect(param_0, param_1, param_2)
Actor *param_0;
s32 param_1;
s32 param_2;
{
    void **local_0;
    switch (param_1) {
        case 0x22:
            local_0 = func_80100094(param_0, 0);
            _gczoombox_entrypoint_18(local_0[param_2]);
            _gczoombox_entrypoint_16(local_0[param_2]);
            _gczoombox_entrypoint_9(local_0[param_2]);
            _gczoombox_entrypoint_11(local_0[param_2]);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080714C_chgameselect(Actor *param_0, s32 (*param_1)(s32), s32 param_2, s32 param_3,
                                s32 param_4, s32 param_5, s32 param_6)
{
    s32 local_3;
    RankData *local_0;
    s32 local_1[4];
    s32 local_2[4];

    local_0 = func_80100094(param_0, 0);
    for (local_3 = 0; local_3 < param_0->unk6C_0; local_3++) {
        local_1[local_3] = param_1(local_3);
        local_2[local_3] = local_3 + 1;
    }
    if (param_6 || !func_800AA194()) {
        _sumultiscore_entrypoint_0(local_1, local_2, param_0->unk6C_0);
    } else {
        _sumultiscore_entrypoint_1(local_1, local_2, param_0->unk6C_0);
    }
    for (local_3 = 0; local_3 < param_0->unk6C_0; local_3++) {
        B_80808560_chgameselect.id = local_2[local_3];
        B_80808560_chgameselect.score = local_1[local_3];
        B_80808560_chgameselect.rank = (local_3 > 0 && local_1[local_3] == local_1[local_3 - 1])
                                           ? B_80808560_chgameselect.rank
                                           : 4 - local_3;
        if (local_1[local_3] == local_1[0]) {
            local_0->unk24 = local_3 + 1;
        }
        if (param_5 && !param_0->unk64_19) {
            func_800AA220(local_2[local_3] - 1, B_80808560_chgameselect.rank);
        }
        func_80803E94_chgameselect(local_0->slot[local_3], 0x18F3,
                                   (((s32 *) &B_80808560_chgameselect)[param_2] == 1) ? param_4
                                                                                      : param_3,
                                   3, &B_80808560_chgameselect);
        _gczoombox_entrypoint_8(local_0->zoom[local_3], local_0->slot[local_3]);
        _gczoombox_entrypoint_27(local_0->zoom[local_3], D_808084FC_chgameselect);
    }
    if (param_5) {
        param_0->unk64_19 = 1;
    }
}

void func_808073AC_chgameselect(u8 *param_0)
{
    s32 sp3C;
    u8 *sp38;
    s32 sp34;

    sp3C = (*(s32 *) ((s8 *) (func_80106790((*(s32 *) ((s8 *) (param_0) + (0x3C))))) + (0x2C)));
    sp38 = func_80100094(param_0, 0);
    if (func_800AA0D0() == 1) {
        func_8080714C_chgameselect(param_0, &func_800AA180, 1, 0x1E, 0x1F, 0, 0);
    } else {
        func_8080714C_chgameselect(param_0, &func_800AA180, 2, 0x20, 0x21, 1, 0);
    }
    (*(s16 *) ((s8 *) (&B_80808570_chgameselect) + (0))) = 0x18E4;
    sp34 = func_800AA148();
    (*(s16 *) ((s8 *) (&B_80808570_chgameselect) + (2))) =
        (s16) (sp34 - _gcfrontend_entrypoint_5(3));
    (*(s16 *) ((s8 *) (&B_80808570_chgameselect) + (4))) = 0x18F3;
    (*(s16 *) ((s8 *) (&B_80808570_chgameselect) + (6))) = 0x14;
    func_80803F90_chgameselect((*(s32 *) ((s8 *) (sp38) + (0x20))), 2, &B_80808570_chgameselect);
    func_80802730_chgameselect(sp3C, (*(s32 *) ((s8 *) (sp38) + (0x20))));
    (*(u8 *) ((s8 *) (param_0) + (0x65))) = (u8) ((*(u8 *) ((s8 *) (param_0) + (0x65))) & 0xFFEF);
}

void func_808074C8_chgameselect(Actor *param_0)
{
    u32 local_1;
    u8 *local_0;

    local_1 = func_80106790(param_0->unk3C)->actorData[5];
    func_8080714C_chgameselect(param_0, func_800AA16C, 1, 0x1E, 0x1F, 0, 1);
    if (func_800AA240()) {
        func_80802640_chgameselect(local_1, 0x18F3, 0);
        func_808026C8_chgameselect(local_1, 0x16);
    } else {
        local_0 = func_80100094(param_0, 0);
        B_80808588_chgameselect[0] = func_800AA0C4() + 1;
        B_80808588_chgameselect[1] = func_800AA0D0();
        func_80803E94_chgameselect(*(s32 *) (local_0 + 0x20), 0x18F3, 0x15, 2,
                                   B_80808588_chgameselect);
        func_80802640_chgameselect(local_1, 0, 0);
        func_80802730_chgameselect(local_1, *(s32 *) (local_0 + 0x20));
    }
    param_0->unk64_20 = 1;
}

void func_808075D0_chgameselect(param_0, param_1) Actor *param_0;
s32 param_1;
{
    s32 *local_1;
    s32 *local_0;
    u32 local_2;
    local_0 = (s32 *) func_80100094(param_0, 0);
    switch (param_1) {
        case 5:
            if (func_800AA240() && !*(s16 *) ((u8 *) local_0 + 0x26)) {
                func_80803CA0_chgameselect();
                *(s16 *) ((u8 *) local_0 + 0x26) = 1;
            }
        case 2:
            param_0->unk58 = 7.5f;
            break;
        case 3:
            for (local_2 = 0; local_2 < param_0->unk6C_0; local_2++) {
                _gczoombox_entrypoint_17(local_0[local_2]);
                _gczoombox_entrypoint_12(local_0[local_2]);
            }
            if (param_0->unk70_10 == 2)
                func_808074C8_chgameselect(param_0);
            else if (param_0->unk70_10 == 5)
                func_808073AC_chgameselect(param_0);
            break;
        case 4:
            for (local_2 = 0; local_2 < param_0->unk6C_0; local_2++) {
                _gczoombox_entrypoint_18(local_0[local_2]);
                _gczoombox_entrypoint_11(local_0[local_2]);
            }
            break;
        case 6:
            for (local_2 = 0; local_2 < param_0->unk6C_0; local_2++)
                _gczoombox_entrypoint_34(local_0[local_2]);
    }
    func_80101FDC(param_0, param_1);
}

int func_80807790_chgameselect(s32 param_0, s32 param_1)
{
    s32 *local_1;
    u32 local_2;
    local_1 = func_80100094(param_0, 0);
    local_2 = 0;
    local_1 = local_1;
    if (((*((s32 *) (((char *) (param_0 ^ 0)) + 0x6C))) & 0x1FF) != 0) {
        do {
            if (_gczoombox_entrypoint_3(local_1[0]) != param_1) {
                return 0;
            }
            local_2++;
            local_1 += 1;
        } while (local_2 < ((*((s32 *) (((char *) param_0) + 0x6C))) & 0x1FF));
    }
    return 1;
}

void func_80807824_chgameselect(s32 param_0)
{
    s16 local_0;
    s32 *local_1;
    s32 *local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;

    local_1 = func_80100094(param_0, 0);
    local_3 = (func_8001211C() << 5) & 0x1FF;
    local_4 = local_3;
    if (local_3 >= 0x100) {
        local_4 = 0x200 - local_3;
    }
    local_0 = (local_4 / 2) + 0x7F;
    *(s16 *) ((char *) &B_80808590_chgameselect + 4) = local_0;
    *(s16 *) ((char *) &B_80808590_chgameselect + 2) = local_0;
    *(s16 *) ((char *) &B_80808590_chgameselect + 0) = local_0;
    local_5 = 0;
    local_2 = local_1;
    if (*(s16 *) ((char *) local_1 + 0x24) > 0) {
        do {
            _gczoombox_entrypoint_27(*local_2, &B_80808590_chgameselect);
            local_5 += 1;
            local_2 += 1;
        } while (local_5 < *(s16 *) ((char *) local_1 + 0x24));
    }
}

int chgameselect_entrypoint_7()
{
    return D_80808504_chgameselect;
}

void func_808078F0_chgameselect(void *param_0)
{
    *(u16 *) ((u8 *) param_0 + 0x6E) &= 0xFE00;
}

void func_80807900_chgameselect(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];

    if (param_0->unk70_10 == 2) {
        *(f32 *) &param_0->actorData[7] += *(f32 *) &param_0->actorData[3] * func_800D8FF8();
        if (*(f32 *) &param_0->actorData[7] >= 1.0f) {
            *(f32 *) &param_0->actorData[7] = 1.0f;
            func_80101FDC(param_0, 1);
        }
        func_800EFE50(local_0, param_0->position, (f32 *) &param_0->actorData[0],
                      *(f32 *) &param_0->actorData[7]);
        func_800F16AC(local_1, param_0->rotation, (f32 *) &param_0->actorData[4],
                      *(f32 *) &param_0->actorData[7]);
        func_800E39D8(local_0, local_1);
        func_80101180(0x4AB, 0x23, 0);
    }
}

void func_808079C8_chgameselect(s32 arg0)
{
}

s32 func_808079D0_chgameselect(s32 param_0, s32 param_1, S16Pair param_2)
{
    if (param_1 == 0x21) {
        func_80807A10_chgameselect(param_0, param_2.b, param_2.a);
    } else {
        return 0;
    }
    return 1;
}

void func_80807A10_chgameselect(param_0, param_1, param_2) Actor *param_0;
s32 param_1;
s32 param_2;
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    func_800E39A8(param_0->position, param_0->rotation);
    func_800A5800(param_1);
    _cadbfunc_entrypoint_0(&OD(0));
    _cadbfunc_entrypoint_2(&OD(4));
    local_0 = func_800EEAD4(param_0->position, &OD(0));
    switch (param_2) {
        case 0:
            OD(7) = 1.0f;
            param_0->unk6C_0 = param_1;
            param_0->unk64_20 = 0;
            OD(3) = 1;
            break;
        case 1:
            OD(7) = 0.0f;
            param_0->unk6C_0 = param_1;
            param_0->unk64_20 = 0;
            OD(3) = 1.0f;
            break;
        case 2:
            func_800A5800(param_0->unk6C_0);
            _cadbfunc_entrypoint_0(local_1);
            _cadbfunc_entrypoint_2(local_2);
            func_800EFE50(&OD(0), local_1, &OD(0), 0.3f);
            func_800F16AC(&OD(4), local_2, &OD(4), 0.3f);
            OD(7) = 0.0f;
            if (param_0->unk64_20) {
                local_0 = func_800EEAD4(param_0->position, &OD(0));
                OD(3) = 320.0f / local_0;
            } else {
                OD(3) = 1.6666666f;
            }
            param_0->unk64_20 = 1;
            break;
        case 3:
            OD(7) = 0.0f;
            param_0->unk6C_0 = param_1;
            OD(3) = 1.6666666f;
            param_0->unk64_20 = 0;
    }
    if (local_0 < 0.01f) {
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
