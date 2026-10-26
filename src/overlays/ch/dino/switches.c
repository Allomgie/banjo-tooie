#include "common.h"

extern int D_80800C30_chdinoswitches;
extern int D_80800C78_chdinoswitches;
extern int D_80800CC0_chdinoswitches;
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
typedef struct { u16 f[10]; } E20;
extern u8 D_8011A270[];
extern u8 D_8011A248[];
typedef struct { u8 pad_0[0x74]; u32 pad_1 : 10; u32 local_0 : 1; u32 pad_2 : 21; } DinoSwitchFlags;
extern void _chdinoswitches_entrypoint_4(void);
extern void (*func_800CE95C(s32))(void);
extern void func_800CE928(s32, void (*)(void), s32);
extern void func_800CE8D8(s32, f32, s32);
extern struct { u16 field; u16 pad[9]; } D_80800B22_chdinoswitches[];
typedef struct { u16 flag; u8 pad_0[0x12]; } DinoSwitchFlag;
extern s32 func_80101E14(Actor *, f32);
extern void func_80101EE4(Actor *, f32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern u16 D_80800B2C_chdinoswitches[];
s32 func_80800108_chdinoswitches();

int chdinoswitches_entrypoint_0()
{
    return (int)&D_80800C30_chdinoswitches;
}

int chdinoswitches_entrypoint_1()
{
    return (int)&D_80800C78_chdinoswitches;
}

int chdinoswitches_entrypoint_2(void)
{
    return (int)&D_80800CC0_chdinoswitches;
}

int chdinoswitches_entrypoint_3()
{
  return (int)D_80800D08_chdinoswitches;
}

void func_80800030_chdinoswitches(u8 *param_0) {
    s32 local_0;

    local_0 = func_80800108_chdinoswitches();
    *(s32 *)((char *)param_0 + 0x18) = local_0;
    if ((local_0 == 4) && ((func_800DA298(0x676U) != 0) || (func_800D0B68(0x18, 0) != 0))) {
        func_800DA544(0xA10);
    }
    _chswitch_entrypoint_7(param_0, *(u16 *)((char *)((local_0 * 0x14) + D_80800B20_chdinoswitches) + 2));
    _chswitch_entrypoint_8(param_0, *(s32 *)((char *)((local_0 * 0x14) + D_80800B20_chdinoswitches) + 4));
    if (*(s32 *)((char *)param_0 + 0x18) == 4) {
        if (func_800DA298(*(u16 *)((char *)((local_0 * 0x14) + D_80800B20_chdinoswitches) + 2)) != 0) {
            func_80103110(param_0, 0);
        }
    } else {
        _chswitch_entrypoint_9(param_0);
    }
}

s32 func_80800108_chdinoswitches(param_0) ALCSPlayer *param_0;
{
  ALCSPlayer *new_var;
  s32 local_0;
  s32 local_1;
  u16 *local_2;
  local_0 = func_800EA05C();
  if ((local_0 == (*((u16 *) D_80800B44_chdinoswitches))) && ((((u32) ((u16) (*((u16 *) (((char *) param_0) + 0x76))))) >> 7) == (*((u16 *) D_80800B34_chdinoswitches))))
  {
    return 1;
  }
  if ((local_0 == (*((u16 *) D_80800B58_chdinoswitches))) && ((((u32) ((u16) (*((u16 *) (((char *) param_0) + 0x76))))) >> 7) == (*((u16 *) D_80800B48_chdinoswitches))))
  {
    return 2;
  }
  new_var = param_0;
  local_1 = 4;
  if ((local_0 == (*((u16 *) D_80800B6C_chdinoswitches))) && ((((u32) ((u16) (*((u16 *) (((char *) new_var) + 0x76))))) >> 7) == (*((u16 *) D_80800B5C_chdinoswitches))))
  {
    return 3;
  }
  if (((!param_0) && (!param_0)) && (!param_0))
  {
  }
  local_1 = 4;
  local_2 = (u16 *) D_80800B70_chdinoswitches;
  loop_10:
  if ((local_0 == (*((u16 *) (local_2 + 8)))) && ((((u32) ((u16) (*((u16 *) (((char *) param_0) + 0x76))))) >> 7) == (*((u16 *) (local_2 + 0)))))
  {
    return local_1;
  }

  if ((local_0 == (*((u16 *) (local_2 + 18)))) && ((((u32) ((u16) (*((u16 *) (((char *) param_0) + 0x76))))) >> 7) == (*((u16 *) (local_2 + 10)))))
  {
    return local_1 + 1;
  }
  if ((local_0 == (*((u16 *) (local_2 + 28)))) && ((((u32) ((u16) (*((u16 *) (((char *) param_0) + 0x76))))) >> 7) == (*((u16 *) (local_2 + 20)))))
  {
    return local_1 + 2;
  }
  if ((local_0 == (*((u16 *) (local_2 + 38)))) && ((((u32) ((u16) (*((u16 *) (((char *) param_0) + 0x76))))) >> 7) == (*((u16 *) (local_2 + 0x1E)))))
  {
    return local_1 + 3;
  }
  local_1 += 4;
  local_2 += 0x28;
  if (local_1 == 0xC)
  {
    return 0;
  }
  goto loop_10;
}

void func_80800270_chdinoswitches(Actor *param_0)
{
    s32 local_0;

    local_0 = param_0->actorData[0];
    func_801032B0(param_0, *(u16 *)((u8 *)D_80800B28_chdinoswitches + local_0 * 0x14),
                 *(u16 *)((u8 *)param_0->unk0 + 0x16));
}

s32 func_808002B0_chdinoswitches(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 pad[2];
    Unk80132ED0 *local_0;
    s32 local_1;

    switch (param_1) {
        case 7:
            local_0 = param_0->unk3C;
            if (local_0) func_8010114C(local_0, param_1, 0);
            break;
        case 0x95:
            _subaddiefind_entrypoint_10(param_0, 0x364, param_0->unk74_7);
            func_80800270_chdinoswitches(param_0);
            return _chswitch_entrypoint_10(param_0, param_1, param_2);
        case 0x99:
            if (((DinoSwitchFlags *)param_0)->local_0) local_1 = param_0->actorData[0];
            else local_1 = func_80800108_chdinoswitches();
            switch (((E20 *) D_80800B28_chdinoswitches)[local_1].f[0]) {
                case 0x7B8:
                case 0x7B9:
                case 0x942:
                    func_80101074(D_8011A270);
                    return 1;
                default:
                    func_80101074(D_8011A248);
                    return 1;
            }
            break;
        default:
            return _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
    return 1;
}

s32 func_808003E8_chdinoswitches(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    switch (param_1) {
    case 7:
        if (!func_800D0B68(0x18, 0)) {
            func_80103110(param_0, 0);
            func_8010114C(param_0->unk3C, 7, 0);
            func_800CE8D8(0, 35.0f, 0x23);
            func_800CE88C(0, 1);
            func_800CE928(0, _chdinoswitches_entrypoint_4, 0);
        }
        break;
    case 0x91:
        if (func_800F64A4(param_2, 0x40000) && func_800CEAA8(0) && func_800CE95C(0) == _chdinoswitches_entrypoint_4) {
            func_800CE8D8(0, 35.0f, 0x23);
            func_800CE928(0, _chdinoswitches_entrypoint_4, 0);
        }
        return _chswitch_entrypoint_10(param_0, param_1, param_2);
    case 8:
        func_80103110(param_0, 1);
        break;
    case 0x99:
        func_80101074(D_8011A248);
        break;
    case 0xB7:
        if (!(param_2 & 0xFFFF)) {
            if (((param_2 >> 16) & 0xFFFF) == 0x18) {
                if (func_800CEAA8(0) && func_800CE95C(0) == _chdinoswitches_entrypoint_4) {
                    func_800CE928(0, NULL, 0);
                    func_800CE88C(0, 0);
                }
                if (param_0->unk3C) func_8010114C(param_0->unk3C, 7, 0);
            }
        }
        break;
    case 0x95:
        _subaddiefind_entrypoint_10(param_0, 0x364, param_0->unk74_7);
        _chswitch_entrypoint_10(param_0, param_1, param_2);
        if (func_800DA298(*(u16 *)(((u8 *) D_80800B22_chdinoswitches) + param_0->actorData[0] * 20))) func_80103110(param_0, 0);
        break;
    default:
        return _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
    return 1;
}

int chdinoswitches_entrypoint_4(s32 param_0, s32 param_1)
{
  s32 local_1;
  s32 local_0;
  if (func_800EA05C() == 0x112)
  {
    local_1 = _subaddiefind_entrypoint_11(0x364, 0x35);
    local_0 = _subaddiefind_entrypoint_11(0x433, 0x35);
    func_80101180(0x433, 8, 0);
    func_8010108C(local_1, 8, 0);
    func_80103110(local_0, 1);
    return;
  }
  if (func_800DA298(0xA3A) == 0)
  {
    _glcutDll_entrypoint_6(0x112, 0x37);
    return;
  }
  func_800DA524(0xA10);
  func_800DA524(0x676);
}

void func_80800714_chdinoswitches(Actor *param_0)
{
  s32 local_0;
  s32 *local_1 = (s32 *) (((char *) param_0) + 0x18);
  *((s32 *) (((char *) param_0) + 0x18)) = func_80800108_chdinoswitches();
  if (func_800DA298(D_80800B22_chdinoswitches[*((s32 *) (((char *) param_0) + 0x18))].field))
  {
    func_80102424(param_0, 3);
    func_80101EE4(param_0, 0.3f);
    func_8010A570(param_0);
  }
  if ((*local_1) == 3)
  {
    func_80109EEC(param_0, 0x44);
  }
}

void func_808007A0_chdinoswitches(Actor *param_0)
{
    if (param_0->unk70_10 == 2 && func_80101E14(param_0, 0.3f)) {
        func_800DA544(((DinoSwitchFlag *) D_80800B22_chdinoswitches)[param_0->actorData[0]].flag);
        func_80102424(param_0, 3);
        func_80101EE4(param_0, 0.3f);
        func_80103110(param_0, 0);
        if (param_0->unk3C != NULL) func_8010114C(param_0->unk3C, 7, 0);
    }
}

int func_80800848_chdinoswitches(Actor *param_0, s32 param_1, u8 param_2)
{
    switch (param_1)
    {
    case 0x40:
        _gcaudiolist_entrypoint_0(0);
        func_80102424(param_0, 2);
        func_8010A570(param_0);
        func_80103110(param_0, 1);
        goto block_6;
    case 0x95:
        _subaddiefind_entrypoint_10(param_0, 0x364, (u32)((u16) (*(u16 *)((char *)(param_0) + 0x76))) >> 7);
        func_80800270_chdinoswitches(param_0);
        goto block_6;
    default:
        return 0;
    }
block_6:
    return 1;
}

void func_808008F0_chdinoswitches(Actor *param_0)
{
    u8 *local_1;
    s32 local_0 = func_80800108_chdinoswitches();
    s32 local_2;

    param_0->actorData[0] = local_0;
    local_1 = D_80800B20_chdinoswitches + local_0 * 20;
    if (local_0 == 4 && func_800D0B68(0x18, 0)) func_800DA544(*(u16 *)(local_1 + 18));
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, param_0->scale * 350.0f, *(u16 *)(local_1 + 14), *(u16 *)(local_1 + 18))) {
        _chdoormake_entrypoint_5(param_0, 2.75f);
        _chdoormake_entrypoint_8(param_0, 14);
        local_2 = *(s16 *)(local_1 + 10);
        if (local_2 != -1) _chdoormake_entrypoint_9(param_0, 0, local_2, 0x10);
    }
    switch (param_0->actorData[0]) {
        case 3:
            func_8010A800(param_0, 0);
            break;
        case 4:
            _chdoormake_entrypoint_9(param_0, 1, 0x23, 0x810);
            _chdoormake_entrypoint_12(param_0, 1, 0x37);
            _chdoormake_entrypoint_10(param_0, 1, 0xA3A);
            _chdoormake_entrypoint_10(param_0, 0, 0xA23);
            break;
    }
}

void func_80800A48_chdinoswitches(param_0) Actor *param_0;
{
    s32 local_0;

    local_0 = param_0->actorData[0];
    func_80103140(param_0, *(u16 *)((u8 *)D_80800B2C_chdinoswitches + local_0 * 0x14),
                 *(u16 *)((u8 *)param_0->unk0 + 0x16));
}

s32 func_80800A88_chdinoswitches(u8 *param_0, s32 param_1, s32 param_2) {
    switch (param_1) {                                 
    case 0xB:
        if (((*(s32 *)((s8 *)(param_0) + (0x18))) == 4) && (param_2 == 0x23) && (_glcutDll_entrypoint_19(0x37) != 0)) {
            _glcutDll_entrypoint_17();
        }
        return 3;
    case 0x95:
        func_80800A48_chdinoswitches();
        
    default:
        return _chdoor_entrypoint_1(param_0, param_1, param_2);
    }
}
