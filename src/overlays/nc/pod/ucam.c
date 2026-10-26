#include "common.h"
extern void _susplinet_entrypoint_11(void *, f32);

extern s32 D_8012B260;
extern u8 f7[];
extern s32 func_8001B754(s16);
extern void func_800EF334(f32 *, f32);
typedef struct { s16 local_0; s16 pad_0; f32 local_1[3]; f32 local_2[3]; u8 pad_1[0x20]; f32 local_3[3]; u8 pad_2[8]; f32 local_4; f32 local_5; } CameraSplineView;
extern f32 _suspline_entrypoint_4(void *, s32);
extern void _suspline_entrypoint_9(s32, f32);
extern void *func_8001B798();
typedef struct { s16 local_0; s16 local_1; u8 pad_0[0x5C]; u8 local_2; u8 pad_1[4]; u8 local_3; } PodUCamSplineState;
extern f32 _glintrosyncDll_entrypoint_5(void);
extern f32 func_800D8FF8(void);
extern f32 _susplinet_entrypoint_9(void *);
extern void _susplinet_entrypoint_16(void *, f32, f32);
extern f32 _susplinet_entrypoint_8(s32, s32);
extern void _ncpod_entrypoint_9(s32, f32);
extern void _ncpod_entrypoint_11(s32, f32);
typedef struct { u8 local_0[2]; s16 local_1; u8 local_2[0x54]; s16 local_3; u8 local_4[6]; u8 local_5; } UCamSpline49;
extern f32 *_susplinet_entrypoint_14(void *, s32);
extern s32 *_susplinet_entrypoint_15(void *, s32);
extern s16 *_susplinet_entrypoint_12(void *);
extern s16 *_susplinet_entrypoint_13(void *);
extern void _susplinet_entrypoint_0(void *, s32, s32, f32);
extern void *_suspline_entrypoint_10(void *, s32);
extern void *_suspline_entrypoint_11(void *, s32);
extern void func_800F0EF0(s32, f32 *);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
typedef struct { u8 pad_0[0x58]; s16 local_0; u8 pad_1[2]; s32 local_1; u8 local_2; } PodUserCameraState;
typedef struct { u8 pad_0[2]; s16 local_0; u8 pad_1[0x5C]; u8 local_1; } PodCameraState;
extern s32 _susplinet_entrypoint_4(void *, s32);
extern s32 _suspline_entrypoint_2(void *, f32);
extern s32 _susplinet_entrypoint_5(void *, f32);
extern f32 _suspline_entrypoint_6(void *);
extern void _suspline_entrypoint_3(void *, s32, f32 *);
extern void _suspline_entrypoint_5(void *, f32 *);
extern Actor *_subaddiefind_entrypoint_12(s32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
s32 ncpoducam_entrypoint_1();
void func_8080145C_ncpoducam();
void func_808003A8_ncpoducam();

void func_80800000_ncpoducam(u8 *param_0) {
    func_800EFD24(param_0 + 4);
    func_800EFD24(param_0 + 0x10);
    func_800EFD24(param_0 + 0x24);
    func_800EFD24(param_0 + 0x30);
    (*(s8 *)((s8 *)(param_0) + (0x63))) = 0;
    (*(f32 *)((s8 *)(param_0) + (0x50))) = 40.0f;
    (*(f32 *)((s8 *)(param_0) + (0x54))) = 1.0f;
}

s16 ncpoducam_entrypoint_0(void) {
    s16 temp_v0;
    s16 sp26;
    u8 *temp_v0_2;

    temp_v0 = func_8001B668(0, 0x68);
    sp26 = temp_v0;
    temp_v0_2 = ncpoducam_entrypoint_1(temp_v0);
    (*(s32 *)((s8 *)(temp_v0_2) + (0x5C))) = 0;
    (*(s32 *)((s8 *)(temp_v0_2) + (0x1C))) = 0;
    (*(s16 *)((s8 *)(temp_v0_2) + (0))) = 0;
    (*(s16 *)((s8 *)(temp_v0_2) + (2))) = 0;
    func_800EFD24(temp_v0_2 + 0x3C);
    func_800EFD24(temp_v0_2 + 4);
    func_800EFD24(temp_v0_2 + 0x10);
    (*(s16 *)((s8 *)(temp_v0_2) + (0x48))) = 0;
    (*(s32 *)((s8 *)(temp_v0_2) + (0x4C))) = 0;
    (*(s16 *)((s8 *)(temp_v0_2) + (0x58))) = -1;
    (*(u8 *)((s8 *)(temp_v0_2) + (0x60))) = 0xFF;
    (*(s8 *)((s8 *)(temp_v0_2) + (0x62))) = 0;
    (*(s8 *)((s8 *)(temp_v0_2) + (0x65))) = func_800E6A00();
    return temp_v0;
}

s32 ncpoducam_entrypoint_1(param_0) s16 param_0;{
    s32 local_0 = param_0;
    func_8001B798(local_0);
}

s32 ncpoducam_entrypoint_2(void *param_0, s32 param_1, s32 param_2)
{
  *(s16 *)((char *)param_0 + 0x58) = param_2;
  func_8080145C_ncpoducam(param_0, param_1, 1);
}

void ncpoducam_entrypoint_3(s32 *param_0, s32 *param_1)
{
    param_0[7] = param_1;
    param_0[8] = (u32)((unsigned short)(*(u16 *)((char *)(param_1) + 18))) >> 1;
}

void ncpoducam_entrypoint_4(void *param_0, int param_1)
{
  void *new_var;
  new_var = param_0;
  *((s16 *) (0x48 + ((char *) new_var))) = param_1;
}

int ncpoducam_entrypoint_5(union U1 *param_0)
{
  return *(s16*)((char*)param_0 + 0x48);
}

void func_80800160_ncpoducam(s16 *param_0) {
    if (param_0[0] != 0) {
        func_8001B754(param_0[0]);
        param_0[0] = 0;
    }
    if (param_0[1] != 0) {
        func_8001B754(param_0[1]);
        param_0[1] = 0;
    }
}

s32 ncpoducam_entrypoint_6(param_0) s16 param_0; {
    s32 local_0;

    local_0 = ncpoducam_entrypoint_1(param_0);
    func_80800160_ncpoducam(local_0 | 0);
    return func_8001B754(param_0);
}

int func_808001F0_ncpoducam(u16 *param_0, u32 param_1)
{
    s32 ret;
    if (param_1 == -1) {
        ret = 0;
    } else {
        ret = (param_1 == ((u32)*(u16 *)(param_0 + 9) >> 1));
    }
    return ret;
}

int func_8080021C_ncpoducam(u8 *param_0)
{
    f32 local_0[3];
    s16 local_4;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    local_4 = *(s16 *)(param_0 + 0x48);
    if (local_4 & 1) {
        if (func_808001F0_ncpoducam(*(s32 *)(param_0 + 0x1C), *(s32 *)(param_0 + 0x20))) {
            func_80103DFC(func_80106790(*(s32 *)(param_0 + 0x1C)), local_0);
            if ((*(s16 *)(param_0 + 0x48) & 0x400) && param_0[0x63]) {
                func_800EFB24(local_1, local_0, (f32 *)(param_0 + 0x3C));
                func_800EF334(local_1, 0.3f);
                func_800EF04C((f32 *)(param_0 + 0x3C), local_1);
                return 1;
            }
            func_800EE7F8(param_0 + 0x3C, local_0);
            param_0[0x63] = 1;
        }
        return 1;
    }
    if (local_4 & 0x40) {
        func_800F5BC4(func_800F54E4(), local_2);
        func_800F5A00(func_800F54E4(), local_0);
        func_800EF04C(local_0, local_2);
        if ((*(s16 *)(param_0 + 0x48) & 0x400) && param_0[0x63]) {
            func_800EFB24(local_3, local_0, (f32 *)(param_0 + 0x3C));
            func_800EF334(local_3, 0.3f);
            func_800EF04C((f32 *)(param_0 + 0x3C), local_3);
            return 1;
        }
        param_0[0x63] = 1;
        func_800EE7F8(param_0 + 0x3C, local_0);
        return 1;
    }
    if (local_4 & 0x80) { return 1; }
    return 0;
}

void func_808003A8_ncpoducam(param_0, param_1) u8 *param_0; s32 param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    Actor *local_6;
    void *local_7;
    s32 local_8;

    local_7 = func_8001B798(*(s16 *)param_0);
    _suspline_entrypoint_3(local_7, 0, local_3);
    _suspline_entrypoint_3(local_7, 2, local_4);
    _suspline_entrypoint_3(local_7, 1, local_5);
    if (*(s16 *)(param_0 + 0x48) & 8) {
        if (func_808001F0_ncpoducam(*(s32 *)(param_0 + 0x1C), *(s32 *)(param_0 + 0x20))) {
            local_6 = (Actor *)func_80106790(*(s32 *)(param_0 + 0x1C));
        } else {
            local_6 = NULL;
        }
    } else {
        func_800A5800(*(s16 *)(param_0 + 0x58));
        _cadbfunc_entrypoint_24(&local_8);
        local_6 = _subaddiefind_entrypoint_12(local_8);
    }
    if (local_6) {
        if (!(*(s16 *)(param_0 + 0x48) & 0x400) || !param_0[0x63]) {
            func_800EE7F8((f32 *)(param_0 + 0x30), local_6->rotation);
            func_800EE7F8((f32 *)(param_0 + 0x24), local_6->position);
            param_0[0x63] = 1;
        } else {
            *(f32 *)(param_0 + 0x30) += func_800F1DCC(local_6->rotation[0], *(f32 *)(param_0 + 0x30)) * 0.1f;
            *(f32 *)(param_0 + 0x34) += func_800F1DCC(local_6->rotation[1], *(f32 *)(param_0 + 0x34)) * 0.1f;
            *(f32 *)(param_0 + 0x38) += func_800F1DCC(local_6->rotation[2], *(f32 *)(param_0 + 0x38)) * 0.1f;
            *(f32 *)(param_0 + 0x24) += (local_6->position[0] - *(f32 *)(param_0 + 0x24)) * 0.1f;
            *(f32 *)(param_0 + 0x28) += (local_6->position[1] - *(f32 *)(param_0 + 0x28)) * 0.1f;
            *(f32 *)(param_0 + 0x2C) += (local_6->position[2] - *(f32 *)(param_0 + 0x2C)) * 0.1f;
        }
    }
    func_800EE7F8((f32 *)(param_0 + 4), local_4);
    func_800EF6A8((f32 *)(param_0 + 4), (f32 *)(param_0 + 0x30), *(f32 *)(param_0 + 4), *(f32 *)(param_0 + 8), *(f32 *)(param_0 + 0xC));
    func_800EF04C((f32 *)(param_0 + 4), (f32 *)(param_0 + 0x24));
    if (!(*(s16 *)(param_0 + 0x48) & 1)) {
        func_800EE7F8(local_0, local_3);
        func_800EF6A8(local_0, (f32 *)(param_0 + 0x30), local_0[0], local_0[1], local_0[2]);
        func_800EF04C(local_0, (f32 *)(param_0 + 0x24));
        func_800EE7F8(local_1, local_3);
        func_800EF5A0(local_2, local_5, 100.0f, 0.0f, 0.0f);
        func_800EF04C(local_1, local_2);
        func_800EF6A8(local_1, (f32 *)(param_0 + 0x30), local_1[0], local_1[1], local_1[2]);
        func_800EF04C(local_1, (f32 *)(param_0 + 0x24));
        *(f32 *)(param_0 + 0x18) = func_800136E4(-func_800F1828(local_0, local_1));
        *(f32 *)(param_0 + 0x10) = -func_800136E4(func_800F1828(local_0, (f32 *)(param_0 + 4)));
        *(f32 *)(param_0 + 0x14) = func_800136E4(func_800F1DF4(local_0, (f32 *)(param_0 + 4)));
    }
    if (func_8080021C_ncpoducam(param_0)) {
        func_800F18FC((f32 *)(param_0 + 0x3C), (f32 *)(param_0 + 4), (f32 *)(param_0 + 0x10));
        *(f32 *)(param_0 + 0x10) = -*(f32 *)(param_0 + 0x10);
        *(f32 *)(param_0 + 0x18) = 0.0f;
    }
    *(f32 *)(param_0 + 0x50) = _suspline_entrypoint_4(local_7, 0);
    if (!param_1) {
        _suspline_entrypoint_5(local_7, local_4);
    }
}

