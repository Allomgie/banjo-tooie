#include "common.h"

extern void func_80114CB0(s32, f32);
extern void func_80114CC0(s32, f32);
extern s32 D_80137320;
extern s32 D_80137330;
extern void func_80114C9C();
extern u8 unk10[];
typedef struct { void *unk0; void *unk4; u8 pad8[4]; void *unkC; void *unk10; } S_110068;
extern S_110068 *defrag(S_110068 *);
extern void *func_80110FCC(void *, S_110068 *);
extern void *func_80115324(void *, S_110068 *);
extern void *func_80114CD4(void *);

void func_8010F9C0(u8 *param_0, s32 param_1) {
    if (param_1 != (*(s16 *)((s8 *)param_0 + 0x16))) {
        switch ((*(s16 *)((s8 *)param_0 + 0x16))) {
        case 1:
            break;
        case 3:
            _ncfixposrot_entrypoint_1((*(s32 *)((s8 *)param_0 + 8)));
            (*(s32 *)((s8 *)param_0 + 8)) = 0;
            break;
        case 8:
            _ncpod_entrypoint_1((*(s16 *)((s8 *)param_0 + 0x14)));
            (*(s16 *)((s8 *)param_0 + 0x14)) = 0;
            break;
        case 2:
            if ((*(s32 *)((s8 *)param_0 + 4)) != 0) {
                func_80110B68((*(s32 *)((s8 *)param_0 + 4)), 0);
            }
            break;
        }
        (*(s16 *)((s8 *)param_0 + 0x16)) = (s16) param_1;
        switch (param_1) {
        case 1:
            break;
        case 3:
            (*(s32 *)((s8 *)param_0 + 8)) = _ncfixposrot_entrypoint_0();
            return;
        case 2:
            if ((*(s32 *)((s8 *)param_0 + 4)) != 0) {
                func_80110B68((*(s32 *)((s8 *)param_0 + 4)), 1);
                return;
            }
            (*(s32 *)((s8 *)param_0 + 4)) = func_80110424(param_0, (*(s32 *)((s8 *)param_0 + 0x1C)));
            return;
        case 8:
            (*(s16 *)((s8 *)param_0 + 0x14)) = _ncpod_entrypoint_0((*(s32 *)((s8 *)param_0 + 0x1C)));
            break;
        }
    }
}

int func_8010FAE4(s16 *param_0)
{
  s16 new_var2;
  int new_var;
  short new_var3;
  new_var = 5;
  new_var3 = 0;
  new_var3 = new_var;
  new_var3 = new_var3 ^ new_var3;
  new_var2 = param_0[11];
  return new_var2;
}

void func_8010FAEC(void *param_0, void *param_1)
{
  s32 *new_var;
  new_var = (s32 *) param_1;
  if (new_var[3])
  {
    if (func_800A9420(new_var[7]) != 0)
    {
      func_80114FA4(param_0, new_var[3], param_1);
    }
  }
}

u8 *func_8010FB34(s32 param_0, s32 param_1) {
    u8 *local_0;

    local_0 = heap_alloc(0x40);
    *(s32 **)((char *)local_0 + 0) = (s32 *)param_0;
    *(s8 *)((char *)local_0 + 0x18) = 0;
    *(s8 *)((char *)local_0 + 0x19) = 0;
    *(s8 *)((char *)local_0 + 0x20) = 0;
    *(s32 **)((char *)local_0 + 0x10) = (s32 *)func_80114BD4();
    if (func_800DA298(0x6B5) != 0) {
        *(s32 **)((char *)local_0 + 0xC) = (s32 *)func_80115118(local_0);
    } else {
        *(s32 **)((char *)local_0 + 0xC) = (s32 *)0;
    }
    *(s32 **)((char *)local_0 + 0x1C) = (s32 *)param_1;
    *(s32 **)((char *)local_0 + 4) = (s32 *)func_80110424(local_0, param_1);
    *(s32 **)((char *)local_0 + 8) = (s32 *)0;
    *(s16 *)((char *)local_0 + 0x14) = 0;
    *(s16 *)((char *)local_0 + 0x16) = 0;
    func_8010F9C0(local_0, 1);
    return local_0;
}

