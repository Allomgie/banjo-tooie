#include "common.h"

extern int D_80800CB0_sucoasterhit;
extern u8 *func_80106790(void *);
extern u8 *func_80100094(u8 *, s32);
extern s32 func_800D9058(f32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, s32, s32, f32, s32, s32);
typedef struct { u8 pad_0[0x78]; u32 pad_1:29; u32 local_0:1; u32 pad_2:2; } CoasterHitFlags27;
typedef struct { u8 pad_0[0x64]; u32 pad_1:2; u32 local_0:1; u32 pad_2:29; } CoasterHitActive27;
typedef struct { u8 pad_0[0x18]; u8 pad_1 : 4; u8 local_0 : 1; u8 pad_2 : 3; } CoasterHitState_80800114_sucoasterhit;
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 29; u32 local_0 : 1; u32 pad_2 : 2; } CoasterHitActor;
typedef struct { u8 pad[0x78]; u32 pad78:29; u32 flag:1; u32 rest:2; } CoasterHitState_808001C8_sucoasterhit;
extern int _sucoaster_entrypoint_9(CoasterHitState_808001C8_sucoasterhit *, s32, s32);
typedef struct { u8 pad0[0x24]; u32 kind:10; u32 rest:22; } CoasterHitMsg;
extern s32 func_800F0E28();
extern s32 D_80800CC4_sucoasterhit;
extern s32 _chbaddiesetup_entrypoint_10;
extern s32 func_80108EF4;
extern f32 func_800136E4(f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800F5F24(s32);
extern f32 func_800EEFD4(f32 *);
extern f32 func_800F1DF4(f32 *, u8 *);
extern f32 func_800EC708(void *);
extern void _chbounce_entrypoint_3(f32);
extern void _chbounce_entrypoint_2(f32);
extern void _chbounce_entrypoint_5(s32, u8 *);
extern void _chbaddiesetup_entrypoint_5(s32 *, s32, s32, f32, s32, s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void _subaddiejoy_entrypoint_10(u8 *, f32, f32);
typedef struct { u8 pad[0x19]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 rest : 5; } HitFlags;
extern u8 D_80800CE8_sucoasterhit[];
extern u8 D_80800D14_sucoasterhit[];
extern s32 _subaddievolume_entrypoint_0(void *, f32 (*)[3], s32, s32, s32 *);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_80103F38(Actor *, f32 *);
typedef struct { s16 sound; s16 volume; s16 pitch; s16 pad; } CoasterHitSoundEntry;
typedef struct { u32 header; CoasterHitSoundEntry entries[1]; } CoasterHitSoundTable;
extern s16 D_80800CDC_sucoasterhit[];
extern void func_800C31DC(u8, f32);
extern s32 func_800C4350(u8, f32 *, s16 *);
extern void func_800C301C(u8, s32);
extern void func_800C3058(u8, s32);
extern void func_800C3BDC(u8);
extern void func_800C2FDC(u8);

int sucoasterhit_entrypoint_0()
{
    return (int)&D_80800CB0_sucoasterhit;
}

void func_8080000C_sucoasterhit(Unk80132ED0 *param_0, u8 *param_1)
{
    Actor *local_1;
    u8 *local_0;

    local_1 = func_80106790(param_0);
    local_0 = func_80100094(local_1, 0);
    if (!((CoasterHitFlags27 *)local_1)->local_0 && !( *((u8 *)local_1 + 0x74) & 1)) {
        local_1->unk6C_0 = func_800D9058(2.0f);
        if (local_1->unk70_10 != 2 && local_1->unk70_10 != 9 && local_1->unk70_10 != 0xE && !((CoasterHitActive27 *)local_1)->local_0) {
            if (_sucoaster_entrypoint_9(local_1, 3, 3) && !(*(u32 *)(param_1 + 0x24) >> 22)) {
                _subaddierouteDll_entrypoint_6(local_1, local_0, local_0[0x16], 0, 1.0f, 0x46, 0x78);
            }
        }
    }
}

void func_80800114_sucoasterhit(Unk80132ED0 *param_0, Unk80132ED0 *param_1)
{
    Actor *local_0;
    CoasterHitState_80800114_sucoasterhit *local_1;

    local_0 = func_80106790(param_0);
    if (!((CoasterHitActor *)local_0)->local_0) {
        local_1 = func_80100094(local_0, 0);
        if (param_1->unk24 >> 22 == 0x27D) {
            if (local_0->unk70_10 != 0xF) _sucoaster_entrypoint_9(local_0, 0xF, 4);
            local_1->local_0 = 1;
        } else if (func_801021BC(local_0, 0xB)) {
            _sucoaster_entrypoint_9(local_0, 0xB, 4);
        }
    }
}

void func_808001C8_sucoasterhit(s32 param_0, s32 param_1) {
    CoasterHitState_808001C8_sucoasterhit *local_0 = func_80106790(param_0);
    if (!local_0->flag) {
        _sucoaster_entrypoint_9(local_0, 0xC, 5);
    }
}

s32 func_80800208_sucoasterhit(s32 param_0, CoasterHitMsg *param_1, s32 param_2, s32 *param_3, s32 *param_4)
{
    s32 local_0 = param_1->kind != 0x27D;
    s32 local_1 = param_1->kind == 0;

    if (!local_0) {
        *param_3 *= 2;
        return 7;
    }
    if (*param_4 == 0) {
        if (*param_3 != 0 || local_1) {
            *param_3 = func_800F0E28(1, *param_3, local_1);
        } else {
            *param_3 = 0;
        }
    }
    return 0;
}

void func_80800294_sucoasterhit(void *param_0, u8 *param_1, s32 param_2)
{
    u8 *sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    u8 *sp74;
    u32 sp70;
    f32 sp6C;
    f32 sp60[3];
    f32 sp54[3];
    f32 sp50;
    f32 sp4C;
    u8 *sp48;
    f32 sp3C[3];
    f32 sp34[2];
    u8 *a0;

    sp9C = func_80106790(param_0);
    sp98 = _glhittableDll_entrypoint_10(param_2);
    sp94 = _glhittableDll_entrypoint_7(param_2);
    sp90 = _glhittableDll_entrypoint_9(param_2);
    sp8C = _glhittableDll_entrypoint_6(param_2);
    sp78 = (*(u32 *)(param_1 + 0x24) >> 22) == 0;
    sp74 = func_80100094(sp9C, 0);
    if (sp78 == 0 || ((sp70 = (u32)*(u16 *)(param_1 + 0x1A) >> 5, func_800F70EC(sp70) != 0) && func_800F6C1C(sp70) != 0) || _glhittableDll_entrypoint_8(param_2) == 0) {
        sp88 = func_80800208_sucoasterhit(sp9C, param_1, &sp94, &sp90, &sp8C);
        if (sp90 != 0) {
            if (1) {}
            if (sp88 & 1) sp7C = sp90; else sp7C = 100 / sp90;
            *(u8 *)(sp9C + sp8C + 0x5C) = func_800F0E28(0, *(u8 *)(sp9C + sp8C + 0x5C) - sp7C);
            a0 = sp9C + sp8C;
            if (a0[0x5C] != 0 && !(sp88 & 1) && sp90 >= 2) {
                sp94 = sp94 / 2;
            }
            sp84 = sp8C == 2 && a0[0x5C] == 0;
            if ((sp88 & 4) && sp84 == 0) {
                sp94 = 0;
            }
            if (sp94 != 0) {
                if (_sueggmisc_entrypoint_0(param_1) != 0) {
                    sp48 = func_80106790(param_1);
                    _suegg_entrypoint_18(sp48, sp60);
                    _suegg_entrypoint_19(sp48, sp54);
                } else if (sp78 != 0) {
                    func_800F57F0((u32)*(u16 *)(param_1 + 0x1A) >> 5, sp60);
                    func_800F5D70((u32)*(u16 *)(param_1 + 0x1A) >> 5, sp54);
                    if (func_800EEFD4(sp54) < 100.0f) {
                        func_800EEB9C(sp54, func_800F5F24((u32)*(u16 *)(param_1 + 0x1A) >> 5), 200.0f);
                    }
                } else {
                    func_800EC398(param_1, sp60);
                    func_800EFD24(sp54);
                }
                sp4C = func_800F1DF4(sp60, sp9C + 4);
                if (func_800F1EA4(sp54, &sp50) == 0) {
                    sp50 = sp4C;
                }
                sp50 += func_800DC178(-30.0f, 30.0f);
                sp6C = func_800136E4(sp50);
                _chbounce_entrypoint_3(sp6C);
                _chbounce_entrypoint_2(sp6C);
                _chbounce_entrypoint_5(sp94 + 0xF, sp9C);
                *(f32 *)(sp9C + 0x54) = func_800136E4(sp6C + 180.0f);
                *(f32 *)(sp9C + 0x48) = *(f32 *)(sp9C + 0x54);
            }
            a0 = sp9C; /* Claude 28.10. (Permuter-Idee, von Hand): a0 frueh, vor sp80 */
            sp80 = (sp88 & 2) == 0 || sp84 != 0;
            if (sp80 != 0) {
                switch (sp8C) {
                    case 2:
                        func_80109600(sp9C, param_1);
                        if ((*(u32 *)(param_1 + 0x24) >> 22) == 0x26D) {
                            if (1) {}
                            _chflamer_entrypoint_1(sp9C, param_1);
                        }
                        break;
                    case 1:
                        func_80109600(sp9C, param_1);
                        if ((*(u32 *)(param_1 + 0x24) >> 22) == 0x26E) {
                            if (1) {}
                            func_800EC370(param_1, sp3C);
                            _chfreezy_entrypoint_1(sp9C, sp3C);
                        }
                        break;
                }
            }
            if (sp90 != 0 && ((u32)*(u16 *)(sp9C + 0x72) >> 10) == 9 && ((u32)(*(s32 *)(*(u8 **)sp9C + 0x18) << 11) >> 28) == 1) {
                func_8010965C(sp9C);
                ((HitFlags *)sp74)->b5 = 1;
            }
            a0 += sp8C;
            if (a0[0x5C] == 0 || sp8C != 0) {
                if (a0[0x5C] != 0) {
                    sp8C -= 1;
                    a0 -= 1;
                }
                if (sp8C != 2) {
                    a0[0x5C] = 0x63;
                }
                if (sp8C == 2 && sp98 != 0 && func_8010A430(sp9C) != 0) {
                    sp34[1] = func_800F5F24(func_800F54E4());
                    func_800EB860(&func_80108EF4, sp9C);
                    sp34[0] = *(f32 *)(sp9C + 8) + func_800EC708(param_0);
                    _chbaddiesetup_entrypoint_5(&_chbaddiesetup_entrypoint_10, sp98 + 2, *(s32 *)(sp9C + 4), sp34[0], *(s32 *)(sp9C + 0xC), *(s32 *)&sp34[1]);
                    func_800EB874();
                }
                switch (sp8C) {
                    case 0:
                        func_8080000C_sucoasterhit(*(u8 **)sp9C, param_1);
                        break;
                    case 1:
                        func_80800114_sucoasterhit(*(u8 **)sp9C, param_1);
                        break;
                    case 2:
                        func_808001C8_sucoasterhit(*(u8 **)sp9C, param_1);
                        break;
                }
            }
            if (sp80 != 0) {
                func_8010D930(1, *(s32 *)(sp9C + 0x70) & 1, sp9C + 4, &D_80800CC4_sucoasterhit);
                _subaddiejoy_entrypoint_10(sp9C, 1.0f, 0.25f);
            }
        }
    }
}

void func_80800870_sucoasterhit(Actor *param_0, u32 *param_1, s32 param_2, s32 param_3)
{
    CoasterHitSoundTable *local_0;
    f32 local_1;

    local_0 = (CoasterHitSoundTable *)_sucoasterdata_entrypoint_1(param_1[6] >> 28);
    if (local_0->entries[param_2].sound) {
        if (param_3) {
            if (!param_0->unk5F) {
                param_0->unk5F = func_800C4350(param_0->unk5F, param_0->position, D_80800CDC_sucoasterhit);
                local_1 = func_800DC178(-0.05f, 0.05f);
                local_1 += (f32)local_0->entries[param_2].pitch * 0.00390625f;
                func_800C301C(param_0->unk5F, local_0->entries[param_2].sound);
                func_800C3058(param_0->unk5F, local_0->entries[param_2].volume);
                func_800C31DC(param_0->unk5F, local_1);
            }
            if (param_0->unk5F) {
                func_800C4350(param_0->unk5F, param_0->position, 0);
                func_800C3BDC(param_0->unk5F);
            }
        } else if (param_0->unk5F) {
            func_800C2FDC(param_0->unk5F);
            param_0->unk5F = 0;
        }
    }
}

s32 func_80800AEC_sucoasterhit();

s32 sucoasterhit_entrypoint_1(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    s32 local_1_c;
    s32 local_2;
    u32 t;
    local_0 = func_80100094(param_0, 0);
    t = (*(u32 *)(local_0 + 0x18) << 4) >> 31;
    local_1 = t != 0;
    local_1_c = local_1;
    local_2 = local_1;
    if (!local_1) {
        local_2 = 0;
        if (param_0->unk58 > 0.0f) local_2 = 1;
    }
    if (local_1_c) param_0->unk58 = 0.7f;
    local_0[0x18] &= ~8;
    func_80800870_sucoasterhit(param_0, local_0, 4, local_2);
    if (!local_2) {
        func_80102190(param_0, 0);
        _sucoaster_entrypoint_9(param_0, 3, 9);
        return 1;
    }
    param_0->position[0] += func_8001210C(1) ? -10.0f : 10.0f;
    param_0->position[2] += func_8001210C(1) ? 10.0f : -10.0f;
    _sucoaster_entrypoint_22(param_0);
    func_80800AEC_sucoasterhit(param_0, local_0);
    return 0;
}

s32 func_80800AEC_sucoasterhit(Actor *param_0, u8 *param_1)
{
    f32 local_0[20][3];
    f32 local_1[3];
    s32 local_2;
    s32 local_5;
    s32 local_4;
    s32 local_3;
    local_3 = param_1[0x14];
    local_2 = _subaddievolume_entrypoint_0(param_0, local_0, 1, 5, &local_3);
    param_1[0x14] = local_3;
    if (local_2 > 0) {
        func_80103F38(param_0, local_1);
        local_4 = func_800B5BE4(0x12);
        func_800BABB8(local_4, 0, 0, 1.0f, D_80800CE8_sucoasterhit);
    }
    for (local_5 = 0; local_5 < local_2; local_5++) func_800BABB8(local_4, local_0[local_5], local_1, 1.0f, D_80800D14_sucoasterhit);
    return local_2 >= 0;
}

void sucoasterhit_entrypoint_2(s32 param_0) {
    if ((*(s32 *)((s8 *)(_sucoasterdata_entrypoint_1((u32) (*(u32 *)((s8 *)(func_80100094(param_0, 0)) + (0x18))) >> 0x1C)) + (0x44))) & 2) {
        func_800E1610(0, 0x41400000, 0x3F59999A, param_0 + 4);
        func_80018820(0, 0x3FC00000, 0x3ECCCCCD);
        _subaddiejoy_entrypoint_10(param_0, 1.5f, 0.6f);
        func_8010108C(param_0, 0xB6, 0);
    }
}
