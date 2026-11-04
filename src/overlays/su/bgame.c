#include "common.h"

#define SG ((SubGameView *) sg)
extern u8 D_80800970_susubgame[];
extern s32 _gcdialogcamera_entrypoint_0(s32, s32);
typedef struct {
    u8 state;
    u8 cutscene;
    s16 flags;
    f32 unk_4;
    f32 view_scale[4];
} SubGameView;
extern s32 func_800D3948(void);
extern void *func_800A93E4(s32);
extern void *func_80110024(void *);
extern void _ncpod_entrypoint_12(void *, s32);
extern void _ncpod_entrypoint_22(void *, s32, f32 *);
extern void _ncpod_entrypoint_23(void *, s32, f32 *);
extern f32 func_8010CD50(Actor *, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _ncpod_entrypoint_24(void *, s32, f32 *);
extern void _ncpod_entrypoint_21(void *, s32, s32);
extern void func_8010D5DC();
extern void func_800F4A58(s32, f32 *, f32);
// Sets up the pod camera views of all participating players and runs their camera script.
void susubgame_entrypoint_5();
void func_8080078C_susubgame();
int func_80800814_susubgame();
int func_808008DC_susubgame();
void susubgame_entrypoint_12();

// Initializes the sub-game state block.
void susubgame_entrypoint_0(s32 actor, u8 *sg, unsigned long flags)
{
    // Matching: the extra temporary is needed for the match.
    u8 *block;
    *(s8 *) sg = 0;
    *(s16 *) (sg + 2) = flags;
    *(s8 *) (sg + 1) = 0;
    *(s16 *) (sg + 4) = 0x15;
    block = sg;
    susubgame_entrypoint_12(block, &D_80800970_susubgame);
}

void susubgame_entrypoint_1(void *actor, void *sg, int param_2)
{
    *(u16 *) ((char *) sg + 4) = param_2;
}

s32 susubgame_entrypoint_2(s32 actor, u8 *sg)
{
    return sg[0];
}

// Shows the intro dialog through the dialog camera.
int susubgame_entrypoint_3(void *actor, u8 *sg, s32 param_2, s32 param_3)
{
    if (_gcdialogcamera_entrypoint_0(param_2, param_3)) {
        if (*sg != 2)
            susubgame_entrypoint_5(actor, sg, 5, 1, 0);
        return 2;
    }
    return 1;
}

// Closes the pod cameras of all participating players; ends the cutscene if one was started.
int susubgame_entrypoint_4(s32 actor, u8 *sg)
{
    s32 i;
    if (*sg != 0) {
        for (i = 0; i < 8; i++) {
            // Matching: "| 0" on the loop index is needed for the match.
            if (func_808008DC_susubgame(i | 0) != 0) {
                _ncpod_entrypoint_17(func_800A93E4(i | 0), 0);
            }
        }

        *sg = 0;
        if (*(sg + 1) != 0) {
            *(sg + 1) = 0;
            _glcutDll_entrypoint_17();
        }
        return 1;
    }
    return 0;
}

// Sets up the pod camera views of all participating players and runs their camera script.
void susubgame_entrypoint_5(actor, sg, arg2, arg3, flags) Actor *actor;
u8 *sg;
s32 arg2;
s32 arg3;
s32 flags;
{
    s32 i;
    void *view;
    void *pod;
    f32 scaled[4];
    f32 vec[3];

    if (func_800D3948()) {
        flags |= 4;
    }
    switch (SG->state) {
        case 0:
            func_80800814_susubgame(actor, sg, flags);
            // fallthrough
        case 1:
        case 3:
            for (i = 0; i < 4; i++) {
                scaled[i] = SG->view_scale[i] * actor->scale;
            }
            for (i = 0; i < 8; i++) {
                if (func_808008DC_susubgame(i)) {
                    view = func_800A93E4(i);
                    pod = func_80110024(func_800A93E4(i));
                    _ncpod_entrypoint_12(pod, 1);
                    _ncpod_entrypoint_22(pod, 0, scaled);
                    _ncpod_entrypoint_23(pod, 0, actor->position);
                    if (SG->flags & 1) {
                        func_800EFA4C(vec, 0.0f, func_8010CD50(actor, i), 0.0f);
                        _ncpod_entrypoint_24(pod, 0, vec);
                    } else {
                        _ncpod_entrypoint_24(pod, 0, actor->rotation);
                    }
                    func_8080078C_susubgame(view, i);
                }
            }
            SG->state = 2;
            // fallthrough
        case 2:
            for (i = 0; i < 8; i++) {
                if (func_808008DC_susubgame(i)) {
                    _ncpod_entrypoint_21(func_800A93E4(i), arg2, arg3);
                }
            }
    }
}

// Runs the pod camera script for the current player.
void susubgame_entrypoint_6(s32 *actor, u8 *sg, s32 param_2, s32 flags, s32 script)
{
    if (script == 0) {
        script = *actor;
    }
    switch (*sg) {
        case 0:
            func_80800814_susubgame(actor, sg, flags);
            // fallthrough
        case 2:
        case 3:
            *sg = 1;
            // fallthrough
        case 1:
            _ncpod_entrypoint_20(func_800A93E4(func_800F54E4()), script, param_2, flags | 0x800);
    }
}

// Runs a pod camera script for each participating player.
void susubgame_entrypoint_7(Actor *actor, u8 *sg, s32 *param_2, s32 flags,
                            Unk80132ED0 *script)
{
    s32 i;

    if (script == NULL) {
        script = actor->unk0;
    }
    switch (sg[0]) {
        case 0:
            func_80800814_susubgame(actor, sg, flags);
            // fallthrough
        case 2:
        case 3:
            sg[0] = 1;
            // fallthrough
        case 1:
            for (i = 0; i < 8; i++) {
                if (func_808008DC_susubgame(i)) {
                    _ncpod_entrypoint_20(func_800A93E4(i), script, param_2[i],
                                         flags | 0x800);
                }
            }
    }
}

// Runs a pod camera script (variant 32) for each participating player.
void susubgame_entrypoint_8(s32 *actor, u8 *sg, s32 param_2, s32 flags, s32 script)
{
    s32 i;

    if (script == 0) {
        script = *actor;
    }
    switch (*sg) {
        case 0:
            func_80800814_susubgame(actor, sg, flags);
            // fallthrough
        case 1:
        case 2:
            *sg = 3;
            // fallthrough
        case 3:
            i = 0;
            do {
                if (func_808008DC_susubgame(i)) {
                    _ncpod_entrypoint_32(func_800A93E4(i), script, param_2, flags | 0x800);
                }
                i++;
            } while (i != 8);
    }
}

// Tests whether all participating players are ready.
int susubgame_entrypoint_9()
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (func_808008DC_susubgame(i) && !func_800F6F00(i))
            return 0;
    }

    return 1;
}

