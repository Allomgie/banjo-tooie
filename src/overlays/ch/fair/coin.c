#include "common.h"

extern s32 D_80800150_chfaircoin[];
extern int D_8080015C_chfaircoin[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_8001395C(f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);

// Flies the coin in a sine arc, plays a jingle on arrival.
void func_80800000_chfaircoin(Actor *coin)
{
    f32 t;

    func_800D9078((f32 *) &coin->actorData[3]);
    t = func_800F10B4(*(f32 *) &coin->actorData[3], coin->unk58, 0.0f, 0.0f, 1.0f);
    func_800EFE50(coin->position, (f32 *) &coin->actorData[4], (f32 *) &coin->actorData[0],
                  t);
    coin->position[1] += func_8001395C(t * 3.1415927f) * 200.0f;
    if (*(f32 *) &coin->actorData[3] == 0.0f) {
        func_800FFAB0(coin);
        func_800FC660(0xE);
    }
}

u8 *chfaircoin_entrypoint_0(s32 from_pos, s32 to_pos, f32 duration)
{
    u8 *coin;

    coin = func_80108474(0x166, from_pos, 0);
    func_800EE7F8(coin + 0x18, to_pos);
    func_800EE7F8(coin + 0x28, from_pos);
    *(f32 *) ((s8 *) coin + 0x24) = duration;
    *(f32 *) ((s8 *) coin + 0x58) = duration;
    func_800C4AF0(0, &D_80800150_chfaircoin);
    return coin;
}

int chfaircoin_entrypoint_1()
{
    return (int) &D_8080015C_chfaircoin;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
s32 D_80800150_chfaircoin[3] = {0x1303F0, 0x166D60, 0x0};
int D_8080015C_chfaircoin[21] = {0x2780166,
                                 0x7D20001,
                                 0x0,
                                 (u32) func_80800000_chfaircoin,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x4,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_80107C2C,
                                 -0x7FFFFFFE,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0};
