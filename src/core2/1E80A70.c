#include "core2/1E80A70.h"
extern u32 D_80127650;

extern void func_800E3BFC(f32, f32, f32);
extern void func_800E3C58(f32, f32, f32);
extern void func_800E3900(f32);
extern void func_800E3CE8(void);
extern u8 D_8012762C;
extern s16 D_80127632;
extern u8 D_80127647;
extern f32 D_8012763C;
typedef struct { s16 field0; s16 field2; s16 field4; u8 pad6[2]; f32 field8; u8 padC[4]; s16 field10; u8 field12, field13, field14, field15, field16, field17; u8 pad18[2]; u8 field1A, field1B, field1C; } LocalState;
extern s32 func_8001BD50(f32);
extern s16 D_80127634;
typedef struct { u8 pad0[0x10]; s16 unk10; u8 pad12; u8 unk13; u8 pad14; u8 unk15; u8 unk16; u8 pad17; u8 unk18; } G_A7A6C;
extern f32 D_80127638;
extern s32 D_8011A418;
extern s32 D_8011A3F8[];
extern void func_80015E80(s32, s32 *);
extern void func_80015F28(s32, s32 *);
extern void func_80015FFC(s32, s32 *);
extern s32 func_80015F84(s32);
extern struct { s32 local_0, local_1, local_2; } D_80127670;
typedef struct { s16 x; s16 y; s16 z; s16 w; } Struct_8011A420;
extern Struct_8011A420 D_8011A420[20];
typedef struct { s32 local_0, local_1; f32 local_2; } SoundA84EC;
extern void func_800158E4(s32);
extern void func_80015CE8(s32, s32);
extern s32 func_8001592C(s32, s32, s32, s32);
extern void func_800C54CC(s32, f32, f32);
extern s32 D_80127678[];
extern void func_800C5464(void);
extern s32 func_800CA334(void);
typedef struct { s32 a; s32 b; s32 c; } T8670;
extern s32 D_801276C4;
extern void func_800E42B4(s32);
typedef struct { s32 local_0; s32 local_1; s32 local_2; } local_type;
extern void func_800CA558(s32, f32, s32);
extern void func_800C5668(s32, s32);
void func_800A7A18();
void func_800A7A6C();
void func_800A7A90();
void func_800A861C();
int func_800A8670();
void func_800A8710();
s32 func_800A8BD4();

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    s16 mapValue;
    u8 unk12;
    s8 entranceIndex;
    s32 unk14;
    s8 unk18;
    s8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
} D_80127630_unk;
extern s32 D_8011A3F0;
extern s32 D_8011A3F4;

typedef union {
    LocalState LocalState;
    D_80127630_unk D_80127630_unk;
    G_A7A6C G_A7A6C;
    u8 arr[1];
} Union_D_80127630;
extern Union_D_80127630 D_80127630;
extern s32 D_80127658;
extern s32 D_80127674;
extern void* D_801276BC;
typedef struct
{
    s32 unk0, unk4;
    f32 unk8;
} unk_D_80127688;
extern unk_D_80127688 D_80127688[];

s32* func_800A7180(void)
{
    return &D_80127658;
}

void func_800A718C(void) {
    func_800E3BFC(0.0f, 0.0f, 0.0f);
    func_800E3C58(-30.0f, 30.0f, 0.0f);
    func_800E3900(6e+03f);
    func_800E3CE8();
}

int func_800A71E0()
{
  s32 local_0;
  func_800D58CC();
  func_8001A570();
  func_8001B840();
  for (local_0 = 0; local_0 < 0xf; local_0++)
  {
    func_8001B518(1);
    func_800DF874();
    _cosectionstor_entrypoint_2();
    func_800C9484();
    func_800B5E3C();
    func_800D58AC();
    func_800E4C7C();
    func_800CA174();
    func_800FCD5C();
    func_800A9D00();
    func_800C9484();
    func_800B4380();
    func_8008BA5C();
    func_800DA1E0();
    func_800D15CC();
  }

}

