#include "common.h"
#include "playerstate.h"

typedef struct { u8 pad_0[0x54]; f32 local_0; u8 pad_1[4]; u8 local_1; u8 local_2; u8 local_3; u8 local_4; f32 local_5; f32 local_6; } SubmarineSequence;
typedef struct { u8 pad_0[0x130]; SubmarineSequence *local_0; } SubmarinePlayerView;
extern f32 func_800D8FF8(void);
typedef struct { u8 pad[0x28]; s32 f28; s32 arr[10]; } SubS;
extern void _basub_entrypoint_4(void);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern s32 D_80800C10_basub;
extern PlayerState *func_800F53D0(s32);
extern s32 func_80092CDC(PlayerState *, f32 *, s32);
extern s32 func_80092EB0(PlayerState *);
extern void func_800F3BD0(PlayerState *, s32, f32 *);
extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void _baeggfire_entrypoint_3(PlayerState *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern f32 func_800964DC(PlayerState *);
extern s32 _basub_entrypoint_6(s32, s32, s32);
extern s32 _chtorpedo_entrypoint_0(f32 *, f32 *, f32 *,
    s32 (*)(s32, s32, s32), s32, f32);
extern u8 D_80800C24_basub[];
extern void _basub_entrypoint_7(void);
extern void func_8009C128();
extern void func_8010D930(s32, s32, f32 *, void *);
extern void _chbaddiesetup_entrypoint_2(void (*)(void), s32, f32);
extern s32 D_80800C30_basub;
extern void func_800E0AF0(s32, f32);
extern void func_800F1574(f32 *, f32);
extern void func_800E0AFC(s32, s32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
void func_80800834_basub();
int basub_entrypoint_15();

s32 basub_entrypoint_0() 
{
    return 0x6C;
}

void func_80800008_basub(PlayerState *param_0, s32 param_1)
{
    switch (param_1) {
    case 1:
        if (((SubmarinePlayerView *)param_0)->local_0->local_2 == 2) {
            ((SubmarinePlayerView *)param_0)->local_0->local_3 = 0;
            ((SubmarinePlayerView *)param_0)->local_0->local_0 =
                ((SubmarinePlayerView *)param_0)->local_0->local_5 - ((SubmarinePlayerView *)param_0)->local_0->local_6;
        }
        break;
    case 2:
        if (((SubmarinePlayerView *)param_0)->local_0->local_2 == 1) {
            ((SubmarinePlayerView *)param_0)->local_0->local_1 = ((SubmarinePlayerView *)param_0)->local_0->local_4 - 1;
        } else {
            ((SubmarinePlayerView *)param_0)->local_0->local_1--;
        }
        ((SubmarinePlayerView *)param_0)->local_0->local_0 += ((SubmarinePlayerView *)param_0)->local_0->local_6;
        func_80800834_basub(param_0);
        break;
    }
    ((SubmarinePlayerView *)param_0)->local_0->local_2 = param_1;
}

void func_808000CC_basub(u8 *param_0) {
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x58))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x5E))) = 0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x54))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x5D))) = 0;
    func_80800008_basub(param_0, 1);
}

