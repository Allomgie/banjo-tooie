#include "common.h"

extern void *D_80800270_chweldarbossdoors;
extern int D_808002B8_chweldarbossdoors[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
typedef struct {
    u8 pad[0x76];
    u16 f76 : 9;
    u16 pad76 : 7;
} WeldS2;
extern void func_80103140(WeldS2 *, s32, s32);
extern s32 _chdoor_entrypoint_1(WeldS2 *, s32, s32);
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 rest : 10;
} WeldS;
extern void func_800DF744(s32, s32, WeldS *);
extern void func_80101870(WeldS *, s32);

void *chweldarbossdoors_entrypoint_0()
{
    return &D_80800270_chweldarbossdoors;
}

int chweldarbossdoors_entrypoint_1()
{
    return &D_808002B8_chweldarbossdoors;
}

// Large sliding door; variant 0x32 is mirrored.
void func_80800018_chweldarbossdoors(Actor *door)
{
    f32 yaw;
    s32 mirrored;

    yaw = door->rotation[1];
    mirrored = 0;
    if (door->unk74_7 == 0x32) {
        mirrored = 1;
        yaw += 180.0f;
    }
    _subaddiefade_entrypoint_14(door);
    if (_chdoormake_entrypoint_3(door, yaw + 90.0f, 0.0f, 750.0f, 0x102, -1)) {
        _chdoormake_entrypoint_5(door, 8.5f);
        _chdoormake_entrypoint_6(door, 1.0f);
        if (mirrored)
            _chdoormake_entrypoint_8(door, 8);
    }
}

s32 func_808000E0_chweldarbossdoors(WeldS2 *door, s32 msg, s32 arg)
{
    if (msg == 0x95) {
        func_80103140(door, (u16) (door->f76 + 0x837), 0);
    }
    return _chdoor_entrypoint_1(door, msg, arg);
}

void func_80800140_chweldarbossdoors(WeldS *door, s32 arg)
{
    func_800DF744(1, (door->f72 == 1) ? 0 : 1, door);
    func_80101870(door, arg);
}

// Entry door; starts closed during a retry fight or a cutscene.
void func_80800194_chweldarbossdoors(Actor *door)
{
    s32 close_door;

    close_door = func_800DA298(0x174) != 0;
    if (close_door) {
        close_door = func_800DA298(0x18C) == 0;
        if (close_door)
            close_door = func_800F64A4(func_800F54E4(), 1) != 0;
    }
    if (close_door || _glcutDll_entrypoint_20())
        func_80101FDC(door, 1);
    if (_chdoormake_entrypoint_3(door, 0.0f, 90.0f, 350.0f, 2, -1)) {
        _chdoormake_entrypoint_5(door, 3.0f);
        _chdoormake_entrypoint_6(door, 0.15f);
        _chdoormake_entrypoint_8(door, 4);
    }
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file and the
// assembler schedules them differently otherwise. D_808002B8_chweldarbossdoors is declared as int[] above.
extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80107C2C();
void *D_80800270_chweldarbossdoors = (void *) 0x00AC0341;
static u32 D_80800270_chweldarbossdoors_rest[17] = {0xFFFF0001,
                                                    0x0,
                                                    (u32) _chdoor_entrypoint_0,
                                                    (u32) func_80105834,
                                                    (u32) func_80800140_chweldarbossdoors,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    0x400,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    (u32) func_80800018_chweldarbossdoors,
                                                    (u32) func_80107C2C,
                                                    0x80082412,
                                                    (u32) func_808000E0_chweldarbossdoors,
                                                    0x0};
int D_808002B8_chweldarbossdoors[18] = {0xAC0431,
                                        0x8800004,
                                        0x0,
                                        (u32) _chdoor_entrypoint_0,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x40000800,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_80800194_chweldarbossdoors,
                                        (u32) func_80107C2C,
                                        -0x7FF7DBEE,
                                        (u32) _chdoor_entrypoint_1,
                                        0x0};
