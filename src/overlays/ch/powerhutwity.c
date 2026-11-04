#include "common.h"

extern int D_80800B28_chpowerhutwitchy[];
extern int D_80800B70_chpowerhutwitchy[];
extern int D_80800BB8_chpowerhutwitchy[];
extern s32 D_80800C00_chpowerhutwitchy[];
extern u8 D_80800B00_chpowerhutwitchy[];
extern void _chpowerhut_entrypoint_0(s32, void *);
extern u8 *func_80100094(s32, s32);
extern u8 _chpowerhutwitchy_entrypoint_4[];
extern Actor *func_80106790(void *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F2FD0(f32 *, f32 *, f32);
extern int func_800F3320(u8 *, u8 *, u8 *, f32);
extern u8 D_80800C48_chpowerhutwitchy[];
extern u8 D_80800B14_chpowerhutwitchy[];
extern void _chpowerhutwitchy_entrypoint_5(void);
typedef struct {
    u8 pad_0[0xC];
    f32 unk_C;
} PowerHutVertex;
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
void func_8080024C_chpowerhutwitchy();
void func_80800890_chpowerhutwitchy();
void func_808009FC_chpowerhutwitchy();

int chpowerhutwitchy_entrypoint_0()
{
    return (int) &D_80800B28_chpowerhutwitchy;
}

int chpowerhutwitchy_entrypoint_1()
{
    return (int) &D_80800B70_chpowerhutwitchy;
}

int chpowerhutwitchy_entrypoint_2(void)
{
    return &D_80800BB8_chpowerhutwitchy;
}

int chpowerhutwitchy_entrypoint_3()
{
    return (int) D_80800C00_chpowerhutwitchy;
}

void func_80800030_chpowerhutwitchy(s32 actor)
{
    _chpowerhut_entrypoint_0(actor, D_80800B00_chpowerhutwitchy);
    func_80100094(actor, 0)[0x18] = 0;
}

void func_80800068_chpowerhutwitchy(Actor *actor)
{
    _chpowerhut_entrypoint_1(actor, D_80800B00_chpowerhutwitchy);
    switch (actor->unk70_10) {
        case 1:
        case 2:
            break;
        case 3:
            if (*(s16 *) ((u8 *) func_80100094(actor, 0) + 0xC) == 2) {
                func_800BF744(1, 0);
                func_800BF744(2, 1);
                func_800BF744(3, 0);
                func_800BF744(4, 1);
                func_800BF744(7, 0);
                func_800BF744(8, 1);
                *((u8 *) func_80100094(actor, 0) + 0x18) = 1;
            }
            if (*(s16 *) ((u8 *) func_80100094(actor, 0) + 0xC) == 3) {
                *(f32 *) &actor->actorData[4] =
                    *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x14);
                func_8080024C_chpowerhutwitchy(actor);
            }
    }
}

void func_80800168_chpowerhutwitchy(Actor *actor, s32 msg, s32 param_2)
{
    s32 powered;

    if (msg == 0x95) {
        powered = func_800DA298(0xEB) || _glcutDll_entrypoint_20();
        func_800BF744(1, !powered);
        func_800BF744(2, powered);
        func_800BF744(3, !powered);
        func_800BF744(4, powered);
        func_800BF744(7, !powered);
        func_800BF744(8, powered);
        *(f32 *) ((u8 *) actor + 0x28) = *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x14);
        if (!powered) {
            func_8080024C_chpowerhutwitchy(actor);
        }
    }
    _chpowerhut_entrypoint_3(actor, msg, param_2, D_80800B00_chpowerhutwitchy);
}

void func_8080024C_chpowerhutwitchy(param_0) s32 *param_0;
{
    s32 map_a;
    s32 map_b;
    map_a = func_800BEA88(0);
    // Matching: empty if blocks are needed for the match.
    if (1) {
    }
    if (1) {
    }
    _glid_entrypoint_0(map_a, 1, &_chpowerhutwitchy_entrypoint_4, *param_0);
    _glid_entrypoint_0(map_a, 2, &_chpowerhutwitchy_entrypoint_4, *param_0);
    _glid_entrypoint_0(map_a, 3, &_chpowerhutwitchy_entrypoint_4, *param_0);
    _glid_entrypoint_0(map_a, 6, &_chpowerhutwitchy_entrypoint_4, *param_0);
    map_b = func_800BEA88(1);
    _glid_entrypoint_0(map_b, 1, &_chpowerhutwitchy_entrypoint_4, *param_0);
    _glid_entrypoint_0(map_b, 2, &_chpowerhutwitchy_entrypoint_4, *param_0);
    _glid_entrypoint_0(map_b, 6, &_chpowerhutwitchy_entrypoint_4, *param_0);
    // Matching: empty if block needed for the match.
    if (param_0) {
    }
}

