#include "common.h"

extern int D_80800A80_chkingjinjobits[];
typedef union {
    s32 local_0;
    u8 local_1[4];
} KingJinjoEvent;
extern s32 _chkingjinjobits_entrypoint_1;
extern void func_8010D5DC(void);
extern s32 func_800EA364(void);
extern void func_80101FDC(Actor *, s32);
extern void func_800BF744(s32, s32);
extern s32 func_800EA090(void);
extern void func_800F4A58(s32, f32 *, f32);
extern void func_800F49D4(s32, void (*)(void), s32);
extern f32 D_80800AC8_chkingjinjobits[];
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EE88C(f32 *, Vtx *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
int func_80800744_chkingjinjobits();
void func_80800354_chkingjinjobits();

int chkingjinjobits_entrypoint_0()
{
    return (int) &D_80800A80_chkingjinjobits;
}

void func_8080000C_chkingjinjobits(s32 arg0)
{
}

// State machine per script: 2/3 Wooded Hollow, 4-7 temple drain and repair.
void func_80800014_chkingjinjobits(Actor *actor)
{
    s32 unk_0;
    s32 unk_1;
    switch (actor->unk70_10) {
        case 2:
            if ((func_8010D23C() != 0) && (func_8010C500(actor) != 0)) {
                func_800DA544(0x367);
                _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) actor + 0), 0x1537, 0x44, 0, 0x97);
                _capod_entrypoint_13(*(s32 *) ((s8 *) actor + 0), 0, 9, 0x10);
                func_80101FDC(actor, 1);
            }

            return;

        case 3:
            if (actor->unk64_19 && actor->unk64_20) {
                func_800F82D4(func_800F54E4(), 0);
                _capod_entrypoint_14();
                _glcutDll_entrypoint_0();
                _glcutDll_entrypoint_7(0x18E);
                _glcutDll_entrypoint_22(0x68);
                _glcutDll_entrypoint_12(1);
                _glcutDll_entrypoint_16();
            }
            break;

        case 4:
            if (func_800DA298(0x67A) != 0) {
                func_800BF744(3, 1);
                func_800DA544(0x360);
                func_80101FDC(actor, 5);
            }
            break;

        case 5:
            unk_0 = func_800D9078(&actor->unk58);
            _glid_entrypoint_0(func_800BEA88(0), 1, &_chkingjinjobits_entrypoint_1,
                               *(s32 *) ((s8 *) actor + 0));
            if (unk_0 != 0) {
                func_800BF744(3, 0);
                func_800FFAB0(actor);
            }
            break;

        case 6:
            if (func_800DA298(0x67B) != 0) {
                func_80101FDC(actor, 7);
                func_800BF744(3, 1);
            }
            _glid_entrypoint_0(func_800BEA88(0), 1, &_chkingjinjobits_entrypoint_1,
                               *(s32 *) ((s8 *) actor + 0));
            return;

        case 7:
            unk_1 = func_800D9078(&actor->unk58);
            _glid_entrypoint_0(func_800BEA88(0), 1, &_chkingjinjobits_entrypoint_1,
                               *(s32 *) ((s8 *) actor + 0));
            if (unk_1 != 0) {
                func_800BF744(1, 1);
                func_800BF744(2, 0);
                func_800BF744(3, 0);
                func_800DA524(0x360);
                func_800DA544(0x3B);
                func_800DA524(0x1A5);
                func_800FFAB0(actor);
            }
    }
}

int func_8080029C_chkingjinjobits(Actor *actor, s32 msg, s32 msg_data)
{
    switch (msg) {
        case 0x95:
            func_80800354_chkingjinjobits(actor);
            break;
        case 0x2E:
            func_80800744_chkingjinjobits(actor, ((s16 *) &msg_data)[0], ((s16 *) &msg_data)[1]);
            break;
        case 0x32:
            actor->unk64_20 = 1;
            func_800F82D4(func_800F54E4(), 1);
            break;
        case 0xB:
            if (func_800EA05C() == 0x14F) {
                func_800FFAB0(actor);
            }
            return 3;
        default:
            return 0;
    }
    return 1;
}

