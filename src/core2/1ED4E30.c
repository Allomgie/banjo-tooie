#include "core2/1ED4E30.h"
#include "freelist.h"

extern s16 D_80123DE0[96];
extern void func_800DA544(s32);
extern void func_800FED70(s32);
typedef struct { u8 pad0[0x38]; void *unk38; s32 unk3C[5]; } S_FB650;
typedef struct { s32 unk0; s32 unk4; } R_FB650;
typedef struct { f32 field_0, field_4, field_8, field_C; f32 field_10, field_14, field_18, field_1C; s32 field_20, field_24; s16 field_28, field_2A; u32 field_2C; u8 pad_30:4, field_30:4; u8 field_31, field_32, field_33, field_34; u8 pad_35[3]; void *field_38; u8 pad_3C[0x14]; } LocalState_800FB6E0;
extern f32 D_801359B4;
extern f32 D_801359B8;
extern u8 D_801357D0[400];
void func_800172D4(u8, s32);
typedef struct { u32 local_0; f32 local_1; u8 local_2[0x18]; s32 local_3; s32 local_4; s16 local_5; s16 local_6; u32 local_7; u32 local_8:4; u32 local_9:28; u32 local_10; FreeList *local_11; s32 local_12[5]; } local_type_800FB808;
extern u8 D_80123E40;
extern void func_800FE614(void);
extern void func_80017864(void);
extern void func_80016E7C(void);
extern void func_80017244(void);
typedef struct { f32 delay, elapsed; f32 normal_0, normal_1; f32 paused_0, paused_1; f32 current_0, current_1; s32 volume, target; s16 track, step; u32 mask; u8 flag_30, stop_at_zero, pad_32[2], muted, pad_35[0x1B]; } LocalTrack;
extern u8 D_801359B1;
extern const f32 D_80126150;
extern f32 func_800D8FF8(void);
extern f32 func_800F13F0(f32, f32);
extern s32 func_80090200(void);
extern s32 func_800A5490(void);
extern s32 func_80017778(s32);
extern s32 func_800177C4(s32);
extern void func_80017534(u8, f32, f32);
extern void func_800175F0(void);
extern void func_800FDC58(s32);
extern void func_80017EC0(s32);
extern u32 func_800170D4(u8);
extern u32 func_80017070(u8);
extern void func_80017404(u8, s32);
typedef struct { f32 field_0, field_4, field_8, field_C; f32 field_10, field_14, field_18, field_1C; s32 field_20, field_24; s16 field_28, field_2A; s32 field_2C; u8 pad_30:4, field_30:4; u8 field_31, field_32, field_33, field_34; u8 pad_35[3]; void *field_38; u8 pad_3C[0x14]; } LocalState_800FBF9C;
typedef struct { s32 field_0, field_4; } LocalEntry;
extern s32 func_80017764();
extern u8 D_80135964[];
extern u8 D_80135980[];
extern u8 D_8013598A[];
extern u8 D_80135988[];
typedef struct { f32 field_0, field_4, field_8, field_C; f32 field_10, field_14, field_18, field_1C; s32 field_20, field_24; s16 field_28, field_2A; s32 field_2C; u8 pad_30[0x20]; } LocalState_800FC1CC;
typedef struct { f32 local_0; f32 local_1; u8 local_2[0x18]; s32 local_3; u8 local_4[4]; s16 local_5; s16 local_6; u8 local_7[5]; u8 local_8; u8 local_9[2]; u8 local_10; u8 local_11[0x1B]; } local_type_800FC508;
typedef struct { u8 pad_0[0x30]; u8 local_0 : 4; u8 local_1 : 4; } local_2;
extern u8 D_801359B0[4];
extern s32 func_800FE7A8(s32);
extern u8 unk10[];
extern u8 unkC[];
extern u8 unk8[];
typedef struct { u8 pad0[8]; f32 f8; f32 fC; u8 pad10[0x18]; s16 f28; u8 pad2A[6]; u8 f30; u8 pad31[0x1F]; } EntryFC9B4;
typedef struct { u8 pad[0x20]; s32 unk20; u8 pad24[0xD]; u8 unk31; u8 pad32[2]; u8 unk34; } S_FCA90;
extern u8 unk2A[];
extern s32 func_80017108(u8);
extern s32 func_80017210(s32);
extern s32 func_800178C4(s32, s32, s32);
typedef struct { f32 field_0, field_4, field_8, field_C; f32 field_10, field_14, field_18, field_1C; s32 field_20, field_24; s16 field_28, field_2A; s32 field_2C; u8 pad_30:4, field_30:4; u8 field_31, field_32, field_33, field_34; u8 pad_35[3]; void *field_38; u8 pad_3C[0x14]; } LocalState_800FCED0;
extern s32 func_80017D74(s32, s32, f32);
void func_800FB908();
void func_800FCB00();
s32 func_800FCB54(s32, s32, s32, f32);
void func_800FCB9C(s32 param_0, s32 param_1, s32 param_2, f32 param_3, s32 param_4);

