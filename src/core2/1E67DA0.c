#include "core2/1E67DA0.h"
#include "common.h"

#define LOCAL_RECORD (*(local_record **)((u8 *)param_0 + 0xC))
typedef struct {u8 local_0[0x18]; u16 local_1:15; u16 local_2:1;} local_marker_8008E530;
typedef struct {u8 local_0[0x64]; u32 local_1:14; u32 local_2:1; u32 local_3:17; u8 local_4[0x10]; u32 local_5:28; u32 local_6:1; u32 local_7:3;} local_actor;
extern s32 _chbounce_entrypoint_10(Actor *);
extern s32 _glhittableDll_entrypoint_4(s32, Unk80132ED0 *);
extern s32 _glhittableDll_entrypoint_2(s32);
extern s32 _glhittableDll_entrypoint_8(s32);
extern s32 _glhittableDll_entrypoint_3(s32, Unk80132ED0 *, s32);
extern s32 func_800F424C(PlayerState *);
extern void func_800EB210(Unk80132ED0 *, s32, s32);
typedef struct { u8 local_0[8]; void (*local_1)(void); u8 local_2[12]; u32 local_3:16; u32 local_4:11; u32 local_5:5; u8 local_6[12]; u32 local_7:21; u32 local_8:1; u32 local_9:10; } local_marker_8008E618;
typedef struct {local_marker_8008E618 *local_0; u8 local_1[20]; s32 local_2;} local_record;
extern void func_8009C128(PlayerState *, f32 *);
extern local_marker_8008E618 *func_800EBFD4(f32 *, s32, s32);
extern void baflag_clear(PlayerState *, s32);
extern f32 D_80126D08[];
extern u8 D_80126CE0[];
typedef struct { u8 pad_0[0x28]; u32 local_0 : 22; u32 local_1 : 1; u32 local_2 : 9; } local_9;
typedef struct { local_9 *local_0; } local_10;
struct Func_8008E92C_Arg0 { u8 pad0[12]; struct { u8 pad0[24]; s32 unk18; } *unkC; };
extern struct Func_8008E92C_Arg0 *param_0;
typedef struct { u8 pad0[0x28]; u32 f0 : 22; u32 flag : 1; u32 f2 : 9; } S2_8E974;
typedef struct { S2_8E974 *unk0; } S1_8E974;
typedef struct { u8 pad0[0xC]; S1_8E974 *unkC; } S0_8E974;
typedef struct { u8 pad00[0x1A]; u16 id : 11; u16 pad1A : 5; } LocalMarker;
typedef struct { u8 pad00[0x5C]; u8 health[3]; } LocalHealth;
typedef struct { u8 pad00[0x24]; u32 flags; } LocalActorInfo;
extern f32 D_80124B70, D_80124B74;
extern s32 func_800D3948();
extern Actor *func_80106790(LocalMarker *);
extern PlayerState *func_800F53D0(s32);
extern void baflag_set(PlayerState *, s32);
extern s32 func_8009BD44();
extern void func_800A17A8(PlayerState *, s32);
extern s32 func_800A1718(PlayerState *);
extern void func_8009AD14();
extern s32 func_800F0D90();
extern void func_800F76B0();
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern LocalActorInfo *func_80100368(Actor *);
extern void func_801096C8(Actor *, void *);
extern s32 D_80117CAC;
int func_8008ED70();

s32 func_8008E4B0(void) {
    return sizeof(BaUnknownC);
}

s32 *func_8008E4B8(PlayerState *self) {
    s32 i;
    for (i = 0; i < 3; i++) {
        self->unkC->unkC[i] = (s32)func_8009E138(self, i);
    }
    return self->unkC->unkC;
}

void func_8008E530(PlayerState *param_0, Unk80132ED0 *param_1) {
    Actor *local_0;
    s32 local_1;
    if (((local_marker_8008E530 *)param_1)->local_2) {
        local_0 = func_80106790(param_1);
        if (((local_actor *)local_0)->local_2) return;
        if (((local_actor *)local_0)->local_6 && _chbounce_entrypoint_10(local_0)) return;
    }
    local_1 = _glhittableDll_entrypoint_4(**(s32 **)((u8 *)param_0 + 0xC), param_1);
    if (!func_800F424C(param_0) && _glhittableDll_entrypoint_2(local_1) && _glhittableDll_entrypoint_8(local_1)) return;
    if (!_glhittableDll_entrypoint_3(**(s32 **)((u8 *)param_0 + 0xC), param_1, local_1)) {
        func_800EB210(param_1, **(s32 **)((u8 *)param_0 + 0xC), 0);
    }
}

