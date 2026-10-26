#include "common.h"

extern int D_80800B20_chflamer;
extern s32 func_800BF8E4(void);
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } FlamerState;
typedef struct { f32 f0; s16 s4; s16 s6; s16 s8; s16 sA; s16 sC; s16 sE; u32 w10; } FlamerEnt;
typedef struct { s32 w0; u8 pad_4[0x12]; s16 count; s16 timer; s16 pad_1A; FlamerEnt ent[1]; } FlamerRec;
extern f32 func_80103F38(void *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
typedef union { s32 word; void *pointer; } FlamerEvent;
extern void *func_80100094(Actor *, u32);
typedef struct { u8 pad_0[0x74]; u32 pad_1:7; u32 local_0:1; u32 pad_2:24; } FlamerActorFlags;
extern void _chflamer_entrypoint_2(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_801084B0(s32, Actor **);
extern f32 func_800DC178(f32, f32);
extern void _subaddielink_entrypoint_0();
typedef struct { u8 pad_0[0x16]; s16 current; s16 target; u8 pad_1[0x192]; s32 volume; } FlamerVolume29;
extern s32 _subaddievolume_entrypoint_0(void *, f32 (*)[3], s32, s32, s32 *);
extern s32 D_80800B68_chflamer;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EE88C();
extern void func_800EF04C(f32 *, f32 *);
typedef struct { f32 local_0; s16 local_1; s16 local_2; s16 local_3[3]; s16 local_4; f32 local_5; } FlamerPart37;
typedef struct { f32 local_0; s16 local_1; s16 local_2; f32 local_3[2]; f32 local_4; } FlamerParticle;
typedef struct { u8 pad_0[0x16]; s16 local_0; s16 local_1; u16 pad_1; FlamerParticle local_2[1]; } FlamerParticles;
extern s32 func_800DC298(f32);
extern u8 D_80800B7C_chflamer[];
extern s32 func_800E3E8C(f32 *, f32);
extern void func_800F2F60(s32 *, void *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800C8E54(s32, f32, f32);
s32 func_80800594_chflamer(Actor *param_0, s32 param_1, FlamerEvent param_2);
void func_80800738_chflamer();
s32 func_808007A8_chflamer();
void func_8080098C_chflamer();
void func_80800434_chflamer();
void func_808008C0_chflamer();
void func_808009C0_chflamer();
extern void func_80105834(), func_80107C2C(), func_8080000C_chflamer(), func_80800434_chflamer();

int chflamer_entrypoint_0()
{
  return &D_80800B20_chflamer;
}

void func_8080000C_chflamer(param_0) s32 param_0; {
    u8 *local_0 = func_80100094(param_0, 0);
    *(s16 *)(local_0 + 0x16) = 0;
    *(s16 *)(local_0 + 0x18) = 0;
    *(s32 *)(local_0 + 0x1AC) = 0;
    if (func_800BF8E4() > 0) {
        *(s16 *)(local_0 + 4) = 400;
    }
}

void func_80800050_chflamer(Actor *param_0)
{
    FlamerRec *local_0;
    u8 *local_1;
    s32 local_7;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    FlamerEnt *local_8;
    f32 local_6[3];
    f32 local_5[3];

    local_0 = func_80100094(param_0, 0);
    local_1 = _subaddielink_entrypoint_4((u8 *)local_0 + 0x1B4);
    if (local_1 != 0 && !func_801072A8(local_1)) {
        *(f32 *)((u8 *)local_0 + 0x1B0) = func_80103F38(local_1, 0);
        func_800EE7F8(param_0->position, (f32 *)(local_1 + 4));
        func_800EE7F8(param_0->rotation, (f32 *)(local_1 + 0x44));
        param_0->scale = *(f32 *)(local_1 + 0x38);
    }
    func_8080098C_chflamer(param_0);
    if (1) {}
    switch (((FlamerState *)param_0)->st) {
    case 1:
        if (local_1 == 0 || !(local_1[0x74] & 1)) {
            func_80800738_chflamer(param_0);
            local_1 = 0;
        }
        local_0->timer += 2;
        if (local_0->timer >= 0x14) {
            local_0->timer = 0x14;
            param_0->unk70_10 = 2;
        }
        break;
    case 2:
        if (func_800D9078(&param_0->unk58) || local_1 == 0 || !(local_1[0x74] & 1)) {
            func_80800738_chflamer(param_0);
            local_1 = 0;
        }
        break;
    case 3:
        local_0->timer -= 1;
        if (local_0->timer <= 0) {
            local_0->timer = 0;
            if (local_0->count == 0) {
                if (func_800BF8E4() > 0) {
                    local_0->w0 = _chlightfader_entrypoint_1(local_0->w0, 1.0f, 2);
                }
                func_800FFA88(param_0->unk0);
                return;
            }
        }
        break;
    }
    if (func_808007A8_chflamer(param_0, local_1)) {
        local_2 = func_800D8FF8();
        local_8 = local_0->ent;
        local_3 = local_2 * 50.0f;
        local_4 = local_2 * 300.0f;
        for (local_7 = 0; local_7 < local_0->count;) {
            {
                local_8->f0 += local_2 * 15.0f;
                if ((s32)local_8->f0 >= 9) {
                    local_0->count -= 1;
                    if (local_0->count > 0) {
                        rare_memcpy(local_8, &local_0->ent[local_0->count], 0x14);
                    }
                    continue;
                } else {
                    local_8->s4 += local_4;
                    local_8->sA += local_2 * local_8->s4;
                    func_800EE88C(local_6, &local_8->s8);
                    func_800EF04C(local_6, param_0->position);
                    if (func_800EFC7C(local_6, param_0->position) > 1600.0f) {
                        func_800EFB24(local_5, param_0->position, local_6);
                        local_5[1] = 0.0f;
                        func_800EF368(local_5, local_3);
                        local_8->s8 += local_5[0];
                        local_8->sC += local_5[2];
                    }
                    local_8++;
                    local_7++;
                }
            }
        }
    }
    if (func_800BF8E4() > 0) {
        func_808009C0_chflamer(param_0, local_1);
    }
}

void func_80800434_chflamer(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0 = func_80100094(param_0, 0);
    s32 local_1 = func_800D674C(0x9CE);
    f32 local_2;
    f32 local_3;
    FlamerPart37 *local_6;
    Vec3f local_4;
    Vec3f local_5;
    s32 local_7;

    func_800E2588(1);
    func_800E2594(param_1, local_1);
    local_2 = func_800F10B4(*(f32 *)(local_0 + 0x1B0), 50.0f, 200.0f, 0.6f, 1.6f) * 0.5f;
    local_6 = (FlamerPart37 *)(local_0 + 0x1C);
    for (local_7 = 0; local_7 < *(s16 *)(local_0 + 0x16); local_7++, local_6++) {
        local_3 = local_6->local_5 * local_2;
        func_800EE88C(local_4.f, local_6->local_3);
        func_800EF04C(local_4.f, param_0->position);
        func_800EFA4C(local_5.f, local_3, local_3, local_3);
        func_800E2720(param_1, (s32)local_6->local_0, local_6->local_2, local_4.f, local_5.f, 0xC0);
    }
    func_800E2A14(param_1);
}

s32 func_80800594_chflamer(Actor *param_0, s32 param_1, FlamerEvent param_2)
{
    u8 *local_0;

    switch (param_1) {
    case 0x95:
        local_0 = func_80100094(param_0, 0);
        _subaddielink_entrypoint_3(local_0 + 0x1B4);
        if (func_800BF8E4() > 0) {
            *(s32 *)local_0 = func_800C8A98();
            local_0[0x14] = 0;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void chflamer_entrypoint_1(Actor *param_0, void *param_1)
{
    if (!param_0->unk64_17 && !((FlamerActorFlags *)param_0)->local_0) {
        if (param_1) {
            if (*(u16 *)((u8 *)param_1 + 0x18) & 1) func_8010114C(param_1, 0x92, 0);
        }
        ((FlamerActorFlags *)param_0)->local_0 = 1;
        func_8010108C(param_0, 0x2B, 1);
        _chbaddiesetup_entrypoint_2(_chflamer_entrypoint_2, param_0->unk0, 0);
    }
}

void chflamer_entrypoint_2(Unk80132ED0 *param_0, s32 param_1)
{
    Actor *local_0;
    Actor *local_1;
    u8 *local_2;
    local_0 = func_80106790(param_0);
    if (!local_0->unk64_17) {
        local_1 = func_801084B0(0x3A2, &local_0);
        if (local_1) {
            local_2 = func_80100094(local_1, 0);
            _subaddielink_entrypoint_1(local_2 + 0x1B4, param_0);
            local_1->unk58 = func_800DC178(4.0f, 6.0f);
            local_1->unk70_10 = 1;
        }
    }
}

void func_80800738_chflamer(param_0) Actor *param_0;
{
    u8 *local_0;
    Actor *local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = (Actor *)_subaddielink_entrypoint_4(local_0 + 0x1B4);
    if (local_1 != 0) {
        *(u8 *)((u8 *)local_1 + 0x74) &= ~1;
        func_8010108C(local_1, 0x2B, 0);
    }
    _subaddielink_entrypoint_0(local_0 + 0x1B4);
    *(u8 *)((u8 *)param_0 + 0x72) = (*(u8 *)((u8 *)param_0 + 0x72) & 0xFF03) | 0xC;
}

s32 func_808007A8_chflamer(param_0, param_1) Actor *param_0; void *param_1;
{
    f32 local_1[20][3];
    FlamerVolume29 *local_0;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    local_0 = func_80100094(param_0, 0);
    local_4 = 0;
    if (local_0->current >= local_0->target) return 1;
    while (local_0->current < local_0->target) {
        local_2 = _subaddievolume_entrypoint_0(param_1, local_1, 2, func_800F1418(20, local_0->target - local_0->current), &local_0->volume);
        if (local_2 >= 0) local_4++;
        if (local_2 <= 0) break;
        for (local_3 = 0; local_3 < local_2; local_3++) func_808008C0_chflamer(param_0, local_1[local_3]);
    }
    return local_4;
}

void func_808008C0_chflamer(param_0, param_1) Actor *param_0; f32 param_1[3];
{
    FlamerParticles *local_0;
    FlamerParticle *local_1;

    local_0 = func_80100094(param_0, 0);
    if (local_0->local_0 < local_0->local_1) {
        local_1 = &local_0->local_2[local_0->local_0];
        local_1->local_0 = 0.0f;
        local_1->local_1 = func_800DC128(30, 40);
        local_1->local_4 = func_800DC178(0.8f, 1.2f);
        local_1->local_2 = func_800DC298(0.5f);
        func_800EF3DC(param_1, param_0->position);
        func_800EE940(local_1->local_3, param_1);
        local_0->local_0++;
    }
}

void func_8080098C_chflamer(param_0) s32 param_0;
{
    _subaddieaudioloop_entrypoint_5(param_0, param_0 + 4, 1, -1, &D_80800B68_chflamer);
}

void func_808009C0_chflamer(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_5;
    f32 local_0[3];
    f32 local_1;
  s32 pad0;
    s32 local_2[3];
    local_5 = func_80100094(param_0, 0);
    if (param_1) {
        local_1 = func_80103F38(param_1, local_0) * 0.75f;
        *(s16 *)(local_5 + 4) = local_1;
    } else {
        local_1 = *(s16 *)(local_5 + 4);
        func_800EE7F8(local_0, (f32 *)(local_5 + 8));
    }
    if (!local_5[0x14] || func_800E3E8C(param_0->position, 3.0f * local_1) ||
        func_800E3E8C((f32 *)(local_5 + 8), 3.0f * local_1)) {
        func_800F2F60(local_2, D_80800B7C_chflamer, func_800DC178(0.8f, 1.0f));
        func_800EE7F8((f32 *)(local_5 + 8), local_0);
        func_800C8CB8(*(s32 *)local_5, local_0);
        func_800C8E84(*(s32 *)local_5, local_2);
        func_800C8E54(*(s32 *)local_5, local_1, 3.0f * local_1);
    }
    local_5[0x14] = 1;
}
