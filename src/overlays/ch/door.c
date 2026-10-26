#include "common.h"

typedef struct { u8 pad_0[0x2E]; s16 local_0; s16 local_1; s16 local_2; } DoorLoopSound;
extern void *func_80100094(Actor *, u32);
extern void func_800C4B64(f32);
extern u8 D_808015B0_chdoor[];
extern void func_800C4B7C(s32);
extern void func_800C4B70(s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
typedef struct { u16 unk0; u16 unk2; u8 unk4; u8 unk5; u16 flag : 1; u16 id : 15; } DoorEntry;
typedef struct { u32 unk0; u8 pad4[0x18]; DoorEntry ents[1]; } DoorState;
typedef struct { s32 unk0; u8 pad4[4]; u8 unk8_7 : 6; u8 unk8_1 : 1; u8 unk8_0 : 1; u8 pad9; s16 unkA; u8 padC[0x14]; u8 unk20; u8 unk21; u8 pad22[2]; s16 unk24; u8 pad26[2]; u8 unk28; u8 unk29; u8 pad2A[2]; s16 unk2C; } DoorLocal;
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern s32 _glcutDll_entrypoint_19(s32);
extern s32 _capod_entrypoint_17(f32);
typedef struct { u32 local_0; s16 local_1; } DoorFlagState;
extern f32 mlAbsF(f32);
extern void func_800F5A00(s32, f32 *);
extern f32 func_800137AC(f32);
extern f32 func_800137C4(void);
extern f32 func_800F5F24(s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_800F0AA4(f32 *, f32 *, f32 *, f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EE88C();
typedef struct Mass45DoorFlags { u32 local_0 : 15; u32 local_1 : 1; u32 local_2 : 16; } Mass45DoorFlags;
extern f32 func_800F1DCC(f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void _sudeflect_entrypoint_3(f32 *, f32 *, f32 *, f32 *, s32);
typedef struct { u32 flags; u8 pad4[4]; u32 pad8_26:6; u32 b25:1; u32 pad8_0:25; } DoorHead;
typedef struct { u32 flags; u8 pad4[4]; u32 pad8_26:6; u32 b25:1; u32 pad8_16:9; s16 unkA; s16 unkC; s16 unkE; } DoorData;
void func_8080050C_chdoor();

void func_80800028_chdoor();

extern void func_80101FDC(Actor *, s32);
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern void func_80103110(Actor *, s32);
extern s32 func_800E1610(s32, f32, f32, f32 *);
extern void func_800E148C(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
extern void func_800FC660(s32);
extern void func_8010A624(Actor *);
extern void func_8010A63C(Actor *);
extern void func_800FFAB0(Actor *);
s32 func_808013C0_chdoor();
void func_8080032C_chdoor(Actor *param_0, f32 param_1);
void func_80800754_chdoor();
void func_808008A0_chdoor();
void func_808009F4_chdoor();
void func_80800B14_chdoor();

void chdoor_entrypoint_0(s32 arg0)
{
    func_80800028_chdoor();
    func_8080050C_chdoor(arg0);
}
void func_8080069C_chdoor();

void func_80800028_chdoor(Actor *param_0)
{
    u8 *local_0;
    s32 local_5;
    f32 local_1;
    s32 local_2;
    s32 pad[2];
    f32 local_3;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
        case 1:
            if (*(s32 *)local_0 & 4) {
                if (func_800DA298(*(s16 *)(local_0 + 4))) {
                    func_80800754_chdoor(param_0);
                }
            } else {
                local_5 = local_0[0x20];
                if (local_5 && _glcutDll_entrypoint_19(local_5)) {
                    func_80800754_chdoor(param_0);
                }
            }
            break;
        case 2:
            if (func_800D9078(&param_0->unk58)) {
                func_80800B14_chdoor(param_0, 3);
            }
            break;
        case 3:
            local_1 = param_0->unk58;
            local_2 = func_800D9078(&param_0->unk58);
            func_8080032C_chdoor(param_0, func_800F12D4(param_0->unk58,
                0.0f, *(s16 *)(local_0 + 0xA) * 0.00390625f, 1.0f, 0.0f));
            if (local_1 >= 0.2f && param_0->unk58 < 0.2f) {
                func_8080069C_chdoor(param_0, 1);
            }
            if (local_2) {
                func_80800B14_chdoor(param_0, 4);
                func_8010108C(param_0, 0x9D, 0);
            }
            break;
        case 4:
            if (*(s32 *)local_0 & 2) {
                if (*(s32 *)local_0 & 4) {
                    if (!func_800DA298(*(s16 *)(local_0 + 4))) {
                        func_808008A0_chdoor(param_0);
                    }
                } else {
                    local_5 = local_0[0x28];
                    if (local_5 && _glcutDll_entrypoint_19(local_5)) {
                        func_808008A0_chdoor(param_0);
                    }
                }
                if (*(s32 *)local_0 & 0x400) {
                    func_808008A0_chdoor(param_0);
                }
            }
            break;
        case 5:
            if (func_800D9078(&param_0->unk58)) {
                func_80800B14_chdoor(param_0, 6);
            }
            break;
        case 6:
            local_3 = param_0->unk58;
            local_4 = func_800D9078(&param_0->unk58);
            func_8080032C_chdoor(param_0, func_800F12D4(param_0->unk58,
                0.0f, *(s16 *)(local_0 + 0xA) * 0.00390625f, 0.0f, 1.0f));
            if (local_3 >= 0.2f && param_0->unk58 < 0.2f) {
                func_8080069C_chdoor(param_0, 0);
            }
            if (local_4) {
                func_80800B14_chdoor(param_0, 1);
                func_8010108C(param_0, 0x9E, 0);
            }
            break;
    }
}

void func_8080032C_chdoor(Actor *param_0, f32 param_1)
{
    u8 *local_6;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    s32 unused_slot1;
    f32 local_4[3];
    f32 local_5[3];
    s32 unused_slot2;

    local_6 = func_80100094(param_0, 0);
    switch (*(u32 *)(local_6 + 8) >> 26) {
        case 1:
            param_0->rotation[1] = *(s16 *)(local_6 + 0x12) + func_800F1DCC(*(s16 *)(local_6 + 0x10), *(s16 *)(local_6 + 0x12)) * param_1;
            break;
        case 2:
            func_800EE88C(local_0, (s16 *)(local_6 + 0x10));
            func_800EE88C(local_1, (s16 *)(local_6 + 0x16));
            func_800EFE50(param_0->position, local_0, local_1, param_1);
            break;
        case 3:
            param_0->rotation[0] = *(s16 *)(local_6 + 0x12) + func_800F1DCC(*(s16 *)(local_6 + 0x10), *(s16 *)(local_6 + 0x12)) * param_1;
            break;
        case 4:
            func_800EE88C(local_2, (s16 *)(local_6 + 0x10));
            func_800EE88C(local_3, (s16 *)(local_6 + 0x16));
            func_800EFE50(param_0->position, local_2, local_3, param_1);
            param_0->rotation[2] = *(s16 *)(local_6 + 0x1C) * 0.00390625f * param_1;
            break;
        case 5:
            _subaddiefade_entrypoint_1(param_0, (s32)((1.0f - param_1) * 255.0f));
            break;
    }
    func_80103014(param_0);
    if ((*(s32 *)local_6 << 15) < 0) {
        func_80104004(param_0, local_4, local_5);
        _sudeflect_entrypoint_3(param_0->position, param_0->rotation, local_4, local_5, 2);
    }
}

void func_8080050C_chdoor(Actor *param_0)
{
    s32 local_0;
    DoorLoopSound *local_1;

    local_0 = 0;
    local_1 = func_80100094(param_0, 0);
    if (param_0->unk70_10 == 3 || param_0->unk70_10 == 6) local_0 = 1;
    if (local_1->local_0 && (local_0 || (!local_0 && param_0->unk5F))) {
        func_800C4B7C(local_1->local_0);
        func_800C4B70(local_1->local_1);
        func_800C4B64((f32)local_1->local_2 * 0.00390625f);
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_0, ((s16 *) D_808015B0_chdoor));
    }
}

void func_808005E4_chdoor(Actor *param_0, s32 param_1)
{
    s16 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0[28] != 0 &&
        ((param_1 != 0 && local_0[26] != 0) ||
         (param_1 == 0 && local_0[27] != 0))) {
        func_800C4B7C(local_0[28]);
        func_800C4B70(local_0[29]);
        func_800C4B64(local_0[30] * 0.00390625f);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808015B0_chdoor);
    }
}

void func_8080069C_chdoor(Actor *param_0, s32 param_1)
{
    s16 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0[33] != 0 &&
        ((param_1 != 0 && local_0[31] != 0) ||
         (param_1 == 0 && local_0[32] != 0))) {
        func_800C4B7C(local_0[33]);
        func_800C4B70(local_0[34]);
        func_800C4B64(local_0[35] * 0.00390625f);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808015B0_chdoor);
    }
}

