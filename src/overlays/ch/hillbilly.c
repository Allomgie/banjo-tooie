#include "common.h"

#define PLANT_ACTOR_FLAGS_DEFINED
extern int D_80800C60_chhillbilly[];
typedef struct { u8 pad[0x28]; u32 pad28:18; u32 flag:1; u32 rest:13; } HillSub;
extern void func_800DF744(s32, s32, HillSub **);
extern void _sucoaster_entrypoint_20(HillSub **, s32);
extern void func_800EE7F8(void *, void *);
extern s32 D_80800CB4_chhillbilly[];
typedef struct { u8 pad_0[0x64]; u32 : 2; u32 local_0 : 1; u32 : 29; } HillbillyFlags1262;
extern s32 _subaddiejoy_entrypoint_6(Actor *, s32);
extern int _sucoaster_entrypoint_13(Actor *);
typedef struct { u8 pad_0[0x64]; u32 pad_64_30 : 2; u32 flag_64_29 : 1; u32 pad_64_0 : 29; } PlantActorFlags;
extern s32 _subaddieDll_entrypoint_3(Actor *);
extern void _sucoaster_entrypoint_6();
extern void _sucoaster_entrypoint_10(Actor *, s32);
typedef struct { u8 pad0[0x64]; u32 pad64 : 2; u32 unk64_29 : 1; u32 pad64_0 : 29; u8 pad68[0x10]; u32 pad78 : 29; u32 unk78_2 : 1; u32 pad78_0 : 2; } HillbillyActor;
typedef struct { u8 pad0[0x2A]; u8 unk2A; } HillbillyModel;
extern u8 D_80800B54_chhillbilly[];
extern s32 _sucoaster_entrypoint_21(Actor *, s32, s32);
extern void func_80101074();
extern s32 _sucoaster_entrypoint_3(u8 *);
extern void func_800EE88C(f32 *, f32 *);
extern void func_800BBCB8(void *, s32, s32, s32, void *);
extern s32 D_80800CF0_chhillbilly[];
extern void func_80103140();
extern void func_801032B0();
extern void func_8010A3E8(Actor *, f32);
extern void _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
extern f32 func_8010CD28(Actor *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_80102D78(Actor *, f32 *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void _sucoaster_entrypoint_7(Actor *, s32, f32);
extern u8 D_80800CA8_chhillbilly[];
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 local_0 : 1; u32 pad_2 : 29; u8 pad_3[0x10]; u32 pad_4 : 29; u32 local_1 : 1; u32 pad_5 : 2; } HillbillyFlags62;
extern f32 func_800EFC7C();
extern s32 func_800D9058(f32);
extern void func_8010297C(Actor *, f32, f32, f32);
typedef struct { u32 pad64_30 : 2; u32 unk64_29 : 1; u32 pad64_0 : 29; } ActorFlags64;
void func_808009D8_chhillbilly();
s32 func_808002F0_chhillbilly();
s32 func_808006B4_chhillbilly();

int *chhillbilly_entrypoint_0()
{
    return &D_80800C60_chhillbilly;
}

s32 func_8080000C_chhillbilly(s32 param_0) {
    s32 local_0;

    if (_sucoaster_entrypoint_0(param_0, 0xC)) {
        local_0 = _sucoaster_entrypoint_3(param_0);
        func_800EE940(local_0 + 6, param_0 + 4);
        func_800EE940(local_0, param_0 + 4);
    }
}

void func_80800944_chhillbilly();

s32 func_8080042C_chhillbilly();

void func_80800064_chhillbilly(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];

    _sucoaster_entrypoint_2(param_0);
    if (((HillbillyFlags62 *)param_0)->local_1) return;
    _subaddieskeleton_entrypoint_3(param_0->unk0, 4, local_0);
    func_800EE940(_sucoaster_entrypoint_3(param_0), local_0);
    switch (param_0->unk70_10) {
    case 2:
    case 3:
    case 8:
        if (func_8080042C_chhillbilly(param_0)) {
            _sucoaster_entrypoint_10(param_0, 0x14);
            ((f32 *)param_0->actorData)[3] = 0.0f;
        }
        break;
    case 19:
        func_80800944_chhillbilly(param_0);
        param_0->unk54 = func_8010CD28(param_0);
        func_80102BF8(param_0, 0.2f, 60.0f, 300.0f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800CA8_chhillbilly, 0.2f);
        if (func_80101DDC(param_0)) {
            _sucoaster_entrypoint_10(param_0, (((u8 *)param_0)[0x74] & 1) ? 0x12 :
                ((HillbillyFlags62 *)param_0)->local_0 ? 2 : 8);
        }
        break;
    case 20:
        _sucoaster_entrypoint_19(param_0);
        if (func_80101DDC(param_0)) {
            func_808009D8_chhillbilly(param_0, 0x78A, 0);
            _sucoaster_entrypoint_10(param_0, 0x16);
        }
        break;
    case 21:
        _sucoaster_entrypoint_19(param_0);
        if (!_sucoaster_entrypoint_13(param_0)) {
            if (func_808002F0_chhillbilly(param_0)) {
                _sucoaster_entrypoint_10(param_0, 0x14);
                ((f32 *)param_0->actorData)[3] = 0.0f;
                break;
            }
            if (_subaddierouteDll_entrypoint_4(param_0)) {
                func_800EE88C(local_1, (f32 *)((u8 *)_sucoaster_entrypoint_3(param_0) + 6));
                param_0->unk54 = func_80102D78(param_0, local_1);
            }
        }
        _sucoaster_entrypoint_7(param_0, 0x5802, 30.0f);
        break;
    case 22:
        if (func_808003C8_chhillbilly(param_0)) {
            func_808009D8_chhillbilly(param_0, 0x789, 0);
            _sucoaster_entrypoint_10(param_0, 0x13);
        }
        break;
    }
}

