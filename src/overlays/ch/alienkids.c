#include "ch/alienkids.h"

#define ACTOR_CALLBACK_DATA_DEFINED
extern int D_808020DC_chalienkids;
extern int D_80802124_chalienkids;
extern void *D_8080216C_chalienkids;
extern s32 D_808021B4_chalienkids[];
extern void func_80102424(Actor *, s32);
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern s32 func_800DA298(s32);
extern s32 func_800D9078(f32 *);
extern s32 func_800F54E4(void);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void *func_80100094(Actor *, s32);
extern void _capod_entrypoint_14(void);
extern void func_80101180(s32, s32, s32);
extern void func_80103110(Actor *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern Actor *func_80106790(Unk80132ED0 *);
extern Unk80132ED0 *func_80101080(void);
extern u8 unk2C[];
extern u8 unk72[];
extern void func_80101870(Actor *, void *);
extern void func_8010A764(Actor *, s32);
extern u8 D_80801E60_chalienkids[];
extern u8 D_80801E80_chalienkids[];
extern u8 D_80801E98_chalienkids[];
extern u8 D_80801EA8_chalienkids[];
extern u8 D_80802234_chalienkids[];
typedef struct { u32 pad : 15; u32 flag : 1; u32 pad2 : 16; } BitTest15;
typedef struct { u8 pad_0[0x1C]; f32 local_0[4]; } AlienRingState331;
extern u8 D_8080223C_chalienkids[];
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_80103EF4(Actor *);
extern f32 func_80103EAC(Actor *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern f32 func_800136E4(f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef struct { u8 pad_0[0x74]; u32 pad_1 : 26; u32 local_0 : 1; u32 pad_2 : 5; } AlienKidFlags;
extern f32 func_8010A40C(Actor *);
extern void func_8008FB58(f32 *, f32, f32);
extern s32 D_80802260_chalienkids;
extern f32 func_80800D68_chalienkids[];
extern u8 D_8080226C_chalienkids[];
extern s32 _subaddiedialog_entrypoint_8(Actor *, f32 *, void *, void *, s32);
typedef struct { u8 pad_0[0x30]; Unk80132ED0 *local_0; } AlienKidAttachment;
extern u8 D_8080227C_chalienkids[];
extern void func_80109F08(void *param_0, int param_1);
typedef union { s32 word; void *pointer; } ActorCallbackData;
extern s32 _subaddieDll_entrypoint_5(Actor *, void *);
extern void func_80101FDC(Actor *, s32);
extern u8 D_80802284_chalienkids[];
extern int func_80101E14(Actor *, f32);
extern u8 D_808021FC_chalienkids[];
extern s32 _plsu_entrypoint_3(Unk80132ED0 *);
extern void func_800F7BC8(s32, s32, Unk80132ED0 *);
extern void func_800F82D4(s32, s32);
extern void func_8010A624(Actor *);
extern Actor *func_801084B0(s32, Actor **);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 _chlifeforcespell_entrypoint_1(Actor **, f32 *, s32, f32, s32);
extern s32 _gcdialogcamera_entrypoint_3(f32 *, f32);
typedef struct { u8 pad[0x30]; Unk80132ED0 *marker; } AlienKidLink;
extern void _chbadshad_entrypoint_2(Actor *, s32, f32, s32);
void func_80800D58_chalienkids();
void func_80800FA4_chalienkids();
void func_80801BC4_chalienkids();
void func_80801628_chalienkids();
void func_808019C8_chalienkids();

int *chalienkids_entrypoint_0()
{
    return &D_808020DC_chalienkids;
}

int *chalienkids_entrypoint_1()
{
    return &D_80802124_chalienkids;
}

void *chalienkids_entrypoint_2(void)
{
    return &D_8080216C_chalienkids;
}

int chalienkids_entrypoint_3()
{
  return D_808021B4_chalienkids;
}

int func_80800030_chalienkids(int param_0)
{
  int new_var;
  func_80800FA4_chalienkids(param_0, 0x32, 0x372, 4);
  new_var = 0;
}

void func_80801884_chalienkids();

void func_8080184C_chalienkids();

void func_808016D4_chalienkids();

void func_8080158C_chalienkids();

void func_80800058_chalienkids(Actor *param_0)
{
    func_808019C8_chalienkids((u8 *)param_0);
    switch (param_0->unk70_10) {
    case 2:
        func_80801884_chalienkids(param_0);
        break;
    case 3:
        if (func_80801158_chalienkids(param_0, 0x9E5)) {
            func_80102424(param_0, 4);
            _subaddieDll_entrypoint_4(param_0, 0);
        }
        break;
    case 5:
        if (func_80101DDC(param_0)) {
            _subaddieskeleton_entrypoint_2(param_0->unk0, 4, param_0->position);
            func_80102424(param_0, 14);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1284, 6, param_0->position, 0xB7);
        }
        break;
    case 15:
        func_8010B990(param_0, 0x1005);
        break;
    case 16:
        func_8080184C_chalienkids(param_0, D_80801E60_chalienkids, 4);
        break;
    }
    func_808016D4_chalienkids(param_0);
    func_8080158C_chalienkids(param_0);
    func_80801628_chalienkids(param_0);
}

int func_8080017C_chalienkids(Actor *param_0)
{
  func_80800FA4_chalienkids(param_0, 0x33, 0x373, 6);
  if (!func_800DA298(0x373) && !_glcutDll_entrypoint_20())
  {
    func_8010A85C(param_0, 2);
  }
}

void func_808001D0_chalienkids(Actor *param_0)
{

    s32 local_1;

    func_808019C8_chalienkids((u8 *)param_0);
    switch (param_0->unk70_10) {
    case 2:
        func_80801884_chalienkids(param_0);
        break;
    case 3:
        if (func_80801158_chalienkids(param_0, 0x9E5)) {
            func_80102424(param_0, 6);
            _subaddieDll_entrypoint_4(param_0, 0);
        }
        break;
    case 7:
        if (func_800D9078(&param_0->unk58)) {
            func_80102424(param_0, 8);
            ((u8 *)param_0)[0x77] &= ~0x20;
        }
        break;
    case 8:
        if (func_80101E14(param_0, 0.4f)) {
            func_8010A85C(param_0, 1);
        }
        if (func_80101DDC(param_0)) {
            _subaddieskeleton_entrypoint_2(param_0->unk0, 4, param_0->position);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1285, 4, param_0->position, 0xB7);
            func_80102424(param_0, 0xE);
        }
        break;
    case 15:
        local_1 = 5;
        if (param_0->unk6C_0) {
            param_0->unk6C_0--;
        } else {
            local_1 = 0x1005;
        }
        func_8010B990(param_0, local_1);
        break;
    case 16:
        func_8080184C_chalienkids(param_0, &D_80801E80_chalienkids, 3);
        break;
    }
    func_808016D4_chalienkids(param_0);
    func_8080158C_chalienkids(param_0);
    func_80801628_chalienkids(param_0);
}

int func_80800370_chalienkids(s32 param_0, s32 param_1)
{
  Actor *local_0;
  f32 local_2[3];
  f32 local_1[3];
  local_0 = func_80100094(param_0, 0);
  if ((*(s32 *)((char *)(local_0) + 0x2C)) != 0)
  {
    _subaddiefade_entrypoint_9(param_0, local_1);
    _chlifeforcespell_entrypoint_2(param_0, (*(s32 *)((char *)(local_0) + 0x2C)), local_2);
    _subaddiefade_entrypoint_11(param_0, local_2);
    func_80800D58_chalienkids(param_0, param_1);
    _subaddiefade_entrypoint_11(param_0, local_1);
  }
  else
  {
    func_80800D58_chalienkids(param_0, param_1);
  }
}

void func_80800408_chalienkids(Actor *param_0)
{
    func_80800FA4_chalienkids(param_0, 0x34, 0x374, 9);
    if (((u32)((u16)(*(u16 *)((char *)(param_0) + 0x72))) >> 0xA) == 9) {
        func_8010A63C(param_0);
    }
}

void func_80801520_chalienkids();

void func_80800454_chalienkids(Actor *this)
{
    s32 v;

    func_808019C8_chalienkids(this);
    switch (this->unk70_10) {
    case 2:
        func_80801884_chalienkids(this);
        break;
    case 3:
        if (func_80801158_chalienkids(this, 0x9E5)) {
            func_80102424(this, 9);
            _subaddieDll_entrypoint_4(this, 0);
        }
        break;
    case 9:
        if (!_subaddiedialog_entrypoint_8(this, this->position, D_808021FC_chalienkids, D_80801E98_chalienkids, 2)) {
            v = _plsu_entrypoint_3(this->unk0);
            if (v != -1 && func_800DA298(0x371)) {
                func_800F7BC8(v, 0x53, this->unk0);
            }
        }
        break;
    case 0xB:
        if (func_800D9078(&this->unk58)) {
            func_800F82D4(func_800F54E4(), 0);
            func_80102424(this, 0xE);
            _subaddiedialog_entrypoint_11(this->unk0, 0x1286, 6, this->position, 0xB7);
            func_8010A624(this);
        }
        break;
    case 0xC:
        if (func_80801158_chalienkids(this, 0x9E6)) {
            func_80801520_chalienkids(this, 0x374);
        }
        break;
    case 0xD:
        if (func_80801158_chalienkids(this, 0x9E6)) {
            _capod_entrypoint_14();
            _subaddieDll_entrypoint_4(this, 0);
            func_80102424(this, 0x10);
            func_80101180(0x45A, 0x31, this->unk6C_9);
        }
        break;
    case 0x10:
        func_8080184C_chalienkids(this, D_80801EA8_chalienkids, 3);
        break;
    }
    func_808016D4_chalienkids(this);
    func_8080158C_chalienkids(this);
}

s32 func_8080193C_chalienkids();

void func_808014B0_chalienkids();

void func_80800DB8_chalienkids();

s32 func_80800648_chalienkids(Actor *param_0, s32 param_1, s32 param_2)
{
    extern Vec3f D_8080220C_chalienkids;
    extern Vec3f D_80802218_chalienkids;
    extern f32 D_80802224_chalienkids[];
    char *local_0;
    Actor *local_1;
    f32 local_2[3];
    Actor *local_3;
    Vec3f local_4;
    Vec3f local_5;
    f32 local_6[3];
    s16 *local_7;
    s32 local_8;
    char *local_9;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x3D:
            switch (param_2) {
                case 0:
                case 1:
                    local_1 = func_801084B0(0x459, &param_0);
                    *(s32 *)(local_0 + 0x30) = (s32)local_1->unk0;
                    local_1->unk3C = param_0->unk0;
                    *(f32 *)((char *)local_1 + 0x48) = 0.0f;
                    *(s32 *)&local_1->unk50 = param_2 == 1 ? 0x6B4 : 0;
                    if (!func_800DA298(0x376)) {
                        func_8010A570(local_1);
                    } else {
                        *((u8 *)local_1 + 0x65) &= ~1;
                    }
                    break;
                case 2:
                    func_800EE7F8(local_2, param_0->position);
                    local_2[1] -= 120.0f;
                    *(s32 *)(local_0 + 0x2C) = _chlifeforcespell_entrypoint_1(&param_0, local_2, 100, 4.0f, 0x12);
                    break;
                case 3:
                    local_3 = func_80108528(0x466, param_0->position, 0, &param_0);
                    param_0->unk3C = local_3->unk0;
                    break;
            }
            break;
        case 0x0A:
            local_8 = param_0->unk6C_9;
            if (local_8 == 0x456) {
                    local_4 = D_8080220C_chalienkids;
                    func_800F77E8(func_800F54E4(), &local_4);
                    func_80102424(param_0, 5);
                    *((u8 *)param_0 + 0x77) &= ~0x20;
                    _capod_entrypoint_13(param_0->unk0, 0, 0x60, 0x30);
            } else if (local_8 == 0x457) {
                    local_5 = D_80802218_chalienkids;
                    func_800F77E8(func_800F54E4(), &local_5);
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x12CE, 6, param_0->position, 0xB7);
                    _capod_entrypoint_13(param_0->unk0, 0, 0x5D, 0x30);
            }
            *(s32 *)(local_0 + 0x30) = 0;
            break;
        case 0x18:
            func_800EE7F8(local_6, param_0->position);
            func_800EF1B8(local_6, param_0->rotation[1] + 40.0f, 150.0f);
            func_800F77E8(func_800F54E4(), local_6);
            func_800F8300(func_800F54E4(), 2, param_0->position);
            _capod_entrypoint_13(param_0->unk0, 0, 0x65, 0x30);
            func_80102424(param_0, 0xB);
            param_0->unk58 = 2.0f;
            break;
        case 0x2E:
            local_7 = (s16 *)&param_2;
            func_80800DB8_chalienkids(param_0, local_7[0], local_7[1]);
            break;
        case 0x0B:
            switch (param_2) {
                case 0xC:
                    func_80101180(0x457, 0x4A, 0);
                    return 4;
                case 0xF:
                    func_80101180(0x458, 0x4A, 0);
                    return 4;
                case 0x13:
                    func_808014B0_chalienkids(param_0, 0x372);
                    _subaddieDll_entrypoint_4(param_0, 0);
                    func_80102424(param_0, 0x10);
                    _capod_entrypoint_14();
                    func_80101180(0x45A, 0x31, param_0->unk6C_9);
                    return 4;
                case 0x16:
                    func_808014B0_chalienkids(param_0, 0x373);
                    _subaddieDll_entrypoint_4(param_0, 0);
                    func_80102424(param_0, 0x10);
                    _capod_entrypoint_14();
                    func_80101180(0x45A, 0x31, param_0->unk6C_9);
                    return 4;
            }
            return 2;
        case 0x4A:
            func_80102424(param_0, 2);
            func_80103110(param_0, 1);
            _subaddieDll_entrypoint_4(param_0, 1);
            switch (param_0->unk6C_9) {
                case 0x456:
                    param_0->unk58 = 4.0f;
                    _capod_entrypoint_13(param_0->unk0, 0, 0xC, 0x2030);
                    break;
                case 0x457:
                    param_0->unk58 = 2.5f;
                    _capod_entrypoint_14();
                    _capod_entrypoint_13(param_0->unk0, 0, 0xF, 0x2030);
                    break;
                case 0x458:
                    param_0->unk58 = 2.0f;
                    func_8010A63C(param_0);
                    _capod_entrypoint_14();
                    _capod_entrypoint_13(param_0->unk0, 0, 0x12, 0x2010);
                    break;
            }
            break;
        case 0x4B:
            func_80108B04(param_0, 2);
            _capod_entrypoint_13(param_0->unk0, 0, 0x31, 0x30);
            _subaddieDll_entrypoint_4(param_0, 1);
            param_0->unk58 = 6.0f;
            func_80102424(param_0, 7);
            break;
        case 0x4C:
            local_9 = func_80100094(param_0, 0);
            *(s32 *)(local_9 + 0x2C) = 0;
            break;
        case 0x4E:
            if (param_0->unk70_10 == 0x10) {
                _subaddieDll_entrypoint_4(param_0, 1);
                func_80102424(param_0, 0x12);
                func_80108B04(param_0, 3);
                param_0->unk58 = 1.2f;
            }
            break;
        case 0x29:
            func_8080193C_chalienkids(param_0);
            break;
        case 0x2A:
            func_80801994_chalienkids(param_0);
            break;
        case 0x95:
            local_9 = func_80100094(param_0, 0);
            *(s32 *)(local_9 + 0x30) = 0;
            switch (param_0->unk6C_9) {
                case 0x456:
                    if (!func_800DA298(0x372) && !_glcutDll_entrypoint_20()) {
                        func_80108B04(param_0, 0);
                    }
                    break;
                case 0x457:
                    if (!func_800DA298(0x373) && !func_800DA298(0x6B4) && !_glcutDll_entrypoint_20()) {
                        func_80108B04(param_0, 1);
                    }
                    break;
            }
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80802224_chalienkids, param_0->scale);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800D58_chalienkids(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;

    func_80101870(param_0, (void *)param_1);
    if (param_0->unk7C_12) {
        local_0 = func_80100094(param_0, 0);
        if (*(Unk80132ED0 **)(local_0 + 0x30)) {
            func_8010A764(func_80106790(*(Unk80132ED0 **)(local_0 + 0x30)), param_1);
        }
    }
}