void func_80800754_chdoor(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    if (*(s16 *)(local_0 + 12)) local_1 = 2;
    else local_1 = 3;
    if (func_800DA298(0x9CC, local_1)) {
        if ((*(u32 *)local_0 & 0x4000) &&
            (!(*(u32 *)local_0 & 0x80) || !func_800DA298(*(u16 *)(local_0 + 0x22) & 0x7FFF, local_1))) local_1 = 7;
        func_80800B14_chdoor(param_0, local_1);
        switch (*(u32 *)(local_0 + 8) >> 26) {
        case 1: param_0->rotation[1] = *(s16 *)(local_0 + 0x12); break;
        case 2: func_800EE88C(param_0->position, (s16 *)(local_0 + 0x10)); break;
        case 3: param_0->rotation[0] = *(s16 *)(local_0 + 0x12); break;
        case 4:
            func_800EE88C(param_0->position, (s16 *)(local_0 + 0x10));
            param_0->rotation[2] = 0.0f;
            break;
        case 5: _subaddiefade_entrypoint_1(param_0, 255); break;
        }
        func_80103014(param_0);
    }
}

void func_808008A0_chdoor(param_0) Actor *param_0;
{
    u8 *local_0 = func_80100094(param_0, 0);
    s32 local_1 = *(s16 *)(local_0 + 14) ? 5 : 6;

    if ((*(u32 *)local_0 & 0x4000) &&
        (!(*(u32 *)local_0 & 0x80) || !func_800DA298(*(u16 *)(local_0 + 0x2A) & 0x7FFF))) {
        local_1 = 8;
    }
    func_80800B14_chdoor(param_0, local_1);
    switch (*(u32 *)(local_0 + 8) >> 26) {
        case 1:
            param_0->rotation[1] = *(s16 *)(local_0 + 0x10);
            break;
        case 2:
            func_800EE88C(param_0->position, local_0 + 0x16);
            break;
        case 3:
            param_0->rotation[0] = *(s16 *)(local_0 + 0x10);
            break;
        case 4:
            func_800EE88C(param_0->position, local_0 + 0x16);
            param_0->rotation[2] = *(s16 *)(local_0 + 0x1C) * 0.00390625f;
            break;
        case 5:
            _subaddiefade_entrypoint_1(param_0, 0);
            break;
    }
    func_80103014(param_0);
}

