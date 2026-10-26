#include "common.h"

#define IDBOUNCE_DATA_DEFINED
typedef struct { s16 x; s16 y; s16 z; s16 pad[5]; } BouncePt;
typedef struct { u8 pad0[4]; f32 unk4; u8 pad8[4]; f32 unkC; u8 pad10[0xC]; f32 unk1C; f32 unk20; u8 pad24[4]; f32 *unk28; u8 pad2C[8]; f32 unk34; f32 unk38; f32 unk3C; f32 unk40; f32 unk44; } BounceCtx;
extern u8 D_80135480[];
extern f32 sqrtf(f32);
extern s32 func_800F54E4(void);
typedef struct { u8 local_0; u8 pad_0[3]; f32 local_1[3]; u8 pad_1[0xC]; f32 local_2; f32 local_3; f32 *local_4; f32 *local_5; f32 *local_6; f32 local_7; f32 local_8; f32 local_9; f32 local_10; f32 local_11; f32 local_12; f32 local_13; f32 local_14; f32 local_15; f32 local_16[3]; } IdBounceData;
extern void func_800F83E4(u32, f32);
typedef struct { s32 local_0; u8 pad_0[0x1C]; } BounceLookupRecord;
extern BounceLookupRecord D_80800E50_idbounce[];
extern void heap_free(void *);
extern void *heap_alloc(s32);
extern void func_800EE7F8(f32 *, f32 *);
extern Actor *func_80106790(Unk80132ED0 *);
typedef struct { s8 local_0; u8 pad_0[0x1F]; f32 local_1; f32 *local_2; f32 *local_3; f32 *local_4; f32 local_5; f32 local_6; f32 local_7; f32 local_8; f32 local_9; f32 local_10; f32 local_11; f32 local_12; f32 local_13; f32 local_14[3]; } IdBounceInitData;
extern f32 func_800D8FF8(void);
extern void func_800EF334(f32 *, f32);
extern u8 D_8013546C;
extern void _idbounce_entrypoint_0(void);
extern void _idbounce_entrypoint_1(void);
extern void _idbounce_entrypoint_2(void);

f32 func_80800000_idbounce(void)
{
    switch (func_8008FD48()) {
    case 0x11:
        return 0.1f;
    case 0xA:
        return 0.7f;
    case 0xB:
        return 0.4f;
    default:
        return 1.0f;
    }
}

void idbounce_entrypoint_0(s32 param_0, BouncePt *param_1, BouncePt *param_2, s32 param_3, BounceCtx *param_4)
{
    f32 damp;
    f32 px;
    f32 pz;
    f32 k3;
    f32 k1;
    f32 k2;
    f32 acc;
    f32 dist;
    f32 dx;
    f32 dz;
    f32 f0;
    BouncePt *end;

    px = param_4->unk4;
    pz = param_4->unkC;
    damp = param_4->unk20;
    k1 = param_4->unk40;
    k2 = param_4->unk44;
    k3 = param_4->unk1C;
    end = param_2 + param_3;
    if (param_2 < end) {
        do {
            acc = 0.0f;
            if (D_80135480[1] != 0) {
                dx = (f32)param_2->x - px;
                dz = (f32)param_2->z - pz;
                dist = sqrtf(dx * dx + dz * dz);
                if (dist < param_4->unk34) {
                    acc = 0.0f - damp;
                } else if (dist < param_4->unk38) {
                    acc = 0.0f;
                    acc -= damp * (1.0f - (dist - param_4->unk34) * param_4->unk3C);
                }
            }
            acc = acc;
            acc += ((f32)(param_1->y - param_2->y) * k1 - *param_4->unk28 * k2);
            *param_4->unk28 += acc * k3;
            param_2->y += *param_4->unk28 * k3;
            if (D_80135480[1] != 0) {
                if (D_80135480[2] == 0 && dist < param_4->unk34) {
                    if (*param_4->unk28 < 0.0f) { if (*param_4->unk28 < 0.0f) {} } else {}
                    acc = *param_4->unk28;
                    if (D_80135480[2] == 0) {
                        if (2000.0f < *param_4->unk28) {
                            acc = 2000.0f;
                        }
                        else {}
                        func_800F83E4(func_800F54E4(), acc);
                        D_80135480[2] = 1;
                    }
                }
            }
            param_2++;
            param_1++;
            param_4->unk28 = param_4->unk28 + 1;
        } while (param_2 < end);
    }
}