void func_800A72A4(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s32 local_0;
    s32 local_1;

    local_0 = (s32) D_8012762C;
    local_1 = _gcsectionDll_entrypoint_4();
    func_800E96E0();
    _gcsectionDll_entrypoint_1(1);
    if ((param_3 != 0) || (param_2 != 0) || (local_1 != local_0)) {
        _gclevel_entrypoint_1();
        if (param_3 != 0) {
            _gcgame_entrypoint_1();
            _gcgame_entrypoint_0(1);
        }
        _gclevel_entrypoint_0(param_0, param_1);
    }
    _gcsectionDll_entrypoint_0(param_0, param_1);
    func_801101C0();
    func_800A8D70(param_0, param_1);
    func_80081724();
    func_800EA0CC(param_0, param_1, 0);
    func_800A718C();
}

int func_800A7380(s32 param_0)
{
  func_800EA0A8();
  func_800A8F68();
  func_800C2AB8();
  func_800FB968();
  func_8001A2B0();
  func_800D6C64();
  func_800D58CC();
  func_8008B768();
  func_80081724();
  if (param_0 != 0)
  {
    func_800A71E0();
  }
}

void func_800A8CCC();

void func_800A8BA8();

s32 func_800A89F8();

void func_800A73F4(s32 param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  local_0 = *((s32 *) (((s8 *) (&D_80127658)) + 4));
  local_1 = *((s32 *) (((s8 *) (&D_80127658)) + 8));
  func_800A8670();
  func_800A9378();
  func_800F5184();
  func_800A8BA8(&D_80127658, param_1);
  if (func_800A8BD4(&D_80127658, -1, param_1) != 0)
  {
    do
    {
      func_800E9F20(func_800A89F8(), param_1);
    }
    while (func_800A8BD4(&D_80127658, -1, param_1) != 0);
  }
  func_800A8CCC(&D_80127658, param_1);
  if (D_80127632 == 5)
  {
    func_800A9AA4(&D_80127658);
  }
  if (func_800EA358() != 0)
  {
    func_800EB51C(3, &D_80127658);
  }
  func_800C0984(&D_80127658);
  func_800C9358(&D_80127658, param_1);
  func_800C0130(&D_80127658);
  if (func_800EA358() != 0)
  {
    func_800EB51C(4, &D_80127658);
  }
  func_800FA508(&D_80127658);
  func_800B7448(&D_80127658);
  func_800C940C(&D_80127658, param_1);
  func_800E7EF4(&D_80127658);
  osWritebackDCache(local_0, (((s32) ((*((s32 *) (((s8 *) (&D_80127658)) + 4))) - local_0)) >> 6) << 6);
  osWritebackDCache(local_1, (((s32) ((*((s32 *) (((s8 *) (&D_80127658)) + 8))) - local_1)) >> 4) * 0x10);
  func_800F51A8();
  func_800D36A8();
  func_800FFC90();
  func_800A89BC(((((s32) ((*((s32 *) (((s8 *) (&D_80127658)) + 8))) - local_1)) >> 4) * 0x10) * 0);
}

void func_800A7584(param_0, param_1) s32 param_0; s32 param_1;
{
  D_80127630.arr[0x1a] = param_0 + 1;
  D_80127630.arr[0x1b] = param_1;
}

void func_800A759C(s32 param_0, s32 param_1)
{
    /* HEADER DEPENDENCY: also push core2/1E80A70.h; the second argument is s32. */
    s32 local_0;
    local_0 = D_80127632;
    if ((D_80127632 == 3 && param_0 != 4) || (D_80127632 == 4 && param_0 != 3)) func_800C9B84();
    if (D_80127632 == 4 && param_0 != 4) func_800C0920();
    if (D_80127632 == 5) func_800A9AF8();
    D_80127632 = param_0;
    switch (D_80127632) {
    case 2: func_800EA148(3); break;
    case 5: func_800A9998();
    case 3:
        if (local_0 != 4) func_800EA148(2);
        if (param_1 && !D_80127647) func_800C9598();
        D_8012763C = 0.0f;
        break;
    case 4:
        func_800EA334(0);
        func_8001608C();
        func_800C08F8();
        break;
    }
}