void func_808009F4_chdoor(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1;
    s16 local_2;
    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 1: case 2: case 7:
        local_2 = *(s16 *)(local_0 + 0xC);
        *(s16 *)(local_0 + 0xC) = 0;
        func_80800754_chdoor(param_0);
        *(s16 *)(local_0 + 0xC) = local_2;
        break;
    case 6:
        local_1 = *(s16 *)(local_0 + 0xA) * 0.00390625f - param_0->unk58;
        func_80800B14_chdoor(param_0, 3);
        param_0->unk58 = local_1;
        break;
    case 3:
        local_1 = *(s16 *)(local_0 + 0xA) * 0.00390625f - param_0->unk58;
        func_80800B14_chdoor(param_0, 6);
        param_0->unk58 = local_1;
        break;
    case 4: case 5: case 8:
        local_2 = *(s16 *)(local_0 + 0xE);
        *(s16 *)(local_0 + 0xE) = 0;
        func_808008A0_chdoor(param_0);
        *(s16 *)(local_0 + 0xE) = local_2;
        break;
    }
}

void func_80801330_chdoor();

void func_80800FC0_chdoor();

void func_80800B14_chdoor(param_0, param_1) Actor *param_0; s32 param_1;
{
    DoorData *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    local_1 = param_0->unk70_10;
    local_2 = (local_0->flags & 4) ? 1 : 0;
    local_3 = (local_0->flags & 8) ? 1 : 0;
    if (local_0->b25) {
        switch (local_1) {
        case 3:
            func_80101FDC(param_0, 6);
            func_80800FC0_chdoor(param_0, 1);
            param_0->unk58 = local_0->unkA * 0.00390625f;
            break;
        case 6:
            func_80101FDC(param_0, 3);
            if (local_0->unkC == 0) {
                func_80800FC0_chdoor(param_0, 0);
            }
            param_0->unk58 = local_0->unkA * 0.00390625f;
            break;
        }
        local_0->b25 = 0;
        return;
    }
    func_80101FDC(param_0, param_1);
    switch (param_1) {
    case 1:
        _subaddieaudioloop_entrypoint_2(param_0);
        func_80103110(param_0, local_2 | local_3);
        func_80801330_chdoor(param_0, 0);
        if (local_0->flags & 0x100) {
            func_800E148C(func_800E1610(2, 100.0f, 0.85f, param_0->position), 1000.0f, 4000.0f);
            func_80018820(0, 1.0f, 0.4f);
        }
        break;
    case 2:
        func_80800FC0_chdoor(param_0, 0);
        param_0->unk58 = local_0->unkC * 0.00390625f;
        func_80103110(param_0, 1);
        break;
    case 3:
        if (local_0->flags & 0x40) {
            func_800FC660(0x10);
        }
        if (local_0->unkC == 0) {
            func_80800FC0_chdoor(param_0, 0);
        }
        param_0->unk58 = local_0->unkA * 0.00390625f;
        func_808005E4_chdoor(param_0, 1);
        func_80103110(param_0, 1);
        func_80801330_chdoor(param_0, 1);
        break;
    case 4:
        _subaddieaudioloop_entrypoint_2(param_0);
        func_80103110(param_0, local_2 | local_3);
        if (local_0->flags & 0x800) {
            func_8010A624(param_0);
        }
        if (local_0->flags & 0x2000) {
            param_0->unk64_16 = 0;
        }
        if (local_0->flags & 1) {
            func_800FFAB0(param_0);
        }
        break;
    case 5:
        func_80800FC0_chdoor(param_0, 1);
        param_0->unk58 = local_0->unkE * 0.00390625f;
        func_80103110(param_0, 1);
        break;
    case 6:
        if (local_0->flags & 0x1000) {
            func_800FC660(0x17);
        }
        if (local_0->unkE == 0) {
            func_80800FC0_chdoor(param_0, 1);
        }
        if (local_0->flags & 0x800) {
            func_8010A63C(param_0);
        }
        if (local_0->flags & 0x2000) {
            param_0->unk64_16 = 1;
        }
        param_0->unk58 = local_0->unkA * 0.00390625f;
        func_808005E4_chdoor(param_0, 0);
        func_80103110(param_0, 1);
        break;
    case 7:
        func_80800FC0_chdoor(param_0, 0);
        func_80103110(param_0, local_3);
        break;
    case 8:
        func_80800FC0_chdoor(param_0, 1);
        func_80103110(param_0, local_3);
        break;
    }
}

