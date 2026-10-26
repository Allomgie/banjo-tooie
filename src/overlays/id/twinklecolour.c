#include "common.h"

typedef struct { f32 unk0; s16 unk4; s16 unk6; s16 unk8; u8 unkA; u8 unkB; u8 unkC; u8 unkD; u8 padE[6]; } IdTwinkle_idtwinklecolour_entrypoint_0;
typedef struct { s16 unk0[3]; s16 unk6[3]; s16 unkC; s16 unkE[3]; s32 unk14; s16 unk18; s16 unk1A; u8 pad1C[4]; s16 unk20; s16 unk22; IdTwinkle_idtwinklecolour_entrypoint_0 *unk24; } IdTwinkleColour_idtwinklecolour_entrypoint_0;
extern s32 func_800DC214(s32, s32);
typedef struct { f32 f; s16 x; s16 y; s16 z; s16 padA; u8 idx; u8 padD[7]; } TwinkleEntry;
typedef struct { u8 pad0[0x22]; s16 count; TwinkleEntry *list; } TwinkleSet;
extern u8 D_80800970_idtwinklecolour[][3];
extern u8 _idtwinklecolour_entrypoint_0[];
extern u8 _idtwinklecolour_entrypoint_1[];
extern void heap_free();
typedef struct { u8 pad0[0xD]; u8 unkD; u8 padE[6]; } IdTwinkle_idtwinklecolour_entrypoint_4;
typedef struct { s16 unk0[3]; s16 unk6[3]; s16 unkC; u8 padE[0xA]; s16 unk18; s16 unk1A; u8 pad1C[6]; s16 unk22; IdTwinkle_idtwinklecolour_entrypoint_4 *unk24; } IdTwinkleColour_idtwinklecolour_entrypoint_4;
extern void _glidmake_entrypoint_2();
extern s16 _glidmake_entrypoint_3(s32, s32);
extern f32 sqrtf(f32);
extern void *heap_alloc(s32);
extern f32 func_800D8FF8(void);
extern void _idtwinklecolour_entrypoint_2(void);
extern void _glid_entrypoint_0(s32, s32, void (*)(void), void *);

void idtwinklecolour_entrypoint_0(s32 arg0, s16 *pos, s32 arg2, IdTwinkleColour_idtwinklecolour_entrypoint_0 *this)
{
    s32 i;
    s32 sq;
    s32 d[3];

    if (!this->unk24[this->unk20].unkD) {
        return;
    }
    for (i = 0; i < 3; i++) {
        d[i] = pos[i] - this->unkE[i];
    }
    sq = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
    if (this->unk14 < sq) {
        return;
    }
    for (i = 0; i < this->unk22; i++) {
        if (this->unk24[i].unk4 == pos[0] && this->unk24[i].unk6 == pos[1] && this->unk24[i].unk8 == pos[2]) {
            return;
        }
    }
    this->unk24[this->unk20].unk4 = pos[0];
    this->unk24[this->unk20].unk6 = pos[1];
    this->unk24[this->unk20].unk8 = pos[2];
    this->unk24[this->unk20].unk0 = 0.0f;
    this->unk24[this->unk20].unkB = 10;
    this->unk24[this->unk20].unkA = 1;
    this->unk24[this->unk20].unkD = 0;
    this->unk24[this->unk20].unkC = func_800DC214(0, 1);
}

void idtwinklecolour_entrypoint_1(s32 param_0, s16 *param_1, s32 param_2, s16 *param_3)
{
  if (!(*(s16*)((s8*)param_3 + 0x1E) != *(s16*)((s8*)param_3 + 0x1C))) {
    param_3[7] = param_1[0];
    param_3[8] = param_1[1];
    param_3[9] = param_1[2];
  }
  *(s16*)((s8*)param_3 + 0x1C) = *(s16*)((s8*)param_3 + 0x1C) + 1;
}

void idtwinklecolour_entrypoint_2(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, TwinkleSet *param_4)
{
    Vtx *local_0;
    s32 local_1;
    u8 *local_3;
    f32 local_4;

    local_0 = param_1 + param_3;
    for (; param_1 < local_0; param_1++, param_2++) {
        for (local_1 = 0; local_1 < param_4->count; local_1++) {
            if (param_1->v.ob[0] == param_4->list[local_1].x && param_1->v.ob[1] == param_4->list[local_1].y && param_1->v.ob[2] == param_4->list[local_1].z) {
                break;
            }
        }
        if (local_1 == param_4->count) {
            continue;
        }
        local_4 = param_4->list[local_1].f;
        local_3 = D_80800970_idtwinklecolour[param_4->list[local_1].idx];
        param_2->v.cn[0] = (u32)param_1->v.cn[0] + (local_3[0] - param_1->v.cn[0]) * local_4;
        param_2->v.cn[1] = (u32)param_1->v.cn[1] + (local_3[1] - param_1->v.cn[1]) * local_4;
        param_2->v.cn[2] = (u32)param_1->v.cn[2] + (local_3[2] - param_1->v.cn[2]) * local_4;
    }
}