void func_80800704_ncpoducam(CameraSplineView *param_0, s32 param_1)
{

    void *local_0;

    local_0 = func_8001B798(param_0->local_0);
    _suspline_entrypoint_3(local_0, 0, param_0->local_1);
    if (!func_8080021C_ncpoducam(param_0)) {
        _suspline_entrypoint_3(local_0, 1, param_0->local_2);
    } else {
        func_800F18FC(param_0->local_3, param_0->local_1, param_0->local_2);
        param_0->local_2[0] = -param_0->local_2[0];
        param_0->local_2[2] = 0.0f;
    }
    param_0->local_4 = _suspline_entrypoint_4(local_0, 0);
    param_0->local_5 = _suspline_entrypoint_4(local_0, 1);
    if (!param_1) _suspline_entrypoint_5(local_0, param_0->local_1);
}

int func_808007D0_ncpoducam(u8 *param_0)
{
  s32 local_1;
  switch (param_0[0x60])
  {
    case 5:
    case 6:
      local_1 = func_8001B798(*(short *)(param_0 + 0), param_0);
      _suspline_entrypoint_13(local_1);
      _suspline_entrypoint_9(local_1, _suspline_entrypoint_6(local_1));
      _suspline_entrypoint_14(local_1);
      _suspline_entrypoint_17(local_1);
    case 8:
      return;
  }
}

