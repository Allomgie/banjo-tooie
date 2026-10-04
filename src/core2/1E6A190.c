#include "common.h"

#include "core2/1E6A190.h"

typedef struct {
    u8 pad0[0xC];
} Unk_1E6A190_1;

typedef struct {
    f32 unk0;
    Unk_1E6A190_1 unk4[4];
} Unk_1E6A190_0;

extern Unk_1E6A190_0 D_80117CC0;
extern Unk_1E6A190_0 D_80117CFC;
extern Unk_1E6A190_0 D_80117D80;

s32 func_800908A0(void) {
    return sizeof(BaUnknown20);
}

Unk_1E6A190_0 *func_800908A8(s32 arg0) {
    switch (arg0) {
    case 0:
        return &D_80117D80;

    case 1:
        return &D_80117CFC;
    
    case 2:
        return &D_80117CC0;

    default:
        return NULL;
    }
}

void func_800908F0(PlayerState *self, s32 arg1) {
    self->unk20->unk9 = arg1;
    if (arg1 == 1) {
        func_8009ADF0(self, 4, 0);
    } else {
        func_8009ADF0(self, 4, 1);
    }
}

void func_80090938(PlayerState *self) {
    self->unk20->unk0 = 0;
    self->unk20->unk4 = 0.0f;
    self->unk20->unk8 = 0;
    self->unk20->unk9 = 0;
    func_800908F0(self, 1);

}

void func_8009097C(PlayerState *self, s32 arg1) {
    self->unk20->unk0 = arg1;
    self->unk20->unk8 = 0;
    self->unk20->unk4 = func_800908A8(arg1)->unk0;
    func_800908F0(self, 2);
}

void func_800909CC(PlayerState *self) {
    func_8009097C(self, 1);
}

void func_800909EC(PlayerState *self) {
    func_8009097C(self, 0);
}

void func_80090A0C(PlayerState *self) {
    func_8009097C(self, 2);
}

void func_80090A2C(PlayerState *self) {
    func_800908F0(self, 1);
}

void func_80090A4C(u8 *param_0)
{
  u8 *local_0;
  f32 local_1;
  f32 local_2;
  f32 local_3;
  u8 *local_4;
  u8 *local_5;
  u8 *local_6;
  float mlAbsF(float);
  local_1 = func_800D8FF8();
  local_3 = local_1;
  if (local_1 > 0.0f)
  {
    loop_1:
    local_5 = *((u8 **) (((s8 *) param_0) + 0x20));

    *((f32 *) (((s8 *) local_5) + 4)) = (f32) ((*((f32 *) (((s8 *) local_5) + 4))) - local_3);
    local_2 = *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x20)))) + 4));
    if (!(local_2 > 0.0f))
    {
      local_3 = mlAbsF(local_2);
      local_4 = ((*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x20)))) + 8))) * 0xC) + (u8 *) func_800908A8(*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x20)))) + 0)));
      func_800950FC(param_0, *((u8 *) (((s8 *) local_4) + 4)), *((s32 *) (((s8 *) local_4) + 8)));
      local_4 += 0xC;
      if ((*((u8 *) (((s8 *) local_4) + 4))) == 4)
      {
        if ((*((f32 *) (local_4))) == 0.0f)
        {
          func_800908F0(param_0, 1);
          return;
        }
        local_4 = func_800908A8(*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x20)))) + 0)));
        *((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x20)))) + 8)) = 0U;
        goto block_7;
      }
      local_6 = *((u8 **) (((s8 *) param_0) + 0x20));
      *((u8 *) (((s8 *) local_6) + 8)) = (u8) ((*((u8 *) (((s8 *) local_6) + 8))) + 1);
      block_7:
      *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x20)))) + 4)) = *((f32 *) local_4);

      if (!(local_3 > 0.0f))
      {
      }
      else
      {
        goto loop_1;
      }
    }
  }
}
