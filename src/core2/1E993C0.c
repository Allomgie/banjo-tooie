#include "common.h"
s32 func_800BFC34(s32);
s32 func_800BFC94(s32);

f32 func_800DF428(f32);
extern void func_800E24C0(s32);
extern void func_800E249C(s32);
extern s32 func_800D2F20(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E2AA4(s32, s32, s32, s32, s32, f32 *);

void func_800BFAD0(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 sp24;

    sp24 = func_800BFC34(param_4);
    func_800DF428((f32)func_800D2F20());
    func_800DF470(1);
    func_800DF830(1);
    func_800DF3E0();
    func_800DF7E8(func_800D731C(param_4) & 0xFF);
    func_800DE448(param_1, param_2, param_3, 0, sp24);
}

void func_800BFB58(s32 param_0, s32 param_1, f32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8) {
    f32 sp2C[3];
    s32 sp28;
    s32 var_a0;

    sp28 = func_800BFC94(param_3);
    func_800EFA4C(sp2C, param_2, param_2, param_2);
    func_800E249C(func_800D2F20());
    func_800E24C0(1);
    func_800E24F8(0xFF - (param_4 * 0x10), 0xFF - (param_5 * 0x10), 0xFF - (param_6 * 0x10));
    if (func_800AF5A8(sp28) & 0xB00) {
        var_a0 = 1;
    } else {
        var_a0 = 3;
    }
    func_800E2588(var_a0);
    func_800E2AA4(param_0, sp28, param_8, param_7, param_1, sp2C);
}

s32 func_800BFC34(s32 arg0)
{
    return func_800D674C(arg0);
}

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

void func_800BFCB4(void) {
}

void func_800BFCBC(void) {
}

func_800BFCC4(s32 param_0){
}
