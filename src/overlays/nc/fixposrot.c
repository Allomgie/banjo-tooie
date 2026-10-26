#include "common.h"

extern void func_800EFD24(void *);
extern void *heap_alloc(int);
extern void func_800F18FC();
extern f32 func_800136E4(f32);
extern void func_800C53EC(int, int);
extern void func_8010F9C0(s32, int);
extern void *func_8011001C();

void *ncfixposrot_entrypoint_0()
{
  void *local_0;
  local_0 = heap_alloc(0x1C);
  func_800EFD24(local_0);
  func_800EFD24(((char *) local_0) + 0xC);
  *(s16 *)(((char *) local_0) + 0x18) = 0;
  return local_0;
}

void ncfixposrot_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void ncfixposrot_entrypoint_2(u8 *param_0, s32 param_1) {
    func_800F18FC(param_1, param_0, param_0 + 0xC, param_1);
    *(f32 *)(param_0 + 0xC) = func_800136E4(-*(f32 *)(param_0 + 0xC));
    *(f32 *)(param_0 + 0x14) = 0.0f;
}

void ncfixposrot_entrypoint_3(void *param_0, f32 param_1) {
    *(f32 *)((u8 *)param_0 + 0x14) = func_800136E4(param_1);
}

int ncfixposrot_entrypoint_4(s32 param_0[3])
{
  func_800EE7F8(&param_0[3]);
}

void ncfixposrot_entrypoint_5()
{
    func_800EE7F8();
}

s32 ncfixposrot_entrypoint_6(s32 param_0, s32 param_1){
    func_8010FE14(param_1, param_0, param_0 + 0xC);
}

s32 ncfixposrot_entrypoint_7(s32 param_0, s32 param_1){
    func_800A5800(param_1 | 0);
    _cadbfunc_entrypoint_0(param_0);
    _cadbfunc_entrypoint_2(param_0 + 0xC);
}

int ncfixposrot_entrypoint_8(s32 param_0, s32 param_1)
{
  func_8010F9C0(param_0, 3);
  return ncfixposrot_entrypoint_7(func_8011001C(param_0), param_1);
}

void ncfixposrot_entrypoint_9(s32 param_0)
{
    void *local_0;
    local_0 = func_8011001C();
    if (*(s16 *)((char *)local_0 + 0x18) != 0)
    {
        func_800C53EC(0, 0);
        *(s16 *)((char *)local_0 + 0x18) = 0;
    }
    func_8010F9C0(param_0, 2);
    return;
}

s32 ncfixposrot_entrypoint_10(s32 param_0, s32 param_1, s32 param_2){
    s32 local_0;

    func_8010F9C0(param_0, 3);
    local_0 = func_8011001C(param_0);
    func_800EE7F8(local_0, param_1);
    func_800EE7F8(local_0 + 0xC, param_2);
}

s32 ncfixposrot_entrypoint_11(s32 param_0, s32 param_1, s32 param_2){
    s32 local_0;

    func_8010F9C0(param_0, 3);
    local_0 = func_8011001C(param_0);
    func_800EE7F8(local_0, param_1);
    ncfixposrot_entrypoint_2(local_0, param_2);
}

s32 ncfixposrot_entrypoint_12(s32 param_0, s32 param_1){
    func_800EE7F8(param_1 | 0, param_0 | 0);
}

int ncfixposrot_entrypoint_13(s32 param_0, s32 param_1)
{
  func_800EE7F8(param_1 | 0, param_0 + 0xC);
}

void ncfixposrot_entrypoint_14(Actor *param_0)
{
    func_800C52F4(0, 0);
    *(s16 *)((char *)param_0 + 0x18) = 1;
}
