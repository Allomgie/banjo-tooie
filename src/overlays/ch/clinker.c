#include "common.h"

extern int D_808014D4_chclinker[];
typedef struct {
    u8 pad_0[8];
    Unk80132ED0 *actors[2];
    f32 dists[2];
    s32 count;
} ClinkerClosestActors;
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 *func_80100094();
extern s32 func_8010C710(Actor *);
extern u32 func_800F54E4(void);
extern int D_80801550_chclinker[];
extern void *D_80801598_chclinker;
extern s32 D_80801408_chclinker[];
extern s32 D_80801418_chclinker[];
extern s32 D_80801444_chclinker[];
extern s32 D_8080148C_chclinker[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern s32 func_800BABB8(s32, f32 *, s32, f32, s32 *);
typedef struct {
    u8 pad0[0xC];
    u32 unkC_23 : 9;
    u32 unkC_0 : 23;
} ClinkerCube;
extern s32 _gccubesearch_entrypoint_9(s32, ClinkerCube **, s32);
extern Actor *func_801085CC(s32, ClinkerCube *, u32);
typedef struct {
    u8 pad_0[8];
    Unk80132ED0 *markers[4];
    s32 count;
} ClinkerMarkers29;
extern u8 D_8080154C_chclinker[];
extern u8 D_8080151C_chclinker[];
extern u8 D_80801534_chclinker[];
extern s32 func_80101E14(Actor *, f32);
extern void func_8010D930(s32, s32, f32 *, void *);
extern f32 func_800D8FF8(void);
extern f32 func_800F13F0(f32, f32);
typedef struct {
    s32 targets;
    f32 time;
} ClinkerData88;
extern void func_800CE8D8(s32, f32, s32);
typedef struct {
    s32 unk0;
} ClinkerLocal;
typedef union {
    s32 w;
    struct {
        s16 a;
        s16 b;
    } h;
} ClinkerArg;
extern s32 func_800D395C(void);
extern s32 func_800D0A9C(s32, s32);
extern void func_800FC63C(s32, s32);
extern Unk80132ED0 **func_801084B0(s32, Actor **);
extern s32 _bsfirstp_entrypoint_18;
extern s32 _glcutDll_entrypoint_19(s32);
extern void _capod_entrypoint_13(void *, s32, s32, s32);
extern void func_80101FDC(Actor *, s32);
extern s32 func_800EA090(void);
extern s32 func_800C6E38(s32);
extern s32 func_800F5410(s32);
extern s32 func_800DA9E4(s32, s32);
extern void func_800F49D4(s32, s32 *, s32);
void func_80800304_chclinker();
void func_808003A8_chclinker();
void func_808005BC_chclinker();
void func_808000F4_chclinker();
void func_808008E0_chclinker();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_808007BC_chclinker(),
    func_808008C0_chclinker();

void func_80800000_chclinker(s32 param_0)
{
    u8 *data;
    s32 unk_0;
    s32 unk_1;

    data = func_80100094(param_0, 0);
    func_808003A8_chclinker(param_0);
    unk_0 = func_800D395C();
    unk_1 = func_800D0A9C(0x35, 1) == 0;
    if ((unk_0 != 0) || (unk_1 != 0)) {
        *(s32 *) ((s8 *) data + 4) = 1;
        return;
    }
    *(s32 *) ((s8 *) data + 4) = 0;
    func_8010A570(param_0);
    func_80103110(param_0, 0);
}

int func_80800088_chclinker(Actor *param_0)
{
    s32 data;
    data = func_80100094(param_0, 0);
    switch ((*(u16 *) (0x72 + (char *) param_0) & 0xFFFFFFFF) >> 10) {
        case 1:
            func_808005BC_chclinker(*(Actor **) ((char *) data + 0x0), param_0);
            break;

        case 2:
            func_808000F4_chclinker(param_0);
    }
}

void func_808000F4_chclinker(param_0) Actor *param_0;
{
    u8 *data;
    s32 emitter;
    data = func_80100094(param_0, 0);
    switch (*(s32 *) (data + 8)) {
        case 0:
            func_800C4AF0(param_0->position, &D_80801408_chclinker);
            func_800BBCB8(param_0->position, 0, 1.0f, 1, &D_80801418_chclinker);
            emitter = func_800BABB8(0, param_0->position, 0, 1.0f, &D_80801444_chclinker);
            func_800BA994(emitter, -30, (s16) (s32) (param_0->rotation[1] - 45.0f), 450, 30,
                          (s32) (param_0->rotation[1] + 45.0f), 600);
            func_800BA22C(emitter, 8);
            emitter = func_800BABB8(0, param_0->position, 0, 1.0f, &D_8080148C_chclinker);
            func_800BA994(emitter, -30, (s16) (s32) (param_0->rotation[1] - 45.0f), 100, 30,
                          (s32) (param_0->rotation[1] + 45.0f), 200);
            func_800BA22C(emitter, 4);
            param_0->unk58 = 0.1f;
            *(s32 *) (data + 8) = 1;
            break;
        case 1:
            if (func_800D9078(&param_0->unk58)) {
                *(s32 *) (data + 4) = 0;
                func_80103110(param_0, 0);
            }
            break;
    }
}

int func_808002B0_chclinker(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x40) {
        func_80101180(0x2BF, 0x4F, 0);
        func_80800304_chclinker(param_0, 2);
    } else {
        return 0;
    }
    return 1;
}

