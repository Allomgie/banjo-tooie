#include "core2/1E72EA0.h"

f32 func_80090010(void);
void func_800EFCD8(f32 *, f32, f32);
extern f32 yaw_get(s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_80094430(s32, f32);
extern int func_800A391C(s32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void _bashoes_entrypoint_12(PlayerState *, f32);
extern void _baduo_entrypoint_20(void *, void *, f32);
extern void _baduo_entrypoint_9(PlayerState *, f32);
extern void _bainvisible_entrypoint_5(PlayerState *, f32);
typedef struct { /* 0x00 */ s32 unk0; /* 0x04 */ u8 pad04[36]; } Eintrag;
typedef struct { /* 0x00 */ u8 pad00[8]; /* 0x08 */ f32 unk8[3]; /* 0x14 */ s32 unk14; /* 0x18 */ s32 unk18; /* 0x1C */ u8 pad1C[0x30]; /* 0x4C */ Eintrag arr[5]; } Sub;
typedef struct { /* 0x00 */ u8 pad00[0xC0]; /* 0xC0 */ Sub *unkC0; } Akteur;
void func_800EFD24(f32 *);
void func_80099B94();
void func_8009ACF4(s32 param_0, f32 param_1);
int func_8009AD04(s32 param_0, f32 param_1);
void func_8009AD14();
int func_8009AD20();
void func_8009AD44();

s32 func_800995B0(void) {
    return sizeof(BaUnknownC0);
}

void func_800995B8(PlayerState *param_0, s32 param_1)
{
  f32 local_0[6];
  f32 local_6;
  func_800A34CC(param_0, 1);
  switch (param_1)
  {
    case 0:
      func_800EC398(*((s32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xC0)))) + 0x14)), &local_0[3], param_1);
      func_800A34AC(param_0, &local_0[3]);
      return;

    case 1:
      func_800A34AC(param_0, (*((u8 **) (((s8 *) param_0) + 0xC0))) + 8, param_1);
      return;

    case 2:
      func_8008FE68(&local_0[3]);
      local_6 = func_80090010();
      func_800EFCD8(&local_0[0], local_6, 100.0f);
      local_0[1] = 0.0f;
      local_0[3] += local_0[0];
      local_0[4] += local_0[1];
      local_0[5] += local_0[2];
      func_800A34AC(param_0, &local_0[3]);
      func_800A34CC(param_0, *((s32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xC0)))) + 0x1C)));
      return;

    case 3:
      func_800A34AC(param_0, (*((u8 **) (((s8 *) param_0) + 0xC0))) + 8, param_1);
      return;

  }

}

int func_800996E0(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800A1718();
  if (local_0 < 2)
  {
    func_800A17A8(param_0, -local_0);
    return 0;
  }
  else
  {
    local_1 = 1 - local_0;
    func_800A17A8(param_0, local_1);
    return 1;
  }
}

int func_80099730(s32 param_0, s32 param_1)
{
  func_8009AD20(param_0 | 0, 0xD);
  func_800995B8(param_0 | 0, 2);
  if (param_1 != 0)
  {
    func_800996E0(param_0 | 0);
  }
  else
  {
    func_800A17A8(param_0 | 0, -1);
  }
  if (func_800A1718(param_0 | 0))
  {
    _badata_entrypoint_26(param_0 | 0);
  }
  else
  {
    _badata_entrypoint_20(param_0 | 0);
  }
}

void func_800997BC(s32 param_0)
{
    f32 local_1[3];
    f32 local_0[3];

    func_8009C128(param_0, local_0);
    func_800EEB9C(local_1, yaw_get(param_0), 100.0f);
    local_0[0] += local_1[0];
    local_0[1] += local_1[1];
    local_0[2] += local_1[2];
    func_800A34AC(param_0, local_0);
    func_800A17A8(param_0, -1);
}

