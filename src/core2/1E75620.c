#include "core2/1E75620.h"
#include <ultra64.h>
#include "types.h"

extern void bastatetimer_set(void *, int, f32);
extern s32 bastatetimer_isDone(void *, s32);
void func_8009BDAC(PlayerState *param_0, f32 param_1);

s32 func_8009BD30() 
{
    return 0x1;
}

void func_8009BD38(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0xD4)))[0] = v;
}

s32 func_8009BD44(void *arg)
{
    return ((u8 *)(*(void **)((char *)arg + 0xD4)))[0];
}

void func_8009BD50(void *param_0)
{
  void *local_0;
  ;
  *((u8 *) (*((void **) (((char *) param_0) + 0xD4)))) = 0;
  func_8009BD38(param_0, 1);
  bastatetimer_clear(param_0, 4);
}

void func_8009BD88(PlayerState *param_0) {
    func_8009BDAC(param_0, 0.6f);
}

void func_8009BDAC(PlayerState *param_0, f32 param_1)
{
  bastatetimer_set(param_0, 4, param_1);
  func_8009BD38(param_0, 3);
}

void func_8009BDE4(void *param_0)
{
    if (bastatetimer_isDone(param_0, 4)) {
        func_8009BD38(param_0, 1);
    }
}
