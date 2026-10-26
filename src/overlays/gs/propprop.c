#include "common.h"

typedef struct { s16 frameCnt; u8 pad2[0xE]; u32 bit31 : 4; u32 bit27 : 3; u32 bit24 : 2; u32 bit22 : 2; u32 rest : 21; } GsSprite;
typedef struct { u8 pad0[3]; u8 pad3_7 : 6; u8 isMirrored : 1; u8 pad3_0 : 1; u8 pad4[6]; u16 frame : 5; u16 pad_lo : 11; } GsSpriteProp;
typedef struct { u8 pad0[8]; u32 pad8_hi : 26; u32 unk8_5 : 1; u32 pad8_lo : 5; } GsSpriteProp2;
extern GsSprite *func_800EC3E8(s32);
extern s32 _gsproplookup_entrypoint_1();
extern GsSprite *func_800BFC94(s32);
extern s32 func_8001211C();
typedef struct { u32 pad_0 : 22; u32 local_0 : 8; u32 pad_1 : 2; u32 pad_2; u32 pad_3 : 16; u32 local_1 : 8; u32 pad_4 : 6; u32 local_2 : 1; u32 pad_5 : 1; } PropPropertyScale;
extern void func_800BFAD0(s32, f32 *, f32 *, f32, void *);
extern void func_800BFB58(s32, f32 *, f32, void *, s32, s32, s32, s32, s32);

void gspropprop_entrypoint_0(s16 param_0[3], s32 *param_1)
{
  unsigned char new_var;
  param_1[0] = *(s16*)((s8*)param_0 + 4);
  param_1[new_var = 1] = *(s16*)((s8*)param_0 + 6);
  param_1[2] = param_0[4];
}

f32 func_8080001C_gspropprop() {
    return (f32) func_800B0CFC(func_800BFC94(_gsproplookup_entrypoint_1()));
}

f32 func_80800050_gspropprop() {
    func_800B2354(func_800B2840(func_800BFC34(_gsproplookup_entrypoint_0())));
}

f32 gspropprop_entrypoint_1(PropPropertyScale *param_0)
{
    if (param_0->local_2) return func_80800050_gspropprop(param_0) * 0.5f * param_0->local_1 * 0.01f;
    return func_8080001C_gspropprop(param_0) * 0.5f * param_0->local_0 * 0.01f;
}

void gspropprop_entrypoint_2(u8 *prop)
{
    GsSprite *var_v0;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 var_t5;
    s32 var_v1;

    var_v0 = ((u32)(((u16 *)prop)[5]) & 1) ? func_800EC3E8(*(s32 *)prop)
           : func_800BFC94(_gsproplookup_entrypoint_1(prop));
    if ((var_v0 != NULL) && (var_v0->bit27 != 0)) {
        sp48 = var_v0->bit31;
        sp44 = var_v0->bit27;
        sp40 = var_v0->bit24;
        sp3C = var_v0->bit22;
        sp38 = var_v0->frameCnt;
        sp34 = (sp44 == 1) || (sp44 == 2U);
        sp30 = (sp44 == 3) ? sp38 : (sp38 - sp34) * 2;

        sp2C = (s32)((((u32)(((u16 *)prop)[5]) << 0x15) >> 0x1B) * sp30) / 32;
        var_v1 = (((func_8001211C(sp34, sp30, prop, sp40) % (sp30 * sp48)) / sp48) + sp2C) % sp30;
        var_t5 = 0;
        switch (sp40) {
            default:
                sp40 = 0;
                break;
            case 1:
                sp40 = (((((u32)(((u16 *)prop)[5]) << 0x15) >> 0x1B) & 2)) ? 1 : 0;
                break;
            case 2:
                sp40 = 1;
                break;
            case 3:
                sp40 = (((u32)(((u16 *)prop)[1]) << 0x1e) >> 0x1f);
                break;
        }

        switch (sp44) {
            case 4:
                var_t5 = sp38 <= var_v1;
            case 1:
                sp3C = sp38 <= var_v1;
                break;
            case 2:
                var_t5 = sp38 <= var_v1;
            default:
                switch (sp3C) {
                    case 1:
                        sp3C = ((((u32)(((u16 *)prop)[5]) << 0x15) >> 0x1b) & 1) ? 1 : 0;
                        break;
                    case 2:
                        sp3C = 1;
                        break;
                    default:
                        if (((u32)(((u16 *)prop)[5])) & 1) {
                            sp3C = (((u32)(((u32 *)prop)[2]) << 0x1a) >> 0x1f);
                        } else {
                            sp3C = (((u32)(((u16 *)prop)[1]) << 0x1e) >> 0x1f);
                        }
                        if (1);
                        break;
                }
                break;
        }

        if ((sp3C ^ sp40 ^ var_t5)) {
            var_v1 = sp30 - var_v1;
        }

        var_v1 += (sp34) ? sp40 : -sp40;
        var_v1 = (var_v1 < 0) ? var_v1 + sp38 : var_v1 % sp38;
        ((GsSpriteProp *)prop)->frame = var_v1;
        if (((u32)(((u16 *)prop)[5]) & 1)) {
            ((GsSpriteProp2 *)prop)->unk8_5 = sp3C;
        } else {
            ((GsSpriteProp *)prop)->isMirrored = sp3C;
        }
    }
}

void gspropprop_entrypoint_3(u8 *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    void *local_2;
    func_800EE88C(local_0, param_0 + 4);
    if ((*(u32 *)(param_0 + 8) << 30) >> 31) {
        local_2 = (void *)_gsproplookup_entrypoint_0(param_0);
        local_1[0] = 0.0f;
        local_1[1] = 2.0f * (f32)(u32)param_0[2];
        local_1[2] = 2.0f * (f32)(u32)param_0[3];
        func_800BFAD0(param_1, local_0, local_1, (f32)(u32)param_0[10] * 0.01f, local_2);
    } else {
        func_800BFB58(param_1, local_0, (f32)((*(u32 *)param_0 << 22) >> 24) * 0.01f,
            (void *)_gsproplookup_entrypoint_1(param_0),
            *(u16 *)param_0 & 7, (u32)*(u16 *)(param_0 + 2) >> 13,
            (*(u32 *)param_0 << 19) >> 29, (*(u32 *)param_0 << 30) >> 31,
            (u32)*(u16 *)(param_0 + 10) >> 11);
    }
}