s32 func_80800854_ncpoducam(u8 *param_0, s32 param_1)
{
    s32 local_0 = 0;
    s32 local_1;

    local_1 = _ncpod_entrypoint_5(param_1, func_80110024(param_1), 14, *(s16 *)(param_0 + 0x58), 0);
    if (local_1 == 4) {
        return local_1;
    }
    *(s32 *)(param_0 + 0x4C) = local_1;
    switch (param_0[0x60]) {
        case 5:
        case 6:
            local_0 = _suspline_entrypoint_7(func_8001B798(*(s16 *)param_0));
            break;
        case 8:
            break;
    }
    if (local_0) {
        local_1 = _ncpod_entrypoint_5(param_1, func_80110024(param_1), 12, *(s16 *)(param_0 + 0x58), 0);
        if (local_1 == 4) {
            return local_1;
        }
        *(s32 *)(param_0 + 0x4C) = local_1;
    }
    return local_1;
}

void func_80800944_ncpoducam(PodUCamSplineState *param_0)
{
    f32 local_0;
    void *local_1;
    f32 local_2;

    if (param_0->local_3) local_0 = _glintrosyncDll_entrypoint_5();
    else local_0 = func_800D8FF8();
    switch (param_0->local_2) {
        case 8:
            local_1 = func_8001B798(param_0->local_1);
            local_2 = _susplinet_entrypoint_9(local_1);
            _susplinet_entrypoint_11(local_1, local_2);
            _susplinet_entrypoint_16(local_1, local_2, 100.0f * local_0 + local_2);
            break;
        case 5:
        case 6:
            _suspline_entrypoint_16(func_8001B798(param_0->local_0));
            break;
    }
}

