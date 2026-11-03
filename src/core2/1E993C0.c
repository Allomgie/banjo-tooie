#include "common.h"
s32 func_800BFC34(s32);
s32 func_800BFC94(s32);

f32 func_800DF428(f32);
extern void func_800E24C0(s32);
extern void func_800E249C(s32);
extern s32 func_800D2F20(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E2AA4(s32, s32, s32, s32, s32, f32 *);

// Draws a static model prop.
void func_800BFAD0(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 asset_id)
{
    s32 asset;

    asset = func_800BFC34(asset_id);
    func_800DF428((f32) func_800D2F20());
    func_800DF470(1);
    func_800DF830(1);
    func_800DF3E0();
    func_800DF7E8(func_800D731C(asset_id) & 0xFF);
    func_800DE448(param_1, param_2, param_3, 0, asset);
}

// Draws a static sprite prop.
void func_800BFB58(s32 param_0, s32 param_1, f32 scale_factor, s32 asset_id, s32 tint_r, s32 tint_g,
                   s32 tint_b, s32 param_7, s32 param_8)
{
    f32 scale[3];
    s32 asset;
    s32 blend_mode;

    asset = func_800BFC94(asset_id);
    func_800EFA4C(scale, scale_factor, scale_factor, scale_factor);
    func_800E249C(func_800D2F20());
    func_800E24C0(1);
    func_800E24F8(0xFF - (tint_r * 0x10), 0xFF - (tint_g * 0x10), 0xFF - (tint_b * 0x10));
    if (func_800AF5A8(asset) & 0xB00) {
        blend_mode = 1;
    } else {
        blend_mode = 3;
    }
    func_800E2588(blend_mode);
    func_800E2AA4(param_0, asset, param_8, param_7, param_1, scale);
}

// Acquires the asset.
s32 func_800BFC34(s32 arg0)
{
    return func_800D674C(arg0);
}

// Releases the asset (pair of func_800BFC34).
void func_800BFC54()
{
    func_800D6B0C();
}

void func_800BFC74()
{
    func_800D62E4();
}

s32 func_800BFC94(s32 arg0)
{
    return func_800D674C(arg0);
}

// Empty stub.
void func_800BFCB4(void)
{
}

void func_800BFCBC(void)
{
}

func_800BFCC4(s32 param_0)
{
}
