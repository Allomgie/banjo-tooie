#include "common.h"

extern char D_808002B4_chtalontorpedoboulder;
extern void func_80102FDC(Actor *, f32);
extern s32 D_80800240_chtalontorpedoboulder;
extern s32 D_808002FC_chtalontorpedoboulder;
typedef struct { u8 pad[0x76]; u16 f76:9; u16 pad76:7; } TalonState;
typedef struct { s16 id; s16 val; } TalonEntry;
extern TalonEntry D_80800314_chtalontorpedoboulder[];
extern TalonEntry D_80800318_chtalontorpedoboulder[];
s32 func_808001CC_chtalontorpedoboulder();
s32 func_808001F8_chtalontorpedoboulder();

int chtalontorpedoboulder_entrypoint_0()
{
  return (int)&D_808002B4_chtalontorpedoboulder;
}

void func_8080000C_chtalontorpedoboulder(Actor *param_0)
{
    s32 local_0;

    local_0 = func_808001CC_chtalontorpedoboulder(param_0);
    if (local_0 != 0 && func_800DA298(local_0)) {
        func_800FFAB0(param_0);
    } else {
        func_80102FDC(param_0, param_0->scale + param_0->scale);
    }
}

s32 func_80800070_chtalontorpedoboulder(u8 *param_0, s32 param_1, s32 param_2) {
    s32 local_0;
    s32 local_1;
    s32 local_3;

    switch (param_1) {
    case 0x40:
        local_0 = func_808001CC_chtalontorpedoboulder(param_0);
        local_1 = func_808001F8_chtalontorpedoboulder(param_0);
        _chexploder_entrypoint_3(param_0, param_0 + 4, 0xF);
        func_800BABB8(0, param_0 + 4, param_0 + 4, (*(s32 *)((s8 *)(param_0) + (0x38))), &D_80800240_chtalontorpedoboulder);
        _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_808002FC_chtalontorpedoboulder);
        if (local_0 != 0) {
            func_800DA544(local_0);
        }
        if (local_1 != -1) {
            _capod_entrypoint_13((*(s32 *)((s8 *)(param_0) + (0))), 0, local_1, 0x10);
        }
        goto block_9;
    case 0x90:
        local_3 = func_80106790(func_80101080());
        _chexploder_entrypoint_9(local_3, 1, 2);
        _chexploder_entrypoint_9(local_3, 2, 0);
        goto block_9;
    default:
        return 0;
    }
block_9:
    return 1;
}

s32 func_80800194_chtalontorpedoboulder(s32 param_0, s32 param_1){
    func_800DF744(2, 1);
    func_80101870(param_0, param_1);
}

s32 func_808001CC_chtalontorpedoboulder(param_0) void *param_0;
{
  s32 temp_v1;
  temp_v1 = ((((u16) (*((u16 *) (((u8 *) param_0) + 0x76)))) & 0xFFFFFFFF) >> 7) - 0x32;
  if ((temp_v1 < 0) || (temp_v1 >= 5))
  {
    return 0;
  }
  return temp_v1 + 0x3EF;
}

s32 func_808001F8_chtalontorpedoboulder(param_0) TalonState *param_0; {
    s32 i;
    for (i = 0; i < 1; i++) {
        if (D_80800314_chtalontorpedoboulder[i].id == param_0->f76 - 0x32) {
            return D_80800314_chtalontorpedoboulder[i].val;
        }
    }
    return -1;
}
