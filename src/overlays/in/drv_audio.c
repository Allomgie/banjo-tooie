#include "common.h"

typedef struct { Actor *local_0; void *local_1; } AudioDriverOwner;
extern s16 D_80801478_indrv_audio[];
extern s32 func_800C4350();
extern f32 func_800F1DF4(f32 *, f32 *);
extern s32 func_800F20BC(f32, f32, f32);
extern void func_800C3AE0(u8, f32);
typedef struct { u16 local_0; u16 pad_0; void *local_1; } DriverAudioEntry31;
extern DriverAudioEntry31 D_808014A4_indrv_audio[];
extern DriverAudioEntry31 D_80801A4C_indrv_audio[];
extern Actor *func_80106790();

void func_80800000_indrv_audio(AudioDriverOwner *param_0, s32 param_1, s16 *param_2)
{
    f32 local_0[3];
    u8 local_1;
    f32 local_2[3];
    f32 local_3[3];
    if (param_1 >= 0) func_800DBEFC(param_0->local_1, param_1, local_0);
    else func_800EE88C(local_0, param_0->local_0->position);
    local_1 = func_800C4350(0, local_0, D_80801478_indrv_audio);
    func_800C4350(local_1, local_0, param_2);
    func_8010FFB0(func_8008FFE8(), local_2, local_3);
    if (!func_800F20BC(local_3[1], func_800F1DF4(local_0, local_2), 50.0f)) func_800C3AE0(local_1, 0.25f);
    func_800C3BDC(local_1);
}

void func_808000BC_indrv_audio(s32 param_0, s32 param_1) {
    u8 local_0 = func_800C4350(0, 0, ((u8 *) D_80801478_indrv_audio));
    func_800C4350(local_0, 0, param_1);
    func_800C3BDC(local_0);
}

void indrv_audio_entrypoint_0(Unk80132ED0 *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    for (local_0 = 0; local_0 < 181; local_0++) {
        if (param_1 == D_808014A4_indrv_audio[local_0].local_0) {
            switch (param_2) {
                case -3:
                    if (func_80106790(param_0)->unk7C_12) {
                        func_80800000_indrv_audio(param_0, -2, D_808014A4_indrv_audio[local_0].local_1);
                    }
                    break;
                case -2:
                    func_808000BC_indrv_audio(param_0, D_808014A4_indrv_audio[local_0].local_1);
                    break;
                case -4:
                    if (func_800DA298(0xE)) {
                        func_80800000_indrv_audio(param_0, -1, D_808014A4_indrv_audio[local_0].local_1);
                    }
                    break;
                default:
                    func_80800000_indrv_audio(param_0, param_2, D_808014A4_indrv_audio[local_0].local_1);
                    break;
            }
        }
    }
}