void func_80800FC0_chdoor(Actor *param_0, s32 param_1)
{
    DoorState *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0->ents[param_1].flag) {
        if ((local_0->unk0 & 0x80) && local_0->ents[param_1].id) {
            if (!func_800DA9E4(local_0->ents[param_1].id, 1)) {
                _capod_entrypoint_13(param_0->unk0, 0, local_0->ents[param_1].unk5, local_0->ents[param_1].unk2);
            }
        } else {
            _capod_entrypoint_13(param_0->unk0, 0, local_0->ents[param_1].unk5, local_0->ents[param_1].unk2);
        }
    }
}

s32 chdoor_entrypoint_1(Actor *this, s32 msg, s32 arg2)
{
    DoorLocal *local;
    s32 a;
    s32 b;

    local = func_80100094(this, 0);
    switch (msg) {
    case 7:
        if (arg2 != 0 && local->unkA * 0.00390625f == 0.0f) {
            _chdoormake_entrypoint_5(this, arg2);
        }
        switch (this->unk70_10) {
        case 6:
            local->unk8_1 = 1;
            break;
        case 1:
            func_80800754_chdoor(this);
            break;
        }
        break;
    case 8:
        if (!(local->unk0 & 2)) {
            return 0;
        }
        switch (this->unk70_10) {
        case 3:
            local->unk8_1 = 1;
            break;
        case 4:
            func_808008A0_chdoor(this);
            break;
        }
        break;
    case 0x49:
        a = local->unk20;
        b = local->unk28;
        if (a != -1 && _glcutDll_entrypoint_19(a)) {
            func_80800754_chdoor(this);
            return 1;
        }
        if (b != -1 && _glcutDll_entrypoint_19(b)) {
            func_808008A0_chdoor(this);
            return 1;
        }
        return 0;
    case 0x6F:
        if (!(local->unk0 & 0x200)) {
            return 0;
        }
        return func_808013C0_chdoor(this, arg2);
    case 0xE:
        if (!(local->unk0 & 0x4000)) {
            return 2;
        }
        if (arg2 == local->unk21) {
            if (_capod_entrypoint_17(local->unk24 * 0.00390625f)) {
                func_80800B14_chdoor(this, 3);
            }
        } else if (arg2 == local->unk29) {
            if (_capod_entrypoint_17(local->unk2C * 0.00390625f)) {
                func_80800B14_chdoor(this, 6);
            }
        }
        return 3;
    default:
        return 0;
    }
    return 1;
}

