#include "common.h"

typedef struct { f32 local_0; f32 pad_0[2]; f32 local_1; } PodDialogRange;
typedef struct { PodDialogRange local_0[2]; u8 pad_0[8]; f32 local_1[2][3]; } PodDialogPositions;
extern void func_800EE7F8(f32 *, f32 *);
typedef struct { u8 pad_0[0x28]; f32 first[3]; f32 second[3]; f32 pad_1; f32 angle; u8 pad_2[0x1CC]; u8 positive; } PodDialogDirection;
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800139F8(f32);
typedef struct { u8 padC4[0xC4]; f32 unkC4[30]; f32 unk13C[6]; f32 unk154; u8 pad158[0x9C]; f32 unk1F4[3]; f32 unk200[3]; f32 unk20C; u8 unk210; s8 unk211; u8 unk212; u8 unk213; u8 unk214; u8 unk215; } PodDialog;
extern s32 _ncpod_entrypoint_5(s32, s32, s32, s32, PodDialog *);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF9A8(f32 *, f32 *, f32);
extern void func_800EF8BC(f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
typedef struct { f32 unk0; f32 unk4; f32 unk8; } PodDialogEntry;
extern PodDialogEntry D_80802A40_ncpoddialog[];
typedef struct { u8 pad_0[0x211]; s8 local_0; u8 pad_1[5]; u8 local_1; } DialogFraming301;
extern void func_800A8A04(s32, s32 *, s32 *, s32 *, s32 *);
extern void func_8001B798();
typedef struct { /* 0x000 */ f32 range[2][4]; /* 0x020 */ f32 weight[2]; /* 0x028 */ f32 posA[2][3]; /* 0x040 */ f32 posB[2][3]; /* 0x058 */ f32 pathA[10][3]; /* 0x0D0 */ f32 pathB[10][3]; /* 0x148 */ f32 vec148[3]; /* 0x154 */ f32 unk154; /* 0x158 */ u8 pad158[0x18]; /* 0x170 */ f32 vec170[3]; /* 0x17C */ f32 vec17C[3]; /* 0x188 */ f32 pathC[10][3]; /* 0x200 */ f32 vec200[3]; /* 0x20C */ f32 unk20C; /* 0x210 */ u8 unk210; /* 0x211 */ s8 unk211; /* 0x212 */ u8 unk212; /* 0x213 */ u8 unk213; /* 0x214 */ u8 unk214; /* 0x215 */ u8 unk215; /* 0x216 */ u8 unk216; /* 0x217 */ u8 unk217; } PodDialogState;
extern s16 func_8001B668(s32, s32);
extern void func_800EFD24(f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern s32 _ncpod_entrypoint_4(s32 param_0);
extern s32 func_80110024(s32 param_0);
extern s32 func_800BF340(f32 *, f32 *, f32 *, u32, f32);
typedef struct { u8 pad_0[0x58]; f32 local_0[10][3]; } DialogCameraSegments;
typedef struct { u8 pad_0[0x58]; f32 position[3]; u8 pad_1[0x60]; f32 first[3]; f32 angles[2]; u8 pad_2[0x64]; f32 pitch; f32 yaw; f32 pad_3; f32 second[3]; } PodDialogOrientation;
extern f32 func_800136E4(f32);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct { f32 local_0[10][3]; } DialogPoseChain;
extern void func_800EEB9C(f32 *, f32, f32);
typedef struct { u8 pad0[0x58]; f32 path[10][3]; f32 rot[10][3]; f32 center[3]; u8 pad154[0x34]; f32 out[10][3]; f32 unk200[3]; } PodPath;
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800F0EF0(s32, f32 *);
typedef struct PodDialogRotation { f32 local_0; f32 local_1; f32 local_2; f32 local_3; } PodDialogRotation;
extern void func_800EF334(f32 *, f32);
typedef struct { u8 pad_0[0x20]; f32 distances[2]; } NcPodPlayerDistances;
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EE7B4(f32 *, f32 *, f32 *, f32);
extern f32 func_800F2094(f32, f32);
extern s32 func_800F20BC(f32, f32, f32);
extern s32 func_800F05F8(f32 *, f32 *, f32 *, f32, f32 *);
typedef struct { f32 local_0[2][4]; f32 local_1[2]; u8 pad_0[0x1EE]; u8 local_2; } PodDialogLimits;
extern s32 func_800EEDE8(f32 *, f32 *, f32);
typedef struct { u8 pad_0[0x211]; s8 local_0; u8 local_1; u8 local_2; u8 pad_1[2]; u8 local_3; } NcpodDialogState;
extern f32 func_800D8FF8(void);
extern f32 _mlspline_entrypoint_13(s32, f32 *, f32, f32, f32, void *);
extern void _mlspline_entrypoint_8(void);
extern void _mlspline_entrypoint_4(f32, s32, f32 *, f32 *);
extern void _ncpod_entrypoint_9(s32, f32);
extern void func_800EF368(f32 *, f32);
void func_80800D10_ncpoddialog();
s32 func_808013C0_ncpoddialog();
s32 func_80801504_ncpoddialog();
void func_808017F4_ncpoddialog();
void func_80801B98_ncpoddialog();
s32 ncpoddialog_entrypoint_11();
s32 func_80800698_ncpoddialog();
int func_808006D4_ncpoddialog();
s32 func_808015CC_ncpoddialog();
extern void func_8080189C_ncpoddialog(f32 *);
void func_808023B4_ncpoddialog();

void func_80800000_ncpoddialog(PodDialogPositions *param_0, s32 param_1, f32 *param_2)
{
    func_800EE7F8(param_2, param_0->local_1[param_1]);
    param_2[1] += param_0->local_0[param_1].local_1;
    param_2[1] += 0.5f * (param_0->local_0[param_1].local_0 - param_0->local_0[param_1].local_1);
}

void func_8080008C_ncpoddialog(PodDialogDirection *param_0)
{
    f32 local_0;
    local_0 = func_800F1DCC(func_800F1DF4(param_0->first, param_0->second), param_0->angle);
    if (local_0 < -90.0f || local_0 > 90.0f) local_0 = -local_0;
    if (local_0 > 0.0f) param_0->positive = 1;
    else param_0->positive = 0;
}

s32 func_80800128_ncpoddialog(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3, s32 *param_4)
{
    f32 local_0[3];
    f32 local_6;
    f32 local_7;
    f32 local_1[4];
    f32 local_2[4];
    f32 local_3[4][4];
    f32 local_4;
    f32 local_5[4][4];

    local_4 = 1.0f / func_800139F8(20.0f);
    func_800D93A0(local_1, param_3);
    func_800D965C(local_1, local_3);
    func_800D9624(local_2, local_1);
    func_800D965C(local_2, local_5);
    func_800EFB24(local_0, param_0, param_2);
    func_800F23D0(local_5, local_0, local_0);
    local_6 = (f32)(param_4[3] - param_4[1]) * local_4 * 0.5f;
    local_7 = 1.0f / local_0[2];
    param_1[0] = (f32)(param_4[2] - param_4[0]) * 0.5f - local_0[0] * local_6 * local_7;
    param_1[1] = (f32)(param_4[3] - param_4[1]) * 0.5f + local_0[1] * local_6 * local_7;
    param_1[0] += (f32)param_4[0];
    param_1[1] += (f32)param_4[1];
    if (local_0[2] > 0.0f || param_1[0] < (f32)param_4[0] ||
        (f32)param_4[0] < param_1[0] || param_1[1] < (f32)param_4[1] ||
        (f32)param_4[3] < param_1[1]) {
        return 0;
    }
    return 1;
}

s32 func_80800338_ncpoddialog(PodDialog *this, s32 arg1, s32 state)
{
    s32 r;
    s32 v;

    this->unk210 = state;
    if (this->unk210 == 2) {
        if (this->unk215 == 0) {
            func_8080008C_ncpoddialog(this);
        }
        this->unk154 = 0;
        switch (this->unk213) {
        case 1:
            this->unk20C = 1.0f;
            break;
        case 0:
        case 2:
            this->unk20C = 0.0f;
            break;
        }
        func_808017F4_ncpoddialog(this, arg1);
        if (this->unk211 != 0 && this->unk211 != 1) {
            func_80800D10_ncpoddialog(this, this->unkC4, this->unk13C);
        }
        func_80801B98_ncpoddialog(this);
        r = func_808013C0_ncpoddialog(this);
        v = func_80801504_ncpoddialog(this);
        if (this->unk211 == 9) {
        } else if (this->unk212 && this->unk211 == 8 && r == 0) {
            if (_ncpod_entrypoint_5(arg1, func_80110024(arg1), 0xAC, this->unk211, this) != 5) {
                v = _ncpod_entrypoint_5(arg1, func_80110024(arg1), 0x58, this->unk211, NULL);
                if (v == 4) {
                    return v;
                }
                this->unk212 = 0;
                func_80800338_ncpoddialog(this, arg1, 1);
                return 3;
            }
            this->unk211 = 9;
            this->unk212 = 1;
            func_80800338_ncpoddialog(this, arg1, 2);
            return 3;
        } else {
        switch (this->unk213) {
        case 0:
        case 2:
            if (v == 0) {
                this->unk213 = 1;
                func_80800338_ncpoddialog(this, arg1, 2);
                return 3;
            }
        case 1:
            if (r == 0) {
                if (this->unk211 != 2 && this->unk211 != 6) {
                    this->unk211 = 8;
                } else {
                    this->unk211 = 4;
                }
                this->unk212 = 1;
                func_80800338_ncpoddialog(this, arg1, 2);
                return 3;
            }
            func_800EE7F8(this->unk200, this->unk1F4);
            break;
        }
        }
    }
    return 3;
}

s32 func_80800584_ncpoddialog(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3, f32 *param_4, s32 param_5, s32 *param_6, s32 *param_7)
{
    f32 local_0[2];
    s32 local_1 = 0;
    func_80800128_ncpoddialog(param_0, local_0, param_3, param_4, param_7);
    if (!*param_6) {
        param_1[0] = local_0[0];
        param_1[1] = local_0[1];
        param_2[0] = local_0[0];
        param_2[1] = local_0[1];
        *param_6 = 1;
        local_1 = 2;
    } else {
        if (local_0[0] < param_1[0]) { param_1[0] = local_0[0]; local_1 = 1; }
        if (param_2[0] < local_0[0]) { param_2[0] = local_0[0]; local_1 = 1; }
        if (local_0[1] < param_1[1]) { param_1[1] = local_0[1]; local_1 = 1; }
        if (param_2[1] < local_0[1]) { param_2[1] = local_0[1]; local_1 = 1; }
    }
    return local_1;
}

s32 func_80800698_ncpoddialog(param_0) u8 *param_0; {
  switch (*(s8 *)((char *)param_0 + 0x211) - 2)
  {
    case 0 :
    case 2 :
    case 3 :
    case 4 :
    case 6 :
    case 7 :
      return 1;

    case 1 :
    case 5 :
    default :
      break;
  }
  return 0;
}

int func_808006D4_ncpoddialog(param_0) s32 param_0[0];
{
  switch (*(s8 *)((char *)param_0 + 0x211) - 2)
  {
    case 0 :
    case 1 :
    case 2 :
    case 4 :
    case 6 :
    case 7 :
      return 1;

    case 3 :
    case 5 :
    default :
      break;
  }
  return 0;
}

void func_80800710_ncpoddialog(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3, f32 *param_4, s32 param_5, s32 *param_6)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    f32 local_6[3];
    f32 local_7[3];
    f32 local_8[3];
    f32 local_9[3];

    local_5 = 0;
    if (func_808006D4_ncpoddialog(param_0)) {
        local_6[1] = (param_0[0] - param_0[3]) * 0.5f;
        local_6[0] = param_0[1] * 0.5f;
        local_6[2] = param_0[2] * 0.5f;
        local_0[0] = 0.0f;
        local_0[1] = param_0[3] + local_6[1];
        local_0[2] = 0.0f;
        func_800EF5A0(local_0, &param_0[0x10], local_0[0], local_0[1], local_0[2]);
        func_800EF04C(local_0, &param_0[0xA]);
        for (local_2 = -1; local_2 < 2; local_2 += 2) {
            for (local_3 = -1; local_3 < 2; local_3 += 2) {
                for (local_4 = -1; local_4 < 2; local_4 += 2) {
                    func_800EF5A0(local_1, &param_0[0x10], local_6[0] * local_2, local_6[1] * local_3, local_6[2] * local_4);
                    func_800EF04C(local_1, local_0);
                    func_80800584_ncpoddialog(local_1, param_1, param_2, param_3, param_4, param_5, &local_5, param_6);
                }
            }
        }
    }
    if (func_80800698_ncpoddialog(param_0)) {
        local_9[1] = (param_0[4] - param_0[7]) * 0.5f;
        local_9[0] = param_0[5] * 0.5f;
        local_9[2] = param_0[6] * 0.5f;
        local_0[0] = 0.0f;
        local_0[1] = param_0[7] + local_9[1];
        local_0[2] = 0.0f;
        func_800EE7F8(local_7, &param_0[0x13]);
        local_7[0] = 0.0f;
        func_800EF5A0(local_0, local_7, local_0[0], local_0[1], local_0[2]);
        func_800EE7F8(local_8, &param_0[0xD]);
        func_800EF04C(local_0, local_8);
        for (local_2 = -1; local_2 < 2; local_2 += 2) {
            for (local_3 = -1; local_3 < 2; local_3 += 2) {
                for (local_4 = -1; local_4 < 2; local_4 += 2) {
                    func_800EF5A0(local_1, local_7, local_9[0] * local_2, local_9[1] * local_3, local_9[2] * local_4);
                    func_800EF04C(local_1, local_0);
                    func_80800584_ncpoddialog(local_1, param_1, param_2, param_3, param_4, param_5, &local_5, param_6);
                }
            }
        }
    }
}

void func_80800A98_ncpoddialog(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4)
{
    f32 local_0[3];
    func_800EFA4C(local_0, param_2, param_3, param_4);
    func_800EF9A8(local_0, local_0, param_1[2]);
    func_800EF8BC(local_0, local_0, param_1[0]);
    func_800EF934(local_0, local_0, param_1[1]);
    func_800EF04C(param_0, local_0);
}

s32 func_80800B28_ncpoddialog(f32 *pos, f32 *arg1, f32 *arg2, s32 *rect, s32 idx, f32 *center, f32 *size)
{
    f32 max[2];
    f32 min[2];

    func_80800A98_ncpoddialog(arg1, arg2, D_80802A40_ncpoddialog[idx].unk0, D_80802A40_ncpoddialog[idx].unk4, D_80802A40_ncpoddialog[idx].unk8);
    func_80800710_ncpoddialog(pos, max, min, arg1, arg2, 0, rect);
    size[0] = max[0] - min[0];
    size[1] = max[1] - min[1];
    center[0] = min[0] + size[0] * 0.5f;
    center[1] = min[1] + size[1] * 0.5f;
    switch (idx) {
    case 5:
    case 6:
        if (min[0] < rect[0] + 20 || rect[2] - 20 < min[0] || min[1] < rect[1] + 20 || rect[3] - 20 < min[1]) {
            return 0;
        }
        if (max[0] < rect[0] + 20 || rect[2] - 20 < max[0] || max[1] < rect[1] + 20 || rect[3] - 20 < max[1]) {
            return 0;
        }
        break;
    }
    return 1;
}

void func_80800D10_ncpoddialog(param_0, param_1, param_2) DialogFraming301 *param_0; f32 *param_1; f32 *param_2;
{
    f32 local_2[2];
    f32 local_1[2];
    s32 local_0[4];
    f32 local_5;
    s32 local_4;
    s32 local_3 = 0;

    func_800A8A04(0, &local_0[0], &local_0[1], &local_0[2], &local_0[3]);
    local_0[1] = 28;
    local_0[3] = 200;
    local_4 = (f32)local_0[0] + (f32)local_0[2] * 0.5f;
    func_80800B28_ncpoddialog(param_0, param_1, param_2, local_0, 0, local_1, local_2);
    if (param_0->local_0 != 8 && param_0->local_0 != 9) {
        local_5 = local_4;
        while (local_5 < local_1[0] && local_3 != 10) {
            local_3++;
            func_80800B28_ncpoddialog(param_0, param_1, param_2, local_0, 1, local_1, local_2);
        }
        local_3 = 0;
        while (local_1[0] < local_5 && local_3 != 10) {
            local_3++;
            func_80800B28_ncpoddialog(param_0, param_1, param_2, local_0, 2, local_1, local_2);
        }
        local_3 = 0;
        local_5 = local_3 + 0x72; /* agV12: 0x72 reaches the int->float cvt only via constant propagation (local_3 == 0) -> runtime li/mtc1/cvt.s.w like target without the k1 slot; a literal 0x72 is folded */
        while (local_1[1] < local_5 && local_3 != 10) {
            local_3++;
            func_80800B28_ncpoddialog(param_0, param_1, param_2, local_0, 3, local_1, local_2);
        }
        local_3 = 0;
        while (local_5 < local_1[1] && local_3 != 10) {
            local_3++;
            func_80800B28_ncpoddialog(param_0, param_1, param_2, local_0, 4, local_1, local_2);
        }
        local_3 = 0;
    }
    if (!param_0->local_1) {
        while (func_80800B28_ncpoddialog(param_0, param_1, param_2, local_0, 5, local_1, local_2) && local_3 < 10) {
            local_3++;
        }
        local_3 = 0;
    }
    while (!func_80800B28_ncpoddialog(param_0, param_1, param_2, local_0, 6, local_1, local_2) && local_3 < 10) {
        local_3++;
    }
}

s32 func_80801058_ncpoddialog(u8 *param_0, s32 param_1) {
    if (param_0[0x212]) {
        param_0[0x212] = 0;
        return func_80800338_ncpoddialog(param_0, param_1, 2);
    }
    return 3;
}

s32 ncpoddialog_entrypoint_0(s16 param_0) {
    s32 local_0 = param_0;
    func_8001B798(local_0);
}

int ncpoddialog_entrypoint_1(param_0, param_1) s16 param_0; s32 param_1;
{
  u32 local_0;
  s32 new_var;
  u32 local_1;
  local_0 = ncpoddialog_entrypoint_0(param_0);
  local_1 = func_80801058_ncpoddialog(local_0 | 0, param_1);
  if (4 == local_1)
  {
    return local_1;
  }
  if (((*((u8 *) (local_0 + 0x210))) != 1) && ((*((u8 *) (local_0 + 0x210))) == 2))
  {
    new_var = param_1;
    local_1 = func_808015CC_ncpoddialog(local_0 & 0xFFFFFFFFu, new_var, local_0);
    if (4 == local_1)
    {
      return local_1;
    }
  }
  return local_1;
}

int ncpoddialog_entrypoint_2(void)
{
    s16 local_0;
    PodDialogState *local_1;
    s32 local_2;
    s32 local_3;
    f32 *w;

    local_0 = func_8001B668(0, 0x21C);
    local_1 = ncpoddialog_entrypoint_0(local_0);
    local_1->unk210 = 1;
    for (local_2 = 0; local_2 != 10; local_2++) {
        func_800EFD24(local_1->pathA[local_2]);
        func_800EFD24(local_1->pathB[local_2]);
        func_800EFD24(local_1->pathC[local_2]);
    }
    local_1->unk20C = 0.0f;
    func_800EFD24(local_1->vec148);
    local_1->unk154 = 0.0f;
    local_1->unk211 = -1;
    local_1->unk212 = 0;
    local_1->unk213 = 0;
    local_1->unk214 = 0;
    local_1->unk215 = 0;
    local_1->unk217 = 0;
    func_800EFD24(local_1->vec170);
    func_800EFD24(local_1->vec17C);
    func_800EFD24(local_1->vec200);
    for (local_3 = 0; local_3 != 2; local_3++) {
        func_800EFD24(local_1->posA[local_3]);
        func_800EFD24(local_1->posB[local_3]);
        w = &local_1->weight[local_3];
        local_1->range[local_3][1] = 0.0f;
        local_1->range[local_3][2] = 0.0f;
        local_1->range[local_3][3] = 0.0f;
        local_1->range[local_3][0] = 0.0f;
        *w = 0.0f;
    }
    return local_0;
}

int func_808012A0_ncpoddialog(s32 param_0, s32 param_1, s32 param_2)
{
  if (func_800F690C(param_0) || func_800F693C(param_0))
  {
    _plcamera_entrypoint_14(param_0, param_1, param_2);
  }
  else
  {
    func_8010FFB0(func_800F5EF8(param_0), param_1, param_2);
  }
}

void func_80801310_ncpoddialog(param_0, param_1) u8 *param_0; s32 param_1;
{
    f32 local_0[3];
    func_808012A0_ncpoddialog(_ncpod_entrypoint_4(func_80110024(param_1)), param_0 + 0x158, param_0 + 0x164);
    func_800EE7F8(param_0 + 0x200, param_0 + 0x158);
    func_800EE7F8(local_0, param_0 + 0x164);
    func_800EF214(param_0 + 0x200, -local_0[0], local_0[1], -5e+02f);
}

s32 ncpoddialog_entrypoint_3(param_0) s16 param_0;{
    func_8001B754(param_0);
}

s32 func_808013C0_ncpoddialog(param_0) u8 *param_0;
{
    Vec3f local_0;
    Vec3f local_1;
    Vec3f local_2;
    s32 local_4 = 1;

    if (func_808006D4_ncpoddialog(param_0)) {
        func_80800000_ncpoddialog(param_0, 0, local_1.f);
        func_800EE7F8(local_2.f, (f32 *)(param_0 + 0xC4));
        if (func_800BF340(local_2.f, local_1.f, local_0.f, 0x860020, 30.0f)) local_4 = 0;
        else if (func_800BF340(local_1.f, local_2.f, local_0.f, 0x860020, 30.0f)) local_4 = 0;
    }
    if (func_80800698_ncpoddialog(param_0)) {
        func_80800000_ncpoddialog(param_0, 1, local_1.f);
        func_800EE7F8(local_2.f, (f32 *)(param_0 + 0xC4));
        if (func_800BF340(local_2.f, local_1.f, local_0.f, 0x860020, 30.0f)) local_4 = 0;
        else if (func_800BF340(local_1.f, local_2.f, local_0.f, 0x860020, 30.0f)) local_4 = 0;
    }
    return local_4;
}

s32 func_80801504_ncpoddialog(param_0) DialogCameraSegments *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    s32 local_3;

    local_3 = 1;
    for (local_2 = 0; local_2 < 9; local_2++) {
        func_800EE7F8(local_1, param_0->local_0[local_2 + 1]);
        if (func_800BF340(param_0->local_0[local_2], local_1, local_0, 0x860020, 30.0f)) local_3 = 0;
    }
    return local_3;
}

