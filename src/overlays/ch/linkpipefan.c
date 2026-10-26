#include "common.h"

extern s32 D_8080091C_chlinkpipefan;
extern s32 D_80800960_chlinkpipefan;
extern s32 D_80800994_chlinkpipefan;
extern s32 D_808009A0_chlinkpipefan;
extern f32 func_800F13C4(f32, f32);
extern void func_800DA544(s32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void _chskeletonexplode_entrypoint_7(Actor *, f32 *);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern s32 D_808009AC_chlinkpipefan;
extern s32 D_808009B8_chlinkpipefan;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef union { Unk80132ED0 *marker; s32 word; } Mass63FanEvent;
extern int D_808009C8_chlinkpipefan;
extern u8 D_80800910_chlinkpipefan[];
extern void _chlinkpipefan_entrypoint_0(void);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 func_800DC178(f32, f32);
extern s32 func_800D91EC(f32 *, f32);
extern s32 func_800D90F8(f32 *, f32);
extern void func_800C4208(s32, f32, s32, f32 *, f32, f32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);

void func_80800000_chlinkpipefan(u8 *param_0)
{
  u32 temp_t6;
  u32 var_v0;
  int new_var;
  temp_t6 = (var_v0 = ((u32) (*((u16 *) (((u8 *) param_0) + 0x76)))) >> 7);
  if ((((s32) temp_t6) < 0x33) || (((s32) temp_t6) >= 0x3A))
  {
    func_800FFA88(*((s32 *) (((u8 *) param_0) + 0)));
    new_var = 7;
 if (0) { }
    var_v0 = ((u32) (*((u16 *) (((u8 *) param_0) + 0x76)))) >> new_var;
  }
  if (func_800DA298(var_v0 + 0x15C) != 0)
  {
    func_800FFA88(*((s32 *) (((u8 *) param_0) + 0)));
  }
  *((f32 *) (((u8 *) param_0) + 0x34)) = 1.5f;
}

void func_808003B4_chlinkpipefan();

void func_80800080_chlinkpipefan(Actor *param_0)
{
    s32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;

    local_0 = param_0->unk70_10;
    switch (local_0) {
    case 1:
        param_0->rotation[2] = func_800F1FF0(param_0->rotation[2], 0.0f, 0.1f, 0.1f, 3.0f);
        break;
    case 2:
        if (func_800D91EC((f32 *)&param_0->actorData[7], 1.5f)) {
            param_0->unk54 = 450.0f;
        } else {
            param_0->unk54 = func_800F10B4(*(f32 *)&param_0->actorData[7], 1.5f, 0, 450.0f, 0);
        }
        break;
    case 3:
        if (func_800D90F8((f32 *)&param_0->actorData[7], 0.75f)) {
            if (func_800D90A4(&param_0->unk58)) {
                func_808003B4_chlinkpipefan(param_0, 2);
            }
        } else {
            param_0->unk54 = func_800F10B4(*(f32 *)&param_0->actorData[7], 1.5f, 0, 450.0f, 0);
        }
        break;
    case 4:
        if (func_800D90A4((f32 *)&param_0->actorData[7])) {
            param_0->unk54 = 0.0f;
            if (func_800D90A4(&param_0->unk58)) {
                func_808003B4_chlinkpipefan(param_0, 2);
            }
        } else {
            param_0->unk54 = func_800F10B4(*(f32 *)&param_0->actorData[7], 1.5f, 0, 450.0f, 0);
        }
        break;
    }
    ((f32 *)param_0->actorData)[3] = param_0->rotation[2];
    param_0->rotation[2] = func_800136E4(param_0->rotation[2] + func_800D8FF8() * param_0->unk54);
    local_1 = func_800F13C4(((f32 *)param_0->actorData)[3], 90.0f); if (func_800F13C4(param_0->rotation[2], 90.0f) < local_1 && param_0->unk54 > 225.0f) {
        local_2 = func_800F10B4(param_0->unk54, 225.0f, 450.0f, 0.3f, 0.6f); func_800C4208(0x3FF, func_800DC178(-0.05f, 0.05f) + local_2, 0x4A38, param_0->position, 200.0f, 1500.0f);
    }
    if (param_0->unk54 != 0.0f) {
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800910_chlinkpipefan);
        _subaddieaudioloop_entrypoint_0(param_0, func_800F10B4(param_0->unk54, 225.0f, 450.0f, 0.4f, 0.8f));
    }
    if (param_0->unk6C_0) {
        param_0->unk6C_0--;
    }
    if (func_801065A4(param_0)) {
        _glid_entrypoint_0(func_801065A4(param_0), 1, _chlinkpipefan_entrypoint_0, param_0->unk0);
    }
    func_8010A654(param_0, param_0->unk70_10 == 4);
}