void chpowerhutwitchy_entrypoint_4(s32 param_0, u8 *param_1, u8 *param_2, s32 param_3,
                                   Unk80132ED0 *param_4)
{
    f32 progress;
    f32 alpha_scale;

    progress = ((f32 *) func_80106790(param_4)->actorData)[4];
    switch (param_0) {
        case 1:
            for (; param_3 > 0; param_3--, param_1 += 0x10, param_2 += 0x10) {
                func_800F2FD0((f32 *) (param_2 + 0xC), (f32 *) (param_1 + 0xC), progress);
            }
            break;
        case 2:
            for (; param_3 > 0; param_3--, param_1 += 0x10, param_2 += 0x10) {
                func_800F3320(param_2 + 0xC, D_80800C48_chpowerhutwitchy, param_1 + 0xC, progress);
            }
            break;
        case 3:
            alpha_scale = func_800F10B4(progress, 0.0f, 1.0f, 0.3f, 1.0f);
            for (; param_3 > 0; param_1 += 0x10, param_3--, param_2 += 0x10) {
                param_2[0xF] = (u32) ((f32) (u32) param_1[0xF] * alpha_scale);
            }
            break;
        case 6:
            for (; param_3 > 0; param_1 += 0x10, param_3--, param_2 += 0x10) {
                param_2[0xF] = (u32) ((f32) (u32) param_1[0xF] * progress);
            }
    }
}

void func_808005C8_chpowerhutwitchy(s32 param_0)
{
    s32 actor = param_0;
    _chpowerhut_entrypoint_0(actor, (int *) D_80800B14_chpowerhutwitchy);
    *(s8 *) ((s8 *) func_80100094(actor, 0) + 0x18) = 0;
    *(s8 *) ((s8 *) func_80100094(actor, 0) + 0x19) = 0;
}

void func_80800610_chpowerhutwitchy(Actor *actor)
{
    f32 progress;

    _chpowerhut_entrypoint_1(actor, D_80800B14_chpowerhutwitchy);
    if (actor->unk70_10 == 3 || actor->unk70_10 == 4) {
        if (*(s16 *) ((u8 *) func_80100094(actor, 0) + 0xC) == 2) {
            func_800BF744(5, 0);
            func_800BF744(6, 1);
            *((u8 *) func_80100094(actor, 0) + 0x18) = 1;
        }
        if (!*((u8 *) func_80100094(actor, 0) + 0x19)) {
            progress = *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x14);
            if (*(s16 *) ((u8 *) func_80100094(actor, 0) + 0xC) == 4) {
                func_808009FC_chpowerhutwitchy(actor);
            }
            if (*(s16 *) ((u8 *) func_80100094(actor, 0) + 0xC) == 3) {
                *(f32 *) &actor->actorData[4] = func_800F10B4(progress, 0.0f, 1.0f, 0.3f, 1.0f);
                func_80800890_chpowerhutwitchy(actor);
            }
        }
    }
}

s32 func_8080073C_chpowerhutwitchy(Actor *actor, s32 msg, s32 param_2)
{
    s32 powered;

    switch (msg) {
        case 0xB:
            if (param_2 == 0x31) {
                _capod_entrypoint_14();
                _capod_entrypoint_13(actor->unk0, 0, 0x35, 0x2010);
                // Open both dome doors.
                func_80101180(0x39E, 7, 0);
                func_80101180(0x39F, 7, 0);
                return 4;
            }
            return 3;
        case 0x95:
            powered = func_800DA298(0xEC) || _glcutDll_entrypoint_20();
            func_800BF744(5, !powered);
            func_800BF744(6, powered);
            *(f32 *) &actor->actorData[4] = func_800F10B4(
                *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x14), 0.0f, 1.0f, 0.3f, 1.0f);
            if (!powered)
                func_80800890_chpowerhutwitchy(actor);
            else
                func_808009FC_chpowerhutwitchy(actor);
    }
    return _chpowerhut_entrypoint_3(actor, msg, param_2, D_80800B14_chpowerhutwitchy);
}

void func_80800890_chpowerhutwitchy(param_0) Actor *param_0;
{
    s32 map;
    map = func_800BEA88(0);
    _glid_entrypoint_0(map, 4, _chpowerhutwitchy_entrypoint_5, param_0->unk0);
    _glid_entrypoint_0(map, 5, _chpowerhutwitchy_entrypoint_5, param_0->unk0);
    map = func_800BEA88(1);
    _glid_entrypoint_0(map, 4, _chpowerhutwitchy_entrypoint_5, param_0->unk0);
    _glid_entrypoint_0(map, 5, _chpowerhutwitchy_entrypoint_5, param_0->unk0);
}