void func_80800304_chclinker(param_0, param_1) Actor *param_0;
s32 param_1;
{
    s32 *data;

    data = func_80100094(param_0, 0);
    if (param_1 == 2) {
        func_8010A570(param_0);
        _subaddieDll_entrypoint_4(param_0, 1);
        data[2] = 0;
    }
    func_80101FDC(param_0, param_1);
}

s32 func_80800368_chclinker(s32 param_0, s32 param_1)
{
    s32 data;
    data = func_80100094(param_0, 0);
    func_800DF744(3, *(s32 **) (data + 4));
    func_80101870(param_0, param_1);
}

void func_808003A8_chclinker(param_0) Actor *param_0;
{
    f32 start[3];
    f32 end[3];
    f32 hit[3];

    func_800EE7F8(start, ((char *) param_0 + 4));
    func_800EF1B8(start, (*(s32 *) ((char *) (param_0) + 0x48)), 0x42C80000);
    func_800EE7F8(end, ((char *) param_0 + 4));
    func_800EF1B8(end, (*(s32 *) ((char *) (param_0) + 0x48)), 0xC3480000);

if (func_800BEF00(start, end, hit, *(s32 *) ((char *) param_0 + 0x14)) != 0) {
    func_800EE7F8(((char *) param_0 + 4), end);
    func_800EF1B8(((char *) param_0 + 4), *(s32 *) ((char *) param_0 + 0x48), 0x40A00000);
    func_80103014(param_0);
    _subaddiezone_entrypoint_0(param_0);
}

}

int chclinker_entrypoint_0()
{
    return (int) &D_808014D4_chclinker;
}

s32 func_8080045C_chclinker(s32 **param_0)
{
    s32 owner;
    s32 count;
    ClinkerCube *cubes[40];
    s32 i;
    Actor *target;
    Actor *controller;
    s32 result;
    // Spawns one target actor per cube found.

    controller = (Actor *) *param_0;
    owner = *(s32 *) controller;
    count = _gccubesearch_entrypoint_9(0x2BA, cubes, 40);
    for (i = 0; i < count; i++) {
        target = func_801085CC(0x2C1, cubes[i], cubes[i]->unkC_23);
        target->scale = cubes[i]->unkC_0 * 0.01f;
        func_80100094(target, 0)[0] = owner;
    }
    controller = func_80106790(owner);
    func_80100094(controller, 0)[0] = count;
    *param_0 = (s32 *) controller;
    if (count != 0) {
        result = 1;
    } else {
        result = 0;

}
return result;
}