// Picks the script for the current map; the actor is removed if none applies.
void func_80800354_chkingjinjobits(actor) Actor *actor;
{
    s32 keep;
    s32 life_sapped;
    s32 unk_2;
    s32 has_jiggy;
    s32 unk_4;
    f32 marker_pos[6];
    s32 unk_6;

    keep = 0;
    life_sapped = func_800DA298(0x360);
    unk_2 = func_800DA298(0x3B);
    has_jiggy = func_800D0B68(0x5A, 1);
    switch (func_800EA05C()) {
        case 0x142:
            if (_glcutDll_entrypoint_19(0x66)) {
                unk_4 = 0x900;
                if (func_800EA364() == 0x143) {
                    unk_4 = 0x2900;
                }
                _capod_entrypoint_13(actor->unk0, 0, 0x4B, unk_4);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x154D, 0x44, 0, 0xAE);
                keep = 1;
            } else if (!func_800DB9B0() && !life_sapped && !unk_2 && func_800EA090() == 1 &&
                       has_jiggy) {
                unk_6 = func_800F54E4();
                _subaddiemarker_entrypoint_1(actor, 0x154, 0x32, marker_pos, 1);
                func_800F497C(unk_6);
                func_800F49A8(unk_6, 1);
                func_800F49D4(unk_6, func_8010D5DC, actor->unk0);
                func_800F4A58(unk_6, marker_pos, 200.0f);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x154C, 0x44, 0, 0xAE);
                func_80101FDC(actor, 3);
                _capod_entrypoint_13(actor->unk0, 0, 0x4C, 0x2030);
                keep = 1;
            }
            func_800BF744(1, !life_sapped);
            func_800BF744(2, life_sapped);
            func_800BF744(3, 0);
            break;
        case 0x145:
        case 0x146:
        case 0x147:
        case 0x148:
        case 0x149:
        case 0x14A:
        case 0x14B:
        case 0x14C:
        case 0x14D:
        case 0x14E:
            if (!has_jiggy && !func_800DB9B0() && !func_800DA9E4(0x67D, 1)) {
                keep = 1;
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1536, 0xE, 0, 0xAE);
            }
            break;
        case 0x14F:
            keep = !func_800DA298(0x367);
            func_80101FDC(actor, 2);
            _subaddieDll_entrypoint_1(actor);
            break;
        case 0x190:
            keep = 1;
            func_80101FDC(actor, 4);
            actor->unk6C_0 = 0;
            actor->unk58 = 12.0f;
            func_800BF744(1, 0);
            func_800BF744(2, 1);
            func_800BF744(3, 1);
            break;
        case 0x198:
            keep = 1;
            func_80101FDC(actor, 6);
            actor->unk6C_0 = 1;
            actor->unk58 = 12.0f;
            func_800BF744(1, 0);
            func_800BF744(2, 1);
            func_800BF744(3, 1);
            break;
        case 0x160:
            if (func_800EA090() == 4) {
                keep = 1;
                _capod_entrypoint_2(actor->unk0, 0x15, 0x2000);
                _capod_entrypoint_8(1);
                _gcdialogcamera_entrypoint_8();
                _capod_entrypoint_7(5, 1);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x14D7, 0xC, 0, 0x22);
                func_80101FDC(actor, 8);
            }
            break;
    }
    if (!keep) {
        func_800FFAB0(actor);
    }
}

int func_80800744_chkingjinjobits(Actor *actor, s32 msg, KingJinjoEvent event)
{
    switch (msg) {
        case 0x1536:
            _glcutDll_entrypoint_6(0x142, 0x66, actor);
            break;
        case 0x154C:
            actor->unk64_19 = 1;
            break;
        case 0x14D7:
            _capod_entrypoint_3(0);
            func_800FFAB0(actor);
    }
}

// Glid vertex callback: sets vertex alpha from the distance to a centre point.
void chkingjinjobits_entrypoint_1(s32 unk_0, Vtx *src, Vtx *dst, s32 count, Unk80132ED0 *marker)
{
    Actor *actor;
    f32 radius;
    f32 dist;
    f32 vertex_pos[3];
    s32 pad[2]; // Matching: needed for the match.
    Vtx *end;

    actor = func_80106790(marker);
    if (actor->unk6C_0) {
        radius = func_800F12D4(actor->unk58, 0.0f, 12.0f, 10.0f, 3000.0f);
    } else {
        radius = func_800F12D4(actor->unk58, 0.0f, 12.0f, 3000.0f, 10.0f);
    }
    for (end = src + count; src < end; src++, dst++) {
        func_800EE88C(vertex_pos, src);
        dist = func_800EEAD4(vertex_pos, D_80800AC8_chkingjinjobits);
        if (dist < radius) {
            dst->v.cn[3] = 0;
        } else if (radius + 200.0f < dist) {
            dst->v.cn[3] = 0xFF;
        } else {
            dst->v.cn[3] = func_800F10B4(dist - radius, 0.0f, 200.0f, 0, 255.0f);
        }
    }
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
// TU-NOTE: the overlay .data is defined here in C.
int D_80800A80_chkingjinjobits[18] = {0x15804EB,
                                      0x1,
                                      0x0,
                                      (u32) func_80800014_chkingjinjobits,
                                      (u32) func_80105834,
                                      (u32) func_8010A730,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x4,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_8080000C_chkingjinjobits,
                                      (u32) func_80107C2C,
                                      -0x7FFFD9FE,
                                      (u32) func_8080029C_chkingjinjobits,
                                      0x0};
f32 D_80800AC8_chkingjinjobits[6] = {0.0f, 1.8e+03f, 0.0f, 0.0f, 0.0f, 0.0f};
