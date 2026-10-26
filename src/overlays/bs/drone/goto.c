#include "common.h"
#include "overlays/ba/playerstate.h"

extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void _bamovegoto_entrypoint_7(PlayerState *, f32);
extern void _bamovegoto_entrypoint_8(PlayerState *, f32);
typedef struct { u8 pad_0[0x194]; s32 local_0; } DroneArrivalState;
void func_80800148_bsdronegoto();

void func_808000C0_bsdronegoto();

extern s32 func_800F1EA4(f32 *, f32 *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void func_80091E6C();
void func_80800150_bsdronegoto();
void func_8080032C_bsdronegoto();

void func_80800000_bsdronegoto(Actor *param_0, s32 param_1) {
    s32 local_0;

    local_0 = *(s32 *)((char *)param_0 + 0x190);
    switch (local_0) {
    case 1:
        func_80800148_bsdronegoto(param_0);
        break;
    case 2:
        func_8080032C_bsdronegoto(param_0);
        break;
    }
    *(s32 *)((char *)param_0 + 0x190) = param_1;
    switch (param_1) {
    case 1:
        func_808000C0_bsdronegoto(param_0, param_1);
        return;
    case 2:
        func_80800150_bsdronegoto(param_0, param_1);
        return;
    }
}

int func_8080009C_bsdronegoto()
{
  s32 local_0;
  local_0 = func_800A3274();
  return local_0 != 0x12;
}

void func_808000C0_bsdronegoto()
{
    func_8009B7C0();
}

void func_808000E0_bsdronegoto(param_0) s32 param_0;
{
  s32 var_v1;
  func_8009B7C0();
  var_v1 = func_8080009C_bsdronegoto(param_0) != 0;
  if (var_v1 != 0)
  {
    var_v1 = player_inWater(param_0) != 0;
  }
  if ((var_v1 != (param_0 * 0)) || (player_isStable(param_0) != 0))
  {
    func_80800000_bsdronegoto(param_0, 2);
  }
}

void func_80800148_bsdronegoto(s32 arg0) 
{
}
void func_80800150_bsdronegoto(param_0) PlayerState *param_0;
{
    f32 local_0;
    f32 local_1;
    f32 local_2[3];
    s32 local_3;
    _badata_entrypoint_1(param_0, &local_3, &local_0);
    baanim_playForDuration_loopSmooth(param_0, local_3, local_0);
    _badrone_entrypoint_8(param_0, local_2, &local_0, &local_1);
    _bamovegoto_entrypoint_0(param_0);
    _bamovegoto_entrypoint_12(param_0, local_2);
    if (local_0 != 0.0f) {
        _bamovegoto_entrypoint_9(param_0, 1);
        _bamovegoto_entrypoint_7(param_0, local_0);
    } else {
        _bamovegoto_entrypoint_9(param_0, 2);
        _bamovegoto_entrypoint_8(param_0, local_1);
    }
    func_8009FFD8(param_0, 1, 1, 3, 0);
    *(s32 *)((u8 *)param_0 + 0x198) = func_80095898(param_0);
    if (_badrone_entrypoint_7(param_0)) {
        func_800961A0(param_0, 0);
        _bamovegoto_entrypoint_10(param_0, 1);
    } else func_800961A0(param_0, 1);
    _bamovegoto_entrypoint_13(param_0);
}

void func_8080026C_bsdronegoto(param_0) PlayerState *param_0;
{
    f32 local_0;
    f32 local_1[3];
    s32 local_2;
    s32 local_3;

    func_8009BB24(param_0, local_1);
    if (func_800F1EA4(local_1, &local_0)) yaw_setIdeal(param_0, local_0);
    func_8009FF00(param_0);
    if (_bamovegoto_entrypoint_4(param_0)) {
        local_2 = ((DroneArrivalState *)param_0)->local_0;
        if (!local_2) {
            ((DroneArrivalState *)param_0)->local_0 = local_2 + 1;
            if (_badrone_entrypoint_9(param_0) == 1) {
                if (func_8008E124(param_0)) local_3 = _badata_entrypoint_32(param_0);
                else local_3 = _badata_entrypoint_34(param_0);
                bs_setState(param_0, local_3);
            }
            _badrone_entrypoint_6(param_0);
        }
    }
}

void func_8080032C_bsdronegoto(param_0) long param_0;
{
  func_800961A0(param_0, *(long *)(param_0 + 0x198));
}

void bsdronegoto_entrypoint_0(u8 *param_0) {
    (*(s32 *)((s8 *)(param_0) + (0x190))) = 0;
    (*(s32 *)((s8 *)(param_0) + (0x194))) = 0;
    _gcgoto_entrypoint_14(1);
    func_80091E48(param_0, 0x3F);
    if ((player_isStable(param_0) == 0) && (_badata_entrypoint_14(param_0) != 0)) {
        func_80800000_bsdronegoto(param_0, 1);
        return;
    }
    func_80800000_bsdronegoto(param_0, 2);
}

void bsdronegoto_entrypoint_1(void *param_0)
{
    switch (*(int *)((char*)param_0 + 0x190))
    {
        case 1 :
            func_808000E0_bsdronegoto();
            break;

        case 2 :
            func_8080026C_bsdronegoto();
            break;
    }
}

s32 bsdronegoto_entrypoint_2(s32 param_0){
    func_80800000_bsdronegoto(param_0, 0);
    func_80091E6C(param_0);
    _gcgoto_entrypoint_14(0);
}

void bsdronegoto_entrypoint_3(u8 *param_0) {
    s32 local_0;

    if ((*(s32 *)((s8 *)(param_0) + (0x194))) != 0) {
        func_80099B94();
        return;
    }
    local_0 = func_8009E6EC();
    switch (local_0) {                              
    case 0x56: ;
    case 0x5D:
    case 0x61: ;
    case 0x62:
    case 0x63: ;
    case 0x95:
    case 0x96:
        func_80099B94(param_0);
        return;
    case 0x8F:
        _bamovegoto_entrypoint_1(param_0);
        func_8009E830(param_0, 2);
        return;
    default:
        func_80099AA8(param_0);
        return;
    }
}