extern s32 D_80135960[];

int func_800FB540(s32 *param_0)
{
  s32 local_0;
  if (((u8) (*(u8 *)((char *)(param_0) + 51))) == 0)
  {
    func_800FED70(*(s16 *)((char *)param_0 + 0x28));
    *(u8 *)((char *)param_0 + 0x33) = 1;
    for (local_0 = 0; local_0 < 0x30; local_0++)
    {
      if (*(s16 *)((char *)param_0 + 0x28) == D_80123DE0[local_0])
      {
        func_800DA544(local_0 + 0x53E);
        break;
      }
    }
  }
}

int func_800FB5BC(Actor *param_0)
{
    s32 *local_0 = (s32 *)((char *)param_0 + 0x28);
    if ((*(u8 *)((char *)(local_0) + 0xB)) != 0)
    {
        func_800FED90(*(s16 *)((char *)param_0 + 0x28));
        (*(s8 *)((char *)(local_0) + 0xB)) = 0;
    }
}

s32 *func_800FB5F8(param_0) s32 param_0; {
    LocalTrack *music_track;
    LocalTrack *free_music_track;

    free_music_track = NULL;

    for (music_track = (LocalTrack *) D_801357D0; music_track < (LocalTrack *) D_801357D0 + 6; music_track++) {
        if (param_0 == music_track->track) {
            return (s32 *) music_track;
        }

        if (free_music_track == NULL && (s32) music_track->track < 0) {
            free_music_track = music_track;
        }
    }

    return (s32 *) free_music_track;
}

void func_800FB650(S_FB650 *param_0, s32 param_1, s32 param_2) {
    void *sp24;
    R_FB650 *e;
    s32 i;
    freelist_clear(param_0->unk38);
    for (i = 0; i < 5; i++) {
        param_0->unk3C[i] = 0;
    }
    e = freelist_next(&param_0->unk38, &sp24);
    e->unk0 = param_1;
    e->unk4 = param_2;
}

s32 func_800FB6C0(s32 param_0, s32 param_1){
    func_800FB650(param_0, param_1, param_1);
}

void func_800FB6E0(LocalState_800FB6E0 *param_0, s32 param_1)
{
    param_0->field_0 = 0.0f;
    param_0->field_4 = 0.0f;
    param_0->field_8 = D_801359B4;
    param_0->field_C = D_801359B8;
    param_0->field_18 = D_801359B4;
    param_0->field_1C = D_801359B8;
    param_0->field_20 = 0;
    param_0->field_24 = 0;
    param_0->field_28 = (s16)-1;
    param_0->field_2A = 0;
    param_0->field_2C = -1;
    param_0->field_30 = 0;
    param_0->field_31 = 0;
    param_0->field_32 = 0;
    param_0->field_34 = 0;
    param_0->field_10 = (f32)0;
    param_0->field_14 = 1.0f;
    if (param_1 == 0) param_0->field_33 = 0;
}

void func_800FB774(void *param_0)
{
  func_800FB6C0(param_0, func_80017764(*(s16 *)((u8 *)param_0 + 0x28)));
  func_800FB5BC(param_0);
  *(s16 *)((u8 *)param_0 + 0x28) = -1;
  ((u8 *)param_0)[0x30] &= 0xff0f;
  func_80017404((u8)((s32)((u8 *)param_0 - D_801357D0) / 0x50), *(s16 *)((u8 *)param_0 + 0x22));
  func_800FB6E0(param_0, 0);
  func_800172D4((u8)((s32)((u8 *)param_0 - D_801357D0) / 0x50), -1);
}