void func_80800DB8_chalienkids(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    switch (param_1) {
        case 0x1284:
            ((f32 *)param_0->actorData)[3] = 200.0f;
            func_80102424(param_0, 15);
            _subaddieDll_entrypoint_4(param_0, 1);
            _capod_entrypoint_14();
            _capod_entrypoint_13(param_0->unk0, 0, 0x13, 0x2010);
            break;
        case 0x1285:
            param_0->unk6C_0 = 5;
            ((f32 *)param_0->actorData)[3] = 200.0f;
            func_80102424(param_0, 15);
            _subaddieDll_entrypoint_4(param_0, 1);
            _capod_entrypoint_14();
            _capod_entrypoint_13(param_0->unk0, 0, 0x16, 0x2010);
            break;
        case 0x1286:
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80802234_chalienkids);
            func_80102424(param_0, 12);
            _subaddiefade_entrypoint_5(param_0);
            param_0->unk58 = 2.0f;
            break;
        case 0x12CE:
            _capod_entrypoint_14();
            break;
        default:
            local_0 = _subaddiedialog_entrypoint_9(param_0, param_1, D_80801E60_chalienkids, 4) != 0;
            local_1 = _subaddiedialog_entrypoint_9(param_0, param_1, D_80801E80_chalienkids, 3) != 0;
            if (local_0 || local_1) {
                func_80102424(param_0, 16);
            } else if (_subaddiedialog_entrypoint_9(param_0, param_1, D_80801EA8_chalienkids, 3)) {
                func_80102424(param_0, 16);
            } else if (_subaddiedialog_entrypoint_9(param_0, param_1, D_80801E98_chalienkids, 2)) {
                func_80102424(param_0, 9);
            }
            break;
    }
}