void func_80800A18_ncpoducam(u8 *param_0)
{
    s32 local_0;
    local_0 = func_8001B798(*(s16 *)(param_0 + 2));
    _susplinet_entrypoint_17(local_0);
    _susplinet_entrypoint_7(local_0, 0, param_0 + 4);
    _susplinet_entrypoint_7(local_0, 1, param_0 + 0x10);
    *(f32 *)(param_0 + 0x50) = _susplinet_entrypoint_8(local_0, 0);
    *(f32 *)(param_0 + 0x54) = _susplinet_entrypoint_8(local_0, 1);
}

void func_80800A94_ncpoducam(u8 *param_0, s32 param_1)
{
    s32 local_0;

    switch (param_0[0x60]) {
    case 8: func_80800A18_ncpoducam(param_0); break;
    case 5: func_80800704_ncpoducam(param_0, 0); break;
    case 6: func_808003A8_ncpoducam(param_0, 0); break;
    }
    local_0 = func_80110024(param_1);
    _ncpod_entrypoint_8(local_0, param_0 + 4, param_0 + 16);
    _ncpod_entrypoint_9(local_0, *(f32 *)(param_0 + 0x50));
    if (*(f32 *)(param_0 + 0x50) == 40.0f && (param_0[0x60] == 5 || param_0[0x60] == 8)) {
        _ncpod_entrypoint_11(local_0, *(f32 *)(param_0 + 0x54));
    }
}

