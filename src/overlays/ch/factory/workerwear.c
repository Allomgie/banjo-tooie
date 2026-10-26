#include "common.h"

extern void *D_80800438_chfactoryworkerwear;
extern f32 D_80800480_chfactoryworkerwear[];
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_80013970(f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern u8 *func_80100094(s32, s32);
extern void func_80101038();
extern f32 func_80101068(void);
extern f32 func_800136E4(f32);
void func_8080000C_chfactoryworkerwear();

void *chfactoryworkerwear_entrypoint_0()
{
    return &D_80800438_chfactoryworkerwear;
}

void func_8080000C_chfactoryworkerwear(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 2:
            *(f32 *)local_0 = param_0->scale;
            func_800EE7F8((f32 *)(local_0 + 4), param_0->position);
            func_8010A800(param_0, 1);
            break;
        case 3:
            func_800EE7F8(param_0->position, (f32 *)(local_0 + 0x10));
            param_0->rotation[1] = func_800136E4(param_0->rotation[1] + 180.0f);
            param_0->scale = 1.0f;
            break;
        case 4:
            param_0->rotation[2] = 0.0f;
            param_0->scale = 0.4f;
            func_801032B0(param_0, 0x83C, param_0->unk0->unk16);
            break;
    }
    func_80102424(param_0, param_1);
}

void func_80800100_chfactoryworkerwear(s32 param_0) {
    *(u8 *)(func_80100094(param_0, 0) + 0x24) = 0;
}

void func_80800124_chfactoryworkerwear(s32 arg0) 
{
}
void func_8080012C_chfactoryworkerwear(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
        case 1:
            break;
        case 2:
            func_800EFE50(param_0->position, (f32 *)(local_0 + 4),
                (f32 *)(local_0 + 0x10), *(f32 *)(local_0 + 0x1C));
            param_0->scale = func_800F1214(*(f32 *)(local_0 + 0x1C), *(f32 *)local_0, 0.4f);
            break;
        case 3:
            param_0->rotation[2] += *(f32 *)(local_0 + 0x20) * func_800D8FF8();
            break;
        case 4:
            func_800BBCB8(param_0->position, 0, 1.0f, 5, D_80800480_chfactoryworkerwear);
            func_800EFE50(param_0->position, (f32 *)(local_0 + 4),
                (f32 *)(local_0 + 0x10), *(f32 *)(local_0 + 0x1C));
            param_0->position[1] += func_80013970(*(f32 *)(local_0 + 0x1C) * 180.0f) * 30.0f;
            param_0->scale = func_800F1214(*(f32 *)(local_0 + 0x1C), *(f32 *)local_0, 0.4f);
            break;
    }
}

int func_80800260_chfactoryworkerwear(Actor *param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_80100094(param_0, 0);
  *(u8 *)((char *)(local_0) + 0x24) = param_1;
  switch (param_1)
  {
    case 1 :
      func_8080000C_chfactoryworkerwear(param_0, 2);
      return;
    case 2 :
      func_8080000C_chfactoryworkerwear(param_0, 3);
      return;
    case 3 :
      func_8080000C_chfactoryworkerwear(param_0, 4);
      return;
  }
}

void func_808002E4_chfactoryworkerwear(s32 param_0) {
    u8 *local_0 = func_80100094(param_0, 0);
    func_80101038(local_0 + 0x10);
    *(f32 *)(local_0 + 0x1C) = func_80101068();
}

void func_80800320_chfactoryworkerwear(s32 param_0) {
    u8 *local_0 = func_80100094(param_0, 0);
    *(f32 *)(local_0 + 0x20) = func_80101068();
}

int func_80800350_chfactoryworkerwear(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x21:
            switch (((s16 *)&param_2)[0]) {
                case 1: func_80800260_chfactoryworkerwear(param_0, ((s16 *)&param_2)[1]); break;
                case 2: func_80800320_chfactoryworkerwear(param_0); break;
                case 3: func_808002E4_chfactoryworkerwear(param_0); break;
            }
            break;
        case 0x2C:
            func_800FFA88(param_0->unk0);
            break;
    }
    return 0;
}
