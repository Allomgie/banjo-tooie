#include "common.h"

extern u8 D_8011A6E0[];
void func_800B9A24(Gfx **param_0, s32 param_1, s32 *param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6);

void func_800B9990(u8 **param_0)
{
  s32 *new_var;
  u8 *local_0;
  local_0 = *param_0;
  *param_0 = (*param_0) + 8;
 *(new_var = (s32 *) (((s8 *) local_0) + 0)) = 0xDE000000; *((u8 **) (((s8 *) local_0) + 4)) = ((u8 *) ((s32 *) D_8011A6E0)) - 0x80000000;
  func_800D2CC4();
}

void func_800B99CC(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_0[4];
    func_800E7FCC(local_0);
    func_800B9A24(param_0, param_1, param_2, local_0[0], local_0[1], local_0[2], local_0[3]);
}

void func_800B9A24(Gfx **param_0, s32 param_1, s32 *param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
    { Gfx *_g = (Gfx *)((*param_0)++); _g->words.w0 = (_SHIFTL((0xde), 24, 8) | _SHIFTL((0x00), 16, 8) | _SHIFTL((0), 0, 16)); _g->words.w1 = (unsigned int)(D_8011A6E0 - 0x80000000); };
    { Gfx *_g = (Gfx *)((*param_0)++); _g->words.w0 = _SHIFTL(0xf8, 24, 8); _g->words.w1 = (unsigned int)((_SHIFTL(param_2[0], 24, 8) | _SHIFTL(param_2[1], 16, 8) | _SHIFTL(param_2[2], 8, 8) | _SHIFTL(param_1, 0, 8))); };
    { Gfx *_g = (Gfx *)((*param_0)++); _g->words.w0 = (_SHIFTL(0xe4, 24, 8) | _SHIFTL((param_3 + param_5) * 4, 12, 12) | _SHIFTL((param_4 + param_6) * 4, 0, 12)); _g->words.w1 = (_SHIFTL(0, 24, 3) | _SHIFTL(param_3 * 4, 12, 12) | _SHIFTL(param_4 * 4, 0, 12)); { Gfx *_g = (Gfx *)((*param_0)++); _g->words.w0 = _SHIFTL((0xe1), 24, 8); _g->words.w1 = (unsigned int)((_SHIFTL(0, 16, 16) | _SHIFTL(0, 0, 16))); }; { Gfx *_g = (Gfx *)((*param_0)++); _g->words.w0 = _SHIFTL((0xf1), 24, 8); _g->words.w1 = (unsigned int)((_SHIFTL(0x100, 16, 16) | _SHIFTL(0x100, 0, 16))); };};
    func_800D2CC4();
}
