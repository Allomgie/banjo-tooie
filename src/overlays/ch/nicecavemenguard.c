#include "ch/nicecavemenguard.h"

extern int D_80800920_chnicecavemenguard[];
extern void func_80102FDC(Actor *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_80105A9C(Actor *, f32);
extern s32 D_808009E8_chnicecavemenguard[];
extern void _subaddieaudioquick_entrypoint_3(u8 *, u8 *, void *, f32);
typedef struct {
    s32 a, b, c;
} Trip;
extern Trip D_808009F0_chnicecavemenguard;
extern s32 D_808009FC_chnicecavemenguard[];
extern void _subaddieaudioquick_entrypoint_4();
extern s32 func_800F4F34(s32, f32 *, f32, f32);
extern s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern u8 D_80800968_chnicecavemenguard[];
extern u8 D_808008C0_chnicecavemenguard[];
extern u8 D_80800978_chnicecavemenguard[];
extern u8 D_80800984_chnicecavemenguard[];
extern f32 func_80101F24(Actor *);
extern s32 D_80800990_chnicecavemenguard[];
extern s32 D_8080099C_chnicecavemenguard[];
extern s32 D_808009DC_chnicecavemenguard[];
extern s32 D_808009AC_chnicecavemenguard[];
extern f32 D_808009BC_chnicecavemenguard[];
extern s16 D_808009CC_chnicecavemenguard[];
extern s16 D_808009D4_chnicecavemenguard[];
extern f32 func_800DC178(f32, f32);
extern void func_800C31DC(u8, f32);
void func_808004FC_chnicecavemenguard();
void func_80800608_chnicecavemenguard();
extern void func_801018A4(), func_80102EC0(), func_80107C2C(), func_8080000C_chnicecavemenguard(),
    func_80800388_chnicecavemenguard();

// Oogle Boogle guard at the Terrydactyland cave entrance: blocks, talks, then walks off and sets flag 0x186.
int *chnicecavemenguard_entrypoint_0()
{
    return &D_80800920_chnicecavemenguard;
}

void func_8080000C_chnicecavemenguard(actor) Actor *actor;
{
    if (_glcutDll_entrypoint_20())
        func_80102424(actor, 6);
    else if (func_800DA298(0x186)) {
        func_800FFAB0(actor);
        return;
    }
    func_80102FDC(actor, actor->scale * 1.25f);
    func_800EE7F8((f32 *) actor->actorData, actor->position);
    func_800EF1B8((f32 *) actor->actorData, actor->rotation[1] + 180.0f, 150.0f);
    func_80105A9C(actor, 400.0f);
    func_80105BAC(actor);
}

void func_8080075C_chnicecavemenguard();

void func_80800730_chnicecavemenguard();

void func_80800600_chnicecavemenguard();

void func_808000D4_chnicecavemenguard(Actor *actor)
{
    s32 unk_0;
    f32 *pos;
    u32 state;
    unk_0 = 0;
    func_800F7B9C(func_800F54E4(), 0x7E);
    if (func_80100094(actor, 1) != 0) {
        _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
    }
    state = actor->unk70_10;
    switch (state) {
        case 1:
            unk_0 = 1;
            func_80800600_chnicecavemenguard(actor);
            if (func_800F64A4(func_800F54E4(), 0x60000) == 0) {
                _subaddiedialog_entrypoint_8(actor, actor->position,
                                             &D_80800968_chnicecavemenguard,
                                             &D_808008C0_chnicecavemenguard, 5);
            }
            state = actor->unk70_10;
            break;

        case 2:
            unk_0 = 1;
            func_80800600_chnicecavemenguard(actor);
            state = actor->unk70_10;
            break;

        case 3:
            unk_0 = 1;
            func_80800608_chnicecavemenguard(actor);
            if (func_80101DDC(actor) != 0) {
                _subaddieaudioloop_entrypoint_2(actor);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17E7, 7, actor->position, 0x96);
                func_80102424(actor, 2);
            }
            state = actor->unk70_10;
            break;

        case 4:
            func_80800730_chnicecavemenguard(actor);
            if (func_80101DDC(actor) != 0) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17E8, 4, actor->position, 0x96);
                func_80102424(actor, 5);
            }
            state = actor->unk70_10;
            break;

        case 5:
            func_8080075C_chnicecavemenguard(actor);
            func_80105854(actor);
            func_800F4F34(func_800F54E4(), actor->position, 80.0f, 100.0f);
            if (func_80105A5C(actor) != 0) {
                func_800DA544(0x186);
                _capod_entrypoint_14();
                func_800F7F98(func_800F54E4(), 0);
            }
            state = actor->unk70_10;
            break;

        case 6:
            func_80800608_chnicecavemenguard(actor);
            state = actor->unk70_10;
    }

    pos = actor->position;
    if (state != 5) {
        if (_sudeflect_entrypoint_0(pos, 100.0f, 180.0f, 0xA) & 2) {
            _sudeflect_entrypoint_4(9, pos);
        }
    }
    if ((unk_0 != 0) && (_sudeflect_entrypoint_3((f32 *) actor->actorData, actor->rotation,
                                                   &D_80800978_chnicecavemenguard,
                                                   &D_80800984_chnicecavemenguard, 2) &
                           2)) {
        _sudeflect_entrypoint_4(9, actor->position);
    }
}

