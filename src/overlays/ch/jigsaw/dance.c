#include "common.h"

extern int D_80800488_chjigsawdance;
extern f32 func_80101F24(void);
extern f32 func_80090010(void);
extern void *func_8008FD20(void);
extern void *func_80104248(Actor *);
extern f32 anctrl_getAnimTimer(void *);
extern void anctrl_setStart(void *, f32);
extern void anctrl_setDuration(void *, f32);

void func_80800000_chjigsawdance(Actor *param_0)
{
  if (func_800CFA70((s32)param_0->unk50, 1) != -1) {
    param_0->unk6C_0 = func_800C8A98();
    func_800CF9E4((s32)param_0->unk50, 1, param_0->unk6C_0);
    func_800C8CB8(param_0->unk6C_0, (u8 *)param_0 + 4);
    return;
  }
  param_0->unk6C_0 = 0;
}

int func_808000AC_chjigsawdance(Actor *param_0)
{
  Actor *new_var;
  s32 local_0;
  s32 new_var5;
  char *new_var4;
  s32 new_var2;
  s32 new_var3;
  new_var5 = *((s32 *) ((new_var4 = (char *) param_0) + 0x6C));
  local_0 = new_var5 & 0x1FF;
  new_var2 = (unsigned short) local_0;
  new_var3 = new_var2;
  if (new_var3 != 0)
  {
    func_800C8B84(new_var3);
    new_var = param_0;
    *((u16 *) (((char *) new_var) + 0x6E)) &= 0xFE00;
  }
  if (!param_0)
  {
  }
}

void func_808000F0_chjigsawdance(Actor *param_0)
{
    void *local_0;
    void *local_2;
    f32 local_1[3];

    if (param_0->unk6C_0) {
        if (func_80101F24() > 0.85f) {
            func_800C8B84(param_0->unk6C_0);
            param_0->unk6C_0 = 0;
        } else {
            func_8008FE94(7, local_1);
            func_800C8CB8(param_0->unk6C_0, local_1);
        }
    }
    switch (param_0->unk70_10) {
        case 1:
            break;
        case 2:
            func_8010D254(param_0->position);
            param_0->rotation[1] = func_80090010();
            local_0 = func_8008FD20();
            local_2 = func_80104248(param_0);
            anctrl_setSmoothTransition(local_2, 0);
            anctrl_setIndex(local_2, anctrl_getIndex(local_0));
            anctrl_setStart(local_2, anctrl_getAnimTimer(local_0));
            anctrl_setDuration(local_2, 1000.0f);
            anctrl_start(local_2);
            break;
        case 3:
            local_0 = func_8008FD20();
            local_2 = func_80104248(param_0);
            anctrl_setSmoothTransition(local_2, 0);
            anctrl_setStart(local_2, anctrl_getAnimTimer(local_0));
            anctrl_setDuration(local_2, 1000.0f);
            anctrl_start(local_2);
            break;
        case 4:
            func_8010D254(param_0->position);
            param_0->rotation[1] = func_80090010();
            local_0 = func_8008FD20();
            local_2 = func_80104248(param_0);
            anctrl_setSmoothTransition(local_2, 0);
            anctrl_setStart(local_2, anctrl_getAnimTimer(local_0));
            anctrl_setDuration(local_2, 1000.0f);
            anctrl_start(local_2);
            break;
    }
}

s32 chjigsawdance_entrypoint_0(Actor *this, s32 param_1){
    this->unk50 = param_1;
}

void chjigsawdance_entrypoint_1(Actor *param_0, s32 param_1)
{
    void *local_0;

    switch (param_1) {
        case 3:
            if (param_0->unk70_10 == 1) {
                func_80101FDC(param_0, 2);
                anctrl_setPlaybackType(func_80104248(param_0), 1);
            }
            break;
        case 2:
            func_80101FDC(param_0, 3);
            break;
        case 1:
            func_80101FDC(param_0, 4);
            break;
        case 4:
            func_8010D254(param_0->position);
            param_0->rotation[1] = func_80090010();
            local_0 = func_80104248(param_0);
            anctrl_setSmoothTransition(local_0, 0);
            anctrl_setStart(local_0, anctrl_getAnimTimer(func_8008FD20()));
            anctrl_setDuration(local_0, 1000.0f);
            anctrl_start(local_0);
            break;
        case 5:
            if (param_0->unk6C_0) {
                func_800C8B84((s32)param_0->unk6C_0);
                param_0->unk6C_0 = 0;
            }
            func_800FFA88(param_0->unk0);
            break;
    }
}

int *chjigsawdance_entrypoint_2()
{
    return &D_80800488_chjigsawdance;
}
