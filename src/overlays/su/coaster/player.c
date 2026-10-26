#include "common.h"

typedef struct { u8 pad_0[0xE]; s16 local_0; } CoasterPlayerTarget;
extern void *func_80100094(Actor *, u32);
extern f32 func_80107C00(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F2094(f32, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void _sucoaster_entrypoint_6(Actor *, f32);
typedef struct { u8 pad_0[0xC]; s16 local_0; s16 local_1; u8 pad_1[8]; u32 local_2 : 4; u32 pad_2 : 6; u32 local_3 : 1; u32 pad_3 : 21; } CoasterPlayerState441;
typedef struct { u8 pad_0[0x64]; u32 pad_1:3; u32 local_0:2; u32 pad_2:27; } CoasterController441;




































s32 sucoasterplayer_entrypoint_2(Actor *param_0, f32 param_1);

extern void _sucoaster_entrypoint_11(Actor *, f32);
extern void _subaddiefade_entrypoint_3();
extern s32 func_800DC298(f32);

void sucoasterplayer_entrypoint_0(Actor *param_0)
{
    CoasterPlayerState441 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 2:
        if (!func_8080076C_sucoasterplayer(param_0, local_0)) {
            if (sucoasterplayer_entrypoint_3(param_0)) {
                if ((f32)_sucoasterdata_entrypoint_2(local_0->local_2) * ((f32)local_0->local_0 * 0.00390625f) <= (f32)local_0->local_1) {
                    _sucoaster_entrypoint_9(param_0, 3, 6);
                }
            } else if (func_801021BC(param_0, 7) && func_80016B54(((CoasterController441 *)param_0)->local_0, 1) == 1) {
                _sucoaster_entrypoint_9(param_0, 7, 6);
            }
        }
        sucoasterplayer_entrypoint_2(param_0, 30.0f);
        return;
    case 3:
        _sucoaster_entrypoint_11(param_0, (f32)_sucoasterdata_entrypoint_2(local_0->local_2));
        if (!func_8080076C_sucoasterplayer(param_0, local_0)) {
            if (sucoasterplayer_entrypoint_3(param_0)) {
                if ((f32)_sucoasterdata_entrypoint_3(local_0->local_2) * ((f32)local_0->local_0 * 0.00390625f) < (f32)local_0->local_1) {
                    _sucoaster_entrypoint_9(param_0, 8, 6);
                }
                if ((f32)local_0->local_1 < (f32)_sucoasterdata_entrypoint_2(local_0->local_2) * ((f32)local_0->local_0 * 0.00390625f)) {
                    _sucoaster_entrypoint_9(param_0, 2, 6);
                }
            } else {
                _sucoaster_entrypoint_9(param_0, 2, 6);
            }
        }
        sucoasterplayer_entrypoint_2(param_0, 30.0f);
        return;
    case 8:
        _sucoaster_entrypoint_11(param_0, (f32)_sucoasterdata_entrypoint_3(local_0->local_2));
        if (!func_8080076C_sucoasterplayer(param_0, local_0)) {
            if (sucoasterplayer_entrypoint_3(param_0)) {
                if ((f32)local_0->local_1 <= (f32)_sucoasterdata_entrypoint_3(local_0->local_2) * ((f32)local_0->local_0 * 0.00390625f)) {
                    _sucoaster_entrypoint_9(param_0, 3, 6);
                }
            } else {
                _sucoaster_entrypoint_9(param_0, 3, 6);
            }
        }
        sucoasterplayer_entrypoint_2(param_0, 30.0f);
        return;
    case 9:
        _sucoaster_entrypoint_19(param_0);
        _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 1);
        func_80102BF8(param_0, 0.3f, 1.0f, 1000.0f);
        sucoasterplayer_entrypoint_2(param_0, 30.0f);
        _sucoaster_entrypoint_16(param_0, 1);
        _sucoaster_entrypoint_16(param_0, 6);
        if (!local_0->local_3 && _sucoaster_entrypoint_16(param_0, 5)) {
            _sucoasterhit_entrypoint_2(param_0);
        }
        if (func_80101DDC(param_0)) {
            _sucoaster_entrypoint_9(param_0, 3, 6);
            return;
        }
        return;
    case 11:
        _sucoaster_entrypoint_16(param_0, 2);
        if (func_80101DDC(param_0)) {
            _sucoaster_entrypoint_9(param_0, 3, 6);
            return;
        }
        break;
    case 12:
    case 13:
    case 18:
        param_0->unk64_24 = 0;
        return;
    case 15:
        _sucoasterhit_entrypoint_1(param_0);
        return;
    case 7:
        _sucoaster_entrypoint_19(param_0);
        sucoasterplayer_entrypoint_3(param_0);
        _sucoaster_entrypoint_16(param_0, 0);
        func_80102BF8(param_0, 0.3f, 1.0f, 1000.0f);
        if (func_80101DDC(param_0)) {
            _sucoaster_entrypoint_9(param_0, 2, 6);
        }
        break;
    }
}

