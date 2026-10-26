#include "common.h"

#define PLANT_ACTOR_FLAGS_DEFINED
#define DATA ((f32 *)this->actorData)
extern int D_80800A9C_ch2dbaddy;
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 local_0 : 1; u32 pad_2 : 29; } BaddyHitFlags1766;
typedef struct { s16 index; u8 count; u8 pad_0; } BaddyMessage29;
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 29; u32 locked : 1; u32 pad_2 : 2; } BaddyFlags29;
extern u8 D_80800A3C_ch2dbaddy[];
extern void *_sucoaster_entrypoint_3();
typedef struct { u8 pad[0x64]; u32 pad64:2; u32 flag:1; u32 rest:29; } JoyState;
extern s32 _subaddiejoy_entrypoint_6(JoyState *, s32);
extern s32 _sucoaster_entrypoint_13(JoyState *);
typedef struct { u8 pad_0[0x64]; u32 pad_64_30 : 2; u32 flag_64_29 : 1; u32 pad_64_0 : 29; } PlantActorFlags;
typedef struct { u8 pad_0[0x64]; u32 pad_1:2; u32 flag_29:1; u32 pad_2:29; } BaddyFlags30;
extern void _sucoaster_entrypoint_6();
extern u8 D_80800AE4_ch2dbaddy[];
extern s32 D_80800AF4_ch2dbaddy;
extern s16 D_80800B00_ch2dbaddy[];
extern void func_8010A3E8(Actor *, f32);
extern void func_80102FDC(Actor *, f32);
extern void func_800EE940(void *, f32 *);
typedef struct { u32 pad78_3 : 29; u32 unk78_2 : 1; u32 pad78_0 : 2; } ActorFlags78;
typedef struct { u32 pad64_30 : 2; u32 unk64_29 : 1; u32 pad64_0 : 29; } ActorFlags64;
extern void _sucoaster_entrypoint_2(Actor *);
extern void _sucoaster_entrypoint_10(Actor *, s32);
extern void _sucoaster_entrypoint_19(Actor *);
extern f32 func_8010CD28(Actor *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010A5B0(Actor *, s32);
extern s32 func_80101DDC(Actor *);
extern f32 func_80101F24(Actor *);
extern void func_8010A570(Actor *);
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern void func_800EE88C(f32 *, void *);
extern f32 func_80102D78(Actor *, f32 *);
extern void _sucoaster_entrypoint_7(Actor *, s32, f32);
extern f32 func_800EFC7C();
typedef struct { u8 pad0[0x64]; u32 b31 : 1; u32 b30 : 1; u32 b29 : 1; u32 rest : 29; } Baddy2DFlags;
extern s32 func_800D9058(f32);
extern void func_8010297C(Actor *, f32, f32, f32);
void func_808004A8_ch2dbaddy();
void func_808004F4_ch2dbaddy();
void func_80800700_ch2dbaddy();
void func_80800850_ch2dbaddy();
s32 func_808003C4_ch2dbaddy();
int func_80800564_ch2dbaddy();

int ch2dbaddy_entrypoint_0()
{
    return (int)&D_80800A9C_ch2dbaddy;
}

void func_8080000C_ch2dbaddy(Actor *param_0)
{
    void *local_0;
    if (_sucoaster_entrypoint_0(param_0, 10)) {
        func_8010A3E8(param_0, 0.55f);
        func_80102FDC(param_0, param_0->scale * 0.6f);
        local_0 = _sucoaster_entrypoint_3(param_0);
        func_80800850_ch2dbaddy(param_0);
        func_800EE940(local_0, param_0->position);
        param_0->unk64_16 = 0;
        func_8010A570(param_0);
    }
}

s32 func_80800468_ch2dbaddy();

void func_808000A0_ch2dbaddy(Actor *this)
{
    f32 vec[3];

    _sucoaster_entrypoint_2(this);
    if (((ActorFlags78 *)&this->unk78)->unk78_2) {
        return;
    }
    switch (this->unk70_10) {
    case 2:
    case 3:
    case 8:
        if (func_80800468_ch2dbaddy(this)) {
            _sucoaster_entrypoint_10(this, 0x16);
            DATA[3] = 0.0f;
        }
        break;
    case 0x13:
        _sucoaster_entrypoint_19(this);
        if (func_8080041C_ch2dbaddy(this)) {
            func_80800700_ch2dbaddy(this, 0x14);
        }
        break;
    case 0x14:
        func_80800820_ch2dbaddy(this);
        this->unk54 = func_8010CD28(this);
        func_80102BF8(this, 0.2f, 60.0f, 300.0f);
        func_8010A5B0(this, this->unk64_20);
        this->unk64_20 = 1;
        if (func_80101DDC(this)) {
            _sucoaster_entrypoint_10(this, ((ActorFlags64 *)((u8 *)this + 0x64))->unk64_29 ? 2 : 8);
        }
        break;
    case 0x16:
        _sucoaster_entrypoint_19(this);
        if (0.6f < func_80101F24(this)) {
            func_8010A570(this);
        }
        if (func_80101DDC(this)) {
            func_80800700_ch2dbaddy(this, 0x13);
        }
        break;
    case 0x15:
        _sucoaster_entrypoint_19(this);
        if (!_sucoaster_entrypoint_13(this)) {
            if (func_808003C4_ch2dbaddy(this)) {
                _sucoaster_entrypoint_10(this, 0x16);
                DATA[3] = 0.0f;
                break;
            }
            if (_subaddierouteDll_entrypoint_4(this)) {
                func_800EE88C(vec, _sucoaster_entrypoint_3(this));
                this->unk54 = func_80102D78(this, vec);
            }
        }
        _sucoaster_entrypoint_7(this, 0x5802, 30.0f);
        break;
    }
}

s32 func_808002A8_ch2dbaddy(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    switch (param_1) {
    case 1:
    case 2:
        local_0 = _sucoaster_entrypoint_21(param_0, param_1, param_2);
        if (!((BaddyFlags29 *)param_0)->locked) {
            if (((BaddyHitFlags1766 *)param_0)->local_0) func_808004A8_ch2dbaddy(param_0);
            else func_808004F4_ch2dbaddy(param_0);
            return 1;
        }
        break;
    case 0x42:
        local_0 = func_80800564_ch2dbaddy(param_0, ((BaddyMessage29 *)&param_2)->index, ((BaddyMessage29 *)&param_2)->count);
        break;
    case 0x95:
        func_801032B0(param_0, *(u16 *)((u8 *)_sucoaster_entrypoint_3(param_0) + 6), 0);
        local_0 = _sucoaster_entrypoint_21(param_0, param_1, param_2);
        break;
    case 0x38:
        func_80101074(D_80800A3C_ch2dbaddy);
        return 8;
    default:
        local_0 = _sucoaster_entrypoint_21(param_0, param_1, param_2);
        break;
    }
    return local_0;
}

s32 func_808003C4_ch2dbaddy(param_0) u8 *param_0; {
    f32 local_0[3];
    func_800EE88C(local_0, _sucoaster_entrypoint_3(param_0));
    return func_800EFC7C(param_0 + 4, local_0) < 10000.0f;
}

int func_8080041C_ch2dbaddy(JoyState *param_0) {
    if (param_0->flag) {
        return _subaddiejoy_entrypoint_6(param_0, 0) == 1;
    }
    return _sucoaster_entrypoint_13(param_0) == 1;
}

s32 func_80800468_ch2dbaddy(Actor *param_0)
{
    if (((PlantActorFlags *)param_0)->flag_64_29) {
        return _subaddiejoy_entrypoint_6(param_0, 0) == 1;
    }
    return 0;
}

void func_808004A8_ch2dbaddy(param_0) u8 *param_0; {
    u32 local_0;

    local_0 = (u32)(*(u16 *)((char *)param_0 + 0x72)) >> 0xA;
    if (local_0 != 0x13) {
        if (local_0 == 0x15) {
            _sucoaster_entrypoint_10(param_0, 3);
        }
    } else {
        func_80800700_ch2dbaddy(param_0, 0x14);
    }
}

void func_808004F4_ch2dbaddy(param_0) u8 *param_0; {
    s32 sp1C;
    u32 temp_t6;

    temp_t6 = (u32) (*(u16 *)((s8 *)(param_0) + (0x72))) >> 0xA;
    if (temp_t6 == 2 || temp_t6 == 3 || temp_t6 == 8) {
        if (_subaddieDll_entrypoint_3(param_0) != 0) {
            sp1C = 0x15;
        } else {
            sp1C = 0xE;
        }
        _sucoaster_entrypoint_6(param_0, 0x43480000, sp1C);
        _sucoaster_entrypoint_10(param_0, sp1C);
    }
}

int func_80800564_ch2dbaddy(param_0, param_1, param_2) Actor *param_0; s32 param_1; u32 param_2;
{
    switch (param_2) {
        case 0:
            if (param_0->unk70_10 == 0x13) { return 0; }
            switch (param_1) {
                case 2: case 3: func_80800700_ch2dbaddy(param_0, 0x15); return 0;
                case 4: func_80800700_ch2dbaddy(param_0, 0x15); return 0;
                case 5: case 8: case 9: case 18: return 1;
                case 7: _sucoaster_entrypoint_10(param_0, 8); return 0;
            }
            break;
        case 2: case 7: func_80800700_ch2dbaddy(param_0, 0x15); return 0;
        case 3:
            param_0->unk6C_0 = func_800D9058(2.0f);
            func_8010297C(param_0, param_0->unk54, 70.0f, 120.0f);
            if (param_0->unk70_10 == 8) { func_80800700_ch2dbaddy(param_0, 0x15); }
            return 0;
        case 4:
            if (param_0->unk70_10 != 0x13) { return 1; }
            break;
        case 1: case 6: return 1;
        case 5: func_80800700_ch2dbaddy(param_0, 0xC); return 0;
        case 8:
            if (param_1 == 0x11) { func_801020DC(param_0, 0); }
            return 1;
        case 9:
            if (((Baddy2DFlags *)param_0)->b29) {
                _sucoaster_entrypoint_10(param_0, 2);
                return 0;
            }
            return 1;
    }
    return 0;
}

void func_80800700_ch2dbaddy(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    local_0 = _sucoaster_entrypoint_3(param_0);
    switch (param_1) {
    case 0xC:
        func_8010A570(param_0);
        _sucoaster_entrypoint_10(param_0, param_1);
        break;
    case 0x15:
        _sucoaster_entrypoint_10(param_0, param_1);
        _sucoaster_entrypoint_6(param_0, 0x43480000);
        break;
    case 0x13:
        _sucoaster_entrypoint_10(param_0, param_1);
        func_8010A570(param_0);
        if (!((BaddyFlags30 *)param_0)->flag_29) {
            func_80800850_ch2dbaddy(param_0);
            func_801032B0(param_0, *(u16 *)(local_0 + 6), 0);
        }
        param_0->unk64_16 = 0;
        break;
    case 0x14:
        _sucoaster_entrypoint_10(param_0, param_1);
        param_0->unk64_16 = 1;
        param_0->unk64_20 = 0;
        func_8010A570(param_0);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800AE4_ch2dbaddy);
        break;
    }
}

int func_80800820_ch2dbaddy(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddieaudioquick_entrypoint_3(param_0, local_0, &D_80800AF4_ch2dbaddy, 0x3DCCCCCD);
}

void func_80800850_ch2dbaddy(void) {
    void *local_0 = _sucoaster_entrypoint_3();
    *((u16 *)((char *)local_0 + 6)) = D_80800B00_ch2dbaddy[func_800DC128(0, 3)];
}