void func_800A76F4(s32 param_0)
{
    /* HEADER DEPENDENCY: also push core2/1E80A70.h; A759C and A76F4 use s32 arguments. */
    s32 local_0,local_1,local_2,local_3,local_4,local_5;
    func_800FB968();
    _glintrosyncDll_entrypoint_0(D_80127630.LocalState.field10);
    func_8001A2B0();
    local_0 = D_80127630.LocalState.field16;
    local_1 = D_80127630.LocalState.field15;
    local_2 = D_80127630.LocalState.field14;
    local_3 = D_80127630.LocalState.field10;
    local_4 = D_80127630.LocalState.field13;
    local_5 = D_80127630.LocalState.field0;
    D_80127630.LocalState.field16 = 0;
    D_80127630.LocalState.field15 = 0;
    D_80127630.LocalState.field14 = 0;
    D_80127630.LocalState.field10 = 0;
    D_80127630.LocalState.field13 = 0;
    func_800A759C(2,0);
    D_80127630.LocalState.field1C = param_0;
    func_800A5CF0(0);
    if (!(func_800DA9E4(0x647,0) && _gcsectionDll_entrypoint_4(D_80127630.LocalState.field10) != D_8012762C) && !func_800DA298(0x650))
        _cosectionstor_entrypoint_3(func_800EA05C());
    func_800A7380(1);
    func_800A72A4(local_3,local_4,local_1,local_0);
    func_800A5CF0(1);
    func_800A5C94();
    func_80081724();
    _glintrosyncDll_entrypoint_1();
    D_80127630.LocalState.field0 = local_5;
    D_80127630.LocalState.field1C = 2;
    func_800A759C(param_0,local_2);
    func_80015768();
}

void func_800A7FD4();

void func_800A7840(s32 param_0) {
    s32 sp1C;
    s32 sp18;

    func_8001A4B8(((u32 *) &D_80127658));
    if (D_80127634 != 0) {
        func_8001A4B8(((u32 *) &D_80127658));
    }
    sp1C = ((u32) D_80127658);
    func_800A73F4(func_80014F58(), param_0);
    if (D_80127634 == 0) {
        sp18 = ((u32) D_80127658);
        func_80015410();
        if (D_80127650 == 0) {
            if (func_8001BD50(0.4f) != 0) {
                func_800A7FD4();
            }
        }
        func_800E82EC();
        func_8001A270(sp1C, sp18);
    }
    func_80015878();
    func_800E4628();
    D_80127634 = 0;
    D_80127650 = 0;
}

void func_800A791C(s32 arg0, s32 arg1, s32 arg2)
{
    func_800A79D4(arg0, arg1);
    func_800A7A90(arg2);
    func_800A7B18(1U);
}

int func_800A794C(s32 param_0, s32 param_1, s32 param_2)
{
  func_800FE8EC();
  func_800A7A18(param_0, param_1);
  func_800A7A90(param_2);
  func_800A7B18(1);
}

void func_800A7990(s32 param_0, s32 param_1, s32 param_2)
{
  func_800FE8EC();
  func_800A7A6C(param_0, param_1);
  func_800A7A90(param_2);
  func_800A7B18(1);
}

void func_800A79D4(s32 param_0, s32 param_1) {
    func_800FE4E4();
    *(u8*)((char*)&D_80127630 + 0x16) = 1;
    *(u8*)((char*)&D_80127630 + 0x15) = 0;
    *(s16*)((char*)&D_80127630 + 0x10) = param_0;
    *(u8*)((char*)&D_80127630 + 0x13) = param_1;
}