s32 func_80800B74_ncpoducam(u8 *param_0, s32 param_1)
{
    s32 local_1 = 0;
    s32 local_0 = 3;

    switch (param_0[0x60]) {
    case 8:
        local_1 = _susplinet_entrypoint_2(func_8001B798(*(s16 *)(param_0 + 2)));
        break;
    case 5:
    case 6:
        local_1 = _suspline_entrypoint_1(func_8001B798(*(s16 *)param_0));
        break;
    }
    if (local_1) {
        if (*(s16 *)(param_0 + 0x48) & 0x20) {
            func_8080145C_ncpoducam(param_0, param_1, 2);
            local_0 = _ncpod_entrypoint_5(param_1, func_80110024(param_1), 11, *(s16 *)(param_0 + 0x58), 0);
            if (local_0 == 4) return local_0;
            *(s32 *)(param_0 + 0x4C) = local_0;
        } else {
            local_0 = _ncpod_entrypoint_5(param_1, func_80110024(param_1), 11, *(s16 *)(param_0 + 0x58), 0);
            if (local_0 == 4) return local_0;
            *(s32 *)(param_0 + 0x4C) = local_0;
            func_8080145C_ncpoducam(param_0, param_1, 3);
        }
    }
    return local_0;
}

int func_80800CB8_ncpoducam(param_0, param_1) s16 param_0; s32 param_1;
{
  s32 local_0;
  u32 local_1 = 0;
  while (param_0 != -1)
  {
    func_800A5800(param_0);
    _cadbfunc_entrypoint_16(&param_0);
    local_1++;
  }

  return local_1;
}

void func_80800D28_ncpoducam(UCamSpline49 *param_0)
{
    f32 *local_0[2];
    s32 *local_1[2];
    s16 *local_9;
    void *local_5;
    s32 local_6;
    s16 local_2;
    s16 local_8;
    s32 local_3[2];
    s32 local_7;
    s16 *local_10;
    f32 local_4;
    local_6 = func_80800CB8_ncpoducam(param_0->local_3, param_0->local_5);
    local_5 = (void *)_susplinet_entrypoint_18(local_6, 2, 2);
    param_0->local_1 = func_8001B668(0, local_5);
    local_5 = func_8001B798(param_0->local_1);
    _susplinet_entrypoint_19(local_5, local_6, 2, 2);
    _susplinet_entrypoint_1(local_5, 1, 1);
    for (local_6 = 0; local_6 < 2; local_6++) {
        local_0[local_6] = _susplinet_entrypoint_14(local_5, local_6);
    }
    for (local_6 = 0; local_6 != 2; local_6++) {
        local_1[local_6] = _susplinet_entrypoint_15(local_5, local_6);
    }
    local_9 = _susplinet_entrypoint_12(local_5);
    local_10 = _susplinet_entrypoint_13(local_5);
    local_2 = param_0->local_3;
    local_8 = 0;
    while (local_2 != -1) {
        func_800A5800(local_2);
        _cadbfunc_entrypoint_0(local_0[0]);
        _cadbfunc_entrypoint_2(local_0[1]);
        *local_10 = -1;
        _cadbfunc_entrypoint_12(local_1[0]);
        _cadbfunc_entrypoint_24(local_3);
        *local_9 = local_3[0];
        _cadbfunc_entrypoint_14(local_1[1]);
        _cadbfunc_entrypoint_29(0x100, &local_4);
        _susplinet_entrypoint_0(local_5, local_8, 2, local_4);
        _cadbfunc_entrypoint_29(0x200, &local_4);
        _susplinet_entrypoint_0(local_5, local_8, 4, local_4);
        _cadbfunc_entrypoint_29(0x400, &local_4);
        _susplinet_entrypoint_0(local_5, local_8, 1, local_4);
        local_9++;
        local_10++;
        local_0[0] += 3;
        local_0[1] += 3;
        local_1[0]++;
        local_1[1]++;
        local_8++;
        _cadbfunc_entrypoint_16(&local_2);
    }
}