void func_800FB808(void) {
    local_type_800FB808 *local_0;
    s32 local_1;
    if (D_80123E40) func_800FB908();
    D_80123E40 = 1;
    D_801359B4 = 0;
    D_801359B8 = 1.0f;
    for (local_0 = ((local_type_800FB808 *) D_801357D0); local_0 < &((local_type_800FB808 *) D_801357D0)[6]; local_0++) {
        local_0->local_5 = -1;
        local_0->local_3 = 0;
        local_0->local_6 = 0;
        local_0->local_4 = 0;
        local_0->local_1 = 0.0f;
        local_0->local_8 = 0;
        local_0->local_11 = freelist_new(8, 4);
        func_800FB6E0(local_0, 0);
        for (local_1 = 0; local_1 < 5; local_1++) local_0->local_12[local_1] = 0;
    }
    func_800FE614();
    func_80017864();
}

void func_800FB908()
{
  u8 *local_0;
  func_80017244();
  func_80016E7C();
 local_0 = &D_801357D0[0]; while (1) {
    freelist_free(*((void **)(local_0 + 0x38)));
    local_0 += 0x50;
    *((u32 *) (local_0 - 0x18)) = 0;
    if (local_0 >= (((u8 *) D_801359B0)))
    {
      break;
    }
  }

  ((u8 *) &D_80123E40)[0] = 0;
}

void func_800FB968(void)
{
    s32 local_0;
    LocalTrack *local_1;
    f32 local_2;
    s32 local_3;
    u32 local_4;
    u32 local_5;
    s32 local_6;
    u32 local_7;

    local_2 = func_800D8FF8();
    local_3 = D_801359B1;
    if (func_80090200()) {
        local_3 = func_800A5490();
        D_801359B1 = local_3;
    }
    for (local_1 = ((LocalTrack *) D_801357D0); local_1 < ((LocalTrack *) D_801357D0) + 6; local_1++) {
        if (local_1->track < 0) continue;
        local_1->elapsed = func_800F13F0(local_1->elapsed + local_2, 600.0f);
        if (local_1->elapsed > 1.0f && func_80017778(local_1 - ((LocalTrack *) D_801357D0))) {
            func_800FB774(local_1);
            continue;
        }
        if (local_3) {
            if (local_1->paused_0 != local_1->current_0 || local_1->paused_1 != local_1->current_1) {
            local_1->current_0 += (local_1->paused_0 - local_1->current_0) * 0.05f;
            local_1->current_1 += (local_1->paused_1 - local_1->current_1) * 0.05f;
            func_80017534(local_1 - ((LocalTrack *) D_801357D0), local_1->current_0, local_1->current_1);
            }
        } else {
            if (local_1->normal_0 != local_1->current_0 || local_1->normal_1 != local_1->current_1) {
            local_1->current_0 += (local_1->normal_0 - local_1->current_0) * 0.05f;
            local_1->current_1 += (local_1->normal_1 - local_1->current_1) * 0.05f;
            func_80017534(local_1 - ((LocalTrack *) D_801357D0), local_1->current_0, local_1->current_1);
            }
        }
    }
    func_800175F0();
    func_800FDC58(local_3);
    for (local_1 = ((LocalTrack *) D_801357D0); local_1 < ((LocalTrack *) D_801357D0) + 6; local_1++) {
        if (local_1->track < 0) continue;
        local_0 = local_1 - ((LocalTrack *) D_801357D0);
        func_80017EC0(local_0);
        local_4 = func_800170D4(local_0);
        local_5 = func_80017070(local_0);
        local_6 = func_800177C4(local_0);
        local_4 &= local_5;
        local_7 = local_1->mask & local_5;
        if ((local_6 && local_7) || (!local_6 && !local_4)) {
            if (local_4 || local_7) {
                func_80017404(local_0, (s16)local_1->volume);
                local_1->muted = 0;
            } else {
                func_80017404(local_0, 0);
                local_1->muted = 1;
            }
        }
    }
    if (!((u8 *) D_801359B0)[0]) return;
    ((u8 *) D_801359B0)[0] = 0;
    for (local_1 = ((LocalTrack *) D_801357D0); local_1 < ((LocalTrack *) D_801357D0) + 6; local_1++) {
        if (local_1->track < 0) continue;
        if (local_1->step) {
            if (local_1->delay > 0.0f) {
                local_1->delay -= func_800D8FF8();
                ((u8 *) D_801359B0)[0] = 1;
                continue;
            }
            if (local_1->step < 0) {
                local_1->volume += local_1->step;
                if (local_1->stop_at_zero && !local_1->target && local_1->volume <= 0) {
                    func_800FB774(local_1);
                    continue;
                } else {
                    if (local_1->target >= local_1->volume) {
                        local_1->volume = local_1->target;
                        local_1->step = 0;
                    } else {
                        ((u8 *) D_801359B0)[0] = 1;
                    }
                    if (!local_1->muted) func_80017404(local_1 - ((LocalTrack *) D_801357D0), (s16)local_1->volume);
                }
                continue;
            }
            if (local_1->volume < local_1->target) {
                if (!local_1->volume) local_1->elapsed = 0.0f;
                local_1->volume += local_1->step;
                if (local_1->volume >= local_1->target) {
                    local_1->volume = local_1->target;
                    local_1->step = 0;
                } else {
                    ((u8 *) D_801359B0)[0] = 1;
                }
                if (!local_1->muted) func_80017404(local_1 - ((LocalTrack *) D_801357D0), (s16)local_1->volume);
                continue;
            }
            local_1->step = 0;
        }
    }
}