void func_800A7A18(param_0, param_1) s32 param_0; s32 param_1;
{
    func_800FE8EC();
    *(u8*)((char*)((u8 *) D_80127630.arr) + 0x16) = 0;
    *(u8*)((char*)((u8 *) D_80127630.arr) + 0x15) = 1;
    *(s16*)((char*)((u8 *) D_80127630.arr) + 0x10) = param_0;
    *(u8*)((char*)((u8 *) D_80127630.arr) + 0x13) = param_1;
}

void func_800A7A5C(void) 
{
    D_80127630.D_80127630_unk.unk18 = 1;
}
void func_800A7A6C(param_0, param_1) s32 param_0; s32 param_1; {
    D_80127630.G_A7A6C.unk15 = D_80127630.G_A7A6C.unk18;
    D_80127630.G_A7A6C.unk16 = 0;
    D_80127630.G_A7A6C.unk10 = param_0;
    D_80127630.G_A7A6C.unk13 = param_1;
    D_80127630.G_A7A6C.unk18 = 0;
}

void func_800A7A90(param_0) s32 param_0;
{
  D_80127630.arr[0x14] = param_0;
  D_80127630.arr[0x17] = 0;
  if (param_0 != 0 && func_800C9510() == 0)
  {
    func_800C9610();
  }
}

void func_800A7AD4(s32 param_0, s32 param_1)
{
  ((u8*)((s32 *) D_80127630.arr))[0x14] = (u8)param_0;
  ((u8*)((s32 *) D_80127630.arr))[0x17] = (u8)param_1;
  if (param_0 != 0 && !func_800C9510())
  {
    func_800C964C(param_1);
  }
}

//Set Warp Bit To On
void func_800A7B18(u32 warpVal)
{
    D_80127630.D_80127630_unk.unk12 = warpVal;
}

int func_800A7B24()
{
  func_800A759C(2, 0);
  func_80013430();
  func_800B5DF4();
  func_800CA060();
  func_800DF35C();
  func_800A7380(0);
  _gcsectionDll_entrypoint_1(0);
  _gclevel_entrypoint_1();
  _gcgame_entrypoint_1();
  func_8008B64C();
  func_800FB908();
  func_800C2A90();
  func_800A8710();
  func_800E4290();
  _glcutDll_entrypoint_2();
}

void func_800A7BB8(s32 param_0) {
  func_800A5CF0(1);
  D_80127630.LocalState.field12 = 0;
  D_80127630.LocalState.field10 = D_80127630.LocalState.field13 = D_80127630.LocalState.field14 = D_80127630.LocalState.field17 = D_80127630.LocalState.field15 = D_80127630.LocalState.field16 = 0;
  D_80127630.LocalState.field1A = 0;
  D_80127630.LocalState.field1B = 0;
  D_80127630.LocalState.field4 = 0;
  func_800A8240();
  func_800DA238();
  func_800DA268();
  _glglobaldata_entrypoint_0();
  _glglobalsettings_entrypoint_1();
  _glgamedata_entrypoint_0();
  func_800D3970();
  func_800E4278();
  func_800A861C();
  func_800C2A08();
  func_800FB808();
  _glcutDll_entrypoint_3();
  func_800CA098();
  func_800D34A0();
  func_800B5DD4();
  func_800133A0();
  func_800DF38C();
  func_8008B610();
  func_800DC310();
  func_8001A290();
  func_800D8F84();
  _gsattract_entrypoint_4();
  func_800EBB5C();
  _gcgame_entrypoint_0(0);
  D_80127630.LocalState.field2 = 2;
  D_80127630.LocalState.field8 = 0.0f;
  func_800D8FA0(0);
  _gclevel_entrypoint_0(param_0, 0);
  _gcsectionDll_entrypoint_0(param_0, 0);
  func_800A71E0();
  func_800A72A4(param_0, 0, 0, 0);
  D_80127630.LocalState.field0 = 0;
  func_800A759C(3, 1);
}

