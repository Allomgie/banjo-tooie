// Probably the timed grille in Glitter Gulch Mine's waterfall area: opens when its switch is shot,
// closes after 35 s, unless the player reached the area behind it (flag 0x503).
#include "common.h"

extern void _chwaterfallgrill_entrypoint_0(void);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_11(Actor *, s32, f32);
extern void func_800CE8D8(s32, f32, s32);
extern void *D_80800330_chwaterfallgrill;

int func_80800000_chwaterfallgrill(Actor *actor)
{
    _chdoor_entrypoint_0();
    do { // Matching: empty loop needed for the match.
    } while (0);
    if (((u32) *(u16 *) ((char *) actor + 0x72) >> 10) == 4) {
        if (func_8010CB0C((char *) actor + 0x18, 0xB4, 0xC8, -350)) {
            func_800DA544(0x503);
            func_800CE928(0, 0, 0);
            func_800CE88C(0, 0);
            func_800FC660(0x10);
            func_80103110(actor, 0);
        }
    }
}

void func_8080008C_chwaterfallgrill(Actor *actor)
{
    if (func_800DA298(0x503))
        func_800DA544(0x9F2);
    else if (!func_800CEAA8(0) ||
             (void *) func_800CE95C(0) != (void *) _chwaterfallgrill_entrypoint_0)
        func_800DA524(0x9F2);
    func_800EE7F8((f32 *) actor->actorData, actor->position);
    if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, 440.0f, 0x408A, 0x9F2)) {
        _chdoormake_entrypoint_8(actor, 2);
        _chdoormake_entrypoint_5(actor, 2.5f);
        _chdoormake_entrypoint_9(actor, 0, 0, 16);
        _chdoormake_entrypoint_10(actor, 0, 0x501);
        _chdoormake_entrypoint_11(actor, 0, 0.9499969482421875f);
        _chdoormake_entrypoint_9(actor, 1, 2, 16);
        _chdoormake_entrypoint_10(actor, 1, 0x502);
        _chdoormake_entrypoint_11(actor, 1, 0.25f);
    }
    if (func_800DA298(0x503) || !func_800DA298(0x9F2))
        func_80103110(actor, 0);
}

// Message 7: switch shot, open and start the 35 s timer.
s32 func_808001E0_chwaterfallgrill(Actor *actor, s32 message, s32 unk_2)
{
    switch (message) {
        case 7:
            if (func_800DA298(0x503)) {
                return 0;
            }
            if (func_800CEAA8(0)) {
                func_800CE8D8(0, 35.0f, 0x23);
                func_800CE928(0, _chwaterfallgrill_entrypoint_0, 0);
            }
            func_80103110(actor, 1);
            break;
        case 0x9D:
            func_800CE8D8(0, 35.0f, 0x23);
            func_800CE928(0, _chwaterfallgrill_entrypoint_0, 0);
            func_800CE88C(0, 1);
            break;
        case 0x9E:
            func_80103110(actor, 0);
    }
    return _chdoor_entrypoint_1(actor, message, unk_2);
}

// Timer callback: closes the grille (message 8) in the mine, otherwise clears flag 0x9F2.
s32 chwaterfallgrill_entrypoint_0(Actor *this, u32 unk_1)
{
    if (func_800EA05C(this) == 0xC7) {
        func_80101180(0x11B, 8, 0);
    } else {
        func_800DA524(0x9F2);
        if (this) { // Matching: empty block needed for the match.
        }
    }
}

int chwaterfallgrill_entrypoint_1()
{
    return &D_80800330_chwaterfallgrill;
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file, and IDO schedules them differently otherwise.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
void *D_80800330_chwaterfallgrill = (void *) 0x00AC011B;
static u32 D_80800330_chwaterfallgrill_rest[19] = {0x6810001,
                                                   0x0,
                                                   (u32) func_80800000_chwaterfallgrill,
                                                   (u32) func_80105834,
                                                   (u32) func_80101870,
                                                   0x0,
                                                   0x0,
                                                   0x0,
                                                   0x800,
                                                   0x0,
                                                   0x0,
                                                   0x0,
                                                   (u32) func_8080008C_chwaterfallgrill,
                                                   (u32) func_80107C2C,
                                                   0x80082402,
                                                   (u32) func_808001E0_chwaterfallgrill,
                                                   0x0,
                                                   0x0,
                                                   0x0};
