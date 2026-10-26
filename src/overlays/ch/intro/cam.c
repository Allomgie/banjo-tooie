#include "common.h"

extern void _capod_entrypoint_13(s32, s32, s32, s32);
extern s32 func_800EA05C(void);
extern int D_80800A20_chintrocam;
extern s32 _capod_entrypoint_17(f32);

void func_80800000_chintrocam(void *param_0)
{
  int new_var2;
  u16 *new_var3;
  void *new_var;
  new_var3 = (u16 *) (((s8 *) param_0) + 0x6E);
  *((u16 *) (((s8 *) param_0) + 0x6E)) = (u16) (((*new_var3) & 0xFE00) | ((func_800EA05C() & 0x1FF) & 0xFFFFu));
  new_var = param_0;
  _capod_entrypoint_13(*((s32 *) (((s8 *) param_0) + 0)), new_var2 = 0, (s32) (*((f32 *) (((s8 *) new_var) + 0x48))), 0x6822);
}

void func_80800054_chintrocam(s32 arg0) 
{
}
void func_8080005C_chintrocam(Actor *param_0)
{
    switch (*(u32 *)((char *)param_0 + 0x6C) & 0x1FF) {
        case 0xA1:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x5D, -2);
            }
            break;

        case 0xA2:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x5D, -2);
            }
            if (_capod_entrypoint_17(1400.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x24, -2);
            }
            break;

        case 0xA3:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x5D, -2);
            }
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x25, -2);
            }
            if (_capod_entrypoint_17(2300.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x28, -2);
            }
            if (_capod_entrypoint_17(2800.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x2A, -2);
            }
            break;

        case 0xA4:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x5D, -2);
            }
            if (_capod_entrypoint_17(4200.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x68, -2);
            }
            if (_capod_entrypoint_17(4200.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x69, -2);
            }
            if (_capod_entrypoint_17(4195.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6A, -2);
            }
            break;

        case 0xA5:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x5D, -2);
            }
            if (_capod_entrypoint_17(550.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x56, -2);
            }
            break;

        case 0xA6:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x5D, -2);
            }
            if (_capod_entrypoint_17(3085.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x2F, -2);
            }
            if (_capod_entrypoint_17(3200.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x31, -2);
            }
            if (_capod_entrypoint_17(3400.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x32, -2);
            }
            break;

        case 0xA9:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x63, -2);
            }
            break;

        case 0xAC:
            if (_capod_entrypoint_17(2100.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x5E, -2);
            }
            if (_capod_entrypoint_17(2640.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x5F, -2);
            }
            if (_capod_entrypoint_17(2640.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x60, -2);
            }
            if (_capod_entrypoint_17(2640.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x61, -2);
            }
            if (_capod_entrypoint_17(2650.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x62, -2);
            }
            break;

        case 0x18E:
            if (_capod_entrypoint_17(1000.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6B, -2);
            }
            break;

        case 0x18C:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6C, -2);
            }
            if (_capod_entrypoint_17(2900.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6D, -2);
            }
            if (_capod_entrypoint_17(9250.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6E, -2);
            }
            if (_capod_entrypoint_17(9250.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6F, -2);
            }
            if (_capod_entrypoint_17(9450.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x75, -2);
            }
            if (_capod_entrypoint_17(9450.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x76, -2);
            }
            break;

        case 0x18F:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x70, -2);
            }
            if (_capod_entrypoint_17(830.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x71, -2);
            }
            break;

        case 0x190:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x72, -2);
            }
            break;

        case 0x194:
            if (_capod_entrypoint_17(3500.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x70, -2);
            }
            if (_capod_entrypoint_17(3500.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6E, -2);
            }
            if (_capod_entrypoint_17(3500.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6F, -2);
            }
            if (_capod_entrypoint_17(4200.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x75, -2);
            }
            if (_capod_entrypoint_17(4220.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x76, -2);
            }
            break;

        case 0x197:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x70, -2);
            }
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6E, -2);
            }
            if (_capod_entrypoint_17(625.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x71, -2);
            }
            break;

        case 0x198:
            if (_capod_entrypoint_17(1.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x71, -2);
            }
            if (_capod_entrypoint_17(320.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6E, -2);
            }
            break;

        case 0x195:
            if (_capod_entrypoint_17(2900.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x70, -2);
            }
            if (_capod_entrypoint_17(2900.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6E, -2);
            }
            if (_capod_entrypoint_17(2930.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x6F, -2);
            }
            if (_capod_entrypoint_17(2950.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x75, -2);
            }
            if (_capod_entrypoint_17(2970.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x76, -2);
            }
            break;

        case 0x193:
            if (_capod_entrypoint_17(150.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x73, -2);
            }
            if (_capod_entrypoint_17(150.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0x74, -2);
            }
            break;

        case 0x196:
            if (_capod_entrypoint_17(4800.0f)) {
                _indrv_audio_entrypoint_0(*(s32 *)param_0, 0xAD, -2);
            }
            break;

        case 0x17E:
        case 0x199:
            break;
    }
}

s32 func_808008EC_chintrocam(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
int chintrocam_entrypoint_0()
{
    return (int)&D_80800A20_chintrocam;
}