void func_80800110_basub(PlayerState *param_0)
{
    f32 local_0;

    local_0 = func_800D8FF8();
    if (*(f32 *)((SubmarinePlayerView *)param_0)->local_0->pad_1 > 0.0f) {
        *(f32 *)((SubmarinePlayerView *)param_0)->local_0->pad_1 -= local_0;
        if (*(f32 *)((SubmarinePlayerView *)param_0)->local_0->pad_1 <= 0.0f)
            ((SubmarinePlayerView *)param_0)->local_0->local_3 = 0;
    }
    switch (((SubmarinePlayerView *)param_0)->local_0->local_2) {
        case 1:
            if (((SubmarinePlayerView *)param_0)->local_0->local_0 > 0.0f)
                ((SubmarinePlayerView *)param_0)->local_0->local_0 -= local_0;
            if (((SubmarinePlayerView *)param_0)->local_0->local_0 <= 0 && ((SubmarinePlayerView *)param_0)->local_0->local_3)
                func_80800008_basub(param_0, 2);
            break;
        case 2:
            ((SubmarinePlayerView *)param_0)->local_0->local_0 -= local_0;
            if (((SubmarinePlayerView *)param_0)->local_0->local_0 <= 0) {
                if (((SubmarinePlayerView *)param_0)->local_0->local_1) {
                    if (((SubmarinePlayerView *)param_0)->local_0->local_3) func_80800008_basub(param_0, 2);
                    else func_80800008_basub(param_0, 1);
                } else func_80800008_basub(param_0, 1);
            }
            break;
    }
}

void func_80800254_basub(PlayerState *param_0, s32 param_1)
{
    s32 local_0;

    for (local_0 = 0; local_0 < 10; local_0++) {
        if (((s32 *)*(void **)((u8 *)param_0 + 0x130))[11 + local_0] == 0) {
            ((s32 *)*(void **)((u8 *)param_0 + 0x130))[11 + local_0] = param_1;
            ((s32 *)*(void **)((u8 *)param_0 + 0x130))[10]++;
            return;
        }
    }
}

void func_80800358_basub(PlayerState *param_0, s32 param_1)
{
    s32 local_0;

    for (local_0 = 0; local_0 < 10; local_0++) {
        if (((s32 *)*(void **)((u8 *)param_0 + 0x130))[11 + local_0] == param_1) {
            ((s32 *)*(void **)((u8 *)param_0 + 0x130))[11 + local_0] = 0;
            ((s32 *)*(void **)((u8 *)param_0 + 0x130))[10]--;
            return;
        }
    }
}

void func_80800458_basub(u8 *param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;

    local_1 = 0;
    do {
        local_0 = (*(s32 *)((s8 *)(((*(s32 *)((s8 *)(param_0) + (0x130))) + local_1)) + (0x2C)));
        if (local_0 != 0) {
            func_8010114C(local_0, param_1, (*(s32 *)((s8 *)(param_0) + (0x184))));
        }
        local_1 += 4;
    } while (local_1 != 0x28);
}

void func_808004C8_basub(u8 *param_0) {
    s32 i;
    for (i = 0; i < 10; i++) {
        (*(SubS **)(param_0 + 0x130))->arr[i] = 0;
    }
    (*(SubS **)(param_0 + 0x130))->f28 = 0;
}

void basub_entrypoint_1(s32 arg0)
{
    func_80800458_basub(arg0,0x5);
}

f32 basub_entrypoint_2(u8 *param_0) {
    u8 *local_0;

    local_0 = (*(u8 **)((s8 *)(param_0) + (0x130)));
    if ((*(f32 *)((s8 *)(local_0) + (4))) > 0.0f) {
        return (*(f32 *)((s8 *)(local_0) + (0)));
    }
    return 0.0f;
}

void basub_entrypoint_3(u8 *param_0, f32 param_1, f32 param_2)
{
  u8 *local_0;
  u8 *local_1;
  local_0 = *((u8 **) (((s8 *) param_0) + 0x130));
  if (!((*((f32 *) (((s8 *) local_0) + 4))) > 0.0f))
  {
    *((f32 *) (((s8 *) local_0) + 0)) = param_1;
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x130)))) + 4)) = param_2;
 do { local_1 = *((u8 **) (((s8 *) param_0) + 0x130)); *((f32 *) (((s8 *) local_1) + 8)) = (f32) (*((f32 *) (((s8 *) local_1) + 4))); } while (0);
  }
}

void basub_entrypoint_4(s32 param_0)
{
    int local_0;
    local_0 = func_800F53D0(param_0);
    _chping_entrypoint_0(*(int *)(local_0 + 0x184));
}

