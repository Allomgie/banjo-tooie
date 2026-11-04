// Probably the exit lift of the Hag 1 arena: a map-mesh vertex callback lowers it after the
// fight, and standing on it warps the player to Cauldron Keep (map 0x15D).
#include "common.h"

extern int D_80800430_chdiggerbossdoor[];
extern u8 D_80800478_chdiggerbossdoor[];
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern u8 _chdiggerbossdoor_entrypoint_1[];
extern Actor *func_80106790();
void func_80800370_chdiggerbossdoor();

int *chdiggerbossdoor_entrypoint_0()
{
    return &D_80800430_chdiggerbossdoor;
}

// Init: if Hag 1 is already defeated, start in the lowered state.
void func_8080000C_chdiggerbossdoor(Actor *actor)
{
    *(f32 *) ((char *) actor + 0x28) = 0.0f;
    if (func_800EA090() == 6) {
        *(f32 *) ((char *) actor + 0x28) = -500.0f;
        if (func_800DA298(0x43) != 0) {
            func_80800370_chdiggerbossdoor(actor);
            func_8010108C(actor, 7, 0);
            func_800F8294(func_800F54E4(), (f32 *) ((char *) actor + 4));
            _capod_entrypoint_21(*(s32 **) ((char *) actor + 0), 0, 0x55, 0x2010);
            *(u16 *) ((char *) actor + 0x6E) = (*(u16 *) ((char *) actor + 0x6E) & 0xFE00) | 1;
        }
    }
}

// Update: state 2 lowers the lift, state 3 waits for the player, state 4 warps to Cauldron Keep.
void func_808000B0_chdiggerbossdoor(Actor *actor)
{
    s32 moving;
    s32 player;
    f32 pos[3];

    moving = 0;
    player = func_800F54E4();
    switch (actor->unk70_10) {
        case 2:
            if (func_800D9078(&actor->unk58)) {
                if (func_800DA298(0x43)) {
                    _capod_entrypoint_22();
                    actor->unk6C_0 = 0;
                }
                func_80101FDC(actor, 3);
            } else {
                moving = 1;
            }
            ((f32 *) actor->actorData)[4] =
                func_800F12D4(actor->unk58, 0.0f, 6.0f, 0.0f, -500.0f);
            func_800EE7F8(pos, actor->position);
            pos[1] += ((f32 *) actor->actorData)[4];
            func_800F8294(player, pos);
            break;
        case 4:
            if (func_800D9078(&actor->unk58)) {
                _gcgoto_entrypoint_1(0x15D, 5);
                func_80101FDC(actor, 1);
            } else {
                moving = 1;
            }
            ((f32 *) actor->actorData)[4] =
                func_800F12D4(actor->unk58, 0.0f, 6.0f, -500.0f, 0.0f);
            break;
        case 3:
            if ((s32) ((u32) func_800F55FC(player) << 3) < 0 && func_80016B30(0, 1) == 1 &&
                func_800F4BB8(player, -1, 0)) {
                _capod_entrypoint_21(actor->unk0, 0, 0x54, 0x10);
                func_80101FDC(actor, 4);
                actor->unk6C_0 = 1;
                actor->unk58 = 6.0f;
            }
            break;
    }
    _subaddieaudioloop_entrypoint_4(actor, actor->position, moving,
                                    D_80800478_chdiggerbossdoor);
    func_80800370_chdiggerbossdoor(actor);
}

void func_808002A8_chdiggerbossdoor(void *actor)
{
    if (*(s32 *) ((char *) actor + 0x6C) & 0x1FF) {
        _capod_entrypoint_22();
        *(u16 *) ((char *) actor + 0x6E) &= 0xFE00;
    }
}

// Message 7 (sent by the boss on defeat) starts lowering the lift.
int func_808002E8_chdiggerbossdoor(Actor *actor, s32 msg, s32 param_2)
{
    switch (msg) {
        case 7:
            if (actor->unk70_10 == 1) {
                func_80101FDC(actor, 2);
                actor->unk58 = 6.0f;
            }
            break;
        case 0x95:
            func_80800370_chdiggerbossdoor(actor);
            return 1;
        default:
            return 0;
    }
    return 1;
}

// Registers the vertex callback that shifts the map mesh by the lift height.
void func_80800370_chdiggerbossdoor(actor) s32 *actor;
{
    s32 glid;

    glid = func_800BEA88(0);

if (glid != 0) {
    _glid_entrypoint_0(glid, 1, &_chdiggerbossdoor_entrypoint_1, *actor);
}

}

// Vertex callback: adds the lift height to each vertex Y.
void chdiggerbossdoor_entrypoint_1(void *param_0, Vtx *src, Vtx *dst, s32 count,
                                   Unk80132ED0 *param_4)
{
    s16 height;
    Vtx *end;
    height = *(f32 *) &func_80106790(param_4)->actorData[4];
    end = src + count;
    for (; src < end; src++, dst++) {
        dst->v.ob[1] = src->v.ob[1] + height;
    }
}

extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
int D_80800430_chdiggerbossdoor[18] = {0xAC04F1,
                                       0x1,
                                       0x0,
                                       (u32) func_808000B0_chdiggerbossdoor,
                                       (u32) func_80102EC0,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_808002A8_chdiggerbossdoor,
                                       0x0,
                                       0x0,
                                       (u32) func_8080000C_chdiggerbossdoor,
                                       (u32) func_80107C2C,
                                       -0x7FFFFBFE,
                                       (u32) func_808002E8_chdiggerbossdoor,
                                       0x0};
u8 D_80800478_chdiggerbossdoor[24] = {0x0, 0x13, 0x4, 0xAD, 0x0,  0x16, 0x6D, 0x60,
                                      0x0, 0x1,  0x3, 0xE8, 0x1F, 0x40, 0x0,  0x0,
                                      0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0};
