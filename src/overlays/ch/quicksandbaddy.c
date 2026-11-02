#include "common.h"

extern f32 func_800C6920(f32[3], f32, f32, s32);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800DC0C0(void);
extern s32 func_800B53A4(s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 D_80801370_chquicksandbaddy[];
extern s32 D_80801390_chquicksandbaddy[];
extern u8 D_80801394_chquicksandbaddy[];
extern u8 _chquicksandbaddy_entrypoint_0[];
extern u8 D_808013D4_chquicksandbaddy[];
extern void *func_80100094(Actor *, u32);
extern int func_800EEF24(f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern int D_808013D8_chquicksandbaddy;
extern void *func_80100074(Actor *, s32, s32);
extern f32 func_800DC178(f32, f32);
typedef struct { f32 local_0; u16 local_1; u16 local_2; } QuicksandAnimation;
typedef struct { f32 local_0; f32 local_1; } QuicksandSoundEvent;
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800C4140(s32, f32 *, s32);
extern void func_800F7C58(s32, s32, s32);
extern f32 func_800F5628(s32);
extern f32 func_80103EAC(Actor *);
extern f32 *func_800CC63C(s32, s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800F4F34(s32, f32 *, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern void func_80101EE4(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern void * func_800C6A7C(f32 *, f32 *, f32 *, u32);
extern s32 func_800CC338(f32 *, s32, s32);
extern s32 func_800D90A4(f32 *);
extern f32 func_800D91B8(f32 *);
extern s32 func_800E3980(s32);
extern void func_800EF04C(f32 *, f32 *);
extern int func_800F6AA4(s32);
extern void func_800F7D90(s32, s32, s32, s32);
extern void func_800FC660(u32);
extern s32 func_80101DDC(void *);
extern void func_80102424(void *, s32);
extern void func_80103014(s32);
extern void func_8010D254(s32);
typedef struct { u8 pad[0x78]; u32 p78 : 8; u32 f4 : 4; u32 rest : 20; } QS78;
f32 func_80800CC0_chquicksandbaddy();

extern f32 mlAbsF(f32);
int func_808010A0_chquicksandbaddy();
s32 func_80800CFC_chquicksandbaddy();

void func_80800000_chquicksandbaddy(Actor *param_0)
{
    s32 local_0[3];
    s32 local_1;
    s32 local_3;
    f32 (*local_2)[3];

    local_1 = _gccubesearch_entrypoint_9(0x510, local_0, 3);
    if (local_1) {
        local_2 = func_80100074(param_0, 1, 0x24);
        local_3 = 0;
        for (; local_3 < local_1; local_3++) {
            _gspropctrl_entrypoint_11(local_0[local_3], local_2[local_3]);
        }
        for (; local_3 < 3; local_3++) {
            func_800EFD24(local_2[local_3]);
        }
    }
    if (!_subaddieDll_entrypoint_1(param_0)) {
        func_800FFA88(param_0->unk0);
        return;
    }
    *(f32 *)((u8 *)param_0 + 0x34) = param_0->position[1];
    param_0->unk58 = 0.2f;
    *(f32 *)((u8 *)param_0 + 0x24) = 0.0f;
    param_0->unk54 = 0.0f;
    param_0->unk54 = param_0->position[1] - func_80800CC0_chquicksandbaddy(param_0);
    *(f32 *)((u8 *)param_0 + 0x28) = func_800DC178(20.0f, 30.0f);
    ((u8 *)param_0)[0x65] &= ~1;
}

void func_80800FC8_chquicksandbaddy(s32 param_0, f32 param_1, s32 param_2);

void chquicksandbaddy_entrypoint_0();

s32 func_80800DBC_chquicksandbaddy();

void func_80800140_chquicksandbaddy(Actor *param_0)
{
    extern u8 D_808012E0_chquicksandbaddy[];
    extern u8 D_808012F0_chquicksandbaddy[];
    extern u8 D_80801300_chquicksandbaddy[];
    extern u8 D_80801310_chquicksandbaddy[];
    extern QuicksandAnimation D_808012A0_chquicksandbaddy[];
    extern QuicksandSoundEvent D_80801320_chquicksandbaddy[];
    extern s32 D_80801370_chquicksandbaddy[];

    switch (param_0->unk70_10) {
    case 1: {
        f32 local_0[3];
        f32 local_1[3];
        func_8010D254(local_0);
        if (func_800D90A4((f32 *)param_0->actorData + 4)) {
            func_800E3980(local_1);
            param_0->rotation[1] = func_800F1DF4(param_0->position, local_1);
            func_80102424(param_0, 6);
        }
        if (func_80800DBC_chquicksandbaddy(param_0)) {
            if (func_800F6AA4(func_800F54E4())) {
                param_0->actorData[5] = 1;
            } else {
                param_0->actorData[5] = 0;
            }
            if (func_800F7B9C(func_800F54E4(), 0x34)) {
                func_800EE7F8(param_0->position, local_0);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                    D_808012E0_chquicksandbaddy);
                _subaddieDll_entrypoint_4(param_0, 1);
                func_800F5A00(func_800F54E4(), param_0->position);
                param_0->position[1] = func_800F5628(func_800F54E4()) + param_0->unk54;
                if (func_8008FC00() == 1) {
                    func_80102424(param_0, 5);
                    param_0->unk58 = 0.0f;
                    ((f32 *)param_0->actorData)[4] = 0.0f;
                } else {
                    func_80102424(param_0, 2);
                    param_0->unk58 = 0.5f;
                }
            }
        } else if (((f32 *)param_0->actorData)[7] < local_0[1]) {
            param_0->unk58 = 0.2f;
            if (func_800D90A4((f32 *)param_0->actorData + 3)) {
                ((f32 *)param_0->actorData)[3] = 0.5f;
                if (func_800F56AC(func_800F54E4()) != 0x14 &&
                    func_800F6C5C(func_800F54E4())) {
                    local_0[1] = func_800F5628(func_800F54E4());
                    func_800EE7F8(param_0->actorData, local_0);
                    param_0->unk64_20 = 1;
                }
            }
        } else {
            param_0->unk58 = 0.2f;
        }
        break;
    }
    case 2: {
        f32 local_2[3];
        if (func_800D90A4(&param_0->unk58)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                D_808012F0_chquicksandbaddy);
            if ((func_800EA05C() == 0xB9 || func_800EA05C() == 0xC4) &&
                func_80800CFC_chquicksandbaddy(param_0, param_0->position,
                    (f32 *)param_0->actorData)) {
                func_800F7D90(func_800F54E4(), 0x52, param_0->actorData,
                    param_0->actorData[5] ? 0 : 1);
                param_0->unk64_19 = 1;
            } else if (func_80801154_chquicksandbaddy(param_0, local_2) != -1) {
                func_800F7D90(func_800F54E4(), 0x52, local_2,
                    param_0->actorData[5] ? 0 : 1);
                param_0->unk64_19 = 1;
            } else {
                func_800F7C58(func_800F54E4(), 0x6A,
                    param_0->actorData[5] ? 0 : 1);
                param_0->unk64_19 = 0;
            }
            param_0->unk74_30 = 0;
            param_0->unk79_4 = 0;
            param_0->unk50 = 0.0f;
            param_0->unk58 = 1.0f;
            func_80102424(param_0, 3);
        }
        break;
    }
    case 3: {
        f32 local_3[3];
        if (func_800D90A4(&param_0->unk58)) {
            f32 *local_10;
            if (param_0->unk64_19) {
                func_800F5A00(func_800F54E4(), local_3);
            } else {
                func_800E3980(local_3);
            }
            param_0->rotation[1] = func_800F1DF4(param_0->position, local_3);
            func_80102424(param_0, 4);
            if (!(param_0->unk74_30 && param_0->unk79_4 >= 6)) {
                local_10 = func_800CC63C(
                    (*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1,
                    ((*(u32 *)((u8 *)param_0 + 0x70) << 22) >> 26) - 1);
                func_800EE7F8(param_0->position, local_10);
                param_0->position[1] = func_80800CC0_chquicksandbaddy(param_0);
            }
        } else if (!(param_0->unk74_30 && param_0->unk79_4 >= 6)) {
            s32 local_14;
            f32 local_4[3];
            f32 local_5[3];
            f32 local_8[3];
            f32 local_6[3];
            f32 local_7;
            param_0->unk74_30 = 1;
            for (local_14 = 0; local_14 < 3; local_14++) {
                local_7 = param_0->unk79_4 * 60.0f;
                func_800EE7F8(local_4, param_0->position);
                local_4[1] += 60.0f;
                func_800EEB9C(local_5, local_7, func_80103EAC(param_0));
                func_800EF04C(local_5, local_4);
                func_800EE7F8(local_6, local_5);
                if (func_800C6A7C(local_4, local_5, local_8, 0)) {
                    func_800EF334(local_8, 300.0f);
                    func_800EF04C(local_8, local_5);
                    func_800EFB24(local_6, local_5, local_6);
                    func_800EF04C(param_0->position, local_6);
                    param_0->position[1] = func_80800CC0_chquicksandbaddy(param_0);
                    param_0->unk74_30 = 0;
                    param_0->unk79_4 = 0;
                    break;
                } else if (func_800CC338(local_5,
                    (*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1,
                    ((*(u32 *)((u8 *)param_0 + 0x70) << 22) >> 26) - 1) == -1) {
                    func_800EEB9C(local_8,
                        func_800F1DF4(param_0->position, func_800CC63C(
                            (*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1,
                            ((*(u32 *)((u8 *)param_0 + 0x70) << 22) >> 26) - 1)),
                        func_80103EAC(param_0));
                    func_800EF04C(param_0->position, local_8);
                    param_0->position[1] = func_80800CC0_chquicksandbaddy(param_0);
                    param_0->unk74_30 = 0;
                    param_0->unk79_4 = 0;
                    break;
                } else {
                    ((QS78 *)param_0)->f4 += 1;
                    param_0->unk74_30 = (s32)param_0->unk74_30 & 1;
                }
            }
        }
        func_80103014(param_0);
        break;
    }
    case 4:
        func_800F4F34(func_800F54E4(), param_0->position,
            param_0->scale * 50.0f, param_0->scale * 150.0f);
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position,
            D_80801300_chquicksandbaddy, D_80801310_chquicksandbaddy);
        if (func_80101E14(param_0, 0.6f)) {
            func_800C4140(0x7FFB5DB2, param_0->position, 0x0BB80190);
        } else if (func_80101E14(param_0, 0.69f)) {
            func_800C4140(0x797B5DB2, param_0->position, 0x0BB80190);
        } else if (func_80101E14(param_0, 0.78f)) {
            func_800C4140(0x731B5DB2, param_0->position, 0x0BB80190);
        } else if (func_80101E14(param_0, 0.87f)) {
            func_800C4140(0x6CBB5DB2, param_0->position, 0x0BB80190);
        }
        if (func_80101DDC(param_0)) {
            ((f32 *)param_0->actorData)[4] = func_800DC178(20.0f, 30.0f);
            func_80102424(param_0, 1);
            _subaddieDll_entrypoint_4(param_0, 0);
            param_0->unk58 = 0.2f;
        }
        break;
    case 5: {
        QuicksandSoundEvent *local_10;
        ((f32 *)param_0->actorData)[4] = param_0->unk58;
        func_800D91B8(&param_0->unk58);
        local_10 = D_80801320_chquicksandbaddy; do { /* agV31: init and do on ONE line (as1 line priority: end address first) */
            if (local_10->local_0 < param_0->unk58 &&
                ((f32 *)param_0->actorData)[4] <= local_10->local_0) {
                if (local_10->local_1 == -1.0f) {
                    func_800F7B9C(func_800F54E4(), 0x26);
                } else if (local_10->local_1 == -2.0f) {
                    func_800FC660(0xB);
                } else {
                    f32 local_11 = local_10->local_1;
                    func_800C4140(((u16)(u32)(local_11 * 1023.0f) << 21) + 0x1B5DB2,
                        param_0->position, 0x0BB80190);
                }
                break;
            }
            local_10++;
        } while (local_10 != (QuicksandSoundEvent *)D_80801370_chquicksandbaddy);
        break;
    }
    case 6:
        if (func_80101E14(param_0, 0.09f)) {
            func_80101EE4(param_0, 0.91f);
            func_80102424(param_0, 7);
        }
        break;
    case 7:
        if (func_80101DDC(param_0)) {
            ((f32 *)param_0->actorData)[4] = func_800DC178(20.0f, 30.0f);
            func_80102424(param_0, 1);
        }
        break;
    }

    if (D_808012A0_chquicksandbaddy[param_0->unk70_10].local_1 == 0x1E4) {
        param_0->unk64_16 = 1;
        if (func_80101E14(param_0, 0.07f) || func_80101E14(param_0, 0.92f)) {
            f32 local_7;
            local_7 = func_800C6920(param_0->position, 500.0f, -500.0f, 0)
                + param_0->unk54;
            func_80800FC8_chquicksandbaddy(param_0->position, local_7, 5);
            param_0->position[1] = local_7;
            chquicksandbaddy_entrypoint_0(0, param_0->position);
        } else if (func_80101F24(param_0) > 0.2f &&
                   func_80101F24(param_0) < 0.55f && func_800DC0C0() < 0.5f) {
            f32 local_1[3];
            _subaddieskeleton_entrypoint_0(param_0, 0x4D, local_1);
            func_80800FC8_chquicksandbaddy(local_1,
                func_800C6920(local_1, 500.0f, -500.0f, 0) + param_0->unk54, 1);
        }
    } else {
        param_0->unk64_16 = 0;
    }
}

f32 func_80800CC0_chquicksandbaddy(Actor *param_0)
{
    f32 local_0;

    local_0 = func_800C6920(param_0->position, 500.0f, -500.0f, 0) + param_0->unk54;
    return local_0;
}

s32 func_80800CFC_chquicksandbaddy(param_0, param_1, param_2) Actor *param_0; f32 *param_1; f32 *param_2;
{
    f32 local_0[3];

    if (!param_0->unk64_20) return 0;
    if (func_800EEB40(param_1, param_2) > 4000000.0f) return 0;
    if (mlAbsF(param_2[1] - param_1[1]) > 500.0f) return 0;
    if (func_800C6A7C(param_1, param_2, local_0, 0)) return 0;
    return 1;
}

s32 func_80800DBC_chquicksandbaddy(Actor *param_0)
{
    f32 local_0[3];
    Actor *local_1[20];
    s32 local_2;
    s32 local_3;
    Actor **local_4;
    f32 local_5;

    if (!func_8010C500()) return 0;
    if (func_800F55D0(func_800F54E4())) return 0;
    if (!func_800F6E00(func_800F54E4())) return 0;
    if (!func_800F6C5C(func_800F54E4())) return 0;
    local_2 = _subaddiefind_entrypoint_4(0x1EF, local_1, 20);
    func_800F5A00(func_800F54E4(), local_0);
    local_3 = 0;
    if (local_2 > 0) {
        local_4 = local_1;
        do {
            if (param_0 != *local_4 && (*(u32 *)((u8 *)param_0 + 0x70) >> 25) == (*(u32 *)((u8 *)*local_4 + 0x70) >> 25)) {
                local_5 = func_800EEB40(local_0, param_0->position);
                if (func_800EEB40(local_0, (*local_4)->position) < local_5) return 0;
            }
            local_3++;
            local_4++;
        } while (local_3 != local_2);
    }
    return func_800D90A4(&param_0->unk58) == 0;
}

void chquicksandbaddy_entrypoint_0(s32 param_0, f32 *param_1)
{
    s32 local_0;
    if (func_800DC0C0() < 0.75f && func_808010A0_chquicksandbaddy(D_80801390_chquicksandbaddy) && func_8001210C(3)) {
        local_0 = func_800B53A4(1);
        func_800BABB8(local_0, param_1, NULL, 2.0f, D_80801370_chquicksandbaddy);
        func_800BAB80(local_0, D_80801390_chquicksandbaddy);
        func_800BA22C(local_0, 1);
    }
}

void func_80800FC8_chquicksandbaddy(s32 param_0, f32 param_1, s32 param_2) {
    s32 temp_v0;

    if (func_808010A0_chquicksandbaddy(&D_808013D4_chquicksandbaddy) != 0) {
        temp_v0 = func_800B53A4(param_2);
        func_800BABB8(temp_v0, param_0, param_0, 1.0f, &D_80801394_chquicksandbaddy);
        if (param_2 >= 2) {
            func_800BA714(temp_v0, 0x32, 0x64);
        }
        func_800BAB80(temp_v0, &D_808013D4_chquicksandbaddy);
        func_800BA4D0(temp_v0, (s16) (s32) param_1);
        func_800BA544(temp_v0, &_chquicksandbaddy_entrypoint_0);
        func_800BA22C(temp_v0, param_2);
    }
}

int func_808010A0_chquicksandbaddy(param_0) Gtexture *param_0;
{
  s32 local_0;
  u8 local_1 = 0xB4;
  switch (func_800EA05C())
  {
    case 0xB9 :
    case 0xC4 :
      (*(u8 *)((char *)(param_0) + 0x0)) = 0xC8;
      (*(u8 *)((char *)(param_0) + 0x1)) = 0xA0;
      (*(u8 *)((char *)(param_0) + 0x2)) = 0x32;
      return 1;

    case 0x100 :
    case 0x10F :
    case 0x15C :
      (*(u8 *)((char *)(param_0) + 0x0)) = local_1;
      (*(u8 *)((char *)(param_0) + 0x1)) = local_1;
      (*(u8 *)((char *)(param_0) + 0x2)) = local_1;
      return 1;

    case 0x106 :
      (*(u8 *)((char *)(param_0) + 0x0)) = 0x32;
      (*(u8 *)((char *)(param_0) + 0x1)) = 0xA0;
      (*(u8 *)((char *)(param_0) + 0x2)) = 0x32;
      return 1;

    default :
      return 0;
  }
}

int func_80801154_chquicksandbaddy(Actor *param_0, f32 *param_1)
{
    f32 (*local_0[1])[3]; /* one-element array: memory-resident holder (store stays at its statement, not coalesced with the call result) */
    void *local_6;
    f32 *local_1;
    f32 local_2;
    f32 local_3;
    s32 local_4;
    s32 local_5;

    local_6 = func_80100094(param_0, 1);
    if (local_6) {
        local_5 = -1;
        local_2 = 0.0f;
        local_4 = 0;
        local_1 = local_6;
        local_0[0] = local_6;
        for (; local_4 != 3; local_4++, local_1 += 3) {
            if (1) {} /* PROBE (from hm draft): empty block at loop-body start, load-bearing */
            if (!func_800EEF24(local_1)) {
                break;
            }
            if (local_5 != -1) {
                local_3 = func_800EEB40(param_0->position, local_1);
                if (local_3 < local_2) {
                    local_2 = local_3;
                    local_5 = local_4;
                }
            } else {
                local_2 = func_800EEB40(param_0->position, local_1);
                local_5 = local_4;
            }
        }
        if (local_5 != -1) {
            func_800EE7F8(param_1, local_0[0][local_5]);
        }
        return local_5;
    }
    return -1;
}

int *chquicksandbaddy_entrypoint_1()
{
    return &D_808013D8_chquicksandbaddy;
}