void idbounce_entrypoint_1(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, IdBounceData *param_4)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;
    f32 local_9;
    Vtx *local_10;

    local_1 = param_4->local_1[0];
    local_2 = param_4->local_1[2];
    local_0 = param_4->local_3;
    local_4 = param_4->local_11;
    local_5 = param_4->local_12;
    local_3 = param_4->local_2;

    for (local_10 = param_2 + param_3; param_2 < local_10; param_2++) {
        if (1) {}
        local_6 = 0.0f;
        if (D_80135480[1]) {
            local_8 = param_2->v.ob[0] - local_1;
            local_9 = param_2->v.ob[2] - local_2;
            local_7 = sqrtf(local_8 * local_8 + local_9 * local_9);
            if (local_7 < param_4->local_8) {
                local_6 -= local_0;
            } else if (local_7 < param_4->local_9) {
                local_6 -= local_0 * (1.0f - (local_7 - param_4->local_8) * param_4->local_10);
            }
        }
        local_6 += (param_1->v.ob[1] - param_2->v.ob[1]) * local_4 - *param_4->local_5 * local_5;
        *param_4->local_5 += local_6 * local_3;
        param_2->v.ob[1] += *param_4->local_5 * local_3;
        if (D_80135480[1]) {
            if (D_80135480[2] == 0 && local_7 < param_4->local_8) {
                if (*param_4->local_5 < 0.0f) { if (*param_4->local_5 < 0.0f) {} } else {}
                local_6 = *param_4->local_5 / param_4->local_15;
                if (D_80135480[2] == 0) {
                    if (local_6 > 2000.0f) {
                        local_6 = 2000.0f;
                    }
                    func_800F83E4(func_800F54E4(), local_6);
                    D_80135480[2] = 1;
                }
            }
        }
        if (param_2->v.ob[1] < 0) {
            param_2->v.ob[1] = 0;
        }
        param_1++;
        param_4->local_5++;
    }
}

void idbounce_entrypoint_2(Vtx *param_0, Vtx *param_1, Vtx *param_2, s32 param_3, IdBounceData *param_4)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;
    f32 local_9;
    Vtx *local_10;
    s32 local_11;

    local_1 = param_4->local_1[0];
    local_2 = param_4->local_1[2];
    local_0 = param_4->local_3;
    local_4 = param_4->local_11;
    local_5 = param_4->local_12;
    local_11 = param_4->local_0 == 2;
    local_3 = param_4->local_2;

    for (local_10 = param_1 + param_3;
         param_1 < local_10;
         param_1++) {
        local_7 = param_4->local_9;
        local_6 = 0.0f;
        if (D_80135480[1]) {
            local_8 = param_2->v.ob[0] - local_1;
            local_9 = param_2->v.ob[2] - local_2;
            local_7 = sqrtf(local_8 * local_8 + local_9 * local_9);
            if (local_7 < param_4->local_8) {
                local_6 -= local_0;
            } else if (local_7 < param_4->local_9) {
                local_6 -= local_0 * (1.0f - (local_7 - param_4->local_8) * param_4->local_10);
            }
        }
        local_6 += (param_0->v.ob[1] - param_2->v.ob[1]) * local_4 - *param_4->local_5 * local_5;
        *param_4->local_5 += local_6 * local_3;
        param_1->v.ob[1] = *param_4->local_5 * local_3 + param_2->v.ob[1];
        if (D_80135480[1]) {
            if (D_80135480[2] == 0 && local_7 < param_4->local_8) {
                if (*param_4->local_5 < 0.0f) {
                    local_6 = *param_4->local_5 / param_4->local_15;
                } else if (*param_4->local_5 < 10.0f * param_4->local_15) {
                    local_6 = -1.0f;
                } else if (param_4->local_13 < *param_4->local_5) {
                    local_6 = *param_4->local_5 * param_4->local_14;
                } else {
                    local_6 = *param_4->local_5 / param_4->local_15;
                }
                if (D_80135480[2] == 0) {
                    if (local_6 > 2000.0f) {
                        local_6 = 2000.0f;
                    }
                    func_800F83E4(func_800F54E4(), local_6);
                    D_80135480[2] = 1;
                }
            }
        }
        if (local_11 && param_1->v.ob[1] < 0) {
            param_1->v.ob[1] = 0;
        }
        param_0++;
        param_2++;
        param_4->local_5++;
    }
}

BounceLookupRecord *func_80800874_idbounce(s32 param_0)
{
    BounceLookupRecord *local_0 = D_80800E50_idbounce;
    while (local_0->local_0 != -1) {
        if (local_0->local_0 == param_0) break;
        local_0++;
    }
    return local_0;
}

int func_808008B4_idbounce()
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800F54E4();
  local_1 = func_800F6C5C(local_0);
  if (local_1 == 0)
  {
    return 0;
  }
  else
  {
    if ((func_800F55FC(local_0) & 0x8000) == 0)
    {
      return 0;
    }
    return 1;
  }
}

