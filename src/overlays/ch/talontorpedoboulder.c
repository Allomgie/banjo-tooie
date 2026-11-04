#include "common.h"

extern u32 D_808002B4_chtalontorpedoboulder[];
extern void func_80102FDC(Actor *, f32);
extern s32 D_80800240_chtalontorpedoboulder[];
extern s32 D_808002FC_chtalontorpedoboulder[];
typedef struct {
    u8 pad[0x76];
    u16 f76 : 9;
    u16 pad76 : 7;
} TalonState;
typedef struct {
    s16 id;
    s16 val;
} TalonEntry;
extern TalonEntry D_80800314_chtalontorpedoboulder[];
s32 func_808001CC_chtalontorpedoboulder();
s32 func_808001F8_chtalontorpedoboulder();

int chtalontorpedoboulder_entrypoint_0()
{
    return (int) &D_808002B4_chtalontorpedoboulder;
}

void func_8080000C_chtalontorpedoboulder(Actor *actor)
{
    s32 flag;

    flag = func_808001CC_chtalontorpedoboulder(actor);
    if (flag != 0 && func_800DA298(flag)) {
        func_800FFAB0(actor);
    } else {
        func_80102FDC(actor, actor->scale + actor->scale);
    }
}

// 0x40: hit by the Talon Torpedo; 0x90: debris.
s32 func_80800070_chtalontorpedoboulder(u8 *actor, s32 msg, s32 param_2)
{
    s32 flag;
    s32 camera_id;
    s32 exploder;

    switch (msg) {
        case 0x40:
            flag = func_808001CC_chtalontorpedoboulder(actor);
            camera_id = func_808001F8_chtalontorpedoboulder(actor);
            _chexploder_entrypoint_3(actor, actor + 4, 0xF);
            func_800BABB8(0, actor + 4, actor + 4, *(s32 *) ((s8 *) actor + 0x38),
                          &D_80800240_chtalontorpedoboulder);
            _subaddieaudioquick_entrypoint_2(actor, actor + 4,
                                             &D_808002FC_chtalontorpedoboulder);
            if (flag != 0) {
                func_800DA544(flag);
            }
            if (camera_id != -1) {
                _capod_entrypoint_13(*(s32 *) ((s8 *) actor + 0), 0, camera_id, 0x10);
            }
            goto block_9;
        case 0x90:
            exploder = func_80106790(func_80101080());
            _chexploder_entrypoint_9(exploder, 1, 2);
            _chexploder_entrypoint_9(exploder, 2, 0);
            goto block_9;
        default:
            return 0;
    }
block_9:
    return 1;
}

s32 func_80800194_chtalontorpedoboulder(s32 param_0, s32 param_1)
{
    func_800DF744(2, 1);
    func_80101870(param_0, param_1);
}

// Returns the game flag for this boulder variant, or 0 if the variant is out of range.
s32 func_808001CC_chtalontorpedoboulder(actor) void *actor;
{
    s32 variant;
    variant = (((u16) *(u16 *) ((u8 *) actor + 0x76) & 0xFFFFFFFF) >> 7) - 0x32;
    if ((variant < 0) || (variant >= 5)) {
        return 0;
    }
    return variant + 0x3EF;
}

s32 func_808001F8_chtalontorpedoboulder(actor)
TalonState *actor;
{
    s32 i;
    for (i = 0; i < 1; i++) {

if (D_80800314_chtalontorpedoboulder[i].id == actor->f76 - 0x32) {
    return D_80800314_chtalontorpedoboulder[i].val;
}


}
return -1;
}

// TU-NOTE: the overlay .data is defined here in C because its tables point to functions of this file;
// IDO schedules some of them differently otherwise. Values are taken from the ROM.
extern void func_80102EC0();
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_80800240_chtalontorpedoboulder[29] = {
    0x4100016, -0x7FFFFFE3, 0x9DD002B, 0x8000A00,   0x220180,   0x2000480, 0x6000015,  0x26,
    0x190000,  0x7002D,     0x320064,  0x20DEA7,    0x71C0000A, -0x63FFE7, -0x63FF9C,  0x4B0064,
    0x41A0F10, 0x1D092F,    0x140016,  -0x7A79FFD3, 0x1900258,  0x1BFCE0,  -0x257FFDE, 0xB300CC,
    0xB300B3,  0x1E0032,    0x32000D,  0x4B0F1A,    0x0};
u32 D_808002B4_chtalontorpedoboulder[18] = {0x10B0472,
                                            0x92A0001,
                                            0x0,
                                            (u32) func_80102EC0,
                                            (u32) func_80105834,
                                            (u32) func_80800194_chtalontorpedoboulder,
                                            0x0,
                                            0x0,
                                            0x0,
                                            0x40000800,
                                            0x0,
                                            (u32) func_80108ED0,
                                            0x0,
                                            (u32) func_8080000C_chtalontorpedoboulder,
                                            (u32) func_80107C2C,
                                            0x80080C10,
                                            (u32) func_80800070_chtalontorpedoboulder,
                                            0x0};
s32 D_808002FC_chtalontorpedoboulder[6] = {0x1B0013,   0x413000A, 0xE60016,
                                           0x6D600001, 0x4E209C4, 0x0};
TalonEntry D_80800314_chtalontorpedoboulder[1] = {0x0, 0x2};
TalonEntry D_80800318_chtalontorpedoboulder[2] = {0x0, 0x0, 0x0, 0x0};