void func_80800F64_ncpoducam(u8 *param_0)
{
    f32 *local_0[3];
    f32 *local_1[4];
    s32 local_2;
    s16 local_3;
    s16 local_4;
    f32 local_5;
    s32 local_6[2];
    void *local_7;

    local_2 = func_80800CB8_ncpoducam(*(s16 *)(param_0 + 0x58), param_0[0x60]);
    *(s16 *)param_0 = func_8001B668(0, _suspline_entrypoint_18(local_2, 3, 4));
    local_7 = func_8001B798(*(s16 *)param_0);
    _suspline_entrypoint_19(local_7, local_2, 3, 4, 2, 2);
    for (local_4 = 0; local_4 < 3; local_4++) {
        local_0[local_4] = _suspline_entrypoint_10(local_7, local_4);
    }
    for (local_4 = 0; local_4 < 4; local_4++) {
        local_1[local_4] = _suspline_entrypoint_11(local_7, local_4);
    }
    local_4 = 0;
    local_3 = *(s16 *)(param_0 + 0x58);
    while (local_3 != -1) {
        func_800A5800(local_3);
        _cadbfunc_entrypoint_0(local_0[0]);
        _cadbfunc_entrypoint_2(local_0[1]);
        _cadbfunc_entrypoint_10(local_1[2]);
        _cadbfunc_entrypoint_12(local_1[0]);
        *local_1[1] = 1.0f;
        _cadbfunc_entrypoint_18(local_1[3]);
        _cadbfunc_entrypoint_29(8, local_6);
        _suspline_entrypoint_0(local_7, local_4, local_6[0]);
        local_0[0] += 3;
        local_0[1] += 3;
        local_1[2]++;
        local_1[0]++;
        local_1[1]++;
        local_1[3]++;
        local_4++;
        _cadbfunc_entrypoint_16(&local_3);
    }
    for (local_4 = 0; local_4 < 3; local_4++) {
        local_0[local_4] = _suspline_entrypoint_10(local_7, local_4);
    }
    for (local_4 = 0; local_4 < 4; local_4++) {
        local_1[local_4] = _suspline_entrypoint_11(local_7, local_4);
    }
    func_800F0EF0(local_2, local_0[1]);
    for (local_4 = 0; local_4 < local_2; local_4++) {
        local_5 = *local_1[3];
        *local_1[3] = local_0[1][2];
        func_800EE7F8(local_0[2], local_0[1]);
        func_800EF4E4(local_0[2], local_0[2][0], local_0[2][1], 0.0f, 0.0f, -local_5);
        func_800EF04C(local_0[2], local_0[0]);
        local_0[0] += 3;
        local_0[1] += 3;
        local_0[2] += 3;
        local_1[3]++;
    }
}

void func_80801274_ncpoducam(u8 *param_0)
{
    u8 *local_0[2];
    u8 *local_1[3];
    void *local_2;
    s16 local_3;
    void *local_6;
    s16 local_5;
    s32 local_4;

    local_2 = func_80800CB8_ncpoducam(*(s16 *)(param_0 + 0x58), param_0[0x60]);
    *(s16 *)param_0 = func_8001B668(0, _suspline_entrypoint_18(local_2, 2, 3));
    local_6 = func_8001B798(*(s16 *)param_0);
    _suspline_entrypoint_19(local_6, local_2, 2, 3, 0, 2);
    for (local_5 = 0; local_5 < 2; local_5++) {
        local_0[local_5] = _suspline_entrypoint_10(local_6, local_5);
    }
    for (local_5 = 0; local_5 < 3; local_5++) {
        local_1[local_5] = _suspline_entrypoint_11(local_6, local_5);
    }
    local_5 = 0;
    local_3 = *(s16 *)(param_0 + 0x58);
    while (local_3 != -1) {
        func_800A5800(local_3);
        _cadbfunc_entrypoint_0(local_0[0]);
        _cadbfunc_entrypoint_2(local_0[1]);
        _cadbfunc_entrypoint_10(local_1[2]);
        _cadbfunc_entrypoint_12(local_1[0]);
        _cadbfunc_entrypoint_14(local_1[1]);
        _cadbfunc_entrypoint_29(8, &local_4);
        _suspline_entrypoint_0(local_6, local_5, local_4);
        local_0[0] += 12;
        local_0[1] += 12;
        local_1[2] += 4;
        local_1[0] += 4;
        local_1[1] += 4;
        local_5++;
        _cadbfunc_entrypoint_16(&local_3);
    }
    func_800F0EF0(local_2, _suspline_entrypoint_10(local_6, 1));
}

