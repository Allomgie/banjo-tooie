#include "ch/minegrilldoor.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);

extern u32 D_80800190_chminegrilldoor[];

void func_80800000_chminegrilldoor(Actor *door)
{
    door->unk6C_0 = 0;
    if (_chdoormake_entrypoint_3(door, 0.0f, 90.0f, door->scale * 220.0f, 4, 0x43B)) {
        _chdoormake_entrypoint_8(door, 2);
    }
}

// Messages 0x79..0x7C set/clear one of two bits; both set opens the door.
s32 func_80800068_chminegrilldoor(Actor *door, s32 msg, s32 arg)
{
    s32 bits;
    s32 mask;
    if (!func_800DA298(0x43B) && msg >= 0x79 && msg < 0x7D) {
        bits = msg - 0x79;
        mask = (bits & 2) ? 2 : 1;
        door->unk6C_0 = (door->unk6C_0 & (3 - mask)) + (bits & 1) * mask;
        if (door->unk6C_0 == 3) {
            func_800DA544(0x43B);
            _capod_entrypoint_13(door->unk0, 0, 8, 0x10);
        }
        return 1;
    }
    return _chdoor_entrypoint_1(door, msg, arg);
}

int func_80800144_chminegrilldoor(Actor *door)
{
    if ((*(s32 *) ((char *) door + 0x6C) & 0x1FF) == 3) {
        _chdoor_entrypoint_0();
    }
}

void *chminegrilldoor_entrypoint_0(void)
{
    return &D_80800190_chminegrilldoor;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u32 D_80800190_chminegrilldoor[20] = {0xAC04C2,
                                      0x96B0001,
                                      0x0,
                                      (u32) func_80800144_chminegrilldoor,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x7D00000,
                                      0x0,
                                      0x43B0000,
                                      0xC00,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800000_chminegrilldoor,
                                      (u32) func_80107C2C,
                                      0x80002402,
                                      (u32) func_80800068_chminegrilldoor,
                                      0x0,
                                      0x0,
                                      0x0};