void func_8010FBD4(void *param_0)
{
  void *s0 = param_0;
  void **new_var;
  func_8010F9C0(s0, 1);
  if ((*((void **) (((u8 *) s0) + 0x4))) != 0)
  {
    func_801104F4(*((void **) (((u8 *) s0) + 0x4)));
  }
  ;
  if ((*((void **) (((u8 *) s0) + 0xC))) != 0)
  {
    func_801150F8(*(&(*((void **) (((u8 *) s0) + 0xC)))));
  }
  func_80114C7C(*((void **) (((u8 *) s0) + 0x10)));
  heap_free(s0);
}

void func_8010FC38(u8 *param_0)
{
    f32 local_1[3];
    f32 local_2[3];
    s16 local_0;
    s32 pad0;

    local_0 = *(s16 *)(param_0 + 0x16);
    if ((param_0[0x18] == 0) && (param_0[0x19] == 0))
    {
        local_0 = 0;
    }
    switch (local_0)
    {
    case 2:
        func_80110588(*(s32 *)(param_0 + 4));
        break;
    case 3:
        _ncfixposrot_entrypoint_6(*(s32 *)(param_0 + 8), param_0);
        break;
    case 8:
        _ncpod_entrypoint_14(*(s16 *)(param_0 + 0x14), param_0);
        break;
    }
    func_800CA8B4(*(s32 *)param_0, &local_1, &local_2);
    func_800E1A58(&local_1, &local_2);
    func_800CA628(*(s32 *)param_0, &local_1, &local_2);
    if (*(s32 *)(param_0 + 0xC) != 0)
    {
        func_801151C4(*(s32 *)(param_0 + 0xC));
    }
}

void func_8010FD08(param_0) s32 param_0;
{
    s32 local_0;
    local_0 = param_0;
    *(u8 *)(local_0 + 0x19) = 1;
    func_8010FC38(local_0);
    *(u8 *)(local_0 + 0x19) = 0;
}

void func_8010FD38(void *param_0, f32 param_1) {
    func_80114CB0(*(s32 *)((u8 *)param_0 + 0x10), param_1);
}

void func_8010FD60(void *param_0, f32 param_1) {
    func_80114CC0(*(s32 *)((u8 *)param_0 + 0x10), param_1);
}

void func_8010FD88()
{
    func_8010FD08();
}

void func_8010FDA8(u8 *param_0, s32 param_1, u8 *param_2)
{
    (*(u8 *)((char *)(param_0) + 32)) = 0x28;
    func_800EE7F8(param_0 + 0x24, param_1);
    func_800EE7F8(param_0 + 0x30, param_2);
}

func_8010FDEC(s32 param_0, f32 param_1){
    ((u8 *)param_0)[0x20] = 0x29;
    ((f32 *)((u8 *)param_0 + 0x3C))[0] = param_1;
}

void func_8010FE00(s32 param_0, s32 param_1, unsigned int param_2)
{
  u8 *local_0 = (u8 *) (((s32 *) param_0) + 6);
  *local_0 = param_2 == 2;
}

int func_8010FE14(param_0) s32 param_0[3];
{
  func_800CA628(param_0[0]);
}