void func_800FBEC8(s32 param_0, u32 *param_1, u32 *param_2) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 *local_5;

    local_0 = freelist_capacity(*(s32 **)((char *)param_0 + 0x38));
    local_3 = 0x7FFF;
    local_4 = 0x40000000;
    local_2 = 1;
    if (local_0 >= 2) {
        do {
            if ((freelist_is_element_alive(*(s32 **)((char *)param_0 + 0x38), local_2) != 0) && ((local_5 = freelist_at(*(s32 **)((char *)param_0 + 0x38), local_2), local_1 = *(s32 *)((char *)local_5 + 0), (local_1 < local_3)) || ((local_3 == local_1) && (*(s32 *)((char *)local_5 + 4) < local_4)))) {
                local_3 = local_1;
                local_4 = *(s32 *)((char *)local_5 + 4);
            }
            local_2 += 1;
        } while (local_2 < local_0);
    }
    *param_1 = local_3;
    *param_2 = local_4;
}

void func_800FBF9C(LocalState_800FBF9C *param_0, s32 *param_1, s32 *param_2, s32 *param_3)
{
    s32 local_0;
    LocalEntry *local_2;
    s32 local_1;
    LocalEntry *local_3;
    local_0 = *param_1;
    local_1 = *param_2;
    if (*param_3 != 0 && !freelist_is_element_alive(param_0->field_38, *param_3)) {
        *param_3 = 0;
    }
    if (local_0 < 0) {
        local_2 = freelist_at(param_0->field_38, 1);
        local_0 = local_2->field_0 < func_80017764(param_0->field_28) ? func_80017764(param_0->field_28) : local_2->field_0;
        if (*param_3 != 0) {
            *param_2 = ((LocalEntry *) freelist_at(param_0->field_38, *param_3))->field_4;
            freelist_erase(param_0->field_38, *param_3);
            *param_3 = 0;
            func_800FBEC8(param_0, param_1, &local_1);
            return;
        }
    }
    if (*param_3 == 0) {
        local_3 = freelist_at(param_0->field_38, 1);
        if (local_3->field_0 < local_0 || (local_0 == local_3->field_0 && local_1 >= local_3->field_4)) {
            func_800FB650(param_0, local_0, local_1);
        } else {
            freelist_next(&param_0->field_38, param_3);
        }
    }
    if (*param_3 != 0) {
        local_3 = freelist_at(param_0->field_38, *param_3);
        local_3->field_0 = local_0;
        local_3->field_4 = local_1;
    }
    func_800FBEC8(param_0, param_1, param_2);
}

