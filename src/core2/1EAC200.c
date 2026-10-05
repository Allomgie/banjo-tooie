#include "common.h"

typedef struct { s16 map; u8 flags; u8 pad[13]; } LocalEntry;
typedef struct { u8 enabled, pad; s16 color[4]; s16 pad2; f32 near, far; } LocalRange;
typedef struct { u8 enabled, status, pad[2]; LocalRange range[2]; s16 color[4]; } LocalState;
extern LocalState D_8012B320;
extern LocalEntry D_8011B530[];
extern s32 func_800EA05C(void);
typedef struct { u32 word0, word1; } LocalGfx;
extern void *func_800A89F8(void);
extern void *func_800A9478(void *);
extern void *func_800A93E4(void *);
extern s32 func_800F6BE4(void *);
extern s32 func_8010FFD8(void *);
extern s32 func_800F0D90(s32, s32, s32);
extern void func_800E3CB8(f32 *, f32 *);
typedef struct {u8 local_0; u8 local_1; u8 local_2[42]; s16 local_3[4];} local_type;
extern u8 D_8012B321;
typedef struct { s32 pad[2]; } EntryD2CD0;
typedef struct { s16 *local_0; s32 local_1; } StateD2CD0;
extern StateD2CD0 D_8012B360;
extern void func_800BE58C(s32 *, s32 *);
extern void *heap_alloc(s32);
extern void func_800BE52C(EntryD2CD0 **, s32 *);
extern s32 func_800E9D68(EntryD2CD0 *);
extern s32 func_800E9DC4(EntryD2CD0 *);
s32 defrag();
int func_800D2CC4();

void func_800D2910(s32 param_0, u8 *param_1)
{
    s32 idx = param_0 * 0x14;
    u8 *ptr = &((u8 *) &D_8012B320)[idx];

    ptr[4] = 1;
    *(s16 *)(ptr + 6) = *(u8 *)(param_1 + 0xC);
    *(s16 *)(ptr + 8) = param_1[0xD];
    *(s16 *)(ptr + 0xA) = param_1[0xE];
    *(s16 *)(ptr + 0xC) = param_1[0xF];
    *((f32 *)&ptr[0x10]) = *((f32 *)&param_1[4]);
    *((f32 *)&ptr[0x14]) = *((f32 *)&param_1[8]);
    ((u8 *) &D_8012B320)[0]++;
}

void func_800D2970(void)
{
  D_8012B320.range[0].enabled = D_8012B320.range[1].enabled = 0;
  D_8012B320.status = 0;
  D_8012B320.enabled = 0;
}

void func_800D298C(void)
{
    LocalEntry *local_0;
    s32 local_1;
    local_0 = D_8011B530;
    local_1 = func_800EA05C();
    D_8012B320.range[1].enabled = D_8012B320.status = D_8012B320.enabled = 0;
    D_8012B320.range[0].enabled = 0;
    while (local_0->map != -1) {
        if (local_0->map == local_1) {
            if (local_0->flags & 1) func_800D2910(0, local_0);
            if (local_0->flags & 2) func_800D2910(1, local_0);
        }
        local_0++;
    }
}