s32 func_808015CC_ncpoddialog(param_0, param_1) u8 *param_0; s32 param_1;
{
    f32 local_1;
    f32 local_0;
    f32 *local_2;

    switch (param_0[0x213]) {
    case 2:
        local_1 = 10.0f;
        local_0 = 20.0f;
        break;
    case 0:
        local_1 = 125.0f;
        local_0 = 500.0f;
        break;
    case 1:
        local_0 = local_1 = 5000.0f;
        break;
    }
    if (*(f32 *)(param_0 + 0x20C) < 0.15f) {
        *(f32 *)(param_0 + 0x154) = func_800F10B4(*(f32 *)(param_0 + 0x20C), 0.0f, 0.15f, local_1, local_0);
    } else if (*(f32 *)(param_0 + 0x20C) > 0.85f) {
        *(f32 *)(param_0 + 0x154) = func_800F10B4(*(f32 *)(param_0 + 0x20C), 0.85f, 1.0, local_0, local_1);
    }
    if (*(f32 *)(param_0 + 0x20C) < 1.0f) {
        if (param_0[0x213] == 1) {
            *(f32 *)(param_0 + 0x20C) = 1.0f;
            local_2 = (f32 *)(param_0 + 0x58);
        } else {
            local_2 = (f32 *)(param_0 + 0x58);
            *(f32 *)(param_0 + 0x20C) = _mlspline_entrypoint_13(10, local_2,
                *(f32 *)(param_0 + 0x20C), *(f32 *)(param_0 + 0x154) * func_800D8FF8(), 1.0f, _mlspline_entrypoint_8);
        }
    } else {
        *(f32 *)(param_0 + 0x20C) = 1.0f;
        if (_ncpod_entrypoint_5(param_1, func_80110024(param_1), 0x58, *(s8 *)(param_0 + 0x211), 0) == 4) {
            return 4;
        }
        func_80800338_ncpoddialog(param_0, param_1, 1);
        local_2 = (f32 *)(param_0 + 0x58);
    }
    _mlspline_entrypoint_4(*(f32 *)(param_0 + 0x20C), 10, local_2, (f32 *)(param_0 + 0x170));
    _mlspline_entrypoint_4(*(f32 *)(param_0 + 0x20C), 10, (f32 *)(param_0 + 0xD0), (f32 *)(param_0 + 0x17C));
    _ncpod_entrypoint_8(func_80110024(param_1), (f32 *)(param_0 + 0x170), (f32 *)(param_0 + 0x17C));
    _ncpod_entrypoint_9(func_80110024(param_1), 40.0f);
    return 0;
}

