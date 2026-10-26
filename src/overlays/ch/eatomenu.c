#include "common.h"

extern void *D_8080089C_chcheatomenu;
typedef struct { s16 a; s16 b; s16 c; } Opt6;
extern Opt6 D_808008E4_chcheatomenu;
extern Opt6 D_808008EC_chcheatomenu;
extern Opt6 D_808008F4_chcheatomenu;
extern u8 _gcnewoption_entrypoint_35[];
extern u8 _gcnewoption_entrypoint_15[];
extern u8 D_80800880_chcheatomenu[];
extern u8 D_80800890_chcheatomenu[];
extern void _capod_entrypoint_3(int, void *);
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern void _gcnewoption_entrypoint_40(void *, s32, s32, s32, f32, f32);
int func_8080052C_chcheatomenu();
void func_8080058C_chcheatomenu();
int func_80800668_chcheatomenu();
void func_80800720_chcheatomenu();
void func_808007B8_chcheatomenu();
s32 func_80800800_chcheatomenu();
void func_80800364_chcheatomenu();

int chcheatomenu_entrypoint_0()
{
  return &D_8080089C_chcheatomenu;
}

void func_8080000C_chcheatomenu(s32 arg0) 
{
}
void func_80800014_chcheatomenu(void *param_0)
{
    s32 local_0;

    local_0 = (u32)(*(u16 *)((char *)param_0 + 0x72)) >> 10;
    switch (local_0)
    {
        case 1:
            func_8080058C_chcheatomenu(param_0);
            return;

        case 3:
            func_80800668_chcheatomenu(param_0);
            func_80800720_chcheatomenu(param_0);
            return;

        case 4:
            _gcnewoption_entrypoint_0(func_80100094(param_0, 0));
            return;

        case 5:
            _gcnewoption_entrypoint_6(param_0, 0);
            func_808007B8_chcheatomenu(param_0);
            func_80090708(0);
            func_80101FDC(param_0, 1);
            return;
    }
}