void func_80801330_chdoor(Actor *param_0, s32 param_1)
{
    DoorFlagState *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    if (local_0->local_1 != -1 && !(local_0->local_0 & 0x20)) {
        local_1 = param_1 ? 1 : 0;
        if (local_0->local_0 & 0x10) func_800DA3B8(local_0->local_1, local_1 ? 0 : 1);
        else func_800DA3B8(local_0->local_1, local_1);
    }
}

s32 func_808013C0_chdoor(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    f32 local_1[3];
    f32 local_5;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_6;
    f32 local_7;
    local_0 = func_80100094(param_0, 0);
    func_800F5A00(param_1, local_1);
    if (*(u32 *)(local_0 + 8) >> 26 == 2) local_5 = *(s16 *)(local_0 + 0x12);
    else local_5 = param_0->position[1];
    if (mlAbsF(local_1[1] - local_5) > 100.0f) return 0;
    local_6 = func_800137AC(param_0->rotation[1]) * 100.0f;
    local_7 = func_800137C4() * 100.0f;
    local_2[0] = param_0->position[0] - local_6;
    local_2[2] = param_0->position[2] - local_7;
    local_3[0] = param_0->position[0] + local_6;
    local_3[2] = param_0->position[2] + local_7;
    func_800EEB9C(local_4, func_800F5F24(param_1), 200.0f);
    func_800EF04C(local_4, local_1);
    if (!func_800F0AA4(local_2, local_3, local_1, local_4)) return 0;
    func_808009F4_chdoor(param_0);
    return 1;
}
