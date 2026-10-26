#include "common.h"
#include "overlays/ba/playerstate.h"

extern void *func_800A4C68(void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
typedef struct { u8 pad_0[0x10]; u8 local_0; u8 local_1; u8 local_2; u8 local_3; } EggFireQueue;
typedef struct { u8 pad_0[0x6C]; EggFireQueue *local_0; } EggFirePlayer;
extern void _baeggfire_entrypoint_1(s32);
extern void _baeggfire_entrypoint_2(s32);
extern void func_800C9DE4(f32, void (*)(s32), s32);
typedef struct { f32 local_0; s32 local_1; s32 local_2; s32 local_3; u8 local_4; } EggFireState;
typedef struct { u8 pad_0[0x6C]; EggFireState *local_0; } EggFireModePlayer;
void func_808000B8_baeggfire();
void func_80800180_baeggfire();
void func_80800250_baeggfire();

s32 baeggfire_entrypoint_0() 
{
    return 0x14;
}

void func_80800008_baeggfire(param_0, param_1) Actor *param_0; s32 param_1; {
    u8 *local_0;

    if (param_1 == 1) {
        local_0 = *(u8 **)((char *)param_0 + 0x6C);
        *(u8 *)((char *)local_0 + 0x12) = *(u8 *)((char *)local_0 + 0x12) + 1;
        return;
    }
    local_0 = *(u8 **)((char *)param_0 + 0x6C);
    *(u8 *)((char *)local_0 + 0x11) = *(u8 *)((char *)local_0 + 0x11) + 1;
}

void func_80800040_baeggfire(u8 *param_0) {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x6C)))) + (0x12))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x6C)))) + (0x11))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x6C)))) + (0x13))) = 0;
}

void baeggfire_entrypoint_1()
{
  s32 local_4 = func_800F53D0();
  s32 local_8 = (((((*((s32 *) (local_4 + 0x6C))) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
  *((u8 *) (local_8 + 0x13)) = 0;
  func_80800008_baeggfire(local_4, 0);
}

void baeggfire_entrypoint_2(void) {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(func_800F53D0()) + (0x6C)))) + (0x13))) = 0;
}

void func_808000B8_baeggfire(param_0) PlayerState *param_0;
{
    EggFireQueue *local_0;

    local_0 = ((EggFirePlayer *)param_0)->local_0;
    if (!local_0->local_3) {
        if (local_0->local_2) {
            func_800C9DE4(0.25f, _baeggfire_entrypoint_1, param_0->unk184);
            ((EggFirePlayer *)param_0)->local_0->local_3 = 1;
            _baeggsetup_entrypoint_10(param_0);
            ((EggFirePlayer *)param_0)->local_0->local_2--;
        } else if (local_0->local_1) {
            func_800C9DE4(0.17f, _baeggfire_entrypoint_2, param_0->unk184);
            ((EggFirePlayer *)param_0)->local_0->local_3 = 1;
            _baeggsetup_entrypoint_8(param_0, ((EggFirePlayer *)param_0)->local_0->local_0);
            ((EggFirePlayer *)param_0)->local_0->local_1--;
        }
    }
}

void func_80800180_baeggfire(param_0, param_1) EggFireModePlayer *param_0; s32 param_1;
{
    param_0->local_0->local_2 = param_1;
    switch (param_1) {
    case 1:
        param_0->local_0->local_0 = 0.0f;
        param_0->local_0->local_1 = 0;
        param_0->local_0->local_3 = 0;
        break;
    case 2:
        if (func_800944F8(param_0, param_0->local_0->local_4)) param_0->local_0->local_0 = 0.15f;
        else param_0->local_0->local_0 = 0.28f;
        break;
    case 3:
        param_0->local_0->local_0 = 0.2f;
        break;
    case 4:
        param_0->local_0->local_0 = 0.5f;
        break;
    }
}

void baeggfire_entrypoint_3();