void func_8010FE34(u8 *param_0, s32 param_1) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)(param_0) + (0x20)));
    if (temp_v0 != 0) {
        (*(u8 *)((s8 *)(param_0) + (0x20))) = 0U;
        if ((*(s16 *)((s8 *)(param_0) + (0x16))) == 2) {
            switch (temp_v0) {                      
            case 40:
                func_8010FE14(param_0, param_0 + 0x24, param_0 + 0x30);
                func_801108A0((*(s32 *)((s8 *)(param_0) + (4))));
                break;
            case 41:
                func_80110970((*(s32 *)((s8 *)(param_0) + (4))), (*(s32 *)((s8 *)(param_0) + (0x3C))));
                break;
            }
            func_8010FD08(param_0);
            return;
        }
    }
    if (_ncstart_entrypoint_0(param_1, &D_80137320, &D_80137330) == 0) {
        if ((*(s16 *)((s8 *)(param_0) + (0x16))) == 2) {
            func_80110928((*(s32 *)((s8 *)(param_0) + (4))));
        }
        func_8010FD08(param_0);
        return;
    }
    if ((*(s16 *)((s8 *)(param_0) + (0x16))) == 2) {
        func_80110A24((*(s32 *)((s8 *)(param_0) + (4))), &D_80137330, &D_80137320);
    }
    func_800CA5B8((*(s32 *)((s8 *)(param_0) + (0))), &D_80137320);
    func_800CA668((*(s32 *)((s8 *)(param_0) + (0))), &D_80137330);
    func_800CAF34((*(s32 *)((s8 *)(param_0) + (0))));
    if ((*(s16 *)((s8 *)(param_0) + (0x16))) == 2) {
        func_801108A0((*(s32 *)((s8 *)(param_0) + (4))));
        func_8010FD08(param_0);
    }
}

func_8010FF80(s32 param_0){
    return *(s32*)param_0;
}

void func_8010FF88(Actor *param_0)
{
  func_80114C9C(*(int *)((char *)param_0 + 0x10));
}

func_8010FFA8(s32 param_0) {
    s16 local_0;
    local_0 = *(s16*)((char*)param_0 + 0x16);
    return local_0;
}

int func_8010FFB0(param_0) s32 param_0[3];
{
  func_800CA8B4(param_0[0]);
}

func_8010FFD0(u8 *param_0) {
    return param_0[0x19];
}

s32 func_8010FFD8(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    local_1 = *(s32 *)(param_0 + 0xC);
    if (local_1 != 0) {
        local_0 = func_801150F0(local_1);
    } else {
        local_0 = 0;
    }
    return local_0;
}

int func_80110014(s32 param_0[3])
{
  return param_0[1];
}

func_8011001C(param_0)
{
    return ((s32*)param_0)[2];
}

int func_80110024(s32 param_0, s32 param_1)
{
  param_1 = *(s16 *)(param_0 + 0x14);
  if (param_1 != 0)
  {
    return _ncpod_entrypoint_2((s16)param_1);
  }
  return 0;
}

func_80110060(Actor *param_0) {
    return (*(s32 *)((char *)(param_0) + 0x10));
}

S_110068 *func_80110068(S_110068 *param_0, void *param_1) {
    S_110068 *p = defrag(param_0);
    p->unk0 = param_1;
    if (p->unk4 != 0) { p->unk4 = func_80110FCC(p->unk4, p); }
    if (p->unkC != 0) { p->unkC = func_80115324(p->unkC, p); }
    if (p->unk10 != 0) { p->unk10 = func_80114CD4(p->unk10); }
    return p;
}

void func_801100E4(s32 *param_0, s32 *param_1)
{
    f32 local_fpc[3];
    f32 local_fp[3];

    if (param_0 != param_1)
    {
        func_800CA314((void *)param_0[0], (void *)param_1[0]);
        if (param_0[1] != 0)
        {
            func_8010FFB0((void *)param_1, local_fpc, local_fp);
            func_80110770((void *)param_0[1], local_fpc);
            func_80110790((void *)param_0[1], local_fp);
            func_80111018((void *)param_0[1], (void *)param_1[1]);
        }
    }
}

void func_80110164(u8 *param_0) {
    s32 local_0;
    s32 local_1;

    func_8011490C((*(s32 *)((s8 *)(param_0) + (0x10))), param_0, (*(s32 *)((s8 *)(param_0) + (0x1C))));
    func_80114C9C((*(s32 *)((s8 *)(param_0) + (0x10))), &local_0, &local_1, param_0);
    func_800CA6C0((*(s32 *)((s8 *)(param_0) + (0))), local_0, local_1, param_0);
}