// Places the player at a start marker, by player-control script or by teleport.
int susubgame_entrypoint_10(Actor *actor, s32 param_1, s32 param_2, s32 param_3)
{
    f32 marker[6];
    s32 scripted;
    s32 player;
    f32 rot[3];

    scripted = !func_800DA9E4(param_3, 1);
    player = func_800F54E4();
    if (!_subaddiemarker_entrypoint_0(actor, param_2, marker, 1))
        return 0;
    if (scripted) {
        func_800F608C(player, param_1);
        func_800F497C(player);
        func_800F49A8(player, 1);
        func_800F49D4(player, func_8010D5DC, actor->unk0);
        func_800F4A58(player, marker, 200.0f);
    } else {
        func_800EFA4C(rot, 0.0f, marker[4], 0.0f);
        func_800F608C(player, param_1);
        func_800F8294(player, marker);
        func_800F832C(player, rot);
        func_800F497C(player);
    }
    return scripted;
}

// Stops the timer in the given slot if it is running.
s32 susubgame_entrypoint_11(s32 slot)
{
    if (func_800CEAA8(slot) != 0) {
        func_800CE88C(slot, 0);
    }
}

void func_8080078C_susubgame(view, player) s32 view;
s32 player;
{
    f32 pos[3];
    f32 rot[3];
    f32 scale[4];
    s32 pod;

    pod = func_80110024(func_800A93E4(player));
    func_800F5A00(player, pos);
    func_800F5DC8(player, rot);
    _ncpod_entrypoint_23(pod, 1, pos);
    _ncpod_entrypoint_24(pod, 1, rot);
    _gcdialogcamera_entrypoint_7(player, scale);
    _ncpod_entrypoint_22(pod, 1, scale);
}

int func_80800814_susubgame(actor, sg, flags)
s32 actor[2];
s32 *sg;
u32 flags;
{
    s32 view;
    s32 i;
    // Matching: "&*" is needed for the match.
    Gtexture *state = &*sg;
    i = 0;
    while (i < 8) {
        if (func_808008DC_susubgame(i) != 0) {
            view = func_800A93E4(i);
            _ncpod_entrypoint_16(view, actor[0], *(s16 *) ((char *) state + 0x4),
                                 flags | 0x800);
        }
        i++;
    }

    if (flags & 0x800) {
        *(u8 *) ((char *) state + 0x1) = 0;
    } else {
        *(u8 *) ((char *) state + 0x1) = 1;
    }
    if (*(u8 *) ((char *) state + 0x1) != 0) {
        _glcutDll_entrypoint_6(func_800EA05C(), 0x79);
    }
}

int func_808008DC_susubgame(player)
s32 player;
{
    if (func_800D3948()) {
        return func_800F6438(player) != 0 && func_800A9420(player) != 0;
    }
    return func_800F54E4() == player;
}

void susubgame_entrypoint_12(dst, src) float dst[4];
float src[4];
{
    dst[2] = src[0];
    dst[3] = src[1];
    dst[4] = src[2];
    dst[5] = src[3];
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
u8 D_80800970_susubgame[16] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                               0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