void func_80800298_chhillbilly(HillSub **param_0, s32 param_1) {
    func_800DF744(3, (*param_0)->flag ? 0 : 1, param_0);
    _sucoaster_entrypoint_20(param_0, param_1);
}

s32 func_808002F0_chhillbilly(param_0) u8 *param_0; {
    f32 local_0[3];
    func_800EE88C(local_0, _sucoaster_entrypoint_3(param_0) + 6);
    return func_800EFC7C(param_0 + 4, local_0) < 10000.0f;
}

void func_80800348_chhillbilly(void *param_0)
{
  f32 local_0[3];
  if ((((unsigned int) (*((u16 *) ((char *) param_0 + 0x72)))) >> 10) == 0x16)
  {
    func_800EE7F8(local_0, (void *) (((char *) param_0) + 0x4));
  }
  else
  {
    func_800EE88C(local_0, _sucoaster_entrypoint_3(param_0));
  }
  func_800BBCB8(local_0, 0, *((s32 *) (((char *) param_0) + 0x38)), 1, &D_80800CB4_chhillbilly);
}

int func_808003C8_chhillbilly(Actor *param_0)
{
    if (((HillbillyFlags1262 *)param_0)->local_0) {
        return _subaddiejoy_entrypoint_6(param_0, 0) == 1;
    }
    if (*((u8 *)param_0 + 0x74) & 1) {
        return 1;
    }
    return _sucoaster_entrypoint_13(param_0) == 1;
}

s32 func_8080042C_chhillbilly(Actor *param_0)
{
    if (((PlantActorFlags *)param_0)->flag_64_29) {
        return _subaddiejoy_entrypoint_6(param_0, 0) == 1;
    }
    return 0;
}

void func_8080046C_chhillbilly(u8 *param_0)
{
  u32 temp_t6;
  temp_t6 = (u16) (*((u16 *) (((s8 *) param_0) + 0x72)));
  temp_t6 = temp_t6 >> 10;
  switch (temp_t6)
  {
    case 21:
      _sucoaster_entrypoint_10(param_0, 3);
      return;

    case 22:
      func_808009D8_chhillbilly(param_0, 0x789, 0);
      _sucoaster_entrypoint_10(param_0, 0x13);
      return;

  }

}

void func_808004D0_chhillbilly(Actor *param_0)
{
    s32 local_1;
    u32 local_0;

    local_0 = param_0->unk70_10;
    if (local_0 == 2 || local_0 == 3 || local_0 == 8) {
        if (_subaddieDll_entrypoint_3(param_0)) {
            local_1 = 21;
        } else {
            local_1 = 14;
        }
        _sucoaster_entrypoint_6(param_0, 0x43480000, local_1);
        _sucoaster_entrypoint_10(param_0, local_1);
    }
}