void func_80800FA4_chalienkids(param_0, param_1, param_2, param_3) Actor *param_0; s32 param_1; s32 param_2; s32 param_3;
{
    u8 *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_800DA298(0x372) != 0;
    if (local_1) {
        local_1 = func_800DA298(0x373) != 0;
        if (local_1) { local_1 = func_800DA298(0x374) != 0; }
    }
    if (local_1 && !_glcutDll_entrypoint_20()) { func_800FFAB0(param_0); return; }
    ((BitTest15 *)((u8 *)param_0 + 0x94))->flag = 1;
    _subaddiemarker_entrypoint_1(param_0, 0x154, param_1, local_0, 1);
    if (_glcutDll_entrypoint_20()) {
        func_8010A85C(param_0, 1);
        func_800EE7F8(param_0->position, local_0);
        param_0->rotation[1] = *(f32 *)(local_0 + 0x10);
        func_80102424(param_0, 0x10);
        func_80103014(param_0);
        return;
    }
    if (!func_800DA298(0x376)) {
        ((BitTest15 *)((u8 *)param_0 + 0x64))->flag = 0;
        func_80103110(param_0, 0);
        return;
    }
    if (func_800DA298(param_2)) {
        func_8010A85C(param_0, 1);
        func_800EE7F8(param_0->position, local_0);
        param_0->rotation[1] = *(f32 *)(local_0 + 0x10);
        func_80102424(param_0, 0x10);
        func_80103014(param_0);
        return;
    }
    func_80102424(param_0, param_3);
}