void func_80800388_chnicecavemenguard(Actor *actor)
{
    func_8080080C_chnicecavemenguard(actor);
}

s32 func_808007A8_chnicecavemenguard();

s32 func_808005D4_chnicecavemenguard();

s32 func_808003A8_chnicecavemenguard(actor, msg, data)
u8 *actor;
s32 msg;
s16 data[3];
{
    s32 result;
    s16(*data_ptr)[3];
    switch (msg) {
        case 46:
            data_ptr = &data;
            func_808005D4_chnicecavemenguard(actor, *data_ptr[0], (*data_ptr)[1]);
            goto block_13;

        case 29:

        case 30:
            if ((func_800F52B8(func_800F54E4(), *(s32 **) actor) == 0x18) &&
                (((u32) (u16) *(u16 *) ((char *) actor + 0x72) >> 0xA) == 1)) {
                func_80102424(actor, 3);
            }
            goto block_13;

        case 27:
            if ((func_800F52B8(func_800F54E4(), *(s32 **) actor) == 0x17) &&
                (((u32) (u16) *(u16 *) ((char *) actor + 0x72) >> 0xA) == 1)) {
                _capod_entrypoint_13(*(s32 **) actor, 0, 6, 0x20);
                func_800F7F98(func_800F54E4(), 1);
                func_80102424(actor, 4);
            }
            goto block_13;

        case 41:
            func_808007A8_chnicecavemenguard(actor);
            goto block_13;

        case 42:
            func_8080080C_chnicecavemenguard(actor);
            goto block_13;

        case 31:
            func_808004FC_chnicecavemenguard(actor);
            goto block_13;

        default:
            return 0;
    }

block_13:
    result = 1;

    return result;
}

void func_808004FC_chnicecavemenguard(actor) Actor *actor;
{
    func_801015D0(actor);
    func_800DF744(5, 1);
    func_800DF744(6, 1);
    func_800DF744(8, 3);
    switch (actor->unk70_10) {
        case 5:
            func_800DF744(4, 0);
            func_800DF744(7, 0);
            break;
        case 4:
            if (func_80101F24(actor) > 0.26f) {
                func_800DF744(4, 0);
                func_800DF744(7, 1);
                break;
            }
        default:
            func_800DF744(4, 1);
            func_800DF744(7, 0);
    }
}

s32 func_808005D4_chnicecavemenguard(s32 actor, s32 dialog_id, s32 unk_2)
{
    if (dialog_id != 0x17E8)
        func_80102424(actor, 1);
}

void func_80800600_chnicecavemenguard(s32 arg0)
{
}

void func_80800608_chnicecavemenguard(actor) Actor *actor;
{
    s32 i;

    if (!actor->unk5F) {
        actor->unk5F = func_800C4350(0, actor->position, &D_808009DC_chnicecavemenguard);
    }
    for (i = 0; i < 4; i++) {
        if (func_80101E14(actor, D_808009AC_chnicecavemenguard[i])) {
            func_800C301C(actor->unk5F, D_808009CC_chnicecavemenguard[i]);
            func_800C31DC(actor->unk5F,
                          D_808009BC_chnicecavemenguard[i] + func_800DC178(-0.02f, 0.02f));
            func_800C3058(actor->unk5F, D_808009D4_chnicecavemenguard[i]);
            func_800C3BDC(actor->unk5F);
            break;
        }
    }
    _subaddieaudioquick_entrypoint_4(actor, actor->position, &D_80800990_chnicecavemenguard,
                                     &D_8080099C_chnicecavemenguard);
}

void func_80800730_chnicecavemenguard(u8 *actor)
{
    _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_808009E8_chnicecavemenguard, 0.0f);
}

void func_8080075C_chnicecavemenguard(u8 *actor)
{
    Trip pattern = D_808009F0_chnicecavemenguard;
    _subaddieaudioquick_entrypoint_4(actor, actor + 4, &D_808009FC_chnicecavemenguard,
                                     &pattern);
}