int func_800A7D30()
{
  if (D_80127638 == 0)
  {
    func_800D8FA0(0);
  }
  else
  {
    func_800D8FA0(func_80014F4C() | 0);
  }
}

s32 func_800A7D84(void)
{
    s32 sp1C;
    s32 temp_v0;

    D_80127630.D_80127630_unk.unk8 += func_800D8FF8();


    if (func_800C9510() == 0)
    {

        temp_v0 = D_80127630.D_80127630_unk.unk12;
        D_80127630.D_80127630_unk.unk12 = 0U;
        if (temp_v0 != 0)
        {
            switch (temp_v0)
            {
            case 1:
                func_800A76F4(3);
                return 0;
            case 2:
                func_800A76F4(D_80127630.D_80127630_unk.unk2);
                return 0;
            case 3:
                func_800A9924(D_80127630.D_80127630_unk.mapValue, D_80127630.D_80127630_unk.entranceIndex);
                func_800A76F4(5);
                return 0;
            }
        }
        temp_v0 = D_80127630.D_80127630_unk.unk1A;
    }

    if (D_80127630.D_80127630_unk.unk1A != 0)
    {
        func_800A759C(D_80127630.D_80127630_unk.unk1A - 1, D_80127630.D_80127630_unk.unk1B);
        D_80127630.D_80127630_unk.unk1A = 0U;
    }
    sp1C = func_800EA170();

    if ((D_8011A3F4 != 0) && (D_8011A3F0 == 0))
    {
        func_800A8278();
    }
    func_800C7900();
    func_800C427C();
    func_800FB968();
    switch (D_80127630.D_80127630_unk.unk2)
    {
    case 5:
        func_800A9A14();
        break;
    case 3:
        D_80127630.D_80127630_unk.unkC += func_800D8FF8();
        if ((0.6f < D_80127630.D_80127630_unk.unkC) && (func_800C0A34() != 0))
        {
            func_800A759C(4, 0U);
        }
        else if (sp1C == 0)
        {
            func_800A759C(3, 1U);
        }
        break;
    case 4:
        if (func_800C0948() != 0)
        {
            func_800EA334(1);
            func_800EA34C(1);
            func_800A759C(3, 0U);
            func_800FFC14();
            func_800F8850();
        }
    }
    if (func_800A819C() != 0)
    {
        func_800CA0A8();
    }
    func_800C92A8();
    return 1;

}

void func_800A7FB4()
{
    func_800A7584();
}



void func_8001B84C(void);
void defragment_overlays(void);
void func_801015C8(void);
void func_80017840(void);
void func_800D8674(void);
void func_800B5A6C(void);
void func_800A5654(void);
void func_800A95C4(void);
void func_800F86D8(void);
void func_800F91EC(void);
void func_800B562C(void);
void func_800BF58C(void);
void func_800BD600(void);
void func_800CCFEC(void);
void func_800A5D6C(void);
void func_8010E030(void);
void func_800C075C(void);
void func_800C08C0(void);
void func_801005B8(void);
void func_800D6D68(void);
void func_80100E54(void);
void func_800BFFF4(void);
void func_800C9074(void);
void func_800DBB64(void);
void func_800E8B3C(void);
void func_800A86D8(void);
void func_800EE670(void);
void func_800ABA20(void);
void func_800FA608(void);
void func_800E8A20(void);
void func_800EB7A8(void);
void func_800D88C0(void);
void func_800FFE08(void);
void func_8001B858(void);