s32 func_80800574_chclinker(param_0) void *param_0;
{
    _susubgame_entrypoint_11(0);
}

void func_80800598_chclinker(s32 param_0)
{
    s32 *data = func_80100094(param_0, 0);
    data[6] = 0;
}

// Keeps the two closest actors, sorted by distance.
void func_808005BC_chclinker(param_0, param_1) Unk80132ED0 *param_0;
Actor *param_1;
{
    s32 dist;
    ClinkerClosestActors *list;
    s32 slot;
    s32 i;

    list = func_80100094(func_80106790(param_0), 0);
    dist = func_8010C710(param_1);
    slot = 0;
    for (i = 0; i < list->count; i++) {
        if (list->dists[i] < (f32) dist) {
            slot = i + 1;
        }

}
switch (slot) {
    case 0:
        list->actors[1] = list->actors[0];
        list->dists[1] = list->dists[0];
    case 1:
        list->actors[slot] = param_1->unk0;
        list->dists[slot] = dist;
        list->count++;

if (list->count >= 3) {
    list->count = 2;
}

}
}

void func_808006A4_chclinker(Actor *param_0)
{
    ClinkerMarkers29 *data;
    Actor *marker;
    s32 i;
    data = func_80100094(param_0, 0);
    for (i = 0; i < data->count; i++) {
        marker = func_80106790(data->markers[i]);
        if (func_80101E14(marker, 0.25f))
            func_8010D930(D_8080154C_chclinker[i], 0, marker->position,
                          D_8080151C_chclinker);
        if (func_80101E14(marker, 0.8f))
            func_8010D930(D_8080154C_chclinker[i], 0, marker->position,
                          D_80801534_chclinker);
    }
    data->count = 0;
}

void func_808007BC_chclinker(param_0) Actor *param_0;
{
    u8 *data;

    data = func_80100094(param_0, 0);
    func_808006A4_chclinker(param_0);
    switch ((s32) param_0->unk70_10) {
        case 2:
            func_800D24E8(0x103, *(s32 *) data, 0);

if (func_800CEAD0(0)) {
    func_808008E0_chclinker(param_0, 3);
}

break;
case 3:
    func_800D24E8(0x103, *(s32 *) data, 0);
    break;
case 6:
    *(f32 *) (data + 4) = func_800F13F0(*(f32 *) (data + 4) + func_800D8FF8(), 999.0f);
    func_800D24E8(0x103, *(s32 *) data, 0);
    func_800D2498(0xCC, (s32) *(f32 *) (data + 4), 0);
case 7:
    break;

}
}

void func_808008C0_chclinker(s32 arg0)
{
    func_808008E0_chclinker(arg0, 0x5);
}

s32 func_80800BDC_chclinker();