void idbounce_entrypoint_3(u8 *param_0) {
    heap_free(*(void **)(param_0 + 0x24));
    D_80135480[3]--;
}

void idbounce_entrypoint_4(IdBounceInitData *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    f32 *local_0;
    s32 local_1;
    Actor *local_2;
    s32 local_3;

    local_0 = (f32 *)func_80800874_idbounce(param_1);
    local_1 = _glidmake_entrypoint_3(param_2, param_3);
    param_0->local_2 = heap_alloc(local_1 * sizeof(f32));
    param_0->local_4 = param_0->local_2 + local_1;
    for (param_0->local_3 = param_0->local_2; param_0->local_3 < param_0->local_4; param_0->local_3++) {
        *param_0->local_3 = 0.0f;
    }
    param_0->local_1 = 0.0f;
    param_0->local_5 = -local_0[1] / -2700.0f;
    param_0->local_6 = local_0[2];
    param_0->local_7 = local_0[3];
    param_0->local_9 = local_0[4];
    param_0->local_10 = local_0[5];
    param_0->local_11 = local_0[6];
    param_0->local_12 = local_0[7];
    if (param_4 == 4) {
        local_2 = func_80106790(func_80106314());
        param_0->local_13 = 1.0f / local_2->scale;
        func_800EE7F8(param_0->local_14, local_2->position);
        switch (local_2->unk6C_9) {
        case 0x34C: param_0->local_0 = 2; break;
        case 0x47E: case 0x4C4: case 0x4C5: case 0x4C6: case 0x4C7:
        case 0x50B: case 0x50C: case 0x531:
            param_0->local_0 = 3;
            break;
        default: param_0->local_0 = 1; break;
        }
    } else {
        param_0->local_14[2] = 0.0f;
        param_0->local_14[1] = 0.0f;
        param_0->local_14[0] = 0.0f;
        local_3 = func_800EA05C();
        if (local_3 != 0xE2 && local_3 != 0xE4 && local_3 != 0xE5 && local_3 != 0xF8 && local_3 != 0x138) {
            param_0->local_13 = 0.0f;
            param_0->local_0 = 0;
        } else {
            param_0->local_0 = 3;
            param_0->local_13 = 1.0f;
        }
    }
    if (param_0->local_13) {
        param_0->local_5 *= param_0->local_13;
        param_0->local_6 *= param_0->local_13;
        param_0->local_7 *= param_0->local_13;
        param_0->local_9 *= param_0->local_13;
        param_0->local_10 *= param_0->local_13;
        param_0->local_11 *= param_0->local_13;
        param_0->local_12 /= param_0->local_13;
    }
    param_0->local_8 = 1.0f / (local_0[3] - local_0[2]);
    D_80135480[3]++;
}

void idbounce_entrypoint_5(u8 *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    *(f32 *)(param_0 + 0x1C) = func_800D8FF8();
    func_800F5A00(func_800F54E4(), (f32 *)(param_0 + 4));
    func_800EF3DC((f32 *)(param_0 + 4), param_0 + 0x54);
    if (*(f32 *)(param_0 + 0x50) != 0.0f)
        func_800EF334((f32 *)(param_0 + 4), *(f32 *)(param_0 + 0x50));
    *(f32 *)(param_0 + 0x20) = -*(f32 *)(param_0 + 0x30) * func_80800000_idbounce() * -2700.0f;
    if (*((u8 *)&D_8013546C + 0x14)) {
        func_800F5D70(func_800F54E4(), local_0);
        *(f32 *)(param_0 + 0x20) -= *(f32 *)(param_0 + 0x30) * func_80800000_idbounce()
            * local_0[1] / *(f32 *)(param_0 + 0x1C);
    }
    *(s32 *)(param_0 + 0x28) = *(s32 *)(param_0 + 0x24);
    switch (param_0[0]) {
    case 0: _glid_entrypoint_0(param_1, param_2, _idbounce_entrypoint_0, param_0); break;
    case 1: _glid_entrypoint_0(param_1, param_2, _idbounce_entrypoint_1, param_0); break;
    case 2:
    case 3: _glid_entrypoint_1(param_1, param_2, _idbounce_entrypoint_2, param_0); break;
    }
}

void idbounce_entrypoint_6(void)
{
    s32 local_0;

    local_0 = func_808008B4_idbounce();
    D_80135480[2] = 0;
    D_80135480[0] = !D_80135480[1] && local_0 != 0;
    D_80135480[1] = local_0;
}

void idbounce_entrypoint_7(void)
{
    if (D_80135480[1] != 0 && D_80135480[2] == 0) {
        func_800F83E4(func_800F54E4(), -1.0f);
    }
}