s32 func_80800540_chhillbilly(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    switch (param_1) {
    case 1:
    case 2:
        local_0 = _sucoaster_entrypoint_21(param_0, param_1, param_2);
        if (!((HillbillyActor *)param_0)->unk78_2) {
            if (((HillbillyActor *)param_0)->unk64_29) {
                func_8080046C_chhillbilly(param_0);
            } else {
                func_808004D0_chhillbilly(param_0);
            }
            return 1;
        }
        break;
    case 0x42:
        local_0 = func_808006B4_chhillbilly(param_0, ((s16 *)&param_2)[0], ((u8 *)&param_2)[2]);
        break;
    case 0x8F:
        local_1 = param_2;
        if (local_1 == 0 || local_1 == 4) {
            func_808009D8_chhillbilly(param_0, 0x78A, 0);
            ((HillbillyModel *)param_0->unk0)->unk2A &= ~0x20;
        }
        local_0 = 1;
        break;
    case 0x95:
        func_808009D8_chhillbilly(param_0, (param_0->unk70_10 == 0x16 || param_0->unk70_10 == 0x10) ? 0x78A : 0x789, 1);
        local_0 = _sucoaster_entrypoint_21(param_0, param_1, param_2);
        break;
    case 0x38:
        func_80101074(D_80800B54_chhillbilly);
        return 7;
    default:
        local_0 = _sucoaster_entrypoint_21(param_0, param_1, param_2);
        break;
    }
    return local_0;
}

void func_80800894_chhillbilly();

s32 func_808006B4_chhillbilly(param_0, param_1, param_2) Actor *param_0; s32 param_1; u32 param_2;
{
    switch (param_2) {
    case 0:
        if (param_0->unk70_10 == 0x16) return 0;
        switch (param_1) {
        case 2:
        case 3:
            func_80800894_chhillbilly(param_0, param_0->unk0->unk14 == 0x78A ? 0x16 : 0x15);
            return 0;
        case 4:
            func_80800894_chhillbilly(param_0, 0x15);
            return 0;
        case 5:
        case 8:
        case 9:
        case 18:
            return 1;
        case 7:
            _sucoaster_entrypoint_10(param_0, 8);
            return 0;
        }
        break;
    case 2:
    case 7:
        func_80800894_chhillbilly(param_0, 0x15);
        return 0;
    case 3:
        param_0->unk6C_0 = func_800D9058(2.0f);
        func_8010297C(param_0, param_0->unk54, 70.0f, 120.0f);
        if (param_0->unk70_10 == 8) func_80800894_chhillbilly(param_0, 0x15);
        return 0;
    case 4:
        if (param_0->unk0->unk14 == 0x789)
            return 1;
        break;
    case 1:
    case 6:
        return 1;
    case 5:
        func_80800894_chhillbilly(param_0, 0xC);
        return 0;
    case 8:
        if (param_1 == 0x11) {
            func_808009D8_chhillbilly(param_0, 0x78A, 0);
            func_801020DC(param_0, 0);
        }
        ((u8 *)param_0->unk0)[0x2A] &= ~0x20;
        return 1;
    case 9:
        if (((ActorFlags64 *)((u8 *)param_0 + 0x64))->unk64_29) {
            _sucoaster_entrypoint_10(param_0, 2);
            return 0;
        }
        return 1;
    }
    return 0;
}

void func_80800894_chhillbilly(u8 **param_0, s32 param_1)
{
  char new_var2;
  u8 **new_var;
  u8 *temp_v0;
  switch (param_1)
  {
    case 0xC:
      func_80800348_chhillbilly(param_0);
      new_var = param_0;
      func_808009D8_chhillbilly(param_0, 0x789, 0);
      func_8010A570(param_0);
      _sucoaster_entrypoint_10(new_var, 0xC);
      new_var2 = !param_0;
      temp_v0 = *param_0;
      if ((new_var2 && (!param_0)) && new_var2)
    {
    }
      *((u8 *) (((s8 *) temp_v0) + 0x2A)) = (*((u8 *) (((s8 *) temp_v0) + 0x2A))) | 0x20;
      return;

    case 0x15:
      _sucoaster_entrypoint_10(param_0, 0x15);
      _sucoaster_entrypoint_6(param_0, 0x43480000);
      return;

    case 0x16:
      _sucoaster_entrypoint_10(param_0, 0x16);
      return;

  }

}

