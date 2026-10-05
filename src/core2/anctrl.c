#include "core2/anctrl.h"

extern f32 func_800D8FF8(void);
extern f32 _glintrosyncDll_entrypoint_5(void);
typedef struct { u32 local_0 : 25; u32 local_1 : 1; u32 local_2 : 6; } local_type_8008AA0C;
extern f32 func_8008C0D0(s32);
extern void func_8008C1F0(s32, s32);
typedef struct {u8 local_0[0x18]; u32 local_1:24; u32 local_2:1; u32 local_3:7;} local_type_8008AAC0;
extern f32 func_8008C0C8(void *);
extern void func_8008C1C0(void *, f32);
typedef struct { f32 unk0; f32 unk4; f32 unk8; u8 padC[0xC]; u16 unk18; u8 unk1A; u8 b7 : 1; u8 rest : 7; } S8008AB84;
typedef struct { u8 pad[0x18]; u32 pad0:24, local_0:1, pad1:7; } LocalState;
typedef struct { char pad[0x1B]; u8 b7 : 1; u8 b6 : 1; u8 default_start : 1; u8 rest : 5; } AcBf_anctrl_reset;
typedef struct { f32 unk0; u8 pad4[0x10]; f32 unk14; u16 unk18; u8 unk1A; u8 b7 : 1; u8 b6 : 1; u32 f5 : 1; u32 rest : 5; u8 unk1C[4]; } S8008AFCC;
typedef struct { u8 local_0[0x18]; u32 local_1:25; u32 local_2:1; u32 local_3:6; } local_type_anctrl_start;
extern void func_8008C0AC(void *);
extern void func_8008C1B8(void *, s32);
extern void func_8008C1E4(void *, f32);
extern void func_8008C270(void *);
typedef struct { f32 unk0; u8 pad4[0x10]; f32 unk14; u16 unk18; u8 unk1A; u8 b7 : 1; u8 b6 : 1; u8 f5 : 1; u8 f34 : 2; u8 f2 : 1; u8 b1 : 1; u8 b0 : 1; } S8008B134;
typedef struct { char pad[0x1B]; u8 bit7 : 1; u8 smooth : 1; u8 rest : 6; } AcBf_anctrl_setSmoothTransition;
extern AssetId func_8008C0C0(void *);
extern u8 unk18[];
typedef struct { f32 timer; u8 pad_4[0x17]; u8 direction:1, pad_1B:7; } LocalAnimCtrl;
extern struct SomeStruct { u32 unk18; };
extern void func_8008C124(void *, s32);
extern s32 func_800E6A00(void);
s32 func_8008AEDC();
void anctrl_setPlaybackType();
void func_8008B188();
void anctrl_setSmoothTransition();
void anctrl_setDuration(AnimCtrl *param_0, f32 param_1);
void func_8008B1C8(AnimCtrl *param_0, f32 param_1);
void anctrl_setSubrange(AnimCtrl *param_0, f32 param_1, f32 param_2);
f32 func_8008B2AC(f32 param_0[3]);
void func_8008B2E8();
void func_8008B518();

f32 func_8008A990(u8 *param_0) {
    u32 local_0;

    local_0 = (u32) (*(s32 *)((char *)param_0 + 0x18) << 0x1B) >> 0x1E;
    switch (local_0) {
    case 0:
        return func_800D8FF8();
    case 1:
        return 0.033333f;
    case 2:
        return _glintrosyncDll_entrypoint_5();
    default:
        return func_800D8FF8();
    }
}

void func_8008AA0C(u8 *param_0)
{
  s32 v0;
  f32 f0;
  u8 *local_0 = param_0;
  if (((local_type_8008AA0C *)(param_0 + 0x18))->local_1)
  {
    if (!local_0)
    {
    }
    v0 = func_8008AEDC();
    f0 = func_8008C0D0(v0);
    if (f0 < 1.0f)
    {
      f0 += func_8008A990(local_0) / (*((f32 *) (((s8 *) local_0) + 0x10)));
      if (f0 >= 1.0f)
      {
        func_8008C1F0(v0, 1);
        f0 = 1.0f;
      }
      func_8008C1E4(v0, f0);
    }
  }
}