int func_80099840(s32 param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  int new_var;
 goto dummy_label_22716; dummy_label_22716: ;
  new_var = 0;
  local_0 = func_800A1718();
  local_1 = param_1 == new_var;
  if (local_1 != new_var)
  {
    local_1 = local_0 != new_var;
  }
  local_0 = local_1;
  if (local_0 != new_var)
  {
    _badata_entrypoint_26(param_0);
    return;
  }
  _badata_entrypoint_20(param_0);
}

void func_8009989C(void *param_0, s32 param_1)
{
  s32 local_0;
  u8 *local_1;
  u8 *local_2;
  s32 new_var;
  local_1 = *((u8 **) (((u8 *) param_0) + 0xC0));
  local_0 = 0;
  local_2 = local_1;
  do
  {
    if ((*((s32 *) (local_2 + 0x4C))) == param_1)
    {
      return;
    }
    local_0 += 0x28;
    local_2 += 0x28;
  }
  while (local_0 < 0xC8);
  local_0 = 0;
  local_2 = local_1;
  do
  {
    if ((*((s32 *) (local_2 + 0x4C))) == 0)
    {
      *((s32 *) (local_2 + 0x4C)) = param_1;
      local_1 = *((u8 **) (((u8 *) param_0) + 0xC0));
      *((s32 *) ((local_1 + local_0) + 0x40)) = *((s32 *) (local_1 + 0x18));
      local_1 = *((u8 **) (((u8 *) param_0) + 0xC0));
      *((f32 *) ((local_1 + local_0) + 0x28)) = *((f32 *) (local_1 + 0x0));
      new_var = local_0;
      local_1 = *((u8 **) (((u8 *) param_0) + 0xC0));
      *((f32 *) ((local_1 + new_var) + 0x2C)) = *((f32 *) (local_1 + 0x4));
      local_1 = *((u8 **) (((u8 *) param_0) + 0xC0));
      local_0 = 0x14;
      *((s32 *) ((local_1 + new_var) + 0x3C)) = *((s32 *) (local_1 + local_0));
      local_1 = *((u8 **) (((u8 *) param_0) + 0xC0));
      func_800EE7F8((local_1 + new_var) + 0x30, local_1 + 0x8);
      return;
    }
    local_0 += 0x28;
    local_2 += 0x28;
  }
  while (local_0 != 0xC8);
}

void func_80099970(u8 *param_0) {
    s32 local_0;
    s32 local_1;
    u8 *local_2;
    u8 *local_3;

    local_3 = (*(u8 **)((s8 *)(param_0) + (0xC0)));
    local_1 = 0;
loop_1:
    if ((*(s32 *)((s8 *)(local_3) + (0x4C))) != 0) {
        func_8009ACF4(param_0, (*(f32 *)((s8 *)(local_3) + (0x28))));
        func_8009AD04(param_0, (*(f32 *)((s8 *)(((*(u8 **)((s8 *)(param_0) + (0xC0))) + local_1)) + (0x2C))));
        func_8009AD14(param_0, (*(s32 *)((s8 *)(((*(u8 **)((s8 *)(param_0) + (0xC0))) + local_1)) + (0x3C))));
        func_8009AD20(param_0, (*(s32 *)((s8 *)(((*(u8 **)((s8 *)(param_0) + (0xC0))) + local_1)) + (0x40))));
        func_8009AD44(param_0, (*(u8 **)((s8 *)(param_0) + (0xC0))) + local_1 + 0x30);
        local_2 = (*(u8 **)((s8 *)(param_0) + (0xC0))) + local_1;
        local_0 = (*(s32 *)((s8 *)(local_2) + (0x4C)));
        (*(s32 *)((s8 *)(local_2) + (0x4C))) = 0;
        func_8009E7C8(param_0, local_0);
        return;
    }
    local_1 += 0x28;
    local_3 += 0x28;
    if (local_1 == 0xC8) {
        return;
    }
    goto loop_1;
}

f32 func_80099A34(PlayerState *self) {
    return self->unkC0->unk0;
}

f32 func_80099A40(PlayerState *self) {
    return self->unkC0->unk4;
}