void func_808017F4_ncpoddialog(param_0, param_1) PodDialogOrientation *param_0; s32 param_1;
{
    s32 local_0;
    local_0 = _ncpod_entrypoint_4(func_80110024(param_1));
    func_808023B4_ncpoddialog(param_0, param_1);
    func_808012A0_ncpoddialog(local_0, param_0->position, param_0->angles);
    param_0->angles[0] = func_800136E4(param_0->angles[0]);
    param_0->angles[1] = func_800136E4(param_0->angles[1]);
    param_0->yaw = func_800136E4(func_800F1DF4(param_0->second, param_0->first));
    param_0->pitch = func_800136E4(-func_800F1828(param_0->second, param_0->first));
}

void func_8080189C_ncpoddialog(param_0) f32 *param_0;
{
    s32 local_0;
    if (param_0[9] + 178.0f <= param_0[0]) { param_0[0] -= 360.0f; }
    if (param_0[0] + 178.0f <= param_0[9]) { param_0[9] -= 360.0f; }
    for (local_0 = 1; local_0 < 9; local_0++) {
        param_0[local_0] = param_0[0] * ((f32)(9 - local_0) * 0.11111111f) +
            param_0[9] * ((f32)local_0 * 0.11111111f);
    }
}

void func_80801A30_ncpoddialog(f32 *param_0)
{
    s32 local_0;
    for (local_0 = 1; local_0 < 9; local_0++) {
        param_0[local_0] = func_800F10B4(local_0, 0.0f, 9.0f, param_0[0], param_0[9]);
    }
}

