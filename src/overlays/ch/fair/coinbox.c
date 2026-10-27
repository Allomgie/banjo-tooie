#include "common.h"

typedef struct { u8 pad[0x76]; u16 f76:9; u16 pad76:7; } CoinBoxState;
extern s16 func_80800424_chfaircoinbox[];
extern void func_800DA544(s32);
extern s32 func_808002E4_chfaircoinbox[];
typedef struct { s32 a; s32 b; } CoinEnt;
extern CoinEnt D_80800470_chfaircoinbox[];
extern s32 func_800DA298(s32);
extern s32 func_8008FB10(f32 *, f32, f32, f32);
extern u16 D_80800490_chfaircoinbox;
extern s16 D_80800494_chfaircoinbox;
extern s32 func_808003E4_chfaircoinbox[];
typedef union { s32 local_0; s16 local_1[2]; } CoinboxMessage;
extern s32 D_808004B8_chfaircoinbox;
extern int D_808004C8_chfaircoinbox;
void func_808002CC_chfaircoinbox();
void func_80800264_chfaircoinbox();

s16 func_80800000_chfaircoinbox(param_0) CoinBoxState *param_0; {
    return func_80800424_chfaircoinbox[param_0->f76];
}

void func_8080001C_chfaircoinbox(u8 *param_0) {
    func_800DA544(*(s32 *)((char *)func_808002E4_chfaircoinbox + ((u32)((u16) * (u16 *)(param_0 + 0x76)) >> 7) * 8));
}

s32 func_80800050_chfaircoinbox(CoinBoxState *param_0) {
    s32 local_1 = param_0->f76 - 0x32;
    if (func_800DA298(D_80800470_chfaircoinbox[local_1].b)) {
        func_800DA544(D_80800470_chfaircoinbox[local_1].a);
    }
    return D_80800470_chfaircoinbox[local_1].a;
}

void func_808000A4_chfaircoinbox(Actor *param_0, s32 param_1)
{
    func_80101FDC(param_0, param_1);
    switch (param_0->unk70_10) {
    case 2:
        func_800904F4(0x46, param_0->unk0);
        break;
    case 3:
        func_800C01A8(100, 0);
        func_8080001C_chfaircoinbox(param_0);
        func_80090708(0);
        func_800FC660(0x10);
        switch (param_0->unk74_7 - 0x32) {
        case 0:
            func_80101180(0x340, 10, 0);
            break;
        case 1:
            func_80101180(0x307, 10, 0);
            break;
        }
        break;
    }
}

void func_8080016C_chfaircoinbox(s32 arg0) 
{
}
int func_80800174_chfaircoinbox(s32 param_0)
{
  func_8010A63C();
  if (func_800DA298(func_80800050_chfaircoinbox(param_0)) != 0)
  {
    func_808000A4_chfaircoinbox(param_0, 4);
    return;
  }
  func_808000A4_chfaircoinbox(param_0, 1);
}

void func_808001C8_chfaircoinbox(Actor *param_0)
{
    func_8008FB10(param_0->position, 120.0f, 0.0f, 92.0f);
    switch (param_0->unk70_10) {
    case 1:
        if (func_800DA298(func_80800050_chfaircoinbox(param_0))) {
            func_808000A4_chfaircoinbox(param_0, 3);
            break;
        }
        func_808002CC_chfaircoinbox(param_0);
        break;
    case 2:
    case 3:
    case 4:
        break;
    }
}

void func_80800264_chfaircoinbox(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    (void)&param_2;

    switch (param_1) {
    case 0x10B4:
        func_80090708(0);
        break;
    case 0x10B5:
    case 0x10B6:
    case 0x10B7:
        func_808000A4_chfaircoinbox(param_0, 2);
        break;
    case 0x10B8:
        func_808000A4_chfaircoinbox(param_0, 3);
        break;
    }
}

void func_808002CC_chfaircoinbox(param_0) Actor *param_0;
{
    s32 local_0;

    D_80800494_chfaircoinbox = func_808003E4_chfaircoinbox[param_0->unk74_7];
    local_0 = func_80800000_chfaircoinbox();
    D_80800490_chfaircoinbox = local_0;
    if (func_800DA298((u16)local_0)) {
        return;
    }
    /* Probe: `^ 0` makes the first argument a new value, so param_0 lives in its copy for the fourth argument (a3)
     * as in the target (lw a3 + or a0,a3); compare chgameselect 944/998. */
    local_0 = _subaddiedialog_entrypoint_7((Actor *)((s32)param_0 ^ 0), param_0->position, &D_80800490_chfaircoinbox, param_0);
    if (local_0 != 0) {
        /* empty else-if chain over the dialog IDs of this file's table: keeps the beq test for 0x10B5 (the original body was probably debug code) */
        if (local_0 == 0x10B5) {
        } else if (local_0 == 0x10B6) {
        } else if (local_0 == 0x10B7) {
        } else if (local_0 == 0x10B4) {
        }
        func_80090734(1, param_0->position);
    }
}

s32 chfaircoinbox_entrypoint_0(s32 param_0, s32 param_1)
{
  func_800EE7F8(param_1, func_80106790(param_0) + 4);
  return 1;
  func_80106790(param_0);
}

void chfaircoinbox_entrypoint_1()
{
  int new_var;
  s32 *temp_v0;
  temp_v0 = func_80106790();
  _subaddiedialog_entrypoint_11(*temp_v0, 0x10B8, 4, temp_v0 + 1, 0x8C);
}

s32 func_808003C4_chfaircoinbox(Actor *param_0, s32 param_1, CoinboxMessage param_2)
{
    switch (param_1) {
    case 0x2E:
        func_80800264_chfaircoinbox(param_0, param_2.local_1[0], param_2.local_1[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_808004B8_chfaircoinbox, *(void **)((u8 *)param_0 + 0x38));
        break;
    default:
        return 0;
    }
    return 1;
}

int chfaircoinbox_entrypoint_2(void)
{
    return (int)&D_808004C8_chfaircoinbox;
}