// do_tidy
void func_800A7FD4(void) {
    D_80127650 = 1;
    func_8001B84C();
    func_8001B840();
    defragment_overlays();
    func_8001B518(0);
    func_801015C8();
    func_80017840();
    func_800D8674();
    func_8008BA5C();
    func_800B5A6C();
    func_800A5654();
    func_800DF874();
    func_800A95C4();
    func_800F86D8();
    func_800F91EC();
    func_800B562C();
    func_800BF58C();
    func_800BD600();
    func_800CCFEC();
    func_800A5D6C();
    func_800B5E3C();
    func_800DA1E0();
    func_800D15CC();
    func_8010E030();
    func_800C075C();
    if (D_80127630.D_80127630_unk.unk2 == 4) {
        func_800C08C0();
    }
    func_801005B8();
    func_800D6D68();
    func_80100E54();
    func_800BFFF4();
    func_800C9074();
    func_800DBB64();
    func_800E8B3C();
    func_800A86D8();
    func_800EE670();
    func_800ABA20();
    func_800FA608();
    func_800E8A20();
    func_800A9D00();
    func_800C9484();
    func_800B4380();
    func_800EB7A8();
    func_800D88C0();
    func_800FFE08();
    func_8001B858();
}

void func_800A8168(void) {
    D_80127630.D_80127630_unk.unk4 = 1;
}

s16 func_800A8178(void) {
    return D_80127630.D_80127630_unk.unk4;
}

s16 func_800A8184(void) {
    return D_80127630.D_80127630_unk.unk2;
}

u8 func_800A8190(void) {
    return D_80127630.D_80127630_unk.unk1C;
}

int func_800A819C(void) {
    return D_80127630.D_80127630_unk.unk2 == 3 || D_80127630.D_80127630_unk.unk2 == 5;
}

int func_800A81C4(void) {
    s32 a, b;
    if (D_80127630.D_80127630_unk.mapValue == 0) {
        return 0;
    }
    a = _gcsectionDll_entrypoint_4(D_80127630.D_80127630_unk.mapValue);
    b = _gcsectionDll_entrypoint_4(func_800EA05C());
    return b != a && D_80127630.D_80127630_unk.unk6 == 0;
}

void func_800A8230(void) {
    D_80127630.D_80127630_unk.unk6 = 1;
}

void func_800A8240(void) {
    D_80127630.D_80127630_unk.unk6 = 0;
}

s16 func_800A824C(void) {
    return D_80127630.D_80127630_unk.unk6;
}

f32 func_800A8258(void) {
    return D_80127630.D_80127630_unk.unk8;
}

int func_800A8264(void) {
    return D_80127630.D_80127630_unk.unk12 != 0;
}

void func_800A8278(void) {
    s32 i;
    s32 stelle;
    s32 feld[14];

    D_8011A3F4 -= 1;
    func_80015E80(0, feld);
    func_80015F28(0, &feld[6]);
    func_80015FFC(0, &feld[9]);
    feld[13] = func_80015F84(0);
    stelle = D_8011A3F8[D_8011A418];
    if (feld[stelle] == 1) {
        D_8011A418 += 1;
    }
    for (i = 0; i != 0xE; i++) {
        if (i != stelle && feld[i] == 1) {
            D_8011A418 = 0;
            break;
        }
    }
    if (D_8011A3F8[D_8011A418] == -1) {
        D_8011A3F0 = 1;
    }
}

s32 func_800A8380(s32 param_0) {
    
    s32 local_1;
    s32 local_2;

    if (D_80127670.local_2 == 0) {
        local_1 = 1;
    } else {
        local_1 = 7;
    }
    switch (D_80127670.local_0) {
    case 2:
        return local_1 + param_0;
    case 3:
        if (local_1 == 1) return param_0 ? param_0 + 4 : local_1;
        return param_0 ? param_0 * 2 + 2 : local_1;
    case 4:
        return param_0 + 3;
    default:
        return 0;
    }
}

void func_800A8424(s32 param_0, s32 *param_1, s32 *param_2, s32 *param_3, s32 *param_4) {
  *param_1 = ((s32 *) &D_80127670)[3] * D_8011A420[param_0].x;
  if (D_8011A420[param_0].x == 1) (*param_1)++;
  *param_2 = ((s32 *) &D_80127670)[4] * D_8011A420[param_0].y;
  if (D_8011A420[param_0].y != 0) (*param_2)++;
  *param_3 = ((s32 *) &D_80127670)[3] * D_8011A420[param_0].z;
  if (D_8011A420[param_0].z == 1) (*param_3)--;
  *param_4 = ((s32 *) &D_80127670)[4] * D_8011A420[param_0].w;
  if (D_8011A420[param_0].w == 1) (*param_4)--;
}