void func_8008AAC0(AnimCtrl *param_0) {
    void *local_0;
    f32 local_2;
    f32 local_3;
    local_0 = func_8008AEDC(param_0);
    func_8008AA0C(param_0);
    *(f32 *)param_0 = func_8008C0C8(local_0);
    local_2 = func_8008A990(param_0) / func_8008B2AC(param_0);
    if (!((local_type_8008AAC0 *)param_0)->local_2) local_2 = -local_2;
    local_3 = *(f32 *)param_0 + local_2;
    if (local_3 < 0.0f) local_3 += 1.0f;
    local_3 -= (s32)local_3;
    func_8008C1C0(local_0, local_3);
}

void func_8008AB84(AnimCtrl *param_0) {
    s32 local_0;
    S8008AB84 *p = (S8008AB84 *)param_0;
    s8 _sfpad[12];
    f32 local_1;
    f32 d;
    f32 pos;
    f32 range;
    f32 t;

    local_0 = func_8008AEDC();
    func_8008AA0C(param_0);
    p->unk0 = func_8008C0C8(local_0);
    local_1 = func_8008A990(param_0);
    d = local_1 / func_8008B2AC(param_0);
    if (!p->b7) {
        d = -d;
    }
    pos = p->unk0 + d;
    if (p->unk8 <= pos) {
        range = p->unk8 - p->unk4;
        t = (pos - p->unk4) / range;
        pos = p->unk4 + (t - (s32)t) * range;
    }
    func_8008C1C0(local_0, pos);
}

void func_8008AC4C(u8 *param_0)
{
    s32 local_0;
    f32 local_1;
    f32 local_3;

    local_0 = func_8008AEDC(param_0);
    func_8008AA0C(param_0);
    *((f32 *)param_0) = func_8008C0C8(local_0);
    local_3 = func_8008A990(param_0) / func_8008B2AC(param_0);
    if (!((LocalState *)param_0)->local_0) {
        local_3 = -local_3;
    }
    local_1 = *((f32 *)param_0) + local_3;
    if (local_1 < 0.0f) {
        local_1 = 0.0f;
        anctrl_setPlaybackType((AnimCtrl *)param_0, 3);
    } else if (local_1 > *(f32 *)(param_0 + 8) || local_1 > 0.999999f) {
        if (local_1 > *(f32 *)(param_0 + 8)) local_1 = *(f32 *)(param_0 + 8);
        if (local_1 > 0.999999f) local_1 = 0.999999f;
        anctrl_setPlaybackType((AnimCtrl *)param_0, 3);
    } else {
        local_1 -= (f32)(s32)local_1;
    }
    func_8008C1C0(local_0, local_1);
}

AnimCtrl * func_8008AD80(s32 param_0)
{
  s32 *local_1;

  local_1 = heap_alloc(func_8008C0B8() + 0x1C);
  func_8008B518(local_1, param_0);
  return local_1;
}

void func_8008ADBC(s32 arg0)
{
    func_8008B5E8();
    heap_free(arg0);
}
void func_8008ADE4(u8 *param_0) {
    struct {
        u8 pad[0x18];
        unsigned int pad2 : 29;
        unsigned int f : 1;
        unsigned int pad_bits : 2;
    } *p = (void *)param_0;

    switch (param_0[0x1A]) {
        case 1:
            func_8008AC4C(param_0);
            func_8008C1CC(&param_0[0x1C], p->f);
            break;
        case 2:
            func_8008AAC0(param_0);
            func_8008C1CC(&param_0[0x1C], p->f);
            break;
        case 4:
            func_8008AB84(param_0);
            func_8008C1CC(&param_0[0x1C], p->f);
            break;
        case 3:
            func_8008AA0C(param_0);
            func_8008C1CC(&param_0[0x1C], p->f);
            break;
        case 0:
            break;
    }
}

AnimCtrl* func_8008AEB4(AnimCtrl* arg0)
{
    return defrag(arg0);
}
void anctrl_setIndex(AnimCtrl *param_0, AssetId param_1) {
    *(s16 *)((u8 *)param_0 + 0x18) = param_1;
}

s32 func_8008AEDC(param_0) s32 param_0; {
    return param_0 + 0x1C;
}

int func_8008AEE4(s32 param_0)
{
  func_8008C1D4(param_0 + 0x1C);
}

int func_8008AF04(s32 param_0)
{
  func_8008C1DC(param_0 + 0x1C);
}