s32 func_808007A8_chnicecavemenguard(s32 actor)
{
    s32 expr;
    if (!func_80100094(actor, 1)) {
        _suexpression_entrypoint_7(actor, 1, 0x96);
        expr = func_80100094(actor, 1);
        _suexpression_entrypoint_12(expr, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(expr, 0x320);
    }
}

void func_8080080C_chnicecavemenguard(Actor *actor)
{
    if (func_80100094(actor, 1) != 0) {
        _suexpression_entrypoint_8(actor, 1);
    }
}

u8 D_808008C0_chnicecavemenguard[40] = {0x0,  0x0,  0x2,  0x1,  0x17, 0xE5, 0x1,  0x0, 0x0,  0x0,
                                        0x4,  0x1,  0x17, 0xE6, 0x2,  0x0,  0x0,  0x0, 0x4,  0x0,
                                        0x18, 0x1B, 0x1,  0x0,  0x0,  0x0,  0x2,  0x0, 0x18, 0x1C,
                                        0x2,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xE, 0x3,  0x0};
u8 D_808008E8_chnicecavemenguard[56] = {
    0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0xA0, 0x0,  0x0,  0x2,  0xED,
    0x0,  0x1,  0x40, 0xA0, 0x0,  0x0,  0x2,  0xED, 0x0,  0x1,  0x40, 0x80, 0x0,  0x0,
    0x2,  0xEE, 0x0,  0x2,  0x3F, 0xB3, 0x33, 0x33, 0x2,  0xEF, 0x0,  0x2,  0x3F, 0x28,
    0xF5, 0xC3, 0x2,  0xF0, 0x0,  0x1,  0x40, 0x80, 0x0,  0x0,  0x2,  0xEE, 0x0,  0x1};
int D_80800920_chnicecavemenguard[18] = {0x30E03A5,
                                         0x7EE0001,
                                         (u32) &D_808008E8_chnicecavemenguard,
                                         (u32) func_80102EC0,
                                         (u32) func_808000D4_chnicecavemenguard,
                                         (u32) func_801018A4,
                                         0x5DC0000,
                                         0x3FC00000,
                                         0x18607E7,
                                         0x40840124,
                                         (u32) func_80800388_chnicecavemenguard,
                                         0x0,
                                         0x0,
                                         (u32) func_8080000C_chnicecavemenguard,
                                         (u32) func_80107C2C,
                                         -0x7BEFEBEE,
                                         (u32) func_808003A8_chnicecavemenguard,
                                         0x0};
u8 D_80800968_chnicecavemenguard[16] = {0x3, 0x23, 0x0, 0x0, 0x1, 0x5E, 0x0, 0x96,
                                        0x0, 0x0,  0x0, 0xC, 0x2, 0x3C, 0x2, 0x0};
u8 D_80800978_chnicecavemenguard[12] = {0xC3, 0x96, 0x0,  0x0,  0xC2, 0xC8,
                                        0x0,  0x0,  0xC3, 0xAF, 0x0,  0x0};
u8 D_80800984_chnicecavemenguard[12] = {0x43, 0x96, 0x0,  0x0,  0x43, 0xE1,
                                        0x0,  0x0,  0x43, 0x16, 0x0,  0x0};
s32 D_80800990_chnicecavemenguard[3] = {0x130417, 0xD00C0, 0xD90000};
s32 D_8080099C_chnicecavemenguard[4] = {0x3F23D70A, 0x3F3AE148, 0x3F51EB85, -0x40800000};
s32 D_808009AC_chnicecavemenguard[4] = {0x0, 0x3E6B851F, 0x3EA3D70A, 0x3ED70A3D};
f32 D_808009BC_chnicecavemenguard[4] = {0.9f, 1.1f, 1.05f, 1.0f};
s16 D_808009CC_chnicecavemenguard[4] = {0x5BE, 0x5BC, 0x5BD, 0x5BD};
s16 D_808009D4_chnicecavemenguard[4] = {0x7D00, 0x55F0, 0x55F0, 0x55F0};
s32 D_808009DC_chnicecavemenguard[3] = {0x3060001, 0xC80BB8, 0x70000};
s32 D_808009E8_chnicecavemenguard[2] = {0x1305B6, 0x180000};
Trip D_808009F0_chnicecavemenguard = {0x3D75C28F, 0x3F0F5C29, -0x40800000};
s32 D_808009FC_chnicecavemenguard[5] = {0x130404, 0xD00F3, 0x10C0016, 0x36B00000, 0x0};
