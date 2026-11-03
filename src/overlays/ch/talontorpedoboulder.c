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

void func_8080000C_chtalontorpedoboulder(Actor *param_0)
{
    s32 local_0;

    local_0 = func_808001CC_chtalontorpedoboulder(param_0);
    if (local_0 != 0 && func_800DA298(local_0)) {
        func_800FFAB0(param_0);
    } else {
        func_80102FDC(param_0, param_0->scale + param_0->scale);
    }
}

s32 func_80800070_chtalontorpedoboulder(u8 *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    s32 local_3;

    switch (param_1) {
        case 0x40:
            local_0 = func_808001CC_chtalontorpedoboulder(param_0);
            local_1 = func_808001F8_chtalontorpedoboulder(param_0);
            _chexploder_entrypoint_3(param_0, param_0 + 4, 0xF);
            func_800BABB8(0, param_0 + 4, param_0 + 4, *(s32 *) ((s8 *) param_0 + 0x38),
                          &D_80800240_chtalontorpedoboulder);
            _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4,
                                             &D_808002FC_chtalontorpedoboulder);
            if (local_0 != 0) {
                func_800DA544(local_0);
            }
            if (local_1 != -1) {
                _capod_entrypoint_13(*(s32 *) ((s8 *) param_0 + 0), 0, local_1, 0x10);
            }
            goto block_9;
        case 0x90:
            local_3 = func_80106790(func_80101080());
            _chexploder_entrypoint_9(local_3, 1, 2);
            _chexploder_entrypoint_9(local_3, 2, 0);
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

s32 func_808001CC_chtalontorpedoboulder(param_0) void *param_0;
{
    s32 temp_v1;
    temp_v1 = (((u16) *(u16 *) ((u8 *) param_0 + 0x76) & 0xFFFFFFFF) >> 7) - 0x32;
    if ((temp_v1 < 0) || (temp_v1 >= 5)) {
        return 0;
    }
    return temp_v1 + 0x3EF;
}

s32 func_808001F8_chtalontorpedoboulder(param_0)
TalonState *param_0;
{
    s32 i;
    for (i = 0; i < 1; i++) {

if (D_80800314_chtalontorpedoboulder[i].id == param_0->f76 - 0x32) {
    return D_80800314_chtalontorpedoboulder[i].val;
}

}
return -1;
}

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