void anctrl_reset(AnimCtrl *param_0)
{
    *(u8 *)((char *)param_0 + 0x1A) = 2;
    ((AcBf_anctrl_reset *)param_0)->default_start = 1;
    *(f32 *)((char *)param_0 + 0x0) = 0.0f;
    *(f32 *)((char *)param_0 + 0x14) = 0.0f;
    anctrl_setSmoothTransition(param_0, 1);
    anctrl_setSubrange(param_0, 0, 1.0f);
    anctrl_setDuration(param_0, 2.5678000450134277f);
    func_8008B1C8(param_0, 0.2f);
    func_8008B188(param_0, 1);
    func_8008B2E8(param_0, func_800E6A00() ? 2 : 0);
}

void func_8008AFCC(AnimCtrl *param_0) {
    S8008AFCC *p = (S8008AFCC *)param_0;
    if (p->f5) {
        if (p->b7 == 1) {
            func_8008C1C0(p->unk1C, 0.0f);
        } else {
            func_8008C1C0(p->unk1C, 0.999999f);
        }
    } else {
        func_8008C1C0(p->unk1C, p->unk14);
    }
    p->unk0 = func_8008C0C8(p->unk1C);
}

void anctrl_start(AnimCtrl *param_0) {
    if (((local_type_anctrl_start *)param_0)->local_2 && func_8008C0C0((u8 *)param_0 + 0x1C)) {
        func_8008C0AC((u8 *)param_0 + 0x1C);
        func_8008C1B8((u8 *)param_0 + 0x1C, *(s16 *)((u8 *)param_0 + 0x18));
        func_8008AFCC(param_0);
        func_8008C1E4((u8 *)param_0 + 0x1C, 0.0f);
    } else {
        func_8008C270((u8 *)param_0 + 0x1C);
        func_8008C1B8((u8 *)param_0 + 0x1C, *(s16 *)((u8 *)param_0 + 0x18));
        func_8008AFCC(param_0);
        func_8008C1E4((u8 *)param_0 + 0x1C, 1.0f);
    }
}

void func_8008B10C(AnimCtrl *param_0, f32 param_1) {
    func_8008C1C0((u8 *)param_0 + 0x1C, param_1);
}

void anctrl_setPlaybackType(param_0, param_1) AnimCtrl * param_0; s32 param_1;
{
    S8008B134 *p = (S8008B134 *) param_0;
    p->unk1A = param_1 & 0xFFu;
    switch (param_1)
    {
        case 1:
        case 3:
            p->f2 = 0;
            break;
        case 2:
        case 4:
            p->f2 = 1;
            break;
    }
}

void func_8008B188(param_0, param_1) AnimCtrl * param_0; s32 param_1;
{
  unsigned short new_var;
  unsigned char new_var2;
  new_var2 = param_1;
  *((u8 *) (((char *) param_0) + 0x1B)) = ((*((u8 *) (((char *) param_0) + 0x1B))) & 0xFF7F) | (new_var = new_var2 << 7);
}

void anctrl_setSmoothTransition(param_0, param_1) AnimCtrl * param_0; s32 param_1;
{
    ((AcBf_anctrl_setSmoothTransition *)param_0)->smooth = param_1;
}

void anctrl_setDuration(AnimCtrl *param_0, f32 param_1) {
    *(f32 *)((u8 *)param_0 + 0xC) = param_1;
}

void func_8008B1C8(AnimCtrl *param_0, f32 param_1) {
    *(f32 *)((char *)param_0 + 0x10) = param_1;
}

void anctrl_setSubrange(AnimCtrl *param_0, f32 param_1, f32 param_2) {
    f32 local_1;

    *(f32 *)((char *)param_0 + 0x4) = param_1 - (s32) param_1;
    if (param_2 != 1.0f) {
        *(f32 *)((char *)param_0 + 0x8) = param_2 - (s32) param_2;
    } else {
        *(f32 *)((char *)param_0 + 0x8) = param_2;
    }
}

func_8008B238(f32 param_0[3], f32 *param_1, f32 *param_2){
    *param_1 = param_0[1];
    *param_2 = param_0[2];
}

void anctrl_setStart(AnimCtrl *param_0, f32 param_1)
{
    (*(u8 *)((char *)(param_0) + 27)) &= ~0x20;
    *(f32 *)((char *)param_0 + 0x14) = param_1;
}

AssetId anctrl_getIndex(AnimCtrl *param_0) {
    return func_8008C0C0((u8 *)param_0 + 0x1C);
}

s32 anctrl_getPlaybackType(AnimCtrl *param_0) {
    return *(u8 *)((u8 *)param_0 + 0x1A);
}

