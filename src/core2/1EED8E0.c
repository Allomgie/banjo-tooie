/*
 * 1EED8E0 -- third of the three units the former 1EEC090 consists of,
 * from func_80113FF0 on. See 1EEC090.c for why the range is three objects.
 *
 * The boundary: 1EEC780 is used by 1EE9AB0 and the ba overlays, this unit
 * only by 1EE92B0, and func_80113FF0 is called only from func_80114184.
 *
 * Functions defined in the earlier units are declared here in exactly the
 * form their definitions had (prototype for ANSI, empty parameter list for
 * K&R), so every call compiles as it did in the combined file.
 */

#include "core2/1EEC090.h"
#include <types.h>
extern void func_800EF334(f32 *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EE7F8();
s32 func_800C6A7C(s32 param_0, s32 param_1, f32 *param_2, s32 param_3);
extern void *func_8010FF80(void *);
extern void *func_800A940C(void *);
typedef struct { s32 pad; f32 local_0; u8 local_1; u8 pad_1[3]; } Entry113FF0;
typedef struct { u8 pad[0x48]; Entry113FF0 local_0[7]; } State113FF0;
typedef struct { u32 local_0; f32 local_1; u8 local_2; u8 pad[3]; } Hit114184;
typedef struct { s16 local_0; u8 local_1, local_2; u8 pad[0x10]; f32 local_3[3]; u8 pad2[0x18]; u32 local_4; f32 local_5[3]; Hit114184 local_6[7]; } State114184;
typedef struct { u8 pad[8]; u32 local_0; } Surface114184;
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern void func_800CA8F4(void *, f32 *, f32 *);
extern s32 func_800CACEC(void *, f32 *, f32);
extern PlayerState *func_80110014(PlayerState *);
extern PlayerState *func_800F5EF8(s32);
extern s32 func_800F5898(void);
extern s32 func_800F6BE4(s32);
extern s32 func_800F6438(s32);
extern s32 func_800F6640(s32);
extern s32 func_800F6690(s32);
typedef struct { u8 pad[0x14]; u16 local_0; u8 pad2[2]; u16 local_1; } Marker11458C;
typedef struct { Marker11458C *local_0; s32 pad; u32 pad2:27; u32 local_1:1; u32 local_2:1; u32 pad3:2; u32 local_3:1; } Entry11458C;
typedef struct { u8 pad[0x64]; u32 pad2:14; u32 local_0:1; u32 pad3:17; u8 pad4[0x2C]; u32 pad5:17; u32 local_1:1; u32 pad6:14; } Actor11458C;
extern void **func_800BE444(f32 *);
extern Entry11458C *func_800E9E88(void *);
extern Entry11458C *func_800E9EB4(void *);
extern Actor11458C *func_80106790(Marker11458C *);
extern s32 func_801072A8(Actor11458C *);
extern f32 func_800EC75C(Marker11458C *, f32 *);
typedef struct { u8 pad[2]; u8 local_0; u8 pad2[9]; f32 local_1; u8 pad3[0x3C]; f32 local_2[1][3]; } Bounds114774;
extern f32 func_800F13F0(f32, f32);
extern f32 func_800C9588(void);
extern s32 func_800C954C(void);
typedef struct { u8 pad[3]; u8 local_0; u8 local_1; u8 pad5[3]; f32 local_2, local_3, local_4; } State149;
extern void func_800BED18(s32 *, s32 *);
extern s32 func_800BCC58(void);
extern s32 func_800E36D0(s32 *, s32 *, f32 *, f32 *);
extern void func_800EE84C(f32 *, s32 *);
extern void func_800BCC28(f32 *, f32 *);
extern f32 func_800C5190(void *);
typedef struct {s32 local_0; f32 local_1; u8 local_2; u8 local_3[3];} local_record;
typedef struct {s16 local_0; u8 local_1, local_2, local_3; u8 local_4[3]; f32 local_5; u8 local_6[60]; local_record local_7[7];} local_type;
extern void *heap_alloc(s32);
void func_80114CF4();

s32 func_80113FF0(State113FF0 *param_0) {
    f32 local_0;
    s32 local_1;
    s32 local_2;
    f32 local_3;
    local_0 = -1.0f;
    local_1 = -1;
    for (local_2 = 0; local_2 < 7; local_2++) {
        if (param_0->local_0[local_2].local_1) {
            local_3 = param_0->local_0[local_2].local_0;
            if (local_1 == -1 || local_3 < local_0) {
            local_0 = local_3;
            local_1 = local_2;
            }
        }
    }
    return local_1;
}

int func_8011413C(s32 param_0, f32 *param_1, f32 param_2, s32 param_3)
{
  if (param_3 != 0)
  {
    func_800CB0E8(param_0, param_1, param_3 - 1);
  }
  else
  {
    func_800CA740(param_0, param_1);
  }
  func_800EF334(param_1, param_2);
}

s32 func_80114184(State114184 *param_0, s32 param_1, f32 param_2, s32 param_3, u32 param_4) {
    f32 local_0[3], local_1[3], local_2[3];
    f32 local_3;
    f32 local_4[3];
    Surface114184 *local_5;
    s32 local_6;
    f32 local_7[3];
    if (!param_3) { func_80113FF0(param_0); return; }
    func_800CA8F4(param_1, local_1, local_2);
    if (param_0->local_2 && func_800EEAA4(local_2, param_0->local_5) < 0.1f) {
        func_800EFB24(local_7, local_1, param_0->local_3);
        local_3 = func_800EEAA4(local_7, param_0->local_5);
        param_0->local_6[6].local_0 = param_0->local_4;
        param_0->local_6[6].local_2 = 1;
        param_0->local_6[6].local_1 = local_3;
    } else {
        param_0->local_6[6].local_0 = 0;
        param_0->local_6[6].local_1 = -1.0f;
        param_0->local_6[6].local_2 = 0;
    }
    func_8011413C(param_1, local_0, param_2, param_0->local_0);
    func_800EF04C(local_0, local_1);
    local_5 = func_800C6A7C(local_1, local_0, local_4, param_4);
    if (local_5) {
        local_3 = func_800EEAD4(local_1, local_0);
        func_800EF3DC(local_0, local_1);
        param_0->local_6[param_0->local_0].local_0 = local_5->local_0;
        param_0->local_6[param_0->local_0].local_2 = 1;
    } else {
        param_0->local_6[param_0->local_0].local_0 = 0;
        local_3 = -1.0f;
        param_0->local_6[param_0->local_0].local_2 = 0;
    }
    param_0->local_6[param_0->local_0].local_1 = local_3;
    param_0->local_0++;
    if (param_0->local_0 >= 6) param_0->local_0 = 0;
    param_0->local_1 = 0;
    for (local_6 = 0; local_6 < 7; local_6++) {
        if (param_0->local_6[local_6].local_0) {
            if (param_0->local_6[local_6].local_0 & 0x20020) param_0->local_1 = 1;
            else { param_0->local_1 = 0; break; }
        }
    }
    func_80113FF0(param_0);
}

s32 func_801143A4(void *param_0, f32 *param_1, f32 param_2, f32 *param_3) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    func_800CA8F4(param_0, local_0, local_1);
    func_800EFB24(local_2, param_1, local_0);
    local_3 = func_800EEAA4(local_2, local_1) - param_2;
    if (local_3 < *param_3 && func_800CACEC(param_0, param_1, param_2)) {
        *param_3 = local_3;
        return 1;
    }
    return 0;
}