s32 func_80099A4C(PlayerState *self) {
    return self->unkC0->unk14;
}

s32 func_80099A58(PlayerState *self) {
    return self->unkC0->unk18;
}

s32 func_80099A64(PlayerState *self) {
    return self->unkC0->unk1C;
}

s32 func_80099A70(PlayerState *self) {
    return self->unkC0->unk20;
}


void func_80099A7C(PlayerState *player, f32 *param_1)
{
  char *new_var;
  if (1)
  {
    new_var = param_1;
  }
  func_800EE7F8(new_var, new_var = ((char *) (*((struct ba_unknown_C0_s **) (((char *) player) + 0xC0)))) + 8);
}

void func_80099AA8(PlayerState *param_0) {
    s32 s = func_8009E6EC(param_0);

    switch (s) {
        case 0xF:
        case 0x13:
        case 0x26:
        case 0x2A:
        case 0x30:
            func_8009989C(param_0, s);
            break;

        case 0x27:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x4D:
        case 0x62:
        case 0x63:
        case 0x6B:
        case 0x6C:
        case 0x7C:
        case 0x7D:
        case 0x81:
        case 0x89:
        case 0x91:
        case 0x98:
        case 0x9A:
            func_80099B94(param_0);
            return;
    }

    func_8009E830(param_0, 1);
    bs_setState(param_0, 0);
}

int func_80099B54(Actor *param_0) {
    Actor *local_0;
    local_0 = func_80099A4C(param_0);
    func_8009EAE8((u32)(*(s32*)((u8*)func_80106790(local_0) + 0x6C) << 11) >> 20);
    _badata_entrypoint_33(param_0);
}