void func_80800250_baeggfire(param_0) PlayerState *param_0;
{
    f32 local_5;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_4;
    s32 local_3;
    local_3 = func_800944F8(param_0, ((u8 *)(*(void **)((u8 *)param_0 + 0x6C)))[0x10]);
    if (!*(s32 *)((u8 *)(*(void **)((u8 *)param_0 + 0x6C)) + 4)) ((u8 *)(*(void **)((u8 *)param_0 + 0x6C)))[0x10] = func_80094510(param_0);
    local_4 = func_800944E0(param_0, ((u8 *)(*(void **)((u8 *)param_0 + 0x6C)))[0x10]);
    if (!*(s32 *)((u8 *)(*(void **)((u8 *)param_0 + 0x6C)) + 4)) {
        func_80800008_baeggfire(param_0, 1, local_4);
        if (local_4 == 1) func_80800180_baeggfire(param_0, 4);
        else func_80800180_baeggfire(param_0, 2);
    } else if (local_3 || *(s32 *)((u8 *)(*(void **)((u8 *)param_0 + 0x6C)) + 4) < local_4 - 1) {
        func_80800008_baeggfire(param_0, 0, local_4);
        func_80800180_baeggfire(param_0, 2);
    } else {
        func_80800008_baeggfire(param_0, 0, local_4);
        func_80800180_baeggfire(param_0, 4);
    }
    if (local_3) *(s32 *)((u8 *)(*(void **)((u8 *)param_0 + 0x6C)) + 4) = 1;
    else (*(s32 *)((u8 *)(*(void **)((u8 *)param_0 + 0x6C)) + 4))++;
    *(s32 *)((u8 *)(*(void **)((u8 *)param_0 + 0x6C)) + 0xC) = 0;
    baeggfire_entrypoint_3(param_0, local_0, local_1);
    func_800EF368(local_1, 100.0f);
    func_800EE780(local_2, local_0, local_1);
    if (((u8 *)(*(void **)((u8 *)param_0 + 0x6C)))[0x10] == 7) local_5 = 5000.0f;
    else local_5 = 3000.0f;
    func_800EF368(local_1, local_5);
    _baeggsetup_entrypoint_6(param_0, ((u8 *)(*(void **)((u8 *)param_0 + 0x6C)))[0x10], local_0, local_2, local_1);
    _baeggcursor_entrypoint_8(param_0);
    func_800C6DA0(0x43);
}

void baeggfire_entrypoint_3(void *param_0, f32 param_1[3], f32 param_2[3])
{
    f32 local_0[2];
    f32 local_1[2];
    f32 local_2[3];
    f32 local_3[3];

    if (_baeggcursor_entrypoint_2(param_0) != 1) _baeggcursor_entrypoint_3(param_0, &local_0[0], &local_0[1]);
    else {
        local_0[0] = 152.0f;
        local_0[1] = 114.0f;
    }
    func_800C5008(func_800A4C68(param_0), local_0, local_1);
    func_800EFA4C(local_3, local_1[0], local_1[1], 100.0f);
    func_800C4E58(func_800A4C68(param_0), local_3, local_2);
    func_800A4CE8(param_0, param_1);
    func_800EFB24(param_2, local_2, param_1);
    func_800EF368(param_2, 1.0f);
}

void baeggfire_entrypoint_4(s32 arg0)
{
    func_8009E0AC(arg0,1);
}

void baeggfire_entrypoint_5(u8 *param_0) {
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x6C)))) + (0))) = 0.0f;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x6C)))) + (0xC))) = 0;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x6C)))) + (8))) = 0;
    func_80800180_baeggfire(param_0, 1);
    func_8009E0AC(param_0, 0);
    func_80800040_baeggfire(param_0);
}

void baeggfire_entrypoint_6(PlayerState *param_0)
{
    func_808000B8_baeggfire(param_0);
    switch (*(s32 *)(*(u8 **)((u8 *)param_0 + 0x6C) + 8)) {
        case 1:
            if (*(s32 *)(*(u8 **)((u8 *)param_0 + 0x6C) + 0xC)) {
                func_80800250_baeggfire(param_0);
            }
            break;
        case 2:
            if (func_800D9078(*(void **)((u8 *)param_0 + 0x6C))) {
                func_80800180_baeggfire(param_0, 3);
            }
            break;
        case 3:
            if (func_800D9078(*(void **)((u8 *)param_0 + 0x6C))) {
                func_80800180_baeggfire(param_0, 1);
            }
            if (*(s32 *)(*(u8 **)((u8 *)param_0 + 0x6C) + 0xC)) {
                func_80800250_baeggfire(param_0);
            }
            break;
        case 4:
            if (func_800D9078(*(void **)((u8 *)param_0 + 0x6C))) {
                func_80800180_baeggfire(param_0, 1);
            }
            break;
    }
}

void baeggfire_entrypoint_7(void *param_0)
{
  void *local_0;
  char *new_var;
  new_var = ((char *) param_0) + 0x6C;
  if ((!(*((void **) new_var))) && (!(*((void **) new_var))))
  {
  }
  *((u32 *) (((char *) (*((void **) new_var))) + 0xC)) = 1;
}

int baeggfire_entrypoint_8(void *param_0)
{
  return ((*((int **) (((char *) param_0) + 108)))[0x8 / 4] < 2) ^ 0x1;
}