void func_80801138_chalienkids(Actor* arg0)
{
    func_80801994_chalienkids(arg0);
}

int func_80801158_chalienkids(Actor *param_0, s32 param_1)
{
    f32 local_6;
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_7;
    f32 local_9;
    f32 local_10;
    f32 local_5;
    f32 local_4[3];
    f32 local_11;
    s32 local_12;
    s32 local_13;
    AlienRingState331 *local_14;

    local_14 = func_80100094(param_0, 0);
    local_0 = func_800D9078(&param_0->unk58);
    if (!_subaddieskeleton_entrypoint_0(param_0, 3, local_1)) {
        func_800EE7F8(local_1, param_0->position);
    }
    local_5 = func_800D8FF8();
    local_12 = func_800B53A4(8);
    local_6 = func_80103EF4(param_0);
    local_7 = func_80103EAC(param_0) * 1.25f;
    func_800EE7F8(local_4, local_1);
    local_4[1] += 0.5f * local_6;
    local_9 = func_800F12D4(param_0->unk58, 0.0f, 2.0f, local_6, 0.5f * local_6);
    local_10 = func_800F12D4(param_0->unk58, 0.0f, 2.0f, 0.5f * local_6, local_6);
    local_7 = func_800F12D4(param_0->unk58, 0.0f, 2.0f, 0.25f * local_7, local_7);
    func_800BA3FC(local_12, param_1);
    for (local_13 = 0, local_11 = 0.0f; local_13 != 4; local_13++, local_11 += 90.0f) {
        func_800EEB9C(local_3, local_14->local_0[0] + local_11, local_7);
        func_800EE780(local_2, local_1, local_3);
        local_2[1] += local_9 + 10.0f * func_80013970(local_14->local_0[2] + local_11);
        func_800BABB8(local_12, local_2, local_4, 1.0f, D_8080223C_chalienkids);
        func_800EEB9C(local_3, local_14->local_0[1] + local_11, local_7);
        func_800EE780(local_2, local_1, local_3);
        local_2[1] += local_10 + 10.0f * func_80013970(local_14->local_0[3] + local_11);
        func_800BABB8(local_12, local_2, local_4, 1.0f, D_8080223C_chalienkids);
    }
    local_14->local_0[0] = func_800136E4(local_14->local_0[0] - local_5 * 380.0f);
    local_14->local_0[1] = func_800136E4(local_14->local_0[1] + local_5 * 380.0f);
    local_14->local_0[2] += local_5 * 100.0f;
    local_14->local_0[3] += local_5 * 150.0f;
    if (local_0) {
        func_800FCAE0(0x1C, 0, 500);
    } else {
        func_800FCAE0(0x1C, -1, 500);
    }
    return local_0;
}

