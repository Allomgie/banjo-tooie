#include "common.h"

extern int D_808001D0_chplatuegrill[];
typedef union {
    s32 word;
    void *pointer;
} PlatueGrillEventPayload;
extern int D_80800238_chplatuegrill[];
extern f32 func_80103EF4(Actor *);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);

void func_80800000_chplatuegrill(Actor *param_0)
{
    _chdoormake_entrypoint_3(param_0, param_0->rotation[1], 90.0f, func_80103EF4(param_0) * 1.1f, 1,
                             0x3EA);
    _chdoormake_entrypoint_5(param_0, 2.0f);
    _chdoormake_entrypoint_6(param_0, 4.0f);
    _chdoormake_entrypoint_8(param_0, 2);
    _chdoormake_entrypoint_9(param_0, 0, 0x10, 0x10);
}

int chplatuegrill_entrypoint_0()
{
    return (int) &D_808001D0_chplatuegrill;
}

s32 func_808000A0_chplatuegrill(Actor *this)
{
    if (func_800DA298(0x3EA) != 0) {
        this->unk58 = 0.0f;
        func_80102424(this, 2);
    }
}

void func_808000DC_chplatuegrill(u8 *param_0)
{
    u32 temp_t6;

    temp_t6 = (u32) *(u16 *) ((char *) param_0 + 0x72) >> 0xA;
    if (temp_t6 != 2) {
        if ((temp_t6 == 3) && (func_80101DDC() != 0)) {
            func_80102424(param_0, 2);
            func_80101180(0x518, 7, 0);
        }
    } else {
        func_80103110(param_0, 0);
    }
}

s32 func_80800148_chplatuegrill(Actor *param_0, s32 param_1, PlatueGrillEventPayload param_2)
{
    if (param_1 == 0x40) {
        if (param_0->unk70_10 == 1) {
            func_80103110(param_0, 1);
            func_80102424(param_0, 3);
            func_800FC660(0xE);
        }
        return 1;
    }
    return 0;
}

int chplatuegrill_entrypoint_1()
{
    return &D_80800238_chplatuegrill;
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
int D_808001D0_chplatuegrill[18] = {0x1580518,
                                    0x96A0001,
                                    0x0,
                                    (u32) _chdoor_entrypoint_0,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x1F40,
                                    0x0,
                                    0x3EA0000,
                                    0xC00,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    (u32) func_80800000_chplatuegrill,
                                    (u32) func_80107C2C,
                                    -0x7FFFDBFE,
                                    (u32) _chdoor_entrypoint_1,
                                    0x0};
u32 D_80800218_chplatuegrill[8] = {0x0,        0x0,      0x3ECCCCCD, 0x8E0044,
                                   0x3ECCCCCD, 0x8E0002, 0x3C23D70A, 0x8E0002};
int D_80800238_chplatuegrill[18] = {0x1110519,
                                    0x99B0001,
                                    (u32) &D_80800218_chplatuegrill,
                                    (u32) func_808000DC_chplatuegrill,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x1388,
                                    0x0,
                                    0x0,
                                    0x828,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    (u32) func_808000A0_chplatuegrill,
                                    (u32) func_80107C2C,
                                    -0x7FFDDC00,
                                    (u32) func_80800148_chplatuegrill,
                                    0x0};