s32 func_8008B28C(AnimCtrl *param_0)
{
  u8 *new_var;
  new_var = &((u8 *) param_0)[0x1B];
  return (((((((((*new_var) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) >> 7;
}

u32 func_8008B29C(struct SomeStruct *param_0)
{
  u32 local_0;
  u32 new_var;
  new_var = *((s32 *) (((char *) param_0) + 0x18));
  local_0 = new_var;
  if ((!local_0) && (!local_0))
  {
  }
  local_0 = local_0 << 0x19;
  new_var = local_0 >> 0x1F;
  return new_var;
}

f32 func_8008B2AC(f32 param_0[3]){
    return param_0[3];
}

f32 anctrl_getAnimTimer(AnimCtrl *param_0) {
    return func_8008C0C8((u8 *)param_0 + 0x1C);
}

f32 func_8008B2D4(f32 param_0[3]){
    return param_0[0];
}

func_8008B2DC(f32 *param_0, f32 param_1){
    *param_0 = param_1;
}

void func_8008B2E8(param_0, param_1) AnimCtrl * param_0; s32 param_1;
{
  typedef struct {
    u8 pad_0[0x1B];
    u8 local_0 : 3;
    u8 local_1 : 2;
    u8 local_2 : 3;
  } Struct8008B2E8;

  ((Struct8008B2E8 *)param_0)->local_1 = param_1;
}

int func_8008B304(s32 param_0)
{
  func_8008C038(param_0 + 0x1C);
}

s32 anctrl_isStopped(AnimCtrl *param_0) {
    return anctrl_getPlaybackType(param_0) == 3;
}

int anctrl_isAt(AnimCtrl *param_0, f32 param_1)
{
    f32 local_0;
    local_0 = func_8008C0C8((u8 *)param_0 + 0x1C);
    if (local_0 == ((LocalAnimCtrl *)param_0)->timer) return 0;
    if (((LocalAnimCtrl *)param_0)->direction == 1) {
        if (((LocalAnimCtrl *)param_0)->timer < local_0) {
            return ((LocalAnimCtrl *)param_0)->timer <= param_1 && param_1 < local_0;
        } else {
            return ((LocalAnimCtrl *)param_0)->timer <= param_1 || param_1 < local_0;
        }
    } else {
        if (local_0 < ((LocalAnimCtrl *)param_0)->timer) {
            return param_1 <= ((LocalAnimCtrl *)param_0)->timer && local_0 < param_1;
        } else {
            return param_1 <= ((LocalAnimCtrl *)param_0)->timer || local_0 < param_1;
        }
    }
}

void func_8008B4A8(u8 *param_0, u32 param_1)
{
  int new_var;
  char new_var2;
  param_0[new_var = 0x1B] = (u8) ((param_0[new_var] & 0xFFFB) | ((new_var2 = param_1 * 4) & 4));
  if (!param_0)
  {
  }
}

int func_8008B4C4(param_0)
struct SomeStruct *param_0;
{
  u32 new_var;
  u32 local_0;
  u32 new_var2;
  local_0 = (*((s32 *) (((char *) param_0) + 24))) << 29;
  new_var = local_0;
  ;
  if (((local_0 && local_0) & 0xFFFFFFFF) && local_0)
  {
  }
  local_0 = (0, new_var >> 31);
  return local_0;
}

s32 func_8008B4D4(AnimCtrl *param_0)
{
  func_8008C27C(param_0 + 0x1C);
}

int func_8008B4F4()
{
    return func_8008C0B8() + 0x1C;
}

void func_8008B518(param_0, param_1) AnimCtrl * param_0; s32 param_1;
{
    func_8008C124((u8 *)param_0 + 0x1C, 1);
    ((S8008B134 *)param_0)->unk1A = 0;
    ((S8008B134 *)param_0)->unk18 = 0;
    ((S8008B134 *)param_0)->f5 = 1;
    ((S8008B134 *)param_0)->unk0 = 0.0f;
    ((S8008B134 *)param_0)->unk14 = 0.0f;
    if (func_800E6A00() != 0) {
        ((S8008B134 *)param_0)->f34 = 2;
    } else {
        ((S8008B134 *)param_0)->f34 = 0;
    }
    ((S8008B134 *)param_0)->f2 = 1;
    anctrl_setSubrange(param_0, 0.0f, 1.0f);
    anctrl_setDuration(param_0, 2.1234f);
    func_8008B1C8(param_0, 0.2f);
    anctrl_setSmoothTransition(param_0, 1);
    func_8008B188(param_0, 1);
}

int func_8008B5E8(s32 param_0)
{
  func_8008C0D8(param_0 + 0x1C);
}