void func_80801AC0_ncpoddialog(DialogPoseChain *param_0, f32 *param_1, f32 *param_2, f32 *param_3)
{
    s32 local_0;
    for (local_0 = 1; local_0 < 9; local_0++) {
        func_800EEB9C(param_0->local_0[local_0], param_1[local_0], param_2[local_0]);
        func_800EF04C(param_0->local_0[local_0], param_3);
        param_0->local_0[local_0][1] = func_800F10B4((f32)local_0, 0.0f, 9.0f, param_0->local_0[0][1], param_0->local_0[9][1]);
    }
}

void func_80801B98_ncpoddialog(PodPath *this)
{
    f32 angs[10];
    f32 dists[10];
    f32 pts[10][3];
    f32 d;
    s32 i;
    s32 j;

    angs[0] = func_800136E4(func_800F1DF4(this->center, this->path[0]));
    angs[9] = func_800136E4(func_800F1DF4(this->center, this->path[9]));
    func_8080189C_ncpoddialog(angs);
    dists[0] = func_800EFB8C(this->path[0], this->center);
    dists[9] = func_800EFB8C(this->path[9], this->center);
    func_80801A30_ncpoddialog(dists);
    func_80801AC0_ncpoddialog(this->path[0], angs, dists, this->center);
    d = func_800EEAD4(this->path[9], this->center);
    func_800EE7F8(pts[0], this->unk200);
    func_800EE7F8(pts[9], this->path[9]);
    func_800EF214(pts[9], -this->rot[9][0], this->rot[9][1], -d);
    for (i = 1; i < 9; i++) {
        for (j = 0; j < 3; j++) {
            pts[i][j] = func_800F10B4(i, 0.0f, 9.0f, pts[0][j], pts[9][j]);
        }
    }
    for (i = 0; i < 10; i++) {
        func_800EE7F8(this->out[i], pts[i]);
    }
    for (i = 1; i < 9; i++) {
        this->rot[i][1] = func_800136E4(func_800F1DF4(pts[i], this->path[i]));
        this->rot[i][0] = func_800136E4(-func_800F1828(pts[i], this->path[i]));
        this->rot[i][2] = 0.0f;
    }
    func_800F0EF0(10, this->rot[0]);
}