void sucoasterplayer_entrypoint_1(Actor *param_0)
{
    u32 local_0;

    if (!((*(u32 *)((u8 *)param_0 + 0x64) << 2) >> 31)) {
        if (param_0->unk70_10 == 12) return;
        local_0 = *(u32 *)((u8 *)param_0 + 0x70);
        if (!(local_0 >> 25) || !((local_0 << 22) >> 26)) return;
        if (_subaddieDll_entrypoint_3()) {
            if (param_0->unk70_10 == 2) _sucoaster_entrypoint_9(param_0, func_800DC298(0.5f) ? 2 : 3, 7);
        } else if (!func_80107070(param_0, 1)) {
            _subaddiefade_entrypoint_3(param_0);
            _sucoaster_entrypoint_10(param_0, 14);
        }
        *(u32 *)((u8 *)param_0 + 0x14) |= 0x80000;
    } else {
        *(u32 *)((u8 *)param_0 + 0x14) &= ~0x80000;
        switch (param_0->unk70_10) {
            case 5: case 6: case 7: case 10:
                _sucoaster_entrypoint_9(param_0, 2, 6);
                break;
            case 4:
                _sucoaster_entrypoint_9(param_0, 3, 6);
                break;
        }
    }
    param_0->unk54 = *(f32 *)((u8 *)param_0 + 0x48);
}

s32 sucoasterplayer_entrypoint_2(Actor *param_0, f32 param_1)
{
    CoasterPlayerTarget *local_0;
    f32 local_1;

    local_0 = func_80100094(param_0, 0);
    *(f32 *)&param_0->actorData[3] = func_800F15F8(*(f32 *)&param_0->actorData[3], local_0->local_0, func_80107C00() * param_1);
    _sucoaster_entrypoint_18(param_0);
    local_1 = func_800F2094(param_0->unk54, param_0->rotation[1]);
    func_80102BF8(param_0, 0.3f, 1.0f, 1000.0f);
    if (local_1 >= 100.0f) return 1;
    func_8010B990(param_0, 0x205025);
    return 1;
}

int sucoasterplayer_entrypoint_3(Actor *param_0)
{
    u32 *local_0;
    f32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 1);
    _sucoaster_entrypoint_6(param_0, _sucoasterdata_entrypoint_4(local_0[6] >> 28) * local_1);
    return local_1 != 0.0f;
}

int func_8080076C_sucoasterplayer(Actor *param_0, void *param_1)
{
    void *local_1 = _sucoasterdata_entrypoint_1((u32)(*(s32 *)((char *)(param_1) + 0x18)) >> 28);
    if ((*(u16 *)((char *)(local_1) + 0x4A)) != 0)
    {
        if (func_80016B30((u32)(*(s32 *)((char *)(param_0) + 0x64)) * 8 >> 30, 1) == 1)
        {
            return _sucoaster_entrypoint_9(param_0, 9, 6);
        }
    }
    return 0;
}
