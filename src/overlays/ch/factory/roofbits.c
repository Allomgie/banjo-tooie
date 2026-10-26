#include "ch/factory/roofbits.h"

extern void func_800EE7F8(void *param_0, s32 param_1);
extern void func_800EF1B8(void *param_0, s32 param_1, s32 param_2);
extern void _chexploder_entrypoint_3(void *param_0, void *param_1, s32 param_2);
extern Actor *func_80106790();
extern u8 D_80800920_chfactoryroofbits[];
extern u8 D_80800968_chfactoryroofbits[];
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern int D_80800974_chfactoryroofbits;
extern u8 D_808009FC_chfactoryroofbits[];
extern u8 D_808009BC_chfactoryroofbits[];
extern void func_800DF500(f32, f32, s32);
extern void func_80101870();
extern int D_80800A08_chfactoryroofbits;
extern f32 func_80103EF4(Actor *);
extern int _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern int D_80800A50_chfactoryroofbits;
extern Vec3f D_80800A98_chfactoryroofbits;
extern s32 D_80800AA4_chfactoryroofbits[];
extern int D_80800AEC_chfactoryroofbits;
extern int D_80800B34_chfactoryroofbits;
extern void func_800EFA4C(f32 *, f32, f32, f32);
void func_808000D4_chfactoryroofbits();
s32 func_808001C0_chfactoryroofbits();

int func_80800000_chfactoryroofbits(s32 param_0)
{
  func_800EFA4C(param_0 + 4, -1124.0f, 9002.0f, 1596.0f);
}

int func_8080003C_chfactoryroofbits(s32 param_0, s32 param_1, f32 param_2)
{
  f32 local_1[3];
  if (param_1 == 0x40)
  {
    func_800EE7F8(local_1, param_0 + 4);
    func_800EF1B8(local_1, *(s32 *)(param_0 + 0x48), 0xC3160000);
    local_1[1] -= 50.0f;
    _chexploder_entrypoint_3((void *)param_0, local_1, 0xC);
    return 1;
  }
  else if (param_1 == 0x90)
  {
    func_808000D4_chfactoryroofbits(param_0);
    return 1;
  }
  return 0;
}

void func_808000D4_chfactoryroofbits(param_0) Actor *param_0;
{
    _chexploder_entrypoint_6(func_80106790(func_80101080(param_0)), 600.0f, 800.0f);
    func_800DA544(0x196);
    func_800BABB8(0, param_0->position, param_0->position, param_0->scale, D_80800920_chfactoryroofbits);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800968_chfactoryroofbits);
}

int chfactoryroofbits_entrypoint_0()
{
    return (int)&D_80800974_chfactoryroofbits;
}

s32 func_8080015C_chfactoryroofbits(s32 param_0) {
    switch (param_0) {
        case 0x4B:
            return 0x197;
        case 0x4C:
            return 0x198;
        case 0x4D:
            return 0x199;
        case 0x4E:
            return 0x19A;
        case 0xE:
            return 0x19B;
        default:
            return 0;
    }
}

s32 func_808001C0_chfactoryroofbits(param_0, param_1, param_2, param_3) s32 param_0; f32 *param_1; f32 *param_2; f32 *param_3;
{
    switch (param_0) {
    case 0x4B:
        func_800EFA4C(param_1, -1397.0f, 8063.0f, -632.0f);
        func_800EFA4C(param_2, 0.94f, 0.73f, 1.0f);
        *param_3 = 312.0f;
        break;
    case 0x4C:
        func_800EFA4C(param_1, 174.0f, 8066.0f, -1017.0f);
        func_800EFA4C(param_2, 0.94f, 0.73f, 1.0f);
        *param_3 = 312.0f;
        break;
    case 0x4D:
        func_800EFA4C(param_1, -1138.0f, 2148.0f, 2300.0f);
        func_800EFA4C(param_2, 1.8f, 1.8f, 1.8f);
        *param_3 = 0.0f;
        break;
    case 0x4E:
        func_800EFA4C(param_1, 2303.0f, 2143.0f, -376.0f);
        func_800EFA4C(param_2, 1.8f, 1.8f, 1.8f);
        *param_3 = 0.0f;
        break;
    case 0xE:
        func_800EFA4C(param_1, 2645.0f, 1494.0f, 2645.0f);
        func_800EFA4C(param_2, 1.14f, 1.0f, 1.0f);
        *param_3 = 0.0f;
        break;
    default:
        return 1;
    }
    return func_800DA298(func_8080015C_chfactoryroofbits(param_0));
}

int func_808003C4_chfactoryroofbits(Actor *param_0)
{
    if (func_808001C0_chfactoryroofbits((u32)(*(s32 *)((char *)param_0 + 0x6C)) >> 0x15, (s32 *)((char *)param_0 + 0x4), (s32 *)((char *)param_0 + 0x28), (s32 *)((char *)param_0 + 0x44)))
    {
        func_800FFA88(*(s32 *)param_0);
    }
}