void func_80099B94(param_0) PlayerState * param_0; {
    s32 local_20;
    s32 local_0;
    u8 * local_23;
    s32 local_9;
    s32 local_10;
    s32 local_11;
    s32 local_14;
    s32 local_19;
    s32 local_16;
    s32 local_1;
    s32 local_2;
    s32 local_15;
    s16 local_5[1];
    s16 local_4[1];
    u8 * local_21;
    u8 * local_22;
    s32 local_18;
    local_9 = 1;
    local_19 = 0;
    local_0 = bs_getCurrentState();
    switch (func_8009E6EC(param_0)) {
    case 57:
        baflag_set(param_0, 37);
        baflag_set(param_0, 46);
        baflag_set(param_0, 36);
        local_19 = _badrone_entrypoint_24(param_0);
        local_9 = 2;
        goto block_180;
    case 94:
        baflag_set(param_0, 37);
        baflag_set(param_0, 58);
        baflag_set(param_0, 36);
        _bafpctrl_entrypoint_11(param_0, 6, 1);
        local_19 = _badrone_entrypoint_24(param_0);
        local_9 = 2;
        goto block_180;
    case 105:
        baflag_set(param_0, 36);
        if (func_8009E71C(param_0, 9)) {
            baflag_set(param_0, 47);
            baflag_set(param_0, 48);
            _bafpctrl_entrypoint_11(param_0, 14, 1);
        } else local_19 = _badrone_entrypoint_24(param_0);
        local_9 = 2;
        goto block_180;
    case 10:
        local_9 = 2;
        local_19 = _badrone_entrypoint_28(param_0);
        goto block_180;
    case 81:
        if (func_8008DD90(param_0) == 0) {
            func_8009AD20(param_0, 1);
            case 106: local_10 = func_80099A58(param_0);
            if (local_10) func_800A17A8(param_0, -local_10);
            if (func_800A1718(param_0) == 0) {
                local_19 = func_80099840(param_0, 1);
            } else local_19 = _badrone_entrypoint_17(param_0);
            local_9 = 2;
        }
        goto block_180;
    case 82:
        local_11 = func_80099A58(param_0);
        if (local_11) func_800A17A8(param_0, -local_11);
        if (func_800A1718(param_0) == 0) {
            local_19 = func_80099840(param_0, 1);
        } else local_19 = _badrone_entrypoint_20(param_0, *(u8 ** )((s8 * ) param_0 + 192) + 8, 2);
        local_9 = 2;
        goto block_180;
    case 111:
        local_19 = _badrone_entrypoint_18(param_0, *(s32 * )( * (u8 ** )((s8 * ) param_0 + 192) + 20));
        local_9 = 2;
        goto block_180;
    case 107:
        _bafpctrl_entrypoint_13(param_0, 0);
        if (func_800A3404(param_0)) func_8009337C(param_0, 1);
        if (func_8008DAA8(param_0) && func_800A3274(param_0) != 17 && func_8008DD70(param_0) == 0 && func_800A9420( * (s32 * )((s8 * ) param_0 + 388)) == 0) {
            local_14 = _plsu_entrypoint_1(17);
            if (local_14 != -1) func_800F7B9C(local_14, 148);
        }
        local_9 = 2;
        goto block_180;
    case 108:
        _bafpctrl_entrypoint_13(param_0, 1);
        if (func_800A3404(param_0)) func_8009337C(param_0, 0);
        if (func_8008E124(param_0) == 0 && func_8009E674(param_0, 16) == 0 && func_8009E674(param_0, 8) == 0 && _bafpctrl_entrypoint_4(param_0) == 3) _bafpctrl_entrypoint_19(param_0);
        local_9 = 2;
        goto block_180;
    case 93:
        if ( * (s32 * )( * (u8 ** )((s8 * ) param_0 + 192) + 24)) {
            baflag_set(param_0, 57);
        } else baflag_clear(param_0, 57);
        local_9 = 2;
        goto block_180;
    case 47:
        local_19 = _badrone_entrypoint_20(param_0, *(u8 ** )((s8 * ) param_0 + 192) + 8, 1);
        local_9 = 2;
        goto block_180;
    case 146:
        func_800A17A8(param_0, -1);
        local_19 = _badrone_entrypoint_20(param_0, *(u8 ** )((s8 * ) param_0 + 192) + 8, 1);
        local_9 = 2;
        goto block_180;
    case 36:
        if (func_8008DD90(param_0) == 0) {
            func_800995B8(param_0, 0);
            local_19 = _badata_entrypoint_27(param_0);
            local_9 = 2;
        }
        goto block_180;
    case 35:
        if (func_8008DD90(param_0) == 0) {
            func_800995B8(param_0, 1);
            local_19 = _badata_entrypoint_27(param_0);
            local_9 = 2;
        }
        goto block_180;
    case 45:
    case 152:
        func_800995B8(param_0, 3);
        if (player_inWater(param_0) && func_8009E71C(param_0, 11)) {
            local_19 = 162;
        } else local_19 = _badata_entrypoint_27(param_0);
        local_9 = 2;
        goto block_180;
    case 137:
        _babounce_entrypoint_7(param_0, *(s32 * )( * (u8 ** )((s8 * ) param_0 + 192) + 20));
        local_9 = 2;
        goto block_180;
    case 104:
        func_800995B8(param_0, 3);
        local_19 = _badrone_entrypoint_22(param_0, *(u8 ** )((s8 * ) param_0 + 192) + 8);
        local_9 = 2;
        goto block_180;
    case 69:
        if (func_800F64A4( * (s32 * )((s8 * ) param_0 + 388), 513)) {
            local_19 = 288;
        } else local_19 = func_80099840(param_0, 1);
        local_9 = 2;
        goto block_180;
    case 87:
        _bacough_entrypoint_4(param_0, 1);
        local_9 = 2;
        goto block_180;
    case 86:
        _bacough_entrypoint_4(param_0, 2);
        local_9 = 2;
        goto block_180;
    case 68:
        local_19 = 287;
        local_9 = 2;
        goto block_180;
    case 19:
        func_800A17A8(param_0, -0x3E7);
    case 11:
        func_800997BC(param_0);
        local_19 = func_80099840(param_0, 0);
        local_9 = 2;
        goto block_180;
    case 38:
        func_800A17A8(param_0, -0x3E7);
        _basudie_entrypoint_1(param_0);
        _basudie_entrypoint_0(param_0);
        local_9 = 2;
        goto block_180;
    case 25:
        local_19 = func_8009F354(param_0);
        local_9 = 2;
        goto block_180;
    case 17:
        local_19 = 84;
        local_9 = 2;
        goto block_180;
    case 77:
        _bababykaz_entrypoint_14(param_0);
        local_9 = 2;
        goto block_180;
    case 124:
        local_19 = _badrone_entrypoint_19(param_0);
        local_9 = 2;
        goto block_180;
    case 76:
        _baduo_entrypoint_15(param_0, *(u8 ** )((s8 * ) param_0 + 192) + 8);
        local_9 = 2;
        goto block_180;
    case 62:
        _baduo_entrypoint_17(param_0, *(u8 ** )((s8 * ) param_0 + 192) + 8);
        local_9 = 2;
        goto block_180;
    case 60:
        _baduo_entrypoint_18(param_0, *(u8 ** )((s8 * ) param_0 + 192) + 8);
        local_9 = 2;
        goto block_180;
    case 63:
        local_23 = * (u8 ** )((s8 * ) param_0 + 192);
        _baduo_entrypoint_20(param_0, local_23 + 8, *(f32 * ) local_23);
        local_9 = 2;
        goto block_180;
    case 95:
        func_80094430(param_0, *(f32 * ) * (u8 ** )((s8 * ) param_0 + 192));
        local_9 = 2;
        goto block_180;
    case 43:
        baflag_set(param_0, 56);
        _bashoes_entrypoint_12(param_0, *(f32 * ) * (u8 ** )((s8 * ) param_0 + 192));
        if (func_8009CA70(param_0, local_0, 64) == 0) local_19 = func_8009F354(param_0);
        local_9 = 2;
        goto block_180;
    case 41:
        baflag_set(param_0, 55);
        _bashoes_entrypoint_12(param_0, *(f32 * ) * (u8 ** )((s8 * ) param_0 + 192));
        if (func_8009CA70(param_0, local_0, 64) == 0) local_19 = func_8009F354(param_0);
        local_9 = 2;
        goto block_180;
    case 26:
        baflag_set(param_0, 16);
        _bashoes_entrypoint_12(param_0, *(f32 * ) * (u8 ** )((s8 * ) param_0 + 192));
        if (func_8009CA70(param_0, local_0, 64) == 0) local_19 = func_8009F354(param_0);
        local_9 = 2;
        goto block_180;
    case 27:
        baflag_set(param_0, 14);
        func_800A391C(param_0, *(f32 * ) * (u8 ** )((s8 * ) param_0 + 192));
        local_19 = func_8009F354(param_0);
        local_9 = 2;
        goto block_180;
    case 71:
        local_15 = func_80099A4C(param_0);
        _suegg_entrypoint_6(local_15, & local_1, & local_2);
        func_8009AD20(param_0, _gcegg_entrypoint_7(local_2) + 2);
        if (func_8009BD44(param_0) != 3 && func_8008DD90(param_0) == 0) {
            func_800995B8(param_0, 0);
            if (func_8010114C(local_15, 28, *(s32 * )((s8 * ) param_0 + 388)) != 1) func_800A17A8(param_0, -1);
            local_19 = func_80099840(param_0, 0);
            local_9 = 2;
        }
        goto block_180;
    case 31:
        if (func_8009BD44(param_0) != 3 && func_8008DD90(param_0) == 0 && func_8008E974(param_0)) {
            case 49: func_800995B8(param_0, 2);
            func_800A17A8(param_0, -1);
            local_19 = func_80099840(param_0, 0);
            local_9 = 2;
        }
        goto block_180;
    case 33:
        if (func_8009BD44(param_0) != 3 && func_8008DD90(param_0) == 0) {
            case 51: func_800995B8(param_0, 0);
            if (func_8010114C( * (s32 * )( * (u8 ** )((s8 * ) param_0 + 192) + 20), 28, *(s32 * )((s8 * ) param_0 + 388)) != 1) func_800A17A8(param_0, -1);
            local_19 = func_80099840(param_0, 0);
            local_9 = 2;
        }
        goto block_180;
    case 78:
        if (func_8009BD44(param_0) != 3) {
            func_800995B8(param_0, 1);
            func_800A17A8(param_0, -func_80099A58(param_0));
            if ( * (s32 * )((s8 * ) param_0 + 344)) {
                if (func_800A1718(param_0) == 0) func_80101180(708, 112, *(s32 * )((s8 * ) param_0 + 388) * 16 | func_80099A70(param_0));
                if (func_800A3274(param_0) == 6) {
                    local_19 = _badata_entrypoint_26(param_0);
                } else local_19 = func_80099840(param_0, 0);
            } else local_19 = func_80099840(param_0, 0);
            local_9 = 2;
        }
        goto block_180;
    case 32:
        if (func_8009BD44(param_0) != 3) {
            func_800995B8(param_0, 1);
            func_800A17A8(param_0, -1);
            local_19 = func_80099840(param_0, 0);
            local_9 = 2;
        }
        goto block_180;
    case 46:
        func_800995B8(param_0, 3);
        func_800A17A8(param_0, -1);
        local_19 = func_80099840(param_0, 0);
        local_9 = 2;
        goto block_180;
    case 145:
        local_19 = _badrone_entrypoint_21(param_0);
        local_9 = 2;
        goto block_180;
    case 64:
        _baduo_entrypoint_11(param_0, 1);
        local_9 = 2;
        goto block_180;
    case 132:
        if (func_800A3970(param_0, *(s32 * )( * (u8 ** )((s8 * ) param_0 + 192) + 24))) local_9 = 2;
        goto block_180;
    case 20:
        local_19 = 5;
        local_9 = 2;
        goto block_180;
    case 96:
        func_800F911C(1);
        _baduo_entrypoint_7(param_0, 1);
        func_800A0CF4(param_0, 1);
        func_800A3410(param_0, 1);
        func_800A3904(param_0, 1);
        goto block_180;
    case 53:
        baflag_set(param_0, 26);
        local_19 = func_8009F354(param_0);
        local_9 = 2;
        goto block_180;
    case 4:
    case 5:
        _baduo_entrypoint_10(param_0, 0);
        _baduo_entrypoint_11(param_0, 0);
        local_9 = 2;
        goto block_180;
    case 58:
        if (func_8008E23C(param_0)) {
            _baduo_entrypoint_11(param_0, 1);
            local_9 = 2;
        } else {
            _baduo_entrypoint_8(param_0, *(u8 ** )((s8 * ) param_0 + 192) + 8);
            _baduo_entrypoint_9(param_0, *(f32 * ) * (u8 ** )((s8 * ) param_0 + 192) + 180.0f);
            _baduo_entrypoint_10(param_0, 1);
            local_9 = 2;
        }
        goto block_180;
    case 59:
        if (func_8008E23C(param_0)) {
            _baduo_entrypoint_11(param_0, 1);
            _baduo_entrypoint_8(param_0, *(u8 ** )((s8 * ) param_0 + 192) + 8);
            local_9 = 2;
        }
        goto block_180;
    case 65:
        _baduo_entrypoint_11(param_0, 0);
        local_9 = 2;
        goto block_180;
    case 149:
        func_8009EC08(local_5, local_4);
        local_5[1] = func_80099A58(param_0);
        local_4[1] = func_80099A64(param_0);
        if (local_5[0] != local_5[1] || local_4[0] != local_4[1]) func_8009EB24(local_5[1], local_4[1]);
        local_9 = 2;
        goto block_180;
    case 150:
        func_8009EBD0();
        local_9 = 2;
        goto block_180;
    case 151:
        func_800A05DC(param_0);
        local_9 = 2;
        goto block_180;
    case 39:
        local_19 = func_80099B54(param_0);
        local_9 = 2;
        goto block_180;
    case 52:
        local_19 = _badrone_entrypoint_26(param_0);
        local_9 = 2;
        goto block_180;
    case 12:
        local_16 = func_8008FD48();
        local_18 = !(local_16 == 1);
        if (local_18) local_18 = !(local_16 == 10);
        if (func_8009CC68(param_0) == 0 && local_18 == 0 && baflag_isTrue(param_0, 15) == 0 && player_isStable(param_0) == 0) {
            local_19 = 79;
            local_9 = 2;
        }
        goto block_180;
    case 61:
        _baduo_entrypoint_19(param_0);
        local_9 = 2;
        goto block_180;
    case 30:
        if (func_8008D630(param_0)) {
            local_9 = 2;
            local_19 = _badata_entrypoint_29(param_0);
        }
        goto block_180;
    case 29:
        if (func_8008D630(param_0)) {
            local_9 = 2;
            local_19 = _badata_entrypoint_31(param_0);
        }
        goto block_180;
    case 28:
        if (func_8008D630(param_0)) {
            local_9 = 2;
            local_19 = _badata_entrypoint_32(param_0);
        }
        goto block_180;
    case 21:
        local_9 = 2;
        if (func_8009CBDC(param_0, local_0) == 9) local_19 = 36;
        else switch (func_800F40EC(param_0)) {
        case 1:
            local_19 = 45;
            break;
        case 2:
            local_19 = 43;
            break;
        case 0:
            if (player_isStable(param_0)) local_20 = _badata_entrypoint_34(param_0);
            else local_20 = _badata_entrypoint_24(param_0);
            local_19 = local_20;
        }
        baphysics_set_target_horizontal_velocity(param_0, 0);
        func_8009BA9C(param_0, 0);
        goto block_180;
    case 37:
        local_9 = 2;
        local_19 = _badata_entrypoint_32(param_0);
        goto block_180;
    case 147:
        _bafpctrl_entrypoint_19(param_0);
        local_9 = 2;
        goto block_180;
    case 138:
        func_80094574(param_0, *(s32 * )( * (u8 ** )((s8 * ) param_0 + 192) + 24));
        local_9 = 2;
        goto block_180;
    case 56:
        local_9 = 2;
        local_19 = 181;
        goto block_180;
    case 89:
        _basquash_entrypoint_3(param_0, 1);
        local_19 = func_80099730(param_0, 0);
        goto block_180;
    case 90:
        _basquash_entrypoint_3(param_0, 1);
        local_19 = func_80099730(param_0, 1);
        goto block_180;
    case 154:
        _basquash_entrypoint_3(param_0, 1);
        goto block_180;
    case 91:
        _basquash_entrypoint_3(param_0, 2);
        local_19 = func_80099730(param_0, 0);
        goto block_180;
    case 92:
        _basquash_entrypoint_3(param_0, 2);
        local_19 = func_80099730(param_0, 1);
        goto block_180;
    case 15:
        baflag_set(param_0, 6);
        local_19 = func_8009F354(param_0);
        local_9 = 2;
        goto block_180;
    case 48:
        func_800A17A8(param_0, -0x3E7);
        baflag_set(param_0, 6);
        local_19 = func_8009F354(param_0);
        local_9 = 2;
        goto block_180;
    case 55:
        local_19 = _badrone_entrypoint_27(param_0);
        local_9 = 2;
        goto block_180;
    case 42:
        local_9 = 2;
        local_19 = func_8009F354(param_0);
        baflag_set(param_0, 20);
        goto block_180;
    case 73:
        baflag_set(param_0, 2);
        local_9 = 2;
        goto block_180;
    case 74:
        baflag_set(param_0, 1);
        local_9 = 2;
        goto block_180;
    case 97:
        _bsfirstp_entrypoint_26(param_0);
        return;
    case 139:
        local_19 = 66;
        local_9 = 2;
        goto block_180;
    case 98:
        func_800A3544(param_0, 1);
        func_8009337C(param_0, 0);
        local_9 = 2;
        goto block_180;
    case 99:
        func_800A3544(param_0, 0);
        func_8009337C(param_0, 1);
        local_9 = 2;
        goto block_180;
    case 102:
        local_21 = * (u8 ** )((s8 * ) param_0 + 192);
        func_8008ED88(param_0, local_21 + 8, *(s32 * )(local_21 + 20));
        local_9 = 2;
        goto block_180;
    case 103:
        _bainvisible_entrypoint_5(param_0, *(f32 * ) * (u8 ** )((s8 * ) param_0 + 192));
        local_9 = 2;
        goto block_180;
    case 125:
        if ( * (s32 * )((s8 * ) param_0 + 344)) {
            _badeathmatch_entrypoint_5(param_0, _badeathmatch_entrypoint_4( * (s32 * )( * (u8 ** )((s8 * ) param_0 + 192) + 24)), *(s32 * )( * (u8 ** )((s8 * ) param_0 + 192) + 28));
            local_9 = 2;
        } else {
            local_22 = * (u8 ** )((s8 * ) param_0 + 192);
            func_800D175C( * (s32 * )(local_22 + 24), *(s32 * )(local_22 + 28));
            local_9 = 2;
        }
        goto block_180;
    case 140:
        func_800956B8(param_0);
    }
    block_180: func_8009E830(param_0, local_9);
    bs_setState(param_0, local_19);
}