void func_80800944_chhillbilly(Actor *param_0)
{
    f32 local_1[3];
    f32 local_0[3];
    if (param_0->unk7C_12 && !func_8001210C(1)) {
        func_800EE88C(local_0, _sucoaster_entrypoint_3(param_0));
        func_800EE7F8(local_1, local_0);
        local_1[1] -= 20.0f;
        func_800BBCB8(local_0, local_1, 0x3F800000, 3, D_80800CF0_chhillbilly);
    }
}

void func_808009D8_chhillbilly(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    if (param_2) func_801032B0(param_0, (u16)param_1, param_0->unk0->unk16);
    else func_80103140(param_0, (u16)param_1, param_0->unk0->unk16);
    switch (param_1) {
    case 0x789:
        func_8010A3E8(param_0, 0.75f);
        break;
    case 0x78A:
        func_8010A3E8(param_0, 1.0f);
        break;
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/hillbilly.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800C60_chhillbilly -> int[], D_80800CB4_chhillbilly -> s32[] */
extern void func_80105834();
extern void _sucoaster_entrypoint_1();
extern void _sucoasterhit_entrypoint_0();
extern void func_80107C2C();
u32 D_80800B40_chhillbilly[5] = { 0x160001, 0xE0001, 0xD0001, 0x100001, 0x160001 };
u8 D_80800B54_chhillbilly[84] = { 0x0, 0x0, 0x0, 0x2A, 0x3F, 0xA0, 0x0, 0x0, 0x0, 0x2B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1E, 0x3F, 0xA6, 0x66, 0x66, 0x2, 0x1C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x3F, 0xA6, 0x66, 0x66, 0x2, 0xE, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1C, 0x3F, 0xA6, 0x66, 0x66, 0x1, 0xE, 0x0, 0x0, 0x0, 0x0, 0x0, 0x14, 0x3F, 0x99, 0x99, 0x9A, 0x2, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x3F, 0x99, 0x99, 0x9A, 0x2, 0xA, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x3F, 0xC0, 0x0, 0x0, 0x1, 0x12, 0x0, 0x0 };
u32 D_80800BA8_chhillbilly[46] = { 0x0, 0x0, 0x3F19999A, 0x21D0001, 0x3F19999A, 0x21D0001, 0x3FC00000, 0x21A0001, 0x3F800000, 0x21A0001, 0x3FC00000, 0x21A0001, 0x3FC00000, 0x21A0001, 0x0, 0x0, 0x3FC00000, 0x21A0001, 0x3F99999A, 0x3E10002, 0x3FC00000, 0x21A0001, 0x3F000000, 0x3E20002, 0x3FB33333, 0x21B0002, 0x3FB33333, 0x21B0084, 0x3F19999A, 0x21D0001, 0x3FC00000, 0x21A0020, 0x0, 0x0, 0x3F8CCCCD, 0x21C0001, 0x3FC00000, 0x21A0001, 0x3F666666, 0x2180002, 0x3F8CCCCD, 0x2190002, 0x3F4CCCCD, 0x21A0001, 0x3F8CCCCD, 0x21C0001 };
int D_80800C60_chhillbilly[18] = { 0x1A10150, 0x78A0016, (u32)&D_80800BA8_chhillbilly, (u32)func_80800064_chhillbilly, (u32)func_80105834, (u32)func_80800298_chhillbilly, 0xBB80000, 0x3F800000, 0x0, 0x43050361, (u32)_sucoaster_entrypoint_1, (u32)_sucoasterhit_entrypoint_0, 0x0, (u32)func_8080000C_chhillbilly, (u32)func_80107C2C, -0x7BCDABE3, (u32)func_80800540_chhillbilly, (u32)&D_80800B40_chhillbilly };
u8 D_80800CA8_chhillbilly[12] = { 0x0, 0x13, 0x4, 0xCF, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
s32 D_80800CB4_chhillbilly[15] = { 0x1D078A, 0x270064, 0xC800C8, 0x190001B, -0x31F02BC, 0x150000, 0x66002B, 0x3000400, 0x2CFF6A, 0x12CFF6A, 0x960190, 0x960007, 0x30004, 0x800016, 0x1820000 };
s32 D_80800CF0_chhillbilly[16] = { 0x1D06A4, 0x161182, 0x1BFDA8, -0x257FFD9, -0x2570258, 0x2580258, 0x2D0096, 0xC80022, 0xC0019, 0x0, 0x2B0099, 0xCC0015, 0xB3, 0xB0032, 0x3CFFF6, -0x140000 };