void basub_entrypoint_5(PlayerState *param_0)
{
    f32 *local_0 = *(f32 **)((u8 *)param_0 + 0x130);

    if (local_0[7] == 0.0f) {
        local_0[7] = 3.0f;
        func_8009DB04(param_0, 0x52A, 1.0f, 0x7FFF);
        _chbaddiesetup_entrypoint_1(_basub_entrypoint_4, param_0->unk184);
    }
}

int basub_entrypoint_6(s32 param_0, s32 param_1, s32 param_2)
{
  f32 local_0[3];
  s32 local_1;

  local_1 = func_800F53D0(param_2);
  switch (param_1)
  {
    case 5:
      func_8008F880(param_0, local_0);
      func_8010D930(6, -1, local_0, &D_80800C10_basub);
      break;
    case 0x78:
      break;
  }
  func_80800358_basub(local_1, param_0);
}

void basub_entrypoint_7(s32 param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    s32 local_4;
    PlayerState *local_6;

    local_6 = func_800F53D0(param_0);
    local_3 = func_80092CDC(local_6, local_1, 5);
    local_4 = func_80092EB0(local_6);
    if (local_3 && local_4) {
        func_800F3BD0(local_6, 5, local_0);
        func_800EEC30(local_2, -(func_8009BFCC(local_6)), yaw_get(local_6),
            *(f32 *)((u8 *)*(void **)((u8 *)local_6 + 0x130) + 0x68));
    } else {
        _baeggfire_entrypoint_3(local_6, local_0, local_2);
        func_800EF368(local_2, 100.0f);
        func_800EE780(local_1, local_0, local_2);
        func_800EF368(local_2,
            *(f32 *)((u8 *)*(void **)((u8 *)local_6 + 0x130) + 0x68));
        _baeggcursor_entrypoint_8(local_6);
    }
    (*(u8 *)((u8 *)*(void **)((u8 *)local_6 + 0x130) + 0x5E))--;
    func_80800254_basub(local_6, _chtorpedo_entrypoint_0(local_1, local_0,
        local_2, _basub_entrypoint_6, local_6->unk184, func_800964DC(local_6)));
}

void basub_entrypoint_8(u8 *param_0, s32 param_1) {
    u8 local_0;
    u8 *local_1;

    local_1 = (*(u8 **)((s8 *)(param_0) + (0x130)));
    local_0 = (*(u8 *)((s8 *)(local_1) + (0x5E)));
    if (((*(s32 *)((s8 *)(local_1) + (0x28))) + local_0) < 0xA) {
        (*(u8 *)((s8 *)(local_1) + (0x5E))) = (u8) (local_0 + 1);
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x58))) = 0.35f;
    }
}

void func_80800834_basub(param_0) u8 *param_0; {
    f32 local_0[4];
    local_0[3] = 0.0f;
    func_8009C128(param_0, local_0);
    func_8010D930(0xB, -1, local_0, D_80800C24_basub);
    _chbaddiesetup_entrypoint_2(_basub_entrypoint_7, *(s32 *)(param_0 + 0x184), local_0[3]);
}

void basub_entrypoint_9(u8 *param_0) {
    func_80800458_basub(param_0, 0x2C);
    func_800C2FDC((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0xC))));
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0xC))) = 0;
    _bawobble_entrypoint_2(param_0);
}

void basub_entrypoint_10(u8 *param_0)
{
  u8 *local_0;
  _bawobble_entrypoint_3();
  func_808000CC_basub(param_0);
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x130)))) + 0)) = 0.0f;
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x130)))) + 8)) = 0.0f;
  local_0 = *((u8 **) (((s8 *) param_0) + 0x130));
  *((f32 *) (((s8 *) local_0) + 4)) = (f32) (*((f32 *) (((s8 *) local_0) + 8)));
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x130)))) + 0xC)) = func_8009D454(param_0, 0, &D_80800C30_basub);
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x130)))) + 0x10)) = 1.0f;
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x130)))) + 0x18)) = 0.0f * 1.0f;
  local_0 = *((u8 **) (((s8 *) param_0) + 0x130));
  *((f32 *) (((s8 *) local_0) + 0x14)) = (f32) (*((f32 *) (((s8 *) local_0) + 0x18)));
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x130)))) + 0x1C)) = 0.0f;
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x130)))) + 0x20)) = 0.0f;
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x130)))) + 0x24)) = 0.0f;
  func_808004C8_basub(param_0);
  basub_entrypoint_15(param_0, 0);
}

