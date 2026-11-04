// Probably the internal doors of Targitzan's temple: several variants built with chdoormake,
// opening angle from a table, some start open, and a linked prop/door id is attached on load.
#include "common.h"

extern int D_808001C0_chtempleinternaldoor[];
extern u8 D_8012762C;
extern f32 D_8080020C_chtempleinternaldoor[][2];
extern void func_80101FDC(Actor *, s32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_7(Actor *, f32);
extern void _chdoormake_entrypoint_8(Actor *, s32);
typedef struct {
    u8 pad[0x76];
    u16 f76 : 9;
    u16 pad76 : 7;
} DoorState;
typedef struct {
    u16 link_id;
    u8 pad[6];
} DoorEntry;
extern DoorEntry D_80800208_chtempleinternaldoor[];
extern void func_80103140(DoorState *, s32, s32);
void func_80800178_chtempleinternaldoor();

int chtempleinternaldoor_entrypoint_0()
{
    return (int) &D_808001C0_chtempleinternaldoor;
}

void func_8080000C_chtempleinternaldoor(Actor *actor)
{
    s32 variant;
    s32 door_flags;
    f32 angle;

    // Variants 1, 10, 11 start open unless the map entrance is 0x1B
    variant = actor->unk74_7 - 0x32;
    switch (variant) {
        case 0:
            door_flags = 0;
            break;
        case 1:
        case 10:
        case 11:
            if (D_8012762C == 0x1B) {
                door_flags = 0;
            } else {
                func_80101FDC(actor, 4);
                door_flags = 0;
            }
            break;
        default:
            door_flags = 0x1060A;
            break;
    }
    angle = D_8080020C_chtempleinternaldoor[variant][0];
    if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, angle, door_flags, -1)) {
        _chdoormake_entrypoint_5(actor, 2.0f);
        _chdoormake_entrypoint_7(actor, 5.0f);
        _chdoormake_entrypoint_8(actor, 5);
    }
}

s32 func_808000F8_chtempleinternaldoor(void *door)
{
    _chdoor_entrypoint_0();
    if (((u32) (u16) *(u16 *) ((char *) door + 0x72) >> 0xA) == 1) {
        _chdoormake_entrypoint_7(door, 5.0f);
    }
}

// Message 0x95 (on load): attach the linked door/prop id from the table.
s32 func_80800138_chtempleinternaldoor(s32 actor, s32 msg, s32 param_2)
{
    if (msg == 0x95) {
        func_80800178_chtempleinternaldoor(actor, msg, param_2);
    }
    _chdoor_entrypoint_1(actor, msg, param_2);
}

void func_80800178_chtempleinternaldoor(door) DoorState *door;
{
    s32 variant = door->f76 - 0x32;
    func_80103140(door, D_80800208_chtempleinternaldoor[variant].link_id,
                  *(u16 *) (*(u8 **) door + 0x16));
}
// TU-NOTE: the overlay .data is defined here in C because its tables point to functions of this file;
// IDO schedules some of them differently otherwise. Values are taken from the ROM.
// D_8080020C_chtempleinternaldoor is a linker symbol at D_80800208_chtempleinternaldoor + 0x4.

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_808001C0_chtempleinternaldoor[18] = {0xAC02B6,
                                           0x8400001,
                                           0x0,
                                           (u32) func_808000F8_chtempleinternaldoor,
                                           (u32) func_80105834,
                                           (u32) func_80101870,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x800,
                                           0x0,
                                           0x0,
                                           0x0,
                                           (u32) func_8080000C_chtempleinternaldoor,
                                           (u32) func_80107C2C,
                                           -0x7FFFDBFE,
                                           (u32) func_80800138_chtempleinternaldoor,
                                           0x0};
DoorEntry D_80800208_chtempleinternaldoor[13] = {
    0x83F, 0x0,   0x0,   0x43,  0x3E,  0x0,   0x0,  0x840, 0x0,   0x0,   0x43,  0x3E,  0x0,
    0x0,   0x841, 0x0,   0x0,   0x43,  0x4D,  0x0,  0x0,   0x842, 0x0,   0x0,   0x43,  0x16,
    0x0,   0x0,   0x843, 0x0,   0x0,   0x43,  0x16, 0x0,   0x0,   0x844, 0x0,   0x0,   0x43,
    0x16,  0x0,   0x0,   0x845, 0x0,   0x0,   0x43, 0x16,  0x0,   0x0,   0x846, 0x0,   0x0,
    0x43,  0x16,  0x0,   0x0,   0x847, 0x0,   0x0,  0x43,  0x16,  0x0,   0x0,   0x848, 0x0,
    0x0,   0x43,  0x16,  0x0,   0x0,   0x850, 0x0,  0x0,   0x43,  0x16,  0x0,   0x0,   0x84F,
    0x0,   0x0,   0x43,  0x16,  0x0,   0x0,   0x0,  0x0,   0x0,   0x0,   0x0,   0x0,   0x0};