void func_8009AB78(PlayerState *param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_800A3274();
    local_1 = 1;
    local_2 = 0;
    local_3 = func_8009E6EC((s32) param_0);
    if (local_3 != 8) {
        if (local_3 == 0x12) {
            if ((baflag_isFalse(param_0, 0xF) != 0) && (bastatetimer_isDone(param_0, 0) != 0) && ((local_0 == 1) || (local_0 == 0xA))) {
                local_1 = 2;
                func_8008F6B8(param_0, func_8008E9AC(param_0));
            }
            goto block_9;
        }
        goto bahold;
    }
    local_2 = 0x3C;
    local_1 = 2;
    goto block_9;
bahold:
    _bahold_entrypoint_4(param_0);
    func_80099B94(param_0);
    return;
block_9:
    bs_setState(param_0, local_2);
    func_8009E830(param_0, local_1);
}

void func_8009AC6C(Akteur *param_0)
{
    int i;
    param_0->unkC0->unk18 = 0;
    param_0->unkC0->unk14 = 0;
    func_800EFD24(param_0->unkC0->unk8);
    for (i = 0; i < 5; i++)
    {
        param_0->unkC0->arr[i].unk0 = 0;
    }
}

void func_8009ACF4(s32 param_0, f32 param_1)
{
  *((f32 *) ((s32 *) (param_0))[0x30]) = param_1;
}

func_8009AD04(s32 param_0, f32 param_1){
    *(f32*)(*(s32*)(param_0 + 0xC0) + 4) = param_1;
}

void func_8009AD14(param_0, param_1) u8 * param_0; s32 param_1; {
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC0)))) + (0x14))) = param_1;
}

func_8009AD20(param_0, param_1) s32 param_0; s32 param_1;{
    *(s32*)(*(s32*)(param_0 + 0xC0) + 0x18) = param_1;
}

int func_8009AD2C(void *param_0, s32 param_1)
{
  void **local_0;
  (*((void ***) (((u8 *) param_0) + 0xC0)))[7] = param_1;
}

func_8009AD38(s32 param_0, s32 param_1){
    *(s32*)(*(s32*)(param_0 + 0xC0) + 0x20) = param_1;
}

void func_8009AD44(param_0) Actor * param_0;
{
  func_800EE7F8(*(s32 *)((char *)param_0 + 0xc0) + 8);
}