void func_80801DB8_ncpoddialog(u8 *param_0, s32 param_1, f32 param_2)
{

    f32 local_1;
    func_80800000_ncpoddialog(param_0, param_1, ((f32 *)(param_0 + 0x148)));
    param_2 += ((f32 (*)[3])(param_0 + 0x44))[param_1][0];
    local_1 = ((PodDialogRotation *)param_0)[param_1].local_0 - ((PodDialogRotation *)param_0)[param_1].local_3;
    if (local_1 < ((PodDialogRotation *)param_0)[param_1].local_1) {
        local_1 = ((PodDialogRotation *)param_0)[param_1].local_1;
    }
    if (local_1 < ((PodDialogRotation *)param_0)[param_1].local_2) {
        local_1 = ((PodDialogRotation *)param_0)[param_1].local_2;
    }
    func_800EEB9C((f32 *)(param_0 + 0xC4), param_2, local_1);
    func_800EF04C((f32 *)(param_0 + 0xC4), ((f32 *)(param_0 + 0x148)));
    *(f32 *)(param_0 + 0xC8) = *(f32 *)(param_0 + 0x14C);
}

void func_80801E78_ncpoddialog(u8 *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 *local_1;
    f32 local_3;
    local_1 = (f32 *)(param_0 + 0xC4);
    func_80800000_ncpoddialog(param_0, 1 - param_1, local_1);
    func_80800000_ncpoddialog(param_0, param_1, (f32 *)(param_0 + 0x148));
    *(f32 *)(param_0 + 0xC8) += *(f32 *)(param_0 + 0x14C);
    *(f32 *)(param_0 + 0xC8) *= 0.5f;
    *(f32 *)(param_0 + 0x14C) = *(f32 *)(param_0 + 0xC8);
    local_3 = func_800F1DF4((f32 *)(param_0 + 0x148), local_1);
    if (param_2) local_3 += 90.0f;
    else local_3 -= 90.0f;
    func_800EEB9C(local_0, local_3, ((NcPodPlayerDistances *)param_0)->distances[1 - param_1]);
    func_800EF04C(local_1, local_0);
    func_800EFB24(local_0, local_1, (f32 *)(param_0 + 0x148));
    func_800EF334(local_0, 0.5f);
    func_800EF04C(local_1, local_0);
}