void func_808014B0_chalienkids(Actor *param_0, s32 param_1)
{
    f32 *local_0;
    local_0 = func_80100094(param_0, 0);
    func_800EE7F8(param_0->position, local_0);
    param_0->rotation[1] = local_0[4];
    ((AlienKidFlags *)param_0)->local_0 = 1;
    func_80103014(param_0);
    func_80104E78(param_0);
    func_800DA544(param_1);
}

void func_80801520_chalienkids(void *param_0, s32 param_1) {
    s32 s0;
    f32 f4;

    s0 = (s32) param_0;
    f4 = 2.0f;
    *(f32 *)((u8 *)param_0 + 0x58) = f4;
    _subaddiefade_entrypoint_2();
    _subaddieDll_entrypoint_4(param_0, 1);
    func_8010A3E8(param_0, 0x3F19999A);
    func_80102424(param_0, 0xD);
    func_808014B0_chalienkids(param_0, param_1);
}

void func_8080158C_chalienkids(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;

    local_2 = func_80103EAC(param_0);
    local_1 = func_8010A40C(param_0) * local_2;
    if (param_0->unk64_16 && !func_8010A698(param_0)) {
        if (_subaddieskeleton_entrypoint_0(param_0, 3, local_0)) {
            func_8008FB58(local_0, 0.5f * local_1, local_1);
        }
    }
}

