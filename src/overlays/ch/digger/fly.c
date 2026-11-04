// Possibly a flying digger minion: two ActorInfos whose only own code is an init that sets up
// the shared flying-baddie AI (sucoasterfly) at 0.75x scale.
#include "common.h"

extern int D_808000F8_chdiggerfly[];
extern void *D_80800140_chdiggerfly;
extern void _sucoasterfly_entrypoint_1();
extern void func_80102FDC(u8 *, f32);
extern void func_8010A3E8(u8 *, f32);

int chdiggerfly_entrypoint_0()
{
    return (int) &D_808000F8_chdiggerfly;
}

int chdiggerfly_entrypoint_1()
{
    return &D_80800140_chdiggerfly;
}

// Init: shared flying-baddie AI at 0.75x scale.
void func_80800018_chdiggerfly(u8 *actor)
{
    _sucoasterfly_entrypoint_1(actor, 0);
    func_80102FDC(actor, *(f32 *) (actor + 0x38) * 0.75f);
    func_8010A3E8(actor, 0.75f);
}

extern void _sucoasterfly_entrypoint_3();
extern void func_80105834();
extern void _sucoasterfly_entrypoint_6();
extern void _sucoasterfly_entrypoint_2();
extern void _sucoasterfly_entrypoint_0();
extern void func_80107C2C();
extern void _sucoasterfly_entrypoint_4();
u32 D_80800070_chdiggerfly[34] = {
    0x0,        0x0,        0x3ECCCCCD, 0x1900001,  0x3ECCCCCD, 0x1900001,  0x3F0A3D71,
    0x1900001,  0x3ECCCCCD, 0x1900001,  0x3EE66666, 0x5280002,  0x3EB851EC, 0x5290001,
    0x3ECCCCCD, 0x1900001,  0x3F0A3D71, 0x1900001,  0x3F0A3D71, 0x1900001,  0x3F147AE1,
    0x52A0002,  0x3EA8F5C3, 0x52B0101,  0x3EC28F5C, 0x52C0002,  0x3EC28F5C, 0x52C0084,
    0x3F0A3D71, 0x0,        0x3F0A3D71, 0x1900001,  0x3F0A3D71, 0x1900001};
int D_808000F8_chdiggerfly[18] = {0x1A40133,
                                  0x65E0001,
                                  (u32) &D_80800070_chdiggerfly,
                                  (u32) _sucoasterfly_entrypoint_3,
                                  (u32) func_80105834,
                                  (u32) _sucoasterfly_entrypoint_6,
                                  0x9C40000,
                                  0x40000000,
                                  0x0,
                                  0x3250329,
                                  (u32) _sucoasterfly_entrypoint_2,
                                  (u32) _sucoasterfly_entrypoint_0,
                                  0x0,
                                  (u32) func_80800018_chdiggerfly,
                                  (u32) func_80107C2C,
                                  -0x7FCDBFE3,
                                  (u32) _sucoasterfly_entrypoint_4,
                                  -0x7FEDBA9C};
void *D_80800140_chdiggerfly = (void *) 0x01A50134;
static u32 D_80800140_chdiggerfly_rest[19] = {0x65E0001,
                                              (u32) &D_80800070_chdiggerfly,
                                              (u32) _sucoasterfly_entrypoint_3,
                                              (u32) func_80105834,
                                              (u32) _sucoasterfly_entrypoint_6,
                                              0x9C40000,
                                              0x40000000,
                                              0x0,
                                              0x3250329,
                                              (u32) _sucoasterfly_entrypoint_2,
                                              (u32) _sucoasterfly_entrypoint_0,
                                              0x0,
                                              (u32) func_80800018_chdiggerfly,
                                              (u32) func_80107C2C,
                                              0x80124015,
                                              (u32) _sucoasterfly_entrypoint_4,
                                              0x80124564,
                                              0x0,
                                              0x0};