void func_80801F88_ncpoddialog(u8 *param_0, f32 param_1)
{
    f32 local_0;
    f32 *local_4;
    f32 local_1[3];
    f32 local_2[3];

    func_80800000_ncpoddialog(param_0, 1, local_1);
    func_800EE780(local_2, (f32 *)(param_0 + 0x28), local_1);
    func_800EF334(local_2, 0.5f);
    local_0 = func_800F1DF4((f32 *)(param_0 + 0x28), local_1);
    func_800F1828((f32 *)(param_0 + 0x28), local_1);
    local_0 += param_1;
    local_4 = (f32 *)(param_0 + 0xC4);
    func_800EEC30(local_4, 0.0f, local_0, 500.0f);
    func_800EE7B4((f32 *)(param_0 + 0x148), local_2, local_4, -0.1f);
    func_800EF04C(local_4, local_2);
}

void func_80802048_ncpoddialog(void *param_0, f32 *param_1, f32 *param_2, f32 *param_3, f32 param_4)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    s32 local_6;
    Vec3f local_7;
    Vec3f local_8;
    s32 local_9;
    s32 local_10;
    s32 local_11;
    f32 local_12;
    f32 local_13;
    f32 local_14;
    s32 local_15;
    Vec3f local_16;

    local_0 = param_2[1];
    param_4 *= 0.75f;
    if (param_4 < 5.0f) {
        return;
    }
    local_1 = func_800EFB8C(param_1, param_2);
    if (local_1 < func_800EFB8C(param_1, param_3) - param_4) {
        return;
    }
    local_2 = func_800EFB8C(param_1, param_3);
    local_3 = func_800F1DF4(param_1, param_3);
    local_4 = func_800F1DF4(param_1, param_2);
    func_800EEB9C(local_8.f, local_3 + 90.0f, param_4);
    func_800EE7F8(local_7.f, local_8.f);
    func_800EF04C(local_8.f, param_3);
    func_800EFB24(local_7.f, param_3, local_7.f);
    local_5 = func_800F2094(func_800F1DF4(param_1, local_8.f), local_3);
    local_6 = func_800F20BC(local_4, local_3, local_5);
    if (local_6) {
        local_12 = param_4 * 0.5f + local_2;
        if (local_1 < local_12) {
            local_1 = local_12;
        }
        local_13 = local_5 * 0.5f;
        local_9 = func_800F20BC(local_4, local_13 + local_3, local_13);
        if (local_9) {
            local_4 = local_3 + local_5;
        } else {
            local_4 = local_3 - local_5;
        }
        func_800EEB9C(param_2, local_4, local_1);
        func_800EF04C(param_2, param_1);
        func_800EFB24(local_16.f, param_2, param_1);
        local_15 = 1;
        local_10 = 0;
        while (local_15 && local_10++ < 5) {
            local_15 = func_800F05F8(param_1, local_16.f, param_3, param_4, &local_14);
            if (local_15 && local_14 < 1.0f) {
                local_11 = local_5 < 0.0f ? -5 : 5;
                local_4 += local_11;
                func_800EEB9C(local_16.f, local_4, local_1);
            }
        }
        func_800EEB9C(param_2, local_4, local_1);
        func_800EF04C(param_2, param_1);
    }
    param_2[1] = local_0;
}