void func_800FC124(u32 param_0)
{
  s32 local_0;
  if (param_0 != (*((s16 *) (((char *) (&D_80135988)) + 0))))
  {
    func_800FB6E0(&D_80135960, 0);
    func_800172D4(5, param_0);
    *((s16 *) (((char *) (&D_80135988)) + 0)) = (s16) param_0;
    local_0 = func_80017764(param_0);
 if (1) { }
    *((s32 *) (((char *) (&D_80135980)) + 0)) = local_0;
    *((s16 *) (((char *) (&D_8013598A)) + 0)) = 0;
    *((f32 *) (((char *) (&D_80135964)) + 0)) = 0.0f;
    func_800FB6C0(&D_80135960, local_0);
  }
}

void func_800FC1A8()
{
    func_800FB774(&D_80135960);
}

void func_800FC1CC(s32 param_0, s32 param_1)
{
    s32 i;
    for (i = 0; i < 5; i++) {
        if (((LocalState_800FC1CC *) D_801357D0)[i].field_28 >= 0) {
            func_800FCB00(((LocalState_800FC1CC *) D_801357D0)[i].field_28, param_0, param_1, 1);
        }
    }
}

void func_800FC240(s32 param_0, s32 param_1)
{
  s16 *new_var;
 do { s32 *var_s0 = (s32 *) (((int *) D_801357D0)); do { s16 temp_a0 = *((s16 *) (((char *) var_s0) + 0x28)); if ((temp_a0 >= 0) && (func_800FE7A8(temp_a0) == 0)) { new_var = &(*((s16 *) (((char *) var_s0) + 0x28))); func_800FCB00(*new_var, param_0, param_1, 1); } var_s0 += 0x50 / (sizeof(s32)); } while (var_s0 != ((s32 *) (((int *) D_80135960)))); } while (0);
}

void func_800FC2C4(s32 param_0, s32 param_1)
{
  u8 *new_var;
  u8 *local_0;
 do { new_var = ((s32 *) D_80135960); local_0 = ((s32 *) D_801357D0); } while (0);
  do
  {
    s16 local_1;
    local_1 = *((s16 *) (((s8 *) local_0) + 0x28));
    if ((((short) local_1) >= 0) && ((((u32) (*((u32 *) (((s8 *) local_0) + 0x30)))) >> 0x1C) == 0))
    {
      func_800FCB00(local_1, param_0, param_1, 1);
    }
    local_0 += 0x50;
  }
  while (local_0 != new_var);
}

void func_800FC348(u32 param_0, u32 param_1, u32 param_2)
{
  u8 *local_0;
  u8 *local_1;
 local_0 = ((u8 *) D_801357D0); local_1 = ((u8 *) D_801357D0); do {
    if (((*((s16 *) (((char *) local_1) + 0x28))) >= 0) && (!func_800FE7A8(*((s16 *) (((char *) local_1) + 0x28)))))
    {
      func_800FCB00(*((s16 *) (((char *) local_1) + 0x28)), param_0, param_1, param_2);
    }
    local_1 += 0x50;
  }
  while (local_1 != ((u8 *) (&D_80135960)));
}

int func_800FC3D8(s32 param_0, s32 param_1, s32 param_2, f32 param_3)
{
  unsigned int new_var2;
  int new_var;
  s32 local_0;
  if (param_3 == 0.0f)
  {
    return 0x7FFF;
  }
  if (param_2 == (-1))
  {
    new_var = 0;
    param_2 = func_80017764(param_0) | new_var;
  }
  if (param_1 == param_2)
  {
    return 1;
  }
  if (param_3 == 0.0f)
  {
    local_0 = param_1 - param_2;
  }
  else
  {
    local_0 = ((param_1 - param_2) / (param_3 * 30.0f)) + 1.0f;
    if (local_0 < 0)
    {
      local_0 = -local_0;
    }
    else
      if (local_0 == 0)
    {
      local_0 = 1;
    }
  }
  return local_0;
}

s32 func_800FC4B0(s32 param_0, s32 param_1, s32 param_2, f32 param_3) {
    s32 var_a1;
    u8 *temp_v0;

    param_1 = param_1;
    if (param_1 == -1) {
        temp_v0 = func_800FB5F8();
        if (temp_v0 == NULL) {
            return 0;
        }
        param_1 = (*(s32 *)((u8 *)temp_v0 + 0x20));
        goto block_4;
    }
block_4:
    return func_800FC3D8(param_0, param_1, param_2, param_3);
}