void func_80801628_chalienkids(param_0) Actor *param_0;
{
  s32 pad0;
  s32 local_2;
  AlienKidLink *local_0;
  Actor *local_1;
  if (param_0->unk7C_12)
  {
    local_0 = func_80100094(param_0, 0);
    local_2 = 0;
    if (local_0->marker)
    {
      local_1 = func_80106790(local_0->marker);
    }
    else
    {
      local_1 = 0;
    }
    if (local_1)
    {
      local_2 = func_8010A654(local_1, 0);
    }
    _chbadshad_entrypoint_2(param_0, 3, ((float) param_0->scale) * 1.4f, 0);
    if (local_1)
    {
      func_8010A654(local_1, local_2);
    }
  }
}

void func_808016D4_chalienkids(Actor *param_0)
{
    f32 local_1;
    switch (param_0->unk70_10) {
    case 0x12:
        if (func_800D9078((u8 *)param_0 + 0x58)) func_80102424(param_0, 0x13);
        return;
    case 0x13:
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 0x14);
            *(f32 *)((u8 *)param_0 + 0x58) = func_80800D68_chalienkids[param_0->unk6C_9];
        }
        break;
    case 0x14:
        if (func_800D9078((u8 *)param_0 + 0x58)) {
            func_80102424(param_0, 0x15);
            *(f32 *)((u8 *)param_0 + 0x34) = 50.0f;
            *(f32 *)((u8 *)param_0 + 0x58) = 4.0f;
            *(f32 *)((u8 *)param_0 + 0x28) = 0.5f;
        }
        break;
    case 0x15: {
        s32 local_0 = func_800D9078((u8 *)param_0 + 0x58);
        *(f32 *)((u8 *)param_0 + 0x34) += func_800D8FF8() * 100.0f;
        local_1 = func_800D8FF8();
        local_1 *= *(f32 *)((u8 *)param_0 + 0x34);
        param_0->position[1] += local_1;
        if (func_800D9078((u8 *)param_0 + 0x28)) _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80802260_chalienkids);
        if (local_0) {
            func_8010114C(*(s32 *)((u8 *)param_0 + 0x3C), 0x4F, 0);
            func_800FFAB0(param_0);
        }
        break;
    }
    }
}

