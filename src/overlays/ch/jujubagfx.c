// Visual effect of Mumbo's juju bag spell: a sumumbofx object follows the player (as Mumbo) or the
// Mumbo NPC while the spell is cast and fades out on cue flag 0x9F3.
#include "common.h"

extern void *D_80800470_chjujubagfx;
extern void *func_80100094(Actor *, u32);
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_3(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _sumumbofx_entrypoint_23(void *, f32);
extern void _chbaddiesetup_entrypoint_0(void *);
extern void *_chjujubagfx_entrypoint_1;
extern f32 _sumumbofx_entrypoint_21(void *);
extern f32 _sumumbofx_entrypoint_22(void *);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, f32 *, f32 *);
extern Vec3f D_808004B8_chjujubagfx;
extern Vec3f D_808004C4_chjujubagfx;

int chjujubagfx_entrypoint_0()
{
    return &D_80800470_chjujubagfx;
}

// State 2 starts the spell effect, state 4 fades it out.
void func_8080000C_chjujubagfx(Actor *actor, s32 state)
{
    void *fx;

    func_80101FDC(actor, state);
    switch (state) {
        case 2:
            _sumumbofx_entrypoint_0(actor, 1, 10, 0x9E4);
            fx = func_80100094(actor, 1);
            _sumumbofx_entrypoint_2(fx);
            _sumumbofx_entrypoint_24(fx, 0.15f);
            _sumumbofx_entrypoint_4(fx);
            _sumumbofx_entrypoint_3(fx, 360.0f);
            _sumumbofx_entrypoint_15(fx, 0.5f);
            _sumumbofx_entrypoint_23(fx, 0.0f);
            _sumumbofx_entrypoint_19(fx, 0);
            break;
        case 4:
            func_800DA524(0x9F3);
            _sumumbofx_entrypoint_16(func_80100094(actor, 1), 0.5f);
            actor->unk64_20 = 1;
    }
}

int func_80800100_chjujubagfx(Actor *actor)
{
    s32 transformation;
    s32 *mumbo;
    transformation = func_8010D278();
    // Not Mumbo: attach to the NPC Mumbo.
    if (transformation != 0xD) {
        mumbo = _subaddiefind_entrypoint_0(&actor->position, 0x190, -1, 0);
        *(s32 *) ((char *) actor + 0x3C) = *(s32 *) ((char *) mumbo + 0x0);
    } else {
        func_8008FE94(1, &actor->position);
    }
    *(u8 *) ((char *) actor + 0x65) &= 0xFFEF;
    func_8080000C_chjujubagfx(actor, 2);
}

s32 func_80800174_chjujubagfx(Actor *actor)
{
    if (func_80100094(actor, 1) != 0) {
        _sumumbofx_entrypoint_1(actor, 1);
    }
}

void func_808001A8_chjujubagfx(Actor *actor)
{
    Vec3f unk_0;
    Vec3f offset;
    void *fx;
    f32 *pos;

    unk_0 = D_808004B8_chjujubagfx;
    offset = D_808004C4_chjujubagfx;
    fx = func_80100094(actor, 1);
    // Cast cue: start fading out.
    if (func_800DA298(0x9F3)) {
        func_8080000C_chjujubagfx(actor, 4);
    }
    // Follow the player (when Mumbo) or the NPC Mumbo.
    if (!actor->unk64_20) {
        if (func_8010D278() != 0xD) {
            if (actor->unk3C != NULL) {
                _chnewmumbo_entrypoint_0(func_80106790(actor->unk3C), actor->position);
            }
        } else {
            func_8008FE94(1, actor->position);
        }
    }
    switch (actor->unk70_10) {
        case 2:
            pos = actor->position;
            _sumumbofx_entrypoint_14(fx);
            _sumumbofx_entrypoint_7(fx, 28.0f, 0, 10, pos, offset.f, unk_0.f);
            if (_sumumbofx_entrypoint_21(fx) == 0.0f) {
                _sumumbofx_entrypoint_17(fx, 10.0f);
                func_8080000C_chjujubagfx(actor, 3);
            }
            return;
        case 3:
            pos = actor->position;
            _sumumbofx_entrypoint_14(fx);
            _sumumbofx_entrypoint_7(fx, 28.0f, 0, 10, pos, offset.f, unk_0.f);
            return;
        case 4:
            pos = actor->position;
            _sumumbofx_entrypoint_14(fx);
            _sumumbofx_entrypoint_7(fx, 28.0f, 0, 10, pos, offset.f, unk_0.f);
            if (_sumumbofx_entrypoint_22(fx) < 0.05f) {
                func_800FFAB0(actor);
            }
    }
}

s32 func_808003D4_chjujubagfx(s32 actor, s32 gfx)
{
    _sumumbofx_entrypoint_8(func_80100094(actor, 1), gfx);
}

// Spawns actor 0x2F9 at the player.
s32 chjujubagfx_entrypoint_1(void)
{
    f32 pos[3];

    func_8010D254(pos);
    func_80108474(0x2F9, pos, 0);
}

void chjujubagfx_entrypoint_2(void)
{
    _chbaddiesetup_entrypoint_0(&_chjujubagfx_entrypoint_1);
}

// TU-NOTE: .data of this overlay is defined here in C; its tables point to functions of this file.
// IDO's assembler schedules some of them differently otherwise. Values are taken from the ROM.
extern void func_80105834();
extern void func_80107C2C();
void *D_80800470_chjujubagfx = (void *) 0x02BE02F9;
static u32 D_80800470_chjujubagfx_rest[17] = {0x63F0001,
                                              0x0,
                                              (u32) func_808001A8_chjujubagfx,
                                              (u32) func_80105834,
                                              (u32) func_808003D4_chjujubagfx,
                                              0x13880000,
                                              0x0,
                                              0x0,
                                              0x4,
                                              (u32) func_80800174_chjujubagfx,
                                              0x0,
                                              0x0,
                                              (u32) func_80800100_chjujubagfx,
                                              (u32) func_80107C2C,
                                              0x80000002,
                                              0x0,
                                              0x0};
Vec3f D_808004B8_chjujubagfx = {0.0f, 0.0f, 0.0f};
Vec3f D_808004C4_chjujubagfx = {0.0f, -14.0f, 0.0f};