void func_800FC508(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    local_type_800FC508 *local_0;
    if (param_1 == -1) param_1 = func_80017764();
    if (param_3 == -1) param_3 = param_1;
    local_0 = func_800FB5F8(param_0);
    if (local_0) {
        if (local_0->local_5 < 0 || param_2 != 0) {
            func_800FB6E0(local_0, param_2);
            local_0->local_5 = param_0;
            local_0->local_6 = 0;
            local_0->local_8 = 0;
            local_0->local_1 = 0.0f;
            func_800FB6C0(local_0, param_3);
            func_800172D4((u8)(local_0 - ((local_type_800FC508 *) D_801357D0)), param_0);
        }
        if (!local_0->local_10) func_80017404((u8)(local_0 - ((local_type_800FC508 *) D_801357D0)), (s16)param_1);
        local_0->local_3 = param_1;
        func_800FB540(local_0);
    }
}

int func_800FC618(s32 p0, s32 p1)
{
  func_800FC508(p0, p1, 0, -1);
}

void func_800FC63C(u32 param_0, u32 param_1) {
    func_800FC508(param_0, param_1, 1, -1);
}

void func_800FC660(u32 param_0) {
  func_800FC508(param_0, -1, 1, -1);
}

int func_800FC688(s32 param_0, s32 param_1)
{
  func_800FC508(param_0, 1, 1, param_1 | 0);
}

void func_800FC6B0(u32 param_0)
{
  u32 local_0;
  u32 local_1;
  local_1 = func_800FB5F8();
  if (local_1 != 0)
  {
    if ((*((s16 *) (((char *) local_1) + 0x28))) < 0)
    {
      func_800FB6E0(local_1, 0);
      *((s16 *) (((char *) local_1) + 0x2A)) = 0;
      *((s16 *) (((char *) local_1) + 0x28)) = (s16) param_0;
      if (1)
      {
        *((f32 *) (((char *) local_1) + 0x4)) = 0.0f;
        func_800172D4((((s32) (local_1 - ((u32) (((u8 *) D_801357D0))))) / 80), param_0);
        local_0 = func_80017764(param_0);
      }
      *((u32 *) (((0, (char *) local_1)) + 0x20)) = local_0;
      func_800FB6C0(local_1, local_0);
    }
    func_800FB540(local_1);
  }
}

void func_800FC74C(u32 param_0)
{
  void *local_0;
  local_0 = func_800FB5F8(param_0);
  if (local_0 != 0)
  {
    if ((*((s16 *) (((u8 *) local_0) + 0x28))) >= 0)
    {
      func_800FB774(local_0);
    }
  }
}

void func_800FC788(s32 param_0, s32 param_1)
{
  local_2 *local_0;
  local_0 = func_800FB5F8(param_0);
  if (local_0 != 0)
  {
    local_0->local_0 = param_1;
  }
}

void func_800FC7C4()
{
  int new_var;
  u8 *s0;
  u8 *s1;
  s0 = (u8 *) (&D_801357D0);
 s0 = (u8 *) (&D_801357D0); s1 = (u8 *) (&D_801359B0);
  do
  {
    ;
    if ((*((s16 *) (s0 + 0x28))) >= 0)
    {
      func_800FB774(s0);
    }
    s0 += 0x50;
  }
  while (s0 < s1);
}

void func_800FC81C()
{
  u8 *local_0;
 local_0 = &D_801357D0; do {
    if ((((s16) (*((s16 *) (local_0 + 0x28)))) >= 0) && (func_800FE7A8(*((s16 *) (local_0 + 0x28))) == 0))
    {
      func_800FB774(local_0);
    }
    local_0 += 0x50;
  }
  while (((u32) local_0) < ((u32) (&D_801359B0)));
}

void func_800FC884(void)
{
  u8 *local_0;
 local_0 = &D_801357D0; do {
    if ((((s16) (*((s16 *) (local_0 + 0x28)))) >= 0) && ((((u32 *) (local_0 + 0x30))[0] >> 0x1C) == 0))
    {
      func_800FB774(local_0);
    }
    local_0 += 0x50;
  }
  while (((u32) local_0) < ((u32) (((u8 *) D_801359B0))));
}

