#include "common.h"

extern void *D_80800470_chjujubagfx;
extern void *func_80100094(Actor *, u32);
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_3(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _sumumbofx_entrypoint_23(void *, f32);
extern void _chbaddiesetup_entrypoint_0(void *);
extern void *_chjujubagfx_entrypoint_1;
extern f32 _sumumbofx_entrypoint_21(void *);
extern f32 _sumumbofx_entrypoint_22(void *);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, f32 *, f32 *);
extern Vec3f D_808004B8_chjujubagfx;
extern Vec3f D_808004C4_chjujubagfx;

int chjujubagfx_entrypoint_0()
{
  return &D_80800470_chjujubagfx;
}

void func_8080000C_chjujubagfx(Actor *param_0, s32 param_1)
{
    void *local_0;

    func_80101FDC(param_0, param_1);
    switch (param_1) {
        case 2:
            _sumumbofx_entrypoint_0(param_0, 1, 10, 0x9E4);
            local_0 = func_80100094(param_0, 1);
            _sumumbofx_entrypoint_2(local_0);
            _sumumbofx_entrypoint_24(local_0, 0.15f);
            _sumumbofx_entrypoint_4(local_0);
            _sumumbofx_entrypoint_3(local_0, 360.0f);
            _sumumbofx_entrypoint_15(local_0, 0.5f);
            _sumumbofx_entrypoint_23(local_0, 0.0f);
            _sumumbofx_entrypoint_19(local_0, 0);
            break;
        case 4:
            func_800DA524(0x9F3);
            _sumumbofx_entrypoint_16(func_80100094(param_0, 1), 0.5f);
            param_0->unk64_20 = 1;
            break;
    }
}

int func_80800100_chjujubagfx(Actor *param_0)
{
    s32 local_0;
    s32 *local_1;
    local_0 = func_8010D278();
    if (local_0 != 0xD)
    {
        local_1 = _subaddiefind_entrypoint_0(&param_0->position, 0x190, -1, 0);
        *(s32 *)((char *)(param_0) + 0x3C) = (*(s32 *)((char *)(local_1) + 0x0));
    }
    else
    {
        func_8008FE94(1, &param_0->position);
    }
    *(u8 *)((char *)(param_0) + 0x65) &= 0xFFEF;
    func_8080000C_chjujubagfx(param_0, 2);
}

s32 func_80800174_chjujubagfx(Actor *this){
    if(func_80100094(this, 1) != 0){
        _sumumbofx_entrypoint_1(this, 1);
    }
}

void func_808001A8_chjujubagfx(Actor *param_0)
{
    Vec3f local_0;
    Vec3f local_1;
    void *local_2;
    f32 *local_3;

    local_0 = D_808004B8_chjujubagfx;
    local_1 = D_808004C4_chjujubagfx;
    local_2 = func_80100094(param_0, 1);
    if (func_800DA298(0x9F3)) {
        func_8080000C_chjujubagfx(param_0, 4);
    }
    if (!param_0->unk64_20) {
        if (func_8010D278() != 0xD) {
            if (param_0->unk3C != NULL) {
                _chnewmumbo_entrypoint_0(func_80106790(param_0->unk3C), param_0->position);
            }
        } else {
            func_8008FE94(1, param_0->position);
        }
    }
    switch (param_0->unk70_10) {
    case 2:
        local_3 = param_0->position;
        _sumumbofx_entrypoint_14(local_2);
        _sumumbofx_entrypoint_7(local_2, 28.0f, 0, 10, local_3, local_1.f, local_0.f);
        if (_sumumbofx_entrypoint_21(local_2) == 0.0f) {
            _sumumbofx_entrypoint_17(local_2, 10.0f);
            func_8080000C_chjujubagfx(param_0, 3);
        }
        return;
    case 3:
        local_3 = param_0->position;
        _sumumbofx_entrypoint_14(local_2);
        _sumumbofx_entrypoint_7(local_2, 28.0f, 0, 10, local_3, local_1.f, local_0.f);
        return;
    case 4:
        local_3 = param_0->position;
        _sumumbofx_entrypoint_14(local_2);
        _sumumbofx_entrypoint_7(local_2, 28.0f, 0, 10, local_3, local_1.f, local_0.f);
        if (_sumumbofx_entrypoint_22(local_2) < 0.05f) {
            func_800FFAB0(param_0);
        }
        break;
    }
}

s32 func_808003D4_chjujubagfx(s32 param_0, s32 param_1){
    _sumumbofx_entrypoint_8(func_80100094(param_0, 1), param_1);
}

s32 chjujubagfx_entrypoint_1(void){
    f32 local_0[3];

    func_8010D254(local_0);
    func_80108474(0x2F9, local_0, 0);
}

void chjujubagfx_entrypoint_2(void)
{
  _chbaddiesetup_entrypoint_0(&_chjujubagfx_entrypoint_1);
}