void func_8080184C_chalienkids(u8 *param_0, s32 param_1, s32 param_2) {
    _subaddiedialog_entrypoint_8(param_0, param_0 + 4, D_8080226C_chalienkids, param_1, param_2);
}

void func_80801884_chalienkids(Actor *param_0)
{
    AlienKidAttachment *local_0;
    Actor *local_1;

    if (func_800D9078(&param_0->unk58)) {
        local_0 = func_80100094(param_0, 0);
        func_80102424(param_0, 3);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080227C_chalienkids);
        param_0->unk64_16 = 1;
        param_0->unk58 = 2.0f;
        _subaddiefade_entrypoint_2(param_0);
        func_8010A800(param_0, 0);
        if (local_0->local_0) {
            local_1 = func_80106790(local_0->local_0);
            local_1->unk64_16 = 0;
            func_8010A590(local_1);
        }
    }
}

s32 func_8080193C_chalienkids(s32 param_0) {
    s32 local_0;

    if (!func_80100094(param_0, 1)) {
        local_0 = _suexpression_entrypoint_7(param_0, 1, 0xB7);
        _suexpression_entrypoint_12(local_0, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(local_0, 0x3E8);
    }
}

void func_80801994_chalienkids(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_808019C8_chalienkids(param_0) u8 *param_0; {
    s32 sp1C;
    s32 temp_v0;
    s32 temp_v0_2;

    if ((*(u16 *)((u8 *)param_0 + 0x64)) & 1) {
        temp_v0 = func_80100094(param_0, 1);
        sp1C = temp_v0;
        if (temp_v0 != 0) {
            temp_v0_2 = func_801022E4(param_0);
            switch (temp_v0_2) {
            case 0x325:
            case 0x326:
            case 0x329:
            case 0x32C:
            case 0x32E:
                break;
            default:
            case 0x327:
            case 0x328:
            case 0x32A:
            case 0x32B:
            case 0x32D:
                _suexpression_entrypoint_18(sp1C, 1);
                break;
            }
            _suexpression_entrypoint_10(sp1C, *(s32 *)param_0, 0);
        }
    }
}

int func_80801A50_chalienkids(Actor *param_0)
{
  func_80109F08(param_0, 0x44);
  ((u8 *)(((char *)param_0) + 0x7A))[0] = (((u8 *)(((char *)param_0) + 0x7A))[0] & 0xFF3F) | 0x80;
}

void func_80801A88_chalienkids(Actor *param_0)
{
    f32 local_0[3];
    if (param_0->unk70_10 == 2) {
        if (_subaddieDll_entrypoint_6(param_0, 10)) {
            func_8010A570(param_0);
            func_800EE7F8(local_0, param_0->position);
            local_0[1] -= 100.0f;
            _chexploder_entrypoint_3(param_0, local_0, 0);
        }
    }
}

s32 func_80801B08_chalienkids(s32 param_0, s32 param_1){
    func_800DF744(3, 1);
    func_80101870(param_0, param_1);
}

s32 func_80801B40_chalienkids(Actor *param_0, s32 param_1, ActorCallbackData param_2)
{
    switch (param_1) {
        case 0x40:
            if (_subaddieDll_entrypoint_5(param_0, param_2.pointer)) {
                func_80103110(param_0, 1);
                func_80101FDC(param_0, 2);
                return 0;
            }
            break;
        case 0x90:
            func_80801BC4_chalienkids(param_0);
            return 0;
        default:
            return 0;
    }
    return 0;
}

void func_80801BC4_chalienkids(param_0) Actor *param_0;
{
    s32 local_0;
    _chexploder_entrypoint_9(func_80106790(func_80101080()), 3, 2);
    func_8010114C(param_0->unk3C, 0xA, 0);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80802284_chalienkids);
    local_0 = *(s32 *)((u8 *)param_0 + 0x50);
    if (local_0) {
        func_800DA544(local_0);
    }
    func_800FFAB0(param_0);
}