void func_80800574_idtwinklecolour(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 *local_0;
  int local_1;
  local_0 = (s32 *) param_0;
  local_1 = func_800DC214(0, *((s16 *) (((char *) local_0) + 0xC)));
  *((s16 *) (((char *) local_0) + 0x1E)) = local_1;
  *((s16 *) (((char *) local_0) + 0x1C)) = 0;
  *((s16 *) (((char *) local_0) + 0x20)) = param_3;
  _glid_entrypoint_2(param_1, param_2, &_idtwinklecolour_entrypoint_1, local_0);
  local_1 = func_800DC214(*((s16 *) (((char *) local_0) + 0x18)), *((s16 *) (((char *) local_0) + 0x1A)));
  *((s32 *) (((char *) local_0) + 0x14)) = local_1 * local_1;
  _glid_entrypoint_2(param_1, param_2, &_idtwinklecolour_entrypoint_0, local_0);
}

void idtwinklecolour_entrypoint_3(void *param_0)
{
    heap_free(((void **)param_0)[9]);
}

void idtwinklecolour_entrypoint_4(IdTwinkleColour_idtwinklecolour_entrypoint_4 *this, s32 count, s32 arg2, s32 arg3)
{
    s16 diff[3];
    s32 i;
    s32 sum;

    sum = 0;
    _glidmake_entrypoint_2(arg2, arg3, this->unk0, this->unk6);
    this->unkC = _glidmake_entrypoint_3(arg2, arg3);
    for (i = 0; i < 3; i++) {
        diff[i] = this->unk6[i] - this->unk0[i];
        sum += diff[i] * diff[i];
    }
    sum = sqrtf(sum);
    this->unk22 = count;
    this->unk1A = sum * 0.25f;
    this->unk18 = this->unk1A * 0.5f;
    if (this->unk22 <= 0 || this->unk22 > 20) {
        this->unk22 = 5;
    }
    this->unk24 = heap_alloc(this->unk22 * sizeof(IdTwinkle_idtwinklecolour_entrypoint_4));
    bzero(this->unk24, this->unk22 * sizeof(IdTwinkle_idtwinklecolour_entrypoint_4));
    for (i = 0; i < this->unk22; i++) {
        this->unk24[i].unkD = 1;
        func_80800574_idtwinklecolour(this, arg2, arg3, i);
    }
}

void idtwinklecolour_entrypoint_5(u8 *param_0, s32 param_1, s32 param_2)
{
    f32 local_0;
    s32 local_1;
    s32 local_2;
    u8 *local_3;
    local_0 = func_800D8FF8();
    if (func_800E3DC0(param_0, param_0 + 6)) {
        for (local_1 = 0; local_1 < *(s16 *)(param_0 + 0x22); local_1++) {
            local_2 = local_1 * 0x14;
            local_3 = *(u8 **)(param_0 + 0x24) + local_2;
            *(f32 *)local_3 += (f32)*(s8 *)(local_3 + 0xB) * local_0;
            local_3 = *(u8 **)(param_0 + 0x24) + local_2;
            if (*(f32 *)local_3 >= 1.0f) {
                *(f32 *)local_3 = 1.0f;
                local_3 = *(u8 **)(param_0 + 0x24) + local_2;
                *(s8 *)(local_3 + 0xB) = -*(s8 *)(local_3 + 0xB);
            } else if (*(f32 *)local_3 < 0.0f) {
                *(f32 *)local_3 = 0.0f;
                (*(u8 **)(param_0 + 0x24) + local_2)[0xD] = 1;
            }
        }
        _glid_entrypoint_0(param_1, param_2, _idtwinklecolour_entrypoint_2, param_0);
        for (local_1 = 0; local_1 < *(s16 *)(param_0 + 0x22); local_1++) {
            local_2 = local_1 * 0x14;
            if ((*(u8 **)(param_0 + 0x24) + local_2)[0xD])
                func_80800574_idtwinklecolour(param_0, param_1, param_2, local_1);
        }
    }
}
