#include "common.h"

extern int D_80800290_charea51gate[];
extern void func_800EC398(void *, f32 *);
extern int D_808002D8_charea51gate[];
typedef struct {
    u8 pad[0x7C];
    u32 pad7C : 19;
    u32 flag : 1;
    u32 rest : 12;
} GateState;
extern void _chelectricfence_entrypoint_2();
extern int func_800DC298(f32);
void func_80800228_charea51gate();

int *charea51gate_entrypoint_0()
{
    return &D_80800290_charea51gate;
}

int func_8080000C_charea51gate(f32 obj[3])
{
    f32 *pos;
    pos = &obj[0];
    func_80104004(obj, &obj[6], &obj[10]);
    do {
        obj[12] = obj[8] + 40.0f;
        func_8010A800(pos, 2);
    } while (0);
}

void func_80800054_charea51gate(GateState *gate)
{
    if (gate->flag && func_800DC298(0.15f)) {
        _chelectricfence_entrypoint_2(gate, (u8 *) gate + 0x18, (u8 *) gate + 0x28);
    }
}

// Message 0x3E: touched, shocks the player unless protected. 0x90: explosion.
s32 func_808000A0_charea51gate(Actor *actor, s32 msg, void *data)
{
    u8 *hit;
    f32 shock_pos[3];
    s32 do_shock;
    s32 unk_3;
    s32 local_4;
    s32 local_5;
    switch (msg) {
        case 0x3E:
            do_shock = 1;
            hit = *(void **) &data;
            func_800EC398(hit, shock_pos);
            if ((*(u32 *) (hit + 0x24) >> 22) == 0) {
                if (!func_800F64A4((u32) *(u16 *) (hit + 0x1A) >> 5, 0x8000))
                    func_800F79DC((u32) *(u16 *) (hit + 0x1A) >> 5, 5, actor->unk0, hit);
                else
                    do_shock = func_8001210C(3) == 0;
            }
            if (do_shock)
                _chelectricfence_entrypoint_1(actor, shock_pos);
            return 1;
        case 0x40:
            _chexploder_entrypoint_4(actor, (u8 *) *(void **) *(void **) &data + 4, 2);
            break;
        case 0x90:
            func_80800228_charea51gate(actor);
            break;
        case 0x95:
            unk_3 = func_800F6438(func_800F54E4()) != 0;
            if (unk_3)
                unk_3 = func_800F64A4(func_800F54E4(), 0x8000) == 0;
            if (unk_3)
                func_80109EF4(actor, 1);
            else
                func_80109F08(actor, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

// Explosion: blows up the gate and sets flag 0xA7.
void func_80800228_charea51gate(actor) s32 actor;
{
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_808002D8_charea51gate);
    func_800FFAB0(actor);
    func_800DA544(0xA7);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800290_charea51gate[18] = {0x2A70342,
                                   0x7800001,
                                   0x0,
                                   (u32) func_80800054_charea51gate,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x17700000,
                                   0x0,
                                   0xA70000,
                                   0xC00,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_8080000C_charea51gate,
                                   (u32) func_80107C2C,
                                   -0x7FFFDC00,
                                   (u32) func_808000A0_charea51gate,
                                   0x0};
int D_808002D8_charea51gate[6] = {0x1304C8, 0xA00E6, 0x180000, 0x0, 0x0, 0x0};