void func_8008E618(PlayerState *param_0) {
    f32 local_0[3];
    func_8009C128(param_0, local_0);
    LOCAL_RECORD->local_0 = func_800EBFD4(local_0, 1, 0);
    LOCAL_RECORD->local_0->local_8 = 1;
    LOCAL_RECORD->local_0->local_1 = func_8008ED70;
    LOCAL_RECORD->local_0->local_4 = *(s32 *)((u8 *)param_0 + 0x184);
    baflag_clear(param_0, 8);
    LOCAL_RECORD->local_2 = -1;
}

void func_8008E6BC(s32 *param_0)
{
  s32 *local_0;
  s32 *local_1;
  s32 *local_2;
  s32 *local_3;
  if (1)
  {
    local_0 = param_0;
    ;
    func_800EBFF4(*(*((s32 **) (param_0 + 3))));
    local_2 = local_0;
 ; *(*((s32 **) (local_2 + 3))) = 0;
  }
}

void func_8008E6F0(PlayerState *param_0)
{
  f32 local_0[3];
  s32 local_4;
  s32 local_5;
  s32 local_6;
  s32 local_1;
  s32 local_7;
  s32 local_2;
  s32 local_8;
  s32 local_3;
  s32 var_s0;
  s32 var_s0_2;
  f32 temp_f0;
  func_8009C128(param_0, local_0);
  func_800EC0EC(local_0, *((u8 **) (*((u8 **) (((char *) param_0) + 0xC)))));
  baflag_clear(param_0, 8);
  if (((local_10 *) *((u8 **) (((char *) param_0) + 0xC)))->local_0->local_1)
  {
    if (func_80091E80(param_0, 8) != 0)
    {
      if (func_800EA068(0x20) == 0)
      {
        if (func_8008DAA8(param_0) == 0)
        {
          var_s0 = func_800F54E4();
          local_2 = func_800F5410(var_s0);
          if (local_2 == 9)
          {
            goto block_16;
          }
          if (local_2 != 0xB)
          {
            if (local_2 == 0x11)
            {
              if (func_800F6D24(var_s0) != 0)
              {
                return;
                if (!param_0)
                {
                }
              }
              goto block_16;
            }
          }
          else
            if (func_800F8B88() == 3)
          {
            if (func_800F6D24(var_s0) != 0)
            {
              return;
            }
            goto block_16;
          }
        }
        else
        {
          goto block_16;
        }
      }
      else
      {
        var_s0 = func_800EA068(8);
        local_1 = func_800EA068(0x4000);
        local_2 = baflag_isTrue(param_0, 0x3B);
        if (((var_s0 != 0) && (local_1 != 0)) && (local_2 != 0))
        {
          _bsfirstp_entrypoint_14(param_0);
        }
        block_16:
        func_800CB840(1, *((s32 **) (((char *) param_0) + 0x184)));

        var_s0 = 0;
        loop_17:
        temp_f0 = func_8009E138(param_0, var_s0);

        if (temp_f0 != 0)
        {
          D_80126D08[var_s0] = temp_f0;
          func_8009E154(param_0, var_s0, (var_s0 * 0xC) + D_80126CE0);
          var_s0 += 1;
          if (var_s0 != 3)
          {
            goto loop_17;
          }
        }
        local_2 = func_800CDBA8(*((u8 **) (*((u8 **) (((char *) param_0) + 0xC)))), D_80126CE0, D_80126D08, var_s0);
        var_s0_2 = 0;
        if (local_2 > 0)
        {
          do
          {
            local_1 = func_800CDFA8(var_s0_2, &local_3);
            *((s32 *) (((char *) *((u8 **) (((char *) param_0) + 0xC))) + 0x18)) = local_3;
            func_8008E530(param_0, local_1);
            var_s0_2 += 1;
          }
          while (var_s0_2 < local_2);
        }
        func_800CB870();
        *((s32 *) (((char *) *((u8 **) (((char *) param_0) + 0xC))) + 0x18)) = -1;
      }
    }
  }
}

s32 func_8008E92C(struct Func_8008E92C_Arg0 *param_0) {
    return param_0->unkC->unk18;
}

