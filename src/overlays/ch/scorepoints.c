// Floating score popup used by minigames: prints a number at a world position, bobs briefly,
// then rises and fades while a jingle plays.
#include "common.h"

extern int D_808003C0_chscorepoints[];
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern f32 func_800D8FF8(void);
extern void *func_800A89F8(void);
extern void *func_80100094(Actor *, u32);
extern s32 func_800C4C34(void *, f32 *, f32 *, s32 *);
extern s32 _subaddiefade_entrypoint_0(Actor *);
typedef struct {
    u8 pad_0[0x28];
    s32 value;
    s32 flags;
    u8 pad_30[0x20];
    s32 color_id;
    s32 unk_54;
} ScoreDisplay1581;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_80108474(s32, f32 *, s32);
extern int func_800D3DA4(s32);
extern s32 _chscorepoints_entrypoint_1;

int *chscorepoints_entrypoint_0()
{
    return &D_808003C0_chscorepoints;
}

// Formats the value as text, sets the bob time and plays a jingle for positive or negative values.
void func_8080000C_chscorepoints(u8 *popup)
{
    char text[0x20];
    s32 len;

    func_800E73D4(text);
    func_800E6DB4(text, *(s32 **) (popup + 0x28));
    len = func_800E7188(text);
    func_80100074(popup, 0, len + 1);
    rare_memcpy(func_80100094(popup, 0), text, len + 1);
    *(f32 *) ((s8 *) popup + 0x58) = 0.8f;
    if (*(s32 *) ((s8 *) popup + 0x2C) & 1) {
        if (*(s32 *) ((s8 *) popup + 0x28) < 0) {
            func_800FC660(0xF);
            return;
        }
        func_800FC660(0xE);
    }
}

// Bobs for 0.8 s, then rises.
void func_808000BC_chscorepoints(Actor *actor)
{
    s32 finished;

    switch (actor->unk70_10) {
        case 1:
            finished = func_800D9078(&actor->unk58);
            ((f32 *) actor->actorData)[6] =
                func_80013970(func_800F12D4(actor->unk58, 0.0f, 0.8f, 0.0f, 720.0f)) * 50.0f;
            if (finished) {
                _subaddiefade_entrypoint_3(actor);
                func_80101FDC(actor, 2);
            }
            break;
        case 2:
            ((f32 *) actor->actorData)[6] = 0.0f;
            actor->position[1] += func_800D8FF8() * 120.0f;
    }
}

// Prints the number at the projected world position.
void func_8080019C_chscorepoints(Actor *actor, void *gfx)
{
    s32 unk_0;
    void *unk_1;
    f32 screen[2];
    f32 world[3];
    void *text;
    s32 on_screen;
    s32 projected;

    unk_0 = *(s32 *) &actor->unk54;
    unk_1 = func_800A89F8();
    func_800B8C50();
    func_800B8C8C(_subaddiefade_entrypoint_0(actor));
    func_800B8C98(1);
    func_800B8CE0(*(s32 *) &actor->unk50);
    func_800B7F14(gfx);
    if (unk_0 == -1 || (void *) func_800A940C(unk_0) == unk_1) {
        func_800EE7F8(world, actor->position);
        world[1] += *(f32 *) &actor->actorData[6];
        projected = func_800C4C34(unk_1, world, screen, &on_screen);
        if (on_screen && projected) {
            text = func_80100094(actor, 0);
            func_800B8E28(gfx, (s32) screen[0], (s32) screen[1], text);
        }
    }
    func_800B811C(gfx);
}

// Spawns a score popup at a world position.
void chscorepoints_entrypoint_1(s32 value, s32 unk_1, s32 x, s32 y, s32 z,
                                s32 flags)
{
    f32 pos[3];
    ScoreDisplay1581 *popup;

    func_800EFA4C(pos, (f32) x, (f32) y, (f32) z);
    popup = func_80108474(0x14E, pos, 0);
    popup->value = value;
    popup->flags = flags;
    popup->unk_54 = unk_1;
    popup->color_id = func_800D3DA4(unk_1) + 0xC29;
}

// Queues the spawn of a score popup.
void chscorepoints_entrypoint_2(s32 value, s32 unk_1, u8 *pos, s32 flags)
{
    _chbaddiesetup_entrypoint_6(
        &_chscorepoints_entrypoint_1, value, unk_1, (s32) *(f32 *) ((s8 *) pos + 0),
        (s32) *(f32 *) ((s8 *) pos + 4), (s32) *(f32 *) ((s8 *) pos + 8), flags);
}

// TU-NOTE: the .data of this overlay is defined here in C; its tables point to functions of this file,
// and IDO's assembler schedules some of them differently otherwise.
extern void func_80105834();
extern void func_80107C2C();
int D_808003C0_chscorepoints[20] = {0x33D014E,
                                    -0xFFFF,
                                    0x0,
                                    (u32) func_808000BC_chscorepoints,
                                    (u32) func_80105834,
                                    (u32) func_8080019C_chscorepoints,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x20004,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_8080000C_chscorepoints,
                                    (u32) func_80107C2C,
                                    -0x7FFFFFFE,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0};