int func_800FC8EC()
{
  Actor *local_0 = func_800FB5F8();
  if (local_0 != NULL)
  {
    (*(f32 *)((char *)(local_0) + 0xC)) = 1.0f;
    (*(f32 *)((char *)(local_0) + 0x14)) = 1.0f;
    (*(f32 *)((char *)(local_0) + 0x8)) = 0.0f;
    (*(f32 *)((char *)(local_0) + 0x10)) = 0.25f;
  }
}

void func_800FC934(s32 param_0, f32 param_1, f32 param_2)
{
  s32 local_0;
  Actor *local_1;
  Actor *new_var;
  char new_var2;
  new_var = func_800FB5F8(param_0);
  local_1 = new_var;
  if (local_1 != 0)
  {
    new_var2 = 0xFFFFFFFFFFFFFFFFu;
    *((f32 *) (((u8 *) local_1) + 8)) = param_1;
    *((f32 *) (((u8 *) local_1) + 12)) = param_2;
    local_0 = 1;
    local_0 = (((*((u8 *) (((u8 *) local_1) + 48))) & new_var2) & 0xFFF0) | local_0;
    *((u8 *) (((u8 *) local_1) + 48)) = local_0;
    local_0++;
    local_0--;
  }
}

void func_800FC97C(void *param_0, f32 param_1, f32 param_2) {
    void *temp = func_800FB5F8(param_0);
    if (temp) {
        *(f32 *)((u8 *)temp + 0x10) = param_1;
        *(f32 *)((u8 *)temp + 0x14) = param_2;
    }
}

void func_800FC9B4(s32 param_0, f32 param_1) {
    s32 local_0;

    if (param_0 != 0) {
        D_801359B4 = param_1;
        D_801359B8 = 1.0f;
    } else {
        D_801359B4 = 0.0f;
        D_801359B8 = 1.0f;
    }
    for (local_0 = 0; local_0 < 5; local_0++) {
        if (((EntryFC9B4 *) D_801357D0)[local_0].f28 >= 0 && func_800FE7A8(((EntryFC9B4 *) D_801357D0)[local_0].f28) == 0 && !(((EntryFC9B4 *) D_801357D0)[local_0].f30 & 0xF)) {
            ((EntryFC9B4 *) D_801357D0)[local_0].f8 = D_801359B4;
            ((EntryFC9B4 *) D_801357D0)[local_0].fC = D_801359B8;
        }
    }
}

void func_800FCA90(u32 param_0) {
    S_FCA90 *p = func_800FB5F8(param_0);
    if (p != 0) {
        p->unk31 = 1;
        if ((p->unk20 == 0) || (p->unk34 != 0)) { func_800FB774(p); }
    }
}

void func_800FCAE0(u32 param_0, u32 param_1, u32 param_2)
{
  func_800FCB54(param_0, param_1, param_2, 0);
}

