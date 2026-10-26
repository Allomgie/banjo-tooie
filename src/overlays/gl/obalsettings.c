#include "gl/globalsettings.h"

extern void func_800DA3B8();
extern s16 D_80800560_glglobalsettings[][2];
s32 glglobalsettings_entrypoint_4();
int glglobalsettings_entrypoint_5();
void glglobalsettings_entrypoint_6();
s32 glglobalsettings_entrypoint_7();
void glglobalsettings_entrypoint_8();

s32 glglobalsettings_entrypoint_0(void){
    glglobalsettings_entrypoint_4(0);
    glglobalsettings_entrypoint_6(0, 0);
    glglobalsettings_entrypoint_8(1);
}

s32 glglobalsettings_entrypoint_3();

void func_80800034_glglobalsettings(void)
{
    s32 local_0;
    s32 local_1;

    glglobalsettings_entrypoint_4(glglobalsettings_entrypoint_3());
    glglobalsettings_entrypoint_8(glglobalsettings_entrypoint_7());
    glglobalsettings_entrypoint_5(&local_0, &local_1);
    glglobalsettings_entrypoint_6(local_0, local_1);
}

int func_80800084_glglobalsettings()
{
    heap_alloc(0x80);
}

s32 func_808000A4_glglobalsettings(s32 param_0, s32 param_1)
{
    s32 i;
    s32 ret;

    for (i = 3; i != 0; i--) {
        ret = _glgamestore_entrypoint_1(param_0, param_1);
        if (ret == 0) {
            break;
        }
    }

    if (ret != 0) {
        _glglobaldata_entrypoint_4(param_1);
    }

    return ret;
}

s32 func_80800114_glglobalsettings(void *param_0)
{
  s32 i;
  s32 new_var;
  new_var = (s32) param_0;
  for (i = 0; i < 2; i++)
  {
    if (i != new_var)
    {
      _glgamestore_entrypoint_5(i);
    }
  }

}

s32 func_80800168_glglobalsettings(s32 *param_0) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s5;

    var_s1 = func_80800084_glglobalsettings();
    var_s5 = -1;
    var_s0 = 0;
    var_s2 = 0;
    do {
        if (func_808000A4_glglobalsettings(var_s0, var_s1) != 0) {
            goto skip_block;
        }
        temp_v0 = var_s1;
        var_s1 = *param_0;
        var_s2 += 1;
        var_s5 = var_s0;
        *param_0 = temp_v0;
    skip_block:
        var_s0 += 1;
    } while (var_s0 != 2);
    if (var_s2 >= 2) {
        func_80800114_glglobalsettings(var_s5);
    }
    heap_free(var_s1);
    return var_s5;
}

s32 glglobalsettings_entrypoint_1(void) {
    s32 temp;
    void *local_0;

    local_0 = func_80800084_glglobalsettings();
    temp = func_80800168_glglobalsettings(&local_0);
    if (temp == -1) {
        glglobalsettings_entrypoint_0();
    } else {
        _glglobaldata_entrypoint_2(local_0);
        func_80800034_glglobalsettings();
    }
    heap_free(local_0);
}

s32 func_80800278_glglobalsettings(s32 param_0, s32 param_1) {
    s32 local_3;
    s32 local_4;
    s32 local_2;

    local_4 = 3;
    local_3 = func_80800084_glglobalsettings();
loop_1:
    local_2 = _glgamestore_entrypoint_3(param_0, param_1);
    if (local_2 == 0) {
        func_808000A4_glglobalsettings(param_0, local_3);
    }
    local_4 -= 1;
    if ((local_2 != 0) && (local_4 != 0)) {
        goto loop_1;
    }
    heap_free(local_3);
    return local_2;
}

s32 glglobalsettings_entrypoint_2(void) {
    s32 local_0;
    s32 local_1;
    s32 local_5;
    s32 local_3;

    if (func_800DA298(0xD54) == 0) {
        return 0;
    }
    local_3 = func_80800084_glglobalsettings();
    local_1 = func_80800168_glglobalsettings(&local_3);
    _glglobaldata_entrypoint_3(local_3);
    local_5 = 0;
loop_3:
    if (local_5 == local_1) {
        local_5 += 1;
        if (local_5 != 2) {
            goto loop_3;
        }
    }
    local_0 = func_80800278_glglobalsettings(local_5, local_3);
    if (local_0 == 0) {
        func_80800114_glglobalsettings(local_5);
        func_800DA524(0xD54);
    }
    heap_free(local_3);
    return local_0;
}

s32 glglobalsettings_entrypoint_3()
{
    return func_800DA298(GFLAG_BB9_WIDESCREEN_ENABLED);
}

s32 glglobalsettings_entrypoint_4(param_0) int param_0; {
    set_widescreen(param_0);
    func_800DA3B8(0xBB9, param_0 ? 1 : 0);
}

int glglobalsettings_entrypoint_5(param_0, param_1) s32 *param_0; s32 *param_1;
{
  s32 local_0;
  local_0 = func_800DA564(0xBBA, 6);
  param_0[0] = local_0 - 0x20;
  param_1[0] = func_800DA564(0xBC0, 6) - 0x28;
}

void glglobalsettings_entrypoint_6(param_0, param_1) s32 param_0; s32 param_1;
{
    func_80015670();
    param_0 += 0x20;
    param_1 += 0x28;
    if (param_0 >= 0x40) {
        param_0 = 0x3F;
    }
    if (param_1 >= 0x40) {
        param_1 = 0x3F;
    }
    func_800DA7A8(0xBBA, param_0, 6);
    func_800DA7A8(0xBC0, param_1, 6);
}

s32 glglobalsettings_entrypoint_7(void){
    func_800DA564(0xBC6, 2);
}

void glglobalsettings_entrypoint_8(param_0) s32 param_0;
{
    func_80012F0C(D_80800560_glglobalsettings[param_0][0]);
    func_80012F34(0, D_80800560_glglobalsettings[param_0][1]);
    func_80012F34(1, D_80800560_glglobalsettings[param_0][1]);
    func_800DA7A8(0xBC6, param_0, 2);
}