void func_808003B4_chlinkpipefan(Actor *param_0, u32 param_1)
{
    f32 *local_0;

    switch (param_1) {
        case 1:
            param_0->rotation[2] = func_800F13C4(param_0->rotation[2], 90.0f);
            if (param_0->rotation[2] > 45.0f) param_0->rotation[2] = 90.0f - param_0->rotation[2];
            func_800DA544(param_0->unk74_7 + 0x15C);
            local_0 = param_0->position;
            func_800BBCB8(local_0, local_0, 1.0f, 4, &D_8080091C_chlinkpipefan);
            func_800BBCB8(local_0, local_0, 1.0f, 10, &D_80800960_chlinkpipefan);
            _subaddieaudioquick_entrypoint_2(param_0, local_0, &D_80800994_chlinkpipefan);
            _chskeletonexplode_entrypoint_7(param_0, local_0);
            return;
        case 2:
            func_80101FDC(param_0, param_1);
            return;
        case 3:
            func_80101FDC(param_0, param_1);
            param_0->unk58 = 5.0f;
            return;
        case 4:
            param_0->unk58 = 5.0f;
            if (param_0->unk70_10 != 4) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_808009A0_chlinkpipefan);
                func_80101FDC(param_0, param_1);
            }
            return;
    }
}

void chlinkpipefan_entrypoint_0(void *param_0, void *param_1, u8 (*param_2)[16], s32 param_3, Unk80132ED0 *param_4)
{
    f32 local_0;
    u8 (*local_1)[16];
    u8 local_2;

    local_0 = func_800F12D4(func_80106790(param_4)->unk54, 225.0f, 450.0f, 0.0f, 255.0f);
    local_1 = param_2 + param_3;
    if (param_2 < local_1) {
        local_2 = (u8)(u32)local_0;
        do {
            (*param_2)[15] = local_2;
            param_2++;
        } while (param_2 < local_1);
    }
}

s32 func_80800638_chlinkpipefan(Actor *param_0, s32 param_1, Mass63FanEvent param_2)
{
    Actor *local_0;
    s32 local_1;
    s32 k = 15; /* comparison value as a local: IDO then puts the constant register (shared with case 0xF) on the left of bne */

    switch (param_1) {
    case 0x3E:
        if (param_0->unk70_10 != 4) {
            local_1 = (*(u32 *)((u8 *)param_0->unk0 + 0x18) << 11) >> 28;
            if (k == local_1) {
                func_800F79DC(func_800F54E4(), 6, param_0->unk0);
            } else if (local_1 == 1) {
                func_800F79DC(func_800F54E4(), 3, param_0->unk0);
            }
        }
        return 1;
    case 0x3F:
        if (func_80106790(param_2.marker)->unk6C_9 == 0x15C) {
            func_808003B4_chlinkpipefan(param_0, 4);
        } else if (((*(u32 *)((u8 *)param_0->unk0 + 0x18) << 11) >> 28) == 1 && param_0->unk70_10 != 4) {
            func_808003B4_chlinkpipefan(param_0, 3);
        }
        if (!param_0->unk6C_0) {
            if (param_0->unk70_10 == 4) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_808009B8_chlinkpipefan);
            } else {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_808009AC_chlinkpipefan);
            }
        }
        param_0->unk6C_0 = 8;
        return 1;
    case 0x40:
        if (param_0->unk70_10 == 4 && param_0->unk54 <= 45.0f) {
            func_808003B4_chlinkpipefan(param_0, 1);
        }
        return 1;
    case 0x1F:
        func_801015D0(param_0);
        func_800DF6BC((s32)func_800F10B4(param_0->unk54, 0.0f, 225.0f, 255.0f, 0.0f), 255);
        func_800DF744(1, 1);
        return 1;
    case 0xF:
        local_0 = func_80106790(func_80101080());
        _chskeletonexplode_entrypoint_3(local_0, 1, 0);
        _chskeletonexplode_entrypoint_4(local_0, 7);
        _chskeletonexplode_entrypoint_5(local_0, (s32)func_800F10B4(param_0->unk54, 0.0f, 225.0f, 255.0f, 0.0f));
        func_800FFA88(param_0->unk0);
        return 1;
    default:
        return 0;
    }
}

int chlinkpipefan_entrypoint_1()
{
    return (int)&D_808009C8_chlinkpipefan;
}
