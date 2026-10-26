#include "common.h"

typedef struct { s16 local_0; u16 local_1; s32 local_2; s16 local_3; s16 local_4[2]; u16 local_5; } GSWorldData49;

void gsworldDll_entrypoint_0(s32 param_0, s32 param_1) {
    s32 local_0;

    func_8001A2B0();
    local_0 = _gsmaker_entrypoint_2(param_0);
    if (_gsmaker_entrypoint_16(local_0, 0) == 0) {
        do {
            if (_gsmaker_entrypoint_16(local_0, 2) == 0) {
                if (_gsmaker_entrypoint_16(local_0, 1) != 0) {
                    func_800BDC68(local_0);
                } else if (_gsmaker_entrypoint_16(local_0, 4) != 0) {
                    func_800C90F4(local_0);
                } else if (_gsmaker_entrypoint_16(local_0, 5) == 0) {
                    if (_gsmaker_entrypoint_16(local_0, 6) != 0) {
                        _cadbio_entrypoint_0(local_0);
                    } else if (_gsmaker_entrypoint_16(local_0, 7) != 0) {
                        func_800BDC90(local_0);
                    }
                }
            }
        } while (_gsmaker_entrypoint_16(local_0, 0) == 0);
    }
    _gsmaker_entrypoint_0(local_0);
}

void gsworldDll_entrypoint_1(u8 *param_0) {
  _gccollectDll_entrypoint_5();
  func_800EA148(3);
  func_800C00E0();
  _sufade_entrypoint_2();
  _subaddierouteDll_entrypoint_0();
  func_800C7500();
  func_800D8800();
  func_800D743C();
  func_800A5CC4();
  func_800D8898();
  _glcutDll_entrypoint_5();
  func_800F732C();
  func_800B5E04();
  func_800FA660();
  _chbounce_entrypoint_1();
  func_800E1748();
  func_800A5630();
  func_800B5AD4();
  func_800B5824();
  func_800B5054();
  func_800B7CC4();
  _gcgoto_entrypoint_12();
  func_800BD5DC();
  func_800CB9AC();
  func_800C5770();
  func_800BF420();
  func_800BFCB4();
  func_800C90D0();
  func_800BFF28();
  _idworldmake_entrypoint_3();
  func_80100610();
  func_80100B4C();
  _sulights_entrypoint_8();
  func_800C7A60();
  func_800AB9D0();
  func_800FFDBC();
  func_8010D89C();
  func_800E4CE8();
  func_800E9774();
  func_800C6A60();
  func_800D2E4C();
  func_800EBC04();
  _gldialog_entrypoint_3();
  func_800FF038((*(u16 *)((s8 *)(param_0) + (2))));
  func_800DBB24();
  func_800E8B04();
  func_800D2970();
  func_800E86DC();
  func_800BC8A0();
}

void gsworldDll_entrypoint_2(GSWorldData49 *param_0, unsigned int param_1, s32 param_2, s32 param_3)
{
  param_0->local_5 = param_0->local_1;
  param_0->local_0 = 3;
  param_0->local_1 = param_1;
  param_0->local_2 = _gcsectionDll_entrypoint_2(param_1);
  param_0->local_3 = param_2;
  func_800A9EC0((s32) param_1);
  func_800D8800();
  func_800BC690();
  func_800E829C();
  func_800E8A60();
  func_800EA334(1);
  func_800EA34C(1);
  func_800D9FFC();
  func_800A5320();
  func_800D298C();
  func_800A5AB0();
  func_8010052C();
  func_80100B3C();
  func_800C6A68();
  _idworldmake_entrypoint_4();
  func_800C90AC();
  func_800BF444();
  _gcwater_entrypoint_0();
  func_800C5778();
  _gldialog_entrypoint_2();
  func_800D8870();
  func_800A5C04();
  func_800EBB94();
  func_800E9728();
  _gcgoto_entrypoint_13();
  func_800C7A58();
  func_800A55E0();
  func_800B5028();
  func_800B5884();
  func_800B5B04();
  func_800B7D14();
  func_800BFCBC();
  func_800BFF4C();
  func_800AB980();
  func_800CB988();
  func_800BD570();
  func_800FA010();
  if (param_3 != 0xF)
  {
    gsworldDll_entrypoint_0((s32) param_1, param_3);
  }
  func_800BF68C();
  func_800D2CD0();
  func_800D5250();
  func_800C00BC();
  func_800DA048();
  _glintrosyncDll_entrypoint_6((s32) param_1);
  func_800D7418();
  _glhittableDll_entrypoint_0();
  func_8010D790();
  func_800A5C28();
  func_800F73C4(_gcstatusDll_entrypoint_11());
  func_800E1788();
  func_800FE740();
  func_800C73A4();
  _chbounce_entrypoint_0();
  func_800A5124(param_0->local_3);
  func_800B5DFC();
  func_800A5C94();
  _glcutDll_entrypoint_4();
}

void gsworldDll_entrypoint_3(s16 *param_0, long param_1)
{
  func_8001A2B0(param_0, param_1);
  func_800A5104(*param_0, param_1);
  func_800C2A5C(*param_0, param_1);
  func_800FE8BC(*param_0, param_1);
  func_800C7574(*param_0, param_1);
  func_800B5654(*param_0, param_1);
  *param_0 = param_1;
}

void func_8080054C_gsworldDll(s32 arg0, s32 arg1, s32 arg2) {
}
int gsworldDll_entrypoint_4(volatile u16 *param_0)
{
  int new_var;
  u16 local_0;
  new_var = (unsigned int) 0;
  ;
  ;
  new_var = 1;
  func_8080054C_gsworldDll(new_var, param_0[new_var], "world.gs");
}
