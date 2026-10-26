#include "common.h"

extern int D_808001C0_chtempleinternaldoor;
extern u8 D_8012762C;
extern f32 D_8080020C_chtempleinternaldoor[][2];
extern void func_80101FDC(Actor *, s32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_7(Actor *, f32);
extern void _chdoormake_entrypoint_8(Actor *, s32);
typedef struct { u8 pad[0x76]; u16 f76:9; u16 pad76:7; } DoorState;
typedef struct { u16 a; u8 pad[6]; } DoorEntry;
extern DoorEntry D_80800208_chtempleinternaldoor[];
extern void func_80103140(DoorState *, s32, s32);
void func_80800178_chtempleinternaldoor();

int chtempleinternaldoor_entrypoint_0()
{
  return (int)&D_808001C0_chtempleinternaldoor;
}

void func_8080000C_chtempleinternaldoor(Actor *param_0)
{
    s32 local_1;
    s32 local_0;
    f32 local_2;

    local_1 = param_0->unk74_7 - 0x32;
    switch (local_1) {
    case 0:
        local_0 = 0;
        break;
    case 1:
    case 10:
    case 11:
        if (D_8012762C == 0x1B) {
            local_0 = 0;
        } else {
            func_80101FDC(param_0, 4);
            local_0 = 0;
        }
        break;
    default:
        local_0 = 0x1060A;
        break;
    }
    local_2 = D_8080020C_chtempleinternaldoor[local_1][0];
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, local_2, local_0, -1)) {
        _chdoormake_entrypoint_5(param_0, 2.0f);
        _chdoormake_entrypoint_7(param_0, 5.0f);
        _chdoormake_entrypoint_8(param_0, 5);
    }
}

s32 func_808000F8_chtempleinternaldoor(void *param_0)
{
    _chdoor_entrypoint_0();
    if (((u32)((u16)(*(u16 *)((char *)param_0 + 0x72))) >> 0xA) == 1) {
        _chdoormake_entrypoint_7(param_0, 5.0f);
    }
}

s32 func_80800138_chtempleinternaldoor(s32 param_0, s32 param_1, s32 param_2) {
    if (param_1 == 0x95) {
        func_80800178_chtempleinternaldoor(param_0, param_1, param_2);
    }
    _chdoor_entrypoint_1(param_0, param_1, param_2);
}

void func_80800178_chtempleinternaldoor(param_0) DoorState *param_0; {
    s32 local_0 = param_0->f76 - 0x32;
    func_80103140(param_0, D_80800208_chtempleinternaldoor[local_0].a, *(u16 *)(*(u8 **)param_0 + 0x16));
}