void func_8080145C_ncpoducam(param_0, param_1, param_2) void *param_0; s32 param_1; s32 param_2;
{
    ((PodUserCameraState *)param_0)->local_1 = param_2;
    switch (param_2) {
    case 1:
        func_80800160_ncpoducam(param_0);
        func_80800000_ncpoducam(param_0);
        switch (((PodUserCameraState *)param_0)->local_2 = func_800A5854(((PodUserCameraState *)param_0)->local_0)) {
        case 8:
            func_80800D28_ncpoducam(param_0);
            return;
        case 5:
            func_80801274_ncpoducam(param_0);
            return;
        case 6:
            func_80800F64_ncpoducam(param_0);
            return;
        }
        break;
    case 3:
        _ncpod_entrypoint_12(func_80110024(param_1), 0);
        break;
    }
}

s32 ncpoducam_entrypoint_7(s16 param_0, void *param_1)
{
    u8 *local_1;
    s32 local_0;

    local_1 = (u8 *)ncpoducam_entrypoint_1(param_0);
    local_0 = 3;
    switch (*(s32 *)(local_1 + 0x5C)) {
        case 0:
            break;
        case 1:
            func_808007D0_ncpoducam(local_1);
            local_0 = func_80800854_ncpoducam(local_1, param_1);
            if (local_0 == 4) {
                return local_0;
            }
            if (*(s16 *)(local_1 + 0x48) & 2) {
                if (local_1[0x64]) {
                    func_80800944_ncpoducam(local_1);
                } else {
                    local_1[0x64] = 1;
                }
            }
            func_80800A94_ncpoducam(local_1, param_1);
            if (!(*(s16 *)(local_1 + 0x48) & 2)) {
                func_80800944_ncpoducam(local_1);
            }
            local_0 = func_80800B74_ncpoducam(local_1, param_1);
            break;
        case 2:
            local_0 = func_80800854_ncpoducam(local_1, param_1);
            if (local_0 == 4) {
                return local_0;
            }
            func_80800A94_ncpoducam(local_1, param_1);
            break;
        case 3:
            break;
    }
    return local_0;
}

s32 ncpoducam_entrypoint_8(PodCameraState *param_0, s32 param_1)
{
    switch ((*(PodCameraState **)&param_0)->local_1) {
    case 8:
        return _susplinet_entrypoint_4(func_8001B798(param_0->local_0), param_1);
    case 5:
    case 6:
        break;
    }
    return 0;
}

s32 ncpoducam_entrypoint_9(u8 *param_0, f32 param_1)
{
    void *local_0;

    switch (param_0[0x60]) {
        case 8:
            local_0 = func_8001B798(*(s16 *)(param_0 + 2));
            return _susplinet_entrypoint_5(local_0, param_1);
        case 5:
        case 6:
            local_0 = func_8001B798(*(s16 *)param_0);
            return _suspline_entrypoint_2(local_0, param_1);
    }
    return 0;
}

f32 ncpoducam_entrypoint_10(u8 *param_0)
{
    switch (param_0[0x60]) {
    case 8:
        return _susplinet_entrypoint_9(func_8001B798(*(s16 *)(param_0 + 2)));
    case 5:
    case 6:
        return _suspline_entrypoint_6(func_8001B798(*(s16 *)param_0));
    default:
        return 0.0f;
    }
}

int ncpoducam_entrypoint_11(s32 param_0[3])
{
  func_800EE7F8(&param_0[15]);
}