void func_800FCB00(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s32 param_3; {
    func_800FCB9C(param_0, param_1, param_2, 0, (s32)func_800FB5F8() + (param_3 * 4) + 0x3C);
}

s32 func_800FCB54(s32 param_0, s32 param_1, s32 param_2, f32 param_3)
{
  s32 local_0 = func_800FB5F8();
  func_800FCB9C(param_0, param_1, param_2, 0, local_0 + 0x3C);
}

void func_800FCB9C(s32 param_0, s32 param_1, s32 param_2, f32 param_3, s32 param_4)
{
  u8 sp24;
  u8 *temp_v0;
  temp_v0 = func_800FB5F8();
  if (temp_v0 != 0)
  {
    if ((*((s16 *) (((s8 *) temp_v0) + 0x28))) < 0)
    {
      if (param_1 != 0)
      {
        func_800FB6E0(temp_v0, 0);
        sp24 = (((s32) (((u8 *) temp_v0) - ((u8 *) (((u8 *) D_801357D0))))) / 80);
        func_800172D4(sp24, param_0);
        *((s16 *) (((s8 *) temp_v0) + 0x28)) = (s16) param_0;
        *((s32 *) (((s8 *) temp_v0) + 0x20)) = 0;
        *((f32 *) (((s8 *) temp_v0) + 4)) = 0.0f;
        func_800FB6C0(temp_v0, 0);
        if ((*((u8 *) (((s8 *) temp_v0) + 0x34))) == 0)
        {
          func_80017404((u8) sp24, 0);
        }
        goto block_5;
      }
    }
    else
    {
      block_5:
      func_800FBF9C(temp_v0, &param_1, &param_2, param_4);

      *((f32 *) (((s8 *) temp_v0) + 0)) = param_3;
      if ((*((s32 *) (((s8 *) temp_v0) + 0x20))) < param_1)
      {
        *((s16 *) (((s8 *) temp_v0) + 0x2A)) = (s16) param_2;
      }
      else
      {
        *((s16 *) (((s8 *) temp_v0) + 0x2A)) = (s16) (-param_2);
      }
      *((s32 *) (((s8 *) temp_v0) + 0x24)) = param_1;
      if (param_1 != 0)
      {
        func_800FB540(temp_v0);
      }
      else
      {
        func_800FB5BC(temp_v0);
      }
      (*((u8 *) D_801359B0)) = 1;
    }
  }
}

s32 func_800FCCD4(s32 param_0)
{
    s32 *local_1;
    s32 local_0;
    local_1 = func_800FB5F8(param_0);
    if (local_1 == NULL || *(s16 *)((char *)local_1 + 0x28) == -1) {
        local_0 = 0;
    } else {
        local_0 = 1;
    }
    return local_0;
}

void func_800FCD14(s32 param_0, s32 param_1)
{
    s32 local_0;
    local_0 = func_800FB5F8(param_0);
    if (local_0 != 0)
    {
        local_0 -= (s32)&((s32 *) D_801357D0)[0];
        local_0 /= 0x50;
        local_0 &= 0xFF;
        func_800174C0(local_0, param_1);
    }
}

void func_800FCD5C(void)
{
  s8 *var_s0;
  s32 temp_v0;
 if (D_80123E40 != 0) { var_s0 = (s8 *) (((s32 *) D_801357D0)); do {
      temp_v0 = freelist_defrag(*((s32 *) (var_s0 + 0x38)));
      var_s0 += 0x50;
      *((s32 *) (var_s0 - 0x18)) = temp_v0;
    }
    while (((u32) var_s0) < ((u32) (((s32 *) D_801359B0))));
  }
}

int func_800FCDB4()
{
  Actor *local_0;
  local_0 = func_800FB5F8();
  if (local_0 != NULL)
  {
    return (*(s32 *)((char *)(local_0) + 0x2C));
  }
  return 0;
}

s32 func_800FCDE0(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  void *local_1;
  local_1 = func_800FB5F8();
  if (!local_1) { return 0; }
  if (((u8 *) local_1)[50] != 0 && ((s32 *) local_1)[11] == param_1)
  {
    return 1;
  }
  local_0 = (((s32) local_1) - ((s32) ((s32 *) D_801357D0))) / 0x50;
  if (func_80017108((u8)local_0) == param_0)
  {
    if (func_80017210((u8)local_0) == 1 || func_800177C4(local_0))
    {
      if (func_800178C4(local_0, param_1, param_2))
      {
        ((s32 *) local_1)[11] = param_1;
        ((u8 *) local_1)[50] = 1;
        return 1;
      }
    }
  }
  ((s32 *) local_1)[11] = param_1;
  ((u8 *) local_1)[50] = 0;
  return 0;
}

int func_800FCED0(s32 param_0, s32 param_1, f32 param_2)
{
    LocalState_800FCED0 *p;
    p = func_800FB5F8();
    if (p != NULL) {
        if (func_80017108(p - ((LocalState_800FCED0 *) D_801357D0)) != param_0) return 0;
        return func_80017D74(p - ((LocalState_800FCED0 *) D_801357D0), param_1, param_2);
    }
    return 0;
}

int func_800FCF50(int param_0)
{
  s32 local_0;
  for (local_0 = 0; local_0 < 0x30; local_0++)
  {
    if (param_0 == ((s16 *) D_80123DE0)[local_0])
    {
      return func_800DA298(local_0 + 0x53E);
    }
  }

  return 1;
}