s32 func_808000D4_chcheatomenu(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x2E:
        func_80101FDC(param_0, 1);
        func_808007B8_chcheatomenu(param_0);
        break;
    case 0x20:
        func_8080052C_chcheatomenu(param_0, func_80101080(), ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_80800150_chcheatomenu(s32 param_0, s32 param_1)
{
    if ((u32)(((u16 *)param_0)[0x39]) >> 0xA == 4) {
        _gcnewoption_entrypoint_1(func_80100094(param_0, 0), param_1);
    }
}

void func_80800194_chcheatomenu(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s32 i;
    s32 count;
    s32 pad;
    Opt6 local_0;
    Opt6 local_1;
    Opt6 local_2;

    count = 0;
    i = 1;
    do {
        if (func_800D3E14(i) || func_800D3DD0(i)) {
            if (count == param_2) break;
            count++;
        }
        i++;
    } while (i != 13);
    if (_gcnewoption_entrypoint_17((*(s32 *)&param_1), param_2)) {
        local_0 = D_808008E4_chcheatomenu;
        count = i - 1;
        _gcnewoption_entrypoint_13(param_1, param_2, &local_0);
        _gcnewoption_entrypoint_12(param_1, param_2, (s16)(count * 3 + 4));
        func_800D3F58(count + 1, 1);
    } else if (_gcnewoption_entrypoint_18(param_1, param_2)) {
        local_1 = D_808008EC_chcheatomenu;
        count = i - 1;
        _gcnewoption_entrypoint_13(param_1, param_2, &local_1);
        _gcnewoption_entrypoint_12(param_1, param_2, (s16)(count * 3 + 5));
        func_800D3F58(count + 1, 0);
    } else if (_gcnewoption_entrypoint_19(param_1, param_2)) {
        local_2 = D_808008F4_chcheatomenu;
        _gcnewoption_entrypoint_13(param_1, param_2, &local_2);
        _gcnewoption_entrypoint_12(param_1, param_2, (s16)(i * 3 + 3));
    }
    if (param_3) {
        func_800D3FD4(1);
    }
}

void func_80800364_chcheatomenu(param_0, param_1) Actor *param_0; void *param_1;
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800F1418(5, func_80800800_chcheatomenu());
    _gcnewoption_entrypoint_14(param_1, 0, 1, 3, 4.0f);
    _gcnewoption_entrypoint_40(param_1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(param_1, 0x37);
    for (local_1 = 0; local_1 < local_0; local_1++) _gcnewoption_entrypoint_31(param_1, local_1, 0x37);
}

void func_80800428_chcheatomenu(param_0, param_1) s32 param_0; s32 param_1; {
    s32 var_s0;
    s32 var_s1;
    s32 temp;

    var_s0 = 0;
    var_s1 = 1;
    do {
        temp = func_800D3FC0(var_s1);
        temp = (temp << 16) >> 16;
        _gcnewoption_entrypoint_31(param_1, var_s0, temp);
        if (func_800D3E14(var_s1) != 0) {
            if (func_800D3E40(var_s1) != 0) {
                _gcnewoption_entrypoint_21(param_1, var_s0);
            } else {
                _gcnewoption_entrypoint_22(param_1, var_s0);
            }
            func_80800194_chcheatomenu(param_0, param_1, var_s0, 0);
            goto block_8;
        }
        if (func_800D3DD0(var_s1) != 0) {
            _gcnewoption_entrypoint_23(param_1, var_s0);
            func_80800194_chcheatomenu(param_0, param_1, var_s0, 0);
block_8:
            var_s0 += 1;
        }
        var_s1 += 1;
    } while (var_s1 != 0xD);
}

int func_8080052C_chcheatomenu(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s32 param_3;
{
  s32 new_var;
  new_var = param_0;
  switch (param_3)
  {
    case 1:
      func_80800194_chcheatomenu(new_var, param_1, param_2, 1);
      break;

    case 0:
      func_80800428_chcheatomenu();
      break;

    new_var = 0;
    case 2:
      func_80101FDC(new_var, 5);

 if (1) { }
  }

}

void func_8080058C_chcheatomenu(param_0) s32 *param_0;
{
  s32 var_v0;

  if (func_80090178(0xFFFEFFFF) != 0)
  {
    if (func_800DA298(0xD3) == 0)
    {
      var_v0 = _subaddiedialog_entrypoint_2(param_0 + 1, 0xC8, 0x32, 0);
    }
    else
    {
      var_v0 = _subaddiedialog_entrypoint_5(param_0 + 1, 0xC8, 0x32, 0);
    }
    if (var_v0 != 0)
    {
      func_800DA544(0xD3);
      if (func_80800800_chcheatomenu() == 0)
      {
        _subaddiedialog_entrypoint_11(*param_0, 0x1149, 0xF, param_0 + 1, 0x37);
        func_80101FDC(param_0, 2);
        func_80800720_chcheatomenu(param_0);
        return;
      }
      func_80101FDC(param_0, 3);
    }
  }
}

int func_80800668_chcheatomenu(param_0) s32 param_0;
{
  f32 local_2[2];
  s32 local_4;
  s32 local_0;
  local_4 = func_80800800_chcheatomenu();
  _gcnewoption_entrypoint_4(param_0, 0, &_gcnewoption_entrypoint_15, &_gcnewoption_entrypoint_35, 0x1848);
  local_0 = func_80100094(param_0, 0);
  _gcnewoption_entrypoint_8(local_0, func_800F1418(5, local_4));
  _gcnewoption_entrypoint_9(local_0, local_4);
  _gcnewoption_entrypoint_10(local_0, 1);
  func_80800364_chcheatomenu(param_0, local_0);
  _gcnewoption_entrypoint_11(local_0);
  func_80101FDC(param_0, 4);
  func_80090708(2);
}

void func_80800720_chcheatomenu(param_0) Actor *param_0;
{
    if (!param_0->unk6C_0) {
        _capod_entrypoint_2(param_0->unk0, 0x19, 0);
        _capod_entrypoint_8(1);
        _capod_entrypoint_9(0, D_80800880_chcheatomenu);
        _capod_entrypoint_10(0, D_80800890_chcheatomenu);
        _capod_entrypoint_11(0, param_0->rotation);
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_7(3, 0);
        param_0->unk6C_0 = 1;
    }
}

void func_808007B8_chcheatomenu(param_0) void *param_0;
{

  if (((s32) ((s32 *) (((char *) param_0) + 0x6C))[0]) & 0x1FF)
  {
    _capod_entrypoint_3(0, param_0);
    *((u16 *) (((char *) param_0) + 0x6E)) &= ~0x1FF;
  }
}

s32 func_80800800_chcheatomenu(void)
{
    s32 local_0;
    s32 local_1 = 0;

    for (local_0 = 1; local_0 < 13; local_0++) {
        if (func_800D3DD0(local_0) || func_800D3E14(local_0)) {
            local_1++;
        }
    }
    return local_1;
}
