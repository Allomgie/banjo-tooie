#include "common.h"

extern void *D_80801200_chfirefx;
extern int D_80801248_chfirefx;
typedef struct { u8 pad_0[0x74]; u32 pad_1 : 25; u32 local_0 : 1; u32 pad_2 : 6; } FireFxSpawnFlags;
extern void *func_80100094(Actor *, u32);
typedef struct { u8 pad0[0x14]; u16 unk14; u16 unk16; } FireFxData_80800AA8_chfirefx;
extern s16 D_80801290_chfirefx[];
extern s32 func_800DA298(s32);
extern void func_8010D640(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 func_800C4350(u8, f32 *, s16 *);
extern void func_800C3584(u8, f32, f32);
extern void func_800C3BDC();
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern Actor *_subaddielink_entrypoint_4(void *);
typedef struct { s32 local_0; s32 local_1; struct { u32 local_0[2]; } local_2[16]; } FireFxResetLinks;
typedef struct { s32 unk0; s32 unk4; s32 unk8[1][2]; } FireFxLocal;
extern void func_80103110(Actor *, s32);
extern void func_8010D254(f32 *);
typedef struct { s32 unused; s32 count; u32 links[1][2]; } FireFxLinks;
extern void _subaddielink_entrypoint_1();
extern void *func_80100074(Actor *, s32, s32);
typedef struct { u8 pad_0[4]; f32 local_0; s16 local_1; s16 local_2; s16 local_3; s16 local_4; s16 local_5; s16 local_6; u16 local_7; u16 local_8; void *local_9[2]; } FireEffectState961;
typedef struct { f32 unk0; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s32 unk10; } FirePart;
typedef struct { u8 pad0[4]; f32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 padE; u16 unk10; s16 unk12; u8 pad14[0xC]; FirePart parts[1]; } FireData;
extern s32 func_800F54E4(void);
extern u8 func_800D9078(f32*);
extern s32 func_800F6438(s32);
extern s32 func_800F6AA4(s32);
extern s32 func_800F6478(s32);
extern s32 func_8010CEF8(Actor *, s32);
extern s32 func_800F7B9C(s32, s32);
extern void _chhotwaterpoolbits_entrypoint_5(Actor *, f32);
extern f32 func_800D8FF8(void);
extern void rare_memcpy(void *, void *, s32);
extern void func_800EE88C();
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800E2588();
extern void func_800E2594();
extern void func_800E2A14();
extern f32 func_800F0E00(f32, f32);
extern s32 func_800E3E8C(f32 *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
typedef struct { f32 local_0; s16 local_1; s16 local_2; s16 local_3[3]; s16 local_4; f32 local_5; } FireParticle48;
typedef struct { u8 pad0[4]; f32 unk4; s16 count; s16 max; u8 padC[2]; s16 unkE; u8 pad10[2]; s16 unk12; u8 pad14[0xC]; FireParticle48 particles[1]; } FireFxData_80800884_chfirefx;
extern void func_800EE940();
extern u8 D_808012A8_chfirefx[];
extern s32 func_800C8A98(void);
extern void func_800C8E54(s32, f32, f32);
extern s32 func_800F2F60(s32 *, s32 *, f32);
extern s32 func_8010CAC0(f32 *, s32);
extern s32 _subaddiezone_entrypoint_1(Actor *);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
typedef struct { u32 pad_0 : 26; u32 local_0 : 1; u32 pad_1 : 5; } Broad51FireFlags;
void func_8080116C_chfirefx();
void chfirefx_entrypoint_2(Actor *param_0, f32 param_1, f32 param_2, s32 param_3, s32 param_4);
s32 func_80800884_chfirefx();
void func_80800C18_chfirefx();

int chfirefx_entrypoint_0()
{
  return &D_80801200_chfirefx;
}

int chfirefx_entrypoint_1()
{
    return &D_80801248_chfirefx;
}

void func_80800018_chfirefx(Actor *param_0)
{
    s32 local_0;
    local_0 = 0xD;
    if (((FireFxSpawnFlags *)param_0)->local_0) {
        local_0 = 0x2D;
    }
    ((FireFxSpawnFlags *)param_0)->local_0 = 0;
    chfirefx_entrypoint_2(param_0, param_0->scale, (f32)param_0->unk74_7,
        (s32)param_0->rotation[1], local_0);
}

void chfirefx_entrypoint_2(Actor *param_0, f32 param_1, f32 param_2, s32 param_3, s32 param_4)
{
    FireEffectState961 *local_0;
    Actor *local_1;

    local_0 = func_80100074(param_0, 0, param_3 * 0x14 + 0x20);
    local_0->local_3 = param_3;
    local_0->local_1 = 0;
    local_0->local_2 = local_0->local_1;
    local_0->local_4 = 0;
    local_0->local_0 = param_1;
    local_0->local_5 = param_4;
    local_0->local_6 = (s32)param_2;
    local_0->local_7 = (u32)(param_1 * 150.0f);
    local_0->local_8 = (u32)(param_1 * 850.0f);
    if ((param_4 & 8) && param_2 <= 70.0f) {
        local_0->local_4 = 1;
    }
    if (param_4 & 0x10) {
        local_0->local_4 = 1;
    }
    local_1 = _subaddiefind_entrypoint_2(0x289, 0);
    _subaddielink_entrypoint_1(local_0->local_9, local_1 != NULL ? local_1->unk0 : NULL);
    param_0->unk64_20 = func_800EA05C() == 0xED;
}

void func_80800E9C_chfirefx();

void chfirefx_entrypoint_3(Actor *param_0)
{
    s32 local_2;
    FireData *local_0;
    s32 local_1;
    f32 dt;
    f32 local_3[2];
    FirePart *local_6;
    f32 local_7;
    FirePart *local_10;
    u32 k0 = 2; /* constant holder (from hm): keeps 2 in s1 like target; s32 or literal 2 = worse */
    f32 local_8[1];
    f32 local_9[3];

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800F54E4();
    func_800D9078(&param_0->unk58);
    switch (param_0->unk70_10) {
    case 2:
        local_0->unkA += 2;
        if (local_0->unkA >= local_0->unkC) {
            local_0->unkA = local_0->unkC;
        }
        if ((local_0->unk10 & 4) && func_800F6438(local_1) && !func_800F6AA4(local_1) && func_800F6478(local_1) && func_8010CEF8(param_0, local_0->unk12) && k0 == func_800F7B9C(local_1, 0x51)) {
            _chhotwaterpoolbits_entrypoint_5(param_0, 0.75f);
        }
        break;
    case 1:
        local_0->unkA -= 2;
        if (local_0->unkA < 0) {
            local_0->unkA = 0;
        }
        break;
    }
    if (func_80800884_chfirefx(param_0)) {
        dt = func_800D8FF8();
        local_7 = local_0->unk4 * dt;
        local_3[1] = local_7 * 50.0f;
        local_3[0] = local_7 * 400.0f;
        local_6 = local_10 = local_0->parts;
        for (local_2 = 0; local_2 < local_0->unk8;) {
            if (1) {} /* PROBE (from hm): needed, without = 31 */
            local_6->unk0 += dt * 15.0f;
            if ((s32)local_6->unk0 >= 9) {
                local_0->unk8--;
                if (local_0->unk8 > 0) {
                    rare_memcpy(local_6, &local_10[local_0->unk8], 0x14);
                }
                continue;
            } else {
                local_6->unk4 += local_3[0];
                local_6->unkA += dt * local_6->unk4;
                func_800EE88C(local_8, &local_6->unk8);
                func_800EF04C(local_8, param_0->position);
                if ((0.4f * local_0->unk12) * (0.4f * local_0->unk12) < func_800EFC7C(local_8, param_0->position)) {
                    func_800EFB24(local_9, param_0->position, local_8);
                    local_9[1] = 0.0f;
                    func_800EF368(local_9, local_3[1]);
                    local_6->unk8 += local_9[0];
                    local_6->unkC += local_9[2];
                }
                local_6++;
                local_2++;
            }
        }
    }
    if (local_0->unk10 & 1) {
        func_80800C18_chfirefx(param_0);
    }
    func_80800E9C_chfirefx(param_0);
}

void chfirefx_entrypoint_4(Actor *param_0, s32 param_1)
{
    f32 local_2;
    u8 *local_3;
    u8 *local_4;
    f32 *local_5;
    f32 local_0[3];
    f32 local_1[3];
    s32 local_6;
    s32 local_7;
    local_3 = func_80100094(param_0, 0);
    local_5 = param_0->position;
    if (!func_800E3E8C(local_5, (func_800F0E00(75.0f, *(s16 *)(local_3 + 0x12)) * 2.5f) * 0.6f)) { return; }
    param_0->unk7C_12 = 1;
    if (*(s16 *)(local_3 + 8)) {
        local_4 = local_3 + 0x20;
        local_7 = func_800D674C(0x9CE);
        func_800E2588(1);
        func_800E2594(param_1, local_7);
        func_800E24D8(1);
        for (local_6 = 0; local_6 < *(s16 *)(local_3 + 8); local_6++, local_4 += 0x14) {
            local_2 = (*(f32 *)(local_3 + 4) * *(f32 *)(local_4 + 0x10)) * 0.5f;
            func_800EE88C(local_0, local_4 + 8);
            func_800EF04C(local_0, local_5);
            func_800EFA4C(local_1, local_2, local_2, local_2);
            func_800E2720(param_1, (s32)*(f32 *)local_4, *(s16 *)(local_4 + 6), local_0, local_1, 0xC0);
        }
        func_800E2A14(param_1);
    }
}

s32 chfirefx_entrypoint_5(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;

    switch (param_1) {
    case 0x95:
        local_0 = func_80100094(param_0, 0);
        _subaddielink_entrypoint_3(local_0 + 0x18);
        *(s32 *)local_0 = 0;
        if (*(u16 *)(local_0 + 0x10) & 1) {
            func_80800C18_chfirefx(param_0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void chfirefx_entrypoint_6(param_0, param_1, param_2) s32 param_0; s16 param_1; s16 param_2; {
    u8 *local_0 = func_80100094(param_0, 0);
    *(s16 *)(local_0 + 0x14) = param_1;
    *(s16 *)(local_0 + 0x16) = param_2;
}

s32 func_80800884_chfirefx(param_0) Actor *param_0;
{
    FireFxData_80800884_chfirefx *local_2;
    FireParticle48 *local_3;
    f32 local_0[3];
    s32 local_1[3];
    s32 local_4;
    f32 local_5;
    f32 local_6;

    local_2 = func_80100094(param_0, 0);
    local_4 = 0;
    if (local_2->count >= local_2->max) {
        return 1;
    }
    if (local_2->unkE == 1) {
        if (param_0->unk58 != 0.0f) {
            return 1;
        }
        param_0->unk58 = 0.06f;
    }
    func_800E3980(local_0);
    if (1) {}
    while (local_2->count < local_2->max && local_4 < 2) {
        local_3 = &local_2->particles[local_2->count];
        local_3->local_0 = 0.0f;
        local_3->local_1 = (s32) (local_2->unk4 * func_800DC128(30, 40));
        local_3->local_5 = func_800DC178(0.8f, 1.2f);
        local_3->local_2 = func_800DC298(0.5f);
        local_5 = func_800F1DF4(param_0->position, local_0);
        local_6 = func_800DC178(-90.0f, 90.0f);
        func_800EEB9C((f32 *)local_1, local_6 + local_5, func_800DC178(local_2->unk12 * 0.25f, local_2->unk12));
        func_800EE940(local_3->local_3, local_1);
        (local_2->count)++;
        local_4++;
    }
    return 1;
}

void func_80800AA8_chfirefx(Actor *param_0)
{
    FireFxData_80800AA8_chfirefx *local_0;
    f32 local_1[3];
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_2 = (param_0->unk70_10 == 2);
    if (param_0->unk64_20) {
        local_2 &= (func_800DA298(0) == 0);
    }
    func_8010D640(local_1);
    if (local_2 && (f32)(local_0->unk16 * local_0->unk16) < func_800EEB40(local_1, param_0->position)) {
        local_2 = 0;
    }
    if (local_2) {
        if (param_0->unk5F == 0) {
            param_0->unk5F = func_800C4350(param_0->unk5F, param_0->position, D_80801290_chfirefx);
        }
        if (param_0->unk5F) {
            func_800C4350(param_0->unk5F, param_0->position, NULL);
            func_800C3584(param_0->unk5F, (f32)(u32)local_0->unk14, (f32)(u32)local_0->unk16);
            func_800C3BDC(param_0->unk5F);
        }
    } else {
        _subaddieaudioloop_entrypoint_2(param_0);
    }
}

void func_80800C18_chfirefx(param_0) Actor *param_0;
{
    u8 *local_6;
    f32 local_0[3];
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4[3];

    local_6 = func_80100094(param_0, 0);
    local_1 = 0;
    if (*(s16 *)(local_6 + 8) == 0) {
        if (*(s32 *)local_6) {
            *(s32 *)local_6 = _chlightfader_entrypoint_1(*(s32 *)local_6, 1.6f, 1);
        }
    } else {
        if (*(s32 *)local_6 == 0) {
            local_3 = 9;
            *(s32 *)local_6 = func_800C8A98();
            if (!(*(u16 *)(local_6 + 0x10) & 0x20)) {
                local_3 = 11;
            }
            func_800C8F64(*(s32 *)local_6, local_3);
            func_800C8E54(*(s32 *)local_6, func_800F0E00(75.0f, *(s16 *)(local_6 + 0x12)) * 2.5f, (func_800F0E00(75.0f, *(s16 *)(local_6 + 0x12)) * 2.5f) * 3.0f);
            func_800EE7F8(local_0, param_0->position);
            local_0[1] += *(s16 *)(local_6 + 0x12) * 0.4f;
            func_800C8CB8(*(s32 *)local_6, local_0);
            local_1 = 1;
        }
        local_2 = ((*(u32 *)((u8 *)param_0 + 0x7C) << 19) >> 31) || func_8010CAC0(param_0->position, (s32)((func_800F0E00(75.0f, *(s16 *)(local_6 + 0x12)) * 2.5f) * 3.0f));
        if (*((u8 *)param_0 + 0x78)) {
            if (!_subaddiezone_entrypoint_1(param_0)) {
                local_2 = 0;
            }
        }
        if (local_1 || local_2) {
            if (!((Broad51FireFlags *)((u8 *)param_0 + 0x74))->local_0) {
                func_800EE7F8(local_0, param_0->position);
                local_0[1] += *(s16 *)(local_6 + 0x12) * 0.4f;
                func_800C8CB8(*(s32 *)local_6, local_0);
            }
            func_800F2F60(local_4, (s32 *)D_808012A8_chfirefx, func_800DC178(0.8f, 1.0f));
            func_800C8E84(*(s32 *)local_6, local_4);
        }
    }
}

void func_80800E9C_chfirefx(Actor *param_0)
{
    Actor *local_0;

    local_0 = _subaddielink_entrypoint_4((u8 *)func_80100094(param_0, 0) + 0x18);
    if (local_0 == NULL || param_0->unk70_10 != 2) {
        func_80800AA8_chfirefx(param_0);
    } else {
        func_8080116C_chfirefx(local_0, param_0);
    }
}

void func_80800F00_chfirefx(Actor *param_0)
{
    FireFxResetLinks *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 16; local_1++) {
        _subaddielink_entrypoint_0(&local_0->local_2[local_1]);
    }
    local_0->local_1 = 0;
    local_0->local_0 = (s32)param_0->rotation[1];
}

void func_80800F7C_chfirefx(Actor *this)
{
    Actor *list[16];
    s32 i;
    s32 j;
    s32 n;
    f32 dist[16];
    f32 c[3];
    FireFxLocal *local;
    f32 tf;
    Actor *ta;

    local = func_80100094(this, 0);
    for (i = 0, n = 0; i < local->unk4; i++) {
        list[n] = _subaddielink_entrypoint_4(local->unk8[i]);
        if (list[n] != NULL) {
            n++;
        }
    }
    func_80103110(this, 0);
    local->unk4 = 0;
    if (n == 0) {
        return;
    }
    if (local->unk0 >= n) {
        for (i = 0; i < n; i++) {
            func_80800AA8_chfirefx(list[i]);
        }
        return;
    }
    func_8010D254(c);
    for (i = 0; i < n; i++) {
        dist[i] = func_800EEB40(c, list[i]->position);
    }
    for (j = 1; j < n; j++) {
        i = j;
        while (i > 0 && dist[i] < dist[i - 1]) {
            tf = dist[i];
            dist[i] = dist[i - 1];
            dist[i - 1] = tf;
            ta = list[i];
            list[i] = list[i - 1];
            list[i - 1] = ta;
            i--;
        }
    }
    for (i = 0; i < local->unk0; i++) {
        func_80800AA8_chfirefx(list[i]);
    }
}

void func_8080116C_chfirefx(param_0, param_1) Actor *param_0; Actor *param_1;
{
    FireFxLinks *local_0;

    local_0 = func_80100094(param_0, 0);
    _subaddielink_entrypoint_1(local_0->links[local_0->count++], param_1->unk0);
    func_80103110(param_0, 1);
}