void chpowerhutwitchy_entrypoint_5(s32 param_0, PowerHutVertex *param_1, PowerHutVertex *param_2,
                                   s32 param_3, void *param_4)
{
    f32 progress;

    progress = *(f32 *) &func_80106790(param_4)->actorData[4];
    switch (param_0) {
        case 4:
            while (param_3 > 0) {
                func_800F2FD0(&param_2->unk_C, &param_1->unk_C, progress);
                param_3--;
                param_1++;
                param_2++;
            }
            break;
        case 5:
            while (param_3 > 0) {
                func_800F2FD0(&param_2->unk_C, &param_1->unk_C, progress);
                param_3--;
                param_1++;
                param_2++;
            }
    }
}

// Adds the dome mesh effect, only in the main Witchyworld map.
void func_808009FC_chpowerhutwitchy(this) Actor *this;
{

if (func_800EA05C() == 0xD6) {
    _idworldmake_entrypoint_1(func_800BEA88(0), 0x89D, 4, 1);
}

*(s8 *) ((char *) func_80100094(this, 0) + 0x19) = 1;
}

// Builds a dome door; the door at 0x39E gets the extra call.
void func_80800A58_chpowerhutwitchy(Actor *actor)
{
    f32 offset = -90.0f;
    s32 is_first = 0;

if (actor->unk6C_9 == 0x39E) {
    offset = 90.0f;
    is_first = 1;
}

if (_chdoormake_entrypoint_3(actor, offset, 0.0f, 100.0f, 1, 0xEC)) {
    _chdoormake_entrypoint_6(actor, 0.75f);
    if (is_first)
        _chdoormake_entrypoint_8(actor, 0x10);
}

}

extern void func_80105834();
extern void _chpowerhut_entrypoint_2();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
extern void func_80101870();
extern void _chdoor_entrypoint_1();
u8 D_80800B00_chpowerhutwitchy[20] = {0x0, 0xEB, 0x0,  0x26, 0x0, 0x10, 0x2,  0x58, 0x41, 0xC8,
                                      0x0, 0x0,  0x40, 0xE0, 0x0, 0x0,  0x41, 0x0,  0x0,  0x0};
u8 D_80800B14_chpowerhutwitchy[20] = {0x0, 0xEC, 0x0,  0x31, 0x0, 0x30, 0x1,  0xC2, 0x41, 0x50,
                                      0x0, 0x0,  0x40, 0x20, 0x0, 0x0,  0x40, 0xC0, 0x0,  0x0};
int D_80800B28_chpowerhutwitchy[18] = {0x306039C,
                                       -0xFFFF,
                                       0x0,
                                       (u32) func_80800068_chpowerhutwitchy,
                                       (u32) func_80105834,
                                       (u32) _chpowerhut_entrypoint_2,
                                       0xBB80000,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x1C0000,
                                       (u32) func_80800030_chpowerhutwitchy,
                                       (u32) func_80107C2C,
                                       -0x7FFFF3FE,
                                       (u32) func_80800168_chpowerhutwitchy,
                                       0x0};
int D_80800B70_chpowerhutwitchy[18] = {0x307039D,
                                       -0xFFFF,
                                       0x0,
                                       (u32) func_80800610_chpowerhutwitchy,
                                       (u32) func_80105834,
                                       (u32) _chpowerhut_entrypoint_2,
                                       0xBB80000,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x1C0000,
                                       (u32) func_808005C8_chpowerhutwitchy,
                                       (u32) func_80107C2C,
                                       -0x7FFFF3FE,
                                       (u32) func_8080073C_chpowerhutwitchy,
                                       0x0};
int D_80800BB8_chpowerhutwitchy[18] = {0xAC039E,
                                       0x79B0001,
                                       0x0,
                                       (u32) _chdoor_entrypoint_0,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x800,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80800A58_chpowerhutwitchy,
                                       (u32) func_80107C2C,
                                       -0x7FFFD3FE,
                                       (u32) _chdoor_entrypoint_1,
                                       0x0};
s32 D_80800C00_chpowerhutwitchy[18] = {0xAC039F,
                                       0x79C0001,
                                       0x0,
                                       (u32) _chdoor_entrypoint_0,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x800,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80800A58_chpowerhutwitchy,
                                       (u32) func_80107C2C,
                                       -0x7FFFD3FE,
                                       (u32) _chdoor_entrypoint_1,
                                       0x0};
u8 D_80800C48_chpowerhutwitchy[8] = {0x64, 0x64, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0};
