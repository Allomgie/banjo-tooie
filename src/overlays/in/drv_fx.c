#include "common.h"

extern Actor *func_80106790(Unk80132ED0 *);
extern void func_800DBEFC(void *, s32, f32 *);
extern void func_800EE88C(f32 *, void *);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern s32 D_808005B0_indrv_fx;
extern s32 D_80800608_indrv_fx;
extern s32 D_80800648_indrv_fx;
extern s32 D_80800684_indrv_fx;
extern s32 D_808006E4_indrv_fx;
extern s32 D_80800720_indrv_fx;
extern s32 D_80800780_indrv_fx;
extern s32 D_808007E0_indrv_fx;
extern s32 D_80800818_indrv_fx;
extern s32 D_80800870_indrv_fx;
extern s32 D_808008C0_indrv_fx;
extern s32 D_80800920_indrv_fx;
extern s32 D_80800964_indrv_fx;
extern s32 D_808009A8_indrv_fx;
extern s32 D_808009F4_indrv_fx;
extern s32 D_80800A4C_indrv_fx;
extern s32 D_80800AA4_indrv_fx;
extern s32 D_80800AFC_indrv_fx;
extern s32 D_80800B2C_indrv_fx;
extern s32 D_80800B5C_indrv_fx;
extern s32 D_80800BA0_indrv_fx;
extern s32 D_80800BE8_indrv_fx;
extern s32 D_80800C3C_indrv_fx;
extern s32 D_80800CA4_indrv_fx;
extern s32 D_80800CF0_indrv_fx;
extern s32 D_80800D30_indrv_fx;
extern s32 D_80800D6C_indrv_fx;
extern s32 D_80800DBC_indrv_fx;
extern s32 D_80800E0C_indrv_fx;
extern s32 D_80800E5C_indrv_fx;
extern s32 D_80800EAC_indrv_fx;

void func_80800000_indrv_fx(Unk80132ED0 *param_0, s32 param_1, f32 param_2, s32 param_3, s32 *param_4)
{
    f32 local_0[3];
    Actor *local_1;

    local_1 = func_80106790(param_0);
    if (local_1->unk7C_12 || param_1 == -1) {
        if (param_1 == -1) {} // empty test (no code): counts as an extra use of -1 for uopt coloring
        if (param_1 != -1) {
            func_800DBEFC(param_0->unk4, param_1, local_0);
        } else {
            func_800EE88C(local_0, (u8 *)param_0->unk0 + 4);
        }
        func_800BBCB8(local_0, (s32)local_0, param_2, param_3, param_4);
    }
}

int indrv_fx_entrypoint_0(s32 param_0, u32 param_1, s32 param_2)
{
    switch (param_1)
    {
        case 0:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 2, &D_808005B0_indrv_fx);
            break;
        case 1:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 5, &D_80800608_indrv_fx);
            break;
        case 2:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 5, &D_80800648_indrv_fx);
            break;
        case 3:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800684_indrv_fx);
            break;
        case 4:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 4, &D_808006E4_indrv_fx);
            break;
        case 5:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800720_indrv_fx);
            break;
        case 10:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800780_indrv_fx);
            break;
        case 6:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 3, &D_808007E0_indrv_fx);
            break;
        case 7:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 6, &D_80800818_indrv_fx);
            break;
        case 8:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800870_indrv_fx);
            break;
        case 9:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_808008C0_indrv_fx);
            break;
        case 11:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800920_indrv_fx);
            break;
        case 12:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800964_indrv_fx);
            break;
        case 13:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_808009A8_indrv_fx);
            break;
        case 14:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 2, &D_808009F4_indrv_fx);
            break;
        case 15:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 2, &D_80800A4C_indrv_fx);
            break;
        case 16:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 3, &D_80800AA4_indrv_fx);
            break;
        case 17:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800AFC_indrv_fx);
            break;
        case 18:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800B2C_indrv_fx);
            break;
        case 19:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800B5C_indrv_fx);
            break;
        case 20:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 30, &D_80800BA0_indrv_fx);
            break;
        case 21:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 6, &D_80800BE8_indrv_fx);
            break;
        case 22:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800C3C_indrv_fx);
            break;
        case 23:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800CA4_indrv_fx);
            break;
        case 24:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800CF0_indrv_fx);
            break;
        case 25:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800D30_indrv_fx);
            break;
        case 26:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800D6C_indrv_fx);
            break;
        case 27:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800DBC_indrv_fx);
            break;
        case 28:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800E0C_indrv_fx);
            break;
        case 29:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800E5C_indrv_fx);
            break;
        case 30:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800EAC_indrv_fx);
            break;
    }
}
