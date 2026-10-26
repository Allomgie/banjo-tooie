#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_8009C128(PlayerState *, f32 *);
extern void func_800F3E84(PlayerState *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern f32 func_800DC0C0(void);
extern void _baeggsetup_entrypoint_1(s32);
extern u8 _baeggsetup_entrypoint_4[];
extern void func_80094C0C();
extern void _chbaddiesetup_entrypoint_1();
extern void func_800C4B64(f32);
extern void func_800C4B70(s32);
extern void func_800C4B7C(s32);
extern void func_8010D930(s32, s32, f32 *, void *);
extern u8 D_80800860_baeggsetup[];
void baeggsetup_entrypoint_3();

s32 baeggsetup_entrypoint_0() 
{
    return 0x28;
}

int func_80800008_baeggsetup(s32 param_0)
{
  return func_8009E674(param_0, 2) == 0;
}

void baeggsetup_entrypoint_1(s32 param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    PlayerState *local_3;

    local_3 = (PlayerState *)func_800F53D0();
    func_800EE7F8(local_0, *(f32 **)((u8 *)local_3 + 0x70));
    func_800EE7F8(local_2, *(f32 **)((u8 *)local_3 + 0x70) + 3);
    func_800EE7F8(local_1, *(f32 **)((u8 *)local_3 + 0x70) + 6);
    switch ((*(u8 **)((u8 *)local_3 + 0x70))[0x24]) {
        case 1: _cheggnormal_entrypoint_1(local_0, local_2, local_1, param_0); break;
        case 2: _cheggfire_entrypoint_1(local_0, local_2, local_1, param_0); break;
        case 3: _cheggice_entrypoint_1(local_0, local_2, local_1, param_0); break;
        case 4: _chegggrenade_entrypoint_2(local_0, local_2, local_1, param_0); break;
        case 5:
            _bababykaz_entrypoint_13(local_3);
            _cheggclockwork_entrypoint_1(local_0, local_2, local_1, param_0, func_80800008_baeggsetup(local_3));
            break;
        case 7: _chegggolden_entrypoint_1(local_0, local_2, local_1, param_0); break;
    }
}

void baeggsetup_entrypoint_2(PlayerState *param_0, s32 param_1, f32 param_2, f32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];

    func_80094C0C(param_0);
    func_8009C128(param_0, local_3);
    local_3[1] += param_2;
    func_800EE7F8(local_0, local_3);
    func_800F3E84(param_0, local_1);
    local_1[1] = func_800136E4(local_1[1] + 180.0f);
    func_800EEB9C(local_2, local_1[1], param_3);
    func_800EF04C(local_3, local_2);
    local_1[1] += func_800DC0C0() * 6.0f - 3.0f;
    func_800EEB9C(local_2, local_1[1], 200.0f);
    local_2[1] = func_800DC0C0() * 20.0f + 700.0f;
    func_800EE7F8(*(f32 **)((u8 *)param_0 + 0x70), local_0);
    func_800EE7F8(*(f32 **)((u8 *)param_0 + 0x70) + 3, local_3);
    func_800EE7F8(*(f32 **)((u8 *)param_0 + 0x70) + 6, local_2);
    (*(u8 **)((u8 *)param_0 + 0x70))[0x24] = param_1;
    _chbaddiesetup_entrypoint_1(&_baeggsetup_entrypoint_1, *(s32 *)((u8 *)param_0 + 0x184));
}

void baeggsetup_entrypoint_3(param_0, param_1, param_2, param_3, param_4) s32 param_0; s32 param_1; s32 param_2; s32 param_3; s32 param_4;
{
  s32 local_1;
  s32 new_var;
  new_var = param_0;
  local_1 = func_800F53D0();
  switch (param_1)
  {
    case 1:
      _cheggnormal_entrypoint_2(param_2, param_3, param_4, new_var);
      return;

    case 2:
      _cheggfire_entrypoint_2(param_2, param_3, param_4, param_0);
      return;

    case 3:
      _cheggice_entrypoint_2(param_2, param_3, param_4, new_var);
      return;

    case 4:
      _chegggrenade_entrypoint_3(param_2, param_3, param_4, param_0);
      return;

    case 5:
      _bababykaz_entrypoint_13(local_1);
      _cheggclockwork_entrypoint_1(param_2, param_3, param_4, new_var, func_80800008_baeggsetup(local_1));
      return;

    case 7:
      _chegggolden_entrypoint_2(param_2, param_3, param_4, new_var);
      return;

    case 6:
      _cheggproximity_entrypoint_1(param_2, param_3, param_4, new_var);

    default:
      return;

  }

}