void func_8080230C_ncpoddialog(u8 *param_0, u8 *param_1, u8 *param_2) {
    s8 var_v0;

    var_v0 = ((s8 *)param_0)[0x211];
    if (var_v0 == 4 || var_v0 == 5 || var_v0 == 6 || var_v0 == 8) {
        func_80802048_ncpoddialog(param_0, param_1, param_2, param_0 + 0x28, (*(f32 *)((u8 *)param_0 + 0x20)));
        var_v0 = ((s8 *)param_0)[0x211];
    }
    if (var_v0 == 2 || var_v0 == 3 || var_v0 == 4 || var_v0 == 8) {
        func_80802048_ncpoddialog(param_0, param_1, param_2, param_0 + 0x34, (*(f32 *)((u8 *)param_0 + 0x24)));
    }
}

void func_808023B4_ncpoddialog(param_0, param_1) u8 *param_0; s32 param_1;
{
    s32 local_0;
    Vec3f local_1;
    Vec3f local_2;
    Vec3f local_3;
    Vec3f local_4;
    Vec3f local_5;

    local_0 = 0;
    if (param_0[0x214] == 1) {
        local_0 = 1;
    }
    switch (param_0[0x211]) {
    case 0:
    case 1:
        func_800EE7F8((f32 *)(param_0 + 0xC4), (f32 *)(param_0 + 0x158));
        func_800EEC30((f32 *)(param_0 + 0x148), -*(f32 *)(param_0 + 0x164), *(f32 *)(param_0 + 0x168), 500.0f);
        func_800EF04C((f32 *)(param_0 + 0x148), (f32 *)(param_0 + 0x158));
        break;
    case 4:
        func_80801F88_ncpoddialog(param_0, (f32)(local_0 ? -90 : 90));
        break;
    case 2:
        func_80801E78_ncpoddialog(param_0, 0, 1 - local_0);
        break;
    case 6:
        func_80801E78_ncpoddialog(param_0, 1, local_0);
        break;
    case 5:
        func_80801DB8_ncpoddialog(param_0, 1, (f32)(local_0 ? 10 : -10));
        break;
    case 3:
        func_80801DB8_ncpoddialog(param_0, 0, (f32)(local_0 ? -10 : 10));
        break;
    case 8:
        func_800EE7F8(local_1.f, (f32 *)(param_0 + 0x158));
        func_800EE7F8(local_2.f, (f32 *)(param_0 + 0x164));
        func_80800000_ncpoddialog(param_0, 0, local_3.f);
        func_80800000_ncpoddialog(param_0, 1, (f32 *)(param_0 + 0x148));
        func_800EF04C((f32 *)(param_0 + 0x148), local_3.f);
        func_800EF334((f32 *)(param_0 + 0x148), 0.5f);
        func_800EFB24((f32 *)(param_0 + 0xC4), (f32 *)(param_0 + 0x148), local_1.f);
        func_800EF368((f32 *)(param_0 + 0xC4), 250.0f);
        func_800EF04C((f32 *)(param_0 + 0xC4), local_1.f);
        func_800EEC30((f32 *)(param_0 + 0x188), -*(f32 *)(param_0 + 0xD0), *(f32 *)(param_0 + 0xD4), -200.0f);
        func_800EF04C((f32 *)(param_0 + 0x188), (f32 *)(param_0 + 0x58));
        func_800EE7F8((f32 *)(param_0 + 0x200), (f32 *)(param_0 + 0x188));
        break;
    case 9:
        func_80800000_ncpoddialog(param_0, 0, local_4.f);
        func_80800000_ncpoddialog(param_0, 1, (f32 *)(param_0 + 0x148));
        func_800EF04C((f32 *)(param_0 + 0x148), local_4.f);
        func_800EF334((f32 *)(param_0 + 0x148), 0.5f);
        func_800A5800(param_0[0x218]);
        _cadbfunc_entrypoint_0((f32 *)(param_0 + 0xC4));
        _cadbfunc_entrypoint_2(local_5.f);
        break;
    default:
        break;
    }
    func_8080230C_ncpoddialog(param_0, (f32 *)(param_0 + 0x148), (f32 *)(param_0 + 0xC4));
}