void func_808008E0_chclinker(param_0, param_1) Actor *param_0;
s32 param_1;
{
    ClinkerData88 *data;
    s32 player;
    s32 unk_0;
    s32 unk_1;
    s32 dialog_id;

    data = func_80100094(param_0, 0);
    if (param_1 != param_0->unk70_10) {
        switch (param_1) {
            case 2:
                _gcfrontend_entrypoint_9(0x6C);
                func_800D2498(0x103, data->targets, 0);
                func_800CE8D8(0, (f32) param_0->unk74_7, param_0->unk74_7);
                func_800CE88C(0, 1);
                break;
            case 4:
                func_800FC63C(0x10, -1);
                func_80800BDC_chclinker(param_0, 0x1372);
                if (func_800CEAA8(0)) {
                    func_800CE88C(0, 0);
                }
                if (param_0->unk3C) {
                    func_8010114C(param_0->unk3C, 0x4F, 0);
                    param_0->unk3C = NULL;
                }
                break;
            case 5:
                func_800D284C(0x103);
                if (func_800D395C()) {
                    func_800D284C(0xCC);
                } else {
                    if (func_800CEAA8(0)) {
                        func_800CE88C(0, 0);
                    }
                    func_800D284C(0xCC);
                }
                break;
            case 3:
                func_80108B04(param_0, 0);
                func_80800BDC_chclinker(param_0, 0x1371);
                break;
            case 9:
                player = func_800F54E4();
                func_800F49D4(player, 0, 0);
                func_800F7B9C(player, 0x8F);
                func_800F7B9C(player, 0x62);
                func_800F7C58(player, 0x61, 0);
                func_80800BDC_chclinker(param_0, func_800D211C(0x94) ? 0x137C : 0xCEC);
                func_800F7F98(func_800F54E4(), 1);
                break;
            case 6:
                data->time = 0.0f;
                func_800D2498(0x103, data->targets, 0);
                func_800D2498(0xCC, (s32) data->time, 0);
                break;
            case 7:
                switch (func_800D2054(1, 0x94, (s32) data->time)) {
                    case -1:
                        dialog_id = 0x137F;
                        break;
                    case 0:
                        dialog_id = 0x137E;
                        break;
                    case 1:
                        dialog_id = 0x137D;
                }
                func_800FC63C(0x10, -1);
                func_80800BDC_chclinker(param_0, dialog_id);
                break;
            case 8:
                func_80800BDC_chclinker(param_0, 0xCEB);
        }

func_80101FDC(param_0, param_1);
}
}

s32 func_80800BDC_chclinker(Actor *param_0, s32 param_1)
{
    s32 unk_0;

    switch (param_1) {
        case 0x1372:
        default:
            unk_0 = 0x22;
            func_800F7F98(func_800F54E4(), 1);
            break;
        case 0x1371:
            unk_0 = 0x23;
            break;
        case 0x1373:
            unk_0 = 7;
            break;
        case 0xCEC:
        case 0x137C:
            unk_0 = 0x23;
            break;
        case 0xCEB:
            unk_0 = 0x144;
    }
    _chmrtannoy_entrypoint_0();
    _subaddiedialog_entrypoint_11(param_0->unk0, param_1, unk_0, param_0->position, 0xA3);
    return 1;
}

int func_80800C9C_chclinker(s32 param_0, s32 param_1, s32 param_2)
{
    f32 *data;
    data = func_80100094(param_0, 0, param_1 | 0);
    switch (param_1) {
        case 0x137C:
            func_800D211C(0x94);
            break;

        case 0x137D:
        case 0x137E:
        case 0x137F:
            return data[1];

        default:
            return 0;
    }
}

void func_80800D24_chclinker(s32 param_0, s32 param_1, s32 param_2)
{
    s32 dialog_id;

    dialog_id = func_800C064C();
    switch (dialog_id) {
        case 0x1371:
            break;
        case 0x1372:
            _glcutDll_entrypoint_6(0x187, 0x87);
            return;
        case 0x137C:
            func_80800BDC_chclinker(param_0, 0xCEC);
            return;
        case 0xCEC:
            func_800F7F98(func_800F54E4(), 0);
            func_808008E0_chclinker(param_0, 6);
            return;
        case 0x137D:;
        case 0x137E:
        case 0x137F:
            func_808008E0_chclinker(param_0, 8);
            return;

case 0xCEB:
    if (param_2 > 0) {
        _gcfrontend_entrypoint_11();
        return;
    }

_gcfrontend_entrypoint_10();

}
}