void func_800A84EC(s32 param_0, u32 param_1) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    if (D_80127688[param_0].unk0 != 0) func_800158E4(D_80127688[param_0].unk0);
    func_800A8424(param_1, &local_0, &local_1, &local_2, &local_3);
    D_80127688[param_0].unk0 = func_8001592C(local_0, local_1, local_2, local_3);
    D_80127688[param_0].unk8 = 40.0f;
    if (D_80127688[param_0].unk4 != 0) {
        func_80015CE8(D_80127688[param_0].unk0, D_80127688[param_0].unk4);
    }
    func_800C54CC(param_0, 40.0f, 1.0f);
}

void func_800A85A8(void)
{
    u32 *var_s1;
    s32 var_s0;

    var_s1 = ((u32 *) D_80127688);
    var_s0 = 0;
    do {
        if (*var_s1 != 0) {
            func_800A84EC(var_s0, func_800A8380(var_s0));
        }
        var_s0 += 1;
        var_s1 += 3;
    } while (var_s0 != 4);
    func_800A84EC(4, 0);
}

void func_800A861C(void)
{
  s32 local_0;
  u32 local_1;
  if (((!((u8 *) D_80127688)) && (!((u8 *) D_80127688))) && (!((u8 *) D_80127688)))
  {
  }
  D_80127678[0] = 0;
  local_0 = func_800CA334();
  local_1 = (u32) ((u8 *) D_80127688);
  *((s32 *) (local_1 + 0x34)) = local_0;
  func_800E42B4(local_0);
  func_800A84EC(4, 0);
  func_800C5464();
  func_800A89BC(4);
}

int func_800A8670()
{
  s32 i;
  for (i = 0; i < 5; i++)
  {
    if (((T8670 *) D_80127688)[i].a != 0 &&((T8670 *) D_80127688)[i].b != 0)
    {
      func_800C54F0(i);
    }
  }
}

void func_800A86D8(void)
{
    if (D_801276BC != 0)
    {
        D_801276BC = func_800CA384(D_801276BC);
    }
}

void func_800A8710(void) {
    s32 i;

    func_800CA364(*(s32 *)((s8 *)((s32 *) D_80127688) + 0x34));
    *(s32 *)((s8 *)((s32 *) D_80127688) + 0x34) = 0;
    for (i = 0; i < 5; i++) {
        if (D_80127688[i].unk0 != 0) {
            func_800158E4(D_80127688[i].unk0);
            D_80127688[i].unk0 = 0;
        }
    }
}

int func_800A877C(s32 param_0)
{
  if (*(int *)(((char *) D_80127688) + param_0 * 12) != 0)
  {
    return 1;
  }
  if (param_0 >= (*((int *) &D_80127670)))
  {
    (*((int *) &D_80127670)) = param_0 + 1;
    func_800A85A8();
  }
  func_800A84EC(param_0, func_800A8380(param_0));
  return 1;
}

s32 func_800A87FC(s32 param_0) {
    s32 local_1;
    if (D_80127688[param_0].unk0 == 0) return 0;
    func_800158E4(D_80127688[param_0].unk0);
    D_80127688[param_0].unk0 = 0;
    D_80127688[param_0].unk4 = 0;
    if (param_0 + 1 == D_80127670.local_0) {
        D_80127670.local_0 = 0;
        for (local_1 = 0; local_1 < 4; local_1++) {
            if (D_80127688[param_0].unk0 != 0) D_80127670.local_0++;
        }
        func_800A85A8();
    }
    if (D_80127670.local_0 == 0) func_800E42B4(D_801276BC);
    return 1;
}

