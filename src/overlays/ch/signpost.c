#include "common.h"

extern void *D_808002E0_chsignpost;
typedef struct { u8 pad[0x28]; s32 f28; u8 pad2[0xC]; f32 f38; u8 pad3[0x3A]; u16 f76:9; u16 pad76:7; } SignState;
extern void func_80102FDC(SignState *, f32);
extern s32 func_8010CD88(Actor *, f32, f32);
typedef union { s32 local_0; s16 local_1[2]; } SignpostMessage1482;
extern u8 D_80800328_chsignpost[];
extern void func_80800264_chsignpost(s32, s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
void func_80800230_chsignpost();
int func_80800274_chsignpost();

int chsignpost_entrypoint_0()
{
  return &D_808002E0_chsignpost;
}

void func_8080000C_chsignpost(SignState *param_0) {
    func_80102FDC(param_0, param_0->f38 * 0.75f);
    param_0->f28 = param_0->f76 - 0x32;
}

void func_80800058_chsignpost(Actor *param_0)
{
    s32 local_1;
    s32 local_2;

    local_2 = param_0->unk70_10;
    switch (local_2) {
        case 1:
            if (!func_800DA298(0x3A)) {
                if (func_8010CAC0(param_0->position, 0x15E) && func_8010CD88(param_0, 360.0f, 70.0f) && func_800F4B8C(func_800F54E4(), -1, 0)) {
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x16C2, 0xE, param_0->position, 0x28);
                    func_80101FDC(param_0, 2);
                    func_800DA544(0x3A);
                }
            } else {
                local_1 = (*(u32 *)((u8 *)param_0 + 0x70) & 1) ? 4 : 0;
                if (_subaddiedialog_entrypoint_6(param_0->position, (s32)param_0->rotation[1],
                        (*(u32 *)((u8 *)param_0 + 0x70) & 1) ? 0x15E : 0xFA, 70,
                        local_1)) {
                    param_0->unk70_10 = 2;
                    func_80800274_chsignpost(param_0);
                }
            }
            break;
        case 2:
            break;
    }
}

s32 func_8080019C_chsignpost(Actor *param_0, s32 param_1, SignpostMessage1482 param_2)
{
    switch (param_1) {
    case 0x2E:
        func_80800230_chsignpost(param_0, param_2.local_1[0], param_2.local_1[1]);
        break;
    case 0x2F:
        func_80800264_chsignpost((s32)param_0, param_2.local_1[0], param_2.local_1[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800328_chsignpost, param_0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800230_chsignpost(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2;
{
  if (1)
  {
    if (((((u16) (*((u16 *) (((u8 *) param_0) + 0x72)))) & 0xFFFFFFFF) >> 10) == 2)
    {
      *((u8 *) (((u8 *) param_0) + 0x72)) = ((*((u8 *) (((u8 *) param_0) + 0x72))) & 0xFF03) | 4;
    }
  }
}

void func_80800264_chsignpost(s32 arg0, s32 arg1, s32 arg2) {
}
int func_80800274_chsignpost(param_0) volatile s32 param_0[3];
{
  s32 local_0;
  s32 local_1;

  local_1 = param_0[10] + 0x1686;
  if ((local_1 >= 0x16B7) && (local_1 < 0x16BF)) {
    local_0 = local_1;
    if (func_800D3E40(6, local_1) == 0) {
      local_1 = 0x16BF;
    }
  }
  _subaddiedialog_entrypoint_11(param_0[0], local_1, 0xF, &param_0[1], 0x28);
  return 1;
}