void baeggsetup_entrypoint_4(s32 param_0) {
    u8 *local_0;

    local_0 = (*(u8 **)((s8 *)(func_800F53D0()) + (0x70)));
    baeggsetup_entrypoint_3(param_0, (*(u8 *)((s8 *)(local_0) + (0x24))), local_0, local_0 + 0xC, local_0 + 0x18);
}

void baeggsetup_entrypoint_5(PlayerState *param_0, s32 param_1, f32 param_2, f32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];

    func_80094C0C(param_0);
    func_8009C128(param_0, local_3);
    local_3[1] += param_2;
    func_800EE7F8(local_0, local_3);
    func_800F3E84(param_0, local_1);
    func_800EEB9C(local_2, local_1[1], param_3);
    func_800EF04C(local_3, local_2);
    local_1[1] = local_1[1];
    func_800EEB9C(local_2, local_1[1], 800.0f);
    local_2[1] = 0.0f;
    func_800EE7F8(*(f32 **)((u8 *)param_0 + 0x70), local_0);
    func_800EE7F8(*(f32 **)((u8 *)param_0 + 0x70) + 3, local_3);
    func_800EE7F8(*(f32 **)((u8 *)param_0 + 0x70) + 6, local_2);
    (*(u8 **)((u8 *)param_0 + 0x70))[0x24] = param_1;
    _chbaddiesetup_entrypoint_1(_baeggsetup_entrypoint_4, *(s32 *)((u8 *)param_0 + 0x184));
}

void baeggsetup_entrypoint_6(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    func_80094C0C();
    func_800EE7F8((*(u8 **)((s8 *)(param_0) + (0x70))), param_2);
    func_800EE7F8((*(u8 **)((s8 *)(param_0) + (0x70))) + 0xC, param_3);
    func_800EE7F8((*(u8 **)((s8 *)(param_0) + (0x70))) + 0x18, param_4);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x70)))) + (0x24))) = (s8) param_1;
    _chbaddiesetup_entrypoint_1(((s32 *) _baeggsetup_entrypoint_4), (*(s32 *)((s8 *)(param_0) + (0x184))));
}

s32 baeggsetup_entrypoint_7(s32 param_0, s32 param_1)
{
    _chbaddiesetup_entrypoint_1(param_1, *(s32 *)(param_0 + 0x184));
}

void baeggsetup_entrypoint_8(PlayerState *param_0, s32 param_1)
{
    s32 local_0;
    f32 local_1;
    s32 local_3;
    f32 local_2[3];

    local_0 = 0;
    local_1 = 1.0f;
    local_3 = param_1;
    switch (local_3) {
    case 1: local_0 = 0x443E; break;
    case 2: local_0 = 0x4590; break;
    case 3: local_0 = 0x4597; break;
    case 4: local_0 = 0x4591; break;
    case 5: local_0 = 0x458F; break;
    case 6: local_0 = 0x458F; break;
    case 7: local_0 = 0x443E; break;
    }
    if (local_0) {
        func_8009C128(param_0, local_2);
        func_8009DAAC(&local_0, &local_1);
        func_800C4B64(local_1);
        func_800C4B70(0x7FFF);
        func_800C4B7C(local_0);
        func_8010D930(11, -1, local_2, D_80800860_baeggsetup);
    }
}

void baeggsetup_entrypoint_9(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1 = 1.4f;
    s32 local_3;
    f32 local_2[3];

    local_3 = func_80094510(param_0);
    switch (local_3) {
        case 1: local_0 = 0x42B; break;
        case 2: local_0 = 0x42B; break;
        case 3: local_0 = 0x42B; break;
        case 4: local_0 = 0x42B; break;
        case 5: local_0 = 0x42B; break;
        case 6: local_0 = 0x42B; break;
        case 7: local_0 = 0x42B; break;
    }
    if (local_0 != 0) {
        func_8009C128(param_0, local_2);
        func_8009DAAC(&local_0, &local_1);
        func_800C4B64(local_1);
        func_800C4B70(0x6D60);
        func_800C4B7C(local_0);
        func_8010D930(11, -1, local_2, D_80800860_baeggsetup);
    }
}

void baeggsetup_entrypoint_10(s32 param_0) {
    f32 local_0[3];
    func_8009C128(param_0, local_0);
    func_800C4B64(1.0f);
    func_800C4B70(0x7FFF);
    func_800C4B7C(0x4A5);
    func_8010D930(0xA, -1, local_0, ((s32 *) D_80800860_baeggsetup));
}