f32 func_80114444()
{
    if (func_800F5410() == 0xD)
    {
        return 1.1f;
    }
    return 0.8f;
}

int func_8011447C(PlayerState *param_0, PlayerState *param_1)
{
    s32 local_0;
    s32 local_1;
    f32 local_3[3];
    f32 local_2;
    local_1 = 0;
    for (local_0 = 0; local_0 < func_800F5898(); local_0++)
    {
        if ((((func_800F6BE4(local_0) && func_800F6BE4(local_0)) && func_800F6438(local_0)) && func_800F6640(local_0)) && func_800F6690(local_0))
        {
            local_2 = func_80112550(func_80110014(func_800F5EF8(local_0)), local_3);
            local_1 |= func_801143A4(param_0, local_3, local_2 * func_80114444(local_0), param_1);
        }
    }
    return local_1;
}

s32 func_8011458C(f32 *param_0, f32 *param_1, f32 *param_2) {
    s32 local_0;
    f32 local_5, local_11;
    Marker11458C *local_6;
    Actor11458C *local_7;
    f32 local_4[3];
    Entry11458C *local_8, *local_9;
    void **local_10;
    local_10 = func_800BE444(param_1);
    local_0 = 0;
    if (*local_10) {
    local_11 = 0.8f;
    do {
        local_8 = func_800E9E88(*local_10);
        local_9 = func_800E9EB4(*local_10);
        for (; local_8 < local_9; local_8++) {
            if (!local_8->local_1 || !local_8->local_3 || local_8->local_2) continue;
            local_6 = local_8->local_0;
            if (!(local_6->local_1 & 1)) continue;
            if (local_6->local_0 == 0 || local_6->local_0 == 0xFFFF) continue;
            local_7 = func_80106790(local_6);
            if (!local_7->local_1 || local_7->local_0 || func_801072A8(local_7)) continue;
            local_5 = func_800EC75C(local_6, local_4) * local_11;
            if (func_801143A4(param_0, local_4, local_5, param_2)) {
                local_0 = 1;
                if (*param_2 < 0.0f) {
                    *param_2 = 0.0f;
                    break;
                }
            }
        }
        if (local_8 < local_9) break;
        local_10++;
    } while (*local_10);
    }
    if (local_0 && *param_2 < 25.0f) *param_2 = 25.0f;
    return local_0;
}