void func_800D2A44(LocalGfx **param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    s32 local_4;
    void *local_5;
    s32 local_6;
    f32 local_7;
    f32 local_8;
    s32 local_9;
    f32 local_10;
    f32 local_11;
    LocalGfx *local_12;
    s32 local_13;
    f32 local_14[1];
    if (D_8012B320.enabled) {
        local_5 = func_800A9478(func_800A89F8());
        if (func_800F6BE4(local_5)) {
            local_4 = func_8010FFD8(func_800A93E4(local_5));
        } else {
            local_4 = 1;
        }
        if (D_8012B320.range[1].enabled && local_4) {
            local_4 = 1;
        } else if (D_8012B320.range[0].enabled && !local_4) {
            local_4 = 0;
        } else {
            return;
        }
        func_800E3CB8(&local_0, &local_1);
        local_2 = local_0;
        local_3 = local_1;
        local_14[0] = local_3 - local_2;
        if (local_3 != local_2) {
            D_8012B320.color[0] = D_8012B320.range[local_4].color[0];
            D_8012B320.color[1] = D_8012B320.range[local_4].color[1];
            D_8012B320.color[2] = D_8012B320.range[local_4].color[2];
            D_8012B320.color[3] = D_8012B320.range[local_4].color[3];
            local_10 = D_8012B320.range[local_4].near;
            local_11 = D_8012B320.range[local_4].far;
            local_9 = 0;
            if (local_3 < local_10) {
                local_6 = 0;
            } else {
                local_3 = (2.0f * local_3) / local_14[0];
                local_7 = (1.0f - local_2 / local_10) * local_3 - 1.0f;
                local_8 = (1.0f - local_2 / local_11) * local_3 - 1.0f;
                local_3 = 1.0f / (local_8 - local_7);
                local_6 = (s32)(256.0f * local_3);
                local_9 = (s32)(-256.0f * local_7 * local_3);
            }
            local_12 = (*param_0)++;
            local_12->word0 = 0xDB080000;
            local_13 = func_800F0D90(local_6, -0x7FFF, 0x7FFF);
            local_12->word1 = (func_800F0D90(local_9, -0x7FFF, 0x7FFF) & 0xFFFF) | ((local_13 & 0xFFFF) << 16);
            func_800D2CC4();
        }
    }
}

void func_800D2C54(Gfx **param_0) {
    if (!(*((local_type *) &D_8012B320)).local_1) {
        gDPSetFogColor((*param_0)++, (*((local_type *) &D_8012B320)).local_3[0], (*((local_type *) &D_8012B320)).local_3[1], (*((local_type *) &D_8012B320)).local_3[2], (*((local_type *) &D_8012B320)).local_3[3]);
        (*((local_type *) &D_8012B320)).local_1 = 1;
    }
}

int func_800D2CC4()
{
  D_8012B321 = 0;
}

void func_800D2CD0(void) {
    s32 local_0[3];
    s32 local_1[3];
    s32 local_2[3];
    EntryD2CD0 *local_3;
    s32 local_4;
    EntryD2CD0 *local_5;
    s32 local_6;
    func_800BE58C(local_1, local_2);
    D_8012B360.local_1 = local_1[1];
    D_8012B360.local_0 = heap_alloc(D_8012B360.local_1 * 2);
    for (local_6 = 0; local_6 < D_8012B360.local_1; local_6++) *(s16 *)((u8 *)D_8012B360.local_0 + (local_6 << 1)) = 0;
    func_800BE52C(&local_3, &local_4);
    for (local_0[1] = 0; local_0[1] < local_1[1]; local_0[1]++) {
        for (local_0[0] = 0; local_0[0] < local_1[0]; local_0[0]++) {
            for (local_0[2] = 0; local_0[2] < local_1[2]; local_0[2]++) {
                local_5 = (local_0[1] * local_2[0]) + (local_0[0] + (local_3 + local_0[2] * local_2[1]));
                if (func_800E9D68(local_5)) {
                    local_6 = func_800E9DC4(local_5);
                    *(s16 *)((local_0[1] << 1) + (u8 *)D_8012B360.local_0) += local_6;
                }
            }
        }
    }
}

int func_800D2E4C()
{
  if (((void * *) &D_8012B360)[0] != 0)
  {
    heap_free(((void * *) &D_8012B360)[0]);
    ((void * *) &D_8012B360)[0] = 0;
  }
  ((void * *) &D_8012B360)[1] = 0;
}

u32 func_800D2E90(int param_0) {
    int local_0;

    if (param_0 < 0 || param_0 >= ((int *) &D_8012B360)[1]) {
        return 0;
    }
    if (*(s16 *)(((int *) &D_8012B360)[0] + param_0 * 2) != 0) {
        local_0 = 1;
    } else {
        local_0 = 0;
    }
    return local_0;
}

void func_800D2EE4()
{
  if ((*((s32 *) &D_8012B360)) != 0)
  {
    (*((s32 *) &D_8012B360)) = defrag((*((s32 *) &D_8012B360)));
  }
}