s32 func_80800E1C_chclinker(Actor *this, s32 msg, ClinkerArg arg)
{
    ClinkerLocal *data;

    data = func_80100094(this, 0);
    switch (msg) {
        case 0x49:
            if (func_8080045C_chclinker(&this)) {
                data = func_80100094(this, 0);
                func_80800598_chclinker(this);
                if (func_800D395C()) {
                    func_808008E0_chclinker(this, 9);
                } else if (!func_800D0A9C(0x35, 1)) {
                    func_808008E0_chclinker(this, 2);
                }
            }

break;

case 0x4F:
    if (--data->unk0 != 0) {
        func_800FC63C(0xE, -1);
    } else {

func_808008E0_chclinker(this, func_800D395C() ? 7 : 4);
}
break;
case 0x3D:
    this->unk3C = *func_801084B0(0x178, &this);
    break;
case 0x30:
    return func_80800C9C_chclinker(this, arg.h.a, arg.h.b);
case 0x2E:
    func_80800D24_chclinker(this, arg.h.a, arg.h.b);
    break;
case 0x9F:
    func_808008E0_chclinker(this, 5);
    break;
case 0x96:
    if (!func_800D395C()) {
        return 0;
    }
    func_808008E0_chclinker(this, 8);
    break;
default:
    return 0;
    }
    return 1;
    }

    int *chclinker_entrypoint_1()
    {
        return &D_80801550_chclinker;
    }

    void func_80800FFC_chclinker(s32 arg0)
    {
    }
    void func_80801004_chclinker(s32 arg0)
    {
    }
    void func_8080100C_chclinker(param_0, param_1) Actor *param_0;
    s32 param_1;
    {
        if (_glcutDll_entrypoint_19(0x87)) {
            _capod_entrypoint_13((*(Actor **) &param_0)->unk0, 0, 1, 0x900);
            func_80101FDC((*(Actor **) &param_0), 3);
            *(f32 *) ((u8 *) (*(Actor **) &param_0) + 0x58) = 0.15f;
            return;
        }
        switch (func_800EA090()) {
            case 1:
                if (func_800C6E38(0x15) && func_800F5410(0) == 1 && !func_800DA9E4(0x6BA, 1)) {
                    func_80101FDC((*(Actor **) &param_0), 2);
                    _capod_entrypoint_13((*(Actor **) &param_0)->unk0, 0, 5, 0x2020);
                    func_800F49D4(func_800F54E4(), &_bsfirstp_entrypoint_18, 0);
                }
                break;
            case 2:
                func_80101FDC((*(Actor **) &param_0), 4);
                _capod_entrypoint_13((*(Actor **) &param_0)->unk0, 0, 3, 0x2000);
        }
    }

    void func_8080112C_chclinker(u8 *param_0)
    {
        u32 temp_t6;

        temp_t6 = (u16) (*(u16 *) ((s8 *) param_0 + 0x72));
        temp_t6 >>= 0xA;
        switch (temp_t6) {
            case 3:
                if (func_800D9078(param_0 + 0x58, param_0) != 0) {
                    func_800D1000(0x35, 1, 0, 1, 0);
                    func_80101FDC(param_0, 1);
                }
            case 2:;
            case 4:
                return;
        }
    }

    s32 func_808011A8_chclinker(Actor *param_0, s32 param_1, s32 param_2)
    {
        switch (param_1) {
            case 0x49:
                func_8080100C_chclinker(param_0, param_2);
                return 1;
            case 0xB:
                if (param_0->unk70_10 == 4) {
                    func_800F7F98(func_800F54E4(), 0);
                    func_800F7B9C(func_800F54E4(), 0x73);
                    func_80101FDC(param_0, 1);

if (!func_800D0A9C(0x35, 1)) {
    func_80800BDC_chclinker(param_0, 0x1373);
}

}
return 3;
case 0x2E:
    func_800F7F98(func_800F54E4(), 0);
    return 1;
case 0x77:
    if (param_0->unk70_10 == 2) {
        func_800F7B9C(param_2, 0x73);
        func_80101FDC(param_0, 1);
        _capod_entrypoint_14();
        func_800F7B9C(func_800F54E4(), 0x99);
        return 1;
    }
    }
    return 0;
    }

    int chclinker_entrypoint_2(void)
    {
        return (int) &D_80801598_chclinker;
    }

    extern void func_80108ED0();
    u32 D_808013F0_chclinker[6] = {0x0, 0x0, 0x3FA66666, 0x31B0000, 0x3FA66666, 0x31B0000};
    s32 D_80801408_chclinker[4] = {0x13063D, 0x1012C, 0x7D00016, 0x6D600000};
    s32 D_80801418_chclinker[11] = {0x1D09C9, 0x1F8040,  0x18,      0x0,      0xF000F00, 0x160010,
                                    0x2501C0, 0x1C0002B, 0x1330135, 0x150000, 0x660000};
    s32 D_80801444_chclinker[18] = {0x810001D, 0x84E0001, 0xFF6A,    0x0,       -0x12C0000,
                                    0xB0001,   0x1001E,   -0x1DFFEA, 0x4000027, -0x1F301F4,
                                    0x1F401F4, 0x240100,  0x2000015, 0xC2,      0x2B00C2,
                                    0x1400004, 0x660007,  0x20000};
    s32 D_8080148C_chclinker[18] = {0x410001D, 0x84E0001, 0xFF38,    0x0,       -0x1900000,
                                    0xB0001,   0x1001E,   -0x1DFFEA, 0x4000027, -0xF900FA,
                                    0xFA00FA,  0x240080,  0xC00015,  0xC2,      0x2B0100,
                                    0x1820004, 0x660007,  0x20000};
    int D_808014D4_chclinker[18] = {0x16C02C1,
                                    0x84D0001,
                                    (u32) &D_808013F0_chclinker,
                                    (u32) func_80800088_chclinker,
                                    (u32) func_80105834,
                                    (u32) func_80800368_chclinker,
                                    0x5DC0000,
                                    0x0,
                                    0x0,
                                    0x100,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0xC0000,
                                    (u32) func_80800000_chclinker,
                                    (u32) func_80107C2C,
                                    -0x7FFFDC00,
                                    (u32) func_808002B0_chclinker,
                                    0x0};
    u8 D_8080151C_chclinker[24] = {0x0, 0x13, 0x6,  0x7B, 0x0, 0x1,  0x1, 0x2C,
                                   0x3, 0xE8, 0x0,  0xD,  0x0, 0xF3, 0x1, 0xC,
                                   0x0, 0x16, 0x4E, 0x20, 0x0, 0x0,  0x0, 0x0};
    u8 D_80801534_chclinker[24] = {0x0, 0x13, 0x6,  0x7C, 0x0, 0x1,  0x1, 0x2C,
                                   0x3, 0xE8, 0x0,  0xD,  0x0, 0xF3, 0x1, 0xC,
                                   0x0, 0x16, 0x4E, 0x20, 0x0, 0x0,  0x0, 0x0};
    u8 D_8080154C_chclinker[4] = {0x4, 0x5, 0x0, 0x0};
    int D_80801550_chclinker[18] = {0x15802BF,
                                    0x1,
                                    0x0,
                                    (u32) func_808007BC_chclinker,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_808008C0_chclinker,
                                    0x0,
                                    0x1C0000,
                                    (u32) func_80800574_chclinker,
                                    (u32) func_80107C2C,
                                    -0x7FFFF9FE,
                                    (u32) func_80800E1C_chclinker,
                                    0x0};
    void *D_80801598_chclinker = (void *) 0x015802C0;
    static u32 D_80801598_chclinker_rest[17] = {0x1,
                                                0x0,
                                                (u32) func_8080112C_chclinker,
                                                (u32) func_80105834,
                                                (u32) func_80101870,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) func_80801004_chclinker,
                                                0x0,
                                                0x0,
                                                (u32) func_80800FFC_chclinker,
                                                (u32) func_80107C2C,
                                                0x80000202,
                                                (u32) func_808011A8_chclinker,
                                                0x0};