f32 func_80114774(Bounds114774 *param_0, void *param_1, s32 param_2, void *param_3) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    s32 local_3;
    f32 local_4;
    f32 local_5;
    local_4 = func_800F0E00(350.0f, param_0->local_1);
    local_3 = func_80114184(param_0, param_1, local_4, 1, 0x820020);
    local_1 = param_0->local_1;
    if (local_3 != -1) {
        local_5 = param_0->local_2[local_3][0] * 0.8f - 15.0f;
        local_1 = func_800F13F0(local_1, local_5);
    }
    local_0 = local_1;
    if (func_8011447C(param_1, &local_0)) {
        if (local_0 < 0.0f) local_0 = 0.0f;
        local_1 = func_800F13F0(local_1, local_0);
    }
    local_0 = local_1;
    if (local_1 > 25.0f && func_8011458C(param_1, param_3, &local_0)) local_1 = func_800F13F0(local_1, local_0);
    if (func_800C954C()) local_1 = func_800F13F0(local_1, func_800C9588() * 0.8f);
    local_2 = param_0->local_0 ? 25.0f : 10.0f;
    if (local_1 < local_2) local_1 = local_2;
    return local_1;
}

void func_8011490C(State149 *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2[3];
    s32 local_3[3];
    void *local_4;
    s32 local_5;
    f32 local_8[3];
    f32 local_9[3];
    f32 local_10;
    local_4 = func_8010FF80(param_1);
    func_800BED18(local_2, local_3);
    func_800CA8F4(local_4, local_0, local_1);
    if (func_800BCC58()) {
        func_800EE84C(local_8, local_2);
        func_800EE84C(local_9, local_3);
        func_800BCC28(local_8, local_8);
        func_800BCC28(local_9, local_9);
        for (local_5 = 0; local_5 < 3; local_5++) {
            if (local_8[local_5] < local_2[local_5]) local_2[local_5] = local_8[local_5];
            if (local_3[local_5] < local_9[local_5]) local_3[local_5] = local_9[local_5];
            if (local_3[local_5] < local_8[local_5]) local_3[local_5] = local_8[local_5];
            if (local_9[local_5] < local_2[local_5]) local_2[local_5] = local_9[local_5];
        }
    }
    param_0->local_4 = func_800E36D0(local_2, local_3, local_0, local_1) + 100.0f;
    if (param_0->local_4 < 1000.0f) param_0->local_4 = 1000.0f;
    else if (32000.0f < param_0->local_4) param_0->local_4 = 32000.0f;
    param_0->local_3 = param_0->local_4 * 0.0078125f;
    if (param_0->local_2 > 0.0f) param_0->local_3 = param_0->local_2;
    else if (param_0->local_3 < 10.0f) param_0->local_3 = 10.0f;
    else param_0->local_3 = func_800F13F0(param_0->local_3, func_80114774(param_0, local_4, param_1, local_0));
    local_10 = 1.0f / func_800C5190(func_800A940C(param_2));
    if (local_10 != 1.0f) {
        param_0->local_3 *= local_10;
        param_0->local_4 *= local_10;
    }
    if (param_0->local_2 > 0.0f && param_0->local_1) {
        param_0->local_1 = 0;
        param_0->local_2 = 0.0f;
    }
    param_0->local_0 = 0;
}

local_type *func_80114BD4(void) {
    local_type *local_0;
    s32 local_1;
    local_0 = heap_alloc(sizeof(local_type));
    local_0->local_1 = 0;
    local_0->local_0 = 0;
    local_0->local_2 = 0;
    local_0->local_3 = 0;
    local_0->local_5 = 0.0f;
    for (local_1 = 0; local_1 < 7; local_1++) {
        local_0->local_7[local_1].local_0 = 0;
        local_0->local_7[local_1].local_1 = -1.0f;
        local_0->local_7[local_1].local_2 = 0;
    }
    return local_0;
}

void func_80114C7C(void* arg0) 
{
    heap_free(arg0);
}
int func_80114C9C(f32 param_0[3], f32 *param_1, f32 *param_2)
{
  *param_1 = *(f32*)((s8*)param_0 + 12);
  *param_2 = param_0[4];
}

func_80114CB0(s32 param_0, f32 param_1){
    *(s8*)(param_0 + 4) = 0;
    *(f32*)(param_0 + 8) = param_1;
}

func_80114CC0(s32 *param_0, f32 param_1) {
    *(s8 *)((char *)param_0 + 4) = 1;
    *(f32 *)((char *)param_0 + 8) = param_1;
}

void* func_80114CD4(void* arg0) 
{
    return defrag(arg0);
}
void func_80114CF4(param_0, param_1, param_2, param_3) u8 * param_0; s32 param_1; s32 param_2; s32 param_3;
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  if (!(param_2 & 0x40000))
  {
    local_0 = 0;
    local_1 = param_0 + 0x14;
    local_2 = param_1;
    do
    {
      func_800EE7F8(local_1, local_2);
      local_0 += 0xC;
      local_1 += 0xC;
      local_2 += 0xC;
    }
    while (local_0 != 0x24);
    func_800EE7F8(param_0 + 0x3C, param_3);
    *((s8 *) (((s8 *) param_0) + 3)) = 1;
    *((s32 *) (((s8 *) param_0) + 0x38)) = param_2;
    *((s8 *) (((s8 *) param_0) + 3)) = 1;
  }
}