void basub_entrypoint_11(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 0x130) + 0x10) = param_1;
}

int basub_entrypoint_12(s32 param_0, f32 param_1)
{
  s32 new_var;
  new_var = 0x130;
  *((f32 *) ((*((s32 *) (param_0 + 0x130))) + 0x18)) = param_1;
}

void basub_entrypoint_13(void *param_0, f32 param_1)
{
  void *local_0;
  ;
  *((f32 *) (((char *) (*((void **) (((char *) param_0) + 0x130)))) + 0x24)) = param_1;
}

void basub_entrypoint_14(u8 *param_0)
{
    f32 local_2;
    f32 local_3;
    f32 local_0[3];
    s32 local_1;
    local_2 = func_800D8FF8();
    local_1 = func_80092AD8(param_0);
    func_800E0AF0(local_1, 1.0f);
    func_800F1574((f32 *)(*(u8 **)(param_0 + 0x130) + 4), local_2);
    local_3 = local_2 < *(f32 *)((*(u8 **)(param_0 + 0x130)) + 0x1C) ? local_2 : *(f32 *)((*(u8 **)(param_0 + 0x130)) + 0x1C);
    *(f32 *)((*(u8 **)(param_0 + 0x130)) + 0x1C) -= local_3;
    *(f32 *)((*(u8 **)(param_0 + 0x130)) + 0x20) += *(f32 *)((*(u8 **)(param_0 + 0x130)) + 0x24) * local_2;
    func_800E0AFC(local_1, 0x2A, 1.0f, 0.0f, 0.0f, *(f32 *)(*(u8 **)(param_0 + 0x130) + 0x20));
    *(f32 *)(*(u8 **)(param_0 + 0x130) + 0x14) = func_800F15F8(*(f32 *)((*(u8 **)(param_0 + 0x130)) + 0x14), *(f32 *)((*(u8 **)(param_0 + 0x130)) + 0x18), 450.0f * local_2);
    func_800E0AFC(local_1, 0x41, 1.0f, *(f32 *)(*(u8 **)(param_0 + 0x130) + 0x14), 0.0f, 0.0f);
    func_800E0AFC(local_1, 0x43, 1.0f, *(f32 *)(*(u8 **)(param_0 + 0x130) + 0x14), 0.0f, 0.0f);
    func_8009C128(param_0, local_0);
    func_800C35E8((*(u8 **)(param_0 + 0x130))[0xC], local_0);
    func_800C33DC((*(u8 **)(param_0 + 0x130))[0xC], 0);
    func_800C368C((*(u8 **)(param_0 + 0x130))[0xC], 0);
    func_800C31DC((*(u8 **)(param_0 + 0x130))[0xC], *(s32 *)((*(u8 **)(param_0 + 0x130)) + 0x10));
    func_800C3BDC((*(u8 **)(param_0 + 0x130))[0xC]);
    func_80800110_basub(param_0);
}

int basub_entrypoint_15(param_0, param_1) u8 *param_0; s32 param_1; {
    if (param_1 != 0) {
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x68))) = 3000.0f;
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x5F))) = 6;
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x60))) = 0.8f;
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x64))) = 0.28f;
        return;
    }
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x68))) = 1500.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x5F))) = 3;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x60))) = 0.8f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x130)))) + (0x64))) = 0.28f;
}