s32 func_8008E938(void *param_0) {
    return *(s32 *)(*(u32 *)((u8 *)param_0 + 0xC));
}

void func_8008E944(PlayerState *param_0) {
    u8 *v = *(u8 **)(*(u8 **)((u8 *)param_0 + 0xC));
    *(u8 *)(v + 0x2A) &= ~2;
}

void func_8008E95C(PlayerState *param_0)
{
  u8 *temp_v0;
  temp_v0 = *(*((u8 ***) (((s8 *) param_0) + 0xC)));
  *((u8 *) (((s8 *) temp_v0) + 0x2A)) = (u8) (((*((u8 *) (((s8 *) temp_v0) + 0x2A))) & 0xFFu) | 2);
}

s32 func_8008E974(S0_8E974 *param_0) {
    s32 rv = 0;
    return (param_0->unkC->unk0->flag) ? 1 : rv;
}

func_8008E9A0(s32 param_0, s32 param_1){
    *(s32*)(*(s32*)(param_0 + 0xC) + 0x4) = param_1;
}

s32 func_8008E9AC(s32 param_0)
{
  s32 temp;
  return *((s32 *) ((*((s32 *) (param_0 + 0xC))) + 0x4));
}

int func_8008E9B8(s32 param_0, s32 *param_1)
{
  s32 local_0;
  local_0 = func_8008E4B8(param_0);
  *param_1 = local_0;
  return 3;
}

void func_8008E9E4(LocalMarker *param_0, LocalMarker *param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    Actor *local_4;
    PlayerState *local_5;
    s32 local_6;
    s32 local_7;

    local_6 = (!func_800D3948() || func_800F6774(func_800F54E4())) && !func_800F9184();
    local_1 = _glhittableDll_entrypoint_8(param_2);
    local_2 = 0;
    local_4 = func_80106790(param_1);
    local_3 = param_0->id;
    local_5 = func_800F53D0(local_3);
    if (_glhittableDll_entrypoint_9(param_2)) baflag_set(local_5, 8);
    if ((func_8009BD44(local_5) != 3 && func_800F6C1C(local_3)) || !local_1) {
        local_0 = _glhittableDll_entrypoint_5(param_2);
        if (local_0 > 0 && local_0 < 6) {
            local_2 = 2;
            local_1 = local_1 - 1 < 0 ? 0 : local_1 - 1;
        }
        if (local_0 >= 7 && local_0 < 12 && (_glhittableDll_entrypoint_9(param_2) < 2 || (_glhittableDll_entrypoint_6(param_2) != -1 && ((LocalHealth *)local_4)->health[_glhittableDll_entrypoint_6(param_2)]))) {
            local_2 = 1;
        }
        if (local_1 && local_6) {
            if (_glhittableDll_entrypoint_8(param_2) == 3) func_800A17A8(local_5, -999);
            else func_800A17A8(local_5, -local_1);
        }
        if (!func_800A1718(local_5)) local_2 = 2;
        if (local_2 != 2 || local_6) {
            switch (local_2) {
            case 0:
                func_8009AD14(local_5, param_1);
                func_8009E7C8(local_5, 0x72);
                break;
            case 1:
                local_0 = func_800F0D90(local_0, 7, 11) - 7;
                local_7 = func_8010108C(local_4, 0x50, (local_0 << 16) | (local_3 & 0xFFFF));
                if (local_7 > 0) local_0 = func_800F0D90(local_7 - 1, 0, 4);
                func_800F76B0(local_3, local_0 + 8, param_1);
                _bamotor_entrypoint_1(local_5, 0.8f, (f32)local_0 + D_80124B70, 0.3f);
                break;
            case 2:
                local_0 = func_800F0D90(local_0, 1, 5) - 1;
                local_7 = func_8010108C(local_4, 0x50, (local_0 << 16) | (local_3 & 0xFFFF));
                if (local_7 > 0) local_0 = func_800F0D90(local_7 - 1, 0, 4);
                func_800F79DC(local_3, local_0 + 3, param_1);
                _bamotor_entrypoint_1(local_5, 1.0f, (f32)local_0 + D_80124B74, 0.5f);
                if (func_80100368(local_4)->flags & 0x3000000) {
                    func_801096C8(local_4, **(void ***)((u8 *)local_5 + 0xC));
                }
                break;
            }
        }
    }
}

int func_8008ED70()
{
  return (int)&D_80117CAC;
}
