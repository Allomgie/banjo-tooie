#include "common.h"
#include "freelist.h"
#include <freelist.h>

typedef struct { s32 shift, base; } LocalExponent;
extern LocalExponent D_801234C0[];
extern f32 D_80125E40;
extern f32 D_80125E44;
extern u16 func_8001A0C0(s32, s32);
extern f32 mlAbsF(f32);
typedef struct { s32 vector[3]; } LocalRecord;
typedef struct { f32 local_0, local_1; s32 local_2; } ViewE82;
typedef struct { void *local_0; ViewE82 local_1[2][5]; s32 local_2; } StateE82;
typedef struct { f32 local_0[3], local_1; f32 local_2[3], local_3[3], local_4[3]; s16 local_5, local_6; } SampleE82;
typedef struct { u8 pad[0xC]; f32 local_0; SampleE82 local_1[2][5]; s16 local_2; } EntryE82;
extern void *func_800A8984(s32);
extern void func_800CA6D4(void *, f32 *, f32 *);
extern void _chjiggygamenew_entrypoint_2(void);
extern s32 func_800DA298(s32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern u8 *D_8012D600;
typedef struct {u8 local_0[0x34]; s16 local_1; u8 local_2[2];} local_entry;
typedef struct {u8 local_0[12]; f32 local_1; local_entry local_2[2][5]; s16 local_3; u16 local_4;} local_type;
extern void func_800EE7F8(void *param_0, s32 param_1);
typedef struct { f32 local_0; f32 local_1; f32 local_2; u8 local_3[4]; f32 local_4[3]; f32 local_5[3]; f32 local_6[3]; s16 local_7; s16 local_8; } local_inner;
typedef struct { u8 local_0[0xC]; f32 local_1; local_inner local_2[2][5]; s16 local_3; } local_outer;
extern s32 D_8012D67C;
extern s32 func_800C4C34(s32, local_outer *, local_inner *, s32 *);
extern f32 func_800E3928(local_outer *, f32 *);
extern void func_800E3980(f32 *);
s16 func_800E8918();

f32 func_800E81E0(s32 param_0, s32 param_1, f32 param_2, f32 param_3)
{
    s32 local_0;
    s32 local_1;
    LocalExponent *local_2;
    s32 local_4, local_5, local_6;
    f32 local_3;
    local_0 = func_8001A0C0(param_0, param_1);
    local_4 = (local_0 >> 13) & 7;
    local_2 = &D_801234C0[local_4];
    local_5 = (local_0 >> 2) & 0x7FF;
    local_1 = local_2->base + (local_5 << local_2->shift);
    local_6 = local_1 / 256 - 511;
    local_3 = local_6 / D_80125E40 - param_2;
    return mlAbsF(local_3) < D_80125E44 ? 0.0f : param_3 / local_3;
}

void func_800E829C(void)
{
    s32 local_0, local_1;
    for (local_0 = 0; local_0 < 2; local_0++) {
        for (local_1 = 0; local_1 < 5; local_1++) {
            ((LocalRecord *) &D_8012D600)[local_0 * 5 + local_1 + 1].vector[0] = 0;
        }
    }
}

void func_800E82EC(void)
{
    s32 local_10;
    s32 local_0;
    s32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    s32 local_6;
    EntryE82 *local_8;
    SampleE82 *local_9;
    local_2 = 2.0f;
    for (local_6 = 0; local_6 < 5; local_6++) {
        local_8 = func_800A8984(local_6);
        if (local_8) {
            func_800CA6D4(local_8, &local_3, &local_4);
            local_5 = 1.0f / (local_3 - local_4);
            (*((StateE82 *) &D_8012D600)).local_1[(*((StateE82 *) &D_8012D600)).local_2][local_6].local_0 = -((local_3 + local_4) * local_5);
            (*((StateE82 *) &D_8012D600)).local_1[(*((StateE82 *) &D_8012D600)).local_2][local_6].local_1 = -(local_2 * local_3 * local_4 * local_5);
            (*((StateE82 *) &D_8012D600)).local_1[(*((StateE82 *) &D_8012D600)).local_2][local_6].local_2 = 1;
        } else {
            (*((StateE82 *) &D_8012D600)).local_1[(*((StateE82 *) &D_8012D600)).local_2][local_6].local_2 = 0;
        }
    }
    if (++(*((StateE82 *) &D_8012D600)).local_2 >= 2) (*((StateE82 *) &D_8012D600)).local_2 = 0;
    if (func_800DA298(0xD4E) || func_800DA298(0xD4F)) _chjiggygamenew_entrypoint_2();
    if ((*((StateE82 *) &D_8012D600)).local_0) {
        local_1 = freelist_capacity((*((StateE82 *) &D_8012D600)).local_0);
        for (local_0 = 1; local_0 < local_1; local_0++) {
            if (freelist_is_element_alive((*((StateE82 *) &D_8012D600)).local_0, local_0)) {
                local_8 = freelist_at((*((StateE82 *) &D_8012D600)).local_0, local_0);
                for (local_6 = 0; local_6 < 5; local_6++) {
                    local_9 = &local_8->local_1[(*((StateE82 *) &D_8012D600)).local_2][local_6];
                    if (local_9->local_6 &&(*((StateE82 *) &D_8012D600)).local_1[(*((StateE82 *) &D_8012D600)).local_2][local_6].local_2) {
                        if (!(local_9->local_0[0] < 0.0f) && !(local_9->local_0[0] >= 304.0f) && !(local_9->local_0[1] < 0.0f) && !(local_9->local_0[1] >= 228.0f)) {
                            switch (local_8->local_2) {
                                case 1:
                                    local_5 = -func_800E81E0(local_9->local_0[0], local_9->local_0[1], (*((StateE82 *) &D_8012D600)).local_1[(*((StateE82 *) &D_8012D600)).local_2][local_6].local_0, (*((StateE82 *) &D_8012D600)).local_1[(*((StateE82 *) &D_8012D600)).local_2][local_6].local_1);
                                    local_2 = local_9->local_0[2] - local_5;
                                    local_9->local_1 = local_5;
                                    if (mlAbsF(local_2) < local_8->local_0) local_9->local_5 = 1;
                                    else if (local_2 > 0.0f) local_9->local_5 = 0;
                                    else local_9->local_5 = 1;
                                    func_800EFB24(local_9->local_4, local_9->local_3, local_9->local_2);
                                    func_800EF334(local_9->local_4, local_9->local_1 / local_9->local_0[2]);
                                    func_800EF04C(local_9->local_4, local_9->local_2);
                                    break;
                                case 0:
                                    if (func_8001A0C0(local_9->local_0[0], local_9->local_0[1]) == 0xFFFC) local_9->local_5 = 1;
                                    else local_9->local_5 = 0;
                                    break;
                            }
                        } else { local_9->local_5 = -1; }
                    } else {
                        local_9->local_5 = -1;
                    }
                    local_9->local_6 = 0;
                }
            }
        }
    }
}

int func_800E86DC()
{
  if (D_8012D600 != 0)
  {
    freelist_free(D_8012D600);
    D_8012D600 = 0;
  }
}

int func_800E8714(s32 param_0) {
    s32 local_0;
    local_type *local_1;
    s32 local_2;
    s32 local_3;
    if (!((FreeList *) D_8012D600)) D_8012D600 = freelist_new(sizeof(local_type), 4);
    local_1 = freelist_next(((FreeList * *) &D_8012D600), &local_0);
    bzero(local_1, sizeof(local_type));
    for (local_2 = 0; local_2 < 2; local_2++) {
        for (local_3 = 0; local_3 < 5; local_3++) {
            local_1->local_2[local_2][local_3].local_1 = -1;
        }
    }
    local_1->local_1 = 20.0f;
    local_1->local_3 = param_0;
    return (u8)local_0;
}

s32 func_800E87E0(param_0) u8 param_0;{
    freelist_erase(D_8012D600, param_0);
    if(!freelist_used_count(D_8012D600)){
        freelist_free(D_8012D600);
        D_8012D600 = 0;
    }
}

void func_800E8830(param_0, param_1) u8 param_0; s32 param_1;
{
  void *local_0;
  local_0 = freelist_at(((void *) D_8012D600), param_0);
  func_800EE7F8(local_0, param_1);
}

void func_800E8870(param_0, param_1) u8 param_0; s32 param_1;
{
  u8 *local_0;
  local_0 = freelist_at(((FreeList *) D_8012D600), param_0);
  *((float *) (local_0 + 12)) = *((float *) (&param_1));
}

int func_800E88AC(param_0, param_1) u8 param_0; s32 param_1;
{
  u32 local_0;
  local_0 = func_800A89F8();
  func_800E8918(param_0, local_0 | 0, 0, param_1);
}

int func_800E88E4(param_0) u8 param_0;
{
  u32 local_0;
  local_0 = func_800A89F8();
  func_800E8918(param_0, local_0 | 0, 0, 0);
}

s16 func_800E8918(param_0, param_1, param_2, param_3) u8 param_0; s32 param_1; f32 * param_2; f32 * param_3; {
    f32 local_0[3];
    local_inner *local_1;
    local_outer *local_2;
    s32 local_3;
    s32 local_4;
    local_2 = freelist_at(((FreeList *) D_8012D600), param_0);
    local_1 = &local_2->local_2[D_8012D67C][param_1];
    if (local_1->local_8) local_1->local_8 = 0;
    local_3 = func_800C4C34(param_1, local_2, local_1, &local_4);
    if (local_4 && local_3) {
        local_1->local_2 = func_800E3928(local_2, local_0);
        func_800E3980(local_1->local_4);
        func_800EE7F8(local_1->local_5, (f32 *)local_2);
        local_1->local_8 = 1;
    }
    if (param_3) { param_3[0] = local_1->local_0; param_3[1] = local_1->local_1; }
    if (param_2) func_800EE7F8(param_2, local_1->local_6);
    return local_1->local_7;
}

void func_800E8A20()
{
  if (D_8012D600 != 0)
  {
    D_8012D600 = freelist_defrag(D_8012D600);
  }
}