int func_80800414_chfactoryroofbits(Actor *param_0, s32 param_1, struct { Unk80132ED0 *p; } param_2) /* event parameter as a struct passed by value: the target saves a2 to its home slot */
{
    s32 local_0;
    f32 *local_1;
    if (param_1 == 0x40) {
        if (*(u16 *)((u8 *)param_2.p + 0x18) & 1) {
            if ((((u32)*(u32 *)((u8 *)func_80106790(param_2.p) + 0x6C) << 11) >> 20) == 0x15D) {
                local_0 = func_800B53A4(32);
                local_1 = param_0->position;
                func_800BABB8(local_0, local_1, 0, ((f32 *)param_0->actorData)[6] * 0.5f, D_808009BC_chfactoryroofbits);
                func_800BA930(local_0, -200, 400, -200, 200, 800, 200);
                func_800BA22C(local_0, 32);
            } else {
                local_0 = func_800B53A4(16);
                local_1 = param_0->position;
                func_800BABB8(local_0, local_1, 0, ((f32 *)param_0->actorData)[6], D_808009BC_chfactoryroofbits);
                func_800BA22C(local_0, 16);
            }
        } else {
            local_0 = func_800B53A4(8);
            local_1 = param_0->position;
            func_800BABB8(local_0, local_1, 0, ((f32 *)param_0->actorData)[6] * 1.25f, D_808009BC_chfactoryroofbits);
            func_800BA22C(local_0, 8);
        }
        _subaddieaudioquick_entrypoint_2(param_0, local_1, D_808009FC_chfactoryroofbits);
        func_800DA544(func_8080015C_chfactoryroofbits((u32)*(u32 *)((u8 *)param_0 + 0x6C) >> 21));
        func_800FFAB0(param_0);
        return 1;
    }
    return 0;
}

void func_808005DC_chfactoryroofbits(u8 *param_0, s32 param_1) {
    func_800DF500(*(f32 *)(param_0 + 0x28), *(f32 *)(param_0 + 0x2C), *(s32 *)(param_0 + 0x30));
    func_80101870(param_0, param_1);
}

int *chfactoryroofbits_entrypoint_1()
{
    return &D_80800A08_chfactoryroofbits;
}

void func_80800624_chfactoryroofbits(Actor *param_0)
{
    _chdoormake_entrypoint_3(param_0, param_0->rotation[1], 90.0f, func_80103EF4(param_0), 0x20AE, 0xA08);
    _chdoormake_entrypoint_5(param_0, 3.0f);
    _chdoormake_entrypoint_6(param_0, 7.0f);
    _chdoormake_entrypoint_8(param_0, 4);
    _chdoormake_entrypoint_9(param_0, 0, 1, 0x10);
    _chdoormake_entrypoint_10(param_0, 0, 0x19C);
    _chdoormake_entrypoint_9(param_0, 1, 0xB, 0x10);
    _chdoormake_entrypoint_10(param_0, 1, 0x19D);
}

int *chfactoryroofbits_entrypoint_2()
{
    return &D_80800A50_chfactoryroofbits;
}

void func_808006E8_chfactoryroofbits(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_A08_UNK);
}

s32 func_80800708_chfactoryroofbits(Actor *param_0, s32 param_1, s32 param_2)
{
    Vec3f local_0;
    switch (param_1) {
        case 0x3D:
            local_0 = D_80800A98_chfactoryroofbits;
            func_80108528(0x3F3, local_0.f, 0x10E, &param_0);
            break;
        case 0x95:
            if (!_subaddiefind_entrypoint_2(0x3F3, 0)) func_80108B04(param_0, 0);
            break;
    }
    return _chswitch_entrypoint_10(param_0, param_1, param_2);
}

int chfactoryroofbits_entrypoint_3()
{
    return D_80800AA4_chfactoryroofbits;
}

void func_808007B8_chfactoryroofbits(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_163_STATION_UNLOCKED_GI);
    _chswitch_entrypoint_9(arg0);
}

int func_808007E4_chfactoryroofbits(Actor *param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 7)
  {
    _glcutDll_entrypoint_6(0x102, 0x44);
  }
  _chswitch_entrypoint_10(param_0, param_1 | param_1, param_2);
}

int chfactoryroofbits_entrypoint_4()
{
    return (int)&D_80800AEC_chfactoryroofbits;
}

s32 func_80800840_chfactoryroofbits(Actor *this) {
    _chdoormake_entrypoint_0(this, 0x42b40000, 0x80, 0x355);
    _chdoormake_entrypoint_5(this, 3.0f);
    _chdoormake_entrypoint_6(this, 1.0f);
    _chdoormake_entrypoint_8(this, 4);
}

s32 func_80800890_chfactoryroofbits(Actor *param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x49) {
        if (param_2 == 0x86) {
            _capod_entrypoint_13(param_0->unk0, 0, 0x12, 0x910);
            return _chdoor_entrypoint_1(param_0, 7, 0);
        }
        return 0;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

int *chfactoryroofbits_entrypoint_5()
{
    return &D_80800B34_chfactoryroofbits;
}