s32 func_800A88C4(s32 param_0, s32 param_1) {
    s32 local_0;
    if (((local_type *) D_80127688)[param_0].local_0 == 0) return 0;
    local_0 = ((local_type *) D_80127688)[param_0].local_1;
    ((local_type *) D_80127688)[param_0].local_1 = param_1;
    func_80015CE8(((local_type *) D_80127688)[param_0].local_0, param_1);
    if (param_0 == D_80127674) func_800E42B4(((local_type *) D_80127688)[param_0].local_1);
    return local_0;
}

s32 func_800A8948(s32 arg0)
{
    s32 temp_v0;

    if (D_80127688[arg0].unk0 == 0)
    {
        return 0;
    }
    temp_v0 = D_80127688[arg0].unk4;
    D_80127688[arg0].unk4 = 0;
    return temp_v0;
}

s32 func_800A8984(s32 arg0) 
{
    return D_80127688[arg0].unk4;
}

s32 func_800A89A0(s32 arg0) 
{
    return D_80127688[arg0].unk0;
}

void func_800A89BC(s32 arg0)
{
    D_80127674 = arg0;
    func_800E42B4(D_80127688[arg0].unk4);
}

s32 func_800A89F8()
{
    return D_80127674;
}

void func_800A8A04(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    func_80015CC0(D_80127688[arg0].unk0, arg1, arg2, arg3, arg4);
}

int func_800A8A44(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
  u32 local_0;
  local_0 = func_800A8380(param_0);
  func_800A8424(local_0 | 0, param_1, param_2, param_3, param_4);
}

void func_800A8A88(s32 param_0, f32 param_1)
{
  s32 temp_a2;
  u8 *temp_v0;
  temp_v0 = (param_0 * 0xC) + (((u8 *) D_80127688));
  *((f32 *) (((s8 *) temp_v0) + 8)) = param_1;
  temp_a2 = *((s32 *) (((s8 *) temp_v0) + 4));
  if (temp_a2 != 0)
  {
    func_800CA558(temp_a2, param_1, *((s32 *) (((s8 *) temp_v0) + 4)));
  }
}

f32 func_800A8AD4(s32 arg0) 
{
    return D_80127688[arg0].unk8;
}

void func_800A8AF0(s32 arg0)
{
    func_80015D14(D_80127688[arg0].unk0);
}

void func_800A8B24(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_5;

    local_5 = *(s32*)((char*)((s32 *) D_80127688) + (D_80127674 * 0xC));
    func_80015CC0(local_5, &local_0, &local_1, &local_2, &local_3);
    func_800E7FB0(local_0, local_1, local_2, local_3);
    func_800E7EC0(param_0);
    func_800157EC(local_5, param_0);
}

void func_800A8BA8(Gfx** arg0, s32 arg1)
{
    D_80127674 = -1;
    func_800E7E70(arg0);
}

s32 func_800A8BD4(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    if (param_1 >= 0) D_80127670.local_1 = param_1 - 1;
    if (D_80127670.local_1 >= 0 && D_80127688[D_80127670.local_1].unk4 != 0) {
        func_800C5668(D_80127670.local_1, param_0);
    }
    for (D_80127670.local_1++; D_80127670.local_1 < 4; D_80127670.local_1++) {
        if (D_80127688[D_80127670.local_1].unk0 != 0) break;
    }
    if (D_80127670.local_1 >= 4) return 0;
    func_800A89BC(D_80127670.local_1);
    func_800A8B24(param_0, param_2);
    return 1;
}

void func_800A8CCC(s32 arg0, s32 arg1)
{
    func_800A89BC(4);
    func_800A8B24(arg0, arg1);
}

void func_800A8D00(s32 param_0, s32 param_1)
{
    if ((param_0 != (((s32 *) &D_80127670)[3] << 1)) || (param_1 != (((s32 *) &D_80127670)[4] << 1)))
    {
        ((s32 *) &D_80127670)[3] = param_0 / 2;
        ((s32 *) &D_80127670)[4] = param_1 / 2;
        func_800A85A8();
    }
}