void ncpoddialog_entrypoint_4(PodDialogLimits *param_0, s32 param_1, f32 *param_2)
{
    s32 local_0;
    s32 local_1 = 0;

    for (local_0 = 0; local_0 < 4; local_0++) {
        if (param_2[local_0] + 10.0f < param_0->local_0[param_1][local_0] ||
            param_0->local_0[param_1][local_0] < param_2[local_0] - 10.0f) {
            param_0->local_0[param_1][local_0] = param_2[local_0];
            local_1 = 1;
        }
    }
    if (local_1) {
        param_0->local_1[param_1] = param_0->local_0[param_1][2] < param_0->local_0[param_1][1] ? param_0->local_0[param_1][1] : param_0->local_0[param_1][2];
        param_0->local_2 = 1;
    }
}

void ncpoddialog_entrypoint_5(u8 *param_0, s32 param_1, f32 *param_2)
{
    if (!func_800EEDE8(((f32 (*)[3])(param_0 + 0x28))[param_1], param_2, 10.0f)) {
        func_800EE7F8(((f32 (*)[3])(param_0 + 0x28))[param_1], param_2);
        param_0[0x216] = 1;
    }
}

void ncpoddialog_entrypoint_6(s32 param_0, s32 param_1, s32 param_2)
{
  int new_var;
  new_var = 0x40;
  func_800EE7F8(new_var + (param_0 + (param_1 * 0xC)), param_2);
}

void ncpoddialog_entrypoint_7(u8 *param_0, s32 param_1)
{
    if (param_1 >= 0)
    {
        (*(u8 *)((u8 *)(param_0) + 0x215)) = 1;
        if (param_1 == 0)
        {
            (*(u8 *)((u8 *)(param_0) + 0x214)) = 0;
            return;
        }
        (*(u8 *)((u8 *)(param_0) + 0x214)) = 1;
        return;
    }
    (*(u8 *)((u8 *)(param_0) + 0x215)) = 0;
}

int ncpoddialog_entrypoint_8(Actor *param_0, s32 param_1)
{
    *(u8 *)((char *)param_0 + 0x218) = param_1;
    return 5;
}

void ncpoddialog_entrypoint_9(NcpodDialogState *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    if (param_0->local_0 == -1) {
        func_80801310_ncpoddialog();
    }
    if (param_2 == param_0->local_0 && param_0->local_3 == 0) {
        return;
    }
    param_0->local_3 = 0;
    param_0->local_0 = param_2;
    param_0->local_2 = param_3;
    func_8009055C(100, (param_3 << 16) | param_2);
    if ((param_0->local_0 == 0 && param_0->local_2 == 1) || param_0->local_0 == 7) {
        if (_ncpod_entrypoint_5(param_1, func_80110024(param_1), 0x58, param_0->local_0, 0) != 4) {
            func_80800338_ncpoddialog(param_0, param_1, 1);
        }
    } else {
        param_0->local_1 = 1;
    }
}

void ncpoddialog_entrypoint_10(u32 arg0) {
    u32 v1 = arg0;
    u32 v2 = v1 & 0xFFFF0000;
    u32 v3 = v2 >> 16;
    u32 v4 = arg0 & 0xFFFF;
    ncpoddialog_entrypoint_11(v4, v3, 1);
}

s32 ncpoddialog_entrypoint_11(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
    switch (param_2) {
    case 0:
        if (param_0 == 0 || param_0 == 7) {
            return 1;
        }
        break;
    case 1:
        if (param_1 == 1 && (param_0 == 0 || param_0 == 1)) {
            return 1;
        }
        break;
    default:
        return 0;
    }
    return 0;
}
